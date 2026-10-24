# Duke Nukem 64 Recompiled

This directory contains the PC build of the Duke Nukem 64 recompilation. The executable uses N64ModernRuntime, SDL2, and RT64 for runtime services, input, audio, and rendering.
See the [repository overview](../README.md) for the downloadable first alpha package and GitHub release workflow.

## Scope and alpha status

This is the Windows x64 PC integration of the recompiled game. The first public package is `v0.1.0-alpha.1`; expect incomplete polish and report reproducible issues with the runtime, renderer, input, audio, or launcher.

## Requirements

- Windows 10 or Windows 11 x64.
- A DirectX 12- or Vulkan-capable GPU supported by RT64.
- A legally obtained, compatible Duke Nukem 64 `.z64` ROM.
- For source builds: CMake 3.20 or newer, Ninja, LLVM/Clang, Git, and network access for the configured FetchContent dependencies.

The release archive already contains the game executable, launcher, SDL2, and RT64 shader compiler DLLs. It does not contain the ROM or extracted game assets.

## Building

Configure and build with CMake and Ninja from the repository root:

```powershell
# Debug
cmake -S Duke64-RE -B Duke64-RE/build-pc-rt64-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
ninja -C Duke64-RE/build-pc-rt64-debug Duke64Recompiled Duke64Launcher

# Release
cmake -S Duke64-RE -B Duke64-RE/build-pc-rt64-release -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja -C Duke64-RE/build-pc-rt64-release Duke64Recompiled Duke64Launcher
```

Both configurations place `Duke64Recompiled.exe`, `Duke64Launcher.exe`, `SDL2.dll`, `dxil.dll`, and `dxcompiler.dll` in the build output directory.

## First alpha launcher

The first alpha archive is named:

```text
Duke64Recompiled-v0.1.0-alpha.1-windows-x64.zip
```

Extract the complete archive and keep these files together:

- `Duke64Launcher.exe`
- `Duke64Recompiled.exe`
- `SDL2.dll`
- `dxil.dll`
- `dxcompiler.dll`

Run `Duke64Launcher.exe` and select the legally obtained Duke Nukem 64 `.z64` ROM in the file picker. The launcher passes the selected path to the game, which caches it as `dukenukem.z64` in the active user-data directory before normal ROM hash validation. The ROM is not included in the release package.

For scripted launches, use:

```powershell
.\Duke64Launcher.exe --rom "C:\path\to\dukenukem.z64"
```

`Duke64Recompiled.exe --rom <path>` accepts the same option without the picker. The launcher requires the `.z64` extension, but the game still validates the ROM contents and rejects unsupported dumps.

The Windows executables include the Duke64-styled application icon at all standard shell sizes.

## ROM and user data

The runtime stores per-user data in `%LOCALAPPDATA%\Duke64Recompiled` on Windows. It creates this directory on first launch and uses it for configuration, cached ROM data, mods, saves, and screenshots.

Important files and directories are:

| Path | Purpose |
| --- | --- |
| `dukenukem.z64` | Cached ROM selected by the launcher or discovered at startup. |
| `duke64.json` | Window, mouse, controller, gyro, and keyboard settings. |
| `duke64.mempak` | Persistent Controller Pak data. |
| `screenshots\duke64-N.bmp` | Numbered F12 screenshots. |

To keep data beside the executable instead, create an empty `portable.txt` file next to `Duke64Recompiled.exe`. Portable mode uses that executable directory for the ROM cache, configuration, mods, saves, and screenshots.

Without the launcher, startup searches the current directory, its parent, the executable directory, and the executable's parent for these recognized filenames:

```text
Duke Nukem 64 (USA).z64
dukenukem.z64
Duke Nukem 64 (U) [!].z64
```

The original ROM must be legally obtained; it is not distributed by this project. ROM cache copy failures are reported and still pass through normal ROM validation.

## Input

### Keyboard and mouse

The default PC mapping is:

| Action | Default input |
| --- | --- |
| Move | `W` / `S` |
| Run | Hold `Shift`; `Caps Lock` toggles run mode |
| Strafe | `A` / `D` |
| Turn and aim | Relative mouse movement |
| Fire | Left mouse button, `Left Ctrl`, or `Z` |
| Jump | `Space` |
| Crouch | `C` |
| Open/use | `E` |
| Previous/next weapon | `Q` / `R` |
| Inventory | `Tab` |
| Inventory cycle | `[` / `]` |
| Start/menu | `Enter` |
| Menu navigation | Arrow keys |
| Menu select | `Enter` |
| Previous menu | `Escape` |

Press any keyboard key or controller button during the logo or intro screens to jump directly to the main menu.

Hold either Shift key to run. Press `Caps Lock` to toggle the same run modifier without holding Shift; press it again to return to walking. This changes movement speed only and does not affect menu navigation.

The N64 controlmap defaults were updated so inventory and strafe actions match these PC controls.

### Xbox-compatible controllers

The first three SDL game controllers are assigned to local multiplayer ports 2–4:

- Left stick: move and strafe.
- Gyro aiming is available for compatible controllers when `gyro_sensitivity` is greater than zero.
- Right stick: turn and aim.
- A: jump; B: crouch; X or right trigger: fire; Y: next weapon.
- D-pad: directional aim/strafe input.
- Left shoulder: inventory; right shoulder: open/use; Start: start/menu.

