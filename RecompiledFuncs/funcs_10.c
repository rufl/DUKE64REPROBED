#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void alSeqTicksToSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D03AC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800D03B0: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800D03B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D03B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D03BC: bgez        $a2, L_800D03D0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800D03C0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800D03D0;
    }
    // 0x800D03C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D03C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D03C8: nop

    // 0x800D03CC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800D03D0:
    // 0x800D03D0: lh          $t6, 0x18($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X18));
    // 0x800D03D4: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D03D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800D03DC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800D03E0: ldc1        $f10, -0x5E78($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X5E78);
    // 0x800D03E4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D03E8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800D03EC: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x800D03F0: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800D03F4: div.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f18.d);
    // 0x800D03F8: jr          $ra
    // 0x800D03FC: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    return;
    // 0x800D03FC: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
;}
RECOMP_FUNC void rotatesprite_simple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A64: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x80065A68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80065A6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80065A70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80065A74: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80065A78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80065A7C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80065A80: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80065A84: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80065A88: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80065A8C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80065A90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80065A94: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80065A98: sw          $a2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r6;
    // 0x80065A9C: andi        $s1, $a2, 0xFFFF
    ctx->r17 = ctx->r6 & 0XFFFF;
    // 0x80065AA0: jal         0x8006370C
    // 0x80065AA4: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    gettileid(rdram, ctx);
        goto after_0;
    // 0x80065AA4: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    after_0:
    // 0x80065AA8: addiu       $s3, $zero, 0x1C
    ctx->r19 = ADD32(0, 0X1C);
    // 0x80065AAC: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065AB0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80065AB4: addiu       $s2, $s2, -0x5010
    ctx->r18 = ADD32(ctx->r18, -0X5010);
    // 0x80065AB8: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x80065ABC: mflo        $t7
    ctx->r15 = lo;
    // 0x80065AC0: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x80065AC4: lw          $t9, 0x8($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X8));
    // 0x80065AC8: andi        $t6, $t9, 0xC0
    ctx->r14 = ctx->r25 & 0XC0;
    // 0x80065ACC: beql        $t6, $zero, L_80065B00
    if (ctx->r14 == 0) {
        // 0x80065AD0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80065B00;
    }
    goto skip_0;
    // 0x80065AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80065AD4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80065AD8: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80065ADC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80065AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065AE4: jal         0x8009223C
    // 0x80065AE8: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
    animateoffs(rdram, ctx);
        goto after_1;
    // 0x80065AE8: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
    after_1:
    // 0x80065AEC: lhu         $a2, 0x12A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X12A);
    // 0x80065AF0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80065AF4: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x80065AF8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80065AFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80065B00:
    // 0x80065B00: beql        $a2, $at, L_80066144
    if (ctx->r6 == ctx->r1) {
        // 0x80065B04: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_80066144;
    }
    goto skip_1;
    // 0x80065B04: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_1:
    // 0x80065B08: multu       $a2, $s3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065B0C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x80065B10: sh          $a2, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r6;
    // 0x80065B14: mflo        $t9
    ctx->r25 = lo;
    // 0x80065B18: addu        $fp, $s2, $t9
    ctx->r30 = ADD32(ctx->r18, ctx->r25);
    // 0x80065B1C: lh          $v1, 0xC($fp)
    ctx->r3 = S32(MEM_H(ctx->r30, 0XC));
    // 0x80065B20: lhu         $v0, 0x12($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X12);
    // 0x80065B24: lhu         $a1, 0x14($fp)
    ctx->r5 = MEM_HU(ctx->r30, 0X14);
    // 0x80065B28: addu        $t6, $v1, $s0
    ctx->r14 = ADD32(ctx->r3, ctx->r16);
    // 0x80065B2C: sll         $t7, $v0, 10
    ctx->r15 = S32(ctx->r2 << 10);
    // 0x80065B30: div         $zero, $t7, $v1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r3)));
    // 0x80065B34: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
    // 0x80065B38: mflo        $t8
    ctx->r24 = lo;
    // 0x80065B3C: lh          $t6, 0xE($fp)
    ctx->r14 = S32(MEM_H(ctx->r30, 0XE));
    // 0x80065B40: sll         $t9, $a1, 10
    ctx->r25 = S32(ctx->r5 << 10);
    // 0x80065B44: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x80065B48: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x80065B4C: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    // 0x80065B50: bne         $v1, $zero, L_80065B5C
    if (ctx->r3 != 0) {
        // 0x80065B54: nop
    
            goto L_80065B5C;
    }
    // 0x80065B54: nop

    // 0x80065B58: break       7
    do_break(2147900248);
L_80065B5C:
    // 0x80065B5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065B60: bne         $v1, $at, L_80065B74
    if (ctx->r3 != ctx->r1) {
        // 0x80065B64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065B74;
    }
    // 0x80065B64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065B68: bne         $t7, $at, L_80065B74
    if (ctx->r15 != ctx->r1) {
        // 0x80065B6C: nop
    
            goto L_80065B74;
    }
    // 0x80065B6C: nop

    // 0x80065B70: break       6
    do_break(2147900272);
L_80065B74:
    // 0x80065B74: mflo        $t7
    ctx->r15 = lo;
    // 0x80065B78: sw          $t7, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r15;
    // 0x80065B7C: bne         $t6, $zero, L_80065B88
    if (ctx->r14 != 0) {
        // 0x80065B80: nop
    
            goto L_80065B88;
    }
    // 0x80065B80: nop

    // 0x80065B84: break       7
    do_break(2147900292);
L_80065B88:
    // 0x80065B88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065B8C: bne         $t6, $at, L_80065BA0
    if (ctx->r14 != ctx->r1) {
        // 0x80065B90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065BA0;
    }
    // 0x80065B90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065B94: bne         $t9, $at, L_80065BA0
    if (ctx->r25 != ctx->r1) {
        // 0x80065B98: nop
    
            goto L_80065BA0;
    }
    // 0x80065B98: nop

    // 0x80065B9C: break       6
    do_break(2147900316);
L_80065BA0:
    // 0x80065BA0: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065BA4: mflo        $a3
    ctx->r7 = lo;
    // 0x80065BA8: addiu       $t1, $a3, 0xFFF
    ctx->r9 = ADD32(ctx->r7, 0XFFF);
    // 0x80065BAC: bgez        $t1, L_80065BBC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80065BB0: sra         $t8, $t1, 12
        ctx->r24 = S32(SIGNED(ctx->r9) >> 12);
            goto L_80065BBC;
    }
    // 0x80065BB0: sra         $t8, $t1, 12
    ctx->r24 = S32(SIGNED(ctx->r9) >> 12);
    // 0x80065BB4: addiu       $at, $t1, 0xFFF
    ctx->r1 = ADD32(ctx->r9, 0XFFF);
    // 0x80065BB8: sra         $t8, $at, 12
    ctx->r24 = S32(SIGNED(ctx->r1) >> 12);
L_80065BBC:
    // 0x80065BBC: sw          $t8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r24;
    // 0x80065BC0: jal         0x80063880
    // 0x80065BC4: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    func_80063880(rdram, ctx);
        goto after_2;
    // 0x80065BC4: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    after_2:
    // 0x80065BC8: lw          $t1, 0x64($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X64));
    // 0x80065BCC: lhu         $a1, 0x14($fp)
    ctx->r5 = MEM_HU(ctx->r30, 0X14);
    // 0x80065BD0: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80065BD4: addiu       $t2, $t2, 0x4418
    ctx->r10 = ADD32(ctx->r10, 0X4418);
    // 0x80065BD8: div         $zero, $a1, $t1
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r9)));
    // 0x80065BDC: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065BE0: lh          $t3, 0xE($fp)
    ctx->r11 = S32(MEM_H(ctx->r30, 0XE));
    // 0x80065BE4: lhu         $a2, 0x12A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X12A);
    // 0x80065BE8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80065BEC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80065BF0: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80065BF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80065BF8: mflo        $s7
    ctx->r23 = lo;
    // 0x80065BFC: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    // 0x80065C00: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80065C04: addiu       $s3, $v0, 0x20
    ctx->r19 = ADD32(ctx->r2, 0X20);
    // 0x80065C08: bne         $t1, $zero, L_80065C14
    if (ctx->r9 != 0) {
        // 0x80065C0C: nop
    
            goto L_80065C14;
    }
    // 0x80065C0C: nop

    // 0x80065C10: break       7
    do_break(2147900432);
L_80065C14:
    // 0x80065C14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065C18: bne         $t1, $at, L_80065C2C
    if (ctx->r9 != ctx->r1) {
        // 0x80065C1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065C2C;
    }
    // 0x80065C1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065C20: bne         $a1, $at, L_80065C2C
    if (ctx->r5 != ctx->r1) {
        // 0x80065C24: nop
    
            goto L_80065C2C;
    }
    // 0x80065C24: nop

    // 0x80065C28: break       6
    do_break(2147900456);
L_80065C2C:
    // 0x80065C2C: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x80065C30: sw          $t9, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r25;
    // 0x80065C34: sw          $t4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r12;
    // 0x80065C38: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80065C3C: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
    // 0x80065C40: jal         0x80063880
    // 0x80065C44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80063880(rdram, ctx);
        goto after_3;
    // 0x80065C44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80065C48: lw          $t5, 0xC8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80065C4C: lw          $t1, 0x64($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X64));
    // 0x80065C50: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80065C54: lw          $t3, 0xE8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x80065C58: lw          $t4, 0xE4($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XE4));
    // 0x80065C5C: addiu       $t2, $t2, 0x4418
    ctx->r10 = ADD32(ctx->r10, 0X4418);
    // 0x80065C60: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x80065C64: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065C68: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x80065C6C: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x80065C70: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80065C74: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80065C78: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80065C7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80065C80: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80065C84: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065C88: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80065C8C: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x80065C90: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80065C94: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80065C98: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80065C9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80065CA0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80065CA4: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065CA8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80065CAC: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80065CB0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80065CB4: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80065CB8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80065CBC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80065CC0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80065CC4: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065CC8: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x80065CCC: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80065CD0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80065CD4: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80065CD8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80065CDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80065CE0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80065CE4: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065CE8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80065CEC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80065CF0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80065CF4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80065CF8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80065CFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80065D00: blez        $t1, L_80066140
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80065D04: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_80066140;
    }
    // 0x80065D04: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80065D08: div         $zero, $t3, $t1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r9)));
    // 0x80065D0C: lw          $v0, 0xD4($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XD4));
    // 0x80065D10: or          $ra, $s0, $zero
    ctx->r31 = ctx->r16 | 0;
    // 0x80065D14: mflo        $s6
    ctx->r22 = lo;
    // 0x80065D18: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80065D1C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x80065D20: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80065D24: bgez        $v0, L_80065D34
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80065D28: sra         $t5, $v0, 4
        ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
            goto L_80065D34;
    }
    // 0x80065D28: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80065D2C: addiu       $at, $v0, 0xF
    ctx->r1 = ADD32(ctx->r2, 0XF);
    // 0x80065D30: sra         $t5, $at, 4
    ctx->r13 = S32(SIGNED(ctx->r1) >> 4);
L_80065D34:
    // 0x80065D34: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80065D38: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80065D3C: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x80065D40: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80065D44: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80065D48: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80065D4C: lw          $t6, 0x114($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80065D50: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80065D54: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x80065D58: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80065D5C: lw          $t8, 0x108($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X108));
    // 0x80065D60: sll         $t7, $t6, 18
    ctx->r15 = S32(ctx->r14 << 18);
    // 0x80065D64: lw          $t6, 0x10C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X10C));
    // 0x80065D68: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80065D6C: sra         $s5, $t7, 16
    ctx->r21 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80065D70: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80065D74: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80065D78: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80065D7C: sll         $t8, $ra, 18
    ctx->r24 = S32(ctx->r31 << 18);
    // 0x80065D80: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80065D84: or          $ra, $t7, $zero
    ctx->r31 = ctx->r15 | 0;
    // 0x80065D88: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80065D8C: bne         $t1, $zero, L_80065D98
    if (ctx->r9 != 0) {
        // 0x80065D90: nop
    
            goto L_80065D98;
    }
    // 0x80065D90: nop

    // 0x80065D94: break       7
    do_break(2147900820);
L_80065D98:
    // 0x80065D98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065D9C: bne         $t1, $at, L_80065DB0
    if (ctx->r9 != ctx->r1) {
        // 0x80065DA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065DB0;
    }
    // 0x80065DA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065DA4: bne         $t3, $at, L_80065DB0
    if (ctx->r11 != ctx->r1) {
        // 0x80065DA8: nop
    
            goto L_80065DB0;
    }
    // 0x80065DA8: nop

    // 0x80065DAC: break       6
    do_break(2147900844);
L_80065DB0:
    // 0x80065DB0: slt         $at, $s1, $s7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r23) ? 1 : 0;
L_80065DB4:
    // 0x80065DB4: beq         $at, $zero, L_80065DC4
    if (ctx->r1 == 0) {
        // 0x80065DB8: or          $t0, $s7, $zero
        ctx->r8 = ctx->r23 | 0;
            goto L_80065DC4;
    }
    // 0x80065DB8: or          $t0, $s7, $zero
    ctx->r8 = ctx->r23 | 0;
    // 0x80065DBC: b           L_80065DC4
    // 0x80065DC0: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
        goto L_80065DC4;
    // 0x80065DC0: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
L_80065DC4:
    // 0x80065DC4: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065DC8: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x80065DCC: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x80065DD0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80065DD4: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80065DD8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80065DDC: sw          $s3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r19;
    // 0x80065DE0: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065DE4: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x80065DE8: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80065DEC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80065DF0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80065DF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80065DF8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80065DFC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80065E00: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065E04: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80065E08: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80065E0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80065E10: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80065E14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80065E18: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80065E1C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80065E20: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065E24: subu        $s1, $s1, $t0
    ctx->r17 = SUB32(ctx->r17, ctx->r8);
    // 0x80065E28: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80065E2C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80065E30: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80065E34: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80065E38: lw          $t6, 0xD4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XD4));
    // 0x80065E3C: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x80065E40: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80065E44: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065E48: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x80065E4C: mflo        $a2
    ctx->r6 = lo;
    // 0x80065E50: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x80065E54: sra         $t8, $a2, 2
    ctx->r24 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80065E58: addiu       $a2, $t8, -0x1
    ctx->r6 = ADD32(ctx->r24, -0X1);
    // 0x80065E5C: slti        $at, $a2, 0x7FF
    ctx->r1 = SIGNED(ctx->r6) < 0X7FF ? 1 : 0;
    // 0x80065E60: beq         $at, $zero, L_80065E70
    if (ctx->r1 == 0) {
        // 0x80065E64: nop
    
            goto L_80065E70;
    }
    // 0x80065E64: nop

    // 0x80065E68: b           L_80065E70
    // 0x80065E6C: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
        goto L_80065E70;
    // 0x80065E6C: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
L_80065E70:
    // 0x80065E70: bgtz        $t5, L_80065E80
    if (SIGNED(ctx->r13) > 0) {
        // 0x80065E74: nop
    
            goto L_80065E80;
    }
    // 0x80065E74: nop

    // 0x80065E78: b           L_80065E80
    // 0x80065E7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80065E80;
    // 0x80065E7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80065E80:
    // 0x80065E80: bgtz        $t5, L_80065E90
    if (SIGNED(ctx->r13) > 0) {
        // 0x80065E84: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_80065E90;
    }
    // 0x80065E84: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x80065E88: b           L_80065E90
    // 0x80065E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80065E90;
    // 0x80065E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80065E90:
    // 0x80065E90: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x80065E94: bne         $v0, $zero, L_80065EA0
    if (ctx->r2 != 0) {
        // 0x80065E98: nop
    
            goto L_80065EA0;
    }
    // 0x80065E98: nop

    // 0x80065E9C: break       7
    do_break(2147901084);
L_80065EA0:
    // 0x80065EA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80065EA4: bne         $v0, $at, L_80065EB8
    if (ctx->r2 != ctx->r1) {
        // 0x80065EA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80065EB8;
    }
    // 0x80065EA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80065EAC: bne         $t7, $at, L_80065EB8
    if (ctx->r15 != ctx->r1) {
        // 0x80065EB0: nop
    
            goto L_80065EB8;
    }
    // 0x80065EB0: nop

    // 0x80065EB4: break       6
    do_break(2147901108);
L_80065EB8:
    // 0x80065EB8: mflo        $t9
    ctx->r25 = lo;
    // 0x80065EBC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80065EC0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80065EC4: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x80065EC8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80065ECC: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80065ED0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80065ED4: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80065ED8: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065EDC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80065EE0: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80065EE4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80065EE8: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80065EEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80065EF0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80065EF4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80065EF8: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065EFC: lw          $t6, 0x5C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x80065F00: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80065F04: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80065F08: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80065F0C: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80065F10: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80065F14: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80065F18: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80065F1C: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065F20: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80065F24: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x80065F28: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80065F2C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80065F30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80065F34: lw          $t6, 0x58($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80065F38: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80065F3C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80065F40: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80065F44: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80065F48: lhu         $t8, 0x12($fp)
    ctx->r24 = MEM_HU(ctx->r30, 0X12);
    // 0x80065F4C: sll         $a0, $t4, 16
    ctx->r4 = S32(ctx->r12 << 16);
    // 0x80065F50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80065F54: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065F58: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80065F5C: mflo        $t6
    ctx->r14 = lo;
    // 0x80065F60: bgez        $t6, L_80065F70
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80065F64: sra         $t9, $t6, 1
        ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80065F70;
    }
    // 0x80065F64: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80065F68: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80065F6C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80065F70:
    // 0x80065F70: bgez        $t9, L_80065F80
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80065F74: sra         $t7, $t9, 2
        ctx->r15 = S32(SIGNED(ctx->r25) >> 2);
            goto L_80065F80;
    }
    // 0x80065F74: sra         $t7, $t9, 2
    ctx->r15 = S32(SIGNED(ctx->r25) >> 2);
    // 0x80065F78: addiu       $at, $t9, 0x3
    ctx->r1 = ADD32(ctx->r25, 0X3);
    // 0x80065F7C: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_80065F80:
    // 0x80065F80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80065F84: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80065F88: beq         $at, $zero, L_80065F98
    if (ctx->r1 == 0) {
        // 0x80065F8C: addu        $s3, $s3, $t8
        ctx->r19 = ADD32(ctx->r19, ctx->r24);
            goto L_80065F98;
    }
    // 0x80065F8C: addu        $s3, $s3, $t8
    ctx->r19 = ADD32(ctx->r19, ctx->r24);
    // 0x80065F90: b           L_80065F98
    // 0x80065F94: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_80065F98;
    // 0x80065F94: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_80065F98:
    // 0x80065F98: lw          $a1, 0x0($t2)
    ctx->r5 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80065F9C: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x80065FA0: addu        $t0, $t4, $v0
    ctx->r8 = ADD32(ctx->r12, ctx->r2);
    // 0x80065FA4: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80065FA8: blez        $s5, L_80065FB8
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80065FAC: sw          $t6, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r14;
            goto L_80065FB8;
    }
    // 0x80065FAC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80065FB0: b           L_80065FB8
    // 0x80065FB4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
        goto L_80065FB8;
    // 0x80065FB4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
L_80065FB8:
    // 0x80065FB8: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x80065FBC: sra         $t9, $v1, 16
    ctx->r25 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80065FC0: blez        $t9, L_80065FD0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80065FC4: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_80065FD0;
    }
    // 0x80065FC4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80065FC8: b           L_80065FD4
    // 0x80065FCC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80065FD4;
    // 0x80065FCC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80065FD0:
    // 0x80065FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065FD4:
    // 0x80065FD4: andi        $t7, $v0, 0xFFF
    ctx->r15 = ctx->r2 & 0XFFF;
    // 0x80065FD8: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x80065FDC: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80065FE0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80065FE4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80065FE8: blez        $ra, L_80065FF8
    if (SIGNED(ctx->r31) <= 0) {
        // 0x80065FEC: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_80065FF8;
    }
    // 0x80065FEC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80065FF0: b           L_80065FFC
    // 0x80065FF4: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
        goto L_80065FFC;
    // 0x80065FF4: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
L_80065FF8:
    // 0x80065FF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80065FFC:
    // 0x80065FFC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80066000: blez        $t6, L_80066010
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80066004: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80066010;
    }
    // 0x80066004: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80066008: b           L_80066014
    // 0x8006600C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066014;
    // 0x8006600C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80066010:
    // 0x80066010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066014:
    // 0x80066014: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x80066018: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8006601C: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x80066020: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80066024: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80066028: lw          $a2, 0x0($t2)
    ctx->r6 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8006602C: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80066030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80066034: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80066038: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8006603C: bgez        $ra, L_80066090
    if (SIGNED(ctx->r31) >= 0) {
        // 0x80066040: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_80066090;
    }
    // 0x80066040: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80066044: lh          $v0, 0x10E($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X10E));
    // 0x80066048: multu       $ra, $v0
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006604C: mflo        $v1
    ctx->r3 = lo;
    // 0x80066050: sra         $t7, $v1, 7
    ctx->r15 = S32(SIGNED(ctx->r3) >> 7);
    // 0x80066054: bgez        $v0, L_80066074
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80066058: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80066074;
    }
    // 0x80066058: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8006605C: blez        $t7, L_8006606C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80066060: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006606C;
    }
    // 0x80066060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80066064: b           L_80066090
    // 0x80066068: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80066090;
    // 0x80066068: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8006606C:
    // 0x8006606C: b           L_80066090
    // 0x80066070: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80066090;
    // 0x80066070: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80066074:
    // 0x80066074: bgez        $v1, L_80066084
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80066078: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80066084;
    }
    // 0x80066078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006607C: b           L_80066084
    // 0x80066080: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80066084;
    // 0x80066080: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80066084:
    // 0x80066084: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80066088: b           L_80066090
    // 0x8006608C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80066090;
    // 0x8006608C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80066090:
    // 0x80066090: bgez        $t4, L_800660F8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80066094: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800660F8;
    }
    // 0x80066094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80066098: lh          $v1, 0x10A($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X10A));
    // 0x8006609C: bgez        $v1, L_800660CC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800660A0: nop
    
            goto L_800660CC;
    }
    // 0x800660A0: nop

    // 0x800660A4: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800660A8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800660AC: mflo        $v0
    ctx->r2 = lo;
    // 0x800660B0: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800660B4: blez        $t6, L_800660C4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800660B8: nop
    
            goto L_800660C4;
    }
    // 0x800660B8: nop

    // 0x800660BC: b           L_800660F8
    // 0x800660C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800660F8;
    // 0x800660C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800660C4:
    // 0x800660C4: b           L_800660F8
    // 0x800660C8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800660F8;
    // 0x800660C8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800660CC:
    // 0x800660CC: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800660D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800660D4: mflo        $v0
    ctx->r2 = lo;
    // 0x800660D8: sra         $t9, $v0, 7
    ctx->r25 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800660DC: bgez        $t9, L_800660EC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800660E0: nop
    
            goto L_800660EC;
    }
    // 0x800660E0: nop

    // 0x800660E4: b           L_800660EC
    // 0x800660E8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
        goto L_800660EC;
    // 0x800660E8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800660EC:
    // 0x800660EC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800660F0: b           L_800660F8
    // 0x800660F4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_800660F8;
    // 0x800660F4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800660F8:
    // 0x800660F8: negu        $t8, $v0
    ctx->r24 = SUB32(0, ctx->r2);
    // 0x800660FC: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80066100: negu        $t9, $a1
    ctx->r25 = SUB32(0, ctx->r5);
    // 0x80066104: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80066108: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8006610C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80066110: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80066114: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80066118: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8006611C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80066120: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80066124: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80066128: lw          $t8, 0x44($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8006612C: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80066130: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80066134: lw          $t6, 0x100($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X100));
    // 0x80066138: bnel        $s4, $t6, L_80065DB4
    if (ctx->r20 != ctx->r14) {
        // 0x8006613C: slt         $at, $s1, $s7
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r23) ? 1 : 0;
            goto L_80065DB4;
    }
    goto skip_2;
    // 0x8006613C: slt         $at, $s1, $s7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r23) ? 1 : 0;
    skip_2:
L_80066140:
    // 0x80066140: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_80066144:
    // 0x80066144: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80066148: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8006614C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80066150: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80066154: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80066158: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8006615C: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80066160: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80066164: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80066168: jr          $ra
    // 0x8006616C: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x8006616C: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void checkavailinven(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075878: lh          $t6, 0x2DA($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X2DA));
    // 0x8007587C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80075880: blezl       $t6, L_80075894
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80075884: lh          $t8, 0x320($a0)
        ctx->r24 = S32(MEM_H(ctx->r4, 0X320));
            goto L_80075894;
    }
    goto skip_0;
    // 0x80075884: lh          $t8, 0x320($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X320));
    skip_0:
    // 0x80075888: jr          $ra
    // 0x8007588C: sb          $t7, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r15;
    return;
    // 0x8007588C: sb          $t7, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r15;
    // 0x80075890: lh          $t8, 0x320($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X320));
L_80075894:
    // 0x80075894: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80075898: blezl       $t8, L_800758AC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007589C: lh          $t0, 0x2BC($a0)
        ctx->r8 = S32(MEM_H(ctx->r4, 0X2BC));
            goto L_800758AC;
    }
    goto skip_1;
    // 0x8007589C: lh          $t0, 0x2BC($a0)
    ctx->r8 = S32(MEM_H(ctx->r4, 0X2BC));
    skip_1:
    // 0x800758A0: jr          $ra
    // 0x800758A4: sb          $t9, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r25;
    return;
    // 0x800758A4: sb          $t9, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r25;
    // 0x800758A8: lh          $t0, 0x2BC($a0)
    ctx->r8 = S32(MEM_H(ctx->r4, 0X2BC));
L_800758AC:
    // 0x800758AC: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800758B0: blezl       $t0, L_800758C4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800758B4: lh          $t2, 0x31E($a0)
        ctx->r10 = S32(MEM_H(ctx->r4, 0X31E));
            goto L_800758C4;
    }
    goto skip_2;
    // 0x800758B4: lh          $t2, 0x31E($a0)
    ctx->r10 = S32(MEM_H(ctx->r4, 0X31E));
    skip_2:
    // 0x800758B8: jr          $ra
    // 0x800758BC: sb          $t1, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r9;
    return;
    // 0x800758BC: sb          $t1, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r9;
    // 0x800758C0: lh          $t2, 0x31E($a0)
    ctx->r10 = S32(MEM_H(ctx->r4, 0X31E));
L_800758C4:
    // 0x800758C4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800758C8: blezl       $t2, L_800758DC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800758CC: lh          $t4, 0x2EC($a0)
        ctx->r12 = S32(MEM_H(ctx->r4, 0X2EC));
            goto L_800758DC;
    }
    goto skip_3;
    // 0x800758CC: lh          $t4, 0x2EC($a0)
    ctx->r12 = S32(MEM_H(ctx->r4, 0X2EC));
    skip_3:
    // 0x800758D0: jr          $ra
    // 0x800758D4: sb          $t3, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r11;
    return;
    // 0x800758D4: sb          $t3, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r11;
    // 0x800758D8: lh          $t4, 0x2EC($a0)
    ctx->r12 = S32(MEM_H(ctx->r4, 0X2EC));
L_800758DC:
    // 0x800758DC: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800758E0: blezl       $t4, L_800758F4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800758E4: lh          $t6, 0x31C($a0)
        ctx->r14 = S32(MEM_H(ctx->r4, 0X31C));
            goto L_800758F4;
    }
    goto skip_4;
    // 0x800758E4: lh          $t6, 0x31C($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X31C));
    skip_4:
    // 0x800758E8: jr          $ra
    // 0x800758EC: sb          $t5, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r13;
    return;
    // 0x800758EC: sb          $t5, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r13;
    // 0x800758F0: lh          $t6, 0x31C($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X31C));
L_800758F4:
    // 0x800758F4: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800758F8: blezl       $t6, L_8007590C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800758FC: lh          $t8, 0x332($a0)
        ctx->r24 = S32(MEM_H(ctx->r4, 0X332));
            goto L_8007590C;
    }
    goto skip_5;
    // 0x800758FC: lh          $t8, 0x332($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X332));
    skip_5:
    // 0x80075900: jr          $ra
    // 0x80075904: sb          $t7, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r15;
    return;
    // 0x80075904: sb          $t7, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r15;
    // 0x80075908: lh          $t8, 0x332($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X332));
L_8007590C:
    // 0x8007590C: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80075910: blezl       $t8, L_80075924
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80075914: lh          $t0, 0x322($a0)
        ctx->r8 = S32(MEM_H(ctx->r4, 0X322));
            goto L_80075924;
    }
    goto skip_6;
    // 0x80075914: lh          $t0, 0x322($a0)
    ctx->r8 = S32(MEM_H(ctx->r4, 0X322));
    skip_6:
    // 0x80075918: jr          $ra
    // 0x8007591C: sb          $t9, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r25;
    return;
    // 0x8007591C: sb          $t9, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r25;
    // 0x80075920: lh          $t0, 0x322($a0)
    ctx->r8 = S32(MEM_H(ctx->r4, 0X322));
L_80075924:
    // 0x80075924: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80075928: blezl       $t0, L_8007593C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8007592C: sb          $zero, 0x33F($a0)
        MEM_B(0X33F, ctx->r4) = 0;
            goto L_8007593C;
    }
    goto skip_7;
    // 0x8007592C: sb          $zero, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = 0;
    skip_7:
    // 0x80075930: jr          $ra
    // 0x80075934: sb          $t1, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r9;
    return;
    // 0x80075934: sb          $t1, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = ctx->r9;
    // 0x80075938: sb          $zero, 0x33F($a0)
    MEM_B(0X33F, ctx->r4) = 0;
L_8007593C:
    // 0x8007593C: jr          $ra
    // 0x80075940: nop

    return;
    // 0x80075940: nop

;}
RECOMP_FUNC void animatetip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073048: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007304C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80073050: addiu       $t7, $t7, -0x17D0
    ctx->r15 = ADD32(ctx->r15, -0X17D0);
    // 0x80073054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80073058: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8007305C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80073060: addiu       $t2, $t7, 0x24
    ctx->r10 = ADD32(ctx->r15, 0X24);
    // 0x80073064: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
L_80073068:
    // 0x80073068: lw          $at, 0x0($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X0));
    // 0x8007306C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80073070: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80073074: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80073078: lw          $at, -0x8($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, -0X8));
    // 0x8007307C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80073080: lw          $at, -0x4($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, -0X4));
    // 0x80073084: bne         $t7, $t2, L_80073068
    if (ctx->r15 != ctx->r10) {
        // 0x80073088: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80073068;
    }
    // 0x80073088: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8007308C: lw          $at, 0x0($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X0));
    // 0x80073090: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x80073094: addiu       $t5, $t5, 0x5770
    ctx->r13 = ADD32(ctx->r13, 0X5770);
    // 0x80073098: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8007309C: lhu         $at, 0x4($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X4);
    // 0x800730A0: sh          $at, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r1;
    // 0x800730A4: lh          $t3, 0x5E($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X5E));
    // 0x800730A8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800730AC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800730B0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800730B4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800730B8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800730BC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800730C0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800730C4: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x800730C8: lh          $t9, 0x2B6($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X2B6));
    // 0x800730CC: bnel        $t9, $zero, L_800730E0
    if (ctx->r25 != 0) {
        // 0x800730D0: lh          $a0, 0x28A($v1)
        ctx->r4 = S32(MEM_H(ctx->r3, 0X28A));
            goto L_800730E0;
    }
    goto skip_0;
    // 0x800730D0: lh          $a0, 0x28A($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X28A));
    skip_0:
    // 0x800730D4: b           L_800731CC
    // 0x800730D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800731CC;
    // 0x800730D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800730DC: lh          $a0, 0x28A($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X28A));
L_800730E0:
    // 0x800730E0: jal         0x80091A38
    // 0x800730E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    klabs(rdram, ctx);
        goto after_0;
    // 0x800730E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x800730E8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800730EC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800730F0: lw          $v1, 0x24($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800730F4: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x800730F8: addiu       $t2, $t2, -0x1988
    ctx->r10 = ADD32(ctx->r10, -0X1988);
    // 0x800730FC: lh          $t9, 0x288($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X288));
    // 0x80073100: lbu         $t6, 0x364($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X364);
    // 0x80073104: mflo        $t7
    ctx->r15 = lo;
    // 0x80073108: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007310C: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80073110: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80073114: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    // 0x80073118: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x8007311C: lh          $t6, 0x18($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X18));
    // 0x80073120: subu        $t1, $t7, $t3
    ctx->r9 = SUB32(ctx->r15, ctx->r11);
    // 0x80073124: sll         $t4, $t1, 16
    ctx->r12 = S32(ctx->r9 << 16);
    // 0x80073128: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007312C: bne         $t6, $at, L_8007313C
    if (ctx->r14 != ctx->r1) {
        // 0x80073130: sra         $t1, $t4, 16
        ctx->r9 = S32(SIGNED(ctx->r12) >> 16);
            goto L_8007313C;
    }
    // 0x80073130: sra         $t1, $t4, 16
    ctx->r9 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80073134: b           L_80073140
    // 0x80073138: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80073140;
    // 0x80073138: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8007313C:
    // 0x8007313C: lbu         $t0, 0x27($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X27);
L_80073140:
    // 0x80073140: lh          $t7, 0x5E($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X5E));
    // 0x80073144: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x80073148: lh          $t9, 0x28A($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X28A));
    // 0x8007314C: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80073150: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x80073154: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80073158: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007315C: lb          $t4, 0x5600($t4)
    ctx->r12 = S32(MEM_B(ctx->r12, 0X5600));
    // 0x80073160: lh          $v0, 0x2B6($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X2B6));
    // 0x80073164: lw          $t2, 0x220($v1)
    ctx->r10 = S32(MEM_W(ctx->r3, 0X220));
    // 0x80073168: lh          $t6, 0x2B8($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0X2B8));
    // 0x8007316C: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x80073170: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80073174: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x80073178: addu        $t9, $sp, $t4
    ctx->r25 = ADD32(ctx->r29, ctx->r12);
    // 0x8007317C: lh          $t9, 0x28($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X28));
    // 0x80073180: subu        $t7, $t2, $t6
    ctx->r15 = SUB32(ctx->r10, ctx->r14);
    // 0x80073184: addiu       $t2, $zero, 0x1A
    ctx->r10 = ADD32(0, 0X1A);
    // 0x80073188: subu        $a0, $t5, $t8
    ctx->r4 = SUB32(ctx->r13, ctx->r24);
    // 0x8007318C: subu        $a2, $t2, $v0
    ctx->r6 = SUB32(ctx->r10, ctx->r2);
    // 0x80073190: sra         $t6, $a2, 4
    ctx->r14 = S32(SIGNED(ctx->r6) >> 4);
    // 0x80073194: sra         $t3, $t7, 4
    ctx->r11 = S32(SIGNED(ctx->r15) >> 4);
    // 0x80073198: sra         $t5, $t9, 1
    ctx->r13 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8007319C: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x800731A0: addiu       $a2, $t6, 0xA10
    ctx->r6 = ADD32(ctx->r14, 0XA10);
    // 0x800731A4: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x800731A8: subu        $a1, $t8, $t3
    ctx->r5 = SUB32(ctx->r24, ctx->r11);
    // 0x800731AC: addiu       $a1, $a1, 0xF0
    ctx->r5 = ADD32(ctx->r5, 0XF0);
    // 0x800731B0: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800731B4: addiu       $a0, $a0, 0xAA
    ctx->r4 = ADD32(ctx->r4, 0XAA);
    // 0x800731B8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800731BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800731C0: jal         0x800724B0
    // 0x800731C4: lb          $a3, 0x5B($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0X5B));
    myospal(rdram, ctx);
        goto after_1;
    // 0x800731C4: lb          $a3, 0x5B($sp)
    ctx->r7 = S32(MEM_B(ctx->r29, 0X5B));
    after_1:
    // 0x800731C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800731CC:
    // 0x800731CC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800731D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800731D4: jr          $ra
    // 0x800731D8: nop

    return;
    // 0x800731D8: nop

;}
RECOMP_FUNC void setupgfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BB84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004BB88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004BB8C: jal         0x8004BA4C
    // 0x8004BB90: nop

    set_gfxdata(rdram, ctx);
        goto after_0;
    // 0x8004BB90: nop

    after_0:
    // 0x8004BB94: jal         0x8004B704
    // 0x8004BB98: nop

    func_8004B704(rdram, ctx);
        goto after_1;
    // 0x8004BB98: nop

    after_1:
    // 0x8004BB9C: jal         0x8004B7D4
    // 0x8004BBA0: nop

    func_8004B7D4(rdram, ctx);
        goto after_2;
    // 0x8004BBA0: nop

    after_2:
    // 0x8004BBA4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004BBA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004BBAC: jr          $ra
    // 0x8004BBB0: nop

    return;
    // 0x8004BBB0: nop

