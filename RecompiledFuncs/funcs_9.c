#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void animatefist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072A70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80072A74: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80072A78: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80072A7C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072A80: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80072A84: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80072A88: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80072A8C: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80072A90: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80072A94: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80072A98: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x80072A9C: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x80072AA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80072AA4: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80072AA8: lh          $t0, 0x2E6($a2)
    ctx->r8 = S32(MEM_H(ctx->r6, 0X2E6));
    // 0x80072AAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072AB0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80072AB4: slti        $at, $t0, 0x21
    ctx->r1 = SIGNED(ctx->r8) < 0X21 ? 1 : 0;
    // 0x80072AB8: bne         $at, $zero, L_80072AC4
    if (ctx->r1 != 0) {
        // 0x80072ABC: nop
    
            goto L_80072AC4;
    }
    // 0x80072ABC: nop

    // 0x80072AC0: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
L_80072AC4:
    // 0x80072AC4: bgtzl       $t0, L_80072AD8
    if (SIGNED(ctx->r8) > 0) {
        // 0x80072AC8: lh          $a0, 0x28A($a2)
        ctx->r4 = S32(MEM_H(ctx->r6, 0X28A));
            goto L_80072AD8;
    }
    goto skip_0;
    // 0x80072AC8: lh          $a0, 0x28A($a2)
    ctx->r4 = S32(MEM_H(ctx->r6, 0X28A));
    skip_0:
    // 0x80072ACC: b           L_80072C04
    // 0x80072AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80072C04;
    // 0x80072AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80072AD4: lh          $a0, 0x28A($a2)
    ctx->r4 = S32(MEM_H(ctx->r6, 0X28A));
L_80072AD8:
    // 0x80072AD8: sh          $a1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r5;
    // 0x80072ADC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80072AE0: jal         0x80091A38
    // 0x80072AE4: sh          $t0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r8;
    klabs(rdram, ctx);
        goto after_0;
    // 0x80072AE4: sh          $t0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r8;
    after_0:
    // 0x80072AE8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80072AEC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80072AF0: lh          $t0, 0x34($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X34));
    // 0x80072AF4: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80072AF8: addiu       $a3, $a3, -0x9A0
    ctx->r7 = ADD32(ctx->r7, -0X9A0);
    // 0x80072AFC: sll         $t3, $t0, 6
    ctx->r11 = S32(ctx->r8 << 6);
    // 0x80072B00: addiu       $t4, $t3, 0x200
    ctx->r12 = ADD32(ctx->r11, 0X200);
    // 0x80072B04: andi        $t5, $t4, 0x7FF
    ctx->r13 = ctx->r12 & 0X7FF;
    // 0x80072B08: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80072B0C: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80072B10: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x80072B14: mflo        $a0
    ctx->r4 = lo;
    // 0x80072B18: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80072B1C: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80072B20: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x80072B24: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80072B28: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80072B2C: subu        $v1, $t1, $t9
    ctx->r3 = SUB32(ctx->r9, ctx->r25);
    // 0x80072B30: ori         $at, $at, 0x61F5
    ctx->r1 = ctx->r1 | 0X61F5;
    // 0x80072B34: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80072B38: bne         $at, $zero, L_80072B48
    if (ctx->r1 != 0) {
        // 0x80072B3C: lh          $a1, 0x3E($sp)
        ctx->r5 = S32(MEM_H(ctx->r29, 0X3E));
            goto L_80072B48;
    }
    // 0x80072B3C: lh          $a1, 0x3E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X3E));
    // 0x80072B40: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80072B44: ori         $v1, $v1, 0x61F4
    ctx->r3 = ctx->r3 | 0X61F4;
L_80072B48:
    // 0x80072B48: ori         $at, $zero, 0x9FD8
    ctx->r1 = 0 | 0X9FD8;
    // 0x80072B4C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80072B50: beq         $at, $zero, L_80072B5C
    if (ctx->r1 == 0) {
        // 0x80072B54: addiu       $t2, $t0, 0x6
        ctx->r10 = ADD32(ctx->r8, 0X6);
            goto L_80072B5C;
    }
    // 0x80072B54: addiu       $t2, $t0, 0x6
    ctx->r10 = ADD32(ctx->r8, 0X6);
    // 0x80072B58: ori         $v1, $zero, 0x9D62
    ctx->r3 = 0 | 0X9D62;
L_80072B5C:
    // 0x80072B5C: sll         $t3, $t2, 7
    ctx->r11 = S32(ctx->r10 << 7);
    // 0x80072B60: andi        $t4, $t3, 0x7FF
    ctx->r12 = ctx->r11 & 0X7FF;
    // 0x80072B64: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80072B68: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80072B6C: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80072B70: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80072B74: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80072B78: lh          $v0, 0x0($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0X0));
    // 0x80072B7C: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x80072B80: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80072B84: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80072B88: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80072B8C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80072B90: lui         $t1, 0x802A
    ctx->r9 = S32(0X802A << 16);
    // 0x80072B94: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80072B98: lb          $t1, 0x5600($t1)
    ctx->r9 = S32(MEM_B(ctx->r9, 0X5600));
    // 0x80072B9C: sra         $t7, $v0, 9
    ctx->r15 = S32(SIGNED(ctx->r2) >> 9);
    // 0x80072BA0: addiu       $v0, $t7, 0xD6
    ctx->r2 = ADD32(ctx->r15, 0XD6);
    // 0x80072BA4: sra         $t9, $t1, 4
    ctx->r25 = S32(SIGNED(ctx->r9) >> 4);
    // 0x80072BA8: subu        $t2, $t9, $t0
    ctx->r10 = SUB32(ctx->r25, ctx->r8);
    // 0x80072BAC: addiu       $t3, $t2, 0xDE
    ctx->r11 = ADD32(ctx->r10, 0XDE);
    // 0x80072BB0: addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // 0x80072BB4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80072BB8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80072BBC: addiu       $t7, $zero, 0x668
    ctx->r15 = ADD32(0, 0X668);
    // 0x80072BC0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80072BC4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80072BC8: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80072BCC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80072BD0: bgez        $t5, L_80072BE4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80072BD4: sra         $t6, $t5, 16
        ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
            goto L_80072BE4;
    }
    // 0x80072BD4: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80072BD8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80072BDC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80072BE0: sra         $t6, $at, 16
    ctx->r14 = S32(SIGNED(ctx->r1) >> 16);
L_80072BE4:
    // 0x80072BE4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80072BE8: nop

    // 0x80072BEC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80072BF0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80072BF4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80072BF8: jal         0x8005D13C
    // 0x80072BFC: nop

    rotatesprite(rdram, ctx);
        goto after_1;
    // 0x80072BFC: nop

    after_1:
    // 0x80072C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072C04:
    // 0x80072C04: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80072C08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80072C0C: jr          $ra
    // 0x80072C10: nop

    return;
    // 0x80072C10: nop

;}
RECOMP_FUNC void divscale5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091168: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009116C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091170: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80091174: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091178: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009117C: jal         0x800BB834
    // 0x80091180: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091180: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091188: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8009118C: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091190: jal         0x800BB89C
    // 0x80091194: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091194: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091198: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8009119C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800911A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800911A4: jr          $ra
    // 0x800911A8: nop

    return;
    // 0x800911A8: nop

;}
RECOMP_FUNC void divscale6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800911AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800911B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800911B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800911B8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800911BC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x800911C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800911C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800911C8: jal         0x800BB834
    // 0x800911CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800911CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800911D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800911D4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800911D8: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800911DC: jal         0x800BB89C
    // 0x800911E0: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800911E0: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x800911E4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800911E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800911EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800911F0: jr          $ra
    // 0x800911F4: nop

    return;
    // 0x800911F4: nop

;}
RECOMP_FUNC void func_80059398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059398: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x8005939C: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800593A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800593A4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800593A8: bgez        $a0, L_800593B8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800593AC: sra         $t8, $a0, 1
        ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800593B8;
    }
    // 0x800593AC: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800593B0: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
    // 0x800593B4: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_800593B8:
    // 0x800593B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800593BC: bne         $a1, $at, L_800593E0
    if (ctx->r5 != ctx->r1) {
        // 0x800593C0: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_800593E0;
    }
    // 0x800593C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800593C4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800593C8: addiu       $v0, $v0, 0x4D84
    ctx->r2 = ADD32(ctx->r2, 0X4D84);
    // 0x800593CC: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800593D0: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x800593D4: sb          $t8, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r24;
    // 0x800593D8: jr          $ra
    // 0x800593DC: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
    return;
    // 0x800593DC: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
L_800593E0:
    // 0x800593E0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800593E4: addiu       $v0, $v0, 0x4D84
    ctx->r2 = ADD32(ctx->r2, 0X4D84);
    // 0x800593E8: addu        $t9, $v0, $a1
    ctx->r25 = ADD32(ctx->r2, ctx->r5);
    // 0x800593EC: sb          $a0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r4;
    // 0x800593F0: jr          $ra
    // 0x800593F4: nop

    return;
    // 0x800593F4: nop

;}
RECOMP_FUNC void setanimation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD66C: lui         $t1, 0x802B
    ctx->r9 = S32(0X802B << 16);
    // 0x800AD670: addiu       $t1, $t1, -0x55A8
    ctx->r9 = ADD32(ctx->r9, -0X55A8);
    // 0x800AD674: lw          $t0, 0x0($t1)
    ctx->r8 = S32(MEM_W(ctx->r9, 0X0));
    // 0x800AD678: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD67C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AD680: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AD684: slti        $at, $t0, 0x3F
    ctx->r1 = SIGNED(ctx->r8) < 0X3F ? 1 : 0;
    // 0x800AD688: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AD68C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD690: bne         $at, $zero, L_800AD6A0
    if (ctx->r1 != 0) {
        // 0x800AD694: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_800AD6A0;
    }
    // 0x800AD694: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800AD698: b           L_800AD758
    // 0x800AD69C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AD758;
    // 0x800AD69C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AD6A0:
    // 0x800AD6A0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800AD6A4: blez        $t0, L_800AD6D8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800AD6A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AD6D8;
    }
    // 0x800AD6A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD6AC: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x800AD6B0: addiu       $v1, $v1, -0x5940
    ctx->r3 = ADD32(ctx->r3, -0X5940);
L_800AD6B4:
    // 0x800AD6B4: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800AD6B8: bnel        $a1, $t8, L_800AD6CC
    if (ctx->r5 != ctx->r24) {
        // 0x800AD6BC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800AD6CC;
    }
    goto skip_0;
    // 0x800AD6BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800AD6C0: b           L_800AD6D8
    // 0x800AD6C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800AD6D8;
    // 0x800AD6C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800AD6C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800AD6CC:
    // 0x800AD6CC: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800AD6D0: bne         $at, $zero, L_800AD6B4
    if (ctx->r1 != 0) {
        // 0x800AD6D4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800AD6B4;
    }
    // 0x800AD6D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800AD6D8:
    // 0x800AD6D8: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x800AD6DC: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AD6E0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AD6E4: sh          $a0, -0x5640($at)
    MEM_H(-0X5640, ctx->r1) = ctx->r4;
    // 0x800AD6E8: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AD6EC: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800AD6F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800AD6F4: lw          $t2, 0x28($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800AD6F8: sw          $a1, -0x5940($at)
    MEM_W(-0X5940, ctx->r1) = ctx->r5;
    // 0x800AD6FC: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AD700: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800AD704: sw          $t2, -0x5840($at)
    MEM_W(-0X5840, ctx->r1) = ctx->r10;
    // 0x800AD708: lw          $t4, 0x0($a1)
    ctx->r12 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800AD70C: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800AD710: negu        $t5, $a3
    ctx->r13 = SUB32(0, ctx->r7);
    // 0x800AD714: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x800AD718: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AD71C: bne         $at, $zero, L_800AD734
    if (ctx->r1 != 0) {
        // 0x800AD720: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800AD734;
    }
    // 0x800AD720: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800AD724: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AD728: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800AD72C: b           L_800AD740
    // 0x800AD730: sw          $a3, -0x5740($at)
    MEM_W(-0X5740, ctx->r1) = ctx->r7;
        goto L_800AD740;
    // 0x800AD730: sw          $a3, -0x5740($at)
    MEM_W(-0X5740, ctx->r1) = ctx->r7;
L_800AD734:
    // 0x800AD734: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AD738: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800AD73C: sw          $t5, -0x5740($at)
    MEM_W(-0X5740, ctx->r1) = ctx->r13;
L_800AD740:
    // 0x800AD740: bne         $a2, $t0, L_800AD74C
    if (ctx->r6 != ctx->r8) {
        // 0x800AD744: nop
    
            goto L_800AD74C;
    }
    // 0x800AD744: nop

    // 0x800AD748: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_800AD74C:
    // 0x800AD74C: jal         0x800753A8
    // 0x800AD750: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    setinterpolation(rdram, ctx);
        goto after_0;
    // 0x800AD750: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800AD754: lw          $v0, 0x18($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X18));
L_800AD758:
    // 0x800AD758: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800AD75C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AD760: jr          $ra
    // 0x800AD764: nop

    return;
    // 0x800AD764: nop

;}
RECOMP_FUNC void FindDistance3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099414: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80099418: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8009941C: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80099420: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80099424: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80099428: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8009942C: nop

    // 0x80099430: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80099434: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80099438: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8009943C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80099440: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80099444: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80099448: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8009944C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80099450: jr          $ra
    // 0x80099454: nop

    return;
    // 0x80099454: nop

;}
RECOMP_FUNC void func_80063168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063168: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x8006316C: lw          $t6, -0x1994($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X1994));
    // 0x80063170: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80063174: lwc1        $f8, 0x4C5C($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, 0X4C5C));
    // 0x80063178: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8006317C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80063180: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80063184: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063188: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8006318C: lw          $t7, -0x1990($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X1990));
    // 0x80063190: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063198: addiu       $t8, $t7, -0x64
    ctx->r24 = ADD32(ctx->r15, -0X64);
    // 0x8006319C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800631A0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800631A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800631A8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800631AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800631B0: swc1        $f18, -0x6520($at)
    MEM_W(-0X6520, ctx->r1) = ctx->f18.u32l;
    // 0x800631B4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800631B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800631BC: jal         0x8006E420
    // 0x800631C0: nop

    getanglef(rdram, ctx);
        goto after_0;
    // 0x800631C0: nop

    after_0:
    // 0x800631C4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800631C8: addiu       $v1, $v1, -0x651C
    ctx->r3 = ADD32(ctx->r3, -0X651C);
    // 0x800631CC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800631D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800631D4: lwc1        $f8, 0x4C60($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, 0X4C60));
    // 0x800631D8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = S32(MEM_W(ctx->r3, 0X0));
    // 0x800631DC: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800631E0: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x800631E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800631E8: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800631EC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800631F0: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x800631F4: lw          $t9, -0x19A0($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X19A0));
    // 0x800631F8: lw          $t1, -0x199C($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, -0X199C));
    // 0x800631FC: lw          $v0, -0x1998($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X1998));
    // 0x80063200: bgez        $t9, L_80063210
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80063204: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_80063210;
    }
    // 0x80063204: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80063208: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8006320C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80063210:
    // 0x80063210: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80063214: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006321C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80063220: swc1        $f18, -0x5B70($at)
    MEM_W(-0X5B70, ctx->r1) = ctx->f18.u32l;
    // 0x80063224: bgez        $t1, L_80063234
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80063228: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_80063234;
    }
    // 0x80063228: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8006322C: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x80063230: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_80063234:
    // 0x80063234: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80063238: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006323C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80063240: swc1        $f6, -0x5B6C($at)
    MEM_W(-0X5B6C, ctx->r1) = ctx->f6.u32l;
    // 0x80063244: bgez        $v0, L_80063254
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80063248: sra         $t3, $v0, 5
        ctx->r11 = S32(SIGNED(ctx->r2) >> 5);
            goto L_80063254;
    }
    // 0x80063248: sra         $t3, $v0, 5
    ctx->r11 = S32(SIGNED(ctx->r2) >> 5);
    // 0x8006324C: addiu       $at, $v0, 0x1F
    ctx->r1 = ADD32(ctx->r2, 0X1F);
    // 0x80063250: sra         $t3, $at, 5
    ctx->r11 = S32(SIGNED(ctx->r1) >> 5);
L_80063254:
    // 0x80063254: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80063258: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006325C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80063260: swc1        $f10, -0x5B68($at)
    MEM_W(-0X5B68, ctx->r1) = ctx->f10.u32l;
    // 0x80063264: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80063268: jr          $ra
    // 0x8006326C: sw          $v0, -0x2348($at)
    MEM_W(-0X2348, ctx->r1) = ctx->r2;
    return;
    // 0x8006326C: sw          $v0, -0x2348($at)
    MEM_W(-0X2348, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void divscale2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009107C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091084: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091088: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009108C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80091090: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091098: jal         0x800BB834
    // 0x8009109C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x8009109C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800910A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800910A4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800910A8: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800910AC: jal         0x800BB89C
    // 0x800910B0: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800910B0: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x800910B4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800910B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800910BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800910C0: jr          $ra
    // 0x800910C4: nop

    return;
    // 0x800910C4: nop

;}
RECOMP_FUNC void divscale3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800910C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800910CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800910D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800910D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800910D8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800910DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800910E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800910E4: jal         0x800BB834
    // 0x800910E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800910E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800910EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800910F0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800910F4: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800910F8: jal         0x800BB89C
    // 0x800910FC: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800910FC: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091100: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091108: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009110C: jr          $ra
    // 0x80091110: nop

    return;
    // 0x80091110: nop

;}
RECOMP_FUNC void display_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FC64: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8004FC68: addiu       $t0, $t0, 0x4418
    ctx->r8 = ADD32(ctx->r8, 0X4418);
    // 0x8004FC6C: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FC70: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8004FC74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004FC78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004FC7C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8004FC80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004FC84: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8004FC88: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8004FC8C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8004FC90: addiu       $s0, $s0, 0x4410
    ctx->r16 = ADD32(ctx->r16, 0X4410);
    // 0x8004FC94: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8004FC98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004FC9C: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004FCA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004FCA4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004FCA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004FCAC: jal         0x800BD8C8
    // 0x8004FCB0: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    guTranslate(rdram, ctx);
        goto after_0;
    // 0x8004FCB0: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    after_0:
    // 0x8004FCB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004FCB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004FCBC: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004FCC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004FCC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004FCC8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004FCCC: jal         0x800BD974
    // 0x8004FCD0: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    guScale(rdram, ctx);
        goto after_1;
    // 0x8004FCD0: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    after_1:
    // 0x8004FCD4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8004FCD8: addiu       $t0, $t0, 0x4418
    ctx->r8 = ADD32(ctx->r8, 0X4418);
    // 0x8004FCDC: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FCE0: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x8004FCE4: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x8004FCE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8004FCEC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8004FCF0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004FCF4: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004FCF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004FCFC: ori         $at, $at, 0x300
    ctx->r1 = ctx->r1 | 0X300;
    // 0x8004FD00: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8004FD04: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8004FD08: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FD0C: lui         $t4, 0x100
    ctx->r12 = S32(0X100 << 16);
    // 0x8004FD10: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x8004FD14: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8004FD18: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8004FD1C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8004FD20: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004FD24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004FD28: ori         $at, $at, 0x380
    ctx->r1 = ctx->r1 | 0X380;
    // 0x8004FD2C: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x8004FD30: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8004FD34: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FD38: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x8004FD3C: addiu       $t9, $t9, 0x1908
    ctx->r25 = ADD32(ctx->r25, 0X1908);
    // 0x8004FD40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8004FD44: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8004FD48: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8004FD4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8004FD50: jal         0x8005C28C
    // 0x8004FD54: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    clearscreen(rdram, ctx);
        goto after_2;
    // 0x8004FD54: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_2:
    // 0x8004FD58: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8004FD5C: addiu       $t0, $t0, 0x4418
    ctx->r8 = ADD32(ctx->r8, 0X4418);
    // 0x8004FD60: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FD64: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8004FD68: lui         $t3, 0x55
    ctx->r11 = S32(0X55 << 16);
    // 0x8004FD6C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8004FD70: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8004FD74: ori         $t3, $t3, 0x3048
    ctx->r11 = ctx->r11 | 0X3048;
    // 0x8004FD78: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8004FD7C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8004FD80: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8004FD84: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FD88: lui         $t5, 0xEE00
    ctx->r13 = S32(0XEE00 << 16);
    // 0x8004FD8C: lui         $t6, 0x32
    ctx->r14 = S32(0X32 << 16);
    // 0x8004FD90: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8004FD94: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8004FD98: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8004FD9C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8004FDA0: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FDA4: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8004FDA8: ori         $t8, $t8, 0x602
    ctx->r24 = ctx->r24 | 0X602;
    // 0x8004FDAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8004FDB0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8004FDB4: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x8004FDB8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8004FDBC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8004FDC0: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FDC4: lui         $t3, 0x4A
    ctx->r11 = S32(0X4A << 16);
    // 0x8004FDC8: lui         $t2, 0xED05
    ctx->r10 = S32(0XED05 << 16);
    // 0x8004FDCC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8004FDD0: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8004FDD4: ori         $t2, $t2, 0x403C
    ctx->r10 = ctx->r10 | 0X403C;
    // 0x8004FDD8: ori         $t3, $t3, 0xC384
    ctx->r11 = ctx->r11 | 0XC384;
    // 0x8004FDDC: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8004FDE0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8004FDE4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8004FDE8: lhu         $t4, 0x3778($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X3778);
    // 0x8004FDEC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8004FDF0: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8004FDF4: sltiu       $at, $t4, 0xA
    ctx->r1 = ctx->r12 < 0XA ? 1 : 0;
    // 0x8004FDF8: beq         $at, $zero, L_80050698
    if (ctx->r1 == 0) {
        // 0x8004FDFC: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80050698;
    }
    // 0x8004FDFC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8004FE00: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8004FE04: addu        $at, $at, $t4
    gpr jr_addend_8004FE0C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8004FE08: lw          $t4, 0x37EC($at)
    ctx->r12 = ADD32(ctx->r1, 0X37EC);
    // 0x8004FE0C: jr          $t4
    // 0x8004FE10: nop

    switch (jr_addend_8004FE0C >> 2) {
        case 0: goto L_8004FE14; break;
        case 1: goto L_8004FEDC; break;
        case 2: goto L_8004FF0C; break;
        case 3: goto L_8004FFE8; break;
        case 4: goto L_8005014C; break;
        case 5: goto L_800501F4; break;
        case 6: goto L_80050248; break;
        case 7: goto L_80050360; break;
        case 8: goto L_800504E8; break;
        case 9: goto L_80050594; break;
        default: switch_error(__func__, 0x8004FE0C, 0x801037EC);
    }
    // 0x8004FE10: nop

L_8004FE14:
    // 0x8004FE14: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8004FE18: lh          $t5, 0x12D0($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X12D0));
    // 0x8004FE1C: beq         $t5, $zero, L_8004FE34
    if (ctx->r13 == 0) {
        // 0x8004FE20: nop
    
            goto L_8004FE34;
    }
    // 0x8004FE20: nop

    // 0x8004FE24: jal         0x8005857C
    // 0x8004FE28: nop

    func_8005857C(rdram, ctx);
        goto after_3;
    // 0x8004FE28: nop

    after_3:
    // 0x8004FE2C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8004FE30: sh          $zero, 0x12D0($at)
    MEM_H(0X12D0, ctx->r1) = 0;
L_8004FE34:
    // 0x8004FE34: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004FE38: lh          $t6, 0x3774($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X3774));
    // 0x8004FE3C: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x8004FE40: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004FE44: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8004FE48: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x8004FE4C: bgezl       $v0, L_8004FE60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004FE50: sll         $s0, $v0, 16
        ctx->r16 = S32(ctx->r2 << 16);
            goto L_8004FE60;
    }
    goto skip_0;
    // 0x8004FE50: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    skip_0:
    // 0x8004FE54: b           L_8004FE68
    // 0x8004FE58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8004FE68;
    // 0x8004FE58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004FE5C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
L_8004FE60:
    // 0x8004FE60: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8004FE64: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8004FE68:
    // 0x8004FE68: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8004FE6C: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8004FE70: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x8004FE74: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004FE78: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004FE7C: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004FE80: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8004FE84: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8004FE88: jal         0x8006E994
    // 0x8004FE8C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_4;
    // 0x8004FE8C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_4:
    // 0x8004FE90: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004FE94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004FE98: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8004FE9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004FEA0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004FEA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004FEA8: addiu       $t4, $zero, 0xE56
    ctx->r12 = ADD32(0, 0XE56);
    // 0x8004FEAC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8004FEB0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8004FEB4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8004FEB8: jal         0x8005D13C
    // 0x8004FEBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_5;
    // 0x8004FEBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x8004FEC0: sltiu       $a0, $s0, 0x1
    ctx->r4 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x8004FEC4: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8004FEC8: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004FECC: jal         0x8004F96C
    // 0x8004FED0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_8004F96C(rdram, ctx);
        goto after_6;
    // 0x8004FED0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_6:
    // 0x8004FED4: b           L_800506BC
    // 0x8004FED8: nop

        goto L_800506BC;
    // 0x8004FED8: nop

L_8004FEDC:
    // 0x8004FEDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004FEE0: jal         0x8004F9A0
    // 0x8004FEE4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    func_8004F9A0(rdram, ctx);
        goto after_7;
    // 0x8004FEE4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_7:
    // 0x8004FEE8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004FEEC: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x8004FEF0: xori        $t8, $a0, 0xA0
    ctx->r24 = ctx->r4 ^ 0XA0;
    // 0x8004FEF4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8004FEF8: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8004FEFC: jal         0x8004F96C
    // 0x8004FF00: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_8;
    // 0x8004FF00: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_8:
    // 0x8004FF04: b           L_800506BC
    // 0x8004FF08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800506BC;
    // 0x8004FF08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8004FF0C:
    // 0x8004FF0C: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8004FF10: lui         $t2, 0xED16
    ctx->r10 = S32(0XED16 << 16);
    // 0x8004FF14: lui         $t3, 0x39
    ctx->r11 = S32(0X39 << 16);
    // 0x8004FF18: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8004FF1C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8004FF20: ori         $t3, $t3, 0x42B0
    ctx->r11 = ctx->r11 | 0X42B0;
    // 0x8004FF24: ori         $t2, $t2, 0xC110
    ctx->r10 = ctx->r10 | 0XC110;
    // 0x8004FF28: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004FF2C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8004FF30: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8004FF34: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x8004FF38: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004FF3C: sll         $t4, $a0, 3
    ctx->r12 = S32(ctx->r4 << 3);
    // 0x8004FF40: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x8004FF44: bne         $at, $zero, L_8004FF54
    if (ctx->r1 != 0) {
        // 0x8004FF48: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_8004FF54;
    }
    // 0x8004FF48: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004FF4C: b           L_8004FF60
    // 0x8004FF50: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
        goto L_8004FF60;
    // 0x8004FF50: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
L_8004FF54:
    // 0x8004FF54: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x8004FF58: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8004FF5C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_8004FF60:
    // 0x8004FF60: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8004FF64: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8004FF68: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x8004FF6C: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004FF70: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004FF74: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004FF78: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8004FF7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8004FF80: jal         0x8006E994
    // 0x8004FF84: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_9;
    // 0x8004FF84: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_9:
    // 0x8004FF88: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004FF8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004FF90: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8004FF94: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004FF98: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004FF9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004FFA0: addiu       $t9, $zero, 0xF56
    ctx->r25 = ADD32(0, 0XF56);
    // 0x8004FFA4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8004FFA8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8004FFAC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8004FFB0: jal         0x8005D13C
    // 0x8004FFB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_10;
    // 0x8004FFB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_10:
    // 0x8004FFB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004FFBC: jal         0x8004F9A0
    // 0x8004FFC0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    func_8004F9A0(rdram, ctx);
        goto after_11;
    // 0x8004FFC0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_11:
    // 0x8004FFC4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004FFC8: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x8004FFCC: xori        $t1, $a0, 0xA0
    ctx->r9 = ctx->r4 ^ 0XA0;
    // 0x8004FFD0: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8004FFD4: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8004FFD8: jal         0x8004F96C
    // 0x8004FFDC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_12;
    // 0x8004FFDC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_12:
    // 0x8004FFE0: b           L_800506BC
    // 0x8004FFE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800506BC;
    // 0x8004FFE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8004FFE8:
    // 0x8004FFE8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8004FFEC: lh          $t4, 0x3774($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, 0X3774));
    // 0x8004FFF0: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8004FFF4: bnel        $t4, $at, L_80050010
    if (ctx->r12 != ctx->r1) {
        // 0x8004FFF8: lw          $v0, 0x0($t0)
        ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
            goto L_80050010;
    }
    goto skip_1;
    // 0x8004FFF8: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    skip_1:
    // 0x8004FFFC: jal         0x80058E1C
    // 0x80050000: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    sound(rdram, ctx);
        goto after_13;
    // 0x80050000: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_13:
    // 0x80050004: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80050008: addiu       $t0, $t0, 0x4418
    ctx->r8 = ADD32(ctx->r8, 0X4418);
    // 0x8005000C: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
L_80050010:
    // 0x80050010: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80050014: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80050018: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8005001C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80050020: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80050024: lui         $t6, 0xED16
    ctx->r14 = S32(0XED16 << 16);
    // 0x80050028: lui         $t8, 0x39
    ctx->r24 = S32(0X39 << 16);
    // 0x8005002C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050030: ori         $t8, $t8, 0x42B0
    ctx->r24 = ctx->r24 | 0X42B0;
    // 0x80050034: ori         $t6, $t6, 0xC110
    ctx->r14 = ctx->r14 | 0XC110;
    // 0x80050038: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005003C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050040: addiu       $t7, $zero, 0xF56
    ctx->r15 = ADD32(0, 0XF56);
    // 0x80050044: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80050048: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005004C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80050050: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80050054: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80050058: jal         0x8005D13C
    // 0x8005005C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    rotatesprite(rdram, ctx);
        goto after_14;
    // 0x8005005C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_14:
    // 0x80050060: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80050064: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x80050068: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005006C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80050070: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x80050074: bne         $at, $zero, L_8005011C
    if (ctx->r1 != 0) {
        // 0x80050078: addiu       $t9, $v1, 0x28
        ctx->r25 = ADD32(ctx->r3, 0X28);
            goto L_8005011C;
    }
    // 0x80050078: addiu       $t9, $v1, 0x28
    ctx->r25 = ADD32(ctx->r3, 0X28);
    // 0x8005007C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80050080: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80050084: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80050088: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8005008C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80050090: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80050094: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80050098: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8005009C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800500A0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800500A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800500A8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800500AC: addiu       $v0, $v1, -0x3C
    ctx->r2 = ADD32(ctx->r3, -0X3C);
    // 0x800500B0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800500B4: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800500B8: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x800500BC: slti        $at, $v0, 0x62
    ctx->r1 = SIGNED(ctx->r2) < 0X62 ? 1 : 0;
    // 0x800500C0: sub.d       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f18.d - ctx->f10.d;
    // 0x800500C4: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x800500C8: nop

    // 0x800500CC: bc1fl       L_800500E0
    if (!c1cs) {
        // 0x800500D0: cvt.s.d     $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
            goto L_800500E0;
    }
    goto skip_2;
    // 0x800500D0: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
    skip_2:
    // 0x800500D4: b           L_800500E0
    // 0x800500D8: cvt.s.d     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.fl = CVT_S_D(ctx->f12.d);
        goto L_800500E0;
    // 0x800500D8: cvt.s.d     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.fl = CVT_S_D(ctx->f12.d);
    // 0x800500DC: cvt.s.d     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f0.fl = CVT_S_D(ctx->f2.d);
L_800500E0:
    // 0x800500E0: bne         $at, $zero, L_800500F0
    if (ctx->r1 != 0) {
        // 0x800500E4: div.s       $f2, $f16, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
            goto L_800500F0;
    }
    // 0x800500E4: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800500E8: b           L_800500F0
    // 0x800500EC: addiu       $s0, $zero, 0x61
    ctx->r16 = ADD32(0, 0X61);
        goto L_800500F0;
    // 0x800500EC: addiu       $s0, $zero, 0x61
    ctx->r16 = ADD32(0, 0X61);
L_800500F0:
    // 0x800500F0: addiu       $t2, $s0, 0x64
    ctx->r10 = ADD32(ctx->r16, 0X64);
    // 0x800500F4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800500F8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800500FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050100: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80050104: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80050108: addiu       $t3, $zero, 0xF57
    ctx->r11 = ADD32(0, 0XF57);
    // 0x8005010C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80050110: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80050114: jal         0x8005D13C
    // 0x80050118: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    rotatesprite(rdram, ctx);
        goto after_15;
    // 0x80050118: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_15:
L_8005011C:
    // 0x8005011C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80050120: jal         0x8004F9A0
    // 0x80050124: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    func_8004F9A0(rdram, ctx);
        goto after_16;
    // 0x80050124: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_16:
    // 0x80050128: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005012C: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050130: xori        $t4, $a0, 0xA0
    ctx->r12 = ctx->r4 ^ 0XA0;
    // 0x80050134: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80050138: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8005013C: jal         0x8004F96C
    // 0x80050140: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_17;
    // 0x80050140: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_17:
    // 0x80050144: b           L_800506BC
    // 0x80050148: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800506BC;
    // 0x80050148: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8005014C:
    // 0x8005014C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050150: lh          $v0, 0x3774($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X3774));
    // 0x80050154: addiu       $t7, $zero, 0x8C
    ctx->r15 = ADD32(0, 0X8C);
    // 0x80050158: addiu       $t9, $zero, 0xF58
    ctx->r25 = ADD32(0, 0XF58);
    // 0x8005015C: addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // 0x80050160: bgez        $v0, L_80050170
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80050164: sll         $s0, $v0, 16
        ctx->r16 = S32(ctx->r2 << 16);
            goto L_80050170;
    }
    // 0x80050164: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80050168: b           L_80050178
    // 0x8005016C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80050178;
    // 0x8005016C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80050170:
    // 0x80050170: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80050174: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_80050178:
    // 0x80050178: subu        $v0, $t7, $s0
    ctx->r2 = SUB32(ctx->r15, ctx->r16);
    // 0x8005017C: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80050180: beq         $at, $zero, L_80050194
    if (ctx->r1 == 0) {
        // 0x80050184: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80050194;
    }
    // 0x80050184: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80050188: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005018C: b           L_800501A0
    // 0x80050190: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800501A0;
    // 0x80050190: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80050194:
    // 0x80050194: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80050198: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005019C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
L_800501A0:
    // 0x800501A0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800501A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800501A8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800501AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800501B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800501B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800501B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800501BC: jal         0x8005D13C
    // 0x800501C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_18;
    // 0x800501C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_18:
    // 0x800501C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800501C8: jal         0x8004F9A0
    // 0x800501CC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8004F9A0(rdram, ctx);
        goto after_19;
    // 0x800501CC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_19:
    // 0x800501D0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800501D4: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x800501D8: xori        $t1, $a0, 0x82
    ctx->r9 = ctx->r4 ^ 0X82;
    // 0x800501DC: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x800501E0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x800501E4: jal         0x8004F96C
    // 0x800501E8: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_20;
    // 0x800501E8: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_20:
    // 0x800501EC: b           L_800506BC
    // 0x800501F0: nop

        goto L_800506BC;
    // 0x800501F0: nop

L_800501F4:
    // 0x800501F4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800501F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800501FC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050200: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050204: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050208: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8005020C: addiu       $t4, $zero, 0xF5A
    ctx->r12 = ADD32(0, 0XF5A);
    // 0x80050210: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80050214: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80050218: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005021C: jal         0x8005D13C
    // 0x80050220: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_21;
    // 0x80050220: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_21:
    // 0x80050224: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050228: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x8005022C: xori        $t5, $a0, 0x28
    ctx->r13 = ctx->r4 ^ 0X28;
    // 0x80050230: sltiu       $t5, $t5, 0x1
    ctx->r13 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x80050234: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80050238: jal         0x8004F96C
    // 0x8005023C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_22;
    // 0x8005023C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_22:
    // 0x80050240: b           L_800506BC
    // 0x80050244: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800506BC;
    // 0x80050244: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80050248:
    // 0x80050248: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005024C: lh          $v0, 0x3774($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X3774));
    // 0x80050250: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80050254: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80050258: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8005025C: addiu       $v0, $t7, -0x50
    ctx->r2 = ADD32(ctx->r15, -0X50);
    // 0x80050260: bgez        $v0, L_80050270
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80050264: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80050270;
    }
    // 0x80050264: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80050268: b           L_80050274
    // 0x8005026C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80050274;
    // 0x8005026C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80050270:
    // 0x80050270: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80050274:
    // 0x80050274: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    // 0x80050278: bne         $at, $zero, L_80050288
    if (ctx->r1 != 0) {
        // 0x8005027C: addiu       $t1, $zero, 0x100
        ctx->r9 = ADD32(0, 0X100);
            goto L_80050288;
    }
    // 0x8005027C: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x80050280: b           L_800502A4
    // 0x80050284: addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
        goto L_800502A4;
    // 0x80050284: addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