Local multiplayer uses the keyboard/mouse as player 1 and up to three SDL game controllers as players 2–4. The same controller layout supports the built-in split-screen Dukematch and cooperative modes after selecting local multiplayer in the game menus.

Controllers may be connected or disconnected while the game is running. The first keyboard/mouse player exposes the virtual Controller Pak used by the save backend, attached SDL controllers expose Controller Paks for their ports, and detached ports expose none.

Controller and mouse behavior is configured in `duke64.json`:

```json
{
    "mouse_sensitivity": 1.0,
    "window_width": 1280,
    "window_height": 720,
    "controller_deadzone": 0.24,
    "gyro_sensitivity": 0.0,
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

`window_width` and `window_height` are clamped to `640–7680` and `360–4320`. `mouse_sensitivity`, `controller_sensitivity`, and `gyro_sensitivity` accept `0.0–4.0`; a gyro sensitivity of `0.0` disables motion aiming. `controller_deadzone` accepts `0.0–0.9`. Keyboard values use SDL scancode names. Invalid or missing keyboard entries fall back to defaults.

Press `Alt+Enter` to toggle borderless fullscreen. Relative mouse capture is released while the window is unfocused and restored when focus returns.

Press `F3` to toggle a brief rendering diagnostics overlay showing measured presented FPS, display refresh rate, active graphics API, backbuffer size, resolution scale, and presentation mode.

## Screenshots

Press `F12` during gameplay to write a 32-bit BMP screenshot to the active user-data directory's `screenshots` folder. Files use the name pattern `duke64-N.bmp` and are numbered without overwriting existing captures.

## Audio and runtime fixes

The recompiled audio path includes the ASP indirect-branch target table, FIFO command-list handoff, exact byte copies for unaligned audio command data, synchronous audio-task execution, and scheduler completion ordering. These fixes keep generated RSP audio execution aligned with the original command stream, prevent stale or partially copied commands, and ensure audio completion is posted after the scheduler records its current task.

The host path converts byte-swapped N64 stereo samples into host-native samples, returns libultra's actual DAC-derived rate, and resamples that source rate through SDL's `AUDIO_S16SYS` `SDL_AudioStream` to a fixed 48 kHz stereo device with a 1024-sample buffer. Queue depth is converted back to source-rate frames for `osAiGetLength`, and rate changes drain the old stream before switching. See [AUDIO_PATCHES.md](AUDIO_PATCHES.md) for the complete patch record, affected files, regeneration notes, and verification evidence.

The AI bridge applies the N64 audio DMA length granularity (eight-byte units) before copying samples, matching the hardware contract used by the reference emulation path.

On Windows, the runtime requests a 1 ms timer resolution before starting the VI thread. This prevents the default coarse `Sleep` quantum from delaying the absolute 60 Hz VI deadlines that drive audio and rendering. The emulated NTSC cadence remains 60 Hz by design; the renderer is not given an additional host-side frame cap beyond RT64's display/present pacing.

## Save safety

Controller Pak writes are serialized and roll back the in-memory state when the backing file cannot be written. Failed writes return the appropriate controller-pak error instead of reporting success.

The Controller Pak save writer uses a temporary file and preserves the previous save as a `.bak` fallback when replacement fails. In-memory Pak state is rolled back after failed writes. Directory checks reject invalid occupied entries instead of silently reporting success.

Disconnected controller ports are returned with cleared button and stick values plus a no-response status, preventing stale input from carrying into another local player.

ROM cache copy failures are reported to stderr and continue through normal ROM validation rather than terminating through an uncaught filesystem exception.

## Release automation

The first alpha release is defined by `.github/workflows/alpha-release.yml`. The workflow runs for the `v0.1.0-alpha.1` tag or through manual GitHub Actions dispatch. It configures a Windows Ninja Release build, builds both executables, copies the runtime DLLs and project documentation, uses `CHANGELOG.md` as the GitHub release body, creates the Windows x64 archive, and publishes a prerelease. ROM files are intentionally excluded.

## Troubleshooting

### The launcher cannot find the game

`Duke64Launcher.exe` expects `Duke64Recompiled.exe` beside it. Extract the full archive instead of copying only the launcher.

### Windows reports a missing DLL

Keep `SDL2.dll`, `dxil.dll`, and `dxcompiler.dll` beside `Duke64Recompiled.exe`. These files are produced by the build and included in the alpha archive.

### The selected ROM is rejected

The `.z64` extension is only a file-picker filter. The runtime validates the supported Duke Nukem 64 ROM hash. Select a legally obtained, unmodified compatible dump.

### Settings or saves are in an unexpected location

Check for `portable.txt` beside the executable. If present, configuration, saves, mods, screenshots, and the cached ROM are beside the executable; otherwise they are under `%LOCALAPPDATA%\Duke64Recompiled`.

### Gyro aiming does not work

Set `gyro_sensitivity` above `0.0` in `duke64.json` and use a controller exposing motion sensors through SDL. Gyro input is optional, contributes to right-stick aim during gameplay, and does not replace the right stick.


## Credits and license

See [CREDITS.md](CREDITS.md) for the original Duke Nukem 64 credits, upstream projects, bundled dependencies, and attribution boundaries. Original Duke64-RE-owned integration code and documentation are released under the [WTFPL](LICENSE); upstream, generated game, extracted data, ROM, and third-party components retain their own licenses and ownership.