;}
RECOMP_FUNC void func_8004B7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B7D4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8004B7D8: addiu       $a3, $a3, 0x4418
    ctx->r7 = ADD32(ctx->r7, 0X4418);
    // 0x8004B7DC: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8004B7E0: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8004B7E4: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x8004B7E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8004B7EC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8004B7F0: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x8004B7F4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8004B7F8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8004B7FC: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8004B800: lui         $t0, 0xFF10
    ctx->r8 = S32(0XFF10 << 16);
    // 0x8004B804: ori         $t0, $t0, 0x13F
    ctx->r8 = ctx->r8 | 0X13F;
    // 0x8004B808: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8004B80C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8004B810: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8004B814: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8004B818: lw          $t1, 0x36F0($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, 0X36F0));
    // 0x8004B81C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004B820: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8004B824: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004B828: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8004B82C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8004B830: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8004B834: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8004B838: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8004B83C: sll         $t2, $t2, 11
    ctx->r10 = S32(ctx->r10 << 11);
    // 0x8004B840: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8004B844: addiu       $t4, $t4, 0x400
    ctx->r12 = ADD32(ctx->r12, 0X400);
    // 0x8004B848: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004B84C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8004B850: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8004B854: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x8004B858: ori         $t8, $t8, 0x1
    ctx->r24 = ctx->r24 | 0X1;
    // 0x8004B85C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8004B860: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8004B864: lui         $t7, 0xF700
    ctx->r15 = S32(0XF700 << 16);
    // 0x8004B868: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8004B86C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8004B870: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8004B874: lui         $t0, 0xF64F
    ctx->r8 = S32(0XF64F << 16);
    // 0x8004B878: ori         $t0, $t0, 0xC3BC
    ctx->r8 = ctx->r8 | 0XC3BC;
    // 0x8004B87C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8004B880: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8004B884: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8004B888: jr          $ra
    // 0x8004B88C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    return;
    // 0x8004B88C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void ms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C68: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80076C6C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80076C70: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x80076C74: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80076C78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80076C7C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80076C80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076C84: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80076C88: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x80076C8C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80076C90: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x80076C94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076C98: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
    // 0x80076C9C: lh          $v1, 0x14($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0X14));
    // 0x80076CA0: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x80076CA4: addiu       $t1, $t1, -0x9A0
    ctx->r9 = ADD32(ctx->r9, -0X9A0);
    // 0x80076CA8: addiu       $t2, $v1, 0x200
    ctx->r10 = ADD32(ctx->r3, 0X200);
    // 0x80076CAC: andi        $t3, $t2, 0x7FF
    ctx->r11 = ctx->r10 & 0X7FF;
    // 0x80076CB0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80076CB4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80076CB8: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80076CBC: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x80076CC0: lh          $v0, 0x18($s3)
    ctx->r2 = S32(MEM_H(ctx->r19, 0X18));
    // 0x80076CC4: andi        $t4, $v1, 0x7FF
    ctx->r12 = ctx->r3 & 0X7FF;
    // 0x80076CC8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80076CCC: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80076CD0: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x80076CD4: lw          $t9, 0x0($s3)
    ctx->r25 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80076CD8: sll         $t4, $s0, 3
    ctx->r12 = S32(ctx->r16 << 3);
    // 0x80076CDC: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80076CE0: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x80076CE4: lw          $t3, 0x4($s3)
    ctx->r11 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80076CE8: addiu       $t5, $t5, -0x5C00
    ctx->r13 = ADD32(ctx->r13, -0X5C00);
    // 0x80076CEC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80076CF0: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80076CF4: mflo        $t7
    ctx->r15 = lo;
    // 0x80076CF8: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x80076CFC: lh          $t7, 0x0($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X0));
    // 0x80076D00: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x80076D04: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x80076D08: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80076D0C: lw          $s6, 0x38($t0)
    ctx->r22 = S32(MEM_W(ctx->r8, 0X38));
    // 0x80076D10: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80076D14: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80076D18: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80076D1C: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80076D20: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80076D24: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80076D28: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80076D2C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80076D30: mflo        $t9
    ctx->r25 = lo;
    // 0x80076D34: sra         $t8, $t9, 14
    ctx->r24 = S32(SIGNED(ctx->r25) >> 14);
    // 0x80076D38: addu        $a3, $t3, $t8
    ctx->r7 = ADD32(ctx->r11, ctx->r24);
    // 0x80076D3C: sw          $a3, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r7;
    // 0x80076D40: lw          $s7, 0x34($t0)
    ctx->r23 = S32(MEM_W(ctx->r8, 0X34));
    // 0x80076D44: lw          $a2, 0x0($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80076D48: lhu         $a0, 0x10($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X10);
    // 0x80076D4C: jal         0x8005ADFC
    // 0x80076D50: andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    ms_update(rdram, ctx);
        goto after_0;
    // 0x80076D50: andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    after_0:
    // 0x80076D54: lh          $t6, 0x10($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80076D58: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80076D5C: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x80076D60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80076D64: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80076D68: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80076D6C: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x80076D70: lh          $v0, 0x8($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X8));
    // 0x80076D74: lh          $t3, 0xA($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0XA));
    // 0x80076D78: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x80076D7C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80076D80: addu        $s4, $t3, $v0
    ctx->r20 = ADD32(ctx->r11, ctx->r2);
    // 0x80076D84: sll         $t8, $s4, 16
    ctx->r24 = S32(ctx->r20 << 16);
    // 0x80076D88: sra         $s4, $t8, 16
    ctx->r20 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80076D8C: sra         $t4, $s0, 16
    ctx->r12 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80076D90: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80076D94: beq         $at, $zero, L_80076E2C
    if (ctx->r1 == 0) {
        // 0x80076D98: or          $s0, $t4, $zero
        ctx->r16 = ctx->r12 | 0;
            goto L_80076E2C;
    }
    // 0x80076D98: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80076D9C: sll         $v0, $s7, 2
    ctx->r2 = S32(ctx->r23 << 2);
    // 0x80076DA0: andi        $s5, $s6, 0x7FF
    ctx->r21 = ctx->r22 & 0X7FF;
    // 0x80076DA4: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x80076DA8: addiu       $t6, $t6, -0x1900
    ctx->r14 = ADD32(ctx->r14, -0X1900);
    // 0x80076DAC: sll         $t7, $s5, 16
    ctx->r15 = S32(ctx->r21 << 16);
    // 0x80076DB0: addiu       $t5, $t5, -0x2900
    ctx->r13 = ADD32(ctx->r13, -0X2900);
    // 0x80076DB4: addu        $s1, $v0, $t5
    ctx->r17 = ADD32(ctx->r2, ctx->r13);
    // 0x80076DB8: sra         $s5, $t7, 16
    ctx->r21 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80076DBC: addu        $s2, $v0, $t6
    ctx->r18 = ADD32(ctx->r2, ctx->r14);
    // 0x80076DC0: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x80076DC4: addiu       $s7, $sp, 0x68
    ctx->r23 = ADD32(ctx->r29, 0X68);
L_80076DC8:
    // 0x80076DC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80076DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80076DD0: lw          $a2, 0x0($s1)
    ctx->r6 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80076DD4: lw          $a3, 0x0($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80076DD8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80076DDC: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80076DE0: jal         0x80097F04
    // 0x80076DE4: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    rotatepoint(rdram, ctx);
        goto after_1;
    // 0x80076DE4: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    after_1:
    // 0x80076DE8: lw          $t8, 0x0($s3)
    ctx->r24 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80076DEC: lw          $t2, 0x6C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x80076DF0: lw          $t4, 0x4($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80076DF4: lw          $t5, 0x68($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X68));
    // 0x80076DF8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80076DFC: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80076E00: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80076E04: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    // 0x80076E08: jal         0x8009562C
    // 0x80076E0C: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    dragpoint(rdram, ctx);
        goto after_2;
    // 0x80076E0C: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x80076E10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80076E14: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x80076E18: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80076E1C: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80076E20: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80076E24: bne         $at, $zero, L_80076DC8
    if (ctx->r1 != 0) {
        // 0x80076E28: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80076DC8;
    }
    // 0x80076E28: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80076E2C:
    // 0x80076E2C: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80076E30: lw          $s0, 0x24($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80076E34: lw          $s1, 0x28($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80076E38: lw          $s2, 0x2C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80076E3C: lw          $s3, 0x30($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80076E40: lw          $s4, 0x34($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80076E44: lw          $s5, 0x38($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80076E48: lw          $s6, 0x3C($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80076E4C: lw          $s7, 0x40($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80076E50: jr          $ra
    // 0x80076E54: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80076E54: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void inside(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E14: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80091E18: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80091E1C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80091E20: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80091E24: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80091E28: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80091E2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80091E30: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80091E34: bltz        $t7, L_80091E58
    if (SIGNED(ctx->r15) < 0) {
        // 0x80091E38: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80091E58;
    }
    // 0x80091E38: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80091E3C: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x80091E40: lh          $t8, -0x5378($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X5378));
    // 0x80091E44: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80091E48: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x80091E4C: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80091E50: bne         $at, $zero, L_80091E60
    if (ctx->r1 != 0) {
        // 0x80091E54: sll         $t9, $t9, 4
        ctx->r25 = S32(ctx->r25 << 4);
            goto L_80091E60;
    }
    // 0x80091E54: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
L_80091E58:
    // 0x80091E58: b           L_80092014
    // 0x80091E5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80092014;
    // 0x80091E5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80091E60:
    // 0x80091E60: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80091E64: addiu       $t6, $t6, -0x1988
    ctx->r14 = ADD32(ctx->r14, -0X1988);
    // 0x80091E68: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x80091E6C: lh          $t7, 0x8($a0)
    ctx->r15 = S32(MEM_H(ctx->r4, 0X8));
    // 0x80091E70: addiu       $s1, $zero, 0x24
    ctx->r17 = ADD32(0, 0X24);
    // 0x80091E74: lh          $a1, 0xA($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0XA));
    // 0x80091E78: multu       $t7, $s1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091E7C: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80091E80: addiu       $t5, $t5, 0x61A8
    ctx->r13 = ADD32(ctx->r13, 0X61A8);
    // 0x80091E84: andi        $a0, $a1, 0x1
    ctx->r4 = ctx->r5 & 0X1;
    // 0x80091E88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80091E8C: mflo        $t8
    ctx->r24 = lo;
    // 0x80091E90: addu        $v0, $t5, $t8
    ctx->r2 = ADD32(ctx->r13, ctx->r24);
    // 0x80091E94: beql        $zero, $a0, L_80091F1C
    if (0 == ctx->r4) {
        // 0x80091E98: lh          $t9, 0x8($v0)
        ctx->r25 = S32(MEM_H(ctx->r2, 0X8));
            goto L_80091F1C;
    }
    goto skip_0;
    // 0x80091E98: lh          $t9, 0x8($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X8));
    skip_0:
    // 0x80091E9C: lh          $t6, 0x8($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X8));
    // 0x80091EA0: lw          $t9, 0x4($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80091EA4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80091EA8: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091EAC: subu        $a2, $t9, $a3
    ctx->r6 = SUB32(ctx->r25, ctx->r7);
    // 0x80091EB0: mflo        $t7
    ctx->r15 = lo;
    // 0x80091EB4: addu        $t1, $t5, $t7
    ctx->r9 = ADD32(ctx->r13, ctx->r15);
    // 0x80091EB8: lw          $t8, 0x4($t1)
    ctx->r24 = S32(MEM_W(ctx->r9, 0X4));
    // 0x80091EBC: subu        $t2, $t8, $a3
    ctx->r10 = SUB32(ctx->r24, ctx->r7);
    // 0x80091EC0: xor         $t9, $a2, $t2
    ctx->r25 = ctx->r6 ^ ctx->r10;
    // 0x80091EC4: bgez        $t9, L_80091F10
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80091EC8: nop
    
            goto L_80091F10;
    }
    // 0x80091EC8: nop

    // 0x80091ECC: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80091ED0: lw          $t7, 0x0($t1)
    ctx->r15 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80091ED4: subu        $t0, $t6, $s0
    ctx->r8 = SUB32(ctx->r14, ctx->r16);
    // 0x80091ED8: subu        $t4, $t7, $s0
    ctx->r12 = SUB32(ctx->r15, ctx->r16);
    // 0x80091EDC: xor         $t8, $t0, $t4
    ctx->r24 = ctx->r8 ^ ctx->r12;
    // 0x80091EE0: bltz        $t8, L_80091EF0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80091EE4: nop
    
            goto L_80091EF0;
    }
    // 0x80091EE4: nop

    // 0x80091EE8: b           L_80091F10
    // 0x80091EEC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80091F10;
    // 0x80091EEC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80091EF0:
    // 0x80091EF0: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091EF4: mflo        $t9
    ctx->r25 = lo;
    // 0x80091EF8: nop

    // 0x80091EFC: nop

    // 0x80091F00: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091F04: mflo        $t6
    ctx->r14 = lo;
    // 0x80091F08: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x80091F0C: xor         $v1, $t7, $t2
    ctx->r3 = ctx->r15 ^ ctx->r10;
L_80091F10:
    // 0x80091F10: beq         $a1, $zero, L_80092010
    if (ctx->r5 == 0) {
        // 0x80091F14: addiu       $v0, $v0, 0x24
        ctx->r2 = ADD32(ctx->r2, 0X24);
            goto L_80092010;
    }
    // 0x80091F14: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
L_80091F18:
    // 0x80091F18: lh          $t9, 0x8($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X8));
L_80091F1C:
    // 0x80091F1C: lw          $t8, 0x4($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80091F20: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x80091F24: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091F28: subu        $a2, $t8, $a3
    ctx->r6 = SUB32(ctx->r24, ctx->r7);
    // 0x80091F2C: mflo        $t6
    ctx->r14 = lo;
    // 0x80091F30: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x80091F34: lw          $t7, 0x4($t1)
    ctx->r15 = S32(MEM_W(ctx->r9, 0X4));
    // 0x80091F38: subu        $t2, $t7, $a3
    ctx->r10 = SUB32(ctx->r15, ctx->r7);
    // 0x80091F3C: xor         $t8, $a2, $t2
    ctx->r24 = ctx->r6 ^ ctx->r10;
    // 0x80091F40: bgezl       $t8, L_80091F94
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80091F44: lh          $t9, 0x2C($v0)
        ctx->r25 = S32(MEM_H(ctx->r2, 0X2C));
            goto L_80091F94;
    }
    goto skip_1;
    // 0x80091F44: lh          $t9, 0x2C($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X2C));
    skip_1:
    // 0x80091F48: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80091F4C: lw          $t6, 0x0($t1)
    ctx->r14 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80091F50: subu        $t0, $t9, $s0
    ctx->r8 = SUB32(ctx->r25, ctx->r16);
    // 0x80091F54: subu        $t4, $t6, $s0
    ctx->r12 = SUB32(ctx->r14, ctx->r16);
    // 0x80091F58: xor         $t7, $t0, $t4
    ctx->r15 = ctx->r8 ^ ctx->r12;
    // 0x80091F5C: bltz        $t7, L_80091F6C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80091F60: nop
    
            goto L_80091F6C;
    }
    // 0x80091F60: nop

    // 0x80091F64: b           L_80091F90
    // 0x80091F68: xor         $v1, $v1, $t0
    ctx->r3 = ctx->r3 ^ ctx->r8;
        goto L_80091F90;
    // 0x80091F68: xor         $v1, $v1, $t0
    ctx->r3 = ctx->r3 ^ ctx->r8;
L_80091F6C:
    // 0x80091F6C: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091F70: mflo        $t8
    ctx->r24 = lo;
    // 0x80091F74: nop

    // 0x80091F78: nop

    // 0x80091F7C: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091F80: mflo        $t9
    ctx->r25 = lo;
    // 0x80091F84: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x80091F88: xor         $t7, $t6, $t2
    ctx->r15 = ctx->r14 ^ ctx->r10;
    // 0x80091F8C: xor         $v1, $v1, $t7
    ctx->r3 = ctx->r3 ^ ctx->r15;
L_80091F90:
    // 0x80091F90: lh          $t9, 0x2C($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X2C));
L_80091F94:
    // 0x80091F94: lw          $t8, 0x28($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X28));
    // 0x80091F98: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
    // 0x80091F9C: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091FA0: subu        $a2, $t8, $a3
    ctx->r6 = SUB32(ctx->r24, ctx->r7);
    // 0x80091FA4: mflo        $t6
    ctx->r14 = lo;
    // 0x80091FA8: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x80091FAC: lw          $t7, 0x4($t1)
    ctx->r15 = S32(MEM_W(ctx->r9, 0X4));
    // 0x80091FB0: subu        $t2, $t7, $a3
    ctx->r10 = SUB32(ctx->r15, ctx->r7);
    // 0x80091FB4: xor         $t8, $a2, $t2
    ctx->r24 = ctx->r6 ^ ctx->r10;
    // 0x80091FB8: bgez        $t8, L_80092008
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80091FBC: nop
    
            goto L_80092008;
    }
    // 0x80091FBC: nop

    // 0x80091FC0: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80091FC4: lw          $t6, 0x0($t1)
    ctx->r14 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80091FC8: subu        $t0, $t9, $s0
    ctx->r8 = SUB32(ctx->r25, ctx->r16);
    // 0x80091FCC: subu        $t4, $t6, $s0
    ctx->r12 = SUB32(ctx->r14, ctx->r16);
    // 0x80091FD0: xor         $t7, $t0, $t4
    ctx->r15 = ctx->r8 ^ ctx->r12;
    // 0x80091FD4: bltz        $t7, L_80091FE4
    if (SIGNED(ctx->r15) < 0) {
        // 0x80091FD8: nop
    
            goto L_80091FE4;
    }
    // 0x80091FD8: nop

    // 0x80091FDC: b           L_80092008
    // 0x80091FE0: xor         $v1, $v1, $t0
    ctx->r3 = ctx->r3 ^ ctx->r8;
        goto L_80092008;
    // 0x80091FE0: xor         $v1, $v1, $t0
    ctx->r3 = ctx->r3 ^ ctx->r8;
L_80091FE4:
    // 0x80091FE4: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091FE8: mflo        $t8
    ctx->r24 = lo;
    // 0x80091FEC: nop

    // 0x80091FF0: nop

    // 0x80091FF4: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091FF8: mflo        $t9
    ctx->r25 = lo;
    // 0x80091FFC: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x80092000: xor         $t7, $t6, $t2
    ctx->r15 = ctx->r14 ^ ctx->r10;
    // 0x80092004: xor         $v1, $v1, $t7
    ctx->r3 = ctx->r3 ^ ctx->r15;
L_80092008:
    // 0x80092008: bne         $a1, $zero, L_80091F18
    if (ctx->r5 != 0) {
        // 0x8009200C: addiu       $v0, $v0, 0x24
        ctx->r2 = ADD32(ctx->r2, 0X24);
            goto L_80091F18;
    }
    // 0x8009200C: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
L_80092010:
    // 0x80092010: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
L_80092014:
    // 0x80092014: lw          $s0, 0x8($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X8));
    // 0x80092018: lw          $s1, 0xC($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XC));
    // 0x8009201C: jr          $ra
    // 0x80092020: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80092020: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void gameplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D950: lui         $a3, 0x802A
    ctx->r7 = S32(0X802A << 16);
    // 0x8004D954: addiu       $a3, $a3, 0x5770
    ctx->r7 = ADD32(ctx->r7, 0X5770);
    // 0x8004D958: lbu         $t6, 0x338($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X338);
    // 0x8004D95C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D964: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8004D968: beq         $t7, $zero, L_8004D980
    if (ctx->r15 == 0) {
        // 0x8004D96C: nop
    
            goto L_8004D980;
    }
    // 0x8004D96C: nop

    // 0x8004D970: jal         0x800998D4
    // 0x8004D974: nop

    domovethings(rdram, ctx);
        goto after_0;
    // 0x8004D974: nop

    after_0:
    // 0x8004D978: lui         $a3, 0x802A
    ctx->r7 = S32(0X802A << 16);
    // 0x8004D97C: addiu       $a3, $a3, 0x5770
    ctx->r7 = ADD32(ctx->r7, 0X5770);
L_8004D980:
    // 0x8004D980: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x8004D984: addiu       $t2, $t2, -0x5598
    ctx->r10 = ADD32(ctx->r10, -0X5598);
    // 0x8004D988: lw          $a2, 0x18C($t2)
    ctx->r6 = S32(MEM_W(ctx->r10, 0X18C));
    // 0x8004D98C: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8004D990: bnel        $at, $zero, L_8004DB84
    if (ctx->r1 != 0) {
        // 0x8004D994: lbu         $a1, 0x338($a3)
        ctx->r5 = MEM_BU(ctx->r7, 0X338);
            goto L_8004DB84;
    }
    goto skip_0;
    // 0x8004D994: lbu         $a1, 0x338($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X338);
    skip_0:
    // 0x8004D998: lw          $t8, 0x13C($t2)
    ctx->r24 = S32(MEM_W(ctx->r10, 0X13C));
    // 0x8004D99C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8004D9A0: bnel        $t8, $zero, L_8004DB84
    if (ctx->r24 != 0) {
        // 0x8004D9A4: lbu         $a1, 0x338($a3)
        ctx->r5 = MEM_BU(ctx->r7, 0X338);
            goto L_8004DB84;
    }
    goto skip_1;
    // 0x8004D9A4: lbu         $a1, 0x338($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X338);
    skip_1:
    // 0x8004D9A8: lbu         $t1, 0x378C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X378C);
    // 0x8004D9AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004D9B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D9B4: bne         $t1, $at, L_8004DA00
    if (ctx->r9 != ctx->r1) {
        // 0x8004D9B8: addiu       $v0, $v0, 0x3780
        ctx->r2 = ADD32(ctx->r2, 0X3780);
            goto L_8004DA00;
    }
    // 0x8004D9B8: addiu       $v0, $v0, 0x3780
    ctx->r2 = ADD32(ctx->r2, 0X3780);
    // 0x8004D9BC: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8004D9C0: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x8004D9C4: bne         $t3, $zero, L_8004DA00
    if (ctx->r11 != 0) {
        // 0x8004D9C8: sw          $t3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r11;
            goto L_8004DA00;
    }
    // 0x8004D9C8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8004D9CC: blez        $a2, L_8004DA00
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004D9D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004DA00;
    }
    // 0x8004D9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004D9D4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8004D9D8: addiu       $v1, $zero, 0x38C
    ctx->r3 = ADD32(0, 0X38C);
L_8004D9DC:
    // 0x8004D9DC: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D9E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004D9E4: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8004D9E8: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004D9EC: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8004D9F0: mflo        $t5
    ctx->r13 = lo;
    // 0x8004D9F4: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x8004D9F8: bne         $at, $zero, L_8004D9DC
    if (ctx->r1 != 0) {
        // 0x8004D9FC: sh          $a0, 0x2F0($t6)
        MEM_H(0X2F0, ctx->r14) = ctx->r4;
            goto L_8004D9DC;
    }
    // 0x8004D9FC: sh          $a0, 0x2F0($t6)
    MEM_H(0X2F0, ctx->r14) = ctx->r4;
L_8004DA00:
    // 0x8004DA00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004DA04: bne         $t1, $at, L_8004DA90
    if (ctx->r9 != ctx->r1) {
        // 0x8004DA08: addiu       $v1, $zero, 0x38C
        ctx->r3 = ADD32(0, 0X38C);
            goto L_8004DA90;
    }
    // 0x8004DA08: addiu       $v1, $zero, 0x38C
    ctx->r3 = ADD32(0, 0X38C);
    // 0x8004DA0C: lh          $t9, 0x2F0($a3)
    ctx->r25 = S32(MEM_H(ctx->r7, 0X2F0));
    // 0x8004DA10: bnel        $t9, $zero, L_8004DA94
    if (ctx->r25 != 0) {
        // 0x8004DA14: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8004DA94;
    }
    goto skip_2;
    // 0x8004DA14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_2:
    // 0x8004DA18: blez        $a2, L_8004DA90
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004DA1C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004DA90;
    }
    // 0x8004DA1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004DA20: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8004DA24: lh          $t0, 0x3788($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X3788));
    // 0x8004DA28: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
L_8004DA2C:
    // 0x8004DA2C: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004DA30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004DA34: mflo        $t3
    ctx->r11 = lo;
    // 0x8004DA38: addu        $v0, $a3, $t3
    ctx->r2 = ADD32(ctx->r7, ctx->r11);
    // 0x8004DA3C: lh          $t4, 0x2AE($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X2AE));
    // 0x8004DA40: lh          $t5, 0x2B0($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X2B0));
    // 0x8004DA44: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8004DA48: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004DA4C: bne         $at, $zero, L_8004DA80
    if (ctx->r1 != 0) {
        // 0x8004DA50: sll         $t4, $a0, 16
        ctx->r12 = S32(ctx->r4 << 16);
            goto L_8004DA80;
    }
    // 0x8004DA50: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x8004DA54: blez        $a2, L_8004DA80
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004DA58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004DA80;
    }
    // 0x8004DA58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004DA5C:
    // 0x8004DA5C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004DA60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004DA64: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8004DA68: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004DA6C: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8004DA70: mflo        $t7
    ctx->r15 = lo;
    // 0x8004DA74: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8004DA78: bne         $at, $zero, L_8004DA5C
    if (ctx->r1 != 0) {
        // 0x8004DA7C: sh          $a1, 0x2F0($t8)
        MEM_H(0X2F0, ctx->r24) = ctx->r5;
            goto L_8004DA5C;
    }
    // 0x8004DA7C: sh          $a1, 0x2F0($t8)
    MEM_H(0X2F0, ctx->r24) = ctx->r5;
L_8004DA80:
    // 0x8004DA80: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004DA84: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8004DA88: bne         $at, $zero, L_8004DA2C
    if (ctx->r1 != 0) {
        // 0x8004DA8C: nop
    
            goto L_8004DA2C;
    }
    // 0x8004DA8C: nop

L_8004DA90:
    // 0x8004DA90: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8004DA94:
    // 0x8004DA94: bne         $t1, $at, L_8004DB80
    if (ctx->r9 != ctx->r1) {
        // 0x8004DA98: addiu       $a1, $zero, 0x3C
        ctx->r5 = ADD32(0, 0X3C);
            goto L_8004DB80;
    }
    // 0x8004DA98: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8004DA9C: lh          $t6, 0x2F0($a3)
    ctx->r14 = S32(MEM_H(ctx->r7, 0X2F0));
    // 0x8004DAA0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004DAA4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8004DAA8: bne         $t6, $zero, L_8004DB80
    if (ctx->r14 != 0) {
        // 0x8004DAAC: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_8004DB80;
    }
    // 0x8004DAAC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8004DAB0: blez        $a2, L_8004DAF8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004DAB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004DAF8;
    }
    // 0x8004DAB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004DAB8:
    // 0x8004DAB8: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004DABC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004DAC0: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x8004DAC4: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004DAC8: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8004DACC: mflo        $t7
    ctx->r15 = lo;
    // 0x8004DAD0: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8004DAD4: lh          $t9, 0x28C($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X28C));
    // 0x8004DAD8: blez        $t9, L_8004DAEC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8004DADC: nop
    
            goto L_8004DAEC;
    }
    // 0x8004DADC: nop

    // 0x8004DAE0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004DAE4: sll         $t3, $t0, 16
    ctx->r11 = S32(ctx->r8 << 16);
    // 0x8004DAE8: sra         $t0, $t3, 16
    ctx->r8 = S32(SIGNED(ctx->r11) >> 16);
L_8004DAEC:
    // 0x8004DAEC: bne         $at, $zero, L_8004DAB8
    if (ctx->r1 != 0) {
        // 0x8004DAF0: nop
    
            goto L_8004DAB8;
    }
    // 0x8004DAF0: nop

    // 0x8004DAF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004DAF8:
    // 0x8004DAF8: lh          $a0, -0x9DC($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X9DC));
    // 0x8004DAFC: blezl       $a0, L_8004DB44
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004DB00: slti        $at, $t0, 0x2
        ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
            goto L_8004DB44;
    }
    goto skip_3;
    // 0x8004DB00: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    skip_3:
L_8004DB04:
    // 0x8004DB04: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004DB08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004DB0C: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x8004DB10: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004DB14: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004DB18: mflo        $t7
    ctx->r15 = lo;
    // 0x8004DB1C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8004DB20: lh          $t9, 0x28C($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X28C));
    // 0x8004DB24: blez        $t9, L_8004DB38
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8004DB28: nop
    
            goto L_8004DB38;
    }
    // 0x8004DB28: nop

    // 0x8004DB2C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8004DB30: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x8004DB34: sra         $t1, $t3, 16
    ctx->r9 = S32(SIGNED(ctx->r11) >> 16);
L_8004DB38:
    // 0x8004DB38: bne         $at, $zero, L_8004DB04
    if (ctx->r1 != 0) {
        // 0x8004DB3C: nop
    
            goto L_8004DB04;
    }
    // 0x8004DB3C: nop

    // 0x8004DB40: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
L_8004DB44:
    // 0x8004DB44: bne         $at, $zero, L_8004DB54
    if (ctx->r1 != 0) {
        // 0x8004DB48: nop
    
            goto L_8004DB54;
    }
    // 0x8004DB48: nop

    // 0x8004DB4C: bnel        $t1, $zero, L_8004DB84
    if (ctx->r9 != 0) {
        // 0x8004DB50: lbu         $a1, 0x338($a3)
        ctx->r5 = MEM_BU(ctx->r7, 0X338);
            goto L_8004DB84;
    }
    goto skip_4;
    // 0x8004DB50: lbu         $a1, 0x338($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X338);
    skip_4:
L_8004DB54:
    // 0x8004DB54: blez        $a2, L_8004DB80
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004DB58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004DB80;
    }
    // 0x8004DB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004DB5C:
    // 0x8004DB5C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004DB60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004DB64: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8004DB68: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004DB6C: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8004DB70: mflo        $t7
    ctx->r15 = lo;
    // 0x8004DB74: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8004DB78: bne         $at, $zero, L_8004DB5C
    if (ctx->r1 != 0) {
        // 0x8004DB7C: sh          $a1, 0x2F0($t8)
        MEM_H(0X2F0, ctx->r24) = ctx->r5;
            goto L_8004DB5C;
    }
    // 0x8004DB7C: sh          $a1, 0x2F0($t8)
    MEM_H(0X2F0, ctx->r24) = ctx->r5;
L_8004DB80:
    // 0x8004DB80: lbu         $a1, 0x338($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X338);
L_8004DB84:
    // 0x8004DB84: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8004DB88: addiu       $t0, $t0, -0x5B5C
    ctx->r8 = ADD32(ctx->r8, -0X5B5C);
    // 0x8004DB8C: andi        $v0, $a1, 0x8
    ctx->r2 = ctx->r5 & 0X8;
    // 0x8004DB90: bne         $v0, $zero, L_8004DBA4
    if (ctx->r2 != 0) {
        // 0x8004DB94: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8004DBA4;
    }
    // 0x8004DB94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8004DB98: andi        $t4, $a0, 0x20
    ctx->r12 = ctx->r4 & 0X20;
    // 0x8004DB9C: beql        $t4, $zero, L_8004DCAC
    if (ctx->r12 == 0) {
        // 0x8004DBA0: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8004DCAC;
    }
    goto skip_5;
    // 0x8004DBA0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_5:
L_8004DBA4:
    // 0x8004DBA4: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x8004DBA8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8004DBAC: bne         $at, $zero, L_8004DBBC
    if (ctx->r1 != 0) {
        // 0x8004DBB0: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_8004DBBC;
    }
    // 0x8004DBB0: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x8004DBB4: b           L_8004DCA8
    // 0x8004DBB8: sb          $t5, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r13;
        goto L_8004DCA8;
    // 0x8004DBB8: sb          $t5, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r13;
L_8004DBBC:
    // 0x8004DBBC: beq         $v0, $zero, L_8004DC30
    if (ctx->r2 == 0) {
        // 0x8004DBC0: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_8004DC30;
    }
    // 0x8004DBC0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004DBC4: lbu         $t6, 0x3758($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3758);
    // 0x8004DBC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004DBCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DBD0: beq         $t6, $zero, L_8004DC30
    if (ctx->r14 == 0) {
        // 0x8004DBD4: addiu       $t8, $zero, 0x7
        ctx->r24 = ADD32(0, 0X7);
            goto L_8004DC30;
    }
    // 0x8004DBD4: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8004DBD8: sb          $t7, 0x38B4($at)
    MEM_B(0X38B4, ctx->r1) = ctx->r15;
    // 0x8004DBDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DBE0: sb          $t8, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r24;
    // 0x8004DBE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DBE8: sb          $zero, 0x3758($at)
    MEM_B(0X3758, ctx->r1) = 0;
    // 0x8004DBEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DBF0: sh          $zero, 0x3774($at)
    MEM_H(0X3774, ctx->r1) = 0;
    // 0x8004DBF4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8004DBF8: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x8004DBFC: sh          $t9, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r25;
    // 0x8004DC00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC04: sb          $zero, 0x375C($at)
    MEM_B(0X375C, ctx->r1) = 0;
    // 0x8004DC08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DC0C: sh          $zero, -0x6B30($at)
    MEM_H(-0X6B30, ctx->r1) = 0;
    // 0x8004DC10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC14: jal         0x8005932C
    // 0x8004DC18: sh          $zero, 0x3778($at)
    MEM_H(0X3778, ctx->r1) = 0;
    stopallsounds(rdram, ctx);
        goto after_1;
    // 0x8004DC18: sh          $zero, 0x3778($at)
    MEM_H(0X3778, ctx->r1) = 0;
    after_1:
    // 0x8004DC1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004DC20: jal         0x80059398
    // 0x8004DC24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80059398(rdram, ctx);
        goto after_2;
    // 0x8004DC24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8004DC28: b           L_8004DCAC
    // 0x8004DC2C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8004DCAC;
    // 0x8004DC2C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004DC30:
    // 0x8004DC30: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8004DC34: bnel        $at, $zero, L_8004DC5C
    if (ctx->r1 != 0) {
        // 0x8004DC38: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8004DC5C;
    }
    goto skip_6;
    // 0x8004DC38: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_6:
    // 0x8004DC3C: lw          $t3, 0x13C($t2)
    ctx->r11 = S32(MEM_W(ctx->r10, 0X13C));
    // 0x8004DC40: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8004DC44: bnel        $t3, $zero, L_8004DC5C
    if (ctx->r11 != 0) {
        // 0x8004DC48: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8004DC5C;
    }
    goto skip_7;
    // 0x8004DC48: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_7:
    // 0x8004DC4C: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    // 0x8004DC50: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8004DC54: sb          $t4, 0x338($a3)
    MEM_B(0X338, ctx->r7) = ctx->r12;
    // 0x8004DC58: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_8004DC5C:
    // 0x8004DC5C: bne         $a0, $at, L_8004DC94
    if (ctx->r4 != ctx->r1) {
        // 0x8004DC60: nop
    
            goto L_8004DC94;
    }
    // 0x8004DC60: nop

    // 0x8004DC64: lh          $t5, 0x28C($a3)
    ctx->r13 = S32(MEM_H(ctx->r7, 0X28C));
    // 0x8004DC68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004DC6C: bgtz        $t5, L_8004DC94
    if (SIGNED(ctx->r13) > 0) {
        // 0x8004DC70: nop
    
            goto L_8004DC94;
    }
    // 0x8004DC70: nop

    // 0x8004DC74: bne         $a2, $at, L_8004DC94
    if (ctx->r6 != ctx->r1) {
        // 0x8004DC78: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_8004DC94;
    }
    // 0x8004DC78: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8004DC7C: lb          $t6, 0x1360($t6)
    ctx->r14 = S32(MEM_B(ctx->r14, 0X1360));
    // 0x8004DC80: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004DC84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC88: bne         $t6, $zero, L_8004DC94
    if (ctx->r14 != 0) {
        // 0x8004DC8C: nop
    
            goto L_8004DC94;
    }
    // 0x8004DC8C: nop

    // 0x8004DC90: sb          $t7, 0x377C($at)
    MEM_B(0X377C, ctx->r1) = ctx->r15;
L_8004DC94:
    // 0x8004DC94: jal         0x800AC4A4
    // 0x8004DC98: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    enterlevel(rdram, ctx);
        goto after_3;
    // 0x8004DC98: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_3:
    // 0x8004DC9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004DCA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DCA4: sb          $t8, 0x3758($at)
    MEM_B(0X3758, ctx->r1) = ctx->r24;
L_8004DCA8:
    // 0x8004DCA8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004DCAC:
    // 0x8004DCAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004DCB0: jr          $ra
    // 0x8004DCB4: nop

    return;
    // 0x8004DCB4: nop

;}
RECOMP_FUNC void func_80062D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D98: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80062D9C: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80062DA0: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80062DA4: slti        $at, $a3, 0x7F
    ctx->r1 = SIGNED(ctx->r7) < 0X7F ? 1 : 0;
    // 0x80062DA8: bne         $at, $zero, L_80062DB4
    if (ctx->r1 != 0) {
        // 0x80062DAC: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_80062DB4;
    }
    // 0x80062DAC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80062DB0: addiu       $a3, $zero, -0x7F
    ctx->r7 = ADD32(0, -0X7F);
L_80062DB4:
    // 0x80062DB4: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x80062DB8: subu        $t1, $t8, $a3
    ctx->r9 = SUB32(ctx->r24, ctx->r7);
    // 0x80062DBC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80062DC0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80062DC4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80062DC8: sra         $a3, $t3, 16
    ctx->r7 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80062DCC: slti        $at, $a3, 0x101
    ctx->r1 = SIGNED(ctx->r7) < 0X101 ? 1 : 0;
    // 0x80062DD0: bne         $at, $zero, L_80062DDC
    if (ctx->r1 != 0) {
        // 0x80062DD4: lui         $t5, 0x8022
        ctx->r13 = S32(0X8022 << 16);
            goto L_80062DDC;
    }
    // 0x80062DD4: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80062DD8: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