L_80050288:
    // 0x80050288: bgez        $v0, L_80050298
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005028C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80050298;
    }
    // 0x8005028C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80050290: b           L_80050298
    // 0x80050294: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80050298;
    // 0x80050294: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80050298:
    // 0x80050298: sll         $s0, $v1, 16
    ctx->r16 = S32(ctx->r3 << 16);
    // 0x8005029C: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800502A0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800502A4:
    // 0x800502A4: subu        $a3, $t1, $s0
    ctx->r7 = SUB32(ctx->r9, ctx->r16);
    // 0x800502A8: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x800502AC: jal         0x8006E994
    // 0x800502B0: sra         $a3, $t2, 16
    ctx->r7 = S32(SIGNED(ctx->r10) >> 16);
    setrotatespriteflags(rdram, ctx);
        goto after_23;
    // 0x800502B0: sra         $a3, $t2, 16
    ctx->r7 = S32(SIGNED(ctx->r10) >> 16);
    after_23:
    // 0x800502B4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800502B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800502BC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800502C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800502C4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800502C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800502CC: addiu       $t4, $zero, 0xF59
    ctx->r12 = ADD32(0, 0XF59);
    // 0x800502D0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800502D4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800502D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800502DC: jal         0x8005D13C
    // 0x800502E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_24;
    // 0x800502E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_24:
    // 0x800502E4: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x800502E8: sra         $t5, $a3, 16
    ctx->r13 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800502EC: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800502F0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800502F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800502F8: jal         0x8006E994
    // 0x800502FC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    setrotatespriteflags(rdram, ctx);
        goto after_25;
    // 0x800502FC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_25:
    // 0x80050300: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80050304: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80050308: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8005030C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050310: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050314: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050318: addiu       $t6, $zero, 0xF5B
    ctx->r14 = ADD32(0, 0XF5B);
    // 0x8005031C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80050320: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80050324: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80050328: jal         0x8005D13C
    // 0x8005032C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_26;
    // 0x8005032C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_26:
    // 0x80050330: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80050334: jal         0x8004F9A0
    // 0x80050338: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    func_8004F9A0(rdram, ctx);
        goto after_27;
    // 0x80050338: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    after_27:
    // 0x8005033C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050340: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050344: xori        $t8, $a0, 0x9A
    ctx->r24 = ctx->r4 ^ 0X9A;
    // 0x80050348: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8005034C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80050350: jal         0x8004F96C
    // 0x80050354: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_28;
    // 0x80050354: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_28:
    // 0x80050358: b           L_800506BC
    // 0x8005035C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800506BC;
    // 0x8005035C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80050360:
    // 0x80050360: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80050364: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x80050368: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005036C: bnel        $v1, $at, L_80050388
    if (ctx->r3 != ctx->r1) {
        // 0x80050370: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80050388;
    }
    goto skip_3;
    // 0x80050370: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_3:
    // 0x80050374: jal         0x80058E1C
    // 0x80050378: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    sound(rdram, ctx);
        goto after_29;
    // 0x80050378: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_29:
    // 0x8005037C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80050380: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x80050384: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_80050388:
    // 0x80050388: bnel        $v1, $at, L_800503A4
    if (ctx->r3 != ctx->r1) {
        // 0x8005038C: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800503A4;
    }
    goto skip_4;
    // 0x8005038C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_4:
    // 0x80050390: jal         0x80058E1C
    // 0x80050394: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    sound(rdram, ctx);
        goto after_30;
    // 0x80050394: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_30:
    // 0x80050398: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005039C: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x800503A0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_800503A4:
    // 0x800503A4: bnel        $v1, $at, L_800503B8
    if (ctx->r3 != ctx->r1) {
        // 0x800503A8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800503B8;
    }
    goto skip_5;
    // 0x800503A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    skip_5:
    // 0x800503AC: jal         0x80058E1C
    // 0x800503B0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    sound(rdram, ctx);
        goto after_31;
    // 0x800503B0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_31:
    // 0x800503B4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800503B8:
    // 0x800503B8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800503BC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800503C0: jal         0x8006E994
    // 0x800503C4: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    setrotatespriteflags(rdram, ctx);
        goto after_32;
    // 0x800503C4: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_32:
    // 0x800503C8: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x800503CC: addiu       $t0, $t0, 0x4418
    ctx->r8 = ADD32(ctx->r8, 0X4418);
    // 0x800503D0: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x800503D4: lui         $t2, 0xED16
    ctx->r10 = S32(0XED16 << 16);
    // 0x800503D8: lui         $t3, 0x39
    ctx->r11 = S32(0X39 << 16);
    // 0x800503DC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800503E0: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800503E4: ori         $t3, $t3, 0x42B0
    ctx->r11 = ctx->r11 | 0X42B0;
    // 0x800503E8: ori         $t2, $t2, 0xC110
    ctx->r10 = ctx->r10 | 0XC110;
    // 0x800503EC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800503F0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800503F4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800503F8: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x800503FC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050400: ldc1        $f10, 0x3818($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3818);
    // 0x80050404: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80050408: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8005040C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80050410: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x80050414: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80050418: sll         $s0, $v1, 16
    ctx->r16 = S32(ctx->r3 << 16);
    // 0x8005041C: sra         $t4, $s0, 16
    ctx->r12 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80050420: andi        $t5, $v1, 0x8
    ctx->r13 = ctx->r3 & 0X8;
    // 0x80050424: mul.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80050428: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x8005042C: addiu       $t6, $zero, 0xF5C
    ctx->r14 = ADD32(0, 0XF5C);
    // 0x80050430: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x80050434: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80050438: bne         $t5, $zero, L_80050448
    if (ctx->r13 != 0) {
        // 0x8005043C: cvt.s.d     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
            goto L_80050448;
    }
    // 0x8005043C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80050440: bne         $at, $zero, L_8005047C
    if (ctx->r1 != 0) {
        // 0x80050444: addiu       $t8, $s0, 0xA0
        ctx->r24 = ADD32(ctx->r16, 0XA0);
            goto L_8005047C;
    }
    // 0x80050444: addiu       $t8, $s0, 0xA0
    ctx->r24 = ADD32(ctx->r16, 0XA0);
L_80050448:
    // 0x80050448: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005044C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80050450: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050454: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050458: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8005045C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050460: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80050464: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80050468: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005046C: jal         0x8005D13C
    // 0x80050470: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_33;
    // 0x80050470: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_33:
    // 0x80050474: b           L_800504BC
    // 0x80050478: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
        goto L_800504BC;
    // 0x80050478: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8005047C:
    // 0x8005047C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80050480: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050484: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050488: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005048C: bgez        $s0, L_8005049C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80050490: sra         $t7, $s0, 1
        ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8005049C;
    }
    // 0x80050490: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80050494: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x80050498: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8005049C:
    // 0x8005049C: addiu       $t9, $t7, 0x78
    ctx->r25 = ADD32(ctx->r15, 0X78);
    // 0x800504A0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800504A4: addiu       $t1, $zero, 0xF59
    ctx->r9 = ADD32(0, 0XF59);
    // 0x800504A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800504AC: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800504B0: jal         0x8005D13C
    // 0x800504B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_34;
    // 0x800504B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_34:
    // 0x800504B8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800504BC:
    // 0x800504BC: jal         0x8004F9A0
    // 0x800504C0: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    func_8004F9A0(rdram, ctx);
        goto after_35;
    // 0x800504C0: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_35:
    // 0x800504C4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800504C8: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x800504CC: xori        $t2, $a0, 0x4F
    ctx->r10 = ctx->r4 ^ 0X4F;
    // 0x800504D0: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x800504D4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800504D8: jal         0x8004F96C
    // 0x800504DC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_36;
    // 0x800504DC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_36:
    // 0x800504E0: b           L_800506BC
    // 0x800504E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800506BC;
    // 0x800504E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800504E8:
    // 0x800504E8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800504EC: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x800504F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800504F4: bnel        $v1, $at, L_80050510
    if (ctx->r3 != ctx->r1) {
        // 0x800504F8: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80050510;
    }
    goto skip_6;
    // 0x800504F8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_6:
    // 0x800504FC: jal         0x80058E1C
    // 0x80050500: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    sound(rdram, ctx);
        goto after_37;
    // 0x80050500: addiu       $a0, $zero, 0xC3
    ctx->r4 = ADD32(0, 0XC3);
    after_37:
    // 0x80050504: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80050508: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x8005050C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80050510:
    // 0x80050510: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80050514: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80050518: addiu       $t6, $zero, 0xE6
    ctx->r14 = ADD32(0, 0XE6);
    // 0x8005051C: subu        $s0, $t6, $t5
    ctx->r16 = SUB32(ctx->r14, ctx->r13);
    // 0x80050520: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x80050524: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80050528: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005052C: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80050530: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80050534: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80050538: mflo        $t9
    ctx->r25 = lo;
    // 0x8005053C: addiu       $v0, $t7, 0xA0
    ctx->r2 = ADD32(ctx->r15, 0XA0);
    // 0x80050540: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80050544: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80050548: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x8005054C: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80050550: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80050554: addiu       $t3, $zero, 0xF5D
    ctx->r11 = ADD32(0, 0XF5D);
    // 0x80050558: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005055C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80050560: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80050564: jal         0x8005D13C
    // 0x80050568: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    rotatesprite(rdram, ctx);
        goto after_38;
    // 0x80050568: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_38:
    // 0x8005056C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80050570: jal         0x8004F9A0
    // 0x80050574: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    func_8004F9A0(rdram, ctx);
        goto after_39;
    // 0x80050574: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_39:
    // 0x80050578: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8005057C: slti        $t4, $a0, -0x46
    ctx->r12 = SIGNED(ctx->r4) < -0X46 ? 1 : 0;
    // 0x80050580: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80050584: jal         0x8004F96C
    // 0x80050588: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_40;
    // 0x80050588: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_40:
    // 0x8005058C: b           L_800506BC
    // 0x80050590: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800506BC;
    // 0x80050590: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80050594:
    // 0x80050594: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80050598: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x8005059C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800505A0: bnel        $v1, $at, L_800505D0
    if (ctx->r3 != ctx->r1) {
        // 0x800505A4: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800505D0;
    }
    goto skip_7;
    // 0x800505A4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_7:
    // 0x800505A8: jal         0x800585D4
    // 0x800505AC: nop

    stopsong(rdram, ctx);
        goto after_41;
    // 0x800505AC: nop

    after_41:
    // 0x800505B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800505B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800505B8: sh          $t8, 0x12D0($at)
    MEM_H(0X12D0, ctx->r1) = ctx->r24;
    // 0x800505BC: jal         0x80058E1C
    // 0x800505C0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    sound(rdram, ctx);
        goto after_42;
    // 0x800505C0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_42:
    // 0x800505C4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800505C8: lh          $v1, 0x3774($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X3774));
    // 0x800505CC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_800505D0:
    // 0x800505D0: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800505D4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800505D8: addiu       $t1, $zero, 0x178
    ctx->r9 = ADD32(0, 0X178);
    // 0x800505DC: subu        $v0, $t1, $t7
    ctx->r2 = SUB32(ctx->r9, ctx->r15);
    // 0x800505E0: bgez        $v0, L_800505F0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800505E4: addiu       $a3, $zero, 0x100
        ctx->r7 = ADD32(0, 0X100);
            goto L_800505F0;
    }
    // 0x800505E4: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x800505E8: b           L_800505FC
    // 0x800505EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800505FC;
    // 0x800505EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800505F0:
    // 0x800505F0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800505F4: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800505F8: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800505FC:
    // 0x800505FC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80050600: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80050604: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80050608: sra         $t4, $a2, 16
    ctx->r12 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005060C: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80050610: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80050614: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80050618: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8005061C: jal         0x8006E994
    // 0x80050620: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_43;
    // 0x80050620: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_43:
    // 0x80050624: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80050628: lh          $t6, 0x3774($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X3774));
    // 0x8005062C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050630: ldc1        $f10, 0x3820($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X3820);
    // 0x80050634: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80050638: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8005063C: ldc1        $f6, 0x3828($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X3828);
    // 0x80050640: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x80050644: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050648: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005064C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050650: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050654: mul.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80050658: addiu       $t5, $zero, 0xF5E
    ctx->r13 = ADD32(0, 0XF5E);
    // 0x8005065C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80050660: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80050664: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80050668: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x8005066C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050670: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050674: jal         0x8005D13C
    // 0x80050678: nop

    rotatesprite(rdram, ctx);
        goto after_44;
    // 0x80050678: nop

    after_44:
    // 0x8005067C: sltiu       $a0, $s0, 0x1
    ctx->r4 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80050680: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80050684: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80050688: jal         0x8004F96C
    // 0x8005068C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_8004F96C(rdram, ctx);
        goto after_45;
    // 0x8005068C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_45:
    // 0x80050690: b           L_800506BC
    // 0x80050694: nop

        goto L_800506BC;
    // 0x80050694: nop

L_80050698:
    // 0x80050698: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005069C: sb          $t7, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r15;
    // 0x800506A0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800506A4: jal         0x800585D4
    // 0x800506A8: sh          $t9, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r25;
    stopsong(rdram, ctx);
        goto after_46;
    // 0x800506A8: sh          $t9, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r25;
    after_46:
    // 0x800506AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800506B0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800506B4: sh          $t2, 0x12D0($at)
    MEM_H(0X12D0, ctx->r1) = ctx->r10;
    // 0x800506B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800506BC:
    // 0x800506BC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800506C0: lh          $a0, -0x9DC($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X9DC));
    // 0x800506C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800506C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800506CC: blez        $a0, L_80050700
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800506D0: addiu       $v1, $v1, -0x6C48
        ctx->r3 = ADD32(ctx->r3, -0X6C48);
            goto L_80050700;
    }
    // 0x800506D0: addiu       $v1, $v1, -0x6C48
    ctx->r3 = ADD32(ctx->r3, -0X6C48);
L_800506D4:
    // 0x800506D4: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x800506D8: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800506DC: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x800506E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800506E4: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x800506E8: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800506EC: or          $v0, $v0, $t6
    ctx->r2 = ctx->r2 | ctx->r14;
    // 0x800506F0: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800506F4: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x800506F8: bne         $at, $zero, L_800506D4
    if (ctx->r1 != 0) {
        // 0x800506FC: sra         $v0, $t5, 16
        ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
            goto L_800506D4;
    }
    // 0x800506FC: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
L_80050700:
    // 0x80050700: andi        $t9, $v0, 0x1000
    ctx->r25 = ctx->r2 & 0X1000;
    // 0x80050704: beq         $t9, $zero, L_80050730
    if (ctx->r25 == 0) {
        // 0x80050708: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80050730;
    }
    // 0x80050708: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8005070C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050710: sb          $t2, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r10;
    // 0x80050714: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050718: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x8005071C: jal         0x800585D4
    // 0x80050720: sh          $t3, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r11;
    stopsong(rdram, ctx);
        goto after_47;
    // 0x80050720: sh          $t3, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r11;
    after_47:
    // 0x80050724: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80050728: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8005072C: sh          $t4, 0x12D0($at)
    MEM_H(0X12D0, ctx->r1) = ctx->r12;
L_80050730:
    // 0x80050730: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050734: addiu       $v0, $v0, 0x3774
    ctx->r2 = ADD32(ctx->r2, 0X3774);
    // 0x80050738: lh          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X0));
    // 0x8005073C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80050740: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80050744: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80050748: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x8005074C: jr          $ra
    // 0x80050750: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80050750: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void alEvtqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9E20: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C9E24: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C9E28: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C9E2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9E30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C9E34: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C9E38: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800C9E3C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C9E40: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800C9E44: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C9E48: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800C9E4C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C9E50: blez        $a2, L_800C9E74
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800C9E54: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800C9E74;
    }
    // 0x800C9E54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C9E58: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_800C9E5C:
    // 0x800C9E5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C9E60: jal         0x800BF7A0
    // 0x800C9E64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_0;
    // 0x800C9E64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800C9E68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C9E6C: bne         $s0, $s3, L_800C9E5C
    if (ctx->r16 != ctx->r19) {
        // 0x800C9E70: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_800C9E5C;
    }
    // 0x800C9E70: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_800C9E74:
    // 0x800C9E74: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C9E78: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C9E7C: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800C9E80: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C9E84: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C9E88: jr          $ra
    // 0x800C9E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C9E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void animatewalls(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD768: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AD76C: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AD770: lh          $a2, -0x55AC($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55AC));
    // 0x800AD774: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AD778: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AD77C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AD780: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AD784: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AD788: blez        $a2, L_800AD9AC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AD78C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800AD9AC;
    }
    // 0x800AD78C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AD790: lui         $s1, 0x802B
    ctx->r17 = S32(0X802B << 16);
    // 0x800AD794: addiu       $s1, $s1, -0x6940
    ctx->r17 = ADD32(ctx->r17, -0X6940);
    // 0x800AD798: addiu       $s4, $zero, 0x297
    ctx->r20 = ADD32(0, 0X297);
    // 0x800AD79C: addiu       $s3, $zero, 0x10C
    ctx->r19 = ADD32(0, 0X10C);
    // 0x800AD7A0: addiu       $s2, $zero, 0x298
    ctx->r18 = ADD32(0, 0X298);
    // 0x800AD7A4: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
L_800AD7A8:
    // 0x800AD7A8: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800AD7AC: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x800AD7B0: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800AD7B4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800AD7B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AD7BC: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800AD7C0: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800AD7C4: slti        $at, $a0, 0x114
    ctx->r1 = SIGNED(ctx->r4) < 0X114 ? 1 : 0;
    // 0x800AD7C8: bne         $at, $zero, L_800AD7F4
    if (ctx->r1 != 0) {
        // 0x800AD7CC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800AD7F4;
    }
    // 0x800AD7CC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800AD7D0: addiu       $t8, $v1, -0x1018
    ctx->r24 = ADD32(ctx->r3, -0X1018);
    // 0x800AD7D4: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x800AD7D8: beq         $at, $zero, L_800AD8AC
    if (ctx->r1 == 0) {
        // 0x800AD7DC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800AD8AC;
    }
    // 0x800AD7DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800AD7E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AD7E4: addu        $at, $at, $t8
    gpr jr_addend_800AD7EC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800AD7E8: lw          $t8, -0x79A4($at)
    ctx->r24 = ADD32(ctx->r1, -0X79A4);
    // 0x800AD7EC: jr          $t8
    // 0x800AD7F0: nop

    switch (jr_addend_800AD7EC >> 2) {
        case 0: goto L_800AD818; break;
        case 1: goto L_800AD8AC; break;
        case 2: goto L_800AD8AC; break;
        case 3: goto L_800AD818; break;
        case 4: goto L_800AD8AC; break;
        case 5: goto L_800AD818; break;
        case 6: goto L_800AD8AC; break;
        case 7: goto L_800AD818; break;
        case 8: goto L_800AD818; break;
        case 9: goto L_800AD818; break;
        default: switch_error(__func__, 0x800AD7EC, 0x8010865C);
    }
    // 0x800AD7F0: nop

L_800AD7F4:
    // 0x800AD7F4: addiu       $t9, $v1, -0x107
    ctx->r25 = ADD32(ctx->r3, -0X107);
    // 0x800AD7F8: sltiu       $at, $t9, 0xD
    ctx->r1 = ctx->r25 < 0XD ? 1 : 0;
    // 0x800AD7FC: beq         $at, $zero, L_800AD8AC
    if (ctx->r1 == 0) {
        // 0x800AD800: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800AD8AC;
    }
    // 0x800AD800: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800AD804: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AD808: addu        $at, $at, $t9
    gpr jr_addend_800AD810 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AD80C: lw          $t9, -0x797C($at)
    ctx->r25 = ADD32(ctx->r1, -0X797C);
    // 0x800AD810: jr          $t9
    // 0x800AD814: nop

    switch (jr_addend_800AD810 >> 2) {
        case 0: goto L_800AD818; break;
        case 1: goto L_800AD818; break;
        case 2: goto L_800AD818; break;
        case 3: goto L_800AD818; break;
        case 4: goto L_800AD818; break;
        case 5: goto L_800AD854; break;
        case 6: goto L_800AD854; break;
        case 7: goto L_800AD854; break;
        case 8: goto L_800AD818; break;
        case 9: goto L_800AD818; break;
        case 10: goto L_800AD818; break;
        case 11: goto L_800AD818; break;
        case 12: goto L_800AD818; break;
        default: switch_error(__func__, 0x800AD810, 0x80108684);
    }
    // 0x800AD814: nop

L_800AD818:
    // 0x800AD818: jal         0x8009800C
    // 0x800AD81C: nop

    krand2(rdram, ctx);
        goto after_0;
    // 0x800AD81C: nop

    after_0:
    // 0x800AD820: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x800AD824: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800AD828: beq         $at, $zero, L_800AD83C
    if (ctx->r1 == 0) {
        // 0x800AD82C: lui         $a2, 0x802B
        ctx->r6 = S32(0X802B << 16);
            goto L_800AD83C;
    }
    // 0x800AD82C: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AD830: lh          $t1, 0x10($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800AD834: sh          $s3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r19;
    // 0x800AD838: sw          $t1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r9;
L_800AD83C:
    // 0x800AD83C: lh          $a2, -0x55AC($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55AC));
    // 0x800AD840: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x800AD844: addiu       $t3, $t3, -0x6940
    ctx->r11 = ADD32(ctx->r11, -0X6940);
    // 0x800AD848: sll         $t2, $a2, 3
    ctx->r10 = S32(ctx->r6 << 3);
    // 0x800AD84C: b           L_800AD99C
    // 0x800AD850: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
        goto L_800AD99C;
    // 0x800AD850: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
L_800AD854:
    // 0x800AD854: lw          $v0, 0x4($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800AD858: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x800AD85C: addiu       $t5, $t5, -0x6940
    ctx->r13 = ADD32(ctx->r13, -0X6940);
    // 0x800AD860: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x800AD864: bltz        $v0, L_800AD88C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AD868: addu        $a1, $t4, $t5
        ctx->r5 = ADD32(ctx->r12, ctx->r13);
            goto L_800AD88C;
    }
    // 0x800AD868: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800AD86C: lh          $v1, 0x18($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
    // 0x800AD870: addiu       $at, $zero, 0x509
    ctx->r1 = ADD32(0, 0X509);
    // 0x800AD874: beq         $v1, $at, L_800AD88C
    if (ctx->r3 == ctx->r1) {
        // 0x800AD878: addiu       $at, $zero, 0x512
        ctx->r1 = ADD32(0, 0X512);
            goto L_800AD88C;
    }
    // 0x800AD878: addiu       $at, $zero, 0x512
    ctx->r1 = ADD32(0, 0X512);
    // 0x800AD87C: beql        $v1, $at, L_800AD890
    if (ctx->r3 == ctx->r1) {
        // 0x800AD880: addiu       $t6, $a0, 0x1
        ctx->r14 = ADD32(ctx->r4, 0X1);
            goto L_800AD890;
    }
    goto skip_0;
    // 0x800AD880: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800AD884: b           L_800AD99C
    // 0x800AD888: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
        goto L_800AD99C;
    // 0x800AD888: sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
L_800AD88C:
    // 0x800AD88C: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
L_800AD890:
    // 0x800AD890: sh          $t6, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r14;
    // 0x800AD894: lh          $t7, 0x10($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800AD898: addiu       $at, $zero, 0x10F
    ctx->r1 = ADD32(0, 0X10F);
    // 0x800AD89C: bnel        $t7, $at, L_800AD9A0
    if (ctx->r15 != ctx->r1) {
        // 0x800AD8A0: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800AD9A0;
    }
    goto skip_1;
    // 0x800AD8A0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    skip_1:
    // 0x800AD8A4: b           L_800AD99C
    // 0x800AD8A8: sh          $s3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r19;
        goto L_800AD99C;
    // 0x800AD8A8: sh          $s3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r19;
L_800AD8AC:
    // 0x800AD8AC: lh          $v1, 0xE($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0XE));
    // 0x800AD8B0: andi        $t8, $v1, 0x10
    ctx->r24 = ctx->r3 & 0X10;
    // 0x800AD8B4: beq         $t8, $zero, L_800AD98C
    if (ctx->r24 == 0) {
        // 0x800AD8B8: nop
    
            goto L_800AD98C;
    }
    // 0x800AD8B8: nop

    // 0x800AD8BC: lh          $v0, 0x12($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X12));
    // 0x800AD8C0: andi        $t9, $v1, 0xFE
    ctx->r25 = ctx->r3 & 0XFE;
    // 0x800AD8C4: beq         $v0, $s4, L_800AD8DC
    if (ctx->r2 == ctx->r20) {
        // 0x800AD8C8: nop
    
            goto L_800AD8DC;
    }
    // 0x800AD8C8: nop

    // 0x800AD8CC: beq         $v0, $s2, L_800AD8DC
    if (ctx->r2 == ctx->r18) {
        // 0x800AD8D0: addiu       $at, $zero, 0x299
        ctx->r1 = ADD32(0, 0X299);
            goto L_800AD8DC;
    }
    // 0x800AD8D0: addiu       $at, $zero, 0x299
    ctx->r1 = ADD32(0, 0X299);
    // 0x800AD8D4: bne         $v0, $at, L_800AD98C
    if (ctx->r2 != ctx->r1) {
        // 0x800AD8D8: nop
    
            goto L_800AD98C;
    }
    // 0x800AD8D8: nop

L_800AD8DC:
    // 0x800AD8DC: beq         $t9, $zero, L_800AD98C
    if (ctx->r25 == 0) {
        // 0x800AD8E0: lw          $v0, 0x4($s1)
        ctx->r2 = S32(MEM_W(ctx->r17, 0X4));
            goto L_800AD98C;
    }
    // 0x800AD8E0: lw          $v0, 0x4($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800AD8E4: lbu         $t0, 0x20($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X20);
    // 0x800AD8E8: lbu         $t2, 0x21($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X21);
    // 0x800AD8EC: lh          $t4, 0x18($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X18));
    // 0x800AD8F0: sra         $v1, $v0, 10
    ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
    // 0x800AD8F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AD8F8: subu        $t1, $t0, $v1
    ctx->r9 = SUB32(ctx->r8, ctx->r3);
    // 0x800AD8FC: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x800AD900: sb          $t1, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r9;
    // 0x800AD904: bne         $t4, $at, L_800AD918
    if (ctx->r12 != ctx->r1) {
        // 0x800AD908: sb          $t3, 0x21($s0)
        MEM_B(0X21, ctx->r16) = ctx->r11;
            goto L_800AD918;
    }
    // 0x800AD908: sb          $t3, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r11;
    // 0x800AD90C: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800AD910: b           L_800AD920
    // 0x800AD914: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
        goto L_800AD920;
    // 0x800AD914: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
L_800AD918:
    // 0x800AD918: addiu       $t5, $v0, 0x80
    ctx->r13 = ADD32(ctx->r2, 0X80);
    // 0x800AD91C: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
L_800AD920:
    // 0x800AD920: lw          $v0, 0x4($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800AD924: slti        $at, $v0, 0x800
    ctx->r1 = SIGNED(ctx->r2) < 0X800 ? 1 : 0;
    // 0x800AD928: beq         $at, $zero, L_800AD948
    if (ctx->r1 == 0) {
        // 0x800AD92C: andi        $t6, $v0, 0x80
        ctx->r14 = ctx->r2 & 0X80;
            goto L_800AD948;
    }
    // 0x800AD92C: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800AD930: beq         $t6, $zero, L_800AD940
    if (ctx->r14 == 0) {
        // 0x800AD934: nop
    
            goto L_800AD940;
    }
    // 0x800AD934: nop

    // 0x800AD938: b           L_800AD98C
    // 0x800AD93C: sh          $s4, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r20;
        goto L_800AD98C;
    // 0x800AD93C: sh          $s4, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r20;
L_800AD940:
    // 0x800AD940: b           L_800AD98C
    // 0x800AD944: sh          $s2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r18;
        goto L_800AD98C;
    // 0x800AD944: sh          $s2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r18;
L_800AD948:
    // 0x800AD948: jal         0x8009800C
    // 0x800AD94C: nop

    krand2(rdram, ctx);
        goto after_1;
    // 0x800AD94C: nop

    after_1:
    // 0x800AD950: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x800AD954: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x800AD958: beq         $at, $zero, L_800AD984
    if (ctx->r1 == 0) {
        // 0x800AD95C: lui         $a2, 0x802B
        ctx->r6 = S32(0X802B << 16);
            goto L_800AD984;
    }
    // 0x800AD95C: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AD960: jal         0x8009800C
    // 0x800AD964: nop

    krand2(rdram, ctx);
        goto after_2;
    // 0x800AD964: nop

    after_2:
    // 0x800AD968: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x800AD96C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x800AD970: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x800AD974: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x800AD978: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AD97C: b           L_800AD98C
    // 0x800AD980: lh          $a2, -0x55AC($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55AC));
        goto L_800AD98C;
    // 0x800AD980: lh          $a2, -0x55AC($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55AC));
L_800AD984:
    // 0x800AD984: sh          $s2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r18;
    // 0x800AD988: lh          $a2, -0x55AC($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55AC));
L_800AD98C:
    // 0x800AD98C: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x800AD990: addiu       $t2, $t2, -0x6940
    ctx->r10 = ADD32(ctx->r10, -0X6940);
    // 0x800AD994: sll         $t1, $a2, 3
    ctx->r9 = S32(ctx->r6 << 3);
    // 0x800AD998: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
L_800AD99C:
    // 0x800AD99C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_800AD9A0:
    // 0x800AD9A0: sltu        $at, $s1, $a1
    ctx->r1 = ctx->r17 < ctx->r5 ? 1 : 0;
    // 0x800AD9A4: bnel        $at, $zero, L_800AD7A8
    if (ctx->r1 != 0) {
        // 0x800AD9A8: lh          $v0, 0x0($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
            goto L_800AD7A8;
    }
    goto skip_2;
    // 0x800AD9A8: lh          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X0));
    skip_2:
L_800AD9AC:
    // 0x800AD9AC: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800AD9B0: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800AD9B4: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800AD9B8: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800AD9BC: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AD9C0: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800AD9C4: jr          $ra
    // 0x800AD9C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AD9C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004D460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004D468: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004D46C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D470: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x8004D474: addiu       $t9, $t9, -0x6C30
    ctx->r25 = ADD32(ctx->r25, -0X6C30);
    // 0x8004D478: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x8004D47C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8004D480: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x8004D484: ori         $t2, $t2, 0x2000
    ctx->r10 = ctx->r10 | 0X2000;
    // 0x8004D488: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8004D48C: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x8004D490: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x8004D494: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8004D498: addiu       $t0, $zero, 0x4000
    ctx->r8 = ADD32(0, 0X4000);
    // 0x8004D49C: ori         $t1, $zero, 0x8000
    ctx->r9 = 0 | 0X8000;
    // 0x8004D4A0: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x8004D4A4: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8004D4A8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8004D4AC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8004D4B0: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x8004D4B4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8004D4B8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8004D4BC: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8004D4C0: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x8004D4C4: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8004D4C8: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8004D4CC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8004D4D0: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8004D4D4: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x8004D4D8: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x8004D4DC: lui         $t1, 0x2
    ctx->r9 = S32(0X2 << 16);
    // 0x8004D4E0: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x8004D4E4: ori         $t4, $t4, 0x1
    ctx->r12 = ctx->r12 | 0X1;
    // 0x8004D4E8: ori         $t5, $t5, 0x8
    ctx->r13 = ctx->r13 | 0X8;
    // 0x8004D4EC: ori         $t6, $t6, 0x4
    ctx->r14 = ctx->r14 | 0X4;
    // 0x8004D4F0: ori         $t7, $t7, 0x2000
    ctx->r15 = ctx->r15 | 0X2000;
    // 0x8004D4F4: ori         $t8, $t8, 0x8
    ctx->r24 = ctx->r24 | 0X8;
    // 0x8004D4F8: ori         $t9, $t9, 0x4
    ctx->r25 = ctx->r25 | 0X4;
    // 0x8004D4FC: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
    // 0x8004D500: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x8004D504: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8004D508: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x8004D50C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8004D510: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8004D514: sw          $t4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r12;
    // 0x8004D518: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x8004D51C: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x8004D520: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x8004D524: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x8004D528: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x8004D52C: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    // 0x8004D530: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x8004D534: sw          $t1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r9;
    // 0x8004D538: sw          $v1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r3;
    // 0x8004D53C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8004D540: lbu         $t3, 0x5AF6($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X5AF6);
    // 0x8004D544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D548: beql        $t3, $zero, L_8004D55C
    if (ctx->r11 == 0) {
        // 0x8004D54C: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8004D55C;
    }
    goto skip_0;
    // 0x8004D54C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x8004D550: jal         0x8004D664
    // 0x8004D554: nop

    func_8004D664(rdram, ctx);
        goto after_0;
    // 0x8004D554: nop

    after_0:
    // 0x8004D558: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004D55C:
    // 0x8004D55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D560: jr          $ra
    // 0x8004D564: nop

    return;
    // 0x8004D564: nop

;}
RECOMP_FUNC void cameratext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074C28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80074C2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074C30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80074C34: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80074C38: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80074C3C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80074C40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074C44: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80074C48: addiu       $a2, $zero, 0x9B2
    ctx->r6 = ADD32(0, 0X9B2);
    // 0x80074C4C: jal         0x800724B0
    // 0x80074C50: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    myospal(rdram, ctx);
        goto after_0;
    // 0x80074C50: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    after_0:
    // 0x80074C54: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80074C58: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80074C5C: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    // 0x80074C60: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80074C64: addiu       $a2, $zero, 0x9B3
    ctx->r6 = ADD32(0, 0X9B3);
    // 0x80074C68: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    // 0x80074C6C: jal         0x800724B0
    // 0x80074C70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    myospal(rdram, ctx);
        goto after_1;
    // 0x80074C70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80074C74: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80074C78: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80074C7C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80074C80: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80074C84: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80074C88: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // 0x80074C8C: addiu       $a2, $zero, 0x9B3
    ctx->r6 = ADD32(0, 0X9B3);
    // 0x80074C90: jal         0x800724B0
    // 0x80074C94: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    myospal(rdram, ctx);
        goto after_2;
    // 0x80074C94: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    after_2:
    // 0x80074C98: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80074C9C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80074CA0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80074CA4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80074CA8: addiu       $a0, $zero, 0x114
    ctx->r4 = ADD32(0, 0X114);
    // 0x80074CAC: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // 0x80074CB0: addiu       $a2, $zero, 0x9B3
    ctx->r6 = ADD32(0, 0X9B3);
    // 0x80074CB4: jal         0x800724B0
    // 0x80074CB8: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    myospal(rdram, ctx);
        goto after_3;
    // 0x80074CB8: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    after_3:
    // 0x80074CBC: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x80074CC0: lw          $t2, -0x5370($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X5370));
    // 0x80074CC4: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x80074CC8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80074CCC: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80074CD0: beq         $t3, $zero, L_80074CEC
    if (ctx->r11 == 0) {
        // 0x80074CD4: addiu       $a2, $zero, 0x9B4
        ctx->r6 = ADD32(0, 0X9B4);
            goto L_80074CEC;
    }
    // 0x80074CD4: addiu       $a2, $zero, 0x9B4
    ctx->r6 = ADD32(0, 0X9B4);
    // 0x80074CD8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80074CDC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80074CE0: addiu       $a3, $zero, -0x20
    ctx->r7 = ADD32(0, -0X20);
    // 0x80074CE4: jal         0x800724B0
    // 0x80074CE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    myospal(rdram, ctx);
        goto after_4;
    // 0x80074CE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
L_80074CEC:
    // 0x80074CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80074CF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80074CF4: jr          $ra
    // 0x80074CF8: nop

    return;
    // 0x80074CF8: nop

;}
RECOMP_FUNC void displayrest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074CFC: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x80074D00: lh          $t6, -0x53DC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X53DC));
    // 0x80074D04: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80074D08: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80074D0C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80074D10: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80074D14: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80074D18: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80074D1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80074D20: lui         $s4, 0x802A
    ctx->r20 = S32(0X802A << 16);
    // 0x80074D24: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80074D28: addiu       $s4, $s4, 0x5770
    ctx->r20 = ADD32(ctx->r20, 0X5770);
    // 0x80074D2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80074D30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80074D34: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x80074D38: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80074D3C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80074D40: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80074D44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80074D48: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80074D4C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80074D50: jal         0x8005C28C
    // 0x80074D54: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    clearscreen(rdram, ctx);
        goto after_0;
    // 0x80074D54: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    after_0:
    // 0x80074D58: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80074D5C: addiu       $s3, $s3, 0x4418
    ctx->r19 = ADD32(ctx->r19, 0X4418);
    // 0x80074D60: lw          $v1, 0x0($s3)
    ctx->r3 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80074D64: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x80074D68: ori         $t0, $t0, 0x602
    ctx->r8 = ctx->r8 | 0X602;
    // 0x80074D6C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80074D70: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80074D74: lui         $t1, 0x802B
    ctx->r9 = S32(0X802B << 16);
    // 0x80074D78: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80074D7C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80074D80: lh          $t1, -0x54AC($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, -0X54AC));
    // 0x80074D84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80074D88: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x80074D8C: bnel        $t1, $at, L_8007512C
    if (ctx->r9 != ctx->r1) {
        // 0x80074D90: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8007512C;
    }
    goto skip_0;
    // 0x80074D90: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    skip_0:
    // 0x80074D94: lbu         $v1, -0x54B4($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X54B4);
    // 0x80074D98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80074D9C: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x80074DA0: beq         $v1, $at, L_80074F28
    if (ctx->r3 == ctx->r1) {
        // 0x80074DA4: addiu       $s1, $s1, -0x2904
        ctx->r17 = ADD32(ctx->r17, -0X2904);
            goto L_80074F28;
    }
    // 0x80074DA4: addiu       $s1, $s1, -0x2904
    ctx->r17 = ADD32(ctx->r17, -0X2904);
    // 0x80074DA8: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x80074DAC: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80074DB0: lh          $t2, -0x9DC($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X9DC));
    // 0x80074DB4: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x80074DB8: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80074DBC: beq         $at, $zero, L_80074F28
    if (ctx->r1 == 0) {
        // 0x80074DC0: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80074F28;
    }
    // 0x80074DC0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80074DC4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80074DC8: addiu       $s2, $zero, 0x38C
    ctx->r18 = ADD32(0, 0X38C);
    // 0x80074DCC: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
L_80074DD0:
    // 0x80074DD0: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80074DD4: addiu       $t4, $sp, 0x74
    ctx->r12 = ADD32(ctx->r29, 0X74);
    // 0x80074DD8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80074DDC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80074DE0: addiu       $a1, $sp, 0x7A
    ctx->r5 = ADD32(ctx->r29, 0X7A);
    // 0x80074DE4: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x80074DE8: jal         0x8006E6B0
    // 0x80074DEC: addiu       $a3, $sp, 0x76
    ctx->r7 = ADD32(ctx->r29, 0X76);
    getviewborder(rdram, ctx);
        goto after_1;
    // 0x80074DEC: addiu       $a3, $sp, 0x76
    ctx->r7 = ADD32(ctx->r29, 0X76);
    after_1:
    // 0x80074DF0: lh          $t6, 0x7A($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X7A));
    // 0x80074DF4: lh          $t2, 0x78($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X78));
    // 0x80074DF8: lw          $v1, 0x0($s3)
    ctx->r3 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80074DFC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80074E00: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80074E04: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80074E08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80074E0C: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x80074E10: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80074E14: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80074E18: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80074E1C: nop

    // 0x80074E20: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80074E24: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80074E28: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80074E2C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80074E30: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80074E34: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80074E38: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x80074E3C: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80074E40: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x80074E44: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x80074E48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80074E4C: lh          $t7, 0x76($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X76));
    // 0x80074E50: lh          $t3, 0x74($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X74));
    // 0x80074E54: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80074E58: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80074E5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80074E60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80074E64: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80074E68: nop

    // 0x80074E6C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80074E70: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80074E74: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80074E78: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80074E7C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80074E80: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x80074E84: sll         $t2, $t0, 12
    ctx->r10 = S32(ctx->r8 << 12);
    // 0x80074E88: andi        $t5, $t1, 0xFFF
    ctx->r13 = ctx->r9 & 0XFFF;
    // 0x80074E8C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80074E90: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80074E94: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x80074E98: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074E9C: mflo        $t7
    ctx->r15 = lo;
    // 0x80074EA0: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x80074EA4: lh          $a0, 0x2BE($t8)
    ctx->r4 = S32(MEM_H(ctx->r24, 0X2BE));
    // 0x80074EA8: bltz        $a0, L_80074EC0
    if (SIGNED(ctx->r4) < 0) {
        // 0x80074EAC: nop
    
            goto L_80074EC0;
    }
    // 0x80074EAC: nop

    // 0x80074EB0: jal         0x80074C28
    // 0x80074EB4: nop

    cameratext(rdram, ctx);
        goto after_2;
    // 0x80074EB4: nop

    after_2:
    // 0x80074EB8: b           L_80074F00
    // 0x80074EBC: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
        goto L_80074F00;
    // 0x80074EBC: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
