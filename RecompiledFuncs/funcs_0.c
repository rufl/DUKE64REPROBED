#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80063A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A08: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80063A0C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80063A10: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80063A14: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80063A18: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80063A1C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80063A20: lhu         $v0, -0x4FFE($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4FFE);
    // 0x80063A24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80063A28: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80063A2C: bne         $at, $zero, L_80063A4C
    if (ctx->r1 != 0) {
        // 0x80063A30: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80063A4C;
    }
    // 0x80063A30: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80063A34: beq         $v0, $at, L_80063AC4
    if (ctx->r2 == ctx->r1) {
        // 0x80063A38: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_80063AC4;
    }
    // 0x80063A38: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80063A3C: beq         $v0, $at, L_80063ACC
    if (ctx->r2 == ctx->r1) {
        // 0x80063A40: nop
    
            goto L_80063ACC;
    }
    // 0x80063A40: nop

    // 0x80063A44: b           L_80063AD8
    // 0x80063A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80063AD8;
    // 0x80063A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063A4C:
    // 0x80063A4C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x80063A50: bne         $at, $zero, L_80063A6C
    if (ctx->r1 != 0) {
        // 0x80063A54: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80063A6C;
    }
    // 0x80063A54: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80063A58: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80063A5C: beq         $v0, $at, L_80063ABC
    if (ctx->r2 == ctx->r1) {
        // 0x80063A60: nop
    
            goto L_80063ABC;
    }
    // 0x80063A60: nop

    // 0x80063A64: b           L_80063AD8
    // 0x80063A68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80063AD8;
    // 0x80063A68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063A6C:
    // 0x80063A6C: sltiu       $at, $t8, 0x20
    ctx->r1 = ctx->r24 < 0X20 ? 1 : 0;
    // 0x80063A70: beq         $at, $zero, L_80063AD4
    if (ctx->r1 == 0) {
        // 0x80063A74: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80063AD4;
    }
    // 0x80063A74: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80063A78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80063A7C: addu        $at, $at, $t8
    gpr jr_addend_80063A84 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80063A80: lw          $t8, 0x4C64($at)
    ctx->r24 = ADD32(ctx->r1, 0X4C64);
    // 0x80063A84: jr          $t8
    // 0x80063A88: nop

    switch (jr_addend_80063A84 >> 2) {
        case 0: goto L_80063A8C; break;
        case 1: goto L_80063A94; break;
        case 2: goto L_80063AD4; break;
        case 3: goto L_80063A9C; break;
        case 4: goto L_80063AD4; break;
        case 5: goto L_80063AD4; break;
        case 6: goto L_80063AD4; break;
        case 7: goto L_80063AA4; break;
        case 8: goto L_80063AD4; break;
        case 9: goto L_80063AD4; break;
        case 10: goto L_80063AD4; break;
        case 11: goto L_80063AD4; break;
        case 12: goto L_80063AD4; break;
        case 13: goto L_80063AD4; break;
        case 14: goto L_80063AD4; break;
        case 15: goto L_80063AAC; break;
        case 16: goto L_80063AD4; break;
        case 17: goto L_80063AD4; break;
        case 18: goto L_80063AD4; break;
        case 19: goto L_80063AD4; break;
        case 20: goto L_80063AD4; break;
        case 21: goto L_80063AD4; break;
        case 22: goto L_80063AD4; break;
        case 23: goto L_80063AD4; break;
        case 24: goto L_80063AD4; break;
        case 25: goto L_80063AD4; break;
        case 26: goto L_80063AD4; break;
        case 27: goto L_80063AD4; break;
        case 28: goto L_80063AD4; break;
        case 29: goto L_80063AD4; break;
        case 30: goto L_80063AD4; break;
        case 31: goto L_80063AB4; break;
        default: switch_error(__func__, 0x80063A84, 0x80104C64);
    }
    // 0x80063A88: nop

L_80063A8C:
    // 0x80063A8C: jr          $ra
    // 0x80063A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80063A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063A94:
    // 0x80063A94: jr          $ra
    // 0x80063A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80063A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80063A9C:
    // 0x80063A9C: jr          $ra
    // 0x80063AA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80063AA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80063AA4:
    // 0x80063AA4: jr          $ra
    // 0x80063AA8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80063AA8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80063AAC:
    // 0x80063AAC: jr          $ra
    // 0x80063AB0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80063AB0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80063AB4:
    // 0x80063AB4: jr          $ra
    // 0x80063AB8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80063AB8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80063ABC:
    // 0x80063ABC: jr          $ra
    // 0x80063AC0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x80063AC0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80063AC4:
    // 0x80063AC4: jr          $ra
    // 0x80063AC8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x80063AC8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80063ACC:
    // 0x80063ACC: jr          $ra
    // 0x80063AD0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80063AD0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80063AD4:
    // 0x80063AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063AD8:
    // 0x80063AD8: jr          $ra
    // 0x80063ADC: nop

    return;
    // 0x80063ADC: nop

;}
RECOMP_FUNC void __vsVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA6E4: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x800CA6E8: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x800CA6EC: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x800CA6F0: lbu         $t2, 0x31($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X31);
    // 0x800CA6F4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA6F8: lw          $t1, 0x60($a1)
    ctx->r9 = S32(MEM_W(ctx->r5, 0X60));
    // 0x800CA6FC: lw          $t6, 0x20($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X20));
    // 0x800CA700: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800CA704: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800CA708: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x800CA70C: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x800CA710: mflo        $t8
    ctx->r24 = lo;
    // 0x800CA714: nop

    // 0x800CA718: nop

    // 0x800CA71C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA720: lh          $t9, 0x32($a1)
    ctx->r25 = S32(MEM_H(ctx->r5, 0X32));
    // 0x800CA724: mflo        $v1
    ctx->r3 = lo;
    // 0x800CA728: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x800CA72C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800CA730: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA734: mflo        $t8
    ctx->r24 = lo;
    // 0x800CA738: nop

    // 0x800CA73C: nop

    // 0x800CA740: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA744: mflo        $a2
    ctx->r6 = lo;
    // 0x800CA748: sra         $t0, $a2, 14
    ctx->r8 = S32(SIGNED(ctx->r6) >> 14);
    // 0x800CA74C: nop

    // 0x800CA750: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA754: mflo        $v1
    ctx->r3 = lo;
    // 0x800CA758: srl         $t2, $v1, 15
    ctx->r10 = S32(U32(ctx->r3) >> 15);
    // 0x800CA75C: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x800CA760: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800CA764: jr          $ra
    // 0x800CA768: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800CA768: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void __resetPerfChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA584: lw          $t6, 0x60($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA588: sll         $v0, $a1, 4
    ctx->r2 = S32(ctx->r5 << 4);
    // 0x800CA58C: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x800CA590: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800CA594: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x800CA598: lw          $t8, 0x60($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA59C: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x800CA5A0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800CA5A4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CA5A8: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x800CA5AC: lw          $t1, 0x60($a0)
    ctx->r9 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA5B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CA5B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CA5B8: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800CA5BC: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x800CA5C0: lw          $t4, 0x60($a0)
    ctx->r12 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA5C4: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x800CA5C8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800CA5CC: sb          $t3, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r11;
    // 0x800CA5D0: lw          $t7, 0x60($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA5D4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800CA5D8: sb          $t6, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r14;
    // 0x800CA5DC: lw          $t9, 0x60($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA5E0: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800CA5E4: sb          $zero, 0xB($t1)
    MEM_B(0XB, ctx->r9) = 0;
    // 0x800CA5E8: lw          $t2, 0x60($a0)
    ctx->r10 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA5EC: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x800CA5F0: sh          $t0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r8;
    // 0x800CA5F4: lw          $t3, 0x60($a0)
    ctx->r11 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA5F8: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x800CA5FC: jr          $ra
    // 0x800CA600: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    return;
    // 0x800CA600: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
;}
RECOMP_FUNC void enterlevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC4A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AC4A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AC4AC: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x800AC4B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AC4B4: andi        $a1, $s0, 0x2
    ctx->r5 = ctx->r16 & 0X2;
    // 0x800AC4B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AC4BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AC4C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AC4C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800AC4C8: beq         $a1, $at, L_800AC4E0
    if (ctx->r5 == ctx->r1) {
        // 0x800AC4CC: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_800AC4E0;
    }
    // 0x800AC4CC: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800AC4D0: lui         $s2, 0x802B
    ctx->r18 = S32(0X802B << 16);
    // 0x800AC4D4: addiu       $s2, $s2, -0x5598
    ctx->r18 = ADD32(ctx->r18, -0X5598);
    // 0x800AC4D8: lw          $t6, 0x16C($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X16C));
    // 0x800AC4DC: sw          $t6, 0x154($s2)
    MEM_W(0X154, ctx->r18) = ctx->r14;
L_800AC4E0:
    // 0x800AC4E0: lui         $s2, 0x802B
    ctx->r18 = S32(0X802B << 16);
    // 0x800AC4E4: addiu       $s2, $s2, -0x5598
    ctx->r18 = ADD32(ctx->r18, -0X5598);
    // 0x800AC4E8: lw          $v1, 0x18C($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X18C));
    // 0x800AC4EC: lw          $t7, 0x164($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X164));
    // 0x800AC4F0: lw          $t8, 0x160($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X160));
    // 0x800AC4F4: lw          $t9, 0x168($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X168));
    // 0x800AC4F8: lw          $t0, 0x170($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X170));
    // 0x800AC4FC: lw          $t1, 0x138($s2)
    ctx->r9 = S32(MEM_W(ctx->r18, 0X138));
    // 0x800AC500: lw          $t2, 0x178($s2)
    ctx->r10 = S32(MEM_W(ctx->r18, 0X178));
    // 0x800AC504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AC508: sw          $v0, 0x1A0($s2)
    MEM_W(0X1A0, ctx->r18) = ctx->r2;
    // 0x800AC50C: sw          $t7, 0x148($s2)
    MEM_W(0X148, ctx->r18) = ctx->r15;
    // 0x800AC510: sw          $t8, 0x14C($s2)
    MEM_W(0X14C, ctx->r18) = ctx->r24;
    // 0x800AC514: sw          $t9, 0x150($s2)
    MEM_W(0X150, ctx->r18) = ctx->r25;
    // 0x800AC518: sw          $t0, 0x158($s2)
    MEM_W(0X158, ctx->r18) = ctx->r8;
    // 0x800AC51C: sw          $t1, 0x13C($s2)
    MEM_W(0X13C, ctx->r18) = ctx->r9;
    // 0x800AC520: beq         $v0, $v1, L_800AC530
    if (ctx->r2 == ctx->r3) {
        // 0x800AC524: sw          $t2, 0x17C($s2)
        MEM_W(0X17C, ctx->r18) = ctx->r10;
            goto L_800AC530;
    }
    // 0x800AC524: sw          $t2, 0x17C($s2)
    MEM_W(0X17C, ctx->r18) = ctx->r10;
    // 0x800AC528: bnel        $v0, $t1, L_800AC540
    if (ctx->r2 != ctx->r9) {
        // 0x800AC52C: lw          $t4, 0x190($s2)
        ctx->r12 = S32(MEM_W(ctx->r18, 0X190));
            goto L_800AC540;
    }
    goto skip_0;
    // 0x800AC52C: lw          $t4, 0x190($s2)
    ctx->r12 = S32(MEM_W(ctx->r18, 0X190));
    skip_0:
L_800AC530:
    // 0x800AC530: sw          $zero, 0x14C($s2)
    MEM_W(0X14C, ctx->r18) = 0;
    // 0x800AC534: sw          $zero, 0x150($s2)
    MEM_W(0X150, ctx->r18) = 0;
    // 0x800AC538: sw          $zero, 0x148($s2)
    MEM_W(0X148, ctx->r18) = 0;
    // 0x800AC53C: lw          $t4, 0x190($s2)
    ctx->r12 = S32(MEM_W(ctx->r18, 0X190));
L_800AC540:
    // 0x800AC540: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800AC544: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800AC548: bnel        $t4, $at, L_800AC558
    if (ctx->r12 != ctx->r1) {
        // 0x800AC54C: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800AC558;
    }
    goto skip_1;
    // 0x800AC54C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    skip_1:
    // 0x800AC550: sw          $v0, 0x148($s2)
    MEM_W(0X148, ctx->r18) = ctx->r2;
    // 0x800AC554: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_800AC558:
    // 0x800AC558: bne         $at, $zero, L_800AC57C
    if (ctx->r1 != 0) {
        // 0x800AC55C: nop
    
            goto L_800AC57C;
    }
    // 0x800AC55C: nop

    // 0x800AC560: lw          $t5, 0x13C($s2)
    ctx->r13 = S32(MEM_W(ctx->r18, 0X13C));
    // 0x800AC564: bne         $t5, $zero, L_800AC57C
    if (ctx->r13 != 0) {
        // 0x800AC568: nop
    
            goto L_800AC57C;
    }
    // 0x800AC568: nop

    // 0x800AC56C: sw          $v0, 0x158($s2)
    MEM_W(0X158, ctx->r18) = ctx->r2;
    // 0x800AC570: sw          $v0, 0x14C($s2)
    MEM_W(0X14C, ctx->r18) = ctx->r2;
    // 0x800AC574: sw          $v0, 0x150($s2)
    MEM_W(0X150, ctx->r18) = ctx->r2;
    // 0x800AC578: sw          $zero, 0x148($s2)
    MEM_W(0X148, ctx->r18) = 0;
L_800AC57C:
    // 0x800AC57C: bnel        $a1, $zero, L_800AC59C
    if (ctx->r5 != 0) {
        // 0x800AC580: sw          $zero, 0x140($s2)
        MEM_W(0X140, ctx->r18) = 0;
            goto L_800AC59C;
    }
    goto skip_2;
    // 0x800AC580: sw          $zero, 0x140($s2)
    MEM_W(0X140, ctx->r18) = 0;
    skip_2:
    // 0x800AC584: lw          $t6, 0x154($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X154));
    // 0x800AC588: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AC58C: bnel        $t6, $at, L_800AC59C
    if (ctx->r14 != ctx->r1) {
        // 0x800AC590: sw          $zero, 0x140($s2)
        MEM_W(0X140, ctx->r18) = 0;
            goto L_800AC59C;
    }
    goto skip_3;
    // 0x800AC590: sw          $zero, 0x140($s2)
    MEM_W(0X140, ctx->r18) = 0;
    skip_3:
    // 0x800AC594: sw          $zero, 0x154($s2)
    MEM_W(0X154, ctx->r18) = 0;
    // 0x800AC598: sw          $zero, 0x140($s2)
    MEM_W(0X140, ctx->r18) = 0;
L_800AC59C:
    // 0x800AC59C: lbu         $t7, 0x377C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X377C);
    // 0x800AC5A0: beq         $t7, $zero, L_800AC5E4
    if (ctx->r15 == 0) {
        // 0x800AC5A4: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800AC5E4;
    }
    // 0x800AC5A4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AC5A8: lh          $v0, 0x3750($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X3750));
    // 0x800AC5AC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x800AC5B0: blez        $v0, L_800AC5D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AC5B4: nop
    
            goto L_800AC5D0;
    }
    // 0x800AC5B4: nop

    // 0x800AC5B8: jal         0x80055088
    // 0x800AC5BC: nop

    loadgame(rdram, ctx);
        goto after_0;
    // 0x800AC5BC: nop

    after_0:
    // 0x800AC5C0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800AC5C4: lh          $v0, 0x3750($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X3750));
    // 0x800AC5C8: b           L_800AC5D0
    // 0x800AC5CC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
        goto L_800AC5D0;
    // 0x800AC5CC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_800AC5D0:
    // 0x800AC5D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800AC5D4: sb          $zero, 0x377C($at)
    MEM_B(0X377C, ctx->r1) = 0;
    // 0x800AC5D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800AC5DC: sh          $v0, 0x3754($at)
    MEM_H(0X3754, ctx->r1) = ctx->r2;
    // 0x800AC5E0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_800AC5E4:
    // 0x800AC5E4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800AC5E8: jal         0x8005B5F0
    // 0x800AC5EC: lh          $a0, 0x3750($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3750));
    func_8005B5F0(rdram, ctx);
        goto after_1;
    // 0x800AC5EC: lh          $a0, 0x3750($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X3750));
    after_1:
    // 0x800AC5F0: jal         0x800AB350
    // 0x800AC5F4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    prelevel(rdram, ctx);
        goto after_2;
    // 0x800AC5F4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x800AC5F8: jal         0x800B2E9C
    // 0x800AC5FC: nop

    allignwarpelevators(rdram, ctx);
        goto after_3;
    // 0x800AC5FC: nop

    after_3:
    // 0x800AC600: jal         0x800ABF64
    // 0x800AC604: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    resetpspritevars(rdram, ctx);
        goto after_4;
    // 0x800AC604: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_4:
    // 0x800AC608: andi        $t8, $s1, 0x4
    ctx->r24 = ctx->r17 & 0X4;
    // 0x800AC60C: bne         $t8, $zero, L_800AC61C
    if (ctx->r24 != 0) {
        // 0x800AC610: andi        $t9, $s1, 0x8
        ctx->r25 = ctx->r17 & 0X8;
            goto L_800AC61C;
    }
    // 0x800AC610: andi        $t9, $s1, 0x8
    ctx->r25 = ctx->r17 & 0X8;
    // 0x800AC614: beq         $t9, $zero, L_800AC62C
    if (ctx->r25 == 0) {
        // 0x800AC618: andi        $t1, $s1, 0x20
        ctx->r9 = ctx->r17 & 0X20;
            goto L_800AC62C;
    }
    // 0x800AC618: andi        $t1, $s1, 0x20
    ctx->r9 = ctx->r17 & 0X20;
L_800AC61C:
    // 0x800AC61C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800AC620: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800AC624: b           L_800AC65C
    // 0x800AC628: sb          $t0, 0x5AA8($at)
    MEM_B(0X5AA8, ctx->r1) = ctx->r8;
        goto L_800AC65C;
    // 0x800AC628: sb          $t0, 0x5AA8($at)
    MEM_B(0X5AA8, ctx->r1) = ctx->r8;
L_800AC62C:
    // 0x800AC62C: beql        $t1, $zero, L_800AC660
    if (ctx->r9 == 0) {
        // 0x800AC630: lw          $v1, 0x18C($s2)
        ctx->r3 = S32(MEM_W(ctx->r18, 0X18C));
            goto L_800AC660;
    }
    goto skip_4;
    // 0x800AC630: lw          $v1, 0x18C($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X18C));
    skip_4:
    // 0x800AC634: lw          $t2, 0x154($s2)
    ctx->r10 = S32(MEM_W(ctx->r18, 0X154));
    // 0x800AC638: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AC63C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800AC640: bne         $t2, $at, L_800AC654
    if (ctx->r10 != ctx->r1) {
        // 0x800AC644: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_800AC654;
    }
    // 0x800AC644: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800AC648: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800AC64C: b           L_800AC65C
    // 0x800AC650: sb          $t3, 0x5AA8($at)
    MEM_B(0X5AA8, ctx->r1) = ctx->r11;
        goto L_800AC65C;
    // 0x800AC650: sb          $t3, 0x5AA8($at)
    MEM_B(0X5AA8, ctx->r1) = ctx->r11;
L_800AC654:
    // 0x800AC654: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800AC658: sb          $t4, 0x5AA8($at)
    MEM_B(0X5AA8, ctx->r1) = ctx->r12;
L_800AC65C:
    // 0x800AC65C: lw          $v1, 0x18C($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X18C));
L_800AC660:
    // 0x800AC660: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AC664: blez        $v1, L_800AC71C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AC668: sll         $t5, $s1, 3
        ctx->r13 = S32(ctx->r17 << 3);
            goto L_800AC71C;
    }
    // 0x800AC668: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
L_800AC66C:
    // 0x800AC66C: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800AC670: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800AC674: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x800AC678: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800AC67C: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800AC680: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800AC684: addiu       $t6, $t6, 0x5770
    ctx->r14 = ADD32(ctx->r14, 0X5770);
    // 0x800AC688: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800AC68C: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x800AC690: lh          $t7, 0x288($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800AC694: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800AC698: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800AC69C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AC6A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800AC6A4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800AC6A8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800AC6AC: lh          $v0, -0x1974($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X1974));
    // 0x800AC6B0: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800AC6B4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AC6B8: beq         $v0, $at, L_800AC6D0
    if (ctx->r2 == ctx->r1) {
        // 0x800AC6BC: addiu       $at, $zero, 0x35B
        ctx->r1 = ADD32(0, 0X35B);
            goto L_800AC6D0;
    }
    // 0x800AC6BC: addiu       $at, $zero, 0x35B
    ctx->r1 = ADD32(0, 0X35B);
    // 0x800AC6C0: beq         $v0, $at, L_800AC6D0
    if (ctx->r2 == ctx->r1) {
        // 0x800AC6C4: addiu       $at, $zero, 0x43A
        ctx->r1 = ADD32(0, 0X43A);
            goto L_800AC6D0;
    }
    // 0x800AC6C4: addiu       $at, $zero, 0x43A
    ctx->r1 = ADD32(0, 0X43A);
    // 0x800AC6C8: bnel        $v0, $at, L_800AC708
    if (ctx->r2 != ctx->r1) {
        // 0x800AC6CC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800AC708;
    }
    goto skip_5;
    // 0x800AC6CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
L_800AC6D0:
    // 0x800AC6D0: jal         0x800AB04C
    // 0x800AC6D4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    resetweapons(rdram, ctx);
        goto after_5;
    // 0x800AC6D4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_5:
    // 0x800AC6D8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800AC6DC: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AC6E0: jal         0x800AB118
    // 0x800AC6E4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    resetinventory(rdram, ctx);
        goto after_6;
    // 0x800AC6E4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_6:
    // 0x800AC6E8: sb          $zero, 0x34A($s0)
    MEM_B(0X34A, ctx->r16) = 0;
    // 0x800AC6EC: sb          $zero, 0x355($s0)
    MEM_B(0X355, ctx->r16) = 0;
    // 0x800AC6F0: sh          $zero, 0x290($s0)
    MEM_H(0X290, ctx->r16) = 0;
    // 0x800AC6F4: sh          $zero, 0x2B2($s0)
    MEM_H(0X2B2, ctx->r16) = 0;
    // 0x800AC6F8: sh          $zero, 0x372($s0)
    MEM_H(0X372, ctx->r16) = 0;
    // 0x800AC6FC: sh          $zero, 0x2D4($s0)
    MEM_H(0X2D4, ctx->r16) = 0;
    // 0x800AC700: lw          $v1, 0x18C($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X18C));
    // 0x800AC704: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800AC708:
    // 0x800AC708: sll         $t1, $s1, 16
    ctx->r9 = S32(ctx->r17 << 16);
    // 0x800AC70C: sra         $s1, $t1, 16
    ctx->r17 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800AC710: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AC714: bnel        $at, $zero, L_800AC66C
    if (ctx->r1 != 0) {
        // 0x800AC718: sll         $t5, $s1, 3
        ctx->r13 = S32(ctx->r17 << 3);
            goto L_800AC66C;
    }
    goto skip_6;
    // 0x800AC718: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    skip_6:
L_800AC71C:
    // 0x800AC71C: jal         0x800AC36C
    // 0x800AC720: nop

    resetmys(rdram, ctx);
        goto after_7;
    // 0x800AC720: nop

    after_7:
    // 0x800AC724: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800AC728: sw          $zero, 0x5ACC($at)
    MEM_W(0X5ACC, ctx->r1) = 0;
    // 0x800AC72C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AC730: sb          $zero, -0x5388($at)
    MEM_B(-0X5388, ctx->r1) = 0;
    // 0x800AC734: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800AC738: sh          $zero, -0x55BE($at)
    MEM_H(-0X55BE, ctx->r1) = 0;
    // 0x800AC73C: lw          $t3, 0x194($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X194));
    // 0x800AC740: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x800AC744: lui         $a0, 0x802B
    ctx->r4 = S32(0X802B << 16);
    // 0x800AC748: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800AC74C: sh          $t4, 0xF0($s2)
    MEM_H(0XF0, ctx->r18) = ctx->r12;
    // 0x800AC750: lw          $s1, 0x1390($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X1390));
    // 0x800AC754: lui         $v1, 0x802A
    ctx->r3 = S32(0X802A << 16);
    // 0x800AC758: addiu       $v1, $v1, 0x75A0
    ctx->r3 = ADD32(ctx->r3, 0X75A0);
    // 0x800AC75C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800AC760: sll         $t5, $s1, 16
    ctx->r13 = S32(ctx->r17 << 16);
    // 0x800AC764: sra         $s1, $t5, 16
    ctx->r17 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800AC768: bltz        $s1, L_800AC798
    if (SIGNED(ctx->r17) < 0) {
        // 0x800AC76C: addiu       $a0, $a0, -0x7A60
        ctx->r4 = ADD32(ctx->r4, -0X7A60);
            goto L_800AC798;
    }
    // 0x800AC76C: addiu       $a0, $a0, -0x7A60
    ctx->r4 = ADD32(ctx->r4, -0X7A60);
L_800AC770:
    // 0x800AC770: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800AC774: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x800AC778: lw          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800AC77C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800AC780: sll         $t1, $s1, 16
    ctx->r9 = S32(ctx->r17 << 16);
    // 0x800AC784: lw          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X0));
    // 0x800AC788: sra         $s1, $t1, 16
    ctx->r17 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800AC78C: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x800AC790: bgez        $s1, L_800AC770
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800AC794: sw          $t9, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r25;
            goto L_800AC770;
    }
    // 0x800AC794: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_800AC798:
    // 0x800AC798: jal         0x8005932C
    // 0x800AC79C: nop

    stopallsounds(rdram, ctx);
        goto after_8;
    // 0x800AC79C: nop

    after_8:
    // 0x800AC7A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AC7A4: jal         0x80059398
    // 0x800AC7A8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80059398(rdram, ctx);
        goto after_9;
    // 0x800AC7A8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_9:
    // 0x800AC7AC: jal         0x800AC2A8
    // 0x800AC7B0: nop

    clearfrags(rdram, ctx);
        goto after_10;
    // 0x800AC7B0: nop

    after_10:
    // 0x800AC7B4: jal         0x800AC324
    // 0x800AC7B8: nop

    resettimevars(rdram, ctx);
        goto after_11;
    // 0x800AC7B8: nop

    after_11:
    // 0x800AC7BC: jal         0x8006EC0C
    // 0x800AC7C0: nop

    resetsbarscroll(rdram, ctx);
        goto after_12;
    // 0x800AC7C0: nop

    after_12:
    // 0x800AC7C4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AC7C8: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800AC7CC: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800AC7D0: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800AC7D4: jr          $ra
    // 0x800AC7D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AC7D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8005B720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B720: jr          $ra
    // 0x8005B724: nop

    return;
    // 0x8005B724: nop

;}
RECOMP_FUNC void rotatesprite_simplest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C9BC: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8005C9C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005C9C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005C9C8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005C9CC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005C9D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005C9D4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8005C9D8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8005C9DC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8005C9E0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8005C9E4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8005C9E8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005C9EC: sw          $a2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r6;
    // 0x8005C9F0: andi        $s0, $a2, 0xFFFF
    ctx->r16 = ctx->r6 & 0XFFFF;
    // 0x8005C9F4: jal         0x8006370C
    // 0x8005C9F8: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    gettileid(rdram, ctx);
        goto after_0;
    // 0x8005C9F8: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    after_0:
    // 0x8005C9FC: addiu       $s5, $zero, 0x1C
    ctx->r21 = ADD32(0, 0X1C);
    // 0x8005CA00: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CA04: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8005CA08: addiu       $s4, $s4, -0x5010
    ctx->r20 = ADD32(ctx->r20, -0X5010);
    // 0x8005CA0C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8005CA10: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x8005CA14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CA18: mflo        $t7
    ctx->r15 = lo;
    // 0x8005CA1C: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8005CA20: lw          $t9, 0x8($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X8));
    // 0x8005CA24: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8005CA28: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8005CA2C: andi        $t6, $t9, 0xC0
    ctx->r14 = ctx->r25 & 0XC0;
    // 0x8005CA30: beql        $t6, $zero, L_8005CA54
    if (ctx->r14 == 0) {
        // 0x8005CA34: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005CA54;
    }
    goto skip_0;
    // 0x8005CA34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8005CA38: jal         0x8009223C
    // 0x8005CA3C: sh          $a2, 0x122($sp)
    MEM_H(0X122, ctx->r29) = ctx->r6;
    animateoffs(rdram, ctx);
        goto after_1;
    // 0x8005CA3C: sh          $a2, 0x122($sp)
    MEM_H(0X122, ctx->r29) = ctx->r6;
    after_1:
    // 0x8005CA40: lhu         $a2, 0x122($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X122);
    // 0x8005CA44: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8005CA48: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x8005CA4C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8005CA50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8005CA54:
    // 0x8005CA54: beql        $a2, $at, L_8005D114
    if (ctx->r6 == ctx->r1) {
        // 0x8005CA58: lw          $ra, 0x34($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
            goto L_8005D114;
    }
    goto skip_1;
    // 0x8005CA58: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    skip_1:
    // 0x8005CA5C: multu       $a2, $s5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CA60: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8005CA64: mflo        $t9
    ctx->r25 = lo;
    // 0x8005CA68: addu        $s7, $s4, $t9
    ctx->r23 = ADD32(ctx->r20, ctx->r25);
    // 0x8005CA6C: lw          $v0, 0x8($s7)
    ctx->r2 = S32(MEM_W(ctx->r23, 0X8));
    // 0x8005CA70: lh          $v1, 0xC($s7)
    ctx->r3 = S32(MEM_H(ctx->r23, 0XC));
    // 0x8005CA74: lh          $a1, 0xE($s7)
    ctx->r5 = S32(MEM_H(ctx->r23, 0XE));
    // 0x8005CA78: andi        $t6, $v0, 0xFF00
    ctx->r14 = ctx->r2 & 0XFF00;
    // 0x8005CA7C: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8005CA80: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8005CA84: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8005CA88: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005CA8C: sra         $t9, $t8, 24
    ctx->r25 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8005CA90: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8005CA94: lhu         $t0, 0x12($s7)
    ctx->r8 = MEM_HU(ctx->r23, 0X12);
    // 0x8005CA98: subu        $s1, $s1, $t9
    ctx->r17 = SUB32(ctx->r17, ctx->r25);
    // 0x8005CA9C: sra         $t9, $t8, 24
    ctx->r25 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8005CAA0: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8005CAA4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8005CAA8: subu        $s2, $s2, $t9
    ctx->r18 = SUB32(ctx->r18, ctx->r25);
    // 0x8005CAAC: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8005CAB0: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8005CAB4: bgez        $v1, L_8005CAC4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005CAB8: sra         $t6, $v1, 1
        ctx->r14 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8005CAC4;
    }
    // 0x8005CAB8: sra         $t6, $v1, 1
    ctx->r14 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8005CABC: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x8005CAC0: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8005CAC4:
    // 0x8005CAC4: subu        $t3, $s1, $t6
    ctx->r11 = SUB32(ctx->r17, ctx->r14);
    // 0x8005CAC8: bgez        $a1, L_8005CAD8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8005CACC: sra         $t7, $a1, 1
        ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8005CAD8;
    }
    // 0x8005CACC: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8005CAD0: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x8005CAD4: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8005CAD8:
    // 0x8005CAD8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8005CADC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005CAE0: addu        $t8, $v1, $t3
    ctx->r24 = ADD32(ctx->r3, ctx->r11);
    // 0x8005CAE4: subu        $s3, $s2, $t7
    ctx->r19 = SUB32(ctx->r18, ctx->r15);
    // 0x8005CAE8: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x8005CAEC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005CAF0: bgez        $t0, L_8005CB08
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005CAF4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8005CB08;
    }
    // 0x8005CAF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005CAF8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005CAFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005CB00: nop

    // 0x8005CB04: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8005CB08:
    // 0x8005CB08: div.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8005CB0C: lhu         $v0, 0x14($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X14);
    // 0x8005CB10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8005CB14: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8005CB18: nop

    // 0x8005CB1C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005CB20: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005CB24: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x8005CB28: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8005CB2C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005CB30: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8005CB34: bgez        $v0, L_8005CB48
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005CB38: sw          $t6, 0x104($sp)
        MEM_W(0X104, ctx->r29) = ctx->r14;
            goto L_8005CB48;
    }
    // 0x8005CB38: sw          $t6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r14;
    // 0x8005CB3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005CB40: nop

    // 0x8005CB44: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_8005CB48:
    // 0x8005CB48: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8005CB4C: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CB50: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x8005CB54: sh          $a2, 0x122($sp)
    MEM_H(0X122, ctx->r29) = ctx->r6;
    // 0x8005CB58: sw          $t3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r11;
    // 0x8005CB5C: mflo        $a3
    ctx->r7 = lo;
    // 0x8005CB60: addiu       $t1, $a3, 0xFFF
    ctx->r9 = ADD32(ctx->r7, 0XFFF);
    // 0x8005CB64: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005CB68: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8005CB6C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8005CB70: nop

    // 0x8005CB74: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
    // 0x8005CB78: bgez        $t1, L_8005CB88
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005CB7C: sra         $t9, $t1, 12
        ctx->r25 = S32(SIGNED(ctx->r9) >> 12);
            goto L_8005CB88;
    }
    // 0x8005CB7C: sra         $t9, $t1, 12
    ctx->r25 = S32(SIGNED(ctx->r9) >> 12);
    // 0x8005CB80: addiu       $at, $t1, 0xFFF
    ctx->r1 = ADD32(ctx->r9, 0XFFF);
    // 0x8005CB84: sra         $t9, $at, 12
    ctx->r25 = S32(SIGNED(ctx->r1) >> 12);
