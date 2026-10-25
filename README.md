# Duke Nukem 64 Reprobed

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
| `duke64.json` | Window, frame-rate, mouse, controller, gyro, and keyboard settings. |
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
| Turn and aim | Relative mouse turn and mouselook |
| Fire | Left mouse button or `Z` |
| Jump | `Space` |
| Crouch | `Ctrl` |
| Mighty Foot | `V` or right mouse button |
| Open/use | `E` |
| Previous/next weapon | `Q` / `R` |
| Weapon slots | `1`–`9` (top row or keypad) |
| Inventory | `Tab` |
| Inventory cycle | `[` / `]` |
| Start/menu | `Enter` |
| Menu navigation | Arrow keys |
| Menu select | `Enter` |
| Previous menu / exit from main menu | `Escape` |

Keyboard actions can be remapped in `Options -> Control Options`. Select an
action, press the replacement key, or press `Escape` to cancel. Mouse
sensitivity and horizontal/vertical aim inversion are also adjustable on the
same page. Changes are written to `duke64.json` immediately. The left and
right mouse buttons remain the default fire and Mighty Foot inputs.

`Enter` opens the in-game menu during gameplay and selects the highlighted
item in menus. The configured `start` key follows the same behavior. `Escape`
backs out of nested menus and exits from the main menu. Mouse clicks do not
navigate or select menu items; left and right mouse buttons remain gameplay
inputs, and a click skips startup screens. Quick keyboard taps are latched
across the SDL event and game-input threads.

Number keys select the weapon slots in the standard Duke order: `1` pistol, `2`
shotgun, `3` chaingun, `4` RPG, `5` pipebomb, `6` shrinker, `7` devastator,
`8` tripbomb, and `9` freezer. Press the same number again within about 400 ms
to select that slot's alternate weapon where one exists: dual pistols, the
alternate shotgun, alternate RPG, remote detonator, or expander. Single presses
continue to select the primary weapon and normal ownership/ammo checks still
apply.

The PC build skips the startup Controller Pak check; saves and loads use the persistent virtual Pak. Press any keyboard key or controller button during the remaining logo or intro screens to jump directly to the main menu.

Hold either Shift key to run. Press `Caps Lock` to toggle the same run modifier without holding Shift; press it again to return to walking. This changes movement speed only and does not affect menu navigation.

The default recompiled controlmap aligns the N64 action bits with the PC
keyboard/mouse layout and the controller layout below.

### Xbox-compatible controllers

The first three SDL game controllers are assigned to local multiplayer ports 2–4:

- Left stick: move; horizontal movement strafes.
- Hold left-stick click (L3) to run.
- Right stick: turn and aim.
- Click right stick (R3): Mighty Foot.
- A: jump; B: crouch; X or right trigger: fire; Y: next weapon; Back: previous weapon.
- D-pad up/down: aim; D-pad left/right: cycle inventory.
- Left shoulder: inventory; right shoulder: open/use; Start: start/menu.
- In menus, A selects, B backs out, and directional input navigates.

Local multiplayer uses the keyboard/mouse as player 1 and up to three SDL game controllers as players 2–4. The same controller layout supports the built-in split-screen Dukematch and cooperative modes after selecting local multiplayer in the game menus.

Controllers may be connected or disconnected while the game is running. The first keyboard/mouse player exposes the virtual Controller Pak used by the save backend, attached SDL controllers expose Controller Paks for their ports, and detached ports expose none.

Controller and mouse behavior is configured in `duke64.json`:

```json
{
    "mouse_sensitivity": 1.0,
    "window_width": 1280,
    "window_height": 720,
    "frame_rate": "60",
    "aspect_ratio": "original",
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
        "crouch": "Left Ctrl",
        "mighty_foot": "V",
        "start": "Return",
        "open": "E",
        "previous_weapon": "Q",
        "next_weapon": "R",
        "inventory_previous": "Left Bracket",
        "inventory_next": "Right Bracket"
    }
}
```

