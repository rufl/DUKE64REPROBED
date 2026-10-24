#define SDL_MAIN_HANDLED
#define __PRFCHWINTRIN_H
#include <SDL.h>
#include <SDL_syswm.h>
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <string>
#include <windows.h>

#include "librecomp/game.hpp"
#include "librecomp/rsp.hpp"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/events.hpp"
#include "ultramodern/error_handling.hpp"
#include "ultramodern/input.hpp"
#include <filesystem>
#include <fstream>
#include <vector>
#include "json/json.hpp"
#include "librecomp/overlays.hpp"
#include "funcs.h"
#include "recomp_overlays.inl"
#include "ultramodern/threads.hpp"

std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(uint8_t*, ultramodern::renderer::WindowHandle, bool);
RspExitReason aspMain(uint8_t* rdram, uint32_t ucode_addr);
extern "C" void proutSprintf_recomp(uint8_t* rdram, recomp_context* ctx);

static const ManualPatchSymbol manual_patch_symbols[] = {
    { 0x800BD9C0, proutSprintf_recomp },
    { 0, nullptr }
};

static RspUcodeFunc* get_rsp_microcode(const OSTask* task) {
    if (task->t.type == M_AUDTASK) return aspMain;
    return nullptr;
}


static SDL_Window* window;
static std::array<SDL_GameController*, 3> controllers{};
static SDL_AudioDeviceID audio_device;
static SDL_AudioStream* audio_stream;
static constexpr Uint8 audio_channels = 2;
static constexpr SDL_AudioFormat audio_format = AUDIO_S16SYS;
static constexpr int audio_device_buffer_samples = 1024;
static uint32_t audio_frequency = 48000;
static int audio_device_frequency = 48000;
static SDL_AudioStream* create_audio_stream(uint32_t source_frequency) {
    if (source_frequency == 0 || audio_device_frequency <= 0 ||
        source_frequency > static_cast<uint32_t>(std::numeric_limits<int>::max())) {
        return nullptr;
    }
    return SDL_NewAudioStream(
        audio_format, audio_channels, static_cast<int>(source_frequency),
        audio_format, audio_channels, audio_device_frequency
    );
}
static void drain_audio_stream(SDL_AudioStream* stream) {
    if (stream == nullptr || audio_device == 0) {
        return;
    }
    std::array<uint8_t, 8192> converted{};
    while (true) {
        const int available = SDL_AudioStreamAvailable(stream);
        if (available <= 0) {
            return;
        }
        const int requested = std::min(available, static_cast<int>(converted.size()));
        const int byte_count = SDL_AudioStreamGet(stream, converted.data(), requested);
        if (byte_count <= 0) {
            std::fprintf(stderr, "SDL audio conversion failed: %s\n", SDL_GetError());
            return;
        }
        if (SDL_QueueAudio(audio_device, converted.data(), static_cast<Uint32>(byte_count)) != 0) {
            std::fprintf(stderr, "SDL audio queue failed: %s\n", SDL_GetError());
            return;
        }
    }
}
static void queue_samples(int16_t* samples, size_t sample_count) {
    if (audio_device == 0 || samples == nullptr || sample_count == 0) {
        return;
    }
    if (audio_stream == nullptr) {
        audio_stream = create_audio_stream(audio_frequency);
        if (audio_stream == nullptr) {
            std::fprintf(stderr, "SDL audio conversion initialization failed: %s\n", SDL_GetError());
            return;
        }
    }
    constexpr size_t max_chunk_samples =
        static_cast<size_t>(std::numeric_limits<int>::max()) / sizeof(int16_t);
    while (sample_count > 0) {
        size_t chunk_samples = std::min(sample_count, max_chunk_samples);
        if (chunk_samples < sample_count && (chunk_samples & 1) != 0) {
            --chunk_samples;
        }
        if (SDL_AudioStreamPut(
                audio_stream, samples, static_cast<int>(chunk_samples * sizeof(int16_t))) != 0) {
            std::fprintf(stderr, "SDL audio conversion input failed: %s\n", SDL_GetError());
            return;
        }
        samples += chunk_samples;
        sample_count -= chunk_samples;
    }
    drain_audio_stream(audio_stream);
}
static size_t get_frames_remaining() {
    if (audio_device == 0 || audio_frequency == 0 || audio_device_frequency <= 0) {
        return 0;
    }
    const size_t queued_bytes = SDL_GetQueuedAudioSize(audio_device);
    const size_t converted_bytes = audio_stream == nullptr
        ? 0
        : static_cast<size_t>(std::max(SDL_AudioStreamAvailable(audio_stream), 0));
    const size_t output_frames =
        (queued_bytes + converted_bytes) / (audio_channels * sizeof(int16_t));
    // osAiGetLength is expressed at the game's source rate, while SDL queues
    // the resampled output at the fixed device rate.
    return static_cast<size_t>(
        (static_cast<uint64_t>(output_frames) * audio_frequency) /
        static_cast<uint32_t>(audio_device_frequency)
    );
}
static void set_frequency(uint32_t frequency) {
    if (frequency == 0 || frequency == audio_frequency) {
        return;
    }
    SDL_AudioStream* new_stream = create_audio_stream(frequency);
    if (new_stream == nullptr) {
        std::fprintf(stderr, "SDL audio rate conversion initialization failed: %s\n", SDL_GetError());
        return;
    }
    if (audio_stream != nullptr) {
        SDL_AudioStreamFlush(audio_stream);
        drain_audio_stream(audio_stream);
        SDL_FreeAudioStream(audio_stream);
    }
    audio_stream = new_stream;
    audio_frequency = frequency;
}
static int mouse_turn;
static int mouse_look;
static float mouse_sensitivity = 1.0f;
static int window_width = 1280;
static int window_height = 720;
struct KeyboardBindings {
    SDL_Scancode move_forward = SDL_SCANCODE_W;
    SDL_Scancode move_backward = SDL_SCANCODE_S;
    SDL_Scancode strafe_left = SDL_SCANCODE_A;
    SDL_Scancode strafe_right = SDL_SCANCODE_D;
    SDL_Scancode fire = SDL_SCANCODE_Z;
    SDL_Scancode jump = SDL_SCANCODE_SPACE;
    SDL_Scancode crouch = SDL_SCANCODE_C;
    SDL_Scancode start = SDL_SCANCODE_RETURN;
    SDL_Scancode open = SDL_SCANCODE_E;
    SDL_Scancode previous_weapon = SDL_SCANCODE_Q;
    SDL_Scancode next_weapon = SDL_SCANCODE_R;
    SDL_Scancode inventory_previous = SDL_SCANCODE_LEFTBRACKET;
    SDL_Scancode inventory_next = SDL_SCANCODE_RIGHTBRACKET;
} keyboard_bindings;
static float controller_deadzone = 0.24f;
static float controller_sensitivity = 1.0f;
static bool invert_aim_x = false;
static bool invert_aim_y = false;
static std::filesystem::path screenshot_path;