L_8005CB88:
    // 0x8005CB88: sw          $t9, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r25;
    // 0x8005CB8C: jal         0x80063880
    // 0x8005CB90: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    func_80063880(rdram, ctx);
        goto after_2;
    // 0x8005CB90: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    after_2:
    // 0x8005CB94: lw          $t1, 0x4C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8005CB98: lhu         $a1, 0x14($s7)
    ctx->r5 = MEM_HU(ctx->r23, 0X14);
    // 0x8005CB9C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8005CBA0: addiu       $t2, $t2, 0x4418
    ctx->r10 = ADD32(ctx->r10, 0X4418);
    // 0x8005CBA4: div         $zero, $a1, $t1
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r9)));
    // 0x8005CBA8: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CBAC: lh          $a3, 0xE($s7)
    ctx->r7 = S32(MEM_H(ctx->r23, 0XE));
    // 0x8005CBB0: lhu         $a2, 0x122($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X122);
    // 0x8005CBB4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005CBB8: lw          $t3, 0x114($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X114));
    // 0x8005CBBC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8005CBC0: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8005CBC4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005CBC8: mflo        $s6
    ctx->r22 = lo;
    // 0x8005CBCC: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x8005CBD0: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8005CBD4: addiu       $s2, $v0, 0x20
    ctx->r18 = ADD32(ctx->r2, 0X20);
    // 0x8005CBD8: bne         $t1, $zero, L_8005CBE4
    if (ctx->r9 != 0) {
        // 0x8005CBDC: nop
    
            goto L_8005CBE4;
    }
    // 0x8005CBDC: nop

    // 0x8005CBE0: break       7
    do_break(2147863520);
L_8005CBE4:
    // 0x8005CBE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005CBE8: bne         $t1, $at, L_8005CBFC
    if (ctx->r9 != ctx->r1) {
        // 0x8005CBEC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005CBFC;
    }
    // 0x8005CBEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005CBF0: bne         $a1, $at, L_8005CBFC
    if (ctx->r5 != ctx->r1) {
        // 0x8005CBF4: nop
    
            goto L_8005CBFC;
    }
    // 0x8005CBF4: nop

    // 0x8005CBF8: break       6
    do_break(2147863544);
L_8005CBFC:
    // 0x8005CBFC: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8005CC00: sw          $t6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r14;
    // 0x8005CC04: sw          $t4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r12;
    // 0x8005CC08: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005CC0C: sw          $v1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r3;
    // 0x8005CC10: jal         0x80063880
    // 0x8005CC14: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80063880(rdram, ctx);
        goto after_3;
    // 0x8005CC14: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8005CC18: lw          $t5, 0xC0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x8005CC1C: lw          $t1, 0x4C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8005CC20: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8005CC24: lw          $t3, 0x114($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X114));
    // 0x8005CC28: lw          $t4, 0xDC($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XDC));
    // 0x8005CC2C: addiu       $t2, $t2, 0x4418
    ctx->r10 = ADD32(ctx->r10, 0X4418);
    // 0x8005CC30: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x8005CC34: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CC38: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8005CC3C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8005CC40: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005CC44: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005CC48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005CC4C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005CC50: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005CC54: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CC58: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8005CC5C: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8005CC60: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005CC64: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8005CC68: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005CC6C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005CC70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005CC74: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CC78: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8005CC7C: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8005CC80: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005CC84: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005CC88: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005CC8C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005CC90: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8005CC94: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CC98: lui         $t6, 0x703
    ctx->r14 = S32(0X703 << 16);
    // 0x8005CC9C: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8005CCA0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005CCA4: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8005CCA8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005CCAC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005CCB0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8005CCB4: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CCB8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8005CCBC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8005CCC0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005CCC4: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8005CCC8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005CCCC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005CCD0: blez        $t1, L_8005D110
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8005CCD4: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8005D110;
    }
    // 0x8005CCD4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8005CCD8: lw          $v0, 0xCC($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x8005CCDC: or          $ra, $t3, $zero
    ctx->r31 = ctx->r11 | 0;
    // 0x8005CCE0: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8005CCE4: addiu       $t6, $t9, 0x7
    ctx->r14 = ADD32(ctx->r25, 0X7);
    // 0x8005CCE8: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8005CCEC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8005CCF0: bgez        $v0, L_8005CD00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005CCF4: sra         $t5, $v0, 4
        ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
            goto L_8005CD00;
    }
    // 0x8005CCF4: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8005CCF8: addiu       $at, $v0, 0xF
    ctx->r1 = ADD32(ctx->r2, 0XF);
    // 0x8005CCFC: sra         $t5, $at, 4
    ctx->r13 = S32(SIGNED(ctx->r1) >> 4);
L_8005CD00:
    // 0x8005CD00: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x8005CD04: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8005CD08: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005CD0C: lw          $t7, 0x10C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X10C));
    // 0x8005CD10: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8005CD14: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8005CD18: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8005CD1C: sll         $t8, $t7, 18
    ctx->r24 = S32(ctx->r15 << 18);
    // 0x8005CD20: lw          $t7, 0x100($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X100));
    // 0x8005CD24: sra         $s4, $t8, 16
    ctx->r20 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8005CD28: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8005CD2C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8005CD30: lw          $t7, 0xE0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x8005CD34: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8005CD38: lw          $t9, 0x104($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X104));
    // 0x8005CD3C: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x8005CD40: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8005CD44: sll         $t6, $ra, 18
    ctx->r14 = S32(ctx->r31 << 18);
    // 0x8005CD48: sra         $ra, $t6, 16
    ctx->r31 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8005CD4C: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8005CD50: mflo        $s5
    ctx->r21 = lo;
    // 0x8005CD54: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8005CD58: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8005CD5C: bne         $t1, $zero, L_8005CD68
    if (ctx->r9 != 0) {
        // 0x8005CD60: nop
    
            goto L_8005CD68;
    }
    // 0x8005CD60: nop

    // 0x8005CD64: break       7
    do_break(2147863908);
L_8005CD68:
    // 0x8005CD68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005CD6C: bne         $t1, $at, L_8005CD80
    if (ctx->r9 != ctx->r1) {
        // 0x8005CD70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005CD80;
    }
    // 0x8005CD70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005CD74: bne         $t7, $at, L_8005CD80
    if (ctx->r15 != ctx->r1) {
        // 0x8005CD78: nop
    
            goto L_8005CD80;
    }
    // 0x8005CD78: nop

    // 0x8005CD7C: break       6
    do_break(2147863932);
L_8005CD80:
    // 0x8005CD80: slt         $at, $s0, $s6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r22) ? 1 : 0;
L_8005CD84:
    // 0x8005CD84: beq         $at, $zero, L_8005CD94
    if (ctx->r1 == 0) {
        // 0x8005CD88: or          $t0, $s6, $zero
        ctx->r8 = ctx->r22 | 0;
            goto L_8005CD94;
    }
    // 0x8005CD88: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
    // 0x8005CD8C: b           L_8005CD94
    // 0x8005CD90: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
        goto L_8005CD94;
    // 0x8005CD90: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_8005CD94:
    // 0x8005CD94: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CD98: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8005CD9C: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8005CDA0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005CDA4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005CDA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005CDAC: sw          $s2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r18;
    // 0x8005CDB0: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CDB4: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8005CDB8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005CDBC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005CDC0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005CDC4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005CDC8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8005CDCC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005CDD0: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CDD4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005CDD8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8005CDDC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8005CDE0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8005CDE4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005CDE8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005CDEC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005CDF0: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CDF4: subu        $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
    // 0x8005CDF8: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8005CDFC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005CE00: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8005CE04: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005CE08: lw          $t8, 0xCC($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x8005CE0C: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8005CE10: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8005CE14: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CE18: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8005CE1C: mflo        $a2
    ctx->r6 = lo;
    // 0x8005CE20: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8005CE24: sra         $t9, $a2, 2
    ctx->r25 = S32(SIGNED(ctx->r6) >> 2);
    // 0x8005CE28: addiu       $a2, $t9, -0x1
    ctx->r6 = ADD32(ctx->r25, -0X1);
    // 0x8005CE2C: slti        $at, $a2, 0x7FF
    ctx->r1 = SIGNED(ctx->r6) < 0X7FF ? 1 : 0;
    // 0x8005CE30: beq         $at, $zero, L_8005CE40
    if (ctx->r1 == 0) {
        // 0x8005CE34: nop
    
            goto L_8005CE40;
    }
    // 0x8005CE34: nop

    // 0x8005CE38: b           L_8005CE40
    // 0x8005CE3C: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
        goto L_8005CE40;
    // 0x8005CE3C: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
L_8005CE40:
    // 0x8005CE40: bgtz        $t5, L_8005CE50
    if (SIGNED(ctx->r13) > 0) {
        // 0x8005CE44: nop
    
            goto L_8005CE50;
    }
    // 0x8005CE44: nop

    // 0x8005CE48: b           L_8005CE50
    // 0x8005CE4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8005CE50;
    // 0x8005CE4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8005CE50:
    // 0x8005CE50: bgtz        $t5, L_8005CE60
    if (SIGNED(ctx->r13) > 0) {
        // 0x8005CE54: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_8005CE60;
    }
    // 0x8005CE54: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x8005CE58: b           L_8005CE60
    // 0x8005CE5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005CE60;
    // 0x8005CE5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005CE60:
    // 0x8005CE60: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x8005CE64: bne         $v0, $zero, L_8005CE70
    if (ctx->r2 != 0) {
        // 0x8005CE68: nop
    
            goto L_8005CE70;
    }
    // 0x8005CE68: nop

    // 0x8005CE6C: break       7
    do_break(2147864172);
L_8005CE70:
    // 0x8005CE70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005CE74: bne         $v0, $at, L_8005CE88
    if (ctx->r2 != ctx->r1) {
        // 0x8005CE78: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005CE88;
    }
    // 0x8005CE78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005CE7C: bne         $t7, $at, L_8005CE88
    if (ctx->r15 != ctx->r1) {
        // 0x8005CE80: nop
    
            goto L_8005CE88;
    }
    // 0x8005CE80: nop

    // 0x8005CE84: break       6
    do_break(2147864196);
L_8005CE88:
    // 0x8005CE88: mflo        $t6
    ctx->r14 = lo;
    // 0x8005CE8C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8005CE90: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005CE94: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x8005CE98: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8005CE9C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8005CEA0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8005CEA4: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8005CEA8: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CEAC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005CEB0: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x8005CEB4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005CEB8: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8005CEBC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8005CEC0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8005CEC4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8005CEC8: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CECC: lw          $t8, 0x54($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8005CED0: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8005CED4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005CED8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005CEDC: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8005CEE0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005CEE4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8005CEE8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005CEEC: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CEF0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8005CEF4: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x8005CEF8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8005CEFC: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005CF00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005CF04: lw          $t8, 0x50($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X50));
    // 0x8005CF08: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005CF0C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8005CF10: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8005CF14: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005CF18: lhu         $t9, 0x12($s7)
    ctx->r25 = MEM_HU(ctx->r23, 0X12);
    // 0x8005CF1C: sll         $a0, $t4, 16
    ctx->r4 = S32(ctx->r12 << 16);
    // 0x8005CF20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005CF24: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CF28: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8005CF2C: mflo        $t8
    ctx->r24 = lo;
    // 0x8005CF30: bgez        $t8, L_8005CF40
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005CF34: sra         $t6, $t8, 1
        ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8005CF40;
    }
    // 0x8005CF34: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8005CF38: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8005CF3C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8005CF40:
    // 0x8005CF40: bgez        $t6, L_8005CF50
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005CF44: sra         $t7, $t6, 2
        ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
            goto L_8005CF50;
    }
    // 0x8005CF44: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x8005CF48: addiu       $at, $t6, 0x3
    ctx->r1 = ADD32(ctx->r14, 0X3);
    // 0x8005CF4C: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_8005CF50:
    // 0x8005CF50: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005CF54: slt         $at, $s1, $s5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8005CF58: beq         $at, $zero, L_8005CF68
    if (ctx->r1 == 0) {
        // 0x8005CF5C: addu        $s2, $s2, $t9
        ctx->r18 = ADD32(ctx->r18, ctx->r25);
            goto L_8005CF68;
    }
    // 0x8005CF5C: addu        $s2, $s2, $t9
    ctx->r18 = ADD32(ctx->r18, ctx->r25);
    // 0x8005CF60: b           L_8005CF68
    // 0x8005CF64: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8005CF68;
    // 0x8005CF64: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8005CF68:
    // 0x8005CF68: lw          $a1, 0x0($t2)
    ctx->r5 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CF6C: subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // 0x8005CF70: addu        $t0, $t4, $v0
    ctx->r8 = ADD32(ctx->r12, ctx->r2);
    // 0x8005CF74: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8005CF78: blez        $s4, L_8005CF88
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8005CF7C: sw          $t8, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r24;
            goto L_8005CF88;
    }
    // 0x8005CF7C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8005CF80: b           L_8005CF88
    // 0x8005CF84: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
        goto L_8005CF88;
    // 0x8005CF84: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
L_8005CF88:
    // 0x8005CF88: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8005CF8C: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8005CF90: blez        $t6, L_8005CFA0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005CF94: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_8005CFA0;
    }
    // 0x8005CF94: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8005CF98: b           L_8005CFA4
    // 0x8005CF9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8005CFA4;
    // 0x8005CF9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8005CFA0:
    // 0x8005CFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CFA4:
    // 0x8005CFA4: andi        $t7, $v0, 0xFFF
    ctx->r15 = ctx->r2 & 0XFFF;
    // 0x8005CFA8: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x8005CFAC: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8005CFB0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8005CFB4: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8005CFB8: blez        $ra, L_8005CFC8
    if (SIGNED(ctx->r31) <= 0) {
        // 0x8005CFBC: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_8005CFC8;
    }
    // 0x8005CFBC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8005CFC0: b           L_8005CFCC
    // 0x8005CFC4: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
        goto L_8005CFCC;
    // 0x8005CFC4: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
L_8005CFC8:
    // 0x8005CFC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8005CFCC:
    // 0x8005CFCC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8005CFD0: blez        $t8, L_8005CFE0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005CFD4: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8005CFE0;
    }
    // 0x8005CFD4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8005CFD8: b           L_8005CFE4
    // 0x8005CFDC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005CFE4;
    // 0x8005CFDC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005CFE0:
    // 0x8005CFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005CFE4:
    // 0x8005CFE4: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x8005CFE8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8005CFEC: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x8005CFF0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8005CFF4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8005CFF8: lw          $a2, 0x0($t2)
    ctx->r6 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005CFFC: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8005D000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D004: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x8005D008: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005D00C: bgez        $ra, L_8005D060
    if (SIGNED(ctx->r31) >= 0) {
        // 0x8005D010: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8005D060;
    }
    // 0x8005D010: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8005D014: lh          $v0, 0x106($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X106));
    // 0x8005D018: multu       $ra, $v0
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005D01C: mflo        $v1
    ctx->r3 = lo;
    // 0x8005D020: sra         $t7, $v1, 7
    ctx->r15 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8005D024: bgez        $v0, L_8005D044
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005D028: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_8005D044;
    }
    // 0x8005D028: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8005D02C: blez        $t7, L_8005D03C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8005D030: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005D03C;
    }
    // 0x8005D030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D034: b           L_8005D060
    // 0x8005D038: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_8005D060;
    // 0x8005D038: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8005D03C:
    // 0x8005D03C: b           L_8005D060
    // 0x8005D040: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8005D060;
    // 0x8005D040: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8005D044:
    // 0x8005D044: bgez        $v1, L_8005D054
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005D048: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005D054;
    }
    // 0x8005D048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D04C: b           L_8005D054
    // 0x8005D050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8005D054;
    // 0x8005D050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8005D054:
    // 0x8005D054: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005D058: b           L_8005D060
    // 0x8005D05C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8005D060;
    // 0x8005D05C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8005D060:
    // 0x8005D060: bgez        $t4, L_8005D0C8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8005D064: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005D0C8;
    }
    // 0x8005D064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D068: lh          $v1, 0x102($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X102));
    // 0x8005D06C: bgez        $v1, L_8005D09C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005D070: nop
    
            goto L_8005D09C;
    }
    // 0x8005D070: nop

    // 0x8005D074: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005D078: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8005D07C: mflo        $v0
    ctx->r2 = lo;
    // 0x8005D080: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005D084: blez        $t8, L_8005D094
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005D088: nop
    
            goto L_8005D094;
    }
    // 0x8005D088: nop

    // 0x8005D08C: b           L_8005D0C8
    // 0x8005D090: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8005D0C8;
    // 0x8005D090: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8005D094:
    // 0x8005D094: b           L_8005D0C8
    // 0x8005D098: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8005D0C8;
    // 0x8005D098: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8005D09C:
    // 0x8005D09C: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005D0A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005D0A4: mflo        $v0
    ctx->r2 = lo;
    // 0x8005D0A8: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8005D0AC: bgez        $t6, L_8005D0BC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005D0B0: nop
    
            goto L_8005D0BC;
    }
    // 0x8005D0B0: nop

    // 0x8005D0B4: b           L_8005D0BC
    // 0x8005D0B8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_8005D0BC;
    // 0x8005D0B8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8005D0BC:
    // 0x8005D0BC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8005D0C0: b           L_8005D0C8
    // 0x8005D0C4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_8005D0C8;
    // 0x8005D0C4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8005D0C8:
    // 0x8005D0C8: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x8005D0CC: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x8005D0D0: negu        $t6, $a1
    ctx->r14 = SUB32(0, ctx->r5);
    // 0x8005D0D4: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8005D0D8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8005D0DC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8005D0E0: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8005D0E4: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8005D0E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005D0EC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8005D0F0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005D0F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005D0F8: lw          $t9, 0x38($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8005D0FC: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x8005D100: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005D104: lw          $t8, 0xF8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XF8));
    // 0x8005D108: bnel        $s3, $t8, L_8005CD84
    if (ctx->r19 != ctx->r24) {
        // 0x8005D10C: slt         $at, $s0, $s6
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8005CD84;
    }
    goto skip_2;
    // 0x8005D10C: slt         $at, $s0, $s6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r22) ? 1 : 0;
    skip_2:
L_8005D110:
    // 0x8005D110: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
L_8005D114:
    // 0x8005D114: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8005D118: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8005D11C: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8005D120: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005D124: lw          $s4, 0x24($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8005D128: lw          $s5, 0x28($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8005D12C: lw          $s6, 0x2C($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8005D130: lw          $s7, 0x30($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8005D134: jr          $ra
    // 0x8005D138: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x8005D138: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_8004D380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D384: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004D388: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004D38C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D390: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x8004D394: addiu       $t9, $t9, -0x6C30
    ctx->r25 = ADD32(ctx->r25, -0X6C30);
    // 0x8004D398: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x8004D39C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8004D3A0: addiu       $t3, $zero, 0x200
    ctx->r11 = ADD32(0, 0X200);
    // 0x8004D3A4: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8004D3A8: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x8004D3AC: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8004D3B0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004D3B4: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8004D3B8: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8004D3BC: addiu       $t1, $zero, 0x4000
    ctx->r9 = ADD32(0, 0X4000);
    // 0x8004D3C0: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x8004D3C4: addiu       $t4, $zero, 0x100
    ctx->r12 = ADD32(0, 0X100);
    // 0x8004D3C8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004D3CC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8004D3D0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8004D3D4: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8004D3D8: sw          $t4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r12;
    // 0x8004D3DC: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8004D3E0: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x8004D3E4: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x8004D3E8: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x8004D3EC: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8004D3F0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8004D3F4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8004D3F8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8004D3FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004D400: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004D404: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x8004D408: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8004D40C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8004D410: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x8004D414: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x8004D418: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x8004D41C: sw          $t8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r24;
    // 0x8004D420: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    // 0x8004D424: sw          $t0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r8;
    // 0x8004D428: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x8004D42C: sw          $t2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r10;
    // 0x8004D430: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8004D434: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8004D438: lbu         $t4, 0x5AF6($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X5AF6);
    // 0x8004D43C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D440: beql        $t4, $zero, L_8004D454
    if (ctx->r12 == 0) {
        // 0x8004D444: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8004D454;
    }
    goto skip_0;
    // 0x8004D444: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x8004D448: jal         0x8004D664
    // 0x8004D44C: nop

    func_8004D664(rdram, ctx);
        goto after_0;
    // 0x8004D44C: nop

    after_0:
    // 0x8004D450: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004D454:
    // 0x8004D454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D458: jr          $ra
    // 0x8004D45C: nop

    return;
    // 0x8004D45C: nop

;}
RECOMP_FUNC void dodge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089E4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089E50: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80089E54: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80089E58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80089E5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80089E60: lh          $v0, 0x14($a0)
    ctx->r2 = S32(MEM_H(ctx->r4, 0X14));
    // 0x80089E64: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x80089E68: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x80089E6C: addiu       $t6, $v0, 0x200
    ctx->r14 = ADD32(ctx->r2, 0X200);
    // 0x80089E70: andi        $t7, $t6, 0x7FF
    ctx->r15 = ctx->r14 & 0X7FF;
    // 0x80089E74: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80089E78: lh          $t0, 0x2860($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X2860));
    // 0x80089E7C: addiu       $t1, $t1, -0x9A0
    ctx->r9 = ADD32(ctx->r9, -0X9A0);
    // 0x80089E80: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x80089E84: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80089E88: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80089E8C: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x80089E90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80089E94: lw          $ra, 0x0($a0)
    ctx->r31 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80089E98: lw          $s1, 0x4($a0)
    ctx->r17 = S32(MEM_W(ctx->r4, 0X4));
    // 0x80089E9C: lh          $s3, 0x0($t8)
    ctx->r19 = S32(MEM_H(ctx->r24, 0X0));
    // 0x80089EA0: bltz        $t0, L_80089FD4
    if (SIGNED(ctx->r8) < 0) {
        // 0x80089EA4: lh          $s2, 0x0($t9)
        ctx->r18 = S32(MEM_H(ctx->r25, 0X0));
            goto L_80089FD4;
    }
    // 0x80089EA4: lh          $s2, 0x0($t9)
    ctx->r18 = S32(MEM_H(ctx->r25, 0X0));
    // 0x80089EA8: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x80089EAC: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x80089EB0: addiu       $t2, $t2, 0x6BA8
    ctx->r10 = ADD32(ctx->r10, 0X6BA8);
    // 0x80089EB4: addiu       $t4, $t4, 0x5F40
    ctx->r12 = ADD32(ctx->r12, 0X5F40);
    // 0x80089EB8: lui         $t5, 0x40
    ctx->r13 = S32(0X40 << 16);
    // 0x80089EBC: addiu       $t3, $zero, 0x2C
    ctx->r11 = ADD32(0, 0X2C);
L_80089EC0:
    // 0x80089EC0: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089EC4: mflo        $t9
    ctx->r25 = lo;
    // 0x80089EC8: addu        $v0, $t2, $t9
    ctx->r2 = ADD32(ctx->r10, ctx->r25);
    // 0x80089ECC: lh          $t6, 0x16($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X16));
    // 0x80089ED0: beql        $t0, $t6, L_80089FC4
    if (ctx->r8 == ctx->r14) {
        // 0x80089ED4: sll         $t6, $t0, 1
        ctx->r14 = S32(ctx->r8 << 1);
            goto L_80089FC4;
    }
    goto skip_0;
    // 0x80089ED4: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    skip_0:
    // 0x80089ED8: lh          $t7, 0x10($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X10));
    // 0x80089EDC: lh          $t8, 0x10($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X10));
    // 0x80089EE0: bnel        $t7, $t8, L_80089FC4
    if (ctx->r15 != ctx->r24) {
        // 0x80089EE4: sll         $t6, $t0, 1
        ctx->r14 = S32(ctx->r8 << 1);
            goto L_80089FC4;
    }
    goto skip_1;
    // 0x80089EE4: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    skip_1:
    // 0x80089EE8: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80089EEC: lh          $v1, 0x14($v0)
    ctx->r3 = S32(MEM_H(ctx->r2, 0X14));
    // 0x80089EF0: lw          $t6, 0x4($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80089EF4: subu        $a0, $t9, $ra
    ctx->r4 = SUB32(ctx->r25, ctx->r31);
    // 0x80089EF8: multu       $s2, $a0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089EFC: addiu       $t7, $v1, 0x200
    ctx->r15 = ADD32(ctx->r3, 0X200);
    // 0x80089F00: andi        $t8, $t7, 0x7FF
    ctx->r24 = ctx->r15 & 0X7FF;
    // 0x80089F04: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80089F08: subu        $a1, $t6, $s1
    ctx->r5 = SUB32(ctx->r14, ctx->r17);
    // 0x80089F0C: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x80089F10: lh          $a2, 0x0($t6)
    ctx->r6 = S32(MEM_H(ctx->r14, 0X0));
    // 0x80089F14: andi        $t7, $v1, 0x7FF
    ctx->r15 = ctx->r3 & 0X7FF;
    // 0x80089F18: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80089F1C: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x80089F20: mflo        $t6
    ctx->r14 = lo;
    // 0x80089F24: lh          $a3, 0x0($t9)
    ctx->r7 = S32(MEM_H(ctx->r25, 0X0));
    // 0x80089F28: nop

    // 0x80089F2C: multu       $s3, $a1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089F30: mflo        $t7
    ctx->r15 = lo;
    // 0x80089F34: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80089F38: bltzl       $t8, L_80089FC4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80089F3C: sll         $t6, $t0, 1
        ctx->r14 = S32(ctx->r8 << 1);
            goto L_80089FC4;
    }
    goto skip_2;
    // 0x80089F3C: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    skip_2:
    // 0x80089F40: multu       $a2, $a0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089F44: mflo        $t9
    ctx->r25 = lo;
    // 0x80089F48: nop

    // 0x80089F4C: nop

    // 0x80089F50: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089F54: mflo        $t6
    ctx->r14 = lo;
    // 0x80089F58: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80089F5C: bgezl       $t7, L_80089FC4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80089F60: sll         $t6, $t0, 1
        ctx->r14 = S32(ctx->r8 << 1);
            goto L_80089FC4;
    }
    goto skip_3;
    // 0x80089F60: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    skip_3:
    // 0x80089F64: multu       $a2, $a1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089F68: mflo        $t8
    ctx->r24 = lo;
    // 0x80089F6C: nop

    // 0x80089F70: nop

    // 0x80089F74: multu       $a3, $a0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089F78: mflo        $t9
    ctx->r25 = lo;
    // 0x80089F7C: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x80089F80: blez        $v0, L_80089F90
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80089F84: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_80089F90;
    }
    // 0x80089F84: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80089F88: b           L_80089F90
    // 0x80089F8C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80089F90;
    // 0x80089F8C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80089F90:
    // 0x80089F90: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80089F94: beql        $at, $zero, L_80089FC4
    if (ctx->r1 == 0) {
        // 0x80089F98: sll         $t6, $t0, 1
        ctx->r14 = S32(ctx->r8 << 1);
            goto L_80089FC4;
    }
    goto skip_4;
    // 0x80089F98: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    skip_4:
    // 0x80089F9C: jal         0x8009800C
    // 0x80089FA0: nop

    krand2(rdram, ctx);
        goto after_0;
    // 0x80089FA0: nop

    after_0:
    // 0x80089FA4: lh          $t6, 0x14($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X14));
    // 0x80089FA8: andi        $t7, $v0, 0x400
    ctx->r15 = ctx->r2 & 0X400;
    // 0x80089FAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80089FB0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80089FB4: addiu       $t9, $t8, -0x200
    ctx->r25 = ADD32(ctx->r24, -0X200);
    // 0x80089FB8: b           L_80089FD8
    // 0x80089FBC: sh          $t9, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r25;
        goto L_80089FD8;
    // 0x80089FBC: sh          $t9, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r25;
    // 0x80089FC0: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
L_80089FC4:
    // 0x80089FC4: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80089FC8: lh          $t0, 0x0($t7)
    ctx->r8 = S32(MEM_H(ctx->r15, 0X0));
    // 0x80089FCC: bgez        $t0, L_80089EC0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80089FD0: nop
    
            goto L_80089EC0;
    }
    // 0x80089FD0: nop

L_80089FD4:
    // 0x80089FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80089FD8:
    // 0x80089FD8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80089FDC: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80089FE0: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80089FE4: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80089FE8: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80089FEC: jr          $ra
    // 0x80089FF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80089FF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void dmulscale24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090BF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090BFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090C00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090C04: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090C08: jal         0x800BB8F8
    // 0x80090C0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090C0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090C10: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090C14: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090C18: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090C1C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090C20: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090C24: jal         0x800BB8F8
    // 0x80090C28: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090C28: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090C2C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090C30: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090C34: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090C38: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090C3C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090C40: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090C44: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090C48: jal         0x800BBA24
    // 0x80090C4C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090C4C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_2:
    // 0x80090C50: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090C54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090C58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090C5C: jr          $ra
    // 0x80090C60: nop

    return;
    // 0x80090C60: nop

;}
RECOMP_FUNC void alSndpSetSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C16E0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800C16E4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C16E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C16EC: jr          $ra
    // 0x800C16F0: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    return;
    // 0x800C16F0: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void dmulscale21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090AA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090AAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090AB0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090AB4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090AB8: jal         0x800BB8F8
    // 0x80090ABC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090ABC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090AC0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090AC4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090AC8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090ACC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090AD0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090AD4: jal         0x800BB8F8
    // 0x80090AD8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090AD8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090ADC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090AE0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090AE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090AE8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090AEC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090AF0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090AF4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090AF8: jal         0x800BBA24
    // 0x80090AFC: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090AFC: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    after_2:
    // 0x80090B00: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090B04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090B08: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090B0C: jr          $ra
    // 0x80090B10: nop

    return;
    // 0x80090B10: nop

;}
RECOMP_FUNC void dmulscale22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090B14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090B1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090B20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090B24: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090B28: jal         0x800BB8F8
    // 0x80090B2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090B2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090B30: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090B34: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090B38: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090B3C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090B40: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090B44: jal         0x800BB8F8
    // 0x80090B48: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090B48: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090B4C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090B50: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090B54: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090B58: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090B5C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090B60: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090B64: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090B68: jal         0x800BBA24
    // 0x80090B6C: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090B6C: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    after_2:
    // 0x80090B70: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090B78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090B7C: jr          $ra
    // 0x80090B80: nop

    return;
    // 0x80090B80: nop

;}
RECOMP_FUNC void displayrooms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800711A8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800711AC: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800711B0: lh          $t6, 0xAA($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XAA));
    // 0x800711B4: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800711B8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800711BC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800711C0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800711C4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800711C8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800711CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800711D0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800711D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800711D8: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x800711DC: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x800711E0: lh          $v0, 0x288($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800711E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800711E8: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800711EC: bltz        $v0, L_800717DC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800711F0: slti        $at, $v0, 0x291
        ctx->r1 = SIGNED(ctx->r2) < 0X291 ? 1 : 0;
            goto L_800717DC;
    }
    // 0x800711F0: slti        $at, $v0, 0x291
    ctx->r1 = SIGNED(ctx->r2) < 0X291 ? 1 : 0;
    // 0x800711F4: beq         $at, $zero, L_800717DC
    if (ctx->r1 == 0) {
        // 0x800711F8: sh          $v0, 0x82($sp)
        MEM_H(0X82, ctx->r29) = ctx->r2;
            goto L_800717DC;
    }
    // 0x800711F8: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x800711FC: jal         0x800754D4
    // 0x80071200: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    dointerpolations(rdram, ctx);
        goto after_0;
    // 0x80071200: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80071204: jal         0x80071104
    // 0x80071208: nop

    animatecamsprite(rdram, ctx);
        goto after_1;
    // 0x80071208: nop

    after_1:
    // 0x8007120C: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x80071210: lh          $v0, -0x54AC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X54AC));
    // 0x80071214: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x80071218: addiu       $t2, $t2, 0x6BA8
    ctx->r10 = ADD32(ctx->r10, 0X6BA8);
    // 0x8007121C: bltz        $v0, L_8007132C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80071220: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_8007132C;
    }
    // 0x80071220: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80071224: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80071228: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8007122C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80071230: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80071234: addu        $v1, $t9, $t2
    ctx->r3 = ADD32(ctx->r25, ctx->r10);
    // 0x80071238: lh          $a0, 0x1A($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X1A));
    // 0x8007123C: addiu       $t3, $zero, -0x64
    ctx->r11 = ADD32(0, -0X64);
    // 0x80071240: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x80071244: bgez        $a0, L_8007125C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80071248: slti        $at, $a0, 0xC8
        ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
            goto L_8007125C;
    }
    // 0x80071248: slti        $at, $a0, 0xC8
    ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
    // 0x8007124C: sh          $t3, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r11;
    // 0x80071250: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x80071254: b           L_80071270
    // 0x80071258: lh          $v0, -0x54AC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X54AC));
        goto L_80071270;
    // 0x80071258: lh          $v0, -0x54AC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X54AC));
L_8007125C:
    // 0x8007125C: bne         $at, $zero, L_80071270
    if (ctx->r1 != 0) {
        // 0x80071260: addiu       $t4, $zero, 0x12C
        ctx->r12 = ADD32(0, 0X12C);
            goto L_80071270;
    }
    // 0x80071260: addiu       $t4, $zero, 0x12C
    ctx->r12 = ADD32(0, 0X12C);
    // 0x80071264: sh          $t4, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r12;
    // 0x80071268: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x8007126C: lh          $v0, -0x54AC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X54AC));