`window_width` and `window_height` are clamped to `640–7680` and `360–4320`.
`mouse_sensitivity` accepts `0.1–4.0`; `controller_sensitivity` accepts
`0.1–4.0`; `gyro_sensitivity` accepts `0.0–4.0`; a gyro sensitivity of
`0.0` disables motion aiming. `controller_deadzone` accepts `0.0–0.9`.
Keyboard values use SDL scancode names. Invalid or missing keyboard entries
fall back to defaults.
`frame_rate` accepts `"30"`, `"60"`, `"90"`, `"120"`, `"144"`, `"165"`, `"240"`, `"360"`, or `"unlocked"`; it defaults to `"60"`. Fixed values request RT64 pacing/interpolation at that rate when supported. `"unlocked"` disables v-sync and the software pacing sleep, so tearing is possible and the achievable rate is limited by renderer throughput. Restart after editing this setting.
`aspect_ratio` accepts `"original"` (the default 4:3 frame with pillarboxing) or `"expand"` (adapts the game viewport to the window's aspect ratio, including 16:9 and ultrawide displays). The same setting is available in Display Options as `ASPECT ORIGINAL`/`ASPECT EXPAND`; changes apply immediately and are saved to `duke64.json`.
Display Options also exposes `RESOLUTION`; left/right cycles common window sizes and saves the selected `window_width`/`window_height` immediately.

Press `Alt+Enter` to toggle borderless fullscreen. Relative mouse capture is released while the window is unfocused and restored when focus returns.

Press `F3` to toggle a brief rendering diagnostics overlay showing measured presented FPS, configured frame-rate target, display refresh rate, active graphics API, backbuffer size, resolution scale, and presentation mode.

## Screenshots

Press `F12` during gameplay to write a 32-bit BMP screenshot to the active user-data directory's `screenshots` folder. Files use the name pattern `duke64-N.bmp` and are numbered without overwriting existing captures.

## Audio and runtime fixes

The recompiled audio path includes the ASP indirect-branch target table, FIFO command-list handoff, exact byte copies for unaligned audio command data, synchronous audio-task execution, and scheduler completion ordering. These fixes keep generated RSP audio execution aligned with the original command stream, prevent stale or partially copied commands, and ensure audio completion is posted after the scheduler records its current task.

The host path converts byte-swapped N64 stereo samples into host-native samples, returns libultra's actual DAC-derived rate, and resamples that source rate through SDL's `AUDIO_S16SYS` `SDL_AudioStream` to a fixed 48 kHz stereo device with a 1024-sample buffer. Queue depth is converted back to source-rate frames for `osAiGetLength`, and rate changes drain the old stream before switching. See [AUDIO_PATCHES.md](AUDIO_PATCHES.md) for the complete patch record, affected files, regeneration notes, and verification evidence.
The host scheduler gives the audio client a higher virtual priority and drains client-produced tasks again within the same retrace. Generated audio completion is handled inline after the current task is recorded, preventing the one-VI-late cadence that caused slow or jittery music.

The AI bridge applies the N64 audio DMA length granularity (eight-byte units) before copying samples, matching the hardware contract used by the reference emulation path.

On Windows, the runtime requests a 1 ms timer resolution before starting the VI thread. This prevents the default coarse `Sleep` quantum from delaying the absolute 60 Hz VI deadlines that drive audio and rendering. The emulated NTSC cadence remains 60 Hz by design; the renderer is not given an additional host-side frame cap beyond RT64's display/present pacing.

## Mirrors

Vanilla mirror walls now emit an RT64 mirror draw marker around their overpic geometry. The RT64 raster renderer snapshots the current color target before the first mirror draw and the mirror pixel shader samples that snapshot with a horizontal screen-space reflection. This avoids sampling a color attachment while it is being written and works with both single-sample copies and multisample resolves.

This is a shader-compatible fallback, not a full reflected-room render pass. Reflections therefore do not reproduce plane-specific perspective, recursive mirrors, or a separately rendered actor scene; mirror walls remain usable and display the content rendered before the mirror in the current frame instead of the MIRROR tile.

## Mods and asset packs

The runtime uses the existing N64ModernRuntime mod scanner and stores user mods in the
active data directory's `mods` folder. This is `%LOCALAPPDATA%\Duke64Recompiled\mods`
unless portable mode is enabled. Loose mod directories and `.nrm` packages are always
supported. Source-port-style `.zip`, `.pk3`, and `.pk4` packages are also discovered;
`.rtz` is accepted for a standalone RT64 texture pack. A package may contain `mod.json`,
but the source-port-style containers can omit it and receive a default manifest based on
the filename.

The layout is intentionally close to the EDuke32/Raze workflow while remaining a native
Duke64 format:

```text
my-pack/
  mod.json
  duke64.assets.json
  assets/
    textures/
      rt64.json
      textures/*.dds
    voxels.json
    voxels/
      123.vox
    sounds.json
    sounds/
      pistol.wav
    music.json
    music/
      e1m1.wav
```

`mod.json` uses the runtime manifest schema:

```json
{
    "game_id": "dukenukem",
    "id": "my-pack",
    "display_name": "My Duke64 Pack",
    "version": "1.0.0",
    "authors": ["Author"],
    "minimum_recomp_version": "0.1.0",
    "enabled_by_default": true
}
```

`duke64.assets.json` selects the optional asset indexes. Every path is package-relative;
absolute paths and `..` traversal are rejected.

```json
{
    "version": 1,
    "textures": "assets/textures",
    "voxels": "assets/voxels.json",
    "sounds": "assets/sounds.json",
    "music": "assets/music.json"
}
```

### Texture packs

Textures use RT64's existing replacement database. `textures` points at a directory
containing `rt64.json`, or directly at that file. DDS and PNG files referenced by the
database are loaded from the same directory. A standalone `.rtz` package contains
`rt64.json` at its root.

### Voxel indexes

Voxel entries use numeric Duke tile IDs and MagicaVoxel `.vox` files:

```json
{
    "version": 1,
    "entries": [
        {
            "tile": 123,
            "model": "assets/voxels/123.vox",
            "texture": "assets/textures/123.dds"
        }
    ]
}
```

The loader validates the VOX container and records the tile mapping before gameplay
starts. RT64 currently exposes texture replacement, not a model replacement API. The
optional `texture` path is validated as a companion asset and must also be referenced
by an RT64 database; it is not an automatic tile remap. No voxel model is silently
treated as a texture.

### Sound effects and music

Both audio indexes use numeric IDs and PCM/IEEE-float WAV files:

```json
{
    "version": 1,
    "entries": [
        { "id": 42, "file": "assets/sounds/pistol.wav", "volume": 1.0 }
    ]
}
```

`sounds.json` IDs replace the corresponding `spritesound` call. `music.json` IDs replace
tracks started by the game's song-start path and loop through the host SDL audio queue.
`stopsong` stops the external track. WAV input is converted to stereo `S16` and resampled
to the device rate by SDL; unsupported or malformed audio is skipped with a diagnostic.

### Ordering and toggling

Vanilla assets are the base layer. Enabled mods are applied in the order shown by
`mods.json`; a later mod wins when it defines the same RT64 texture hash, sound ID, or
music ID. Asset packs are loaded before the game entry point and are not runtime
toggleable, avoiding renderer/audio state races. Reordering mods before the next launch
changes the override precedence.

The package conventions borrow only resource-loading ideas from EDuke32 and Raze; no
GPL source code is linked into Duke64-RE. The upstream projects and their licenses remain
separate from this repository's generated game code and user-created assets.

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