L_80062DDC:
    // 0x80062DDC: bgtz        $a3, L_80062DE8
    if (SIGNED(ctx->r7) > 0) {
        // 0x80062DE0: lui         $t7, 0x8022
        ctx->r15 = S32(0X8022 << 16);
            goto L_80062DE8;
    }
    // 0x80062DE0: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80062DE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80062DE8:
    // 0x80062DE8: lw          $t5, -0x19A0($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X19A0));
    // 0x80062DEC: bgez        $t5, L_80062DFC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80062DF0: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_80062DFC;
    }
    // 0x80062DF0: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80062DF4: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x80062DF8: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80062DFC:
    // 0x80062DFC: subu        $v0, $t6, $a0
    ctx->r2 = SUB32(ctx->r14, ctx->r4);
    // 0x80062E00: blez        $v0, L_80062E10
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80062E04: lui         $t5, 0x8022
        ctx->r13 = S32(0X8022 << 16);
            goto L_80062E10;
    }
    // 0x80062E04: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80062E08: b           L_80062E14
    // 0x80062E0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80062E14;
    // 0x80062E0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80062E10:
    // 0x80062E10: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80062E14:
    // 0x80062E14: lw          $t7, -0x199C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X199C));
    // 0x80062E18: bgez        $t7, L_80062E28
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80062E1C: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_80062E28;
    }
    // 0x80062E1C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80062E20: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x80062E24: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80062E28:
    // 0x80062E28: subu        $v0, $t8, $a1
    ctx->r2 = SUB32(ctx->r24, ctx->r5);
    // 0x80062E2C: blezl       $v0, L_80062E40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80062E30: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80062E40;
    }
    goto skip_0;
    // 0x80062E30: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    skip_0:
    // 0x80062E34: b           L_80062E40
    // 0x80062E38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80062E40;
    // 0x80062E38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80062E3C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_80062E40:
    // 0x80062E40: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80062E44: beql        $at, $zero, L_80062E58
    if (ctx->r1 == 0) {
        // 0x80062E48: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80062E58;
    }
    goto skip_1;
    // 0x80062E48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_1:
    // 0x80062E4C: b           L_80062E58
    // 0x80062E50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80062E58;
    // 0x80062E50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80062E54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80062E58:
    // 0x80062E58: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80062E5C: beq         $at, $zero, L_80062E6C
    if (ctx->r1 == 0) {
        // 0x80062E60: sra         $t2, $v0, 2
        ctx->r10 = S32(SIGNED(ctx->r2) >> 2);
            goto L_80062E6C;
    }
    // 0x80062E60: sra         $t2, $v0, 2
    ctx->r10 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80062E64: b           L_80062E70
    // 0x80062E68: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80062E70;
    // 0x80062E68: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80062E6C:
    // 0x80062E6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_80062E70:
    // 0x80062E70: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80062E74: beq         $at, $zero, L_80062E84
    if (ctx->r1 == 0) {
        // 0x80062E78: lui         $v0, 0x8022
        ctx->r2 = S32(0X8022 << 16);
            goto L_80062E84;
    }
    // 0x80062E78: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80062E7C: b           L_80062E88
    // 0x80062E80: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_80062E88;
    // 0x80062E80: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80062E84:
    // 0x80062E84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80062E88:
    // 0x80062E88: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x80062E8C: addu        $t1, $t9, $a1
    ctx->r9 = ADD32(ctx->r25, ctx->r5);
    // 0x80062E90: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80062E94: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80062E98: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80062E9C: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x80062EA0: mflo        $t4
    ctx->r12 = lo;
    // 0x80062EA4: subu        $t0, $v1, $t4
    ctx->r8 = SUB32(ctx->r3, ctx->r12);
    // 0x80062EA8: bne         $a3, $v1, L_80062EB4
    if (ctx->r7 != ctx->r3) {
        // 0x80062EAC: addiu       $v0, $v0, -0x2980
        ctx->r2 = ADD32(ctx->r2, -0X2980);
            goto L_80062EB4;
    }
    // 0x80062EAC: addiu       $v0, $v0, -0x2980
    ctx->r2 = ADD32(ctx->r2, -0X2980);
    // 0x80062EB0: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
L_80062EB4:
    // 0x80062EB4: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80062EB8: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80062EBC: addiu       $a0, $a0, -0x2930
    ctx->r4 = ADD32(ctx->r4, -0X2930);
    // 0x80062EC0: addiu       $v1, $v1, -0x2958
    ctx->r3 = ADD32(ctx->r3, -0X2958);
    // 0x80062EC4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80062EC8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80062ECC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80062ED0: lbu         $t5, -0x2904($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X2904);
    // 0x80062ED4: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x80062ED8: addiu       $t7, $t7, 0x5770
    ctx->r15 = ADD32(ctx->r15, 0X5770);
    // 0x80062EDC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80062EE0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80062EE4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80062EE8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80062EEC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80062EF0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80062EF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80062EF8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80062EFC: lh          $a2, 0x2BE($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X2BE));
    // 0x80062F00: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x80062F04: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80062F08: bltz        $a2, L_80062F30
    if (SIGNED(ctx->r6) < 0) {
        // 0x80062F0C: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_80062F30;
    }
    // 0x80062F0C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80062F10: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80062F14: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80062F18: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80062F1C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80062F20: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x80062F24: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80062F28: b           L_80062F34
    // 0x80062F2C: lh          $t0, 0x6BB8($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X6BB8));
        goto L_80062F34;
    // 0x80062F2C: lh          $t0, 0x6BB8($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X6BB8));
L_80062F30:
    // 0x80062F30: lh          $t0, 0x288($a1)
    ctx->r8 = S32(MEM_H(ctx->r5, 0X288));
L_80062F34:
    // 0x80062F34: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80062F38: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x80062F3C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80062F40: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80062F44: lh          $t1, -0x1970($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, -0X1970));
    // 0x80062F48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80062F4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80062F50: bne         $t1, $at, L_80062F5C
    if (ctx->r9 != ctx->r1) {
        // 0x80062F54: lui         $at, 0x8022
        ctx->r1 = S32(0X8022 << 16);
            goto L_80062F5C;
    }
    // 0x80062F54: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80062F58: sb          $t2, -0x298C($at)
    MEM_B(-0X298C, ctx->r1) = ctx->r10;
L_80062F5C:
    // 0x80062F5C: lbu         $t3, -0x298C($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X298C);
    // 0x80062F60: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80062F64: sltiu       $at, $t4, 0xE
    ctx->r1 = ctx->r12 < 0XE ? 1 : 0;
    // 0x80062F68: beq         $at, $zero, L_8006302C
    if (ctx->r1 == 0) {
        // 0x80062F6C: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8006302C;
    }
    // 0x80062F6C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80062F70: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80062F74: addu        $at, $at, $t4
    gpr jr_addend_80062F7C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80062F78: lw          $t4, 0x4C24($at)
    ctx->r12 = ADD32(ctx->r1, 0X4C24);
    // 0x80062F7C: jr          $t4
    // 0x80062F80: nop

    switch (jr_addend_80062F7C >> 2) {
        case 0: goto L_80062F84; break;
        case 1: goto L_80062FB8; break;
        case 2: goto L_8006302C; break;
        case 3: goto L_80062FEC; break;
        case 4: goto L_8006302C; break;
        case 5: goto L_80062FFC; break;
        case 6: goto L_8006302C; break;
        case 7: goto L_80062FFC; break;
        case 8: goto L_8006302C; break;
        case 9: goto L_8006302C; break;
        case 10: goto L_8006302C; break;
        case 11: goto L_8006302C; break;
        case 12: goto L_8006302C; break;
        case 13: goto L_80062FFC; break;
        default: switch_error(__func__, 0x80062F7C, 0x80104C24);
    }
    // 0x80062F80: nop

L_80062F84:
    // 0x80062F84: lw          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80062F88: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80062F8C: bgez        $t5, L_80062F9C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80062F90: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_80062F9C;
    }
    // 0x80062F90: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80062F94: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x80062F98: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80062F9C:
    // 0x80062F9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80062FA0: bgez        $t7, L_80062FB0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80062FA4: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_80062FB0;
    }
    // 0x80062FA4: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80062FA8: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x80062FAC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80062FB0:
    // 0x80062FB0: b           L_8006302C
    // 0x80062FB4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8006302C;
    // 0x80062FB4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80062FB8:
    // 0x80062FB8: lw          $t9, 0x0($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80062FBC: lw          $t2, 0x0($a0)
    ctx->r10 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80062FC0: bgez        $t9, L_80062FD0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80062FC4: sra         $t1, $t9, 1
        ctx->r9 = S32(SIGNED(ctx->r25) >> 1);
            goto L_80062FD0;
    }
    // 0x80062FC4: sra         $t1, $t9, 1
    ctx->r9 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80062FC8: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x80062FCC: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80062FD0:
    // 0x80062FD0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80062FD4: bgez        $t2, L_80062FE4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80062FD8: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80062FE4;
    }
    // 0x80062FD8: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80062FDC: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80062FE0: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80062FE4:
    // 0x80062FE4: b           L_8006302C
    // 0x80062FE8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
        goto L_8006302C;
    // 0x80062FE8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_80062FEC:
    // 0x80062FEC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80062FF0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80062FF4: b           L_8006302C
    // 0x80062FF8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8006302C;
    // 0x80062FF8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80062FFC:
    // 0x80062FFC: lw          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80063000: lw          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80063004: bgez        $t4, L_80063014
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80063008: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_80063014;
    }
    // 0x80063008: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8006300C: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x80063010: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80063014:
    // 0x80063014: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80063018: bgez        $t6, L_80063028
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006301C: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80063028;
    }
    // 0x8006301C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80063020: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80063024: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80063028:
    // 0x80063028: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8006302C:
    // 0x8006302C: lbu         $t8, 0x346($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X346);
    // 0x80063030: blezl       $t8, L_80063098
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80063034: lw          $t3, 0x0($v0)
        ctx->r11 = S32(MEM_W(ctx->r2, 0X0));
            goto L_80063098;
    }
    goto skip_2;
    // 0x80063034: lw          $t3, 0x0($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X0));
    skip_2:
    // 0x80063038: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8006303C: addiu       $a1, $zero, 0xAB
    ctx->r5 = ADD32(0, 0XAB);
    // 0x80063040: lw          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80063044: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063048: addiu       $a3, $a3, 0x200
    ctx->r7 = ADD32(ctx->r7, 0X200);
    // 0x8006304C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80063050: lw          $t3, 0x0($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80063054: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80063058: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8006305C: sll         $t4, $t4, 7
    ctx->r12 = S32(ctx->r12 << 7);
    // 0x80063060: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x80063064: mflo        $t1
    ctx->r9 = lo;
    // 0x80063068: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8006306C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80063070: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063074: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80063078: mflo        $t7
    ctx->r15 = lo;
    // 0x8006307C: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80063080: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80063084: div         $zero, $a3, $at
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r1)));
    // 0x80063088: mflo        $t9
    ctx->r25 = lo;
    // 0x8006308C: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x80063090: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80063094: lw          $t3, 0x0($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X0));
L_80063098:
    // 0x80063098: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8006309C: lw          $t9, 0x0($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800630A0: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800630A4: mflo        $t4
    ctx->r12 = lo;
    // 0x800630A8: bgez        $t4, L_800630B8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800630AC: sra         $t5, $t4, 8
        ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
            goto L_800630B8;
    }
    // 0x800630AC: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800630B0: addiu       $at, $t4, 0xFF
    ctx->r1 = ADD32(ctx->r12, 0XFF);
    // 0x800630B4: sra         $t5, $at, 8
    ctx->r13 = S32(SIGNED(ctx->r1) >> 8);
L_800630B8:
    // 0x800630B8: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800630BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800630C0: lw          $a1, 0x0($v0)
    ctx->r5 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800630C4: mflo        $t7
    ctx->r15 = lo;
    // 0x800630C8: bgez        $t7, L_800630D8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800630CC: sra         $t8, $t7, 8
        ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
            goto L_800630D8;
    }
    // 0x800630CC: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800630D0: addiu       $at, $t7, 0xFF
    ctx->r1 = ADD32(ctx->r15, 0XFF);
    // 0x800630D4: sra         $t8, $at, 8
    ctx->r24 = S32(SIGNED(ctx->r1) >> 8);
L_800630D8:
    // 0x800630D8: multu       $a3, $t9
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800630DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800630E0: mflo        $t1
    ctx->r9 = lo;
    // 0x800630E4: bgez        $t1, L_800630F4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800630E8: sra         $t2, $t1, 8
        ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
            goto L_800630F4;
    }
    // 0x800630E8: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800630EC: addiu       $at, $t1, 0xFF
    ctx->r1 = ADD32(ctx->r9, 0XFF);
    // 0x800630F0: sra         $t2, $at, 8
    ctx->r10 = S32(SIGNED(ctx->r1) >> 8);
L_800630F4:
    // 0x800630F4: bgez        $a1, L_80063104
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800630F8: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_80063104;
    }
    // 0x800630F8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800630FC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80063100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80063104:
    // 0x80063104: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80063108: bne         $at, $zero, L_80063114
    if (ctx->r1 != 0) {
        // 0x8006310C: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80063114;
    }
    // 0x8006310C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80063110: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_80063114:
    // 0x80063114: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80063118: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8006311C: bgezl       $v0, L_80063130
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80063120: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80063130;
    }
    goto skip_3;
    // 0x80063120: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    skip_3:
    // 0x80063124: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80063128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006312C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
L_80063130:
    // 0x80063130: bnel        $at, $zero, L_80063140
    if (ctx->r1 != 0) {
        // 0x80063134: lw          $v0, 0x0($a0)
        ctx->r2 = S32(MEM_W(ctx->r4, 0X0));
            goto L_80063140;
    }
    goto skip_4;
    // 0x80063134: lw          $v0, 0x0($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X0));
    skip_4:
    // 0x80063138: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8006313C: lw          $v0, 0x0($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X0));
L_80063140:
    // 0x80063140: bgezl       $v0, L_80063154
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80063144: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80063154;
    }
    goto skip_5;
    // 0x80063144: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    skip_5:
    // 0x80063148: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8006314C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80063150: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
L_80063154:
    // 0x80063154: bne         $at, $zero, L_80063160
    if (ctx->r1 != 0) {
        // 0x80063158: nop
    
            goto L_80063160;
    }
    // 0x80063158: nop

    // 0x8006315C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_80063160:
    // 0x80063160: jr          $ra
    // 0x80063164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80063164: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void displayflash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800726B0: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800726B4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x800726B8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800726BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800726C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800726C4: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X38));
    // 0x800726C8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800726CC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800726D0: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800726D4: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800726D8: lh          $v0, -0x9DC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9DC));
    // 0x800726DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800726E0: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800726E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800726E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800726EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800726F0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800726F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800726F8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800726FC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80072700: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80072704: bne         $v1, $v0, L_8007272C
    if (ctx->r3 != ctx->r2) {
        // 0x80072708: cvt.s.d     $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
            goto L_8007272C;
    }
    // 0x80072708: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8007270C: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x80072710: addiu       $t0, $t0, -0x2904
    ctx->r8 = ADD32(ctx->r8, -0X2904);
    // 0x80072714: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80072718: addiu       $s0, $s0, 0x34
    ctx->r16 = ADD32(ctx->r16, 0X34);
    // 0x8007271C: bne         $t6, $zero, L_8007272C
    if (ctx->r14 != 0) {
        // 0x80072720: nop
    
            goto L_8007272C;
    }
    // 0x80072720: nop

    // 0x80072724: b           L_8007272C
    // 0x80072728: addiu       $s0, $a1, -0x34
    ctx->r16 = ADD32(ctx->r5, -0X34);
        goto L_8007272C;
    // 0x80072728: addiu       $s0, $a1, -0x34
    ctx->r16 = ADD32(ctx->r5, -0X34);
L_8007272C:
    // 0x8007272C: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x80072730: bne         $at, $zero, L_800727C8
    if (ctx->r1 != 0) {
        // 0x80072734: addiu       $t0, $t0, -0x2904
        ctx->r8 = ADD32(ctx->r8, -0X2904);
            goto L_800727C8;
    }
    // 0x80072734: addiu       $t0, $t0, -0x2904
    ctx->r8 = ADD32(ctx->r8, -0X2904);
    // 0x80072738: addiu       $s1, $s1, -0x15
    ctx->r17 = ADD32(ctx->r17, -0X15);
    // 0x8007273C: addiu       $s0, $s0, -0xF
    ctx->r16 = ADD32(ctx->r16, -0XF);
    // 0x80072740: bgez        $s1, L_80072750
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80072744: sra         $t7, $s1, 1
        ctx->r15 = S32(SIGNED(ctx->r17) >> 1);
            goto L_80072750;
    }
    // 0x80072744: sra         $t7, $s1, 1
    ctx->r15 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80072748: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x8007274C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80072750:
    // 0x80072750: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80072754: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80072758: bgez        $s0, L_80072768
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8007275C: sra         $t8, $s0, 1
        ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
            goto L_80072768;
    }
    // 0x8007275C: sra         $t8, $s0, 1
    ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80072760: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x80072764: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80072768:
    // 0x80072768: beq         $v0, $zero, L_80072778
    if (ctx->r2 == 0) {
        // 0x8007276C: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_80072778;
    }
    // 0x8007276C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80072770: bnel        $v1, $v0, L_80072784
    if (ctx->r3 != ctx->r2) {
        // 0x80072774: addiu       $s1, $s1, 0xA0
        ctx->r17 = ADD32(ctx->r17, 0XA0);
            goto L_80072784;
    }
    goto skip_0;
    // 0x80072774: addiu       $s1, $s1, 0xA0
    ctx->r17 = ADD32(ctx->r17, 0XA0);
    skip_0:
L_80072778:
    // 0x80072778: b           L_80072784
    // 0x8007277C: addiu       $s1, $s1, 0x15
    ctx->r17 = ADD32(ctx->r17, 0X15);
        goto L_80072784;
    // 0x8007277C: addiu       $s1, $s1, 0x15
    ctx->r17 = ADD32(ctx->r17, 0X15);
    // 0x80072780: addiu       $s1, $s1, 0xA0
    ctx->r17 = ADD32(ctx->r17, 0XA0);
L_80072784:
    // 0x80072784: beq         $v0, $zero, L_80072794
    if (ctx->r2 == 0) {
        // 0x80072788: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80072794;
    }
    // 0x80072788: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007278C: bnel        $v0, $at, L_800727A0
    if (ctx->r2 != ctx->r1) {
        // 0x80072790: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_800727A0;
    }
    goto skip_1;
    // 0x80072790: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    skip_1:
L_80072794:
    // 0x80072794: b           L_800727A0
    // 0x80072798: addiu       $s0, $s0, 0xF
    ctx->r16 = ADD32(ctx->r16, 0XF);
        goto L_800727A0;
    // 0x80072798: addiu       $s0, $s0, 0xF
    ctx->r16 = ADD32(ctx->r16, 0XF);
    // 0x8007279C: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
L_800727A0:
    // 0x800727A0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800727A4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800727A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800727AC: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800727B0: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x800727B4: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x800727B8: nop

    // 0x800727BC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800727C0: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x800727C4: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
L_800727C8:
    // 0x800727C8: lh          $t9, 0x32($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X32));
    // 0x800727CC: lh          $t7, 0x42($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X42));
    // 0x800727D0: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    // 0x800727D4: bne         $t9, $at, L_8007284C
    if (ctx->r25 != ctx->r1) {
        // 0x800727D8: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_8007284C;
    }
    // 0x800727D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800727DC: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800727E0: lui         $a2, 0x802A
    ctx->r6 = S32(0X802A << 16);
    // 0x800727E4: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x800727E8: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800727EC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800727F0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800727F4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800727F8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800727FC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80072800: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80072804: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x80072808: lh          $a2, 0x5A32($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X5A32));
    // 0x8007280C: addiu       $t6, $zero, 0xAA
    ctx->r14 = ADD32(0, 0XAA);
    // 0x80072810: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80072814: sll         $t3, $a2, 8
    ctx->r11 = S32(ctx->r6 << 8);
    // 0x80072818: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x8007281C: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80072820: mflo        $t4
    ctx->r12 = lo;
    // 0x80072824: andi        $a2, $t4, 0xFF
    ctx->r6 = ctx->r12 & 0XFF;
    // 0x80072828: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8007282C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80072830: addiu       $a3, $zero, 0x73
    ctx->r7 = ADD32(0, 0X73);
    // 0x80072834: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80072838: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8007283C: jal         0x8006E264
    // 0x80072840: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    setfxcolor(rdram, ctx);
        goto after_0;
    // 0x80072840: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80072844: b           L_8007288C
    // 0x80072848: nop

        goto L_8007288C;
    // 0x80072848: nop

L_8007284C:
    // 0x8007284C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80072850: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80072854: addiu       $t9, $t9, -0x58B8
    ctx->r25 = ADD32(ctx->r25, -0X58B8);
    // 0x80072858: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8007285C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80072860: lbu         $t1, 0x4($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X4);
    // 0x80072864: lbu         $t2, 0x5($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X5);
    // 0x80072868: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8007286C: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x80072870: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x80072874: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x80072878: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x8007287C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x80072880: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80072884: jal         0x8006E264
    // 0x80072888: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    setfxcolor(rdram, ctx);
        goto after_1;
    // 0x80072888: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_1:
L_8007288C:
    // 0x8007288C: jal         0x8006370C
    // 0x80072890: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    gettileid(rdram, ctx);
        goto after_2;
    // 0x80072890: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    after_2:
    // 0x80072894: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80072898: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x8007289C: lbu         $t3, 0x3F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3F);
    // 0x800728A0: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800728A4: lw          $a3, 0x38($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800728A8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800728AC: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800728B0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800728B4: jal         0x8006CF8C
    // 0x800728B8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    rendertileworld(rdram, ctx);
        goto after_3;
    // 0x800728B8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_3:
    // 0x800728BC: jal         0x8006E39C
    // 0x800728C0: nop

    unsetfxsprite(rdram, ctx);
        goto after_4;
    // 0x800728C0: nop

    after_4:
    // 0x800728C4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800728C8: lw          $s0, 0x1C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800728CC: lw          $s1, 0x20($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800728D0: jr          $ra
    // 0x800728D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800728D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void badguypic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A090: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8009A094: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8009A098: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009A09C: slti        $at, $t7, 0x7D2
    ctx->r1 = SIGNED(ctx->r15) < 0X7D2 ? 1 : 0;
    // 0x8009A0A0: bne         $at, $zero, L_8009A184
    if (ctx->r1 != 0) {
        // 0x8009A0A4: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8009A184;
    }
    // 0x8009A0A4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8009A0A8: slti        $at, $t7, 0xA47
    ctx->r1 = SIGNED(ctx->r15) < 0XA47 ? 1 : 0;
    // 0x8009A0AC: bne         $at, $zero, L_8009A0F4
    if (ctx->r1 != 0) {
        // 0x8009A0B0: addiu       $at, $zero, 0xA96
        ctx->r1 = ADD32(0, 0XA96);
            goto L_8009A0F4;
    }
    // 0x8009A0B0: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    // 0x8009A0B4: beq         $t7, $at, L_8009A244
    if (ctx->r15 == ctx->r1) {
        // 0x8009A0B8: addiu       $at, $zero, 0xAC8
        ctx->r1 = ADD32(0, 0XAC8);
            goto L_8009A244;
    }
    // 0x8009A0B8: addiu       $at, $zero, 0xAC8
    ctx->r1 = ADD32(0, 0XAC8);
    // 0x8009A0BC: beq         $t7, $at, L_8009A244
    if (ctx->r15 == ctx->r1) {
        // 0x8009A0C0: addiu       $at, $zero, 0x1202
        ctx->r1 = ADD32(0, 0X1202);
            goto L_8009A244;
    }
    // 0x8009A0C0: addiu       $at, $zero, 0x1202
    ctx->r1 = ADD32(0, 0X1202);
    // 0x8009A0C4: beq         $t7, $at, L_8009A244
    if (ctx->r15 == ctx->r1) {
        // 0x8009A0C8: addiu       $at, $zero, 0x1203
        ctx->r1 = ADD32(0, 0X1203);
            goto L_8009A244;
    }
    // 0x8009A0C8: addiu       $at, $zero, 0x1203
    ctx->r1 = ADD32(0, 0X1203);
    // 0x8009A0CC: beq         $t7, $at, L_8009A244
    if (ctx->r15 == ctx->r1) {
        // 0x8009A0D0: addiu       $at, $zero, 0x123E
        ctx->r1 = ADD32(0, 0X123E);
            goto L_8009A244;
    }
    // 0x8009A0D0: addiu       $at, $zero, 0x123E
    ctx->r1 = ADD32(0, 0X123E);
    // 0x8009A0D4: beq         $t7, $at, L_8009A244
    if (ctx->r15 == ctx->r1) {
        // 0x8009A0D8: addiu       $at, $zero, 0x123F
        ctx->r1 = ADD32(0, 0X123F);
            goto L_8009A244;
    }
    // 0x8009A0D8: addiu       $at, $zero, 0x123F
    ctx->r1 = ADD32(0, 0X123F);
    // 0x8009A0DC: beq         $t7, $at, L_8009A244
    if (ctx->r15 == ctx->r1) {
        // 0x8009A0E0: addiu       $at, $zero, 0x1252
        ctx->r1 = ADD32(0, 0X1252);
            goto L_8009A244;
    }
    // 0x8009A0E0: addiu       $at, $zero, 0x1252
    ctx->r1 = ADD32(0, 0X1252);
    // 0x8009A0E4: beq         $t7, $at, L_8009A244
    if (ctx->r15 == ctx->r1) {
        // 0x8009A0E8: nop
    
            goto L_8009A244;
    }
    // 0x8009A0E8: nop

    // 0x8009A0EC: b           L_8009A250
    // 0x8009A0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A250;
    // 0x8009A0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A0F4:
    // 0x8009A0F4: slti        $at, $a0, 0x871
    ctx->r1 = SIGNED(ctx->r4) < 0X871 ? 1 : 0;
    // 0x8009A0F8: bne         $at, $zero, L_8009A158
    if (ctx->r1 != 0) {
        // 0x8009A0FC: slti        $at, $a0, 0x94A
        ctx->r1 = SIGNED(ctx->r4) < 0X94A ? 1 : 0;
            goto L_8009A158;
    }
    // 0x8009A0FC: slti        $at, $a0, 0x94A
    ctx->r1 = SIGNED(ctx->r4) < 0X94A ? 1 : 0;
    // 0x8009A100: bne         $at, $zero, L_8009A118
    if (ctx->r1 != 0) {
        // 0x8009A104: addiu       $at, $zero, 0xA46
        ctx->r1 = ADD32(0, 0XA46);
            goto L_8009A118;
    }
    // 0x8009A104: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    // 0x8009A108: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A10C: nop
    
            goto L_8009A244;
    }
    // 0x8009A10C: nop

    // 0x8009A110: b           L_8009A250
    // 0x8009A114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A250;
    // 0x8009A114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A118:
    // 0x8009A118: slti        $at, $a0, 0x876
    ctx->r1 = SIGNED(ctx->r4) < 0X876 ? 1 : 0;
    // 0x8009A11C: bne         $at, $zero, L_8009A144
    if (ctx->r1 != 0) {
        // 0x8009A120: addiu       $t8, $a0, -0x938
        ctx->r24 = ADD32(ctx->r4, -0X938);
            goto L_8009A144;
    }
    // 0x8009A120: addiu       $t8, $a0, -0x938
    ctx->r24 = ADD32(ctx->r4, -0X938);
    // 0x8009A124: sltiu       $at, $t8, 0x12
    ctx->r1 = ctx->r24 < 0X12 ? 1 : 0;
    // 0x8009A128: beq         $at, $zero, L_8009A24C
    if (ctx->r1 == 0) {
        // 0x8009A12C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8009A24C;
    }
    // 0x8009A12C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8009A130: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8009A134: addu        $at, $at, $t8
    gpr jr_addend_8009A13C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8009A138: lw          $t8, 0x68A8($at)
    ctx->r24 = ADD32(ctx->r1, 0X68A8);
    // 0x8009A13C: jr          $t8
    // 0x8009A140: nop

    switch (jr_addend_8009A13C >> 2) {
        case 0: goto L_8009A244; break;
        case 1: goto L_8009A24C; break;
        case 2: goto L_8009A24C; break;
        case 3: goto L_8009A24C; break;
        case 4: goto L_8009A24C; break;
        case 5: goto L_8009A24C; break;
        case 6: goto L_8009A24C; break;
        case 7: goto L_8009A24C; break;
        case 8: goto L_8009A24C; break;
        case 9: goto L_8009A24C; break;
        case 10: goto L_8009A244; break;
        case 11: goto L_8009A244; break;
        case 12: goto L_8009A244; break;
        case 13: goto L_8009A244; break;
        case 14: goto L_8009A244; break;
        case 15: goto L_8009A244; break;
        case 16: goto L_8009A244; break;
        case 17: goto L_8009A244; break;
        default: switch_error(__func__, 0x8009A13C, 0x801068A8);
    }
    // 0x8009A140: nop

L_8009A144:
    // 0x8009A144: addiu       $at, $zero, 0x875
    ctx->r1 = ADD32(0, 0X875);
    // 0x8009A148: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A14C: nop
    
            goto L_8009A244;
    }
    // 0x8009A14C: nop

    // 0x8009A150: b           L_8009A250
    // 0x8009A154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A250;
    // 0x8009A154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A158:
    // 0x8009A158: addiu       $at, $zero, 0x7FD
    ctx->r1 = ADD32(0, 0X7FD);
    // 0x8009A15C: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A160: addiu       $at, $zero, 0x848
        ctx->r1 = ADD32(0, 0X848);
            goto L_8009A244;
    }
    // 0x8009A160: addiu       $at, $zero, 0x848
    ctx->r1 = ADD32(0, 0X848);
    // 0x8009A164: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A168: addiu       $at, $zero, 0x866
        ctx->r1 = ADD32(0, 0X866);
            goto L_8009A244;
    }
    // 0x8009A168: addiu       $at, $zero, 0x866
    ctx->r1 = ADD32(0, 0X866);
    // 0x8009A16C: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A170: addiu       $at, $zero, 0x870
        ctx->r1 = ADD32(0, 0X870);
            goto L_8009A244;
    }
    // 0x8009A170: addiu       $at, $zero, 0x870
    ctx->r1 = ADD32(0, 0X870);
    // 0x8009A174: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A178: nop
    
            goto L_8009A244;
    }
    // 0x8009A178: nop

    // 0x8009A17C: b           L_8009A250
    // 0x8009A180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A250;
    // 0x8009A180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A184:
    // 0x8009A184: slti        $at, $a0, 0x6D1
    ctx->r1 = SIGNED(ctx->r4) < 0X6D1 ? 1 : 0;
    // 0x8009A188: bne         $at, $zero, L_8009A1D0
    if (ctx->r1 != 0) {
        // 0x8009A18C: addiu       $at, $zero, 0x71C
        ctx->r1 = ADD32(0, 0X71C);
            goto L_8009A1D0;
    }
    // 0x8009A18C: addiu       $at, $zero, 0x71C
    ctx->r1 = ADD32(0, 0X71C);
    // 0x8009A190: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A194: addiu       $at, $zero, 0x758
        ctx->r1 = ADD32(0, 0X758);
            goto L_8009A244;
    }
    // 0x8009A194: addiu       $at, $zero, 0x758
    ctx->r1 = ADD32(0, 0X758);
    // 0x8009A198: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A19C: addiu       $at, $zero, 0x780
        ctx->r1 = ADD32(0, 0X780);
            goto L_8009A244;
    }
    // 0x8009A19C: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x8009A1A0: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A1A4: addiu       $at, $zero, 0x781
        ctx->r1 = ADD32(0, 0X781);
            goto L_8009A244;
    }
    // 0x8009A1A4: addiu       $at, $zero, 0x781
    ctx->r1 = ADD32(0, 0X781);
    // 0x8009A1A8: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A1AC: addiu       $at, $zero, 0x7A8
        ctx->r1 = ADD32(0, 0X7A8);
            goto L_8009A244;
    }
    // 0x8009A1AC: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
    // 0x8009A1B0: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A1B4: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_8009A244;
    }
    // 0x8009A1B4: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    // 0x8009A1B8: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A1BC: addiu       $at, $zero, 0x7D1
        ctx->r1 = ADD32(0, 0X7D1);
            goto L_8009A244;
    }
    // 0x8009A1BC: addiu       $at, $zero, 0x7D1
    ctx->r1 = ADD32(0, 0X7D1);
    // 0x8009A1C0: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A1C4: nop
    
            goto L_8009A244;
    }
    // 0x8009A1C4: nop

    // 0x8009A1C8: b           L_8009A250
    // 0x8009A1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A250;
    // 0x8009A1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A1D0:
    // 0x8009A1D0: slti        $at, $a0, 0x691
    ctx->r1 = SIGNED(ctx->r4) < 0X691 ? 1 : 0;
    // 0x8009A1D4: bne         $at, $zero, L_8009A220
    if (ctx->r1 != 0) {
        // 0x8009A1D8: slti        $at, $a0, 0x693
        ctx->r1 = SIGNED(ctx->r4) < 0X693 ? 1 : 0;
            goto L_8009A220;
    }
    // 0x8009A1D8: slti        $at, $a0, 0x693
    ctx->r1 = SIGNED(ctx->r4) < 0X693 ? 1 : 0;
    // 0x8009A1DC: bne         $at, $zero, L_8009A204
    if (ctx->r1 != 0) {
        // 0x8009A1E0: addiu       $t9, $a0, -0x6B3
        ctx->r25 = ADD32(ctx->r4, -0X6B3);
            goto L_8009A204;
    }
    // 0x8009A1E0: addiu       $t9, $a0, -0x6B3
    ctx->r25 = ADD32(ctx->r4, -0X6B3);
    // 0x8009A1E4: sltiu       $at, $t9, 0x1E
    ctx->r1 = ctx->r25 < 0X1E ? 1 : 0;
    // 0x8009A1E8: beq         $at, $zero, L_8009A24C
    if (ctx->r1 == 0) {
        // 0x8009A1EC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8009A24C;
    }
    // 0x8009A1EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8009A1F0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8009A1F4: addu        $at, $at, $t9
    gpr jr_addend_8009A1FC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8009A1F8: lw          $t9, 0x68F0($at)
    ctx->r25 = ADD32(ctx->r1, 0X68F0);
    // 0x8009A1FC: jr          $t9
    // 0x8009A200: nop

    switch (jr_addend_8009A1FC >> 2) {
        case 0: goto L_8009A244; break;
        case 1: goto L_8009A24C; break;
        case 2: goto L_8009A24C; break;
        case 3: goto L_8009A24C; break;
        case 4: goto L_8009A24C; break;
        case 5: goto L_8009A24C; break;
        case 6: goto L_8009A24C; break;
        case 7: goto L_8009A24C; break;
        case 8: goto L_8009A24C; break;
        case 9: goto L_8009A24C; break;
        case 10: goto L_8009A244; break;
        case 11: goto L_8009A24C; break;
        case 12: goto L_8009A24C; break;
        case 13: goto L_8009A24C; break;
        case 14: goto L_8009A24C; break;
        case 15: goto L_8009A24C; break;
        case 16: goto L_8009A24C; break;
        case 17: goto L_8009A24C; break;
        case 18: goto L_8009A24C; break;
        case 19: goto L_8009A24C; break;
        case 20: goto L_8009A24C; break;
        case 21: goto L_8009A24C; break;
        case 22: goto L_8009A24C; break;
        case 23: goto L_8009A24C; break;
        case 24: goto L_8009A24C; break;
        case 25: goto L_8009A24C; break;
        case 26: goto L_8009A244; break;
        case 27: goto L_8009A244; break;
        case 28: goto L_8009A24C; break;
        case 29: goto L_8009A244; break;
        default: switch_error(__func__, 0x8009A1FC, 0x801068F0);
    }
    // 0x8009A200: nop

