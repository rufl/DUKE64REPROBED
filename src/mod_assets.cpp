#include "mod_assets.hpp"

#include "duke64_asset_hooks.h"
#include "json/json.hpp"
#include "librecomp/mods.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <limits>
#include <map>
#include <mutex>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

namespace {
using json = nlohmann::json;

extern "C" void duke64_audio_queue_samples(const int16_t* samples, size_t sample_count, uint32_t sample_rate);
extern "C" void duke64_audio_start_music(const int16_t* samples, size_t sample_count, uint32_t sample_rate);
extern "C" void duke64_audio_stop_music();

constexpr std::string_view asset_manifest_name = "duke64.assets.json";
constexpr std::string_view texture_manifest_name = "rt64.json";
constexpr int max_audio_id = 4095;
constexpr size_t max_manifest_bytes = 4 * 1024 * 1024;
constexpr size_t max_voxel_bytes = 64 * 1024 * 1024;

struct AudioClip {
    std::vector<int16_t> samples;
    uint32_t sample_rate = 0;
};

struct VoxelEntry {
    int tile = -1;
    std::string model_path;
    std::string texture_path;
};

struct PendingTextureDirectory {
    std::filesystem::path path;
    std::string zip_base;
};

struct AssetPack {
    std::string mod_id;
    std::filesystem::path root_path;
    std::optional<PendingTextureDirectory> texture_directory;
    std::unordered_map<int, AudioClip> sounds;
    std::unordered_map<int, AudioClip> music;
    std::vector<VoxelEntry> voxels;
};

std::mutex asset_mutex;
std::unordered_map<std::string, AssetPack> asset_packs;
std::vector<std::string> ordered_asset_ids;
bool content_types_registered = false;
recomp::mods::ModContentTypeId duke64_asset_content_type{ 0 };

std::string normalize_slashes(std::string value) {
    std::replace(value.begin(), value.end(), '\\', '/');
    return value;
}

std::optional<std::string> safe_asset_path(const json& value) {
    if (!value.is_string()) {
        return std::nullopt;
    }

    const std::string raw = normalize_slashes(value.get<std::string>());
    if (raw.empty() || raw.front() == '/' || raw.find(':') != std::string::npos) {
        return std::nullopt;
    }

    const std::filesystem::path path(raw);
    if (path.is_absolute() || path.has_root_name() || path.has_root_directory()) {
        return std::nullopt;
    }

    std::string result;
    for (const auto& component : path) {
        const std::string part = component.generic_string();
        if (part.empty() || part == ".") {
            continue;
        }
        if (part == "..") {
            return std::nullopt;
        }
        if (!result.empty()) {
            result.push_back('/');
        }
        result += part;
    }
    return result.empty() ? std::nullopt : std::optional<std::string>{ std::move(result) };
}

std::string append_asset_path(std::string_view base, std::string_view child) {
    if (base.empty()) {
        return std::string(child);
    }
    std::string result(base);
    result.push_back('/');
    result += child;
    return result;
}

std::optional<std::vector<char>> read_asset(const recomp::mods::ModHandle& mod, std::string_view path, bool enforce_size = true) {
    bool exists = false;
    std::vector<char> data = mod.manifest.file_handle->read_file(std::string(path), exists);
    if (!exists || (enforce_size && data.size() > max_manifest_bytes)) {
        return std::nullopt;
    }
    return data;
}

std::optional<json> read_json_asset(const recomp::mods::ModHandle& mod, std::string_view path) {
    const auto data = read_asset(mod, path);
    if (!data) {
        return std::nullopt;
    }
    try {
        json parsed = json::parse(data->begin(), data->end(), nullptr, true);
        return parsed;
    }
    catch (const json::exception& error) {
        std::fprintf(stderr, "Ignoring invalid asset manifest %.*s in mod %s: %s\n",
                     static_cast<int>(path.size()), path.data(), mod.manifest.mod_id.c_str(), error.what());
        return std::nullopt;
    }
}

uint16_t read_u16(const uint8_t* data) {
    return static_cast<uint16_t>(data[0]) |
        static_cast<uint16_t>(data[1] << 8);
}

uint32_t read_u32(const uint8_t* data) {
    return static_cast<uint32_t>(data[0]) |
        (static_cast<uint32_t>(data[1]) << 8) |
        (static_cast<uint32_t>(data[2]) << 16) |
        (static_cast<uint32_t>(data[3]) << 24);
}

int16_t clamp_sample(double value) {
    const double clamped = std::clamp(value, -32768.0, 32767.0);
    return static_cast<int16_t>(std::lround(clamped));
}

std::optional<AudioClip> decode_wav(const std::vector<char>& data, float volume) {
    if (data.size() < 12 || std::memcmp(data.data(), "RIFF", 4) != 0 ||
        std::memcmp(data.data() + 8, "WAVE", 4) != 0) {
        return std::nullopt;
    }

    uint16_t format = 0;
    uint16_t channels = 0;
    uint16_t bits_per_sample = 0;
    uint32_t sample_rate = 0;
    const uint8_t* sample_data = nullptr;
    size_t sample_data_size = 0;

    size_t offset = 12;
    while (offset + 8 <= data.size()) {
        const uint8_t* chunk = reinterpret_cast<const uint8_t*>(data.data() + offset);
        const uint32_t chunk_size = read_u32(chunk + 4);
        offset += 8;
        if (chunk_size > data.size() - offset) {
            return std::nullopt;
        }

        if (std::memcmp(chunk, "fmt ", 4) == 0 && chunk_size >= 16) {
            format = read_u16(reinterpret_cast<const uint8_t*>(data.data() + offset));
            channels = read_u16(reinterpret_cast<const uint8_t*>(data.data() + offset + 2));
            sample_rate = read_u32(reinterpret_cast<const uint8_t*>(data.data() + offset + 4));
            bits_per_sample = read_u16(reinterpret_cast<const uint8_t*>(data.data() + offset + 14));
        }
        else if (std::memcmp(chunk, "data", 4) == 0) {
            sample_data = reinterpret_cast<const uint8_t*>(data.data() + offset);
            sample_data_size = chunk_size;
        }

        offset += chunk_size + (chunk_size & 1u);
    }

    if ((format != 1 && format != 3) || channels == 0 || sample_rate == 0 ||
        sample_data == nullptr || sample_data_size == 0 ||
        (format == 1 && (bits_per_sample != 8 && bits_per_sample != 16 && bits_per_sample != 24 && bits_per_sample != 32)) ||
        (format == 3 && bits_per_sample != 32)) {
        return std::nullopt;
    }

    const size_t bytes_per_channel = bits_per_sample / 8;
    const size_t bytes_per_frame = bytes_per_channel * channels;
    if (bytes_per_channel == 0 || bytes_per_frame == 0) {
        return std::nullopt;
    }
    const size_t frame_count = sample_data_size / bytes_per_frame;
    if (frame_count == 0 || frame_count > 20'000'000 || frame_count > (std::numeric_limits<size_t>::max() / 2)) {
        return std::nullopt;
    }

    AudioClip clip;
    clip.sample_rate = sample_rate;
    clip.samples.resize(frame_count * 2);
    const float safe_volume = std::clamp(volume, 0.0f, 4.0f);

    auto read_channel = [&](const uint8_t* frame, uint16_t channel) -> double {
        const uint8_t* sample = frame + bytes_per_channel * std::min<uint16_t>(channel, channels - 1);
        if (format == 3) {
            float result = 0.0f;
            std::memcpy(&result, sample, sizeof(result));
            return std::clamp(static_cast<double>(result), -1.0, 1.0) * 32767.0;
        }
        switch (bits_per_sample) {
        case 8:
            return (static_cast<int>(sample[0]) - 128) * 256.0;
        case 16:
            return static_cast<double>(static_cast<int16_t>(read_u16(sample)));
        case 24: {
            int32_t value = static_cast<int32_t>(sample[0]) |
                (static_cast<int32_t>(sample[1]) << 8) |
                (static_cast<int32_t>(sample[2]) << 16);
            if ((value & 0x00800000) != 0) {
                value |= ~0x00FFFFFF;
            }
            return static_cast<double>(value >> 8);
        }
        case 32: {
            int32_t value = static_cast<int32_t>(read_u32(sample));
            return static_cast<double>(value) / 65536.0;
        }
        default:
            return 0.0;
        }
    };

    for (size_t frame_index = 0; frame_index < frame_count; ++frame_index) {
        const uint8_t* frame = sample_data + frame_index * bytes_per_frame;
        const double left = read_channel(frame, 0) * safe_volume;
        const double right = read_channel(frame, channels > 1 ? 1 : 0) * safe_volume;
        clip.samples[frame_index * 2] = clamp_sample(left);
        clip.samples[frame_index * 2 + 1] = clamp_sample(right);
    }
    return clip;
}

bool scan_vox_chunks(const std::vector<char>& data, size_t begin, size_t end, bool& has_size, bool& has_xyzi) {
    while (begin + 12 <= end) {
        const uint8_t* chunk = reinterpret_cast<const uint8_t*>(data.data() + begin);
        const uint32_t content_size = read_u32(chunk + 4);
        const uint32_t children_size = read_u32(chunk + 8);
        const size_t payload_begin = begin + 12;
        if (content_size > end - payload_begin || children_size > end - payload_begin - content_size) {
            return false;
        }
        const size_t children_begin = payload_begin + content_size;
        const size_t next = children_begin + children_size;

        if (std::memcmp(chunk, "SIZE", 4) == 0 && content_size >= 12) {
            const uint8_t* size_data = reinterpret_cast<const uint8_t*>(data.data() + payload_begin);
            has_size = read_u32(size_data) > 0 && read_u32(size_data + 4) > 0 && read_u32(size_data + 8) > 0;
        }
        else if (std::memcmp(chunk, "XYZI", 4) == 0 && content_size >= 4) {
            const uint8_t* voxel_data = reinterpret_cast<const uint8_t*>(data.data() + payload_begin);
            const uint32_t voxel_count = read_u32(voxel_data);
            has_xyzi = voxel_count <= (content_size - 4) / 4;
        }

        if (children_size != 0 && !scan_vox_chunks(data, children_begin, next, has_size, has_xyzi)) {
            return false;
        }
        begin = next;
    }
    return begin == end;
}

bool validate_vox(const std::vector<char>& data) {
    if (data.size() < 20 || std::memcmp(data.data(), "VOX ", 4) != 0 || read_u32(reinterpret_cast<const uint8_t*>(data.data() + 4)) == 0) {
        return false;
    }
    bool has_size = false;
    bool has_xyzi = false;
    return scan_vox_chunks(data, 8, data.size(), has_size, has_xyzi) && has_size && has_xyzi;
}

bool parse_audio_manifest(const recomp::mods::ModHandle& mod, const json& manifest, std::unordered_map<int, AudioClip>& output) {
    if (!manifest.is_object() || !manifest.contains("entries")) {
        return false;
    }

    std::vector<json> entries;
    const json& raw_entries = manifest.at("entries");
    if (raw_entries.is_array()) {
        entries.assign(raw_entries.begin(), raw_entries.end());
    }
    else if (raw_entries.is_object()) {
        for (const auto& [id, file] : raw_entries.items()) {
            entries.push_back(json{ {"id", id}, {"file", file} });
        }
    }
    else {
        return false;
    }

    bool any_loaded = false;
    for (const json& entry : entries) {
        if (!entry.is_object()) {
            continue;
        }
        int id = entry.value("id", -1);
        if (id < 0 || id > max_audio_id) {
            continue;
        }
        const json& path_value = entry.contains("file") ? entry.at("file") : entry.value("path", json{});
        const auto path = safe_asset_path(path_value);
        if (!path) {
            std::fprintf(stderr, "Ignoring unsafe audio path in mod %s\n", mod.manifest.mod_id.c_str());
            continue;
        }
        const auto data = read_asset(mod, *path, false);
        if (!data) {
            std::fprintf(stderr, "Missing audio asset %s in mod %s\n", path->c_str(), mod.manifest.mod_id.c_str());
            continue;
        }
        if (data->size() > max_voxel_bytes) {
            std::fprintf(stderr, "Audio asset %s is too large in mod %s\n", path->c_str(), mod.manifest.mod_id.c_str());
            continue;
        }
        const float volume = entry.value("volume", 1.0f);
        auto clip = decode_wav(*data, volume);
        if (!clip) {
            std::fprintf(stderr, "Unsupported or invalid WAV %s in mod %s\n", path->c_str(), mod.manifest.mod_id.c_str());
            continue;
        }
        output[id] = std::move(*clip);
        any_loaded = true;
    }
    return any_loaded;
}

bool parse_voxel_manifest(const recomp::mods::ModHandle& mod, const json& manifest, std::vector<VoxelEntry>& output) {
    if (!manifest.is_object() || !manifest.contains("entries") || !manifest.at("entries").is_array()) {
        return false;
    }

    bool any_loaded = false;
    for (const json& entry : manifest.at("entries")) {
        if (!entry.is_object()) {
            continue;
        }
        const int tile = entry.value("tile", -1);
        const auto model = safe_asset_path(entry.value("model", json{}));
        if (tile < 0 || tile > 65535 || !model) {
            continue;
        }
        const auto data = read_asset(mod, *model, false);
        if (!data || data->size() > max_voxel_bytes || !validate_vox(*data)) {
            std::fprintf(stderr, "Invalid MagicaVoxel asset %s in mod %s\n", model->c_str(), mod.manifest.mod_id.c_str());
            continue;
        }

        VoxelEntry voxel{ .tile = tile, .model_path = *model };
        if (entry.contains("texture")) {
            const auto texture = safe_asset_path(entry.at("texture"));
            if (texture && mod.manifest.file_handle->file_exists(*texture)) {
                voxel.texture_path = *texture;
            }
        }
        output.push_back(std::move(voxel));
        any_loaded = true;
    }
    return any_loaded;
}

std::optional<std::string> get_texture_base(const recomp::mods::ModHandle& mod, const json* asset_manifest) {
    auto texture_manifest_is_nonempty = [&](const std::string& path) {
        const auto manifest = read_json_asset(mod, path);
        return manifest && manifest->is_object() &&
            manifest->contains("textures") && (*manifest)["textures"].is_array() &&
            !(*manifest)["textures"].empty();
    };

    if (asset_manifest != nullptr && asset_manifest->contains("textures")) {
        const auto configured = safe_asset_path(asset_manifest->at("textures"));
        if (!configured) {
            return std::nullopt;
        }
        if (configured->size() >= texture_manifest_name.size() &&
            configured->compare(configured->size() - texture_manifest_name.size(), texture_manifest_name.size(), texture_manifest_name) == 0) {
            const std::filesystem::path file_path(*configured);
            const std::string parent = file_path.parent_path().generic_string();
            if (mod.manifest.file_handle->file_exists(*configured) &&
                texture_manifest_is_nonempty(*configured)) {
                return parent;
            }
            return std::nullopt;
        }
        const std::string marker = append_asset_path(*configured, texture_manifest_name);
        if (mod.manifest.file_handle->file_exists(marker) &&
            texture_manifest_is_nonempty(marker)) {
            return *configured;
        }
        return std::nullopt;
    }

    if (mod.manifest.file_handle->file_exists("rt64.json") &&
        texture_manifest_is_nonempty("rt64.json")) {
        return std::string{};
    }
    if (mod.manifest.file_handle->file_exists("assets/textures/rt64.json") &&
        texture_manifest_is_nonempty("assets/textures/rt64.json")) {
        return std::string("assets/textures");
    }
    return std::nullopt;
}

std::optional<AssetPack> load_asset_pack(const recomp::mods::ModHandle& mod) {
    const bool has_asset_manifest = mod.manifest.file_handle->file_exists(std::string(asset_manifest_name));
    const bool has_texture_manifest = mod.manifest.file_handle->file_exists(std::string(texture_manifest_name));
    if (!has_asset_manifest && !has_texture_manifest) {
        return std::nullopt;
    }

    std::optional<json> asset_manifest;
    if (has_asset_manifest) {
        asset_manifest = read_json_asset(mod, asset_manifest_name);
        if (!asset_manifest || !asset_manifest->is_object()) {
            return std::nullopt;
        }
        if (asset_manifest->value("version", 1) != 1) {
            std::fprintf(stderr, "Unsupported Duke64 asset manifest version in mod %s\n", mod.manifest.mod_id.c_str());
            return std::nullopt;
        }
    }

    AssetPack pack;
    pack.mod_id = mod.manifest.mod_id;
    pack.root_path = mod.manifest.mod_root_path;

    const auto texture_base = get_texture_base(mod, asset_manifest ? &*asset_manifest : nullptr);
    if (texture_base) {
        const bool is_archive = std::filesystem::is_regular_file(pack.root_path);
        if (is_archive) {
            pack.texture_directory = PendingTextureDirectory{ pack.root_path, *texture_base };
        }
        else {
            pack.texture_directory = PendingTextureDirectory{
                pack.root_path / std::filesystem::path(*texture_base), {}
            };
        }
    }

    if (asset_manifest) {
        const auto load_json_path = [&](std::string_view key) -> std::optional<json> {
            if (!asset_manifest->contains(key)) {
                return std::nullopt;
            }
            const auto path = safe_asset_path(asset_manifest->at(key));
            if (!path) {
                std::fprintf(stderr, "Ignoring unsafe %.*s path in mod %s\n",
                             static_cast<int>(key.size()), key.data(), mod.manifest.mod_id.c_str());
                return std::nullopt;
            }
            return read_json_asset(mod, *path);
        };

        if (const auto voxels = load_json_path("voxels")) {
            parse_voxel_manifest(mod, *voxels, pack.voxels);
        }
        if (const auto sounds = load_json_path("sounds")) {
            parse_audio_manifest(mod, *sounds, pack.sounds);
        }
        if (const auto music = load_json_path("music")) {
            parse_audio_manifest(mod, *music, pack.music);
        }
    }

    if (!pack.texture_directory && pack.sounds.empty() && pack.music.empty() && pack.voxels.empty()) {
        return std::nullopt;
    }
    return pack;
}
size_t get_order(const AssetPack& pack) {
    const size_t order = recomp::mods::get_mod_order_index(pack.mod_id);
    return order == static_cast<size_t>(-1) ? std::numeric_limits<size_t>::max() : order;
}

void rebuild_asset_order_locked() {
    ordered_asset_ids.clear();
    ordered_asset_ids.reserve(asset_packs.size());
    for (const auto& [mod_id, unused_pack] : asset_packs) {
        (void)unused_pack;
        ordered_asset_ids.push_back(mod_id);
    }
    std::sort(ordered_asset_ids.begin(), ordered_asset_ids.end(), [](const std::string& lhs, const std::string& rhs) {
        const size_t lhs_order = get_order(asset_packs.at(lhs));
        const size_t rhs_order = get_order(asset_packs.at(rhs));
        return lhs_order == rhs_order ? lhs < rhs : lhs_order < rhs_order;
    });
}

template <typename Member>
const AudioClip* find_audio_clip_locked(int id, Member member) {
    for (auto it = ordered_asset_ids.rbegin(); it != ordered_asset_ids.rend(); ++it) {
        const auto pack_it = asset_packs.find(*it);
        if (pack_it == asset_packs.end()) {
            continue;
        }
        const auto& clips = pack_it->second.*member;
        const auto clip = clips.find(id);
        if (clip != clips.end()) {
            return &clip->second;
        }
    }
    return nullptr;
}

void on_asset_enabled(recomp::mods::ModContext&, const recomp::mods::ModHandle& mod) {
    std::optional<AssetPack> pack;
    try {
        pack = load_asset_pack(mod);
    }
    catch (const std::exception& error) {
        std::fprintf(stderr, "Ignoring malformed Duke64 assets in mod %s: %s\n",
                     mod.manifest.mod_id.c_str(), error.what());
    }
    {
        std::lock_guard lock(asset_mutex);
        if (pack) {
            const size_t voxel_count = pack->voxels.size();
            const size_t sound_count = pack->sounds.size();
            const size_t music_count = pack->music.size();
            const bool has_textures = pack->texture_directory.has_value();
            asset_packs[pack->mod_id] = std::move(*pack);
            std::fprintf(stderr, "Loaded Duke64 assets from %s: textures=%s voxels=%zu sounds=%zu music=%zu\n",
                         mod.manifest.mod_id.c_str(), has_textures ? "yes" : "no", voxel_count, sound_count, music_count);
        }
        else {
            asset_packs.erase(mod.manifest.mod_id);
        }
        rebuild_asset_order_locked();
    }
}

void on_asset_disabled(recomp::mods::ModContext&, const recomp::mods::ModHandle& mod) {
    {
        std::lock_guard lock(asset_mutex);
        asset_packs.erase(mod.manifest.mod_id);
        rebuild_asset_order_locked();
    }
}

void on_assets_reordered(recomp::mods::ModContext&) {
    {
        std::lock_guard lock(asset_mutex);
        rebuild_asset_order_locked();
    }
}


} // namespace

