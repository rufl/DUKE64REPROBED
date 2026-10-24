# Duke64-RE Audio and Runtime Patch Record

This document records the audio-related fixes and the runtime/compiler changes that make them work. It is intentionally more detailed than the changelog: it names the source-of-truth configuration, generated artifacts, handoff contracts, scheduler ordering, and verification evidence.

## Scope and symptom

The patch set addresses audio command processing that could become stale or incomplete, audio-task completion that could be delayed until a later VI event, host audio queue underruns, and sample-format/rate mismatches at the SDL boundary. The affected path crosses four layers:

1. N64Recomp's generated 32-bit MIPS arithmetic and load expressions.
2. The generated Duke audio handler and ASP microcode.
3. librecomp/ultramodern RSP-task and scheduler integration.
4. The SDL host audio queue and `osAiGetLength` accounting.

The important invariant is that each audio task executes the command list produced for that task, ASP reads that list using its normal bounded DMA behavior, and the scheduler observes completion after its current-task state has been recorded.

## Patch inventory

| Area | Files | Patch |
| --- | --- | --- |
| MIPS integer representation | `N64ModernRuntime/N64Recomp/include/recomp.h`, `N64ModernRuntime/N64Recomp/src/cgenerator.cpp` | Keep 32-bit signed arithmetic and signed loads sign-extended in the host 64-bit GPR representation. |
| Generated function boundaries | `Duke64-RE/duke_recomp.toml`, generated `Duke64-RE/RecompiledFuncs/recomp_overlays.inl` | Preserve complete function bodies for the scheduler/audio-related manual functions. |
| ASP control flow | `Duke64-RE/asp.us.toml`, generated `Duke64-RE/rsp/aspMain.cpp` | Register the indirect branch targets used by the audio microcode. |
| Audio command-list handoff | generated `Duke64-RE/RecompiledFuncs/funcs_3.c`, `N64ModernRuntime/librecomp/src/rsp.cpp` | Pair the generated list address and byte size, queue pairs FIFO, and consume one pair per audio task. |
| RSP memory behavior | `N64ModernRuntime/librecomp/include/librecomp/rsp.hpp`, `N64ModernRuntime/librecomp/src/rsp.cpp` | Copy DMEM data byte-by-byte and provide ASP with the list address/size instead of preloading an oversized list. |
| Scheduler completion | `N64ModernRuntime/ultramodern/src/events.cpp`, generated `Duke64-RE/RecompiledFuncs/funcs_14.c` | Execute audio tasks synchronously and enqueue completion only after the scheduler records its current RSP task. |
| Host queue accounting | `N64ModernRuntime/librecomp/src/ai.cpp`, `N64ModernRuntime/ultramodern/src/audio.cpp`, `Duke64-RE/src/main.cpp` | Convert N64 sample words to host-native stereo samples, resample the game's exact AI rate to a fixed 48 kHz SDL device, and report queued output in source-rate units with lead-time subtraction. |
| Generated-source cleanup | `Duke64-RE/RecompiledFuncs/funcs_3.c`, `Duke64-RE/RecompiledFuncs/funcs_14.c` | Retain only the permanent bridge calls; remove temporary timing and scheduler diagnostics. |

## 1. Correct 32-bit MIPS values in generated C

### Signed arithmetic

`N64ModernRuntime/N64Recomp/include/recomp.h` now defines the 32-bit arithmetic helpers as signed 32-bit results widened to the host GPR type:

```c
#define ADD32(a, b) \
    ((gpr)(int64_t)(int32_t)((a) + (b)))

#define SUB32(a, b) \
    ((gpr)(int64_t)(int32_t)((a) - (b)))
```

This matters because generated contexts use a host 64-bit `gpr`, while MIPS integer arithmetic wraps at 32 bits. The explicit cast sequence preserves the wrapped 32-bit value and its sign when later code uses `SIGNED(...)`, signed comparisons, addresses, lengths, or branch conditions.

### Signed loads

`N64ModernRuntime/N64Recomp/src/cgenerator.cpp` now emits `S32(...)` around signed `LW`, `LH`, and `LB` operations. Unsigned `LWU`, `LHU`, and `LBU` continue to use their unsigned memory helpers without sign extension.

The generated output consequently contains expressions such as:

```c
ctx->r4 = S32(MEM_W(ctx->r4, offset));
ctx->r7 = S32(MEM_H(ctx->r3, offset));
ctx->r14 = S32(MEM_B(ctx->r14, offset));
```

This is a generator fix, not an audio-only special case. The audio scheduler and generated audio handler depend on the same 32-bit value semantics as the rest of the recompiled program.

## 2. Preserve complete generated function bodies

`Duke64-RE/duke_recomp.toml` declares these manual function boundaries:

| Function | Section | VRAM | Size |
| --- | --- | ---: | ---: |
| `func_8004C65C` | `.main` | `0x8004C65C` | `0x124` |
| `func_800C0EDC` | `.main` | `0x800C0EDC` | `0x614` |
| `func_800BFABC` | `.main` | `0x800BFABC` | `0x548` |