L_8009A204:
    // 0x8009A204: addiu       $at, $zero, 0x691
    ctx->r1 = ADD32(0, 0X691);
    // 0x8009A208: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A20C: addiu       $at, $zero, 0x692
        ctx->r1 = ADD32(0, 0X692);
            goto L_8009A244;
    }
    // 0x8009A20C: addiu       $at, $zero, 0x692
    ctx->r1 = ADD32(0, 0X692);
    // 0x8009A210: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A214: nop
    
            goto L_8009A244;
    }
    // 0x8009A214: nop

    // 0x8009A218: b           L_8009A250
    // 0x8009A21C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A250;
    // 0x8009A21C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A220:
    // 0x8009A220: addiu       $at, $zero, 0x2A3
    ctx->r1 = ADD32(0, 0X2A3);
    // 0x8009A224: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A228: addiu       $at, $zero, 0x4F3
        ctx->r1 = ADD32(0, 0X4F3);
            goto L_8009A244;
    }
    // 0x8009A228: addiu       $at, $zero, 0x4F3
    ctx->r1 = ADD32(0, 0X4F3);
    // 0x8009A22C: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A230: addiu       $at, $zero, 0x60E
        ctx->r1 = ADD32(0, 0X60E);
            goto L_8009A244;
    }
    // 0x8009A230: addiu       $at, $zero, 0x60E
    ctx->r1 = ADD32(0, 0X60E);
    // 0x8009A234: beq         $a0, $at, L_8009A244
    if (ctx->r4 == ctx->r1) {
        // 0x8009A238: addiu       $at, $zero, 0x690
        ctx->r1 = ADD32(0, 0X690);
            goto L_8009A244;
    }
    // 0x8009A238: addiu       $at, $zero, 0x690
    ctx->r1 = ADD32(0, 0X690);
    // 0x8009A23C: bnel        $a0, $at, L_8009A250
    if (ctx->r4 != ctx->r1) {
        // 0x8009A240: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009A250;
    }
    goto skip_0;
    // 0x8009A240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8009A244:
    // 0x8009A244: jr          $ra
    // 0x8009A248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009A248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009A24C:
    // 0x8009A24C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A250:
    // 0x8009A250: jr          $ra
    // 0x8009A254: nop

    return;
    // 0x8009A254: nop

;}
RECOMP_FUNC void loadgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005508C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055090: jal         0x80054DE0
    // 0x80055094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80054DE0(rdram, ctx);
        goto after_0;
    // 0x80055094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80055098: jal         0x80054DE0
    // 0x8005509C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80054DE0(rdram, ctx);
        goto after_1;
    // 0x8005509C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800550A0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800550A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800550A8: jr          $ra
    // 0x800550AC: nop

    return;
    // 0x800550AC: nop

;}
RECOMP_FUNC void divscale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090FE8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80090FEC: lbu         $a3, 0x2B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2B);
    // 0x80090FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090FF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80090FF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090FFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80091000: jal         0x800BB834
    // 0x80091004: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091004: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_0:
    // 0x80091008: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009100C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091010: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091014: jal         0x800BB89C
    // 0x80091018: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091018: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x8009101C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091024: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091028: jr          $ra
    // 0x8009102C: nop

    return;
    // 0x8009102C: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1230: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D1234: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D1238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D123C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800D1240: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800D1244: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D1248: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D124C: lw          $a3, 0x44($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800D1250: jal         0x800BB89C
    // 0x800D1254: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1254: lw          $a2, 0x40($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X40));
    after_0:
    // 0x800D1258: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D125C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800D1260: lw          $a0, 0x40($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800D1264: lw          $a1, 0x44($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800D1268: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D126C: jal         0x800BB8F8
    // 0x800D1270: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1270: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x800D1274: lw          $t6, 0x38($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800D1278: lw          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800D127C: lw          $t0, 0x20($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800D1280: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800D1284: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x800D1288: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800D128C: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800D1290: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800D1294: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800D1298: bgtz        $t0, L_800D12F8
    if (SIGNED(ctx->r8) > 0) {
        // 0x800D129C: lw          $t1, 0x24($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800D12F8;
    }
    // 0x800D129C: lw          $t1, 0x24($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800D12A0: bltz        $t0, L_800D12B0
    if (SIGNED(ctx->r8) < 0) {
        // 0x800D12A4: nop
    
            goto L_800D12B0;
    }
    // 0x800D12A4: nop

    // 0x800D12A8: b           L_800D12FC
    // 0x800D12AC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_800D12FC;
    // 0x800D12AC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800D12B0:
    // 0x800D12B0: bltzl       $t8, L_800D12FC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D12B4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800D12FC;
    }
    goto skip_0;
    // 0x800D12B4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x800D12B8: bgtz        $t8, L_800D12C8
    if (SIGNED(ctx->r24) > 0) {
        // 0x800D12BC: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_800D12C8;
    }
    // 0x800D12BC: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800D12C0: beql        $t9, $zero, L_800D12FC
    if (ctx->r25 == 0) {
        // 0x800D12C4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800D12FC;
    }
    goto skip_1;
    // 0x800D12C4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_800D12C8:
    // 0x800D12C8: lw          $t4, 0x40($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800D12CC: lw          $t5, 0x44($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800D12D0: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800D12D4: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x800D12D8: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x800D12DC: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x800D12E0: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x800D12E4: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x800D12E8: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800D12EC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D12F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800D12F4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800D12F8:
    // 0x800D12F8: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800D12FC:
    // 0x800D12FC: lw          $v0, 0x30($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800D1300: lw          $at, 0x0($t0)
    ctx->r1 = S32(MEM_W(ctx->r8, 0X0));
    // 0x800D1304: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x800D1308: lw          $t3, 0x4($t0)
    ctx->r11 = S32(MEM_W(ctx->r8, 0X4));
    // 0x800D130C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800D1310: lw          $at, 0x8($t0)
    ctx->r1 = S32(MEM_W(ctx->r8, 0X8));
    // 0x800D1314: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x800D1318: lw          $t3, 0xC($t0)
    ctx->r11 = S32(MEM_W(ctx->r8, 0XC));
    // 0x800D131C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D1320: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800D1324: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D1328: jr          $ra
    // 0x800D132C: nop

    return;
    // 0x800D132C: nop

;}
RECOMP_FUNC void func_8005850C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005850C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80058510: lb          $t6, 0x1360($t6)
    ctx->r14 = S32(MEM_B(ctx->r14, 0X1360));
    // 0x80058514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005851C: bne         $t6, $zero, L_8005856C
    if (ctx->r14 != 0) {
        // 0x80058520: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8005856C;
    }
    // 0x80058520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80058524: jal         0x80058348
    // 0x80058528: nop

    func_80058348(rdram, ctx);
        goto after_0;
    // 0x80058528: nop

    after_0:
    // 0x8005852C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058530: beq         $v0, $at, L_8005856C
    if (ctx->r2 == ctx->r1) {
        // 0x80058534: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8005856C;
    }
    // 0x80058534: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80058538: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8005853C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80058540: lw          $t0, 0x18($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80058544: addiu       $t8, $t8, -0x5F08
    ctx->r24 = ADD32(ctx->r24, -0X5F08);
    // 0x80058548: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005854C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80058550: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80058554: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80058558: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x8005855C: addiu       $a0, $a0, -0x5FA0
    ctx->r4 = ADD32(ctx->r4, -0X5FA0);
    // 0x80058560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80058564: jal         0x800BB610
    // 0x80058568: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80058568: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    after_1:
L_8005856C:
    // 0x8005856C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80058570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058574: jr          $ra
    // 0x80058578: nop

    return;
    // 0x80058578: nop

;}
RECOMP_FUNC void osScGetCmdQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C654: jr          $ra
    // 0x8004C658: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
    return;
    // 0x8004C658: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
;}
RECOMP_FUNC void func_80064AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064AA4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80064AA8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80064AAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80064AB0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80064AB4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064AB8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80064ABC: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80064AC0: addiu       $t9, $t9, -0x28F8
    ctx->r25 = ADD32(ctx->r25, -0X28F8);
    // 0x80064AC4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80064AC8: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x80064ACC: lbu         $t5, 0x2($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X2);
    // 0x80064AD0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80064AD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80064AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064ADC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80064AE0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80064AE4: bne         $t5, $at, L_80064C24
    if (ctx->r13 != ctx->r1) {
        // 0x80064AE8: lbu         $t4, 0x1($t3)
        ctx->r12 = MEM_BU(ctx->r11, 0X1);
            goto L_80064C24;
    }
    // 0x80064AE8: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80064AEC: addiu       $a0, $zero, 0xF51
    ctx->r4 = ADD32(0, 0XF51);
    // 0x80064AF0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80064AF4: jal         0x80061CB8
    // 0x80064AF8: sh          $t4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r12;
    func_80061CB8(rdram, ctx);
        goto after_0;
    // 0x80064AF8: sh          $t4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r12;
    after_0:
    // 0x80064AFC: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80064B00: addiu       $a3, $a3, 0x4418
    ctx->r7 = ADD32(ctx->r7, 0X4418);
    // 0x80064B04: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80064B08: lhu         $t4, 0x3C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3C);
    // 0x80064B0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80064B10: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80064B14: lw          $t3, 0x1C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80064B18: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80064B1C: addiu       $t9, $t9, -0x5A18
    ctx->r25 = ADD32(ctx->r25, -0X5A18);
    // 0x80064B20: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80064B24: sll         $t8, $t4, 5
    ctx->r24 = S32(ctx->r12 << 5);
    // 0x80064B28: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80064B2C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80064B30: lbu         $t9, 0xA($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XA);
    // 0x80064B34: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x80064B38: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80064B3C: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x80064B40: lbu         $t9, 0xB($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XB);
    // 0x80064B44: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80064B48: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x80064B4C: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x80064B50: or          $t5, $t6, $t7
    ctx->r13 = ctx->r14 | ctx->r15;
    // 0x80064B54: ori         $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 | 0XFF;
    // 0x80064B58: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80064B5C: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80064B60: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80064B64: addiu       $t0, $t0, -0x5B50
    ctx->r8 = ADD32(ctx->r8, -0X5B50);
    // 0x80064B68: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x80064B6C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80064B70: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80064B74: lbu         $t6, 0xD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XD);
    // 0x80064B78: lbu         $t5, 0xF($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XF);
    // 0x80064B7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80064B80: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80064B84: lbu         $t6, 0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XE);
    // 0x80064B88: sll         $t8, $t5, 8
    ctx->r24 = S32(ctx->r13 << 8);
    // 0x80064B8C: or          $t5, $t8, $t7
    ctx->r13 = ctx->r24 | ctx->r15;
    // 0x80064B90: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80064B94: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x80064B98: ori         $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 | 0XFF;
    // 0x80064B9C: lui         $t2, 0xBF00
    ctx->r10 = S32(0XBF00 << 16);
    // 0x80064BA0: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80064BA4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80064BA8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
L_80064BAC:
    // 0x80064BAC: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064BB0: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80064BB4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80064BB8: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80064BBC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80064BC0: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80064BC4: mflo        $t5
    ctx->r13 = lo;
    // 0x80064BC8: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x80064BCC: lhu         $t8, 0x4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X4);
    // 0x80064BD0: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80064BD4: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064BD8: mflo        $t7
    ctx->r15 = lo;
    // 0x80064BDC: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80064BE0: nop

    // 0x80064BE4: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064BE8: mflo        $t5
    ctx->r13 = lo;
    // 0x80064BEC: andi        $t8, $t5, 0xFF
    ctx->r24 = ctx->r13 & 0XFF;
    // 0x80064BF0: lhu         $t5, 0x2($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2);
    // 0x80064BF4: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80064BF8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80064BFC: multu       $t5, $a0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80064C00: mflo        $t8
    ctx->r24 = lo;
    // 0x80064C04: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80064C08: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x80064C0C: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x80064C10: slti        $at, $t8, 0x14
    ctx->r1 = SIGNED(ctx->r24) < 0X14 ? 1 : 0;
    // 0x80064C14: or          $t5, $t6, $t7
    ctx->r13 = ctx->r14 | ctx->r15;
    // 0x80064C18: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80064C1C: bne         $at, $zero, L_80064BAC
    if (ctx->r1 != 0) {
        // 0x80064C20: sw          $t5, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r13;
            goto L_80064BAC;
    }
    // 0x80064C20: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
L_80064C24:
    // 0x80064C24: lbu         $t9, 0x3($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X3);
    // 0x80064C28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80064C2C: lbu         $t6, 0x47($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X47);
    // 0x80064C30: bnel        $t9, $at, L_80064D1C
    if (ctx->r25 != ctx->r1) {
        // 0x80064C34: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_80064D1C;
    }
    goto skip_0;
    // 0x80064C34: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x80064C38: bne         $t6, $zero, L_80064D18
    if (ctx->r14 != 0) {
        // 0x80064C3C: addiu       $a0, $zero, 0xE5A
        ctx->r4 = ADD32(0, 0XE5A);
            goto L_80064D18;
    }
    // 0x80064C3C: addiu       $a0, $zero, 0xE5A
    ctx->r4 = ADD32(0, 0XE5A);
    // 0x80064C40: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80064C44: addiu       $t5, $t5, -0x5A18
    ctx->r13 = ADD32(ctx->r13, -0X5A18);
    // 0x80064C48: sll         $t7, $t4, 5
    ctx->r15 = S32(ctx->r12 << 5);
    // 0x80064C4C: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
    // 0x80064C50: jal         0x80061CB8
    // 0x80064C54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80061CB8(rdram, ctx);
        goto after_1;
    // 0x80064C54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80064C58: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80064C5C: addiu       $a3, $a3, 0x4418
    ctx->r7 = ADD32(ctx->r7, 0X4418);
    // 0x80064C60: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80064C64: lw          $v0, 0x1C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80064C68: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80064C6C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80064C70: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80064C74: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80064C78: lbu         $t9, 0x1A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1A);
    // 0x80064C7C: lbu         $t7, 0x1C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1C);
    // 0x80064C80: lui         $t2, 0xBF00
    ctx->r10 = S32(0XBF00 << 16);
    // 0x80064C84: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x80064C88: lbu         $t9, 0x1B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1B);
    // 0x80064C8C: sll         $t5, $t7, 8
    ctx->r13 = S32(ctx->r15 << 8);
    // 0x80064C90: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80064C94: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x80064C98: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x80064C9C: ori         $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 | 0XFF;
    // 0x80064CA0: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80064CA4: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80064CA8: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80064CAC: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x80064CB0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80064CB4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80064CB8: lbu         $t7, 0x1D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1D);
    // 0x80064CBC: lbu         $t6, 0x1F($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1F);
    // 0x80064CC0: sll         $t5, $t7, 24
    ctx->r13 = S32(ctx->r15 << 24);
    // 0x80064CC4: lbu         $t7, 0x1E($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1E);
    // 0x80064CC8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x80064CCC: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80064CD0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80064CD4: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x80064CD8: ori         $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 | 0XFF;
    // 0x80064CDC: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80064CE0: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80064CE4: lui         $t6, 0xC78
    ctx->r14 = S32(0XC78 << 16);
    // 0x80064CE8: ori         $t6, $t6, 0x828C
    ctx->r14 = ctx->r14 | 0X828C;
    // 0x80064CEC: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80064CF0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80064CF4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80064CF8: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80064CFC: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80064D00: lui         $t5, 0xC78
    ctx->r13 = S32(0XC78 << 16);
    // 0x80064D04: ori         $t5, $t5, 0x8C96
    ctx->r13 = ctx->r13 | 0X8C96;
    // 0x80064D08: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80064D0C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80064D10: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x80064D14: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_80064D18:
    // 0x80064D18: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80064D1C:
    // 0x80064D1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80064D20: jr          $ra
    // 0x80064D24: nop

    return;
    // 0x80064D24: nop

;}
RECOMP_FUNC void displaymasks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072F78: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80072F7C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072F80: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80072F84: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80072F88: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80072F8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80072F90: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80072F94: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80072F98: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x80072F9C: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x80072FA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80072FA4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80072FA8: lh          $t1, 0x288($v0)
    ctx->r9 = S32(MEM_H(ctx->r2, 0X288));
    // 0x80072FAC: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80072FB0: addiu       $t3, $t3, -0x1988
    ctx->r11 = ADD32(ctx->r11, -0X1988);
    // 0x80072FB4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80072FB8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80072FBC: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80072FC0: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80072FC4: lh          $t4, 0x18($v1)
    ctx->r12 = S32(MEM_H(ctx->r3, 0X18));
    // 0x80072FC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80072FCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80072FD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072FD4: bne         $t4, $at, L_80072FE4
    if (ctx->r12 != ctx->r1) {
        // 0x80072FD8: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80072FE4;
    }
    // 0x80072FD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80072FDC: b           L_80072FE8
    // 0x80072FE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80072FE8;
    // 0x80072FE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80072FE4:
    // 0x80072FE4: lbu         $t0, 0x27($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X27);
L_80072FE8:
    // 0x80072FE8: lbu         $t5, 0x344($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X344);
    // 0x80072FEC: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x80072FF0: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    // 0x80072FF4: beq         $t5, $zero, L_80073038
    if (ctx->r13 == 0) {
        // 0x80072FF8: addiu       $a2, $zero, 0xA15
        ctx->r6 = ADD32(0, 0XA15);
            goto L_80073038;
    }
    // 0x80072FF8: addiu       $a2, $zero, 0xA15
    ctx->r6 = ADD32(0, 0XA15);
    // 0x80072FFC: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x80073000: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80073004: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80073008: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007300C: jal         0x800724B0
    // 0x80073010: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    myospal(rdram, ctx);
        goto after_0;
    // 0x80073010: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80073014: lw          $v0, 0x20($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80073018: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007301C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80073020: addiu       $a0, $zero, 0xD9
    ctx->r4 = ADD32(0, 0XD9);
    // 0x80073024: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    // 0x80073028: addiu       $a2, $zero, 0xA15
    ctx->r6 = ADD32(0, 0XA15);
    // 0x8007302C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80073030: jal         0x800724B0
    // 0x80073034: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    myospal(rdram, ctx);
        goto after_1;
    // 0x80073034: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
L_80073038:
    // 0x80073038: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8007303C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80073040: jr          $ra
    // 0x80073044: nop

    return;
    // 0x80073044: nop

;}
RECOMP_FUNC void updateceilz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A70C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8005A710: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005A714: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005A718: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8005A71C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005A720: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x8005A724: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005A728: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005A72C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8005A730: lhu         $s0, 0x20($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X20);
    // 0x8005A734: lbu         $a1, 0x2C($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X2C);
    // 0x8005A738: lh          $t2, 0xC($v1)
    ctx->r10 = S32(MEM_H(ctx->r3, 0XC));
    // 0x8005A73C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8005A740: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x8005A744: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x8005A748: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005A74C: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x8005A750: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8005A754: addu        $s0, $t9, $at
    ctx->r16 = ADD32(ctx->r25, ctx->r1);
    // 0x8005A758: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8005A75C: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8005A760: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005A764: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x8005A768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005A76C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005A770: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005A774: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005A778: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005A77C: bne         $t3, $at, L_8005A7EC
    if (ctx->r11 != ctx->r1) {
        // 0x8005A780: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_8005A7EC;
    }
    // 0x8005A780: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8005A784: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005A788: blez        $t1, L_8005A828
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8005A78C: or          $s2, $t1, $zero
        ctx->r18 = ctx->r9 | 0;
            goto L_8005A828;
    }
    // 0x8005A78C: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x8005A790: sll         $s3, $t6, 16
    ctx->r19 = S32(ctx->r14 << 16);
    // 0x8005A794: sra         $t4, $s3, 16
    ctx->r12 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8005A798: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
L_8005A79C:
    // 0x8005A79C: lh          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8005A7A0: lh          $a2, 0x2($s0)
    ctx->r6 = S32(MEM_H(ctx->r16, 0X2));
    // 0x8005A7A4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8005A7A8: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8005A7AC: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8005A7B0: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x8005A7B4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8005A7B8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8005A7BC: jal         0x80098E64
    // 0x8005A7C0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    getceilzofslope(rdram, ctx);
        goto after_0;
    // 0x8005A7C0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_0:
    // 0x8005A7C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005A7C8: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x8005A7CC: slt         $at, $t9, $s2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8005A7D0: sra         $t8, $v0, 5
    ctx->r24 = S32(SIGNED(ctx->r2) >> 5);
    // 0x8005A7D4: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8005A7D8: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x8005A7DC: bne         $at, $zero, L_8005A79C
    if (ctx->r1 != 0) {
        // 0x8005A7E0: addiu       $s0, $s0, 0xA
        ctx->r16 = ADD32(ctx->r16, 0XA);
            goto L_8005A79C;
    }
    // 0x8005A7E0: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8005A7E4: b           L_8005A82C
    // 0x8005A7E8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_8005A82C;
    // 0x8005A7E8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_8005A7EC:
    // 0x8005A7EC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8005A7F0: lh          $t1, 0x4($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0X4));
    // 0x8005A7F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005A7F8: sra         $t0, $v0, 5
    ctx->r8 = S32(SIGNED(ctx->r2) >> 5);
    // 0x8005A7FC: beq         $t0, $t1, L_8005A828
    if (ctx->r8 == ctx->r9) {
        // 0x8005A800: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8005A828;
    }
    // 0x8005A800: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8005A804: blez        $a1, L_8005A828
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005A808: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_8005A828;
    }
    // 0x8005A808: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
L_8005A80C:
    // 0x8005A80C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005A810: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x8005A814: slt         $at, $t2, $s2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8005A818: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x8005A81C: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x8005A820: bne         $at, $zero, L_8005A80C
    if (ctx->r1 != 0) {
        // 0x8005A824: addiu       $s0, $s0, 0xA
        ctx->r16 = ADD32(ctx->r16, 0XA);
            goto L_8005A80C;
    }
    // 0x8005A824: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
L_8005A828:
    // 0x8005A828: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_8005A82C:
    // 0x8005A82C: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8005A830: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8005A834: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8005A838: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8005A83C: jr          $ra
    // 0x8005A840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005A840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void setdefaultcontrollermode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D804: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004D808: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004D80C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8004D810: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004D814: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004D818: lui         $s1, 0x802A
    ctx->r17 = S32(0X802A << 16);
    // 0x8004D81C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004D820: addiu       $s1, $s1, 0x5770
    ctx->r17 = ADD32(ctx->r17, 0X5770);
    // 0x8004D824: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004D828: addiu       $s2, $zero, 0x38C
    ctx->r18 = ADD32(0, 0X38C);
    // 0x8004D82C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8004D830:
    // 0x8004D830: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D834: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8004D838: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004D83C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8004D840: mflo        $t6
    ctx->r14 = lo;
    // 0x8004D844: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x8004D848: sb          $s3, 0x280($v0)
    MEM_B(0X280, ctx->r2) = ctx->r19;
    // 0x8004D84C: jal         0x8004D888
    // 0x8004D850: sb          $zero, 0x386($v0)
    MEM_B(0X386, ctx->r2) = 0;
    func_8004D888(rdram, ctx);
        goto after_0;
    // 0x8004D850: sb          $zero, 0x386($v0)
    MEM_B(0X386, ctx->r2) = 0;
    after_0:
    // 0x8004D854: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004D858: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x8004D85C: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004D860: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8004D864: bne         $at, $zero, L_8004D830
    if (ctx->r1 != 0) {
        // 0x8004D868: nop
    
            goto L_8004D830;
    }
    // 0x8004D868: nop

    // 0x8004D86C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8004D870: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004D874: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004D878: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004D87C: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004D880: jr          $ra
    // 0x8004D884: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004D884: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void cansee(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092E68: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80092E6C: lw          $t9, 0xF0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x80092E70: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80092E74: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80092E78: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    // 0x80092E7C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80092E80: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80092E84: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80092E88: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80092E8C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80092E90: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80092E94: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80092E98: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80092E9C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80092EA0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80092EA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80092EA8: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80092EAC: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80092EB0: bne         $a0, $t9, L_80092ED0
    if (ctx->r4 != ctx->r25) {
        // 0x80092EB4: sw          $a2, 0xE8($sp)
        MEM_W(0XE8, ctx->r29) = ctx->r6;
            goto L_80092ED0;
    }
    // 0x80092EB4: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x80092EB8: lw          $t3, 0xF4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XF4));
    // 0x80092EBC: lh          $v1, 0xFE($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0XFE));
    // 0x80092EC0: bne         $a1, $t3, L_80092ED0
    if (ctx->r5 != ctx->r11) {
        // 0x80092EC4: xor         $v0, $t7, $v1
        ctx->r2 = ctx->r15 ^ ctx->r3;
            goto L_80092ED0;
    }
    // 0x80092EC4: xor         $v0, $t7, $v1
    ctx->r2 = ctx->r15 ^ ctx->r3;
    // 0x80092EC8: b           L_8009321C
    // 0x80092ECC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_8009321C;
    // 0x80092ECC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80092ED0:
    // 0x80092ED0: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80092ED4: lui         $a2, 0x8028
    ctx->r6 = S32(0X8028 << 16);
    // 0x80092ED8: sh          $a3, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = ctx->r7;
    // 0x80092EDC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80092EE0: addiu       $a2, $a2, -0x70D0
    ctx->r6 = ADD32(ctx->r6, -0X70D0);
    // 0x80092EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80092EE8:
    // 0x80092EE8: lh          $v1, 0x0($a2)
    ctx->r3 = S32(MEM_H(ctx->r6, 0X0));
    // 0x80092EEC: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80092EF0: addiu       $t5, $t5, -0x1988
    ctx->r13 = ADD32(ctx->r13, -0X1988);
    // 0x80092EF4: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80092EF8: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80092EFC: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80092F00: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80092F04: lh          $t6, 0x8($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X8));
    // 0x80092F08: lh          $a0, 0xA($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0XA));
    // 0x80092F0C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80092F10: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80092F14: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80092F18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80092F1C: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x80092F20: blez        $a0, L_800931C0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80092F24: addu        $s5, $t7, $t8
        ctx->r21 = ADD32(ctx->r15, ctx->r24);
            goto L_800931C0;
    }
    // 0x80092F24: addu        $s5, $t7, $t8
    ctx->r21 = ADD32(ctx->r15, ctx->r24);
    // 0x80092F28: lw          $t9, 0xF0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x80092F2C: lw          $t2, 0xE0($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x80092F30: lw          $t3, 0xF4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XF4));
    // 0x80092F34: lw          $t4, 0xE4($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XE4));
    // 0x80092F38: sw          $v1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r3;
    // 0x80092F3C: sw          $a0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r4;
    // 0x80092F40: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x80092F44: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80092F48: subu        $s7, $t9, $t2
    ctx->r23 = SUB32(ctx->r25, ctx->r10);
    // 0x80092F4C: subu        $fp, $t3, $t4
    ctx->r30 = SUB32(ctx->r11, ctx->r12);
L_80092F50:
    // 0x80092F50: lh          $t5, 0x8($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0X8));
    // 0x80092F54: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80092F58: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x80092F5C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80092F60: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80092F64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80092F68: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80092F6C: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80092F70: lw          $v1, 0x0($s5)
    ctx->r3 = S32(MEM_W(ctx->r21, 0X0));
    // 0x80092F74: lw          $t3, 0x4($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80092F78: lw          $a0, 0x4($s5)
    ctx->r4 = S32(MEM_W(ctx->r21, 0X4));
    // 0x80092F7C: subu        $a2, $v1, $t9
    ctx->r6 = SUB32(ctx->r3, ctx->r25);
    // 0x80092F80: multu       $fp, $a2
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092F84: subu        $t1, $a0, $t3
    ctx->r9 = SUB32(ctx->r4, ctx->r11);
    // 0x80092F88: lw          $t8, 0xE0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x80092F8C: lw          $t2, 0xE4($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XE4));
    // 0x80092F90: subu        $a1, $v1, $t8
    ctx->r5 = SUB32(ctx->r3, ctx->r24);
    // 0x80092F94: subu        $a3, $a0, $t2
    ctx->r7 = SUB32(ctx->r4, ctx->r10);
    // 0x80092F98: mflo        $t4
    ctx->r12 = lo;
    // 0x80092F9C: nop

    // 0x80092FA0: nop

    // 0x80092FA4: multu       $s7, $t1
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092FA8: mflo        $t5
    ctx->r13 = lo;
    // 0x80092FAC: subu        $t0, $t4, $t5
    ctx->r8 = SUB32(ctx->r12, ctx->r13);
    // 0x80092FB0: blezl       $t0, L_800931A8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80092FB4: lw          $v0, 0xCC($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0XCC));
            goto L_800931A8;
    }
    goto skip_0;
    // 0x80092FB4: lw          $v0, 0xCC($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XCC));
    skip_0:
    // 0x80092FB8: multu       $fp, $a1
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092FBC: mflo        $t6
    ctx->r14 = lo;
    // 0x80092FC0: nop

    // 0x80092FC4: nop

    // 0x80092FC8: multu       $s7, $a3
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092FCC: mflo        $t7
    ctx->r15 = lo;
    // 0x80092FD0: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80092FD4: bltz        $v0, L_800931A4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80092FD8: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800931A4;
    }
    // 0x80092FD8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092FDC: beql        $at, $zero, L_800931A8
    if (ctx->r1 == 0) {
        // 0x80092FE0: lw          $v0, 0xCC($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0XCC));
            goto L_800931A8;
    }
    goto skip_1;
    // 0x80092FE0: lw          $v0, 0xCC($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XCC));
    skip_1:
    // 0x80092FE4: multu       $a3, $a2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092FE8: mflo        $t8
    ctx->r24 = lo;
    // 0x80092FEC: nop

    // 0x80092FF0: nop

    // 0x80092FF4: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092FF8: mflo        $t9
    ctx->r25 = lo;
    // 0x80092FFC: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x80093000: bltz        $v0, L_800931A4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80093004: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800931A4;
    }
    // 0x80093004: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80093008: beq         $at, $zero, L_800931A4
    if (ctx->r1 == 0) {
        // 0x8009300C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800931A4;
    }
    // 0x8009300C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80093010: lh          $s0, 0xC($s5)
    ctx->r16 = S32(MEM_H(ctx->r21, 0XC));
    // 0x80093014: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80093018: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8009301C: bltz        $s0, L_8009303C
    if (SIGNED(ctx->r16) < 0) {
        // 0x80093020: sra         $a2, $t0, 31
        ctx->r6 = S32(SIGNED(ctx->r8) >> 31);
            goto L_8009303C;
    }
    // 0x80093020: sra         $a2, $t0, 31
    ctx->r6 = S32(SIGNED(ctx->r8) >> 31);
    // 0x80093024: lh          $t2, 0xE($s5)
    ctx->r10 = S32(MEM_H(ctx->r21, 0XE));
    // 0x80093028: lh          $s4, 0xB2($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0XB2));
    // 0x8009302C: lw          $t4, 0xF8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XF8));
    // 0x80093030: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80093034: beq         $t3, $zero, L_80093044
    if (ctx->r11 == 0) {
        // 0x80093038: lw          $t5, 0xE8($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0XE8));
            goto L_80093044;
    }
    // 0x80093038: lw          $t5, 0xE8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XE8));
L_8009303C:
    // 0x8009303C: b           L_8009321C
    // 0x80093040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009321C;
    // 0x80093040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80093044:
    // 0x80093044: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80093048: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8009304C: sra         $t4, $s7, 31
    ctx->r12 = S32(SIGNED(ctx->r23) >> 31);
    // 0x80093050: sra         $t2, $fp, 31
    ctx->r10 = S32(SIGNED(ctx->r30) >> 31);
    // 0x80093054: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80093058: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x8009305C: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80093060: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x80093064: sw          $fp, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r30;
    // 0x80093068: jal         0x80091704
    // 0x8009306C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    divscale24(rdram, ctx);
        goto after_0;
    // 0x8009306C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    after_0:
    // 0x80093070: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80093074: lw          $a0, 0x68($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X68));
    // 0x80093078: lw          $a1, 0x6C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x8009307C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80093080: jal         0x8008FF80
    // 0x80093084: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    mulscale24(rdram, ctx);
        goto after_1;
    // 0x80093084: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    after_1:
    // 0x80093088: lw          $t7, 0xE0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x8009308C: sra         $a2, $s1, 31
    ctx->r6 = S32(SIGNED(ctx->r17) >> 31);
    // 0x80093090: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80093094: lw          $a0, 0x50($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80093098: lw          $a1, 0x54($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8009309C: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x800930A0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800930A4: jal         0x8008FF80
    // 0x800930A8: addu        $s3, $v0, $t7
    ctx->r19 = ADD32(ctx->r2, ctx->r15);
    mulscale24(rdram, ctx);
        goto after_2;
    // 0x800930A8: addu        $s3, $v0, $t7
    ctx->r19 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x800930AC: lw          $t8, 0xE4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XE4));
    // 0x800930B0: lw          $a0, 0x58($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800930B4: lw          $a1, 0x5C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800930B8: lw          $a2, 0x68($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800930BC: lw          $a3, 0x6C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x800930C0: jal         0x8008FF80
    // 0x800930C4: addu        $s2, $v0, $t8
    ctx->r18 = ADD32(ctx->r2, ctx->r24);
    mulscale24(rdram, ctx);
        goto after_3;
    // 0x800930C4: addu        $s2, $v0, $t8
    ctx->r18 = ADD32(ctx->r2, ctx->r24);
    after_3:
    // 0x800930C8: lw          $t9, 0xE8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x800930CC: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x800930D0: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800930D4: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x800930D8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800930DC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800930E0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800930E4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800930E8: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    // 0x800930EC: jal         0x80099104
    // 0x800930F0: addu        $s1, $v0, $t9
    ctx->r17 = ADD32(ctx->r2, ctx->r25);
    getzsofslope(rdram, ctx);
        goto after_4;
    // 0x800930F0: addu        $s1, $v0, $t9
    ctx->r17 = ADD32(ctx->r2, ctx->r25);
    after_4:
    // 0x800930F4: lw          $t4, 0xB8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800930F8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800930FC: lw          $t5, 0xB4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x80093100: slt         $at, $t4, $s1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80093104: beq         $at, $zero, L_80093118
    if (ctx->r1 == 0) {
        // 0x80093108: sra         $t6, $a0, 16
        ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
            goto L_80093118;
    }
    // 0x80093108: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009310C: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80093110: bne         $at, $zero, L_80093120
    if (ctx->r1 != 0) {
        // 0x80093114: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80093120;
    }
    // 0x80093114: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_80093118:
    // 0x80093118: b           L_8009321C
    // 0x8009311C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009321C;
    // 0x8009311C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80093120:
    // 0x80093120: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x80093124: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80093128: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8009312C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80093130: jal         0x80099104
    // 0x80093134: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    getzsofslope(rdram, ctx);
        goto after_5;
    // 0x80093134: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    after_5:
    // 0x80093138: lw          $t8, 0xB8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x8009313C: addiu       $v0, $s6, -0x1
    ctx->r2 = ADD32(ctx->r22, -0X1);
    // 0x80093140: lw          $t9, 0xB4($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x80093144: slt         $at, $t8, $s1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80093148: beq         $at, $zero, L_8009315C
    if (ctx->r1 == 0) {
        // 0x8009314C: sll         $t2, $v0, 1
        ctx->r10 = S32(ctx->r2 << 1);
            goto L_8009315C;
    }
    // 0x8009314C: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80093150: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80093154: bne         $at, $zero, L_80093164
    if (ctx->r1 != 0) {
        // 0x80093158: lui         $t3, 0x8028
        ctx->r11 = S32(0X8028 << 16);
            goto L_80093164;
    }
    // 0x80093158: lui         $t3, 0x8028
    ctx->r11 = S32(0X8028 << 16);
L_8009315C:
    // 0x8009315C: b           L_8009321C
    // 0x80093160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009321C;
    // 0x80093160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80093164:
    // 0x80093164: bltz        $v0, L_8009318C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80093168: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8009318C;
    }
    // 0x80093168: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009316C: addiu       $t3, $t3, -0x70D0
    ctx->r11 = ADD32(ctx->r11, -0X70D0);
    // 0x80093170: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
L_80093174:
    // 0x80093174: lh          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80093178: beq         $s0, $t4, L_8009318C
    if (ctx->r16 == ctx->r12) {
        // 0x8009317C: nop
    
            goto L_8009318C;
    }
    // 0x8009317C: nop

    // 0x80093180: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80093184: bgez        $v1, L_80093174
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80093188: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_80093174;
    }
    // 0x80093188: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_8009318C:
    // 0x8009318C: bgez        $v1, L_800931A4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80093190: sll         $t5, $s6, 1
        ctx->r13 = S32(ctx->r22 << 1);
            goto L_800931A4;
    }
    // 0x80093190: sll         $t5, $s6, 1
    ctx->r13 = S32(ctx->r22 << 1);
    // 0x80093194: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80093198: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8009319C: sh          $s0, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = ctx->r16;
    // 0x800931A0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_800931A4:
    // 0x800931A4: lw          $v0, 0xCC($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XCC));
L_800931A8:
    // 0x800931A8: addiu       $s5, $s5, 0x24
    ctx->r21 = ADD32(ctx->r21, 0X24);
    // 0x800931AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800931B0: bgtz        $v0, L_80092F50
    if (SIGNED(ctx->r2) > 0) {
        // 0x800931B4: sw          $v0, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r2;
            goto L_80092F50;
    }
    // 0x800931B4: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // 0x800931B8: lw          $a2, 0x78($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800931BC: lw          $a1, 0xAC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XAC));
L_800931C0:
    // 0x800931C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800931C4: slt         $at, $a1, $s6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800931C8: bne         $at, $zero, L_80092EE8
    if (ctx->r1 != 0) {
        // 0x800931CC: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80092EE8;
    }
    // 0x800931CC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800931D0: addiu       $v0, $s6, -0x1
    ctx->r2 = ADD32(ctx->r22, -0X1);
    // 0x800931D4: bltz        $v0, L_80093218
    if (SIGNED(ctx->r2) < 0) {
        // 0x800931D8: sll         $t6, $v0, 1
        ctx->r14 = S32(ctx->r2 << 1);
            goto L_80093218;
    }
    // 0x800931D8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800931DC: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800931E0: addiu       $t7, $t7, -0x70D0
    ctx->r15 = ADD32(ctx->r15, -0X70D0);
    // 0x800931E4: lui         $a0, 0x8028
    ctx->r4 = S32(0X8028 << 16);
    // 0x800931E8: addiu       $a0, $a0, -0x70D0
    ctx->r4 = ADD32(ctx->r4, -0X70D0);
    // 0x800931EC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800931F0: lh          $v1, 0xFE($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0XFE));
    // 0x800931F4: lh          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X0));