L_80074EC0:
    // 0x80074EC0: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80074EC4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80074EC8: jal         0x8007351C
    // 0x80074ECC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    displayweapon(rdram, ctx);
        goto after_3;
    // 0x80074ECC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x80074ED0: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x80074ED4: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80074ED8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80074EDC: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80074EE0: mflo        $t0
    ctx->r8 = lo;
    // 0x80074EE4: addu        $t3, $s4, $t0
    ctx->r11 = ADD32(ctx->r20, ctx->r8);
    // 0x80074EE8: lh          $t4, 0x2E2($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X2E2));
    // 0x80074EEC: bnel        $t4, $zero, L_80074F04
    if (ctx->r12 != 0) {
        // 0x80074EF0: addiu       $t2, $s0, 0x1
        ctx->r10 = ADD32(ctx->r16, 0X1);
            goto L_80074F04;
    }
    goto skip_1;
    // 0x80074EF0: addiu       $t2, $s0, 0x1
    ctx->r10 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80074EF4: jal         0x80072F78
    // 0x80074EF8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    displaymasks(rdram, ctx);
        goto after_4;
    // 0x80074EF8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_4:
    // 0x80074EFC: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
L_80074F00:
    // 0x80074F00: addiu       $t2, $s0, 0x1
    ctx->r10 = ADD32(ctx->r16, 0X1);
L_80074F04:
    // 0x80074F04: sb          $t2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r10;
    // 0x80074F08: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x80074F0C: lh          $t5, -0x9DC($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X9DC));
    // 0x80074F10: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // 0x80074F14: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80074F18: bnel        $at, $zero, L_80074DD0
    if (ctx->r1 != 0) {
        // 0x80074F1C: sll         $a0, $v0, 16
        ctx->r4 = S32(ctx->r2 << 16);
            goto L_80074DD0;
    }
    goto skip_2;
    // 0x80074F1C: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    skip_2:
    // 0x80074F20: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x80074F24: lbu         $v1, -0x54B4($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X54B4);
L_80074F28:
    // 0x80074F28: blezl       $v1, L_8007512C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80074F2C: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8007512C;
    }
    goto skip_3;
    // 0x80074F2C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    skip_3:
    // 0x80074F30: jal         0x800754D4
    // 0x80074F34: lw          $a0, 0xA0($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XA0));
    dointerpolations(rdram, ctx);
        goto after_5;
    // 0x80074F34: lw          $a0, 0xA0($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XA0));
    after_5:
    // 0x80074F38: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x80074F3C: lbu         $t6, -0x5592($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X5592);
    // 0x80074F40: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80074F44: addiu       $a0, $a0, -0x9A0
    ctx->r4 = ADD32(ctx->r4, -0X9A0);
    // 0x80074F48: bne         $t6, $zero, L_8007508C
    if (ctx->r14 != 0) {
        // 0x80074F4C: lui         $t3, 0x802B
        ctx->r11 = S32(0X802B << 16);
            goto L_8007508C;
    }
    // 0x80074F4C: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x80074F50: lw          $v0, 0x90($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X90));
    // 0x80074F54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80074F58: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80074F5C: lh          $t7, 0x2BE($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X2BE));
    // 0x80074F60: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x80074F64: bne         $t7, $at, L_80075120
    if (ctx->r15 != ctx->r1) {
        // 0x80074F68: nop
    
            goto L_80075120;
    }
    // 0x80074F68: nop

    // 0x80074F6C: lh          $t8, -0x9D8($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X9D8));
    // 0x80074F70: lh          $t9, -0x53DC($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X53DC));
    // 0x80074F74: lw          $a3, 0xA0($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80074F78: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80074F7C: bne         $t8, $t9, L_8007501C
    if (ctx->r24 != ctx->r25) {
        // 0x80074F80: sra         $a2, $a3, 31
        ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
            goto L_8007501C;
    }
    // 0x80074F80: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80074F84: lh          $t0, -0x9DC($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, -0X9DC));
    // 0x80074F88: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x80074F8C: lui         $t4, 0x802B
    ctx->r12 = S32(0X802B << 16);
    // 0x80074F90: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x80074F94: bnel        $at, $zero, L_80075020
    if (ctx->r1 != 0) {
        // 0x80074F98: lw          $t7, 0x214($v0)
        ctx->r15 = S32(MEM_W(ctx->r2, 0X214));
            goto L_80075020;
    }
    goto skip_4;
    // 0x80074F98: lw          $t7, 0x214($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X214));
    skip_4:
    // 0x80074F9C: lw          $t3, -0x53C0($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, -0X53C0));
    // 0x80074FA0: lw          $t4, -0x53BC($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X53BC));
    // 0x80074FA4: lw          $a3, 0xA0($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80074FA8: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    // 0x80074FAC: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80074FB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80074FB4: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80074FB8: jal         0x8008FD60
    // 0x80074FBC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    mulscale16(rdram, ctx);
        goto after_6;
    // 0x80074FBC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80074FC0: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x80074FC4: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x80074FC8: lw          $t8, -0x53B0($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X53B0));
    // 0x80074FCC: lw          $t5, -0x53B4($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X53B4));
    // 0x80074FD0: lw          $a2, 0x48($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80074FD4: lw          $a3, 0x4C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80074FD8: subu        $a1, $t5, $t8
    ctx->r5 = SUB32(ctx->r13, ctx->r24);
    // 0x80074FDC: jal         0x8008FD60
    // 0x80074FE0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_7;
    // 0x80074FE0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_7:
    // 0x80074FE4: lui         $t0, 0x802B
    ctx->r8 = S32(0X802B << 16);
    // 0x80074FE8: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x80074FEC: lh          $t3, -0x5392($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X5392));
    // 0x80074FF0: lh          $t0, -0x5394($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, -0X5394));
    // 0x80074FF4: lw          $a2, 0x48($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80074FF8: lw          $a3, 0x4C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80074FFC: subu        $t4, $t0, $t3
    ctx->r12 = SUB32(ctx->r8, ctx->r11);
    // 0x80075000: addiu       $t1, $t4, 0x400
    ctx->r9 = ADD32(ctx->r12, 0X400);
    // 0x80075004: andi        $t2, $t1, 0x7FF
    ctx->r10 = ctx->r9 & 0X7FF;
    // 0x80075008: addiu       $a1, $t2, -0x400
    ctx->r5 = ADD32(ctx->r10, -0X400);
    // 0x8007500C: jal         0x8008FD60
    // 0x80075010: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_8;
    // 0x80075010: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_8:
    // 0x80075014: b           L_80075120
    // 0x80075018: nop

        goto L_80075120;
    // 0x80075018: nop

L_8007501C:
    // 0x8007501C: lw          $t7, 0x214($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X214));
L_80075020:
    // 0x80075020: lw          $t5, 0x238($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X238));
    // 0x80075024: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80075028: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8007502C: subu        $a1, $t7, $t5
    ctx->r5 = SUB32(ctx->r15, ctx->r13);
    // 0x80075030: jal         0x8008FD60
    // 0x80075034: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_9;
    // 0x80075034: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_9:
    // 0x80075038: lw          $v1, 0x90($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X90));
    // 0x8007503C: lw          $a2, 0x48($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80075040: lw          $a3, 0x4C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80075044: lw          $t3, 0x218($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X218));
    // 0x80075048: lw          $t4, 0x23C($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, 0X23C));
    // 0x8007504C: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    // 0x80075050: jal         0x8008FD60
    // 0x80075054: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_10;
    // 0x80075054: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_10:
    // 0x80075058: lw          $t6, 0x90($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X90));
    // 0x8007505C: lw          $a2, 0x48($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80075060: lw          $a3, 0x4C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80075064: lh          $t7, 0x282($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X282));
    // 0x80075068: lh          $t5, 0x284($t6)
    ctx->r13 = S32(MEM_H(ctx->r14, 0X284));
    // 0x8007506C: subu        $t8, $t7, $t5
    ctx->r24 = SUB32(ctx->r15, ctx->r13);
    // 0x80075070: addiu       $t9, $t8, 0x400
    ctx->r25 = ADD32(ctx->r24, 0X400);
    // 0x80075074: andi        $t0, $t9, 0x7FF
    ctx->r8 = ctx->r25 & 0X7FF;
    // 0x80075078: addiu       $a1, $t0, -0x400
    ctx->r5 = ADD32(ctx->r8, -0X400);
    // 0x8007507C: jal         0x8008FD60
    // 0x80075080: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_11;
    // 0x80075080: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_11:
    // 0x80075084: b           L_80075120
    // 0x80075088: nop

        goto L_80075120;
    // 0x80075088: nop

L_8007508C:
    // 0x8007508C: lui         $t4, 0x802B
    ctx->r12 = S32(0X802B << 16);
    // 0x80075090: lw          $t4, -0x5494($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X5494));
    // 0x80075094: lw          $t3, -0x5488($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, -0X5488));
    // 0x80075098: addiu       $t5, $zero, 0xA00
    ctx->r13 = ADD32(0, 0XA00);
    // 0x8007509C: sra         $t2, $t4, 3
    ctx->r10 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800750A0: addu        $v0, $t3, $t2
    ctx->r2 = ADD32(ctx->r11, ctx->r10);
    // 0x800750A4: subu        $t8, $t5, $v0
    ctx->r24 = SUB32(ctx->r13, ctx->r2);
    // 0x800750A8: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800750AC: andi        $t9, $t8, 0x7FF
    ctx->r25 = ctx->r24 & 0X7FF;
    // 0x800750B0: sw          $v0, -0x5488($at)
    MEM_W(-0X5488, ctx->r1) = ctx->r2;
    // 0x800750B4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800750B8: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800750BC: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x800750C0: lw          $v1, -0x5498($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5498));
    // 0x800750C4: lh          $t4, 0x0($t1)
    ctx->r12 = S32(MEM_H(ctx->r9, 0X0));
    // 0x800750C8: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800750CC: lw          $t7, -0x5490($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X5490));
    // 0x800750D0: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800750D4: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x800750D8: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800750DC: andi        $t0, $t9, 0x7FF
    ctx->r8 = ctx->r25 & 0X7FF;
    // 0x800750E0: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800750E4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800750E8: addu        $t4, $a0, $t1
    ctx->r12 = ADD32(ctx->r4, ctx->r9);
    // 0x800750EC: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x800750F0: mflo        $t3
    ctx->r11 = lo;
    // 0x800750F4: sra         $t2, $t3, 14
    ctx->r10 = S32(SIGNED(ctx->r11) >> 14);
    // 0x800750F8: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x800750FC: sw          $t6, -0x5490($at)
    MEM_W(-0X5490, ctx->r1) = ctx->r14;
    // 0x80075100: lh          $t3, 0x0($t4)
    ctx->r11 = S32(MEM_H(ctx->r12, 0X0));
    // 0x80075104: lw          $t5, -0x548C($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X548C));
    // 0x80075108: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x8007510C: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80075110: mflo        $t7
    ctx->r15 = lo;
    // 0x80075114: sra         $t2, $t7, 14
    ctx->r10 = S32(SIGNED(ctx->r15) >> 14);
    // 0x80075118: addu        $t6, $t5, $t2
    ctx->r14 = ADD32(ctx->r13, ctx->r10);
    // 0x8007511C: sw          $t6, -0x548C($at)
    MEM_W(-0X548C, ctx->r1) = ctx->r14;
L_80075120:
    // 0x80075120: jal         0x800755C4
    // 0x80075124: nop

    restoreinterpolations(rdram, ctx);
        goto after_12;
    // 0x80075124: nop

    after_12:
    // 0x80075128: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8007512C:
    // 0x8007512C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075130: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80075134: jal         0x8006E994
    // 0x80075138: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    setrotatespriteflags(rdram, ctx);
        goto after_13;
    // 0x80075138: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_13:
    // 0x8007513C: jal         0x8006EC60
    // 0x80075140: nop

    coolgaugetext(rdram, ctx);
        goto after_14;
    // 0x80075140: nop

    after_14:
    // 0x80075144: jal         0x80099568
    // 0x80075148: nop

    operatefta(rdram, ctx);
        goto after_15;
    // 0x80075148: nop

    after_15:
    // 0x8007514C: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x80075150: lw          $t8, -0x540C($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X540C));
    // 0x80075154: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x80075158: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8007515C: bnel        $at, $zero, L_80075328
    if (ctx->r1 != 0) {
        // 0x80075160: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_80075328;
    }
    goto skip_5;
    // 0x80075160: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_5:
    // 0x80075164: lw          $t9, -0x545C($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X545C));
    // 0x80075168: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8007516C: bnel        $t9, $zero, L_80075328
    if (ctx->r25 != 0) {
        // 0x80075170: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_80075328;
    }
    goto skip_6;
    // 0x80075170: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_6:
    // 0x80075174: lbu         $t0, 0x378C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X378C);
    // 0x80075178: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007517C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80075180: bnel        $t0, $at, L_80075328
    if (ctx->r8 != ctx->r1) {
        // 0x80075184: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_80075328;
    }
    goto skip_7;
    // 0x80075184: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_7:
    // 0x80075188: lbu         $t1, -0x5B5C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X5B5C);
    // 0x8007518C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80075190: addiu       $s1, $s1, 0x3780
    ctx->r17 = ADD32(ctx->r17, 0X3780);
    // 0x80075194: bne         $t1, $zero, L_80075314
    if (ctx->r9 != 0) {
        // 0x80075198: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_80075314;
    }
    // 0x80075198: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8007519C: lw          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800751A0: bgez        $v0, L_800751B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800751A4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800751B0;
    }
    // 0x800751A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800751A8: b           L_800751B0
    // 0x800751AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800751B0;
    // 0x800751AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800751B0:
    // 0x800751B0: slti        $at, $s0, 0x12C
    ctx->r1 = SIGNED(ctx->r16) < 0X12C ? 1 : 0;
    // 0x800751B4: beq         $at, $zero, L_800751D8
    if (ctx->r1 == 0) {
        // 0x800751B8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800751D8;
    }
    // 0x800751B8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800751BC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800751C0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x800751C4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x800751C8: jal         0x8006E994
    // 0x800751CC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    setrotatespriteflags(rdram, ctx);
        goto after_16;
    // 0x800751CC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_16:
    // 0x800751D0: b           L_800751EC
    // 0x800751D4: lw          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X0));
        goto L_800751EC;
    // 0x800751D4: lw          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X0));
L_800751D8:
    // 0x800751D8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800751DC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800751E0: jal         0x8006E994
    // 0x800751E4: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    setrotatespriteflags(rdram, ctx);
        goto after_17;
    // 0x800751E4: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_17:
    // 0x800751E8: lw          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X0));
L_800751EC:
    // 0x800751EC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800751F0: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x800751F4: bgez        $v0, L_80075204
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800751F8: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80075204;
    }
    // 0x800751F8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800751FC: b           L_80075208
    // 0x80075200: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80075208;
    // 0x80075200: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80075204:
    // 0x80075204: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80075208:
    // 0x80075208: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x8007520C: lh          $t3, -0x9DC($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X9DC));
    // 0x80075210: mflo        $s0
    ctx->r16 = lo;
    // 0x80075214: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80075218: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8007521C: bne         $at, $zero, L_8007522C
    if (ctx->r1 != 0) {
        // 0x80075220: addiu       $a2, $a2, 0x5200
        ctx->r6 = ADD32(ctx->r6, 0X5200);
            goto L_8007522C;
    }
    // 0x80075220: addiu       $a2, $a2, 0x5200
    ctx->r6 = ADD32(ctx->r6, 0X5200);
    // 0x80075224: b           L_80075230
    // 0x80075228: addiu       $s2, $zero, 0x74
    ctx->r18 = ADD32(0, 0X74);
        goto L_80075230;
    // 0x80075228: addiu       $s2, $zero, 0x74
    ctx->r18 = ADD32(0, 0X74);
L_8007522C:
    // 0x8007522C: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
L_80075230:
    // 0x80075230: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80075234: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80075238: jal         0x80063F68
    // 0x8007523C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    gametext(rdram, ctx);
        goto after_18;
    // 0x8007523C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_18:
    // 0x80075240: addiu       $s3, $zero, 0x3C
    ctx->r19 = ADD32(0, 0X3C);
    // 0x80075244: div         $zero, $s0, $s3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r19)));
    // 0x80075248: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
    // 0x8007524C: mflo        $a2
    ctx->r6 = lo;
    // 0x80075250: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80075254: addiu       $a1, $a1, 0x5204
    ctx->r5 = ADD32(ctx->r5, 0X5204);
    // 0x80075258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007525C: bne         $s3, $zero, L_80075268
    if (ctx->r19 != 0) {
        // 0x80075260: nop
    
            goto L_80075268;
    }
    // 0x80075260: nop

    // 0x80075264: break       7
    do_break(2147963492);
L_80075268:
    // 0x80075268: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007526C: bne         $s3, $at, L_80075280
    if (ctx->r19 != ctx->r1) {
        // 0x80075270: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80075280;
    }
    // 0x80075270: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80075274: bne         $s0, $at, L_80075280
    if (ctx->r16 != ctx->r1) {
        // 0x80075278: nop
    
            goto L_80075280;
    }
    // 0x80075278: nop

    // 0x8007527C: break       6
    do_break(2147963516);
L_80075280:
    // 0x80075280: jal         0x800BD9E4
    // 0x80075284: nop

    sprintf_recomp(rdram, ctx);
        goto after_19;
    // 0x80075284: nop

    after_19:
    // 0x80075288: jal         0x80099488
    // 0x8007528C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80099488(rdram, ctx);
        goto after_20;
    // 0x8007528C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80075290: addiu       $t5, $zero, 0x9E
    ctx->r13 = ADD32(0, 0X9E);
    // 0x80075294: subu        $a0, $t5, $v0
    ctx->r4 = SUB32(ctx->r13, ctx->r2);
    // 0x80075298: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8007529C: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800752A0: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x800752A4: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800752A8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800752AC: jal         0x80063F68
    // 0x800752B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    gametext(rdram, ctx);
        goto after_21;
    // 0x800752B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_21:
    // 0x800752B4: div         $zero, $s0, $s3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r19)));
    // 0x800752B8: mfhi        $a2
    ctx->r6 = hi;
    // 0x800752BC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800752C0: addiu       $a1, $a1, 0x520C
    ctx->r5 = ADD32(ctx->r5, 0X520C);
    // 0x800752C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800752C8: bne         $s3, $zero, L_800752D4
    if (ctx->r19 != 0) {
        // 0x800752CC: nop
    
            goto L_800752D4;
    }
    // 0x800752CC: nop

    // 0x800752D0: break       7
    do_break(2147963600);
L_800752D4:
    // 0x800752D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800752D8: bne         $s3, $at, L_800752EC
    if (ctx->r19 != ctx->r1) {
        // 0x800752DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800752EC;
    }
    // 0x800752DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800752E0: bne         $s0, $at, L_800752EC
    if (ctx->r16 != ctx->r1) {
        // 0x800752E4: nop
    
            goto L_800752EC;
    }
    // 0x800752E4: nop

    // 0x800752E8: break       6
    do_break(2147963624);
L_800752EC:
    // 0x800752EC: jal         0x800BD9E4
    // 0x800752F0: nop

    sprintf_recomp(rdram, ctx);
        goto after_22;
    // 0x800752F0: nop

    after_22:
    // 0x800752F4: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800752F8: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800752FC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80075300: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    // 0x80075304: jal         0x80063F68
    // 0x80075308: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    gametext(rdram, ctx);
        goto after_23;
    // 0x80075308: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_23:
    // 0x8007530C: b           L_80075328
    // 0x80075310: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_80075328;
    // 0x80075310: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_80075314:
    // 0x80075314: lw          $t0, 0x3784($t0)
    ctx->r8 = S32(MEM_W(ctx->r8, 0X3784));
    // 0x80075318: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8007531C: addiu       $s1, $s1, 0x3780
    ctx->r17 = ADD32(ctx->r17, 0X3780);
    // 0x80075320: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x80075324: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_80075328:
    // 0x80075328: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8007532C: lw          $s0, 0x28($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80075330: lw          $s1, 0x2C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80075334: lw          $s2, 0x30($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80075338: lw          $s3, 0x34($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8007533C: lw          $s4, 0x38($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80075340: jr          $ra
    // 0x80075344: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80075344: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void furthestangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FF4: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80089FF8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80089FFC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008A000: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8008A004: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A008: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A00C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A010: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x8008A014: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8008A018: addiu       $t1, $t1, 0x6BA8
    ctx->r9 = ADD32(ctx->r9, 0X6BA8);
    // 0x8008A01C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008A020: addu        $s1, $t9, $t1
    ctx->r17 = ADD32(ctx->r25, ctx->r9);
    // 0x8008A024: lh          $t2, 0xE($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, 0XE));
    // 0x8008A028: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x8008A02C: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8008A030: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8008A034: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8008A038: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x8008A03C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8008A040: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8008A044: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8008A048: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8008A04C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8008A050: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8008A054: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8008A058: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8008A05C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8008A060: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8008A064: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x8008A068: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x8008A06C: beq         $t2, $at, L_8008A0A4
    if (ctx->r10 == ctx->r1) {
        // 0x8008A070: lui         $s4, 0xC000
        ctx->r20 = S32(0XC000 << 16);
            goto L_8008A0A4;
    }
    // 0x8008A070: lui         $s4, 0xC000
    ctx->r20 = S32(0XC000 << 16);
    // 0x8008A074: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8008A078: lw          $t3, 0x2318($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X2318));
    // 0x8008A07C: lw          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8008A080: andi        $t5, $t4, 0x3F
    ctx->r13 = ctx->r12 & 0X3F;
    // 0x8008A084: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8008A088: bnel        $at, $zero, L_8008A0A8
    if (ctx->r1 != 0) {
        // 0x8008A08C: lh          $v0, 0x14($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0X14));
            goto L_8008A0A8;
    }
    goto skip_0;
    // 0x8008A08C: lh          $v0, 0x14($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X14));
    skip_0:
    // 0x8008A090: lh          $v0, 0x14($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X14));
    // 0x8008A094: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x8008A098: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8008A09C: b           L_8008A214
    // 0x8008A0A0: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
        goto L_8008A214;
    // 0x8008A0A0: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_8008A0A4:
    // 0x8008A0A4: lh          $v0, 0x14($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X14));
L_8008A0A8:
    // 0x8008A0A8: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8008A0AC: addiu       $fp, $sp, 0xA0
    ctx->r30 = ADD32(ctx->r29, 0XA0);
    // 0x8008A0B0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8008A0B4: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8008A0B8: addiu       $t9, $v0, 0x800
    ctx->r25 = ADD32(ctx->r2, 0X800);
    // 0x8008A0BC: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008A0C0: beq         $at, $zero, L_8008A204
    if (ctx->r1 == 0) {
        // 0x8008A0C4: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_8008A204;
    }
    // 0x8008A0C4: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8008A0C8: div         $zero, $t1, $a2
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r6)));
    // 0x8008A0CC: mflo        $s5
    ctx->r21 = lo;
    // 0x8008A0D0: sll         $t2, $s5, 16
    ctx->r10 = S32(ctx->r21 << 16);
    // 0x8008A0D4: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8008A0D8: lui         $s3, 0x8010
    ctx->r19 = S32(0X8010 << 16);
    // 0x8008A0DC: addiu       $s3, $s3, -0x9A0
    ctx->r19 = ADD32(ctx->r19, -0X9A0);
    // 0x8008A0E0: or          $s5, $t3, $zero
    ctx->r21 = ctx->r11 | 0;
    // 0x8008A0E4: lw          $s2, 0x0($s1)
    ctx->r18 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8008A0E8: lw          $a1, 0x4($s1)
    ctx->r5 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8008A0EC: bne         $a2, $zero, L_8008A0F8
    if (ctx->r6 != 0) {
        // 0x8008A0F0: nop
    
            goto L_8008A0F8;
    }
    // 0x8008A0F0: nop

    // 0x8008A0F4: break       7
    do_break(2148049140);
L_8008A0F8:
    // 0x8008A0F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008A0FC: bne         $a2, $at, L_8008A110
    if (ctx->r6 != ctx->r1) {
        // 0x8008A100: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008A110;
    }
    // 0x8008A100: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008A104: bne         $t1, $at, L_8008A110
    if (ctx->r9 != ctx->r1) {
        // 0x8008A108: nop
    
            goto L_8008A110;
    }
    // 0x8008A108: nop

    // 0x8008A10C: break       6
    do_break(2148049164);
L_8008A110:
    // 0x8008A110: addiu       $s7, $sp, 0xA2
    ctx->r23 = ADD32(ctx->r29, 0XA2);
    // 0x8008A114: addiu       $s6, $sp, 0xA4
    ctx->r22 = ADD32(ctx->r29, 0XA4);
    // 0x8008A118: addiu       $t4, $s0, 0x200
    ctx->r12 = ADD32(ctx->r16, 0X200);
L_8008A11C:
    // 0x8008A11C: andi        $t5, $t4, 0x7FF
    ctx->r13 = ctx->r12 & 0X7FF;
    // 0x8008A120: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8008A124: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x8008A128: andi        $t9, $s0, 0x7FF
    ctx->r25 = ctx->r16 & 0X7FF;
    // 0x8008A12C: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x8008A130: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8008A134: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8008A138: lh          $t3, 0x0($t2)
    ctx->r11 = S32(MEM_H(ctx->r10, 0X0));
    // 0x8008A13C: lw          $a2, 0x8($s1)
    ctx->r6 = S32(MEM_W(ctx->r17, 0X8));
    // 0x8008A140: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8008A144: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8008A148: addiu       $t6, $sp, 0x90
    ctx->r14 = ADD32(ctx->r29, 0X90);
    // 0x8008A14C: addiu       $t5, $sp, 0x94
    ctx->r13 = ADD32(ctx->r29, 0X94);
    // 0x8008A150: addiu       $t4, $sp, 0x98
    ctx->r12 = ADD32(ctx->r29, 0X98);
    // 0x8008A154: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8008A158: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8008A15C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8008A160: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8008A164: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x8008A168: sw          $fp, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r30;
    // 0x8008A16C: sw          $s7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r23;
    // 0x8008A170: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    // 0x8008A174: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008A178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008A17C: lh          $a3, 0x10($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X10));
    // 0x8008A180: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008A184: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8008A188: jal         0x8009324C
    // 0x8008A18C: addiu       $a2, $a2, -0x800
    ctx->r6 = ADD32(ctx->r6, -0X800);
    hitscan(rdram, ctx);
        goto after_0;
    // 0x8008A18C: addiu       $a2, $a2, -0x800
    ctx->r6 = ADD32(ctx->r6, -0X800);
    after_0:
    // 0x8008A190: lw          $s2, 0x0($s1)
    ctx->r18 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8008A194: lw          $t8, 0x98($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X98));
    // 0x8008A198: lw          $t0, 0x84($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X84));
    // 0x8008A19C: lw          $t9, 0x94($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X94));
    // 0x8008A1A0: subu        $v0, $t8, $s2
    ctx->r2 = SUB32(ctx->r24, ctx->r18);
    // 0x8008A1A4: blez        $v0, L_8008A1B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A1A8: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_8008A1B4;
    }
    // 0x8008A1A8: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x8008A1AC: b           L_8008A1B4
    // 0x8008A1B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8008A1B4;
    // 0x8008A1B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8008A1B4:
    // 0x8008A1B4: lw          $a1, 0x4($s1)
    ctx->r5 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8008A1B8: subu        $v0, $t9, $a1
    ctx->r2 = SUB32(ctx->r25, ctx->r5);
    // 0x8008A1BC: blez        $v0, L_8008A1CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A1C0: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_8008A1CC;
    }
    // 0x8008A1C0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8008A1C4: b           L_8008A1CC
    // 0x8008A1C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8008A1CC;
    // 0x8008A1C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8008A1CC:
    // 0x8008A1CC: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x8008A1D0: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008A1D4: beql        $at, $zero, L_8008A1E8
    if (ctx->r1 == 0) {
        // 0x8008A1D8: lh          $t3, 0x14($t0)
        ctx->r11 = S32(MEM_H(ctx->r8, 0X14));
            goto L_8008A1E8;
    }
    goto skip_1;
    // 0x8008A1D8: lh          $t3, 0x14($t0)
    ctx->r11 = S32(MEM_H(ctx->r8, 0X14));
    skip_1:
    // 0x8008A1DC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8008A1E0: sh          $s0, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r16;
    // 0x8008A1E4: lh          $t3, 0x14($t0)
    ctx->r11 = S32(MEM_H(ctx->r8, 0X14));
L_8008A1E8:
    // 0x8008A1E8: addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    // 0x8008A1EC: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x8008A1F0: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8008A1F4: addiu       $t4, $t3, 0x800
    ctx->r12 = ADD32(ctx->r11, 0X800);
    // 0x8008A1F8: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008A1FC: bnel        $at, $zero, L_8008A11C
    if (ctx->r1 != 0) {
        // 0x8008A200: addiu       $t4, $s0, 0x200
        ctx->r12 = ADD32(ctx->r16, 0X200);
            goto L_8008A11C;
    }
    goto skip_2;
    // 0x8008A200: addiu       $t4, $s0, 0x200
    ctx->r12 = ADD32(ctx->r16, 0X200);
    skip_2:
L_8008A204:
    // 0x8008A204: lh          $v0, 0x9E($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x8008A208: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x8008A20C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8008A210: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_8008A214:
    // 0x8008A214: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x8008A218: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8008A21C: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8008A220: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8008A224: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8008A228: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x8008A22C: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8008A230: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x8008A234: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x8008A238: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x8008A23C: jr          $ra
    // 0x8008A240: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8008A240: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void lotsofmail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800763F4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800763F8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800763FC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80076400: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80076404: sll         $s1, $t7, 16
    ctx->r17 = S32(ctx->r15 << 16);
    // 0x80076408: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8007640C: sra         $t8, $s1, 16
    ctx->r24 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80076410: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80076414: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80076418: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x8007641C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80076420: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80076424: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80076428: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007642C: blez        $t7, L_80076508
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80076430: or          $s1, $t8, $zero
        ctx->r17 = ctx->r24 | 0;
            goto L_80076508;
    }
    // 0x80076430: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80076434: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x80076438: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x8007643C: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x80076440: addiu       $s3, $zero, 0x2F00
    ctx->r19 = ADD32(0, 0X2F00);
L_80076444:
    // 0x80076444: jal         0x8009800C
    // 0x80076448: nop

    krand2(rdram, ctx);
        goto after_0;
    // 0x80076448: nop

    after_0:
    // 0x8007644C: jal         0x8009800C
    // 0x80076450: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_1;
    // 0x80076450: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_1:
    // 0x80076454: div         $zero, $s2, $s3
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r19)));
    // 0x80076458: lw          $t9, 0x8($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8007645C: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    // 0x80076460: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80076464: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    // 0x80076468: bne         $s3, $zero, L_80076474
    if (ctx->r19 != 0) {
        // 0x8007646C: nop
    
            goto L_80076474;
    }
    // 0x8007646C: nop

    // 0x80076470: break       7
    do_break(2147968112);
L_80076474:
    // 0x80076474: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076478: bne         $s3, $at, L_8007648C
    if (ctx->r19 != ctx->r1) {
        // 0x8007647C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007648C;
    }
    // 0x8007647C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076480: bne         $s2, $at, L_8007648C
    if (ctx->r18 != ctx->r1) {
        // 0x80076484: nop
    
            goto L_8007648C;
    }
    // 0x80076484: nop

    // 0x80076488: break       6
    do_break(2147968136);
L_8007648C:
    // 0x8007648C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80076490: addiu       $t1, $zero, 0x113A
    ctx->r9 = ADD32(0, 0X113A);
    // 0x80076494: addiu       $t2, $zero, -0x20
    ctx->r10 = ADD32(0, -0X20);
    // 0x80076498: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8007649C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800764A0: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x800764A4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800764A8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800764AC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800764B0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800764B4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800764B8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800764BC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800764C0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800764C4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800764C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800764CC: jal         0x8009B028
    // 0x800764D0: subu        $a3, $t9, $t0
    ctx->r7 = SUB32(ctx->r25, ctx->r8);
    EGS(rdram, ctx);
        goto after_2;
    // 0x800764D0: subu        $a3, $t9, $t0
    ctx->r7 = SUB32(ctx->r25, ctx->r8);
    after_2:
    // 0x800764D4: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800764D8: sra         $t7, $s2, 16
    ctx->r15 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800764DC: jal         0x8009800C
    // 0x800764E0: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    krand2(rdram, ctx);
        goto after_3;
    // 0x800764E0: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    after_3:
    // 0x800764E4: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800764E8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800764EC: sll         $t1, $s1, 16
    ctx->r9 = S32(ctx->r17 << 16);
    // 0x800764F0: sra         $s1, $t1, 16
    ctx->r17 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800764F4: andi        $t8, $v0, 0xC
    ctx->r24 = ctx->r2 & 0XC;
    // 0x800764F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800764FC: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x80076500: bgtz        $s1, L_80076444
    if (SIGNED(ctx->r17) > 0) {
        // 0x80076504: sh          $t8, 0xC($t0)
        MEM_H(0XC, ctx->r8) = ctx->r24;
            goto L_80076444;
    }
    // 0x80076504: sh          $t8, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r24;
L_80076508:
    // 0x80076508: lw          $ra, 0x54($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8007650C: lw          $s0, 0x3C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80076510: lw          $s1, 0x40($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80076514: lw          $s2, 0x44($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80076518: lw          $s3, 0x48($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8007651C: lw          $s4, 0x4C($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80076520: lw          $s5, 0x50($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80076524: jr          $ra
    // 0x80076528: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80076528: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80059390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059390: jr          $ra
    // 0x80059394: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80059394: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void callsound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC900: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800AC904: addiu       $v1, $v1, -0x9B0
    ctx->r3 = ADD32(ctx->r3, -0X9B0);
    // 0x800AC908: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800AC90C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AC910: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800AC914: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AC918: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AC91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC920: beq         $t8, $zero, L_800AC934
    if (ctx->r24 == 0) {
        // 0x800AC924: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800AC934;
    }
    // 0x800AC924: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800AC928: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800AC92C: b           L_800ACB00
    // 0x800AC930: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ACB00;
    // 0x800AC930: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AC934:
    // 0x800AC934: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800AC938: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800AC93C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800AC940: lh          $v0, 0x2330($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X2330));
    // 0x800AC944: bltz        $v0, L_800ACAFC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AC948: lui         $t0, 0x8027
        ctx->r8 = S32(0X8027 << 16);
            goto L_800ACAFC;
    }
    // 0x800AC948: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x800AC94C: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x800AC950: addiu       $a1, $a1, 0x6BA8
    ctx->r5 = ADD32(ctx->r5, 0X6BA8);
    // 0x800AC954: addiu       $t0, $t0, 0x4FA0
    ctx->r8 = ADD32(ctx->r8, 0X4FA0);
    // 0x800AC958: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x800AC95C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800AC960:
    // 0x800AC960: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC964: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x800AC968: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800AC96C: mflo        $t1
    ctx->r9 = lo;
    // 0x800AC970: addu        $v1, $a1, $t1
    ctx->r3 = ADD32(ctx->r5, ctx->r9);
    // 0x800AC974: lh          $t2, 0xE($v1)
    ctx->r10 = S32(MEM_H(ctx->r3, 0XE));
    // 0x800AC978: bnel        $a0, $t2, L_800ACAF4
    if (ctx->r4 != ctx->r10) {
        // 0x800AC97C: lh          $v0, 0x0($t5)
        ctx->r2 = S32(MEM_H(ctx->r13, 0X0));
            goto L_800ACAF4;
    }
    goto skip_0;
    // 0x800AC97C: lh          $v0, 0x0($t5)
    ctx->r2 = S32(MEM_H(ctx->r13, 0X0));
    skip_0:
    // 0x800AC980: lh          $a2, 0x1E($v1)
    ctx->r6 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800AC984: slti        $at, $a2, 0x3E8
    ctx->r1 = SIGNED(ctx->r6) < 0X3E8 ? 1 : 0;
    // 0x800AC988: beql        $at, $zero, L_800ACAF4
    if (ctx->r1 == 0) {
        // 0x800AC98C: lh          $v0, 0x0($t5)
        ctx->r2 = S32(MEM_H(ctx->r13, 0X0));
            goto L_800ACAF4;
    }
    goto skip_1;
    // 0x800AC98C: lh          $v0, 0x0($t5)
    ctx->r2 = S32(MEM_H(ctx->r13, 0X0));
    skip_1:
    // 0x800AC990: lh          $t3, 0x2E($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X2E));
    // 0x800AC994: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AC998: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x800AC99C: bne         $t3, $at, L_800AC9A8
    if (ctx->r11 != ctx->r1) {
        // 0x800AC9A0: addu        $t4, $t4, $v0
        ctx->r12 = ADD32(ctx->r12, ctx->r2);
            goto L_800AC9A8;
    }
    // 0x800AC9A0: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x800AC9A4: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
L_800AC9A8:
    // 0x800AC9A8: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x800AC9AC: addiu       $t5, $t5, -0x5C00
    ctx->r13 = ADD32(ctx->r13, -0X5C00);
    // 0x800AC9B0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800AC9B4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AC9B8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800AC9BC: lw          $t7, 0x30($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X30));
    // 0x800AC9C0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800AC9C4: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x800AC9C8: bnel        $t7, $zero, L_800ACA74
    if (ctx->r15 != 0) {
        // 0x800AC9CC: lh          $a3, 0x20($v1)
        ctx->r7 = S32(MEM_H(ctx->r3, 0X20));
            goto L_800ACA74;
    }
    goto skip_2;
    // 0x800AC9CC: lh          $a3, 0x20($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X20));
    skip_2:
    // 0x800AC9D0: lbu         $t8, -0xB68($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0XB68);
    // 0x800AC9D4: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x800AC9D8: bne         $t9, $zero, L_800ACAE8
    if (ctx->r25 != 0) {
        // 0x800AC9DC: nop
    
            goto L_800ACAE8;
    }
    // 0x800AC9DC: nop

    // 0x800AC9E0: beq         $a2, $zero, L_800ACA30
    if (ctx->r6 == 0) {
        // 0x800AC9E4: andi        $a0, $a2, 0xFFFF
        ctx->r4 = ctx->r6 & 0XFFFF;
            goto L_800ACA30;
    }
    // 0x800AC9E4: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x800AC9E8: lh          $a1, 0x2E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X2E));
    // 0x800AC9EC: jal         0x80059034
    // 0x800AC9F0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    spritesound(rdram, ctx);
        goto after_0;
    // 0x800AC9F0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x800AC9F4: lw          $v1, 0x20($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800AC9F8: lh          $a3, 0x20($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X20));
    // 0x800AC9FC: beql        $a3, $zero, L_800ACA34
    if (ctx->r7 == 0) {
        // 0x800ACA00: lh          $t3, 0x10($v1)
        ctx->r11 = S32(MEM_H(ctx->r3, 0X10));
            goto L_800ACA34;
    }
    goto skip_3;
    // 0x800ACA00: lh          $t3, 0x10($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0X10));
    skip_3:
    // 0x800ACA04: lh          $t1, 0x1E($v1)
    ctx->r9 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800ACA08: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
    // 0x800ACA0C: beql        $t1, $a3, L_800ACA34
    if (ctx->r9 == ctx->r7) {
        // 0x800ACA10: lh          $t3, 0x10($v1)
        ctx->r11 = S32(MEM_H(ctx->r3, 0X10));
            goto L_800ACA34;
    }
    goto skip_4;
    // 0x800ACA10: lh          $t3, 0x10($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0X10));
    skip_4:
    // 0x800ACA14: beq         $at, $zero, L_800ACA30
    if (ctx->r1 == 0) {
        // 0x800ACA18: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_800ACA30;
    }
    // 0x800ACA18: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x800ACA1C: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ACA20: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800ACA24: jal         0x80059218
    // 0x800ACA28: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    stopsound(rdram, ctx);
        goto after_1;
    // 0x800ACA28: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x800ACA2C: lw          $v1, 0x20($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X20));
