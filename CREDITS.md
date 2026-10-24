# Credits

Duke64-RE is a recompiled PC build of *Duke Nukem 64*. This file distinguishes the original game credits, upstream projects, and the project-owned integration work.

## Original game

The extracted game credit data in `data/asm/game1.rodata.s` identifies the following contributors and organizations:

- **Eurocom Entertainment Software / Eurocom Developments Ltd.** — development.
- **3D Realms Entertainment / 3D Realms Team** — original Duke Nukem work and production.
- **GT Interactive Software Corp.** — publisher credit in the game.
- **Rick Raymo** — producer.
- **Ashley Finney** and **Simon Mills** — programming.
- **Bill Beacham** and **Kev Harvey** — level design.
- **Steve Bamford**, **Andy Bee**, **Rob Benton**, **Nick Dry**, **Paul Gregory**, **Darren Hyland**, and **Adrian Mannion** — graphics.
- **Neil Baldwin** and **Steve Duckworth** — audio.
- **Hugh Binns**, **Bill Beacham**, **Mike Botham**, **Andy Collins**, and **Aaron Jenkins** — project management and quality approval.
- **Rob Letts** — GT Europe producer.
- **Cara McMullan** — European localisation.
- **Nic Lavroff** — manual.
- **Jon St. John** — voice talent, including Duke Nukem.
- **Paul Bates**, **Tim Rogers**, **Mat Sneap**, **Ken Silverman**, **Todd Replogle**, **Scott Miller**, **George Broussard**, **Tony Kee**, **Dan Harnett**, **Max Taylor**, **Stew Kosoy**, and **Graeme Boxall** — special thanks.
- **Allen H. Blum III** — original concept and map design.
- **Greg Malone** — producer.
- **Mark Dochtermann** — network layer.
- **Richard Gray** — map design.
- **Chuck Jones**, **Dirk Jones**, **Stephen Hornback**, **James Storey**, and **David Demaret** — 3D modelling and artwork.
- **Sapphire** — 3D modelling credit.
- **Douglas R. Wood** — sound engine.
- **Jim Dose** — sound and music.
- **Robert Prince** and **Lee Jackson** — sound and music.
- **Lani Minella** — voice production and voice talent.

The game, its code, artwork, music, voices, trademarks, and ROM remain the property of their respective rights holders. This project does not distribute the original ROM.

## Recompilation and runtime projects

- [N64Recomp](https://github.com/N64Recomp/N64Recomp) — static N64 binary recompiler; **Wiseguy** is identified as the copyright holder in its MIT license.
- N64Recomp's bundled [Rabbitizer](https://github.com/Decompollaborate/rabbitizer) — **Decompollaborate**, MIT.
- N64Recomp's bundled [ELFIO](https://github.com/serge1/ELFIO) — **Serge Lamikhov-Center**, MIT.
- N64Recomp's bundled [fmt](https://github.com/fmtlib/fmt) — **Victor Zverovich and `{fmt}` contributors**, MIT.
- N64Recomp's bundled [tomlplusplus](https://github.com/marzer/tomlplusplus) — **Mark Gillard**, MIT.
- N64Recomp's bundled [SLJIT](https://github.com/zherczeg/sljit) — **Zoltan Herczeg**, BSD-style license.
- [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) — `ultramodern` and `librecomp` runtime libraries and the runtime integration model; distributed in this checkout with its GPLv3 license.
- [RT64](https://github.com/rt64/rt64) — N64 renderer; copyright credit is **RT64 Contributors** under its MIT license. RT64 also credits **Wiseguy**'s homebrew test ROMs and **Tharo**'s RDP research in its documentation.
- [ares](https://github.com/ares-emulator/ares) — reference for the N64 RSP reciprocal/inverse-square-root constants and AI hardware behavior; the ares runtime is not linked into Duke64-RE.
- [SDL](https://github.com/libsdl-org/SDL) — host windowing, input, and audio; **Sam Lantinga** and SDL contributors under the zlib license.
- [Gamepad Motion Helpers](https://github.com/JibbSmart/GamepadMotionHelpers) — Julian “Jibb” Smart, MIT; optional controller gyro aiming.
- [Duke Nukem Zero Hour: Recompiled](https://github.com/sonicdcer/DNZHRecomp) — reference for controller motion integration and quality-of-life patterns.
- Mupen64Plus Core material bundled under RT64's `src/contrib/mupen64plus-core` retains its GPLv2 and component attributions. Its author list includes Richard Goedeken, Sven Eckelmann, John Chadwick, James Hood, Scott Gorman, Scott Knauert, Jesse Dean, Louai Al-Khanji, Bob Forder, Jason Espinosa, Bobby Smiles, Dorian Fevrier, Richard Hender, Will Nayes, Conchur Navid, Gillou68310, HyperHacker, littleguy77, and Nebuleon, among others.

N64Recomp's bundled dependencies, RT64's bundled dependencies, SDL, and all other third-party components retain the license and attribution files shipped in their component directories. Those files are authoritative and are not relicensed by Duke64-RE.

## Duke64-RE integration

The Duke64-RE contributors maintain the PC frontend, RT64 integration, SDL input/audio integration, Controller Pak persistence bridge, generated-runtime hooks, build configuration, documentation, and fixes in this project. The checkout does not contain version-control author metadata, so individual local contributor names are not invented here; additions should be credited by name or handle when supplied by their authors.

## License scope

Original Duke64-RE-owned integration code and documentation, to the extent they are not generated from the game or derived from an upstream component, are released under the [WTFPL](LICENSE).

The WTFPL does **not** replace the licenses or ownership of the original game, generated recompiled game code, extracted game data, `src/libultra`, N64Recomp, N64ModernRuntime, RT64, SDL, or any vendored dependency. See each component's own license files before redistributing a combined build.