L_800931F8:
    // 0x800931F8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800931FC: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80093200: bne         $v1, $t8, L_80093210
    if (ctx->r3 != ctx->r24) {
        // 0x80093204: nop
    
            goto L_80093210;
    }
    // 0x80093204: nop

    // 0x80093208: b           L_8009321C
    // 0x8009320C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009321C;
    // 0x8009320C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80093210:
    // 0x80093210: beql        $at, $zero, L_800931F8
    if (ctx->r1 == 0) {
        // 0x80093214: lh          $t8, 0x0($v0)
        ctx->r24 = S32(MEM_H(ctx->r2, 0X0));
            goto L_800931F8;
    }
    goto skip_2;
    // 0x80093214: lh          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X0));
    skip_2:
L_80093218:
    // 0x80093218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009321C:
    // 0x8009321C: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80093220: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80093224: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80093228: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8009322C: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80093230: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80093234: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80093238: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8009323C: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80093240: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80093244: jr          $ra
    // 0x80093248: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80093248: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void stopallsounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005932C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059334: jal         0x80058348
    // 0x80059338: nop

    func_80058348(rdram, ctx);
        goto after_0;
    // 0x80059338: nop

    after_0:
    // 0x8005933C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059340: beq         $v0, $at, L_80059374
    if (ctx->r2 == ctx->r1) {
        // 0x80059344: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80059374;
    }
    // 0x80059344: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80059348: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8005934C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80059350: addiu       $t7, $t7, -0x5F08
    ctx->r15 = ADD32(ctx->r15, -0X5F08);
    // 0x80059354: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80059358: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8005935C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80059360: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80059364: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x80059368: addiu       $a0, $a0, -0x5FA0
    ctx->r4 = ADD32(ctx->r4, -0X5FA0);
    // 0x8005936C: jal         0x800BB610
    // 0x80059370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80059370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80059374:
    // 0x80059374: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80059378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005937C: jr          $ra
    // 0x80059380: nop

    return;
    // 0x80059380: nop

;}
RECOMP_FUNC void alSeqFileNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0348: lh          $t6, 0x2($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X2));
    // 0x800C034C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0350: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C0354: blez        $t6, L_800C0380
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C0358: nop
    
            goto L_800C0380;
    }
    // 0x800C0358: nop

    // 0x800C035C: lw          $t7, 0x4($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X4));
L_800C0360:
    // 0x800C0360: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C0364: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C0368: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C036C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800C0370: lh          $t9, 0x2($a0)
    ctx->r25 = S32(MEM_H(ctx->r4, 0X2));
    // 0x800C0374: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C0378: bnel        $at, $zero, L_800C0360
    if (ctx->r1 != 0) {
        // 0x800C037C: lw          $t7, 0x4($v1)
        ctx->r15 = S32(MEM_W(ctx->r3, 0X4));
            goto L_800C0360;
    }
    goto skip_0;
    // 0x800C037C: lw          $t7, 0x4($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X4));
    skip_0:
L_800C0380:
    // 0x800C0380: jr          $ra
    // 0x800C0384: nop

    return;
    // 0x800C0384: nop

;}
RECOMP_FUNC void stopinterpolation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075428: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8007542C: addiu       $t1, $t1, 0x1390
    ctx->r9 = ADD32(ctx->r9, 0X1390);
    // 0x80075430: lw          $v1, 0x0($t1)
    ctx->r3 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80075434: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80075438: lw          $a1, 0x1394($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, 0X1394));
    // 0x8007543C: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80075440: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80075444: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80075448: bne         $at, $zero, L_800754CC
    if (ctx->r1 != 0) {
        // 0x8007544C: lui         $t6, 0x802B
        ctx->r14 = S32(0X802B << 16);
            goto L_800754CC;
    }
    // 0x8007544C: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x80075450: addiu       $t6, $t6, -0x7A60
    ctx->r14 = ADD32(ctx->r14, -0X7A60);
    // 0x80075454: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80075458: lui         $a1, 0x802A
    ctx->r5 = S32(0X802A << 16);
    // 0x8007545C: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x80075460: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x80075464: addiu       $t2, $t2, 0x75A0
    ctx->r10 = ADD32(ctx->r10, 0X75A0);
    // 0x80075468: addiu       $t3, $t3, -0x7A60
    ctx->r11 = ADD32(ctx->r11, -0X7A60);
    // 0x8007546C: addiu       $a1, $a1, 0x65A0
    ctx->r5 = ADD32(ctx->r5, 0X65A0);
    // 0x80075470: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x80075474: addu        $a3, $a2, $t6
    ctx->r7 = ADD32(ctx->r6, ctx->r14);
L_80075478:
    // 0x80075478: lw          $t8, 0x0($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8007547C: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80075480: sll         $v0, $t9, 2
    ctx->r2 = S32(ctx->r25 << 2);
    // 0x80075484: bne         $a0, $t8, L_800754BC
    if (ctx->r4 != ctx->r24) {
        // 0x80075488: addu        $t4, $a1, $v0
        ctx->r12 = ADD32(ctx->r5, ctx->r2);
            goto L_800754BC;
    }
    // 0x80075488: addu        $t4, $a1, $v0
    ctx->r12 = ADD32(ctx->r5, ctx->r2);
    // 0x8007548C: lw          $t5, 0x0($t4)
    ctx->r13 = S32(MEM_W(ctx->r12, 0X0));
    // 0x80075490: addu        $t7, $a1, $a2
    ctx->r15 = ADD32(ctx->r5, ctx->r6);
    // 0x80075494: addu        $t6, $t2, $v0
    ctx->r14 = ADD32(ctx->r10, ctx->r2);
    // 0x80075498: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8007549C: lw          $t8, 0x0($t6)
    ctx->r24 = S32(MEM_W(ctx->r14, 0X0));
    // 0x800754A0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800754A4: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800754A8: addu        $t9, $t2, $a2
    ctx->r25 = ADD32(ctx->r10, ctx->r6);
    // 0x800754AC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800754B0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800754B4: lw          $t5, 0x0($t4)
    ctx->r13 = S32(MEM_W(ctx->r12, 0X0));
    // 0x800754B8: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_800754BC:
    // 0x800754BC: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x800754C0: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800754C4: beq         $at, $zero, L_80075478
    if (ctx->r1 == 0) {
        // 0x800754C8: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80075478;
    }
    // 0x800754C8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
L_800754CC:
    // 0x800754CC: jr          $ra
    // 0x800754D0: nop

    return;
    // 0x800754D0: nop

;}
RECOMP_FUNC void dmulscale12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800906B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800906B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800906BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800906C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800906C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800906C8: jal         0x800BB8F8
    // 0x800906CC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800906CC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800906D0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800906D4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800906D8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800906DC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800906E0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800906E4: jal         0x800BB8F8
    // 0x800906E8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800906E8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x800906EC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800906F0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800906F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800906F8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x800906FC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090700: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090704: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090708: jal         0x800BBA24
    // 0x8009070C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009070C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_2:
    // 0x80090710: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090714: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090718: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009071C: jr          $ra
    // 0x80090720: nop

    return;
    // 0x80090720: nop

;}
RECOMP_FUNC void func_80057EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057EB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80057EB8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80057EBC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80057EC0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80057EC4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80057EC8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80057ECC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80057ED0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80057ED4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x80057ED8: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x80057EDC: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x80057EE0: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x80057EE4: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80057EE8: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80057EEC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80057EF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80057EF4: addiu       $s6, $s6, 0x4D90
    ctx->r22 = ADD32(ctx->r22, 0X4D90);
    // 0x80057EF8: addiu       $s5, $s5, -0x1830
    ctx->r21 = ADD32(ctx->r21, -0X1830);
    // 0x80057EFC: addiu       $s4, $s4, -0x25F0
    ctx->r20 = ADD32(ctx->r20, -0X25F0);
    // 0x80057F00: addiu       $s3, $s3, -0x18F0
    ctx->r19 = ADD32(ctx->r19, -0X18F0);
    // 0x80057F04: addiu       $s2, $s2, 0x4D20
    ctx->r18 = ADD32(ctx->r18, 0X4D20);
    // 0x80057F08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80057F0C: sll         $t6, $s1, 4
    ctx->r14 = S32(ctx->r17 << 4);
L_80057F10:
    // 0x80057F10: addu        $s0, $s3, $t6
    ctx->r16 = ADD32(ctx->r19, ctx->r14);
    // 0x80057F14: lb          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80057F18: beql        $t7, $zero, L_80057F9C
    if (ctx->r15 == 0) {
        // 0x80057F1C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80057F9C;
    }
    goto skip_0;
    // 0x80057F1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80057F20: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    // 0x80057F24: bnel        $s7, $t8, L_80057F9C
    if (ctx->r23 != ctx->r24) {
        // 0x80057F28: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80057F9C;
    }
    goto skip_1;
    // 0x80057F28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80057F2C: lw          $t9, 0x8($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X8));
    // 0x80057F30: lw          $t2, 0x4($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X4));
    // 0x80057F34: lw          $a0, 0x0($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80057F38: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80057F3C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80057F40: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80057F44: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80057F48: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80057F4C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80057F50: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80057F54: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x80057F58: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80057F5C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80057F60: jal         0x800C16E0
    // 0x80057F64: lh          $a1, 0x0($t4)
    ctx->r5 = S32(MEM_H(ctx->r12, 0X0));
    alSndpSetSound(rdram, ctx);
        goto after_0;
    // 0x80057F64: lh          $a1, 0x0($t4)
    ctx->r5 = S32(MEM_H(ctx->r12, 0X0));
    after_0:
    // 0x80057F68: jal         0x800C2410
    // 0x80057F6C: lw          $a0, 0x0($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X0));
    alSndpStop(rdram, ctx);
        goto after_1;
    // 0x80057F6C: lw          $a0, 0x0($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X0));
    after_1:
    // 0x80057F70: lw          $a0, 0x4($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X4));
    // 0x80057F74: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
    // 0x80057F78: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80057F7C: addu        $v0, $s5, $a0
    ctx->r2 = ADD32(ctx->r21, ctx->r4);
    // 0x80057F80: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x80057F84: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80057F88: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80057F8C: xor         $t9, $t5, $t8
    ctx->r25 = ctx->r13 ^ ctx->r24;
    // 0x80057F90: jal         0x800590B0
    // 0x80057F94: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    testcallback(rdram, ctx);
        goto after_2;
    // 0x80057F94: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    after_2:
    // 0x80057F98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80057F9C:
    // 0x80057F9C: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x80057FA0: sra         $s1, $t0, 16
    ctx->r17 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80057FA4: slti        $at, $s1, 0xC
    ctx->r1 = SIGNED(ctx->r17) < 0XC ? 1 : 0;
    // 0x80057FA8: bnel        $at, $zero, L_80057F10
    if (ctx->r1 != 0) {
        // 0x80057FAC: sll         $t6, $s1, 4
        ctx->r14 = S32(ctx->r17 << 4);
            goto L_80057F10;
    }
    goto skip_2;
    // 0x80057FAC: sll         $t6, $s1, 4
    ctx->r14 = S32(ctx->r17 << 4);
    skip_2:
    // 0x80057FB0: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80057FB4: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80057FB8: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80057FBC: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80057FC0: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80057FC4: lw          $s4, 0x24($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80057FC8: lw          $s5, 0x28($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80057FCC: lw          $s6, 0x2C($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80057FD0: lw          $s7, 0x30($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80057FD4: jr          $ra
    // 0x80057FD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80057FD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80061FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061FC8: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x80061FCC: lhu         $t7, -0x1400($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X1400);
    // 0x80061FD0: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x80061FD4: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80061FD8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80061FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061FE0: beq         $t6, $t7, L_800622D0
    if (ctx->r14 == ctx->r15) {
        // 0x80061FE4: sw          $a0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r4;
            goto L_800622D0;
    }
    // 0x80061FE4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80061FE8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80061FEC: addiu       $a1, $a1, 0x4418
    ctx->r5 = ADD32(ctx->r5, 0X4418);
    // 0x80061FF0: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80061FF4: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x80061FF8: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    // 0x80061FFC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80062000: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80062004: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80062008: sh          $t6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r14;
    // 0x8006200C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80062010: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80062014: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062018: jal         0x80063880
    // 0x8006201C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    func_80063880(rdram, ctx);
        goto after_0;
    // 0x8006201C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80062020: lw          $t3, 0x5C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x80062024: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80062028: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8006202C: addiu       $a1, $a1, 0x4418
    ctx->r5 = ADD32(ctx->r5, 0X4418);
    // 0x80062030: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80062034: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80062038: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8006203C: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x80062040: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80062044: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80062048: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006204C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80062050: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80062054: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80062058: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8006205C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80062060: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80062064: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80062068: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006206C: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80062070: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80062074: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80062078: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006207C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80062080: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80062084: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80062088: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006208C: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x80062090: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x80062094: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80062098: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8006209C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800620A0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800620A4: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800620A8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800620AC: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x800620B0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800620B4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800620B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800620BC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800620C0: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800620C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800620C8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800620CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800620D0: jal         0x80063880
    // 0x800620D4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_80063880(rdram, ctx);
        goto after_1;
    // 0x800620D4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_1:
    // 0x800620D8: lw          $t4, 0x44($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800620DC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x800620E0: addiu       $t8, $v0, 0x20
    ctx->r24 = ADD32(ctx->r2, 0X20);
    // 0x800620E4: addiu       $a1, $a1, 0x4418
    ctx->r5 = ADD32(ctx->r5, 0X4418);
    // 0x800620E8: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x800620EC: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800620F0: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800620F4: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800620F8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800620FC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80062100: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x80062104: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80062108: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006210C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80062110: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80062114: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80062118: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8006211C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80062120: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80062124: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80062128: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006212C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80062130: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80062134: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80062138: addiu       $t3, $t3, -0x1B34
    ctx->r11 = ADD32(ctx->r11, -0X1B34);
    // 0x8006213C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80062140: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80062144: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80062148: lh          $t8, 0x62($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X62));
    // 0x8006214C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80062150: addiu       $t6, $t6, -0x5010
    ctx->r14 = ADD32(ctx->r14, -0X5010);
    // 0x80062154: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80062158: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8006215C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80062160: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
    // 0x80062164: lhu         $t0, 0x12($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X12);
    // 0x80062168: lhu         $t7, 0x14($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X14);
    // 0x8006216C: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    // 0x80062170: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x80062174: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062178: mflo        $t1
    ctx->r9 = lo;
    // 0x8006217C: addiu       $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x80062180: sra         $t8, $t1, 2
    ctx->r24 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80062184: addiu       $t1, $t8, -0x1
    ctx->r9 = ADD32(ctx->r24, -0X1);
    // 0x80062188: slti        $at, $t1, 0x7FF
    ctx->r1 = SIGNED(ctx->r9) < 0X7FF ? 1 : 0;
    // 0x8006218C: beq         $at, $zero, L_8006219C
    if (ctx->r1 == 0) {
        // 0x80062190: nop
    
            goto L_8006219C;
    }
    // 0x80062190: nop

    // 0x80062194: b           L_8006219C
    // 0x80062198: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
        goto L_8006219C;
    // 0x80062198: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_8006219C:
    // 0x8006219C: bgez        $t0, L_800621AC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800621A0: sra         $v0, $t0, 4
        ctx->r2 = S32(SIGNED(ctx->r8) >> 4);
            goto L_800621AC;
    }
    // 0x800621A0: sra         $v0, $t0, 4
    ctx->r2 = S32(SIGNED(ctx->r8) >> 4);
    // 0x800621A4: addiu       $at, $t0, 0xF
    ctx->r1 = ADD32(ctx->r8, 0XF);
    // 0x800621A8: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_800621AC:
    // 0x800621AC: bgtz        $v0, L_800621BC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800621B0: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800621BC;
    }
    // 0x800621B0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800621B4: b           L_800621BC
    // 0x800621B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_800621BC;
    // 0x800621B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800621BC:
    // 0x800621BC: bgtz        $v0, L_800621CC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800621C0: addiu       $t9, $t1, 0x7FF
        ctx->r25 = ADD32(ctx->r9, 0X7FF);
            goto L_800621CC;
    }
    // 0x800621C0: addiu       $t9, $t1, 0x7FF
    ctx->r25 = ADD32(ctx->r9, 0X7FF);
    // 0x800621C4: b           L_800621D0
    // 0x800621C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_800621D0;
    // 0x800621C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800621CC:
    // 0x800621CC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_800621D0:
    // 0x800621D0: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x800621D4: bne         $t0, $zero, L_800621E0
    if (ctx->r8 != 0) {
        // 0x800621D8: nop
    
            goto L_800621E0;
    }
    // 0x800621D8: nop

    // 0x800621DC: break       7
    do_break(2147885532);
L_800621E0:
    // 0x800621E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800621E4: bne         $t0, $at, L_800621F8
    if (ctx->r8 != ctx->r1) {
        // 0x800621E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800621F8;
    }
    // 0x800621E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800621EC: bne         $t9, $at, L_800621F8
    if (ctx->r25 != ctx->r1) {
        // 0x800621F0: nop
    
            goto L_800621F8;
    }
    // 0x800621F0: nop

    // 0x800621F4: break       6
    do_break(2147885556);
L_800621F8:
    // 0x800621F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800621FC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80062200: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80062204: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x80062208: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8006220C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80062210: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80062214: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80062218: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006221C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80062220: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x80062224: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80062228: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8006222C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80062230: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80062234: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80062238: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8006223C: lhu         $t7, 0x12($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X12);
    // 0x80062240: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80062244: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80062248: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x8006224C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80062250: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80062254: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80062258: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8006225C: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x80062260: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80062264: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80062268: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006226C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80062270: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80062274: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80062278: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8006227C: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80062280: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80062284: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80062288: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006228C: lhu         $t8, 0x14($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X14);
    // 0x80062290: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80062294: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80062298: lhu         $t8, 0x12($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X12);
    // 0x8006229C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800622A0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800622A4: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800622A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800622AC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800622B0: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800622B4: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800622B8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800622BC: lw          $t8, 0x0($t3)
    ctx->r24 = S32(MEM_W(ctx->r11, 0X0));
    // 0x800622C0: lw          $t6, 0x1C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800622C4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800622C8: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800622CC: sh          $t6, -0x1400($at)
    MEM_H(-0X1400, ctx->r1) = ctx->r14;
L_800622D0:
    // 0x800622D0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800622D4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800622D8: jr          $ra
    // 0x800622DC: nop

    return;
    // 0x800622DC: nop

;}
RECOMP_FUNC void dmulscale8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800904F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800904F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800904FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090500: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090504: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090508: jal         0x800BB8F8
    // 0x8009050C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009050C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090510: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090514: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090518: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009051C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090520: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090524: jal         0x800BB8F8
    // 0x80090528: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090528: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009052C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090530: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090534: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090538: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009053C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090540: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090544: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090548: jal         0x800BBA24
    // 0x8009054C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009054C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x80090550: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090554: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090558: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009055C: jr          $ra
    // 0x80090560: nop

    return;
    // 0x80090560: nop

;}
RECOMP_FUNC void dmulscale10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800905D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800905D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800905DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800905E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800905E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800905E8: jal         0x800BB8F8
    // 0x800905EC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800905EC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800905F0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800905F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800905F8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800905FC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090600: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090604: jal         0x800BB8F8
    // 0x80090608: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090608: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009060C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090610: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090614: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090618: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009061C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090620: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090624: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090628: jal         0x800BBA24
    // 0x8009062C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009062C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_2:
    // 0x80090630: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090638: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009063C: jr          $ra
    // 0x80090640: nop

    return;
    // 0x80090640: nop

;}
RECOMP_FUNC void hitradius(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087994: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80087998: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8008799C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800879A0: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800879A4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800879A8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800879AC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800879B0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800879B4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800879B8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800879BC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800879C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800879C4: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x800879C8: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800879CC: sw          $a2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r6;
    // 0x800879D0: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x800879D4: addiu       $t7, $t7, -0x1710
    ctx->r15 = ADD32(ctx->r15, -0X1710);
    // 0x800879D8: lw          $at, 0x0($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800879DC: addiu       $t6, $sp, 0x80
    ctx->r14 = ADD32(ctx->r29, 0X80);
    // 0x800879E0: addiu       $fp, $zero, 0x2C
    ctx->r30 = ADD32(0, 0X2C);
    // 0x800879E4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800879E8: lwr         $at, 0x6($t7)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r15, 0X6);
    // 0x800879EC: lui         $s7, 0x8024
    ctx->r23 = S32(0X8024 << 16);
    // 0x800879F0: addiu       $s7, $s7, 0x6BA8
    ctx->r23 = ADD32(ctx->r23, 0X6BA8);
    // 0x800879F4: swr         $at, 0x6($t6)
    do_swr(rdram, 0X6, ctx->r14, ctx->r1);
    // 0x800879F8: lh          $t4, 0xCA($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800879FC: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x80087A00: lui         $a0, 0x802A
    ctx->r4 = S32(0X802A << 16);
    // 0x80087A04: multu       $t4, $fp
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80087A08: lui         $s6, 0x8022
    ctx->r22 = S32(0X8022 << 16);
    // 0x80087A0C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80087A10: addiu       $s6, $s6, 0x61A8
    ctx->r22 = ADD32(ctx->r22, 0X61A8);
    // 0x80087A14: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    // 0x80087A18: mflo        $t5
    ctx->r13 = lo;
    // 0x80087A1C: addu        $s3, $s7, $t5
    ctx->r19 = ADD32(ctx->r23, ctx->r13);
    // 0x80087A20: lh          $t9, 0xE($s3)
    ctx->r25 = S32(MEM_H(ctx->r19, 0XE));
    // 0x80087A24: beq         $t9, $at, L_80087D40
    if (ctx->r25 == ctx->r1) {
        // 0x80087A28: nop
    
            goto L_80087D40;
    }
    // 0x80087A28: nop

    // 0x80087A2C: lh          $t8, 0x10($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80087A30: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x80087A34: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x80087A38: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80087A3C: sh          $t8, 0x300($at)
    MEM_H(0X300, ctx->r1) = ctx->r24;
    // 0x80087A40: lw          $a0, 0x54($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X54));
L_80087A44:
    // 0x80087A44: lw          $t6, 0xA8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x80087A48: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x80087A4C: lh          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_H(ctx->r4, 0X0));
    // 0x80087A50: addiu       $t4, $t4, -0x1988
    ctx->r12 = ADD32(ctx->r12, -0X1988);
    // 0x80087A54: lw          $t9, 0x8($s3)
    ctx->r25 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80087A58: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80087A5C: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80087A60: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80087A64: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x80087A68: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80087A6C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80087A70: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x80087A74: lw          $t7, 0xCC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80087A78: subu        $t8, $t5, $t9
    ctx->r24 = SUB32(ctx->r13, ctx->r25);
    // 0x80087A7C: sra         $t6, $t8, 8
    ctx->r14 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80087A80: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80087A84: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80087A88: beq         $at, $zero, L_80087B80
    if (ctx->r1 == 0) {
        // 0x80087A8C: sw          $a0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r4;
            goto L_80087B80;
    }
    // 0x80087A8C: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80087A90: lh          $t3, 0x8($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X8));
    // 0x80087A94: lw          $t1, 0x0($s3)
    ctx->r9 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80087A98: lw          $t2, 0x4($s3)
    ctx->r10 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80087A9C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80087AA0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80087AA4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80087AA8: addu        $a2, $s6, $t4
    ctx->r6 = ADD32(ctx->r22, ctx->r12);
    // 0x80087AAC: lw          $t5, 0x0($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X0));
    // 0x80087AB0: subu        $v0, $t5, $t1
    ctx->r2 = SUB32(ctx->r13, ctx->r9);
    // 0x80087AB4: blez        $v0, L_80087AC4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087AB8: negu        $a1, $v0
        ctx->r5 = SUB32(0, ctx->r2);
            goto L_80087AC4;
    }
    // 0x80087AB8: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    // 0x80087ABC: b           L_80087AC4
    // 0x80087AC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80087AC4;
    // 0x80087AC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80087AC4:
    // 0x80087AC4: lw          $t9, 0x4($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X4));
    // 0x80087AC8: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80087ACC: lw          $t6, 0xCC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80087AD0: subu        $v0, $t9, $t2
    ctx->r2 = SUB32(ctx->r25, ctx->r10);
    // 0x80087AD4: blez        $v0, L_80087AE4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087AD8: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80087AE4;
    }
    // 0x80087AD8: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80087ADC: b           L_80087AE4
    // 0x80087AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80087AE4;
    // 0x80087AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80087AE4:
    // 0x80087AE4: addu        $t8, $a0, $a1
    ctx->r24 = ADD32(ctx->r4, ctx->r5);
    // 0x80087AE8: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80087AEC: beq         $at, $zero, L_80087B08
    if (ctx->r1 == 0) {
        // 0x80087AF0: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_80087B08;
    }
    // 0x80087AF0: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80087AF4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80087AF8: jal         0x800B147C
    // 0x80087AFC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    checkhitceiling(rdram, ctx);
        goto after_0;
    // 0x80087AFC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x80087B00: b           L_80087B84
    // 0x80087B04: lh          $v0, 0x8($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X8));
        goto L_80087B84;
    // 0x80087B04: lh          $v0, 0x8($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X8));
L_80087B08:
    // 0x80087B08: lh          $t3, 0x8($a2)
    ctx->r11 = S32(MEM_H(ctx->r6, 0X8));
    // 0x80087B0C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80087B10: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80087B14: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80087B18: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x80087B1C: lh          $t9, 0x8($t5)
    ctx->r25 = S32(MEM_H(ctx->r13, 0X8));
    // 0x80087B20: lw          $t4, 0xCC($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80087B24: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x80087B28: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80087B2C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80087B30: addu        $a0, $s6, $t8
    ctx->r4 = ADD32(ctx->r22, ctx->r24);
    // 0x80087B34: lw          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80087B38: subu        $v0, $t6, $t1
    ctx->r2 = SUB32(ctx->r14, ctx->r9);
    // 0x80087B3C: blez        $v0, L_80087B4C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087B40: negu        $a1, $v0
        ctx->r5 = SUB32(0, ctx->r2);
            goto L_80087B4C;
    }
    // 0x80087B40: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    // 0x80087B44: b           L_80087B4C
    // 0x80087B48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80087B4C;
    // 0x80087B48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80087B4C:
    // 0x80087B4C: lw          $t7, 0x4($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X4));
    // 0x80087B50: subu        $v0, $t7, $t2
    ctx->r2 = SUB32(ctx->r15, ctx->r10);
    // 0x80087B54: blez        $v0, L_80087B64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087B58: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80087B64;
    }
    // 0x80087B58: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80087B5C: b           L_80087B64
    // 0x80087B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80087B64;
    // 0x80087B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80087B64:
    // 0x80087B64: addu        $t3, $a0, $a1
    ctx->r11 = ADD32(ctx->r4, ctx->r5);
    // 0x80087B68: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80087B6C: beq         $at, $zero, L_80087B80
    if (ctx->r1 == 0) {
        // 0x80087B70: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_80087B80;
    }
    // 0x80087B70: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80087B74: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80087B78: jal         0x800B147C
    // 0x80087B7C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    checkhitceiling(rdram, ctx);
        goto after_1;
    // 0x80087B7C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_1:
L_80087B80:
    // 0x80087B80: lh          $v0, 0x8($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X8));
L_80087B84:
    // 0x80087B84: lh          $t9, 0xA($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0XA));
    // 0x80087B88: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80087B8C: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80087B90: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80087B94: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80087B98: addu        $s5, $t9, $v0
    ctx->r21 = ADD32(ctx->r25, ctx->r2);
    // 0x80087B9C: slt         $at, $t7, $s5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80087BA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80087BA4: addu        $s2, $s6, $t8
    ctx->r18 = ADD32(ctx->r22, ctx->r24);
    // 0x80087BA8: beq         $at, $zero, L_80087D30
    if (ctx->r1 == 0) {
        // 0x80087BAC: sh          $v0, 0x8C($sp)
        MEM_H(0X8C, ctx->r29) = ctx->r2;
            goto L_80087D30;
    }
    // 0x80087BAC: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
L_80087BB0:
    // 0x80087BB0: lw          $a3, 0x0($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80087BB4: lw          $t1, 0x0($s3)
    ctx->r9 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80087BB8: lw          $t2, 0x4($s3)
    ctx->r10 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80087BBC: lw          $t4, 0xCC($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80087BC0: subu        $v0, $a3, $t1
    ctx->r2 = SUB32(ctx->r7, ctx->r9);
    // 0x80087BC4: blez        $v0, L_80087BD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087BC8: negu        $a1, $v0
        ctx->r5 = SUB32(0, ctx->r2);
            goto L_80087BD4;
    }
    // 0x80087BC8: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    // 0x80087BCC: b           L_80087BD4
    // 0x80087BD0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80087BD4;
    // 0x80087BD0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80087BD4:
    // 0x80087BD4: lw          $t0, 0x4($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X4));
    // 0x80087BD8: subu        $v0, $t0, $t2
    ctx->r2 = SUB32(ctx->r8, ctx->r10);
    // 0x80087BDC: blez        $v0, L_80087BEC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087BE0: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80087BEC;
    }
    // 0x80087BE0: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80087BE4: b           L_80087BEC
    // 0x80087BE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80087BEC;
    // 0x80087BE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80087BEC:
    // 0x80087BEC: addu        $t3, $a0, $a1
    ctx->r11 = ADD32(ctx->r4, ctx->r5);
    // 0x80087BF0: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80087BF4: beql        $at, $zero, L_80087D14
    if (ctx->r1 == 0) {
        // 0x80087BF8: lh          $t4, 0x8C($sp)
        ctx->r12 = S32(MEM_H(ctx->r29, 0X8C));
            goto L_80087D14;
    }
    goto skip_0;
    // 0x80087BF8: lh          $t4, 0x8C($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X8C));
    skip_0:
    // 0x80087BFC: lh          $a0, 0xC($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0XC));
    // 0x80087C00: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x80087C04: bltzl       $a0, L_80087C68
    if (SIGNED(ctx->r4) < 0) {
        // 0x80087C08: lh          $t7, 0x8($s2)
        ctx->r15 = S32(MEM_H(ctx->r18, 0X8));
            goto L_80087C68;
    }
    goto skip_1;
    // 0x80087C08: lh          $t7, 0x8($s2)
    ctx->r15 = S32(MEM_H(ctx->r18, 0X8));
    skip_1:
    // 0x80087C0C: bltz        $v0, L_80087C3C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80087C10: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80087C3C;
    }
    // 0x80087C10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80087C14: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x80087C18: addiu       $t9, $t9, 0x300
    ctx->r25 = ADD32(ctx->r25, 0X300);
    // 0x80087C1C: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x80087C20: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
L_80087C24:
    // 0x80087C24: lh          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80087C28: beq         $a0, $t8, L_80087C3C
    if (ctx->r4 == ctx->r24) {
        // 0x80087C2C: nop
    
            goto L_80087C3C;
    }
    // 0x80087C2C: nop

    // 0x80087C30: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80087C34: bgez        $v1, L_80087C24
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80087C38: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_80087C24;
    }
    // 0x80087C38: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_80087C3C:
    // 0x80087C3C: bgez        $v1, L_80087C64
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80087C40: sll         $t6, $s4, 1
        ctx->r14 = S32(ctx->r20 << 1);
            goto L_80087C64;
    }
    // 0x80087C40: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x80087C44: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x80087C48: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80087C4C: sh          $a0, 0x300($at)
    MEM_H(0X300, ctx->r1) = ctx->r4;
    // 0x80087C50: lw          $t2, 0x4($s3)
    ctx->r10 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80087C54: lw          $t1, 0x0($s3)
    ctx->r9 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80087C58: lw          $t0, 0x4($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X4));
    // 0x80087C5C: lw          $a3, 0x0($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80087C60: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80087C64:
    // 0x80087C64: lh          $t7, 0x8($s2)
    ctx->r15 = S32(MEM_H(ctx->r18, 0X8));
L_80087C68:
    // 0x80087C68: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x80087C6C: sll         $t3, $t7, 3
    ctx->r11 = S32(ctx->r15 << 3);
    // 0x80087C70: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x80087C74: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80087C78: addu        $v0, $s6, $t3
    ctx->r2 = ADD32(ctx->r22, ctx->r11);
    // 0x80087C7C: lw          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80087C80: lw          $t6, 0x4($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80087C84: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80087C88: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80087C8C: sra         $t9, $t5, 1
    ctx->r25 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80087C90: sra         $t3, $t7, 1
    ctx->r11 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80087C94: addu        $s0, $t9, $t1
    ctx->r16 = ADD32(ctx->r25, ctx->r9);
    // 0x80087C98: addu        $s1, $t3, $t2
    ctx->r17 = ADD32(ctx->r11, ctx->r10);
    // 0x80087C9C: sra         $a0, $s0, 1
    ctx->r4 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80087CA0: sra         $a1, $s1, 1
    ctx->r5 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80087CA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80087CA8: jal         0x80097DB8
    // 0x80087CAC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    updatesector(rdram, ctx);
        goto after_2;
    // 0x80087CAC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_2:
    // 0x80087CB0: lh          $t5, 0x88($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X88));
    // 0x80087CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80087CB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80087CBC: bltz        $t5, L_80087D10
    if (SIGNED(ctx->r13) < 0) {
        // 0x80087CC0: or          $a3, $t5, $zero
        ctx->r7 = ctx->r13 | 0;
            goto L_80087D10;
    }
    // 0x80087CC0: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x80087CC4: lw          $a2, 0x8($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80087CC8: lw          $t9, 0x0($s3)
    ctx->r25 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80087CCC: lw          $t8, 0x4($s3)
    ctx->r24 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80087CD0: lh          $t6, 0x10($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80087CD4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80087CD8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80087CDC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80087CE0: jal         0x80092E68
    // 0x80087CE4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    cansee(rdram, ctx);
        goto after_3;
    // 0x80087CE4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_3:
    // 0x80087CE8: beq         $v0, $zero, L_80087D10
    if (ctx->r2 == 0) {
        // 0x80087CEC: lh          $a0, 0xCA($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XCA));
            goto L_80087D10;
    }
    // 0x80087CEC: lh          $a0, 0xCA($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x80087CF0: lw          $t7, 0x8($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80087CF4: lh          $t3, 0xE($s3)
    ctx->r11 = S32(MEM_H(ctx->r19, 0XE));
    // 0x80087CF8: lw          $a2, 0x0($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80087CFC: lw          $a3, 0x4($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X4));
    // 0x80087D00: lh          $a1, 0x8C($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X8C));
    // 0x80087D04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80087D08: jal         0x800B06B8
    // 0x80087D0C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    checkhitwall(rdram, ctx);
        goto after_4;
    // 0x80087D0C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_4:
L_80087D10:
    // 0x80087D10: lh          $t4, 0x8C($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X8C));
L_80087D14:
    // 0x80087D14: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
    // 0x80087D18: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80087D1C: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x80087D20: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80087D24: slt         $at, $t8, $s5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80087D28: bne         $at, $zero, L_80087BB0
    if (ctx->r1 != 0) {
        // 0x80087D2C: sh          $t5, 0x8C($sp)
        MEM_H(0X8C, ctx->r29) = ctx->r13;
            goto L_80087BB0;
    }
    // 0x80087D2C: sh          $t5, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r13;
L_80087D30:
    // 0x80087D30: lw          $t6, 0xA8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x80087D34: slt         $at, $t6, $s4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80087D38: bnel        $at, $zero, L_80087A44
    if (ctx->r1 != 0) {
        // 0x80087D3C: lw          $a0, 0x54($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X54));
            goto L_80087A44;
    }
    goto skip_2;
    // 0x80087D3C: lw          $a0, 0x54($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X54));
    skip_2:
L_80087D40:
    // 0x80087D40: jal         0x8009800C
    // 0x80087D44: nop

    krand2(rdram, ctx);
        goto after_5;
    // 0x80087D44: nop

    after_5:
    // 0x80087D48: andi        $t7, $v0, 0x1FFF
    ctx->r15 = ctx->r2 & 0X1FFF;
    // 0x80087D4C: addiu       $t3, $t7, -0x1000
    ctx->r11 = ADD32(ctx->r15, -0X1000);
    // 0x80087D50: lui         $s5, 0x8027
    ctx->r21 = S32(0X8027 << 16);
    // 0x80087D54: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x80087D58: addiu       $s5, $s5, 0x5F40
    ctx->r21 = ADD32(ctx->r21, 0X5F40);
    // 0x80087D5C: sh          $zero, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = 0;
    // 0x80087D60: addiu       $s6, $zero, 0x26D
    ctx->r22 = ADD32(0, 0X26D);
L_80087D64:
    // 0x80087D64: lh          $t4, 0x8C($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X8C));
    // 0x80087D68: lui         $s4, 0x8027
    ctx->r20 = S32(0X8027 << 16);
    // 0x80087D6C: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x80087D70: lbu         $t5, 0x80($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X80);
    // 0x80087D74: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80087D78: addu        $s4, $s4, $t9
    ctx->r20 = ADD32(ctx->r20, ctx->r25);
    // 0x80087D7C: lh          $s4, 0x2858($s4)
    ctx->r20 = S32(MEM_H(ctx->r20, 0X2858));
    // 0x80087D80: bltz        $s4, L_800883F8
    if (SIGNED(ctx->r20) < 0) {
        // 0x80087D84: sll         $t8, $s4, 1
        ctx->r24 = S32(ctx->r20 << 1);
            goto L_800883F8;
    }
    // 0x80087D84: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
L_80087D88:
    // 0x80087D88: lh          $t3, 0x8C($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X8C));
    // 0x80087D8C: addu        $t6, $s5, $t8
    ctx->r14 = ADD32(ctx->r21, ctx->r24);
    // 0x80087D90: lh          $t7, 0x0($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X0));
    // 0x80087D94: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80087D98: beq         $t3, $zero, L_80087DE0
    if (ctx->r11 == 0) {
        // 0x80087D9C: sh          $t7, 0x8A($sp)
        MEM_H(0X8A, ctx->r29) = ctx->r15;
            goto L_80087DE0;
    }
    // 0x80087D9C: sh          $t7, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r15;
    // 0x80087DA0: beql        $at, $zero, L_80087DE4
    if (ctx->r1 == 0) {
        // 0x80087DA4: sll         $t5, $s4, 2
        ctx->r13 = S32(ctx->r20 << 2);
            goto L_80087DE4;
    }
    goto skip_3;
    // 0x80087DA4: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    skip_3:
    // 0x80087DA8: multu       $s4, $fp
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80087DAC: addiu       $at, $zero, 0x3B7
    ctx->r1 = ADD32(0, 0X3B7);
    // 0x80087DB0: mflo        $t4
    ctx->r12 = lo;
    // 0x80087DB4: addu        $s1, $s7, $t4
    ctx->r17 = ADD32(ctx->r23, ctx->r12);
    // 0x80087DB8: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    // 0x80087DBC: beq         $v0, $at, L_80087DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80087DC0: addiu       $at, $zero, 0x38C
        ctx->r1 = ADD32(0, 0X38C);
            goto L_80087DE0;
    }
    // 0x80087DC0: addiu       $at, $zero, 0x38C
    ctx->r1 = ADD32(0, 0X38C);
    // 0x80087DC4: beq         $v0, $at, L_80087DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80087DC8: addiu       $at, $zero, 0x38E
        ctx->r1 = ADD32(0, 0X38E);
            goto L_80087DE0;
    }
    // 0x80087DC8: addiu       $at, $zero, 0x38E
    ctx->r1 = ADD32(0, 0X38E);
    // 0x80087DCC: beq         $v0, $at, L_80087DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80087DD0: addiu       $at, $zero, 0x3DE
        ctx->r1 = ADD32(0, 0X3DE);
            goto L_80087DE0;
    }
    // 0x80087DD0: addiu       $at, $zero, 0x3DE
    ctx->r1 = ADD32(0, 0X3DE);
    // 0x80087DD4: beq         $v0, $at, L_80087DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80087DD8: addiu       $at, $zero, 0x3D2
        ctx->r1 = ADD32(0, 0X3D2);
            goto L_80087DE0;
    }
    // 0x80087DD8: addiu       $at, $zero, 0x3D2
    ctx->r1 = ADD32(0, 0X3D2);
    // 0x80087DDC: bne         $v0, $at, L_80087E9C
    if (ctx->r2 != ctx->r1) {
        // 0x80087DE0: sll         $t5, $s4, 2
        ctx->r13 = S32(ctx->r20 << 2);
            goto L_80087E9C;
    }
