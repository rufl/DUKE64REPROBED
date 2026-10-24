# Changelog

All notable changes to the Duke Nukem 64 recompilation are documented here.

## [0.1.0-alpha.1]

### Added

- Added a Windows user-data directory at `%LOCALAPPDATA%\Duke64Recompiled` for runtime configuration, cached ROM data, mods, and saves.
- Added portable mode through an empty `portable.txt` file beside the executable.
- Added automatic discovery and caching of common Duke Nukem 64 ROM filenames as `dukenukem.z64` in the active user-data directory.
- Added persistent controller tuning in `duke64.json`:
  - `controller_deadzone`
  - `controller_sensitivity`
  - `invert_aim_x`
  - `invert_aim_y`
- Added SDL controller analog deadzone normalization and sensitivity scaling.
- Added optional controller gyro aiming through Gamepad Motion Helpers; configure `gyro_sensitivity` in `duke64.json`.
- Added `Duke64Launcher.exe`, a native Windows ROM picker that starts the game with a selected `.z64` file.
- Added F12 BMP screenshots written to the active user-data directory's `screenshots` folder.
- Added a multi-resolution Duke64-styled Windows executable icon.
- Added persistent mouse sensitivity configuration through `duke64.json`.
- Added `Alt+Enter` borderless fullscreen toggling and focus-aware relative mouse capture.
- Added persistent window width and height settings.
- Added configurable keyboard bindings using SDL scancode names.
- Added a persistent Controller Pak backend using `duke64.mempak`.
- Added an F3 rendering diagnostics overlay with measured presented FPS, display refresh rate, active graphics API, backbuffer size, resolution scale, and presentation mode.

### Changed

- Registered the selected user-data directory with N64ModernRuntime so save and configuration services share one location.
- Reworked default keyboard and mouse controls for PC play:
  - WASD movement and strafing.
  - Mouse turn/aim.
  - Left mouse, Left Ctrl, and Z fire.
  - Space jump, C crouch, E open/use, Q/R weapon selection, Tab inventory, and bracket inventory cycling.
- Updated the recompiled controlmap defaults for PC inventory and strafe controls.
- Corrected PC movement so Shift runs while W/S are held; Caps Lock toggles the same run modifier without forcing forward movement.
- Added Xbox-compatible controller mappings for movement, aiming, jump, crouch, fire, weapon selection, inventory, and open/use.
- Added safe controller hot-plug handling and accurate connected-device reporting.
- Added local multiplayer input support: keyboard/mouse player 1 plus up to three SDL controllers on ports 2–4.
- Confirmed the same local controller layout supports the game's built-in cooperative mode.
- Added the missing ASP indirect branch targets used by the Duke Nukem 64 audio microcode.
- Changed audio command-list handling to preserve FIFO order and pass the exact command-list address and size to ASP.
- Moved Controller Pak persistence from the working directory to the registered runtime configuration path.
- Changed audio RSP tasks to run synchronously and enabled VI message requeue so host completion keeps pace with the scheduler.
- Changed host audio accounting to resample the game's exact AI rate into a fixed 48 kHz stereo device queue and report queue depth in source-rate frames.

### Fixed

- Controller input reads now clear button and stick fields for disconnected ports instead of exposing stale data.
- Controller Pak detection now exposes the virtual save Pak on the keyboard/mouse player, so single-player save menus no longer report that no Pak is present.
- Controller Pak replacement failures preserve the previous save and validate directory entries through `osPfsChecker`.
- Audio command processing now lets ASP fetch command lists in bounded DMEM chunks instead of preloading oversized lists.
- Fixed audio completion ordering by posting the SP completion after the scheduler records its current RSP task, avoiding completion stalls until the next VI.
- Fixed the AI frequency bridge to return libultra's actual DAC-derived rate instead of the nominal request.
- Fixed byte-swapped RDRAM audio buffers being passed directly to the host, which reversed interleaved stereo pairs.
- Fixed Debug audio-task underruns by compiling the synchronous generated audio path and ASP at `-O2`.
- AI audio buffers now honor the hardware eight-byte DMA length granularity before host conversion.
- Windows VI scheduling now requests 1 ms timer resolution, removing coarse sleep quantization without changing the emulated 60 Hz cadence.
- ROM cache copy failures now report diagnostics instead of escaping as uncaught filesystem exceptions.
- Screenshot numbering avoids overwriting existing captures.

### Documentation

- Added `Duke64-RE/CREDITS.md` with original game, upstream, and dependency attribution boundaries.
- Added `Duke64-RE/LICENSE` with the WTFPL for project-owned integration code and documentation.
- Added the repository landing page with alpha download, launcher, ROM, configuration, build, release, troubleshooting, and attribution documentation.
- Expanded `Duke64-RE/README.md` with source-build, release-workflow, launcher, runtime, and troubleshooting guidance.