static std::filesystem::path get_user_data_path(const char* executable) {
    const auto executable_dir = std::filesystem::absolute(executable).parent_path();
    if (std::filesystem::exists(executable_dir / "portable.txt")) {
        return executable_dir;
    }
    char* local_app_data = nullptr;
    size_t local_app_data_size = 0;
    if (_dupenv_s(&local_app_data, &local_app_data_size, "LOCALAPPDATA") == 0 &&
        local_app_data != nullptr && local_app_data[0] != '\0') {
        const auto path = std::filesystem::path(local_app_data) / "Duke64Recompiled";
        std::free(local_app_data);
        return path;
    }
    std::free(local_app_data);
    return std::filesystem::current_path() / "Duke64Recompiled";
}

static void load_input_config(const std::filesystem::path& data_path) {
    const auto config_path = data_path / "duke64.json";
    const auto scancode_name = [](SDL_Scancode scancode) {
        return std::string(SDL_GetScancodeName(scancode));
    };
    if (!std::filesystem::exists(config_path)) {
        std::ofstream output(config_path);
        if (output) {
            output << nlohmann::json{
                {"mouse_sensitivity", mouse_sensitivity},
                {"window_width", window_width},
                {"window_height", window_height},
                {"controller_deadzone", controller_deadzone},
                {"controller_sensitivity", controller_sensitivity},
                {"invert_aim_x", invert_aim_x},
                {"invert_aim_y", invert_aim_y},
                {"keyboard", {
                    {"move_forward", scancode_name(keyboard_bindings.move_forward)},
                    {"move_backward", scancode_name(keyboard_bindings.move_backward)},
                    {"strafe_left", scancode_name(keyboard_bindings.strafe_left)},
                    {"strafe_right", scancode_name(keyboard_bindings.strafe_right)},
                    {"fire", scancode_name(keyboard_bindings.fire)},
                    {"jump", scancode_name(keyboard_bindings.jump)},
                    {"crouch", scancode_name(keyboard_bindings.crouch)},
                    {"start", scancode_name(keyboard_bindings.start)},
                    {"open", scancode_name(keyboard_bindings.open)},
                    {"previous_weapon", scancode_name(keyboard_bindings.previous_weapon)},
                    {"next_weapon", scancode_name(keyboard_bindings.next_weapon)},
                    {"inventory_previous", scancode_name(keyboard_bindings.inventory_previous)},
                    {"inventory_next", scancode_name(keyboard_bindings.inventory_next)}
                }}
            }.dump(4) << '\n';
        }
        return;
    }
    try {
        const nlohmann::json config = nlohmann::json::parse(std::ifstream(config_path));
        mouse_sensitivity = std::clamp(config.value("mouse_sensitivity", mouse_sensitivity), 0.1f, 4.0f);
        window_width = std::clamp(config.value("window_width", window_width), 640, 7680);
        window_height = std::clamp(config.value("window_height", window_height), 360, 4320);
        controller_deadzone = std::clamp(config.value("controller_deadzone", controller_deadzone), 0.0f, 0.9f);
        controller_sensitivity = std::clamp(config.value("controller_sensitivity", controller_sensitivity), 0.1f, 4.0f);
        invert_aim_x = config.value("invert_aim_x", invert_aim_x);
        invert_aim_y = config.value("invert_aim_y", invert_aim_y);
        const nlohmann::json keyboard = config.value("keyboard", nlohmann::json::object());
        const auto read_scancode = [&keyboard](const char* key, SDL_Scancode fallback) {
            if (!keyboard.contains(key) || !keyboard[key].is_string()) return fallback;
            const SDL_Scancode value = SDL_GetScancodeFromName(keyboard[key].get<std::string>().c_str());
            return value == SDL_SCANCODE_UNKNOWN ? fallback : value;
        };
        keyboard_bindings.move_forward = read_scancode("move_forward", keyboard_bindings.move_forward);
        keyboard_bindings.move_backward = read_scancode("move_backward", keyboard_bindings.move_backward);
        keyboard_bindings.strafe_left = read_scancode("strafe_left", keyboard_bindings.strafe_left);
        keyboard_bindings.strafe_right = read_scancode("strafe_right", keyboard_bindings.strafe_right);
        keyboard_bindings.fire = read_scancode("fire", keyboard_bindings.fire);
        keyboard_bindings.jump = read_scancode("jump", keyboard_bindings.jump);
        keyboard_bindings.crouch = read_scancode("crouch", keyboard_bindings.crouch);
        keyboard_bindings.start = read_scancode("start", keyboard_bindings.start);
        keyboard_bindings.open = read_scancode("open", keyboard_bindings.open);
        keyboard_bindings.previous_weapon = read_scancode("previous_weapon", keyboard_bindings.previous_weapon);
        keyboard_bindings.next_weapon = read_scancode("next_weapon", keyboard_bindings.next_weapon);
        keyboard_bindings.inventory_previous = read_scancode("inventory_previous", keyboard_bindings.inventory_previous);
        keyboard_bindings.inventory_next = read_scancode("inventory_next", keyboard_bindings.inventory_next);
    }
    catch (const nlohmann::json::exception& error) {
        std::fprintf(stderr, "Ignoring invalid input config %s: %s\n", config_path.string().c_str(), error.what());
    }
}