L_80071270:
    // 0x80071270: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80071274: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80071278: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007127C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80071280: lh          $t7, -0x5BF4($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X5BF4));
    // 0x80071284: lh          $t5, 0x14($v1)
    ctx->r13 = S32(MEM_H(ctx->r3, 0X14));
    // 0x80071288: lw          $a3, 0xAC($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x8007128C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x80071290: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x80071294: addiu       $t9, $t8, 0x400
    ctx->r25 = ADD32(ctx->r24, 0X400);
    // 0x80071298: andi        $t2, $t9, 0x7FF
    ctx->r10 = ctx->r25 & 0X7FF;
    // 0x8007129C: addiu       $a1, $t2, -0x400
    ctx->r5 = ADD32(ctx->r10, -0X400);
    // 0x800712A0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800712A4: jal         0x8008FD60
    // 0x800712A8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    mulscale16(rdram, ctx);
        goto after_2;
    // 0x800712A8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_2:
    // 0x800712AC: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800712B0: lh          $t6, -0x54AC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X54AC));
    // 0x800712B4: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x800712B8: lui         $a0, 0x8028
    ctx->r4 = S32(0X8028 << 16);
    // 0x800712BC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800712C0: lw          $v1, 0x50($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800712C4: addiu       $a0, $a0, -0x5C00
    ctx->r4 = ADD32(ctx->r4, -0X5C00);
    // 0x800712C8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x800712CC: lh          $t3, 0x10($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0X10));
    // 0x800712D0: mflo        $t5
    ctx->r13 = lo;
    // 0x800712D4: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x800712D8: lh          $t8, 0xC($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0XC));
    // 0x800712DC: sh          $t3, -0x2340($at)
    MEM_H(-0X2340, ctx->r1) = ctx->r11;
    // 0x800712E0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x800712E4: addu        $t1, $v0, $t8
    ctx->r9 = ADD32(ctx->r2, ctx->r24);
    // 0x800712E8: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x800712EC: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800712F0: sw          $t2, -0x1994($at)
    MEM_W(-0X1994, ctx->r1) = ctx->r10;
    // 0x800712F4: lh          $t4, 0x1A($v1)
    ctx->r12 = S32(MEM_H(ctx->r3, 0X1A));
    // 0x800712F8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x800712FC: sw          $t4, -0x1990($at)
    MEM_W(-0X1990, ctx->r1) = ctx->r12;
    // 0x80071300: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80071304: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80071308: sw          $t6, -0x19A0($at)
    MEM_W(-0X19A0, ctx->r1) = ctx->r14;
    // 0x8007130C: lw          $t5, 0x4($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X4));
    // 0x80071310: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80071314: sw          $t5, -0x199C($at)
    MEM_W(-0X199C, ctx->r1) = ctx->r13;
    // 0x80071318: lw          $t7, 0x8($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X8));
    // 0x8007131C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80071320: addiu       $t8, $t7, -0x400
    ctx->r24 = ADD32(ctx->r15, -0X400);
    // 0x80071324: b           L_8007177C
    // 0x80071328: sw          $t8, -0x1998($at)
    MEM_W(-0X1998, ctx->r1) = ctx->r24;
        goto L_8007177C;
    // 0x80071328: sw          $t8, -0x1998($at)
    MEM_W(-0X1998, ctx->r1) = ctx->r24;
L_8007132C:
    // 0x8007132C: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x80071330: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x80071334: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80071338: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8007133C: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80071340: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80071344: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80071348: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8007134C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80071350: lbu         $t3, 0x6BD0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6BD0);
    // 0x80071354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80071358: addiu       $a3, $t3, 0x1C
    ctx->r7 = ADD32(ctx->r11, 0X1C);
    // 0x8007135C: jal         0x8009166C
    // 0x80071360: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    divscale22(rdram, ctx);
        goto after_3;
    // 0x80071360: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_3:
    // 0x80071364: lw          $t6, 0x214($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X214));
    // 0x80071368: lw          $t5, 0x238($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X238));
    // 0x8007136C: lw          $a3, 0xAC($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x80071370: subu        $a1, $t6, $t5
    ctx->r5 = SUB32(ctx->r14, ctx->r13);
    // 0x80071374: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80071378: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007137C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80071380: jal         0x8008FD60
    // 0x80071384: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    mulscale16(rdram, ctx);
        goto after_4;
    // 0x80071384: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_4:
    // 0x80071388: lw          $t9, 0x238($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X238));
    // 0x8007138C: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80071390: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80071394: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x80071398: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
    // 0x8007139C: lw          $t5, 0x23C($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X23C));
    // 0x800713A0: lw          $t6, 0x218($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800713A4: subu        $a1, $t6, $t5
    ctx->r5 = SUB32(ctx->r14, ctx->r13);
    // 0x800713A8: jal         0x8008FD60
    // 0x800713AC: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_5;
    // 0x800713AC: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_5:
    // 0x800713B0: lw          $t8, 0x23C($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X23C));
    // 0x800713B4: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800713B8: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800713BC: addu        $t2, $v0, $t8
    ctx->r10 = ADD32(ctx->r2, ctx->r24);
    // 0x800713C0: sw          $t2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r10;
    // 0x800713C4: lw          $t9, 0x240($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X240));
    // 0x800713C8: lw          $t3, 0x21C($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800713CC: subu        $a1, $t3, $t9
    ctx->r5 = SUB32(ctx->r11, ctx->r25);
    // 0x800713D0: jal         0x8008FD60
    // 0x800713D4: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_6;
    // 0x800713D4: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_6:
    // 0x800713D8: lw          $t6, 0x240($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X240));
    // 0x800713DC: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800713E0: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800713E4: addu        $t5, $v0, $t6
    ctx->r13 = ADD32(ctx->r2, ctx->r14);
    // 0x800713E8: sw          $t5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r13;
    // 0x800713EC: lh          $t8, 0x284($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X284));
    // 0x800713F0: lh          $t7, 0x282($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X282));
    // 0x800713F4: subu        $t2, $t7, $t8
    ctx->r10 = SUB32(ctx->r15, ctx->r24);
    // 0x800713F8: addiu       $t3, $t2, 0x400
    ctx->r11 = ADD32(ctx->r10, 0X400);
    // 0x800713FC: andi        $t9, $t3, 0x7FF
    ctx->r25 = ctx->r11 & 0X7FF;
    // 0x80071400: addiu       $a1, $t9, -0x400
    ctx->r5 = ADD32(ctx->r25, -0X400);
    // 0x80071404: jal         0x8008FD60
    // 0x80071408: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_7;
    // 0x80071408: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_7:
    // 0x8007140C: lh          $t6, 0x284($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X284));
    // 0x80071410: lw          $t8, 0x220($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X220));
    // 0x80071414: lh          $t2, 0x2B8($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x80071418: lw          $t9, 0x224($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X224));
    // 0x8007141C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80071420: lw          $t6, 0x228($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X228));
    // 0x80071424: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x80071428: subu        $t4, $t3, $t9
    ctx->r12 = SUB32(ctx->r11, ctx->r25);
    // 0x8007142C: subu        $a1, $t4, $t6
    ctx->r5 = SUB32(ctx->r12, ctx->r14);
    // 0x80071430: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80071434: sh          $t7, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r15;
    // 0x80071438: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8007143C: jal         0x8008FD60
    // 0x80071440: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    mulscale16(rdram, ctx);
        goto after_8;
    // 0x80071440: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    after_8:
    // 0x80071444: lw          $t7, 0x224($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X224));
    // 0x80071448: lh          $t1, 0x80($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X80));
    // 0x8007144C: lw          $t2, 0x228($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X228));
    // 0x80071450: lh          $t4, 0x28A($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X28A));
    // 0x80071454: lh          $v1, 0x2BE($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2BE));
    // 0x80071458: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8007145C: addu        $t0, $t8, $t2
    ctx->r8 = ADD32(ctx->r24, ctx->r10);
    // 0x80071460: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x80071464: sll         $t3, $t0, 16
    ctx->r11 = S32(ctx->r8 << 16);
    // 0x80071468: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8007146C: sra         $t0, $t3, 16
    ctx->r8 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80071470: bltz        $v1, L_800714B8
    if (SIGNED(ctx->r3) < 0) {
        // 0x80071474: sra         $t1, $t6, 16
        ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800714B8;
    }
    // 0x80071474: sra         $t1, $t6, 16
    ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80071478: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8007147C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071480: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x80071484: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x80071488: mflo        $t7
    ctx->r15 = lo;
    // 0x8007148C: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x80071490: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80071494: lw          $t2, 0x4($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80071498: lw          $t3, 0x8($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X8));
    // 0x8007149C: lh          $t9, 0x10($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X10));
    // 0x800714A0: lh          $t1, 0x14($v0)
    ctx->r9 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800714A4: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x800714A8: sw          $t2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r10;
    // 0x800714AC: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x800714B0: b           L_80071554
    // 0x800714B4: sh          $t9, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r25;
        goto L_80071554;
    // 0x800714B4: sh          $t9, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r25;
L_800714B8:
    // 0x800714B8: lh          $t4, 0x2E2($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X2E2));
    // 0x800714BC: bnel        $t4, $zero, L_80071518
    if (ctx->r12 != 0) {
        // 0x800714C0: addiu       $t4, $sp, 0x82
        ctx->r12 = ADD32(ctx->r29, 0X82);
            goto L_80071518;
    }
    goto skip_0;
    // 0x800714C0: addiu       $t4, $sp, 0x82
    ctx->r12 = ADD32(ctx->r29, 0X82);
    skip_0:
    // 0x800714C4: lw          $t6, 0x244($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X244));
    // 0x800714C8: lw          $t5, 0x248($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X248));
    // 0x800714CC: sh          $t1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r9;
    // 0x800714D0: sh          $t0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r8;
    // 0x800714D4: subu        $a1, $t6, $t5
    ctx->r5 = SUB32(ctx->r14, ctx->r13);
    // 0x800714D8: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800714DC: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800714E0: jal         0x8008FD60
    // 0x800714E4: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    mulscale16(rdram, ctx);
        goto after_9;
    // 0x800714E4: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    after_9:
    // 0x800714E8: lw          $t8, 0x9C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800714EC: lw          $t2, 0x248($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X248));
    // 0x800714F0: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x800714F4: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x800714F8: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x800714FC: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80071500: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x80071504: lh          $t0, 0x7C($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X7C));
    // 0x80071508: lh          $t1, 0x80($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X80));
    // 0x8007150C: b           L_80071554
    // 0x80071510: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
        goto L_80071554;
    // 0x80071510: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80071514: addiu       $t4, $sp, 0x82
    ctx->r12 = ADD32(ctx->r29, 0X82);
L_80071518:
    // 0x80071518: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8007151C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80071520: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x80071524: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x80071528: addiu       $a3, $sp, 0x9C
    ctx->r7 = ADD32(ctx->r29, 0X9C);
    // 0x8007152C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80071530: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80071534: sh          $t0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r8;
    // 0x80071538: jal         0x80070EF4
    // 0x8007153C: sh          $t1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r9;
    view(rdram, ctx);
        goto after_10;
    // 0x8007153C: sh          $t1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r9;
    after_10:
    // 0x80071540: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x80071544: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x80071548: lh          $t0, 0x7C($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X7C));
    // 0x8007154C: lh          $t1, 0x80($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X80));
    // 0x80071550: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
L_80071554:
    // 0x80071554: lh          $t6, 0x2E0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x80071558: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8007155C: lui         $a0, 0x8028
    ctx->r4 = S32(0X8028 << 16);
    // 0x80071560: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071564: addiu       $a0, $a0, -0x5C00
    ctx->r4 = ADD32(ctx->r4, -0X5C00);
    // 0x80071568: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x8007156C: lbu         $v1, -0x559D($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X559D);
    // 0x80071570: mflo        $t5
    ctx->r13 = lo;
    // 0x80071574: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x80071578: lw          $t8, 0x18($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X18));
    // 0x8007157C: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x80071580: lh          $t2, 0x2E0($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x80071584: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071588: mflo        $t3
    ctx->r11 = lo;
    // 0x8007158C: addu        $t9, $a0, $t3
    ctx->r25 = ADD32(ctx->r4, ctx->r11);
    // 0x80071590: lw          $t4, 0x14($t9)
    ctx->r12 = S32(MEM_W(ctx->r25, 0X14));
    // 0x80071594: blez        $v1, L_800715D8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071598: sw          $t4, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r12;
            goto L_800715D8;
    }
    // 0x80071598: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
    // 0x8007159C: lh          $t6, 0xAA($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XAA));
    // 0x800715A0: lw          $a0, 0x9C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800715A4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800715A8: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800715AC: andi        $t3, $t7, 0x2
    ctx->r11 = ctx->r15 & 0X2;
    // 0x800715B0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800715B4: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x800715B8: sll         $t2, $t8, 9
    ctx->r10 = S32(ctx->r24 << 9);
    // 0x800715BC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800715C0: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x800715C4: subu        $a0, $a0, $t2
    ctx->r4 = SUB32(ctx->r4, ctx->r10);
    // 0x800715C8: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x800715CC: sll         $t5, $t1, 16
    ctx->r13 = S32(ctx->r9 << 16);
    // 0x800715D0: sra         $t1, $t5, 16
    ctx->r9 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800715D4: sw          $a0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r4;
L_800715D8:
    // 0x800715D8: lh          $t8, 0x2E0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800715DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800715E0: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800715E4: mflo        $t2
    ctx->r10 = lo;
    // 0x800715E8: addu        $t9, $a2, $t2
    ctx->r25 = ADD32(ctx->r6, ctx->r10);
    // 0x800715EC: lbu         $t3, 0x25($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X25);
    // 0x800715F0: bnel        $t3, $at, L_80071608
    if (ctx->r11 != ctx->r1) {
        // 0x800715F4: lh          $v1, 0x2BE($s0)
        ctx->r3 = S32(MEM_H(ctx->r16, 0X2BE));
            goto L_80071608;
    }
    goto skip_1;
    // 0x800715F4: lh          $v1, 0x2BE($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2BE));
    skip_1:
    // 0x800715F8: lw          $a0, 0x9C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800715FC: addiu       $a0, $a0, -0x1200
    ctx->r4 = ADD32(ctx->r4, -0X1200);
    // 0x80071600: sw          $a0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r4;
    // 0x80071604: lh          $v1, 0x2BE($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2BE));
L_80071608:
    // 0x80071608: bltzl       $v1, L_80071634
    if (SIGNED(ctx->r3) < 0) {
        // 0x8007160C: lh          $t8, 0x370($s0)
        ctx->r24 = S32(MEM_H(ctx->r16, 0X370));
            goto L_80071634;
    }
    goto skip_2;
    // 0x8007160C: lh          $t8, 0x370($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X370));
    skip_2:
    // 0x80071610: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071614: mflo        $t4
    ctx->r12 = lo;
    // 0x80071618: addu        $t6, $a2, $t4
    ctx->r14 = ADD32(ctx->r6, ctx->r12);
    // 0x8007161C: lb          $t0, 0x24($t6)
    ctx->r8 = S32(MEM_B(ctx->r14, 0X24));
    // 0x80071620: addiu       $t0, $t0, 0x64
    ctx->r8 = ADD32(ctx->r8, 0X64);
    // 0x80071624: sll         $t5, $t0, 16
    ctx->r13 = S32(ctx->r8 << 16);
    // 0x80071628: b           L_8007168C
    // 0x8007162C: sra         $t0, $t5, 16
    ctx->r8 = S32(SIGNED(ctx->r13) >> 16);
        goto L_8007168C;
    // 0x8007162C: sra         $t0, $t5, 16
    ctx->r8 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80071630: lh          $t8, 0x370($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X370));
L_80071634:
    // 0x80071634: lbu         $t3, 0x342($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X342);
    // 0x80071638: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8007163C: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x80071640: bne         $t3, $zero, L_8007168C
    if (ctx->r11 != 0) {
        // 0x80071644: sra         $t0, $t2, 16
        ctx->r8 = S32(SIGNED(ctx->r10) >> 16);
            goto L_8007168C;
    }
    // 0x80071644: sra         $t0, $t2, 16
    ctx->r8 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80071648: lw          $t6, 0x260($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X260));
    // 0x8007164C: lw          $t4, 0x9C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80071650: lw          $a0, 0x8C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x80071654: addiu       $t5, $t6, 0x400
    ctx->r13 = ADD32(ctx->r14, 0X400);
    // 0x80071658: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007165C: beq         $at, $zero, L_8007166C
    if (ctx->r1 == 0) {
        // 0x80071660: addiu       $a0, $a0, 0x400
        ctx->r4 = ADD32(ctx->r4, 0X400);
            goto L_8007166C;
    }
    // 0x80071660: addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    // 0x80071664: b           L_8007168C
    // 0x80071668: sw          $a0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r4;
        goto L_8007168C;
    // 0x80071668: sw          $a0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r4;
L_8007166C:
    // 0x8007166C: lw          $t8, 0x25C($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X25C));
    // 0x80071670: lw          $t7, 0x9C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80071674: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x80071678: addiu       $t2, $t8, -0x400
    ctx->r10 = ADD32(ctx->r24, -0X400);
    // 0x8007167C: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80071680: beq         $at, $zero, L_8007168C
    if (ctx->r1 == 0) {
        // 0x80071684: addiu       $a0, $a0, -0x400
        ctx->r4 = ADD32(ctx->r4, -0X400);
            goto L_8007168C;
    }
    // 0x80071684: addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // 0x80071688: sw          $a0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r4;
L_8007168C:
    // 0x8007168C: lh          $t9, 0x82($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X82));
    // 0x80071690: lw          $a0, 0x9C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80071694: bltz        $t9, L_800716F4
    if (SIGNED(ctx->r25) < 0) {
        // 0x80071698: addiu       $t3, $sp, 0x90
        ctx->r11 = ADD32(ctx->r29, 0X90);
            goto L_800716F4;
    }
    // 0x80071698: addiu       $t3, $sp, 0x90
    ctx->r11 = ADD32(ctx->r29, 0X90);
    // 0x8007169C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800716A0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800716A4: lw          $a1, 0xA4($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800716A8: lw          $a2, 0xA0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800716AC: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    // 0x800716B0: sh          $t0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r8;
    // 0x800716B4: jal         0x80099104
    // 0x800716B8: sh          $t1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r9;
    getzsofslope(rdram, ctx);
        goto after_11;
    // 0x800716B8: sh          $t1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r9;
    after_11:
    // 0x800716BC: lw          $v0, 0x8C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800716C0: lw          $a0, 0x9C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800716C4: lh          $t0, 0x7C($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X7C));
    // 0x800716C8: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x800716CC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800716D0: beq         $at, $zero, L_800716DC
    if (ctx->r1 == 0) {
        // 0x800716D4: lh          $t1, 0x80($sp)
        ctx->r9 = S32(MEM_H(ctx->r29, 0X80));
            goto L_800716DC;
    }
    // 0x800716D4: lh          $t1, 0x80($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X80));
    // 0x800716D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800716DC:
    // 0x800716DC: lw          $v0, 0x90($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X90));
    // 0x800716E0: addiu       $v0, $v0, -0x400
    ctx->r2 = ADD32(ctx->r2, -0X400);
    // 0x800716E4: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800716E8: beql        $at, $zero, L_800716F8
    if (ctx->r1 == 0) {
        // 0x800716EC: slti        $at, $t0, 0xE5
        ctx->r1 = SIGNED(ctx->r8) < 0XE5 ? 1 : 0;
            goto L_800716F8;
    }
    goto skip_3;
    // 0x800716EC: slti        $at, $t0, 0xE5
    ctx->r1 = SIGNED(ctx->r8) < 0XE5 ? 1 : 0;
    skip_3:
    // 0x800716F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800716F4:
    // 0x800716F4: slti        $at, $t0, 0xE5
    ctx->r1 = SIGNED(ctx->r8) < 0XE5 ? 1 : 0;
L_800716F8:
    // 0x800716F8: bne         $at, $zero, L_80071708
    if (ctx->r1 != 0) {
        // 0x800716FC: lh          $t4, 0x82($sp)
        ctx->r12 = S32(MEM_H(ctx->r29, 0X82));
            goto L_80071708;
    }
    // 0x800716FC: lh          $t4, 0x82($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X82));
    // 0x80071700: b           L_8007170C
    // 0x80071704: addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
        goto L_8007170C;
    // 0x80071704: addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
L_80071708:
    // 0x80071708: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8007170C:
    // 0x8007170C: slti        $at, $v0, -0x1C
    ctx->r1 = SIGNED(ctx->r2) < -0X1C ? 1 : 0;
    // 0x80071710: beql        $at, $zero, L_80071724
    if (ctx->r1 == 0) {
        // 0x80071714: slti        $at, $t0, 0xE5
        ctx->r1 = SIGNED(ctx->r8) < 0XE5 ? 1 : 0;
            goto L_80071724;
    }
    goto skip_4;
    // 0x80071714: slti        $at, $t0, 0xE5
    ctx->r1 = SIGNED(ctx->r8) < 0XE5 ? 1 : 0;
    skip_4:
    // 0x80071718: b           L_80071740
    // 0x8007171C: addiu       $t0, $zero, -0x1C
    ctx->r8 = ADD32(0, -0X1C);
        goto L_80071740;
    // 0x8007171C: addiu       $t0, $zero, -0x1C
    ctx->r8 = ADD32(0, -0X1C);
    // 0x80071720: slti        $at, $t0, 0xE5
    ctx->r1 = SIGNED(ctx->r8) < 0XE5 ? 1 : 0;
L_80071724:
    // 0x80071724: bne         $at, $zero, L_80071734
    if (ctx->r1 != 0) {
        // 0x80071728: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80071734;
    }
    // 0x80071728: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8007172C: b           L_80071734
    // 0x80071730: addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
        goto L_80071734;
    // 0x80071730: addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
L_80071734:
    // 0x80071734: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80071738: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8007173C: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_80071740:
    // 0x80071740: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80071744: sh          $t4, -0x2340($at)
    MEM_H(-0X2340, ctx->r1) = ctx->r12;
    // 0x80071748: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8007174C: sw          $t1, -0x1994($at)
    MEM_W(-0X1994, ctx->r1) = ctx->r9;
    // 0x80071750: lw          $t5, 0xA4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x80071754: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80071758: sw          $t0, -0x1990($at)
    MEM_W(-0X1990, ctx->r1) = ctx->r8;
    // 0x8007175C: lw          $t8, 0xA0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80071760: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80071764: sw          $t5, -0x19A0($at)
    MEM_W(-0X19A0, ctx->r1) = ctx->r13;
    // 0x80071768: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8007176C: sw          $t8, -0x199C($at)
    MEM_W(-0X199C, ctx->r1) = ctx->r24;
    // 0x80071770: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80071774: sw          $a0, -0x1998($at)
    MEM_W(-0X1998, ctx->r1) = ctx->r4;
    // 0x80071778: sw          $a0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r4;
L_8007177C:
    // 0x8007177C: jal         0x800755C4
    // 0x80071780: nop

    restoreinterpolations(rdram, ctx);
        goto after_12;
    // 0x80071780: nop

    after_12:
    // 0x80071784: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x80071788: lui         $t2, 0x8028
    ctx->r10 = S32(0X8028 << 16);
    // 0x8007178C: lw          $t2, -0x68A4($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X68A4));
    // 0x80071790: lw          $t7, -0x5370($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X5370));
    // 0x80071794: addiu       $t5, $zero, 0x200
    ctx->r13 = ADD32(0, 0X200);
    // 0x80071798: slt         $at, $t7, $t2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007179C: beql        $at, $zero, L_800717DC
    if (ctx->r1 == 0) {
        // 0x800717A0: sw          $t5, 0x268($s0)
        MEM_W(0X268, ctx->r16) = ctx->r13;
            goto L_800717DC;
    }
    goto skip_5;
    // 0x800717A0: sw          $t5, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r13;
    skip_5:
    // 0x800717A4: lw          $a0, 0x268($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X268));
    // 0x800717A8: jal         0x80091A38
    // 0x800717AC: addiu       $a0, $a0, -0x200
    ctx->r4 = ADD32(ctx->r4, -0X200);
    klabs(rdram, ctx);
        goto after_13;
    // 0x800717AC: addiu       $a0, $a0, -0x200
    ctx->r4 = ADD32(ctx->r4, -0X200);
    after_13:
    // 0x800717B0: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x800717B4: bnel        $at, $zero, L_800717E0
    if (ctx->r1 != 0) {
        // 0x800717B8: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_800717E0;
    }
    goto skip_6;
    // 0x800717B8: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_6:
    // 0x800717BC: lw          $v0, 0x268($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X268));
    // 0x800717C0: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x800717C4: subu        $t3, $t9, $v0
    ctx->r11 = SUB32(ctx->r25, ctx->r2);
    // 0x800717C8: sra         $t6, $t3, 2
    ctx->r14 = S32(SIGNED(ctx->r11) >> 2);
    // 0x800717CC: addu        $t4, $v0, $t6
    ctx->r12 = ADD32(ctx->r2, ctx->r14);
    // 0x800717D0: b           L_800717DC
    // 0x800717D4: sw          $t4, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r12;
        goto L_800717DC;
    // 0x800717D4: sw          $t4, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r12;
    // 0x800717D8: sw          $t5, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r13;
L_800717DC:
    // 0x800717DC: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
L_800717E0:
    // 0x800717E0: lw          $s0, 0x28($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800717E4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800717E8: jr          $ra
    // 0x800717EC: nop

    return;
    // 0x800717EC: nop

;}
RECOMP_FUNC void mulscale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F92C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008F930: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008F934: jal         0x800BB8F8
    // 0x8008F938: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008F938: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008F93C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F940: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008F944: lw          $a2, 0x28($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8008F948: jal         0x800BBA24
    // 0x8008F94C: lw          $a3, 0x2C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X2C));
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008F94C: lw          $a3, 0x2C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X2C));
    after_1:
    // 0x8008F950: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008F954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F958: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008F95C: jr          $ra
    // 0x8008F960: nop

    return;
    // 0x8008F960: nop

;}
RECOMP_FUNC void dmulscale20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090A3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090A40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090A44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090A48: jal         0x800BB8F8
    // 0x80090A4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090A4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090A50: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090A54: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090A58: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090A5C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090A60: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090A64: jal         0x800BB8F8
    // 0x80090A68: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090A68: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090A6C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090A70: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090A74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090A78: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090A7C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090A80: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090A84: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090A88: jal         0x800BBA24
    // 0x80090A8C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090A8C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_2:
    // 0x80090A90: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090A94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090A98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090A9C: jr          $ra
    // 0x80090AA0: nop

    return;
    // 0x80090AA0: nop

;}
RECOMP_FUNC void updatesectorz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070CB0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80070CB4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80070CB8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80070CBC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80070CC0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80070CC4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80070CC8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80070CCC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80070CD0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80070CD4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80070CD8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80070CDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80070CE0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80070CE4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80070CE8: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80070CEC: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x80070CF0: lh          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_H(ctx->r7, 0X0));
    // 0x80070CF4: addiu       $t7, $sp, 0x54
    ctx->r15 = ADD32(ctx->r29, 0X54);
    // 0x80070CF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80070CFC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x80070D00: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80070D04: jal         0x80099104
    // 0x80070D08: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    getzsofslope(rdram, ctx);
        goto after_0;
    // 0x80070D08: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x80070D0C: lw          $t8, 0x58($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80070D10: lw          $t9, 0x54($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80070D14: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80070D18: bne         $at, $zero, L_80070D40
    if (ctx->r1 != 0) {
        // 0x80070D1C: slt         $at, $t9, $s6
        ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_80070D40;
    }
    // 0x80070D1C: slt         $at, $t9, $s6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80070D20: bne         $at, $zero, L_80070D40
    if (ctx->r1 != 0) {
        // 0x80070D24: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80070D40;
    }
    // 0x80070D24: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80070D28: lw          $t0, 0x74($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X74));
    // 0x80070D2C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80070D30: jal         0x80091E14
    // 0x80070D34: lh          $a2, 0x0($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X0));
    inside(rdram, ctx);
        goto after_1;
    // 0x80070D34: lh          $a2, 0x0($t0)
    ctx->r6 = S32(MEM_H(ctx->r8, 0X0));
    after_1:
    // 0x80070D38: bnel        $v0, $zero, L_80070EC8
    if (ctx->r2 != 0) {
        // 0x80070D3C: lw          $ra, 0x44($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
            goto L_80070EC8;
    }
    goto skip_0;
    // 0x80070D3C: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    skip_0:
L_80070D40:
    // 0x80070D40: lw          $t1, 0x74($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X74));
    // 0x80070D44: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x80070D48: lh          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_H(ctx->r9, 0X0));
    // 0x80070D4C: bltz        $v1, L_80070E24
    if (SIGNED(ctx->r3) < 0) {
        // 0x80070D50: nop
    
            goto L_80070E24;
    }
    // 0x80070D50: nop

    // 0x80070D54: lh          $t2, -0x5378($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X5378));
    // 0x80070D58: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80070D5C: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80070D60: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80070D64: beq         $at, $zero, L_80070E24
    if (ctx->r1 == 0) {
        // 0x80070D68: sll         $t3, $t3, 4
        ctx->r11 = S32(ctx->r11 << 4);
            goto L_80070E24;
    }
    // 0x80070D68: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80070D6C: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x80070D70: addiu       $t4, $t4, -0x1988
    ctx->r12 = ADD32(ctx->r12, -0X1988);
    // 0x80070D74: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80070D78: lh          $t5, 0x8($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X8));
    // 0x80070D7C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80070D80: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x80070D84: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80070D88: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80070D8C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80070D90: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x80070D94: lh          $s3, 0xA($v0)
    ctx->r19 = S32(MEM_H(ctx->r2, 0XA));
    // 0x80070D98: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_80070D9C:
    // 0x80070D9C: lh          $s1, 0xC($s2)
    ctx->r17 = S32(MEM_H(ctx->r18, 0XC));
    // 0x80070DA0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80070DA4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80070DA8: bltz        $s1, L_80070E18
    if (SIGNED(ctx->r17) < 0) {
        // 0x80070DAC: sll         $s0, $s1, 16
        ctx->r16 = S32(ctx->r17 << 16);
            goto L_80070E18;
    }
    // 0x80070DAC: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
    // 0x80070DB0: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80070DB4: sll         $a0, $t8, 16
    ctx->r4 = S32(ctx->r24 << 16);
    // 0x80070DB8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80070DBC: addiu       $t0, $sp, 0x54
    ctx->r8 = ADD32(ctx->r29, 0X54);
    // 0x80070DC0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80070DC4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80070DC8: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80070DCC: jal         0x80099104
    // 0x80070DD0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    getzsofslope(rdram, ctx);
        goto after_2;
    // 0x80070DD0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x80070DD4: lw          $t1, 0x58($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80070DD8: lw          $t2, 0x54($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80070DDC: slt         $at, $s6, $t1
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80070DE0: bne         $at, $zero, L_80070E18
    if (ctx->r1 != 0) {
        // 0x80070DE4: slt         $at, $t2, $s6
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_80070E18;
    }
    // 0x80070DE4: slt         $at, $t2, $s6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80070DE8: bne         $at, $zero, L_80070E18
    if (ctx->r1 != 0) {
        // 0x80070DEC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80070E18;
    }
    // 0x80070DEC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80070DF0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80070DF4: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80070DF8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80070DFC: jal         0x80091E14
    // 0x80070E00: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    inside(rdram, ctx);
        goto after_3;
    // 0x80070E00: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x80070E04: bnel        $v0, $s7, L_80070E1C
    if (ctx->r2 != ctx->r23) {
        // 0x80070E08: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80070E1C;
    }
    goto skip_1;
    // 0x80070E08: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_1:
    // 0x80070E0C: lw          $t4, 0x74($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X74));
    // 0x80070E10: b           L_80070EC4
    // 0x80070E14: sh          $s1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r17;
        goto L_80070EC4;
    // 0x80070E14: sh          $s1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r17;
L_80070E18:
    // 0x80070E18: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80070E1C:
    // 0x80070E1C: bne         $s3, $zero, L_80070D9C
    if (ctx->r19 != 0) {
        // 0x80070E20: addiu       $s2, $s2, 0x24
        ctx->r18 = ADD32(ctx->r18, 0X24);
            goto L_80070D9C;
    }
    // 0x80070E20: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
L_80070E24:
    // 0x80070E24: lui         $s1, 0x802B
    ctx->r17 = S32(0X802B << 16);
    // 0x80070E28: lh          $s1, -0x5378($s1)
    ctx->r17 = S32(MEM_H(ctx->r17, -0X5378));
    // 0x80070E2C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80070E30: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80070E34: bltz        $s1, L_80070EB8
    if (SIGNED(ctx->r17) < 0) {
        // 0x80070E38: sll         $s0, $s1, 16
        ctx->r16 = S32(ctx->r17 << 16);
            goto L_80070EB8;
    }
    // 0x80070E38: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
L_80070E3C:
    // 0x80070E3C: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80070E40: sll         $a0, $t5, 16
    ctx->r4 = S32(ctx->r13 << 16);
    // 0x80070E44: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80070E48: addiu       $t7, $sp, 0x54
    ctx->r15 = ADD32(ctx->r29, 0X54);
    // 0x80070E4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80070E50: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80070E54: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80070E58: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80070E5C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80070E60: jal         0x80099104
    // 0x80070E64: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    getzsofslope(rdram, ctx);
        goto after_4;
    // 0x80070E64: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_4:
    // 0x80070E68: lw          $t8, 0x58($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80070E6C: lw          $t9, 0x54($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80070E70: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80070E74: bne         $at, $zero, L_80070EAC
    if (ctx->r1 != 0) {
        // 0x80070E78: slt         $at, $t9, $s6
        ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_80070EAC;
    }
    // 0x80070E78: slt         $at, $t9, $s6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80070E7C: bne         $at, $zero, L_80070EAC
    if (ctx->r1 != 0) {
        // 0x80070E80: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80070EAC;
    }
    // 0x80070E80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80070E84: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80070E88: sra         $t0, $a2, 16
    ctx->r8 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80070E8C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80070E90: jal         0x80091E14
    // 0x80070E94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    inside(rdram, ctx);
        goto after_5;
    // 0x80070E94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x80070E98: bnel        $v0, $s7, L_80070EB0
    if (ctx->r2 != ctx->r23) {
        // 0x80070E9C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80070EB0;
    }
    goto skip_2;
    // 0x80070E9C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x80070EA0: lw          $t1, 0x74($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X74));
    // 0x80070EA4: b           L_80070EC4
    // 0x80070EA8: sh          $s1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r17;
        goto L_80070EC4;
    // 0x80070EA8: sh          $s1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r17;