L_80087DE0:
    // 0x80087DE0: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
L_80087DE4:
    // 0x80087DE4: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x80087DE8: lh          $t9, 0xE($s3)
    ctx->r25 = S32(MEM_H(ctx->r19, 0XE));
    // 0x80087DEC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80087DF0: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x80087DF4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80087DF8: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x80087DFC: bne         $t9, $at, L_80087E10
    if (ctx->r25 != ctx->r1) {
        // 0x80087E00: addu        $s1, $s7, $t5
        ctx->r17 = ADD32(ctx->r23, ctx->r13);
            goto L_80087E10;
    }
    // 0x80087E00: addu        $s1, $s7, $t5
    ctx->r17 = ADD32(ctx->r23, ctx->r13);
    // 0x80087E04: lh          $t8, 0xC($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, 0XC));
    // 0x80087E08: andi        $t6, $t8, 0x101
    ctx->r14 = ctx->r24 & 0X101;
    // 0x80087E0C: beq         $t6, $zero, L_800883EC
    if (ctx->r14 == 0) {
        // 0x80087E10: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800883EC;
    }
L_80087E10:
    // 0x80087E10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80087E14: jal         0x800ACEC8
    // 0x80087E18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    dist(rdram, ctx);
        goto after_6;
    // 0x80087E18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80087E1C: lw          $t7, 0xCC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80087E20: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80087E24: beql        $at, $zero, L_800883F0
    if (ctx->r1 == 0) {
        // 0x80087E28: lh          $s4, 0x8A($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
            goto L_800883F0;
    }
    goto skip_4;
    // 0x80087E28: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    skip_4:
    // 0x80087E2C: jal         0x80099ED4
    // 0x80087E30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    badguy(rdram, ctx);
        goto after_7;
    // 0x80087E30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80087E34: beql        $v0, $zero, L_80087E84
    if (ctx->r2 == 0) {
        // 0x80087E38: sll         $a0, $s4, 16
        ctx->r4 = S32(ctx->r20 << 16);
            goto L_80087E84;
    }
    goto skip_5;
    // 0x80087E38: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    skip_5:
    // 0x80087E3C: lw          $v0, 0xB4($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x80087E40: lw          $t3, 0x8($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80087E44: lw          $t9, 0x8($s3)
    ctx->r25 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80087E48: lw          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80087E4C: lw          $a1, 0x4($s1)
    ctx->r5 = S32(MEM_W(ctx->r17, 0X4));
    // 0x80087E50: lh          $a3, 0x10($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X10));
    // 0x80087E54: lw          $t4, 0x0($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80087E58: lw          $t5, 0x4($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80087E5C: lh          $t6, 0x10($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80087E60: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x80087E64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80087E68: addu        $a2, $t3, $v0
    ctx->r6 = ADD32(ctx->r11, ctx->r2);
    // 0x80087E6C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80087E70: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80087E74: jal         0x80092E68
    // 0x80087E78: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    cansee(rdram, ctx);
        goto after_8;
    // 0x80087E78: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_8:
    // 0x80087E7C: beq         $v0, $zero, L_800883EC
    if (ctx->r2 == 0) {
        // 0x80087E80: sll         $a0, $s4, 16
        ctx->r4 = S32(ctx->r20 << 16);
            goto L_800883EC;
    }
    // 0x80087E80: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
L_80087E84:
    // 0x80087E84: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80087E88: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80087E8C: jal         0x800B177C
    // 0x80087E90: lh          $a1, 0xCA($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XCA));
    checkhitsprite(rdram, ctx);
        goto after_9;
    // 0x80087E90: lh          $a1, 0xCA($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XCA));
    after_9:
    // 0x80087E94: b           L_800883F0
    // 0x80087E98: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
        goto L_800883F0;
    // 0x80087E98: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
L_80087E9C:
    // 0x80087E9C: lh          $t3, 0x22($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0X22));
    // 0x80087EA0: bltzl       $t3, L_800883F0
    if (SIGNED(ctx->r11) < 0) {
        // 0x80087EA4: lh          $s4, 0x8A($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
            goto L_800883F0;
    }
    goto skip_6;
    // 0x80087EA4: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    skip_6:
    // 0x80087EA8: beq         $s1, $s3, L_800883EC
    if (ctx->r17 == ctx->r19) {
        // 0x80087EAC: addiu       $at, $zero, 0xA06
        ctx->r1 = ADD32(0, 0XA06);
            goto L_800883EC;
    }
    // 0x80087EAC: addiu       $at, $zero, 0xA06
    ctx->r1 = ADD32(0, 0XA06);
    // 0x80087EB0: beql        $v0, $at, L_80087F00
    if (ctx->r2 == ctx->r1) {
        // 0x80087EB4: lh          $v1, 0xE($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
            goto L_80087F00;
    }
    goto skip_7;
    // 0x80087EB4: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    skip_7:
    // 0x80087EB8: jal         0x80099ED4
    // 0x80087EBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    badguy(rdram, ctx);
        goto after_10;
    // 0x80087EBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80087EC0: bnel        $v0, $zero, L_80087F00
    if (ctx->r2 != 0) {
        // 0x80087EC4: lh          $v1, 0xE($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
            goto L_80087F00;
    }
    goto skip_8;
    // 0x80087EC4: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    skip_8:
    // 0x80087EC8: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    // 0x80087ECC: addiu       $at, $zero, 0x386
    ctx->r1 = ADD32(0, 0X386);
    // 0x80087ED0: beq         $v0, $at, L_80087EFC
    if (ctx->r2 == ctx->r1) {
        // 0x80087ED4: addiu       $at, $zero, 0x385
        ctx->r1 = ADD32(0, 0X385);
            goto L_80087EFC;
    }
    // 0x80087ED4: addiu       $at, $zero, 0x385
    ctx->r1 = ADD32(0, 0X385);
    // 0x80087ED8: beql        $v0, $at, L_80087F00
    if (ctx->r2 == ctx->r1) {
        // 0x80087EDC: lh          $v1, 0xE($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
            goto L_80087F00;
    }
    goto skip_9;
    // 0x80087EDC: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    skip_9:
    // 0x80087EE0: lh          $t4, 0xC($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, 0XC));
    // 0x80087EE4: addiu       $at, $zero, 0x5EE
    ctx->r1 = ADD32(0, 0X5EE);
    // 0x80087EE8: andi        $t5, $t4, 0x101
    ctx->r13 = ctx->r12 & 0X101;
    // 0x80087EEC: bnel        $t5, $zero, L_80087F00
    if (ctx->r13 != 0) {
        // 0x80087EF0: lh          $v1, 0xE($s3)
        ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
            goto L_80087F00;
    }
    goto skip_10;
    // 0x80087EF0: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    skip_10:
    // 0x80087EF4: bnel        $v0, $at, L_800883F0
    if (ctx->r2 != ctx->r1) {
        // 0x80087EF8: lh          $s4, 0x8A($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
            goto L_800883F0;
    }
    goto skip_11;
    // 0x80087EF8: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    skip_11:
L_80087EFC:
    // 0x80087EFC: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
L_80087F00:
    // 0x80087F00: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x80087F04: bnel        $v1, $at, L_80087F44
    if (ctx->r3 != ctx->r1) {
        // 0x80087F08: addiu       $at, $zero, 0x672
        ctx->r1 = ADD32(0, 0X672);
            goto L_80087F44;
    }
    goto skip_12;
    // 0x80087F08: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
    skip_12:
    // 0x80087F0C: lh          $t9, 0xE($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0XE));
    // 0x80087F10: addiu       $at, $zero, 0x60E
    ctx->r1 = ADD32(0, 0X60E);
    // 0x80087F14: beql        $t9, $at, L_80087F44
    if (ctx->r25 == ctx->r1) {
        // 0x80087F18: addiu       $at, $zero, 0x672
        ctx->r1 = ADD32(0, 0X672);
            goto L_80087F44;
    }
    goto skip_13;
    // 0x80087F18: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
    skip_13:
    // 0x80087F1C: lh          $t8, 0x16($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X16));
    // 0x80087F20: beq         $s4, $t8, L_80087F38
    if (ctx->r20 == ctx->r24) {
        // 0x80087F24: nop
    
            goto L_80087F38;
    }
    // 0x80087F24: nop

    // 0x80087F28: lbu         $t6, 0x27($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X27);
    // 0x80087F2C: slti        $at, $t6, 0x18
    ctx->r1 = SIGNED(ctx->r14) < 0X18 ? 1 : 0;
    // 0x80087F30: beql        $at, $zero, L_80087F44
    if (ctx->r1 == 0) {
        // 0x80087F34: addiu       $at, $zero, 0x672
        ctx->r1 = ADD32(0, 0X672);
            goto L_80087F44;
    }
    goto skip_14;
    // 0x80087F34: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
    skip_14:
L_80087F38:
    // 0x80087F38: b           L_800883F0
    // 0x80087F3C: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
        goto L_800883F0;
    // 0x80087F3C: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    // 0x80087F40: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
L_80087F44:
    // 0x80087F44: beq         $v1, $at, L_80087F54
    if (ctx->r3 == ctx->r1) {
        // 0x80087F48: addiu       $at, $zero, 0xF01
        ctx->r1 = ADD32(0, 0XF01);
            goto L_80087F54;
    }
    // 0x80087F48: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    // 0x80087F4C: bnel        $v1, $at, L_80087F6C
    if (ctx->r3 != ctx->r1) {
        // 0x80087F50: lh          $t3, 0xE($s1)
        ctx->r11 = S32(MEM_H(ctx->r17, 0XE));
            goto L_80087F6C;
    }
    goto skip_15;
    // 0x80087F50: lh          $t3, 0xE($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0XE));
    skip_15:
L_80087F54:
    // 0x80087F54: lh          $t7, 0x16($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
    // 0x80087F58: bnel        $s4, $t7, L_80087F6C
    if (ctx->r20 != ctx->r15) {
        // 0x80087F5C: lh          $t3, 0xE($s1)
        ctx->r11 = S32(MEM_H(ctx->r17, 0XE));
            goto L_80087F6C;
    }
    goto skip_16;
    // 0x80087F5C: lh          $t3, 0xE($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0XE));
    skip_16:
    // 0x80087F60: b           L_800883F0
    // 0x80087F64: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
        goto L_800883F0;
    // 0x80087F64: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    // 0x80087F68: lh          $t3, 0xE($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0XE));
L_80087F6C:
    // 0x80087F6C: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x80087F70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80087F74: bne         $t3, $at, L_80087F88
    if (ctx->r11 != ctx->r1) {
        // 0x80087F78: nop
    
            goto L_80087F88;
    }
    // 0x80087F78: nop

    // 0x80087F7C: lw          $t4, 0x8($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80087F80: addiu       $t5, $t4, -0x2600
    ctx->r13 = ADD32(ctx->r12, -0X2600);
    // 0x80087F84: sw          $t5, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r13;
L_80087F88:
    // 0x80087F88: jal         0x800ACEC8
    // 0x80087F8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    dist(rdram, ctx);
        goto after_11;
    // 0x80087F8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x80087F90: lh          $t9, 0xE($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0XE));
    // 0x80087F94: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x80087F98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80087F9C: bnel        $t9, $at, L_80087FB4
    if (ctx->r25 != ctx->r1) {
        // 0x80087FA0: lw          $t7, 0xCC($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0XCC));
            goto L_80087FB4;
    }
    goto skip_17;
    // 0x80087FA0: lw          $t7, 0xCC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XCC));
    skip_17:
    // 0x80087FA4: lw          $t8, 0x8($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80087FA8: addiu       $t6, $t8, 0x2600
    ctx->r14 = ADD32(ctx->r24, 0X2600);
    // 0x80087FAC: sw          $t6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r14;
    // 0x80087FB0: lw          $t7, 0xCC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XCC));
L_80087FB4:
    // 0x80087FB4: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80087FB8: beql        $at, $zero, L_800883F0
    if (ctx->r1 == 0) {
        // 0x80087FBC: lh          $s4, 0x8A($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
            goto L_800883F0;
    }
    goto skip_18;
    // 0x80087FBC: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    skip_18:
    // 0x80087FC0: lw          $a2, 0x8($s1)
    ctx->r6 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80087FC4: lw          $t5, 0x8($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X8));
    // 0x80087FC8: lw          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80087FCC: lw          $a1, 0x4($s1)
    ctx->r5 = S32(MEM_W(ctx->r17, 0X4));
    // 0x80087FD0: lh          $a3, 0x10($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X10));
    // 0x80087FD4: lw          $t3, 0x0($s3)
    ctx->r11 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80087FD8: lw          $t4, 0x4($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80087FDC: lh          $t8, 0x10($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80087FE0: addiu       $t9, $t5, -0xC00
    ctx->r25 = ADD32(ctx->r13, -0XC00);
    // 0x80087FE4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80087FE8: addiu       $a2, $a2, -0x800
    ctx->r6 = ADD32(ctx->r6, -0X800);
    // 0x80087FEC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80087FF0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80087FF4: jal         0x80092E68
    // 0x80087FF8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    cansee(rdram, ctx);
        goto after_12;
    // 0x80087FF8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_12:
    // 0x80087FFC: beql        $v0, $zero, L_800883F0
    if (ctx->r2 == 0) {
        // 0x80088000: lh          $s4, 0x8A($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
            goto L_800883F0;
    }
    goto skip_19;
    // 0x80088000: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    skip_19:
    // 0x80088004: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80088008: lw          $t7, 0x0($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X0));
    // 0x8008800C: lw          $t3, 0x4($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X4));
    // 0x80088010: lw          $t4, 0x4($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80088014: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x80088018: jal         0x80092024
    // 0x8008801C: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    getangle(rdram, ctx);
        goto after_13;
    // 0x8008801C: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    after_13:
    // 0x80088020: sll         $t5, $s4, 3
    ctx->r13 = S32(ctx->r20 << 3);
    // 0x80088024: lh          $v1, 0xE($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0XE));
    // 0x80088028: addu        $t5, $t5, $s4
    ctx->r13 = ADD32(ctx->r13, ctx->r20);
    // 0x8008802C: lui         $t9, 0x8028
    ctx->r25 = S32(0X8028 << 16);
    // 0x80088030: addiu       $t9, $t9, -0x5C00
    ctx->r25 = ADD32(ctx->r25, -0X5C00);
    // 0x80088034: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80088038: addu        $s2, $t5, $t9
    ctx->r18 = ADD32(ctx->r13, ctx->r25);
    // 0x8008803C: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x80088040: bne         $v1, $at, L_80088060
    if (ctx->r3 != ctx->r1) {
        // 0x80088044: sh          $v0, 0x4($s2)
        MEM_H(0X4, ctx->r18) = ctx->r2;
            goto L_80088060;
    }
    // 0x80088044: sh          $v0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r2;
    // 0x80088048: lh          $t8, 0x22($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, 0X22));
    // 0x8008804C: addiu       $t6, $zero, 0xA2D
    ctx->r14 = ADD32(0, 0XA2D);
    // 0x80088050: blezl       $t8, L_80088064
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80088054: addiu       $at, $zero, 0x66E
        ctx->r1 = ADD32(0, 0X66E);
            goto L_80088064;
    }
    goto skip_20;
    // 0x80088054: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    skip_20:
    // 0x80088058: b           L_80088090
    // 0x8008805C: sh          $t6, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r14;
        goto L_80088090;
    // 0x8008805C: sh          $t6, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r14;
L_80088060:
    // 0x80088060: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
L_80088064:
    // 0x80088064: bne         $v1, $at, L_80088074
    if (ctx->r3 != ctx->r1) {
        // 0x80088068: addiu       $t7, $zero, 0x66E
        ctx->r15 = ADD32(0, 0X66E);
            goto L_80088074;
    }
    // 0x80088068: addiu       $t7, $zero, 0x66E
    ctx->r15 = ADD32(0, 0X66E);
    // 0x8008806C: b           L_80088090
    // 0x80088070: sh          $t7, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r15;
        goto L_80088090;
    // 0x80088070: sh          $t7, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r15;
L_80088074:
    // 0x80088074: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    // 0x80088078: bne         $v1, $at, L_8008808C
    if (ctx->r3 != ctx->r1) {
        // 0x8008807C: addiu       $t4, $zero, 0x686
        ctx->r12 = ADD32(0, 0X686);
            goto L_8008808C;
    }
    // 0x8008807C: addiu       $t4, $zero, 0x686
    ctx->r12 = ADD32(0, 0X686);
    // 0x80088080: addiu       $t3, $zero, 0xF01
    ctx->r11 = ADD32(0, 0XF01);
    // 0x80088084: b           L_80088090
    // 0x80088088: sh          $t3, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r11;
        goto L_80088090;
    // 0x80088088: sh          $t3, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r11;
L_8008808C:
    // 0x8008808C: sh          $t4, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r12;
L_80088090:
    // 0x80088090: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x80088094: beq         $v1, $at, L_800882EC
    if (ctx->r3 == ctx->r1) {
        // 0x80088098: lw          $t5, 0xCC($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0XCC));
            goto L_800882EC;
    }
    // 0x80088098: lw          $t5, 0xCC($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x8008809C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800880A0: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800880A4: mflo        $t9
    ctx->r25 = lo;
    // 0x800880A8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800880AC: beq         $at, $zero, L_80088114
    if (ctx->r1 == 0) {
        // 0x800880B0: lw          $t5, 0xCC($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0XCC));
            goto L_80088114;
    }
    // 0x800880B0: lw          $t5, 0xCC($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x800880B4: lw          $t8, 0xDC($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XDC));
    // 0x800880B8: lw          $v0, 0xD8($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XD8));
    // 0x800880BC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800880C0: bne         $t8, $v0, L_800880D0
    if (ctx->r24 != ctx->r2) {
        // 0x800880C4: subu        $s0, $t8, $v0
        ctx->r16 = SUB32(ctx->r24, ctx->r2);
            goto L_800880D0;
    }
    // 0x800880C4: subu        $s0, $t8, $v0
    ctx->r16 = SUB32(ctx->r24, ctx->r2);
    // 0x800880C8: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x800880CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800880D0:
    // 0x800880D0: jal         0x8009800C
    // 0x800880D4: nop

    krand2(rdram, ctx);
        goto after_14;
    // 0x800880D4: nop

    after_14:
    // 0x800880D8: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x800880DC: lw          $t3, 0xD8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XD8));
    // 0x800880E0: mfhi        $t7
    ctx->r15 = hi;
    // 0x800880E4: bne         $s0, $zero, L_800880F0
    if (ctx->r16 != 0) {
        // 0x800880E8: nop
    
            goto L_800880F0;
    }
    // 0x800880E8: nop

    // 0x800880EC: break       7
    do_break(2148040940);
L_800880F0:
    // 0x800880F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800880F4: bne         $s0, $at, L_80088108
    if (ctx->r16 != ctx->r1) {
        // 0x800880F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80088108;
    }
    // 0x800880F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800880FC: bne         $v0, $at, L_80088108
    if (ctx->r2 != ctx->r1) {
        // 0x80088100: nop
    
            goto L_80088108;
    }
    // 0x80088100: nop

    // 0x80088104: break       6
    do_break(2148040964);
L_80088108:
    // 0x80088108: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x8008810C: b           L_800881F4
    // 0x80088110: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
        goto L_800881F4;
    // 0x80088110: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
L_80088114:
    // 0x80088114: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80088118: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008811C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80088120: mflo        $t8
    ctx->r24 = lo;
    // 0x80088124: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80088128: beq         $at, $zero, L_80088190
    if (ctx->r1 == 0) {
        // 0x8008812C: lw          $t9, 0xCC($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0XCC));
            goto L_80088190;
    }
    // 0x8008812C: lw          $t9, 0xCC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80088130: lw          $t6, 0xD8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XD8));
    // 0x80088134: lw          $v0, 0xD4($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XD4));
    // 0x80088138: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008813C: bne         $t6, $v0, L_8008814C
    if (ctx->r14 != ctx->r2) {
        // 0x80088140: subu        $s0, $t6, $v0
        ctx->r16 = SUB32(ctx->r14, ctx->r2);
            goto L_8008814C;
    }
    // 0x80088140: subu        $s0, $t6, $v0
    ctx->r16 = SUB32(ctx->r14, ctx->r2);
    // 0x80088144: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
    // 0x80088148: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8008814C:
    // 0x8008814C: jal         0x8009800C
    // 0x80088150: nop

    krand2(rdram, ctx);
        goto after_15;
    // 0x80088150: nop

    after_15:
    // 0x80088154: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x80088158: lw          $t4, 0xD4($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XD4));
    // 0x8008815C: mfhi        $t3
    ctx->r11 = hi;
    // 0x80088160: bne         $s0, $zero, L_8008816C
    if (ctx->r16 != 0) {
        // 0x80088164: nop
    
            goto L_8008816C;
    }
    // 0x80088164: nop

    // 0x80088168: break       7
    do_break(2148041064);
L_8008816C:
    // 0x8008816C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80088170: bne         $s0, $at, L_80088184
    if (ctx->r16 != ctx->r1) {
        // 0x80088174: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80088184;
    }
    // 0x80088174: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80088178: bne         $v0, $at, L_80088184
    if (ctx->r2 != ctx->r1) {
        // 0x8008817C: nop
    
            goto L_80088184;
    }
    // 0x8008817C: nop

    // 0x80088180: break       6
    do_break(2148041088);
L_80088184:
    // 0x80088184: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80088188: b           L_800881F4
    // 0x8008818C: sh          $t5, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r13;
        goto L_800881F4;
    // 0x8008818C: sh          $t5, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r13;
L_80088190:
    // 0x80088190: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80088194: beq         $at, $zero, L_800881F4
    if (ctx->r1 == 0) {
        // 0x80088198: lw          $v0, 0xD0($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0XD0));
            goto L_800881F4;
    }
    // 0x80088198: lw          $v0, 0xD0($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XD0));
    // 0x8008819C: lw          $t8, 0xD4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XD4));
    // 0x800881A0: bne         $t8, $v0, L_800881B4
    if (ctx->r24 != ctx->r2) {
        // 0x800881A4: subu        $s0, $t8, $v0
        ctx->r16 = SUB32(ctx->r24, ctx->r2);
            goto L_800881B4;
    }
    // 0x800881A4: subu        $s0, $t8, $v0
    ctx->r16 = SUB32(ctx->r24, ctx->r2);
    // 0x800881A8: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800881AC: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
    // 0x800881B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800881B4:
    // 0x800881B4: jal         0x8009800C
    // 0x800881B8: nop

    krand2(rdram, ctx);
        goto after_16;
    // 0x800881B8: nop

    after_16:
    // 0x800881BC: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x800881C0: lw          $t3, 0xD0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XD0));
    // 0x800881C4: mfhi        $t7
    ctx->r15 = hi;
    // 0x800881C8: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x800881CC: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
    // 0x800881D0: bne         $s0, $zero, L_800881DC
    if (ctx->r16 != 0) {
        // 0x800881D4: nop
    
            goto L_800881DC;
    }
    // 0x800881D4: nop

    // 0x800881D8: break       7
    do_break(2148041176);
L_800881DC:
    // 0x800881DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800881E0: bne         $s0, $at, L_800881F4
    if (ctx->r16 != ctx->r1) {
        // 0x800881E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800881F4;
    }
    // 0x800881E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800881E8: bne         $v0, $at, L_800881F4
    if (ctx->r2 != ctx->r1) {
        // 0x800881EC: nop
    
            goto L_800881F4;
    }
    // 0x800881EC: nop

    // 0x800881F0: break       6
    do_break(2148041200);
L_800881F4:
    // 0x800881F4: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800881F8: addiu       $at, $zero, 0x938
    ctx->r1 = ADD32(0, 0X938);
    // 0x800881FC: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x80088200: beq         $v0, $at, L_80088254
    if (ctx->r2 == ctx->r1) {
        // 0x80088204: sra         $t6, $a0, 16
        ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
            goto L_80088254;
    }
    // 0x80088204: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80088208: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
    // 0x8008820C: beq         $v0, $at, L_80088254
    if (ctx->r2 == ctx->r1) {
        // 0x80088210: addiu       $at, $zero, 0xA46
        ctx->r1 = ADD32(0, 0XA46);
            goto L_80088254;
    }
    // 0x80088210: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    // 0x80088214: beq         $v0, $at, L_80088254
    if (ctx->r2 == ctx->r1) {
        // 0x80088218: addiu       $at, $zero, 0xA96
        ctx->r1 = ADD32(0, 0XA96);
            goto L_80088254;
    }
    // 0x80088218: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    // 0x8008821C: beq         $v0, $at, L_80088254
    if (ctx->r2 == ctx->r1) {
        // 0x80088220: addiu       $at, $zero, 0xAC8
        ctx->r1 = ADD32(0, 0XAC8);
            goto L_80088254;
    }
    // 0x80088220: addiu       $at, $zero, 0xAC8
    ctx->r1 = ADD32(0, 0XAC8);
    // 0x80088224: beql        $v0, $at, L_80088258
    if (ctx->r2 == ctx->r1) {
        // 0x80088228: addiu       $at, $zero, 0x50E
        ctx->r1 = ADD32(0, 0X50E);
            goto L_80088258;
    }
    goto skip_21;
    // 0x80088228: addiu       $at, $zero, 0x50E
    ctx->r1 = ADD32(0, 0X50E);
    skip_21:
    // 0x8008822C: lh          $v1, 0x18($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X18));
    // 0x80088230: bgezl       $v1, L_80088244
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80088234: lh          $t5, 0x22($s3)
        ctx->r13 = S32(MEM_H(ctx->r19, 0X22));
            goto L_80088244;
    }
    goto skip_22;
    // 0x80088234: lh          $t5, 0x22($s3)
    ctx->r13 = S32(MEM_H(ctx->r19, 0X22));
    skip_22:
    // 0x80088238: sh          $zero, 0x18($s1)
    MEM_H(0X18, ctx->r17) = 0;
    // 0x8008823C: lh          $v1, 0x18($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X18));
    // 0x80088240: lh          $t5, 0x22($s3)
    ctx->r13 = S32(MEM_H(ctx->r19, 0X22));
L_80088244:
    // 0x80088244: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    // 0x80088248: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8008824C: addu        $t8, $v1, $t9
    ctx->r24 = ADD32(ctx->r3, ctx->r25);
    // 0x80088250: sh          $t8, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r24;
L_80088254:
    // 0x80088254: addiu       $at, $zero, 0x50E
    ctx->r1 = ADD32(0, 0X50E);
L_80088258:
    // 0x80088258: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x8008825C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800882DC;
    }
    // 0x8008825C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80088260: addiu       $at, $zero, 0x520
    ctx->r1 = ADD32(0, 0X520);
    // 0x80088264: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x80088268: addiu       $at, $zero, 0x525
        ctx->r1 = ADD32(0, 0X525);
            goto L_800882DC;
    }
    // 0x80088268: addiu       $at, $zero, 0x525
    ctx->r1 = ADD32(0, 0X525);
    // 0x8008826C: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x80088270: addiu       $at, $zero, 0x529
        ctx->r1 = ADD32(0, 0X529);
            goto L_800882DC;
    }
    // 0x80088270: addiu       $at, $zero, 0x529
    ctx->r1 = ADD32(0, 0X529);
    // 0x80088274: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x80088278: addiu       $at, $zero, 0x52D
        ctx->r1 = ADD32(0, 0X52D);
            goto L_800882DC;
    }
    // 0x80088278: addiu       $at, $zero, 0x52D
    ctx->r1 = ADD32(0, 0X52D);
    // 0x8008827C: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x80088280: addiu       $at, $zero, 0x52B
        ctx->r1 = ADD32(0, 0X52B);
            goto L_800882DC;
    }
    // 0x80088280: addiu       $at, $zero, 0x52B
    ctx->r1 = ADD32(0, 0X52B);
    // 0x80088284: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x80088288: addiu       $at, $zero, 0x536
        ctx->r1 = ADD32(0, 0X536);
            goto L_800882DC;
    }
    // 0x80088288: addiu       $at, $zero, 0x536
    ctx->r1 = ADD32(0, 0X536);
    // 0x8008828C: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x80088290: addiu       $at, $zero, 0x573
        ctx->r1 = ADD32(0, 0X573);
            goto L_800882DC;
    }
    // 0x80088290: addiu       $at, $zero, 0x573
    ctx->r1 = ADD32(0, 0X573);
    // 0x80088294: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x80088298: addiu       $at, $zero, 0x538
        ctx->r1 = ADD32(0, 0X538);
            goto L_800882DC;
    }
    // 0x80088298: addiu       $at, $zero, 0x538
    ctx->r1 = ADD32(0, 0X538);
    // 0x8008829C: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x800882A0: addiu       $at, $zero, 0xD7A
        ctx->r1 = ADD32(0, 0XD7A);
            goto L_800882DC;
    }
    // 0x800882A0: addiu       $at, $zero, 0xD7A
    ctx->r1 = ADD32(0, 0XD7A);
    // 0x800882A4: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x800882A8: addiu       $at, $zero, 0x1300
        ctx->r1 = ADD32(0, 0X1300);
            goto L_800882DC;
    }
    // 0x800882A8: addiu       $at, $zero, 0x1300
    ctx->r1 = ADD32(0, 0X1300);
    // 0x800882AC: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x800882B0: addiu       $at, $zero, 0x2F1
        ctx->r1 = ADD32(0, 0X2F1);
            goto L_800882DC;
    }
    // 0x800882B0: addiu       $at, $zero, 0x2F1
    ctx->r1 = ADD32(0, 0X2F1);
    // 0x800882B4: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x800882B8: addiu       $at, $zero, 0x365
        ctx->r1 = ADD32(0, 0X365);
            goto L_800882DC;
    }
    // 0x800882B8: addiu       $at, $zero, 0x365
    ctx->r1 = ADD32(0, 0X365);
    // 0x800882BC: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x800882C0: addiu       $at, $zero, 0x549
        ctx->r1 = ADD32(0, 0X549);
            goto L_800882DC;
    }
    // 0x800882C0: addiu       $at, $zero, 0x549
    ctx->r1 = ADD32(0, 0X549);
    // 0x800882C4: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x800882C8: addiu       $at, $zero, 0x386
        ctx->r1 = ADD32(0, 0X386);
            goto L_800882DC;
    }
    // 0x800882C8: addiu       $at, $zero, 0x386
    ctx->r1 = ADD32(0, 0X386);
    // 0x800882CC: beq         $v0, $at, L_800882DC
    if (ctx->r2 == ctx->r1) {
        // 0x800882D0: addiu       $at, $zero, 0x385
        ctx->r1 = ADD32(0, 0X385);
            goto L_800882DC;
    }
    // 0x800882D0: addiu       $at, $zero, 0x385
    ctx->r1 = ADD32(0, 0X385);
    // 0x800882D4: bnel        $v0, $at, L_80088300
    if (ctx->r2 != ctx->r1) {
        // 0x800882D8: lh          $v0, 0xE($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
            goto L_80088300;
    }
    goto skip_23;
    // 0x800882D8: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    skip_23:
L_800882DC:
    // 0x800882DC: jal         0x800B177C
    // 0x800882E0: lh          $a1, 0xCA($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XCA));
    checkhitsprite(rdram, ctx);
        goto after_17;
    // 0x800882E0: lh          $a1, 0xCA($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XCA));
    after_17:
    // 0x800882E4: b           L_80088300
    // 0x800882E8: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
        goto L_80088300;
    // 0x800882E8: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
L_800882EC:
    // 0x800882EC: lh          $t7, 0x22($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X22));
    // 0x800882F0: bnel        $t7, $zero, L_80088300
    if (ctx->r15 != 0) {
        // 0x800882F4: lh          $v0, 0xE($s1)
        ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
            goto L_80088300;
    }
    goto skip_24;
    // 0x800882F4: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    skip_24:
    // 0x800882F8: sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
    // 0x800882FC: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