namespace duke64 {

void register_mod_asset_content_types() {
    if (content_types_registered) {
        return;
    }

    duke64_asset_content_type = recomp::mods::register_mod_content_type({
        .content_filename = std::string(asset_manifest_name),
        .allow_runtime_toggle = false,
        .on_enabled = on_asset_enabled,
        .on_disabled = on_asset_disabled,
        .on_reordered = on_assets_reordered
    });

    const std::vector<recomp::mods::ModContentTypeId> asset_types{
        duke64_asset_content_type
    };
    recomp::mods::register_mod_container_type("zip", asset_types, false);
    recomp::mods::register_mod_container_type("pk3", asset_types, false);
    recomp::mods::register_mod_container_type("pk4", asset_types, false);
    content_types_registered = true;
}

std::vector<RT64::ReplacementDirectory> get_texture_replacement_directories() {
    std::lock_guard lock(asset_mutex);
    std::vector<RT64::ReplacementDirectory> result;
    result.reserve(ordered_asset_ids.size());
    for (const std::string& mod_id : ordered_asset_ids) {
        const auto pack_it = asset_packs.find(mod_id);
        if (pack_it != asset_packs.end() && pack_it->second.texture_directory) {
            const auto& pending = *pack_it->second.texture_directory;
            result.emplace_back(pending.path, pending.zip_base);
        }
    }
    return result;
}

} // namespace duke64

extern "C" int duke64_try_play_external_sound(int sound_id, int sprite_id) {
    (void)sprite_id;
    std::lock_guard lock(asset_mutex);
    const AudioClip* clip = find_audio_clip_locked(sound_id, &AssetPack::sounds);
    if (clip == nullptr || clip->samples.empty()) {
        return 0;
    }
    duke64_audio_queue_samples(clip->samples.data(), clip->samples.size(), clip->sample_rate);
    return 1;
}

extern "C" int duke64_try_start_external_music(int music_id) {
    std::lock_guard lock(asset_mutex);
    const AudioClip* clip = find_audio_clip_locked(music_id, &AssetPack::music);
    if (clip == nullptr || clip->samples.empty()) {
        return 0;
    }
    duke64_audio_start_music(clip->samples.data(), clip->samples.size(), clip->sample_rate);
    return 1;
}

extern "C" void duke64_stop_external_music() {
    duke64_audio_stop_music();
}