L_80070EAC:
    // 0x80070EAC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80070EB0:
    // 0x80070EB0: bgezl       $s1, L_80070E3C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80070EB4: sll         $s0, $s1, 16
        ctx->r16 = S32(ctx->r17 << 16);
            goto L_80070E3C;
    }
    goto skip_3;
    // 0x80070EB4: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
    skip_3:
L_80070EB8:
    // 0x80070EB8: lw          $t3, 0x74($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X74));
    // 0x80070EBC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80070EC0: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
L_80070EC4:
    // 0x80070EC4: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
L_80070EC8:
    // 0x80070EC8: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80070ECC: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80070ED0: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80070ED4: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80070ED8: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80070EDC: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80070EE0: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80070EE4: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80070EE8: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80070EEC: jr          $ra
    // 0x80070EF0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80070EF0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80056F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056F68: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80056F6C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80056F70: addiu       $v1, $v1, -0x6300
    ctx->r3 = ADD32(ctx->r3, -0X6300);
    // 0x80056F74: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80056F78: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80056F7C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80056F80: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80056F84: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80056F88: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80056F8C: bne         $t6, $zero, L_8005700C
    if (ctx->r14 != 0) {
        // 0x80056F90: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_8005700C;
    }
    // 0x80056F90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80056F94: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80056F98: addiu       $t7, $t7, -0x62F0
    ctx->r15 = ADD32(ctx->r15, -0X62F0);
    // 0x80056F9C: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x80056FA0: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x80056FA4: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x80056FA8: lui         $s2, 0x8022
    ctx->r18 = S32(0X8022 << 16);
    // 0x80056FAC: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80056FB0: addiu       $s2, $s2, -0x6310
    ctx->r18 = ADD32(ctx->r18, -0X6310);
    // 0x80056FB4: addiu       $s3, $s3, -0x6070
    ctx->r19 = ADD32(ctx->r19, -0X6070);
    // 0x80056FB8: addiu       $s1, $s1, -0x62DC
    ctx->r17 = ADD32(ctx->r17, -0X62DC);
    // 0x80056FBC: addiu       $s0, $s0, -0x62F0
    ctx->r16 = ADD32(ctx->r16, -0X62F0);
L_80056FC0:
    // 0x80056FC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80056FC4: jal         0x800BF7A0
    // 0x80056FC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_0;
    // 0x80056FC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80056FCC: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80056FD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80056FD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80056FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80056FDC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80056FE0: jal         0x800BF830
    // 0x80056FE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80056FE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80056FE8: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80056FEC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80056FF0: bne         $s1, $s3, L_80056FC0
    if (ctx->r17 != ctx->r19) {
        // 0x80056FF4: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80056FC0;
    }
    // 0x80056FF4: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80056FF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80056FFC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80057000: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80057004: addiu       $v1, $v1, -0x6300
    ctx->r3 = ADD32(ctx->r3, -0X6300);
    // 0x80057008: sb          $t9, -0x6300($at)
    MEM_B(-0X6300, ctx->r1) = ctx->r25;
L_8005700C:
    // 0x8005700C: lw          $t0, 0x30($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80057010: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80057014: addiu       $v0, $v0, 0x6DB0
    ctx->r2 = ADD32(ctx->r2, 0X6DB0);
    // 0x80057018: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8005701C: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80057020: lw          $s3, 0x28($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80057024: lw          $s2, 0x24($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80057028: lw          $s1, 0x20($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005702C: lw          $s0, 0x1C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80057030: jr          $ra
    // 0x80057034: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80057034: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006A310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A310: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006A314: sh          $zero, -0x1400($at)
    MEM_H(-0X1400, ctx->r1) = 0;
    // 0x8006A318: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006A31C: sw          $zero, -0x13D4($at)
    MEM_W(-0X13D4, ctx->r1) = 0;
    // 0x8006A320: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006A324: sb          $zero, -0x13FC($at)
    MEM_B(-0X13FC, ctx->r1) = 0;
    // 0x8006A328: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006A32C: sb          $zero, -0x13D0($at)
    MEM_B(-0X13D0, ctx->r1) = 0;
    // 0x8006A330: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006A334: sb          $zero, -0x13CF($at)
    MEM_B(-0X13CF, ctx->r1) = 0;
    // 0x8006A338: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006A33C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8006A340: sb          $t6, -0x13CE($at)
    MEM_B(-0X13CE, ctx->r1) = ctx->r14;
    // 0x8006A344: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A348: lwc1        $f4, -0x6520($at)
    ctx->f4.u32l = S32(MEM_W(ctx->r1, -0X6520));
    // 0x8006A34C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8006A350: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006A354: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006A358: ldc1        $f16, 0x4DA0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X4DA0);
    // 0x8006A35C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006A360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A368: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8006A36C: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8006A370: jal         0x800C2BF0
    // 0x8006A374: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A374: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x8006A378: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006A37C: swc1        $f0, -0x13DC($at)
    MEM_W(-0X13DC, ctx->r1) = ctx->f0.u32l;
    // 0x8006A380: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A384: lwc1        $f4, -0x6520($at)
    ctx->f4.u32l = S32(MEM_W(ctx->r1, -0X6520));
    // 0x8006A388: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8006A38C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006A390: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006A394: ldc1        $f16, 0x4DA8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X4DA8);
    // 0x8006A398: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006A39C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8006A3A0: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8006A3A4: jal         0x800C2DB0
    // 0x8006A3A8: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A3A8: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_1:
    // 0x8006A3AC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8006A3B0: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006A3B4: swc1        $f0, -0x13D8($at)
    MEM_W(-0X13D8, ctx->r1) = ctx->f0.u32l;
    // 0x8006A3B8: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x8006A3BC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A3C0: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8006A3C4: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8006A3C8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006A3CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006A3D0: ori         $t9, $t9, 0x49D8
    ctx->r25 = ctx->r25 | 0X49D8;
    // 0x8006A3D4: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8006A3D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006A3DC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006A3E0: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A3E4: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8006A3E8: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x8006A3EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006A3F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006A3F4: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x8006A3F8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8006A3FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006A400: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A404: lui         $t7, 0xFF33
    ctx->r15 = S32(0XFF33 << 16);
    // 0x8006A408: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x8006A40C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006A410: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006A414: ori         $t6, $t6, 0x1824
    ctx->r14 = ctx->r14 | 0X1824;
    // 0x8006A418: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8006A41C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8006A420: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006A424: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A428: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8006A42C: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x8006A430: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006A434: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006A438: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006A43C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8006A440: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006A444: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A448: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8006A44C: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x8006A450: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006A454: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006A458: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x8006A45C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006A460: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006A464: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A468: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8006A46C: ori         $t7, $t7, 0x602
    ctx->r15 = ctx->r15 | 0X602;
    // 0x8006A470: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006A474: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006A478: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006A47C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006A480: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A484: lui         $t6, 0x1F
    ctx->r14 = S32(0X1F << 16);
    // 0x8006A488: ori         $t6, $t6, 0x3204
    ctx->r14 = ctx->r14 | 0X3204;
    // 0x8006A48C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006A490: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006A494: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8006A498: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006A49C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8006A4A0: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A4A4: addiu       $t9, $zero, 0x205
    ctx->r25 = ADD32(0, 0X205);
    // 0x8006A4A8: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x8006A4AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006A4B0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006A4B4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006A4B8: jal         0x8005C28C
    // 0x8006A4BC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    clearscreen(rdram, ctx);
        goto after_2;
    // 0x8006A4BC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_2:
    // 0x8006A4C0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8006A4C4: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x8006A4C8: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A4CC: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8006A4D0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8006A4D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006A4D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006A4DC: ori         $t8, $t8, 0x49D8
    ctx->r24 = ctx->r24 | 0X49D8;
    // 0x8006A4E0: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8006A4E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006A4E8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8006A4EC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A4F0: addiu       $t7, $zero, 0x205
    ctx->r15 = ADD32(0, 0X205);
    // 0x8006A4F4: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x8006A4F8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006A4FC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006A500: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8006A504: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006A508: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A50C: lui         $ra, 0xB900
    ctx->r31 = S32(0XB900 << 16);
    // 0x8006A510: ori         $ra, $ra, 0x201
    ctx->r31 = ctx->r31 | 0X201;
    // 0x8006A514: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006A518: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006A51C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8006A520: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006A524: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8006A528: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A52C: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8006A530: ori         $t7, $t7, 0x1301
    ctx->r15 = ctx->r15 | 0X1301;
    // 0x8006A534: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006A538: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006A53C: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8006A540: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8006A544: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006A548: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A54C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8006A550: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8006A554: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006A558: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006A55C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006A560: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8006A564: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A568: ori         $t8, $t8, 0x49D8
    ctx->r24 = ctx->r24 | 0X49D8;
    // 0x8006A56C: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8006A570: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006A574: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006A578: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8006A57C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006A580: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A584: lui         $t7, 0xFF33
    ctx->r15 = S32(0XFF33 << 16);
    // 0x8006A588: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x8006A58C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006A590: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006A594: ori         $t6, $t6, 0x1824
    ctx->r14 = ctx->r14 | 0X1824;
    // 0x8006A598: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8006A59C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8006A5A0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006A5A4: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A5A8: lui         $t6, 0xFF00
    ctx->r14 = S32(0XFF00 << 16);
    // 0x8006A5AC: ori         $t6, $t6, 0x77
    ctx->r14 = ctx->r14 | 0X77;
    // 0x8006A5B0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006A5B4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006A5B8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8006A5BC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006A5C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8006A5C4: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A5C8: lui         $t9, 0x9757
    ctx->r25 = S32(0X9757 << 16);
    // 0x8006A5CC: ori         $t9, $t9, 0x2744
    ctx->r25 = ctx->r25 | 0X2744;
    // 0x8006A5D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006A5D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006A5D8: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x8006A5DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006A5E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006A5E4: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A5E8: lui         $t8, 0x5727
    ctx->r24 = S32(0X5727 << 16);
    // 0x8006A5EC: ori         $t8, $t8, 0x9722
    ctx->r24 = ctx->r24 | 0X9722;
    // 0x8006A5F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8006A5F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006A5F8: lui         $t7, 0xF900
    ctx->r15 = S32(0XF900 << 16);
    // 0x8006A5FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006A600: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8006A604: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006A608: lui         $t6, 0xEE00
    ctx->r14 = S32(0XEE00 << 16);
    // 0x8006A60C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8006A610: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006A614: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006A618: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006A61C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8006A620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A624: jr          $ra
    // 0x8006A628: nop

    return;
    // 0x8006A628: nop

;}
RECOMP_FUNC void func_8006693C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006693C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066940: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066944: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80066948: jal         0x8005C28C
    // 0x8006694C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    clearscreen(rdram, ctx);
        goto after_0;
    // 0x8006694C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80066950: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80066954: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x80066958: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006695C: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80066960: ori         $t8, $t8, 0x3C0
    ctx->r24 = ctx->r24 | 0X3C0;
    // 0x80066964: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066968: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006696C: lui         $t7, 0xED00
    ctx->r15 = S32(0XED00 << 16);
    // 0x80066970: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80066974: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80066978: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006697C: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80066980: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80066984: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066988: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006698C: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x80066990: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x80066994: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80066998: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006699C: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800669A0: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x800669A4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800669A8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800669AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800669B0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800669B4: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x800669B8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800669BC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800669C0: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800669C4: lui         $t9, 0xFF00
    ctx->r25 = S32(0XFF00 << 16);
    // 0x800669C8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800669CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800669D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800669D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800669D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800669DC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800669E0: lui         $t7, 0xE44F
    ctx->r15 = S32(0XE44F << 16);
    // 0x800669E4: ori         $t7, $t7, 0xC044
    ctx->r15 = ctx->r15 | 0XC044;
    // 0x800669E8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800669EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800669F0: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800669F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800669F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800669FC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066A00: lui         $ra, 0xB400
    ctx->r31 = S32(0XB400 << 16);
    // 0x80066A04: lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // 0x80066A08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066A0C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066A10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066A14: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80066A18: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066A1C: ori         $s1, $s1, 0x400
    ctx->r17 = ctx->r17 | 0X400;
    // 0x80066A20: lui         $s0, 0xB300
    ctx->r16 = S32(0XB300 << 16);
    // 0x80066A24: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066A28: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066A2C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80066A30: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80066A34: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066A38: lui         $t8, 0xE44F
    ctx->r24 = S32(0XE44F << 16);
    // 0x80066A3C: ori         $t8, $t8, 0xC380
    ctx->r24 = ctx->r24 | 0XC380;
    // 0x80066A40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80066A44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80066A48: addiu       $t9, $zero, 0x37C
    ctx->r25 = ADD32(0, 0X37C);
    // 0x80066A4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80066A50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066A54: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066A58: lui         $t9, 0xE405
    ctx->r25 = S32(0XE405 << 16);
    // 0x80066A5C: ori         $t9, $t9, 0xC3C0
    ctx->r25 = ctx->r25 | 0XC3C0;
    // 0x80066A60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066A64: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066A68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066A6C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80066A70: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066A74: lui         $t6, 0x5
    ctx->r14 = S32(0X5 << 16);
    // 0x80066A78: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80066A7C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80066A80: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80066A84: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80066A88: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80066A8C: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066A90: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80066A94: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80066A98: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80066A9C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80066AA0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80066AA4: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066AA8: lui         $t6, 0xE44A
    ctx->r14 = S32(0XE44A << 16);
    // 0x80066AAC: ori         $t6, $t6, 0x83C0
    ctx->r14 = ctx->r14 | 0X83C0;
    // 0x80066AB0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80066AB4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80066AB8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066ABC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80066AC0: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066AC4: lui         $t7, 0x4A
    ctx->r15 = S32(0X4A << 16);
    // 0x80066AC8: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x80066ACC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80066AD0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80066AD4: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80066AD8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80066ADC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066AE0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066AE4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066AE8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80066AEC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80066AF0: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066AF4: lui         $t7, 0xE44F
    ctx->r15 = S32(0XE44F << 16);
    // 0x80066AF8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80066AFC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80066B00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066B04: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80066B08: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066B0C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066B10: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066B14: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80066B18: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80066B1C: lh          $t2, -0x9DC($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X9DC));
    // 0x80066B20: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80066B24: bnel        $at, $zero, L_80066B7C
    if (ctx->r1 != 0) {
        // 0x80066B28: slti        $at, $t2, 0x3
        ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
            goto L_80066B7C;
    }
    goto skip_0;
    // 0x80066B28: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    skip_0:
    // 0x80066B2C: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066B30: ori         $t7, $t7, 0xC1E4
    ctx->r15 = ctx->r15 | 0XC1E4;
    // 0x80066B34: addiu       $t8, $zero, 0x1D8
    ctx->r24 = ADD32(0, 0X1D8);
    // 0x80066B38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066B3C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066B40: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80066B44: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80066B48: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066B4C: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80066B50: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066B54: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80066B58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066B5C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80066B60: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066B64: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066B68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066B6C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80066B70: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80066B74: lh          $t2, -0x9DC($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X9DC));
    // 0x80066B78: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
L_80066B7C:
    // 0x80066B7C: bne         $at, $zero, L_80066BCC
    if (ctx->r1 != 0) {
        // 0x80066B80: lui         $t8, 0xE428
        ctx->r24 = S32(0XE428 << 16);
            goto L_80066BCC;
    }
    // 0x80066B80: lui         $t8, 0xE428
    ctx->r24 = S32(0XE428 << 16);
    // 0x80066B84: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066B88: lui         $t9, 0x27
    ctx->r25 = S32(0X27 << 16);
    // 0x80066B8C: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x80066B90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80066B94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80066B98: ori         $t8, $t8, 0x83C0
    ctx->r24 = ctx->r24 | 0X83C0;
    // 0x80066B9C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80066BA0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80066BA4: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066BA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80066BAC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80066BB0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80066BB4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80066BB8: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80066BBC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80066BC0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80066BC4: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80066BC8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_80066BCC:
    // 0x80066BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80066BD0: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80066BD4: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80066BD8: jr          $ra
    // 0x80066BDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80066BDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void clipinsidebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A98: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80091A9C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80091AA0: addiu       $t5, $zero, 0x24
    ctx->r13 = ADD32(0, 0X24);
    // 0x80091AA4: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091AA8: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x80091AAC: addiu       $t4, $t4, 0x61A8
    ctx->r12 = ADD32(ctx->r12, 0X61A8);
    // 0x80091AB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80091AB4: mflo        $t8
    ctx->r24 = lo;
    // 0x80091AB8: addu        $v0, $t4, $t8
    ctx->r2 = ADD32(ctx->r12, ctx->r24);
    // 0x80091ABC: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80091AC0: lw          $t7, 0x4($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80091AC4: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x80091AC8: lh          $t9, 0x8($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X8));
    // 0x80091ACC: subu        $v1, $t6, $a0
    ctx->r3 = SUB32(ctx->r14, ctx->r4);
    // 0x80091AD0: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x80091AD4: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091AD8: subu        $t0, $t8, $a1
    ctx->r8 = SUB32(ctx->r24, ctx->r5);
    // 0x80091ADC: mflo        $t6
    ctx->r14 = lo;
    // 0x80091AE0: addu        $t1, $t4, $t6
    ctx->r9 = ADD32(ctx->r12, ctx->r14);
    // 0x80091AE4: lw          $t7, 0x0($t1)
    ctx->r15 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80091AE8: lw          $t9, 0x4($t1)
    ctx->r25 = S32(MEM_W(ctx->r9, 0X4));
    // 0x80091AEC: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x80091AF0: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x80091AF4: subu        $t3, $t6, $a1
    ctx->r11 = SUB32(ctx->r14, ctx->r5);
    // 0x80091AF8: bgez        $v1, L_80091B10
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80091AFC: subu        $t2, $t8, $a0
        ctx->r10 = SUB32(ctx->r24, ctx->r4);
            goto L_80091B10;
    }
    // 0x80091AFC: subu        $t2, $t8, $a0
    ctx->r10 = SUB32(ctx->r24, ctx->r4);
    // 0x80091B00: bgez        $t2, L_80091B10
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80091B04: nop
    
            goto L_80091B10;
    }
    // 0x80091B04: nop

    // 0x80091B08: jr          $ra
    // 0x80091B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80091B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091B10:
    // 0x80091B10: bgez        $t0, L_80091B28
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80091B14: sll         $v0, $a3, 1
        ctx->r2 = S32(ctx->r7 << 1);
            goto L_80091B28;
    }
    // 0x80091B14: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x80091B18: bgezl       $t3, L_80091B2C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80091B1C: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80091B2C;
    }
    goto skip_0;
    // 0x80091B1C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x80091B20: jr          $ra
    // 0x80091B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80091B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091B28:
    // 0x80091B28: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_80091B2C:
    // 0x80091B2C: bne         $at, $zero, L_80091B44
    if (ctx->r1 != 0) {
        // 0x80091B30: slt         $at, $t2, $v0
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80091B44;
    }
    // 0x80091B30: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80091B34: bnel        $at, $zero, L_80091B48
    if (ctx->r1 != 0) {
        // 0x80091B38: slt         $at, $t0, $v0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80091B48;
    }
    goto skip_1;
    // 0x80091B38: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    skip_1:
    // 0x80091B3C: jr          $ra
    // 0x80091B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80091B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091B44:
    // 0x80091B44: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
L_80091B48:
    // 0x80091B48: bne         $at, $zero, L_80091B64
    if (ctx->r1 != 0) {
        // 0x80091B4C: subu        $t2, $t2, $v1
        ctx->r10 = SUB32(ctx->r10, ctx->r3);
            goto L_80091B64;
    }
    // 0x80091B4C: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80091B50: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80091B54: bnel        $at, $zero, L_80091B68
    if (ctx->r1 != 0) {
        // 0x80091B58: subu        $t7, $a3, $t0
        ctx->r15 = SUB32(ctx->r7, ctx->r8);
            goto L_80091B68;
    }
    goto skip_2;
    // 0x80091B58: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
    skip_2:
    // 0x80091B5C: jr          $ra
    // 0x80091B60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80091B60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091B64:
    // 0x80091B64: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
L_80091B68:
    // 0x80091B68: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091B6C: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x80091B70: subu        $t9, $a3, $v1
    ctx->r25 = SUB32(ctx->r7, ctx->r3);
    // 0x80091B74: mflo        $t8
    ctx->r24 = lo;
    // 0x80091B78: nop

    // 0x80091B7C: nop

    // 0x80091B80: multu       $t3, $t9
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091B84: mflo        $t6
    ctx->r14 = lo;
    // 0x80091B88: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80091B8C: bne         $at, $zero, L_80091BF8
    if (ctx->r1 != 0) {
        // 0x80091B90: nop
    
            goto L_80091BF8;
    }
    // 0x80091B90: nop

    // 0x80091B94: blez        $t2, L_80091BB0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80091B98: subu        $t9, $v0, $t0
        ctx->r25 = SUB32(ctx->r2, ctx->r8);
            goto L_80091BB0;
    }
    // 0x80091B98: subu        $t9, $v0, $t0
    ctx->r25 = SUB32(ctx->r2, ctx->r8);
    // 0x80091B9C: negu        $t7, $t0
    ctx->r15 = SUB32(0, ctx->r8);
    // 0x80091BA0: multu       $t2, $t7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091BA4: mflo        $t2
    ctx->r10 = lo;
    // 0x80091BA8: b           L_80091BC0
    // 0x80091BAC: nop

        goto L_80091BC0;
    // 0x80091BAC: nop

L_80091BB0:
    // 0x80091BB0: multu       $t2, $t9
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091BB4: mflo        $t2
    ctx->r10 = lo;
    // 0x80091BB8: nop

    // 0x80091BBC: nop

L_80091BC0:
    // 0x80091BC0: blez        $t3, L_80091BE0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80091BC4: negu        $t6, $v1
        ctx->r14 = SUB32(0, ctx->r3);
            goto L_80091BE0;
    }
    // 0x80091BC4: negu        $t6, $v1
    ctx->r14 = SUB32(0, ctx->r3);
    // 0x80091BC8: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x80091BCC: multu       $t3, $t8
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091BD0: mflo        $t3
    ctx->r11 = lo;
    // 0x80091BD4: slt         $v0, $t2, $t3
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80091BD8: jr          $ra
    // 0x80091BDC: nop

    return;
    // 0x80091BDC: nop

L_80091BE0:
    // 0x80091BE0: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091BE4: mflo        $t3
    ctx->r11 = lo;
    // 0x80091BE8: nop

    // 0x80091BEC: nop

    // 0x80091BF0: jr          $ra
    // 0x80091BF4: slt         $v0, $t2, $t3
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    return;
    // 0x80091BF4: slt         $v0, $t2, $t3
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
L_80091BF8:
    // 0x80091BF8: blez        $t2, L_80091C14
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80091BFC: negu        $t9, $t0
        ctx->r25 = SUB32(0, ctx->r8);
            goto L_80091C14;
    }
    // 0x80091BFC: negu        $t9, $t0
    ctx->r25 = SUB32(0, ctx->r8);
    // 0x80091C00: subu        $t7, $v0, $t0
    ctx->r15 = SUB32(ctx->r2, ctx->r8);
    // 0x80091C04: multu       $t2, $t7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091C08: mflo        $t2
    ctx->r10 = lo;
    // 0x80091C0C: b           L_80091C24
    // 0x80091C10: nop

        goto L_80091C24;
    // 0x80091C10: nop

L_80091C14:
    // 0x80091C14: multu       $t2, $t9
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091C18: mflo        $t2
    ctx->r10 = lo;
    // 0x80091C1C: nop

    // 0x80091C20: nop

L_80091C24:
    // 0x80091C24: blez        $t3, L_80091C40
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80091C28: subu        $t6, $v0, $v1
        ctx->r14 = SUB32(ctx->r2, ctx->r3);
            goto L_80091C40;
    }
    // 0x80091C28: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x80091C2C: negu        $t8, $v1
    ctx->r24 = SUB32(0, ctx->r3);
    // 0x80091C30: multu       $t3, $t8
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091C34: mflo        $t3
    ctx->r11 = lo;
    // 0x80091C38: b           L_80091C54
    // 0x80091C3C: slt         $v0, $t2, $t3
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
        goto L_80091C54;
    // 0x80091C3C: slt         $v0, $t2, $t3
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
L_80091C40:
    // 0x80091C40: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091C44: mflo        $t3
    ctx->r11 = lo;
    // 0x80091C48: nop

    // 0x80091C4C: nop

    // 0x80091C50: slt         $v0, $t2, $t3
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
L_80091C54:
    // 0x80091C54: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80091C58: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80091C5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80091C60: jr          $ra
    // 0x80091C64: nop

    return;
    // 0x80091C64: nop

;}
RECOMP_FUNC void allignwarpelevators(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2E9C: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800B2EA0: lh          $v1, 0x285E($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X285E));
    // 0x800B2EA4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B2EA8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800B2EAC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800B2EB0: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800B2EB4: bltz        $t6, L_800B2FA4
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B2EB8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800B2FA4;
    }
    // 0x800B2EB8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800B2EBC: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800B2EC0: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800B2EC4: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x800B2EC8: addiu       $t2, $t2, 0x6BA8
    ctx->r10 = ADD32(ctx->r10, 0X6BA8);
    // 0x800B2ECC: addiu       $t4, $t4, -0x1988
    ctx->r12 = ADD32(ctx->r12, -0X1988);
    // 0x800B2ED0: addiu       $s0, $s0, 0x5F40
    ctx->r16 = ADD32(ctx->r16, 0X5F40);
    // 0x800B2ED4: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x800B2ED8: addiu       $t3, $zero, 0x2C
    ctx->r11 = ADD32(0, 0X2C);
    // 0x800B2EDC: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
L_800B2EE0:
    // 0x800B2EE0: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2EE4: mflo        $t7
    ctx->r15 = lo;
    // 0x800B2EE8: addu        $a0, $t2, $t7
    ctx->r4 = ADD32(ctx->r10, ctx->r15);
    // 0x800B2EEC: lh          $t8, 0x1E($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X1E));
    // 0x800B2EF0: bnel        $t1, $t8, L_800B2F94
    if (ctx->r9 != ctx->r24) {
        // 0x800B2EF4: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_800B2F94;
    }
    goto skip_0;
    // 0x800B2EF4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    skip_0:
    // 0x800B2EF8: lb          $t9, 0x24($a0)
    ctx->r25 = S32(MEM_B(ctx->r4, 0X24));
    // 0x800B2EFC: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x800B2F00: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2F04: slti        $at, $t9, 0x11
    ctx->r1 = SIGNED(ctx->r25) < 0X11 ? 1 : 0;
    // 0x800B2F08: bnel        $at, $zero, L_800B2F94
    if (ctx->r1 != 0) {
        // 0x800B2F0C: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_800B2F94;
    }
    goto skip_1;
    // 0x800B2F0C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    skip_1:
    // 0x800B2F10: bltz        $t6, L_800B2F90
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B2F14: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800B2F90;
    }
    // 0x800B2F14: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_800B2F18:
    // 0x800B2F18: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2F1C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B2F20: addu        $a2, $t2, $t7
    ctx->r6 = ADD32(ctx->r10, ctx->r15);
    // 0x800B2F24: lh          $t8, 0x1E($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0X1E));
    // 0x800B2F28: bnel        $t1, $t8, L_800B2F80
    if (ctx->r9 != ctx->r24) {
        // 0x800B2F2C: sll         $t9, $a1, 1
        ctx->r25 = S32(ctx->r5 << 1);
            goto L_800B2F80;
    }
    goto skip_2;
    // 0x800B2F2C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    skip_2:
    // 0x800B2F30: beql        $v0, $a1, L_800B2F80
    if (ctx->r2 == ctx->r5) {
        // 0x800B2F34: sll         $t9, $a1, 1
        ctx->r25 = S32(ctx->r5 << 1);
            goto L_800B2F80;
    }
    goto skip_3;
    // 0x800B2F34: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    skip_3:
    // 0x800B2F38: lh          $t9, 0x20($a0)
    ctx->r25 = S32(MEM_H(ctx->r4, 0X20));
    // 0x800B2F3C: lh          $t6, 0x20($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0X20));
    // 0x800B2F40: bnel        $t9, $t6, L_800B2F80
    if (ctx->r25 != ctx->r14) {
        // 0x800B2F44: sll         $t9, $a1, 1
        ctx->r25 = S32(ctx->r5 << 1);
            goto L_800B2F80;
    }
    goto skip_4;
    // 0x800B2F44: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    skip_4:
    // 0x800B2F48: lh          $t7, 0x10($a2)
    ctx->r15 = S32(MEM_H(ctx->r6, 0X10));
    // 0x800B2F4C: lh          $t9, 0x10($a0)
    ctx->r25 = S32(MEM_H(ctx->r4, 0X10));
    // 0x800B2F50: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2F54: mflo        $t8
    ctx->r24 = lo;
    // 0x800B2F58: addu        $a3, $t4, $t8
    ctx->r7 = ADD32(ctx->r12, ctx->r24);
    // 0x800B2F5C: nop

    // 0x800B2F60: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2F64: mflo        $t6
    ctx->r14 = lo;
    // 0x800B2F68: addu        $t0, $t4, $t6
    ctx->r8 = ADD32(ctx->r12, ctx->r14);
    // 0x800B2F6C: lw          $t7, 0x4($t0)
    ctx->r15 = S32(MEM_W(ctx->r8, 0X4));
    // 0x800B2F70: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800B2F74: lw          $t8, 0x0($t0)
    ctx->r24 = S32(MEM_W(ctx->r8, 0X0));
    // 0x800B2F78: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800B2F7C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
L_800B2F80:
    // 0x800B2F80: addu        $t6, $s0, $t9
    ctx->r14 = ADD32(ctx->r16, ctx->r25);
    // 0x800B2F84: lh          $a1, 0x0($t6)
    ctx->r5 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800B2F88: bgez        $a1, L_800B2F18
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B2F8C: nop
    
            goto L_800B2F18;
    }
    // 0x800B2F8C: nop

L_800B2F90:
    // 0x800B2F90: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
L_800B2F94:
    // 0x800B2F94: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800B2F98: lh          $v0, 0x0($t8)
    ctx->r2 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800B2F9C: bgez        $v0, L_800B2EE0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B2FA0: nop
    
            goto L_800B2EE0;
    }
    // 0x800B2FA0: nop

L_800B2FA4:
    // 0x800B2FA4: lw          $s0, 0x4($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X4));
    // 0x800B2FA8: jr          $ra
    // 0x800B2FAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B2FAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void alCSeqTicksToSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C21C0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800C21C4: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800C21C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C21CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C21D0: bgez        $a2, L_800C21E4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C21D4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C21E4;
    }
    // 0x800C21D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C21D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C21DC: nop

    // 0x800C21E0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800C21E4:
    // 0x800C21E4: lw          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800C21E8: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C21EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C21F0: lw          $t7, 0x40($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X40));
    // 0x800C21F4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800C21F8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800C21FC: bgez        $t7, L_800C2210
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C2200: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C2210;
    }
    // 0x800C2200: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C2204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2208: nop

    // 0x800C220C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_800C2210:
    // 0x800C2210: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2214: ldc1        $f18, -0x6458($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6458);
    // 0x800C2218: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800C221C: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800C2220: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800C2224: jr          $ra
    // 0x800C2228: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    return;
    // 0x800C2228: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8C48: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C8C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8C50: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800C8C54: jal         0x800C8BC0
    // 0x800C8C58: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800C8C58: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800C8C5C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C8C60: jal         0x800C8AC0
    // 0x800C8C64: lw          $a1, 0x58($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X58));
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800C8C64: lw          $a1, 0x58($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X58));
    after_1:
    // 0x800C8C68: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C8C6C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800C8C70: jr          $ra
    // 0x800C8C74: nop

    return;
    // 0x800C8C74: nop

;}
RECOMP_FUNC void hitasprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1CD4: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x800A1CD8: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800A1CDC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A1CE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A1CE4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800A1CE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A1CEC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A1CF0: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800A1CF4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800A1CF8: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x800A1CFC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A1D00: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A1D04: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800A1D08: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x800A1D0C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800A1D10: jal         0x80099ED4
    // 0x800A1D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    badguy(rdram, ctx);
        goto after_0;
    // 0x800A1D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A1D18: beq         $v0, $zero, L_800A1D28
    if (ctx->r2 == 0) {
        // 0x800A1D1C: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_800A1D28;
    }
    // 0x800A1D1C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x800A1D20: b           L_800A1D44
    // 0x800A1D24: addiu       $v1, $zero, 0x2A00
    ctx->r3 = ADD32(0, 0X2A00);
        goto L_800A1D44;
    // 0x800A1D24: addiu       $v1, $zero, 0x2A00
    ctx->r3 = ADD32(0, 0X2A00);
L_800A1D28:
    // 0x800A1D28: lh          $t9, 0xE($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0XE));
    // 0x800A1D2C: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x800A1D30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A1D34: bne         $t9, $at, L_800A1D44
    if (ctx->r25 != ctx->r1) {
        // 0x800A1D38: nop
    
            goto L_800A1D44;
    }
    // 0x800A1D38: nop

    // 0x800A1D3C: b           L_800A1D44
    // 0x800A1D40: addiu       $v1, $zero, 0x2700
    ctx->r3 = ADD32(0, 0X2700);
        goto L_800A1D44;
    // 0x800A1D40: addiu       $v1, $zero, 0x2700
    ctx->r3 = ADD32(0, 0X2700);