L_80088300:
    // 0x80088300: addiu       $at, $zero, 0x686
    ctx->r1 = ADD32(0, 0X686);
    // 0x80088304: beql        $v0, $at, L_800883F0
    if (ctx->r2 == ctx->r1) {
        // 0x80088308: lh          $s4, 0x8A($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
            goto L_800883F0;
    }
    goto skip_25;
    // 0x80088308: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    skip_25:
    // 0x8008830C: lh          $v1, 0x16($s3)
    ctx->r3 = S32(MEM_H(ctx->r19, 0X16));
    // 0x80088310: bltzl       $v1, L_800883F0
    if (SIGNED(ctx->r3) < 0) {
        // 0x80088314: lh          $s4, 0x8A($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
            goto L_800883F0;
    }
    goto skip_26;
    // 0x80088314: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
    skip_26:
    // 0x80088318: multu       $v1, $fp
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008831C: mflo        $t3
    ctx->r11 = lo;
    // 0x80088320: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x80088324: lh          $t5, 0x12($t4)
    ctx->r13 = S32(MEM_H(ctx->r12, 0X12));
    // 0x80088328: slti        $at, $t5, 0x400
    ctx->r1 = SIGNED(ctx->r13) < 0X400 ? 1 : 0;
    // 0x8008832C: beq         $at, $zero, L_800883EC
    if (ctx->r1 == 0) {
        // 0x80088330: addiu       $at, $zero, 0x57D
        ctx->r1 = ADD32(0, 0X57D);
            goto L_800883EC;
    }
    // 0x80088330: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x80088334: bnel        $v0, $at, L_800883E8
    if (ctx->r2 != ctx->r1) {
        // 0x80088338: lh          $t7, 0x16($s3)
        ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
            goto L_800883E8;
    }
    goto skip_27;
    // 0x80088338: lh          $t7, 0x16($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
    skip_27:
    // 0x8008833C: lh          $v1, 0x1A($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X1A));
    // 0x80088340: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x80088344: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x80088348: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8008834C: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80088350: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80088354: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80088358: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8008835C: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80088360: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80088364: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x80088368: lh          $t6, 0x2BE($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X2BE));
    // 0x8008836C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80088370: addiu       $a2, $v0, 0x288
    ctx->r6 = ADD32(ctx->r2, 0X288);
    // 0x80088374: bltzl       $t6, L_800883E8
    if (SIGNED(ctx->r14) < 0) {
        // 0x80088378: lh          $t7, 0x16($s3)
        ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
            goto L_800883E8;
    }
    goto skip_28;
    // 0x80088378: lh          $t7, 0x16($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
    skip_28:
    // 0x8008837C: lw          $a0, 0x238($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X238));
    // 0x80088380: lw          $a1, 0x23C($v0)
    ctx->r5 = S32(MEM_W(ctx->r2, 0X23C));
    // 0x80088384: lw          $t3, 0x240($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X240));
    // 0x80088388: lh          $t4, 0x284($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X284));
    // 0x8008838C: sh          $t7, 0x2BE($v0)
    MEM_H(0X2BE, ctx->r2) = ctx->r15;
    // 0x80088390: sw          $a0, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->r4;
    // 0x80088394: sw          $a1, 0x218($v0)
    MEM_W(0X218, ctx->r2) = ctx->r5;
    // 0x80088398: sw          $t3, 0x21C($v0)
    MEM_W(0X21C, ctx->r2) = ctx->r11;
    // 0x8008839C: jal         0x80097DB8
    // 0x800883A0: sh          $t4, 0x282($v0)
    MEM_H(0X282, ctx->r2) = ctx->r12;
    updatesector(rdram, ctx);
        goto after_18;
    // 0x800883A0: sh          $t4, 0x282($v0)
    MEM_H(0X282, ctx->r2) = ctx->r12;
    after_18:
    // 0x800883A4: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800883A8: lh          $v0, 0x285A($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X285A));
    // 0x800883AC: bltzl       $v0, L_800883E8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800883B0: lh          $t7, 0x16($s3)
        ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
            goto L_800883E8;
    }
    goto skip_29;
    // 0x800883B0: lh          $t7, 0x16($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
    skip_29:
L_800883B4:
    // 0x800883B4: multu       $v0, $fp
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800883B8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800883BC: addu        $t6, $s5, $t8
    ctx->r14 = ADD32(ctx->r21, ctx->r24);
    // 0x800883C0: mflo        $t5
    ctx->r13 = lo;
    // 0x800883C4: addu        $v1, $s7, $t5
    ctx->r3 = ADD32(ctx->r23, ctx->r13);
    // 0x800883C8: lh          $t9, 0xE($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0XE));
    // 0x800883CC: bnel        $s6, $t9, L_800883DC
    if (ctx->r22 != ctx->r25) {
        // 0x800883D0: lh          $v0, 0x0($t6)
        ctx->r2 = S32(MEM_H(ctx->r14, 0X0));
            goto L_800883DC;
    }
    goto skip_30;
    // 0x800883D0: lh          $v0, 0x0($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0X0));
    skip_30:
    // 0x800883D4: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
    // 0x800883D8: lh          $v0, 0x0($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0X0));
L_800883DC:
    // 0x800883DC: bgez        $v0, L_800883B4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800883E0: nop
    
            goto L_800883B4;
    }
    // 0x800883E0: nop

    // 0x800883E4: lh          $t7, 0x16($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X16));
L_800883E8:
    // 0x800883E8: sh          $t7, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r15;
L_800883EC:
    // 0x800883EC: lh          $s4, 0x8A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X8A));
L_800883F0:
    // 0x800883F0: bgezl       $s4, L_80087D88
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800883F4: sll         $t8, $s4, 1
        ctx->r24 = S32(ctx->r20 << 1);
            goto L_80087D88;
    }
    goto skip_31;
    // 0x800883F4: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    skip_31:
L_800883F8:
    // 0x800883F8: lh          $t3, 0x8C($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X8C));
    // 0x800883FC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80088400: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80088404: sra         $t9, $t5, 16
    ctx->r25 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80088408: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x8008840C: bne         $at, $zero, L_80087D64
    if (ctx->r1 != 0) {
        // 0x80088410: sh          $t4, 0x8C($sp)
        MEM_H(0X8C, ctx->r29) = ctx->r12;
            goto L_80087D64;
    }
    // 0x80088410: sh          $t4, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r12;
    // 0x80088414: lw          $ra, 0x4C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80088418: lw          $s0, 0x28($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8008841C: lw          $s1, 0x2C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80088420: lw          $s2, 0x30($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80088424: lw          $s3, 0x34($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80088428: lw          $s4, 0x38($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8008842C: lw          $s5, 0x3C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80088430: lw          $s6, 0x40($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80088434: lw          $s7, 0x44($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80088438: lw          $fp, 0x48($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8008843C: jr          $ra
    // 0x80088440: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80088440: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void dmulscale11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090644: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009064C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090650: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090654: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090658: jal         0x800BB8F8
    // 0x8009065C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009065C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090660: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090664: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090668: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009066C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090670: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090674: jal         0x800BB8F8
    // 0x80090678: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090678: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009067C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090680: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090684: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090688: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009068C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090690: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090694: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090698: jal         0x800BBA24
    // 0x8009069C: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009069C: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    after_2:
    // 0x800906A0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800906A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800906A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800906AC: jr          $ra
    // 0x800906B0: nop

    return;
    // 0x800906B0: nop

;}
RECOMP_FUNC void dmulscale9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090564: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009056C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090570: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090574: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090578: jal         0x800BB8F8
    // 0x8009057C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009057C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090580: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090584: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090588: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009058C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090590: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090594: jal         0x800BB8F8
    // 0x80090598: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090598: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009059C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800905A0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800905A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800905A8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x800905AC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800905B0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x800905B4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800905B8: jal         0x800BBA24
    // 0x800905BC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x800905BC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_2:
    // 0x800905C0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800905C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800905C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800905CC: jr          $ra
    // 0x800905D0: nop

    return;
    // 0x800905D0: nop

;}
RECOMP_FUNC void alEvtqFlush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9BFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C9C00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C9C04: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C9C08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9C0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C9C10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9C14: jal         0x800BC180
    // 0x800C9C18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9C18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C9C1C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C9C20: lw          $s0, 0x8($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X8));
    // 0x800C9C24: beq         $s0, $zero, L_800C9C4C
    if (ctx->r16 == 0) {
        // 0x800C9C28: nop
    
            goto L_800C9C4C;
    }
    // 0x800C9C28: nop

L_800C9C2C:
    // 0x800C9C2C: lw          $s1, 0x0($s0)
    ctx->r17 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800C9C30: jal         0x800BF770
    // 0x800C9C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C9C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9C3C: jal         0x800BF7A0
    // 0x800C9C40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C9C40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800C9C44: bne         $s1, $zero, L_800C9C2C
    if (ctx->r17 != 0) {
        // 0x800C9C48: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C9C2C;
    }
    // 0x800C9C48: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C9C4C:
    // 0x800C9C4C: jal         0x800BC180
    // 0x800C9C50: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C9C50: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    after_3:
    // 0x800C9C54: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C9C58: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800C9C5C: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C9C60: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C9C64: jr          $ra
    // 0x800C9C68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C9C68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800919B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800919B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800919B8: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800919BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800919C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800919C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800919C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800919CC: sra         $a0, $a0, 31
    ctx->r4 = S32(SIGNED(ctx->r4) >> 31);
    // 0x800919D0: jal         0x800BB8F8
    // 0x800919D4: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800919D4: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_0:
    // 0x800919D8: lw          $a3, 0x20($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800919DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800919E0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800919E4: jal         0x800BB89C
    // 0x800919E8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800919E8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_1:
    // 0x800919EC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800919F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800919F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800919F8: jr          $ra
    // 0x800919FC: nop

    return;
    // 0x800919FC: nop

;}
RECOMP_FUNC void func_80060B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060B34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060B38: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060B40: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80060B44: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80060B48: beq         $at, $zero, L_80060C30
    if (ctx->r1 == 0) {
        // 0x80060B4C: or          $t7, $a1, $zero
        ctx->r15 = ctx->r5 | 0;
            goto L_80060C30;
    }
    // 0x80060B4C: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x80060B50: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80060B54: addiu       $t9, $t9, -0x2338
    ctx->r25 = ADD32(ctx->r25, -0X2338);
    // 0x80060B58: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80060B5C: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x80060B60: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80060B64: sll         $t1, $a2, 3
    ctx->r9 = S32(ctx->r6 << 3);
    // 0x80060B68: sll         $t2, $t7, 3
    ctx->r10 = S32(ctx->r15 << 3);
    // 0x80060B6C: lw          $a1, 0x4($t0)
    ctx->r5 = S32(MEM_W(ctx->r8, 0X4));
    // 0x80060B70: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80060B74: addu        $v1, $t2, $t9
    ctx->r3 = ADD32(ctx->r10, ctx->r25);
    // 0x80060B78: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x80060B7C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
L_80060B80:
    // 0x80060B80: lw          $t3, 0xC($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0XC));
L_80060B84:
    // 0x80060B84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80060B88: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80060B8C: sltu        $at, $a1, $t3
    ctx->r1 = ctx->r5 < ctx->r11 ? 1 : 0;
    // 0x80060B90: bnel        $at, $zero, L_80060B84
    if (ctx->r1 != 0) {
        // 0x80060B94: lw          $t3, 0xC($v0)
        ctx->r11 = S32(MEM_W(ctx->r2, 0XC));
            goto L_80060B84;
    }
    goto skip_0;
    // 0x80060B94: lw          $t3, 0xC($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0XC));
    skip_0:
    // 0x80060B98: lw          $t4, -0x4($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, -0X4));
L_80060B9C:
    // 0x80060B9C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80060BA0: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x80060BA4: sltu        $at, $t4, $a1
    ctx->r1 = ctx->r12 < ctx->r5 ? 1 : 0;
    // 0x80060BA8: bnel        $at, $zero, L_80060B9C
    if (ctx->r1 != 0) {
        // 0x80060BAC: lw          $t4, -0x4($v1)
        ctx->r12 = S32(MEM_W(ctx->r3, -0X4));
            goto L_80060B9C;
    }
    goto skip_1;
    // 0x80060BAC: lw          $t4, -0x4($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, -0X4));
    skip_1:
    // 0x80060BB0: lw          $at, 0x0($v0)
    ctx->r1 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80060BB4: lw          $t8, 0x4($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80060BB8: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x80060BBC: lw          $at, 0x0($v1)
    ctx->r1 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80060BC0: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80060BC4: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80060BC8: lw          $t7, 0x4($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X4));
    // 0x80060BCC: lw          $at, 0x0($a3)
    ctx->r1 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80060BD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80060BD4: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x80060BD8: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80060BDC: bne         $at, $zero, L_80060B80
    if (ctx->r1 != 0) {
        // 0x80060BE0: sw          $t8, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r24;
            goto L_80060B80;
    }
    // 0x80060BE0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80060BE4: lw          $at, 0x0($v0)
    ctx->r1 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80060BE8: lw          $a0, 0x38($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80060BEC: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    // 0x80060BF0: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x80060BF4: lw          $t3, 0x4($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80060BF8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80060BFC: lw          $at, 0x0($t0)
    ctx->r1 = S32(MEM_W(ctx->r8, 0X0));
    // 0x80060C00: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80060C04: lw          $t5, 0x4($t0)
    ctx->r13 = S32(MEM_W(ctx->r8, 0X4));
    // 0x80060C08: lw          $at, 0x0($a3)
    ctx->r1 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80060C0C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80060C10: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80060C14: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80060C18: jal         0x80060B34
    // 0x80060C1C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    func_80060B34(rdram, ctx);
        goto after_0;
    // 0x80060C1C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    after_0:
    // 0x80060C20: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80060C24: lw          $a1, 0x3C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80060C28: jal         0x80060B34
    // 0x80060C2C: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    func_80060B34(rdram, ctx);
        goto after_1;
    // 0x80060C2C: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    after_1:
L_80060C30:
    // 0x80060C30: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80060C34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80060C38: jr          $ra
    // 0x80060C3C: nop

    return;
    // 0x80060C3C: nop

;}
RECOMP_FUNC void dmulscale17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800908E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800908E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800908EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800908F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800908F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800908F8: jal         0x800BB8F8
    // 0x800908FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800908FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090900: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090904: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090908: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009090C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090910: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090914: jal         0x800BB8F8
    // 0x80090918: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090918: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009091C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090920: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090924: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090928: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009092C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090930: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090934: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090938: jal         0x800BBA24
    // 0x8009093C: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009093C: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_2:
    // 0x80090940: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090944: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009094C: jr          $ra
    // 0x80090950: nop

    return;
    // 0x80090950: nop

;}
RECOMP_FUNC void dmulscale18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090954: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009095C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090960: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090964: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090968: jal         0x800BB8F8
    // 0x8009096C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009096C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090970: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090974: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090978: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009097C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090980: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090984: jal         0x800BB8F8
    // 0x80090988: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090988: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009098C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090990: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090994: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090998: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009099C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800909A0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x800909A4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800909A8: jal         0x800BBA24
    // 0x800909AC: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x800909AC: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    after_2:
    // 0x800909B0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800909B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800909B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800909BC: jr          $ra
    // 0x800909C0: nop

    return;
    // 0x800909C0: nop

;}
RECOMP_FUNC void _timeToSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2468: lw          $t6, 0x44($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X44));
    // 0x800C246C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800C2470: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2474: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800C2478: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C247C: ldc1        $f4, -0x6450($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X6450);
    // 0x800C2480: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C2484: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C2488: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800C248C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C2490: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C2494: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C2498: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C249C: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x800C24A0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800C24A4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800C24A8: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C24AC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C24B0: nop

    // 0x800C24B4: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x800C24B8: jr          $ra
    // 0x800C24BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800C24BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void __seqpReleaseVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA76C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800CA770: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800CA774: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800CA778: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800CA77C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800CA780: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800CA784: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CA788: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CA78C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CA790: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800CA794: lw          $s6, 0x10($a1)
    ctx->r22 = S32(MEM_W(ctx->r5, 0X10));
    // 0x800CA798: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800CA79C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800CA7A0: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x800CA7A4: bnel        $t6, $zero, L_800CA810
    if (ctx->r14 != 0) {
        // 0x800CA7A8: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_800CA810;
    }
    goto skip_0;
    // 0x800CA7A8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_0:
    // 0x800CA7AC: lw          $s0, 0x50($a0)
    ctx->r16 = S32(MEM_W(ctx->r4, 0X50));
    // 0x800CA7B0: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x800CA7B4: beql        $s0, $zero, L_800CA810
    if (ctx->r16 == 0) {
        // 0x800CA7B8: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_800CA810;
    }
    goto skip_1;
    // 0x800CA7B8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_1:
L_800CA7BC:
    // 0x800CA7BC: lh          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800CA7C0: lw          $s1, 0x0($s0)
    ctx->r17 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800CA7C4: bne         $s3, $t7, L_800CA804
    if (ctx->r19 != ctx->r15) {
        // 0x800CA7C8: nop
    
            goto L_800CA804;
    }
    // 0x800CA7C8: nop

    // 0x800CA7CC: lw          $t8, 0x10($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X10));
    // 0x800CA7D0: bne         $s5, $t8, L_800CA804
    if (ctx->r21 != ctx->r24) {
        // 0x800CA7D4: nop
    
            goto L_800CA804;
    }
    // 0x800CA7D4: nop

    // 0x800CA7D8: beq         $s1, $zero, L_800CA7F0
    if (ctx->r17 == 0) {
        // 0x800CA7DC: addiu       $s2, $s4, 0x48
        ctx->r18 = ADD32(ctx->r20, 0X48);
            goto L_800CA7F0;
    }
    // 0x800CA7DC: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    // 0x800CA7E0: lw          $t9, 0x8($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800CA7E4: lw          $t0, 0x8($s0)
    ctx->r8 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CA7E8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800CA7EC: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_800CA7F0:
    // 0x800CA7F0: jal         0x800BF770
    // 0x800CA7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800CA7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800CA7F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CA7FC: jal         0x800BF7A0
    // 0x800CA800: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x800CA800: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_800CA804:
    // 0x800CA804: bne         $s1, $zero, L_800CA7BC
    if (ctx->r17 != 0) {
        // 0x800CA808: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800CA7BC;
    }
    // 0x800CA808: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800CA80C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_800CA810:
    // 0x800CA810: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x800CA814: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x800CA818: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x800CA81C: lw          $t4, 0x68($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800CA820: lw          $t3, 0x1C($s4)
    ctx->r11 = S32(MEM_W(ctx->r20, 0X1C));
    // 0x800CA824: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800CA828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA82C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800CA830: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x800CA834: lw          $a0, 0x14($s4)
    ctx->r4 = S32(MEM_W(ctx->r20, 0X14));
    // 0x800CA838: jal         0x800D05B0
    // 0x800CA83C: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    alSynSetPriority(rdram, ctx);
        goto after_2;
    // 0x800CA83C: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    after_2:
    // 0x800CA840: lw          $a0, 0x14($s4)
    ctx->r4 = S32(MEM_W(ctx->r20, 0X14));
    // 0x800CA844: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800CA848: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA84C: jal         0x800CA230
    // 0x800CA850: lw          $a3, 0x68($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X68));
    alSynSetVol(rdram, ctx);
        goto after_3;
    // 0x800CA850: lw          $a3, 0x68($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X68));
    after_3:
    // 0x800CA854: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800CA858: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x800CA85C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800CA860: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CA864: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800CA868: jal         0x800C9C6C
    // 0x800CA86C: lw          $a2, 0x68($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X68));
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x800CA86C: lw          $a2, 0x68($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X68));
    after_4:
    // 0x800CA870: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800CA874: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800CA878: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CA87C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CA880: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CA884: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800CA888: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800CA88C: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800CA890: jr          $ra
    // 0x800CA894: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800CA894: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void alSynSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA2D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA2D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA2D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CA2DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CA2E0: lw          $t6, 0x8($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X8));
    // 0x800CA2E4: beql        $t6, $zero, L_800CA348
    if (ctx->r14 == 0) {
        // 0x800CA2E8: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CA348;
    }
    goto skip_0;
    // 0x800CA2E8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800CA2EC: jal         0x800C2570
    // 0x800CA2F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800CA2F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CA2F4: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CA2F8: beq         $v0, $zero, L_800CA344
    if (ctx->r2 == 0) {
        // 0x800CA2FC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800CA344;
    }
    // 0x800CA2FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CA300: lw          $t7, 0x18($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800CA304: lw          $t9, 0x8($a3)
    ctx->r25 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA308: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800CA30C: lw          $t8, 0x1C($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X1C));
    // 0x800CA310: lw          $t0, 0xD8($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0XD8));
    // 0x800CA314: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800CA318: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800CA31C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800CA320: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800CA324: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CA328: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800CA32C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800CA330: lw          $t3, 0x8($a3)
    ctx->r11 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA334: lw          $a0, 0xC($t3)
    ctx->r4 = S32(MEM_W(ctx->r11, 0XC));
    // 0x800CA338: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CA33C: jalr        $t9
    // 0x800CA340: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CA340: nop

    after_1:
L_800CA344:
    // 0x800CA344: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CA348:
    // 0x800CA348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA34C: jr          $ra
    // 0x800CA350: nop

    return;
    // 0x800CA350: nop

;}
RECOMP_FUNC void getinput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2754: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A2758: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800A275C: lh          $v0, 0x52($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X52));
    // 0x800A2760: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x800A2764: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x800A2768: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800A276C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A2770: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800A2774: lh          $t7, -0x6C40($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X6C40));
    // 0x800A2778: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800A277C: lh          $t8, -0x6C38($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X6C38));
    // 0x800A2780: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x800A2784: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800A2788: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x800A278C: lhu         $t9, -0x6C48($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X6C48);
    // 0x800A2790: lh          $t4, 0x52($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X52));
    // 0x800A2794: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A2798: sh          $t7, -0x689E($at)
    MEM_H(-0X689E, ctx->r1) = ctx->r15;
    // 0x800A279C: lui         $s0, 0x8028
    ctx->r16 = S32(0X8028 << 16);
    // 0x800A27A0: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800A27A4: addiu       $s0, $s0, -0x689A
    ctx->r16 = ADD32(ctx->r16, -0X689A);
    // 0x800A27A8: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x800A27AC: sh          $t8, -0x689C($at)
    MEM_H(-0X689C, ctx->r1) = ctx->r24;
    // 0x800A27B0: addiu       $t6, $t6, -0x6C30
    ctx->r14 = ADD32(ctx->r14, -0X6C30);
    // 0x800A27B4: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800A27B8: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800A27BC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800A27C0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800A27C4: lb          $t9, 0x1360($t9)
    ctx->r25 = S32(MEM_B(ctx->r25, 0X1360));
    // 0x800A27C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A27CC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800A27D0: lw          $t8, 0x3C($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X3C));
    // 0x800A27D4: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800A27D8: beq         $t9, $zero, L_800A2814
    if (ctx->r25 == 0) {
        // 0x800A27DC: sh          $t8, -0x6898($at)
        MEM_H(-0X6898, ctx->r1) = ctx->r24;
            goto L_800A2814;
    }
    // 0x800A27DC: sh          $t8, -0x6898($at)
    MEM_H(-0X6898, ctx->r1) = ctx->r24;
    // 0x800A27E0: jal         0x8005B480
    // 0x800A27E4: nop

    demoinput(rdram, ctx);
        goto after_0;
    // 0x800A27E4: nop

    after_0:
    // 0x800A27E8: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800A27EC: lh          $t4, -0x29B2($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X29B2));
    // 0x800A27F0: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800A27F4: lh          $t5, -0x29B0($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X29B0));
    // 0x800A27F8: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800A27FC: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800A2800: lhu         $t6, -0x29AE($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X29AE);
    // 0x800A2804: sh          $t4, -0x689E($at)
    MEM_H(-0X689E, ctx->r1) = ctx->r12;
    // 0x800A2808: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800A280C: sh          $t5, -0x689C($at)
    MEM_H(-0X689C, ctx->r1) = ctx->r13;
    // 0x800A2810: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_800A2814:
    // 0x800A2814: lh          $t8, 0x52($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X52));
    // 0x800A2818: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800A281C: lw          $t7, -0x5370($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X5370));
    // 0x800A2820: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800A2824: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A2828: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800A282C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A2830: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A2834: lui         $s0, 0x802B
    ctx->r16 = S32(0X802B << 16);
    // 0x800A2838: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800A283C: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x800A2840: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A2844: addiu       $s0, $s0, -0x53E8
    ctx->r16 = ADD32(ctx->r16, -0X53E8);
    // 0x800A2848: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A284C: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x800A2850: sw          $t7, -0x68AC($at)
    MEM_W(-0X68AC, ctx->r1) = ctx->r15;
    // 0x800A2854: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800A2858: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x800A285C: lh          $t5, 0x2E6($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X2E6));
    // 0x800A2860: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x800A2864: addiu       $v1, $v1, -0x5598
    ctx->r3 = ADD32(ctx->r3, -0X5598);
    // 0x800A2868: bnel        $t5, $zero, L_800A2DE4
    if (ctx->r13 != 0) {
        // 0x800A286C: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_800A2DE4;
    }
    goto skip_0;
    // 0x800A286C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_0:
    // 0x800A2870: lw          $t6, 0x18C($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X18C));
    // 0x800A2874: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2878: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800A287C: bnel        $at, $zero, L_800A28B4
    if (ctx->r1 != 0) {
        // 0x800A2880: lw          $a0, 0x0($t4)
        ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
            goto L_800A28B4;
    }
    goto skip_1;
    // 0x800A2880: lw          $a0, 0x0($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
    skip_1:
    // 0x800A2884: lw          $t7, 0x13C($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X13C));
    // 0x800A2888: bnel        $t7, $zero, L_800A28B4
    if (ctx->r15 != 0) {
        // 0x800A288C: lw          $a0, 0x0($t4)
        ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
            goto L_800A28B4;
    }
    goto skip_2;
    // 0x800A288C: lw          $a0, 0x0($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
    skip_2:
    // 0x800A2890: lh          $t8, 0x28C($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X28C));
    // 0x800A2894: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800A2898: bgtzl       $t8, L_800A28B4
    if (SIGNED(ctx->r24) > 0) {
        // 0x800A289C: lw          $a0, 0x0($t4)
        ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
            goto L_800A28B4;
    }
    goto skip_3;
    // 0x800A289C: lw          $a0, 0x0($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
    skip_3:
    // 0x800A28A0: lbu         $t9, 0x378C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X378C);
    // 0x800A28A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A28A8: beql        $t9, $at, L_800A2DE4
    if (ctx->r25 == ctx->r1) {
        // 0x800A28AC: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_800A2DE4;
    }
    goto skip_4;
    // 0x800A28AC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_4:
    // 0x800A28B0: lw          $a0, 0x0($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
L_800A28B4:
    // 0x800A28B4: jal         0x800A2684
    // 0x800A28B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    BUTTON(rdram, ctx);
        goto after_1;
    // 0x800A28B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A28BC: lw          $t6, 0x20($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A28C0: slti        $t5, $v0, 0x0
    ctx->r13 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A28C4: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
    // 0x800A28C8: jal         0x800A2684
    // 0x800A28CC: lw          $a0, 0x4($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, 0X4));
    BUTTON(rdram, ctx);
        goto after_2;
    // 0x800A28CC: lw          $a0, 0x4($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, 0X4));
    after_2:
    // 0x800A28D0: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A28D4: slti        $t8, $v0, 0x0
    ctx->r24 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A28D8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800A28DC: lw          $t5, 0x20($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A28E0: or          $t4, $t7, $t9
    ctx->r12 = ctx->r15 | ctx->r25;
    // 0x800A28E4: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x800A28E8: jal         0x800A2684
    // 0x800A28EC: lw          $a0, 0x8($t5)
    ctx->r4 = S32(MEM_W(ctx->r13, 0X8));
    BUTTON(rdram, ctx);
        goto after_3;
    // 0x800A28EC: lw          $a0, 0x8($t5)
    ctx->r4 = S32(MEM_W(ctx->r13, 0X8));
    after_3:
    // 0x800A28F0: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A28F4: slti        $t8, $v0, 0x0
    ctx->r24 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A28F8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800A28FC: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2900: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800A2904: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x800A2908: jal         0x800A2684
    // 0x800A290C: lw          $a0, 0xC($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0XC));
    BUTTON(rdram, ctx);
        goto after_4;
    // 0x800A290C: lw          $a0, 0xC($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0XC));
    after_4:
    // 0x800A2910: lw          $t5, 0x8($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A2914: slti        $t8, $v0, 0x0
    ctx->r24 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A2918: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800A291C: lw          $t9, 0x20($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2920: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800A2924: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x800A2928: jal         0x800A2684
    // 0x800A292C: lw          $a0, 0x10($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X10));
    BUTTON(rdram, ctx);
        goto after_5;
    // 0x800A292C: lw          $a0, 0x10($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X10));
    after_5:
    // 0x800A2930: lw          $t4, 0x8($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A2934: slti        $t8, $v0, 0x0
    ctx->r24 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A2938: lw          $t7, 0x20($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A293C: sll         $t5, $t8, 4
    ctx->r13 = S32(ctx->r24 << 4);
    // 0x800A2940: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800A2944: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // 0x800A2948: lw          $a0, 0x18($t7)
    ctx->r4 = S32(MEM_W(ctx->r15, 0X18));
    // 0x800A294C: jal         0x800A2684
    // 0x800A2950: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    BUTTON(rdram, ctx);
        goto after_6;
    // 0x800A2950: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    after_6:
    // 0x800A2954: bgez        $v0, L_800A2960
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2958: lh          $v1, 0x4E($sp)
        ctx->r3 = S32(MEM_H(ctx->r29, 0X4E));
            goto L_800A2960;
    }
    // 0x800A2958: lh          $v1, 0x4E($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X4E));
    // 0x800A295C: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_800A2960:
    // 0x800A2960: lw          $t9, 0x20($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2964: lw          $a0, 0x14($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X14));
    // 0x800A2968: jal         0x800A2684
    // 0x800A296C: sh          $v1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r3;
    BUTTON(rdram, ctx);
        goto after_7;
    // 0x800A296C: sh          $v1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r3;
    after_7:
    // 0x800A2970: bgez        $v0, L_800A297C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2974: lh          $v1, 0x4E($sp)
        ctx->r3 = S32(MEM_H(ctx->r29, 0X4E));
            goto L_800A297C;
    }
    // 0x800A2974: lh          $v1, 0x4E($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X4E));
    // 0x800A2978: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
L_800A297C:
    // 0x800A297C: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A2980: sll         $t4, $v1, 8
    ctx->r12 = S32(ctx->r3 << 8);
    // 0x800A2984: lw          $t6, 0x20($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2988: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x800A298C: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
    // 0x800A2990: jal         0x800A2684
    // 0x800A2994: lw          $a0, 0x24($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, 0X24));
    BUTTON(rdram, ctx);
        goto after_8;
    // 0x800A2994: lw          $a0, 0x24($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, 0X24));
    after_8:
    // 0x800A2998: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A299C: slti        $t9, $v0, 0x0
    ctx->r25 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A29A0: sll         $t8, $t9, 29
    ctx->r24 = S32(ctx->r25 << 29);
    // 0x800A29A4: lw          $t5, 0x20($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A29A8: or          $t4, $t7, $t8
    ctx->r12 = ctx->r15 | ctx->r24;
    // 0x800A29AC: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x800A29B0: jal         0x800A2684
    // 0x800A29B4: lw          $a0, 0x1C($t5)
    ctx->r4 = S32(MEM_W(ctx->r13, 0X1C));
    BUTTON(rdram, ctx);
        goto after_9;
    // 0x800A29B4: lw          $a0, 0x1C($t5)
    ctx->r4 = S32(MEM_W(ctx->r13, 0X1C));
    after_9:
    // 0x800A29B8: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A29BC: slti        $t9, $v0, 0x0
    ctx->r25 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A29C0: sll         $t7, $t9, 20
    ctx->r15 = S32(ctx->r25 << 20);
    // 0x800A29C4: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A29C8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800A29CC: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800A29D0: jal         0x800A2684
    // 0x800A29D4: lw          $a0, 0x20($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0X20));
    BUTTON(rdram, ctx);
        goto after_10;
    // 0x800A29D4: lw          $a0, 0x20($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0X20));
    after_10:
    // 0x800A29D8: lw          $t5, 0x8($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A29DC: slti        $t9, $v0, 0x0
    ctx->r25 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A29E0: sll         $t6, $t9, 27
    ctx->r14 = S32(ctx->r25 << 27);
    // 0x800A29E4: lw          $t8, 0x20($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A29E8: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800A29EC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x800A29F0: jal         0x800A2684
    // 0x800A29F4: lw          $a0, 0x28($t8)
    ctx->r4 = S32(MEM_W(ctx->r24, 0X28));
    BUTTON(rdram, ctx);
        goto after_11;
    // 0x800A29F4: lw          $a0, 0x28($t8)
    ctx->r4 = S32(MEM_W(ctx->r24, 0X28));
    after_11:
    // 0x800A29F8: slti        $t9, $v0, 0x0
    ctx->r25 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x800A29FC: lw          $t4, 0x8($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800A2A00: sll         $t5, $t9, 30
    ctx->r13 = S32(ctx->r25 << 30);
    // 0x800A2A04: lh          $t9, 0x52($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X52));
    // 0x800A2A08: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800A2A0C: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x800A2A10: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800A2A14: addiu       $t2, $t2, -0x53D8
    ctx->r10 = ADD32(ctx->r10, -0X53D8);
    // 0x800A2A18: addiu       $a1, $a1, -0x53D0
    ctx->r5 = ADD32(ctx->r5, -0X53D0);
    // 0x800A2A1C: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800A2A20: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // Host Mighty Foot maps to the game's logical quick-kick bit 22.
    if (duke64_mighty_foot_held(SIGNED(MEM_H(ctx->r29, 0X52)))) {
        MEM_W(0X8, ctx->r16) |= 0X400000;
    }
    // 0x800A2A24: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800A2A28: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800A2A2C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800A2A30: lui         $v1, 0x8028
    ctx->r3 = S32(0X8028 << 16);
    // 0x800A2A34: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x800A2A38: sw          $zero, -0x53D4($at)
    MEM_W(-0X53D4, ctx->r1) = 0;
    // 0x800A2A3C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A2A40: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x800A2A44: addiu       $v1, $v1, -0x689E
    ctx->r3 = ADD32(ctx->r3, -0X689E);
    // 0x800A2A48: lh          $a0, 0x0($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X0));
    // 0x800A2A4C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800A2A50: lb          $t5, 0x5601($t5)
    ctx->r13 = S32(MEM_B(ctx->r13, 0X5601));
    // 0x800A2A54: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800A2A58: addiu       $a2, $a2, -0x53CC
    ctx->r6 = ADD32(ctx->r6, -0X53CC);
    // 0x800A2A5C: blez        $a0, L_800A2A6C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800A2A60: sw          $t5, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r13;
            goto L_800A2A6C;
    }
    // 0x800A2A60: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800A2A64: b           L_800A2A70
    // 0x800A2A68: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800A2A70;
    // 0x800A2A68: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800A2A6C:
    // 0x800A2A6C: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_800A2A70:
    // 0x800A2A70: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800A2A74: beq         $at, $zero, L_800A2A84
    if (ctx->r1 == 0) {
        // 0x800A2A78: lui         $a3, 0x8028
        ctx->r7 = S32(0X8028 << 16);
            goto L_800A2A84;
    }
    // 0x800A2A78: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800A2A7C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800A2A80: lh          $a0, 0x0($v1)
    ctx->r4 = S32(MEM_H(ctx->r3, 0X0));
L_800A2A84:
    // 0x800A2A84: addiu       $a3, $a3, -0x689C
    ctx->r7 = ADD32(ctx->r7, -0X689C);
    // 0x800A2A88: lh          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800A2A8C: blezl       $v1, L_800A2AA0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A2A90: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_800A2AA0;
    }
    goto skip_5;
    // 0x800A2A90: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    skip_5:
    // 0x800A2A94: b           L_800A2AA0
    // 0x800A2A98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800A2AA0;
    // 0x800A2A98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A2A9C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_800A2AA0:
    // 0x800A2AA0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800A2AA4: beql        $at, $zero, L_800A2AB8
    if (ctx->r1 == 0) {
        // 0x800A2AA8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A2AB8;
    }
    goto skip_6;
    // 0x800A2AA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_6:
    // 0x800A2AAC: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x800A2AB0: lh          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800A2AB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A2AB8:
    // 0x800A2AB8: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x800A2ABC: lw          $t7, 0x24($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800A2AC0: mflo        $t6
    ctx->r14 = lo;
    // 0x800A2AC4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800A2AC8: lbu         $t8, 0x280($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X280);
    // 0x800A2ACC: bne         $t8, $zero, L_800A2ADC
    if (ctx->r24 != 0) {
        // 0x800A2AD0: sll         $t9, $v1, 1
        ctx->r25 = S32(ctx->r3 << 1);
            goto L_800A2ADC;
    }
    // 0x800A2AD0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800A2AD4: b           L_800A2B44
    // 0x800A2AD8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
        goto L_800A2B44;
    // 0x800A2AD8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_800A2ADC:
    // 0x800A2ADC: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x800A2AE0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800A2AE4: lui         $at, 0x3FF4
    ctx->r1 = S32(0X3FF4 << 16);
    // 0x800A2AE8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A2AEC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A2AF0: lw          $a0, 0x0($a2)
    ctx->r4 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A2AF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A2AF8: mtc1        $a0, $f16
    ctx->f16.u32l = ctx->r4;
    // 0x800A2AFC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A2B00: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800A2B04: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x800A2B08: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800A2B0C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800A2B10: nop

    // 0x800A2B14: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800A2B18: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800A2B1C: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x800A2B20: bnel        $at, $zero, L_800A2B30
    if (ctx->r1 != 0) {
        // 0x800A2B24: slti        $at, $v0, -0x19
        ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
            goto L_800A2B30;
    }
    goto skip_7;
    // 0x800A2B24: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
    skip_7:
    // 0x800A2B28: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // 0x800A2B2C: slti        $at, $v0, -0x19
    ctx->r1 = SIGNED(ctx->r2) < -0X19 ? 1 : 0;
L_800A2B30:
    // 0x800A2B30: beql        $at, $zero, L_800A2B40
    if (ctx->r1 == 0) {
        // 0x800A2B34: subu        $t8, $a0, $v0
        ctx->r24 = SUB32(ctx->r4, ctx->r2);
            goto L_800A2B40;
    }
    goto skip_8;
    // 0x800A2B34: subu        $t8, $a0, $v0
    ctx->r24 = SUB32(ctx->r4, ctx->r2);
    skip_8:
    // 0x800A2B38: addiu       $v0, $zero, -0x19
    ctx->r2 = ADD32(0, -0X19);
    // 0x800A2B3C: subu        $t8, $a0, $v0
    ctx->r24 = SUB32(ctx->r4, ctx->r2);