static Uint32 mouse_buttons;

static void* create_gfx() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) != 0) {
        std::fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        std::exit(EXIT_FAILURE);
    }
    SDL_AudioSpec desired{};
    SDL_AudioSpec obtained{};
    desired.freq = audio_device_frequency;
    desired.format = audio_format;
    desired.channels = audio_channels;
    desired.samples = audio_device_buffer_samples;
    audio_device = SDL_OpenAudioDevice(nullptr, 0, &desired, &obtained, 0);
    if (audio_device == 0) {
        std::fprintf(stderr, "SDL audio initialization failed: %s\n", SDL_GetError());
        std::exit(EXIT_FAILURE);
    }
    audio_device_frequency = obtained.freq;
    audio_stream = create_audio_stream(audio_frequency);
    if (audio_stream == nullptr) {
        std::fprintf(stderr, "SDL audio conversion initialization failed: %s\n", SDL_GetError());
        std::exit(EXIT_FAILURE);
    }
    SDL_PauseAudioDevice(audio_device, 0);
    return nullptr;
}
static ultramodern::renderer::WindowHandle create_window(void*) {
    window = SDL_CreateWindow("Duke Nukem 64: Recompiled", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              window_width, window_height, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::fprintf(stderr, "SDL window creation failed: %s\n", SDL_GetError());
        std::exit(EXIT_FAILURE);
    }
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_SysWMinfo info{};
    SDL_VERSION(&info.version);
    if (!SDL_GetWindowWMInfo(window, &info)) {
        std::fprintf(stderr, "SDL window handle query failed: %s\n", SDL_GetError());
        std::exit(EXIT_FAILURE);
    }
    return { info.info.win.window, GetCurrentThreadId() };
}

