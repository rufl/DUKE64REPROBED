#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058E1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80058E20: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80058E24: lh          $t6, 0x32($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X32));
    // 0x80058E28: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80058E2C: addiu       $a1, $a1, -0xB68
    ctx->r5 = ADD32(ctx->r5, -0XB68);
    // 0x80058E30: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80058E34: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80058E38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80058E3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80058E40: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80058E44: beq         $t9, $zero, L_80058E94
    if (ctx->r25 == 0) {
        // 0x80058E48: lui         $a2, 0x802A
        ctx->r6 = S32(0X802A << 16);
            goto L_80058E94;
    }
    // 0x80058E48: lui         $a2, 0x802A
    ctx->r6 = S32(0X802A << 16);
    // 0x80058E4C: addiu       $a2, $a2, 0xB00
    ctx->r6 = ADD32(ctx->r6, 0XB00);
    // 0x80058E50: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80058E54:
    // 0x80058E54: lw          $v1, 0xC($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0XC));
    // 0x80058E58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058E5C: blezl       $v1, L_80058E8C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80058E60: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80058E8C;
    }
    goto skip_0;
    // 0x80058E60: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
L_80058E64:
    // 0x80058E64: blez        $v1, L_80058E7C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80058E68: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80058E7C;
    }
    // 0x80058E68: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80058E6C: addu        $t1, $a1, $a0
    ctx->r9 = ADD32(ctx->r5, ctx->r4);
    // 0x80058E70: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80058E74: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x80058E78: bne         $t3, $zero, L_80058FDC
    if (ctx->r11 != 0) {
        // 0x80058E7C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80058FDC;
    }
L_80058E7C:
    // 0x80058E7C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058E80: bne         $at, $zero, L_80058E64
    if (ctx->r1 != 0) {
        // 0x80058E84: nop
    
            goto L_80058E64;
    }
    // 0x80058E84: nop

    // 0x80058E88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80058E8C:
    // 0x80058E8C: bne         $a0, $a3, L_80058E54
    if (ctx->r4 != ctx->r7) {
        // 0x80058E90: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80058E54;
    }
    // 0x80058E90: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80058E94:
    // 0x80058E94: lh          $v0, 0x32($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X32));
    // 0x80058E98: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80058E9C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80058EA0: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x80058EA4: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x80058EA8: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x80058EAC: lh          $a1, -0xDC0($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0XDC0));
    // 0x80058EB0: lh          $v1, -0x1018($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, -0X1018));
    // 0x80058EB4: sh          $a1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r5;
    // 0x80058EB8: subu        $a0, $v1, $a1
    ctx->r4 = SUB32(ctx->r3, ctx->r5);
    // 0x80058EBC: jal         0x80091A38
    // 0x80058EC0: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    klabs(rdram, ctx);
        goto after_0;
    // 0x80058EC0: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80058EC4: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80058EC8: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80058ECC: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80058ED0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80058ED4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80058ED8: lh          $v1, 0x2C($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X2C));
    // 0x80058EDC: beq         $t7, $zero, L_80058FA0
    if (ctx->r15 == 0) {
        // 0x80058EE0: lh          $a1, 0x2A($sp)
        ctx->r5 = S32(MEM_H(ctx->r29, 0X2A));
            goto L_80058FA0;
    }
    // 0x80058EE0: lh          $a1, 0x2A($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X2A));
    // 0x80058EE4: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058EE8: beql        $at, $zero, L_80058F4C
    if (ctx->r1 == 0) {
        // 0x80058EEC: sh          $v1, 0x2C($sp)
        MEM_H(0X2C, ctx->r29) = ctx->r3;
            goto L_80058F4C;
    }
    goto skip_1;
    // 0x80058EEC: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    skip_1:
    // 0x80058EF0: sh          $t5, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r13;
    // 0x80058EF4: jal         0x8009800C
    // 0x80058EF8: sh          $a1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r5;
    krand2(rdram, ctx);
        goto after_1;
    // 0x80058EF8: sh          $a1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r5;
    after_1:
    // 0x80058EFC: lh          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X28));
    // 0x80058F00: lh          $a1, 0x2A($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X2A));
    // 0x80058F04: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80058F08: mfhi        $t8
    ctx->r24 = hi;
    // 0x80058F0C: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x80058F10: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x80058F14: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80058F18: bne         $a0, $zero, L_80058F24
    if (ctx->r4 != 0) {
        // 0x80058F1C: nop
    
            goto L_80058F24;
    }
    // 0x80058F1C: nop

    // 0x80058F20: break       7
    do_break(2147847968);
L_80058F24:
    // 0x80058F24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058F28: bne         $a0, $at, L_80058F3C
    if (ctx->r4 != ctx->r1) {
        // 0x80058F2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80058F3C;
    }
    // 0x80058F2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80058F30: bne         $v0, $at, L_80058F3C
    if (ctx->r2 != ctx->r1) {
        // 0x80058F34: nop
    
            goto L_80058F3C;
    }
    // 0x80058F34: nop

    // 0x80058F38: break       6
    do_break(2147847992);
L_80058F3C:
    // 0x80058F3C: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80058F40: b           L_80058FAC
    // 0x80058F44: nop

        goto L_80058FAC;
    // 0x80058F44: nop

    // 0x80058F48: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
L_80058F4C:
    // 0x80058F4C: jal         0x8009800C
    // 0x80058F50: sh          $a0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r4;
    krand2(rdram, ctx);
        goto after_2;
    // 0x80058F50: sh          $a0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x80058F54: lh          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X28));
    // 0x80058F58: lh          $v1, 0x2C($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X2C));
    // 0x80058F5C: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80058F60: mfhi        $t2
    ctx->r10 = hi;
    // 0x80058F64: addu        $t0, $t2, $v1
    ctx->r8 = ADD32(ctx->r10, ctx->r3);
    // 0x80058F68: sll         $t3, $t0, 16
    ctx->r11 = S32(ctx->r8 << 16);
    // 0x80058F6C: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80058F70: bne         $a0, $zero, L_80058F7C
    if (ctx->r4 != 0) {
        // 0x80058F74: nop
    
            goto L_80058F7C;
    }
    // 0x80058F74: nop

    // 0x80058F78: break       7
    do_break(2147848056);
L_80058F7C:
    // 0x80058F7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058F80: bne         $a0, $at, L_80058F94
    if (ctx->r4 != ctx->r1) {
        // 0x80058F84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80058F94;
    }
    // 0x80058F84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80058F88: bne         $v0, $at, L_80058F94
    if (ctx->r2 != ctx->r1) {
        // 0x80058F8C: nop
    
            goto L_80058F94;
    }
    // 0x80058F8C: nop

    // 0x80058F90: break       6
    do_break(2147848080);
L_80058F94:
    // 0x80058F94: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x80058F98: b           L_80058FAC
    // 0x80058F9C: nop

        goto L_80058FAC;
    // 0x80058F9C: nop

L_80058FA0:
    // 0x80058FA0: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80058FA4: sra         $t5, $t0, 16
    ctx->r13 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80058FA8: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
L_80058FAC:
    // 0x80058FAC: jal         0x80058A30
    // 0x80058FB0: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
    func_80058A30(rdram, ctx);
        goto after_3;
    // 0x80058FB0: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
    after_3:
    // 0x80058FB4: lh          $t0, 0x2E($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X2E));
    // 0x80058FB8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80058FBC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80058FC0: lh          $a0, 0x32($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X32));
    // 0x80058FC4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80058FC8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80058FCC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x80058FD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80058FD4: jal         0x80058428
    // 0x80058FD8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_80058428(rdram, ctx);
        goto after_4;
    // 0x80058FD8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_4:
L_80058FDC:
    // 0x80058FDC: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80058FE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80058FE4: jr          $ra
    // 0x80058FE8: nop

    return;
    // 0x80058FE8: nop

;}
RECOMP_FUNC void alSaveParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE500: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CE504: beq         $a1, $at, L_800CE520
    if (ctx->r5 == ctx->r1) {
        // 0x800CE508: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CE520;
    }
    // 0x800CE508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CE50C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800CE510: beql        $a1, $at, L_800CE52C
    if (ctx->r5 == ctx->r1) {
        // 0x800CE514: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800CE52C;
    }
    goto skip_0;
    // 0x800CE514: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800CE518: jr          $ra
    // 0x800CE51C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE51C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE520:
    // 0x800CE520: jr          $ra
    // 0x800CE524: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x800CE524: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800CE528: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800CE52C:
    // 0x800CE52C: jr          $ra
    // 0x800CE530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void fakekrand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071FC0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80071FC4: lb          $t6, 0x36C8($t6)
    ctx->r14 = S32(MEM_B(ctx->r14, 0X36C8));
    // 0x80071FC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071FCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80071FD0: bne         $t6, $at, L_80071FE8
    if (ctx->r14 != ctx->r1) {
        // 0x80071FD4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80071FE8;
    }
    // 0x80071FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071FD8: jal         0x80098054
    // 0x80071FDC: nop

    krand(rdram, ctx);
        goto after_0;
    // 0x80071FDC: nop

    after_0:
    // 0x80071FE0: b           L_80071FF0
    // 0x80071FE4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80071FF0;
    // 0x80071FE4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80071FE8:
    // 0x80071FE8: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80071FEC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80071FF0:
    // 0x80071FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071FF4: jr          $ra
    // 0x80071FF8: nop

    return;
    // 0x80071FF8: nop

;}
RECOMP_FUNC void guNormalize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C99F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C99F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C99F8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = S32(MEM_W(ctx->r4, 0X0));
    // 0x800C99FC: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = S32(MEM_W(ctx->r5, 0X0));
    // 0x800C9A00: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C9A04: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9A08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9A0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9A10: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9A18: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9A1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C9A20: jal         0x800C3DC0
    // 0x800C9A24: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9A24: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x800C9A28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9A2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C9A30: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800C9A34: lw          $a1, 0x1C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C9A38: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C9A3C: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = S32(MEM_W(ctx->r4, 0X0));
    // 0x800C9A40: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C9A44: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800C9A48: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800C9A4C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = S32(MEM_W(ctx->r5, 0X0));
    // 0x800C9A50: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800C9A54: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800C9A58: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C9A5C: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800C9A60: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x800C9A64: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C9A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9A6C: jr          $ra
    // 0x800C9A70: nop

    return;
    // 0x800C9A70: nop

;}
RECOMP_FUNC void func_80066718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066718: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x8006671C: lbu         $t6, -0x2904($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2904);
    // 0x80066720: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x80066724: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x80066728: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8006672C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80066730: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80066734: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80066738: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006673C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80066740: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80066744: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80066748: lw          $t9, 0x274($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X274));
    // 0x8006674C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066750: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066754: bne         $t9, $zero, L_80066768
    if (ctx->r25 != 0) {
        // 0x80066758: nop
    
            goto L_80066768;
    }
    // 0x80066758: nop

    // 0x8006675C: lw          $t5, 0x210($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X210));
    // 0x80066760: beql        $t5, $zero, L_80066930
    if (ctx->r13 == 0) {
        // 0x80066764: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_80066930;
    }
    goto skip_0;
    // 0x80066764: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_0:
L_80066768:
    // 0x80066768: jal         0x8005C28C
    // 0x8006676C: nop

    clearscreen(rdram, ctx);
        goto after_0;
    // 0x8006676C: nop

    after_0:
    // 0x80066770: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80066774: addiu       $t1, $t1, 0x4418
    ctx->r9 = ADD32(ctx->r9, 0X4418);
    // 0x80066778: lw          $v0, 0x0($t1)
    ctx->r2 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8006677C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80066780: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80066784: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066788: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8006678C: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x80066790: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80066794: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80066798: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8006679C: lw          $v0, 0x0($t1)
    ctx->r2 = S32(MEM_W(ctx->r9, 0X0));
    // 0x800667A0: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x800667A4: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x800667A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800667AC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800667B0: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x800667B4: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x800667B8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800667BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800667C0: lw          $v0, 0x0($t1)
    ctx->r2 = S32(MEM_W(ctx->r9, 0X0));
    // 0x800667C4: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x800667C8: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800667CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800667D0: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800667D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800667D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800667DC: lw          $v0, 0x0($t1)
    ctx->r2 = S32(MEM_W(ctx->r9, 0X0));
    // 0x800667E0: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800667E4: ori         $t5, $t5, 0xE02
    ctx->r13 = ctx->r13 | 0XE02;
    // 0x800667E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800667EC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800667F0: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800667F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800667F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800667FC: lbu         $t6, -0x2904($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2904);
    // 0x80066800: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x80066804: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80066808: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8006680C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80066810: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80066814: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80066818: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006681C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80066820: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80066824: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x80066828: sb          $zero, -0x13CF($at)
    MEM_B(-0X13CF, ctx->r1) = 0;
    // 0x8006682C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80066830: lbu         $t3, 0x367($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X367);
    // 0x80066834: lbu         $t2, 0x368($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X368);
    // 0x80066838: lbu         $t4, 0x369($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X369);
    // 0x8006683C: lw          $t0, 0x210($v1)
    ctx->r8 = S32(MEM_W(ctx->r3, 0X210));
    // 0x80066840: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80066844: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80066848: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8006684C: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x80066850: or          $t2, $t5, $zero
    ctx->r10 = ctx->r13 | 0;
    // 0x80066854: blez        $t0, L_80066868
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80066858: or          $t4, $t6, $zero
        ctx->r12 = ctx->r14 | 0;
            goto L_80066868;
    }
    // 0x80066858: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x8006685C: addu        $t2, $t5, $t0
    ctx->r10 = ADD32(ctx->r13, ctx->r8);
    // 0x80066860: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80066864: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80066868:
    // 0x80066868: lw          $a0, 0x274($v1)
    ctx->r4 = S32(MEM_W(ctx->r3, 0X274));
    // 0x8006686C: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x80066870: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80066874: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80066878: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006687C: beq         $at, $zero, L_8006688C
    if (ctx->r1 == 0) {
        // 0x80066880: addiu       $a0, $zero, 0xF8A
        ctx->r4 = ADD32(0, 0XF8A);
            goto L_8006688C;
    }
    // 0x80066880: addiu       $a0, $zero, 0xF8A
    ctx->r4 = ADD32(0, 0XF8A);
    // 0x80066884: b           L_80066890
    // 0x80066888: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80066890;
    // 0x80066888: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8006688C:
    // 0x8006688C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80066890:
    // 0x80066890: slti        $at, $t3, 0x100
    ctx->r1 = SIGNED(ctx->r11) < 0X100 ? 1 : 0;
    // 0x80066894: bnel        $at, $zero, L_800668A4
    if (ctx->r1 != 0) {
        // 0x80066898: slti        $at, $t2, 0x100
        ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
            goto L_800668A4;
    }
    goto skip_1;
    // 0x80066898: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    skip_1:
    // 0x8006689C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800668A0: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
L_800668A4:
    // 0x800668A4: bne         $at, $zero, L_800668B0
    if (ctx->r1 != 0) {
        // 0x800668A8: sll         $t6, $t3, 24
        ctx->r14 = S32(ctx->r11 << 24);
            goto L_800668B0;
    }
    // 0x800668A8: sll         $t6, $t3, 24
    ctx->r14 = S32(ctx->r11 << 24);
    // 0x800668AC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_800668B0:
    // 0x800668B0: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x800668B4: bnel        $at, $zero, L_800668C4
    if (ctx->r1 != 0) {
        // 0x800668B8: slti        $at, $a1, 0x100
        ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
            goto L_800668C4;
    }
    goto skip_2;
    // 0x800668B8: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    skip_2:
    // 0x800668BC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800668C0: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
L_800668C4:
    // 0x800668C4: bnel        $at, $zero, L_800668D4
    if (ctx->r1 != 0) {
        // 0x800668C8: lw          $v0, 0x0($t1)
        ctx->r2 = S32(MEM_W(ctx->r9, 0X0));
            goto L_800668D4;
    }
    goto skip_3;
    // 0x800668C8: lw          $v0, 0x0($t1)
    ctx->r2 = S32(MEM_W(ctx->r9, 0X0));
    skip_3:
    // 0x800668CC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800668D0: lw          $v0, 0x0($t1)
    ctx->r2 = S32(MEM_W(ctx->r9, 0X0));
L_800668D4:
    // 0x800668D4: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x800668D8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800668DC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800668E0: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800668E4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800668E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800668EC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800668F0: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800668F4: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800668F8: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x800668FC: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x80066900: jal         0x8006370C
    // 0x80066904: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    gettileid(rdram, ctx);
        goto after_1;
    // 0x80066904: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    after_1:
    // 0x80066908: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8006690C: lwc1        $f12, -0x3C88($at)
    ctx->f12.u32l = S32(MEM_W(ctx->r1, -0X3C88));
    // 0x80066910: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x80066914: lwc1        $f14, -0x3C84($at)
    ctx->f14.u32l = S32(MEM_W(ctx->r1, -0X3C84));
    // 0x80066918: lui         $a2, 0x4250
    ctx->r6 = S32(0X4250 << 16);
    // 0x8006691C: lui         $a3, 0x42B0
    ctx->r7 = S32(0X42B0 << 16);
    // 0x80066920: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80066924: jal         0x8006CF8C
    // 0x80066928: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rendertileworld(rdram, ctx);
        goto after_2;
    // 0x80066928: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8006692C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_80066930:
    // 0x80066930: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80066934: jr          $ra
    // 0x80066938: nop

    return;
    // 0x80066938: nop

;}
RECOMP_FUNC void mulscale21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FEB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FEBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FEC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FEC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FEC8: jal         0x800BB8F8
    // 0x8008FECC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FECC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FED0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FED4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FED8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FEDC: jal         0x800BBA24
    // 0x8008FEE0: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FEE0: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    after_1:
    // 0x8008FEE4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FEE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FEEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FEF0: jr          $ra
    // 0x8008FEF4: nop

    return;
    // 0x8008FEF4: nop

;}
RECOMP_FUNC void alSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D002C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D0030: jal         0x800CFFD8
    // 0x800D0034: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    static_5_800CFFD8(rdram, ctx);
        goto after_0;
    // 0x800D0034: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_0:
    // 0x800D0038: lw          $t6, 0xC($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0XC));
    // 0x800D003C: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800D0040: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800D0044: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800D0048: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x800D004C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D0050: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800D0054: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D0058: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D005C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D0060: bne         $a0, $at, L_800D0120
    if (ctx->r4 != ctx->r1) {
        // 0x800D0064: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_800D0120;
    }
    // 0x800D0064: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800D0068: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800D006C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D0070: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800D0074: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x800D0078: bne         $v0, $at, L_800D00E8
    if (ctx->r2 != ctx->r1) {
        // 0x800D007C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800D00E8;
    }
    // 0x800D007C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800D0080: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D0084: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x800D0088: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D008C: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D0090: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x800D0094: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800D0098: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D009C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800D00A0: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800D00A4: sb          $v0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r2;
    // 0x800D00A8: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800D00AC: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D00B0: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D00B4: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D00B8: sb          $a0, 0xB($a3)
    MEM_B(0XB, ctx->r7) = ctx->r4;
    // 0x800D00BC: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800D00C0: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800D00C4: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800D00C8: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x800D00CC: sb          $a1, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r5;
    // 0x800D00D0: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800D00D4: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D00D8: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800D00DC: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x800D00E0: b           L_800D0118
    // 0x800D00E4: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
        goto L_800D0118;
    // 0x800D00E4: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
L_800D00E8:
    // 0x800D00E8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800D00EC: bne         $v0, $at, L_800D0118
    if (ctx->r2 != ctx->r1) {
        // 0x800D00F0: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_800D0118;
    }
    // 0x800D00F0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800D00F4: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x800D00F8: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D00FC: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D0100: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x800D0104: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800D0108: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D010C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D0110: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800D0114: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_800D0118:
    // 0x800D0118: b           L_800D0198
    // 0x800D011C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
        goto L_800D0198;
    // 0x800D011C: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
L_800D0120:
    // 0x800D0120: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D0124: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800D0128: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x800D012C: beq         $t6, $zero, L_800D0154
    if (ctx->r14 == 0) {
        // 0x800D0130: sw          $t1, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->r9;
            goto L_800D0154;
    }
    // 0x800D0130: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D0134: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x800D0138: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800D013C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D0140: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800D0144: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800D0148: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800D014C: b           L_800D0160
    // 0x800D0150: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
        goto L_800D0160;
    // 0x800D0150: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
L_800D0154:
    // 0x800D0154: lh          $t8, 0x1A($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0X1A));
    // 0x800D0158: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x800D015C: sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
L_800D0160:
    // 0x800D0160: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    // 0x800D0164: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800D0168: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800D016C: beq         $t9, $at, L_800D0194
    if (ctx->r25 == ctx->r1) {
        // 0x800D0170: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_800D0194;
    }
    // 0x800D0170: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800D0174: beql        $t9, $at, L_800D0198
    if (ctx->r25 == ctx->r1) {
        // 0x800D0178: sb          $zero, 0xA($a3)
        MEM_B(0XA, ctx->r7) = 0;
            goto L_800D0198;
    }
    goto skip_0;
    // 0x800D0178: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
    skip_0:
    // 0x800D017C: lw          $v1, 0x8($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800D0180: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x800D0184: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800D0188: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x800D018C: b           L_800D0198
    // 0x800D0190: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
        goto L_800D0198;
    // 0x800D0190: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_800D0194:
    // 0x800D0194: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
L_800D0198:
    // 0x800D0198: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800D019C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D01A0: jr          $ra
    // 0x800D01A4: nop

    return;
    // 0x800D01A4: nop

;}
RECOMP_FUNC void alCSPStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C18B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C18B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C18B8: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800C18BC: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C18C0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C18C4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C18C8: jal         0x800C9C6C
    // 0x800C18CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C18CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C18D0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C18D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C18D8: jr          $ra
    // 0x800C18DC: nop

    return;
    // 0x800C18DC: nop

;}
RECOMP_FUNC void mulscale20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FE70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FE74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FE78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FE7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FE80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FE84: jal         0x800BB8F8
    // 0x8008FE88: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FE88: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FE8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FE90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FE94: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FE98: jal         0x800BBA24
    // 0x8008FE9C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FE9C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_1:
    // 0x8008FEA0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FEA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FEA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FEAC: jr          $ra
    // 0x8008FEB0: nop

    return;
    // 0x8008FEB0: nop

;}
RECOMP_FUNC void movefallers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007820C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80078210: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80078214: lh          $v0, 0x2870($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X2870));
    // 0x80078218: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8007821C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80078220: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80078224: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80078228: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8007822C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80078230: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80078234: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80078238: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8007823C: bltz        $v0, L_80078630
    if (SIGNED(ctx->r2) < 0) {
        // 0x80078240: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_80078630;
    }
    // 0x80078240: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80078244: sh          $v0, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r2;
    // 0x80078248: lh          $a2, 0x6E($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X6E));
    // 0x8007824C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80078250:
    // 0x80078250: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80078254: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80078258: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007825C: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80078260: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80078264: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x80078268: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007826C: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x80078270: addu        $fp, $t8, $t9
    ctx->r30 = ADD32(ctx->r24, ctx->r25);
    // 0x80078274: addu        $t4, $t4, $a2
    ctx->r12 = ADD32(ctx->r12, ctx->r6);
    // 0x80078278: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x8007827C: lh          $a0, 0x10($fp)
    ctx->r4 = S32(MEM_H(ctx->r30, 0X10));
    // 0x80078280: addiu       $t5, $t5, -0x5C00
    ctx->r13 = ADD32(ctx->r13, -0X5C00);
    // 0x80078284: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80078288: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x8007828C: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x80078290: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x80078294: lw          $v0, 0x30($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X30));
    // 0x80078298: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007829C: lh          $t7, 0x5F40($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X5F40));
    // 0x800782A0: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x800782A4: sra         $t3, $s0, 16
    ctx->r11 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800782A8: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x800782AC: bne         $v0, $zero, L_800783E0
    if (ctx->r2 != 0) {
        // 0x800782B0: sh          $t7, 0x6C($sp)
        MEM_H(0X6C, ctx->r29) = ctx->r15;
            goto L_800783E0;
    }
    // 0x800782B0: sh          $t7, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r15;
    // 0x800782B4: lw          $t6, 0x8($fp)
    ctx->r14 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800782B8: lh          $t8, 0x14($fp)
    ctx->r24 = S32(MEM_H(ctx->r30, 0X14));
    // 0x800782BC: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x800782C0: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800782C4: addiu       $t7, $t6, -0x1000
    ctx->r15 = ADD32(ctx->r14, -0X1000);
    // 0x800782C8: sw          $t7, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r15;
    // 0x800782CC: lh          $s7, 0x22($fp)
    ctx->r23 = S32(MEM_H(ctx->r30, 0X22));
    // 0x800782D0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800782D4: jal         0x80077388
    // 0x800782D8: sw          $t8, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r24;
    ifhitbyweapon(rdram, ctx);
        goto after_0;
    // 0x800782D8: sw          $t8, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r24;
    after_0:
    // 0x800782DC: bltz        $v0, L_800783C8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800782E0: addiu       $at, $zero, 0x394
        ctx->r1 = ADD32(0, 0X394);
            goto L_800783C8;
    }
    // 0x800782E0: addiu       $at, $zero, 0x394
    ctx->r1 = ADD32(0, 0X394);
    // 0x800782E4: beq         $v0, $at, L_8007830C
    if (ctx->r2 == ctx->r1) {
        // 0x800782E8: addiu       $at, $zero, 0xA2D
        ctx->r1 = ADD32(0, 0XA2D);
            goto L_8007830C;
    }
    // 0x800782E8: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x800782EC: beq         $v0, $at, L_8007830C
    if (ctx->r2 == ctx->r1) {
        // 0x800782F0: addiu       $at, $zero, 0x686
        ctx->r1 = ADD32(0, 0X686);
            goto L_8007830C;
    }
    // 0x800782F0: addiu       $at, $zero, 0x686
    ctx->r1 = ADD32(0, 0X686);
    // 0x800782F4: beq         $v0, $at, L_8007830C
    if (ctx->r2 == ctx->r1) {
        // 0x800782F8: addiu       $at, $zero, 0x4DF
        ctx->r1 = ADD32(0, 0X4DF);
            goto L_8007830C;
    }
    // 0x800782F8: addiu       $at, $zero, 0x4DF
    ctx->r1 = ADD32(0, 0X4DF);
    // 0x800782FC: beq         $v0, $at, L_8007830C
    if (ctx->r2 == ctx->r1) {
        // 0x80078300: addiu       $at, $zero, 0x437
        ctx->r1 = ADD32(0, 0X437);
            goto L_8007830C;
    }
    // 0x80078300: addiu       $at, $zero, 0x437
    ctx->r1 = ADD32(0, 0X437);
    // 0x80078304: bnel        $v0, $at, L_800783C4
    if (ctx->r2 != ctx->r1) {
        // 0x80078308: sh          $zero, 0x6($s1)
        MEM_H(0X6, ctx->r17) = 0;
            goto L_800783C4;
    }
    goto skip_0;
    // 0x80078308: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    skip_0:
L_8007830C:
    // 0x8007830C: lh          $t3, 0x22($fp)
    ctx->r11 = S32(MEM_H(ctx->r30, 0X22));
    // 0x80078310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80078314: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x80078318: bgtz        $t3, L_800783B8
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007831C: nop
    
            goto L_800783B8;
    }
    // 0x8007831C: nop

    // 0x80078320: sw          $a1, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r5;
    // 0x80078324: lh          $s0, 0x2870($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X2870));
    // 0x80078328: addiu       $t2, $zero, 0x48
    ctx->r10 = ADD32(0, 0X48);
    // 0x8007832C: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x80078330: bltz        $s0, L_800783B8
    if (SIGNED(ctx->r16) < 0) {
        // 0x80078334: lui         $t0, 0x8024
        ctx->r8 = S32(0X8024 << 16);
            goto L_800783B8;
    }
    // 0x80078334: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x80078338: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x8007833C: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x80078340: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x80078344: addiu       $a3, $zero, 0x4E7
    ctx->r7 = ADD32(0, 0X4E7);
    // 0x80078348: addiu       $a0, $zero, 0x4E2
    ctx->r4 = ADD32(0, 0X4E2);
L_8007834C:
    // 0x8007834C: multu       $s0, $t1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078350: lh          $t6, 0x20($fp)
    ctx->r14 = S32(MEM_H(ctx->r30, 0X20));
    // 0x80078354: mflo        $t4
    ctx->r12 = lo;
    // 0x80078358: addu        $v0, $t0, $t4
    ctx->r2 = ADD32(ctx->r8, ctx->r12);
    // 0x8007835C: lh          $t5, 0x20($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X20));
    // 0x80078360: bnel        $t5, $t6, L_800783A8
    if (ctx->r13 != ctx->r14) {
        // 0x80078364: sll         $t5, $s0, 1
        ctx->r13 = S32(ctx->r16 << 1);
            goto L_800783A8;
    }
    goto skip_1;
    // 0x80078364: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    skip_1:
    // 0x80078368: multu       $s0, $t2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007836C: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80078370: mflo        $t7
    ctx->r15 = lo;
    // 0x80078374: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80078378: sw          $a1, -0x5BD0($at)
    MEM_W(-0X5BD0, ctx->r1) = ctx->r5;
    // 0x8007837C: lh          $t8, 0xC($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0XC));
    // 0x80078380: lh          $v1, 0xE($v0)
    ctx->r3 = S32(MEM_H(ctx->r2, 0XE));
    // 0x80078384: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80078388: beq         $a3, $v1, L_80078398
    if (ctx->r7 == ctx->r3) {
        // 0x8007838C: sh          $t9, 0xC($v0)
        MEM_H(0XC, ctx->r2) = ctx->r25;
            goto L_80078398;
    }
    // 0x8007838C: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x80078390: bnel        $a0, $v1, L_800783A8
    if (ctx->r4 != ctx->r3) {
        // 0x80078394: sll         $t5, $s0, 1
        ctx->r13 = S32(ctx->r16 << 1);
            goto L_800783A8;
    }
    goto skip_2;
    // 0x80078394: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    skip_2:
L_80078398:
    // 0x80078398: lh          $t3, 0xC($v0)
    ctx->r11 = S32(MEM_H(ctx->r2, 0XC));
    // 0x8007839C: ori         $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 | 0X8000;
    // 0x800783A0: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
    // 0x800783A4: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
L_800783A8:
    // 0x800783A8: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x800783AC: lh          $s0, 0x0($t6)
    ctx->r16 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800783B0: bgez        $s0, L_8007834C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800783B4: nop
    
            goto L_8007834C;
    }
    // 0x800783B4: nop

L_800783B8:
    // 0x800783B8: b           L_800783CC
    // 0x800783BC: lw          $t8, 0x8($fp)
    ctx->r24 = S32(MEM_W(ctx->r30, 0X8));
        goto L_800783CC;
    // 0x800783BC: lw          $t8, 0x8($fp)
    ctx->r24 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800783C0: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
L_800783C4:
    // 0x800783C4: sh          $s7, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r23;
L_800783C8:
    // 0x800783C8: lw          $t8, 0x8($fp)
    ctx->r24 = S32(MEM_W(ctx->r30, 0X8));
L_800783CC:
    // 0x800783CC: lw          $t7, 0x34($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X34));
    // 0x800783D0: addiu       $t9, $t8, 0x1000
    ctx->r25 = ADD32(ctx->r24, 0X1000);
    // 0x800783D4: sw          $t9, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r25;
    // 0x800783D8: b           L_8007861C
    // 0x800783DC: sh          $t7, 0x14($fp)
    MEM_H(0X14, ctx->r30) = ctx->r15;
        goto L_8007861C;
    // 0x800783DC: sh          $t7, 0x14($fp)
    MEM_H(0X14, ctx->r30) = ctx->r15;
L_800783E0:
    // 0x800783E0: bnel        $a1, $v0, L_80078620
    if (ctx->r5 != ctx->r2) {
        // 0x800783E4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80078620;
    }
    goto skip_3;
    // 0x800783E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_3:
    // 0x800783E8: lh          $v0, 0x1E($fp)
    ctx->r2 = S32(MEM_H(ctx->r30, 0X1E));
    // 0x800783EC: blez        $v0, L_80078430
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800783F0: addiu       $t3, $v0, -0x3
        ctx->r11 = ADD32(ctx->r2, -0X3);
            goto L_80078430;
    }
    // 0x800783F0: addiu       $t3, $v0, -0x3
    ctx->r11 = ADD32(ctx->r2, -0X3);
    // 0x800783F4: sh          $t3, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r11;
    // 0x800783F8: lh          $t4, 0x1E($fp)
    ctx->r12 = S32(MEM_H(ctx->r30, 0X1E));
    // 0x800783FC: bgtzl       $t4, L_80078620
    if (SIGNED(ctx->r12) > 0) {
        // 0x80078400: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80078620;
    }
    goto skip_4;
    // 0x80078400: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_4:
    // 0x80078404: jal         0x8009800C
    // 0x80078408: nop

    krand2(rdram, ctx);
        goto after_1;
    // 0x80078408: nop

    after_1:
    // 0x8007840C: addiu       $t5, $v0, 0x20
    ctx->r13 = ADD32(ctx->r2, 0X20);
    // 0x80078410: andi        $t6, $t5, 0x3F
    ctx->r14 = ctx->r13 & 0X3F;
    // 0x80078414: jal         0x8009800C
    // 0x80078418: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    krand2(rdram, ctx);
        goto after_2;
    // 0x80078418: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    after_2:
    // 0x8007841C: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x80078420: addiu       $t8, $zero, -0x400
    ctx->r24 = ADD32(0, -0X400);
    // 0x80078424: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x80078428: b           L_8007861C
    // 0x8007842C: sh          $t9, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r25;
        goto L_8007861C;
    // 0x8007842C: sh          $t9, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r25;
L_80078430:
    // 0x80078430: lh          $v0, 0x18($fp)
    ctx->r2 = S32(MEM_H(ctx->r30, 0X18));
    // 0x80078434: sh          $a2, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r6;
    // 0x80078438: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8007843C: blez        $v0, L_80078464
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80078440: addiu       $t3, $v0, -0x8
        ctx->r11 = ADD32(ctx->r2, -0X8);
            goto L_80078464;
    }
    // 0x80078440: addiu       $t3, $v0, -0x8
    ctx->r11 = ADD32(ctx->r2, -0X8);
    // 0x80078444: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    // 0x80078448: sh          $t3, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r11;
    // 0x8007844C: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80078450: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80078454: sh          $a2, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r6;
    // 0x80078458: jal         0x80076190
    // 0x8007845C: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    ssp(rdram, ctx);
        goto after_3;
    // 0x8007845C: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    after_3:
    // 0x80078460: lh          $a0, 0x10($fp)
    ctx->r4 = S32(MEM_H(ctx->r30, 0X10));
L_80078464:
    // 0x80078464: jal         0x80075688
    // 0x80078468: nop

    floorspace(rdram, ctx);
        goto after_4;
    // 0x80078468: nop

    after_4:
    // 0x8007846C: beq         $v0, $zero, L_8007847C
    if (ctx->r2 == 0) {
        // 0x80078470: nop
    
            goto L_8007847C;
    }
    // 0x80078470: nop

    // 0x80078474: b           L_80078494
    // 0x80078478: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
        goto L_80078494;
    // 0x80078478: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8007847C:
    // 0x8007847C: jal         0x8007561C
    // 0x80078480: lh          $a0, 0x10($fp)
    ctx->r4 = S32(MEM_H(ctx->r30, 0X10));
    ceilingspace(rdram, ctx);
        goto after_5;
    // 0x80078480: lh          $a0, 0x10($fp)
    ctx->r4 = S32(MEM_H(ctx->r30, 0X10));
    after_5:
    // 0x80078484: beq         $v0, $zero, L_80078494
    if (ctx->r2 == 0) {
        // 0x80078488: addiu       $s7, $zero, 0xB0
        ctx->r23 = ADD32(0, 0XB0);
            goto L_80078494;
    }
    // 0x80078488: addiu       $s7, $zero, 0xB0
    ctx->r23 = ADD32(0, 0XB0);
    // 0x8007848C: b           L_80078494
    // 0x80078490: addiu       $s7, $zero, 0x1D
    ctx->r23 = ADD32(0, 0X1D);
        goto L_80078494;
    // 0x80078490: addiu       $s7, $zero, 0x1D
    ctx->r23 = ADD32(0, 0X1D);
L_80078494:
    // 0x80078494: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80078498: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x8007849C: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800784A0: addiu       $t6, $t6, -0x1988
    ctx->r14 = ADD32(ctx->r14, -0X1988);
    // 0x800784A4: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800784A8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x800784AC: lw          $v0, 0x4($a1)
    ctx->r2 = S32(MEM_W(ctx->r5, 0X4));
    // 0x800784B0: lw          $v1, 0x8($fp)
    ctx->r3 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800784B4: addiu       $t8, $v0, -0x100
    ctx->r24 = ADD32(ctx->r2, -0X100);
    // 0x800784B8: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800784BC: beql        $at, $zero, L_80078500
    if (ctx->r1 == 0) {
        // 0x800784C0: subu        $t6, $v0, $v1
        ctx->r14 = SUB32(ctx->r2, ctx->r3);
            goto L_80078500;
    }
    goto skip_5;
    // 0x800784C0: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    skip_5:
    // 0x800784C4: lh          $t7, 0x1C($fp)
    ctx->r15 = S32(MEM_H(ctx->r30, 0X1C));
    // 0x800784C8: addiu       $t3, $zero, 0x1800
    ctx->r11 = ADD32(0, 0X1800);
    // 0x800784CC: addu        $t9, $t7, $s7
    ctx->r25 = ADD32(ctx->r15, ctx->r23);
    // 0x800784D0: sh          $t9, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r25;
    // 0x800784D4: lh          $a0, 0x1C($fp)
    ctx->r4 = S32(MEM_H(ctx->r30, 0X1C));
    // 0x800784D8: slti        $at, $a0, 0x1801
    ctx->r1 = SIGNED(ctx->r4) < 0X1801 ? 1 : 0;
    // 0x800784DC: bnel        $at, $zero, L_800784F0
    if (ctx->r1 != 0) {
        // 0x800784E0: lw          $t4, 0x8($fp)
        ctx->r12 = S32(MEM_W(ctx->r30, 0X8));
            goto L_800784F0;
    }
    goto skip_6;
    // 0x800784E0: lw          $t4, 0x8($fp)
    ctx->r12 = S32(MEM_W(ctx->r30, 0X8));
    skip_6:
    // 0x800784E4: sh          $t3, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r11;
    // 0x800784E8: lh          $a0, 0x1C($fp)
    ctx->r4 = S32(MEM_H(ctx->r30, 0X1C));
    // 0x800784EC: lw          $t4, 0x8($fp)
    ctx->r12 = S32(MEM_W(ctx->r30, 0X8));
L_800784F0:
    // 0x800784F0: lw          $v0, 0x4($a1)
    ctx->r2 = S32(MEM_W(ctx->r5, 0X4));
    // 0x800784F4: addu        $v1, $t4, $a0
    ctx->r3 = ADD32(ctx->r12, ctx->r4);
    // 0x800784F8: sw          $v1, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r3;
    // 0x800784FC: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
L_80078500:
    // 0x80078500: slti        $at, $t6, 0x1000
    ctx->r1 = SIGNED(ctx->r14) < 0X1000 ? 1 : 0;
    // 0x80078504: beql        $at, $zero, L_80078620
    if (ctx->r1 == 0) {
        // 0x80078508: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80078620;
    }
    goto skip_7;
    // 0x80078508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_7:
    // 0x8007850C: jal         0x8009800C
    // 0x80078510: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    krand2(rdram, ctx);
        goto after_6;
    // 0x80078510: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    after_6:
    // 0x80078514: andi        $v1, $v0, 0x7
    ctx->r3 = ctx->r2 & 0X7;
    // 0x80078518: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007851C: sll         $s0, $v1, 16
    ctx->r16 = S32(ctx->r3 << 16);
    // 0x80078520: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80078524: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80078528: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8007852C: blez        $t9, L_8007860C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80078530: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_8007860C;
    }
    // 0x80078530: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_80078534:
    // 0x80078534: jal         0x8009800C
    // 0x80078538: nop

    krand2(rdram, ctx);
        goto after_7;
    // 0x80078538: nop

    after_7:
    // 0x8007853C: jal         0x8009800C
    // 0x80078540: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_8;
    // 0x80078540: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    after_8:
    // 0x80078544: jal         0x8009800C
    // 0x80078548: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_9;
    // 0x80078548: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    after_9:
    // 0x8007854C: jal         0x8009800C
    // 0x80078550: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_10;
    // 0x80078550: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_10:
    // 0x80078554: jal         0x8009800C
    // 0x80078558: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_11;
    // 0x80078558: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_11:
    // 0x8007855C: jal         0x8009800C
    // 0x80078560: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_12;
    // 0x80078560: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_12:
    // 0x80078564: jal         0x8009800C
    // 0x80078568: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_13;
    // 0x80078568: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    after_13:
    // 0x8007856C: lw          $t4, 0x0($fp)
    ctx->r12 = S32(MEM_W(ctx->r30, 0X0));
    // 0x80078570: lw          $t6, 0x4($fp)
    ctx->r14 = S32(MEM_W(ctx->r30, 0X4));
    // 0x80078574: lw          $t8, 0x8($fp)
    ctx->r24 = S32(MEM_W(ctx->r30, 0X8));
    // 0x80078578: lh          $a0, 0x10($fp)
    ctx->r4 = S32(MEM_H(ctx->r30, 0X10));
    // 0x8007857C: andi        $t3, $s5, 0xFF
    ctx->r11 = ctx->r21 & 0XFF;
    // 0x80078580: andi        $t5, $s6, 0xFF
    ctx->r13 = ctx->r22 & 0XFF;
    // 0x80078584: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80078588: andi        $t7, $s1, 0x1FFF
    ctx->r15 = ctx->r17 & 0X1FFF;
    // 0x8007858C: andi        $t9, $s2, 0xF
    ctx->r25 = ctx->r18 & 0XF;
    // 0x80078590: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x80078594: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80078598: addiu       $t3, $t9, 0x956
    ctx->r11 = ADD32(ctx->r25, 0X956);
    // 0x8007859C: addiu       $t4, $zero, -0x8
    ctx->r12 = ADD32(0, -0X8);
    // 0x800785A0: subu        $a3, $t8, $t7
    ctx->r7 = SUB32(ctx->r24, ctx->r15);
    // 0x800785A4: andi        $t8, $s3, 0x7FF
    ctx->r24 = ctx->r19 & 0X7FF;
    // 0x800785A8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800785AC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800785B0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800785B4: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x800785B8: lh          $t6, 0x6E($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X6E));
    // 0x800785BC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800785C0: andi        $t3, $v0, 0x7FF
    ctx->r11 = ctx->r2 & 0X7FF;
    // 0x800785C4: addiu       $t4, $zero, -0x200
    ctx->r12 = ADD32(0, -0X200);
    // 0x800785C8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800785CC: andi        $t7, $s4, 0x3F
    ctx->r15 = ctx->r20 & 0X3F;
    // 0x800785D0: addiu       $t9, $t7, 0x40
    ctx->r25 = ADD32(ctx->r15, 0X40);
    // 0x800785D4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800785D8: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800785DC: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800785E0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800785E4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800785E8: addiu       $a3, $a3, -0x800
    ctx->r7 = ADD32(ctx->r7, -0X800);
    // 0x800785EC: addiu       $a2, $a2, -0x80
    ctx->r6 = ADD32(ctx->r6, -0X80);
    // 0x800785F0: addiu       $a1, $a1, -0x80
    ctx->r5 = ADD32(ctx->r5, -0X80);
    // 0x800785F4: jal         0x8009B028
    // 0x800785F8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    EGS(rdram, ctx);
        goto after_14;
    // 0x800785F8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_14:
    // 0x800785FC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80078600: slt         $at, $s7, $s0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80078604: bne         $at, $zero, L_80078534
    if (ctx->r1 != 0) {
        // 0x80078608: nop
    
            goto L_80078534;
    }
    // 0x80078608: nop

L_8007860C:
    // 0x8007860C: jal         0x80092728
    // 0x80078610: lh          $a0, 0x6E($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X6E));
    deletesprite(rdram, ctx);
        goto after_15;
    // 0x80078610: lh          $a0, 0x6E($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X6E));
    after_15:
    // 0x80078614: b           L_80078620
    // 0x80078618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80078620;
    // 0x80078618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8007861C:
    // 0x8007861C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80078620:
    // 0x80078620: lh          $t7, 0x6C($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X6C));
    // 0x80078624: bgez        $t7, L_80078250
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80078628: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_80078250;
    }
    // 0x80078628: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8007862C: sh          $t7, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r15;
L_80078630:
    // 0x80078630: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x80078634: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80078638: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8007863C: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80078640: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80078644: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80078648: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8007864C: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80078650: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x80078654: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80078658: jr          $ra
    // 0x8007865C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007865C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void movecyclers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007769C: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x800776A0: lh          $v0, -0x55A4($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X55A4));
    // 0x800776A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800776A8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800776AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800776B0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800776B4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800776B8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800776BC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800776C0: bltz        $v0, L_80077810
    if (SIGNED(ctx->r2) < 0) {
        // 0x800776C4: sw          $s0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r16;
            goto L_80077810;
    }
    // 0x800776C4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800776C8: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x800776CC: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800776D0: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x800776D4: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x800776D8: addiu       $t2, $t2, -0x900
    ctx->r10 = ADD32(ctx->r10, -0X900);
    // 0x800776DC: addiu       $t4, $t4, -0x9A0
    ctx->r12 = ADD32(ctx->r12, -0X9A0);
    // 0x800776E0: addiu       $t5, $t5, -0x1988
    ctx->r13 = ADD32(ctx->r13, -0X1988);
    // 0x800776E4: addiu       $s1, $s1, 0x61A8
    ctx->r17 = ADD32(ctx->r17, 0X61A8);
    // 0x800776E8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800776EC: addiu       $s2, $zero, 0x24
    ctx->r18 = ADD32(0, 0X24);
    // 0x800776F0: addiu       $s0, $zero, 0x30
    ctx->r16 = ADD32(0, 0X30);
    // 0x800776F4: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
L_800776F8:
    // 0x800776F8: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800776FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80077700: mflo        $t8
    ctx->r24 = lo;
    // 0x80077704: addu        $v1, $t2, $t8
    ctx->r3 = ADD32(ctx->r10, ctx->r24);
    // 0x80077708: lh          $a3, 0x2($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X2));
    // 0x8007770C: lh          $a1, 0x6($v1)
    ctx->r5 = S32(MEM_H(ctx->r3, 0X6));
    // 0x80077710: lbu         $t0, 0x5($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X5);
    // 0x80077714: andi        $t9, $a3, 0x7FF
    ctx->r25 = ctx->r7 & 0X7FF;
    // 0x80077718: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8007771C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80077720: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x80077724: lh          $a0, 0x0($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X0));
    // 0x80077728: sra         $t9, $t8, 10
    ctx->r25 = S32(SIGNED(ctx->r24) >> 10);
    // 0x8007772C: addu        $a2, $t9, $a1
    ctx->r6 = ADD32(ctx->r25, ctx->r5);
    // 0x80077730: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80077734: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80077738: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8007773C: beql        $at, $zero, L_80077758
    if (ctx->r1 == 0) {
        // 0x80077740: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80077758;
    }
    goto skip_0;
    // 0x80077740: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x80077744: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x80077748: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8007774C: b           L_8007776C
    // 0x80077750: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
        goto L_8007776C;
    // 0x80077750: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80077754: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_80077758:
    // 0x80077758: beq         $at, $zero, L_8007776C
    if (ctx->r1 == 0) {
        // 0x8007775C: nop
    
            goto L_8007776C;
    }
    // 0x8007775C: nop

    // 0x80077760: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x80077764: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80077768: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8007776C:
    // 0x8007776C: multu       $a0, $s0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077770: lh          $t9, 0xA($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0XA));
    // 0x80077774: mflo        $t6
    ctx->r14 = lo;
    // 0x80077778: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8007777C: lh          $t7, 0x1C($a1)
    ctx->r15 = S32(MEM_H(ctx->r5, 0X1C));
    // 0x80077780: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80077784: beq         $t9, $zero, L_80077800
    if (ctx->r25 == 0) {
        // 0x80077788: sh          $t8, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r24;
            goto L_80077800;
    }
    // 0x80077788: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x8007778C: lh          $t6, 0x8($a1)
    ctx->r14 = S32(MEM_H(ctx->r5, 0X8));
    // 0x80077790: lh          $a0, 0xA($a1)
    ctx->r4 = S32(MEM_H(ctx->r5, 0XA));
    // 0x80077794: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077798: mflo        $t7
    ctx->r15 = lo;
    // 0x8007779C: addu        $v1, $s1, $t7
    ctx->r3 = ADD32(ctx->r17, ctx->r15);
    // 0x800777A0: blezl       $a0, L_800777FC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800777A4: sb          $a2, 0x22($a1)
        MEM_B(0X22, ctx->r5) = ctx->r6;
            goto L_800777FC;
    }
    goto skip_1;
    // 0x800777A4: sb          $a2, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r6;
    skip_1:
L_800777A8:
    // 0x800777A8: lh          $t8, 0x16($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X16));
    // 0x800777AC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800777B0: beql        $s3, $t8, L_800777EC
    if (ctx->r19 == ctx->r24) {
        // 0x800777B4: sll         $t9, $a0, 16
        ctx->r25 = S32(ctx->r4 << 16);
            goto L_800777EC;
    }
    goto skip_2;
    // 0x800777B4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    skip_2:
    // 0x800777B8: lh          $t9, 0xE($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0XE));
    // 0x800777BC: sb          $a2, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r6;
    // 0x800777C0: andi        $t6, $t9, 0x2
    ctx->r14 = ctx->r25 & 0X2;
    // 0x800777C4: beql        $t6, $zero, L_800777EC
    if (ctx->r14 == 0) {
        // 0x800777C8: sll         $t9, $a0, 16
        ctx->r25 = S32(ctx->r4 << 16);
            goto L_800777EC;
    }
    goto skip_3;
    // 0x800777C8: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    skip_3:
    // 0x800777CC: lh          $a3, 0xA($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0XA));
    // 0x800777D0: bltzl       $a3, L_800777EC
    if (SIGNED(ctx->r7) < 0) {
        // 0x800777D4: sll         $t9, $a0, 16
        ctx->r25 = S32(ctx->r4 << 16);
            goto L_800777EC;
    }
    goto skip_4;
    // 0x800777D4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    skip_4:
    // 0x800777D8: multu       $a3, $s2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800777DC: mflo        $t7
    ctx->r15 = lo;
    // 0x800777E0: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x800777E4: sb          $a2, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r6;
    // 0x800777E8: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
L_800777EC:
    // 0x800777EC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800777F0: bgtz        $a0, L_800777A8
    if (SIGNED(ctx->r4) > 0) {
        // 0x800777F4: addiu       $v1, $v1, 0x24
        ctx->r3 = ADD32(ctx->r3, 0X24);
            goto L_800777A8;
    }
    // 0x800777F4: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
    // 0x800777F8: sb          $a2, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r6;
L_800777FC:
    // 0x800777FC: sb          $a2, 0x26($a1)
    MEM_B(0X26, ctx->r5) = ctx->r6;
L_80077800:
    // 0x80077800: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80077804: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80077808: bgez        $v0, L_800776F8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007780C: nop
    
            goto L_800776F8;
    }
    // 0x8007780C: nop

L_80077810:
    // 0x80077810: lw          $s0, 0x8($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X8));
    // 0x80077814: lw          $s1, 0xC($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XC));
    // 0x80077818: lw          $s2, 0x10($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X10));
    // 0x8007781C: lw          $s3, 0x14($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80077820: jr          $ra
    // 0x80077824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80077824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void tracers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1858: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800A185C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800A1860: lw          $s3, 0xB0($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A1864: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800A1868: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800A186C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800A1870: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800A1874: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A1878: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800A187C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A1880: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800A1884: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800A1888: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800A188C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800A1890: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800A1894: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800A1898: beq         $s3, $at, L_800A1B94
    if (ctx->r19 == ctx->r1) {
        // 0x800A189C: sw          $s5, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r21;
            goto L_800A1B94;
    }
    // 0x800A189C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800A18A0: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800A18A4: lw          $a1, -0x540C($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X540C));
    // 0x800A18A8: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800A18AC: subu        $t1, $a3, $s1
    ctx->r9 = SUB32(ctx->r7, ctx->r17);
    // 0x800A18B0: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800A18B4: subu        $s5, $t0, $t9
    ctx->r21 = SUB32(ctx->r8, ctx->r25);
    // 0x800A18B8: div         $zero, $t1, $s5
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r21)));
    // 0x800A18BC: lw          $a0, 0xA8($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A18C0: mflo        $v1
    ctx->r3 = lo;
    // 0x800A18C4: lw          $t3, 0xAC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A18C8: subu        $t2, $a0, $s2
    ctx->r10 = SUB32(ctx->r4, ctx->r18);
    // 0x800A18CC: div         $zero, $t2, $s5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r21)));
    // 0x800A18D0: subu        $t4, $t3, $s4
    ctx->r12 = SUB32(ctx->r11, ctx->r20);
    // 0x800A18D4: mflo        $a3
    ctx->r7 = lo;
    // 0x800A18D8: sll         $t6, $s3, 3
    ctx->r14 = S32(ctx->r19 << 3);
    // 0x800A18DC: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x800A18E0: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x800A18E4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800A18E8: addu        $t6, $t6, $s3
    ctx->r14 = ADD32(ctx->r14, ctx->r19);
    // 0x800A18EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A18F0: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x800A18F4: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800A18F8: addiu       $t7, $t7, 0x5770
    ctx->r15 = ADD32(ctx->r15, 0X5770);
    // 0x800A18FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A1900: addu        $s6, $t6, $t7
    ctx->r22 = ADD32(ctx->r14, ctx->r15);
    // 0x800A1904: lh          $t8, 0x288($s6)
    ctx->r24 = S32(MEM_H(ctx->r22, 0X288));
    // 0x800A1908: mflo        $t5
    ctx->r13 = lo;
    // 0x800A190C: subu        $v0, $s1, $s0
    ctx->r2 = SUB32(ctx->r17, ctx->r16);
    // 0x800A1910: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800A1914: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    // 0x800A1918: sh          $t8, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r24;
    // 0x800A191C: bne         $s5, $zero, L_800A1928
    if (ctx->r21 != 0) {
        // 0x800A1920: nop
    
            goto L_800A1928;
    }
    // 0x800A1920: nop

    // 0x800A1924: break       7
    do_break(2148145444);
L_800A1928:
    // 0x800A1928: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A192C: bne         $s5, $at, L_800A1940
    if (ctx->r21 != ctx->r1) {
        // 0x800A1930: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A1940;
    }
    // 0x800A1930: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A1934: bne         $t1, $at, L_800A1940
    if (ctx->r9 != ctx->r1) {
        // 0x800A1938: nop
    
            goto L_800A1940;
    }
    // 0x800A1938: nop

    // 0x800A193C: break       6
    do_break(2148145468);
L_800A1940:
    // 0x800A1940: bne         $s5, $zero, L_800A194C
    if (ctx->r21 != 0) {
        // 0x800A1944: nop
    
            goto L_800A194C;
    }
    // 0x800A1944: nop

    // 0x800A1948: break       7
    do_break(2148145480);
L_800A194C:
    // 0x800A194C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A1950: bne         $s5, $at, L_800A1964
    if (ctx->r21 != ctx->r1) {
        // 0x800A1954: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A1964;
    }
    // 0x800A1954: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A1958: bne         $t2, $at, L_800A1964
    if (ctx->r10 != ctx->r1) {
        // 0x800A195C: nop
    
            goto L_800A1964;
    }
    // 0x800A195C: nop

    // 0x800A1960: break       6
    do_break(2148145504);
L_800A1964:
    // 0x800A1964: bne         $s5, $zero, L_800A1970
    if (ctx->r21 != 0) {
        // 0x800A1968: nop
    
            goto L_800A1970;
    }
    // 0x800A1968: nop

    // 0x800A196C: break       7
    do_break(2148145516);
L_800A1970:
    // 0x800A1970: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A1974: bne         $s5, $at, L_800A1988
    if (ctx->r21 != ctx->r1) {
        // 0x800A1978: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A1988;
    }
    // 0x800A1978: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A197C: bne         $t4, $at, L_800A1988
    if (ctx->r12 != ctx->r1) {
        // 0x800A1980: nop
    
            goto L_800A1988;
    }
    // 0x800A1980: nop

    // 0x800A1984: break       6
    do_break(2148145540);
L_800A1988:
    // 0x800A1988: blezl       $v0, L_800A199C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A198C: negu        $s3, $v0
        ctx->r19 = SUB32(0, ctx->r2);
            goto L_800A199C;
    }
    goto skip_0;
    // 0x800A198C: negu        $s3, $v0
    ctx->r19 = SUB32(0, ctx->r2);
    skip_0:
    // 0x800A1990: b           L_800A199C
    // 0x800A1994: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_800A199C;
    // 0x800A1994: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800A1998: negu        $s3, $v0
    ctx->r19 = SUB32(0, ctx->r2);
L_800A199C:
    // 0x800A199C: subu        $v0, $s2, $a0
    ctx->r2 = SUB32(ctx->r18, ctx->r4);
    // 0x800A19A0: blez        $v0, L_800A19B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A19A4: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_800A19B0;
    }
    // 0x800A19A4: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x800A19A8: b           L_800A19B0
    // 0x800A19AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800A19B0;
    // 0x800A19AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800A19B0:
    // 0x800A19B0: addu        $t6, $a0, $s3
    ctx->r14 = ADD32(ctx->r4, ctx->r19);
    // 0x800A19B4: slti        $at, $t6, 0xC0C
    ctx->r1 = SIGNED(ctx->r14) < 0XC0C ? 1 : 0;
    // 0x800A19B8: bne         $at, $zero, L_800A1B94
    if (ctx->r1 != 0) {
        // 0x800A19BC: addiu       $t7, $zero, 0x8
        ctx->r15 = ADD32(0, 0X8);
            goto L_800A1B94;
    }
    // 0x800A19BC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800A19C0: subu        $s5, $t7, $a1
    ctx->r21 = SUB32(ctx->r15, ctx->r5);
    // 0x800A19C4: blez        $s5, L_800A1B94
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800A19C8: addiu       $fp, $zero, 0x7
        ctx->r30 = ADD32(0, 0X7);
            goto L_800A1B94;
    }
    // 0x800A19C8: addiu       $fp, $zero, 0x7
    ctx->r30 = ADD32(0, 0X7);
    // 0x800A19CC: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x800A19D0: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800A19D4: addiu       $s7, $sp, 0x86
    ctx->r23 = ADD32(ctx->r29, 0X86);
    // 0x800A19D8: lw          $v1, 0x90($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X90));
L_800A19DC:
    // 0x800A19DC: lw          $a3, 0x8C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800A19E0: lw          $t8, 0x88($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X88));
    // 0x800A19E4: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // 0x800A19E8: addu        $s2, $s2, $a3
    ctx->r18 = ADD32(ctx->r18, ctx->r7);
    // 0x800A19EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800A19F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A19F4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800A19F8: jal         0x80097DB8
    // 0x800A19FC: addu        $s4, $s4, $t8
    ctx->r20 = ADD32(ctx->r20, ctx->r24);
    updatesector(rdram, ctx);
        goto after_0;
    // 0x800A19FC: addu        $s4, $s4, $t8
    ctx->r20 = ADD32(ctx->r20, ctx->r24);
    after_0:
    // 0x800A1A00: lh          $t9, 0x86($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X86));
    // 0x800A1A04: bltzl       $t9, L_800A1B8C
    if (SIGNED(ctx->r25) < 0) {
        // 0x800A1A08: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_800A1B8C;
    }
    goto skip_1;
    // 0x800A1A08: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    skip_1:
    // 0x800A1A0C: lh          $t0, 0x2B2($s6)
    ctx->r8 = S32(MEM_H(ctx->r22, 0X2B2));
    // 0x800A1A10: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800A1A14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A1A18: bne         $fp, $t0, L_800A1A94
    if (ctx->r30 != ctx->r8) {
        // 0x800A1A1C: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800A1A94;
    }
    // 0x800A1A1C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A1A20: lh          $t5, 0x2E0($s6)
    ctx->r13 = S32(MEM_H(ctx->r22, 0X2E0));
    // 0x800A1A24: addiu       $t1, $zero, 0x990
    ctx->r9 = ADD32(0, 0X990);
    // 0x800A1A28: addiu       $t2, $zero, -0x10
    ctx->r10 = ADD32(0, -0X10);
    // 0x800A1A2C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A1A30: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A1A34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A1A38: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800A1A3C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A1A40: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A1A44: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800A1A48: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800A1A4C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800A1A50: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A1A54: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A1A58: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A1A5C: jal         0x8009B028
    // 0x800A1A60: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    EGS(rdram, ctx);
        goto after_1;
    // 0x800A1A60: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    after_1:
    // 0x800A1A64: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800A1A68: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800A1A6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A1A70: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800A1A74: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800A1A78: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x800A1A7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A1A80: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800A1A84: lh          $t0, 0xC($v1)
    ctx->r8 = S32(MEM_H(ctx->r3, 0XC));
    // 0x800A1A88: ori         $t9, $t0, 0x82
    ctx->r25 = ctx->r8 | 0X82;
    // 0x800A1A8C: b           L_800A1B88
    // 0x800A1A90: sh          $t9, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r25;
        goto L_800A1B88;
    // 0x800A1A90: sh          $t9, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r25;
L_800A1A94:
    // 0x800A1A94: lh          $t1, 0x86($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X86));
    // 0x800A1A98: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x800A1A9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A1AA0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A1AA4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A1AA8: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800A1AAC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A1AB0: lh          $t3, -0x1970($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X1970));
    // 0x800A1AB4: bnel        $t3, $at, L_800A1B3C
    if (ctx->r11 != ctx->r1) {
        // 0x800A1AB8: lh          $t7, 0x2E0($s6)
        ctx->r15 = S32(MEM_H(ctx->r22, 0X2E0));
            goto L_800A1B3C;
    }
    goto skip_2;
    // 0x800A1AB8: lh          $t7, 0x2E0($s6)
    ctx->r15 = S32(MEM_H(ctx->r22, 0X2E0));
    skip_2:
    // 0x800A1ABC: jal         0x8009800C
    // 0x800A1AC0: nop

    krand2(rdram, ctx);
        goto after_2;
    // 0x800A1AC0: nop

    after_2:
    // 0x800A1AC4: jal         0x8009800C
    // 0x800A1AC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_3;
    // 0x800A1AC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_3:
    // 0x800A1ACC: jal         0x8009800C
    // 0x800A1AD0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_4;
    // 0x800A1AD0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_4:
    // 0x800A1AD4: lh          $t1, 0x2E0($s6)
    ctx->r9 = S32(MEM_H(ctx->r22, 0X2E0));
    // 0x800A1AD8: andi        $t6, $s0, 0x3
    ctx->r14 = ctx->r16 & 0X3;
    // 0x800A1ADC: andi        $t8, $s3, 0x3
    ctx->r24 = ctx->r19 & 0X3;
    // 0x800A1AE0: addiu       $t0, $t8, 0x4
    ctx->r8 = ADD32(ctx->r24, 0X4);
    // 0x800A1AE4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800A1AE8: addiu       $t4, $zero, 0x295
    ctx->r12 = ADD32(0, 0X295);
    // 0x800A1AEC: addiu       $t5, $zero, -0x20
    ctx->r13 = ADD32(0, -0X20);
    // 0x800A1AF0: andi        $t9, $v0, 0x7FF
    ctx->r25 = ctx->r2 & 0X7FF;
    // 0x800A1AF4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800A1AF8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A1AFC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800A1B00: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A1B04: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A1B08: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800A1B0C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A1B10: lh          $a0, 0x86($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X86));
    // 0x800A1B14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A1B18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A1B1C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800A1B20: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A1B24: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A1B28: jal         0x8009B028
    // 0x800A1B2C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    EGS(rdram, ctx);
        goto after_5;
    // 0x800A1B2C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_5:
    // 0x800A1B30: b           L_800A1B8C
    // 0x800A1B34: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_800A1B8C;
    // 0x800A1B34: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800A1B38: lh          $t7, 0x2E0($s6)
    ctx->r15 = S32(MEM_H(ctx->r22, 0X2E0));
L_800A1B3C:
    // 0x800A1B3C: addiu       $t3, $zero, 0x919
    ctx->r11 = ADD32(0, 0X919);
    // 0x800A1B40: addiu       $t4, $zero, -0x20
    ctx->r12 = ADD32(0, -0X20);
    // 0x800A1B44: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x800A1B48: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800A1B4C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800A1B50: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800A1B54: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A1B58: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800A1B5C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800A1B60: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A1B64: lh          $a0, 0x86($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X86));
    // 0x800A1B68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A1B6C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A1B70: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800A1B74: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A1B78: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A1B7C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A1B80: jal         0x8009B028
    // 0x800A1B84: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    EGS(rdram, ctx);
        goto after_6;
    // 0x800A1B84: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_6:
L_800A1B88:
    // 0x800A1B88: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800A1B8C:
    // 0x800A1B8C: bgtzl       $s5, L_800A19DC
    if (SIGNED(ctx->r21) > 0) {
        // 0x800A1B90: lw          $v1, 0x90($sp)
        ctx->r3 = S32(MEM_W(ctx->r29, 0X90));
            goto L_800A19DC;
    }
    goto skip_3;
    // 0x800A1B90: lw          $v1, 0x90($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X90));
    skip_3:
L_800A1B94:
    // 0x800A1B94: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800A1B98: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800A1B9C: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800A1BA0: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800A1BA4: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800A1BA8: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800A1BAC: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800A1BB0: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800A1BB4: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800A1BB8: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800A1BBC: jr          $ra
    // 0x800A1BC0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800A1BC0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void initcache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800717F0: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800717F4: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800717F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800717FC: addiu       $v0, $v0, 0x1FE0
    ctx->r2 = ADD32(ctx->r2, 0X1FE0);
    // 0x80071800: addiu       $v1, $v1, -0x1020
    ctx->r3 = ADD32(ctx->r3, -0X1020);
L_80071804:
    // 0x80071804: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80071808: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8007180C: bne         $at, $zero, L_80071804
    if (ctx->r1 != 0) {
        // 0x80071810: sw          $zero, -0x8($v1)
        MEM_W(-0X8, ctx->r3) = 0;
            goto L_80071804;
    }
    // 0x80071810: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x80071814: lui         $t6, 0x14
    ctx->r14 = S32(0X14 << 16);
    // 0x80071818: ori         $t6, $t6, 0x9539
    ctx->r14 = ctx->r14 | 0X9539;
    // 0x8007181C: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80071820: sw          $t6, 0x1FE4($at)
    MEM_W(0X1FE4, ctx->r1) = ctx->r14;
    // 0x80071824: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80071828: lui         $t7, 0x14
    ctx->r15 = S32(0X14 << 16);
    // 0x8007182C: lui         $t8, 0x14
    ctx->r24 = S32(0X14 << 16);
    // 0x80071830: ori         $t8, $t8, 0xCAB8
    ctx->r24 = ctx->r24 | 0XCAB8;
    // 0x80071834: ori         $t7, $t7, 0xAFD6
    ctx->r15 = ctx->r15 | 0XAFD6;
    // 0x80071838: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x8007183C: addiu       $v1, $v1, 0x1FF0
    ctx->r3 = ADD32(ctx->r3, 0X1FF0);
    // 0x80071840: sw          $t7, 0x1FE8($at)
    MEM_W(0X1FE8, ctx->r1) = ctx->r15;
    // 0x80071844: sw          $t8, 0x1FEC($at)
    MEM_W(0X1FEC, ctx->r1) = ctx->r24;
    // 0x80071848: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007184C: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x80071850: subu        $a0, $a3, $v0
    ctx->r4 = SUB32(ctx->r7, ctx->r2);
L_80071854:
    // 0x80071854: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x80071858: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x8007185C: mflo        $t0
    ctx->r8 = lo;
    // 0x80071860: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x80071864: lui         $t2, 0x1000
    ctx->r10 = S32(0X1000 << 16);
    // 0x80071868: div         $zero, $t2, $t1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r9)));
    // 0x8007186C: mflo        $t3
    ctx->r11 = lo;
    // 0x80071870: addiu       $t4, $a0, -0x2
    ctx->r12 = ADD32(ctx->r4, -0X2);
    // 0x80071874: lui         $t5, 0x1000
    ctx->r13 = S32(0X1000 << 16);
    // 0x80071878: div         $zero, $t5, $t4
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r12)));
    // 0x8007187C: addiu       $t7, $a0, -0x3
    ctx->r15 = ADD32(ctx->r4, -0X3);
    // 0x80071880: lui         $t8, 0x1000
    ctx->r24 = S32(0X1000 << 16);
    // 0x80071884: mflo        $t6
    ctx->r14 = lo;
    // 0x80071888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007188C: bne         $a0, $zero, L_80071898
    if (ctx->r4 != 0) {
        // 0x80071890: nop
    
            goto L_80071898;
    }
    // 0x80071890: nop

    // 0x80071894: break       7
    do_break(2147948692);
L_80071898:
    // 0x80071898: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007189C: bne         $a0, $at, L_800718B0
    if (ctx->r4 != ctx->r1) {
        // 0x800718A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800718B0;
    }
    // 0x800718A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800718A4: bne         $t9, $at, L_800718B0
    if (ctx->r25 != ctx->r1) {
        // 0x800718A8: nop
    
            goto L_800718B0;
    }
    // 0x800718A8: nop

    // 0x800718AC: break       6
    do_break(2147948716);
L_800718B0:
    // 0x800718B0: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x800718B4: mflo        $t9
    ctx->r25 = lo;
    // 0x800718B8: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x800718BC: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x800718C0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800718C4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800718C8: bne         $t1, $zero, L_800718D4
    if (ctx->r9 != 0) {
        // 0x800718CC: nop
    
            goto L_800718D4;
    }
    // 0x800718CC: nop

    // 0x800718D0: break       7
    do_break(2147948752);
L_800718D4:
    // 0x800718D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800718D8: bne         $t1, $at, L_800718EC
    if (ctx->r9 != ctx->r1) {
        // 0x800718DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800718EC;
    }
    // 0x800718DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800718E0: bne         $t2, $at, L_800718EC
    if (ctx->r10 != ctx->r1) {
        // 0x800718E4: nop
    
            goto L_800718EC;
    }
    // 0x800718E4: nop

    // 0x800718E8: break       6
    do_break(2147948776);
L_800718EC:
    // 0x800718EC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800718F0: bne         $t4, $zero, L_800718FC
    if (ctx->r12 != 0) {
        // 0x800718F4: nop
    
            goto L_800718FC;
    }
    // 0x800718F4: nop

    // 0x800718F8: break       7
    do_break(2147948792);
L_800718FC:
    // 0x800718FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80071900: bne         $t4, $at, L_80071914
    if (ctx->r12 != ctx->r1) {
        // 0x80071904: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80071914;
    }
    // 0x80071904: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80071908: bne         $t5, $at, L_80071914
    if (ctx->r13 != ctx->r1) {
        // 0x8007190C: nop
    
            goto L_80071914;
    }
    // 0x8007190C: nop

    // 0x80071910: break       6
    do_break(2147948816);
L_80071914:
    // 0x80071914: bne         $t7, $zero, L_80071920
    if (ctx->r15 != 0) {
        // 0x80071918: nop
    
            goto L_80071920;
    }
    // 0x80071918: nop

    // 0x8007191C: break       7
    do_break(2147948828);
L_80071920:
    // 0x80071920: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80071924: bne         $t7, $at, L_80071938
    if (ctx->r15 != ctx->r1) {
        // 0x80071928: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80071938;
    }
    // 0x80071928: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007192C: bne         $t8, $at, L_80071938
    if (ctx->r24 != ctx->r1) {
        // 0x80071930: nop
    
            goto L_80071938;
    }
    // 0x80071930: nop

    // 0x80071934: break       6
    do_break(2147948852);
L_80071938:
    // 0x80071938: bnel        $v0, $a3, L_80071854
    if (ctx->r2 != ctx->r7) {
        // 0x8007193C: subu        $a0, $a3, $v0
        ctx->r4 = SUB32(ctx->r7, ctx->r2);
            goto L_80071854;
    }
    goto skip_0;
    // 0x8007193C: subu        $a0, $a3, $v0
    ctx->r4 = SUB32(ctx->r7, ctx->r2);
    skip_0:
    // 0x80071940: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80071944: sw          $a2, -0x1814($at)
    MEM_W(-0X1814, ctx->r1) = ctx->r6;
    // 0x80071948: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x8007194C: addiu       $v1, $v1, -0x1020
    ctx->r3 = ADD32(ctx->r3, -0X1020);
    // 0x80071950: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80071954: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x80071958: addiu       $v0, $v0, -0x1820
    ctx->r2 = ADD32(ctx->r2, -0X1820);
    // 0x8007195C: addiu       $t2, $t2, -0x1818
    ctx->r10 = ADD32(ctx->r10, -0X1818);
    // 0x80071960: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80071964: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80071968: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8007196C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80071970: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80071974: jr          $ra
    // 0x80071978: sw          $t1, -0x1810($at)
    MEM_W(-0X1810, ctx->r1) = ctx->r9;
    return;
    // 0x80071978: sw          $t1, -0x1810($at)
    MEM_W(-0X1810, ctx->r1) = ctx->r9;
;}
RECOMP_FUNC void operatesectors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADBFC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800ADC00: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800ADC04: lh          $t6, 0xA2($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800ADC08: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800ADC0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800ADC10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ADC14: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800ADC18: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800ADC1C: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x800ADC20: addu        $s7, $t7, $t8
    ctx->r23 = ADD32(ctx->r15, ctx->r24);
    // 0x800ADC24: lh          $t0, 0x18($s7)
    ctx->r8 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800ADC28: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800ADC2C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800ADC30: andi        $t9, $t0, 0x3FFF
    ctx->r25 = ctx->r8 & 0X3FFF;
    // 0x800ADC34: addiu       $t4, $t9, -0x9
    ctx->r12 = ADD32(ctx->r25, -0X9);
    // 0x800ADC38: sltiu       $at, $t4, 0x17
    ctx->r1 = ctx->r12 < 0X17 ? 1 : 0;
    // 0x800ADC3C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800ADC40: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800ADC44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800ADC48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800ADC4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800ADC50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800ADC54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ADC58: beq         $at, $zero, L_800AEFD4
    if (ctx->r1 == 0) {
        // 0x800ADC5C: sw          $a1, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->r5;
            goto L_800AEFD4;
    }
    // 0x800ADC5C: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800ADC60: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800ADC64: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800ADC68: addu        $at, $at, $t4
    gpr jr_addend_800ADC70 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800ADC6C: lw          $t4, -0x7948($at)
    ctx->r12 = ADD32(ctx->r1, -0X7948);
    // 0x800ADC70: jr          $t4
    // 0x800ADC74: nop

    switch (jr_addend_800ADC70 >> 2) {
        case 0: goto L_800ADDC0; break;
        case 1: goto L_800AEFD4; break;
        case 2: goto L_800AEFD4; break;
        case 3: goto L_800AEFD4; break;
        case 4: goto L_800AEFD4; break;
        case 5: goto L_800AEFD4; break;
        case 6: goto L_800AE2CC; break;
        case 7: goto L_800AE424; break;
        case 8: goto L_800AE424; break;
        case 9: goto L_800AE510; break;
        case 10: goto L_800AE510; break;
        case 11: goto L_800AE740; break;
        case 12: goto L_800AE850; break;
        case 13: goto L_800AE958; break;
        case 14: goto L_800AEA40; break;
        case 15: goto L_800AEFD4; break;
        case 16: goto L_800AEC40; break;
        case 17: goto L_800ADD38; break;
        case 18: goto L_800AEDF0; break;
        case 19: goto L_800AEEC0; break;
        case 20: goto L_800AE5F8; break;
        case 21: goto L_800ADC78; break;
        case 22: goto L_800ADCF4; break;
        default: switch_error(__func__, 0x800ADC70, 0x801086B8);
    }
    // 0x800ADC74: nop

L_800ADC78:
    // 0x800ADC78: lh          $fp, 0x1A($s7)
    ctx->r30 = S32(MEM_H(ctx->r23, 0X1A));
    // 0x800ADC7C: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800ADC80: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800ADC84: multu       $fp, $t0
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADC88: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800ADC8C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800ADC90: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800ADC94: mflo        $t5
    ctx->r13 = lo;
    // 0x800ADC98: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x800ADC9C: lh          $v0, 0xC($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0XC));
    // 0x800ADCA0: beq         $v0, $zero, L_800ADCB0
    if (ctx->r2 == 0) {
        // 0x800ADCA4: nop
    
            goto L_800ADCB0;
    }
    // 0x800ADCA4: nop

    // 0x800ADCA8: bnel        $v0, $at, L_800ADCBC
    if (ctx->r2 != ctx->r1) {
        // 0x800ADCAC: addiu       $s5, $zero, 0x2C
        ctx->r21 = ADD32(0, 0X2C);
            goto L_800ADCBC;
    }
    goto skip_0;
    // 0x800ADCAC: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    skip_0:
L_800ADCB0:
    // 0x800ADCB0: jal         0x800AC900
    // 0x800ADCB4: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_0;
    // 0x800ADCB4: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_0:
    // 0x800ADCB8: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
L_800ADCBC:
    // 0x800ADCBC: multu       $fp, $s5
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADCC0: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800ADCC4: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800ADCC8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800ADCCC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800ADCD0: mflo        $t7
    ctx->r15 = lo;
    // 0x800ADCD4: addu        $s3, $s4, $t7
    ctx->r19 = ADD32(ctx->r20, ctx->r15);
    // 0x800ADCD8: lh          $t8, 0x22($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X22));
    // 0x800ADCDC: bne         $s6, $t8, L_800ADCEC
    if (ctx->r22 != ctx->r24) {
        // 0x800ADCE0: nop
    
            goto L_800ADCEC;
    }
    // 0x800ADCE0: nop

    // 0x800ADCE4: b           L_800AEFD4
    // 0x800ADCE8: sh          $v1, 0x22($s3)
    MEM_H(0X22, ctx->r19) = ctx->r3;
        goto L_800AEFD4;
    // 0x800ADCE8: sh          $v1, 0x22($s3)
    MEM_H(0X22, ctx->r19) = ctx->r3;
L_800ADCEC:
    // 0x800ADCEC: b           L_800AEFD4
    // 0x800ADCF0: sh          $s6, 0x22($s3)
    MEM_H(0X22, ctx->r19) = ctx->r22;
        goto L_800AEFD4;
    // 0x800ADCF0: sh          $s6, 0x22($s3)
    MEM_H(0X22, ctx->r19) = ctx->r22;
L_800ADCF4:
    // 0x800ADCF4: lh          $fp, 0x1A($s7)
    ctx->r30 = S32(MEM_H(ctx->r23, 0X1A));
    // 0x800ADCF8: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800ADCFC: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800ADD00: multu       $fp, $t0
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADD04: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800ADD08: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800ADD0C: mflo        $t9
    ctx->r25 = lo;
    // 0x800ADD10: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x800ADD14: lw          $t4, 0x40($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X40));
    // 0x800ADD18: bnel        $t4, $zero, L_800ADD28
    if (ctx->r12 != 0) {
        // 0x800ADD1C: lh          $a0, 0xA2($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
            goto L_800ADD28;
    }
    goto skip_1;
    // 0x800ADD1C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    skip_1:
    // 0x800ADD20: sw          $s6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r22;
    // 0x800ADD24: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
L_800ADD28:
    // 0x800ADD28: jal         0x800AC900
    // 0x800ADD2C: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_1;
    // 0x800ADD2C: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_1:
    // 0x800ADD30: b           L_800AEFD8
    // 0x800ADD34: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800ADD34: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800ADD38:
    // 0x800ADD38: jal         0x800AD620
    // 0x800ADD3C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    getanimationgoal(rdram, ctx);
        goto after_2;
    // 0x800ADD3C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
    // 0x800ADD40: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x800ADD44: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800ADD48: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800ADD4C: bne         $s0, $t6, L_800AEFD4
    if (ctx->r16 != ctx->r14) {
        // 0x800ADD50: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800AEFD4;
    }
    // 0x800ADD50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ADD54: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800ADD58: sb          $t7, -0x9B0($at)
    MEM_B(-0X9B0, ctx->r1) = ctx->r15;
    // 0x800ADD5C: lh          $t8, 0x18($s7)
    ctx->r24 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800ADD60: andi        $t9, $t8, 0xFF00
    ctx->r25 = ctx->r24 & 0XFF00;
    // 0x800ADD64: sh          $t9, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r25;
    // 0x800ADD68: lh          $t4, 0x18($s7)
    ctx->r12 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800ADD6C: ori         $t5, $t4, 0x16
    ctx->r13 = ctx->r12 | 0X16;
    // 0x800ADD70: sh          $t5, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r13;
    // 0x800ADD74: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    // 0x800ADD78: jal         0x800ADBFC
    // 0x800ADD7C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    operatesectors(rdram, ctx);
        goto after_3;
    // 0x800ADD7C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    after_3:
    // 0x800ADD80: lh          $t6, 0x18($s7)
    ctx->r14 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800ADD84: andi        $t7, $t6, 0xFF00
    ctx->r15 = ctx->r14 & 0XFF00;
    // 0x800ADD88: sh          $t7, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r15;
    // 0x800ADD8C: lh          $t8, 0x18($s7)
    ctx->r24 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800ADD90: ori         $t9, $t8, 0x9
    ctx->r25 = ctx->r24 | 0X9;
    // 0x800ADD94: sh          $t9, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r25;
    // 0x800ADD98: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    // 0x800ADD9C: jal         0x800ADBFC
    // 0x800ADDA0: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    operatesectors(rdram, ctx);
        goto after_4;
    // 0x800ADDA0: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    after_4:
    // 0x800ADDA4: lh          $t4, 0x18($s7)
    ctx->r12 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800ADDA8: andi        $t5, $t4, 0xFF00
    ctx->r13 = ctx->r12 & 0XFF00;
    // 0x800ADDAC: sh          $t5, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r13;
    // 0x800ADDB0: lh          $t6, 0x18($s7)
    ctx->r14 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800ADDB4: ori         $t7, $t6, 0x1A
    ctx->r15 = ctx->r14 | 0X1A;
    // 0x800ADDB8: b           L_800AEFD4
    // 0x800ADDBC: sh          $t7, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r15;
        goto L_800AEFD4;
    // 0x800ADDBC: sh          $t7, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r15;
L_800ADDC0:
    // 0x800ADDC0: lh          $a1, 0x8($s7)
    ctx->r5 = S32(MEM_H(ctx->r23, 0X8));
    // 0x800ADDC4: lh          $t8, 0xA($s7)
    ctx->r24 = S32(MEM_H(ctx->r23, 0XA));
    // 0x800ADDC8: lh          $s6, 0x1C($s7)
    ctx->r22 = S32(MEM_H(ctx->r23, 0X1C));
    // 0x800ADDCC: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x800ADDD0: addu        $a2, $t8, $a1
    ctx->r6 = ADD32(ctx->r24, ctx->r5);
    // 0x800ADDD4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800ADDD8: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ADDDC: sll         $s2, $a1, 16
    ctx->r18 = S32(ctx->r5 << 16);
    // 0x800ADDE0: sra         $t4, $s2, 16
    ctx->r12 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800ADDE4: slt         $at, $a2, $t5
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800ADDE8: sra         $t9, $s6, 4
    ctx->r25 = S32(SIGNED(ctx->r22) >> 4);
    // 0x800ADDEC: or          $s6, $t9, $zero
    ctx->r22 = ctx->r25 | 0;
    // 0x800ADDF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800ADDF4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800ADDF8: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x800ADDFC: bne         $at, $zero, L_800ADE50
    if (ctx->r1 != 0) {
        // 0x800ADE00: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_800ADE50;
    }
    // 0x800ADE00: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800ADE04: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x800ADE08: addiu       $s4, $s4, 0x61A8
    ctx->r20 = ADD32(ctx->r20, 0X61A8);
    // 0x800ADE0C: addiu       $s5, $zero, 0x24
    ctx->r21 = ADD32(0, 0X24);
L_800ADE10:
    // 0x800ADE10: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADE14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800ADE18: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x800ADE1C: sra         $t4, $t9, 16
    ctx->r12 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800ADE20: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800ADE24: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x800ADE28: mflo        $t6
    ctx->r14 = lo;
    // 0x800ADE2C: addu        $s1, $s4, $t6
    ctx->r17 = ADD32(ctx->r20, ctx->r14);
    // 0x800ADE30: lw          $t7, 0x0($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800ADE34: lw          $t8, 0x4($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800ADE38: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800ADE3C: beq         $at, $zero, L_800ADE10
    if (ctx->r1 == 0) {
        // 0x800ADE40: addu        $t0, $t0, $t8
        ctx->r8 = ADD32(ctx->r8, ctx->r24);
            goto L_800ADE10;
    }
    // 0x800ADE40: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800ADE44: sll         $s2, $a1, 16
    ctx->r18 = S32(ctx->r5 << 16);
    // 0x800ADE48: sra         $t5, $s2, 16
    ctx->r13 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800ADE4C: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
L_800ADE50:
    // 0x800ADE50: subu        $v1, $a2, $a1
    ctx->r3 = SUB32(ctx->r6, ctx->r5);
    // 0x800ADE54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800ADE58: div         $zero, $a3, $v1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r3)));
    // 0x800ADE5C: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x800ADE60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ADE64: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800ADE68: addiu       $s4, $s4, 0x61A8
    ctx->r20 = ADD32(ctx->r20, 0X61A8);
    // 0x800ADE6C: addiu       $s5, $zero, 0x24
    ctx->r21 = ADD32(0, 0X24);
    // 0x800ADE70: bne         $v1, $zero, L_800ADE7C
    if (ctx->r3 != 0) {
        // 0x800ADE74: nop
    
            goto L_800ADE7C;
    }
    // 0x800ADE74: nop

    // 0x800ADE78: break       7
    do_break(2148195960);
L_800ADE7C:
    // 0x800ADE7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ADE80: bne         $v1, $at, L_800ADE94
    if (ctx->r3 != ctx->r1) {
        // 0x800ADE84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ADE94;
    }
    // 0x800ADE84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ADE88: bne         $a3, $at, L_800ADE94
    if (ctx->r7 != ctx->r1) {
        // 0x800ADE8C: nop
    
            goto L_800ADE94;
    }
    // 0x800ADE8C: nop

    // 0x800ADE90: break       6
    do_break(2148195984);
L_800ADE94:
    // 0x800ADE94: mflo        $a3
    ctx->r7 = lo;
    // 0x800ADE98: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x800ADE9C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800ADEA0: div         $zero, $t0, $v1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r3)));
    // 0x800ADEA4: bne         $v1, $zero, L_800ADEB0
    if (ctx->r3 != 0) {
        // 0x800ADEA8: nop
    
            goto L_800ADEB0;
    }
    // 0x800ADEA8: nop

    // 0x800ADEAC: break       7
    do_break(2148196012);
L_800ADEB0:
    // 0x800ADEB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ADEB4: bne         $v1, $at, L_800ADEC8
    if (ctx->r3 != ctx->r1) {
        // 0x800ADEB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ADEC8;
    }
    // 0x800ADEB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ADEBC: bne         $t0, $at, L_800ADEC8
    if (ctx->r8 != ctx->r1) {
        // 0x800ADEC0: nop
    
            goto L_800ADEC8;
    }
    // 0x800ADEC0: nop

    // 0x800ADEC4: break       6
    do_break(2148196036);
L_800ADEC8:
    // 0x800ADEC8: mflo        $t0
    ctx->r8 = lo;
    // 0x800ADECC: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800ADED0: bne         $at, $zero, L_800ADF30
    if (ctx->r1 != 0) {
        // 0x800ADED4: addiu       $s7, $sp, 0x68
        ctx->r23 = ADD32(ctx->r29, 0X68);
            goto L_800ADF30;
    }
    // 0x800ADED4: addiu       $s7, $sp, 0x68
    ctx->r23 = ADD32(ctx->r29, 0X68);
    // 0x800ADED8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_800ADEDC:
    // 0x800ADEDC: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADEE0: mflo        $t7
    ctx->r15 = lo;
    // 0x800ADEE4: addu        $s1, $s4, $t7
    ctx->r17 = ADD32(ctx->r20, ctx->r15);
    // 0x800ADEE8: lw          $t8, 0x0($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800ADEEC: beq         $a3, $t8, L_800ADF00
    if (ctx->r7 == ctx->r24) {
        // 0x800ADEF0: nop
    
            goto L_800ADF00;
    }
    // 0x800ADEF0: nop

    // 0x800ADEF4: lw          $t9, 0x4($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800ADEF8: bnel        $t0, $t9, L_800ADF18
    if (ctx->r8 != ctx->r25) {
        // 0x800ADEFC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800ADF18;
    }
    goto skip_2;
    // 0x800ADEFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
L_800ADF00:
    // 0x800ADF00: bnel        $s0, $v0, L_800ADF14
    if (ctx->r16 != ctx->r2) {
        // 0x800ADF04: sw          $s2, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r18;
            goto L_800ADF14;
    }
    goto skip_3;
    // 0x800ADF04: sw          $s2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r18;
    skip_3:
    // 0x800ADF08: b           L_800ADF14
    // 0x800ADF0C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800ADF14;
    // 0x800ADF0C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800ADF10: sw          $s2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r18;
L_800ADF14:
    // 0x800ADF14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800ADF18:
    // 0x800ADF18: sll         $t4, $s2, 16
    ctx->r12 = S32(ctx->r18 << 16);
    // 0x800ADF1C: sra         $s2, $t4, 16
    ctx->r18 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800ADF20: slt         $at, $a2, $s2
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800ADF24: beq         $at, $zero, L_800ADEDC
    if (ctx->r1 == 0) {
        // 0x800ADF28: nop
    
            goto L_800ADEDC;
    }
    // 0x800ADF28: nop

    // 0x800ADF2C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
L_800ADF30:
    // 0x800ADF30: sw          $a1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r5;
    // 0x800ADF34: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    // 0x800ADF38: sw          $a3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r7;
    // 0x800ADF3C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800ADF40: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800ADF44: lw          $v0, 0x0($s7)
    ctx->r2 = S32(MEM_W(ctx->r23, 0X0));
L_800ADF48:
    // 0x800ADF48: lw          $a3, 0x80($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800ADF4C: lw          $a2, 0x8C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800ADF50: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADF54: addiu       $s2, $v0, -0x1
    ctx->r18 = ADD32(ctx->r2, -0X1);
    // 0x800ADF58: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x800ADF5C: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800ADF60: lw          $t0, 0x7C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800ADF64: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x800ADF68: mflo        $t6
    ctx->r14 = lo;
    // 0x800ADF6C: addu        $s3, $s4, $t6
    ctx->r19 = ADD32(ctx->r20, ctx->r14);
    // 0x800ADF70: lw          $t2, 0x0($s3)
    ctx->r10 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800ADF74: bnel        $a3, $t2, L_800AE148
    if (ctx->r7 != ctx->r10) {
        // 0x800ADF78: lw          $t1, 0x4($s3)
        ctx->r9 = S32(MEM_W(ctx->r19, 0X4));
            goto L_800AE148;
    }
    goto skip_4;
    // 0x800ADF78: lw          $t1, 0x4($s3)
    ctx->r9 = S32(MEM_W(ctx->r19, 0X4));
    skip_4:
    // 0x800ADF7C: lw          $t1, 0x4($s3)
    ctx->r9 = S32(MEM_W(ctx->r19, 0X4));
    // 0x800ADF80: bnel        $t0, $t1, L_800AE148
    if (ctx->r8 != ctx->r9) {
        // 0x800ADF84: lw          $t1, 0x4($s3)
        ctx->r9 = S32(MEM_W(ctx->r19, 0X4));
            goto L_800AE148;
    }
    goto skip_5;
    // 0x800ADF84: lw          $t1, 0x4($s3)
    ctx->r9 = S32(MEM_W(ctx->r19, 0X4));
    skip_5:
    // 0x800ADF88: addiu       $s2, $v0, -0x1
    ctx->r18 = ADD32(ctx->r2, -0X1);
    // 0x800ADF8C: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800ADF90: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800ADF94: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x800ADF98: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    // 0x800ADF9C: sw          $a3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r7;
    // 0x800ADFA0: beq         $at, $zero, L_800ADFC0
    if (ctx->r1 == 0) {
        // 0x800ADFA4: sw          $t0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r8;
            goto L_800ADFC0;
    }
    // 0x800ADFA4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800ADFA8: sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6 << 16);
    // 0x800ADFAC: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800ADFB0: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800ADFB4: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    // 0x800ADFB8: sw          $a3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r7;
    // 0x800ADFBC: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
L_800ADFC0:
    // 0x800ADFC0: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADFC4: lh          $t5, 0x8($s3)
    ctx->r13 = S32(MEM_H(ctx->r19, 0X8));
    // 0x800ADFC8: mflo        $t4
    ctx->r12 = lo;
    // 0x800ADFCC: addu        $s1, $s4, $t4
    ctx->r17 = ADD32(ctx->r20, ctx->r12);
    // 0x800ADFD0: lw          $t7, 0x0($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800ADFD4: multu       $t5, $s5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADFD8: lw          $t4, 0x4($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800ADFDC: mflo        $t6
    ctx->r14 = lo;
    // 0x800ADFE0: addu        $s0, $s4, $t6
    ctx->r16 = ADD32(ctx->r20, ctx->r14);
    // 0x800ADFE4: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800ADFE8: lw          $t3, 0x4($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800ADFEC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800ADFF0: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x800ADFF4: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800ADFF8: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800ADFFC: beq         $t9, $t2, L_800AE0A0
    if (ctx->r25 == ctx->r10) {
        // 0x800AE000: subu        $t0, $t6, $t1
        ctx->r8 = SUB32(ctx->r14, ctx->r9);
            goto L_800AE0A0;
    }
    // 0x800AE000: subu        $t0, $t6, $t1
    ctx->r8 = SUB32(ctx->r14, ctx->r9);
    // 0x800AE004: lh          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800AE008: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE00C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AE010: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE014: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE018: mflo        $t8
    ctx->r24 = lo;
    // 0x800AE01C: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x800AE020: lw          $v1, 0x0($t9)
    ctx->r3 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800AE024: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800AE028: addu        $a2, $t2, $v1
    ctx->r6 = ADD32(ctx->r10, ctx->r3);
    // 0x800AE02C: jal         0x800AD66C
    // 0x800AE030: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    setanimation(rdram, ctx);
        goto after_5;
    // 0x800AE030: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    after_5:
    // 0x800AE034: lw          $v1, 0x78($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800AE038: lw          $t4, 0x0($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800AE03C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE040: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AE044: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE048: jal         0x800AD66C
    // 0x800AE04C: addu        $a2, $t4, $v1
    ctx->r6 = ADD32(ctx->r12, ctx->r3);
    setanimation(rdram, ctx);
        goto after_6;
    // 0x800AE04C: addu        $a2, $t4, $v1
    ctx->r6 = ADD32(ctx->r12, ctx->r3);
    after_6:
    // 0x800AE050: lw          $t5, 0x0($s7)
    ctx->r13 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE054: lw          $v1, 0x78($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800AE058: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE05C: multu       $t5, $s5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE060: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE064: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE068: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x800AE06C: lh          $t8, 0x8($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X8));
    // 0x800AE070: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE074: mflo        $t9
    ctx->r25 = lo;
    // 0x800AE078: addu        $s0, $s4, $t9
    ctx->r16 = ADD32(ctx->r20, ctx->r25);
    // 0x800AE07C: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800AE080: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AE084: jal         0x800AD66C
    // 0x800AE088: addu        $a2, $t4, $v1
    ctx->r6 = ADD32(ctx->r12, ctx->r3);
    setanimation(rdram, ctx);
        goto after_7;
    // 0x800AE088: addu        $a2, $t4, $v1
    ctx->r6 = ADD32(ctx->r12, ctx->r3);
    after_7:
    // 0x800AE08C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE090: jal         0x800AC900
    // 0x800AE094: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_8;
    // 0x800AE094: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_8:
    // 0x800AE098: b           L_800AE2B8
    // 0x800AE09C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
        goto L_800AE2B8;
    // 0x800AE09C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
L_800AE0A0:
    // 0x800AE0A0: beql        $t0, $zero, L_800AE2B8
    if (ctx->r8 == 0) {
        // 0x800AE0A4: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_800AE2B8;
    }
    goto skip_6;
    // 0x800AE0A4: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    skip_6:
    // 0x800AE0A8: lh          $t5, 0x8($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X8));
    // 0x800AE0AC: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE0B0: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x800AE0B4: multu       $t5, $s5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE0B8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE0BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE0C0: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x800AE0C4: lw          $t0, 0x4($t7)
    ctx->r8 = S32(MEM_W(ctx->r15, 0X4));
    // 0x800AE0C8: subu        $t0, $t0, $t3
    ctx->r8 = SUB32(ctx->r8, ctx->r11);
    // 0x800AE0CC: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    // 0x800AE0D0: jal         0x800AD66C
    // 0x800AE0D4: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    setanimation(rdram, ctx);
        goto after_9;
    // 0x800AE0D4: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    after_9:
    // 0x800AE0D8: lw          $t0, 0x74($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X74));
    // 0x800AE0DC: lw          $t8, 0x4($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800AE0E0: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE0E4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800AE0E8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE0EC: jal         0x800AD66C
    // 0x800AE0F0: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    setanimation(rdram, ctx);
        goto after_10;
    // 0x800AE0F0: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_10:
    // 0x800AE0F4: lw          $t9, 0x0($s7)
    ctx->r25 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE0F8: lw          $t0, 0x74($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X74));
    // 0x800AE0FC: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE100: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE104: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE108: mflo        $t4
    ctx->r12 = lo;
    // 0x800AE10C: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x800AE110: lh          $t6, 0x8($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X8));
    // 0x800AE114: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE118: mflo        $t7
    ctx->r15 = lo;
    // 0x800AE11C: addu        $s0, $s4, $t7
    ctx->r16 = ADD32(ctx->r20, ctx->r15);
    // 0x800AE120: lw          $t8, 0x4($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800AE124: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800AE128: jal         0x800AD66C
    // 0x800AE12C: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    setanimation(rdram, ctx);
        goto after_11;
    // 0x800AE12C: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_11:
    // 0x800AE130: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE134: jal         0x800AC900
    // 0x800AE138: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_12;
    // 0x800AE138: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_12:
    // 0x800AE13C: b           L_800AE2B8
    // 0x800AE140: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
        goto L_800AE2B8;
    // 0x800AE140: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x800AE144: lw          $t1, 0x4($s3)
    ctx->r9 = S32(MEM_W(ctx->r19, 0X4));
L_800AE148:
    // 0x800AE148: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    // 0x800AE14C: sw          $a3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r7;
    // 0x800AE150: beq         $at, $zero, L_800AE170
    if (ctx->r1 == 0) {
        // 0x800AE154: sw          $t0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r8;
            goto L_800AE170;
    }
    // 0x800AE154: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800AE158: sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6 << 16);
    // 0x800AE15C: sra         $t5, $s2, 16
    ctx->r13 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AE160: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x800AE164: sw          $a2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r6;
    // 0x800AE168: sw          $a3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r7;
    // 0x800AE16C: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
L_800AE170:
    // 0x800AE170: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE174: lh          $t7, 0x8($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X8));
    // 0x800AE178: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE17C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AE180: lw          $a2, 0x80($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800AE184: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE188: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE18C: addu        $s1, $s4, $t6
    ctx->r17 = ADD32(ctx->r20, ctx->r14);
    // 0x800AE190: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800AE194: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE198: lw          $t7, 0x4($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800AE19C: mflo        $t8
    ctx->r24 = lo;
    // 0x800AE1A0: addu        $s0, $s4, $t8
    ctx->r16 = ADD32(ctx->r20, ctx->r24);
    // 0x800AE1A4: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800AE1A8: lw          $t8, 0x4($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800AE1AC: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800AE1B0: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800AE1B4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AE1B8: subu        $v1, $t6, $t2
    ctx->r3 = SUB32(ctx->r14, ctx->r10);
    // 0x800AE1BC: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800AE1C0: beq         $v1, $zero, L_800AE238
    if (ctx->r3 == 0) {
        // 0x800AE1C4: subu        $t0, $t4, $t1
        ctx->r8 = SUB32(ctx->r12, ctx->r9);
            goto L_800AE238;
    }
    // 0x800AE1C4: subu        $t0, $t4, $t1
    ctx->r8 = SUB32(ctx->r12, ctx->r9);
    // 0x800AE1C8: jal         0x800AD66C
    // 0x800AE1CC: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    setanimation(rdram, ctx);
        goto after_13;
    // 0x800AE1CC: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    after_13:
    // 0x800AE1D0: lw          $v1, 0x78($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800AE1D4: lw          $t5, 0x80($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800AE1D8: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE1DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AE1E0: addu        $s0, $t5, $v1
    ctx->r16 = ADD32(ctx->r13, ctx->r3);
    // 0x800AE1E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AE1E8: jal         0x800AD66C
    // 0x800AE1EC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    setanimation(rdram, ctx);
        goto after_14;
    // 0x800AE1EC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_14:
    // 0x800AE1F0: lw          $t6, 0x0($s7)
    ctx->r14 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE1F4: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE1F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AE1FC: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE200: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE204: mflo        $t7
    ctx->r15 = lo;
    // 0x800AE208: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x800AE20C: lh          $t9, 0x8($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X8));
    // 0x800AE210: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE214: mflo        $t4
    ctx->r12 = lo;
    // 0x800AE218: addu        $a1, $s4, $t4
    ctx->r5 = ADD32(ctx->r20, ctx->r12);
    // 0x800AE21C: jal         0x800AD66C
    // 0x800AE220: nop

    setanimation(rdram, ctx);
        goto after_15;
    // 0x800AE220: nop

    after_15:
    // 0x800AE224: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE228: jal         0x800AC900
    // 0x800AE22C: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_16;
    // 0x800AE22C: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_16:
    // 0x800AE230: b           L_800AE2B8
    // 0x800AE234: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
        goto L_800AE2B8;
    // 0x800AE234: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
L_800AE238:
    // 0x800AE238: beq         $t0, $zero, L_800AE2B4
    if (ctx->r8 == 0) {
        // 0x800AE23C: lh          $a0, 0xA2($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
            goto L_800AE2B4;
    }
    // 0x800AE23C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE240: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x800AE244: lw          $a2, 0x7C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800AE248: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE24C: jal         0x800AD66C
    // 0x800AE250: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    setanimation(rdram, ctx);
        goto after_17;
    // 0x800AE250: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    after_17:
    // 0x800AE254: lw          $t0, 0x74($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X74));
    // 0x800AE258: lw          $t5, 0x7C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800AE25C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE260: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800AE264: addu        $s0, $t5, $t0
    ctx->r16 = ADD32(ctx->r13, ctx->r8);
    // 0x800AE268: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AE26C: jal         0x800AD66C
    // 0x800AE270: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    setanimation(rdram, ctx);
        goto after_18;
    // 0x800AE270: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_18:
    // 0x800AE274: lw          $t6, 0x0($s7)
    ctx->r14 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE278: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE27C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800AE280: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE284: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800AE288: mflo        $t7
    ctx->r15 = lo;
    // 0x800AE28C: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x800AE290: lh          $t9, 0x8($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X8));
    // 0x800AE294: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE298: mflo        $t4
    ctx->r12 = lo;
    // 0x800AE29C: addu        $a1, $s4, $t4
    ctx->r5 = ADD32(ctx->r20, ctx->r12);
    // 0x800AE2A0: jal         0x800AD66C
    // 0x800AE2A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    setanimation(rdram, ctx);
        goto after_19;
    // 0x800AE2A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_19:
    // 0x800AE2A8: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE2AC: jal         0x800AC900
    // 0x800AE2B0: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_20;
    // 0x800AE2B0: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_20:
L_800AE2B4:
    // 0x800AE2B4: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
L_800AE2B8:
    // 0x800AE2B8: addiu       $t5, $sp, 0x70
    ctx->r13 = ADD32(ctx->r29, 0X70);
    // 0x800AE2BC: bnel        $s7, $t5, L_800ADF48
    if (ctx->r23 != ctx->r13) {
        // 0x800AE2C0: lw          $v0, 0x0($s7)
        ctx->r2 = S32(MEM_W(ctx->r23, 0X0));
            goto L_800ADF48;
    }
    goto skip_7;
    // 0x800AE2C0: lw          $v0, 0x0($s7)
    ctx->r2 = S32(MEM_W(ctx->r23, 0X0));
    skip_7:
    // 0x800AE2C4: b           L_800AEFD8
    // 0x800AE2C8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE2C8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE2CC:
    // 0x800AE2CC: lh          $t6, 0xA6($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XA6));
    // 0x800AE2D0: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AE2D4: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AE2D8: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE2DC: lh          $t9, 0xA2($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE2E0: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AE2E4: lui         $s2, 0x8027
    ctx->r18 = S32(0X8027 << 16);
    // 0x800AE2E8: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800AE2EC: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x800AE2F0: addu        $s2, $s2, $t4
    ctx->r18 = ADD32(ctx->r18, ctx->r12);
    // 0x800AE2F4: lh          $t4, 0xA2($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE2F8: mflo        $t7
    ctx->r15 = lo;
    // 0x800AE2FC: addu        $a0, $s4, $t7
    ctx->r4 = ADD32(ctx->r20, ctx->r15);
    // 0x800AE300: lh          $t8, 0xE($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0XE));
    // 0x800AE304: bnel        $t8, $at, L_800AEFD8
    if (ctx->r24 != ctx->r1) {
        // 0x800AE308: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800AEFD8;
    }
    goto skip_8;
    // 0x800AE308: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_8:
    // 0x800AE30C: lh          $s2, 0x2330($s2)
    ctx->r18 = S32(MEM_H(ctx->r18, 0X2330));
    // 0x800AE310: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AE314: addiu       $v1, $zero, 0x11
    ctx->r3 = ADD32(0, 0X11);
    // 0x800AE318: bltz        $s2, L_800AE35C
    if (SIGNED(ctx->r18) < 0) {
        // 0x800AE31C: lui         $v0, 0x8027
        ctx->r2 = S32(0X8027 << 16);
            goto L_800AE35C;
    }
    // 0x800AE31C: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800AE320: addiu       $v0, $v0, 0x4FA0
    ctx->r2 = ADD32(ctx->r2, 0X4FA0);
L_800AE324:
    // 0x800AE324: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE328: sll         $t8, $s2, 1
    ctx->r24 = S32(ctx->r18 << 1);
    // 0x800AE32C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800AE330: mflo        $t5
    ctx->r13 = lo;
    // 0x800AE334: addu        $s0, $s4, $t5
    ctx->r16 = ADD32(ctx->r20, ctx->r13);
    // 0x800AE338: lh          $t6, 0xE($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0XE));
    // 0x800AE33C: bnel        $s6, $t6, L_800AE354
    if (ctx->r22 != ctx->r14) {
        // 0x800AE340: lh          $s2, 0x0($t9)
        ctx->r18 = S32(MEM_H(ctx->r25, 0X0));
            goto L_800AE354;
    }
    goto skip_9;
    // 0x800AE340: lh          $s2, 0x0($t9)
    ctx->r18 = S32(MEM_H(ctx->r25, 0X0));
    skip_9:
    // 0x800AE344: lh          $t7, 0x1E($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X1E));
    // 0x800AE348: beql        $v1, $t7, L_800AE360
    if (ctx->r3 == ctx->r15) {
        // 0x800AE34C: lh          $t5, 0x10($a0)
        ctx->r13 = S32(MEM_H(ctx->r4, 0X10));
            goto L_800AE360;
    }
    goto skip_10;
    // 0x800AE34C: lh          $t5, 0x10($a0)
    ctx->r13 = S32(MEM_H(ctx->r4, 0X10));
    skip_10:
    // 0x800AE350: lh          $s2, 0x0($t9)
    ctx->r18 = S32(MEM_H(ctx->r25, 0X0));
L_800AE354:
    // 0x800AE354: bgez        $s2, L_800AE324
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800AE358: nop
    
            goto L_800AE324;
    }
    // 0x800AE358: nop

L_800AE35C:
    // 0x800AE35C: lh          $t5, 0x10($a0)
    ctx->r13 = S32(MEM_H(ctx->r4, 0X10));
L_800AE360:
    // 0x800AE360: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800AE364: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE368: bne         $t4, $t5, L_800AE3CC
    if (ctx->r12 != ctx->r13) {
        // 0x800AE36C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800AE3CC;
    }
    // 0x800AE36C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800AE370: jal         0x800AD9CC
    // 0x800AE374: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    activatewarpelevators(rdram, ctx);
        goto after_21;
    // 0x800AE374: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_21:
    // 0x800AE378: beq         $v0, $zero, L_800AE39C
    if (ctx->r2 == 0) {
        // 0x800AE37C: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_800AE39C;
    }
    // 0x800AE37C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800AE380: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800AE384: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE388: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800AE38C: jal         0x800AD9CC
    // 0x800AE390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    activatewarpelevators(rdram, ctx);
        goto after_22;
    // 0x800AE390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x800AE394: b           L_800AEFD8
    // 0x800AE398: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE398: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE39C:
    // 0x800AE39C: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE3A0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800AE3A4: jal         0x800AD9CC
    // 0x800AE3A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    activatewarpelevators(rdram, ctx);
        goto after_23;
    // 0x800AE3A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x800AE3AC: beq         $v0, $zero, L_800AEFD4
    if (ctx->r2 == 0) {
        // 0x800AE3B0: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_800AEFD4;
    }
    // 0x800AE3B0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800AE3B4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE3B8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800AE3BC: jal         0x800AD9CC
    // 0x800AE3C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    activatewarpelevators(rdram, ctx);
        goto after_24;
    // 0x800AE3C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_24:
    // 0x800AE3C4: b           L_800AEFD8
    // 0x800AE3C8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE3C8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE3CC:
    // 0x800AE3CC: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE3D0: lw          $t7, 0x4($s7)
    ctx->r15 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE3D4: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800AE3D8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE3DC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800AE3E0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800AE3E4: mflo        $t4
    ctx->r12 = lo;
    // 0x800AE3E8: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x800AE3EC: lw          $t6, 0x8($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X8));
    // 0x800AE3F0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AE3F4: beq         $at, $zero, L_800AE414
    if (ctx->r1 == 0) {
        // 0x800AE3F8: nop
    
            goto L_800AE414;
    }
    // 0x800AE3F8: nop

    // 0x800AE3FC: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800AE400: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE404: jal         0x800AD9CC
    // 0x800AE408: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    activatewarpelevators(rdram, ctx);
        goto after_25;
    // 0x800AE408: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_25:
    // 0x800AE40C: b           L_800AEFD8
    // 0x800AE410: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE410: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE414:
    // 0x800AE414: jal         0x800AD9CC
    // 0x800AE418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    activatewarpelevators(rdram, ctx);
        goto after_26;
    // 0x800AE418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x800AE41C: b           L_800AEFD8
    // 0x800AE420: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE420: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE424:
    // 0x800AE424: addiu       $s1, $s7, 0x4
    ctx->r17 = ADD32(ctx->r23, 0X4);
    // 0x800AE428: jal         0x800AD620
    // 0x800AE42C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    getanimationgoal(rdram, ctx);
        goto after_27;
    // 0x800AE42C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x800AE430: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x800AE434: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800AE438: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800AE43C: bne         $s0, $t5, L_800AEFD4
    if (ctx->r16 != ctx->r13) {
        // 0x800AE440: lh          $a0, 0xA2($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
            goto L_800AEFD4;
    }
    // 0x800AE440: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE444: lw          $a1, 0x4($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AE44C: jal         0x80092AA8
    // 0x800AE450: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_28;
    // 0x800AE450: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_28:
    // 0x800AE454: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800AE458: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800AE45C: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AE460: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AE464: bne         $s0, $t8, L_800AE4D0
    if (ctx->r16 != ctx->r24) {
        // 0x800AE468: or          $s2, $t6, $zero
        ctx->r18 = ctx->r14 | 0;
            goto L_800AE4D0;
    }
    // 0x800AE468: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800AE46C: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x800AE470: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800AE474: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800AE478: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE47C: lw          $a1, 0x4($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE480: jal         0x80092AA8
    // 0x800AE484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_29;
    // 0x800AE484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_29:
    // 0x800AE488: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x800AE48C: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800AE490: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800AE494: beq         $s0, $t6, L_800AEFD4
    if (ctx->r16 == ctx->r14) {
        // 0x800AE498: sra         $t4, $s2, 16
        ctx->r12 = S32(SIGNED(ctx->r18) >> 16);
            goto L_800AEFD4;
    }
    // 0x800AE498: sra         $t4, $s2, 16
    ctx->r12 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AE49C: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x800AE4A0: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x800AE4A4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800AE4A8: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800AE4AC: addu        $fp, $fp, $t7
    ctx->r30 = ADD32(ctx->r30, ctx->r15);
    // 0x800AE4B0: lw          $fp, -0x1984($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1984));
    // 0x800AE4B4: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE4B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AE4BC: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    // 0x800AE4C0: jal         0x800AD66C
    // 0x800AE4C4: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    setanimation(rdram, ctx);
        goto after_30;
    // 0x800AE4C4: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_30:
    // 0x800AE4C8: b           L_800AE500
    // 0x800AE4CC: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
        goto L_800AE500;
    // 0x800AE4CC: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
L_800AE4D0:
    // 0x800AE4D0: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x800AE4D4: subu        $t8, $t8, $s2
    ctx->r24 = SUB32(ctx->r24, ctx->r18);
    // 0x800AE4D8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800AE4DC: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800AE4E0: addu        $fp, $fp, $t8
    ctx->r30 = ADD32(ctx->r30, ctx->r24);
    // 0x800AE4E4: lw          $fp, -0x1984($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1984));
    // 0x800AE4E8: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE4EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AE4F0: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    // 0x800AE4F4: jal         0x800AD66C
    // 0x800AE4F8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    setanimation(rdram, ctx);
        goto after_31;
    // 0x800AE4F8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_31:
    // 0x800AE4FC: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
L_800AE500:
    // 0x800AE500: jal         0x800AC900
    // 0x800AE504: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_32;
    // 0x800AE504: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_32:
    // 0x800AE508: b           L_800AEFD8
    // 0x800AE50C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE50C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE510:
    // 0x800AE510: addiu       $s1, $s7, 0x4
    ctx->r17 = ADD32(ctx->r23, 0X4);
    // 0x800AE514: jal         0x800AD620
    // 0x800AE518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    getanimationgoal(rdram, ctx);
        goto after_33;
    // 0x800AE518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x800AE51C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800AE520: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800AE524: sra         $t4, $t9, 16
    ctx->r12 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800AE528: bne         $s0, $t4, L_800AEFD4
    if (ctx->r16 != ctx->r12) {
        // 0x800AE52C: lh          $a0, 0xA2($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
            goto L_800AEFD4;
    }
    // 0x800AE52C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE530: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x800AE534: sra         $t5, $a3, 16
    ctx->r13 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800AE538: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800AE53C: lw          $a1, 0x4($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE540: jal         0x80092AA8
    // 0x800AE544: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_34;
    // 0x800AE544: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_34:
    // 0x800AE548: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800AE54C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x800AE550: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AE554: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800AE558: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800AE55C: bne         $s0, $t7, L_800AE590
    if (ctx->r16 != ctx->r15) {
        // 0x800AE560: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_800AE590;
    }
    // 0x800AE560: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800AE564: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE568: lw          $a1, 0x4($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE56C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AE570: jal         0x80092AA8
    // 0x800AE574: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_35;
    // 0x800AE574: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_35:
    // 0x800AE578: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800AE57C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x800AE580: sra         $t9, $v1, 16
    ctx->r25 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800AE584: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AE588: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800AE58C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800AE590:
    // 0x800AE590: beq         $v1, $s0, L_800AEFD4
    if (ctx->r3 == ctx->r16) {
        // 0x800AE594: sll         $t4, $s2, 2
        ctx->r12 = S32(ctx->r18 << 2);
            goto L_800AEFD4;
    }
    // 0x800AE594: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x800AE598: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    // 0x800AE59C: subu        $t4, $t4, $s2
    ctx->r12 = SUB32(ctx->r12, ctx->r18);
    // 0x800AE5A0: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800AE5A4: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800AE5A8: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x800AE5AC: addu        $fp, $fp, $t4
    ctx->r30 = ADD32(ctx->r30, ctx->r12);
    // 0x800AE5B0: lw          $fp, -0x1984($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1984));
    // 0x800AE5B4: lw          $t7, 0x4($s7)
    ctx->r15 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE5B8: lw          $t6, 0x0($s7)
    ctx->r14 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE5BC: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE5C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AE5C4: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800AE5C8: jal         0x800AD66C
    // 0x800AE5CC: subu        $s3, $t6, $t7
    ctx->r19 = SUB32(ctx->r14, ctx->r15);
    setanimation(rdram, ctx);
        goto after_36;
    // 0x800AE5CC: subu        $s3, $t6, $t7
    ctx->r19 = SUB32(ctx->r14, ctx->r15);
    after_36:
    // 0x800AE5D0: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE5D4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800AE5D8: addu        $a2, $fp, $s3
    ctx->r6 = ADD32(ctx->r30, ctx->r19);
    // 0x800AE5DC: jal         0x800AD66C
    // 0x800AE5E0: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    setanimation(rdram, ctx);
        goto after_37;
    // 0x800AE5E0: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    after_37:
    // 0x800AE5E4: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE5E8: jal         0x800AC900
    // 0x800AE5EC: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_38;
    // 0x800AE5EC: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_38:
    // 0x800AE5F0: b           L_800AEFD8
    // 0x800AE5F4: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE5F4: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE5F8:
    // 0x800AE5F8: andi        $t8, $t0, 0x8000
    ctx->r24 = ctx->r8 & 0X8000;
    // 0x800AE5FC: beq         $t8, $zero, L_800AE634
    if (ctx->r24 == 0) {
        // 0x800AE600: lh          $a0, 0xA2($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
            goto L_800AE634;
    }
    // 0x800AE600: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE604: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE608: lw          $a1, 0x0($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE60C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AE610: jal         0x80092AA8
    // 0x800AE614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_39;
    // 0x800AE614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_39:
    // 0x800AE618: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800AE61C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800AE620: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800AE624: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800AE628: addu        $fp, $fp, $t9
    ctx->r30 = ADD32(ctx->r30, ctx->r25);
    // 0x800AE62C: b           L_800AE65C
    // 0x800AE630: lw          $fp, -0x1984($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1984));
        goto L_800AE65C;
    // 0x800AE630: lw          $fp, -0x1984($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1984));
L_800AE634:
    // 0x800AE634: lw          $a1, 0x0($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE638: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AE63C: jal         0x80092AA8
    // 0x800AE640: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_40;
    // 0x800AE640: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_40:
    // 0x800AE644: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800AE648: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x800AE64C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800AE650: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800AE654: addu        $fp, $fp, $t4
    ctx->r30 = ADD32(ctx->r30, ctx->r12);
    // 0x800AE658: lw          $fp, -0x1988($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1988));
L_800AE65C:
    // 0x800AE65C: lui         $s2, 0x8027
    ctx->r18 = S32(0X8027 << 16);
    // 0x800AE660: lh          $s2, 0x285E($s2)
    ctx->r18 = S32(MEM_H(ctx->r18, 0X285E));
    // 0x800AE664: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AE668: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AE66C: bltz        $s2, L_800AE710
    if (SIGNED(ctx->r18) < 0) {
        // 0x800AE670: or          $a1, $s7, $zero
        ctx->r5 = ctx->r23 | 0;
            goto L_800AE710;
    }
    // 0x800AE670: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800AE674: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AE678: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AE67C: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AE680: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x800AE684: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AE688: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AE68C: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800AE690: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE694: addiu       $v1, $zero, 0x16
    ctx->r3 = ADD32(0, 0X16);
L_800AE698:
    // 0x800AE698: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE69C: mflo        $t5
    ctx->r13 = lo;
    // 0x800AE6A0: addu        $s0, $s4, $t5
    ctx->r16 = ADD32(ctx->r20, ctx->r13);
    // 0x800AE6A4: lh          $t6, 0x1E($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X1E));
    // 0x800AE6A8: bnel        $v1, $t6, L_800AE700
    if (ctx->r3 != ctx->r14) {
        // 0x800AE6AC: sll         $t9, $s2, 1
        ctx->r25 = S32(ctx->r18 << 1);
            goto L_800AE700;
    }
    goto skip_11;
    // 0x800AE6AC: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    skip_11:
    // 0x800AE6B0: lh          $t7, 0x1A($s7)
    ctx->r15 = S32(MEM_H(ctx->r23, 0X1A));
    // 0x800AE6B4: lh          $t8, 0x20($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X20));
    // 0x800AE6B8: bnel        $t7, $t8, L_800AE700
    if (ctx->r15 != ctx->r24) {
        // 0x800AE6BC: sll         $t9, $s2, 1
        ctx->r25 = S32(ctx->r18 << 1);
            goto L_800AE700;
    }
    goto skip_12;
    // 0x800AE6BC: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    skip_12:
    // 0x800AE6C0: multu       $s2, $t0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE6C4: lh          $t9, 0x10($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800AE6C8: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800AE6CC: addiu       $t5, $t5, -0x1988
    ctx->r13 = ADD32(ctx->r13, -0X1988);
    // 0x800AE6D0: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800AE6D4: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x800AE6D8: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800AE6DC: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800AE6E0: lh          $t6, 0x1C($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X1C));
    // 0x800AE6E4: mflo        $t8
    ctx->r24 = lo;
    // 0x800AE6E8: addu        $s1, $a3, $t8
    ctx->r17 = ADD32(ctx->r7, ctx->r24);
    // 0x800AE6EC: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800AE6F0: sh          $t7, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r15;
    // 0x800AE6F4: sw          $a0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r4;
    // 0x800AE6F8: sw          $s6, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r22;
    // 0x800AE6FC: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
L_800AE700:
    // 0x800AE700: addu        $t4, $a2, $t9
    ctx->r12 = ADD32(ctx->r6, ctx->r25);
    // 0x800AE704: lh          $s2, 0x0($t4)
    ctx->r18 = S32(MEM_H(ctx->r12, 0X0));
    // 0x800AE708: bgez        $s2, L_800AE698
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800AE70C: nop
    
            goto L_800AE698;
    }
    // 0x800AE70C: nop

L_800AE710:
    // 0x800AE710: lh          $t5, 0x18($s7)
    ctx->r13 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800AE714: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE718: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800AE71C: xori        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 ^ 0X8000;
    // 0x800AE720: sh          $t6, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r14;
    // 0x800AE724: jal         0x800AD66C
    // 0x800AE728: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    setanimation(rdram, ctx);
        goto after_41;
    // 0x800AE728: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    after_41:
    // 0x800AE72C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE730: jal         0x800AC900
    // 0x800AE734: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_42;
    // 0x800AE734: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_42:
    // 0x800AE738: b           L_800AEFD8
    // 0x800AE73C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE73C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE740:
    // 0x800AE740: lw          $fp, 0x9C($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X9C));
L_800AE744:
    // 0x800AE744: andi        $t7, $t0, 0x8000
    ctx->r15 = ctx->r8 & 0X8000;
    // 0x800AE748: beq         $t7, $zero, L_800AE804
    if (ctx->r15 == 0) {
        // 0x800AE74C: lh          $a0, 0xA2($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
            goto L_800AE804;
    }
    // 0x800AE74C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE750: lh          $t8, 0xA2($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE754: lui         $s2, 0x8027
    ctx->r18 = S32(0X8027 << 16);
    // 0x800AE758: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AE75C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AE760: addu        $s2, $s2, $t9
    ctx->r18 = ADD32(ctx->r18, ctx->r25);
    // 0x800AE764: lh          $s2, 0x2330($s2)
    ctx->r18 = S32(MEM_H(ctx->r18, 0X2330));
    // 0x800AE768: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AE76C: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AE770: bltz        $s2, L_800AE7C4
    if (SIGNED(ctx->r18) < 0) {
        // 0x800AE774: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_800AE7C4;
    }
    // 0x800AE774: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800AE778: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800AE77C: addiu       $v0, $v0, 0x4FA0
    ctx->r2 = ADD32(ctx->r2, 0X4FA0);
    // 0x800AE780: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800AE784:
    // 0x800AE784: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE788: mflo        $t4
    ctx->r12 = lo;
    // 0x800AE78C: addu        $s0, $s4, $t4
    ctx->r16 = ADD32(ctx->r20, ctx->r12);
    // 0x800AE790: lh          $t5, 0x12($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X12));
    // 0x800AE794: bnel        $v1, $t5, L_800AE7B4
    if (ctx->r3 != ctx->r13) {
        // 0x800AE798: sll         $t7, $s2, 1
        ctx->r15 = S32(ctx->r18 << 1);
            goto L_800AE7B4;
    }
    goto skip_13;
    // 0x800AE798: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    skip_13:
    // 0x800AE79C: lh          $t6, 0x1E($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X1E));
    // 0x800AE7A0: bnel        $a0, $t6, L_800AE7B4
    if (ctx->r4 != ctx->r14) {
        // 0x800AE7A4: sll         $t7, $s2, 1
        ctx->r15 = S32(ctx->r18 << 1);
            goto L_800AE7B4;
    }
    goto skip_14;
    // 0x800AE7A4: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    skip_14:
    // 0x800AE7A8: b           L_800AE7C4
    // 0x800AE7AC: lw          $fp, 0x8($s0)
    ctx->r30 = S32(MEM_W(ctx->r16, 0X8));
        goto L_800AE7C4;
    // 0x800AE7AC: lw          $fp, 0x8($s0)
    ctx->r30 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800AE7B0: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
L_800AE7B4:
    // 0x800AE7B4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800AE7B8: lh          $s2, 0x0($t8)
    ctx->r18 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800AE7BC: bgez        $s2, L_800AE784
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800AE7C0: nop
    
            goto L_800AE784;
    }
    // 0x800AE7C0: nop

L_800AE7C4:
    // 0x800AE7C4: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800AE7C8: bnel        $s2, $s0, L_800AE7D8
    if (ctx->r18 != ctx->r16) {
        // 0x800AE7CC: xori        $t9, $t0, 0x8000
        ctx->r25 = ctx->r8 ^ 0X8000;
            goto L_800AE7D8;
    }
    goto skip_15;
    // 0x800AE7CC: xori        $t9, $t0, 0x8000
    ctx->r25 = ctx->r8 ^ 0X8000;
    skip_15:
    // 0x800AE7D0: lw          $fp, 0x4($s7)
    ctx->r30 = S32(MEM_W(ctx->r23, 0X4));
L_800AE7D4:
    // 0x800AE7D4: xori        $t9, $t0, 0x8000
    ctx->r25 = ctx->r8 ^ 0X8000;
L_800AE7D8:
    // 0x800AE7D8: sh          $t9, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r25;
    // 0x800AE7DC: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE7E0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800AE7E4: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800AE7E8: jal         0x800AD66C
    // 0x800AE7EC: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    setanimation(rdram, ctx);
        goto after_43;
    // 0x800AE7EC: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    after_43:
    // 0x800AE7F0: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE7F4: jal         0x800AC900
    // 0x800AE7F8: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_44;
    // 0x800AE7F8: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_44:
    // 0x800AE7FC: b           L_800AEFD8
    // 0x800AE800: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE800: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE804:
    // 0x800AE804: lw          $a1, 0x0($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE808: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AE80C: jal         0x80092AA8
    // 0x800AE810: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_45;
    // 0x800AE810: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_45:
    // 0x800AE814: bltz        $v0, L_800AE83C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AE818: or          $fp, $v0, $zero
        ctx->r30 = ctx->r2 | 0;
            goto L_800AE83C;
    }
    // 0x800AE818: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x800AE81C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800AE820: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x800AE824: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800AE828: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800AE82C: addu        $fp, $fp, $t4
    ctx->r30 = ADD32(ctx->r30, ctx->r12);
    // 0x800AE830: lw          $fp, -0x1988($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1988));
    // 0x800AE834: b           L_800AE7D4
    // 0x800AE838: lh          $t0, 0x18($s7)
    ctx->r8 = S32(MEM_H(ctx->r23, 0X18));
        goto L_800AE7D4;
    // 0x800AE838: lh          $t0, 0x18($s7)
    ctx->r8 = S32(MEM_H(ctx->r23, 0X18));
L_800AE83C:
    // 0x800AE83C: lh          $t5, 0x18($s7)
    ctx->r13 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800AE840: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x800AE844: sh          $t6, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r14;
    // 0x800AE848: b           L_800AE744
    // 0x800AE84C: lh          $t0, 0x18($s7)
    ctx->r8 = S32(MEM_H(ctx->r23, 0X18));
        goto L_800AE744;
    // 0x800AE84C: lh          $t0, 0x18($s7)
    ctx->r8 = S32(MEM_H(ctx->r23, 0X18));
L_800AE850:
    // 0x800AE850: addiu       $s1, $s7, 0x4
    ctx->r17 = ADD32(ctx->r23, 0X4);
    // 0x800AE854: jal         0x800AD620
    // 0x800AE858: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    getanimationgoal(rdram, ctx);
        goto after_46;
    // 0x800AE858: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_46:
    // 0x800AE85C: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800AE860: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x800AE864: sra         $t7, $s2, 16
    ctx->r15 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AE868: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800AE86C: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800AE870: bltz        $t8, L_800AE8E0
    if (SIGNED(ctx->r24) < 0) {
        // 0x800AE874: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800AE8E0;
    }
    // 0x800AE874: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800AE878: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE87C: lui         $s0, 0x802B
    ctx->r16 = S32(0X802B << 16);
    // 0x800AE880: addiu       $s0, $s0, -0x5840
    ctx->r16 = ADD32(ctx->r16, -0X5840);
    // 0x800AE884: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800AE888: addu        $t4, $s0, $t9
    ctx->r12 = ADD32(ctx->r16, ctx->r25);
    // 0x800AE88C: lw          $t5, 0x0($t4)
    ctx->r13 = S32(MEM_W(ctx->r12, 0X0));
    // 0x800AE890: lw          $a1, 0x0($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE894: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AE898: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800AE89C: bnel        $a1, $t5, L_800AE8D8
    if (ctx->r5 != ctx->r13) {
        // 0x800AE8A0: addu        $t5, $s0, $t4
        ctx->r13 = ADD32(ctx->r16, ctx->r12);
            goto L_800AE8D8;
    }
    goto skip_16;
    // 0x800AE8A0: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    skip_16:
    // 0x800AE8A4: jal         0x80092AA8
    // 0x800AE8A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_47;
    // 0x800AE8A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_47:
    // 0x800AE8AC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800AE8B0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800AE8B4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800AE8B8: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800AE8BC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800AE8C0: lw          $t7, -0x1984($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X1984));
    // 0x800AE8C4: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x800AE8C8: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800AE8CC: b           L_800AEFD4
    // 0x800AE8D0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
        goto L_800AEFD4;
    // 0x800AE8D0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800AE8D4: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
L_800AE8D8:
    // 0x800AE8D8: b           L_800AEFD4
    // 0x800AE8DC: sw          $a1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r5;
        goto L_800AEFD4;
    // 0x800AE8DC: sw          $a1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r5;
L_800AE8E0:
    // 0x800AE8E0: lw          $a1, 0x0($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE8E4: lw          $t6, 0x4($s7)
    ctx->r14 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE8E8: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE8EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AE8F0: bnel        $t6, $a1, L_800AE920
    if (ctx->r14 != ctx->r5) {
        // 0x800AE8F4: or          $fp, $a1, $zero
        ctx->r30 = ctx->r5 | 0;
            goto L_800AE920;
    }
    goto skip_17;
    // 0x800AE8F4: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    skip_17:
    // 0x800AE8F8: jal         0x80092AA8
    // 0x800AE8FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_48;
    // 0x800AE8FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_48:
    // 0x800AE900: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800AE904: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800AE908: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800AE90C: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800AE910: addu        $fp, $fp, $t8
    ctx->r30 = ADD32(ctx->r30, ctx->r24);
    // 0x800AE914: b           L_800AE920
    // 0x800AE918: lw          $fp, -0x1984($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1984));
        goto L_800AE920;
    // 0x800AE918: lw          $fp, -0x1984($fp)
    ctx->r30 = S32(MEM_W(ctx->r30, -0X1984));
    // 0x800AE91C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
L_800AE920:
    // 0x800AE920: lh          $t7, 0x18($s7)
    ctx->r15 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800AE924: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AE928: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800AE92C: xori        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 ^ 0X8000;
    // 0x800AE930: sh          $t9, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r25;
    // 0x800AE934: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE938: jal         0x800AD66C
    // 0x800AE93C: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    setanimation(rdram, ctx);
        goto after_49;
    // 0x800AE93C: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    after_49:
    // 0x800AE940: bltz        $v0, L_800AEFD4
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AE944: lh          $a0, 0xA2($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
            goto L_800AEFD4;
    }
    // 0x800AE944: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE948: jal         0x800AC900
    // 0x800AE94C: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_50;
    // 0x800AE94C: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_50:
    // 0x800AE950: b           L_800AEFD8
    // 0x800AE954: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AE954: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AE958:
    // 0x800AE958: andi        $t4, $t0, 0x8000
    ctx->r12 = ctx->r8 & 0X8000;
    // 0x800AE95C: beq         $t4, $zero, L_800AE9A4
    if (ctx->r12 == 0) {
        // 0x800AE960: lh          $a0, 0xA2($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
            goto L_800AE9A4;
    }
    // 0x800AE960: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE964: lw          $t5, 0x0($s7)
    ctx->r13 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE968: lw          $t6, 0x4($s7)
    ctx->r14 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE96C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE970: addiu       $a1, $s7, 0x4
    ctx->r5 = ADD32(ctx->r23, 0X4);
    // 0x800AE974: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800AE978: sra         $a2, $t8, 1
    ctx->r6 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AE97C: sw          $a2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r6;
    // 0x800AE980: jal         0x800AD66C
    // 0x800AE984: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    setanimation(rdram, ctx);
        goto after_51;
    // 0x800AE984: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    after_51:
    // 0x800AE988: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE98C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800AE990: lw          $a2, 0x94($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800AE994: jal         0x800AD66C
    // 0x800AE998: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    setanimation(rdram, ctx);
        goto after_52;
    // 0x800AE998: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    after_52:
    // 0x800AE99C: b           L_800AEA24
    // 0x800AE9A0: lh          $t8, 0x18($s7)
    ctx->r24 = S32(MEM_H(ctx->r23, 0X18));
        goto L_800AEA24;
    // 0x800AE9A0: lh          $t8, 0x18($s7)
    ctx->r24 = S32(MEM_H(ctx->r23, 0X18));
L_800AE9A4:
    // 0x800AE9A4: lw          $a1, 0x4($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800AE9A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AE9AC: jal         0x80092AA8
    // 0x800AE9B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_53;
    // 0x800AE9B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_53:
    // 0x800AE9B4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800AE9B8: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800AE9BC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800AE9C0: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800AE9C4: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x800AE9C8: lw          $a2, -0x1984($t4)
    ctx->r6 = S32(MEM_W(ctx->r12, -0X1984));
    // 0x800AE9CC: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE9D0: addiu       $a1, $s7, 0x4
    ctx->r5 = ADD32(ctx->r23, 0X4);
    // 0x800AE9D4: sw          $a2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r6;
    // 0x800AE9D8: jal         0x800AD66C
    // 0x800AE9DC: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    setanimation(rdram, ctx);
        goto after_54;
    // 0x800AE9DC: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    after_54:
    // 0x800AE9E0: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AE9E4: lw          $a1, 0x0($s7)
    ctx->r5 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800AE9E8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AE9EC: jal         0x80092AA8
    // 0x800AE9F0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    nextsectorneighborz(rdram, ctx);
        goto after_55;
    // 0x800AE9F0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_55:
    // 0x800AE9F4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800AE9F8: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800AE9FC: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800AEA00: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800AEA04: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800AEA08: lw          $a2, -0x1988($t6)
    ctx->r6 = S32(MEM_W(ctx->r14, -0X1988));
    // 0x800AEA0C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AEA10: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800AEA14: sw          $a2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r6;
    // 0x800AEA18: jal         0x800AD66C
    // 0x800AEA1C: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    setanimation(rdram, ctx);
        goto after_56;
    // 0x800AEA1C: lh          $a3, 0x1C($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0X1C));
    after_56:
    // 0x800AEA20: lh          $t8, 0x18($s7)
    ctx->r24 = S32(MEM_H(ctx->r23, 0X18));
L_800AEA24:
    // 0x800AEA24: xori        $t7, $t8, 0x8000
    ctx->r15 = ctx->r24 ^ 0X8000;
    // 0x800AEA28: sh          $t7, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r15;
    // 0x800AEA2C: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    // 0x800AEA30: jal         0x800AC900
    // 0x800AEA34: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    callsound(rdram, ctx);
        goto after_57;
    // 0x800AEA34: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    after_57:
    // 0x800AEA38: b           L_800AEFD8
    // 0x800AEA3C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AEA3C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AEA40:
    // 0x800AEA40: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800AEA44: lh          $v1, 0x285E($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X285E));
    // 0x800AEA48: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x800AEA4C: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x800AEA50: sll         $s2, $v1, 16
    ctx->r18 = S32(ctx->r3 << 16);
    // 0x800AEA54: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AEA58: bltz        $t9, L_800AEAE0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800AEA5C: or          $s2, $t9, $zero
        ctx->r18 = ctx->r25 | 0;
            goto L_800AEAE0;
    }
    // 0x800AEA5C: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800AEA60: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AEA64: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AEA68: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AEA6C: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x800AEA70: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AEA74: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AEA78: addiu       $s7, $zero, 0xB
    ctx->r23 = ADD32(0, 0XB);
    // 0x800AEA7C: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AEA80: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800AEA84: lh          $v0, 0xA2($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0XA2));
L_800AEA88:
    // 0x800AEA88: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEA8C: mflo        $t4
    ctx->r12 = lo;
    // 0x800AEA90: addu        $s0, $s4, $t4
    ctx->r16 = ADD32(ctx->r20, ctx->r12);
    // 0x800AEA94: lh          $t5, 0x1E($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X1E));
    // 0x800AEA98: sll         $t4, $s2, 1
    ctx->r12 = S32(ctx->r18 << 1);
    // 0x800AEA9C: bnel        $s7, $t5, L_800AEAD4
    if (ctx->r23 != ctx->r13) {
        // 0x800AEAA0: addu        $t5, $a2, $t4
        ctx->r13 = ADD32(ctx->r6, ctx->r12);
            goto L_800AEAD4;
    }
    goto skip_18;
    // 0x800AEAA0: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    skip_18:
    // 0x800AEAA4: lh          $t6, 0x10($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800AEAA8: bnel        $v0, $t6, L_800AEAD4
    if (ctx->r2 != ctx->r14) {
        // 0x800AEAAC: addu        $t5, $a2, $t4
        ctx->r13 = ADD32(ctx->r6, ctx->r12);
            goto L_800AEAD4;
    }
    goto skip_19;
    // 0x800AEAAC: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    skip_19:
    // 0x800AEAB0: multu       $s2, $t0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEAB4: mflo        $t8
    ctx->r24 = lo;
    // 0x800AEAB8: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800AEABC: lw          $t9, 0x40($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, 0X40));
    // 0x800AEAC0: bnel        $t9, $zero, L_800AEAD4
    if (ctx->r25 != 0) {
        // 0x800AEAC4: addu        $t5, $a2, $t4
        ctx->r13 = ADD32(ctx->r6, ctx->r12);
            goto L_800AEAD4;
    }
    goto skip_20;
    // 0x800AEAC4: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    skip_20:
    // 0x800AEAC8: b           L_800AEAE0
    // 0x800AEACC: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
        goto L_800AEAE0;
    // 0x800AEACC: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800AEAD0: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
L_800AEAD4:
    // 0x800AEAD4: lh          $s2, 0x0($t5)
    ctx->r18 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800AEAD8: bgez        $s2, L_800AEA88
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800AEADC: nop
    
            goto L_800AEA88;
    }
    // 0x800AEADC: nop

L_800AEAE0:
    // 0x800AEAE0: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AEAE4: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AEAE8: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AEAEC: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AEAF0: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AEAF4: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x800AEAF8: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800AEAFC: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AEB00: bltz        $fp, L_800AEFD4
    if (SIGNED(ctx->r30) < 0) {
        // 0x800AEB04: addiu       $s7, $zero, 0xB
        ctx->r23 = ADD32(0, 0XB);
            goto L_800AEFD4;
    }
    // 0x800AEB04: addiu       $s7, $zero, 0xB
    ctx->r23 = ADD32(0, 0XB);
    // 0x800AEB08: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEB0C: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x800AEB10: sll         $s2, $v1, 16
    ctx->r18 = S32(ctx->r3 << 16);
    // 0x800AEB14: sra         $t5, $s2, 16
    ctx->r13 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AEB18: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x800AEB1C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AEB20: mflo        $t6
    ctx->r14 = lo;
    // 0x800AEB24: addu        $t8, $s4, $t6
    ctx->r24 = ADD32(ctx->r20, ctx->r14);
    // 0x800AEB28: lh          $t7, 0x10($t8)
    ctx->r15 = S32(MEM_H(ctx->r24, 0X10));
    // 0x800AEB2C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800AEB30: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800AEB34: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800AEB38: addu        $s3, $s3, $t9
    ctx->r19 = ADD32(ctx->r19, ctx->r25);
    // 0x800AEB3C: lh          $s3, -0x1970($s3)
    ctx->r19 = S32(MEM_H(ctx->r19, -0X1970));
    // 0x800AEB40: andi        $t4, $s3, 0x8000
    ctx->r12 = ctx->r19 & 0X8000;
    // 0x800AEB44: bltz        $t5, L_800AEFD4
    if (SIGNED(ctx->r13) < 0) {
        // 0x800AEB48: or          $s3, $t4, $zero
        ctx->r19 = ctx->r12 | 0;
            goto L_800AEFD4;
    }
    // 0x800AEB48: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
L_800AEB4C:
    // 0x800AEB4C: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEB50: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800AEB54: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x800AEB58: mflo        $t6
    ctx->r14 = lo;
    // 0x800AEB5C: addu        $s0, $s4, $t6
    ctx->r16 = ADD32(ctx->r20, ctx->r14);
    // 0x800AEB60: lh          $t8, 0x10($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800AEB64: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800AEB68: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x800AEB6C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800AEB70: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x800AEB74: lh          $a0, 0x18($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0X18));
    // 0x800AEB78: andi        $v1, $a0, 0x8000
    ctx->r3 = ctx->r4 & 0X8000;
    // 0x800AEB7C: bnel        $s3, $v1, L_800AEC28
    if (ctx->r19 != ctx->r3) {
        // 0x800AEB80: sll         $t6, $s2, 1
        ctx->r14 = S32(ctx->r18 << 1);
            goto L_800AEC28;
    }
    goto skip_21;
    // 0x800AEB80: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    skip_21:
    // 0x800AEB84: lh          $t4, 0x1E($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X1E));
    // 0x800AEB88: bnel        $s7, $t4, L_800AEC28
    if (ctx->r23 != ctx->r12) {
        // 0x800AEB8C: sll         $t6, $s2, 1
        ctx->r14 = S32(ctx->r18 << 1);
            goto L_800AEC28;
    }
    goto skip_22;
    // 0x800AEB8C: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    skip_22:
    // 0x800AEB90: multu       $fp, $s5
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEB94: lh          $t7, 0x20($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X20));
    // 0x800AEB98: mflo        $t5
    ctx->r13 = lo;
    // 0x800AEB9C: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x800AEBA0: lh          $t8, 0x20($t6)
    ctx->r24 = S32(MEM_H(ctx->r14, 0X20));
    // 0x800AEBA4: bnel        $t8, $t7, L_800AEC28
    if (ctx->r24 != ctx->r15) {
        // 0x800AEBA8: sll         $t6, $s2, 1
        ctx->r14 = S32(ctx->r18 << 1);
            goto L_800AEC28;
    }
    goto skip_23;
    // 0x800AEBA8: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    skip_23:
    // 0x800AEBAC: multu       $s2, $t0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEBB0: mflo        $t9
    ctx->r25 = lo;
    // 0x800AEBB4: addu        $s1, $a3, $t9
    ctx->r17 = ADD32(ctx->r7, ctx->r25);
    // 0x800AEBB8: lw          $t4, 0x40($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X40));
    // 0x800AEBBC: bnel        $t4, $zero, L_800AEC28
    if (ctx->r12 != 0) {
        // 0x800AEBC0: sll         $t6, $s2, 1
        ctx->r14 = S32(ctx->r18 << 1);
            goto L_800AEC28;
    }
    goto skip_24;
    // 0x800AEBC0: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    skip_24:
    // 0x800AEBC4: beq         $v1, $zero, L_800AEBD8
    if (ctx->r3 == 0) {
        // 0x800AEBC8: ori         $t6, $a0, 0x8000
        ctx->r14 = ctx->r4 | 0X8000;
            goto L_800AEBD8;
    }
    // 0x800AEBC8: ori         $t6, $a0, 0x8000
    ctx->r14 = ctx->r4 | 0X8000;
    // 0x800AEBCC: andi        $t5, $a0, 0x7FFF
    ctx->r13 = ctx->r4 & 0X7FFF;
    // 0x800AEBD0: b           L_800AEBDC
    // 0x800AEBD4: sh          $t5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r13;
        goto L_800AEBDC;
    // 0x800AEBD4: sh          $t5, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r13;
L_800AEBD8:
    // 0x800AEBD8: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
L_800AEBDC:
    // 0x800AEBDC: lw          $t8, 0x3C($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X3C));
    // 0x800AEBE0: lw          $t9, 0x94($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800AEBE4: sw          $s6, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r22;
    // 0x800AEBE8: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800AEBEC: bne         $t9, $zero, L_800AEC24
    if (ctx->r25 != 0) {
        // 0x800AEBF0: sw          $t7, 0x3C($s1)
        MEM_W(0X3C, ctx->r17) = ctx->r15;
            goto L_800AEC24;
    }
    // 0x800AEBF0: sw          $t7, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r15;
    // 0x800AEBF4: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800AEBF8: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800AEBFC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AEC00: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    // 0x800AEC04: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800AEC08: jal         0x800AC900
    // 0x800AEC0C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    callsound(rdram, ctx);
        goto after_58;
    // 0x800AEC0C: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    after_58:
    // 0x800AEC10: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AEC14: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AEC18: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AEC1C: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x800AEC20: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
L_800AEC24:
    // 0x800AEC24: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
L_800AEC28:
    // 0x800AEC28: addu        $t8, $a2, $t6
    ctx->r24 = ADD32(ctx->r6, ctx->r14);
    // 0x800AEC2C: lh          $s2, 0x0($t8)
    ctx->r18 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800AEC30: bgez        $s2, L_800AEB4C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800AEC34: nop
    
            goto L_800AEB4C;
    }
    // 0x800AEC34: nop

    // 0x800AEC38: b           L_800AEFD8
    // 0x800AEC3C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AEC3C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AEC40:
    // 0x800AEC40: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800AEC44: lh          $v1, 0x285E($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X285E));
    // 0x800AEC48: addiu       $s7, $zero, 0xF
    ctx->r23 = ADD32(0, 0XF);
    // 0x800AEC4C: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AEC50: bltz        $v1, L_800AECA4
    if (SIGNED(ctx->r3) < 0) {
        // 0x800AEC54: or          $fp, $v1, $zero
        ctx->r30 = ctx->r3 | 0;
            goto L_800AECA4;
    }
    // 0x800AEC54: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
    // 0x800AEC58: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AEC5C: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AEC60: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x800AEC64: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AEC68: lh          $v0, 0xA2($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0XA2));
L_800AEC6C:
    // 0x800AEC6C: multu       $fp, $s5
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEC70: sll         $t5, $fp, 1
    ctx->r13 = S32(ctx->r30 << 1);
    // 0x800AEC74: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x800AEC78: mflo        $t7
    ctx->r15 = lo;
    // 0x800AEC7C: addu        $s3, $s4, $t7
    ctx->r19 = ADD32(ctx->r20, ctx->r15);
    // 0x800AEC80: lh          $t9, 0x1E($s3)
    ctx->r25 = S32(MEM_H(ctx->r19, 0X1E));
    // 0x800AEC84: bnel        $s7, $t9, L_800AEC9C
    if (ctx->r23 != ctx->r25) {
        // 0x800AEC88: lh          $fp, 0x0($t6)
        ctx->r30 = S32(MEM_H(ctx->r14, 0X0));
            goto L_800AEC9C;
    }
    goto skip_25;
    // 0x800AEC88: lh          $fp, 0x0($t6)
    ctx->r30 = S32(MEM_H(ctx->r14, 0X0));
    skip_25:
    // 0x800AEC8C: lh          $t4, 0x10($s3)
    ctx->r12 = S32(MEM_H(ctx->r19, 0X10));
    // 0x800AEC90: beq         $v0, $t4, L_800AECA4
    if (ctx->r2 == ctx->r12) {
        // 0x800AEC94: nop
    
            goto L_800AECA4;
    }
    // 0x800AEC94: nop

    // 0x800AEC98: lh          $fp, 0x0($t6)
    ctx->r30 = S32(MEM_H(ctx->r14, 0X0));
L_800AEC9C:
    // 0x800AEC9C: bgez        $fp, L_800AEC6C
    if (SIGNED(ctx->r30) >= 0) {
        // 0x800AECA0: nop
    
            goto L_800AEC6C;
    }
    // 0x800AECA0: nop

L_800AECA4:
    // 0x800AECA4: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AECA8: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AECAC: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AECB0: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x800AECB4: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AECB8: bltz        $fp, L_800AEFD4
    if (SIGNED(ctx->r30) < 0) {
        // 0x800AECBC: addiu       $s7, $zero, 0xF
        ctx->r23 = ADD32(0, 0XF);
            goto L_800AEFD4;
    }
    // 0x800AECBC: addiu       $s7, $zero, 0xF
    ctx->r23 = ADD32(0, 0XF);
    // 0x800AECC0: sll         $s2, $v1, 16
    ctx->r18 = S32(ctx->r3 << 16);
    // 0x800AECC4: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800AECC8: bltz        $t8, L_800AEFD4
    if (SIGNED(ctx->r24) < 0) {
        // 0x800AECCC: or          $s2, $t8, $zero
        ctx->r18 = ctx->r24 | 0;
            goto L_800AEFD4;
    }
    // 0x800AECCC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800AECD0: sll         $t7, $fp, 2
    ctx->r15 = S32(ctx->r30 << 2);
    // 0x800AECD4: subu        $t7, $t7, $fp
    ctx->r15 = SUB32(ctx->r15, ctx->r30);
    // 0x800AECD8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AECDC: subu        $t7, $t7, $fp
    ctx->r15 = SUB32(ctx->r15, ctx->r30);
    // 0x800AECE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AECE4: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AECE8: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AECEC: addu        $s3, $s4, $t7
    ctx->r19 = ADD32(ctx->r20, ctx->r15);
    // 0x800AECF0: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x800AECF4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AECF8: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
L_800AECFC:
    // 0x800AECFC: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AED00: lh          $t5, 0x20($s3)
    ctx->r13 = S32(MEM_H(ctx->r19, 0X20));
    // 0x800AED04: mflo        $t9
    ctx->r25 = lo;
    // 0x800AED08: addu        $s0, $s4, $t9
    ctx->r16 = ADD32(ctx->r20, ctx->r25);
    // 0x800AED0C: lh          $t4, 0x20($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X20));
    // 0x800AED10: bnel        $t4, $t5, L_800AEDD8
    if (ctx->r12 != ctx->r13) {
        // 0x800AED14: sll         $t9, $s2, 1
        ctx->r25 = S32(ctx->r18 << 1);
            goto L_800AEDD8;
    }
    goto skip_26;
    // 0x800AED14: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    skip_26:
    // 0x800AED18: lh          $t6, 0x1E($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X1E));
    // 0x800AED1C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800AED20: bnel        $s7, $t6, L_800AEDD8
    if (ctx->r23 != ctx->r14) {
        // 0x800AED24: sll         $t9, $s2, 1
        ctx->r25 = S32(ctx->r18 << 1);
            goto L_800AEDD8;
    }
    goto skip_27;
    // 0x800AED24: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    skip_27:
    // 0x800AED28: multu       $s2, $t0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AED2C: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800AED30: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x800AED34: lh          $t5, 0x14($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X14));
    // 0x800AED38: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800AED3C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800AED40: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800AED44: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800AED48: lh          $t9, 0x18($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X18));
    // 0x800AED4C: addiu       $t6, $t5, 0x400
    ctx->r14 = ADD32(ctx->r13, 0X400);
    // 0x800AED50: mflo        $t8
    ctx->r24 = lo;
    // 0x800AED54: addu        $s1, $a3, $t8
    ctx->r17 = ADD32(ctx->r7, ctx->r24);
    // 0x800AED58: lw          $t7, 0x40($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X40));
    // 0x800AED5C: xori        $t4, $t9, 0x8000
    ctx->r12 = ctx->r25 ^ 0X8000;
    // 0x800AED60: sh          $t4, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r12;
    // 0x800AED64: beq         $t7, $zero, L_800AED80
    if (ctx->r15 == 0) {
        // 0x800AED68: sh          $t6, 0x14($s0)
        MEM_H(0X14, ctx->r16) = ctx->r14;
            goto L_800AED80;
    }
    // 0x800AED68: sh          $t6, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r14;
    // 0x800AED6C: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800AED70: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800AED74: jal         0x800AC900
    // 0x800AED78: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    callsound(rdram, ctx);
        goto after_59;
    // 0x800AED78: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_59:
    // 0x800AED7C: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
L_800AED80:
    // 0x800AED80: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800AED84: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800AED88: jal         0x800AC900
    // 0x800AED8C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    callsound(rdram, ctx);
        goto after_60;
    // 0x800AED8C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_60:
    // 0x800AED90: lh          $t5, 0x10($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800AED94: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800AED98: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AED9C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AEDA0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800AEDA4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800AEDA8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800AEDAC: lh          $t8, -0x1970($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X1970));
    // 0x800AEDB0: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AEDB4: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AEDB8: andi        $t7, $t8, 0x8000
    ctx->r15 = ctx->r24 & 0X8000;
    // 0x800AEDBC: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x800AEDC0: beq         $t7, $zero, L_800AEDD0
    if (ctx->r15 == 0) {
        // 0x800AEDC4: addiu       $t0, $zero, 0x48
        ctx->r8 = ADD32(0, 0X48);
            goto L_800AEDD0;
    }
    // 0x800AEDC4: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800AEDC8: b           L_800AEDD4
    // 0x800AEDCC: sw          $s6, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r22;
        goto L_800AEDD4;
    // 0x800AEDCC: sw          $s6, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r22;
L_800AEDD0:
    // 0x800AEDD0: sw          $fp, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r30;
L_800AEDD4:
    // 0x800AEDD4: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
L_800AEDD8:
    // 0x800AEDD8: addu        $t4, $a2, $t9
    ctx->r12 = ADD32(ctx->r6, ctx->r25);
    // 0x800AEDDC: lh          $s2, 0x0($t4)
    ctx->r18 = S32(MEM_H(ctx->r12, 0X0));
    // 0x800AEDE0: bgez        $s2, L_800AECFC
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800AEDE4: nop
    
            goto L_800AECFC;
    }
    // 0x800AEDE4: nop

    // 0x800AEDE8: b           L_800AEFD8
    // 0x800AEDEC: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AEDEC: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AEDF0:
    // 0x800AEDF0: lui         $fp, 0x8027
    ctx->r30 = S32(0X8027 << 16);
    // 0x800AEDF4: lh          $fp, 0x285E($fp)
    ctx->r30 = S32(MEM_H(ctx->r30, 0X285E));
    // 0x800AEDF8: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AEDFC: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AEE00: bltz        $fp, L_800AEFD4
    if (SIGNED(ctx->r30) < 0) {
        // 0x800AEE04: addiu       $s5, $zero, 0x2C
        ctx->r21 = ADD32(0, 0X2C);
            goto L_800AEFD4;
    }
    // 0x800AEE04: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AEE08: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AEE0C: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
    // 0x800AEE10: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AEE14: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_800AEE18:
    // 0x800AEE18: multu       $fp, $s5
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEE1C: mflo        $t5
    ctx->r13 = lo;
    // 0x800AEE20: addu        $s3, $s4, $t5
    ctx->r19 = ADD32(ctx->r20, ctx->r13);
    // 0x800AEE24: lh          $t6, 0x1E($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X1E));
    // 0x800AEE28: sll         $t5, $fp, 1
    ctx->r13 = S32(ctx->r30 << 1);
    // 0x800AEE2C: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800AEE30: bne         $v0, $t8, L_800AEEAC
    if (ctx->r2 != ctx->r24) {
        // 0x800AEE34: addu        $t6, $a2, $t5
        ctx->r14 = ADD32(ctx->r6, ctx->r13);
            goto L_800AEEAC;
    }
    // 0x800AEE34: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x800AEE38: lh          $t7, 0x10($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X10));
    // 0x800AEE3C: bne         $a0, $t7, L_800AEEAC
    if (ctx->r4 != ctx->r15) {
        // 0x800AEE40: xori        $t9, $t0, 0x8000
        ctx->r25 = ctx->r8 ^ 0X8000;
            goto L_800AEEAC;
    }
    // 0x800AEE40: xori        $t9, $t0, 0x8000
    ctx->r25 = ctx->r8 ^ 0X8000;
    // 0x800AEE44: sh          $t9, 0x18($s7)
    MEM_H(0X18, ctx->r23) = ctx->r25;
    // 0x800AEE48: lh          $t4, 0x18($s7)
    ctx->r12 = S32(MEM_H(ctx->r23, 0X18));
    // 0x800AEE4C: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800AEE50: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x800AEE54: beq         $t5, $zero, L_800AEE80
    if (ctx->r13 == 0) {
        // 0x800AEE58: nop
    
            goto L_800AEE80;
    }
    // 0x800AEE58: nop

    // 0x800AEE5C: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800AEE60: multu       $fp, $t0
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEE64: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AEE68: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AEE6C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AEE70: mflo        $t6
    ctx->r14 = lo;
    // 0x800AEE74: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800AEE78: b           L_800AEE9C
    // 0x800AEE7C: sw          $s6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r22;
        goto L_800AEE9C;
    // 0x800AEE7C: sw          $s6, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r22;
L_800AEE80:
    // 0x800AEE80: multu       $fp, $t0
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEE84: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AEE88: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AEE8C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800AEE90: mflo        $t9
    ctx->r25 = lo;
    // 0x800AEE94: addu        $t4, $a3, $t9
    ctx->r12 = ADD32(ctx->r7, ctx->r25);
    // 0x800AEE98: sw          $t7, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r15;
L_800AEE9C:
    // 0x800AEE9C: jal         0x800AC900
    // 0x800AEEA0: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_61;
    // 0x800AEEA0: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_61:
    // 0x800AEEA4: b           L_800AEFD8
    // 0x800AEEA8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AEEA8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AEEAC:
    // 0x800AEEAC: lh          $fp, 0x0($t6)
    ctx->r30 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800AEEB0: bgez        $fp, L_800AEE18
    if (SIGNED(ctx->r30) >= 0) {
        // 0x800AEEB4: nop
    
            goto L_800AEE18;
    }
    // 0x800AEEB4: nop

    // 0x800AEEB8: b           L_800AEFD8
    // 0x800AEEBC: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800AEFD8;
    // 0x800AEEBC: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AEEC0:
    // 0x800AEEC0: lh          $t8, 0xA2($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AEEC4: lui         $fp, 0x8027
    ctx->r30 = S32(0X8027 << 16);
    // 0x800AEEC8: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AEECC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AEED0: addu        $fp, $fp, $t9
    ctx->r30 = ADD32(ctx->r30, ctx->r25);
    // 0x800AEED4: lh          $fp, 0x2330($fp)
    ctx->r30 = S32(MEM_H(ctx->r30, 0X2330));
    // 0x800AEED8: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AEEDC: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800AEEE0: bltz        $fp, L_800AEF30
    if (SIGNED(ctx->r30) < 0) {
        // 0x800AEEE4: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_800AEF30;
    }
    // 0x800AEEE4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800AEEE8: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800AEEEC: addiu       $v0, $v0, 0x4FA0
    ctx->r2 = ADD32(ctx->r2, 0X4FA0);
    // 0x800AEEF0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800AEEF4:
    // 0x800AEEF4: multu       $fp, $s5
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEEF8: sll         $t8, $fp, 1
    ctx->r24 = S32(ctx->r30 << 1);
    // 0x800AEEFC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800AEF00: mflo        $t7
    ctx->r15 = lo;
    // 0x800AEF04: addu        $s3, $s4, $t7
    ctx->r19 = ADD32(ctx->r20, ctx->r15);
    // 0x800AEF08: lh          $t4, 0x12($s3)
    ctx->r12 = S32(MEM_H(ctx->r19, 0X12));
    // 0x800AEF0C: bnel        $v1, $t4, L_800AEF28
    if (ctx->r3 != ctx->r12) {
        // 0x800AEF10: lh          $fp, 0x0($t9)
        ctx->r30 = S32(MEM_H(ctx->r25, 0X0));
            goto L_800AEF28;
    }
    goto skip_28;
    // 0x800AEF10: lh          $fp, 0x0($t9)
    ctx->r30 = S32(MEM_H(ctx->r25, 0X0));
    skip_28:
    // 0x800AEF14: lh          $t5, 0x1E($s3)
    ctx->r13 = S32(MEM_H(ctx->r19, 0X1E));
    // 0x800AEF18: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800AEF1C: beql        $a0, $t6, L_800AEF34
    if (ctx->r4 == ctx->r14) {
        // 0x800AEF20: addiu       $s5, $zero, 0x2C
        ctx->r21 = ADD32(0, 0X2C);
            goto L_800AEF34;
    }
    goto skip_29;
    // 0x800AEF20: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    skip_29:
    // 0x800AEF24: lh          $fp, 0x0($t9)
    ctx->r30 = S32(MEM_H(ctx->r25, 0X0));
L_800AEF28:
    // 0x800AEF28: bgez        $fp, L_800AEEF4
    if (SIGNED(ctx->r30) >= 0) {
        // 0x800AEF2C: nop
    
            goto L_800AEEF4;
    }
    // 0x800AEF2C: nop

L_800AEF30:
    // 0x800AEF30: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
L_800AEF34:
    // 0x800AEF34: multu       $fp, $s5
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEF38: lui         $s3, 0x8027
    ctx->r19 = S32(0X8027 << 16);
    // 0x800AEF3C: lh          $s3, 0x285E($s3)
    ctx->r19 = S32(MEM_H(ctx->r19, 0X285E));
    // 0x800AEF40: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x800AEF44: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x800AEF48: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800AEF4C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800AEF50: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800AEF54: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AEF58: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800AEF5C: mflo        $t7
    ctx->r15 = lo;
    // 0x800AEF60: addu        $t4, $s4, $t7
    ctx->r12 = ADD32(ctx->r20, ctx->r15);
    // 0x800AEF64: bltz        $s3, L_800AEFC8
    if (SIGNED(ctx->r19) < 0) {
        // 0x800AEF68: lh          $fp, 0x20($t4)
        ctx->r30 = S32(MEM_H(ctx->r12, 0X20));
            goto L_800AEFC8;
    }
    // 0x800AEF68: lh          $fp, 0x20($t4)
    ctx->r30 = S32(MEM_H(ctx->r12, 0X20));
    // 0x800AEF6C: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800AEF70: addiu       $a2, $a2, 0x5F40
    ctx->r6 = ADD32(ctx->r6, 0X5F40);
L_800AEF74:
    // 0x800AEF74: multu       $s3, $s5
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEF78: mflo        $t5
    ctx->r13 = lo;
    // 0x800AEF7C: addu        $v0, $s4, $t5
    ctx->r2 = ADD32(ctx->r20, ctx->r13);
    // 0x800AEF80: lh          $t6, 0x1E($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X1E));
    // 0x800AEF84: sll         $t5, $s3, 1
    ctx->r13 = S32(ctx->r19 << 1);
    // 0x800AEF88: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800AEF8C: bne         $a0, $t8, L_800AEFBC
    if (ctx->r4 != ctx->r24) {
        // 0x800AEF90: addu        $t6, $a2, $t5
        ctx->r14 = ADD32(ctx->r6, ctx->r13);
            goto L_800AEFBC;
    }
    // 0x800AEF90: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x800AEF94: multu       $s3, $t0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AEF98: mflo        $t9
    ctx->r25 = lo;
    // 0x800AEF9C: addu        $v1, $a3, $t9
    ctx->r3 = ADD32(ctx->r7, ctx->r25);
    // 0x800AEFA0: lw          $t7, 0x30($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X30));
    // 0x800AEFA4: bnel        $t7, $zero, L_800AEFC0
    if (ctx->r15 != 0) {
        // 0x800AEFA8: lh          $s3, 0x0($t6)
        ctx->r19 = S32(MEM_H(ctx->r14, 0X0));
            goto L_800AEFC0;
    }
    goto skip_30;
    // 0x800AEFA8: lh          $s3, 0x0($t6)
    ctx->r19 = S32(MEM_H(ctx->r14, 0X0));
    skip_30:
    // 0x800AEFAC: lh          $t4, 0x20($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X20));
    // 0x800AEFB0: bnel        $fp, $t4, L_800AEFC0
    if (ctx->r30 != ctx->r12) {
        // 0x800AEFB4: lh          $s3, 0x0($t6)
        ctx->r19 = S32(MEM_H(ctx->r14, 0X0));
            goto L_800AEFC0;
    }
    goto skip_31;
    // 0x800AEFB4: lh          $s3, 0x0($t6)
    ctx->r19 = S32(MEM_H(ctx->r14, 0X0));
    skip_31:
    // 0x800AEFB8: sw          $s6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r22;
L_800AEFBC:
    // 0x800AEFBC: lh          $s3, 0x0($t6)
    ctx->r19 = S32(MEM_H(ctx->r14, 0X0));
L_800AEFC0:
    // 0x800AEFC0: bgez        $s3, L_800AEF74
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800AEFC4: nop
    
            goto L_800AEF74;
    }
    // 0x800AEFC4: nop

L_800AEFC8:
    // 0x800AEFC8: lh          $a0, 0xA2($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XA2));
    // 0x800AEFCC: jal         0x800AC900
    // 0x800AEFD0: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    callsound(rdram, ctx);
        goto after_62;
    // 0x800AEFD0: lh          $a1, 0xA6($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XA6));
    after_62:
L_800AEFD4:
    // 0x800AEFD4: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800AEFD8:
    // 0x800AEFD8: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800AEFDC: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800AEFE0: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800AEFE4: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AEFE8: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800AEFEC: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800AEFF0: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800AEFF4: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800AEFF8: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800AEFFC: jr          $ra
    // 0x800AF000: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800AF000: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80063880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063880: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063884: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063888: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x8006388C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80063890: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80063894: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80063898: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006389C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800638A0: addiu       $t8, $t8, -0x5010
    ctx->r24 = ADD32(ctx->r24, -0X5010);
    // 0x800638A4: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x800638A8: lw          $v1, 0x4($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800638AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800638B0: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x800638B4: beq         $v1, $zero, L_800638D0
    if (ctx->r3 == 0) {
        // 0x800638B8: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_800638D0;
    }
    // 0x800638B8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x800638BC: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x800638C0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800638C4: sb          $t9, -0xC68($at)
    MEM_B(-0XC68, ctx->r1) = ctx->r25;
    // 0x800638C8: b           L_800639F4
    // 0x800638CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800639F4;
    // 0x800638CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800638D0:
    // 0x800638D0: lbu         $t0, 0x16($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X16);
    // 0x800638D4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800638D8: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x800638DC: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x800638E0: bne         $t1, $at, L_80063904
    if (ctx->r9 != ctx->r1) {
        // 0x800638E4: lui         $t0, 0x8026
        ctx->r8 = S32(0X8026 << 16);
            goto L_80063904;
    }
    // 0x800638E4: lui         $t0, 0x8026
    ctx->r8 = S32(0X8026 << 16);
    // 0x800638E8: lhu         $t2, 0x14($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X14);
    // 0x800638EC: lhu         $t3, 0x12($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X12);
    // 0x800638F0: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800638F4: mflo        $a3
    ctx->r7 = lo;
    // 0x800638F8: andi        $t4, $a3, 0xFFFF
    ctx->r12 = ctx->r7 & 0XFFFF;
    // 0x800638FC: b           L_80063930
    // 0x80063900: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
        goto L_80063930;
    // 0x80063900: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
L_80063904:
    // 0x80063904: lhu         $t5, 0x14($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X14);
    // 0x80063908: lhu         $t7, 0x12($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X12);
    // 0x8006390C: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063910: mflo        $a3
    ctx->r7 = lo;
    // 0x80063914: bgez        $a3, L_80063924
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80063918: sra         $t8, $a3, 1
        ctx->r24 = S32(SIGNED(ctx->r7) >> 1);
            goto L_80063924;
    }
    // 0x80063918: sra         $t8, $a3, 1
    ctx->r24 = S32(SIGNED(ctx->r7) >> 1);
    // 0x8006391C: addiu       $at, $a3, 0x1
    ctx->r1 = ADD32(ctx->r7, 0X1);
    // 0x80063920: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80063924:
    // 0x80063924: addiu       $a3, $t8, 0x20
    ctx->r7 = ADD32(ctx->r24, 0X20);
    // 0x80063928: andi        $t9, $a3, 0xFFFF
    ctx->r25 = ctx->r7 & 0XFFFF;
    // 0x8006392C: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
L_80063930:
    // 0x80063930: addiu       $t0, $t0, -0xC68
    ctx->r8 = ADD32(ctx->r8, -0XC68);
    // 0x80063934: addu        $a2, $t6, $t0
    ctx->r6 = ADD32(ctx->r14, ctx->r8);
    // 0x80063938: addiu       $t1, $zero, 0x82
    ctx->r9 = ADD32(0, 0X82);
    // 0x8006393C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80063940: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x80063944: jal         0x80071F44
    // 0x80063948: sh          $a3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r7;
    allocache2(rdram, ctx);
        goto after_0;
    // 0x80063948: sh          $a3, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006394C: lhu         $a2, 0x10($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X10);
    // 0x80063950: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80063954: lw          $a1, -0x6514($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X6514));
    // 0x80063958: lw          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006395C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80063960: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80063964: and         $t3, $a2, $at
    ctx->r11 = ctx->r6 & ctx->r1;
    // 0x80063968: lui         $a0, 0x8026
    ctx->r4 = S32(0X8026 << 16);
    // 0x8006396C: addiu       $a0, $a0, -0x140
    ctx->r4 = ADD32(ctx->r4, -0X140);
    // 0x80063970: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80063974: jal         0x8004B560
    // 0x80063978: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    copyfromrom(rdram, ctx);
        goto after_1;
    // 0x80063978: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    after_1:
    // 0x8006397C: lui         $a0, 0x8026
    ctx->r4 = S32(0X8026 << 16);
    // 0x80063980: addiu       $a0, $a0, -0x140
    ctx->r4 = ADD32(ctx->r4, -0X140);
    // 0x80063984: jal         0x80070BAC
    // 0x80063988: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    RNCDecompress(rdram, ctx);
        goto after_2;
    // 0x80063988: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    after_2:
    // 0x8006398C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80063990: bne         $v0, $at, L_800639AC
    if (ctx->r2 != ctx->r1) {
        // 0x80063994: lhu         $a3, 0x24($sp)
        ctx->r7 = MEM_HU(ctx->r29, 0X24);
            goto L_800639AC;
    }
    // 0x80063994: lhu         $a3, 0x24($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X24);
    // 0x80063998: lui         $a1, 0x8026
    ctx->r5 = S32(0X8026 << 16);
    // 0x8006399C: addiu       $a1, $a1, -0x140
    ctx->r5 = ADD32(ctx->r5, -0X140);
    // 0x800639A0: lw          $a0, 0x4($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800639A4: jal         0x8005A490
    // 0x800639A8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    fastmemcpy(rdram, ctx);
        goto after_3;
    // 0x800639A8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_3:
L_800639AC:
    // 0x800639AC: lbu         $t4, 0x16($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X16);
    // 0x800639B0: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800639B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800639B8: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800639BC: beql        $t5, $at, L_800639F4
    if (ctx->r13 == ctx->r1) {
        // 0x800639C0: lw          $v0, 0x4($s0)
        ctx->r2 = S32(MEM_W(ctx->r16, 0X4));
            goto L_800639F4;
    }
    goto skip_0;
    // 0x800639C0: lw          $v0, 0x4($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X4));
    skip_0:
    // 0x800639C4: lw          $v0, 0x4($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X4));
L_800639C8:
    // 0x800639C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800639CC: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800639D0: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x800639D4: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800639D8: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x800639DC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800639E0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800639E4: sb          $v1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r3;
    // 0x800639E8: bne         $at, $zero, L_800639C8
    if (ctx->r1 != 0) {
        // 0x800639EC: sb          $t7, -0x2($v0)
        MEM_B(-0X2, ctx->r2) = ctx->r15;
            goto L_800639C8;
    }
    // 0x800639EC: sb          $t7, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r15;
    // 0x800639F0: lw          $v0, 0x4($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X4));
L_800639F4:
    // 0x800639F4: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800639F8: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800639FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063A00: jr          $ra
    // 0x80063A04: nop

    return;
    // 0x80063A04: nop

;}
RECOMP_FUNC void func_8004CF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CF80: jr          $ra
    // 0x8004CF84: nop

    return;
    // 0x8004CF84: nop

;}
RECOMP_FUNC void alSynSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA1A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA1A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA1A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CA1AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CA1B0: lw          $t6, 0x8($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X8));
    // 0x800CA1B4: beql        $t6, $zero, L_800CA218
    if (ctx->r14 == 0) {
        // 0x800CA1B8: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CA218;
    }
    goto skip_0;
    // 0x800CA1B8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800CA1BC: jal         0x800C2570
    // 0x800CA1C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800CA1C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CA1C4: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CA1C8: beq         $v0, $zero, L_800CA214
    if (ctx->r2 == 0) {
        // 0x800CA1CC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800CA214;
    }
    // 0x800CA1CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CA1D0: lw          $t7, 0x18($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800CA1D4: lw          $t9, 0x8($a3)
    ctx->r25 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA1D8: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800CA1DC: lw          $t8, 0x1C($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X1C));
    // 0x800CA1E0: lw          $t0, 0xD8($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0XD8));
    // 0x800CA1E4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800CA1E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800CA1EC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800CA1F0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800CA1F4: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x800CA1F8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800CA1FC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800CA200: lw          $t4, 0x8($a3)
    ctx->r12 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA204: lw          $a0, 0xC($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0XC));
    // 0x800CA208: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CA20C: jalr        $t9
    // 0x800CA210: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CA210: nop

    after_1:
L_800CA214:
    // 0x800CA214: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CA218:
    // 0x800CA218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA21C: jr          $ra
    // 0x800CA220: nop

    return;
    // 0x800CA220: nop

;}
RECOMP_FUNC void mulscale22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FEF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FF00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FF04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FF08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FF0C: jal         0x800BB8F8
    // 0x8008FF10: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FF10: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FF14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FF18: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FF1C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FF20: jal         0x800BBA24
    // 0x8008FF24: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FF24: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    after_1:
    // 0x8008FF28: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FF2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FF30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FF34: jr          $ra
    // 0x8008FF38: nop

    return;
    // 0x8008FF38: nop

;}
RECOMP_FUNC void mulscale23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FF3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FF40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FF44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FF48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FF4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FF50: jal         0x800BB8F8
    // 0x8008FF54: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FF54: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FF58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FF5C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FF60: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FF64: jal         0x800BBA24
    // 0x8008FF68: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FF68: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    after_1:
    // 0x8008FF6C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FF70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FF74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FF78: jr          $ra
    // 0x8008FF7C: nop

    return;
    // 0x8008FF7C: nop

;}
RECOMP_FUNC void fastmemcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A494: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8005A498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A49C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8005A4A0: beq         $t6, $zero, L_8005A4B8
    if (ctx->r14 == 0) {
        // 0x8005A4A4: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8005A4B8;
    }
    // 0x8005A4A4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8005A4A8: jal         0x8005A464
    // 0x8005A4AC: nop

    _memcpy(rdram, ctx);
        goto after_0;
    // 0x8005A4AC: nop

    after_0:
    // 0x8005A4B0: b           L_8005A510
    // 0x8005A4B4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8005A510;
    // 0x8005A4B4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8005A4B8:
    // 0x8005A4B8: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x8005A4BC: beq         $t7, $zero, L_8005A4D4
    if (ctx->r15 == 0) {
        // 0x8005A4C0: andi        $t8, $a2, 0x3
        ctx->r24 = ctx->r6 & 0X3;
            goto L_8005A4D4;
    }
    // 0x8005A4C0: andi        $t8, $a2, 0x3
    ctx->r24 = ctx->r6 & 0X3;
    // 0x8005A4C4: jal         0x8005A464
    // 0x8005A4C8: nop

    _memcpy(rdram, ctx);
        goto after_1;
    // 0x8005A4C8: nop

    after_1:
    // 0x8005A4CC: b           L_8005A510
    // 0x8005A4D0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8005A510;
    // 0x8005A4D0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8005A4D4:
    // 0x8005A4D4: beq         $t8, $zero, L_8005A4EC
    if (ctx->r24 == 0) {
        // 0x8005A4D8: srl         $t9, $a2, 2
        ctx->r25 = S32(U32(ctx->r6) >> 2);
            goto L_8005A4EC;
    }
    // 0x8005A4D8: srl         $t9, $a2, 2
    ctx->r25 = S32(U32(ctx->r6) >> 2);
    // 0x8005A4DC: jal         0x8005A464
    // 0x8005A4E0: nop

    _memcpy(rdram, ctx);
        goto after_2;
    // 0x8005A4E0: nop

    after_2:
    // 0x8005A4E4: b           L_8005A510
    // 0x8005A4E8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8005A510;
    // 0x8005A4E8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8005A4EC:
    // 0x8005A4EC: beq         $t9, $zero, L_8005A50C
    if (ctx->r25 == 0) {
        // 0x8005A4F0: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_8005A50C;
    }
    // 0x8005A4F0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8005A4F4:
    // 0x8005A4F4: lw          $t0, 0x0($v1)
    ctx->r8 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8005A4F8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8005A4FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005A500: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005A504: bne         $a2, $zero, L_8005A4F4
    if (ctx->r6 != 0) {
        // 0x8005A508: sw          $t0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r8;
            goto L_8005A4F4;
    }
    // 0x8005A508: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
L_8005A50C:
    // 0x8005A50C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8005A510:
    // 0x8005A510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A514: jr          $ra
    // 0x8005A518: nop

    return;
    // 0x8005A518: nop

;}
RECOMP_FUNC void setinterpolation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800753A8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800753AC: addiu       $a2, $a2, 0x1390
    ctx->r6 = ADD32(ctx->r6, 0X1390);
    // 0x800753B0: lw          $v0, 0x0($a2)
    ctx->r2 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800753B4: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x800753B8: beq         $at, $zero, L_80075420
    if (ctx->r1 == 0) {
        // 0x800753BC: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_80075420;
    }
    // 0x800753BC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800753C0: bltz        $v1, L_800753F8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800753C4: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_800753F8;
    }
    // 0x800753C4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800753C8: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800753CC: addiu       $t7, $t7, -0x7A60
    ctx->r15 = ADD32(ctx->r15, -0X7A60);
    // 0x800753D0: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x800753D4: addiu       $v1, $v1, -0x7A60
    ctx->r3 = ADD32(ctx->r3, -0X7A60);
    // 0x800753D8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800753DC: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
L_800753E0:
    // 0x800753E0: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800753E4: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800753E8: beq         $a0, $t8, L_80075420
    if (ctx->r4 == ctx->r24) {
        // 0x800753EC: nop
    
            goto L_80075420;
    }
    // 0x800753EC: nop

    // 0x800753F0: beql        $at, $zero, L_800753E0
    if (ctx->r1 == 0) {
        // 0x800753F4: lw          $t8, 0x0($a1)
        ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
            goto L_800753E0;
    }
    goto skip_0;
    // 0x800753F4: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    skip_0:
L_800753F8:
    // 0x800753F8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800753FC: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x80075400: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80075404: sw          $a0, -0x7A60($at)
    MEM_W(-0X7A60, ctx->r1) = ctx->r4;
    // 0x80075408: lw          $t9, 0x0($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8007540C: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x80075410: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80075414: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80075418: sw          $t9, 0x65A0($at)
    MEM_W(0X65A0, ctx->r1) = ctx->r25;
    // 0x8007541C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_80075420:
    // 0x80075420: jr          $ra
    // 0x80075424: nop

    return;
    // 0x80075424: nop

;}
RECOMP_FUNC void func_800706B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800706B8: addiu       $t6, $a0, 0x12
    ctx->r14 = ADD32(ctx->r4, 0X12);
    // 0x800706BC: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800706C0: sw          $t6, -0x133C($at)
    MEM_W(-0X133C, ctx->r1) = ctx->r14;
    // 0x800706C4: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800706C8: sw          $a1, -0x1338($at)
    MEM_W(-0X1338, ctx->r1) = ctx->r5;
    // 0x800706CC: lbu         $t8, 0x4($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4);
    // 0x800706D0: lbu         $t1, 0x5($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X5);
    // 0x800706D4: lbu         $t7, 0x7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7);
    // 0x800706D8: lbu         $t4, 0x6($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X6);
    // 0x800706DC: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800706E0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x800706E4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x800706E8: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x800706EC: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800706F0: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x800706F4: addu        $t8, $t6, $a1
    ctx->r24 = ADD32(ctx->r14, ctx->r5);
    // 0x800706F8: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800706FC: sw          $t8, -0x1334($at)
    MEM_W(-0X1334, ctx->r1) = ctx->r24;
    // 0x80070700: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80070704: jr          $ra
    // 0x80070708: sb          $zero, -0x133F($at)
    MEM_B(-0X133F, ctx->r1) = 0;
    return;
    // 0x80070708: sb          $zero, -0x133F($at)
    MEM_B(-0X133F, ctx->r1) = 0;
;}
RECOMP_FUNC void BUTTON(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2684: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800A2688: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x800A268C: beq         $v0, $zero, L_800A26B0
    if (ctx->r2 == 0) {
        // 0x800A2690: lui         $t6, 0x8028
        ctx->r14 = S32(0X8028 << 16);
            goto L_800A26B0;
    }
    // 0x800A2690: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x800A2694: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800A2698: beq         $v0, $at, L_800A2710
    if (ctx->r2 == ctx->r1) {
        // 0x800A269C: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_800A2710;
    }
    // 0x800A269C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800A26A0: beq         $v0, $at, L_800A26D4
    if (ctx->r2 == ctx->r1) {
        // 0x800A26A4: nop
    
            goto L_800A26D4;
    }
    // 0x800A26A4: nop

    // 0x800A26A8: b           L_800A274C
    // 0x800A26AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A274C;
    // 0x800A26AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A26B0:
    // 0x800A26B0: lhu         $t6, -0x689A($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X689A);
    // 0x800A26B4: and         $t7, $t6, $a0
    ctx->r15 = ctx->r14 & ctx->r4;
    // 0x800A26B8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800A26BC: beq         $t8, $zero, L_800A26CC
    if (ctx->r24 == 0) {
        // 0x800A26C0: nop
    
            goto L_800A26CC;
    }
    // 0x800A26C0: nop

    // 0x800A26C4: jr          $ra
    // 0x800A26C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800A26C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A26CC:
    // 0x800A26CC: jr          $ra
    // 0x800A26D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A26D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A26D4:
    // 0x800A26D4: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800A26D8: lhu         $v0, -0x689A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X689A);
    // 0x800A26DC: lui         $t1, 0x8028
    ctx->r9 = S32(0X8028 << 16);
    // 0x800A26E0: and         $t9, $v0, $a0
    ctx->r25 = ctx->r2 & ctx->r4;
    // 0x800A26E4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x800A26E8: beq         $t0, $zero, L_800A2708
    if (ctx->r8 == 0) {
        // 0x800A26EC: nop
    
            goto L_800A2708;
    }
    // 0x800A26EC: nop

    // 0x800A26F0: lhu         $t1, -0x6898($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X6898);
    // 0x800A26F4: and         $t2, $v0, $t1
    ctx->r10 = ctx->r2 & ctx->r9;
    // 0x800A26F8: bne         $t2, $zero, L_800A2708
    if (ctx->r10 != 0) {
        // 0x800A26FC: nop
    
            goto L_800A2708;
    }
    // 0x800A26FC: nop

    // 0x800A2700: jr          $ra
    // 0x800A2704: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800A2704: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A2708:
    // 0x800A2708: jr          $ra
    // 0x800A270C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A270C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A2710:
    // 0x800A2710: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800A2714: lhu         $v0, -0x689A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X689A);
    // 0x800A2718: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x800A271C: and         $t3, $v0, $a0
    ctx->r11 = ctx->r2 & ctx->r4;
    // 0x800A2720: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800A2724: beq         $t4, $zero, L_800A2744
    if (ctx->r12 == 0) {
        // 0x800A2728: nop
    
            goto L_800A2744;
    }
    // 0x800A2728: nop

    // 0x800A272C: lhu         $t5, -0x6898($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X6898);
    // 0x800A2730: and         $t6, $v0, $t5
    ctx->r14 = ctx->r2 & ctx->r13;
    // 0x800A2734: beq         $t6, $zero, L_800A2744
    if (ctx->r14 == 0) {
        // 0x800A2738: nop
    
            goto L_800A2744;
    }
    // 0x800A2738: nop

    // 0x800A273C: jr          $ra
    // 0x800A2740: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800A2740: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A2744:
    // 0x800A2744: jr          $ra
    // 0x800A2748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A2748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A274C:
    // 0x800A274C: jr          $ra
    // 0x800A2750: nop

    return;
    // 0x800A2750: nop

;}
RECOMP_FUNC void alInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF7FC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800BF800: addiu       $v0, $v0, 0x2140
    ctx->r2 = ADD32(ctx->r2, 0X2140);
    // 0x800BF804: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800BF808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF80C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF810: bnel        $t6, $zero, L_800BF824
    if (ctx->r14 != 0) {
        // 0x800BF814: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800BF824;
    }
    goto skip_0;
    // 0x800BF814: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800BF818: jal         0x800C2840
    // 0x800BF81C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    alSynNew(rdram, ctx);
        goto after_0;
    // 0x800BF81C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x800BF820: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800BF824:
    // 0x800BF824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF828: jr          $ra
    // 0x800BF82C: nop

    return;
    // 0x800BF82C: nop

;}
RECOMP_FUNC void checkplayerhurt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1190: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B1194: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B1198: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x800B119C: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800B11A0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B11A4: andi        $v0, $t6, 0xC000
    ctx->r2 = ctx->r14 & 0XC000;
    // 0x800B11A8: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x800B11AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B11B0: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800B11B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B11B8: bne         $v0, $at, L_800B1268
    if (ctx->r2 != ctx->r1) {
        // 0x800B11BC: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_800B1268;
    }
    // 0x800B11BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B11C0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B11C4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B11C8: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800B11CC: slti        $at, $s1, 0x7D0
    ctx->r1 = SIGNED(ctx->r17) < 0X7D0 ? 1 : 0;
    // 0x800B11D0: bne         $at, $zero, L_800B11E0
    if (ctx->r1 != 0) {
        // 0x800B11D4: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800B11E0;
    }
    // 0x800B11D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B11D8: jal         0x80099460
    // 0x800B11DC: addiu       $a0, $a0, -0x7AF0
    ctx->r4 = ADD32(ctx->r4, -0X7AF0);
    gameexit(rdram, ctx);
        goto after_0;
    // 0x800B11DC: addiu       $a0, $a0, -0x7AF0
    ctx->r4 = ADD32(ctx->r4, -0X7AF0);
    after_0:
L_800B11E0:
    // 0x800B11E0: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x800B11E4: multu       $s1, $a3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B11E8: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x800B11EC: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x800B11F0: addiu       $at, $zero, 0x38F
    ctx->r1 = ADD32(0, 0X38F);
    // 0x800B11F4: mflo        $t1
    ctx->r9 = lo;
    // 0x800B11F8: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x800B11FC: lh          $t3, 0xE($t2)
    ctx->r11 = S32(MEM_H(ctx->r10, 0XE));
    // 0x800B1200: bnel        $t3, $at, L_800B146C
    if (ctx->r11 != ctx->r1) {
        // 0x800B1204: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800B146C;
    }
    goto skip_0;
    // 0x800B1204: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_0:
    // 0x800B1208: lh          $t4, 0x2C0($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X2C0));
    // 0x800B120C: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800B1210: beql        $at, $zero, L_800B146C
    if (ctx->r1 == 0) {
        // 0x800B1214: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800B146C;
    }
    goto skip_1;
    // 0x800B1214: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_1:
    // 0x800B1218: lh          $t5, 0x2E0($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B121C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800B1220: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800B1224: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1228: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800B122C: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // 0x800B1230: mflo        $t6
    ctx->r14 = lo;
    // 0x800B1234: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x800B1238: lh          $t7, 0x22($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X22));
    // 0x800B123C: addiu       $t8, $t7, -0x5
    ctx->r24 = ADD32(ctx->r15, -0X5);
    // 0x800B1240: sh          $t8, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r24;
    // 0x800B1244: sh          $t9, 0x2C0($s0)
    MEM_H(0X2C0, ctx->r16) = ctx->r25;
    // 0x800B1248: sw          $t1, 0x274($s0)
    MEM_W(0X274, ctx->r16) = ctx->r9;
    // 0x800B124C: sb          $t2, 0x367($s0)
    MEM_B(0X367, ctx->r16) = ctx->r10;
    // 0x800B1250: sb          $zero, 0x368($s0)
    MEM_B(0X368, ctx->r16) = 0;
    // 0x800B1254: sb          $zero, 0x369($s0)
    MEM_B(0X369, ctx->r16) = 0;
    // 0x800B1258: jal         0x80059034
    // 0x800B125C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_1;
    // 0x800B125C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_1:
    // 0x800B1260: b           L_800B146C
    // 0x800B1264: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800B146C;
    // 0x800B1264: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800B1268:
    // 0x800B1268: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800B126C: bnel        $v0, $at, L_800B146C
    if (ctx->r2 != ctx->r1) {
        // 0x800B1270: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800B146C;
    }
    goto skip_2;
    // 0x800B1270: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_2:
    // 0x800B1274: lh          $v0, 0x2C0($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X2C0));
    // 0x800B1278: andi        $t3, $s1, 0x1FFF
    ctx->r11 = ctx->r17 & 0X1FFF;
    // 0x800B127C: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B1280: blez        $v0, L_800B1294
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B1284: sra         $s1, $t4, 16
        ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
            goto L_800B1294;
    }
    // 0x800B1284: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800B1288: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800B128C: b           L_800B1468
    // 0x800B1290: sh          $t6, 0x2C0($s0)
    MEM_H(0X2C0, ctx->r16) = ctx->r14;
        goto L_800B1468;
    // 0x800B1290: sh          $t6, 0x2C0($s0)
    MEM_H(0X2C0, ctx->r16) = ctx->r14;
L_800B1294:
    // 0x800B1294: sll         $t7, $s1, 3
    ctx->r15 = S32(ctx->r17 << 3);
    // 0x800B1298: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800B129C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B12A0: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x800B12A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B12A8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800B12AC: lh          $t9, 0xE($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0XE));
    // 0x800B12B0: andi        $t1, $t9, 0x55
    ctx->r9 = ctx->r25 & 0X55;
    // 0x800B12B4: beql        $t1, $zero, L_800B146C
    if (ctx->r9 == 0) {
        // 0x800B12B8: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800B146C;
    }
    goto skip_3;
    // 0x800B12B8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_3:
    // 0x800B12BC: lh          $v0, 0x12($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X12));
    // 0x800B12C0: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x800B12C4: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x800B12C8: beq         $v0, $at, L_800B13FC
    if (ctx->r2 == ctx->r1) {
        // 0x800B12CC: addiu       $t0, $t0, -0x9A0
        ctx->r8 = ADD32(ctx->r8, -0X9A0);
            goto L_800B13FC;
    }
    // 0x800B12CC: addiu       $t0, $t0, -0x9A0
    ctx->r8 = ADD32(ctx->r8, -0X9A0);
    // 0x800B12D0: addiu       $at, $zero, 0x297
    ctx->r1 = ADD32(0, 0X297);
    // 0x800B12D4: beq         $v0, $at, L_800B12EC
    if (ctx->r2 == ctx->r1) {
        // 0x800B12D8: addiu       $at, $zero, 0x298
        ctx->r1 = ADD32(0, 0X298);
            goto L_800B12EC;
    }
    // 0x800B12D8: addiu       $at, $zero, 0x298
    ctx->r1 = ADD32(0, 0X298);
    // 0x800B12DC: beq         $v0, $at, L_800B12EC
    if (ctx->r2 == ctx->r1) {
        // 0x800B12E0: addiu       $at, $zero, 0x299
        ctx->r1 = ADD32(0, 0X299);
            goto L_800B12EC;
    }
    // 0x800B12E0: addiu       $at, $zero, 0x299
    ctx->r1 = ADD32(0, 0X299);
    // 0x800B12E4: bnel        $v0, $at, L_800B146C
    if (ctx->r2 != ctx->r1) {
        // 0x800B12E8: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800B146C;
    }
    goto skip_4;
    // 0x800B12E8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_4:
L_800B12EC:
    // 0x800B12EC: lh          $t2, 0x2E0($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B12F0: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x800B12F4: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x800B12F8: multu       $t2, $a3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B12FC: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x800B1300: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x800B1304: addiu       $t0, $t0, -0x9A0
    ctx->r8 = ADD32(ctx->r8, -0X9A0);
    // 0x800B1308: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800B130C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x800B1310: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800B1314: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // 0x800B1318: mflo        $t3
    ctx->r11 = lo;
    // 0x800B131C: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
    // 0x800B1320: lh          $t4, 0x22($v1)
    ctx->r12 = S32(MEM_H(ctx->r3, 0X22));
    // 0x800B1324: addiu       $t5, $t4, -0x5
    ctx->r13 = ADD32(ctx->r12, -0X5);
    // 0x800B1328: sh          $t5, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r13;
    // 0x800B132C: lh          $v0, 0x282($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X282));
    // 0x800B1330: sh          $t6, 0x2C0($s0)
    MEM_H(0X2C0, ctx->r16) = ctx->r14;
    // 0x800B1334: sw          $t7, 0x274($s0)
    MEM_W(0X274, ctx->r16) = ctx->r15;
    // 0x800B1338: addiu       $t9, $v0, 0x200
    ctx->r25 = ADD32(ctx->r2, 0X200);
    // 0x800B133C: andi        $t1, $t9, 0x7FF
    ctx->r9 = ctx->r25 & 0X7FF;
    // 0x800B1340: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800B1344: sb          $t8, 0x367($s0)
    MEM_B(0X367, ctx->r16) = ctx->r24;
    // 0x800B1348: sb          $zero, 0x368($s0)
    MEM_B(0X368, ctx->r16) = 0;
    // 0x800B134C: sb          $zero, 0x369($s0)
    MEM_B(0X369, ctx->r16) = 0;
    // 0x800B1350: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800B1354: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x800B1358: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x800B135C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B1360: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B1364: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800B1368: sw          $t6, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->r14;
    // 0x800B136C: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x800B1370: lh          $t1, 0x0($t9)
    ctx->r9 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B1374: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B1378: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800B137C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800B1380: jal         0x80059034
    // 0x800B1384: sw          $t3, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r11;
    spritesound(rdram, ctx);
        goto after_2;
    // 0x800B1384: sw          $t3, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r11;
    after_2:
    // 0x800B1388: lh          $v0, 0x282($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X282));
    // 0x800B138C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x800B1390: addiu       $t0, $t0, -0x9A0
    ctx->r8 = ADD32(ctx->r8, -0X9A0);
    // 0x800B1394: addiu       $t5, $v0, 0x200
    ctx->r13 = ADD32(ctx->r2, 0X200);
    // 0x800B1398: andi        $t6, $t5, 0x7FF
    ctx->r14 = ctx->r13 & 0X7FF;
    // 0x800B139C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B13A0: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x800B13A4: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B13A8: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x800B13AC: lh          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800B13B0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800B13B4: andi        $t3, $v0, 0x7FF
    ctx->r11 = ctx->r2 & 0X7FF;
    // 0x800B13B8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800B13BC: lw          $t2, 0x214($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800B13C0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800B13C4: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800B13C8: sra         $t1, $t9, 9
    ctx->r9 = S32(SIGNED(ctx->r25) >> 9);
    // 0x800B13CC: lw          $t9, 0x21C($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800B13D0: lw          $t8, 0x218($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800B13D4: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    // 0x800B13D8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800B13DC: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B13E0: sra         $t7, $t6, 9
    ctx->r15 = S32(SIGNED(ctx->r14) >> 9);
    // 0x800B13E4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B13E8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800B13EC: jal         0x800B06B8
    // 0x800B13F0: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    checkhitwall(rdram, ctx);
        goto after_3;
    // 0x800B13F0: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x800B13F4: b           L_800B146C
    // 0x800B13F8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800B146C;
    // 0x800B13F8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800B13FC:
    // 0x800B13FC: lh          $v0, 0x282($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X282));
    // 0x800B1400: addiu       $t2, $zero, 0x1A
    ctx->r10 = ADD32(0, 0X1A);
    // 0x800B1404: sh          $t2, 0x2C0($s0)
    MEM_H(0X2C0, ctx->r16) = ctx->r10;
    // 0x800B1408: addiu       $t4, $v0, 0x200
    ctx->r12 = ADD32(ctx->r2, 0X200);
    // 0x800B140C: andi        $t5, $t4, 0x7FF
    ctx->r13 = ctx->r12 & 0X7FF;
    // 0x800B1410: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800B1414: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x800B1418: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B141C: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800B1420: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800B1424: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800B1428: andi        $t2, $v0, 0x7FF
    ctx->r10 = ctx->r2 & 0X7FF;
    // 0x800B142C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800B1430: lw          $t1, 0x214($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800B1434: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800B1438: lh          $t5, 0x0($t4)
    ctx->r13 = S32(MEM_H(ctx->r12, 0X0));
    // 0x800B143C: sra         $t9, $t8, 9
    ctx->r25 = S32(SIGNED(ctx->r24) >> 9);
    // 0x800B1440: lw          $t8, 0x21C($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800B1444: lw          $t7, 0x218($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800B1448: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    // 0x800B144C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800B1450: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B1454: sra         $t6, $t5, 9
    ctx->r14 = S32(SIGNED(ctx->r13) >> 9);
    // 0x800B1458: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800B145C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B1460: jal         0x800B06B8
    // 0x800B1464: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    checkhitwall(rdram, ctx);
        goto after_4;
    // 0x800B1464: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    after_4:
L_800B1468:
    // 0x800B1468: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800B146C:
    // 0x800B146C: lw          $s0, 0x1C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800B1470: lw          $s1, 0x20($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800B1474: jr          $ra
    // 0x800B1478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B1478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void guScaleF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD928: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BD92C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BD930: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BD934: jal         0x800C8BC0
    // 0x800BD938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800BD938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BD93C: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800BD940: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BD944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD948: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BD94C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800BD950: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BD954: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x800BD958: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BD95C: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x800BD960: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800BD964: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800BD968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD96C: jr          $ra
    // 0x800BD970: nop

    return;
    // 0x800BD970: nop

;}
RECOMP_FUNC void func_80069130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069130: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80069134: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80069138: lhu         $t6, 0x52($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X52);
    // 0x8006913C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80069140: addiu       $v1, $v1, 0x61A8
    ctx->r3 = ADD32(ctx->r3, 0X61A8);
    // 0x80069144: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80069148: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006914C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80069150: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80069154: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069158: sw          $zero, -0x2358($at)
    MEM_W(-0X2358, ctx->r1) = 0;
    // 0x8006915C: addu        $s0, $v1, $t7
    ctx->r16 = ADD32(ctx->r3, ctx->r15);
    // 0x80069160: lh          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X8));
    // 0x80069164: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80069168: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8006916C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80069170: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80069174: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80069178: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8006917C: lw          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80069180: lw          $t5, 0x4($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80069184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069188: lh          $a0, 0x1A($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X1A));
    // 0x8006918C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80069190: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80069194: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x80069198: jal         0x80098E64
    // 0x8006919C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    getceilzofslope(rdram, ctx);
        goto after_0;
    // 0x8006919C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    after_0:
    // 0x800691A0: sra         $t6, $v0, 4
    ctx->r14 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800691A4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800691A8: lh          $a0, 0x1A($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X1A));
    // 0x800691AC: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800691B0: jal         0x80098E64
    // 0x800691B4: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    getceilzofslope(rdram, ctx);
        goto after_1;
    // 0x800691B4: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    after_1:
    // 0x800691B8: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800691BC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800691C0: lh          $a0, 0xC($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800691C4: lw          $a1, 0x4C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800691C8: jal         0x80098E64
    // 0x800691CC: lw          $a2, 0x44($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X44));
    getceilzofslope(rdram, ctx);
        goto after_2;
    // 0x800691CC: lw          $a2, 0x44($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X44));
    after_2:
    // 0x800691D0: sra         $v1, $v0, 4
    ctx->r3 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800691D4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800691D8: lh          $a0, 0xC($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800691DC: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800691E0: jal         0x80098E64
    // 0x800691E4: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    getceilzofslope(rdram, ctx);
        goto after_3;
    // 0x800691E4: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    after_3:
    // 0x800691E8: lw          $v1, 0x2C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800691EC: lw          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800691F0: sra         $t9, $v0, 4
    ctx->r25 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800691F4: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800691F8: beql        $at, $zero, L_8006920C
    if (ctx->r1 == 0) {
        // 0x800691FC: lh          $a0, 0x1A($s0)
        ctx->r4 = S32(MEM_H(ctx->r16, 0X1A));
            goto L_8006920C;
    }
    goto skip_0;
    // 0x800691FC: lh          $a0, 0x1A($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X1A));
    skip_0:
    // 0x80069200: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80069204: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80069208: lh          $a0, 0x1A($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X1A));
L_8006920C:
    // 0x8006920C: lw          $a1, 0x4C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80069210: jal         0x80098FB4
    // 0x80069214: lw          $a2, 0x44($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X44));
    getflorzofslope(rdram, ctx);
        goto after_4;
    // 0x80069214: lw          $a2, 0x44($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X44));
    after_4:
    // 0x80069218: sra         $t4, $v0, 4
    ctx->r12 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8006921C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80069220: lh          $a0, 0x1A($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X1A));
    // 0x80069224: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80069228: jal         0x80098FB4
    // 0x8006922C: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    getflorzofslope(rdram, ctx);
        goto after_5;
    // 0x8006922C: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    after_5:
    // 0x80069230: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80069234: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80069238: lh          $a0, 0xC($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0XC));
    // 0x8006923C: lw          $a1, 0x4C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80069240: jal         0x80098FB4
    // 0x80069244: lw          $a2, 0x44($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X44));
    getflorzofslope(rdram, ctx);
        goto after_6;
    // 0x80069244: lw          $a2, 0x44($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X44));
    after_6:
    // 0x80069248: sra         $v1, $v0, 4
    ctx->r3 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8006924C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80069250: lh          $a0, 0xC($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0XC));
    // 0x80069254: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80069258: jal         0x80098FB4
    // 0x8006925C: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    getflorzofslope(rdram, ctx);
        goto after_7;
    // 0x8006925C: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    after_7:
    // 0x80069260: lw          $v1, 0x2C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80069264: lw          $t6, 0x38($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80069268: sra         $t7, $v0, 4
    ctx->r15 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8006926C: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80069270: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80069274: beql        $at, $zero, L_80069288
    if (ctx->r1 == 0) {
        // 0x80069278: lh          $a2, 0xE($s0)
        ctx->r6 = S32(MEM_H(ctx->r16, 0XE));
            goto L_80069288;
    }
    goto skip_1;
    // 0x80069278: lh          $a2, 0xE($s0)
    ctx->r6 = S32(MEM_H(ctx->r16, 0XE));
    skip_1:
    // 0x8006927C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x80069280: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80069284: lh          $a2, 0xE($s0)
    ctx->r6 = S32(MEM_H(ctx->r16, 0XE));
L_80069288:
    // 0x80069288: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006928C: andi        $t8, $a2, 0x4
    ctx->r24 = ctx->r6 & 0X4;
    // 0x80069290: beq         $t8, $at, L_80069300
    if (ctx->r24 == ctx->r1) {
        // 0x80069294: andi        $a1, $a2, 0xFFFB
        ctx->r5 = ctx->r6 & 0XFFFB;
            goto L_80069300;
    }
    // 0x80069294: andi        $a1, $a2, 0xFFFB
    ctx->r5 = ctx->r6 & 0XFFFB;
    // 0x80069298: lh          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0XC));
    // 0x8006929C: lhu         $t7, 0x1A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1A);
    // 0x800692A0: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800692A4: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800692A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800692AC: addiu       $v0, $v0, -0x1988
    ctx->r2 = ADD32(ctx->r2, -0X1988);
    // 0x800692B0: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x800692B4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800692B8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800692BC: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800692C0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800692C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800692C8: lw          $a0, 0x0($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800692CC: lw          $v1, 0x0($t5)
    ctx->r3 = S32(MEM_W(ctx->r13, 0X0));
    // 0x800692D0: andi        $a1, $a2, 0xFFFB
    ctx->r5 = ctx->r6 & 0XFFFB;
    // 0x800692D4: sra         $t4, $a0, 4
    ctx->r12 = S32(SIGNED(ctx->r4) >> 4);
    // 0x800692D8: sra         $t6, $v1, 4
    ctx->r14 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800692DC: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800692E0: beq         $at, $zero, L_800692F0
    if (ctx->r1 == 0) {
        // 0x800692E4: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800692F0;
    }
    // 0x800692E4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800692E8: b           L_800692F4
    // 0x800692EC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800692F4;
    // 0x800692EC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800692F0:
    // 0x800692F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800692F4:
    // 0x800692F4: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x800692F8: b           L_8006935C
    // 0x800692FC: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
        goto L_8006935C;
    // 0x800692FC: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
L_80069300:
    // 0x80069300: lhu         $t7, 0x1A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1A);
    // 0x80069304: lh          $t5, 0xC($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0XC));
    // 0x80069308: addiu       $v0, $v0, -0x1988
    ctx->r2 = ADD32(ctx->r2, -0X1988);
    // 0x8006930C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80069310: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80069314: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80069318: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8006931C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80069320: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80069324: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80069328: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8006932C: lw          $a0, 0x4($t7)
    ctx->r4 = S32(MEM_W(ctx->r15, 0X4));
    // 0x80069330: lw          $v1, 0x4($t9)
    ctx->r3 = S32(MEM_W(ctx->r25, 0X4));
    // 0x80069334: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80069338: sra         $t8, $a0, 4
    ctx->r24 = S32(SIGNED(ctx->r4) >> 4);
    // 0x8006933C: sra         $t4, $v1, 4
    ctx->r12 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80069340: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80069344: beq         $at, $zero, L_80069354
    if (ctx->r1 == 0) {
        // 0x80069348: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_80069354;
    }
    // 0x80069348: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8006934C: b           L_80069358
    // 0x80069350: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_80069358;
    // 0x80069350: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80069354:
    // 0x80069354: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80069358:
    // 0x80069358: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
L_8006935C:
    // 0x8006935C: lhu         $a0, 0x12($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X12);
    // 0x80069360: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80069364: jal         0x80067590
    // 0x80069368: sh          $a1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r5;
    func_80067590(rdram, ctx);
        goto after_8;
    // 0x80069368: sh          $a1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r5;
    after_8:
    // 0x8006936C: lh          $a1, 0x22($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X22));
    // 0x80069370: jal         0x8006768C
    // 0x80069374: lhu         $a0, 0x52($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X52);
    func_8006768C(rdram, ctx);
        goto after_9;
    // 0x80069374: lhu         $a0, 0x52($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X52);
    after_9:
    // 0x80069378: lw          $v0, 0x24($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8006937C: lw          $t5, 0x3C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80069380: lw          $t7, 0x38($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80069384: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80069388: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x8006938C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80069390: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x80069394: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80069398: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006939C: lwc1        $f0, -0x1418($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X1418));
    // 0x800693A0: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800693A4: lwc1        $f2, -0x1420($at)
    ctx->f2.u32l = S32(MEM_W(ctx->r1, -0X1420));
    // 0x800693A8: lw          $t9, 0x34($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800693AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800693B0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800693B4: subu        $t4, $v0, $t9
    ctx->r12 = SUB32(ctx->r2, ctx->r25);
    // 0x800693B8: lw          $t5, 0x30($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800693BC: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800693C0: addiu       $s0, $s0, -0x1434
    ctx->r16 = ADD32(ctx->r16, -0X1434);
    // 0x800693C4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800693C8: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x800693CC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800693D0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800693D4: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800693D8: lh          $a1, 0x22($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X22));
    // 0x800693DC: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800693E0: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800693E4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800693E8: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x800693EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800693F0: swc1        $f6, -0x1430($at)
    MEM_W(-0X1430, ctx->r1) = ctx->f6.u32l;
    // 0x800693F4: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800693F8: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800693FC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80069400: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80069404: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80069408: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8006940C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80069410: swc1        $f18, -0x142C($at)
    MEM_W(-0X142C, ctx->r1) = ctx->f18.u32l;
    // 0x80069414: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80069418: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8006941C: jal         0x80067AC4
    // 0x80069420: swc1        $f10, -0x1428($at)
    MEM_W(-0X1428, ctx->r1) = ctx->f10.u32l;
    func_80067AC4(rdram, ctx);
        goto after_10;
    // 0x80069420: swc1        $f10, -0x1428($at)
    MEM_W(-0X1428, ctx->r1) = ctx->f10.u32l;
    after_10:
    // 0x80069424: lw          $v0, 0x4C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80069428: lw          $t9, 0x3C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8006942C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80069430: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80069434: lw          $a0, 0x44($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80069438: sh          $t8, -0x23D0($at)
    MEM_H(-0X23D0, ctx->r1) = ctx->r24;
    // 0x8006943C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80069440: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80069444: sh          $t4, -0x23CC($at)
    MEM_H(-0X23CC, ctx->r1) = ctx->r12;
    // 0x80069448: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8006944C: sra         $t5, $a0, 1
    ctx->r13 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80069450: sh          $t5, -0x23CE($at)
    MEM_H(-0X23CE, ctx->r1) = ctx->r13;
    // 0x80069454: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80069458: lwc1        $f16, -0x1444($at)
    ctx->f16.u32l = S32(MEM_W(ctx->r1, -0X1444));
    // 0x8006945C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80069460: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80069464: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80069468: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006946C: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069470: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80069474: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80069478: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x8006947C: addiu       $t1, $t1, -0x23D0
    ctx->r9 = ADD32(ctx->r9, -0X23D0);
    // 0x80069480: sh          $a1, -0x23CA($at)
    MEM_H(-0X23CA, ctx->r1) = ctx->r5;
    // 0x80069484: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x80069488: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8006948C: lw          $t4, 0x38($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80069490: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80069494: mflo        $t9
    ctx->r25 = lo;
    // 0x80069498: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x8006949C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800694A0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800694A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800694A8: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800694AC: sh          $t8, -0x23C8($at)
    MEM_H(-0X23C8, ctx->r1) = ctx->r24;
    // 0x800694B0: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // 0x800694B4: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
    // 0x800694B8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800694BC: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x800694C0: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800694C4: sh          $a1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r5;
    // 0x800694C8: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800694CC: lwc1        $f8, -0x1430($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, -0X1430));
    // 0x800694D0: lw          $t5, 0x34($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800694D4: lw          $a0, 0x40($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800694D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800694DC: lw          $a2, 0x48($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800694E0: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800694E4: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800694E8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800694EC: sra         $t4, $a2, 1
    ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800694F0: mflo        $t9
    ctx->r25 = lo;
    // 0x800694F4: sh          $t7, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r15;
    // 0x800694F8: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x800694FC: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80069500: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    // 0x80069504: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80069508: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x8006950C: lwc1        $f16, -0x1440($at)
    ctx->f16.u32l = S32(MEM_W(ctx->r1, -0X1440));
    // 0x80069510: addiu       $a3, $t8, 0x1
    ctx->r7 = ADD32(ctx->r24, 0X1);
    // 0x80069514: andi        $t5, $a3, 0xFFFF
    ctx->r13 = ctx->r7 & 0XFFFF;
    // 0x80069518: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8006951C: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80069520: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069524: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80069528: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8006952C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80069530: lw          $t7, 0x30($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80069534: sh          $a1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r5;
    // 0x80069538: lwc1        $f4, -0x142C($at)
    ctx->f4.u32l = S32(MEM_W(ctx->r1, -0X142C));
    // 0x8006953C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80069540: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80069544: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80069548: mflo        $t6
    ctx->r14 = lo;
    // 0x8006954C: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80069550: addiu       $t3, $t3, -0x2358
    ctx->r11 = ADD32(ctx->r11, -0X2358);
    // 0x80069554: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80069558: lw          $t5, 0x0($t3)
    ctx->r13 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8006955C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80069560: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
    // 0x80069564: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
    // 0x80069568: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x8006956C: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80069570: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // 0x80069574: sh          $a1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r5;
    // 0x80069578: lwc1        $f8, -0x1428($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, -0X1428));
    // 0x8006957C: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80069580: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80069584: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80069588: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006958C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80069590: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80069594: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80069598: jr          $ra
    // 0x8006959C: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
    return;
    // 0x8006959C: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
;}
RECOMP_FUNC void resetboardtimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B474: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B478: jr          $ra
    // 0x8005B47C: sw          $zero, -0x29AC($at)
    MEM_W(-0X29AC, ctx->r1) = 0;
    return;
    // 0x8005B47C: sw          $zero, -0x29AC($at)
    MEM_W(-0X29AC, ctx->r1) = 0;
;}
RECOMP_FUNC void alLoadNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC124: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CC128: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CC12C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800CC130: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CC134: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CC138: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CC13C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CC140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CC144: addiu       $a1, $a1, -0x3014
    ctx->r5 = ADD32(ctx->r5, -0X3014);
    // 0x800CC148: addiu       $a2, $a2, -0x36C0
    ctx->r6 = ADD32(ctx->r6, -0X36C0);
    // 0x800CC14C: jal         0x800D05C0
    // 0x800CC150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CC150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800CC154: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800CC158: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CC15C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CC160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CC164: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800CC168: jal         0x800BF830
    // 0x800CC16C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CC16C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CC170: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800CC174: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x800CC178: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CC17C: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800CC180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CC184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CC188: jal         0x800BF830
    // 0x800CC18C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800CC18C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800CC190: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800CC194: lw          $t9, 0x2C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800CC198: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800CC19C: jalr        $t9
    // 0x800CC1A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800CC1A0: nop

    after_3:
    // 0x800CC1A4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CC1A8: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800CC1AC: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800CC1B0: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x800CC1B4: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800CC1B8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CC1BC: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CC1C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CC1C4: jr          $ra
    // 0x800CC1C8: nop

    return;
    // 0x800CC1C8: nop

;}
RECOMP_FUNC void alSaveNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBFB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBFB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBFB8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CBFBC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CBFC0: addiu       $a2, $a2, -0x1B00
    ctx->r6 = ADD32(ctx->r6, -0X1B00);
    // 0x800CBFC4: addiu       $a1, $a1, -0x1ACC
    ctx->r5 = ADD32(ctx->r5, -0X1ACC);
    // 0x800CBFC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CBFCC: jal         0x800D05C0
    // 0x800CBFD0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CBFD0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x800CBFD4: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800CBFD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CBFDC: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800CBFE0: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800CBFE4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CBFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBFEC: jr          $ra
    // 0x800CBFF0: nop

    return;
    // 0x800CBFF0: nop

;}
RECOMP_FUNC void alSndpPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1840: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C1844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1848: lw          $t6, 0x3C($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X3C));
    // 0x800C184C: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x800C1850: lw          $v0, 0x40($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X40));
    // 0x800C1854: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1858: mflo        $t7
    ctx->r15 = lo;
    // 0x800C185C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1860: lw          $t9, 0x28($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X28));
    // 0x800C1864: bnel        $t9, $zero, L_800C1898
    if (ctx->r25 != 0) {
        // 0x800C1868: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800C1898;
    }
    goto skip_0;
    // 0x800C1868: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800C186C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800C1870: lw          $t0, 0x3C($a0)
    ctx->r8 = S32(MEM_W(ctx->r4, 0X3C));
    // 0x800C1874: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800C1878: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800C187C: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1880: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C1884: mflo        $t1
    ctx->r9 = lo;
    // 0x800C1888: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800C188C: jal         0x800C9C6C
    // 0x800C1890: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C1890: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_0:
    // 0x800C1894: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C1898:
    // 0x800C1898: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C189C: jr          $ra
    // 0x800C18A0: nop

    return;
    // 0x800C18A0: nop

;}
RECOMP_FUNC void displayinvsprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F180: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006F184: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8006F188: lh          $v0, 0x3A($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x8006F18C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8006F190: addiu       $v1, $v1, -0x9A0
    ctx->r3 = ADD32(ctx->r3, -0X9A0);
    // 0x8006F194: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8006F198: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8006F19C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8006F1A0: addiu       $t3, $t6, 0x200
    ctx->r11 = ADD32(ctx->r14, 0X200);
    // 0x8006F1A4: andi        $t7, $t6, 0x7FF
    ctx->r15 = ctx->r14 & 0X7FF;
    // 0x8006F1A8: andi        $t4, $t3, 0x7FF
    ctx->r12 = ctx->r11 & 0X7FF;
    // 0x8006F1AC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8006F1B0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006F1B4: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8006F1B8: lh          $t7, 0x0($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X0));
    // 0x8006F1BC: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x8006F1C0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8006F1C4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8006F1C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8006F1CC: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8006F1D0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8006F1D4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8006F1D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8006F1DC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8006F1E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006F1E4: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8006F1E8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006F1EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006F1F0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8006F1F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006F1F8: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8006F1FC: lh          $t0, 0x0($t9)
    ctx->r8 = S32(MEM_H(ctx->r25, 0X0));
    // 0x8006F200: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8006F204: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8006F208: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8006F20C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8006F210: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8006F214: sra         $t2, $t1, 14
    ctx->r10 = S32(SIGNED(ctx->r9) >> 14);
    // 0x8006F218: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8006F21C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006F220: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8006F224: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006F228: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8006F22C: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x8006F230: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006F234: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8006F238: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006F23C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006F240: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8006F244: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8006F248: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8006F24C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006F250: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x8006F254: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006F258: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8006F25C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8006F260: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8006F264: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8006F268: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x8006F26C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8006F270: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8006F274: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006F278: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8006F27C: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8006F280: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8006F284: sra         $t2, $a2, 16
    ctx->r10 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006F288: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006F28C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8006F290: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x8006F294: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8006F298: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8006F29C: nop

    // 0x8006F2A0: sll         $t4, $a3, 16
    ctx->r12 = S32(ctx->r7 << 16);
    // 0x8006F2A4: jal         0x8006E994
    // 0x8006F2A8: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    setrotatespriteflags(rdram, ctx);
        goto after_0;
    // 0x8006F2A8: sra         $a3, $t4, 16
    ctx->r7 = S32(SIGNED(ctx->r12) >> 16);
    after_0:
    // 0x8006F2AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8006F2B0: jal         0x8006E7C4
    // 0x8006F2B4: lhu         $a1, 0x3E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X3E);
    invtilescale(rdram, ctx);
        goto after_1;
    // 0x8006F2B4: lhu         $a1, 0x3E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X3E);
    after_1:
    // 0x8006F2B8: sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // 0x8006F2BC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8006F2C0: jal         0x8006E7C4
    // 0x8006F2C4: lhu         $a1, 0x3E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X3E);
    invtilescale(rdram, ctx);
        goto after_2;
    // 0x8006F2C4: lhu         $a1, 0x3E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X3E);
    after_2:
    // 0x8006F2C8: lh          $t6, 0x32($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X32));
    // 0x8006F2CC: lw          $t7, 0x2C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006F2D0: lh          $t9, 0x36($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X36));
    // 0x8006F2D4: lhu         $t0, 0x20($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X20);
    // 0x8006F2D8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006F2DC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8006F2E0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8006F2E4: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8006F2E8: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006F2EC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8006F2F0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = S32(MEM_W(ctx->r29, 0X28));
    // 0x8006F2F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006F2F8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006F2FC: bgez        $t0, L_8006F310
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8006F300: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8006F310;
    }
    // 0x8006F300: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006F304: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006F308: nop

    // 0x8006F30C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8006F310:
    // 0x8006F310: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006F314: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006F318: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006F31C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8006F320: bgez        $v0, L_8006F334
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006F324: nop
    
            goto L_8006F334;
    }
    // 0x8006F324: nop

    // 0x8006F328: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006F32C: nop

    // 0x8006F330: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8006F334:
    // 0x8006F334: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8006F338: lhu         $t1, 0x3E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X3E);
    // 0x8006F33C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006F340: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8006F344: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8006F348: jal         0x8005D13C
    // 0x8006F34C: nop

    rotatesprite(rdram, ctx);
        goto after_3;
    // 0x8006F34C: nop

    after_3:
    // 0x8006F350: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8006F354: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006F358: jr          $ra
    // 0x8006F35C: nop

    return;
    // 0x8006F35C: nop

;}
RECOMP_FUNC void krand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098054: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x80098058: addiu       $v1, $v1, -0x5368
    ctx->r3 = ADD32(ctx->r3, -0X5368);
    // 0x8009805C: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80098060: lui         $at, 0x1A4
    ctx->r1 = S32(0X1A4 << 16);
    // 0x80098064: ori         $at, $at, 0xE86D
    ctx->r1 = ctx->r1 | 0XE86D;
    // 0x80098068: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009806C: mflo        $t7
    ctx->r15 = lo;
    // 0x80098070: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80098074: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80098078: jr          $ra
    // 0x8009807C: srl         $v0, $t8, 16
    ctx->r2 = S32(U32(ctx->r24) >> 16);
    return;
    // 0x8009807C: srl         $v0, $t8, 16
    ctx->r2 = S32(U32(ctx->r24) >> 16);
;}
RECOMP_FUNC void __amHandleFrameMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057FDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057FE0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80057FE4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80057FE8: addiu       $s1, $s1, 0x4D34
    ctx->r17 = ADD32(ctx->r17, 0X4D34);
    // 0x80057FEC: lw          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80057FF0: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x80057FF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80057FF8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80057FFC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80058000: lw          $t7, -0x1718($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X1718));
    // 0x80058004: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80058008: addiu       $s0, $s0, -0x1710
    ctx->r16 = ADD32(ctx->r16, -0X1710);
    // 0x8005800C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80058010: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80058014: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80058018: lw          $t8, -0x6328($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X6328));
    // 0x8005801C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80058020: lw          $t9, 0x4D38($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X4D38));
    // 0x80058024: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80058028: sw          $t8, -0x6058($at)
    MEM_W(-0X6058, ctx->r1) = ctx->r24;
    // 0x8005802C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80058030: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80058034: mfhi        $t1
    ctx->r9 = hi;
    // 0x80058038: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005803C: sw          $t1, -0x5FB0($at)
    MEM_W(-0X5FB0, ctx->r1) = ctx->r9;
    // 0x80058040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058044: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80058048: jal         0x80057038
    // 0x8005804C: sw          $zero, 0x4D30($at)
    MEM_W(0X4D30, ctx->r1) = 0;
    func_80057038(rdram, ctx);
        goto after_0;
    // 0x8005804C: sw          $zero, 0x4D30($at)
    MEM_W(0X4D30, ctx->r1) = 0;
    after_0:
    // 0x80058050: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x80058054: lw          $t2, -0x5FB0($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X5FB0));
    // 0x80058058: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005805C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80058060: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80058064: jal         0x800BF6F0
    // 0x80058068: lw          $a0, -0x6320($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X6320));
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80058068: lw          $a0, -0x6320($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X6320));
    after_1:
    // 0x8005806C: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x80058070: addiu       $t0, $t0, -0x6054
    ctx->r8 = ADD32(ctx->r8, -0X6054);
    // 0x80058074: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80058078: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8005807C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80058080: lw          $t8, 0x4D70($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, 0X4D70));
    // 0x80058084: lw          $t7, -0x5FB8($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X5FB8));
    // 0x80058088: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x8005808C: lw          $t4, -0x5FB0($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X5FB0));
    // 0x80058090: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80058094: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80058098: addiu       $t1, $t9, 0x60
    ctx->r9 = ADD32(ctx->r25, 0X60);
    // 0x8005809C: addiu       $t6, $t6, 0x4D3C
    ctx->r14 = ADD32(ctx->r14, 0X4D3C);
    // 0x800580A0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800580A4: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x800580A8: andi        $t2, $t1, 0xFFF0
    ctx->r10 = ctx->r9 & 0XFFF0;
    // 0x800580AC: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x800580B0: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800580B4: lw          $a0, -0x5FB4($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X5FB4));
    // 0x800580B8: lh          $a3, 0x0($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X0));
    // 0x800580BC: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x800580C0: addiu       $a1, $a1, -0x5FAC
    ctx->r5 = ADD32(ctx->r5, -0X5FAC);
    // 0x800580C4: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800580C8: beq         $at, $zero, L_800580D8
    if (ctx->r1 == 0) {
        // 0x800580CC: nop
    
            goto L_800580D8;
    }
    // 0x800580CC: nop

    // 0x800580D0: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800580D4: lh          $a3, 0x0($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X0));
L_800580D8:
    // 0x800580D8: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800580DC: lw          $a0, -0x6058($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X6058));
    gpr audio_cmd_len = ctx->r5;
    gpr audio_cmd_list = ctx->r4;
    // 0x800580E0: jal         0x800C25A8
    // 0x800580E4: lw          $a2, 0x0($t0)
    ctx->r6 = S32(MEM_W(ctx->r8, 0X0));
    alAudioFrame(rdram, ctx);
    recomp_set_audio_command_list((uint32_t)audio_cmd_list, MEM_W(audio_cmd_len, 0) * 8);
        goto after_2;
    after_2:
    // 0x800580E8: lw          $t3, 0x0($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800580EC: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x800580F0: addiu       $v1, $v1, -0x6328
    ctx->r3 = ADD32(ctx->r3, -0X6328);
    // 0x800580F4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800580F8: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800580FC: lw          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X0));
    // 0x80058100: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058104: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80058108: addiu       $a0, $a0, -0x6058
    ctx->r4 = ADD32(ctx->r4, -0X6058);
    // 0x8005810C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80058110: sw          $t6, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->r14;
    // 0x80058114: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80058118: lw          $t8, 0x0($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005811C: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058120: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80058124: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80058128: lw          $t3, 0x0($t2)
    ctx->r11 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005812C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80058130: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80058134: subu        $t4, $t8, $t3
    ctx->r12 = SUB32(ctx->r24, ctx->r11);
    // 0x80058138: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8005813C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80058140: sw          $t6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r14;
    // 0x80058144: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058148: addiu       $v0, $v0, 0x13C0
    ctx->r2 = ADD32(ctx->r2, 0X13C0);
    // 0x8005814C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80058150: sw          $t9, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r25;
    // 0x80058154: lw          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058158: addiu       $t3, $t3, 0x1490
    ctx->r11 = ADD32(ctx->r11, 0X1490);
    // 0x8005815C: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x80058160: sw          $zero, 0x14($t2)
    MEM_W(0X14, ctx->r10) = 0;
    // 0x80058164: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058168: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005816C: addiu       $t6, $t6, 0x2890
    ctx->r14 = ADD32(ctx->r14, 0X2890);
    // 0x80058170: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
    // 0x80058174: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058178: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8005817C: addiu       $t9, $t9, -0x5640
    ctx->r25 = ADD32(ctx->r25, -0X5640);
    // 0x80058180: sw          $t4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r12;
    // 0x80058184: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058188: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x8005818C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80058190: sw          $t6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r14;
    // 0x80058194: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058198: addiu       $a0, $a0, -0xCB8
    ctx->r4 = ADD32(ctx->r4, -0XCB8);
    // 0x8005819C: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    // 0x800581A0: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581A4: sw          $t2, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r10;
    // 0x800581A8: lw          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581AC: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x800581B0: sw          $zero, 0x30($t3)
    MEM_W(0X30, ctx->r11) = 0;
    // 0x800581B4: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581B8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800581BC: addiu       $t3, $t3, 0x3698
    ctx->r11 = ADD32(ctx->r11, 0X3698);
    // 0x800581C0: sw          $zero, 0x34($t4)
    MEM_W(0X34, ctx->r12) = 0;
    // 0x800581C4: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581C8: sw          $zero, 0x38($t5)
    MEM_W(0X38, ctx->r13) = 0;
    // 0x800581CC: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581D0: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    // 0x800581D4: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581D8: sw          $zero, 0x48($t7)
    MEM_W(0X48, ctx->r15) = 0;
    // 0x800581DC: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581E0: sw          $zero, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = 0;
    // 0x800581E4: lw          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581E8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x800581EC: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581F0: sw          $t2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r10;
    // 0x800581F4: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800581F8: sw          $t3, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->r11;
    // 0x800581FC: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058200: sw          $zero, 0x54($t5)
    MEM_W(0X54, ctx->r13) = 0;
    // 0x80058204: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058208: jal         0x8004C654
    // 0x8005820C: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    osScGetCmdQ(rdram, ctx);
        goto after_3;
    // 0x8005820C: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    after_3:
    // 0x80058210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80058214: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80058218: jal         0x800BB610
    // 0x8005821C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8005821C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80058220: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80058224: addiu       $a0, $a0, 0x3698
    ctx->r4 = ADD32(ctx->r4, 0X3698);
    // 0x80058228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005822C: jal         0x800BB440
    // 0x80058230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80058230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80058234: lui         $t7, 0xA450
    ctx->r15 = S32(0XA450 << 16);
    // 0x80058238: lw          $t9, 0x4($t7)
    osAiGetLength_recomp(rdram, ctx);
    ctx->r25 = S32(ctx->r2);
    // 0x8005823C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80058240: lw          $t2, 0x4D38($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X4D38));
    // 0x80058244: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80058248: srl         $t1, $t9, 2
    ctx->r9 = S32(U32(ctx->r25) >> 2);
    // 0x8005824C: sw          $t1, 0x4D70($at)
    MEM_W(0X4D70, ctx->r1) = ctx->r9;
    // 0x80058250: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80058254: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80058258: lui         $a2, 0x8022
    ctx->r6 = S32(0X8022 << 16);
    // 0x8005825C: mfhi        $v1
    ctx->r3 = hi;
    // 0x80058260: addiu       $a2, $a2, -0x5FB0
    ctx->r6 = ADD32(ctx->r6, -0X5FB0);
    // 0x80058264: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80058268: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005826C: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80058270: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x80058274: lh          $a1, 0x4D3C($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X4D3C));
    // 0x80058278: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8005827C: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80058280: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80058284: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80058288: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8005828C: jal         0x800C2B40
    // 0x80058290: lw          $a0, -0x6320($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X6320));
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_6;
    // 0x80058290: lw          $a0, -0x6320($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X6320));
    after_6:
    // 0x80058294: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80058298: addiu       $v1, $v1, -0x6070
    ctx->r3 = ADD32(ctx->r3, -0X6070);
    // 0x8005829C: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800582A0: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800582A4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800582A8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800582AC: xori        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 ^ 0X1;
    // 0x800582B0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800582B4: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800582B8: lw          $t2, 0x4D38($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X4D38));
    // 0x800582BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800582C0: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x800582C4: jal         0x80057C78
    // 0x800582C8: sw          $t8, 0x4D38($at)
    MEM_W(0X4D38, ctx->r1) = ctx->r24;
    func_80057C78(rdram, ctx);
        goto after_7;
    // 0x800582C8: sw          $t8, 0x4D38($at)
    MEM_W(0X4D38, ctx->r1) = ctx->r24;
    after_7:
    // 0x800582CC: jal         0x8005780C
    // 0x800582D0: nop

    func_8005780C(rdram, ctx);
        goto after_8;
    // 0x800582D0: nop

    after_8:
    // 0x800582D4: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800582D8: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800582DC: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800582E0: jr          $ra
    // 0x800582E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800582E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void breakwall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B064C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B0650: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B0654: lh          $t7, 0x22($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X22));
    // 0x800B0658: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x800B065C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B0660: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B0664: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B0668: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B066C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B0670: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B0674: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800B0678: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B067C: sh          $t6, 0x61B8($at)
    MEM_H(0X61B8, ctx->r1) = ctx->r14;
    // 0x800B0680: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800B0684: jal         0x80059034
    // 0x800B0688: lh          $a1, 0x1E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X1E));
    spritesound(rdram, ctx);
        goto after_0;
    // 0x800B0688: lh          $a1, 0x1E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X1E));
    after_0:
    // 0x800B068C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x800B0690: jal         0x80059034
    // 0x800B0694: lh          $a1, 0x1E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X1E));
    spritesound(rdram, ctx);
        goto after_1;
    // 0x800B0694: lh          $a1, 0x1E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X1E));
    after_1:
    // 0x800B0698: lh          $a0, 0x1E($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X1E));
    // 0x800B069C: lh          $a1, 0x22($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X22));
    // 0x800B06A0: jal         0x8009A2B0
    // 0x800B06A4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lotsofglass(rdram, ctx);
        goto after_2;
    // 0x800B06A4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_2:
    // 0x800B06A8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800B06AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B06B0: jr          $ra
    // 0x800B06B4: nop

    return;
    // 0x800B06B4: nop

;}
RECOMP_FUNC void rotatesprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D13C: addiu       $sp, $sp, -0x2C0
    ctx->r29 = ADD32(ctx->r29, -0X2C0);
    // 0x8005D140: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8005D144: addiu       $t1, $t1, 0x4418
    ctx->r9 = ADD32(ctx->r9, 0X4418);
    // 0x8005D148: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D14C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005D150: lhu         $s1, 0x2D2($sp)
    ctx->r17 = MEM_HU(ctx->r29, 0X2D2);
    // 0x8005D154: lh          $a0, 0x2D6($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X2D6));
    // 0x8005D158: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005D15C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8005D160: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8005D164: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D168: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D16C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8005D170: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8005D174: swc1        $f14, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->f14.u32l;
    // 0x8005D178: sw          $a2, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->r6;
    // 0x8005D17C: sw          $a3, 0x2CC($sp)
    MEM_W(0X2CC, ctx->r29) = ctx->r7;
    // 0x8005D180: sb          $zero, 0x261($sp)
    MEM_B(0X261, ctx->r29) = 0;
    // 0x8005D184: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D188: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x8005D18C: addiu       $t8, $zero, 0x3000
    ctx->r24 = ADD32(0, 0X3000);
    // 0x8005D190: sh          $s1, 0x26E($sp)
    MEM_H(0X26E, ctx->r29) = ctx->r17;
    // 0x8005D194: andi        $t9, $a0, 0x4
    ctx->r25 = ctx->r4 & 0X4;
    // 0x8005D198: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8005D19C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005D1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D1A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005D1A8: beq         $t9, $zero, L_8005D1B4
    if (ctx->r25 == 0) {
        // 0x8005D1AC: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8005D1B4;
    }
    // 0x8005D1AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D1B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8005D1B4:
    // 0x8005D1B4: andi        $t6, $a0, 0x8
    ctx->r14 = ctx->r4 & 0X8;
    // 0x8005D1B8: beq         $t6, $zero, L_8005D1C4
    if (ctx->r14 == 0) {
        // 0x8005D1BC: andi        $a0, $s1, 0xFFFF
        ctx->r4 = ctx->r17 & 0XFFFF;
            goto L_8005D1C4;
    }
    // 0x8005D1BC: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x8005D1C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8005D1C4:
    // 0x8005D1C4: jal         0x8006370C
    // 0x8005D1C8: sb          $a1, 0x262($sp)
    MEM_B(0X262, ctx->r29) = ctx->r5;
    gettileid(rdram, ctx);
        goto after_0;
    // 0x8005D1C8: sb          $a1, 0x262($sp)
    MEM_B(0X262, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005D1CC: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8005D1D0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8005D1D4: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8005D1D8: addiu       $s2, $s2, -0x5010
    ctx->r18 = ADD32(ctx->r18, -0X5010);
    // 0x8005D1DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005D1E0: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8005D1E4: lw          $t9, 0x8($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X8));
    // 0x8005D1E8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8005D1EC: addiu       $t1, $t1, 0x4418
    ctx->r9 = ADD32(ctx->r9, 0X4418);
    // 0x8005D1F0: andi        $t6, $t9, 0xC0
    ctx->r14 = ctx->r25 & 0XC0;
    // 0x8005D1F4: lwc1        $f16, 0x2C8($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X2C8));
    // 0x8005D1F8: beq         $t6, $zero, L_8005D228
    if (ctx->r14 == 0) {
        // 0x8005D1FC: andi        $s1, $v0, 0xFFFF
        ctx->r17 = ctx->r2 & 0XFFFF;
            goto L_8005D228;
    }
    // 0x8005D1FC: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x8005D200: lh          $a0, 0x26E($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X26E));
    // 0x8005D204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D208: jal         0x8009223C
    // 0x8005D20C: swc1        $f16, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->f16.u32l;
    animateoffs(rdram, ctx);
        goto after_1;
    // 0x8005D20C: swc1        $f16, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8005D210: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8005D214: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x8005D218: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8005D21C: addiu       $t1, $t1, 0x4418
    ctx->r9 = ADD32(ctx->r9, 0X4418);
    // 0x8005D220: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8005D224: lwc1        $f16, 0x2C8($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X2C8));
L_8005D228:
    // 0x8005D228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D22C: beq         $s1, $at, L_8005EE20
    if (ctx->r17 == ctx->r1) {
        // 0x8005D230: sll         $t8, $s1, 3
        ctx->r24 = S32(ctx->r17 << 3);
            goto L_8005EE20;
    }
    // 0x8005D230: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x8005D234: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8005D238: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005D23C: addu        $s3, $s2, $t8
    ctx->r19 = ADD32(ctx->r18, ctx->r24);
    // 0x8005D240: lbu         $t9, 0x16($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X16);
    // 0x8005D244: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8005D248: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D24C: andi        $t6, $t9, 0x80
    ctx->r14 = ctx->r25 & 0X80;
    // 0x8005D250: bnel        $t6, $at, L_8005D260
    if (ctx->r14 != ctx->r1) {
        // 0x8005D254: lw          $v0, 0x8($s3)
        ctx->r2 = S32(MEM_W(ctx->r19, 0X8));
            goto L_8005D260;
    }
    goto skip_0;
    // 0x8005D254: lw          $v0, 0x8($s3)
    ctx->r2 = S32(MEM_W(ctx->r19, 0X8));
    skip_0:
    // 0x8005D258: sb          $t7, 0x261($sp)
    MEM_B(0X261, ctx->r29) = ctx->r15;
    // 0x8005D25C: lw          $v0, 0x8($s3)
    ctx->r2 = S32(MEM_W(ctx->r19, 0X8));
L_8005D260:
    // 0x8005D260: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    // 0x8005D264: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8005D268: andi        $t8, $v0, 0xFF00
    ctx->r24 = ctx->r2 & 0XFF00;
    // 0x8005D26C: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8005D270: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x8005D274: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8005D278: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8005D27C: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8005D280: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8005D284: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005D288: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x8005D28C: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8005D290: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8005D294: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x8005D298: beq         $t8, $zero, L_8005D2B0
    if (ctx->r24 == 0) {
        // 0x8005D29C: cvt.s.w     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8005D2B0;
    }
    // 0x8005D29C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005D2A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005D2A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005D2A8: nop

    // 0x8005D2AC: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
L_8005D2B0:
    // 0x8005D2B0: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8005D2B4: lwc1        $f6, 0x2CC($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X2CC));
    // 0x8005D2B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005D2BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005D2C0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005D2C4: lb          $t9, 0x262($sp)
    ctx->r25 = S32(MEM_B(ctx->r29, 0X262));
    // 0x8005D2C8: div.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005D2CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005D2D0: beq         $s0, $zero, L_8005D2DC
    if (ctx->r16 == 0) {
        // 0x8005D2D4: div.s       $f0, $f8, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_8005D2DC;
    }
    // 0x8005D2D4: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005D2D8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8005D2DC:
    // 0x8005D2DC: beq         $t9, $zero, L_8005D2E8
    if (ctx->r25 == 0) {
        // 0x8005D2E0: trunc.w.s   $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_8005D2E8;
    }
    // 0x8005D2E0: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8005D2E4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8005D2E8:
    // 0x8005D2E8: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8005D2EC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005D2F0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8005D2F4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8005D2F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005D2FC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8005D300: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D304: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005D308: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8005D30C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005D310: lh          $t6, 0xC($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0XC));
    // 0x8005D314: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005D318: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005D31C: lwc1        $f14, 0x2C4($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X2C4));
    // 0x8005D320: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8005D324: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x8005D328: lwc1        $f8, 0x2CC($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X2CC));
    // 0x8005D32C: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8005D330: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8005D334: nop

    // 0x8005D338: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8005D33C: nop

    // 0x8005D340: mul.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8005D344: swc1        $f10, 0x2CC($sp)
    MEM_W(0X2CC, ctx->r29) = ctx->f10.u32l;
    // 0x8005D348: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005D34C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8005D350: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8005D354: div.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8005D358: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D35C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005D360: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8005D364: swc1        $f4, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->f4.u32l;
    // 0x8005D368: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8005D36C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x8005D370: bc1t        L_8005EE20
    if (c1cs) {
        // 0x8005D374: swc1        $f8, 0x270($sp)
        MEM_W(0X270, ctx->r29) = ctx->f8.u32l;
            goto L_8005EE20;
    }
    // 0x8005D374: swc1        $f8, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->f8.u32l;
    // 0x8005D378: lwc1        $f10, 0x270($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X270));
    // 0x8005D37C: swc1        $f14, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->f14.u32l;
    // 0x8005D380: lwc1        $f6, 0x274($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X274));
    // 0x8005D384: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8005D388: nop

    // 0x8005D38C: bc1tl       L_8005EE24
    if (c1cs) {
        // 0x8005D390: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_8005EE24;
    }
    goto skip_1;
    // 0x8005D390: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_1:
    // 0x8005D394: lhu         $v0, 0x12($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X12);
    // 0x8005D398: lwc1        $f8, 0x2C4($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X2C4));
    // 0x8005D39C: lwc1        $f4, 0x270($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X270));
    // 0x8005D3A0: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x8005D3A4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8005D3A8: sub.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x8005D3AC: lhu         $v1, 0x14($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X14);
    // 0x8005D3B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005D3B4: add.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x8005D3B8: sll         $t8, $v1, 12
    ctx->r24 = S32(ctx->r3 << 12);
    // 0x8005D3BC: swc1        $f0, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->f0.u32l;
    // 0x8005D3C0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005D3C4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8005D3C8: swc1        $f12, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->f12.u32l;
    // 0x8005D3CC: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8005D3D0: add.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8005D3D4: swc1        $f2, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->f2.u32l;
    // 0x8005D3D8: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8005D3DC: swc1        $f14, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->f14.u32l;
    // 0x8005D3E0: div.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005D3E4: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005D3E8: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8005D3EC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005D3F0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8005D3F4: swc1        $f4, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->f4.u32l;
    // 0x8005D3F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D3FC: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8005D400: nop

    // 0x8005D404: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D408: bgez        $v0, L_8005D41C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005D40C: swc1        $f10, 0x2A8($sp)
        MEM_W(0X2A8, ctx->r29) = ctx->f10.u32l;
            goto L_8005D41C;
    }
    // 0x8005D40C: swc1        $f10, 0x2A8($sp)
    MEM_W(0X2A8, ctx->r29) = ctx->f10.u32l;
    // 0x8005D410: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005D414: nop

    // 0x8005D418: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8005D41C:
    // 0x8005D41C: bgez        $v1, L_8005D434
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005D420: swc1        $f8, 0x274($sp)
        MEM_W(0X274, ctx->r29) = ctx->f8.u32l;
            goto L_8005D434;
    }
    // 0x8005D420: swc1        $f8, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->f8.u32l;
    // 0x8005D424: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005D428: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005D42C: nop

    // 0x8005D430: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8005D434:
    // 0x8005D434: swc1        $f16, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->f16.u32l;
    // 0x8005D438: beq         $s0, $zero, L_8005D470
    if (ctx->r16 == 0) {
        // 0x8005D43C: swc1        $f16, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
            goto L_8005D470;
    }
    // 0x8005D43C: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8005D440: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005D444: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005D448: lwc1        $f6, 0x274($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X274));
    // 0x8005D44C: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8005D450: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8005D454: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8005D458: swc1        $f8, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->f8.u32l;
    // 0x8005D45C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005D460: nop

    // 0x8005D464: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005D468: b           L_8005D47C
    // 0x8005D46C: swc1        $f6, 0x25C($sp)
    MEM_W(0X25C, ctx->r29) = ctx->f6.u32l;
        goto L_8005D47C;
    // 0x8005D46C: swc1        $f6, 0x25C($sp)
    MEM_W(0X25C, ctx->r29) = ctx->f6.u32l;
L_8005D470:
    // 0x8005D470: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005D474: nop

    // 0x8005D478: swc1        $f10, 0x25C($sp)
    MEM_W(0X25C, ctx->r29) = ctx->f10.u32l;
L_8005D47C:
    // 0x8005D47C: lb          $t9, 0x262($sp)
    ctx->r25 = S32(MEM_B(ctx->r29, 0X262));
    // 0x8005D480: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005D484: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005D488: beq         $t9, $zero, L_8005D498
    if (ctx->r25 == 0) {
        // 0x8005D48C: lwc1        $f4, 0x2A8($sp)
        ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X2A8));
            goto L_8005D498;
    }
    // 0x8005D48C: lwc1        $f4, 0x2A8($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X2A8));
    // 0x8005D490: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8005D494: swc1        $f8, 0x2A8($sp)
    MEM_W(0X2A8, ctx->r29) = ctx->f8.u32l;
L_8005D498:
    // 0x8005D498: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X60));
    // 0x8005D49C: lb          $t6, 0x261($sp)
    ctx->r14 = S32(MEM_B(ctx->r29, 0X261));
    // 0x8005D4A0: lhu         $v0, 0x26E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X26E);
    // 0x8005D4A4: div.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8005D4A8: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X58));
    // 0x8005D4AC: lwc1        $f16, 0x2B8($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X2B8));
    // 0x8005D4B0: slti        $at, $v0, 0xE0A
    ctx->r1 = SIGNED(ctx->r2) < 0XE0A ? 1 : 0;
    // 0x8005D4B4: beq         $t6, $zero, L_8005DD80
    if (ctx->r14 == 0) {
        // 0x8005D4B8: swc1        $f4, 0x288($sp)
        MEM_W(0X288, ctx->r29) = ctx->f4.u32l;
            goto L_8005DD80;
    }
    // 0x8005D4B8: swc1        $f4, 0x288($sp)
    MEM_W(0X288, ctx->r29) = ctx->f4.u32l;
    // 0x8005D4BC: bne         $at, $zero, L_8005D4E4
    if (ctx->r1 != 0) {
        // 0x8005D4C0: addiu       $t7, $v0, -0xE5D
        ctx->r15 = ADD32(ctx->r2, -0XE5D);
            goto L_8005D4E4;
    }
    // 0x8005D4C0: addiu       $t7, $v0, -0xE5D
    ctx->r15 = ADD32(ctx->r2, -0XE5D);
    // 0x8005D4C4: sltiu       $at, $t7, 0x16
    ctx->r1 = ctx->r15 < 0X16 ? 1 : 0;
    // 0x8005D4C8: beq         $at, $zero, L_8005DC50
    if (ctx->r1 == 0) {
        // 0x8005D4CC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8005DC50;
    }
    // 0x8005D4CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005D4D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8005D4D4: addu        $at, $at, $t7
    gpr jr_addend_8005D4DC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005D4D8: lw          $t7, 0x4B74($at)
    ctx->r15 = ADD32(ctx->r1, 0X4B74);
    // 0x8005D4DC: jr          $t7
    // 0x8005D4E0: nop

    switch (jr_addend_8005D4DC >> 2) {
        case 0: goto L_8005DAF8; break;
        case 1: goto L_8005DC50; break;
        case 2: goto L_8005DC50; break;
        case 3: goto L_8005DC50; break;
        case 4: goto L_8005DC50; break;
        case 5: goto L_8005DC50; break;
        case 6: goto L_8005DC50; break;
        case 7: goto L_8005DC50; break;
        case 8: goto L_8005DC50; break;
        case 9: goto L_8005DC50; break;
        case 10: goto L_8005DC50; break;
        case 11: goto L_8005DBA4; break;
        case 12: goto L_8005DBA4; break;
        case 13: goto L_8005DC50; break;
        case 14: goto L_8005D598; break;
        case 15: goto L_8005D644; break;
        case 16: goto L_8005D6F0; break;
        case 17: goto L_8005D79C; break;
        case 18: goto L_8005D848; break;
        case 19: goto L_8005D8F4; break;
        case 20: goto L_8005D9A0; break;
        case 21: goto L_8005DA4C; break;
        default: switch_error(__func__, 0x8005D4DC, 0x80104B74);
    }
    // 0x8005D4E0: nop

L_8005D4E4:
    // 0x8005D4E4: addiu       $at, $zero, 0xE09
    ctx->r1 = ADD32(0, 0XE09);
    // 0x8005D4E8: bne         $v0, $at, L_8005DC50
    if (ctx->r2 != ctx->r1) {
        // 0x8005D4EC: lui         $t9, 0xFD10
        ctx->r25 = S32(0XFD10 << 16);
            goto L_8005DC50;
    }
    // 0x8005D4EC: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8005D4F0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D4F4: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8005D4F8: addiu       $t6, $t6, 0x210
    ctx->r14 = ADD32(ctx->r14, 0X210);
    // 0x8005D4FC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D500: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D504: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005D508: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D50C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D510: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8005D514: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8005D518: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D51C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D520: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D524: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D528: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D52C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8005D530: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8005D534: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D538: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D53C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005D540: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D544: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D548: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005D54C: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8005D550: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D554: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D558: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D55C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D560: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D564: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8005D568: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8005D56C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D570: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D574: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005D578: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D57C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D580: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005D584: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D588: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D58C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D590: b           L_8005DCF8
    // 0x8005D594: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_8005DCF8;
    // 0x8005D594: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8005D598:
    // 0x8005D598: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D59C: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x8005D5A0: addiu       $t9, $t9, 0x418
    ctx->r25 = ADD32(ctx->r25, 0X418);
    // 0x8005D5A4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D5A8: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D5AC: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8005D5B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D5B4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005D5B8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D5BC: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8005D5C0: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8005D5C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D5C8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D5CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D5D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D5D4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D5D8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8005D5DC: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8005D5E0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D5E4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D5E8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005D5EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D5F0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D5F4: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005D5F8: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8005D5FC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D600: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D604: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D608: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D60C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D610: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8005D614: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8005D618: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D61C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D620: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005D624: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D628: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D62C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005D630: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D634: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D638: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D63C: b           L_8005DCF8
    // 0x8005D640: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8005DCF8;
    // 0x8005D640: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8005D644:
    // 0x8005D644: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D648: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x8005D64C: addiu       $t8, $t8, 0x620
    ctx->r24 = ADD32(ctx->r24, 0X620);
    // 0x8005D650: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D654: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D658: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8005D65C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D660: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005D664: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D668: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8005D66C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8005D670: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D674: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D678: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D67C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D680: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D684: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8005D688: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8005D68C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D690: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D694: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005D698: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D69C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D6A0: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8005D6A4: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8005D6A8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D6AC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D6B0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D6B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D6B8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D6BC: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8005D6C0: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8005D6C4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D6C8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D6CC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005D6D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D6D4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D6D8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8005D6DC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D6E0: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D6E4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D6E8: b           L_8005DCF8
    // 0x8005D6EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8005DCF8;
    // 0x8005D6EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8005D6F0:
    // 0x8005D6F0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D6F4: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8005D6F8: addiu       $t7, $t7, 0x828
    ctx->r15 = ADD32(ctx->r15, 0X828);
    // 0x8005D6FC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D700: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D704: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8005D708: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D70C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005D710: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D714: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8005D718: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8005D71C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D720: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D724: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D728: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D72C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D730: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8005D734: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8005D738: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D73C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D740: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005D744: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D748: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D74C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8005D750: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8005D754: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D758: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D75C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D760: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D764: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D768: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8005D76C: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8005D770: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D774: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D778: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005D77C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D780: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D784: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005D788: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D78C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D790: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D794: b           L_8005DCF8
    // 0x8005D798: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8005DCF8;
    // 0x8005D798: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8005D79C:
    // 0x8005D79C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D7A0: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8005D7A4: addiu       $t6, $t6, 0xA30
    ctx->r14 = ADD32(ctx->r14, 0XA30);
    // 0x8005D7A8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D7AC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D7B0: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8005D7B4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D7B8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005D7BC: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D7C0: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8005D7C4: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8005D7C8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D7CC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D7D0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D7D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D7D8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D7DC: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8005D7E0: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8005D7E4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D7E8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D7EC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005D7F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D7F4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D7F8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005D7FC: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8005D800: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D804: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D808: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D80C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D810: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D814: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8005D818: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8005D81C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D820: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D824: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005D828: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D82C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D830: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005D834: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D838: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D83C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D840: b           L_8005DCF8
    // 0x8005D844: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_8005DCF8;
    // 0x8005D844: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8005D848:
    // 0x8005D848: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D84C: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x8005D850: addiu       $t9, $t9, 0xC38
    ctx->r25 = ADD32(ctx->r25, 0XC38);
    // 0x8005D854: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D858: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D85C: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8005D860: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D864: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005D868: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D86C: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8005D870: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8005D874: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D878: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D87C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D880: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D884: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D888: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8005D88C: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8005D890: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D894: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D898: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005D89C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D8A0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D8A4: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005D8A8: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8005D8AC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D8B0: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D8B4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D8B8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D8BC: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D8C0: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8005D8C4: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8005D8C8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D8CC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D8D0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005D8D4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D8D8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D8DC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005D8E0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D8E4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D8E8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D8EC: b           L_8005DCF8
    // 0x8005D8F0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8005DCF8;
    // 0x8005D8F0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8005D8F4:
    // 0x8005D8F4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D8F8: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x8005D8FC: addiu       $t8, $t8, 0xE40
    ctx->r24 = ADD32(ctx->r24, 0XE40);
    // 0x8005D900: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D904: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D908: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8005D90C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D910: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005D914: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D918: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8005D91C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8005D920: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D924: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D928: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D92C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D930: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D934: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8005D938: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8005D93C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D940: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D944: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005D948: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D94C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D950: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8005D954: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8005D958: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D95C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D960: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D964: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D968: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D96C: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8005D970: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8005D974: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D978: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D97C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005D980: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D984: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D988: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8005D98C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D990: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005D994: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D998: b           L_8005DCF8
    // 0x8005D99C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8005DCF8;
    // 0x8005D99C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8005D9A0:
    // 0x8005D9A0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D9A4: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8005D9A8: addiu       $t7, $t7, 0x1048
    ctx->r15 = ADD32(ctx->r15, 0X1048);
    // 0x8005D9AC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005D9B0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D9B4: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8005D9B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005D9BC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005D9C0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D9C4: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8005D9C8: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8005D9CC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005D9D0: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D9D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005D9D8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005D9DC: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D9E0: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8005D9E4: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8005D9E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D9EC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005D9F0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005D9F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D9F8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005D9FC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8005DA00: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8005DA04: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DA08: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DA0C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DA10: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DA14: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DA18: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8005DA1C: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8005DA20: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DA24: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DA28: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005DA2C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005DA30: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DA34: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005DA38: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DA3C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DA40: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DA44: b           L_8005DCF8
    // 0x8005DA48: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8005DCF8;
    // 0x8005DA48: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8005DA4C:
    // 0x8005DA4C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DA50: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8005DA54: addiu       $t6, $t6, 0x1250
    ctx->r14 = ADD32(ctx->r14, 0X1250);
    // 0x8005DA58: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DA5C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005DA60: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8005DA64: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005DA68: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005DA6C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DA70: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8005DA74: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8005DA78: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DA7C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DA80: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DA84: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005DA88: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DA8C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8005DA90: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8005DA94: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DA98: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DA9C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005DAA0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DAA4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DAA8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005DAAC: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8005DAB0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DAB4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005DAB8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DABC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005DAC0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DAC4: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8005DAC8: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8005DACC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DAD0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DAD4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005DAD8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005DADC: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DAE0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005DAE4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DAE8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DAEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DAF0: b           L_8005DCF8
    // 0x8005DAF4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_8005DCF8;
    // 0x8005DAF4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8005DAF8:
    // 0x8005DAF8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DAFC: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x8005DB00: addiu       $t9, $t9, 0x1458
    ctx->r25 = ADD32(ctx->r25, 0X1458);
    // 0x8005DB04: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DB08: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DB0C: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8005DB10: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005DB14: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005DB18: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DB1C: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8005DB20: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8005DB24: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DB28: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DB2C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DB30: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005DB34: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DB38: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8005DB3C: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8005DB40: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DB44: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005DB48: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005DB4C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005DB50: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DB54: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005DB58: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8005DB5C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DB60: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DB64: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DB68: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005DB6C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DB70: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8005DB74: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8005DB78: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DB7C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DB80: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005DB84: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DB88: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DB8C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005DB90: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DB94: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005DB98: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DB9C: b           L_8005DCF8
    // 0x8005DBA0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8005DCF8;
    // 0x8005DBA0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8005DBA4:
    // 0x8005DBA4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DBA8: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x8005DBAC: addiu       $t8, $t8, 0x1660
    ctx->r24 = ADD32(ctx->r24, 0X1660);
    // 0x8005DBB0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DBB4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DBB8: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8005DBBC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005DBC0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005DBC4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DBC8: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8005DBCC: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8005DBD0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DBD4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DBD8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DBDC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DBE0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DBE4: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8005DBE8: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8005DBEC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DBF0: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DBF4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005DBF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005DBFC: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DC00: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8005DC04: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8005DC08: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DC0C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DC10: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DC14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005DC18: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DC1C: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8005DC20: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8005DC24: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DC28: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005DC2C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005DC30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005DC34: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DC38: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8005DC3C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DC40: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DC44: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DC48: b           L_8005DCF8
    // 0x8005DC4C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8005DCF8;
    // 0x8005DC4C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8005DC50:
    // 0x8005DC50: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DC54: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8005DC58: addiu       $t7, $t7, 0x8
    ctx->r15 = ADD32(ctx->r15, 0X8);
    // 0x8005DC5C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DC60: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DC64: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8005DC68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DC6C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005DC70: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DC74: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8005DC78: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8005DC7C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DC80: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005DC84: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DC88: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005DC8C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DC90: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8005DC94: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8005DC98: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DC9C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DCA0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005DCA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005DCA8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DCAC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8005DCB0: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8005DCB4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DCB8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DCBC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DCC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DCC4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DCC8: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8005DCCC: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8005DCD0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DCD4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DCD8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005DCDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005DCE0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DCE4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005DCE8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DCEC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DCF0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DCF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8005DCF8:
    // 0x8005DCF8: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x8005DCFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005DD00: lwc1        $f6, 0x274($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X274));
    // 0x8005DD04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005DD08: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x8005DD0C: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8005DD10: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8005DD14: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8005DD18: nop

    // 0x8005DD1C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005DD20: nop

    // 0x8005DD24: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005DD28: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005DD2C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8005DD30: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005DD34: nop

    // 0x8005DD38: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8005DD3C: bne         $t8, $zero, L_8005DD50
    if (ctx->r24 != 0) {
        // 0x8005DD40: nop
    
            goto L_8005DD50;
    }
    // 0x8005DD40: nop

    // 0x8005DD44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005DD48: nop

    // 0x8005DD4C: sub.s       $f20, $f0, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f10.fl;
L_8005DD50:
    // 0x8005DD50: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8005DD54: swc1        $f14, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->f14.u32l;
    // 0x8005DD58: jal         0x80063880
    // 0x8005DD5C: swc1        $f16, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->f16.u32l;
    func_80063880(rdram, ctx);
        goto after_2;
    // 0x8005DD5C: swc1        $f16, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8005DD60: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005DD64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005DD68: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8005DD6C: addiu       $t1, $t1, 0x4418
    ctx->r9 = ADD32(ctx->r9, 0X4418);
    // 0x8005DD70: lwc1        $f14, 0x294($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X294));
    // 0x8005DD74: lwc1        $f16, 0x284($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X284));
    // 0x8005DD78: b           L_8005DECC
    // 0x8005DD7C: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
        goto L_8005DECC;
    // 0x8005DD7C: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
L_8005DD80:
    // 0x8005DD80: lw          $s0, 0x0($t1)
    ctx->r16 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DD84: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8005DD88: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x8005DD8C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x8005DD90: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DD94: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005DD98: swc1        $f16, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->f16.u32l;
    // 0x8005DD9C: jal         0x80063880
    // 0x8005DDA0: swc1        $f14, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->f14.u32l;
    func_80063880(rdram, ctx);
        goto after_3;
    // 0x8005DDA0: swc1        $f14, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8005DDA4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8005DDA8: lwc1        $f14, 0x294($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X294));
    // 0x8005DDAC: lwc1        $f16, 0x284($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X284));
    // 0x8005DDB0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8005DDB4: addiu       $t1, $t1, 0x4418
    ctx->r9 = ADD32(ctx->r9, 0X4418);
    // 0x8005DDB8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DDBC: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8005DDC0: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8005DDC4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DDC8: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DDCC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DDD0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005DDD4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DDD8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8005DDDC: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8005DDE0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DDE4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DDE8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005DDEC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DDF0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DDF4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005DDF8: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8005DDFC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DE00: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005DE04: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DE08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005DE0C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DE10: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x8005DE14: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8005DE18: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DE1C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DE20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005DE24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005DE28: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DE2C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005DE30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005DE34: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005DE38: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DE3C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005DE40: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x8005DE44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005DE48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005DE4C: lwc1        $f8, 0x274($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X274));
    // 0x8005DE50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005DE54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005DE58: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x8005DE5C: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005DE60: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8005DE64: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8005DE68: nop

    // 0x8005DE6C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8005DE70: nop

    // 0x8005DE74: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005DE78: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005DE7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8005DE80: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8005DE84: nop

    // 0x8005DE88: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8005DE8C: bne         $t7, $zero, L_8005DEA0
    if (ctx->r15 != 0) {
        // 0x8005DE90: nop
    
            goto L_8005DEA0;
    }
    // 0x8005DE90: nop

    // 0x8005DE94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005DE98: nop

    // 0x8005DE9C: sub.s       $f20, $f0, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f6.fl;
L_8005DEA0:
    // 0x8005DEA0: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8005DEA4: swc1        $f14, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->f14.u32l;
    // 0x8005DEA8: jal         0x80063880
    // 0x8005DEAC: swc1        $f16, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->f16.u32l;
    func_80063880(rdram, ctx);
        goto after_4;
    // 0x8005DEAC: swc1        $f16, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8005DEB0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005DEB4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8005DEB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005DEBC: addiu       $t1, $t1, 0x4418
    ctx->r9 = ADD32(ctx->r9, 0X4418);
    // 0x8005DEC0: lwc1        $f14, 0x294($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X294));
    // 0x8005DEC4: lwc1        $f16, 0x284($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X284));
    // 0x8005DEC8: addiu       $ra, $v0, 0x20
    ctx->r31 = ADD32(ctx->r2, 0X20);
L_8005DECC:
    // 0x8005DECC: lwc1        $f10, 0x288($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X288));
    // 0x8005DED0: lwc1        $f4, 0x270($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X270));
    // 0x8005DED4: lb          $t8, 0x262($sp)
    ctx->r24 = S32(MEM_B(ctx->r29, 0X262));
    // 0x8005DED8: mul.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8005DEDC: div.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005DEE0: lwc1        $f8, 0x274($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X274));
    // 0x8005DEE4: lwc1        $f4, 0x274($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X274));
    // 0x8005DEE8: beq         $t8, $zero, L_8005E690
    if (ctx->r24 == 0) {
        // 0x8005DEEC: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8005E690;
    }
    // 0x8005DEEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8005DEF0: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005DEF4: lwc1        $f10, 0x2B4($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X2B4));
    // 0x8005DEF8: lwc1        $f8, 0x2BC($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X2BC));
    // 0x8005DEFC: lwc1        $f16, 0x2B0($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X2B0));
    // 0x8005DF00: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8005DF04: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8005DF08: lwc1        $f10, 0x2AC($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X2AC));
    // 0x8005DF0C: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8005DF10: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005DF14: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005DF18: lwc1        $f8, 0x2A8($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X2A8));
    // 0x8005DF1C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8005DF20: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8005DF24: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8005DF28: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x8005DF2C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8005DF30: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005DF34: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8005DF38: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8005DF3C: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8005DF40: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x8005DF44: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8005DF48: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8005DF4C: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8005DF50: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8005DF54: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8005DF58: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8005DF5C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005DF60: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8005DF64: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8005DF68: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x8005DF6C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8005DF70: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8005DF74: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8005DF78: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
L_8005DF7C:
    // 0x8005DF7C: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8005DF80: lb          $t9, 0x261($sp)
    ctx->r25 = S32(MEM_B(ctx->r29, 0X261));
    // 0x8005DF84: bc1fl       L_8005DF98
    if (!c1cs) {
        // 0x8005DF88: mov.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
            goto L_8005DF98;
    }
    goto skip_2;
    // 0x8005DF88: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    skip_2:
    // 0x8005DF8C: b           L_8005DF98
    // 0x8005DF90: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_8005DF98;
    // 0x8005DF90: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8005DF94: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_8005DF98:
    // 0x8005DF98: sub.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8005DF9C: beq         $t9, $zero, L_8005E190
    if (ctx->r25 == 0) {
        // 0x8005DFA0: sub.s       $f14, $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f10.fl;
            goto L_8005E190;
    }
    // 0x8005DFA0: sub.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8005DFA4: div.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8005DFA8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DFAC: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x8005DFB0: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8005DFB4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005DFB8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005DFBC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005DFC0: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x8005DFC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005DFC8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DFCC: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8005DFD0: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005DFD4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005DFD8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005DFDC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005DFE0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005DFE4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005DFE8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005DFEC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005DFF0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005DFF4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005DFF8: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005DFFC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005E000: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E004: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E008: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005E00C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E010: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8005E014: addiu       $t5, $a2, 0x7
    ctx->r13 = ADD32(ctx->r6, 0X7);
    // 0x8005E018: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E01C: multu       $s0, $t3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E020: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E024: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8005E028: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005E02C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005E030: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x8005E034: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8005E038: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    // 0x8005E03C: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8005E040: mflo        $t0
    ctx->r8 = lo;
    // 0x8005E044: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005E048: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005E04C: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8005E050: bgez        $a2, L_8005E060
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8005E054: sra         $a3, $a2, 3
        ctx->r7 = S32(SIGNED(ctx->r6) >> 3);
            goto L_8005E060;
    }
    // 0x8005E054: sra         $a3, $a2, 3
    ctx->r7 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8005E058: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x8005E05C: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_8005E060:
    // 0x8005E060: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005E064: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8005E068: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8005E06C: beq         $at, $zero, L_8005E07C
    if (ctx->r1 == 0) {
        // 0x8005E070: or          $t5, $t8, $zero
        ctx->r13 = ctx->r24 | 0;
            goto L_8005E07C;
    }
    // 0x8005E070: or          $t5, $t8, $zero
    ctx->r13 = ctx->r24 | 0;
    // 0x8005E074: b           L_8005E07C
    // 0x8005E078: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
        goto L_8005E07C;
    // 0x8005E078: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_8005E07C:
    // 0x8005E07C: bgtz        $a3, L_8005E08C
    if (SIGNED(ctx->r7) > 0) {
        // 0x8005E080: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_8005E08C;
    }
    // 0x8005E080: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8005E084: b           L_8005E08C
    // 0x8005E088: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8005E08C;
    // 0x8005E088: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8005E08C:
    // 0x8005E08C: bgtz        $a3, L_8005E09C
    if (SIGNED(ctx->r7) > 0) {
        // 0x8005E090: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8005E09C;
    }
    // 0x8005E090: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8005E094: b           L_8005E0A0
    // 0x8005E098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005E0A0;
    // 0x8005E098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E09C:
    // 0x8005E09C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8005E0A0:
    // 0x8005E0A0: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x8005E0A4: bne         $v0, $zero, L_8005E0B0
    if (ctx->r2 != 0) {
        // 0x8005E0A8: nop
    
            goto L_8005E0B0;
    }
    // 0x8005E0A8: nop

    // 0x8005E0AC: break       7
    do_break(2147868844);
L_8005E0B0:
    // 0x8005E0B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005E0B4: bne         $v0, $at, L_8005E0C8
    if (ctx->r2 != ctx->r1) {
        // 0x8005E0B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005E0C8;
    }
    // 0x8005E0B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E0BC: bne         $t9, $at, L_8005E0C8
    if (ctx->r25 != ctx->r1) {
        // 0x8005E0C0: nop
    
            goto L_8005E0C8;
    }
    // 0x8005E0C0: nop

    // 0x8005E0C4: break       6
    do_break(2147868868);
L_8005E0C8:
    // 0x8005E0C8: mflo        $t6
    ctx->r14 = lo;
    // 0x8005E0CC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8005E0D0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005E0D4: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x8005E0D8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8005E0DC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8005E0E0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8005E0E4: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8005E0E8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E0EC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8005E0F0: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8005E0F4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E0F8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E0FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E100: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005E104: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005E108: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E10C: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8005E110: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E114: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005E118: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E11C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005E120: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8005E124: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005E128: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E12C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005E130: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8005E134: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E138: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8005E13C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E140: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005E144: lw          $t6, 0x44($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8005E148: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x8005E14C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8005E150: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005E154: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8005E158: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8005E15C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005E160: lhu         $t9, 0x12($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X12);
    // 0x8005E164: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8005E168: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8005E16C: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E170: mflo        $t7
    ctx->r15 = lo;
    // 0x8005E174: bgez        $t7, L_8005E184
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005E178: sra         $t6, $t7, 2
        ctx->r14 = S32(SIGNED(ctx->r15) >> 2);
            goto L_8005E184;
    }
    // 0x8005E178: sra         $t6, $t7, 2
    ctx->r14 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8005E17C: addiu       $at, $t7, 0x3
    ctx->r1 = ADD32(ctx->r15, 0X3);
    // 0x8005E180: sra         $t6, $at, 2
    ctx->r14 = S32(SIGNED(ctx->r1) >> 2);
L_8005E184:
    // 0x8005E184: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8005E188: b           L_8005E388
    // 0x8005E18C: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
        goto L_8005E388;
    // 0x8005E18C: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
L_8005E190:
    // 0x8005E190: div.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8005E194: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E198: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x8005E19C: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8005E1A0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005E1A4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005E1A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005E1AC: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x8005E1B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005E1B4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E1B8: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x8005E1BC: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8005E1C0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005E1C4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E1C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005E1CC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005E1D0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005E1D4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E1D8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8005E1DC: sra         $t5, $s0, 1
    ctx->r13 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8005E1E0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005E1E4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005E1E8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005E1EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005E1F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E1F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005E1F8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E1FC: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8005E200: addiu       $t5, $t5, 0x7
    ctx->r13 = ADD32(ctx->r13, 0X7);
    // 0x8005E204: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E208: multu       $s0, $t3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E20C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E210: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8005E214: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005E218: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005E21C: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8005E220: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8005E224: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    // 0x8005E228: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8005E22C: mflo        $a3
    ctx->r7 = lo;
    // 0x8005E230: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x8005E234: sra         $t6, $a3, 2
    ctx->r14 = S32(SIGNED(ctx->r7) >> 2);
    // 0x8005E238: addiu       $a3, $t6, -0x1
    ctx->r7 = ADD32(ctx->r14, -0X1);
    // 0x8005E23C: bgez        $s0, L_8005E24C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8005E240: sra         $a2, $s0, 4
        ctx->r6 = S32(SIGNED(ctx->r16) >> 4);
            goto L_8005E24C;
    }
    // 0x8005E240: sra         $a2, $s0, 4
    ctx->r6 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8005E244: addiu       $at, $s0, 0xF
    ctx->r1 = ADD32(ctx->r16, 0XF);
    // 0x8005E248: sra         $a2, $at, 4
    ctx->r6 = S32(SIGNED(ctx->r1) >> 4);
L_8005E24C:
    // 0x8005E24C: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8005E250: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8005E254: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8005E258: beq         $at, $zero, L_8005E268
    if (ctx->r1 == 0) {
        // 0x8005E25C: or          $t5, $t6, $zero
        ctx->r13 = ctx->r14 | 0;
            goto L_8005E268;
    }
    // 0x8005E25C: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8005E260: b           L_8005E268
    // 0x8005E264: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
        goto L_8005E268;
    // 0x8005E264: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
L_8005E268:
    // 0x8005E268: bgtz        $a2, L_8005E278
    if (SIGNED(ctx->r6) > 0) {
        // 0x8005E26C: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_8005E278;
    }
    // 0x8005E26C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8005E270: b           L_8005E278
    // 0x8005E274: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8005E278;
    // 0x8005E274: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8005E278:
    // 0x8005E278: bgtz        $a2, L_8005E288
    if (SIGNED(ctx->r6) > 0) {
        // 0x8005E27C: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8005E288;
    }
    // 0x8005E27C: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8005E280: b           L_8005E28C
    // 0x8005E284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005E28C;
    // 0x8005E284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E288:
    // 0x8005E288: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8005E28C:
    // 0x8005E28C: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x8005E290: bne         $v0, $zero, L_8005E29C
    if (ctx->r2 != 0) {
        // 0x8005E294: nop
    
            goto L_8005E29C;
    }
    // 0x8005E294: nop

    // 0x8005E298: break       7
    do_break(2147869336);
L_8005E29C:
    // 0x8005E29C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005E2A0: bne         $v0, $at, L_8005E2B4
    if (ctx->r2 != ctx->r1) {
        // 0x8005E2A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005E2B4;
    }
    // 0x8005E2A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E2A8: bne         $t9, $at, L_8005E2B4
    if (ctx->r25 != ctx->r1) {
        // 0x8005E2AC: nop
    
            goto L_8005E2B4;
    }
    // 0x8005E2AC: nop

    // 0x8005E2B0: break       6
    do_break(2147869360);
L_8005E2B4:
    // 0x8005E2B4: mflo        $t8
    ctx->r24 = lo;
    // 0x8005E2B8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8005E2BC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005E2C0: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x8005E2C4: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8005E2C8: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8005E2CC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8005E2D0: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8005E2D4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E2D8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005E2DC: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8005E2E0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E2E4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E2E8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E2EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005E2F0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005E2F4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E2F8: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8005E2FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E300: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005E304: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005E308: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005E30C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8005E310: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005E314: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E318: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005E31C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8005E320: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E324: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8005E328: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E32C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005E330: lw          $t8, 0x44($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8005E334: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x8005E338: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8005E33C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005E340: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8005E344: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8005E348: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005E34C: lhu         $t9, 0x12($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X12);
    // 0x8005E350: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8005E354: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8005E358: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E35C: mflo        $t7
    ctx->r15 = lo;
    // 0x8005E360: bgez        $t7, L_8005E370
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005E364: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8005E370;
    }
    // 0x8005E364: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005E368: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8005E36C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8005E370:
    // 0x8005E370: bgez        $t8, L_8005E380
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005E374: sra         $t9, $t8, 2
        ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
            goto L_8005E380;
    }
    // 0x8005E374: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8005E378: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x8005E37C: sra         $t9, $at, 2
    ctx->r25 = S32(SIGNED(ctx->r1) >> 2);
L_8005E380:
    // 0x8005E380: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8005E384: addu        $ra, $ra, $t6
    ctx->r31 = ADD32(ctx->r31, ctx->r14);
L_8005E388:
    // 0x8005E388: lw          $a1, 0x0($t1)
    ctx->r5 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E38C: lw          $t8, 0x40($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8005E390: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005E394: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x8005E398: blez        $t8, L_8005E3A8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005E39C: sw          $t7, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r15;
            goto L_8005E3A8;
    }
    // 0x8005E39C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005E3A0: b           L_8005E3AC
    // 0x8005E3A4: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
        goto L_8005E3AC;
    // 0x8005E3A4: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_8005E3A8:
    // 0x8005E3A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8005E3AC:
    // 0x8005E3AC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8005E3B0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8005E3B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E3B8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8005E3BC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005E3C0: blez        $t7, L_8005E3D0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005E3C4: andi        $t6, $t0, 0xFFF
        ctx->r14 = ctx->r8 & 0XFFF;
            goto L_8005E3D0;
    }
    // 0x8005E3C4: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x8005E3C8: b           L_8005E3D0
    // 0x8005E3CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8005E3D0;
    // 0x8005E3CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8005E3D0:
    // 0x8005E3D0: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8005E3D4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8005E3D8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8005E3DC: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8005E3E0: blez        $s1, L_8005E3F0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8005E3E4: sw          $t8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r24;
            goto L_8005E3F0;
    }
    // 0x8005E3E4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8005E3E8: b           L_8005E3F4
    // 0x8005E3EC: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
        goto L_8005E3F4;
    // 0x8005E3EC: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
L_8005E3F0:
    // 0x8005E3F0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8005E3F4:
    // 0x8005E3F4: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X68));
    // 0x8005E3F8: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x8005E3FC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8005E400: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8005E404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E408: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8005E40C: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8005E410: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8005E414: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8005E418: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8005E41C: nop

    // 0x8005E420: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8005E424: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8005E428: blez        $t7, L_8005E438
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005E42C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8005E438;
    }
    // 0x8005E42C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8005E430: b           L_8005E438
    // 0x8005E434: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8005E438;
    // 0x8005E434: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8005E438:
    // 0x8005E438: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8005E43C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8005E440: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8005E444: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8005E448: lw          $a2, 0x0($t1)
    ctx->r6 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E44C: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x8005E450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005E454: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x8005E458: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E45C: bgez        $s1, L_8005E4B0
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8005E460: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_8005E4B0;
    }
    // 0x8005E460: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8005E464: lw          $t9, 0x38($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8005E468: multu       $s1, $t9
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E46C: mflo        $v0
    ctx->r2 = lo;
    // 0x8005E470: sra         $t7, $v0, 7
    ctx->r15 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005E474: bgez        $t9, L_8005E494
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005E478: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8005E494;
    }
    // 0x8005E478: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8005E47C: blez        $t7, L_8005E48C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005E480: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005E48C;
    }
    // 0x8005E480: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005E484: b           L_8005E4B0
    // 0x8005E488: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_8005E4B0;
    // 0x8005E488: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8005E48C:
    // 0x8005E48C: b           L_8005E4B0
    // 0x8005E490: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8005E4B0;
    // 0x8005E490: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8005E494:
    // 0x8005E494: bgez        $v0, L_8005E4A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005E498: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005E4A4;
    }
    // 0x8005E498: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005E49C: b           L_8005E4A4
    // 0x8005E4A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8005E4A4;
    // 0x8005E4A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8005E4A4:
    // 0x8005E4A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005E4A8: b           L_8005E4B0
    // 0x8005E4AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8005E4B0;
    // 0x8005E4AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8005E4B0:
    // 0x8005E4B0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8005E4B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E4B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8005E4BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E4C0: bc1f        L_8005E524
    if (!c1cs) {
        // 0x8005E4C4: sub.s       $f6, $f2, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8005E524;
    }
    // 0x8005E4C4: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005E4C8: bgez        $s2, L_8005E4F8
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8005E4CC: nop
    
            goto L_8005E4F8;
    }
    // 0x8005E4CC: nop

    // 0x8005E4D0: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E4D4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005E4D8: mflo        $v0
    ctx->r2 = lo;
    // 0x8005E4DC: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005E4E0: blez        $t6, L_8005E4F0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005E4E4: nop
    
            goto L_8005E4F0;
    }
    // 0x8005E4E4: nop

    // 0x8005E4E8: b           L_8005E524
    // 0x8005E4EC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8005E524;
    // 0x8005E4EC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8005E4F0:
    // 0x8005E4F0: b           L_8005E524
    // 0x8005E4F4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8005E524;
    // 0x8005E4F4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8005E4F8:
    // 0x8005E4F8: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E4FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005E500: mflo        $v0
    ctx->r2 = lo;
    // 0x8005E504: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005E508: bgez        $t8, L_8005E518
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005E50C: nop
    
            goto L_8005E518;
    }
    // 0x8005E50C: nop

    // 0x8005E510: b           L_8005E518
    // 0x8005E514: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8005E518;
    // 0x8005E514: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8005E518:
    // 0x8005E518: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8005E51C: b           L_8005E524
    // 0x8005E520: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8005E524;
    // 0x8005E520: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8005E524:
    // 0x8005E524: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8005E528: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005E52C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8005E530: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005E534: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8005E538: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005E53C: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8005E540: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005E544: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8005E548: nop

    // 0x8005E54C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005E550: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8005E554: nop

    // 0x8005E558: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8005E55C: beql        $t9, $zero, L_8005E5AC
    if (ctx->r25 == 0) {
        // 0x8005E560: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_8005E5AC;
    }
    goto skip_3;
    // 0x8005E560: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x8005E564: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005E568: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005E56C: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005E570: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8005E574: nop

    // 0x8005E578: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005E57C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8005E580: nop

    // 0x8005E584: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8005E588: bne         $t9, $zero, L_8005E5A0
    if (ctx->r25 != 0) {
        // 0x8005E58C: nop
    
            goto L_8005E5A0;
    }
    // 0x8005E58C: nop

    // 0x8005E590: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8005E594: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E598: b           L_8005E5B8
    // 0x8005E59C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8005E5B8;
    // 0x8005E59C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8005E5A0:
    // 0x8005E5A0: b           L_8005E5B8
    // 0x8005E5A4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8005E5B8;
    // 0x8005E5A4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8005E5A8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_8005E5AC:
    // 0x8005E5AC: nop

    // 0x8005E5B0: bltz        $t9, L_8005E5A0
    if (SIGNED(ctx->r25) < 0) {
        // 0x8005E5B4: nop
    
            goto L_8005E5A0;
    }
    // 0x8005E5B4: nop

L_8005E5B8:
    // 0x8005E5B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005E5BC: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x8005E5C0: lwc1        $f4, 0x25C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X25C));
    // 0x8005E5C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005E5C8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005E5CC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8005E5D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8005E5D4: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005E5D8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8005E5DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005E5E0: nop

    // 0x8005E5E4: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005E5E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005E5EC: nop

    // 0x8005E5F0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8005E5F4: beql        $t7, $zero, L_8005E644
    if (ctx->r15 == 0) {
        // 0x8005E5F8: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_8005E644;
    }
    goto skip_4;
    // 0x8005E5F8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x8005E5FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005E600: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005E604: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8005E608: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005E60C: nop

    // 0x8005E610: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8005E614: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005E618: nop

    // 0x8005E61C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8005E620: bne         $t7, $zero, L_8005E638
    if (ctx->r15 != 0) {
        // 0x8005E624: nop
    
            goto L_8005E638;
    }
    // 0x8005E624: nop

    // 0x8005E628: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8005E62C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E630: b           L_8005E650
    // 0x8005E634: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8005E650;
    // 0x8005E634: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8005E638:
    // 0x8005E638: b           L_8005E650
    // 0x8005E63C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8005E650;
    // 0x8005E63C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005E640: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_8005E644:
    // 0x8005E644: nop

    // 0x8005E648: bltz        $t7, L_8005E638
    if (SIGNED(ctx->r15) < 0) {
        // 0x8005E64C: nop
    
            goto L_8005E638;
    }
    // 0x8005E64C: nop

L_8005E650:
    // 0x8005E650: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005E654: or          $t9, $t7, $zero
    ctx->r25 = ctx->r15 | 0;
    // 0x8005E658: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8005E65C: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8005E660: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8005E664: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E668: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    // 0x8005E66C: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x8005E670: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E674: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E678: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005E67C: lw          $t8, 0x30($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8005E680: bc1t        L_8005EE20
    if (c1cs) {
        // 0x8005E684: sw          $t8, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r24;
            goto L_8005EE20;
    }
    // 0x8005E684: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005E688: b           L_8005DF7C
    // 0x8005E68C: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
        goto L_8005DF7C;
    // 0x8005E68C: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_8005E690:
    // 0x8005E690: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005E694: lwc1        $f6, 0x2B4($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X2B4));
    // 0x8005E698: lwc1        $f4, 0x2BC($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X2BC));
    // 0x8005E69C: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x8005E6A0: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8005E6A4: lwc1        $f6, 0x2AC($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X2AC));
    // 0x8005E6A8: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8005E6AC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005E6B0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8005E6B4: lwc1        $f4, 0x2A8($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X2A8));
    // 0x8005E6B8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8005E6BC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8005E6C0: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8005E6C4: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x8005E6C8: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8005E6CC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005E6D0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8005E6D4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8005E6D8: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8005E6DC: mfc1        $s2, $f8
    ctx->r18 = (int32_t)ctx->f8.u32l;
    // 0x8005E6E0: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005E6E4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8005E6E8: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8005E6EC: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8005E6F0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8005E6F4: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x8005E6F8: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8005E6FC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005E700: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8005E704: andi        $t6, $s2, 0xFFFF
    ctx->r14 = ctx->r18 & 0XFFFF;
    // 0x8005E708: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8005E70C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8005E710: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_8005E714:
    // 0x8005E714: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8005E718: lb          $t7, 0x261($sp)
    ctx->r15 = S32(MEM_B(ctx->r29, 0X261));
    // 0x8005E71C: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8005E720: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8005E724: bc1f        L_8005E734
    if (!c1cs) {
        // 0x8005E728: sra         $t5, $s0, 1
        ctx->r13 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8005E734;
    }
    // 0x8005E728: sra         $t5, $s0, 1
    ctx->r13 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8005E72C: b           L_8005E738
    // 0x8005E730: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_8005E738;
    // 0x8005E730: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8005E734:
    // 0x8005E734: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_8005E738:
    // 0x8005E738: sub.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8005E73C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8005E740: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005E744: beq         $t7, $zero, L_8005E938
    if (ctx->r15 == 0) {
        // 0x8005E748: sub.s       $f14, $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
            goto L_8005E938;
    }
    // 0x8005E748: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8005E74C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E750: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8005E754: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8005E758: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E75C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E760: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005E764: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x8005E768: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005E76C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E770: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x8005E774: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8005E778: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005E77C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005E780: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005E784: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005E788: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005E78C: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E790: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8005E794: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005E798: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005E79C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E7A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005E7A4: sra         $t8, $t3, 2
    ctx->r24 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8005E7A8: multu       $s0, $t8
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E7AC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E7B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005E7B4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E7B8: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8005E7BC: addiu       $t5, $a2, 0x7
    ctx->r13 = ADD32(ctx->r6, 0X7);
    // 0x8005E7C0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005E7C4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005E7C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005E7CC: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005E7D0: mflo        $t0
    ctx->r8 = lo;
    // 0x8005E7D4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005E7D8: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005E7DC: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x8005E7E0: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x8005E7E4: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8005E7E8: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8005E7EC: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8005E7F0: bgez        $a2, L_8005E800
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8005E7F4: sra         $a3, $a2, 3
        ctx->r7 = S32(SIGNED(ctx->r6) >> 3);
            goto L_8005E800;
    }
    // 0x8005E7F4: sra         $a3, $a2, 3
    ctx->r7 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8005E7F8: addiu       $at, $a2, 0x7
    ctx->r1 = ADD32(ctx->r6, 0X7);
    // 0x8005E7FC: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_8005E800:
    // 0x8005E800: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005E804: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8005E808: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8005E80C: beq         $at, $zero, L_8005E81C
    if (ctx->r1 == 0) {
        // 0x8005E810: or          $t5, $t7, $zero
        ctx->r13 = ctx->r15 | 0;
            goto L_8005E81C;
    }
    // 0x8005E810: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x8005E814: b           L_8005E820
    // 0x8005E818: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
        goto L_8005E820;
    // 0x8005E818: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_8005E81C:
    // 0x8005E81C: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
L_8005E820:
    // 0x8005E820: bgtz        $a3, L_8005E830
    if (SIGNED(ctx->r7) > 0) {
        // 0x8005E824: div.s       $f0, $f2, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
            goto L_8005E830;
    }
    // 0x8005E824: div.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8005E828: b           L_8005E834
    // 0x8005E82C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8005E834;
    // 0x8005E82C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8005E830:
    // 0x8005E830: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_8005E834:
    // 0x8005E834: bgtz        $a3, L_8005E844
    if (SIGNED(ctx->r7) > 0) {
        // 0x8005E838: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8005E844;
    }
    // 0x8005E838: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8005E83C: b           L_8005E848
    // 0x8005E840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005E848;
    // 0x8005E840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005E844:
    // 0x8005E844: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8005E848:
    // 0x8005E848: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x8005E84C: bne         $v0, $zero, L_8005E858
    if (ctx->r2 != 0) {
        // 0x8005E850: nop
    
            goto L_8005E858;
    }
    // 0x8005E850: nop

    // 0x8005E854: break       7
    do_break(2147870804);
L_8005E858:
    // 0x8005E858: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005E85C: bne         $v0, $at, L_8005E870
    if (ctx->r2 != ctx->r1) {
        // 0x8005E860: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005E870;
    }
    // 0x8005E860: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E864: bne         $t9, $at, L_8005E870
    if (ctx->r25 != ctx->r1) {
        // 0x8005E868: nop
    
            goto L_8005E870;
    }
    // 0x8005E868: nop

    // 0x8005E86C: break       6
    do_break(2147870828);
L_8005E870:
    // 0x8005E870: mflo        $t6
    ctx->r14 = lo;
    // 0x8005E874: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8005E878: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005E87C: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x8005E880: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8005E884: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8005E888: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8005E88C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8005E890: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E894: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005E898: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8005E89C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E8A0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E8A4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E8A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005E8AC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005E8B0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E8B4: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8005E8B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E8BC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005E8C0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E8C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005E8C8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8005E8CC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005E8D0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E8D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005E8D8: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8005E8DC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E8E0: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005E8E4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E8E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005E8EC: lw          $t6, 0x44($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8005E8F0: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x8005E8F4: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005E8F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005E8FC: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8005E900: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8005E904: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005E908: lhu         $t9, 0x12($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X12);
    // 0x8005E90C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005E910: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8005E914: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E918: mflo        $t8
    ctx->r24 = lo;
    // 0x8005E91C: bgez        $t8, L_8005E92C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005E920: sra         $t6, $t8, 2
        ctx->r14 = S32(SIGNED(ctx->r24) >> 2);
            goto L_8005E92C;
    }
    // 0x8005E920: sra         $t6, $t8, 2
    ctx->r14 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8005E924: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x8005E928: sra         $t6, $at, 2
    ctx->r14 = S32(SIGNED(ctx->r1) >> 2);
L_8005E92C:
    // 0x8005E92C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8005E930: b           L_8005EB2C
    // 0x8005E934: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
        goto L_8005EB2C;
    // 0x8005E934: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
L_8005E938:
    // 0x8005E938: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E93C: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8005E940: addiu       $t5, $t5, 0x7
    ctx->r13 = ADD32(ctx->r13, 0X7);
    // 0x8005E944: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005E948: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005E94C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005E950: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x8005E954: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005E958: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E95C: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x8005E960: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8005E964: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005E968: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E96C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005E970: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005E974: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005E978: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E97C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8005E980: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8005E984: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005E988: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005E98C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005E990: sra         $t6, $t3, 2
    ctx->r14 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8005E994: multu       $s0, $t6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E998: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005E99C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005E9A0: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005E9A4: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8005E9A8: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x8005E9AC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005E9B0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E9B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005E9B8: sra         $t7, $t5, 3
    ctx->r15 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005E9BC: mflo        $a3
    ctx->r7 = lo;
    // 0x8005E9C0: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x8005E9C4: sra         $t9, $a3, 2
    ctx->r25 = S32(SIGNED(ctx->r7) >> 2);
    // 0x8005E9C8: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8005E9CC: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x8005E9D0: addiu       $a3, $t9, -0x1
    ctx->r7 = ADD32(ctx->r25, -0X1);
    // 0x8005E9D4: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8005E9D8: bgez        $s0, L_8005E9E8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8005E9DC: sra         $a2, $s0, 4
        ctx->r6 = S32(SIGNED(ctx->r16) >> 4);
            goto L_8005E9E8;
    }
    // 0x8005E9DC: sra         $a2, $s0, 4
    ctx->r6 = S32(SIGNED(ctx->r16) >> 4);
    // 0x8005E9E0: addiu       $at, $s0, 0xF
    ctx->r1 = ADD32(ctx->r16, 0XF);
    // 0x8005E9E4: sra         $a2, $at, 4
    ctx->r6 = S32(SIGNED(ctx->r1) >> 4);
L_8005E9E8:
    // 0x8005E9E8: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8005E9EC: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005E9F0: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x8005E9F4: beq         $at, $zero, L_8005EA04
    if (ctx->r1 == 0) {
        // 0x8005E9F8: or          $t5, $t9, $zero
        ctx->r13 = ctx->r25 | 0;
            goto L_8005EA04;
    }
    // 0x8005E9F8: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x8005E9FC: b           L_8005EA08
    // 0x8005EA00: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
        goto L_8005EA08;
    // 0x8005EA00: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
L_8005EA04:
    // 0x8005EA04: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
L_8005EA08:
    // 0x8005EA08: bgtz        $a2, L_8005EA18
    if (SIGNED(ctx->r6) > 0) {
        // 0x8005EA0C: div.s       $f0, $f2, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
            goto L_8005EA18;
    }
    // 0x8005EA0C: div.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8005EA10: b           L_8005EA1C
    // 0x8005EA14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8005EA1C;
    // 0x8005EA14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8005EA18:
    // 0x8005EA18: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_8005EA1C:
    // 0x8005EA1C: bgtz        $a2, L_8005EA2C
    if (SIGNED(ctx->r6) > 0) {
        // 0x8005EA20: addiu       $t7, $t0, 0x7FF
        ctx->r15 = ADD32(ctx->r8, 0X7FF);
            goto L_8005EA2C;
    }
    // 0x8005EA20: addiu       $t7, $t0, 0x7FF
    ctx->r15 = ADD32(ctx->r8, 0X7FF);
    // 0x8005EA24: b           L_8005EA30
    // 0x8005EA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005EA30;
    // 0x8005EA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005EA2C:
    // 0x8005EA2C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8005EA30:
    // 0x8005EA30: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x8005EA34: bne         $v0, $zero, L_8005EA40
    if (ctx->r2 != 0) {
        // 0x8005EA38: nop
    
            goto L_8005EA40;
    }
    // 0x8005EA38: nop

    // 0x8005EA3C: break       7
    do_break(2147871292);
L_8005EA40:
    // 0x8005EA40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005EA44: bne         $v0, $at, L_8005EA58
    if (ctx->r2 != ctx->r1) {
        // 0x8005EA48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005EA58;
    }
    // 0x8005EA48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005EA4C: bne         $t7, $at, L_8005EA58
    if (ctx->r15 != ctx->r1) {
        // 0x8005EA50: nop
    
            goto L_8005EA58;
    }
    // 0x8005EA50: nop

    // 0x8005EA54: break       6
    do_break(2147871316);
L_8005EA58:
    // 0x8005EA58: mflo        $t8
    ctx->r24 = lo;
    // 0x8005EA5C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8005EA60: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005EA64: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x8005EA68: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8005EA6C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005EA70: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8005EA74: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8005EA78: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005EA7C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005EA80: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8005EA84: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005EA88: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005EA8C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005EA90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005EA94: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005EA98: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005EA9C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005EAA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005EAA4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005EAA8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005EAAC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005EAB0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8005EAB4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005EAB8: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005EABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005EAC0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8005EAC4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005EAC8: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005EACC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005EAD0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005EAD4: lw          $t8, 0x44($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8005EAD8: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x8005EADC: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005EAE0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005EAE4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8005EAE8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8005EAEC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005EAF0: lhu         $t7, 0x12($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X12);
    // 0x8005EAF4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8005EAF8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8005EAFC: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005EB00: mflo        $t6
    ctx->r14 = lo;
    // 0x8005EB04: bgez        $t6, L_8005EB14
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005EB08: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8005EB14;
    }
    // 0x8005EB08: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8005EB0C: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8005EB10: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8005EB14:
    // 0x8005EB14: bgez        $t8, L_8005EB24
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005EB18: sra         $t7, $t8, 2
        ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
            goto L_8005EB24;
    }
    // 0x8005EB18: sra         $t7, $t8, 2
    ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8005EB1C: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x8005EB20: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_8005EB24:
    // 0x8005EB24: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005EB28: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
L_8005EB2C:
    // 0x8005EB2C: lw          $a1, 0x0($t1)
    ctx->r5 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005EB30: lw          $t8, 0x40($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8005EB34: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8005EB38: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8005EB3C: blez        $t8, L_8005EB4C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005EB40: sw          $t6, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r14;
            goto L_8005EB4C;
    }
    // 0x8005EB40: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005EB44: b           L_8005EB50
    // 0x8005EB48: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
        goto L_8005EB50;
    // 0x8005EB48: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_8005EB4C:
    // 0x8005EB4C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8005EB50:
    // 0x8005EB50: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8005EB54: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005EB58: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8005EB5C: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005EB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005EB64: add.s       $f2, $f4, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8005EB68: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8005EB6C: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8005EB70: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8005EB74: nop

    // 0x8005EB78: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8005EB7C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8005EB80: blez        $t6, L_8005EB90
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005EB84: andi        $t9, $t0, 0xFFF
        ctx->r25 = ctx->r8 & 0XFFF;
            goto L_8005EB90;
    }
    // 0x8005EB84: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x8005EB88: b           L_8005EB90
    // 0x8005EB8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8005EB90;
    // 0x8005EB8C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8005EB90:
    // 0x8005EB90: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8005EB94: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8005EB98: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8005EB9C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8005EBA0: blez        $s1, L_8005EBB0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8005EBA4: sw          $t8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r24;
            goto L_8005EBB0;
    }
    // 0x8005EBA4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8005EBA8: b           L_8005EBB4
    // 0x8005EBAC: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
        goto L_8005EBB4;
    // 0x8005EBAC: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
L_8005EBB0:
    // 0x8005EBB0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8005EBB4:
    // 0x8005EBB4: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8005EBB8: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8005EBBC: blez        $t6, L_8005EBCC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005EBC0: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_8005EBCC;
    }
    // 0x8005EBC0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8005EBC4: b           L_8005EBD0
    // 0x8005EBC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8005EBD0;
    // 0x8005EBC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8005EBCC:
    // 0x8005EBCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005EBD0:
    // 0x8005EBD0: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x8005EBD4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8005EBD8: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8005EBDC: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x8005EBE0: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8005EBE4: lw          $a2, 0x0($t1)
    ctx->r6 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005EBE8: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x8005EBEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005EBF0: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x8005EBF4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005EBF8: bgez        $s1, L_8005EC4C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8005EBFC: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_8005EC4C;
    }
    // 0x8005EBFC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8005EC00: lw          $t7, 0x38($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8005EC04: multu       $s1, $t7
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005EC08: mflo        $v0
    ctx->r2 = lo;
    // 0x8005EC0C: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005EC10: bgez        $t7, L_8005EC30
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005EC14: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8005EC30;
    }
    // 0x8005EC14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8005EC18: blez        $t6, L_8005EC28
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005EC1C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005EC28;
    }
    // 0x8005EC1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005EC20: b           L_8005EC4C
    // 0x8005EC24: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
        goto L_8005EC4C;
    // 0x8005EC24: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_8005EC28:
    // 0x8005EC28: b           L_8005EC4C
    // 0x8005EC2C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8005EC4C;
    // 0x8005EC2C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8005EC30:
    // 0x8005EC30: bgez        $v0, L_8005EC40
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005EC34: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005EC40;
    }
    // 0x8005EC34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005EC38: b           L_8005EC40
    // 0x8005EC3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8005EC40;
    // 0x8005EC3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8005EC40:
    // 0x8005EC40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005EC44: b           L_8005EC4C
    // 0x8005EC48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8005EC4C;
    // 0x8005EC48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8005EC4C:
    // 0x8005EC4C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8005EC50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005EC54: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8005EC58: bc1f        L_8005ECBC
    if (!c1cs) {
        // 0x8005EC5C: nop
    
            goto L_8005ECBC;
    }
    // 0x8005EC5C: nop

    // 0x8005EC60: bgez        $s2, L_8005EC90
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8005EC64: nop
    
            goto L_8005EC90;
    }
    // 0x8005EC64: nop

    // 0x8005EC68: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005EC6C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005EC70: mflo        $v0
    ctx->r2 = lo;
    // 0x8005EC74: sra         $t9, $v0, 7
    ctx->r25 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005EC78: blez        $t9, L_8005EC88
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8005EC7C: nop
    
            goto L_8005EC88;
    }
    // 0x8005EC7C: nop

    // 0x8005EC80: b           L_8005ECBC
    // 0x8005EC84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8005ECBC;
    // 0x8005EC84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8005EC88:
    // 0x8005EC88: b           L_8005ECBC
    // 0x8005EC8C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8005ECBC;
    // 0x8005EC8C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8005EC90:
    // 0x8005EC90: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005EC94: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005EC98: mflo        $v0
    ctx->r2 = lo;
    // 0x8005EC9C: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005ECA0: bgez        $t8, L_8005ECB0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005ECA4: nop
    
            goto L_8005ECB0;
    }
    // 0x8005ECA4: nop

    // 0x8005ECA8: b           L_8005ECB0
    // 0x8005ECAC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8005ECB0;
    // 0x8005ECAC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8005ECB0:
    // 0x8005ECB0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8005ECB4: b           L_8005ECBC
    // 0x8005ECB8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8005ECBC;
    // 0x8005ECB8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8005ECBC:
    // 0x8005ECBC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8005ECC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005ECC4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005ECC8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005ECCC: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005ECD0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005ECD4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005ECD8: nop

    // 0x8005ECDC: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8005ECE0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005ECE4: nop

    // 0x8005ECE8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8005ECEC: beql        $t7, $zero, L_8005ED3C
    if (ctx->r15 == 0) {
        // 0x8005ECF0: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_8005ED3C;
    }
    goto skip_5;
    // 0x8005ECF0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x8005ECF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005ECF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005ECFC: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8005ED00: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005ED04: nop

    // 0x8005ED08: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005ED0C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005ED10: nop

    // 0x8005ED14: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8005ED18: bne         $t7, $zero, L_8005ED30
    if (ctx->r15 != 0) {
        // 0x8005ED1C: nop
    
            goto L_8005ED30;
    }
    // 0x8005ED1C: nop

    // 0x8005ED20: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8005ED24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005ED28: b           L_8005ED48
    // 0x8005ED2C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8005ED48;
    // 0x8005ED2C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8005ED30:
    // 0x8005ED30: b           L_8005ED48
    // 0x8005ED34: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8005ED48;
    // 0x8005ED34: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005ED38: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_8005ED3C:
    // 0x8005ED3C: nop

    // 0x8005ED40: bltz        $t7, L_8005ED30
    if (SIGNED(ctx->r15) < 0) {
        // 0x8005ED44: nop
    
            goto L_8005ED30;
    }
    // 0x8005ED44: nop

L_8005ED48:
    // 0x8005ED48: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005ED4C: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8005ED50: lwc1        $f4, 0x25C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X25C));
    // 0x8005ED54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005ED58: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005ED5C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8005ED60: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8005ED64: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8005ED68: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8005ED6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005ED70: nop

    // 0x8005ED74: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005ED78: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005ED7C: nop

    // 0x8005ED80: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8005ED84: beql        $t6, $zero, L_8005EDD4
    if (ctx->r14 == 0) {
        // 0x8005ED88: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_8005EDD4;
    }
    goto skip_6;
    // 0x8005ED88: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_6:
    // 0x8005ED8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005ED90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005ED94: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005ED98: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005ED9C: nop

    // 0x8005EDA0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005EDA4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005EDA8: nop

    // 0x8005EDAC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8005EDB0: bne         $t6, $zero, L_8005EDC8
    if (ctx->r14 != 0) {
        // 0x8005EDB4: nop
    
            goto L_8005EDC8;
    }
    // 0x8005EDB4: nop

    // 0x8005EDB8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8005EDBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005EDC0: b           L_8005EDE0
    // 0x8005EDC4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8005EDE0;
    // 0x8005EDC4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8005EDC8:
    // 0x8005EDC8: b           L_8005EDE0
    // 0x8005EDCC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8005EDE0;
    // 0x8005EDCC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8005EDD0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_8005EDD4:
    // 0x8005EDD4: nop

    // 0x8005EDD8: bltz        $t6, L_8005EDC8
    if (SIGNED(ctx->r14) < 0) {
        // 0x8005EDDC: nop
    
            goto L_8005EDC8;
    }
    // 0x8005EDDC: nop

L_8005EDE0:
    // 0x8005EDE0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005EDE4: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x8005EDE8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8005EDEC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8005EDF0: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8005EDF4: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8005EDF8: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    // 0x8005EDFC: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8005EE00: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005EE04: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005EE08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005EE0C: lw          $t8, 0x30($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8005EE10: bc1t        L_8005EE20
    if (c1cs) {
        // 0x8005EE14: sw          $t8, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r24;
            goto L_8005EE20;
    }
    // 0x8005EE14: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005EE18: b           L_8005E714
    // 0x8005EE1C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
        goto L_8005E714;
    // 0x8005EE1C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_8005EE20:
    // 0x8005EE20: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
L_8005EE24:
    // 0x8005EE24: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8005EE28: lw          $s0, 0x1C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8005EE2C: lw          $s1, 0x20($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005EE30: lw          $s2, 0x24($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8005EE34: lw          $s3, 0x28($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8005EE38: jr          $ra
    // 0x8005EE3C: addiu       $sp, $sp, 0x2C0
    ctx->r29 = ADD32(ctx->r29, 0X2C0);
    return;
    // 0x8005EE3C: addiu       $sp, $sp, 0x2C0
    ctx->r29 = ADD32(ctx->r29, 0X2C0);
;}
RECOMP_FUNC void func_800637C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800637C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800637CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800637D0: jal         0x80063750
    // 0x800637D4: nop

    func_80063750(rdram, ctx);
        goto after_0;
    // 0x800637D4: nop

    after_0:
    // 0x800637D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800637DC: sw          $zero, -0x500C($at)
    MEM_W(-0X500C, ctx->r1) = 0;
    // 0x800637E0: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x800637E4: sb          $zero, -0xC68($at)
    MEM_B(-0XC68, ctx->r1) = 0;
    // 0x800637E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800637EC: sw          $zero, -0x4FF0($at)
    MEM_W(-0X4FF0, ctx->r1) = 0;
    // 0x800637F0: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x800637F4: sb          $zero, -0xC67($at)
    MEM_B(-0XC67, ctx->r1) = 0;
    // 0x800637F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800637FC: sw          $zero, -0x4FD4($at)
    MEM_W(-0X4FD4, ctx->r1) = 0;
    // 0x80063800: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x80063804: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80063808: lui         $v0, 0x8026
    ctx->r2 = S32(0X8026 << 16);
    // 0x8006380C: lui         $a0, 0x8026
    ctx->r4 = S32(0X8026 << 16);
    // 0x80063810: addiu       $a0, $a0, -0x145
    ctx->r4 = ADD32(ctx->r4, -0X145);
    // 0x80063814: addiu       $v0, $v0, -0xC65
    ctx->r2 = ADD32(ctx->r2, -0XC65);
    // 0x80063818: addiu       $v1, $v1, -0x4FBC
    ctx->r3 = ADD32(ctx->r3, -0X4FBC);
    // 0x8006381C: sb          $zero, -0xC66($at)
    MEM_B(-0XC66, ctx->r1) = 0;
L_80063820:
    // 0x80063820: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80063824: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x80063828: sb          $zero, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = 0;
    // 0x8006382C: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x80063830: sb          $zero, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = 0;
    // 0x80063834: sw          $zero, 0x58($v1)
    MEM_W(0X58, ctx->r3) = 0;
    // 0x80063838: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8006383C: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x80063840: sw          $zero, -0x6C($v1)
    MEM_W(-0X6C, ctx->r3) = 0;
    // 0x80063844: bne         $v0, $a0, L_80063820
    if (ctx->r2 != ctx->r4) {
        // 0x80063848: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_80063820;
    }
    // 0x80063848: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x8006384C: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x80063850: lw          $t6, -0x14C0($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X14C0));
    // 0x80063854: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063858: sw          $zero, -0x58D0($at)
    MEM_W(-0X58D0, ctx->r1) = 0;
    // 0x8006385C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80063860: bnel        $t6, $at, L_80063874
    if (ctx->r14 != ctx->r1) {
        // 0x80063864: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_80063874;
    }
    goto skip_0;
    // 0x80063864: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x80063868: jal         0x80056150
    // 0x8006386C: nop

    func_80056150(rdram, ctx);
        goto after_1;
    // 0x8006386C: nop

    after_1:
    // 0x80063870: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80063874:
    // 0x80063874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063878: jr          $ra
    // 0x8006387C: nop

    return;
    // 0x8006387C: nop

;}
RECOMP_FUNC void alSndpSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C17E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C17E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C17E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C17EC: lw          $v0, 0x40($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X40));
    // 0x800C17F0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800C17F4: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x800C17F8: lw          $t8, 0x3C($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X3C));
    // 0x800C17FC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800C1800: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x800C1804: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C1808: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C180C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800C1810: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1814: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800C1818: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800C181C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800C1820: jal         0x800C9C6C
    // 0x800C1824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C1824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C1828: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C182C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C1830: jr          $ra
    // 0x800C1834: nop

    return;
    // 0x800C1834: nop

;}
RECOMP_FUNC void func_800550B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800550B0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800550B4: lui         $t1, 0x4E44
    ctx->r9 = S32(0X4E44 << 16);
    // 0x800550B8: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x800550BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800550C0: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800550C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800550C8: addiu       $t0, $t0, -0x46D8
    ctx->r8 = ADD32(ctx->r8, -0X46D8);
    // 0x800550CC: ori         $t1, $t1, 0x4E45
    ctx->r9 = ctx->r9 | 0X4E45;
    // 0x800550D0: addiu       $a1, $a1, -0x4388
    ctx->r5 = ADD32(ctx->r5, -0X4388);
    // 0x800550D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800550D8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800550DC: addiu       $a3, $zero, 0x3458
    ctx->r7 = ADD32(0, 0X3458);
L_800550E0:
    // 0x800550E0: lb          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_B(ctx->r5, 0X0));
    // 0x800550E4: sll         $t7, $v1, 5
    ctx->r15 = S32(ctx->r3 << 5);
    // 0x800550E8: addu        $a0, $t0, $t7
    ctx->r4 = ADD32(ctx->r8, ctx->r15);
    // 0x800550EC: bnel        $t6, $zero, L_80055124
    if (ctx->r14 != 0) {
        // 0x800550F0: lb          $t3, 0x1($a1)
        ctx->r11 = S32(MEM_B(ctx->r5, 0X1));
            goto L_80055124;
    }
    goto skip_0;
    // 0x800550F0: lb          $t3, 0x1($a1)
    ctx->r11 = S32(MEM_B(ctx->r5, 0X1));
    skip_0:
    // 0x800550F4: lhu         $t8, 0x8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X8);
    // 0x800550F8: bnel        $a3, $t8, L_80055124
    if (ctx->r7 != ctx->r24) {
        // 0x800550FC: lb          $t3, 0x1($a1)
        ctx->r11 = S32(MEM_B(ctx->r5, 0X1));
            goto L_80055124;
    }
    goto skip_1;
    // 0x800550FC: lb          $t3, 0x1($a1)
    ctx->r11 = S32(MEM_B(ctx->r5, 0X1));
    skip_1:
    // 0x80055100: lw          $t9, 0x4($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X4));
    // 0x80055104: bnel        $t1, $t9, L_80055124
    if (ctx->r9 != ctx->r25) {
        // 0x80055108: lb          $t3, 0x1($a1)
        ctx->r11 = S32(MEM_B(ctx->r5, 0X1));
            goto L_80055124;
    }
    goto skip_2;
    // 0x80055108: lb          $t3, 0x1($a1)
    ctx->r11 = S32(MEM_B(ctx->r5, 0X1));
    skip_2:
    // 0x8005510C: bnel        $v0, $a2, L_80055120
    if (ctx->r2 != ctx->r6) {
        // 0x80055110: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80055120;
    }
    goto skip_3;
    // 0x80055110: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_3:
    // 0x80055114: jr          $ra
    // 0x80055118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80055118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005511C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80055120:
    // 0x80055120: lb          $t3, 0x1($a1)
    ctx->r11 = S32(MEM_B(ctx->r5, 0X1));
L_80055124:
    // 0x80055124: sll         $t4, $v1, 5
    ctx->r12 = S32(ctx->r3 << 5);
    // 0x80055128: addu        $a0, $t0, $t4
    ctx->r4 = ADD32(ctx->r8, ctx->r12);
    // 0x8005512C: bnel        $t3, $zero, L_80055164
    if (ctx->r11 != 0) {
        // 0x80055130: lb          $t7, 0x2($a1)
        ctx->r15 = S32(MEM_B(ctx->r5, 0X2));
            goto L_80055164;
    }
    goto skip_4;
    // 0x80055130: lb          $t7, 0x2($a1)
    ctx->r15 = S32(MEM_B(ctx->r5, 0X2));
    skip_4:
    // 0x80055134: lhu         $t5, 0x28($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X28);
    // 0x80055138: bnel        $a3, $t5, L_80055164
    if (ctx->r7 != ctx->r13) {
        // 0x8005513C: lb          $t7, 0x2($a1)
        ctx->r15 = S32(MEM_B(ctx->r5, 0X2));
            goto L_80055164;
    }
    goto skip_5;
    // 0x8005513C: lb          $t7, 0x2($a1)
    ctx->r15 = S32(MEM_B(ctx->r5, 0X2));
    skip_5:
    // 0x80055140: lw          $t6, 0x24($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X24));
    // 0x80055144: bnel        $t1, $t6, L_80055164
    if (ctx->r9 != ctx->r14) {
        // 0x80055148: lb          $t7, 0x2($a1)
        ctx->r15 = S32(MEM_B(ctx->r5, 0X2));
            goto L_80055164;
    }
    goto skip_6;
    // 0x80055148: lb          $t7, 0x2($a1)
    ctx->r15 = S32(MEM_B(ctx->r5, 0X2));
    skip_6:
    // 0x8005514C: bnel        $v0, $a2, L_80055160
    if (ctx->r2 != ctx->r6) {
        // 0x80055150: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80055160;
    }
    goto skip_7;
    // 0x80055150: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_7:
    // 0x80055154: jr          $ra
    // 0x80055158: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80055158: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8005515C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80055160:
    // 0x80055160: lb          $t7, 0x2($a1)
    ctx->r15 = S32(MEM_B(ctx->r5, 0X2));
L_80055164:
    // 0x80055164: sll         $t8, $v1, 5
    ctx->r24 = S32(ctx->r3 << 5);
    // 0x80055168: addu        $a0, $t0, $t8
    ctx->r4 = ADD32(ctx->r8, ctx->r24);
    // 0x8005516C: bnel        $t7, $zero, L_800551A4
    if (ctx->r15 != 0) {
        // 0x80055170: lb          $t4, 0x3($a1)
        ctx->r12 = S32(MEM_B(ctx->r5, 0X3));
            goto L_800551A4;
    }
    goto skip_8;
    // 0x80055170: lb          $t4, 0x3($a1)
    ctx->r12 = S32(MEM_B(ctx->r5, 0X3));
    skip_8:
    // 0x80055174: lhu         $t9, 0x48($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X48);
    // 0x80055178: bnel        $a3, $t9, L_800551A4
    if (ctx->r7 != ctx->r25) {
        // 0x8005517C: lb          $t4, 0x3($a1)
        ctx->r12 = S32(MEM_B(ctx->r5, 0X3));
            goto L_800551A4;
    }
    goto skip_9;
    // 0x8005517C: lb          $t4, 0x3($a1)
    ctx->r12 = S32(MEM_B(ctx->r5, 0X3));
    skip_9:
    // 0x80055180: lw          $t3, 0x44($a0)
    ctx->r11 = S32(MEM_W(ctx->r4, 0X44));
    // 0x80055184: bnel        $t1, $t3, L_800551A4
    if (ctx->r9 != ctx->r11) {
        // 0x80055188: lb          $t4, 0x3($a1)
        ctx->r12 = S32(MEM_B(ctx->r5, 0X3));
            goto L_800551A4;
    }
    goto skip_10;
    // 0x80055188: lb          $t4, 0x3($a1)
    ctx->r12 = S32(MEM_B(ctx->r5, 0X3));
    skip_10:
    // 0x8005518C: bnel        $v0, $a2, L_800551A0
    if (ctx->r2 != ctx->r6) {
        // 0x80055190: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800551A0;
    }
    goto skip_11;
    // 0x80055190: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_11:
    // 0x80055194: jr          $ra
    // 0x80055198: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x80055198: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x8005519C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800551A0:
    // 0x800551A0: lb          $t4, 0x3($a1)
    ctx->r12 = S32(MEM_B(ctx->r5, 0X3));
L_800551A4:
    // 0x800551A4: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
    // 0x800551A8: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800551AC: bnel        $t4, $zero, L_800551E4
    if (ctx->r12 != 0) {
        // 0x800551B0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800551E4;
    }
    goto skip_12;
    // 0x800551B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_12:
    // 0x800551B4: lhu         $t6, 0x68($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X68);
    // 0x800551B8: bnel        $a3, $t6, L_800551E4
    if (ctx->r7 != ctx->r14) {
        // 0x800551BC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800551E4;
    }
    goto skip_13;
    // 0x800551BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_13:
    // 0x800551C0: lw          $t7, 0x64($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X64));
    // 0x800551C4: bnel        $t1, $t7, L_800551E4
    if (ctx->r9 != ctx->r15) {
        // 0x800551C8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800551E4;
    }
    goto skip_14;
    // 0x800551C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_14:
    // 0x800551CC: bnel        $v0, $a2, L_800551E0
    if (ctx->r2 != ctx->r6) {
        // 0x800551D0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800551E0;
    }
    goto skip_15;
    // 0x800551D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_15:
    // 0x800551D4: jr          $ra
    // 0x800551D8: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x800551D8: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x800551DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800551E0:
    // 0x800551E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800551E4:
    // 0x800551E4: bne         $v1, $t2, L_800550E0
    if (ctx->r3 != ctx->r10) {
        // 0x800551E8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800550E0;
    }
    // 0x800551E8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800551EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800551F0: jr          $ra
    // 0x800551F4: nop

    return;
    // 0x800551F4: nop

;}
RECOMP_FUNC void dmulscale32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090F74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090F7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090F80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090F84: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090F88: jal         0x800BB8F8
    // 0x80090F8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090F8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090F90: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090F94: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090F98: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090F9C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090FA0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090FA4: jal         0x800BB8F8
    // 0x80090FA8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090FA8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090FAC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090FB0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090FB4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090FB8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090FBC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090FC0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090FC4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090FC8: jal         0x800BBA24
    // 0x80090FCC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090FCC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_2:
    // 0x80090FD0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090FD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090FDC: jr          $ra
    // 0x80090FE0: nop

    return;
    // 0x80090FE0: nop

;}
RECOMP_FUNC void alCSPPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C23E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C23E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C23E8: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800C23EC: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C23F0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C23F4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C23F8: jal         0x800C9C6C
    // 0x800C23FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C23FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C2400: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C2404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C2408: jr          $ra
    // 0x800C240C: nop

    return;
    // 0x800C240C: nop

;}
RECOMP_FUNC void func_800BBE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBE10: nop

;}
RECOMP_FUNC void dmulscale31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090F04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090F0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090F10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090F14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090F18: jal         0x800BB8F8
    // 0x80090F1C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090F1C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090F20: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090F24: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090F28: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090F2C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090F30: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090F34: jal         0x800BB8F8
    // 0x80090F38: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090F38: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090F3C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090F40: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090F44: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090F48: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090F4C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090F50: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090F54: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090F58: jal         0x800BBA24
    // 0x80090F5C: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090F5C: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
    after_2:
    // 0x80090F60: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090F64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090F68: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090F6C: jr          $ra
    // 0x80090F70: nop

    return;
    // 0x80090F70: nop

;}
RECOMP_FUNC void forceplayerangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1808: jal         0x8009800C
    // 0x800A180C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    krand2(rdram, ctx);
        goto after_0;
    // 0x800A180C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A1810: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800A1814: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x800A1818: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800A181C: subu        $v1, $t0, $t9
    ctx->r3 = SUB32(ctx->r8, ctx->r25);
    // 0x800A1820: lw          $t6, 0x220($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X220));
    // 0x800A1824: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x800A1828: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800A182C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A1830: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800A1834: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800A1838: sw          $t7, 0x220($a0)
    MEM_W(0X220, ctx->r4) = ctx->r15;
    // 0x800A183C: sb          $t8, 0x36C($a0)
    MEM_B(0X36C, ctx->r4) = ctx->r24;
    // 0x800A1840: sh          $t3, 0x28A($a0)
    MEM_H(0X28A, ctx->r4) = ctx->r11;
    // 0x800A1844: sh          $t3, 0x318($a0)
    MEM_H(0X318, ctx->r4) = ctx->r11;
    // 0x800A1848: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800A184C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1850: jr          $ra
    // 0x800A1854: nop

    return;
    // 0x800A1854: nop

;}
RECOMP_FUNC void hitawall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1E44: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A1E48: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800A1E4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A1E50: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A1E54: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800A1E58: lh          $v0, 0x282($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X282));
    // 0x800A1E5C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800A1E60: addiu       $v1, $v1, -0x9A0
    ctx->r3 = ADD32(ctx->r3, -0X9A0);
    // 0x800A1E64: addiu       $t6, $v0, 0x200
    ctx->r14 = ADD32(ctx->r2, 0X200);
    // 0x800A1E68: andi        $t7, $t6, 0x7FF
    ctx->r15 = ctx->r14 & 0X7FF;
    // 0x800A1E6C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800A1E70: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800A1E74: lh          $t0, 0x0($t9)
    ctx->r8 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800A1E78: andi        $t1, $v0, 0x7FF
    ctx->r9 = ctx->r2 & 0X7FF;
    // 0x800A1E7C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800A1E80: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800A1E84: lh          $a3, 0x288($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800A1E88: lw          $a2, 0x21C($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800A1E8C: lw          $a1, 0x218($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800A1E90: lw          $a0, 0x214($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X214));
    // 0x800A1E94: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x800A1E98: lw          $t6, 0x64($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800A1E9C: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x800A1EA0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800A1EA4: addiu       $t0, $sp, 0x54
    ctx->r8 = ADD32(ctx->r29, 0X54);
    // 0x800A1EA8: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x800A1EAC: addiu       $t9, $sp, 0x58
    ctx->r25 = ADD32(ctx->r29, 0X58);
    // 0x800A1EB0: addiu       $t8, $sp, 0x5C
    ctx->r24 = ADD32(ctx->r29, 0X5C);
    // 0x800A1EB4: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x800A1EB8: addiu       $t5, $sp, 0x52
    ctx->r13 = ADD32(ctx->r29, 0X52);
    // 0x800A1EBC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800A1EC0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800A1EC4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800A1EC8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800A1ECC: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800A1ED0: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800A1ED4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800A1ED8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800A1EDC: jal         0x8009324C
    // 0x800A1EE0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    hitscan(rdram, ctx);
        goto after_0;
    // 0x800A1EE0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x800A1EE4: lw          $t2, 0x5C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800A1EE8: lw          $t3, 0x214($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800A1EEC: lw          $t4, 0x58($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800A1EF0: lw          $t5, 0x218($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800A1EF4: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    // 0x800A1EF8: jal         0x800993E0
    // 0x800A1EFC: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    FindDistance2D(rdram, ctx);
        goto after_1;
    // 0x800A1EFC: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    after_1:
    // 0x800A1F00: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800A1F04: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800A1F08: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800A1F0C: jr          $ra
    // 0x800A1F10: nop

    return;
    // 0x800A1F10: nop

;}
RECOMP_FUNC void alClose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF7C4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800BF7C8: lw          $t6, 0x2140($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, 0X2140));
    // 0x800BF7CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF7D4: beql        $t6, $zero, L_800BF7F0
    if (ctx->r14 == 0) {
        // 0x800BF7D8: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800BF7F0;
    }
    goto skip_0;
    // 0x800BF7D8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800BF7DC: jal         0x800C9B40
    // 0x800BF7E0: nop

    alSynDelete(rdram, ctx);
        goto after_0;
    // 0x800BF7E0: nop

    after_0:
    // 0x800BF7E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800BF7E8: sw          $zero, 0x2140($at)
    MEM_W(0X2140, ctx->r1) = 0;
    // 0x800BF7EC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800BF7F0:
    // 0x800BF7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF7F4: jr          $ra
    // 0x800BF7F8: nop

    return;
    // 0x800BF7F8: nop

;}
RECOMP_FUNC void rotatesprite_setidshadepal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071FFC: addiu       $t4, $zero, 0x1C
    ctx->r12 = ADD32(0, 0X1C);
    // 0x80072000: subu        $t6, $t4, $a1
    ctx->r14 = SUB32(ctx->r12, ctx->r5);
    // 0x80072004: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80072008: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8007200C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80072010: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80072014: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80072018: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8007201C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80072020: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80072024: slti        $at, $a1, 0x101
    ctx->r1 = SIGNED(ctx->r5) < 0X101 ? 1 : 0;
    // 0x80072028: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007202C: bne         $at, $zero, L_80072038
    if (ctx->r1 != 0) {
        // 0x80072030: andi        $a3, $a0, 0xFFFF
        ctx->r7 = ctx->r4 & 0XFFFF;
            goto L_80072038;
    }
    // 0x80072030: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x80072034: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
L_80072038:
    // 0x80072038: bgtz        $a1, L_80072044
    if (SIGNED(ctx->r5) > 0) {
        // 0x8007203C: lui         $v0, 0x8022
        ctx->r2 = S32(0X8022 << 16);
            goto L_80072044;
    }
    // 0x8007203C: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80072040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80072044:
    // 0x80072044: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80072048: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8007204C: addiu       $a0, $a0, -0x2930
    ctx->r4 = ADD32(ctx->r4, -0X2930);
    // 0x80072050: addiu       $v1, $v1, -0x2980
    ctx->r3 = ADD32(ctx->r3, -0X2980);
    // 0x80072054: addiu       $v0, $v0, -0x2958
    ctx->r2 = ADD32(ctx->r2, -0X2958);
    // 0x80072058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007205C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80072060: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80072064: beq         $a2, $at, L_80072090
    if (ctx->r6 == ctx->r1) {
        // 0x80072068: sw          $a1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r5;
            goto L_80072090;
    }
    // 0x80072068: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8007206C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80072070: beq         $a2, $at, L_800720C4
    if (ctx->r6 == ctx->r1) {
        // 0x80072074: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800720C4;
    }
    // 0x80072074: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80072078: beq         $a2, $at, L_800720F8
    if (ctx->r6 == ctx->r1) {
        // 0x8007207C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800720F8;
    }
    // 0x8007207C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80072080: beql        $a2, $at, L_800720FC
    if (ctx->r6 == ctx->r1) {
        // 0x80072084: lw          $t6, 0x0($v1)
        ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800720FC;
    }
    goto skip_0;
    // 0x80072084: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    skip_0:
    // 0x80072088: b           L_8007212C
    // 0x8007208C: sll         $t4, $a3, 3
    ctx->r12 = S32(ctx->r7 << 3);
        goto L_8007212C;
    // 0x8007208C: sll         $t4, $a3, 3
    ctx->r12 = S32(ctx->r7 << 3);
L_80072090:
    // 0x80072090: lw          $t4, 0x0($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80072094: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80072098: bgez        $t4, L_800720A8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007209C: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800720A8;
    }
    // 0x8007209C: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800720A0: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800720A4: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800720A8:
    // 0x800720A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800720AC: bgez        $t6, L_800720BC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800720B0: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_800720BC;
    }
    // 0x800720B0: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800720B4: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x800720B8: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800720BC:
    // 0x800720BC: b           L_80072128
    // 0x800720C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_80072128;
    // 0x800720C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800720C4:
    // 0x800720C4: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800720C8: lw          $t4, 0x0($a0)
    ctx->r12 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800720CC: bgez        $t8, L_800720DC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800720D0: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_800720DC;
    }
    // 0x800720D0: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800720D4: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x800720D8: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800720DC:
    // 0x800720DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800720E0: bgez        $t4, L_800720F0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800720E4: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800720F0;
    }
    // 0x800720E4: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800720E8: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800720EC: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800720F0:
    // 0x800720F0: b           L_80072128
    // 0x800720F4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_80072128;
    // 0x800720F4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_800720F8:
    // 0x800720F8: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
L_800720FC:
    // 0x800720FC: lw          $t8, 0x0($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80072100: bgez        $t6, L_80072110
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80072104: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80072110;
    }
    // 0x80072104: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80072108: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8007210C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80072110:
    // 0x80072110: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80072114: bgez        $t8, L_80072124
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80072118: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80072124;
    }
    // 0x80072118: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007211C: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80072120: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80072124:
    // 0x80072124: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_80072128:
    // 0x80072128: sll         $t4, $a3, 3
    ctx->r12 = S32(ctx->r7 << 3);
L_8007212C:
    // 0x8007212C: subu        $t4, $t4, $a3
    ctx->r12 = SUB32(ctx->r12, ctx->r7);
    // 0x80072130: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80072134: addu        $t4, $t4, $a3
    ctx->r12 = ADD32(ctx->r12, ctx->r7);
    // 0x80072138: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007213C: subu        $t4, $t4, $a3
    ctx->r12 = SUB32(ctx->r12, ctx->r7);
    // 0x80072140: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x80072144: addiu       $t5, $t5, 0x5770
    ctx->r13 = ADD32(ctx->r13, 0X5770);
    // 0x80072148: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8007214C: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x80072150: lbu         $t6, 0x346($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X346);
    // 0x80072154: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80072158: addiu       $t3, $t3, 0x4418
    ctx->r11 = ADD32(ctx->r11, 0X4418);
    // 0x8007215C: blezl       $t6, L_800721D4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80072160: lw          $t8, 0x0($v1)
        ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800721D4;
    }
    goto skip_1;
    // 0x80072160: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
    skip_1:
    // 0x80072164: lh          $t7, 0x2BE($t0)
    ctx->r15 = S32(MEM_H(ctx->r8, 0X2BE));
    // 0x80072168: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007216C: bnel        $t7, $at, L_800721D4
    if (ctx->r15 != ctx->r1) {
        // 0x80072170: lw          $t8, 0x0($v1)
        ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800721D4;
    }
    goto skip_2;
    // 0x80072170: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
    skip_2:
    // 0x80072174: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80072178: addiu       $a2, $zero, 0xAB
    ctx->r6 = ADD32(0, 0XAB);
    // 0x8007217C: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    // 0x80072180: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072184: lw          $t8, 0x0($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80072188: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007218C: lw          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80072190: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80072194: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80072198: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x8007219C: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800721A0: mflo        $t9
    ctx->r25 = lo;
    // 0x800721A4: sra         $t4, $t9, 8
    ctx->r12 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800721A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800721AC: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800721B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800721B4: mflo        $t9
    ctx->r25 = lo;
    // 0x800721B8: sra         $t4, $t9, 8
    ctx->r12 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800721BC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800721C0: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x800721C4: mflo        $t5
    ctx->r13 = lo;
    // 0x800721C8: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800721CC: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800721D0: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
L_800721D4:
    // 0x800721D4: lw          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800721D8: lw          $t1, 0x274($t0)
    ctx->r9 = S32(MEM_W(ctx->r8, 0X274));
    // 0x800721DC: multu       $a1, $t8
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800721E0: lw          $t8, 0x0($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800721E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800721E8: bgez        $t9, L_800721F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800721EC: sra         $t4, $t9, 8
        ctx->r12 = S32(SIGNED(ctx->r25) >> 8);
            goto L_800721F8;
    }
    // 0x800721EC: sra         $t4, $t9, 8
    ctx->r12 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800721F0: addiu       $at, $t9, 0xFF
    ctx->r1 = ADD32(ctx->r25, 0XFF);
    // 0x800721F4: sra         $t4, $at, 8
    ctx->r12 = S32(SIGNED(ctx->r1) >> 8);
L_800721F8:
    // 0x800721F8: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800721FC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80072200: mflo        $t6
    ctx->r14 = lo;
    // 0x80072204: bgez        $t6, L_80072214
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80072208: sra         $t7, $t6, 8
        ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
            goto L_80072214;
    }
    // 0x80072208: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8007220C: addiu       $at, $t6, 0xFF
    ctx->r1 = ADD32(ctx->r14, 0XFF);
    // 0x80072210: sra         $t7, $at, 8
    ctx->r15 = S32(SIGNED(ctx->r1) >> 8);
L_80072214:
    // 0x80072214: multu       $a1, $t8
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072218: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007221C: mflo        $t9
    ctx->r25 = lo;
    // 0x80072220: bgez        $t9, L_80072230
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80072224: sra         $t4, $t9, 8
        ctx->r12 = S32(SIGNED(ctx->r25) >> 8);
            goto L_80072230;
    }
    // 0x80072224: sra         $t4, $t9, 8
    ctx->r12 = S32(SIGNED(ctx->r25) >> 8);
    // 0x80072228: addiu       $at, $t9, 0xFF
    ctx->r1 = ADD32(ctx->r25, 0XFF);
    // 0x8007222C: sra         $t4, $at, 8
    ctx->r12 = S32(SIGNED(ctx->r1) >> 8);
L_80072230:
    // 0x80072230: blez        $t1, L_800722D8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80072234: sw          $t4, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r12;
            goto L_800722D8;
    }
    // 0x80072234: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80072238: lw          $t5, 0x210($t0)
    ctx->r13 = S32(MEM_W(ctx->r8, 0X210));
    // 0x8007223C: bnel        $t5, $zero, L_800722DC
    if (ctx->r13 != 0) {
        // 0x80072240: lw          $a1, 0x210($t0)
        ctx->r5 = S32(MEM_W(ctx->r8, 0X210));
            goto L_800722DC;
    }
    goto skip_3;
    // 0x80072240: lw          $a1, 0x210($t0)
    ctx->r5 = S32(MEM_W(ctx->r8, 0X210));
    skip_3:
    // 0x80072244: lbu         $t6, 0x367($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X367);
    // 0x80072248: lw          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8007224C: lw          $a2, 0x0($v0)
    ctx->r6 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80072250: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80072254: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x80072258: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007225C: lbu         $t6, 0x368($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X368);
    // 0x80072260: lw          $a3, 0x0($a0)
    ctx->r7 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80072264: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80072268: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x8007226C: lbu         $t6, 0x369($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X369);
    // 0x80072270: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80072274: mflo        $t9
    ctx->r25 = lo;
    // 0x80072278: bgez        $t9, L_80072288
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007227C: sra         $t4, $t9, 6
        ctx->r12 = S32(SIGNED(ctx->r25) >> 6);
            goto L_80072288;
    }
    // 0x8007227C: sra         $t4, $t9, 6
    ctx->r12 = S32(SIGNED(ctx->r25) >> 6);
    // 0x80072280: addiu       $at, $t9, 0x3F
    ctx->r1 = ADD32(ctx->r25, 0X3F);
    // 0x80072284: sra         $t4, $at, 6
    ctx->r12 = S32(SIGNED(ctx->r1) >> 6);
L_80072288:
    // 0x80072288: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007228C: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x80072290: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80072294: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80072298: mflo        $t9
    ctx->r25 = lo;
    // 0x8007229C: bgez        $t9, L_800722AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800722A0: sra         $t4, $t9, 6
        ctx->r12 = S32(SIGNED(ctx->r25) >> 6);
            goto L_800722AC;
    }
    // 0x800722A0: sra         $t4, $t9, 6
    ctx->r12 = S32(SIGNED(ctx->r25) >> 6);
    // 0x800722A4: addiu       $at, $t9, 0x3F
    ctx->r1 = ADD32(ctx->r25, 0X3F);
    // 0x800722A8: sra         $t4, $at, 6
    ctx->r12 = S32(SIGNED(ctx->r1) >> 6);
L_800722AC:
    // 0x800722AC: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800722B0: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x800722B4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800722B8: mflo        $t9
    ctx->r25 = lo;
    // 0x800722BC: bgez        $t9, L_800722CC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800722C0: sra         $t4, $t9, 6
        ctx->r12 = S32(SIGNED(ctx->r25) >> 6);
            goto L_800722CC;
    }
    // 0x800722C0: sra         $t4, $t9, 6
    ctx->r12 = S32(SIGNED(ctx->r25) >> 6);
    // 0x800722C4: addiu       $at, $t9, 0x3F
    ctx->r1 = ADD32(ctx->r25, 0X3F);
    // 0x800722C8: sra         $t4, $at, 6
    ctx->r12 = S32(SIGNED(ctx->r1) >> 6);
L_800722CC:
    // 0x800722CC: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x800722D0: b           L_80072320
    // 0x800722D4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_80072320;
    // 0x800722D4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_800722D8:
    // 0x800722D8: lw          $a1, 0x210($t0)
    ctx->r5 = S32(MEM_W(ctx->r8, 0X210));
L_800722DC:
    // 0x800722DC: blezl       $a1, L_80072324
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800722E0: lw          $a1, 0x0($v1)
        ctx->r5 = S32(MEM_W(ctx->r3, 0X0));
            goto L_80072324;
    }
    goto skip_4;
    // 0x800722E0: lw          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X0));
    skip_4:
    // 0x800722E4: lw          $a2, 0x0($v0)
    ctx->r6 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800722E8: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x800722EC: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x800722F0: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800722F4: mflo        $t8
    ctx->r24 = lo;
    // 0x800722F8: bgez        $t8, L_80072308
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800722FC: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80072308;
    }
    // 0x800722FC: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80072300: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80072304: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80072308:
    // 0x80072308: bgez        $t9, L_80072318
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007230C: sra         $t4, $t9, 6
        ctx->r12 = S32(SIGNED(ctx->r25) >> 6);
            goto L_80072318;
    }
    // 0x8007230C: sra         $t4, $t9, 6
    ctx->r12 = S32(SIGNED(ctx->r25) >> 6);
    // 0x80072310: addiu       $at, $t9, 0x3F
    ctx->r1 = ADD32(ctx->r25, 0X3F);
    // 0x80072314: sra         $t4, $at, 6
    ctx->r12 = S32(SIGNED(ctx->r1) >> 6);
L_80072318:
    // 0x80072318: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x8007231C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80072320:
    // 0x80072320: lw          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X0));
L_80072324:
    // 0x80072324: bgezl       $a1, L_80072338
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80072328: slti        $at, $a1, 0x100
        ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
            goto L_80072338;
    }
    goto skip_5;
    // 0x80072328: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    skip_5:
    // 0x8007232C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80072330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80072334: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
L_80072338:
    // 0x80072338: bne         $at, $zero, L_80072344
    if (ctx->r1 != 0) {
        // 0x8007233C: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80072344;
    }
    // 0x8007233C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80072340: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
L_80072344:
    // 0x80072344: lw          $a2, 0x0($v0)
    ctx->r6 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80072348: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007234C: bgezl       $a2, L_80072360
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80072350: slti        $at, $a2, 0x100
        ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
            goto L_80072360;
    }
    goto skip_6;
    // 0x80072350: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    skip_6:
    // 0x80072354: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80072358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007235C: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
L_80072360:
    // 0x80072360: bnel        $at, $zero, L_80072370
    if (ctx->r1 != 0) {
        // 0x80072364: lw          $a3, 0x0($a0)
        ctx->r7 = S32(MEM_W(ctx->r4, 0X0));
            goto L_80072370;
    }
    goto skip_7;
    // 0x80072364: lw          $a3, 0x0($a0)
    ctx->r7 = S32(MEM_W(ctx->r4, 0X0));
    skip_7:
    // 0x80072368: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8007236C: lw          $a3, 0x0($a0)
    ctx->r7 = S32(MEM_W(ctx->r4, 0X0));
L_80072370:
    // 0x80072370: bgezl       $a3, L_80072384
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80072374: slti        $at, $a3, 0x100
        ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
            goto L_80072384;
    }
    goto skip_8;
    // 0x80072374: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
    skip_8:
    // 0x80072378: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8007237C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80072380: slti        $at, $a3, 0x100
    ctx->r1 = SIGNED(ctx->r7) < 0X100 ? 1 : 0;
L_80072384:
    // 0x80072384: bnel        $at, $zero, L_80072394
    if (ctx->r1 != 0) {
        // 0x80072388: lw          $a2, 0x0($t3)
        ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
            goto L_80072394;
    }
    goto skip_9;
    // 0x80072388: lw          $a2, 0x0($t3)
    ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
    skip_9:
    // 0x8007238C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80072390: lw          $a2, 0x0($t3)
    ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
L_80072394:
    // 0x80072394: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80072398: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x8007239C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800723A0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800723A4: lw          $t9, 0x0($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800723A8: lw          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800723AC: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x800723B0: lw          $t9, 0x0($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800723B4: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800723B8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800723BC: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800723C0: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800723C4: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800723C8: lw          $t9, -0x5370($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, -0X5370));
    // 0x800723CC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800723D0: or          $t4, $t8, $t6
    ctx->r12 = ctx->r24 | ctx->r14;
    // 0x800723D4: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800723D8: or          $t8, $t4, $t5
    ctx->r24 = ctx->r12 | ctx->r13;
    // 0x800723DC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800723E0: lw          $a2, 0x0($t3)
    ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
    // 0x800723E4: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800723E8: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800723EC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800723F0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800723F4: lw          $t4, 0x0($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800723F8: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800723FC: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x80072400: lw          $t4, 0x0($a0)
    ctx->r12 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80072404: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80072408: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8007240C: andi        $t8, $t4, 0xFF
    ctx->r24 = ctx->r12 & 0XFF;
    // 0x80072410: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x80072414: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x80072418: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x8007241C: ori         $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 | 0XFF;
    // 0x80072420: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80072424: lw          $a2, 0x0($t3)
    ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
    // 0x80072428: lui         $t8, 0xF900
    ctx->r24 = S32(0XF900 << 16);
    // 0x8007242C: addiu       $t4, $a2, 0x8
    ctx->r12 = ADD32(ctx->r6, 0X8);
    // 0x80072430: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80072434: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80072438: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8007243C: lw          $t7, 0x0($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80072440: sll         $t5, $t6, 24
    ctx->r13 = S32(ctx->r14 << 24);
    // 0x80072444: lw          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80072448: andi        $t4, $t7, 0xFF
    ctx->r12 = ctx->r15 & 0XFF;
    // 0x8007244C: sll         $t8, $t4, 16
    ctx->r24 = S32(ctx->r12 << 16);
    // 0x80072450: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80072454: sll         $t4, $t7, 8
    ctx->r12 = S32(ctx->r15 << 8);
    // 0x80072458: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8007245C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x80072460: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x80072464: lw          $a2, 0x0($t3)
    ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
    // 0x80072468: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x8007246C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80072470: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80072474: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80072478: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x8007247C: ori         $t7, $t7, 0x3048
    ctx->r15 = ctx->r15 | 0X3048;
    // 0x80072480: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80072484: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80072488: lw          $a2, 0x0($t3)
    ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
    // 0x8007248C: lui         $t5, 0x44FE
    ctx->r13 = S32(0X44FE << 16);
    // 0x80072490: lui         $t4, 0xFC50
    ctx->r12 = S32(0XFC50 << 16);
    // 0x80072494: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80072498: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8007249C: ori         $t4, $t4, 0xFEA1
    ctx->r12 = ctx->r12 | 0XFEA1;
    // 0x800724A0: ori         $t5, $t5, 0x7339
    ctx->r13 = ctx->r13 | 0X7339;
    // 0x800724A4: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x800724A8: jr          $ra
    // 0x800724AC: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    return;
    // 0x800724AC: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
;}
RECOMP_FUNC void func_80055450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055450: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80055454: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80055458: beq         $a0, $zero, L_800554C4
    if (ctx->r4 == 0) {
        // 0x8005545C: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_800554C4;
    }
    // 0x8005545C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80055460: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80055464: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80055468: jal         0x800550B0
    // 0x8005546C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800550B0(rdram, ctx);
        goto after_0;
    // 0x8005546C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80055470: jal         0x80051D40
    // 0x80055474: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_80051D40(rdram, ctx);
        goto after_1;
    // 0x80055474: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80055478: lw          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8005547C: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x80055480: addiu       $t9, $t9, -0x46D8
    ctx->r25 = ADD32(ctx->r25, -0X46D8);
    // 0x80055484: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80055488: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8005548C: addiu       $t0, $v0, 0xA
    ctx->r8 = ADD32(ctx->r2, 0XA);
    // 0x80055490: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80055494: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    // 0x80055498: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8005549C: lhu         $a1, 0x8($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X8);
    // 0x800554A0: lw          $a2, 0x4($v0)
    ctx->r6 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800554A4: jal         0x800BDE20
    // 0x800554A8: addiu       $a3, $v0, 0xE
    ctx->r7 = ADD32(ctx->r2, 0XE);
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_2;
    // 0x800554A8: addiu       $a3, $v0, 0xE
    ctx->r7 = ADD32(ctx->r2, 0XE);
    after_2:
    // 0x800554AC: jal         0x80051D6C
    // 0x800554B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_80051D6C(rdram, ctx);
        goto after_3;
    // 0x800554B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_3:
    // 0x800554B4: beq         $s0, $zero, L_800554C4
    if (ctx->r16 == 0) {
        // 0x800554B8: nop
    
            goto L_800554C4;
    }
    // 0x800554B8: nop

    // 0x800554BC: b           L_80055584
    // 0x800554C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80055584;
    // 0x800554C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800554C4:
    // 0x800554C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800554C8: jal         0x80055374
    // 0x800554CC: sb          $zero, 0x38D0($at)
    MEM_B(0X38D0, ctx->r1) = 0;
    func_80055374(rdram, ctx);
        goto after_4;
    // 0x800554CC: sb          $zero, 0x38D0($at)
    MEM_B(0X38D0, ctx->r1) = 0;
    after_4:
    // 0x800554D0: jal         0x80055060
    // 0x800554D4: nop

    func_80055060(rdram, ctx);
        goto after_5;
    // 0x800554D4: nop

    after_5:
    // 0x800554D8: jal         0x80051D40
    // 0x800554DC: nop

    func_80051D40(rdram, ctx);
        goto after_6;
    // 0x800554DC: nop

    after_6:
    // 0x800554E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800554E4: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x800554E8: addiu       $v0, $v0, -0x4220
    ctx->r2 = ADD32(ctx->r2, -0X4220);
    // 0x800554EC: addiu       $t1, $t1, -0x4216
    ctx->r9 = ADD32(ctx->r9, -0X4216);
    // 0x800554F0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800554F4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x800554F8: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x800554FC: addiu       $t3, $sp, 0x3C
    ctx->r11 = ADD32(ctx->r29, 0X3C);
    // 0x80055500: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80055504: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80055508: addiu       $a3, $a3, -0x4212
    ctx->r7 = ADD32(ctx->r7, -0X4212);
    // 0x8005550C: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    // 0x80055510: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80055514: lhu         $a1, 0x8($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X8);
    // 0x80055518: jal         0x800BE430
    // 0x8005551C: lw          $a2, 0x4($v0)
    ctx->r6 = S32(MEM_W(ctx->r2, 0X4));
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_7;
    // 0x8005551C: lw          $a2, 0x4($v0)
    ctx->r6 = S32(MEM_W(ctx->r2, 0X4));
    after_7:
    // 0x80055520: jal         0x80051D6C
    // 0x80055524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_80051D6C(rdram, ctx);
        goto after_8;
    // 0x80055524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_8:
    // 0x80055528: beq         $s0, $zero, L_80055538
    if (ctx->r16 == 0) {
        // 0x8005552C: nop
    
            goto L_80055538;
    }
    // 0x8005552C: nop

    // 0x80055530: b           L_80055584
    // 0x80055534: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80055584;
    // 0x80055534: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80055538:
    // 0x80055538: jal         0x80051D40
    // 0x8005553C: nop

    func_80051D40(rdram, ctx);
        goto after_9;
    // 0x8005553C: nop

    after_9:
    // 0x80055540: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x80055544: addiu       $t5, $t5, -0x4360
    ctx->r13 = ADD32(ctx->r13, -0X4360);
    // 0x80055548: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8005554C: addiu       $t4, $zero, 0x140
    ctx->r12 = ADD32(0, 0X140);
    // 0x80055550: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80055554: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    // 0x80055558: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005555C: lw          $a1, 0x3C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80055560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055564: jal         0x800BECDC
    // 0x80055568: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_10;
    // 0x80055568: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x8005556C: jal         0x80051D6C
    // 0x80055570: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_80051D6C(rdram, ctx);
        goto after_11;
    // 0x80055570: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_11:
    // 0x80055574: beq         $s0, $zero, L_80055584
    if (ctx->r16 == 0) {
        // 0x80055578: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80055584;
    }
    // 0x80055578: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005557C: b           L_80055584
    // 0x80055580: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80055584;
    // 0x80055580: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80055584:
    // 0x80055584: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80055588: lw          $s0, 0x28($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8005558C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80055590: jr          $ra
    // 0x80055594: nop

    return;
    // 0x80055594: nop

;}
RECOMP_FUNC void dmulscale30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090E94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090E9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090EA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090EA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090EA8: jal         0x800BB8F8
    // 0x80090EAC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090EAC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090EB0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090EB4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090EB8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090EBC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090EC0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090EC4: jal         0x800BB8F8
    // 0x80090EC8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090EC8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090ECC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090ED0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090ED4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090ED8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090EDC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090EE0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090EE4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090EE8: jal         0x800BBA24
    // 0x80090EEC: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090EEC: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_2:
    // 0x80090EF0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090EF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090EFC: jr          $ra
    // 0x80090F00: nop

    return;
    // 0x80090F00: nop

;}
RECOMP_FUNC void func_8005BB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BB48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BB4C: addiu       $v0, $v0, -0x65A0
    ctx->r2 = ADD32(ctx->r2, -0X65A0);
    // 0x8005BB50: addiu       $t6, $zero, 0x280
    ctx->r14 = ADD32(0, 0X280);
    // 0x8005BB54: addiu       $t7, $zero, 0x1E0
    ctx->r15 = ADD32(0, 0X1E0);
    // 0x8005BB58: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x8005BB5C: jr          $ra
    // 0x8005BB60: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    return;
    // 0x8005BB60: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
;}