L_800ACA30:
    // 0x800ACA30: lh          $t3, 0x10($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0X10));
L_800ACA34:
    // 0x800ACA34: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800ACA38: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x800ACA3C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800ACA40: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800ACA44: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800ACA48: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800ACA4C: lh          $t5, -0x1970($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X1970));
    // 0x800ACA50: lh          $a2, 0x1E($v1)
    ctx->r6 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800ACA54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ACA58: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800ACA5C: beq         $t6, $at, L_800ACAE8
    if (ctx->r14 == ctx->r1) {
        // 0x800ACA60: lw          $t8, 0x18($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X18));
            goto L_800ACAE8;
    }
    // 0x800ACA60: lw          $t8, 0x18($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800ACA64: sw          $t7, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r15;
    // 0x800ACA68: b           L_800ACB00
    // 0x800ACA6C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800ACB00;
    // 0x800ACA6C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800ACA70: lh          $a3, 0x20($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X20));
L_800ACA74:
    // 0x800ACA74: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
    // 0x800ACA78: beq         $at, $zero, L_800ACAE8
    if (ctx->r1 == 0) {
        // 0x800ACA7C: nop
    
            goto L_800ACAE8;
    }
    // 0x800ACA7C: nop

    // 0x800ACA80: beq         $a3, $zero, L_800ACA9C
    if (ctx->r7 == 0) {
        // 0x800ACA84: andi        $a0, $a3, 0xFFFF
        ctx->r4 = ctx->r7 & 0XFFFF;
            goto L_800ACA9C;
    }
    // 0x800ACA84: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x800ACA88: lh          $a1, 0x2E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X2E));
    // 0x800ACA8C: jal         0x80059034
    // 0x800ACA90: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    spritesound(rdram, ctx);
        goto after_2;
    // 0x800ACA90: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x800ACA94: lw          $v1, 0x20($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800ACA98: lh          $a2, 0x1E($v1)
    ctx->r6 = S32(MEM_H(ctx->r3, 0X1E));
L_800ACA9C:
    // 0x800ACA9C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800ACAA0: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x800ACAA4: lbu         $t9, -0xB68($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0XB68);
    // 0x800ACAA8: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x800ACAAC: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ACAB0: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x800ACAB4: bne         $t1, $zero, L_800ACAD0
    if (ctx->r9 != 0) {
        // 0x800ACAB8: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_800ACAD0;
    }
    // 0x800ACAB8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800ACABC: lh          $a3, 0x20($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X20));
    // 0x800ACAC0: beql        $a3, $zero, L_800ACAE4
    if (ctx->r7 == 0) {
        // 0x800ACAC4: lw          $t3, 0x18($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X18));
            goto L_800ACAE4;
    }
    goto skip_5;
    // 0x800ACAC4: lw          $t3, 0x18($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X18));
    skip_5:
    // 0x800ACAC8: beql        $a3, $a2, L_800ACAE4
    if (ctx->r7 == ctx->r6) {
        // 0x800ACACC: lw          $t3, 0x18($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X18));
            goto L_800ACAE4;
    }
    goto skip_6;
    // 0x800ACACC: lw          $t3, 0x18($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X18));
    skip_6:
L_800ACAD0:
    // 0x800ACAD0: jal         0x80059218
    // 0x800ACAD4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    stopsound(rdram, ctx);
        goto after_3;
    // 0x800ACAD4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x800ACAD8: lw          $v1, 0x20($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800ACADC: lh          $a2, 0x1E($v1)
    ctx->r6 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800ACAE0: lw          $t3, 0x18($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X18));
L_800ACAE4:
    // 0x800ACAE4: sw          $zero, 0x30($t3)
    MEM_W(0X30, ctx->r11) = 0;
L_800ACAE8:
    // 0x800ACAE8: b           L_800ACB00
    // 0x800ACAEC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_800ACB00;
    // 0x800ACAEC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800ACAF0: lh          $v0, 0x0($t5)
    ctx->r2 = S32(MEM_H(ctx->r13, 0X0));
L_800ACAF4:
    // 0x800ACAF4: bgez        $v0, L_800AC960
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800ACAF8: nop
    
            goto L_800AC960;
    }
    // 0x800ACAF8: nop

L_800ACAFC:
    // 0x800ACAFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800ACB00:
    // 0x800ACB00: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800ACB04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800ACB08: jr          $ra
    // 0x800ACB0C: nop

    return;
    // 0x800ACB0C: nop

;}
RECOMP_FUNC void agecache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071EEC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80071EF0: lw          $v1, -0x1810($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X1810));
    // 0x80071EF4: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x80071EF8: addiu       $a1, $a1, -0x1020
    ctx->r5 = ADD32(ctx->r5, -0X1020);
    // 0x80071EFC: blez        $v1, L_80071F3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071F00: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80071F3C;
    }
    // 0x80071F00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80071F04:
    // 0x80071F04: lw          $a2, 0x8($a1)
    ctx->r6 = S32(MEM_W(ctx->r5, 0X8));
    // 0x80071F08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80071F0C: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80071F10: addiu       $t6, $a0, -0x2
    ctx->r14 = ADD32(ctx->r4, -0X2);
    // 0x80071F14: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80071F18: slti        $at, $t7, 0xC6
    ctx->r1 = SIGNED(ctx->r15) < 0XC6 ? 1 : 0;
    // 0x80071F1C: beq         $at, $zero, L_80071F30
    if (ctx->r1 == 0) {
        // 0x80071F20: addiu       $t8, $a0, -0x1
        ctx->r24 = ADD32(ctx->r4, -0X1);
            goto L_80071F30;
    }
    // 0x80071F20: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x80071F24: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x80071F28: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80071F2C: lw          $v1, -0x1810($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X1810));
L_80071F30:
    // 0x80071F30: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80071F34: bne         $at, $zero, L_80071F04
    if (ctx->r1 != 0) {
        // 0x80071F38: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_80071F04;
    }
    // 0x80071F38: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_80071F3C:
    // 0x80071F3C: jr          $ra
    // 0x80071F40: nop

    return;
    // 0x80071F40: nop

;}
RECOMP_FUNC void execute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F488: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8008F48C: sh          $a0, 0x2310($at)
    MEM_H(0X2310, ctx->r1) = ctx->r4;
    // 0x8008F490: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x8008F494: lh          $a3, 0x2310($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, 0X2310));
    // 0x8008F498: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8008F49C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008F4A0: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x8008F4A4: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x8008F4A8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008F4AC: sll         $t5, $a3, 3
    ctx->r13 = S32(ctx->r7 << 3);
    // 0x8008F4B0: sh          $a1, 0x2312($at)
    MEM_H(0X2312, ctx->r1) = ctx->r5;
    // 0x8008F4B4: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x8008F4B8: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x8008F4BC: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x8008F4C0: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8008F4C4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008F4C8: addiu       $t3, $t3, 0x6BA8
    ctx->r11 = ADD32(ctx->r11, 0X6BA8);
    // 0x8008F4CC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8008F4D0: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x8008F4D4: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8008F4D8: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x8008F4DC: sw          $a2, 0x2314($at)
    MEM_W(0X2314, ctx->r1) = ctx->r6;
    // 0x8008F4E0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8008F4E4: addiu       $t7, $t7, -0x5C00
    ctx->r15 = ADD32(ctx->r15, -0X5C00);
    // 0x8008F4E8: addiu       $t6, $t5, 0x30
    ctx->r14 = ADD32(ctx->r13, 0X30);
    // 0x8008F4EC: addiu       $t1, $t1, 0x231C
    ctx->r9 = ADD32(ctx->r9, 0X231C);
    // 0x8008F4F0: addiu       $t0, $t0, 0x2318
    ctx->r8 = ADD32(ctx->r8, 0X2318);
    // 0x8008F4F4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008F4F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F4FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008F500: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008F504: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8008F508: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8008F50C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8008F510: lh          $t3, 0xE($t4)
    ctx->r11 = S32(MEM_H(ctx->r12, 0XE));
    // 0x8008F514: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8008F518: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8008F51C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8008F520: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x8008F524: lh          $v0, -0x447C($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X447C));
    // 0x8008F528: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008F52C: addiu       $a0, $a0, 0x2320
    ctx->r4 = ADD32(ctx->r4, 0X2320);
    // 0x8008F530: beq         $v0, $zero, L_8008F904
    if (ctx->r2 == 0) {
        // 0x8008F534: addiu       $a1, $a1, -0x1700
        ctx->r5 = ADD32(ctx->r5, -0X1700);
            goto L_8008F904;
    }
    // 0x8008F534: addiu       $a1, $a1, -0x1700
    ctx->r5 = ADD32(ctx->r5, -0X1700);
    // 0x8008F538: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8008F53C: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8008F540: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x8008F544: sltu        $at, $t7, $a1
    ctx->r1 = ctx->r15 < ctx->r5 ? 1 : 0;
    // 0x8008F548: bne         $at, $zero, L_8008F560
    if (ctx->r1 != 0) {
        // 0x8008F54C: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8008F560;
    }
    // 0x8008F54C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8008F550: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8008F554: addiu       $t8, $t8, -0x4480
    ctx->r24 = ADD32(ctx->r24, -0X4480);
    // 0x8008F558: sltu        $at, $t8, $t7
    ctx->r1 = ctx->r24 < ctx->r15 ? 1 : 0;
    // 0x8008F55C: beq         $at, $zero, L_8008F588
    if (ctx->r1 == 0) {
        // 0x8008F560: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_8008F588;
    }
L_8008F560:
    // 0x8008F560: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8008F564: jal         0x80099460
    // 0x8008F568: addiu       $a0, $a0, 0x5B44
    ctx->r4 = ADD32(ctx->r4, 0X5B44);
    gameexit(rdram, ctx);
        goto after_0;
    // 0x8008F568: addiu       $a0, $a0, 0x5B44
    ctx->r4 = ADD32(ctx->r4, 0X5B44);
    after_0:
    // 0x8008F56C: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008F570: lw          $a0, 0x231C($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X231C));
    // 0x8008F574: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8008F578: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x8008F57C: addiu       $t1, $t1, 0x231C
    ctx->r9 = ADD32(ctx->r9, 0X231C);
    // 0x8008F580: addiu       $t0, $t0, 0x2318
    ctx->r8 = ADD32(ctx->r8, 0X2318);
    // 0x8008F584: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_8008F588:
    // 0x8008F588: lw          $t9, 0x18($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8008F58C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x8008F590: sb          $zero, -0x53C4($at)
    MEM_B(-0X53C4, ctx->r1) = 0;
    // 0x8008F594: lh          $v0, 0x10($t9)
    ctx->r2 = S32(MEM_H(ctx->r25, 0X10));
    // 0x8008F598: bltz        $v0, L_8008F5A8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008F59C: slti        $at, $v0, 0x291
        ctx->r1 = SIGNED(ctx->r2) < 0X291 ? 1 : 0;
            goto L_8008F5A8;
    }
    // 0x8008F59C: slti        $at, $v0, 0x291
    ctx->r1 = SIGNED(ctx->r2) < 0X291 ? 1 : 0;
    // 0x8008F5A0: bnel        $at, $zero, L_8008F608
    if (ctx->r1 != 0) {
        // 0x8008F5A4: lw          $t7, 0x0($t0)
        ctx->r15 = S32(MEM_W(ctx->r8, 0X0));
            goto L_8008F608;
    }
    goto skip_0;
    // 0x8008F5A4: lw          $t7, 0x0($t0)
    ctx->r15 = S32(MEM_W(ctx->r8, 0X0));
    skip_0:
L_8008F5A8:
    // 0x8008F5A8: jal         0x80099ED4
    // 0x8008F5AC: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    badguy(rdram, ctx);
        goto after_1;
    // 0x8008F5AC: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    after_1:
    // 0x8008F5B0: beq         $v0, $zero, L_8008F5F4
    if (ctx->r2 == 0) {
        // 0x8008F5B4: lui         $a0, 0x8027
        ctx->r4 = S32(0X8027 << 16);
            goto L_8008F5F4;
    }
    // 0x8008F5B4: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008F5B8: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8008F5BC: lh          $t2, 0x2312($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X2312));
    // 0x8008F5C0: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x8008F5C4: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x8008F5C8: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8008F5CC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8008F5D0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008F5D4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8008F5D8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008F5DC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8008F5E0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008F5E4: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8008F5E8: lbu         $t5, 0x36B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X36B);
    // 0x8008F5EC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008F5F0: sb          $t6, 0x36B($v0)
    MEM_B(0X36B, ctx->r2) = ctx->r14;
L_8008F5F4:
    // 0x8008F5F4: jal         0x80092728
    // 0x8008F5F8: lh          $a0, 0x2310($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2310));
    deletesprite(rdram, ctx);
        goto after_2;
    // 0x8008F5F8: lh          $a0, 0x2310($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2310));
    after_2:
    // 0x8008F5FC: b           L_8008F908
    // 0x8008F600: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8008F908;
    // 0x8008F600: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008F604: lw          $t7, 0x0($t0)
    ctx->r15 = S32(MEM_W(ctx->r8, 0X0));
L_8008F608:
    // 0x8008F608: lw          $t9, 0x18($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8008F60C: lw          $t8, 0x10($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X10));
    // 0x8008F610: beq         $t8, $zero, L_8008F6C0
    if (ctx->r24 == 0) {
        // 0x8008F614: nop
    
            goto L_8008F6C0;
    }
    // 0x8008F614: nop

    // 0x8008F618: lh          $t2, 0x1E($t9)
    ctx->r10 = S32(MEM_H(ctx->r25, 0X1E));
    // 0x8008F61C: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8008F620: sh          $t3, 0x1E($t9)
    MEM_H(0X1E, ctx->r25) = ctx->r11;
    // 0x8008F624: lw          $v1, 0x0($t0)
    ctx->r3 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008F628: lw          $t5, 0x0($t1)
    ctx->r13 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8008F62C: lw          $a1, 0x10($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X10));
    // 0x8008F630: lh          $t6, 0x1E($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X1E));
    // 0x8008F634: lw          $t4, 0x10($a1)
    ctx->r12 = S32(MEM_W(ctx->r5, 0X10));
    // 0x8008F638: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008F63C: beql        $at, $zero, L_8008F67C
    if (ctx->r1 == 0) {
        // 0x8008F640: lw          $v0, 0xC($v1)
        ctx->r2 = S32(MEM_W(ctx->r3, 0XC));
            goto L_8008F67C;
    }
    goto skip_1;
    // 0x8008F640: lw          $v0, 0xC($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0XC));
    skip_1:
    // 0x8008F644: lw          $t7, 0x8($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X8));
    // 0x8008F648: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008F64C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8008F650: lw          $t2, 0x0($t1)
    ctx->r10 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8008F654: sh          $zero, 0x1E($t2)
    MEM_H(0X1E, ctx->r10) = 0;
    // 0x8008F658: lw          $v1, 0x0($t0)
    ctx->r3 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008F65C: lw          $t9, 0x10($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X10));
    // 0x8008F660: lw          $t3, 0xC($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0XC));
    // 0x8008F664: lw          $t5, 0xC($t9)
    ctx->r13 = S32(MEM_W(ctx->r25, 0XC));
    // 0x8008F668: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x8008F66C: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x8008F670: lw          $v1, 0x0($t0)
    ctx->r3 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008F674: lw          $a1, 0x10($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X10));
    // 0x8008F678: lw          $v0, 0xC($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0XC));
L_8008F67C:
    // 0x8008F67C: blez        $v0, L_8008F68C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008F680: negu        $a2, $v0
        ctx->r6 = SUB32(0, ctx->r2);
            goto L_8008F68C;
    }
    // 0x8008F680: negu        $a2, $v0
    ctx->r6 = SUB32(0, ctx->r2);
    // 0x8008F684: b           L_8008F68C
    // 0x8008F688: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8008F68C;
    // 0x8008F688: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8008F68C:
    // 0x8008F68C: lw          $t6, 0xC($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0XC));
    // 0x8008F690: lw          $t7, 0x4($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X4));
    // 0x8008F694: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008F698: mflo        $a0
    ctx->r4 = lo;
    // 0x8008F69C: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // 0x8008F6A0: blez        $a0, L_8008F6B0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8008F6A4: nop
    
            goto L_8008F6B0;
    }
    // 0x8008F6A4: nop

    // 0x8008F6A8: b           L_8008F6B0
    // 0x8008F6AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8008F6B0;
    // 0x8008F6AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8008F6B0:
    // 0x8008F6B0: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008F6B4: bne         $at, $zero, L_8008F6C0
    if (ctx->r1 != 0) {
        // 0x8008F6B8: nop
    
            goto L_8008F6C0;
    }
    // 0x8008F6B8: nop

    // 0x8008F6BC: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
L_8008F6C0:
    // 0x8008F6C0: jal         0x8008B794
    // 0x8008F6C4: nop

    parse(rdram, ctx);
        goto after_3;
    // 0x8008F6C4: nop

    after_3:
    // 0x8008F6C8: beq         $v0, $zero, L_8008F6C0
    if (ctx->r2 == 0) {
        // 0x8008F6CC: nop
    
            goto L_8008F6C0;
    }
    // 0x8008F6CC: nop

    // 0x8008F6D0: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x8008F6D4: lbu         $t8, -0x53C4($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X53C4);
    // 0x8008F6D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008F6DC: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x8008F6E0: bne         $a1, $t8, L_8008F740
    if (ctx->r5 != ctx->r24) {
        // 0x8008F6E4: lui         $t2, 0x8027
        ctx->r10 = S32(0X8027 << 16);
            goto L_8008F740;
    }
    // 0x8008F6E4: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8008F6E8: lh          $t2, 0x2312($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X2312));
    // 0x8008F6EC: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x8008F6F0: addiu       $t3, $t3, 0x5770
    ctx->r11 = ADD32(ctx->r11, 0X5770);
    // 0x8008F6F4: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x8008F6F8: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x8008F6FC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8008F700: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8008F704: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008F708: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x8008F70C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008F710: lh          $a3, 0x2310($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, 0X2310));
    // 0x8008F714: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x8008F718: lh          $t5, 0x2EE($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X2EE));
    // 0x8008F71C: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8008F720: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8008F724: bne         $a3, $t5, L_8008F730
    if (ctx->r7 != ctx->r13) {
        // 0x8008F728: sra         $t6, $a0, 16
        ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8008F730;
    }
    // 0x8008F728: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008F72C: sh          $t4, 0x2EE($v0)
    MEM_H(0X2EE, ctx->r2) = ctx->r12;
L_8008F730:
    // 0x8008F730: jal         0x80092728
    // 0x8008F734: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    deletesprite(rdram, ctx);
        goto after_4;
    // 0x8008F734: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_4:
    // 0x8008F738: b           L_8008F908
    // 0x8008F73C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8008F908;
    // 0x8008F73C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8008F740:
    // 0x8008F740: jal         0x8008A9A0
    // 0x8008F744: nop

    move(rdram, ctx);
        goto after_5;
    // 0x8008F744: nop

    after_5:
    // 0x8008F748: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008F74C: lw          $a0, 0x231C($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X231C));
    // 0x8008F750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008F754: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8008F758: lh          $v0, 0x12($a0)
    ctx->r2 = S32(MEM_H(ctx->r4, 0X12));
    // 0x8008F75C: bne         $a1, $v0, L_8008F82C
    if (ctx->r5 != ctx->r2) {
        // 0x8008F760: nop
    
            goto L_8008F82C;
    }
    // 0x8008F760: nop

    // 0x8008F764: jal         0x80099ED4
    // 0x8008F768: nop

    badguy(rdram, ctx);
        goto after_6;
    // 0x8008F768: nop

    after_6:
    // 0x8008F76C: beq         $v0, $zero, L_8008F7B0
    if (ctx->r2 == 0) {
        // 0x8008F770: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8008F7B0;
    }
    // 0x8008F770: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008F774: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008F778: lw          $a0, 0x231C($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X231C));
    // 0x8008F77C: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x8008F780: lbu         $t7, 0x27($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X27);
    // 0x8008F784: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x8008F788: beql        $at, $zero, L_8008F908
    if (ctx->r1 == 0) {
        // 0x8008F78C: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8008F908;
    }
    goto skip_2;
    // 0x8008F78C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_2:
    // 0x8008F790: lw          $t8, -0x5450($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X5450));
    // 0x8008F794: bne         $a1, $t8, L_8008F7D4
    if (ctx->r5 != ctx->r24) {
        // 0x8008F798: nop
    
            goto L_8008F7D4;
    }
    // 0x8008F798: nop

    // 0x8008F79C: lh          $t2, 0x22($a0)
    ctx->r10 = S32(MEM_H(ctx->r4, 0X22));
    // 0x8008F7A0: bgtz        $t2, L_8008F7D4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8008F7A4: nop
    
            goto L_8008F7D4;
    }
    // 0x8008F7A4: nop

    // 0x8008F7A8: b           L_8008F908
    // 0x8008F7AC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8008F908;
    // 0x8008F7AC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8008F7B0:
    // 0x8008F7B0: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x8008F7B4: lw          $t9, -0x544C($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X544C));
    // 0x8008F7B8: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8008F7BC: bne         $a1, $t9, L_8008F7D4
    if (ctx->r5 != ctx->r25) {
        // 0x8008F7C0: nop
    
            goto L_8008F7D4;
    }
    // 0x8008F7C0: nop

    // 0x8008F7C4: lw          $t3, 0x231C($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X231C));
    // 0x8008F7C8: lh          $t5, 0xC($t3)
    ctx->r13 = S32(MEM_H(ctx->r11, 0XC));
    // 0x8008F7CC: andi        $t4, $t5, 0x8000
    ctx->r12 = ctx->r13 & 0X8000;
    // 0x8008F7D0: bne         $t4, $zero, L_8008F904
    if (ctx->r12 != 0) {
        // 0x8008F7D4: lui         $a3, 0x8027
        ctx->r7 = S32(0X8027 << 16);
            goto L_8008F904;
    }
L_8008F7D4:
    // 0x8008F7D4: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x8008F7D8: lh          $a3, 0x2310($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, 0X2310));
    // 0x8008F7DC: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x8008F7E0: addiu       $t7, $t7, -0x5C00
    ctx->r15 = ADD32(ctx->r15, -0X5C00);
    // 0x8008F7E4: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x8008F7E8: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x8008F7EC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8008F7F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8008F7F4: lh          $v1, 0x12($v0)
    ctx->r3 = S32(MEM_H(ctx->r2, 0X12));
    // 0x8008F7F8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008F7FC: bne         $at, $zero, L_8008F80C
    if (ctx->r1 != 0) {
        // 0x8008F800: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_8008F80C;
    }
    // 0x8008F800: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x8008F804: b           L_8008F904
    // 0x8008F808: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
        goto L_8008F904;
    // 0x8008F808: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
L_8008F80C:
    // 0x8008F80C: bne         $a1, $v1, L_8008F904
    if (ctx->r5 != ctx->r3) {
        // 0x8008F810: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_8008F904;
    }
    // 0x8008F810: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8008F814: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008F818: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8008F81C: jal         0x800929F0
    // 0x8008F820: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    changespritestat(rdram, ctx);
        goto after_7;
    // 0x8008F820: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8008F824: b           L_8008F908
    // 0x8008F828: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8008F908;
    // 0x8008F828: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8008F82C:
    // 0x8008F82C: bnel        $v0, $at, L_8008F908
    if (ctx->r2 != ctx->r1) {
        // 0x8008F830: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8008F908;
    }
    goto skip_3;
    // 0x8008F830: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_3:
    // 0x8008F834: lh          $v0, 0xE($a0)
    ctx->r2 = S32(MEM_H(ctx->r4, 0XE));
    // 0x8008F838: slti        $at, $v0, 0x403
    ctx->r1 = SIGNED(ctx->r2) < 0X403 ? 1 : 0;
    // 0x8008F83C: bne         $at, $zero, L_8008F89C
    if (ctx->r1 != 0) {
        // 0x8008F840: slti        $at, $v0, 0x4D9
        ctx->r1 = SIGNED(ctx->r2) < 0X4D9 ? 1 : 0;
            goto L_8008F89C;
    }
    // 0x8008F840: slti        $at, $v0, 0x4D9
    ctx->r1 = SIGNED(ctx->r2) < 0X4D9 ? 1 : 0;
    // 0x8008F844: bne         $at, $zero, L_8008F85C
    if (ctx->r1 != 0) {
        // 0x8008F848: addiu       $at, $zero, 0xA06
        ctx->r1 = ADD32(0, 0XA06);
            goto L_8008F85C;
    }
    // 0x8008F848: addiu       $at, $zero, 0xA06
    ctx->r1 = ADD32(0, 0XA06);
    // 0x8008F84C: beq         $v0, $at, L_8008F8B4
    if (ctx->r2 == ctx->r1) {
        // 0x8008F850: nop
    
            goto L_8008F8B4;
    }
    // 0x8008F850: nop

    // 0x8008F854: b           L_8008F908
    // 0x8008F858: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8008F908;
    // 0x8008F858: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8008F85C:
    // 0x8008F85C: slti        $at, $v0, 0x427
    ctx->r1 = SIGNED(ctx->r2) < 0X427 ? 1 : 0;
    // 0x8008F860: bne         $at, $zero, L_8008F888
    if (ctx->r1 != 0) {
        // 0x8008F864: addiu       $t9, $v0, -0x4CB
        ctx->r25 = ADD32(ctx->r2, -0X4CB);
            goto L_8008F888;
    }
    // 0x8008F864: addiu       $t9, $v0, -0x4CB
    ctx->r25 = ADD32(ctx->r2, -0X4CB);
    // 0x8008F868: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x8008F86C: beq         $at, $zero, L_8008F904
    if (ctx->r1 == 0) {
        // 0x8008F870: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8008F904;
    }
    // 0x8008F870: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008F874: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8008F878: addu        $at, $at, $t9
    gpr jr_addend_8008F880 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008F87C: lw          $t9, 0x5E14($at)
    ctx->r25 = ADD32(ctx->r1, 0X5E14);
    // 0x8008F880: jr          $t9
    // 0x8008F884: nop

    switch (jr_addend_8008F880 >> 2) {
        case 0: goto L_8008F8B4; break;
        case 1: goto L_8008F8B4; break;
        case 2: goto L_8008F8B4; break;
        case 3: goto L_8008F904; break;
        case 4: goto L_8008F904; break;
        case 5: goto L_8008F8B4; break;
        case 6: goto L_8008F904; break;
        case 7: goto L_8008F904; break;
        case 8: goto L_8008F904; break;
        case 9: goto L_8008F904; break;
        case 10: goto L_8008F904; break;
        case 11: goto L_8008F8B4; break;
        case 12: goto L_8008F904; break;
        case 13: goto L_8008F8B4; break;
        default: switch_error(__func__, 0x8008F880, 0x80105E14);
    }
    // 0x8008F884: nop

L_8008F888:
    // 0x8008F888: addiu       $at, $zero, 0x426
    ctx->r1 = ADD32(0, 0X426);
    // 0x8008F88C: beq         $v0, $at, L_8008F8B4
    if (ctx->r2 == ctx->r1) {
        // 0x8008F890: nop
    
            goto L_8008F8B4;
    }
    // 0x8008F890: nop

    // 0x8008F894: b           L_8008F908
    // 0x8008F898: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8008F908;
    // 0x8008F898: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8008F89C:
    // 0x8008F89C: addiu       $at, $zero, 0x2A3
    ctx->r1 = ADD32(0, 0X2A3);
    // 0x8008F8A0: beq         $v0, $at, L_8008F8B4
    if (ctx->r2 == ctx->r1) {
        // 0x8008F8A4: addiu       $at, $zero, 0x388
        ctx->r1 = ADD32(0, 0X388);
            goto L_8008F8B4;
    }
    // 0x8008F8A4: addiu       $at, $zero, 0x388
    ctx->r1 = ADD32(0, 0X388);
    // 0x8008F8A8: beq         $v0, $at, L_8008F8B4
    if (ctx->r2 == ctx->r1) {
        // 0x8008F8AC: addiu       $at, $zero, 0x402
        ctx->r1 = ADD32(0, 0X402);
            goto L_8008F8B4;
    }
    // 0x8008F8AC: addiu       $at, $zero, 0x402
    ctx->r1 = ADD32(0, 0X402);
    // 0x8008F8B0: bne         $v0, $at, L_8008F904
    if (ctx->r2 != ctx->r1) {
        // 0x8008F8B4: lui         $a3, 0x8027
        ctx->r7 = S32(0X8027 << 16);
            goto L_8008F904;
    }
L_8008F8B4:
    // 0x8008F8B4: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x8008F8B8: lh          $a3, 0x2310($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, 0X2310));
    // 0x8008F8BC: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x8008F8C0: addiu       $t5, $t5, -0x5C00
    ctx->r13 = ADD32(ctx->r13, -0X5C00);
    // 0x8008F8C4: sll         $t3, $a3, 3
    ctx->r11 = S32(ctx->r7 << 3);
    // 0x8008F8C8: addu        $t3, $t3, $a3
    ctx->r11 = ADD32(ctx->r11, ctx->r7);
    // 0x8008F8CC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008F8D0: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x8008F8D4: lh          $v1, 0x12($v0)
    ctx->r3 = S32(MEM_H(ctx->r2, 0X12));
    // 0x8008F8D8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8008F8DC: bne         $at, $zero, L_8008F8EC
    if (ctx->r1 != 0) {
        // 0x8008F8E0: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8008F8EC;
    }
    // 0x8008F8E0: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8008F8E4: b           L_8008F904
    // 0x8008F8E8: sh          $t4, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r12;
        goto L_8008F904;
    // 0x8008F8E8: sh          $t4, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r12;
L_8008F8EC:
    // 0x8008F8EC: bne         $a1, $v1, L_8008F904
    if (ctx->r5 != ctx->r3) {
        // 0x8008F8F0: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_8008F904;
    }
    // 0x8008F8F0: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x8008F8F4: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008F8F8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008F8FC: jal         0x800929F0
    // 0x8008F900: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    changespritestat(rdram, ctx);
        goto after_8;
    // 0x8008F900: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
L_8008F904:
    // 0x8008F904: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8008F908:
    // 0x8008F908: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008F90C: jr          $ra
    // 0x8008F910: nop

    return;
    // 0x8008F910: nop

;}
RECOMP_FUNC void set_gfxdata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BA4C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004BA50: addiu       $t3, $t3, 0x36F0
    ctx->r11 = ADD32(ctx->r11, 0X36F0);
    // 0x8004BA54: lw          $t6, 0x0($t3)
    ctx->r14 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004BA58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004BA5C: addiu       $t8, $t8, 0x3758
    ctx->r24 = ADD32(ctx->r24, 0X3758);
    // 0x8004BA60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8004BA64: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8004BA68: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8004BA6C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8004BA70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004BA74: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8004BA78: sll         $t7, $t7, 9
    ctx->r15 = S32(ctx->r15 << 9);
    // 0x8004BA7C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004BA80: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004BA84: ori         $at, $at, 0x8600
    ctx->r1 = ctx->r1 | 0X8600;
    // 0x8004BA88: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8004BA8C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8004BA90: addu        $t6, $t9, $at
    ctx->r14 = ADD32(ctx->r25, ctx->r1);
    // 0x8004BA94: addiu       $t2, $t2, 0x4410
    ctx->r10 = ADD32(ctx->r10, 0X4410);
    // 0x8004BA98: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x8004BA9C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8004BAA0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8004BAA4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8004BAA8: addiu       $t7, $t9, 0x600
    ctx->r15 = ADD32(ctx->r25, 0X600);
    // 0x8004BAAC: sw          $t7, -0x537C($at)
    MEM_W(-0X537C, ctx->r1) = ctx->r15;
    // 0x8004BAB0: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004BAB4: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8004BAB8: ori         $t9, $t9, 0x6
    ctx->r25 = ctx->r25 | 0X6;
    // 0x8004BABC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8004BAC0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8004BAC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004BAC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004BACC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004BAD0: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x8004BAD4: ori         $t7, $t7, 0x406
    ctx->r15 = ctx->r15 | 0X406;
    // 0x8004BAD8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8004BADC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8004BAE0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8004BAE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8004BAE8: lw          $t8, 0x4414($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, 0X4414));
    // 0x8004BAEC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8004BAF0: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x8004BAF4: addu        $t9, $t8, $t4
    ctx->r25 = ADD32(ctx->r24, ctx->r12);
    // 0x8004BAF8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8004BAFC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004BB00: ori         $t7, $t7, 0x806
    ctx->r15 = ctx->r15 | 0X806;
    // 0x8004BB04: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8004BB08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8004BB0C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8004BB10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8004BB14: lw          $t8, 0x0($t3)
    ctx->r24 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8004BB18: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8004BB1C: addiu       $t7, $t7, 0x400
    ctx->r15 = ADD32(ctx->r15, 0X400);
    // 0x8004BB20: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004BB24: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8004BB28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004BB2C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8004BB30: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004BB34: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8004BB38: sll         $t9, $t9, 11
    ctx->r25 = S32(ctx->r25 << 11);
    // 0x8004BB3C: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x8004BB40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8004BB44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8004BB48: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004BB4C: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8004BB50: addiu       $t6, $t6, 0x1888
    ctx->r14 = ADD32(ctx->r14, 0X1888);
    // 0x8004BB54: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8004BB58: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8004BB5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8004BB60: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8004BB64: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004BB68: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x8004BB6C: addiu       $t8, $t8, 0x1860
    ctx->r24 = ADD32(ctx->r24, 0X1860);
    // 0x8004BB70: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8004BB74: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8004BB78: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8004BB7C: jr          $ra
    // 0x8004BB80: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x8004BB80: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_80067AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AC4: andi        $t8, $a0, 0x8
    ctx->r24 = ctx->r4 & 0X8;
    // 0x80067AC8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80067ACC: bne         $t8, $at, L_80067AF4
    if (ctx->r24 != ctx->r1) {
        // 0x80067AD0: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_80067AF4;
    }
    // 0x80067AD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80067AD4: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80067AD8: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x80067ADC: addiu       $v1, $v1, -0x1440
    ctx->r3 = ADD32(ctx->r3, -0X1440);
    // 0x80067AE0: addiu       $v0, $v0, -0x1444
    ctx->r2 = ADD32(ctx->r2, -0X1444);
    // 0x80067AE4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = S32(MEM_W(ctx->r2, 0X0));
    // 0x80067AE8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = S32(MEM_W(ctx->r3, 0X0));
    // 0x80067AEC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80067AF0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_80067AF4:
    // 0x80067AF4: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80067AF8: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x80067AFC: addiu       $v1, $v1, -0x1428
    ctx->r3 = ADD32(ctx->r3, -0X1428);
    // 0x80067B00: addiu       $v0, $v0, -0x142C
    ctx->r2 = ADD32(ctx->r2, -0X142C);
    // 0x80067B04: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = S32(MEM_W(ctx->r2, 0X0));
    // 0x80067B08: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = S32(MEM_W(ctx->r3, 0X0));
    // 0x80067B0C: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x80067B10: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x80067B14: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80067B18: addiu       $a1, $a1, -0x1434
    ctx->r5 = ADD32(ctx->r5, -0X1434);
    // 0x80067B1C: addiu       $a0, $a0, -0x1430
    ctx->r4 = ADD32(ctx->r4, -0X1430);
    // 0x80067B20: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80067B24: bc1fl       L_80067B38
    if (!c1cs) {
        // 0x80067B28: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_80067B38;
    }
    goto skip_0;
    // 0x80067B28: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    skip_0:
    // 0x80067B2C: b           L_80067B38
    // 0x80067B30: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80067B38;
    // 0x80067B30: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80067B34: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80067B38:
    // 0x80067B38: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = S32(MEM_W(ctx->r4, 0X0));
    // 0x80067B3C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80067B40: nop

    // 0x80067B44: bc1fl       L_80067B58
    if (!c1cs) {
        // 0x80067B48: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80067B58;
    }
    goto skip_1;
    // 0x80067B48: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x80067B4C: b           L_80067B74
    // 0x80067B50: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
        goto L_80067B74;
    // 0x80067B50: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
    // 0x80067B54: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80067B58:
    // 0x80067B58: nop

    // 0x80067B5C: bc1fl       L_80067B70
    if (!c1cs) {
        // 0x80067B60: mov.s       $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
            goto L_80067B70;
    }
    goto skip_2;
    // 0x80067B60: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
    skip_2:
    // 0x80067B64: b           L_80067B70
    // 0x80067B68: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
        goto L_80067B70;
    // 0x80067B68: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80067B6C: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
L_80067B70:
    // 0x80067B70: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
L_80067B74:
    // 0x80067B74: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = S32(MEM_W(ctx->r5, 0X0));
    // 0x80067B78: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80067B7C: nop

    // 0x80067B80: bc1fl       L_80067B94
    if (!c1cs) {
        // 0x80067B84: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80067B94;
    }
    goto skip_3;
    // 0x80067B84: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_3:
    // 0x80067B88: b           L_80067BE8
    // 0x80067B8C: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
        goto L_80067BE8;
    // 0x80067B8C: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    // 0x80067B90: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80067B94:
    // 0x80067B94: nop

    // 0x80067B98: bc1fl       L_80067BAC
    if (!c1cs) {
        // 0x80067B9C: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_80067BAC;
    }
    goto skip_4;
    // 0x80067B9C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    skip_4:
    // 0x80067BA0: b           L_80067BAC
    // 0x80067BA4: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80067BAC;
    // 0x80067BA4: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80067BA8: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80067BAC:
    // 0x80067BAC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80067BB0: nop

    // 0x80067BB4: bc1fl       L_80067BC8
    if (!c1cs) {
        // 0x80067BB8: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80067BC8;
    }
    goto skip_5;
    // 0x80067BB8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_5:
    // 0x80067BBC: b           L_80067BE4
    // 0x80067BC0: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
        goto L_80067BE4;
    // 0x80067BC0: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
    // 0x80067BC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80067BC8:
    // 0x80067BC8: nop

    // 0x80067BCC: bc1fl       L_80067BE0
    if (!c1cs) {
        // 0x80067BD0: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_80067BE0;
    }
    goto skip_6;
    // 0x80067BD0: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    skip_6:
    // 0x80067BD4: b           L_80067BE0
    // 0x80067BD8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80067BE0;
    // 0x80067BD8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80067BDC: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80067BE0:
    // 0x80067BE0: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
L_80067BE4:
    // 0x80067BE4: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