L_800A1D44:
    // 0x800A1D44: lh          $v0, 0x14($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X14));
    // 0x800A1D48: addiu       $t0, $t0, -0x9A0
    ctx->r8 = ADD32(ctx->r8, -0X9A0);
    // 0x800A1D4C: lw          $t1, 0x8($s0)
    ctx->r9 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A1D50: addiu       $t2, $v0, 0x200
    ctx->r10 = ADD32(ctx->r2, 0X200);
    // 0x800A1D54: andi        $t3, $t2, 0x7FF
    ctx->r11 = ctx->r10 & 0X7FF;
    // 0x800A1D58: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800A1D5C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800A1D60: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800A1D64: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x800A1D68: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800A1D6C: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x800A1D70: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x800A1D74: lh          $t1, 0x0($t9)
    ctx->r9 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800A1D78: lw          $t4, 0x6C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x800A1D7C: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x800A1D80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A1D84: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x800A1D88: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x800A1D8C: addiu       $t7, $sp, 0x5C
    ctx->r15 = ADD32(ctx->r29, 0X5C);
    // 0x800A1D90: addiu       $t5, $sp, 0x64
    ctx->r13 = ADD32(ctx->r29, 0X64);
    // 0x800A1D94: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x800A1D98: addiu       $t2, $sp, 0x56
    ctx->r10 = ADD32(ctx->r29, 0X56);
    // 0x800A1D9C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A1DA0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800A1DA4: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800A1DA8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800A1DAC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800A1DB0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800A1DB4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800A1DB8: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800A1DBC: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800A1DC0: lh          $a3, 0x10($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800A1DC4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800A1DC8: jal         0x8009324C
    // 0x800A1DCC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    hitscan(rdram, ctx);
        goto after_1;
    // 0x800A1DCC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    after_1:
    // 0x800A1DD0: lh          $v1, 0x54($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X54));
    // 0x800A1DD4: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x800A1DD8: bltz        $v1, L_800A1E14
    if (SIGNED(ctx->r3) < 0) {
        // 0x800A1DDC: sll         $t9, $v1, 3
        ctx->r25 = S32(ctx->r3 << 3);
            goto L_800A1E14;
    }
    // 0x800A1DDC: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800A1DE0: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x800A1DE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A1DE8: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800A1DEC: lh          $t1, 0x61B6($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, 0X61B6));
    // 0x800A1DF0: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x800A1DF4: beql        $t2, $zero, L_800A1E18
    if (ctx->r10 == 0) {
        // 0x800A1DF8: lw          $t3, 0x64($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
            goto L_800A1E18;
    }
    goto skip_0;
    // 0x800A1DF8: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
    skip_0:
    // 0x800A1DFC: jal         0x80099ED4
    // 0x800A1E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    badguy(rdram, ctx);
        goto after_2;
    // 0x800A1E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A1E04: beql        $v0, $zero, L_800A1E18
    if (ctx->r2 == 0) {
        // 0x800A1E08: lw          $t3, 0x64($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
            goto L_800A1E18;
    }
    goto skip_1;
    // 0x800A1E08: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
    skip_1:
    // 0x800A1E0C: b           L_800A1E30
    // 0x800A1E10: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
        goto L_800A1E30;
    // 0x800A1E10: lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
L_800A1E14:
    // 0x800A1E14: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
L_800A1E18:
    // 0x800A1E18: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800A1E1C: lw          $t5, 0x60($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800A1E20: lw          $t6, 0x4($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800A1E24: subu        $a0, $t3, $t4
    ctx->r4 = SUB32(ctx->r11, ctx->r12);
    // 0x800A1E28: jal         0x800993E0
    // 0x800A1E2C: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    FindDistance2D(rdram, ctx);
        goto after_3;
    // 0x800A1E2C: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    after_3:
L_800A1E30:
    // 0x800A1E30: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800A1E34: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800A1E38: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800A1E3C: jr          $ra
    // 0x800A1E40: nop

    return;
    // 0x800A1E40: nop

;}
RECOMP_FUNC void func_80059468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059468: andi        $t6, $a0, 0x7
    ctx->r14 = ctx->r4 & 0X7;
    // 0x8005946C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80059470: sra         $t8, $a0, 3
    ctx->r24 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80059474: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80059478: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005947C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80059480: lbu         $t7, 0x4D90($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4D90);
    // 0x80059484: lbu         $t9, -0x5308($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X5308);
    // 0x80059488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005948C: and         $t0, $t7, $t9
    ctx->r8 = ctx->r15 & ctx->r25;
    // 0x80059490: beq         $t0, $zero, L_800594A0
    if (ctx->r8 == 0) {
        // 0x80059494: nop
    
            goto L_800594A0;
    }
    // 0x80059494: nop

    // 0x80059498: jr          $ra
    // 0x8005949C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005949C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800594A0:
    // 0x800594A0: jr          $ra
    // 0x800594A4: nop

    return;
    // 0x800594A4: nop

;}
RECOMP_FUNC void dmulscale23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090B84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090B8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090B90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090B94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090B98: jal         0x800BB8F8
    // 0x80090B9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090B9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090BA0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090BA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090BA8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090BAC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090BB0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090BB4: jal         0x800BB8F8
    // 0x80090BB8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090BB8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090BBC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090BC0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090BC4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090BC8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090BCC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090BD0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090BD4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090BD8: jal         0x800BBA24
    // 0x80090BDC: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090BDC: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    after_2:
    // 0x80090BE0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090BE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090BEC: jr          $ra
    // 0x80090BF0: nop

    return;
    // 0x80090BF0: nop

;}
RECOMP_FUNC void lintersect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009521C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80095220: lw          $t8, 0x7C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x80095224: lw          $t9, 0x84($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X84));
    // 0x80095228: subu        $t4, $a3, $a0
    ctx->r12 = SUB32(ctx->r7, ctx->r4);
    // 0x8009522C: lw          $t6, 0x78($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X78));
    // 0x80095230: subu        $t3, $t8, $t9
    ctx->r11 = SUB32(ctx->r24, ctx->r25);
    // 0x80095234: multu       $t4, $t3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095238: lw          $t7, 0x80($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X80));
    // 0x8009523C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80095240: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80095244: subu        $t2, $t6, $t7
    ctx->r10 = SUB32(ctx->r14, ctx->r15);
    // 0x80095248: lw          $t7, 0x70($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X70));
    // 0x8009524C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095250: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80095254: subu        $t5, $t7, $a1
    ctx->r13 = SUB32(ctx->r15, ctx->r5);
    // 0x80095258: lw          $t7, 0x78($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X78));
    // 0x8009525C: mflo        $t9
    ctx->r25 = lo;
    // 0x80095260: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80095264: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x80095268: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009526C: mflo        $t6
    ctx->r14 = lo;
    // 0x80095270: subu        $t0, $t9, $t6
    ctx->r8 = SUB32(ctx->r25, ctx->r14);
    // 0x80095274: bltz        $t0, L_80095308
    if (SIGNED(ctx->r8) < 0) {
        // 0x80095278: nop
    
            goto L_80095308;
    }
    // 0x80095278: nop

    // 0x8009527C: bne         $t0, $zero, L_8009528C
    if (ctx->r8 != 0) {
        // 0x80095280: lw          $t7, 0x78($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X78));
            goto L_8009528C;
    }
    // 0x80095280: lw          $t7, 0x78($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X78));
    // 0x80095284: b           L_8009541C
    // 0x80095288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009541C;
    // 0x80095288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009528C:
    // 0x8009528C: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80095290: lw          $t9, 0x7C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x80095294: lw          $t6, 0x64($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X64));
    // 0x80095298: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x8009529C: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800952A0: subu        $a0, $t9, $t6
    ctx->r4 = SUB32(ctx->r25, ctx->r14);
    // 0x800952A4: mflo        $t7
    ctx->r15 = lo;
    // 0x800952A8: nop

    // 0x800952AC: nop

    // 0x800952B0: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800952B4: mflo        $t8
    ctx->r24 = lo;
    // 0x800952B8: subu        $t1, $t7, $t8
    ctx->r9 = SUB32(ctx->r15, ctx->r24);
    // 0x800952BC: bltz        $t1, L_800952CC
    if (SIGNED(ctx->r9) < 0) {
        // 0x800952C0: slt         $at, $t1, $t0
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800952CC;
    }
    // 0x800952C0: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800952C4: bne         $at, $zero, L_800952D4
    if (ctx->r1 != 0) {
        // 0x800952C8: nop
    
            goto L_800952D4;
    }
    // 0x800952C8: nop

L_800952CC:
    // 0x800952CC: b           L_8009541C
    // 0x800952D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009541C;
    // 0x800952D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800952D4:
    // 0x800952D4: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800952D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800952DC: nop

    // 0x800952E0: nop

    // 0x800952E4: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800952E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800952EC: subu        $v0, $t9, $t6
    ctx->r2 = SUB32(ctx->r25, ctx->r14);
    // 0x800952F0: bltz        $v0, L_80095300
    if (SIGNED(ctx->r2) < 0) {
        // 0x800952F4: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80095300;
    }
    // 0x800952F4: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800952F8: bnel        $at, $zero, L_80095380
    if (ctx->r1 != 0) {
        // 0x800952FC: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_80095380;
    }
    goto skip_0;
    // 0x800952FC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    skip_0:
L_80095300:
    // 0x80095300: b           L_8009541C
    // 0x80095304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009541C;
    // 0x80095304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80095308:
    // 0x80095308: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009530C: lw          $t9, 0x7C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x80095310: lw          $t6, 0x64($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X64));
    // 0x80095314: subu        $a0, $t9, $t6
    ctx->r4 = SUB32(ctx->r25, ctx->r14);
    // 0x80095318: mflo        $t7
    ctx->r15 = lo;
    // 0x8009531C: nop

    // 0x80095320: nop

    // 0x80095324: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095328: mflo        $t8
    ctx->r24 = lo;
    // 0x8009532C: subu        $t1, $t7, $t8
    ctx->r9 = SUB32(ctx->r15, ctx->r24);
    // 0x80095330: bgtz        $t1, L_80095340
    if (SIGNED(ctx->r9) > 0) {
        // 0x80095334: slt         $at, $t0, $t1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80095340;
    }
    // 0x80095334: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80095338: bne         $at, $zero, L_80095348
    if (ctx->r1 != 0) {
        // 0x8009533C: nop
    
            goto L_80095348;
    }
    // 0x8009533C: nop

L_80095340:
    // 0x80095340: b           L_8009541C
    // 0x80095344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009541C;
    // 0x80095344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80095348:
    // 0x80095348: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009534C: mflo        $t9
    ctx->r25 = lo;
    // 0x80095350: nop

    // 0x80095354: nop

    // 0x80095358: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009535C: mflo        $t6
    ctx->r14 = lo;
    // 0x80095360: subu        $v0, $t9, $t6
    ctx->r2 = SUB32(ctx->r25, ctx->r14);
    // 0x80095364: bgtz        $v0, L_80095374
    if (SIGNED(ctx->r2) > 0) {
        // 0x80095368: slt         $at, $t0, $v0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80095374;
    }
    // 0x80095368: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8009536C: bnel        $at, $zero, L_80095380
    if (ctx->r1 != 0) {
        // 0x80095370: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_80095380;
    }
    goto skip_1;
    // 0x80095370: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    skip_1:
L_80095374:
    // 0x80095374: b           L_8009541C
    // 0x80095378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009541C;
    // 0x80095378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009537C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80095380:
    // 0x80095380: sra         $a0, $t1, 31
    ctx->r4 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80095384: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80095388: sra         $a2, $t0, 31
    ctx->r6 = S32(SIGNED(ctx->r8) >> 31);
    // 0x8009538C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80095390: jal         0x80091704
    // 0x80095394: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    divscale24(rdram, ctx);
        goto after_0;
    // 0x80095394: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    after_0:
    // 0x80095398: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8009539C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800953A0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800953A4: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800953A8: jal         0x8008FF80
    // 0x800953AC: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale24(rdram, ctx);
        goto after_1;
    // 0x800953AC: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_1:
    // 0x800953B0: lw          $t7, 0x60($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800953B4: lw          $t9, 0x88($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X88));
    // 0x800953B8: lw          $a1, 0x30($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800953BC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800953C0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800953C4: lw          $a3, 0x38($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800953C8: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800953CC: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x800953D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800953D4: jal         0x8008FF80
    // 0x800953D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    mulscale24(rdram, ctx);
        goto after_2;
    // 0x800953D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800953DC: lw          $t7, 0x64($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800953E0: lw          $t8, 0x8C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800953E4: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x800953E8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800953EC: lw          $t7, 0x68($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800953F0: lw          $t9, 0x74($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X74));
    // 0x800953F4: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800953F8: lw          $a2, 0x18($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800953FC: subu        $a1, $t9, $t7
    ctx->r5 = SUB32(ctx->r25, ctx->r15);
    // 0x80095400: jal         0x8008FF80
    // 0x80095404: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale24(rdram, ctx);
        goto after_3;
    // 0x80095404: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_3:
    // 0x80095408: lw          $t8, 0x68($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X68));
    // 0x8009540C: lw          $t7, 0x90($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X90));
    // 0x80095410: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80095414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80095418: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
L_8009541C:
    // 0x8009541C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80095420: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80095424: jr          $ra
    // 0x80095428: nop

    return;
    // 0x80095428: nop

;}
RECOMP_FUNC void alEnvmixerParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD8A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD8A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CD8AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD8B0: beq         $a1, $v0, L_800CD950
    if (ctx->r5 == ctx->r2) {
        // 0x800CD8B4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CD950;
    }
    // 0x800CD8B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CD8B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CD8BC: beq         $a1, $at, L_800CD8DC
    if (ctx->r5 == ctx->r1) {
        // 0x800CD8C0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800CD8DC;
    }
    // 0x800CD8C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CD8C4: beq         $a1, $at, L_800CD8FC
    if (ctx->r5 == ctx->r1) {
        // 0x800CD8C8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800CD8FC;
    }
    // 0x800CD8C8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800CD8CC: beql        $a1, $at, L_800CD92C
    if (ctx->r5 == ctx->r1) {
        // 0x800CD8D0: lw          $a0, 0x0($a3)
        ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
            goto L_800CD92C;
    }
    goto skip_0;
    // 0x800CD8D0: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
    skip_0:
    // 0x800CD8D4: b           L_800CD95C
    // 0x800CD8D8: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
        goto L_800CD95C;
    // 0x800CD8D8: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
L_800CD8DC:
    // 0x800CD8DC: lw          $v0, 0x40($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X40));
    // 0x800CD8E0: beql        $v0, $zero, L_800CD8F4
    if (ctx->r2 == 0) {
        // 0x800CD8E4: sw          $a2, 0x3C($a3)
        MEM_W(0X3C, ctx->r7) = ctx->r6;
            goto L_800CD8F4;
    }
    goto skip_1;
    // 0x800CD8E4: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
    skip_1:
    // 0x800CD8E8: b           L_800CD8F4
    // 0x800CD8EC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_800CD8F4;
    // 0x800CD8EC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800CD8F0: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
L_800CD8F4:
    // 0x800CD8F4: b           L_800CD970
    // 0x800CD8F8: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
        goto L_800CD970;
    // 0x800CD8F8: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
L_800CD8FC:
    // 0x800CD8FC: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
    // 0x800CD900: sw          $v0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r2;
    // 0x800CD904: sw          $zero, 0x48($a3)
    MEM_W(0X48, ctx->r7) = 0;
    // 0x800CD908: beq         $a0, $zero, L_800CD970
    if (ctx->r4 == 0) {
        // 0x800CD90C: sh          $v0, 0x1A($a3)
        MEM_H(0X1A, ctx->r7) = ctx->r2;
            goto L_800CD970;
    }
    // 0x800CD90C: sh          $v0, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r2;
    // 0x800CD910: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CD914: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CD918: jalr        $t9
    // 0x800CD91C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CD91C: nop

    after_0:
    // 0x800CD920: b           L_800CD974
    // 0x800CD924: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800CD974;
    // 0x800CD924: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CD928: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
L_800CD92C:
    // 0x800CD92C: sw          $v0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r2;
    // 0x800CD930: beql        $a0, $zero, L_800CD974
    if (ctx->r4 == 0) {
        // 0x800CD934: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CD974;
    }
    goto skip_2;
    // 0x800CD934: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_2:
    // 0x800CD938: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CD93C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CD940: jalr        $t9
    // 0x800CD944: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CD944: nop

    after_1:
    // 0x800CD948: b           L_800CD974
    // 0x800CD94C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800CD974;
    // 0x800CD94C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CD950:
    // 0x800CD950: b           L_800CD970
    // 0x800CD954: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800CD970;
    // 0x800CD954: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x800CD958: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
L_800CD95C:
    // 0x800CD95C: beql        $a0, $zero, L_800CD974
    if (ctx->r4 == 0) {
        // 0x800CD960: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CD974;
    }
    goto skip_3;
    // 0x800CD960: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_3:
    // 0x800CD964: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CD968: jalr        $t9
    // 0x800CD96C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CD96C: nop

    after_2:
L_800CD970:
    // 0x800CD970: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CD974:
    // 0x800CD974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CD97C: jr          $ra
    // 0x800CD980: nop

    return;
    // 0x800CD980: nop

;}
RECOMP_FUNC void dmulscale25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090C64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090C6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090C70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090C74: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090C78: jal         0x800BB8F8
    // 0x80090C7C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090C7C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090C80: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090C84: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090C88: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090C8C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090C90: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090C94: jal         0x800BB8F8
    // 0x80090C98: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090C98: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090C9C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090CA0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090CA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090CA8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090CAC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090CB0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090CB4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090CB8: jal         0x800BBA24
    // 0x80090CBC: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090CBC: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    after_2:
    // 0x80090CC0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090CC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090CC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090CCC: jr          $ra
    // 0x80090CD0: nop

    return;
    // 0x80090CD0: nop

;}
RECOMP_FUNC void gettilesizy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B4EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4EB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B4EB4: jal         0x8006370C
    // 0x800B4EB8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    gettileid(rdram, ctx);
        goto after_0;
    // 0x800B4EB8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_0:
    // 0x800B4EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B4EC0: bne         $v0, $at, L_800B4ED0
    if (ctx->r2 != ctx->r1) {
        // 0x800B4EC4: nop
    
            goto L_800B4ED0;
    }
    // 0x800B4EC4: nop

    // 0x800B4EC8: b           L_800B4EF0
    // 0x800B4ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B4EF0;
    // 0x800B4ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B4ED0:
    // 0x800B4ED0: jal         0x8006370C
    // 0x800B4ED4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    gettileid(rdram, ctx);
        goto after_1;
    // 0x800B4ED4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x800B4ED8: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800B4EDC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800B4EE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B4EE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B4EE8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800B4EEC: lh          $v0, -0x5002($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X5002));
L_800B4EF0:
    // 0x800B4EF0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800B4EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B4EF8: jr          $ra
    // 0x800B4EFC: nop

    return;
    // 0x800B4EFC: nop

;}
RECOMP_FUNC void checkhitceiling(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B147C: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x800B1480: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B1484: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B1488: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B148C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B1490: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x800B1494: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800B1498: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x800B149C: lh          $v0, 0x10($t5)
    ctx->r2 = S32(MEM_H(ctx->r13, 0X10));
    // 0x800B14A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B14A4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800B14A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B14AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B14B0: beq         $v0, $at, L_800B14E0
    if (ctx->r2 == ctx->r1) {
        // 0x800B14B4: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800B14E0;
    }
    // 0x800B14B4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800B14B8: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
    // 0x800B14BC: beq         $v0, $at, L_800B14E0
    if (ctx->r2 == ctx->r1) {
        // 0x800B14C0: addiu       $at, $zero, 0x7C
        ctx->r1 = ADD32(0, 0X7C);
            goto L_800B14E0;
    }
    // 0x800B14C0: addiu       $at, $zero, 0x7C
    ctx->r1 = ADD32(0, 0X7C);
    // 0x800B14C4: beq         $v0, $at, L_800B14E0
    if (ctx->r2 == ctx->r1) {
        // 0x800B14C8: addiu       $at, $zero, 0x2BD
        ctx->r1 = ADD32(0, 0X2BD);
            goto L_800B14E0;
    }
    // 0x800B14C8: addiu       $at, $zero, 0x2BD
    ctx->r1 = ADD32(0, 0X2BD);
    // 0x800B14CC: beq         $v0, $at, L_800B14E0
    if (ctx->r2 == ctx->r1) {
        // 0x800B14D0: addiu       $at, $zero, 0x2BF
        ctx->r1 = ADD32(0, 0X2BF);
            goto L_800B14E0;
    }
    // 0x800B14D0: addiu       $at, $zero, 0x2BF
    ctx->r1 = ADD32(0, 0X2BF);
    // 0x800B14D4: beq         $v0, $at, L_800B14E0
    if (ctx->r2 == ctx->r1) {
        // 0x800B14D8: addiu       $at, $zero, 0x2C1
        ctx->r1 = ADD32(0, 0X2C1);
            goto L_800B14E0;
    }
    // 0x800B14D8: addiu       $at, $zero, 0x2C1
    ctx->r1 = ADD32(0, 0X2C1);
    // 0x800B14DC: bne         $v0, $at, L_800B1768
    if (ctx->r2 != ctx->r1) {
        // 0x800B14E0: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_800B1768;
    }
L_800B14E0:
    // 0x800B14E0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800B14E4: lh          $t9, -0x9D8($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X9D8));
    // 0x800B14E8: lui         $a0, 0x802A
    ctx->r4 = S32(0X802A << 16);
    // 0x800B14EC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800B14F0: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800B14F4: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x800B14F8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800B14FC: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800B1500: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B1504: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x800B1508: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B150C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800B1510: lh          $a0, 0x5A50($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X5A50));
    // 0x800B1514: sh          $a1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r5;
    // 0x800B1518: jal         0x8009A8A4
    // 0x800B151C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    ceilingglass(rdram, ctx);
        goto after_0;
    // 0x800B151C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_0:
    // 0x800B1520: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800B1524: lh          $t7, -0x53DC($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X53DC));
    // 0x800B1528: lui         $a1, 0x802A
    ctx->r5 = S32(0X802A << 16);
    // 0x800B152C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x800B1530: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B1534: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B1538: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B153C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B1540: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B1544: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B1548: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B154C: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800B1550: jal         0x80059034
    // 0x800B1554: lh          $a1, 0x5A50($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X5A50));
    spritesound(rdram, ctx);
        goto after_1;
    // 0x800B1554: lh          $a1, 0x5A50($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X5A50));
    after_1:
    // 0x800B1558: lw          $t5, 0x18($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800B155C: addiu       $at, $zero, 0x2BF
    ctx->r1 = ADD32(0, 0X2BF);
    // 0x800B1560: addiu       $t9, $zero, 0x2C0
    ctx->r25 = ADD32(0, 0X2C0);
    // 0x800B1564: lh          $v1, 0x10($t5)
    ctx->r3 = S32(MEM_H(ctx->r13, 0X10));
    // 0x800B1568: addiu       $t6, $zero, 0x2C2
    ctx->r14 = ADD32(0, 0X2C2);
    // 0x800B156C: addiu       $t7, $zero, 0x2BE
    ctx->r15 = ADD32(0, 0X2BE);
    // 0x800B1570: bne         $v1, $at, L_800B1580
    if (ctx->r3 != ctx->r1) {
        // 0x800B1574: addiu       $t8, $zero, 0x7D
        ctx->r24 = ADD32(0, 0X7D);
            goto L_800B1580;
    }
    // 0x800B1574: addiu       $t8, $zero, 0x7D
    ctx->r24 = ADD32(0, 0X7D);
    // 0x800B1578: sh          $t9, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r25;
    // 0x800B157C: lh          $v1, 0x10($t5)
    ctx->r3 = S32(MEM_H(ctx->r13, 0X10));
L_800B1580:
    // 0x800B1580: addiu       $at, $zero, 0x2C1
    ctx->r1 = ADD32(0, 0X2C1);
    // 0x800B1584: bne         $v1, $at, L_800B1594
    if (ctx->r3 != ctx->r1) {
        // 0x800B1588: addiu       $t9, $zero, 0x79
        ctx->r25 = ADD32(0, 0X79);
            goto L_800B1594;
    }
    // 0x800B1588: addiu       $t9, $zero, 0x79
    ctx->r25 = ADD32(0, 0X79);
    // 0x800B158C: sh          $t6, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r14;
    // 0x800B1590: lh          $v1, 0x10($t5)
    ctx->r3 = S32(MEM_H(ctx->r13, 0X10));
L_800B1594:
    // 0x800B1594: addiu       $at, $zero, 0x2BD
    ctx->r1 = ADD32(0, 0X2BD);
    // 0x800B1598: bne         $v1, $at, L_800B15A8
    if (ctx->r3 != ctx->r1) {
        // 0x800B159C: addiu       $t6, $zero, 0x7B
        ctx->r14 = ADD32(0, 0X7B);
            goto L_800B15A8;
    }
    // 0x800B159C: addiu       $t6, $zero, 0x7B
    ctx->r14 = ADD32(0, 0X7B);
    // 0x800B15A0: sh          $t7, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r15;
    // 0x800B15A4: lh          $v1, 0x10($t5)
    ctx->r3 = S32(MEM_H(ctx->r13, 0X10));
L_800B15A8:
    // 0x800B15A8: addiu       $at, $zero, 0x7C
    ctx->r1 = ADD32(0, 0X7C);
    // 0x800B15AC: bnel        $v1, $at, L_800B15C0
    if (ctx->r3 != ctx->r1) {
        // 0x800B15B0: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_800B15C0;
    }
    goto skip_0;
    // 0x800B15B0: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    skip_0:
    // 0x800B15B4: sh          $t8, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r24;
    // 0x800B15B8: lh          $v1, 0x10($t5)
    ctx->r3 = S32(MEM_H(ctx->r13, 0X10));
    // 0x800B15BC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
L_800B15C0:
    // 0x800B15C0: bnel        $v1, $at, L_800B15D4
    if (ctx->r3 != ctx->r1) {
        // 0x800B15C4: addiu       $at, $zero, 0x7A
        ctx->r1 = ADD32(0, 0X7A);
            goto L_800B15D4;
    }
    goto skip_1;
    // 0x800B15C4: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
    skip_1:
    // 0x800B15C8: sh          $t9, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r25;
    // 0x800B15CC: lh          $v1, 0x10($t5)
    ctx->r3 = S32(MEM_H(ctx->r13, 0X10));
    // 0x800B15D0: addiu       $at, $zero, 0x7A
    ctx->r1 = ADD32(0, 0X7A);
L_800B15D4:
    // 0x800B15D4: bnel        $v1, $at, L_800B15E4
    if (ctx->r3 != ctx->r1) {
        // 0x800B15D8: lh          $t7, 0x1A($t5)
        ctx->r15 = S32(MEM_H(ctx->r13, 0X1A));
            goto L_800B15E4;
    }
    goto skip_2;
    // 0x800B15D8: lh          $t7, 0x1A($t5)
    ctx->r15 = S32(MEM_H(ctx->r13, 0X1A));
    skip_2:
    // 0x800B15DC: sh          $t6, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r14;
    // 0x800B15E0: lh          $t7, 0x1A($t5)
    ctx->r15 = S32(MEM_H(ctx->r13, 0X1A));
L_800B15E4:
    // 0x800B15E4: lh          $t8, 0x32($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X32));
    // 0x800B15E8: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x800B15EC: bne         $t7, $zero, L_800B16BC
    if (ctx->r15 != 0) {
        // 0x800B15F0: sll         $t9, $t8, 1
        ctx->r25 = S32(ctx->r24 << 1);
            goto L_800B16BC;
    }
    // 0x800B15F0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B15F4: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800B15F8: lh          $a0, 0x2330($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2330));
    // 0x800B15FC: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B1600: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B1604: bltz        $a0, L_800B16BC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B1608: addiu       $t1, $zero, 0x2C
        ctx->r9 = ADD32(0, 0X2C);
            goto L_800B16BC;
    }
    // 0x800B1608: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B160C: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x800B1610: addiu       $a1, $a1, 0x4FA0
    ctx->r5 = ADD32(ctx->r5, 0X4FA0);
    // 0x800B1614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B1618: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_800B161C:
    // 0x800B161C: multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1620: mflo        $t6
    ctx->r14 = lo;
    // 0x800B1624: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x800B1628: lh          $t7, 0xE($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0XE));
    // 0x800B162C: bnel        $a3, $t7, L_800B16AC
    if (ctx->r7 != ctx->r15) {
        // 0x800B1630: sll         $t8, $a0, 1
        ctx->r24 = S32(ctx->r4 << 1);
            goto L_800B16AC;
    }
    goto skip_3;
    // 0x800B1630: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    skip_3:
    // 0x800B1634: lh          $t8, 0x1E($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800B1638: bnel        $v0, $t8, L_800B16AC
    if (ctx->r2 != ctx->r24) {
        // 0x800B163C: sll         $t8, $a0, 1
        ctx->r24 = S32(ctx->r4 << 1);
            goto L_800B16AC;
    }
    goto skip_4;
    // 0x800B163C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    skip_4:
    // 0x800B1640: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800B1644: lh          $v0, 0x285E($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X285E));
    // 0x800B1648: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x800B164C: addiu       $t4, $t4, 0x5F40
    ctx->r12 = ADD32(ctx->r12, 0X5F40);
    // 0x800B1650: bltz        $v0, L_800B16A0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B1654: addiu       $t3, $zero, 0x48
        ctx->r11 = ADD32(0, 0X48);
            goto L_800B16A0;
    }
    // 0x800B1654: addiu       $t3, $zero, 0x48
    ctx->r11 = ADD32(0, 0X48);
    // 0x800B1658: lui         $t2, 0x8028
    ctx->r10 = S32(0X8028 << 16);
    // 0x800B165C: addiu       $t2, $t2, -0x5C00
    ctx->r10 = ADD32(ctx->r10, -0X5C00);
    // 0x800B1660: lh          $a0, 0x20($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X20));
L_800B1664:
    // 0x800B1664: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1668: mflo        $t9
    ctx->r25 = lo;
    // 0x800B166C: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x800B1670: lh          $t7, 0x20($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X20));
    // 0x800B1674: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800B1678: bnel        $t7, $a0, L_800B1694
    if (ctx->r15 != ctx->r4) {
        // 0x800B167C: addu        $t7, $t4, $t6
        ctx->r15 = ADD32(ctx->r12, ctx->r14);
            goto L_800B1694;
    }
    goto skip_5;
    // 0x800B167C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    skip_5:
    // 0x800B1680: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1684: mflo        $t8
    ctx->r24 = lo;
    // 0x800B1688: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x800B168C: sw          $a3, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r7;
    // 0x800B1690: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
L_800B1694:
    // 0x800B1694: lh          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800B1698: bgez        $v0, L_800B1664
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B169C: nop
    
            goto L_800B1664;
    }
    // 0x800B169C: nop

L_800B16A0:
    // 0x800B16A0: b           L_800B16BC
    // 0x800B16A4: nop

        goto L_800B16BC;
    // 0x800B16A4: nop

    // 0x800B16A8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
L_800B16AC:
    // 0x800B16AC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800B16B0: lh          $a0, 0x0($t9)
    ctx->r4 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B16B4: bgez        $a0, L_800B161C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800B16B8: nop
    
            goto L_800B161C;
    }
    // 0x800B16B8: nop

L_800B16BC:
    // 0x800B16BC: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x800B16C0: lh          $a0, 0x285E($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X285E));
    // 0x800B16C4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800B16C8: jal         0x8009800C
    // 0x800B16CC: sh          $a0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r4;
    krand2(rdram, ctx);
        goto after_2;
    // 0x800B16CC: sh          $a0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r4;
    after_2:
    // 0x800B16D0: lh          $a0, 0x2E($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X2E));
    // 0x800B16D4: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B16D8: lui         $t2, 0x8028
    ctx->r10 = S32(0X8028 << 16);
    // 0x800B16DC: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x800B16E0: addiu       $t4, $t4, 0x5F40
    ctx->r12 = ADD32(ctx->r12, 0X5F40);
    // 0x800B16E4: addiu       $t2, $t2, -0x5C00
    ctx->r10 = ADD32(ctx->r10, -0X5C00);
    // 0x800B16E8: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B16EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B16F0: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B16F4: addiu       $t3, $zero, 0x48
    ctx->r11 = ADD32(0, 0X48);
    // 0x800B16F8: bltz        $a0, L_800B1760
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B16FC: lw          $t5, 0x18($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X18));
            goto L_800B1760;
    }
    // 0x800B16FC: lw          $t5, 0x18($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800B1700: lh          $a1, 0x1A($t5)
    ctx->r5 = S32(MEM_H(ctx->r13, 0X1A));
    // 0x800B1704: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_800B1708:
    // 0x800B1708: multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B170C: mflo        $t6
    ctx->r14 = lo;
    // 0x800B1710: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x800B1714: lh          $t7, 0x20($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X20));
    // 0x800B1718: bnel        $t7, $a1, L_800B1750
    if (ctx->r15 != ctx->r5) {
        // 0x800B171C: sll         $t9, $a0, 1
        ctx->r25 = S32(ctx->r4 << 1);
            goto L_800B1750;
    }
    goto skip_6;
    // 0x800B171C: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    skip_6:
    // 0x800B1720: lh          $t8, 0x1E($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800B1724: bnel        $a2, $t8, L_800B1750
    if (ctx->r6 != ctx->r24) {
        // 0x800B1728: sll         $t9, $a0, 1
        ctx->r25 = S32(ctx->r4 << 1);
            goto L_800B1750;
    }
    goto skip_7;
    // 0x800B1728: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    skip_7:
    // 0x800B172C: multu       $a0, $t3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1730: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800B1734: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800B1738: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800B173C: mflo        $t9
    ctx->r25 = lo;
    // 0x800B1740: addu        $v1, $t2, $t9
    ctx->r3 = ADD32(ctx->r10, ctx->r25);
    // 0x800B1744: sw          $t8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r24;
    // 0x800B1748: sw          $a3, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r7;
    // 0x800B174C: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
