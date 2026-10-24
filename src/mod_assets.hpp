#pragma once

#include <filesystem>
#include <vector>

#include "render/rt64_texture_cache.h"

namespace duke64 {

void register_mod_asset_content_types();
std::vector<RT64::ReplacementDirectory> get_texture_replacement_directories();

}

extern "C" void duke64_refresh_asset_packs();