L_80067BE8:
    // 0x80067BE8: lwc1        $f6, 0x4D80($at)
    ctx->f6.u32l = S32(MEM_W(ctx->r1, 0X4D80));
    // 0x80067BEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80067BF0: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80067BF4: nop

    // 0x80067BF8: bc1fl       L_80067C60
    if (!c1cs) {
        // 0x80067BFC: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80067C60;
    }
    goto skip_7;
    // 0x80067BFC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_7:
    // 0x80067C00: lwc1        $f8, 0x4D84($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, 0X4D84));
    // 0x80067C04: addiu       $at, $zero, -0x1000
    ctx->r1 = ADD32(0, -0X1000);
    // 0x80067C08: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80067C0C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80067C10: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80067C14: nop

    // 0x80067C18: addiu       $t1, $t0, 0xFFF
    ctx->r9 = ADD32(ctx->r8, 0XFFF);
    // 0x80067C1C: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80067C20: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80067C24: nop

    // 0x80067C28: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067C2C: add.s       $f8, $f14, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x80067C30: add.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x80067C34: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80067C38: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = S32(MEM_W(ctx->r5, 0X0));
    // 0x80067C3C: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80067C40: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80067C44: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = S32(MEM_W(ctx->r4, 0X0));
    // 0x80067C48: add.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80067C4C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80067C50: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = S32(MEM_W(ctx->r2, 0X0));
    // 0x80067C54: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80067C58: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = S32(MEM_W(ctx->r3, 0X0));
    // 0x80067C5C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80067C60:
    // 0x80067C60: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80067C64: bc1fl       L_80067C78
    if (!c1cs) {
        // 0x80067C68: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_80067C78;
    }
    goto skip_8;
    // 0x80067C68: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    skip_8:
    // 0x80067C6C: b           L_80067C78
    // 0x80067C70: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80067C78;
    // 0x80067C70: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80067C74: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80067C78:
    // 0x80067C78: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80067C7C: nop

    // 0x80067C80: bc1fl       L_80067C94
    if (!c1cs) {
        // 0x80067C84: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80067C94;
    }
    goto skip_9;
    // 0x80067C84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_9:
    // 0x80067C88: b           L_80067CB0
    // 0x80067C8C: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
        goto L_80067CB0;
    // 0x80067C8C: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
    // 0x80067C90: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80067C94:
    // 0x80067C94: nop

    // 0x80067C98: bc1fl       L_80067CAC
    if (!c1cs) {
        // 0x80067C9C: mov.s       $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
            goto L_80067CAC;
    }
    goto skip_10;
    // 0x80067C9C: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
    skip_10:
    // 0x80067CA0: b           L_80067CAC
    // 0x80067CA4: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
        goto L_80067CAC;
    // 0x80067CA4: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80067CA8: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
L_80067CAC:
    // 0x80067CAC: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
L_80067CB0:
    // 0x80067CB0: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x80067CB4: nop

    // 0x80067CB8: bc1fl       L_80067CCC
    if (!c1cs) {
        // 0x80067CBC: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80067CCC;
    }
    goto skip_11;
    // 0x80067CBC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_11:
    // 0x80067CC0: b           L_80067D20
    // 0x80067CC4: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
        goto L_80067D20;
    // 0x80067CC4: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    // 0x80067CC8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80067CCC:
    // 0x80067CCC: nop

    // 0x80067CD0: bc1fl       L_80067CE4
    if (!c1cs) {
        // 0x80067CD4: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_80067CE4;
    }
    goto skip_12;
    // 0x80067CD4: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    skip_12:
    // 0x80067CD8: b           L_80067CE4
    // 0x80067CDC: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80067CE4;
    // 0x80067CDC: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80067CE0: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80067CE4:
    // 0x80067CE4: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80067CE8: nop

    // 0x80067CEC: bc1fl       L_80067D00
    if (!c1cs) {
        // 0x80067CF0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80067D00;
    }
    goto skip_13;
    // 0x80067CF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_13:
    // 0x80067CF4: b           L_80067D1C
    // 0x80067CF8: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
        goto L_80067D1C;
    // 0x80067CF8: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
    // 0x80067CFC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80067D00:
    // 0x80067D00: nop

    // 0x80067D04: bc1fl       L_80067D18
    if (!c1cs) {
        // 0x80067D08: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_80067D18;
    }
    goto skip_14;
    // 0x80067D08: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    skip_14:
    // 0x80067D0C: b           L_80067D18
    // 0x80067D10: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80067D18;
    // 0x80067D10: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80067D14: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80067D18:
    // 0x80067D18: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
L_80067D1C:
    // 0x80067D1C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
L_80067D20:
    // 0x80067D20: lwc1        $f8, 0x4D88($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, 0X4D88));
    // 0x80067D24: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80067D28: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80067D2C: nop

    // 0x80067D30: bc1f        L_80067D84
    if (!c1cs) {
        // 0x80067D34: nop
    
            goto L_80067D84;
    }
    // 0x80067D34: nop

    // 0x80067D38: lwc1        $f10, 0x4D8C($at)
    ctx->f10.u32l = S32(MEM_W(ctx->r1, 0X4D8C));
    // 0x80067D3C: addiu       $at, $zero, -0x1000
    ctx->r1 = ADD32(0, -0X1000);
    // 0x80067D40: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80067D44: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80067D48: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80067D4C: nop

    // 0x80067D50: addiu       $t5, $t4, 0xFFF
    ctx->r13 = ADD32(ctx->r12, 0XFFF);
    // 0x80067D54: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80067D58: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80067D5C: nop

    // 0x80067D60: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067D64: sub.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80067D68: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80067D6C: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x80067D70: sub.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80067D74: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80067D78: sub.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80067D7C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80067D80: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_80067D84:
    // 0x80067D84: jr          $ra
    // 0x80067D88: nop

    return;
    // 0x80067D88: nop

;}
RECOMP_FUNC void alFxParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0ED4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0ED8: bne         $a1, $at, L_800D0EE4
    if (ctx->r5 != ctx->r1) {
        // 0x800D0EDC: nop
    
            goto L_800D0EE4;
    }
    // 0x800D0EDC: nop

    // 0x800D0EE0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_800D0EE4:
    // 0x800D0EE4: jr          $ra
    // 0x800D0EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D0EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void checkweapons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A3434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3438: lh          $a1, 0x2B2($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0X2B2));
    // 0x800A343C: blez        $a1, L_800A34D0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800A3440: slti        $at, $a1, 0xF
        ctx->r1 = SIGNED(ctx->r5) < 0XF ? 1 : 0;
            goto L_800A34D0;
    }
    // 0x800A3440: slti        $at, $a1, 0xF
    ctx->r1 = SIGNED(ctx->r5) < 0XF ? 1 : 0;
    // 0x800A3444: beql        $at, $zero, L_800A34D4
    if (ctx->r1 == 0) {
        // 0x800A3448: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800A34D4;
    }
    goto skip_0;
    // 0x800A3448: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800A344C: beql        $a1, $zero, L_800A34D4
    if (ctx->r5 == 0) {
        // 0x800A3450: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800A34D4;
    }
    goto skip_1;
    // 0x800A3450: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_1:
    // 0x800A3454: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x800A3458: jal         0x8009800C
    // 0x800A345C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    krand2(rdram, ctx);
        goto after_0;
    // 0x800A345C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A3460: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800A3464: lh          $a1, 0x1C($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X1C));
    // 0x800A3468: beq         $t6, $zero, L_800A34A0
    if (ctx->r14 == 0) {
        // 0x800A346C: lw          $a2, 0x20($sp)
        ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
            goto L_800A34A0;
    }
    // 0x800A346C: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A3470: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x800A3474: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800A3478: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800A347C: lh          $a1, -0x5050($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X5050));
    // 0x800A3480: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800A3484: bne         $a1, $at, L_800A3490
    if (ctx->r5 != ctx->r1) {
        // 0x800A3488: nop
    
            goto L_800A3490;
    }
    // 0x800A3488: nop

    // 0x800A348C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
L_800A3490:
    // 0x800A3490: jal         0x8009D240
    // 0x800A3494: lh          $a0, 0x2E0($a2)
    ctx->r4 = S32(MEM_H(ctx->r6, 0X2E0));
    spawn(rdram, ctx);
        goto after_1;
    // 0x800A3494: lh          $a0, 0x2E0($a2)
    ctx->r4 = S32(MEM_H(ctx->r6, 0X2E0));
    after_1:
    // 0x800A3498: b           L_800A34D4
    // 0x800A349C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800A34D4;
    // 0x800A349C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800A34A0:
    // 0x800A34A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A34A4: beq         $a1, $at, L_800A34C4
    if (ctx->r5 == ctx->r1) {
        // 0x800A34A8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800A34C4;
    }
    // 0x800A34A8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A34AC: beq         $a1, $at, L_800A34C4
    if (ctx->r5 == ctx->r1) {
        // 0x800A34B0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A34C4;
    }
    // 0x800A34B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A34B4: beq         $a1, $at, L_800A34C4
    if (ctx->r5 == ctx->r1) {
        // 0x800A34B8: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800A34C4;
    }
    // 0x800A34B8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800A34BC: bnel        $a1, $at, L_800A34D4
    if (ctx->r5 != ctx->r1) {
        // 0x800A34C0: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800A34D4;
    }
    goto skip_2;
    // 0x800A34C0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_2:
L_800A34C4:
    // 0x800A34C4: lh          $a0, 0x2E0($a2)
    ctx->r4 = S32(MEM_H(ctx->r6, 0X2E0));
    // 0x800A34C8: jal         0x8009D240
    // 0x800A34CC: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    spawn(rdram, ctx);
        goto after_2;
    // 0x800A34CC: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    after_2:
L_800A34D0:
    // 0x800A34D0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800A34D4:
    // 0x800A34D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A34D8: jr          $ra
    // 0x800A34DC: nop

    return;
    // 0x800A34DC: nop

;}
RECOMP_FUNC void check_activator_motion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACB10: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x800ACB14: addiu       $a3, $a3, 0x2858
    ctx->r7 = ADD32(ctx->r7, 0X2858);
    // 0x800ACB18: lh          $v0, 0x10($a3)
    ctx->r2 = S32(MEM_H(ctx->r7, 0X10));
    // 0x800ACB1C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800ACB20: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800ACB24: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800ACB28: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800ACB2C: bltz        $v0, L_800ACC7C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800ACB30: sw          $s0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r16;
            goto L_800ACC7C;
    }
    // 0x800ACB30: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800ACB34: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800ACB38: lui         $t4, 0x8028
    ctx->r12 = S32(0X8028 << 16);
    // 0x800ACB3C: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x800ACB40: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x800ACB44: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800ACB48: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800ACB4C: addiu       $t2, $t2, -0x55A8
    ctx->r10 = ADD32(ctx->r10, -0X55A8);
    // 0x800ACB50: addiu       $t3, $t3, -0x5640
    ctx->r11 = ADD32(ctx->r11, -0X5640);
    // 0x800ACB54: addiu       $t4, $t4, -0x5C00
    ctx->r12 = ADD32(ctx->r12, -0X5C00);
    // 0x800ACB58: addiu       $s0, $s0, 0x5F40
    ctx->r16 = ADD32(ctx->r16, 0X5F40);
    // 0x800ACB5C: addiu       $t5, $zero, 0x48
    ctx->r13 = ADD32(0, 0X48);
    // 0x800ACB60: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
L_800ACB64:
    // 0x800ACB64: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACB68: mflo        $t8
    ctx->r24 = lo;
    // 0x800ACB6C: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x800ACB70: lh          $t9, 0x1E($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800ACB74: bnel        $a0, $t9, L_800ACC6C
    if (ctx->r4 != ctx->r25) {
        // 0x800ACB78: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_800ACC6C;
    }
    goto skip_0;
    // 0x800ACB78: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    skip_0:
    // 0x800ACB7C: lw          $a1, 0x0($t2)
    ctx->r5 = S32(MEM_W(ctx->r10, 0X0));
    // 0x800ACB80: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800ACB84: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800ACB88: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800ACB8C: bltzl       $a1, L_800ACBC8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800ACB90: lh          $a1, 0x6($a3)
        ctx->r5 = S32(MEM_H(ctx->r7, 0X6));
            goto L_800ACBC8;
    }
    goto skip_1;
    // 0x800ACB90: lh          $a1, 0x6($a3)
    ctx->r5 = S32(MEM_H(ctx->r7, 0X6));
    skip_1:
    // 0x800ACB94: lh          $a2, 0x10($v1)
    ctx->r6 = S32(MEM_H(ctx->r3, 0X10));
    // 0x800ACB98: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
L_800ACB9C:
    // 0x800ACB9C: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x800ACBA0: lh          $t6, 0x0($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800ACBA4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800ACBA8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800ACBAC: bne         $a2, $t6, L_800ACBBC
    if (ctx->r6 != ctx->r14) {
        // 0x800ACBB0: sra         $a1, $t7, 16
        ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800ACBBC;
    }
    // 0x800ACBB0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800ACBB4: b           L_800ACC80
    // 0x800ACBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ACC80;
    // 0x800ACBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ACBBC:
    // 0x800ACBBC: bgezl       $a1, L_800ACB9C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800ACBC0: sll         $t8, $a1, 1
        ctx->r24 = S32(ctx->r5 << 1);
            goto L_800ACB9C;
    }
    goto skip_2;
    // 0x800ACBC0: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    skip_2:
    // 0x800ACBC4: lh          $a1, 0x6($a3)
    ctx->r5 = S32(MEM_H(ctx->r7, 0X6));
L_800ACBC8:
    // 0x800ACBC8: bltzl       $a1, L_800ACC6C
    if (SIGNED(ctx->r5) < 0) {
        // 0x800ACBCC: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_800ACC6C;
    }
    goto skip_3;
    // 0x800ACBCC: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    skip_3:
    // 0x800ACBD0: lh          $a2, 0x10($v1)
    ctx->r6 = S32(MEM_H(ctx->r3, 0X10));
L_800ACBD4:
    // 0x800ACBD4: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACBD8: mflo        $t9
    ctx->r25 = lo;
    // 0x800ACBDC: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x800ACBE0: lh          $t6, 0x10($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0X10));
    // 0x800ACBE4: bnel        $a2, $t6, L_800ACC58
    if (ctx->r6 != ctx->r14) {
        // 0x800ACBE8: sll         $t7, $a1, 1
        ctx->r15 = S32(ctx->r5 << 1);
            goto L_800ACC58;
    }
    goto skip_4;
    // 0x800ACBE8: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    skip_4:
    // 0x800ACBEC: lh          $t7, 0x1E($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800ACBF0: addiu       $t8, $t7, -0xB
    ctx->r24 = ADD32(ctx->r15, -0XB);
    // 0x800ACBF4: sltiu       $at, $t8, 0x16
    ctx->r1 = ctx->r24 < 0X16 ? 1 : 0;
    // 0x800ACBF8: beq         $at, $zero, L_800ACC54
    if (ctx->r1 == 0) {
        // 0x800ACBFC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800ACC54;
    }
    // 0x800ACBFC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800ACC00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800ACC04: addu        $at, $at, $t8
    gpr jr_addend_800ACC0C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800ACC08: lw          $t8, -0x7AA8($at)
    ctx->r24 = ADD32(ctx->r1, -0X7AA8);
    // 0x800ACC0C: jr          $t8
    // 0x800ACC10: nop

    switch (jr_addend_800ACC0C >> 2) {
        case 0: goto L_800ACC14; break;
        case 1: goto L_800ACC54; break;
        case 2: goto L_800ACC54; break;
        case 3: goto L_800ACC54; break;
        case 4: goto L_800ACC54; break;
        case 5: goto L_800ACC54; break;
        case 6: goto L_800ACC54; break;
        case 7: goto L_800ACC34; break;
        case 8: goto L_800ACC54; break;
        case 9: goto L_800ACC34; break;
        case 10: goto L_800ACC54; break;
        case 11: goto L_800ACC54; break;
        case 12: goto L_800ACC54; break;
        case 13: goto L_800ACC54; break;
        case 14: goto L_800ACC54; break;
        case 15: goto L_800ACC54; break;
        case 16: goto L_800ACC54; break;
        case 17: goto L_800ACC54; break;
        case 18: goto L_800ACC54; break;
        case 19: goto L_800ACC14; break;
        case 20: goto L_800ACC34; break;
        case 21: goto L_800ACC34; break;
        default: switch_error(__func__, 0x800ACC0C, 0x80108558);
    }
    // 0x800ACC10: nop

L_800ACC14:
    // 0x800ACC14: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACC18: mflo        $t9
    ctx->r25 = lo;
    // 0x800ACC1C: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x800ACC20: lw          $t7, 0x40($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X40));
    // 0x800ACC24: beql        $t7, $zero, L_800ACC58
    if (ctx->r15 == 0) {
        // 0x800ACC28: sll         $t7, $a1, 1
        ctx->r15 = S32(ctx->r5 << 1);
            goto L_800ACC58;
    }
    goto skip_5;
    // 0x800ACC28: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    skip_5:
    // 0x800ACC2C: b           L_800ACC80
    // 0x800ACC30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ACC80;
    // 0x800ACC30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ACC34:
    // 0x800ACC34: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACC38: mflo        $t8
    ctx->r24 = lo;
    // 0x800ACC3C: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800ACC40: lw          $t6, 0x30($t9)
    ctx->r14 = S32(MEM_W(ctx->r25, 0X30));
    // 0x800ACC44: beql        $t6, $zero, L_800ACC58
    if (ctx->r14 == 0) {
        // 0x800ACC48: sll         $t7, $a1, 1
        ctx->r15 = S32(ctx->r5 << 1);
            goto L_800ACC58;
    }
    goto skip_6;
    // 0x800ACC48: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    skip_6:
    // 0x800ACC4C: b           L_800ACC80
    // 0x800ACC50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ACC80;
    // 0x800ACC50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ACC54:
    // 0x800ACC54: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
L_800ACC58:
    // 0x800ACC58: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800ACC5C: lh          $a1, 0x0($t8)
    ctx->r5 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800ACC60: bgez        $a1, L_800ACBD4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800ACC64: nop
    
            goto L_800ACBD4;
    }
    // 0x800ACC64: nop

    // 0x800ACC68: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
L_800ACC6C:
    // 0x800ACC6C: addu        $t6, $s0, $t9
    ctx->r14 = ADD32(ctx->r16, ctx->r25);
    // 0x800ACC70: lh          $v0, 0x0($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800ACC74: bgez        $v0, L_800ACB64
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800ACC78: nop
    
            goto L_800ACB64;
    }
    // 0x800ACC78: nop

L_800ACC7C:
    // 0x800ACC7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ACC80:
    // 0x800ACC80: lw          $s0, 0x4($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X4));
    // 0x800ACC84: jr          $ra
    // 0x800ACC88: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800ACC88: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void displayloogie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800728D8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800728DC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800728E0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800728E4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800728E8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800728EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800728F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800728F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800728F8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800728FC: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x80072900: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80072904: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x80072908: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007290C: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x80072910: lw          $v0, 0x210($s2)
    ctx->r2 = S32(MEM_W(ctx->r18, 0X210));
    // 0x80072914: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80072918: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8007291C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80072920: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80072924: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80072928: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8007292C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80072930: beq         $v0, $zero, L_80072A48
    if (ctx->r2 == 0) {
        // 0x80072934: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_80072A48;
    }
    // 0x80072934: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80072938: lw          $t0, 0x20C($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X20C));
    // 0x8007293C: sll         $s4, $v0, 2
    ctx->r20 = S32(ctx->r2 << 2);
    // 0x80072940: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80072944: blez        $t0, L_80072A48
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80072948: sll         $t1, $t7, 2
        ctx->r9 = S32(ctx->r15 << 2);
            goto L_80072A48;
    }
    // 0x80072948: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8007294C: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x80072950: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x80072954: addiu       $t2, $t2, 0x5600
    ctx->r10 = ADD32(ctx->r10, 0X5600);
    // 0x80072958: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007295C: lui         $s3, 0x8010
    ctx->r19 = S32(0X8010 << 16);
    // 0x80072960: addiu       $s3, $s3, -0x9A0
    ctx->r19 = ADD32(ctx->r19, -0X9A0);
    // 0x80072964: addu        $s5, $t1, $t2
    ctx->r21 = ADD32(ctx->r9, ctx->r10);
    // 0x80072968: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x8007296C: addiu       $s6, $zero, 0x64
    ctx->r22 = ADD32(0, 0X64);
    // 0x80072970: lw          $t3, 0x210($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X210));
L_80072974:
    // 0x80072974: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80072978: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x8007297C: andi        $t6, $t5, 0x7FF
    ctx->r14 = ctx->r13 & 0X7FF;
    // 0x80072980: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80072984: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80072988: jal         0x80091A38
    // 0x8007298C: lh          $a0, 0x0($t8)
    ctx->r4 = S32(MEM_H(ctx->r24, 0X0));
    klabs(rdram, ctx);
        goto after_0;
    // 0x8007298C: lh          $a0, 0x0($t8)
    ctx->r4 = S32(MEM_H(ctx->r24, 0X0));
    after_0:
    // 0x80072990: lw          $t9, 0x210($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X210));
    // 0x80072994: lb          $t6, 0x0($s5)
    ctx->r14 = S32(MEM_B(ctx->r21, 0X0));
    // 0x80072998: lw          $t7, 0xC($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0XC));
    // 0x8007299C: addu        $v0, $t9, $s0
    ctx->r2 = ADD32(ctx->r25, ctx->r16);
    // 0x800729A0: sll         $t0, $v0, 6
    ctx->r8 = S32(ctx->r2 << 6);
    // 0x800729A4: andi        $t1, $t0, 0x7FF
    ctx->r9 = ctx->r8 & 0X7FF;
    // 0x800729A8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800729AC: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x800729B0: sll         $v1, $v0, 9
    ctx->r3 = S32(ctx->r2 << 9);
    // 0x800729B4: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x800729B8: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    // 0x800729BC: sll         $t2, $s0, 8
    ctx->r10 = S32(ctx->r16 << 8);
    // 0x800729C0: subu        $t3, $v1, $t2
    ctx->r11 = SUB32(ctx->r3, ctx->r10);
    // 0x800729C4: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800729C8: sra         $t5, $t4, 10
    ctx->r13 = S32(SIGNED(ctx->r12) >> 10);
    // 0x800729CC: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x800729D0: lw          $t9, 0x10C($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X10C));
    // 0x800729D4: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800729D8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800729DC: subu        $t0, $t9, $s4
    ctx->r8 = SUB32(ctx->r25, ctx->r20);
    // 0x800729E0: addiu       $t1, $t0, 0xC8
    ctx->r9 = ADD32(ctx->r8, 0XC8);
    // 0x800729E4: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800729E8: addiu       $t6, $zero, 0x665
    ctx->r14 = ADD32(0, 0X665);
    // 0x800729EC: mflo        $t4
    ctx->r12 = lo;
    // 0x800729F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800729F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800729F8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800729FC: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80072A00: bgez        $t4, L_80072A14
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80072A04: sra         $t5, $t4, 16
        ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
            goto L_80072A14;
    }
    // 0x80072A04: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80072A08: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80072A0C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80072A10: sra         $t5, $at, 16
    ctx->r13 = S32(SIGNED(ctx->r1) >> 16);
L_80072A14:
    // 0x80072A14: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80072A18: nop

    // 0x80072A1C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80072A20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80072A24: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80072A28: jal         0x8005D13C
    // 0x80072A2C: nop

    rotatesprite(rdram, ctx);
        goto after_1;
    // 0x80072A2C: nop

    after_1:
    // 0x80072A30: lw          $t7, 0x20C($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X20C));
    // 0x80072A34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80072A38: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80072A3C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80072A40: bnel        $at, $zero, L_80072974
    if (ctx->r1 != 0) {
        // 0x80072A44: lw          $t3, 0x210($s2)
        ctx->r11 = S32(MEM_W(ctx->r18, 0X210));
            goto L_80072974;
    }
    goto skip_0;
    // 0x80072A44: lw          $t3, 0x210($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X210));
    skip_0:
L_80072A48:
    // 0x80072A48: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80072A4C: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80072A50: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80072A54: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80072A58: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80072A5C: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80072A60: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80072A64: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80072A68: jr          $ra
    // 0x80072A6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80072A6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void getviewborder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E6B0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006E6B4: lh          $v0, -0x9DC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9DC));
    // 0x8006E6B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006E6BC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8006E6C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006E6C4: beq         $v0, $v1, L_8006E6F4
    if (ctx->r2 == ctx->r3) {
        // 0x8006E6C8: sra         $a0, $t6, 16
        ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8006E6F4;
    }
    // 0x8006E6C8: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006E6CC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8006E6D0: beq         $v0, $t0, L_8006E71C
    if (ctx->r2 == ctx->r8) {
        // 0x8006E6D4: addiu       $t4, $zero, 0x16
        ctx->r12 = ADD32(0, 0X16);
            goto L_8006E71C;
    }
    // 0x8006E6D4: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x8006E6D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006E6DC: beq         $v0, $at, L_8006E75C
    if (ctx->r2 == ctx->r1) {
        // 0x8006E6E0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8006E75C;
    }
    // 0x8006E6E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006E6E4: beq         $v0, $at, L_8006E75C
    if (ctx->r2 == ctx->r1) {
        // 0x8006E6E8: nop
    
            goto L_8006E75C;
    }
    // 0x8006E6E8: nop

    // 0x8006E6EC: jr          $ra
    // 0x8006E6F0: nop

    return;
    // 0x8006E6F0: nop

L_8006E6F4:
    // 0x8006E6F4: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x8006E6F8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8006E6FC: addiu       $t9, $zero, 0x12A
    ctx->r25 = ADD32(0, 0X12A);
    // 0x8006E700: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x8006E704: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8006E708: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x8006E70C: lw          $t3, 0x10($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X10));
    // 0x8006E710: addiu       $t2, $zero, 0xE0
    ctx->r10 = ADD32(0, 0XE0);
    // 0x8006E714: jr          $ra
    // 0x8006E718: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    return;
    // 0x8006E718: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
L_8006E71C:
    // 0x8006E71C: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x8006E720: addiu       $t5, $zero, 0x12A
    ctx->r13 = ADD32(0, 0X12A);
    // 0x8006E724: bne         $a0, $zero, L_8006E744
    if (ctx->r4 != 0) {
        // 0x8006E728: sh          $t5, 0x0($a3)
        MEM_H(0X0, ctx->r7) = ctx->r13;
            goto L_8006E744;
    }
    // 0x8006E728: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
    // 0x8006E72C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8006E730: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x8006E734: lw          $t8, 0x10($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X10));
    // 0x8006E738: addiu       $t7, $zero, 0x77
    ctx->r15 = ADD32(0, 0X77);
    // 0x8006E73C: jr          $ra
    // 0x8006E740: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    return;
    // 0x8006E740: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_8006E744:
    // 0x8006E744: addiu       $t9, $zero, 0x79
    ctx->r25 = ADD32(0, 0X79);
    // 0x8006E748: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x8006E74C: lw          $t2, 0x10($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X10));
    // 0x8006E750: addiu       $t1, $zero, 0xE0
    ctx->r9 = ADD32(0, 0XE0);
    // 0x8006E754: jr          $ra
    // 0x8006E758: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    return;
    // 0x8006E758: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
L_8006E75C:
    // 0x8006E75C: beq         $a0, $zero, L_8006E76C
    if (ctx->r4 == 0) {
        // 0x8006E760: addiu       $t3, $zero, 0x16
        ctx->r11 = ADD32(0, 0X16);
            goto L_8006E76C;
    }
    // 0x8006E760: addiu       $t3, $zero, 0x16
    ctx->r11 = ADD32(0, 0X16);
    // 0x8006E764: bne         $a0, $t0, L_8006E77C
    if (ctx->r4 != ctx->r8) {
        // 0x8006E768: addiu       $t5, $zero, 0xA1
        ctx->r13 = ADD32(0, 0XA1);
            goto L_8006E77C;
    }
    // 0x8006E768: addiu       $t5, $zero, 0xA1
    ctx->r13 = ADD32(0, 0XA1);
L_8006E76C:
    // 0x8006E76C: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x8006E770: addiu       $t4, $zero, 0x9F
    ctx->r12 = ADD32(0, 0X9F);
    // 0x8006E774: b           L_8006E788
    // 0x8006E778: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
        goto L_8006E788;
    // 0x8006E778: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
L_8006E77C:
    // 0x8006E77C: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
    // 0x8006E780: addiu       $t6, $zero, 0x12A
    ctx->r14 = ADD32(0, 0X12A);
    // 0x8006E784: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
L_8006E788:
    // 0x8006E788: beq         $a0, $zero, L_8006E798
    if (ctx->r4 == 0) {
        // 0x8006E78C: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_8006E798;
    }
    // 0x8006E78C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8006E790: bne         $a0, $v1, L_8006E7AC
    if (ctx->r4 != ctx->r3) {
        // 0x8006E794: addiu       $t1, $zero, 0x79
        ctx->r9 = ADD32(0, 0X79);
            goto L_8006E7AC;
    }
    // 0x8006E794: addiu       $t1, $zero, 0x79
    ctx->r9 = ADD32(0, 0X79);
L_8006E798:
    // 0x8006E798: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x8006E79C: lw          $t9, 0x10($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X10));
    // 0x8006E7A0: addiu       $t8, $zero, 0x77
    ctx->r24 = ADD32(0, 0X77);
    // 0x8006E7A4: jr          $ra
    // 0x8006E7A8: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    return;
    // 0x8006E7A8: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
L_8006E7AC:
    // 0x8006E7AC: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x8006E7B0: lw          $t3, 0x10($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X10));
    // 0x8006E7B4: addiu       $t2, $zero, 0xE0
    ctx->r10 = ADD32(0, 0XE0);
    // 0x8006E7B8: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x8006E7BC: jr          $ra
    // 0x8006E7C0: nop

    return;
    // 0x8006E7C0: nop

;}
RECOMP_FUNC void setrotatespriteflags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E994: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006E998: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8006E99C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006E9A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006E9A4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8006E9A8: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006E9AC: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8006E9B0: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8006E9B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006E9B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8006E9BC: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8006E9C0: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006E9C4: bne         $at, $zero, L_8006E9D4
    if (ctx->r1 != 0) {
        // 0x8006E9C8: sra         $a2, $t6, 16
        ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8006E9D4;
    }
    // 0x8006E9C8: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006E9CC: b           L_8006E9D8
    // 0x8006E9D0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8006E9D8;
    // 0x8006E9D0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006E9D4:
    // 0x8006E9D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006E9D8:
    // 0x8006E9D8: bgez        $v0, L_8006E9E8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006E9DC: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_8006E9E8;
    }
    // 0x8006E9DC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8006E9E0: b           L_8006EA08
    // 0x8006E9E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8006EA08;
    // 0x8006E9E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006E9E8:
    // 0x8006E9E8: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8006E9EC: bne         $at, $zero, L_8006E9FC
    if (ctx->r1 != 0) {
        // 0x8006E9F0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8006E9FC;
    }
    // 0x8006E9F0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006E9F4: b           L_8006E9FC
    // 0x8006E9F8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8006E9FC;
    // 0x8006E9F8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006E9FC:
    // 0x8006E9FC: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8006EA00: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006EA04: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_8006EA08:
    // 0x8006EA08: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x8006EA0C: bne         $at, $zero, L_8006EA1C
    if (ctx->r1 != 0) {
        // 0x8006EA10: addiu       $v1, $v1, 0x4418
        ctx->r3 = ADD32(ctx->r3, 0X4418);
            goto L_8006EA1C;
    }
    // 0x8006EA10: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x8006EA14: b           L_8006EA20
    // 0x8006EA18: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8006EA20;
    // 0x8006EA18: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006EA1C:
    // 0x8006EA1C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8006EA20:
    // 0x8006EA20: bgez        $v0, L_8006EA30
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006EA24: slti        $at, $a1, 0x100
        ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
            goto L_8006EA30;
    }
    // 0x8006EA24: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x8006EA28: b           L_8006EA4C
    // 0x8006EA2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8006EA4C;
    // 0x8006EA2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8006EA30:
    // 0x8006EA30: bne         $at, $zero, L_8006EA40
    if (ctx->r1 != 0) {
        // 0x8006EA34: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8006EA40;
    }
    // 0x8006EA34: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8006EA38: b           L_8006EA40
    // 0x8006EA3C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8006EA40;
    // 0x8006EA3C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006EA40:
    // 0x8006EA40: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8006EA44: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006EA48: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8006EA4C:
    // 0x8006EA4C: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    // 0x8006EA50: bne         $at, $zero, L_8006EA60
    if (ctx->r1 != 0) {
        // 0x8006EA54: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8006EA60;
    }
    // 0x8006EA54: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8006EA58: b           L_8006EA60
    // 0x8006EA5C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8006EA60;
    // 0x8006EA5C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006EA60:
    // 0x8006EA60: bgez        $v0, L_8006EA70
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006EA64: slti        $at, $a2, 0x100
        ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
            goto L_8006EA70;
    }
    // 0x8006EA64: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    // 0x8006EA68: b           L_8006EA8C
    // 0x8006EA6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8006EA8C;
    // 0x8006EA6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8006EA70:
    // 0x8006EA70: bne         $at, $zero, L_8006EA80
    if (ctx->r1 != 0) {
        // 0x8006EA74: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8006EA80;
    }
    // 0x8006EA74: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8006EA78: b           L_8006EA80
    // 0x8006EA7C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8006EA80;
    // 0x8006EA7C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006EA80:
    // 0x8006EA80: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x8006EA84: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006EA88: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_8006EA8C:
    // 0x8006EA8C: slti        $at, $a3, 0x101
    ctx->r1 = SIGNED(ctx->r7) < 0X101 ? 1 : 0;
    // 0x8006EA90: bne         $at, $zero, L_8006EAA0
    if (ctx->r1 != 0) {
        // 0x8006EA94: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8006EAA0;
    }
    // 0x8006EA94: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8006EA98: b           L_8006EAA0
    // 0x8006EA9C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
        goto L_8006EAA0;
    // 0x8006EA9C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_8006EAA0:
    // 0x8006EAA0: bgez        $v0, L_8006EAB0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006EAA4: slti        $at, $a3, 0x101
        ctx->r1 = SIGNED(ctx->r7) < 0X101 ? 1 : 0;
            goto L_8006EAB0;
    }
    // 0x8006EAA4: slti        $at, $a3, 0x101
    ctx->r1 = SIGNED(ctx->r7) < 0X101 ? 1 : 0;
    // 0x8006EAA8: b           L_8006EACC
    // 0x8006EAAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_8006EACC;
    // 0x8006EAAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8006EAB0:
    // 0x8006EAB0: bne         $at, $zero, L_8006EAC0
    if (ctx->r1 != 0) {
        // 0x8006EAB4: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8006EAC0;
    }
    // 0x8006EAB4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8006EAB8: b           L_8006EAC0
    // 0x8006EABC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
        goto L_8006EAC0;
    // 0x8006EABC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_8006EAC0:
    // 0x8006EAC0: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8006EAC4: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8006EAC8: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
L_8006EACC:
    // 0x8006EACC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006EAD0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8006EAD4: sll         $t9, $a0, 24
    ctx->r25 = S32(ctx->r4 << 24);
    // 0x8006EAD8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006EADC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006EAE0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8006EAE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006EAE8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8006EAEC: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8006EAF0: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x8006EAF4: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x8006EAF8: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x8006EAFC: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x8006EB00: or          $t6, $t2, $t7
    ctx->r14 = ctx->r10 | ctx->r15;
    // 0x8006EB04: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8006EB08: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006EB0C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8006EB10: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x8006EB14: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006EB18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006EB1C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8006EB20: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006EB24: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006EB28: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    // 0x8006EB2C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006EB30: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006EB34: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8006EB38: bne         $at, $zero, L_8006EBBC
    if (ctx->r1 != 0) {
        // 0x8006EB3C: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_8006EBBC;
    }
    // 0x8006EB3C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006EB40: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x8006EB44: bne         $a3, $at, L_8006EB74
    if (ctx->r7 != ctx->r1) {
        // 0x8006EB48: lui         $t8, 0xB900
        ctx->r24 = S32(0XB900 << 16);
            goto L_8006EB74;
    }
    // 0x8006EB48: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8006EB4C: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006EB50: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8006EB54: lui         $t7, 0xF0A
    ctx->r15 = S32(0XF0A << 16);
    // 0x8006EB58: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006EB5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006EB60: ori         $t7, $t7, 0x7008
    ctx->r15 = ctx->r15 | 0X7008;
    // 0x8006EB64: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8006EB68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006EB6C: b           L_8006EB94
    // 0x8006EB70: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8006EB94;
    // 0x8006EB70: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8006EB74:
    // 0x8006EB74: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006EB78: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8006EB7C: ori         $t9, $t9, 0x4A50
    ctx->r25 = ctx->r25 | 0X4A50;
    // 0x8006EB80: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006EB84: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006EB88: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8006EB8C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006EB90: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8006EB94:
    // 0x8006EB94: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006EB98: lui         $t6, 0xFC50
    ctx->r14 = S32(0XFC50 << 16);
    // 0x8006EB9C: lui         $t8, 0x44FE
    ctx->r24 = S32(0X44FE << 16);
    // 0x8006EBA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006EBA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006EBA8: ori         $t8, $t8, 0x7339
    ctx->r24 = ctx->r24 | 0X7339;
    // 0x8006EBAC: ori         $t6, $t6, 0xFEA1
    ctx->r14 = ctx->r14 | 0XFEA1;
    // 0x8006EBB0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006EBB4: jr          $ra
    // 0x8006EBB8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    return;
    // 0x8006EBB8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8006EBBC:
    // 0x8006EBBC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006EBC0: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8006EBC4: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x8006EBC8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006EBCC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006EBD0: ori         $t6, $t6, 0x4A50
    ctx->r14 = ctx->r14 | 0X4A50;
    // 0x8006EBD4: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8006EBD8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006EBDC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8006EBE0: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006EBE4: lui         $t7, 0x4466
    ctx->r15 = S32(0X4466 << 16);
    // 0x8006EBE8: lui         $t9, 0xFC30
    ctx->r25 = S32(0XFC30 << 16);
    // 0x8006EBEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006EBF0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006EBF4: ori         $t9, $t9, 0xB261
    ctx->r25 = ctx->r25 | 0XB261;
    // 0x8006EBF8: ori         $t7, $t7, 0x4924
    ctx->r15 = ctx->r15 | 0X4924;
    // 0x8006EBFC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8006EC00: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006EC04: jr          $ra
    // 0x8006EC08: nop

    return;
    // 0x8006EC08: nop

;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF1B0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800CF1B4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800CF1B8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800CF1BC: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x800CF1C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CF1C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CF1C8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800CF1CC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800CF1D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CF1D4: bne         $v1, $v0, L_800CF1E8
    if (ctx->r3 != ctx->r2) {
        // 0x800CF1D8: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_800CF1E8;
    }
    // 0x800CF1D8: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800CF1DC: lui         $s3, 0x8010
    ctx->r19 = S32(0X8010 << 16);
    // 0x800CF1E0: b           L_800CF1F0
    // 0x800CF1E4: addiu       $s3, $s3, 0x2664
    ctx->r19 = ADD32(ctx->r19, 0X2664);
        goto L_800CF1F0;
    // 0x800CF1E4: addiu       $s3, $s3, 0x2664
    ctx->r19 = ADD32(ctx->r19, 0X2664);