The explicit sizes prevent function discovery from cutting through the scheduler/event loop or the audio handler. The generated overlay table in `Duke64-RE/RecompiledFuncs/recomp_overlays.inl` carries the corresponding ROM sizes.

`func_8004C65C` is the scheduler-side function whose generated body now contains the audio completion bridge. `func_800BFABC` is the audio handler boundary. `func_800C0EDC` remains part of the same explicit manual-boundary set and must be kept intact when regenerating the function table.

## 3. Generate the complete ASP control-flow surface

`Duke64-RE/asp.us.toml` generates `Duke64-RE/rsp/aspMain.cpp` from the Duke ASP text at `0x04001080`. The configuration adds these 17 indirect branch targets:

```text
0x11DC, 0x1214, 0x1254, 0x1294, 0x12D0, 0x12EC, 0x1328,
0x138C, 0x140C, 0x144C, 0x1470, 0x170C, 0x1800, 0x187C,
0x1B38, 0x1C00, 0x1E24
```

Without these targets, generated ASP dispatch can miss valid audio microcode paths. The target list is part of the source configuration; `rsp/aspMain.cpp` is the generated artifact.

## 4. Preserve the generated audio command list

The generated `__amHandleFrameMsg` path in `Duke64-RE/RecompiledFuncs/funcs_3.c` captures the command-list address and the address of the command-count value before calling `alAudioFrame`:

```c
gpr audio_cmd_len = ctx->r5;
gpr audio_cmd_list = ctx->r4;
...
alAudioFrame(rdram, ctx);
recomp_set_audio_command_list(
    (uint32_t)audio_cmd_list,
    MEM_W(audio_cmd_len, 0) * 8
);
```

The size passed to the runtime is the generated command count multiplied by the 8-byte audio-command width. The runtime stores the pair in a mutex-protected FIFO in `N64ModernRuntime/librecomp/src/rsp.cpp`:

```cpp
struct AudioCommandList {
    uint32_t address;
    uint32_t size;
};
```

One queued pair is consumed for each `M_AUDTASK`. FIFO pairing prevents one frame's address from being combined with another frame's size.

## 5. Let ASP fetch command lists through bounded DMA

`recomp::rsp::run_task` starts with the task's normal command-list address and size, then replaces them with the oldest generated handoff pair when the task is an audio task. It writes the selected address and byte size to the ASP task parameters at DMEM offsets `0xFF0` and `0xFF4`:

```cpp
RSP_MEM_W_STORE(0xFF0, 0, command_list);
RSP_MEM_W_STORE(0xFF4, 0, command_size);
```

The old full-list preload behavior is intentionally not used. ASP fetches the list in the bounded chunks described by its microcode. A zero-sized list is treated as a completed task. If no RSP microcode is registered for an audio task, the runtime also treats that audio task as completed so an integration that intentionally disables audio does not abort the scheduler.

`N64ModernRuntime/librecomp/include/librecomp/rsp.hpp` keeps RSP memory and DMA transfers byte-oriented:

- `RSP_MEM_W_LOAD` and `RSP_MEM_W_STORE` assemble/store individual bytes in RSP byte order.
- `dma_rdram_to_dmem` and `dma_dmem_to_rdram` copy each byte explicitly.
- DMA length remains inclusive, and the DRAM address is aligned according to the RSP DMA rules.

The byte-wise path avoids host alignment assumptions and preserves unaligned or partial command data exactly.

## 6. Complete audio tasks in scheduler order

### Root cause

The host RSP completion path originally enqueued an external SP message. External messages were applied when game code entered the message-queue wrappers, but the scheduler itself could be blocked waiting for an interrupt-queue message. An audio task could therefore finish on the host while the scheduler did not consume completion until a later VI. The audio manager waited on its completion queue, client queues accumulated, and the SDL device could underrun.

### Runtime dispatch

`N64ModernRuntime/ultramodern/src/events.cpp` now dispatches task types as follows:

- `M_GFXTASK`: enqueue the task on the graphics action queue.
- `M_AUDTASK`: call `ultramodern::rsp::run_task` synchronously.
- Other task types: retain the existing asynchronous SP task queue.

Synchronous execution makes the audio handler finish before the scheduler posts the corresponding completion event.

### Completion bridge

The generated scheduler function in `Duke64-RE/RecompiledFuncs/funcs_14.c` checks the OS task type at offset `0x10` (`2` is `M_AUDTASK`) after writing the current task to the scheduler state at offset `0x274`. It then calls:

```c
ultramodern_complete_sp_task(rdram);
```

The call is present in both scheduler branches: the branch that changes the current task and the branch that updates both current and next task state.

`N64ModernRuntime/ultramodern/src/events.cpp` implements the bridge by queueing the existing external SP message under `message_mutex`:

```cpp
extern "C" void ultramodern_complete_sp_task(uint8_t* rdram) {
    complete_sp_task_sync(rdram);
}
```

The helper deliberately does not call `osSendMesg` directly. It uses the external-event queue, but only after the generated scheduler has recorded the current task. This ordering avoids consuming the message against stale scheduler state and avoids the scheduler deadlock caused by trying to send directly into the scheduler's queue from the synchronous path. The ordinary `sp_complete()` path remains for asynchronous non-audio work.

## 7. Account for the SDL host queue

### AI bindings

`N64ModernRuntime/librecomp/src/ai.cpp` now exposes the host queue state through the standard AI entry points:

- `osAiSetFrequency_recomp` emulates libultra's integer DAC divisor and updates the runtime and host with the resulting actual sample rate.
- `osAiSetNextBuffer_recomp` forwards the RDRAM buffer and byte count to `queue_audio_buffer`.
- `osAiGetLength_recomp` returns `ultramodern::get_remaining_audio_bytes()`.

### Runtime accounting

`N64ModernRuntime/ultramodern/src/audio.cpp`:

- Requires an even byte count because samples are 16-bit.
- Reads each sample through the N64 halfword address mapping (`address ^ 2`) into a reusable host-native buffer; passing the raw RDRAM pointer would reverse each interleaved stereo pair.
- Forwards the converted samples to the registered host callback.
- Uses `audio_callbacks.get_frames_remaining()` as the queue source. The callback reports frames at the current game sample rate even when the host device runs at another rate.
- Converts stereo frames back to bytes using `frames * 2 * sizeof(int16_t)`.
- Subtracts `0.5 * sizeof(int16_t) * (sample_rate / 60)` bytes, clamped at zero, so the game requests the next buffer before the device queue reaches empty.

The offset is deliberately small. Reporting too much remaining audio delays production; reporting too little can add lag or increase queue pressure.

### SDL integration

`Duke64-RE/src/main.cpp` opens SDL audio with:

- `AUDIO_S16SYS` format.
- Two channels.
- A fixed 48 kHz output rate and `samples = 1024`.
- An `SDL_AudioStream` that converts from the game's exact AI rate (22047 Hz for Duke's 22050 Hz request) to the fixed output rate.
- `SDL_QueueAudio` for the converted output.
- A remaining-frame callback that maps queued output frames back to source-rate frames before `osAiGetLength` reports them.

When the game changes rate, the old stream is flushed and drained into the existing SDL queue before it is replaced. Already queued output therefore remains in order and the new rate starts after it, without dropping a chunk or changing playback speed.

The Duke runtime also sets `config.message_queue_control.requeue_vi = true`, preserving the VI cadence needed by the scheduler and audio producer.

## 8. Keep synchronous audio work within the VI cadence

Audio RSP tasks execute synchronously so the generated scheduler sees completion in order. In a Debug build, CMake normally compiles generated C and the ASP translation unit at `-O0`; the audio task can then exceed the 16.67 ms VI interval and drain the host queue. `Duke64-RE/CMakeLists.txt` adds `-O2` for those generated/runtime target sources in Debug builds while retaining debug symbols. This keeps the synchronous task within the cadence without changing the generated semantics.

## 9. Generated-source cleanup

Temporary diagnostic instrumentation was removed after the scheduler ordering and queue behavior were confirmed:

- `Duke64-RE/RecompiledFuncs/funcs_3.c` retains the permanent `recomp_set_audio_command_list` call but no frame/timing logging or Windows diagnostic includes.
- `Duke64-RE/RecompiledFuncs/funcs_14.c` retains the permanent bridge declaration and scheduler hook but no scheduler probe logging.
- The runtime sources retain no `audio-debug`, `vi-debug`, or `debug_` probes from the investigation.

The generated C files are artifacts. When regenerating them, verify that the manual function boundaries still produce the complete functions and that the two permanent bridge hooks are still present. The TOML files preserve the function-size and ASP-target inputs, but generated-file custom hooks should not be assumed to survive an unrelated regeneration step.

## Verification record

### Build

From the repository root:

```powershell
cmake -S Duke64-RE -B Duke64-RE/build-pc-rt64-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
ninja -C Duke64-RE/build-pc-rt64-debug Duke64Recompiled
```

The build completed successfully. The linker emitted the existing warning that both `wmain` and `main` were found and that it used `main`.

### Executable smoke runs

```powershell
timeout 5s Duke64-RE/build-pc-rt64-debug/Duke64Recompiled.exe
$env:SDL_AUDIODRIVER = "dummy"
timeout 5s Duke64-RE/build-pc-rt64-debug/Duke64Recompiled.exe
```

Both runs stayed alive for the full interval without audio conversion, queue, or runtime errors. Exit code `124` is expected from the timeout wrapper.

### Verification scope

The smoke runs verify executable startup and the live SDL audio initialization, conversion, queue, and scheduler path. They are not a subjective listening test or a waveform comparison.