static void save_screenshot() {
    if (window == nullptr) return;

    int width = 0;
    int height = 0;
    SDL_GetWindowSize(window, &width, &height);
    SDL_SysWMinfo info{};
    SDL_VERSION(&info.version);
    if (width <= 0 || height <= 0 || !SDL_GetWindowWMInfo(window, &info)) return;

    HDC source = GetDC(info.info.win.window);
    HDC desktop = GetDC(nullptr);
    if (source == nullptr || desktop == nullptr) {
        if (source != nullptr) ReleaseDC(info.info.win.window, source);
        if (desktop != nullptr) ReleaseDC(nullptr, desktop);
        return;
    }
    HDC capture = CreateCompatibleDC(desktop);
    HBITMAP bitmap = CreateCompatibleBitmap(desktop, width, height);
    if (capture == nullptr || bitmap == nullptr) {
        if (bitmap != nullptr) DeleteObject(bitmap);
        if (capture != nullptr) DeleteDC(capture);
        ReleaseDC(nullptr, desktop);
        ReleaseDC(info.info.win.window, source);
        return;
    }
    HGDIOBJ previous = SelectObject(capture, bitmap);
    const bool copied = BitBlt(capture, 0, 0, width, height, source, 0, 0, SRCCOPY | CAPTUREBLT) != 0;

    std::vector<uint8_t> pixels(static_cast<size_t>(width) * static_cast<size_t>(height) * 4);
    BITMAPINFO bitmap_info{};
    bitmap_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmap_info.bmiHeader.biWidth = width;
    bitmap_info.bmiHeader.biHeight = -height;
    bitmap_info.bmiHeader.biPlanes = 1;
    bitmap_info.bmiHeader.biBitCount = 32;
    bitmap_info.bmiHeader.biCompression = BI_RGB;
    const bool read = copied && GetDIBits(capture, bitmap, 0, height, pixels.data(), &bitmap_info, DIB_RGB_COLORS) != 0;
    SelectObject(capture, previous);
    DeleteObject(bitmap);
    DeleteDC(capture);
    ReleaseDC(nullptr, desktop);
    ReleaseDC(info.info.win.window, source);
    if (!read) return;

    const auto screenshot_directory = screenshot_path / "screenshots";
    std::filesystem::create_directories(screenshot_directory);
    for (int index = 0; index < 10000; ++index) {
        const auto path = screenshot_directory / ("duke64-" + std::to_string(index) + ".bmp");
        if (std::filesystem::exists(path)) continue;
        SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
            pixels.data(), width, height, 32, width * 4,
            0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
        if (surface != nullptr) {
            if (SDL_SaveBMP(surface, path.string().c_str()) == 0)
                std::fprintf(stderr, "Screenshot saved: %s\n", path.string().c_str());
            SDL_FreeSurface(surface);
        }
        return;
    }
}