L_800CF1E8:
    // 0x800CF1E8: lui         $s3, 0x8010
    ctx->r19 = S32(0X8010 << 16);
    // 0x800CF1EC: addiu       $s3, $s3, 0x2650
    ctx->r19 = ADD32(ctx->r19, 0X2650);
L_800CF1F0:
    // 0x800CF1F0: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x800CF1F4: bne         $v0, $at, L_800CF204
    if (ctx->r2 != ctx->r1) {
        // 0x800CF1F8: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_800CF204;
    }
    // 0x800CF1F8: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x800CF1FC: b           L_800CF224
    // 0x800CF200: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_800CF224;
    // 0x800CF200: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800CF204:
    // 0x800CF204: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800CF208: beq         $v0, $at, L_800CF220
    if (ctx->r2 == ctx->r1) {
        // 0x800CF20C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_800CF220;
    }
    // 0x800CF20C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800CF210: beq         $v1, $v0, L_800CF220
    if (ctx->r3 == ctx->r2) {
        // 0x800CF214: nop
    
            goto L_800CF220;
    }
    // 0x800CF214: nop

    // 0x800CF218: b           L_800CF220
    // 0x800CF21C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_800CF220;
    // 0x800CF21C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800CF220:
    // 0x800CF220: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800CF224:
    // 0x800CF224: lw          $t8, 0x0($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800CF228: lw          $t9, 0x4($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800CF22C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800CF230: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800CF234: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800CF238: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800CF23C: beq         $v0, $at, L_800CF250
    if (ctx->r2 == ctx->r1) {
        // 0x800CF240: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_800CF250;
    }
    // 0x800CF240: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800CF244: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x800CF248: bnel        $v0, $at, L_800CF28C
    if (ctx->r2 != ctx->r1) {
        // 0x800CF24C: lw          $t2, 0x60($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
            goto L_800CF28C;
    }
    goto skip_0;
    // 0x800CF24C: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    skip_0:
L_800CF250:
    // 0x800CF250: lw          $t4, 0x40($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800CF254: bgtzl       $t4, L_800CF28C
    if (SIGNED(ctx->r12) > 0) {
        // 0x800CF258: lw          $t2, 0x60($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
            goto L_800CF28C;
    }
    goto skip_1;
    // 0x800CF258: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    skip_1:
    // 0x800CF25C: bltz        $t4, L_800CF26C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800CF260: lw          $t6, 0x60($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X60));
            goto L_800CF26C;
    }
    // 0x800CF260: lw          $t6, 0x60($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800CF264: b           L_800CF28C
    // 0x800CF268: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
        goto L_800CF28C;
    // 0x800CF268: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
L_800CF26C:
    // 0x800CF26C: lw          $t7, 0x64($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800CF270: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800CF274: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800CF278: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800CF27C: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800CF280: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800CF284: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800CF288: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
L_800CF28C:
    // 0x800CF28C: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800CF290: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x800CF294: bne         $t2, $zero, L_800CF2B0
    if (ctx->r10 != 0) {
        // 0x800CF298: lw          $a0, 0x60($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X60));
            goto L_800CF2B0;
    }
    // 0x800CF298: lw          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800CF29C: bnel        $t3, $zero, L_800CF2B4
    if (ctx->r11 != 0) {
        // 0x800CF2A0: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_800CF2B4;
    }
    goto skip_2;
    // 0x800CF2A0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x800CF2A4: lw          $t4, 0x24($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X24));
    // 0x800CF2A8: beql        $t4, $zero, L_800CF2EC
    if (ctx->r12 == 0) {
        // 0x800CF2AC: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_800CF2EC;
    }
    goto skip_3;
    // 0x800CF2AC: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_800CF2B0:
    // 0x800CF2B0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_800CF2B4:
    // 0x800CF2B4: lw          $a1, 0x64($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800CF2B8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800CF2BC: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800CF2C0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800CF2C4: jal         0x800BB7BC
    // 0x800CF2C8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x800CF2C8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x800CF2CC: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800CF2D0: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x800CF2D4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800CF2D8: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x800CF2DC: lw          $t1, 0x70($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800CF2E0: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x800CF2E4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800CF2E8: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_800CF2EC:
    // 0x800CF2EC: lw          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800CF2F0: lw          $a1, 0x64($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800CF2F4: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800CF2F8: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800CF2FC: jal         0x800BB7F8
    // 0x800CF300: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800CF300: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x800CF304: lw          $t1, 0x70($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800CF308: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x800CF30C: bltz        $v0, L_800CF3BC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CF310: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800CF3BC;
    }
    // 0x800CF310: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800CF314: bgtz        $v0, L_800CF324
    if (SIGNED(ctx->r2) > 0) {
        // 0x800CF318: nop
    
            goto L_800CF324;
    }
    // 0x800CF318: nop

    // 0x800CF31C: beql        $v1, $zero, L_800CF3C0
    if (ctx->r3 == 0) {
        // 0x800CF320: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800CF3C0;
    }
    goto skip_4;
    // 0x800CF320: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_800CF324:
    // 0x800CF324: blez        $s0, L_800CF3BC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800CF328: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_800CF3BC;
    }
    // 0x800CF328: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800CF32C: lw          $t2, 0x0($s1)
    ctx->r10 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800CF330: lw          $t3, 0x4($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800CF334: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800CF338: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800CF33C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800CF340: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800CF344: lw          $t6, 0x38($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X38));
L_800CF348:
    // 0x800CF348: lw          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800CF34C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800CF350: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800CF354: lw          $a3, 0x44($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800CF358: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CF35C: jal         0x800D1230
    // 0x800CF360: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x800CF360: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800CF364: lw          $t8, 0x50($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800CF368: lw          $t9, 0x54($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800CF36C: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x800CF370: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800CF374: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800CF378: lw          $t3, 0x5C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800CF37C: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x800CF380: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CF384: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x800CF388: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800CF38C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800CF390: lw          $t8, 0x0($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800CF394: lw          $t9, 0x4($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800CF398: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800CF39C: bltz        $t8, L_800CF3BC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800CF3A0: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_800CF3BC;
    }
    // 0x800CF3A0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800CF3A4: bgtz        $t8, L_800CF3B4
    if (SIGNED(ctx->r24) > 0) {
        // 0x800CF3A8: nop
    
            goto L_800CF3B4;
    }
    // 0x800CF3A8: nop

    // 0x800CF3AC: beql        $t9, $zero, L_800CF3C0
    if (ctx->r25 == 0) {
        // 0x800CF3B0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800CF3C0;
    }
    goto skip_5;
    // 0x800CF3B0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_800CF3B4:
    // 0x800CF3B4: bgtzl       $s0, L_800CF348
    if (SIGNED(ctx->r16) > 0) {
        // 0x800CF3B8: lw          $t6, 0x38($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X38));
            goto L_800CF348;
    }
    goto skip_6;
    // 0x800CF3B8: lw          $t6, 0x38($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X38));
    skip_6:
L_800CF3BC:
    // 0x800CF3BC: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_800CF3C0:
    // 0x800CF3C0: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x800CF3C4: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x800CF3C8: lw          $a0, 0x8($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800CF3CC: jal         0x800BDA40
    // 0x800CF3D0: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800CF3D0: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x800CF3D4: lw          $a1, 0x14($s1)
    ctx->r5 = S32(MEM_W(ctx->r17, 0X14));
    // 0x800CF3D8: lw          $a0, 0x24($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X24));
    // 0x800CF3DC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CF3E0: beq         $at, $zero, L_800CF3EC
    if (ctx->r1 == 0) {
        // 0x800CF3E4: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_800CF3EC;
    }
    // 0x800CF3E4: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x800CF3E8: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_800CF3EC:
    // 0x800CF3EC: bgezl       $a0, L_800CF430
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800CF3F0: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_800CF430;
    }
    goto skip_7;
    // 0x800CF3F0: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_7:
    // 0x800CF3F4: lw          $t6, 0x30($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X30));
    // 0x800CF3F8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800CF3FC: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x800CF400: bnel        $t7, $at, L_800CF430
    if (ctx->r15 != ctx->r1) {
        // 0x800CF404: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_800CF430;
    }
    goto skip_8;
    // 0x800CF404: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_8:
    // 0x800CF408: lw          $t8, 0x28($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X28));
    // 0x800CF40C: lw          $t9, 0xC($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0XC));
    // 0x800CF410: lw          $v0, 0x10($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X10));
    // 0x800CF414: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800CF418: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x800CF41C: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x800CF420: blez        $s0, L_800CF42C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800CF424: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_800CF42C;
    }
    // 0x800CF424: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x800CF428: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_800CF42C:
    // 0x800CF42C: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
L_800CF430:
    // 0x800CF430: lw          $s0, 0x1C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CF434: lw          $s1, 0x20($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CF438: lw          $s2, 0x24($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CF43C: lw          $s3, 0x28($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800CF440: jr          $ra
    // 0x800CF444: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800CF444: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void _loadOutputBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0A54: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D0A58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D0A5C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D0A60: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D0A64: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800D0A68: lw          $t6, 0x24($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X24));
    // 0x800D0A6C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D0A70: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800D0A74: beq         $t6, $zero, L_800D0C30
    if (ctx->r14 == 0) {
        // 0x800D0A78: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_800D0C30;
    }
    // 0x800D0A78: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D0A7C: lw          $t7, 0x4($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X4));
    // 0x800D0A80: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800D0A84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D0A88: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D0A8C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800D0A90: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800D0A94: jal         0x800D05E0
    // 0x800D0A98: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    _doModFunc(rdram, ctx);
        goto after_0;
    // 0x800D0A98: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    after_0:
    // 0x800D0A9C: lw          $t4, 0x38($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800D0AA0: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800D0AA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800D0AA8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800D0AAC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D0AB0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D0AB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D0AB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D0ABC: lw          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800D0AC0: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x800D0AC4: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D0AC8: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D0ACC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D0AD0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800D0AD4: nop

    // 0x800D0AD8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D0ADC: nop

    // 0x800D0AE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D0AE4: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D0AE8: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800D0AEC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800D0AF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D0AF4: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x800D0AF8: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x800D0AFC: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D0B00: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800D0B04: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800D0B08: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = S32(MEM_W(ctx->r2, 0X20));
    // 0x800D0B0C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D0B10: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800D0B14: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800D0B18: nop

    // 0x800D0B1C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800D0B20: nop

    // 0x800D0B24: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D0B28: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x800D0B2C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x800D0B30: lw          $t9, 0x18($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X18));
    // 0x800D0B34: lw          $t8, 0x4($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800D0B38: lw          $t7, 0x18($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X18));
    // 0x800D0B3C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800D0B40: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x800D0B44: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800D0B48: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800D0B4C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x800D0B50: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800D0B54: lw          $t9, 0x70($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800D0B58: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800D0B5C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800D0B60: subu        $a1, $t0, $t3
    ctx->r5 = SUB32(ctx->r8, ctx->r11);
    // 0x800D0B64: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800D0B68: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800D0B6C: addu        $a3, $t1, $t8
    ctx->r7 = ADD32(ctx->r9, ctx->r24);
    // 0x800D0B70: jal         0x800D08C8
    // 0x800D0B74: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _loadBuffer(rdram, ctx);
        goto after_1;
    // 0x800D0B74: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800D0B78: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800D0B7C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D0B80: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D0B84: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x800D0B88: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800D0B8C: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800D0B90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D0B94: lw          $t8, 0x68($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800D0B98: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x800D0B9C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800D0BA0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D0BA4: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800D0BA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D0BAC: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800D0BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D0BB4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x800D0BB8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800D0BBC: lw          $t5, 0x24($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800D0BC0: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D0BC4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800D0BC8: lw          $t7, 0x24($t5)
    ctx->r15 = S32(MEM_W(ctx->r13, 0X24));
    // 0x800D0BCC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800D0BD0: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800D0BD4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800D0BD8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D0BDC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800D0BE0: nop

    // 0x800D0BE4: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800D0BE8: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x800D0BEC: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800D0BF0: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800D0BF4: lw          $t7, 0x24($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800D0BF8: lw          $a0, 0x14($t7)
    ctx->r4 = S32(MEM_W(ctx->r15, 0X14));
    // 0x800D0BFC: jal         0x800BF6F0
    // 0x800D0C00: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D0C00: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800D0C04: lw          $t6, 0x30($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800D0C08: lw          $t1, 0x2C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800D0C0C: lw          $v1, 0x5C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800D0C10: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x800D0C14: lw          $t8, 0x24($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800D0C18: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x800D0C1C: lw          $t4, 0x18($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X18));
    // 0x800D0C20: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x800D0C24: subu        $t5, $t9, $s1
    ctx->r13 = SUB32(ctx->r25, ctx->r17);
    // 0x800D0C28: b           L_800D0C60
    // 0x800D0C2C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
        goto L_800D0C60;
    // 0x800D0C2C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
L_800D0C30:
    // 0x800D0C30: lw          $t6, 0x4($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800D0C34: lw          $t7, 0x18($t2)
    ctx->r15 = S32(MEM_W(ctx->r10, 0X18));
    // 0x800D0C38: lw          $t9, 0x70($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800D0C3C: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800D0C40: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800D0C44: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800D0C48: lw          $a2, 0x68($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800D0C4C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D0C50: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x800D0C54: jal         0x800D08C8
    // 0x800D0C58: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _loadBuffer(rdram, ctx);
        goto after_3;
    // 0x800D0C58: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x800D0C5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D0C60:
    // 0x800D0C60: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800D0C64: lw          $s0, 0x1C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800D0C68: lw          $s1, 0x20($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800D0C6C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800D0C70: jr          $ra
    // 0x800D0C74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D0C74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ms_add_internal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A8BC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8005A8C0: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8005A8C4: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x8005A8C8: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x8005A8CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8005A8D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005A8D4: addiu       $t1, $t1, -0x3E28
    ctx->r9 = ADD32(ctx->r9, -0X3E28);
    // 0x8005A8D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A8DC:
    // 0x8005A8DC: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8005A8E0: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x8005A8E4: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8005A8E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005A8EC: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x8005A8F0: beq         $a1, $t9, L_8005AA80
    if (ctx->r5 == ctx->r25) {
        // 0x8005A8F4: slti        $at, $t5, 0x28
        ctx->r1 = SIGNED(ctx->r13) < 0X28 ? 1 : 0;
            goto L_8005AA80;
    }
    // 0x8005A8F4: slti        $at, $t5, 0x28
    ctx->r1 = SIGNED(ctx->r13) < 0X28 ? 1 : 0;
    // 0x8005A8F8: bne         $at, $zero, L_8005A8DC
    if (ctx->r1 != 0) {
        // 0x8005A8FC: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8005A8DC;
    }
    // 0x8005A8FC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8005A900: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8005A904: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8005A908: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8005A90C: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x8005A910: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8005A914: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8005A918: lh          $a1, 0xC($v0)
    ctx->r5 = S32(MEM_H(ctx->r2, 0XC));
    // 0x8005A91C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8005A920: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005A924: andi        $t8, $a1, 0x40
    ctx->r24 = ctx->r5 & 0X40;
    // 0x8005A928: bne         $a3, $t8, L_8005A940
    if (ctx->r7 != ctx->r24) {
        // 0x8005A92C: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8005A940;
    }
    // 0x8005A92C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8005A930: lbu         $v1, 0x2C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2C);
    // 0x8005A934: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8005A938: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x8005A93C: andi        $v1, $t9, 0xFFFF
    ctx->r3 = ctx->r25 & 0XFFFF;
L_8005A940:
    // 0x8005A940: lh          $a2, 0xE($v0)
    ctx->r6 = S32(MEM_H(ctx->r2, 0XE));
    // 0x8005A944: addiu       $t2, $t2, 0x4D9C
    ctx->r10 = ADD32(ctx->r10, 0X4D9C);
    // 0x8005A948: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005A94C: andi        $t6, $a2, 0x40
    ctx->r14 = ctx->r6 & 0X40;
    // 0x8005A950: bne         $a3, $t6, L_8005A970
    if (ctx->r7 != ctx->r14) {
        // 0x8005A954: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8005A970;
    }
    // 0x8005A954: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8005A958: lbu         $t7, 0x2B($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2B);
    // 0x8005A95C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005A960: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8005A964: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8005A968: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x8005A96C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_8005A970:
    // 0x8005A970: bne         $a3, $a1, L_8005A998
    if (ctx->r7 != ctx->r5) {
        // 0x8005A974: nop
    
            goto L_8005A998;
    }
    // 0x8005A974: nop

    // 0x8005A978: lhu         $a1, 0x20($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X20);
    // 0x8005A97C: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x8005A980: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x8005A984: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8005A988: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x8005A98C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8005A990: addu        $a1, $t5, $at
    ctx->r5 = ADD32(ctx->r13, ctx->r1);
    // 0x8005A994: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
L_8005A998:
    // 0x8005A998: bne         $a3, $a2, L_8005A9BC
    if (ctx->r7 != ctx->r6) {
        // 0x8005A99C: lw          $a1, 0x0($sp)
        ctx->r5 = S32(MEM_W(ctx->r29, 0X0));
            goto L_8005A9BC;
    }
    // 0x8005A99C: lw          $a1, 0x0($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X0));
    // 0x8005A9A0: lhu         $a1, 0x1E($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X1E);
    // 0x8005A9A4: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x8005A9A8: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x8005A9AC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8005A9B0: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8005A9B4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8005A9B8: addu        $a1, $t6, $at
    ctx->r5 = ADD32(ctx->r14, ctx->r1);
L_8005A9BC:
    // 0x8005A9BC: lhu         $a2, 0x0($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X0);
    // 0x8005A9C0: addiu       $t3, $t3, 0x4DA0
    ctx->r11 = ADD32(ctx->r11, 0X4DA0);
    // 0x8005A9C4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005A9C8: sll         $a3, $a2, 1
    ctx->r7 = S32(ctx->r6 << 1);
    // 0x8005A9CC: addu        $t7, $t1, $a3
    ctx->r15 = ADD32(ctx->r9, ctx->r7);
    // 0x8005A9D0: sh          $a0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r4;
    // 0x8005A9D4: lhu         $t0, 0x0($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X0);
    // 0x8005A9D8: addu        $at, $at, $a3
    ctx->r1 = ADD32(ctx->r1, ctx->r7);
    // 0x8005A9DC: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x8005A9E0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005A9E4: sh          $t0, -0x3DD8($at)
    MEM_H(-0X3DD8, ctx->r1) = ctx->r8;
    // 0x8005A9E8: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x8005A9EC: bne         $at, $zero, L_8005A9FC
    if (ctx->r1 != 0) {
        // 0x8005A9F0: sh          $t8, 0x0($t2)
        MEM_H(0X0, ctx->r10) = ctx->r24;
            goto L_8005A9FC;
    }
    // 0x8005A9F0: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
L_8005A9F4:
    // 0x8005A9F4: b           L_8005A9F4
    pause_self(rdram);
    // 0x8005A9F8: nop

L_8005A9FC:
    // 0x8005A9FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005AA00: blez        $v1, L_8005AA80
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005AA04: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8005AA80;
    }
    // 0x8005AA04: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005AA08: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x8005AA0C: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x8005AA10: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x8005AA14: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x8005AA18: addiu       $t2, $t2, -0x3D88
    ctx->r10 = ADD32(ctx->r10, -0X3D88);
    // 0x8005AA1C: addiu       $t4, $t4, -0x33A0
    ctx->r12 = ADD32(ctx->r12, -0X33A0);
    // 0x8005AA20: lw          $t1, -0x29B8($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, -0X29B8));
    // 0x8005AA24: lw          $a3, -0x29BC($a3)
    ctx->r7 = S32(MEM_W(ctx->r7, -0X29BC));
L_8005AA28:
    // 0x8005AA28: lh          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_H(ctx->r5, 0X0));
    // 0x8005AA2C: sll         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8 << 1);
    // 0x8005AA30: addu        $t6, $t2, $v1
    ctx->r14 = ADD32(ctx->r10, ctx->r3);
    // 0x8005AA34: subu        $t5, $t9, $a3
    ctx->r13 = SUB32(ctx->r25, ctx->r7);
    // 0x8005AA38: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x8005AA3C: lh          $t7, 0x2($a1)
    ctx->r15 = S32(MEM_H(ctx->r5, 0X2));
    // 0x8005AA40: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x8005AA44: addu        $t9, $t4, $v1
    ctx->r25 = ADD32(ctx->r12, ctx->r3);
    // 0x8005AA48: andi        $t0, $t5, 0xFFFF
    ctx->r8 = ctx->r13 & 0XFFFF;
    // 0x8005AA4C: subu        $t8, $t7, $t1
    ctx->r24 = SUB32(ctx->r15, ctx->r9);
    // 0x8005AA50: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8005AA54: slti        $at, $t0, 0x4F3
    ctx->r1 = SIGNED(ctx->r8) < 0X4F3 ? 1 : 0;
    // 0x8005AA58: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x8005AA5C: bne         $at, $zero, L_8005AA6C
    if (ctx->r1 != 0) {
        // 0x8005AA60: sh          $t5, 0x0($t3)
        MEM_H(0X0, ctx->r11) = ctx->r13;
            goto L_8005AA6C;
    }
    // 0x8005AA60: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
L_8005AA64:
    // 0x8005AA64: b           L_8005AA64
    pause_self(rdram);
    // 0x8005AA68: nop

L_8005AA6C:
    // 0x8005AA6C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005AA70: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x8005AA74: slt         $at, $t8, $a0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005AA78: bne         $at, $zero, L_8005AA28
    if (ctx->r1 != 0) {
        // 0x8005AA7C: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8005AA28;
    }
    // 0x8005AA7C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
L_8005AA80:
    // 0x8005AA80: jr          $ra
    // 0x8005AA84: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8005AA84: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE8B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800BE8B8: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x800BE8BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE8C0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800BE8C4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800BE8C8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800BE8CC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800BE8D0: blez        $t6, L_800BE8E4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BE8D4: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_800BE8E4;
    }
    // 0x800BE8D4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800BE8D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BE8DC: b           L_800BE8F0
    // 0x800BE8E0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_800BE8F0;
    // 0x800BE8E0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_800BE8E4:
    // 0x800BE8E4: lw          $t8, 0x50($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800BE8E8: lw          $t9, 0x60($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X60));
    // 0x800BE8EC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800BE8F0:
    // 0x800BE8F0: lw          $t0, 0x18($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800BE8F4: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800BE8F8: beq         $at, $zero, L_800BE934
    if (ctx->r1 == 0) {
        // 0x800BE8FC: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800BE934;
    }
    // 0x800BE8FC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_800BE900:
    // 0x800BE900: lw          $t2, 0x4C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BE904: lw          $t1, 0x54($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800BE908: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BE90C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800BE910: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800BE914: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800BE918: beq         $t5, $at, L_800BE934
    if (ctx->r13 == ctx->r1) {
        // 0x800BE91C: nop
    
            goto L_800BE934;
    }
    // 0x800BE91C: nop

    // 0x800BE920: lw          $t6, 0x4C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BE924: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BE928: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800BE92C: bne         $at, $zero, L_800BE900
    if (ctx->r1 != 0) {
        // 0x800BE930: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_800BE900;
    }
    // 0x800BE930: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_800BE934:
    // 0x800BE934: lw          $t8, 0x4C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BE938: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800BE93C: bne         $t8, $at, L_800BE958
    if (ctx->r24 != ctx->r1) {
        // 0x800BE940: nop
    
            goto L_800BE958;
    }
    // 0x800BE940: nop

    // 0x800BE944: lw          $t0, 0x5C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800BE948: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BE94C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800BE950: b           L_800BEB08
    // 0x800BE954: lw          $v0, 0x1C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_800BEB08;
    // 0x800BE954: lw          $v0, 0x1C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1C));
L_800BE958:
    // 0x800BE958: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800BE95C:
    // 0x800BE95C: lw          $t2, 0x20($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BE960: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x800BE964: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x800BE968: lw          $t3, 0x20($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BE96C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800BE970: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x800BE974: bne         $at, $zero, L_800BE95C
    if (ctx->r1 != 0) {
        // 0x800BE978: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800BE95C;
    }
    // 0x800BE978: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800BE97C: lw          $t5, 0x4C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BE980: lw          $t7, 0x64($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800BE984: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800BE988: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800BE98C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800BE990: lw          $t8, 0x4C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BE994: lw          $t2, 0x64($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800BE998: lw          $t0, 0x58($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800BE99C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BE9A0: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800BE9A4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800BE9A8: lw          $t1, 0x0($t2)
    ctx->r9 = S32(MEM_W(ctx->r10, 0X0));
    // 0x800BE9AC: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BE9B0: beq         $at, $zero, L_800BEA84
    if (ctx->r1 == 0) {
        // 0x800BE9B4: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_800BEA84;
    }
    // 0x800BE9B4: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800BE9B8: beq         $at, $zero, L_800BEA84
    if (ctx->r1 == 0) {
        // 0x800BE9BC: nop
    
            goto L_800BEA84;
    }
    // 0x800BE9BC: nop

L_800BE9C0:
    // 0x800BE9C0: lw          $t4, 0x4C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BE9C4: lw          $t3, 0x54($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800BE9C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BE9CC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800BE9D0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800BE9D4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800BE9D8: bne         $t7, $at, L_800BEA50
    if (ctx->r15 != ctx->r1) {
        // 0x800BE9DC: nop
    
            goto L_800BEA50;
    }
    // 0x800BE9DC: nop

    // 0x800BE9E0: lw          $t2, 0x44($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BE9E4: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x800BE9E8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800BE9EC: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x800BE9F0: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800BE9F4: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x800BE9F8: lw          $t5, 0x44($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BE9FC: lw          $t4, 0x54($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800BEA00: lw          $t9, 0x4C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BEA04: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800BEA08: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800BEA0C: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x800BEA10: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800BEA14: lw          $a1, 0x44($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BEA18: jal         0x800BEB18
    // 0x800BEA1C: lw          $a0, 0x50($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X50));
    static_5_800BEB18(rdram, ctx);
        goto after_0;
    // 0x800BEA1C: lw          $a0, 0x50($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X50));
    after_0:
    // 0x800BEA20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BEA24: lw          $t2, 0x1C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BEA28: beq         $t2, $zero, L_800BEA38
    if (ctx->r10 == 0) {
        // 0x800BEA2C: nop
    
            goto L_800BEA38;
    }
    // 0x800BEA2C: nop

    // 0x800BEA30: b           L_800BEB08
    // 0x800BEA34: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800BEB08;
    // 0x800BEA34: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800BEA38:
    // 0x800BEA38: lw          $t3, 0x4C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BEA3C: lw          $t0, 0x64($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800BEA40: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800BEA44: lw          $t8, 0x0($t0)
    ctx->r24 = S32(MEM_W(ctx->r8, 0X0));
    // 0x800BEA48: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800BEA4C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_800BEA50:
    // 0x800BEA50: lw          $t5, 0x4C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BEA54: lw          $t9, 0x64($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800BEA58: lw          $t6, 0x58($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800BEA5C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800BEA60: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800BEA64: lw          $t7, 0x0($t9)
    ctx->r15 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800BEA68: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BEA6C: beq         $at, $zero, L_800BEA84
    if (ctx->r1 == 0) {
        // 0x800BEA70: nop
    
            goto L_800BEA84;
    }
    // 0x800BEA70: nop

    // 0x800BEA74: lw          $t2, 0x4C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BEA78: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800BEA7C: bne         $at, $zero, L_800BE9C0
    if (ctx->r1 != 0) {
        // 0x800BEA80: nop
    
            goto L_800BE9C0;
    }
    // 0x800BEA80: nop

L_800BEA84:
    // 0x800BEA84: lw          $t3, 0x48($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800BEA88: lw          $t8, 0x5C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800BEA8C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800BEA90: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800BEA94: lw          $t1, 0x4C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BEA98: bne         $t1, $at, L_800BEACC
    if (ctx->r9 != ctx->r1) {
        // 0x800BEA9C: nop
    
            goto L_800BEACC;
    }
    // 0x800BEA9C: nop

    // 0x800BEAA0: lw          $t5, 0x64($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800BEAA4: lw          $t0, 0x58($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800BEAA8: lw          $t4, 0x0($t5)
    ctx->r12 = S32(MEM_W(ctx->r13, 0X0));
    // 0x800BEAAC: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BEAB0: beq         $at, $zero, L_800BEACC
    if (ctx->r1 == 0) {
        // 0x800BEAB4: nop
    
            goto L_800BEACC;
    }
    // 0x800BEAB4: nop

    // 0x800BEAB8: lw          $t9, 0x44($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BEABC: lw          $t6, 0x68($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800BEAC0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800BEAC4: b           L_800BEB08
    // 0x800BEAC8: lw          $v0, 0x1C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_800BEB08;
    // 0x800BEAC8: lw          $v0, 0x1C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1C));
L_800BEACC:
    // 0x800BEACC: lw          $t3, 0x44($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BEAD0: lw          $t2, 0x54($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800BEAD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BEAD8: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800BEADC: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800BEAE0: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x800BEAE4: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800BEAE8: lw          $a1, 0x44($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BEAEC: lw          $a0, 0x50($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800BEAF0: jal         0x800BEB18
    // 0x800BEAF4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    static_5_800BEB18(rdram, ctx);
        goto after_1;
    // 0x800BEAF4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800BEAF8: lw          $t5, 0x68($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800BEAFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BEB00: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800BEB04: lw          $v0, 0x1C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1C));
L_800BEB08:
    // 0x800BEB08: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800BEB0C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800BEB10: jr          $ra
    // 0x800BEB14: nop

    return;
    // 0x800BEB14: nop

;}
RECOMP_FUNC void keepaway(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097438: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8009743C: addiu       $t7, $t7, 0x6F30
    ctx->r15 = ADD32(ctx->r15, 0X6F30);
    // 0x80097440: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x80097444: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80097448: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8009744C: lw          $t3, 0x4($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80097450: lw          $t9, 0xC($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0XC));
    // 0x80097454: lw          $t2, 0x0($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80097458: lw          $t8, 0x8($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X8));
    // 0x8009745C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80097460: subu        $t0, $t9, $t3
    ctx->r8 = SUB32(ctx->r25, ctx->r11);
    // 0x80097464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097468: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8009746C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80097470: negu        $a0, $t0
    ctx->r4 = SUB32(0, ctx->r8);
    // 0x80097474: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80097478: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009747C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80097480: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80097484: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80097488: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8009748C: jal         0x80091A50
    // 0x80097490: subu        $s1, $t8, $t2
    ctx->r17 = SUB32(ctx->r24, ctx->r10);
    ksgn(rdram, ctx);
        goto after_0;
    // 0x80097490: subu        $s1, $t8, $t2
    ctx->r17 = SUB32(ctx->r24, ctx->r10);
    after_0:
    // 0x80097494: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80097498: jal         0x80091A50
    // 0x8009749C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    ksgn(rdram, ctx);
        goto after_1;
    // 0x8009749C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800974A0: lw          $a3, 0x48($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800974A4: lw          $t0, 0x40($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800974A8: lw          $t1, 0x3C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800974AC: lw          $t2, 0x34($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800974B0: blez        $s1, L_800974C0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800974B4: lw          $t3, 0x30($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X30));
            goto L_800974C0;
    }
    // 0x800974B4: lw          $t3, 0x30($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800974B8: b           L_800974C4
    // 0x800974BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800974C4;
    // 0x800974BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800974C0:
    // 0x800974C0: negu        $a0, $s1
    ctx->r4 = SUB32(0, ctx->r17);
L_800974C4:
    // 0x800974C4: blez        $t0, L_800974D4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800974C8: lw          $v1, 0x20($sp)
        ctx->r3 = S32(MEM_W(ctx->r29, 0X20));
            goto L_800974D4;
    }
    // 0x800974C8: lw          $v1, 0x20($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800974CC: b           L_800974D4
    // 0x800974D0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_800974D4;
    // 0x800974D0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800974D4:
    // 0x800974D4: slt         $a2, $v1, $a0
    ctx->r6 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800974D8: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x800974DC: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800974E0: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
L_800974E4:
    // 0x800974E4: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x800974E8: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800974EC: subu        $t5, $v1, $t2
    ctx->r13 = SUB32(ctx->r3, ctx->r10);
    // 0x800974F0: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800974F4: subu        $t7, $a0, $t3
    ctx->r15 = SUB32(ctx->r4, ctx->r11);
    // 0x800974F8: addu        $t9, $v1, $t1
    ctx->r25 = ADD32(ctx->r3, ctx->r9);
    // 0x800974FC: addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // 0x80097500: mflo        $t6
    ctx->r14 = lo;
    // 0x80097504: nop

    // 0x80097508: nop

    // 0x8009750C: multu       $s1, $t7
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097510: mflo        $t8
    ctx->r24 = lo;
    // 0x80097514: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80097518: bnel        $at, $zero, L_80097554
    if (ctx->r1 != 0) {
        // 0x8009751C: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_80097554;
    }
    goto skip_0;
    // 0x8009751C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_0:
    // 0x80097520: bne         $a2, $zero, L_8009753C
    if (ctx->r6 != 0) {
        // 0x80097524: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8009753C;
    }
    // 0x80097524: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80097528: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x8009752C: andi        $t5, $a2, 0xFF
    ctx->r13 = ctx->r6 & 0XFF;
    // 0x80097530: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80097534: b           L_800974E4
    // 0x80097538: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
        goto L_800974E4;
    // 0x80097538: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_8009753C:
    // 0x8009753C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80097540: xori        $a2, $a1, 0x1
    ctx->r6 = ctx->r5 ^ 0X1;
    // 0x80097544: andi        $t5, $a2, 0xFF
    ctx->r13 = ctx->r6 & 0XFF;
    // 0x80097548: b           L_800974E4
    // 0x8009754C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
        goto L_800974E4;
    // 0x8009754C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80097550: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_80097554:
    // 0x80097554: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80097558: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8009755C: jr          $ra
    // 0x80097560: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80097560: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80051850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051858: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005185C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051860: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80051864: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80051868: sw          $t6, 0x38B0($at)
    MEM_W(0X38B0, ctx->r1) = ctx->r14;
    // 0x8005186C: addiu       $a1, $a1, -0x4728
    ctx->r5 = ADD32(ctx->r5, -0X4728);
    // 0x80051870: addiu       $a0, $a0, -0x4720
    ctx->r4 = ADD32(ctx->r4, -0X4720);
    // 0x80051874: jal         0x800BB760
    // 0x80051878: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80051878: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8005187C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80051880: addiu       $a0, $a0, -0x4720
    ctx->r4 = ADD32(ctx->r4, -0X4720);
    // 0x80051884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051888: jal         0x800BB610
    // 0x8005188C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8005188C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80051890: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80051894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051898: jr          $ra
    // 0x8005189C: nop

    return;
    // 0x8005189C: nop

;}
RECOMP_FUNC void insertspritestat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092658: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009265C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80092660: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80092664: slti        $at, $a0, 0x400
    ctx->r1 = SIGNED(ctx->r4) < 0X400 ? 1 : 0;
    // 0x80092668: beq         $at, $zero, L_80092688
    if (ctx->r1 == 0) {
        // 0x8009266C: lui         $t1, 0x8027
        ctx->r9 = S32(0X8027 << 16);
            goto L_80092688;
    }
    // 0x8009266C: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x80092670: addiu       $t1, $t1, 0x2858
    ctx->r9 = ADD32(ctx->r9, 0X2858);
    // 0x80092674: lh          $v0, 0x800($t1)
    ctx->r2 = S32(MEM_H(ctx->r9, 0X800));
    // 0x80092678: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8009267C: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x80092680: bne         $t0, $v0, L_80092690
    if (ctx->r8 != ctx->r2) {
        // 0x80092684: sll         $v1, $v0, 16
        ctx->r3 = S32(ctx->r2 << 16);
            goto L_80092690;
    }
    // 0x80092684: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
L_80092688:
    // 0x80092688: jr          $ra
    // 0x8009268C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8009268C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80092690:
    // 0x80092690: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092694: sll         $a1, $t8, 1
    ctx->r5 = S32(ctx->r24 << 1);
    // 0x80092698: addiu       $t9, $t9, 0x5F40
    ctx->r25 = ADD32(ctx->r25, 0X5F40);
    // 0x8009269C: addu        $a2, $a1, $t9
    ctx->r6 = ADD32(ctx->r5, ctx->r25);
    // 0x800926A0: lh          $t3, 0x0($a2)
    ctx->r11 = S32(MEM_H(ctx->r6, 0X0));
    // 0x800926A4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800926A8: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800926AC: sh          $t3, 0x800($t1)
    MEM_H(0X800, ctx->r9) = ctx->r11;
    // 0x800926B0: lh          $v0, 0x800($t1)
    ctx->r2 = S32(MEM_H(ctx->r9, 0X800));
    // 0x800926B4: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800926B8: addu        $a3, $t1, $t7
    ctx->r7 = ADD32(ctx->r9, ctx->r15);
    // 0x800926BC: bltz        $v0, L_800926D8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800926C0: subu        $t3, $t3, $v1
        ctx->r11 = SUB32(ctx->r11, ctx->r3);
            goto L_800926D8;
    }
    // 0x800926C0: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x800926C4: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x800926C8: addiu       $t2, $t2, 0x4000
    ctx->r10 = ADD32(ctx->r10, 0X4000);
    // 0x800926CC: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x800926D0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800926D4: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
L_800926D8:
    // 0x800926D8: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x800926DC: addiu       $t2, $t2, 0x4000
    ctx->r10 = ADD32(ctx->r10, 0X4000);
    // 0x800926E0: addu        $t6, $t2, $a1
    ctx->r14 = ADD32(ctx->r10, ctx->r5);
    // 0x800926E4: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
    // 0x800926E8: lh          $v0, 0x0($a3)
    ctx->r2 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800926EC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800926F0: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x800926F4: bltz        $v0, L_80092708
    if (SIGNED(ctx->r2) < 0) {
        // 0x800926F8: sh          $v0, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r2;
            goto L_80092708;
    }
    // 0x800926F8: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x800926FC: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80092700: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80092704: sh          $v1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r3;
L_80092708:
    // 0x80092708: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8009270C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80092710: sh          $v1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r3;
    // 0x80092714: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80092718: sh          $a0, 0x6BBA($at)
    MEM_H(0X6BBA, ctx->r1) = ctx->r4;
    // 0x8009271C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80092720: jr          $ra
    // 0x80092724: nop

    return;
    // 0x80092724: nop