L_800A2B40:
    // 0x800A2B40: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800A2B44:
    // 0x800A2B44: lw          $t9, 0x20($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2B48: jal         0x800A2684
    // 0x800A2B4C: lw          $a0, 0x34($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X34));
    BUTTON(rdram, ctx);
        goto after_12;
    // 0x800A2B4C: lw          $a0, 0x34($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X34));
    after_12:
    // 0x800A2B50: bgez        $v0, L_800A2B68
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2B54: lui         $t4, 0x802B
        ctx->r12 = S32(0X802B << 16);
            goto L_800A2B68;
    }
    // 0x800A2B54: lui         $t4, 0x802B
    ctx->r12 = S32(0X802B << 16);
    // 0x800A2B58: lw          $t4, -0x53D4($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X53D4));
    // 0x800A2B5C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800A2B60: addiu       $t5, $t4, 0x50
    ctx->r13 = ADD32(ctx->r12, 0X50);
    // 0x800A2B64: sw          $t5, -0x53D4($at)
    MEM_W(-0X53D4, ctx->r1) = ctx->r13;
L_800A2B68:
    // 0x800A2B68: lw          $t6, 0x20($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2B6C: jal         0x800A2684
    // 0x800A2B70: lw          $a0, 0x38($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, 0X38));
    BUTTON(rdram, ctx);
        goto after_13;
    // 0x800A2B70: lw          $a0, 0x38($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, 0X38));
    after_13:
    // 0x800A2B74: bgez        $v0, L_800A2B8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2B78: lui         $t7, 0x802B
        ctx->r15 = S32(0X802B << 16);
            goto L_800A2B8C;
    }
    // 0x800A2B78: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800A2B7C: lw          $t7, -0x53D4($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X53D4));
    // 0x800A2B80: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800A2B84: addiu       $t8, $t7, -0x50
    ctx->r24 = ADD32(ctx->r15, -0X50);
    // 0x800A2B88: sw          $t8, -0x53D4($at)
    MEM_W(-0X53D4, ctx->r1) = ctx->r24;
L_800A2B8C:
    // 0x800A2B8C: lw          $t9, 0x20($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2B90: jal         0x800A2684
    // 0x800A2B94: lw          $a0, 0x2C($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X2C));
    BUTTON(rdram, ctx);
        goto after_14;
    // 0x800A2B94: lw          $a0, 0x2C($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X2C));
    after_14:
    // 0x800A2B98: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x800A2B9C: bgez        $v0, L_800A2BB4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2BA0: addiu       $t2, $t2, -0x53D8
        ctx->r10 = ADD32(ctx->r10, -0X53D8);
            goto L_800A2BB4;
    }
    // 0x800A2BA0: addiu       $t2, $t2, -0x53D8
    ctx->r10 = ADD32(ctx->r10, -0X53D8);
    // 0x800A2BA4: lw          $t4, 0x0($t2)
    ctx->r12 = S32(MEM_W(ctx->r10, 0X0));
    // 0x800A2BA8: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800A2BAC: addiu       $t5, $t4, 0x50
    ctx->r13 = ADD32(ctx->r12, 0X50);
    // 0x800A2BB0: sw          $t5, -0x53D8($at)
    MEM_W(-0X53D8, ctx->r1) = ctx->r13;
L_800A2BB4:
    // 0x800A2BB4: lw          $t6, 0x20($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2BB8: jal         0x800A2684
    // 0x800A2BBC: lw          $a0, 0x30($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, 0X30));
    BUTTON(rdram, ctx);
        goto after_15;
    // 0x800A2BBC: lw          $a0, 0x30($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, 0X30));
    after_15:
    // 0x800A2BC0: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x800A2BC4: bgez        $v0, L_800A2BDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2BC8: addiu       $t2, $t2, -0x53D8
        ctx->r10 = ADD32(ctx->r10, -0X53D8);
            goto L_800A2BDC;
    }
    // 0x800A2BC8: addiu       $t2, $t2, -0x53D8
    ctx->r10 = ADD32(ctx->r10, -0X53D8);
    // 0x800A2BCC: lw          $t7, 0x0($t2)
    ctx->r15 = S32(MEM_W(ctx->r10, 0X0));
    // 0x800A2BD0: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800A2BD4: addiu       $t8, $t7, -0x50
    ctx->r24 = ADD32(ctx->r15, -0X50);
    // 0x800A2BD8: sw          $t8, -0x53D8($at)
    MEM_W(-0X53D8, ctx->r1) = ctx->r24;
    const int keyboard_strafe_left = duke64_keyboard_strafe_left();
    const int keyboard_strafe_right = duke64_keyboard_strafe_right();
    const int keyboard_move_forward = duke64_keyboard_move_forward();
    const int keyboard_move_backward = duke64_keyboard_move_backward();
    const gpr keyboard_base = S32(0X802B << 16);
    if (keyboard_strafe_left != 0) {
        MEM_W(-0X53D4, keyboard_base) =
            ADD32(MEM_W(keyboard_base, -0X53D4), keyboard_strafe_left);
    }
    if (keyboard_strafe_right != 0) {
        MEM_W(-0X53D4, keyboard_base) =
            ADD32(MEM_W(keyboard_base, -0X53D4), -keyboard_strafe_right);
    }
    if (keyboard_move_forward != 0) {
        MEM_W(-0X53D8, keyboard_base) =
            ADD32(MEM_W(keyboard_base, -0X53D8), keyboard_move_forward);
    }
    if (keyboard_move_backward != 0) {
        MEM_W(-0X53D8, keyboard_base) =
            ADD32(MEM_W(keyboard_base, -0X53D8), -keyboard_move_backward);
    }

L_800A2BDC:
    // 0x800A2BDC: lw          $v1, 0x0($t2)
    ctx->r3 = S32(MEM_W(ctx->r10, 0X0));
    // 0x800A2BE0: lui         $t3, 0x802B
    ctx->r11 = S32(0X802B << 16);
    // 0x800A2BE4: addiu       $t3, $t3, -0x53D4
    ctx->r11 = ADD32(ctx->r11, -0X53D4);
    // 0x800A2BE8: slti        $at, $v1, -0x5A
    ctx->r1 = SIGNED(ctx->r3) < -0X5A ? 1 : 0;
    // 0x800A2BEC: beq         $at, $zero, L_800A2BFC
    if (ctx->r1 == 0) {
        // 0x800A2BF0: lui         $t0, 0x802B
        ctx->r8 = S32(0X802B << 16);
            goto L_800A2BFC;
    }
    // 0x800A2BF0: lui         $t0, 0x802B
    ctx->r8 = S32(0X802B << 16);
    // 0x800A2BF4: addiu       $v1, $zero, -0x5A
    ctx->r3 = ADD32(0, -0X5A);
    // 0x800A2BF8: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
L_800A2BFC:
    // 0x800A2BFC: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
    // 0x800A2C00: bne         $at, $zero, L_800A2C10
    if (ctx->r1 != 0) {
        // 0x800A2C04: addiu       $t0, $t0, -0x53D0
        ctx->r8 = ADD32(ctx->r8, -0X53D0);
            goto L_800A2C10;
    }
    // 0x800A2C04: addiu       $t0, $t0, -0x53D0
    ctx->r8 = ADD32(ctx->r8, -0X53D0);
    // 0x800A2C08: addiu       $v1, $zero, 0x5A
    ctx->r3 = ADD32(0, 0X5A);
    // 0x800A2C0C: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
L_800A2C10:
    // 0x800A2C10: lw          $v0, 0x0($t3)
    ctx->r2 = S32(MEM_W(ctx->r11, 0X0));
    // 0x800A2C14: lui         $t1, 0x802B
    ctx->r9 = S32(0X802B << 16);
    // 0x800A2C18: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x800A2C1C: slti        $at, $v0, -0x5A
    ctx->r1 = SIGNED(ctx->r2) < -0X5A ? 1 : 0;
    // 0x800A2C20: beq         $at, $zero, L_800A2C30
    if (ctx->r1 == 0) {
        // 0x800A2C24: addiu       $t1, $t1, -0x53CC
        ctx->r9 = ADD32(ctx->r9, -0X53CC);
            goto L_800A2C30;
    }
    // 0x800A2C24: addiu       $t1, $t1, -0x53CC
    ctx->r9 = ADD32(ctx->r9, -0X53CC);
    // 0x800A2C28: addiu       $v0, $zero, -0x5A
    ctx->r2 = ADD32(0, -0X5A);
    // 0x800A2C2C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_800A2C30:
    // 0x800A2C30: slti        $at, $v0, 0x5B
    ctx->r1 = SIGNED(ctx->r2) < 0X5B ? 1 : 0;
    // 0x800A2C34: bne         $at, $zero, L_800A2C40
    if (ctx->r1 != 0) {
        // 0x800A2C38: addiu       $t8, $zero, 0x7F
        ctx->r24 = ADD32(0, 0X7F);
            goto L_800A2C40;
    }
    // 0x800A2C38: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x800A2C3C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_800A2C40:
    // 0x800A2C40: lw          $v0, 0x0($t0)
    ctx->r2 = S32(MEM_W(ctx->r8, 0X0));
    // 0x800A2C44: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x800A2C48: slti        $at, $v0, -0x7F
    ctx->r1 = SIGNED(ctx->r2) < -0X7F ? 1 : 0;
    // 0x800A2C4C: beql        $at, $zero, L_800A2C60
    if (ctx->r1 == 0) {
        // 0x800A2C50: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_800A2C60;
    }
    goto skip_9;
    // 0x800A2C50: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    skip_9:
    // 0x800A2C54: addiu       $v0, $zero, -0x7F
    ctx->r2 = ADD32(0, -0X7F);
    // 0x800A2C58: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800A2C5C: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
L_800A2C60:
    // 0x800A2C60: bne         $at, $zero, L_800A2C6C
    if (ctx->r1 != 0) {
        // 0x800A2C64: lui         $v0, 0x802B
        ctx->r2 = S32(0X802B << 16);
            goto L_800A2C6C;
    }
    // 0x800A2C64: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x800A2C68: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_800A2C6C:
    // 0x800A2C6C: lw          $a0, 0x0($t1)
    ctx->r4 = S32(MEM_W(ctx->r9, 0X0));
    // 0x800A2C70: addiu       $v0, $v0, -0x5598
    ctx->r2 = ADD32(ctx->r2, -0X5598);
    // 0x800A2C74: slti        $at, $a0, -0x7F
    ctx->r1 = SIGNED(ctx->r4) < -0X7F ? 1 : 0;
    // 0x800A2C78: beql        $at, $zero, L_800A2C8C
    if (ctx->r1 == 0) {
        // 0x800A2C7C: slti        $at, $a0, 0x80
        ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
            goto L_800A2C8C;
    }
    goto skip_10;
    // 0x800A2C7C: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    skip_10:
    // 0x800A2C80: addiu       $a0, $zero, -0x7F
    ctx->r4 = ADD32(0, -0X7F);
    // 0x800A2C84: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x800A2C88: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
L_800A2C8C:
    // 0x800A2C8C: bnel        $at, $zero, L_800A2C9C
    if (ctx->r1 != 0) {
        // 0x800A2C90: lbu         $t5, 0x6($v0)
        ctx->r13 = MEM_BU(ctx->r2, 0X6);
            goto L_800A2C9C;
    }
    goto skip_11;
    // 0x800A2C90: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    skip_11:
    // 0x800A2C94: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800A2C98: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
L_800A2C9C:
    // 0x800A2C9C: beql        $t5, $zero, L_800A2CD4
    if (ctx->r13 == 0) {
        // 0x800A2CA0: lw          $t8, 0x24($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800A2CD4;
    }
    goto skip_12;
    // 0x800A2CA0: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    skip_12:
    // 0x800A2CA4: lbu         $t6, 0xE4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XE4);
    // 0x800A2CA8: beql        $t6, $zero, L_800A2CD4
    if (ctx->r14 == 0) {
        // 0x800A2CAC: lw          $t8, 0x24($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800A2CD4;
    }
    goto skip_13;
    // 0x800A2CAC: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    skip_13:
    // 0x800A2CB0: lw          $t7, 0x0($t0)
    ctx->r15 = S32(MEM_W(ctx->r8, 0X0));
    // 0x800A2CB4: sw          $v1, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r3;
    // 0x800A2CB8: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800A2CBC: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x800A2CC0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800A2CC4: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800A2CC8: b           L_800A2DE0
    // 0x800A2CCC: sw          $t7, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r15;
        goto L_800A2DE0;
    // 0x800A2CCC: sw          $t7, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r15;
    // 0x800A2CD0: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
L_800A2CD4:
    // 0x800A2CD4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800A2CD8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A2CDC: lh          $v0, 0x282($t8)
    ctx->r2 = S32(MEM_H(ctx->r24, 0X282));
    // 0x800A2CE0: sra         $a0, $v1, 31
    ctx->r4 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800A2CE4: addiu       $t9, $v0, 0xA00
    ctx->r25 = ADD32(ctx->r2, 0XA00);
    // 0x800A2CE8: andi        $t4, $t9, 0x7FF
    ctx->r12 = ctx->r25 & 0X7FF;
    // 0x800A2CEC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800A2CF0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800A2CF4: lh          $a3, -0x9A0($t6)
    ctx->r7 = S32(MEM_H(ctx->r14, -0X9A0));
    // 0x800A2CF8: sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // 0x800A2CFC: jal         0x8008FB84
    // 0x800A2D00: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    mulscale9(rdram, ctx);
        goto after_16;
    // 0x800A2D00: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_16:
    // 0x800A2D04: lh          $t8, 0x4C($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X4C));
    // 0x800A2D08: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800A2D0C: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x800A2D10: addiu       $t9, $t8, 0x800
    ctx->r25 = ADD32(ctx->r24, 0X800);
    // 0x800A2D14: andi        $t4, $t9, 0x7FF
    ctx->r12 = ctx->r25 & 0X7FF;
    // 0x800A2D18: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800A2D1C: addiu       $t6, $t6, -0x9A0
    ctx->r14 = ADD32(ctx->r14, -0X9A0);
    // 0x800A2D20: addiu       $t2, $t2, -0x53D8
    ctx->r10 = ADD32(ctx->r10, -0X53D8);
    // 0x800A2D24: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x800A2D28: lh          $a3, 0x0($t1)
    ctx->r7 = S32(MEM_H(ctx->r9, 0X0));
    // 0x800A2D2C: lw          $a1, 0x0($t2)
    ctx->r5 = S32(MEM_W(ctx->r10, 0X0));
    // 0x800A2D30: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800A2D34: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800A2D38: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x800A2D3C: jal         0x8008FB84
    // 0x800A2D40: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale9(rdram, ctx);
        goto after_17;
    // 0x800A2D40: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_17:
    // 0x800A2D44: lw          $t1, 0x20($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800A2D48: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800A2D4C: lw          $a1, -0x53D4($t8)
    ctx->r5 = S32(MEM_W(ctx->r24, -0X53D4));
    // 0x800A2D50: lh          $a3, 0x0($t1)
    ctx->r7 = S32(MEM_H(ctx->r9, 0X0));
    // 0x800A2D54: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800A2D58: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800A2D5C: jal         0x8008FB84
    // 0x800A2D60: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    mulscale9(rdram, ctx);
        goto after_18;
    // 0x800A2D60: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_18:
    // 0x800A2D64: lh          $t5, 0x4C($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X4C));
    // 0x800A2D68: lw          $t0, 0x38($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800A2D6C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800A2D70: addiu       $t6, $t5, 0x600
    ctx->r14 = ADD32(ctx->r13, 0X600);
    // 0x800A2D74: andi        $t7, $t6, 0x7FF
    ctx->r15 = ctx->r14 & 0X7FF;
    // 0x800A2D78: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800A2D7C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A2D80: lui         $t4, 0x802B
    ctx->r12 = S32(0X802B << 16);
    // 0x800A2D84: lw          $a1, -0x53D4($t4)
    ctx->r5 = S32(MEM_W(ctx->r12, -0X53D4));
    // 0x800A2D88: lh          $a3, -0x9A0($t9)
    ctx->r7 = S32(MEM_H(ctx->r25, -0X9A0));
    // 0x800A2D8C: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800A2D90: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800A2D94: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800A2D98: jal         0x8008FB84
    // 0x800A2D9C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    mulscale9(rdram, ctx);
        goto after_19;
    // 0x800A2D9C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_19:
    // 0x800A2DA0: lw          $t4, 0x24($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800A2DA4: lw          $v1, 0x34($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800A2DA8: lw          $t0, 0x38($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800A2DAC: lw          $t5, 0x37C($t4)
    ctx->r13 = S32(MEM_W(ctx->r12, 0X37C));
    // 0x800A2DB0: lw          $t6, 0x380($t4)
    ctx->r14 = S32(MEM_W(ctx->r12, 0X380));
    // 0x800A2DB4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800A2DB8: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x800A2DBC: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800A2DC0: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x800A2DC4: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x800A2DC8: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800A2DCC: lw          $t7, -0x53D0($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X53D0));
    // 0x800A2DD0: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800A2DD4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800A2DD8: lw          $t8, -0x53CC($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X53CC));
    // 0x800A2DDC: sb          $t8, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r24;
L_800A2DE0:
    // 0x800A2DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_800A2DE4:
    // 0x800A2DE4: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800A2DE8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800A2DEC: jr          $ra
    // 0x800A2DF0: nop

    return;
    // 0x800A2DF0: nop

;}
RECOMP_FUNC void osScAddClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C57C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004C580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C584: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004C588: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004C58C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004C590: jal         0x800BC180
    // 0x8004C594: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8004C594: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004C598: lw          $a1, 0x1C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004C59C: lw          $t6, 0x20($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004C5A0: lw          $v1, 0x18($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004C5A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004C5A8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8004C5AC: lw          $t7, 0x260($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X260));
    // 0x8004C5B0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8004C5B4: jal         0x800BC180
    // 0x8004C5B8: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8004C5B8: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    after_1:
    // 0x8004C5BC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004C5C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004C5C4: jr          $ra
    // 0x8004C5C8: nop

    return;
    // 0x8004C5C8: nop

;}
RECOMP_FUNC void dmulscale14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090794: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009079C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800907A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800907A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800907A8: jal         0x800BB8F8
    // 0x800907AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800907AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800907B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800907B4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800907B8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800907BC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800907C0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800907C4: jal         0x800BB8F8
    // 0x800907C8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800907C8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x800907CC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800907D0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800907D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800907D8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x800907DC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800907E0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x800907E4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800907E8: jal         0x800BBA24
    // 0x800907EC: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x800907EC: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_2:
    // 0x800907F0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800907F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800907F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800907FC: jr          $ra
    // 0x80090800: nop

    return;
    // 0x80090800: nop

;}
RECOMP_FUNC void dmulscale16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090874: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009087C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090880: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090884: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090888: jal         0x800BB8F8
    // 0x8009088C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009088C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090890: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090894: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090898: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009089C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800908A0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800908A4: jal         0x800BB8F8
    // 0x800908A8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800908A8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x800908AC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800908B0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800908B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800908B8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x800908BC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800908C0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x800908C4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800908C8: jal         0x800BBA24
    // 0x800908CC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x800908CC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x800908D0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800908D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800908D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800908DC: jr          $ra
    // 0x800908E0: nop

    return;
    // 0x800908E0: nop

;}
RECOMP_FUNC void FX_StopSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800593F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800593FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059400: jal         0x8005850C
    // 0x80059404: nop

    func_8005850C(rdram, ctx);
        goto after_0;
    // 0x80059404: nop

    after_0:
    // 0x80059408: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8005940C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059410: jr          $ra
    // 0x80059414: nop

    return;
    // 0x80059414: nop

;}
RECOMP_FUNC void ksqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092164: bgezl       $a0, L_80092178
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80092168: mtc1        $a0, $f4
        ctx->f4.u32l = ctx->r4;
            goto L_80092178;
    }
    goto skip_0;
    // 0x80092168: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    skip_0:
    // 0x8009216C: jr          $ra
    // 0x80092170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80092170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80092174: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_80092178:
    // 0x80092178: nop

    // 0x8009217C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80092180: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80092184: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80092188: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8009218C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80092190: nop

    // 0x80092194: jr          $ra
    // 0x80092198: nop

    return;
    // 0x80092198: nop

;}
RECOMP_FUNC void nextsectorneighborz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092AA8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80092AAC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80092AB0: sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6 << 16);
    // 0x80092AB4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80092AB8: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80092ABC: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80092AC0: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80092AC4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80092AC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80092ACC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80092AD0: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80092AD4: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80092AD8: bne         $a3, $t1, L_80092AEC
    if (ctx->r7 != ctx->r9) {
        // 0x80092ADC: sw          $a2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r6;
            goto L_80092AEC;
    }
    // 0x80092ADC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80092AE0: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80092AE4: b           L_80092AF0
    // 0x80092AE8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
        goto L_80092AF0;
    // 0x80092AE8: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
L_80092AEC:
    // 0x80092AEC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
L_80092AF0:
    // 0x80092AF0: lh          $t9, 0x12($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X12));
    // 0x80092AF4: addiu       $t3, $zero, 0x30
    ctx->r11 = ADD32(0, 0X30);
    // 0x80092AF8: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x80092AFC: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092B00: addiu       $t2, $t2, -0x1988
    ctx->r10 = ADD32(ctx->r10, -0X1988);
    // 0x80092B04: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80092B08: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x80092B0C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80092B10: mflo        $t4
    ctx->r12 = lo;
    // 0x80092B14: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x80092B18: lh          $t5, 0x8($a1)
    ctx->r13 = S32(MEM_H(ctx->r5, 0X8));
    // 0x80092B1C: lh          $a2, 0xA($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0XA));
    // 0x80092B20: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80092B24: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80092B28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80092B2C: andi        $a1, $a2, 0x1
    ctx->r5 = ctx->r6 & 0X1;
    // 0x80092B30: beq         $zero, $a1, L_80092C44
    if (0 == ctx->r5) {
        // 0x80092B34: addu        $a0, $t6, $t7
        ctx->r4 = ADD32(ctx->r14, ctx->r15);
            goto L_80092C44;
    }
    // 0x80092B34: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80092B38: lh          $a1, 0xC($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0XC));
    // 0x80092B3C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80092B40: bltz        $a1, L_80092C3C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80092B44: nop
    
            goto L_80092C3C;
    }
    // 0x80092B44: nop

    // 0x80092B48: bne         $s0, $t1, L_80092BC8
    if (ctx->r16 != ctx->r9) {
        // 0x80092B4C: nop
    
            goto L_80092BC8;
    }
    // 0x80092B4C: nop

    // 0x80092B50: bne         $a3, $t1, L_80092B90
    if (ctx->r7 != ctx->r9) {
        // 0x80092B54: nop
    
            goto L_80092B90;
    }
    // 0x80092B54: nop

    // 0x80092B58: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092B5C: mflo        $t8
    ctx->r24 = lo;
    // 0x80092B60: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80092B64: lw          $t0, 0x4($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0X4));
    // 0x80092B68: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092B6C: beq         $at, $zero, L_80092C3C
    if (ctx->r1 == 0) {
        // 0x80092B70: slt         $at, $t0, $v0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80092C3C;
    }
    // 0x80092B70: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80092B74: beq         $at, $zero, L_80092C3C
    if (ctx->r1 == 0) {
        // 0x80092B78: nop
    
            goto L_80092C3C;
    }
    // 0x80092B78: nop

    // 0x80092B7C: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092B80: sra         $t4, $v1, 16
    ctx->r12 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092B84: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80092B88: b           L_80092C3C
    // 0x80092B8C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80092C3C;
    // 0x80092B8C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80092B90:
    // 0x80092B90: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092B94: mflo        $t5
    ctx->r13 = lo;
    // 0x80092B98: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80092B9C: lw          $t0, 0x4($t6)
    ctx->r8 = S32(MEM_W(ctx->r14, 0X4));
    // 0x80092BA0: slt         $at, $t0, $s1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80092BA4: beq         $at, $zero, L_80092C3C
    if (ctx->r1 == 0) {
        // 0x80092BA8: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80092C3C;
    }
    // 0x80092BA8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092BAC: beq         $at, $zero, L_80092C3C
    if (ctx->r1 == 0) {
        // 0x80092BB0: nop
    
            goto L_80092C3C;
    }
    // 0x80092BB0: nop

    // 0x80092BB4: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092BB8: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092BBC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80092BC0: b           L_80092C3C
    // 0x80092BC4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80092C3C;
    // 0x80092BC4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80092BC8:
    // 0x80092BC8: bne         $a3, $t1, L_80092C08
    if (ctx->r7 != ctx->r9) {
        // 0x80092BCC: nop
    
            goto L_80092C08;
    }
    // 0x80092BCC: nop

    // 0x80092BD0: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092BD4: mflo        $t8
    ctx->r24 = lo;
    // 0x80092BD8: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80092BDC: lw          $t0, 0x0($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0X0));
    // 0x80092BE0: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092BE4: beq         $at, $zero, L_80092C3C
    if (ctx->r1 == 0) {
        // 0x80092BE8: slt         $at, $t0, $v0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80092C3C;
    }
    // 0x80092BE8: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80092BEC: beq         $at, $zero, L_80092C3C
    if (ctx->r1 == 0) {
        // 0x80092BF0: nop
    
            goto L_80092C3C;
    }
    // 0x80092BF0: nop

    // 0x80092BF4: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092BF8: sra         $t4, $v1, 16
    ctx->r12 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092BFC: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80092C00: b           L_80092C3C
    // 0x80092C04: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80092C3C;
    // 0x80092C04: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80092C08:
    // 0x80092C08: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092C0C: mflo        $t5
    ctx->r13 = lo;
    // 0x80092C10: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80092C14: lw          $t0, 0x0($t6)
    ctx->r8 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80092C18: slt         $at, $t0, $s1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80092C1C: beq         $at, $zero, L_80092C3C
    if (ctx->r1 == 0) {
        // 0x80092C20: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80092C3C;
    }
    // 0x80092C20: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092C24: beq         $at, $zero, L_80092C3C
    if (ctx->r1 == 0) {
        // 0x80092C28: nop
    
            goto L_80092C3C;
    }
    // 0x80092C28: nop

    // 0x80092C2C: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092C30: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092C34: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80092C38: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80092C3C:
    // 0x80092C3C: beq         $a2, $zero, L_80092E54
    if (ctx->r6 == 0) {
        // 0x80092C40: addiu       $a0, $a0, 0x24
        ctx->r4 = ADD32(ctx->r4, 0X24);
            goto L_80092E54;
    }
    // 0x80092C40: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
L_80092C44:
    // 0x80092C44: lh          $a1, 0xC($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0XC));
    // 0x80092C48: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80092C4C: bltzl       $a1, L_80092D4C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80092C50: lh          $a1, 0x30($a0)
        ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
            goto L_80092D4C;
    }
    goto skip_0;
    // 0x80092C50: lh          $a1, 0x30($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
    skip_0:
    // 0x80092C54: bne         $s0, $t1, L_80092CD4
    if (ctx->r16 != ctx->r9) {
        // 0x80092C58: nop
    
            goto L_80092CD4;
    }
    // 0x80092C58: nop

    // 0x80092C5C: bne         $a3, $t1, L_80092C9C
    if (ctx->r7 != ctx->r9) {
        // 0x80092C60: nop
    
            goto L_80092C9C;
    }
    // 0x80092C60: nop

    // 0x80092C64: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092C68: mflo        $t8
    ctx->r24 = lo;
    // 0x80092C6C: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80092C70: lw          $t0, 0x4($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0X4));
    // 0x80092C74: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092C78: beq         $at, $zero, L_80092D48
    if (ctx->r1 == 0) {
        // 0x80092C7C: slt         $at, $t0, $v0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80092D48;
    }
    // 0x80092C7C: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80092C80: beql        $at, $zero, L_80092D4C
    if (ctx->r1 == 0) {
        // 0x80092C84: lh          $a1, 0x30($a0)
        ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
            goto L_80092D4C;
    }
    goto skip_1;
    // 0x80092C84: lh          $a1, 0x30($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
    skip_1:
    // 0x80092C88: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092C8C: sra         $t4, $v1, 16
    ctx->r12 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092C90: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80092C94: b           L_80092D48
    // 0x80092C98: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_80092D48;
    // 0x80092C98: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_80092C9C:
    // 0x80092C9C: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092CA0: mflo        $t5
    ctx->r13 = lo;
    // 0x80092CA4: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80092CA8: lw          $t0, 0x4($t6)
    ctx->r8 = S32(MEM_W(ctx->r14, 0X4));
    // 0x80092CAC: slt         $at, $t0, $s1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80092CB0: beq         $at, $zero, L_80092D48
    if (ctx->r1 == 0) {
        // 0x80092CB4: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80092D48;
    }
    // 0x80092CB4: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092CB8: beql        $at, $zero, L_80092D4C
    if (ctx->r1 == 0) {
        // 0x80092CBC: lh          $a1, 0x30($a0)
        ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
            goto L_80092D4C;
    }
    goto skip_2;
    // 0x80092CBC: lh          $a1, 0x30($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
    skip_2:
    // 0x80092CC0: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092CC4: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092CC8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80092CCC: b           L_80092D48
    // 0x80092CD0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_80092D48;
    // 0x80092CD0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80092CD4:
    // 0x80092CD4: bne         $a3, $t1, L_80092D14
    if (ctx->r7 != ctx->r9) {
        // 0x80092CD8: nop
    
            goto L_80092D14;
    }
    // 0x80092CD8: nop

    // 0x80092CDC: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092CE0: mflo        $t8
    ctx->r24 = lo;
    // 0x80092CE4: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80092CE8: lw          $t0, 0x0($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0X0));
    // 0x80092CEC: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092CF0: beq         $at, $zero, L_80092D48
    if (ctx->r1 == 0) {
        // 0x80092CF4: slt         $at, $t0, $v0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80092D48;
    }
    // 0x80092CF4: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80092CF8: beql        $at, $zero, L_80092D4C
    if (ctx->r1 == 0) {
        // 0x80092CFC: lh          $a1, 0x30($a0)
        ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
            goto L_80092D4C;
    }
    goto skip_3;
    // 0x80092CFC: lh          $a1, 0x30($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
    skip_3:
    // 0x80092D00: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092D04: sra         $t4, $v1, 16
    ctx->r12 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092D08: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80092D0C: b           L_80092D48
    // 0x80092D10: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_80092D48;
    // 0x80092D10: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_80092D14:
    // 0x80092D14: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092D18: mflo        $t5
    ctx->r13 = lo;
    // 0x80092D1C: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80092D20: lw          $t0, 0x0($t6)
    ctx->r8 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80092D24: slt         $at, $t0, $s1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80092D28: beq         $at, $zero, L_80092D48
    if (ctx->r1 == 0) {
        // 0x80092D2C: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80092D48;
    }
    // 0x80092D2C: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092D30: beql        $at, $zero, L_80092D4C
    if (ctx->r1 == 0) {
        // 0x80092D34: lh          $a1, 0x30($a0)
        ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
            goto L_80092D4C;
    }
    goto skip_4;
    // 0x80092D34: lh          $a1, 0x30($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
    skip_4:
    // 0x80092D38: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092D3C: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092D40: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80092D44: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80092D48:
    // 0x80092D48: lh          $a1, 0x30($a0)
    ctx->r5 = S32(MEM_H(ctx->r4, 0X30));
L_80092D4C:
    // 0x80092D4C: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x80092D50: bltz        $a1, L_80092E4C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80092D54: nop
    
            goto L_80092E4C;
    }
    // 0x80092D54: nop

    // 0x80092D58: bne         $s0, $t1, L_80092DD8
    if (ctx->r16 != ctx->r9) {
        // 0x80092D5C: nop
    
            goto L_80092DD8;
    }
    // 0x80092D5C: nop

    // 0x80092D60: bne         $a3, $t1, L_80092DA0
    if (ctx->r7 != ctx->r9) {
        // 0x80092D64: nop
    
            goto L_80092DA0;
    }
    // 0x80092D64: nop

    // 0x80092D68: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092D6C: mflo        $t8
    ctx->r24 = lo;
    // 0x80092D70: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80092D74: lw          $t0, 0x4($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0X4));
    // 0x80092D78: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092D7C: beq         $at, $zero, L_80092E4C
    if (ctx->r1 == 0) {
        // 0x80092D80: slt         $at, $t0, $v0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80092E4C;
    }
    // 0x80092D80: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80092D84: beq         $at, $zero, L_80092E4C
    if (ctx->r1 == 0) {
        // 0x80092D88: nop
    
            goto L_80092E4C;
    }
    // 0x80092D88: nop

    // 0x80092D8C: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092D90: sra         $t4, $v1, 16
    ctx->r12 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092D94: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80092D98: b           L_80092E4C
    // 0x80092D9C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80092E4C;
    // 0x80092D9C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80092DA0:
    // 0x80092DA0: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092DA4: mflo        $t5
    ctx->r13 = lo;
    // 0x80092DA8: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80092DAC: lw          $t0, 0x4($t6)
    ctx->r8 = S32(MEM_W(ctx->r14, 0X4));
    // 0x80092DB0: slt         $at, $t0, $s1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80092DB4: beq         $at, $zero, L_80092E4C
    if (ctx->r1 == 0) {
        // 0x80092DB8: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80092E4C;
    }
    // 0x80092DB8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092DBC: beq         $at, $zero, L_80092E4C
    if (ctx->r1 == 0) {
        // 0x80092DC0: nop
    
            goto L_80092E4C;
    }
    // 0x80092DC0: nop

    // 0x80092DC4: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092DC8: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092DCC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80092DD0: b           L_80092E4C
    // 0x80092DD4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80092E4C;
    // 0x80092DD4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80092DD8:
    // 0x80092DD8: bne         $a3, $t1, L_80092E18
    if (ctx->r7 != ctx->r9) {
        // 0x80092DDC: nop
    
            goto L_80092E18;
    }
    // 0x80092DDC: nop

    // 0x80092DE0: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092DE4: mflo        $t8
    ctx->r24 = lo;
    // 0x80092DE8: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80092DEC: lw          $t0, 0x0($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0X0));
    // 0x80092DF0: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092DF4: beq         $at, $zero, L_80092E4C
    if (ctx->r1 == 0) {
        // 0x80092DF8: slt         $at, $t0, $v0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80092E4C;
    }
    // 0x80092DF8: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80092DFC: beq         $at, $zero, L_80092E4C
    if (ctx->r1 == 0) {
        // 0x80092E00: nop
    
            goto L_80092E4C;
    }
    // 0x80092E00: nop

    // 0x80092E04: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092E08: sra         $t4, $v1, 16
    ctx->r12 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092E0C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80092E10: b           L_80092E4C
    // 0x80092E14: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80092E4C;
    // 0x80092E14: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80092E18:
    // 0x80092E18: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092E1C: mflo        $t5
    ctx->r13 = lo;
    // 0x80092E20: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80092E24: lw          $t0, 0x0($t6)
    ctx->r8 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80092E28: slt         $at, $t0, $s1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80092E2C: beq         $at, $zero, L_80092E4C
    if (ctx->r1 == 0) {
        // 0x80092E30: slt         $at, $v0, $t0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80092E4C;
    }
    // 0x80092E30: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80092E34: beq         $at, $zero, L_80092E4C
    if (ctx->r1 == 0) {
        // 0x80092E38: nop
    
            goto L_80092E4C;
    }
    // 0x80092E38: nop

    // 0x80092E3C: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80092E40: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80092E44: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80092E48: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80092E4C:
    // 0x80092E4C: bne         $a2, $zero, L_80092C44
    if (ctx->r6 != 0) {
        // 0x80092E50: addiu       $a0, $a0, 0x24
        ctx->r4 = ADD32(ctx->r4, 0X24);
            goto L_80092C44;
    }
    // 0x80092E50: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
L_80092E54:
    // 0x80092E54: lw          $s0, 0x8($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X8));
    // 0x80092E58: lw          $s1, 0xC($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0XC));
    // 0x80092E5C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80092E60: jr          $ra
    // 0x80092E64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80092E64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void dmulscale7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090484: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009048C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090490: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090494: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090498: jal         0x800BB8F8
    // 0x8009049C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009049C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800904A0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800904A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800904A8: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800904AC: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800904B0: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800904B4: jal         0x800BB8F8
    // 0x800904B8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800904B8: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x800904BC: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800904C0: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800904C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800904C8: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x800904CC: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800904D0: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x800904D4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800904D8: jal         0x800BBA24
    // 0x800904DC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x800904DC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_2:
    // 0x800904E0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800904E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800904E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800904EC: jr          $ra
    // 0x800904F0: nop

    return;
    // 0x800904F0: nop

;}
RECOMP_FUNC void dmulscale13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090724: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80090728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009072C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80090730: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80090734: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80090738: jal         0x800BB8F8
    // 0x8009073C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8009073C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090740: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80090744: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80090748: lw          $a0, 0x30($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8009074C: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80090750: lw          $a2, 0x38($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80090754: jal         0x800BB8F8
    // 0x80090758: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80090758: lw          $a3, 0x3C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X3C));
    after_1:
    // 0x8009075C: lw          $t7, 0x1C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80090760: lw          $t6, 0x18($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80090764: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090768: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x8009076C: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80090770: addu        $a0, $at, $t6
    ctx->r4 = ADD32(ctx->r1, ctx->r14);
    // 0x80090774: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80090778: jal         0x800BBA24
    // 0x8009077C: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    __ll_rshift_recomp(rdram, ctx);
        goto after_2;
    // 0x8009077C: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    after_2:
    // 0x80090780: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090788: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009078C: jr          $ra
    // 0x80090790: nop

    return;
    // 0x80090790: nop

;}