static void update_gfx(void*) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            ultramodern::quit();
        }
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_F12 &&
                 event.key.repeat == 0) {
            save_screenshot();
        }
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN &&
                 (event.key.keysym.mod & KMOD_ALT) != 0 && event.key.repeat == 0) {
            const bool fullscreen = (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP) != 0;
            SDL_SetWindowFullscreen(window, fullscreen ? 0 : SDL_WINDOW_FULLSCREEN_DESKTOP);
        }
        else if (event.type == SDL_WINDOWEVENT &&
                 event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
            SDL_SetRelativeMouseMode(SDL_FALSE);
            mouse_turn = 0;
            mouse_look = 0;
        }
        else if (event.type == SDL_WINDOWEVENT &&
                 event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
            SDL_SetRelativeMouseMode(SDL_TRUE);
        }
        else if (event.type == SDL_CONTROLLERDEVICEREMOVED) {
            for (SDL_GameController*& game_controller : controllers) {
                if (game_controller != nullptr &&
                    SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(game_controller)) == event.cdevice.which) {
                    SDL_GameControllerClose(game_controller);
                    game_controller = nullptr;
                    break;
                }
            }
        }
    }
}
static void close_controller(int controller_slot) {
    SDL_GameController*& game_controller = controllers[controller_slot];
    if (game_controller != nullptr) {
        SDL_GameControllerClose(game_controller);
        game_controller = nullptr;
    }
}
static void poll_input() {
    SDL_GameControllerUpdate();
    for (int slot = 0; slot < static_cast<int>(controllers.size()); ++slot) {
        if (controllers[slot] != nullptr && !SDL_GameControllerGetAttached(controllers[slot])) {
            close_controller(slot);
        }
    }
    for (int device_index = 0; device_index < SDL_NumJoysticks(); ++device_index) {
        if (!SDL_IsGameController(device_index)) continue;
        const SDL_JoystickID instance_id = SDL_JoystickGetDeviceInstanceID(device_index);
        bool already_open = false;
        for (SDL_GameController* game_controller : controllers) {
            if (game_controller != nullptr &&
                SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(game_controller)) == instance_id) {
                already_open = true;
                break;
            }
        }
        if (already_open) continue;
        for (int slot = 0; slot < static_cast<int>(controllers.size()); ++slot) {
            if (controllers[slot] == nullptr) {
                controllers[slot] = SDL_GameControllerOpen(device_index);
                break;
            }
        }
    }
    mouse_buttons = SDL_GetRelativeMouseState(&mouse_turn, &mouse_look);
}
static float normalize_stick_axis(Sint16 value, bool invert) {
    const float deadzone = std::clamp(controller_deadzone, 0.0f, 0.9f);
    const float normalized = static_cast<float>(value) / 32767.0f;
    const float magnitude = std::abs(normalized);
    if (magnitude <= deadzone) return 0.0f;
    float result = std::copysign((magnitude - deadzone) / (1.0f - deadzone), normalized);
    result = std::clamp(result * controller_sensitivity, -1.0f, 1.0f);
    return invert ? -result : result;
}

static bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    constexpr uint16_t N64_A = 0x8000;
    constexpr uint16_t N64_B = 0x4000;
    constexpr uint16_t N64_Z = 0x2000;
    constexpr uint16_t N64_START = 0x1000;
    constexpr uint16_t N64_DPAD_UP = 0x0800;
    constexpr uint16_t N64_DPAD_DOWN = 0x0400;
    constexpr uint16_t N64_DPAD_LEFT = 0x0200;
    constexpr uint16_t N64_DPAD_RIGHT = 0x0100;
    constexpr uint16_t N64_L = 0x0020;
    constexpr uint16_t N64_R = 0x0010;
    constexpr uint16_t N64_C_UP = 0x0008;
    constexpr uint16_t N64_C_DOWN = 0x0004;
    constexpr uint16_t N64_C_LEFT = 0x0002;
    constexpr uint16_t N64_C_RIGHT = 0x0001;

    if (controller_num > 0) {
        const size_t physical_slot = static_cast<size_t>(controller_num - 1);
        if (physical_slot >= controllers.size() || controllers[physical_slot] == nullptr ||
            !SDL_GameControllerGetAttached(controllers[physical_slot])) {
            return false;
        }
        SDL_GameController* game_controller = controllers[physical_slot];
        auto pressed = [game_controller](SDL_GameControllerButton button) {
            return SDL_GameControllerGetButton(game_controller, button) != 0;
        };
        uint16_t state = 0;
        const float left_x = normalize_stick_axis(
            SDL_GameControllerGetAxis(game_controller, SDL_CONTROLLER_AXIS_LEFTX), false);
        const float left_y = normalize_stick_axis(
            SDL_GameControllerGetAxis(game_controller, SDL_CONTROLLER_AXIS_LEFTY), false);
        const float right_x = normalize_stick_axis(
            SDL_GameControllerGetAxis(game_controller, SDL_CONTROLLER_AXIS_RIGHTX), invert_aim_x);
        const float right_y = normalize_stick_axis(
            SDL_GameControllerGetAxis(game_controller, SDL_CONTROLLER_AXIS_RIGHTY), invert_aim_y);
        if (pressed(SDL_CONTROLLER_BUTTON_A)) state |= N64_C_UP;       // Jump.
        if (pressed(SDL_CONTROLLER_BUTTON_B)) state |= N64_C_DOWN;     // Crouch.
        if (pressed(SDL_CONTROLLER_BUTTON_X) ||
            SDL_GameControllerGetAxis(game_controller, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 16000)
            state |= N64_Z;                                           // Fire.
        if (pressed(SDL_CONTROLLER_BUTTON_Y)) state |= N64_A;          // Next weapon.
        if (pressed(SDL_CONTROLLER_BUTTON_START)) state |= N64_START;
        if (pressed(SDL_CONTROLLER_BUTTON_DPAD_UP) || right_y < -0.35f) state |= N64_DPAD_UP;
        if (pressed(SDL_CONTROLLER_BUTTON_DPAD_DOWN) || right_y > 0.35f) state |= N64_DPAD_DOWN;
        if (pressed(SDL_CONTROLLER_BUTTON_DPAD_LEFT) || left_x < -0.35f) state |= N64_DPAD_LEFT;
        if (pressed(SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || left_x > 0.35f) state |= N64_DPAD_RIGHT;
        if (pressed(SDL_CONTROLLER_BUTTON_LEFTSHOULDER)) state |= N64_L; // Inventory.
        if (pressed(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)) state |= N64_R; // Open/use.
        *buttons = state;
        *x = right_x;
        *y = left_y;
        return true;
    }
    if (controller_num != 0) return false;

    const Uint8* keys = SDL_GetKeyboardState(nullptr);
    auto pressed = [keys](SDL_Scancode key) { return keys[key] != 0; };
    uint16_t state = 0;
    const bool mouse_left = (mouse_buttons & SDL_BUTTON_LMASK) != 0;
    if (pressed(SDL_SCANCODE_LCTRL) || pressed(keyboard_bindings.fire) || mouse_left)
        state |= N64_Z;                                               // PC fire.
    if (pressed(keyboard_bindings.jump)) state |= N64_C_UP;            // PC jump.
    if (pressed(keyboard_bindings.crouch)) state |= N64_C_DOWN;        // PC crouch.
    if (pressed(keyboard_bindings.start) || pressed(SDL_SCANCODE_ESCAPE)) state |= N64_START;
    if (pressed(SDL_SCANCODE_UP) || mouse_look < -2) state |= N64_DPAD_UP;
    if (pressed(SDL_SCANCODE_DOWN) || mouse_look > 2) state |= N64_DPAD_DOWN;
    if (pressed(keyboard_bindings.strafe_left)) state |= N64_DPAD_LEFT;  // PC strafe left.
    if (pressed(keyboard_bindings.strafe_right)) state |= N64_DPAD_RIGHT; // PC strafe right.
    if (pressed(keyboard_bindings.inventory_previous)) state |= N64_C_LEFT;
    if (pressed(keyboard_bindings.inventory_next)) state |= N64_C_RIGHT;
    if (pressed(keyboard_bindings.open)) state |= N64_R;                // Open/use.
    if (pressed(keyboard_bindings.previous_weapon) || pressed(SDL_SCANCODE_PAGEUP)) state |= N64_B;
    if (pressed(keyboard_bindings.next_weapon) || pressed(SDL_SCANCODE_PAGEDOWN)) state |= N64_A;
    *x = std::clamp(static_cast<float>(mouse_turn) * 0.75f * mouse_sensitivity, -80.0f, 80.0f);
    *y = static_cast<float>(pressed(keyboard_bindings.move_backward) - pressed(keyboard_bindings.move_forward));
    return true;
}
static void set_rumble(int controller_num, bool enabled) {
    if (controller_num <= 0) return;
    const size_t physical_slot = static_cast<size_t>(controller_num - 1);
    if (physical_slot < controllers.size() && controllers[physical_slot] != nullptr &&
        SDL_GameControllerGetAttached(controllers[physical_slot])) {
        SDL_GameControllerRumble(controllers[physical_slot], enabled ? 0xFFFF : 0,
                                 enabled ? 0xFFFF : 0, enabled ? 250 : 0);
    }
}
static ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num) {
    if (controller_num == 0) {
        // The keyboard and mouse form the always-available first local player.
        return { ultramodern::input::Device::Controller, ultramodern::input::Pak::None };
    }
    const size_t physical_slot = static_cast<size_t>(controller_num - 1);
    if (physical_slot < controllers.size() && controllers[physical_slot] != nullptr &&
        SDL_GameControllerGetAttached(controllers[physical_slot])) {
        return { ultramodern::input::Device::Controller, ultramodern::input::Pak::ControllerPak };
    }
    return { ultramodern::input::Device::None, ultramodern::input::Pak::None };
}
// Runtime lifecycle notifications are not needed by the SDL/RT64 frontend.
static void vi_callback() {}
static void gfx_init_callback() {}
static void message_box(const char* msg) { std::fprintf(stderr, "%s\n", msg); }
static std::string thread_name(const OSThread*) { return "duke64"; }