;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE100: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE104: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BE108: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x800BE10C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BE110: lw          $t7, 0x2C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BE114: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BE118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE11C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BE120: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800BE124: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800BE128: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800BE12C: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x800BE130: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800BE134: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
    // 0x800BE138: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x800BE13C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BE140: beq         $t4, $at, L_800BE170
    if (ctx->r12 == ctx->r1) {
        // 0x800BE144: nop
    
            goto L_800BE170;
    }
    // 0x800BE144: nop

    // 0x800BE148: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x800BE14C: blez        $t5, L_800BE160
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BE150: nop
    
            goto L_800BE160;
    }
    // 0x800BE150: nop

    // 0x800BE154: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BE158: b           L_800BE194
    // 0x800BE15C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_800BE194;
    // 0x800BE15C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_800BE160:
    // 0x800BE160: lw          $t7, 0x28($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BE164: lw          $t9, 0x60($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, 0X60));
    // 0x800BE168: b           L_800BE194
    // 0x800BE16C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_800BE194;
    // 0x800BE16C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800BE170:
    // 0x800BE170: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x800BE174: blez        $t2, L_800BE188
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BE178: nop
    
            goto L_800BE188;
    }
    // 0x800BE178: nop

    // 0x800BE17C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800BE180: b           L_800BE194
    // 0x800BE184: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
        goto L_800BE194;
    // 0x800BE184: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_800BE188:
    // 0x800BE188: lw          $t6, 0x28($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BE18C: lw          $t0, 0x60($t6)
    ctx->r8 = S32(MEM_W(ctx->r14, 0X60));
    // 0x800BE190: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800BE194:
    // 0x800BE194: lbu         $t3, 0x25($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X25);
    // 0x800BE198: lw          $t4, 0x18($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800BE19C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BE1A0: beq         $at, $zero, L_800BE1C0
    if (ctx->r1 == 0) {
        // 0x800BE1A4: nop
    
            goto L_800BE1C0;
    }
    // 0x800BE1A4: nop

    // 0x800BE1A8: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x800BE1AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BE1B0: beq         $t5, $at, L_800BE1C0
    if (ctx->r13 == ctx->r1) {
        // 0x800BE1B4: nop
    
            goto L_800BE1C0;
    }
    // 0x800BE1B4: nop

    // 0x800BE1B8: b           L_800BE328
    // 0x800BE1BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800BE328;
    // 0x800BE1BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800BE1C0:
    // 0x800BE1C0: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x800BE1C4: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x800BE1C8: lw          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800BE1CC: sh          $at, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r1;
    // 0x800BE1D0: lw          $t1, 0x40($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800BE1D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BE1D8: bne         $t1, $at, L_800BE1F8
    if (ctx->r9 != ctx->r1) {
        // 0x800BE1DC: nop
    
            goto L_800BE1F8;
    }
    // 0x800BE1DC: nop

    // 0x800BE1E0: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x800BE1E4: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BE1E8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800BE1EC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800BE1F0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800BE1F4: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_800BE1F8:
    // 0x800BE1F8: lw          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BE1FC: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x800BE200: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800BE204: jal         0x800BE338
    // 0x800BE208: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    __osBlockSum(rdram, ctx);
        goto after_0;
    // 0x800BE208: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x800BE20C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BE210: lw          $t9, 0x1C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BE214: beq         $t9, $zero, L_800BE224
    if (ctx->r25 == 0) {
        // 0x800BE218: nop
    
            goto L_800BE224;
    }
    // 0x800BE218: nop

    // 0x800BE21C: b           L_800BE328
    // 0x800BE220: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800BE328;
    // 0x800BE220: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800BE224:
    // 0x800BE224: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x800BE228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BE22C: bne         $t8, $at, L_800BE23C
    if (ctx->r24 != ctx->r1) {
        // 0x800BE230: nop
    
            goto L_800BE23C;
    }
    // 0x800BE230: nop

    // 0x800BE234: b           L_800BE328
    // 0x800BE238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BE328;
    // 0x800BE238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BE23C:
    // 0x800BE23C: lw          $t2, 0x28($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BE240: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x800BE244: lw          $t1, 0x60($t2)
    ctx->r9 = S32(MEM_W(ctx->r10, 0X60));
    // 0x800BE248: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800BE24C: bne         $at, $zero, L_800BE2E4
    if (ctx->r1 != 0) {
        // 0x800BE250: nop
    
            goto L_800BE2E4;
    }
    // 0x800BE250: nop

L_800BE254:
    // 0x800BE254: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x800BE258: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x800BE25C: lw          $t4, 0x2C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BE260: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800BE264: sh          $t3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r11;
    // 0x800BE268: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800BE26C: lhu         $at, 0x0($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X0);
    // 0x800BE270: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800BE274: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800BE278: sh          $at, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r1;
    // 0x800BE27C: lbu         $t3, 0x21($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X21);
    // 0x800BE280: lw          $t1, 0x2C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BE284: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800BE288: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x800BE28C: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x800BE290: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    // 0x800BE294: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800BE298: lbu         $a1, 0x21($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X21);
    // 0x800BE29C: jal         0x800BE338
    // 0x800BE2A0: lw          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X28));
    __osBlockSum(rdram, ctx);
        goto after_1;
    // 0x800BE2A0: lw          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X28));
    after_1:
    // 0x800BE2A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BE2A8: lw          $t5, 0x1C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BE2AC: beq         $t5, $zero, L_800BE2BC
    if (ctx->r13 == 0) {
        // 0x800BE2B0: nop
    
            goto L_800BE2BC;
    }
    // 0x800BE2B0: nop

    // 0x800BE2B4: b           L_800BE328
    // 0x800BE2B8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800BE328;
    // 0x800BE2B8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800BE2BC:
    // 0x800BE2BC: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x800BE2C0: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x800BE2C4: bne         $t8, $t0, L_800BE2E4
    if (ctx->r24 != ctx->r8) {
        // 0x800BE2C8: nop
    
            goto L_800BE2E4;
    }
    // 0x800BE2C8: nop

    // 0x800BE2CC: lw          $t2, 0x28($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BE2D0: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x800BE2D4: lw          $t3, 0x60($t2)
    ctx->r11 = S32(MEM_W(ctx->r10, 0X60));
    // 0x800BE2D8: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BE2DC: beq         $at, $zero, L_800BE254
    if (ctx->r1 == 0) {
        // 0x800BE2E0: nop
    
            goto L_800BE254;
    }
    // 0x800BE2E0: nop

L_800BE2E4:
    // 0x800BE2E4: lw          $t6, 0x28($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BE2E8: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x800BE2EC: lw          $t7, 0x60($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X60));
    // 0x800BE2F0: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BE2F4: bne         $at, $zero, L_800BE314
    if (ctx->r1 != 0) {
        // 0x800BE2F8: nop
    
            goto L_800BE314;
    }
    // 0x800BE2F8: nop

    // 0x800BE2FC: lbu         $t8, 0x25($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X25);
    // 0x800BE300: lw          $t5, 0x2C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BE304: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800BE308: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800BE30C: addu        $t2, $t5, $t0
    ctx->r10 = ADD32(ctx->r13, ctx->r8);
    // 0x800BE310: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
L_800BE314:
    // 0x800BE314: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x800BE318: lhu         $at, 0x0($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0X0);
    // 0x800BE31C: lw          $t9, 0x3C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800BE320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BE324: sh          $at, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r1;
L_800BE328:
    // 0x800BE328: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800BE32C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE330: jr          $ra
    // 0x800BE334: nop

    return;
    // 0x800BE334: nop

;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C675C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C6760: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x800C6764: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x800C6768: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x800C676C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800C6770: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C6774:
    // 0x800C6774: lw          $t7, 0x0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C6778: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800C677C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800C6780: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x800C6784: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800C6788: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800C678C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x800C6790: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x800C6794: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x800C6798: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x800C679C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800C67A0: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x800C67A4: lw          $t6, 0x0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C67A8: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800C67AC: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x800C67B0: bne         $at, $zero, L_800C6774
    if (ctx->r1 != 0) {
        // 0x800C67B4: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_800C6774;
    }
    // 0x800C67B4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800C67B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C67BC: jr          $ra
    // 0x800C67C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C67C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80050A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050A10: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80050A14: lhu         $t6, 0x3778($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X3778);
    // 0x80050A18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80050A20: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x80050A24: beq         $at, $zero, L_80050D74
    if (ctx->r1 == 0) {
        // 0x80050A28: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80050D74;
    }
    // 0x80050A28: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80050A2C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80050A30: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050A34: addu        $at, $at, $t6
    gpr jr_addend_80050A3C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80050A38: lw          $t6, 0x384C($at)
    ctx->r14 = ADD32(ctx->r1, 0X384C);
    // 0x80050A3C: jr          $t6
    // 0x80050A40: nop

    switch (jr_addend_80050A3C >> 2) {
        case 0: goto L_80050A44; break;
        case 1: goto L_80050AE4; break;
        case 2: goto L_80050B54; break;
        case 3: goto L_80050BA8; break;
        case 4: goto L_80050C18; break;
        case 5: goto L_80050C88; break;
        case 6: goto L_80050D44; break;
        default: switch_error(__func__, 0x80050A3C, 0x8010384C);
    }
    // 0x80050A40: nop

L_80050A44:
    // 0x80050A44: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050A48: lh          $v0, 0x3774($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X3774));
    // 0x80050A4C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80050A50: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80050A54: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80050A58: bne         $at, $zero, L_80050A68
    if (ctx->r1 != 0) {
        // 0x80050A5C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80050A68;
    }
    // 0x80050A5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80050A60: b           L_80050A74
    // 0x80050A64: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_80050A74;
    // 0x80050A64: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80050A68:
    // 0x80050A68: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80050A6C: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80050A70: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
L_80050A74:
    // 0x80050A74: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80050A78: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x80050A7C: sra         $t0, $a2, 16
    ctx->r8 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80050A80: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80050A84: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80050A88: jal         0x8006E994
    // 0x80050A8C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_0;
    // 0x80050A8C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_0:
    // 0x80050A90: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80050A94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050A98: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050A9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050AA0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050AA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050AA8: addiu       $t1, $zero, 0xE6D
    ctx->r9 = ADD32(0, 0XE6D);
    // 0x80050AAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050AB0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050AB4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80050AB8: jal         0x8005D13C
    // 0x80050ABC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_1;
    // 0x80050ABC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80050AC0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050AC4: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050AC8: xori        $t2, $a0, 0x3C
    ctx->r10 = ctx->r4 ^ 0X3C;
    // 0x80050ACC: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80050AD0: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80050AD4: jal         0x8004F96C
    // 0x80050AD8: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_2;
    // 0x80050AD8: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_2:
    // 0x80050ADC: b           L_80050DF8
    // 0x80050AE0: nop

        goto L_80050DF8;
    // 0x80050AE0: nop

L_80050AE4:
    // 0x80050AE4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80050AE8: lh          $t5, 0x3774($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X3774));
    // 0x80050AEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050AF0: bnel        $t5, $at, L_80050B04
    if (ctx->r13 != ctx->r1) {
        // 0x80050AF4: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80050B04;
    }
    goto skip_0;
    // 0x80050AF4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_0:
    // 0x80050AF8: jal         0x80058E1C
    // 0x80050AFC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    sound(rdram, ctx);
        goto after_3;
    // 0x80050AFC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_3:
    // 0x80050B00: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80050B04:
    // 0x80050B04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050B08: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050B0C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050B10: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050B14: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050B18: addiu       $t6, $zero, 0xE6E
    ctx->r14 = ADD32(0, 0XE6E);
    // 0x80050B1C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050B20: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050B24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80050B28: jal         0x8005D13C
    // 0x80050B2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_4;
    // 0x80050B2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x80050B30: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050B34: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050B38: xori        $t7, $a0, 0x3C
    ctx->r15 = ctx->r4 ^ 0X3C;
    // 0x80050B3C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80050B40: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80050B44: jal         0x8004F96C
    // 0x80050B48: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_5;
    // 0x80050B48: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_5:
    // 0x80050B4C: b           L_80050DF8
    // 0x80050B50: nop

        goto L_80050DF8;
    // 0x80050B50: nop

L_80050B54:
    // 0x80050B54: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80050B58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050B5C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050B60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050B64: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050B68: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050B6C: addiu       $t0, $zero, 0xE6F
    ctx->r8 = ADD32(0, 0XE6F);
    // 0x80050B70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050B74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050B78: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80050B7C: jal         0x8005D13C
    // 0x80050B80: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_6;
    // 0x80050B80: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x80050B84: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050B88: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050B8C: xori        $t1, $a0, 0x3C
    ctx->r9 = ctx->r4 ^ 0X3C;
    // 0x80050B90: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80050B94: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80050B98: jal         0x8004F96C
    // 0x80050B9C: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_7;
    // 0x80050B9C: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_7:
    // 0x80050BA0: b           L_80050DF8
    // 0x80050BA4: nop

        goto L_80050DF8;
    // 0x80050BA4: nop

L_80050BA8:
    // 0x80050BA8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80050BAC: lh          $t4, 0x3774($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, 0X3774));
    // 0x80050BB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050BB4: bnel        $t4, $at, L_80050BC8
    if (ctx->r12 != ctx->r1) {
        // 0x80050BB8: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80050BC8;
    }
    goto skip_1;
    // 0x80050BB8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_1:
    // 0x80050BBC: jal         0x80058E1C
    // 0x80050BC0: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    sound(rdram, ctx);
        goto after_8;
    // 0x80050BC0: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_8:
    // 0x80050BC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80050BC8:
    // 0x80050BC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050BCC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050BD0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050BD4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050BD8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050BDC: addiu       $t5, $zero, 0xE70
    ctx->r13 = ADD32(0, 0XE70);
    // 0x80050BE0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050BE4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050BE8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80050BEC: jal         0x8005D13C
    // 0x80050BF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_9;
    // 0x80050BF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x80050BF4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050BF8: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050BFC: xori        $t6, $a0, 0x3C
    ctx->r14 = ctx->r4 ^ 0X3C;
    // 0x80050C00: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80050C04: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80050C08: jal         0x8004F96C
    // 0x80050C0C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_10;
    // 0x80050C0C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_10:
    // 0x80050C10: b           L_80050DF8
    // 0x80050C14: nop

        goto L_80050DF8;
    // 0x80050C14: nop

L_80050C18:
    // 0x80050C18: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80050C1C: lh          $t9, 0x3774($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X3774));
    // 0x80050C20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050C24: bnel        $t9, $at, L_80050C38
    if (ctx->r25 != ctx->r1) {
        // 0x80050C28: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80050C38;
    }
    goto skip_2;
    // 0x80050C28: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_2:
    // 0x80050C2C: jal         0x80058E1C
    // 0x80050C30: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    sound(rdram, ctx);
        goto after_11;
    // 0x80050C30: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_11:
    // 0x80050C34: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80050C38:
    // 0x80050C38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050C3C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050C40: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050C44: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050C48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050C4C: addiu       $t0, $zero, 0xE71
    ctx->r8 = ADD32(0, 0XE71);
    // 0x80050C50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050C54: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050C58: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80050C5C: jal         0x8005D13C
    // 0x80050C60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_12;
    // 0x80050C60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_12:
    // 0x80050C64: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050C68: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050C6C: xori        $t1, $a0, 0x3C
    ctx->r9 = ctx->r4 ^ 0X3C;
    // 0x80050C70: sltiu       $t1, $t1, 0x1
    ctx->r9 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80050C74: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80050C78: jal         0x8004F96C
    // 0x80050C7C: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_13;
    // 0x80050C7C: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_13:
    // 0x80050C80: b           L_80050DF8
    // 0x80050C84: nop

        goto L_80050DF8;
    // 0x80050C84: nop

L_80050C88:
    // 0x80050C88: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050C8C: lh          $v0, 0x3774($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X3774));
    // 0x80050C90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80050C94: bnel        $v0, $at, L_80050CB0
    if (ctx->r2 != ctx->r1) {
        // 0x80050C98: sll         $t4, $v0, 4
        ctx->r12 = S32(ctx->r2 << 4);
            goto L_80050CB0;
    }
    goto skip_3;
    // 0x80050C98: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    skip_3:
    // 0x80050C9C: jal         0x80058E1C
    // 0x80050CA0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    sound(rdram, ctx);
        goto after_14;
    // 0x80050CA0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_14:
    // 0x80050CA4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050CA8: lh          $v0, 0x3774($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X3774));
    // 0x80050CAC: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
L_80050CB0:
    // 0x80050CB0: addiu       $t5, $zero, 0x3C0
    ctx->r13 = ADD32(0, 0X3C0);
    // 0x80050CB4: subu        $v1, $t5, $t4
    ctx->r3 = SUB32(ctx->r13, ctx->r12);
    // 0x80050CB8: bgez        $v1, L_80050CC8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80050CBC: addiu       $a3, $zero, 0x100
        ctx->r7 = ADD32(0, 0X100);
            goto L_80050CC8;
    }
    // 0x80050CBC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80050CC0: b           L_80050CD4
    // 0x80050CC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80050CD4;
    // 0x80050CC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80050CC8:
    // 0x80050CC8: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80050CCC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80050CD0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_80050CD4:
    // 0x80050CD4: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80050CD8: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x80050CDC: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80050CE0: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80050CE4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80050CE8: jal         0x8006E994
    // 0x80050CEC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_15;
    // 0x80050CEC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_15:
    // 0x80050CF0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80050CF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050CF8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050CFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050D00: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050D04: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050D08: addiu       $t9, $zero, 0xE72
    ctx->r25 = ADD32(0, 0XE72);
    // 0x80050D0C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050D10: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050D14: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80050D18: jal         0x8005D13C
    // 0x80050D1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_16;
    // 0x80050D1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_16:
    // 0x80050D20: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80050D24: lh          $a0, 0x3774($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3774));
    // 0x80050D28: xori        $t0, $a0, 0x3C
    ctx->r8 = ctx->r4 ^ 0X3C;
    // 0x80050D2C: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80050D30: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80050D34: jal         0x8004F96C
    // 0x80050D38: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    func_8004F96C(rdram, ctx);
        goto after_17;
    // 0x80050D38: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    after_17:
    // 0x80050D3C: b           L_80050DF8
    // 0x80050D40: nop

        goto L_80050DF8;
    // 0x80050D40: nop

L_80050D44:
    // 0x80050D44: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80050D48: lh          $t3, 0x12D0($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, 0X12D0));
    // 0x80050D4C: beq         $t3, $zero, L_80050D64
    if (ctx->r11 == 0) {
        // 0x80050D50: nop
    
            goto L_80050D64;
    }
    // 0x80050D50: nop

    // 0x80050D54: jal         0x8005857C
    // 0x80050D58: nop

    func_8005857C(rdram, ctx);
        goto after_18;
    // 0x80050D58: nop

    after_18:
    // 0x80050D5C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050D60: sh          $zero, 0x12D0($at)
    MEM_H(0X12D0, ctx->r1) = 0;
L_80050D64:
    // 0x80050D64: jal         0x80050EE4
    // 0x80050D68: nop

    func_80050EE4(rdram, ctx);
        goto after_19;
    // 0x80050D68: nop

    after_19:
    // 0x80050D6C: b           L_80050DF8
    // 0x80050D70: nop

        goto L_80050DF8;
    // 0x80050D70: nop

L_80050D74:
    // 0x80050D74: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80050D78: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80050D7C: jal         0x8006E994
    // 0x80050D80: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    setrotatespriteflags(rdram, ctx);
        goto after_20;
    // 0x80050D80: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_20:
    // 0x80050D84: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80050D88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80050D8C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80050D90: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80050D94: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80050D98: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80050D9C: addiu       $t5, $zero, 0xE56
    ctx->r13 = ADD32(0, 0XE56);
    // 0x80050DA0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80050DA4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80050DA8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80050DAC: jal         0x8005D13C
    // 0x80050DB0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_21;
    // 0x80050DB0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_21:
    // 0x80050DB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80050DB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050DBC: sb          $t4, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r12;
    // 0x80050DC0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050DC4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80050DC8: sb          $t6, 0x12B8($at)
    MEM_B(0X12B8, ctx->r1) = ctx->r14;
    // 0x80050DCC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050DD0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80050DD4: sh          $t7, 0x12C8($at)
    MEM_H(0X12C8, ctx->r1) = ctx->r15;
    // 0x80050DD8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050DDC: addiu       $t8, $zero, -0x78
    ctx->r24 = ADD32(0, -0X78);
    // 0x80050DE0: sh          $t8, 0x12CC($at)
    MEM_H(0X12CC, ctx->r1) = ctx->r24;
    // 0x80050DE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80050DE8: sb          $zero, -0x46DE($at)
    MEM_B(-0X46DE, ctx->r1) = 0;
    // 0x80050DEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80050DF0: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80050DF4: sh          $t9, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r25;
L_80050DF8:
    // 0x80050DF8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050DFC: addiu       $v0, $v0, 0x3774
    ctx->r2 = ADD32(ctx->r2, 0X3774);
    // 0x80050E00: lh          $t0, 0x0($v0)
    ctx->r8 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80050E04: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80050E08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80050E0C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80050E10: jr          $ra
    // 0x80050E14: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x80050E14: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_80058A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058A30: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80058A34: addiu       $v1, $v1, 0x4D80
    ctx->r3 = ADD32(ctx->r3, 0X4D80);
    // 0x80058A38: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80058A3C: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80058A40: jr          $ra
    // 0x80058A44: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x80058A44: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void __lookupVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAB4C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800CAB50: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800CAB54: lw          $v1, 0x64($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X64));
    // 0x800CAB58: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x800CAB5C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800CAB60: beq         $v1, $zero, L_800CABB4
    if (ctx->r3 == 0) {
        // 0x800CAB64: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800CABB4;
    }
    // 0x800CAB64: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800CAB68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800CAB6C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800CAB70: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800CAB74: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
L_800CAB78:
    // 0x800CAB78: bnel        $v0, $t8, L_800CABAC
    if (ctx->r2 != ctx->r24) {
        // 0x800CAB7C: lw          $v1, 0x0($v1)
        ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800CABAC;
    }
    goto skip_0;
    // 0x800CAB7C: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
    skip_0:
    // 0x800CAB80: lbu         $t9, 0x31($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X31);
    // 0x800CAB84: bnel        $a2, $t9, L_800CABAC
    if (ctx->r6 != ctx->r25) {
        // 0x800CAB88: lw          $v1, 0x0($v1)
        ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800CABAC;
    }
    goto skip_1;
    // 0x800CAB88: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
    skip_1:
    // 0x800CAB8C: lbu         $a0, 0x35($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X35);
    // 0x800CAB90: beql        $a1, $a0, L_800CABAC
    if (ctx->r5 == ctx->r4) {
        // 0x800CAB94: lw          $v1, 0x0($v1)
        ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800CABAC;
    }
    goto skip_2;
    // 0x800CAB94: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
    skip_2:
    // 0x800CAB98: beql        $a3, $a0, L_800CABAC
    if (ctx->r7 == ctx->r4) {
        // 0x800CAB9C: lw          $v1, 0x0($v1)
        ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800CABAC;
    }
    goto skip_3;
    // 0x800CAB9C: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
    skip_3:
    // 0x800CABA0: jr          $ra
    // 0x800CABA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800CABA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CABA8: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
L_800CABAC:
    // 0x800CABAC: bnel        $v1, $zero, L_800CAB78
    if (ctx->r3 != 0) {
        // 0x800CABB0: lbu         $t8, 0x32($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X32);
            goto L_800CAB78;
    }
    goto skip_4;
    // 0x800CABB0: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
    skip_4:
L_800CABB4:
    // 0x800CABB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CABB8: jr          $ra
    // 0x800CABBC: nop

    return;
    // 0x800CABBC: nop

;}
RECOMP_FUNC void func_800528AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800528AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800528B0: sltiu       $at, $a0, 0xC
    ctx->r1 = ctx->r4 < 0XC ? 1 : 0;
    // 0x800528B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800528B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800528BC: beq         $at, $zero, L_80052BF8
    if (ctx->r1 == 0) {
        // 0x800528C0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80052BF8;
    }
    // 0x800528C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800528C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800528C8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800528CC: addu        $at, $at, $t6
    gpr jr_addend_800528D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800528D0: lw          $t6, 0x3F44($at)
    ctx->r14 = ADD32(ctx->r1, 0X3F44);
    // 0x800528D4: jr          $t6
    // 0x800528D8: nop

    switch (jr_addend_800528D4 >> 2) {
        case 0: goto L_80052C1C; break;
        case 1: goto L_800528DC; break;
        case 2: goto L_80052924; break;
        case 3: goto L_80052BF8; break;
        case 4: goto L_80052ADC; break;
        case 5: goto L_80052BF8; break;
        case 6: goto L_80052BF8; break;
        case 7: goto L_80052BF8; break;
        case 8: goto L_80052BF8; break;
        case 9: goto L_80052BF8; break;
        case 10: goto L_80052B24; break;
        case 11: goto L_80052B24; break;
        default: switch_error(__func__, 0x800528D4, 0x80103F44);
    }
    // 0x800528D8: nop

L_800528DC:
    // 0x800528DC: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x800528E0: lbu         $t7, -0x4365($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4365);
    // 0x800528E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800528E8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800528EC: bne         $t7, $at, L_80052904
    if (ctx->r15 != ctx->r1) {
        // 0x800528F0: addiu       $t1, $zero, 0x32
        ctx->r9 = ADD32(0, 0X32);
            goto L_80052904;
    }
    // 0x800528F0: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x800528F4: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x800528F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800528FC: b           L_80052910
    // 0x80052900: sb          $t8, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r24;
        goto L_80052910;
    // 0x80052900: sb          $t8, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r24;
L_80052904:
    // 0x80052904: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80052908: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005290C: sb          $t9, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r25;
L_80052910:
    // 0x80052910: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052914: sb          $t0, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r8;
    // 0x80052918: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8005291C: b           L_80052C1C
    // 0x80052920: sh          $t1, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r9;
        goto L_80052C1C;
    // 0x80052920: sh          $t1, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r9;
L_80052924:
    // 0x80052924: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80052928: addiu       $s0, $s0, 0x38B8
    ctx->r16 = ADD32(ctx->r16, 0X38B8);
    // 0x8005292C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80052930: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
    // 0x80052934: lb          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80052938: bne         $s1, $t2, L_80052954
    if (ctx->r17 != ctx->r10) {
        // 0x8005293C: nop
    
            goto L_80052954;
    }
    // 0x8005293C: nop

L_80052940:
    // 0x80052940: jal         0x800BDDD0
    // 0x80052944: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80052944: nop

    after_0:
    // 0x80052948: lb          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_B(ctx->r16, 0X0));
    // 0x8005294C: beq         $s1, $t3, L_80052940
    if (ctx->r17 == ctx->r11) {
        // 0x80052950: nop
    
            goto L_80052940;
    }
    // 0x80052950: nop

L_80052954:
    // 0x80052954: jal         0x8004BD60
    // 0x80052958: nop

    updatetime(rdram, ctx);
        goto after_1;
    // 0x80052958: nop

    after_1:
    // 0x8005295C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80052960: lw          $v0, 0x38BC($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, 0X38BC));
    // 0x80052964: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80052968: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x8005296C: beq         $v0, $at, L_80052990
    if (ctx->r2 == ctx->r1) {
        // 0x80052970: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80052990;
    }
    // 0x80052970: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80052974: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80052978: beq         $v0, $at, L_800529D0
    if (ctx->r2 == ctx->r1) {
        // 0x8005297C: addiu       $v1, $zero, 0xB
        ctx->r3 = ADD32(0, 0XB);
            goto L_800529D0;
    }
    // 0x8005297C: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x80052980: beq         $v0, $v1, L_800529D0
    if (ctx->r2 == ctx->r3) {
        // 0x80052984: lui         $t2, 0x801D
        ctx->r10 = S32(0X801D << 16);
            goto L_800529D0;
    }
    // 0x80052984: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x80052988: b           L_80052AA0
    // 0x8005298C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
        goto L_80052AA0;
    // 0x8005298C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
L_80052990:
    // 0x80052990: lbu         $t4, -0x4365($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X4365);
    // 0x80052994: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80052998: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8005299C: bne         $t4, $at, L_800529B4
    if (ctx->r12 != ctx->r1) {
        // 0x800529A0: addiu       $t8, $zero, 0x32
        ctx->r24 = ADD32(0, 0X32);
            goto L_800529B4;
    }
    // 0x800529A0: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x800529A4: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x800529A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800529AC: b           L_800529BC
    // 0x800529B0: sb          $t5, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r13;
        goto L_800529BC;
    // 0x800529B0: sb          $t5, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r13;
L_800529B4:
    // 0x800529B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800529B8: sb          $t6, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r14;
L_800529BC:
    // 0x800529BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800529C0: sb          $t7, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r15;
    // 0x800529C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800529C8: b           L_80052C1C
    // 0x800529CC: sh          $t8, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r24;
        goto L_80052C1C;
    // 0x800529CC: sh          $t8, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r24;
L_800529D0:
    // 0x800529D0: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800529D4: addiu       $s0, $s0, 0x38C0
    ctx->r16 = ADD32(ctx->r16, 0X38C0);
    // 0x800529D8: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
    // 0x800529DC: lb          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_B(ctx->r16, 0X0));
    // 0x800529E0: bne         $s1, $t9, L_800529FC
    if (ctx->r17 != ctx->r25) {
        // 0x800529E4: nop
    
            goto L_800529FC;
    }
    // 0x800529E4: nop

L_800529E8:
    // 0x800529E8: jal         0x800BDDD0
    // 0x800529EC: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800529EC: nop

    after_2:
    // 0x800529F0: lb          $t0, 0x0($s0)
    ctx->r8 = S32(MEM_B(ctx->r16, 0X0));
    // 0x800529F4: beq         $s1, $t0, L_800529E8
    if (ctx->r17 == ctx->r8) {
        // 0x800529F8: nop
    
            goto L_800529E8;
    }
    // 0x800529F8: nop

L_800529FC:
    // 0x800529FC: jal         0x8004BD60
    // 0x80052A00: nop

    updatetime(rdram, ctx);
        goto after_3;
    // 0x80052A00: nop

    after_3:
    // 0x80052A04: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80052A08: lw          $t1, 0x38C4($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, 0X38C4));
    // 0x80052A0C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x80052A10: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x80052A14: bne         $t1, $zero, L_80052A60
    if (ctx->r9 != 0) {
        // 0x80052A18: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_80052A60;
    }
    // 0x80052A18: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80052A1C: lbu         $t2, -0x4365($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X4365);
    // 0x80052A20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052A24: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80052A28: bne         $t2, $at, L_80052A40
    if (ctx->r10 != ctx->r1) {
        // 0x80052A2C: addiu       $t6, $zero, 0x32
        ctx->r14 = ADD32(0, 0X32);
            goto L_80052A40;
    }
    // 0x80052A2C: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80052A30: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80052A34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052A38: b           L_80052A4C
    // 0x80052A3C: sb          $t3, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r11;
        goto L_80052A4C;
    // 0x80052A3C: sb          $t3, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r11;
L_80052A40:
    // 0x80052A40: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80052A44: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052A48: sb          $t4, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r12;
L_80052A4C:
    // 0x80052A4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052A50: sb          $t5, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r13;
    // 0x80052A54: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80052A58: b           L_80052C1C
    // 0x80052A5C: sh          $t6, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r14;
        goto L_80052C1C;
    // 0x80052A5C: sh          $t6, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r14;
L_80052A60:
    // 0x80052A60: lbu         $t7, -0x4365($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4365);
    // 0x80052A64: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80052A68: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80052A6C: bne         $t7, $at, L_80052A84
    if (ctx->r15 != ctx->r1) {
        // 0x80052A70: addiu       $t1, $zero, 0x32
        ctx->r9 = ADD32(0, 0X32);
            goto L_80052A84;
    }
    // 0x80052A70: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80052A74: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80052A78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052A7C: b           L_80052A8C
    // 0x80052A80: sb          $t8, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r24;
        goto L_80052A8C;
    // 0x80052A80: sb          $t8, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r24;
L_80052A84:
    // 0x80052A84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052A88: sb          $t9, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r25;
L_80052A8C:
    // 0x80052A8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052A90: sb          $t0, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r8;
    // 0x80052A94: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80052A98: b           L_80052C1C
    // 0x80052A9C: sh          $t1, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r9;
        goto L_80052C1C;
    // 0x80052A9C: sh          $t1, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r9;
L_80052AA0:
    // 0x80052AA0: lbu         $t2, -0x4365($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X4365);
    // 0x80052AA4: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80052AA8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052AAC: bne         $v1, $t2, L_80052AC4
    if (ctx->r3 != ctx->r10) {
        // 0x80052AB0: addiu       $t6, $zero, 0x32
        ctx->r14 = ADD32(0, 0X32);
            goto L_80052AC4;
    }
    // 0x80052AB0: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80052AB4: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x80052AB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052ABC: b           L_80052AC8
    // 0x80052AC0: sb          $t3, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r11;
        goto L_80052AC8;
    // 0x80052AC0: sb          $t3, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r11;
L_80052AC4:
    // 0x80052AC4: sb          $t4, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r12;
L_80052AC8:
    // 0x80052AC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052ACC: sb          $t5, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r13;
    // 0x80052AD0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80052AD4: b           L_80052C1C
    // 0x80052AD8: sh          $t6, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r14;
        goto L_80052C1C;
    // 0x80052AD8: sh          $t6, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r14;
L_80052ADC:
    // 0x80052ADC: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x80052AE0: lbu         $t7, -0x4365($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4365);
    // 0x80052AE4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80052AE8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80052AEC: bne         $t7, $at, L_80052B04
    if (ctx->r15 != ctx->r1) {
        // 0x80052AF0: addiu       $t1, $zero, 0x32
        ctx->r9 = ADD32(0, 0X32);
            goto L_80052B04;
    }
    // 0x80052AF0: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80052AF4: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80052AF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052AFC: b           L_80052B10
    // 0x80052B00: sb          $t8, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r24;
        goto L_80052B10;
    // 0x80052B00: sb          $t8, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r24;
L_80052B04:
    // 0x80052B04: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80052B08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052B0C: sb          $t9, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r25;
L_80052B10:
    // 0x80052B10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052B14: sb          $t0, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r8;
    // 0x80052B18: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80052B1C: b           L_80052C1C
    // 0x80052B20: sh          $t1, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r9;
        goto L_80052C1C;
    // 0x80052B20: sh          $t1, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r9;
L_80052B24:
    // 0x80052B24: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80052B28: addiu       $s0, $s0, 0x38C0
    ctx->r16 = ADD32(ctx->r16, 0X38C0);
    // 0x80052B2C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80052B30: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
    // 0x80052B34: lb          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80052B38: bne         $s1, $t2, L_80052B54
    if (ctx->r17 != ctx->r10) {
        // 0x80052B3C: nop
    
            goto L_80052B54;
    }
    // 0x80052B3C: nop

L_80052B40:
    // 0x80052B40: jal         0x800BDDD0
    // 0x80052B44: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_4;
    // 0x80052B44: nop

    after_4:
    // 0x80052B48: lb          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80052B4C: beq         $s1, $t3, L_80052B40
    if (ctx->r17 == ctx->r11) {
        // 0x80052B50: nop
    
            goto L_80052B40;
    }
    // 0x80052B50: nop

L_80052B54:
    // 0x80052B54: jal         0x8004BD60
    // 0x80052B58: nop

    updatetime(rdram, ctx);
        goto after_5;
    // 0x80052B58: nop

    after_5:
    // 0x80052B5C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80052B60: lw          $t4, 0x38C4($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, 0X38C4));
    // 0x80052B64: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x80052B68: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x80052B6C: bne         $t4, $zero, L_80052BB8
    if (ctx->r12 != 0) {
        // 0x80052B70: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_80052BB8;
    }
    // 0x80052B70: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80052B74: lbu         $t5, -0x4365($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4365);
    // 0x80052B78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052B7C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80052B80: bne         $t5, $at, L_80052B98
    if (ctx->r13 != ctx->r1) {
        // 0x80052B84: addiu       $t9, $zero, 0x32
        ctx->r25 = ADD32(0, 0X32);
            goto L_80052B98;
    }
    // 0x80052B84: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80052B88: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80052B8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052B90: b           L_80052BA4
    // 0x80052B94: sb          $t6, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r14;
        goto L_80052BA4;
    // 0x80052B94: sb          $t6, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r14;
L_80052B98:
    // 0x80052B98: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80052B9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052BA0: sb          $t7, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r15;
L_80052BA4:
    // 0x80052BA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052BA8: sb          $t8, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r24;
    // 0x80052BAC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80052BB0: b           L_80052C1C
    // 0x80052BB4: sh          $t9, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r25;
        goto L_80052C1C;
    // 0x80052BB4: sh          $t9, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r25;
L_80052BB8:
    // 0x80052BB8: lbu         $t0, -0x4365($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X4365);
    // 0x80052BBC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80052BC0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80052BC4: bne         $t0, $at, L_80052BDC
    if (ctx->r8 != ctx->r1) {
        // 0x80052BC8: addiu       $t4, $zero, 0x32
        ctx->r12 = ADD32(0, 0X32);
            goto L_80052BDC;
    }
    // 0x80052BC8: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80052BCC: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x80052BD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052BD4: b           L_80052BE4
    // 0x80052BD8: sb          $t1, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r9;
        goto L_80052BE4;
    // 0x80052BD8: sb          $t1, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r9;
L_80052BDC:
    // 0x80052BDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052BE0: sb          $t2, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r10;
L_80052BE4:
    // 0x80052BE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052BE8: sb          $t3, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r11;
    // 0x80052BEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80052BF0: b           L_80052C1C
    // 0x80052BF4: sh          $t4, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r12;
        goto L_80052C1C;
    // 0x80052BF4: sh          $t4, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r12;
L_80052BF8:
    // 0x80052BF8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80052BFC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80052C00: sb          $t5, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r13;
    // 0x80052C04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052C08: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80052C0C: sb          $t6, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r14;
    // 0x80052C10: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80052C14: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80052C18: sh          $t7, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r15;
L_80052C1C:
    // 0x80052C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80052C20: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80052C24: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80052C28: jr          $ra
    // 0x80052C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80052C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void alSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D01A8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D01AC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800D01B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D01B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D01B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D01BC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800D01C0: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800D01C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D01C8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800D01CC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D01D0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800D01D4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D01D8: bne         $a2, $zero, L_800D01F8
    if (ctx->r6 != 0) {
        // 0x800D01DC: sw          $s2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r18;
            goto L_800D01F8;
    }
    // 0x800D01DC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D01E0: lw          $t6, 0x4($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800D01E4: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x800D01E8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D01EC: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800D01F0: b           L_800D029C
    // 0x800D01F4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_800D029C;
    // 0x800D01F4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_800D01F8:
    // 0x800D01F8: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800D01FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D0200: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x800D0204: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800D0208: lh          $t8, 0x1A($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X1A));
    // 0x800D020C: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x800D0210: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    // 0x800D0214: lw          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800D0218: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800D021C: lw          $t0, 0x4($s0)
    ctx->r8 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800D0220: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x800D0224: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800D0228: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x800D022C: lw          $s4, 0x8($s0)
    ctx->r20 = S32(MEM_W(ctx->r16, 0X8));
