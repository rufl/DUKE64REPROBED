#pragma once

#include <cstdint>

namespace duke64 {
    enum class FrameRateMode : std::uint8_t {
        Fps30,
        Fps60,
        Fps90,
        Fps120,
        Fps144,
        Fps165,
        Fps240,
        Fps360,
        Unlocked,
    };

    void set_frame_rate_mode(FrameRateMode mode);
    FrameRateMode get_frame_rate_mode();
    std::uint32_t get_frame_rate_target();
    const char* get_frame_rate_mode_name();
    bool is_frame_rate_unlocked();
}
