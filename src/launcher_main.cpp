#include <windows.h>
#include <commdlg.h>
#include <shellapi.h>

#include <array>
#include <cstdlib>
#include <cwctype>
#include <filesystem>
#include <optional>
#include <string>
#include <system_error>
#include <vector>

namespace {

constexpr wchar_t launcher_title[] = L"Duke64 Launcher";
constexpr wchar_t game_executable[] = L"Duke64Recompiled.exe";

void show_error(const std::wstring& message) {
    MessageBoxW(nullptr, message.c_str(), launcher_title, MB_OK | MB_ICONERROR);
}

std::wstring win32_error_message(DWORD error) {
    std::array<wchar_t, 512> buffer{};
    const DWORD length = FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr,
        error,
        0,
        buffer.data(),
        static_cast<DWORD>(buffer.size()),
        nullptr
    );
    if (length == 0) {
        return L"Windows error " + std::to_wstring(error);
    }
    std::wstring result(buffer.data(), length);
    while (!result.empty() && (result.back() == L'\r' || result.back() == L'\n')) {
        result.pop_back();
    }
    return result;
}

std::filesystem::path launcher_directory() {
    std::array<wchar_t, 32768> buffer{};
    const DWORD length = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
    if (length == 0 || length == buffer.size()) {
        show_error(L"Unable to determine the launcher directory.\n\n" +
                   win32_error_message(GetLastError()));
        return {};
    }
    return std::filesystem::path(std::wstring(buffer.data(), length)).parent_path();
}

bool command_line_rom(std::filesystem::path& rom_path) {
    int argument_count = 0;
    LPWSTR* arguments = CommandLineToArgvW(GetCommandLineW(), &argument_count);
    if (arguments == nullptr) {
        show_error(L"Unable to read the launcher command line.\n\n" +
                   win32_error_message(GetLastError()));
        return false;
    }

    bool valid = true;
    for (int i = 1; i < argument_count; ++i) {
        if (std::wstring(arguments[i]) != L"--rom") {
            continue;
        }
        if (i + 1 >= argument_count) {
            show_error(L"The --rom option requires a .z64 file path.");
            valid = false;
            break;
        }
        rom_path = std::filesystem::path(arguments[++i]);
        break;
    }
    LocalFree(arguments);
    return valid;
}

std::optional<std::filesystem::path> pick_rom(const std::filesystem::path& initial_directory) {
    std::array<wchar_t, 32768> file_name{};
    const std::wstring initial_directory_string = initial_directory.wstring();
    OPENFILENAMEW dialog{};
    dialog.lStructSize = sizeof(dialog);
    dialog.lpstrFilter =
        L"Nintendo 64 ROM (*.z64)\0*.z64\0All files (*.*)\0*.*\0";
    dialog.lpstrFile = file_name.data();
    dialog.nMaxFile = static_cast<DWORD>(file_name.size());
    dialog.lpstrTitle = L"Select Duke Nukem 64 ROM";
    dialog.lpstrInitialDir = initial_directory_string.empty() ? nullptr : initial_directory_string.c_str();
    dialog.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;

    if (!GetOpenFileNameW(&dialog)) {
        const DWORD error = CommDlgExtendedError();
        if (error != 0) {
            show_error(L"Unable to open the ROM picker.\n\n" + win32_error_message(error));
        }
        return std::nullopt;
    }
    return std::filesystem::path(file_name.data());
}

bool is_z64_file(const std::filesystem::path& path) {
    std::wstring extension = path.extension().wstring();
    for (wchar_t& character : extension) {
        character = static_cast<wchar_t>(std::towlower(character));
    }
    return extension == L".z64";
}

std::wstring quote_argument(const std::filesystem::path& path) {
    const std::wstring value = path.wstring();
    std::wstring result;
    result.reserve(value.size() + 2);
    result.push_back(L'"');

    size_t backslash_count = 0;
    for (wchar_t character : value) {
        if (character == L'\\') {
            ++backslash_count;
            continue;
        }
        if (character == L'"') {
            result.append(backslash_count * 2 + 1, L'\\');
            result.push_back(L'"');
            backslash_count = 0;
            continue;
        }
        result.append(backslash_count, L'\\');
        backslash_count = 0;
        result.push_back(character);
    }
    result.append(backslash_count * 2, L'\\');
    result.push_back(L'"');
    return result;
}

bool launch_game(const std::filesystem::path& launcher_directory,
                 const std::filesystem::path& rom_path) {
    const std::filesystem::path game_path = launcher_directory / game_executable;
    std::error_code file_error;
    if (!std::filesystem::is_regular_file(game_path, file_error)) {
        show_error(L"Duke64Recompiled.exe was not found beside the launcher:\n\n" +
                   game_path.wstring());
        return false;
    }

    std::wstring command_line = quote_argument(game_path) + L" --rom " + quote_argument(rom_path);
    std::vector<wchar_t> mutable_command_line(command_line.begin(), command_line.end());
    mutable_command_line.push_back(L'\0');

    STARTUPINFOW startup_info{};
    startup_info.cb = sizeof(startup_info);
    PROCESS_INFORMATION process_info{};
    const std::wstring working_directory = launcher_directory.wstring();
    if (!CreateProcessW(
            game_path.c_str(),
            mutable_command_line.data(),
            nullptr,
            nullptr,
            FALSE,
            CREATE_UNICODE_ENVIRONMENT,
            nullptr,
            working_directory.empty() ? nullptr : working_directory.c_str(),
            &startup_info,
            &process_info)) {
        show_error(L"Unable to start Duke64Recompiled.exe.\n\n" +
                   win32_error_message(GetLastError()));
        return false;
    }

    CloseHandle(process_info.hThread);
    CloseHandle(process_info.hProcess);
    return true;
}

} // namespace

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
    const std::filesystem::path directory = launcher_directory();
    if (directory.empty()) {
        return EXIT_FAILURE;
    }

    std::filesystem::path rom_path;
    if (!command_line_rom(rom_path)) {
        return EXIT_FAILURE;
    }
    if (rom_path.empty()) {
        const auto selected_path = pick_rom(directory);
        if (!selected_path.has_value()) {
            return EXIT_SUCCESS;
        }
        rom_path = *selected_path;
    }
    std::error_code absolute_path_error;
    rom_path = std::filesystem::absolute(rom_path, absolute_path_error);
    if (absolute_path_error) {
        show_error(L"Unable to resolve the selected ROM path:\n\n" + rom_path.wstring());
        return EXIT_FAILURE;
    }

    if (!is_z64_file(rom_path)) {
        show_error(L"Please select a Nintendo 64 .z64 ROM file.");
        return EXIT_FAILURE;
    }

    std::error_code file_error;
    if (!std::filesystem::is_regular_file(rom_path, file_error)) {
        show_error(L"The selected ROM file cannot be opened:\n\n" + rom_path.wstring());
        return EXIT_FAILURE;
    }

    return launch_game(directory, rom_path) ? EXIT_SUCCESS : EXIT_FAILURE;
}