L_800B1750:
    // 0x800B1750: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x800B1754: lh          $a0, 0x0($t6)
    ctx->r4 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800B1758: bgez        $a0, L_800B1708
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800B175C: nop
    
            goto L_800B1708;
    }
    // 0x800B175C: nop

L_800B1760:
    // 0x800B1760: b           L_800B176C
    // 0x800B1764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B176C;
    // 0x800B1764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B1768:
    // 0x800B1768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B176C:
    // 0x800B176C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800B1770: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B1774: jr          $ra
    // 0x800B1778: nop

    return;
    // 0x800B1778: nop

;}
RECOMP_FUNC void animateknuckles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072DCC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80072DD0: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80072DD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072DD8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80072DDC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80072DE0: addiu       $t7, $t7, -0x17E8
    ctx->r15 = ADD32(ctx->r15, -0X17E8);
    // 0x80072DE4: lw          $at, 0x0($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X0));
    // 0x80072DE8: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80072DEC: lw          $t1, 0x4($t7)
    ctx->r9 = S32(MEM_W(ctx->r15, 0X4));
    // 0x80072DF0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80072DF4: lw          $at, 0x8($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X8));
    // 0x80072DF8: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80072DFC: lw          $t1, 0xC($t7)
    ctx->r9 = S32(MEM_W(ctx->r15, 0XC));
    // 0x80072E00: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80072E04: lw          $at, 0x10($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X10));
    // 0x80072E08: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80072E0C: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x80072E10: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80072E14: lhu         $at, 0x14($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X14);
    // 0x80072E18: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x80072E1C: sh          $at, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r1;
    // 0x80072E20: lh          $t2, 0x4E($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X4E));
    // 0x80072E24: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80072E28: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80072E2C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80072E30: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80072E34: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80072E38: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80072E3C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80072E40: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80072E44: lbu         $t5, 0x361($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X361);
    // 0x80072E48: beq         $t5, $zero, L_80072E7C
    if (ctx->r13 == 0) {
        // 0x80072E4C: nop
    
            goto L_80072E7C;
    }
    // 0x80072E4C: nop

    // 0x80072E50: lh          $t9, 0x2E0($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X2E0));
    // 0x80072E54: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80072E58: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80072E5C: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80072E60: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80072E64: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80072E68: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80072E6C: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80072E70: lh          $t6, 0x6BCA($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X6BCA));
    // 0x80072E74: bgtzl       $t6, L_80072E88
    if (SIGNED(ctx->r14) > 0) {
        // 0x80072E78: lh          $a0, 0x28A($v1)
        ctx->r4 = S32(MEM_H(ctx->r3, 0X28A));
            goto L_80072E88;
    }
    goto skip_0;
    // 0x80072E78: lh          $a0, 0x28A($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X28A));
    skip_0:
L_80072E7C:
    // 0x80072E7C: b           L_80072F68
    // 0x80072E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80072F68;
    // 0x80072E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80072E84: lh          $a0, 0x28A($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X28A));
L_80072E88:
    // 0x80072E88: jal         0x80091A38
    // 0x80072E8C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    klabs(rdram, ctx);
        goto after_0;
    // 0x80072E8C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80072E90: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80072E94: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80072E98: lw          $v1, 0x28($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80072E9C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80072EA0: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x80072EA4: lh          $t8, 0x288($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X288));
    // 0x80072EA8: lbu         $t3, 0x364($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X364);
    // 0x80072EAC: mflo        $t2
    ctx->r10 = lo;
    // 0x80072EB0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80072EB4: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80072EB8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80072EBC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80072EC0: lh          $t1, 0x18($a0)
    ctx->r9 = S32(MEM_H(ctx->r4, 0X18));
    // 0x80072EC4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80072EC8: subu        $t0, $t2, $t4
    ctx->r8 = SUB32(ctx->r10, ctx->r12);
    // 0x80072ECC: sll         $t5, $t0, 16
    ctx->r13 = S32(ctx->r8 << 16);
    // 0x80072ED0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80072ED4: bne         $t1, $at, L_80072EE4
    if (ctx->r9 != ctx->r1) {
        // 0x80072ED8: sra         $t0, $t5, 16
        ctx->r8 = S32(SIGNED(ctx->r13) >> 16);
            goto L_80072EE4;
    }
    // 0x80072ED8: sra         $t0, $t5, 16
    ctx->r8 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80072EDC: b           L_80072EE8
    // 0x80072EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80072EE8;
    // 0x80072EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072EE4:
    // 0x80072EE4: lbu         $v0, 0x27($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X27);
L_80072EE8:
    // 0x80072EE8: lh          $t3, 0x4E($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X4E));
    // 0x80072EEC: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x80072EF0: lh          $t9, 0x28A($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X28A));
    // 0x80072EF4: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80072EF8: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80072EFC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80072F00: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80072F04: lb          $t4, 0x5600($t4)
    ctx->r12 = S32(MEM_B(ctx->r12, 0X5600));
    // 0x80072F08: lbu         $t2, 0x361($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X361);
    // 0x80072F0C: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80072F10: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x80072F14: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80072F18: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x80072F1C: lw          $t6, 0x220($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X220));
    // 0x80072F20: lh          $t7, 0x2B8($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X2B8));
    // 0x80072F24: addu        $a2, $sp, $t9
    ctx->r6 = ADD32(ctx->r29, ctx->r25);
    // 0x80072F28: lh          $a2, 0x30($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X30));
    // 0x80072F2C: subu        $t1, $t6, $t7
    ctx->r9 = SUB32(ctx->r14, ctx->r15);
    // 0x80072F30: sra         $t3, $t1, 4
    ctx->r11 = S32(SIGNED(ctx->r9) >> 4);
    // 0x80072F34: subu        $a0, $t5, $t8
    ctx->r4 = SUB32(ctx->r13, ctx->r24);
    // 0x80072F38: addiu       $a2, $a2, 0x914
    ctx->r6 = ADD32(ctx->r6, 0X914);
    // 0x80072F3C: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x80072F40: subu        $a1, $t0, $t3
    ctx->r5 = SUB32(ctx->r8, ctx->r11);
    // 0x80072F44: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80072F48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80072F4C: addiu       $a1, $a1, 0xB4
    ctx->r5 = ADD32(ctx->r5, 0XB4);
    // 0x80072F50: sra         $a2, $t5, 16
    ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80072F54: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    // 0x80072F58: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80072F5C: jal         0x800724B0
    // 0x80072F60: lb          $a3, 0x4B($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0X4B));
    myospal(rdram, ctx);
        goto after_1;
    // 0x80072F60: lb          $a3, 0x4B($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0X4B));
    after_1:
    // 0x80072F64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80072F68:
    // 0x80072F68: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80072F6C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80072F70: jr          $ra
    // 0x80072F74: nop

    return;
    // 0x80072F74: nop

;}
RECOMP_FUNC void dmulscale26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090CD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090CDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090CE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090CE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090CE8: jal         0x800BB8F8
    // 0x80090CEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090CEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090CF0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090CF4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090CF8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090CFC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090D00: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090D04: jal         0x800BB8F8
    // 0x80090D08: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090D08: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090D0C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090D10: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090D14: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090D18: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090D1C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090D20: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090D24: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090D28: jal         0x800BBA24
    // 0x80090D2C: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090D2C: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_2:
    // 0x80090D30: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090D34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090D38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090D3C: jr          $ra
    // 0x80090D40: nop

    return;
    // 0x80090D40: nop

;}
RECOMP_FUNC void viswallcheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059CE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80059CEC: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80059CF0: lw          $v0, -0x523C($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X523C));
    // 0x80059CF4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80059CF8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80059CFC: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x80059D00: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80059D04: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80059D08: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80059D0C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80059D10: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80059D14: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80059D18: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80059D1C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80059D20: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80059D24: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80059D28: blez        $v0, L_80059DB8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80059D2C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80059DB8;
    }
    // 0x80059D2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80059D30: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x80059D34: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x80059D38: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x80059D3C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80059D40: addiu       $s3, $s3, -0x5238
    ctx->r19 = ADD32(ctx->r19, -0X5238);
    // 0x80059D44: addiu       $s4, $s4, -0x4A38
    ctx->r20 = ADD32(ctx->r20, -0X4A38);
    // 0x80059D48: addiu       $s1, $s1, -0x4238
    ctx->r17 = ADD32(ctx->r17, -0X4238);
L_80059D4C:
    // 0x80059D4C: lhu         $t6, 0x0($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X0);
    // 0x80059D50: sll         $s0, $s2, 2
    ctx->r16 = S32(ctx->r18 << 2);
    // 0x80059D54: addu        $t7, $s3, $s0
    ctx->r15 = ADD32(ctx->r19, ctx->r16);
    // 0x80059D58: bnel        $s5, $t6, L_80059DAC
    if (ctx->r21 != ctx->r14) {
        // 0x80059D5C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80059DAC;
    }
    goto skip_0;
    // 0x80059D5C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80059D60: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80059D64: jal         0x80059554
    // 0x80059D68: lwc1        $f14, 0x0($t7)
    ctx->f14.u32l = S32(MEM_W(ctx->r15, 0X0));
    getangledelta(rdram, ctx);
        goto after_0;
    // 0x80059D68: lwc1        $f14, 0x0($t7)
    ctx->f14.u32l = S32(MEM_W(ctx->r15, 0X0));
    after_0:
    // 0x80059D6C: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80059D70: addu        $t8, $s4, $s0
    ctx->r24 = ADD32(ctx->r20, ctx->r16);
    // 0x80059D74: bc1f        L_80059DA0
    if (!c1cs) {
        // 0x80059D78: nop
    
            goto L_80059DA0;
    }
    // 0x80059D78: nop

    // 0x80059D7C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80059D80: jal         0x80059554
    // 0x80059D84: lwc1        $f14, 0x0($t8)
    ctx->f14.u32l = S32(MEM_W(ctx->r24, 0X0));
    getangledelta(rdram, ctx);
        goto after_1;
    // 0x80059D84: lwc1        $f14, 0x0($t8)
    ctx->f14.u32l = S32(MEM_W(ctx->r24, 0X0));
    after_1:
    // 0x80059D88: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80059D8C: nop

    // 0x80059D90: bc1f        L_80059DA0
    if (!c1cs) {
        // 0x80059D94: nop
    
            goto L_80059DA0;
    }
    // 0x80059D94: nop

    // 0x80059D98: b           L_80059DBC
    // 0x80059D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059DBC;
    // 0x80059D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059DA0:
    // 0x80059DA0: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80059DA4: lw          $v0, -0x523C($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X523C));
    // 0x80059DA8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80059DAC:
    // 0x80059DAC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80059DB0: bne         $at, $zero, L_80059D4C
    if (ctx->r1 != 0) {
        // 0x80059DB4: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_80059D4C;
    }
    // 0x80059DB4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80059DB8:
    // 0x80059DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059DBC:
    // 0x80059DBC: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80059DC0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80059DC4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80059DC8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80059DCC: lw          $s0, 0x2C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80059DD0: lw          $s1, 0x30($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80059DD4: lw          $s2, 0x34($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80059DD8: lw          $s3, 0x38($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80059DDC: lw          $s4, 0x3C($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80059DE0: lw          $s5, 0x40($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80059DE4: jr          $ra
    // 0x80059DE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80059DE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alEnvmixerPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDE9C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800CDEA0: lw          $t6, 0xB8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800CDEA4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800CDEA8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800CDEAC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800CDEB0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800CDEB4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800CDEB8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800CDEBC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800CDEC0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800CDEC4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800CDEC8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800CDECC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800CDED0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800CDED4: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800CDED8: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800CDEDC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800CDEE0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800CDEE4: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x800CDEE8: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800CDEEC: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800CDEF0: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x800CDEF4: lw          $t8, 0x3C($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X3C));
    // 0x800CDEF8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800CDEFC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800CDF00: beql        $t8, $zero, L_800CE374
    if (ctx->r24 == 0) {
        // 0x800CDF04: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_800CE374;
    }
    goto skip_0;
    // 0x800CDF04: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    skip_0:
    // 0x800CDF08: lw          $v1, 0x3C($fp)
    ctx->r3 = S32(MEM_W(ctx->r30, 0X3C));
L_800CDF0C:
    // 0x800CDF0C: lw          $v0, 0x94($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800CDF10: lw          $t8, 0xB0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800CDF14: lw          $t9, 0x4($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800CDF18: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x800CDF1C: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CDF20: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x800CDF24: bne         $at, $zero, L_800CE370
    if (ctx->r1 != 0) {
        // 0x800CDF28: sw          $t9, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r25;
            goto L_800CE370;
    }
    // 0x800CDF28: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800CDF2C: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x800CDF30: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x800CDF34: beq         $at, $zero, L_800CE2E8
    if (ctx->r1 == 0) {
        // 0x800CDF38: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800CE2E8;
    }
    // 0x800CDF38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800CDF3C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CDF40: addu        $at, $at, $t9
    gpr jr_addend_800CDF48 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800CDF44: lw          $t9, -0x5F40($at)
    ctx->r25 = ADD32(ctx->r1, -0X5F40);
    // 0x800CDF48: jr          $t9
    // 0x800CDF4C: nop

    switch (jr_addend_800CDF48 >> 2) {
        case 0: goto L_800CE2C8; break;
        case 1: goto L_800CE2E8; break;
        case 2: goto L_800CE2E8; break;
        case 3: goto L_800CE2E8; break;
        case 4: goto L_800CE2E8; break;
        case 5: goto L_800CE2E8; break;
        case 6: goto L_800CE2E8; break;
        case 7: goto L_800CE2E8; break;
        case 8: goto L_800CE2E8; break;
        case 9: goto L_800CE2E8; break;
        case 10: goto L_800CE2E8; break;
        case 11: goto L_800CE090; break;
        case 12: goto L_800CE090; break;
        case 13: goto L_800CDF50; break;
        case 14: goto L_800CE234; break;
        case 15: goto L_800CE288; break;
        case 16: goto L_800CE090; break;
        default: switch_error(__func__, 0x800CDF48, 0x8010A0C0);
    }
    // 0x800CDF4C: nop

L_800CDF50:
    // 0x800CDF50: lh          $t6, 0xA($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0XA));
    // 0x800CDF54: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800CDF58: beql        $t6, $zero, L_800CDF78
    if (ctx->r14 == 0) {
        // 0x800CDF5C: lw          $t9, 0x8($fp)
        ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
            goto L_800CDF78;
    }
    goto skip_1;
    // 0x800CDF5C: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
    skip_1:
    // 0x800CDF60: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800CDF64: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800CDF68: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800CDF6C: jalr        $t9
    // 0x800CDF70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CDF70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800CDF74: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
L_800CDF78:
    // 0x800CDF78: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800CDF7C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800CDF80: jalr        $t9
    // 0x800CDF84: lw          $a2, 0x18($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X18));
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CDF84: lw          $a2, 0x18($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X18));
    after_1:
    // 0x800CDF88: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800CDF8C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800CDF90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CDF94: jalr        $t9
    // 0x800CDF98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CDF98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800CDF9C: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
    // 0x800CDFA0: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800CDFA4: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CDFA8: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800CDFAC: lh          $v1, 0x10($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800CDFB0: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CDFB4: mflo        $a0
    ctx->r4 = lo;
    // 0x800CDFB8: sra         $t7, $a0, 15
    ctx->r15 = S32(SIGNED(ctx->r4) >> 15);
    // 0x800CDFBC: sh          $t7, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r15;
    // 0x800CDFC0: lbu         $t6, 0x12($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X12);
    // 0x800CDFC4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800CDFC8: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800CDFCC: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x800CDFD0: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800CDFD4: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800CDFD8: lh          $t7, 0x2420($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X2420));
    // 0x800CDFDC: sh          $t7, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r15;
    // 0x800CDFE0: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x800CDFE4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800CDFE8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800CDFEC: negu        $t8, $t9
    ctx->r24 = SUB32(0, ctx->r25);
    // 0x800CDFF0: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800CDFF4: lh          $t7, 0x251E($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X251E));
    // 0x800CDFF8: sh          $t7, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r15;
    // 0x800CDFFC: lw          $t6, 0x14($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CE000: beql        $t6, $zero, L_800CE018
    if (ctx->r14 == 0) {
        // 0x800CE004: lh          $v0, 0x18($fp)
        ctx->r2 = S32(MEM_H(ctx->r30, 0X18));
            goto L_800CE018;
    }
    goto skip_2;
    // 0x800CE004: lh          $v0, 0x18($fp)
    ctx->r2 = S32(MEM_H(ctx->r30, 0X18));
    skip_2:
    // 0x800CE008: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800CE00C: b           L_800CE05C
    // 0x800CE010: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
        goto L_800CE05C;
    // 0x800CE010: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800CE014: lh          $v0, 0x18($fp)
    ctx->r2 = S32(MEM_H(ctx->r30, 0X18));
L_800CE018:
    // 0x800CE018: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800CE01C: lh          $v1, 0x1A($fp)
    ctx->r3 = S32(MEM_H(ctx->r30, 0X1A));
    // 0x800CE020: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800CE024: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800CE028: lh          $t8, 0x2420($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X2420));
    // 0x800CE02C: negu        $t9, $t9
    ctx->r25 = SUB32(0, ctx->r25);
    // 0x800CE030: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CE034: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800CE038: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800CE03C: mflo        $t7
    ctx->r15 = lo;
    // 0x800CE040: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800CE044: sh          $t6, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r14;
    // 0x800CE048: lh          $t8, 0x251E($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X251E));
    // 0x800CE04C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CE050: mflo        $t7
    ctx->r15 = lo;
    // 0x800CE054: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800CE058: sh          $t6, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r14;
L_800CE05C:
    // 0x800CE05C: lw          $t9, 0x0($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X0));
    // 0x800CE060: beql        $t9, $zero, L_800CE328
    if (ctx->r25 == 0) {
        // 0x800CE064: lw          $t8, 0x60($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
            goto L_800CE328;
    }
    goto skip_3;
    // 0x800CE064: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
    skip_3:
    // 0x800CE068: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = S32(MEM_W(ctx->r16, 0XC));
    // 0x800CE06C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800CE070: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800CE074: lw          $a0, 0x0($fp)
    ctx->r4 = S32(MEM_W(ctx->r30, 0X0));
    // 0x800CE078: lw          $a2, 0x74($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X74));
    // 0x800CE07C: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CE080: jalr        $t9
    // 0x800CE084: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800CE084: nop

    after_3:
    // 0x800CE088: b           L_800CE328
    // 0x800CE08C: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
        goto L_800CE328;
    // 0x800CE08C: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
L_800CE090:
    // 0x800CE090: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800CE094: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800CE098: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800CE09C: lw          $s5, 0x60($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800CE0A0: lw          $a3, 0xB4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800CE0A4: jal         0x800CDB54
    // 0x800CE0A8: lw          $t0, 0xA4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA4));
    static_5_800CDB54(rdram, ctx);
        goto after_4;
    // 0x800CE0A8: lw          $t0, 0xA4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA4));
    after_4:
    // 0x800CE0AC: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800CE0B0: lw          $a0, 0x34($fp)
    ctx->r4 = S32(MEM_W(ctx->r30, 0X34));
    // 0x800CE0B4: lw          $a3, 0x30($fp)
    ctx->r7 = S32(MEM_W(ctx->r30, 0X30));
    // 0x800CE0B8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800CE0BC: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CE0C0: bnel        $at, $zero, L_800CE12C
    if (ctx->r1 != 0) {
        // 0x800CE0C4: lh          $t6, 0x1C($fp)
        ctx->r14 = S32(MEM_H(ctx->r30, 0X1C));
            goto L_800CE12C;
    }
    goto skip_4;
    // 0x800CE0C4: lh          $t6, 0x1C($fp)
    ctx->r14 = S32(MEM_H(ctx->r30, 0X1C));
    skip_4:
    // 0x800CE0C8: lh          $v0, 0x18($fp)
    ctx->r2 = S32(MEM_H(ctx->r30, 0X18));
    // 0x800CE0CC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800CE0D0: lh          $v1, 0x1A($fp)
    ctx->r3 = S32(MEM_H(ctx->r30, 0X1A));
    // 0x800CE0D4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800CE0D8: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800CE0DC: lh          $t7, 0x2420($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X2420));
    // 0x800CE0E0: negu        $t8, $t8
    ctx->r24 = SUB32(0, ctx->r24);
    // 0x800CE0E4: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CE0E8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800CE0EC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800CE0F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800CE0F4: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800CE0F8: sh          $t9, 0x28($fp)
    MEM_H(0X28, ctx->r30) = ctx->r25;
    // 0x800CE0FC: lh          $t7, 0x251E($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X251E));
    // 0x800CE100: lh          $t8, 0x28($fp)
    ctx->r24 = S32(MEM_H(ctx->r30, 0X28));
    // 0x800CE104: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800CE108: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CE10C: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800CE110: mflo        $t6
    ctx->r14 = lo;
    // 0x800CE114: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800CE118: sh          $t9, 0x2E($fp)
    MEM_H(0X2E, ctx->r30) = ctx->r25;
    // 0x800CE11C: lh          $t7, 0x2E($fp)
    ctx->r15 = S32(MEM_H(ctx->r30, 0X2E));
    // 0x800CE120: b           L_800CE17C
    // 0x800CE124: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
        goto L_800CE17C;
    // 0x800CE124: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
    // 0x800CE128: lh          $t6, 0x1C($fp)
    ctx->r14 = S32(MEM_H(ctx->r30, 0X1C));
L_800CE12C:
    // 0x800CE12C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800CE130: lh          $a1, 0x26($fp)
    ctx->r5 = S32(MEM_H(ctx->r30, 0X26));
    // 0x800CE134: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800CE138: lhu         $a2, 0x24($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X24);
    // 0x800CE13C: jal         0x800CDDEC
    // 0x800CE140: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    static_5_800CDDEC(rdram, ctx);
        goto after_5;
    // 0x800CE140: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x800CE144: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800CE148: lh          $t7, 0x1E($fp)
    ctx->r15 = S32(MEM_H(ctx->r30, 0X1E));
    // 0x800CE14C: lw          $a0, 0x30($fp)
    ctx->r4 = S32(MEM_W(ctx->r30, 0X30));
    // 0x800CE150: lh          $a1, 0x2C($fp)
    ctx->r5 = S32(MEM_H(ctx->r30, 0X2C));
    // 0x800CE154: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800CE158: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CE15C: lhu         $a2, 0x2A($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X2A);
    // 0x800CE160: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800CE164: jal         0x800CDDEC
    // 0x800CE168: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    static_5_800CDDEC(rdram, ctx);
        goto after_6;
    // 0x800CE168: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_6:
    // 0x800CE16C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800CE170: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800CE174: nop

    // 0x800CE178: sh          $t9, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r25;
L_800CE17C:
    // 0x800CE17C: lh          $t8, 0x1C($fp)
    ctx->r24 = S32(MEM_H(ctx->r30, 0X1C));
    // 0x800CE180: bnel        $t8, $zero, L_800CE190
    if (ctx->r24 != 0) {
        // 0x800CE184: lh          $t7, 0x1E($fp)
        ctx->r15 = S32(MEM_H(ctx->r30, 0X1E));
            goto L_800CE190;
    }
    goto skip_5;
    // 0x800CE184: lh          $t7, 0x1E($fp)
    ctx->r15 = S32(MEM_H(ctx->r30, 0X1E));
    skip_5:
    // 0x800CE188: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800CE18C: lh          $t7, 0x1E($fp)
    ctx->r15 = S32(MEM_H(ctx->r30, 0X1E));
L_800CE190:
    // 0x800CE190: bnel        $t7, $zero, L_800CE1A0
    if (ctx->r15 != 0) {
        // 0x800CE194: lw          $v1, 0x3C($fp)
        ctx->r3 = S32(MEM_W(ctx->r30, 0X3C));
            goto L_800CE1A0;
    }
    goto skip_6;
    // 0x800CE194: lw          $v1, 0x3C($fp)
    ctx->r3 = S32(MEM_W(ctx->r30, 0X3C));
    skip_6:
    // 0x800CE198: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800CE19C: lw          $v1, 0x3C($fp)
    ctx->r3 = S32(MEM_W(ctx->r30, 0X3C));
L_800CE1A0:
    // 0x800CE1A0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800CE1A4: lh          $a0, 0x8($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X8));
    // 0x800CE1A8: bnel        $a0, $at, L_800CE1C0
    if (ctx->r4 != ctx->r1) {
        // 0x800CE1AC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800CE1C0;
    }
    goto skip_7;
    // 0x800CE1AC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_7:
    // 0x800CE1B0: lw          $t6, 0xC($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0XC));
    // 0x800CE1B4: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800CE1B8: lh          $a0, 0x8($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X8));
    // 0x800CE1BC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_800CE1C0:
    // 0x800CE1C0: bnel        $a0, $at, L_800CE1F0
    if (ctx->r4 != ctx->r1) {
        // 0x800CE1C4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800CE1F0;
    }
    goto skip_8;
    // 0x800CE1C4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_8:
    // 0x800CE1C8: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800CE1CC: lw          $v0, 0xC($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0XC));
    // 0x800CE1D0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CE1D4: mflo        $v0
    ctx->r2 = lo;
    // 0x800CE1D8: sra         $t9, $v0, 15
    ctx->r25 = S32(SIGNED(ctx->r2) >> 15);
    // 0x800CE1DC: sh          $t9, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r25;
    // 0x800CE1E0: lw          $t8, 0x10($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X10));
    // 0x800CE1E4: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800CE1E8: lh          $a0, 0x8($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X8));
    // 0x800CE1EC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_800CE1F0:
    // 0x800CE1F0: bne         $a0, $at, L_800CE22C
    if (ctx->r4 != ctx->r1) {
        // 0x800CE1F4: nop
    
            goto L_800CE22C;
    }
    // 0x800CE1F4: nop

    // 0x800CE1F8: lw          $t7, 0xC($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0XC));
    // 0x800CE1FC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800CE200: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800CE204: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800CE208: lh          $t9, 0x2420($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X2420));
    // 0x800CE20C: sh          $t9, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r25;
    // 0x800CE210: lw          $t8, 0xC($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0XC));
    // 0x800CE214: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800CE218: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800CE21C: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x800CE220: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800CE224: lh          $t9, 0x251E($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X251E));
    // 0x800CE228: sh          $t9, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r25;
L_800CE22C:
    // 0x800CE22C: b           L_800CE324
    // 0x800CE230: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
        goto L_800CE324;
    // 0x800CE230: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
L_800CE234:
    // 0x800CE234: lh          $t8, 0xA($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0XA));
    // 0x800CE238: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800CE23C: beql        $t8, $zero, L_800CE25C
    if (ctx->r24 == 0) {
        // 0x800CE240: lw          $t9, 0x8($fp)
        ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
            goto L_800CE25C;
    }
    goto skip_9;
    // 0x800CE240: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
    skip_9:
    // 0x800CE244: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800CE248: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800CE24C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800CE250: jalr        $t9
    // 0x800CE254: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x800CE254: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800CE258: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
L_800CE25C:
    // 0x800CE25C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800CE260: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800CE264: jalr        $t9
    // 0x800CE268: lw          $a2, 0xC($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0XC));
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800CE268: lw          $a2, 0xC($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0XC));
    after_8:
    // 0x800CE26C: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800CE270: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800CE274: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CE278: jalr        $t9
    // 0x800CE27C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800CE27C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x800CE280: b           L_800CE328
    // 0x800CE284: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
        goto L_800CE328;
    // 0x800CE284: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
L_800CE288:
    // 0x800CE288: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800CE28C: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800CE290: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800CE294: lw          $s5, 0x60($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800CE298: lw          $a3, 0xB4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800CE29C: jal         0x800CDB54
    // 0x800CE2A0: lw          $t0, 0xA4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA4));
    static_5_800CDB54(rdram, ctx);
        goto after_10;
    // 0x800CE2A0: lw          $t0, 0xA4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA4));
    after_10:
    // 0x800CE2A4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800CE2A8: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800CE2AC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800CE2B0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800CE2B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CE2B8: jalr        $t9
    // 0x800CE2BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800CE2BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800CE2C0: b           L_800CE328
    // 0x800CE2C4: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
        goto L_800CE328;
    // 0x800CE2C4: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
L_800CE2C8:
    // 0x800CE2C8: lw          $t7, 0xC($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0XC));
    // 0x800CE2CC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800CE2D0: lw          $a0, 0x2140($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X2140));
    // 0x800CE2D4: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
    // 0x800CE2D8: jal         0x800C24C0
    // 0x800CE2DC: lw          $a1, 0xC($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0XC));
    _freePVoice(rdram, ctx);
        goto after_12;
    // 0x800CE2DC: lw          $a1, 0xC($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0XC));
    after_12:
    // 0x800CE2E0: b           L_800CE328
    // 0x800CE2E4: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
        goto L_800CE328;
    // 0x800CE2E4: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
L_800CE2E8:
    // 0x800CE2E8: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800CE2EC: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800CE2F0: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800CE2F4: lw          $s5, 0x60($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800CE2F8: lw          $a3, 0xB4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800CE2FC: jal         0x800CDB54
    // 0x800CE300: lw          $t0, 0xA4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA4));
    static_5_800CDB54(rdram, ctx);
        goto after_13;
    // 0x800CE300: lw          $t0, 0xA4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA4));
    after_13:
    // 0x800CE304: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800CE308: lw          $t9, 0x8($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800CE30C: lw          $v1, 0x3C($fp)
    ctx->r3 = S32(MEM_W(ctx->r30, 0X3C));
    // 0x800CE310: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800CE314: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800CE318: lh          $a1, 0x8($v1)
    ctx->r5 = S32(MEM_H(ctx->r3, 0X8));
    // 0x800CE31C: jalr        $t9
    // 0x800CE320: lw          $a2, 0xC($v1)
    ctx->r6 = S32(MEM_W(ctx->r3, 0XC));
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x800CE320: lw          $a2, 0xC($v1)
    ctx->r6 = S32(MEM_W(ctx->r3, 0XC));
    after_14:
L_800CE324:
    // 0x800CE324: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
L_800CE328:
    // 0x800CE328: lh          $t6, 0x8E($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X8E));
    // 0x800CE32C: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800CE330: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800CE334: lw          $t6, 0xB0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800CE338: sh          $t9, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r25;
    // 0x800CE33C: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x800CE340: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800CE344: lw          $a0, 0x3C($fp)
    ctx->r4 = S32(MEM_W(ctx->r30, 0X3C));
    // 0x800CE348: lw          $t9, 0x0($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800CE34C: bne         $t9, $zero, L_800CE358
    if (ctx->r25 != 0) {
        // 0x800CE350: sw          $t9, 0x3C($fp)
        MEM_W(0X3C, ctx->r30) = ctx->r25;
            goto L_800CE358;
    }
    // 0x800CE350: sw          $t9, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r25;
    // 0x800CE354: sw          $zero, 0x40($fp)
    MEM_W(0X40, ctx->r30) = 0;
L_800CE358:
    // 0x800CE358: jal         0x800C2558
    // 0x800CE35C: nop

    __freeParam(rdram, ctx);
        goto after_15;
    // 0x800CE35C: nop

    after_15:
    // 0x800CE360: lw          $t8, 0xA0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800CE364: lw          $t7, 0x3C($t8)
    ctx->r15 = S32(MEM_W(ctx->r24, 0X3C));
    // 0x800CE368: bnel        $t7, $zero, L_800CDF0C
    if (ctx->r15 != 0) {
        // 0x800CE36C: lw          $v1, 0x3C($fp)
        ctx->r3 = S32(MEM_W(ctx->r30, 0X3C));
            goto L_800CDF0C;
    }
    goto skip_10;
    // 0x800CE36C: lw          $v1, 0x3C($fp)
    ctx->r3 = S32(MEM_W(ctx->r30, 0X3C));
    skip_10:
L_800CE370:
    // 0x800CE370: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
L_800CE374:
    // 0x800CE374: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800CE378: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800CE37C: lw          $s5, 0xB0($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800CE380: lw          $a3, 0xB4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800CE384: jal         0x800CDB54
    // 0x800CE388: lw          $t0, 0xA4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA4));
    static_5_800CDB54(rdram, ctx);
        goto after_16;
    // 0x800CE388: lw          $t0, 0xA4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA4));
    after_16:
    // 0x800CE38C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800CE390: lw          $t9, 0x30($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X30));
    // 0x800CE394: lw          $a0, 0x34($fp)
    ctx->r4 = S32(MEM_W(ctx->r30, 0X34));
    // 0x800CE398: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800CE39C: beql        $at, $zero, L_800CE3AC
    if (ctx->r1 == 0) {
        // 0x800CE3A0: lw          $ra, 0x54($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X54));
            goto L_800CE3AC;
    }
    goto skip_11;
    // 0x800CE3A0: lw          $ra, 0x54($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X54));
    skip_11:
    // 0x800CE3A4: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800CE3A8: lw          $ra, 0x54($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X54));
