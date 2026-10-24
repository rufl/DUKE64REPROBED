# Duke Nukem 64 Recompiled

This directory contains the PC build of the Duke Nukem 64 recompilation. The executable uses N64ModernRuntime, SDL2, and RT64 for runtime services, input, audio, and rendering.

## Building

Configure and build with CMake and Ninja from the repository root:

```powershell
cmake -S Duke64-RE -B Duke64-RE/build-pc-rt64-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
ninja -C Duke64-RE/build-pc-rt64-debug Duke64Recompiled
```

The resulting executable is `Duke64-RE/build-pc-rt64-debug/Duke64Recompiled.exe`.

The Windows executable includes the Duke64-styled application icon at all standard shell sizes.

## ROM and user data

The runtime stores per-user data in `%LOCALAPPDATA%\Duke64Recompiled` on Windows. On first launch it creates this directory and can copy a recognized Duke Nukem 64 ROM into it as `dukenukem.z64`. The original ROM must be legally obtained; it is not distributed by this project.

To keep data beside the executable instead, create an empty `portable.txt` file next to `Duke64Recompiled.exe`. Portable mode uses that executable directory for the ROM cache, configuration, mods, and save data.

The runtime configuration path is shared by the save backends. Controller Pak data is stored as:

```text
duke64.mempak
```

inside the active user-data directory. EEPROM, SRAM, FlashRAM, and other librecomp save files use the same registered configuration path.

## Input

### Keyboard and mouse

The default PC mapping is:

| Action | Default input |
| --- | --- |
| Move | `W` / `S` |
| Strafe | `A` / `D` |
| Turn and aim | Relative mouse movement |
| Fire | Left mouse button, `Left Ctrl`, or `Z` |
| Jump | `Space` |
| Crouch | `C` |
| Open/use | `E` |
| Previous/next weapon | `Q` / `R` |
| Inventory | `Tab` |
| Inventory cycle | `[` / `]` |
| Start/menu | `Enter` or `Escape` |

The N64 controlmap defaults were updated so inventory and strafe actions match these PC controls.

### Xbox-compatible controllers

The first three SDL game controllers are assigned to local multiplayer ports 2–4:

- Left stick: move and strafe.
- Right stick: turn and aim.
- A: jump; B: crouch; X or right trigger: fire; Y: next weapon.
- D-pad: directional aim/strafe input.
- Left shoulder: inventory; right shoulder: open/use; Start: start/menu.

Local multiplayer uses the keyboard/mouse as player 1 and up to three SDL game controllers as players 2–4. The same controller layout supports the built-in split-screen Dukematch and cooperative modes after selecting local multiplayer in the game menus.

Controllers may be connected or disconnected while the game is running. The runtime drops detached devices safely and reports no Controller Pak when no controller is attached.

Controller and mouse behavior is configured in `duke64.json`:

```json
{
    "mouse_sensitivity": 1.0,
    "window_width": 1280,
    "window_height": 720,
    "controller_deadzone": 0.24,
    "controller_sensitivity": 1.0,
    "invert_aim_x": false,
    "invert_aim_y": false,
    "keyboard": {
        "move_forward": "W",
        "move_backward": "S",
        "strafe_left": "A",
        "strafe_right": "D",
        "fire": "Z",
        "jump": "Space",
        "crouch": "C",
        "start": "Return",
        "open": "E",
        "previous_weapon": "Q",
        "next_weapon": "R",
        "inventory_previous": "Left Bracket",
        "inventory_next": "Right Bracket"
    }
}
```

`window_width` and `window_height` are clamped to `640–7680` and `360–4320`. `mouse_sensitivity` and `controller_sensitivity` accept `0.1–4.0`. `controller_deadzone` accepts `0.0–0.9`. Keyboard values use SDL scancode names. Invalid or missing keyboard entries fall back to defaults.

Press `Alt+Enter` to toggle borderless fullscreen. Relative mouse capture is released while the window is unfocused and restored when focus returns.

## Screenshots

Press `F12` during gameplay to write a 32-bit BMP screenshot to the active user-data directory's `screenshots` folder. Files use the name pattern `duke64-N.bmp` and are numbered without overwriting existing captures.

## Audio and runtime fixes

The recompiled audio path includes the ASP indirect-branch target table, FIFO command-list handoff, exact byte copies for unaligned audio command data, synchronous audio-task execution, and scheduler completion ordering. These fixes keep generated RSP audio execution aligned with the original command stream, prevent stale or partially copied commands, and ensure audio completion is posted after the scheduler records its current task.

The host path converts byte-swapped N64 stereo samples into host-native samples, returns libultra's actual DAC-derived rate, and resamples that source rate through SDL's `AUDIO_S16SYS` `SDL_AudioStream` to a fixed 48 kHz stereo device with a 1024-sample buffer. Queue depth is converted back to source-rate frames for `osAiGetLength`, and rate changes drain the old stream before switching. See [AUDIO_PATCHES.md](AUDIO_PATCHES.md) for the complete patch record, affected files, regeneration notes, and verification evidence.

## Save safety

Controller Pak writes are serialized and roll back the in-memory state when the backing file cannot be written. Failed writes return the appropriate controller-pak error instead of reporting success.

The Controller Pak save writer uses a temporary file and preserves the previous save as a `.bak` fallback when replacement fails. In-memory Pak state is rolled back after failed writes. Directory checks reject invalid occupied entries instead of silently reporting success.

Disconnected controller ports are returned with cleared button and stick values plus a no-response status, preventing stale input from carrying into another local player.

ROM cache copy failures are reported to stderr and continue through normal ROM validation rather than terminating through an uncaught filesystem exception.