int main(int argc, char** argv) {
    const auto data_path = get_user_data_path(argv[0]);
    std::error_code data_path_error;
    std::filesystem::create_directories(data_path, data_path_error);
    if (data_path_error) {
        std::fprintf(stderr, "Failed to create user data path %s: %s\n",
                     data_path.string().c_str(), data_path_error.message().c_str());
        return EXIT_FAILURE;
    }
    screenshot_path = data_path;
    recomp::register_config_path(data_path);
    load_input_config(data_path);

    recomp::rsp::callbacks_t rsp_callbacks{ .get_rsp_microcode = get_rsp_microcode };
    const std::filesystem::path stored_rom_path = data_path / "dukenukem.z64";
    if (!std::filesystem::exists(stored_rom_path)) {
        const auto exe_dir = std::filesystem::absolute(argv[0]).parent_path();
        for (const auto& rom_dir : {
            std::filesystem::current_path(),
            std::filesystem::current_path().parent_path(),
            exe_dir,
            exe_dir.parent_path()
        }) {
            for (const auto& filename : {
                "Duke Nukem 64 (USA).z64",
                "dukenukem.z64",
                "Duke Nukem 64 (U) [!].z64"
            }) {
                const auto candidate = rom_dir / filename;
                if (std::filesystem::exists(candidate)) {
                    std::error_code copy_error;
                    std::filesystem::copy_file(candidate, stored_rom_path, std::filesystem::copy_options::none, copy_error);
                    if (!copy_error) break;
                    std::fprintf(stderr, "Failed to cache ROM %s: %s\n",
                                 candidate.string().c_str(), copy_error.message().c_str());
                }
            }
            if (std::filesystem::exists(stored_rom_path)) break;
        }
    }
    recomp::GameEntry game{
        .rom_hash = 0xE19B16ED3BC8262FULL,
        .internal_name = "",
        .display_name = "Duke Nukem 64",
        .game_id = u8"dukenukem",
        .mod_game_id = "dukenukem",
        .save_type = recomp::SaveType::AllowAll,
        .entrypoint_address = static_cast<gpr>(static_cast<int32_t>(0x8004B400)),
        .entrypoint = recomp_entrypoint,
    };
    recomp::register_game(game);
    recomp::overlays::register_manual_patch_symbols(manual_patch_symbols);
    recomp::overlays::register_overlays(
        { section_table, 2, num_sections },
        { overlay_sections_by_index, sizeof(overlay_sections_by_index) / sizeof(overlay_sections_by_index[0]) }
    );
    std::vector<char*> runtime_argv(argv, argv + argc);
    bool has_game_argument = false;
    for (int i = 1; i < argc; ++i) {
        has_game_argument |= std::string(argv[i]) == "--game";
    }
    if (!has_game_argument) {
        runtime_argv.push_back(const_cast<char*>("--game"));
        runtime_argv.push_back(const_cast<char*>("dukenukem"));
    }
    argc = static_cast<int>(runtime_argv.size());
    argv = runtime_argv.data();
    ultramodern::renderer::callbacks_t renderer_callbacks{ .create_render_context = create_render_context };
    ultramodern::gfx_callbacks_t gfx_callbacks{ .create_gfx = create_gfx, .create_window = create_window, .update_gfx = update_gfx };
    ultramodern::audio_callbacks_t audio_callbacks{ .queue_samples = queue_samples, .get_frames_remaining = get_frames_remaining, .set_frequency = set_frequency };
    ultramodern::input::callbacks_t input_callbacks{ .poll_input = poll_input, .get_input = get_input, .set_rumble = set_rumble, .get_connected_device_info = get_connected_device_info };
    ultramodern::events::callbacks_t events_callbacks{ .vi_callback = vi_callback, .gfx_init_callback = gfx_init_callback };
    ultramodern::error_handling::callbacks_t errors{ .message_box = message_box };
    ultramodern::threads::callbacks_t threads{ .get_game_thread_name = thread_name };
    recomp::Configuration config{};
    config.message_queue_control.requeue_vi = true;
    config.argc = argc;
    config.argv = argv;
    config.project_version = recomp::Version{ 0, 1, 0 };
    config.rsp_callbacks = rsp_callbacks;
    config.renderer_callbacks = renderer_callbacks;
    config.audio_callbacks = audio_callbacks;
    config.input_callbacks = input_callbacks;
    config.gfx_callbacks = gfx_callbacks;
    config.events_callbacks = events_callbacks;
    config.error_handling_callbacks = errors;
    recomp::start(config);
    return 0;
}
