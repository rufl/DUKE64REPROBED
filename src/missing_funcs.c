#include "recomp.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define PAK_CHANNELS 4
#define PAK_BANKS 64
#define PAK_BLOCKS 256
#define PAK_BLOCK_SIZE 32

static uint8_t controller_pak[PAK_CHANNELS][PAK_BANKS][PAK_BLOCKS][PAK_BLOCK_SIZE];
static uint8_t active_bank[PAK_CHANNELS];
static int controller_pak_loaded;

static void load_controller_pak(void) {
    if (controller_pak_loaded) return;
    controller_pak_loaded = 1;
    FILE* file = NULL;
    if (fopen_s(&file, "duke64_controller_pak.bin", "rb") != 0) file = NULL;
    if (file != NULL) {
        fread(controller_pak, sizeof(controller_pak), 1, file);
        fclose(file);
    }
}

static void save_controller_pak(void) {
    FILE* file = NULL;
    if (fopen_s(&file, "duke64_controller_pak.bin.tmp", "wb") != 0) file = NULL;
    if (file == NULL) return;
    if (fwrite(controller_pak, sizeof(controller_pak), 1, file) == 1) {
        fclose(file);
        remove("duke64_controller_pak.bin");
        rename("duke64_controller_pak.bin.tmp", "duke64_controller_pak.bin");
    } else {
        fclose(file);
        remove("duke64_controller_pak.bin.tmp");
    }
}

RECOMP_FUNC void __ll_rshift_recomp(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    uint64_t value = (uint64_t)(uint32_t)ctx->r4 << 32 | (uint32_t)ctx->r5;
    uint32_t shift = (uint32_t)ctx->r7 & 63;
    uint64_t result = (int64_t)value >> shift;
    ctx->r2 = (uint32_t)result;
    ctx->r3 = (uint32_t)(result >> 32);
}

RECOMP_FUNC void __osPfsSelectBank_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint32_t pfs = (uint32_t)ctx->r4;
    uint32_t channel = MEM_W(8, pfs) & (PAK_CHANNELS - 1);
    active_bank[channel] = (uint8_t)(MEM_B(57, pfs) & (PAK_BANKS - 1));
    load_controller_pak();
    ctx->r2 = 0;
    (void)rdram;
}

RECOMP_FUNC void __osContRamRead_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint32_t channel = (uint32_t)ctx->r5 & (PAK_CHANNELS - 1);
    uint32_t block = (uint32_t)ctx->r6 & (PAK_BLOCKS - 1);
    uint32_t buffer = (uint32_t)ctx->r7;
    load_controller_pak();
    memcpy(&MEM_B(0, buffer), controller_pak[channel][active_bank[channel]][block], PAK_BLOCK_SIZE);
    ctx->r2 = 0;
    (void)rdram;
}

RECOMP_FUNC void __osContRamWrite_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint32_t channel = (uint32_t)ctx->r5 & (PAK_CHANNELS - 1);
    uint32_t block = (uint32_t)ctx->r6 & (PAK_BLOCKS - 1);
    uint32_t buffer = (uint32_t)ctx->r7;
    load_controller_pak();
    memcpy(controller_pak[channel][active_bank[channel]][block], &MEM_B(0, buffer), PAK_BLOCK_SIZE);
    save_controller_pak();
    ctx->r2 = 0;
    (void)rdram;
}

RECOMP_FUNC void proutSprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    gpr dst = ctx->r4;
    gpr src = ctx->r5;
    uint32_t count = (uint32_t)ctx->r6;
    for (uint32_t i = 0; i < count; ++i) {
        MEM_B((int32_t)i, dst) = MEM_B((int32_t)i, src);
    }
    ctx->r2 = ADD32(dst, count);
    (void)rdram;
}