L_800D0230:
    // 0x800D0230: lh          $s5, 0x1A($s0)
    ctx->r21 = S32(MEM_H(ctx->r16, 0X1A));
    // 0x800D0234: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800D0238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D023C: jal         0x800D0024
    // 0x800D0240: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alSeqNextEvent(rdram, ctx);
        goto after_0;
    // 0x800D0240: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800D0244: lh          $t1, 0x50($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X50));
    // 0x800D0248: bnel        $t1, $s3, L_800D0264
    if (ctx->r9 != ctx->r19) {
        // 0x800D024C: lw          $v0, 0xC($s0)
        ctx->r2 = S32(MEM_W(ctx->r16, 0XC));
            goto L_800D0264;
    }
    goto skip_0;
    // 0x800D024C: lw          $v0, 0xC($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0XC));
    skip_0:
    // 0x800D0250: lw          $s4, 0x8($s0)
    ctx->r20 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800D0254: lh          $s5, 0x1A($s0)
    ctx->r21 = S32(MEM_H(ctx->r16, 0X1A));
    // 0x800D0258: b           L_800D0270
    // 0x800D025C: lw          $s6, 0xC($s0)
    ctx->r22 = S32(MEM_W(ctx->r16, 0XC));
        goto L_800D0270;
    // 0x800D025C: lw          $s6, 0xC($s0)
    ctx->r22 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800D0260: lw          $v0, 0xC($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0XC));
L_800D0264:
    // 0x800D0264: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800D0268: bnel        $at, $zero, L_800D0230
    if (ctx->r1 != 0) {
        // 0x800D026C: lw          $s4, 0x8($s0)
        ctx->r20 = S32(MEM_W(ctx->r16, 0X8));
            goto L_800D0230;
    }
    goto skip_1;
    // 0x800D026C: lw          $s4, 0x8($s0)
    ctx->r20 = S32(MEM_W(ctx->r16, 0X8));
    skip_1:
L_800D0270:
    // 0x800D0270: sw          $s4, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r20;
    // 0x800D0274: sh          $s5, 0xC($s7)
    MEM_H(0XC, ctx->r23) = ctx->r21;
    // 0x800D0278: sw          $s6, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r22;
    // 0x800D027C: lw          $t2, 0xC($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800D0280: sw          $t2, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r10;
    // 0x800D0284: lw          $t3, 0x4C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800D0288: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x800D028C: lh          $t4, 0x3E($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X3E));
    // 0x800D0290: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x800D0294: lw          $t5, 0x44($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800D0298: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
L_800D029C:
    // 0x800D029C: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800D02A0: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800D02A4: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800D02A8: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800D02AC: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800D02B0: lw          $s4, 0x24($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800D02B4: lw          $s5, 0x28($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800D02B8: lw          $s6, 0x2C($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800D02BC: lw          $s7, 0x30($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800D02C0: jr          $ra
    // 0x800D02C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D02C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8005C390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C390: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x8005C394: bne         $at, $zero, L_8005C3AC
    if (ctx->r1 != 0) {
        // 0x8005C398: nop
    
            goto L_8005C3AC;
    }
    // 0x8005C398: nop

    // 0x8005C39C: addiu       $a0, $a0, -0xB
    ctx->r4 = ADD32(ctx->r4, -0XB);
L_8005C3A0:
    // 0x8005C3A0: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x8005C3A4: beql        $at, $zero, L_8005C3A0
    if (ctx->r1 == 0) {
        // 0x8005C3A8: addiu       $a0, $a0, -0xB
        ctx->r4 = ADD32(ctx->r4, -0XB);
            goto L_8005C3A0;
    }
    goto skip_0;
    // 0x8005C3A8: addiu       $a0, $a0, -0xB
    ctx->r4 = ADD32(ctx->r4, -0XB);
    skip_0:
L_8005C3AC:
    // 0x8005C3AC: bgezl       $a0, L_8005C3C4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005C3B0: sltiu       $at, $a0, 0x9
        ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
            goto L_8005C3C4;
    }
    goto skip_1;
    // 0x8005C3B0: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
    skip_1:
    // 0x8005C3B4: addiu       $a0, $a0, 0xB
    ctx->r4 = ADD32(ctx->r4, 0XB);
L_8005C3B8:
    // 0x8005C3B8: bltzl       $a0, L_8005C3B8
    if (SIGNED(ctx->r4) < 0) {
        // 0x8005C3BC: addiu       $a0, $a0, 0xB
        ctx->r4 = ADD32(ctx->r4, 0XB);
            goto L_8005C3B8;
    }
    goto skip_2;
    // 0x8005C3BC: addiu       $a0, $a0, 0xB
    ctx->r4 = ADD32(ctx->r4, 0XB);
    skip_2:
    // 0x8005C3C0: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
L_8005C3C4:
    // 0x8005C3C4: beq         $at, $zero, L_8005C4CC
    if (ctx->r1 == 0) {
        // 0x8005C3C8: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8005C4CC;
    }
    // 0x8005C3C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8005C3CC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8005C3D0: addu        $at, $at, $t6
    gpr jr_addend_8005C3D8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8005C3D4: lw          $t6, 0x4AEC($at)
    ctx->r14 = ADD32(ctx->r1, 0X4AEC);
    // 0x8005C3D8: jr          $t6
    // 0x8005C3DC: nop

    switch (jr_addend_8005C3D8 >> 2) {
        case 0: goto L_8005C3E0; break;
        case 1: goto L_8005C410; break;
        case 2: goto L_8005C440; break;
        case 3: goto L_8005C470; break;
        case 4: goto L_8005C4CC; break;
        case 5: goto L_8005C4CC; break;
        case 6: goto L_8005C4CC; break;
        case 7: goto L_8005C4CC; break;
        case 8: goto L_8005C4A0; break;
        default: switch_error(__func__, 0x8005C3D8, 0x80104AEC);
    }
    // 0x8005C3DC: nop

L_8005C3E0:
    // 0x8005C3E0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8005C3E4: addiu       $a0, $a0, 0x4418
    ctx->r4 = ADD32(ctx->r4, 0X4418);
    // 0x8005C3E8: lw          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005C3EC: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8005C3F0: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x8005C3F4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005C3F8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005C3FC: ori         $t9, $t9, 0x2230
    ctx->r25 = ctx->r25 | 0X2230;
    // 0x8005C400: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8005C404: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005C408: jr          $ra
    // 0x8005C40C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    return;
    // 0x8005C40C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8005C410:
    // 0x8005C410: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8005C414: addiu       $a0, $a0, 0x4418
    ctx->r4 = ADD32(ctx->r4, 0X4418);
    // 0x8005C418: lw          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005C41C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x8005C420: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x8005C424: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8005C428: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8005C42C: ori         $t2, $t2, 0x4A50
    ctx->r10 = ctx->r10 | 0X4A50;
    // 0x8005C430: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x8005C434: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005C438: jr          $ra
    // 0x8005C43C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    return;
    // 0x8005C43C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_8005C440:
    // 0x8005C440: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8005C444: addiu       $a0, $a0, 0x4418
    ctx->r4 = ADD32(ctx->r4, 0X4418);
    // 0x8005C448: lw          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005C44C: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x8005C450: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x8005C454: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8005C458: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005C45C: ori         $t5, $t5, 0x2E10
    ctx->r13 = ctx->r13 | 0X2E10;
    // 0x8005C460: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x8005C464: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8005C468: jr          $ra
    // 0x8005C46C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    return;
    // 0x8005C46C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_8005C470:
    // 0x8005C470: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8005C474: addiu       $a0, $a0, 0x4418
    ctx->r4 = ADD32(ctx->r4, 0X4418);
    // 0x8005C478: lw          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005C47C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8005C480: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8005C484: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005C488: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005C48C: ori         $t8, $t8, 0x4E50
    ctx->r24 = ctx->r24 | 0X4E50;
    // 0x8005C490: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8005C494: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005C498: jr          $ra
    // 0x8005C49C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x8005C49C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_8005C4A0:
    // 0x8005C4A0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8005C4A4: addiu       $a0, $a0, 0x4418
    ctx->r4 = ADD32(ctx->r4, 0X4418);
    // 0x8005C4A8: lw          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005C4AC: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x8005C4B0: lui         $t1, 0x55
    ctx->r9 = S32(0X55 << 16);
    // 0x8005C4B4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005C4B8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005C4BC: ori         $t1, $t1, 0x3078
    ctx->r9 = ctx->r9 | 0X3078;
    // 0x8005C4C0: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x8005C4C4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8005C4C8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_8005C4CC:
    // 0x8005C4CC: jr          $ra
    // 0x8005C4D0: nop

    return;
    // 0x8005C4D0: nop

;}
RECOMP_FUNC void krand2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009800C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80098010: lb          $t6, 0x1360($t6)
    ctx->r14 = S32(MEM_B(ctx->r14, 0X1360));
    // 0x80098014: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x80098018: addiu       $v1, $v1, -0x5368
    ctx->r3 = ADD32(ctx->r3, -0X5368);
    // 0x8009801C: beql        $t6, $zero, L_80098030
    if (ctx->r14 == 0) {
        // 0x80098020: lw          $t7, 0x0($v1)
        ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
            goto L_80098030;
    }
    goto skip_0;
    // 0x80098020: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
    skip_0:
    // 0x80098024: jr          $ra
    // 0x80098028: ori         $v0, $zero, 0xF837
    ctx->r2 = 0 | 0XF837;
    return;
    // 0x80098028: ori         $v0, $zero, 0xF837
    ctx->r2 = 0 | 0XF837;
    // 0x8009802C: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
L_80098030:
    // 0x80098030: lui         $at, 0x1A4
    ctx->r1 = S32(0X1A4 << 16);
    // 0x80098034: ori         $at, $at, 0xE86D
    ctx->r1 = ctx->r1 | 0XE86D;
    // 0x80098038: multu       $t7, $at
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009803C: mflo        $t8
    ctx->r24 = lo;
    // 0x80098040: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80098044: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80098048: srl         $v0, $t9, 16
    ctx->r2 = S32(U32(ctx->r25) >> 16);
    // 0x8009804C: jr          $ra
    // 0x80098050: nop

    return;
    // 0x80098050: nop

;}
RECOMP_FUNC void alSeqpSetBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1660: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C1664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1668: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800C166C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1670: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C1674: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C1678: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C167C: jal         0x800C9C6C
    // 0x800C1680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C1680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C1684: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C1688: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C168C: jr          $ra
    // 0x800C1690: nop

    return;
    // 0x800C1690: nop

;}
RECOMP_FUNC void badguy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099ED4: lh          $v0, 0xE($a0)
    ctx->r2 = S32(MEM_H(ctx->r4, 0XE));
    // 0x80099ED8: slti        $at, $v0, 0x7D2
    ctx->r1 = SIGNED(ctx->r2) < 0X7D2 ? 1 : 0;
    // 0x80099EDC: bne         $at, $zero, L_80099FBC
    if (ctx->r1 != 0) {
        // 0x80099EE0: slti        $at, $v0, 0xA47
        ctx->r1 = SIGNED(ctx->r2) < 0XA47 ? 1 : 0;
            goto L_80099FBC;
    }
    // 0x80099EE0: slti        $at, $v0, 0xA47
    ctx->r1 = SIGNED(ctx->r2) < 0XA47 ? 1 : 0;
    // 0x80099EE4: bne         $at, $zero, L_80099F2C
    if (ctx->r1 != 0) {
        // 0x80099EE8: addiu       $at, $zero, 0xA96
        ctx->r1 = ADD32(0, 0XA96);
            goto L_80099F2C;
    }
    // 0x80099EE8: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    // 0x80099EEC: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099EF0: addiu       $at, $zero, 0xAC8
        ctx->r1 = ADD32(0, 0XAC8);
            goto L_8009A07C;
    }
    // 0x80099EF0: addiu       $at, $zero, 0xAC8
    ctx->r1 = ADD32(0, 0XAC8);
    // 0x80099EF4: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099EF8: addiu       $at, $zero, 0x1202
        ctx->r1 = ADD32(0, 0X1202);
            goto L_8009A07C;
    }
    // 0x80099EF8: addiu       $at, $zero, 0x1202
    ctx->r1 = ADD32(0, 0X1202);
    // 0x80099EFC: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099F00: addiu       $at, $zero, 0x1203
        ctx->r1 = ADD32(0, 0X1203);
            goto L_8009A07C;
    }
    // 0x80099F00: addiu       $at, $zero, 0x1203
    ctx->r1 = ADD32(0, 0X1203);
    // 0x80099F04: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099F08: addiu       $at, $zero, 0x123E
        ctx->r1 = ADD32(0, 0X123E);
            goto L_8009A07C;
    }
    // 0x80099F08: addiu       $at, $zero, 0x123E
    ctx->r1 = ADD32(0, 0X123E);
    // 0x80099F0C: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099F10: addiu       $at, $zero, 0x123F
        ctx->r1 = ADD32(0, 0X123F);
            goto L_8009A07C;
    }
    // 0x80099F10: addiu       $at, $zero, 0x123F
    ctx->r1 = ADD32(0, 0X123F);
    // 0x80099F14: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099F18: addiu       $at, $zero, 0x1252
        ctx->r1 = ADD32(0, 0X1252);
            goto L_8009A07C;
    }
    // 0x80099F18: addiu       $at, $zero, 0x1252
    ctx->r1 = ADD32(0, 0X1252);
    // 0x80099F1C: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099F20: nop
    
            goto L_8009A07C;
    }
    // 0x80099F20: nop

    // 0x80099F24: b           L_8009A088
    // 0x80099F28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A088;
    // 0x80099F28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80099F2C:
    // 0x80099F2C: slti        $at, $v0, 0x871
    ctx->r1 = SIGNED(ctx->r2) < 0X871 ? 1 : 0;
    // 0x80099F30: bne         $at, $zero, L_80099F90
    if (ctx->r1 != 0) {
        // 0x80099F34: slti        $at, $v0, 0x94A
        ctx->r1 = SIGNED(ctx->r2) < 0X94A ? 1 : 0;
            goto L_80099F90;
    }
    // 0x80099F34: slti        $at, $v0, 0x94A
    ctx->r1 = SIGNED(ctx->r2) < 0X94A ? 1 : 0;
    // 0x80099F38: bne         $at, $zero, L_80099F50
    if (ctx->r1 != 0) {
        // 0x80099F3C: addiu       $at, $zero, 0xA46
        ctx->r1 = ADD32(0, 0XA46);
            goto L_80099F50;
    }
    // 0x80099F3C: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    // 0x80099F40: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099F44: nop
    
            goto L_8009A07C;
    }
    // 0x80099F44: nop

    // 0x80099F48: b           L_8009A088
    // 0x80099F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A088;
    // 0x80099F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80099F50:
    // 0x80099F50: slti        $at, $v0, 0x876
    ctx->r1 = SIGNED(ctx->r2) < 0X876 ? 1 : 0;
    // 0x80099F54: bne         $at, $zero, L_80099F7C
    if (ctx->r1 != 0) {
        // 0x80099F58: addiu       $t6, $v0, -0x938
        ctx->r14 = ADD32(ctx->r2, -0X938);
            goto L_80099F7C;
    }
    // 0x80099F58: addiu       $t6, $v0, -0x938
    ctx->r14 = ADD32(ctx->r2, -0X938);
    // 0x80099F5C: sltiu       $at, $t6, 0x12
    ctx->r1 = ctx->r14 < 0X12 ? 1 : 0;
    // 0x80099F60: beq         $at, $zero, L_8009A084
    if (ctx->r1 == 0) {
        // 0x80099F64: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8009A084;
    }
    // 0x80099F64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80099F68: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80099F6C: addu        $at, $at, $t6
    gpr jr_addend_80099F74 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80099F70: lw          $t6, 0x67E8($at)
    ctx->r14 = ADD32(ctx->r1, 0X67E8);
    // 0x80099F74: jr          $t6
    // 0x80099F78: nop

    switch (jr_addend_80099F74 >> 2) {
        case 0: goto L_8009A07C; break;
        case 1: goto L_8009A084; break;
        case 2: goto L_8009A084; break;
        case 3: goto L_8009A084; break;
        case 4: goto L_8009A084; break;
        case 5: goto L_8009A084; break;
        case 6: goto L_8009A084; break;
        case 7: goto L_8009A084; break;
        case 8: goto L_8009A084; break;
        case 9: goto L_8009A084; break;
        case 10: goto L_8009A07C; break;
        case 11: goto L_8009A07C; break;
        case 12: goto L_8009A07C; break;
        case 13: goto L_8009A07C; break;
        case 14: goto L_8009A07C; break;
        case 15: goto L_8009A07C; break;
        case 16: goto L_8009A07C; break;
        case 17: goto L_8009A07C; break;
        default: switch_error(__func__, 0x80099F74, 0x801067E8);
    }
    // 0x80099F78: nop

L_80099F7C:
    // 0x80099F7C: addiu       $at, $zero, 0x875
    ctx->r1 = ADD32(0, 0X875);
    // 0x80099F80: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099F84: nop
    
            goto L_8009A07C;
    }
    // 0x80099F84: nop

    // 0x80099F88: b           L_8009A088
    // 0x80099F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A088;
    // 0x80099F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80099F90:
    // 0x80099F90: addiu       $at, $zero, 0x7FD
    ctx->r1 = ADD32(0, 0X7FD);
    // 0x80099F94: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099F98: addiu       $at, $zero, 0x848
        ctx->r1 = ADD32(0, 0X848);
            goto L_8009A07C;
    }
    // 0x80099F98: addiu       $at, $zero, 0x848
    ctx->r1 = ADD32(0, 0X848);
    // 0x80099F9C: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FA0: addiu       $at, $zero, 0x866
        ctx->r1 = ADD32(0, 0X866);
            goto L_8009A07C;
    }
    // 0x80099FA0: addiu       $at, $zero, 0x866
    ctx->r1 = ADD32(0, 0X866);
    // 0x80099FA4: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FA8: addiu       $at, $zero, 0x870
        ctx->r1 = ADD32(0, 0X870);
            goto L_8009A07C;
    }
    // 0x80099FA8: addiu       $at, $zero, 0x870
    ctx->r1 = ADD32(0, 0X870);
    // 0x80099FAC: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FB0: nop
    
            goto L_8009A07C;
    }
    // 0x80099FB0: nop

    // 0x80099FB4: b           L_8009A088
    // 0x80099FB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A088;
    // 0x80099FB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80099FBC:
    // 0x80099FBC: slti        $at, $v0, 0x6D1
    ctx->r1 = SIGNED(ctx->r2) < 0X6D1 ? 1 : 0;
    // 0x80099FC0: bne         $at, $zero, L_8009A008
    if (ctx->r1 != 0) {
        // 0x80099FC4: addiu       $at, $zero, 0x71C
        ctx->r1 = ADD32(0, 0X71C);
            goto L_8009A008;
    }
    // 0x80099FC4: addiu       $at, $zero, 0x71C
    ctx->r1 = ADD32(0, 0X71C);
    // 0x80099FC8: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FCC: addiu       $at, $zero, 0x758
        ctx->r1 = ADD32(0, 0X758);
            goto L_8009A07C;
    }
    // 0x80099FCC: addiu       $at, $zero, 0x758
    ctx->r1 = ADD32(0, 0X758);
    // 0x80099FD0: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FD4: addiu       $at, $zero, 0x780
        ctx->r1 = ADD32(0, 0X780);
            goto L_8009A07C;
    }
    // 0x80099FD4: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x80099FD8: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FDC: addiu       $at, $zero, 0x781
        ctx->r1 = ADD32(0, 0X781);
            goto L_8009A07C;
    }
    // 0x80099FDC: addiu       $at, $zero, 0x781
    ctx->r1 = ADD32(0, 0X781);
    // 0x80099FE0: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FE4: addiu       $at, $zero, 0x7A8
        ctx->r1 = ADD32(0, 0X7A8);
            goto L_8009A07C;
    }
    // 0x80099FE4: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
    // 0x80099FE8: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FEC: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_8009A07C;
    }
    // 0x80099FEC: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    // 0x80099FF0: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FF4: addiu       $at, $zero, 0x7D1
        ctx->r1 = ADD32(0, 0X7D1);
            goto L_8009A07C;
    }
    // 0x80099FF4: addiu       $at, $zero, 0x7D1
    ctx->r1 = ADD32(0, 0X7D1);
    // 0x80099FF8: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x80099FFC: nop
    
            goto L_8009A07C;
    }
    // 0x80099FFC: nop

    // 0x8009A000: b           L_8009A088
    // 0x8009A004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A088;
    // 0x8009A004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A008:
    // 0x8009A008: slti        $at, $v0, 0x691
    ctx->r1 = SIGNED(ctx->r2) < 0X691 ? 1 : 0;
    // 0x8009A00C: bne         $at, $zero, L_8009A058
    if (ctx->r1 != 0) {
        // 0x8009A010: slti        $at, $v0, 0x693
        ctx->r1 = SIGNED(ctx->r2) < 0X693 ? 1 : 0;
            goto L_8009A058;
    }
    // 0x8009A010: slti        $at, $v0, 0x693
    ctx->r1 = SIGNED(ctx->r2) < 0X693 ? 1 : 0;
    // 0x8009A014: bne         $at, $zero, L_8009A03C
    if (ctx->r1 != 0) {
        // 0x8009A018: addiu       $t7, $v0, -0x6B3
        ctx->r15 = ADD32(ctx->r2, -0X6B3);
            goto L_8009A03C;
    }
    // 0x8009A018: addiu       $t7, $v0, -0x6B3
    ctx->r15 = ADD32(ctx->r2, -0X6B3);
    // 0x8009A01C: sltiu       $at, $t7, 0x1E
    ctx->r1 = ctx->r15 < 0X1E ? 1 : 0;
    // 0x8009A020: beq         $at, $zero, L_8009A084
    if (ctx->r1 == 0) {
        // 0x8009A024: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8009A084;
    }
    // 0x8009A024: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8009A028: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8009A02C: addu        $at, $at, $t7
    gpr jr_addend_8009A034 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8009A030: lw          $t7, 0x6830($at)
    ctx->r15 = ADD32(ctx->r1, 0X6830);
    // 0x8009A034: jr          $t7
    // 0x8009A038: nop

    switch (jr_addend_8009A034 >> 2) {
        case 0: goto L_8009A07C; break;
        case 1: goto L_8009A084; break;
        case 2: goto L_8009A084; break;
        case 3: goto L_8009A084; break;
        case 4: goto L_8009A084; break;
        case 5: goto L_8009A084; break;
        case 6: goto L_8009A084; break;
        case 7: goto L_8009A084; break;
        case 8: goto L_8009A084; break;
        case 9: goto L_8009A084; break;
        case 10: goto L_8009A07C; break;
        case 11: goto L_8009A084; break;
        case 12: goto L_8009A084; break;
        case 13: goto L_8009A084; break;
        case 14: goto L_8009A084; break;
        case 15: goto L_8009A084; break;
        case 16: goto L_8009A084; break;
        case 17: goto L_8009A084; break;
        case 18: goto L_8009A084; break;
        case 19: goto L_8009A084; break;
        case 20: goto L_8009A084; break;
        case 21: goto L_8009A084; break;
        case 22: goto L_8009A084; break;
        case 23: goto L_8009A084; break;
        case 24: goto L_8009A084; break;
        case 25: goto L_8009A084; break;
        case 26: goto L_8009A07C; break;
        case 27: goto L_8009A07C; break;
        case 28: goto L_8009A084; break;
        case 29: goto L_8009A07C; break;
        default: switch_error(__func__, 0x8009A034, 0x80106830);
    }
    // 0x8009A038: nop

L_8009A03C:
    // 0x8009A03C: addiu       $at, $zero, 0x691
    ctx->r1 = ADD32(0, 0X691);
    // 0x8009A040: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A044: addiu       $at, $zero, 0x692
        ctx->r1 = ADD32(0, 0X692);
            goto L_8009A07C;
    }
    // 0x8009A044: addiu       $at, $zero, 0x692
    ctx->r1 = ADD32(0, 0X692);
    // 0x8009A048: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A04C: nop
    
            goto L_8009A07C;
    }
    // 0x8009A04C: nop

    // 0x8009A050: b           L_8009A088
    // 0x8009A054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A088;
    // 0x8009A054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A058:
    // 0x8009A058: addiu       $at, $zero, 0x2A3
    ctx->r1 = ADD32(0, 0X2A3);
    // 0x8009A05C: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A060: addiu       $at, $zero, 0x4F3
        ctx->r1 = ADD32(0, 0X4F3);
            goto L_8009A07C;
    }
    // 0x8009A060: addiu       $at, $zero, 0x4F3
    ctx->r1 = ADD32(0, 0X4F3);
    // 0x8009A064: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A068: addiu       $at, $zero, 0x60E
        ctx->r1 = ADD32(0, 0X60E);
            goto L_8009A07C;
    }
    // 0x8009A068: addiu       $at, $zero, 0x60E
    ctx->r1 = ADD32(0, 0X60E);
    // 0x8009A06C: beq         $v0, $at, L_8009A07C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A070: addiu       $at, $zero, 0x690
        ctx->r1 = ADD32(0, 0X690);
            goto L_8009A07C;
    }
    // 0x8009A070: addiu       $at, $zero, 0x690
    ctx->r1 = ADD32(0, 0X690);
    // 0x8009A074: bnel        $v0, $at, L_8009A088
    if (ctx->r2 != ctx->r1) {
        // 0x8009A078: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009A088;
    }
    goto skip_0;
    // 0x8009A078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8009A07C:
    // 0x8009A07C: jr          $ra
    // 0x8009A080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009A080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009A084:
    // 0x8009A084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A088:
    // 0x8009A088: jr          $ra
    // 0x8009A08C: nop

    return;
    // 0x8009A08C: nop

;}
RECOMP_FUNC void incur_damage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A1584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1588: lh          $t6, 0x2E0($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X2E0));
    // 0x800A158C: addiu       $t2, $zero, 0x2C
    ctx->r10 = ADD32(0, 0X2C);
    // 0x800A1590: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x800A1594: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A1598: addiu       $t1, $t1, 0x6BA8
    ctx->r9 = ADD32(ctx->r9, 0X6BA8);
    // 0x800A159C: lh          $t9, 0x2E8($a0)
    ctx->r25 = S32(MEM_H(ctx->r4, 0X2E8));
    // 0x800A15A0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A15A4: sra         $t3, $t9, 8
    ctx->r11 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800A15A8: mflo        $t7
    ctx->r15 = lo;
    // 0x800A15AC: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x800A15B0: lh          $t8, 0x22($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X22));
    // 0x800A15B4: subu        $t4, $t8, $t3
    ctx->r12 = SUB32(ctx->r24, ctx->r11);
    // 0x800A15B8: sh          $t4, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r12;
    // 0x800A15BC: lh          $t5, 0x2E0($a0)
    ctx->r13 = S32(MEM_H(ctx->r4, 0X2E0));
    // 0x800A15C0: lh          $t8, 0x28C($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X28C));
    // 0x800A15C4: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x800A15C8: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A15CC: mflo        $t6
    ctx->r14 = lo;
    // 0x800A15D0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800A15D4: lh          $t9, 0x22($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X22));
    // 0x800A15D8: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x800A15DC: bgezl       $t0, L_800A170C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A15E0: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800A170C;
    }
    goto skip_0;
    // 0x800A15E0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800A15E4: sh          $zero, 0x2E8($a0)
    MEM_H(0X2E8, ctx->r4) = 0;
    // 0x800A15E8: lw          $t3, -0x5408($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, -0X5408));
    // 0x800A15EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A15F0: bnel        $t3, $at, L_800A161C
    if (ctx->r11 != ctx->r1) {
        // 0x800A15F4: lh          $t4, 0x2E0($a3)
        ctx->r12 = S32(MEM_H(ctx->r7, 0X2E0));
            goto L_800A161C;
    }
    goto skip_1;
    // 0x800A15F4: lh          $t4, 0x2E0($a3)
    ctx->r12 = S32(MEM_H(ctx->r7, 0X2E0));
    skip_1:
    // 0x800A15F8: bgez        $t0, L_800A1608
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A15FC: sra         $v0, $t0, 1
        ctx->r2 = S32(SIGNED(ctx->r8) >> 1);
            goto L_800A1608;
    }
    // 0x800A15FC: sra         $v0, $t0, 1
    ctx->r2 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800A1600: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x800A1604: sra         $v0, $at, 1
    ctx->r2 = S32(SIGNED(ctx->r1) >> 1);
L_800A1608:
    // 0x800A1608: bltz        $v0, L_800A1618
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A160C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800A1618;
    }
    // 0x800A160C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800A1610: b           L_800A1618
    // 0x800A1614: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800A1618;
    // 0x800A1614: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A1618:
    // 0x800A1618: lh          $t4, 0x2E0($a3)
    ctx->r12 = S32(MEM_H(ctx->r7, 0X2E0));
L_800A161C:
    // 0x800A161C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800A1620: lh          $t7, -0x9DC($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X9DC));
    // 0x800A1624: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A1628: mflo        $t5
    ctx->r13 = lo;
    // 0x800A162C: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x800A1630: lh          $v0, 0x1A($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0X1A));
    // 0x800A1634: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A1638: beq         $at, $zero, L_800A1670
    if (ctx->r1 == 0) {
        // 0x800A163C: slti        $at, $t0, -0x3
        ctx->r1 = SIGNED(ctx->r8) < -0X3 ? 1 : 0;
            goto L_800A1670;
    }
    // 0x800A163C: slti        $at, $t0, -0x3
    ctx->r1 = SIGNED(ctx->r8) < -0X3 ? 1 : 0;
    // 0x800A1640: beq         $at, $zero, L_800A1670
    if (ctx->r1 == 0) {
        // 0x800A1644: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_800A1670;
    }
    // 0x800A1644: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800A1648: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800A164C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800A1650: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800A1654: jal         0x8005194C
    // 0x800A1658: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    controllersetvib(rdram, ctx);
        goto after_0;
    // 0x800A1658: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x800A165C: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x800A1660: addiu       $t1, $t1, 0x6BA8
    ctx->r9 = ADD32(ctx->r9, 0X6BA8);
    // 0x800A1664: lw          $a3, 0x20($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A1668: lw          $t0, 0x1C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800A166C: addiu       $t2, $zero, 0x2C
    ctx->r10 = ADD32(0, 0X2C);
L_800A1670:
    // 0x800A1670: lh          $t9, 0x322($a3)
    ctx->r25 = S32(MEM_H(ctx->r7, 0X322));
    // 0x800A1674: blezl       $t9, L_800A16F0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A1678: lh          $t8, 0x2E0($a3)
        ctx->r24 = S32(MEM_H(ctx->r7, 0X2E0));
            goto L_800A16F0;
    }
    goto skip_2;
    // 0x800A1678: lh          $t8, 0x2E0($a3)
    ctx->r24 = S32(MEM_H(ctx->r7, 0X2E0));
    skip_2:
    // 0x800A167C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800A1680: jal         0x8009800C
    // 0x800A1684: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_1;
    // 0x800A1684: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x800A1688: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800A168C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800A1690: mfhi        $t8
    ctx->r24 = hi;
    // 0x800A1694: lw          $t0, 0x1C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800A1698: addiu       $t3, $t8, 0x14
    ctx->r11 = ADD32(ctx->r24, 0X14);
    // 0x800A169C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800A16A0: multu       $t3, $t0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A16A4: lw          $a3, 0x20($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A16A8: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x800A16AC: addiu       $t1, $t1, 0x6BA8
    ctx->r9 = ADD32(ctx->r9, 0X6BA8);
    // 0x800A16B0: lh          $t5, 0x322($a3)
    ctx->r13 = S32(MEM_H(ctx->r7, 0X322));
    // 0x800A16B4: addiu       $t2, $zero, 0x2C
    ctx->r10 = ADD32(0, 0X2C);
    // 0x800A16B8: mflo        $v1
    ctx->r3 = lo;
    // 0x800A16BC: nop

    // 0x800A16C0: nop

    // 0x800A16C4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800A16C8: mflo        $t4
    ctx->r12 = lo;
    // 0x800A16CC: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800A16D0: sh          $t6, 0x322($a3)
    MEM_H(0X322, ctx->r7) = ctx->r14;
    // 0x800A16D4: lh          $a1, 0x322($a3)
    ctx->r5 = S32(MEM_H(ctx->r7, 0X322));
    // 0x800A16D8: subu        $t0, $t0, $t4
    ctx->r8 = SUB32(ctx->r8, ctx->r12);
    // 0x800A16DC: bgezl       $a1, L_800A16F0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800A16E0: lh          $t8, 0x2E0($a3)
        ctx->r24 = S32(MEM_H(ctx->r7, 0X2E0));
            goto L_800A16F0;
    }
    goto skip_3;
    // 0x800A16E0: lh          $t8, 0x2E0($a3)
    ctx->r24 = S32(MEM_H(ctx->r7, 0X2E0));
    skip_3:
    // 0x800A16E4: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x800A16E8: sh          $zero, 0x322($a3)
    MEM_H(0X322, ctx->r7) = 0;
    // 0x800A16EC: lh          $t8, 0x2E0($a3)
    ctx->r24 = S32(MEM_H(ctx->r7, 0X2E0));
L_800A16F0:
    // 0x800A16F0: lh          $t7, 0x28C($a3)
    ctx->r15 = S32(MEM_H(ctx->r7, 0X28C));
    // 0x800A16F4: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A16F8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800A16FC: mflo        $t3
    ctx->r11 = lo;
    // 0x800A1700: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800A1704: sh          $t9, 0x22($t4)
    MEM_H(0X22, ctx->r12) = ctx->r25;
    // 0x800A1708: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800A170C:
    // 0x800A170C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A1710: jr          $ra
    // 0x800A1714: nop

    return;
    // 0x800A1714: nop

;}
RECOMP_FUNC void printnumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E878: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006E87C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8006E880: addiu       $t0, $t0, 0x4418
    ctx->r8 = ADD32(ctx->r8, 0X4418);
    // 0x8006E884: lw          $a3, 0x0($t0)
    ctx->r7 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8006E888: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006E88C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006E890: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x8006E894: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006E898: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006E89C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006E8A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006E8A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006E8A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006E8AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006E8B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8006E8B4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8006E8B8: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8006E8BC: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8006E8C0: ori         $t9, $t9, 0x4A50
    ctx->r25 = ctx->r25 | 0X4A50;
    // 0x8006E8C4: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8006E8C8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8006E8CC: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x8006E8D0: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x8006E8D4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8006E8D8: andi        $s2, $a0, 0xFFFF
    ctx->r18 = ctx->r4 & 0XFFFF;
    // 0x8006E8DC: beq         $v1, $zero, L_8006E96C
    if (ctx->r3 == 0) {
        // 0x8006E8E0: andi        $t6, $a1, 0xFFFF
        ctx->r14 = ctx->r5 & 0XFFFF;
            goto L_8006E96C;
    }
    // 0x8006E8E0: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8006E8E4: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x8006E8E8: beq         $s5, $v1, L_8006E96C
    if (ctx->r21 == ctx->r3) {
        // 0x8006E8EC: addiu       $s6, $zero, 0xD
        ctx->r22 = ADD32(0, 0XD);
            goto L_8006E96C;
    }
    // 0x8006E8EC: addiu       $s6, $zero, 0xD
    ctx->r22 = ADD32(0, 0XD);
    // 0x8006E8F0: beq         $s6, $v1, L_8006E96C
    if (ctx->r22 == ctx->r3) {
        // 0x8006E8F4: or          $s4, $t6, $zero
        ctx->r20 = ctx->r14 | 0;
            goto L_8006E96C;
    }
    // 0x8006E8F4: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x8006E8F8: addiu       $s3, $zero, 0x25
    ctx->r19 = ADD32(0, 0X25);
    // 0x8006E8FC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_8006E900:
    // 0x8006E900: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006E904: slti        $at, $t1, 0x30
    ctx->r1 = SIGNED(ctx->r9) < 0X30 ? 1 : 0;
    // 0x8006E908: bne         $at, $zero, L_8006E928
    if (ctx->r1 != 0) {
        // 0x8006E90C: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8006E928;
    }
    // 0x8006E90C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E910: slti        $at, $t1, 0x3A
    ctx->r1 = SIGNED(ctx->r9) < 0X3A ? 1 : 0;
    // 0x8006E914: beq         $at, $zero, L_8006E928
    if (ctx->r1 == 0) {
        // 0x8006E918: nop
    
            goto L_8006E928;
    }
    // 0x8006E918: nop

    // 0x8006E91C: addiu       $v0, $t1, 0xE69
    ctx->r2 = ADD32(ctx->r9, 0XE69);
    // 0x8006E920: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8006E924: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
L_8006E928:
    // 0x8006E928: bne         $v0, $s3, L_8006E934
    if (ctx->r2 != ctx->r19) {
        // 0x8006E92C: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_8006E934;
    }
    // 0x8006E92C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8006E930: addiu       $v0, $zero, 0xE98
    ctx->r2 = ADD32(0, 0XE98);
L_8006E934:
    // 0x8006E934: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006E938: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8006E93C: jal         0x80065A64
    // 0x8006E940: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    rotatesprite_simple(rdram, ctx);
        goto after_0;
    // 0x8006E940: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    after_0:
    // 0x8006E944: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x8006E948: addiu       $s2, $s0, 0x4
    ctx->r18 = ADD32(ctx->r16, 0X4);
    // 0x8006E94C: andi        $t4, $s2, 0xFFFF
    ctx->r12 = ctx->r18 & 0XFFFF;
    // 0x8006E950: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x8006E954: beq         $v1, $zero, L_8006E96C
    if (ctx->r3 == 0) {
        // 0x8006E958: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8006E96C;
    }
    // 0x8006E958: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006E95C: beql        $s5, $v1, L_8006E970
    if (ctx->r21 == ctx->r3) {
        // 0x8006E960: lw          $ra, 0x34($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
            goto L_8006E970;
    }
    goto skip_0;
    // 0x8006E960: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    skip_0:
    // 0x8006E964: bnel        $s6, $v1, L_8006E900
    if (ctx->r22 != ctx->r3) {
        // 0x8006E968: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_8006E900;
    }
    goto skip_1;
    // 0x8006E968: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    skip_1:
L_8006E96C:
    // 0x8006E96C: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
L_8006E970:
    // 0x8006E970: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8006E974: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8006E978: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8006E97C: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8006E980: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8006E984: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006E988: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8006E98C: jr          $ra
    // 0x8006E990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006E990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void addammo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800756F4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800756F8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800756FC: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x80075700: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80075704: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80075708: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x8007570C: lh          $t1, 0x28E($v0)
    ctx->r9 = S32(MEM_H(ctx->r2, 0X28E));
    // 0x80075710: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80075714: lui         $v1, 0x8028
    ctx->r3 = S32(0X8028 << 16);
    // 0x80075718: addu        $t2, $t1, $a2
    ctx->r10 = ADD32(ctx->r9, ctx->r6);
    // 0x8007571C: sh          $t2, 0x28E($v0)
    MEM_H(0X28E, ctx->r2) = ctx->r10;
    // 0x80075720: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80075724: lw          $v1, -0x5C40($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5C40));
    // 0x80075728: lh          $t4, 0x28E($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X28E));
    // 0x8007572C: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80075730: beq         $at, $zero, L_8007573C
    if (ctx->r1 == 0) {
        // 0x80075734: nop
    
            goto L_8007573C;
    }
    // 0x80075734: nop

    // 0x80075738: sh          $v1, 0x28E($v0)
    MEM_H(0X28E, ctx->r2) = ctx->r3;
L_8007573C:
    // 0x8007573C: jr          $ra
    // 0x80075740: nop

    return;
    // 0x80075740: nop

;}
