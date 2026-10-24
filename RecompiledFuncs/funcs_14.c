#include "recomp.h"
#include "funcs.h"
extern void ultramodern_complete_sp_task(uint8_t* rdram);

RECOMP_FUNC void func_8006789C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006789C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800678A0: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x800678A4: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x800678A8: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800678AC: addiu       $a3, $a3, 0x61A8
    ctx->r7 = ADD32(ctx->r7, 0X61A8);
    // 0x800678B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800678B4: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x800678B8: lbu         $t2, 0x1E($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1E);
    // 0x800678BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800678C0: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800678C4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800678C8: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800678CC: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x800678D0: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x800678D4: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800678D8: addiu       $t1, $t1, -0x1418
    ctx->r9 = ADD32(ctx->r9, -0X1418);
    // 0x800678DC: addiu       $t0, $t0, -0x1414
    ctx->r8 = ADD32(ctx->r8, -0X1414);
    // 0x800678E0: addiu       $a2, $a2, -0x141C
    ctx->r6 = ADD32(ctx->r6, -0X141C);
    // 0x800678E4: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800678E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800678EC: lwc1        $f0, -0x145C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X145C));
    // 0x800678F0: bgez        $t2, L_80067908
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800678F4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80067908;
    }
    // 0x800678F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800678F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800678FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80067900: nop

    // 0x80067904: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80067908:
    // 0x80067908: div.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006790C: lh          $t3, 0xA($v0)
    ctx->r11 = S32(MEM_H(ctx->r2, 0XA));
    // 0x80067910: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067914: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80067918: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006791C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80067920: addu        $v1, $a3, $t4
    ctx->r3 = ADD32(ctx->r7, ctx->r12);
    // 0x80067924: lbu         $t5, 0x20($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X20);
    // 0x80067928: andi        $t4, $a1, 0x4
    ctx->r12 = ctx->r5 & 0X4;
    // 0x8006792C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80067930: nop

    // 0x80067934: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067938: bgez        $t5, L_8006794C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8006793C: swc1        $f10, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
            goto L_8006794C;
    }
    // 0x8006793C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80067940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067944: nop

    // 0x80067948: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8006794C:
    // 0x8006794C: div.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067950: lbu         $t6, 0x1F($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1F);
    // 0x80067954: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067958: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8006795C: nop

    // 0x80067960: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067964: bgez        $t6, L_80067978
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067968: swc1        $f8, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
            goto L_80067978;
    }
    // 0x80067968: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x8006796C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80067970: nop

    // 0x80067974: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80067978:
    // 0x80067978: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006797C: lwc1        $f4, -0x1458($at)
    ctx->f4.u32l = S32(MEM_W(ctx->r1, -0X1458));
    // 0x80067980: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067984: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80067988: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8006798C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80067990: andi        $t7, $a1, 0x100
    ctx->r15 = ctx->r5 & 0X100;
    // 0x80067994: div.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80067998: bne         $t7, $at, L_800679E4
    if (ctx->r15 != ctx->r1) {
        // 0x8006799C: swc1        $f6, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
            goto L_800679E4;
    }
    // 0x8006799C: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x800679A0: lbu         $t8, 0x21($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X21);
    // 0x800679A4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800679A8: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800679AC: subu        $t2, $t9, $t8
    ctx->r10 = SUB32(ctx->r25, ctx->r24);
    // 0x800679B0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800679B4: addiu       $v0, $v0, -0x1410
    ctx->r2 = ADD32(ctx->r2, -0X1410);
    // 0x800679B8: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800679BC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800679C0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800679C4: lwc1        $f0, -0x1448($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X1448));
    // 0x800679C8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800679CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800679D0: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = S32(MEM_W(ctx->r2, 0X0));
    // 0x800679D4: div.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800679D8: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800679DC: b           L_80067A3C
    // 0x800679E0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_80067A3C;
    // 0x800679E0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_800679E4:
    // 0x800679E4: lbu         $t3, 0x21($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X21);
    // 0x800679E8: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800679EC: addiu       $v0, $v0, -0x1410
    ctx->r2 = ADD32(ctx->r2, -0X1410);
    // 0x800679F0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800679F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800679F8: bgez        $t3, L_80067A0C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800679FC: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80067A0C;
    }
    // 0x800679FC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067A00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067A04: nop

    // 0x80067A08: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80067A0C:
    // 0x80067A0C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80067A10: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80067A14: lwc1        $f0, -0x1448($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X1448));
    // 0x80067A18: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80067A1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80067A20: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = S32(MEM_W(ctx->r2, 0X0));
    // 0x80067A24: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = S32(MEM_W(ctx->r9, 0X0));
    // 0x80067A28: div.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80067A2C: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x80067A30: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80067A34: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80067A38: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_80067A3C:
    // 0x80067A3C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = S32(MEM_W(ctx->r2, 0X0));
    // 0x80067A40: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x80067A44: addiu       $v1, $v1, -0x1420
    ctx->r3 = ADD32(ctx->r3, -0X1420);
    // 0x80067A48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80067A4C: bne         $t4, $at, L_80067A78
    if (ctx->r12 != ctx->r1) {
        // 0x80067A50: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80067A78;
    }
    // 0x80067A50: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x80067A54: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80067A58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80067A5C: nop

    // 0x80067A60: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80067A64: nop

    // 0x80067A68: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80067A6C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80067A70: b           L_80067A8C
    // 0x80067A74: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
        goto L_80067A8C;
    // 0x80067A74: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_80067A78:
    // 0x80067A78: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80067A7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80067A80: nop

    // 0x80067A84: mul.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80067A88: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_80067A8C:
    // 0x80067A8C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = S32(MEM_W(ctx->r8, 0X0));
    // 0x80067A90: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80067A94: mul.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80067A98: swc1        $f0, -0x1444($at)
    MEM_W(-0X1444, ctx->r1) = ctx->f0.u32l;
    // 0x80067A9C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80067AA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80067AA4: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = S32(MEM_W(ctx->r6, 0X0));
    // 0x80067AA8: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80067AAC: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80067AB0: nop

    // 0x80067AB4: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80067AB8: add.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80067ABC: jr          $ra
    // 0x80067AC0: swc1        $f16, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x80067AC0: swc1        $f16, -0x1440($at)
    MEM_W(-0X1440, ctx->r1) = ctx->f16.u32l;
;}
RECOMP_FUNC void _memset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A51C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005A520: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8005A524: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8005A528: beq         $a2, $zero, L_8005A540
    if (ctx->r6 == 0) {
        // 0x8005A52C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8005A540;
    }
    // 0x8005A52C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8005A530:
    // 0x8005A530: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8005A534: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8005A538: bne         $a2, $zero, L_8005A530
    if (ctx->r6 != 0) {
        // 0x8005A53C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8005A530;
    }
    // 0x8005A53C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8005A540:
    // 0x8005A540: jr          $ra
    // 0x8005A544: nop

    return;
    // 0x8005A544: nop

;}
RECOMP_FUNC void guTranslate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD8C8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800BD8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD8D0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800BD8D4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800BD8D8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800BD8DC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800BD8E0: jal         0x800C8BC0
    // 0x800BD8E4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800BD8E4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800BD8E8: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X6C));
    // 0x800BD8EC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X70));
    // 0x800BD8F0: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X74));
    // 0x800BD8F4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800BD8F8: lw          $a1, 0x68($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800BD8FC: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800BD900: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800BD904: jal         0x800C8AC0
    // 0x800BD908: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800BD908: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800BD90C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800BD910: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800BD914: jr          $ra
    // 0x800BD918: nop

    return;
    // 0x800BD918: nop

;}
RECOMP_FUNC void alSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFFC8: jr          $ra
    // 0x800CFFCC: lw          $v0, 0xC($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0XC));
    return;
    // 0x800CFFCC: lw          $v0, 0xC($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0XC));
;}
RECOMP_FUNC void rendertileworld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF8C: addiu       $sp, $sp, -0x1C8
    ctx->r29 = ADD32(ctx->r29, -0X1C8);
    // 0x8006CF90: lh          $a1, 0x1DE($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X1DE));
    // 0x8006CF94: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8006CF98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8006CF9C: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8006CFA0: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x8006CFA4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8006CFA8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8006CFAC: andi        $t6, $a1, 0x4
    ctx->r14 = ctx->r5 & 0X4;
    // 0x8006CFB0: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8006CFB4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8006CFB8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8006CFBC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8006CFC0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8006CFC4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8006CFC8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8006CFCC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8006CFD0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8006CFD4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8006CFD8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8006CFDC: swc1        $f14, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->f14.u32l;
    // 0x8006CFE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006CFE4: beq         $t6, $zero, L_8006CFF0
    if (ctx->r14 == 0) {
        // 0x8006CFE8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8006CFF0;
    }
    // 0x8006CFE8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8006CFEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8006CFF0:
    // 0x8006CFF0: andi        $t7, $a1, 0x8
    ctx->r15 = ctx->r5 & 0X8;
    // 0x8006CFF4: beq         $t7, $zero, L_8006D000
    if (ctx->r15 == 0) {
        // 0x8006CFF8: lhu         $s4, 0x1DA($sp)
        ctx->r20 = MEM_HU(ctx->r29, 0X1DA);
            goto L_8006D000;
    }
    // 0x8006CFF8: lhu         $s4, 0x1DA($sp)
    ctx->r20 = MEM_HU(ctx->r29, 0X1DA);
    // 0x8006CFFC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8006D000:
    // 0x8006D000: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8006D004: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8006D008: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006D00C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006D010: sll         $t8, $s4, 3
    ctx->r24 = S32(ctx->r20 << 3);
    // 0x8006D014: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x8006D018: mul.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8006D01C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006D020: addiu       $t9, $t9, -0x5010
    ctx->r25 = ADD32(ctx->r25, -0X5010);
    // 0x8006D024: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006D028: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x8006D02C: mul.s       $f22, $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8006D030: lw          $t6, 0x8($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X8));
    // 0x8006D034: lui         $at, 0x8026
    ctx->r1 = S32(0X8026 << 16);
    // 0x8006D038: lwc1        $f0, -0x3C80($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X3C80));
    // 0x8006D03C: andi        $t7, $t6, 0xFF00
    ctx->r15 = ctx->r14 & 0XFF00;
    // 0x8006D040: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x8006D044: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8006D048: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8006D04C: sra         $t6, $t9, 24
    ctx->r14 = S32(SIGNED(ctx->r25) >> 24);
    // 0x8006D050: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8006D054: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8006D058: lwc1        $f4, 0x1CC($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X1CC));
    // 0x8006D05C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8006D060: mul.s       $f24, $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x8006D064: nop

    // 0x8006D068: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006D06C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006D070: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006D074: swc1        $f6, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->f6.u32l;
    // 0x8006D078: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8006D07C: beq         $a0, $zero, L_8006D088
    if (ctx->r4 == 0) {
        // 0x8006D080: div.s       $f2, $f10, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
            goto L_8006D088;
    }
    // 0x8006D080: div.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8006D084: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8006D088:
    // 0x8006D088: lh          $t7, 0xC($s2)
    ctx->r15 = S32(MEM_H(ctx->r18, 0XC));
    // 0x8006D08C: lh          $t8, 0xE($s2)
    ctx->r24 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8006D090: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006D094: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8006D098: nop

    // 0x8006D09C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006D0A0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8006D0A4: sub.s       $f24, $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x8006D0A8: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8006D0AC: swc1        $f24, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->f24.u32l;
    // 0x8006D0B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006D0B4: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006D0B8: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8006D0BC: div.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006D0C0: swc1        $f6, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f6.u32l;
    // 0x8006D0C4: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8006D0C8: nop

    // 0x8006D0CC: bc1f        L_8006D0E4
    if (!c1cs) {
        // 0x8006D0D0: swc1        $f8, 0x178($sp)
        MEM_W(0X178, ctx->r29) = ctx->f8.u32l;
            goto L_8006D0E4;
    }
    // 0x8006D0D0: swc1        $f8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f8.u32l;
    // 0x8006D0D4: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8006D0D8: swc1        $f24, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->f24.u32l;
    // 0x8006D0DC: bc1tl       L_8006E228
    if (c1cs) {
        // 0x8006D0E0: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_8006E228;
    }
    goto skip_0;
    // 0x8006D0E0: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_0:
L_8006D0E4:
    // 0x8006D0E4: lhu         $v0, 0x12($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X12);
    // 0x8006D0E8: lwc1        $f16, 0x1C8($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X1C8));
    // 0x8006D0EC: lwc1        $f20, 0x17C($sp)
    ctx->f20.u32l = S32(MEM_W(ctx->r29, 0X17C));
    // 0x8006D0F0: sll         $t9, $v0, 12
    ctx->r25 = S32(ctx->r2 << 12);
    // 0x8006D0F4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8006D0F8: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x8006D0FC: lhu         $v1, 0x14($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X14);
    // 0x8006D100: lwc1        $f24, 0x1CC($sp)
    ctx->f24.u32l = S32(MEM_W(ctx->r29, 0X1CC));
    // 0x8006D104: add.s       $f12, $f16, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8006D108: lwc1        $f26, 0x178($sp)
    ctx->f26.u32l = S32(MEM_W(ctx->r29, 0X178));
    // 0x8006D10C: sll         $t6, $v1, 12
    ctx->r14 = S32(ctx->r3 << 12);
    // 0x8006D110: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006D114: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006D118: swc1        $f0, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->f0.u32l;
    // 0x8006D11C: swc1        $f12, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->f12.u32l;
    // 0x8006D120: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006D124: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8006D128: sub.s       $f2, $f24, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x8006D12C: add.s       $f14, $f24, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = ctx->f24.fl + ctx->f26.fl;
    // 0x8006D130: swc1        $f2, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->f2.u32l;
    // 0x8006D134: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006D138: swc1        $f14, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->f14.u32l;
    // 0x8006D13C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006D140: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8006D144: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006D148: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8006D14C: swc1        $f8, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->f8.u32l;
    // 0x8006D150: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006D154: bgez        $v0, L_8006D168
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D158: swc1        $f10, 0x1B0($sp)
        MEM_W(0X1B0, ctx->r29) = ctx->f10.u32l;
            goto L_8006D168;
    }
    // 0x8006D158: swc1        $f10, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->f10.u32l;
    // 0x8006D15C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006D160: nop

    // 0x8006D164: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_8006D168:
    // 0x8006D168: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8006D16C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006D170: bgez        $v1, L_8006D184
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006D174: cvt.s.w     $f26, $f10
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    ctx->f26.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8006D184;
    }
    // 0x8006D174: cvt.s.w     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    ctx->f26.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006D178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006D17C: nop

    // 0x8006D180: add.s       $f26, $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f4.fl;
L_8006D184:
    // 0x8006D184: beq         $a0, $zero, L_8006D1BC
    if (ctx->r4 == 0) {
        // 0x8006D188: swc1        $f20, 0x17C($sp)
        MEM_W(0X17C, ctx->r29) = ctx->f20.u32l;
            goto L_8006D1BC;
    }
    // 0x8006D188: swc1        $f20, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f20.u32l;
    // 0x8006D18C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006D190: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006D194: lwc1        $f10, 0x17C($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X17C));
    // 0x8006D198: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8006D19C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8006D1A0: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8006D1A4: swc1        $f6, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->f6.u32l;
    // 0x8006D1A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006D1AC: nop

    // 0x8006D1B0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8006D1B4: b           L_8006D1C8
    // 0x8006D1B8: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
        goto L_8006D1C8;
    // 0x8006D1B8: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
L_8006D1BC:
    // 0x8006D1BC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8006D1C0: nop

    // 0x8006D1C4: swc1        $f12, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f12.u32l;
L_8006D1C8:
    // 0x8006D1C8: beq         $s3, $zero, L_8006D1D8
    if (ctx->r19 == 0) {
        // 0x8006D1CC: lwc1        $f4, 0x1B0($sp)
        ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X1B0));
            goto L_8006D1D8;
    }
    // 0x8006D1CC: lwc1        $f4, 0x1B0($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x8006D1D0: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8006D1D4: swc1        $f8, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->f8.u32l;
L_8006D1D8:
    // 0x8006D1D8: jal         0x80063880
    // 0x8006D1DC: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    func_80063880(rdram, ctx);
        goto after_0;
    // 0x8006D1DC: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    after_0:
    // 0x8006D1E0: lhu         $t7, 0x14($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X14);
    // 0x8006D1E4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8006D1E8: addiu       $a3, $a3, 0x4418
    ctx->r7 = ADD32(ctx->r7, 0X4418);
    // 0x8006D1EC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8006D1F0: addiu       $s0, $v0, 0x20
    ctx->r16 = ADD32(ctx->r2, 0X20);
    // 0x8006D1F4: bgez        $t7, L_8006D20C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006D1F8: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8006D20C;
    }
    // 0x8006D1F8: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006D1FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006D200: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006D204: nop

    // 0x8006D208: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8006D20C:
    // 0x8006D20C: lh          $t8, 0xE($s2)
    ctx->r24 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8006D210: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8006D214: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006D218: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8006D21C: lw          $s1, 0x0($a3)
    ctx->r17 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D220: lwc1        $f20, 0x1C0($sp)
    ctx->f20.u32l = S32(MEM_W(ctx->r29, 0X1C0));
    // 0x8006D224: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006D228: addiu       $t9, $s1, 0x8
    ctx->r25 = ADD32(ctx->r17, 0X8);
    // 0x8006D22C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D230: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8006D234: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8006D238: swc1        $f16, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->f16.u32l;
    // 0x8006D23C: mul.s       $f6, $f8, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8006D240: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    // 0x8006D244: div.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8006D248: jal         0x80063880
    // 0x8006D24C: swc1        $f2, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->f2.u32l;
    func_80063880(rdram, ctx);
        goto after_1;
    // 0x8006D24C: swc1        $f2, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8006D250: lwc1        $f2, 0x190($sp)
    ctx->f2.u32l = S32(MEM_W(ctx->r29, 0X190));
    // 0x8006D254: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8006D258: lwc1        $f16, 0x19C($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X19C));
    // 0x8006D25C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8006D260: addiu       $a3, $a3, 0x4418
    ctx->r7 = ADD32(ctx->r7, 0X4418);
    // 0x8006D264: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D268: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8006D26C: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8006D270: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006D274: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006D278: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006D27C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006D280: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D284: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8006D288: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8006D28C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006D290: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D294: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006D298: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006D29C: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D2A0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8006D2A4: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8006D2A8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006D2AC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8006D2B0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006D2B4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006D2B8: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D2BC: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x8006D2C0: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8006D2C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006D2C8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006D2CC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006D2D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006D2D4: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D2D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006D2DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006D2E0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006D2E4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D2E8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8006D2EC: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x8006D2F0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006D2F4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006D2F8: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X17C));
    // 0x8006D2FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006D300: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8006D304: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006D308: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006D30C: lui         $fp, 0xF300
    ctx->r30 = S32(0XF300 << 16);
    // 0x8006D310: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006D314: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8006D318: mul.s       $f10, $f26, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f18.fl);
    // 0x8006D31C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8006D320: nop

    // 0x8006D324: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006D328: div.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006D32C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8006D330: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006D334: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8006D338: nop

    // 0x8006D33C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8006D340: bne         $t7, $zero, L_8006D354
    if (ctx->r15 != 0) {
        // 0x8006D344: nop
    
            goto L_8006D354;
    }
    // 0x8006D344: nop

    // 0x8006D348: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006D34C: nop

    // 0x8006D350: sub.s       $f22, $f0, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f0.fl - ctx->f6.fl;
L_8006D354:
    // 0x8006D354: mul.s       $f22, $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8006D358: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8006D35C: sw          $s2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r18;
    // 0x8006D360: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006D364: beql        $s3, $zero, L_8006DAD8
    if (ctx->r19 == 0) {
        // 0x8006D368: div.s       $f24, $f2, $f26
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = DIV_S(ctx->f2.fl, ctx->f26.fl);
            goto L_8006DAD8;
    }
    goto skip_1;
    // 0x8006D368: div.s       $f24, $f2, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = DIV_S(ctx->f2.fl, ctx->f26.fl);
    skip_1:
    // 0x8006D36C: div.s       $f24, $f2, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = DIV_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8006D370: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X17C));
    // 0x8006D374: lwc1        $f14, 0x1BC($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x8006D378: lwc1        $f10, 0x1B4($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X1B4));
    // 0x8006D37C: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006D380: lwc1        $f8, 0x1C4($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X1C4));
    // 0x8006D384: lwc1        $f20, 0x1B8($sp)
    ctx->f20.u32l = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x8006D388: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8006D38C: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x8006D390: lui         $s7, 0x708
    ctx->r23 = S32(0X708 << 16);
    // 0x8006D394: ori         $s7, $s7, 0x200
    ctx->r23 = ctx->r23 | 0X200;
    // 0x8006D398: mfc1        $s6, $f4
    ctx->r22 = (int32_t)ctx->f4.u32l;
    // 0x8006D39C: sra         $s4, $s2, 1
    ctx->r20 = S32(SIGNED(ctx->r18) >> 1);
    // 0x8006D3A0: bgez        $s2, L_8006D3B0
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8006D3A4: sra         $t5, $s2, 4
        ctx->r13 = S32(SIGNED(ctx->r18) >> 4);
            goto L_8006D3B0;
    }
    // 0x8006D3A4: sra         $t5, $s2, 4
    ctx->r13 = S32(SIGNED(ctx->r18) >> 4);
    // 0x8006D3A8: addiu       $at, $s2, 0xF
    ctx->r1 = ADD32(ctx->r18, 0XF);
    // 0x8006D3AC: sra         $t5, $at, 4
    ctx->r13 = S32(SIGNED(ctx->r1) >> 4);
L_8006D3B0:
    // 0x8006D3B0: addiu       $s4, $s4, 0x7
    ctx->r20 = ADD32(ctx->r20, 0X7);
    // 0x8006D3B4: sra         $t9, $s4, 3
    ctx->r25 = S32(SIGNED(ctx->r20) >> 3);
    // 0x8006D3B8: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006D3BC: lwc1        $f8, 0x1B0($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x8006D3C0: addiu       $s5, $s2, -0x1
    ctx->r21 = ADD32(ctx->r18, -0X1);
    // 0x8006D3C4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006D3C8: mfc1        $ra, $f6
    ctx->r31 = (int32_t)ctx->f6.u32l;
    // 0x8006D3CC: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x8006D3D0: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006D3D4: mfc1        $s3, $f4
    ctx->r19 = (int32_t)ctx->f4.u32l;
    // 0x8006D3D8: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8006D3DC: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8006D3E0: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x8006D3E4: sll         $s4, $t6, 9
    ctx->r20 = S32(ctx->r14 << 9);
    // 0x8006D3E8: sll         $s5, $t9, 12
    ctx->r21 = S32(ctx->r25 << 12);
    // 0x8006D3EC: sll         $t8, $s6, 16
    ctx->r24 = S32(ctx->r22 << 16);
    // 0x8006D3F0: sra         $s6, $t8, 16
    ctx->r22 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006D3F4: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8006D3F8: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8006D3FC: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006D400: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006D404: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8006D408: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x8006D40C: sll         $t7, $ra, 16
    ctx->r15 = S32(ctx->r31 << 16);
    // 0x8006D410: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8006D414: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8006D418: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8006D41C: sra         $ra, $t7, 16
    ctx->r31 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8006D420: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
L_8006D424:
    // 0x8006D424: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
    // 0x8006D428: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8006D42C: trunc.w.s   $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8006D430: bc1fl       L_8006D444
    if (!c1cs) {
        // 0x8006D434: mov.s       $f2, $f22
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
            goto L_8006D444;
    }
    goto skip_2;
    // 0x8006D434: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    skip_2:
    // 0x8006D438: b           L_8006D444
    // 0x8006D43C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
        goto L_8006D444;
    // 0x8006D43C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8006D440: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
L_8006D444:
    // 0x8006D444: sub.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8006D448: lb          $t7, -0x13CF($t7)
    ctx->r15 = S32(MEM_B(ctx->r15, -0X13CF));
    // 0x8006D44C: sub.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8006D450: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8006D454: beql        $t7, $zero, L_8006D5E0
    if (ctx->r15 == 0) {
        // 0x8006D458: div.s       $f14, $f2, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
            goto L_8006D5E0;
    }
    goto skip_3;
    // 0x8006D458: div.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    skip_3:
    // 0x8006D45C: div.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8006D460: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D464: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8006D468: lui         $t7, 0xF590
    ctx->r15 = S32(0XF590 << 16);
    // 0x8006D46C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006D470: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8006D474: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006D478: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8006D47C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006D480: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D484: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8006D488: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8006D48C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006D490: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006D494: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006D498: sw          $s7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r23;
    // 0x8006D49C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006D4A0: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D4A4: or          $t4, $s4, $at
    ctx->r12 = ctx->r20 | ctx->r1;
    // 0x8006D4A8: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8006D4AC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006D4B0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8006D4B4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006D4B8: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8006D4BC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006D4C0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8006D4C4: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D4C8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8006D4CC: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8006D4D0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006D4D4: multu       $s2, $t2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D4D8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006D4DC: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x8006D4E0: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8006D4E4: mflo        $v0
    ctx->r2 = lo;
    // 0x8006D4E8: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006D4EC: sra         $t8, $v0, 2
    ctx->r24 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8006D4F0: addiu       $v0, $t8, -0x1
    ctx->r2 = ADD32(ctx->r24, -0X1);
    // 0x8006D4F4: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8006D4F8: beq         $at, $zero, L_8006D508
    if (ctx->r1 == 0) {
        // 0x8006D4FC: nop
    
            goto L_8006D508;
    }
    // 0x8006D4FC: nop

    // 0x8006D500: b           L_8006D508
    // 0x8006D504: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
        goto L_8006D508;
    // 0x8006D504: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8006D508:
    // 0x8006D508: bgtz        $t5, L_8006D518
    if (SIGNED(ctx->r13) > 0) {
        // 0x8006D50C: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8006D518;
    }
    // 0x8006D50C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006D510: b           L_8006D518
    // 0x8006D514: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8006D518;
    // 0x8006D514: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8006D518:
    // 0x8006D518: bgtz        $t5, L_8006D528
    if (SIGNED(ctx->r13) > 0) {
        // 0x8006D51C: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8006D528;
    }
    // 0x8006D51C: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8006D520: b           L_8006D528
    // 0x8006D524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006D528;
    // 0x8006D524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006D528:
    // 0x8006D528: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x8006D52C: bne         $v0, $zero, L_8006D538
    if (ctx->r2 != 0) {
        // 0x8006D530: nop
    
            goto L_8006D538;
    }
    // 0x8006D530: nop

    // 0x8006D534: break       7
    do_break(2147931444);
L_8006D538:
    // 0x8006D538: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D53C: bne         $v0, $at, L_8006D550
    if (ctx->r2 != ctx->r1) {
        // 0x8006D540: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006D550;
    }
    // 0x8006D540: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006D544: bne         $t9, $at, L_8006D550
    if (ctx->r25 != ctx->r1) {
        // 0x8006D548: nop
    
            goto L_8006D550;
    }
    // 0x8006D548: nop

    // 0x8006D54C: break       6
    do_break(2147931468);
L_8006D550:
    // 0x8006D550: mflo        $t6
    ctx->r14 = lo;
    // 0x8006D554: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8006D558: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8006D55C: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x8006D560: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8006D564: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8006D568: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8006D56C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8006D570: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D574: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8006D578: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8006D57C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006D580: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D584: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006D588: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006D58C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006D590: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D594: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8006D598: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8006D59C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006D5A0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006D5A4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006D5A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006D5AC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006D5B0: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D5B4: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8006D5B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006D5BC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006D5C0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D5C4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8006D5C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006D5CC: or          $t8, $s5, $t9
    ctx->r24 = ctx->r21 | ctx->r25;
    // 0x8006D5D0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006D5D4: b           L_8006D758
    // 0x8006D5D8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_8006D758;
    // 0x8006D5D8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8006D5DC: div.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
L_8006D5E0:
    // 0x8006D5E0: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D5E4: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x8006D5E8: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8006D5EC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006D5F0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006D5F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006D5F8: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8006D5FC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006D600: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D604: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8006D608: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8006D60C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006D610: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D614: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006D618: sw          $s7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r23;
    // 0x8006D61C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006D620: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D624: or          $t4, $s4, $at
    ctx->r12 = ctx->r20 | ctx->r1;
    // 0x8006D628: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8006D62C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006D630: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006D634: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006D638: trunc.w.s   $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8006D63C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006D640: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8006D644: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D648: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8006D64C: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8006D650: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006D654: multu       $s2, $t2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D658: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D65C: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x8006D660: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8006D664: mflo        $v0
    ctx->r2 = lo;
    // 0x8006D668: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006D66C: sra         $t6, $v0, 2
    ctx->r14 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8006D670: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x8006D674: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8006D678: beq         $at, $zero, L_8006D688
    if (ctx->r1 == 0) {
        // 0x8006D67C: nop
    
            goto L_8006D688;
    }
    // 0x8006D67C: nop

    // 0x8006D680: b           L_8006D688
    // 0x8006D684: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
        goto L_8006D688;
    // 0x8006D684: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8006D688:
    // 0x8006D688: bgtz        $t5, L_8006D698
    if (SIGNED(ctx->r13) > 0) {
        // 0x8006D68C: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8006D698;
    }
    // 0x8006D68C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006D690: b           L_8006D698
    // 0x8006D694: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8006D698;
    // 0x8006D694: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8006D698:
    // 0x8006D698: bgtz        $t5, L_8006D6A8
    if (SIGNED(ctx->r13) > 0) {
        // 0x8006D69C: addiu       $t7, $t0, 0x7FF
        ctx->r15 = ADD32(ctx->r8, 0X7FF);
            goto L_8006D6A8;
    }
    // 0x8006D69C: addiu       $t7, $t0, 0x7FF
    ctx->r15 = ADD32(ctx->r8, 0X7FF);
    // 0x8006D6A0: b           L_8006D6A8
    // 0x8006D6A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006D6A8;
    // 0x8006D6A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006D6A8:
    // 0x8006D6A8: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x8006D6AC: bne         $v0, $zero, L_8006D6B8
    if (ctx->r2 != 0) {
        // 0x8006D6B0: nop
    
            goto L_8006D6B8;
    }
    // 0x8006D6B0: nop

    // 0x8006D6B4: break       7
    do_break(2147931828);
L_8006D6B8:
    // 0x8006D6B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006D6BC: bne         $v0, $at, L_8006D6D0
    if (ctx->r2 != ctx->r1) {
        // 0x8006D6C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006D6D0;
    }
    // 0x8006D6C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006D6C4: bne         $t7, $at, L_8006D6D0
    if (ctx->r15 != ctx->r1) {
        // 0x8006D6C8: nop
    
            goto L_8006D6D0;
    }
    // 0x8006D6C8: nop

    // 0x8006D6CC: break       6
    do_break(2147931852);
L_8006D6D0:
    // 0x8006D6D0: mflo        $t9
    ctx->r25 = lo;
    // 0x8006D6D4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8006D6D8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8006D6DC: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x8006D6E0: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8006D6E4: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8006D6E8: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8006D6EC: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8006D6F0: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D6F4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8006D6F8: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8006D6FC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006D700: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006D704: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006D708: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006D70C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006D710: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D714: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8006D718: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8006D71C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006D720: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D724: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006D728: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006D72C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006D730: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D734: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x8006D738: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8006D73C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006D740: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006D744: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8006D748: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006D74C: or          $t6, $s5, $t7
    ctx->r14 = ctx->r21 | ctx->r15;
    // 0x8006D750: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006D754: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8006D758:
    // 0x8006D758: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D75C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8006D760: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8006D764: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x8006D768: blez        $s6, L_8006D778
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8006D76C: sw          $t9, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r25;
            goto L_8006D778;
    }
    // 0x8006D76C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006D770: b           L_8006D77C
    // 0x8006D774: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
        goto L_8006D77C;
    // 0x8006D774: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
L_8006D778:
    // 0x8006D778: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8006D77C:
    // 0x8006D77C: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8006D780: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8006D784: blez        $t6, L_8006D794
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006D788: andi        $t7, $t0, 0xFFF
        ctx->r15 = ctx->r8 & 0XFFF;
            goto L_8006D794;
    }
    // 0x8006D788: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x8006D78C: b           L_8006D798
    // 0x8006D790: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D798;
    // 0x8006D790: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8006D794:
    // 0x8006D794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006D798:
    // 0x8006D798: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x8006D79C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8006D7A0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8006D7A4: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8006D7A8: blez        $ra, L_8006D7B8
    if (SIGNED(ctx->r31) <= 0) {
        // 0x8006D7AC: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_8006D7B8;
    }
    // 0x8006D7AC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8006D7B0: b           L_8006D7BC
    // 0x8006D7B4: or          $t0, $ra, $zero
    ctx->r8 = ctx->r31 | 0;
        goto L_8006D7BC;
    // 0x8006D7B4: or          $t0, $ra, $zero
    ctx->r8 = ctx->r31 | 0;
L_8006D7B8:
    // 0x8006D7B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8006D7BC:
    // 0x8006D7BC: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8006D7C0: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x8006D7C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006D7C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8006D7CC: sub.s       $f0, $f4, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8006D7D0: sub.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8006D7D4: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8006D7D8: mul.s       $f6, $f12, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x8006D7DC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8006D7E0: nop

    // 0x8006D7E4: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8006D7E8: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006D7EC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8006D7F0: blez        $t6, L_8006D800
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006D7F4: trunc.w.s   $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
            goto L_8006D800;
    }
    // 0x8006D7F4: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006D7F8: b           L_8006D800
    // 0x8006D7FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D800;
    // 0x8006D7FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8006D800:
    // 0x8006D800: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x8006D804: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8006D808: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8006D80C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8006D810: lw          $a2, 0x0($a3)
    ctx->r6 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006D814: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8006D818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006D81C: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x8006D820: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006D824: bgez        $ra, L_8006D874
    if (SIGNED(ctx->r31) >= 0) {
        // 0x8006D828: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8006D874;
    }
    // 0x8006D828: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8006D82C: multu       $ra, $s3
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D830: mflo        $v0
    ctx->r2 = lo;
    // 0x8006D834: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006D838: bgez        $s3, L_8006D858
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8006D83C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8006D858;
    }
    // 0x8006D83C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006D840: blez        $t8, L_8006D850
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8006D844: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006D850;
    }
    // 0x8006D844: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D848: b           L_8006D874
    // 0x8006D84C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_8006D874;
    // 0x8006D84C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_8006D850:
    // 0x8006D850: b           L_8006D874
    // 0x8006D854: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8006D874;
    // 0x8006D854: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8006D858:
    // 0x8006D858: bgez        $v0, L_8006D868
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006D85C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006D868;
    }
    // 0x8006D85C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D860: b           L_8006D868
    // 0x8006D864: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8006D868;
    // 0x8006D864: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8006D868:
    // 0x8006D868: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006D86C: b           L_8006D874
    // 0x8006D870: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8006D874;
    // 0x8006D870: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8006D874:
    // 0x8006D874: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8006D878: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8006D87C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006D880: bc1f        L_8006D8E4
    if (!c1cs) {
        // 0x8006D884: nop
    
            goto L_8006D8E4;
    }
    // 0x8006D884: nop

    // 0x8006D888: bgez        $s1, L_8006D8B8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8006D88C: nop
    
            goto L_8006D8B8;
    }
    // 0x8006D88C: nop

    // 0x8006D890: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D894: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8006D898: mflo        $v0
    ctx->r2 = lo;
    // 0x8006D89C: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006D8A0: blez        $t6, L_8006D8B0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006D8A4: nop
    
            goto L_8006D8B0;
    }
    // 0x8006D8A4: nop

    // 0x8006D8A8: b           L_8006D8E4
    // 0x8006D8AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D8E4;
    // 0x8006D8AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8006D8B0:
    // 0x8006D8B0: b           L_8006D8E4
    // 0x8006D8B4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8006D8E4;
    // 0x8006D8B4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8006D8B8:
    // 0x8006D8B8: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D8BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006D8C0: mflo        $v0
    ctx->r2 = lo;
    // 0x8006D8C4: sra         $t7, $v0, 7
    ctx->r15 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006D8C8: bgez        $t7, L_8006D8D8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006D8CC: nop
    
            goto L_8006D8D8;
    }
    // 0x8006D8CC: nop

    // 0x8006D8D0: b           L_8006D8D8
    // 0x8006D8D4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_8006D8D8;
    // 0x8006D8D4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_8006D8D8:
    // 0x8006D8D8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8006D8DC: b           L_8006D8E4
    // 0x8006D8E0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8006D8E4;
    // 0x8006D8E0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006D8E4:
    // 0x8006D8E4: andi        $t6, $t8, 0x1F
    ctx->r14 = ctx->r24 & 0X1F;
    // 0x8006D8E8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8006D8EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006D8F0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006D8F4: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006D8F8: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X160));
    // 0x8006D8FC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8006D900: nop

    // 0x8006D904: xori        $t8, $t9, 0x1F
    ctx->r24 = ctx->r25 ^ 0X1F;
    // 0x8006D908: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8006D90C: nop

    // 0x8006D910: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006D914: sub.s       $f10, $f2, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f26.fl;
    // 0x8006D918: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006D91C: nop

    // 0x8006D920: mul.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x8006D924: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8006D928: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006D92C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006D930: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8006D934: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8006D938: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006D93C: nop

    // 0x8006D940: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006D944: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006D948: nop

    // 0x8006D94C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8006D950: beq         $t7, $zero, L_8006D99C
    if (ctx->r15 == 0) {
        // 0x8006D954: nop
    
            goto L_8006D99C;
    }
    // 0x8006D954: nop

    // 0x8006D958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006D95C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006D960: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8006D964: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006D968: nop

    // 0x8006D96C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8006D970: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006D974: nop

    // 0x8006D978: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8006D97C: bne         $t7, $zero, L_8006D994
    if (ctx->r15 != 0) {
        // 0x8006D980: nop
    
            goto L_8006D994;
    }
    // 0x8006D980: nop

    // 0x8006D984: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8006D988: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006D98C: b           L_8006D9AC
    // 0x8006D990: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8006D9AC;
    // 0x8006D990: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8006D994:
    // 0x8006D994: b           L_8006D9AC
    // 0x8006D998: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8006D9AC;
    // 0x8006D998: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8006D99C:
    // 0x8006D99C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8006D9A0: nop

    // 0x8006D9A4: bltz        $t7, L_8006D994
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006D9A8: nop
    
            goto L_8006D994;
    }
    // 0x8006D9A8: nop

L_8006D9AC:
    // 0x8006D9AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006D9B0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8006D9B4: lwc1        $f8, 0x16C($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X16C));
    // 0x8006D9B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D9BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006D9C0: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8006D9C4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8006D9C8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8006D9CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8006D9D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006D9D4: nop

    // 0x8006D9D8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8006D9DC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8006D9E0: nop

    // 0x8006D9E4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8006D9E8: beql        $t6, $zero, L_8006DA38
    if (ctx->r14 == 0) {
        // 0x8006D9EC: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_8006DA38;
    }
    goto skip_4;
    // 0x8006D9EC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x8006D9F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006D9F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D9F8: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8006D9FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006DA00: nop

    // 0x8006DA04: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8006DA08: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8006DA0C: nop

    // 0x8006DA10: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8006DA14: bne         $t6, $zero, L_8006DA2C
    if (ctx->r14 != 0) {
        // 0x8006DA18: nop
    
            goto L_8006DA2C;
    }
    // 0x8006DA18: nop

    // 0x8006DA1C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8006DA20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006DA24: b           L_8006DA44
    // 0x8006DA28: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8006DA44;
    // 0x8006DA28: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8006DA2C:
    // 0x8006DA2C: b           L_8006DA44
    // 0x8006DA30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8006DA44;
    // 0x8006DA30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8006DA34: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_8006DA38:
    // 0x8006DA38: nop

    // 0x8006DA3C: bltz        $t6, L_8006DA2C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8006DA40: nop
    
            goto L_8006DA2C;
    }
    // 0x8006DA40: nop

L_8006DA44:
    // 0x8006DA44: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8006DA48: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x8006DA4C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8006DA50: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8006DA54: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8006DA58: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DA5C: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x8006DA60: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8006DA64: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006DA68: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006DA6C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006DA70: lw          $t8, 0x64($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X64));
    // 0x8006DA74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006DA78: bc1t        L_8006E224
    if (c1cs) {
        // 0x8006DA7C: sw          $t8, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r24;
            goto L_8006E224;
    }
    // 0x8006DA7C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006DA80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006DA84: lw          $t6, 0x9C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x8006DA88: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8006DA8C: sub.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8006DA90: lhu         $t7, 0x12($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X12);
    // 0x8006DA94: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006DA98: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8006DA9C: nop

    // 0x8006DAA0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006DAA4: mflo        $t6
    ctx->r14 = lo;
    // 0x8006DAA8: bgez        $t6, L_8006DAB8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006DAAC: sra         $t9, $t6, 1
        ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8006DAB8;
    }
    // 0x8006DAAC: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8006DAB0: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8006DAB4: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8006DAB8:
    // 0x8006DAB8: bgez        $t9, L_8006DAC8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006DABC: sra         $t7, $t9, 2
        ctx->r15 = S32(SIGNED(ctx->r25) >> 2);
            goto L_8006DAC8;
    }
    // 0x8006DABC: sra         $t7, $t9, 2
    ctx->r15 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8006DAC0: addiu       $at, $t9, 0x3
    ctx->r1 = ADD32(ctx->r25, 0X3);
    // 0x8006DAC4: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_8006DAC8:
    // 0x8006DAC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006DACC: b           L_8006D424
    // 0x8006DAD0: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
        goto L_8006D424;
    // 0x8006DAD0: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x8006DAD4: div.s       $f24, $f2, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = DIV_S(ctx->f2.fl, ctx->f26.fl);
L_8006DAD8:
    // 0x8006DAD8: lwc1        $f4, 0x17C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X17C));
    // 0x8006DADC: lwc1        $f14, 0x1BC($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x8006DAE0: lwc1        $f6, 0x1B4($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X1B4));
    // 0x8006DAE4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006DAE8: lwc1        $f4, 0x1C4($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X1C4));
    // 0x8006DAEC: lui         $s7, 0x708
    ctx->r23 = S32(0X708 << 16);
    // 0x8006DAF0: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8006DAF4: mfc1        $s2, $f8
    ctx->r18 = (int32_t)ctx->f8.u32l;
    // 0x8006DAF8: lui         $fp, 0xF300
    ctx->r30 = S32(0XF300 << 16);
    // 0x8006DAFC: ori         $s7, $s7, 0x200
    ctx->r23 = ctx->r23 | 0X200;
    // 0x8006DB00: mfc1        $s6, $f10
    ctx->r22 = (int32_t)ctx->f10.u32l;
    // 0x8006DB04: sra         $s4, $s2, 1
    ctx->r20 = S32(SIGNED(ctx->r18) >> 1);
    // 0x8006DB08: bgez        $s2, L_8006DB18
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8006DB0C: sra         $t5, $s2, 4
        ctx->r13 = S32(SIGNED(ctx->r18) >> 4);
            goto L_8006DB18;
    }
    // 0x8006DB0C: sra         $t5, $s2, 4
    ctx->r13 = S32(SIGNED(ctx->r18) >> 4);
    // 0x8006DB10: addiu       $at, $s2, 0xF
    ctx->r1 = ADD32(ctx->r18, 0XF);
    // 0x8006DB14: sra         $t5, $at, 4
    ctx->r13 = S32(SIGNED(ctx->r1) >> 4);
L_8006DB18:
    // 0x8006DB18: addiu       $s4, $s4, 0x7
    ctx->r20 = ADD32(ctx->r20, 0X7);
    // 0x8006DB1C: sra         $t9, $s4, 3
    ctx->r25 = S32(SIGNED(ctx->r20) >> 3);
    // 0x8006DB20: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006DB24: lwc1        $f4, 0x1B0($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x8006DB28: addiu       $s5, $s2, -0x1
    ctx->r21 = ADD32(ctx->r18, -0X1);
    // 0x8006DB2C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006DB30: mfc1        $ra, $f8
    ctx->r31 = (int32_t)ctx->f8.u32l;
    // 0x8006DB34: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8006DB38: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8006DB3C: mfc1        $s3, $f10
    ctx->r19 = (int32_t)ctx->f10.u32l;
    // 0x8006DB40: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8006DB44: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8006DB48: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x8006DB4C: sll         $s4, $t7, 9
    ctx->r20 = S32(ctx->r15 << 9);
    // 0x8006DB50: sll         $s5, $t9, 12
    ctx->r21 = S32(ctx->r25 << 12);
    // 0x8006DB54: sll         $t6, $s6, 16
    ctx->r14 = S32(ctx->r22 << 16);
    // 0x8006DB58: sra         $s6, $t6, 16
    ctx->r22 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006DB5C: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x8006DB60: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8006DB64: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8006DB68: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006DB6C: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8006DB70: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x8006DB74: sll         $t8, $ra, 16
    ctx->r24 = S32(ctx->r31 << 16);
    // 0x8006DB78: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8006DB7C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8006DB80: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8006DB84: sra         $ra, $t8, 16
    ctx->r31 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006DB88: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
L_8006DB8C:
    // 0x8006DB8C: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
    // 0x8006DB90: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8006DB94: bc1fl       L_8006DBA8
    if (!c1cs) {
        // 0x8006DB98: mov.s       $f2, $f22
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
            goto L_8006DBA8;
    }
    goto skip_5;
    // 0x8006DB98: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    skip_5:
    // 0x8006DB9C: b           L_8006DBA8
    // 0x8006DBA0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
        goto L_8006DBA8;
    // 0x8006DBA0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8006DBA4: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
L_8006DBA8:
    // 0x8006DBA8: mul.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8006DBAC: sub.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8006DBB0: lb          $t8, -0x13CF($t8)
    ctx->r24 = S32(MEM_B(ctx->r24, -0X13CF));
    // 0x8006DBB4: sub.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8006DBB8: beq         $t8, $zero, L_8006DD40
    if (ctx->r24 == 0) {
        // 0x8006DBBC: div.s       $f6, $f8, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
            goto L_8006DD40;
    }
    // 0x8006DBBC: div.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8006DBC0: div.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8006DBC4: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DBC8: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8006DBCC: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x8006DBD0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006DBD4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006DBD8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006DBDC: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8006DBE0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006DBE4: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DBE8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8006DBEC: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8006DBF0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006DBF4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006DBF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006DBFC: sw          $s7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r23;
    // 0x8006DC00: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006DC04: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DC08: or          $t4, $s4, $at
    ctx->r12 = ctx->r20 | ctx->r1;
    // 0x8006DC0C: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8006DC10: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006DC14: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8006DC18: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006DC1C: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8006DC20: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006DC24: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8006DC28: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DC2C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8006DC30: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8006DC34: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006DC38: multu       $s2, $t2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006DC3C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006DC40: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x8006DC44: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8006DC48: mflo        $v0
    ctx->r2 = lo;
    // 0x8006DC4C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006DC50: sra         $t6, $v0, 2
    ctx->r14 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8006DC54: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x8006DC58: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8006DC5C: beq         $at, $zero, L_8006DC6C
    if (ctx->r1 == 0) {
        // 0x8006DC60: nop
    
            goto L_8006DC6C;
    }
    // 0x8006DC60: nop

    // 0x8006DC64: b           L_8006DC6C
    // 0x8006DC68: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
        goto L_8006DC6C;
    // 0x8006DC68: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8006DC6C:
    // 0x8006DC6C: bgtz        $t5, L_8006DC7C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8006DC70: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8006DC7C;
    }
    // 0x8006DC70: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006DC74: b           L_8006DC7C
    // 0x8006DC78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8006DC7C;
    // 0x8006DC78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8006DC7C:
    // 0x8006DC7C: bgtz        $t5, L_8006DC8C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8006DC80: addiu       $t9, $t0, 0x7FF
        ctx->r25 = ADD32(ctx->r8, 0X7FF);
            goto L_8006DC8C;
    }
    // 0x8006DC80: addiu       $t9, $t0, 0x7FF
    ctx->r25 = ADD32(ctx->r8, 0X7FF);
    // 0x8006DC84: b           L_8006DC8C
    // 0x8006DC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006DC8C;
    // 0x8006DC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006DC8C:
    // 0x8006DC8C: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x8006DC90: bne         $v0, $zero, L_8006DC9C
    if (ctx->r2 != 0) {
        // 0x8006DC94: nop
    
            goto L_8006DC9C;
    }
    // 0x8006DC94: nop

    // 0x8006DC98: break       7
    do_break(2147933336);
L_8006DC9C:
    // 0x8006DC9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006DCA0: bne         $v0, $at, L_8006DCB4
    if (ctx->r2 != ctx->r1) {
        // 0x8006DCA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006DCB4;
    }
    // 0x8006DCA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006DCA8: bne         $t9, $at, L_8006DCB4
    if (ctx->r25 != ctx->r1) {
        // 0x8006DCAC: nop
    
            goto L_8006DCB4;
    }
    // 0x8006DCAC: nop

    // 0x8006DCB0: break       6
    do_break(2147933360);
L_8006DCB4:
    // 0x8006DCB4: mflo        $t7
    ctx->r15 = lo;
    // 0x8006DCB8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8006DCBC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8006DCC0: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x8006DCC4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8006DCC8: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8006DCCC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8006DCD0: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8006DCD4: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DCD8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8006DCDC: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8006DCE0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006DCE4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006DCE8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006DCEC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006DCF0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006DCF4: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DCF8: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8006DCFC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8006DD00: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006DD04: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006DD08: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006DD0C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006DD10: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006DD14: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DD18: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x8006DD1C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006DD20: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006DD24: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006DD28: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8006DD2C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006DD30: or          $t6, $s5, $t9
    ctx->r14 = ctx->r21 | ctx->r25;
    // 0x8006DD34: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006DD38: b           L_8006DEBC
    // 0x8006DD3C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_8006DEBC;
    // 0x8006DD3C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8006DD40:
    // 0x8006DD40: div.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8006DD44: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DD48: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8006DD4C: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8006DD50: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006DD54: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006DD58: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006DD5C: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8006DD60: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006DD64: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DD68: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8006DD6C: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8006DD70: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006DD74: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006DD78: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006DD7C: sw          $s7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r23;
    // 0x8006DD80: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006DD84: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DD88: or          $t4, $s4, $at
    ctx->r12 = ctx->r20 | ctx->r1;
    // 0x8006DD8C: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x8006DD90: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006DD94: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8006DD98: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006DD9C: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8006DDA0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006DDA4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8006DDA8: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DDAC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8006DDB0: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8006DDB4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006DDB8: multu       $s2, $t2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006DDBC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006DDC0: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x8006DDC4: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8006DDC8: mflo        $v0
    ctx->r2 = lo;
    // 0x8006DDCC: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006DDD0: sra         $t7, $v0, 2
    ctx->r15 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8006DDD4: addiu       $v0, $t7, -0x1
    ctx->r2 = ADD32(ctx->r15, -0X1);
    // 0x8006DDD8: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8006DDDC: beq         $at, $zero, L_8006DDEC
    if (ctx->r1 == 0) {
        // 0x8006DDE0: nop
    
            goto L_8006DDEC;
    }
    // 0x8006DDE0: nop

    // 0x8006DDE4: b           L_8006DDEC
    // 0x8006DDE8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
        goto L_8006DDEC;
    // 0x8006DDE8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8006DDEC:
    // 0x8006DDEC: bgtz        $t5, L_8006DDFC
    if (SIGNED(ctx->r13) > 0) {
        // 0x8006DDF0: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8006DDFC;
    }
    // 0x8006DDF0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006DDF4: b           L_8006DDFC
    // 0x8006DDF8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8006DDFC;
    // 0x8006DDF8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8006DDFC:
    // 0x8006DDFC: bgtz        $t5, L_8006DE0C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8006DE00: addiu       $t8, $t0, 0x7FF
        ctx->r24 = ADD32(ctx->r8, 0X7FF);
            goto L_8006DE0C;
    }
    // 0x8006DE00: addiu       $t8, $t0, 0x7FF
    ctx->r24 = ADD32(ctx->r8, 0X7FF);
    // 0x8006DE04: b           L_8006DE0C
    // 0x8006DE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006DE0C;
    // 0x8006DE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006DE0C:
    // 0x8006DE0C: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x8006DE10: bne         $v0, $zero, L_8006DE1C
    if (ctx->r2 != 0) {
        // 0x8006DE14: nop
    
            goto L_8006DE1C;
    }
    // 0x8006DE14: nop

    // 0x8006DE18: break       7
    do_break(2147933720);
L_8006DE1C:
    // 0x8006DE1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006DE20: bne         $v0, $at, L_8006DE34
    if (ctx->r2 != ctx->r1) {
        // 0x8006DE24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006DE34;
    }
    // 0x8006DE24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006DE28: bne         $t8, $at, L_8006DE34
    if (ctx->r24 != ctx->r1) {
        // 0x8006DE2C: nop
    
            goto L_8006DE34;
    }
    // 0x8006DE2C: nop

    // 0x8006DE30: break       6
    do_break(2147933744);
L_8006DE34:
    // 0x8006DE34: mflo        $t9
    ctx->r25 = lo;
    // 0x8006DE38: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8006DE3C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8006DE40: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8006DE44: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8006DE48: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8006DE4C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8006DE50: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8006DE54: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DE58: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8006DE5C: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8006DE60: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006DE64: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8006DE68: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8006DE6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006DE70: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006DE74: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DE78: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8006DE7C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8006DE80: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006DE84: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006DE88: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006DE8C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006DE90: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8006DE94: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DE98: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x8006DE9C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8006DEA0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006DEA4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8006DEA8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8006DEAC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006DEB0: or          $t7, $s5, $t8
    ctx->r15 = ctx->r21 | ctx->r24;
    // 0x8006DEB4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006DEB8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8006DEBC:
    // 0x8006DEBC: sub.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x8006DEC0: lw          $a1, 0x0($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DEC4: mul.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8006DEC8: trunc.w.s   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8006DECC: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x8006DED0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8006DED4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8006DED8: add.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8006DEDC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8006DEE0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8006DEE4: blez        $s6, L_8006DEF4
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8006DEE8: trunc.w.s   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8006DEF4;
    }
    // 0x8006DEE8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006DEEC: b           L_8006DEF4
    // 0x8006DEF0: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
        goto L_8006DEF4;
    // 0x8006DEF0: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
L_8006DEF4:
    // 0x8006DEF4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8006DEF8: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006DEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006DF00: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x8006DF04: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8006DF08: blez        $t7, L_8006DF18
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006DF0C: andi        $t8, $t0, 0xFFF
        ctx->r24 = ctx->r8 & 0XFFF;
            goto L_8006DF18;
    }
    // 0x8006DF0C: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x8006DF10: b           L_8006DF18
    // 0x8006DF14: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8006DF18;
    // 0x8006DF14: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DF18:
    // 0x8006DF18: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x8006DF1C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8006DF20: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8006DF24: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8006DF28: blez        $ra, L_8006DF38
    if (SIGNED(ctx->r31) <= 0) {
        // 0x8006DF2C: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_8006DF38;
    }
    // 0x8006DF2C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8006DF30: b           L_8006DF3C
    // 0x8006DF34: or          $t0, $ra, $zero
    ctx->r8 = ctx->r31 | 0;
        goto L_8006DF3C;
    // 0x8006DF34: or          $t0, $ra, $zero
    ctx->r8 = ctx->r31 | 0;
L_8006DF38:
    // 0x8006DF38: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8006DF3C:
    // 0x8006DF3C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8006DF40: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8006DF44: blez        $t7, L_8006DF54
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006DF48: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8006DF54;
    }
    // 0x8006DF48: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8006DF4C: b           L_8006DF58
    // 0x8006DF50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8006DF58;
    // 0x8006DF50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006DF54:
    // 0x8006DF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006DF58:
    // 0x8006DF58: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x8006DF5C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8006DF60: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x8006DF64: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8006DF68: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8006DF6C: lw          $a2, 0x0($a3)
    ctx->r6 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006DF70: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8006DF74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006DF78: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x8006DF7C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8006DF80: bgez        $ra, L_8006DFD0
    if (SIGNED(ctx->r31) >= 0) {
        // 0x8006DF84: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8006DFD0;
    }
    // 0x8006DF84: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8006DF88: multu       $ra, $s3
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006DF8C: mflo        $v0
    ctx->r2 = lo;
    // 0x8006DF90: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006DF94: bgez        $s3, L_8006DFB4
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8006DF98: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8006DFB4;
    }
    // 0x8006DF98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DF9C: blez        $t6, L_8006DFAC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006DFA0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006DFAC;
    }
    // 0x8006DFA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006DFA4: b           L_8006DFD0
    // 0x8006DFA8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
        goto L_8006DFD0;
    // 0x8006DFA8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_8006DFAC:
    // 0x8006DFAC: b           L_8006DFD0
    // 0x8006DFB0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8006DFD0;
    // 0x8006DFB0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8006DFB4:
    // 0x8006DFB4: bgez        $v0, L_8006DFC4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006DFB8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006DFC4;
    }
    // 0x8006DFB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006DFBC: b           L_8006DFC4
    // 0x8006DFC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8006DFC4;
    // 0x8006DFC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8006DFC4:
    // 0x8006DFC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006DFC8: b           L_8006DFD0
    // 0x8006DFCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8006DFD0;
    // 0x8006DFCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8006DFD0:
    // 0x8006DFD0: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x8006DFD4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8006DFD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006DFDC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8006DFE0: bc1f        L_8006E044
    if (!c1cs) {
        // 0x8006DFE4: nop
    
            goto L_8006E044;
    }
    // 0x8006DFE4: nop

    // 0x8006DFE8: bgez        $s1, L_8006E018
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8006DFEC: nop
    
            goto L_8006E018;
    }
    // 0x8006DFEC: nop

    // 0x8006DFF0: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006DFF4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8006DFF8: mflo        $v0
    ctx->r2 = lo;
    // 0x8006DFFC: sra         $t7, $v0, 7
    ctx->r15 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006E000: blez        $t7, L_8006E010
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006E004: nop
    
            goto L_8006E010;
    }
    // 0x8006E004: nop

    // 0x8006E008: b           L_8006E044
    // 0x8006E00C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8006E044;
    // 0x8006E00C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E010:
    // 0x8006E010: b           L_8006E044
    // 0x8006E014: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_8006E044;
    // 0x8006E014: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8006E018:
    // 0x8006E018: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006E01C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006E020: mflo        $v0
    ctx->r2 = lo;
    // 0x8006E024: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8006E028: bgez        $t8, L_8006E038
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006E02C: nop
    
            goto L_8006E038;
    }
    // 0x8006E02C: nop

    // 0x8006E030: b           L_8006E038
    // 0x8006E034: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8006E038;
    // 0x8006E034: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8006E038:
    // 0x8006E038: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8006E03C: b           L_8006E044
    // 0x8006E040: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8006E044;
    // 0x8006E040: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006E044:
    // 0x8006E044: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x8006E048: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8006E04C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006E050: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006E054: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006E058: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X160));
    // 0x8006E05C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8006E060: nop

    // 0x8006E064: xori        $t6, $t9, 0x1F
    ctx->r14 = ctx->r25 ^ 0X1F;
    // 0x8006E068: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006E06C: nop

    // 0x8006E070: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006E074: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8006E078: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006E07C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006E080: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8006E084: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006E088: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8006E08C: nop

    // 0x8006E090: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8006E094: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8006E098: nop

    // 0x8006E09C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8006E0A0: beql        $t8, $zero, L_8006E0F0
    if (ctx->r24 == 0) {
        // 0x8006E0A4: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_8006E0F0;
    }
    goto skip_6;
    // 0x8006E0A4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_6:
    // 0x8006E0A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006E0AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006E0B0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006E0B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8006E0B8: nop

    // 0x8006E0BC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8006E0C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8006E0C4: nop

    // 0x8006E0C8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8006E0CC: bne         $t8, $zero, L_8006E0E4
    if (ctx->r24 != 0) {
        // 0x8006E0D0: nop
    
            goto L_8006E0E4;
    }
    // 0x8006E0D0: nop

    // 0x8006E0D4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8006E0D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006E0DC: b           L_8006E0FC
    // 0x8006E0E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8006E0FC;
    // 0x8006E0E0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8006E0E4:
    // 0x8006E0E4: b           L_8006E0FC
    // 0x8006E0E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8006E0FC;
    // 0x8006E0E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8006E0EC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_8006E0F0:
    // 0x8006E0F0: nop

    // 0x8006E0F4: bltz        $t8, L_8006E0E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x8006E0F8: nop
    
            goto L_8006E0E4;
    }
    // 0x8006E0F8: nop

L_8006E0FC:
    // 0x8006E0FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006E100: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8006E104: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X16C));
    // 0x8006E108: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006E10C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006E110: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8006E114: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8006E118: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006E11C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8006E120: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006E124: nop

    // 0x8006E128: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8006E12C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006E130: nop

    // 0x8006E134: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8006E138: beql        $t7, $zero, L_8006E188
    if (ctx->r15 == 0) {
        // 0x8006E13C: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_8006E188;
    }
    goto skip_7;
    // 0x8006E13C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_7:
    // 0x8006E140: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006E144: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006E148: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8006E14C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006E150: nop

    // 0x8006E154: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8006E158: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006E15C: nop

    // 0x8006E160: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8006E164: bne         $t7, $zero, L_8006E17C
    if (ctx->r15 != 0) {
        // 0x8006E168: nop
    
            goto L_8006E17C;
    }
    // 0x8006E168: nop

    // 0x8006E16C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8006E170: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006E174: b           L_8006E194
    // 0x8006E178: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8006E194;
    // 0x8006E178: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8006E17C:
    // 0x8006E17C: b           L_8006E194
    // 0x8006E180: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8006E194;
    // 0x8006E180: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8006E184: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_8006E188:
    // 0x8006E188: nop

    // 0x8006E18C: bltz        $t7, L_8006E17C
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006E190: nop
    
            goto L_8006E17C;
    }
    // 0x8006E190: nop

L_8006E194:
    // 0x8006E194: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006E198: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x8006E19C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8006E1A0: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8006E1A4: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8006E1A8: lw          $v1, 0x0($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8006E1AC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x8006E1B0: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8006E1B4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006E1B8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8006E1BC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006E1C0: lw          $t6, 0x64($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X64));
    // 0x8006E1C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006E1C8: bc1t        L_8006E224
    if (c1cs) {
        // 0x8006E1CC: sw          $t6, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r14;
            goto L_8006E224;
    }
    // 0x8006E1CC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8006E1D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006E1D4: lw          $t7, 0x9C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x8006E1D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8006E1DC: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8006E1E0: lhu         $t8, 0x12($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X12);
    // 0x8006E1E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8006E1E8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8006E1EC: nop

    // 0x8006E1F0: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006E1F4: mflo        $t7
    ctx->r15 = lo;
    // 0x8006E1F8: bgez        $t7, L_8006E208
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006E1FC: sra         $t9, $t7, 1
        ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8006E208;
    }
    // 0x8006E1FC: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8006E200: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8006E204: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8006E208:
    // 0x8006E208: bgez        $t9, L_8006E218
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8006E20C: sra         $t8, $t9, 2
        ctx->r24 = S32(SIGNED(ctx->r25) >> 2);
            goto L_8006E218;
    }
    // 0x8006E20C: sra         $t8, $t9, 2
    ctx->r24 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8006E210: addiu       $at, $t9, 0x3
    ctx->r1 = ADD32(ctx->r25, 0X3);
    // 0x8006E214: sra         $t8, $at, 2
    ctx->r24 = S32(SIGNED(ctx->r1) >> 2);
L_8006E218:
    // 0x8006E218: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8006E21C: b           L_8006DB8C
    // 0x8006E220: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_8006DB8C;
    // 0x8006E220: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_8006E224:
    // 0x8006E224: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_8006E228:
    // 0x8006E228: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8006E22C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8006E230: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8006E234: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8006E238: lw          $s0, 0x38($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8006E23C: lw          $s1, 0x3C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8006E240: lw          $s2, 0x40($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8006E244: lw          $s3, 0x44($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8006E248: lw          $s4, 0x48($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8006E24C: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8006E250: lw          $s6, 0x50($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X50));
    // 0x8006E254: lw          $s7, 0x54($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8006E258: lw          $fp, 0x58($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X58));
    // 0x8006E25C: jr          $ra
    // 0x8006E260: addiu       $sp, $sp, 0x1C8
    ctx->r29 = ADD32(ctx->r29, 0X1C8);
    return;
    // 0x8006E260: addiu       $sp, $sp, 0x1C8
    ctx->r29 = ADD32(ctx->r29, 0X1C8);
;}
RECOMP_FUNC void func_80054DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054DE0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80054DE4: addiu       $v0, $v0, -0x4360
    ctx->r2 = ADD32(ctx->r2, -0X4360);
    // 0x80054DE8: lh          $t6, 0xE($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0XE));
    // 0x80054DEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054DF0: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x80054DF4: sh          $t6, 0x3750($at)
    MEM_H(0X3750, ctx->r1) = ctx->r14;
    // 0x80054DF8: lh          $t7, 0x10($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X10));
    // 0x80054DFC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80054E00: addiu       $v1, $v1, -0x5598
    ctx->r3 = ADD32(ctx->r3, -0X5598);
    // 0x80054E04: sh          $t7, -0x9DC($at)
    MEM_H(-0X9DC, ctx->r1) = ctx->r15;
    // 0x80054E08: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x80054E0C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80054E10: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80054E14: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x80054E18: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80054E1C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80054E20: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // 0x80054E24: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x80054E28: lbu         $t3, 0x12($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X12);
    // 0x80054E2C: lbu         $t4, 0x13C($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X13C);
    // 0x80054E30: lw          $t5, 0xFC($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0XFC));
    // 0x80054E34: lw          $t6, 0x100($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X100));
    // 0x80054E38: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x80054E3C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80054E40: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80054E44: sb          $t3, 0x386($a3)
    MEM_B(0X386, ctx->r7) = ctx->r11;
    // 0x80054E48: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x80054E4C: sw          $t5, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r13;
    // 0x80054E50: sw          $t6, 0x13C($v1)
    MEM_W(0X13C, ctx->r3) = ctx->r14;
    // 0x80054E54: lw          $t7, 0x104($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X104));
    // 0x80054E58: lw          $t8, 0x108($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X108));
    // 0x80054E5C: lw          $t9, 0x10C($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X10C));
    // 0x80054E60: lw          $t3, 0x110($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X110));
    // 0x80054E64: lw          $t4, 0x114($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X114));
    // 0x80054E68: lw          $t5, 0x118($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X118));
    // 0x80054E6C: lw          $t6, 0x11C($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X11C));
    // 0x80054E70: sw          $t7, 0x144($v1)
    MEM_W(0X144, ctx->r3) = ctx->r15;
    // 0x80054E74: sw          $t8, 0x148($v1)
    MEM_W(0X148, ctx->r3) = ctx->r24;
    // 0x80054E78: sw          $t9, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = ctx->r25;
    // 0x80054E7C: sw          $t3, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->r11;
    // 0x80054E80: sw          $t4, 0x158($v1)
    MEM_W(0X158, ctx->r3) = ctx->r12;
    // 0x80054E84: sw          $t5, 0x160($v1)
    MEM_W(0X160, ctx->r3) = ctx->r13;
    // 0x80054E88: sw          $t6, 0x164($v1)
    MEM_W(0X164, ctx->r3) = ctx->r14;
    // 0x80054E8C: lw          $t7, 0x120($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X120));
    // 0x80054E90: lw          $t8, 0x124($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X124));
    // 0x80054E94: lw          $t9, 0x128($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X128));
    // 0x80054E98: lw          $t3, 0x12C($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X12C));
    // 0x80054E9C: lw          $t4, 0x130($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X130));
    // 0x80054EA0: lw          $t5, 0x134($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X134));
    // 0x80054EA4: lw          $t6, 0x138($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X138));
    // 0x80054EA8: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x80054EAC: addu        $t0, $v0, $t2
    ctx->r8 = ADD32(ctx->r2, ctx->r10);
    // 0x80054EB0: sw          $t7, 0x168($v1)
    MEM_W(0X168, ctx->r3) = ctx->r15;
    // 0x80054EB4: sw          $t8, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->r24;
    // 0x80054EB8: sw          $t9, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->r25;
    // 0x80054EBC: sw          $t3, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->r11;
    // 0x80054EC0: sw          $t4, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->r12;
    // 0x80054EC4: sw          $t5, 0x18C($v1)
    MEM_W(0X18C, ctx->r3) = ctx->r13;
    // 0x80054EC8: sw          $t6, 0x190($v1)
    MEM_W(0X190, ctx->r3) = ctx->r14;
    // 0x80054ECC: lh          $t4, 0x64($t0)
    ctx->r12 = S32(MEM_H(ctx->r8, 0X64));
    // 0x80054ED0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80054ED4: addu        $a2, $v0, $t8
    ctx->r6 = ADD32(ctx->r2, ctx->r24);
    // 0x80054ED8: sh          $t4, 0x2B2($a3)
    MEM_H(0X2B2, ctx->r7) = ctx->r12;
    // 0x80054EDC: lh          $t4, 0x80($t0)
    ctx->r12 = S32(MEM_H(ctx->r8, 0X80));
    // 0x80054EE0: lbu         $t7, 0x14($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X14);
    // 0x80054EE4: lw          $t9, 0x20($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X20));
    // 0x80054EE8: lw          $t3, 0x18($a2)
    ctx->r11 = S32(MEM_W(ctx->r6, 0X18));
    // 0x80054EEC: lh          $t5, 0x68($t0)
    ctx->r13 = S32(MEM_H(ctx->r8, 0X68));
    // 0x80054EF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80054EF4: lh          $t6, 0x6C($t0)
    ctx->r14 = S32(MEM_H(ctx->r8, 0X6C));
    // 0x80054EF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80054EFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80054F00: sh          $t4, 0x2EC($a3)
    MEM_H(0X2EC, ctx->r7) = ctx->r12;
    // 0x80054F04: sll         $t4, $s0, 3
    ctx->r12 = S32(ctx->r16 << 3);
    // 0x80054F08: sh          $t5, 0x2B4($a3)
    MEM_H(0X2B4, ctx->r7) = ctx->r13;
    // 0x80054F0C: lh          $t5, 0xC4($t0)
    ctx->r13 = S32(MEM_H(ctx->r8, 0XC4));
    // 0x80054F10: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80054F14: sb          $t7, 0x385($a3)
    MEM_B(0X385, ctx->r7) = ctx->r15;
    // 0x80054F18: sb          $t9, 0x384($a3)
    MEM_B(0X384, ctx->r7) = ctx->r25;
    // 0x80054F1C: sb          $t3, 0x280($a3)
    MEM_B(0X280, ctx->r7) = ctx->r11;
    // 0x80054F20: sh          $t6, 0x2BC($a3)
    MEM_H(0X2BC, ctx->r7) = ctx->r14;
    // 0x80054F24: lh          $t7, 0x70($t0)
    ctx->r15 = S32(MEM_H(ctx->r8, 0X70));
    // 0x80054F28: lh          $t8, 0x74($t0)
    ctx->r24 = S32(MEM_H(ctx->r8, 0X74));
    // 0x80054F2C: lh          $t9, 0x78($t0)
    ctx->r25 = S32(MEM_H(ctx->r8, 0X78));
    // 0x80054F30: lh          $t3, 0x7C($t0)
    ctx->r11 = S32(MEM_H(ctx->r8, 0X7C));
    // 0x80054F34: lh          $t6, 0xC8($t0)
    ctx->r14 = S32(MEM_H(ctx->r8, 0XC8));
    // 0x80054F38: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80054F3C: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80054F40: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80054F44: sh          $t5, 0x314($a3)
    MEM_H(0X314, ctx->r7) = ctx->r13;
    // 0x80054F48: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x80054F4C: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80054F50: sh          $t7, 0x2DA($a3)
    MEM_H(0X2DA, ctx->r7) = ctx->r15;
    // 0x80054F54: sh          $t8, 0x2E2($a3)
    MEM_H(0X2E2, ctx->r7) = ctx->r24;
    // 0x80054F58: sh          $t9, 0x28C($a3)
    MEM_H(0X28C, ctx->r7) = ctx->r25;
    // 0x80054F5C: sh          $t3, 0x2E8($a3)
    MEM_H(0X2E8, ctx->r7) = ctx->r11;
    // 0x80054F60: sh          $t6, 0x31C($a3)
    MEM_H(0X31C, ctx->r7) = ctx->r14;
    // 0x80054F64: lh          $t7, 0xCC($t0)
    ctx->r15 = S32(MEM_H(ctx->r8, 0XCC));
    // 0x80054F68: lh          $t8, 0xD0($t0)
    ctx->r24 = S32(MEM_H(ctx->r8, 0XD0));
    // 0x80054F6C: lh          $t9, 0xD4($t0)
    ctx->r25 = S32(MEM_H(ctx->r8, 0XD4));
    // 0x80054F70: lh          $t3, 0xD8($t0)
    ctx->r11 = S32(MEM_H(ctx->r8, 0XD8));
    // 0x80054F74: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x80054F78: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80054F7C: addiu       $t5, $t5, 0x5770
    ctx->r13 = ADD32(ctx->r13, 0X5770);
    // 0x80054F80: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x80054F84: addiu       $t6, $t6, -0x4360
    ctx->r14 = ADD32(ctx->r14, -0X4360);
    // 0x80054F88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80054F8C: addu        $v1, $t2, $t6
    ctx->r3 = ADD32(ctx->r10, ctx->r14);
    // 0x80054F90: addu        $a2, $s0, $t6
    ctx->r6 = ADD32(ctx->r16, ctx->r14);
    // 0x80054F94: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80054F98: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80054F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80054FA0: sh          $t7, 0x31E($a3)
    MEM_H(0X31E, ctx->r7) = ctx->r15;
    // 0x80054FA4: sh          $t8, 0x320($a3)
    MEM_H(0X320, ctx->r7) = ctx->r24;
    // 0x80054FA8: sh          $t9, 0x322($a3)
    MEM_H(0X322, ctx->r7) = ctx->r25;
    // 0x80054FAC: sh          $t3, 0x332($a3)
    MEM_H(0X332, ctx->r7) = ctx->r11;
L_80054FB0:
    // 0x80054FB0: lh          $t7, 0x28($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X28));
    // 0x80054FB4: lbu         $t8, 0xDC($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XDC);
    // 0x80054FB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80054FBC: slti        $at, $a0, 0xF
    ctx->r1 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x80054FC0: sh          $t7, 0x28E($v0)
    MEM_H(0X28E, ctx->r2) = ctx->r15;
    // 0x80054FC4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80054FC8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80054FCC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80054FD0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80054FD4: bne         $at, $zero, L_80054FB0
    if (ctx->r1 != 0) {
        // 0x80054FD8: sb          $t8, 0x348($a1)
        MEM_B(0X348, ctx->r5) = ctx->r24;
            goto L_80054FB0;
    }
    // 0x80054FD8: sb          $t8, 0x348($a1)
    MEM_B(0X348, ctx->r5) = ctx->r24;
    // 0x80054FDC: lh          $t9, 0x84($t0)
    ctx->r25 = S32(MEM_H(ctx->r8, 0X84));
    // 0x80054FE0: lh          $t3, 0x88($t0)
    ctx->r11 = S32(MEM_H(ctx->r8, 0X88));
    // 0x80054FE4: lh          $t4, 0x8C($t0)
    ctx->r12 = S32(MEM_H(ctx->r8, 0X8C));
    // 0x80054FE8: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x80054FEC: addiu       $t5, $t5, -0x4354
    ctx->r13 = ADD32(ctx->r13, -0X4354);
    // 0x80054FF0: addu        $v1, $t2, $t5
    ctx->r3 = ADD32(ctx->r10, ctx->r13);
    // 0x80054FF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80054FF8: addiu       $v0, $t1, 0x6
    ctx->r2 = ADD32(ctx->r9, 0X6);
    // 0x80054FFC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80055000: sh          $t9, 0x2F4($t1)
    MEM_H(0X2F4, ctx->r9) = ctx->r25;
    // 0x80055004: sh          $t3, 0x2F6($t1)
    MEM_H(0X2F6, ctx->r9) = ctx->r11;
    // 0x80055008: sh          $t4, 0x2F8($t1)
    MEM_H(0X2F8, ctx->r9) = ctx->r12;
L_8005500C:
    // 0x8005500C: lh          $t7, 0x88($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X88));
    // 0x80055010: lh          $t8, 0x8C($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X8C));
    // 0x80055014: lh          $t9, 0x90($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X90));
    // 0x80055018: lh          $t6, 0x84($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0X84));
    // 0x8005501C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80055020: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80055024: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80055028: sh          $t7, 0x2EE($v0)
    MEM_H(0X2EE, ctx->r2) = ctx->r15;
    // 0x8005502C: sh          $t8, 0x2F0($v0)
    MEM_H(0X2F0, ctx->r2) = ctx->r24;
    // 0x80055030: sh          $t9, 0x2F2($v0)
    MEM_H(0X2F2, ctx->r2) = ctx->r25;
    // 0x80055034: bne         $a0, $a1, L_8005500C
    if (ctx->r4 != ctx->r5) {
        // 0x80055038: sh          $t6, 0x2EC($v0)
        MEM_H(0X2EC, ctx->r2) = ctx->r14;
            goto L_8005500C;
    }
    // 0x80055038: sh          $t6, 0x2EC($v0)
    MEM_H(0X2EC, ctx->r2) = ctx->r14;
    // 0x8005503C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80055040: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80055044: jal         0x8004D888
    // 0x80055048: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_8004D888(rdram, ctx);
        goto after_0;
    // 0x80055048: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_0:
    // 0x8005504C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80055050: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80055054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80055058: jr          $ra
    // 0x8005505C: nop

    return;
    // 0x8005505C: nop

;}
RECOMP_FUNC void func_8005B728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B728: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8005B72C: lw          $t6, -0x14C0($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X14C0));
    // 0x8005B730: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005B734: addiu       $t8, $t8, -0x6508
    ctx->r24 = ADD32(ctx->r24, -0X6508);
    // 0x8005B738: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005B73C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005B740: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005B744: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8005B748: lw          $t9, 0x20($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X20));
    // 0x8005B74C: lw          $t1, 0x24($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X24));
    // 0x8005B750: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8005B754: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8005B758: addiu       $a2, $a2, -0x5B70
    ctx->r6 = ADD32(ctx->r6, -0X5B70);
    // 0x8005B75C: lw          $t2, 0x28($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X28));
    // 0x8005B760: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005B764: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8005B768: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005B76C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005B770: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8005B774: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005B778: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8005B77C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = S32(MEM_W(ctx->r6, 0X0));
    // 0x8005B780: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8005B784: addiu       $a3, $a3, -0x5B6C
    ctx->r7 = ADD32(ctx->r7, -0X5B6C);
    // 0x8005B788: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005B78C: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005B790: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = S32(MEM_W(ctx->r7, 0X0));
    // 0x8005B794: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8005B798: addiu       $t0, $t0, -0x5B68
    ctx->r8 = ADD32(ctx->r8, -0X5B68);
    // 0x8005B79C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8005B7A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005B7A4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8005B7A8: lui         $v1, 0x802A
    ctx->r3 = S32(0X802A << 16);
    // 0x8005B7AC: addiu       $v1, $v1, 0x5770
    ctx->r3 = ADD32(ctx->r3, 0X5770);
    // 0x8005B7B0: lw          $t9, 0x2C($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X2C));
    // 0x8005B7B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B7B8: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005B7BC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8005B7C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005B7C4: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = S32(MEM_W(ctx->r8, 0X0));
    // 0x8005B7C8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005B7CC: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8005B7D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005B7D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B7D8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8005B7DC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8005B7E0: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8005B7E4: sh          $t1, 0x288($v1)
    MEM_H(0X288, ctx->r3) = ctx->r9;
    // 0x8005B7E8: sh          $zero, 0x2E2($v1)
    MEM_H(0X2E2, ctx->r3) = 0;
    // 0x8005B7EC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005B7F0: lw          $a0, 0x8($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X8));
    // 0x8005B7F4: addiu       $a1, $a1, -0x1988
    ctx->r5 = ADD32(ctx->r5, -0X1988);
    // 0x8005B7F8: sh          $t9, 0x282($v1)
    MEM_H(0X282, ctx->r3) = ctx->r25;
    // 0x8005B7FC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8005B800: sw          $t4, 0x214($v1)
    MEM_W(0X214, ctx->r3) = ctx->r12;
    // 0x8005B804: sw          $t6, 0x218($v1)
    MEM_W(0X218, ctx->r3) = ctx->r14;
    // 0x8005B808: jal         0x80070BAC
    // 0x8005B80C: sw          $t8, 0x21C($v1)
    MEM_W(0X21C, ctx->r3) = ctx->r24;
    RNCDecompress(rdram, ctx);
        goto after_0;
    // 0x8005B80C: sw          $t8, 0x21C($v1)
    MEM_W(0X21C, ctx->r3) = ctx->r24;
    after_0:
    // 0x8005B810: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8005B814: lw          $t2, -0x14C0($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X14C0));
    // 0x8005B818: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005B81C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x8005B820: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8005B824: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005B828: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8005B82C: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8005B830: lw          $a0, -0x64FC($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X64FC));
    // 0x8005B834: jal         0x80070BAC
    // 0x8005B838: addiu       $a1, $a1, 0x61A8
    ctx->r5 = ADD32(ctx->r5, 0X61A8);
    RNCDecompress(rdram, ctx);
        goto after_1;
    // 0x8005B838: addiu       $a1, $a1, 0x61A8
    ctx->r5 = ADD32(ctx->r5, 0X61A8);
    after_1:
    // 0x8005B83C: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x8005B840: lw          $t4, -0x14C0($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X14C0));
    // 0x8005B844: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005B848: lui         $a1, 0x8024
    ctx->r5 = S32(0X8024 << 16);
    // 0x8005B84C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8005B850: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005B854: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8005B858: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8005B85C: lw          $a0, -0x64F8($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X64F8));
    // 0x8005B860: jal         0x80070BAC
    // 0x8005B864: addiu       $a1, $a1, 0x6BA8
    ctx->r5 = ADD32(ctx->r5, 0X6BA8);
    RNCDecompress(rdram, ctx);
        goto after_2;
    // 0x8005B864: addiu       $a1, $a1, 0x6BA8
    ctx->r5 = ADD32(ctx->r5, 0X6BA8);
    after_2:
    // 0x8005B868: lui         $a0, 0x8035
    ctx->r4 = S32(0X8035 << 16);
    // 0x8005B86C: lui         $a1, 0x802C
    ctx->r5 = S32(0X802C << 16);
    // 0x8005B870: ori         $a1, $a1, 0x5000
    ctx->r5 = ctx->r5 | 0X5000;
    // 0x8005B874: jal         0x80070BAC
    // 0x8005B878: ori         $a0, $a0, 0xA800
    ctx->r4 = ctx->r4 | 0XA800;
    RNCDecompress(rdram, ctx);
        goto after_3;
    // 0x8005B878: ori         $a0, $a0, 0xA800
    ctx->r4 = ctx->r4 | 0XA800;
    after_3:
    // 0x8005B87C: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x8005B880: lh          $a1, -0x5378($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X5378));
    // 0x8005B884: lui         $a2, 0x8022
    ctx->r6 = S32(0X8022 << 16);
    // 0x8005B888: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005B88C: blez        $a1, L_8005B8C8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005B890: addiu       $a2, $a2, -0x2900
        ctx->r6 = ADD32(ctx->r6, -0X2900);
            goto L_8005B8C8;
    }
    // 0x8005B890: addiu       $a2, $a2, -0x2900
    ctx->r6 = ADD32(ctx->r6, -0X2900);
    // 0x8005B894: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8005B898: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8005B89C: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x8005B8A0: addiu       $v0, $t6, -0x1988
    ctx->r2 = ADD32(ctx->r14, -0X1988);
    // 0x8005B8A4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005B8A8: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
L_8005B8AC:
    // 0x8005B8AC: lbu         $t8, 0x2B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2B);
    // 0x8005B8B0: lbu         $t9, 0x2C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2C);
    // 0x8005B8B4: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8005B8B8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8005B8BC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8005B8C0: bne         $at, $zero, L_8005B8AC
    if (ctx->r1 != 0) {
        // 0x8005B8C4: addu        $v1, $v1, $t9
        ctx->r3 = ADD32(ctx->r3, ctx->r25);
            goto L_8005B8AC;
    }
    // 0x8005B8C4: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
L_8005B8C8:
    // 0x8005B8C8: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8005B8CC: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x8005B8D0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8005B8D4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005B8D8: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8005B8DC: addiu       $v1, $t2, 0x3F
    ctx->r3 = ADD32(ctx->r10, 0X3F);
    // 0x8005B8E0: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8005B8E4: and         $t3, $v1, $at
    ctx->r11 = ctx->r3 & ctx->r1;
    // 0x8005B8E8: lui         $at, 0x802C
    ctx->r1 = S32(0X802C << 16);
    // 0x8005B8EC: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x8005B8F0: addu        $a0, $t3, $at
    ctx->r4 = ADD32(ctx->r11, ctx->r1);
    // 0x8005B8F4: lui         $t5, 0x803D
    ctx->r13 = S32(0X803D << 16);
    // 0x8005B8F8: ori         $t5, $t5, 0xA800
    ctx->r13 = ctx->r13 | 0XA800;
    // 0x8005B8FC: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x8005B900: subu        $a1, $t5, $a0
    ctx->r5 = SUB32(ctx->r13, ctx->r4);
    // 0x8005B904: jal         0x800717F0
    // 0x8005B908: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    initcache(rdram, ctx);
        goto after_4;
    // 0x8005B908: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    after_4:
    // 0x8005B90C: jal         0x800637C8
    // 0x8005B910: nop

    func_800637C8(rdram, ctx);
        goto after_5;
    // 0x8005B910: nop

    after_5:
    // 0x8005B914: jal         0x8005B720
    // 0x8005B918: nop

    func_8005B720(rdram, ctx);
        goto after_6;
    // 0x8005B918: nop

    after_6:
    // 0x8005B91C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8005B920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B924: jr          $ra
    // 0x8005B928: nop

    return;
    // 0x8005B928: nop

    // 0x8005B92C: jr          $ra
    // 0x8005B930: nop

    return;
    // 0x8005B930: nop

    // 0x8005B934: jr          $ra
    // 0x8005B938: nop

    return;
    // 0x8005B938: nop

;}
RECOMP_FUNC void insertsprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009253C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80092544: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80092548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009254C: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80092550: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80092554: jal         0x80092658
    // 0x80092558: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    insertspritestat(rdram, ctx);
        goto after_0;
    // 0x80092558: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x8009255C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80092560: addiu       $v1, $v1, -0x9FC
    ctx->r3 = ADD32(ctx->r3, -0X9FC);
    // 0x80092564: lw          $t9, 0x0($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80092568: lh          $a0, 0x1A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X1A));
    // 0x8009256C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80092570: jal         0x80092588
    // 0x80092574: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    insertspritesect(rdram, ctx);
        goto after_1;
    // 0x80092574: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    after_1:
    // 0x80092578: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8009257C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092580: jr          $ra
    // 0x80092584: nop

    return;
    // 0x80092584: nop

;}
RECOMP_FUNC void alEnvmixerNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC1CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CC1D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CC1D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CC1D8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CC1DC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CC1E0: addiu       $a2, $a2, -0x275C
    ctx->r6 = ADD32(ctx->r6, -0X275C);
    // 0x800CC1E4: addiu       $a1, $a1, -0x2164
    ctx->r5 = ADD32(ctx->r5, -0X2164);
    // 0x800CC1E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CC1EC: jal         0x800D05C0
    // 0x800CC1F0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CC1F0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x800CC1F4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800CC1F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CC1FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CC200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CC204: lw          $a2, 0x24($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CC208: jal         0x800BF830
    // 0x800CC20C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CC20C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CC210: lw          $t0, 0x20($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CC214: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800CC218: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800CC21C: sw          $v1, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r3;
    // 0x800CC220: sw          $zero, 0x48($t0)
    MEM_W(0X48, ctx->r8) = 0;
    // 0x800CC224: sh          $v1, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r3;
    // 0x800CC228: sh          $v1, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r3;
    // 0x800CC22C: sh          $v1, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r3;
    // 0x800CC230: sh          $v1, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r3;
    // 0x800CC234: sh          $v1, 0x1E($t0)
    MEM_H(0X1E, ctx->r8) = ctx->r3;
    // 0x800CC238: sh          $zero, 0x20($t0)
    MEM_H(0X20, ctx->r8) = 0;
    // 0x800CC23C: sh          $zero, 0x22($t0)
    MEM_H(0X22, ctx->r8) = 0;
    // 0x800CC240: sh          $v1, 0x26($t0)
    MEM_H(0X26, ctx->r8) = ctx->r3;
    // 0x800CC244: sh          $zero, 0x24($t0)
    MEM_H(0X24, ctx->r8) = 0;
    // 0x800CC248: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x800CC24C: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
    // 0x800CC250: sh          $zero, 0x18($t0)
    MEM_H(0X18, ctx->r8) = 0;
    // 0x800CC254: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x800CC258: sw          $zero, 0x40($t0)
    MEM_W(0X40, ctx->r8) = 0;
    // 0x800CC25C: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    // 0x800CC260: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CC264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CC268: jr          $ra
    // 0x800CC26C: nop

    return;
    // 0x800CC26C: nop

;}
RECOMP_FUNC void func_80060C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060C40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80060C44: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80060C48: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80060C4C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80060C50: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80060C54: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80060C58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060C5C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060C60: jal         0x8006A310
    // 0x80060C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8006A310(rdram, ctx);
        goto after_0;
    // 0x80060C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80060C68: lui         $s5, 0x8022
    ctx->r21 = S32(0X8022 << 16);
    // 0x80060C6C: addiu       $s5, $s5, -0x2990
    ctx->r21 = ADD32(ctx->r21, -0X2990);
    // 0x80060C70: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x80060C74: lui         $s6, 0x8022
    ctx->r22 = S32(0X8022 << 16);
    // 0x80060C78: lw          $s6, -0x5240($s6)
    ctx->r22 = S32(MEM_W(ctx->r22, -0X5240));
    // 0x80060C7C: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x80060C80: addiu       $s4, $s4, -0x5A00
    ctx->r20 = ADD32(ctx->r20, -0X5A00);
    // 0x80060C84: blez        $s6, L_80060DF4
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80060C88: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80060DF4;
    }
    // 0x80060C88: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80060C8C: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x80060C90: lui         $ra, 0x8022
    ctx->r31 = S32(0X8022 << 16);
    // 0x80060C94: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80060C98: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x80060C9C: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x80060CA0: addiu       $t2, $t2, 0x6BA8
    ctx->r10 = ADD32(ctx->r10, 0X6BA8);
    // 0x80060CA4: addiu       $t4, $t4, 0x4FA0
    ctx->r12 = ADD32(ctx->r12, 0X4FA0);
    // 0x80060CA8: addiu       $t5, $t5, -0x19A0
    ctx->r13 = ADD32(ctx->r13, -0X19A0);
    // 0x80060CAC: addiu       $ra, $ra, -0x2338
    ctx->r31 = ADD32(ctx->r31, -0X2338);
    // 0x80060CB0: addiu       $s0, $s0, -0x2344
    ctx->r16 = ADD32(ctx->r16, -0X2344);
    // 0x80060CB4: ori         $s2, $zero, 0x8000
    ctx->r18 = 0 | 0X8000;
    // 0x80060CB8: addiu       $s1, $zero, 0x100
    ctx->r17 = ADD32(0, 0X100);
    // 0x80060CBC: addiu       $t3, $zero, 0x2C
    ctx->r11 = ADD32(0, 0X2C);
L_80060CC0:
    // 0x80060CC0: lhu         $t1, 0x0($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0X0);
    // 0x80060CC4: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x80060CC8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80060CCC: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x80060CD0: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x80060CD4: lh          $t0, 0x2330($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X2330));
    // 0x80060CD8: bltzl       $t0, L_80060DE8
    if (SIGNED(ctx->r8) < 0) {
        // 0x80060CDC: slt         $at, $s3, $s6
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_80060DE8;
    }
    goto skip_0;
    // 0x80060CDC: slt         $at, $s3, $s6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r22) ? 1 : 0;
    skip_0:
L_80060CE0:
    // 0x80060CE0: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060CE4: mflo        $t7
    ctx->r15 = lo;
    // 0x80060CE8: addu        $v0, $t2, $t7
    ctx->r2 = ADD32(ctx->r10, ctx->r15);
    // 0x80060CEC: lh          $t8, 0xC($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0XC));
    // 0x80060CF0: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80060CF4: beql        $s2, $t9, L_80060DD4
    if (ctx->r18 == ctx->r25) {
        // 0x80060CF8: sll         $t9, $t0, 1
        ctx->r25 = S32(ctx->r8 << 1);
            goto L_80060DD4;
    }
    goto skip_1;
    // 0x80060CF8: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    skip_1:
    // 0x80060CFC: lh          $t6, 0xE($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0XE));
    // 0x80060D00: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80060D04: bnel        $at, $zero, L_80060DD4
    if (ctx->r1 != 0) {
        // 0x80060D08: sll         $t9, $t0, 1
        ctx->r25 = S32(ctx->r8 << 1);
            goto L_80060DD4;
    }
    goto skip_2;
    // 0x80060D08: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    skip_2:
    // 0x80060D0C: lbu         $t7, 0x27($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X27);
    // 0x80060D10: beql        $t7, $zero, L_80060DD4
    if (ctx->r15 == 0) {
        // 0x80060D14: sll         $t9, $t0, 1
        ctx->r25 = S32(ctx->r8 << 1);
            goto L_80060DD4;
    }
    goto skip_3;
    // 0x80060D14: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    skip_3:
    // 0x80060D18: lw          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_W(ctx->r13, 0X0));
    // 0x80060D1C: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80060D20: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80060D24: lw          $a1, -0x199C($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X199C));
    // 0x80060D28: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x80060D2C: blez        $v1, L_80060D3C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80060D30: lw          $a3, 0x0($s0)
        ctx->r7 = S32(MEM_W(ctx->r16, 0X0));
            goto L_80060D3C;
    }
    // 0x80060D30: lw          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80060D34: b           L_80060D40
    // 0x80060D38: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80060D40;
    // 0x80060D38: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80060D3C:
    // 0x80060D3C: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
L_80060D40:
    // 0x80060D40: lw          $t6, 0x4($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80060D44: sll         $t7, $a3, 3
    ctx->r15 = S32(ctx->r7 << 3);
    // 0x80060D48: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x80060D4C: blez        $v1, L_80060D5C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80060D50: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_80060D5C;
    }
    // 0x80060D50: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80060D54: b           L_80060D5C
    // 0x80060D58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80060D5C;
    // 0x80060D58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80060D5C:
    // 0x80060D5C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80060D60: beq         $at, $zero, L_80060D70
    if (ctx->r1 == 0) {
        // 0x80060D64: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80060D70;
    }
    // 0x80060D64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80060D68: b           L_80060D70
    // 0x80060D6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
        goto L_80060D70;
    // 0x80060D6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_80060D70:
    // 0x80060D70: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80060D74: beq         $at, $zero, L_80060D84
    if (ctx->r1 == 0) {
        // 0x80060D78: sra         $t6, $a1, 2
        ctx->r14 = S32(SIGNED(ctx->r5) >> 2);
            goto L_80060D84;
    }
    // 0x80060D78: sra         $t6, $a1, 2
    ctx->r14 = S32(SIGNED(ctx->r5) >> 2);
    // 0x80060D7C: b           L_80060D88
    // 0x80060D80: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
        goto L_80060D88;
    // 0x80060D80: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80060D84:
    // 0x80060D84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80060D88:
    // 0x80060D88: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80060D8C: beq         $at, $zero, L_80060D9C
    if (ctx->r1 == 0) {
        // 0x80060D90: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80060D9C;
    }
    // 0x80060D90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80060D94: b           L_80060D9C
    // 0x80060D98: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_80060D9C;
    // 0x80060D98: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80060D9C:
    // 0x80060D9C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80060DA0: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80060DA4: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x80060DA8: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x80060DAC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80060DB0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80060DB4: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80060DB8: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x80060DBC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80060DC0: bne         $s1, $t8, L_80060DD0
    if (ctx->r17 != ctx->r24) {
        // 0x80060DC4: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_80060DD0;
    }
    // 0x80060DC4: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80060DC8: b           L_80060E04
    // 0x80060DCC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80060E04;
    // 0x80060DCC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80060DD0:
    // 0x80060DD0: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
L_80060DD4:
    // 0x80060DD4: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x80060DD8: lh          $t0, 0x0($t6)
    ctx->r8 = S32(MEM_H(ctx->r14, 0X0));
    // 0x80060DDC: bgez        $t0, L_80060CE0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80060DE0: nop
    
            goto L_80060CE0;
    }
    // 0x80060DE0: nop

    // 0x80060DE4: slt         $at, $s3, $s6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r22) ? 1 : 0;
L_80060DE8:
    // 0x80060DE8: bne         $at, $zero, L_80060CC0
    if (ctx->r1 != 0) {
        // 0x80060DEC: addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
            goto L_80060CC0;
    }
    // 0x80060DEC: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80060DF0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80060DF4:
    // 0x80060DF4: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x80060DF8: addiu       $s0, $s0, -0x2344
    ctx->r16 = ADD32(ctx->r16, -0X2344);
    // 0x80060DFC: ori         $s2, $zero, 0x8000
    ctx->r18 = 0 | 0X8000;
    // 0x80060E00: lw          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_W(ctx->r16, 0X0));
L_80060E04:
    // 0x80060E04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80060E08: jal         0x80060B34
    // 0x80060E0C: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    func_80060B34(rdram, ctx);
        goto after_1;
    // 0x80060E0C: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    after_1:
    // 0x80060E10: lw          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80060E14: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x80060E18: addiu       $s1, $s1, -0x2338
    ctx->r17 = ADD32(ctx->r17, -0X2338);
    // 0x80060E1C: blezl       $a3, L_80060E80
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80060E20: lw          $ra, 0x34($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
            goto L_80060E80;
    }
    goto skip_4;
    // 0x80060E20: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    skip_4:
    // 0x80060E24: lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X0);
L_80060E28:
    // 0x80060E28: andi        $t7, $a3, 0x8000
    ctx->r15 = ctx->r7 & 0X8000;
    // 0x80060E2C: bne         $s2, $t7, L_80060E4C
    if (ctx->r18 != ctx->r15) {
        // 0x80060E30: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80060E4C;
    }
    // 0x80060E30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80060E34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80060E38: andi        $t8, $a0, 0x7FFF
    ctx->r24 = ctx->r4 & 0X7FFF;
    // 0x80060E3C: jal         0x80060EAC
    // 0x80060E40: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80060EAC(rdram, ctx);
        goto after_2;
    // 0x80060E40: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x80060E44: b           L_80060E68
    // 0x80060E48: lw          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_W(ctx->r16, 0X0));
        goto L_80060E68;
    // 0x80060E48: lw          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_W(ctx->r16, 0X0));
L_80060E4C:
    // 0x80060E4C: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x80060E50: jal         0x8006A62C
    // 0x80060E54: lw          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_W(ctx->r17, 0X4));
    func_8006A62C(rdram, ctx);
        goto after_3;
    // 0x80060E54: lw          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_W(ctx->r17, 0X4));
    after_3:
    // 0x80060E58: lw          $t9, 0x0($s5)
    ctx->r25 = S32(MEM_W(ctx->r21, 0X0));
    // 0x80060E5C: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80060E60: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x80060E64: lw          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_W(ctx->r16, 0X0));
L_80060E68:
    // 0x80060E68: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80060E6C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80060E70: slt         $at, $s3, $a3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80060E74: bnel        $at, $zero, L_80060E28
    if (ctx->r1 != 0) {
        // 0x80060E78: lhu         $a3, 0x0($s1)
        ctx->r7 = MEM_HU(ctx->r17, 0X0);
            goto L_80060E28;
    }
    goto skip_5;
    // 0x80060E78: lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X0);
    skip_5:
    // 0x80060E7C: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
L_80060E80:
    // 0x80060E80: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80060E84: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80060E88: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80060E8C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80060E90: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80060E94: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80060E98: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80060E9C: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80060EA0: sw          $a3, -0x13D4($at)
    MEM_W(-0X13D4, ctx->r1) = ctx->r7;
    // 0x80060EA4: jr          $ra
    // 0x80060EA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80060EA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80063AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063AE0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80063AE4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80063AE8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80063AEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80063AF0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80063AF4: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80063AF8: lhu         $v0, -0x4FFC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4FFC);
    // 0x80063AFC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80063B00: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80063B04: bne         $at, $zero, L_80063B24
    if (ctx->r1 != 0) {
        // 0x80063B08: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80063B24;
    }
    // 0x80063B08: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80063B0C: beq         $v0, $at, L_80063B9C
    if (ctx->r2 == ctx->r1) {
        // 0x80063B10: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_80063B9C;
    }
    // 0x80063B10: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80063B14: beq         $v0, $at, L_80063BA4
    if (ctx->r2 == ctx->r1) {
        // 0x80063B18: nop
    
            goto L_80063BA4;
    }
    // 0x80063B18: nop

    // 0x80063B1C: b           L_80063BB0
    // 0x80063B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80063BB0;
    // 0x80063B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063B24:
    // 0x80063B24: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x80063B28: bne         $at, $zero, L_80063B44
    if (ctx->r1 != 0) {
        // 0x80063B2C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80063B44;
    }
    // 0x80063B2C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80063B30: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80063B34: beq         $v0, $at, L_80063B94
    if (ctx->r2 == ctx->r1) {
        // 0x80063B38: nop
    
            goto L_80063B94;
    }
    // 0x80063B38: nop

    // 0x80063B3C: b           L_80063BB0
    // 0x80063B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80063BB0;
    // 0x80063B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063B44:
    // 0x80063B44: sltiu       $at, $t8, 0x20
    ctx->r1 = ctx->r24 < 0X20 ? 1 : 0;
    // 0x80063B48: beq         $at, $zero, L_80063BAC
    if (ctx->r1 == 0) {
        // 0x80063B4C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80063BAC;
    }
    // 0x80063B4C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80063B50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80063B54: addu        $at, $at, $t8
    gpr jr_addend_80063B5C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80063B58: lw          $t8, 0x4CE4($at)
    ctx->r24 = ADD32(ctx->r1, 0X4CE4);
    // 0x80063B5C: jr          $t8
    // 0x80063B60: nop

    switch (jr_addend_80063B5C >> 2) {
        case 0: goto L_80063B64; break;
        case 1: goto L_80063B6C; break;
        case 2: goto L_80063BAC; break;
        case 3: goto L_80063B74; break;
        case 4: goto L_80063BAC; break;
        case 5: goto L_80063BAC; break;
        case 6: goto L_80063BAC; break;
        case 7: goto L_80063B7C; break;
        case 8: goto L_80063BAC; break;
        case 9: goto L_80063BAC; break;
        case 10: goto L_80063BAC; break;
        case 11: goto L_80063BAC; break;
        case 12: goto L_80063BAC; break;
        case 13: goto L_80063BAC; break;
        case 14: goto L_80063BAC; break;
        case 15: goto L_80063B84; break;
        case 16: goto L_80063BAC; break;
        case 17: goto L_80063BAC; break;
        case 18: goto L_80063BAC; break;
        case 19: goto L_80063BAC; break;
        case 20: goto L_80063BAC; break;
        case 21: goto L_80063BAC; break;
        case 22: goto L_80063BAC; break;
        case 23: goto L_80063BAC; break;
        case 24: goto L_80063BAC; break;
        case 25: goto L_80063BAC; break;
        case 26: goto L_80063BAC; break;
        case 27: goto L_80063BAC; break;
        case 28: goto L_80063BAC; break;
        case 29: goto L_80063BAC; break;
        case 30: goto L_80063BAC; break;
        case 31: goto L_80063B8C; break;
        default: switch_error(__func__, 0x80063B5C, 0x80104CE4);
    }
    // 0x80063B60: nop

L_80063B64:
    // 0x80063B64: jr          $ra
    // 0x80063B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80063B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063B6C:
    // 0x80063B6C: jr          $ra
    // 0x80063B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80063B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80063B74:
    // 0x80063B74: jr          $ra
    // 0x80063B78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80063B78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80063B7C:
    // 0x80063B7C: jr          $ra
    // 0x80063B80: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80063B80: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80063B84:
    // 0x80063B84: jr          $ra
    // 0x80063B88: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80063B88: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80063B8C:
    // 0x80063B8C: jr          $ra
    // 0x80063B90: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80063B90: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80063B94:
    // 0x80063B94: jr          $ra
    // 0x80063B98: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x80063B98: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80063B9C:
    // 0x80063B9C: jr          $ra
    // 0x80063BA0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x80063BA0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80063BA4:
    // 0x80063BA4: jr          $ra
    // 0x80063BA8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80063BA8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80063BAC:
    // 0x80063BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063BB0:
    // 0x80063BB0: jr          $ra
    // 0x80063BB4: nop

    return;
    // 0x80063BB4: nop

;}
RECOMP_FUNC void func_8005857C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005857C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058584: jal         0x80058348
    // 0x80058588: nop

    func_80058348(rdram, ctx);
        goto after_0;
    // 0x80058588: nop

    after_0:
    // 0x8005858C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058590: beq         $v0, $at, L_800585C4
    if (ctx->r2 == ctx->r1) {
        // 0x80058594: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800585C4;
    }
    // 0x80058594: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80058598: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8005859C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800585A0: addiu       $t7, $t7, -0x5F08
    ctx->r15 = ADD32(ctx->r15, -0X5F08);
    // 0x800585A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800585A8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800585AC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800585B0: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800585B4: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x800585B8: addiu       $a0, $a0, -0x5FA0
    ctx->r4 = ADD32(ctx->r4, -0X5FA0);
    // 0x800585BC: jal         0x800BB610
    // 0x800585C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800585C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_800585C4:
    // 0x800585C4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800585C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800585CC: jr          $ra
    // 0x800585D0: nop

    return;
    // 0x800585D0: nop

;}
RECOMP_FUNC void func_80070274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80070278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007027C: jal         0x800700F0
    // 0x80070280: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_0;
    // 0x80070280: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80070284: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x80070288: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    // 0x8007028C: jal         0x800700F0
    // 0x80070290: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_1;
    // 0x80070290: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80070294: bne         $v0, $zero, L_800702A4
    if (ctx->r2 != 0) {
        // 0x80070298: nop
    
            goto L_800702A4;
    }
    // 0x80070298: nop

    // 0x8007029C: b           L_800702C4
    // 0x800702A0: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
        goto L_800702C4;
    // 0x800702A0: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
L_800702A4:
    // 0x800702A4: jal         0x800700F0
    // 0x800702A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_2;
    // 0x800702A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800702AC: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x800702B0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800702B4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800702B8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800702BC: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x800702C0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800702C4:
    // 0x800702C4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800702C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800702CC: jr          $ra
    // 0x800702D0: nop

    return;
    // 0x800702D0: nop

;}
RECOMP_FUNC void guLookAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3678: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800C367C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X80));
    // 0x800C3680: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C3684: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C3688: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800C368C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C3690: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X94));
    // 0x800C3694: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X84));
    // 0x800C3698: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X88));
    // 0x800C369C: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800C36A0: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = S32(MEM_W(ctx->r29, 0X90));
    // 0x800C36A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C36A8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800C36AC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C36B0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800C36B4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800C36B8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800C36BC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800C36C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C36C4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C36C8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800C36CC: jal         0x800C33C0
    // 0x800C36D0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    guLookAtF(rdram, ctx);
        goto after_0;
    // 0x800C36D0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800C36D4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800C36D8: jal         0x800C8AC0
    // 0x800C36DC: lw          $a1, 0x70($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X70));
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800C36DC: lw          $a1, 0x70($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X70));
    after_1:
    // 0x800C36E0: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800C36E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800C36E8: jr          $ra
    // 0x800C36EC: nop

    return;
    // 0x800C36EC: nop

;}
RECOMP_FUNC void func_8004C65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C65C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8004C660: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8004C664: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8004C668: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8004C66C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004C670: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004C674: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004C678: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004C67C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8004C680: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8004C684: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004C688: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004C68C: addiu       $s3, $a0, 0x40
    ctx->r19 = ADD32(ctx->r4, 0X40);
    // 0x8004C690: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
    // 0x8004C694: addiu       $s5, $zero, 0x29A
    ctx->r21 = ADD32(0, 0X29A);
    // 0x8004C698: addiu       $s6, $zero, 0x29B
    ctx->r22 = ADD32(0, 0X29B);
    // 0x8004C69C: addiu       $s7, $zero, 0x29C
    ctx->r23 = ADD32(0, 0X29C);
    // 0x8004C6A0: addiu       $fp, $zero, 0x29D
    ctx->r30 = ADD32(0, 0X29D);
    // 0x8004C6A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8004C6A8:
    // 0x8004C6A8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8004C6AC: jal         0x800BB440
    // 0x8004C6B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8004C6B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8004C6B4: lw          $v0, 0x54($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8004C6B8: beq         $v0, $s5, L_8004C6E0
    if (ctx->r2 == ctx->r21) {
        // 0x8004C6BC: nop
    
            goto L_8004C6E0;
    }
    // 0x8004C6BC: nop

    // 0x8004C6C0: beq         $v0, $s6, L_8004C6F0
    if (ctx->r2 == ctx->r22) {
        // 0x8004C6C4: nop
    
            goto L_8004C6F0;
    }
    // 0x8004C6C4: nop

    // 0x8004C6C8: beq         $v0, $s7, L_8004C700
    if (ctx->r2 == ctx->r23) {
        // 0x8004C6CC: nop
    
            goto L_8004C700;
    }
    // 0x8004C6CC: nop

    // 0x8004C6D0: beql        $v0, $fp, L_8004C714
    if (ctx->r2 == ctx->r30) {
        // 0x8004C6D4: lw          $s0, 0x260($s2)
        ctx->r16 = S32(MEM_W(ctx->r18, 0X260));
            goto L_8004C714;
    }
    goto skip_0;
    // 0x8004C6D4: lw          $s0, 0x260($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X260));
    skip_0:
    // 0x8004C6D8: b           L_8004C6A8
    // 0x8004C6DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_8004C6A8;
    // 0x8004C6DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8004C6E0:
    // 0x8004C6E0: jal         0x8004C780
    // 0x8004C6E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_5_8004C780(rdram, ctx);
        goto after_1;
    // 0x8004C6E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8004C6E8: b           L_8004C6A8
    // 0x8004C6EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_8004C6A8;
    // 0x8004C6EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8004C6F0:
    // 0x8004C6F0: jal         0x8004C8A0
    // 0x8004C6F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_5_8004C8A0(rdram, ctx);
        goto after_2;
    // 0x8004C6F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8004C6F8: b           L_8004C6A8
    // 0x8004C6FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_8004C6A8;
    // 0x8004C6FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8004C700:
    // 0x8004C700: jal         0x8004CA04
    // 0x8004C704: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    static_5_8004CA04(rdram, ctx);
        goto after_3;
    // 0x8004C704: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8004C708: b           L_8004C6A8
    // 0x8004C70C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_8004C6A8;
    // 0x8004C70C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8004C710: lw          $s0, 0x260($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X260));
L_8004C714:
    // 0x8004C714: addiu       $s1, $s2, 0x20
    ctx->r17 = ADD32(ctx->r18, 0X20);
    // 0x8004C718: beql        $s0, $zero, L_8004C6A8
    if (ctx->r16 == 0) {
        // 0x8004C71C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8004C6A8;
    }
    goto skip_1;
    // 0x8004C71C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
    // 0x8004C720: lw          $a0, 0x4($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X4));
L_8004C724:
    // 0x8004C724: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004C728: jal         0x800BB610
    // 0x8004C72C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8004C72C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8004C730: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004C734: bnel        $s0, $zero, L_8004C724
    if (ctx->r16 != 0) {
        // 0x8004C738: lw          $a0, 0x4($s0)
        ctx->r4 = S32(MEM_W(ctx->r16, 0X4));
            goto L_8004C724;
    }
    goto skip_2;
    // 0x8004C738: lw          $a0, 0x4($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X4));
    skip_2:
    // 0x8004C73C: b           L_8004C6A8
    // 0x8004C740: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_8004C6A8;
    // 0x8004C740: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8004C744: nop

    // 0x8004C748: nop

    // 0x8004C74C: nop

    // 0x8004C750: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8004C754: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004C758: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004C75C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004C760: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8004C764: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8004C768: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8004C76C: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8004C770: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8004C774: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8004C778: jr          $ra
    // 0x8004C77C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8004C77C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800C0EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0EDC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800C0EE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C0EE4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C0EE8: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x800C0EEC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C0EF0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C0EF4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C0EF8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C0EFC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C0F00: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C0F04: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C0F08: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C0F0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C0F10: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C0F14: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800C0F18: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_800C0F1C:
    // 0x800C0F1C: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x800C0F20: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800C0F24: beq         $at, $zero, L_800C149C
    if (ctx->r1 == 0) {
        // 0x800C0F28: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C149C;
    }
    // 0x800C0F28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0F2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C0F30: addu        $at, $at, $t7
    gpr jr_addend_800C0F38 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C0F34: lw          $t7, -0x651C($at)
    ctx->r15 = ADD32(ctx->r1, -0X651C);
    // 0x800C0F38: jr          $t7
    // 0x800C0F3C: nop

    switch (jr_addend_800C0F38 >> 2) {
        case 0: goto L_800C0F40; break;
        case 1: goto L_800C149C; break;
        case 2: goto L_800C1270; break;
        case 3: goto L_800C149C; break;
        case 4: goto L_800C149C; break;
        case 5: goto L_800C102C; break;
        case 6: goto L_800C1078; break;
        case 7: goto L_800C128C; break;
        case 8: goto L_800C149C; break;
        case 9: goto L_800C100C; break;
        case 10: goto L_800C12AC; break;
        case 11: goto L_800C149C; break;
        case 12: goto L_800C143C; break;
        case 13: goto L_800C1458; break;
        case 14: goto L_800C148C; break;
        case 15: goto L_800C1310; break;
        case 16: goto L_800C1334; break;
        case 17: goto L_800C13A0; break;
        case 18: goto L_800C149C; break;
        case 19: goto L_800C149C; break;
        case 20: goto L_800C149C; break;
        case 21: goto L_800C1270; break;
        case 22: goto L_800C10DC; break;
        case 23: goto L_800C11E8; break;
        default: switch_error(__func__, 0x800C0F38, 0x80109AE4);
    }
    // 0x800C0F3C: nop

L_800C0F40:
    // 0x800C0F40: lw          $a0, 0x18($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X18));
    // 0x800C0F44: beql        $a0, $zero, L_800C14A0
    if (ctx->r4 == 0) {
        // 0x800C0F48: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C14A0;
    }
    goto skip_0;
    // 0x800C0F48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x800C0F4C: jal         0x800C1B44
    // 0x800C0F50: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    alCSeqNextEvent(rdram, ctx);
        goto after_0;
    // 0x800C0F50: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x800C0F54: lh          $t8, 0x58($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X58));
    // 0x800C0F58: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C0F5C: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x800C0F60: beq         $at, $zero, L_800C149C
    if (ctx->r1 == 0) {
        // 0x800C0F64: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800C149C;
    }
    // 0x800C0F64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C0F68: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C0F6C: addu        $at, $at, $t9
    gpr jr_addend_800C0F74 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C0F70: lw          $t9, -0x64BC($at)
    ctx->r25 = ADD32(ctx->r1, -0X64BC);
    // 0x800C0F74: jr          $t9
    // 0x800C0F78: nop

    switch (jr_addend_800C0F74 >> 2) {
        case 0: goto L_800C0F7C; break;
        case 1: goto L_800C149C; break;
        case 2: goto L_800C0FA4; break;
        case 3: goto L_800C0FD0; break;
        case 4: goto L_800C149C; break;
        case 5: goto L_800C149C; break;
        case 6: goto L_800C149C; break;
        case 7: goto L_800C149C; break;
        case 8: goto L_800C149C; break;
        case 9: goto L_800C149C; break;
        case 10: goto L_800C149C; break;
        case 11: goto L_800C149C; break;
        case 12: goto L_800C149C; break;
        case 13: goto L_800C149C; break;
        case 14: goto L_800C149C; break;
        case 15: goto L_800C149C; break;
        case 16: goto L_800C149C; break;
        case 17: goto L_800C0FFC; break;
        case 18: goto L_800C0FFC; break;
        case 19: goto L_800C0FFC; break;
        default: switch_error(__func__, 0x800C0F74, 0x80109B44);
    }
    // 0x800C0F78: nop

L_800C0F7C:
    // 0x800C0F7C: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x800C0F80: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C0F84: jal         0x800C06AC
    // 0x800C0F88: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_5_800C06AC(rdram, ctx);
        goto after_1;
    // 0x800C0F88: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_1:
    // 0x800C0F8C: lw          $s2, 0xA0($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C0F90: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800C0F94: jal         0x800C0430
    // 0x800C0F98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_2;
    // 0x800C0F98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800C0F9C: b           L_800C14A0
    // 0x800C0FA0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C0FA0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C0FA4:
    // 0x800C0FA4: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x800C0FA8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800C0FAC: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C0FB0: jal         0x800C04DC
    // 0x800C0FB4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_5_800C04DC(rdram, ctx);
        goto after_3;
    // 0x800C0FB4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_3:
    // 0x800C0FB8: lw          $s2, 0xA0($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C0FBC: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800C0FC0: jal         0x800C0430
    // 0x800C0FC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_4;
    // 0x800C0FC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x800C0FC8: b           L_800C14A0
    // 0x800C0FCC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C0FCC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C0FD0:
    // 0x800C0FD0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C0FD4: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x800C0FD8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C0FDC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800C0FE0: sh          $t7, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r15;
    // 0x800C0FE4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800C0FE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C0FEC: jal         0x800C9C6C
    // 0x800C0FF0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x800C0FF0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x800C0FF4: b           L_800C14A0
    // 0x800C0FF8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C0FF8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C0FFC:
    // 0x800C0FFC: jal         0x800C0430
    // 0x800C1000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_6;
    // 0x800C1000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800C1004: b           L_800C14A0
    // 0x800C1008: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1008: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C100C:
    // 0x800C100C: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800C1010: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C1014: lw          $a2, 0x5C($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X5C));
    // 0x800C1018: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C101C: jal         0x800C9C6C
    // 0x800C1020: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x800C1020: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_7:
    // 0x800C1024: b           L_800C14A0
    // 0x800C1028: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1028: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C102C:
    // 0x800C102C: lw          $s0, 0x3C($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C1030: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C1034: jal         0x800CA400
    // 0x800C1038: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_8;
    // 0x800C1038: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800C103C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C1040: jal         0x800CA480
    // 0x800C1044: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_9;
    // 0x800C1044: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800C1048: lw          $s1, 0x10($s0)
    ctx->r17 = S32(MEM_W(ctx->r16, 0X10));
    // 0x800C104C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1050: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x800C1054: beql        $t9, $zero, L_800C1068
    if (ctx->r25 == 0) {
        // 0x800C1058: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C1068;
    }
    goto skip_1;
    // 0x800C1058: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x800C105C: jal         0x800CBB70
    // 0x800C1060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_10;
    // 0x800C1060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x800C1064: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C1068:
    // 0x800C1068: jal         0x800CA940
    // 0x800C106C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_11;
    // 0x800C106C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x800C1070: b           L_800C14A0
    // 0x800C1074: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1074: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C1078:
    // 0x800C1078: lw          $s0, 0x3C($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C107C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C1080: lw          $s1, 0x10($s0)
    ctx->r17 = S32(MEM_W(ctx->r16, 0X10));
    // 0x800C1084: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x800C1088: bnel        $t6, $zero, L_800C1098
    if (ctx->r14 != 0) {
        // 0x800C108C: lw          $s3, 0x40($s2)
        ctx->r19 = S32(MEM_W(ctx->r18, 0X40));
            goto L_800C1098;
    }
    goto skip_2;
    // 0x800C108C: lw          $s3, 0x40($s2)
    ctx->r19 = S32(MEM_W(ctx->r18, 0X40));
    skip_2:
    // 0x800C1090: sb          $t7, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r15;
    // 0x800C1094: lw          $s3, 0x40($s2)
    ctx->r19 = S32(MEM_W(ctx->r18, 0X40));
L_800C1098:
    // 0x800C1098: lw          $t8, 0x1C($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X1C));
    // 0x800C109C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C10A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C10A4: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x800C10A8: sw          $t9, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r25;
    // 0x800C10AC: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    // 0x800C10B0: jal         0x800CA6E4
    // 0x800C10B4: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    __vsVol(rdram, ctx);
        goto after_12;
    // 0x800C10B4: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    after_12:
    // 0x800C10B8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800C10BC: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C10C0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C10C4: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C10C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C10CC: jal         0x800CA230
    // 0x800C10D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    alSynSetVol(rdram, ctx);
        goto after_13;
    // 0x800C10D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_13:
    // 0x800C10D4: b           L_800C14A0
    // 0x800C10D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C10D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C10DC:
    // 0x800C10DC: lw          $t9, 0x74($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X74));
    // 0x800C10E0: lw          $s4, 0x40($s2)
    ctx->r20 = S32(MEM_W(ctx->r18, 0X40));
    // 0x800C10E4: lw          $s1, 0x3C($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C10E8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800C10EC: jalr        $t9
    // 0x800C10F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x800C10F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x800C10F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C10F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C10FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C1100: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X78));
    // 0x800C1104: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C1108: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C110C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C1110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C1114: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C1118: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C111C: nop

    // 0x800C1120: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800C1124: beql        $t6, $zero, L_800C1174
    if (ctx->r14 == 0) {
        // 0x800C1128: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_800C1174;
    }
    goto skip_3;
    // 0x800C1128: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800C112C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C1130: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C1134: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C1138: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C113C: nop

    // 0x800C1140: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C1144: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C1148: nop

    // 0x800C114C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800C1150: bne         $t6, $zero, L_800C1168
    if (ctx->r14 != 0) {
        // 0x800C1154: nop
    
            goto L_800C1168;
    }
    // 0x800C1154: nop

    // 0x800C1158: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800C115C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C1160: b           L_800C1180
    // 0x800C1164: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800C1180;
    // 0x800C1164: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800C1168:
    // 0x800C1168: b           L_800C1180
    // 0x800C116C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800C1180;
    // 0x800C116C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C1170: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_800C1174:
    // 0x800C1174: nop

    // 0x800C1178: bltz        $t6, L_800C1168
    if (SIGNED(ctx->r14) < 0) {
        // 0x800C117C: nop
    
            goto L_800C1168;
    }
    // 0x800C117C: nop

L_800C1180:
    // 0x800C1180: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C1184: jal         0x800CA6E4
    // 0x800C1188: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    __vsVol(rdram, ctx);
        goto after_15;
    // 0x800C1188: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    after_15:
    // 0x800C118C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800C1190: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800C1194: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C1198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C119C: jal         0x800CA6C0
    // 0x800C11A0: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    __vsDelta(rdram, ctx);
        goto after_16;
    // 0x800C11A0: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    after_16:
    // 0x800C11A4: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800C11A8: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C11AC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C11B0: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C11B4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C11B8: jal         0x800CA230
    // 0x800C11BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x800C11BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_17:
    // 0x800C11C0: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800C11C4: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C11C8: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x800C11CC: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x800C11D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C11D4: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C11D8: jal         0x800C9C6C
    // 0x800C11DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x800C11DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_18:
    // 0x800C11E0: b           L_800C14A0
    // 0x800C11E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C11E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C11E8:
    // 0x800C11E8: lw          $t9, 0x74($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X74));
    // 0x800C11EC: lw          $s4, 0x40($s2)
    ctx->r20 = S32(MEM_W(ctx->r18, 0X40));
    // 0x800C11F0: lw          $s1, 0x3C($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C11F4: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x800C11F8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800C11FC: jalr        $t9
    // 0x800C1200: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x800C1200: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_19:
    // 0x800C1204: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X78));
    // 0x800C1208: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = S32(MEM_W(ctx->r17, 0X28));
    // 0x800C120C: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x800C1210: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x800C1214: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = S32(MEM_W(ctx->r17, 0X2C));
    // 0x800C1218: lw          $t6, 0x60($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C121C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C1220: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C1224: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C1228: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = S32(MEM_W(ctx->r24, 0XC));
    // 0x800C122C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C1230: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C1234: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800C1238: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C123C: jal         0x800CA2D0
    // 0x800C1240: nop

    alSynSetPitch(rdram, ctx);
        goto after_20;
    // 0x800C1240: nop

    after_20:
    // 0x800C1244: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x800C1248: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x800C124C: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x800C1250: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x800C1254: sb          $s0, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r16;
    // 0x800C1258: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C125C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C1260: jal         0x800C9C6C
    // 0x800C1264: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_21;
    // 0x800C1264: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_21:
    // 0x800C1268: b           L_800C14A0
    // 0x800C126C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C126C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C1270:
    // 0x800C1270: lw          $t0, 0x50($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800C1274: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C1278: jal         0x800C06AC
    // 0x800C127C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_5_800C06AC(rdram, ctx);
        goto after_22;
    // 0x800C127C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_22:
    // 0x800C1280: lw          $s2, 0xA0($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C1284: b           L_800C149C
    // 0x800C1288: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800C149C;
    // 0x800C1288: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
L_800C128C:
    // 0x800C128C: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x800C1290: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800C1294: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C1298: jal         0x800C04DC
    // 0x800C129C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_5_800C04DC(rdram, ctx);
        goto after_23;
    // 0x800C129C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_23:
    // 0x800C12A0: lw          $s2, 0xA0($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C12A4: b           L_800C149C
    // 0x800C12A8: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800C149C;
    // 0x800C12A8: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
L_800C12AC:
    // 0x800C12AC: lw          $s1, 0x64($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C12B0: lh          $t6, 0x3C($s2)
    ctx->r14 = S32(MEM_H(ctx->r18, 0X3C));
    // 0x800C12B4: beq         $s1, $zero, L_800C149C
    if (ctx->r17 == 0) {
        // 0x800C12B8: sh          $t6, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r14;
            goto L_800C149C;
    }
    // 0x800C12B8: sh          $t6, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r14;
    // 0x800C12BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800C12C0:
    // 0x800C12C0: jal         0x800CA6E4
    // 0x800C12C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_24;
    // 0x800C12C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x800C12C8: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800C12CC: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800C12D0: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C12D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C12D8: jal         0x800CA6C0
    // 0x800C12DC: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    __vsDelta(rdram, ctx);
        goto after_25;
    // 0x800C12DC: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    after_25:
    // 0x800C12E0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800C12E4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C12E8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C12EC: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C12F0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C12F4: jal         0x800CA230
    // 0x800C12F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_26;
    // 0x800C12F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x800C12FC: lw          $s1, 0x0($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C1300: bnel        $s1, $zero, L_800C12C0
    if (ctx->r17 != 0) {
        // 0x800C1304: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C12C0;
    }
    goto skip_4;
    // 0x800C1304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x800C1308: b           L_800C14A0
    // 0x800C130C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C130C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C1310:
    // 0x800C1310: lw          $t9, 0x2C($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X2C));
    // 0x800C1314: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C1318: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C131C: beq         $t9, $at, L_800C149C
    if (ctx->r25 == ctx->r1) {
        // 0x800C1320: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C149C;
    }
    // 0x800C1320: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1324: jal         0x800C0430
    // 0x800C1328: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_27;
    // 0x800C1328: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    after_27:
    // 0x800C132C: b           L_800C14A0
    // 0x800C1330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C1334:
    // 0x800C1334: lw          $t7, 0x2C($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X2C));
    // 0x800C1338: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C133C: bnel        $t7, $at, L_800C14A0
    if (ctx->r15 != ctx->r1) {
        // 0x800C1340: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C14A0;
    }
    goto skip_5;
    // 0x800C1340: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_5:
    // 0x800C1344: lw          $s1, 0x64($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C1348: beq         $s1, $zero, L_800C1398
    if (ctx->r17 == 0) {
        // 0x800C134C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C1398;
    }
    // 0x800C134C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800C1350:
    // 0x800C1350: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C1354: jal         0x800CA400
    // 0x800C1358: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    alSynStopVoice(rdram, ctx);
        goto after_28;
    // 0x800C1358: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    after_28:
    // 0x800C135C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C1360: jal         0x800CA480
    // 0x800C1364: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_29;
    // 0x800C1364: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_29:
    // 0x800C1368: lbu         $t8, 0x37($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X37);
    // 0x800C136C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1370: beql        $t8, $zero, L_800C1384
    if (ctx->r24 == 0) {
        // 0x800C1374: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C1384;
    }
    goto skip_6;
    // 0x800C1374: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
    // 0x800C1378: jal         0x800CBB70
    // 0x800C137C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_30;
    // 0x800C137C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_30:
    // 0x800C1380: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C1384:
    // 0x800C1384: jal         0x800CA940
    // 0x800C1388: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_31;
    // 0x800C1388: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_31:
    // 0x800C138C: lw          $s1, 0x64($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C1390: bnel        $s1, $zero, L_800C1350
    if (ctx->r17 != 0) {
        // 0x800C1394: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C1350;
    }
    goto skip_7;
    // 0x800C1394: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_7:
L_800C1398:
    // 0x800C1398: b           L_800C149C
    // 0x800C139C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_800C149C;
    // 0x800C139C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_800C13A0:
    // 0x800C13A0: lw          $t9, 0x2C($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X2C));
    // 0x800C13A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C13A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C13AC: bnel        $t9, $at, L_800C14A0
    if (ctx->r25 != ctx->r1) {
        // 0x800C13B0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C14A0;
    }
    goto skip_8;
    // 0x800C13B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_8:
    // 0x800C13B4: jal         0x800C9B50
    // 0x800C13B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_32;
    // 0x800C13B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x800C13BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C13C0: jal         0x800C9B50
    // 0x800C13C4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    alEvtqFlushType(rdram, ctx);
        goto after_33;
    // 0x800C13C4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_33:
    // 0x800C13C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C13CC: jal         0x800C9B50
    // 0x800C13D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_34;
    // 0x800C13D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
    // 0x800C13D4: lw          $s1, 0x64($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C13D8: beq         $s1, $zero, L_800C1410
    if (ctx->r17 == 0) {
        // 0x800C13DC: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C1410;
    }
    // 0x800C13DC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800C13E0:
    // 0x800C13E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C13E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C13E8: jal         0x800CA898
    // 0x800C13EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __voiceNeedsNoteKill(rdram, ctx);
        goto after_35;
    // 0x800C13EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_35:
    // 0x800C13F0: beq         $v0, $zero, L_800C1404
    if (ctx->r2 == 0) {
        // 0x800C13F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C1404;
    }
    // 0x800C13F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C13F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C13FC: jal         0x800CA76C
    // 0x800C1400: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __seqpReleaseVoice(rdram, ctx);
        goto after_36;
    // 0x800C1400: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_36:
L_800C1404:
    // 0x800C1404: lw          $s1, 0x0($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C1408: bnel        $s1, $zero, L_800C13E0
    if (ctx->r17 != 0) {
        // 0x800C140C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C13E0;
    }
    goto skip_9;
    // 0x800C140C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_9:
L_800C1410:
    // 0x800C1410: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C1414: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x800C1418: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C141C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800C1420: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x800C1424: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800C1428: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C142C: jal         0x800C9C6C
    // 0x800C1430: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    alEvtqPostEvent(rdram, ctx);
        goto after_37;
    // 0x800C1430: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_37:
    // 0x800C1434: b           L_800C14A0
    // 0x800C1438: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1438: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C143C:
    // 0x800C143C: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x800C1440: lw          $t9, 0x60($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C1444: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x800C1448: sll         $t6, $s0, 4
    ctx->r14 = S32(ctx->r16 << 4);
    // 0x800C144C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800C1450: b           L_800C149C
    // 0x800C1454: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_800C149C;
    // 0x800C1454: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_800C1458:
    // 0x800C1458: lw          $t9, 0x3C($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C145C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C1460: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1464: sw          $t9, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r25;
    // 0x800C1468: jal         0x800C04A0
    // 0x800C146C: lwc1        $f12, -0x646C($at)
    ctx->f12.u32l = S32(MEM_W(ctx->r1, -0X646C));
    static_5_800C04A0(rdram, ctx);
        goto after_38;
    // 0x800C146C: lwc1        $f12, -0x646C($at)
    ctx->f12.u32l = S32(MEM_W(ctx->r1, -0X646C));
    after_38:
    // 0x800C1470: lw          $a1, 0x20($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X20));
    // 0x800C1474: beql        $a1, $zero, L_800C14A0
    if (ctx->r5 == 0) {
        // 0x800C1478: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C14A0;
    }
    goto skip_10;
    // 0x800C1478: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_10:
    // 0x800C147C: jal         0x800CA604
    // 0x800C1480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __initFromBank(rdram, ctx);
        goto after_39;
    // 0x800C1480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_39:
    // 0x800C1484: b           L_800C14A0
    // 0x800C1488: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1488: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C148C:
    // 0x800C148C: lw          $a1, 0x3C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C1490: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1494: jal         0x800CA604
    // 0x800C1498: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_40;
    // 0x800C1498: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_40:
L_800C149C:
    // 0x800C149C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C14A0:
    // 0x800C14A0: jal         0x800C9D90
    // 0x800C14A4: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    alEvtqNextEvent(rdram, ctx);
        goto after_41;
    // 0x800C14A4: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    after_41:
    // 0x800C14A8: beq         $v0, $zero, L_800C0F1C
    if (ctx->r2 == 0) {
        // 0x800C14AC: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_800C0F1C;
    }
    // 0x800C14AC: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x800C14B0: lw          $t6, 0x1C($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X1C));
    // 0x800C14B4: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C14B8: sw          $t8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r24;
    // 0x800C14BC: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800C14C0: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800C14C4: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800C14C8: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C14CC: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800C14D0: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800C14D4: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800C14D8: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800C14DC: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C14E0: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C14E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C14E8: jr          $ra
    // 0x800C14EC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800C14EC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800BFABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFABC: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800BFAC0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800BFAC4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800BFAC8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800BFACC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800BFAD0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800BFAD4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BFAD8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800BFADC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800BFAE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800BFAE4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800BFAE8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800BFAEC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800BFAF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800BFAF4: ldc1        $f20, -0x66E0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X66E0);
    // 0x800BFAF8: addiu       $s4, $a0, 0x28
    ctx->r20 = ADD32(ctx->r4, 0X28);
    // 0x800BFAFC: addiu       $s7, $a0, 0x14
    ctx->r23 = ADD32(ctx->r4, 0X14);
    // 0x800BFB00: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800BFB04:
    // 0x800BFB04: lh          $v0, 0x28($s6)
    ctx->r2 = S32(MEM_H(ctx->r22, 0X28));
    // 0x800BFB08: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800BFB0C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800BFB10: bne         $v0, $at, L_800BFB30
    if (ctx->r2 != ctx->r1) {
        // 0x800BFB14: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFB30;
    }
    // 0x800BFB14: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800BFB18: sh          $t6, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r14;
    // 0x800BFB1C: lw          $a2, 0x48($s6)
    ctx->r6 = S32(MEM_W(ctx->r22, 0X48));
    // 0x800BFB20: jal         0x800C9C6C
    // 0x800BFB24: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800BFB24: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    after_0:
    // 0x800BFB28: b           L_800BFFB4
    // 0x800BFB2C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFB2C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFB30:
    // 0x800BFB30: lw          $s5, 0x2C($s6)
    ctx->r21 = S32(MEM_W(ctx->r22, 0X2C));
    // 0x800BFB34: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x800BFB38: beq         $at, $zero, L_800BFFB0
    if (ctx->r1 == 0) {
        // 0x800BFB3C: lw          $s1, 0x1C($s5)
        ctx->r17 = S32(MEM_W(ctx->r21, 0X1C));
            goto L_800BFFB0;
    }
    // 0x800BFB3C: lw          $s1, 0x1C($s5)
    ctx->r17 = S32(MEM_W(ctx->r21, 0X1C));
    // 0x800BFB40: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800BFB44: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BFB48: addu        $at, $at, $t7
    gpr jr_addend_800BFB50 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BFB4C: lw          $t7, -0x66D8($at)
    ctx->r15 = ADD32(ctx->r1, -0X66D8);
    // 0x800BFB50: jr          $t7
    // 0x800BFB54: nop

    switch (jr_addend_800BFB50 >> 2) {
        case 0: goto L_800BFB58; break;
        case 1: goto L_800BFCC0; break;
        case 2: goto L_800BFD8C; break;
        case 3: goto L_800BFE70; break;
        case 4: goto L_800BFDF4; break;
        case 5: goto L_800BFFB0; break;
        case 6: goto L_800BFED4; break;
        case 7: goto L_800BFF80; break;
        case 8: goto L_800BFE48; break;
        default: switch_error(__func__, 0x800BFB50, 0x80109928);
    }
    // 0x800BFB54: nop

L_800BFB58:
    // 0x800BFB58: lw          $t8, 0x28($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFB5C: bnel        $t8, $zero, L_800BFFB4
    if (ctx->r24 != 0) {
        // 0x800BFB60: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_0;
    // 0x800BFB60: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_0:
    // 0x800BFB64: beq         $s1, $zero, L_800BFFB0
    if (ctx->r17 == 0) {
        // 0x800BFB68: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800BFFB0;
    }
    // 0x800BFB68: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFB6C: sh          $zero, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = 0;
    // 0x800BFB70: lh          $t9, 0x20($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0X20));
    // 0x800BFB74: sb          $zero, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = 0;
    // 0x800BFB78: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x800BFB7C: sh          $t9, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r25;
    // 0x800BFB80: jal         0x800C9FC8
    // 0x800BFB84: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    alSynAllocVoice(rdram, ctx);
        goto after_1;
    // 0x800BFB84: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    after_1:
    // 0x800BFB88: lw          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFB8C: lh          $t7, 0x2C($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X2C));
    // 0x800BFB90: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800BFB94: lbu         $t6, 0xC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XC);
    // 0x800BFB98: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800BFB9C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFBA0: mflo        $t8
    ctx->r24 = lo;
    // 0x800BFBA4: nop

    // 0x800BFBA8: nop

    // 0x800BFBAC: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800BFBB0: mflo        $t9
    ctx->r25 = lo;
    // 0x800BFBB4: sh          $t9, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r25;
    // 0x800BFBB8: lbu         $t7, 0xC($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XC);
    // 0x800BFBBC: lbu         $t6, 0x2E($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X2E);
    // 0x800BFBC0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800BFBC4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800BFBC8: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x800BFBCC: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800BFBD0: bgtzl       $v1, L_800BFBE0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800BFBD4: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800BFBE0;
    }
    goto skip_1;
    // 0x800BFBD4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_1:
    // 0x800BFBD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BFBDC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800BFBE0:
    // 0x800BFBE0: beq         $at, $zero, L_800BFBF0
    if (ctx->r1 == 0) {
        // 0x800BFBE4: nop
    
            goto L_800BFBF0;
    }
    // 0x800BFBE4: nop

    // 0x800BFBE8: b           L_800BFBF0
    // 0x800BFBEC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_800BFBF0;
    // 0x800BFBEC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_800BFBF0:
    // 0x800BFBF0: lwc1        $f4, 0x24($s5)
    ctx->f4.u32l = S32(MEM_W(ctx->r21, 0X24));
    // 0x800BFBF4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFBF8: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x800BFBFC: lw          $s0, 0x0($a3)
    ctx->r16 = S32(MEM_W(ctx->r7, 0X0));
    // 0x800BFC00: lw          $a2, 0x8($s1)
    ctx->r6 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800BFC04: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC08: jal         0x800CA110
    // 0x800BFC0C: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    alSynStartVoice(rdram, ctx);
        goto after_2;
    // 0x800BFC0C: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    after_2:
    // 0x800BFC10: lbu         $a2, 0xD7($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD7);
    // 0x800BFC14: sw          $fp, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r30;
    // 0x800BFC18: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC1C: jal         0x800CA1A0
    // 0x800BFC20: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynSetPan(rdram, ctx);
        goto after_3;
    // 0x800BFC20: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x800BFC24: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC28: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFC2C: lh          $a2, 0xBA($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0XBA));
    // 0x800BFC30: jal         0x800CA230
    // 0x800BFC34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_4;
    // 0x800BFC34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x800BFC38: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC3C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFC40: jal         0x800CA2D0
    // 0x800BFC44: lw          $a2, 0xD0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XD0));
    alSynSetPitch(rdram, ctx);
        goto after_5;
    // 0x800BFC44: lw          $a2, 0xD0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XD0));
    after_5:
    // 0x800BFC48: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC4C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFC50: jal         0x800CA360
    // 0x800BFC54: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    alSynSetFXMix(rdram, ctx);
        goto after_6;
    // 0x800BFC54: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    after_6:
    // 0x800BFC58: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800BFC5C: sh          $t6, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r14;
    // 0x800BFC60: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800BFC64: lw          $t7, 0x0($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFC68: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = S32(MEM_W(ctx->r21, 0X24));
    // 0x800BFC6C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800BFC70: lw          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800BFC74: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800BFC78: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BFC7C: nop

    // 0x800BFC80: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFC84: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BFC88: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800BFC8C: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800BFC90: nop

    // 0x800BFC94: bc1fl       L_800BFCA8
    if (!c1cs) {
        // 0x800BFC98: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800BFCA8;
    }
    goto skip_2;
    // 0x800BFC98: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_2:
    // 0x800BFC9C: b           L_800BFCB0
    // 0x800BFCA0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
        goto L_800BFCB0;
    // 0x800BFCA0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800BFCA4: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_800BFCA8:
    // 0x800BFCA8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800BFCAC: nop

L_800BFCB0:
    // 0x800BFCB0: jal         0x800C9C6C
    // 0x800BFCB4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x800BFCB4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    after_7:
    // 0x800BFCB8: b           L_800BFFB4
    // 0x800BFCBC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFCBC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFCC0:
    // 0x800BFCC0: lw          $t9, 0x28($s5)
    ctx->r25 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFCC4: bnel        $fp, $t9, L_800BFFB4
    if (ctx->r30 != ctx->r25) {
        // 0x800BFCC8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_3;
    // 0x800BFCC8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_3:
    // 0x800BFCCC: beq         $s1, $zero, L_800BFFB0
    if (ctx->r17 == 0) {
        // 0x800BFCD0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800BFFB0;
    }
    // 0x800BFCD0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFCD4: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFCD8: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = S32(MEM_W(ctx->r21, 0X24));
    // 0x800BFCDC: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x800BFCE0: lw          $v0, 0x8($t6)
    ctx->r2 = S32(MEM_W(ctx->r14, 0X8));
    // 0x800BFCE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BFCE8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BFCEC: nop

    // 0x800BFCF0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFCF4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BFCF8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800BFCFC: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800BFD00: nop

    // 0x800BFD04: bc1fl       L_800BFD18
    if (!c1cs) {
        // 0x800BFD08: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800BFD18;
    }
    goto skip_4;
    // 0x800BFD08: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_4:
    // 0x800BFD0C: b           L_800BFD20
    // 0x800BFD10: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_800BFD20;
    // 0x800BFD10: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x800BFD14: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_800BFD18:
    // 0x800BFD18: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800BFD1C: nop

L_800BFD20:
    // 0x800BFD20: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800BFD24: jal         0x800CA230
    // 0x800BFD28: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    alSynSetVol(rdram, ctx);
        goto after_8;
    // 0x800BFD28: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    after_8:
    // 0x800BFD2C: beq         $s0, $zero, L_800BFD5C
    if (ctx->r16 == 0) {
        // 0x800BFD30: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800BFD5C;
    }
    // 0x800BFD30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFD34: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800BFD38: sh          $t8, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r24;
    // 0x800BFD3C: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800BFD40: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800BFD44: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x800BFD48: jal         0x800C9C6C
    // 0x800BFD4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_9;
    // 0x800BFD4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x800BFD50: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800BFD54: b           L_800BFFB0
    // 0x800BFD58: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
        goto L_800BFFB0;
    // 0x800BFD58: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
L_800BFD5C:
    // 0x800BFD5C: jal         0x800CA400
    // 0x800BFD60: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    alSynStopVoice(rdram, ctx);
        goto after_10;
    // 0x800BFD60: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    after_10:
    // 0x800BFD64: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFD68: jal         0x800CA480
    // 0x800BFD6C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_11;
    // 0x800BFD6C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_11:
    // 0x800BFD70: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800BFD74: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800BFD78: jal         0x800BFA30
    // 0x800BFD7C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    static_5_800BFA30(rdram, ctx);
        goto after_12;
    // 0x800BFD7C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_12:
    // 0x800BFD80: lw          $s4, 0x4C($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BFD84: b           L_800BFFB0
    // 0x800BFD88: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
        goto L_800BFFB0;
    // 0x800BFD88: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_800BFD8C:
    // 0x800BFD8C: lw          $t7, 0x28($s5)
    ctx->r15 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFD90: lbu         $t6, 0x8($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X8);
    // 0x800BFD94: bne         $fp, $t7, L_800BFFB0
    if (ctx->r30 != ctx->r15) {
        // 0x800BFD98: sb          $t6, 0x2E($s5)
        MEM_B(0X2E, ctx->r21) = ctx->r14;
            goto L_800BFFB0;
    }
    // 0x800BFD98: sb          $t6, 0x2E($s5)
    MEM_B(0X2E, ctx->r21) = ctx->r14;
    // 0x800BFD9C: beq         $s1, $zero, L_800BFFB0
    if (ctx->r17 == 0) {
        // 0x800BFDA0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800BFFB0;
    }
    // 0x800BFDA0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFDA4: lbu         $t9, 0xC($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XC);
    // 0x800BFDA8: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800BFDAC: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800BFDB0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800BFDB4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800BFDB8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800BFDBC: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BFDC0: bgtzl       $v1, L_800BFDD0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800BFDC4: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800BFDD0;
    }
    goto skip_5;
    // 0x800BFDC4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_5:
    // 0x800BFDC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BFDCC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800BFDD0:
    // 0x800BFDD0: beq         $at, $zero, L_800BFDE0
    if (ctx->r1 == 0) {
        // 0x800BFDD4: nop
    
            goto L_800BFDE0;
    }
    // 0x800BFDD4: nop

    // 0x800BFDD8: b           L_800BFDE0
    // 0x800BFDDC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_800BFDE0;
    // 0x800BFDDC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_800BFDE0:
    // 0x800BFDE0: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFDE4: jal         0x800CA1A0
    // 0x800BFDE8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_13;
    // 0x800BFDE8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    after_13:
    // 0x800BFDEC: b           L_800BFFB4
    // 0x800BFDF0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFDF0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFDF4:
    // 0x800BFDF4: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = S32(MEM_W(ctx->r20, 0X8));
    // 0x800BFDF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BFDFC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFE00: swc1        $f0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f0.u32l;
    // 0x800BFE04: ldc1        $f8, -0x66B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X66B0);
    // 0x800BFE08: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800BFE0C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BFE10: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800BFE14: nop

    // 0x800BFE18: bc1fl       L_800BFE2C
    if (!c1cs) {
        // 0x800BFE1C: lw          $t8, 0x28($s5)
        ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
            goto L_800BFE2C;
    }
    goto skip_6;
    // 0x800BFE1C: lw          $t8, 0x28($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
    skip_6:
    // 0x800BFE20: lwc1        $f10, -0x66A8($at)
    ctx->f10.u32l = S32(MEM_W(ctx->r1, -0X66A8));
    // 0x800BFE24: swc1        $f10, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f10.u32l;
    // 0x800BFE28: lw          $t8, 0x28($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
L_800BFE2C:
    // 0x800BFE2C: bnel        $fp, $t8, L_800BFFB4
    if (ctx->r30 != ctx->r24) {
        // 0x800BFE30: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_7;
    // 0x800BFE30: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_7:
    // 0x800BFE34: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFE38: jal         0x800CA2D0
    // 0x800BFE3C: lw          $a2, 0x24($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X24));
    alSynSetPitch(rdram, ctx);
        goto after_14;
    // 0x800BFE3C: lw          $a2, 0x24($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X24));
    after_14:
    // 0x800BFE40: b           L_800BFFB4
    // 0x800BFE44: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFE44: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFE48:
    // 0x800BFE48: lw          $t6, 0x28($s5)
    ctx->r14 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFE4C: lbu         $t9, 0x8($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X8);
    // 0x800BFE50: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFE54: bne         $fp, $t6, L_800BFFB0
    if (ctx->r30 != ctx->r14) {
        // 0x800BFE58: sb          $t9, 0x2F($s5)
        MEM_B(0X2F, ctx->r21) = ctx->r25;
            goto L_800BFFB0;
    }
    // 0x800BFE58: sb          $t9, 0x2F($s5)
    MEM_B(0X2F, ctx->r21) = ctx->r25;
    // 0x800BFE5C: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFE60: jal         0x800CA360
    // 0x800BFE64: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_15;
    // 0x800BFE64: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    after_15:
    // 0x800BFE68: b           L_800BFFB4
    // 0x800BFE6C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFE6C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFE70:
    // 0x800BFE70: lw          $t8, 0x28($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFE74: lh          $t7, 0x8($s4)
    ctx->r15 = S32(MEM_H(ctx->r20, 0X8));
    // 0x800BFE78: bne         $fp, $t8, L_800BFFB0
    if (ctx->r30 != ctx->r24) {
        // 0x800BFE7C: sh          $t7, 0x2C($s5)
        MEM_H(0X2C, ctx->r21) = ctx->r15;
            goto L_800BFFB0;
    }
    // 0x800BFE7C: sh          $t7, 0x2C($s5)
    MEM_H(0X2C, ctx->r21) = ctx->r15;
    // 0x800BFE80: beql        $s1, $zero, L_800BFFB4
    if (ctx->r17 == 0) {
        // 0x800BFE84: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_8;
    // 0x800BFE84: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_8:
    // 0x800BFE88: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFE8C: lh          $t7, 0x2C($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X2C));
    // 0x800BFE90: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800BFE94: lbu         $t6, 0xD($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XD);
    // 0x800BFE98: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFE9C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFEA0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFEA4: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x800BFEA8: mflo        $t0
    ctx->r8 = lo;
    // 0x800BFEAC: nop

    // 0x800BFEB0: nop

    // 0x800BFEB4: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800BFEB8: mflo        $t8
    ctx->r24 = lo;
    // 0x800BFEBC: sll         $a2, $t8, 16
    ctx->r6 = S32(ctx->r24 << 16);
    // 0x800BFEC0: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BFEC4: jal         0x800CA230
    // 0x800BFEC8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    alSynSetVol(rdram, ctx);
        goto after_16;
    // 0x800BFEC8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_16:
    // 0x800BFECC: b           L_800BFFB4
    // 0x800BFED0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFED0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFED4:
    // 0x800BFED4: lw          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFED8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BFEDC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFEE0: lw          $v1, 0x4($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X4));
    // 0x800BFEE4: beql        $v1, $at, L_800BFFB4
    if (ctx->r3 == ctx->r1) {
        // 0x800BFEE8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_9;
    // 0x800BFEE8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_9:
    // 0x800BFEEC: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
    // 0x800BFEF0: lh          $t7, 0x2C($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X2C));
    // 0x800BFEF4: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800BFEF8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800BFEFC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFF00: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = S32(MEM_W(ctx->r21, 0X24));
    // 0x800BFF04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BFF08: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x800BFF0C: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BFF10: mflo        $t0
    ctx->r8 = lo;
    // 0x800BFF14: nop

    // 0x800BFF18: nop

    // 0x800BFF1C: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800BFF20: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800BFF24: mflo        $t0
    ctx->r8 = lo;
    // 0x800BFF28: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800BFF2C: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x800BFF30: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BFF34: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800BFF38: bc1fl       L_800BFF4C
    if (!c1cs) {
        // 0x800BFF3C: trunc.w.d   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800BFF4C;
    }
    goto skip_10;
    // 0x800BFF3C: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    skip_10:
    // 0x800BFF40: b           L_800BFF54
    // 0x800BFF44: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_800BFF54;
    // 0x800BFF44: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x800BFF48: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
L_800BFF4C:
    // 0x800BFF4C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800BFF50: nop

L_800BFF54:
    // 0x800BFF54: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800BFF58: jal         0x800CA230
    // 0x800BFF5C: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x800BFF5C: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    after_17:
    // 0x800BFF60: sh          $fp, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r30;
    // 0x800BFF64: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800BFF68: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800BFF6C: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x800BFF70: jal         0x800C9C6C
    // 0x800BFF74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x800BFF74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x800BFF78: b           L_800BFFB4
    // 0x800BFF7C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFF7C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFF80:
    // 0x800BFF80: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFF84: jal         0x800CA400
    // 0x800BFF88: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_19;
    // 0x800BFF88: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_19:
    // 0x800BFF8C: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFF90: jal         0x800CA480
    // 0x800BFF94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_20;
    // 0x800BFF94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_20:
    // 0x800BFF98: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800BFF9C: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800BFFA0: jal         0x800BFA30
    // 0x800BFFA4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    static_5_800BFA30(rdram, ctx);
        goto after_21;
    // 0x800BFFA4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_21:
    // 0x800BFFA8: lw          $s4, 0x4C($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BFFAC: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_800BFFB0:
    // 0x800BFFB0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFFB4:
    // 0x800BFFB4: jal         0x800C9D90
    // 0x800BFFB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alEvtqNextEvent(rdram, ctx);
        goto after_22;
    // 0x800BFFB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_22:
    // 0x800BFFBC: beq         $v0, $zero, L_800BFB04
    if (ctx->r2 == 0) {
        // 0x800BFFC0: sw          $v0, 0x4C($s6)
        MEM_W(0X4C, ctx->r22) = ctx->r2;
            goto L_800BFB04;
    }
    // 0x800BFFC0: sw          $v0, 0x4C($s6)
    MEM_W(0X4C, ctx->r22) = ctx->r2;
    // 0x800BFFC4: lw          $t7, 0x50($s6)
    ctx->r15 = S32(MEM_W(ctx->r22, 0X50));
    // 0x800BFFC8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800BFFCC: sw          $t8, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->r24;
    // 0x800BFFD0: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BFFD4: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800BFFD8: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800BFFDC: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800BFFE0: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800BFFE4: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800BFFE8: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BFFEC: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BFFF0: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BFFF4: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BFFF8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800BFFFC: jr          $ra
    // 0x800C0000: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800C0000: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void static_5_8004C780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C780: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004C784: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004C788: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8004C78C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004C790: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004C794: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004C798: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8004C79C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8004C7A0: lw          $t6, 0x27C($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X27C));
    // 0x8004C7A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004C7A8: addiu       $s3, $sp, 0x44
    ctx->r19 = ADD32(ctx->r29, 0X44);
    // 0x8004C7AC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004C7B0: sw          $t7, 0x27C($a0)
    MEM_W(0X27C, ctx->r4) = ctx->r15;
    // 0x8004C7B4: addiu       $s2, $a0, 0x78
    ctx->r18 = ADD32(ctx->r4, 0X78);
    // 0x8004C7B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004C7BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8004C7C0: jal         0x800BB440
    // 0x8004C7C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8004C7C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8004C7C8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8004C7CC: beq         $v0, $s0, L_8004C7F4
    if (ctx->r2 == ctx->r16) {
        // 0x8004C7D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004C7F4;
    }
    // 0x8004C7D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8004C7D4:
    // 0x8004C7D4: jal         0x8004CBE0
    // 0x8004C7D8: lw          $a1, 0x44($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X44));
    static_5_8004CBE0(rdram, ctx);
        goto after_1;
    // 0x8004C7D8: lw          $a1, 0x44($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X44));
    after_1:
    // 0x8004C7DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004C7E0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8004C7E4: jal         0x800BB440
    // 0x8004C7E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8004C7E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8004C7EC: bnel        $v0, $s0, L_8004C7D4
    if (ctx->r2 != ctx->r16) {
        // 0x8004C7F0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004C7D4;
    }
    goto skip_0;
    // 0x8004C7F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_8004C7F4:
    // 0x8004C7F4: lw          $t8, 0x280($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X280));
    // 0x8004C7F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C7FC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8004C800: beql        $t8, $zero, L_8004C828
    if (ctx->r24 == 0) {
        // 0x8004C804: lw          $t0, 0x274($s1)
        ctx->r8 = S32(MEM_W(ctx->r17, 0X274));
            goto L_8004C828;
    }
    goto skip_1;
    // 0x8004C804: lw          $t0, 0x274($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X274));
    skip_1:
    // 0x8004C808: lw          $t9, 0x274($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X274));
    // 0x8004C80C: beql        $t9, $zero, L_8004C828
    if (ctx->r25 == 0) {
        // 0x8004C810: lw          $t0, 0x274($s1)
        ctx->r8 = S32(MEM_W(ctx->r17, 0X274));
            goto L_8004C828;
    }
    goto skip_2;
    // 0x8004C810: lw          $t0, 0x274($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X274));
    skip_2:
    // 0x8004C814: jal         0x8004CD58
    // 0x8004C818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    static_5_8004CD58(rdram, ctx);
        goto after_3;
    // 0x8004C818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8004C81C: b           L_8004C860
    // 0x8004C820: lw          $s0, 0x260($s1)
    ctx->r16 = S32(MEM_W(ctx->r17, 0X260));
        goto L_8004C860;
    // 0x8004C820: lw          $s0, 0x260($s1)
    ctx->r16 = S32(MEM_W(ctx->r17, 0X260));
    // 0x8004C824: lw          $t0, 0x274($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X274));
L_8004C828:
    // 0x8004C828: lw          $t3, 0x278($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X278));
    // 0x8004C82C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8004C830: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8004C834: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8004C838: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8004C83C: or          $s0, $t2, $t4
    ctx->r16 = ctx->r10 | ctx->r12;
    // 0x8004C840: jal         0x8004CD94
    // 0x8004C844: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    static_5_8004CD94(rdram, ctx);
        goto after_4;
    // 0x8004C844: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8004C848: beq         $v0, $s0, L_8004C85C
    if (ctx->r2 == ctx->r16) {
        // 0x8004C84C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004C85C;
    }
    // 0x8004C84C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C850: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8004C854: jal         0x8004CC48
    // 0x8004C858: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    static_5_8004CC48(rdram, ctx);
        goto after_5;
    // 0x8004C858: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    after_5:
L_8004C85C:
    // 0x8004C85C: lw          $s0, 0x260($s1)
    ctx->r16 = S32(MEM_W(ctx->r17, 0X260));
L_8004C860:
    // 0x8004C860: beql        $s0, $zero, L_8004C888
    if (ctx->r16 == 0) {
        // 0x8004C864: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8004C888;
    }
    goto skip_3;
    // 0x8004C864: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_3:
    // 0x8004C868: lw          $a0, 0x4($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X4));
L_8004C86C:
    // 0x8004C86C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8004C870: jal         0x800BB610
    // 0x8004C874: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x8004C874: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8004C878: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8004C87C: bnel        $s0, $zero, L_8004C86C
    if (ctx->r16 != 0) {
        // 0x8004C880: lw          $a0, 0x4($s0)
        ctx->r4 = S32(MEM_W(ctx->r16, 0X4));
            goto L_8004C86C;
    }
    goto skip_4;
    // 0x8004C880: lw          $a0, 0x4($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X4));
    skip_4:
    // 0x8004C884: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_8004C888:
    // 0x8004C888: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004C88C: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004C890: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004C894: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004C898: jr          $ra
    // 0x8004C89C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004C89C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void static_5_8004C8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C8A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004C8A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004C8A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004C8AC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8004C8B0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8004C8B4: lw          $a1, 0x274($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X274));
    // 0x8004C8B8: sw          $zero, 0x274($a0)
    MEM_W(0X274, ctx->r4) = 0;
    // 0x8004C8BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004C8C0: lw          $t6, 0x4($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X4));
    // 0x8004C8C4: addiu       $a0, $a1, 0x10
    ctx->r4 = ADD32(ctx->r5, 0X10);
    // 0x8004C8C8: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8004C8CC: beq         $t7, $zero, L_8004C920
    if (ctx->r15 == 0) {
        // 0x8004C8D0: nop
    
            goto L_8004C920;
    }
    // 0x8004C8D0: nop

    // 0x8004C8D4: jal         0x800BC220
    // 0x8004C8D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_0;
    // 0x8004C8D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004C8DC: beq         $v0, $zero, L_8004C920
    if (ctx->r2 == 0) {
        // 0x8004C8E0: lw          $a1, 0x2C($sp)
        ctx->r5 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_8004C920;
    }
    // 0x8004C8E0: lw          $a1, 0x2C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8004C8E4: lw          $t8, 0x4($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X4));
    // 0x8004C8E8: lw          $t0, 0x8($a1)
    ctx->r8 = S32(MEM_W(ctx->r5, 0X8));
    // 0x8004C8EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004C8F0: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8004C8F4: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x8004C8F8: bne         $t1, $at, L_8004C9A8
    if (ctx->r9 != ctx->r1) {
        // 0x8004C8FC: sw          $t9, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r25;
            goto L_8004C9A8;
    }
    // 0x8004C8FC: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8004C900: lw          $t2, 0x268($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X268));
    // 0x8004C904: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8004C908: lw          $t3, 0x270($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X270));
    // 0x8004C90C: sw          $a1, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r5;
    // 0x8004C910: bnel        $t3, $zero, L_8004C9AC
    if (ctx->r11 != 0) {
        // 0x8004C914: lw          $t0, 0x274($s0)
        ctx->r8 = S32(MEM_W(ctx->r16, 0X274));
            goto L_8004C9AC;
    }
    goto skip_0;
    // 0x8004C914: lw          $t0, 0x274($s0)
    ctx->r8 = S32(MEM_W(ctx->r16, 0X274));
    skip_0:
    // 0x8004C918: b           L_8004C9A8
    // 0x8004C91C: sw          $a1, 0x270($s0)
    MEM_W(0X270, ctx->r16) = ctx->r5;
        goto L_8004C9A8;
    // 0x8004C91C: sw          $a1, 0x270($s0)
    MEM_W(0X270, ctx->r16) = ctx->r5;
L_8004C920:
    // 0x8004C920: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C924: addiu       $v0, $v0, 0x3704
    ctx->r2 = ADD32(ctx->r2, 0X3704);
    // 0x8004C928: lw          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8004C92C: beq         $t4, $zero, L_8004C958
    if (ctx->r12 == 0) {
        // 0x8004C930: nop
    
            goto L_8004C958;
    }
    // 0x8004C930: nop

    // 0x8004C934: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8004C938: jal         0x800BB580
    // 0x8004C93C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8004C93C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8004C940: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8004C944: lw          $t5, 0x3708($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, 0X3708));
    // 0x8004C948: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C94C: lw          $a1, 0x2C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8004C950: subu        $t9, $v1, $t5
    ctx->r25 = SUB32(ctx->r3, ctx->r13);
    // 0x8004C954: sw          $t9, 0x370C($at)
    MEM_W(0X370C, ctx->r1) = ctx->r25;
L_8004C958:
    // 0x8004C958: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C95C: addiu       $v0, $v0, 0x3710
    ctx->r2 = ADD32(ctx->r2, 0X3710);
    // 0x8004C960: lw          $t1, 0x0($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8004C964: beql        $t1, $zero, L_8004C994
    if (ctx->r9 == 0) {
        // 0x8004C968: lw          $t8, 0x4($a1)
        ctx->r24 = S32(MEM_W(ctx->r5, 0X4));
            goto L_8004C994;
    }
    goto skip_1;
    // 0x8004C968: lw          $t8, 0x4($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X4));
    skip_1:
    // 0x8004C96C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8004C970: jal         0x800BB580
    // 0x8004C974: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x8004C974: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x8004C978: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8004C97C: lw          $t2, 0x3714($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X3714));
    // 0x8004C980: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004C984: lw          $a1, 0x2C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8004C988: subu        $t7, $v1, $t2
    ctx->r15 = SUB32(ctx->r3, ctx->r10);
    // 0x8004C98C: sw          $t7, 0x3718($at)
    MEM_W(0X3718, ctx->r1) = ctx->r15;
    // 0x8004C990: lw          $t8, 0x4($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X4));
L_8004C994:
    // 0x8004C994: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8004C998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004C99C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8004C9A0: jal         0x8004CB20
    // 0x8004C9A4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    static_5_8004CB20(rdram, ctx);
        goto after_3;
    // 0x8004C9A4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    after_3:
L_8004C9A8:
    // 0x8004C9A8: lw          $t0, 0x274($s0)
    ctx->r8 = S32(MEM_W(ctx->r16, 0X274));
L_8004C9AC:
    // 0x8004C9AC: lw          $t4, 0x278($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X278));
    // 0x8004C9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004C9B4: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x8004C9B8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8004C9BC: sltiu       $t5, $t4, 0x1
    ctx->r13 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x8004C9C0: or          $a3, $t2, $t5
    ctx->r7 = ctx->r10 | ctx->r13;
    // 0x8004C9C4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8004C9C8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8004C9CC: jal         0x8004CD94
    // 0x8004C9D0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    static_5_8004CD94(rdram, ctx);
        goto after_4;
    // 0x8004C9D0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8004C9D4: lw          $a3, 0x20($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004C9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004C9DC: lw          $a1, 0x28($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8004C9E0: beql        $v0, $a3, L_8004C9F4
    if (ctx->r2 == ctx->r7) {
        // 0x8004C9E4: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_8004C9F4;
    }
    goto skip_2;
    // 0x8004C9E4: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_2:
    // 0x8004C9E8: jal         0x8004CC48
    // 0x8004C9EC: lw          $a2, 0x24($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X24));
    static_5_8004CC48(rdram, ctx);
        goto after_5;
    // 0x8004C9EC: lw          $a2, 0x24($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X24));
    after_5:
    // 0x8004C9F0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_8004C9F4:
    // 0x8004C9F4: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004C9F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004C9FC: jr          $ra
    // 0x8004CA00: nop

    return;
    // 0x8004CA00: nop

;}
RECOMP_FUNC void static_5_8004CA04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CA04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004CA08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004CA0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004CA10: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8004CA14: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8004CA18: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004CA1C: lw          $a1, 0x278($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X278));
    // 0x8004CA20: addiu       $v0, $v0, 0x371C
    ctx->r2 = ADD32(ctx->r2, 0X371C);
    // 0x8004CA24: sw          $zero, 0x278($a0)
    MEM_W(0X278, ctx->r4) = 0;
    // 0x8004CA28: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8004CA2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004CA30: beql        $t6, $zero, L_8004CA60
    if (ctx->r14 == 0) {
        // 0x8004CA34: lw          $t3, 0x4($a1)
        ctx->r11 = S32(MEM_W(ctx->r5, 0X4));
            goto L_8004CA60;
    }
    goto skip_0;
    // 0x8004CA34: lw          $t3, 0x4($a1)
    ctx->r11 = S32(MEM_W(ctx->r5, 0X4));
    skip_0:
    // 0x8004CA38: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8004CA3C: jal         0x800BB580
    // 0x8004CA40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8004CA40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004CA44: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8004CA48: lw          $t7, 0x3714($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, 0X3714));
    // 0x8004CA4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CA50: lw          $a1, 0x2C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8004CA54: subu        $t1, $v1, $t7
    ctx->r9 = SUB32(ctx->r3, ctx->r15);
    // 0x8004CA58: sw          $t1, 0x3724($at)
    MEM_W(0X3724, ctx->r1) = ctx->r9;
    // 0x8004CA5C: lw          $t3, 0x4($a1)
    ctx->r11 = S32(MEM_W(ctx->r5, 0X4));
L_8004CA60:
    // 0x8004CA60: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004CA64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004CA68: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8004CA6C: jal         0x8004CB20
    // 0x8004CA70: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    static_5_8004CB20(rdram, ctx);
        goto after_1;
    // 0x8004CA70: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    after_1:
    // 0x8004CA74: lw          $t5, 0x274($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X274));
    // 0x8004CA78: lw          $t8, 0x278($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X278));
    // 0x8004CA7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004CA80: sltiu       $t6, $t5, 0x1
    ctx->r14 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8004CA84: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8004CA88: sltiu       $t9, $t8, 0x1
    ctx->r25 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8004CA8C: or          $a3, $t7, $t9
    ctx->r7 = ctx->r15 | ctx->r25;
    // 0x8004CA90: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8004CA94: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8004CA98: jal         0x8004CD94
    // 0x8004CA9C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    static_5_8004CD94(rdram, ctx);
        goto after_2;
    // 0x8004CA9C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x8004CAA0: lw          $a3, 0x20($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004CAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004CAA8: lw          $a1, 0x28($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8004CAAC: beql        $v0, $a3, L_8004CAC0
    if (ctx->r2 == ctx->r7) {
        // 0x8004CAB0: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_8004CAC0;
    }
    goto skip_1;
    // 0x8004CAB0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_1:
    // 0x8004CAB4: jal         0x8004CC48
    // 0x8004CAB8: lw          $a2, 0x24($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X24));
    static_5_8004CC48(rdram, ctx);
        goto after_3;
    // 0x8004CAB8: lw          $a2, 0x24($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X24));
    after_3:
    // 0x8004CABC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_8004CAC0:
    // 0x8004CAC0: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004CAC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004CAC8: jr          $ra
    // 0x8004CACC: nop

    return;
    // 0x8004CACC: nop

;}
RECOMP_FUNC void static_5_800BEB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEB18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BEB1C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BEB20: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800BEB24: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800BEB28: lw          $t7, 0x28($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BEB2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BEB30: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BEB34: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BEB38: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800BEB3C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800BEB40: jal         0x800C73EC
    // 0x800BEB44: lw          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X28));
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800BEB44: lw          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X28));
    after_0:
    // 0x800BEB48: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800BEB4C: lw          $t8, 0x20($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BEB50: beq         $t8, $zero, L_800BEB60
    if (ctx->r24 == 0) {
        // 0x800BEB54: nop
    
            goto L_800BEB60;
    }
    // 0x800BEB54: nop

    // 0x800BEB58: b           L_800BEBC8
    // 0x800BEB5C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800BEBC8;
    // 0x800BEB5C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800BEB60:
    // 0x800BEB60: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800BEB64:
    // 0x800BEB64: lw          $t9, 0x28($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BEB68: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BEB6C: lw          $t2, 0x24($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BEB70: lw          $a0, 0x4($t9)
    ctx->r4 = S32(MEM_W(ctx->r25, 0X4));
    // 0x800BEB74: lw          $a1, 0x8($t9)
    ctx->r5 = S32(MEM_W(ctx->r25, 0X8));
    // 0x800BEB78: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800BEB7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800BEB80: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800BEB84: jal         0x800C8740
    // 0x800BEB88: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_1;
    // 0x800BEB88: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800BEB8C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800BEB90: lw          $t3, 0x20($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BEB94: bne         $t3, $zero, L_800BEBB0
    if (ctx->r11 != 0) {
        // 0x800BEB98: nop
    
            goto L_800BEBB0;
    }
    // 0x800BEB98: nop

    // 0x800BEB9C: lw          $t4, 0x24($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BEBA0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800BEBA4: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x800BEBA8: bne         $at, $zero, L_800BEB64
    if (ctx->r1 != 0) {
        // 0x800BEBAC: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800BEB64;
    }
    // 0x800BEBAC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800BEBB0:
    // 0x800BEBB0: lw          $t6, 0x28($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BEBB4: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x800BEBB8: jal         0x800C73EC
    // 0x800BEBBC: lw          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X28));
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800BEBBC: lw          $a0, 0x28($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X28));
    after_2:
    // 0x800BEBC0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800BEBC4: lw          $v0, 0x20($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X20));
L_800BEBC8:
    // 0x800BEBC8: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BEBCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BEBD0: jr          $ra
    // 0x800BEBD4: nop

    return;
    // 0x800BEBD4: nop

    // 0x800BEBD8: nop

    // 0x800BEBDC: nop

    // 0x800BEBE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BEBE4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800BEBE8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800BEBEC: lw          $t8, 0x2C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BEBF0: lw          $t6, 0x24($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BEBF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEBF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800BEBFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800BEC00: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800BEC04: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BEC08: beq         $t7, $t9, L_800BEC44
    if (ctx->r15 == ctx->r25) {
        // 0x800BEC0C: nop
    
            goto L_800BEC44;
    }
    // 0x800BEC0C: nop

    // 0x800BEC10: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800BEC14: lw          $t0, 0x24($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BEC18: lw          $a1, 0x28($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BEC1C: lw          $a0, 0x20($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BEC20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BEC24: jal         0x800C70CC
    // 0x800BEC28: lbu         $a3, 0x0($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X0);
    __osPfsRWInode_recomp(rdram, ctx);
        goto after_3;
    // 0x800BEC28: lbu         $a3, 0x0($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X0);
    after_3:
    // 0x800BEC2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BEC30: lw          $t1, 0x1C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BEC34: beq         $t1, $zero, L_800BEC44
    if (ctx->r9 == 0) {
        // 0x800BEC38: nop
    
            goto L_800BEC44;
    }
    // 0x800BEC38: nop

    // 0x800BEC3C: b           L_800BECCC
    // 0x800BEC40: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800BECCC;
    // 0x800BEC40: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800BEC44:
    // 0x800BEC44: lw          $t2, 0x2C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BEC48: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BEC4C: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x800BEC50: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800BEC54: addu        $t8, $t3, $t5
    ctx->r24 = ADD32(ctx->r11, ctx->r13);
    // 0x800BEC58: lhu         $at, 0x0($t8)
    ctx->r1 = MEM_HU(ctx->r24, 0X0);
    // 0x800BEC5C: sh          $at, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r1;
    // 0x800BEC60: lw          $t1, 0x20($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BEC64: lw          $t6, 0x2C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BEC68: lw          $t4, 0x60($t1)
    ctx->r12 = S32(MEM_W(ctx->r9, 0X60));
    // 0x800BEC6C: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x800BEC70: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BEC74: bne         $at, $zero, L_800BECA4
    if (ctx->r1 != 0) {
        // 0x800BEC78: nop
    
            goto L_800BECA4;
    }
    // 0x800BEC78: nop

    // 0x800BEC7C: lbu         $t3, 0x0($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X0);
    // 0x800BEC80: lbu         $t5, 0x64($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X64);
    // 0x800BEC84: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800BEC88: beq         $at, $zero, L_800BECA4
    if (ctx->r1 == 0) {
        // 0x800BEC8C: nop
    
            goto L_800BECA4;
    }
    // 0x800BEC8C: nop

    // 0x800BEC90: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x800BEC94: blez        $t7, L_800BECA4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BEC98: slti        $at, $t7, 0x80
        ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
            goto L_800BECA4;
    }
    // 0x800BEC98: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800BEC9C: bne         $at, $zero, L_800BECC8
    if (ctx->r1 != 0) {
        // 0x800BECA0: nop
    
            goto L_800BECC8;
    }
    // 0x800BECA0: nop

L_800BECA4:
    // 0x800BECA4: lw          $t2, 0x2C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BECA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BECAC: lhu         $t8, 0x0($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X0);
    // 0x800BECB0: bne         $t8, $at, L_800BECC0
    if (ctx->r24 != ctx->r1) {
        // 0x800BECB4: nop
    
            goto L_800BECC0;
    }
    // 0x800BECB4: nop

    // 0x800BECB8: b           L_800BECCC
    // 0x800BECBC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800BECCC;
    // 0x800BECBC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800BECC0:
    // 0x800BECC0: b           L_800BECCC
    // 0x800BECC4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800BECCC;
    // 0x800BECC4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800BECC8:
    // 0x800BECC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BECCC:
    // 0x800BECCC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800BECD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BECD4: jr          $ra
    // 0x800BECD8: nop

    return;
    // 0x800BECD8: nop

;}
RECOMP_FUNC void static_5_800BFA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFA30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFA34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFA38: jal         0x800BC180
    // 0x800BFA3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800BFA3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800BFA40: lw          $s0, 0x8($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X8));
    // 0x800BFA44: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800BFA48: beq         $s0, $zero, L_800BFA94
    if (ctx->r16 == 0) {
        // 0x800BFA4C: nop
    
            goto L_800BFA94;
    }
    // 0x800BFA4C: nop

L_800BFA50:
    // 0x800BFA50: lw          $t6, 0x10($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X10));
    // 0x800BFA54: lw          $s1, 0x0($s0)
    ctx->r17 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800BFA58: bne         $s3, $t6, L_800BFA8C
    if (ctx->r19 != ctx->r14) {
        // 0x800BFA5C: nop
    
            goto L_800BFA8C;
    }
    // 0x800BFA5C: nop

    // 0x800BFA60: beq         $s1, $zero, L_800BFA78
    if (ctx->r17 == 0) {
        // 0x800BFA64: nop
    
            goto L_800BFA78;
    }
    // 0x800BFA64: nop

    // 0x800BFA68: lw          $t7, 0x8($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800BFA6C: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800BFA70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800BFA74: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
L_800BFA78:
    // 0x800BFA78: jal         0x800BF770
    // 0x800BFA7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800BFA7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800BFA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BFA84: jal         0x800BF7A0
    // 0x800BFA88: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800BFA88: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800BFA8C:
    // 0x800BFA8C: bne         $s1, $zero, L_800BFA50
    if (ctx->r17 != 0) {
        // 0x800BFA90: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800BFA50;
    }
    // 0x800BFA90: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800BFA94:
    // 0x800BFA94: jal         0x800BC180
    // 0x800BFA98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800BFA98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x800BFA9C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800BFAA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFAA4: jr          $ra
    // 0x800BFAA8: nop

    return;
    // 0x800BFAA8: nop

    // 0x800BFAAC: jr          $ra
    // 0x800BFAB0: nop

    return;
    // 0x800BFAB0: nop

    // 0x800BFAB4: jr          $ra
    // 0x800BFAB8: nop

    return;
    // 0x800BFAB8: nop

    // 0x800BFABC: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800BFAC0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800BFAC4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800BFAC8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800BFACC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800BFAD0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800BFAD4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BFAD8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800BFADC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800BFAE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800BFAE4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800BFAE8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800BFAEC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800BFAF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800BFAF4: ldc1        $f20, -0x66E0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X66E0);
    // 0x800BFAF8: addiu       $s4, $a0, 0x28
    ctx->r20 = ADD32(ctx->r4, 0X28);
    // 0x800BFAFC: addiu       $s7, $a0, 0x14
    ctx->r23 = ADD32(ctx->r4, 0X14);
    // 0x800BFB00: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800BFB04:
    // 0x800BFB04: lh          $v0, 0x28($s6)
    ctx->r2 = S32(MEM_H(ctx->r22, 0X28));
    // 0x800BFB08: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800BFB0C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800BFB10: bne         $v0, $at, L_800BFB30
    if (ctx->r2 != ctx->r1) {
        // 0x800BFB14: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFB30;
    }
    // 0x800BFB14: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800BFB18: sh          $t6, 0xF4($sp)
    MEM_H(0XF4, ctx->r29) = ctx->r14;
    // 0x800BFB1C: lw          $a2, 0x48($s6)
    ctx->r6 = S32(MEM_W(ctx->r22, 0X48));
    // 0x800BFB20: jal         0x800C9C6C
    // 0x800BFB24: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x800BFB24: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
    after_4:
    // 0x800BFB28: b           L_800BFFB4
    // 0x800BFB2C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFB2C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFB30:
    // 0x800BFB30: lw          $s5, 0x2C($s6)
    ctx->r21 = S32(MEM_W(ctx->r22, 0X2C));
    // 0x800BFB34: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x800BFB38: beq         $at, $zero, L_800BFFB0
    if (ctx->r1 == 0) {
        // 0x800BFB3C: lw          $s1, 0x1C($s5)
        ctx->r17 = S32(MEM_W(ctx->r21, 0X1C));
            goto L_800BFFB0;
    }
    // 0x800BFB3C: lw          $s1, 0x1C($s5)
    ctx->r17 = S32(MEM_W(ctx->r21, 0X1C));
    // 0x800BFB40: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800BFB44: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BFB48: addu        $at, $at, $t7
    gpr jr_addend_800BFB50 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800BFB4C: lw          $t7, -0x66D8($at)
    ctx->r15 = ADD32(ctx->r1, -0X66D8);
    // 0x800BFB50: jr          $t7
    // 0x800BFB54: nop

    switch (jr_addend_800BFB50 >> 2) {
        case 0: goto L_800BFB58; break;
        case 1: goto L_800BFCC0; break;
        case 2: goto L_800BFD8C; break;
        case 3: goto L_800BFE70; break;
        case 4: goto L_800BFDF4; break;
        case 5: goto L_800BFFB0; break;
        case 6: goto L_800BFED4; break;
        case 7: goto L_800BFF80; break;
        case 8: goto L_800BFE48; break;
        default: switch_error(__func__, 0x800BFB50, 0x80109928);
    }
    // 0x800BFB54: nop

L_800BFB58:
    // 0x800BFB58: lw          $t8, 0x28($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFB5C: bnel        $t8, $zero, L_800BFFB4
    if (ctx->r24 != 0) {
        // 0x800BFB60: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_0;
    // 0x800BFB60: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_0:
    // 0x800BFB64: beq         $s1, $zero, L_800BFFB0
    if (ctx->r17 == 0) {
        // 0x800BFB68: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800BFFB0;
    }
    // 0x800BFB68: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFB6C: sh          $zero, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = 0;
    // 0x800BFB70: lh          $t9, 0x20($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0X20));
    // 0x800BFB74: sb          $zero, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = 0;
    // 0x800BFB78: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x800BFB7C: sh          $t9, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r25;
    // 0x800BFB80: jal         0x800C9FC8
    // 0x800BFB84: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    alSynAllocVoice(rdram, ctx);
        goto after_5;
    // 0x800BFB84: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    after_5:
    // 0x800BFB88: lw          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFB8C: lh          $t7, 0x2C($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X2C));
    // 0x800BFB90: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800BFB94: lbu         $t6, 0xC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XC);
    // 0x800BFB98: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800BFB9C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFBA0: mflo        $t8
    ctx->r24 = lo;
    // 0x800BFBA4: nop

    // 0x800BFBA8: nop

    // 0x800BFBAC: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800BFBB0: mflo        $t9
    ctx->r25 = lo;
    // 0x800BFBB4: sh          $t9, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r25;
    // 0x800BFBB8: lbu         $t7, 0xC($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XC);
    // 0x800BFBBC: lbu         $t6, 0x2E($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X2E);
    // 0x800BFBC0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800BFBC4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800BFBC8: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x800BFBCC: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800BFBD0: bgtzl       $v1, L_800BFBE0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800BFBD4: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800BFBE0;
    }
    goto skip_1;
    // 0x800BFBD4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_1:
    // 0x800BFBD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BFBDC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800BFBE0:
    // 0x800BFBE0: beq         $at, $zero, L_800BFBF0
    if (ctx->r1 == 0) {
        // 0x800BFBE4: nop
    
            goto L_800BFBF0;
    }
    // 0x800BFBE4: nop

    // 0x800BFBE8: b           L_800BFBF0
    // 0x800BFBEC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_800BFBF0;
    // 0x800BFBEC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_800BFBF0:
    // 0x800BFBF0: lwc1        $f4, 0x24($s5)
    ctx->f4.u32l = S32(MEM_W(ctx->r21, 0X24));
    // 0x800BFBF4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFBF8: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x800BFBFC: lw          $s0, 0x0($a3)
    ctx->r16 = S32(MEM_W(ctx->r7, 0X0));
    // 0x800BFC00: lw          $a2, 0x8($s1)
    ctx->r6 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800BFC04: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC08: jal         0x800CA110
    // 0x800BFC0C: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    alSynStartVoice(rdram, ctx);
        goto after_6;
    // 0x800BFC0C: sb          $t0, 0xD7($sp)
    MEM_B(0XD7, ctx->r29) = ctx->r8;
    after_6:
    // 0x800BFC10: lbu         $a2, 0xD7($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD7);
    // 0x800BFC14: sw          $fp, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r30;
    // 0x800BFC18: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC1C: jal         0x800CA1A0
    // 0x800BFC20: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynSetPan(rdram, ctx);
        goto after_7;
    // 0x800BFC20: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_7:
    // 0x800BFC24: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC28: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFC2C: lh          $a2, 0xBA($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0XBA));
    // 0x800BFC30: jal         0x800CA230
    // 0x800BFC34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_8;
    // 0x800BFC34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_8:
    // 0x800BFC38: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC3C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFC40: jal         0x800CA2D0
    // 0x800BFC44: lw          $a2, 0xD0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XD0));
    alSynSetPitch(rdram, ctx);
        goto after_9;
    // 0x800BFC44: lw          $a2, 0xD0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XD0));
    after_9:
    // 0x800BFC48: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFC4C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFC50: jal         0x800CA360
    // 0x800BFC54: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    alSynSetFXMix(rdram, ctx);
        goto after_10;
    // 0x800BFC54: lbu         $a2, 0x2F($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0X2F);
    after_10:
    // 0x800BFC58: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800BFC5C: sh          $t6, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r14;
    // 0x800BFC60: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800BFC64: lw          $t7, 0x0($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFC68: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = S32(MEM_W(ctx->r21, 0X24));
    // 0x800BFC6C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800BFC70: lw          $v0, 0x0($t7)
    ctx->r2 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800BFC74: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800BFC78: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BFC7C: nop

    // 0x800BFC80: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFC84: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BFC88: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800BFC8C: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800BFC90: nop

    // 0x800BFC94: bc1fl       L_800BFCA8
    if (!c1cs) {
        // 0x800BFC98: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800BFCA8;
    }
    goto skip_2;
    // 0x800BFC98: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_2:
    // 0x800BFC9C: b           L_800BFCB0
    // 0x800BFCA0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
        goto L_800BFCB0;
    // 0x800BFCA0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800BFCA4: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_800BFCA8:
    // 0x800BFCA8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800BFCAC: nop

L_800BFCB0:
    // 0x800BFCB0: jal         0x800C9C6C
    // 0x800BFCB4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    alEvtqPostEvent(rdram, ctx);
        goto after_11;
    // 0x800BFCB4: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    after_11:
    // 0x800BFCB8: b           L_800BFFB4
    // 0x800BFCBC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFCBC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFCC0:
    // 0x800BFCC0: lw          $t9, 0x28($s5)
    ctx->r25 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFCC4: bnel        $fp, $t9, L_800BFFB4
    if (ctx->r30 != ctx->r25) {
        // 0x800BFCC8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_3;
    // 0x800BFCC8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_3:
    // 0x800BFCCC: beq         $s1, $zero, L_800BFFB0
    if (ctx->r17 == 0) {
        // 0x800BFCD0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800BFFB0;
    }
    // 0x800BFCD0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFCD4: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFCD8: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = S32(MEM_W(ctx->r21, 0X24));
    // 0x800BFCDC: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x800BFCE0: lw          $v0, 0x8($t6)
    ctx->r2 = S32(MEM_W(ctx->r14, 0X8));
    // 0x800BFCE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BFCE8: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BFCEC: nop

    // 0x800BFCF0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFCF4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BFCF8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800BFCFC: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800BFD00: nop

    // 0x800BFD04: bc1fl       L_800BFD18
    if (!c1cs) {
        // 0x800BFD08: trunc.w.d   $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800BFD18;
    }
    goto skip_4;
    // 0x800BFD08: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    skip_4:
    // 0x800BFD0C: b           L_800BFD20
    // 0x800BFD10: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_800BFD20;
    // 0x800BFD10: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x800BFD14: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
L_800BFD18:
    // 0x800BFD18: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800BFD1C: nop

L_800BFD20:
    // 0x800BFD20: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800BFD24: jal         0x800CA230
    // 0x800BFD28: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    alSynSetVol(rdram, ctx);
        goto after_12;
    // 0x800BFD28: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    after_12:
    // 0x800BFD2C: beq         $s0, $zero, L_800BFD5C
    if (ctx->r16 == 0) {
        // 0x800BFD30: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800BFD5C;
    }
    // 0x800BFD30: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFD34: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800BFD38: sh          $t8, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r24;
    // 0x800BFD3C: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800BFD40: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800BFD44: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x800BFD48: jal         0x800C9C6C
    // 0x800BFD4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_13;
    // 0x800BFD4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_13:
    // 0x800BFD50: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800BFD54: b           L_800BFFB0
    // 0x800BFD58: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
        goto L_800BFFB0;
    // 0x800BFD58: sw          $t9, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r25;
L_800BFD5C:
    // 0x800BFD5C: jal         0x800CA400
    // 0x800BFD60: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    alSynStopVoice(rdram, ctx);
        goto after_14;
    // 0x800BFD60: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    after_14:
    // 0x800BFD64: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFD68: jal         0x800CA480
    // 0x800BFD6C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_15;
    // 0x800BFD6C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_15:
    // 0x800BFD70: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800BFD74: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800BFD78: jal         0x800BFA30
    // 0x800BFD7C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    static_5_800BFA30(rdram, ctx);
        goto after_16;
    // 0x800BFD7C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_16:
    // 0x800BFD80: lw          $s4, 0x4C($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BFD84: b           L_800BFFB0
    // 0x800BFD88: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
        goto L_800BFFB0;
    // 0x800BFD88: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_800BFD8C:
    // 0x800BFD8C: lw          $t7, 0x28($s5)
    ctx->r15 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFD90: lbu         $t6, 0x8($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X8);
    // 0x800BFD94: bne         $fp, $t7, L_800BFFB0
    if (ctx->r30 != ctx->r15) {
        // 0x800BFD98: sb          $t6, 0x2E($s5)
        MEM_B(0X2E, ctx->r21) = ctx->r14;
            goto L_800BFFB0;
    }
    // 0x800BFD98: sb          $t6, 0x2E($s5)
    MEM_B(0X2E, ctx->r21) = ctx->r14;
    // 0x800BFD9C: beq         $s1, $zero, L_800BFFB0
    if (ctx->r17 == 0) {
        // 0x800BFDA0: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800BFFB0;
    }
    // 0x800BFDA0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFDA4: lbu         $t9, 0xC($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XC);
    // 0x800BFDA8: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800BFDAC: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800BFDB0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800BFDB4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800BFDB8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800BFDBC: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BFDC0: bgtzl       $v1, L_800BFDD0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800BFDC4: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_800BFDD0;
    }
    goto skip_5;
    // 0x800BFDC4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_5:
    // 0x800BFDC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BFDCC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_800BFDD0:
    // 0x800BFDD0: beq         $at, $zero, L_800BFDE0
    if (ctx->r1 == 0) {
        // 0x800BFDD4: nop
    
            goto L_800BFDE0;
    }
    // 0x800BFDD4: nop

    // 0x800BFDD8: b           L_800BFDE0
    // 0x800BFDDC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
        goto L_800BFDE0;
    // 0x800BFDDC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
L_800BFDE0:
    // 0x800BFDE0: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFDE4: jal         0x800CA1A0
    // 0x800BFDE8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_17;
    // 0x800BFDE8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    after_17:
    // 0x800BFDEC: b           L_800BFFB4
    // 0x800BFDF0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFDF0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFDF4:
    // 0x800BFDF4: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = S32(MEM_W(ctx->r20, 0X8));
    // 0x800BFDF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BFDFC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFE00: swc1        $f0, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f0.u32l;
    // 0x800BFE04: ldc1        $f8, -0x66B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X66B0);
    // 0x800BFE08: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800BFE0C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BFE10: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800BFE14: nop

    // 0x800BFE18: bc1fl       L_800BFE2C
    if (!c1cs) {
        // 0x800BFE1C: lw          $t8, 0x28($s5)
        ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
            goto L_800BFE2C;
    }
    goto skip_6;
    // 0x800BFE1C: lw          $t8, 0x28($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
    skip_6:
    // 0x800BFE20: lwc1        $f10, -0x66A8($at)
    ctx->f10.u32l = S32(MEM_W(ctx->r1, -0X66A8));
    // 0x800BFE24: swc1        $f10, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f10.u32l;
    // 0x800BFE28: lw          $t8, 0x28($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
L_800BFE2C:
    // 0x800BFE2C: bnel        $fp, $t8, L_800BFFB4
    if (ctx->r30 != ctx->r24) {
        // 0x800BFE30: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_7;
    // 0x800BFE30: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_7:
    // 0x800BFE34: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFE38: jal         0x800CA2D0
    // 0x800BFE3C: lw          $a2, 0x24($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X24));
    alSynSetPitch(rdram, ctx);
        goto after_18;
    // 0x800BFE3C: lw          $a2, 0x24($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X24));
    after_18:
    // 0x800BFE40: b           L_800BFFB4
    // 0x800BFE44: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFE44: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFE48:
    // 0x800BFE48: lw          $t6, 0x28($s5)
    ctx->r14 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFE4C: lbu         $t9, 0x8($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X8);
    // 0x800BFE50: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFE54: bne         $fp, $t6, L_800BFFB0
    if (ctx->r30 != ctx->r14) {
        // 0x800BFE58: sb          $t9, 0x2F($s5)
        MEM_B(0X2F, ctx->r21) = ctx->r25;
            goto L_800BFFB0;
    }
    // 0x800BFE58: sb          $t9, 0x2F($s5)
    MEM_B(0X2F, ctx->r21) = ctx->r25;
    // 0x800BFE5C: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFE60: jal         0x800CA360
    // 0x800BFE64: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_19;
    // 0x800BFE64: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    after_19:
    // 0x800BFE68: b           L_800BFFB4
    // 0x800BFE6C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFE6C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFE70:
    // 0x800BFE70: lw          $t8, 0x28($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X28));
    // 0x800BFE74: lh          $t7, 0x8($s4)
    ctx->r15 = S32(MEM_H(ctx->r20, 0X8));
    // 0x800BFE78: bne         $fp, $t8, L_800BFFB0
    if (ctx->r30 != ctx->r24) {
        // 0x800BFE7C: sh          $t7, 0x2C($s5)
        MEM_H(0X2C, ctx->r21) = ctx->r15;
            goto L_800BFFB0;
    }
    // 0x800BFE7C: sh          $t7, 0x2C($s5)
    MEM_H(0X2C, ctx->r21) = ctx->r15;
    // 0x800BFE80: beql        $s1, $zero, L_800BFFB4
    if (ctx->r17 == 0) {
        // 0x800BFE84: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_8;
    // 0x800BFE84: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_8:
    // 0x800BFE88: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFE8C: lh          $t7, 0x2C($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X2C));
    // 0x800BFE90: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800BFE94: lbu         $t6, 0xD($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XD);
    // 0x800BFE98: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFE9C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFEA0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFEA4: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x800BFEA8: mflo        $t0
    ctx->r8 = lo;
    // 0x800BFEAC: nop

    // 0x800BFEB0: nop

    // 0x800BFEB4: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800BFEB8: mflo        $t8
    ctx->r24 = lo;
    // 0x800BFEBC: sll         $a2, $t8, 16
    ctx->r6 = S32(ctx->r24 << 16);
    // 0x800BFEC0: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BFEC4: jal         0x800CA230
    // 0x800BFEC8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    alSynSetVol(rdram, ctx);
        goto after_20;
    // 0x800BFEC8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_20:
    // 0x800BFECC: b           L_800BFFB4
    // 0x800BFED0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFED0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFED4:
    // 0x800BFED4: lw          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800BFED8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BFEDC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800BFEE0: lw          $v1, 0x4($a3)
    ctx->r3 = S32(MEM_W(ctx->r7, 0X4));
    // 0x800BFEE4: beql        $v1, $at, L_800BFFB4
    if (ctx->r3 == ctx->r1) {
        // 0x800BFEE8: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800BFFB4;
    }
    goto skip_9;
    // 0x800BFEE8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_9:
    // 0x800BFEEC: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
    // 0x800BFEF0: lh          $t7, 0x2C($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X2C));
    // 0x800BFEF4: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x800BFEF8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800BFEFC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BFF00: lwc1        $f2, 0x24($s5)
    ctx->f2.u32l = S32(MEM_W(ctx->r21, 0X24));
    // 0x800BFF04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BFF08: lui         $a3, 0x7FFF
    ctx->r7 = S32(0X7FFF << 16);
    // 0x800BFF0C: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BFF10: mflo        $t0
    ctx->r8 = lo;
    // 0x800BFF14: nop

    // 0x800BFF18: nop

    // 0x800BFF1C: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x800BFF20: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800BFF24: mflo        $t0
    ctx->r8 = lo;
    // 0x800BFF28: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x800BFF2C: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x800BFF30: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800BFF34: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800BFF38: bc1fl       L_800BFF4C
    if (!c1cs) {
        // 0x800BFF3C: trunc.w.d   $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
            goto L_800BFF4C;
    }
    goto skip_10;
    // 0x800BFF3C: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    skip_10:
    // 0x800BFF40: b           L_800BFF54
    // 0x800BFF44: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
        goto L_800BFF54;
    // 0x800BFF44: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x800BFF48: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
L_800BFF4C:
    // 0x800BFF4C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800BFF50: nop

L_800BFF54:
    // 0x800BFF54: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800BFF58: jal         0x800CA230
    // 0x800BFF5C: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    alSynSetVol(rdram, ctx);
        goto after_21;
    // 0x800BFF5C: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    after_21:
    // 0x800BFF60: sh          $fp, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r30;
    // 0x800BFF64: sw          $s5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r21;
    // 0x800BFF68: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800BFF6C: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x800BFF70: jal         0x800C9C6C
    // 0x800BFF74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_22;
    // 0x800BFF74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_22:
    // 0x800BFF78: b           L_800BFFB4
    // 0x800BFF7C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
        goto L_800BFFB4;
    // 0x800BFF7C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFF80:
    // 0x800BFF80: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFF84: jal         0x800CA400
    // 0x800BFF88: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_23;
    // 0x800BFF88: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_23:
    // 0x800BFF8C: lw          $a0, 0x38($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X38));
    // 0x800BFF90: jal         0x800CA480
    // 0x800BFF94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_24;
    // 0x800BFF94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_24:
    // 0x800BFF98: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800BFF9C: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800BFFA0: jal         0x800BFA30
    // 0x800BFFA4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    static_5_800BFA30(rdram, ctx);
        goto after_25;
    // 0x800BFFA4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    after_25:
    // 0x800BFFA8: lw          $s4, 0x4C($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800BFFAC: sw          $zero, 0x28($s5)
    MEM_W(0X28, ctx->r21) = 0;
L_800BFFB0:
    // 0x800BFFB0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800BFFB4:
    // 0x800BFFB4: jal         0x800C9D90
    // 0x800BFFB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alEvtqNextEvent(rdram, ctx);
        goto after_26;
    // 0x800BFFB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_26:
    // 0x800BFFBC: beq         $v0, $zero, L_800BFB04
    if (ctx->r2 == 0) {
        // 0x800BFFC0: sw          $v0, 0x4C($s6)
        MEM_W(0X4C, ctx->r22) = ctx->r2;
            goto L_800BFB04;
    }
    // 0x800BFFC0: sw          $v0, 0x4C($s6)
    MEM_W(0X4C, ctx->r22) = ctx->r2;
    // 0x800BFFC4: lw          $t7, 0x50($s6)
    ctx->r15 = S32(MEM_W(ctx->r22, 0X50));
    // 0x800BFFC8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800BFFCC: sw          $t8, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->r24;
    // 0x800BFFD0: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BFFD4: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800BFFD8: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800BFFDC: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800BFFE0: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800BFFE4: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800BFFE8: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BFFEC: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BFFF0: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BFFF4: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BFFF8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800BFFFC: jr          $ra
    // 0x800C0000: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800C0000: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void static_5_800C0150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0150: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800C0154: bne         $t6, $zero, L_800C0234
    if (ctx->r14 != 0) {
        // 0x800C0158: nop
    
            goto L_800C0234;
    }
    // 0x800C0158: nop

    // 0x800C015C: lh          $t7, 0xE($a0)
    ctx->r15 = S32(MEM_H(ctx->r4, 0XE));
    // 0x800C0160: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C0164: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x800C0168: blez        $t7, L_800C0234
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C016C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C0234;
    }
    // 0x800C016C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0170: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C0174: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C0178: lw          $t8, 0x10($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X10));
L_800C017C:
    // 0x800C017C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C0180: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C0184: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x800C0188: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C018C: bnel        $t6, $zero, L_800C0220
    if (ctx->r14 != 0) {
        // 0x800C0190: lh          $t8, 0xE($a0)
        ctx->r24 = S32(MEM_H(ctx->r4, 0XE));
            goto L_800C0220;
    }
    goto skip_0;
    // 0x800C0190: lh          $t8, 0xE($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0XE));
    skip_0:
    // 0x800C0194: lw          $t7, 0x0($t9)
    ctx->r15 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800C0198: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x800C019C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C01A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C01A4: lw          $t9, 0x4($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X4));
    // 0x800C01A8: lw          $t7, 0x8($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800C01AC: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x800C01B0: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C01B4: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800C01B8: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800C01BC: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x800C01C0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800C01C4: bnel        $t9, $zero, L_800C0220
    if (ctx->r25 != 0) {
        // 0x800C01C8: lh          $t8, 0xE($a0)
        ctx->r24 = S32(MEM_H(ctx->r4, 0XE));
            goto L_800C0220;
    }
    goto skip_1;
    // 0x800C01C8: lh          $t8, 0xE($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0XE));
    skip_1:
    // 0x800C01CC: lw          $t6, 0x0($t8)
    ctx->r14 = S32(MEM_W(ctx->r24, 0X0));
    // 0x800C01D0: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x800C01D4: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x800C01D8: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C01DC: bne         $a2, $zero, L_800C0204
    if (ctx->r6 != 0) {
        // 0x800C01E0: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_800C0204;
    }
    // 0x800C01E0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C01E4: lw          $t8, 0x10($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, 0X10));
    // 0x800C01E8: lw          $a2, 0xC($t0)
    ctx->r6 = S32(MEM_W(ctx->r8, 0XC));
    // 0x800C01EC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C01F0: beq         $a2, $zero, L_800C021C
    if (ctx->r6 == 0) {
        // 0x800C01F4: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_800C021C;
    }
    // 0x800C01F4: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x800C01F8: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x800C01FC: b           L_800C021C
    // 0x800C0200: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_800C021C;
    // 0x800C0200: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_800C0204:
    // 0x800C0204: bnel        $t2, $a2, L_800C0220
    if (ctx->r10 != ctx->r6) {
        // 0x800C0208: lh          $t8, 0xE($a0)
        ctx->r24 = S32(MEM_H(ctx->r4, 0XE));
            goto L_800C0220;
    }
    goto skip_2;
    // 0x800C0208: lh          $t8, 0xE($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0XE));
    skip_2:
    // 0x800C020C: lw          $a2, 0xC($t0)
    ctx->r6 = S32(MEM_W(ctx->r8, 0XC));
    // 0x800C0210: beq         $a2, $zero, L_800C021C
    if (ctx->r6 == 0) {
        // 0x800C0214: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_800C021C;
    }
    // 0x800C0214: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x800C0218: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_800C021C:
    // 0x800C021C: lh          $t8, 0xE($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0XE));
L_800C0220:
    // 0x800C0220: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C0224: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C0228: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C022C: bnel        $at, $zero, L_800C017C
    if (ctx->r1 != 0) {
        // 0x800C0230: lw          $t8, 0x10($v1)
        ctx->r24 = S32(MEM_W(ctx->r3, 0X10));
            goto L_800C017C;
    }
    goto skip_3;
    // 0x800C0230: lw          $t8, 0x10($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X10));
    skip_3:
L_800C0234:
    // 0x800C0234: jr          $ra
    // 0x800C0238: nop

    return;
    // 0x800C0238: nop

    // 0x800C023C: jr          $ra
    // 0x800C0240: nop

    return;
    // 0x800C0240: nop

;}
RECOMP_FUNC void static_5_800C04A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C04A0: lw          $v0, 0x18($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X18));
    // 0x800C04A4: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x800C04A8: beql        $v0, $zero, L_800C04CC
    if (ctx->r2 == 0) {
        // 0x800C04AC: sw          $t8, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r24;
            goto L_800C04CC;
    }
    goto skip_0;
    // 0x800C04AC: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    skip_0:
    // 0x800C04B0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = S32(MEM_W(ctx->r2, 0X8));
    // 0x800C04B4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800C04B8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C04BC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C04C0: jr          $ra
    // 0x800C04C4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    return;
    // 0x800C04C4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x800C04C8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
L_800C04CC:
    // 0x800C04CC: jr          $ra
    // 0x800C04D0: nop

    return;
    // 0x800C04D0: nop

    // 0x800C04D4: jr          $ra
    // 0x800C04D8: nop

    return;
    // 0x800C04D8: nop

;}
RECOMP_FUNC void static_5_800C04DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C04DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C04E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C04E4: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800C04E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C04EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C04F0: bne         $t6, $at, L_800C069C
    if (ctx->r14 != ctx->r1) {
        // 0x800C04F4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800C069C;
    }
    // 0x800C04F4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C04F8: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800C04FC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800C0500: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800C0504: bnel        $t7, $at, L_800C06A0
    if (ctx->r15 != ctx->r1) {
        // 0x800C0508: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800C06A0;
    }
    goto skip_0;
    // 0x800C0508: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800C050C: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x800C0510: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x800C0514: lw          $fp, 0x24($s7)
    ctx->r30 = S32(MEM_W(ctx->r23, 0X24));
    // 0x800C0518: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C051C: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x800C0520: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C0524: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C0528: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800C052C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800C0530: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800C0534: jal         0x800C04A0
    // 0x800C0538: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    static_5_800C04A0(rdram, ctx);
        goto after_0;
    // 0x800C0538: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800C053C: lw          $s1, 0x50($s7)
    ctx->r17 = S32(MEM_W(ctx->r23, 0X50));
    // 0x800C0540: beq         $s1, $zero, L_800C05B8
    if (ctx->r17 == 0) {
        // 0x800C0544: nop
    
            goto L_800C05B8;
    }
    // 0x800C0544: nop

    // 0x800C0548: addiu       $s4, $zero, 0x15
    ctx->r20 = ADD32(0, 0X15);
L_800C054C:
    // 0x800C054C: lh          $t7, 0xC($s1)
    ctx->r15 = S32(MEM_H(ctx->r17, 0XC));
    // 0x800C0550: lw          $t9, 0x8($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800C0554: lw          $s2, 0x0($s1)
    ctx->r18 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C0558: bne         $s4, $t7, L_800C05B0
    if (ctx->r20 != ctx->r15) {
        // 0x800C055C: addu        $s0, $s0, $t9
        ctx->r16 = ADD32(ctx->r16, ctx->r25);
            goto L_800C05B0;
    }
    // 0x800C055C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x800C0560: jal         0x800BF770
    // 0x800C0564: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C0564: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800C0568: beql        $s3, $zero, L_800C0588
    if (ctx->r19 == 0) {
        // 0x800C056C: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_800C0588;
    }
    goto skip_1;
    // 0x800C056C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_1:
    // 0x800C0570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C0574: jal         0x800BF7A0
    // 0x800C0578: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C0578: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x800C057C: b           L_800C0590
    // 0x800C0580: nop

        goto L_800C0590;
    // 0x800C0580: nop

    // 0x800C0584: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800C0588:
    // 0x800C0588: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x800C058C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
L_800C0590:
    // 0x800C0590: beq         $s2, $zero, L_800C05AC
    if (ctx->r18 == 0) {
        // 0x800C0594: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_800C05AC;
    }
    // 0x800C0594: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800C0598: lw          $v0, 0x8($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800C059C: lw          $t8, 0x8($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X8));
    // 0x800C05A0: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C05A4: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800C05A8: sw          $t6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r14;
L_800C05AC:
    // 0x800C05AC: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_800C05B0:
    // 0x800C05B0: bne         $s2, $zero, L_800C054C
    if (ctx->r18 != 0) {
        // 0x800C05B4: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800C054C;
    }
    // 0x800C05B4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_800C05B8:
    // 0x800C05B8: beq         $s3, $zero, L_800C069C
    if (ctx->r19 == 0) {
        // 0x800C05BC: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_800C069C;
    }
    // 0x800C05BC: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800C05C0: addiu       $s4, $s7, 0x48
    ctx->r20 = ADD32(ctx->r23, 0X48);
    // 0x800C05C4: addiu       $s5, $s4, 0x8
    ctx->r21 = ADD32(ctx->r20, 0X8);
    // 0x800C05C8: addiu       $s6, $zero, -0x8
    ctx->r22 = ADD32(0, -0X8);
L_800C05CC:
    // 0x800C05CC: lw          $t9, 0x8($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800C05D0: lw          $t7, 0x24($s7)
    ctx->r15 = S32(MEM_W(ctx->r23, 0X24));
    // 0x800C05D4: lw          $s2, 0x0($s1)
    ctx->r18 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C05D8: div         $zero, $t9, $fp
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r30)));
    // 0x800C05DC: mflo        $v0
    ctx->r2 = lo;
    // 0x800C05E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C05E4: bne         $fp, $zero, L_800C05F0
    if (ctx->r30 != 0) {
        // 0x800C05E8: nop
    
            goto L_800C05F0;
    }
    // 0x800C05E8: nop

    // 0x800C05EC: break       7
    do_break(2148271596);
L_800C05F0:
    // 0x800C05F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C05F4: bne         $fp, $at, L_800C0608
    if (ctx->r30 != ctx->r1) {
        // 0x800C05F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C0608;
    }
    // 0x800C05F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C05FC: bne         $t9, $at, L_800C0608
    if (ctx->r25 != ctx->r1) {
        // 0x800C0600: nop
    
            goto L_800C0608;
    }
    // 0x800C0600: nop

    // 0x800C0604: break       6
    do_break(2148271620);
L_800C0608:
    // 0x800C0608: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C060C: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x800C0610: mflo        $t8
    ctx->r24 = lo;
    // 0x800C0614: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x800C0618: jal         0x800BC180
    // 0x800C061C: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C061C: nop

    after_3:
    // 0x800C0620: beq         $s4, $s6, L_800C068C
    if (ctx->r20 == ctx->r22) {
        // 0x800C0624: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800C068C;
    }
    // 0x800C0624: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C0628: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
L_800C062C:
    // 0x800C062C: bnel        $a0, $zero, L_800C064C
    if (ctx->r4 != 0) {
        // 0x800C0630: lw          $v0, 0x8($s1)
        ctx->r2 = S32(MEM_W(ctx->r17, 0X8));
            goto L_800C064C;
    }
    goto skip_2;
    // 0x800C0630: lw          $v0, 0x8($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X8));
    skip_2:
    // 0x800C0634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C0638: jal         0x800BF7A0
    // 0x800C063C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800C063C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800C0640: b           L_800C068C
    // 0x800C0644: nop

        goto L_800C068C;
    // 0x800C0644: nop

    // 0x800C0648: lw          $v0, 0x8($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X8));
L_800C064C:
    // 0x800C064C: lw          $v1, 0x8($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800C0650: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C0654: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C0658: beq         $at, $zero, L_800C067C
    if (ctx->r1 == 0) {
        // 0x800C065C: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800C067C;
    }
    // 0x800C065C: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800C0660: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x800C0664: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800C0668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C066C: jal         0x800BF7A0
    // 0x800C0670: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800C0670: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800C0674: b           L_800C068C
    // 0x800C0678: nop

        goto L_800C068C;
    // 0x800C0678: nop

L_800C067C:
    // 0x800C067C: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x800C0680: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800C0684: bnel        $s0, $zero, L_800C062C
    if (ctx->r16 != 0) {
        // 0x800C0688: lw          $a0, 0x0($s0)
        ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C062C;
    }
    goto skip_3;
    // 0x800C0688: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    skip_3:
L_800C068C:
    // 0x800C068C: jal         0x800BC180
    // 0x800C0690: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800C0690: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x800C0694: bne         $s2, $zero, L_800C05CC
    if (ctx->r18 != 0) {
        // 0x800C0698: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800C05CC;
    }
    // 0x800C0698: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_800C069C:
    // 0x800C069C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C06A0:
    // 0x800C06A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C06A4: jr          $ra
    // 0x800C06A8: nop

    return;
    // 0x800C06A8: nop

;}
RECOMP_FUNC void static_5_800C06AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C06AC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C06B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C06B4: lbu         $s6, 0x8($t0)
    ctx->r22 = MEM_BU(ctx->r8, 0X8);
    // 0x800C06B8: lbu         $s4, 0x9($t0)
    ctx->r20 = MEM_BU(ctx->r8, 0X9);
    // 0x800C06BC: lbu         $s1, 0xA($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0XA);
    // 0x800C06C0: andi        $v1, $s6, 0xF0
    ctx->r3 = ctx->r22 & 0XF0;
    // 0x800C06C4: addiu       $t7, $v1, -0x80
    ctx->r15 = ADD32(ctx->r3, -0X80);
    // 0x800C06C8: sltiu       $at, $t7, 0x61
    ctx->r1 = ctx->r15 < 0X61 ? 1 : 0;
    // 0x800C06CC: andi        $t6, $s6, 0xF
    ctx->r14 = ctx->r22 & 0XF;
    // 0x800C06D0: beq         $at, $zero, L_800C0EC4
    if (ctx->r1 == 0) {
        // 0x800C06D4: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_800C0EC4;
    }
    // 0x800C06D4: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x800C06D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C06DC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C06E0: addu        $at, $at, $t7
    gpr jr_addend_800C06E8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C06E4: lw          $t7, -0x66A0($at)
    ctx->r15 = ADD32(ctx->r1, -0X66A0);
    // 0x800C06E8: jr          $t7
    // 0x800C06EC: nop

    switch (jr_addend_800C06E8 >> 2) {
        case 0: goto L_800C0A90; break;
        case 1: goto L_800C0EC4; break;
        case 2: goto L_800C0EC4; break;
        case 3: goto L_800C0EC4; break;
        case 4: goto L_800C0EC4; break;
        case 5: goto L_800C0EC4; break;
        case 6: goto L_800C0EC4; break;
        case 7: goto L_800C0EC4; break;
        case 8: goto L_800C0EC4; break;
        case 9: goto L_800C0EC4; break;
        case 10: goto L_800C0EC4; break;
        case 11: goto L_800C0EC4; break;
        case 12: goto L_800C0EC4; break;
        case 13: goto L_800C0EC4; break;
        case 14: goto L_800C0EC4; break;
        case 15: goto L_800C0EC4; break;
        case 16: goto L_800C06F0; break;
        case 17: goto L_800C0EC4; break;
        case 18: goto L_800C0EC4; break;
        case 19: goto L_800C0EC4; break;
        case 20: goto L_800C0EC4; break;
        case 21: goto L_800C0EC4; break;
        case 22: goto L_800C0EC4; break;
        case 23: goto L_800C0EC4; break;
        case 24: goto L_800C0EC4; break;
        case 25: goto L_800C0EC4; break;
        case 26: goto L_800C0EC4; break;
        case 27: goto L_800C0EC4; break;
        case 28: goto L_800C0EC4; break;
        case 29: goto L_800C0EC4; break;
        case 30: goto L_800C0EC4; break;
        case 31: goto L_800C0EC4; break;
        case 32: goto L_800C0AE8; break;
        case 33: goto L_800C0EC4; break;
        case 34: goto L_800C0EC4; break;
        case 35: goto L_800C0EC4; break;
        case 36: goto L_800C0EC4; break;
        case 37: goto L_800C0EC4; break;
        case 38: goto L_800C0EC4; break;
        case 39: goto L_800C0EC4; break;
        case 40: goto L_800C0EC4; break;
        case 41: goto L_800C0EC4; break;
        case 42: goto L_800C0EC4; break;
        case 43: goto L_800C0EC4; break;
        case 44: goto L_800C0EC4; break;
        case 45: goto L_800C0EC4; break;
        case 46: goto L_800C0EC4; break;
        case 47: goto L_800C0EC4; break;
        case 48: goto L_800C0BC0; break;
        case 49: goto L_800C0EC4; break;
        case 50: goto L_800C0EC4; break;
        case 51: goto L_800C0EC4; break;
        case 52: goto L_800C0EC4; break;
        case 53: goto L_800C0EC4; break;
        case 54: goto L_800C0EC4; break;
        case 55: goto L_800C0EC4; break;
        case 56: goto L_800C0EC4; break;
        case 57: goto L_800C0EC4; break;
        case 58: goto L_800C0EC4; break;
        case 59: goto L_800C0EC4; break;
        case 60: goto L_800C0EC4; break;
        case 61: goto L_800C0EC4; break;
        case 62: goto L_800C0EC4; break;
        case 63: goto L_800C0EC4; break;
        case 64: goto L_800C0DF8; break;
        case 65: goto L_800C0EC4; break;
        case 66: goto L_800C0EC4; break;
        case 67: goto L_800C0EC4; break;
        case 68: goto L_800C0EC4; break;
        case 69: goto L_800C0EC4; break;
        case 70: goto L_800C0EC4; break;
        case 71: goto L_800C0EC4; break;
        case 72: goto L_800C0EC4; break;
        case 73: goto L_800C0EC4; break;
        case 74: goto L_800C0EC4; break;
        case 75: goto L_800C0EC4; break;
        case 76: goto L_800C0EC4; break;
        case 77: goto L_800C0EC4; break;
        case 78: goto L_800C0EC4; break;
        case 79: goto L_800C0EC4; break;
        case 80: goto L_800C0B4C; break;
        case 81: goto L_800C0EC4; break;
        case 82: goto L_800C0EC4; break;
        case 83: goto L_800C0EC4; break;
        case 84: goto L_800C0EC4; break;
        case 85: goto L_800C0EC4; break;
        case 86: goto L_800C0EC4; break;
        case 87: goto L_800C0EC4; break;
        case 88: goto L_800C0EC4; break;
        case 89: goto L_800C0EC4; break;
        case 90: goto L_800C0EC4; break;
        case 91: goto L_800C0EC4; break;
        case 92: goto L_800C0EC4; break;
        case 93: goto L_800C0EC4; break;
        case 94: goto L_800C0EC4; break;
        case 95: goto L_800C0EC4; break;
        case 96: goto L_800C0E2C; break;
        default: switch_error(__func__, 0x800C06E8, 0x80109960);
    }
    // 0x800C06EC: nop

L_800C06F0:
    // 0x800C06F0: beql        $s1, $zero, L_800C0A94
    if (ctx->r17 == 0) {
        // 0x800C06F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C0A94;
    }
    goto skip_0;
    // 0x800C06F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x800C06F8: lw          $t8, 0x2C($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X2C));
    // 0x800C06FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C0700: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C0704: bne         $t8, $at, L_800C0EC4
    if (ctx->r24 != ctx->r1) {
        // 0x800C0708: andi        $a1, $s4, 0xFF
        ctx->r5 = ctx->r20 & 0XFF;
            goto L_800C0EC4;
    }
    // 0x800C0708: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C070C: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C0710: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800C0714: jal         0x800CAC30
    // 0x800C0718: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    __lookupSoundQuick(rdram, ctx);
        goto after_0;
    // 0x800C0718: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    after_0:
    // 0x800C071C: beq         $v0, $zero, L_800C0EC4
    if (ctx->r2 == 0) {
        // 0x800C0720: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_800C0EC4;
    }
    // 0x800C0720: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800C0724: lw          $t9, 0x60($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C0728: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800C072C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C0730: addu        $t6, $t9, $fp
    ctx->r14 = ADD32(ctx->r25, ctx->r30);
    // 0x800C0734: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x800C0738: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x800C073C: sb          $zero, 0x78($sp)
    MEM_B(0X78, ctx->r29) = 0;
    // 0x800C0740: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C0744: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C0748: andi        $a3, $s6, 0xFF
    ctx->r7 = ctx->r22 & 0XFF;
    // 0x800C074C: jal         0x800CABC0
    // 0x800C0750: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    __mapVoice(rdram, ctx);
        goto after_1;
    // 0x800C0750: sh          $t7, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r15;
    after_1:
    // 0x800C0754: beq         $v0, $zero, L_800C0EC4
    if (ctx->r2 == 0) {
        // 0x800C0758: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C0EC4;
    }
    // 0x800C0758: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C075C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C0760: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800C0764: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x800C0768: jal         0x800C9FC8
    // 0x800C076C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    alSynAllocVoice(rdram, ctx);
        goto after_2;
    // 0x800C076C: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x800C0770: sw          $s7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r23;
    // 0x800C0774: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x800C0778: lw          $t8, 0x60($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C077C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800C0780: addu        $t9, $t8, $fp
    ctx->r25 = ADD32(ctx->r24, ctx->r30);
    // 0x800C0784: lbu         $t6, 0xB($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XB);
    // 0x800C0788: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x800C078C: bnel        $at, $zero, L_800C07A0
    if (ctx->r1 != 0) {
        // 0x800C0790: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_800C07A0;
    }
    goto skip_1;
    // 0x800C0790: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_1:
    // 0x800C0794: b           L_800C07A0
    // 0x800C0798: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800C07A0;
    // 0x800C0798: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
    // 0x800C079C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800C07A0:
    // 0x800C07A0: lw          $v0, 0x4($s7)
    ctx->r2 = S32(MEM_W(ctx->r23, 0X4));
    // 0x800C07A4: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C07A8: lb          $t6, 0x5($v0)
    ctx->r14 = S32(MEM_B(ctx->r2, 0X5));
    // 0x800C07AC: subu        $t8, $s4, $t7
    ctx->r24 = SUB32(ctx->r20, ctx->r15);
    // 0x800C07B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C07B4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C07B8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C07BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C07C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C07C4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x800C07C8: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800C07CC: jal         0x800CBE70
    // 0x800C07D0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x800C07D0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x800C07D4: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x800C07D8: lw          $t9, 0x0($s7)
    ctx->r25 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800C07DC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800C07E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C07E4: lbu         $t6, 0xC($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XC);
    // 0x800C07E8: sb          $t6, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r14;
    // 0x800C07EC: lw          $t8, 0x0($s7)
    ctx->r24 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800C07F0: lw          $t7, 0x1C($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X1C));
    // 0x800C07F4: lw          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X0));
    // 0x800C07F8: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x800C07FC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800C0800: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x800C0804: lw          $t8, 0x60($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C0808: addu        $t7, $t8, $fp
    ctx->r15 = ADD32(ctx->r24, ctx->r30);
    // 0x800C080C: lw          $s1, 0x0($t7)
    ctx->r17 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800C0810: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800C0814: lbu         $a2, 0x4($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X4);
    // 0x800C0818: beql        $a2, $zero, L_800C0884
    if (ctx->r6 == 0) {
        // 0x800C081C: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800C0884;
    }
    goto skip_2;
    // 0x800C081C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_2:
    // 0x800C0820: lw          $v0, 0x70($s2)
    ctx->r2 = S32(MEM_W(ctx->r18, 0X70));
    // 0x800C0824: beql        $v0, $zero, L_800C0884
    if (ctx->r2 == 0) {
        // 0x800C0828: cfc1        $t8, $FpcCsr
        ctx->r24 = get_cop1_cs();
            goto L_800C0884;
    }
    goto skip_3;
    // 0x800C0828: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    skip_3:
    // 0x800C082C: lbu         $t9, 0x6($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6);
    // 0x800C0830: lbu         $a3, 0x5($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X5);
    // 0x800C0834: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800C0838: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C083C: lbu         $t6, 0x7($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X7);
    // 0x800C0840: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800C0844: jalr        $v0
    // 0x800C0848: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800C0848: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x800C084C: beq         $v0, $zero, L_800C0880
    if (ctx->r2 == 0) {
        // 0x800C0850: addiu       $t8, $zero, 0x16
        ctx->r24 = ADD32(0, 0X16);
            goto L_800C0880;
    }
    // 0x800C0850: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800C0854: lw          $t7, 0x5C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800C0858: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C085C: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800C0860: addiu       $a0, $s2, 0x48
    ctx->r4 = ADD32(ctx->r18, 0X48);
    // 0x800C0864: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C0868: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C086C: jal         0x800C9C6C
    // 0x800C0870: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x800C0870: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_5:
    // 0x800C0874: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800C0878: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x800C087C: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800C0880:
    // 0x800C0880: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_800C0884:
    // 0x800C0884: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C0888: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C088C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X64));
    // 0x800C0890: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C0894: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C0898: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C089C: nop

    // 0x800C08A0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800C08A4: beql        $t7, $zero, L_800C08F4
    if (ctx->r15 == 0) {
        // 0x800C08A8: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_800C08F4;
    }
    goto skip_4;
    // 0x800C08A8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x800C08AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C08B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C08B4: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C08B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C08BC: nop

    // 0x800C08C0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C08C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C08C8: nop

    // 0x800C08CC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800C08D0: bne         $t7, $zero, L_800C08E8
    if (ctx->r15 != 0) {
        // 0x800C08D4: nop
    
            goto L_800C08E8;
    }
    // 0x800C08D4: nop

    // 0x800C08D8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800C08DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C08E0: b           L_800C0900
    // 0x800C08E4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800C0900;
    // 0x800C08E4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800C08E8:
    // 0x800C08E8: b           L_800C0900
    // 0x800C08EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800C0900;
    // 0x800C08EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C08F0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_800C08F4:
    // 0x800C08F4: nop

    // 0x800C08F8: bltz        $t7, L_800C08E8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800C08FC: nop
    
            goto L_800C08E8;
    }
    // 0x800C08FC: nop

L_800C0900:
    // 0x800C0900: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0904: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0908: sb          $t7, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r15;
    // 0x800C090C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0910: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800C0914: lbu         $a2, 0x8($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X8);
    // 0x800C0918: addiu       $s5, $s2, 0x48
    ctx->r21 = ADD32(ctx->r18, 0X48);
    // 0x800C091C: beql        $a2, $zero, L_800C098C
    if (ctx->r6 == 0) {
        // 0x800C0920: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X64));
            goto L_800C098C;
    }
    goto skip_5;
    // 0x800C0920: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X64));
    skip_5:
    // 0x800C0924: lw          $v0, 0x70($s2)
    ctx->r2 = S32(MEM_W(ctx->r18, 0X70));
    // 0x800C0928: beql        $v0, $zero, L_800C098C
    if (ctx->r2 == 0) {
        // 0x800C092C: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X64));
            goto L_800C098C;
    }
    goto skip_6;
    // 0x800C092C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X64));
    skip_6:
    // 0x800C0930: lbu         $t9, 0xA($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XA);
    // 0x800C0934: lbu         $a3, 0x9($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X9);
    // 0x800C0938: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800C093C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C0940: lbu         $t6, 0xB($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XB);
    // 0x800C0944: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800C0948: jalr        $v0
    // 0x800C094C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800C094C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x800C0950: beq         $v0, $zero, L_800C0988
    if (ctx->r2 == 0) {
        // 0x800C0954: addiu       $t8, $zero, 0x17
        ctx->r24 = ADD32(0, 0X17);
            goto L_800C0988;
    }
    // 0x800C0954: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x800C0958: lw          $t7, 0x5C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800C095C: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C0960: sw          $s0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r16;
    // 0x800C0964: sb          $s6, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r22;
    // 0x800C0968: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C096C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C0970: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C0974: jal         0x800C9C6C
    // 0x800C0978: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x800C0978: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    after_7:
    // 0x800C097C: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x800C0980: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x800C0984: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_800C0988:
    // 0x800C0988: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X64));
L_800C098C:
    // 0x800C098C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = S32(MEM_W(ctx->r16, 0X28));
    // 0x800C0990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0994: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800C0998: lw          $t8, 0x60($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C099C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = S32(MEM_W(ctx->r16, 0X2C));
    // 0x800C09A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C09A4: addu        $v0, $t8, $fp
    ctx->r2 = ADD32(ctx->r24, ctx->r30);
    // 0x800C09A8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = S32(MEM_W(ctx->r2, 0XC));
    // 0x800C09AC: lbu         $s1, 0xA($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0XA);
    // 0x800C09B0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C09B4: nop

    // 0x800C09B8: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800C09BC: jal         0x800CAB04
    // 0x800C09C0: nop

    __vsPan(rdram, ctx);
        goto after_8;
    // 0x800C09C0: nop

    after_8:
    // 0x800C09C4: andi        $fp, $v0, 0xFF
    ctx->r30 = ctx->r2 & 0XFF;
    // 0x800C09C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C09CC: jal         0x800CA6E4
    // 0x800C09D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_9;
    // 0x800C09D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x800C09D4: lw          $t7, 0x0($s7)
    ctx->r15 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800C09D8: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C09DC: lw          $a2, 0x8($s7)
    ctx->r6 = S32(MEM_W(ctx->r23, 0X8));
    // 0x800C09E0: lw          $s3, 0x0($t7)
    ctx->r19 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800C09E4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C09E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C09EC: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    // 0x800C09F0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C09F4: lw          $a1, 0x38($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C09F8: jal         0x800CBEC0
    // 0x800C09FC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    alSynStartVoiceParams(rdram, ctx);
        goto after_10;
    // 0x800C09FC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    after_10:
    // 0x800C0A00: lw          $t6, 0x38($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C0A04: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800C0A08: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x800C0A0C: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x800C0A10: lw          $t8, 0x0($s7)
    ctx->r24 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800C0A14: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C0A18: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C0A1C: lbu         $t7, 0xD($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XD);
    // 0x800C0A20: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C0A24: sb          $t7, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r15;
    // 0x800C0A28: lw          $t9, 0x0($s7)
    ctx->r25 = S32(MEM_W(ctx->r23, 0X0));
    // 0x800C0A2C: lw          $t6, 0x4($t9)
    ctx->r14 = S32(MEM_W(ctx->r25, 0X4));
    // 0x800C0A30: jal         0x800C9C6C
    // 0x800C0A34: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    alEvtqPostEvent(rdram, ctx);
        goto after_11;
    // 0x800C0A34: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    after_11:
    // 0x800C0A38: lw          $v0, 0xBC($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800C0A3C: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x800C0A40: ori         $t9, $s6, 0x80
    ctx->r25 = ctx->r22 | 0X80;
    // 0x800C0A44: lw          $t8, 0xC($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800C0A48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C0A4C: beql        $t8, $zero, L_800C0EC8
    if (ctx->r24 == 0) {
        // 0x800C0A50: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C0EC8;
    }
    goto skip_7;
    // 0x800C0A50: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_7:
    // 0x800C0A54: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x800C0A58: sb          $t9, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r25;
    // 0x800C0A5C: sb          $s4, 0x95($sp)
    MEM_B(0X95, ctx->r29) = ctx->r20;
    // 0x800C0A60: sb          $zero, 0x96($sp)
    MEM_B(0X96, ctx->r29) = 0;
    // 0x800C0A64: lw          $t8, 0x8($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X8));
    // 0x800C0A68: lw          $t6, 0x24($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X24));
    // 0x800C0A6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C0A70: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C0A74: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0A78: mflo        $s3
    ctx->r19 = lo;
    // 0x800C0A7C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C0A80: jal         0x800C9C6C
    // 0x800C0A84: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_12;
    // 0x800C0A84: nop

    after_12:
    // 0x800C0A88: b           L_800C0EC8
    // 0x800C0A8C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0A8C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0A90:
    // 0x800C0A90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C0A94:
    // 0x800C0A94: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C0A98: jal         0x800CAB4C
    // 0x800C0A9C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_13;
    // 0x800C0A9C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_13:
    // 0x800C0AA0: beq         $v0, $zero, L_800C0EC4
    if (ctx->r2 == 0) {
        // 0x800C0AA4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C0EC4;
    }
    // 0x800C0AA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C0AA8: lbu         $t7, 0x35($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X35);
    // 0x800C0AAC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800C0AB0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800C0AB4: bne         $s6, $t7, L_800C0AC4
    if (ctx->r22 != ctx->r15) {
        // 0x800C0AB8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C0AC4;
    }
    // 0x800C0AB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C0ABC: b           L_800C0EC4
    // 0x800C0AC0: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
        goto L_800C0EC4;
    // 0x800C0AC0: sb          $t9, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r25;
L_800C0AC4:
    // 0x800C0AC4: lw          $t6, 0x20($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X20));
    // 0x800C0AC8: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800C0ACC: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800C0AD0: lw          $t8, 0x0($t6)
    ctx->r24 = S32(MEM_W(ctx->r14, 0X0));
    // 0x800C0AD4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C0AD8: jal         0x800CA76C
    // 0x800C0ADC: lw          $a2, 0x8($t8)
    ctx->r6 = S32(MEM_W(ctx->r24, 0X8));
    __seqpReleaseVoice(rdram, ctx);
        goto after_14;
    // 0x800C0ADC: lw          $a2, 0x8($t8)
    ctx->r6 = S32(MEM_W(ctx->r24, 0X8));
    after_14:
    // 0x800C0AE0: b           L_800C0EC8
    // 0x800C0AE4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0AE4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0AE8:
    // 0x800C0AE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C0AEC: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x800C0AF0: jal         0x800CAB4C
    // 0x800C0AF4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    __lookupVoice(rdram, ctx);
        goto after_15;
    // 0x800C0AF4: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    after_15:
    // 0x800C0AF8: beq         $v0, $zero, L_800C0EC4
    if (ctx->r2 == 0) {
        // 0x800C0AFC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C0EC4;
    }
    // 0x800C0AFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C0B00: sb          $s1, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r17;
    // 0x800C0B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C0B08: jal         0x800CA6E4
    // 0x800C0B0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_16;
    // 0x800C0B0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x800C0B10: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C0B14: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C0B18: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800C0B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0B20: jal         0x800CA6C0
    // 0x800C0B24: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    __vsDelta(rdram, ctx);
        goto after_17;
    // 0x800C0B24: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    after_17:
    // 0x800C0B28: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C0B2C: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C0B30: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C0B34: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C0B38: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C0B3C: jal         0x800CA230
    // 0x800C0B40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_18;
    // 0x800C0B40: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_18:
    // 0x800C0B44: b           L_800C0EC8
    // 0x800C0B48: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0B48: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0B4C:
    // 0x800C0B4C: lw          $s0, 0x64($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C0B50: beql        $s0, $zero, L_800C0EC8
    if (ctx->r16 == 0) {
        // 0x800C0B54: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C0EC8;
    }
    goto skip_8;
    // 0x800C0B54: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_8:
    // 0x800C0B58: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C0B5C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800C0B60:
    // 0x800C0B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0B64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C0B68: bnel        $s3, $t6, L_800C0BB0
    if (ctx->r19 != ctx->r14) {
        // 0x800C0B6C: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0BB0;
    }
    goto skip_9;
    // 0x800C0B6C: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_9:
    // 0x800C0B70: jal         0x800CA6E4
    // 0x800C0B74: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    __vsVol(rdram, ctx);
        goto after_19;
    // 0x800C0B74: sb          $s4, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r20;
    after_19:
    // 0x800C0B78: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C0B7C: sra         $t8, $s1, 16
    ctx->r24 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C0B80: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800C0B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0B88: jal         0x800CA6C0
    // 0x800C0B8C: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    __vsDelta(rdram, ctx);
        goto after_20;
    // 0x800C0B8C: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    after_20:
    // 0x800C0B90: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C0B94: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C0B98: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C0B9C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C0BA0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C0BA4: jal         0x800CA230
    // 0x800C0BA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_21;
    // 0x800C0BA8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_21:
    // 0x800C0BAC: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
L_800C0BB0:
    // 0x800C0BB0: bnel        $s0, $zero, L_800C0B60
    if (ctx->r16 != 0) {
        // 0x800C0BB4: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800C0B60;
    }
    goto skip_10;
    // 0x800C0BB4: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_10:
    // 0x800C0BB8: b           L_800C0EC8
    // 0x800C0BBC: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0BBC: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0BC0:
    // 0x800C0BC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800C0BC4: beq         $s4, $at, L_800C0C54
    if (ctx->r20 == ctx->r1) {
        // 0x800C0BC8: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_800C0C54;
    }
    // 0x800C0BC8: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800C0BCC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800C0BD0: beq         $v0, $at, L_800C0BF8
    if (ctx->r2 == ctx->r1) {
        // 0x800C0BD4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800C0BF8;
    }
    // 0x800C0BD4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C0BD8: beq         $v0, $at, L_800C0CE4
    if (ctx->r2 == ctx->r1) {
        // 0x800C0BDC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800C0CE4;
    }
    // 0x800C0BDC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800C0BE0: beq         $v0, $at, L_800C0CF8
    if (ctx->r2 == ctx->r1) {
        // 0x800C0BE4: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_800C0CF8;
    }
    // 0x800C0BE4: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x800C0BE8: beql        $v0, $at, L_800C0DAC
    if (ctx->r2 == ctx->r1) {
        // 0x800C0BEC: lw          $t9, 0x60($s2)
        ctx->r25 = S32(MEM_W(ctx->r18, 0X60));
            goto L_800C0DAC;
    }
    goto skip_11;
    // 0x800C0BEC: lw          $t9, 0x60($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X60));
    skip_11:
    // 0x800C0BF0: b           L_800C0EC8
    // 0x800C0BF4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0BF4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0BF8:
    // 0x800C0BF8: lw          $t9, 0x60($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C0BFC: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C0C00: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C0C04: sb          $s1, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r17;
    // 0x800C0C08: lw          $s0, 0x64($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C0C0C: beql        $s0, $zero, L_800C0EC8
    if (ctx->r16 == 0) {
        // 0x800C0C10: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C0EC8;
    }
    goto skip_12;
    // 0x800C0C10: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_12:
    // 0x800C0C14: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C0C18: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C0C1C:
    // 0x800C0C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0C20: bnel        $s3, $t7, L_800C0C44
    if (ctx->r19 != ctx->r15) {
        // 0x800C0C24: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0C44;
    }
    goto skip_13;
    // 0x800C0C24: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_13:
    // 0x800C0C28: jal         0x800CAB04
    // 0x800C0C2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsPan(rdram, ctx);
        goto after_22;
    // 0x800C0C2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_22:
    // 0x800C0C30: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C0C34: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C0C38: jal         0x800CA1A0
    // 0x800C0C3C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    alSynSetPan(rdram, ctx);
        goto after_23;
    // 0x800C0C3C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_23:
    // 0x800C0C40: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
L_800C0C44:
    // 0x800C0C44: bnel        $s0, $zero, L_800C0C1C
    if (ctx->r16 != 0) {
        // 0x800C0C48: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C0C1C;
    }
    goto skip_14;
    // 0x800C0C48: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_14:
    // 0x800C0C4C: b           L_800C0EC8
    // 0x800C0C50: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0C50: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0C54:
    // 0x800C0C54: lw          $t9, 0x60($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C0C58: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C0C5C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C0C60: sb          $s1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r17;
    // 0x800C0C64: lw          $s0, 0x64($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C0C68: beql        $s0, $zero, L_800C0EC8
    if (ctx->r16 == 0) {
        // 0x800C0C6C: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C0EC8;
    }
    goto skip_15;
    // 0x800C0C6C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_15:
    // 0x800C0C70: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C0C74: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800C0C78: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C0C7C:
    // 0x800C0C7C: bnel        $s3, $t7, L_800C0CD4
    if (ctx->r19 != ctx->r15) {
        // 0x800C0C80: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0CD4;
    }
    goto skip_16;
    // 0x800C0C80: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_16:
    // 0x800C0C84: lbu         $t9, 0x34($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X34);
    // 0x800C0C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0C8C: beql        $s4, $t9, L_800C0CD4
    if (ctx->r20 == ctx->r25) {
        // 0x800C0C90: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0CD4;
    }
    goto skip_17;
    // 0x800C0C90: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_17:
    // 0x800C0C94: jal         0x800CA6E4
    // 0x800C0C98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_24;
    // 0x800C0C98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x800C0C9C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800C0CA0: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800C0CA4: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800C0CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0CAC: jal         0x800CA6C0
    // 0x800C0CB0: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    __vsDelta(rdram, ctx);
        goto after_25;
    // 0x800C0CB0: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    after_25:
    // 0x800C0CB4: sll         $a2, $s1, 16
    ctx->r6 = S32(ctx->r17 << 16);
    // 0x800C0CB8: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C0CBC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C0CC0: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C0CC4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C0CC8: jal         0x800CA230
    // 0x800C0CCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_26;
    // 0x800C0CCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_26:
    // 0x800C0CD0: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
L_800C0CD4:
    // 0x800C0CD4: bnel        $s0, $zero, L_800C0C7C
    if (ctx->r16 != 0) {
        // 0x800C0CD8: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C0C7C;
    }
    goto skip_18;
    // 0x800C0CD8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_18:
    // 0x800C0CDC: b           L_800C0EC8
    // 0x800C0CE0: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0CE0: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0CE4:
    // 0x800C0CE4: lw          $t7, 0x60($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C0CE8: sll         $t9, $s6, 4
    ctx->r25 = S32(ctx->r22 << 4);
    // 0x800C0CEC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800C0CF0: b           L_800C0EC4
    // 0x800C0CF4: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
        goto L_800C0EC4;
    // 0x800C0CF4: sb          $s1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r17;
L_800C0CF8:
    // 0x800C0CF8: lw          $t8, 0x60($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C0CFC: sll         $t7, $s6, 4
    ctx->r15 = S32(ctx->r22 << 4);
    // 0x800C0D00: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0D04: sb          $s1, 0xB($t9)
    MEM_B(0XB, ctx->r25) = ctx->r17;
    // 0x800C0D08: lw          $s0, 0x64($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C0D0C: beql        $s0, $zero, L_800C0EC8
    if (ctx->r16 == 0) {
        // 0x800C0D10: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C0EC8;
    }
    goto skip_19;
    // 0x800C0D10: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_19:
    // 0x800C0D14: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C0D18: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800C0D1C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800C0D20: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x800C0D24: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800C0D28: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800C0D2C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_800C0D30:
    // 0x800C0D30: bnel        $s3, $t6, L_800C0D98
    if (ctx->r19 != ctx->r14) {
        // 0x800C0D34: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0D98;
    }
    goto skip_20;
    // 0x800C0D34: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_20:
    // 0x800C0D38: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800C0D3C: slti        $at, $s1, 0x40
    ctx->r1 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x800C0D40: beql        $s4, $v0, L_800C0D98
    if (ctx->r20 == ctx->r2) {
        // 0x800C0D44: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0D98;
    }
    goto skip_21;
    // 0x800C0D44: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_21:
    // 0x800C0D48: bne         $at, $zero, L_800C0D60
    if (ctx->r1 != 0) {
        // 0x800C0D4C: nop
    
            goto L_800C0D60;
    }
    // 0x800C0D4C: nop

    // 0x800C0D50: bnel        $v0, $zero, L_800C0D98
    if (ctx->r2 != 0) {
        // 0x800C0D54: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0D98;
    }
    goto skip_22;
    // 0x800C0D54: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_22:
    // 0x800C0D58: b           L_800C0D94
    // 0x800C0D5C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
        goto L_800C0D94;
    // 0x800C0D5C: sb          $s5, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r21;
L_800C0D60:
    // 0x800C0D60: bne         $s6, $v0, L_800C0D70
    if (ctx->r22 != ctx->r2) {
        // 0x800C0D64: nop
    
            goto L_800C0D70;
    }
    // 0x800C0D64: nop

    // 0x800C0D68: b           L_800C0D94
    // 0x800C0D6C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_800C0D94;
    // 0x800C0D6C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_800C0D70:
    // 0x800C0D70: bnel        $s7, $v0, L_800C0D98
    if (ctx->r23 != ctx->r2) {
        // 0x800C0D74: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0D98;
    }
    goto skip_23;
    // 0x800C0D74: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_23:
    // 0x800C0D78: lw          $t8, 0x20($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X20));
    // 0x800C0D7C: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x800C0D80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C0D84: lw          $t7, 0x0($t8)
    ctx->r15 = S32(MEM_W(ctx->r24, 0X0));
    // 0x800C0D88: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C0D8C: jal         0x800CA76C
    // 0x800C0D90: lw          $a2, 0x8($t7)
    ctx->r6 = S32(MEM_W(ctx->r15, 0X8));
    __seqpReleaseVoice(rdram, ctx);
        goto after_27;
    // 0x800C0D90: lw          $a2, 0x8($t7)
    ctx->r6 = S32(MEM_W(ctx->r15, 0X8));
    after_27:
L_800C0D94:
    // 0x800C0D94: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
L_800C0D98:
    // 0x800C0D98: bnel        $s0, $zero, L_800C0D30
    if (ctx->r16 != 0) {
        // 0x800C0D9C: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_800C0D30;
    }
    goto skip_24;
    // 0x800C0D9C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x800C0DA0: b           L_800C0EC8
    // 0x800C0DA4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0DA4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C0DA8: lw          $t9, 0x60($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X60));
L_800C0DAC:
    // 0x800C0DAC: sll         $t6, $s6, 4
    ctx->r14 = S32(ctx->r22 << 4);
    // 0x800C0DB0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800C0DB4: sb          $s1, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r17;
    // 0x800C0DB8: lw          $s0, 0x64($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C0DBC: beql        $s0, $zero, L_800C0EC8
    if (ctx->r16 == 0) {
        // 0x800C0DC0: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C0EC8;
    }
    goto skip_25;
    // 0x800C0DC0: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_25:
    // 0x800C0DC4: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C0DC8: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
L_800C0DCC:
    // 0x800C0DCC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C0DD0: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    // 0x800C0DD4: bnel        $s3, $t7, L_800C0DE8
    if (ctx->r19 != ctx->r15) {
        // 0x800C0DD8: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0DE8;
    }
    goto skip_26;
    // 0x800C0DD8: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_26:
    // 0x800C0DDC: jal         0x800CA360
    // 0x800C0DE0: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    alSynSetFXMix(rdram, ctx);
        goto after_28;
    // 0x800C0DE0: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    after_28:
    // 0x800C0DE4: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
L_800C0DE8:
    // 0x800C0DE8: bnel        $s0, $zero, L_800C0DCC
    if (ctx->r16 != 0) {
        // 0x800C0DEC: lbu         $t7, 0x31($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X31);
            goto L_800C0DCC;
    }
    goto skip_27;
    // 0x800C0DEC: lbu         $t7, 0x31($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x800C0DF0: b           L_800C0EC8
    // 0x800C0DF4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0DF4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0DF8:
    // 0x800C0DF8: lw          $v0, 0x20($s2)
    ctx->r2 = S32(MEM_W(ctx->r18, 0X20));
    // 0x800C0DFC: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x800C0E00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C0E04: lh          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X0));
    // 0x800C0E08: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800C0E0C: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800C0E10: slt         $at, $s4, $t9
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C0E14: beql        $at, $zero, L_800C0EC8
    if (ctx->r1 == 0) {
        // 0x800C0E18: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C0EC8;
    }
    goto skip_28;
    // 0x800C0E18: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_28:
    // 0x800C0E1C: jal         0x800CA530
    // 0x800C0E20: lw          $a1, 0xC($t8)
    ctx->r5 = S32(MEM_W(ctx->r24, 0XC));
    __setInstChanState(rdram, ctx);
        goto after_29;
    // 0x800C0E20: lw          $a1, 0xC($t8)
    ctx->r5 = S32(MEM_W(ctx->r24, 0XC));
    after_29:
    // 0x800C0E24: b           L_800C0EC8
    // 0x800C0E28: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800C0EC8;
    // 0x800C0E28: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0E2C:
    // 0x800C0E2C: lw          $t7, 0x60($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C0E30: sll         $fp, $s6, 4
    ctx->r30 = S32(ctx->r22 << 4);
    // 0x800C0E34: sll         $t8, $s1, 7
    ctx->r24 = S32(ctx->r17 << 7);
    // 0x800C0E38: addu        $t9, $t7, $fp
    ctx->r25 = ADD32(ctx->r15, ctx->r30);
    // 0x800C0E3C: lh          $t6, 0x4($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X4));
    // 0x800C0E40: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x800C0E44: addiu       $t9, $t7, -0x2000
    ctx->r25 = ADD32(ctx->r15, -0X2000);
    // 0x800C0E48: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0E4C: mflo        $a0
    ctx->r4 = lo;
    // 0x800C0E50: bgez        $a0, L_800C0E60
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800C0E54: sra         $t8, $a0, 13
        ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
            goto L_800C0E60;
    }
    // 0x800C0E54: sra         $t8, $a0, 13
    ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
    // 0x800C0E58: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
    // 0x800C0E5C: sra         $t8, $at, 13
    ctx->r24 = S32(SIGNED(ctx->r1) >> 13);
L_800C0E60:
    // 0x800C0E60: jal         0x800CBE70
    // 0x800C0E64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    alCents2Ratio(rdram, ctx);
        goto after_30;
    // 0x800C0E64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_30:
    // 0x800C0E68: lw          $t7, 0x60($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C0E6C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C0E70: addu        $t6, $t7, $fp
    ctx->r14 = ADD32(ctx->r15, ctx->r30);
    // 0x800C0E74: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x800C0E78: lw          $s0, 0x64($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C0E7C: beql        $s0, $zero, L_800C0EC8
    if (ctx->r16 == 0) {
        // 0x800C0E80: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800C0EC8;
    }
    goto skip_29;
    // 0x800C0E80: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_29:
    // 0x800C0E84: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    // 0x800C0E88: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
L_800C0E8C:
    // 0x800C0E8C: bnel        $s3, $t9, L_800C0EBC
    if (ctx->r19 != ctx->r25) {
        // 0x800C0E90: lw          $s0, 0x0($s0)
        ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C0EBC;
    }
    goto skip_30;
    // 0x800C0E90: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
    skip_30:
    // 0x800C0E94: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = S32(MEM_W(ctx->r16, 0X28));
    // 0x800C0E98: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = S32(MEM_W(ctx->r16, 0X2C));
    // 0x800C0E9C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C0EA0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C0EA4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800C0EA8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C0EAC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C0EB0: jal         0x800CA2D0
    // 0x800C0EB4: nop

    alSynSetPitch(rdram, ctx);
        goto after_31;
    // 0x800C0EB4: nop

    after_31:
    // 0x800C0EB8: lw          $s0, 0x0($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X0));
L_800C0EBC:
    // 0x800C0EBC: bnel        $s0, $zero, L_800C0E8C
    if (ctx->r16 != 0) {
        // 0x800C0EC0: lbu         $t9, 0x31($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X31);
            goto L_800C0E8C;
    }
    goto skip_31;
    // 0x800C0EC0: lbu         $t9, 0x31($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X31);
    skip_31:
L_800C0EC4:
    // 0x800C0EC4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800C0EC8:
    // 0x800C0EC8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x800C0ECC: jr          $ra
    // 0x800C0ED0: nop

    return;
    // 0x800C0ED0: nop

    // 0x800C0ED4: jr          $ra
    // 0x800C0ED8: nop

    return;
    // 0x800C0ED8: nop

    // 0x800C0EDC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800C0EE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C0EE4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C0EE8: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x800C0EEC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C0EF0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C0EF4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C0EF8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C0EFC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C0F00: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C0F04: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C0F08: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C0F0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C0F10: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C0F14: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800C0F18: addiu       $s5, $a0, 0x48
    ctx->r21 = ADD32(ctx->r4, 0X48);
L_800C0F1C:
    // 0x800C0F1C: lhu         $t7, 0x38($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X38);
    // 0x800C0F20: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x800C0F24: beq         $at, $zero, L_800C149C
    if (ctx->r1 == 0) {
        // 0x800C0F28: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C149C;
    }
    // 0x800C0F28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0F2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C0F30: addu        $at, $at, $t7
    gpr jr_addend_800C0F38 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C0F34: lw          $t7, -0x651C($at)
    ctx->r15 = ADD32(ctx->r1, -0X651C);
    // 0x800C0F38: jr          $t7
    // 0x800C0F3C: nop

    switch (jr_addend_800C0F38 >> 2) {
        case 0: goto L_800C0F40; break;
        case 1: goto L_800C149C; break;
        case 2: goto L_800C1270; break;
        case 3: goto L_800C149C; break;
        case 4: goto L_800C149C; break;
        case 5: goto L_800C102C; break;
        case 6: goto L_800C1078; break;
        case 7: goto L_800C128C; break;
        case 8: goto L_800C149C; break;
        case 9: goto L_800C100C; break;
        case 10: goto L_800C12AC; break;
        case 11: goto L_800C149C; break;
        case 12: goto L_800C143C; break;
        case 13: goto L_800C1458; break;
        case 14: goto L_800C148C; break;
        case 15: goto L_800C1310; break;
        case 16: goto L_800C1334; break;
        case 17: goto L_800C13A0; break;
        case 18: goto L_800C149C; break;
        case 19: goto L_800C149C; break;
        case 20: goto L_800C149C; break;
        case 21: goto L_800C1270; break;
        case 22: goto L_800C10DC; break;
        case 23: goto L_800C11E8; break;
        default: switch_error(__func__, 0x800C0F38, 0x80109AE4);
    }
    // 0x800C0F3C: nop

L_800C0F40:
    // 0x800C0F40: lw          $a0, 0x18($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X18));
    // 0x800C0F44: beql        $a0, $zero, L_800C14A0
    if (ctx->r4 == 0) {
        // 0x800C0F48: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C14A0;
    }
    goto skip_32;
    // 0x800C0F48: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_32:
    // 0x800C0F4C: jal         0x800C1B44
    // 0x800C0F50: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    alCSeqNextEvent(rdram, ctx);
        goto after_32;
    // 0x800C0F50: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_32:
    // 0x800C0F54: lh          $t8, 0x58($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X58));
    // 0x800C0F58: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C0F5C: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x800C0F60: beq         $at, $zero, L_800C149C
    if (ctx->r1 == 0) {
        // 0x800C0F64: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800C149C;
    }
    // 0x800C0F64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C0F68: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C0F6C: addu        $at, $at, $t9
    gpr jr_addend_800C0F74 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C0F70: lw          $t9, -0x64BC($at)
    ctx->r25 = ADD32(ctx->r1, -0X64BC);
    // 0x800C0F74: jr          $t9
    // 0x800C0F78: nop

    switch (jr_addend_800C0F74 >> 2) {
        case 0: goto L_800C0F7C; break;
        case 1: goto L_800C149C; break;
        case 2: goto L_800C0FA4; break;
        case 3: goto L_800C0FD0; break;
        case 4: goto L_800C149C; break;
        case 5: goto L_800C149C; break;
        case 6: goto L_800C149C; break;
        case 7: goto L_800C149C; break;
        case 8: goto L_800C149C; break;
        case 9: goto L_800C149C; break;
        case 10: goto L_800C149C; break;
        case 11: goto L_800C149C; break;
        case 12: goto L_800C149C; break;
        case 13: goto L_800C149C; break;
        case 14: goto L_800C149C; break;
        case 15: goto L_800C149C; break;
        case 16: goto L_800C149C; break;
        case 17: goto L_800C0FFC; break;
        case 18: goto L_800C0FFC; break;
        case 19: goto L_800C0FFC; break;
        default: switch_error(__func__, 0x800C0F74, 0x80109B44);
    }
    // 0x800C0F78: nop

L_800C0F7C:
    // 0x800C0F7C: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x800C0F80: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C0F84: jal         0x800C06AC
    // 0x800C0F88: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_5_800C06AC(rdram, ctx);
        goto after_33;
    // 0x800C0F88: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_33:
    // 0x800C0F8C: lw          $s2, 0xA0($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C0F90: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800C0F94: jal         0x800C0430
    // 0x800C0F98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_34;
    // 0x800C0F98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
    // 0x800C0F9C: b           L_800C14A0
    // 0x800C0FA0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C0FA0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C0FA4:
    // 0x800C0FA4: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x800C0FA8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800C0FAC: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C0FB0: jal         0x800C04DC
    // 0x800C0FB4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_5_800C04DC(rdram, ctx);
        goto after_35;
    // 0x800C0FB4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_35:
    // 0x800C0FB8: lw          $s2, 0xA0($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C0FBC: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800C0FC0: jal         0x800C0430
    // 0x800C0FC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_36;
    // 0x800C0FC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_36:
    // 0x800C0FC8: b           L_800C14A0
    // 0x800C0FCC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C0FCC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C0FD0:
    // 0x800C0FD0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C0FD4: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x800C0FD8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C0FDC: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800C0FE0: sh          $t7, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r15;
    // 0x800C0FE4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800C0FE8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C0FEC: jal         0x800C9C6C
    // 0x800C0FF0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    alEvtqPostEvent(rdram, ctx);
        goto after_37;
    // 0x800C0FF0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_37:
    // 0x800C0FF4: b           L_800C14A0
    // 0x800C0FF8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C0FF8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C0FFC:
    // 0x800C0FFC: jal         0x800C0430
    // 0x800C1000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_38;
    // 0x800C1000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_38:
    // 0x800C1004: b           L_800C14A0
    // 0x800C1008: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1008: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C100C:
    // 0x800C100C: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800C1010: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C1014: lw          $a2, 0x5C($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X5C));
    // 0x800C1018: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C101C: jal         0x800C9C6C
    // 0x800C1020: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    alEvtqPostEvent(rdram, ctx);
        goto after_39;
    // 0x800C1020: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_39:
    // 0x800C1024: b           L_800C14A0
    // 0x800C1028: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1028: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C102C:
    // 0x800C102C: lw          $s0, 0x3C($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C1030: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C1034: jal         0x800CA400
    // 0x800C1038: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynStopVoice(rdram, ctx);
        goto after_40;
    // 0x800C1038: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_40:
    // 0x800C103C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C1040: jal         0x800CA480
    // 0x800C1044: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_41;
    // 0x800C1044: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_41:
    // 0x800C1048: lw          $s1, 0x10($s0)
    ctx->r17 = S32(MEM_W(ctx->r16, 0X10));
    // 0x800C104C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1050: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x800C1054: beql        $t9, $zero, L_800C1068
    if (ctx->r25 == 0) {
        // 0x800C1058: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C1068;
    }
    goto skip_33;
    // 0x800C1058: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_33:
    // 0x800C105C: jal         0x800CBB70
    // 0x800C1060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_42;
    // 0x800C1060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_42:
    // 0x800C1064: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C1068:
    // 0x800C1068: jal         0x800CA940
    // 0x800C106C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_43;
    // 0x800C106C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_43:
    // 0x800C1070: b           L_800C14A0
    // 0x800C1074: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1074: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C1078:
    // 0x800C1078: lw          $s0, 0x3C($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C107C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C1080: lw          $s1, 0x10($s0)
    ctx->r17 = S32(MEM_W(ctx->r16, 0X10));
    // 0x800C1084: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x800C1088: bnel        $t6, $zero, L_800C1098
    if (ctx->r14 != 0) {
        // 0x800C108C: lw          $s3, 0x40($s2)
        ctx->r19 = S32(MEM_W(ctx->r18, 0X40));
            goto L_800C1098;
    }
    goto skip_34;
    // 0x800C108C: lw          $s3, 0x40($s2)
    ctx->r19 = S32(MEM_W(ctx->r18, 0X40));
    skip_34:
    // 0x800C1090: sb          $t7, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r15;
    // 0x800C1094: lw          $s3, 0x40($s2)
    ctx->r19 = S32(MEM_W(ctx->r18, 0X40));
L_800C1098:
    // 0x800C1098: lw          $t8, 0x1C($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X1C));
    // 0x800C109C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C10A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C10A4: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x800C10A8: sw          $t9, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r25;
    // 0x800C10AC: lbu         $t6, 0x44($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X44);
    // 0x800C10B0: jal         0x800CA6E4
    // 0x800C10B4: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    __vsVol(rdram, ctx);
        goto after_44;
    // 0x800C10B4: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    after_44:
    // 0x800C10B8: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800C10BC: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C10C0: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C10C4: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C10C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C10CC: jal         0x800CA230
    // 0x800C10D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    alSynSetVol(rdram, ctx);
        goto after_45;
    // 0x800C10D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_45:
    // 0x800C10D4: b           L_800C14A0
    // 0x800C10D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C10D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C10DC:
    // 0x800C10DC: lw          $t9, 0x74($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X74));
    // 0x800C10E0: lw          $s4, 0x40($s2)
    ctx->r20 = S32(MEM_W(ctx->r18, 0X40));
    // 0x800C10E4: lw          $s1, 0x3C($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C10E8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800C10EC: jalr        $t9
    // 0x800C10F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_46;
    // 0x800C10F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_46:
    // 0x800C10F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C10F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C10FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C1100: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X78));
    // 0x800C1104: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C1108: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C110C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C1110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C1114: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800C1118: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C111C: nop

    // 0x800C1120: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800C1124: beql        $t6, $zero, L_800C1174
    if (ctx->r14 == 0) {
        // 0x800C1128: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_800C1174;
    }
    goto skip_35;
    // 0x800C1128: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_35:
    // 0x800C112C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C1130: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C1134: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C1138: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800C113C: nop

    // 0x800C1140: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C1144: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800C1148: nop

    // 0x800C114C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800C1150: bne         $t6, $zero, L_800C1168
    if (ctx->r14 != 0) {
        // 0x800C1154: nop
    
            goto L_800C1168;
    }
    // 0x800C1154: nop

    // 0x800C1158: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800C115C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C1160: b           L_800C1180
    // 0x800C1164: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800C1180;
    // 0x800C1164: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800C1168:
    // 0x800C1168: b           L_800C1180
    // 0x800C116C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800C1180;
    // 0x800C116C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C1170: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_800C1174:
    // 0x800C1174: nop

    // 0x800C1178: bltz        $t6, L_800C1168
    if (SIGNED(ctx->r14) < 0) {
        // 0x800C117C: nop
    
            goto L_800C1168;
    }
    // 0x800C117C: nop

L_800C1180:
    // 0x800C1180: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C1184: jal         0x800CA6E4
    // 0x800C1188: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    __vsVol(rdram, ctx);
        goto after_47;
    // 0x800C1188: sb          $t6, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r14;
    after_47:
    // 0x800C118C: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800C1190: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800C1194: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C1198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C119C: jal         0x800CA6C0
    // 0x800C11A0: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    __vsDelta(rdram, ctx);
        goto after_48;
    // 0x800C11A0: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    after_48:
    // 0x800C11A4: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800C11A8: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C11AC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C11B0: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C11B4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C11B8: jal         0x800CA230
    // 0x800C11BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_49;
    // 0x800C11BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_49:
    // 0x800C11C0: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800C11C4: sh          $t8, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r24;
    // 0x800C11C8: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x800C11CC: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x800C11D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C11D4: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C11D8: jal         0x800C9C6C
    // 0x800C11DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_50;
    // 0x800C11DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_50:
    // 0x800C11E0: b           L_800C14A0
    // 0x800C11E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C11E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C11E8:
    // 0x800C11E8: lw          $t9, 0x74($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X74));
    // 0x800C11EC: lw          $s4, 0x40($s2)
    ctx->r20 = S32(MEM_W(ctx->r18, 0X40));
    // 0x800C11F0: lw          $s1, 0x3C($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C11F4: lbu         $s0, 0x44($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X44);
    // 0x800C11F8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800C11FC: jalr        $t9
    // 0x800C1200: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_51;
    // 0x800C1200: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_51:
    // 0x800C1204: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X78));
    // 0x800C1208: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = S32(MEM_W(ctx->r17, 0X28));
    // 0x800C120C: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x800C1210: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x800C1214: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = S32(MEM_W(ctx->r17, 0X2C));
    // 0x800C1218: lw          $t6, 0x60($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C121C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800C1220: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C1224: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C1228: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = S32(MEM_W(ctx->r24, 0XC));
    // 0x800C122C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C1230: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C1234: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800C1238: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C123C: jal         0x800CA2D0
    // 0x800C1240: nop

    alSynSetPitch(rdram, ctx);
        goto after_52;
    // 0x800C1240: nop

    after_52:
    // 0x800C1244: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x800C1248: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x800C124C: sw          $s1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r17;
    // 0x800C1250: sw          $s4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r20;
    // 0x800C1254: sb          $s0, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r16;
    // 0x800C1258: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C125C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x800C1260: jal         0x800C9C6C
    // 0x800C1264: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_53;
    // 0x800C1264: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_53:
    // 0x800C1268: b           L_800C14A0
    // 0x800C126C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C126C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C1270:
    // 0x800C1270: lw          $t0, 0x50($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800C1274: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C1278: jal         0x800C06AC
    // 0x800C127C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_5_800C06AC(rdram, ctx);
        goto after_54;
    // 0x800C127C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_54:
    // 0x800C1280: lw          $s2, 0xA0($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C1284: b           L_800C149C
    // 0x800C1288: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800C149C;
    // 0x800C1288: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
L_800C128C:
    // 0x800C128C: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x800C1290: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800C1294: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800C1298: jal         0x800C04DC
    // 0x800C129C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    static_5_800C04DC(rdram, ctx);
        goto after_55;
    // 0x800C129C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    after_55:
    // 0x800C12A0: lw          $s2, 0xA0($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C12A4: b           L_800C149C
    // 0x800C12A8: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800C149C;
    // 0x800C12A8: lw          $s5, 0x4C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X4C));
L_800C12AC:
    // 0x800C12AC: lw          $s1, 0x64($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C12B0: lh          $t6, 0x3C($s2)
    ctx->r14 = S32(MEM_H(ctx->r18, 0X3C));
    // 0x800C12B4: beq         $s1, $zero, L_800C149C
    if (ctx->r17 == 0) {
        // 0x800C12B8: sh          $t6, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r14;
            goto L_800C149C;
    }
    // 0x800C12B8: sh          $t6, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r14;
    // 0x800C12BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800C12C0:
    // 0x800C12C0: jal         0x800CA6E4
    // 0x800C12C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __vsVol(rdram, ctx);
        goto after_56;
    // 0x800C12C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_56:
    // 0x800C12C8: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800C12CC: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800C12D0: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C12D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C12D8: jal         0x800CA6C0
    // 0x800C12DC: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    __vsDelta(rdram, ctx);
        goto after_57;
    // 0x800C12DC: lw          $a1, 0x1C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X1C));
    after_57:
    // 0x800C12E0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x800C12E4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800C12E8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C12EC: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C12F0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800C12F4: jal         0x800CA230
    // 0x800C12F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    alSynSetVol(rdram, ctx);
        goto after_58;
    // 0x800C12F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_58:
    // 0x800C12FC: lw          $s1, 0x0($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C1300: bnel        $s1, $zero, L_800C12C0
    if (ctx->r17 != 0) {
        // 0x800C1304: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C12C0;
    }
    goto skip_36;
    // 0x800C1304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_36:
    // 0x800C1308: b           L_800C14A0
    // 0x800C130C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C130C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C1310:
    // 0x800C1310: lw          $t9, 0x2C($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X2C));
    // 0x800C1314: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C1318: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C131C: beq         $t9, $at, L_800C149C
    if (ctx->r25 == ctx->r1) {
        // 0x800C1320: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C149C;
    }
    // 0x800C1320: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1324: jal         0x800C0430
    // 0x800C1328: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    __CSPPostNextSeqEvent(rdram, ctx);
        goto after_59;
    // 0x800C1328: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    after_59:
    // 0x800C132C: b           L_800C14A0
    // 0x800C1330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C1334:
    // 0x800C1334: lw          $t7, 0x2C($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X2C));
    // 0x800C1338: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C133C: bnel        $t7, $at, L_800C14A0
    if (ctx->r15 != ctx->r1) {
        // 0x800C1340: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C14A0;
    }
    goto skip_37;
    // 0x800C1340: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_37:
    // 0x800C1344: lw          $s1, 0x64($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C1348: beq         $s1, $zero, L_800C1398
    if (ctx->r17 == 0) {
        // 0x800C134C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C1398;
    }
    // 0x800C134C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800C1350:
    // 0x800C1350: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C1354: jal         0x800CA400
    // 0x800C1358: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    alSynStopVoice(rdram, ctx);
        goto after_60;
    // 0x800C1358: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    after_60:
    // 0x800C135C: lw          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800C1360: jal         0x800CA480
    // 0x800C1364: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynFreeVoice(rdram, ctx);
        goto after_61;
    // 0x800C1364: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_61:
    // 0x800C1368: lbu         $t8, 0x37($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X37);
    // 0x800C136C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1370: beql        $t8, $zero, L_800C1384
    if (ctx->r24 == 0) {
        // 0x800C1374: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C1384;
    }
    goto skip_38;
    // 0x800C1374: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_38:
    // 0x800C1378: jal         0x800CBB70
    // 0x800C137C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __seqpStopOsc(rdram, ctx);
        goto after_62;
    // 0x800C137C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_62:
    // 0x800C1380: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C1384:
    // 0x800C1384: jal         0x800CA940
    // 0x800C1388: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __unmapVoice(rdram, ctx);
        goto after_63;
    // 0x800C1388: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_63:
    // 0x800C138C: lw          $s1, 0x64($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C1390: bnel        $s1, $zero, L_800C1350
    if (ctx->r17 != 0) {
        // 0x800C1394: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C1350;
    }
    goto skip_39;
    // 0x800C1394: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_39:
L_800C1398:
    // 0x800C1398: b           L_800C149C
    // 0x800C139C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
        goto L_800C149C;
    // 0x800C139C: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
L_800C13A0:
    // 0x800C13A0: lw          $t9, 0x2C($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X2C));
    // 0x800C13A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C13A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C13AC: bnel        $t9, $at, L_800C14A0
    if (ctx->r25 != ctx->r1) {
        // 0x800C13B0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C14A0;
    }
    goto skip_40;
    // 0x800C13B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_40:
    // 0x800C13B4: jal         0x800C9B50
    // 0x800C13B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_64;
    // 0x800C13B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_64:
    // 0x800C13BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C13C0: jal         0x800C9B50
    // 0x800C13C4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    alEvtqFlushType(rdram, ctx);
        goto after_65;
    // 0x800C13C4: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_65:
    // 0x800C13C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C13CC: jal         0x800C9B50
    // 0x800C13D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_66;
    // 0x800C13D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_66:
    // 0x800C13D4: lw          $s1, 0x64($s2)
    ctx->r17 = S32(MEM_W(ctx->r18, 0X64));
    // 0x800C13D8: beq         $s1, $zero, L_800C1410
    if (ctx->r17 == 0) {
        // 0x800C13DC: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C1410;
    }
    // 0x800C13DC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_800C13E0:
    // 0x800C13E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C13E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C13E8: jal         0x800CA898
    // 0x800C13EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __voiceNeedsNoteKill(rdram, ctx);
        goto after_67;
    // 0x800C13EC: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_67:
    // 0x800C13F0: beq         $v0, $zero, L_800C1404
    if (ctx->r2 == 0) {
        // 0x800C13F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C1404;
    }
    // 0x800C13F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C13F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C13FC: jal         0x800CA76C
    // 0x800C1400: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __seqpReleaseVoice(rdram, ctx);
        goto after_68;
    // 0x800C1400: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_68:
L_800C1404:
    // 0x800C1404: lw          $s1, 0x0($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C1408: bnel        $s1, $zero, L_800C13E0
    if (ctx->r17 != 0) {
        // 0x800C140C: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_800C13E0;
    }
    goto skip_41;
    // 0x800C140C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_41:
L_800C1410:
    // 0x800C1410: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C1414: sw          $t6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r14;
    // 0x800C1418: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C141C: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x800C1420: sh          $t7, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r15;
    // 0x800C1424: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x800C1428: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800C142C: jal         0x800C9C6C
    // 0x800C1430: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    alEvtqPostEvent(rdram, ctx);
        goto after_69;
    // 0x800C1430: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_69:
    // 0x800C1434: b           L_800C14A0
    // 0x800C1438: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1438: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C143C:
    // 0x800C143C: lbu         $s0, 0x3C($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X3C);
    // 0x800C1440: lw          $t9, 0x60($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X60));
    // 0x800C1444: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x800C1448: sll         $t6, $s0, 4
    ctx->r14 = S32(ctx->r16 << 4);
    // 0x800C144C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800C1450: b           L_800C149C
    // 0x800C1454: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_800C149C;
    // 0x800C1454: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_800C1458:
    // 0x800C1458: lw          $t9, 0x3C($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C145C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C1460: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1464: sw          $t9, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r25;
    // 0x800C1468: jal         0x800C04A0
    // 0x800C146C: lwc1        $f12, -0x646C($at)
    ctx->f12.u32l = S32(MEM_W(ctx->r1, -0X646C));
    static_5_800C04A0(rdram, ctx);
        goto after_70;
    // 0x800C146C: lwc1        $f12, -0x646C($at)
    ctx->f12.u32l = S32(MEM_W(ctx->r1, -0X646C));
    after_70:
    // 0x800C1470: lw          $a1, 0x20($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X20));
    // 0x800C1474: beql        $a1, $zero, L_800C14A0
    if (ctx->r5 == 0) {
        // 0x800C1478: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800C14A0;
    }
    goto skip_42;
    // 0x800C1478: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_42:
    // 0x800C147C: jal         0x800CA604
    // 0x800C1480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    __initFromBank(rdram, ctx);
        goto after_71;
    // 0x800C1480: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_71:
    // 0x800C1484: b           L_800C14A0
    // 0x800C1488: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800C14A0;
    // 0x800C1488: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C148C:
    // 0x800C148C: lw          $a1, 0x3C($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X3C));
    // 0x800C1490: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C1494: jal         0x800CA604
    // 0x800C1498: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_72;
    // 0x800C1498: sw          $a1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r5;
    after_72:
L_800C149C:
    // 0x800C149C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800C14A0:
    // 0x800C14A0: jal         0x800C9D90
    // 0x800C14A4: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    alEvtqNextEvent(rdram, ctx);
        goto after_73;
    // 0x800C14A4: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    after_73:
    // 0x800C14A8: beq         $v0, $zero, L_800C0F1C
    if (ctx->r2 == 0) {
        // 0x800C14AC: sw          $v0, 0x28($s2)
        MEM_W(0X28, ctx->r18) = ctx->r2;
            goto L_800C0F1C;
    }
    // 0x800C14AC: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // 0x800C14B0: lw          $t6, 0x1C($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X1C));
    // 0x800C14B4: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C14B8: sw          $t8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r24;
    // 0x800C14BC: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800C14C0: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800C14C4: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800C14C8: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C14CC: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800C14D0: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800C14D4: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800C14D8: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800C14DC: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C14E0: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C14E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C14E8: jr          $ra
    // 0x800C14EC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800C14EC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void static_5_800C1A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1A20: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800C1A24: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800C1A28: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C1A2C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C1A30: beql        $t6, $zero, L_800C1A68
    if (ctx->r14 == 0) {
        // 0x800C1A34: lw          $a3, 0x18($a2)
        ctx->r7 = S32(MEM_W(ctx->r6, 0X18));
            goto L_800C1A68;
    }
    goto skip_0;
    // 0x800C1A34: lw          $a3, 0x18($a2)
    ctx->r7 = S32(MEM_W(ctx->r6, 0X18));
    skip_0:
    // 0x800C1A38: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C1A3C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C1A40: lw          $a3, 0x58($a2)
    ctx->r7 = S32(MEM_W(ctx->r6, 0X58));
    // 0x800C1A44: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1A48: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C1A4C: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800C1A50: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x800C1A54: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800C1A58: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x800C1A5C: jr          $ra
    // 0x800C1A60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C1A60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C1A64: lw          $a3, 0x18($a2)
    ctx->r7 = S32(MEM_W(ctx->r6, 0X18));
L_800C1A68:
    // 0x800C1A68: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x800C1A6C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1A70: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C1A74: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x800C1A78: bne         $t0, $v1, L_800C1ADC
    if (ctx->r8 != ctx->r3) {
        // 0x800C1A7C: nop
    
            goto L_800C1ADC;
    }
    // 0x800C1A7C: nop

    // 0x800C1A80: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x800C1A84: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C1A88: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x800C1A8C: beq         $t0, $a0, L_800C1ADC
    if (ctx->r8 == ctx->r4) {
        // 0x800C1A90: addiu       $t6, $t9, 0x1
        ctx->r14 = ADD32(ctx->r25, 0X1);
            goto L_800C1ADC;
    }
    // 0x800C1A90: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C1A94: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800C1A98: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x800C1A9C: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800C1AA0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C1AA4: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x800C1AA8: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x800C1AAC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800C1AB0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C1AB4: addiu       $t9, $t7, -0x4
    ctx->r25 = ADD32(ctx->r15, -0X4);
    // 0x800C1AB8: sw          $t9, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r25;
    // 0x800C1ABC: sb          $a1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r5;
    // 0x800C1AC0: lw          $a3, 0x58($a2)
    ctx->r7 = S32(MEM_W(ctx->r6, 0X58));
    // 0x800C1AC4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1AC8: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C1ACC: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800C1AD0: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800C1AD4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800C1AD8: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
L_800C1ADC:
    // 0x800C1ADC: jr          $ra
    // 0x800C1AE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C1AE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void static_5_800C1AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1AEC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C1AF0: jal         0x800C1A20
    // 0x800C1AF4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_0;
    // 0x800C1AF4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800C1AF8: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800C1AFC: beq         $t6, $zero, L_800C1B28
    if (ctx->r14 == 0) {
        // 0x800C1B00: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800C1B28;
    }
    // 0x800C1B00: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800C1B04: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_800C1B08:
    // 0x800C1B08: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C1B0C: jal         0x800C1A20
    // 0x800C1B10: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_5_800C1A20(rdram, ctx);
        goto after_1;
    // 0x800C1B10: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800C1B14: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x800C1B18: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800C1B1C: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800C1B20: bne         $t9, $zero, L_800C1B08
    if (ctx->r25 != 0) {
        // 0x800C1B24: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_800C1B08;
    }
    // 0x800C1B24: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_800C1B28:
    // 0x800C1B28: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C1B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1B30: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800C1B34: jr          $ra
    // 0x800C1B38: nop

    return;
    // 0x800C1B38: nop

    // 0x800C1B3C: jr          $ra
    // 0x800C1B40: nop

    return;
    // 0x800C1B40: nop

;}
RECOMP_FUNC void static_5_800C8D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8D34: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800C8D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8D3C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C8D40: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x800C8D44: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C8D48: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800C8D4C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800C8D50: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800C8D54: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800C8D58: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x800C8D5C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800C8D60: bne         $at, $zero, L_800C8D8C
    if (ctx->r1 != 0) {
        // 0x800C8D64: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800C8D8C;
    }
    // 0x800C8D64: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800C8D68: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x800C8D6C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800C8D70: beq         $at, $zero, L_800C9378
    if (ctx->r1 == 0) {
        // 0x800C8D74: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C9378;
    }
    // 0x800C8D74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C8D78: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C8D7C: addu        $at, $at, $t7
    gpr jr_addend_800C8D84 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C8D80: lw          $t7, -0x62DC($at)
    ctx->r15 = ADD32(ctx->r1, -0X62DC);
    // 0x800C8D84: jr          $t7
    // 0x800C8D88: nop

    switch (jr_addend_800C8D84 >> 2) {
        case 0: goto L_800C9098; break;
        case 1: goto L_800C9378; break;
        case 2: goto L_800C9098; break;
        case 3: goto L_800C9378; break;
        case 4: goto L_800C9378; break;
        case 5: goto L_800C9378; break;
        case 6: goto L_800C9378; break;
        case 7: goto L_800C9378; break;
        case 8: goto L_800C9378; break;
        case 9: goto L_800C9378; break;
        case 10: goto L_800C9378; break;
        case 11: goto L_800C9378; break;
        case 12: goto L_800C9378; break;
        case 13: goto L_800C9378; break;
        case 14: goto L_800C9378; break;
        case 15: goto L_800C9378; break;
        case 16: goto L_800C9378; break;
        case 17: goto L_800C9378; break;
        case 18: goto L_800C9378; break;
        case 19: goto L_800C8F48; break;
        case 20: goto L_800C9378; break;
        case 21: goto L_800C9378; break;
        case 22: goto L_800C9378; break;
        case 23: goto L_800C9378; break;
        case 24: goto L_800C9378; break;
        case 25: goto L_800C9378; break;
        case 26: goto L_800C9378; break;
        case 27: goto L_800C9378; break;
        case 28: goto L_800C9378; break;
        case 29: goto L_800C9378; break;
        case 30: goto L_800C8DA0; break;
        case 31: goto L_800C8DD8; break;
        case 32: goto L_800C9098; break;
        case 33: goto L_800C9098; break;
        case 34: goto L_800C9098; break;
        case 35: goto L_800C9378; break;
        case 36: goto L_800C8DD8; break;
        case 37: goto L_800C9378; break;
        case 38: goto L_800C9378; break;
        case 39: goto L_800C9378; break;
        case 40: goto L_800C9378; break;
        case 41: goto L_800C91FC; break;
        case 42: goto L_800C8F48; break;
        case 43: goto L_800C92CC; break;
        case 44: goto L_800C9378; break;
        case 45: goto L_800C9378; break;
        case 46: goto L_800C9314; break;
        case 47: goto L_800C9378; break;
        case 48: goto L_800C8F48; break;
        case 49: goto L_800C9378; break;
        case 50: goto L_800C9378; break;
        case 51: goto L_800C8F48; break;
        default: switch_error(__func__, 0x800C8D84, 0x80109D24);
    }
    // 0x800C8D88: nop

L_800C8D8C:
    // 0x800C8D8C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800C8D90: beql        $v1, $at, L_800C935C
    if (ctx->r3 == ctx->r1) {
        // 0x800C8D94: lw          $t8, 0xC($s0)
        ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
            goto L_800C935C;
    }
    goto skip_0;
    // 0x800C8D94: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    skip_0:
    // 0x800C8D98: b           L_800C937C
    // 0x800C8D9C: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
        goto L_800C937C;
    // 0x800C8D9C: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
L_800C8DA0:
    // 0x800C8DA0: lw          $t8, 0x0($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C8DA4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C8DA8: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800C8DAC: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800C8DB0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C8DB4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800C8DB8: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C8DBC: lw          $t9, -0x4($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, -0X4));
    // 0x800C8DC0: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800C8DC4: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800C8DC8: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C8DCC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800C8DD0: b           L_800C9390
    // 0x800C8DD4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800C9390;
    // 0x800C8DD4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800C8DD8:
    // 0x800C8DD8: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800C8DDC: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800C8DE0: bnel        $v0, $at, L_800C8E18
    if (ctx->r2 != ctx->r1) {
        // 0x800C8DE4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800C8E18;
    }
    goto skip_1;
    // 0x800C8DE4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x800C8DE8: lw          $t9, 0x0($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C8DEC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C8DF0: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x800C8DF4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800C8DF8: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800C8DFC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C8E00: lw          $t7, -0x4($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, -0X4));
    // 0x800C8E04: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800C8E08: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C8E0C: b           L_800C8E74
    // 0x800C8E10: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800C8E74;
    // 0x800C8E10: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800C8E14: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800C8E18:
    // 0x800C8E18: bnel        $v0, $at, L_800C8E50
    if (ctx->r2 != ctx->r1) {
        // 0x800C8E1C: lw          $t7, 0x0($a2)
        ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
            goto L_800C8E50;
    }
    goto skip_2;
    // 0x800C8E1C: lw          $t7, 0x0($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
    skip_2:
    // 0x800C8E20: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C8E24: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800C8E28: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800C8E2C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800C8E30: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800C8E34: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800C8E38: lw          $t8, -0x8($t9)
    ctx->r24 = S32(MEM_W(ctx->r25, -0X8));
    // 0x800C8E3C: lw          $t9, -0x4($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X4));
    // 0x800C8E40: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C8E44: b           L_800C8E74
    // 0x800C8E48: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800C8E74;
    // 0x800C8E48: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800C8E4C: lw          $t7, 0x0($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
L_800C8E50:
    // 0x800C8E50: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C8E54: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x800C8E58: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800C8E5C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C8E60: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800C8E64: lw          $t6, -0x4($t9)
    ctx->r14 = S32(MEM_W(ctx->r25, -0X4));
    // 0x800C8E68: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800C8E6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C8E70: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800C8E74:
    // 0x800C8E74: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x800C8E78: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800C8E7C: bnel        $t7, $at, L_800C8EA0
    if (ctx->r15 != ctx->r1) {
        // 0x800C8E80: lw          $t6, 0x0($s0)
        ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
            goto L_800C8EA0;
    }
    goto skip_3;
    // 0x800C8E80: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    skip_3:
    // 0x800C8E84: lw          $t7, 0x4($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800C8E88: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800C8E8C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800C8E90: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800C8E94: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C8E98: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800C8E9C: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
L_800C8EA0:
    // 0x800C8EA0: bgtzl       $t6, L_800C8EDC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800C8EA4: lw          $v0, 0x30($s0)
        ctx->r2 = S32(MEM_W(ctx->r16, 0X30));
            goto L_800C8EDC;
    }
    goto skip_4;
    // 0x800C8EA4: lw          $v0, 0x30($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X30));
    skip_4:
    // 0x800C8EA8: bltzl       $t6, L_800C8EBC
    if (SIGNED(ctx->r14) < 0) {
        // 0x800C8EAC: lw          $t9, 0xC($s0)
        ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
            goto L_800C8EBC;
    }
    goto skip_5;
    // 0x800C8EAC: lw          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
    skip_5:
    // 0x800C8EB0: b           L_800C8EDC
    // 0x800C8EB4: lw          $v0, 0x30($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X30));
        goto L_800C8EDC;
    // 0x800C8EB4: lw          $v0, 0x30($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X30));
    // 0x800C8EB8: lw          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
L_800C8EBC:
    // 0x800C8EBC: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800C8EC0: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800C8EC4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800C8EC8: lw          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C8ECC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800C8ED0: b           L_800C8F2C
    // 0x800C8ED4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_800C8F2C;
    // 0x800C8ED4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800C8ED8: lw          $v0, 0x30($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X30));
L_800C8EDC:
    // 0x800C8EDC: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x800C8EE0: beq         $t8, $zero, L_800C8F08
    if (ctx->r24 == 0) {
        // 0x800C8EE4: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800C8F08;
    }
    // 0x800C8EE4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800C8EE8: lw          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C8EEC: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x800C8EF0: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x800C8EF4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800C8EF8: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C8EFC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800C8F00: b           L_800C8F2C
    // 0x800C8F04: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_800C8F2C;
    // 0x800C8F04: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_800C8F08:
    // 0x800C8F08: beql        $t6, $zero, L_800C8F30
    if (ctx->r14 == 0) {
        // 0x800C8F0C: lw          $t9, 0xC($s0)
        ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
            goto L_800C8F30;
    }
    goto skip_6;
    // 0x800C8F0C: lw          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
    skip_6:
    // 0x800C8F10: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C8F14: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800C8F18: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800C8F1C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800C8F20: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C8F24: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800C8F28: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800C8F2C:
    // 0x800C8F2C: lw          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
L_800C8F30:
    // 0x800C8F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8F34: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x800C8F38: jal         0x800CF1B0
    // 0x800C8F3C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x800C8F3C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x800C8F40: b           L_800C9394
    // 0x800C8F44: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800C9394;
    // 0x800C8F44: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C8F48:
    // 0x800C8F48: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800C8F4C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800C8F50: bnel        $v0, $at, L_800C8F88
    if (ctx->r2 != ctx->r1) {
        // 0x800C8F54: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800C8F88;
    }
    goto skip_7;
    // 0x800C8F54: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x800C8F58: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C8F5C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C8F60: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x800C8F64: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800C8F68: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x800C8F6C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800C8F70: lw          $t8, -0x4($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, -0X4));
    // 0x800C8F74: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800C8F78: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800C8F7C: b           L_800C8FE4
    // 0x800C8F80: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800C8FE4;
    // 0x800C8F80: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800C8F84: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800C8F88:
    // 0x800C8F88: bnel        $v0, $at, L_800C8FC0
    if (ctx->r2 != ctx->r1) {
        // 0x800C8F8C: lw          $t6, 0x0($a2)
        ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
            goto L_800C8FC0;
    }
    goto skip_8;
    // 0x800C8F8C: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
    skip_8:
    // 0x800C8F90: lw          $t9, 0x0($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C8F94: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800C8F98: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800C8F9C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800C8FA0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C8FA4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800C8FA8: lw          $t9, -0x4($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, -0X4));
    // 0x800C8FAC: lw          $t8, -0x8($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, -0X8));
    // 0x800C8FB0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800C8FB4: b           L_800C8FE4
    // 0x800C8FB8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800C8FE4;
    // 0x800C8FB8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C8FBC: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
L_800C8FC0:
    // 0x800C8FC0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C8FC4: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x800C8FC8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800C8FCC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C8FD0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800C8FD4: lw          $t7, -0x4($t9)
    ctx->r15 = S32(MEM_W(ctx->r25, -0X4));
    // 0x800C8FD8: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800C8FDC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C8FE0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800C8FE4:
    // 0x800C8FE4: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800C8FE8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800C8FEC: bne         $v0, $at, L_800C900C
    if (ctx->r2 != ctx->r1) {
        // 0x800C8FF0: nop
    
            goto L_800C900C;
    }
    // 0x800C8FF0: nop

    // 0x800C8FF4: lw          $t7, 0x4($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800C8FF8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800C8FFC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800C9000: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800C9004: b           L_800C9024
    // 0x800C9008: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800C9024;
    // 0x800C9008: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800C900C:
    // 0x800C900C: bnel        $v0, $zero, L_800C9028
    if (ctx->r2 != 0) {
        // 0x800C9010: lw          $t7, 0x30($s0)
        ctx->r15 = S32(MEM_W(ctx->r16, 0X30));
            goto L_800C9028;
    }
    goto skip_9;
    // 0x800C9010: lw          $t7, 0x30($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X30));
    skip_9:
    // 0x800C9014: lw          $t9, 0x4($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800C9018: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800C901C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C9020: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800C9024:
    // 0x800C9024: lw          $t7, 0x30($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X30));
L_800C9028:
    // 0x800C9028: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x800C902C: beql        $t6, $zero, L_800C9080
    if (ctx->r14 == 0) {
        // 0x800C9030: lw          $t8, 0xC($s0)
        ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
            goto L_800C9080;
    }
    goto skip_10;
    // 0x800C9030: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    skip_10:
    // 0x800C9034: lw          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C9038: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800C903C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800C9040: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x800C9044: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x800C9048: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C904C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800C9050: beq         $v1, $at, L_800C9064
    if (ctx->r3 == ctx->r1) {
        // 0x800C9054: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_800C9064;
    }
    // 0x800C9054: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800C9058: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x800C905C: bnel        $v1, $at, L_800C9080
    if (ctx->r3 != ctx->r1) {
        // 0x800C9060: lw          $t8, 0xC($s0)
        ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
            goto L_800C9080;
    }
    goto skip_11;
    // 0x800C9060: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    skip_11:
L_800C9064:
    // 0x800C9064: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C9068: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800C906C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x800C9070: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C9074: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800C9078: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800C907C: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
L_800C9080:
    // 0x800C9080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9084: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x800C9088: jal         0x800CF1B0
    // 0x800C908C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x800C908C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x800C9090: b           L_800C9394
    // 0x800C9094: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800C9394;
    // 0x800C9094: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C9098:
    // 0x800C9098: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x800C909C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800C90A0: bnel        $t6, $at, L_800C9108
    if (ctx->r14 != ctx->r1) {
        // 0x800C90A4: lw          $v0, 0x0($a2)
        ctx->r2 = S32(MEM_W(ctx->r6, 0X0));
            goto L_800C9108;
    }
    goto skip_12;
    // 0x800C90A4: lw          $v0, 0x0($a2)
    ctx->r2 = S32(MEM_W(ctx->r6, 0X0));
    skip_12:
    // 0x800C90A8: lw          $v0, 0x0($a2)
    ctx->r2 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C90AC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800C90B0: beq         $t9, $zero, L_800C90C8
    if (ctx->r25 == 0) {
        // 0x800C90B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C90C8;
    }
    // 0x800C90B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C90B8: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x800C90BC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800C90C0: b           L_800C90F8
    // 0x800C90C4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_800C90F8;
    // 0x800C90C4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_800C90C8:
    // 0x800C90C8: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800C90CC: beq         $t7, $zero, L_800C90E4
    if (ctx->r15 == 0) {
        // 0x800C90D0: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_800C90E4;
    }
    // 0x800C90D0: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x800C90D4: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x800C90D8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C90DC: b           L_800C90F4
    // 0x800C90E0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_800C90F4;
    // 0x800C90E0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_800C90E4:
    // 0x800C90E4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800C90E8: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800C90EC: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x800C90F0: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800C90F4:
    // 0x800C90F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800C90F8:
    // 0x800C90F8: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x800C90FC: b           L_800C915C
    // 0x800C9100: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_800C915C;
    // 0x800C9100: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x800C9104: lw          $v0, 0x0($a2)
    ctx->r2 = S32(MEM_W(ctx->r6, 0X0));
L_800C9108:
    // 0x800C9108: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800C910C: beq         $t6, $zero, L_800C9124
    if (ctx->r14 == 0) {
        // 0x800C9110: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C9124;
    }
    // 0x800C9110: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C9114: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x800C9118: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800C911C: b           L_800C9154
    // 0x800C9120: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_800C9154;
    // 0x800C9120: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_800C9124:
    // 0x800C9124: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x800C9128: beq         $t8, $zero, L_800C9140
    if (ctx->r24 == 0) {
        // 0x800C912C: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_800C9140;
    }
    // 0x800C912C: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x800C9130: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x800C9134: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800C9138: b           L_800C9150
    // 0x800C913C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_800C9150;
    // 0x800C913C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_800C9140:
    // 0x800C9140: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800C9144: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x800C9148: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x800C914C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800C9150:
    // 0x800C9150: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800C9154:
    // 0x800C9154: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x800C9158: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_800C915C:
    // 0x800C915C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x800C9160: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x800C9164: beql        $t6, $zero, L_800C9190
    if (ctx->r14 == 0) {
        // 0x800C9168: lw          $v0, 0x30($s0)
        ctx->r2 = S32(MEM_W(ctx->r16, 0X30));
            goto L_800C9190;
    }
    goto skip_13;
    // 0x800C9168: lw          $v0, 0x30($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X30));
    skip_13:
    // 0x800C916C: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C9170: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800C9174: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800C9178: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800C917C: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C9180: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800C9184: b           L_800C91E0
    // 0x800C9188: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800C91E0;
    // 0x800C9188: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x800C918C: lw          $v0, 0x30($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X30));
L_800C9190:
    // 0x800C9190: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x800C9194: beq         $t9, $zero, L_800C91BC
    if (ctx->r25 == 0) {
        // 0x800C9198: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800C91BC;
    }
    // 0x800C9198: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800C919C: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C91A0: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800C91A4: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800C91A8: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800C91AC: lw          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C91B0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C91B4: b           L_800C91E0
    // 0x800C91B8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800C91E0;
    // 0x800C91B8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800C91BC:
    // 0x800C91BC: beql        $t7, $zero, L_800C91E4
    if (ctx->r15 == 0) {
        // 0x800C91C0: lw          $t8, 0xC($s0)
        ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
            goto L_800C91E4;
    }
    goto skip_14;
    // 0x800C91C0: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
    skip_14:
    // 0x800C91C4: lw          $t9, 0xC($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C91C8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800C91CC: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800C91D0: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800C91D4: lw          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C91D8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800C91DC: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_800C91E0:
    // 0x800C91E0: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
L_800C91E4:
    // 0x800C91E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C91E8: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800C91EC: jal         0x800CF9C0
    // 0x800C91F0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x800C91F0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x800C91F4: b           L_800C9394
    // 0x800C91F8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800C9394;
    // 0x800C91F8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C91FC:
    // 0x800C91FC: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800C9200: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800C9204: bnel        $v0, $at, L_800C9238
    if (ctx->r2 != ctx->r1) {
        // 0x800C9208: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_800C9238;
    }
    goto skip_15;
    // 0x800C9208: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x800C920C: lw          $t7, 0x0($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C9210: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C9214: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800C9218: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800C921C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800C9220: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C9224: lw          $t9, -0x4($t6)
    ctx->r25 = S32(MEM_W(ctx->r14, -0X4));
    // 0x800C9228: lw          $t7, 0x2C($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X2C));
    // 0x800C922C: b           L_800C9390
    // 0x800C9230: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_800C9390;
    // 0x800C9230: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x800C9234: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_800C9238:
    // 0x800C9238: bnel        $v0, $at, L_800C926C
    if (ctx->r2 != ctx->r1) {
        // 0x800C923C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800C926C;
    }
    goto skip_16;
    // 0x800C923C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x800C9240: lw          $t8, 0x0($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C9244: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C9248: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x800C924C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800C9250: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x800C9254: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800C9258: lw          $t6, -0x4($t9)
    ctx->r14 = S32(MEM_W(ctx->r25, -0X4));
    // 0x800C925C: lw          $t8, 0x2C($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X2C));
    // 0x800C9260: b           L_800C9390
    // 0x800C9264: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_800C9390;
    // 0x800C9264: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800C9268: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800C926C:
    // 0x800C926C: bnel        $v0, $at, L_800C92A8
    if (ctx->r2 != ctx->r1) {
        // 0x800C9270: lw          $t7, 0x0($a2)
        ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
            goto L_800C92A8;
    }
    goto skip_17;
    // 0x800C9270: lw          $t7, 0x0($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
    skip_17:
    // 0x800C9274: lw          $t7, 0x0($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C9278: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C927C: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800C9280: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800C9284: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800C9288: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C928C: lw          $t6, -0x4($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X4));
    // 0x800C9290: lw          $t7, 0x2C($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X2C));
    // 0x800C9294: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800C9298: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800C929C: b           L_800C9390
    // 0x800C92A0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_800C9390;
    // 0x800C92A0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800C92A4: lw          $t7, 0x0($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
L_800C92A8:
    // 0x800C92A8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C92AC: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800C92B0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800C92B4: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800C92B8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C92BC: lw          $t8, -0x4($t6)
    ctx->r24 = S32(MEM_W(ctx->r14, -0X4));
    // 0x800C92C0: lw          $t7, 0x2C($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X2C));
    // 0x800C92C4: b           L_800C9390
    // 0x800C92C8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_800C9390;
    // 0x800C92C8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800C92CC:
    // 0x800C92CC: lw          $t9, 0x0($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C92D0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C92D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C92D8: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x800C92DC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800C92E0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800C92E4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800C92E8: lw          $t6, -0x4($t8)
    ctx->r14 = S32(MEM_W(ctx->r24, -0X4));
    // 0x800C92EC: lw          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C92F0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x800C92F4: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800C92F8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800C92FC: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x800C9300: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C9304: jal         0x800CF1B0
    // 0x800C9308: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x800C9308: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x800C930C: b           L_800C9394
    // 0x800C9310: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800C9394;
    // 0x800C9310: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C9314:
    // 0x800C9314: lw          $t8, 0x0($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800C9318: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C931C: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800C9320: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800C9324: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x800C9328: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C932C: lw          $a0, -0x4($t6)
    ctx->r4 = S32(MEM_W(ctx->r14, -0X4));
    // 0x800C9330: jal         0x800BDA6C
    // 0x800C9334: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x800C9334: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x800C9338: lw          $v1, 0x24($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800C933C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800C9340: bltz        $v1, L_800C9390
    if (SIGNED(ctx->r3) < 0) {
        // 0x800C9344: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800C9390;
    }
    // 0x800C9344: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C9348: beql        $at, $zero, L_800C9394
    if (ctx->r1 == 0) {
        // 0x800C934C: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800C9394;
    }
    goto skip_18;
    // 0x800C934C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_18:
    // 0x800C9350: b           L_800C9390
    // 0x800C9354: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_800C9390;
    // 0x800C9354: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800C9358: lw          $t8, 0xC($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0XC));
L_800C935C:
    // 0x800C935C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x800C9360: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800C9364: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800C9368: lw          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C936C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C9370: b           L_800C9390
    // 0x800C9374: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800C9390;
    // 0x800C9374: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800C9378:
    // 0x800C9378: lw          $t6, 0xC($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0XC));
L_800C937C:
    // 0x800C937C: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x800C9380: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x800C9384: lw          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800C9388: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C938C: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800C9390:
    // 0x800C9390: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C9394:
    // 0x800C9394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9398: jr          $ra
    // 0x800C939C: nop

    return;
    // 0x800C939C: nop

;}
RECOMP_FUNC void static_5_800CCEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCEC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CCEC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CCEC8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CCECC: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800CCED0: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x800CCED4: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800CCED8: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CCEDC: blez        $s1, L_800CCF48
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800CCEE0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CCF48;
    }
    // 0x800CCEE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CCEE4: lw          $t9, 0x30($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X30));
    // 0x800CCEE8: lw          $a0, 0x44($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X44));
    // 0x800CCEEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CCEF0: jalr        $t9
    // 0x800CCEF4: lw          $a2, 0x34($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X34));
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CCEF4: lw          $a2, 0x34($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X34));
    after_0:
    // 0x800CCEF8: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CCEFC: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x800CCF00: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x800CCF04: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CCF08: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CCF0C: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x800CCF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CCF14: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x800CCF18: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800CCF1C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CCF20: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CCF24: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CCF28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CCF2C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CCF30: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x800CCF34: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800CCF38: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CCF3C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800CCF40: b           L_800CCF4C
    // 0x800CCF44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800CCF4C;
    // 0x800CCF44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800CCF48:
    // 0x800CCF48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CCF4C:
    // 0x800CCF4C: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x800CCF50: beq         $t6, $zero, L_800CCF78
    if (ctx->r14 == 0) {
        // 0x800CCF54: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800CCF78;
    }
    // 0x800CCF54: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CCF58: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x800CCF5C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CCF60: lw          $t8, 0x18($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X18));
    // 0x800CCF64: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CCF68: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CCF6C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800CCF70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CCF74: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800CCF78:
    // 0x800CCF78: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x800CCF7C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CCF80: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CCF84: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800CCF88: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CCF8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CCF90: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x800CCF94: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CCF98: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x800CCF9C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800CCFA0: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x800CCFA4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CCFA8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800CCFAC: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800CCFB0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CCFB4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800CCFB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CCFBC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CCFC0: lw          $t9, 0x14($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X14));
    // 0x800CCFC4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CCFC8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CCFCC: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800CCFD0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CCFD4: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x800CCFD8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CCFDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CCFE0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CCFE4: jr          $ra
    // 0x800CCFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CCFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void static_5_800CDB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDB54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CDB58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CDB5C: lw          $t6, 0x48($s3)
    ctx->r14 = S32(MEM_W(ctx->r19, 0X48));
    // 0x800CDB60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CDB64: lw          $a0, 0x0($s3)
    ctx->r4 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800CDB68: bne         $t6, $at, L_800CDB78
    if (ctx->r14 != ctx->r1) {
        // 0x800CDB6C: nop
    
            goto L_800CDB78;
    }
    // 0x800CDB6C: nop

    // 0x800CDB70: bnel        $s5, $zero, L_800CDB84
    if (ctx->r21 != 0) {
        // 0x800CDB74: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_800CDB84;
    }
    goto skip_0;
    // 0x800CDB74: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    skip_0:
L_800CDB78:
    // 0x800CDB78: b           L_800CDDDC
    // 0x800CDB7C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800CDDDC;
    // 0x800CDB7C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800CDB80: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_800CDB84:
    // 0x800CDB84: lw          $t9, 0x4($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800CDB88: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800CDB8C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800CDB90: jalr        $t9
    // 0x800CDB94: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CDB94: nop

    after_0:
    // 0x800CDB98: lh          $t7, 0x0($s6)
    ctx->r15 = S32(MEM_H(ctx->r22, 0X0));
    // 0x800CDB9C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CDBA0: sll         $s7, $s5, 1
    ctx->r23 = S32(ctx->r21 << 1);
    // 0x800CDBA4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CDBA8: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800CDBAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800CDBB0: lh          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X0));
    // 0x800CDBB4: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x800CDBB8: addiu       $s4, $v0, 0x10
    ctx->r20 = ADD32(ctx->r2, 0X10);
    // 0x800CDBBC: addiu       $t8, $t9, 0x440
    ctx->r24 = ADD32(ctx->r25, 0X440);
    // 0x800CDBC0: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800CDBC4: andi        $t9, $s7, 0xFFFF
    ctx->r25 = ctx->r23 & 0XFFFF;
    // 0x800CDBC8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800CDBCC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CDBD0: lh          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X0));
    // 0x800CDBD4: addiu       $t6, $t8, 0x580
    ctx->r14 = ADD32(ctx->r24, 0X580);
    // 0x800CDBD8: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x800CDBDC: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800CDBE0: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800CDBE4: lh          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X0));
    // 0x800CDBE8: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800CDBEC: addiu       $t8, $v1, 0x800
    ctx->r24 = ADD32(ctx->r3, 0X800);
    // 0x800CDBF0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800CDBF4: addiu       $t7, $v1, 0x6C0
    ctx->r15 = ADD32(ctx->r3, 0X6C0);
    // 0x800CDBF8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800CDBFC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800CDC00: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800CDC04: lw          $t7, 0x38($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X38));
    // 0x800CDC08: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800CDC0C: beql        $t7, $zero, L_800CDDAC
    if (ctx->r15 == 0) {
        // 0x800CDC10: lui         $t7, 0x308
        ctx->r15 = S32(0X308 << 16);
            goto L_800CDDAC;
    }
    goto skip_1;
    // 0x800CDC10: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
    skip_1:
    // 0x800CDC14: lh          $t6, 0x18($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X18));
    // 0x800CDC18: sw          $zero, 0x38($s3)
    MEM_W(0X38, ctx->r19) = 0;
    // 0x800CDC1C: lh          $t7, 0x1A($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X1A));
    // 0x800CDC20: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800CDC24: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800CDC28: lh          $t9, 0x2420($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X2420));
    // 0x800CDC2C: lw          $a0, 0x34($s3)
    ctx->r4 = S32(MEM_W(ctx->r19, 0X34));
    // 0x800CDC30: addiu       $s1, $s3, 0x24
    ctx->r17 = ADD32(ctx->r19, 0X24);
    // 0x800CDC34: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CDC38: lh          $t9, 0x1C($s3)
    ctx->r25 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x800CDC3C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800CDC40: nop

    // 0x800CDC44: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CDC48: mflo        $t6
    ctx->r14 = lo;
    // 0x800CDC4C: sra         $t8, $t6, 15
    ctx->r24 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800CDC50: sh          $t8, 0x28($s3)
    MEM_H(0X28, ctx->r19) = ctx->r24;
    // 0x800CDC54: lh          $t7, 0x28($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X28));
    // 0x800CDC58: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800CDC5C: jal         0x800CD984
    // 0x800CDC60: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    static_5_800CD984(rdram, ctx);
        goto after_1;
    // 0x800CDC60: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_1:
    // 0x800CDC64: lh          $t6, 0x18($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X18));
    // 0x800CDC68: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800CDC6C: sh          $v0, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r2;
    // 0x800CDC70: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800CDC74: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x800CDC78: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800CDC7C: lh          $t7, 0x251E($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X251E));
    // 0x800CDC80: lh          $t6, 0x1A($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X1A));
    // 0x800CDC84: lw          $a0, 0x34($s3)
    ctx->r4 = S32(MEM_W(ctx->r19, 0X34));
    // 0x800CDC88: addiu       $s1, $s3, 0x2A
    ctx->r17 = ADD32(ctx->r19, 0X2A);
    // 0x800CDC8C: multu       $t7, $t6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CDC90: lh          $t7, 0x1E($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X1E));
    // 0x800CDC94: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800CDC98: nop

    // 0x800CDC9C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CDCA0: mflo        $t8
    ctx->r24 = lo;
    // 0x800CDCA4: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x800CDCA8: sh          $t9, 0x2E($s3)
    MEM_H(0X2E, ctx->r19) = ctx->r25;
    // 0x800CDCAC: lh          $t6, 0x2E($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X2E));
    // 0x800CDCB0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800CDCB4: jal         0x800CD984
    // 0x800CDCB8: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    static_5_800CD984(rdram, ctx);
        goto after_2;
    // 0x800CDCB8: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_2:
    // 0x800CDCBC: lh          $t8, 0x1C($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X1C));
    // 0x800CDCC0: sh          $v0, 0x2C($s3)
    MEM_H(0X2C, ctx->r19) = ctx->r2;
    // 0x800CDCC4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800CDCC8: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x800CDCCC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800CDCD0: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800CDCD4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800CDCD8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800CDCDC: lh          $t6, 0x1E($s3)
    ctx->r14 = S32(MEM_H(ctx->r19, 0X1E));
    // 0x800CDCE0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800CDCE4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800CDCE8: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x800CDCEC: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800CDCF0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800CDCF4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800CDCF8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CDCFC: lh          $t7, 0x28($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X28));
    // 0x800CDD00: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800CDD04: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x800CDD08: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800CDD0C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800CDD10: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800CDD14: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CDD18: lh          $t7, 0x26($s3)
    ctx->r15 = S32(MEM_H(ctx->r19, 0X26));
    // 0x800CDD1C: lhu         $t9, 0x24($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X24);
    // 0x800CDD20: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800CDD24: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800CDD28: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800CDD2C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800CDD30: lh          $t8, 0x2E($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X2E));
    // 0x800CDD34: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x800CDD38: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800CDD3C: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800CDD40: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800CDD44: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CDD48: lh          $t8, 0x2C($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X2C));
    // 0x800CDD4C: lhu         $t7, 0x2A($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X2A);
    // 0x800CDD50: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800CDD54: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800CDD58: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800CDD5C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800CDD60: lh          $t9, 0x20($s3)
    ctx->r25 = S32(MEM_H(ctx->r19, 0X20));
    // 0x800CDD64: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x800CDD68: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800CDD6C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800CDD70: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CDD74: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CDD78: lh          $t8, 0x22($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0X22));
    // 0x800CDD7C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800CDD80: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800CDD84: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800CDD88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CDD8C: lui         $t6, 0x309
    ctx->r14 = S32(0X309 << 16);
    // 0x800CDD90: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800CDD94: lw          $a0, 0x14($s3)
    ctx->r4 = S32(MEM_W(ctx->r19, 0X14));
    // 0x800CDD98: jal         0x800BF6F0
    // 0x800CDD9C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800CDD9C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_3:
    // 0x800CDDA0: b           L_800CDDC0
    // 0x800CDDA4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_800CDDC0;
    // 0x800CDDA4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800CDDA8: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
L_800CDDAC:
    // 0x800CDDAC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800CDDB0: lw          $a0, 0x14($s3)
    ctx->r4 = S32(MEM_W(ctx->r19, 0X14));
    // 0x800CDDB4: jal         0x800BF6F0
    // 0x800CDDB8: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800CDDB8: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_4:
    // 0x800CDDBC: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800CDDC0:
    // 0x800CDDC0: lh          $t8, 0x0($s6)
    ctx->r24 = S32(MEM_H(ctx->r22, 0X0));
    // 0x800CDDC4: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800CDDC8: addu        $t9, $t8, $s7
    ctx->r25 = ADD32(ctx->r24, ctx->r23);
    // 0x800CDDCC: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x800CDDD0: lw          $t6, 0x30($s3)
    ctx->r14 = S32(MEM_W(ctx->r19, 0X30));
    // 0x800CDDD4: addu        $t7, $t6, $s5
    ctx->r15 = ADD32(ctx->r14, ctx->r21);
    // 0x800CDDD8: sw          $t7, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r15;
L_800CDDDC:
    // 0x800CDDDC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CDDE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CDDE4: jr          $ra
    // 0x800CDDE8: nop

    return;
    // 0x800CDDE8: nop

;}
RECOMP_FUNC void static_5_800CDDEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDDEC: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x800CDDF0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800CDDF4: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x800CDDF8: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x800CDDFC: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x800CDE00: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800CDE04: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CDE08: bne         $t9, $zero, L_800CDE18
    if (ctx->r25 != 0) {
        // 0x800CDE0C: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_800CDE18;
    }
    // 0x800CDE0C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800CDE10: jr          $ra
    // 0x800CDE14: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x800CDE14: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800CDE18:
    // 0x800CDE18: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800CDE1C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CDE20: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800CDE24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CDE28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CDE2C: bgez        $a2, L_800CDE44
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800CDE30: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800CDE44;
    }
    // 0x800CDE30: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CDE34: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CDE38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CDE3C: nop

    // 0x800CDE40: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800CDE44:
    // 0x800CDE44: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800CDE48: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CDE4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CDE50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CDE54: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800CDE58: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800CDE5C: div.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800CDE60: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
L_800CDE64:
    // 0x800CDE64: beq         $t7, $zero, L_800CDE74
    if (ctx->r15 == 0) {
        // 0x800CDE68: sra         $t8, $a0, 1
        ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800CDE74;
    }
    // 0x800CDE68: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800CDE6C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800CDE70: nop

L_800CDE74:
    // 0x800CDE74: beq         $t8, $zero, L_800CDE8C
    if (ctx->r24 == 0) {
        // 0x800CDE78: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_800CDE8C;
    }
    // 0x800CDE78: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800CDE7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CDE80: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800CDE84: bnel        $v0, $v1, L_800CDE64
    if (ctx->r2 != ctx->r3) {
        // 0x800CDE88: andi        $t7, $a0, 0x1
        ctx->r15 = ctx->r4 & 0X1;
            goto L_800CDE64;
    }
    goto skip_0;
    // 0x800CDE88: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    skip_0:
L_800CDE8C:
    // 0x800CDE8C: mul.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800CDE90: nop

    // 0x800CDE94: jr          $ra
    // 0x800CDE98: nop

    return;
    // 0x800CDE98: nop

;}
RECOMP_FUNC void static_5_800CF450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF454: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CF458: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800CF45C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CF460: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800CF464: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800CF468: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800CF46C: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x800CF470: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x800CF474: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800CF478: bgtz        $s3, L_800CF48C
    if (SIGNED(ctx->r19) > 0) {
        // 0x800CF47C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CF48C;
    }
    // 0x800CF47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF480: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800CF484: addiu       $s1, $s1, -0x5E90
    ctx->r17 = ADD32(ctx->r17, -0X5E90);
    // 0x800CF488: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800CF48C:
    // 0x800CF48C: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x800CF490: beq         $v0, $s4, L_800CF4C4
    if (ctx->r2 == ctx->r20) {
        // 0x800CF494: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_800CF4C4;
    }
    // 0x800CF494: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800CF498: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800CF49C: beq         $a0, $v1, L_800CF4A8
    if (ctx->r4 == ctx->r3) {
        // 0x800CF4A0: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800CF4A8;
    }
    // 0x800CF4A0: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800CF4A4: bne         $v1, $at, L_800CF700
    if (ctx->r3 != ctx->r1) {
        // 0x800CF4A8: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_800CF700;
    }
L_800CF4A8:
    // 0x800CF4A8: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x800CF4AC: bne         $at, $zero, L_800CF700
    if (ctx->r1 != 0) {
        // 0x800CF4B0: nop
    
            goto L_800CF700;
    }
    // 0x800CF4B0: nop

    // 0x800CF4B4: lw          $t7, 0x24($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF4B8: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CF4BC: beq         $at, $zero, L_800CF700
    if (ctx->r1 == 0) {
        // 0x800CF4C0: nop
    
            goto L_800CF700;
    }
    // 0x800CF4C0: nop

L_800CF4C4:
    // 0x800CF4C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800CF4C8: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x800CF4CC: beq         $v0, $v1, L_800CF508
    if (ctx->r2 == ctx->r3) {
        // 0x800CF4D0: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_800CF508;
    }
    // 0x800CF4D0: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800CF4D4: lw          $t6, 0x30($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X30));
    // 0x800CF4D8: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF4DC: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800CF4E0: bne         $t7, $zero, L_800CF4F8
    if (ctx->r15 != 0) {
        // 0x800CF4E4: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800CF4F8;
    }
    // 0x800CF4E4: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CF4E8: beql        $at, $zero, L_800CF4FC
    if (ctx->r1 == 0) {
        // 0x800CF4EC: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_800CF4FC;
    }
    goto skip_0;
    // 0x800CF4EC: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x800CF4F0: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800CF4F4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800CF4F8:
    // 0x800CF4F8: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_800CF4FC:
    // 0x800CF4FC: bgez        $t8, L_800CF508
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800CF500: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800CF508;
    }
    // 0x800CF500: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800CF504: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800CF508:
    // 0x800CF508: bgtz        $s2, L_800CF5D8
    if (SIGNED(ctx->r18) > 0) {
        // 0x800CF50C: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800CF5D8;
    }
    // 0x800CF50C: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800CF510: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF514: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF518: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800CF51C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800CF520: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800CF524: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800CF528: lw          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF52C: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF530: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CF534: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800CF538: bgtz        $v0, L_800CF550
    if (SIGNED(ctx->r2) > 0) {
        // 0x800CF53C: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_800CF550;
    }
    // 0x800CF53C: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x800CF540: lw          $t6, 0x30($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X30));
    // 0x800CF544: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x800CF548: beql        $t9, $zero, L_800CF578
    if (ctx->r25 == 0) {
        // 0x800CF54C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800CF578;
    }
    goto skip_1;
    // 0x800CF54C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_800CF550:
    // 0x800CF550: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF554: lw          $t6, 0x14($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF558: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x800CF55C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800CF560: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800CF564: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF568: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF56C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800CF570: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800CF574: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800CF578:
    // 0x800CF578: beql        $at, $zero, L_800CF594
    if (ctx->r1 == 0) {
        // 0x800CF57C: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_800CF594;
    }
    goto skip_2;
    // 0x800CF57C: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x800CF580: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x800CF584: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800CF588: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800CF58C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800CF590: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_800CF594:
    // 0x800CF594: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800CF598: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800CF59C: beq         $at, $zero, L_800CF5B0
    if (ctx->r1 == 0) {
        // 0x800CF5A0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800CF5B0;
    }
    // 0x800CF5A0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800CF5A4: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x800CF5A8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800CF5AC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800CF5B0:
    // 0x800CF5B0: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF5B4: lw          $t9, 0x14($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF5B8: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800CF5BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800CF5C0: jal         0x800BDA40
    // 0x800CF5C4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800CF5C4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800CF5C8: lw          $t8, 0x24($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF5CC: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x800CF5D0: b           L_800CF95C
    // 0x800CF5D4: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_800CF95C;
    // 0x800CF5D4: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_800CF5D8:
    // 0x800CF5D8: beq         $at, $zero, L_800CF650
    if (ctx->r1 == 0) {
        // 0x800CF5DC: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800CF650;
    }
    // 0x800CF5DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CF5E0: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF5E4: lw          $t9, 0x14($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF5E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CF5EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800CF5F0: jal         0x800BDA40
    // 0x800CF5F4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x800CF5F4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x800CF5F8: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF5FC: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF600: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x800CF604: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x800CF608: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800CF60C: bgtz        $v0, L_800CF624
    if (SIGNED(ctx->r2) > 0) {
        // 0x800CF610: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_800CF624;
    }
    // 0x800CF610: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x800CF614: lw          $t9, 0x30($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X30));
    // 0x800CF618: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x800CF61C: beq         $t8, $zero, L_800CF648
    if (ctx->r24 == 0) {
        // 0x800CF620: nop
    
            goto L_800CF648;
    }
    // 0x800CF620: nop

L_800CF624:
    // 0x800CF624: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF628: lw          $t9, 0x14($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF62C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800CF630: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CF634: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x800CF638: lw          $t7, 0x1C($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X1C));
    // 0x800CF63C: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF640: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800CF644: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800CF648:
    // 0x800CF648: b           L_800CF95C
    // 0x800CF64C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_800CF95C;
    // 0x800CF64C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_800CF650:
    // 0x800CF650: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF654: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF658: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800CF65C: jal         0x800BDA40
    // 0x800CF660: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x800CF660: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x800CF664: lw          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF668: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF66C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800CF670: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800CF674: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800CF678: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800CF67C: bgtz        $v0, L_800CF694
    if (SIGNED(ctx->r2) > 0) {
        // 0x800CF680: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800CF694;
    }
    // 0x800CF680: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CF684: lw          $t7, 0x30($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X30));
    // 0x800CF688: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800CF68C: beql        $t9, $zero, L_800CF6BC
    if (ctx->r25 == 0) {
        // 0x800CF690: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800CF6BC;
    }
    goto skip_3;
    // 0x800CF690: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_800CF694:
    // 0x800CF694: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF698: lw          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF69C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800CF6A0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800CF6A4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800CF6A8: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF6AC: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF6B0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800CF6B4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800CF6B8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800CF6BC:
    // 0x800CF6BC: beq         $at, $zero, L_800CF6D0
    if (ctx->r1 == 0) {
        // 0x800CF6C0: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_800CF6D0;
    }
    // 0x800CF6C0: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x800CF6C4: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800CF6C8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800CF6CC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800CF6D0:
    // 0x800CF6D0: lw          $t9, 0x8($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF6D4: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF6D8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800CF6DC: jal         0x800BDA40
    // 0x800CF6E0: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800CF6E0: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x800CF6E4: lw          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF6E8: lw          $t9, 0x24($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF6EC: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x800CF6F0: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800CF6F4: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800CF6F8: b           L_800CF95C
    // 0x800CF6FC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_800CF95C;
    // 0x800CF6FC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_800CF700:
    // 0x800CF700: beq         $a0, $v1, L_800CF710
    if (ctx->r4 == ctx->r3) {
        // 0x800CF704: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800CF710;
    }
    // 0x800CF704: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800CF708: bnel        $v1, $at, L_800CF750
    if (ctx->r3 != ctx->r1) {
        // 0x800CF70C: lw          $t8, 0x8($s0)
        ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
            goto L_800CF750;
    }
    goto skip_4;
    // 0x800CF70C: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    skip_4:
L_800CF710:
    // 0x800CF710: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF714: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x800CF718: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CF71C: beql        $at, $zero, L_800CF730
    if (ctx->r1 == 0) {
        // 0x800CF720: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800CF730;
    }
    goto skip_5;
    // 0x800CF720: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x800CF724: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800CF728: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800CF72C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800CF730:
    // 0x800CF730: bgez        $t7, L_800CF73C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CF734: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_800CF73C;
    }
    // 0x800CF734: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x800CF738: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800CF73C:
    // 0x800CF73C: bne         $a0, $v1, L_800CF74C
    if (ctx->r4 != ctx->r3) {
        // 0x800CF740: nop
    
            goto L_800CF74C;
    }
    // 0x800CF740: nop

    // 0x800CF744: b           L_800CF74C
    // 0x800CF748: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_800CF74C;
    // 0x800CF748: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_800CF74C:
    // 0x800CF74C: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
L_800CF750:
    // 0x800CF750: lw          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF754: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF758: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CF75C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800CF760: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800CF764: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF768: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF76C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800CF770: bgtz        $v0, L_800CF788
    if (SIGNED(ctx->r2) > 0) {
        // 0x800CF774: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_800CF788;
    }
    // 0x800CF774: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800CF778: lw          $t9, 0x30($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X30));
    // 0x800CF77C: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800CF780: beq         $t6, $zero, L_800CF7AC
    if (ctx->r14 == 0) {
        // 0x800CF784: nop
    
            goto L_800CF7AC;
    }
    // 0x800CF784: nop

L_800CF788:
    // 0x800CF788: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF78C: lw          $t9, 0x14($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF790: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x800CF794: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800CF798: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800CF79C: lw          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF7A0: lw          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF7A4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800CF7A8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_800CF7AC:
    // 0x800CF7AC: blezl       $v0, L_800CF808
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CF7B0: lw          $t6, 0x8($s0)
        ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
            goto L_800CF808;
    }
    goto skip_6;
    // 0x800CF7B0: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
    skip_6:
    // 0x800CF7B4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800CF7B8: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800CF7BC: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800CF7C0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800CF7C4: beq         $at, $zero, L_800CF7D8
    if (ctx->r1 == 0) {
        // 0x800CF7C8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800CF7D8;
    }
    // 0x800CF7C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CF7CC: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800CF7D0: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800CF7D4: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_800CF7D8:
    // 0x800CF7D8: lw          $t9, 0x8($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF7DC: lw          $t8, 0x14($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF7E0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800CF7E4: jal         0x800BDA40
    // 0x800CF7E8: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x800CF7E8: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x800CF7EC: lw          $t6, 0x14($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF7F0: lw          $t9, 0x24($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X24));
    // 0x800CF7F4: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x800CF7F8: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800CF7FC: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800CF800: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x800CF804: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
L_800CF808:
    // 0x800CF808: lw          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF80C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800CF810: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CF814: bltz        $s2, L_800CF82C
    if (SIGNED(ctx->r18) < 0) {
        // 0x800CF818: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_800CF82C;
    }
    // 0x800CF818: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x800CF81C: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x800CF820: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800CF824: b           L_800CF848
    // 0x800CF828: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800CF848;
    // 0x800CF828: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800CF82C:
    // 0x800CF82C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x800CF830: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800CF834: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800CF838: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CF83C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800CF840: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CF844: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800CF848:
    // 0x800CF848: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x800CF84C: bnel        $at, $zero, L_800CF8F8
    if (ctx->r1 != 0) {
        // 0x800CF850: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800CF8F8;
    }
    goto skip_7;
    // 0x800CF850: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x800CF854: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x800CF858: bne         $at, $zero, L_800CF8A8
    if (ctx->r1 != 0) {
        // 0x800CF85C: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_800CF8A8;
    }
    // 0x800CF85C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800CF860: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800CF864: bne         $v0, $zero, L_800CF870
    if (ctx->r2 != 0) {
        // 0x800CF868: nop
    
            goto L_800CF870;
    }
    // 0x800CF868: nop

    // 0x800CF86C: break       7
    do_break(2148333676);
L_800CF870:
    // 0x800CF870: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CF874: bne         $v0, $at, L_800CF888
    if (ctx->r2 != ctx->r1) {
        // 0x800CF878: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CF888;
    }
    // 0x800CF878: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CF87C: bne         $s2, $at, L_800CF888
    if (ctx->r18 != ctx->r1) {
        // 0x800CF880: nop
    
            goto L_800CF888;
    }
    // 0x800CF880: nop

    // 0x800CF884: break       6
    do_break(2148333700);
L_800CF888:
    // 0x800CF888: mfhi        $s2
    ctx->r18 = hi;
    // 0x800CF88C: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800CF890: mflo        $t9
    ctx->r25 = lo;
    // 0x800CF894: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800CF898: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CF89C: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800CF8A0: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800CF8A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800CF8A8:
    // 0x800CF8A8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800CF8AC: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800CF8B0: bne         $v0, $zero, L_800CF8BC
    if (ctx->r2 != 0) {
        // 0x800CF8B4: nop
    
            goto L_800CF8BC;
    }
    // 0x800CF8B4: nop

    // 0x800CF8B8: break       7
    do_break(2148333752);
L_800CF8BC:
    // 0x800CF8BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CF8C0: bne         $v0, $at, L_800CF8D4
    if (ctx->r2 != ctx->r1) {
        // 0x800CF8C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CF8D4;
    }
    // 0x800CF8C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CF8C8: bne         $s2, $at, L_800CF8D4
    if (ctx->r18 != ctx->r1) {
        // 0x800CF8CC: nop
    
            goto L_800CF8D4;
    }
    // 0x800CF8CC: nop

    // 0x800CF8D0: break       6
    do_break(2148333776);
L_800CF8D4:
    // 0x800CF8D4: mfhi        $s2
    ctx->r18 = hi;
    // 0x800CF8D8: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800CF8DC: mflo        $t9
    ctx->r25 = lo;
    // 0x800CF8E0: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800CF8E4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CF8E8: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800CF8EC: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800CF8F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CF8F4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800CF8F8:
    // 0x800CF8F8: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800CF8FC: bne         $v0, $zero, L_800CF908
    if (ctx->r2 != 0) {
        // 0x800CF900: nop
    
            goto L_800CF908;
    }
    // 0x800CF900: nop

    // 0x800CF904: break       7
    do_break(2148333828);
L_800CF908:
    // 0x800CF908: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CF90C: bne         $v0, $at, L_800CF920
    if (ctx->r2 != ctx->r1) {
        // 0x800CF910: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CF920;
    }
    // 0x800CF910: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CF914: bne         $s2, $at, L_800CF920
    if (ctx->r18 != ctx->r1) {
        // 0x800CF918: nop
    
            goto L_800CF920;
    }
    // 0x800CF918: nop

    // 0x800CF91C: break       6
    do_break(2148333852);
L_800CF920:
    // 0x800CF920: mfhi        $s2
    ctx->r18 = hi;
    // 0x800CF924: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800CF928: mflo        $t9
    ctx->r25 = lo;
    // 0x800CF92C: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800CF930: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CF934: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x800CF938: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800CF93C: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x800CF940: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800CF944: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800CF948: lw          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF94C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800CF950: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x800CF954: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800CF958: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800CF95C:
    // 0x800CF95C: lw          $t8, 0x30($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X30));
    // 0x800CF960: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800CF964: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x800CF968: bnel        $t6, $at, L_800CF9AC
    if (ctx->r14 != ctx->r1) {
        // 0x800CF96C: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CF9AC;
    }
    goto skip_8;
    // 0x800CF96C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_8:
    // 0x800CF970: lw          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0XC));
    // 0x800CF974: lw          $t9, 0x14($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X14));
    // 0x800CF978: lw          $t6, 0x18($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X18));
    // 0x800CF97C: lw          $v1, 0x28($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X28));
    // 0x800CF980: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CF984: lw          $t9, 0x1C($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X1C));
    // 0x800CF988: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800CF98C: lw          $t6, 0x20($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X20));
    // 0x800CF990: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CF994: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800CF998: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800CF99C: beq         $at, $zero, L_800CF9A8
    if (ctx->r1 == 0) {
        // 0x800CF9A0: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_800CF9A8;
    }
    // 0x800CF9A0: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800CF9A4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800CF9A8:
    // 0x800CF9A8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CF9AC:
    // 0x800CF9AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF9B0: jr          $ra
    // 0x800CF9B4: nop

    return;
    // 0x800CF9B4: nop

    // 0x800CF9B8: jr          $ra
    // 0x800CF9BC: nop

    return;
    // 0x800CF9BC: nop

;}
RECOMP_FUNC void static_5_800CFFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFFD8: lw          $v1, 0x8($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CFFDC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800CFFE0: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800CFFE4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800CFFE8: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x800CFFEC: beq         $t7, $zero, L_800D001C
    if (ctx->r15 == 0) {
        // 0x800CFFF0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D001C;
    }
    // 0x800CFFF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CFFF4: andi        $a1, $v0, 0x7F
    ctx->r5 = ctx->r2 & 0X7F;
L_800CFFF8:
    // 0x800CFFF8: lw          $v1, 0x8($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CFFFC: sll         $t9, $a1, 7
    ctx->r25 = S32(ctx->r5 << 7);
    // 0x800D0000: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800D0004: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800D0008: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800D000C: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x800D0010: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x800D0014: bne         $t7, $zero, L_800CFFF8
    if (ctx->r15 != 0) {
        // 0x800D0018: addu        $a1, $t9, $t6
        ctx->r5 = ADD32(ctx->r25, ctx->r14);
            goto L_800CFFF8;
    }
    // 0x800D0018: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
L_800D001C:
    // 0x800D001C: jr          $ra
    // 0x800D0020: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800D0020: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void static_5_800D0458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0458: lw          $a1, 0x8($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800D045C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800D0460: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x800D0464: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800D0468: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800D046C: sll         $t6, $v1, 24
    ctx->r14 = S32(ctx->r3 << 24);
    // 0x800D0470: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D0474: or          $v1, $t6, $t9
    ctx->r3 = ctx->r14 | ctx->r25;
    // 0x800D0478: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800D047C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800D0480: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800D0484: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D0488: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800D048C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800D0490: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x800D0494: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x800D0498: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800D049C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800D04A0: jr          $ra
    // 0x800D04A4: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
    return;
    // 0x800D04A4: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
;}
RECOMP_FUNC void static_5_800D04A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D04A8: lw          $a1, 0x8($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800D04AC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800D04B0: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x800D04B4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800D04B8: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x800D04BC: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x800D04C0: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800D04C4: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800D04C8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800D04CC: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800D04D0: jr          $ra
    // 0x800D04D4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    return;
    // 0x800D04D4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void static_5_8004CBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CBE0: lw          $v0, 0x10($a1)
    ctx->r2 = S32(MEM_W(ctx->r5, 0X10));
    // 0x8004CBE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004CBE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004CBEC: bnel        $v0, $at, L_8004CC1C
    if (ctx->r2 != ctx->r1) {
        // 0x8004CBF0: lw          $v0, 0x270($a0)
        ctx->r2 = S32(MEM_W(ctx->r4, 0X270));
            goto L_8004CC1C;
    }
    goto skip_0;
    // 0x8004CBF0: lw          $v0, 0x270($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X270));
    skip_0:
    // 0x8004CBF4: lw          $v0, 0x26C($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X26C));
    // 0x8004CBF8: beql        $v0, $zero, L_8004CC0C
    if (ctx->r2 == 0) {
        // 0x8004CBFC: sw          $a1, 0x264($a0)
        MEM_W(0X264, ctx->r4) = ctx->r5;
            goto L_8004CC0C;
    }
    goto skip_1;
    // 0x8004CBFC: sw          $a1, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->r5;
    skip_1:
    // 0x8004CC00: b           L_8004CC0C
    // 0x8004CC04: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_8004CC0C;
    // 0x8004CC04: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8004CC08: sw          $a1, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->r5;
L_8004CC0C:
    // 0x8004CC0C: sw          $a1, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r5;
    // 0x8004CC10: b           L_8004CC34
    // 0x8004CC14: sw          $t6, 0x280($a0)
    MEM_W(0X280, ctx->r4) = ctx->r14;
        goto L_8004CC34;
    // 0x8004CC14: sw          $t6, 0x280($a0)
    MEM_W(0X280, ctx->r4) = ctx->r14;
    // 0x8004CC18: lw          $v0, 0x270($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X270));
L_8004CC1C:
    // 0x8004CC1C: beql        $v0, $zero, L_8004CC30
    if (ctx->r2 == 0) {
        // 0x8004CC20: sw          $a1, 0x268($a0)
        MEM_W(0X268, ctx->r4) = ctx->r5;
            goto L_8004CC30;
    }
    goto skip_2;
    // 0x8004CC20: sw          $a1, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r5;
    skip_2:
    // 0x8004CC24: b           L_8004CC30
    // 0x8004CC28: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_8004CC30;
    // 0x8004CC28: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8004CC2C: sw          $a1, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r5;
L_8004CC30:
    // 0x8004CC30: sw          $a1, 0x270($a0)
    MEM_W(0X270, ctx->r4) = ctx->r5;
L_8004CC34:
    // 0x8004CC34: lw          $t7, 0x8($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X8));
    // 0x8004CC38: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8004CC3C: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x8004CC40: jr          $ra
    // 0x8004CC44: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    return;
    // 0x8004CC44: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void static_5_8004CD58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CD58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004CD5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004CD60: lw          $v0, 0x274($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X274));
    // 0x8004CD64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004CD68: lw          $t6, 0x10($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X10));
    // 0x8004CD6C: bnel        $t6, $at, L_8004CD88
    if (ctx->r14 != ctx->r1) {
        // 0x8004CD70: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8004CD88;
    }
    goto skip_0;
    // 0x8004CD70: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x8004CD74: lw          $t7, 0x4($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X4));
    // 0x8004CD78: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8004CD7C: jal         0x800BC710
    // 0x8004CD80: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    osSpTaskYield_recomp(rdram, ctx);
        goto after_0;
    // 0x8004CD80: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    after_0:
    // 0x8004CD84: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004CD88:
    // 0x8004CD88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004CD8C: jr          $ra
    // 0x8004CD90: nop

    return;
    // 0x8004CD90: nop

;}
RECOMP_FUNC void static_5_8004CD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CD94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004CD98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004CD9C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004CDA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004CDA4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004CDA8: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
L_8004CDAC:
    // 0x8004CDAC: lw          $t6, 0x280($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X280));
    // 0x8004CDB0: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8004CDB4: lw          $s0, 0x268($s1)
    ctx->r16 = S32(MEM_W(ctx->r17, 0X268));
    // 0x8004CDB8: beq         $t6, $zero, L_8004CE14
    if (ctx->r14 == 0) {
        // 0x8004CDBC: lw          $v0, 0x264($s1)
        ctx->r2 = S32(MEM_W(ctx->r17, 0X264));
            goto L_8004CE14;
    }
    // 0x8004CDBC: lw          $v0, 0x264($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X264));
    // 0x8004CDC0: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x8004CDC4: beql        $t7, $zero, L_8004CE18
    if (ctx->r15 == 0) {
        // 0x8004CDC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8004CE18;
    }
    goto skip_0;
    // 0x8004CDC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8004CDCC: beql        $s0, $zero, L_8004CDF4
    if (ctx->r16 == 0) {
        // 0x8004CDD0: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_8004CDF4;
    }
    goto skip_1;
    // 0x8004CDD0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    skip_1:
    // 0x8004CDD4: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8004CDD8: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8004CDDC: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8004CDE0: beql        $t9, $zero, L_8004CDF4
    if (ctx->r25 == 0) {
        // 0x8004CDE4: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_8004CDF4;
    }
    goto skip_2;
    // 0x8004CDE4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    skip_2:
    // 0x8004CDE8: b           L_8004CF50
    // 0x8004CDEC: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
        goto L_8004CF50;
    // 0x8004CDEC: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8004CDF0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8004CDF4:
    // 0x8004CDF4: lw          $t2, 0x264($s1)
    ctx->r10 = S32(MEM_W(ctx->r17, 0X264));
    // 0x8004CDF8: sw          $zero, 0x280($s1)
    MEM_W(0X280, ctx->r17) = 0;
    // 0x8004CDFC: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8004CE00: lw          $t3, 0x0($t2)
    ctx->r11 = S32(MEM_W(ctx->r10, 0X0));
    // 0x8004CE04: bne         $t3, $zero, L_8004CF50
    if (ctx->r11 != 0) {
        // 0x8004CE08: sw          $t3, 0x264($s1)
        MEM_W(0X264, ctx->r17) = ctx->r11;
            goto L_8004CF50;
    }
    // 0x8004CE08: sw          $t3, 0x264($s1)
    MEM_W(0X264, ctx->r17) = ctx->r11;
    // 0x8004CE0C: b           L_8004CF50
    // 0x8004CE10: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
        goto L_8004CF50;
    // 0x8004CE10: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
L_8004CE14:
    // 0x8004CE14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8004CE18:
    // 0x8004CE18: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8004CE1C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004CE20: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004CE24: jal         0x8004CAD0
    // 0x8004CE28: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    __scTaskReady(rdram, ctx);
        goto after_0;
    // 0x8004CE28: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004CE2C: lw          $v1, 0x24($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8004CE30: lw          $a1, 0x2C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8004CE34: lw          $a2, 0x30($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8004CE38: lw          $a3, 0x34($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8004CE3C: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
    // 0x8004CE40: beq         $v0, $zero, L_8004CF50
    if (ctx->r2 == 0) {
        // 0x8004CE44: addiu       $t1, $zero, -0x2
        ctx->r9 = ADD32(0, -0X2);
            goto L_8004CF50;
    }
    // 0x8004CE44: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
    // 0x8004CE48: lw          $t5, 0x8($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8004CE4C: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8004CE50: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8004CE54: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8004CE58: beq         $at, $zero, L_8004CF50
    if (ctx->r1 == 0) {
        // 0x8004CE5C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8004CF50;
    }
    // 0x8004CE5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8004CE60: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8004CE64: addu        $at, $at, $t7
    gpr jr_addend_8004CE6C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8004CE68: lw          $t7, 0x2720($at)
    ctx->r15 = ADD32(ctx->r1, 0X2720);
    // 0x8004CE6C: jr          $t7
    // 0x8004CE70: nop

    switch (jr_addend_8004CE6C >> 2) {
        case 0: goto L_8004CF50; break;
        case 1: goto L_8004CEFC; break;
        case 2: goto L_8004CE74; break;
        case 3: goto L_8004CF50; break;
        case 4: goto L_8004CF50; break;
        case 5: goto L_8004CEFC; break;
        case 6: goto L_8004CEFC; break;
        default: switch_error(__func__, 0x8004CE6C, 0x80102720);
    }
    // 0x8004CE70: nop

L_8004CE74:
    // 0x8004CE74: lw          $t8, 0x4($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004CE78: andi        $t2, $a3, 0x2
    ctx->r10 = ctx->r7 & 0X2;
    // 0x8004CE7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004CE80: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8004CE84: beq         $t9, $zero, L_8004CECC
    if (ctx->r25 == 0) {
        // 0x8004CE88: nop
    
            goto L_8004CECC;
    }
    // 0x8004CE88: nop

    // 0x8004CE8C: beq         $t2, $zero, L_8004CF50
    if (ctx->r10 == 0) {
        // 0x8004CE90: nop
    
            goto L_8004CF50;
    }
    // 0x8004CE90: nop

    // 0x8004CE94: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8004CE98: lw          $t3, 0x4($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004CE9C: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8004CEA0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8004CEA4: beql        $t4, $zero, L_8004CEB8
    if (ctx->r12 == 0) {
        // 0x8004CEA8: lw          $t5, 0x268($s1)
        ctx->r13 = S32(MEM_W(ctx->r17, 0X268));
            goto L_8004CEB8;
    }
    goto skip_3;
    // 0x8004CEA8: lw          $t5, 0x268($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X268));
    skip_3:
    // 0x8004CEAC: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8004CEB0: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
    // 0x8004CEB4: lw          $t5, 0x268($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X268));
L_8004CEB8:
    // 0x8004CEB8: lw          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8004CEBC: bne         $t6, $zero, L_8004CF50
    if (ctx->r14 != 0) {
        // 0x8004CEC0: sw          $t6, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r14;
            goto L_8004CF50;
    }
    // 0x8004CEC0: sw          $t6, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r14;
    // 0x8004CEC4: b           L_8004CF50
    // 0x8004CEC8: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8004CF50;
    // 0x8004CEC8: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8004CECC:
    // 0x8004CECC: bne         $a3, $at, L_8004CF50
    if (ctx->r7 != ctx->r1) {
        // 0x8004CED0: nop
    
            goto L_8004CF50;
    }
    // 0x8004CED0: nop

    // 0x8004CED4: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8004CED8: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8004CEDC: lw          $t8, 0x268($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X268));
    // 0x8004CEE0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8004CEE4: and         $v1, $a3, $at
    ctx->r3 = ctx->r7 & ctx->r1;
    // 0x8004CEE8: lw          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X0));
    // 0x8004CEEC: bne         $t9, $zero, L_8004CF50
    if (ctx->r25 != 0) {
        // 0x8004CEF0: sw          $t9, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r25;
            goto L_8004CF50;
    }
    // 0x8004CEF0: sw          $t9, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r25;
    // 0x8004CEF4: b           L_8004CF50
    // 0x8004CEF8: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8004CF50;
    // 0x8004CEF8: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8004CEFC:
    // 0x8004CEFC: lw          $v0, 0x4($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004CF00: andi        $t4, $a3, 0x2
    ctx->r12 = ctx->r7 & 0X2;
    // 0x8004CF04: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8004CF08: beq         $t3, $zero, L_8004CF24
    if (ctx->r11 == 0) {
        // 0x8004CF0C: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8004CF24;
    }
    // 0x8004CF0C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8004CF10: beq         $t4, $zero, L_8004CF50
    if (ctx->r12 == 0) {
        // 0x8004CF14: nop
    
            goto L_8004CF50;
    }
    // 0x8004CF14: nop

    // 0x8004CF18: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8004CF1C: b           L_8004CF50
    // 0x8004CF20: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
        goto L_8004CF50;
    // 0x8004CF20: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
L_8004CF24:
    // 0x8004CF24: beq         $t5, $zero, L_8004CF50
    if (ctx->r13 == 0) {
        // 0x8004CF28: andi        $t6, $a3, 0x1
        ctx->r14 = ctx->r7 & 0X1;
            goto L_8004CF50;
    }
    // 0x8004CF28: andi        $t6, $a3, 0x1
    ctx->r14 = ctx->r7 & 0X1;
    // 0x8004CF2C: beq         $t6, $zero, L_8004CF50
    if (ctx->r14 == 0) {
        // 0x8004CF30: nop
    
            goto L_8004CF50;
    }
    // 0x8004CF30: nop

    // 0x8004CF34: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8004CF38: lw          $t7, 0x268($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X268));
    // 0x8004CF3C: and         $v1, $a3, $t1
    ctx->r3 = ctx->r7 & ctx->r9;
    // 0x8004CF40: lw          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X0));
    // 0x8004CF44: bne         $t8, $zero, L_8004CF50
    if (ctx->r24 != 0) {
        // 0x8004CF48: sw          $t8, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r24;
            goto L_8004CF50;
    }
    // 0x8004CF48: sw          $t8, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r24;
    // 0x8004CF4C: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8004CF50:
    // 0x8004CF50: beql        $v1, $a3, L_8004CF64
    if (ctx->r3 == ctx->r7) {
        // 0x8004CF54: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_8004CF64;
    }
    goto skip_4;
    // 0x8004CF54: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_4:
    // 0x8004CF58: b           L_8004CDAC
    // 0x8004CF5C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8004CDAC;
    // 0x8004CF5C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8004CF60: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_8004CF64:
    // 0x8004CF64: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004CF68: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004CF6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004CF70: jr          $ra
    // 0x8004CF74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8004CF74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004CF78: nop

    // 0x8004CF7C: nop

;}
RECOMP_FUNC void static_5_8004CC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CC48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004CC4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004CC50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004CC54: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004CC58: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004CC5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004CC60: beq         $a1, $zero, L_8004CD04
    if (ctx->r5 == 0) {
        // 0x8004CC64: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8004CD04;
    }
    // 0x8004CC64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004CC68: lw          $t6, 0x10($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X10));
    // 0x8004CC6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004CC70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004CC74: bne         $t6, $at, L_8004CCA0
    if (ctx->r14 != ctx->r1) {
        // 0x8004CC78: nop
    
            goto L_8004CCA0;
    }
    // 0x8004CC78: nop

    // 0x8004CC7C: jal         0x800BB2F0
    // 0x8004CC80: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x8004CC80: nop

    after_0:
    // 0x8004CC84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004CC88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CC8C: jal         0x800BB580
    // 0x8004CC90: sw          $t7, 0x3704($at)
    MEM_W(0X3704, ctx->r1) = ctx->r15;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8004CC90: sw          $t7, 0x3704($at)
    MEM_W(0X3704, ctx->r1) = ctx->r15;
    after_1:
    // 0x8004CC94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CC98: b           L_8004CCD0
    // 0x8004CC9C: sw          $v1, 0x3708($at)
    MEM_W(0X3708, ctx->r1) = ctx->r3;
        goto L_8004CCD0;
    // 0x8004CC9C: sw          $v1, 0x3708($at)
    MEM_W(0X3708, ctx->r1) = ctx->r3;
L_8004CCA0:
    // 0x8004CCA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CCA4: jal         0x800BB580
    // 0x8004CCA8: sw          $t9, 0x3710($at)
    MEM_W(0X3710, ctx->r1) = ctx->r25;
    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x8004CCA8: sw          $t9, 0x3710($at)
    MEM_W(0X3710, ctx->r1) = ctx->r25;
    after_2:
    // 0x8004CCAC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004CCB0: addiu       $a0, $a0, 0x3714
    ctx->r4 = ADD32(ctx->r4, 0X3714);
    // 0x8004CCB4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8004CCB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004CCBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CCC0: sw          $t1, 0x371C($at)
    MEM_W(0X371C, ctx->r1) = ctx->r9;
    // 0x8004CCC4: lw          $t2, 0x0($a0)
    ctx->r10 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8004CCC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CCCC: sw          $t2, 0x3720($at)
    MEM_W(0X3720, ctx->r1) = ctx->r10;
L_8004CCD0:
    // 0x8004CCD0: lw          $t3, 0x4($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8004CCD4: addiu       $at, $zero, -0x31
    ctx->r1 = ADD32(0, -0X31);
    // 0x8004CCD8: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8004CCDC: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8004CCE0: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x8004CCE4: jal         0x800BC48C
    // 0x8004CCE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_3;
    // 0x8004CCE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x8004CCEC: jal         0x800BC61C
    // 0x8004CCF0: lw          $a0, 0x20($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X20));
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_4;
    // 0x8004CCF0: lw          $a0, 0x20($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X20));
    after_4:
    // 0x8004CCF4: lw          $t5, 0x28($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8004CCF8: bne         $s0, $s1, L_8004CD04
    if (ctx->r16 != ctx->r17) {
        // 0x8004CCFC: sw          $s0, 0x274($t5)
        MEM_W(0X274, ctx->r13) = ctx->r16;
        if (MEM_W(0X10, ctx->r16) == 2 /* M_AUDTASK */) {
            ultramodern_complete_sp_task(rdram);
        }
            goto L_8004CD04;
    }
    // 0x8004CCFC: sw          $s0, 0x274($t5)
    MEM_W(0X274, ctx->r13) = ctx->r16;
    // 0x8004CD00: sw          $s1, 0x278($t5)
    MEM_W(0X278, ctx->r13) = ctx->r17;
    if (MEM_W(0X10, ctx->r16) == 2 /* M_AUDTASK */) {
        ultramodern_complete_sp_task(rdram);
    }
L_8004CD04:
    // 0x8004CD04: beql        $s1, $zero, L_8004CD48
    if (ctx->r17 == 0) {
        // 0x8004CD08: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_8004CD48;
    }
    goto skip_0;
    // 0x8004CD08: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_0:
    // 0x8004CD0C: beql        $s1, $s0, L_8004CD48
    if (ctx->r17 == ctx->r16) {
        // 0x8004CD10: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_8004CD48;
    }
    goto skip_1;
    // 0x8004CD10: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_1:
    // 0x8004CD14: lw          $t6, 0x3C($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X3C));
    // 0x8004CD18: lw          $a0, 0x38($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X38));
    // 0x8004CD1C: lw          $a2, 0x0($t6)
    ctx->r6 = S32(MEM_W(ctx->r14, 0X0));
    // 0x8004CD20: jal         0x800BC660
    // 0x8004CD24: lw          $a3, 0x4($t6)
    ctx->r7 = S32(MEM_W(ctx->r14, 0X4));
    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x8004CD24: lw          $a3, 0x4($t6)
    ctx->r7 = S32(MEM_W(ctx->r14, 0X4));
    after_5:
    // 0x8004CD28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004CD2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CD30: lw          $t8, 0x28($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8004CD34: sw          $t7, 0x372C($at)
    MEM_W(0X372C, ctx->r1) = ctx->r15;
    // 0x8004CD38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CD3C: sw          $zero, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = 0;
    // 0x8004CD40: sw          $s1, 0x278($t8)
    MEM_W(0X278, ctx->r24) = ctx->r17;
    // 0x8004CD44: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_8004CD48:
    // 0x8004CD48: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004CD4C: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004CD50: jr          $ra
    // 0x8004CD54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004CD54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void static_5_8004CB20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CB20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004CB24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004CB28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004CB2C: lw          $t6, 0x4($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X4));
    // 0x8004CB30: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8004CB34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004CB38: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8004CB3C: bne         $t7, $zero, L_8004CBD0
    if (ctx->r15 != 0) {
        // 0x8004CB40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004CBD0;
    }
    // 0x8004CB40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004CB44: lw          $a0, 0x50($a1)
    ctx->r4 = S32(MEM_W(ctx->r5, 0X50));
    // 0x8004CB48: lw          $a1, 0x54($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, 0X54));
    // 0x8004CB4C: jal         0x800BB610
    // 0x8004CB50: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8004CB50: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004CB54: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004CB58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004CB5C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004CB60: lw          $t8, 0x10($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X10));
    // 0x8004CB64: bne         $t8, $at, L_8004CBC8
    if (ctx->r24 != ctx->r1) {
        // 0x8004CB68: nop
    
            goto L_8004CBC8;
    }
    // 0x8004CB68: nop

    // 0x8004CB6C: lbu         $t9, 0x3700($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X3700);
    // 0x8004CB70: lw          $t0, 0x18($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004CB74: bnel        $t9, $zero, L_8004CBAC
    if (ctx->r25 != 0) {
        // 0x8004CB78: lw          $v0, 0x8($a3)
        ctx->r2 = S32(MEM_W(ctx->r7, 0X8));
            goto L_8004CBAC;
    }
    goto skip_0;
    // 0x8004CB78: lw          $v0, 0x8($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X8));
    skip_0:
    // 0x8004CB7C: lw          $t1, 0x27C($t0)
    ctx->r9 = S32(MEM_W(ctx->r8, 0X27C));
    // 0x8004CB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004CB84: sltiu       $at, $t1, 0x3
    ctx->r1 = ctx->r9 < 0X3 ? 1 : 0;
    // 0x8004CB88: bnel        $at, $zero, L_8004CBA0
    if (ctx->r1 != 0) {
        // 0x8004CB8C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8004CBA0;
    }
    goto skip_1;
    // 0x8004CB8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_1:
    // 0x8004CB90: jal         0x800BAAE0
    // 0x8004CB94: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x8004CB94: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8004CB98: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004CB9C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8004CBA0:
    // 0x8004CBA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CBA4: sb          $t2, 0x3700($at)
    MEM_B(0X3700, ctx->r1) = ctx->r10;
    // 0x8004CBA8: lw          $v0, 0x8($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X8));
L_8004CBAC:
    // 0x8004CBAC: andi        $t3, $v0, 0x40
    ctx->r11 = ctx->r2 & 0X40;
    // 0x8004CBB0: beq         $t3, $zero, L_8004CBC8
    if (ctx->r11 == 0) {
        // 0x8004CBB4: andi        $t4, $v0, 0x20
        ctx->r12 = ctx->r2 & 0X20;
            goto L_8004CBC8;
    }
    // 0x8004CBB4: andi        $t4, $v0, 0x20
    ctx->r12 = ctx->r2 & 0X20;
    // 0x8004CBB8: beq         $t4, $zero, L_8004CBC8
    if (ctx->r12 == 0) {
        // 0x8004CBBC: nop
    
            goto L_8004CBC8;
    }
    // 0x8004CBBC: nop

    // 0x8004CBC0: jal         0x800BC320
    // 0x8004CBC4: lw          $a0, 0xC($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0XC));
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x8004CBC4: lw          $a0, 0xC($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0XC));
    after_2:
L_8004CBC8:
    // 0x8004CBC8: b           L_8004CBD0
    // 0x8004CBCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004CBD0;
    // 0x8004CBCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004CBD0:
    // 0x8004CBD0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004CBD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004CBD8: jr          $ra
    // 0x8004CBDC: nop

    return;
    // 0x8004CBDC: nop

;}
RECOMP_FUNC void static_5_800CD984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD984: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800CD988: bne         $a0, $zero, L_800CD9B8
    if (ctx->r4 != 0) {
        // 0x800CD98C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CD9B8;
    }
    // 0x800CD98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD990: c.le.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d <= ctx->f14.d;
    // 0x800CD994: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800CD998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CD99C: bc1f        L_800CD9B0
    if (!c1cs) {
        // 0x800CD9A0: nop
    
            goto L_800CD9B0;
    }
    // 0x800CD9A0: nop

    // 0x800CD9A4: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x800CD9A8: b           L_800CDB44
    // 0x800CD9AC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_800CDB44;
    // 0x800CD9AC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800CD9B0:
    // 0x800CD9B0: b           L_800CDB44
    // 0x800CD9B4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
        goto L_800CDB44;
    // 0x800CD9B4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_800CD9B8:
    // 0x800CD9B8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CD9BC: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800CD9C0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800CD9C4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800CD9C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CD9CC: c.lt.d      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.d < ctx->f22.d;
    // 0x800CD9D0: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x800CD9D4: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800CD9D8: addiu       $t7, $t7, 0x2520
    ctx->r15 = ADD32(ctx->r15, 0X2520);
    // 0x800CD9DC: bc1f        L_800CD9E8
    if (!c1cs) {
        // 0x800CD9E0: or          $t6, $s2, $zero
        ctx->r14 = ctx->r18 | 0;
            goto L_800CD9E8;
    }
    // 0x800CD9E0: or          $t6, $s2, $zero
    ctx->r14 = ctx->r18 | 0;
    // 0x800CD9E4: mov.d       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.d = ctx->f22.d;
L_800CD9E8:
    // 0x800CD9E8: c.le.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d <= ctx->f4.d;
    // 0x800CD9EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CD9F0: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x800CD9F4: bc1f        L_800CDA08
    if (!c1cs) {
        // 0x800CD9F8: nop
    
            goto L_800CDA08;
    }
    // 0x800CD9F8: nop

    // 0x800CD9FC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CDA00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CDA04: nop

L_800CDA08:
    // 0x800CDA08: lw          $at, 0x0($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800CDA0C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800CDA10: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800CDA14: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x800CDA18: lw          $at, -0x8($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, -0X8));
    // 0x800CDA1C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800CDA20: lw          $at, -0x4($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, -0X4));
    // 0x800CDA24: bne         $t7, $t9, L_800CDA08
    if (ctx->r15 != ctx->r25) {
        // 0x800CDA28: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_800CDA08;
    }
    // 0x800CDA28: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800CDA2C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800CDA30: lui         $t8, 0x4000
    ctx->r24 = S32(0X4000 << 16);
    // 0x800CDA34: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800CDA38: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CDA3C: lw          $at, 0x0($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800CDA40: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x800CDA44: cvt.d.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.d = CVT_D_W(ctx->f6.u32l);
    // 0x800CDA48: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800CDA4C: div.d       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f22.d, ctx->f10.d);
    // 0x800CDA50: div.d       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f16.d);
    // 0x800CDA54: mul.d       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x800CDA58: trunc.w.d   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800CDA5C: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800CDA60: jal         0x800CD7B8
    // 0x800CDA64: nop

    _frexpf(rdram, ctx);
        goto after_0;
    // 0x800CDA64: nop

    after_0:
    // 0x800CDA68: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800CDA6C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800CDA70: lw          $t6, 0xB0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800CDA74: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CDA78: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CDA7C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800CDA80: mul.d       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800CDA84: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CDA88: ldc1        $f8, -0x5F50($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X5F50);
    // 0x800CDA8C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CDA90: trunc.w.d   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800CDA94: mov.d       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.d = ctx->f22.d;
    // 0x800CDA98: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800CDA9C: nop

    // 0x800CDAA0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800CDAA4: addu        $t7, $s2, $t9
    ctx->r15 = ADD32(ctx->r18, ctx->r25);
    // 0x800CDAA8: ldc1        $f6, -0x40($t7)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r15, -0X40);
    // 0x800CDAAC: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x800CDAB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CDAB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CDAB8: mul.d       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800CDABC: nop

    // 0x800CDAC0: mul.d       $f14, $f6, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f14.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x800CDAC4: div.d       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f14.d);
    // 0x800CDAC8: beq         $s0, $zero, L_800CDAF0
    if (ctx->r16 == 0) {
        // 0x800CDACC: add.d       $f0, $f22, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
            goto L_800CDAF0;
    }
    // 0x800CDACC: add.d       $f0, $f22, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
L_800CDAD0:
    // 0x800CDAD0: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x800CDAD4: beq         $t8, $zero, L_800CDAE4
    if (ctx->r24 == 0) {
        // 0x800CDAD8: sra         $t9, $s0, 1
        ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
            goto L_800CDAE4;
    }
    // 0x800CDAD8: sra         $t9, $s0, 1
    ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800CDADC: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x800CDAE0: nop

L_800CDAE4:
    // 0x800CDAE4: mul.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x800CDAE8: bne         $t9, $zero, L_800CDAD0
    if (ctx->r25 != 0) {
        // 0x800CDAEC: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_800CDAD0;
    }
    // 0x800CDAEC: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800CDAF0:
    // 0x800CDAF0: mul.d       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800CDAF4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CDAF8: mul.d       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x800CDAFC: nop

    // 0x800CDB00: mul.d       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f12.d);
    // 0x800CDB04: trunc.w.d   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800CDB08: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800CDB0C: nop

    // 0x800CDB10: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800CDB14: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CDB18: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800CDB1C: nop

    // 0x800CDB20: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CDB24: ldc1        $f4, -0x5F48($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X5F48);
    // 0x800CDB28: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800CDB2C: sub.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f2.d - ctx->f6.d;
    // 0x800CDB30: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800CDB34: trunc.w.d   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x800CDB38: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800CDB3C: nop

    // 0x800CDB40: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_800CDB44:
    // 0x800CDB44: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CDB48: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x800CDB4C: jr          $ra
    // 0x800CDB50: nop

    return;
    // 0x800CDB50: nop

;}