L_800CE3AC:
    // 0x800CE3AC: lw          $v0, 0xA4($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800CE3B0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800CE3B4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800CE3B8: lw          $s0, 0x30($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800CE3BC: lw          $s1, 0x34($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800CE3C0: lw          $s2, 0x38($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800CE3C4: lw          $s3, 0x3C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800CE3C8: lw          $s4, 0x40($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800CE3CC: lw          $s5, 0x44($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800CE3D0: lw          $s6, 0x48($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800CE3D4: lw          $s7, 0x4C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800CE3D8: lw          $fp, 0x50($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800CE3DC: jr          $ra
    // 0x800CE3E0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800CE3E0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void alSynNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2840: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800C2844: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C2848: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C284C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C2850: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C2854: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C2858: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C285C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C2860: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C2864: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C2868: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C286C: lw          $s7, 0x14($a1)
    ctx->r23 = S32(MEM_W(ctx->r5, 0X14));
    // 0x800C2870: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800C2874: lw          $t6, 0x4($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X4));
    // 0x800C2878: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800C287C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800C2880: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x800C2884: lw          $t7, 0x18($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X18));
    // 0x800C2888: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x800C288C: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800C2890: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x800C2894: lw          $t9, 0x10($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X10));
    // 0x800C2898: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800C289C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800C28A0: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800C28A4: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x800C28A8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C28AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C28B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C28B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C28B8: jal         0x800BF830
    // 0x800C28BC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800C28BC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x800C28C0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800C28C4: jal         0x800CBFB0
    // 0x800C28C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    alSaveNew(rdram, ctx);
        goto after_1;
    // 0x800C28C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800C28CC: lw          $t1, 0x5C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800C28D0: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x800C28D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C28D8: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x800C28DC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C28E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C28E4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800C28E8: jal         0x800BF830
    // 0x800C28EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800C28EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800C28F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C28F4: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x800C28F8: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x800C28FC: lw          $a3, 0x4($fp)
    ctx->r7 = S32(MEM_W(ctx->r30, 0X4));
    // 0x800C2900: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C2904: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C2908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C290C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C2910: jal         0x800BF830
    // 0x800C2914: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800C2914: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x800C2918: lw          $a0, 0x34($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X34));
    // 0x800C291C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C2920: jal         0x800CC048
    // 0x800C2924: lw          $a2, 0x4($fp)
    ctx->r6 = S32(MEM_W(ctx->r30, 0X4));
    alAuxBusNew(rdram, ctx);
        goto after_4;
    // 0x800C2924: lw          $a2, 0x4($fp)
    ctx->r6 = S32(MEM_W(ctx->r30, 0X4));
    after_4:
    // 0x800C2928: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800C292C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C2930: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C2934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C2938: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800C293C: jal         0x800BF830
    // 0x800C2940: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x800C2940: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800C2944: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x800C2948: lw          $a3, 0x4($fp)
    ctx->r7 = S32(MEM_W(ctx->r30, 0X4));
    // 0x800C294C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800C2950: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C2954: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C2958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C295C: jal         0x800BF830
    // 0x800C2960: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x800C2960: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x800C2964: lw          $a0, 0x30($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X30));
    // 0x800C2968: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C296C: jal         0x800CBFF4
    // 0x800C2970: lw          $a2, 0x4($fp)
    ctx->r6 = S32(MEM_W(ctx->r30, 0X4));
    alMainBusNew(rdram, ctx);
        goto after_7;
    // 0x800C2970: lw          $a2, 0x4($fp)
    ctx->r6 = S32(MEM_W(ctx->r30, 0X4));
    after_7:
    // 0x800C2974: lbu         $t7, 0x1C($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1C);
    // 0x800C2978: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800C297C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800C2980: beq         $t7, $zero, L_800C299C
    if (ctx->r15 == 0) {
        // 0x800C2984: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800C299C;
    }
    // 0x800C2984: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C2988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C298C: jal         0x800CC750
    // 0x800C2990: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    alSynAllocFX(rdram, ctx);
        goto after_8;
    // 0x800C2990: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_8:
    // 0x800C2994: b           L_800C29AC
    // 0x800C2998: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
        goto L_800C29AC;
    // 0x800C2998: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_800C299C:
    // 0x800C299C: lw          $a0, 0x30($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X30));
    // 0x800C29A0: jal         0x800CC7F0
    // 0x800C29A4: lw          $a2, 0x34($s6)
    ctx->r6 = S32(MEM_W(ctx->r22, 0X34));
    alMainBusParam(rdram, ctx);
        goto after_9;
    // 0x800C29A4: lw          $a2, 0x34($s6)
    ctx->r6 = S32(MEM_W(ctx->r22, 0X34));
    after_9:
    // 0x800C29A8: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_800C29AC:
    // 0x800C29AC: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x800C29B0: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x800C29B4: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x800C29B8: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x800C29BC: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x800C29C0: lw          $a3, 0x4($fp)
    ctx->r7 = S32(MEM_W(ctx->r30, 0X4));
    // 0x800C29C4: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x800C29C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C29CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C29D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C29D4: jal         0x800BF830
    // 0x800C29D8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x800C29D8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_10:
    // 0x800C29DC: lw          $t9, 0x4($fp)
    ctx->r25 = S32(MEM_W(ctx->r30, 0X4));
    // 0x800C29E0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C29E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C29E8: blez        $t9, L_800C2AA8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800C29EC: addiu       $a1, $s6, 0x4
        ctx->r5 = ADD32(ctx->r22, 0X4);
            goto L_800C2AA8;
    }
    // 0x800C29EC: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x800C29F0: addiu       $s1, $v0, 0x8C
    ctx->r17 = ADD32(ctx->r2, 0X8C);
    // 0x800C29F4: addiu       $s2, $v0, 0x58
    ctx->r18 = ADD32(ctx->r2, 0X58);
    // 0x800C29F8: addiu       $s3, $v0, 0x10
    ctx->r19 = ADD32(ctx->r2, 0X10);
    // 0x800C29FC: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
L_800C2A00:
    // 0x800C2A00: lw          $a1, 0x48($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800C2A04: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800C2A08: jal         0x800BF7A0
    // 0x800C2A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_11;
    // 0x800C2A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800C2A10: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800C2A14: lw          $a1, 0x24($s6)
    ctx->r5 = S32(MEM_W(ctx->r22, 0X24));
    // 0x800C2A18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C2A1C: jal         0x800CC124
    // 0x800C2A20: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alLoadNew(rdram, ctx);
        goto after_12;
    // 0x800C2A20: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x800C2A24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C2A28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C2A2C: jal         0x800CC940
    // 0x800C2A30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alLoadParam(rdram, ctx);
        goto after_13;
    // 0x800C2A30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x800C2A34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C2A38: jal         0x800CC09C
    // 0x800C2A3C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alResampleNew(rdram, ctx);
        goto after_14;
    // 0x800C2A3C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x800C2A40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C2A44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C2A48: jal         0x800CD490
    // 0x800C2A4C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alResampleParam(rdram, ctx);
        goto after_15;
    // 0x800C2A4C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x800C2A50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C2A54: jal         0x800CC1CC
    // 0x800C2A58: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alEnvmixerNew(rdram, ctx);
        goto after_16;
    // 0x800C2A58: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x800C2A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C2A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C2A64: jal         0x800CD8A4
    // 0x800C2A68: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alEnvmixerParam(rdram, ctx);
        goto after_17;
    // 0x800C2A68: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_17:
    // 0x800C2A6C: lw          $a0, 0x34($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X34));
    // 0x800C2A70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C2A74: jal         0x800CE3F0
    // 0x800C2A78: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    alAuxBusParam(rdram, ctx);
        goto after_18;
    // 0x800C2A78: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x800C2A7C: addiu       $t0, $s5, 0x8C
    ctx->r8 = ADD32(ctx->r21, 0X8C);
    // 0x800C2A80: sw          $t0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r8;
    // 0x800C2A84: lw          $t1, 0x4($fp)
    ctx->r9 = S32(MEM_W(ctx->r30, 0X4));
    // 0x800C2A88: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C2A8C: addiu       $s0, $s0, 0xDC
    ctx->r16 = ADD32(ctx->r16, 0XDC);
    // 0x800C2A90: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C2A94: addiu       $s1, $s1, 0xDC
    ctx->r17 = ADD32(ctx->r17, 0XDC);
    // 0x800C2A98: addiu       $s2, $s2, 0xDC
    ctx->r18 = ADD32(ctx->r18, 0XDC);
    // 0x800C2A9C: bne         $at, $zero, L_800C2A00
    if (ctx->r1 != 0) {
        // 0x800C2AA0: addiu       $s3, $s3, 0xDC
        ctx->r19 = ADD32(ctx->r19, 0XDC);
            goto L_800C2A00;
    }
    // 0x800C2AA0: addiu       $s3, $s3, 0xDC
    ctx->r19 = ADD32(ctx->r19, 0XDC);
    // 0x800C2AA4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800C2AA8:
    // 0x800C2AA8: lw          $a0, 0x5C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800C2AAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C2AB0: jal         0x800CE500
    // 0x800C2AB4: lw          $a2, 0x30($s6)
    ctx->r6 = S32(MEM_W(ctx->r22, 0X30));
    alSaveParam(rdram, ctx);
        goto after_19;
    // 0x800C2AB4: lw          $a2, 0x30($s6)
    ctx->r6 = S32(MEM_W(ctx->r22, 0X30));
    after_19:
    // 0x800C2AB8: lw          $a3, 0x8($fp)
    ctx->r7 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800C2ABC: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800C2AC0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C2AC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C2AC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C2ACC: jal         0x800BF830
    // 0x800C2AD0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_20;
    // 0x800C2AD0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_20:
    // 0x800C2AD4: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x800C2AD8: lw          $t3, 0x8($fp)
    ctx->r11 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800C2ADC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C2AE0: blezl       $t3, L_800C2B10
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800C2AE4: sw          $s7, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r23;
            goto L_800C2B10;
    }
    goto skip_0;
    // 0x800C2AE4: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    skip_0:
    // 0x800C2AE8: lw          $t4, 0x2C($s6)
    ctx->r12 = S32(MEM_W(ctx->r22, 0X2C));
L_800C2AEC:
    // 0x800C2AEC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C2AF0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800C2AF4: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x800C2AF8: lw          $t5, 0x8($fp)
    ctx->r13 = S32(MEM_W(ctx->r30, 0X8));
    // 0x800C2AFC: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800C2B00: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C2B04: bnel        $at, $zero, L_800C2AEC
    if (ctx->r1 != 0) {
        // 0x800C2B08: lw          $t4, 0x2C($s6)
        ctx->r12 = S32(MEM_W(ctx->r22, 0X2C));
            goto L_800C2AEC;
    }
    goto skip_1;
    // 0x800C2B08: lw          $t4, 0x2C($s6)
    ctx->r12 = S32(MEM_W(ctx->r22, 0X2C));
    skip_1:
    // 0x800C2B0C: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
L_800C2B10:
    // 0x800C2B10: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800C2B14: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800C2B18: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800C2B1C: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C2B20: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800C2B24: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800C2B28: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800C2B2C: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800C2B30: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C2B34: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C2B38: jr          $ra
    // 0x800C2B3C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800C2B3C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void alSeqSecToTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D02C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D02CC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800D02D0: ldc1        $f6, -0x5E80($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X5E80);
    // 0x800D02D4: lh          $t6, 0x18($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X18));
    // 0x800D02D8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800D02DC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D02E0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800D02E4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D02E8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800D02EC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800D02F0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800D02F4: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800D02F8: bgezl       $a2, L_800D0314
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800D02FC: div.d       $f8, $f18, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
            goto L_800D0314;
    }
    goto skip_0;
    // 0x800D02FC: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
    skip_0:
    // 0x800D0300: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800D0304: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800D0308: nop

    // 0x800D030C: add.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f6.d + ctx->f10.d;
    // 0x800D0310: div.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f6.d);
L_800D0314:
    // 0x800D0314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D0318: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800D031C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800D0320: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800D0324: nop

    // 0x800D0328: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800D032C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800D0330: nop

    // 0x800D0334: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800D0338: beql        $v0, $zero, L_800D0394
    if (ctx->r2 == 0) {
        // 0x800D033C: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800D0394;
    }
    goto skip_1;
    // 0x800D033C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x800D0340: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D0344: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D0348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D034C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D0350: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800D0354: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800D0358: nop

    // 0x800D035C: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800D0360: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800D0364: nop

    // 0x800D0368: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800D036C: bnel        $v0, $zero, L_800D0388
    if (ctx->r2 != 0) {
        // 0x800D0370: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_800D0388;
    }
    goto skip_2;
    // 0x800D0370: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_2:
    // 0x800D0374: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800D0378: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D037C: jr          $ra
    // 0x800D0380: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x800D0380: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800D0384: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
L_800D0388:
    // 0x800D0388: jr          $ra
    // 0x800D038C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800D038C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800D0390: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800D0394:
    // 0x800D0394: nop

    // 0x800D0398: bltzl       $v0, L_800D0388
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D039C: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_800D0388;
    }
    goto skip_3;
    // 0x800D039C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_3:
    // 0x800D03A0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800D03A4: jr          $ra
    // 0x800D03A8: nop

    return;
    // 0x800D03A8: nop

;}
RECOMP_FUNC void dmulscale27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090D44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090D4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090D50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090D54: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090D58: jal         0x800BB8F8
    // 0x80090D5C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090D5C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090D60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090D64: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090D68: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090D6C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090D70: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090D74: jal         0x800BB8F8
    // 0x80090D78: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090D78: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090D7C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090D80: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090D84: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090D88: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090D8C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090D90: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090D94: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090D98: jal         0x800BBA24
    // 0x80090D9C: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090D9C: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    after_2:
    // 0x80090DA0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090DA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090DA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090DAC: jr          $ra
    // 0x80090DB0: nop

    return;
    // 0x80090DB0: nop

;}
RECOMP_FUNC void gettilesizx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4E50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B4E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4E58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B4E5C: jal         0x8006370C
    // 0x800B4E60: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    gettileid(rdram, ctx);
        goto after_0;
    // 0x800B4E60: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_0:
    // 0x800B4E64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B4E68: bne         $v0, $at, L_800B4E78
    if (ctx->r2 != ctx->r1) {
        // 0x800B4E6C: nop
    
            goto L_800B4E78;
    }
    // 0x800B4E6C: nop

    // 0x800B4E70: b           L_800B4E98
    // 0x800B4E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B4E98;
    // 0x800B4E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B4E78:
    // 0x800B4E78: jal         0x8006370C
    // 0x800B4E7C: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    gettileid(rdram, ctx);
        goto after_1;
    // 0x800B4E7C: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x800B4E80: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800B4E84: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800B4E88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B4E8C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B4E90: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800B4E94: lh          $v0, -0x5004($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X5004));
L_800B4E98:
    // 0x800B4E98: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800B4E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B4EA0: jr          $ra
    // 0x800B4EA4: nop

    return;
    // 0x800B4EA4: nop

;}
RECOMP_FUNC void func_80059420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059420: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80059424: lw          $v1, -0x524C($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X524C));
    // 0x80059428: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8005942C: addiu       $a1, $a1, -0x5900
    ctx->r5 = ADD32(ctx->r5, -0X5900);
    // 0x80059430: blez        $v1, L_8005945C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80059434: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005945C;
    }
    // 0x80059434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059438:
    // 0x80059438: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x8005943C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80059440: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80059444: bne         $a0, $t6, L_80059454
    if (ctx->r4 != ctx->r14) {
        // 0x80059448: nop
    
            goto L_80059454;
    }
    // 0x80059448: nop

    // 0x8005944C: jr          $ra
    // 0x80059450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80059450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059454:
    // 0x80059454: bne         $at, $zero, L_80059438
    if (ctx->r1 != 0) {
        // 0x80059458: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80059438;
    }
    // 0x80059458: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_8005945C:
    // 0x8005945C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059460: jr          $ra
    // 0x80059464: nop

    return;
    // 0x80059464: nop

;}
RECOMP_FUNC void dmulscale28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090DB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090DBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090DC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090DC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090DC8: jal         0x800BB8F8
    // 0x80090DCC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090DCC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090DD0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090DD4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090DD8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80090DDC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090DE0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090DE4: jal         0x800BB8F8
    // 0x80090DE8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090DE8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x80090DEC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090DF0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090DF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090DF8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80090DFC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090E00: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090E04: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090E08: jal         0x800BBA24
    // 0x80090E0C: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x80090E0C: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_2:
    // 0x80090E10: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090E14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090E18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090E1C: jr          $ra
    // 0x80090E20: nop

    return;
    // 0x80090E20: nop

;}
RECOMP_FUNC void raytrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097564: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80097568: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8009756C: lh          $t7, 0x6F22($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X6F22));
    // 0x80097570: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80097574: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80097578: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8009757C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80097580: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80097584: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80097588: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009758C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80097590: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80097594: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80097598: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009759C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800975A0: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800975A4: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800975A8: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x800975AC: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x800975B0: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x800975B4: bltz        $t8, L_8009782C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800975B8: sw          $t8, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r24;
            goto L_8009782C;
    }
    // 0x800975B8: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x800975BC: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x800975C0: addiu       $t2, $t2, 0x6F30
    ctx->r10 = ADD32(ctx->r10, 0X6F30);
    // 0x800975C4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800975C8: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800975CC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_800975D0:
    // 0x800975D0: lw          $t4, 0x44($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800975D4: lw          $t5, 0x9C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800975D8: lw          $t8, 0x98($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800975DC: lw          $s6, 0x0($t4)
    ctx->r22 = S32(MEM_W(ctx->r12, 0X0));
    // 0x800975E0: lw          $a1, 0x8($t4)
    ctx->r5 = S32(MEM_W(ctx->r12, 0X8));
    // 0x800975E4: lw          $s7, 0x4($t4)
    ctx->r23 = S32(MEM_W(ctx->r12, 0X4));
    // 0x800975E8: lw          $a2, 0xC($t4)
    ctx->r6 = S32(MEM_W(ctx->r12, 0XC));
    // 0x800975EC: subu        $v1, $a1, $s6
    ctx->r3 = SUB32(ctx->r5, ctx->r22);
    // 0x800975F0: subu        $t6, $t5, $s7
    ctx->r14 = SUB32(ctx->r13, ctx->r23);
    // 0x800975F4: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800975F8: subu        $t9, $t8, $s6
    ctx->r25 = SUB32(ctx->r24, ctx->r22);
    // 0x800975FC: subu        $a0, $a2, $s7
    ctx->r4 = SUB32(ctx->r6, ctx->r23);
    // 0x80097600: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
    // 0x80097604: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80097608: lw          $t3, 0xA0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x8009760C: mflo        $t7
    ctx->r15 = lo;
    // 0x80097610: nop

    // 0x80097614: nop

    // 0x80097618: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009761C: mflo        $t2
    ctx->r10 = lo;
    // 0x80097620: subu        $s1, $t7, $t2
    ctx->r17 = SUB32(ctx->r15, ctx->r10);
    // 0x80097624: blezl       $s1, L_80097814
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80097628: lw          $t4, 0x6C($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
            goto L_80097814;
    }
    goto skip_0;
    // 0x80097628: lw          $t4, 0x6C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
    skip_0:
    // 0x8009762C: lw          $v0, 0x0($t3)
    ctx->r2 = S32(MEM_W(ctx->r11, 0X0));
    // 0x80097630: lw          $t4, 0xA4($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x80097634: lw          $t3, 0x9C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80097638: subu        $t5, $v0, $s6
    ctx->r13 = SUB32(ctx->r2, ctx->r22);
    // 0x8009763C: multu       $t5, $a0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097640: lw          $a3, 0x0($t4)
    ctx->r7 = S32(MEM_W(ctx->r12, 0X0));
    // 0x80097644: lw          $t2, 0x98($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80097648: subu        $t9, $a3, $s7
    ctx->r25 = SUB32(ctx->r7, ctx->r23);
    // 0x8009764C: subu        $s4, $a3, $t3
    ctx->r20 = SUB32(ctx->r7, ctx->r11);
    // 0x80097650: subu        $t4, $s6, $t2
    ctx->r12 = SUB32(ctx->r22, ctx->r10);
    // 0x80097654: mflo        $t8
    ctx->r24 = lo;
    // 0x80097658: nop

    // 0x8009765C: nop

    // 0x80097660: multu       $v1, $t9
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097664: mflo        $t7
    ctx->r15 = lo;
    // 0x80097668: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8009766C: bnel        $at, $zero, L_80097814
    if (ctx->r1 != 0) {
        // 0x80097670: lw          $t4, 0x6C($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
            goto L_80097814;
    }
    goto skip_1;
    // 0x80097670: lw          $t4, 0x6C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
    skip_1:
    // 0x80097674: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097678: subu        $s3, $v0, $t2
    ctx->r19 = SUB32(ctx->r2, ctx->r10);
    // 0x8009767C: subu        $t6, $s7, $t3
    ctx->r14 = SUB32(ctx->r23, ctx->r11);
    // 0x80097680: subu        $t7, $a1, $t2
    ctx->r15 = SUB32(ctx->r5, ctx->r10);
    // 0x80097684: mflo        $t5
    ctx->r13 = lo;
    // 0x80097688: nop

    // 0x8009768C: nop

    // 0x80097690: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097694: mflo        $t9
    ctx->r25 = lo;
    // 0x80097698: slt         $at, $t5, $t9
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8009769C: bnel        $at, $zero, L_80097814
    if (ctx->r1 != 0) {
        // 0x800976A0: lw          $t4, 0x6C($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
            goto L_80097814;
    }
    goto skip_2;
    // 0x800976A0: lw          $t4, 0x6C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
    skip_2:
    // 0x800976A4: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800976A8: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x800976AC: subu        $t3, $a2, $t3
    ctx->r11 = SUB32(ctx->r6, ctx->r11);
    // 0x800976B0: mflo        $t2
    ctx->r10 = lo;
    // 0x800976B4: nop

    // 0x800976B8: nop

    // 0x800976BC: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800976C0: mflo        $t6
    ctx->r14 = lo;
    // 0x800976C4: slt         $at, $t2, $t6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800976C8: beql        $at, $zero, L_80097814
    if (ctx->r1 == 0) {
        // 0x800976CC: lw          $t4, 0x6C($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
            goto L_80097814;
    }
    goto skip_3;
    // 0x800976CC: lw          $t4, 0x6C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
    skip_3:
    // 0x800976D0: multu       $s3, $a0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800976D4: addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
    // 0x800976D8: mflo        $t5
    ctx->r13 = lo;
    // 0x800976DC: nop

    // 0x800976E0: nop

    // 0x800976E4: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800976E8: mflo        $t9
    ctx->r25 = lo;
    // 0x800976EC: subu        $s2, $t5, $t9
    ctx->r18 = SUB32(ctx->r13, ctx->r25);
    // 0x800976F0: beq         $s2, $zero, L_80097810
    if (ctx->r18 == 0) {
        // 0x800976F4: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80097810;
    }
    // 0x800976F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800976F8:
    // 0x800976F8: bgez        $s0, L_80097720
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800976FC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80097720;
    }
    // 0x800976FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097700: lw          $t8, 0x98($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80097704: lw          $t7, 0xA0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80097708: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8009770C: lw          $t3, 0xA4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x80097710: lw          $t4, 0x9C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80097714: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80097718: b           L_80097830
    // 0x8009771C: lw          $v0, 0x6C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X6C));
        goto L_80097830;
    // 0x8009771C: lw          $v0, 0x6C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X6C));
L_80097720:
    // 0x80097720: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80097724: jal         0x800919B0
    // 0x80097728: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    scale(rdram, ctx);
        goto after_0;
    // 0x80097728: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x8009772C: lw          $t2, 0x98($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80097730: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80097734: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80097738: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009773C: jal         0x800919B0
    // 0x80097740: addu        $s5, $v0, $t2
    ctx->r21 = ADD32(ctx->r2, ctx->r10);
    scale(rdram, ctx);
        goto after_1;
    // 0x80097740: addu        $s5, $v0, $t2
    ctx->r21 = ADD32(ctx->r2, ctx->r10);
    after_1:
    // 0x80097744: lw          $t5, 0x60($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80097748: subu        $t6, $s5, $s6
    ctx->r14 = SUB32(ctx->r21, ctx->r22);
    // 0x8009774C: lw          $a0, 0x9C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80097750: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097754: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80097758: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x8009775C: subu        $t8, $v1, $s7
    ctx->r24 = SUB32(ctx->r3, ctx->r23);
    // 0x80097760: mflo        $t9
    ctx->r25 = lo;
    // 0x80097764: nop

    // 0x80097768: nop

    // 0x8009776C: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097770: mflo        $t7
    ctx->r15 = lo;
    // 0x80097774: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80097778: beql        $at, $zero, L_800976F8
    if (ctx->r1 == 0) {
        // 0x8009777C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800976F8;
    }
    goto skip_4;
    // 0x8009777C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_4:
    // 0x80097780: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80097784: blez        $v0, L_80097794
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097788: lw          $t4, 0x98($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X98));
            goto L_80097794;
    }
    // 0x80097788: lw          $t4, 0x98($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X98));
    // 0x8009778C: b           L_80097798
    // 0x80097790: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_80097798;
    // 0x80097790: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80097794:
    // 0x80097794: negu        $a3, $v0
    ctx->r7 = SUB32(0, ctx->r2);
L_80097798:
    // 0x80097798: subu        $v0, $t4, $s5
    ctx->r2 = SUB32(ctx->r12, ctx->r21);
    // 0x8009779C: blez        $v0, L_800977AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800977A0: lw          $t0, 0xA0($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XA0));
            goto L_800977AC;
    }
    // 0x800977A0: lw          $t0, 0xA0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800977A4: b           L_800977B0
    // 0x800977A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_800977B0;
    // 0x800977A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800977AC:
    // 0x800977AC: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
L_800977B0:
    // 0x800977B0: lw          $t3, 0x98($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800977B4: lw          $t2, 0x0($t0)
    ctx->r10 = S32(MEM_W(ctx->r8, 0X0));
    // 0x800977B8: lw          $t1, 0xA4($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800977BC: lw          $t6, 0x9C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800977C0: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x800977C4: blez        $v0, L_800977D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800977C8: addu        $t8, $a1, $a3
        ctx->r24 = ADD32(ctx->r5, ctx->r7);
            goto L_800977D4;
    }
    // 0x800977C8: addu        $t8, $a1, $a3
    ctx->r24 = ADD32(ctx->r5, ctx->r7);
    // 0x800977CC: b           L_800977D8
    // 0x800977D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800977D8;
    // 0x800977D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800977D4:
    // 0x800977D4: negu        $a2, $v0
    ctx->r6 = SUB32(0, ctx->r2);
L_800977D8:
    // 0x800977D8: lw          $t5, 0x0($t1)
    ctx->r13 = S32(MEM_W(ctx->r9, 0X0));
    // 0x800977DC: subu        $v0, $t6, $t5
    ctx->r2 = SUB32(ctx->r14, ctx->r13);
    // 0x800977E0: blez        $v0, L_800977F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800977E4: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_800977F0;
    }
    // 0x800977E4: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x800977E8: b           L_800977F0
    // 0x800977EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800977F0;
    // 0x800977EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800977F0:
    // 0x800977F0: addu        $t9, $a0, $a2
    ctx->r25 = ADD32(ctx->r4, ctx->r6);
    // 0x800977F4: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800977F8: beql        $at, $zero, L_80097814
    if (ctx->r1 == 0) {
        // 0x800977FC: lw          $t4, 0x6C($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
            goto L_80097814;
    }
    goto skip_5;
    // 0x800977FC: lw          $t4, 0x6C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
    skip_5:
    // 0x80097800: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
    // 0x80097804: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x80097808: lw          $t7, 0x6C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x8009780C: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
L_80097810:
    // 0x80097810: lw          $t4, 0x6C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
L_80097814:
    // 0x80097814: lw          $t2, 0x44($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80097818: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x8009781C: addiu       $t6, $t2, -0x10
    ctx->r14 = ADD32(ctx->r10, -0X10);
    // 0x80097820: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80097824: bgez        $t3, L_800975D0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80097828: sw          $t3, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r11;
            goto L_800975D0;
    }
    // 0x80097828: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
L_8009782C:
    // 0x8009782C: lw          $v0, 0x68($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X68));
L_80097830:
    // 0x80097830: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80097834: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80097838: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8009783C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80097840: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80097844: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80097848: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8009784C: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80097850: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80097854: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80097858: jr          $ra
    // 0x8009785C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8009785C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void divscale28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009183C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091840: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091844: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80091848: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009184C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091850: jal         0x800BB834
    // 0x80091854: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091854: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009185C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091860: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091864: jal         0x800BB89C
    // 0x80091868: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091868: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x8009186C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091874: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091878: jr          $ra
    // 0x8009187C: nop

    return;
    // 0x8009187C: nop

;}
RECOMP_FUNC void divscale29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091888: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009188C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091890: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x80091894: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009189C: jal         0x800BB834
    // 0x800918A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800918A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800918A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800918A8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800918AC: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800918B0: jal         0x800BB89C
    // 0x800918B4: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800918B4: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x800918B8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800918BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800918C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800918C4: jr          $ra
    // 0x800918C8: nop

    return;
    // 0x800918C8: nop

;}
RECOMP_FUNC void checkavailweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075944: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80075948: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8007594C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075950: addiu       $t6, $t6, -0x1740
    ctx->r14 = ADD32(ctx->r14, -0X1740);
    // 0x80075954: lw          $at, 0x0($t6)
    ctx->r1 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80075958: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x8007595C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80075960: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x80075964: lw          $t9, 0x4($t6)
    ctx->r25 = S32(MEM_W(ctx->r14, 0X4));
    // 0x80075968: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007596C: lw          $at, 0x8($t6)
    ctx->r1 = S32(MEM_W(ctx->r14, 0X8));
    // 0x80075970: sw          $at, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r1;
    // 0x80075974: lw          $t9, 0xC($t6)
    ctx->r25 = S32(MEM_W(ctx->r14, 0XC));
    // 0x80075978: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x8007597C: lw          $at, 0x10($t6)
    ctx->r1 = S32(MEM_W(ctx->r14, 0X10));
    // 0x80075980: sw          $at, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r1;
    // 0x80075984: lw          $t9, 0x14($t6)
    ctx->r25 = S32(MEM_W(ctx->r14, 0X14));
    // 0x80075988: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    // 0x8007598C: lw          $at, 0x18($t6)
    ctx->r1 = S32(MEM_W(ctx->r14, 0X18));
    // 0x80075990: sw          $at, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r1;
    // 0x80075994: lh          $v0, 0x2BA($a0)
    ctx->r2 = S32(MEM_H(ctx->r4, 0X2BA));
    // 0x80075998: bltz        $v0, L_800759F4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8007599C: sll         $a1, $v0, 16
        ctx->r5 = S32(ctx->r2 << 16);
            goto L_800759F4;
    }
    // 0x8007599C: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x800759A0: lh          $t2, 0x2B2($a0)
    ctx->r10 = S32(MEM_H(ctx->r4, 0X2B2));
    // 0x800759A4: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800759A8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800759AC: beq         $t0, $t2, L_80075AA8
    if (ctx->r8 == ctx->r10) {
        // 0x800759B0: sh          $t1, 0x2BA($a0)
        MEM_H(0X2BA, ctx->r4) = ctx->r9;
            goto L_80075AA8;
    }
    // 0x800759B0: sh          $t1, 0x2BA($a0)
    MEM_H(0X2BA, ctx->r4) = ctx->r9;
    // 0x800759B4: beq         $t0, $zero, L_800759E4
    if (ctx->r8 == 0) {
        // 0x800759B8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800759E4;
    }
    // 0x800759B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800759BC: beq         $t0, $at, L_800759E4
    if (ctx->r8 == ctx->r1) {
        // 0x800759C0: addu        $t3, $a0, $t0
        ctx->r11 = ADD32(ctx->r4, ctx->r8);
            goto L_800759E4;
    }
    // 0x800759C0: addu        $t3, $a0, $t0
    ctx->r11 = ADD32(ctx->r4, ctx->r8);
    // 0x800759C4: lbu         $t4, 0x349($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X349);
    // 0x800759C8: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x800759CC: addu        $t8, $a0, $t5
    ctx->r24 = ADD32(ctx->r4, ctx->r13);
    // 0x800759D0: beql        $t4, $zero, L_800759F8
    if (ctx->r12 == 0) {
        // 0x800759D4: lh          $a2, 0x2B2($a0)
        ctx->r6 = S32(MEM_H(ctx->r4, 0X2B2));
            goto L_800759F8;
    }
    goto skip_0;
    // 0x800759D4: lh          $a2, 0x2B2($a0)
    ctx->r6 = S32(MEM_H(ctx->r4, 0X2B2));
    skip_0:
    // 0x800759D8: lh          $t7, 0x28E($t8)
    ctx->r15 = S32(MEM_H(ctx->r24, 0X28E));
    // 0x800759DC: blezl       $t7, L_800759F8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800759E0: lh          $a2, 0x2B2($a0)
        ctx->r6 = S32(MEM_H(ctx->r4, 0X2B2));
            goto L_800759F8;
    }
    goto skip_1;
    // 0x800759E0: lh          $a2, 0x2B2($a0)
    ctx->r6 = S32(MEM_H(ctx->r4, 0X2B2));
    skip_1:
L_800759E4:
    // 0x800759E4: jal         0x80075744
    // 0x800759E8: nop

    addweapon(rdram, ctx);
        goto after_0;
    // 0x800759E8: nop

    after_0:
    // 0x800759EC: b           L_80075AAC
    // 0x800759F0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80075AAC;
    // 0x800759F0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800759F4:
    // 0x800759F4: lh          $a2, 0x2B2($a0)
    ctx->r6 = S32(MEM_H(ctx->r4, 0X2B2));
L_800759F8:
    // 0x800759F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800759FC: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80075A00: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80075A04: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x80075A08: lbu         $t0, 0x349($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X349);
    // 0x80075A0C: sll         $t1, $t6, 1
    ctx->r9 = S32(ctx->r14 << 1);
    // 0x80075A10: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80075A14: beq         $t0, $zero, L_80075A28
    if (ctx->r8 == 0) {
        // 0x80075A18: nop
    
            goto L_80075A28;
    }
    // 0x80075A18: nop

    // 0x80075A1C: lh          $t3, 0x28E($t2)
    ctx->r11 = S32(MEM_H(ctx->r10, 0X28E));
    // 0x80075A20: bgtzl       $t3, L_80075AAC
    if (SIGNED(ctx->r11) > 0) {
        // 0x80075A24: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_80075AAC;
    }
    goto skip_2;
    // 0x80075A24: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_2:
