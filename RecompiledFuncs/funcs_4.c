#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void spriteglass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A6CC: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8009A6D0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8009A6D4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8009A6D8: lh          $t9, -0x9DC($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X9DC));
    // 0x8009A6DC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8009A6E0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8009A6E4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8009A6E8: div         $zero, $t8, $t0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r8)));
    // 0x8009A6EC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8009A6F0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8009A6F4: sll         $s6, $a0, 16
    ctx->r22 = S32(ctx->r4 << 16);
    // 0x8009A6F8: sra         $t6, $s6, 16
    ctx->r14 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8009A6FC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8009A700: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x8009A704: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8009A708: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8009A70C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8009A710: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8009A714: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8009A718: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8009A71C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8009A720: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009A724: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8009A728: bne         $t0, $zero, L_8009A734
    if (ctx->r8 != 0) {
        // 0x8009A72C: nop
    
            goto L_8009A734;
    }
    // 0x8009A72C: nop

    // 0x8009A730: break       7
    do_break(2148116272);
L_8009A734:
    // 0x8009A734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009A738: bne         $t0, $at, L_8009A74C
    if (ctx->r8 != ctx->r1) {
        // 0x8009A73C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009A74C;
    }
    // 0x8009A73C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009A740: bne         $a1, $at, L_8009A74C
    if (ctx->r5 != ctx->r1) {
        // 0x8009A744: nop
    
            goto L_8009A74C;
    }
    // 0x8009A744: nop

    // 0x8009A748: break       6
    do_break(2148116296);
L_8009A74C:
    // 0x8009A74C: mflo        $a1
    ctx->r5 = lo;
    // 0x8009A750: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x8009A754: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8009A758: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8009A75C: blez        $t2, L_8009A874
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009A760: or          $s1, $t2, $zero
        ctx->r17 = ctx->r10 | 0;
            goto L_8009A874;
    }
    // 0x8009A760: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8009A764: sll         $t3, $s6, 2
    ctx->r11 = S32(ctx->r22 << 2);
    // 0x8009A768: subu        $t3, $t3, $s6
    ctx->r11 = SUB32(ctx->r11, ctx->r22);
    // 0x8009A76C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8009A770: subu        $t3, $t3, $s6
    ctx->r11 = SUB32(ctx->r11, ctx->r22);
    // 0x8009A774: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x8009A778: addiu       $t4, $t4, 0x6BA8
    ctx->r12 = ADD32(ctx->r12, 0X6BA8);
    // 0x8009A77C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8009A780: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x8009A784: addiu       $fp, $zero, -0x200
    ctx->r30 = ADD32(0, -0X200);
    // 0x8009A788: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_8009A78C:
    // 0x8009A78C: jal         0x80098054
    // 0x8009A790: nop

    krand(rdram, ctx);
        goto after_0;
    // 0x8009A790: nop

    after_0:
    // 0x8009A794: jal         0x80098054
    // 0x8009A798: andi        $s2, $v0, 0x7FF
    ctx->r18 = ctx->r2 & 0X7FF;
    krand(rdram, ctx);
        goto after_1;
    // 0x8009A798: andi        $s2, $v0, 0x7FF
    ctx->r18 = ctx->r2 & 0X7FF;
    after_1:
    // 0x8009A79C: lw          $t5, 0x8($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8009A7A0: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x8009A7A4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8009A7A8: jal         0x80098054
    // 0x8009A7AC: subu        $s3, $t5, $t7
    ctx->r19 = SUB32(ctx->r13, ctx->r15);
    krand(rdram, ctx);
        goto after_2;
    // 0x8009A7AC: subu        $s3, $t5, $t7
    ctx->r19 = SUB32(ctx->r13, ctx->r15);
    after_2:
    // 0x8009A7B0: jal         0x80098054
    // 0x8009A7B4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    krand(rdram, ctx);
        goto after_3;
    // 0x8009A7B4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    after_3:
    // 0x8009A7B8: jal         0x80098054
    // 0x8009A7BC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    krand(rdram, ctx);
        goto after_4;
    // 0x8009A7BC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    after_4:
    // 0x8009A7C0: div         $zero, $s1, $s7
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r23)));
    // 0x8009A7C4: mfhi        $t8
    ctx->r24 = hi;
    // 0x8009A7C8: andi        $t3, $s5, 0x3F
    ctx->r11 = ctx->r21 & 0X3F;
    // 0x8009A7CC: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x8009A7D0: subu        $t5, $fp, $t6
    ctx->r13 = SUB32(ctx->r30, ctx->r14);
    // 0x8009A7D4: addiu       $t4, $t3, 0x20
    ctx->r12 = ADD32(ctx->r11, 0X20);
    // 0x8009A7D8: addiu       $t9, $t8, 0x407
    ctx->r25 = ADD32(ctx->r24, 0X407);
    // 0x8009A7DC: andi        $t0, $s4, 0xF
    ctx->r8 = ctx->r20 & 0XF;
    // 0x8009A7E0: addiu       $t1, $zero, 0x24
    ctx->r9 = ADD32(0, 0X24);
    // 0x8009A7E4: addiu       $t2, $zero, 0x24
    ctx->r10 = ADD32(0, 0X24);
    // 0x8009A7E8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8009A7EC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8009A7F0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8009A7F4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009A7F8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009A7FC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A800: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8009A804: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8009A808: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    // 0x8009A80C: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8009A810: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8009A814: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8009A818: bne         $s7, $zero, L_8009A824
    if (ctx->r23 != 0) {
        // 0x8009A81C: nop
    
            goto L_8009A824;
    }
    // 0x8009A81C: nop

    // 0x8009A820: break       7
    do_break(2148116512);
L_8009A824:
    // 0x8009A824: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009A828: bne         $s7, $at, L_8009A83C
    if (ctx->r23 != ctx->r1) {
        // 0x8009A82C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009A83C;
    }
    // 0x8009A82C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009A830: bne         $s1, $at, L_8009A83C
    if (ctx->r17 != ctx->r1) {
        // 0x8009A834: nop
    
            goto L_8009A83C;
    }
    // 0x8009A834: nop

    // 0x8009A838: break       6
    do_break(2148116536);
L_8009A83C:
    // 0x8009A83C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009A840: jal         0x8009B028
    // 0x8009A844: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    EGS(rdram, ctx);
        goto after_5;
    // 0x8009A844: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    after_5:
    // 0x8009A848: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8009A84C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8009A850: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8009A854: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8009A858: lbu         $t8, 0x25($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X25);
    // 0x8009A85C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8009A860: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x8009A864: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8009A868: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8009A86C: bgtz        $s1, L_8009A78C
    if (SIGNED(ctx->r17) > 0) {
        // 0x8009A870: sb          $t8, 0x6BCD($at)
        MEM_B(0X6BCD, ctx->r1) = ctx->r24;
            goto L_8009A78C;
    }
    // 0x8009A870: sb          $t8, 0x6BCD($at)
    MEM_B(0X6BCD, ctx->r1) = ctx->r24;
L_8009A874:
    // 0x8009A874: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x8009A878: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8009A87C: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8009A880: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8009A884: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8009A888: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x8009A88C: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8009A890: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x8009A894: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x8009A898: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x8009A89C: jr          $ra
    // 0x8009A8A0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8009A8A0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void adjustceilingpanning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AF24: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005AF28: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005AF2C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8005AF30: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8005AF34: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8005AF38: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8005AF3C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8005AF40: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x8005AF44: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005AF48: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8005AF4C: lhu         $a3, 0x20($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X20);
    // 0x8005AF50: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8005AF54: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x8005AF58: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8005AF5C: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8005AF60: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x8005AF64: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x8005AF68: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005AF6C: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x8005AF70: lbu         $t1, 0x2C($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2C);
    // 0x8005AF74: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8005AF78: addu        $a3, $t9, $at
    ctx->r7 = ADD32(ctx->r25, ctx->r1);
    // 0x8005AF7C: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x8005AF80: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x8005AF84: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005AF88: sll         $t6, $t9, 19
    ctx->r14 = S32(ctx->r25 << 19);
    // 0x8005AF8C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8005AF90: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8005AF94: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8005AF98: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005AF9C: blez        $t1, L_8005B1BC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8005AFA0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8005B1BC;
    }
    // 0x8005AFA0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005AFA4: addiu       $s1, $sp, 0x1C
    ctx->r17 = ADD32(ctx->r29, 0X1C);
    // 0x8005AFA8: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
L_8005AFAC:
    // 0x8005AFAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005AFB0:
    // 0x8005AFB0: lh          $t8, 0x6($a3)
    ctx->r24 = S32(MEM_H(ctx->r7, 0X6));
    // 0x8005AFB4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8005AFB8: addu        $t6, $s0, $v1
    ctx->r14 = ADD32(ctx->r16, ctx->r3);
    // 0x8005AFBC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x8005AFC0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8005AFC4: lh          $t7, 0x8($a3)
    ctx->r15 = S32(MEM_H(ctx->r7, 0X8));
    // 0x8005AFC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005AFCC: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x8005AFD0: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8005AFD4: addu        $t9, $s1, $v1
    ctx->r25 = ADD32(ctx->r17, ctx->r3);
    // 0x8005AFD8: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8005AFDC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8005AFE0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005AFE4: bne         $at, $zero, L_8005AFB0
    if (ctx->r1 != 0) {
        // 0x8005AFE8: addiu       $a3, $a3, 0xA
        ctx->r7 = ADD32(ctx->r7, 0XA);
            goto L_8005AFB0;
    }
    // 0x8005AFE8: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x8005AFEC: lw          $v1, 0x28($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8005AFF0: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8005AFF4: lw          $t2, 0x30($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8005AFF8: slti        $at, $v1, 0x7FF8
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF8 ? 1 : 0;
    // 0x8005AFFC: lw          $t3, 0x1C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8005B000: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005B004: bne         $at, $zero, L_8005B020
    if (ctx->r1 != 0) {
        // 0x8005B008: lw          $t5, 0x24($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8005B020;
    }
    // 0x8005B008: lw          $t5, 0x24($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8005B00C: slti        $at, $a0, 0x7FF8
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF8 ? 1 : 0;
    // 0x8005B010: bne         $at, $zero, L_8005B020
    if (ctx->r1 != 0) {
        // 0x8005B014: slti        $at, $t2, 0x7FF8
        ctx->r1 = SIGNED(ctx->r10) < 0X7FF8 ? 1 : 0;
            goto L_8005B020;
    }
    // 0x8005B014: slti        $at, $t2, 0x7FF8
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF8 ? 1 : 0;
    // 0x8005B018: beql        $at, $zero, L_8005B050
    if (ctx->r1 == 0) {
        // 0x8005B01C: slti        $at, $v1, 0x7FF9
        ctx->r1 = SIGNED(ctx->r3) < 0X7FF9 ? 1 : 0;
            goto L_8005B050;
    }
    goto skip_0;
    // 0x8005B01C: slti        $at, $v1, 0x7FF9
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF9 ? 1 : 0;
    skip_0:
L_8005B020:
    // 0x8005B020: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
L_8005B024:
    // 0x8005B024: slti        $at, $v1, 0x7FF8
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF8 ? 1 : 0;
    // 0x8005B028: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x8005B02C: bne         $at, $zero, L_8005B020
    if (ctx->r1 != 0) {
        // 0x8005B030: addiu       $t2, $t2, 0x1000
        ctx->r10 = ADD32(ctx->r10, 0X1000);
            goto L_8005B020;
    }
    // 0x8005B030: addiu       $t2, $t2, 0x1000
    ctx->r10 = ADD32(ctx->r10, 0X1000);
    // 0x8005B034: slti        $at, $a0, 0x7FF8
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF8 ? 1 : 0;
    // 0x8005B038: bnel        $at, $zero, L_8005B024
    if (ctx->r1 != 0) {
        // 0x8005B03C: addiu       $v1, $v1, 0x1000
        ctx->r3 = ADD32(ctx->r3, 0X1000);
            goto L_8005B024;
    }
    goto skip_1;
    // 0x8005B03C: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    skip_1:
    // 0x8005B040: slti        $at, $t2, 0x7FF8
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF8 ? 1 : 0;
    // 0x8005B044: bnel        $at, $zero, L_8005B024
    if (ctx->r1 != 0) {
        // 0x8005B048: addiu       $v1, $v1, 0x1000
        ctx->r3 = ADD32(ctx->r3, 0X1000);
            goto L_8005B024;
    }
    goto skip_2;
    // 0x8005B048: addiu       $v1, $v1, 0x1000
    ctx->r3 = ADD32(ctx->r3, 0X1000);
    skip_2:
    // 0x8005B04C: slti        $at, $v1, 0x7FF9
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF9 ? 1 : 0;
L_8005B050:
    // 0x8005B050: beq         $at, $zero, L_8005B06C
    if (ctx->r1 == 0) {
        // 0x8005B054: addiu       $a3, $a3, -0x1E
        ctx->r7 = ADD32(ctx->r7, -0X1E);
            goto L_8005B06C;
    }
    // 0x8005B054: addiu       $a3, $a3, -0x1E
    ctx->r7 = ADD32(ctx->r7, -0X1E);
    // 0x8005B058: slti        $at, $a0, 0x7FF9
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF9 ? 1 : 0;
    // 0x8005B05C: beq         $at, $zero, L_8005B06C
    if (ctx->r1 == 0) {
        // 0x8005B060: slti        $at, $t2, 0x7FF9
        ctx->r1 = SIGNED(ctx->r10) < 0X7FF9 ? 1 : 0;
            goto L_8005B06C;
    }
    // 0x8005B060: slti        $at, $t2, 0x7FF9
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF9 ? 1 : 0;
    // 0x8005B064: bnel        $at, $zero, L_8005B09C
    if (ctx->r1 != 0) {
        // 0x8005B068: slti        $at, $t3, 0x7FF8
        ctx->r1 = SIGNED(ctx->r11) < 0X7FF8 ? 1 : 0;
            goto L_8005B09C;
    }
    goto skip_3;
    // 0x8005B068: slti        $at, $t3, 0x7FF8
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF8 ? 1 : 0;
    skip_3:
L_8005B06C:
    // 0x8005B06C: addiu       $v1, $v1, -0x1000
    ctx->r3 = ADD32(ctx->r3, -0X1000);
L_8005B070:
    // 0x8005B070: slti        $at, $v1, 0x7FF9
    ctx->r1 = SIGNED(ctx->r3) < 0X7FF9 ? 1 : 0;
    // 0x8005B074: addiu       $a0, $a0, -0x1000
    ctx->r4 = ADD32(ctx->r4, -0X1000);
    // 0x8005B078: beq         $at, $zero, L_8005B06C
    if (ctx->r1 == 0) {
        // 0x8005B07C: addiu       $t2, $t2, -0x1000
        ctx->r10 = ADD32(ctx->r10, -0X1000);
            goto L_8005B06C;
    }
    // 0x8005B07C: addiu       $t2, $t2, -0x1000
    ctx->r10 = ADD32(ctx->r10, -0X1000);
    // 0x8005B080: slti        $at, $a0, 0x7FF9
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF9 ? 1 : 0;
    // 0x8005B084: beql        $at, $zero, L_8005B070
    if (ctx->r1 == 0) {
        // 0x8005B088: addiu       $v1, $v1, -0x1000
        ctx->r3 = ADD32(ctx->r3, -0X1000);
            goto L_8005B070;
    }
    goto skip_4;
    // 0x8005B088: addiu       $v1, $v1, -0x1000
    ctx->r3 = ADD32(ctx->r3, -0X1000);
    skip_4:
    // 0x8005B08C: slti        $at, $t2, 0x7FF9
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF9 ? 1 : 0;
    // 0x8005B090: beql        $at, $zero, L_8005B070
    if (ctx->r1 == 0) {
        // 0x8005B094: addiu       $v1, $v1, -0x1000
        ctx->r3 = ADD32(ctx->r3, -0X1000);
            goto L_8005B070;
    }
    goto skip_5;
    // 0x8005B094: addiu       $v1, $v1, -0x1000
    ctx->r3 = ADD32(ctx->r3, -0X1000);
    skip_5:
    // 0x8005B098: slti        $at, $t3, 0x7FF8
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF8 ? 1 : 0;
L_8005B09C:
    // 0x8005B09C: bne         $at, $zero, L_8005B0B8
    if (ctx->r1 != 0) {
        // 0x8005B0A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005B0B8;
    }
    // 0x8005B0A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005B0A4: slti        $at, $t4, 0x7FF8
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF8 ? 1 : 0;
    // 0x8005B0A8: bne         $at, $zero, L_8005B0B8
    if (ctx->r1 != 0) {
        // 0x8005B0AC: slti        $at, $t5, 0x7FF8
        ctx->r1 = SIGNED(ctx->r13) < 0X7FF8 ? 1 : 0;
            goto L_8005B0B8;
    }
    // 0x8005B0AC: slti        $at, $t5, 0x7FF8
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF8 ? 1 : 0;
    // 0x8005B0B0: beql        $at, $zero, L_8005B0E8
    if (ctx->r1 == 0) {
        // 0x8005B0B4: slti        $at, $t3, 0x7FF9
        ctx->r1 = SIGNED(ctx->r11) < 0X7FF9 ? 1 : 0;
            goto L_8005B0E8;
    }
    goto skip_6;
    // 0x8005B0B4: slti        $at, $t3, 0x7FF9
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF9 ? 1 : 0;
    skip_6:
L_8005B0B8:
    // 0x8005B0B8: addiu       $t3, $t3, 0x1000
    ctx->r11 = ADD32(ctx->r11, 0X1000);
L_8005B0BC:
    // 0x8005B0BC: slti        $at, $t3, 0x7FF8
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF8 ? 1 : 0;
    // 0x8005B0C0: addiu       $t4, $t4, 0x1000
    ctx->r12 = ADD32(ctx->r12, 0X1000);
    // 0x8005B0C4: bne         $at, $zero, L_8005B0B8
    if (ctx->r1 != 0) {
        // 0x8005B0C8: addiu       $t5, $t5, 0x1000
        ctx->r13 = ADD32(ctx->r13, 0X1000);
            goto L_8005B0B8;
    }
    // 0x8005B0C8: addiu       $t5, $t5, 0x1000
    ctx->r13 = ADD32(ctx->r13, 0X1000);
    // 0x8005B0CC: slti        $at, $t4, 0x7FF8
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF8 ? 1 : 0;
    // 0x8005B0D0: bnel        $at, $zero, L_8005B0BC
    if (ctx->r1 != 0) {
        // 0x8005B0D4: addiu       $t3, $t3, 0x1000
        ctx->r11 = ADD32(ctx->r11, 0X1000);
            goto L_8005B0BC;
    }
    goto skip_7;
    // 0x8005B0D4: addiu       $t3, $t3, 0x1000
    ctx->r11 = ADD32(ctx->r11, 0X1000);
    skip_7:
    // 0x8005B0D8: slti        $at, $t5, 0x7FF8
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF8 ? 1 : 0;
    // 0x8005B0DC: bnel        $at, $zero, L_8005B0BC
    if (ctx->r1 != 0) {
        // 0x8005B0E0: addiu       $t3, $t3, 0x1000
        ctx->r11 = ADD32(ctx->r11, 0X1000);
            goto L_8005B0BC;
    }
    goto skip_8;
    // 0x8005B0E0: addiu       $t3, $t3, 0x1000
    ctx->r11 = ADD32(ctx->r11, 0X1000);
    skip_8:
    // 0x8005B0E4: slti        $at, $t3, 0x7FF9
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF9 ? 1 : 0;
L_8005B0E8:
    // 0x8005B0E8: beq         $at, $zero, L_8005B104
    if (ctx->r1 == 0) {
        // 0x8005B0EC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8005B104;
    }
    // 0x8005B0EC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005B0F0: slti        $at, $t4, 0x7FF9
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF9 ? 1 : 0;
    // 0x8005B0F4: beq         $at, $zero, L_8005B104
    if (ctx->r1 == 0) {
        // 0x8005B0F8: slti        $at, $t5, 0x7FF9
        ctx->r1 = SIGNED(ctx->r13) < 0X7FF9 ? 1 : 0;
            goto L_8005B104;
    }
    // 0x8005B0F8: slti        $at, $t5, 0x7FF9
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF9 ? 1 : 0;
    // 0x8005B0FC: bnel        $at, $zero, L_8005B134
    if (ctx->r1 != 0) {
        // 0x8005B100: sw          $v1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r3;
            goto L_8005B134;
    }
    goto skip_9;
    // 0x8005B100: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    skip_9:
L_8005B104:
    // 0x8005B104: addiu       $t3, $t3, -0x1000
    ctx->r11 = ADD32(ctx->r11, -0X1000);
L_8005B108:
    // 0x8005B108: slti        $at, $t3, 0x7FF9
    ctx->r1 = SIGNED(ctx->r11) < 0X7FF9 ? 1 : 0;
    // 0x8005B10C: addiu       $t4, $t4, -0x1000
    ctx->r12 = ADD32(ctx->r12, -0X1000);
    // 0x8005B110: beq         $at, $zero, L_8005B104
    if (ctx->r1 == 0) {
        // 0x8005B114: addiu       $t5, $t5, -0x1000
        ctx->r13 = ADD32(ctx->r13, -0X1000);
            goto L_8005B104;
    }
    // 0x8005B114: addiu       $t5, $t5, -0x1000
    ctx->r13 = ADD32(ctx->r13, -0X1000);
    // 0x8005B118: slti        $at, $t4, 0x7FF9
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF9 ? 1 : 0;
    // 0x8005B11C: beql        $at, $zero, L_8005B108
    if (ctx->r1 == 0) {
        // 0x8005B120: addiu       $t3, $t3, -0x1000
        ctx->r11 = ADD32(ctx->r11, -0X1000);
            goto L_8005B108;
    }
    goto skip_10;
    // 0x8005B120: addiu       $t3, $t3, -0x1000
    ctx->r11 = ADD32(ctx->r11, -0X1000);
    skip_10:
    // 0x8005B124: slti        $at, $t5, 0x7FF9
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF9 ? 1 : 0;
    // 0x8005B128: beql        $at, $zero, L_8005B108
    if (ctx->r1 == 0) {
        // 0x8005B12C: addiu       $t3, $t3, -0x1000
        ctx->r11 = ADD32(ctx->r11, -0X1000);
            goto L_8005B108;
    }
    goto skip_11;
    // 0x8005B12C: addiu       $t3, $t3, -0x1000
    ctx->r11 = ADD32(ctx->r11, -0X1000);
    skip_11:
    // 0x8005B130: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
L_8005B134:
    // 0x8005B134: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8005B138: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8005B13C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8005B140: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8005B144: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8005B148:
    // 0x8005B148: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8005B14C: addu        $t7, $s0, $v1
    ctx->r15 = ADD32(ctx->r16, ctx->r3);
    // 0x8005B150: lw          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X0));
    // 0x8005B154: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005B158: addu        $t9, $s1, $v1
    ctx->r25 = ADD32(ctx->r17, ctx->r3);
    // 0x8005B15C: sh          $t8, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r24;
    // 0x8005B160: lw          $t6, 0x0($t9)
    ctx->r14 = S32(MEM_W(ctx->r25, 0X0));
    // 0x8005B164: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8005B168: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8005B16C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8005B170: addiu       $a3, $a3, 0xA
    ctx->r7 = ADD32(ctx->r7, 0XA);
    // 0x8005B174: bne         $at, $zero, L_8005B148
    if (ctx->r1 != 0) {
        // 0x8005B178: sh          $t6, -0x2($a3)
        MEM_H(-0X2, ctx->r7) = ctx->r14;
            goto L_8005B148;
    }
    // 0x8005B178: sh          $t6, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r14;
    // 0x8005B17C: lw          $v1, 0x28($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8005B180: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8005B184: lw          $t2, 0x30($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8005B188: lw          $t3, 0x1C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8005B18C: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005B190: lw          $t5, 0x24($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8005B194: andi        $t8, $t0, 0xFFFF
    ctx->r24 = ctx->r8 & 0XFFFF;
    // 0x8005B198: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005B19C: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8005B1A0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8005B1A4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8005B1A8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8005B1AC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8005B1B0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8005B1B4: bne         $at, $zero, L_8005AFAC
    if (ctx->r1 != 0) {
        // 0x8005B1B8: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_8005AFAC;
    }
    // 0x8005B1B8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8005B1BC:
    // 0x8005B1BC: lw          $s0, 0x8($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X8));
    // 0x8005B1C0: lw          $s1, 0xC($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XC));
    // 0x8005B1C4: jr          $ra
    // 0x8005B1C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005B1C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _allocatePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9EE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9EE8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C9EEC: lw          $a3, 0x14($a0)
    ctx->r7 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800C9EF0: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800C9EF4: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C9EF8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C9EFC: beq         $a3, $zero, L_800C9F34
    if (ctx->r7 == 0) {
        // 0x800C9F00: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C9F34;
    }
    // 0x800C9F00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9F04: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C9F08: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C9F0C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C9F10: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C9F14: jal         0x800BF770
    // 0x800C9F18: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C9F18: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800C9F1C: lw          $t0, 0x28($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800C9F20: lw          $a0, 0x24($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C9F24: jal         0x800BF7A0
    // 0x800C9F28: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C9F28: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x800C9F2C: b           L_800C9FB4
    // 0x800C9F30: lw          $v1, 0x1C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_800C9FB4;
    // 0x800C9F30: lw          $v1, 0x1C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X1C));
L_800C9F34:
    // 0x800C9F34: lw          $a3, 0x4($t0)
    ctx->r7 = S32(MEM_W(ctx->r8, 0X4));
    // 0x800C9F38: beq         $a3, $zero, L_800C9F6C
    if (ctx->r7 == 0) {
        // 0x800C9F3C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800C9F6C;
    }
    // 0x800C9F3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C9F40: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C9F44: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C9F48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C9F4C: jal         0x800BF770
    // 0x800C9F50: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800C9F50: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800C9F54: lw          $t0, 0x28($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800C9F58: lw          $a0, 0x24($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C9F5C: jal         0x800BF7A0
    // 0x800C9F60: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800C9F60: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800C9F64: b           L_800C9FB4
    // 0x800C9F68: lw          $v1, 0x1C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_800C9FB4;
    // 0x800C9F68: lw          $v1, 0x1C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X1C));
L_800C9F6C:
    // 0x800C9F6C: lw          $a3, 0xC($t0)
    ctx->r7 = S32(MEM_W(ctx->r8, 0XC));
    // 0x800C9F70: beql        $a3, $zero, L_800C9FB8
    if (ctx->r7 == 0) {
        // 0x800C9F74: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800C9FB8;
    }
    goto skip_0;
    // 0x800C9F74: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800C9F78: lw          $t8, 0x8($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X8));
L_800C9F7C:
    // 0x800C9F7C: lh          $t9, 0x16($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X16));
    // 0x800C9F80: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C9F84: bnel        $at, $zero, L_800C9FAC
    if (ctx->r1 != 0) {
        // 0x800C9F88: lw          $a3, 0x0($a3)
        ctx->r7 = S32(MEM_W(ctx->r7, 0X0));
            goto L_800C9FAC;
    }
    goto skip_1;
    // 0x800C9F88: lw          $a3, 0x0($a3)
    ctx->r7 = S32(MEM_W(ctx->r7, 0X0));
    skip_1:
    // 0x800C9F8C: lw          $t1, 0xD8($a3)
    ctx->r9 = S32(MEM_W(ctx->r7, 0XD8));
    // 0x800C9F90: bnel        $t1, $zero, L_800C9FAC
    if (ctx->r9 != 0) {
        // 0x800C9F94: lw          $a3, 0x0($a3)
        ctx->r7 = S32(MEM_W(ctx->r7, 0X0));
            goto L_800C9FAC;
    }
    goto skip_2;
    // 0x800C9F94: lw          $a3, 0x0($a3)
    ctx->r7 = S32(MEM_W(ctx->r7, 0X0));
    skip_2:
    // 0x800C9F98: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C9F9C: lw          $t2, 0x8($a3)
    ctx->r10 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800C9FA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C9FA4: lh          $a2, 0x16($t2)
    ctx->r6 = S32(MEM_H(ctx->r10, 0X16));
    // 0x800C9FA8: lw          $a3, 0x0($a3)
    ctx->r7 = S32(MEM_W(ctx->r7, 0X0));
L_800C9FAC:
    // 0x800C9FAC: bnel        $a3, $zero, L_800C9F7C
    if (ctx->r7 != 0) {
        // 0x800C9FB0: lw          $t8, 0x8($a3)
        ctx->r24 = S32(MEM_W(ctx->r7, 0X8));
            goto L_800C9F7C;
    }
    goto skip_3;
    // 0x800C9FB0: lw          $t8, 0x8($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X8));
    skip_3:
L_800C9FB4:
    // 0x800C9FB4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C9FB8:
    // 0x800C9FB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9FBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C9FC0: jr          $ra
    // 0x800C9FC4: nop

    return;
    // 0x800C9FC4: nop

;}
RECOMP_FUNC void loadefs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4D34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B4D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4D3C: jal         0x80091A68
    // 0x800B4D40: nop

    initengine(rdram, ctx);
        goto after_0;
    // 0x800B4D40: nop

    after_0:
    // 0x800B4D44: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800B4D48: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x800B4D4C: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B4D50: lui         $a1, 0xFD05
    ctx->r5 = S32(0XFD05 << 16);
    // 0x800B4D54: lui         $a0, 0x2FA
    ctx->r4 = S32(0X2FA << 16);
    // 0x800B4D58: ori         $a0, $a0, 0xF081
    ctx->r4 = ctx->r4 | 0XF081;
    // 0x800B4D5C: ori         $a1, $a1, 0xF80
    ctx->r5 = ctx->r5 | 0XF80;
    // 0x800B4D60: addiu       $a2, $a2, -0x1700
    ctx->r6 = ADD32(ctx->r6, -0X1700);
    // 0x800B4D64: addiu       $a3, $a3, -0x447C
    ctx->r7 = ADD32(ctx->r7, -0X447C);
    // 0x800B4D68: addiu       $v0, $v0, -0x1700
    ctx->r2 = ADD32(ctx->r2, -0X1700);
    // 0x800B4D6C: lw          $v1, 0x0($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0X0));
L_800B4D70:
    // 0x800B4D70: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B4D74: bne         $at, $zero, L_800B4D88
    if (ctx->r1 != 0) {
        // 0x800B4D78: addu        $t6, $v1, $a1
        ctx->r14 = ADD32(ctx->r3, ctx->r5);
            goto L_800B4D88;
    }
    // 0x800B4D78: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x800B4D7C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B4D80: addu        $t8, $t6, $a2
    ctx->r24 = ADD32(ctx->r14, ctx->r6);
    // 0x800B4D84: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800B4D88:
    // 0x800B4D88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B4D8C: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x800B4D90: bnel        $at, $zero, L_800B4D70
    if (ctx->r1 != 0) {
        // 0x800B4D94: lw          $v1, 0x0($v0)
        ctx->r3 = S32(MEM_W(ctx->r2, 0X0));
            goto L_800B4D70;
    }
    goto skip_0;
    // 0x800B4D94: lw          $v1, 0x0($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0X0));
    skip_0:
    // 0x800B4D98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B4D9C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800B4DA0: sw          $t9, -0x5474($at)
    MEM_W(-0X5474, ctx->r1) = ctx->r25;
    // 0x800B4DA4: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800B4DA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B4DAC: sb          $t0, 0x5AF5($at)
    MEM_B(0X5AF5, ctx->r1) = ctx->r8;
    // 0x800B4DB0: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800B4DB4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800B4DB8: sb          $t1, 0x5E81($at)
    MEM_B(0X5E81, ctx->r1) = ctx->r9;
    // 0x800B4DBC: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800B4DC0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B4DC4: sb          $t2, 0x620D($at)
    MEM_B(0X620D, ctx->r1) = ctx->r10;
    // 0x800B4DC8: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800B4DCC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B4DD0: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800B4DD4: addiu       $v0, $v0, -0x5C40
    ctx->r2 = ADD32(ctx->r2, -0X5C40);
    // 0x800B4DD8: sb          $t3, 0x6599($at)
    MEM_B(0X6599, ctx->r1) = ctx->r11;
    // 0x800B4DDC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800B4DE0: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x800B4DE4: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x800B4DE8: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x800B4DEC: addiu       $t5, $zero, 0x190
    ctx->r13 = ADD32(0, 0X190);
    // 0x800B4DF0: addiu       $t6, $zero, 0x42
    ctx->r14 = ADD32(0, 0X42);
    // 0x800B4DF4: addiu       $t7, $zero, 0x30
    ctx->r15 = ADD32(0, 0X30);
    // 0x800B4DF8: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800B4DFC: addiu       $t9, $zero, 0x24
    ctx->r25 = ADD32(0, 0X24);
    // 0x800B4E00: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800B4E04: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    // 0x800B4E08: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B4E0C: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x800B4E10: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x800B4E14: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x800B4E18: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x800B4E1C: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x800B4E20: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x800B4E24: sw          $t8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r24;
    // 0x800B4E28: sw          $a0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r4;
    // 0x800B4E2C: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
    // 0x800B4E30: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x800B4E34: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    // 0x800B4E38: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x800B4E3C: sw          $t1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r9;
    // 0x800B4E40: jr          $ra
    // 0x800B4E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B4E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056154: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80056158: addiu       $a2, $a2, -0x27CC
    ctx->r6 = ADD32(ctx->r6, -0X27CC);
    // 0x8005615C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056160: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80056164: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80056168: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8005616C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80056170: ori         $a1, $a1, 0x87E0
    ctx->r5 = ctx->r5 | 0X87E0;
    // 0x80056174: jal         0x80071F44
    // 0x80056178: addiu       $a0, $a0, -0x27C8
    ctx->r4 = ADD32(ctx->r4, -0X27C8);
    allocache2(rdram, ctx);
        goto after_0;
    // 0x80056178: addiu       $a0, $a0, -0x27C8
    ctx->r4 = ADD32(ctx->r4, -0X27C8);
    after_0:
    // 0x8005617C: lui         $a0, 0x8026
    ctx->r4 = S32(0X8026 << 16);
    // 0x80056180: lui         $a1, 0x3F
    ctx->r5 = S32(0X3F << 16);
    // 0x80056184: addiu       $a1, $a1, -0x6AB0
    ctx->r5 = ADD32(ctx->r5, -0X6AB0);
    // 0x80056188: addiu       $a0, $a0, -0x140
    ctx->r4 = ADD32(ctx->r4, -0X140);
    // 0x8005618C: jal         0x8004B560
    // 0x80056190: ori         $a2, $zero, 0xB3F8
    ctx->r6 = 0 | 0XB3F8;
    copyfromrom(rdram, ctx);
        goto after_1;
    // 0x80056190: ori         $a2, $zero, 0xB3F8
    ctx->r6 = 0 | 0XB3F8;
    after_1:
    // 0x80056194: lui         $a0, 0x8026
    ctx->r4 = S32(0X8026 << 16);
    // 0x80056198: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8005619C: lw          $a1, -0x27C8($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X27C8));
    // 0x800561A0: jal         0x80070BAC
    // 0x800561A4: addiu       $a0, $a0, -0x140
    ctx->r4 = ADD32(ctx->r4, -0X140);
    RNCDecompress(rdram, ctx);
        goto after_2;
    // 0x800561A4: addiu       $a0, $a0, -0x140
    ctx->r4 = ADD32(ctx->r4, -0X140);
    after_2:
    // 0x800561A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800561AC: sw          $zero, -0x27D8($at)
    MEM_W(-0X27D8, ctx->r1) = 0;
    // 0x800561B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800561B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800561B8: sw          $zero, -0x27D4($at)
    MEM_W(-0X27D4, ctx->r1) = 0;
    // 0x800561BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800561C0: swc1        $f0, -0x27D0($at)
    MEM_W(-0X27D0, ctx->r1) = ctx->f0.u32l;
    // 0x800561C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800561C8: sw          $zero, -0x27E0($at)
    MEM_W(-0X27E0, ctx->r1) = 0;
    // 0x800561CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800561D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800561D4: sb          $v0, -0x27DC($at)
    MEM_B(-0X27DC, ctx->r1) = ctx->r2;
    // 0x800561D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800561DC: sb          $v0, -0x27DB($at)
    MEM_B(-0X27DB, ctx->r1) = ctx->r2;
    // 0x800561E0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800561E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800561E8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800561EC: sb          $t7, -0x27DA($at)
    MEM_B(-0X27DA, ctx->r1) = ctx->r15;
    // 0x800561F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800561F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800561F8: jr          $ra
    // 0x800561FC: swc1        $f0, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->f0.u32l;
    return;
    // 0x800561FC: swc1        $f0, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80066250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066250: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80066254: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80066258: addiu       $a0, $a0, -0x2790
    ctx->r4 = ADD32(ctx->r4, -0X2790);
    // 0x8006625C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80066260: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
L_80066264:
    // 0x80066264: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066268: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006626C: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80066270: sra         $v0, $t1, 16
    ctx->r2 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80066274: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80066278: mflo        $t6
    ctx->r14 = lo;
    // 0x8006627C: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80066280: lb          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_B(ctx->r3, 0X0));
    // 0x80066284: beq         $t7, $zero, L_800662D4
    if (ctx->r15 == 0) {
        // 0x80066288: nop
    
            goto L_800662D4;
    }
    // 0x80066288: nop

    // 0x8006628C: lh          $t8, 0x6($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X6));
    // 0x80066290: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = S32(MEM_W(ctx->r3, 0X14));
    // 0x80066294: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = S32(MEM_W(ctx->r3, 0X18));
    // 0x80066298: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8006629C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = S32(MEM_W(ctx->r3, 0X10));
    // 0x800662A0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800662A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800662A8: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
    // 0x800662AC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800662B0: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = S32(MEM_W(ctx->r3, 0X14));
    // 0x800662B4: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800662B8: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
    // 0x800662BC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800662C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800662C4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800662C8: bc1f        L_800662D4
    if (!c1cs) {
        // 0x800662CC: sh          $t0, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r8;
            goto L_800662D4;
    }
    // 0x800662CC: sh          $t0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r8;
    // 0x800662D0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_800662D4:
    // 0x800662D4: bne         $at, $zero, L_80066264
    if (ctx->r1 != 0) {
        // 0x800662D8: nop
    
            goto L_80066264;
    }
    // 0x800662D8: nop

    // 0x800662DC: jr          $ra
    // 0x800662E0: nop

    return;
    // 0x800662E0: nop

;}
RECOMP_FUNC void drawbaroverlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F004: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006F00C: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8006F010: addiu       $s0, $s0, -0x134E
    ctx->r16 = ADD32(ctx->r16, -0X134E);
    // 0x8006F014: lh          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006F018: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006F01C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F020: slti        $at, $t6, -0x46
    ctx->r1 = SIGNED(ctx->r14) < -0X46 ? 1 : 0;
    // 0x8006F024: bne         $at, $zero, L_8006F16C
    if (ctx->r1 != 0) {
        // 0x8006F028: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8006F16C;
    }
    // 0x8006F028: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006F02C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006F030: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8006F034: jal         0x8006E994
    // 0x8006F038: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    setrotatespriteflags(rdram, ctx);
        goto after_0;
    // 0x8006F038: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    after_0:
    // 0x8006F03C: lh          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006F040: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006F044: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006F048: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8006F04C: lh          $t9, -0x1344($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X1344));
    // 0x8006F050: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8006F054: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8006F058: addiu       $t8, $t7, 0x5
    ctx->r24 = ADD32(ctx->r15, 0X5);
    // 0x8006F05C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8006F060: addiu       $t0, $t9, -0xE
    ctx->r8 = ADD32(ctx->r25, -0XE);
    // 0x8006F064: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8006F068: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006F06C: addiu       $t1, $zero, 0xE31
    ctx->r9 = ADD32(0, 0XE31);
    // 0x8006F070: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8006F074: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006F078: jal         0x8005D13C
    // 0x8006F07C: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    rotatesprite(rdram, ctx);
        goto after_1;
    // 0x8006F07C: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    after_1:
    // 0x8006F080: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8006F084: lh          $t5, -0x1344($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X1344));
    // 0x8006F088: lh          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006F08C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006F090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006F094: addiu       $t3, $zero, 0x13A
    ctx->r11 = ADD32(0, 0X13A);
    // 0x8006F098: addiu       $t6, $t5, -0xE
    ctx->r14 = ADD32(ctx->r13, -0XE);
    // 0x8006F09C: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8006F0A0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8006F0A4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006F0A8: addiu       $t7, $zero, 0xE31
    ctx->r15 = ADD32(0, 0XE31);
    // 0x8006F0AC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8006F0B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006F0B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006F0B8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8006F0BC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006F0C0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006F0C4: jal         0x8005D13C
    // 0x8006F0C8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    rotatesprite(rdram, ctx);
        goto after_2;
    // 0x8006F0C8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_2:
    // 0x8006F0CC: lh          $t9, 0x2A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X2A));
    // 0x8006F0D0: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8006F0D4: lh          $t1, -0x9DC($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, -0X9DC));
    // 0x8006F0D8: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8006F0DC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8006F0E0: bne         $t0, $t1, L_8006F16C
    if (ctx->r8 != ctx->r9) {
        // 0x8006F0E4: addiu       $a0, $a0, -0x134C
        ctx->r4 = ADD32(ctx->r4, -0X134C);
            goto L_8006F16C;
    }
    // 0x8006F0E4: addiu       $a0, $a0, -0x134C
    ctx->r4 = ADD32(ctx->r4, -0X134C);
    // 0x8006F0E8: lh          $t3, 0x0($a0)
    ctx->r11 = S32(MEM_H(ctx->r4, 0X0));
    // 0x8006F0EC: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x8006F0F0: addiu       $v1, $v1, -0x1350
    ctx->r3 = ADD32(ctx->r3, -0X1350);
    // 0x8006F0F4: beql        $t3, $zero, L_8006F124
    if (ctx->r11 == 0) {
        // 0x8006F0F8: lh          $v0, 0x0($v1)
        ctx->r2 = S32(MEM_H(ctx->r3, 0X0));
            goto L_8006F124;
    }
    goto skip_0;
    // 0x8006F0F8: lh          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X0));
    skip_0:
    // 0x8006F0FC: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x8006F100: addiu       $v1, $v1, -0x1350
    ctx->r3 = ADD32(ctx->r3, -0X1350);
    // 0x8006F104: lh          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X0));
    // 0x8006F108: lh          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006F10C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8006F110: subu        $t4, $t2, $v0
    ctx->r12 = SUB32(ctx->r10, ctx->r2);
    // 0x8006F114: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x8006F118: b           L_8006F16C
    // 0x8006F11C: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
        goto L_8006F16C;
    // 0x8006F11C: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8006F120: lh          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X0));
L_8006F124:
    // 0x8006F124: lh          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006F128: addiu       $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
    // 0x8006F12C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8006F130: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8006F134: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8006F138: lh          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006F13C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8006F140: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006F144: slti        $at, $t9, 0x39
    ctx->r1 = SIGNED(ctx->r25) < 0X39 ? 1 : 0;
    // 0x8006F148: bne         $at, $zero, L_8006F15C
    if (ctx->r1 != 0) {
        // 0x8006F14C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8006F15C;
    }
    // 0x8006F14C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8006F150: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x8006F154: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x8006F158: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8006F15C:
    // 0x8006F15C: lh          $t3, 0x0($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0X0));
    // 0x8006F160: bgtzl       $t3, L_8006F170
    if (SIGNED(ctx->r11) > 0) {
        // 0x8006F164: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8006F170;
    }
    goto skip_1;
    // 0x8006F164: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_1:
    // 0x8006F168: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
L_8006F16C:
    // 0x8006F16C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_8006F170:
    // 0x8006F170: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8006F174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006F178: jr          $ra
    // 0x8006F17C: nop

    return;
    // 0x8006F17C: nop

;}
RECOMP_FUNC void idle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B4B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004B4B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004B4BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004B4C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004B4C4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004B4C8: addiu       $a2, $a2, 0x35E8
    ctx->r6 = ADD32(ctx->r6, 0X35E8);
    // 0x8004B4CC: addiu       $a1, $a1, 0x3608
    ctx->r5 = ADD32(ctx->r5, 0X3608);
    // 0x8004B4D0: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8004B4D4: jal         0x800BB080
    // 0x8004B4D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_0;
    // 0x8004B4D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x8004B4DC: jal         0x800BAAE0
    // 0x8004B4E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x8004B4E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8004B4E4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8004B4E8: addiu       $t6, $t6, 0x6FE8
    ctx->r14 = ADD32(ctx->r14, 0X6FE8);
    // 0x8004B4EC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004B4F0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8004B4F4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8004B4F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004B4FC: addiu       $a2, $a2, -0x4278
    ctx->r6 = ADD32(ctx->r6, -0X4278);
    // 0x8004B500: addiu       $a0, $a0, 0x2E38
    ctx->r4 = ADD32(ctx->r4, 0X2E38);
    // 0x8004B504: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004B508: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8004B50C: jal         0x800BADE0
    // 0x8004B510: lw          $a3, 0x20($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X20));
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8004B510: lw          $a3, 0x20($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X20));
    after_2:
    // 0x8004B514: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004B518: jal         0x800BAF30
    // 0x8004B51C: addiu       $a0, $a0, 0x2E38
    ctx->r4 = ADD32(ctx->r4, 0X2E38);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8004B51C: addiu       $a0, $a0, 0x2E38
    ctx->r4 = ADD32(ctx->r4, 0X2E38);
    after_3:
    // 0x8004B520: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004B524: addiu       $a0, $a0, -0x1378
    ctx->r4 = ADD32(ctx->r4, -0X1378);
    // 0x8004B528: jal         0x800BB210
    // 0x8004B52C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_4;
    // 0x8004B52C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_8004B530:
    // 0x8004B530: b           L_8004B530
    pause_self(rdram);
    // 0x8004B534: nop

    // 0x8004B538: nop

    // 0x8004B53C: nop

    // 0x8004B540: nop

    // 0x8004B544: nop

    // 0x8004B548: nop

    // 0x8004B54C: nop

    // 0x8004B550: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004B554: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004B558: jr          $ra
    // 0x8004B55C: nop

    return;
    // 0x8004B55C: nop

;}
RECOMP_FUNC void alMainBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBFF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBFF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CBFFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CC000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC004: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CC008: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CC00C: addiu       $a1, $a1, -0x37E0
    ctx->r5 = ADD32(ctx->r5, -0X37E0);
    // 0x800CC010: addiu       $a2, $a2, -0x3810
    ctx->r6 = ADD32(ctx->r6, -0X3810);
    // 0x800CC014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CC018: jal         0x800D05C0
    // 0x800CC01C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CC01C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x800CC020: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800CC024: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CC028: lw          $t6, 0x20($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CC02C: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800CC030: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CC034: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800CC038: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CC03C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC040: jr          $ra
    // 0x800CC044: nop

    return;
    // 0x800CC044: nop

;}
RECOMP_FUNC void drawstatusbar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F608: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8006F60C: lh          $t6, -0x134C($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X134C));
    // 0x8006F610: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006F614: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F618: beq         $t6, $zero, L_800700E0
    if (ctx->r14 == 0) {
        // 0x8006F61C: sw          $a0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r4;
            goto L_800700E0;
    }
    // 0x8006F61C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8006F620: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x8006F624: lw          $t7, -0x540C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X540C));
    // 0x8006F628: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x8006F62C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8006F630: bnel        $at, $zero, L_8006F768
    if (ctx->r1 != 0) {
        // 0x8006F634: lh          $t3, 0x62($sp)
        ctx->r11 = S32(MEM_H(ctx->r29, 0X62));
            goto L_8006F768;
    }
    goto skip_0;
    // 0x8006F634: lh          $t3, 0x62($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X62));
    skip_0:
    // 0x8006F638: lw          $t8, -0x545C($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X545C));
    // 0x8006F63C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8006F640: bnel        $t8, $zero, L_8006F768
    if (ctx->r24 != 0) {
        // 0x8006F644: lh          $t3, 0x62($sp)
        ctx->r11 = S32(MEM_H(ctx->r29, 0X62));
            goto L_8006F768;
    }
    goto skip_1;
    // 0x8006F644: lh          $t3, 0x62($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X62));
    skip_1:
    // 0x8006F648: lbu         $t9, 0x378C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X378C);
    // 0x8006F64C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006F650: lh          $t1, 0x62($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X62));
    // 0x8006F654: beq         $t9, $at, L_8006F764
    if (ctx->r25 == ctx->r1) {
        // 0x8006F658: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_8006F764;
    }
    // 0x8006F658: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8006F65C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x8006F660: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x8006F664: beq         $t1, $zero, L_8006F690
    if (ctx->r9 == 0) {
        // 0x8006F668: addiu       $v1, $zero, 0xC8
        ctx->r3 = ADD32(0, 0XC8);
            goto L_8006F690;
    }
    // 0x8006F668: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x8006F66C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006F670: beq         $t1, $at, L_8006F698
    if (ctx->r9 == ctx->r1) {
        // 0x8006F674: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006F698;
    }
    // 0x8006F674: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006F678: beq         $t1, $at, L_8006F6A4
    if (ctx->r9 == ctx->r1) {
        // 0x8006F67C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006F6A4;
    }
    // 0x8006F67C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006F680: beql        $t1, $at, L_8006F6B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006F684: addiu       $v1, $zero, 0x40
        ctx->r3 = ADD32(0, 0X40);
            goto L_8006F6B0;
    }
    goto skip_2;
    // 0x8006F684: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    skip_2:
    // 0x8006F688: b           L_8006F6B4
    // 0x8006F68C: lh          $t2, 0x62($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X62));
        goto L_8006F6B4;
    // 0x8006F68C: lh          $t2, 0x62($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X62));
L_8006F690:
    // 0x8006F690: b           L_8006F6B0
    // 0x8006F694: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_8006F6B0;
    // 0x8006F694: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_8006F698:
    // 0x8006F698: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8006F69C: b           L_8006F6B0
    // 0x8006F6A0: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
        goto L_8006F6B0;
    // 0x8006F6A0: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
L_8006F6A4:
    // 0x8006F6A4: b           L_8006F6B0
    // 0x8006F6A8: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
        goto L_8006F6B0;
    // 0x8006F6A8: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8006F6AC: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
L_8006F6B0:
    // 0x8006F6B0: lh          $t2, 0x62($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X62));
L_8006F6B4:
    // 0x8006F6B4: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x8006F6B8: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x8006F6BC: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8006F6C0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8006F6C4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8006F6C8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8006F6CC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006F6D0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8006F6D4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006F6D8: addu        $t0, $t3, $t4
    ctx->r8 = ADD32(ctx->r11, ctx->r12);
    // 0x8006F6DC: lh          $t5, 0x2AE($t0)
    ctx->r13 = S32(MEM_H(ctx->r8, 0X2AE));
    // 0x8006F6E0: lh          $t6, 0x2B0($t0)
    ctx->r14 = S32(MEM_H(ctx->r8, 0X2B0));
    // 0x8006F6E4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006F6E8: addiu       $a1, $a1, 0x5150
    ctx->r5 = ADD32(ctx->r5, 0X5150);
    // 0x8006F6EC: sh          $v0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r2;
    // 0x8006F6F0: sh          $v1, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r3;
    // 0x8006F6F4: sh          $a3, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r7;
    // 0x8006F6F8: jal         0x800BD9E4
    // 0x8006F6FC: subu        $a2, $t5, $t6
    ctx->r6 = SUB32(ctx->r13, ctx->r14);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006F6FC: subu        $a2, $t5, $t6
    ctx->r6 = SUB32(ctx->r13, ctx->r14);
    after_0:
    // 0x8006F700: lh          $a0, 0x44($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X44));
    // 0x8006F704: lh          $a1, 0x42($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X42));
    // 0x8006F708: lh          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X40));
    // 0x8006F70C: jal         0x8006E994
    // 0x8006F710: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    setrotatespriteflags(rdram, ctx);
        goto after_1;
    // 0x8006F710: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    after_1:
    // 0x8006F714: jal         0x80099488
    // 0x8006F718: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_80099488(rdram, ctx);
        goto after_2;
    // 0x8006F718: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x8006F71C: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8006F720: lh          $t7, -0x1348($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X1348));
    // 0x8006F724: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x8006F728: lh          $a1, -0x1346($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X1346));
    // 0x8006F72C: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
    // 0x8006F730: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8006F734: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8006F738: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x8006F73C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8006F740: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006F744: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8006F748: jal         0x80063F68
    // 0x8006F74C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    gametext(rdram, ctx);
        goto after_3;
    // 0x8006F74C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x8006F750: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006F754: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006F758: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8006F75C: jal         0x8006E994
    // 0x8006F760: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    setrotatespriteflags(rdram, ctx);
        goto after_4;
    // 0x8006F760: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    after_4:
L_8006F764:
    // 0x8006F764: lh          $t3, 0x62($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X62));
L_8006F768:
    // 0x8006F768: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x8006F76C: addiu       $t5, $t5, 0x5770
    ctx->r13 = ADD32(ctx->r13, 0X5770);
    // 0x8006F770: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8006F774: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8006F778: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8006F77C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006F780: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006F784: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8006F788: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006F78C: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x8006F790: lh          $v0, 0x372($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X372));
    // 0x8006F794: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006F798: beql        $v0, $zero, L_8006F9D0
    if (ctx->r2 == 0) {
        // 0x8006F79C: lbu         $t3, 0x33F($t0)
        ctx->r11 = MEM_BU(ctx->r8, 0X33F);
            goto L_8006F9D0;
    }
    goto skip_3;
    // 0x8006F79C: lbu         $t3, 0x33F($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X33F);
    skip_3:
    // 0x8006F7A0: lh          $t6, -0x9DC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X9DC));
    // 0x8006F7A4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8006F7A8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006F7AC: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8006F7B0: beq         $at, $zero, L_8006F890
    if (ctx->r1 == 0) {
        // 0x8006F7B4: addu        $a1, $a1, $t7
        ctx->r5 = ADD32(ctx->r5, ctx->r15);
            goto L_8006F890;
    }
    // 0x8006F7B4: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8006F7B8: lhu         $a1, -0x5030($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X5030);
    // 0x8006F7BC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8006F7C0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8006F7C4: jal         0x8006E7C4
    // 0x8006F7C8: sh          $a1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r5;
    invtilescale(rdram, ctx);
        goto after_5;
    // 0x8006F7C8: sh          $a1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r5;
    after_5:
    // 0x8006F7CC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8006F7D0: lh          $t8, -0x9DC($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X9DC));
    // 0x8006F7D4: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006F7D8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8006F7DC: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8006F7E0: beq         $at, $zero, L_8006F7FC
    if (ctx->r1 == 0) {
        // 0x8006F7E4: lui         $t4, 0x8027
        ctx->r12 = S32(0X8027 << 16);
            goto L_8006F7FC;
    }
    // 0x8006F7E4: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x8006F7E8: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8006F7EC: lh          $t9, -0x134A($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X134A));
    // 0x8006F7F0: addiu       $t1, $t9, 0x37
    ctx->r9 = ADD32(ctx->r25, 0X37);
    // 0x8006F7F4: b           L_8006F80C
    // 0x8006F7F8: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
        goto L_8006F80C;
    // 0x8006F7F8: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_8006F7FC:
    // 0x8006F7FC: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8006F800: lh          $t2, -0x134A($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X134A));
    // 0x8006F804: addiu       $t3, $t2, 0xF
    ctx->r11 = ADD32(ctx->r10, 0XF);
    // 0x8006F808: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_8006F80C:
    // 0x8006F80C: lh          $t4, -0x1344($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X1344));
    // 0x8006F810: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x8006F814: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x8006F818: addiu       $t5, $t4, -0xC
    ctx->r13 = ADD32(ctx->r12, -0XC);
    // 0x8006F81C: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8006F820: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8006F824: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8006F828: sh          $v1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r3;
    // 0x8006F82C: jal         0x8006E994
    // 0x8006F830: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_6;
    // 0x8006F830: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_6:
    // 0x8006F834: lw          $t7, 0x48($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006F838: lhu         $v1, 0x46($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X46);
    // 0x8006F83C: lw          $t6, 0x4C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8006F840: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8006F844: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8006F848: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8006F84C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8006F850: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006F854: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006F858: bgez        $v1, L_8006F870
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006F85C: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8006F870;
    }
    // 0x8006F85C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006F860: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006F864: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006F868: nop

    // 0x8006F86C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_8006F870:
    // 0x8006F870: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x8006F874: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006F878: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006F87C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006F880: jal         0x8005D13C
    // 0x8006F884: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    rotatesprite(rdram, ctx);
        goto after_7;
    // 0x8006F884: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x8006F888: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006F88C: lh          $v0, 0x372($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X372));
L_8006F890:
    // 0x8006F890: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8006F894: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8006F898: bne         $v1, $at, L_8006F8A8
    if (ctx->r3 != ctx->r1) {
        // 0x8006F89C: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_8006F8A8;
    }
    // 0x8006F89C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8006F8A0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8006F8A4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
L_8006F8A8:
    // 0x8006F8A8: lh          $t1, 0x62($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X62));
    // 0x8006F8AC: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x8006F8B0: lui         $a2, 0x802A
    ctx->r6 = S32(0X802A << 16);
    // 0x8006F8B4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8006F8B8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8006F8BC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8006F8C0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8006F8C4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006F8C8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8006F8CC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8006F8D0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8006F8D4: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x8006F8D8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006F8DC: addiu       $a1, $a1, 0x5154
    ctx->r5 = ADD32(ctx->r5, 0X5154);
    // 0x8006F8E0: lh          $a2, 0x59FE($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X59FE));
    // 0x8006F8E4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8006F8E8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8006F8EC: jal         0x800BD9E4
    // 0x8006F8F0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8006F8F0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_8:
    // 0x8006F8F4: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8006F8F8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8006F8FC: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006F900: beq         $a3, $at, L_8006F91C
    if (ctx->r7 == ctx->r1) {
        // 0x8006F904: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8006F91C;
    }
    // 0x8006F904: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006F908: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8006F90C: beq         $a3, $at, L_8006F91C
    if (ctx->r7 == ctx->r1) {
        // 0x8006F910: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8006F91C;
    }
    // 0x8006F910: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8006F914: bne         $a3, $at, L_8006F938
    if (ctx->r7 != ctx->r1) {
        // 0x8006F918: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8006F938;
    }
    // 0x8006F918: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_8006F91C:
    // 0x8006F91C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006F920: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8006F924: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    // 0x8006F928: jal         0x8006E994
    // 0x8006F92C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_9;
    // 0x8006F92C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_9:
    // 0x8006F930: b           L_8006F950
    // 0x8006F934: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
        goto L_8006F950;
    // 0x8006F934: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006F938:
    // 0x8006F938: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006F93C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8006F940: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    // 0x8006F944: jal         0x8006E994
    // 0x8006F948: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_10;
    // 0x8006F948: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_10:
    // 0x8006F94C: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006F950:
    // 0x8006F950: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8006F954: lh          $t5, -0x9DC($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X9DC));
    // 0x8006F958: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8006F95C: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x8006F960: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8006F964: beq         $at, $zero, L_8006F9A0
    if (ctx->r1 == 0) {
        // 0x8006F968: addiu       $a2, $sp, 0x54
        ctx->r6 = ADD32(ctx->r29, 0X54);
            goto L_8006F9A0;
    }
    // 0x8006F968: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8006F96C: lw          $a0, 0x4C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8006F970: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006F974: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8006F978: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8006F97C: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8006F980: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x8006F984: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8006F988: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8006F98C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8006F990: jal         0x8006E878
    // 0x8006F994: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    printnumber(rdram, ctx);
        goto after_11;
    // 0x8006F994: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_11:
    // 0x8006F998: b           L_8006F9CC
    // 0x8006F99C: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
        goto L_8006F9CC;
    // 0x8006F99C: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006F9A0:
    // 0x8006F9A0: lh          $a0, -0x134A($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X134A));
    // 0x8006F9A4: lh          $a1, -0x1344($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X1344));
    // 0x8006F9A8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8006F9AC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006F9B0: addiu       $a1, $a1, -0xA
    ctx->r5 = ADD32(ctx->r5, -0XA);
    // 0x8006F9B4: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x8006F9B8: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8006F9BC: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006F9C0: jal         0x80063F68
    // 0x8006F9C4: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    gametext(rdram, ctx);
        goto after_12;
    // 0x8006F9C4: sra         $a1, $t1, 16
    ctx->r5 = S32(SIGNED(ctx->r9) >> 16);
    after_12:
    // 0x8006F9C8: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006F9CC:
    // 0x8006F9CC: lbu         $t3, 0x33F($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X33F);
L_8006F9D0:
    // 0x8006F9D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006F9D4: sltiu       $at, $t3, 0x9
    ctx->r1 = ctx->r11 < 0X9 ? 1 : 0;
    // 0x8006F9D8: beq         $at, $zero, L_8006FB48
    if (ctx->r1 == 0) {
        // 0x8006F9DC: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8006FB48;
    }
    // 0x8006F9DC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006F9E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006F9E4: addu        $at, $at, $t3
    gpr jr_addend_8006F9EC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8006F9E8: lw          $t3, 0x5164($at)
    ctx->r11 = ADD32(ctx->r1, 0X5164);
    // 0x8006F9EC: jr          $t3
    // 0x8006F9F0: nop

    switch (jr_addend_8006F9EC >> 2) {
        case 0: goto L_8006FB40; break;
        case 1: goto L_8006F9F4; break;
        case 2: goto L_8006FA08; break;
        case 3: goto L_8006FA44; break;
        case 4: goto L_8006FA78; break;
        case 5: goto L_8006FAB0; break;
        case 6: goto L_8006FAE0; break;
        case 7: goto L_8006FB08; break;
        case 8: goto L_8006FB2C; break;
        default: switch_error(__func__, 0x8006F9EC, 0x80105164);
    }
    // 0x8006F9F0: nop

L_8006F9F4:
    // 0x8006F9F4: lhu         $a2, 0x2DA($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X2DA);
    // 0x8006F9F8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    // 0x8006F9FC: sh          $a1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r5;
    // 0x8006FA00: b           L_8006FB48
    // 0x8006FA04: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
        goto L_8006FB48;
    // 0x8006FA04: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
L_8006FA08:
    // 0x8006FA08: lh          $a2, 0x320($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X320));
    // 0x8006FA0C: addiu       $t4, $zero, 0x37
    ctx->r12 = ADD32(0, 0X37);
    // 0x8006FA10: sh          $t4, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r12;
    // 0x8006FA14: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8006FA18: bgez        $a2, L_8006FA28
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006FA1C: sra         $t5, $a2, 2
        ctx->r13 = S32(SIGNED(ctx->r6) >> 2);
            goto L_8006FA28;
    }
    // 0x8006FA1C: sra         $t5, $a2, 2
    ctx->r13 = S32(SIGNED(ctx->r6) >> 2);
    // 0x8006FA20: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
    // 0x8006FA24: sra         $t5, $at, 2
    ctx->r13 = S32(SIGNED(ctx->r1) >> 2);
L_8006FA28:
    // 0x8006FA28: andi        $a2, $t5, 0xFFFF
    ctx->r6 = ctx->r13 & 0XFFFF;
    // 0x8006FA2C: slti        $at, $a2, 0x64
    ctx->r1 = SIGNED(ctx->r6) < 0X64 ? 1 : 0;
    // 0x8006FA30: beq         $at, $zero, L_8006FA3C
    if (ctx->r1 == 0) {
        // 0x8006FA34: nop
    
            goto L_8006FA3C;
    }
    // 0x8006FA34: nop

    // 0x8006FA38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006FA3C:
    // 0x8006FA3C: b           L_8006FB48
    // 0x8006FA40: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
        goto L_8006FB48;
    // 0x8006FA40: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
L_8006FA44:
    // 0x8006FA44: lh          $a2, 0x2BC($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X2BC));
    // 0x8006FA48: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8006FA4C: lh          $t1, 0x324($t0)
    ctx->r9 = S32(MEM_H(ctx->r8, 0X324));
    // 0x8006FA50: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    // 0x8006FA54: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x8006FA58: addiu       $t7, $zero, 0x544
    ctx->r15 = ADD32(0, 0X544);
    // 0x8006FA5C: mflo        $t8
    ctx->r24 = lo;
    // 0x8006FA60: sh          $t7, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r15;
    // 0x8006FA64: blez        $t1, L_8006FA70
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8006FA68: andi        $a2, $t8, 0xFFFF
        ctx->r6 = ctx->r24 & 0XFFFF;
            goto L_8006FA70;
    }
    // 0x8006FA68: andi        $a2, $t8, 0xFFFF
    ctx->r6 = ctx->r24 & 0XFFFF;
    // 0x8006FA6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006FA70:
    // 0x8006FA70: b           L_8006FB48
    // 0x8006FA74: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
        goto L_8006FB48;
    // 0x8006FA74: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
L_8006FA78:
    // 0x8006FA78: lh          $a2, 0x31E($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X31E));
    // 0x8006FA7C: lbu         $t5, 0x341($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X341);
    // 0x8006FA80: addiu       $t2, $zero, 0x39
    ctx->r10 = ADD32(0, 0X39);
    // 0x8006FA84: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    // 0x8006FA88: sh          $t2, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r10;
    // 0x8006FA8C: bgez        $a2, L_8006FA9C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006FA90: sra         $t3, $a2, 4
        ctx->r11 = S32(SIGNED(ctx->r6) >> 4);
            goto L_8006FA9C;
    }
    // 0x8006FA90: sra         $t3, $a2, 4
    ctx->r11 = S32(SIGNED(ctx->r6) >> 4);
    // 0x8006FA94: addiu       $at, $a2, 0xF
    ctx->r1 = ADD32(ctx->r6, 0XF);
    // 0x8006FA98: sra         $t3, $at, 4
    ctx->r11 = S32(SIGNED(ctx->r1) >> 4);
L_8006FA9C:
    // 0x8006FA9C: blez        $t5, L_8006FAA8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8006FAA0: andi        $a2, $t3, 0xFFFF
        ctx->r6 = ctx->r11 & 0XFFFF;
            goto L_8006FAA8;
    }
    // 0x8006FAA0: andi        $a2, $t3, 0xFFFF
    ctx->r6 = ctx->r11 & 0XFFFF;
    // 0x8006FAA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006FAA8:
    // 0x8006FAA8: b           L_8006FB48
    // 0x8006FAAC: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
        goto L_8006FB48;
    // 0x8006FAAC: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
L_8006FAB0:
    // 0x8006FAB0: lh          $a2, 0x2EC($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X2EC));
    // 0x8006FAB4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8006FAB8: lbu         $t9, 0x346($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X346);
    // 0x8006FABC: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x8006FAC0: addiu       $t6, $zero, 0x3B
    ctx->r14 = ADD32(0, 0X3B);
    // 0x8006FAC4: mflo        $t7
    ctx->r15 = lo;
    // 0x8006FAC8: sh          $t6, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r14;
    // 0x8006FACC: blez        $t9, L_8006FAD8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8006FAD0: andi        $a2, $t7, 0xFFFF
        ctx->r6 = ctx->r15 & 0XFFFF;
            goto L_8006FAD8;
    }
    // 0x8006FAD0: andi        $a2, $t7, 0xFFFF
    ctx->r6 = ctx->r15 & 0XFFFF;
    // 0x8006FAD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006FAD8:
    // 0x8006FAD8: b           L_8006FB48
    // 0x8006FADC: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
        goto L_8006FB48;
    // 0x8006FADC: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
L_8006FAE0:
    // 0x8006FAE0: lh          $a2, 0x31C($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X31C));
    // 0x8006FAE4: addiu       $t1, $zero, 0x38
    ctx->r9 = ADD32(0, 0X38);
    // 0x8006FAE8: sh          $t1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r9;
    // 0x8006FAEC: addiu       $a2, $a2, 0x3F
    ctx->r6 = ADD32(ctx->r6, 0X3F);
    // 0x8006FAF0: bgez        $a2, L_8006FB00
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006FAF4: sra         $t2, $a2, 6
        ctx->r10 = S32(SIGNED(ctx->r6) >> 6);
            goto L_8006FB00;
    }
    // 0x8006FAF4: sra         $t2, $a2, 6
    ctx->r10 = S32(SIGNED(ctx->r6) >> 6);
    // 0x8006FAF8: addiu       $at, $a2, 0x3F
    ctx->r1 = ADD32(ctx->r6, 0X3F);
    // 0x8006FAFC: sra         $t2, $at, 6
    ctx->r10 = S32(SIGNED(ctx->r1) >> 6);
L_8006FB00:
    // 0x8006FB00: b           L_8006FB48
    // 0x8006FB04: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
        goto L_8006FB48;
    // 0x8006FB04: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
L_8006FB08:
    // 0x8006FB08: lh          $a2, 0x332($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X332));
    // 0x8006FB0C: addiu       $t4, $zero, 0x3D
    ctx->r12 = ADD32(0, 0X3D);
    // 0x8006FB10: sh          $t4, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r12;
    // 0x8006FB14: bgez        $a2, L_8006FB24
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006FB18: sra         $t5, $a2, 1
        ctx->r13 = S32(SIGNED(ctx->r6) >> 1);
            goto L_8006FB24;
    }
    // 0x8006FB18: sra         $t5, $a2, 1
    ctx->r13 = S32(SIGNED(ctx->r6) >> 1);
    // 0x8006FB1C: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x8006FB20: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8006FB24:
    // 0x8006FB24: b           L_8006FB48
    // 0x8006FB28: sh          $t5, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r13;
        goto L_8006FB48;
    // 0x8006FB28: sh          $t5, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r13;
L_8006FB2C:
    // 0x8006FB2C: lhu         $a2, 0x322($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X322);
    // 0x8006FB30: addiu       $t7, $zero, 0x36
    ctx->r15 = ADD32(0, 0X36);
    // 0x8006FB34: sh          $t7, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r15;
    // 0x8006FB38: b           L_8006FB48
    // 0x8006FB3C: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
        goto L_8006FB48;
    // 0x8006FB3C: sh          $a2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r6;
L_8006FB40:
    // 0x8006FB40: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8006FB44: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
L_8006FB48:
    // 0x8006FB48: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006FB4C: lh          $v0, -0x9DC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9DC));
    // 0x8006FB50: lhu         $a1, 0x5E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X5E);
    // 0x8006FB54: lhu         $a2, 0x5C($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X5C);
    // 0x8006FB58: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006FB5C: bne         $at, $zero, L_8006FB78
    if (ctx->r1 != 0) {
        // 0x8006FB60: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_8006FB78;
    }
    // 0x8006FB60: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8006FB64: beq         $v1, $zero, L_8006FB78
    if (ctx->r3 == 0) {
        // 0x8006FB68: slti        $at, $a2, 0x1E
        ctx->r1 = SIGNED(ctx->r6) < 0X1E ? 1 : 0;
            goto L_8006FB78;
    }
    // 0x8006FB68: slti        $at, $a2, 0x1E
    ctx->r1 = SIGNED(ctx->r6) < 0X1E ? 1 : 0;
    // 0x8006FB6C: beq         $at, $zero, L_8006FB78
    if (ctx->r1 == 0) {
        // 0x8006FB70: addiu       $t8, $zero, 0x14
        ctx->r24 = ADD32(0, 0X14);
            goto L_8006FB78;
    }
    // 0x8006FB70: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8006FB74: sw          $t8, 0x22C($t0)
    MEM_W(0X22C, ctx->r8) = ctx->r24;
L_8006FB78:
    // 0x8006FB78: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006FB7C: bne         $at, $zero, L_8006FB94
    if (ctx->r1 != 0) {
        // 0x8006FB80: nop
    
            goto L_8006FB94;
    }
    // 0x8006FB80: nop

    // 0x8006FB84: lw          $t9, 0x22C($t0)
    ctx->r25 = S32(MEM_W(ctx->r8, 0X22C));
    // 0x8006FB88: bne         $t9, $zero, L_8006FB94
    if (ctx->r25 != 0) {
        // 0x8006FB8C: nop
    
            goto L_8006FB94;
    }
    // 0x8006FB8C: nop

    // 0x8006FB90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8006FB94:
    // 0x8006FB94: beq         $a1, $zero, L_8006FD74
    if (ctx->r5 == 0) {
        // 0x8006FB98: nop
    
            goto L_8006FD74;
    }
    // 0x8006FB98: nop

    // 0x8006FB9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006FBA0: sb          $v1, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r3;
    // 0x8006FBA4: sh          $a1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r5;
    // 0x8006FBA8: jal         0x8006E7C4
    // 0x8006FBAC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    invtilescale(rdram, ctx);
        goto after_13;
    // 0x8006FBAC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_13:
    // 0x8006FBB0: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x8006FBB4: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8006FBB8: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8006FBBC: lh          $t1, -0x1348($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, -0X1348));
    // 0x8006FBC0: lh          $t3, -0x1344($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X1344));
    // 0x8006FBC4: lh          $t5, -0x9DC($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X9DC));
    // 0x8006FBC8: addiu       $t2, $t1, -0x17
    ctx->r10 = ADD32(ctx->r9, -0X17);
    // 0x8006FBCC: addiu       $t4, $t3, -0xA
    ctx->r12 = ADD32(ctx->r11, -0XA);
    // 0x8006FBD0: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8006FBD4: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006FBD8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8006FBDC: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8006FBE0: bne         $at, $zero, L_8006FC08
    if (ctx->r1 != 0) {
        // 0x8006FBE4: sw          $t4, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r12;
            goto L_8006FC08;
    }
    // 0x8006FBE4: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8006FBE8: lw          $t6, 0x22C($t0)
    ctx->r14 = S32(MEM_W(ctx->r8, 0X22C));
    // 0x8006FBEC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8006FBF0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8006FBF4: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8006FBF8: mflo        $t8
    ctx->r24 = lo;
    // 0x8006FBFC: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8006FC00: b           L_8006FC14
    // 0x8006FC04: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_8006FC14;
    // 0x8006FC04: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8006FC08:
    // 0x8006FC08: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x8006FC0C: sh          $t9, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r25;
    // 0x8006FC10: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8006FC14:
    // 0x8006FC14: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006FC18: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8006FC1C: lh          $a3, 0x3A($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x8006FC20: sh          $v1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r3;
    // 0x8006FC24: jal         0x8006E994
    // 0x8006FC28: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_14;
    // 0x8006FC28: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_14:
    // 0x8006FC2C: lw          $t1, 0x4C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8006FC30: lw          $t3, 0x48($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006FC34: lhu         $v1, 0x46($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X46);
    // 0x8006FC38: addiu       $t2, $t1, -0x11
    ctx->r10 = ADD32(ctx->r9, -0X11);
    // 0x8006FC3C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8006FC40: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8006FC44: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8006FC48: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8006FC4C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006FC50: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006FC54: bgez        $v1, L_8006FC6C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006FC58: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8006FC6C;
    }
    // 0x8006FC58: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006FC5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006FC60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006FC64: nop

    // 0x8006FC68: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8006FC6C:
    // 0x8006FC6C: lhu         $t5, 0x5E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X5E);
    // 0x8006FC70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006FC74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006FC78: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006FC7C: jal         0x8005D13C
    // 0x8006FC80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    rotatesprite(rdram, ctx);
        goto after_15;
    // 0x8006FC80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_15:
    // 0x8006FC84: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006FC88: addiu       $a1, $a1, 0x5158
    ctx->r5 = ADD32(ctx->r5, 0X5158);
    // 0x8006FC8C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8006FC90: jal         0x800BD9E4
    // 0x8006FC94: lw          $a2, 0x28($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X28));
    sprintf_recomp(rdram, ctx);
        goto after_16;
    // 0x8006FC94: lw          $a2, 0x28($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X28));
    after_16:
    // 0x8006FC98: lw          $t6, 0x28($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8006FC9C: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006FCA0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006FCA4: slti        $at, $t6, 0x1E
    ctx->r1 = SIGNED(ctx->r14) < 0X1E ? 1 : 0;
    // 0x8006FCA8: beq         $at, $zero, L_8006FCD0
    if (ctx->r1 == 0) {
        // 0x8006FCAC: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8006FCD0;
    }
    // 0x8006FCAC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006FCB0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006FCB4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006FCB8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8006FCBC: lh          $a3, 0x3A($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x8006FCC0: jal         0x8006E994
    // 0x8006FCC4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_17;
    // 0x8006FCC4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_17:
    // 0x8006FCC8: b           L_8006FCE4
    // 0x8006FCCC: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
        goto L_8006FCE4;
    // 0x8006FCCC: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FCD0:
    // 0x8006FCD0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8006FCD4: lh          $a3, 0x3A($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x8006FCD8: jal         0x8006E994
    // 0x8006FCDC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_18;
    // 0x8006FCDC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_18:
    // 0x8006FCE0: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FCE4:
    // 0x8006FCE4: lhu         $a0, 0x4E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4E);
    // 0x8006FCE8: lhu         $a1, 0x4A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X4A);
    // 0x8006FCEC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8006FCF0: jal         0x8006E878
    // 0x8006FCF4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    printnumber(rdram, ctx);
        goto after_19;
    // 0x8006FCF4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_19:
    // 0x8006FCF8: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006FCFC: lbu         $v0, 0x33F($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X33F);
    // 0x8006FD00: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006FD04: bne         $at, $zero, L_8006FD74
    if (ctx->r1 != 0) {
        // 0x8006FD08: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_8006FD74;
    }
    // 0x8006FD08: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8006FD0C: bne         $at, $zero, L_8006FD34
    if (ctx->r1 != 0) {
        // 0x8006FD10: lbu         $t7, 0x53($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X53);
            goto L_8006FD34;
    }
    // 0x8006FD10: lbu         $t7, 0x53($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X53);
    // 0x8006FD14: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006FD18: lw          $a0, 0x4C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8006FD1C: addiu       $a2, $zero, 0xEA3
    ctx->r6 = ADD32(0, 0XEA3);
    // 0x8006FD20: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8006FD24: jal         0x80065A64
    // 0x8006FD28: addiu       $a1, $a1, -0xA
    ctx->r5 = ADD32(ctx->r5, -0XA);
    rotatesprite_simple(rdram, ctx);
        goto after_20;
    // 0x8006FD28: addiu       $a1, $a1, -0xA
    ctx->r5 = ADD32(ctx->r5, -0XA);
    after_20:
    // 0x8006FD2C: b           L_8006FD74
    // 0x8006FD30: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
        goto L_8006FD74;
    // 0x8006FD30: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FD34:
    // 0x8006FD34: beq         $t7, $zero, L_8006FD5C
    if (ctx->r15 == 0) {
        // 0x8006FD38: lw          $a0, 0x4C($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X4C));
            goto L_8006FD5C;
    }
    // 0x8006FD38: lw          $a0, 0x4C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8006FD3C: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006FD40: lw          $a0, 0x4C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8006FD44: addiu       $a2, $zero, 0xEA5
    ctx->r6 = ADD32(0, 0XEA5);
    // 0x8006FD48: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8006FD4C: jal         0x80065A64
    // 0x8006FD50: addiu       $a1, $a1, -0xA
    ctx->r5 = ADD32(ctx->r5, -0XA);
    rotatesprite_simple(rdram, ctx);
        goto after_21;
    // 0x8006FD50: addiu       $a1, $a1, -0xA
    ctx->r5 = ADD32(ctx->r5, -0XA);
    after_21:
    // 0x8006FD54: b           L_8006FD74
    // 0x8006FD58: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
        goto L_8006FD74;
    // 0x8006FD58: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FD5C:
    // 0x8006FD5C: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006FD60: addiu       $a2, $zero, 0xEA4
    ctx->r6 = ADD32(0, 0XEA4);
    // 0x8006FD64: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8006FD68: jal         0x80065A64
    // 0x8006FD6C: addiu       $a1, $a1, -0xA
    ctx->r5 = ADD32(ctx->r5, -0XA);
    rotatesprite_simple(rdram, ctx);
        goto after_22;
    // 0x8006FD6C: addiu       $a1, $a1, -0xA
    ctx->r5 = ADD32(ctx->r5, -0XA);
    after_22:
    // 0x8006FD70: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FD74:
    // 0x8006FD74: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006FD78: addiu       $a1, $a1, 0x5160
    ctx->r5 = ADD32(ctx->r5, 0X5160);
    // 0x8006FD7C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8006FD80: lh          $a2, 0x28C($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X28C));
    // 0x8006FD84: jal         0x800BD9E4
    // 0x8006FD88: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x8006FD88: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_23:
    // 0x8006FD8C: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006FD90: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006FD94: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006FD98: lh          $t8, 0x28C($t0)
    ctx->r24 = S32(MEM_H(ctx->r8, 0X28C));
    // 0x8006FD9C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8006FDA0: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    // 0x8006FDA4: slti        $at, $t8, 0x1E
    ctx->r1 = SIGNED(ctx->r24) < 0X1E ? 1 : 0;
    // 0x8006FDA8: beq         $at, $zero, L_8006FDD0
    if (ctx->r1 == 0) {
        // 0x8006FDAC: nop
    
            goto L_8006FDD0;
    }
    // 0x8006FDAC: nop

    // 0x8006FDB0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006FDB4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8006FDB8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8006FDBC: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    // 0x8006FDC0: jal         0x8006E994
    // 0x8006FDC4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_24;
    // 0x8006FDC4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_24:
    // 0x8006FDC8: b           L_8006FDDC
    // 0x8006FDCC: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
        goto L_8006FDDC;
    // 0x8006FDCC: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FDD0:
    // 0x8006FDD0: jal         0x8006E994
    // 0x8006FDD4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_25;
    // 0x8006FDD4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_25:
    // 0x8006FDD8: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FDDC:
    // 0x8006FDDC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8006FDE0: lh          $t9, -0x9DC($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X9DC));
    // 0x8006FDE4: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8006FDE8: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x8006FDEC: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8006FDF0: beq         $at, $zero, L_8006FE54
    if (ctx->r1 == 0) {
        // 0x8006FDF4: addiu       $a2, $sp, 0x54
        ctx->r6 = ADD32(ctx->r29, 0X54);
            goto L_8006FE54;
    }
    // 0x8006FDF4: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8006FDF8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8006FDFC: jal         0x80099488
    // 0x8006FE00: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_80099488(rdram, ctx);
        goto after_26;
    // 0x8006FE00: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_26:
    // 0x8006FE04: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x8006FE08: lh          $t1, -0x134A($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, -0X134A));
    // 0x8006FE0C: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x8006FE10: lh          $a1, -0x1344($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X1344));
    // 0x8006FE14: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006FE18: bgez        $v0, L_8006FE28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006FE1C: sra         $t2, $v0, 1
        ctx->r10 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8006FE28;
    }
    // 0x8006FE1C: sra         $t2, $v0, 1
    ctx->r10 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8006FE20: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8006FE24: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8006FE28:
    // 0x8006FE28: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    // 0x8006FE2C: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
    // 0x8006FE30: addiu       $a1, $a1, -0x12
    ctx->r5 = ADD32(ctx->r5, -0X12);
    // 0x8006FE34: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x8006FE38: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8006FE3C: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8006FE40: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8006FE44: jal         0x80063F68
    // 0x8006FE48: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    gametext(rdram, ctx);
        goto after_27;
    // 0x8006FE48: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_27:
    // 0x8006FE4C: b           L_8006FE80
    // 0x8006FE50: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
        goto L_8006FE80;
    // 0x8006FE50: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FE54:
    // 0x8006FE54: lh          $a0, -0x134A($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X134A));
    // 0x8006FE58: lh          $a1, -0x1346($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X1346));
    // 0x8006FE5C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8006FE60: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006FE64: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8006FE68: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8006FE6C: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8006FE70: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8006FE74: jal         0x8006413C
    // 0x8006FE78: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    menutext(rdram, ctx);
        goto after_28;
    // 0x8006FE78: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_28:
    // 0x8006FE7C: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
L_8006FE80:
    // 0x8006FE80: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8006FE84: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006FE88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8006FE8C: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    // 0x8006FE90: jal         0x8006E994
    // 0x8006FE94: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    setrotatespriteflags(rdram, ctx);
        goto after_29;
    // 0x8006FE94: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_29:
    // 0x8006FE98: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x8006FE9C: lw          $t2, -0x540C($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X540C));
    // 0x8006FEA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006FEA4: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006FEA8: beq         $t2, $at, L_8006FEBC
    if (ctx->r10 == ctx->r1) {
        // 0x8006FEAC: lui         $t3, 0x802B
        ctx->r11 = S32(0X802B << 16);
            goto L_8006FEBC;
    }
    // 0x8006FEAC: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x8006FEB0: lw          $t3, -0x545C($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, -0X545C));
    // 0x8006FEB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006FEB8: bne         $t3, $at, L_800700E0
    if (ctx->r11 != ctx->r1) {
        // 0x8006FEBC: lui         $t4, 0x8010
        ctx->r12 = S32(0X8010 << 16);
            goto L_800700E0;
    }
L_8006FEBC:
    // 0x8006FEBC: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8006FEC0: lh          $t4, -0x9DC($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X9DC));
    // 0x8006FEC4: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x8006FEC8: beql        $at, $zero, L_8006FFE8
    if (ctx->r1 == 0) {
        // 0x8006FECC: lh          $v0, 0x2D6($t0)
        ctx->r2 = S32(MEM_H(ctx->r8, 0X2D6));
            goto L_8006FFE8;
    }
    goto skip_4;
    // 0x8006FECC: lh          $v0, 0x2D6($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2D6));
    skip_4:
    // 0x8006FED0: lh          $v0, 0x2D6($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2D6));
    // 0x8006FED4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006FED8: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8006FEDC: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8006FEE0: beq         $t5, $zero, L_8006FF30
    if (ctx->r13 == 0) {
        // 0x8006FEE4: lui         $t8, 0x8027
        ctx->r24 = S32(0X8027 << 16);
            goto L_8006FF30;
    }
    // 0x8006FEE4: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8006FEE8: lh          $t6, -0x1348($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X1348));
    // 0x8006FEEC: lh          $t8, -0x1344($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X1344));
    // 0x8006FEF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006FEF4: addiu       $t7, $t6, -0x3D
    ctx->r15 = ADD32(ctx->r14, -0X3D);
    // 0x8006FEF8: addiu       $t9, $t8, -0x18
    ctx->r25 = ADD32(ctx->r24, -0X18);
    // 0x8006FEFC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8006FF00: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8006FF04: addiu       $t1, $zero, 0xE25
    ctx->r9 = ADD32(0, 0XE25);
    // 0x8006FF08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006FF0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006FF10: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8006FF14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006FF18: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8006FF1C: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006FF20: jal         0x8005D13C
    // 0x8006FF24: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    rotatesprite(rdram, ctx);
        goto after_30;
    // 0x8006FF24: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_30:
    // 0x8006FF28: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006FF2C: lh          $v0, 0x2D6($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2D6));
L_8006FF30:
    // 0x8006FF30: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x8006FF34: beq         $t2, $zero, L_8006FF8C
    if (ctx->r10 == 0) {
        // 0x8006FF38: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8006FF8C;
    }
    // 0x8006FF38: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006FF3C: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8006FF40: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8006FF44: lh          $t5, -0x1344($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X1344));
    // 0x8006FF48: lh          $t3, -0x1348($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X1348));
    // 0x8006FF4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006FF50: addiu       $t6, $t5, -0x12
    ctx->r14 = ADD32(ctx->r13, -0X12);
    // 0x8006FF54: addiu       $t4, $t3, -0x41
    ctx->r12 = ADD32(ctx->r11, -0X41);
    // 0x8006FF58: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8006FF5C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8006FF60: addiu       $t7, $zero, 0xE26
    ctx->r15 = ADD32(0, 0XE26);
    // 0x8006FF64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006FF68: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006FF6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006FF70: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006FF74: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8006FF78: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006FF7C: jal         0x8005D13C
    // 0x8006FF80: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    rotatesprite(rdram, ctx);
        goto after_31;
    // 0x8006FF80: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_31:
    // 0x8006FF84: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006FF88: lh          $v0, 0x2D6($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2D6));
L_8006FF8C:
    // 0x8006FF8C: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8006FF90: beq         $t8, $zero, L_800700E0
    if (ctx->r24 == 0) {
        // 0x8006FF94: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800700E0;
    }
    // 0x8006FF94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006FF98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006FF9C: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8006FFA0: lh          $t9, -0x1348($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X1348));
    // 0x8006FFA4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8006FFA8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8006FFAC: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8006FFB0: lh          $t2, -0x1344($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X1344));
    // 0x8006FFB4: addiu       $t1, $t9, -0x41
    ctx->r9 = ADD32(ctx->r25, -0X41);
    // 0x8006FFB8: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8006FFBC: addiu       $t3, $t2, -0xA
    ctx->r11 = ADD32(ctx->r10, -0XA);
    // 0x8006FFC0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8006FFC4: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006FFC8: addiu       $t4, $zero, 0xE27
    ctx->r12 = ADD32(0, 0XE27);
    // 0x8006FFCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8006FFD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006FFD4: jal         0x8005D13C
    // 0x8006FFD8: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    rotatesprite(rdram, ctx);
        goto after_32;
    // 0x8006FFD8: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    after_32:
    // 0x8006FFDC: b           L_800700E4
    // 0x8006FFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_800700E4;
    // 0x8006FFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8006FFE4: lh          $v0, 0x2D6($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2D6));
L_8006FFE8:
    // 0x8006FFE8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006FFEC: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8006FFF0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8006FFF4: beq         $t5, $zero, L_80070044
    if (ctx->r13 == 0) {
        // 0x8006FFF8: lui         $t8, 0x8027
        ctx->r24 = S32(0X8027 << 16);
            goto L_80070044;
    }
    // 0x8006FFF8: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8006FFFC: lh          $t6, -0x1348($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X1348));
    // 0x80070000: lh          $t8, -0x1346($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X1346));
    // 0x80070004: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80070008: addiu       $t7, $t6, -0x1E
    ctx->r15 = ADD32(ctx->r14, -0X1E);
    // 0x8007000C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80070010: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80070014: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80070018: addiu       $t1, $zero, 0xE25
    ctx->r9 = ADD32(0, 0XE25);
    // 0x8007001C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80070020: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80070024: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80070028: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007002C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80070030: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80070034: jal         0x8005D13C
    // 0x80070038: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    rotatesprite(rdram, ctx);
        goto after_33;
    // 0x80070038: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_33:
    // 0x8007003C: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80070040: lh          $v0, 0x2D6($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2D6));
L_80070044:
    // 0x80070044: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x80070048: beq         $t2, $zero, L_80070098
    if (ctx->r10 == 0) {
        // 0x8007004C: lui         $t3, 0x8027
        ctx->r11 = S32(0X8027 << 16);
            goto L_80070098;
    }
    // 0x8007004C: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x80070050: lh          $t3, -0x1348($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X1348));
    // 0x80070054: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x80070058: lh          $t5, -0x1346($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X1346));
    // 0x8007005C: addiu       $t4, $t3, -0x14
    ctx->r12 = ADD32(ctx->r11, -0X14);
    // 0x80070060: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80070064: addiu       $t6, $t5, 0x7
    ctx->r14 = ADD32(ctx->r13, 0X7);
    // 0x80070068: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8007006C: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80070070: addiu       $t7, $zero, 0xE26
    ctx->r15 = ADD32(0, 0XE26);
    // 0x80070074: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80070078: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8007007C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80070080: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80070084: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80070088: jal         0x8005D13C
    // 0x8007008C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    rotatesprite(rdram, ctx);
        goto after_34;
    // 0x8007008C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_34:
    // 0x80070090: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80070094: lh          $v0, 0x2D6($t0)
    ctx->r2 = S32(MEM_H(ctx->r8, 0X2D6));
L_80070098:
    // 0x80070098: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x8007009C: beq         $t8, $zero, L_800700E0
    if (ctx->r24 == 0) {
        // 0x800700A0: lui         $t9, 0x8027
        ctx->r25 = S32(0X8027 << 16);
            goto L_800700E0;
    }
    // 0x800700A0: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x800700A4: lh          $t9, -0x1348($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X1348));
    // 0x800700A8: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x800700AC: lh          $t2, -0x1346($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X1346));
    // 0x800700B0: addiu       $t1, $t9, -0xA
    ctx->r9 = ADD32(ctx->r25, -0XA);
    // 0x800700B4: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800700B8: addiu       $t3, $t2, 0x7
    ctx->r11 = ADD32(ctx->r10, 0X7);
    // 0x800700BC: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800700C0: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800700C4: addiu       $t4, $zero, 0xE27
    ctx->r12 = ADD32(0, 0XE27);
    // 0x800700C8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x800700CC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800700D0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800700D4: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800700D8: jal         0x8005D13C
    // 0x800700DC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_35;
    // 0x800700DC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_35:
L_800700E0:
    // 0x800700E0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_800700E4:
    // 0x800700E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800700E8: jr          $ra
    // 0x800700EC: nop

    return;
    // 0x800700EC: nop

;}
RECOMP_FUNC void divscale18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009153C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091544: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091548: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009154C: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x80091550: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091554: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091558: jal         0x800BB834
    // 0x8009155C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x8009155C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091564: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091568: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8009156C: jal         0x800BB89C
    // 0x80091570: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091570: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091574: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009157C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091580: jr          $ra
    // 0x80091584: nop

    return;
    // 0x80091584: nop

;}
RECOMP_FUNC void func_80061904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061904: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80061908: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8006190C: lhu         $t7, -0x2982($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2982);
    // 0x80061910: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80061914: sll         $s1, $a0, 16
    ctx->r17 = S32(ctx->r4 << 16);
    // 0x80061918: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8006191C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80061920: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80061924: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061928: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8006192C: beq         $t6, $t7, L_80061CA0
    if (ctx->r14 == ctx->r15) {
        // 0x80061930: sh          $t6, 0x76($sp)
        MEM_H(0X76, ctx->r29) = ctx->r14;
            goto L_80061CA0;
    }
    // 0x80061930: sh          $t6, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r14;
    // 0x80061934: jal         0x8006370C
    // 0x80061938: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    gettileid(rdram, ctx);
        goto after_0;
    // 0x80061938: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    after_0:
    // 0x8006193C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80061940: sra         $t4, $t9, 16
    ctx->r12 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061944: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80061948: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8006194C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80061950: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80061954: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80061958: lw          $t6, -0x5008($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X5008));
    // 0x8006195C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80061960: sra         $t8, $s1, 16
    ctx->r24 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80061964: andi        $t7, $t6, 0xC0
    ctx->r15 = ctx->r14 & 0XC0;
    // 0x80061968: beq         $t7, $zero, L_80061988
    if (ctx->r15 == 0) {
        // 0x8006196C: or          $s1, $t8, $zero
        ctx->r17 = ctx->r24 | 0;
            goto L_80061988;
    }
    // 0x8006196C: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80061970: lh          $a0, 0x76($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X76));
    // 0x80061974: jal         0x8009223C
    // 0x80061978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    animateoffs(rdram, ctx);
        goto after_1;
    // 0x80061978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8006197C: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80061980: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x80061984: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
L_80061988:
    // 0x80061988: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8006198C: addiu       $s0, $s0, 0x4418
    ctx->r16 = ADD32(ctx->r16, 0X4418);
    // 0x80061990: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061994: lui         $t5, 0xFD10
    ctx->r13 = S32(0XFD10 << 16);
    // 0x80061998: andi        $s2, $s1, 0xFFFF
    ctx->r18 = ctx->r17 & 0XFFFF;
    // 0x8006199C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800619A0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800619A4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800619A8: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x800619AC: jal         0x80063880
    // 0x800619B0: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    func_80063880(rdram, ctx);
        goto after_2;
    // 0x800619B0: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    after_2:
    // 0x800619B4: lw          $t2, 0x70($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800619B8: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x800619BC: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x800619C0: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x800619C4: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800619C8: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x800619CC: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x800619D0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800619D4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800619D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800619DC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800619E0: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800619E4: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800619E8: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x800619EC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800619F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800619F4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800619F8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800619FC: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061A00: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x80061A04: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80061A08: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80061A0C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80061A10: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80061A14: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061A18: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061A1C: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80061A20: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80061A24: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80061A28: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80061A2C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80061A30: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80061A34: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061A38: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x80061A3C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80061A40: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80061A44: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80061A48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061A4C: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061A50: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061A54: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80061A58: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061A5C: jal         0x80063880
    // 0x80061A60: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    func_80063880(rdram, ctx);
        goto after_3;
    // 0x80061A60: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_3:
    // 0x80061A64: lw          $t3, 0x58($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80061A68: addiu       $t8, $v0, 0x20
    ctx->r24 = ADD32(ctx->r2, 0X20);
    // 0x80061A6C: lui         $t4, 0xF550
    ctx->r12 = S32(0XF550 << 16);
    // 0x80061A70: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x80061A74: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061A78: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80061A7C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061A80: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80061A84: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80061A88: jal         0x80063AE0
    // 0x80061A8C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    func_80063AE0(rdram, ctx);
        goto after_4;
    // 0x80061A8C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_4:
    // 0x80061A90: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x80061A94: jal         0x80063A08
    // 0x80061A98: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    func_80063A08(rdram, ctx);
        goto after_5;
    // 0x80061A98: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    after_5:
    // 0x80061A9C: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x80061AA0: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x80061AA4: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80061AA8: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x80061AAC: or          $t7, $t6, $t2
    ctx->r15 = ctx->r14 | ctx->r10;
    // 0x80061AB0: lw          $t6, 0x54($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80061AB4: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80061AB8: sll         $t4, $t9, 14
    ctx->r12 = S32(ctx->r25 << 14);
    // 0x80061ABC: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x80061AC0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80061AC4: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061AC8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80061ACC: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    // 0x80061AD0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80061AD4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80061AD8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80061ADC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061AE0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80061AE4: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061AE8: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80061AEC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80061AF0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80061AF4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80061AF8: addiu       $t6, $t6, -0x5010
    ctx->r14 = ADD32(ctx->r14, -0X5010);
    // 0x80061AFC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80061B00: lui         $t4, 0xF300
    ctx->r12 = S32(0XF300 << 16);
    // 0x80061B04: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x80061B08: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80061B0C: lhu         $t8, 0x14($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X14);
    // 0x80061B10: lhu         $a1, 0x12($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X12);
    // 0x80061B14: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x80061B18: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80061B1C: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061B20: mflo        $a3
    ctx->r7 = lo;
    // 0x80061B24: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x80061B28: sra         $t9, $a3, 2
    ctx->r25 = S32(SIGNED(ctx->r7) >> 2);
    // 0x80061B2C: addiu       $a3, $t9, -0x1
    ctx->r7 = ADD32(ctx->r25, -0X1);
    // 0x80061B30: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x80061B34: beq         $at, $zero, L_80061B44
    if (ctx->r1 == 0) {
        // 0x80061B38: nop
    
            goto L_80061B44;
    }
    // 0x80061B38: nop

    // 0x80061B3C: b           L_80061B44
    // 0x80061B40: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
        goto L_80061B44;
    // 0x80061B40: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_80061B44:
    // 0x80061B44: bgez        $a1, L_80061B54
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80061B48: sra         $v0, $a1, 4
        ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
            goto L_80061B54;
    }
    // 0x80061B48: sra         $v0, $a1, 4
    ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
    // 0x80061B4C: addiu       $at, $a1, 0xF
    ctx->r1 = ADD32(ctx->r5, 0XF);
    // 0x80061B50: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_80061B54:
    // 0x80061B54: bgtz        $v0, L_80061B64
    if (SIGNED(ctx->r2) > 0) {
        // 0x80061B58: andi        $t8, $t0, 0xFFF
        ctx->r24 = ctx->r8 & 0XFFF;
            goto L_80061B64;
    }
    // 0x80061B58: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x80061B5C: b           L_80061B68
    // 0x80061B60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80061B68;
    // 0x80061B60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80061B64:
    // 0x80061B64: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80061B68:
    // 0x80061B68: bgtz        $v0, L_80061B78
    if (SIGNED(ctx->r2) > 0) {
        // 0x80061B6C: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_80061B78;
    }
    // 0x80061B6C: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x80061B70: b           L_80061B7C
    // 0x80061B74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80061B7C;
    // 0x80061B74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80061B78:
    // 0x80061B78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80061B7C:
    // 0x80061B7C: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x80061B80: mflo        $t4
    ctx->r12 = lo;
    // 0x80061B84: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x80061B88: bne         $a1, $zero, L_80061B94
    if (ctx->r5 != 0) {
        // 0x80061B8C: nop
    
            goto L_80061B94;
    }
    // 0x80061B8C: nop

    // 0x80061B90: break       7
    do_break(2147883920);
L_80061B94:
    // 0x80061B94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80061B98: bne         $a1, $at, L_80061BAC
    if (ctx->r5 != ctx->r1) {
        // 0x80061B9C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80061BAC;
    }
    // 0x80061B9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80061BA0: bne         $t7, $at, L_80061BAC
    if (ctx->r15 != ctx->r1) {
        // 0x80061BA4: nop
    
            goto L_80061BAC;
    }
    // 0x80061BA4: nop

    // 0x80061BA8: break       6
    do_break(2147883944);
L_80061BAC:
    // 0x80061BAC: or          $t6, $t5, $t2
    ctx->r14 = ctx->r13 | ctx->r10;
    // 0x80061BB0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80061BB4: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80061BB8: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x80061BBC: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061BC0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80061BC4: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x80061BC8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80061BCC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80061BD0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80061BD4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061BD8: lhu         $t6, 0x12($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X12);
    // 0x80061BDC: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061BE0: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x80061BE4: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80061BE8: addiu       $t7, $t9, 0x7
    ctx->r15 = ADD32(ctx->r25, 0X7);
    // 0x80061BEC: sra         $t4, $t7, 3
    ctx->r12 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80061BF0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80061BF4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80061BF8: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x80061BFC: sll         $t8, $t5, 9
    ctx->r24 = S32(ctx->r13 << 9);
    // 0x80061C00: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80061C04: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80061C08: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80061C0C: jal         0x80063AE0
    // 0x80061C10: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    func_80063AE0(rdram, ctx);
        goto after_6;
    // 0x80061C10: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    after_6:
    // 0x80061C14: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x80061C18: jal         0x80063A08
    // 0x80061C1C: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    func_80063A08(rdram, ctx);
        goto after_7;
    // 0x80061C1C: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    after_7:
    // 0x80061C20: lbu         $t4, 0x3B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3B);
    // 0x80061C24: andi        $t9, $v0, 0xF
    ctx->r25 = ctx->r2 & 0XF;
    // 0x80061C28: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80061C2C: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x80061C30: sll         $t8, $t5, 14
    ctx->r24 = S32(ctx->r13 << 14);
    // 0x80061C34: lw          $a2, 0x28($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80061C38: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80061C3C: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x80061C40: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061C44: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x80061C48: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80061C4C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061C50: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80061C54: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80061C58: lhu         $t5, 0x14($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X14);
    // 0x80061C5C: lhu         $t9, 0x12($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X12);
    // 0x80061C60: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80061C64: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80061C68: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80061C6C: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x80061C70: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80061C74: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x80061C78: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80061C7C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80061C80: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80061C84: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80061C88: lhu         $t4, 0x76($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X76);
    // 0x80061C8C: addiu       $a1, $a1, -0x1B34
    ctx->r5 = ADD32(ctx->r5, -0X1B34);
    // 0x80061C90: sh          $t4, -0x2982($at)
    MEM_H(-0X2982, ctx->r1) = ctx->r12;
    // 0x80061C94: lw          $t5, 0x0($a1)
    ctx->r13 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80061C98: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80061C9C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80061CA0:
    // 0x80061CA0: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80061CA4: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80061CA8: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80061CAC: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80061CB0: jr          $ra
    // 0x80061CB4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80061CB4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void divscale17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800914F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800914F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800914F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800914FC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091500: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x80091504: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091508: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009150C: jal         0x800BB834
    // 0x80091510: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091510: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091518: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8009151C: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091520: jal         0x800BB89C
    // 0x80091524: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091524: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091528: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8009152C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091530: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091534: jr          $ra
    // 0x80091538: nop

    return;
    // 0x80091538: nop

;}
RECOMP_FUNC void view(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070EF4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80070EF8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80070EFC: lh          $s0, 0x9E($sp)
    ctx->r16 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x80070F00: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80070F04: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80070F08: addiu       $t6, $s0, 0x600
    ctx->r14 = ADD32(ctx->r16, 0X600);
    // 0x80070F0C: andi        $t7, $t6, 0x7FF
    ctx->r15 = ctx->r14 & 0X7FF;
    // 0x80070F10: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80070F14: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80070F18: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80070F1C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80070F20: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80070F24: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80070F28: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80070F2C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80070F30: lh          $t7, 0x2E0($a0)
    ctx->r15 = S32(MEM_H(ctx->r4, 0X2E0));
    // 0x80070F34: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80070F38: addiu       $t0, $t0, -0x9A0
    ctx->r8 = ADD32(ctx->r8, -0X9A0);
    // 0x80070F3C: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x80070F40: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80070F44: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80070F48: lh          $s1, 0x0($t9)
    ctx->r17 = S32(MEM_H(ctx->r25, 0X0));
    // 0x80070F4C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80070F50: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80070F54: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80070F58: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80070F5C: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x80070F60: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80070F64: addiu       $t2, $s0, 0x400
    ctx->r10 = ADD32(ctx->r16, 0X400);
    // 0x80070F68: lh          $v0, 0xC($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0XC));
    // 0x80070F6C: andi        $t3, $t2, 0x7FF
    ctx->r11 = ctx->r10 & 0X7FF;
    // 0x80070F70: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80070F74: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80070F78: sra         $t1, $s1, 4
    ctx->r9 = S32(SIGNED(ctx->r17) >> 4);
    // 0x80070F7C: lh          $s2, 0x0($t5)
    ctx->r18 = S32(MEM_H(ctx->r13, 0X0));
    // 0x80070F80: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80070F84: lw          $fp, 0x98($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80070F88: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x80070F8C: andi        $t1, $v0, 0xFEFE
    ctx->r9 = ctx->r2 & 0XFEFE;
    // 0x80070F90: sh          $t1, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r9;
    // 0x80070F94: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80070F98: lw          $a0, 0x0($a1)
    ctx->r4 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80070F9C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80070FA0: lw          $a1, 0x0($a2)
    ctx->r5 = S32(MEM_W(ctx->r6, 0X0));
    // 0x80070FA4: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80070FA8: lw          $a2, 0x0($a3)
    ctx->r6 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80070FAC: sra         $t6, $s2, 4
    ctx->r14 = S32(SIGNED(ctx->r18) >> 4);
    // 0x80070FB0: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80070FB4: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x80070FB8: jal         0x80070CB0
    // 0x80070FBC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    updatesectorz(rdram, ctx);
        goto after_0;
    // 0x80070FBC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_0:
    // 0x80070FC0: sll         $t2, $s1, 14
    ctx->r10 = S32(ctx->r17 << 14);
    // 0x80070FC4: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80070FC8: sll         $t4, $s2, 14
    ctx->r12 = S32(ctx->r18 << 14);
    // 0x80070FCC: bgez        $s1, L_80070FDC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80070FD0: sra         $t3, $s1, 3
        ctx->r11 = S32(SIGNED(ctx->r17) >> 3);
            goto L_80070FDC;
    }
    // 0x80070FD0: sra         $t3, $s1, 3
    ctx->r11 = S32(SIGNED(ctx->r17) >> 3);
    // 0x80070FD4: addiu       $at, $s1, 0x7
    ctx->r1 = ADD32(ctx->r17, 0X7);
    // 0x80070FD8: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_80070FDC:
    // 0x80070FDC: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x80070FE0: lui         $s3, 0x1
    ctx->r19 = S32(0X1 << 16);
    // 0x80070FE4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80070FE8: bgez        $s2, L_80070FF8
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80070FEC: sra         $t5, $s2, 3
        ctx->r13 = S32(SIGNED(ctx->r18) >> 3);
            goto L_80070FF8;
    }
    // 0x80070FEC: sra         $t5, $s2, 3
    ctx->r13 = S32(SIGNED(ctx->r18) >> 3);
    // 0x80070FF0: addiu       $at, $s2, 0x7
    ctx->r1 = ADD32(ctx->r18, 0X7);
    // 0x80070FF4: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80070FF8:
    // 0x80070FF8: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x80070FFC: ori         $s3, $s3, 0x1
    ctx->r19 = ctx->r19 | 0X1;
    // 0x80071000: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80071004: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80071008: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
L_8007100C:
    // 0x8007100C: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x80071010: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80071014: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80071018: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007101C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80071020: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80071024: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80071028: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8007102C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x80071030: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80071034: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80071038: jal         0x800958C8
    // 0x8007103C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    clipmove(rdram, ctx);
        goto after_1;
    // 0x8007103C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    after_1:
    // 0x80071040: bne         $v0, $zero, L_80071050
    if (ctx->r2 != 0) {
        // 0x80071044: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80071050;
    }
    // 0x80071044: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80071048: bnel        $s0, $s4, L_8007100C
    if (ctx->r16 != ctx->r20) {
        // 0x8007104C: addiu       $t6, $zero, 0x80
        ctx->r14 = ADD32(0, 0X80);
            goto L_8007100C;
    }
    goto skip_0;
    // 0x8007104C: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    skip_0:
L_80071050:
    // 0x80071050: lh          $t9, 0x0($fp)
    ctx->r25 = S32(MEM_H(ctx->r30, 0X0));
    // 0x80071054: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80071058: addiu       $v1, $v1, -0x1830
    ctx->r3 = ADD32(ctx->r3, -0X1830);
    // 0x8007105C: bgez        $t9, L_80071074
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80071060: lui         $t0, 0x800F
        ctx->r8 = S32(0X800F << 16);
            goto L_80071074;
    }
    // 0x80071060: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x80071064: lh          $t1, 0x5A($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x80071068: lw          $t2, 0x84($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X84));
    // 0x8007106C: b           L_800710D4
    // 0x80071070: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
        goto L_800710D4;
    // 0x80071070: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
L_80071074:
    // 0x80071074: addiu       $t0, $t0, -0x182C
    ctx->r8 = ADD32(ctx->r8, -0X182C);
    // 0x80071078: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x8007107C: lw          $v0, -0x5370($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X5370));
    // 0x80071080: lw          $t4, 0x0($t0)
    ctx->r12 = S32(MEM_W(ctx->r8, 0X0));
    // 0x80071084: lw          $t3, 0x0($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80071088: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8007108C: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80071090: sll         $t6, $t5, 10
    ctx->r14 = S32(ctx->r13 << 10);
    // 0x80071094: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80071098: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8007109C: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800710A0: bne         $at, $zero, L_800710B0
    if (ctx->r1 != 0) {
        // 0x800710A4: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_800710B0;
    }
    // 0x800710A4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800710A8: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800710AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800710B0:
    // 0x800710B0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800710B4: lw          $a2, 0x0($s7)
    ctx->r6 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800710B8: lw          $a1, 0x0($s6)
    ctx->r5 = S32(MEM_W(ctx->r22, 0X0));
    // 0x800710BC: lw          $a0, 0x0($s5)
    ctx->r4 = S32(MEM_W(ctx->r21, 0X0));
    // 0x800710C0: jal         0x80070CB0
    // 0x800710C4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    updatesectorz(rdram, ctx);
        goto after_2;
    // 0x800710C4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x800710C8: lh          $t1, 0x5A($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x800710CC: lw          $t2, 0x84($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800710D0: sh          $t1, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r9;
L_800710D4:
    // 0x800710D4: lw          $ra, 0x54($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800710D8: lw          $s0, 0x30($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800710DC: lw          $s1, 0x34($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800710E0: lw          $s2, 0x38($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800710E4: lw          $s3, 0x3C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800710E8: lw          $s4, 0x40($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800710EC: lw          $s5, 0x44($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800710F0: lw          $s6, 0x48($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800710F4: lw          $s7, 0x4C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800710F8: lw          $fp, 0x50($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800710FC: jr          $ra
    // 0x80071100: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80071100: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80063270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063270: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x80063274: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80063278: lhu         $t6, -0x2340($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2340);
    // 0x8006327C: lw          $a3, -0x1994($a3)
    ctx->r7 = S32(MEM_W(ctx->r7, -0X1994));
    // 0x80063280: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063284: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80063288: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8006328C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80063290: lui         $a2, 0x8022
    ctx->r6 = S32(0X8022 << 16);
    // 0x80063294: lw          $a2, -0x1998($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, -0X1998));
    // 0x80063298: lw          $a1, -0x199C($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X199C));
    // 0x8006329C: lw          $a0, -0x19A0($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X19A0));
    // 0x800632A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800632A4: jal         0x80059DEC
    // 0x800632A8: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    drawrooms_(rdram, ctx);
        goto after_0;
    // 0x800632A8: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    after_0:
    // 0x800632AC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800632B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800632B4: jr          $ra
    // 0x800632B8: nop

    return;
    // 0x800632B8: nop

;}
RECOMP_FUNC void func_8005862C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005862C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058634: jal         0x80058348
    // 0x80058638: nop

    func_80058348(rdram, ctx);
        goto after_0;
    // 0x80058638: nop

    after_0:
    // 0x8005863C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058640: beq         $v0, $at, L_80058674
    if (ctx->r2 == ctx->r1) {
        // 0x80058644: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80058674;
    }
    // 0x80058644: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80058648: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8005864C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80058650: addiu       $t7, $t7, -0x5F08
    ctx->r15 = ADD32(ctx->r15, -0X5F08);
    // 0x80058654: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80058658: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8005865C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80058660: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80058664: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x80058668: addiu       $a0, $a0, -0x5FA0
    ctx->r4 = ADD32(ctx->r4, -0X5FA0);
    // 0x8005866C: jal         0x800BB610
    // 0x80058670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80058670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80058674:
    // 0x80058674: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80058678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005867C: jr          $ra
    // 0x80058680: nop

    return;
    // 0x80058680: nop

;}
RECOMP_FUNC void addweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075748: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8007574C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80075750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80075758: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x8007575C: lbu         $t8, 0x349($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X349);
    // 0x80075760: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80075764: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80075768: bne         $t8, $zero, L_800757D8
    if (ctx->r24 != 0) {
        // 0x8007576C: sltiu       $at, $a1, 0xC
        ctx->r1 = ctx->r5 < 0XC ? 1 : 0;
            goto L_800757D8;
    }
    // 0x8007576C: sltiu       $at, $a1, 0xC
    ctx->r1 = ctx->r5 < 0XC ? 1 : 0;
    // 0x80075770: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80075774: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80075778: bne         $t7, $at, L_80075784
    if (ctx->r15 != ctx->r1) {
        // 0x8007577C: sb          $v1, 0x349($v0)
        MEM_B(0X349, ctx->r2) = ctx->r3;
            goto L_80075784;
    }
    // 0x8007577C: sb          $v1, 0x349($v0)
    MEM_B(0X349, ctx->r2) = ctx->r3;
    // 0x80075780: sb          $v1, 0x350($a0)
    MEM_B(0X350, ctx->r4) = ctx->r3;
L_80075784:
    // 0x80075784: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80075788: bnel        $a1, $at, L_80075798
    if (ctx->r5 != ctx->r1) {
        // 0x8007578C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80075798;
    }
    goto skip_0;
    // 0x8007578C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80075790: sb          $v1, 0x34F($a2)
    MEM_B(0X34F, ctx->r6) = ctx->r3;
    // 0x80075794: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80075798:
    // 0x80075798: bnel        $a1, $at, L_800757A8
    if (ctx->r5 != ctx->r1) {
        // 0x8007579C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800757A8;
    }
    goto skip_1;
    // 0x8007579C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x800757A0: sb          $v1, 0x355($a2)
    MEM_B(0X355, ctx->r6) = ctx->r3;
    // 0x800757A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800757A8:
    // 0x800757A8: bnel        $a1, $at, L_800757B8
    if (ctx->r5 != ctx->r1) {
        // 0x800757AC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800757B8;
    }
    goto skip_2;
    // 0x800757AC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_2:
    // 0x800757B0: sb          $v1, 0x356($a2)
    MEM_B(0X356, ctx->r6) = ctx->r3;
    // 0x800757B4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_800757B8:
    // 0x800757B8: bnel        $a1, $at, L_800757C8
    if (ctx->r5 != ctx->r1) {
        // 0x800757BC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800757C8;
    }
    goto skip_3;
    // 0x800757BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_3:
    // 0x800757C0: sb          $v1, 0x357($a2)
    MEM_B(0X357, ctx->r6) = ctx->r3;
    // 0x800757C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_800757C8:
    // 0x800757C8: bnel        $a1, $at, L_8007586C
    if (ctx->r5 != ctx->r1) {
        // 0x800757CC: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8007586C;
    }
    goto skip_4;
    // 0x800757CC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_4:
    // 0x800757D0: b           L_80075868
    // 0x800757D4: sb          $v1, 0x354($a2)
    MEM_B(0X354, ctx->r6) = ctx->r3;
        goto L_80075868;
    // 0x800757D4: sb          $v1, 0x354($a2)
    MEM_B(0X354, ctx->r6) = ctx->r3;
L_800757D8:
    // 0x800757D8: lbu         $t9, 0x347($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X347);
    // 0x800757DC: sh          $zero, 0x2E4($a2)
    MEM_H(0X2E4, ctx->r6) = 0;
    // 0x800757E0: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800757E4: bne         $t9, $zero, L_80075800
    if (ctx->r25 != 0) {
        // 0x800757E8: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80075800;
    }
    // 0x800757E8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800757EC: lh          $t1, 0x2B2($a2)
    ctx->r9 = S32(MEM_H(ctx->r6, 0X2B2));
    // 0x800757F0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800757F4: sh          $t0, 0x328($a2)
    MEM_H(0X328, ctx->r6) = ctx->r8;
    // 0x800757F8: b           L_8007580C
    // 0x800757FC: sh          $t1, 0x2B4($a2)
    MEM_H(0X2B4, ctx->r6) = ctx->r9;
        goto L_8007580C;
    // 0x800757FC: sh          $t1, 0x2B4($a2)
    MEM_H(0X2B4, ctx->r6) = ctx->r9;
L_80075800:
    // 0x80075800: sh          $t2, 0x328($a2)
    MEM_H(0X328, ctx->r6) = ctx->r10;
    // 0x80075804: sb          $zero, 0x347($a2)
    MEM_B(0X347, ctx->r6) = 0;
    // 0x80075808: sh          $t3, 0x2B4($a2)
    MEM_H(0X2B4, ctx->r6) = ctx->r11;
L_8007580C:
    // 0x8007580C: sh          $zero, 0x2D4($a2)
    MEM_H(0X2D4, ctx->r6) = 0;
    // 0x80075810: sh          $a1, 0x2B2($a2)
    MEM_H(0X2B2, ctx->r6) = ctx->r5;
    // 0x80075814: beq         $at, $zero, L_8007585C
    if (ctx->r1 == 0) {
        // 0x80075818: sh          $a1, 0x372($a2)
        MEM_H(0X372, ctx->r6) = ctx->r5;
            goto L_8007585C;
    }
    // 0x80075818: sh          $a1, 0x372($a2)
    MEM_H(0X372, ctx->r6) = ctx->r5;
    // 0x8007581C: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x80075820: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80075824: addu        $at, $at, $t4
    gpr jr_addend_8007582C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80075828: lw          $t4, 0x5344($at)
    ctx->r12 = ADD32(ctx->r1, 0X5344);
    // 0x8007582C: jr          $t4
    // 0x80075830: nop

    switch (jr_addend_8007582C >> 2) {
        case 0: goto L_80075868; break;
        case 1: goto L_80075848; break;
        case 2: goto L_80075834; break;
        case 3: goto L_8007585C; break;
        case 4: goto L_8007585C; break;
        case 5: goto L_80075868; break;
        case 6: goto L_8007585C; break;
        case 7: goto L_8007585C; break;
        case 8: goto L_8007585C; break;
        case 9: goto L_80075868; break;
        case 10: goto L_8007585C; break;
        case 11: goto L_80075868; break;
        default: switch_error(__func__, 0x8007582C, 0x80105344);
    }
    // 0x80075830: nop

L_80075834:
    // 0x80075834: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    // 0x80075838: jal         0x80059034
    // 0x8007583C: lh          $a1, 0x2E0($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X2E0));
    spritesound(rdram, ctx);
        goto after_0;
    // 0x8007583C: lh          $a1, 0x2E0($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X2E0));
    after_0:
    // 0x80075840: b           L_8007586C
    // 0x80075844: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8007586C;
    // 0x80075844: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80075848:
    // 0x80075848: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8007584C: jal         0x80059034
    // 0x80075850: lh          $a1, 0x2E0($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X2E0));
    spritesound(rdram, ctx);
        goto after_1;
    // 0x80075850: lh          $a1, 0x2E0($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X2E0));
    after_1:
    // 0x80075854: b           L_8007586C
    // 0x80075858: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8007586C;
    // 0x80075858: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8007585C:
    // 0x8007585C: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    // 0x80075860: jal         0x80059034
    // 0x80075864: lh          $a1, 0x2E0($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X2E0));
    spritesound(rdram, ctx);
        goto after_2;
    // 0x80075864: lh          $a1, 0x2E0($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X2E0));
    after_2:
L_80075868:
    // 0x80075868: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8007586C:
    // 0x8007586C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075870: jr          $ra
    // 0x80075874: nop

    return;
    // 0x80075874: nop

;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3360: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800C3364: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800C3368: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800C336C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X78));
    // 0x800C3370: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800C3374: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X80));
    // 0x800C3378: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C337C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800C3380: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800C3384: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800C3388: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800C338C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C3390: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C3394: jal         0x800C3130
    // 0x800C3398: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x800C3398: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800C339C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800C33A0: jal         0x800C8AC0
    // 0x800C33A4: lw          $a1, 0x68($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X68));
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800C33A4: lw          $a1, 0x68($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X68));
    after_1:
    // 0x800C33A8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C33AC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800C33B0: jr          $ra
    // 0x800C33B4: nop

    return;
    // 0x800C33B4: nop

;}
RECOMP_FUNC void mainproc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BD88: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8004BD8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004BD90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004BD94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8004BD98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004BD9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004BDA0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8004BDA4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8004BDA8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8004BDAC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8004BDB0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004BDB4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004BDB8: addiu       $a1, $a1, 0x36B0
    ctx->r5 = ADD32(ctx->r5, 0X36B0);
    // 0x8004BDBC: addiu       $a0, $a0, 0x3620
    ctx->r4 = ADD32(ctx->r4, 0X3620);
    // 0x8004BDC0: jal         0x800BB760
    // 0x8004BDC4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8004BDC4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x8004BDC8: lui         $a3, 0x802B
    ctx->r7 = S32(0X802B << 16);
    // 0x8004BDCC: lui         $v0, 0xC
    ctx->r2 = S32(0XC << 16);
    // 0x8004BDD0: addiu       $a3, $a3, -0x1850
    ctx->r7 = ADD32(ctx->r7, -0X1850);
    // 0x8004BDD4: addiu       $v0, $v0, 0x2270
    ctx->r2 = ADD32(ctx->r2, 0X2270);
    // 0x8004BDD8: lui         $a1, 0xC
    ctx->r5 = S32(0XC << 16);
    // 0x8004BDDC: addiu       $a1, $a1, 0x880
    ctx->r5 = ADD32(ctx->r5, 0X880);
    // 0x8004BDE0: addu        $t7, $a3, $v0
    ctx->r15 = ADD32(ctx->r7, ctx->r2);
    // 0x8004BDE4: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x8004BDE8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8004BDEC: ori         $at, $at, 0x5001
    ctx->r1 = ctx->r1 | 0X5001;
    // 0x8004BDF0: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x8004BDF4: addiu       $v1, $v1, 0x4414
    ctx->r3 = ADD32(ctx->r3, 0X4414);
    // 0x8004BDF8: sltu        $at, $t8, $at
    ctx->r1 = ctx->r24 < ctx->r1 ? 1 : 0;
    // 0x8004BDFC: bne         $at, $zero, L_8004BE0C
    if (ctx->r1 != 0) {
        // 0x8004BE00: sw          $a3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r7;
            goto L_8004BE0C;
    }
    // 0x8004BE00: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
L_8004BE04:
    // 0x8004BE04: b           L_8004BE04
    pause_self(rdram);
    // 0x8004BE08: nop

L_8004BE0C:
    // 0x8004BE0C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8004BE10: jal         0x8004B560
    // 0x8004BE14: subu        $a2, $v0, $a1
    ctx->r6 = SUB32(ctx->r2, ctx->r5);
    copyfromrom(rdram, ctx);
        goto after_1;
    // 0x8004BE14: subu        $a2, $v0, $a1
    ctx->r6 = SUB32(ctx->r2, ctx->r5);
    after_1:
    // 0x8004BE18: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8004BE1C: addiu       $s1, $s1, -0xCB8
    ctx->r17 = ADD32(ctx->r17, -0XCB8);
    // 0x8004BE20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004BE24: addiu       $a1, $a1, 0x35D0
    ctx->r5 = ADD32(ctx->r5, 0X35D0);
    // 0x8004BE28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BE2C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8004BE30: jal         0x8004C410
    // 0x8004BE34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    osCreateScheduler2(rdram, ctx);
        goto after_2;
    // 0x8004BE34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8004BE38: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x8004BE3C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8004BE40: addiu       $s2, $s2, 0x6FE8
    ctx->r18 = ADD32(ctx->r18, 0X6FE8);
    // 0x8004BE44: addiu       $t9, $t9, -0x4E68
    ctx->r25 = ADD32(ctx->r25, -0X4E68);
    // 0x8004BE48: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8004BE4C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8004BE50: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8004BE54: addiu       $a2, $a2, -0x3E08
    ctx->r6 = ADD32(ctx->r6, -0X3E08);
    // 0x8004BE58: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8004BE5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004BE60: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8004BE64: jal         0x800BADE0
    // 0x8004BE68: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8004BE68: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x8004BE6C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8004BE70: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004BE74: addiu       $s3, $s3, -0x4E68
    ctx->r19 = ADD32(ctx->r19, -0X4E68);
    // 0x8004BE78: addiu       $t1, $t1, -0xCB8
    ctx->r9 = ADD32(ctx->r9, -0XCB8);
    // 0x8004BE7C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8004BE80: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8004BE84: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8004BE88: addiu       $a2, $a2, -0x3CBC
    ctx->r6 = ADD32(ctx->r6, -0X3CBC);
    // 0x8004BE8C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8004BE90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8004BE94: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8004BE98: jal         0x800BADE0
    // 0x8004BE9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_4;
    // 0x8004BE9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8004BEA0: jal         0x800582F0
    // 0x8004BEA4: nop

    soundSetupMsgQueue(rdram, ctx);
        goto after_5;
    // 0x8004BEA4: nop

    after_5:
    // 0x8004BEA8: jal         0x800577DC
    // 0x8004BEAC: nop

    soundInit(rdram, ctx);
        goto after_6;
    // 0x8004BEAC: nop

    after_6:
    // 0x8004BEB0: jal         0x80051910
    // 0x8004BEB4: nop

    controllervibdisable(rdram, ctx);
        goto after_7;
    // 0x8004BEB4: nop

    after_7:
    // 0x8004BEB8: jal         0x8004CF88
    // 0x8004BEBC: nop

    initControllers(rdram, ctx);
        goto after_8;
    // 0x8004BEBC: nop

    after_8:
    // 0x8004BEC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004BEC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004BEC8: addiu       $a1, $a1, 0x36D0
    ctx->r5 = ADD32(ctx->r5, 0X36D0);
    // 0x8004BECC: addiu       $a0, $a0, 0x3638
    ctx->r4 = ADD32(ctx->r4, 0X3638);
    // 0x8004BED0: jal         0x800BB760
    // 0x8004BED4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_9;
    // 0x8004BED4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8004BED8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8004BEDC: addiu       $s4, $s4, 0x3650
    ctx->r20 = ADD32(ctx->r20, 0X3650);
    // 0x8004BEE0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004BEE4: addiu       $a1, $a1, 0x36D8
    ctx->r5 = ADD32(ctx->r5, 0X36D8);
    // 0x8004BEE8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004BEEC: jal         0x800BB760
    // 0x8004BEF0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_10;
    // 0x8004BEF0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_10:
    // 0x8004BEF4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004BEF8: addiu       $a1, $a1, 0x35D0
    ctx->r5 = ADD32(ctx->r5, 0X35D0);
    // 0x8004BEFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BF00: jal         0x8004C57C
    // 0x8004BF04: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    osScAddClient(rdram, ctx);
        goto after_11;
    // 0x8004BF04: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
    // 0x8004BF08: jal         0x800BAF30
    // 0x8004BF0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_12;
    // 0x8004BF0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x8004BF10: jal         0x800BAF30
    // 0x8004BF14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_13;
    // 0x8004BF14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x8004BF18: jal         0x8004B650
    // 0x8004BF1C: nop

    determineclockfreq(rdram, ctx);
        goto after_14;
    // 0x8004BF1C: nop

    after_14:
    // 0x8004BF20: jal         0x8004D804
    // 0x8004BF24: nop

    setdefaultcontrollermode(rdram, ctx);
        goto after_15;
    // 0x8004BF24: nop

    after_15:
    // 0x8004BF28: jal         0x800B4D34
    // 0x8004BF2C: nop

    loadefs(rdram, ctx);
        goto after_16;
    // 0x8004BF2C: nop

    after_16:
    // 0x8004BF30: jal         0x80064848
    // 0x8004BF34: nop

    cacheandtileinit(rdram, ctx);
        goto after_17;
    // 0x8004BF34: nop

    after_17:
    // 0x8004BF38: jal         0x800BB580
    // 0x8004BF3C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_18;
    // 0x8004BF3C: nop

    after_18:
    // 0x8004BF40: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8004BF44: addiu       $s2, $s2, 0x4428
    ctx->r18 = ADD32(ctx->r18, 0X4428);
    // 0x8004BF48: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x8004BF4C: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x8004BF50: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x8004BF54: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8004BF58: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8004BF5C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8004BF60: sw          $v1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r3;
    // 0x8004BF64: addiu       $s0, $s0, 0x4408
    ctx->r16 = ADD32(ctx->r16, 0X4408);
    // 0x8004BF68: addiu       $s1, $s1, 0x36F8
    ctx->r17 = ADD32(ctx->r17, 0X36F8);
    // 0x8004BF6C: addiu       $s3, $s3, 0x36CC
    ctx->r19 = ADD32(ctx->r19, 0X36CC);
    // 0x8004BF70: addiu       $s5, $s5, 0x4420
    ctx->r21 = ADD32(ctx->r21, 0X4420);
    // 0x8004BF74: addiu       $s6, $s6, 0x36F0
    ctx->r22 = ADD32(ctx->r22, 0X36F0);
L_8004BF78:
    // 0x8004BF78: jal         0x800BB580
    // 0x8004BF7C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_19;
    // 0x8004BF7C: nop

    after_19:
    // 0x8004BF80: lw          $t7, 0x4($s5)
    ctx->r15 = S32(MEM_W(ctx->r21, 0X4));
    // 0x8004BF84: lw          $t6, 0x0($s5)
    ctx->r14 = S32(MEM_W(ctx->r21, 0X0));
    // 0x8004BF88: lw          $t1, 0x4($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8004BF8C: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8004BF90: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x8004BF94: subu        $t9, $v1, $t7
    ctx->r25 = SUB32(ctx->r3, ctx->r15);
    // 0x8004BF98: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x8004BF9C: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x8004BFA0: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x8004BFA4: sltu        $at, $t3, $t9
    ctx->r1 = ctx->r11 < ctx->r25 ? 1 : 0;
    // 0x8004BFA8: addu        $t2, $at, $t0
    ctx->r10 = ADD32(ctx->r1, ctx->r8);
    // 0x8004BFAC: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8004BFB0: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8004BFB4: sw          $v1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r3;
    // 0x8004BFB8: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8004BFBC: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x8004BFC0: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004BFC4: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004BFC8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004BFCC: jal         0x800BB8F8
    // 0x8004BFD0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    __ll_mul_recomp(rdram, ctx);
        goto after_20;
    // 0x8004BFD0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_20:
    // 0x8004BFD4: lw          $t4, 0x0($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8004BFD8: lw          $t5, 0x4($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8004BFDC: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004BFE0: bne         $at, $zero, L_8004C014
    if (ctx->r1 != 0) {
        // 0x8004BFE4: slt         $at, $v0, $t4
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
            goto L_8004C014;
    }
    // 0x8004BFE4: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8004BFE8: bne         $at, $zero, L_8004BFFC
    if (ctx->r1 != 0) {
        // 0x8004BFEC: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_8004BFFC;
    }
    // 0x8004BFEC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004BFF0: sltu        $at, $v1, $t5
    ctx->r1 = ctx->r3 < ctx->r13 ? 1 : 0;
    // 0x8004BFF4: beql        $at, $zero, L_8004C018
    if (ctx->r1 == 0) {
        // 0x8004BFF8: lw          $t6, 0x0($s2)
        ctx->r14 = S32(MEM_W(ctx->r18, 0X0));
            goto L_8004C018;
    }
    goto skip_0;
    // 0x8004BFF8: lw          $t6, 0x0($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X0));
    skip_0:
L_8004BFFC:
    // 0x8004BFFC: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004C000: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004C004: jal         0x800BB8F8
    // 0x8004C008: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    __ll_mul_recomp(rdram, ctx);
        goto after_21;
    // 0x8004C008: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_21:
    // 0x8004C00C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8004C010: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
L_8004C014:
    // 0x8004C014: lw          $t6, 0x0($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X0));
L_8004C018:
    // 0x8004C018: lw          $t7, 0x4($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8004C01C: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004C020: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004C024: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004C028: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8004C02C: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x8004C030: jal         0x800BB8F8
    // 0x8004C034: sw          $t7, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r15;
    __ll_mul_recomp(rdram, ctx);
        goto after_22;
    // 0x8004C034: sw          $t7, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r15;
    after_22:
    // 0x8004C038: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8004C03C: lw          $t1, 0x4($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8004C040: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004C044: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8004C048: bne         $at, $zero, L_8004C0EC
    if (ctx->r1 != 0) {
        // 0x8004C04C: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_8004C0EC;
    }
    // 0x8004C04C: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8004C050: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004C054: bne         $at, $zero, L_8004C064
    if (ctx->r1 != 0) {
        // 0x8004C058: sltu        $at, $v1, $t1
        ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
            goto L_8004C064;
    }
    // 0x8004C058: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x8004C05C: beql        $at, $zero, L_8004C0F0
    if (ctx->r1 == 0) {
        // 0x8004C060: lw          $t8, 0x40($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X40));
            goto L_8004C0F0;
    }
    goto skip_1;
    // 0x8004C060: lw          $t8, 0x40($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X40));
    skip_1:
L_8004C064:
    // 0x8004C064: jal         0x8004B9E4
    // 0x8004C068: nop

    timerupdate(rdram, ctx);
        goto after_23;
    // 0x8004C068: nop

    after_23:
    // 0x8004C06C: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004C070: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004C074: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004C078: jal         0x800BB8F8
    // 0x8004C07C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    __ll_mul_recomp(rdram, ctx);
        goto after_24;
    // 0x8004C07C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_24:
    // 0x8004C080: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8004C084: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004C088: lw          $t3, 0x36FC($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X36FC));
    // 0x8004C08C: lw          $t2, 0x36F8($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X36F8));
    // 0x8004C090: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004C094: sltu        $at, $t3, $v1
    ctx->r1 = ctx->r11 < ctx->r3 ? 1 : 0;
    // 0x8004C098: subu        $t4, $t2, $v0
    ctx->r12 = SUB32(ctx->r10, ctx->r2);
    // 0x8004C09C: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x8004C0A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C0A4: subu        $t5, $t3, $v1
    ctx->r13 = SUB32(ctx->r11, ctx->r3);
    // 0x8004C0A8: sw          $t5, 0x36FC($at)
    MEM_W(0X36FC, ctx->r1) = ctx->r13;
    // 0x8004C0AC: sw          $t4, 0x36F8($at)
    MEM_W(0X36F8, ctx->r1) = ctx->r12;
    // 0x8004C0B0: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004C0B4: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004C0B8: jal         0x800BB8F8
    // 0x8004C0BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    __ll_mul_recomp(rdram, ctx);
        goto after_25;
    // 0x8004C0BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_25:
    // 0x8004C0C0: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8004C0C4: lw          $t7, 0x4($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8004C0C8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004C0CC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8004C0D0: bne         $at, $zero, L_8004C064
    if (ctx->r1 != 0) {
        // 0x8004C0D4: sw          $t7, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r15;
            goto L_8004C064;
    }
    // 0x8004C0D4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8004C0D8: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004C0DC: bne         $at, $zero, L_8004C0EC
    if (ctx->r1 != 0) {
        // 0x8004C0E0: sltu        $at, $v1, $t7
        ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
            goto L_8004C0EC;
    }
    // 0x8004C0E0: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x8004C0E4: bne         $at, $zero, L_8004C064
    if (ctx->r1 != 0) {
        // 0x8004C0E8: nop
    
            goto L_8004C064;
    }
    // 0x8004C0E8: nop

L_8004C0EC:
    // 0x8004C0EC: lw          $t8, 0x40($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X40));
L_8004C0F0:
    // 0x8004C0F0: bltz        $t8, L_8004BF78
    if (SIGNED(ctx->r24) < 0) {
        // 0x8004C0F4: nop
    
            goto L_8004BF78;
    }
    // 0x8004C0F4: nop

    // 0x8004C0F8: bgtz        $t8, L_8004C100
    if (SIGNED(ctx->r24) > 0) {
        // 0x8004C0FC: nop
    
            goto L_8004C100;
    }
    // 0x8004C0FC: nop

L_8004C100:
    // 0x8004C100: jal         0x8004B9E4
    // 0x8004C104: nop

    timerupdate(rdram, ctx);
        goto after_26;
    // 0x8004C104: nop

    after_26:
    // 0x8004C108: jal         0x8004BB84
    // 0x8004C10C: nop

    setupgfx(rdram, ctx);
        goto after_27;
    // 0x8004C10C: nop

    after_27:
    // 0x8004C110: jal         0x8004B890
    // 0x8004C114: nop

    display(rdram, ctx);
        goto after_28;
    // 0x8004C114: nop

    after_28:
    // 0x8004C118: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004C11C: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004C120: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004C124: jal         0x800BB8F8
    // 0x8004C128: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    __ll_mul_recomp(rdram, ctx);
        goto after_29;
    // 0x8004C128: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_29:
    // 0x8004C12C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8004C130: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004C134: lw          $t3, 0x36FC($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X36FC));
    // 0x8004C138: lw          $t2, 0x36F8($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X36F8));
    // 0x8004C13C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004C140: sltu        $at, $t3, $v1
    ctx->r1 = ctx->r11 < ctx->r3 ? 1 : 0;
    // 0x8004C144: subu        $t4, $t2, $v0
    ctx->r12 = SUB32(ctx->r10, ctx->r2);
    // 0x8004C148: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x8004C14C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C150: subu        $t5, $t3, $v1
    ctx->r13 = SUB32(ctx->r11, ctx->r3);
    // 0x8004C154: sw          $t5, 0x36FC($at)
    MEM_W(0X36FC, ctx->r1) = ctx->r13;
    // 0x8004C158: sw          $t4, 0x36F8($at)
    MEM_W(0X36F8, ctx->r1) = ctx->r12;
    // 0x8004C15C: lw          $t6, 0x0($s3)
    ctx->r14 = S32(MEM_W(ctx->r19, 0X0));
    // 0x8004C160: addiu       $a0, $a0, 0x3638
    ctx->r4 = ADD32(ctx->r4, 0X3638);
    // 0x8004C164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004C168: beq         $t6, $zero, L_8004C1AC
    if (ctx->r14 == 0) {
        // 0x8004C16C: nop
    
            goto L_8004C1AC;
    }
    // 0x8004C16C: nop

    // 0x8004C170: jal         0x800BB440
    // 0x8004C174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_30;
    // 0x8004C174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_30:
    // 0x8004C178: lw          $t7, 0x8($s4)
    ctx->r15 = S32(MEM_W(ctx->r20, 0X8));
    // 0x8004C17C: lw          $t0, 0x10($s4)
    ctx->r8 = S32(MEM_W(ctx->r20, 0X10));
    // 0x8004C180: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x8004C184: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004C188: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004C18C: bne         $at, $zero, L_8004C19C
    if (ctx->r1 != 0) {
        // 0x8004C190: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8004C19C;
    }
    // 0x8004C190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004C194: jal         0x800BB440
    // 0x8004C198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_31;
    // 0x8004C198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
L_8004C19C:
    // 0x8004C19C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8004C1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004C1A4: jal         0x800BB440
    // 0x8004C1A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_32;
    // 0x8004C1A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_32:
L_8004C1AC:
    // 0x8004C1AC: jal         0x8004BBB4
    // 0x8004C1B0: nop

    creategfxtask(rdram, ctx);
        goto after_33;
    // 0x8004C1B0: nop

    after_33:
    // 0x8004C1B4: lw          $t8, 0x0($s6)
    ctx->r24 = S32(MEM_W(ctx->r22, 0X0));
    // 0x8004C1B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004C1BC: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x8004C1C0: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x8004C1C4: b           L_8004BF78
    // 0x8004C1C8: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
        goto L_8004BF78;
    // 0x8004C1C8: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
    // 0x8004C1CC: nop

    // 0x8004C1D0: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8004C1D4: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004C1D8: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8004C1DC: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8004C1E0: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8004C1E4: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8004C1E8: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8004C1EC: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8004C1F0: jr          $ra
    // 0x8004C1F4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8004C1F4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80056400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056400: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80056404: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80056408: addiu       $v0, $v0, -0x27E0
    ctx->r2 = ADD32(ctx->r2, -0X27E0);
    // 0x8005640C: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056410: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80056414: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80056418: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8005641C: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80056420: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80056424: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80056428: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8005642C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80056430: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80056434: bne         $t6, $zero, L_80056448
    if (ctx->r14 != 0) {
        // 0x80056438: sw          $s0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r16;
            goto L_80056448;
    }
    // 0x80056438: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8005643C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80056440: addiu       $a2, $a2, 0x4858
    ctx->r6 = ADD32(ctx->r6, 0X4858);
    // 0x80056444: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_80056448:
    // 0x80056448: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8005644C: lw          $t7, -0x13F8($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X13F8));
    // 0x80056450: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80056454: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x80056458: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005645C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80056460: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80056464: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80056468: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005646C: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80056470: lbu         $a1, 0x25($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X25);
    // 0x80056474: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80056478: addiu       $a2, $a2, 0x4858
    ctx->r6 = ADD32(ctx->r6, 0X4858);
    // 0x8005647C: bne         $a1, $zero, L_80056490
    if (ctx->r5 != 0) {
        // 0x80056480: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_80056490;
    }
    // 0x80056480: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80056484: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80056488: sb          $t6, 0x25($a3)
    MEM_B(0X25, ctx->r7) = ctx->r14;
    // 0x8005648C: andi        $a1, $t6, 0xFF
    ctx->r5 = ctx->r14 & 0XFF;
L_80056490:
    // 0x80056490: addiu       $v1, $v1, -0x27DA
    ctx->r3 = ADD32(ctx->r3, -0X27DA);
    // 0x80056494: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80056498: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8005649C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x800564A0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800564A4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800564A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800564AC: addiu       $t0, $t0, -0x27D0
    ctx->r8 = ADD32(ctx->r8, -0X27D0);
    // 0x800564B0: addiu       $a0, $a0, -0x27DC
    ctx->r4 = ADD32(ctx->r4, -0X27DC);
    // 0x800564B4: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x800564B8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = S32(MEM_W(ctx->r8, 0X0));
    // 0x800564BC: bgez        $t7, L_800564D4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800564C0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800564D4;
    }
    // 0x800564C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800564C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800564C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800564CC: nop

    // 0x800564D0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800564D4:
    // 0x800564D4: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800564D8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800564DC: lui         $ra, 0x800D
    ctx->r31 = S32(0X800D << 16);
    // 0x800564E0: lui         $fp, 0x800D
    ctx->r30 = S32(0X800D << 16);
    // 0x800564E4: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x800564E8: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = S32(MEM_W(ctx->r8, 0X0));
    // 0x800564EC: addiu       $a1, $a1, -0x27D8
    ctx->r5 = ADD32(ctx->r5, -0X27D8);
    // 0x800564F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800564F4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800564F8: addiu       $fp, $fp, 0x486C
    ctx->r30 = ADD32(ctx->r30, 0X486C);
    // 0x800564FC: addiu       $ra, $ra, 0x4880
    ctx->r31 = ADD32(ctx->r31, 0X4880);
    // 0x80056500: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80056504: bc1f        L_80056644
    if (!c1cs) {
        // 0x80056508: addiu       $s6, $zero, 0xA
        ctx->r22 = ADD32(0, 0XA);
            goto L_80056644;
    }
    // 0x80056508: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x8005650C: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80056510: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056514: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80056518: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x8005651C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80056520: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x80056524: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80056528: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x8005652C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80056530: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80056534: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x80056538: addiu       $t3, $t3, -0x27DB
    ctx->r11 = ADD32(ctx->r11, -0X27DB);
    // 0x8005653C: addiu       $t4, $t4, 0x4868
    ctx->r12 = ADD32(ctx->r12, 0X4868);
    // 0x80056540: addiu       $s0, $s0, 0x4864
    ctx->r16 = ADD32(ctx->r16, 0X4864);
    // 0x80056544: addiu       $s2, $s2, 0x4870
    ctx->r18 = ADD32(ctx->r18, 0X4870);
    // 0x80056548: addiu       $s5, $s5, 0x4878
    ctx->r21 = ADD32(ctx->r21, 0X4878);
    // 0x8005654C: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80056550: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x80056554: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80056558: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8005655C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80056560: sw          $t6, -0x27D4($at)
    MEM_W(-0X27D4, ctx->r1) = ctx->r14;
L_80056564:
    // 0x80056564: lw          $t7, 0x0($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056568: lb          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_B(ctx->r15, 0X0));
    // 0x8005656C: addiu       $t6, $t8, 0x5
    ctx->r14 = ADD32(ctx->r24, 0X5);
    // 0x80056570: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x80056574: beq         $at, $zero, L_8005663C
    if (ctx->r1 == 0) {
        // 0x80056578: sw          $t8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r24;
            goto L_8005663C;
    }
    // 0x80056578: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8005657C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80056580: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80056584: addu        $at, $at, $t6
    gpr jr_addend_8005658C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80056588: lw          $t6, 0x45B0($at)
    ctx->r14 = ADD32(ctx->r1, 0X45B0);
    // 0x8005658C: jr          $t6
    // 0x80056590: nop

    switch (jr_addend_8005658C >> 2) {
        case 0: goto L_800565AC; break;
        case 1: goto L_8005663C; break;
        case 2: goto L_800565A4; break;
        case 3: goto L_8005659C; break;
        case 4: goto L_80056594; break;
        case 5: goto L_8005663C; break;
        case 6: goto L_8005663C; break;
        case 7: goto L_8005663C; break;
        case 8: goto L_8005663C; break;
        case 9: goto L_8005663C; break;
        case 10: goto L_8005663C; break;
        case 11: goto L_800565B4; break;
        case 12: goto L_800565D0; break;
        case 13: goto L_8005663C; break;
        case 14: goto L_80056604; break;
        case 15: goto L_80056620; break;
        default: switch_error(__func__, 0x8005658C, 0x801045B0);
    }
    // 0x80056590: nop

L_80056594:
    // 0x80056594: b           L_80056564
    // 0x80056598: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_80056564;
    // 0x80056598: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_8005659C:
    // 0x8005659C: b           L_80056564
    // 0x800565A0: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
        goto L_80056564;
    // 0x800565A0: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
L_800565A4:
    // 0x800565A4: b           L_80056564
    // 0x800565A8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
        goto L_80056564;
    // 0x800565A8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
L_800565AC:
    // 0x800565AC: b           L_80056564
    // 0x800565B0: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
        goto L_80056564;
    // 0x800565B0: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
L_800565B4:
    // 0x800565B4: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800565B8: bne         $s7, $t0, L_8005663C
    if (ctx->r23 != ctx->r8) {
        // 0x800565BC: nop
    
            goto L_8005663C;
    }
    // 0x800565BC: nop

    // 0x800565C0: sb          $t0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r8;
    // 0x800565C4: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x800565C8: b           L_80056564
    // 0x800565CC: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
        goto L_80056564;
    // 0x800565CC: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_800565D0:
    // 0x800565D0: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800565D4: bne         $s1, $t0, L_800565EC
    if (ctx->r17 != ctx->r8) {
        // 0x800565D8: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_800565EC;
    }
    // 0x800565D8: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800565DC: sb          $t0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r8;
    // 0x800565E0: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x800565E4: b           L_80056564
    // 0x800565E8: sb          $s3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r19;
        goto L_80056564;
    // 0x800565E8: sb          $s3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r19;
L_800565EC:
    // 0x800565EC: bne         $s4, $t1, L_8005663C
    if (ctx->r20 != ctx->r9) {
        // 0x800565F0: nop
    
            goto L_8005663C;
    }
    // 0x800565F0: nop

    // 0x800565F4: sb          $t0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r8;
    // 0x800565F8: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x800565FC: b           L_80056564
    // 0x80056600: sb          $s6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r22;
        goto L_80056564;
    // 0x80056600: sb          $s6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r22;
L_80056604:
    // 0x80056604: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x80056608: bne         $t2, $t0, L_8005663C
    if (ctx->r10 != ctx->r8) {
        // 0x8005660C: nop
    
            goto L_8005663C;
    }
    // 0x8005660C: nop

    // 0x80056610: sb          $t0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r8;
    // 0x80056614: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80056618: b           L_80056564
    // 0x8005661C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
        goto L_80056564;
    // 0x8005661C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_80056620:
    // 0x80056620: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x80056624: bne         $t2, $t0, L_8005663C
    if (ctx->r10 != ctx->r8) {
        // 0x80056628: nop
    
            goto L_8005663C;
    }
    // 0x80056628: nop

    // 0x8005662C: sb          $t0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r8;
    // 0x80056630: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80056634: b           L_80056564
    // 0x80056638: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
        goto L_80056564;
    // 0x80056638: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_8005663C:
    // 0x8005663C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80056640: lwc1        $f0, -0x27D0($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X27D0));
L_80056644:
    // 0x80056644: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x80056648: addiu       $t3, $t3, -0x27DB
    ctx->r11 = ADD32(ctx->r11, -0X27DB);
    // 0x8005664C: lbu         $t7, 0x0($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X0);
    // 0x80056650: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x80056654: div.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80056658: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005665C: bne         $t7, $t1, L_80056668
    if (ctx->r15 != ctx->r9) {
        // 0x80056660: addiu       $t8, $t1, 0x4
        ctx->r24 = ADD32(ctx->r9, 0X4);
            goto L_80056668;
    }
    // 0x80056660: addiu       $t8, $t1, 0x4
    ctx->r24 = ADD32(ctx->r9, 0X4);
    // 0x80056664: sb          $t8, 0x25($a3)
    MEM_B(0X25, ctx->r7) = ctx->r24;
L_80056668:
    // 0x80056668: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8005666C: lw          $s0, 0x8($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X8));
    // 0x80056670: lw          $s1, 0xC($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XC));
    // 0x80056674: lw          $s2, 0x10($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X10));
    // 0x80056678: lw          $s3, 0x14($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8005667C: lw          $s4, 0x18($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80056680: lw          $s5, 0x1C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80056684: lw          $s6, 0x20($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80056688: lw          $s7, 0x24($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8005668C: lw          $fp, 0x28($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80056690: swc1        $f6, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->f6.u32l;
    // 0x80056694: jr          $ra
    // 0x80056698: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80056698: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void addexplosionmodel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064960: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80064964: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80064968: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006496C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80064970: lh          $t6, -0x9DC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X9DC));
    // 0x80064974: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80064978: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8006497C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80064980: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x80064984: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80064988: andi        $t5, $a3, 0xFF
    ctx->r13 = ctx->r7 & 0XFF;
    // 0x8006498C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80064990: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x80064994: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80064998: bne         $t0, $t6, L_80064A4C
    if (ctx->r8 != ctx->r14) {
        // 0x8006499C: sra         $a1, $t8, 16
        ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80064A4C;
    }
    // 0x8006499C: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800649A0: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x800649A4: addiu       $t1, $t1, -0x28F8
    ctx->r9 = ADD32(ctx->r9, -0X28F8);
    // 0x800649A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800649AC: addiu       $t2, $zero, 0x16
    ctx->r10 = ADD32(0, 0X16);
L_800649B0:
    // 0x800649B0: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800649B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800649B8: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800649BC: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800649C0: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800649C4: mflo        $t7
    ctx->r15 = lo;
    // 0x800649C8: addu        $v1, $t1, $t7
    ctx->r3 = ADD32(ctx->r9, ctx->r15);
    // 0x800649CC: lb          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_B(ctx->r3, 0X0));
    // 0x800649D0: beq         $t8, $zero, L_800649E8
    if (ctx->r24 == 0) {
        // 0x800649D4: nop
    
            goto L_800649E8;
    }
    // 0x800649D4: nop

    // 0x800649D8: bne         $at, $zero, L_800649B0
    if (ctx->r1 != 0) {
        // 0x800649DC: nop
    
            goto L_800649B0;
    }
    // 0x800649DC: nop

    // 0x800649E0: jr          $ra
    // 0x800649E4: nop

    return;
    // 0x800649E4: nop

L_800649E8:
    // 0x800649E8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800649EC: addiu       $t5, $t5, -0x5A18
    ctx->r13 = ADD32(ctx->r13, -0X5A18);
    // 0x800649F0: sll         $t4, $a3, 5
    ctx->r12 = S32(ctx->r7 << 5);
    // 0x800649F4: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800649F8: lh          $t6, 0x4($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X4));
    // 0x800649FC: lh          $t7, 0x14($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X14));
    // 0x80064A00: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x80064A04: sh          $t6, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r14;
    // 0x80064A08: lhu         $t9, 0x12($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X12);
    // 0x80064A0C: lh          $t3, 0x6($v0)
    ctx->r11 = S32(MEM_H(ctx->r2, 0X6));
    // 0x80064A10: lh          $t4, 0x16($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X16));
    // 0x80064A14: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80064A18: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x80064A1C: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
    // 0x80064A20: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x80064A24: sh          $a1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r5;
    // 0x80064A28: sh          $a2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r6;
    // 0x80064A2C: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80064A30: sh          $t7, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r15;
    // 0x80064A34: sh          $t8, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r24;
    // 0x80064A38: sh          $t9, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r25;
    // 0x80064A3C: sh          $t3, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r11;
    // 0x80064A40: sh          $t4, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r12;
    // 0x80064A44: sb          $t5, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r13;
    // 0x80064A48: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
L_80064A4C:
    // 0x80064A4C: jr          $ra
    // 0x80064A50: nop

    return;
    // 0x80064A50: nop

;}
RECOMP_FUNC void divscale15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009145C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091460: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091464: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091468: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x8009146C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091470: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091474: jal         0x800BB834
    // 0x80091478: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091478: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009147C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091480: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091484: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091488: jal         0x800BB89C
    // 0x8009148C: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x8009148C: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091490: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091498: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009149C: jr          $ra
    // 0x800914A0: nop

    return;
    // 0x800914A0: nop

;}
RECOMP_FUNC void func_80055374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80055378: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8005537C: lui         $t7, 0x4E44
    ctx->r15 = S32(0X4E44 << 16);
    // 0x80055380: addiu       $v0, $v0, -0x4220
    ctx->r2 = ADD32(ctx->r2, -0X4220);
    // 0x80055384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055388: addiu       $t6, $zero, 0x3458
    ctx->r14 = ADD32(0, 0X3458);
    // 0x8005538C: ori         $t7, $t7, 0x4E45
    ctx->r15 = ctx->r15 | 0X4E45;
    // 0x80055390: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80055394: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80055398: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005539C: addiu       $a0, $a0, -0x4212
    ctx->r4 = ADD32(ctx->r4, -0X4212);
    // 0x800553A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800553A4: jal         0x8005A548
    // 0x800553A8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    clearbufbyte(rdram, ctx);
        goto after_0;
    // 0x800553A8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x800553AC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800553B0: addiu       $a0, $a0, -0x4216
    ctx->r4 = ADD32(ctx->r4, -0X4216);
    // 0x800553B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800553B8: jal         0x8005A548
    // 0x800553BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    clearbufbyte(rdram, ctx);
        goto after_1;
    // 0x800553BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800553C0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800553C4: lh          $a2, 0x3750($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X3750));
    // 0x800553C8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800553CC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800553D0: addiu       $a1, $a1, 0x3E38
    ctx->r5 = ADD32(ctx->r5, 0X3E38);
    // 0x800553D4: addiu       $a0, $a0, -0x4212
    ctx->r4 = ADD32(ctx->r4, -0X4212);
    // 0x800553D8: jal         0x800BD9E4
    // 0x800553DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800553DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_2:
    // 0x800553E0: jal         0x800551F8
    // 0x800553E4: nop

    func_800551F8(rdram, ctx);
        goto after_3;
    // 0x800553E4: nop

    after_3:
    // 0x800553E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800553EC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800553F0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x800553F4: sb          $v0, -0x4216($at)
    MEM_B(-0X4216, ctx->r1) = ctx->r2;
    // 0x800553F8: addiu       $a3, $a3, -0x4210
    ctx->r7 = ADD32(ctx->r7, -0X4210);
    // 0x800553FC: addiu       $a2, $a2, -0x4220
    ctx->r6 = ADD32(ctx->r6, -0X4220);
    // 0x80055400: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
L_80055404:
    // 0x80055404: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80055408: addiu       $v1, $v1, 0x38D4
    ctx->r3 = ADD32(ctx->r3, 0X38D4);
    // 0x8005540C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80055410: lbu         $a0, 0xE($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XE);
L_80055414:
    // 0x80055414: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80055418: bnel        $a0, $t8, L_8005542C
    if (ctx->r4 != ctx->r24) {
        // 0x8005541C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8005542C;
    }
    goto skip_0;
    // 0x8005541C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80055420: b           L_80055434
    // 0x80055424: sb          $v0, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r2;
        goto L_80055434;
    // 0x80055424: sb          $v0, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r2;
    // 0x80055428: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8005542C:
    // 0x8005542C: bne         $v0, $a1, L_80055414
    if (ctx->r2 != ctx->r5) {
        // 0x80055430: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80055414;
    }
    // 0x80055430: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80055434:
    // 0x80055434: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80055438: bne         $a2, $a3, L_80055404
    if (ctx->r6 != ctx->r7) {
        // 0x8005543C: nop
    
            goto L_80055404;
    }
    // 0x8005543C: nop

    // 0x80055440: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80055444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80055448: jr          $ra
    // 0x8005544C: nop

    return;
    // 0x8005544C: nop

;}
RECOMP_FUNC void func_8006ADA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ADA4: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x8006ADA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006ADAC: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8006ADB0: lw          $s0, -0x13CC($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, -0X13CC));
    // 0x8006ADB4: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006ADB8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006ADBC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006ADC0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006ADC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006ADC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006ADCC: sw          $a0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r4;
    // 0x8006ADD0: sw          $a1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r5;
    // 0x8006ADD4: sw          $a2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r6;
    // 0x8006ADD8: sh          $zero, -0x1400($at)
    MEM_H(-0X1400, ctx->r1) = 0;
    // 0x8006ADDC: lbu         $t9, 0x25($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X25);
    // 0x8006ADE0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8006ADE4: sb          $t9, -0x298C($at)
    MEM_B(-0X298C, ctx->r1) = ctx->r25;
    // 0x8006ADE8: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006ADEC: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8006ADF0: lw          $a2, 0x8($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8006ADF4: bgez        $a0, L_8006AE04
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006ADF8: sra         $t8, $a0, 1
        ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8006AE04;
    }
    // 0x8006ADF8: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8006ADFC: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
    // 0x8006AE00: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8006AE04:
    // 0x8006AE04: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8006AE08: bgez        $a1, L_8006AE18
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8006AE0C: sra         $t6, $a1, 1
        ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8006AE18;
    }
    // 0x8006AE0C: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8006AE10: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8006AE14: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8006AE18:
    // 0x8006AE18: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8006AE1C: bgez        $a2, L_8006AE2C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006AE20: sra         $t7, $a2, 1
        ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
            goto L_8006AE2C;
    }
    // 0x8006AE20: sra         $t7, $a2, 1
    ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
    // 0x8006AE24: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x8006AE28: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8006AE2C:
    // 0x8006AE2C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8006AE30: jal         0x80062D98
    // 0x8006AE34: lb          $a3, 0x24($s0)
    ctx->r7 = S32(MEM_B(ctx->r16, 0X24));
    func_80062D98(rdram, ctx);
        goto after_0;
    // 0x8006AE34: lb          $a3, 0x24($s0)
    ctx->r7 = S32(MEM_B(ctx->r16, 0X24));
    after_0:
    // 0x8006AE38: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x8006AE3C: addiu       $t1, $t1, -0x139C
    ctx->r9 = ADD32(ctx->r9, -0X139C);
    // 0x8006AE40: lw          $t9, 0x0($t1)
    ctx->r25 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8006AE44: addiu       $t3, $zero, 0x1C
    ctx->r11 = ADD32(0, 0X1C);
    // 0x8006AE48: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8006AE4C: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AE50: lw          $s0, -0x13CC($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, -0X13CC));
    // 0x8006AE54: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006AE58: addiu       $t2, $t2, -0x5010
    ctx->r10 = ADD32(ctx->r10, -0X5010);
    // 0x8006AE5C: lbu         $v1, 0x27($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X27);
    // 0x8006AE60: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8006AE64: mflo        $t8
    ctx->r24 = lo;
    // 0x8006AE68: addu        $t0, $t2, $t8
    ctx->r8 = ADD32(ctx->r10, ctx->r24);
    // 0x8006AE6C: lh          $t6, 0xC($t0)
    ctx->r14 = S32(MEM_H(ctx->r8, 0XC));
    // 0x8006AE70: lh          $t8, 0xE($t0)
    ctx->r24 = S32(MEM_H(ctx->r8, 0XE));
    // 0x8006AE74: lw          $a1, 0x8($t0)
    ctx->r5 = S32(MEM_W(ctx->r8, 0X8));
    // 0x8006AE78: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AE7C: andi        $t5, $a1, 0xFF00
    ctx->r13 = ctx->r5 & 0XFF00;
    // 0x8006AE80: mflo        $t7
    ctx->r15 = lo;
    // 0x8006AE84: bgez        $t7, L_8006AE94
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006AE88: sra         $t9, $t7, 4
        ctx->r25 = S32(SIGNED(ctx->r15) >> 4);
            goto L_8006AE94;
    }
    // 0x8006AE88: sra         $t9, $t7, 4
    ctx->r25 = S32(SIGNED(ctx->r15) >> 4);
    // 0x8006AE8C: addiu       $at, $t7, 0xF
    ctx->r1 = ADD32(ctx->r15, 0XF);
    // 0x8006AE90: sra         $t9, $at, 4
    ctx->r25 = S32(SIGNED(ctx->r1) >> 4);
L_8006AE94:
    // 0x8006AE94: sh          $t9, 0x10E($sp)
    MEM_H(0X10E, ctx->r29) = ctx->r25;
    // 0x8006AE98: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    // 0x8006AE9C: lb          $t7, 0x29($s0)
    ctx->r15 = S32(MEM_B(ctx->r16, 0X29));
    // 0x8006AEA0: sra         $t9, $t5, 8
    ctx->r25 = S32(SIGNED(ctx->r13) >> 8);
    // 0x8006AEA4: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AEA8: sll         $t8, $t9, 24
    ctx->r24 = S32(ctx->r25 << 24);
    // 0x8006AEAC: lh          $a3, 0xC($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0XC));
    // 0x8006AEB0: mflo        $a2
    ctx->r6 = lo;
    // 0x8006AEB4: bgez        $a2, L_8006AEC4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006AEB8: sra         $t6, $a2, 3
        ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
            goto L_8006AEC4;
    }
    // 0x8006AEB8: sra         $t6, $a2, 3
    ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8006AEBC: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x8006AEC0: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8006AEC4:
    // 0x8006AEC4: andi        $a2, $t6, 0xFFFF
    ctx->r6 = ctx->r14 & 0XFFFF;
    // 0x8006AEC8: sra         $t6, $t8, 24
    ctx->r14 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006AECC: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x8006AED0: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AED4: andi        $t8, $a3, 0x80
    ctx->r24 = ctx->r7 & 0X80;
    // 0x8006AED8: mflo        $t5
    ctx->r13 = lo;
    // 0x8006AEDC: bgez        $t5, L_8006AEEC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8006AEE0: sra         $t9, $t5, 3
        ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
            goto L_8006AEEC;
    }
    // 0x8006AEE0: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8006AEE4: addiu       $at, $t5, 0x7
    ctx->r1 = ADD32(ctx->r13, 0X7);
    // 0x8006AEE8: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8006AEEC:
    // 0x8006AEEC: bne         $t4, $t8, L_8006AF3C
    if (ctx->r12 != ctx->r24) {
        // 0x8006AEF0: or          $t5, $t9, $zero
        ctx->r13 = ctx->r25 | 0;
            goto L_8006AF3C;
    }
    // 0x8006AEF0: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8006AEF4: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8006AEF8: bgez        $a2, L_8006AF08
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8006AEFC: sra         $t7, $a2, 1
        ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
            goto L_8006AF08;
    }
    // 0x8006AEFC: sra         $t7, $a2, 1
    ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
    // 0x8006AF00: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x8006AF04: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8006AF08:
    // 0x8006AF08: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x8006AF0C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8006AF10: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8006AF14: lw          $t7, 0x0($t1)
    ctx->r15 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8006AF18: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8006AF1C: lw          $s0, -0x13CC($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, -0X13CC));
    // 0x8006AF20: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x8006AF24: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8006AF28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006AF2C: addu        $t9, $t2, $t6
    ctx->r25 = ADD32(ctx->r10, ctx->r14);
    // 0x8006AF30: lw          $a1, 0x8($t9)
    ctx->r5 = S32(MEM_W(ctx->r25, 0X8));
    // 0x8006AF34: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    // 0x8006AF38: lh          $a3, 0xC($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0XC));
L_8006AF3C:
    // 0x8006AF3C: andi        $t8, $a3, 0x8
    ctx->r24 = ctx->r7 & 0X8;
    // 0x8006AF40: beq         $t8, $zero, L_8006AF80
    if (ctx->r24 == 0) {
        // 0x8006AF44: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8006AF80;
    }
    // 0x8006AF44: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8006AF48: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8006AF4C: and         $v0, $a1, $at
    ctx->r2 = ctx->r5 & ctx->r1;
    // 0x8006AF50: lb          $t8, 0x2A($s0)
    ctx->r24 = S32(MEM_B(ctx->r16, 0X2A));
    // 0x8006AF54: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006AF58: sll         $t6, $t7, 24
    ctx->r14 = S32(ctx->r15 << 24);
    // 0x8006AF5C: sra         $t9, $t6, 24
    ctx->r25 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006AF60: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x8006AF64: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AF68: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8006AF6C: mflo        $v0
    ctx->r2 = lo;
    // 0x8006AF70: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006AF74: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x8006AF78: b           L_8006AFB4
    // 0x8006AF7C: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
        goto L_8006AFB4;
    // 0x8006AF7C: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
L_8006AF80:
    // 0x8006AF80: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8006AF84: and         $v0, $a1, $at
    ctx->r2 = ctx->r5 & ctx->r1;
    // 0x8006AF88: lb          $t9, 0x2A($s0)
    ctx->r25 = S32(MEM_B(ctx->r16, 0X2A));
    // 0x8006AF8C: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006AF90: sll         $t7, $t8, 24
    ctx->r15 = S32(ctx->r24 << 24);
    // 0x8006AF94: sra         $t6, $t7, 24
    ctx->r14 = S32(SIGNED(ctx->r15) >> 24);
    // 0x8006AF98: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x8006AF9C: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AFA0: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8006AFA4: mflo        $v0
    ctx->r2 = lo;
    // 0x8006AFA8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8006AFAC: subu        $t6, $t7, $t8
    ctx->r14 = SUB32(ctx->r15, ctx->r24);
    // 0x8006AFB0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
L_8006AFB4:
    // 0x8006AFB4: lw          $t9, 0x0($t1)
    ctx->r25 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8006AFB8: lui         $s2, 0x8027
    ctx->r18 = S32(0X8027 << 16);
    // 0x8006AFBC: lw          $s2, -0x13E4($s2)
    ctx->r18 = S32(MEM_W(ctx->r18, -0X13E4));
    // 0x8006AFC0: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AFC4: sw          $t5, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r13;
    // 0x8006AFC8: mflo        $t8
    ctx->r24 = lo;
    // 0x8006AFCC: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x8006AFD0: lbu         $t6, 0x16($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X16);
    // 0x8006AFD4: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x8006AFD8: andi        $t9, $t6, 0x80
    ctx->r25 = ctx->r14 & 0X80;
    // 0x8006AFDC: beq         $t4, $t9, L_8006B0B4
    if (ctx->r12 == ctx->r25) {
        // 0x8006AFE0: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_8006B0B4;
    }
    // 0x8006AFE0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8006AFE4: addiu       $t4, $t4, 0x4418
    ctx->r12 = ADD32(ctx->r12, 0X4418);
    // 0x8006AFE8: lw          $s0, 0x0($t4)
    ctx->r16 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006AFEC: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8006AFF0: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x8006AFF4: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8006AFF8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006AFFC: jal         0x80063880
    // 0x8006B000: lhu         $a0, 0x2($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X2);
    func_80063880(rdram, ctx);
        goto after_1;
    // 0x8006B000: lhu         $a0, 0x2($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X2);
    after_1:
    // 0x8006B004: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8006B008: addiu       $t4, $t4, 0x4418
    ctx->r12 = ADD32(ctx->r12, 0X4418);
    // 0x8006B00C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8006B010: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B014: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8006B018: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8006B01C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006B020: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006B024: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006B028: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006B02C: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B030: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8006B034: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8006B038: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006B03C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8006B040: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006B044: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006B048: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B04C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8006B050: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8006B054: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006B058: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006B05C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006B060: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006B064: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B068: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x8006B06C: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8006B070: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006B074: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006B078: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8006B07C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006B080: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B084: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8006B088: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8006B08C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006B090: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8006B094: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006B098: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006B09C: jal         0x80063880
    // 0x8006B0A0: lhu         $a0, -0x139A($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X139A);
    func_80063880(rdram, ctx);
        goto after_2;
    // 0x8006B0A0: lhu         $a0, -0x139A($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X139A);
    after_2:
    // 0x8006B0A4: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8006B0A8: addiu       $t4, $t4, 0x4418
    ctx->r12 = ADD32(ctx->r12, 0X4418);
    // 0x8006B0AC: b           L_8006B178
    // 0x8006B0B0: addiu       $s1, $v0, 0x20
    ctx->r17 = ADD32(ctx->r2, 0X20);
        goto L_8006B178;
    // 0x8006B0B0: addiu       $s1, $v0, 0x20
    ctx->r17 = ADD32(ctx->r2, 0X20);
L_8006B0B4:
    // 0x8006B0B4: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8006B0B8: addiu       $t4, $t4, 0x4418
    ctx->r12 = ADD32(ctx->r12, 0X4418);
    // 0x8006B0BC: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B0C0: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8006B0C4: addiu       $t8, $t8, 0x8
    ctx->r24 = ADD32(ctx->r24, 0X8);
    // 0x8006B0C8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006B0CC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006B0D0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006B0D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006B0D8: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B0DC: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8006B0E0: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8006B0E4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006B0E8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006B0EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006B0F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006B0F4: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B0F8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8006B0FC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8006B100: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006B104: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006B108: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006B10C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006B110: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B114: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8006B118: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8006B11C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006B120: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006B124: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006B128: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006B12C: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B130: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8006B134: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8006B138: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006B13C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8006B140: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006B144: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006B148: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B14C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8006B150: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8006B154: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006B158: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006B15C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006B160: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006B164: jal         0x80063880
    // 0x8006B168: lhu         $a0, -0x139A($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X139A);
    func_80063880(rdram, ctx);
        goto after_3;
    // 0x8006B168: lhu         $a0, -0x139A($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X139A);
    after_3:
    // 0x8006B16C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8006B170: addiu       $t4, $t4, 0x4418
    ctx->r12 = ADD32(ctx->r12, 0X4418);
    // 0x8006B174: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8006B178:
    // 0x8006B178: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8006B17C: lw          $s0, -0x13CC($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, -0X13CC));
    // 0x8006B180: lw          $t6, 0x38($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8006B184: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8006B188: lw          $v0, 0x8($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8006B18C: lh          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0XC));
    // 0x8006B190: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006B194: sra         $t7, $v0, 5
    ctx->r15 = S32(SIGNED(ctx->r2) >> 5);
    // 0x8006B198: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8006B19C: subu        $s4, $t9, $t7
    ctx->r20 = SUB32(ctx->r25, ctx->r15);
    // 0x8006B1A0: subu        $s3, $t7, $t6
    ctx->r19 = SUB32(ctx->r15, ctx->r14);
    // 0x8006B1A4: andi        $t7, $t8, 0x4
    ctx->r15 = ctx->r24 & 0X4;
    // 0x8006B1A8: blez        $t7, L_8006B1E0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006B1AC: nop
    
            goto L_8006B1E0;
    }
    // 0x8006B1AC: nop

    // 0x8006B1B0: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8006B1B4: lw          $a0, -0x139C($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X139C));
    // 0x8006B1B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006B1BC: addiu       $t9, $t9, -0x5010
    ctx->r25 = ADD32(ctx->r25, -0X5010);
    // 0x8006B1C0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8006B1C4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8006B1C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006B1CC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8006B1D0: lhu         $t8, 0x12($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X12);
    // 0x8006B1D4: sh          $zero, 0xF0($sp)
    MEM_H(0XF0, ctx->r29) = 0;
    // 0x8006B1D8: b           L_8006B208
    // 0x8006B1DC: sh          $t8, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r24;
        goto L_8006B208;
    // 0x8006B1DC: sh          $t8, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r24;
L_8006B1E0:
    // 0x8006B1E0: lw          $a0, -0x139C($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X139C));
    // 0x8006B1E4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006B1E8: addiu       $t6, $t6, -0x5010
    ctx->r14 = ADD32(ctx->r14, -0X5010);
    // 0x8006B1EC: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8006B1F0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8006B1F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006B1F8: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8006B1FC: lhu         $t9, 0x12($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X12);
    // 0x8006B200: sh          $zero, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = 0;
    // 0x8006B204: sh          $t9, 0xF0($sp)
    MEM_H(0XF0, ctx->r29) = ctx->r25;
L_8006B208:
    // 0x8006B208: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8006B20C: sb          $t8, -0x1398($at)
    MEM_B(-0X1398, ctx->r1) = ctx->r24;
    // 0x8006B210: lh          $a3, 0xC($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0XC));
    // 0x8006B214: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006B218: addiu       $t6, $zero, 0xC0
    ctx->r14 = ADD32(0, 0XC0);
    // 0x8006B21C: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x8006B220: bne         $t7, $at, L_8006B234
    if (ctx->r15 != ctx->r1) {
        // 0x8006B224: addiu       $t8, $zero, 0x80
        ctx->r24 = ADD32(0, 0X80);
            goto L_8006B234;
    }
    // 0x8006B224: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8006B228: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006B22C: sb          $t6, -0x1398($at)
    MEM_B(-0X1398, ctx->r1) = ctx->r14;
    // 0x8006B230: lh          $a3, 0xC($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0XC));
L_8006B234:
    // 0x8006B234: andi        $t9, $a3, 0x200
    ctx->r25 = ctx->r7 & 0X200;
    // 0x8006B238: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8006B23C: bne         $t9, $at, L_8006B24C
    if (ctx->r25 != ctx->r1) {
        // 0x8006B240: lui         $at, 0x8027
        ctx->r1 = S32(0X8027 << 16);
            goto L_8006B24C;
    }
    // 0x8006B240: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006B244: sb          $t8, -0x1398($at)
    MEM_B(-0X1398, ctx->r1) = ctx->r24;
    // 0x8006B248: lh          $a3, 0xC($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0XC));
L_8006B24C:
    // 0x8006B24C: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006B250: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8006B254: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006B258: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8006B25C: andi        $a1, $a3, 0x30
    ctx->r5 = ctx->r7 & 0X30;
    // 0x8006B260: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006B264: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8006B268: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8006B26C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8006B270: nop

    // 0x8006B274: sh          $v0, 0x106($sp)
    MEM_H(0X106, ctx->r29) = ctx->r2;
    // 0x8006B278: sh          $v0, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r2;
    // 0x8006B27C: sh          $v0, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r2;
    // 0x8006B280: lw          $t7, 0x4($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8006B284: sh          $v0, 0x104($sp)
    MEM_H(0X104, ctx->r29) = ctx->r2;
    // 0x8006B288: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8006B28C: nop

    // 0x8006B290: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006B294: div.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006B298: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006B29C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8006B2A0: nop

    // 0x8006B2A4: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8006B2A8: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006B2AC: sh          $v1, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r3;
    // 0x8006B2B0: sh          $v1, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r3;
    // 0x8006B2B4: sh          $v1, 0x102($sp)
    MEM_H(0X102, ctx->r29) = ctx->r3;
    // 0x8006B2B8: bne         $a1, $zero, L_8006B580
    if (ctx->r5 != 0) {
        // 0x8006B2BC: sh          $v1, 0xFC($sp)
        MEM_H(0XFC, ctx->r29) = ctx->r3;
            goto L_8006B580;
    }
    // 0x8006B2BC: sh          $v1, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = ctx->r3;
    // 0x8006B2C0: lw          $t7, 0x148($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X148));
    // 0x8006B2C4: lui         $t1, 0x8024
    ctx->r9 = S32(0X8024 << 16);
    // 0x8006B2C8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8006B2CC: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8006B2D0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006B2D4: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8006B2D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006B2DC: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8006B2E0: lh          $t1, 0x6BB6($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, 0X6BB6));
    // 0x8006B2E4: slti        $at, $t1, 0x8E0
    ctx->r1 = SIGNED(ctx->r9) < 0X8E0 ? 1 : 0;
    // 0x8006B2E8: bne         $at, $zero, L_8006B35C
    if (ctx->r1 != 0) {
        // 0x8006B2EC: slti        $at, $t1, 0x111A
        ctx->r1 = SIGNED(ctx->r9) < 0X111A ? 1 : 0;
            goto L_8006B35C;
    }
    // 0x8006B2EC: slti        $at, $t1, 0x111A
    ctx->r1 = SIGNED(ctx->r9) < 0X111A ? 1 : 0;
    // 0x8006B2F0: bne         $at, $zero, L_8006B328
    if (ctx->r1 != 0) {
        // 0x8006B2F4: addiu       $at, $zero, 0x11C6
        ctx->r1 = ADD32(0, 0X11C6);
            goto L_8006B328;
    }
    // 0x8006B2F4: addiu       $at, $zero, 0x11C6
    ctx->r1 = ADD32(0, 0X11C6);
    // 0x8006B2F8: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B2FC: addiu       $at, $zero, 0x11E7
        ctx->r1 = ADD32(0, 0X11E7);
            goto L_8006B4B0;
    }
    // 0x8006B2FC: addiu       $at, $zero, 0x11E7
    ctx->r1 = ADD32(0, 0X11E7);
    // 0x8006B300: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B304: addiu       $at, $zero, 0x11EA
        ctx->r1 = ADD32(0, 0X11EA);
            goto L_8006B4B0;
    }
    // 0x8006B304: addiu       $at, $zero, 0x11EA
    ctx->r1 = ADD32(0, 0X11EA);
    // 0x8006B308: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B30C: addiu       $at, $zero, 0x11EB
        ctx->r1 = ADD32(0, 0X11EB);
            goto L_8006B4B0;
    }
    // 0x8006B30C: addiu       $at, $zero, 0x11EB
    ctx->r1 = ADD32(0, 0X11EB);
    // 0x8006B310: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B314: addiu       $at, $zero, 0x131A
        ctx->r1 = ADD32(0, 0X131A);
            goto L_8006B4B0;
    }
    // 0x8006B314: addiu       $at, $zero, 0x131A
    ctx->r1 = ADD32(0, 0X131A);
    // 0x8006B318: beql        $t1, $at, L_8006B4B4
    if (ctx->r9 == ctx->r1) {
        // 0x8006B31C: lhu         $t8, 0x10E($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X10E);
            goto L_8006B4B4;
    }
    goto skip_0;
    // 0x8006B31C: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
    skip_0:
    // 0x8006B320: b           L_8006B42C
    // 0x8006B324: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
        goto L_8006B42C;
    // 0x8006B324: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
L_8006B328:
    // 0x8006B328: addiu       $at, $zero, 0x8FC
    ctx->r1 = ADD32(0, 0X8FC);
    // 0x8006B32C: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B330: addiu       $at, $zero, 0x905
        ctx->r1 = ADD32(0, 0X905);
            goto L_8006B4B0;
    }
    // 0x8006B330: addiu       $at, $zero, 0x905
    ctx->r1 = ADD32(0, 0X905);
    // 0x8006B334: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B338: addiu       $at, $zero, 0x907
        ctx->r1 = ADD32(0, 0X907);
            goto L_8006B4B0;
    }
    // 0x8006B338: addiu       $at, $zero, 0x907
    ctx->r1 = ADD32(0, 0X907);
    // 0x8006B33C: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B340: addiu       $at, $zero, 0xD65
        ctx->r1 = ADD32(0, 0XD65);
            goto L_8006B4B0;
    }
    // 0x8006B340: addiu       $at, $zero, 0xD65
    ctx->r1 = ADD32(0, 0XD65);
    // 0x8006B344: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B348: addiu       $at, $zero, 0x1119
        ctx->r1 = ADD32(0, 0X1119);
            goto L_8006B4B0;
    }
    // 0x8006B348: addiu       $at, $zero, 0x1119
    ctx->r1 = ADD32(0, 0X1119);
    // 0x8006B34C: beql        $t1, $at, L_8006B4B4
    if (ctx->r9 == ctx->r1) {
        // 0x8006B350: lhu         $t8, 0x10E($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X10E);
            goto L_8006B4B4;
    }
    goto skip_1;
    // 0x8006B350: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
    skip_1:
    // 0x8006B354: b           L_8006B42C
    // 0x8006B358: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
        goto L_8006B42C;
    // 0x8006B358: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
L_8006B35C:
    // 0x8006B35C: slti        $at, $t1, 0x3EE
    ctx->r1 = SIGNED(ctx->r9) < 0X3EE ? 1 : 0;
    // 0x8006B360: bne         $at, $zero, L_8006B398
    if (ctx->r1 != 0) {
        // 0x8006B364: addiu       $at, $zero, 0x444
        ctx->r1 = ADD32(0, 0X444);
            goto L_8006B398;
    }
    // 0x8006B364: addiu       $at, $zero, 0x444
    ctx->r1 = ADD32(0, 0X444);
    // 0x8006B368: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B36C: addiu       $at, $zero, 0x4C5
        ctx->r1 = ADD32(0, 0X4C5);
            goto L_8006B4B0;
    }
    // 0x8006B36C: addiu       $at, $zero, 0x4C5
    ctx->r1 = ADD32(0, 0X4C5);
    // 0x8006B370: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B374: addiu       $at, $zero, 0x4C9
        ctx->r1 = ADD32(0, 0X4C9);
            goto L_8006B4B0;
    }
    // 0x8006B374: addiu       $at, $zero, 0x4C9
    ctx->r1 = ADD32(0, 0X4C9);
    // 0x8006B378: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B37C: addiu       $at, $zero, 0x4EC
        ctx->r1 = ADD32(0, 0X4EC);
            goto L_8006B4B0;
    }
    // 0x8006B37C: addiu       $at, $zero, 0x4EC
    ctx->r1 = ADD32(0, 0X4EC);
    // 0x8006B380: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B384: addiu       $at, $zero, 0x8DF
        ctx->r1 = ADD32(0, 0X8DF);
            goto L_8006B4B0;
    }
    // 0x8006B384: addiu       $at, $zero, 0x8DF
    ctx->r1 = ADD32(0, 0X8DF);
    // 0x8006B388: beql        $t1, $at, L_8006B4B4
    if (ctx->r9 == ctx->r1) {
        // 0x8006B38C: lhu         $t8, 0x10E($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X10E);
            goto L_8006B4B4;
    }
    goto skip_2;
    // 0x8006B38C: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
    skip_2:
    // 0x8006B390: b           L_8006B42C
    // 0x8006B394: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
        goto L_8006B42C;
    // 0x8006B394: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
L_8006B398:
    // 0x8006B398: slti        $at, $t1, 0x221
    ctx->r1 = SIGNED(ctx->r9) < 0X221 ? 1 : 0;
    // 0x8006B39C: bne         $at, $zero, L_8006B40C
    if (ctx->r1 != 0) {
        // 0x8006B3A0: slti        $at, $t1, 0x2BD
        ctx->r1 = SIGNED(ctx->r9) < 0X2BD ? 1 : 0;
            goto L_8006B40C;
    }
    // 0x8006B3A0: slti        $at, $t1, 0x2BD
    ctx->r1 = SIGNED(ctx->r9) < 0X2BD ? 1 : 0;
    // 0x8006B3A4: bne         $at, $zero, L_8006B3CC
    if (ctx->r1 != 0) {
        // 0x8006B3A8: addiu       $t9, $t1, -0x38C
        ctx->r25 = ADD32(ctx->r9, -0X38C);
            goto L_8006B3CC;
    }
    // 0x8006B3A8: addiu       $t9, $t1, -0x38C
    ctx->r25 = ADD32(ctx->r9, -0X38C);
    // 0x8006B3AC: sltiu       $at, $t9, 0x62
    ctx->r1 = ctx->r25 < 0X62 ? 1 : 0;
    // 0x8006B3B0: beq         $at, $zero, L_8006B428
    if (ctx->r1 == 0) {
        // 0x8006B3B4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8006B428;
    }
    // 0x8006B3B4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006B3B8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006B3BC: addu        $at, $at, $t9
    gpr jr_addend_8006B3C4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8006B3C0: lw          $t9, 0x4E80($at)
    ctx->r25 = ADD32(ctx->r1, 0X4E80);
    // 0x8006B3C4: jr          $t9
    // 0x8006B3C8: nop

    switch (jr_addend_8006B3C4 >> 2) {
        case 0: goto L_8006B4B0; break;
        case 1: goto L_8006B4B0; break;
        case 2: goto L_8006B4B0; break;
        case 3: goto L_8006B428; break;
        case 4: goto L_8006B428; break;
        case 5: goto L_8006B428; break;
        case 6: goto L_8006B428; break;
        case 7: goto L_8006B428; break;
        case 8: goto L_8006B428; break;
        case 9: goto L_8006B428; break;
        case 10: goto L_8006B428; break;
        case 11: goto L_8006B428; break;
        case 12: goto L_8006B4B0; break;
        case 13: goto L_8006B4B0; break;
        case 14: goto L_8006B428; break;
        case 15: goto L_8006B428; break;
        case 16: goto L_8006B428; break;
        case 17: goto L_8006B428; break;
        case 18: goto L_8006B428; break;
        case 19: goto L_8006B428; break;
        case 20: goto L_8006B428; break;
        case 21: goto L_8006B428; break;
        case 22: goto L_8006B428; break;
        case 23: goto L_8006B428; break;
        case 24: goto L_8006B428; break;
        case 25: goto L_8006B428; break;
        case 26: goto L_8006B428; break;
        case 27: goto L_8006B428; break;
        case 28: goto L_8006B428; break;
        case 29: goto L_8006B428; break;
        case 30: goto L_8006B428; break;
        case 31: goto L_8006B428; break;
        case 32: goto L_8006B4B0; break;
        case 33: goto L_8006B428; break;
        case 34: goto L_8006B428; break;
        case 35: goto L_8006B428; break;
        case 36: goto L_8006B428; break;
        case 37: goto L_8006B428; break;
        case 38: goto L_8006B428; break;
        case 39: goto L_8006B428; break;
        case 40: goto L_8006B428; break;
        case 41: goto L_8006B428; break;
        case 42: goto L_8006B4B0; break;
        case 43: goto L_8006B428; break;
        case 44: goto L_8006B428; break;
        case 45: goto L_8006B428; break;
        case 46: goto L_8006B428; break;
        case 47: goto L_8006B428; break;
        case 48: goto L_8006B428; break;
        case 49: goto L_8006B428; break;
        case 50: goto L_8006B428; break;
        case 51: goto L_8006B428; break;
        case 52: goto L_8006B428; break;
        case 53: goto L_8006B428; break;
        case 54: goto L_8006B428; break;
        case 55: goto L_8006B428; break;
        case 56: goto L_8006B428; break;
        case 57: goto L_8006B428; break;
        case 58: goto L_8006B428; break;
        case 59: goto L_8006B428; break;
        case 60: goto L_8006B428; break;
        case 61: goto L_8006B428; break;
        case 62: goto L_8006B428; break;
        case 63: goto L_8006B428; break;
        case 64: goto L_8006B428; break;
        case 65: goto L_8006B428; break;
        case 66: goto L_8006B4B0; break;
        case 67: goto L_8006B4B0; break;
        case 68: goto L_8006B428; break;
        case 69: goto L_8006B4B0; break;
        case 70: goto L_8006B428; break;
        case 71: goto L_8006B428; break;
        case 72: goto L_8006B428; break;
        case 73: goto L_8006B428; break;
        case 74: goto L_8006B428; break;
        case 75: goto L_8006B428; break;
        case 76: goto L_8006B428; break;
        case 77: goto L_8006B428; break;
        case 78: goto L_8006B428; break;
        case 79: goto L_8006B428; break;
        case 80: goto L_8006B428; break;
        case 81: goto L_8006B428; break;
        case 82: goto L_8006B428; break;
        case 83: goto L_8006B4B0; break;
        case 84: goto L_8006B428; break;
        case 85: goto L_8006B4B0; break;
        case 86: goto L_8006B4B0; break;
        case 87: goto L_8006B4B0; break;
        case 88: goto L_8006B4B0; break;
        case 89: goto L_8006B4B0; break;
        case 90: goto L_8006B428; break;
        case 91: goto L_8006B428; break;
        case 92: goto L_8006B428; break;
        case 93: goto L_8006B428; break;
        case 94: goto L_8006B428; break;
        case 95: goto L_8006B428; break;
        case 96: goto L_8006B428; break;
        case 97: goto L_8006B4B0; break;
        default: switch_error(__func__, 0x8006B3C4, 0x80104E80);
    }
    // 0x8006B3C8: nop

L_8006B3CC:
    // 0x8006B3CC: slti        $at, $t1, 0x27E
    ctx->r1 = SIGNED(ctx->r9) < 0X27E ? 1 : 0;
    // 0x8006B3D0: bne         $at, $zero, L_8006B3EC
    if (ctx->r1 != 0) {
        // 0x8006B3D4: addiu       $t8, $t1, -0x23D
        ctx->r24 = ADD32(ctx->r9, -0X23D);
            goto L_8006B3EC;
    }
    // 0x8006B3D4: addiu       $t8, $t1, -0x23D
    ctx->r24 = ADD32(ctx->r9, -0X23D);
    // 0x8006B3D8: addiu       $at, $zero, 0x2BC
    ctx->r1 = ADD32(0, 0X2BC);
    // 0x8006B3DC: beql        $t1, $at, L_8006B4B4
    if (ctx->r9 == ctx->r1) {
        // 0x8006B3E0: lhu         $t8, 0x10E($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X10E);
            goto L_8006B4B4;
    }
    goto skip_3;
    // 0x8006B3E0: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
    skip_3:
    // 0x8006B3E4: b           L_8006B42C
    // 0x8006B3E8: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
        goto L_8006B42C;
    // 0x8006B3E8: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
L_8006B3EC:
    // 0x8006B3EC: sltiu       $at, $t8, 0x41
    ctx->r1 = ctx->r24 < 0X41 ? 1 : 0;
    // 0x8006B3F0: beq         $at, $zero, L_8006B428
    if (ctx->r1 == 0) {
        // 0x8006B3F4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8006B428;
    }
    // 0x8006B3F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006B3F8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006B3FC: addu        $at, $at, $t8
    gpr jr_addend_8006B404 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8006B400: lw          $t8, 0x5008($at)
    ctx->r24 = ADD32(ctx->r1, 0X5008);
    // 0x8006B404: jr          $t8
    // 0x8006B408: nop

    switch (jr_addend_8006B404 >> 2) {
        case 0: goto L_8006B4B0; break;
        case 1: goto L_8006B428; break;
        case 2: goto L_8006B428; break;
        case 3: goto L_8006B428; break;
        case 4: goto L_8006B428; break;
        case 5: goto L_8006B428; break;
        case 6: goto L_8006B428; break;
        case 7: goto L_8006B4B0; break;
        case 8: goto L_8006B4B0; break;
        case 9: goto L_8006B4B0; break;
        case 10: goto L_8006B4B0; break;
        case 11: goto L_8006B428; break;
        case 12: goto L_8006B428; break;
        case 13: goto L_8006B428; break;
        case 14: goto L_8006B428; break;
        case 15: goto L_8006B428; break;
        case 16: goto L_8006B428; break;
        case 17: goto L_8006B428; break;
        case 18: goto L_8006B428; break;
        case 19: goto L_8006B428; break;
        case 20: goto L_8006B428; break;
        case 21: goto L_8006B428; break;
        case 22: goto L_8006B428; break;
        case 23: goto L_8006B428; break;
        case 24: goto L_8006B428; break;
        case 25: goto L_8006B428; break;
        case 26: goto L_8006B428; break;
        case 27: goto L_8006B428; break;
        case 28: goto L_8006B428; break;
        case 29: goto L_8006B428; break;
        case 30: goto L_8006B428; break;
        case 31: goto L_8006B428; break;
        case 32: goto L_8006B428; break;
        case 33: goto L_8006B428; break;
        case 34: goto L_8006B4B0; break;
        case 35: goto L_8006B4B0; break;
        case 36: goto L_8006B428; break;
        case 37: goto L_8006B428; break;
        case 38: goto L_8006B428; break;
        case 39: goto L_8006B428; break;
        case 40: goto L_8006B428; break;
        case 41: goto L_8006B428; break;
        case 42: goto L_8006B4B0; break;
        case 43: goto L_8006B4B0; break;
        case 44: goto L_8006B4B0; break;
        case 45: goto L_8006B4B0; break;
        case 46: goto L_8006B4B0; break;
        case 47: goto L_8006B428; break;
        case 48: goto L_8006B428; break;
        case 49: goto L_8006B428; break;
        case 50: goto L_8006B428; break;
        case 51: goto L_8006B428; break;
        case 52: goto L_8006B428; break;
        case 53: goto L_8006B428; break;
        case 54: goto L_8006B428; break;
        case 55: goto L_8006B428; break;
        case 56: goto L_8006B428; break;
        case 57: goto L_8006B428; break;
        case 58: goto L_8006B428; break;
        case 59: goto L_8006B428; break;
        case 60: goto L_8006B4B0; break;
        case 61: goto L_8006B4B0; break;
        case 62: goto L_8006B4B0; break;
        case 63: goto L_8006B4B0; break;
        case 64: goto L_8006B4B0; break;
        default: switch_error(__func__, 0x8006B404, 0x80105008);
    }
    // 0x8006B408: nop

L_8006B40C:
    // 0x8006B40C: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x8006B410: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B414: addiu       $at, $zero, 0x21A
        ctx->r1 = ADD32(0, 0X21A);
            goto L_8006B4B0;
    }
    // 0x8006B414: addiu       $at, $zero, 0x21A
    ctx->r1 = ADD32(0, 0X21A);
    // 0x8006B418: beq         $t1, $at, L_8006B4B0
    if (ctx->r9 == ctx->r1) {
        // 0x8006B41C: addiu       $at, $zero, 0x220
        ctx->r1 = ADD32(0, 0X220);
            goto L_8006B4B0;
    }
    // 0x8006B41C: addiu       $at, $zero, 0x220
    ctx->r1 = ADD32(0, 0X220);
    // 0x8006B420: beql        $t1, $at, L_8006B4B4
    if (ctx->r9 == ctx->r1) {
        // 0x8006B424: lhu         $t8, 0x10E($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X10E);
            goto L_8006B4B4;
    }
    goto skip_4;
    // 0x8006B424: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
    skip_4:
L_8006B428:
    // 0x8006B428: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
L_8006B42C:
    // 0x8006B42C: lh          $t9, 0xFC($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XFC));
    // 0x8006B430: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x8006B434: bgez        $t7, L_8006B444
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006B438: sra         $t6, $t7, 1
        ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8006B444;
    }
    // 0x8006B438: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8006B43C: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8006B440: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8006B444:
    // 0x8006B444: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8006B448: nop

    // 0x8006B44C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006B450: bgez        $t9, L_8006B460
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006B454: sra         $t8, $t9, 1
        ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8006B460;
    }
    // 0x8006B454: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8006B458: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8006B45C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8006B460:
    // 0x8006B460: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8006B464: nop

    // 0x8006B468: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006B46C: bgez        $s4, L_8006B47C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x8006B470: sra         $t7, $s4, 1
        ctx->r15 = S32(SIGNED(ctx->r20) >> 1);
            goto L_8006B47C;
    }
    // 0x8006B470: sra         $t7, $s4, 1
    ctx->r15 = S32(SIGNED(ctx->r20) >> 1);
    // 0x8006B474: addiu       $at, $s4, 0x1
    ctx->r1 = ADD32(ctx->r20, 0X1);
    // 0x8006B478: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8006B47C:
    // 0x8006B47C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x8006B480: bgez        $t6, L_8006B490
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006B484: sra         $t9, $t6, 1
        ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8006B490;
    }
    // 0x8006B484: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8006B488: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8006B48C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8006B490:
    // 0x8006B490: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8006B494: nop

    // 0x8006B498: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006B49C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8006B4A0: jal         0x8006CB30
    // 0x8006B4A4: nop

    func_8006CB30(rdram, ctx);
        goto after_4;
    // 0x8006B4A4: nop

    after_4:
    // 0x8006B4A8: b           L_8006C2E0
    // 0x8006B4AC: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
        goto L_8006C2E0;
    // 0x8006B4AC: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
L_8006B4B0:
    // 0x8006B4B0: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
L_8006B4B4:
    // 0x8006B4B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006B4B8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8006B4BC: bgez        $t8, L_8006B4D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006B4C0: cvt.s.w     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8006B4D0;
    }
    // 0x8006B4C0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006B4C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006B4C8: nop

    // 0x8006B4CC: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_8006B4D0:
    // 0x8006B4D0: lh          $t8, 0x108($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X108));
    // 0x8006B4D4: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006B4D8: lwc1        $f10, -0x13DC($at)
    ctx->f10.u32l = S32(MEM_W(ctx->r1, -0X13DC));
    // 0x8006B4DC: lh          $t7, 0x10A($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X10A));
    // 0x8006B4E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8006B4E4: mul.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8006B4E8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8006B4EC: lh          $t7, 0x102($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X102));
    // 0x8006B4F0: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006B4F4: lh          $t8, 0x100($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X100));
    // 0x8006B4F8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006B4FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006B500: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8006B504: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8006B508: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8006B50C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006B510: lwc1        $f6, -0x13D8($at)
    ctx->f6.u32l = S32(MEM_W(ctx->r1, -0X13D8));
    // 0x8006B514: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8006B518: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8006B51C: mul.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006B520: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8006B524: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8006B528: sh          $t6, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r14;
    // 0x8006B52C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8006B530: sh          $t9, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r25;
    // 0x8006B534: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006B538: or          $t6, $t9, $zero
    ctx->r14 = ctx->r25 | 0;
    // 0x8006B53C: lw          $t9, 0x30($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8006B540: sh          $t6, 0x104($sp)
    MEM_H(0X104, ctx->r29) = ctx->r14;
    // 0x8006B544: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006B548: sh          $t9, 0x106($sp)
    MEM_H(0X106, ctx->r29) = ctx->r25;
    // 0x8006B54C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8006B550: sub.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8006B554: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006B558: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006B55C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8006B560: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8006B564: sh          $t7, 0x102($sp)
    MEM_H(0X102, ctx->r29) = ctx->r15;
    // 0x8006B568: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x8006B56C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8006B570: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8006B574: sh          $t6, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r14;
    // 0x8006B578: sh          $t9, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = ctx->r25;
    // 0x8006B57C: sh          $t8, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r24;
L_8006B580:
    // 0x8006B580: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8006B584: bnel        $a1, $at, L_8006B818
    if (ctx->r5 != ctx->r1) {
        // 0x8006B588: lbu         $t6, 0x16($t0)
        ctx->r14 = MEM_BU(ctx->r8, 0X16);
            goto L_8006B818;
    }
    goto skip_5;
    // 0x8006B588: lbu         $t6, 0x16($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X16);
    skip_5:
    // 0x8006B58C: lh          $t9, 0x14($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X14));
    // 0x8006B590: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006B594: lwc1        $f18, 0x510C($at)
    ctx->f18.u32l = S32(MEM_W(ctx->r1, 0X510C));
    // 0x8006B598: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8006B59C: lhu         $t8, 0x10E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X10E);
    // 0x8006B5A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006B5A4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006B5A8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8006B5AC: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8006B5B0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006B5B4: div.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006B5B8: bgez        $t8, L_8006B5CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006B5BC: swc1        $f6, 0x13C($sp)
        MEM_W(0X13C, ctx->r29) = ctx->f6.u32l;
            goto L_8006B5CC;
    }
    // 0x8006B5BC: swc1        $f6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f6.u32l;
    // 0x8006B5C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006B5C4: nop

    // 0x8006B5C8: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_8006B5CC:
    // 0x8006B5CC: lb          $t7, -0x13D0($t7)
    ctx->r15 = S32(MEM_B(ctx->r15, -0X13D0));
    // 0x8006B5D0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x8006B5D4: lw          $t6, 0x150($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X150));
    // 0x8006B5D8: beq         $t7, $zero, L_8006B68C
    if (ctx->r15 == 0) {
        // 0x8006B5DC: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_8006B68C;
    }
    // 0x8006B5DC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8006B5E0: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8006B5E4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8006B5E8: mflo        $t9
    ctx->r25 = lo;
    // 0x8006B5EC: addiu       $s0, $s0, -0x58BC
    ctx->r16 = ADD32(ctx->r16, -0X58BC);
    // 0x8006B5F0: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8006B5F4: beq         $at, $zero, L_8006B604
    if (ctx->r1 == 0) {
        // 0x8006B5F8: sw          $t9, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r25;
            goto L_8006B604;
    }
    // 0x8006B5F8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8006B5FC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8006B600: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8006B604:
    // 0x8006B604: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8006B608: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006B60C: lwc1        $f16, 0x13C($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X13C));
    // 0x8006B610: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006B614: lwc1        $f8, 0x5110($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, 0X5110));
    // 0x8006B618: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006B61C: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006B620: jal         0x800C2BF0
    // 0x8006B624: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8006B624: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_5:
    // 0x8006B628: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006B62C: lh          $t6, 0x10A($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X10A));
    // 0x8006B630: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006B634: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8006B638: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006B63C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006B640: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006B644: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8006B648: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006B64C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006B650: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8006B654: jal         0x800C2DB0
    // 0x8006B658: sh          $t7, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r15;
    __cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x8006B658: sh          $t7, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r15;
    after_6:
    // 0x8006B65C: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006B660: lh          $t6, 0x102($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X102));
    // 0x8006B664: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8006B668: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8006B66C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006B670: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006B674: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006B678: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8006B67C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006B680: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8006B684: nop

    // 0x8006B688: sh          $t7, 0x102($sp)
    MEM_H(0X102, ctx->r29) = ctx->r15;
L_8006B68C:
    // 0x8006B68C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8006B690: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006B694: lwc1        $f4, 0x13C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X13C));
    // 0x8006B698: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006B69C: lwc1        $f8, 0x5114($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, 0X5114));
    // 0x8006B6A0: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006B6A4: lh          $t6, 0x10A($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X10A));
    // 0x8006B6A8: div.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8006B6AC: sh          $t6, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r14;
    // 0x8006B6B0: jal         0x800C2BF0
    // 0x8006B6B4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_7;
    // 0x8006B6B4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x8006B6B8: lh          $t9, 0x10A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X10A));
    // 0x8006B6BC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x8006B6C0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x8006B6C4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8006B6C8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006B6CC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006B6D0: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8006B6D4: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8006B6D8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8006B6DC: jal         0x800C2BF0
    // 0x8006B6E0: sh          $t7, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r15;
    __sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x8006B6E0: sh          $t7, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r15;
    after_8:
    // 0x8006B6E4: lh          $t6, 0x108($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X108));
    // 0x8006B6E8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x8006B6EC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x8006B6F0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006B6F4: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8006B6F8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006B6FC: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006B700: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8006B704: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8006B708: jal         0x800C2DB0
    // 0x8006B70C: sh          $t8, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r24;
    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x8006B70C: sh          $t8, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r24;
    after_9:
    // 0x8006B710: lh          $t7, 0x102($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X102));
    // 0x8006B714: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x8006B718: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x8006B71C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8006B720: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8006B724: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006B728: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8006B72C: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8006B730: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006B734: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8006B738: jal         0x800C2DB0
    // 0x8006B73C: sh          $t9, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r25;
    __cosf_recomp(rdram, ctx);
        goto after_10;
    // 0x8006B73C: sh          $t9, 0x100($sp)
    MEM_H(0X100, ctx->r29) = ctx->r25;
    after_10:
    // 0x8006B740: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x8006B744: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006B748: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x8006B74C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006B750: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8006B754: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8006B758: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8006B75C: jal         0x800C2BF0
    // 0x8006B760: sh          $t7, 0x102($sp)
    MEM_H(0X102, ctx->r29) = ctx->r15;
    __sinf_recomp(rdram, ctx);
        goto after_11;
    // 0x8006B760: sh          $t7, 0x102($sp)
    MEM_H(0X102, ctx->r29) = ctx->r15;
    after_11:
    // 0x8006B764: lw          $t6, 0x114($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X114));
    // 0x8006B768: lh          $t9, 0x10A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X10A));
    // 0x8006B76C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x8006B770: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8006B774: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8006B778: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006B77C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006B780: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006B784: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8006B788: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006B78C: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8006B790: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8006B794: jal         0x800C2BF0
    // 0x8006B798: sh          $t7, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r15;
    __sinf_recomp(rdram, ctx);
        goto after_12;
    // 0x8006B798: sh          $t7, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = ctx->r15;
    after_12:
    // 0x8006B79C: lh          $t6, 0x108($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X108));
    // 0x8006B7A0: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006B7A4: lh          $t7, 0x10A($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X10A));
    // 0x8006B7A8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8006B7AC: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006B7B0: lh          $t8, 0x100($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X100));
    // 0x8006B7B4: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8006B7B8: sh          $t7, 0x104($sp)
    MEM_H(0X104, ctx->r29) = ctx->r15;
    // 0x8006B7BC: lh          $t7, 0x102($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X102));
    // 0x8006B7C0: lw          $t6, -0x139C($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X139C));
    // 0x8006B7C4: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006B7C8: sh          $t8, 0xFE($sp)
    MEM_H(0XFE, ctx->r29) = ctx->r24;
    // 0x8006B7CC: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8006B7D0: lw          $t8, -0x13CC($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X13CC));
    // 0x8006B7D4: sh          $t7, 0xFC($sp)
    MEM_H(0XFC, ctx->r29) = ctx->r15;
    // 0x8006B7D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006B7DC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8006B7E0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8006B7E4: addiu       $t7, $t7, -0x5010
    ctx->r15 = ADD32(ctx->r15, -0X5010);
    // 0x8006B7E8: addiu       $t4, $t4, 0x4418
    ctx->r12 = ADD32(ctx->r12, 0X4418);
    // 0x8006B7EC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006B7F0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8006B7F4: nop

    // 0x8006B7F8: sh          $t9, 0x108($sp)
    MEM_H(0X108, ctx->r29) = ctx->r25;
    // 0x8006B7FC: sh          $t9, 0x106($sp)
    MEM_H(0X106, ctx->r29) = ctx->r25;
    // 0x8006B800: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x8006B804: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x8006B808: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8006B80C: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x8006B810: lh          $a3, 0xC($t8)
    ctx->r7 = S32(MEM_H(ctx->r24, 0XC));
    // 0x8006B814: lbu         $t6, 0x16($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X16);
L_8006B818:
    // 0x8006B818: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8006B81C: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x8006B820: andi        $t9, $t6, 0x80
    ctx->r25 = ctx->r14 & 0X80;
    // 0x8006B824: beq         $v0, $t9, L_8006B874
    if (ctx->r2 == ctx->r25) {
        // 0x8006B828: lui         $s0, 0x8022
        ctx->r16 = S32(0X8022 << 16);
            goto L_8006B874;
    }
    // 0x8006B828: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x8006B82C: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8006B830: addiu       $t5, $t5, -0x13E8
    ctx->r13 = ADD32(ctx->r13, -0X13E8);
    // 0x8006B834: lw          $t7, 0x0($t5)
    ctx->r15 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006B838: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x8006B83C: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x8006B840: mflo        $t6
    ctx->r14 = lo;
    // 0x8006B844: sw          $t6, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r14;
    // 0x8006B848: bne         $t7, $zero, L_8006B854
    if (ctx->r15 != 0) {
        // 0x8006B84C: nop
    
            goto L_8006B854;
    }
    // 0x8006B84C: nop

    // 0x8006B850: break       7
    do_break(2147924048);
L_8006B854:
    // 0x8006B854: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B858: bne         $t7, $at, L_8006B86C
    if (ctx->r15 != ctx->r1) {
        // 0x8006B85C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006B86C;
    }
    // 0x8006B85C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006B860: bne         $t8, $at, L_8006B86C
    if (ctx->r24 != ctx->r1) {
        // 0x8006B864: nop
    
            goto L_8006B86C;
    }
    // 0x8006B864: nop

    // 0x8006B868: break       6
    do_break(2147924072);
L_8006B86C:
    // 0x8006B86C: b           L_8006B8B4
    // 0x8006B870: nop

        goto L_8006B8B4;
    // 0x8006B870: nop

L_8006B874:
    // 0x8006B874: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8006B878: addiu       $t5, $t5, -0x13E8
    ctx->r13 = ADD32(ctx->r13, -0X13E8);
    // 0x8006B87C: lw          $t9, 0x0($t5)
    ctx->r25 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006B880: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x8006B884: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x8006B888: mflo        $t7
    ctx->r15 = lo;
    // 0x8006B88C: sw          $t7, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r15;
    // 0x8006B890: bne         $t9, $zero, L_8006B89C
    if (ctx->r25 != 0) {
        // 0x8006B894: nop
    
            goto L_8006B89C;
    }
    // 0x8006B894: nop

    // 0x8006B898: break       7
    do_break(2147924120);
L_8006B89C:
    // 0x8006B89C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B8A0: bne         $t9, $at, L_8006B8B4
    if (ctx->r25 != ctx->r1) {
        // 0x8006B8A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006B8B4;
    }
    // 0x8006B8A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006B8A8: bne         $t8, $at, L_8006B8B4
    if (ctx->r24 != ctx->r1) {
        // 0x8006B8AC: nop
    
            goto L_8006B8B4;
    }
    // 0x8006B8AC: nop

    // 0x8006B8B0: break       6
    do_break(2147924144);
L_8006B8B4:
    // 0x8006B8B4: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8006B8B8: lw          $t6, -0x13E4($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X13E4));
    // 0x8006B8BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006B8C0: andi        $t8, $a3, 0x8
    ctx->r24 = ctx->r7 & 0X8;
    // 0x8006B8C4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8006B8C8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8006B8CC: addiu       $a1, $a1, -0x537C
    ctx->r5 = ADD32(ctx->r5, -0X537C);
    // 0x8006B8D0: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006B8D4: addiu       $s0, $s0, -0x2350
    ctx->r16 = ADD32(ctx->r16, -0X2350);
    // 0x8006B8D8: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x8006B8DC: beq         $t8, $zero, L_8006B8E8
    if (ctx->r24 == 0) {
        // 0x8006B8E0: div.s       $f0, $f6, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_8006B8E8;
    }
    // 0x8006B8E0: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006B8E4: addu        $s3, $s3, $s4
    ctx->r19 = ADD32(ctx->r19, ctx->r20);
L_8006B8E8:
    // 0x8006B8E8: bnel        $at, $zero, L_8006C2E0
    if (ctx->r1 != 0) {
        // 0x8006B8EC: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_8006C2E0;
    }
    goto skip_6;
    // 0x8006B8EC: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_6:
L_8006B8F0:
    // 0x8006B8F0: lhu         $t9, 0xF0($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0XF0);
    // 0x8006B8F4: lhu         $t6, 0xF4($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XF4);
    // 0x8006B8F8: or          $t2, $s2, $zero
    ctx->r10 = ctx->r18 | 0;
    // 0x8006B8FC: sll         $t7, $t9, 5
    ctx->r15 = S32(ctx->r25 << 5);
    // 0x8006B900: lw          $t9, 0x12C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X12C));
    // 0x8006B904: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x8006B908: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8006B90C: slt         $at, $t9, $s2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8006B910: beq         $at, $zero, L_8006B920
    if (ctx->r1 == 0) {
        // 0x8006B914: sw          $t7, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r15;
            goto L_8006B920;
    }
    // 0x8006B914: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8006B918: b           L_8006B920
    // 0x8006B91C: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
        goto L_8006B920;
    // 0x8006B91C: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
L_8006B920:
    // 0x8006B920: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8006B924: lb          $t7, -0x13CF($t7)
    ctx->r15 = S32(MEM_B(ctx->r15, -0X13CF));
    // 0x8006B928: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8006B92C: beq         $t7, $zero, L_8006BB2C
    if (ctx->r15 == 0) {
        // 0x8006B930: nop
    
            goto L_8006BB2C;
    }
    // 0x8006B930: nop

    // 0x8006B934: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B938: lui         $t8, 0xFD90
    ctx->r24 = S32(0XFD90 << 16);
    // 0x8006B93C: lui         $t7, 0xF590
    ctx->r15 = S32(0XF590 << 16);
    // 0x8006B940: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006B944: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006B948: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006B94C: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8006B950: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B954: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8006B958: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8006B95C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006B960: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006B964: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006B968: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006B96C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006B970: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B974: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8006B978: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8006B97C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006B980: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8006B984: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006B988: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006B98C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8006B990: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006B994: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8006B998: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006B99C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006B9A0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006B9A4: lw          $t0, 0x0($t5)
    ctx->r8 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006B9A8: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x8006B9AC: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B9B0: mflo        $a3
    ctx->r7 = lo;
    // 0x8006B9B4: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x8006B9B8: sra         $t8, $a3, 2
    ctx->r24 = S32(SIGNED(ctx->r7) >> 2);
    // 0x8006B9BC: addiu       $a3, $t8, -0x1
    ctx->r7 = ADD32(ctx->r24, -0X1);
    // 0x8006B9C0: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8006B9C4: beq         $at, $zero, L_8006B9D4
    if (ctx->r1 == 0) {
        // 0x8006B9C8: nop
    
            goto L_8006B9D4;
    }
    // 0x8006B9C8: nop

    // 0x8006B9CC: b           L_8006B9D4
    // 0x8006B9D0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
        goto L_8006B9D4;
    // 0x8006B9D0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
L_8006B9D4:
    // 0x8006B9D4: bgez        $t0, L_8006B9E4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8006B9D8: sra         $v0, $t0, 4
        ctx->r2 = S32(SIGNED(ctx->r8) >> 4);
            goto L_8006B9E4;
    }
    // 0x8006B9D8: sra         $v0, $t0, 4
    ctx->r2 = S32(SIGNED(ctx->r8) >> 4);
    // 0x8006B9DC: addiu       $at, $t0, 0xF
    ctx->r1 = ADD32(ctx->r8, 0XF);
    // 0x8006B9E0: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_8006B9E4:
    // 0x8006B9E4: bgtz        $v0, L_8006B9F4
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006B9E8: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8006B9F4;
    }
    // 0x8006B9E8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8006B9EC: b           L_8006B9F4
    // 0x8006B9F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8006B9F4;
    // 0x8006B9F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8006B9F4:
    // 0x8006B9F4: bgtz        $v0, L_8006BA04
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006B9F8: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8006BA04;
    }
    // 0x8006B9F8: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8006B9FC: b           L_8006BA08
    // 0x8006BA00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8006BA08;
    // 0x8006BA00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8006BA04:
    // 0x8006BA04: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8006BA08:
    // 0x8006BA08: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x8006BA0C: bne         $t1, $zero, L_8006BA18
    if (ctx->r9 != 0) {
        // 0x8006BA10: nop
    
            goto L_8006BA18;
    }
    // 0x8006BA10: nop

    // 0x8006BA14: break       7
    do_break(2147924500);
L_8006BA18:
    // 0x8006BA18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BA1C: bne         $t1, $at, L_8006BA30
    if (ctx->r9 != ctx->r1) {
        // 0x8006BA20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006BA30;
    }
    // 0x8006BA20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006BA24: bne         $t9, $at, L_8006BA30
    if (ctx->r25 != ctx->r1) {
        // 0x8006BA28: nop
    
            goto L_8006BA30;
    }
    // 0x8006BA28: nop

    // 0x8006BA2C: break       6
    do_break(2147924524);
L_8006BA30:
    // 0x8006BA30: mflo        $t7
    ctx->r15 = lo;
    // 0x8006BA34: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8006BA38: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8006BA3C: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8006BA40: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8006BA44: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8006BA48: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x8006BA4C: sw          $t6, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r14;
    // 0x8006BA50: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BA54: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8006BA58: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8006BA5C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006BA60: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006BA64: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006BA68: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006BA6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006BA70: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BA74: lw          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BA78: addiu       $a2, $t2, -0x1
    ctx->r6 = ADD32(ctx->r10, -0X1);
    // 0x8006BA7C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006BA80: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8006BA84: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x8006BA88: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006BA8C: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8006BA90: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8006BA94: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x8006BA98: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8006BA9C: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8006BAA0: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8006BAA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006BAA8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006BAAC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006BAB0: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BAB4: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8006BAB8: subu        $s2, $s2, $t2
    ctx->r18 = SUB32(ctx->r18, ctx->r10);
    // 0x8006BABC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006BAC0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006BAC4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006BAC8: lw          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BACC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006BAD0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8006BAD4: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8006BAD8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8006BADC: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8006BAE0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8006BAE4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8006BAE8: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8006BAEC: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8006BAF0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8006BAF4: lw          $t7, 0x0($t5)
    ctx->r15 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BAF8: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BAFC: mflo        $t8
    ctx->r24 = lo;
    // 0x8006BB00: bgez        $t8, L_8006BB10
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006BB04: sra         $t6, $t8, 1
        ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8006BB10;
    }
    // 0x8006BB04: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8006BB08: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8006BB0C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8006BB10:
    // 0x8006BB10: bgez        $t6, L_8006BB20
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006BB14: sra         $t9, $t6, 2
        ctx->r25 = S32(SIGNED(ctx->r14) >> 2);
            goto L_8006BB20;
    }
    // 0x8006BB14: sra         $t9, $t6, 2
    ctx->r25 = S32(SIGNED(ctx->r14) >> 2);
    // 0x8006BB18: addiu       $at, $t6, 0x3
    ctx->r1 = ADD32(ctx->r14, 0X3);
    // 0x8006BB1C: sra         $t9, $at, 2
    ctx->r25 = S32(SIGNED(ctx->r1) >> 2);
L_8006BB20:
    // 0x8006BB20: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8006BB24: b           L_8006BF2C
    // 0x8006BB28: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
        goto L_8006BF2C;
    // 0x8006BB28: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
L_8006BB2C:
    // 0x8006BB2C: lw          $t8, -0x139C($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X139C));
    // 0x8006BB30: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006BB34: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x8006BB38: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x8006BB3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006BB40: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8006BB44: lbu         $t9, -0x4FFA($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4FFA);
    // 0x8006BB48: andi        $t7, $t9, 0x80
    ctx->r15 = ctx->r25 & 0X80;
    // 0x8006BB4C: beql        $v0, $t7, L_8006BD50
    if (ctx->r2 == ctx->r15) {
        // 0x8006BB50: lw          $v1, 0x0($t4)
        ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
            goto L_8006BD50;
    }
    goto skip_7;
    // 0x8006BB50: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    skip_7:
    // 0x8006BB54: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BB58: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8006BB5C: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8006BB60: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006BB64: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8006BB68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006BB6C: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8006BB70: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BB74: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x8006BB78: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8006BB7C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006BB80: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006BB84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006BB88: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006BB8C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006BB90: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BB94: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8006BB98: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8006BB9C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006BBA0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006BBA4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006BBA8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006BBAC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8006BBB0: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BBB4: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8006BBB8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006BBBC: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006BBC0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006BBC4: lw          $t0, 0x0($t5)
    ctx->r8 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BBC8: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x8006BBCC: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BBD0: mflo        $a3
    ctx->r7 = lo;
    // 0x8006BBD4: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x8006BBD8: sra         $t6, $a3, 2
    ctx->r14 = S32(SIGNED(ctx->r7) >> 2);
    // 0x8006BBDC: addiu       $a3, $t6, -0x1
    ctx->r7 = ADD32(ctx->r14, -0X1);
    // 0x8006BBE0: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8006BBE4: beq         $at, $zero, L_8006BBF4
    if (ctx->r1 == 0) {
        // 0x8006BBE8: nop
    
            goto L_8006BBF4;
    }
    // 0x8006BBE8: nop

    // 0x8006BBEC: b           L_8006BBF4
    // 0x8006BBF0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
        goto L_8006BBF4;
    // 0x8006BBF0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
L_8006BBF4:
    // 0x8006BBF4: bgez        $t0, L_8006BC04
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8006BBF8: sra         $v0, $t0, 4
        ctx->r2 = S32(SIGNED(ctx->r8) >> 4);
            goto L_8006BC04;
    }
    // 0x8006BBF8: sra         $v0, $t0, 4
    ctx->r2 = S32(SIGNED(ctx->r8) >> 4);
    // 0x8006BBFC: addiu       $at, $t0, 0xF
    ctx->r1 = ADD32(ctx->r8, 0XF);
    // 0x8006BC00: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_8006BC04:
    // 0x8006BC04: bgtz        $v0, L_8006BC14
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006BC08: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8006BC14;
    }
    // 0x8006BC08: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8006BC0C: b           L_8006BC14
    // 0x8006BC10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8006BC14;
    // 0x8006BC10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8006BC14:
    // 0x8006BC14: bgtz        $v0, L_8006BC24
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006BC18: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8006BC24;
    }
    // 0x8006BC18: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8006BC1C: b           L_8006BC28
    // 0x8006BC20: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8006BC28;
    // 0x8006BC20: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8006BC24:
    // 0x8006BC24: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8006BC28:
    // 0x8006BC28: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x8006BC2C: bne         $t1, $zero, L_8006BC38
    if (ctx->r9 != 0) {
        // 0x8006BC30: nop
    
            goto L_8006BC38;
    }
    // 0x8006BC30: nop

    // 0x8006BC34: break       7
    do_break(2147925044);
L_8006BC38:
    // 0x8006BC38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BC3C: bne         $t1, $at, L_8006BC50
    if (ctx->r9 != ctx->r1) {
        // 0x8006BC40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006BC50;
    }
    // 0x8006BC40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006BC44: bne         $t9, $at, L_8006BC50
    if (ctx->r25 != ctx->r1) {
        // 0x8006BC48: nop
    
            goto L_8006BC50;
    }
    // 0x8006BC48: nop

    // 0x8006BC4C: break       6
    do_break(2147925068);
L_8006BC50:
    // 0x8006BC50: mflo        $t7
    ctx->r15 = lo;
    // 0x8006BC54: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8006BC58: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8006BC5C: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8006BC60: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8006BC64: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8006BC68: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8006BC6C: sw          $t8, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r24;
    // 0x8006BC70: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BC74: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8006BC78: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8006BC7C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006BC80: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006BC84: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006BC88: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006BC8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006BC90: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BC94: lw          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BC98: addiu       $a2, $t2, -0x1
    ctx->r6 = ADD32(ctx->r10, -0X1);
    // 0x8006BC9C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006BCA0: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8006BCA4: addiu       $t6, $t9, 0x7
    ctx->r14 = ADD32(ctx->r25, 0X7);
    // 0x8006BCA8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006BCAC: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8006BCB0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8006BCB4: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x8006BCB8: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8006BCBC: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8006BCC0: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8006BCC4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006BCC8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006BCCC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006BCD0: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BCD4: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8006BCD8: subu        $s2, $s2, $t2
    ctx->r18 = SUB32(ctx->r18, ctx->r10);
    // 0x8006BCDC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006BCE0: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8006BCE4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006BCE8: lw          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BCEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006BCF0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8006BCF4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006BCF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006BCFC: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8006BD00: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8006BD04: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8006BD08: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8006BD0C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8006BD10: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8006BD14: lw          $t7, 0x0($t5)
    ctx->r15 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BD18: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BD1C: mflo        $t6
    ctx->r14 = lo;
    // 0x8006BD20: bgez        $t6, L_8006BD30
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006BD24: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8006BD30;
    }
    // 0x8006BD24: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8006BD28: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8006BD2C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8006BD30:
    // 0x8006BD30: bgez        $t8, L_8006BD40
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006BD34: sra         $t9, $t8, 2
        ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
            goto L_8006BD40;
    }
    // 0x8006BD34: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8006BD38: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x8006BD3C: sra         $t9, $at, 2
    ctx->r25 = S32(SIGNED(ctx->r1) >> 2);
L_8006BD40:
    // 0x8006BD40: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8006BD44: b           L_8006BF2C
    // 0x8006BD48: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
        goto L_8006BF2C;
    // 0x8006BD48: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
    // 0x8006BD4C: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
L_8006BD50:
    // 0x8006BD50: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8006BD54: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8006BD58: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006BD5C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8006BD60: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006BD64: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8006BD68: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BD6C: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8006BD70: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8006BD74: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006BD78: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006BD7C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006BD80: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006BD84: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006BD88: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BD8C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8006BD90: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8006BD94: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006BD98: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8006BD9C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006BDA0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006BDA4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8006BDA8: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BDAC: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8006BDB0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006BDB4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006BDB8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006BDBC: lw          $t0, 0x0($t5)
    ctx->r8 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BDC0: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x8006BDC4: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BDC8: mflo        $a3
    ctx->r7 = lo;
    // 0x8006BDCC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006BDD0: sra         $t8, $a3, 1
    ctx->r24 = S32(SIGNED(ctx->r7) >> 1);
    // 0x8006BDD4: addiu       $a3, $t8, -0x1
    ctx->r7 = ADD32(ctx->r24, -0X1);
    // 0x8006BDD8: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8006BDDC: beq         $at, $zero, L_8006BDEC
    if (ctx->r1 == 0) {
        // 0x8006BDE0: nop
    
            goto L_8006BDEC;
    }
    // 0x8006BDE0: nop

    // 0x8006BDE4: b           L_8006BDEC
    // 0x8006BDE8: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
        goto L_8006BDEC;
    // 0x8006BDE8: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
L_8006BDEC:
    // 0x8006BDEC: bgez        $t0, L_8006BDFC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8006BDF0: sra         $v0, $t0, 3
        ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8006BDFC;
    }
    // 0x8006BDF0: sra         $v0, $t0, 3
    ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8006BDF4: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8006BDF8: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8006BDFC:
    // 0x8006BDFC: bgtz        $v0, L_8006BE0C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006BE00: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8006BE0C;
    }
    // 0x8006BE00: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8006BE04: b           L_8006BE0C
    // 0x8006BE08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8006BE0C;
    // 0x8006BE08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8006BE0C:
    // 0x8006BE0C: bgtz        $v0, L_8006BE1C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006BE10: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8006BE1C;
    }
    // 0x8006BE10: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8006BE14: b           L_8006BE20
    // 0x8006BE18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8006BE20;
    // 0x8006BE18: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8006BE1C:
    // 0x8006BE1C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8006BE20:
    // 0x8006BE20: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x8006BE24: bne         $t1, $zero, L_8006BE30
    if (ctx->r9 != 0) {
        // 0x8006BE28: nop
    
            goto L_8006BE30;
    }
    // 0x8006BE28: nop

    // 0x8006BE2C: break       7
    do_break(2147925548);
L_8006BE30:
    // 0x8006BE30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BE34: bne         $t1, $at, L_8006BE48
    if (ctx->r9 != ctx->r1) {
        // 0x8006BE38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006BE48;
    }
    // 0x8006BE38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006BE3C: bne         $t9, $at, L_8006BE48
    if (ctx->r25 != ctx->r1) {
        // 0x8006BE40: nop
    
            goto L_8006BE48;
    }
    // 0x8006BE40: nop

    // 0x8006BE44: break       6
    do_break(2147925572);
L_8006BE48:
    // 0x8006BE48: mflo        $t7
    ctx->r15 = lo;
    // 0x8006BE4C: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8006BE50: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8006BE54: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8006BE58: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8006BE5C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8006BE60: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x8006BE64: sw          $t6, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r14;
    // 0x8006BE68: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BE6C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8006BE70: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8006BE74: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006BE78: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006BE7C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006BE80: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006BE84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006BE88: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BE8C: lw          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BE90: addiu       $a2, $t2, -0x1
    ctx->r6 = ADD32(ctx->r10, -0X1);
    // 0x8006BE94: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006BE98: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x8006BE9C: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8006BEA0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006BEA4: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x8006BEA8: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x8006BEAC: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8006BEB0: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8006BEB4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8006BEB8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006BEBC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006BEC0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006BEC4: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BEC8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8006BECC: subu        $s2, $s2, $t2
    ctx->r18 = SUB32(ctx->r18, ctx->r10);
    // 0x8006BED0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006BED4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006BED8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006BEDC: lw          $t9, 0x0($t5)
    ctx->r25 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BEE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006BEE4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8006BEE8: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x8006BEEC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006BEF0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8006BEF4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8006BEF8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8006BEFC: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8006BF00: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8006BF04: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006BF08: lw          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8006BF0C: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BF10: mflo        $t9
    ctx->r25 = lo;
    // 0x8006BF14: bgez        $t9, L_8006BF24
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006BF18: sra         $t7, $t9, 2
        ctx->r15 = S32(SIGNED(ctx->r25) >> 2);
            goto L_8006BF24;
    }
    // 0x8006BF18: sra         $t7, $t9, 2
    ctx->r15 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8006BF1C: addiu       $at, $t9, 0x3
    ctx->r1 = ADD32(ctx->r25, 0X3);
    // 0x8006BF20: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_8006BF24:
    // 0x8006BF24: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8006BF28: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
L_8006BF2C:
    // 0x8006BF2C: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8006BF30: lw          $t8, -0x13CC($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X13CC));
    // 0x8006BF34: lh          $t9, 0xC($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0XC));
    // 0x8006BF38: andi        $t7, $t9, 0x8
    ctx->r15 = ctx->r25 & 0X8;
    // 0x8006BF3C: beql        $t7, $zero, L_8006BF88
    if (ctx->r15 == 0) {
        // 0x8006BF40: mtc1        $t2, $f6
        ctx->f6.u32l = ctx->r10;
            goto L_8006BF88;
    }
    goto skip_8;
    // 0x8006BF40: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    skip_8:
    // 0x8006BF44: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8006BF48: sll         $t1, $s3, 16
    ctx->r9 = S32(ctx->r19 << 16);
    // 0x8006BF4C: sra         $t6, $t1, 16
    ctx->r14 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8006BF50: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006BF54: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8006BF58: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8006BF5C: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006BF60: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8006BF64: nop

    // 0x8006BF68: subu        $v1, $s3, $v0
    ctx->r3 = SUB32(ctx->r19, ctx->r2);
    // 0x8006BF6C: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x8006BF70: sra         $t9, $t3, 16
    ctx->r25 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8006BF74: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x8006BF78: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x8006BF7C: b           L_8006BFC0
    // 0x8006BF80: subu        $s4, $s4, $v0
    ctx->r20 = SUB32(ctx->r20, ctx->r2);
        goto L_8006BFC0;
    // 0x8006BF80: subu        $s4, $s4, $v0
    ctx->r20 = SUB32(ctx->r20, ctx->r2);
    // 0x8006BF84: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
L_8006BF88:
    // 0x8006BF88: sll         $t1, $s3, 16
    ctx->r9 = S32(ctx->r19 << 16);
    // 0x8006BF8C: sra         $t7, $t1, 16
    ctx->r15 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8006BF90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006BF94: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x8006BF98: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006BF9C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006BFA0: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8006BFA4: nop

    // 0x8006BFA8: addu        $v1, $s3, $v0
    ctx->r3 = ADD32(ctx->r19, ctx->r2);
    // 0x8006BFAC: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x8006BFB0: sra         $t8, $t3, 16
    ctx->r24 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8006BFB4: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x8006BFB8: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x8006BFBC: subu        $s4, $s4, $v0
    ctx->r20 = SUB32(ctx->r20, ctx->r2);
L_8006BFC0:
    // 0x8006BFC0: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x8006BFC4: lh          $t9, -0x2354($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X2354));
    // 0x8006BFC8: bnel        $t9, $zero, L_8006C004
    if (ctx->r25 != 0) {
        // 0x8006BFCC: lw          $v1, 0x0($t4)
        ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
            goto L_8006C004;
    }
    goto skip_9;
    // 0x8006BFCC: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    skip_9:
    // 0x8006BFD0: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006BFD4: lui         $t6, 0x4F0
    ctx->r14 = S32(0X4F0 << 16);
    // 0x8006BFD8: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8006BFDC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006BFE0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006BFE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006BFE8: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006BFEC: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8006BFF0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8006BFF4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006BFF8: sh          $t9, -0x2354($at)
    MEM_H(-0X2354, ctx->r1) = ctx->r25;
    // 0x8006BFFC: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8006C000: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
L_8006C004:
    // 0x8006C004: lui         $t6, 0xBF00
    ctx->r14 = S32(0XBF00 << 16);
    // 0x8006C008: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8006C00C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006C010: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8006C014: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006C018: lh          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006C01C: lui         $ra, 0x8022
    ctx->r31 = S32(0X8022 << 16);
    // 0x8006C020: addiu       $ra, $ra, -0x2980
    ctx->r31 = ADD32(ctx->r31, -0X2980);
    // 0x8006C024: sll         $v0, $t8, 2
    ctx->r2 = S32(ctx->r24 << 2);
    // 0x8006C028: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8006C02C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006C030: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x8006C034: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8006C038: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8006C03C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8006C040: addiu       $t7, $v0, 0xA
    ctx->r15 = ADD32(ctx->r2, 0XA);
    // 0x8006C044: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8006C048: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x8006C04C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8006C050: addiu       $t9, $v0, 0x14
    ctx->r25 = ADD32(ctx->r2, 0X14);
    // 0x8006C054: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x8006C058: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8006C05C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006C060: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8006C064: lui         $t7, 0xBF00
    ctx->r15 = S32(0XBF00 << 16);
    // 0x8006C068: sll         $t2, $a2, 5
    ctx->r10 = S32(ctx->r6 << 5);
    // 0x8006C06C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006C070: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8006C074: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006C078: lh          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006C07C: sll         $v0, $t8, 2
    ctx->r2 = S32(ctx->r24 << 2);
    // 0x8006C080: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8006C084: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006C088: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8006C08C: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8006C090: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x8006C094: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8006C098: addiu       $t9, $v0, 0x14
    ctx->r25 = ADD32(ctx->r2, 0X14);
    // 0x8006C09C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8006C0A0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8006C0A4: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8006C0A8: addiu       $t6, $v0, 0x1E
    ctx->r14 = ADD32(ctx->r2, 0X1E);
    // 0x8006C0AC: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8006C0B0: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8006C0B4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006C0B8: lh          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8006C0BC: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8006C0C0: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x8006C0C4: addiu       $t9, $t6, 0x4
    ctx->r25 = ADD32(ctx->r14, 0X4);
    // 0x8006C0C8: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8006C0CC: lh          $t8, -0x2354($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X2354));
    // 0x8006C0D0: lh          $t6, 0x10A($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X10A));
    // 0x8006C0D4: addiu       $v0, $v0, -0x13D4
    ctx->r2 = ADD32(ctx->r2, -0X13D4);
    // 0x8006C0D8: addiu       $t7, $t8, -0x4
    ctx->r15 = ADD32(ctx->r24, -0X4);
    // 0x8006C0DC: sh          $t7, -0x2354($at)
    MEM_H(-0X2354, ctx->r1) = ctx->r15;
    // 0x8006C0E0: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C0E4: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x8006C0E8: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x8006C0EC: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C0F0: lh          $t8, 0x102($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X102));
    // 0x8006C0F4: sh          $t8, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r24;
    // 0x8006C0F8: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C0FC: sh          $t1, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r9;
    // 0x8006C100: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C104: lw          $t9, 0x40($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8006C108: sh          $t9, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r25;
    // 0x8006C10C: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C110: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8006C114: sh          $zero, 0xA($t7)
    MEM_H(0XA, ctx->r15) = 0;
    // 0x8006C118: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C11C: lw          $t6, 0x0($ra)
    ctx->r14 = S32(MEM_W(ctx->r31, 0X0));
    // 0x8006C120: sb          $t6, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r14;
    // 0x8006C124: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C128: lw          $t8, -0x2958($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X2958));
    // 0x8006C12C: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x8006C130: sb          $t8, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r24;
    // 0x8006C134: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C138: lw          $t6, -0x2930($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X2930));
    // 0x8006C13C: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8006C140: sb          $t6, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r14;
    // 0x8006C144: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C148: lbu         $t8, -0x1398($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X1398);
    // 0x8006C14C: sb          $t8, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r24;
    // 0x8006C150: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C154: lh          $t8, 0x108($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X108));
    // 0x8006C158: addiu       $t9, $t6, 0x10
    ctx->r25 = ADD32(ctx->r14, 0X10);
    // 0x8006C15C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8006C160: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8006C164: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C168: lh          $t6, 0x100($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X100));
    // 0x8006C16C: sh          $t6, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r14;
    // 0x8006C170: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C174: sh          $t1, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r9;
    // 0x8006C178: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C17C: lw          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8006C180: sh          $t7, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r15;
    // 0x8006C184: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C188: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x8006C18C: sh          $zero, 0xA($t9)
    MEM_H(0XA, ctx->r25) = 0;
    // 0x8006C190: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C194: lw          $t8, 0x0($ra)
    ctx->r24 = S32(MEM_W(ctx->r31, 0X0));
    // 0x8006C198: sb          $t8, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r24;
    // 0x8006C19C: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C1A0: lw          $t6, -0x2958($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X2958));
    // 0x8006C1A4: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8006C1A8: sb          $t6, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r14;
    // 0x8006C1AC: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C1B0: lw          $t8, -0x2930($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X2930));
    // 0x8006C1B4: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8006C1B8: sb          $t8, 0xE($t7)
    MEM_B(0XE, ctx->r15) = ctx->r24;
    // 0x8006C1BC: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C1C0: lbu         $t6, -0x1398($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1398);
    // 0x8006C1C4: sb          $t6, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r14;
    // 0x8006C1C8: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C1CC: lh          $t6, 0x106($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X106));
    // 0x8006C1D0: addiu       $t7, $t8, 0x10
    ctx->r15 = ADD32(ctx->r24, 0X10);
    // 0x8006C1D4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8006C1D8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x8006C1DC: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C1E0: lh          $t8, 0xFE($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XFE));
    // 0x8006C1E4: sh          $t8, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r24;
    // 0x8006C1E8: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C1EC: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8006C1F0: sh          $t3, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r11;
    // 0x8006C1F4: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C1F8: lw          $t9, 0x3C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8006C1FC: sh          $t9, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r25;
    // 0x8006C200: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C204: sh          $t2, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r10;
    // 0x8006C208: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C20C: lw          $t9, 0x0($ra)
    ctx->r25 = S32(MEM_W(ctx->r31, 0X0));
    // 0x8006C210: sb          $t9, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r25;
    // 0x8006C214: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C218: lw          $t7, -0x2958($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X2958));
    // 0x8006C21C: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x8006C220: sb          $t7, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r15;
    // 0x8006C224: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C228: lw          $t9, -0x2930($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X2930));
    // 0x8006C22C: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8006C230: sb          $t9, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r25;
    // 0x8006C234: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C238: lbu         $t7, -0x1398($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1398);
    // 0x8006C23C: sb          $t7, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r15;
    // 0x8006C240: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C244: lh          $t7, 0x104($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X104));
    // 0x8006C248: addiu       $t8, $t9, 0x10
    ctx->r24 = ADD32(ctx->r25, 0X10);
    // 0x8006C24C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8006C250: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8006C254: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C258: lh          $t9, 0xFC($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XFC));
    // 0x8006C25C: sh          $t9, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r25;
    // 0x8006C260: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C264: sh          $t3, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r11;
    // 0x8006C268: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C26C: lw          $t6, 0x40($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8006C270: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8006C274: sh          $t6, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r14;
    // 0x8006C278: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C27C: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x8006C280: sh          $t2, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r10;
    // 0x8006C284: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C288: lw          $t7, -0x2980($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X2980));
    // 0x8006C28C: sb          $t7, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r15;
    // 0x8006C290: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C294: lw          $t9, -0x2958($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X2958));
    // 0x8006C298: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8006C29C: sb          $t9, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r25;
    // 0x8006C2A0: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C2A4: lw          $t7, -0x2930($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X2930));
    // 0x8006C2A8: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8006C2AC: sb          $t7, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r15;
    // 0x8006C2B0: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C2B4: lbu         $t9, -0x1398($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1398);
    // 0x8006C2B8: sb          $t9, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r25;
    // 0x8006C2BC: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8006C2C0: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006C2C4: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8006C2C8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006C2CC: addiu       $t6, $t7, 0x10
    ctx->r14 = ADD32(ctx->r15, 0X10);
    // 0x8006C2D0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8006C2D4: beq         $at, $zero, L_8006B8F0
    if (ctx->r1 == 0) {
        // 0x8006C2D8: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_8006B8F0;
    }
    // 0x8006C2D8: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8006C2DC: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
L_8006C2E0:
    // 0x8006C2E0: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8006C2E4: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8006C2E8: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8006C2EC: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8006C2F0: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8006C2F4: jr          $ra
    // 0x8006C2F8: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x8006C2F8: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void displayinvweapons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F360: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8006F364: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006F368: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8006F36C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006F370: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8006F374: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006F378: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006F37C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006F380: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006F384: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x8006F388: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006F38C: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x8006F390: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006F394: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8006F398: lh          $v1, 0x378($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X378));
    // 0x8006F39C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F3A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006F3A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006F3A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006F3AC: blez        $v1, L_8006F5EC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006F3B0: sw          $a0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r4;
            goto L_8006F5EC;
    }
    // 0x8006F3B0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8006F3B4: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8006F3B8: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x8006F3BC: lh          $t1, -0x1348($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, -0X1348));
    // 0x8006F3C0: lh          $t0, -0x134A($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, -0X134A));
    // 0x8006F3C4: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8006F3C8: lh          $t5, -0x1344($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X1344));
    // 0x8006F3CC: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x8006F3D0: lhu         $s3, 0x372($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X372);
    // 0x8006F3D4: bgez        $s1, L_8006F3E4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8006F3D8: sra         $t2, $s1, 1
        ctx->r10 = S32(SIGNED(ctx->r17) >> 1);
            goto L_8006F3E4;
    }
    // 0x8006F3D8: sra         $t2, $s1, 1
    ctx->r10 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8006F3DC: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x8006F3E0: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8006F3E4:
    // 0x8006F3E4: subu        $s2, $t5, $v1
    ctx->r18 = SUB32(ctx->r13, ctx->r3);
    // 0x8006F3E8: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
    // 0x8006F3EC: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8006F3F0: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8006F3F4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8006F3F8: sra         $s1, $t3, 16
    ctx->r17 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8006F3FC: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006F400: beq         $s3, $at, L_8006F424
    if (ctx->r19 == ctx->r1) {
        // 0x8006F404: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_8006F424;
    }
    // 0x8006F404: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8006F408: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8006F40C: beq         $s3, $at, L_8006F430
    if (ctx->r19 == ctx->r1) {
        // 0x8006F410: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8006F430;
    }
    // 0x8006F410: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8006F414: beql        $s3, $at, L_8006F440
    if (ctx->r19 == ctx->r1) {
        // 0x8006F418: addiu       $s3, $zero, 0x8
        ctx->r19 = ADD32(0, 0X8);
            goto L_8006F440;
    }
    goto skip_0;
    // 0x8006F418: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    skip_0:
    // 0x8006F41C: b           L_8006F448
    // 0x8006F420: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
        goto L_8006F448;
    // 0x8006F420: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_8006F424:
    // 0x8006F424: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006F428: b           L_8006F444
    // 0x8006F42C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006F444;
    // 0x8006F42C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006F430:
    // 0x8006F430: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x8006F434: b           L_8006F444
    // 0x8006F438: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8006F444;
    // 0x8006F438: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006F43C: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_8006F440:
    // 0x8006F440: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8006F444:
    // 0x8006F444: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_8006F448:
    // 0x8006F448: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006F44C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8006F450: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8006F454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F458: jal         0x800B2FB0
    // 0x8006F45C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    getnextweapon(rdram, ctx);
        goto after_0;
    // 0x8006F45C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x8006F460: lw          $a1, 0x2C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006F464: sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // 0x8006F468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F46C: jal         0x800B2FB0
    // 0x8006F470: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    getnextweapon(rdram, ctx);
        goto after_1;
    // 0x8006F470: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8006F474: sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // 0x8006F478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F47C: lh          $a1, 0x40($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X40));
    // 0x8006F480: jal         0x800B2FB0
    // 0x8006F484: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    getnextweapon(rdram, ctx);
        goto after_2;
    // 0x8006F484: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_2:
    // 0x8006F488: sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // 0x8006F48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006F490: lh          $a1, 0x42($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X42));
    // 0x8006F494: jal         0x800B2FB0
    // 0x8006F498: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    getnextweapon(rdram, ctx);
        goto after_3;
    // 0x8006F498: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8006F49C: lh          $t1, 0x374($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0X374));
    // 0x8006F4A0: lh          $t5, 0x3C($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x8006F4A4: addiu       $t2, $zero, -0x78
    ctx->r10 = ADD32(0, -0X78);
    // 0x8006F4A8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8006F4AC: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8006F4B0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8006F4B4: subu        $a2, $t2, $t1
    ctx->r6 = SUB32(ctx->r10, ctx->r9);
    // 0x8006F4B8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8006F4BC: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x8006F4C0: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x8006F4C4: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006F4C8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006F4CC: sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
    // 0x8006F4D0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8006F4D4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8006F4D8: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8006F4DC: jal         0x8006F180
    // 0x8006F4E0: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    displayinvsprite(rdram, ctx);
        goto after_4;
    // 0x8006F4E0: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    after_4:
    // 0x8006F4E4: lh          $t9, 0x374($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X374));
    // 0x8006F4E8: lh          $t3, 0x3E($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X3E));
    // 0x8006F4EC: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x8006F4F0: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8006F4F4: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8006F4F8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8006F4FC: subu        $a2, $t0, $t9
    ctx->r6 = SUB32(ctx->r8, ctx->r25);
    // 0x8006F500: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8006F504: addu        $a3, $a3, $t4
    ctx->r7 = ADD32(ctx->r7, ctx->r12);
    // 0x8006F508: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x8006F50C: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006F510: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006F514: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8006F518: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8006F51C: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8006F520: jal         0x8006F180
    // 0x8006F524: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    displayinvsprite(rdram, ctx);
        goto after_5;
    // 0x8006F524: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    after_5:
    // 0x8006F528: lh          $t7, 0x374($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X374));
    // 0x8006F52C: lh          $t2, 0x40($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X40));
    // 0x8006F530: addiu       $t8, $zero, -0x3C
    ctx->r24 = ADD32(0, -0X3C);
    // 0x8006F534: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8006F538: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8006F53C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8006F540: subu        $a2, $t8, $t7
    ctx->r6 = SUB32(ctx->r24, ctx->r15);
    // 0x8006F544: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x8006F548: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x8006F54C: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8006F550: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006F554: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006F558: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8006F55C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8006F560: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8006F564: jal         0x8006F180
    // 0x8006F568: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    displayinvsprite(rdram, ctx);
        goto after_6;
    // 0x8006F568: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    after_6:
    // 0x8006F56C: lh          $t5, 0x374($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X374));
    // 0x8006F570: lh          $t0, 0x42($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X42));
    // 0x8006F574: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8006F578: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8006F57C: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8006F580: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8006F584: subu        $a2, $t6, $t5
    ctx->r6 = SUB32(ctx->r14, ctx->r13);
    // 0x8006F588: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x8006F58C: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x8006F590: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8006F594: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006F598: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006F59C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8006F5A0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8006F5A4: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006F5A8: jal         0x8006F180
    // 0x8006F5AC: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    displayinvsprite(rdram, ctx);
        goto after_7;
    // 0x8006F5AC: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    after_7:
    // 0x8006F5B0: lh          $a2, 0x374($s0)
    ctx->r6 = S32(MEM_H(ctx->r16, 0X374));
    // 0x8006F5B4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8006F5B8: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8006F5BC: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x8006F5C0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8006F5C4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x8006F5C8: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x8006F5CC: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x8006F5D0: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006F5D4: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006F5D8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8006F5DC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8006F5E0: lhu         $a3, -0x5050($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X5050);
    // 0x8006F5E4: jal         0x8006F180
    // 0x8006F5E8: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    displayinvsprite(rdram, ctx);
        goto after_8;
    // 0x8006F5E8: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    after_8:
L_8006F5EC:
    // 0x8006F5EC: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8006F5F0: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8006F5F4: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8006F5F8: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8006F5FC: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8006F600: jr          $ra
    // 0x8006F604: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006F604: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void lotsofcolourglass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AB30: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8009AB34: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8009AB38: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8009AB3C: lh          $t3, -0x9DC($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X9DC));
    // 0x8009AB40: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8009AB44: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x8009AB48: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8009AB4C: div         $zero, $t8, $t4
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r12)));
    // 0x8009AB50: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8009AB54: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009AB58: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x8009AB5C: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8009AB60: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8009AB64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8009AB68: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8009AB6C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8009AB70: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8009AB74: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8009AB78: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8009AB7C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8009AB80: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8009AB84: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8009AB88: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8009AB8C: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8009AB90: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x8009AB94: sh          $t9, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r25;
    // 0x8009AB98: bne         $t4, $zero, L_8009ABA4
    if (ctx->r12 != 0) {
        // 0x8009AB9C: nop
    
            goto L_8009ABA4;
    }
    // 0x8009AB9C: nop

    // 0x8009ABA0: break       7
    do_break(2148117408);
L_8009ABA4:
    // 0x8009ABA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009ABA8: bne         $t4, $at, L_8009ABBC
    if (ctx->r12 != ctx->r1) {
        // 0x8009ABAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009ABBC;
    }
    // 0x8009ABAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009ABB0: bne         $a2, $at, L_8009ABBC
    if (ctx->r6 != ctx->r1) {
        // 0x8009ABB4: nop
    
            goto L_8009ABBC;
    }
    // 0x8009ABB4: nop

    // 0x8009ABB8: break       6
    do_break(2148117432);
L_8009ABBC:
    // 0x8009ABBC: mflo        $a2
    ctx->r6 = lo;
    // 0x8009ABC0: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x8009ABC4: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8009ABC8: bgez        $s0, L_8009AD08
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8009ABCC: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8009AD08;
    }
    // 0x8009ABCC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8009ABD0: addiu       $s4, $t6, -0x1
    ctx->r20 = ADD32(ctx->r14, -0X1);
    // 0x8009ABD4: bltz        $s4, L_8009AF60
    if (SIGNED(ctx->r20) < 0) {
        // 0x8009ABD8: lh          $t7, 0xAA($sp)
        ctx->r15 = S32(MEM_H(ctx->r29, 0XAA));
            goto L_8009AF60;
    }
    // 0x8009ABD8: lh          $t7, 0xAA($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XAA));
    // 0x8009ABDC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009ABE0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8009ABE4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8009ABE8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8009ABEC: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x8009ABF0: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x8009ABF4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8009ABF8: lui         $fp, 0x8024
    ctx->r30 = S32(0X8024 << 16);
    // 0x8009ABFC: addiu       $fp, $fp, 0x6BA8
    ctx->r30 = ADD32(ctx->r30, 0X6BA8);
    // 0x8009AC00: addu        $s3, $t8, $t9
    ctx->r19 = ADD32(ctx->r24, ctx->r25);
    // 0x8009AC04: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x8009AC08: addiu       $s5, $zero, 0x400
    ctx->r21 = ADD32(0, 0X400);
L_8009AC0C:
    // 0x8009AC0C: jal         0x8009800C
    // 0x8009AC10: nop

    krand2(rdram, ctx);
        goto after_0;
    // 0x8009AC10: nop

    after_0:
    // 0x8009AC14: andi        $s2, $v0, 0x7FF
    ctx->r18 = ctx->r2 & 0X7FF;
    // 0x8009AC18: sll         $t3, $s2, 16
    ctx->r11 = S32(ctx->r18 << 16);
    // 0x8009AC1C: jal         0x8009800C
    // 0x8009AC20: sra         $s2, $t3, 16
    ctx->r18 = S32(SIGNED(ctx->r11) >> 16);
    krand2(rdram, ctx);
        goto after_1;
    // 0x8009AC20: sra         $s2, $t3, 16
    ctx->r18 = S32(SIGNED(ctx->r11) >> 16);
    after_1:
    // 0x8009AC24: jal         0x8009800C
    // 0x8009AC28: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_2;
    // 0x8009AC28: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_2:
    // 0x8009AC2C: jal         0x8009800C
    // 0x8009AC30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_3;
    // 0x8009AC30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_3:
    // 0x8009AC34: div         $zero, $s4, $s7
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r23)));
    // 0x8009AC38: lw          $t5, 0x8($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X8));
    // 0x8009AC3C: mfhi        $t7
    ctx->r15 = hi;
    // 0x8009AC40: addiu       $t8, $t7, 0x407
    ctx->r24 = ADD32(ctx->r15, 0X407);
    // 0x8009AC44: andi        $t6, $s1, 0x3F00
    ctx->r14 = ctx->r17 & 0X3F00;
    // 0x8009AC48: addiu       $t9, $zero, -0x20
    ctx->r25 = ADD32(0, -0X20);
    // 0x8009AC4C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009AC50: addiu       $t3, $zero, 0x24
    ctx->r11 = ADD32(0, 0X24);
    // 0x8009AC54: subu        $a3, $t5, $t6
    ctx->r7 = SUB32(ctx->r13, ctx->r14);
    // 0x8009AC58: lh          $t9, 0xAA($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XAA));
    // 0x8009AC5C: andi        $t5, $s0, 0x3F
    ctx->r13 = ctx->r16 & 0X3F;
    // 0x8009AC60: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8009AC64: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009AC68: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x8009AC6C: subu        $t8, $s5, $t7
    ctx->r24 = SUB32(ctx->r21, ctx->r15);
    // 0x8009AC70: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8009AC74: addiu       $t6, $t5, 0x20
    ctx->r14 = ADD32(ctx->r13, 0X20);
    // 0x8009AC78: addiu       $t4, $zero, 0x24
    ctx->r12 = ADD32(0, 0X24);
    // 0x8009AC7C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8009AC80: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8009AC84: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8009AC88: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8009AC8C: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x8009AC90: lw          $a1, 0x0($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X0));
    // 0x8009AC94: lw          $a2, 0x4($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X4));
    // 0x8009AC98: bne         $s7, $zero, L_8009ACA4
    if (ctx->r23 != 0) {
        // 0x8009AC9C: nop
    
            goto L_8009ACA4;
    }
    // 0x8009AC9C: nop

    // 0x8009ACA0: break       7
    do_break(2148117664);
L_8009ACA4:
    // 0x8009ACA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009ACA8: bne         $s7, $at, L_8009ACBC
    if (ctx->r23 != ctx->r1) {
        // 0x8009ACAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009ACBC;
    }
    // 0x8009ACAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009ACB0: bne         $s4, $at, L_8009ACBC
    if (ctx->r20 != ctx->r1) {
        // 0x8009ACB4: nop
    
            goto L_8009ACBC;
    }
    // 0x8009ACB4: nop

    // 0x8009ACB8: break       6
    do_break(2148117688);
L_8009ACBC:
    // 0x8009ACBC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009ACC0: jal         0x8009B028
    // 0x8009ACC4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    EGS(rdram, ctx);
        goto after_4;
    // 0x8009ACC4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_4:
    // 0x8009ACC8: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8009ACCC: sra         $t4, $s0, 16
    ctx->r12 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8009ACD0: jal         0x8009800C
    // 0x8009ACD4: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    krand2(rdram, ctx);
        goto after_5;
    // 0x8009ACD4: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    after_5:
    // 0x8009ACD8: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8009ACDC: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8009ACE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009ACE4: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8009ACE8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009ACEC: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x8009ACF0: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8009ACF4: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x8009ACF8: bgez        $s4, L_8009AC0C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x8009ACFC: sb          $t5, 0x25($t7)
        MEM_B(0X25, ctx->r15) = ctx->r13;
            goto L_8009AC0C;
    }
    // 0x8009ACFC: sb          $t5, 0x25($t7)
    MEM_B(0X25, ctx->r15) = ctx->r13;
    // 0x8009AD00: b           L_8009AF64
    // 0x8009AD04: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
        goto L_8009AF64;
    // 0x8009AD04: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
L_8009AD08:
    // 0x8009AD08: addiu       $t2, $zero, 0x24
    ctx->r10 = ADD32(0, 0X24);
    // 0x8009AD0C: multu       $s0, $t2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009AD10: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x8009AD14: addiu       $t1, $t1, 0x61A8
    ctx->r9 = ADD32(ctx->r9, 0X61A8);
    // 0x8009AD18: addiu       $a3, $a2, 0x1
    ctx->r7 = ADD32(ctx->r6, 0X1);
    // 0x8009AD1C: lui         $fp, 0x8024
    ctx->r30 = S32(0X8024 << 16);
    // 0x8009AD20: addiu       $fp, $fp, 0x6BA8
    ctx->r30 = ADD32(ctx->r30, 0X6BA8);
    // 0x8009AD24: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8009AD28: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x8009AD2C: mflo        $t8
    ctx->r24 = lo;
    // 0x8009AD30: addu        $v0, $t1, $t8
    ctx->r2 = ADD32(ctx->r9, ctx->r24);
    // 0x8009AD34: lh          $t9, 0x8($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X8));
    // 0x8009AD38: lw          $v1, 0x0($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8009AD3C: lw          $a0, 0x4($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X4));
    // 0x8009AD40: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009AD44: lh          $t9, 0xAA($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XAA));
    // 0x8009AD48: or          $s5, $v1, $zero
    ctx->r21 = ctx->r3 | 0;
    // 0x8009AD4C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8009AD50: mflo        $t3
    ctx->r11 = lo;
    // 0x8009AD54: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    // 0x8009AD58: lw          $t4, 0x0($a1)
    ctx->r12 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8009AD5C: lw          $t5, 0x4($a1)
    ctx->r13 = S32(MEM_W(ctx->r5, 0X4));
    // 0x8009AD60: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8009AD64: subu        $t6, $t4, $v1
    ctx->r14 = SUB32(ctx->r12, ctx->r3);
    // 0x8009AD68: div         $zero, $t6, $a3
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r7)));
    // 0x8009AD6C: subu        $t7, $t5, $a0
    ctx->r15 = SUB32(ctx->r13, ctx->r4);
    // 0x8009AD70: mflo        $t0
    ctx->r8 = lo;
    // 0x8009AD74: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8009AD78: bne         $a3, $zero, L_8009AD84
    if (ctx->r7 != 0) {
        // 0x8009AD7C: nop
    
            goto L_8009AD84;
    }
    // 0x8009AD7C: nop

    // 0x8009AD80: break       7
    do_break(2148117888);
L_8009AD84:
    // 0x8009AD84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009AD88: bne         $a3, $at, L_8009AD9C
    if (ctx->r7 != ctx->r1) {
        // 0x8009AD8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009AD9C;
    }
    // 0x8009AD8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009AD90: bne         $t6, $at, L_8009AD9C
    if (ctx->r14 != ctx->r1) {
        // 0x8009AD94: nop
    
            goto L_8009AD9C;
    }
    // 0x8009AD94: nop

    // 0x8009AD98: break       6
    do_break(2148117912);
L_8009AD9C:
    // 0x8009AD9C: div         $zero, $t7, $a3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r7)));
    // 0x8009ADA0: mflo        $t8
    ctx->r24 = lo;
    // 0x8009ADA4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8009ADA8: bne         $a3, $zero, L_8009ADB4
    if (ctx->r7 != 0) {
        // 0x8009ADAC: nop
    
            goto L_8009ADB4;
    }
    // 0x8009ADAC: nop

    // 0x8009ADB0: break       7
    do_break(2148117936);
L_8009ADB4:
    // 0x8009ADB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009ADB8: bne         $a3, $at, L_8009ADCC
    if (ctx->r7 != ctx->r1) {
        // 0x8009ADBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009ADCC;
    }
    // 0x8009ADBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009ADC0: bne         $t7, $at, L_8009ADCC
    if (ctx->r15 != ctx->r1) {
        // 0x8009ADC4: nop
    
            goto L_8009ADCC;
    }
    // 0x8009ADC4: nop

    // 0x8009ADC8: break       6
    do_break(2148117960);
L_8009ADCC:
    // 0x8009ADCC: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8009ADD0: blez        $a2, L_8009AF60
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8009ADD4: subu        $t3, $t3, $t9
        ctx->r11 = SUB32(ctx->r11, ctx->r25);
            goto L_8009AF60;
    }
    // 0x8009ADD4: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8009ADD8: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x8009ADDC: addiu       $t4, $t4, 0x6BA8
    ctx->r12 = ADD32(ctx->r12, 0X6BA8);
    // 0x8009ADE0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8009ADE4: addu        $s3, $t3, $t4
    ctx->r19 = ADD32(ctx->r11, ctx->r12);
    // 0x8009ADE8: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
L_8009ADEC:
    // 0x8009ADEC: lw          $t0, 0xA0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x8009ADF0: lw          $t6, 0x9C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x8009ADF4: addiu       $a2, $sp, 0x8E
    ctx->r6 = ADD32(ctx->r29, 0X8E);
    // 0x8009ADF8: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x8009ADFC: addu        $s6, $s6, $t6
    ctx->r22 = ADD32(ctx->r22, ctx->r14);
    // 0x8009AE00: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8009AE04: jal         0x80097DB8
    // 0x8009AE08: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    updatesector(rdram, ctx);
        goto after_6;
    // 0x8009AE08: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x8009AE0C: jal         0x8009800C
    // 0x8009AE10: nop

    krand2(rdram, ctx);
        goto after_7;
    // 0x8009AE10: nop

    after_7:
    // 0x8009AE14: lh          $t5, 0x8E($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X8E));
    // 0x8009AE18: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8009AE1C: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x8009AE20: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8009AE24: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8009AE28: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8009AE2C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8009AE30: lw          $a1, 0x4($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X4));
    // 0x8009AE34: lw          $t9, 0x0($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8009AE38: subu        $a0, $t9, $a1
    ctx->r4 = SUB32(ctx->r25, ctx->r5);
    // 0x8009AE3C: blez        $a0, L_8009AE4C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8009AE40: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8009AE4C;
    }
    // 0x8009AE40: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8009AE44: b           L_8009AE4C
    // 0x8009AE48: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_8009AE4C;
    // 0x8009AE48: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8009AE4C:
    // 0x8009AE4C: and         $t3, $v1, $v0
    ctx->r11 = ctx->r3 & ctx->r2;
    // 0x8009AE50: subu        $s1, $a1, $t3
    ctx->r17 = SUB32(ctx->r5, ctx->r11);
    // 0x8009AE54: slti        $at, $s1, -0x2000
    ctx->r1 = SIGNED(ctx->r17) < -0X2000 ? 1 : 0;
    // 0x8009AE58: bne         $at, $zero, L_8009AE68
    if (ctx->r1 != 0) {
        // 0x8009AE5C: slti        $at, $s1, 0x2001
        ctx->r1 = SIGNED(ctx->r17) < 0X2001 ? 1 : 0;
            goto L_8009AE68;
    }
    // 0x8009AE5C: slti        $at, $s1, 0x2001
    ctx->r1 = SIGNED(ctx->r17) < 0X2001 ? 1 : 0;
    // 0x8009AE60: bnel        $at, $zero, L_8009AE84
    if (ctx->r1 != 0) {
        // 0x8009AE64: lh          $s2, 0x14($s3)
        ctx->r18 = S32(MEM_H(ctx->r19, 0X14));
            goto L_8009AE84;
    }
    goto skip_0;
    // 0x8009AE64: lh          $s2, 0x14($s3)
    ctx->r18 = S32(MEM_H(ctx->r19, 0X14));
    skip_0:
L_8009AE68:
    // 0x8009AE68: jal         0x8009800C
    // 0x8009AE6C: nop

    krand2(rdram, ctx);
        goto after_8;
    // 0x8009AE6C: nop

    after_8:
    // 0x8009AE70: lw          $t6, 0x8($s3)
    ctx->r14 = S32(MEM_W(ctx->r19, 0X8));
    // 0x8009AE74: andi        $t4, $v0, 0x3FFF
    ctx->r12 = ctx->r2 & 0X3FFF;
    // 0x8009AE78: addu        $s1, $t4, $t6
    ctx->r17 = ADD32(ctx->r12, ctx->r14);
    // 0x8009AE7C: addiu       $s1, $s1, -0x2000
    ctx->r17 = ADD32(ctx->r17, -0X2000);
    // 0x8009AE80: lh          $s2, 0x14($s3)
    ctx->r18 = S32(MEM_H(ctx->r19, 0X14));
L_8009AE84:
    // 0x8009AE84: addiu       $s2, $s2, -0x400
    ctx->r18 = ADD32(ctx->r18, -0X400);
    // 0x8009AE88: sll         $t5, $s2, 16
    ctx->r13 = S32(ctx->r18 << 16);
    // 0x8009AE8C: jal         0x8009800C
    // 0x8009AE90: sra         $s2, $t5, 16
    ctx->r18 = S32(SIGNED(ctx->r13) >> 16);
    krand2(rdram, ctx);
        goto after_9;
    // 0x8009AE90: sra         $s2, $t5, 16
    ctx->r18 = S32(SIGNED(ctx->r13) >> 16);
    after_9:
    // 0x8009AE94: jal         0x8009800C
    // 0x8009AE98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_10;
    // 0x8009AE98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_10:
    // 0x8009AE9C: div         $zero, $s4, $s7
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r23)));
    // 0x8009AEA0: mfhi        $t8
    ctx->r24 = hi;
    // 0x8009AEA4: addiu       $t9, $t8, 0x407
    ctx->r25 = ADD32(ctx->r24, 0X407);
    // 0x8009AEA8: addiu       $t3, $zero, -0x20
    ctx->r11 = ADD32(0, -0X20);
    // 0x8009AEAC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009AEB0: addiu       $t4, $zero, 0x24
    ctx->r12 = ADD32(0, 0X24);
    // 0x8009AEB4: lh          $t3, 0xAA($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0XAA));
    // 0x8009AEB8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8009AEBC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009AEC0: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x8009AEC4: andi        $t5, $s0, 0x3F
    ctx->r13 = ctx->r16 & 0X3F;
    // 0x8009AEC8: addiu       $t7, $t5, 0x20
    ctx->r15 = ADD32(ctx->r13, 0X20);
    // 0x8009AECC: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8009AED0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8009AED4: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8009AED8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8009AEDC: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8009AEE0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8009AEE4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8009AEE8: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x8009AEEC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8009AEF0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8009AEF4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8009AEF8: bne         $s7, $zero, L_8009AF04
    if (ctx->r23 != 0) {
        // 0x8009AEFC: nop
    
            goto L_8009AF04;
    }
    // 0x8009AEFC: nop

    // 0x8009AF00: break       7
    do_break(2148118272);
L_8009AF04:
    // 0x8009AF04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009AF08: bne         $s7, $at, L_8009AF1C
    if (ctx->r23 != ctx->r1) {
        // 0x8009AF0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8009AF1C;
    }
    // 0x8009AF0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009AF10: bne         $s4, $at, L_8009AF1C
    if (ctx->r20 != ctx->r1) {
        // 0x8009AF14: nop
    
            goto L_8009AF1C;
    }
    // 0x8009AF14: nop

    // 0x8009AF18: break       6
    do_break(2148118296);
L_8009AF1C:
    // 0x8009AF1C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009AF20: jal         0x8009B028
    // 0x8009AF24: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    EGS(rdram, ctx);
        goto after_11;
    // 0x8009AF24: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_11:
    // 0x8009AF28: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8009AF2C: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8009AF30: jal         0x8009800C
    // 0x8009AF34: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    krand2(rdram, ctx);
        goto after_12;
    // 0x8009AF34: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    after_12:
    // 0x8009AF38: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8009AF3C: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8009AF40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8009AF44: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8009AF48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8009AF4C: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x8009AF50: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x8009AF54: andi        $t5, $v0, 0x7
    ctx->r13 = ctx->r2 & 0X7;
    // 0x8009AF58: bne         $s4, $zero, L_8009ADEC
    if (ctx->r20 != 0) {
        // 0x8009AF5C: sb          $t5, 0x25($t8)
        MEM_B(0X25, ctx->r24) = ctx->r13;
            goto L_8009ADEC;
    }
    // 0x8009AF5C: sb          $t5, 0x25($t8)
    MEM_B(0X25, ctx->r24) = ctx->r13;
L_8009AF60:
    // 0x8009AF60: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
L_8009AF64:
    // 0x8009AF64: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8009AF68: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8009AF6C: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8009AF70: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8009AF74: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x8009AF78: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8009AF7C: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x8009AF80: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x8009AF84: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x8009AF88: jr          $ra
    // 0x8009AF8C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8009AF8C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void divscale16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800914A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800914A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800914AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800914B0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800914B4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800914B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800914BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800914C0: jal         0x800BB834
    // 0x800914C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800914C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800914C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800914CC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800914D0: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800914D4: jal         0x800BB89C
    // 0x800914D8: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800914D8: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x800914DC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800914E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800914E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800914E8: jr          $ra
    // 0x800914EC: nop

    return;
    // 0x800914EC: nop

;}
RECOMP_FUNC void func_80066170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066170: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066174: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x80066178: addiu       $a3, $a3, -0x28F8
    ctx->r7 = ADD32(ctx->r7, -0X28F8);
    // 0x8006617C: addiu       $t1, $t1, -0x5A18
    ctx->r9 = ADD32(ctx->r9, -0X5A18);
    // 0x80066180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80066184: addiu       $t0, $zero, 0x16
    ctx->r8 = ADD32(0, 0X16);
L_80066188:
    // 0x80066188: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006618C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066190: mflo        $t6
    ctx->r14 = lo;
    // 0x80066194: addu        $v1, $a3, $t6
    ctx->r3 = ADD32(ctx->r7, ctx->r14);
    // 0x80066198: lb          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_B(ctx->r3, 0X0));
    // 0x8006619C: beql        $t7, $zero, L_80066238
    if (ctx->r15 == 0) {
        // 0x800661A0: sll         $t3, $v0, 16
        ctx->r11 = S32(ctx->r2 << 16);
            goto L_80066238;
    }
    goto skip_0;
    // 0x800661A0: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    skip_0:
    // 0x800661A4: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x800661A8: lh          $a1, 0x12($v1)
    ctx->r5 = S32(MEM_H(ctx->r3, 0X12));
    // 0x800661AC: lh          $t2, 0xA($v1)
    ctx->r10 = S32(MEM_H(ctx->r3, 0XA));
    // 0x800661B0: lh          $a0, 0x14($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X14));
    // 0x800661B4: lh          $t8, 0xC($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0XC));
    // 0x800661B8: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x800661BC: addu        $a2, $t1, $t5
    ctx->r6 = ADD32(ctx->r9, ctx->r13);
    // 0x800661C0: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x800661C4: lh          $t6, 0x18($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0X18));
    // 0x800661C8: lhu         $t2, 0xE($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XE);
    // 0x800661CC: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x800661D0: lh          $t8, 0x8($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0X8));
    // 0x800661D4: lhu         $t4, 0x10($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X10);
    // 0x800661D8: sh          $t3, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r11;
    // 0x800661DC: sh          $t9, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r25;
    // 0x800661E0: subu        $t7, $a0, $t6
    ctx->r15 = SUB32(ctx->r4, ctx->r14);
    // 0x800661E4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800661E8: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800661EC: subu        $t9, $a1, $t8
    ctx->r25 = SUB32(ctx->r5, ctx->r24);
    // 0x800661F0: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800661F4: sh          $t7, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r15;
    // 0x800661F8: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
    // 0x800661FC: sh          $t3, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r11;
    // 0x80066200: bne         $t6, $zero, L_8006620C
    if (ctx->r14 != 0) {
        // 0x80066204: sh          $t5, 0x10($v1)
        MEM_H(0X10, ctx->r3) = ctx->r13;
            goto L_8006620C;
    }
    // 0x80066204: sh          $t5, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r13;
    // 0x80066208: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
L_8006620C:
    // 0x8006620C: lhu         $t7, 0x10($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X10);
    // 0x80066210: bnel        $t7, $zero, L_80066220
    if (ctx->r15 != 0) {
        // 0x80066214: lbu         $t8, 0x3($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X3);
            goto L_80066220;
    }
    goto skip_1;
    // 0x80066214: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    skip_1:
    // 0x80066218: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8006621C: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
L_80066220:
    // 0x80066220: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x80066224: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80066228: bnel        $t2, $zero, L_80066238
    if (ctx->r10 != 0) {
        // 0x8006622C: sll         $t3, $v0, 16
        ctx->r11 = S32(ctx->r2 << 16);
            goto L_80066238;
    }
    goto skip_2;
    // 0x8006622C: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    skip_2:
    // 0x80066230: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80066234: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
L_80066238:
    // 0x80066238: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8006623C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80066240: bne         $at, $zero, L_80066188
    if (ctx->r1 != 0) {
        // 0x80066244: nop
    
            goto L_80066188;
    }
    // 0x80066244: nop

    // 0x80066248: jr          $ra
    // 0x8006624C: nop

    return;
    // 0x8006624C: nop

;}
RECOMP_FUNC void func_80062804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062804: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80062808: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8006280C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80062810: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80062814: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x80062818: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8006281C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062820: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80062824: lhu         $s1, 0x1E($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X1E);
    // 0x80062828: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x8006282C: lbu         $t9, 0x27($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X27);
    // 0x80062830: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80062834: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80062838: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006283C: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x80062840: addu        $s1, $t8, $at
    ctx->r17 = ADD32(ctx->r24, ctx->r1);
    // 0x80062844: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80062848: sb          $t9, -0x298C($at)
    MEM_B(-0X298C, ctx->r1) = ctx->r25;
    // 0x8006284C: lb          $t0, 0x26($v0)
    ctx->r8 = S32(MEM_B(ctx->r2, 0X26));
    // 0x80062850: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062854: lui         $s7, 0x8022
    ctx->r23 = S32(0X8022 << 16);
    // 0x80062858: addiu       $s7, $s7, -0x234C
    ctx->r23 = ADD32(ctx->r23, -0X234C);
    // 0x8006285C: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x80062860: sw          $t0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r8;
    // 0x80062864: sw          $zero, -0x3C70($at)
    MEM_W(-0X3C70, ctx->r1) = 0;
    // 0x80062868: lbu         $t1, 0x2B($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2B);
    // 0x8006286C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80062870: lui         $fp, 0x8026
    ctx->r30 = S32(0X8026 << 16);
    // 0x80062874: addiu       $fp, $fp, -0x3C76
    ctx->r30 = ADD32(ctx->r30, -0X3C76);
    // 0x80062878: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006287C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062880: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80062884: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062888: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006288C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062890: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062894: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
    // 0x80062898: blez        $t1, L_80062A90
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8006289C: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80062A90;
    }
    // 0x8006289C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800628A0: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x800628A4: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x800628A8: lui         $s2, 0x8022
    ctx->r18 = S32(0X8022 << 16);
    // 0x800628AC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800628B0: addiu       $s0, $s0, -0x537C
    ctx->r16 = ADD32(ctx->r16, -0X537C);
    // 0x800628B4: addiu       $s2, $s2, -0x2980
    ctx->r18 = ADD32(ctx->r18, -0X2980);
    // 0x800628B8: addiu       $s3, $s3, -0x2958
    ctx->r19 = ADD32(ctx->r19, -0X2958);
    // 0x800628BC: addiu       $s4, $s4, -0x2930
    ctx->r20 = ADD32(ctx->r20, -0X2930);
    // 0x800628C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800628C4: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x800628C8: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
L_800628CC:
    // 0x800628CC: lh          $a1, 0x2($s1)
    ctx->r5 = S32(MEM_H(ctx->r17, 0X2));
    // 0x800628D0: lh          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_H(ctx->r17, 0X4));
    // 0x800628D4: jal         0x80062D98
    // 0x800628D8: lh          $a3, 0x2($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X2));
    func_80062D98(rdram, ctx);
        goto after_0;
    // 0x800628D8: lh          $a3, 0x2($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X2));
    after_0:
    // 0x800628DC: lh          $t2, 0x0($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, 0X0));
    // 0x800628E0: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800628E4: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x800628E8: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x800628EC: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800628F0: lh          $t4, -0x8($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, -0X8));
    // 0x800628F4: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x800628F8: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800628FC: lh          $t6, -0x6($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, -0X6));
    // 0x80062900: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
    // 0x80062904: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062908: lh          $t8, -0x4($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, -0X4));
    // 0x8006290C: sh          $t8, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r24;
    // 0x80062910: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062914: lh          $t0, -0x2($s1)
    ctx->r8 = S32(MEM_H(ctx->r17, -0X2));
    // 0x80062918: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    // 0x8006291C: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062920: lw          $t2, 0x0($s2)
    ctx->r10 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80062924: sb          $t2, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r10;
    // 0x80062928: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006292C: lw          $t4, 0x0($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80062930: sb          $t4, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r12;
    // 0x80062934: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062938: lw          $t6, 0x0($s4)
    ctx->r14 = S32(MEM_W(ctx->r20, 0X0));
    // 0x8006293C: sb          $t6, 0xE($t7)
    MEM_B(0XE, ctx->r15) = ctx->r14;
    // 0x80062940: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062944: sb          $s5, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r21;
    // 0x80062948: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006294C: lh          $a3, 0x2($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X2));
    // 0x80062950: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80062954: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80062958: lh          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_H(ctx->r17, 0X4));
    // 0x8006295C: lh          $a1, 0x2($s1)
    ctx->r5 = S32(MEM_H(ctx->r17, 0X2));
    // 0x80062960: jal         0x80062D98
    // 0x80062964: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    func_80062D98(rdram, ctx);
        goto after_1;
    // 0x80062964: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    after_1:
    // 0x80062968: lh          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_H(ctx->r17, 0X0));
    // 0x8006296C: lw          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062970: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80062974: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80062978: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006297C: lh          $t3, -0x8($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, -0X8));
    // 0x80062980: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x80062984: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062988: lh          $t5, -0x6($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, -0X6));
    // 0x8006298C: sh          $t5, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r13;
    // 0x80062990: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062994: lh          $t7, -0x4($s1)
    ctx->r15 = S32(MEM_H(ctx->r17, -0X4));
    // 0x80062998: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x8006299C: lw          $t0, 0x0($s0)
    ctx->r8 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800629A0: lh          $t9, -0x2($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, -0X2));
    // 0x800629A4: sh          $t9, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r25;
    // 0x800629A8: lw          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800629AC: lw          $t1, 0x0($s2)
    ctx->r9 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800629B0: sb          $t1, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r9;
    // 0x800629B4: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800629B8: lw          $t3, 0x0($s3)
    ctx->r11 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800629BC: sb          $t3, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r11;
    // 0x800629C0: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800629C4: lw          $t5, 0x0($s4)
    ctx->r13 = S32(MEM_W(ctx->r20, 0X0));
    // 0x800629C8: sb          $t5, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r13;
    // 0x800629CC: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800629D0: sb          $s5, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r21;
    // 0x800629D4: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800629D8: lh          $a3, 0x2($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X2));
    // 0x800629DC: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800629E0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800629E4: lh          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_H(ctx->r17, 0X4));
    // 0x800629E8: lh          $a1, 0x2($s1)
    ctx->r5 = S32(MEM_H(ctx->r17, 0X2));
    // 0x800629EC: jal         0x80062D98
    // 0x800629F0: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    func_80062D98(rdram, ctx);
        goto after_2;
    // 0x800629F0: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    after_2:
    // 0x800629F4: lh          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_H(ctx->r17, 0X0));
    // 0x800629F8: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800629FC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80062A00: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80062A04: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x80062A08: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A0C: lh          $t2, -0x8($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, -0X8));
    // 0x80062A10: sh          $t2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r10;
    // 0x80062A14: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A18: lh          $t4, -0x6($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, -0X6));
    // 0x80062A1C: sh          $t4, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r12;
    // 0x80062A20: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A24: lh          $t6, -0x4($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, -0X4));
    // 0x80062A28: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80062A2C: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A30: lh          $t8, -0x2($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, -0X2));
    // 0x80062A34: sh          $t8, 0xA($t9)
    MEM_H(0XA, ctx->r25) = ctx->r24;
    // 0x80062A38: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A3C: lw          $t0, 0x0($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80062A40: sb          $t0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r8;
    // 0x80062A44: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A48: lw          $t2, 0x0($s3)
    ctx->r10 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80062A4C: sb          $t2, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r10;
    // 0x80062A50: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A54: lw          $t4, 0x0($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X0));
    // 0x80062A58: sb          $t4, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r12;
    // 0x80062A5C: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A60: sb          $s5, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r21;
    // 0x80062A64: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80062A68: lh          $t9, 0x0($fp)
    ctx->r25 = S32(MEM_H(ctx->r30, 0X0));
    // 0x80062A6C: lw          $t1, 0x44($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80062A70: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80062A74: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80062A78: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80062A7C: sh          $t0, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r8;
    // 0x80062A80: lbu         $t2, 0x2B($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2B);
    // 0x80062A84: slt         $at, $s6, $t2
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80062A88: bnel        $at, $zero, L_800628CC
    if (ctx->r1 != 0) {
        // 0x80062A8C: lh          $a0, 0x0($s1)
        ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
            goto L_800628CC;
    }
    goto skip_0;
    // 0x80062A8C: lh          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X0));
    skip_0:
L_80062A90:
    // 0x80062A90: lh          $t3, 0x0($fp)
    ctx->r11 = S32(MEM_H(ctx->r30, 0X0));
    // 0x80062A94: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80062A98: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x80062A9C: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80062AA0: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80062AA4: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80062AA8: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80062AAC: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80062AB0: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80062AB4: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80062AB8: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80062ABC: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80062AC0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80062AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80062AC8: jr          $ra
    // 0x80062ACC: sw          $t3, -0x3C70($at)
    MEM_W(-0X3C70, ctx->r1) = ctx->r11;
    return;
    // 0x80062ACC: sw          $t3, -0x3C70($at)
    MEM_W(-0X3C70, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void dragpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009562C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80095630: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80095634: sll         $s4, $a0, 16
    ctx->r20 = S32(ctx->r4 << 16);
    // 0x80095638: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009563C: addiu       $s3, $zero, 0x24
    ctx->r19 = ADD32(0, 0X24);
    // 0x80095640: sra         $t6, $s4, 16
    ctx->r14 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80095644: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095648: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009564C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80095650: sll         $s0, $t6, 16
    ctx->r16 = S32(ctx->r14 << 16);
    // 0x80095654: lui         $s2, 0x8022
    ctx->r18 = S32(0X8022 << 16);
    // 0x80095658: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8009565C: addiu       $s2, $s2, 0x61A8
    ctx->r18 = ADD32(ctx->r18, 0X61A8);
    // 0x80095660: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80095664: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80095668: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009566C: mflo        $t7
    ctx->r15 = lo;
    // 0x80095670: addu        $v0, $s2, $t7
    ctx->r2 = ADD32(ctx->r18, ctx->r15);
    // 0x80095674: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80095678: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009567C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80095680: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80095684: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80095688: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x8009568C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80095690: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80095694: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80095698: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8009569C: addiu       $s1, $zero, 0xE80
    ctx->r17 = ADD32(0, 0XE80);
    // 0x800956A0: addu        $v1, $s2, $t9
    ctx->r3 = ADD32(ctx->r18, ctx->r25);
    // 0x800956A4: lh          $v0, 0xA($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0XA));
L_800956A8:
    // 0x800956A8: bltzl       $v0, L_800956E8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800956AC: sll         $s0, $s4, 16
        ctx->r16 = S32(ctx->r20 << 16);
            goto L_800956E8;
    }
    goto skip_0;
    // 0x800956AC: sll         $s0, $s4, 16
    ctx->r16 = S32(ctx->r20 << 16);
    skip_0:
    // 0x800956B0: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800956B4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800956B8: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x800956BC: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800956C0: mflo        $t0
    ctx->r8 = lo;
    // 0x800956C4: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x800956C8: lh          $s0, 0x8($t1)
    ctx->r16 = S32(MEM_H(ctx->r9, 0X8));
    // 0x800956CC: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800956D0: mflo        $t2
    ctx->r10 = lo;
    // 0x800956D4: addu        $v1, $s2, $t2
    ctx->r3 = ADD32(ctx->r18, ctx->r10);
    // 0x800956D8: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x800956DC: b           L_80095770
    // 0x800956E0: sw          $s6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r22;
        goto L_80095770;
    // 0x800956E0: sw          $s6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r22;
    // 0x800956E4: sll         $s0, $s4, 16
    ctx->r16 = S32(ctx->r20 << 16);
L_800956E8:
    // 0x800956E8: sra         $t3, $s0, 16
    ctx->r11 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800956EC: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x800956F0: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
L_800956F4:
    // 0x800956F4: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800956F8: jal         0x800957A8
    // 0x800956FC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    lastwall(rdram, ctx);
        goto after_0;
    // 0x800956FC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_0:
    // 0x80095700: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095704: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80095708: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009570C: mflo        $t5
    ctx->r13 = lo;
    // 0x80095710: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80095714: lh          $t7, 0xA($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0XA));
    // 0x80095718: bltzl       $t7, L_80095784
    if (SIGNED(ctx->r15) < 0) {
        // 0x8009571C: lw          $ra, 0x34($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
            goto L_80095784;
    }
    goto skip_1;
    // 0x8009571C: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    skip_1:
    // 0x80095720: jal         0x800957A8
    // 0x80095724: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    lastwall(rdram, ctx);
        goto after_1;
    // 0x80095724: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x80095728: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009572C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80095730: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x80095734: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80095738: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x8009573C: mflo        $t9
    ctx->r25 = lo;
    // 0x80095740: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x80095744: lh          $s0, 0xA($t0)
    ctx->r16 = S32(MEM_H(ctx->r8, 0XA));
    // 0x80095748: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009574C: mflo        $t1
    ctx->r9 = lo;
    // 0x80095750: addu        $v1, $s2, $t1
    ctx->r3 = ADD32(ctx->r18, ctx->r9);
    // 0x80095754: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x80095758: beq         $s0, $s4, L_80095780
    if (ctx->r16 == ctx->r20) {
        // 0x8009575C: sw          $s6, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r22;
            goto L_80095780;
    }
    // 0x8009575C: sw          $s6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r22;
    // 0x80095760: bgtzl       $t3, L_800956F4
    if (SIGNED(ctx->r11) > 0) {
        // 0x80095764: sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16 << 16);
            goto L_800956F4;
    }
    goto skip_2;
    // 0x80095764: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    skip_2:
    // 0x80095768: b           L_80095784
    // 0x8009576C: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
        goto L_80095784;
    // 0x8009576C: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
L_80095770:
    // 0x80095770: beq         $s0, $s4, L_80095780
    if (ctx->r16 == ctx->r20) {
        // 0x80095774: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_80095780;
    }
    // 0x80095774: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80095778: bgtzl       $t5, L_800956A8
    if (SIGNED(ctx->r13) > 0) {
        // 0x8009577C: lh          $v0, 0xA($v1)
        ctx->r2 = S32(MEM_H(ctx->r3, 0XA));
            goto L_800956A8;
    }
    goto skip_3;
    // 0x8009577C: lh          $v0, 0xA($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0XA));
    skip_3:
L_80095780:
    // 0x80095780: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
L_80095784:
    // 0x80095784: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80095788: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8009578C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80095790: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80095794: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80095798: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8009579C: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800957A0: jr          $ra
    // 0x800957A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800957A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004D2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D2A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004D2A8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004D2AC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D2B0: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x8004D2B4: addiu       $t9, $t9, -0x6C30
    ctx->r25 = ADD32(ctx->r25, -0X6C30);
    // 0x8004D2B8: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x8004D2BC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8004D2C0: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x8004D2C4: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x8004D2C8: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x8004D2CC: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8004D2D0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004D2D4: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8004D2D8: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8004D2DC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8004D2E0: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x8004D2E4: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x8004D2E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004D2EC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8004D2F0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8004D2F4: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8004D2F8: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x8004D2FC: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8004D300: addiu       $t5, $zero, 0x4000
    ctx->r13 = ADD32(0, 0X4000);
    // 0x8004D304: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8004D308: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x8004D30C: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x8004D310: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8004D314: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8004D318: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8004D31C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004D320: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004D324: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x8004D328: sw          $t5, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r13;
    // 0x8004D32C: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x8004D330: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8004D334: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x8004D338: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x8004D33C: sw          $t0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r8;
    // 0x8004D340: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8004D344: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x8004D348: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x8004D34C: sw          $t2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r10;
    // 0x8004D350: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8004D354: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8004D358: lbu         $t4, 0x5AF6($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X5AF6);
    // 0x8004D35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D360: beql        $t4, $zero, L_8004D374
    if (ctx->r12 == 0) {
        // 0x8004D364: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8004D374;
    }
    goto skip_0;
    // 0x8004D364: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x8004D368: jal         0x8004D664
    // 0x8004D36C: nop

    func_8004D664(rdram, ctx);
        goto after_0;
    // 0x8004D36C: nop

    after_0:
    // 0x8004D370: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004D374:
    // 0x8004D374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D378: jr          $ra
    // 0x8004D37C: nop

    return;
    // 0x8004D37C: nop

;}
RECOMP_FUNC void ifhitbyweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077388: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007738C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80077390: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80077394: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80077398: lui         $t9, 0x8028
    ctx->r25 = S32(0X8028 << 16);
    // 0x8007739C: addiu       $t9, $t9, -0x5C00
    ctx->r25 = ADD32(ctx->r25, -0X5C00);
    // 0x800773A0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800773A4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800773A8: lh          $v0, 0x6($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X6));
    // 0x800773AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800773B0: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800773B4: bltz        $v0, L_8007768C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800773B8: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_8007768C;
    }
    // 0x800773B8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800773BC: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800773C0: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800773C4: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800773C8: mflo        $t4
    ctx->r12 = lo;
    // 0x800773CC: addu        $a1, $t0, $t4
    ctx->r5 = ADD32(ctx->r8, ctx->r12);
    // 0x800773D0: lh          $a2, 0x22($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X22));
    // 0x800773D4: bltzl       $a2, L_80077690
    if (SIGNED(ctx->r6) < 0) {
        // 0x800773D8: sh          $t5, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r13;
            goto L_80077690;
    }
    goto skip_0;
    // 0x800773D8: sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
    skip_0:
    // 0x800773DC: lh          $a0, 0xE($a1)
    ctx->r4 = S32(MEM_H(ctx->r5, 0XE));
    // 0x800773E0: addiu       $t2, $zero, 0x57D
    ctx->r10 = ADD32(0, 0X57D);
    // 0x800773E4: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x800773E8: bne         $t2, $a0, L_80077610
    if (ctx->r10 != ctx->r4) {
        // 0x800773EC: addiu       $t3, $t3, -0x5598
        ctx->r11 = ADD32(ctx->r11, -0X5598);
            goto L_80077610;
    }
    // 0x800773EC: addiu       $t3, $t3, -0x5598
    ctx->r11 = ADD32(ctx->r11, -0X5598);
    // 0x800773F0: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x800773F4: beql        $t5, $zero, L_80077408
    if (ctx->r13 == 0) {
        // 0x800773F8: lh          $a3, 0x8($v1)
        ctx->r7 = S32(MEM_H(ctx->r3, 0X8));
            goto L_80077408;
    }
    goto skip_1;
    // 0x800773F8: lh          $a3, 0x8($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X8));
    skip_1:
    // 0x800773FC: jr          $ra
    // 0x80077400: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80077400: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80077404: lh          $a3, 0x8($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X8));
L_80077408:
    // 0x80077408: lh          $a0, 0x1A($a1)
    ctx->r4 = S32(MEM_H(ctx->r5, 0X1A));
    // 0x8007740C: subu        $t5, $a2, $v0
    ctx->r13 = SUB32(ctx->r6, ctx->r2);
    // 0x80077410: bltz        $a3, L_80077454
    if (SIGNED(ctx->r7) < 0) {
        // 0x80077414: nop
    
            goto L_80077454;
    }
    // 0x80077414: nop

    // 0x80077418: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007741C: mflo        $t6
    ctx->r14 = lo;
    // 0x80077420: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80077424: lh          $t8, 0xE($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0XE));
    // 0x80077428: bne         $t2, $t8, L_80077454
    if (ctx->r10 != ctx->r24) {
        // 0x8007742C: nop
    
            goto L_80077454;
    }
    // 0x8007742C: nop

    // 0x80077430: lw          $t9, 0x13C($t3)
    ctx->r25 = S32(MEM_W(ctx->r11, 0X13C));
    // 0x80077434: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80077438: bne         $t9, $at, L_80077454
    if (ctx->r25 != ctx->r1) {
        // 0x8007743C: nop
    
            goto L_80077454;
    }
    // 0x8007743C: nop

    // 0x80077440: lw          $t4, 0x17C($t3)
    ctx->r12 = S32(MEM_W(ctx->r11, 0X17C));
    // 0x80077444: bne         $t4, $zero, L_80077454
    if (ctx->r12 != 0) {
        // 0x80077448: nop
    
            goto L_80077454;
    }
    // 0x80077448: nop

    // 0x8007744C: jr          $ra
    // 0x80077450: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80077450: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80077454:
    // 0x80077454: bltz        $a3, L_800774DC
    if (SIGNED(ctx->r7) < 0) {
        // 0x80077458: sh          $t5, 0x22($a1)
        MEM_H(0X22, ctx->r5) = ctx->r13;
            goto L_800774DC;
    }
    // 0x80077458: sh          $t5, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r13;
    // 0x8007745C: lh          $t6, 0x22($a1)
    ctx->r14 = S32(MEM_H(ctx->r5, 0X22));
    // 0x80077460: bgtzl       $t6, L_800774E0
    if (SIGNED(ctx->r14) > 0) {
        // 0x80077464: sll         $t5, $a0, 3
        ctx->r13 = S32(ctx->r4 << 3);
            goto L_800774E0;
    }
    goto skip_2;
    // 0x80077464: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    skip_2:
    // 0x80077468: sh          $zero, 0x22($a1)
    MEM_H(0X22, ctx->r5) = 0;
    // 0x8007746C: lh          $t9, 0x8($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X8));
    // 0x80077470: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80077474: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80077478: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007747C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80077480: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80077484: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80077488: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8007748C: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x80077490: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x80077494: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80077498: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8007749C: sh          $a3, 0x2AC($a2)
    MEM_H(0X2AC, ctx->r6) = ctx->r7;
    // 0x800774A0: mflo        $t4
    ctx->r12 = lo;
    // 0x800774A4: addu        $v0, $t0, $t4
    ctx->r2 = ADD32(ctx->r8, ctx->r12);
    // 0x800774A8: lh          $t5, 0xE($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0XE));
    // 0x800774AC: bnel        $t2, $t5, L_800774D8
    if (ctx->r10 != ctx->r13) {
        // 0x800774B0: lh          $t4, 0x2E0($a2)
        ctx->r12 = S32(MEM_H(ctx->r6, 0X2E0));
            goto L_800774D8;
    }
    goto skip_3;
    // 0x800774B0: lh          $t4, 0x2E0($a2)
    ctx->r12 = S32(MEM_H(ctx->r6, 0X2E0));
    skip_3:
    // 0x800774B4: lh          $t6, 0x1A($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X1A));
    // 0x800774B8: beql        $a0, $t6, L_800774D8
    if (ctx->r4 == ctx->r14) {
        // 0x800774BC: lh          $t4, 0x2E0($a2)
        ctx->r12 = S32(MEM_H(ctx->r6, 0X2E0));
            goto L_800774D8;
    }
    goto skip_4;
    // 0x800774BC: lh          $t4, 0x2E0($a2)
    ctx->r12 = S32(MEM_H(ctx->r6, 0X2E0));
    skip_4:
    // 0x800774C0: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800774C4: mflo        $t7
    ctx->r15 = lo;
    // 0x800774C8: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x800774CC: lh          $t9, 0x1A($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X1A));
    // 0x800774D0: sh          $t9, 0x32A($a2)
    MEM_H(0X32A, ctx->r6) = ctx->r25;
    // 0x800774D4: lh          $t4, 0x2E0($a2)
    ctx->r12 = S32(MEM_H(ctx->r6, 0X2E0));
L_800774D8:
    // 0x800774D8: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_800774DC:
    // 0x800774DC: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
L_800774E0:
    // 0x800774E0: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800774E4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800774E8: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x800774EC: lh          $v0, 0x2($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X2));
    // 0x800774F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800774F4: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800774F8: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800774FC: addiu       $t6, $t6, 0x5770
    ctx->r14 = ADD32(ctx->r14, 0X5770);
    // 0x80077500: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80077504: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80077508: beq         $v0, $at, L_800775A8
    if (ctx->r2 == ctx->r1) {
        // 0x8007750C: addu        $a2, $t5, $t6
        ctx->r6 = ADD32(ctx->r13, ctx->r14);
            goto L_800775A8;
    }
    // 0x8007750C: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x80077510: addiu       $at, $zero, 0x3D5
    ctx->r1 = ADD32(0, 0X3D5);
    // 0x80077514: beq         $v0, $at, L_800775A8
    if (ctx->r2 == ctx->r1) {
        // 0x80077518: addiu       $at, $zero, 0x437
        ctx->r1 = ADD32(0, 0X437);
            goto L_800775A8;
    }
    // 0x80077518: addiu       $at, $zero, 0x437
    ctx->r1 = ADD32(0, 0X437);
    // 0x8007751C: beq         $v0, $at, L_800775A8
    if (ctx->r2 == ctx->r1) {
        // 0x80077520: addiu       $at, $zero, 0x4D6
        ctx->r1 = ADD32(0, 0X4D6);
            goto L_800775A8;
    }
    // 0x80077520: addiu       $at, $zero, 0x4D6
    ctx->r1 = ADD32(0, 0X4D6);
    // 0x80077524: beq         $v0, $at, L_800775A8
    if (ctx->r2 == ctx->r1) {
        // 0x80077528: addiu       $at, $zero, 0x4DF
        ctx->r1 = ADD32(0, 0X4DF);
            goto L_800775A8;
    }
    // 0x80077528: addiu       $at, $zero, 0x4DF
    ctx->r1 = ADD32(0, 0X4DF);
    // 0x8007752C: beq         $v0, $at, L_800775A8
    if (ctx->r2 == ctx->r1) {
        // 0x80077530: addiu       $at, $zero, 0x686
        ctx->r1 = ADD32(0, 0X686);
            goto L_800775A8;
    }
    // 0x80077530: addiu       $at, $zero, 0x686
    ctx->r1 = ADD32(0, 0X686);
    // 0x80077534: beq         $v0, $at, L_800775A8
    if (ctx->r2 == ctx->r1) {
        // 0x80077538: addiu       $at, $zero, 0xA2D
        ctx->r1 = ADD32(0, 0XA2D);
            goto L_800775A8;
    }
    // 0x80077538: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x8007753C: beq         $v0, $at, L_800775A8
    if (ctx->r2 == ctx->r1) {
        // 0x80077540: lui         $a1, 0x8010
        ctx->r5 = S32(0X8010 << 16);
            goto L_800775A8;
    }
    // 0x80077540: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80077544: lh          $a0, 0x4($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X4));
    // 0x80077548: addiu       $a1, $a1, -0x9A0
    ctx->r5 = ADD32(ctx->r5, -0X9A0);
    // 0x8007754C: lh          $v0, 0x6($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X6));
    // 0x80077550: addiu       $t8, $a0, 0x200
    ctx->r24 = ADD32(ctx->r4, 0X200);
    // 0x80077554: andi        $t9, $t8, 0x7FF
    ctx->r25 = ctx->r24 & 0X7FF;
    // 0x80077558: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x8007755C: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80077560: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x80077564: lw          $t7, 0x24C($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X24C));
    // 0x80077568: lw          $t5, 0x250($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X250));
    // 0x8007756C: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077570: andi        $t6, $a0, 0x7FF
    ctx->r14 = ctx->r4 & 0X7FF;
    // 0x80077574: mflo        $t8
    ctx->r24 = lo;
    // 0x80077578: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8007757C: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80077580: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x80077584: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80077588: lh          $t9, 0x0($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X0));
    // 0x8007758C: sw          $t4, 0x24C($a2)
    MEM_W(0X24C, ctx->r6) = ctx->r12;
    // 0x80077590: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077594: mflo        $t4
    ctx->r12 = lo;
    // 0x80077598: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x8007759C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800775A0: b           L_8007767C
    // 0x800775A4: sw          $t8, 0x250($a2)
    MEM_W(0X250, ctx->r6) = ctx->r24;
        goto L_8007767C;
    // 0x800775A4: sw          $t8, 0x250($a2)
    MEM_W(0X250, ctx->r6) = ctx->r24;
L_800775A8:
    // 0x800775A8: lh          $a0, 0x4($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X4));
    // 0x800775AC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800775B0: addiu       $a1, $a1, -0x9A0
    ctx->r5 = ADD32(ctx->r5, -0X9A0);
    // 0x800775B4: addiu       $t9, $a0, 0x200
    ctx->r25 = ADD32(ctx->r4, 0X200);
    // 0x800775B8: andi        $t4, $t9, 0x7FF
    ctx->r12 = ctx->r25 & 0X7FF;
    // 0x800775BC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800775C0: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800775C4: lh          $t8, 0x0($t6)
    ctx->r24 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800775C8: lh          $v0, 0x6($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X6));
    // 0x800775CC: lw          $t7, 0x24C($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X24C));
    // 0x800775D0: lw          $t6, 0x250($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X250));
    // 0x800775D4: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800775D8: andi        $t8, $a0, 0x7FF
    ctx->r24 = ctx->r4 & 0X7FF;
    // 0x800775DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800775E0: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800775E4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800775E8: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x800775EC: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x800775F0: lh          $t4, 0x0($t7)
    ctx->r12 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800775F4: sw          $t5, 0x24C($a2)
    MEM_W(0X24C, ctx->r6) = ctx->r13;
    // 0x800775F8: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800775FC: mflo        $t5
    ctx->r13 = lo;
    // 0x80077600: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80077604: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80077608: b           L_8007767C
    // 0x8007760C: sw          $t9, 0x250($a2)
    MEM_W(0X250, ctx->r6) = ctx->r25;
        goto L_8007767C;
    // 0x8007760C: sw          $t9, 0x250($a2)
    MEM_W(0X250, ctx->r6) = ctx->r25;
L_80077610:
    // 0x80077610: bne         $v0, $zero, L_80077640
    if (ctx->r2 != 0) {
        // 0x80077614: subu        $t5, $a2, $v0
        ctx->r13 = SUB32(ctx->r6, ctx->r2);
            goto L_80077640;
    }
    // 0x80077614: subu        $t5, $a2, $v0
    ctx->r13 = SUB32(ctx->r6, ctx->r2);
    // 0x80077618: lh          $t7, 0x2($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X2));
    // 0x8007761C: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x80077620: bnel        $t7, $at, L_80077644
    if (ctx->r15 != ctx->r1) {
        // 0x80077624: addiu       $at, $zero, 0x7A8
        ctx->r1 = ADD32(0, 0X7A8);
            goto L_80077644;
    }
    goto skip_5;
    // 0x80077624: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
    skip_5:
    // 0x80077628: lbu         $t4, 0x27($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X27);
    // 0x8007762C: slti        $at, $t4, 0x18
    ctx->r1 = SIGNED(ctx->r12) < 0X18 ? 1 : 0;
    // 0x80077630: beql        $at, $zero, L_80077644
    if (ctx->r1 == 0) {
        // 0x80077634: addiu       $at, $zero, 0x7A8
        ctx->r1 = ADD32(0, 0X7A8);
            goto L_80077644;
    }
    goto skip_6;
    // 0x80077634: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
    skip_6:
    // 0x80077638: jr          $ra
    // 0x8007763C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8007763C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80077640:
    // 0x80077640: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
L_80077644:
    // 0x80077644: beq         $a0, $at, L_8007767C
    if (ctx->r4 == ctx->r1) {
        // 0x80077648: sh          $t5, 0x22($a1)
        MEM_H(0X22, ctx->r5) = ctx->r13;
            goto L_8007767C;
    }
    // 0x80077648: sh          $t5, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r13;
    // 0x8007764C: lh          $v0, 0x16($a1)
    ctx->r2 = S32(MEM_H(ctx->r5, 0X16));
    // 0x80077650: bltzl       $v0, L_80077680
    if (SIGNED(ctx->r2) < 0) {
        // 0x80077654: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_80077680;
    }
    goto skip_7;
    // 0x80077654: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    skip_7:
    // 0x80077658: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007765C: mflo        $t6
    ctx->r14 = lo;
    // 0x80077660: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x80077664: lh          $t9, 0x12($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X12));
    // 0x80077668: slti        $at, $t9, 0x400
    ctx->r1 = SIGNED(ctx->r25) < 0X400 ? 1 : 0;
    // 0x8007766C: beql        $at, $zero, L_80077680
    if (ctx->r1 == 0) {
        // 0x80077670: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_80077680;
    }
    goto skip_8;
    // 0x80077670: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    skip_8:
    // 0x80077674: lh          $t7, 0x8($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X8));
    // 0x80077678: sh          $t7, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r15;
L_8007767C:
    // 0x8007767C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80077680:
    // 0x80077680: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
    // 0x80077684: jr          $ra
    // 0x80077688: lh          $v0, 0x2($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X2));
    return;
    // 0x80077688: lh          $v0, 0x2($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X2));
L_8007768C:
    // 0x8007768C: sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
L_80077690:
    // 0x80077690: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80077694: jr          $ra
    // 0x80077698: nop

    return;
    // 0x80077698: nop

;}
RECOMP_FUNC void alCSPSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C16A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C16A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C16A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C16AC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800C16B0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800C16B4: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800C16B8: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x800C16BC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C16C0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C16C4: jal         0x800C9C6C
    // 0x800C16C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C16C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C16CC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C16D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C16D4: jr          $ra
    // 0x800C16D8: nop

    return;
    // 0x800C16D8: nop

;}
RECOMP_FUNC void func_800701A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800701A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800701A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800701A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800701AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800701B0: jal         0x800700F0
    // 0x800701B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_0;
    // 0x800701B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800701B8: beq         $v0, $zero, L_8007023C
    if (ctx->r2 == 0) {
        // 0x800701BC: nop
    
            goto L_8007023C;
    }
    // 0x800701BC: nop

    // 0x800701C0: jal         0x800700F0
    // 0x800701C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_1;
    // 0x800701C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800701C8: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x800701CC: jal         0x800700F0
    // 0x800701D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_2;
    // 0x800701D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800701D4: beq         $v0, $zero, L_80070220
    if (ctx->r2 == 0) {
        // 0x800701D8: nop
    
            goto L_80070220;
    }
    // 0x800701D8: nop

    // 0x800701DC: jal         0x800700F0
    // 0x800701E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_3;
    // 0x800701E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800701E4: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x800701E8: addu        $s0, $v0, $t6
    ctx->r16 = ADD32(ctx->r2, ctx->r14);
    // 0x800701EC: ori         $t7, $s0, 0x4
    ctx->r15 = ctx->r16 | 0X4;
    // 0x800701F0: andi        $s0, $t7, 0xFFFF
    ctx->r16 = ctx->r15 & 0XFFFF;
    // 0x800701F4: jal         0x800700F0
    // 0x800701F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_4;
    // 0x800701F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800701FC: bne         $v0, $zero, L_8007023C
    if (ctx->r2 != 0) {
        // 0x80070200: nop
    
            goto L_8007023C;
    }
    // 0x80070200: nop

    // 0x80070204: jal         0x800700F0
    // 0x80070208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_5;
    // 0x80070208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8007020C: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80070210: addu        $s0, $v0, $t9
    ctx->r16 = ADD32(ctx->r2, ctx->r25);
    // 0x80070214: andi        $t0, $s0, 0xFFFF
    ctx->r8 = ctx->r16 & 0XFFFF;
    // 0x80070218: b           L_8007023C
    // 0x8007021C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
        goto L_8007023C;
    // 0x8007021C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80070220:
    // 0x80070220: bne         $s0, $zero, L_8007023C
    if (ctx->r16 != 0) {
        // 0x80070224: nop
    
            goto L_8007023C;
    }
    // 0x80070224: nop

    // 0x80070228: jal         0x800700F0
    // 0x8007022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_6;
    // 0x8007022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80070230: addiu       $s0, $v0, 0x2
    ctx->r16 = ADD32(ctx->r2, 0X2);
    // 0x80070234: andi        $t1, $s0, 0xFFFF
    ctx->r9 = ctx->r16 & 0XFFFF;
    // 0x80070238: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_8007023C:
    // 0x8007023C: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x80070240: addiu       $a1, $a1, -0x133C
    ctx->r5 = ADD32(ctx->r5, -0X133C);
    // 0x80070244: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80070248: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8007024C: sll         $t3, $s0, 8
    ctx->r11 = S32(ctx->r16 << 8);
    // 0x80070250: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80070254: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80070258: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8007025C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80070260: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80070264: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80070268: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007026C: jr          $ra
    // 0x80070270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80070270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6700: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C6704: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800C6708: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800C670C: blez        $a1, L_800C6750
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C6710: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_800C6750;
    }
    // 0x800C6710: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800C6714:
    // 0x800C6714: lw          $t7, 0x4($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X4));
    // 0x800C6718: lw          $t6, 0x8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X8));
    // 0x800C671C: lw          $t3, 0xC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XC));
    // 0x800C6720: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C6724: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800C6728: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C672C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800C6730: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C6734: lw          $t1, 0x8($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X8));
    // 0x800C6738: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C673C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800C6740: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800C6744: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800C6748: bne         $at, $zero, L_800C6714
    if (ctx->r1 != 0) {
        // 0x800C674C: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_800C6714;
    }
    // 0x800C674C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_800C6750:
    // 0x800C6750: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x800C6754: jr          $ra
    // 0x800C6758: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C6758: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800594A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800594A8: andi        $t6, $a0, 0x7
    ctx->r14 = ctx->r4 & 0X7;
    // 0x800594AC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800594B0: sra         $t8, $a0, 3
    ctx->r24 = S32(SIGNED(ctx->r4) >> 3);
    // 0x800594B4: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800594B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800594BC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800594C0: lbu         $t7, 0x4D90($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4D90);
    // 0x800594C4: lbu         $t9, -0x5360($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X5360);
    // 0x800594C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800594CC: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x800594D0: beq         $t0, $zero, L_800594E0
    if (ctx->r8 == 0) {
        // 0x800594D4: nop
    
            goto L_800594E0;
    }
    // 0x800594D4: nop

    // 0x800594D8: jr          $ra
    // 0x800594DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800594DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800594E0:
    // 0x800594E0: jr          $ra
    // 0x800594E4: nop

    return;
    // 0x800594E4: nop

;}
RECOMP_FUNC void movetransports(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AD84: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8007AD88: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x8007AD8C: lh          $v0, 0x286A($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X286A));
    // 0x8007AD90: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007AD94: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007AD98: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007AD9C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007ADA0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007ADA4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007ADA8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007ADAC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007ADB0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007ADB4: bltz        $v0, L_8007BC34
    if (SIGNED(ctx->r2) < 0) {
        // 0x8007ADB8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8007BC34;
    }
    // 0x8007ADB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007ADBC: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x8007ADC0: addiu       $s5, $s5, 0x6BA8
    ctx->r21 = ADD32(ctx->r21, 0X6BA8);
    // 0x8007ADC4: sh          $v0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r2;
    // 0x8007ADC8: addiu       $s6, $zero, 0x2C
    ctx->r22 = ADD32(0, 0X2C);
    // 0x8007ADCC: lh          $v1, 0x7C($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X7C));
L_8007ADD0:
    // 0x8007ADD0: lh          $t3, 0x7C($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X7C));
    // 0x8007ADD4: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8007ADD8: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007ADDC: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8007ADE0: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8007ADE4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8007ADE8: lh          $t0, 0x5F40($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X5F40));
    // 0x8007ADEC: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x8007ADF0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8007ADF4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007ADF8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8007ADFC: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x8007AE00: mflo        $t6
    ctx->r14 = lo;
    // 0x8007AE04: addu        $s4, $s5, $t6
    ctx->r20 = ADD32(ctx->r21, ctx->r14);
    // 0x8007AE08: lh          $a0, 0x10($s4)
    ctx->r4 = S32(MEM_H(ctx->r20, 0X10));
    // 0x8007AE0C: lh          $t1, 0x16($s4)
    ctx->r9 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007AE10: sh          $t0, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r8;
    // 0x8007AE14: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8007AE18: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8007AE1C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8007AE20: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8007AE24: lh          $fp, 0x18($v0)
    ctx->r30 = S32(MEM_H(ctx->r2, 0X18));
    // 0x8007AE28: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8007AE2C: bne         $v1, $t1, L_8007AE40
    if (ctx->r3 != ctx->r9) {
        // 0x8007AE30: sh          $a0, 0x72($sp)
        MEM_H(0X72, ctx->r29) = ctx->r4;
            goto L_8007AE40;
    }
    // 0x8007AE30: sh          $a0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r4;
    // 0x8007AE34: lh          $t2, 0x6E($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X6E));
    // 0x8007AE38: b           L_8007BC28
    // 0x8007AE3C: sh          $t2, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r10;
        goto L_8007BC28;
    // 0x8007AE3C: sh          $t2, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r10;
L_8007AE40:
    // 0x8007AE40: addiu       $t5, $t5, -0x5C00
    ctx->r13 = ADD32(ctx->r13, -0X5C00);
    // 0x8007AE44: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x8007AE48: lw          $v0, 0x30($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X30));
    // 0x8007AE4C: lw          $t6, 0x40($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X40));
    // 0x8007AE50: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8007AE54: blez        $v0, L_8007AE64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007AE58: sw          $t6, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r14;
            goto L_8007AE64;
    }
    // 0x8007AE58: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x8007AE5C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8007AE60: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
L_8007AE64:
    // 0x8007AE64: lh          $t9, 0x72($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X72));
    // 0x8007AE68: lui         $s7, 0x8027
    ctx->r23 = S32(0X8027 << 16);
    // 0x8007AE6C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8007AE70: addu        $s7, $s7, $t0
    ctx->r23 = ADD32(ctx->r23, ctx->r8);
    // 0x8007AE74: lh          $s7, 0x2330($s7)
    ctx->r23 = S32(MEM_H(ctx->r23, 0X2330));
    // 0x8007AE78: bltzl       $s7, L_8007BC24
    if (SIGNED(ctx->r23) < 0) {
        // 0x8007AE7C: lh          $t1, 0x6E($sp)
        ctx->r9 = S32(MEM_H(ctx->r29, 0X6E));
            goto L_8007BC24;
    }
    goto skip_0;
    // 0x8007AE7C: lh          $t1, 0x6E($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X6E));
    skip_0:
L_8007AE80:
    // 0x8007AE80: multu       $s7, $s6
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AE84: sll         $t1, $s7, 1
    ctx->r9 = S32(ctx->r23 << 1);
    // 0x8007AE88: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8007AE8C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8007AE90: lh          $t2, 0x4FA0($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X4FA0));
    // 0x8007AE94: sh          $t2, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r10;
    // 0x8007AE98: mflo        $t3
    ctx->r11 = lo;
    // 0x8007AE9C: addu        $s1, $s5, $t3
    ctx->r17 = ADD32(ctx->r21, ctx->r11);
    // 0x8007AEA0: lh          $a1, 0x12($s1)
    ctx->r5 = S32(MEM_H(ctx->r17, 0X12));
    // 0x8007AEA4: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x8007AEA8: sltiu       $at, $t4, 0xD
    ctx->r1 = ctx->r12 < 0XD ? 1 : 0;
    // 0x8007AEAC: beq         $at, $zero, L_8007BC14
    if (ctx->r1 == 0) {
        // 0x8007AEB0: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8007BC14;
    }
    // 0x8007AEB0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007AEB4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8007AEB8: addu        $at, $at, $t4
    gpr jr_addend_8007AEC0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8007AEBC: lw          $t4, 0x5564($at)
    ctx->r12 = ADD32(ctx->r1, 0X5564);
    // 0x8007AEC0: jr          $t4
    // 0x8007AEC4: nop

    switch (jr_addend_8007AEC0 >> 2) {
        case 0: goto L_8007B510; break;
        case 1: goto L_8007BC14; break;
        case 2: goto L_8007BC14; break;
        case 3: goto L_8007B57C; break;
        case 4: goto L_8007B57C; break;
        case 5: goto L_8007BC14; break;
        case 6: goto L_8007BC14; break;
        case 7: goto L_8007BC14; break;
        case 8: goto L_8007BC14; break;
        case 9: goto L_8007AEC8; break;
        case 10: goto L_8007BC14; break;
        case 11: goto L_8007B57C; break;
        case 12: goto L_8007B57C; break;
        default: switch_error(__func__, 0x8007AEC0, 0x80105564);
    }
    // 0x8007AEC4: nop

L_8007AEC8:
    // 0x8007AEC8: lh          $t5, 0x16($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, 0X16));
    // 0x8007AECC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007AED0: beql        $t5, $at, L_8007BC18
    if (ctx->r13 == ctx->r1) {
        // 0x8007AED4: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_1;
    // 0x8007AED4: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_1:
    // 0x8007AED8: lh          $s3, 0x1A($s1)
    ctx->r19 = S32(MEM_H(ctx->r17, 0X1A));
    // 0x8007AEDC: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x8007AEE0: addiu       $t7, $t7, 0x5770
    ctx->r15 = ADD32(ctx->r15, 0X5770);
    // 0x8007AEE4: sll         $t6, $s3, 3
    ctx->r14 = S32(ctx->r19 << 3);
    // 0x8007AEE8: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x8007AEEC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007AEF0: addu        $t6, $t6, $s3
    ctx->r14 = ADD32(ctx->r14, ctx->r19);
    // 0x8007AEF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8007AEF8: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x8007AEFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8007AF00: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x8007AF04: lh          $t9, 0x32C($s2)
    ctx->r25 = S32(MEM_H(ctx->r18, 0X32C));
    // 0x8007AF08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007AF0C: sb          $t8, 0x339($s2)
    MEM_B(0X339, ctx->r18) = ctx->r24;
    // 0x8007AF10: bne         $t9, $zero, L_8007B0D0
    if (ctx->r25 != 0) {
        // 0x8007AF14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8007B0D0;
    }
    // 0x8007AF14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007AF18: lh          $t0, 0x2C4($s2)
    ctx->r8 = S32(MEM_H(ctx->r18, 0X2C4));
    // 0x8007AF1C: bne         $t0, $zero, L_8007B0D0
    if (ctx->r8 != 0) {
        // 0x8007AF20: nop
    
            goto L_8007B0D0;
    }
    // 0x8007AF20: nop

    // 0x8007AF24: lbu         $a0, 0x33E($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X33E);
    // 0x8007AF28: beql        $a0, $zero, L_8007B0EC
    if (ctx->r4 == 0) {
        // 0x8007AF2C: lw          $t2, 0x60($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B0EC;
    }
    goto skip_2;
    // 0x8007AF2C: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    skip_2:
    // 0x8007AF30: bne         $fp, $zero, L_8007B0E8
    if (ctx->r30 != 0) {
        // 0x8007AF34: lw          $t1, 0x60($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B0E8;
    }
    // 0x8007AF34: lw          $t1, 0x60($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X60));
    // 0x8007AF38: beql        $t1, $zero, L_8007B0EC
    if (ctx->r9 == 0) {
        // 0x8007AF3C: lw          $t2, 0x60($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B0EC;
    }
    goto skip_3;
    // 0x8007AF3C: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    skip_3:
    // 0x8007AF40: lbu         $t2, 0x341($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X341);
    // 0x8007AF44: bnel        $t2, $zero, L_8007B0EC
    if (ctx->r10 != 0) {
        // 0x8007AF48: lw          $t2, 0x60($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B0EC;
    }
    goto skip_4;
    // 0x8007AF48: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    skip_4:
    // 0x8007AF4C: lbu         $t3, 0x25($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X25);
    // 0x8007AF50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007AF54: lh          $a0, 0x7C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X7C));
    // 0x8007AF58: bnel        $t3, $zero, L_8007AF78
    if (ctx->r11 != 0) {
        // 0x8007AF5C: lh          $v1, 0x16($s4)
        ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
            goto L_8007AF78;
    }
    goto skip_5;
    // 0x8007AF5C: lh          $v1, 0x16($s4)
    ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
    skip_5:
    // 0x8007AF60: jal         0x8009D240
    // 0x8007AF64: addiu       $a1, $zero, 0x4ED
    ctx->r5 = ADD32(0, 0X4ED);
    spawn(rdram, ctx);
        goto after_0;
    // 0x8007AF64: addiu       $a1, $zero, 0x4ED
    ctx->r5 = ADD32(0, 0X4ED);
    after_0:
    // 0x8007AF68: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x8007AF6C: jal         0x80059034
    // 0x8007AF70: lh          $a1, 0x7C($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X7C));
    spritesound(rdram, ctx);
        goto after_1;
    // 0x8007AF70: lh          $a1, 0x7C($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X7C));
    after_1:
    // 0x8007AF74: lh          $v1, 0x16($s4)
    ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
L_8007AF78:
    // 0x8007AF78: lui         $a0, 0x802B
    ctx->r4 = S32(0X802B << 16);
    // 0x8007AF7C: lw          $a0, -0x540C($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X540C));
    // 0x8007AF80: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x8007AF84: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8007AF88: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007AF8C: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8007AF90: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007AF94: addu        $a2, $s5, $t4
    ctx->r6 = ADD32(ctx->r21, ctx->r12);
    // 0x8007AF98: blez        $a0, L_8007B020
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007AF9C: lh          $a1, 0x10($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
            goto L_8007B020;
    }
    // 0x8007AF9C: lh          $a1, 0x10($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
    // 0x8007AFA0: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
L_8007AFA4:
    // 0x8007AFA4: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x8007AFA8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007AFAC: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x8007AFB0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007AFB4: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x8007AFB8: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x8007AFBC: addiu       $t6, $t6, 0x5770
    ctx->r14 = ADD32(ctx->r14, 0X5770);
    // 0x8007AFC0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007AFC4: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8007AFC8: lh          $t7, 0x288($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X288));
    // 0x8007AFCC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007AFD0: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x8007AFD4: bne         $t7, $a1, L_8007B014
    if (ctx->r15 != ctx->r5) {
        // 0x8007AFD8: sra         $s0, $t2, 16
        ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
            goto L_8007B014;
    }
    // 0x8007AFD8: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8007AFDC: lh          $t8, 0x2E0($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X2E0));
    // 0x8007AFE0: sh          $s3, 0x32A($v0)
    MEM_H(0X32A, ctx->r2) = ctx->r19;
    // 0x8007AFE4: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AFE8: mflo        $t9
    ctx->r25 = lo;
    // 0x8007AFEC: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x8007AFF0: sh          $zero, 0x22($t0)
    MEM_H(0X22, ctx->r8) = 0;
    // 0x8007AFF4: lh          $v1, 0x16($s4)
    ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007AFF8: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8007AFFC: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x8007B000: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007B004: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x8007B008: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007B00C: addu        $a2, $s5, $t1
    ctx->r6 = ADD32(ctx->r21, ctx->r9);
    // 0x8007B010: lh          $a1, 0x10($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
L_8007B014:
    // 0x8007B014: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007B018: bnel        $at, $zero, L_8007AFA4
    if (ctx->r1 != 0) {
        // 0x8007B01C: sll         $t5, $s0, 3
        ctx->r13 = S32(ctx->r16 << 3);
            goto L_8007AFA4;
    }
    goto skip_6;
    // 0x8007B01C: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    skip_6:
L_8007B020:
    // 0x8007B020: lh          $t5, 0x16($a2)
    ctx->r13 = S32(MEM_H(ctx->r6, 0X16));
    // 0x8007B024: lh          $t4, 0x14($a2)
    ctx->r12 = S32(MEM_H(ctx->r6, 0X14));
    // 0x8007B028: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007B02C: beq         $t5, $v1, L_8007B05C
    if (ctx->r13 == ctx->r3) {
        // 0x8007B030: sh          $t4, 0x282($s2)
        MEM_H(0X282, ctx->r18) = ctx->r12;
            goto L_8007B05C;
    }
    // 0x8007B030: sh          $t4, 0x282($s2)
    MEM_H(0X282, ctx->r18) = ctx->r12;
    // 0x8007B034: lw          $t6, 0x44($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8007B038: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8007B03C: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8007B040: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8007B044: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007B048: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8007B04C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007B050: sw          $v0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r2;
    // 0x8007B054: sw          $v0, -0x5BD0($at)
    MEM_W(-0X5BD0, ctx->r1) = ctx->r2;
    // 0x8007B058: sh          $v0, 0x32C($s2)
    MEM_H(0X32C, ctx->r18) = ctx->r2;
L_8007B05C:
    // 0x8007B05C: lw          $v0, 0x0($a2)
    ctx->r2 = S32(MEM_W(ctx->r6, 0X0));
    // 0x8007B060: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x8007B064: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B068: sw          $v0, 0x214($s2)
    MEM_W(0X214, ctx->r18) = ctx->r2;
    // 0x8007B06C: sw          $v0, 0x238($s2)
    MEM_W(0X238, ctx->r18) = ctx->r2;
    // 0x8007B070: sw          $v0, 0x230($s2)
    MEM_W(0X230, ctx->r18) = ctx->r2;
    // 0x8007B074: lw          $v0, 0x4($a2)
    ctx->r2 = S32(MEM_W(ctx->r6, 0X4));
    // 0x8007B078: addiu       $v1, $v1, -0x2600
    ctx->r3 = ADD32(ctx->r3, -0X2600);
    // 0x8007B07C: sw          $v1, 0x21C($s2)
    MEM_W(0X21C, ctx->r18) = ctx->r3;
    // 0x8007B080: sw          $v1, 0x240($s2)
    MEM_W(0X240, ctx->r18) = ctx->r3;
    // 0x8007B084: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8007B088: sw          $v0, 0x218($s2)
    MEM_W(0X218, ctx->r18) = ctx->r2;
    // 0x8007B08C: sw          $v0, 0x23C($s2)
    MEM_W(0X23C, ctx->r18) = ctx->r2;
    // 0x8007B090: jal         0x80092938
    // 0x8007B094: sw          $v0, 0x234($s2)
    MEM_W(0X234, ctx->r18) = ctx->r2;
    changespritesect(rdram, ctx);
        goto after_2;
    // 0x8007B094: sw          $v0, 0x234($s2)
    MEM_W(0X234, ctx->r18) = ctx->r2;
    after_2:
    // 0x8007B098: lbu         $t0, 0x25($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X25);
    // 0x8007B09C: lh          $t9, 0x10($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X10));
    // 0x8007B0A0: addiu       $a1, $zero, 0x4ED
    ctx->r5 = ADD32(0, 0X4ED);
    // 0x8007B0A4: bne         $t0, $zero, L_8007BC14
    if (ctx->r8 != 0) {
        // 0x8007B0A8: sh          $t9, 0x288($s2)
        MEM_H(0X288, ctx->r18) = ctx->r25;
            goto L_8007BC14;
    }
    // 0x8007B0A8: sh          $t9, 0x288($s2)
    MEM_H(0X288, ctx->r18) = ctx->r25;
    // 0x8007B0AC: jal         0x8009D240
    // 0x8007B0B0: lh          $a0, 0x16($s4)
    ctx->r4 = S32(MEM_H(ctx->r20, 0X16));
    spawn(rdram, ctx);
        goto after_3;
    // 0x8007B0B0: lh          $a0, 0x16($s4)
    ctx->r4 = S32(MEM_H(ctx->r20, 0X16));
    after_3:
    // 0x8007B0B4: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8007B0B8: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B0BC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8007B0C0: jal         0x80059034
    // 0x8007B0C4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    spritesound(rdram, ctx);
        goto after_4;
    // 0x8007B0C4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_4:
    // 0x8007B0C8: b           L_8007BC18
    // 0x8007B0CC: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
        goto L_8007BC18;
    // 0x8007B0CC: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
L_8007B0D0:
    // 0x8007B0D0: bnel        $fp, $at, L_8007BC18
    if (ctx->r30 != ctx->r1) {
        // 0x8007B0D4: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_7;
    // 0x8007B0D4: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_7:
    // 0x8007B0D8: lbu         $a0, 0x33E($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X33E);
    // 0x8007B0DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B0E0: bnel        $a0, $at, L_8007BC18
    if (ctx->r4 != ctx->r1) {
        // 0x8007B0E4: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_8;
    // 0x8007B0E4: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_8:
L_8007B0E8:
    // 0x8007B0E8: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
L_8007B0EC:
    // 0x8007B0EC: bnel        $t2, $zero, L_8007B27C
    if (ctx->r10 != 0) {
        // 0x8007B0F0: lw          $t2, 0x60($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B27C;
    }
    goto skip_9;
    // 0x8007B0F0: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    skip_9:
    // 0x8007B0F4: lw          $t3, 0x8($s4)
    ctx->r11 = S32(MEM_W(ctx->r20, 0X8));
    // 0x8007B0F8: lw          $t4, 0x21C($s2)
    ctx->r12 = S32(MEM_W(ctx->r18, 0X21C));
    // 0x8007B0FC: subu        $v0, $t3, $t4
    ctx->r2 = SUB32(ctx->r11, ctx->r12);
    // 0x8007B100: blez        $v0, L_8007B110
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B104: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_8007B110;
    }
    // 0x8007B104: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8007B108: b           L_8007B110
    // 0x8007B10C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8007B110;
    // 0x8007B10C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8007B110:
    // 0x8007B110: slti        $at, $v1, 0x1800
    ctx->r1 = SIGNED(ctx->r3) < 0X1800 ? 1 : 0;
    // 0x8007B114: beql        $at, $zero, L_8007B27C
    if (ctx->r1 == 0) {
        // 0x8007B118: lw          $t2, 0x60($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B27C;
    }
    goto skip_10;
    // 0x8007B118: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    skip_10:
    // 0x8007B11C: lbu         $v0, 0x341($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X341);
    // 0x8007B120: beq         $v0, $zero, L_8007B178
    if (ctx->r2 == 0) {
        // 0x8007B124: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007B178;
    }
    // 0x8007B124: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007B128: beq         $v0, $zero, L_8007B150
    if (ctx->r2 == 0) {
        // 0x8007B12C: sll         $t5, $s3, 2
        ctx->r13 = S32(ctx->r19 << 2);
            goto L_8007B150;
    }
    // 0x8007B12C: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x8007B130: subu        $t5, $t5, $s3
    ctx->r13 = SUB32(ctx->r13, ctx->r19);
    // 0x8007B134: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007B138: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x8007B13C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8007B140: lw          $t6, 0x5608($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, 0X5608));
    // 0x8007B144: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8007B148: bnel        $t7, $zero, L_8007B17C
    if (ctx->r15 != 0) {
        // 0x8007B14C: lh          $t1, 0x16($s4)
        ctx->r9 = S32(MEM_H(ctx->r20, 0X16));
            goto L_8007B17C;
    }
    goto skip_11;
    // 0x8007B14C: lh          $t1, 0x16($s4)
    ctx->r9 = S32(MEM_H(ctx->r20, 0X16));
    skip_11:
L_8007B150:
    // 0x8007B150: beq         $v0, $zero, L_8007B278
    if (ctx->r2 == 0) {
        // 0x8007B154: sll         $t8, $s3, 2
        ctx->r24 = S32(ctx->r19 << 2);
            goto L_8007B278;
    }
    // 0x8007B154: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x8007B158: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x8007B15C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007B160: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x8007B164: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007B168: lw          $t9, 0x5608($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X5608));
    // 0x8007B16C: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8007B170: beql        $t0, $zero, L_8007B27C
    if (ctx->r8 == 0) {
        // 0x8007B174: lw          $t2, 0x60($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B27C;
    }
    goto skip_12;
    // 0x8007B174: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    skip_12:
L_8007B178:
    // 0x8007B178: lh          $t1, 0x16($s4)
    ctx->r9 = S32(MEM_H(ctx->r20, 0X16));
L_8007B17C:
    // 0x8007B17C: lw          $t3, 0x214($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X214));
    // 0x8007B180: lw          $t9, 0x218($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X218));
    // 0x8007B184: multu       $t1, $s6
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B188: lw          $t6, 0x0($s4)
    ctx->r14 = S32(MEM_W(ctx->r20, 0X0));
    // 0x8007B18C: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007B190: mflo        $t2
    ctx->r10 = lo;
    // 0x8007B194: addu        $a2, $s5, $t2
    ctx->r6 = ADD32(ctx->r21, ctx->r10);
    // 0x8007B198: lw          $t4, 0x0($a2)
    ctx->r12 = S32(MEM_W(ctx->r6, 0X0));
    // 0x8007B19C: lw          $t0, 0x4($a2)
    ctx->r8 = S32(MEM_W(ctx->r6, 0X4));
    // 0x8007B1A0: lw          $t2, 0x4($s4)
    ctx->r10 = S32(MEM_W(ctx->r20, 0X4));
    // 0x8007B1A4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007B1A8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007B1AC: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8007B1B0: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8007B1B4: sw          $t7, 0x214($s2)
    MEM_W(0X214, ctx->r18) = ctx->r15;
    // 0x8007B1B8: sw          $t7, 0x238($s2)
    MEM_W(0X238, ctx->r18) = ctx->r15;
    // 0x8007B1BC: sw          $t3, 0x218($s2)
    MEM_W(0X218, ctx->r18) = ctx->r11;
    // 0x8007B1C0: sw          $t3, 0x23C($s2)
    MEM_W(0X23C, ctx->r18) = ctx->r11;
    // 0x8007B1C4: beq         $v0, $zero, L_8007B20C
    if (ctx->r2 == 0) {
        // 0x8007B1C8: lh          $a1, 0x10($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
            goto L_8007B20C;
    }
    // 0x8007B1C8: lh          $a1, 0x10($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
    // 0x8007B1CC: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x8007B1D0: subu        $t5, $t5, $s3
    ctx->r13 = SUB32(ctx->r13, ctx->r19);
    // 0x8007B1D4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007B1D8: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x8007B1DC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8007B1E0: lw          $t6, 0x5608($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, 0X5608));
    // 0x8007B1E4: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x8007B1E8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8007B1EC: bnel        $t7, $zero, L_8007B200
    if (ctx->r15 != 0) {
        // 0x8007B1F0: lw          $t8, 0x8($a2)
        ctx->r24 = S32(MEM_W(ctx->r6, 0X8));
            goto L_8007B200;
    }
    goto skip_13;
    // 0x8007B1F0: lw          $t8, 0x8($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X8));
    skip_13:
    // 0x8007B1F4: beql        $at, $zero, L_8007B210
    if (ctx->r1 == 0) {
        // 0x8007B1F8: lw          $t0, 0x8($a2)
        ctx->r8 = S32(MEM_W(ctx->r6, 0X8));
            goto L_8007B210;
    }
    goto skip_14;
    // 0x8007B1F8: lw          $t0, 0x8($a2)
    ctx->r8 = S32(MEM_W(ctx->r6, 0X8));
    skip_14:
    // 0x8007B1FC: lw          $t8, 0x8($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X8));
L_8007B200:
    // 0x8007B200: addiu       $t9, $t8, -0x1800
    ctx->r25 = ADD32(ctx->r24, -0X1800);
    // 0x8007B204: b           L_8007B218
    // 0x8007B208: sw          $t9, 0x21C($s2)
    MEM_W(0X21C, ctx->r18) = ctx->r25;
        goto L_8007B218;
    // 0x8007B208: sw          $t9, 0x21C($s2)
    MEM_W(0X21C, ctx->r18) = ctx->r25;
L_8007B20C:
    // 0x8007B20C: lw          $t0, 0x8($a2)
    ctx->r8 = S32(MEM_W(ctx->r6, 0X8));
L_8007B210:
    // 0x8007B210: addiu       $t1, $t0, 0x1800
    ctx->r9 = ADD32(ctx->r8, 0X1800);
    // 0x8007B214: sw          $t1, 0x21C($s2)
    MEM_W(0X21C, ctx->r18) = ctx->r9;
L_8007B218:
    // 0x8007B218: lh          $t2, 0x2E0($s2)
    ctx->r10 = S32(MEM_H(ctx->r18, 0X2E0));
    // 0x8007B21C: lui         $t4, 0x8028
    ctx->r12 = S32(0X8028 << 16);
    // 0x8007B220: lw          $v1, 0x21C($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X21C));
    // 0x8007B224: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007B228: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007B22C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8007B230: addiu       $t4, $t4, -0x5C00
    ctx->r12 = ADD32(ctx->r12, -0X5C00);
    // 0x8007B234: lw          $t5, 0x214($s2)
    ctx->r13 = S32(MEM_W(ctx->r18, 0X214));
    // 0x8007B238: lw          $t6, 0x218($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X218));
    // 0x8007B23C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8007B240: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B244: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8007B248: sw          $v1, 0x240($s2)
    MEM_W(0X240, ctx->r18) = ctx->r3;
    // 0x8007B24C: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x8007B250: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x8007B254: jal         0x80092938
    // 0x8007B258: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    changespritesect(rdram, ctx);
        goto after_5;
    // 0x8007B258: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    after_5:
    // 0x8007B25C: lh          $t8, 0x16($s4)
    ctx->r24 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B260: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B264: mflo        $t9
    ctx->r25 = lo;
    // 0x8007B268: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x8007B26C: lh          $t1, 0x10($t0)
    ctx->r9 = S32(MEM_H(ctx->r8, 0X10));
    // 0x8007B270: b           L_8007BC14
    // 0x8007B274: sh          $t1, 0x288($s2)
    MEM_H(0X288, ctx->r18) = ctx->r9;
        goto L_8007BC14;
    // 0x8007B274: sh          $t1, 0x288($s2)
    MEM_H(0X288, ctx->r18) = ctx->r9;
L_8007B278:
    // 0x8007B278: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
L_8007B27C:
    // 0x8007B27C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007B280: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B284: beql        $t2, $zero, L_8007B37C
    if (ctx->r10 == 0) {
        // 0x8007B288: lw          $t7, 0x60($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B37C;
    }
    goto skip_15;
    // 0x8007B288: lw          $t7, 0x60($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X60));
    skip_15:
    // 0x8007B28C: bnel        $fp, $at, L_8007B37C
    if (ctx->r30 != ctx->r1) {
        // 0x8007B290: lw          $t7, 0x60($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B37C;
    }
    goto skip_16;
    // 0x8007B290: lw          $t7, 0x60($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X60));
    skip_16:
    // 0x8007B294: beq         $a0, $zero, L_8007B378
    if (ctx->r4 == 0) {
        // 0x8007B298: lw          $t4, 0x4C($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X4C));
            goto L_8007B378;
    }
    // 0x8007B298: lw          $t4, 0x4C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8007B29C: lw          $t5, 0x4($t4)
    ctx->r13 = S32(MEM_W(ctx->r12, 0X4));
    // 0x8007B2A0: lw          $t3, 0x21C($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X21C));
    // 0x8007B2A4: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x8007B2A8: addiu       $t6, $t5, -0x1000
    ctx->r14 = ADD32(ctx->r13, -0X1000);
    // 0x8007B2AC: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007B2B0: beq         $at, $zero, L_8007B378
    if (ctx->r1 == 0) {
        // 0x8007B2B4: subu        $t7, $t7, $s3
        ctx->r15 = SUB32(ctx->r15, ctx->r19);
            goto L_8007B378;
    }
    // 0x8007B2B4: subu        $t7, $t7, $s3
    ctx->r15 = SUB32(ctx->r15, ctx->r19);
    // 0x8007B2B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007B2BC: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x8007B2C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007B2C4: lw          $t8, 0x5608($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, 0X5608));
    // 0x8007B2C8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8007B2CC: bnel        $t9, $zero, L_8007B2E8
    if (ctx->r25 != 0) {
        // 0x8007B2D0: lh          $t1, 0x2E0($s2)
        ctx->r9 = S32(MEM_H(ctx->r18, 0X2E0));
            goto L_8007B2E8;
    }
    goto skip_17;
    // 0x8007B2D0: lh          $t1, 0x2E0($s2)
    ctx->r9 = S32(MEM_H(ctx->r18, 0X2E0));
    skip_17:
    // 0x8007B2D4: lw          $t0, 0x254($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X254));
    // 0x8007B2D8: slti        $at, $t0, 0x801
    ctx->r1 = SIGNED(ctx->r8) < 0X801 ? 1 : 0;
    // 0x8007B2DC: bnel        $at, $zero, L_8007B37C
    if (ctx->r1 != 0) {
        // 0x8007B2E0: lw          $t7, 0x60($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B37C;
    }
    goto skip_18;
    // 0x8007B2E0: lw          $t7, 0x60($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X60));
    skip_18:
    // 0x8007B2E4: lh          $t1, 0x2E0($s2)
    ctx->r9 = S32(MEM_H(ctx->r18, 0X2E0));
L_8007B2E8:
    // 0x8007B2E8: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x8007B2EC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007B2F0: multu       $t1, $s6
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B2F4: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B2F8: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8007B2FC: mflo        $t2
    ctx->r10 = lo;
    // 0x8007B300: addu        $t4, $s5, $t2
    ctx->r12 = ADD32(ctx->r21, ctx->r10);
    // 0x8007B304: lh          $t5, 0x22($t4)
    ctx->r13 = S32(MEM_H(ctx->r12, 0X22));
    // 0x8007B308: blezl       $t5, L_8007B31C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8007B30C: lh          $t6, 0x16($s4)
        ctx->r14 = S32(MEM_H(ctx->r20, 0X16));
            goto L_8007B31C;
    }
    goto skip_19;
    // 0x8007B30C: lh          $t6, 0x16($s4)
    ctx->r14 = S32(MEM_H(ctx->r20, 0X16));
    skip_19:
    // 0x8007B310: jal         0x80059034
    // 0x8007B314: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    spritesound(rdram, ctx);
        goto after_6;
    // 0x8007B314: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x8007B318: lh          $t6, 0x16($s4)
    ctx->r14 = S32(MEM_H(ctx->r20, 0X16));
L_8007B31C:
    // 0x8007B31C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x8007B320: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B324: mflo        $t7
    ctx->r15 = lo;
    // 0x8007B328: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8007B32C: lh          $t9, 0x10($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X10));
    // 0x8007B330: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007B334: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8007B338: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8007B33C: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8007B340: lw          $v1, -0x1988($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X1988));
    // 0x8007B344: addiu       $v1, $v1, 0x700
    ctx->r3 = ADD32(ctx->r3, 0X700);
    // 0x8007B348: sw          $v1, 0x21C($s2)
    MEM_W(0X21C, ctx->r18) = ctx->r3;
    // 0x8007B34C: jal         0x8009800C
    // 0x8007B350: sw          $v1, 0x240($s2)
    MEM_W(0X240, ctx->r18) = ctx->r3;
    krand2(rdram, ctx);
        goto after_7;
    // 0x8007B350: sw          $v1, 0x240($s2)
    MEM_W(0X240, ctx->r18) = ctx->r3;
    after_7:
    // 0x8007B354: andi        $t1, $v0, 0x2000
    ctx->r9 = ctx->r2 & 0X2000;
    // 0x8007B358: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x8007B35C: subu        $t4, $t2, $t1
    ctx->r12 = SUB32(ctx->r10, ctx->r9);
    // 0x8007B360: jal         0x8009800C
    // 0x8007B364: sw          $t4, 0x24C($s2)
    MEM_W(0X24C, ctx->r18) = ctx->r12;
    krand2(rdram, ctx);
        goto after_8;
    // 0x8007B364: sw          $t4, 0x24C($s2)
    MEM_W(0X24C, ctx->r18) = ctx->r12;
    after_8:
    // 0x8007B368: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
    // 0x8007B36C: addiu       $t3, $zero, 0x1000
    ctx->r11 = ADD32(0, 0X1000);
    // 0x8007B370: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x8007B374: sw          $t6, 0x250($s2)
    MEM_W(0X250, ctx->r18) = ctx->r14;
L_8007B378:
    // 0x8007B378: lw          $t7, 0x60($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X60));
L_8007B37C:
    // 0x8007B37C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007B380: beql        $t7, $zero, L_8007B404
    if (ctx->r15 == 0) {
        // 0x8007B384: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8007B404;
    }
    goto skip_20;
    // 0x8007B384: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_20:
    // 0x8007B388: bne         $fp, $at, L_8007B400
    if (ctx->r30 != ctx->r1) {
        // 0x8007B38C: lw          $t9, 0x4C($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0X4C));
            goto L_8007B400;
    }
    // 0x8007B38C: lw          $t9, 0x4C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8007B390: lw          $t0, 0x0($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0X0));
    // 0x8007B394: lw          $t8, 0x21C($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X21C));
    // 0x8007B398: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8007B39C: addiu       $t2, $t0, 0x600
    ctx->r10 = ADD32(ctx->r8, 0X600);
    // 0x8007B3A0: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007B3A4: beq         $at, $zero, L_8007B400
    if (ctx->r1 == 0) {
        // 0x8007B3A8: sll         $a1, $s7, 16
        ctx->r5 = S32(ctx->r23 << 16);
            goto L_8007B400;
    }
    // 0x8007B3A8: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x8007B3AC: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B3B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007B3B4: jal         0x80059034
    // 0x8007B3B8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    spritesound(rdram, ctx);
        goto after_9;
    // 0x8007B3B8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_9:
    // 0x8007B3BC: lh          $t4, 0x16($s4)
    ctx->r12 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B3C0: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x8007B3C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007B3C8: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B3CC: mflo        $t3
    ctx->r11 = lo;
    // 0x8007B3D0: addu        $t5, $s5, $t3
    ctx->r13 = ADD32(ctx->r21, ctx->r11);
    // 0x8007B3D4: lh          $t6, 0x10($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X10));
    // 0x8007B3D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007B3DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007B3E0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8007B3E4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8007B3E8: lw          $v1, -0x1984($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X1984));
    // 0x8007B3EC: sb          $t9, 0x33C($s2)
    MEM_B(0X33C, ctx->r18) = ctx->r25;
    // 0x8007B3F0: sh          $zero, 0x2C4($s2)
    MEM_H(0X2C4, ctx->r18) = 0;
    // 0x8007B3F4: addiu       $v1, $v1, -0x700
    ctx->r3 = ADD32(ctx->r3, -0X700);
    // 0x8007B3F8: sw          $v1, 0x21C($s2)
    MEM_W(0X21C, ctx->r18) = ctx->r3;
    // 0x8007B3FC: sw          $v1, 0x240($s2)
    MEM_W(0X240, ctx->r18) = ctx->r3;
L_8007B400:
    // 0x8007B400: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8007B404:
    // 0x8007B404: bne         $s0, $at, L_8007BC14
    if (ctx->r16 != ctx->r1) {
        // 0x8007B408: sll         $a0, $s7, 16
        ctx->r4 = S32(ctx->r23 << 16);
            goto L_8007BC14;
    }
    // 0x8007B408: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007B40C: lh          $v1, 0x16($s4)
    ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B410: lw          $t8, 0x214($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X214));
    // 0x8007B414: lw          $t4, 0x0($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X0));
    // 0x8007B418: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B41C: lw          $t6, 0x218($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X218));
    // 0x8007B420: mflo        $t0
    ctx->r8 = lo;
    // 0x8007B424: addu        $a2, $s5, $t0
    ctx->r6 = ADD32(ctx->r21, ctx->r8);
    // 0x8007B428: lw          $t2, 0x0($a2)
    ctx->r10 = S32(MEM_W(ctx->r6, 0X0));
    // 0x8007B42C: lw          $t7, 0x4($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X4));
    // 0x8007B430: lw          $t0, 0x4($s4)
    ctx->r8 = S32(MEM_W(ctx->r20, 0X4));
    // 0x8007B434: addu        $t1, $t8, $t2
    ctx->r9 = ADD32(ctx->r24, ctx->r10);
    // 0x8007B438: subu        $t3, $t1, $t4
    ctx->r11 = SUB32(ctx->r9, ctx->r12);
    // 0x8007B43C: lh          $t1, 0x16($a2)
    ctx->r9 = S32(MEM_H(ctx->r6, 0X16));
    // 0x8007B440: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8007B444: subu        $t8, $t9, $t0
    ctx->r24 = SUB32(ctx->r25, ctx->r8);
    // 0x8007B448: sw          $t3, 0x214($s2)
    MEM_W(0X214, ctx->r18) = ctx->r11;
    // 0x8007B44C: sw          $t3, 0x238($s2)
    MEM_W(0X238, ctx->r18) = ctx->r11;
    // 0x8007B450: sw          $t8, 0x218($s2)
    MEM_W(0X218, ctx->r18) = ctx->r24;
    // 0x8007B454: sw          $t8, 0x23C($s2)
    MEM_W(0X23C, ctx->r18) = ctx->r24;
    // 0x8007B458: beq         $t1, $v1, L_8007B468
    if (ctx->r9 == ctx->r3) {
        // 0x8007B45C: lh          $a1, 0x10($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
            goto L_8007B468;
    }
    // 0x8007B45C: lh          $a1, 0x10($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
    // 0x8007B460: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x8007B464: sh          $t4, 0x32C($s2)
    MEM_H(0X32C, ctx->r18) = ctx->r12;
L_8007B468:
    // 0x8007B468: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B46C: sh          $a1, 0x288($s2)
    MEM_H(0X288, ctx->r18) = ctx->r5;
    // 0x8007B470: jal         0x80092938
    // 0x8007B474: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    changespritesect(rdram, ctx);
        goto after_10;
    // 0x8007B474: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_10:
    // 0x8007B478: lw          $a3, 0x21C($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X21C));
    // 0x8007B47C: lh          $a0, 0x2E0($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X2E0));
    // 0x8007B480: lw          $a1, 0x214($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X214));
    // 0x8007B484: lw          $a2, 0x218($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X218));
    // 0x8007B488: jal         0x8009219C
    // 0x8007B48C: addiu       $a3, $a3, 0x2600
    ctx->r7 = ADD32(ctx->r7, 0X2600);
    setsprite(rdram, ctx);
        goto after_11;
    // 0x8007B48C: addiu       $a3, $a3, 0x2600
    ctx->r7 = ADD32(ctx->r7, 0X2600);
    after_11:
    // 0x8007B490: jal         0x8009800C
    // 0x8007B494: nop

    krand2(rdram, ctx);
        goto after_12;
    // 0x8007B494: nop

    after_12:
    // 0x8007B498: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x8007B49C: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x8007B4A0: beq         $at, $zero, L_8007B4B8
    if (ctx->r1 == 0) {
        // 0x8007B4A4: sll         $a0, $s7, 16
        ctx->r4 = S32(ctx->r23 << 16);
            goto L_8007B4B8;
    }
    // 0x8007B4A4: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007B4A8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B4AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8007B4B0: jal         0x8009D240
    // 0x8007B4B4: addiu       $a1, $zero, 0x564
    ctx->r5 = ADD32(0, 0X564);
    spawn(rdram, ctx);
        goto after_13;
    // 0x8007B4B4: addiu       $a1, $zero, 0x564
    ctx->r5 = ADD32(0, 0X564);
    after_13:
L_8007B4B8:
    // 0x8007B4B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B4BC: bne         $fp, $at, L_8007BC14
    if (ctx->r30 != ctx->r1) {
        // 0x8007B4C0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8007BC14;
    }
    // 0x8007B4C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007B4C4:
    // 0x8007B4C4: lh          $a0, 0x2E0($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X2E0));
    // 0x8007B4C8: jal         0x8009D240
    // 0x8007B4CC: addiu       $a1, $zero, 0x295
    ctx->r5 = ADD32(0, 0X295);
    spawn(rdram, ctx);
        goto after_14;
    // 0x8007B4CC: addiu       $a1, $zero, 0x295
    ctx->r5 = ADD32(0, 0X295);
    after_14:
    // 0x8007B4D0: jal         0x8009800C
    // 0x8007B4D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_15;
    // 0x8007B4D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_15:
    // 0x8007B4D8: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B4DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007B4E0: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x8007B4E4: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8007B4E8: andi        $t0, $v0, 0x3FFF
    ctx->r8 = ctx->r2 & 0X3FFF;
    // 0x8007B4EC: slti        $at, $s0, 0x9
    ctx->r1 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // 0x8007B4F0: mflo        $t7
    ctx->r15 = lo;
    // 0x8007B4F4: addu        $v1, $s5, $t7
    ctx->r3 = ADD32(ctx->r21, ctx->r15);
    // 0x8007B4F8: lw          $t9, 0x8($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X8));
    // 0x8007B4FC: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x8007B500: bne         $at, $zero, L_8007B4C4
    if (ctx->r1 != 0) {
        // 0x8007B504: sw          $t8, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r24;
            goto L_8007B4C4;
    }
    // 0x8007B504: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8007B508: b           L_8007BC18
    // 0x8007B50C: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
        goto L_8007BC18;
    // 0x8007B50C: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
L_8007B510:
    // 0x8007B510: lh          $v1, 0xE($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0XE));
    // 0x8007B514: slti        $at, $v1, 0x71D
    ctx->r1 = SIGNED(ctx->r3) < 0X71D ? 1 : 0;
    // 0x8007B518: bne         $at, $zero, L_8007B55C
    if (ctx->r1 != 0) {
        // 0x8007B51C: addiu       $t4, $v1, -0x942
        ctx->r12 = ADD32(ctx->r3, -0X942);
            goto L_8007B55C;
    }
    // 0x8007B51C: addiu       $t4, $v1, -0x942
    ctx->r12 = ADD32(ctx->r3, -0X942);
    // 0x8007B520: slti        $at, $v1, 0x781
    ctx->r1 = SIGNED(ctx->r3) < 0X781 ? 1 : 0;
    // 0x8007B524: bne         $at, $zero, L_8007B548
    if (ctx->r1 != 0) {
        // 0x8007B528: sltiu       $at, $t4, 0x8
        ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
            goto L_8007B548;
    }
    // 0x8007B528: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x8007B52C: beq         $at, $zero, L_8007B57C
    if (ctx->r1 == 0) {
        // 0x8007B530: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8007B57C;
    }
    // 0x8007B530: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007B534: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8007B538: addu        $at, $at, $t4
    gpr jr_addend_8007B540 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8007B53C: lw          $t4, 0x5598($at)
    ctx->r12 = ADD32(ctx->r1, 0X5598);
    // 0x8007B540: jr          $t4
    // 0x8007B544: nop

    switch (jr_addend_8007B540 >> 2) {
        case 0: goto L_8007B570; break;
        case 1: goto L_8007B570; break;
        case 2: goto L_8007B570; break;
        case 3: goto L_8007B570; break;
        case 4: goto L_8007B570; break;
        case 5: goto L_8007B570; break;
        case 6: goto L_8007B570; break;
        case 7: goto L_8007B570; break;
        default: switch_error(__func__, 0x8007B540, 0x80105598);
    }
    // 0x8007B544: nop

L_8007B548:
    // 0x8007B548: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x8007B54C: beql        $v1, $at, L_8007B574
    if (ctx->r3 == ctx->r1) {
        // 0x8007B550: lh          $t3, 0x22($s1)
        ctx->r11 = S32(MEM_H(ctx->r17, 0X22));
            goto L_8007B574;
    }
    goto skip_21;
    // 0x8007B550: lh          $t3, 0x22($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0X22));
    skip_21:
    // 0x8007B554: b           L_8007B580
    // 0x8007B558: lh          $v0, 0x1C($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X1C));
        goto L_8007B580;
    // 0x8007B558: lh          $v0, 0x1C($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X1C));
L_8007B55C:
    // 0x8007B55C: addiu       $at, $zero, 0x60E
    ctx->r1 = ADD32(0, 0X60E);
    // 0x8007B560: beq         $v1, $at, L_8007B570
    if (ctx->r3 == ctx->r1) {
        // 0x8007B564: addiu       $at, $zero, 0x71C
        ctx->r1 = ADD32(0, 0X71C);
            goto L_8007B570;
    }
    // 0x8007B564: addiu       $at, $zero, 0x71C
    ctx->r1 = ADD32(0, 0X71C);
    // 0x8007B568: bnel        $v1, $at, L_8007B580
    if (ctx->r3 != ctx->r1) {
        // 0x8007B56C: lh          $v0, 0x1C($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0X1C));
            goto L_8007B580;
    }
    goto skip_22;
    // 0x8007B56C: lh          $v0, 0x1C($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X1C));
    skip_22:
L_8007B570:
    // 0x8007B570: lh          $t3, 0x22($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0X22));
L_8007B574:
    // 0x8007B574: bgtzl       $t3, L_8007BC18
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007B578: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_23;
    // 0x8007B578: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_23:
L_8007B57C:
    // 0x8007B57C: lh          $v0, 0x1C($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X1C));
L_8007B580:
    // 0x8007B580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007B584: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007B588: blez        $v0, L_8007B598
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B58C: negu        $s2, $v0
        ctx->r18 = SUB32(0, ctx->r2);
            goto L_8007B598;
    }
    // 0x8007B58C: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x8007B590: b           L_8007B598
    // 0x8007B594: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_8007B598;
    // 0x8007B594: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8007B598:
    // 0x8007B598: beq         $s2, $zero, L_8007B5C4
    if (ctx->r18 == 0) {
        // 0x8007B59C: lw          $t4, 0x60($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B5C4;
    }
    // 0x8007B59C: lw          $t4, 0x60($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X60));
    // 0x8007B5A0: bne         $fp, $at, L_8007B5C4
    if (ctx->r30 != ctx->r1) {
        // 0x8007B5A4: lw          $t6, 0x4C($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X4C));
            goto L_8007B5C4;
    }
    // 0x8007B5A4: lw          $t6, 0x4C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8007B5A8: lw          $t7, 0x0($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X0));
    // 0x8007B5AC: lw          $t5, 0x8($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X8));
    // 0x8007B5B0: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x8007B5B4: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8007B5B8: beq         $at, $zero, L_8007B5C4
    if (ctx->r1 == 0) {
        // 0x8007B5BC: nop
    
            goto L_8007B5C4;
    }
    // 0x8007B5BC: nop

    // 0x8007B5C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007B5C4:
    // 0x8007B5C4: beq         $s2, $zero, L_8007B5F0
    if (ctx->r18 == 0) {
        // 0x8007B5C8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8007B5F0;
    }
    // 0x8007B5C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B5CC: bne         $fp, $at, L_8007B5F0
    if (ctx->r30 != ctx->r1) {
        // 0x8007B5D0: lw          $t0, 0x4C($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
            goto L_8007B5F0;
    }
    // 0x8007B5D0: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8007B5D4: lw          $t8, 0x4($t0)
    ctx->r24 = S32(MEM_W(ctx->r8, 0X4));
    // 0x8007B5D8: lw          $t1, 0x8($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X8));
    // 0x8007B5DC: subu        $t2, $t8, $s2
    ctx->r10 = SUB32(ctx->r24, ctx->r18);
    // 0x8007B5E0: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8007B5E4: beq         $at, $zero, L_8007B5F0
    if (ctx->r1 == 0) {
        // 0x8007B5E8: nop
    
            goto L_8007B5F0;
    }
    // 0x8007B5E8: nop

    // 0x8007B5EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007B5F0:
    // 0x8007B5F0: bne         $fp, $zero, L_8007B674
    if (ctx->r30 != 0) {
        // 0x8007B5F4: nop
    
            goto L_8007B674;
    }
    // 0x8007B5F4: nop

    // 0x8007B5F8: bnel        $t4, $zero, L_8007B62C
    if (ctx->r12 != 0) {
        // 0x8007B5FC: lh          $v1, 0x16($s4)
        ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
            goto L_8007B62C;
    }
    goto skip_24;
    // 0x8007B5FC: lh          $v1, 0x16($s4)
    ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
    skip_24:
    // 0x8007B600: lw          $t3, 0x8($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X8));
    // 0x8007B604: lw          $t6, 0x8($s4)
    ctx->r14 = S32(MEM_W(ctx->r20, 0X8));
    // 0x8007B608: subu        $v0, $t3, $t6
    ctx->r2 = SUB32(ctx->r11, ctx->r14);
    // 0x8007B60C: blez        $v0, L_8007B61C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B610: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_8007B61C;
    }
    // 0x8007B610: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8007B614: b           L_8007B61C
    // 0x8007B618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8007B61C;
    // 0x8007B618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8007B61C:
    // 0x8007B61C: slti        $at, $v1, 0x1000
    ctx->r1 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // 0x8007B620: beq         $at, $zero, L_8007B674
    if (ctx->r1 == 0) {
        // 0x8007B624: nop
    
            goto L_8007B674;
    }
    // 0x8007B624: nop

    // 0x8007B628: lh          $v1, 0x16($s4)
    ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
L_8007B62C:
    // 0x8007B62C: lw          $t0, 0x60($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X60));
    // 0x8007B630: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007B634: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B638: mflo        $t7
    ctx->r15 = lo;
    // 0x8007B63C: addu        $t5, $s5, $t7
    ctx->r13 = ADD32(ctx->r21, ctx->r15);
    // 0x8007B640: lh          $t9, 0x16($t5)
    ctx->r25 = S32(MEM_H(ctx->r13, 0X16));
    // 0x8007B644: beq         $t9, $v1, L_8007B674
    if (ctx->r25 == ctx->r3) {
        // 0x8007B648: nop
    
            goto L_8007B674;
    }
    // 0x8007B648: nop

    // 0x8007B64C: beq         $t0, $zero, L_8007B674
    if (ctx->r8 == 0) {
        // 0x8007B650: lw          $t8, 0x44($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X44));
            goto L_8007B674;
    }
    // 0x8007B650: lw          $t8, 0x44($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8007B654: lw          $v0, 0x30($t8)
    ctx->r2 = S32(MEM_W(ctx->r24, 0X30));
    // 0x8007B658: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007B65C: blez        $v0, L_8007B674
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B660: nop
    
            goto L_8007B674;
    }
    // 0x8007B660: nop

    // 0x8007B664: beq         $a1, $at, L_8007B674
    if (ctx->r5 == ctx->r1) {
        // 0x8007B668: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8007B674;
    }
    // 0x8007B668: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8007B66C: b           L_8007BC20
    // 0x8007B670: sw          $t2, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r10;
        goto L_8007BC20;
    // 0x8007B670: sw          $t2, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r10;
L_8007B674:
    // 0x8007B674: beql        $a0, $zero, L_8007BC18
    if (ctx->r4 == 0) {
        // 0x8007B678: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_25;
    // 0x8007B678: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_25:
    // 0x8007B67C: lh          $v1, 0xE($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0XE));
    // 0x8007B680: slti        $at, $v1, 0x65F
    ctx->r1 = SIGNED(ctx->r3) < 0X65F ? 1 : 0;
    // 0x8007B684: bne         $at, $zero, L_8007B6C4
    if (ctx->r1 != 0) {
        // 0x8007B688: addiu       $at, $zero, 0x8DE
        ctx->r1 = ADD32(0, 0X8DE);
            goto L_8007B6C4;
    }
    // 0x8007B688: addiu       $at, $zero, 0x8DE
    ctx->r1 = ADD32(0, 0X8DE);
    // 0x8007B68C: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B690: addiu       $at, $zero, 0x8DF
        ctx->r1 = ADD32(0, 0X8DF);
            goto L_8007BC14;
    }
    // 0x8007B690: addiu       $at, $zero, 0x8DF
    ctx->r1 = ADD32(0, 0X8DF);
    // 0x8007B694: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B698: addiu       $at, $zero, 0x906
        ctx->r1 = ADD32(0, 0X906);
            goto L_8007BC14;
    }
    // 0x8007B698: addiu       $at, $zero, 0x906
    ctx->r1 = ADD32(0, 0X906);
    // 0x8007B69C: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6A0: addiu       $at, $zero, 0x907
        ctx->r1 = ADD32(0, 0X907);
            goto L_8007BC14;
    }
    // 0x8007B6A0: addiu       $at, $zero, 0x907
    ctx->r1 = ADD32(0, 0X907);
    // 0x8007B6A4: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6A8: addiu       $at, $zero, 0xA06
        ctx->r1 = ADD32(0, 0XA06);
            goto L_8007BC14;
    }
    // 0x8007B6A8: addiu       $at, $zero, 0xA06
    ctx->r1 = ADD32(0, 0XA06);
    // 0x8007B6AC: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6B0: addiu       $at, $zero, 0xA07
        ctx->r1 = ADD32(0, 0XA07);
            goto L_8007BC14;
    }
    // 0x8007B6B0: addiu       $at, $zero, 0xA07
    ctx->r1 = ADD32(0, 0XA07);
    // 0x8007B6B4: beql        $v1, $at, L_8007BC18
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6B8: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_26;
    // 0x8007B6B8: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_26:
    // 0x8007B6BC: b           L_8007B728
    // 0x8007B6C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
        goto L_8007B728;
    // 0x8007B6C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8007B6C4:
    // 0x8007B6C4: addiu       $at, $zero, 0x295
    ctx->r1 = ADD32(0, 0X295);
    // 0x8007B6C8: beq         $v1, $at, L_8007B740
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6CC: addiu       $at, $zero, 0x399
        ctx->r1 = ADD32(0, 0X399);
            goto L_8007B740;
    }
    // 0x8007B6CC: addiu       $at, $zero, 0x399
    ctx->r1 = ADD32(0, 0X399);
    // 0x8007B6D0: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6D4: addiu       $at, $zero, 0x3B8
        ctx->r1 = ADD32(0, 0X3B8);
            goto L_8007BC14;
    }
    // 0x8007B6D4: addiu       $at, $zero, 0x3B8
    ctx->r1 = ADD32(0, 0X3B8);
    // 0x8007B6D8: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6DC: addiu       $at, $zero, 0x4ED
        ctx->r1 = ADD32(0, 0X4ED);
            goto L_8007BC14;
    }
    // 0x8007B6DC: addiu       $at, $zero, 0x4ED
    ctx->r1 = ADD32(0, 0X4ED);
    // 0x8007B6E0: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6E4: addiu       $at, $zero, 0x564
        ctx->r1 = ADD32(0, 0X564);
            goto L_8007BC14;
    }
    // 0x8007B6E4: addiu       $at, $zero, 0x564
    ctx->r1 = ADD32(0, 0X564);
    // 0x8007B6E8: beq         $v1, $at, L_8007BC14
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6EC: addiu       $at, $zero, 0x58C
        ctx->r1 = ADD32(0, 0X58C);
            goto L_8007BC14;
    }
    // 0x8007B6EC: addiu       $at, $zero, 0x58C
    ctx->r1 = ADD32(0, 0X58C);
    // 0x8007B6F0: beq         $v1, $at, L_8007B708
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6F4: addiu       $at, $zero, 0x65E
        ctx->r1 = ADD32(0, 0X65E);
            goto L_8007B708;
    }
    // 0x8007B6F4: addiu       $at, $zero, 0x65E
    ctx->r1 = ADD32(0, 0X65E);
    // 0x8007B6F8: beql        $v1, $at, L_8007BC18
    if (ctx->r3 == ctx->r1) {
        // 0x8007B6FC: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_27;
    // 0x8007B6FC: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_27:
    // 0x8007B700: b           L_8007B728
    // 0x8007B704: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
        goto L_8007B728;
    // 0x8007B704: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8007B708:
    // 0x8007B708: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007B70C: bnel        $fp, $at, L_8007B728
    if (ctx->r30 != ctx->r1) {
        // 0x8007B710: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8007B728;
    }
    goto skip_28;
    // 0x8007B710: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_28:
    // 0x8007B714: lh          $t1, 0xC($s1)
    ctx->r9 = S32(MEM_H(ctx->r17, 0XC));
    // 0x8007B718: andi        $t4, $t1, 0x7FFF
    ctx->r12 = ctx->r9 & 0X7FFF;
    // 0x8007B71C: b           L_8007BC14
    // 0x8007B720: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
        goto L_8007BC14;
    // 0x8007B720: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
    // 0x8007B724: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8007B728:
    // 0x8007B728: bne         $a1, $at, L_8007B740
    if (ctx->r5 != ctx->r1) {
        // 0x8007B72C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8007B740;
    }
    // 0x8007B72C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B730: beq         $fp, $at, L_8007B740
    if (ctx->r30 == ctx->r1) {
        // 0x8007B734: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007B740;
    }
    // 0x8007B734: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007B738: bnel        $fp, $at, L_8007BC18
    if (ctx->r30 != ctx->r1) {
        // 0x8007B73C: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_29;
    // 0x8007B73C: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_29:
L_8007B740:
    // 0x8007B740: blez        $fp, L_8007B7B0
    if (SIGNED(ctx->r30) <= 0) {
        // 0x8007B744: sll         $a0, $s7, 16
        ctx->r4 = S32(ctx->r23 << 16);
            goto L_8007B7B0;
    }
    // 0x8007B744: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007B748: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B74C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8007B750: jal         0x8009D240
    // 0x8007B754: addiu       $a1, $zero, 0x564
    ctx->r5 = ADD32(0, 0X564);
    spawn(rdram, ctx);
        goto after_16;
    // 0x8007B754: addiu       $a1, $zero, 0x564
    ctx->r5 = ADD32(0, 0X564);
    after_16:
    // 0x8007B758: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8007B75C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B760: bne         $fp, $at, L_8007B7B0
    if (ctx->r30 != ctx->r1) {
        // 0x8007B764: sra         $t6, $s0, 16
        ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
            goto L_8007B7B0;
    }
    // 0x8007B764: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8007B768: lh          $t7, 0x12($s1)
    ctx->r15 = S32(MEM_H(ctx->r17, 0X12));
    // 0x8007B76C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007B770: bne         $t7, $at, L_8007B7B0
    if (ctx->r15 != ctx->r1) {
        // 0x8007B774: nop
    
            goto L_8007B7B0;
    }
    // 0x8007B774: nop

    // 0x8007B778: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B77C: lh          $t9, 0x18($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X18));
    // 0x8007B780: sll         $a0, $t6, 16
    ctx->r4 = S32(ctx->r14 << 16);
    // 0x8007B784: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B788: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8007B78C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8007B790: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x8007B794: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8007B798: mflo        $t5
    ctx->r13 = lo;
    // 0x8007B79C: addu        $v0, $s5, $t5
    ctx->r2 = ADD32(ctx->r21, ctx->r13);
    // 0x8007B7A0: sh          $t0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r8;
    // 0x8007B7A4: lh          $t2, 0x14($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, 0X14));
    // 0x8007B7A8: jal         0x80076190
    // 0x8007B7AC: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    ssp(rdram, ctx);
        goto after_17;
    // 0x8007B7AC: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    after_17:
L_8007B7B0:
    // 0x8007B7B0: beq         $fp, $zero, L_8007B7D4
    if (ctx->r30 == 0) {
        // 0x8007B7B4: lw          $t1, 0x60($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X60));
            goto L_8007B7D4;
    }
    // 0x8007B7B4: lw          $t1, 0x60($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X60));
    // 0x8007B7B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B7BC: beq         $fp, $at, L_8007BA64
    if (ctx->r30 == ctx->r1) {
        // 0x8007B7C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007BA64;
    }
    // 0x8007B7C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007B7C4: beql        $fp, $at, L_8007BB44
    if (ctx->r30 == ctx->r1) {
        // 0x8007B7C8: lh          $t3, 0x16($s4)
        ctx->r11 = S32(MEM_H(ctx->r20, 0X16));
            goto L_8007BB44;
    }
    goto skip_30;
    // 0x8007B7C8: lh          $t3, 0x16($s4)
    ctx->r11 = S32(MEM_H(ctx->r20, 0X16));
    skip_30:
    // 0x8007B7CC: b           L_8007BC18
    // 0x8007B7D0: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
        goto L_8007BC18;
    // 0x8007B7D0: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
L_8007B7D4:
    // 0x8007B7D4: beql        $t1, $zero, L_8007B9A8
    if (ctx->r9 == 0) {
        // 0x8007B7D8: lh          $t4, 0x16($s4)
        ctx->r12 = S32(MEM_H(ctx->r20, 0X16));
            goto L_8007B9A8;
    }
    goto skip_31;
    // 0x8007B7D8: lh          $t4, 0x16($s4)
    ctx->r12 = S32(MEM_H(ctx->r20, 0X16));
    skip_31:
    // 0x8007B7DC: lh          $t4, 0x12($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, 0X12));
    // 0x8007B7E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007B7E4: beql        $t4, $at, L_8007B828
    if (ctx->r12 == ctx->r1) {
        // 0x8007B7E8: lh          $t9, 0x16($s4)
        ctx->r25 = S32(MEM_H(ctx->r20, 0X16));
            goto L_8007B828;
    }
    goto skip_32;
    // 0x8007B7E8: lh          $t9, 0x16($s4)
    ctx->r25 = S32(MEM_H(ctx->r20, 0X16));
    skip_32:
    // 0x8007B7EC: jal         0x800ACE04
    // 0x8007B7F0: lh          $a0, 0x72($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X72));
    checkcursectnums(rdram, ctx);
        goto after_18;
    // 0x8007B7F0: lh          $a0, 0x72($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X72));
    after_18:
    // 0x8007B7F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007B7F8: bnel        $v0, $at, L_8007BC18
    if (ctx->r2 != ctx->r1) {
        // 0x8007B7FC: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_33;
    // 0x8007B7FC: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_33:
    // 0x8007B800: lh          $t3, 0x16($s4)
    ctx->r11 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B804: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B808: mflo        $t6
    ctx->r14 = lo;
    // 0x8007B80C: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x8007B810: jal         0x800ACE04
    // 0x8007B814: lh          $a0, 0x10($t7)
    ctx->r4 = S32(MEM_H(ctx->r15, 0X10));
    checkcursectnums(rdram, ctx);
        goto after_19;
    // 0x8007B814: lh          $a0, 0x10($t7)
    ctx->r4 = S32(MEM_H(ctx->r15, 0X10));
    after_19:
    // 0x8007B818: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007B81C: bnel        $v0, $at, L_8007BC18
    if (ctx->r2 != ctx->r1) {
        // 0x8007B820: lh          $s7, 0x6C($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
            goto L_8007BC18;
    }
    goto skip_34;
    // 0x8007B820: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    skip_34:
    // 0x8007B824: lh          $t9, 0x16($s4)
    ctx->r25 = S32(MEM_H(ctx->r20, 0X16));
L_8007B828:
    // 0x8007B828: lw          $t5, 0x0($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007B82C: lw          $t4, 0x0($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X0));
    // 0x8007B830: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B834: lw          $t6, 0x4($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007B838: mflo        $t0
    ctx->r8 = lo;
    // 0x8007B83C: addu        $t2, $s5, $t0
    ctx->r10 = ADD32(ctx->r21, ctx->r8);
    // 0x8007B840: lw          $t8, 0x0($t2)
    ctx->r24 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8007B844: addu        $t1, $t5, $t8
    ctx->r9 = ADD32(ctx->r13, ctx->r24);
    // 0x8007B848: subu        $t3, $t1, $t4
    ctx->r11 = SUB32(ctx->r9, ctx->r12);
    // 0x8007B84C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8007B850: lh          $t7, 0x16($s4)
    ctx->r15 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B854: lw          $t8, 0x4($s4)
    ctx->r24 = S32(MEM_W(ctx->r20, 0X4));
    // 0x8007B858: lw          $t4, 0x8($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X8));
    // 0x8007B85C: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B860: mflo        $t9
    ctx->r25 = lo;
    // 0x8007B864: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x8007B868: lw          $t2, 0x4($t0)
    ctx->r10 = S32(MEM_W(ctx->r8, 0X4));
    // 0x8007B86C: addu        $t5, $t6, $t2
    ctx->r13 = ADD32(ctx->r14, ctx->r10);
    // 0x8007B870: subu        $t1, $t5, $t8
    ctx->r9 = SUB32(ctx->r13, ctx->r24);
    // 0x8007B874: sw          $t1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r9;
    // 0x8007B878: lh          $t9, 0x16($s4)
    ctx->r25 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B87C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8007B880: lw          $t3, 0x8($s4)
    ctx->r11 = S32(MEM_W(ctx->r20, 0X8));
    // 0x8007B884: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B888: subu        $t7, $t4, $t3
    ctx->r15 = SUB32(ctx->r12, ctx->r11);
    // 0x8007B88C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007B890: addu        $t6, $s5, $t0
    ctx->r14 = ADD32(ctx->r21, ctx->r8);
    // 0x8007B894: lh          $t2, 0x10($t6)
    ctx->r10 = S32(MEM_H(ctx->r14, 0X10));
    // 0x8007B898: sll         $t6, $s7, 3
    ctx->r14 = S32(ctx->r23 << 3);
    // 0x8007B89C: addu        $t6, $t6, $s7
    ctx->r14 = ADD32(ctx->r14, ctx->r23);
    // 0x8007B8A0: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8007B8A4: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x8007B8A8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8007B8AC: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8007B8B0: lw          $t8, -0x1984($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X1984));
    // 0x8007B8B4: lui         $t2, 0x8028
    ctx->r10 = S32(0X8028 << 16);
    // 0x8007B8B8: addiu       $t2, $t2, -0x5C00
    ctx->r10 = ADD32(ctx->r10, -0X5C00);
    // 0x8007B8BC: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8007B8C0: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8007B8C4: lh          $t4, 0x16($s4)
    ctx->r12 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B8C8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007B8CC: lw          $t5, 0x0($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007B8D0: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B8D4: lw          $t7, 0x4($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007B8D8: addu        $v0, $t6, $t2
    ctx->r2 = ADD32(ctx->r14, ctx->r10);
    // 0x8007B8DC: mflo        $t3
    ctx->r11 = lo;
    // 0x8007B8E0: addu        $t9, $s5, $t3
    ctx->r25 = ADD32(ctx->r21, ctx->r11);
    // 0x8007B8E4: lh          $t0, 0x14($t9)
    ctx->r8 = S32(MEM_H(ctx->r25, 0X14));
    // 0x8007B8E8: sw          $t1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r9;
    // 0x8007B8EC: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x8007B8F0: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x8007B8F4: sh          $t0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r8;
    // 0x8007B8F8: lbu         $t1, 0x25($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X25);
    // 0x8007B8FC: lh          $a0, 0x7C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X7C));
    // 0x8007B900: bnel        $t1, $zero, L_8007B948
    if (ctx->r9 != 0) {
        // 0x8007B904: lh          $v1, 0x16($s4)
        ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
            goto L_8007B948;
    }
    goto skip_35;
    // 0x8007B904: lh          $v1, 0x16($s4)
    ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
    skip_35:
    // 0x8007B908: jal         0x8009D240
    // 0x8007B90C: addiu       $a1, $zero, 0x4ED
    ctx->r5 = ADD32(0, 0X4ED);
    spawn(rdram, ctx);
        goto after_20;
    // 0x8007B90C: addiu       $a1, $zero, 0x4ED
    ctx->r5 = ADD32(0, 0X4ED);
    after_20:
    // 0x8007B910: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8007B914: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B918: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8007B91C: jal         0x80059034
    // 0x8007B920: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    spritesound(rdram, ctx);
        goto after_21;
    // 0x8007B920: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_21:
    // 0x8007B924: lh          $a0, 0x16($s4)
    ctx->r4 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B928: jal         0x8009D240
    // 0x8007B92C: addiu       $a1, $zero, 0x4ED
    ctx->r5 = ADD32(0, 0X4ED);
    spawn(rdram, ctx);
        goto after_22;
    // 0x8007B92C: addiu       $a1, $zero, 0x4ED
    ctx->r5 = ADD32(0, 0X4ED);
    after_22:
    // 0x8007B930: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8007B934: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B938: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8007B93C: jal         0x80059034
    // 0x8007B940: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    spritesound(rdram, ctx);
        goto after_23;
    // 0x8007B940: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_23:
    // 0x8007B944: lh          $v1, 0x16($s4)
    ctx->r3 = S32(MEM_H(ctx->r20, 0X16));
L_8007B948:
    // 0x8007B948: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007B94C: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8007B950: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B954: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8007B958: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8007B95C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007B960: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B964: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8007B968: lw          $t2, 0x44($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8007B96C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007B970: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x8007B974: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8007B978: mflo        $t9
    ctx->r25 = lo;
    // 0x8007B97C: addu        $a2, $s5, $t9
    ctx->r6 = ADD32(ctx->r21, ctx->r25);
    // 0x8007B980: lh          $t0, 0x16($a2)
    ctx->r8 = S32(MEM_H(ctx->r6, 0X16));
    // 0x8007B984: beq         $t0, $v1, L_8007B994
    if (ctx->r8 == ctx->r3) {
        // 0x8007B988: nop
    
            goto L_8007B994;
    }
    // 0x8007B988: nop

    // 0x8007B98C: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
    // 0x8007B990: sw          $t5, -0x5BD0($at)
    MEM_W(-0X5BD0, ctx->r1) = ctx->r13;
L_8007B994:
    // 0x8007B994: jal         0x80092938
    // 0x8007B998: lh          $a1, 0x10($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
    changespritesect(rdram, ctx);
        goto after_24;
    // 0x8007B998: lh          $a1, 0x10($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0X10));
    after_24:
    // 0x8007B99C: b           L_8007BC18
    // 0x8007B9A0: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
        goto L_8007BC18;
    // 0x8007B9A0: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    // 0x8007B9A4: lh          $t4, 0x16($s4)
    ctx->r12 = S32(MEM_H(ctx->r20, 0X16));
L_8007B9A8:
    // 0x8007B9A8: lw          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007B9AC: lw          $t2, 0x0($s4)
    ctx->r10 = S32(MEM_W(ctx->r20, 0X0));
    // 0x8007B9B0: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B9B4: lw          $t7, 0x4($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007B9B8: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007B9BC: mflo        $t3
    ctx->r11 = lo;
    // 0x8007B9C0: addu        $t9, $s5, $t3
    ctx->r25 = ADD32(ctx->r21, ctx->r11);
    // 0x8007B9C4: lw          $t0, 0x0($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0X0));
    // 0x8007B9C8: addu        $t6, $t1, $t0
    ctx->r14 = ADD32(ctx->r9, ctx->r8);
    // 0x8007B9CC: subu        $t5, $t6, $t2
    ctx->r13 = SUB32(ctx->r14, ctx->r10);
    // 0x8007B9D0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8007B9D4: lh          $t8, 0x16($s4)
    ctx->r24 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B9D8: lw          $t0, 0x4($s4)
    ctx->r8 = S32(MEM_W(ctx->r20, 0X4));
    // 0x8007B9DC: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B9E0: mflo        $t4
    ctx->r12 = lo;
    // 0x8007B9E4: addu        $t3, $s5, $t4
    ctx->r11 = ADD32(ctx->r21, ctx->r12);
    // 0x8007B9E8: lw          $t9, 0x4($t3)
    ctx->r25 = S32(MEM_W(ctx->r11, 0X4));
    // 0x8007B9EC: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x8007B9F0: subu        $t6, $t1, $t0
    ctx->r14 = SUB32(ctx->r9, ctx->r8);
    // 0x8007B9F4: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8007B9F8: lh          $t2, 0x16($s4)
    ctx->r10 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007B9FC: sll         $t7, $s7, 3
    ctx->r15 = S32(ctx->r23 << 3);
    // 0x8007BA00: addu        $t7, $t7, $s7
    ctx->r15 = ADD32(ctx->r15, ctx->r23);
    // 0x8007BA04: multu       $t2, $s6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BA08: lui         $t9, 0x8028
    ctx->r25 = S32(0X8028 << 16);
    // 0x8007BA0C: addiu       $t9, $t9, -0x5C00
    ctx->r25 = ADD32(ctx->r25, -0X5C00);
    // 0x8007BA10: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007BA14: lw          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007BA18: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x8007BA1C: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007BA20: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8007BA24: mflo        $t5
    ctx->r13 = lo;
    // 0x8007BA28: addu        $t8, $s5, $t5
    ctx->r24 = ADD32(ctx->r21, ctx->r13);
    // 0x8007BA2C: lw          $t4, 0x8($t8)
    ctx->r12 = S32(MEM_W(ctx->r24, 0X8));
    // 0x8007BA30: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x8007BA34: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x8007BA38: addiu       $t3, $t4, 0x1000
    ctx->r11 = ADD32(ctx->r12, 0X1000);
    // 0x8007BA3C: sw          $t3, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r11;
    // 0x8007BA40: lh          $t5, 0x16($s4)
    ctx->r13 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007BA44: sw          $t3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r11;
    // 0x8007BA48: multu       $t5, $s6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BA4C: mflo        $t8
    ctx->r24 = lo;
    // 0x8007BA50: addu        $t4, $s5, $t8
    ctx->r12 = ADD32(ctx->r21, ctx->r24);
    // 0x8007BA54: jal         0x80092938
    // 0x8007BA58: lh          $a1, 0x10($t4)
    ctx->r5 = S32(MEM_H(ctx->r12, 0X10));
    changespritesect(rdram, ctx);
        goto after_25;
    // 0x8007BA58: lh          $a1, 0x10($t4)
    ctx->r5 = S32(MEM_H(ctx->r12, 0X10));
    after_25:
    // 0x8007BA5C: b           L_8007BC18
    // 0x8007BA60: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
        goto L_8007BC18;
    // 0x8007BA60: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
L_8007BA64:
    // 0x8007BA64: lh          $t7, 0x16($s4)
    ctx->r15 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007BA68: lw          $t3, 0x0($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007BA6C: lw          $t2, 0x0($s4)
    ctx->r10 = S32(MEM_W(ctx->r20, 0X0));
    // 0x8007BA70: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BA74: lw          $t8, 0x4($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007BA78: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007BA7C: mflo        $t9
    ctx->r25 = lo;
    // 0x8007BA80: addu        $t1, $s5, $t9
    ctx->r9 = ADD32(ctx->r21, ctx->r25);
    // 0x8007BA84: lw          $t0, 0x0($t1)
    ctx->r8 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8007BA88: addu        $t6, $t3, $t0
    ctx->r14 = ADD32(ctx->r11, ctx->r8);
    // 0x8007BA8C: subu        $t5, $t6, $t2
    ctx->r13 = SUB32(ctx->r14, ctx->r10);
    // 0x8007BA90: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8007BA94: lh          $t4, 0x16($s4)
    ctx->r12 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007BA98: lw          $t0, 0x4($s4)
    ctx->r8 = S32(MEM_W(ctx->r20, 0X4));
    // 0x8007BA9C: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BAA0: mflo        $t7
    ctx->r15 = lo;
    // 0x8007BAA4: addu        $t9, $s5, $t7
    ctx->r25 = ADD32(ctx->r21, ctx->r15);
    // 0x8007BAA8: lw          $t1, 0x4($t9)
    ctx->r9 = S32(MEM_W(ctx->r25, 0X4));
    // 0x8007BAAC: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x8007BAB0: subu        $t6, $t3, $t0
    ctx->r14 = SUB32(ctx->r11, ctx->r8);
    // 0x8007BAB4: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8007BAB8: lh          $t2, 0x16($s4)
    ctx->r10 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007BABC: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8007BAC0: sll         $t3, $s7, 3
    ctx->r11 = S32(ctx->r23 << 3);
    // 0x8007BAC4: multu       $t2, $s6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BAC8: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x8007BACC: lui         $t0, 0x8028
    ctx->r8 = S32(0X8028 << 16);
    // 0x8007BAD0: addiu       $t0, $t0, -0x5C00
    ctx->r8 = ADD32(ctx->r8, -0X5C00);
    // 0x8007BAD4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8007BAD8: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007BADC: lw          $t2, 0x4($s1)
    ctx->r10 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007BAE0: addu        $v0, $t3, $t0
    ctx->r2 = ADD32(ctx->r11, ctx->r8);
    // 0x8007BAE4: mflo        $t5
    ctx->r13 = lo;
    // 0x8007BAE8: addu        $t4, $s5, $t5
    ctx->r12 = ADD32(ctx->r21, ctx->r13);
    // 0x8007BAEC: lh          $t7, 0x10($t4)
    ctx->r15 = S32(MEM_H(ctx->r12, 0X10));
    // 0x8007BAF0: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007BAF4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8007BAF8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007BAFC: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8007BB00: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8007BB04: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8007BB08: lw          $t8, -0x1988($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X1988));
    // 0x8007BB0C: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x8007BB10: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
    // 0x8007BB14: addu        $t1, $t8, $s2
    ctx->r9 = ADD32(ctx->r24, ctx->r18);
    // 0x8007BB18: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8007BB1C: lh          $t7, 0x16($s4)
    ctx->r15 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007BB20: sw          $t1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r9;
    // 0x8007BB24: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BB28: mflo        $t9
    ctx->r25 = lo;
    // 0x8007BB2C: addu        $t8, $s5, $t9
    ctx->r24 = ADD32(ctx->r21, ctx->r25);
    // 0x8007BB30: jal         0x80092938
    // 0x8007BB34: lh          $a1, 0x10($t8)
    ctx->r5 = S32(MEM_H(ctx->r24, 0X10));
    changespritesect(rdram, ctx);
        goto after_26;
    // 0x8007BB34: lh          $a1, 0x10($t8)
    ctx->r5 = S32(MEM_H(ctx->r24, 0X10));
    after_26:
    // 0x8007BB38: b           L_8007BC18
    // 0x8007BB3C: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
        goto L_8007BC18;
    // 0x8007BB3C: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
    // 0x8007BB40: lh          $t3, 0x16($s4)
    ctx->r11 = S32(MEM_H(ctx->r20, 0X16));
L_8007BB44:
    // 0x8007BB44: lw          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007BB48: lw          $t4, 0x0($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X0));
    // 0x8007BB4C: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BB50: lw          $t9, 0x4($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007BB54: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x8007BB58: mflo        $t0
    ctx->r8 = lo;
    // 0x8007BB5C: addu        $t6, $s5, $t0
    ctx->r14 = ADD32(ctx->r21, ctx->r8);
    // 0x8007BB60: lw          $t2, 0x0($t6)
    ctx->r10 = S32(MEM_W(ctx->r14, 0X0));
    // 0x8007BB64: addu        $t5, $t1, $t2
    ctx->r13 = ADD32(ctx->r9, ctx->r10);
    // 0x8007BB68: subu        $t7, $t5, $t4
    ctx->r15 = SUB32(ctx->r13, ctx->r12);
    // 0x8007BB6C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8007BB70: lh          $t8, 0x16($s4)
    ctx->r24 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007BB74: lw          $t2, 0x4($s4)
    ctx->r10 = S32(MEM_W(ctx->r20, 0X4));
    // 0x8007BB78: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BB7C: mflo        $t3
    ctx->r11 = lo;
    // 0x8007BB80: addu        $t0, $s5, $t3
    ctx->r8 = ADD32(ctx->r21, ctx->r11);
    // 0x8007BB84: lw          $t6, 0x4($t0)
    ctx->r14 = S32(MEM_W(ctx->r8, 0X4));
    // 0x8007BB88: addu        $t1, $t9, $t6
    ctx->r9 = ADD32(ctx->r25, ctx->r14);
    // 0x8007BB8C: subu        $t5, $t1, $t2
    ctx->r13 = SUB32(ctx->r9, ctx->r10);
    // 0x8007BB90: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    // 0x8007BB94: lh          $t4, 0x16($s4)
    ctx->r12 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007BB98: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x8007BB9C: sll         $t1, $s7, 3
    ctx->r9 = S32(ctx->r23 << 3);
    // 0x8007BBA0: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BBA4: addu        $t1, $t1, $s7
    ctx->r9 = ADD32(ctx->r9, ctx->r23);
    // 0x8007BBA8: lui         $t2, 0x8028
    ctx->r10 = S32(0X8028 << 16);
    // 0x8007BBAC: addiu       $t2, $t2, -0x5C00
    ctx->r10 = ADD32(ctx->r10, -0X5C00);
    // 0x8007BBB0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007BBB4: lw          $t5, 0x0($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007BBB8: lw          $t4, 0x4($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007BBBC: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8007BBC0: mflo        $t7
    ctx->r15 = lo;
    // 0x8007BBC4: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8007BBC8: lh          $t3, 0x10($t8)
    ctx->r11 = S32(MEM_H(ctx->r24, 0X10));
    // 0x8007BBCC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007BBD0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8007BBD4: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x8007BBD8: subu        $t0, $t0, $t3
    ctx->r8 = SUB32(ctx->r8, ctx->r11);
    // 0x8007BBDC: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8007BBE0: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8007BBE4: lw          $t9, -0x1984($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X1984));
    // 0x8007BBE8: sw          $t5, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r13;
    // 0x8007BBEC: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
    // 0x8007BBF0: subu        $t6, $t9, $s2
    ctx->r14 = SUB32(ctx->r25, ctx->r18);
    // 0x8007BBF4: sw          $t6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r14;
    // 0x8007BBF8: lh          $t3, 0x16($s4)
    ctx->r11 = S32(MEM_H(ctx->r20, 0X16));
    // 0x8007BBFC: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x8007BC00: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BC04: mflo        $t0
    ctx->r8 = lo;
    // 0x8007BC08: addu        $t9, $s5, $t0
    ctx->r25 = ADD32(ctx->r21, ctx->r8);
    // 0x8007BC0C: jal         0x80092938
    // 0x8007BC10: lh          $a1, 0x10($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, 0X10));
    changespritesect(rdram, ctx);
        goto after_27;
    // 0x8007BC10: lh          $a1, 0x10($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, 0X10));
    after_27:
L_8007BC14:
    // 0x8007BC14: lh          $s7, 0x6C($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X6C));
L_8007BC18:
    // 0x8007BC18: bgez        $s7, L_8007AE80
    if (SIGNED(ctx->r23) >= 0) {
        // 0x8007BC1C: nop
    
            goto L_8007AE80;
    }
    // 0x8007BC1C: nop

L_8007BC20:
    // 0x8007BC20: lh          $t1, 0x6E($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X6E));
L_8007BC24:
    // 0x8007BC24: sh          $t1, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r9;
L_8007BC28:
    // 0x8007BC28: lh          $t2, 0x7C($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X7C));
    // 0x8007BC2C: bgezl       $t2, L_8007ADD0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007BC30: lh          $v1, 0x7C($sp)
        ctx->r3 = S32(MEM_H(ctx->r29, 0X7C));
            goto L_8007ADD0;
    }
    goto skip_36;
    // 0x8007BC30: lh          $v1, 0x7C($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X7C));
    skip_36:
L_8007BC34:
    // 0x8007BC34: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8007BC38: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8007BC3C: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8007BC40: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8007BC44: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8007BC48: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8007BC4C: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8007BC50: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8007BC54: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8007BC58: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8007BC5C: jr          $ra
    // 0x8007BC60: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8007BC60: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800624B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800624B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800624B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800624BC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800624C0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800624C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800624C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800624CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800624D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800624D4: jal         0x80062304
    // 0x800624D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80062304(rdram, ctx);
        goto after_0;
    // 0x800624D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800624DC: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x800624E0: lw          $v1, -0x5244($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5244));
    // 0x800624E4: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x800624E8: addiu       $s3, $s3, -0x5B00
    ctx->r19 = ADD32(ctx->r19, -0X5B00);
    // 0x800624EC: blez        $v1, L_80062588
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800624F0: lui         $s6, 0x8026
        ctx->r22 = S32(0X8026 << 16);
            goto L_80062588;
    }
    // 0x800624F0: lui         $s6, 0x8026
    ctx->r22 = S32(0X8026 << 16);
    // 0x800624F4: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x800624F8: addiu       $s4, $s4, -0x1988
    ctx->r20 = ADD32(ctx->r20, -0X1988);
    // 0x800624FC: addiu       $s6, $s6, -0x3C70
    ctx->r22 = ADD32(ctx->r22, -0X3C70);
    // 0x80062500: addiu       $s5, $zero, 0x30
    ctx->r21 = ADD32(0, 0X30);
    // 0x80062504: lhu         $s1, 0x0($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X0);
L_80062508:
    // 0x80062508: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x8006250C: addiu       $t9, $t9, -0x5B00
    ctx->r25 = ADD32(ctx->r25, -0X5B00);
    // 0x80062510: multu       $s1, $s5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062514: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80062518: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x8006251C: mflo        $t6
    ctx->r14 = lo;
    // 0x80062520: addu        $s2, $s4, $t6
    ctx->r18 = ADD32(ctx->r20, ctx->r14);
    // 0x80062524: lbu         $t7, 0x2B($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X2B);
    // 0x80062528: bne         $t7, $zero, L_80062538
    if (ctx->r15 != 0) {
        // 0x8006252C: nop
    
            goto L_80062538;
    }
    // 0x8006252C: nop

    // 0x80062530: b           L_80062578
    // 0x80062534: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
        goto L_80062578;
    // 0x80062534: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
L_80062538:
    // 0x80062538: jal         0x8005A5D4
    // 0x8006253C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    floorupdatez(rdram, ctx);
        goto after_1;
    // 0x8006253C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_1:
    // 0x80062540: jal         0x80062804
    // 0x80062544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80062804(rdram, ctx);
        goto after_2;
    // 0x80062544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80062548: jal         0x8006230C
    // 0x8006254C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_8006230C(rdram, ctx);
        goto after_3;
    // 0x8006254C: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_3:
    // 0x80062550: jal         0x80061904
    // 0x80062554: lh          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X14));
    func_80061904(rdram, ctx);
        goto after_4;
    // 0x80062554: lh          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X14));
    after_4:
    // 0x80062558: jal         0x800616A8
    // 0x8006255C: lh          $a0, 0x2($s6)
    ctx->r4 = S32(MEM_H(ctx->r22, 0X2));
    func_800616A8(rdram, ctx);
        goto after_5;
    // 0x8006255C: lh          $a0, 0x2($s6)
    ctx->r4 = S32(MEM_H(ctx->r22, 0X2));
    after_5:
    // 0x80062560: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80062564: lw          $v1, -0x5244($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5244));
    // 0x80062568: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x8006256C: addiu       $t1, $t1, -0x5B00
    ctx->r9 = ADD32(ctx->r9, -0X5B00);
    // 0x80062570: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x80062574: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_80062578:
    // 0x80062578: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8006257C: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x80062580: bnel        $at, $zero, L_80062508
    if (ctx->r1 != 0) {
        // 0x80062584: lhu         $s1, 0x0($s3)
        ctx->r17 = MEM_HU(ctx->r19, 0X0);
            goto L_80062508;
    }
    goto skip_0;
    // 0x80062584: lhu         $s1, 0x0($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X0);
    skip_0:
L_80062588:
    // 0x80062588: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x8006258C: lw          $v1, -0x5248($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5248));
    // 0x80062590: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x80062594: lui         $s6, 0x8026
    ctx->r22 = S32(0X8026 << 16);
    // 0x80062598: addiu       $s6, $s6, -0x3C70
    ctx->r22 = ADD32(ctx->r22, -0X3C70);
    // 0x8006259C: addiu       $s4, $s4, -0x1988
    ctx->r20 = ADD32(ctx->r20, -0X1988);
    // 0x800625A0: blez        $v1, L_80062634
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800625A4: addiu       $s5, $zero, 0x30
        ctx->r21 = ADD32(0, 0X30);
            goto L_80062634;
    }
    // 0x800625A4: addiu       $s5, $zero, 0x30
    ctx->r21 = ADD32(0, 0X30);
    // 0x800625A8: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x800625AC: addiu       $s3, $s3, -0x5C00
    ctx->r19 = ADD32(ctx->r19, -0X5C00);
    // 0x800625B0: lhu         $s1, 0x0($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X0);
L_800625B4:
    // 0x800625B4: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800625B8: addiu       $t5, $t5, -0x5C00
    ctx->r13 = ADD32(ctx->r13, -0X5C00);
    // 0x800625BC: multu       $s1, $s5
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800625C0: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x800625C4: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800625C8: mflo        $t2
    ctx->r10 = lo;
    // 0x800625CC: addu        $s2, $s4, $t2
    ctx->r18 = ADD32(ctx->r20, ctx->r10);
    // 0x800625D0: lbu         $t3, 0x2C($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X2C);
    // 0x800625D4: bne         $t3, $zero, L_800625E4
    if (ctx->r11 != 0) {
        // 0x800625D8: nop
    
            goto L_800625E4;
    }
    // 0x800625D8: nop

    // 0x800625DC: b           L_80062624
    // 0x800625E0: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
        goto L_80062624;
    // 0x800625E0: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_800625E4:
    // 0x800625E4: jal         0x8005A70C
    // 0x800625E8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    updateceilz(rdram, ctx);
        goto after_6;
    // 0x800625E8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_6:
    // 0x800625EC: jal         0x8006230C
    // 0x800625F0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_8006230C(rdram, ctx);
        goto after_7;
    // 0x800625F0: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_7:
    // 0x800625F4: jal         0x80062AD0
    // 0x800625F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80062AD0(rdram, ctx);
        goto after_8;
    // 0x800625F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x800625FC: jal         0x80061904
    // 0x80062600: lh          $a0, 0x10($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X10));
    func_80061904(rdram, ctx);
        goto after_9;
    // 0x80062600: lh          $a0, 0x10($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X10));
    after_9:
    // 0x80062604: jal         0x800616A8
    // 0x80062608: lh          $a0, 0x2($s6)
    ctx->r4 = S32(MEM_H(ctx->r22, 0X2));
    func_800616A8(rdram, ctx);
        goto after_10;
    // 0x80062608: lh          $a0, 0x2($s6)
    ctx->r4 = S32(MEM_H(ctx->r22, 0X2));
    after_10:
    // 0x8006260C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80062610: lw          $v1, -0x5248($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5248));
    // 0x80062614: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80062618: addiu       $t7, $t7, -0x5C00
    ctx->r15 = ADD32(ctx->r15, -0X5C00);
    // 0x8006261C: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80062620: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_80062624:
    // 0x80062624: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80062628: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8006262C: bnel        $at, $zero, L_800625B4
    if (ctx->r1 != 0) {
        // 0x80062630: lhu         $s1, 0x0($s3)
        ctx->r17 = MEM_HU(ctx->r19, 0X0);
            goto L_800625B4;
    }
    goto skip_1;
    // 0x80062630: lhu         $s1, 0x0($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X0);
    skip_1:
L_80062634:
    // 0x80062634: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80062638: addiu       $a0, $a0, 0x4418
    ctx->r4 = ADD32(ctx->r4, 0X4418);
    // 0x8006263C: lw          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80062640: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x80062644: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x80062648: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006264C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80062650: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80062654: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80062658: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8006265C: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80062660: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80062664: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80062668: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8006266C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80062670: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80062674: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80062678: jr          $ra
    // 0x8006267C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006267C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _saveBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0740: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D0744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D0748: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D074C: lw          $v1, 0x1C($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X1C));
    // 0x800D0750: lw          $v0, 0x14($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800D0754: lw          $t0, 0x70($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800D0758: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800D075C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800D0760: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800D0764: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x800D0768: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x800D076C: beq         $at, $zero, L_800D0778
    if (ctx->r1 == 0) {
        // 0x800D0770: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_800D0778;
    }
    // 0x800D0770: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x800D0774: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_800D0778:
    // 0x800D0778: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x800D077C: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x800D0780: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x800D0784: beq         $at, $zero, L_800D0878
    if (ctx->r1 == 0) {
        // 0x800D0788: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_800D0878;
    }
    // 0x800D0788: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800D078C: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x800D0790: sra         $t8, $t3, 1
    ctx->r24 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800D0794: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800D0798: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800D079C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800D07A0: andi        $t8, $t3, 0xFFFF
    ctx->r24 = ctx->r11 & 0XFFFF;
    // 0x800D07A4: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800D07A8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800D07AC: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800D07B0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800D07B4: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x800D07B8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800D07BC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800D07C0: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800D07C4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800D07C8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D07CC: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800D07D0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800D07D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800D07D8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800D07DC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D07E0: jal         0x800BF6F0
    // 0x800D07E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800D07E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800D07E8: lw          $t4, 0x44($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800D07EC: lw          $a3, 0x28($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800D07F0: lw          $t1, 0x4C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800D07F4: lw          $t3, 0x24($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800D07F8: lw          $t5, 0x68($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800D07FC: lw          $t2, 0x60($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800D0800: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D0804: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800D0808: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x800D080C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D0810: subu        $t7, $a3, $t1
    ctx->r15 = SUB32(ctx->r7, ctx->r9);
    // 0x800D0814: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800D0818: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800D081C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800D0820: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800D0824: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800D0828: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D082C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D0830: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800D0834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D0838: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800D083C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800D0840: lw          $a0, 0x14($t2)
    ctx->r4 = S32(MEM_W(ctx->r10, 0X14));
    // 0x800D0844: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800D0848: jal         0x800BF6F0
    // 0x800D084C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800D084C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x800D0850: lw          $a1, 0x3C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800D0854: lw          $a2, 0x2C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800D0858: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D085C: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x800D0860: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800D0864: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800D0868: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D086C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D0870: b           L_800D08B4
    // 0x800D0874: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800D08B4;
    // 0x800D0874: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800D0878:
    // 0x800D0878: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x800D087C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800D0880: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800D0884: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800D0888: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D088C: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800D0890: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800D0894: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800D0898: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D089C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800D08A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800D08A4: jal         0x800BF6F0
    // 0x800D08A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800D08A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800D08AC: lw          $v1, 0x30($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800D08B0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800D08B4:
    // 0x800D08B4: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800D08B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800D08BC: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800D08C0: jr          $ra
    // 0x800D08C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D08C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void divscale14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009140C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091414: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091418: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009141C: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80091420: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091424: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091428: jal         0x800BB834
    // 0x8009142C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x8009142C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091434: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091438: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8009143C: jal         0x800BB89C
    // 0x80091440: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091440: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091444: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009144C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091450: jr          $ra
    // 0x80091454: nop

    return;
    // 0x80091454: nop

;}
RECOMP_FUNC void divscale13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800913C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800913C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800913C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800913CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800913D0: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x800913D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800913D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800913DC: jal         0x800BB834
    // 0x800913E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800913E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800913E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800913E8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800913EC: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800913F0: jal         0x800BB89C
    // 0x800913F4: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800913F4: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x800913F8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800913FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091400: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091404: jr          $ra
    // 0x80091408: nop

    return;
    // 0x80091408: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8BC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C8BC4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C8BC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C8BCC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C8BD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C8BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C8BD8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800C8BDC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800C8BE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800C8BE4:
    // 0x800C8BE4: bnel        $v0, $zero, L_800C8BF8
    if (ctx->r2 != 0) {
        // 0x800C8BE8: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_800C8BF8;
    }
    goto skip_0;
    // 0x800C8BE8: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x800C8BEC: b           L_800C8BF8
    // 0x800C8BF0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_800C8BF8;
    // 0x800C8BF0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800C8BF4: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_800C8BF8:
    // 0x800C8BF8: bnel        $v0, $a0, L_800C8C0C
    if (ctx->r2 != ctx->r4) {
        // 0x800C8BFC: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_800C8C0C;
    }
    goto skip_1;
    // 0x800C8BFC: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x800C8C00: b           L_800C8C0C
    // 0x800C8C04: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_800C8C0C;
    // 0x800C8C04: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800C8C08: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_800C8C0C:
    // 0x800C8C0C: bnel        $v0, $a1, L_800C8C20
    if (ctx->r2 != ctx->r5) {
        // 0x800C8C10: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_800C8C20;
    }
    goto skip_2;
    // 0x800C8C10: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x800C8C14: b           L_800C8C20
    // 0x800C8C18: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_800C8C20;
    // 0x800C8C18: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800C8C1C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_800C8C20:
    // 0x800C8C20: bnel        $v0, $a2, L_800C8C34
    if (ctx->r2 != ctx->r6) {
        // 0x800C8C24: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_800C8C34;
    }
    goto skip_3;
    // 0x800C8C24: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x800C8C28: b           L_800C8C34
    // 0x800C8C2C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_800C8C34;
    // 0x800C8C2C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800C8C30: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_800C8C34:
    // 0x800C8C34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C8C38: bne         $v0, $a3, L_800C8BE4
    if (ctx->r2 != ctx->r7) {
        // 0x800C8C3C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800C8BE4;
    }
    // 0x800C8C3C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C8C40: jr          $ra
    // 0x800C8C44: nop

    return;
    // 0x800C8C44: nop

;}
RECOMP_FUNC void __voiceNeedsNoteKill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA898: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CA89C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA8A0: lw          $a3, 0x50($a0)
    ctx->r7 = S32(MEM_W(ctx->r4, 0X50));
    // 0x800CA8A4: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800CA8A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800CA8AC: beq         $a3, $zero, L_800CA92C
    if (ctx->r7 == 0) {
        // 0x800CA8B0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800CA92C;
    }
    // 0x800CA8B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CA8B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800CA8B8:
    // 0x800CA8B8: lh          $t6, 0xC($a3)
    ctx->r14 = S32(MEM_H(ctx->r7, 0XC));
    // 0x800CA8BC: lw          $v1, 0x8($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA8C0: lw          $v0, 0x0($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X0));
    // 0x800CA8C4: bne         $a0, $t6, L_800CA924
    if (ctx->r4 != ctx->r14) {
        // 0x800CA8C8: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_800CA924;
    }
    // 0x800CA8C8: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x800CA8CC: lw          $t7, 0x10($a3)
    ctx->r15 = S32(MEM_W(ctx->r7, 0X10));
    // 0x800CA8D0: bne         $a1, $t7, L_800CA924
    if (ctx->r5 != ctx->r15) {
        // 0x800CA8D4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800CA924;
    }
    // 0x800CA8D4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CA8D8: beq         $at, $zero, L_800CA91C
    if (ctx->r1 == 0) {
        // 0x800CA8DC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800CA91C;
    }
    // 0x800CA8DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800CA8E0: beql        $v0, $zero, L_800CA8F8
    if (ctx->r2 == 0) {
        // 0x800CA8E4: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800CA8F8;
    }
    goto skip_0;
    // 0x800CA8E4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    skip_0:
    // 0x800CA8E8: lw          $t8, 0x8($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800CA8EC: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800CA8F0: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x800CA8F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
L_800CA8F8:
    // 0x800CA8F8: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    // 0x800CA8FC: jal         0x800BF770
    // 0x800CA900: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800CA900: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_0:
    // 0x800CA904: lw          $t2, 0x30($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800CA908: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800CA90C: jal         0x800BF7A0
    // 0x800CA910: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800CA910: addiu       $a1, $t2, 0x48
    ctx->r5 = ADD32(ctx->r10, 0X48);
    after_1:
    // 0x800CA914: b           L_800CA92C
    // 0x800CA918: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
        goto L_800CA92C;
    // 0x800CA918: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
L_800CA91C:
    // 0x800CA91C: b           L_800CA92C
    // 0x800CA920: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_800CA92C;
    // 0x800CA920: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800CA924:
    // 0x800CA924: bne         $v0, $zero, L_800CA8B8
    if (ctx->r2 != 0) {
        // 0x800CA928: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800CA8B8;
    }
    // 0x800CA928: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800CA92C:
    // 0x800CA92C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CA930: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CA934: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CA938: jr          $ra
    // 0x800CA93C: nop

    return;
    // 0x800CA93C: nop

;}
RECOMP_FUNC void guRotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF694: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BF698: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BF69C: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800BF6A0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BF6A4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X70));
    // 0x800BF6A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BF6AC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800BF6B0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800BF6B4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800BF6B8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800BF6BC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800BF6C0: jal         0x800BF500
    // 0x800BF6C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    guRotateF(rdram, ctx);
        goto after_0;
    // 0x800BF6C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800BF6C8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800BF6CC: jal         0x800C8AC0
    // 0x800BF6D0: lw          $a1, 0x60($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X60));
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800BF6D0: lw          $a1, 0x60($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X60));
    after_1:
    // 0x800BF6D4: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BF6D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800BF6DC: jr          $ra
    // 0x800BF6E0: nop

    return;
    // 0x800BF6E0: nop

;}
RECOMP_FUNC void resettimevars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC324: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x800AC328: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x800AC32C: lui         $a0, 0x802B
    ctx->r4 = S32(0X802B << 16);
    // 0x800AC330: addiu       $a0, $a0, -0x53D4
    ctx->r4 = ADD32(ctx->r4, -0X53D4);
    // 0x800AC334: addiu       $v1, $v1, -0x53D0
    ctx->r3 = ADD32(ctx->r3, -0X53D0);
    // 0x800AC338: addiu       $v0, $v0, -0x53CC
    ctx->r2 = ADD32(ctx->r2, -0X53CC);
    // 0x800AC33C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800AC340: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800AC344: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800AC348: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AC34C: sw          $zero, -0x53D8($at)
    MEM_W(-0X53D8, ctx->r1) = 0;
    // 0x800AC350: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AC354: sw          $zero, -0x5370($at)
    MEM_W(-0X5370, ctx->r1) = 0;
    // 0x800AC358: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AC35C: sw          $zero, -0x53C8($at)
    MEM_W(-0X53C8, ctx->r1) = 0;
    // 0x800AC360: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AC364: jr          $ra
    // 0x800AC368: sw          $zero, -0x55B0($at)
    MEM_W(-0X55B0, ctx->r1) = 0;
    return;
    // 0x800AC368: sw          $zero, -0x55B0($at)
    MEM_W(-0X55B0, ctx->r1) = 0;
;}
RECOMP_FUNC void divscale11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009132C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091330: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091334: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091338: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x8009133C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091340: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091344: jal         0x800BB834
    // 0x80091348: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091348: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009134C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091350: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091354: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091358: jal         0x800BB89C
    // 0x8009135C: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x8009135C: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091360: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009136C: jr          $ra
    // 0x80091370: nop

    return;
    // 0x80091370: nop

;}
RECOMP_FUNC void stopsound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059218: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8005921C: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80059220: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80059224: lui         $v0, 0x802A
    ctx->r2 = S32(0X802A << 16);
    // 0x80059228: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8005922C: lw          $v0, 0xB0C($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, 0XB0C));
    // 0x80059230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059238: blez        $v0, L_80059270
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005923C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80059270;
    }
    // 0x8005923C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059240: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80059244: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80059248: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8005924C: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x80059250: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80059254: lui         $a0, 0x802A
    ctx->r4 = S32(0X802A << 16);
    // 0x80059258: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8005925C: lw          $a0, 0x1DBC($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X1DBC));
    // 0x80059260: jal         0x8005850C
    // 0x80059264: sh          $t6, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r14;
    func_8005850C(rdram, ctx);
        goto after_0;
    // 0x80059264: sh          $t6, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r14;
    after_0:
    // 0x80059268: jal         0x800590B0
    // 0x8005926C: lh          $a0, 0x1A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X1A));
    testcallback(rdram, ctx);
        goto after_1;
    // 0x8005926C: lh          $a0, 0x1A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X1A));
    after_1:
L_80059270:
    // 0x80059270: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80059274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059278: jr          $ra
    // 0x8005927C: nop

    return;
    // 0x8005927C: nop

;}
RECOMP_FUNC void divscale12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009137C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091380: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091384: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80091388: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009138C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091390: jal         0x800BB834
    // 0x80091394: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091394: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009139C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800913A0: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800913A4: jal         0x800BB89C
    // 0x800913A8: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800913A8: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x800913AC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800913B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800913B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800913B8: jr          $ra
    // 0x800913BC: nop

    return;
    // 0x800913BC: nop

;}
RECOMP_FUNC void divscale10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800912DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800912E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800912E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800912E8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800912EC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800912F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800912F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800912F8: jal         0x800BB834
    // 0x800912FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800912FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091304: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091308: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8009130C: jal         0x800BB89C
    // 0x80091310: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091310: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091314: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009131C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091320: jr          $ra
    // 0x80091324: nop

    return;
    // 0x80091324: nop

;}
RECOMP_FUNC void _filterBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D068C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0690: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800D0694: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800D0698: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800D069C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800D06A0: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D06A4: lui         $t2, 0xB00
    ctx->r10 = S32(0XB00 << 16);
    // 0x800D06A8: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x800D06AC: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x800D06B0: ori         $t2, $t2, 0x20
    ctx->r10 = ctx->r10 | 0X20;
    // 0x800D06B4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D06B8: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D06BC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800D06C0: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x800D06C4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D06C8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D06CC: jal         0x800BF6F0
    // 0x800D06D0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800D06D0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800D06D4: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800D06D8: lw          $t0, 0x28($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800D06DC: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x800D06E0: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x800D06E4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800D06E8: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x800D06EC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D06F0: lw          $t4, 0x2C($t0)
    ctx->r12 = S32(MEM_W(ctx->r8, 0X2C));
    // 0x800D06F4: lh          $t7, 0x2($t0)
    ctx->r15 = S32(MEM_H(ctx->r8, 0X2));
    // 0x800D06F8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800D06FC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800D0700: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800D0704: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D0708: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x800D070C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800D0710: lw          $a0, 0x28($t0)
    ctx->r4 = S32(MEM_W(ctx->r8, 0X28));
    // 0x800D0714: jal         0x800BF6F0
    // 0x800D0718: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800D0718: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x800D071C: lw          $a1, 0x18($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800D0720: lw          $t0, 0x28($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800D0724: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800D0728: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x800D072C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800D0730: lw          $v0, 0x24($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800D0734: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D0738: jr          $ra
    // 0x800D073C: nop

    return;
    // 0x800D073C: nop

;}