L_80075A28:
    // 0x80075A28: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
L_80075A2C:
    // 0x80075A2C: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80075A30: lh          $a1, 0x0($t5)
    ctx->r5 = S32(MEM_H(ctx->r13, 0X0));
    // 0x80075A34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80075A38: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80075A3C: beq         $a1, $zero, L_80075A70
    if (ctx->r5 == 0) {
        // 0x80075A40: addu        $t8, $a0, $a1
        ctx->r24 = ADD32(ctx->r4, ctx->r5);
            goto L_80075A70;
    }
    // 0x80075A40: addu        $t8, $a0, $a1
    ctx->r24 = ADD32(ctx->r4, ctx->r5);
    // 0x80075A44: lbu         $t7, 0x349($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X349);
    // 0x80075A48: sra         $v0, $t1, 16
    ctx->r2 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80075A4C: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x80075A50: beq         $t7, $zero, L_80075A68
    if (ctx->r15 == 0) {
        // 0x80075A54: sll         $t6, $a1, 1
        ctx->r14 = S32(ctx->r5 << 1);
            goto L_80075A68;
    }
    // 0x80075A54: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80075A58: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x80075A5C: lh          $t0, 0x28E($t9)
    ctx->r8 = S32(MEM_H(ctx->r25, 0X28E));
    // 0x80075A60: bgtzl       $t0, L_80075A74
    if (SIGNED(ctx->r8) > 0) {
        // 0x80075A64: lbu         $t3, 0x347($a0)
        ctx->r11 = MEM_BU(ctx->r4, 0X347);
            goto L_80075A74;
    }
    goto skip_3;
    // 0x80075A64: lbu         $t3, 0x347($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X347);
    skip_3:
L_80075A68:
    // 0x80075A68: bnel        $at, $zero, L_80075A2C
    if (ctx->r1 != 0) {
        // 0x80075A6C: sll         $t4, $v0, 1
        ctx->r12 = S32(ctx->r2 << 1);
            goto L_80075A2C;
    }
    goto skip_4;
    // 0x80075A6C: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    skip_4:
L_80075A70:
    // 0x80075A70: lbu         $t3, 0x347($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X347);
L_80075A74:
    // 0x80075A74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80075A78: sh          $a2, 0x2B4($a0)
    MEM_H(0X2B4, ctx->r4) = ctx->r6;
    // 0x80075A7C: sh          $zero, 0x2E4($a0)
    MEM_H(0X2E4, ctx->r4) = 0;
    // 0x80075A80: sh          $a1, 0x2B2($a0)
    MEM_H(0X2B2, ctx->r4) = ctx->r5;
    // 0x80075A84: sh          $a1, 0x372($a0)
    MEM_H(0X372, ctx->r4) = ctx->r5;
    // 0x80075A88: bne         $t3, $at, L_80075AA0
    if (ctx->r11 != ctx->r1) {
        // 0x80075A8C: sh          $zero, 0x2D4($a0)
        MEM_H(0X2D4, ctx->r4) = 0;
            goto L_80075AA0;
    }
    // 0x80075A8C: sh          $zero, 0x2D4($a0)
    MEM_H(0X2D4, ctx->r4) = 0;
    // 0x80075A90: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80075A94: sb          $zero, 0x347($a0)
    MEM_B(0X347, ctx->r4) = 0;
    // 0x80075A98: b           L_80075AA8
    // 0x80075A9C: sh          $t4, 0x328($a0)
    MEM_H(0X328, ctx->r4) = ctx->r12;
        goto L_80075AA8;
    // 0x80075A9C: sh          $t4, 0x328($a0)
    MEM_H(0X328, ctx->r4) = ctx->r12;
L_80075AA0:
    // 0x80075AA0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80075AA4: sh          $t5, 0x328($a0)
    MEM_H(0X328, ctx->r4) = ctx->r13;
L_80075AA8:
    // 0x80075AA8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80075AAC:
    // 0x80075AAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80075AB0: jr          $ra
    // 0x80075AB4: nop

    return;
    // 0x80075AB4: nop

;}
RECOMP_FUNC void alSynStartVoiceParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBEC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CBEC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBEC8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CBECC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CBED0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800CBED4: lw          $t6, 0x8($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X8));
    // 0x800CBED8: beql        $t6, $zero, L_800CBF98
    if (ctx->r14 == 0) {
        // 0x800CBEDC: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CBF98;
    }
    goto skip_0;
    // 0x800CBEDC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800CBEE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CBEE4: jal         0x800C2570
    // 0x800CBEE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800CBEE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CBEEC: lw          $a0, 0x20($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CBEF0: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CBEF4: beq         $v0, $zero, L_800CBF94
    if (ctx->r2 == 0) {
        // 0x800CBEF8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800CBF94;
    }
    // 0x800CBEF8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CBEFC: lbu         $v1, 0x3B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3B);
    // 0x800CBF00: bgez        $v1, L_800CBF14
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CBF04: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800CBF14;
    }
    // 0x800CBF04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CBF08: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x800CBF0C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x800CBF10: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800CBF14:
    // 0x800CBF14: lw          $t9, 0x8($a3)
    ctx->r25 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CBF18: lw          $t8, 0x1C($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X1C));
    // 0x800CBF1C: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x800CBF20: lw          $t0, 0xD8($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0XD8));
    // 0x800CBF24: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800CBF28: sh          $t2, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r10;
    // 0x800CBF2C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800CBF30: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x800CBF34: lh          $t3, 0x1A($a3)
    ctx->r11 = S32(MEM_H(ctx->r7, 0X1A));
    // 0x800CBF38: sh          $t3, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r11;
    // 0x800CBF3C: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x800CBF40: sb          $t4, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r12;
    // 0x800CBF44: lh          $t5, 0x32($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X32));
    // 0x800CBF48: sb          $v1, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r3;
    // 0x800CBF4C: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x800CBF50: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800CBF54: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x800CBF58: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800CBF5C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800CBF60: jal         0x800C2468
    // 0x800CBF64: lw          $a1, 0x3C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X3C));
    _timeToSamples(rdram, ctx);
        goto after_1;
    // 0x800CBF64: lw          $a1, 0x3C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x800CBF68: lw          $a2, 0x1C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CBF6C: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CBF70: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800CBF74: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x800CBF78: lw          $t6, 0x28($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800CBF7C: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x800CBF80: lw          $t7, 0x8($a3)
    ctx->r15 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CBF84: lw          $a0, 0xC($t7)
    ctx->r4 = S32(MEM_W(ctx->r15, 0XC));
    // 0x800CBF88: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CBF8C: jalr        $t9
    // 0x800CBF90: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CBF90: nop

    after_2:
L_800CBF94:
    // 0x800CBF94: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CBF98:
    // 0x800CBF98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CBF9C: jr          $ra
    // 0x800CBFA0: nop

    return;
    // 0x800CBFA0: nop

;}
RECOMP_FUNC void alCSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1B44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C1B48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C1B4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C1B50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C1B54: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x800C1B58: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800C1B5C: lw          $a2, 0x10($a0)
    ctx->r6 = S32(MEM_W(ctx->r4, 0X10));
    // 0x800C1B60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800C1B64: lw          $t3, 0x24($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C1B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1B6C: lw          $t6, 0x4($t4)
    ctx->r14 = S32(MEM_W(ctx->r12, 0X4));
L_800C1B70:
    // 0x800C1B70: srlv        $t7, $t6, $v0
    ctx->r15 = S32(U32(ctx->r14) >> (ctx->r2 & 31));
    // 0x800C1B74: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C1B78: beql        $t8, $zero, L_800C1BBC
    if (ctx->r24 == 0) {
        // 0x800C1B7C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C1BBC;
    }
    goto skip_0;
    // 0x800C1B7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800C1B80: lw          $t6, 0x14($t4)
    ctx->r14 = S32(MEM_W(ctx->r12, 0X14));
    // 0x800C1B84: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800C1B88: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800C1B8C: beql        $t6, $zero, L_800C1BA4
    if (ctx->r14 == 0) {
        // 0x800C1B90: lw          $a0, 0xB8($v1)
        ctx->r4 = S32(MEM_W(ctx->r3, 0XB8));
            goto L_800C1BA4;
    }
    goto skip_1;
    // 0x800C1B90: lw          $a0, 0xB8($v1)
    ctx->r4 = S32(MEM_W(ctx->r3, 0XB8));
    skip_1:
    // 0x800C1B94: lw          $t7, 0xB8($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0XB8));
    // 0x800C1B98: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x800C1B9C: sw          $t8, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r24;
    // 0x800C1BA0: lw          $a0, 0xB8($v1)
    ctx->r4 = S32(MEM_W(ctx->r3, 0XB8));
L_800C1BA4:
    // 0x800C1BA4: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x800C1BA8: beql        $at, $zero, L_800C1BBC
    if (ctx->r1 == 0) {
        // 0x800C1BAC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C1BBC;
    }
    goto skip_2;
    // 0x800C1BAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x800C1BB0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800C1BB4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800C1BB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C1BBC:
    // 0x800C1BBC: bnel        $v0, $a1, L_800C1B70
    if (ctx->r2 != ctx->r5) {
        // 0x800C1BC0: lw          $t6, 0x4($t4)
        ctx->r14 = S32(MEM_W(ctx->r12, 0X4));
            goto L_800C1B70;
    }
    goto skip_3;
    // 0x800C1BC0: lw          $t6, 0x4($t4)
    ctx->r14 = S32(MEM_W(ctx->r12, 0X4));
    skip_3:
    // 0x800C1BC4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1BC8: jal         0x800C1A20
    // 0x800C1BCC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_0;
    // 0x800C1BCC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800C1BD0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C1BD4: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800C1BD8: bne         $v0, $at, L_800C1D44
    if (ctx->r2 != ctx->r1) {
        // 0x800C1BDC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C1D44;
    }
    // 0x800C1BDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C1BE0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1BE4: jal         0x800C1A20
    // 0x800C1BE8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_1;
    // 0x800C1BE8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800C1BEC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800C1BF0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800C1BF4: bne         $v0, $at, L_800C1C48
    if (ctx->r2 != ctx->r1) {
        // 0x800C1BF8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C1C48;
    }
    // 0x800C1BF8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C1BFC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800C1C00: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800C1C04: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800C1C08: sb          $a2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r6;
    // 0x800C1C0C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1C10: jal         0x800C1A20
    // 0x800C1C14: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_2;
    // 0x800C1C14: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x800C1C18: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x800C1C1C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1C20: jal         0x800C1A20
    // 0x800C1C24: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_3;
    // 0x800C1C24: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_3:
    // 0x800C1C28: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x800C1C2C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1C30: jal         0x800C1A20
    // 0x800C1C34: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_4;
    // 0x800C1C34: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x800C1C38: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x800C1C3C: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C1C40: b           L_800C1DE0
    // 0x800C1C44: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
        goto L_800C1DE0;
    // 0x800C1C44: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
L_800C1C48:
    // 0x800C1C48: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800C1C4C: bnel        $v1, $at, L_800C1C88
    if (ctx->r3 != ctx->r1) {
        // 0x800C1C50: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800C1C88;
    }
    goto skip_4;
    // 0x800C1C50: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_4:
    // 0x800C1C54: lw          $t7, 0x4($t4)
    ctx->r15 = S32(MEM_W(ctx->r12, 0X4));
    // 0x800C1C58: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C1C5C: sllv        $t9, $t8, $t3
    ctx->r25 = S32(ctx->r24 << (ctx->r11 & 31));
    // 0x800C1C60: xor         $t6, $t7, $t9
    ctx->r14 = ctx->r15 ^ ctx->r25;
    // 0x800C1C64: beq         $t6, $zero, L_800C1C78
    if (ctx->r14 == 0) {
        // 0x800C1C68: sw          $t6, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r14;
            goto L_800C1C78;
    }
    // 0x800C1C68: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800C1C6C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x800C1C70: b           L_800C1DE0
    // 0x800C1C74: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_800C1DE0;
    // 0x800C1C74: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800C1C78:
    // 0x800C1C78: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800C1C7C: b           L_800C1DE0
    // 0x800C1C80: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
        goto L_800C1DE0;
    // 0x800C1C80: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800C1C84: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800C1C88:
    // 0x800C1C88: bne         $v1, $at, L_800C1CB8
    if (ctx->r3 != ctx->r1) {
        // 0x800C1C8C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800C1CB8;
    }
    // 0x800C1C8C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1C90: jal         0x800C1A20
    // 0x800C1C94: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_5;
    // 0x800C1C94: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x800C1C98: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1C9C: jal         0x800C1A20
    // 0x800C1CA0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_6;
    // 0x800C1CA0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x800C1CA4: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C1CA8: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800C1CAC: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x800C1CB0: b           L_800C1DE0
    // 0x800C1CB4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800C1DE0;
    // 0x800C1CB4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C1CB8:
    // 0x800C1CB8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800C1CBC: bne         $v1, $at, L_800C1DE0
    if (ctx->r3 != ctx->r1) {
        // 0x800C1CC0: sll         $t7, $t3, 2
        ctx->r15 = S32(ctx->r11 << 2);
            goto L_800C1DE0;
    }
    // 0x800C1CC0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800C1CC4: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x800C1CC8: lw          $v0, 0x18($t5)
    ctx->r2 = S32(MEM_W(ctx->r13, 0X18));
    // 0x800C1CCC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C1CD0: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800C1CD4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C1CD8: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x800C1CDC: bne         $a0, $zero, L_800C1CF0
    if (ctx->r4 != 0) {
        // 0x800C1CE0: lbu         $a1, -0x1($v0)
        ctx->r5 = MEM_BU(ctx->r2, -0X1);
            goto L_800C1CF0;
    }
    // 0x800C1CE0: lbu         $a1, -0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X1);
    // 0x800C1CE4: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800C1CE8: b           L_800C1D30
    // 0x800C1CEC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
        goto L_800C1D30;
    // 0x800C1CEC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800C1CF0:
    // 0x800C1CF0: beq         $a0, $at, L_800C1CFC
    if (ctx->r4 == ctx->r1) {
        // 0x800C1CF4: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800C1CFC;
    }
    // 0x800C1CF4: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800C1CF8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_800C1CFC:
    // 0x800C1CFC: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x800C1D00: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x800C1D04: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800C1D08: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800C1D0C: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x800C1D10: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C1D14: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800C1D18: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800C1D1C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800C1D20: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800C1D24: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C1D28: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800C1D2C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800C1D30:
    // 0x800C1D30: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C1D34: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800C1D38: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x800C1D3C: b           L_800C1DE0
    // 0x800C1D40: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800C1DE0;
    // 0x800C1D40: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C1D44:
    // 0x800C1D44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C1D48: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x800C1D4C: beq         $t9, $zero, L_800C1D74
    if (ctx->r25 == 0) {
        // 0x800C1D50: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_800C1D74;
    }
    // 0x800C1D50: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800C1D54: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800C1D58: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1D5C: jal         0x800C1A20
    // 0x800C1D60: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_7;
    // 0x800C1D60: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_7:
    // 0x800C1D64: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800C1D68: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C1D6C: b           L_800C1D84
    // 0x800C1D70: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
        goto L_800C1D84;
    // 0x800C1D70: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
L_800C1D74:
    // 0x800C1D74: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x800C1D78: lbu         $t7, 0xA8($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA8);
    // 0x800C1D7C: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800C1D80: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
L_800C1D84:
    // 0x800C1D84: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800C1D88: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800C1D8C: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800C1D90: beq         $t9, $at, L_800C1DDC
    if (ctx->r25 == ctx->r1) {
        // 0x800C1D94: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_800C1DDC;
    }
    // 0x800C1D94: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800C1D98: beq         $t9, $at, L_800C1DDC
    if (ctx->r25 == ctx->r1) {
        // 0x800C1D9C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800C1DDC;
    }
    // 0x800C1D9C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C1DA0: jal         0x800C1A20
    // 0x800C1DA4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_8;
    // 0x800C1DA4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x800C1DA8: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x800C1DAC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x800C1DB0: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x800C1DB4: andi        $t8, $t6, 0xF0
    ctx->r24 = ctx->r14 & 0XF0;
    // 0x800C1DB8: bne         $t8, $at, L_800C1DE0
    if (ctx->r24 != ctx->r1) {
        // 0x800C1DBC: or          $t2, $t4, $zero
        ctx->r10 = ctx->r12 | 0;
            goto L_800C1DE0;
    }
    // 0x800C1DBC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800C1DC0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800C1DC4: jal         0x800C1AE4
    // 0x800C1DC8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    static_5_800C1AE4(rdram, ctx);
        goto after_9;
    // 0x800C1DC8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_9:
    // 0x800C1DCC: lw          $t1, 0x28($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800C1DD0: lw          $t3, 0x24($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C1DD4: b           L_800C1DE0
    // 0x800C1DD8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_800C1DE0;
    // 0x800C1DD8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_800C1DDC:
    // 0x800C1DDC: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_800C1DE0:
    // 0x800C1DE0: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800C1DE4: lw          $t7, 0xC($t4)
    ctx->r15 = S32(MEM_W(ctx->r12, 0XC));
    // 0x800C1DE8: sw          $t1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r9;
    // 0x800C1DEC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800C1DF0: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x800C1DF4: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x800C1DF8: lh          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X0));
    // 0x800C1DFC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800C1E00: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x800C1E04: beql        $t6, $at, L_800C1E24
    if (ctx->r14 == ctx->r1) {
        // 0x800C1E08: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800C1E24;
    }
    goto skip_5;
    // 0x800C1E08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_5:
    // 0x800C1E0C: jal         0x800C1AE4
    // 0x800C1E10: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    static_5_800C1AE4(rdram, ctx);
        goto after_10;
    // 0x800C1E10: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x800C1E14: lw          $t7, 0xB8($t5)
    ctx->r15 = S32(MEM_W(ctx->r13, 0XB8));
    // 0x800C1E18: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1E1C: sw          $t9, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r25;
    // 0x800C1E20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800C1E24:
    // 0x800C1E24: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x800C1E28: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C1E2C: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800C1E30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C1E34: jr          $ra
    // 0x800C1E38: nop

    return;
    // 0x800C1E38: nop

;}
RECOMP_FUNC void func_8005BF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BF2C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005BF30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005BF34: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x8005BF38: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8005BF3C: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8005BF40: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005BF44: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x8005BF48: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005BF4C: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8005BF50: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x8005BF54: addiu       $t7, $t7, 0x5770
    ctx->r15 = ADD32(ctx->r15, 0X5770);
    // 0x8005BF58: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005BF5C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8005BF60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005BF64: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005BF68: lw          $a0, 0x214($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X214));
    // 0x8005BF6C: lw          $a1, 0x218($v0)
    ctx->r5 = S32(MEM_W(ctx->r2, 0X218));
    // 0x8005BF70: jal         0x80097DB8
    // 0x8005BF74: addiu       $a2, $v0, 0x288
    ctx->r6 = ADD32(ctx->r2, 0X288);
    updatesector(rdram, ctx);
        goto after_0;
    // 0x8005BF74: addiu       $a2, $v0, 0x288
    ctx->r6 = ADD32(ctx->r2, 0X288);
    after_0:
    // 0x8005BF78: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8005BF7C: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8005BF80: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8005BF84: jal         0x800711A8
    // 0x8005BF88: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    displayrooms(rdram, ctx);
        goto after_1;
    // 0x8005BF88: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_1:
    // 0x8005BF8C: jal         0x8005BC30
    // 0x8005BF90: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_8005BC30(rdram, ctx);
        goto after_2;
    // 0x8005BF90: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x8005BF94: jal         0x80063168
    // 0x8005BF98: nop

    func_80063168(rdram, ctx);
        goto after_3;
    // 0x8005BF98: nop

    after_3:
    // 0x8005BF9C: jal         0x80063BB8
    // 0x8005BFA0: nop

    func_80063BB8(rdram, ctx);
        goto after_4;
    // 0x8005BFA0: nop

    after_4:
    // 0x8005BFA4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8005BFA8: addiu       $s0, $s0, 0x4418
    ctx->r16 = ADD32(ctx->r16, 0X4418);
    // 0x8005BFAC: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8005BFB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005BFB4: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8005BFB8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005BFBC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005BFC0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8005BFC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005BFC8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005BFCC: lw          $a0, 0x4410($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4410));
    // 0x8005BFD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005BFD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005BFD8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005BFDC: jal         0x800BD8C8
    // 0x8005BFE0: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    guTranslate(rdram, ctx);
        goto after_5;
    // 0x8005BFE0: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    after_5:
    // 0x8005BFE4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005BFE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005BFEC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8005BFF0: lw          $a0, 0x4410($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4410));
    // 0x8005BFF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005BFF8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005BFFC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005C000: jal         0x800BD974
    // 0x8005C004: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    guScale(rdram, ctx);
        goto after_6;
    // 0x8005C004: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    after_6:
    // 0x8005C008: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8005C00C: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x8005C010: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8005C014: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005C018: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8005C01C: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x8005C020: addiu       $a3, $a3, 0x4410
    ctx->r7 = ADD32(ctx->r7, 0X4410);
    // 0x8005C024: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005C028: lw          $t3, 0x0($a3)
    ctx->r11 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8005C02C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005C030: ori         $at, $at, 0x300
    ctx->r1 = ctx->r1 | 0X300;
    // 0x8005C034: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x8005C038: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005C03C: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8005C040: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8005C044: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x8005C048: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005C04C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005C050: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005C054: lw          $t7, 0x0($a3)
    ctx->r15 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8005C058: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005C05C: ori         $at, $at, 0x380
    ctx->r1 = ctx->r1 | 0X380;
    // 0x8005C060: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8005C064: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005C068: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8005C06C: lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // 0x8005C070: addiu       $a2, $a2, 0x1908
    ctx->r6 = ADD32(ctx->r6, 0X1908);
    // 0x8005C074: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005C078: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005C07C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005C080: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005C084: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8005C088: jal         0x80066324
    // 0x8005C08C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80066324(rdram, ctx);
        goto after_7;
    // 0x8005C08C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_7:
    // 0x8005C090: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8005C094: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005C098: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8005C09C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8005C0A0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8005C0A4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C0A8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8005C0AC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8005C0B0: sw          $zero, -0x2344($at)
    MEM_W(-0X2344, ctx->r1) = 0;
    // 0x8005C0B4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C0B8: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x8005C0BC: jal         0x800BB580
    // 0x8005C0C0: sh          $t3, -0x2982($at)
    MEM_H(-0X2982, ctx->r1) = ctx->r11;
    osGetTime_recomp(rdram, ctx);
        goto after_8;
    // 0x8005C0C0: sh          $t3, -0x2982($at)
    MEM_H(-0X2982, ctx->r1) = ctx->r11;
    after_8:
    // 0x8005C0C4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C0C8: sw          $v0, -0x1B28($at)
    MEM_W(-0X1B28, ctx->r1) = ctx->r2;
    // 0x8005C0CC: jal         0x80063270
    // 0x8005C0D0: sw          $v1, -0x1B24($at)
    MEM_W(-0X1B24, ctx->r1) = ctx->r3;
    func_80063270(rdram, ctx);
        goto after_9;
    // 0x8005C0D0: sw          $v1, -0x1B24($at)
    MEM_W(-0X1B24, ctx->r1) = ctx->r3;
    after_9:
    // 0x8005C0D4: jal         0x800BB580
    // 0x8005C0D8: nop

    osGetTime_recomp(rdram, ctx);
        goto after_10;
    // 0x8005C0D8: nop

    after_10:
    // 0x8005C0DC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C0E0: sw          $v0, -0x1A88($at)
    MEM_W(-0X1A88, ctx->r1) = ctx->r2;
    // 0x8005C0E4: jal         0x800BB580
    // 0x8005C0E8: sw          $v1, -0x1A84($at)
    MEM_W(-0X1A84, ctx->r1) = ctx->r3;
    osGetTime_recomp(rdram, ctx);
        goto after_11;
    // 0x8005C0E8: sw          $v1, -0x1A84($at)
    MEM_W(-0X1A84, ctx->r1) = ctx->r3;
    after_11:
    // 0x8005C0EC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C0F0: sw          $v0, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = ctx->r2;
    // 0x8005C0F4: jal         0x800636B8
    // 0x8005C0F8: sw          $v1, -0x1B1C($at)
    MEM_W(-0X1B1C, ctx->r1) = ctx->r3;
    func_800636B8(rdram, ctx);
        goto after_12;
    // 0x8005C0F8: sw          $v1, -0x1B1C($at)
    MEM_W(-0X1B1C, ctx->r1) = ctx->r3;
    after_12:
    // 0x8005C0FC: jal         0x800BB580
    // 0x8005C100: nop

    osGetTime_recomp(rdram, ctx);
        goto after_13;
    // 0x8005C100: nop

    after_13:
    // 0x8005C104: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C108: sw          $v0, -0x1A80($at)
    MEM_W(-0X1A80, ctx->r1) = ctx->r2;
    // 0x8005C10C: sw          $v1, -0x1A7C($at)
    MEM_W(-0X1A7C, ctx->r1) = ctx->r3;
    // 0x8005C110: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C114: sw          $zero, -0x1B34($at)
    MEM_W(-0X1B34, ctx->r1) = 0;
    // 0x8005C118: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C11C: sh          $zero, -0x2354($at)
    MEM_H(-0X2354, ctx->r1) = 0;
    // 0x8005C120: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C124: sh          $zero, -0x2352($at)
    MEM_H(-0X2352, ctx->r1) = 0;
    // 0x8005C128: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C12C: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8005C130: lw          $t4, -0x537C($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X537C));
    // 0x8005C134: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    // 0x8005C138: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8005C13C: jal         0x800BB580
    // 0x8005C140: sw          $t4, -0x3C7C($at)
    MEM_W(-0X3C7C, ctx->r1) = ctx->r12;
    osGetTime_recomp(rdram, ctx);
        goto after_14;
    // 0x8005C140: sw          $t4, -0x3C7C($at)
    MEM_W(-0X3C7C, ctx->r1) = ctx->r12;
    after_14:
    // 0x8005C144: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C148: sw          $v0, -0x1B18($at)
    MEM_W(-0X1B18, ctx->r1) = ctx->r2;
    // 0x8005C14C: sw          $v1, -0x1B14($at)
    MEM_W(-0X1B14, ctx->r1) = ctx->r3;
    // 0x8005C150: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C154: jal         0x80062314
    // 0x8005C158: sw          $zero, -0x2994($at)
    MEM_W(-0X2994, ctx->r1) = 0;
    func_80062314(rdram, ctx);
        goto after_15;
    // 0x8005C158: sw          $zero, -0x2994($at)
    MEM_W(-0X2994, ctx->r1) = 0;
    after_15:
    // 0x8005C15C: jal         0x800BB580
    // 0x8005C160: nop

    osGetTime_recomp(rdram, ctx);
        goto after_16;
    // 0x8005C160: nop

    after_16:
    // 0x8005C164: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C168: sw          $v0, -0x1A78($at)
    MEM_W(-0X1A78, ctx->r1) = ctx->r2;
    // 0x8005C16C: sw          $v1, -0x1A74($at)
    MEM_W(-0X1A74, ctx->r1) = ctx->r3;
    // 0x8005C170: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C174: sw          $zero, -0x1B34($at)
    MEM_W(-0X1B34, ctx->r1) = 0;
    // 0x8005C178: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C17C: sh          $zero, -0x2354($at)
    MEM_H(-0X2354, ctx->r1) = 0;
    // 0x8005C180: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C184: sh          $zero, -0x2352($at)
    MEM_H(-0X2352, ctx->r1) = 0;
    // 0x8005C188: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C18C: jal         0x800BB580
    // 0x8005C190: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    osGetTime_recomp(rdram, ctx);
        goto after_17;
    // 0x8005C190: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    after_17:
    // 0x8005C194: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C198: sw          $v0, -0x1B10($at)
    MEM_W(-0X1B10, ctx->r1) = ctx->r2;
    // 0x8005C19C: jal         0x800624B4
    // 0x8005C1A0: sw          $v1, -0x1B0C($at)
    MEM_W(-0X1B0C, ctx->r1) = ctx->r3;
    func_800624B4(rdram, ctx);
        goto after_18;
    // 0x8005C1A0: sw          $v1, -0x1B0C($at)
    MEM_W(-0X1B0C, ctx->r1) = ctx->r3;
    after_18:
    // 0x8005C1A4: jal         0x800BB580
    // 0x8005C1A8: nop

    osGetTime_recomp(rdram, ctx);
        goto after_19;
    // 0x8005C1A8: nop

    after_19:
    // 0x8005C1AC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C1B0: sw          $v0, -0x1A70($at)
    MEM_W(-0X1A70, ctx->r1) = ctx->r2;
    // 0x8005C1B4: sw          $v1, -0x1A6C($at)
    MEM_W(-0X1A6C, ctx->r1) = ctx->r3;
    // 0x8005C1B8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C1BC: sw          $zero, -0x1B34($at)
    MEM_W(-0X1B34, ctx->r1) = 0;
    // 0x8005C1C0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C1C4: sh          $zero, -0x2354($at)
    MEM_H(-0X2354, ctx->r1) = 0;
    // 0x8005C1C8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C1CC: sh          $zero, -0x2352($at)
    MEM_H(-0X2352, ctx->r1) = 0;
    // 0x8005C1D0: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8005C1D4: lw          $t5, -0x14C0($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X14C0));
    // 0x8005C1D8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C1DC: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    // 0x8005C1E0: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8005C1E4: bne         $t5, $at, L_8005C24C
    if (ctx->r13 != ctx->r1) {
        // 0x8005C1E8: lui         $t6, 0x802B
        ctx->r14 = S32(0X802B << 16);
            goto L_8005C24C;
    }
    // 0x8005C1E8: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x8005C1EC: lw          $t6, -0x5440($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X5440));
    // 0x8005C1F0: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8005C1F4: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x8005C1F8: bne         $t6, $zero, L_8005C24C
    if (ctx->r14 != 0) {
        // 0x8005C1FC: addiu       $a2, $zero, 0x2000
        ctx->r6 = ADD32(0, 0X2000);
            goto L_8005C24C;
    }
    // 0x8005C1FC: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x8005C200: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x8005C204: lw          $a3, -0x13EC($a3)
    ctx->r7 = S32(MEM_W(ctx->r7, -0X13EC));
    // 0x8005C208: lw          $a0, -0x13F4($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X13F4));
    // 0x8005C20C: jal         0x8005669C
    // 0x8005C210: lw          $a1, -0x13F0($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X13F0));
    func_8005669C(rdram, ctx);
        goto after_20;
    // 0x8005C210: lw          $a1, -0x13F0($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X13F0));
    after_20:
    // 0x8005C214: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8005C218: lui         $t8, 0xBD00
    ctx->r24 = S32(0XBD00 << 16);
    // 0x8005C21C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C220: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005C224: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005C228: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005C22C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005C230: sw          $zero, -0x1B34($at)
    MEM_W(-0X1B34, ctx->r1) = 0;
    // 0x8005C234: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C238: sh          $zero, -0x2354($at)
    MEM_H(-0X2354, ctx->r1) = 0;
    // 0x8005C23C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C240: sh          $zero, -0x2352($at)
    MEM_H(-0X2352, ctx->r1) = 0;
    // 0x8005C244: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005C248: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
L_8005C24C:
    // 0x8005C24C: jal         0x80060C40
    // 0x8005C250: nop

    func_80060C40(rdram, ctx);
        goto after_21;
    // 0x8005C250: nop

    after_21:
    // 0x8005C254: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8005C258: lui         $t0, 0xBD00
    ctx->r8 = S32(0XBD00 << 16);
    // 0x8005C25C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005C260: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005C264: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005C268: jal         0x800651C0
    // 0x8005C26C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    func_800651C0(rdram, ctx);
        goto after_22;
    // 0x8005C26C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_22:
    // 0x8005C270: jal         0x80065458
    // 0x8005C274: nop

    func_80065458(rdram, ctx);
        goto after_23;
    // 0x8005C274: nop

    after_23:
    // 0x8005C278: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8005C27C: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8005C280: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005C284: jr          $ra
    // 0x8005C288: nop

    return;
    // 0x8005C288: nop

;}
RECOMP_FUNC void divscale20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800915D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800915D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800915DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800915E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800915E4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x800915E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800915EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800915F0: jal         0x800BB834
    // 0x800915F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800915F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800915F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800915FC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091600: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091604: jal         0x800BB89C
    // 0x80091608: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091608: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x8009160C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091614: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091618: jr          $ra
    // 0x8009161C: nop

    return;
    // 0x8009161C: nop

;}
RECOMP_FUNC void alUnlink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF770: lw          $v0, 0x0($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800BF774: beql        $v0, $zero, L_800BF788
    if (ctx->r2 == 0) {
        // 0x800BF778: lw          $v0, 0x4($a0)
        ctx->r2 = S32(MEM_W(ctx->r4, 0X4));
            goto L_800BF788;
    }
    goto skip_0;
    // 0x800BF778: lw          $v0, 0x4($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X4));
    skip_0:
    // 0x800BF77C: lw          $t6, 0x4($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800BF780: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800BF784: lw          $v0, 0x4($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X4));
L_800BF788:
    // 0x800BF788: beq         $v0, $zero, L_800BF798
    if (ctx->r2 == 0) {
        // 0x800BF78C: nop
    
            goto L_800BF798;
    }
    // 0x800BF78C: nop

    // 0x800BF790: lw          $t7, 0x0($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800BF794: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800BF798:
    // 0x800BF798: jr          $ra
    // 0x800BF79C: nop

    return;
    // 0x800BF79C: nop

;}
