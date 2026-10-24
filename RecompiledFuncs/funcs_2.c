#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void getincangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089834: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80089838: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8008983C: andi        $t0, $t7, 0x7FF
    ctx->r8 = ctx->r15 & 0X7FF;
    // 0x80089840: andi        $t3, $t9, 0x7FF
    ctx->r11 = ctx->r25 & 0X7FF;
    // 0x80089844: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80089848: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8008984C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80089850: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80089854: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80089858: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8008985C: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x80089860: blez        $v0, L_80089870
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80089864: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_80089870;
    }
    // 0x80089864: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80089868: b           L_80089870
    // 0x8008986C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80089870;
    // 0x8008986C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80089870:
    // 0x80089870: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80089874: beq         $at, $zero, L_80089888
    if (ctx->r1 == 0) {
        // 0x80089878: subu        $v0, $a1, $a0
        ctx->r2 = SUB32(ctx->r5, ctx->r4);
            goto L_80089888;
    }
    // 0x80089878: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // 0x8008987C: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80089880: jr          $ra
    // 0x80089884: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    return;
    // 0x80089884: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_80089888:
    // 0x80089888: slti        $at, $a1, 0x401
    ctx->r1 = SIGNED(ctx->r5) < 0X401 ? 1 : 0;
    // 0x8008988C: bnel        $at, $zero, L_800898A4
    if (ctx->r1 != 0) {
        // 0x80089890: slti        $at, $a0, 0x401
        ctx->r1 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
            goto L_800898A4;
    }
    goto skip_0;
    // 0x80089890: slti        $at, $a0, 0x401
    ctx->r1 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
    skip_0:
    // 0x80089894: addiu       $a1, $a1, -0x800
    ctx->r5 = ADD32(ctx->r5, -0X800);
    // 0x80089898: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8008989C: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800898A0: slti        $at, $a0, 0x401
    ctx->r1 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
L_800898A4:
    // 0x800898A4: bne         $at, $zero, L_800898B8
    if (ctx->r1 != 0) {
        // 0x800898A8: addiu       $t3, $a1, -0x800
        ctx->r11 = ADD32(ctx->r5, -0X800);
            goto L_800898B8;
    }
    // 0x800898A8: addiu       $t3, $a1, -0x800
    ctx->r11 = ADD32(ctx->r5, -0X800);
    // 0x800898AC: addiu       $a0, $a0, -0x800
    ctx->r4 = ADD32(ctx->r4, -0X800);
    // 0x800898B0: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x800898B4: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
L_800898B8:
    // 0x800898B8: addiu       $t5, $a0, -0x800
    ctx->r13 = ADD32(ctx->r4, -0X800);
    // 0x800898BC: subu        $v0, $t3, $t5
    ctx->r2 = SUB32(ctx->r11, ctx->r13);
    // 0x800898C0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800898C4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800898C8: jr          $ra
    // 0x800898CC: nop

    return;
    // 0x800898CC: nop

;}
RECOMP_FUNC void shoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A66F0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800A66F4: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x800A66F8: lh          $t7, 0xDA($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A66FC: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800A6700: addiu       $s6, $zero, 0x2C
    ctx->r22 = ADD32(0, 0X2C);
    // 0x800A6704: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6708: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800A670C: lui         $s5, 0x8024
    ctx->r21 = S32(0X8024 << 16);
    // 0x800A6710: addiu       $s5, $s5, 0x6BA8
    ctx->r21 = ADD32(ctx->r21, 0X6BA8);
    // 0x800A6714: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800A6718: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800A671C: sll         $s4, $a1, 16
    ctx->r20 = S32(ctx->r5 << 16);
    // 0x800A6720: sra         $t6, $s4, 16
    ctx->r14 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800A6724: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x800A6728: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800A672C: mflo        $t8
    ctx->r24 = lo;
    // 0x800A6730: addu        $s1, $s5, $t8
    ctx->r17 = ADD32(ctx->r21, ctx->r24);
    // 0x800A6734: lh          $v1, 0xE($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800A6738: lh          $t9, 0x10($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X10));
    // 0x800A673C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800A6740: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800A6744: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800A6748: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800A674C: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x800A6750: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A6754: bne         $v1, $at, L_800A67C4
    if (ctx->r3 != ctx->r1) {
        // 0x800A6758: sh          $t9, 0xD6($sp)
        MEM_H(0XD6, ctx->r29) = ctx->r25;
            goto L_800A67C4;
    }
    // 0x800A6758: sh          $t9, 0xD6($sp)
    MEM_H(0XD6, ctx->r29) = ctx->r25;
    // 0x800A675C: lh          $t1, 0x1A($s1)
    ctx->r9 = S32(MEM_H(ctx->r17, 0X1A));
    // 0x800A6760: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x800A6764: addiu       $t3, $t3, 0x5770
    ctx->r11 = ADD32(ctx->r11, 0X5770);
    // 0x800A6768: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800A676C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A6770: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800A6774: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800A6778: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A677C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A6780: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A6784: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x800A6788: lw          $t6, 0x244($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X244));
    // 0x800A678C: lw          $t7, 0x21C($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800A6790: lw          $t4, 0x214($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800A6794: lw          $t5, 0x218($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800A6798: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A679C: addiu       $t9, $t8, 0x400
    ctx->r25 = ADD32(ctx->r24, 0X400);
    // 0x800A67A0: addiu       $t2, $zero, 0x309
    ctx->r10 = ADD32(0, 0X309);
    // 0x800A67A4: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x800A67A8: lh          $s3, 0x282($s0)
    ctx->r19 = S32(MEM_H(ctx->r16, 0X282));
    // 0x800A67AC: sw          $t2, 0x27C($s0)
    MEM_W(0X27C, ctx->r16) = ctx->r10;
    // 0x800A67B0: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    // 0x800A67B4: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A67B8: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800A67BC: b           L_800A68A0
    // 0x800A67C0: sw          $t5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r13;
        goto L_800A68A0;
    // 0x800A67C0: sw          $t5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r13;
L_800A67C4:
    // 0x800A67C4: lw          $t4, 0x0($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800A67C8: lw          $t5, 0x4($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800A67CC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800A67D0: sh          $t3, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r11;
    // 0x800A67D4: lh          $s3, 0x14($s1)
    ctx->r19 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800A67D8: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x800A67DC: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A67E0: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    // 0x800A67E4: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800A67E8: jal         0x800B4EA8
    // 0x800A67EC: sw          $t5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r13;
    gettilesizy(rdram, ctx);
        goto after_0;
    // 0x800A67EC: sw          $t5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r13;
    after_0:
    // 0x800A67F0: lw          $t6, 0x78($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A67F4: addiu       $at, $zero, 0x938
    ctx->r1 = ADD32(0, 0X938);
    // 0x800A67F8: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A67FC: lbu         $t8, 0x28($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X28);
    // 0x800A6800: lw          $t7, 0x8($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X8));
    // 0x800A6804: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6808: mflo        $t9
    ctx->r25 = lo;
    // 0x800A680C: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x800A6810: subu        $v1, $t7, $t2
    ctx->r3 = SUB32(ctx->r15, ctx->r10);
    // 0x800A6814: addiu       $v1, $v1, 0x400
    ctx->r3 = ADD32(ctx->r3, 0X400);
    // 0x800A6818: sw          $v1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r3;
    // 0x800A681C: lh          $t3, 0xE($t6)
    ctx->r11 = S32(MEM_H(ctx->r14, 0XE));
    // 0x800A6820: beq         $t3, $at, L_800A68A0
    if (ctx->r11 == ctx->r1) {
        // 0x800A6824: addiu       $v1, $v1, -0x700
        ctx->r3 = ADD32(ctx->r3, -0X700);
            goto L_800A68A0;
    }
    // 0x800A6824: addiu       $v1, $v1, -0x700
    ctx->r3 = ADD32(ctx->r3, -0X700);
    // 0x800A6828: sw          $v1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r3;
    // 0x800A682C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800A6830: jal         0x80099ED4
    // 0x800A6834: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    badguy(rdram, ctx);
        goto after_1;
    // 0x800A6834: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_1:
    // 0x800A6838: beq         $v0, $zero, L_800A68A0
    if (ctx->r2 == 0) {
        // 0x800A683C: lw          $t0, 0xB0($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
            goto L_800A68A0;
    }
    // 0x800A683C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A6840: lw          $t4, 0x78($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A6844: addiu       $t9, $s3, 0x460
    ctx->r25 = ADD32(ctx->r19, 0X460);
    // 0x800A6848: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x800A684C: lh          $t5, 0xE($t4)
    ctx->r13 = S32(MEM_H(ctx->r12, 0XE));
    // 0x800A6850: andi        $t7, $t9, 0x7FF
    ctx->r15 = ctx->r25 & 0X7FF;
    // 0x800A6854: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x800A6858: beq         $t5, $at, L_800A68A0
    if (ctx->r13 == ctx->r1) {
        // 0x800A685C: lw          $t8, 0xC0($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0XC0));
            goto L_800A68A0;
    }
    // 0x800A685C: lw          $t8, 0xC0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A6860: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x800A6864: addiu       $t3, $t3, -0x9A0
    ctx->r11 = ADD32(ctx->r11, -0X9A0);
    // 0x800A6868: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x800A686C: lh          $t4, 0x0($t6)
    ctx->r12 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800A6870: addiu       $t2, $s3, 0x260
    ctx->r10 = ADD32(ctx->r19, 0X260);
    // 0x800A6874: andi        $t6, $t2, 0x7FF
    ctx->r14 = ctx->r10 & 0X7FF;
    // 0x800A6878: sra         $t5, $t4, 7
    ctx->r13 = S32(SIGNED(ctx->r12) >> 7);
    // 0x800A687C: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800A6880: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x800A6884: sw          $t9, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r25;
    // 0x800A6888: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x800A688C: lh          $t5, 0x0($t8)
    ctx->r13 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800A6890: lw          $t7, 0xBC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A6894: sra         $t9, $t5, 7
    ctx->r25 = S32(SIGNED(ctx->r13) >> 7);
    // 0x800A6898: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x800A689C: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
L_800A68A0:
    // 0x800A68A0: slti        $at, $s4, 0x8FC
    ctx->r1 = SIGNED(ctx->r20) < 0X8FC ? 1 : 0;
    // 0x800A68A4: lh          $t1, 0xCA($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A68A8: bne         $at, $zero, L_800A6950
    if (ctx->r1 != 0) {
        // 0x800A68AC: lw          $s1, 0x78($sp)
        ctx->r17 = S32(MEM_W(ctx->r29, 0X78));
            goto L_800A6950;
    }
    // 0x800A68AC: lw          $s1, 0x78($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A68B0: slti        $at, $s4, 0x9FD
    ctx->r1 = SIGNED(ctx->r20) < 0X9FD ? 1 : 0;
    // 0x800A68B4: bne         $at, $zero, L_800A691C
    if (ctx->r1 != 0) {
        // 0x800A68B8: slti        $at, $s4, 0xA36
        ctx->r1 = SIGNED(ctx->r20) < 0XA36 ? 1 : 0;
            goto L_800A691C;
    }
    // 0x800A68B8: slti        $at, $s4, 0xA36
    ctx->r1 = SIGNED(ctx->r20) < 0XA36 ? 1 : 0;
    // 0x800A68BC: bne         $at, $zero, L_800A68DC
    if (ctx->r1 != 0) {
        // 0x800A68C0: addiu       $at, $zero, 0xE32
        ctx->r1 = ADD32(0, 0XE32);
            goto L_800A68DC;
    }
    // 0x800A68C0: addiu       $at, $zero, 0xE32
    ctx->r1 = ADD32(0, 0XE32);
    // 0x800A68C4: beq         $s4, $at, L_800A9B08
    if (ctx->r20 == ctx->r1) {
        // 0x800A68C8: addiu       $at, $zero, 0xF01
        ctx->r1 = ADD32(0, 0XF01);
            goto L_800A9B08;
    }
    // 0x800A68C8: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    // 0x800A68CC: beql        $s4, $at, L_800A85C8
    if (ctx->r20 == ctx->r1) {
        // 0x800A68D0: lw          $t4, 0xB8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
            goto L_800A85C8;
    }
    goto skip_0;
    // 0x800A68D0: lw          $t4, 0xB8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
    skip_0:
    // 0x800A68D4: b           L_800A9D2C
    // 0x800A68D8: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A68D8: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A68DC:
    // 0x800A68DC: slti        $at, $s4, 0xA04
    ctx->r1 = SIGNED(ctx->r20) < 0XA04 ? 1 : 0;
    // 0x800A68E0: bne         $at, $zero, L_800A6908
    if (ctx->r1 != 0) {
        // 0x800A68E4: addiu       $t6, $s4, -0xA23
        ctx->r14 = ADD32(ctx->r20, -0XA23);
            goto L_800A6908;
    }
    // 0x800A68E4: addiu       $t6, $s4, -0xA23
    ctx->r14 = ADD32(ctx->r20, -0XA23);
    // 0x800A68E8: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x800A68EC: beq         $at, $zero, L_800A9D28
    if (ctx->r1 == 0) {
        // 0x800A68F0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A9D28;
    }
    // 0x800A68F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A68F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800A68F8: addu        $at, $at, $t6
    gpr jr_addend_800A6900 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A68FC: lw          $t6, -0x7ED0($at)
    ctx->r14 = ADD32(ctx->r1, -0X7ED0);
    // 0x800A6900: jr          $t6
    // 0x800A6904: nop

    switch (jr_addend_800A6900 >> 2) {
        case 0: goto L_800A7278; break;
        case 1: goto L_800A7278; break;
        case 2: goto L_800A7278; break;
        case 3: goto L_800A7278; break;
        case 4: goto L_800A7278; break;
        case 5: goto L_800A9D28; break;
        case 6: goto L_800A9D28; break;
        case 7: goto L_800A9D28; break;
        case 8: goto L_800A9D28; break;
        case 9: goto L_800A9D28; break;
        case 10: goto L_800A85D0; break;
        case 11: goto L_800A85D0; break;
        case 12: goto L_800A9D28; break;
        case 13: goto L_800A9D28; break;
        case 14: goto L_800A9D28; break;
        case 15: goto L_800A9D28; break;
        case 16: goto L_800A9D28; break;
        case 17: goto L_800A9D28; break;
        case 18: goto L_800A7278; break;
        default: switch_error(__func__, 0x800A6900, 0x80108130);
    }
    // 0x800A6904: nop

L_800A6908:
    // 0x800A6908: addiu       $at, $zero, 0xA03
    ctx->r1 = ADD32(0, 0XA03);
    // 0x800A690C: beq         $s4, $at, L_800A8ECC
    if (ctx->r20 == ctx->r1) {
        // 0x800A6910: sll         $t7, $t1, 3
        ctx->r15 = S32(ctx->r9 << 3);
            goto L_800A8ECC;
    }
    // 0x800A6910: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x800A6914: b           L_800A9D2C
    // 0x800A6918: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A6918: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A691C:
    // 0x800A691C: addiu       $at, $zero, 0x990
    ctx->r1 = ADD32(0, 0X990);
    // 0x800A6920: beq         $s4, $at, L_800A9310
    if (ctx->r20 == ctx->r1) {
        // 0x800A6924: addiu       $at, $zero, 0x9D9
        ctx->r1 = ADD32(0, 0X9D9);
            goto L_800A9310;
    }
    // 0x800A6924: addiu       $at, $zero, 0x9D9
    ctx->r1 = ADD32(0, 0X9D9);
    // 0x800A6928: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A692C: beq         $s4, $at, L_800A6A18
    if (ctx->r20 == ctx->r1) {
        // 0x800A6930: sw          $s1, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r17;
            goto L_800A6A18;
    }
    // 0x800A6930: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    // 0x800A6934: addiu       $at, $zero, 0x9E8
    ctx->r1 = ADD32(0, 0X9E8);
    // 0x800A6938: beq         $s4, $at, L_800A7278
    if (ctx->r20 == ctx->r1) {
        // 0x800A693C: addiu       $at, $zero, 0x9FC
        ctx->r1 = ADD32(0, 0X9FC);
            goto L_800A7278;
    }
    // 0x800A693C: addiu       $at, $zero, 0x9FC
    ctx->r1 = ADD32(0, 0X9FC);
    // 0x800A6940: beql        $s4, $at, L_800A9830
    if (ctx->r20 == ctx->r1) {
        // 0x800A6944: lh          $t8, 0x22($s1)
        ctx->r24 = S32(MEM_H(ctx->r17, 0X22));
            goto L_800A9830;
    }
    goto skip_1;
    // 0x800A6944: lh          $t8, 0x22($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, 0X22));
    skip_1:
    // 0x800A6948: b           L_800A9D2C
    // 0x800A694C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A694C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A6950:
    // 0x800A6950: slti        $at, $s4, 0x673
    ctx->r1 = SIGNED(ctx->r20) < 0X673 ? 1 : 0;
    // 0x800A6954: bne         $at, $zero, L_800A6984
    if (ctx->r1 != 0) {
        // 0x800A6958: addiu       $at, $zero, 0x8F8
        ctx->r1 = ADD32(0, 0X8F8);
            goto L_800A6984;
    }
    // 0x800A6958: addiu       $at, $zero, 0x8F8
    ctx->r1 = ADD32(0, 0X8F8);
    // 0x800A695C: beq         $s4, $at, L_800A69B8
    if (ctx->r20 == ctx->r1) {
        // 0x800A6960: addiu       $at, $zero, 0x8F9
        ctx->r1 = ADD32(0, 0X8F9);
            goto L_800A69B8;
    }
    // 0x800A6960: addiu       $at, $zero, 0x8F9
    ctx->r1 = ADD32(0, 0X8F9);
    // 0x800A6964: beq         $s4, $at, L_800A69B8
    if (ctx->r20 == ctx->r1) {
        // 0x800A6968: addiu       $at, $zero, 0x8FA
        ctx->r1 = ADD32(0, 0X8FA);
            goto L_800A69B8;
    }
    // 0x800A6968: addiu       $at, $zero, 0x8FA
    ctx->r1 = ADD32(0, 0X8FA);
    // 0x800A696C: beq         $s4, $at, L_800A69B8
    if (ctx->r20 == ctx->r1) {
        // 0x800A6970: addiu       $at, $zero, 0x8FB
        ctx->r1 = ADD32(0, 0X8FB);
            goto L_800A69B8;
    }
    // 0x800A6970: addiu       $at, $zero, 0x8FB
    ctx->r1 = ADD32(0, 0X8FB);
    // 0x800A6974: beq         $s4, $at, L_800A69B8
    if (ctx->r20 == ctx->r1) {
        // 0x800A6978: nop
    
            goto L_800A69B8;
    }
    // 0x800A6978: nop

    // 0x800A697C: b           L_800A9D2C
    // 0x800A6980: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A6980: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A6984:
    // 0x800A6984: addiu       $at, $zero, 0x3AC
    ctx->r1 = ADD32(0, 0X3AC);
    // 0x800A6988: beq         $s4, $at, L_800A91F8
    if (ctx->r20 == ctx->r1) {
        // 0x800A698C: addiu       $v1, $zero, 0x550
        ctx->r3 = ADD32(0, 0X550);
            goto L_800A91F8;
    }
    // 0x800A698C: addiu       $v1, $zero, 0x550
    ctx->r3 = ADD32(0, 0X550);
    // 0x800A6990: beq         $s4, $v1, L_800A8174
    if (ctx->r20 == ctx->r3) {
        // 0x800A6994: addiu       $at, $zero, 0x659
        ctx->r1 = ADD32(0, 0X659);
            goto L_800A8174;
    }
    // 0x800A6994: addiu       $at, $zero, 0x659
    ctx->r1 = ADD32(0, 0X659);
    // 0x800A6998: beq         $s4, $at, L_800A8174
    if (ctx->r20 == ctx->r1) {
        // 0x800A699C: addiu       $at, $zero, 0x664
        ctx->r1 = ADD32(0, 0X664);
            goto L_800A8174;
    }
    // 0x800A699C: addiu       $at, $zero, 0x664
    ctx->r1 = ADD32(0, 0X664);
    // 0x800A69A0: beq         $s4, $at, L_800A8174
    if (ctx->r20 == ctx->r1) {
        // 0x800A69A4: addiu       $at, $zero, 0x672
        ctx->r1 = ADD32(0, 0X672);
            goto L_800A8174;
    }
    // 0x800A69A4: addiu       $at, $zero, 0x672
    ctx->r1 = ADD32(0, 0X672);
    // 0x800A69A8: beql        $s4, $at, L_800A91FC
    if (ctx->r20 == ctx->r1) {
        // 0x800A69AC: lh          $t2, 0x22($s1)
        ctx->r10 = S32(MEM_H(ctx->r17, 0X22));
            goto L_800A91FC;
    }
    goto skip_2;
    // 0x800A69AC: lh          $t2, 0x22($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, 0X22));
    skip_2:
    // 0x800A69B0: b           L_800A9D2C
    // 0x800A69B4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A69B4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A69B8:
    // 0x800A69B8: bltzl       $t1, L_800A69E8
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A69BC: sh          $t1, 0xCA($sp)
        MEM_H(0XCA, ctx->r29) = ctx->r9;
            goto L_800A69E8;
    }
    goto skip_3;
    // 0x800A69BC: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    skip_3:
    // 0x800A69C0: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A69C4: jal         0x8009800C
    // 0x800A69C8: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    krand2(rdram, ctx);
        goto after_2;
    // 0x800A69C8: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_2:
    // 0x800A69CC: andi        $t4, $v0, 0x7F
    ctx->r12 = ctx->r2 & 0X7F;
    // 0x800A69D0: subu        $s3, $s3, $t4
    ctx->r19 = SUB32(ctx->r19, ctx->r12);
    // 0x800A69D4: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // 0x800A69D8: sll         $t3, $s3, 16
    ctx->r11 = S32(ctx->r19 << 16);
    // 0x800A69DC: b           L_800A6A04
    // 0x800A69E0: sra         $s3, $t3, 16
    ctx->r19 = S32(SIGNED(ctx->r11) >> 16);
        goto L_800A6A04;
    // 0x800A69E0: sra         $s3, $t3, 16
    ctx->r19 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800A69E4: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
L_800A69E8:
    // 0x800A69E8: jal         0x8009800C
    // 0x800A69EC: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    krand2(rdram, ctx);
        goto after_3;
    // 0x800A69EC: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_3:
    // 0x800A69F0: andi        $t5, $v0, 0x7F
    ctx->r13 = ctx->r2 & 0X7F;
    // 0x800A69F4: subu        $s3, $s3, $t5
    ctx->r19 = SUB32(ctx->r19, ctx->r13);
    // 0x800A69F8: addiu       $s3, $s3, 0x440
    ctx->r19 = ADD32(ctx->r19, 0X440);
    // 0x800A69FC: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800A6A00: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_800A6A04:
    // 0x800A6A04: jal         0x8009800C
    // 0x800A6A08: nop

    krand2(rdram, ctx);
        goto after_4;
    // 0x800A6A08: nop

    after_4:
    // 0x800A6A0C: andi        $t2, $v0, 0x7FF
    ctx->r10 = ctx->r2 & 0X7FF;
    // 0x800A6A10: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800A6A14: subu        $t0, $t6, $t2
    ctx->r8 = SUB32(ctx->r14, ctx->r10);
L_800A6A18:
    // 0x800A6A18: addiu       $at, $zero, 0x9D9
    ctx->r1 = ADD32(0, 0X9D9);
    // 0x800A6A1C: lh          $t1, 0xCA($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A6A20: bne         $s4, $at, L_800A6B50
    if (ctx->r20 != ctx->r1) {
        // 0x800A6A24: lw          $s1, 0x78($sp)
        ctx->r17 = S32(MEM_W(ctx->r29, 0X78));
            goto L_800A6B50;
    }
    // 0x800A6A24: lw          $s1, 0x78($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A6A28: bltz        $t1, L_800A6A94
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A6A2C: sll         $t4, $t1, 3
        ctx->r12 = S32(ctx->r9 << 3);
            goto L_800A6A94;
    }
    // 0x800A6A2C: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x800A6A30: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800A6A34: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800A6A38: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x800A6A3C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A6A40: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x800A6A44: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x800A6A48: addiu       $t3, $t3, 0x5770
    ctx->r11 = ADD32(ctx->r11, 0X5770);
    // 0x800A6A4C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A6A50: addu        $s0, $t4, $t3
    ctx->r16 = ADD32(ctx->r12, ctx->r11);
    // 0x800A6A54: lw          $t8, 0x220($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A6A58: lh          $t7, 0x2B8($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A6A5C: lw          $t6, 0xB8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A6A60: negu        $t5, $t8
    ctx->r13 = SUB32(0, ctx->r24);
    // 0x800A6A64: subu        $t0, $t5, $t7
    ctx->r8 = SUB32(ctx->r13, ctx->r15);
    // 0x800A6A68: addiu       $t0, $t0, 0x64
    ctx->r8 = ADD32(ctx->r8, 0X64);
    // 0x800A6A6C: addiu       $s3, $s3, 0xF
    ctx->r19 = ADD32(ctx->r19, 0XF);
    // 0x800A6A70: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x800A6A74: sll         $t4, $s3, 16
    ctx->r12 = S32(ctx->r19 << 16);
    // 0x800A6A78: addiu       $t2, $t6, 0x600
    ctx->r10 = ADD32(ctx->r14, 0X600);
    // 0x800A6A7C: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x800A6A80: sw          $t2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r10;
    // 0x800A6A84: sra         $s3, $t4, 16
    ctx->r19 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800A6A88: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A6A8C: b           L_800A6B50
    // 0x800A6A90: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
        goto L_800A6B50;
    // 0x800A6A90: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
L_800A6A94:
    // 0x800A6A94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A6A98: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x800A6A9C: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A6AA0: jal         0x800ACF18
    // 0x800A6AA4: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    findplayer(rdram, ctx);
        goto after_5;
    // 0x800A6AA4: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_5:
    // 0x800A6AA8: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800A6AAC: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800A6AB0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800A6AB4: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800A6AB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A6ABC: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800A6AC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A6AC4: lui         $s1, 0x802A
    ctx->r17 = S32(0X802A << 16);
    // 0x800A6AC8: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
    // 0x800A6ACC: lh          $s1, 0x5A50($s1)
    ctx->r17 = S32(MEM_H(ctx->r17, 0X5A50));
    // 0x800A6AD0: lw          $t9, 0xB8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A6AD4: lw          $t1, 0xA0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800A6AD8: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6ADC: lw          $t8, 0xC0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A6AE0: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x800A6AE4: mflo        $t5
    ctx->r13 = lo;
    // 0x800A6AE8: addu        $a2, $s5, $t5
    ctx->r6 = ADD32(ctx->r21, ctx->r13);
    // 0x800A6AEC: lw          $t7, 0x8($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800A6AF0: lw          $t3, 0x0($a2)
    ctx->r11 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A6AF4: lw          $t5, 0x4($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A6AF8: subu        $t6, $t7, $t9
    ctx->r14 = SUB32(ctx->r15, ctx->r25);
    // 0x800A6AFC: sll         $t2, $t6, 8
    ctx->r10 = S32(ctx->r14 << 8);
    // 0x800A6B00: div         $zero, $t2, $t4
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r12)));
    // 0x800A6B04: lw          $t7, 0xBC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A6B08: mflo        $t0
    ctx->r8 = lo;
    // 0x800A6B0C: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A6B10: bne         $t4, $zero, L_800A6B1C
    if (ctx->r12 != 0) {
        // 0x800A6B14: nop
    
            goto L_800A6B1C;
    }
    // 0x800A6B14: nop

    // 0x800A6B18: break       7
    do_break(2148166424);
L_800A6B1C:
    // 0x800A6B1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A6B20: bne         $t4, $at, L_800A6B34
    if (ctx->r12 != ctx->r1) {
        // 0x800A6B24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A6B34;
    }
    // 0x800A6B24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A6B28: bne         $t2, $at, L_800A6B34
    if (ctx->r10 != ctx->r1) {
        // 0x800A6B2C: nop
    
            goto L_800A6B34;
    }
    // 0x800A6B2C: nop

    // 0x800A6B30: break       6
    do_break(2148166448);
L_800A6B34:
    // 0x800A6B34: subu        $a0, $t3, $t8
    ctx->r4 = SUB32(ctx->r11, ctx->r24);
    // 0x800A6B38: jal         0x80092024
    // 0x800A6B3C: subu        $a1, $t5, $t7
    ctx->r5 = SUB32(ctx->r13, ctx->r15);
    getangle(rdram, ctx);
        goto after_6;
    // 0x800A6B3C: subu        $a1, $t5, $t7
    ctx->r5 = SUB32(ctx->r13, ctx->r15);
    after_6:
    // 0x800A6B40: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800A6B44: sra         $t9, $s3, 16
    ctx->r25 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800A6B48: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x800A6B4C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A6B50:
    // 0x800A6B50: addiu       $t6, $s3, 0x200
    ctx->r14 = ADD32(ctx->r19, 0X200);
    // 0x800A6B54: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800A6B58: andi        $t2, $t6, 0x7FF
    ctx->r10 = ctx->r14 & 0X7FF;
    // 0x800A6B5C: addiu       $v0, $v0, -0x9A0
    ctx->r2 = ADD32(ctx->r2, -0X9A0);
    // 0x800A6B60: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x800A6B64: andi        $t5, $s3, 0x7FF
    ctx->r13 = ctx->r19 & 0X7FF;
    // 0x800A6B68: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800A6B6C: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x800A6B70: lh          $t8, 0x0($t3)
    ctx->r24 = S32(MEM_H(ctx->r11, 0X0));
    // 0x800A6B74: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x800A6B78: lh          $t6, 0x0($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800A6B7C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A6B80: addiu       $t8, $sp, 0xD2
    ctx->r24 = ADD32(ctx->r29, 0XD2);
    // 0x800A6B84: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A6B88: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x800A6B8C: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x800A6B90: addiu       $t9, $sp, 0xA4
    ctx->r25 = ADD32(ctx->r29, 0XA4);
    // 0x800A6B94: addiu       $t7, $sp, 0xA8
    ctx->r15 = ADD32(ctx->r29, 0XA8);
    // 0x800A6B98: addiu       $t3, $sp, 0xD0
    ctx->r11 = ADD32(ctx->r29, 0XD0);
    // 0x800A6B9C: addiu       $t4, $sp, 0xD4
    ctx->r12 = ADD32(ctx->r29, 0XD4);
    // 0x800A6BA0: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800A6BA4: sll         $t2, $t0, 6
    ctx->r10 = S32(ctx->r8 << 6);
    // 0x800A6BA8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A6BAC: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800A6BB0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A6BB4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800A6BB8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800A6BBC: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A6BC0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800A6BC4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800A6BC8: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A6BCC: lw          $a0, 0xC0($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A6BD0: lw          $a1, 0xBC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A6BD4: lw          $a2, 0xB8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A6BD8: jal         0x8009324C
    // 0x800A6BDC: lh          $a3, 0xD6($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD6));
    hitscan(rdram, ctx);
        goto after_7;
    // 0x800A6BDC: lh          $a3, 0xD6($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD6));
    after_7:
    // 0x800A6BE0: addiu       $at, $zero, 0x8F8
    ctx->r1 = ADD32(0, 0X8F8);
    // 0x800A6BE4: beq         $s4, $at, L_800A6C08
    if (ctx->r20 == ctx->r1) {
        // 0x800A6BE8: lw          $t0, 0xB0($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
            goto L_800A6C08;
    }
    // 0x800A6BE8: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A6BEC: addiu       $at, $zero, 0x8FA
    ctx->r1 = ADD32(0, 0X8FA);
    // 0x800A6BF0: beq         $s4, $at, L_800A6C08
    if (ctx->r20 == ctx->r1) {
        // 0x800A6BF4: addiu       $at, $zero, 0x8F9
        ctx->r1 = ADD32(0, 0X8F9);
            goto L_800A6C08;
    }
    // 0x800A6BF4: addiu       $at, $zero, 0x8F9
    ctx->r1 = ADD32(0, 0X8F9);
    // 0x800A6BF8: beq         $s4, $at, L_800A6C08
    if (ctx->r20 == ctx->r1) {
        // 0x800A6BFC: addiu       $at, $zero, 0x8FB
        ctx->r1 = ADD32(0, 0X8FB);
            goto L_800A6C08;
    }
    // 0x800A6BFC: addiu       $at, $zero, 0x8FB
    ctx->r1 = ADD32(0, 0X8FB);
    // 0x800A6C00: bne         $s4, $at, L_800A6F04
    if (ctx->r20 != ctx->r1) {
        // 0x800A6C04: lh          $s2, 0xD4($sp)
        ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
            goto L_800A6F04;
    }
    // 0x800A6C04: lh          $s2, 0xD4($sp)
    ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
L_800A6C08:
    // 0x800A6C08: lw          $t2, 0xC0($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A6C0C: lw          $t4, 0xAC($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A6C10: lw          $t3, 0xBC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A6C14: lw          $t8, 0xA8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A6C18: subu        $a0, $t2, $t4
    ctx->r4 = SUB32(ctx->r10, ctx->r12);
    // 0x800A6C1C: jal         0x800993E0
    // 0x800A6C20: subu        $a1, $t3, $t8
    ctx->r5 = SUB32(ctx->r11, ctx->r24);
    FindDistance2D(rdram, ctx);
        goto after_8;
    // 0x800A6C20: subu        $a1, $t3, $t8
    ctx->r5 = SUB32(ctx->r11, ctx->r24);
    after_8:
    // 0x800A6C24: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x800A6C28: beq         $at, $zero, L_800A9D28
    if (ctx->r1 == 0) {
        // 0x800A6C2C: lh          $t5, 0xD0($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A9D28;
    }
    // 0x800A6C2C: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A6C30: bltz        $t5, L_800A9D28
    if (SIGNED(ctx->r13) < 0) {
        // 0x800A6C34: sll         $t7, $t5, 3
        ctx->r15 = S32(ctx->r13 << 3);
            goto L_800A9D28;
    }
    // 0x800A6C34: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800A6C38: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800A6C3C: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800A6C40: addiu       $t9, $t9, 0x61A8
    ctx->r25 = ADD32(ctx->r25, 0X61A8);
    // 0x800A6C44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6C48: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    // 0x800A6C4C: lh          $t6, 0x12($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0X12));
    // 0x800A6C50: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x800A6C54: beql        $t6, $at, L_800A9D2C
    if (ctx->r14 == ctx->r1) {
        // 0x800A6C58: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_4;
    // 0x800A6C58: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_4:
    // 0x800A6C5C: lh          $v0, 0xC($a2)
    ctx->r2 = S32(MEM_H(ctx->r6, 0XC));
    // 0x800A6C60: lh          $s2, 0xD4($sp)
    ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A6C64: bltzl       $v0, L_800A6CD4
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A6C68: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A6CD4;
    }
    goto skip_5;
    // 0x800A6C68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_5:
    // 0x800A6C6C: bltz        $s2, L_800A6CD0
    if (SIGNED(ctx->r18) < 0) {
        // 0x800A6C70: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_800A6CD0;
    }
    // 0x800A6C70: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800A6C74: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800A6C78: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800A6C7C: addiu       $t4, $t4, -0x1988
    ctx->r12 = ADD32(ctx->r12, -0X1988);
    // 0x800A6C80: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800A6C84: addu        $v1, $t2, $t4
    ctx->r3 = ADD32(ctx->r10, ctx->r12);
    // 0x800A6C88: lh          $a1, 0x18($v1)
    ctx->r5 = S32(MEM_H(ctx->r3, 0X18));
    // 0x800A6C8C: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x800A6C90: subu        $t3, $t3, $s2
    ctx->r11 = SUB32(ctx->r11, ctx->r18);
    // 0x800A6C94: bne         $a1, $zero, L_800A6CD0
    if (ctx->r5 != 0) {
        // 0x800A6C98: sll         $t3, $t3, 4
        ctx->r11 = S32(ctx->r11 << 4);
            goto L_800A6CD0;
    }
    // 0x800A6C98: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800A6C9C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800A6CA0: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x800A6CA4: addu        $a0, $t3, $t8
    ctx->r4 = ADD32(ctx->r11, ctx->r24);
    // 0x800A6CA8: lh          $t5, 0x18($a0)
    ctx->r13 = S32(MEM_H(ctx->r4, 0X18));
    // 0x800A6CAC: bnel        $t5, $zero, L_800A6CD4
    if (ctx->r13 != 0) {
        // 0x800A6CB0: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A6CD4;
    }
    goto skip_6;
    // 0x800A6CB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_6:
    // 0x800A6CB4: bnel        $a1, $zero, L_800A6CD4
    if (ctx->r5 != 0) {
        // 0x800A6CB8: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A6CD4;
    }
    goto skip_7;
    // 0x800A6CB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_7:
    // 0x800A6CBC: lw          $t7, 0x4($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800A6CC0: lw          $t9, 0x4($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800A6CC4: subu        $t6, $t7, $t9
    ctx->r14 = SUB32(ctx->r15, ctx->r25);
    // 0x800A6CC8: slti        $at, $t6, 0x1001
    ctx->r1 = SIGNED(ctx->r14) < 0X1001 ? 1 : 0;
    // 0x800A6CCC: beq         $at, $zero, L_800A6CFC
    if (ctx->r1 == 0) {
        // 0x800A6CD0: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A6CFC;
    }
L_800A6CD0:
    // 0x800A6CD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_800A6CD4:
    // 0x800A6CD4: bne         $v0, $at, L_800A9D28
    if (ctx->r2 != ctx->r1) {
        // 0x800A6CD8: lh          $s2, 0xD4($sp)
        ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
            goto L_800A9D28;
    }
    // 0x800A6CD8: lh          $s2, 0xD4($sp)
    ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A6CDC: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x800A6CE0: subu        $t2, $t2, $s2
    ctx->r10 = SUB32(ctx->r10, ctx->r18);
    // 0x800A6CE4: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800A6CE8: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800A6CEC: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800A6CF0: lh          $t4, -0x1970($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X1970));
    // 0x800A6CF4: bnel        $t4, $zero, L_800A9D2C
    if (ctx->r12 != 0) {
        // 0x800A6CF8: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_8;
    // 0x800A6CF8: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_8:
L_800A6CFC:
    // 0x800A6CFC: lh          $t3, 0xE($a2)
    ctx->r11 = S32(MEM_H(ctx->r6, 0XE));
    // 0x800A6D00: andi        $t8, $t3, 0x10
    ctx->r24 = ctx->r11 & 0X10;
    // 0x800A6D04: bnel        $t8, $zero, L_800A9D2C
    if (ctx->r24 != 0) {
        // 0x800A6D08: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_9;
    // 0x800A6D08: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_9:
    // 0x800A6D0C: bltz        $v0, L_800A6D6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A6D10: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_800A6D6C;
    }
    // 0x800A6D10: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x800A6D14: lui         $s2, 0x8027
    ctx->r18 = S32(0X8027 << 16);
    // 0x800A6D18: addu        $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
    // 0x800A6D1C: lh          $s2, 0x2330($s2)
    ctx->r18 = S32(MEM_H(ctx->r18, 0X2330));
    // 0x800A6D20: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800A6D24: addiu       $v1, $v1, 0x4FA0
    ctx->r3 = ADD32(ctx->r3, 0X4FA0);
    // 0x800A6D28: bltz        $s2, L_800A6D6C
    if (SIGNED(ctx->r18) < 0) {
        // 0x800A6D2C: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_800A6D6C;
    }
    // 0x800A6D2C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_800A6D30:
    // 0x800A6D30: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6D34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A6D38: sll         $t2, $s2, 1
    ctx->r10 = S32(ctx->r18 << 1);
    // 0x800A6D3C: addu        $t4, $v1, $t2
    ctx->r12 = ADD32(ctx->r3, ctx->r10);
    // 0x800A6D40: mflo        $t7
    ctx->r15 = lo;
    // 0x800A6D44: addu        $s1, $s5, $t7
    ctx->r17 = ADD32(ctx->r21, ctx->r15);
    // 0x800A6D48: lh          $t9, 0x12($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X12));
    // 0x800A6D4C: bnel        $t9, $at, L_800A6D64
    if (ctx->r25 != ctx->r1) {
        // 0x800A6D50: lh          $s2, 0x0($t4)
        ctx->r18 = S32(MEM_H(ctx->r12, 0X0));
            goto L_800A6D64;
    }
    goto skip_10;
    // 0x800A6D50: lh          $s2, 0x0($t4)
    ctx->r18 = S32(MEM_H(ctx->r12, 0X0));
    skip_10:
    // 0x800A6D54: lh          $t6, 0x1E($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, 0X1E));
    // 0x800A6D58: beql        $v0, $t6, L_800A9D2C
    if (ctx->r2 == ctx->r14) {
        // 0x800A6D5C: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_11;
    // 0x800A6D5C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_11:
    // 0x800A6D60: lh          $s2, 0x0($t4)
    ctx->r18 = S32(MEM_H(ctx->r12, 0X0));
L_800A6D64:
    // 0x800A6D64: bgez        $s2, L_800A6D30
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800A6D68: nop
    
            goto L_800A6D30;
    }
    // 0x800A6D68: nop

L_800A6D6C:
    // 0x800A6D6C: lh          $v0, 0xA($a2)
    ctx->r2 = S32(MEM_H(ctx->r6, 0XA));
    // 0x800A6D70: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800A6D74: bltz        $v0, L_800A6D94
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A6D78: sll         $t3, $v0, 3
        ctx->r11 = S32(ctx->r2 << 3);
            goto L_800A6D94;
    }
    // 0x800A6D78: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x800A6D7C: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x800A6D80: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A6D84: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x800A6D88: lh          $t8, 0x61BE($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X61BE));
    // 0x800A6D8C: bnel        $t8, $zero, L_800A9D2C
    if (ctx->r24 != 0) {
        // 0x800A6D90: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_12;
    // 0x800A6D90: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_12:
L_800A6D94:
    // 0x800A6D94: lh          $t5, 0x16($a2)
    ctx->r13 = S32(MEM_H(ctx->r6, 0X16));
    // 0x800A6D98: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x800A6D9C: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A6DA0: bne         $t5, $zero, L_800A9D28
    if (ctx->r13 != 0) {
        // 0x800A6DA4: lh          $a0, 0xDA($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XDA));
            goto L_800A9D28;
    }
    // 0x800A6DA4: lh          $a0, 0xDA($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A6DA8: jal         0x8009D240
    // 0x800A6DAC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    spawn(rdram, ctx);
        goto after_9;
    // 0x800A6DAC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_9:
    // 0x800A6DB0: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6DB4: addiu       $t6, $zero, -0xC
    ctx->r14 = ADD32(0, -0XC);
    // 0x800A6DB8: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800A6DBC: addiu       $t5, $t5, 0x61A8
    ctx->r13 = ADD32(ctx->r13, 0X61A8);
    // 0x800A6DC0: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800A6DC4: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800A6DC8: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800A6DCC: mflo        $t2
    ctx->r10 = lo;
    // 0x800A6DD0: addu        $t4, $s5, $t2
    ctx->r12 = ADD32(ctx->r21, ctx->r10);
    // 0x800A6DD4: sh          $t6, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r14;
    // 0x800A6DD8: lh          $t3, 0xD0($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A6DDC: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x800A6DE0: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x800A6DE4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A6DE8: addu        $a2, $t8, $t5
    ctx->r6 = ADD32(ctx->r24, ctx->r13);
    // 0x800A6DEC: lh          $t7, 0x8($a2)
    ctx->r15 = S32(MEM_H(ctx->r6, 0X8));
    // 0x800A6DF0: lw          $t2, 0x0($a2)
    ctx->r10 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A6DF4: lw          $t4, 0x4($a2)
    ctx->r12 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A6DF8: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800A6DFC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800A6E00: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6E04: addu        $v1, $t9, $t5
    ctx->r3 = ADD32(ctx->r25, ctx->r13);
    // 0x800A6E08: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800A6E0C: lw          $t3, 0x4($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800A6E10: subu        $a0, $t2, $t6
    ctx->r4 = SUB32(ctx->r10, ctx->r14);
    // 0x800A6E14: jal         0x80092024
    // 0x800A6E18: subu        $a1, $t4, $t3
    ctx->r5 = SUB32(ctx->r12, ctx->r11);
    getangle(rdram, ctx);
        goto after_10;
    // 0x800A6E18: subu        $a1, $t4, $t3
    ctx->r5 = SUB32(ctx->r12, ctx->r11);
    after_10:
    // 0x800A6E1C: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6E20: addiu       $t7, $v0, 0x200
    ctx->r15 = ADD32(ctx->r2, 0X200);
    // 0x800A6E24: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800A6E28: addiu       $a0, $a0, -0x9A0
    ctx->r4 = ADD32(ctx->r4, -0X9A0);
    // 0x800A6E2C: lw          $t6, 0xA4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A6E30: lw          $t4, 0xAC($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A6E34: mflo        $t8
    ctx->r24 = lo;
    // 0x800A6E38: addu        $s1, $s5, $t8
    ctx->r17 = ADD32(ctx->r21, ctx->r24);
    // 0x800A6E3C: sh          $t7, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r15;
    // 0x800A6E40: lh          $t9, 0x14($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800A6E44: sw          $t6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r14;
    // 0x800A6E48: addiu       $t5, $t9, 0x400
    ctx->r13 = ADD32(ctx->r25, 0X400);
    // 0x800A6E4C: andi        $t2, $t5, 0x7FF
    ctx->r10 = ctx->r13 & 0X7FF;
    // 0x800A6E50: sh          $t2, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r10;
    // 0x800A6E54: lh          $v1, 0x14($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800A6E58: addiu       $t3, $v1, 0x200
    ctx->r11 = ADD32(ctx->r3, 0X200);
    // 0x800A6E5C: andi        $t8, $t3, 0x7FF
    ctx->r24 = ctx->r11 & 0X7FF;
    // 0x800A6E60: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800A6E64: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x800A6E68: lh          $t5, 0x0($t9)
    ctx->r13 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800A6E6C: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800A6E70: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x800A6E74: lh          $t9, 0x0($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800A6E78: lw          $t3, 0xA8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A6E7C: sra         $t2, $t5, 10
    ctx->r10 = S32(SIGNED(ctx->r13) >> 10);
    // 0x800A6E80: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x800A6E84: sra         $t5, $t9, 10
    ctx->r13 = S32(SIGNED(ctx->r25) >> 10);
    // 0x800A6E88: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x800A6E8C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800A6E90: jal         0x8009800C
    // 0x800A6E94: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    krand2(rdram, ctx);
        goto after_11;
    // 0x800A6E94: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    after_11:
    // 0x800A6E98: lh          $t2, 0xC($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, 0XC));
    // 0x800A6E9C: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x800A6EA0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A6EA4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A6EA8: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800A6EAC: or          $t8, $t2, $t6
    ctx->r24 = ctx->r10 | ctx->r14;
    // 0x800A6EB0: sh          $t8, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r24;
    // 0x800A6EB4: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x800A6EB8: jal         0x80076190
    // 0x800A6EBC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    ssp(rdram, ctx);
        goto after_12;
    // 0x800A6EBC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_12:
    // 0x800A6EC0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A6EC4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A6EC8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800A6ECC: lw          $a1, 0x0($s1)
    ctx->r5 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800A6ED0: lw          $a2, 0x4($s1)
    ctx->r6 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800A6ED4: jal         0x8009219C
    // 0x800A6ED8: lw          $a3, 0x8($s1)
    ctx->r7 = S32(MEM_W(ctx->r17, 0X8));
    setsprite(rdram, ctx);
        goto after_13;
    // 0x800A6ED8: lw          $a3, 0x8($s1)
    ctx->r7 = S32(MEM_W(ctx->r17, 0X8));
    after_13:
    // 0x800A6EDC: lw          $t3, 0x78($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A6EE0: addiu       $at, $zero, 0x437
    ctx->r1 = ADD32(0, 0X437);
    // 0x800A6EE4: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800A6EE8: lh          $v1, 0xE($t3)
    ctx->r3 = S32(MEM_H(ctx->r11, 0XE));
    // 0x800A6EEC: beq         $v1, $at, L_800A6EFC
    if (ctx->r3 == ctx->r1) {
        // 0x800A6EF0: addiu       $at, $zero, 0x1202
        ctx->r1 = ADD32(0, 0X1202);
            goto L_800A6EFC;
    }
    // 0x800A6EF0: addiu       $at, $zero, 0x1202
    ctx->r1 = ADD32(0, 0X1202);
    // 0x800A6EF4: bnel        $v1, $at, L_800A9D2C
    if (ctx->r3 != ctx->r1) {
        // 0x800A6EF8: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_13;
    // 0x800A6EF8: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_13:
L_800A6EFC:
    // 0x800A6EFC: b           L_800A9D28
    // 0x800A6F00: sb          $t5, 0x25($s1)
    MEM_B(0X25, ctx->r17) = ctx->r13;
        goto L_800A9D28;
    // 0x800A6F00: sb          $t5, 0x25($s1)
    MEM_B(0X25, ctx->r17) = ctx->r13;
L_800A6F04:
    // 0x800A6F04: bltz        $s2, L_800A9D28
    if (SIGNED(ctx->r18) < 0) {
        // 0x800A6F08: lw          $a1, 0xAC($sp)
        ctx->r5 = S32(MEM_W(ctx->r29, 0XAC));
            goto L_800A9D28;
    }
    // 0x800A6F08: lw          $a1, 0xAC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A6F0C: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A6F10: lw          $a2, 0xA8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A6F14: lw          $t2, 0xBC($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A6F18: subu        $v0, $t4, $a1
    ctx->r2 = SUB32(ctx->r12, ctx->r5);
    // 0x800A6F1C: blez        $v0, L_800A6F2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A6F20: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_800A6F2C;
    }
    // 0x800A6F20: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x800A6F24: b           L_800A6F2C
    // 0x800A6F28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800A6F2C;
    // 0x800A6F28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800A6F2C:
    // 0x800A6F2C: subu        $v0, $t2, $a2
    ctx->r2 = SUB32(ctx->r10, ctx->r6);
    // 0x800A6F30: blez        $v0, L_800A6F40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A6F34: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_800A6F40;
    }
    // 0x800A6F34: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x800A6F38: b           L_800A6F40
    // 0x800A6F3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800A6F40;
    // 0x800A6F3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800A6F40:
    // 0x800A6F40: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800A6F44: slti        $at, $t6, 0x400
    ctx->r1 = SIGNED(ctx->r14) < 0X400 ? 1 : 0;
    // 0x800A6F48: beq         $at, $zero, L_800A9D28
    if (ctx->r1 == 0) {
        // 0x800A6F4C: lh          $t8, 0xD0($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A9D28;
    }
    // 0x800A6F4C: lh          $t8, 0xD0($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A6F50: bgez        $t8, L_800A6F60
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A6F54: lh          $a3, 0xD2($sp)
        ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
            goto L_800A6F60;
    }
    // 0x800A6F54: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A6F58: bltz        $a3, L_800A71BC
    if (SIGNED(ctx->r7) < 0) {
        // 0x800A6F5C: lh          $t8, 0xCA($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0XCA));
            goto L_800A71BC;
    }
    // 0x800A6F5C: lh          $t8, 0xCA($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XCA));
L_800A6F60:
    // 0x800A6F60: lh          $t4, 0xDA($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A6F64: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A6F68: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A6F6C: addiu       $t9, $zero, 0x9D9
    ctx->r25 = ADD32(0, 0X9D9);
    // 0x800A6F70: addiu       $t3, $zero, -0xF
    ctx->r11 = ADD32(0, -0XF);
    // 0x800A6F74: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800A6F78: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A6F7C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A6F80: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800A6F84: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A6F88: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800A6F8C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A6F90: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A6F94: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800A6F98: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800A6F9C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A6FA0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A6FA4: jal         0x8009B028
    // 0x800A6FA8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    EGS(rdram, ctx);
        goto after_14;
    // 0x800A6FA8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_14:
    // 0x800A6FAC: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A6FB0: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A6FB4: jal         0x8009800C
    // 0x800A6FB8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    krand2(rdram, ctx);
        goto after_15;
    // 0x800A6FB8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    after_15:
    // 0x800A6FBC: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6FC0: lh          $t5, 0xCA($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A6FC4: andi        $t9, $v0, 0x7
    ctx->r25 = ctx->r2 & 0X7;
    // 0x800A6FC8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800A6FCC: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A6FD0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800A6FD4: addiu       $a1, $zero, 0x919
    ctx->r5 = ADD32(0, 0X919);
    // 0x800A6FD8: mflo        $t8
    ctx->r24 = lo;
    // 0x800A6FDC: addu        $a2, $s5, $t8
    ctx->r6 = ADD32(ctx->r21, ctx->r24);
    // 0x800A6FE0: lh          $t7, 0x22($a2)
    ctx->r15 = S32(MEM_H(ctx->r6, 0X22));
    // 0x800A6FE4: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x800A6FE8: bltz        $t5, L_800A7028
    if (SIGNED(ctx->r13) < 0) {
        // 0x800A6FEC: sh          $t3, 0x22($a2)
        MEM_H(0X22, ctx->r6) = ctx->r11;
            goto L_800A7028;
    }
    // 0x800A6FEC: sh          $t3, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r11;
    // 0x800A6FF0: jal         0x8009D240
    // 0x800A6FF4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    spawn(rdram, ctx);
        goto after_16;
    // 0x800A6FF4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_16:
    // 0x800A6FF8: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6FFC: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x800A7000: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A7004: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800A7008: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A700C: mflo        $t2
    ctx->r10 = lo;
    // 0x800A7010: addu        $v1, $s5, $t2
    ctx->r3 = ADD32(ctx->r21, ctx->r10);
    // 0x800A7014: lw          $t6, 0x8($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X8));
    // 0x800A7018: addiu       $t8, $t6, -0x800
    ctx->r24 = ADD32(ctx->r14, -0X800);
    // 0x800A701C: jal         0x80059034
    // 0x800A7020: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    spritesound(rdram, ctx);
        goto after_17;
    // 0x800A7020: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    after_17:
    // 0x800A7024: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
L_800A7028:
    // 0x800A7028: lh          $t9, 0xCA($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A702C: lui         $v0, 0x802A
    ctx->r2 = S32(0X802A << 16);
    // 0x800A7030: bltz        $t9, L_800A7074
    if (SIGNED(ctx->r25) < 0) {
        // 0x800A7034: sll         $t3, $t9, 3
        ctx->r11 = S32(ctx->r25 << 3);
            goto L_800A7074;
    }
    // 0x800A7034: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x800A7038: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x800A703C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800A7040: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x800A7044: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A7048: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x800A704C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A7050: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800A7054: lh          $v0, 0x5A90($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X5A90));
    // 0x800A7058: blez        $v0, L_800A7074
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A705C: slti        $at, $v0, 0x190
        ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
            goto L_800A7074;
    }
    // 0x800A705C: slti        $at, $v0, 0x190
    ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x800A7060: beql        $at, $zero, L_800A7078
    if (ctx->r1 == 0) {
        // 0x800A7064: lh          $a3, 0xD2($sp)
        ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
            goto L_800A7078;
    }
    goto skip_14;
    // 0x800A7064: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    skip_14:
    // 0x800A7068: lh          $t5, 0x22($a2)
    ctx->r13 = S32(MEM_H(ctx->r6, 0X22));
    // 0x800A706C: addiu       $t4, $t5, 0x19
    ctx->r12 = ADD32(ctx->r13, 0X19);
    // 0x800A7070: sh          $t4, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r12;
L_800A7074:
    // 0x800A7074: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
L_800A7078:
    // 0x800A7078: lh          $t3, 0xD0($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A707C: bltz        $a3, L_800A70E0
    if (SIGNED(ctx->r7) < 0) {
        // 0x800A7080: nop
    
            goto L_800A70E0;
    }
    // 0x800A7080: nop

    // 0x800A7084: multu       $a3, $s6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7088: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x800A708C: mflo        $t2
    ctx->r10 = lo;
    // 0x800A7090: addu        $t6, $s5, $t2
    ctx->r14 = ADD32(ctx->r21, ctx->r10);
    // 0x800A7094: lh          $v0, 0xE($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0XE));
    // 0x800A7098: beq         $v0, $at, L_800A70E0
    if (ctx->r2 == ctx->r1) {
        // 0x800A709C: addiu       $at, $zero, 0xAA
        ctx->r1 = ADD32(0, 0XAA);
            goto L_800A70E0;
    }
    // 0x800A709C: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x800A70A0: beq         $v0, $at, L_800A70E0
    if (ctx->r2 == ctx->r1) {
        // 0x800A70A4: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_800A70E0;
    }
    // 0x800A70A4: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x800A70A8: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x800A70AC: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A70B0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A70B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800A70B8: jal         0x800B177C
    // 0x800A70BC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    checkhitsprite(rdram, ctx);
        goto after_18;
    // 0x800A70BC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_18:
    // 0x800A70C0: lh          $t9, 0xCA($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A70C4: lh          $a1, 0xD2($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A70C8: bltz        $t9, L_800A9D28
    if (SIGNED(ctx->r25) < 0) {
        // 0x800A70CC: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_800A9D28;
    }
    // 0x800A70CC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800A70D0: jal         0x800AF77C
    // 0x800A70D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    checkhitswitch(rdram, ctx);
        goto after_19;
    // 0x800A70D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x800A70D8: b           L_800A9D2C
    // 0x800A70DC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A70DC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A70E0:
    // 0x800A70E0: bltz        $t3, L_800A9D28
    if (SIGNED(ctx->r11) < 0) {
        // 0x800A70E4: sll         $t5, $t3, 3
        ctx->r13 = S32(ctx->r11 << 3);
            goto L_800A9D28;
    }
    // 0x800A70E4: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x800A70E8: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x800A70EC: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800A70F0: addiu       $t4, $t4, 0x61A8
    ctx->r12 = ADD32(ctx->r12, 0X61A8);
    // 0x800A70F4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A70F8: addu        $a2, $t5, $t4
    ctx->r6 = ADD32(ctx->r13, ctx->r12);
    // 0x800A70FC: lh          $t2, 0xE($a2)
    ctx->r10 = S32(MEM_H(ctx->r6, 0XE));
    // 0x800A7100: andi        $t6, $t2, 0x2
    ctx->r14 = ctx->r10 & 0X2;
    // 0x800A7104: beql        $t6, $zero, L_800A7148
    if (ctx->r14 == 0) {
        // 0x800A7108: lh          $t5, 0xD0($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A7148;
    }
    goto skip_15;
    // 0x800A7108: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
    skip_15:
    // 0x800A710C: lh          $v0, 0xC($a2)
    ctx->r2 = S32(MEM_H(ctx->r6, 0XC));
    // 0x800A7110: lw          $t8, 0xA4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A7114: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800A7118: bltz        $v0, L_800A7144
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A711C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_800A7144;
    }
    // 0x800A711C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800A7120: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800A7124: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800A7128: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800A712C: lw          $t9, -0x1984($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X1984));
    // 0x800A7130: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A7134: bnel        $at, $zero, L_800A7148
    if (ctx->r1 != 0) {
        // 0x800A7138: lh          $t5, 0xD0($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A7148;
    }
    goto skip_16;
    // 0x800A7138: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
    skip_16:
    // 0x800A713C: lh          $t3, 0xA($a2)
    ctx->r11 = S32(MEM_H(ctx->r6, 0XA));
    // 0x800A7140: sh          $t3, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = ctx->r11;
L_800A7144:
    // 0x800A7144: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
L_800A7148:
    // 0x800A7148: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800A714C: bltz        $t5, L_800A9D28
    if (SIGNED(ctx->r13) < 0) {
        // 0x800A7150: sll         $t4, $t5, 3
        ctx->r12 = S32(ctx->r13 << 3);
            goto L_800A9D28;
    }
    // 0x800A7150: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x800A7154: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x800A7158: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A715C: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800A7160: lh          $v0, 0x61B8($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X61B8));
    // 0x800A7164: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x800A7168: beq         $v0, $at, L_800A9D28
    if (ctx->r2 == ctx->r1) {
        // 0x800A716C: addiu       $at, $zero, 0xAA
        ctx->r1 = ADD32(0, 0XAA);
            goto L_800A9D28;
    }
    // 0x800A716C: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x800A7170: beq         $v0, $at, L_800A9D28
    if (ctx->r2 == ctx->r1) {
        // 0x800A7174: sll         $a0, $s1, 16
        ctx->r4 = S32(ctx->r17 << 16);
            goto L_800A9D28;
    }
    // 0x800A7174: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800A7178: lw          $t6, 0xA4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A717C: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A7180: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800A7184: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800A7188: lw          $a2, 0xAC($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A718C: lw          $a3, 0xA8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A7190: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800A7194: jal         0x800B06B8
    // 0x800A7198: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    checkhitwall(rdram, ctx);
        goto after_20;
    // 0x800A7198: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_20:
    // 0x800A719C: lh          $t7, 0xCA($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A71A0: lh          $a1, 0xD0($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A71A4: bltz        $t7, L_800A9D28
    if (SIGNED(ctx->r15) < 0) {
        // 0x800A71A8: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800A9D28;
    }
    // 0x800A71A8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A71AC: jal         0x800AF77C
    // 0x800A71B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    checkhitswitch(rdram, ctx);
        goto after_21;
    // 0x800A71B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x800A71B4: b           L_800A9D2C
    // 0x800A71B8: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A71B8: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A71BC:
    // 0x800A71BC: bltzl       $t8, L_800A9D2C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800A71C0: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_17;
    // 0x800A71C0: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_17:
    // 0x800A71C4: blez        $t0, L_800A9D28
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800A71C8: sll         $t9, $s2, 2
        ctx->r25 = S32(ctx->r18 << 2);
            goto L_800A9D28;
    }
    // 0x800A71C8: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x800A71CC: subu        $t9, $t9, $s2
    ctx->r25 = SUB32(ctx->r25, ctx->r18);
    // 0x800A71D0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800A71D4: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x800A71D8: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x800A71DC: lh          $t3, -0x1970($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X1970));
    // 0x800A71E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A71E4: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800A71E8: bne         $v1, $t3, L_800A9D28
    if (ctx->r3 != ctx->r11) {
        // 0x800A71EC: subu        $t4, $t4, $t8
        ctx->r12 = SUB32(ctx->r12, ctx->r24);
            goto L_800A9D28;
    }
    // 0x800A71EC: subu        $t4, $t4, $t8
    ctx->r12 = SUB32(ctx->r12, ctx->r24);
    // 0x800A71F0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800A71F4: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800A71F8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A71FC: subu        $t4, $t4, $t8
    ctx->r12 = SUB32(ctx->r12, ctx->r24);
    // 0x800A7200: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x800A7204: addiu       $t2, $t2, 0x5770
    ctx->r10 = ADD32(ctx->r10, 0X5770);
    // 0x800A7208: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A720C: addu        $s0, $t4, $t2
    ctx->r16 = ADD32(ctx->r12, ctx->r10);
    // 0x800A7210: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A7214: jal         0x8009D240
    // 0x800A7218: addiu       $a1, $zero, 0x564
    ctx->r5 = ADD32(0, 0X564);
    spawn(rdram, ctx);
        goto after_22;
    // 0x800A7218: addiu       $a1, $zero, 0x564
    ctx->r5 = ADD32(0, 0X564);
    after_22:
    // 0x800A721C: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7220: lw          $t7, 0xAC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A7224: lw          $t9, 0xA8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A7228: lh          $t3, 0x282($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X282));
    // 0x800A722C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A7230: sra         $t5, $s1, 16
    ctx->r13 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A7234: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800A7238: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800A723C: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x800A7240: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x800A7244: mflo        $t6
    ctx->r14 = lo;
    // 0x800A7248: addu        $v1, $s5, $t6
    ctx->r3 = ADD32(ctx->r21, ctx->r14);
    // 0x800A724C: sh          $t8, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r24;
    // 0x800A7250: lh          $a0, 0xDA($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A7254: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800A7258: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800A725C: jal         0x80076190
    // 0x800A7260: sh          $t3, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r11;
    ssp(rdram, ctx);
        goto after_23;
    // 0x800A7260: sh          $t3, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r11;
    after_23:
    // 0x800A7264: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7268: mflo        $t4
    ctx->r12 = lo;
    // 0x800A726C: addu        $t2, $s5, $t4
    ctx->r10 = ADD32(ctx->r21, ctx->r12);
    // 0x800A7270: b           L_800A9D28
    // 0x800A7274: sh          $zero, 0x18($t2)
    MEM_H(0X18, ctx->r10) = 0;
        goto L_800A9D28;
    // 0x800A7274: sh          $zero, 0x18($t2)
    MEM_H(0X18, ctx->r10) = 0;
L_800A7278:
    // 0x800A7278: addiu       $at, $zero, 0xA35
    ctx->r1 = ADD32(0, 0XA35);
    // 0x800A727C: bne         $s4, $at, L_800A7288
    if (ctx->r20 != ctx->r1) {
        // 0x800A7280: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800A7288;
    }
    // 0x800A7280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A7284: addiu       $s4, $zero, 0xA24
    ctx->r20 = ADD32(0, 0XA24);
L_800A7288:
    // 0x800A7288: addiu       $at, $zero, 0x9E8
    ctx->r1 = ADD32(0, 0X9E8);
    // 0x800A728C: bne         $s4, $at, L_800A7298
    if (ctx->r20 != ctx->r1) {
        // 0x800A7290: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800A7298;
    }
    // 0x800A7290: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x800A7294: addiu       $s4, $zero, 0xA25
    ctx->r20 = ADD32(0, 0XA25);
L_800A7298:
    // 0x800A7298: lh          $t5, 0x22($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800A729C: addiu       $t6, $zero, -0x60
    ctx->r14 = ADD32(0, -0X60);
    // 0x800A72A0: bltz        $t5, L_800A72AC
    if (SIGNED(ctx->r13) < 0) {
        // 0x800A72A4: nop
    
            goto L_800A72AC;
    }
    // 0x800A72A4: nop

    // 0x800A72A8: sb          $t6, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r14;
L_800A72AC:
    // 0x800A72AC: bltzl       $t1, L_800A7524
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A72B0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800A7524;
    }
    goto skip_18;
    // 0x800A72B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_18:
    // 0x800A72B4: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A72B8: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A72BC: jal         0x800A1F14
    // 0x800A72C0: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    aim(rdram, ctx);
        goto after_24;
    // 0x800A72C0: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_24:
    // 0x800A72C4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A72C8: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A72CC: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800A72D0: bltz        $v0, L_800A73F4
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A72D4: lw          $t0, 0xB0($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
            goto L_800A73F4;
    }
    // 0x800A72D4: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A72D8: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A72DC: lh          $t3, 0xCA($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A72E0: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x800A72E4: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x800A72E8: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x800A72EC: subu        $t8, $t8, $t3
    ctx->r24 = SUB32(ctx->r24, ctx->r11);
    // 0x800A72F0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800A72F4: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x800A72F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A72FC: subu        $t8, $t8, $t3
    ctx->r24 = SUB32(ctx->r24, ctx->r11);
    // 0x800A7300: mflo        $t9
    ctx->r25 = lo;
    // 0x800A7304: addu        $a2, $s5, $t9
    ctx->r6 = ADD32(ctx->r21, ctx->r25);
    // 0x800A7308: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A730C: addu        $s0, $t8, $t4
    ctx->r16 = ADD32(ctx->r24, ctx->r12);
    // 0x800A7310: lhu         $a0, 0xE($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XE);
    // 0x800A7314: jal         0x800B4EA8
    // 0x800A7318: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    gettilesizy(rdram, ctx);
        goto after_25;
    // 0x800A7318: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_25:
    // 0x800A731C: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A7320: lbu         $t2, 0x27($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X27);
    // 0x800A7324: lh          $t6, 0xE($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0XE));
    // 0x800A7328: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A732C: addiu       $t7, $t6, -0x938
    ctx->r15 = ADD32(ctx->r14, -0X938);
    // 0x800A7330: sltiu       $at, $t7, 0x12
    ctx->r1 = ctx->r15 < 0X12 ? 1 : 0;
    // 0x800A7334: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A7338: mflo        $s2
    ctx->r18 = lo;
    // 0x800A733C: sll         $t5, $s2, 1
    ctx->r13 = S32(ctx->r18 << 1);
    // 0x800A7340: beq         $at, $zero, L_800A7360
    if (ctx->r1 == 0) {
        // 0x800A7344: addiu       $s2, $t5, 0x500
        ctx->r18 = ADD32(ctx->r13, 0X500);
            goto L_800A7360;
    }
    // 0x800A7344: addiu       $s2, $t5, 0x500
    ctx->r18 = ADD32(ctx->r13, 0X500);
    // 0x800A7348: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800A734C: addu        $at, $at, $t7
    gpr jr_addend_800A7354 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A7350: lw          $t7, -0x7E84($at)
    ctx->r15 = ADD32(ctx->r1, -0X7E84);
    // 0x800A7354: jr          $t7
    // 0x800A7358: nop

    switch (jr_addend_800A7354 >> 2) {
        case 0: goto L_800A735C; break;
        case 1: goto L_800A7360; break;
        case 2: goto L_800A7360; break;
        case 3: goto L_800A7360; break;
        case 4: goto L_800A7360; break;
        case 5: goto L_800A7360; break;
        case 6: goto L_800A7360; break;
        case 7: goto L_800A7360; break;
        case 8: goto L_800A7360; break;
        case 9: goto L_800A7360; break;
        case 10: goto L_800A735C; break;
        case 11: goto L_800A735C; break;
        case 12: goto L_800A735C; break;
        case 13: goto L_800A735C; break;
        case 14: goto L_800A735C; break;
        case 15: goto L_800A735C; break;
        case 16: goto L_800A735C; break;
        case 17: goto L_800A735C; break;
        default: switch_error(__func__, 0x800A7354, 0x8010817C);
    }
    // 0x800A7358: nop

L_800A735C:
    // 0x800A735C: addiu       $s2, $s2, -0x800
    ctx->r18 = ADD32(ctx->r18, -0X800);
L_800A7360:
    // 0x800A7360: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A7364: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800A7368: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800A736C: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7370: mflo        $t3
    ctx->r11 = lo;
    // 0x800A7374: addu        $a0, $s5, $t3
    ctx->r4 = ADD32(ctx->r21, ctx->r11);
    // 0x800A7378: jal         0x800ACE8C
    // 0x800A737C: nop

    ldist(rdram, ctx);
        goto after_26;
    // 0x800A737C: nop

    after_26:
    // 0x800A7380: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A7384: lw          $t4, 0xB8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A7388: lw          $t9, 0xC0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A738C: lw          $t8, 0x8($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800A7390: lw          $t7, 0x0($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A7394: lw          $t3, 0x4($a2)
    ctx->r11 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A7398: subu        $t2, $t8, $t4
    ctx->r10 = SUB32(ctx->r24, ctx->r12);
    // 0x800A739C: subu        $t5, $t2, $s2
    ctx->r13 = SUB32(ctx->r10, ctx->r18);
    // 0x800A73A0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800A73A4: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800A73A8: lw          $t8, 0xBC($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A73AC: mflo        $t0
    ctx->r8 = lo;
    // 0x800A73B0: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A73B4: bne         $v0, $zero, L_800A73C0
    if (ctx->r2 != 0) {
        // 0x800A73B8: nop
    
            goto L_800A73C0;
    }
    // 0x800A73B8: nop

    // 0x800A73BC: break       7
    do_break(2148168636);
L_800A73C0:
    // 0x800A73C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A73C4: bne         $v0, $at, L_800A73D8
    if (ctx->r2 != ctx->r1) {
        // 0x800A73C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A73D8;
    }
    // 0x800A73C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A73CC: bne         $t6, $at, L_800A73D8
    if (ctx->r14 != ctx->r1) {
        // 0x800A73D0: nop
    
            goto L_800A73D8;
    }
    // 0x800A73D0: nop

    // 0x800A73D4: break       6
    do_break(2148168660);
L_800A73D8:
    // 0x800A73D8: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x800A73DC: jal         0x80092024
    // 0x800A73E0: subu        $a1, $t3, $t8
    ctx->r5 = SUB32(ctx->r11, ctx->r24);
    getangle(rdram, ctx);
        goto after_27;
    // 0x800A73E0: subu        $a1, $t3, $t8
    ctx->r5 = SUB32(ctx->r11, ctx->r24);
    after_27:
    // 0x800A73E4: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800A73E8: sra         $t4, $s3, 16
    ctx->r12 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800A73EC: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x800A73F0: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A73F4:
    // 0x800A73F4: addiu       $at, $zero, 0xA23
    ctx->r1 = ADD32(0, 0XA23);
    // 0x800A73F8: bne         $s4, $at, L_800A747C
    if (ctx->r20 != ctx->r1) {
        // 0x800A73FC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A747C;
    }
    // 0x800A73FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7400: bne         $s1, $at, L_800A7510
    if (ctx->r17 != ctx->r1) {
        // 0x800A7404: lh          $t2, 0xCA($sp)
        ctx->r10 = S32(MEM_H(ctx->r29, 0XCA));
            goto L_800A7510;
    }
    // 0x800A7404: lh          $t2, 0xCA($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A7408: sll         $t5, $t2, 3
    ctx->r13 = S32(ctx->r10 << 3);
    // 0x800A740C: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x800A7410: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800A7414: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x800A7418: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A741C: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x800A7420: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800A7424: addiu       $t6, $t6, 0x5770
    ctx->r14 = ADD32(ctx->r14, 0X5770);
    // 0x800A7428: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A742C: jal         0x8009800C
    // 0x800A7430: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    krand2(rdram, ctx);
        goto after_28;
    // 0x800A7430: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    after_28:
    // 0x800A7434: lw          $t8, 0x220($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A7438: lh          $t2, 0x2B8($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A743C: andi        $t7, $v0, 0x1F
    ctx->r15 = ctx->r2 & 0X1F;
    // 0x800A7440: negu        $t4, $t8
    ctx->r12 = SUB32(0, ctx->r24);
    // 0x800A7444: subu        $s3, $s3, $t7
    ctx->r19 = SUB32(ctx->r19, ctx->r15);
    // 0x800A7448: subu        $t0, $t4, $t2
    ctx->r8 = SUB32(ctx->r12, ctx->r10);
    // 0x800A744C: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x800A7450: addiu       $t0, $t0, 0x64
    ctx->r8 = ADD32(ctx->r8, 0X64);
    // 0x800A7454: sll         $t9, $s3, 16
    ctx->r25 = S32(ctx->r19 << 16);
    // 0x800A7458: sll         $t5, $t0, 5
    ctx->r13 = S32(ctx->r8 << 5);
    // 0x800A745C: sra         $s3, $t9, 16
    ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800A7460: jal         0x8009800C
    // 0x800A7464: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    krand2(rdram, ctx);
        goto after_29;
    // 0x800A7464: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    after_29:
    // 0x800A7468: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A746C: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800A7470: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800A7474: b           L_800A7510
    // 0x800A7478: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
        goto L_800A7510;
    // 0x800A7478: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
L_800A747C:
    // 0x800A747C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7480: bne         $s1, $at, L_800A74CC
    if (ctx->r17 != ctx->r1) {
        // 0x800A7484: lh          $t7, 0xCA($sp)
        ctx->r15 = S32(MEM_H(ctx->r29, 0XCA));
            goto L_800A74CC;
    }
    // 0x800A7484: lh          $t7, 0xCA($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A7488: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800A748C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800A7490: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800A7494: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800A7498: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A749C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800A74A0: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x800A74A4: addiu       $t3, $t3, 0x5770
    ctx->r11 = ADD32(ctx->r11, 0X5770);
    // 0x800A74A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A74AC: addu        $s0, $t9, $t3
    ctx->r16 = ADD32(ctx->r25, ctx->r11);
    // 0x800A74B0: lw          $t8, 0x220($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A74B4: lh          $t2, 0x2B8($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A74B8: negu        $t4, $t8
    ctx->r12 = SUB32(0, ctx->r24);
    // 0x800A74BC: subu        $t0, $t4, $t2
    ctx->r8 = SUB32(ctx->r12, ctx->r10);
    // 0x800A74C0: addiu       $t0, $t0, 0x64
    ctx->r8 = ADD32(ctx->r8, 0X64);
    // 0x800A74C4: sll         $t5, $t0, 5
    ctx->r13 = S32(ctx->r8 << 5);
    // 0x800A74C8: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
L_800A74CC:
    // 0x800A74CC: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
    // 0x800A74D0: beql        $s4, $at, L_800A7514
    if (ctx->r20 == ctx->r1) {
        // 0x800A74D4: lw          $t8, 0xB8($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0XB8));
            goto L_800A7514;
    }
    goto skip_19;
    // 0x800A74D4: lw          $t8, 0xB8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XB8));
    skip_19:
    // 0x800A74D8: jal         0x8009800C
    // 0x800A74DC: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_30;
    // 0x800A74DC: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_30:
    // 0x800A74E0: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A74E4: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800A74E8: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800A74EC: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
    // 0x800A74F0: jal         0x8009800C
    // 0x800A74F4: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_31;
    // 0x800A74F4: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_31:
    // 0x800A74F8: andi        $t7, $v0, 0x1F
    ctx->r15 = ctx->r2 & 0X1F;
    // 0x800A74FC: subu        $s3, $s3, $t7
    ctx->r19 = SUB32(ctx->r19, ctx->r15);
    // 0x800A7500: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x800A7504: sll         $t9, $s3, 16
    ctx->r25 = S32(ctx->r19 << 16);
    // 0x800A7508: sra         $s3, $t9, 16
    ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800A750C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A7510:
    // 0x800A7510: lw          $t8, 0xB8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XB8));
L_800A7514:
    // 0x800A7514: addiu       $t4, $t8, -0x200
    ctx->r12 = ADD32(ctx->r24, -0X200);
    // 0x800A7518: b           L_800A769C
    // 0x800A751C: sw          $t4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r12;
        goto L_800A769C;
    // 0x800A751C: sw          $t4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r12;
    // 0x800A7520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800A7524:
    // 0x800A7524: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x800A7528: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A752C: jal         0x800ACF18
    // 0x800A7530: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    findplayer(rdram, ctx);
        goto after_32;
    // 0x800A7530: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_32:
    // 0x800A7534: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800A7538: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800A753C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A7540: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800A7544: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A7548: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800A754C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A7550: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x800A7554: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800A7558: lh          $t9, 0x5A50($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X5A50));
    // 0x800A755C: lw          $t5, 0xB8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A7560: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A7564: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7568: sra         $t2, $s1, 16
    ctx->r10 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A756C: addiu       $t6, $t5, -0x400
    ctx->r14 = ADD32(ctx->r13, -0X400);
    // 0x800A7570: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800A7574: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x800A7578: lw          $a1, 0x78($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A757C: mflo        $t3
    ctx->r11 = lo;
    // 0x800A7580: addu        $a0, $s5, $t3
    ctx->r4 = ADD32(ctx->r21, ctx->r11);
    // 0x800A7584: jal         0x800ACE8C
    // 0x800A7588: nop

    ldist(rdram, ctx);
        goto after_33;
    // 0x800A7588: nop

    after_33:
    // 0x800A758C: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x800A7590: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x800A7594: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800A7598: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x800A759C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A75A0: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x800A75A4: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x800A75A8: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x800A75AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A75B0: addu        $s0, $t8, $t4
    ctx->r16 = ADD32(ctx->r24, ctx->r12);
    // 0x800A75B4: lw          $t2, 0x21C($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800A75B8: lw          $t5, 0xB8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A75BC: lw          $t9, 0x78($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A75C0: subu        $t6, $t2, $t5
    ctx->r14 = SUB32(ctx->r10, ctx->r13);
    // 0x800A75C4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800A75C8: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x800A75CC: bne         $v0, $zero, L_800A75D8
    if (ctx->r2 != 0) {
        // 0x800A75D0: nop
    
            goto L_800A75D8;
    }
    // 0x800A75D0: nop

    // 0x800A75D4: break       7
    do_break(2148169172);
L_800A75D8:
    // 0x800A75D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A75DC: bne         $v0, $at, L_800A75F0
    if (ctx->r2 != ctx->r1) {
        // 0x800A75E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A75F0;
    }
    // 0x800A75E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A75E4: bne         $t7, $at, L_800A75F0
    if (ctx->r15 != ctx->r1) {
        // 0x800A75E8: nop
    
            goto L_800A75F0;
    }
    // 0x800A75E8: nop

    // 0x800A75EC: break       6
    do_break(2148169196);
L_800A75F0:
    // 0x800A75F0: lh          $t3, 0xE($t9)
    ctx->r11 = S32(MEM_H(ctx->r25, 0XE));
    // 0x800A75F4: mflo        $t0
    ctx->r8 = lo;
    // 0x800A75F8: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    // 0x800A75FC: beq         $t3, $at, L_800A7640
    if (ctx->r11 == ctx->r1) {
        // 0x800A7600: nop
    
            goto L_800A7640;
    }
    // 0x800A7600: nop

    // 0x800A7604: jal         0x8009800C
    // 0x800A7608: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_34;
    // 0x800A7608: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_34:
    // 0x800A760C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A7610: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x800A7614: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800A7618: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
    // 0x800A761C: jal         0x8009800C
    // 0x800A7620: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_35;
    // 0x800A7620: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_35:
    // 0x800A7624: andi        $t4, $v0, 0x3F
    ctx->r12 = ctx->r2 & 0X3F;
    // 0x800A7628: subu        $s3, $s3, $t4
    ctx->r19 = SUB32(ctx->r19, ctx->r12);
    // 0x800A762C: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x800A7630: sll         $t2, $s3, 16
    ctx->r10 = S32(ctx->r19 << 16);
    // 0x800A7634: sra         $s3, $t2, 16
    ctx->r19 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800A7638: b           L_800A769C
    // 0x800A763C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
        goto L_800A769C;
    // 0x800A763C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A7640:
    // 0x800A7640: jal         0x8009800C
    // 0x800A7644: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_36;
    // 0x800A7644: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_36:
    // 0x800A7648: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A764C: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800A7650: lw          $t7, 0x214($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800A7654: lw          $t9, 0xC0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A7658: lw          $t3, 0x218($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800A765C: lw          $t8, 0xBC($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A7660: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800A7664: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
    // 0x800A7668: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A766C: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x800A7670: jal         0x80092024
    // 0x800A7674: subu        $a1, $t3, $t8
    ctx->r5 = SUB32(ctx->r11, ctx->r24);
    getangle(rdram, ctx);
        goto after_37;
    // 0x800A7674: subu        $a1, $t3, $t8
    ctx->r5 = SUB32(ctx->r11, ctx->r24);
    after_37:
    // 0x800A7678: jal         0x8009800C
    // 0x800A767C: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    krand2(rdram, ctx);
        goto after_38;
    // 0x800A767C: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    after_38:
    // 0x800A7680: lw          $v1, 0x84($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800A7684: andi        $t4, $v0, 0x7F
    ctx->r12 = ctx->r2 & 0X7F;
    // 0x800A7688: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A768C: subu        $s3, $v1, $t4
    ctx->r19 = SUB32(ctx->r3, ctx->r12);
    // 0x800A7690: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // 0x800A7694: sll         $t2, $s3, 16
    ctx->r10 = S32(ctx->r19 << 16);
    // 0x800A7698: sra         $s3, $t2, 16
    ctx->r19 = S32(SIGNED(ctx->r10) >> 16);
L_800A769C:
    // 0x800A769C: lw          $v1, 0x78($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A76A0: addiu       $t9, $s3, 0x200
    ctx->r25 = ADD32(ctx->r19, 0X200);
    // 0x800A76A4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800A76A8: lh          $t6, 0xC($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0XC));
    // 0x800A76AC: andi        $t3, $t9, 0x7FF
    ctx->r11 = ctx->r25 & 0X7FF;
    // 0x800A76B0: addiu       $v0, $v0, -0x9A0
    ctx->r2 = ADD32(ctx->r2, -0X9A0);
    // 0x800A76B4: andi        $t7, $t6, 0xFEFE
    ctx->r15 = ctx->r14 & 0XFEFE;
    // 0x800A76B8: sh          $t7, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r15;
    // 0x800A76BC: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800A76C0: andi        $t5, $s3, 0x7FF
    ctx->r13 = ctx->r19 & 0X7FF;
    // 0x800A76C4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800A76C8: addu        $t4, $v0, $t8
    ctx->r12 = ADD32(ctx->r2, ctx->r24);
    // 0x800A76CC: lh          $t2, 0x0($t4)
    ctx->r10 = S32(MEM_H(ctx->r12, 0X0));
    // 0x800A76D0: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800A76D4: lh          $t9, 0x0($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800A76D8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A76DC: addiu       $t2, $sp, 0xD2
    ctx->r10 = ADD32(ctx->r29, 0XD2);
    // 0x800A76E0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A76E4: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x800A76E8: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x800A76EC: addiu       $t7, $sp, 0xA4
    ctx->r15 = ADD32(ctx->r29, 0XA4);
    // 0x800A76F0: addiu       $t6, $sp, 0xA8
    ctx->r14 = ADD32(ctx->r29, 0XA8);
    // 0x800A76F4: addiu       $t4, $sp, 0xD0
    ctx->r12 = ADD32(ctx->r29, 0XD0);
    // 0x800A76F8: addiu       $t8, $sp, 0xD4
    ctx->r24 = ADD32(ctx->r29, 0XD4);
    // 0x800A76FC: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800A7700: sll         $t3, $t0, 6
    ctx->r11 = S32(ctx->r8 << 6);
    // 0x800A7704: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A7708: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800A770C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A7710: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800A7714: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800A7718: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800A771C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800A7720: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800A7724: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A7728: lh          $a3, 0xD6($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A772C: lw          $a2, 0xB8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A7730: lw          $a1, 0xBC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A7734: jal         0x8009324C
    // 0x800A7738: lw          $a0, 0xC0($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XC0));
    hitscan(rdram, ctx);
        goto after_39;
    // 0x800A7738: lw          $a0, 0xC0($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XC0));
    after_39:
    // 0x800A773C: lw          $t3, 0x78($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A7740: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A7744: lh          $t8, 0xC($t3)
    ctx->r24 = S32(MEM_H(ctx->r11, 0XC));
    // 0x800A7748: ori         $t4, $t8, 0x101
    ctx->r12 = ctx->r24 | 0X101;
    // 0x800A774C: sh          $t4, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r12;
    // 0x800A7750: lh          $t2, 0xD4($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A7754: bltzl       $t2, L_800A9D2C
    if (SIGNED(ctx->r10) < 0) {
        // 0x800A7758: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_20;
    // 0x800A7758: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_20:
    // 0x800A775C: jal         0x8009800C
    // 0x800A7760: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_40;
    // 0x800A7760: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_40:
    // 0x800A7764: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x800A7768: bne         $t5, $zero, L_800A77C8
    if (ctx->r13 != 0) {
        // 0x800A776C: lw          $t0, 0xB0($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
            goto L_800A77C8;
    }
    // 0x800A776C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A7770: lh          $a0, 0xD4($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A7774: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800A7778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A777C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A7780: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A7784: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800A7788: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800A778C: lh          $t7, -0x1970($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X1970));
    // 0x800A7790: lw          $a0, 0xAC($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A7794: lw          $a1, 0xA8($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A7798: bne         $t7, $at, L_800A77C8
    if (ctx->r15 != ctx->r1) {
        // 0x800A779C: lw          $a2, 0xA4($sp)
        ctx->r6 = S32(MEM_W(ctx->r29, 0XA4));
            goto L_800A77C8;
    }
    // 0x800A779C: lw          $a2, 0xA4($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A77A0: lw          $t9, 0xBC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A77A4: lw          $t8, 0xB8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A77A8: lh          $t4, 0xCA($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A77AC: lw          $a3, 0xC0($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A77B0: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A77B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800A77B8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A77BC: jal         0x800A1858
    // 0x800A77C0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    tracers(rdram, ctx);
        goto after_41;
    // 0x800A77C0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_41:
    // 0x800A77C4: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A77C8:
    // 0x800A77C8: lh          $t3, 0xCA($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A77CC: lh          $a0, 0xD4($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A77D0: lw          $a1, 0xAC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A77D4: bltz        $t3, L_800A7FE4
    if (SIGNED(ctx->r11) < 0) {
        // 0x800A77D8: lw          $a2, 0xA8($sp)
        ctx->r6 = S32(MEM_W(ctx->r29, 0XA8));
            goto L_800A7FE4;
    }
    // 0x800A77D8: lw          $a2, 0xA8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A77DC: lh          $t7, 0xDA($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A77E0: addiu       $t2, $zero, -0xF
    ctx->r10 = ADD32(0, -0XF);
    // 0x800A77E4: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800A77E8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800A77EC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800A77F0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A77F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A77F8: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800A77FC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800A7800: lw          $a1, 0xAC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A7804: lw          $a2, 0xA8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A7808: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A780C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800A7810: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A7814: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A7818: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A781C: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A7820: jal         0x8009B028
    // 0x800A7824: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    EGS(rdram, ctx);
        goto after_42;
    // 0x800A7824: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_42:
    // 0x800A7828: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A782C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800A7830: addiu       $t6, $t6, -0x447C
    ctx->r14 = ADD32(ctx->r14, -0X447C);
    // 0x800A7834: sll         $t5, $s4, 1
    ctx->r13 = S32(ctx->r20 << 1);
    // 0x800A7838: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x800A783C: lh          $t7, 0x0($a0)
    ctx->r15 = S32(MEM_H(ctx->r4, 0X0));
    // 0x800A7840: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800A7844: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800A7848: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800A784C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800A7850: mflo        $t4
    ctx->r12 = lo;
    // 0x800A7854: addu        $v1, $s5, $t4
    ctx->r3 = ADD32(ctx->r21, ctx->r12);
    // 0x800A7858: lh          $t3, 0xC($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0XC));
    // 0x800A785C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800A7860: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800A7864: ori         $t2, $t3, 0x80
    ctx->r10 = ctx->r11 | 0X80;
    // 0x800A7868: sh          $t2, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r10;
    // 0x800A786C: lw          $t8, -0x1700($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X1700));
    // 0x800A7870: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800A7874: jal         0x8009800C
    // 0x800A7878: sh          $t8, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r24;
    krand2(rdram, ctx);
        goto after_43;
    // 0x800A7878: sh          $t8, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r24;
    after_43:
    // 0x800A787C: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7880: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800A7884: addiu       $t7, $s3, 0x600
    ctx->r15 = ADD32(ctx->r19, 0X600);
    // 0x800A7888: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800A788C: andi        $t9, $t7, 0x7FF
    ctx->r25 = ctx->r15 & 0X7FF;
    // 0x800A7890: addiu       $v1, $v1, -0x9A0
    ctx->r3 = ADD32(ctx->r3, -0X9A0);
    // 0x800A7894: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800A7898: addiu       $t9, $s3, 0x400
    ctx->r25 = ADD32(ctx->r19, 0X400);
    // 0x800A789C: mflo        $t4
    ctx->r12 = lo;
    // 0x800A78A0: addu        $s1, $s5, $t4
    ctx->r17 = ADD32(ctx->r21, ctx->r12);
    // 0x800A78A4: lh          $t3, 0x22($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800A78A8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800A78AC: mfhi        $t2
    ctx->r10 = hi;
    // 0x800A78B0: addu        $t4, $v1, $t8
    ctx->r12 = ADD32(ctx->r3, ctx->r24);
    // 0x800A78B4: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x800A78B8: lh          $t3, 0x0($t4)
    ctx->r11 = S32(MEM_H(ctx->r12, 0X0));
    // 0x800A78BC: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800A78C0: andi        $t8, $t9, 0x7FF
    ctx->r24 = ctx->r25 & 0X7FF;
    // 0x800A78C4: sra         $t2, $t3, 10
    ctx->r10 = S32(SIGNED(ctx->r11) >> 10);
    // 0x800A78C8: sh          $t5, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r13;
    // 0x800A78CC: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800A78D0: addu        $t3, $v1, $t4
    ctx->r11 = ADD32(ctx->r3, ctx->r12);
    // 0x800A78D4: addu        $t5, $t6, $t2
    ctx->r13 = ADD32(ctx->r14, ctx->r10);
    // 0x800A78D8: lh          $t6, 0x0($t3)
    ctx->r14 = S32(MEM_H(ctx->r11, 0X0));
    // 0x800A78DC: lw          $t7, 0x4($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800A78E0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800A78E4: sra         $t2, $t6, 10
    ctx->r10 = S32(SIGNED(ctx->r14) >> 10);
    // 0x800A78E8: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x800A78EC: jal         0x8009800C
    // 0x800A78F0: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    krand2(rdram, ctx);
        goto after_44;
    // 0x800A78F0: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    after_44:
    // 0x800A78F4: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x800A78F8: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800A78FC: beq         $at, $zero, L_800A7910
    if (ctx->r1 == 0) {
        // 0x800A7900: lw          $t0, 0xB0($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
            goto L_800A7910;
    }
    // 0x800A7900: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A7904: lh          $t8, 0xC($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, 0XC));
    // 0x800A7908: ori         $t4, $t8, 0x4
    ctx->r12 = ctx->r24 | 0X4;
    // 0x800A790C: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
L_800A7910:
    // 0x800A7910: jal         0x8009800C
    // 0x800A7914: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_45;
    // 0x800A7914: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_45:
    // 0x800A7918: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x800A791C: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x800A7920: beq         $at, $zero, L_800A7934
    if (ctx->r1 == 0) {
        // 0x800A7924: lw          $t0, 0xB0($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
            goto L_800A7934;
    }
    // 0x800A7924: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A7928: lh          $t6, 0xC($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, 0XC));
    // 0x800A792C: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x800A7930: sh          $t7, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r15;
L_800A7934:
    // 0x800A7934: lh          $t2, 0xD0($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7938: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A793C: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A7940: bne         $t2, $at, L_800A79FC
    if (ctx->r10 != ctx->r1) {
        // 0x800A7944: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A79FC;
    }
    // 0x800A7944: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7948: bnel        $a3, $at, L_800A7A00
    if (ctx->r7 != ctx->r1) {
        // 0x800A794C: addiu       $at, $zero, 0xA27
        ctx->r1 = ADD32(0, 0XA27);
            goto L_800A7A00;
    }
    goto skip_21;
    // 0x800A794C: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
    skip_21:
    // 0x800A7950: bgez        $t0, L_800A79C8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A7954: lh          $t6, 0xD4($sp)
        ctx->r14 = S32(MEM_H(ctx->r29, 0XD4));
            goto L_800A79C8;
    }
    // 0x800A7954: lh          $t6, 0xD4($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A7958: lh          $a1, 0xD4($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A795C: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800A7960: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x800A7964: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x800A7968: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x800A796C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800A7970: addu        $a0, $t5, $t9
    ctx->r4 = ADD32(ctx->r13, ctx->r25);
    // 0x800A7974: lh          $v1, 0x10($a0)
    ctx->r3 = S32(MEM_H(ctx->r4, 0X10));
    // 0x800A7978: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800A797C: beq         $v1, $at, L_800A798C
    if (ctx->r3 == ctx->r1) {
        // 0x800A7980: addiu       $at, $zero, 0x150
        ctx->r1 = ADD32(0, 0X150);
            goto L_800A798C;
    }
    // 0x800A7980: addiu       $at, $zero, 0x150
    ctx->r1 = ADD32(0, 0X150);
    // 0x800A7984: bnel        $v1, $at, L_800A7998
    if (ctx->r3 != ctx->r1) {
        // 0x800A7988: lh          $t8, 0xC($a0)
        ctx->r24 = S32(MEM_H(ctx->r4, 0XC));
            goto L_800A7998;
    }
    goto skip_22;
    // 0x800A7988: lh          $t8, 0xC($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0XC));
    skip_22:
L_800A798C:
    // 0x800A798C: sb          $zero, 0x27($s1)
    MEM_B(0X27, ctx->r17) = 0;
    // 0x800A7990: sb          $zero, 0x28($s1)
    MEM_B(0X28, ctx->r17) = 0;
    // 0x800A7994: lh          $t8, 0xC($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0XC));
L_800A7998:
    // 0x800A7998: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x800A799C: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A79A0: andi        $t4, $t8, 0x1
    ctx->r12 = ctx->r24 & 0X1;
    // 0x800A79A4: beq         $t4, $zero, L_800A79B8
    if (ctx->r12 == 0) {
        // 0x800A79A8: nop
    
            goto L_800A79B8;
    }
    // 0x800A79A8: nop

    // 0x800A79AC: sb          $zero, 0x27($s1)
    MEM_B(0X27, ctx->r17) = 0;
    // 0x800A79B0: b           L_800A9D28
    // 0x800A79B4: sb          $zero, 0x28($s1)
    MEM_B(0X28, ctx->r17) = 0;
        goto L_800A9D28;
    // 0x800A79B4: sb          $zero, 0x28($s1)
    MEM_B(0X28, ctx->r17) = 0;
L_800A79B8:
    // 0x800A79B8: jal         0x800B147C
    // 0x800A79BC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    checkhitceiling(rdram, ctx);
        goto after_46;
    // 0x800A79BC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_46:
    // 0x800A79C0: b           L_800A7A00
    // 0x800A79C4: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
        goto L_800A7A00;
    // 0x800A79C4: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
L_800A79C8:
    // 0x800A79C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A79CC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A79D0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800A79D4: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x800A79D8: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800A79DC: lh          $v1, -0x1974($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, -0X1974));
    // 0x800A79E0: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800A79E4: beq         $v1, $at, L_800A79F4
    if (ctx->r3 == ctx->r1) {
        // 0x800A79E8: addiu       $at, $zero, 0x150
        ctx->r1 = ADD32(0, 0X150);
            goto L_800A79F4;
    }
    // 0x800A79E8: addiu       $at, $zero, 0x150
    ctx->r1 = ADD32(0, 0X150);
    // 0x800A79EC: bnel        $v1, $at, L_800A7A00
    if (ctx->r3 != ctx->r1) {
        // 0x800A79F0: addiu       $at, $zero, 0xA27
        ctx->r1 = ADD32(0, 0XA27);
            goto L_800A7A00;
    }
    goto skip_23;
    // 0x800A79F0: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
    skip_23:
L_800A79F4:
    // 0x800A79F4: sb          $zero, 0x27($s1)
    MEM_B(0X27, ctx->r17) = 0;
    // 0x800A79F8: sb          $zero, 0x28($s1)
    MEM_B(0X28, ctx->r17) = 0;
L_800A79FC:
    // 0x800A79FC: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
L_800A7A00:
    // 0x800A7A00: bne         $s4, $at, L_800A7A9C
    if (ctx->r20 != ctx->r1) {
        // 0x800A7A04: lh          $a3, 0xD2($sp)
        ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
            goto L_800A7A9C;
    }
    // 0x800A7A04: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A7A08: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A7A0C: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A7A10: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800A7A14: jal         0x8009D240
    // 0x800A7A18: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    spawn(rdram, ctx);
        goto after_47;
    // 0x800A7A18: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    after_47:
    // 0x800A7A1C: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7A20: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800A7A24: addiu       $t3, $zero, 0x15C
    ctx->r11 = ADD32(0, 0X15C);
    // 0x800A7A28: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A7A2C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800A7A30: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x800A7A34: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800A7A38: mflo        $t5
    ctx->r13 = lo;
    // 0x800A7A3C: addu        $v1, $s5, $t5
    ctx->r3 = ADD32(ctx->r21, ctx->r13);
    // 0x800A7A40: lh          $t9, 0x14($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X14));
    // 0x800A7A44: sh          $t3, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r11;
    // 0x800A7A48: addiu       $t8, $t9, 0x400
    ctx->r24 = ADD32(ctx->r25, 0X400);
    // 0x800A7A4C: andi        $t4, $t8, 0x7FF
    ctx->r12 = ctx->r24 & 0X7FF;
    // 0x800A7A50: jal         0x80076190
    // 0x800A7A54: sh          $t4, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r12;
    ssp(rdram, ctx);
        goto after_48;
    // 0x800A7A54: sh          $t4, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r12;
    after_48:
    // 0x800A7A58: lh          $v1, 0x22($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800A7A5C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A7A60: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A7A64: sra         $a2, $v1, 2
    ctx->r6 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800A7A68: subu        $t2, $v1, $a2
    ctx->r10 = SUB32(ctx->r3, ctx->r6);
    // 0x800A7A6C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A7A70: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A7A74: addiu       $a1, $zero, 0x9C4
    ctx->r5 = ADD32(0, 0X9C4);
    // 0x800A7A78: sra         $a3, $v1, 1
    ctx->r7 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A7A7C: jal         0x80087994
    // 0x800A7A80: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    hitradius(rdram, ctx);
        goto after_49;
    // 0x800A7A80: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_49:
    // 0x800A7A84: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800A7A88: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A7A8C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800A7A90: jal         0x80059034
    // 0x800A7A94: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    spritesound(rdram, ctx);
        goto after_50;
    // 0x800A7A94: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_50:
    // 0x800A7A98: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
L_800A7A9C:
    // 0x800A7A9C: bltz        $a3, L_800A7B5C
    if (SIGNED(ctx->r7) < 0) {
        // 0x800A7AA0: addiu       $at, $zero, 0xA27
        ctx->r1 = ADD32(0, 0XA27);
            goto L_800A7B5C;
    }
    // 0x800A7AA0: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
    // 0x800A7AA4: beq         $s4, $at, L_800A7B5C
    if (ctx->r20 == ctx->r1) {
        // 0x800A7AA8: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_800A7B5C;
    }
    // 0x800A7AA8: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x800A7AAC: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800A7AB0: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A7AB4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A7AB8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800A7ABC: jal         0x800B177C
    // 0x800A7AC0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    checkhitsprite(rdram, ctx);
        goto after_51;
    // 0x800A7AC0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_51:
    // 0x800A7AC4: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A7AC8: multu       $a3, $s6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7ACC: mflo        $t4
    ctx->r12 = lo;
    // 0x800A7AD0: addu        $a0, $s5, $t4
    ctx->r4 = ADD32(ctx->r21, ctx->r12);
    // 0x800A7AD4: jal         0x80099ED4
    // 0x800A7AD8: nop

    badguy(rdram, ctx);
        goto after_52;
    // 0x800A7AD8: nop

    after_52:
    // 0x800A7ADC: lh          $t6, 0xCA($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A7AE0: sb          $zero, 0x28($s1)
    MEM_B(0X28, ctx->r17) = 0;
    // 0x800A7AE4: sb          $zero, 0x27($s1)
    MEM_B(0X27, ctx->r17) = 0;
    // 0x800A7AE8: bltz        $t6, L_800A80E4
    if (SIGNED(ctx->r14) < 0) {
        // 0x800A7AEC: lh          $a3, 0xD2($sp)
        ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
            goto L_800A80E4;
    }
    // 0x800A7AEC: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A7AF0: multu       $a3, $s6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7AF4: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x800A7AF8: lh          $a0, 0xCA($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A7AFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800A7B00: mflo        $t7
    ctx->r15 = lo;
    // 0x800A7B04: addu        $t2, $s5, $t7
    ctx->r10 = ADD32(ctx->r21, ctx->r15);
    // 0x800A7B08: lh          $v0, 0xE($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0XE));
    // 0x800A7B0C: beq         $v0, $at, L_800A7B4C
    if (ctx->r2 == ctx->r1) {
        // 0x800A7B10: addiu       $at, $zero, 0xA3
        ctx->r1 = ADD32(0, 0XA3);
            goto L_800A7B4C;
    }
    // 0x800A7B10: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x800A7B14: beq         $v0, $at, L_800A7B4C
    if (ctx->r2 == ctx->r1) {
        // 0x800A7B18: addiu       $at, $zero, 0xA4
        ctx->r1 = ADD32(0, 0XA4);
            goto L_800A7B4C;
    }
    // 0x800A7B18: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x800A7B1C: beq         $v0, $at, L_800A7B4C
    if (ctx->r2 == ctx->r1) {
        // 0x800A7B20: addiu       $at, $zero, 0xA5
        ctx->r1 = ADD32(0, 0XA5);
            goto L_800A7B4C;
    }
    // 0x800A7B20: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x800A7B24: beq         $v0, $at, L_800A7B4C
    if (ctx->r2 == ctx->r1) {
        // 0x800A7B28: addiu       $at, $zero, 0xA8
        ctx->r1 = ADD32(0, 0XA8);
            goto L_800A7B4C;
    }
    // 0x800A7B28: addiu       $at, $zero, 0xA8
    ctx->r1 = ADD32(0, 0XA8);
    // 0x800A7B2C: beq         $v0, $at, L_800A7B4C
    if (ctx->r2 == ctx->r1) {
        // 0x800A7B30: addiu       $at, $zero, 0xA9
        ctx->r1 = ADD32(0, 0XA9);
            goto L_800A7B4C;
    }
    // 0x800A7B30: addiu       $at, $zero, 0xA9
    ctx->r1 = ADD32(0, 0XA9);
    // 0x800A7B34: beq         $v0, $at, L_800A7B4C
    if (ctx->r2 == ctx->r1) {
        // 0x800A7B38: addiu       $at, $zero, 0x457
        ctx->r1 = ADD32(0, 0X457);
            goto L_800A7B4C;
    }
    // 0x800A7B38: addiu       $at, $zero, 0x457
    ctx->r1 = ADD32(0, 0X457);
    // 0x800A7B3C: beq         $v0, $at, L_800A7B4C
    if (ctx->r2 == ctx->r1) {
        // 0x800A7B40: addiu       $at, $zero, 0x458
        ctx->r1 = ADD32(0, 0X458);
            goto L_800A7B4C;
    }
    // 0x800A7B40: addiu       $at, $zero, 0x458
    ctx->r1 = ADD32(0, 0X458);
    // 0x800A7B44: bnel        $v0, $at, L_800A80E8
    if (ctx->r2 != ctx->r1) {
        // 0x800A7B48: lh          $t4, 0xD0($sp)
        ctx->r12 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A80E8;
    }
    goto skip_24;
    // 0x800A7B48: lh          $t4, 0xD0($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XD0));
    skip_24:
L_800A7B4C:
    // 0x800A7B4C: jal         0x800AF77C
    // 0x800A7B50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    checkhitswitch(rdram, ctx);
        goto after_53;
    // 0x800A7B50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_53:
    // 0x800A7B54: b           L_800A9D2C
    // 0x800A7B58: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A7B58: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A7B5C:
    // 0x800A7B5C: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7B60: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800A7B64: bltz        $t5, L_800A80E4
    if (SIGNED(ctx->r13) < 0) {
        // 0x800A7B68: sll         $t9, $t5, 3
        ctx->r25 = S32(ctx->r13 << 3);
            goto L_800A80E4;
    }
    // 0x800A7B68: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x800A7B6C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800A7B70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A7B74: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800A7B78: jal         0x800ACC8C
    // 0x800A7B7C: lh          $a0, 0x61B8($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X61B8));
    isadoorwall(rdram, ctx);
        goto after_54;
    // 0x800A7B7C: lh          $a0, 0x61B8($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X61B8));
    after_54:
    // 0x800A7B80: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A7B84: bne         $v1, $v0, L_800A7BAC
    if (ctx->r3 != ctx->r2) {
        // 0x800A7B88: lh          $t8, 0xD0($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A7BAC;
    }
    // 0x800A7B88: lh          $t8, 0xD0($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7B8C: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800A7B90: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800A7B94: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x800A7B98: addiu       $t3, $t3, 0x61A8
    ctx->r11 = ADD32(ctx->r11, 0X61A8);
    // 0x800A7B9C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A7BA0: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    // 0x800A7BA4: b           L_800A7F74
    // 0x800A7BA8: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
        goto L_800A7F74;
    // 0x800A7BA8: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
L_800A7BAC:
    // 0x800A7BAC: lh          $t6, 0xCA($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A7BB0: bltzl       $t6, L_800A7C34
    if (SIGNED(ctx->r14) < 0) {
        // 0x800A7BB4: lh          $t5, 0xD0($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A7C34;
    }
    goto skip_25;
    // 0x800A7BB4: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
    skip_25:
    // 0x800A7BB8: lh          $t7, 0xD0($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7BBC: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800A7BC0: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x800A7BC4: sll         $t2, $t7, 3
    ctx->r10 = S32(ctx->r15 << 3);
    // 0x800A7BC8: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x800A7BCC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A7BD0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800A7BD4: lh          $v0, 0x61B8($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X61B8));
    // 0x800A7BD8: lh          $a0, 0xCA($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A7BDC: lh          $a1, 0xD0($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7BE0: beq         $v0, $at, L_800A7C20
    if (ctx->r2 == ctx->r1) {
        // 0x800A7BE4: addiu       $at, $zero, 0xA3
        ctx->r1 = ADD32(0, 0XA3);
            goto L_800A7C20;
    }
    // 0x800A7BE4: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x800A7BE8: beq         $v0, $at, L_800A7C20
    if (ctx->r2 == ctx->r1) {
        // 0x800A7BEC: addiu       $at, $zero, 0xA4
        ctx->r1 = ADD32(0, 0XA4);
            goto L_800A7C20;
    }
    // 0x800A7BEC: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x800A7BF0: beq         $v0, $at, L_800A7C20
    if (ctx->r2 == ctx->r1) {
        // 0x800A7BF4: addiu       $at, $zero, 0xA5
        ctx->r1 = ADD32(0, 0XA5);
            goto L_800A7C20;
    }
    // 0x800A7BF4: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x800A7BF8: beq         $v0, $at, L_800A7C20
    if (ctx->r2 == ctx->r1) {
        // 0x800A7BFC: addiu       $at, $zero, 0xA8
        ctx->r1 = ADD32(0, 0XA8);
            goto L_800A7C20;
    }
    // 0x800A7BFC: addiu       $at, $zero, 0xA8
    ctx->r1 = ADD32(0, 0XA8);
    // 0x800A7C00: beq         $v0, $at, L_800A7C20
    if (ctx->r2 == ctx->r1) {
        // 0x800A7C04: addiu       $at, $zero, 0xA9
        ctx->r1 = ADD32(0, 0XA9);
            goto L_800A7C20;
    }
    // 0x800A7C04: addiu       $at, $zero, 0xA9
    ctx->r1 = ADD32(0, 0XA9);
    // 0x800A7C08: beq         $v0, $at, L_800A7C20
    if (ctx->r2 == ctx->r1) {
        // 0x800A7C0C: addiu       $at, $zero, 0x457
        ctx->r1 = ADD32(0, 0X457);
            goto L_800A7C20;
    }
    // 0x800A7C0C: addiu       $at, $zero, 0x457
    ctx->r1 = ADD32(0, 0X457);
    // 0x800A7C10: beq         $v0, $at, L_800A7C20
    if (ctx->r2 == ctx->r1) {
        // 0x800A7C14: addiu       $at, $zero, 0x458
        ctx->r1 = ADD32(0, 0X458);
            goto L_800A7C20;
    }
    // 0x800A7C14: addiu       $at, $zero, 0x458
    ctx->r1 = ADD32(0, 0X458);
    // 0x800A7C18: bnel        $v0, $at, L_800A7C34
    if (ctx->r2 != ctx->r1) {
        // 0x800A7C1C: lh          $t5, 0xD0($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A7C34;
    }
    goto skip_26;
    // 0x800A7C1C: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
    skip_26:
L_800A7C20:
    // 0x800A7C20: jal         0x800AF77C
    // 0x800A7C24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    checkhitswitch(rdram, ctx);
        goto after_55;
    // 0x800A7C24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_55:
    // 0x800A7C28: b           L_800A9D2C
    // 0x800A7C2C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A7C2C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800A7C30: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
L_800A7C34:
    // 0x800A7C34: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x800A7C38: lh          $t4, -0x9DC($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X9DC));
    // 0x800A7C3C: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x800A7C40: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800A7C44: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800A7C48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A7C4C: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x800A7C50: beq         $v1, $t4, L_800A7C60
    if (ctx->r3 == ctx->r12) {
        // 0x800A7C54: addu        $a2, $t9, $t8
        ctx->r6 = ADD32(ctx->r25, ctx->r24);
            goto L_800A7C60;
    }
    // 0x800A7C54: addu        $a2, $t9, $t8
    ctx->r6 = ADD32(ctx->r25, ctx->r24);
    // 0x800A7C58: b           L_800A7F74
    // 0x800A7C5C: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
        goto L_800A7F74;
    // 0x800A7C5C: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
L_800A7C60:
    // 0x800A7C60: lh          $t3, 0x16($a2)
    ctx->r11 = S32(MEM_H(ctx->r6, 0X16));
    // 0x800A7C64: bne         $t3, $zero, L_800A7C94
    if (ctx->r11 != 0) {
        // 0x800A7C68: nop
    
            goto L_800A7C94;
    }
    // 0x800A7C68: nop

    // 0x800A7C6C: lh          $v0, 0xA($a2)
    ctx->r2 = S32(MEM_H(ctx->r6, 0XA));
    // 0x800A7C70: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800A7C74: bltz        $v0, L_800A7C9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A7C78: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800A7C9C;
    }
    // 0x800A7C78: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800A7C7C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800A7C80: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A7C84: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800A7C88: lh          $t7, 0x61BE($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X61BE));
    // 0x800A7C8C: beql        $t7, $zero, L_800A7CA0
    if (ctx->r15 == 0) {
        // 0x800A7C90: lh          $v0, 0xD4($sp)
        ctx->r2 = S32(MEM_H(ctx->r29, 0XD4));
            goto L_800A7CA0;
    }
    goto skip_27;
    // 0x800A7C90: lh          $v0, 0xD4($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0XD4));
    skip_27:
L_800A7C94:
    // 0x800A7C94: b           L_800A7F74
    // 0x800A7C98: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
        goto L_800A7F74;
    // 0x800A7C98: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
L_800A7C9C:
    // 0x800A7C9C: lh          $v0, 0xD4($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0XD4));
L_800A7CA0:
    // 0x800A7CA0: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800A7CA4: addiu       $t5, $t5, -0x1988
    ctx->r13 = ADD32(ctx->r13, -0X1988);
    // 0x800A7CA8: bltz        $v0, L_800A7F70
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A7CAC: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_800A7F70;
    }
    // 0x800A7CAC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800A7CB0: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800A7CB4: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800A7CB8: addu        $t9, $t2, $t5
    ctx->r25 = ADD32(ctx->r10, ctx->r13);
    // 0x800A7CBC: lh          $v1, 0x18($t9)
    ctx->r3 = S32(MEM_H(ctx->r25, 0X18));
    // 0x800A7CC0: bnel        $v1, $zero, L_800A7F74
    if (ctx->r3 != 0) {
        // 0x800A7CC4: lh          $a1, 0xE($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800A7F74;
    }
    goto skip_28;
    // 0x800A7CC4: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
    skip_28:
    // 0x800A7CC8: lh          $t8, 0x12($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0X12));
    // 0x800A7CCC: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x800A7CD0: beql        $t8, $at, L_800A7F74
    if (ctx->r24 == ctx->r1) {
        // 0x800A7CD4: lh          $a1, 0xE($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800A7F74;
    }
    goto skip_29;
    // 0x800A7CD4: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
    skip_29:
    // 0x800A7CD8: lh          $v0, 0xC($a2)
    ctx->r2 = S32(MEM_H(ctx->r6, 0XC));
    // 0x800A7CDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7CE0: bltz        $v0, L_800A7D00
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A7CE4: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_800A7D00;
    }
    // 0x800A7CE4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800A7CE8: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x800A7CEC: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800A7CF0: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x800A7CF4: lh          $t6, 0x18($t3)
    ctx->r14 = S32(MEM_H(ctx->r11, 0X18));
    // 0x800A7CF8: beql        $t6, $zero, L_800A7D14
    if (ctx->r14 == 0) {
        // 0x800A7CFC: lh          $a1, 0xE($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800A7D14;
    }
    goto skip_30;
    // 0x800A7CFC: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
    skip_30:
L_800A7D00:
    // 0x800A7D00: bnel        $v0, $at, L_800A7F74
    if (ctx->r2 != ctx->r1) {
        // 0x800A7D04: lh          $a1, 0xE($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800A7F74;
    }
    goto skip_31;
    // 0x800A7D04: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
    skip_31:
    // 0x800A7D08: bnel        $v1, $zero, L_800A7F74
    if (ctx->r3 != 0) {
        // 0x800A7D0C: lh          $a1, 0xE($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800A7F74;
    }
    goto skip_32;
    // 0x800A7D0C: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
    skip_32:
    // 0x800A7D10: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
L_800A7D14:
    // 0x800A7D14: andi        $t7, $a1, 0x10
    ctx->r15 = ctx->r5 & 0X10;
    // 0x800A7D18: bnel        $t7, $zero, L_800A7F74
    if (ctx->r15 != 0) {
        // 0x800A7D1C: lh          $a1, 0xE($a2)
        ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800A7F74;
    }
    goto skip_33;
    // 0x800A7D1C: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
    skip_33:
    // 0x800A7D20: bltz        $v0, L_800A7D80
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A7D24: sll         $t2, $v0, 1
        ctx->r10 = S32(ctx->r2 << 1);
            goto L_800A7D80;
    }
    // 0x800A7D24: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x800A7D28: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800A7D2C: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x800A7D30: lh          $s0, 0x2330($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X2330));
    // 0x800A7D34: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800A7D38: addiu       $v1, $v1, 0x4FA0
    ctx->r3 = ADD32(ctx->r3, 0X4FA0);
    // 0x800A7D3C: bltz        $s0, L_800A7D80
    if (SIGNED(ctx->r16) < 0) {
        // 0x800A7D40: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_800A7D80;
    }
    // 0x800A7D40: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_800A7D44:
    // 0x800A7D44: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7D48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A7D4C: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x800A7D50: addu        $t3, $v1, $t5
    ctx->r11 = ADD32(ctx->r3, ctx->r13);
    // 0x800A7D54: mflo        $t9
    ctx->r25 = lo;
    // 0x800A7D58: addu        $a0, $s5, $t9
    ctx->r4 = ADD32(ctx->r21, ctx->r25);
    // 0x800A7D5C: lh          $t8, 0x12($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X12));
    // 0x800A7D60: bnel        $t8, $at, L_800A7D78
    if (ctx->r24 != ctx->r1) {
        // 0x800A7D64: lh          $s0, 0x0($t3)
        ctx->r16 = S32(MEM_H(ctx->r11, 0X0));
            goto L_800A7D78;
    }
    goto skip_34;
    // 0x800A7D64: lh          $s0, 0x0($t3)
    ctx->r16 = S32(MEM_H(ctx->r11, 0X0));
    skip_34:
    // 0x800A7D68: lh          $t4, 0x1E($a0)
    ctx->r12 = S32(MEM_H(ctx->r4, 0X1E));
    // 0x800A7D6C: beql        $v0, $t4, L_800A7F78
    if (ctx->r2 == ctx->r12) {
        // 0x800A7D70: andi        $t3, $a1, 0x2
        ctx->r11 = ctx->r5 & 0X2;
            goto L_800A7F78;
    }
    goto skip_35;
    // 0x800A7D70: andi        $t3, $a1, 0x2
    ctx->r11 = ctx->r5 & 0X2;
    skip_35:
    // 0x800A7D74: lh          $s0, 0x0($t3)
    ctx->r16 = S32(MEM_H(ctx->r11, 0X0));
L_800A7D78:
    // 0x800A7D78: bgez        $s0, L_800A7D44
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800A7D7C: nop
    
            goto L_800A7D44;
    }
    // 0x800A7D7C: nop

L_800A7D80:
    // 0x800A7D80: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800A7D84: lh          $s0, 0x2862($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X2862));
    // 0x800A7D88: bltzl       $s0, L_800A7E6C
    if (SIGNED(ctx->r16) < 0) {
        // 0x800A7D8C: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_800A7E6C;
    }
    goto skip_36;
    // 0x800A7D8C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    skip_36:
L_800A7D90:
    // 0x800A7D90: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7D94: addiu       $at, $zero, 0x3B8
    ctx->r1 = ADD32(0, 0X3B8);
    // 0x800A7D98: mflo        $t6
    ctx->r14 = lo;
    // 0x800A7D9C: addu        $a0, $s5, $t6
    ctx->r4 = ADD32(ctx->r21, ctx->r14);
    // 0x800A7DA0: lh          $t7, 0xE($a0)
    ctx->r15 = S32(MEM_H(ctx->r4, 0XE));
    // 0x800A7DA4: bne         $t7, $at, L_800A7E50
    if (ctx->r15 != ctx->r1) {
        // 0x800A7DA8: addiu       $at, $zero, 0xA26
        ctx->r1 = ADD32(0, 0XA26);
            goto L_800A7E50;
    }
    // 0x800A7DA8: addiu       $at, $zero, 0xA26
    ctx->r1 = ADD32(0, 0XA26);
    // 0x800A7DAC: beq         $s4, $at, L_800A7DBC
    if (ctx->r20 == ctx->r1) {
        // 0x800A7DB0: addiu       $at, $zero, 0xA27
        ctx->r1 = ADD32(0, 0XA27);
            goto L_800A7DBC;
    }
    // 0x800A7DB0: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
    // 0x800A7DB4: bne         $s4, $at, L_800A7E04
    if (ctx->r20 != ctx->r1) {
        // 0x800A7DB8: nop
    
            goto L_800A7E04;
    }
    // 0x800A7DB8: nop

L_800A7DBC:
    // 0x800A7DBC: jal         0x800ACEC8
    // 0x800A7DC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    dist(rdram, ctx);
        goto after_56;
    // 0x800A7DC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_56:
    // 0x800A7DC4: jal         0x8009800C
    // 0x800A7DC8: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    krand2(rdram, ctx);
        goto after_57;
    // 0x800A7DC8: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    after_57:
    // 0x800A7DCC: lw          $v1, 0x84($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800A7DD0: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x800A7DD4: addiu       $t9, $t2, 0x24
    ctx->r25 = ADD32(ctx->r10, 0X24);
    // 0x800A7DD8: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A7DDC: beq         $at, $zero, L_800A7E50
    if (ctx->r1 == 0) {
        // 0x800A7DE0: lh          $t8, 0xD0($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A7E50;
    }
    // 0x800A7DE0: lh          $t8, 0xD0($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7DE4: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800A7DE8: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800A7DEC: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800A7DF0: addiu       $t5, $t5, 0x61A8
    ctx->r13 = ADD32(ctx->r13, 0X61A8);
    // 0x800A7DF4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A7DF8: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800A7DFC: b           L_800A7F74
    // 0x800A7E00: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
        goto L_800A7F74;
    // 0x800A7E00: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
L_800A7E04:
    // 0x800A7E04: jal         0x800ACEC8
    // 0x800A7E08: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    dist(rdram, ctx);
        goto after_58;
    // 0x800A7E08: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_58:
    // 0x800A7E0C: jal         0x8009800C
    // 0x800A7E10: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    krand2(rdram, ctx);
        goto after_59;
    // 0x800A7E10: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    after_59:
    // 0x800A7E14: lw          $v1, 0x84($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800A7E18: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x800A7E1C: addiu       $t6, $t3, 0xC
    ctx->r14 = ADD32(ctx->r11, 0XC);
    // 0x800A7E20: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A7E24: beql        $at, $zero, L_800A7E54
    if (ctx->r1 == 0) {
        // 0x800A7E28: sll         $t8, $s0, 1
        ctx->r24 = S32(ctx->r16 << 1);
            goto L_800A7E54;
    }
    goto skip_37;
    // 0x800A7E28: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    skip_37:
    // 0x800A7E2C: lh          $t7, 0xD0($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7E30: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800A7E34: addiu       $t9, $t9, 0x61A8
    ctx->r25 = ADD32(ctx->r25, 0X61A8);
    // 0x800A7E38: sll         $t2, $t7, 3
    ctx->r10 = S32(ctx->r15 << 3);
    // 0x800A7E3C: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x800A7E40: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A7E44: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
    // 0x800A7E48: b           L_800A7F74
    // 0x800A7E4C: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
        goto L_800A7F74;
    // 0x800A7E4C: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
L_800A7E50:
    // 0x800A7E50: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
L_800A7E54:
    // 0x800A7E54: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800A7E58: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x800A7E5C: lh          $s0, 0x5F40($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X5F40));
    // 0x800A7E60: bgez        $s0, L_800A7D90
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800A7E64: nop
    
            goto L_800A7D90;
    }
    // 0x800A7E64: nop

    // 0x800A7E68: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
L_800A7E6C:
    // 0x800A7E6C: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A7E70: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800A7E74: jal         0x8009D240
    // 0x800A7E78: addiu       $a1, $zero, 0x3B8
    ctx->r5 = ADD32(0, 0X3B8);
    spawn(rdram, ctx);
        goto after_60;
    // 0x800A7E78: addiu       $a1, $zero, 0x3B8
    ctx->r5 = ADD32(0, 0X3B8);
    after_60:
    // 0x800A7E7C: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7E80: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800A7E84: addiu       $t9, $t9, 0x61A8
    ctx->r25 = ADD32(ctx->r25, 0X61A8);
    // 0x800A7E88: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x800A7E8C: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800A7E90: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x800A7E94: mflo        $t3
    ctx->r11 = lo;
    // 0x800A7E98: addu        $t6, $s5, $t3
    ctx->r14 = ADD32(ctx->r21, ctx->r11);
    // 0x800A7E9C: sh          $zero, 0x18($t6)
    MEM_H(0X18, ctx->r14) = 0;
    // 0x800A7EA0: lh          $t7, 0xD0($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7EA4: sll         $t2, $t7, 3
    ctx->r10 = S32(ctx->r15 << 3);
    // 0x800A7EA8: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x800A7EAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A7EB0: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
    // 0x800A7EB4: lh          $t8, 0x8($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0X8));
    // 0x800A7EB8: lw          $t5, 0x0($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A7EBC: lw          $t6, 0x4($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A7EC0: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800A7EC4: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800A7EC8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A7ECC: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800A7ED0: lw          $t3, 0x0($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800A7ED4: lw          $t7, 0x4($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800A7ED8: subu        $a0, $t5, $t3
    ctx->r4 = SUB32(ctx->r13, ctx->r11);
    // 0x800A7EDC: jal         0x80092024
    // 0x800A7EE0: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    getangle(rdram, ctx);
        goto after_61;
    // 0x800A7EE0: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    after_61:
    // 0x800A7EE4: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7EE8: addiu       $t8, $v0, 0x200
    ctx->r24 = ADD32(ctx->r2, 0X200);
    // 0x800A7EEC: addiu       $at, $zero, 0xA26
    ctx->r1 = ADD32(0, 0XA26);
    // 0x800A7EF0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800A7EF4: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x800A7EF8: mflo        $t2
    ctx->r10 = lo;
    // 0x800A7EFC: addu        $a0, $s5, $t2
    ctx->r4 = ADD32(ctx->r21, ctx->r10);
    // 0x800A7F00: sh          $t8, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r24;
    // 0x800A7F04: lh          $t4, 0x14($a0)
    ctx->r12 = S32(MEM_H(ctx->r4, 0X14));
    // 0x800A7F08: addiu       $t9, $t4, 0x400
    ctx->r25 = ADD32(ctx->r12, 0X400);
    // 0x800A7F0C: andi        $t5, $t9, 0x7FF
    ctx->r13 = ctx->r25 & 0X7FF;
    // 0x800A7F10: beq         $s4, $at, L_800A7F24
    if (ctx->r20 == ctx->r1) {
        // 0x800A7F14: sh          $t5, 0x14($a0)
        MEM_H(0X14, ctx->r4) = ctx->r13;
            goto L_800A7F24;
    }
    // 0x800A7F14: sh          $t5, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r13;
    // 0x800A7F18: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
    // 0x800A7F1C: bnel        $s4, $at, L_800A7F48
    if (ctx->r20 != ctx->r1) {
        // 0x800A7F20: sll         $a0, $s0, 16
        ctx->r4 = S32(ctx->r16 << 16);
            goto L_800A7F48;
    }
    goto skip_38;
    // 0x800A7F20: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    skip_38:
L_800A7F24:
    // 0x800A7F24: lbu         $t3, 0x27($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X27);
    // 0x800A7F28: lbu         $t7, 0x28($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X28);
    // 0x800A7F2C: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800A7F30: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x800A7F34: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x800A7F38: subu        $t2, $t2, $t7
    ctx->r10 = SUB32(ctx->r10, ctx->r15);
    // 0x800A7F3C: sb          $t6, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r14;
    // 0x800A7F40: sb          $t2, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r10;
    // 0x800A7F44: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
L_800A7F48:
    // 0x800A7F48: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A7F4C: jal         0x80076190
    // 0x800A7F50: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    ssp(rdram, ctx);
        goto after_62;
    // 0x800A7F50: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_62:
    // 0x800A7F54: lh          $t4, 0xD0($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7F58: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800A7F5C: addiu       $t5, $t5, 0x61A8
    ctx->r13 = ADD32(ctx->r13, 0X61A8);
    // 0x800A7F60: sll         $t9, $t4, 3
    ctx->r25 = S32(ctx->r12 << 3);
    // 0x800A7F64: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x800A7F68: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A7F6C: addu        $a2, $t9, $t5
    ctx->r6 = ADD32(ctx->r25, ctx->r13);
L_800A7F70:
    // 0x800A7F70: lh          $a1, 0xE($a2)
    ctx->r5 = S32(MEM_H(ctx->r6, 0XE));
L_800A7F74:
    // 0x800A7F74: andi        $t3, $a1, 0x2
    ctx->r11 = ctx->r5 & 0X2;
L_800A7F78:
    // 0x800A7F78: beq         $t3, $zero, L_800A7FB8
    if (ctx->r11 == 0) {
        // 0x800A7F7C: sll         $a0, $s2, 16
        ctx->r4 = S32(ctx->r18 << 16);
            goto L_800A7FB8;
    }
    // 0x800A7F7C: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A7F80: lh          $v0, 0xC($a2)
    ctx->r2 = S32(MEM_H(ctx->r6, 0XC));
    // 0x800A7F84: lw          $t6, 0xA4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A7F88: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x800A7F8C: bltz        $v0, L_800A7FB8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A7F90: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_800A7FB8;
    }
    // 0x800A7F90: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800A7F94: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800A7F98: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800A7F9C: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x800A7FA0: lw          $t2, -0x1984($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X1984));
    // 0x800A7FA4: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A7FA8: bnel        $at, $zero, L_800A7FBC
    if (ctx->r1 != 0) {
        // 0x800A7FAC: lw          $t9, 0xA4($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0XA4));
            goto L_800A7FBC;
    }
    goto skip_39;
    // 0x800A7FAC: lw          $t9, 0xA4($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA4));
    skip_39:
    // 0x800A7FB0: lh          $t8, 0xA($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0XA));
    // 0x800A7FB4: sh          $t8, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = ctx->r24;
L_800A7FB8:
    // 0x800A7FB8: lw          $t9, 0xA4($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA4));
L_800A7FBC:
    // 0x800A7FBC: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A7FC0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800A7FC4: lh          $a1, 0xD0($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A7FC8: lw          $a2, 0xAC($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A7FCC: lw          $a3, 0xA8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A7FD0: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800A7FD4: jal         0x800B06B8
    // 0x800A7FD8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    checkhitwall(rdram, ctx);
        goto after_63;
    // 0x800A7FD8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_63:
    // 0x800A7FDC: b           L_800A80E8
    // 0x800A7FE0: lh          $t4, 0xD0($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XD0));
        goto L_800A80E8;
    // 0x800A7FE0: lh          $t4, 0xD0($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XD0));
L_800A7FE4:
    // 0x800A7FE4: lh          $t6, 0xDA($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A7FE8: addiu       $t5, $zero, -0xF
    ctx->r13 = ADD32(0, -0XF);
    // 0x800A7FEC: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x800A7FF0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800A7FF4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A7FF8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A7FFC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A8000: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A8004: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A8008: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A800C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800A8010: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A8014: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A8018: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A801C: jal         0x8009B028
    // 0x800A8020: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    EGS(rdram, ctx);
        goto after_64;
    // 0x800A8020: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_64:
    // 0x800A8024: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8028: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800A802C: addiu       $t7, $t7, -0x447C
    ctx->r15 = ADD32(ctx->r15, -0X447C);
    // 0x800A8030: sll         $t3, $s4, 1
    ctx->r11 = S32(ctx->r20 << 1);
    // 0x800A8034: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x800A8038: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x800A803C: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800A8040: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800A8044: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A8048: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800A804C: mflo        $t4
    ctx->r12 = lo;
    // 0x800A8050: addu        $v1, $s5, $t4
    ctx->r3 = ADD32(ctx->r21, ctx->r12);
    // 0x800A8054: lh          $t9, 0xC($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0XC));
    // 0x800A8058: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800A805C: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x800A8060: ori         $t5, $t9, 0x80
    ctx->r13 = ctx->r25 | 0X80;
    // 0x800A8064: sh          $t5, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r13;
    // 0x800A8068: lh          $t2, 0x0($t6)
    ctx->r10 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800A806C: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A8070: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800A8074: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x800A8078: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800A807C: lw          $t4, -0x1700($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X1700));
    // 0x800A8080: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800A8084: bltz        $a3, L_800A80B0
    if (SIGNED(ctx->r7) < 0) {
        // 0x800A8088: sh          $t4, 0x22($v1)
        MEM_H(0X22, ctx->r3) = ctx->r12;
            goto L_800A80B0;
    }
    // 0x800A8088: sh          $t4, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r12;
    // 0x800A808C: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A8090: jal         0x800B177C
    // 0x800A8094: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    checkhitsprite(rdram, ctx);
        goto after_65;
    // 0x800A8094: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_65:
    // 0x800A8098: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A809C: mflo        $t3
    ctx->r11 = lo;
    // 0x800A80A0: addu        $s1, $s5, $t3
    ctx->r17 = ADD32(ctx->r21, ctx->r11);
    // 0x800A80A4: sb          $zero, 0x28($s1)
    MEM_B(0X28, ctx->r17) = 0;
    // 0x800A80A8: b           L_800A80E4
    // 0x800A80AC: sb          $zero, 0x27($s1)
    MEM_B(0X27, ctx->r17) = 0;
        goto L_800A80E4;
    // 0x800A80AC: sb          $zero, 0x27($s1)
    MEM_B(0X27, ctx->r17) = 0;
L_800A80B0:
    // 0x800A80B0: lh          $t6, 0xD0($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A80B4: bltzl       $t6, L_800A80E8
    if (SIGNED(ctx->r14) < 0) {
        // 0x800A80B8: lh          $t4, 0xD0($sp)
        ctx->r12 = S32(MEM_H(ctx->r29, 0XD0));
            goto L_800A80E8;
    }
    goto skip_40;
    // 0x800A80B8: lh          $t4, 0xD0($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XD0));
    skip_40:
    // 0x800A80BC: lw          $t8, 0xA4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A80C0: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A80C4: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A80C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800A80CC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800A80D0: lw          $a2, 0xAC($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A80D4: lw          $a3, 0xA8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A80D8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800A80DC: jal         0x800B06B8
    // 0x800A80E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    checkhitwall(rdram, ctx);
        goto after_66;
    // 0x800A80E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_66:
L_800A80E4:
    // 0x800A80E4: lh          $t4, 0xD0($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XD0));
L_800A80E8:
    // 0x800A80E8: bltzl       $t4, L_800A9D2C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800A80EC: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_41;
    // 0x800A80EC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_41:
    // 0x800A80F0: jal         0x8009800C
    // 0x800A80F4: nop

    krand2(rdram, ctx);
        goto after_67;
    // 0x800A80F4: nop

    after_67:
    // 0x800A80F8: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x800A80FC: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x800A8100: beq         $at, $zero, L_800A9D28
    if (ctx->r1 == 0) {
        // 0x800A8104: lw          $t5, 0x68($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X68));
            goto L_800A9D28;
    }
    // 0x800A8104: lw          $t5, 0x68($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X68));
    // 0x800A8108: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x800A810C: addiu       $t3, $t3, -0x302E
    ctx->r11 = ADD32(ctx->r11, -0X302E);
    // 0x800A8110: beq         $t5, $t3, L_800A9D28
    if (ctx->r13 == ctx->r11) {
        // 0x800A8114: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_800A9D28;
    }
    // 0x800A8114: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800A8118: addiu       $t7, $t7, -0x3034
    ctx->r15 = ADD32(ctx->r15, -0X3034);
    // 0x800A811C: beql        $t5, $t7, L_800A9D2C
    if (ctx->r13 == ctx->r15) {
        // 0x800A8120: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_42;
    // 0x800A8120: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_42:
    // 0x800A8124: jal         0x8009800C
    // 0x800A8128: nop

    krand2(rdram, ctx);
        goto after_68;
    // 0x800A8128: nop

    after_68:
    // 0x800A812C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A8130: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800A8134: mfhi        $t1
    ctx->r9 = hi;
    // 0x800A8138: addiu       $t1, $t1, 0x110
    ctx->r9 = ADD32(ctx->r9, 0X110);
    // 0x800A813C: lw          $t8, 0xA4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A8140: sll         $a0, $t1, 16
    ctx->r4 = S32(ctx->r9 << 16);
    // 0x800A8144: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800A8148: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A814C: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A8150: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800A8154: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800A8158: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x800A815C: lw          $a2, 0xAC($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A8160: lw          $a3, 0xA8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A8164: jal         0x80058A48
    // 0x800A8168: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    xyzsound(rdram, ctx);
        goto after_69;
    // 0x800A8168: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_69:
    // 0x800A816C: b           L_800A9D2C
    // 0x800A8170: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A8170: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A8174:
    // 0x800A8174: lh          $t4, 0x22($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800A8178: addiu       $t9, $zero, -0x60
    ctx->r25 = ADD32(0, -0X60);
    // 0x800A817C: addiu       $at, $zero, 0x664
    ctx->r1 = ADD32(0, 0X664);
    // 0x800A8180: bltz        $t4, L_800A818C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800A8184: addiu       $t3, $zero, 0x124
        ctx->r11 = ADD32(0, 0X124);
            goto L_800A818C;
    }
    // 0x800A8184: addiu       $t3, $zero, 0x124
    ctx->r11 = ADD32(0, 0X124);
    // 0x800A8188: sb          $t9, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r25;
L_800A818C:
    // 0x800A818C: bne         $s4, $at, L_800A819C
    if (ctx->r20 != ctx->r1) {
        // 0x800A8190: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800A819C;
    }
    // 0x800A8190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A8194: b           L_800A8270
    // 0x800A8198: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
        goto L_800A8270;
    // 0x800A8198: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
L_800A819C:
    // 0x800A819C: bnel        $s4, $v1, L_800A8260
    if (ctx->r20 != ctx->r3) {
        // 0x800A81A0: lw          $t4, 0xB8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
            goto L_800A8260;
    }
    goto skip_43;
    // 0x800A81A0: lw          $t4, 0xB8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
    skip_43:
    // 0x800A81A4: lh          $t5, 0xE($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800A81A8: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    // 0x800A81AC: bnel        $t5, $at, L_800A8248
    if (ctx->r13 != ctx->r1) {
        // 0x800A81B0: lw          $t5, 0xB8($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0XB8));
            goto L_800A8248;
    }
    goto skip_44;
    // 0x800A81B0: lw          $t5, 0xB8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB8));
    skip_44:
    // 0x800A81B4: lw          $t2, 0xB8($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A81B8: lui         $at, 0x40C8
    ctx->r1 = S32(0X40C8 << 16);
    // 0x800A81BC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A81C0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A81C4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A81C8: addiu       $t4, $s3, 0x200
    ctx->r12 = ADD32(ctx->r19, 0X200);
    // 0x800A81CC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A81D0: addiu       $t7, $zero, 0x284
    ctx->r15 = ADD32(0, 0X284);
    // 0x800A81D4: andi        $t9, $t4, 0x7FF
    ctx->r25 = ctx->r12 & 0X7FF;
    // 0x800A81D8: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x800A81DC: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x800A81E0: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x800A81E4: addiu       $t5, $t5, -0x9A0
    ctx->r13 = ADD32(ctx->r13, -0X9A0);
    // 0x800A81E8: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x800A81EC: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800A81F0: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800A81F4: addiu       $v0, $zero, 0x3F8
    ctx->r2 = ADD32(0, 0X3F8);
    // 0x800A81F8: lw          $t8, 0xC0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A81FC: lw          $t3, 0xBC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A8200: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    // 0x800A8204: lh          $t2, 0x0($t7)
    ctx->r10 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800A8208: andi        $t7, $s3, 0x7FF
    ctx->r15 = ctx->r19 & 0X7FF;
    // 0x800A820C: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8210: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x800A8214: mflo        $t6
    ctx->r14 = lo;
    // 0x800A8218: sra         $t4, $t6, 14
    ctx->r12 = S32(SIGNED(ctx->r14) >> 14);
    // 0x800A821C: addu        $t9, $t8, $t4
    ctx->r25 = ADD32(ctx->r24, ctx->r12);
    // 0x800A8220: sw          $t9, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r25;
    // 0x800A8224: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800A8228: lh          $t8, 0x0($t6)
    ctx->r24 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800A822C: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8230: mflo        $t4
    ctx->r12 = lo;
    // 0x800A8234: sra         $t9, $t4, 14
    ctx->r25 = S32(SIGNED(ctx->r12) >> 14);
    // 0x800A8238: addu        $t7, $t3, $t9
    ctx->r15 = ADD32(ctx->r11, ctx->r25);
    // 0x800A823C: b           L_800A8270
    // 0x800A8240: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
        goto L_800A8270;
    // 0x800A8240: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x800A8244: lw          $t5, 0xB8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB8));
L_800A8248:
    // 0x800A8248: addiu       $t2, $zero, 0x15C
    ctx->r10 = ADD32(0, 0X15C);
    // 0x800A824C: sw          $t2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r10;
    // 0x800A8250: addiu       $t6, $t5, -0x200
    ctx->r14 = ADD32(ctx->r13, -0X200);
    // 0x800A8254: b           L_800A8270
    // 0x800A8258: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
        goto L_800A8270;
    // 0x800A8258: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x800A825C: lw          $t4, 0xB8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
L_800A8260:
    // 0x800A8260: addiu       $t8, $zero, 0x348
    ctx->r24 = ADD32(0, 0X348);
    // 0x800A8264: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x800A8268: addiu       $t3, $t4, -0x200
    ctx->r11 = ADD32(ctx->r12, -0X200);
    // 0x800A826C: sw          $t3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r11;
L_800A8270:
    // 0x800A8270: bltz        $t1, L_800A83C4
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A8274: addiu       $a1, $sp, 0xA0
        ctx->r5 = ADD32(ctx->r29, 0XA0);
            goto L_800A83C4;
    }
    // 0x800A8274: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x800A8278: sll         $t9, $t1, 3
    ctx->r25 = S32(ctx->r9 << 3);
    // 0x800A827C: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x800A8280: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800A8284: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x800A8288: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A828C: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x800A8290: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800A8294: addiu       $t7, $t7, 0x5770
    ctx->r15 = ADD32(ctx->r15, 0X5770);
    // 0x800A8298: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A829C: addu        $s0, $t9, $t7
    ctx->r16 = ADD32(ctx->r25, ctx->r15);
    // 0x800A82A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A82A4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x800A82A8: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A82AC: jal         0x800A1F14
    // 0x800A82B0: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    aim(rdram, ctx);
        goto after_70;
    // 0x800A82B0: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_70:
    // 0x800A82B4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A82B8: sra         $t2, $s1, 16
    ctx->r10 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A82BC: bltz        $v0, L_800A8398
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A82C0: or          $s1, $t2, $zero
        ctx->r17 = ctx->r10 | 0;
            goto L_800A8398;
    }
    // 0x800A82C0: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800A82C4: multu       $t2, $s6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A82C8: mflo        $t5
    ctx->r13 = lo;
    // 0x800A82CC: addu        $a2, $s5, $t5
    ctx->r6 = ADD32(ctx->r21, ctx->r13);
    // 0x800A82D0: lhu         $a0, 0xE($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XE);
    // 0x800A82D4: jal         0x800B4EA8
    // 0x800A82D8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    gettilesizy(rdram, ctx);
        goto after_71;
    // 0x800A82D8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_71:
    // 0x800A82DC: lw          $a1, 0x70($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A82E0: lh          $t4, 0x2E0($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A82E4: lbu         $t6, 0x27($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X27);
    // 0x800A82E8: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A82EC: mflo        $s2
    ctx->r18 = lo;
    // 0x800A82F0: sll         $t8, $s2, 1
    ctx->r24 = S32(ctx->r18 << 1);
    // 0x800A82F4: addiu       $s2, $t8, -0xC00
    ctx->r18 = ADD32(ctx->r24, -0XC00);
    // 0x800A82F8: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A82FC: mflo        $t3
    ctx->r11 = lo;
    // 0x800A8300: addu        $a0, $s5, $t3
    ctx->r4 = ADD32(ctx->r21, ctx->r11);
    // 0x800A8304: jal         0x800ACE8C
    // 0x800A8308: nop

    ldist(rdram, ctx);
        goto after_72;
    // 0x800A8308: nop

    after_72:
    // 0x800A830C: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A8310: lw          $t7, 0xB8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A8314: lw          $t6, 0xB4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800A8318: lw          $t9, 0x8($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800A831C: lw          $t3, 0xC0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A8320: lw          $t4, 0x0($a2)
    ctx->r12 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A8324: subu        $t2, $t9, $t7
    ctx->r10 = SUB32(ctx->r25, ctx->r15);
    // 0x800A8328: subu        $t5, $t2, $s2
    ctx->r13 = SUB32(ctx->r10, ctx->r18);
    // 0x800A832C: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8330: lw          $t7, 0xBC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A8334: lw          $t9, 0x4($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A8338: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x800A833C: subu        $a1, $t9, $t7
    ctx->r5 = SUB32(ctx->r25, ctx->r15);
    // 0x800A8340: mflo        $t8
    ctx->r24 = lo;
    // 0x800A8344: nop

    // 0x800A8348: nop

    // 0x800A834C: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800A8350: mflo        $t0
    ctx->r8 = lo;
    // 0x800A8354: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A8358: bne         $v0, $zero, L_800A8364
    if (ctx->r2 != 0) {
        // 0x800A835C: nop
    
            goto L_800A8364;
    }
    // 0x800A835C: nop

    // 0x800A8360: break       7
    do_break(2148172640);
L_800A8364:
    // 0x800A8364: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8368: bne         $v0, $at, L_800A837C
    if (ctx->r2 != ctx->r1) {
        // 0x800A836C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A837C;
    }
    // 0x800A836C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8370: bne         $t8, $at, L_800A837C
    if (ctx->r24 != ctx->r1) {
        // 0x800A8374: nop
    
            goto L_800A837C;
    }
    // 0x800A8374: nop

    // 0x800A8378: break       6
    do_break(2148172664);
L_800A837C:
    // 0x800A837C: jal         0x80092024
    // 0x800A8380: nop

    getangle(rdram, ctx);
        goto after_73;
    // 0x800A8380: nop

    after_73:
    // 0x800A8384: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800A8388: sra         $t2, $s3, 16
    ctx->r10 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800A838C: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
    // 0x800A8390: b           L_800A8498
    // 0x800A8394: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
        goto L_800A8498;
    // 0x800A8394: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A8398:
    // 0x800A8398: lw          $t5, 0x220($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A839C: lh          $t8, 0x2B8($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A83A0: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800A83A4: subu        $t0, $t6, $t8
    ctx->r8 = SUB32(ctx->r14, ctx->r24);
    // 0x800A83A8: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800A83AC: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x800A83B0: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800A83B4: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x800A83B8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800A83BC: b           L_800A8498
    // 0x800A83C0: addiu       $t0, $t4, 0x2648
    ctx->r8 = ADD32(ctx->r12, 0X2648);
        goto L_800A8498;
    // 0x800A83C0: addiu       $t0, $t4, 0x2648
    ctx->r8 = ADD32(ctx->r12, 0X2648);
L_800A83C4:
    // 0x800A83C4: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A83C8: jal         0x800ACF18
    // 0x800A83CC: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    findplayer(rdram, ctx);
        goto after_74;
    // 0x800A83CC: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_74:
    // 0x800A83D0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A83D4: sra         $t3, $s1, 16
    ctx->r11 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A83D8: jal         0x8009800C
    // 0x800A83DC: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    krand2(rdram, ctx);
        goto after_75;
    // 0x800A83DC: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    after_75:
    // 0x800A83E0: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    // 0x800A83E4: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800A83E8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800A83EC: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x800A83F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A83F4: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800A83F8: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800A83FC: addiu       $t6, $t6, 0x5770
    ctx->r14 = ADD32(ctx->r14, 0X5770);
    // 0x800A8400: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A8404: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x800A8408: lh          $t8, 0x2E0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A840C: andi        $t9, $v0, 0x1F
    ctx->r25 = ctx->r2 & 0X1F;
    // 0x800A8410: subu        $s3, $s3, $t9
    ctx->r19 = SUB32(ctx->r19, ctx->r25);
    // 0x800A8414: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8418: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x800A841C: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800A8420: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A8424: lw          $t9, 0xC0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A8428: lw          $t2, 0xBC($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A842C: mflo        $t4
    ctx->r12 = lo;
    // 0x800A8430: addu        $v1, $s5, $t4
    ctx->r3 = ADD32(ctx->r21, ctx->r12);
    // 0x800A8434: lw          $t3, 0x0($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800A8438: lw          $t7, 0x4($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800A843C: subu        $a0, $t3, $t9
    ctx->r4 = SUB32(ctx->r11, ctx->r25);
    // 0x800A8440: jal         0x800993E0
    // 0x800A8444: subu        $a1, $t7, $t2
    ctx->r5 = SUB32(ctx->r15, ctx->r10);
    FindDistance2D(rdram, ctx);
        goto after_76;
    // 0x800A8444: subu        $a1, $t7, $t2
    ctx->r5 = SUB32(ctx->r15, ctx->r10);
    after_76:
    // 0x800A8448: lw          $t5, 0x240($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X240));
    // 0x800A844C: lw          $t6, 0xB8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A8450: lw          $t3, 0xB4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800A8454: subu        $t8, $t5, $t6
    ctx->r24 = SUB32(ctx->r13, ctx->r14);
    // 0x800A8458: addiu       $t4, $t8, 0x300
    ctx->r12 = ADD32(ctx->r24, 0X300);
    // 0x800A845C: multu       $t4, $t3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8460: mflo        $t9
    ctx->r25 = lo;
    // 0x800A8464: nop

    // 0x800A8468: nop

    // 0x800A846C: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x800A8470: mflo        $t0
    ctx->r8 = lo;
    // 0x800A8474: bne         $v0, $zero, L_800A8480
    if (ctx->r2 != 0) {
        // 0x800A8478: nop
    
            goto L_800A8480;
    }
    // 0x800A8478: nop

    // 0x800A847C: break       7
    do_break(2148172924);
L_800A8480:
    // 0x800A8480: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8484: bne         $v0, $at, L_800A8498
    if (ctx->r2 != ctx->r1) {
        // 0x800A8488: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8498;
    }
    // 0x800A8488: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A848C: bne         $t9, $at, L_800A8498
    if (ctx->r25 != ctx->r1) {
        // 0x800A8490: nop
    
            goto L_800A8498;
    }
    // 0x800A8490: nop

    // 0x800A8494: break       6
    do_break(2148172948);
L_800A8498:
    // 0x800A8498: addiu       $at, $zero, 0x664
    ctx->r1 = ADD32(0, 0X664);
    // 0x800A849C: bne         $s4, $at, L_800A84BC
    if (ctx->r20 != ctx->r1) {
        // 0x800A84A0: addiu       $t8, $zero, -0x7F
        ctx->r24 = ADD32(0, -0X7F);
            goto L_800A84BC;
    }
    // 0x800A84A0: addiu       $t8, $zero, -0x7F
    ctx->r24 = ADD32(0, -0X7F);
    // 0x800A84A4: lw          $t7, 0xB8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A84A8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800A84AC: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x800A84B0: addiu       $t2, $t7, -0xA00
    ctx->r10 = ADD32(ctx->r15, -0XA00);
    // 0x800A84B4: b           L_800A84F0
    // 0x800A84B8: sw          $t2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r10;
        goto L_800A84F0;
    // 0x800A84B8: sw          $t2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r10;
L_800A84BC:
    // 0x800A84BC: addiu       $at, $zero, 0x659
    ctx->r1 = ADD32(0, 0X659);
    // 0x800A84C0: bne         $s4, $at, L_800A84EC
    if (ctx->r20 != ctx->r1) {
        // 0x800A84C4: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800A84EC;
    }
    // 0x800A84C4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800A84C8: lh          $t5, 0xCA($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A84CC: addiu       $v1, $zero, 0x22
    ctx->r3 = ADD32(0, 0X22);
    // 0x800A84D0: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800A84D4: bltz        $t5, L_800A84E4
    if (SIGNED(ctx->r13) < 0) {
        // 0x800A84D8: nop
    
            goto L_800A84E4;
    }
    // 0x800A84D8: nop

    // 0x800A84DC: b           L_800A84F0
    // 0x800A84E0: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
        goto L_800A84F0;
    // 0x800A84E0: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
L_800A84E4:
    // 0x800A84E4: b           L_800A84F0
    // 0x800A84E8: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
        goto L_800A84F0;
    // 0x800A84E8: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
L_800A84EC:
    // 0x800A84EC: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
L_800A84F0:
    // 0x800A84F0: lh          $t6, 0xCA($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A84F4: lh          $a0, 0xD6($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A84F8: lw          $a1, 0xC0($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A84FC: bltz        $t6, L_800A850C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800A8500: lw          $a2, 0xBC($sp)
        ctx->r6 = S32(MEM_W(ctx->r29, 0XBC));
            goto L_800A850C;
    }
    // 0x800A8500: lw          $a2, 0xBC($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A8504: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800A8508: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_800A850C:
    // 0x800A850C: lw          $t4, 0xB4($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800A8510: lh          $t3, 0xDA($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A8514: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800A8518: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A851C: lw          $a3, 0xB8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A8520: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800A8524: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A8528: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800A852C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800A8530: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A8534: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A8538: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800A853C: jal         0x8009B028
    // 0x800A8540: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    EGS(rdram, ctx);
        goto after_77;
    // 0x800A8540: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_77:
    // 0x800A8544: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A8548: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A854C: jal         0x8009800C
    // 0x800A8550: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    krand2(rdram, ctx);
        goto after_78;
    // 0x800A8550: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    after_78:
    // 0x800A8554: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8558: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x800A855C: addiu       $at, $zero, 0x550
    ctx->r1 = ADD32(0, 0X550);
    // 0x800A8560: mflo        $t2
    ctx->r10 = lo;
    // 0x800A8564: addu        $a2, $s5, $t2
    ctx->r6 = ADD32(ctx->r21, ctx->r10);
    // 0x800A8568: lh          $t5, 0x22($a2)
    ctx->r13 = S32(MEM_H(ctx->r6, 0X22));
    // 0x800A856C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800A8570: bne         $s4, $at, L_800A85B0
    if (ctx->r20 != ctx->r1) {
        // 0x800A8574: sh          $t8, 0x22($a2)
        MEM_H(0X22, ctx->r6) = ctx->r24;
            goto L_800A85B0;
    }
    // 0x800A8574: sh          $t8, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r24;
    // 0x800A8578: lw          $t4, 0x78($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A857C: sb          $zero, 0x24($a2)
    MEM_B(0X24, ctx->r6) = 0;
    // 0x800A8580: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    // 0x800A8584: lh          $t3, 0xE($t4)
    ctx->r11 = S32(MEM_H(ctx->r12, 0XE));
    // 0x800A8588: bnel        $t3, $at, L_800A85B4
    if (ctx->r11 != ctx->r1) {
        // 0x800A858C: addiu       $t6, $zero, 0x80
        ctx->r14 = ADD32(0, 0X80);
            goto L_800A85B4;
    }
    goto skip_45;
    // 0x800A858C: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    skip_45:
    // 0x800A8590: jal         0x8009800C
    // 0x800A8594: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    krand2(rdram, ctx);
        goto after_79;
    // 0x800A8594: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_79:
    // 0x800A8598: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A859C: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x800A85A0: lh          $t9, 0x14($a2)
    ctx->r25 = S32(MEM_H(ctx->r6, 0X14));
    // 0x800A85A4: subu        $t2, $t9, $t7
    ctx->r10 = SUB32(ctx->r25, ctx->r15);
    // 0x800A85A8: addiu       $t5, $t2, 0x80
    ctx->r13 = ADD32(ctx->r10, 0X80);
    // 0x800A85AC: sh          $t5, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r13;
L_800A85B0:
    // 0x800A85B0: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
L_800A85B4:
    // 0x800A85B4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800A85B8: sh          $t6, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r14;
    // 0x800A85BC: b           L_800A9D28
    // 0x800A85C0: sb          $t8, 0x26($a2)
    MEM_B(0X26, ctx->r6) = ctx->r24;
        goto L_800A9D28;
    // 0x800A85C0: sb          $t8, 0x26($a2)
    MEM_B(0X26, ctx->r6) = ctx->r24;
    // 0x800A85C4: lw          $t4, 0xB8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
L_800A85C8:
    // 0x800A85C8: addiu       $t3, $t4, 0x300
    ctx->r11 = ADD32(ctx->r12, 0X300);
    // 0x800A85CC: sw          $t3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r11;
L_800A85D0:
    // 0x800A85D0: lh          $t9, 0x22($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800A85D4: addiu       $t7, $zero, -0x60
    ctx->r15 = ADD32(0, -0X60);
    // 0x800A85D8: addiu       $t2, $zero, 0x284
    ctx->r10 = ADD32(0, 0X284);
    // 0x800A85DC: bltz        $t9, L_800A85E8
    if (SIGNED(ctx->r25) < 0) {
        // 0x800A85E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800A85E8;
    }
    // 0x800A85E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A85E4: sb          $t7, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r15;
L_800A85E8:
    // 0x800A85E8: sh          $s4, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r20;
    // 0x800A85EC: bltz        $t1, L_800A87F4
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A85F0: sw          $t2, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r10;
            goto L_800A87F4;
    }
    // 0x800A85F0: sw          $t2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r10;
    // 0x800A85F4: sll         $t5, $t1, 3
    ctx->r13 = S32(ctx->r9 << 3);
    // 0x800A85F8: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x800A85FC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800A8600: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x800A8604: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A8608: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x800A860C: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800A8610: addiu       $t6, $t6, 0x5770
    ctx->r14 = ADD32(ctx->r14, 0X5770);
    // 0x800A8614: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A8618: addiu       $at, $zero, 0xA2E
    ctx->r1 = ADD32(0, 0XA2E);
    // 0x800A861C: bne         $s4, $at, L_800A8668
    if (ctx->r20 != ctx->r1) {
        // 0x800A8620: addu        $s0, $t5, $t6
        ctx->r16 = ADD32(ctx->r13, ctx->r14);
            goto L_800A8668;
    }
    // 0x800A8620: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x800A8624: lbu         $s2, 0x385($s0)
    ctx->r18 = MEM_BU(ctx->r16, 0X385);
    // 0x800A8628: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A862C: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A8630: sb          $t8, 0x385($s0)
    MEM_B(0X385, ctx->r16) = ctx->r24;
    // 0x800A8634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A8638: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x800A863C: jal         0x800A1F14
    // 0x800A8640: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    aim(rdram, ctx);
        goto after_80;
    // 0x800A8640: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_80:
    // 0x800A8644: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A8648: sra         $t4, $s1, 16
    ctx->r12 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A864C: addiu       $t3, $zero, 0x200
    ctx->r11 = ADD32(0, 0X200);
    // 0x800A8650: addiu       $t9, $zero, 0xA2D
    ctx->r25 = ADD32(0, 0XA2D);
    // 0x800A8654: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800A8658: sb          $s2, 0x385($s0)
    MEM_B(0X385, ctx->r16) = ctx->r18;
    // 0x800A865C: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x800A8660: b           L_800A8688
    // 0x800A8664: sh          $t9, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r25;
        goto L_800A8688;
    // 0x800A8664: sh          $t9, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r25;
L_800A8668:
    // 0x800A8668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A866C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x800A8670: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A8674: jal         0x800A1F14
    // 0x800A8678: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    aim(rdram, ctx);
        goto after_81;
    // 0x800A8678: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_81:
    // 0x800A867C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A8680: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A8684: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
L_800A8688:
    // 0x800A8688: bltzl       $v0, L_800A87AC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A868C: lw          $t3, 0x220($s0)
        ctx->r11 = S32(MEM_W(ctx->r16, 0X220));
            goto L_800A87AC;
    }
    goto skip_46;
    // 0x800A868C: lw          $t3, 0x220($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X220));
    skip_46:
    // 0x800A8690: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8694: mflo        $t2
    ctx->r10 = lo;
    // 0x800A8698: addu        $a2, $s5, $t2
    ctx->r6 = ADD32(ctx->r21, ctx->r10);
    // 0x800A869C: lhu         $a0, 0xE($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XE);
    // 0x800A86A0: jal         0x800B4EA8
    // 0x800A86A4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    gettilesizy(rdram, ctx);
        goto after_82;
    // 0x800A86A4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_82:
    // 0x800A86A8: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A86AC: addiu       $at, $zero, 0xA2E
    ctx->r1 = ADD32(0, 0XA2E);
    // 0x800A86B0: lbu         $t5, 0x27($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X27);
    // 0x800A86B4: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A86B8: mflo        $s2
    ctx->r18 = lo;
    // 0x800A86BC: sll         $t6, $s2, 1
    ctx->r14 = S32(ctx->r18 << 1);
    // 0x800A86C0: beq         $s4, $at, L_800A8780
    if (ctx->r20 == ctx->r1) {
        // 0x800A86C4: addiu       $s2, $t6, 0x800
        ctx->r18 = ADD32(ctx->r14, 0X800);
            goto L_800A8780;
    }
    // 0x800A86C4: addiu       $s2, $t6, 0x800
    ctx->r18 = ADD32(ctx->r14, 0X800);
    // 0x800A86C8: lh          $t8, 0x2E0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A86CC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800A86D0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800A86D4: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A86D8: mflo        $t4
    ctx->r12 = lo;
    // 0x800A86DC: addu        $a0, $s5, $t4
    ctx->r4 = ADD32(ctx->r21, ctx->r12);
    // 0x800A86E0: jal         0x800ACE8C
    // 0x800A86E4: nop

    ldist(rdram, ctx);
        goto after_83;
    // 0x800A86E4: nop

    after_83:
    // 0x800A86E8: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A86EC: lw          $t9, 0xB8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A86F0: lw          $t5, 0xB4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800A86F4: lw          $t3, 0x8($a2)
    ctx->r11 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800A86F8: lh          $t8, 0xE($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0XE));
    // 0x800A86FC: subu        $t7, $t3, $t9
    ctx->r15 = SUB32(ctx->r11, ctx->r25);
    // 0x800A8700: subu        $t2, $t7, $s2
    ctx->r10 = SUB32(ctx->r15, ctx->r18);
    // 0x800A8704: multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8708: lw          $t7, 0xBC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A870C: mflo        $t6
    ctx->r14 = lo;
    // 0x800A8710: nop

    // 0x800A8714: nop

    // 0x800A8718: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800A871C: bne         $v0, $zero, L_800A8728
    if (ctx->r2 != 0) {
        // 0x800A8720: nop
    
            goto L_800A8728;
    }
    // 0x800A8720: nop

    // 0x800A8724: break       7
    do_break(2148173604);
L_800A8728:
    // 0x800A8728: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A872C: bne         $v0, $at, L_800A8740
    if (ctx->r2 != ctx->r1) {
        // 0x800A8730: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8740;
    }
    // 0x800A8730: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8734: bne         $t6, $at, L_800A8740
    if (ctx->r14 != ctx->r1) {
        // 0x800A8738: nop
    
            goto L_800A8740;
    }
    // 0x800A8738: nop

    // 0x800A873C: break       6
    do_break(2148173628);
L_800A8740:
    // 0x800A8740: mflo        $t0
    ctx->r8 = lo;
    // 0x800A8744: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
    // 0x800A8748: beql        $t8, $at, L_800A87D0
    if (ctx->r24 == ctx->r1) {
        // 0x800A874C: lh          $t5, 0xC4($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XC4));
            goto L_800A87D0;
    }
    goto skip_47;
    // 0x800A874C: lh          $t5, 0xC4($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XC4));
    skip_47:
    // 0x800A8750: lw          $t4, 0x0($a2)
    ctx->r12 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A8754: lw          $t3, 0xC0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A8758: lw          $t9, 0x4($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A875C: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A8760: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x800A8764: jal         0x80092024
    // 0x800A8768: subu        $a1, $t9, $t7
    ctx->r5 = SUB32(ctx->r25, ctx->r15);
    getangle(rdram, ctx);
        goto after_84;
    // 0x800A8768: subu        $a1, $t9, $t7
    ctx->r5 = SUB32(ctx->r25, ctx->r15);
    after_84:
    // 0x800A876C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800A8770: sra         $t2, $s3, 16
    ctx->r10 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800A8774: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
    // 0x800A8778: b           L_800A87CC
    // 0x800A877C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
        goto L_800A87CC;
    // 0x800A877C: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A8780:
    // 0x800A8780: lw          $t5, 0x220($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A8784: lh          $t8, 0x2B8($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A8788: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800A878C: subu        $t0, $t6, $t8
    ctx->r8 = SUB32(ctx->r14, ctx->r24);
    // 0x800A8790: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x800A8794: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x800A8798: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800A879C: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x800A87A0: b           L_800A87CC
    // 0x800A87A4: addiu       $t0, $t4, 0x1FA4
    ctx->r8 = ADD32(ctx->r12, 0X1FA4);
        goto L_800A87CC;
    // 0x800A87A4: addiu       $t0, $t4, 0x1FA4
    ctx->r8 = ADD32(ctx->r12, 0X1FA4);
    // 0x800A87A8: lw          $t3, 0x220($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X220));
L_800A87AC:
    // 0x800A87AC: lh          $t7, 0x2B8($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A87B0: negu        $t9, $t3
    ctx->r25 = SUB32(0, ctx->r11);
    // 0x800A87B4: subu        $t0, $t9, $t7
    ctx->r8 = SUB32(ctx->r25, ctx->r15);
    // 0x800A87B8: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x800A87BC: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800A87C0: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800A87C4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800A87C8: addiu       $t0, $t2, 0x1FA4
    ctx->r8 = ADD32(ctx->r10, 0X1FA4);
L_800A87CC:
    // 0x800A87CC: lh          $t5, 0xC4($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XC4));
L_800A87D0:
    // 0x800A87D0: addiu       $s2, $zero, 0xA2D
    ctx->r18 = ADD32(0, 0XA2D);
    // 0x800A87D4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A87D8: bnel        $t5, $s2, L_800A8B08
    if (ctx->r13 != ctx->r18) {
        // 0x800A87DC: lh          $t4, 0xCA($sp)
        ctx->r12 = S32(MEM_H(ctx->r29, 0XCA));
            goto L_800A8B08;
    }
    goto skip_48;
    // 0x800A87DC: lh          $t4, 0xCA($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XCA));
    skip_48:
    // 0x800A87E0: lh          $a1, 0xDA($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A87E4: jal         0x80059034
    // 0x800A87E8: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    spritesound(rdram, ctx);
        goto after_85;
    // 0x800A87E8: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_85:
    // 0x800A87EC: b           L_800A8B04
    // 0x800A87F0: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
        goto L_800A8B04;
    // 0x800A87F0: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A87F4:
    // 0x800A87F4: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x800A87F8: sh          $t1, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r9;
    // 0x800A87FC: jal         0x800ACF18
    // 0x800A8800: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    findplayer(rdram, ctx);
        goto after_86;
    // 0x800A8800: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_86:
    // 0x800A8804: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800A8808: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800A880C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800A8810: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800A8814: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A8818: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800A881C: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x800A8820: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x800A8824: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A8828: addu        $v1, $t8, $t4
    ctx->r3 = ADD32(ctx->r24, ctx->r12);
    // 0x800A882C: lw          $t3, 0x238($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X238));
    // 0x800A8830: lw          $t7, 0x23C($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X23C));
    // 0x800A8834: lw          $t9, 0xC0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A8838: lw          $t2, 0xBC($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A883C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A8840: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A8844: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800A8848: subu        $a0, $t3, $t9
    ctx->r4 = SUB32(ctx->r11, ctx->r25);
    // 0x800A884C: jal         0x80092024
    // 0x800A8850: subu        $a1, $t7, $t2
    ctx->r5 = SUB32(ctx->r15, ctx->r10);
    getangle(rdram, ctx);
        goto after_87;
    // 0x800A8850: subu        $a1, $t7, $t2
    ctx->r5 = SUB32(ctx->r15, ctx->r10);
    after_87:
    // 0x800A8854: lw          $a3, 0x78($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A8858: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800A885C: sra         $t5, $s3, 16
    ctx->r13 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800A8860: lh          $v1, 0xE($a3)
    ctx->r3 = S32(MEM_H(ctx->r7, 0XE));
    // 0x800A8864: addiu       $at, $zero, 0xAC8
    ctx->r1 = ADD32(0, 0XAC8);
    // 0x800A8868: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x800A886C: bnel        $v1, $at, L_800A88A0
    if (ctx->r3 != ctx->r1) {
        // 0x800A8870: addiu       $at, $zero, 0xA96
        ctx->r1 = ADD32(0, 0XA96);
            goto L_800A88A0;
    }
    goto skip_49;
    // 0x800A8870: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    skip_49:
    // 0x800A8874: lbu         $t6, 0x25($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X25);
    // 0x800A8878: lw          $t3, 0xB8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A887C: lw          $t8, 0xB8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A8880: beq         $t6, $zero, L_800A8894
    if (ctx->r14 == 0) {
        // 0x800A8884: addiu       $t9, $t3, -0x2000
        ctx->r25 = ADD32(ctx->r11, -0X2000);
            goto L_800A8894;
    }
    // 0x800A8884: addiu       $t9, $t3, -0x2000
    ctx->r25 = ADD32(ctx->r11, -0X2000);
    // 0x800A8888: addiu       $t4, $t8, -0x1000
    ctx->r12 = ADD32(ctx->r24, -0X1000);
    // 0x800A888C: b           L_800A8A0C
    // 0x800A8890: sw          $t4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r12;
        goto L_800A8A0C;
    // 0x800A8890: sw          $t4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r12;
L_800A8894:
    // 0x800A8894: b           L_800A8A0C
    // 0x800A8898: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
        goto L_800A8A0C;
    // 0x800A8898: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x800A889C: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
L_800A88A0:
    // 0x800A88A0: bne         $v1, $at, L_800A8A0C
    if (ctx->r3 != ctx->r1) {
        // 0x800A88A4: addiu       $a0, $zero, 0x38
        ctx->r4 = ADD32(0, 0X38);
            goto L_800A8A0C;
    }
    // 0x800A88A4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800A88A8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800A88AC: andi        $t2, $v0, 0x7FF
    ctx->r10 = ctx->r2 & 0X7FF;
    // 0x800A88B0: addiu       $a2, $a2, -0x9A0
    ctx->r6 = ADD32(ctx->r6, -0X9A0);
    // 0x800A88B4: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800A88B8: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x800A88BC: lh          $v1, 0x0($t6)
    ctx->r3 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800A88C0: lw          $t8, 0xC0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A88C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800A88C8: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800A88CC: div         $zero, $t4, $a0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r4)));
    // 0x800A88D0: addiu       $t5, $v0, 0x600
    ctx->r13 = ADD32(ctx->r2, 0X600);
    // 0x800A88D4: ldc1        $f0, -0x7E38($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X7E38);
    // 0x800A88D8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800A88DC: andi        $t6, $t5, 0x7FF
    ctx->r14 = ctx->r13 & 0X7FF;
    // 0x800A88E0: mflo        $t3
    ctx->r11 = lo;
    // 0x800A88E4: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800A88E8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A88EC: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800A88F0: lw          $t2, 0xBC($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A88F4: addiu       $t7, $zero, 0x304
    ctx->r15 = ADD32(0, 0X304);
    // 0x800A88F8: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x800A88FC: bne         $a0, $zero, L_800A8908
    if (ctx->r4 != 0) {
        // 0x800A8900: nop
    
            goto L_800A8908;
    }
    // 0x800A8900: nop

    // 0x800A8904: break       7
    do_break(2148174084);
L_800A8908:
    // 0x800A8908: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A890C: bne         $a0, $at, L_800A8920
    if (ctx->r4 != ctx->r1) {
        // 0x800A8910: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8920;
    }
    // 0x800A8910: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8914: bne         $t4, $at, L_800A8920
    if (ctx->r12 != ctx->r1) {
        // 0x800A8918: nop
    
            goto L_800A8920;
    }
    // 0x800A8918: nop

    // 0x800A891C: break       6
    do_break(2148174108);
L_800A8920:
    // 0x800A8920: addu        $t4, $a2, $t8
    ctx->r12 = ADD32(ctx->r6, ctx->r24);
    // 0x800A8924: lh          $t3, 0x0($t4)
    ctx->r11 = S32(MEM_H(ctx->r12, 0X0));
    // 0x800A8928: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800A892C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A8930: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x800A8934: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x800A8938: div.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f8.d, ctx->f0.d);
    // 0x800A893C: mflo        $t2
    ctx->r10 = lo;
    // 0x800A8940: addiu       $t8, $v0, 0x200
    ctx->r24 = ADD32(ctx->r2, 0X200);
    // 0x800A8944: andi        $t4, $t8, 0x7FF
    ctx->r12 = ctx->r24 & 0X7FF;
    // 0x800A8948: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x800A894C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800A8950: sll         $t4, $v1, 11
    ctx->r12 = S32(ctx->r3 << 11);
    // 0x800A8954: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x800A8958: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A895C: nop

    // 0x800A8960: cvt.d.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A8964: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x800A8968: div.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x800A896C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800A8970: nop

    // 0x800A8974: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800A8978: sw          $t7, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r15;
    // 0x800A897C: bne         $a0, $zero, L_800A8988
    if (ctx->r4 != 0) {
        // 0x800A8980: nop
    
            goto L_800A8988;
    }
    // 0x800A8980: nop

    // 0x800A8984: break       7
    do_break(2148174212);
L_800A8988:
    // 0x800A8988: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A898C: bne         $a0, $at, L_800A89A0
    if (ctx->r4 != ctx->r1) {
        // 0x800A8990: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A89A0;
    }
    // 0x800A8990: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8994: bne         $t9, $at, L_800A89A0
    if (ctx->r25 != ctx->r1) {
        // 0x800A8998: nop
    
            goto L_800A89A0;
    }
    // 0x800A8998: nop

    // 0x800A899C: break       6
    do_break(2148174236);
L_800A89A0:
    // 0x800A89A0: addu        $t9, $a2, $t3
    ctx->r25 = ADD32(ctx->r6, ctx->r11);
    // 0x800A89A4: lh          $t2, 0x0($t9)
    ctx->r10 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800A89A8: sra         $t3, $t4, 14
    ctx->r11 = S32(SIGNED(ctx->r12) >> 14);
    // 0x800A89AC: sll         $t5, $t2, 11
    ctx->r13 = S32(ctx->r10 << 11);
    // 0x800A89B0: sra         $t7, $t5, 14
    ctx->r15 = S32(SIGNED(ctx->r13) >> 14);
    // 0x800A89B4: cvt.d.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A89B8: add.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d + ctx->f16.d;
    // 0x800A89BC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A89C0: nop

    // 0x800A89C4: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800A89C8: trunc.w.d   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800A89CC: div.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f0.d);
    // 0x800A89D0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800A89D4: nop

    // 0x800A89D8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A89DC: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x800A89E0: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800A89E4: add.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f10.d + ctx->f18.d;
    // 0x800A89E8: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800A89EC: nop

    // 0x800A89F0: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x800A89F4: trunc.w.d   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800A89F8: div.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x800A89FC: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    // 0x800A8A00: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x800A8A04: trunc.w.d   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x800A8A08: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
L_800A8A0C:
    // 0x800A8A0C: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
    // 0x800A8A10: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x800A8A14: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800A8A18: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x800A8A1C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A8A20: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x800A8A24: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x800A8A28: addiu       $t5, $t5, 0x5770
    ctx->r13 = ADD32(ctx->r13, 0X5770);
    // 0x800A8A2C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A8A30: addu        $s0, $t2, $t5
    ctx->r16 = ADD32(ctx->r10, ctx->r13);
    // 0x800A8A34: lh          $t7, 0x2E0($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A8A38: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A8A3C: lw          $t9, 0xBC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A8A40: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8A44: mflo        $t8
    ctx->r24 = lo;
    // 0x800A8A48: addu        $v1, $s5, $t8
    ctx->r3 = ADD32(ctx->r21, ctx->r24);
    // 0x800A8A4C: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800A8A50: lw          $t3, 0x4($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800A8A54: subu        $a0, $t6, $t4
    ctx->r4 = SUB32(ctx->r14, ctx->r12);
    // 0x800A8A58: jal         0x800993E0
    // 0x800A8A5C: subu        $a1, $t3, $t9
    ctx->r5 = SUB32(ctx->r11, ctx->r25);
    FindDistance2D(rdram, ctx);
        goto after_88;
    // 0x800A8A5C: subu        $a1, $t3, $t9
    ctx->r5 = SUB32(ctx->r11, ctx->r25);
    after_88:
    // 0x800A8A60: lw          $t2, 0x240($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X240));
    // 0x800A8A64: lw          $t5, 0xB8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A8A68: lw          $t8, 0xB4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800A8A6C: lw          $a0, 0x78($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A8A70: subu        $t7, $t2, $t5
    ctx->r15 = SUB32(ctx->r10, ctx->r13);
    // 0x800A8A74: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8A78: mflo        $t6
    ctx->r14 = lo;
    // 0x800A8A7C: nop

    // 0x800A8A80: nop

    // 0x800A8A84: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800A8A88: mflo        $t0
    ctx->r8 = lo;
    // 0x800A8A8C: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A8A90: bne         $v0, $zero, L_800A8A9C
    if (ctx->r2 != 0) {
        // 0x800A8A94: nop
    
            goto L_800A8A9C;
    }
    // 0x800A8A94: nop

    // 0x800A8A98: break       7
    do_break(2148174488);
L_800A8A9C:
    // 0x800A8A9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8AA0: bne         $v0, $at, L_800A8AB4
    if (ctx->r2 != ctx->r1) {
        // 0x800A8AA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8AB4;
    }
    // 0x800A8AA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8AA8: bne         $t6, $at, L_800A8AB4
    if (ctx->r14 != ctx->r1) {
        // 0x800A8AAC: nop
    
            goto L_800A8AB4;
    }
    // 0x800A8AAC: nop

    // 0x800A8AB0: break       6
    do_break(2148174512);
L_800A8AB4:
    // 0x800A8AB4: jal         0x80099ED4
    // 0x800A8AB8: nop

    badguy(rdram, ctx);
        goto after_89;
    // 0x800A8AB8: nop

    after_89:
    // 0x800A8ABC: beq         $v0, $zero, L_800A8B04
    if (ctx->r2 == 0) {
        // 0x800A8AC0: lw          $t0, 0xB0($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
            goto L_800A8B04;
    }
    // 0x800A8AC0: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A8AC4: lw          $t4, 0x78($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A8AC8: lh          $t3, 0x20($t4)
    ctx->r11 = S32(MEM_H(ctx->r12, 0X20));
    // 0x800A8ACC: andi        $t9, $t3, 0x40
    ctx->r25 = ctx->r11 & 0X40;
    // 0x800A8AD0: beql        $t9, $zero, L_800A8B08
    if (ctx->r25 == 0) {
        // 0x800A8AD4: lh          $t4, 0xCA($sp)
        ctx->r12 = S32(MEM_H(ctx->r29, 0XCA));
            goto L_800A8B08;
    }
    goto skip_50;
    // 0x800A8AD4: lh          $t4, 0xCA($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XCA));
    skip_50:
    // 0x800A8AD8: jal         0x8009800C
    // 0x800A8ADC: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_90;
    // 0x800A8ADC: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_90:
    // 0x800A8AE0: lw          $t5, 0x78($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A8AE4: andi        $t2, $v0, 0x1F
    ctx->r10 = ctx->r2 & 0X1F;
    // 0x800A8AE8: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A8AEC: lh          $t7, 0x14($t5)
    ctx->r15 = S32(MEM_H(ctx->r13, 0X14));
    // 0x800A8AF0: addu        $s3, $t2, $t7
    ctx->r19 = ADD32(ctx->r10, ctx->r15);
    // 0x800A8AF4: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
    // 0x800A8AF8: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800A8AFC: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800A8B00: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800A8B04:
    // 0x800A8B04: lh          $t4, 0xCA($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XCA));
L_800A8B08:
    // 0x800A8B08: addiu       $s2, $zero, 0xA2D
    ctx->r18 = ADD32(0, 0XA2D);
    // 0x800A8B0C: addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // 0x800A8B10: bltz        $t4, L_800A8B2C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800A8B14: lui         $v1, 0x8010
        ctx->r3 = S32(0X8010 << 16);
            goto L_800A8B2C;
    }
    // 0x800A8B14: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800A8B18: bltz        $s1, L_800A8B2C
    if (SIGNED(ctx->r17) < 0) {
        // 0x800A8B1C: sll         $s0, $s1, 16
        ctx->r16 = S32(ctx->r17 << 16);
            goto L_800A8B2C;
    }
    // 0x800A8B1C: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
    // 0x800A8B20: sra         $t3, $s0, 16
    ctx->r11 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800A8B24: b           L_800A8B30
    // 0x800A8B28: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
        goto L_800A8B30;
    // 0x800A8B28: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
L_800A8B2C:
    // 0x800A8B2C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_800A8B30:
    // 0x800A8B30: addiu       $t9, $s3, 0x35C
    ctx->r25 = ADD32(ctx->r19, 0X35C);
    // 0x800A8B34: andi        $t5, $t9, 0x7FF
    ctx->r13 = ctx->r25 & 0X7FF;
    // 0x800A8B38: addiu       $v1, $v1, -0x9A0
    ctx->r3 = ADD32(ctx->r3, -0X9A0);
    // 0x800A8B3C: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x800A8B40: addu        $t7, $v1, $t2
    ctx->r15 = ADD32(ctx->r3, ctx->r10);
    // 0x800A8B44: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800A8B48: addiu       $t3, $s3, 0x15C
    ctx->r11 = ADD32(ctx->r19, 0X15C);
    // 0x800A8B4C: andi        $t9, $t3, 0x7FF
    ctx->r25 = ctx->r11 & 0X7FF;
    // 0x800A8B50: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800A8B54: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x800A8B58: addu        $t2, $v1, $t5
    ctx->r10 = ADD32(ctx->r3, ctx->r13);
    // 0x800A8B5C: lh          $t7, 0x0($t2)
    ctx->r15 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800A8B60: mflo        $t6
    ctx->r14 = lo;
    // 0x800A8B64: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A8B68: lh          $t2, 0xDA($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A8B6C: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x800A8B70: addu        $a1, $t6, $t4
    ctx->r5 = ADD32(ctx->r14, ctx->r12);
    // 0x800A8B74: lh          $t4, 0xC4($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XC4));
    // 0x800A8B78: lw          $t6, 0xBC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A8B7C: lw          $t5, 0xB4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800A8B80: lw          $a3, 0xB8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A8B84: addiu       $t9, $zero, 0xE
    ctx->r25 = ADD32(0, 0XE);
    // 0x800A8B88: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x800A8B8C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A8B90: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A8B94: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A8B98: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A8B9C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800A8BA0: lh          $a0, 0xD6($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A8BA4: bne         $v0, $zero, L_800A8BB0
    if (ctx->r2 != 0) {
        // 0x800A8BA8: nop
    
            goto L_800A8BB0;
    }
    // 0x800A8BA8: nop

    // 0x800A8BAC: break       7
    do_break(2148174764);
L_800A8BB0:
    // 0x800A8BB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8BB4: bne         $v0, $at, L_800A8BC8
    if (ctx->r2 != ctx->r1) {
        // 0x800A8BB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8BC8;
    }
    // 0x800A8BB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8BBC: bne         $t8, $at, L_800A8BC8
    if (ctx->r24 != ctx->r1) {
        // 0x800A8BC0: nop
    
            goto L_800A8BC8;
    }
    // 0x800A8BC0: nop

    // 0x800A8BC4: break       6
    do_break(2148174788);
L_800A8BC8:
    // 0x800A8BC8: mflo        $t8
    ctx->r24 = lo;
    // 0x800A8BCC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800A8BD0: bne         $v0, $zero, L_800A8BDC
    if (ctx->r2 != 0) {
        // 0x800A8BD4: nop
    
            goto L_800A8BDC;
    }
    // 0x800A8BD4: nop

    // 0x800A8BD8: break       7
    do_break(2148174808);
L_800A8BDC:
    // 0x800A8BDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8BE0: bne         $v0, $at, L_800A8BF4
    if (ctx->r2 != ctx->r1) {
        // 0x800A8BE4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8BF4;
    }
    // 0x800A8BE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8BE8: bne         $t7, $at, L_800A8BF4
    if (ctx->r15 != ctx->r1) {
        // 0x800A8BEC: nop
    
            goto L_800A8BF4;
    }
    // 0x800A8BEC: nop

    // 0x800A8BF0: break       6
    do_break(2148174832);
L_800A8BF4:
    // 0x800A8BF4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800A8BF8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800A8BFC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A8C00: addu        $a2, $t8, $t6
    ctx->r6 = ADD32(ctx->r24, ctx->r14);
    // 0x800A8C04: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800A8C08: jal         0x8009B028
    // 0x800A8C0C: addiu       $a3, $a3, -0x100
    ctx->r7 = ADD32(ctx->r7, -0X100);
    EGS(rdram, ctx);
        goto after_91;
    // 0x800A8C0C: addiu       $a3, $a3, -0x100
    ctx->r7 = ADD32(ctx->r7, -0X100);
    after_91:
    // 0x800A8C10: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A8C14: sra         $t8, $s1, 16
    ctx->r24 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A8C18: jal         0x8009800C
    // 0x800A8C1C: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    krand2(rdram, ctx);
        goto after_92;
    // 0x800A8C1C: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    after_92:
    // 0x800A8C20: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8C24: lh          $t5, 0xC4($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XC4));
    // 0x800A8C28: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x800A8C2C: addiu       $at, $zero, 0xA2E
    ctx->r1 = ADD32(0, 0XA2E);
    // 0x800A8C30: mflo        $t6
    ctx->r14 = lo;
    // 0x800A8C34: addu        $a2, $s5, $t6
    ctx->r6 = ADD32(ctx->r21, ctx->r14);
    // 0x800A8C38: lh          $t4, 0x22($a2)
    ctx->r12 = S32(MEM_H(ctx->r6, 0X22));
    // 0x800A8C3C: addu        $t9, $t4, $t3
    ctx->r25 = ADD32(ctx->r12, ctx->r11);
    // 0x800A8C40: bne         $t5, $s2, L_800A8C4C
    if (ctx->r13 != ctx->r18) {
        // 0x800A8C44: sh          $t9, 0x22($a2)
        MEM_H(0X22, ctx->r6) = ctx->r25;
            goto L_800A8C4C;
    }
    // 0x800A8C44: sh          $t9, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r25;
    // 0x800A8C48: sh          $s0, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r16;
L_800A8C4C:
    // 0x800A8C4C: bnel        $s4, $at, L_800A8C78
    if (ctx->r20 != ctx->r1) {
        // 0x800A8C50: addiu       $at, $zero, 0xF01
        ctx->r1 = ADD32(0, 0XF01);
            goto L_800A8C78;
    }
    goto skip_51;
    // 0x800A8C50: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    skip_51:
    // 0x800A8C54: jal         0x8009800C
    // 0x800A8C58: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    krand2(rdram, ctx);
        goto after_93;
    // 0x800A8C58: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_93:
    // 0x800A8C5C: andi        $t2, $v0, 0x3F
    ctx->r10 = ctx->r2 & 0X3F;
    // 0x800A8C60: slti        $at, $t2, 0x20
    ctx->r1 = SIGNED(ctx->r10) < 0X20 ? 1 : 0;
    // 0x800A8C64: beq         $at, $zero, L_800A8C74
    if (ctx->r1 == 0) {
        // 0x800A8C68: lw          $a2, 0x70($sp)
        ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
            goto L_800A8C74;
    }
    // 0x800A8C68: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A8C6C: addiu       $t7, $zero, 0x201
    ctx->r15 = ADD32(0, 0X201);
    // 0x800A8C70: sh          $t7, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r15;
L_800A8C74:
    // 0x800A8C74: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
L_800A8C78:
    // 0x800A8C78: bnel        $s4, $at, L_800A8CFC
    if (ctx->r20 != ctx->r1) {
        // 0x800A8C7C: lh          $v1, 0xCA($sp)
        ctx->r3 = S32(MEM_H(ctx->r29, 0XCA));
            goto L_800A8CFC;
    }
    goto skip_52;
    // 0x800A8C7C: lh          $v1, 0xCA($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0XCA));
    skip_52:
    // 0x800A8C80: lh          $t8, 0x1C($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0X1C));
    // 0x800A8C84: lh          $v1, 0xCA($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0XCA));
    // 0x800A8C88: addiu       $t9, $zero, 0x42
    ctx->r25 = ADD32(0, 0X42);
    // 0x800A8C8C: addiu       $t6, $t8, -0x20
    ctx->r14 = ADD32(ctx->r24, -0X20);
    // 0x800A8C90: bltz        $v1, L_800A8CC8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800A8C94: sh          $t6, 0x1C($a2)
        MEM_H(0X1C, ctx->r6) = ctx->r14;
            goto L_800A8CC8;
    }
    // 0x800A8C94: sh          $t6, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r14;
    // 0x800A8C98: sll         $t4, $v1, 3
    ctx->r12 = S32(ctx->r3 << 3);
    // 0x800A8C9C: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800A8CA0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800A8CA4: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x800A8CA8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A8CAC: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800A8CB0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A8CB4: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x800A8CB8: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x800A8CBC: lh          $t3, 0x5A32($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, 0X5A32));
    // 0x800A8CC0: b           L_800A8CCC
    // 0x800A8CC4: sh          $t3, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r11;
        goto L_800A8CCC;
    // 0x800A8CC4: sh          $t3, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r11;
L_800A8CC8:
    // 0x800A8CC8: sh          $t9, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r25;
L_800A8CCC:
    // 0x800A8CCC: lh          $v0, 0x1A($a2)
    ctx->r2 = S32(MEM_H(ctx->r6, 0X1A));
    // 0x800A8CD0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A8CD4: lh          $t5, 0x22($a2)
    ctx->r13 = S32(MEM_H(ctx->r6, 0X22));
    // 0x800A8CD8: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8CDC: mflo        $t2
    ctx->r10 = lo;
    // 0x800A8CE0: nop

    // 0x800A8CE4: nop

    // 0x800A8CE8: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x800A8CEC: mflo        $t7
    ctx->r15 = lo;
    // 0x800A8CF0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800A8CF4: sh          $t8, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r24;
    // 0x800A8CF8: lh          $v1, 0xCA($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0XCA));
L_800A8CFC:
    // 0x800A8CFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8D00: lw          $t6, 0x78($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A8D04: bnel        $v1, $at, L_800A8EA8
    if (ctx->r3 != ctx->r1) {
        // 0x800A8D08: lh          $t9, 0xC4($sp)
        ctx->r25 = S32(MEM_H(ctx->r29, 0XC4));
            goto L_800A8EA8;
    }
    goto skip_53;
    // 0x800A8D08: lh          $t9, 0xC4($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XC4));
    skip_53:
    // 0x800A8D0C: lh          $v1, 0xE($t6)
    ctx->r3 = S32(MEM_H(ctx->r14, 0XE));
    // 0x800A8D10: addiu       $at, $zero, 0xAC8
    ctx->r1 = ADD32(0, 0XAC8);
    // 0x800A8D14: bnel        $v1, $at, L_800A8E4C
    if (ctx->r3 != ctx->r1) {
        // 0x800A8D18: addiu       $at, $zero, 0xA96
        ctx->r1 = ADD32(0, 0XA96);
            goto L_800A8E4C;
    }
    goto skip_54;
    // 0x800A8D18: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    skip_54:
    // 0x800A8D1C: jal         0x8009800C
    // 0x800A8D20: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    krand2(rdram, ctx);
        goto after_94;
    // 0x800A8D20: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_94:
    // 0x800A8D24: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x800A8D28: beq         $t4, $zero, L_800A8D8C
    if (ctx->r12 == 0) {
        // 0x800A8D2C: lw          $a2, 0x70($sp)
        ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
            goto L_800A8D8C;
    }
    // 0x800A8D2C: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A8D30: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800A8D34: andi        $t3, $s3, 0x7FF
    ctx->r11 = ctx->r19 & 0X7FF;
    // 0x800A8D38: addiu       $a0, $a0, -0x9A0
    ctx->r4 = ADD32(ctx->r4, -0X9A0);
    // 0x800A8D3C: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x800A8D40: addiu       $t6, $s3, 0x600
    ctx->r14 = ADD32(ctx->r19, 0X600);
    // 0x800A8D44: addu        $t2, $a0, $t9
    ctx->r10 = ADD32(ctx->r4, ctx->r25);
    // 0x800A8D48: andi        $t4, $t6, 0x7FF
    ctx->r12 = ctx->r14 & 0X7FF;
    // 0x800A8D4C: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x800A8D50: lh          $v0, 0x0($t2)
    ctx->r2 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800A8D54: addu        $t9, $a0, $t3
    ctx->r25 = ADD32(ctx->r4, ctx->r11);
    // 0x800A8D58: lh          $v1, 0x0($t9)
    ctx->r3 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800A8D5C: lh          $t8, 0x14($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0X14));
    // 0x800A8D60: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800A8D64: sra         $t5, $v0, 6
    ctx->r13 = S32(SIGNED(ctx->r2) >> 6);
    // 0x800A8D68: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800A8D6C: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800A8D70: sra         $t2, $v1, 6
    ctx->r10 = S32(SIGNED(ctx->r3) >> 6);
    // 0x800A8D74: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x800A8D78: addiu       $t6, $t8, -0x8
    ctx->r14 = ADD32(ctx->r24, -0X8);
    // 0x800A8D7C: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A8D80: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800A8D84: b           L_800A8DDC
    // 0x800A8D88: sh          $t6, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r14;
        goto L_800A8DDC;
    // 0x800A8D88: sh          $t6, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r14;
L_800A8D8C:
    // 0x800A8D8C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800A8D90: andi        $t4, $s3, 0x7FF
    ctx->r12 = ctx->r19 & 0X7FF;
    // 0x800A8D94: addiu       $a0, $a0, -0x9A0
    ctx->r4 = ADD32(ctx->r4, -0X9A0);
    // 0x800A8D98: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x800A8D9C: addiu       $t8, $s3, 0x600
    ctx->r24 = ADD32(ctx->r19, 0X600);
    // 0x800A8DA0: addu        $t9, $a0, $t3
    ctx->r25 = ADD32(ctx->r4, ctx->r11);
    // 0x800A8DA4: andi        $t6, $t8, 0x7FF
    ctx->r14 = ctx->r24 & 0X7FF;
    // 0x800A8DA8: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x800A8DAC: lh          $v0, 0x0($t9)
    ctx->r2 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800A8DB0: addu        $t3, $a0, $t4
    ctx->r11 = ADD32(ctx->r4, ctx->r12);
    // 0x800A8DB4: lh          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_H(ctx->r11, 0X0));
    // 0x800A8DB8: lh          $t7, 0x14($a2)
    ctx->r15 = S32(MEM_H(ctx->r6, 0X14));
    // 0x800A8DBC: sra         $t2, $v0, 6
    ctx->r10 = S32(SIGNED(ctx->r2) >> 6);
    // 0x800A8DC0: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x800A8DC4: sra         $t9, $v1, 6
    ctx->r25 = S32(SIGNED(ctx->r3) >> 6);
    // 0x800A8DC8: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800A8DCC: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800A8DD0: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800A8DD4: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800A8DD8: sh          $t8, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r24;
L_800A8DDC:
    // 0x800A8DDC: lw          $t6, 0x78($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A8DE0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800A8DE4: lbu         $t4, 0x25($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X25);
    // 0x800A8DE8: beql        $t4, $zero, L_800A8E28
    if (ctx->r12 == 0) {
        // 0x800A8DEC: lw          $t6, 0x0($a2)
        ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
            goto L_800A8E28;
    }
    goto skip_55;
    // 0x800A8DEC: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
    skip_55:
    // 0x800A8DF0: bgez        $v0, L_800A8E00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A8DF4: sra         $t3, $v0, 1
        ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800A8E00;
    }
    // 0x800A8DF4: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800A8DF8: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x800A8DFC: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800A8E00:
    // 0x800A8E00: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800A8E04: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800A8E08: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800A8E0C: bgez        $v1, L_800A8E1C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A8E10: sra         $t5, $v1, 1
        ctx->r13 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800A8E1C;
    }
    // 0x800A8E10: sra         $t5, $v1, 1
    ctx->r13 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A8E14: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x800A8E18: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800A8E1C:
    // 0x800A8E1C: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800A8E20: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A8E24: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
L_800A8E28:
    // 0x800A8E28: lw          $t3, 0x4($a2)
    ctx->r11 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A8E2C: sb          $a0, 0x27($a2)
    MEM_B(0X27, ctx->r6) = ctx->r4;
    // 0x800A8E30: addu        $t4, $t6, $v0
    ctx->r12 = ADD32(ctx->r14, ctx->r2);
    // 0x800A8E34: addu        $t9, $t3, $v1
    ctx->r25 = ADD32(ctx->r11, ctx->r3);
    // 0x800A8E38: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800A8E3C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800A8E40: b           L_800A8EA4
    // 0x800A8E44: sb          $a0, 0x28($a2)
    MEM_B(0X28, ctx->r6) = ctx->r4;
        goto L_800A8EA4;
    // 0x800A8E44: sb          $a0, 0x28($a2)
    MEM_B(0X28, ctx->r6) = ctx->r4;
    // 0x800A8E48: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
L_800A8E4C:
    // 0x800A8E4C: bnel        $v1, $at, L_800A8E88
    if (ctx->r3 != ctx->r1) {
        // 0x800A8E50: addiu       $at, $zero, 0xF01
        ctx->r1 = ADD32(0, 0XF01);
            goto L_800A8E88;
    }
    goto skip_56;
    // 0x800A8E50: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
    skip_56:
    // 0x800A8E54: jal         0x8009800C
    // 0x800A8E58: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    krand2(rdram, ctx);
        goto after_95;
    // 0x800A8E58: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_95:
    // 0x800A8E5C: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A8E60: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x800A8E64: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800A8E68: lh          $t2, 0x14($a2)
    ctx->r10 = S32(MEM_H(ctx->r6, 0X14));
    // 0x800A8E6C: sb          $v1, 0x27($a2)
    MEM_B(0X27, ctx->r6) = ctx->r3;
    // 0x800A8E70: sb          $v1, 0x28($a2)
    MEM_B(0X28, ctx->r6) = ctx->r3;
    // 0x800A8E74: subu        $t7, $t2, $t5
    ctx->r15 = SUB32(ctx->r10, ctx->r13);
    // 0x800A8E78: addiu       $t8, $t7, 0x78
    ctx->r24 = ADD32(ctx->r15, 0X78);
    // 0x800A8E7C: b           L_800A8EA4
    // 0x800A8E80: sh          $t8, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r24;
        goto L_800A8EA4;
    // 0x800A8E80: sh          $t8, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r24;
    // 0x800A8E84: addiu       $at, $zero, 0xF01
    ctx->r1 = ADD32(0, 0XF01);
L_800A8E88:
    // 0x800A8E88: beq         $s4, $at, L_800A8EA4
    if (ctx->r20 == ctx->r1) {
        // 0x800A8E8C: addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
            goto L_800A8EA4;
    }
    // 0x800A8E8C: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x800A8E90: lh          $t6, 0x22($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0X22));
    // 0x800A8E94: sb          $v0, 0x27($a2)
    MEM_B(0X27, ctx->r6) = ctx->r2;
    // 0x800A8E98: sb          $v0, 0x28($a2)
    MEM_B(0X28, ctx->r6) = ctx->r2;
    // 0x800A8E9C: sra         $t4, $t6, 2
    ctx->r12 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800A8EA0: sh          $t4, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r12;
L_800A8EA4:
    // 0x800A8EA4: lh          $t9, 0xC4($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XC4));
L_800A8EA8:
    // 0x800A8EA8: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x800A8EAC: sh          $t3, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r11;
    // 0x800A8EB0: bne         $t9, $s2, L_800A8EC4
    if (ctx->r25 != ctx->r18) {
        // 0x800A8EB4: addiu       $t5, $zero, 0x50
        ctx->r13 = ADD32(0, 0X50);
            goto L_800A8EC4;
    }
    // 0x800A8EB4: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x800A8EB8: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A8EBC: b           L_800A9D28
    // 0x800A8EC0: sb          $t2, 0x26($a2)
    MEM_B(0X26, ctx->r6) = ctx->r10;
        goto L_800A9D28;
    // 0x800A8EC0: sb          $t2, 0x26($a2)
    MEM_B(0X26, ctx->r6) = ctx->r10;
L_800A8EC4:
    // 0x800A8EC4: b           L_800A9D28
    // 0x800A8EC8: sb          $t5, 0x26($a2)
    MEM_B(0X26, ctx->r6) = ctx->r13;
        goto L_800A9D28;
    // 0x800A8EC8: sb          $t5, 0x26($a2)
    MEM_B(0X26, ctx->r6) = ctx->r13;
L_800A8ECC:
    // 0x800A8ECC: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x800A8ED0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A8ED4: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800A8ED8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A8EDC: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x800A8EE0: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800A8EE4: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x800A8EE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A8EEC: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x800A8EF0: bltz        $t1, L_800A8F10
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A8EF4: lw          $v0, 0x244($s0)
        ctx->r2 = S32(MEM_W(ctx->r16, 0X244));
            goto L_800A8F10;
    }
    // 0x800A8EF4: lw          $v0, 0x244($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X244));
    // 0x800A8EF8: lw          $t6, 0x220($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A8EFC: lh          $t3, 0x2B8($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A8F00: negu        $t4, $t6
    ctx->r12 = SUB32(0, ctx->r14);
    // 0x800A8F04: subu        $t0, $t4, $t3
    ctx->r8 = SUB32(ctx->r12, ctx->r11);
    // 0x800A8F08: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x800A8F0C: addiu       $t0, $t9, 0xC80
    ctx->r8 = ADD32(ctx->r25, 0XC80);
L_800A8F10:
    // 0x800A8F10: lw          $t2, 0xB8($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A8F14: addiu       $t5, $s3, 0x200
    ctx->r13 = ADD32(ctx->r19, 0X200);
    // 0x800A8F18: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800A8F1C: andi        $t7, $t5, 0x7FF
    ctx->r15 = ctx->r13 & 0X7FF;
    // 0x800A8F20: addiu       $v1, $v1, -0x9A0
    ctx->r3 = ADD32(ctx->r3, -0X9A0);
    // 0x800A8F24: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800A8F28: andi        $t3, $s3, 0x7FF
    ctx->r11 = ctx->r19 & 0X7FF;
    // 0x800A8F2C: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x800A8F30: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800A8F34: subu        $a2, $t2, $v0
    ctx->r6 = SUB32(ctx->r10, ctx->r2);
    // 0x800A8F38: lh          $t4, 0x0($t6)
    ctx->r12 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800A8F3C: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x800A8F40: lh          $t5, 0x0($t2)
    ctx->r13 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800A8F44: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800A8F48: addiu       $t4, $sp, 0xD2
    ctx->r12 = ADD32(ctx->r29, 0XD2);
    // 0x800A8F4C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800A8F50: lui         $t5, 0x100
    ctx->r13 = S32(0X100 << 16);
    // 0x800A8F54: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x800A8F58: addiu       $t2, $sp, 0xA4
    ctx->r10 = ADD32(ctx->r29, 0XA4);
    // 0x800A8F5C: addiu       $t9, $sp, 0xA8
    ctx->r25 = ADD32(ctx->r29, 0XA8);
    // 0x800A8F60: addiu       $t6, $sp, 0xD0
    ctx->r14 = ADD32(ctx->r29, 0XD0);
    // 0x800A8F64: addiu       $t8, $sp, 0xD4
    ctx->r24 = ADD32(ctx->r29, 0XD4);
    // 0x800A8F68: addiu       $t3, $sp, 0xAC
    ctx->r11 = ADD32(ctx->r29, 0XAC);
    // 0x800A8F6C: sll         $t7, $t0, 6
    ctx->r15 = S32(ctx->r8 << 6);
    // 0x800A8F70: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800A8F74: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800A8F78: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800A8F7C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A8F80: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800A8F84: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A8F88: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x800A8F8C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800A8F90: lw          $a0, 0xC0($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A8F94: lw          $a1, 0xBC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A8F98: jal         0x8009324C
    // 0x800A8F9C: lh          $a3, 0xD6($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD6));
    hitscan(rdram, ctx);
        goto after_96;
    // 0x800A8F9C: lh          $a3, 0xD6($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD6));
    after_96:
    // 0x800A8FA0: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A8FA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A8FA8: lh          $t7, 0xD0($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A8FAC: bgezl       $a3, L_800A9D2C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800A8FB0: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_57;
    // 0x800A8FB0: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_57:
    // 0x800A8FB4: bltz        $t7, L_800A9098
    if (SIGNED(ctx->r15) < 0) {
        // 0x800A8FB8: lh          $s2, 0xD4($sp)
        ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
            goto L_800A9098;
    }
    // 0x800A8FB8: lh          $s2, 0xD4($sp)
    ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A8FBC: bltz        $s2, L_800A9098
    if (SIGNED(ctx->r18) < 0) {
        // 0x800A8FC0: lw          $t8, 0xAC($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0XAC));
            goto L_800A9098;
    }
    // 0x800A8FC0: lw          $t8, 0xAC($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A8FC4: lw          $t6, 0xC0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A8FC8: lw          $t4, 0xA8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A8FCC: lw          $t3, 0xBC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A8FD0: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x800A8FD4: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8FD8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
    // 0x800A8FDC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800A8FE0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800A8FE4: ori         $at, $at, 0x4884
    ctx->r1 = ctx->r1 | 0X4884;
    // 0x800A8FE8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800A8FEC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A8FF0: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800A8FF4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800A8FF8: mflo        $t9
    ctx->r25 = lo;
    // 0x800A8FFC: nop

    // 0x800A9000: nop

    // 0x800A9004: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9008: mflo        $t2
    ctx->r10 = lo;
    // 0x800A900C: addu        $t5, $t9, $t2
    ctx->r13 = ADD32(ctx->r25, ctx->r10);
    // 0x800A9010: slt         $at, $t5, $at
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800A9014: beql        $at, $zero, L_800A909C
    if (ctx->r1 == 0) {
        // 0x800A9018: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800A909C;
    }
    goto skip_58;
    // 0x800A9018: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_58:
    // 0x800A901C: lh          $v0, 0x61B4($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X61B4));
    // 0x800A9020: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x800A9024: subu        $t2, $t2, $s2
    ctx->r10 = SUB32(ctx->r10, ctx->r18);
    // 0x800A9028: bltz        $v0, L_800A907C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A902C: sll         $t2, $t2, 4
        ctx->r10 = S32(ctx->r10 << 4);
            goto L_800A907C;
    }
    // 0x800A902C: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800A9030: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800A9034: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800A9038: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800A903C: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800A9040: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x800A9044: lh          $t4, -0x1970($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X1970));
    // 0x800A9048: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x800A904C: subu        $t3, $t3, $s2
    ctx->r11 = SUB32(ctx->r11, ctx->r18);
    // 0x800A9050: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800A9054: beq         $at, $zero, L_800A9098
    if (ctx->r1 == 0) {
        // 0x800A9058: sll         $t3, $t3, 4
        ctx->r11 = S32(ctx->r11 << 4);
            goto L_800A9098;
    }
    // 0x800A9058: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800A905C: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800A9060: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x800A9064: lh          $t9, -0x1970($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X1970));
    // 0x800A9068: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x800A906C: beql        $at, $zero, L_800A909C
    if (ctx->r1 == 0) {
        // 0x800A9070: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800A909C;
    }
    goto skip_59;
    // 0x800A9070: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_59:
    // 0x800A9074: b           L_800A9098
    // 0x800A9078: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_800A9098;
    // 0x800A9078: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800A907C:
    // 0x800A907C: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800A9080: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x800A9084: lh          $t5, -0x1970($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X1970));
    // 0x800A9088: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800A908C: beql        $at, $zero, L_800A909C
    if (ctx->r1 == 0) {
        // 0x800A9090: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800A909C;
    }
    goto skip_60;
    // 0x800A9090: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_60:
    // 0x800A9094: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800A9098:
    // 0x800A9098: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800A909C:
    // 0x800A909C: bne         $s1, $v1, L_800A9D28
    if (ctx->r17 != ctx->r3) {
        // 0x800A90A0: lh          $s2, 0xD4($sp)
        ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
            goto L_800A9D28;
    }
    // 0x800A90A0: lh          $s2, 0xD4($sp)
    ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A90A4: lh          $t9, 0xDA($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A90A8: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A90AC: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A90B0: addiu       $t8, $zero, 0xA06
    ctx->r24 = ADD32(0, 0XA06);
    // 0x800A90B4: addiu       $t6, $zero, -0x10
    ctx->r14 = ADD32(0, -0X10);
    // 0x800A90B8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800A90BC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800A90C0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800A90C4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A90C8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800A90CC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A90D0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A90D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A90D8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A90DC: lw          $a1, 0xAC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A90E0: lw          $a2, 0xA8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A90E4: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A90E8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A90EC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A90F0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A90F4: jal         0x8009B028
    // 0x800A90F8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    EGS(rdram, ctx);
        goto after_97;
    // 0x800A90F8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_97:
    // 0x800A90FC: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9100: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800A9104: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x800A9108: sra         $t5, $s2, 16
    ctx->r13 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800A910C: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A9110: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x800A9114: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800A9118: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x800A911C: mflo        $t7
    ctx->r15 = lo;
    // 0x800A9120: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x800A9124: jal         0x80059034
    // 0x800A9128: sh          $v0, 0x20($t8)
    MEM_H(0X20, ctx->r24) = ctx->r2;
    spritesound(rdram, ctx);
        goto after_98;
    // 0x800A9128: sh          $v0, 0x20($t8)
    MEM_H(0X20, ctx->r24) = ctx->r2;
    after_98:
    // 0x800A912C: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9130: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A9134: addiu       $t3, $zero, -0x14
    ctx->r11 = ADD32(0, -0X14);
    // 0x800A9138: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A913C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800A9140: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x800A9144: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800A9148: mflo        $t4
    ctx->r12 = lo;
    // 0x800A914C: addu        $s1, $s5, $t4
    ctx->r17 = ADD32(ctx->r21, ctx->r12);
    // 0x800A9150: jal         0x80076190
    // 0x800A9154: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    ssp(rdram, ctx);
        goto after_99;
    // 0x800A9154: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    after_99:
    // 0x800A9158: lh          $t5, 0xD0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A915C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800A9160: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x800A9164: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800A9168: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800A916C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A9170: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800A9174: lh          $t6, 0x8($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0X8));
    // 0x800A9178: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800A917C: sh          $t2, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r10;
    // 0x800A9180: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x800A9184: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x800A9188: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A918C: addu        $v1, $t4, $t8
    ctx->r3 = ADD32(ctx->r12, ctx->r24);
    // 0x800A9190: lw          $t9, 0x0($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800A9194: lw          $t5, 0x4($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800A9198: lw          $t2, 0x4($a2)
    ctx->r10 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A919C: lw          $t3, 0x0($a2)
    ctx->r11 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A91A0: subu        $a1, $t2, $t5
    ctx->r5 = SUB32(ctx->r10, ctx->r13);
    // 0x800A91A4: jal         0x80092024
    // 0x800A91A8: subu        $a0, $t3, $t9
    ctx->r4 = SUB32(ctx->r11, ctx->r25);
    getangle(rdram, ctx);
        goto after_100;
    // 0x800A91A8: subu        $a0, $t3, $t9
    ctx->r4 = SUB32(ctx->r11, ctx->r25);
    after_100:
    // 0x800A91AC: sll         $t4, $s2, 3
    ctx->r12 = S32(ctx->r18 << 3);
    // 0x800A91B0: addu        $t4, $t4, $s2
    ctx->r12 = ADD32(ctx->r12, ctx->r18);
    // 0x800A91B4: addiu       $v1, $v0, -0x200
    ctx->r3 = ADD32(ctx->r2, -0X200);
    // 0x800A91B8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800A91BC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800A91C0: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800A91C4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800A91C8: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A91CC: sh          $v1, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r3;
    // 0x800A91D0: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800A91D4: sw          $t6, -0x5BBC($at)
    MEM_W(-0X5BBC, ctx->r1) = ctx->r14;
    // 0x800A91D8: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x800A91DC: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800A91E0: bnel        $at, $zero, L_800A9D2C
    if (ctx->r1 != 0) {
        // 0x800A91E4: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800A9D2C;
    }
    goto skip_61;
    // 0x800A91E4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_61:
    // 0x800A91E8: lh          $t3, 0x2A0($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2A0));
    // 0x800A91EC: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x800A91F0: b           L_800A9D28
    // 0x800A91F4: sh          $t9, 0x2A0($s0)
    MEM_H(0X2A0, ctx->r16) = ctx->r25;
        goto L_800A9D28;
    // 0x800A91F4: sh          $t9, 0x2A0($s0)
    MEM_H(0X2A0, ctx->r16) = ctx->r25;
L_800A91F8:
    // 0x800A91F8: lh          $t2, 0x22($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, 0X22));
L_800A91FC:
    // 0x800A91FC: addiu       $t5, $zero, -0x60
    ctx->r13 = ADD32(0, -0X60);
    // 0x800A9200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A9204: bltz        $t2, L_800A9210
    if (SIGNED(ctx->r10) < 0) {
        // 0x800A9208: addiu       $a1, $sp, 0xA0
        ctx->r5 = ADD32(ctx->r29, 0XA0);
            goto L_800A9210;
    }
    // 0x800A9208: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x800A920C: sb          $t5, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r13;
L_800A9210:
    // 0x800A9210: jal         0x800ACF18
    // 0x800A9214: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    findplayer(rdram, ctx);
        goto after_101;
    // 0x800A9214: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_101:
    // 0x800A9218: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800A921C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800A9220: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A9224: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800A9228: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A922C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800A9230: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A9234: lui         $s1, 0x802A
    ctx->r17 = S32(0X802A << 16);
    // 0x800A9238: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
    // 0x800A923C: lh          $s1, 0x5A50($s1)
    ctx->r17 = S32(MEM_H(ctx->r17, 0X5A50));
    // 0x800A9240: lw          $a1, 0x78($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A9244: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9248: mflo        $t6
    ctx->r14 = lo;
    // 0x800A924C: addu        $a0, $s5, $t6
    ctx->r4 = ADD32(ctx->r21, ctx->r14);
    // 0x800A9250: jal         0x800ACE8C
    // 0x800A9254: nop

    ldist(rdram, ctx);
        goto after_102;
    // 0x800A9254: nop

    after_102:
    // 0x800A9258: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x800A925C: sra         $t0, $v1, 1
    ctx->r8 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A9260: slti        $at, $t0, -0x1000
    ctx->r1 = SIGNED(ctx->r8) < -0X1000 ? 1 : 0;
    // 0x800A9264: beq         $at, $zero, L_800A9270
    if (ctx->r1 == 0) {
        // 0x800A9268: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800A9270;
    }
    // 0x800A9268: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800A926C: addiu       $t0, $zero, -0x800
    ctx->r8 = ADD32(0, -0X800);
L_800A9270:
    // 0x800A9270: addiu       $t8, $s3, 0x400
    ctx->r24 = ADD32(ctx->r19, 0X400);
    // 0x800A9274: andi        $t3, $t8, 0x7FF
    ctx->r11 = ctx->r24 & 0X7FF;
    // 0x800A9278: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x800A927C: addiu       $t2, $t2, -0x9A0
    ctx->r10 = ADD32(ctx->r10, -0X9A0);
    // 0x800A9280: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x800A9284: addu        $t5, $t9, $t2
    ctx->r13 = ADD32(ctx->r25, ctx->r10);
    // 0x800A9288: lh          $t7, 0x0($t5)
    ctx->r15 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800A928C: addiu       $t8, $s3, 0x200
    ctx->r24 = ADD32(ctx->r19, 0X200);
    // 0x800A9290: andi        $t3, $t8, 0x7FF
    ctx->r11 = ctx->r24 & 0X7FF;
    // 0x800A9294: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x800A9298: addu        $t5, $t9, $t2
    ctx->r13 = ADD32(ctx->r25, ctx->r10);
    // 0x800A929C: sra         $t6, $t7, 8
    ctx->r14 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800A92A0: lh          $t7, 0x0($t5)
    ctx->r15 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800A92A4: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A92A8: lh          $t5, 0xDA($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A92AC: lw          $a3, 0xB8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A92B0: addu        $a1, $t6, $t4
    ctx->r5 = ADD32(ctx->r14, ctx->r12);
    // 0x800A92B4: lw          $t4, 0xBC($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A92B8: sra         $t6, $t7, 8
    ctx->r14 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800A92BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A92C0: sra         $t2, $t1, 4
    ctx->r10 = S32(SIGNED(ctx->r9) >> 4);
    // 0x800A92C4: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800A92C8: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800A92CC: addiu       $t8, $zero, -0x40
    ctx->r24 = ADD32(0, -0X40);
    // 0x800A92D0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A92D4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A92D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A92DC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800A92E0: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800A92E4: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x800A92E8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A92EC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A92F0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800A92F4: lh          $a0, 0xD6($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A92F8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800A92FC: addiu       $a3, $a3, 0x600
    ctx->r7 = ADD32(ctx->r7, 0X600);
    // 0x800A9300: jal         0x8009B028
    // 0x800A9304: addu        $a2, $t6, $t4
    ctx->r6 = ADD32(ctx->r14, ctx->r12);
    EGS(rdram, ctx);
        goto after_103;
    // 0x800A9304: addu        $a2, $t6, $t4
    ctx->r6 = ADD32(ctx->r14, ctx->r12);
    after_103:
    // 0x800A9308: b           L_800A9D2C
    // 0x800A930C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A930C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A9310:
    // 0x800A9310: lh          $t6, 0x22($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800A9314: addiu       $t4, $zero, -0x60
    ctx->r12 = ADD32(0, -0X60);
    // 0x800A9318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A931C: bltz        $t6, L_800A9328
    if (SIGNED(ctx->r14) < 0) {
        // 0x800A9320: addiu       $a1, $sp, 0xA0
        ctx->r5 = ADD32(ctx->r29, 0XA0);
            goto L_800A9328;
    }
    // 0x800A9320: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x800A9324: sb          $t4, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r12;
L_800A9328:
    // 0x800A9328: bltz        $t1, L_800A94C4
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A932C: sll         $t8, $t1, 3
        ctx->r24 = S32(ctx->r9 << 3);
            goto L_800A94C4;
    }
    // 0x800A932C: sll         $t8, $t1, 3
    ctx->r24 = S32(ctx->r9 << 3);
    // 0x800A9330: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800A9334: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800A9338: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x800A933C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A9340: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800A9344: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x800A9348: addiu       $t3, $t3, 0x5770
    ctx->r11 = ADD32(ctx->r11, 0X5770);
    // 0x800A934C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A9350: addu        $s0, $t8, $t3
    ctx->r16 = ADD32(ctx->r24, ctx->r11);
    // 0x800A9354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A9358: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x800A935C: jal         0x800A1F14
    // 0x800A9360: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    aim(rdram, ctx);
        goto after_104;
    // 0x800A9360: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_104:
    // 0x800A9364: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A9368: sra         $t9, $s1, 16
    ctx->r25 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A936C: bltz        $v0, L_800A9468
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A9370: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800A9468;
    }
    // 0x800A9370: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800A9374: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9378: mflo        $t2
    ctx->r10 = lo;
    // 0x800A937C: addu        $a2, $s5, $t2
    ctx->r6 = ADD32(ctx->r21, ctx->r10);
    // 0x800A9380: lhu         $a0, 0xE($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XE);
    // 0x800A9384: jal         0x800B4EA8
    // 0x800A9388: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    gettilesizy(rdram, ctx);
        goto after_105;
    // 0x800A9388: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_105:
    // 0x800A938C: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A9390: lbu         $t5, 0x27($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X27);
    // 0x800A9394: lh          $t6, 0xE($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0XE));
    // 0x800A9398: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A939C: addiu       $t4, $t6, -0x938
    ctx->r12 = ADD32(ctx->r14, -0X938);
    // 0x800A93A0: sltiu       $at, $t4, 0x12
    ctx->r1 = ctx->r12 < 0X12 ? 1 : 0;
    // 0x800A93A4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800A93A8: mflo        $s2
    ctx->r18 = lo;
    // 0x800A93AC: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    // 0x800A93B0: beq         $at, $zero, L_800A93D0
    if (ctx->r1 == 0) {
        // 0x800A93B4: addiu       $s2, $t7, 0x500
        ctx->r18 = ADD32(ctx->r15, 0X500);
            goto L_800A93D0;
    }
    // 0x800A93B4: addiu       $s2, $t7, 0x500
    ctx->r18 = ADD32(ctx->r15, 0X500);
    // 0x800A93B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800A93BC: addu        $at, $at, $t4
    gpr jr_addend_800A93C4 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800A93C0: lw          $t4, -0x7E30($at)
    ctx->r12 = ADD32(ctx->r1, -0X7E30);
    // 0x800A93C4: jr          $t4
    // 0x800A93C8: nop

    switch (jr_addend_800A93C4 >> 2) {
        case 0: goto L_800A93CC; break;
        case 1: goto L_800A93D0; break;
        case 2: goto L_800A93D0; break;
        case 3: goto L_800A93D0; break;
        case 4: goto L_800A93D0; break;
        case 5: goto L_800A93D0; break;
        case 6: goto L_800A93D0; break;
        case 7: goto L_800A93D0; break;
        case 8: goto L_800A93D0; break;
        case 9: goto L_800A93D0; break;
        case 10: goto L_800A93CC; break;
        case 11: goto L_800A93CC; break;
        case 12: goto L_800A93CC; break;
        case 13: goto L_800A93CC; break;
        case 14: goto L_800A93CC; break;
        case 15: goto L_800A93CC; break;
        case 16: goto L_800A93CC; break;
        case 17: goto L_800A93CC; break;
        default: switch_error(__func__, 0x800A93C4, 0x801081D0);
    }
    // 0x800A93C8: nop

L_800A93CC:
    // 0x800A93CC: addiu       $s2, $s2, -0x800
    ctx->r18 = ADD32(ctx->r18, -0X800);
L_800A93D0:
    // 0x800A93D0: lh          $t8, 0x2E0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A93D4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800A93D8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800A93DC: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A93E0: mflo        $t3
    ctx->r11 = lo;
    // 0x800A93E4: addu        $a0, $s5, $t3
    ctx->r4 = ADD32(ctx->r21, ctx->r11);
    // 0x800A93E8: jal         0x800ACE8C
    // 0x800A93EC: nop

    ldist(rdram, ctx);
        goto after_106;
    // 0x800A93EC: nop

    after_106:
    // 0x800A93F0: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A93F4: lw          $t2, 0xB8($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A93F8: lw          $t8, 0xC0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A93FC: lw          $t9, 0x8($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800A9400: lw          $t4, 0x0($a2)
    ctx->r12 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A9404: lw          $t3, 0x4($a2)
    ctx->r11 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A9408: subu        $t5, $t9, $t2
    ctx->r13 = SUB32(ctx->r25, ctx->r10);
    // 0x800A940C: subu        $t7, $t5, $s2
    ctx->r15 = SUB32(ctx->r13, ctx->r18);
    // 0x800A9410: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800A9414: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800A9418: lw          $t9, 0xBC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A941C: mflo        $t0
    ctx->r8 = lo;
    // 0x800A9420: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A9424: bne         $v0, $zero, L_800A9430
    if (ctx->r2 != 0) {
        // 0x800A9428: nop
    
            goto L_800A9430;
    }
    // 0x800A9428: nop

    // 0x800A942C: break       7
    do_break(2148176940);
L_800A9430:
    // 0x800A9430: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A9434: bne         $v0, $at, L_800A9448
    if (ctx->r2 != ctx->r1) {
        // 0x800A9438: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A9448;
    }
    // 0x800A9438: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A943C: bne         $t6, $at, L_800A9448
    if (ctx->r14 != ctx->r1) {
        // 0x800A9440: nop
    
            goto L_800A9448;
    }
    // 0x800A9440: nop

    // 0x800A9444: break       6
    do_break(2148176964);
L_800A9448:
    // 0x800A9448: subu        $a0, $t4, $t8
    ctx->r4 = SUB32(ctx->r12, ctx->r24);
    // 0x800A944C: jal         0x80092024
    // 0x800A9450: subu        $a1, $t3, $t9
    ctx->r5 = SUB32(ctx->r11, ctx->r25);
    getangle(rdram, ctx);
        goto after_107;
    // 0x800A9450: subu        $a1, $t3, $t9
    ctx->r5 = SUB32(ctx->r11, ctx->r25);
    after_107:
    // 0x800A9454: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800A9458: sra         $t2, $s3, 16
    ctx->r10 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800A945C: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
    // 0x800A9460: b           L_800A94B4
    // 0x800A9464: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
        goto L_800A94B4;
    // 0x800A9464: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A9468:
    // 0x800A9468: jal         0x8009800C
    // 0x800A946C: nop

    krand2(rdram, ctx);
        goto after_108;
    // 0x800A946C: nop

    after_108:
    // 0x800A9470: lw          $t4, 0x220($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A9474: lh          $t3, 0x2B8($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A9478: andi        $t5, $v0, 0x1F
    ctx->r13 = ctx->r2 & 0X1F;
    // 0x800A947C: negu        $t8, $t4
    ctx->r24 = SUB32(0, ctx->r12);
    // 0x800A9480: subu        $s3, $s3, $t5
    ctx->r19 = SUB32(ctx->r19, ctx->r13);
    // 0x800A9484: subu        $t0, $t8, $t3
    ctx->r8 = SUB32(ctx->r24, ctx->r11);
    // 0x800A9488: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x800A948C: addiu       $t0, $t0, 0x64
    ctx->r8 = ADD32(ctx->r8, 0X64);
    // 0x800A9490: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800A9494: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x800A9498: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800A949C: jal         0x8009800C
    // 0x800A94A0: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    krand2(rdram, ctx);
        goto after_109;
    // 0x800A94A0: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    after_109:
    // 0x800A94A4: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A94A8: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800A94AC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800A94B0: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
L_800A94B4:
    // 0x800A94B4: lw          $t5, 0xB8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A94B8: addiu       $t7, $t5, -0x200
    ctx->r15 = ADD32(ctx->r13, -0X200);
    // 0x800A94BC: b           L_800A95C0
    // 0x800A94C0: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
        goto L_800A95C0;
    // 0x800A94C0: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
L_800A94C4:
    // 0x800A94C4: jal         0x800ACF18
    // 0x800A94C8: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    findplayer(rdram, ctx);
        goto after_110;
    // 0x800A94C8: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_110:
    // 0x800A94CC: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x800A94D0: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800A94D4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800A94D8: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x800A94DC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A94E0: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800A94E4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A94E8: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x800A94EC: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x800A94F0: lh          $t9, 0x5A50($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X5A50));
    // 0x800A94F4: lw          $t4, 0xB8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A94F8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A94FC: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9500: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A9504: addiu       $t8, $t4, -0x400
    ctx->r24 = ADD32(ctx->r12, -0X400);
    // 0x800A9508: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800A950C: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x800A9510: lw          $a1, 0x78($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A9514: mflo        $t2
    ctx->r10 = lo;
    // 0x800A9518: addu        $a0, $s5, $t2
    ctx->r4 = ADD32(ctx->r21, ctx->r10);
    // 0x800A951C: jal         0x800ACE8C
    // 0x800A9520: nop

    ldist(rdram, ctx);
        goto after_111;
    // 0x800A9520: nop

    after_111:
    // 0x800A9524: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    // 0x800A9528: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800A952C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800A9530: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x800A9534: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A9538: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800A953C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A9540: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800A9544: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800A9548: lw          $t7, 0x598C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, 0X598C));
    // 0x800A954C: lw          $t6, 0xB8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A9550: subu        $t4, $t7, $t6
    ctx->r12 = SUB32(ctx->r15, ctx->r14);
    // 0x800A9554: sll         $t8, $t4, 8
    ctx->r24 = S32(ctx->r12 << 8);
    // 0x800A9558: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800A955C: mflo        $t0
    ctx->r8 = lo;
    // 0x800A9560: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A9564: bne         $v0, $zero, L_800A9570
    if (ctx->r2 != 0) {
        // 0x800A9568: nop
    
            goto L_800A9570;
    }
    // 0x800A9568: nop

    // 0x800A956C: break       7
    do_break(2148177260);
L_800A9570:
    // 0x800A9570: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A9574: bne         $v0, $at, L_800A9588
    if (ctx->r2 != ctx->r1) {
        // 0x800A9578: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A9588;
    }
    // 0x800A9578: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A957C: bne         $t8, $at, L_800A9588
    if (ctx->r24 != ctx->r1) {
        // 0x800A9580: nop
    
            goto L_800A9588;
    }
    // 0x800A9580: nop

    // 0x800A9584: break       6
    do_break(2148177284);
L_800A9588:
    // 0x800A9588: jal         0x8009800C
    // 0x800A958C: nop

    krand2(rdram, ctx);
        goto after_112;
    // 0x800A958C: nop

    after_112:
    // 0x800A9590: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A9594: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x800A9598: subu        $t0, $t0, $t3
    ctx->r8 = SUB32(ctx->r8, ctx->r11);
    // 0x800A959C: addiu       $t0, $t0, 0x80
    ctx->r8 = ADD32(ctx->r8, 0X80);
    // 0x800A95A0: jal         0x8009800C
    // 0x800A95A4: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_113;
    // 0x800A95A4: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    after_113:
    // 0x800A95A8: andi        $t9, $v0, 0x3F
    ctx->r25 = ctx->r2 & 0X3F;
    // 0x800A95AC: subu        $s3, $s3, $t9
    ctx->r19 = SUB32(ctx->r19, ctx->r25);
    // 0x800A95B0: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x800A95B4: sll         $t2, $s3, 16
    ctx->r10 = S32(ctx->r19 << 16);
    // 0x800A95B8: sra         $s3, $t2, 16
    ctx->r19 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800A95BC: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A95C0:
    // 0x800A95C0: lw          $t7, 0x78($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A95C4: addiu       $t8, $s3, 0x200
    ctx->r24 = ADD32(ctx->r19, 0X200);
    // 0x800A95C8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800A95CC: lh          $t6, 0xC($t7)
    ctx->r14 = S32(MEM_H(ctx->r15, 0XC));
    // 0x800A95D0: andi        $t3, $t8, 0x7FF
    ctx->r11 = ctx->r24 & 0X7FF;
    // 0x800A95D4: addiu       $v0, $v0, -0x9A0
    ctx->r2 = ADD32(ctx->r2, -0X9A0);
    // 0x800A95D8: andi        $t4, $t6, 0xFEFE
    ctx->r12 = ctx->r14 & 0XFEFE;
    // 0x800A95DC: sh          $t4, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r12;
    // 0x800A95E0: andi        $t6, $s3, 0x7FF
    ctx->r14 = ctx->r19 & 0X7FF;
    // 0x800A95E4: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x800A95E8: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x800A95EC: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x800A95F0: lh          $t5, 0x0($t2)
    ctx->r13 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800A95F4: addu        $t7, $v0, $t4
    ctx->r15 = ADD32(ctx->r2, ctx->r12);
    // 0x800A95F8: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800A95FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800A9600: addiu       $t5, $sp, 0xD2
    ctx->r13 = ADD32(ctx->r29, 0XD2);
    // 0x800A9604: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A9608: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x800A960C: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x800A9610: addiu       $t7, $sp, 0xA4
    ctx->r15 = ADD32(ctx->r29, 0XA4);
    // 0x800A9614: addiu       $t4, $sp, 0xA8
    ctx->r12 = ADD32(ctx->r29, 0XA8);
    // 0x800A9618: addiu       $t2, $sp, 0xD0
    ctx->r10 = ADD32(ctx->r29, 0XD0);
    // 0x800A961C: addiu       $t6, $sp, 0xAC
    ctx->r14 = ADD32(ctx->r29, 0XAC);
    // 0x800A9620: addiu       $t9, $sp, 0xD4
    ctx->r25 = ADD32(ctx->r29, 0XD4);
    // 0x800A9624: sll         $t3, $t0, 6
    ctx->r11 = S32(ctx->r8 << 6);
    // 0x800A9628: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A962C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A9630: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800A9634: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800A9638: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800A963C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800A9640: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800A9644: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800A9648: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A964C: lh          $a3, 0xD6($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A9650: lw          $a2, 0xB8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A9654: lw          $a1, 0xBC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A9658: jal         0x8009324C
    // 0x800A965C: lw          $a0, 0xC0($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XC0));
    hitscan(rdram, ctx);
        goto after_114;
    // 0x800A965C: lw          $a0, 0xC0($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XC0));
    after_114:
    // 0x800A9660: lw          $t3, 0x78($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A9664: addiu       $t5, $zero, 0x990
    ctx->r13 = ADD32(0, 0X990);
    // 0x800A9668: addiu       $t6, $zero, -0x10
    ctx->r14 = ADD32(0, -0X10);
    // 0x800A966C: lh          $t9, 0xC($t3)
    ctx->r25 = S32(MEM_H(ctx->r11, 0XC));
    // 0x800A9670: addiu       $t4, $zero, 0x1C
    ctx->r12 = ADD32(0, 0X1C);
    // 0x800A9674: addiu       $t7, $zero, 0x1C
    ctx->r15 = ADD32(0, 0X1C);
    // 0x800A9678: ori         $t2, $t9, 0x101
    ctx->r10 = ctx->r25 | 0X101;
    // 0x800A967C: sh          $t2, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r10;
    // 0x800A9680: lh          $t8, 0xDA($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A9684: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A9688: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A968C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A9690: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A9694: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A9698: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800A969C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800A96A0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A96A4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800A96A8: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A96AC: lw          $a2, 0xA8($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A96B0: lw          $a1, 0xAC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A96B4: lh          $a0, 0xD6($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A96B8: jal         0x8009B028
    // 0x800A96BC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    EGS(rdram, ctx);
        goto after_115;
    // 0x800A96BC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_115:
    // 0x800A96C0: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A96C4: lh          $t9, 0xD0($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A96C8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A96CC: sra         $t2, $s1, 16
    ctx->r10 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A96D0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800A96D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A96D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A96DC: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800A96E0: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x800A96E4: mflo        $t3
    ctx->r11 = lo;
    // 0x800A96E8: addu        $v1, $s5, $t3
    ctx->r3 = ADD32(ctx->r21, ctx->r11);
    // 0x800A96EC: lh          $t6, 0xC($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0XC));
    // 0x800A96F0: sb          $t5, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r13;
    // 0x800A96F4: sb          $t8, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r24;
    // 0x800A96F8: ori         $t4, $t6, 0x82
    ctx->r12 = ctx->r14 | 0X82;
    // 0x800A96FC: sh          $t4, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r12;
    // 0x800A9700: bne         $t9, $at, L_800A9764
    if (ctx->r25 != ctx->r1) {
        // 0x800A9704: sb          $t8, 0x27($v1)
        MEM_B(0X27, ctx->r3) = ctx->r24;
            goto L_800A9764;
    }
    // 0x800A9704: sb          $t8, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r24;
    // 0x800A9708: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    // 0x800A970C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A9710: lh          $s2, 0xD4($sp)
    ctx->r18 = S32(MEM_H(ctx->r29, 0XD4));
    // 0x800A9714: bnel        $a3, $at, L_800A9768
    if (ctx->r7 != ctx->r1) {
        // 0x800A9718: lh          $a3, 0xD2($sp)
        ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
            goto L_800A9768;
    }
    goto skip_62;
    // 0x800A9718: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    skip_62:
    // 0x800A971C: bltzl       $s2, L_800A9768
    if (SIGNED(ctx->r18) < 0) {
        // 0x800A9720: lh          $a3, 0xD2($sp)
        ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
            goto L_800A9768;
    }
    goto skip_63;
    // 0x800A9720: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
    skip_63:
    // 0x800A9724: bgez        $t0, L_800A97E8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A9728: sll         $t2, $s2, 2
        ctx->r10 = S32(ctx->r18 << 2);
            goto L_800A97E8;
    }
    // 0x800A9728: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x800A972C: subu        $t2, $t2, $s2
    ctx->r10 = SUB32(ctx->r10, ctx->r18);
    // 0x800A9730: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800A9734: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x800A9738: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A973C: lh          $t3, -0x197C($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X197C));
    // 0x800A9740: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x800A9744: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A9748: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x800A974C: bne         $t5, $zero, L_800A97E8
    if (ctx->r13 != 0) {
        // 0x800A9750: nop
    
            goto L_800A97E8;
    }
    // 0x800A9750: nop

    // 0x800A9754: jal         0x800B147C
    // 0x800A9758: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    checkhitceiling(rdram, ctx);
        goto after_116;
    // 0x800A9758: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_116:
    // 0x800A975C: b           L_800A97E8
    // 0x800A9760: nop

        goto L_800A97E8;
    // 0x800A9760: nop

L_800A9764:
    // 0x800A9764: lh          $a3, 0xD2($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0XD2));
L_800A9768:
    // 0x800A9768: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x800A976C: lh          $t8, 0xD0($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XD0));
    // 0x800A9770: bltz        $a3, L_800A9794
    if (SIGNED(ctx->r7) < 0) {
        // 0x800A9774: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_800A9794;
    }
    // 0x800A9774: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x800A9778: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A977C: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800A9780: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800A9784: jal         0x800B177C
    // 0x800A9788: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    checkhitsprite(rdram, ctx);
        goto after_117;
    // 0x800A9788: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_117:
    // 0x800A978C: b           L_800A97E8
    // 0x800A9790: nop

        goto L_800A97E8;
    // 0x800A9790: nop

L_800A9794:
    // 0x800A9794: bltz        $t8, L_800A97E8
    if (SIGNED(ctx->r24) < 0) {
        // 0x800A9798: sll         $t9, $t8, 3
        ctx->r25 = S32(ctx->r24 << 3);
            goto L_800A97E8;
    }
    // 0x800A9798: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800A979C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A97A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A97A4: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800A97A8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800A97AC: lh          $v0, 0x61B8($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X61B8));
    // 0x800A97B0: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x800A97B4: beq         $v0, $at, L_800A97E8
    if (ctx->r2 == ctx->r1) {
        // 0x800A97B8: addiu       $at, $zero, 0xAA
        ctx->r1 = ADD32(0, 0XAA);
            goto L_800A97E8;
    }
    // 0x800A97B8: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x800A97BC: beq         $v0, $at, L_800A97E8
    if (ctx->r2 == ctx->r1) {
        // 0x800A97C0: sll         $a0, $s1, 16
        ctx->r4 = S32(ctx->r17 << 16);
            goto L_800A97E8;
    }
    // 0x800A97C0: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800A97C4: lw          $t3, 0xA4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x800A97C8: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A97CC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800A97D0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800A97D4: lw          $a2, 0xAC($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x800A97D8: lw          $a3, 0xA8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA8));
    // 0x800A97DC: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800A97E0: jal         0x800B06B8
    // 0x800A97E4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    checkhitwall(rdram, ctx);
        goto after_118;
    // 0x800A97E4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_118:
L_800A97E8:
    // 0x800A97E8: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A97EC: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800A97F0: addiu       $t9, $zero, 0x15C
    ctx->r25 = ADD32(0, 0X15C);
    // 0x800A97F4: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800A97F8: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800A97FC: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x800A9800: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800A9804: mflo        $t5
    ctx->r13 = lo;
    // 0x800A9808: addu        $a2, $s5, $t5
    ctx->r6 = ADD32(ctx->r21, ctx->r13);
    // 0x800A980C: lh          $t6, 0x14($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0X14));
    // 0x800A9810: sh          $t9, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r25;
    // 0x800A9814: addiu       $t4, $t6, 0x400
    ctx->r12 = ADD32(ctx->r14, 0X400);
    // 0x800A9818: andi        $t7, $t4, 0x7FF
    ctx->r15 = ctx->r12 & 0X7FF;
    // 0x800A981C: jal         0x80076190
    // 0x800A9820: sh          $t7, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r15;
    ssp(rdram, ctx);
        goto after_119;
    // 0x800A9820: sh          $t7, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r15;
    after_119:
    // 0x800A9824: b           L_800A9D2C
    // 0x800A9828: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800A9D2C;
    // 0x800A9828: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800A982C: lh          $t8, 0x22($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, 0X22));
L_800A9830:
    // 0x800A9830: addiu       $t3, $zero, -0x60
    ctx->r11 = ADD32(0, -0X60);
    // 0x800A9834: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A9838: bltz        $t8, L_800A9844
    if (SIGNED(ctx->r24) < 0) {
        // 0x800A983C: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800A9844;
    }
    // 0x800A983C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x800A9840: sb          $t3, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r11;
L_800A9844:
    // 0x800A9844: bltz        $t1, L_800A9980
    if (SIGNED(ctx->r9) < 0) {
        // 0x800A9848: sll         $t5, $t1, 3
        ctx->r13 = S32(ctx->r9 << 3);
            goto L_800A9980;
    }
    // 0x800A9848: sll         $t5, $t1, 3
    ctx->r13 = S32(ctx->r9 << 3);
    // 0x800A984C: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x800A9850: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800A9854: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x800A9858: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A985C: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x800A9860: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800A9864: addiu       $t6, $t6, 0x5770
    ctx->r14 = ADD32(ctx->r14, 0X5770);
    // 0x800A9868: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A986C: jal         0x800A1F14
    // 0x800A9870: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    aim(rdram, ctx);
        goto after_120;
    // 0x800A9870: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    after_120:
    // 0x800A9874: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A9878: sra         $t4, $s1, 16
    ctx->r12 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A987C: bltz        $v0, L_800A9954
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A9880: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_800A9954;
    }
    // 0x800A9880: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800A9884: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9888: mflo        $t7
    ctx->r15 = lo;
    // 0x800A988C: addu        $a2, $s5, $t7
    ctx->r6 = ADD32(ctx->r21, ctx->r15);
    // 0x800A9890: lhu         $a0, 0xE($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XE);
    // 0x800A9894: jal         0x800B4EA8
    // 0x800A9898: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    gettilesizy(rdram, ctx);
        goto after_121;
    // 0x800A9898: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_121:
    // 0x800A989C: lw          $a1, 0x70($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A98A0: lh          $t8, 0x2E0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A98A4: lbu         $t9, 0x27($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X27);
    // 0x800A98A8: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A98AC: mflo        $s2
    ctx->r18 = lo;
    // 0x800A98B0: sll         $t2, $s2, 1
    ctx->r10 = S32(ctx->r18 << 1);
    // 0x800A98B4: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x800A98B8: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A98BC: mflo        $t3
    ctx->r11 = lo;
    // 0x800A98C0: addu        $a0, $s5, $t3
    ctx->r4 = ADD32(ctx->r21, ctx->r11);
    // 0x800A98C4: jal         0x800ACE8C
    // 0x800A98C8: nop

    ldist(rdram, ctx);
        goto after_122;
    // 0x800A98C8: nop

    after_122:
    // 0x800A98CC: lw          $a2, 0x70($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X70));
    // 0x800A98D0: lw          $t6, 0xB8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A98D4: lui         $at, 0xFFF4
    ctx->r1 = S32(0XFFF4 << 16);
    // 0x800A98D8: lw          $t5, 0x8($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800A98DC: lw          $t3, 0xC0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A98E0: lw          $t8, 0x0($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800A98E4: subu        $t4, $t5, $t6
    ctx->r12 = SUB32(ctx->r13, ctx->r14);
    // 0x800A98E8: subu        $t7, $t4, $s2
    ctx->r15 = SUB32(ctx->r12, ctx->r18);
    // 0x800A98EC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800A98F0: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800A98F4: sll         $t9, $t9, 8
    ctx->r25 = S32(ctx->r25 << 8);
    // 0x800A98F8: addu        $t2, $t9, $at
    ctx->r10 = ADD32(ctx->r25, ctx->r1);
    // 0x800A98FC: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x800A9900: lw          $t6, 0xBC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A9904: lw          $t5, 0x4($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X4));
    // 0x800A9908: mflo        $t0
    ctx->r8 = lo;
    // 0x800A990C: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A9910: bne         $v0, $zero, L_800A991C
    if (ctx->r2 != 0) {
        // 0x800A9914: nop
    
            goto L_800A991C;
    }
    // 0x800A9914: nop

    // 0x800A9918: break       7
    do_break(2148178200);
L_800A991C:
    // 0x800A991C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A9920: bne         $v0, $at, L_800A9934
    if (ctx->r2 != ctx->r1) {
        // 0x800A9924: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A9934;
    }
    // 0x800A9924: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A9928: bne         $t2, $at, L_800A9934
    if (ctx->r10 != ctx->r1) {
        // 0x800A992C: nop
    
            goto L_800A9934;
    }
    // 0x800A992C: nop

    // 0x800A9930: break       6
    do_break(2148178224);
L_800A9934:
    // 0x800A9934: subu        $a0, $t8, $t3
    ctx->r4 = SUB32(ctx->r24, ctx->r11);
    // 0x800A9938: jal         0x80092024
    // 0x800A993C: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    getangle(rdram, ctx);
        goto after_123;
    // 0x800A993C: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    after_123:
    // 0x800A9940: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800A9944: sra         $t4, $s3, 16
    ctx->r12 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800A9948: or          $s3, $t4, $zero
    ctx->r19 = ctx->r12 | 0;
    // 0x800A994C: b           L_800A9A50
    // 0x800A9950: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
        goto L_800A9A50;
    // 0x800A9950: lw          $t0, 0xB0($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB0));
L_800A9954:
    // 0x800A9954: lw          $t7, 0x220($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A9958: lh          $t2, 0x2B8($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A995C: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800A9960: subu        $t0, $t9, $t2
    ctx->r8 = SUB32(ctx->r25, ctx->r10);
    // 0x800A9964: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800A9968: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800A996C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800A9970: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x800A9974: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800A9978: b           L_800A9A50
    // 0x800A997C: addiu       $t0, $t8, 0x2648
    ctx->r8 = ADD32(ctx->r24, 0X2648);
        goto L_800A9A50;
    // 0x800A997C: addiu       $t0, $t8, 0x2648
    ctx->r8 = ADD32(ctx->r24, 0X2648);
L_800A9980:
    // 0x800A9980: lh          $t3, 0x12($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0X12));
    // 0x800A9984: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A9988: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A998C: beq         $t3, $at, L_800A9A50
    if (ctx->r11 == ctx->r1) {
        // 0x800A9990: addiu       $a1, $sp, 0xA0
        ctx->r5 = ADD32(ctx->r29, 0XA0);
            goto L_800A9A50;
    }
    // 0x800A9990: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x800A9994: jal         0x800ACF18
    // 0x800A9998: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    findplayer(rdram, ctx);
        goto after_124;
    // 0x800A9998: sw          $s1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r17;
    after_124:
    // 0x800A999C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800A99A0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800A99A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800A99A8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800A99AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A99B0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800A99B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A99B8: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x800A99BC: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x800A99C0: lh          $t4, 0x5A50($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, 0X5A50));
    // 0x800A99C4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x800A99C8: sra         $t5, $s1, 16
    ctx->r13 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800A99CC: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A99D0: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x800A99D4: lw          $a1, 0x78($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800A99D8: mflo        $t7
    ctx->r15 = lo;
    // 0x800A99DC: addu        $a0, $s5, $t7
    ctx->r4 = ADD32(ctx->r21, ctx->r15);
    // 0x800A99E0: jal         0x800ACE8C
    // 0x800A99E4: nop

    ldist(rdram, ctx);
        goto after_125;
    // 0x800A99E4: nop

    after_125:
    // 0x800A99E8: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x800A99EC: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x800A99F0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800A99F4: addu        $t9, $t9, $s1
    ctx->r25 = ADD32(ctx->r25, ctx->r17);
    // 0x800A99F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A99FC: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x800A9A00: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A9A04: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x800A9A08: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800A9A0C: lw          $t2, 0x59B0($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X59B0));
    // 0x800A9A10: lw          $t8, 0xB8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A9A14: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800A9A18: sra         $t4, $t6, 16
    ctx->r12 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800A9A1C: subu        $t3, $t2, $t8
    ctx->r11 = SUB32(ctx->r10, ctx->r24);
    // 0x800A9A20: sll         $t5, $t3, 9
    ctx->r13 = S32(ctx->r11 << 9);
    // 0x800A9A24: div         $zero, $t5, $t4
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r12)));
    // 0x800A9A28: mflo        $t0
    ctx->r8 = lo;
    // 0x800A9A2C: bne         $t4, $zero, L_800A9A38
    if (ctx->r12 != 0) {
        // 0x800A9A30: nop
    
            goto L_800A9A38;
    }
    // 0x800A9A30: nop

    // 0x800A9A34: break       7
    do_break(2148178484);
L_800A9A38:
    // 0x800A9A38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A9A3C: bne         $t4, $at, L_800A9A50
    if (ctx->r12 != ctx->r1) {
        // 0x800A9A40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A9A50;
    }
    // 0x800A9A40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A9A44: bne         $t5, $at, L_800A9A50
    if (ctx->r13 != ctx->r1) {
        // 0x800A9A48: nop
    
            goto L_800A9A50;
    }
    // 0x800A9A48: nop

    // 0x800A9A4C: break       6
    do_break(2148178508);
L_800A9A50:
    // 0x800A9A50: addiu       $t7, $s3, 0x400
    ctx->r15 = ADD32(ctx->r19, 0X400);
    // 0x800A9A54: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800A9A58: andi        $t9, $t7, 0x7FF
    ctx->r25 = ctx->r15 & 0X7FF;
    // 0x800A9A5C: addiu       $v0, $v0, -0x9A0
    ctx->r2 = ADD32(ctx->r2, -0X9A0);
    // 0x800A9A60: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x800A9A64: addiu       $t4, $s3, 0x200
    ctx->r12 = ADD32(ctx->r19, 0X200);
    // 0x800A9A68: andi        $t7, $t4, 0x7FF
    ctx->r15 = ctx->r12 & 0X7FF;
    // 0x800A9A6C: addu        $t8, $v0, $t2
    ctx->r24 = ADD32(ctx->r2, ctx->r10);
    // 0x800A9A70: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800A9A74: lh          $t3, 0x0($t8)
    ctx->r11 = S32(MEM_H(ctx->r24, 0X0));
    // 0x800A9A78: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x800A9A7C: lh          $t8, 0x0($t2)
    ctx->r24 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800A9A80: lw          $t5, 0xC0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A9A84: sra         $t6, $t3, 12
    ctx->r14 = S32(SIGNED(ctx->r11) >> 12);
    // 0x800A9A88: sra         $t3, $t8, 12
    ctx->r11 = S32(SIGNED(ctx->r24) >> 12);
    // 0x800A9A8C: addu        $a1, $t6, $t5
    ctx->r5 = ADD32(ctx->r14, ctx->r13);
    // 0x800A9A90: lw          $t6, 0xBC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A9A94: lh          $t8, 0xDA($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A9A98: lw          $a3, 0xB8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A9A9C: addu        $a2, $t3, $t6
    ctx->r6 = ADD32(ctx->r11, ctx->r14);
    // 0x800A9AA0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800A9AA4: addiu       $t5, $zero, 0x66E
    ctx->r13 = ADD32(0, 0X66E);
    // 0x800A9AA8: addiu       $t2, $zero, 0x300
    ctx->r10 = ADD32(0, 0X300);
    // 0x800A9AAC: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x800A9AB0: addiu       $t7, $zero, 0x1C
    ctx->r15 = ADD32(0, 0X1C);
    // 0x800A9AB4: addiu       $t4, $zero, -0x10
    ctx->r12 = ADD32(0, -0X10);
    // 0x800A9AB8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800A9ABC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800A9AC0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A9AC4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800A9AC8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800A9ACC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800A9AD0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A9AD4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A9AD8: lh          $a0, 0xD6($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A9ADC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800A9AE0: jal         0x8009B028
    // 0x800A9AE4: addiu       $a3, $a3, 0x200
    ctx->r7 = ADD32(ctx->r7, 0X200);
    EGS(rdram, ctx);
        goto after_126;
    // 0x800A9AE4: addiu       $a3, $a3, 0x200
    ctx->r7 = ADD32(ctx->r7, 0X200);
    after_126:
    // 0x800A9AE8: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9AEC: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x800A9AF0: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x800A9AF4: mflo        $t6
    ctx->r14 = lo;
    // 0x800A9AF8: addu        $v1, $s5, $t6
    ctx->r3 = ADD32(ctx->r21, ctx->r14);
    // 0x800A9AFC: sh          $t5, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r13;
    // 0x800A9B00: b           L_800A9D28
    // 0x800A9B04: sb          $t4, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r12;
        goto L_800A9D28;
    // 0x800A9B04: sb          $t4, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r12;
L_800A9B08:
    // 0x800A9B08: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x800A9B0C: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x800A9B10: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A9B14: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800A9B18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A9B1C: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x800A9B20: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x800A9B24: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x800A9B28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A9B2C: addu        $s0, $t7, $t9
    ctx->r16 = ADD32(ctx->r15, ctx->r25);
    // 0x800A9B30: lh          $t2, 0x2B8($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2B8));
    // 0x800A9B34: lw          $t8, 0x220($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X220));
    // 0x800A9B38: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800A9B3C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A9B40: addu        $t3, $t2, $t8
    ctx->r11 = ADD32(ctx->r10, ctx->r24);
    // 0x800A9B44: addiu       $t6, $t3, -0x64
    ctx->r14 = ADD32(ctx->r11, -0X64);
    // 0x800A9B48: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A9B4C: jal         0x8006E420
    // 0x800A9B50: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    getanglef(rdram, ctx);
        goto after_127;
    // 0x800A9B50: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_127:
    // 0x800A9B54: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800A9B58: addiu       $s0, $s0, -0x651C
    ctx->r16 = ADD32(ctx->r16, -0X651C);
    // 0x800A9B5C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800A9B60: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800A9B64: lwc1        $f16, -0x7DE8($at)
    ctx->f16.u32l = S32(MEM_W(ctx->r1, -0X7DE8));
    // 0x800A9B68: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x800A9B6C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800A9B70: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A9B74: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800A9B78: lwc1        $f8, -0x7DE4($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, -0X7DE4));
    // 0x800A9B7C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x800A9B80: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800A9B84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9B88: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800A9B8C: jal         0x800C2DB0
    // 0x800A9B90: div.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    __cosf_recomp(rdram, ctx);
        goto after_128;
    // 0x800A9B90: div.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    after_128:
    // 0x800A9B94: lui         $at, 0x4440
    ctx->r1 = S32(0X4440 << 16);
    // 0x800A9B98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9B9C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800A9BA0: lwc1        $f10, -0x7DE0($at)
    ctx->f10.u32l = S32(MEM_W(ctx->r1, -0X7DE0));
    // 0x800A9BA4: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800A9BA8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x800A9BAC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800A9BB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9BB4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A9BB8: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A9BBC: div.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A9BC0: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x800A9BC4: jal         0x800C2BF0
    // 0x800A9BC8: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    __sinf_recomp(rdram, ctx);
        goto after_129;
    // 0x800A9BC8: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    after_129:
    // 0x800A9BCC: lui         $at, 0x4440
    ctx->r1 = S32(0X4440 << 16);
    // 0x800A9BD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A9BD4: lh          $t9, 0xD6($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A9BD8: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800A9BDC: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A9BE0: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800A9BE4: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x800A9BE8: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800A9BEC: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x800A9BF0: lh          $t8, -0x1970($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X1970));
    // 0x800A9BF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9BF8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A9BFC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800A9C00: addiu       $t5, $s3, 0x35C
    ctx->r13 = ADD32(ctx->r19, 0X35C);
    // 0x800A9C04: addiu       $v1, $v1, -0x9A0
    ctx->r3 = ADD32(ctx->r3, -0X9A0);
    // 0x800A9C08: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800A9C0C: andi        $t4, $t5, 0x7FF
    ctx->r12 = ctx->r13 & 0X7FF;
    // 0x800A9C10: bne         $t8, $at, L_800A9C40
    if (ctx->r24 != ctx->r1) {
        // 0x800A9C14: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800A9C40;
    }
    // 0x800A9C14: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800A9C18: lw          $t3, 0xB4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800A9C1C: bgez        $t3, L_800A9C2C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A9C20: sra         $t6, $t3, 1
        ctx->r14 = S32(SIGNED(ctx->r11) >> 1);
            goto L_800A9C2C;
    }
    // 0x800A9C20: sra         $t6, $t3, 1
    ctx->r14 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800A9C24: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x800A9C28: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_800A9C2C:
    // 0x800A9C2C: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x800A9C30: bgez        $v0, L_800A9C40
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A9C34: sra         $t0, $v0, 1
        ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800A9C40;
    }
    // 0x800A9C34: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800A9C38: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x800A9C3C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_800A9C40:
    // 0x800A9C40: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800A9C44: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800A9C48: lh          $t2, 0x0($t9)
    ctx->r10 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800A9C4C: addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // 0x800A9C50: addiu       $t6, $s3, 0x15C
    ctx->r14 = ADD32(ctx->r19, 0X15C);
    // 0x800A9C54: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x800A9C58: andi        $t5, $t6, 0x7FF
    ctx->r13 = ctx->r14 & 0X7FF;
    // 0x800A9C5C: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x800A9C60: addu        $t7, $v1, $t4
    ctx->r15 = ADD32(ctx->r3, ctx->r12);
    // 0x800A9C64: lh          $t9, 0x0($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800A9C68: mflo        $t8
    ctx->r24 = lo;
    // 0x800A9C6C: lw          $t3, 0xC0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XC0));
    // 0x800A9C70: lh          $t7, 0xDA($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XDA));
    // 0x800A9C74: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x800A9C78: addu        $a1, $t8, $t3
    ctx->r5 = ADD32(ctx->r24, ctx->r11);
    // 0x800A9C7C: lw          $t8, 0xBC($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800A9C80: lw          $t5, 0xB4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800A9C84: lw          $a3, 0xB8($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800A9C88: addiu       $t3, $zero, 0x12
    ctx->r11 = ADD32(0, 0X12);
    // 0x800A9C8C: sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8 << 4);
    // 0x800A9C90: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x800A9C94: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A9C98: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800A9C9C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800A9CA0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A9CA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800A9CA8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800A9CAC: lh          $a0, 0xD6($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XD6));
    // 0x800A9CB0: bne         $v0, $zero, L_800A9CBC
    if (ctx->r2 != 0) {
        // 0x800A9CB4: nop
    
            goto L_800A9CBC;
    }
    // 0x800A9CB4: nop

    // 0x800A9CB8: break       7
    do_break(2148179128);
L_800A9CBC:
    // 0x800A9CBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A9CC0: bne         $v0, $at, L_800A9CD4
    if (ctx->r2 != ctx->r1) {
        // 0x800A9CC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A9CD4;
    }
    // 0x800A9CC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A9CC8: bne         $t2, $at, L_800A9CD4
    if (ctx->r10 != ctx->r1) {
        // 0x800A9CCC: nop
    
            goto L_800A9CD4;
    }
    // 0x800A9CCC: nop

    // 0x800A9CD0: break       6
    do_break(2148179152);
L_800A9CD4:
    // 0x800A9CD4: mflo        $t2
    ctx->r10 = lo;
    // 0x800A9CD8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800A9CDC: bne         $v0, $zero, L_800A9CE8
    if (ctx->r2 != 0) {
        // 0x800A9CE0: nop
    
            goto L_800A9CE8;
    }
    // 0x800A9CE0: nop

    // 0x800A9CE4: break       7
    do_break(2148179172);
L_800A9CE8:
    // 0x800A9CE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A9CEC: bne         $v0, $at, L_800A9D00
    if (ctx->r2 != ctx->r1) {
        // 0x800A9CF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A9D00;
    }
    // 0x800A9CF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A9CF4: bne         $t9, $at, L_800A9D00
    if (ctx->r25 != ctx->r1) {
        // 0x800A9CF8: nop
    
            goto L_800A9D00;
    }
    // 0x800A9CF8: nop

    // 0x800A9CFC: break       6
    do_break(2148179196);
L_800A9D00:
    // 0x800A9D00: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A9D04: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A9D08: addu        $a2, $t2, $t8
    ctx->r6 = ADD32(ctx->r10, ctx->r24);
    // 0x800A9D0C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800A9D10: jal         0x8009B028
    // 0x800A9D14: addiu       $a3, $a3, -0x100
    ctx->r7 = ADD32(ctx->r7, -0X100);
    EGS(rdram, ctx);
        goto after_130;
    // 0x800A9D14: addiu       $a3, $a3, -0x100
    ctx->r7 = ADD32(ctx->r7, -0X100);
    after_130:
    // 0x800A9D18: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A9D1C: mflo        $t2
    ctx->r10 = lo;
    // 0x800A9D20: addu        $t8, $s5, $t2
    ctx->r24 = ADD32(ctx->r21, ctx->r10);
    // 0x800A9D24: sh          $zero, 0x1A($t8)
    MEM_H(0X1A, ctx->r24) = 0;
L_800A9D28:
    // 0x800A9D28: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800A9D2C:
    // 0x800A9D2C: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800A9D30: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800A9D34: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800A9D38: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800A9D3C: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800A9D40: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800A9D44: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800A9D48: jr          $ra
    // 0x800A9D4C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800A9D4C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void scansector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005962C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80059630: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80059634: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80059638: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8005963C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80059640: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80059644: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x80059648: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8005964C: lui         $s5, 0x8022
    ctx->r21 = S32(0X8022 << 16);
    // 0x80059650: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80059654: lh          $t8, 0x16($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X16));
    // 0x80059658: addiu       $s5, $s5, -0x523C
    ctx->r21 = ADD32(ctx->r21, -0X523C);
    // 0x8005965C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80059660: lw          $s6, 0x0($s5)
    ctx->r22 = S32(MEM_W(ctx->r21, 0X0));
    // 0x80059664: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80059668: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8005966C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80059670: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80059674: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80059678: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8005967C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80059680: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80059684: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80059688: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8005968C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80059690: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80059694: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80059698: swc1        $f12, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f12.u32l;
    // 0x8005969C: swc1        $f14, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f14.u32l;
    // 0x800596A0: sw          $a3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r7;
    // 0x800596A4: beq         $t8, $zero, L_800596DC
    if (ctx->r24 == 0) {
        // 0x800596A8: sw          $s6, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r22;
            goto L_800596DC;
    }
    // 0x800596A8: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x800596AC: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x800596B0: addiu       $t0, $t0, -0x5360
    ctx->r8 = ADD32(ctx->r8, -0X5360);
    // 0x800596B4: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800596B8: andi        $t2, $a2, 0x7
    ctx->r10 = ctx->r6 & 0X7;
    // 0x800596BC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800596C0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800596C4: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800596C8: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x800596CC: lbu         $t3, 0x4D90($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4D90);
    // 0x800596D0: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800596D4: b           L_8005971C
    // 0x800596D8: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
        goto L_8005971C;
    // 0x800596D8: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_800596DC:
    // 0x800596DC: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800596E0: lw          $t5, -0x2348($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X2348));
    // 0x800596E4: lw          $t6, 0x4($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800596E8: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800596EC: beq         $at, $zero, L_8005971C
    if (ctx->r1 == 0) {
        // 0x800596F0: lui         $t8, 0x8022
        ctx->r24 = S32(0X8022 << 16);
            goto L_8005971C;
    }
    // 0x800596F0: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800596F4: addiu       $t8, $t8, -0x5360
    ctx->r24 = ADD32(ctx->r24, -0X5360);
    // 0x800596F8: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800596FC: andi        $t0, $a2, 0x7
    ctx->r8 = ctx->r6 & 0X7;
    // 0x80059700: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80059704: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80059708: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8005970C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80059710: lbu         $t2, 0x4D90($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4D90);
    // 0x80059714: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x80059718: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_8005971C:
    // 0x8005971C: lh          $t4, 0x12($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X12));
    // 0x80059720: andi        $t3, $a2, 0x7
    ctx->r11 = ctx->r6 & 0X7;
    // 0x80059724: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80059728: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8005972C: lbu         $a0, 0x4D90($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4D90);
    // 0x80059730: beq         $t4, $zero, L_80059754
    if (ctx->r12 == 0) {
        // 0x80059734: sra         $v1, $a2, 3
        ctx->r3 = S32(SIGNED(ctx->r6) >> 3);
            goto L_80059754;
    }
    // 0x80059734: sra         $v1, $a2, 3
    ctx->r3 = S32(SIGNED(ctx->r6) >> 3);
    // 0x80059738: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x8005973C: addiu       $t5, $t5, -0x5308
    ctx->r13 = ADD32(ctx->r13, -0X5308);
    // 0x80059740: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x80059744: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80059748: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x8005974C: b           L_80059780
    // 0x80059750: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_80059780;
    // 0x80059750: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_80059754:
    // 0x80059754: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x80059758: lw          $t0, -0x2348($t0)
    ctx->r8 = S32(MEM_W(ctx->r8, -0X2348));
    // 0x8005975C: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80059760: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80059764: beq         $at, $zero, L_80059780
    if (ctx->r1 == 0) {
        // 0x80059768: lui         $t9, 0x8022
        ctx->r25 = S32(0X8022 << 16);
            goto L_80059780;
    }
    // 0x80059768: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x8005976C: addiu       $t9, $t9, -0x5308
    ctx->r25 = ADD32(ctx->r25, -0X5308);
    // 0x80059770: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x80059774: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80059778: or          $t1, $t2, $a0
    ctx->r9 = ctx->r10 | ctx->r4;
    // 0x8005977C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_80059780:
    // 0x80059780: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80059784: lwc1        $f26, 0x48B4($at)
    ctx->f26.u32l = S32(MEM_W(ctx->r1, 0X48B4));
    // 0x80059788: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0XD0));
    // 0x8005978C: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80059790: addiu       $t3, $t3, -0x52B0
    ctx->r11 = ADD32(ctx->r11, -0X52B0);
    // 0x80059794: mul.s       $f20, $f4, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80059798: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x8005979C: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800597A0: or          $t5, $t4, $a0
    ctx->r13 = ctx->r12 | ctx->r4;
    // 0x800597A4: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x800597A8: jal         0x800C2BF0
    // 0x800597AC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800597AC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x800597B0: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800597B4: addiu       $fp, $fp, -0x525C
    ctx->r30 = ADD32(ctx->r30, -0X525C);
    // 0x800597B8: lw          $t6, 0x0($fp)
    ctx->r14 = S32(MEM_W(ctx->r30, 0X0));
    // 0x800597BC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800597C0: lwc1        $f24, 0x48B8($at)
    ctx->f24.u32l = S32(MEM_W(ctx->r1, 0X48B8));
    // 0x800597C4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800597C8: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800597CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800597D0: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0XD4));
    // 0x800597D4: mul.s       $f22, $f8, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800597D8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800597DC: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x800597E0: jal         0x800C2BF0
    // 0x800597E4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800597E4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x800597E8: lw          $t7, 0x0($fp)
    ctx->r15 = S32(MEM_W(ctx->r30, 0X0));
    // 0x800597EC: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800597F0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800597F4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800597F8: nop

    // 0x800597FC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80059800: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80059804: jal         0x800C2DB0
    // 0x80059808: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80059808: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8005980C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80059810: lw          $t8, -0x5258($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X5258));
    // 0x80059814: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80059818: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8005981C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80059820: nop

    // 0x80059824: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80059828: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8005982C: jal         0x800C2DB0
    // 0x80059830: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x80059830: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80059834: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x80059838: lw          $t0, -0x5258($t0)
    ctx->r8 = S32(MEM_W(ctx->r8, -0X5258));
    // 0x8005983C: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80059840: lh          $s3, 0x8($s0)
    ctx->r19 = S32(MEM_H(ctx->r16, 0X8));
    // 0x80059844: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80059848: lh          $t9, 0xA($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0XA));
    // 0x8005984C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80059850: addu        $v1, $t9, $s3
    ctx->r3 = ADD32(ctx->r25, ctx->r19);
    // 0x80059854: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80059858: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8005985C: beq         $at, $zero, L_80059C20
    if (ctx->r1 == 0) {
        // 0x80059860: swc1        $f8, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
            goto L_80059C20;
    }
    // 0x80059860: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x80059864: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x80059868: addiu       $s4, $s4, 0x61A8
    ctx->r20 = ADD32(ctx->r20, 0X61A8);
    // 0x8005986C: sw          $v1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r3;
    // 0x80059870: addiu       $s7, $zero, 0x24
    ctx->r23 = ADD32(0, 0X24);
L_80059874:
    // 0x80059874: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80059878: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x8005987C: addiu       $t3, $t3, -0x5530
    ctx->r11 = ADD32(ctx->r11, -0X5530);
    // 0x80059880: addiu       $t1, $t1, 0x4D90
    ctx->r9 = ADD32(ctx->r9, 0X4D90);
    // 0x80059884: andi        $t2, $s3, 0x7
    ctx->r10 = ctx->r19 & 0X7;
    // 0x80059888: sra         $a3, $s3, 3
    ctx->r7 = S32(SIGNED(ctx->r19) >> 3);
    // 0x8005988C: addu        $s1, $a3, $t3
    ctx->r17 = ADD32(ctx->r7, ctx->r11);
    // 0x80059890: addu        $s2, $t2, $t1
    ctx->r18 = ADD32(ctx->r10, ctx->r9);
    // 0x80059894: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80059898: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x8005989C: and         $t4, $a1, $a2
    ctx->r12 = ctx->r5 & ctx->r6;
    // 0x800598A0: bnel        $t4, $zero, L_80059C10
    if (ctx->r12 != 0) {
        // 0x800598A4: lw          $t4, 0xC0($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
            goto L_80059C10;
    }
    goto skip_0;
    // 0x800598A4: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    skip_0:
    // 0x800598A8: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800598AC: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x800598B0: lw          $t1, 0x0($fp)
    ctx->r9 = S32(MEM_W(ctx->r30, 0X0));
    // 0x800598B4: lw          $t3, -0x5258($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, -0X5258));
    // 0x800598B8: or          $t4, $a2, $a1
    ctx->r12 = ctx->r6 | ctx->r5;
    // 0x800598BC: mflo        $t5
    ctx->r13 = lo;
    // 0x800598C0: addu        $a0, $s4, $t5
    ctx->r4 = ADD32(ctx->r20, ctx->r13);
    // 0x800598C4: lh          $t8, 0x8($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X8));
    // 0x800598C8: lw          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800598CC: lw          $t7, 0x4($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800598D0: multu       $t8, $s7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800598D4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800598D8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800598DC: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800598E0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800598E4: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800598E8: mflo        $t0
    ctx->r8 = lo;
    // 0x800598EC: addu        $v0, $s4, $t0
    ctx->r2 = ADD32(ctx->r20, ctx->r8);
    // 0x800598F0: lw          $t2, 0x4($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800598F4: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800598F8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800598FC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80059900: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80059904: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80059908: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005990C: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80059910: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X74));
    // 0x80059914: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X90));
    // 0x80059918: cvt.s.w     $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    ctx->f26.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005991C: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x80059920: cvt.s.w     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    ctx->f24.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059924: sub.s       $f0, $f20, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f16.fl;
    // 0x80059928: sub.s       $f14, $f26, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f26.fl - ctx->f18.fl;
    // 0x8005992C: sub.s       $f2, $f24, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f16.fl;
    // 0x80059930: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80059934: sub.s       $f12, $f22, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f22.fl - ctx->f18.fl;
    // 0x80059938: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8005993C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80059940: nop

    // 0x80059944: bc1fl       L_80059958
    if (!c1cs) {
        // 0x80059948: sub.s       $f16, $f10, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f20.fl;
            goto L_80059958;
    }
    goto skip_1;
    // 0x80059948: sub.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f20.fl;
    skip_1:
    // 0x8005994C: b           L_80059C0C
    // 0x80059950: sb          $t4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r12;
        goto L_80059C0C;
    // 0x80059950: sb          $t4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r12;
    // 0x80059954: sub.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f20.fl;
L_80059958:
    // 0x80059958: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X94));
    // 0x8005995C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X70));
    // 0x80059960: sub.s       $f4, $f6, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80059964: sub.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x80059968: mul.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8005996C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X98));
    // 0x80059970: sub.s       $f18, $f8, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x80059974: mul.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80059978: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X9C));
    // 0x8005997C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80059980: nop

    // 0x80059984: bc1tl       L_800599B4
    if (c1cs) {
        // 0x80059988: lwc1        $f6, 0x74($sp)
        ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X74));
            goto L_800599B4;
    }
    goto skip_2;
    // 0x80059988: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X74));
    skip_2:
    // 0x8005998C: sub.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80059990: sub.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x80059994: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80059998: nop

    // 0x8005999C: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800599A0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800599A4: nop

    // 0x800599A8: bc1t        L_80059A7C
    if (c1cs) {
        // 0x800599AC: nop
    
            goto L_80059A7C;
    }
    // 0x800599AC: nop

    // 0x800599B0: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X74));
L_800599B4:
    // 0x800599B4: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X90));
    // 0x800599B8: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X70));
    // 0x800599BC: sub.s       $f28, $f6, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f28.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x800599C0: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X94));
    // 0x800599C4: sub.s       $f10, $f4, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x800599C8: sub.s       $f30, $f8, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x800599CC: mul.s       $f12, $f28, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f28.fl, ctx->f10.fl);
    // 0x800599D0: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X98));
    // 0x800599D4: sub.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x800599D8: mul.s       $f14, $f4, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x800599DC: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800599E0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x800599E4: nop

    // 0x800599E8: bc1tl       L_80059A18
    if (c1cs) {
        // 0x800599EC: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80059A18;
    }
    goto skip_3;
    // 0x800599EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_3:
    // 0x800599F0: sub.s       $f8, $f10, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f26.fl;
    // 0x800599F4: sub.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x800599F8: mul.s       $f6, $f28, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f8.fl);
    // 0x800599FC: nop

    // 0x80059A00: mul.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x80059A04: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80059A08: nop

    // 0x80059A0C: bc1t        L_80059A7C
    if (c1cs) {
        // 0x80059A10: nop
    
            goto L_80059A7C;
    }
    // 0x80059A10: nop

    // 0x80059A14: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80059A18:
    // 0x80059A18: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X98));
    // 0x80059A1C: bc1fl       L_80059C10
    if (!c1cs) {
        // 0x80059A20: lw          $t4, 0xC0($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
            goto L_80059C10;
    }
    goto skip_4;
    // 0x80059A20: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    skip_4:
    // 0x80059A24: sub.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80059A28: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80059A2C: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80059A30: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x80059A34: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80059A38: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80059A3C: nop

    // 0x80059A40: bc1fl       L_80059C10
    if (!c1cs) {
        // 0x80059A44: lw          $t4, 0xC0($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
            goto L_80059C10;
    }
    goto skip_5;
    // 0x80059A44: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    skip_5:
    // 0x80059A48: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80059A4C: nop

    // 0x80059A50: bc1tl       L_80059C10
    if (c1cs) {
        // 0x80059A54: lw          $t4, 0xC0($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
            goto L_80059C10;
    }
    goto skip_6;
    // 0x80059A54: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    skip_6:
    // 0x80059A58: sub.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x80059A5C: sub.s       $f4, $f8, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80059A60: mul.s       $f10, $f28, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f6.fl);
    // 0x80059A64: nop

    // 0x80059A68: mul.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80059A6C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80059A70: nop

    // 0x80059A74: bc1t        L_80059C0C
    if (c1cs) {
        // 0x80059A78: nop
    
            goto L_80059C0C;
    }
    // 0x80059A78: nop

L_80059A7C:
    // 0x80059A7C: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80059A80: addiu       $t5, $t5, -0x5700
    ctx->r13 = ADD32(ctx->r13, -0X5700);
    // 0x80059A84: addu        $v0, $a3, $t5
    ctx->r2 = ADD32(ctx->r7, ctx->r13);
    // 0x80059A88: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80059A8C: lh          $v1, 0xC($a0)
    ctx->r3 = S32(MEM_H(ctx->r4, 0XC));
    // 0x80059A90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80059A94: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80059A98: bne         $v1, $at, L_80059AAC
    if (ctx->r3 != ctx->r1) {
        // 0x80059A9C: sb          $t7, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r15;
            goto L_80059AAC;
    }
    // 0x80059A9C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80059AA0: or          $t8, $a2, $a1
    ctx->r24 = ctx->r6 | ctx->r5;
    // 0x80059AA4: b           L_80059C0C
    // 0x80059AA8: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
        goto L_80059C0C;
    // 0x80059AA8: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
L_80059AAC:
    // 0x80059AAC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80059AB0: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80059AB4: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80059AB8: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x80059ABC: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80059AC0: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x80059AC4: lw          $t2, 0x0($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80059AC8: lw          $t1, 0x4($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80059ACC: lw          $a3, 0x70($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X70));
    // 0x80059AD0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80059AD4: bnel        $t2, $t1, L_80059AFC
    if (ctx->r10 != ctx->r9) {
        // 0x80059AD8: mov.s       $f12, $f24
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
            goto L_80059AFC;
    }
    goto skip_7;
    // 0x80059AD8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    skip_7:
    // 0x80059ADC: lh          $t3, 0x12($v0)
    ctx->r11 = S32(MEM_H(ctx->r2, 0X12));
    // 0x80059AE0: lh          $t4, 0x16($v0)
    ctx->r12 = S32(MEM_H(ctx->r2, 0X16));
    // 0x80059AE4: or          $t5, $a2, $a1
    ctx->r13 = ctx->r6 | ctx->r5;
    // 0x80059AE8: bnel        $t3, $t4, L_80059AFC
    if (ctx->r11 != ctx->r12) {
        // 0x80059AEC: mov.s       $f12, $f24
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
            goto L_80059AFC;
    }
    goto skip_8;
    // 0x80059AEC: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    skip_8:
    // 0x80059AF0: b           L_80059C0C
    // 0x80059AF4: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
        goto L_80059C0C;
    // 0x80059AF4: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
    // 0x80059AF8: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
L_80059AFC:
    // 0x80059AFC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x80059B00: jal         0x800595D4
    // 0x80059B04: lw          $a2, 0x74($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X74));
    getanglef2(rdram, ctx);
        goto after_4;
    // 0x80059B04: lw          $a2, 0x74($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X74));
    after_4:
    // 0x80059B08: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80059B0C: lw          $t7, -0x5258($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X5258));
    // 0x80059B10: lw          $t6, 0x0($fp)
    ctx->r14 = S32(MEM_W(ctx->r30, 0X0));
    // 0x80059B14: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80059B18: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80059B1C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80059B20: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80059B24: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059B28: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80059B2C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80059B30: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80059B34: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80059B38: jal         0x800595D4
    // 0x80059B3C: nop

    getanglef2(rdram, ctx);
        goto after_5;
    // 0x80059B3C: nop

    after_5:
    // 0x80059B40: lwc1        $f26, 0xD0($sp)
    ctx->f26.u32l = S32(MEM_W(ctx->r29, 0XD0));
    // 0x80059B44: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80059B48: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80059B4C: jal         0x80059554
    // 0x80059B50: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    getangledelta(rdram, ctx);
        goto after_6;
    // 0x80059B50: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_6:
    // 0x80059B54: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80059B58: lwc1        $f22, 0xD4($sp)
    ctx->f22.u32l = S32(MEM_W(ctx->r29, 0XD4));
    // 0x80059B5C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80059B60: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80059B64: bc1f        L_80059B74
    if (!c1cs) {
        // 0x80059B68: nop
    
            goto L_80059B74;
    }
    // 0x80059B68: nop

    // 0x80059B6C: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x80059B70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80059B74:
    // 0x80059B74: jal         0x80059554
    // 0x80059B78: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    getangledelta(rdram, ctx);
        goto after_7;
    // 0x80059B78: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_7:
    // 0x80059B7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059B80: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80059B84: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80059B88: nop

    // 0x80059B8C: bc1f        L_80059B9C
    if (!c1cs) {
        // 0x80059B90: nop
    
            goto L_80059B9C;
    }
    // 0x80059B90: nop

    // 0x80059B94: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80059B98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80059B9C:
    // 0x80059B9C: beql        $s0, $zero, L_80059BB8
    if (ctx->r16 == 0) {
        // 0x80059BA0: mfc1        $a2, $f20
        ctx->r6 = (int32_t)ctx->f20.u32l;
            goto L_80059BB8;
    }
    goto skip_9;
    // 0x80059BA0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    skip_9:
    // 0x80059BA4: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80059BA8: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x80059BAC: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x80059BB0: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x80059BB4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_80059BB8:
    // 0x80059BB8: jal         0x80059CE8
    // 0x80059BBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    viswallcheck(rdram, ctx);
        goto after_8;
    // 0x80059BBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x80059BC0: beql        $v0, $zero, L_80059C10
    if (ctx->r2 == 0) {
        // 0x80059BC4: lw          $t4, 0xC0($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
            goto L_80059C10;
    }
    goto skip_10;
    // 0x80059BC4: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
    skip_10:
    // 0x80059BC8: lw          $v1, 0x0($s5)
    ctx->r3 = S32(MEM_W(ctx->r21, 0X0));
    // 0x80059BCC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80059BD0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80059BD4: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x80059BD8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80059BDC: sh          $s3, -0x4238($at)
    MEM_H(-0X4238, ctx->r1) = ctx->r19;
    // 0x80059BE0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80059BE4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80059BE8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80059BEC: swc1        $f24, -0x5238($at)
    MEM_W(-0X5238, ctx->r1) = ctx->f24.u32l;
    // 0x80059BF0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80059BF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80059BF8: swc1        $f20, -0x4A38($at)
    MEM_W(-0X4A38, ctx->r1) = ctx->f20.u32l;
    // 0x80059BFC: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x80059C00: slti        $at, $t1, 0x200
    ctx->r1 = SIGNED(ctx->r9) < 0X200 ? 1 : 0;
    // 0x80059C04: beq         $at, $zero, L_80059CA0
    if (ctx->r1 == 0) {
        // 0x80059C08: sw          $t1, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r9;
            goto L_80059CA0;
    }
    // 0x80059C08: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
L_80059C0C:
    // 0x80059C0C: lw          $t4, 0xC0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XC0));
L_80059C10:
    // 0x80059C10: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80059C14: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80059C18: bne         $at, $zero, L_80059874
    if (ctx->r1 != 0) {
        // 0x80059C1C: nop
    
            goto L_80059874;
    }
    // 0x80059C1C: nop

L_80059C20:
    // 0x80059C20: lw          $v0, 0x88($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80059C24: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x80059C28: addiu       $s4, $s4, 0x61A8
    ctx->r20 = ADD32(ctx->r20, 0X61A8);
    // 0x80059C2C: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80059C30: beq         $at, $zero, L_80059CA0
    if (ctx->r1 == 0) {
        // 0x80059C34: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80059CA0;
    }
    // 0x80059C34: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80059C38: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80059C3C: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80059C40: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80059C44: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80059C48: addiu       $t8, $t8, -0x4238
    ctx->r24 = ADD32(ctx->r24, -0X4238);
    // 0x80059C4C: addiu       $t6, $t6, -0x4A38
    ctx->r14 = ADD32(ctx->r14, -0X4A38);
    // 0x80059C50: addiu       $t5, $t5, -0x5238
    ctx->r13 = ADD32(ctx->r13, -0X5238);
    // 0x80059C54: sll         $t7, $s3, 1
    ctx->r15 = S32(ctx->r19 << 1);
    // 0x80059C58: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x80059C5C: addu        $s0, $v0, $t5
    ctx->r16 = ADD32(ctx->r2, ctx->r13);
    // 0x80059C60: addu        $s1, $v0, $t6
    ctx->r17 = ADD32(ctx->r2, ctx->r14);
L_80059C64:
    // 0x80059C64: lhu         $t0, 0x0($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X0);
    // 0x80059C68: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x80059C6C: lwc1        $f14, 0x0($s1)
    ctx->f14.u32l = S32(MEM_W(ctx->r17, 0X0));
    // 0x80059C70: sll         $t9, $t0, 3
    ctx->r25 = S32(ctx->r8 << 3);
    // 0x80059C74: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80059C78: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80059C7C: addu        $v0, $s4, $t9
    ctx->r2 = ADD32(ctx->r20, ctx->r25);
    // 0x80059C80: lh          $a2, 0xC($v0)
    ctx->r6 = S32(MEM_H(ctx->r2, 0XC));
    // 0x80059C84: jal         0x8005962C
    // 0x80059C88: lh          $a3, 0xA($v0)
    ctx->r7 = S32(MEM_H(ctx->r2, 0XA));
    scansector(rdram, ctx);
        goto after_9;
    // 0x80059C88: lh          $a3, 0xA($v0)
    ctx->r7 = S32(MEM_H(ctx->r2, 0XA));
    after_9:
    // 0x80059C8C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80059C90: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80059C94: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80059C98: bne         $s3, $s6, L_80059C64
    if (ctx->r19 != ctx->r22) {
        // 0x80059C9C: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_80059C64;
    }
    // 0x80059C9C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_80059CA0:
    // 0x80059CA0: lw          $ra, 0x6C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x80059CA4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80059CA8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80059CAC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80059CB0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80059CB4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80059CB8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80059CBC: lw          $s0, 0x48($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80059CC0: lw          $s1, 0x4C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80059CC4: lw          $s2, 0x50($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80059CC8: lw          $s3, 0x54($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80059CCC: lw          $s4, 0x58($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80059CD0: lw          $s5, 0x5C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x80059CD4: lw          $s6, 0x60($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80059CD8: lw          $s7, 0x64($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X64));
    // 0x80059CDC: lw          $fp, 0x68($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X68));
    // 0x80059CE0: jr          $ra
    // 0x80059CE4: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80059CE4: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void deletespritesect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092768: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009276C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80092770: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80092774: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80092778: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8009277C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80092780: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80092784: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x80092788: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x8009278C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80092790: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80092794: lh          $v0, 0x10($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X10));
    // 0x80092798: addiu       $t1, $zero, 0x291
    ctx->r9 = ADD32(0, 0X291);
    // 0x8009279C: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x800927A0: bne         $t1, $v0, L_800927B0
    if (ctx->r9 != ctx->r2) {
        // 0x800927A4: addiu       $t2, $t2, 0x2330
        ctx->r10 = ADD32(ctx->r10, 0X2330);
            goto L_800927B0;
    }
    // 0x800927A4: addiu       $t2, $t2, 0x2330
    ctx->r10 = ADD32(ctx->r10, 0X2330);
    // 0x800927A8: jr          $ra
    // 0x800927AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800927AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800927B0:
    // 0x800927B0: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x800927B4: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x800927B8: lh          $t5, 0x0($a1)
    ctx->r13 = S32(MEM_H(ctx->r5, 0X0));
    // 0x800927BC: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x800927C0: addiu       $t3, $t3, 0x3060
    ctx->r11 = ADD32(ctx->r11, 0X3060);
    // 0x800927C4: bne         $a0, $t5, L_800927E0
    if (ctx->r4 != ctx->r13) {
        // 0x800927C8: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_800927E0;
    }
    // 0x800927C8: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800927CC: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800927D0: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x800927D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800927D8: lh          $t7, 0x4FA0($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X4FA0));
    // 0x800927DC: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
L_800927E0:
    // 0x800927E0: addu        $a3, $t3, $v0
    ctx->r7 = ADD32(ctx->r11, ctx->r2);
    // 0x800927E4: lh          $t0, 0x0($a3)
    ctx->r8 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800927E8: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x800927EC: addiu       $t8, $t8, 0x4FA0
    ctx->r24 = ADD32(ctx->r24, 0X4FA0);
    // 0x800927F0: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x800927F4: bltz        $t0, L_8009280C
    if (SIGNED(ctx->r8) < 0) {
        // 0x800927F8: lh          $a2, 0x0($a1)
        ctx->r6 = S32(MEM_H(ctx->r5, 0X0));
            goto L_8009280C;
    }
    // 0x800927F8: lh          $a2, 0x0($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X0));
    // 0x800927FC: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80092800: addu        $t4, $t9, $t8
    ctx->r12 = ADD32(ctx->r25, ctx->r24);
    // 0x80092804: sh          $a2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r6;
    // 0x80092808: lh          $a2, 0x0($a1)
    ctx->r6 = S32(MEM_H(ctx->r5, 0X0));
L_8009280C:
    // 0x8009280C: bltz        $a2, L_80092820
    if (SIGNED(ctx->r6) < 0) {
        // 0x80092810: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_80092820;
    }
    // 0x80092810: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80092814: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x80092818: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8009281C: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
L_80092820:
    // 0x80092820: lh          $a2, 0x522($t2)
    ctx->r6 = S32(MEM_H(ctx->r10, 0X522));
    // 0x80092824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80092828: bltz        $a2, L_80092838
    if (SIGNED(ctx->r6) < 0) {
        // 0x8009282C: sll         $t7, $a2, 1
        ctx->r15 = S32(ctx->r6 << 1);
            goto L_80092838;
    }
    // 0x8009282C: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x80092830: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x80092834: sh          $a0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r4;
L_80092838:
    // 0x80092838: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // 0x8009283C: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // 0x80092840: sh          $a0, 0x522($t2)
    MEM_H(0X522, ctx->r10) = ctx->r4;
    // 0x80092844: sh          $t1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r9;
    // 0x80092848: jr          $ra
    // 0x8009284C: nop

    return;
    // 0x8009284C: nop

;}
RECOMP_FUNC void display_tileviewer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800646A8: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x800646AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800646B0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x800646B4: addiu       $s0, $s0, 0x4418
    ctx->r16 = ADD32(ctx->r16, 0X4418);
    // 0x800646B8: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800646BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800646C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800646C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800646C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800646CC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800646D0: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x800646D4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800646D8: addiu       $s1, $s1, 0x4410
    ctx->r17 = ADD32(ctx->r17, 0X4410);
    // 0x800646DC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800646E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800646E4: lw          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800646E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800646EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800646F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800646F4: jal         0x800BD8C8
    // 0x800646F8: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    guTranslate(rdram, ctx);
        goto after_0;
    // 0x800646F8: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    after_0:
    // 0x800646FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80064700: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80064704: lw          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80064708: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006470C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80064710: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80064714: jal         0x800BD974
    // 0x80064718: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    guScale(rdram, ctx);
        goto after_1;
    // 0x80064718: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    after_1:
    // 0x8006471C: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80064720: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x80064724: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x80064728: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8006472C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80064730: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80064734: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80064738: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006473C: ori         $at, $at, 0x300
    ctx->r1 = ctx->r1 | 0X300;
    // 0x80064740: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x80064744: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80064748: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006474C: lui         $t3, 0x100
    ctx->r11 = S32(0X100 << 16);
    // 0x80064750: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x80064754: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80064758: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8006475C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80064760: lw          $t4, 0x0($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80064764: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80064768: ori         $at, $at, 0x380
    ctx->r1 = ctx->r1 | 0X380;
    // 0x8006476C: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80064770: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80064774: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80064778: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x8006477C: addiu       $t8, $t8, 0x1908
    ctx->r24 = ADD32(ctx->r24, 0X1908);
    // 0x80064780: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80064784: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80064788: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8006478C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80064790: jal         0x8005C28C
    // 0x80064794: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    clearscreen(rdram, ctx);
        goto after_2;
    // 0x80064794: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    after_2:
    // 0x80064798: lw          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006479C: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x800647A0: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800647A4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800647A8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800647AC: ori         $t1, $t1, 0x3C0
    ctx->r9 = ctx->r9 | 0X3C0;
    // 0x800647B0: lui         $t0, 0xED00
    ctx->r8 = S32(0XED00 << 16);
    // 0x800647B4: addiu       $s1, $s1, -0x5B54
    ctx->r17 = ADD32(ctx->r17, -0X5B54);
    // 0x800647B8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800647BC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800647C0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800647C4: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x800647C8: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, 0X4AE0);
    // 0x800647CC: jal         0x800BD9E4
    // 0x800647D0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x800647D0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x800647D4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800647D8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800647DC: jal         0x80063F68
    // 0x800647E0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    gametext(rdram, ctx);
        goto after_4;
    // 0x800647E0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x800647E4: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x800647E8: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // 0x800647EC: jal         0x8005C9BC
    // 0x800647F0: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    rotatesprite_simplest(rdram, ctx);
        goto after_5;
    // 0x800647F0: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    after_5:
    // 0x800647F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800647F8: addiu       $v0, $v0, -0x6C48
    ctx->r2 = ADD32(ctx->r2, -0X6C48);
    // 0x800647FC: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x80064800: andi        $t3, $t2, 0x200
    ctx->r11 = ctx->r10 & 0X200;
    // 0x80064804: beql        $t3, $zero, L_8006481C
    if (ctx->r11 == 0) {
        // 0x80064808: lhu         $t6, 0x0($v0)
        ctx->r14 = MEM_HU(ctx->r2, 0X0);
            goto L_8006481C;
    }
    goto skip_0;
    // 0x80064808: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    skip_0:
    // 0x8006480C: lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X0);
    // 0x80064810: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80064814: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
    // 0x80064818: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
L_8006481C:
    // 0x8006481C: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80064820: beql        $t7, $zero, L_80064838
    if (ctx->r15 == 0) {
        // 0x80064824: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_80064838;
    }
    goto skip_1;
    // 0x80064824: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_1:
    // 0x80064828: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x8006482C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80064830: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x80064834: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_80064838:
    // 0x80064838: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8006483C: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80064840: jr          $ra
    // 0x80064844: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x80064844: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void alLoadParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC944: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CC948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC94C: beq         $a1, $at, L_800CCAA4
    if (ctx->r5 == ctx->r1) {
        // 0x800CC950: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CCAA4;
    }
    // 0x800CC950: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CC954: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800CC958: bnel        $a1, $at, L_800CCB08
    if (ctx->r5 != ctx->r1) {
        // 0x800CC95C: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CCB08;
    }
    goto skip_0;
    // 0x800CC95C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800CC960: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x800CC964: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800CC968: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800CC96C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CC970: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800CC974: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x800CC978: beql        $v0, $zero, L_800CC998
    if (ctx->r2 == 0) {
        // 0x800CC97C: lw          $v0, 0x28($a3)
        ctx->r2 = S32(MEM_W(ctx->r7, 0X28));
            goto L_800CC998;
    }
    goto skip_1;
    // 0x800CC97C: lw          $v0, 0x28($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X28));
    skip_1:
    // 0x800CC980: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CC984: beq         $v0, $a0, L_800CCA58
    if (ctx->r2 == ctx->r4) {
        // 0x800CC988: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_800CCA58;
    }
    // 0x800CC988: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CC98C: b           L_800CCB08
    // 0x800CC990: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800CCB08;
    // 0x800CC990: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CC994: lw          $v0, 0x28($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X28));
L_800CC998:
    // 0x800CC998: addiu       $t7, $t7, -0x3014
    ctx->r15 = ADD32(ctx->r15, -0X3014);
    // 0x800CC99C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800CC9A0: lw          $t8, 0x4($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800CC9A4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CC9A8: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x800CC9AC: mflo        $t9
    ctx->r25 = lo;
    // 0x800CC9B0: bne         $a1, $zero, L_800CC9BC
    if (ctx->r5 != 0) {
        // 0x800CC9B4: nop
    
            goto L_800CC9BC;
    }
    // 0x800CC9B4: nop

    // 0x800CC9B8: break       7
    do_break(2148321720);
L_800CC9BC:
    // 0x800CC9BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CC9C0: bne         $a1, $at, L_800CC9D4
    if (ctx->r5 != ctx->r1) {
        // 0x800CC9C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CC9D4;
    }
    // 0x800CC9C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CC9C8: bne         $t8, $at, L_800CC9D4
    if (ctx->r24 != ctx->r1) {
        // 0x800CC9CC: nop
    
            goto L_800CC9D4;
    }
    // 0x800CC9CC: nop

    // 0x800CC9D0: break       6
    do_break(2148321744);
L_800CC9D4:
    // 0x800CC9D4: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CC9D8: mflo        $t0
    ctx->r8 = lo;
    // 0x800CC9DC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CC9E0: lw          $v0, 0x28($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X28));
    // 0x800CC9E4: lw          $a0, 0x10($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X10));
    // 0x800CC9E8: lw          $t1, 0x0($a0)
    ctx->r9 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800CC9EC: lw          $t3, 0x4($a0)
    ctx->r11 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800CC9F0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800CC9F4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CC9F8: mflo        $t4
    ctx->r12 = lo;
    // 0x800CC9FC: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x800CCA00: lw          $v1, 0xC($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCA04: beql        $v1, $zero, L_800CCA4C
    if (ctx->r3 == 0) {
        // 0x800CCA08: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800CCA4C;
    }
    goto skip_2;
    // 0x800CCA08: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x800CCA0C: lw          $t5, 0x0($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800CCA10: lw          $a1, 0x18($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X18));
    // 0x800CCA14: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800CCA18: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x800CCA1C: lw          $t6, 0xC($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCA20: lw          $t7, 0x4($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X4));
    // 0x800CCA24: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x800CCA28: lw          $t8, 0xC($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCA2C: lw          $t9, 0x8($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X8));
    // 0x800CCA30: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x800CCA34: lw          $a0, 0xC($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCA38: jal         0x800CFF10
    // 0x800CCA3C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy(rdram, ctx);
        goto after_0;
    // 0x800CCA3C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800CCA40: b           L_800CCB08
    // 0x800CCA44: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800CCB08;
    // 0x800CCA44: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CCA48: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800CCA4C:
    // 0x800CCA4C: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800CCA50: b           L_800CCB04
    // 0x800CCA54: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800CCB04;
    // 0x800CCA54: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800CCA58:
    // 0x800CCA58: lw          $v0, 0x28($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X28));
    // 0x800CCA5C: addiu       $t0, $t0, -0x34EC
    ctx->r8 = ADD32(ctx->r8, -0X34EC);
    // 0x800CCA60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x800CCA64: lw          $v1, 0xC($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCA68: beql        $v1, $zero, L_800CCA98
    if (ctx->r3 == 0) {
        // 0x800CCA6C: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800CCA98;
    }
    goto skip_3;
    // 0x800CCA6C: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x800CCA70: lw          $t1, 0x0($v1)
    ctx->r9 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800CCA74: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x800CCA78: lw          $t2, 0xC($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCA7C: lw          $t3, 0x4($t2)
    ctx->r11 = S32(MEM_W(ctx->r10, 0X4));
    // 0x800CCA80: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x800CCA84: lw          $t4, 0xC($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCA88: lw          $t5, 0x8($t4)
    ctx->r13 = S32(MEM_W(ctx->r12, 0X8));
    // 0x800CCA8C: b           L_800CCB04
    // 0x800CCA90: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_800CCB04;
    // 0x800CCA90: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x800CCA94: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800CCA98:
    // 0x800CCA98: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800CCA9C: b           L_800CCB04
    // 0x800CCAA0: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800CCB04;
    // 0x800CCAA0: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800CCAA4:
    // 0x800CCAA4: lw          $v0, 0x28($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X28));
    // 0x800CCAA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CCAAC: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800CCAB0: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x800CCAB4: beq         $v0, $zero, L_800CCB04
    if (ctx->r2 == 0) {
        // 0x800CCAB8: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_800CCB04;
    }
    // 0x800CCAB8: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800CCABC: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800CCAC0: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x800CCAC4: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x800CCAC8: bne         $v1, $zero, L_800CCAE8
    if (ctx->r3 != 0) {
        // 0x800CCACC: nop
    
            goto L_800CCAE8;
    }
    // 0x800CCACC: nop

    // 0x800CCAD0: lw          $v1, 0xC($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCAD4: beql        $v1, $zero, L_800CCB08
    if (ctx->r3 == 0) {
        // 0x800CCAD8: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CCB08;
    }
    goto skip_4;
    // 0x800CCAD8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_4:
    // 0x800CCADC: lw          $t7, 0x8($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X8));
    // 0x800CCAE0: b           L_800CCB04
    // 0x800CCAE4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_800CCB04;
    // 0x800CCAE4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_800CCAE8:
    // 0x800CCAE8: bnel        $a0, $v1, L_800CCB08
    if (ctx->r4 != ctx->r3) {
        // 0x800CCAEC: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CCB08;
    }
    goto skip_5;
    // 0x800CCAEC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_5:
    // 0x800CCAF0: lw          $v1, 0xC($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800CCAF4: beql        $v1, $zero, L_800CCB08
    if (ctx->r3 == 0) {
        // 0x800CCAF8: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CCB08;
    }
    goto skip_6;
    // 0x800CCAF8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_6:
    // 0x800CCAFC: lw          $t8, 0x8($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X8));
    // 0x800CCB00: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_800CCB04:
    // 0x800CCB04: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CCB08:
    // 0x800CCB08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CCB0C: jr          $ra
    // 0x800CCB10: nop

    return;
    // 0x800CCB10: nop

;}
RECOMP_FUNC void operateforcefields(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AF628: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x800AF62C: lh          $v0, -0x55AC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X55AC));
    // 0x800AF630: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x800AF634: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800AF638: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AF63C: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800AF640: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AF644: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800AF648: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    // 0x800AF64C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800AF650: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800AF654: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800AF658: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800AF65C: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800AF660: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800AF664: bltz        $v0, L_800AF758
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AF668: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800AF758;
    }
    // 0x800AF668: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AF66C: lui         $s3, 0x8024
    ctx->r19 = S32(0X8024 << 16);
    // 0x800AF670: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x800AF674: lui         $t0, 0x802B
    ctx->r8 = S32(0X802B << 16);
    // 0x800AF678: addiu       $t0, $t0, -0x6940
    ctx->r8 = ADD32(ctx->r8, -0X6940);
    // 0x800AF67C: addiu       $t1, $t1, 0x61A8
    ctx->r9 = ADD32(ctx->r9, 0X61A8);
    // 0x800AF680: addiu       $s3, $s3, 0x6BA8
    ctx->r19 = ADD32(ctx->r19, 0X6BA8);
    // 0x800AF684: addiu       $s6, $zero, 0x55
    ctx->r22 = ADD32(0, 0X55);
    // 0x800AF688: addiu       $s5, $zero, 0x1E
    ctx->r21 = ADD32(0, 0X1E);
    // 0x800AF68C: addiu       $s4, $zero, 0x2C
    ctx->r20 = ADD32(0, 0X2C);
    // 0x800AF690: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AF694: addiu       $s1, $zero, 0x299
    ctx->r17 = ADD32(0, 0X299);
    // 0x800AF698: addiu       $s0, $zero, 0x298
    ctx->r16 = ADD32(0, 0X298);
    // 0x800AF69C: addiu       $t5, $zero, 0x297
    ctx->r13 = ADD32(0, 0X297);
    // 0x800AF6A0: addiu       $t4, $zero, 0xE6
    ctx->r12 = ADD32(0, 0XE6);
    // 0x800AF6A4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800AF6A8: addiu       $t2, $zero, 0x24
    ctx->r10 = ADD32(0, 0X24);
    // 0x800AF6AC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
L_800AF6B0:
    // 0x800AF6B0: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    // 0x800AF6B4: lh          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_H(ctx->r4, 0X0));
    // 0x800AF6B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AF6BC: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AF6C0: mflo        $t6
    ctx->r14 = lo;
    // 0x800AF6C4: addu        $a2, $t1, $t6
    ctx->r6 = ADD32(ctx->r9, ctx->r14);
    // 0x800AF6C8: lh          $t7, 0x14($a2)
    ctx->r15 = S32(MEM_H(ctx->r6, 0X14));
    // 0x800AF6CC: beql        $a1, $t7, L_800AF6E0
    if (ctx->r5 == ctx->r15) {
        // 0x800AF6D0: lh          $v1, 0x12($a2)
        ctx->r3 = S32(MEM_H(ctx->r6, 0X12));
            goto L_800AF6E0;
    }
    goto skip_0;
    // 0x800AF6D0: lh          $v1, 0x12($a2)
    ctx->r3 = S32(MEM_H(ctx->r6, 0X12));
    skip_0:
    // 0x800AF6D4: bnel        $a1, $t3, L_800AF74C
    if (ctx->r5 != ctx->r11) {
        // 0x800AF6D8: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800AF74C;
    }
    goto skip_1;
    // 0x800AF6D8: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    skip_1:
    // 0x800AF6DC: lh          $v1, 0x12($a2)
    ctx->r3 = S32(MEM_H(ctx->r6, 0X12));
L_800AF6E0:
    // 0x800AF6E0: beql        $v1, $t4, L_800AF704
    if (ctx->r3 == ctx->r12) {
        // 0x800AF6E4: lh          $t8, 0xE($a2)
        ctx->r24 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800AF704;
    }
    goto skip_2;
    // 0x800AF6E4: lh          $t8, 0xE($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0XE));
    skip_2:
    // 0x800AF6E8: beql        $v1, $t5, L_800AF704
    if (ctx->r3 == ctx->r13) {
        // 0x800AF6EC: lh          $t8, 0xE($a2)
        ctx->r24 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800AF704;
    }
    goto skip_3;
    // 0x800AF6EC: lh          $t8, 0xE($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0XE));
    skip_3:
    // 0x800AF6F0: beql        $v1, $s0, L_800AF704
    if (ctx->r3 == ctx->r16) {
        // 0x800AF6F4: lh          $t8, 0xE($a2)
        ctx->r24 = S32(MEM_H(ctx->r6, 0XE));
            goto L_800AF704;
    }
    goto skip_4;
    // 0x800AF6F4: lh          $t8, 0xE($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0XE));
    skip_4:
    // 0x800AF6F8: bnel        $v1, $s1, L_800AF74C
    if (ctx->r3 != ctx->r17) {
        // 0x800AF6FC: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800AF74C;
    }
    goto skip_5;
    // 0x800AF6FC: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    skip_5:
    // 0x800AF700: lh          $t8, 0xE($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0XE));
L_800AF704:
    // 0x800AF704: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800AF708: beql        $t8, $zero, L_800AF748
    if (ctx->r24 == 0) {
        // 0x800AF70C: sh          $s6, 0xE($a2)
        MEM_H(0XE, ctx->r6) = ctx->r22;
            goto L_800AF748;
    }
    goto skip_6;
    // 0x800AF70C: sh          $s6, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r22;
    skip_6:
    // 0x800AF710: bltz        $a3, L_800AF748
    if (SIGNED(ctx->r7) < 0) {
        // 0x800AF714: sh          $zero, 0xE($a2)
        MEM_H(0XE, ctx->r6) = 0;
            goto L_800AF748;
    }
    // 0x800AF714: sh          $zero, 0xE($a2)
    MEM_H(0XE, ctx->r6) = 0;
    // 0x800AF718: multu       $a3, $s4
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AF71C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AF720: addu        $v1, $s3, $t9
    ctx->r3 = ADD32(ctx->r19, ctx->r25);
    // 0x800AF724: lh          $t6, 0xE($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0XE));
    // 0x800AF728: bnel        $s2, $t6, L_800AF74C
    if (ctx->r18 != ctx->r14) {
        // 0x800AF72C: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800AF74C;
    }
    goto skip_7;
    // 0x800AF72C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    skip_7:
    // 0x800AF730: lh          $t7, 0x1E($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800AF734: bnel        $s5, $t7, L_800AF74C
    if (ctx->r21 != ctx->r15) {
        // 0x800AF738: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800AF74C;
    }
    goto skip_8;
    // 0x800AF738: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    skip_8:
    // 0x800AF73C: b           L_800AF748
    // 0x800AF740: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
        goto L_800AF748;
    // 0x800AF740: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
    // 0x800AF744: sh          $s6, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r22;
L_800AF748:
    // 0x800AF748: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
L_800AF74C:
    // 0x800AF74C: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800AF750: bgezl       $v0, L_800AF6B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AF754: sll         $t9, $v0, 3
        ctx->r25 = S32(ctx->r2 << 3);
            goto L_800AF6B0;
    }
    goto skip_9;
    // 0x800AF754: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    skip_9:
L_800AF758:
    // 0x800AF758: lw          $s0, 0x4($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X4));
    // 0x800AF75C: lw          $s1, 0x8($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X8));
    // 0x800AF760: lw          $s2, 0xC($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XC));
    // 0x800AF764: lw          $s3, 0x10($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X10));
    // 0x800AF768: lw          $s4, 0x14($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800AF76C: lw          $s5, 0x18($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800AF770: lw          $s6, 0x1C($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800AF774: jr          $ra
    // 0x800AF778: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800AF778: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void creategfxtask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BBB4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8004BBB8: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x8004BBBC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004BBC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004BBC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004BBC8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8004BBCC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8004BBD0: lui         $t7, 0xE900
    ctx->r15 = S32(0XE900 << 16);
    // 0x8004BBD4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8004BBD8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004BBDC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004BBE0: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8004BBE4: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x8004BBE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8004BBEC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8004BBF0: addiu       $t1, $t1, 0x36F0
    ctx->r9 = ADD32(ctx->r9, 0X36F0);
    // 0x8004BBF4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004BBF8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8004BBFC: lw          $t2, 0x0($t1)
    ctx->r10 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8004BC00: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8004BC04: addiu       $a3, $a3, 0x4410
    ctx->r7 = ADD32(ctx->r7, 0X4410);
    // 0x8004BC08: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8004BC0C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8004BC10: lw          $t5, 0x0($a3)
    ctx->r13 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8004BC14: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004BC18: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8004BC1C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8004BC20: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8004BC24: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004BC28: addiu       $t4, $t4, 0x4358
    ctx->r12 = ADD32(ctx->r12, 0X4358);
    // 0x8004BC2C: ori         $at, $at, 0x8600
    ctx->r1 = ctx->r1 | 0X8600;
    // 0x8004BC30: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8004BC34: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x8004BC38: sw          $t6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r14;
    // 0x8004BC3C: lw          $t8, 0x0($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X0));
    // 0x8004BC40: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004BC44: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x8004BC48: ori         $at, $at, 0x7A00
    ctx->r1 = ctx->r1 | 0X7A00;
    // 0x8004BC4C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8004BC50: addu        $t2, $t9, $at
    ctx->r10 = ADD32(ctx->r25, ctx->r1);
    // 0x8004BC54: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8004BC58: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004BC5C: addiu       $t0, $t0, 0x13C0
    ctx->r8 = ADD32(ctx->r8, 0X13C0);
    // 0x8004BC60: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8004BC64: addiu       $t6, $t6, 0x1490
    ctx->r14 = ADD32(ctx->r14, 0X1490);
    // 0x8004BC68: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8004BC6C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8004BC70: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8004BC74: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004BC78: subu        $t7, $t6, $t0
    ctx->r15 = SUB32(ctx->r14, ctx->r8);
    // 0x8004BC7C: addiu       $t8, $t8, 0x1490
    ctx->r24 = ADD32(ctx->r24, 0X1490);
    // 0x8004BC80: addiu       $t9, $t9, -0x5E40
    ctx->r25 = ADD32(ctx->r25, -0X5E40);
    // 0x8004BC84: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8004BC88: sw          $t8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r24;
    // 0x8004BC8C: sw          $t9, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r25;
    // 0x8004BC90: sw          $t4, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r12;
    // 0x8004BC94: sw          $t7, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r15;
    // 0x8004BC98: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8004BC9C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8004BCA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004BCA4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004BCA8: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x8004BCAC: addiu       $t3, $t3, 0x4440
    ctx->r11 = ADD32(ctx->r11, 0X4440);
    // 0x8004BCB0: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x8004BCB4: addiu       $t5, $t5, 0x4840
    ctx->r13 = ADD32(ctx->r13, 0X4840);
    // 0x8004BCB8: addiu       $t6, $zero, 0x900
    ctx->r14 = ADD32(0, 0X900);
    // 0x8004BCBC: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
    // 0x8004BCC0: addiu       $t8, $t8, 0x3668
    ctx->r24 = ADD32(ctx->r24, 0X3668);
    // 0x8004BCC4: addiu       $t9, $t9, 0x36D0
    ctx->r25 = ADD32(ctx->r25, 0X36D0);
    // 0x8004BCC8: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    // 0x8004BCCC: sw          $t0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r8;
    // 0x8004BCD0: sw          $t2, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r10;
    // 0x8004BCD4: sw          $t3, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r11;
    // 0x8004BCD8: sw          $t4, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r12;
    // 0x8004BCDC: sw          $zero, 0x38($a1)
    MEM_W(0X38, ctx->r5) = 0;
    // 0x8004BCE0: sw          $zero, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = 0;
    // 0x8004BCE4: sw          $t5, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r13;
    // 0x8004BCE8: sw          $t6, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->r14;
    // 0x8004BCEC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8004BCF0: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    // 0x8004BCF4: sw          $t8, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->r24;
    // 0x8004BCF8: sw          $t9, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->r25;
    // 0x8004BCFC: lw          $t2, 0x0($t1)
    ctx->r10 = S32(MEM_W(ctx->r9, 0X0));
    // 0x8004BD00: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8004BD04: addiu       $t4, $t4, 0x400
    ctx->r12 = ADD32(ctx->r12, 0X400);
    // 0x8004BD08: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8004BD0C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8004BD10: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004BD14: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8004BD18: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004BD1C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8004BD20: sll         $t3, $t3, 11
    ctx->r11 = S32(ctx->r11 << 11);
    // 0x8004BD24: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004BD28: sw          $t5, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r13;
    // 0x8004BD2C: jal         0x800BB2F0
    // 0x8004BD30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x8004BD30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004BD34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8004BD38: jal         0x8004C654
    // 0x8004BD3C: addiu       $a0, $a0, -0xCB8
    ctx->r4 = ADD32(ctx->r4, -0XCB8);
    osScGetCmdQ(rdram, ctx);
        goto after_1;
    // 0x8004BD3C: addiu       $a0, $a0, -0xCB8
    ctx->r4 = ADD32(ctx->r4, -0XCB8);
    after_1:
    // 0x8004BD40: lw          $a1, 0x1C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004BD44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004BD48: jal         0x800BB610
    // 0x8004BD4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8004BD4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8004BD50: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004BD54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004BD58: jr          $ra
    // 0x8004BD5C: nop

    return;
    // 0x8004BD5C: nop

;}
RECOMP_FUNC void alCSPSetSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C23A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C23A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C23A8: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x800C23AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C23B0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C23B4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C23B8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C23BC: jal         0x800C9C6C
    // 0x800C23C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C23C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C23C4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C23C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C23CC: jr          $ra
    // 0x800C23D0: nop

    return;
    // 0x800C23D0: nop

;}
RECOMP_FUNC void wallswitchcheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B25C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8009B260: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8009B264: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009B268: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8009B26C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8009B270: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8009B274: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8009B278: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x8009B27C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8009B280: lh          $v0, 0x6BB6($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X6BB6));
    // 0x8009B284: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009B288: slti        $at, $v0, 0x2CA
    ctx->r1 = SIGNED(ctx->r2) < 0X2CA ? 1 : 0;
    // 0x8009B28C: bne         $at, $zero, L_8009B2E0
    if (ctx->r1 != 0) {
        // 0x8009B290: slti        $at, $v0, 0x362
        ctx->r1 = SIGNED(ctx->r2) < 0X362 ? 1 : 0;
            goto L_8009B2E0;
    }
    // 0x8009B290: slti        $at, $v0, 0x362
    ctx->r1 = SIGNED(ctx->r2) < 0X362 ? 1 : 0;
    // 0x8009B294: bne         $at, $zero, L_8009B2C0
    if (ctx->r1 != 0) {
        // 0x8009B298: addiu       $t0, $v0, -0x35C
        ctx->r8 = ADD32(ctx->r2, -0X35C);
            goto L_8009B2C0;
    }
    // 0x8009B298: addiu       $t0, $v0, -0x35C
    ctx->r8 = ADD32(ctx->r2, -0X35C);
    // 0x8009B29C: addiu       $t9, $v0, -0x457
    ctx->r25 = ADD32(ctx->r2, -0X457);
    // 0x8009B2A0: sltiu       $at, $t9, 0x2E
    ctx->r1 = ctx->r25 < 0X2E ? 1 : 0;
    // 0x8009B2A4: beq         $at, $zero, L_8009B344
    if (ctx->r1 == 0) {
        // 0x8009B2A8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8009B344;
    }
    // 0x8009B2A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8009B2AC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8009B2B0: addu        $at, $at, $t9
    gpr jr_addend_8009B2B8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8009B2B4: lw          $t9, 0x698C($at)
    ctx->r25 = ADD32(ctx->r1, 0X698C);
    // 0x8009B2B8: jr          $t9
    // 0x8009B2BC: nop

    switch (jr_addend_8009B2B8 >> 2) {
        case 0: goto L_8009B33C; break;
        case 1: goto L_8009B33C; break;
        case 2: goto L_8009B344; break;
        case 3: goto L_8009B344; break;
        case 4: goto L_8009B344; break;
        case 5: goto L_8009B344; break;
        case 6: goto L_8009B344; break;
        case 7: goto L_8009B344; break;
        case 8: goto L_8009B344; break;
        case 9: goto L_8009B344; break;
        case 10: goto L_8009B344; break;
        case 11: goto L_8009B33C; break;
        case 12: goto L_8009B33C; break;
        case 13: goto L_8009B344; break;
        case 14: goto L_8009B344; break;
        case 15: goto L_8009B344; break;
        case 16: goto L_8009B344; break;
        case 17: goto L_8009B344; break;
        case 18: goto L_8009B344; break;
        case 19: goto L_8009B344; break;
        case 20: goto L_8009B344; break;
        case 21: goto L_8009B344; break;
        case 22: goto L_8009B344; break;
        case 23: goto L_8009B344; break;
        case 24: goto L_8009B344; break;
        case 25: goto L_8009B344; break;
        case 26: goto L_8009B344; break;
        case 27: goto L_8009B344; break;
        case 28: goto L_8009B344; break;
        case 29: goto L_8009B344; break;
        case 30: goto L_8009B344; break;
        case 31: goto L_8009B33C; break;
        case 32: goto L_8009B33C; break;
        case 33: goto L_8009B344; break;
        case 34: goto L_8009B344; break;
        case 35: goto L_8009B344; break;
        case 36: goto L_8009B344; break;
        case 37: goto L_8009B344; break;
        case 38: goto L_8009B344; break;
        case 39: goto L_8009B344; break;
        case 40: goto L_8009B344; break;
        case 41: goto L_8009B344; break;
        case 42: goto L_8009B344; break;
        case 43: goto L_8009B344; break;
        case 44: goto L_8009B33C; break;
        case 45: goto L_8009B33C; break;
        default: switch_error(__func__, 0x8009B2B8, 0x8010698C);
    }
    // 0x8009B2BC: nop

L_8009B2C0:
    // 0x8009B2C0: sltiu       $at, $t0, 0x6
    ctx->r1 = ctx->r8 < 0X6 ? 1 : 0;
    // 0x8009B2C4: beq         $at, $zero, L_8009B344
    if (ctx->r1 == 0) {
        // 0x8009B2C8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8009B344;
    }
    // 0x8009B2C8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8009B2CC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8009B2D0: addu        $at, $at, $t0
    gpr jr_addend_8009B2D8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8009B2D4: lw          $t0, 0x6A44($at)
    ctx->r8 = ADD32(ctx->r1, 0X6A44);
    // 0x8009B2D8: jr          $t0
    // 0x8009B2DC: nop

    switch (jr_addend_8009B2D8 >> 2) {
        case 0: goto L_8009B33C; break;
        case 1: goto L_8009B33C; break;
        case 2: goto L_8009B33C; break;
        case 3: goto L_8009B33C; break;
        case 4: goto L_8009B33C; break;
        case 5: goto L_8009B33C; break;
        default: switch_error(__func__, 0x8009B2D8, 0x80106A44);
    }
    // 0x8009B2DC: nop

L_8009B2E0:
    // 0x8009B2E0: slti        $at, $v0, 0x2C9
    ctx->r1 = SIGNED(ctx->r2) < 0X2C9 ? 1 : 0;
    // 0x8009B2E4: bne         $at, $zero, L_8009B2FC
    if (ctx->r1 != 0) {
        // 0x8009B2E8: addiu       $at, $zero, 0x2C9
        ctx->r1 = ADD32(0, 0X2C9);
            goto L_8009B2FC;
    }
    // 0x8009B2E8: addiu       $at, $zero, 0x2C9
    ctx->r1 = ADD32(0, 0X2C9);
    // 0x8009B2EC: beq         $v0, $at, L_8009B33C
    if (ctx->r2 == ctx->r1) {
        // 0x8009B2F0: nop
    
            goto L_8009B33C;
    }
    // 0x8009B2F0: nop

    // 0x8009B2F4: b           L_8009B348
    // 0x8009B2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009B348;
    // 0x8009B2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009B2FC:
    // 0x8009B2FC: slti        $at, $v0, 0xAB
    ctx->r1 = SIGNED(ctx->r2) < 0XAB ? 1 : 0;
    // 0x8009B300: bne         $at, $zero, L_8009B31C
    if (ctx->r1 != 0) {
        // 0x8009B304: addiu       $t1, $v0, -0x82
        ctx->r9 = ADD32(ctx->r2, -0X82);
            goto L_8009B31C;
    }
    // 0x8009B304: addiu       $t1, $v0, -0x82
    ctx->r9 = ADD32(ctx->r2, -0X82);
    // 0x8009B308: addiu       $at, $zero, 0x2C8
    ctx->r1 = ADD32(0, 0X2C8);
    // 0x8009B30C: beq         $v0, $at, L_8009B33C
    if (ctx->r2 == ctx->r1) {
        // 0x8009B310: nop
    
            goto L_8009B33C;
    }
    // 0x8009B310: nop

    // 0x8009B314: b           L_8009B348
    // 0x8009B318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009B348;
    // 0x8009B318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009B31C:
    // 0x8009B31C: sltiu       $at, $t1, 0x29
    ctx->r1 = ctx->r9 < 0X29 ? 1 : 0;
    // 0x8009B320: beq         $at, $zero, L_8009B344
    if (ctx->r1 == 0) {
        // 0x8009B324: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8009B344;
    }
    // 0x8009B324: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8009B328: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8009B32C: addu        $at, $at, $t1
    gpr jr_addend_8009B334 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009B330: lw          $t1, 0x6A5C($at)
    ctx->r9 = ADD32(ctx->r1, 0X6A5C);
    // 0x8009B334: jr          $t1
    // 0x8009B338: nop

    switch (jr_addend_8009B334 >> 2) {
        case 0: goto L_8009B33C; break;
        case 1: goto L_8009B344; break;
        case 2: goto L_8009B33C; break;
        case 3: goto L_8009B33C; break;
        case 4: goto L_8009B33C; break;
        case 5: goto L_8009B33C; break;
        case 6: goto L_8009B33C; break;
        case 7: goto L_8009B33C; break;
        case 8: goto L_8009B33C; break;
        case 9: goto L_8009B33C; break;
        case 10: goto L_8009B33C; break;
        case 11: goto L_8009B33C; break;
        case 12: goto L_8009B344; break;
        case 13: goto L_8009B344; break;
        case 14: goto L_8009B344; break;
        case 15: goto L_8009B344; break;
        case 16: goto L_8009B33C; break;
        case 17: goto L_8009B33C; break;
        case 18: goto L_8009B33C; break;
        case 19: goto L_8009B33C; break;
        case 20: goto L_8009B344; break;
        case 21: goto L_8009B344; break;
        case 22: goto L_8009B344; break;
        case 23: goto L_8009B344; break;
        case 24: goto L_8009B344; break;
        case 25: goto L_8009B344; break;
        case 26: goto L_8009B344; break;
        case 27: goto L_8009B344; break;
        case 28: goto L_8009B344; break;
        case 29: goto L_8009B344; break;
        case 30: goto L_8009B344; break;
        case 31: goto L_8009B344; break;
        case 32: goto L_8009B33C; break;
        case 33: goto L_8009B33C; break;
        case 34: goto L_8009B33C; break;
        case 35: goto L_8009B33C; break;
        case 36: goto L_8009B33C; break;
        case 37: goto L_8009B33C; break;
        case 38: goto L_8009B33C; break;
        case 39: goto L_8009B33C; break;
        case 40: goto L_8009B33C; break;
        default: switch_error(__func__, 0x8009B334, 0x80106A5C);
    }
    // 0x8009B338: nop

L_8009B33C:
    // 0x8009B33C: jr          $ra
    // 0x8009B340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009B340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009B344:
    // 0x8009B344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009B348:
    // 0x8009B348: jr          $ra
    // 0x8009B34C: nop

    return;
    // 0x8009B34C: nop

;}
RECOMP_FUNC void alSynSetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D05B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D05B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800D05B8: jr          $ra
    // 0x800D05BC: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
    return;
    // 0x800D05BC: sh          $a2, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void dointerpolations(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800754D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800754D8: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800754DC: lw          $v1, 0x1390($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X1390));
    // 0x800754E0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800754E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800754E8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800754EC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800754F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800754F4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800754F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800754FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075500: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80075504: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80075508: bltz        $v1, L_800755A0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8007550C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800755A0;
    }
    // 0x8007550C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80075510: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80075514: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x80075518: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x8007551C: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x80075520: addiu       $t8, $t8, 0x65A0
    ctx->r24 = ADD32(ctx->r24, 0X65A0);
    // 0x80075524: addiu       $t7, $t7, -0x7A60
    ctx->r15 = ADD32(ctx->r15, -0X7A60);
    // 0x80075528: addiu       $t6, $t6, 0x75A0
    ctx->r14 = ADD32(ctx->r14, 0X75A0);
    // 0x8007552C: lui         $s4, 0x802A
    ctx->r20 = S32(0X802A << 16);
    // 0x80075530: addiu       $s4, $s4, 0x75A0
    ctx->r20 = ADD32(ctx->r20, 0X75A0);
    // 0x80075534: addu        $s0, $v0, $t6
    ctx->r16 = ADD32(ctx->r2, ctx->r14);
    // 0x80075538: addu        $s1, $v0, $t7
    ctx->r17 = ADD32(ctx->r2, ctx->r15);
    // 0x8007553C: addu        $s2, $v0, $t8
    ctx->r18 = ADD32(ctx->r2, ctx->r24);
L_80075540:
    // 0x80075540: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80075544: lw          $a0, 0x0($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80075548: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8007554C: lw          $t9, 0x0($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80075550: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80075554: sra         $a2, $s5, 31
    ctx->r6 = S32(SIGNED(ctx->r21) >> 31);
    // 0x80075558: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8007555C: lw          $t0, 0x0($v1)
    ctx->r8 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80075560: subu        $s3, $t0, $a0
    ctx->r19 = SUB32(ctx->r8, ctx->r4);
    // 0x80075564: beql        $v0, $s3, L_80075588
    if (ctx->r2 == ctx->r19) {
        // 0x80075568: addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
            goto L_80075588;
    }
    goto skip_0;
    // 0x80075568: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    skip_0:
    // 0x8007556C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075570: jal         0x8008FD60
    // 0x80075574: sra         $a0, $s3, 31
    ctx->r4 = S32(SIGNED(ctx->r19) >> 31);
    mulscale16(rdram, ctx);
        goto after_0;
    // 0x80075574: sra         $a0, $s3, 31
    ctx->r4 = S32(SIGNED(ctx->r19) >> 31);
    after_0:
    // 0x80075578: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007557C: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80075580: lw          $a0, 0x0($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80075584: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_80075588:
    // 0x80075588: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x8007558C: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x80075590: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x80075594: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x80075598: beq         $at, $zero, L_80075540
    if (ctx->r1 == 0) {
        // 0x8007559C: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_80075540;
    }
    // 0x8007559C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_800755A0:
    // 0x800755A0: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800755A4: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800755A8: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800755AC: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800755B0: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800755B4: lw          $s4, 0x24($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800755B8: lw          $s5, 0x28($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800755BC: jr          $ra
    // 0x800755C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800755C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void rintersect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009542C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80095430: lw          $t8, 0x6C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x80095434: lw          $t9, 0x74($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X74));
    // 0x80095438: lw          $t6, 0x68($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X68));
    // 0x8009543C: lw          $t7, 0x70($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X70));
    // 0x80095440: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x80095444: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095448: subu        $t1, $t6, $t7
    ctx->r9 = SUB32(ctx->r14, ctx->r15);
    // 0x8009544C: lw          $t6, 0x60($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80095450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095454: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80095458: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8009545C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80095460: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80095464: mflo        $t5
    ctx->r13 = lo;
    // 0x80095468: nop

    // 0x8009546C: nop

    // 0x80095470: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095474: mflo        $t7
    ctx->r15 = lo;
    // 0x80095478: subu        $t3, $t5, $t7
    ctx->r11 = SUB32(ctx->r13, ctx->r15);
    // 0x8009547C: bltz        $t3, L_80095510
    if (SIGNED(ctx->r11) < 0) {
        // 0x80095480: lw          $t5, 0x68($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X68));
            goto L_80095510;
    }
    // 0x80095480: lw          $t5, 0x68($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X68));
    // 0x80095484: bne         $t3, $zero, L_80095494
    if (ctx->r11 != 0) {
        // 0x80095488: lw          $t8, 0x68($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X68));
            goto L_80095494;
    }
    // 0x80095488: lw          $t8, 0x68($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X68));
    // 0x8009548C: b           L_8009561C
    // 0x80095490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009561C;
    // 0x80095490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80095494:
    // 0x80095494: lw          $t9, 0x50($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80095498: lw          $t4, 0x6C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x8009549C: lw          $t6, 0x54($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800954A0: subu        $v0, $t8, $t9
    ctx->r2 = SUB32(ctx->r24, ctx->r25);
    // 0x800954A4: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800954A8: subu        $v1, $t4, $t6
    ctx->r3 = SUB32(ctx->r12, ctx->r14);
    // 0x800954AC: lw          $t8, 0x5C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800954B0: mflo        $t5
    ctx->r13 = lo;
    // 0x800954B4: nop

    // 0x800954B8: nop

    // 0x800954BC: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800954C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800954C4: subu        $t0, $t5, $t7
    ctx->r8 = SUB32(ctx->r13, ctx->r15);
    // 0x800954C8: bgez        $t0, L_800954D8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800954CC: nop
    
            goto L_800954D8;
    }
    // 0x800954CC: nop

    // 0x800954D0: b           L_8009561C
    // 0x800954D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009561C;
    // 0x800954D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800954D8:
    // 0x800954D8: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800954DC: lw          $t4, 0x60($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800954E0: mflo        $t9
    ctx->r25 = lo;
    // 0x800954E4: nop

    // 0x800954E8: nop

    // 0x800954EC: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800954F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800954F4: subu        $a0, $t9, $t6
    ctx->r4 = SUB32(ctx->r25, ctx->r14);
    // 0x800954F8: bltz        $a0, L_80095508
    if (SIGNED(ctx->r4) < 0) {
        // 0x800954FC: slt         $at, $a0, $t3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80095508;
    }
    // 0x800954FC: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80095500: bnel        $at, $zero, L_80095590
    if (ctx->r1 != 0) {
        // 0x80095504: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_80095590;
    }
    goto skip_0;
    // 0x80095504: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    skip_0:
L_80095508:
    // 0x80095508: b           L_8009561C
    // 0x8009550C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009561C;
    // 0x8009550C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80095510:
    // 0x80095510: lw          $t7, 0x50($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80095514: lw          $t8, 0x6C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x80095518: lw          $t4, 0x54($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8009551C: subu        $v0, $t5, $t7
    ctx->r2 = SUB32(ctx->r13, ctx->r15);
    // 0x80095520: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095524: subu        $v1, $t8, $t4
    ctx->r3 = SUB32(ctx->r24, ctx->r12);
    // 0x80095528: lw          $t5, 0x5C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x8009552C: mflo        $t9
    ctx->r25 = lo;
    // 0x80095530: nop

    // 0x80095534: nop

    // 0x80095538: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009553C: mflo        $t6
    ctx->r14 = lo;
    // 0x80095540: subu        $t0, $t9, $t6
    ctx->r8 = SUB32(ctx->r25, ctx->r14);
    // 0x80095544: blez        $t0, L_80095554
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80095548: nop
    
            goto L_80095554;
    }
    // 0x80095548: nop

    // 0x8009554C: b           L_8009561C
    // 0x80095550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009561C;
    // 0x80095550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80095554:
    // 0x80095554: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095558: lw          $t8, 0x60($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X60));
    // 0x8009555C: mflo        $t7
    ctx->r15 = lo;
    // 0x80095560: nop

    // 0x80095564: nop

    // 0x80095568: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009556C: mflo        $t4
    ctx->r12 = lo;
    // 0x80095570: subu        $a0, $t7, $t4
    ctx->r4 = SUB32(ctx->r15, ctx->r12);
    // 0x80095574: bgtz        $a0, L_80095584
    if (SIGNED(ctx->r4) > 0) {
        // 0x80095578: slt         $at, $t3, $a0
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80095584;
    }
    // 0x80095578: slt         $at, $t3, $a0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8009557C: bnel        $at, $zero, L_80095590
    if (ctx->r1 != 0) {
        // 0x80095580: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_80095590;
    }
    goto skip_1;
    // 0x80095580: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    skip_1:
L_80095584:
    // 0x80095584: b           L_8009561C
    // 0x80095588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009561C;
    // 0x80095588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009558C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_80095590:
    // 0x80095590: sra         $a0, $t0, 31
    ctx->r4 = S32(SIGNED(ctx->r8) >> 31);
    // 0x80095594: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80095598: jal         0x800914A4
    // 0x8009559C: sra         $a2, $t3, 31
    ctx->r6 = S32(SIGNED(ctx->r11) >> 31);
    divscale16(rdram, ctx);
        goto after_0;
    // 0x8009559C: sra         $a2, $t3, 31
    ctx->r6 = S32(SIGNED(ctx->r11) >> 31);
    after_0:
    // 0x800955A0: lw          $a1, 0x5C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800955A4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800955A8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800955AC: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800955B0: jal         0x8008FD60
    // 0x800955B4: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_1;
    // 0x800955B4: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_1:
    // 0x800955B8: lw          $t6, 0x50($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800955BC: lw          $t8, 0x78($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800955C0: addu        $t5, $v0, $t6
    ctx->r13 = ADD32(ctx->r2, ctx->r14);
    // 0x800955C4: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800955C8: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800955CC: lw          $a1, 0x60($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800955D0: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x800955D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800955D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800955DC: jal         0x8008FD60
    // 0x800955E0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_2;
    // 0x800955E0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_2:
    // 0x800955E4: lw          $t9, 0x54($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800955E8: lw          $t8, 0x7C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X7C));
    // 0x800955EC: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x800955F0: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800955F4: lw          $a1, 0x64($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800955F8: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800955FC: lw          $a2, 0x18($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80095600: jal         0x8008FD60
    // 0x80095604: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_3;
    // 0x80095604: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_3:
    // 0x80095608: lw          $t6, 0x58($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X58));
    // 0x8009560C: lw          $t9, 0x80($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X80));
    // 0x80095610: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80095614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80095618: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
L_8009561C:
    // 0x8009561C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80095620: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80095624: jr          $ra
    // 0x80095628: nop

    return;
    // 0x80095628: nop

;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2BF0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800C2BF4: lw          $v0, 0x0($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C2BF8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C2BFC: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800C2C00: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x800C2C04: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800C2C08: beq         $at, $zero, L_800C2C70
    if (ctx->r1 == 0) {
        // 0x800C2C0C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800C2C70;
    }
    // 0x800C2C0C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800C2C10: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800C2C14: bne         $at, $zero, L_800C2C68
    if (ctx->r1 != 0) {
        // 0x800C2C18: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800C2C68;
    }
    // 0x800C2C18: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800C2C1C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800C2C20: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C2C24: addiu       $v1, $v1, -0x6440
    ctx->r3 = ADD32(ctx->r3, -0X6440);
    // 0x800C2C28: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800C2C2C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800C2C30: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800C2C34: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800C2C38: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800C2C3C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800C2C40: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800C2C44: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800C2C48: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800C2C4C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800C2C50: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800C2C54: nop

    // 0x800C2C58: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800C2C5C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800C2C60: jr          $ra
    // 0x800C2C64: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800C2C64: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800C2C68:
    // 0x800C2C68: jr          $ra
    // 0x800C2C6C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = S32(MEM_W(ctx->r29, 0X0));
    return;
    // 0x800C2C6C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = S32(MEM_W(ctx->r29, 0X0));
L_800C2C70:
    // 0x800C2C70: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800C2C74: beq         $at, $zero, L_800C2D88
    if (ctx->r1 == 0) {
        // 0x800C2C78: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X0));
            goto L_800C2D88;
    }
    // 0x800C2C78: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C2C7C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C2C80: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2C84: ldc1        $f10, -0x6418($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6418);
    // 0x800C2C88: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800C2C8C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800C2C90: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800C2C94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C2C98: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C2C9C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800C2CA0: nop

    // 0x800C2CA4: bc1fl       L_800C2CD4
    if (!c1cs) {
        // 0x800C2CA8: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800C2CD4;
    }
    goto skip_0;
    // 0x800C2CA8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800C2CAC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C2CB0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C2CB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C2CB8: nop

    // 0x800C2CBC: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x800C2CC0: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800C2CC4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C2CC8: b           L_800C2CF0
    // 0x800C2CCC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_800C2CF0;
    // 0x800C2CCC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800C2CD0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800C2CD4:
    // 0x800C2CD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C2CD8: nop

    // 0x800C2CDC: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x800C2CE0: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800C2CE4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800C2CE8: nop

    // 0x800C2CEC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_800C2CF0:
    // 0x800C2CF0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2CF4: ldc1        $f18, -0x6410($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6410);
    // 0x800C2CF8: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x800C2CFC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2D00: ldc1        $f6, -0x6408($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6408);
    // 0x800C2D04: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C2D08: addiu       $v1, $v1, -0x6440
    ctx->r3 = ADD32(ctx->r3, -0X6440);
    // 0x800C2D0C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800C2D10: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800C2D14: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800C2D18: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800C2D1C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800C2D20: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800C2D24: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800C2D28: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800C2D2C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800C2D30: nop

    // 0x800C2D34: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800C2D38: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800C2D3C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800C2D40: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800C2D44: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800C2D48: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800C2D4C: bne         $t9, $zero, L_800C2D6C
    if (ctx->r25 != 0) {
        // 0x800C2D50: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800C2D6C;
    }
    // 0x800C2D50: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800C2D54: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800C2D58: nop

    // 0x800C2D5C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800C2D60: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800C2D64: jr          $ra
    // 0x800C2D68: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800C2D68: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800C2D6C:
    // 0x800C2D6C: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800C2D70: nop

    // 0x800C2D74: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800C2D78: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800C2D7C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800C2D80: jr          $ra
    // 0x800C2D84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800C2D84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800C2D88:
    // 0x800C2D88: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800C2D8C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2D90: bc1t        L_800C2DA4
    if (c1cs) {
        // 0x800C2D94: nop
    
            goto L_800C2DA4;
    }
    // 0x800C2D94: nop

    // 0x800C2D98: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2D9C: jr          $ra
    // 0x800C2DA0: lwc1        $f0, -0x5EF0($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X5EF0));
    return;
    // 0x800C2DA0: lwc1        $f0, -0x5EF0($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X5EF0));
L_800C2DA4:
    // 0x800C2DA4: lwc1        $f0, -0x6400($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X6400));
    // 0x800C2DA8: jr          $ra
    // 0x800C2DAC: nop

    return;
    // 0x800C2DAC: nop

;}
RECOMP_FUNC void mulscale28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009009C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800900A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800900A4: jal         0x800BB8F8
    // 0x800900A8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800900A8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800900AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800900B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800900B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800900B8: jal         0x800BBA24
    // 0x800900BC: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x800900BC: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_1:
    // 0x800900C0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800900C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800900C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800900CC: jr          $ra
    // 0x800900D0: nop

    return;
    // 0x800900D0: nop

;}
RECOMP_FUNC void unsetfxsprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E39C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8006E3A0: addiu       $a2, $a2, 0x4418
    ctx->r6 = ADD32(ctx->r6, 0X4418);
    // 0x8006E3A4: lw          $v1, 0x0($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X0));
    // 0x8006E3A8: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8006E3AC: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x8006E3B0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006E3B4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8006E3B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006E3BC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8006E3C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006E3C4: lw          $v1, 0x0($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X0));
    // 0x8006E3C8: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8006E3CC: ori         $t0, $t0, 0xE02
    ctx->r8 = ctx->r8 | 0XE02;
    // 0x8006E3D0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006E3D4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8006E3D8: ori         $t1, $zero, 0x8000
    ctx->r9 = 0 | 0X8000;
    // 0x8006E3DC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8006E3E0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8006E3E4: lw          $v1, 0x0($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0X0));
    // 0x8006E3E8: lui         $t3, 0xFC12
    ctx->r11 = S32(0XFC12 << 16);
    // 0x8006E3EC: lui         $t4, 0xFF33
    ctx->r12 = S32(0XFF33 << 16);
    // 0x8006E3F0: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8006E3F4: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x8006E3F8: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8006E3FC: ori         $t3, $t3, 0x1824
    ctx->r11 = ctx->r11 | 0X1824;
    // 0x8006E400: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006E404: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8006E408: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8006E40C: jr          $ra
    // 0x8006E410: sb          $zero, -0x13CF($at)
    MEM_B(-0X13CF, ctx->r1) = 0;
    return;
    // 0x8006E410: sb          $zero, -0x13CF($at)
    MEM_B(-0X13CF, ctx->r1) = 0;
;}
RECOMP_FUNC void alAudioFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C25A8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C25AC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800C25B0: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x800C25B4: lw          $s1, 0x2140($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X2140));
    // 0x800C25B8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C25BC: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800C25C0: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800C25C4: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800C25C8: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800C25CC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800C25D0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800C25D4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800C25D8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800C25DC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C25E0: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800C25E4: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800C25E8: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
    // 0x800C25EC: lw          $t7, 0x0($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C25F0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800C25F4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800C25F8: bne         $t7, $zero, L_800C260C
    if (ctx->r15 != 0) {
        // 0x800C25FC: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_800C260C;
    }
    // 0x800C25FC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800C2600: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C2604: b           L_800C280C
    // 0x800C2608: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800C280C;
    // 0x800C2608: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800C260C:
    // 0x800C260C: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x800C2610: lw          $v0, 0x0($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C2614: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x800C2618: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x800C261C: beq         $v0, $zero, L_800C2658
    if (ctx->r2 == 0) {
        // 0x800C2620: addiu       $s2, $zero, -0x10
        ctx->r18 = ADD32(0, -0X10);
            goto L_800C2658;
    }
    // 0x800C2620: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800C2624: lw          $a0, 0x20($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X20));
    // 0x800C2628: lw          $t9, 0x10($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X10));
L_800C262C:
    // 0x800C262C: subu        $t0, $t9, $a0
    ctx->r8 = SUB32(ctx->r25, ctx->r4);
    // 0x800C2630: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C2634: beql        $at, $zero, L_800C2650
    if (ctx->r1 == 0) {
        // 0x800C2638: lw          $v0, 0x0($v0)
        ctx->r2 = S32(MEM_W(ctx->r2, 0X0));
            goto L_800C2650;
    }
    goto skip_0;
    // 0x800C2638: lw          $v0, 0x0($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, 0X0));
    skip_0:
    // 0x800C263C: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x800C2640: lw          $t1, 0x10($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X10));
    // 0x800C2644: lw          $a0, 0x20($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X20));
    // 0x800C2648: subu        $v1, $t1, $a0
    ctx->r3 = SUB32(ctx->r9, ctx->r4);
    // 0x800C264C: lw          $v0, 0x0($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, 0X0));
L_800C2650:
    // 0x800C2650: bnel        $v0, $zero, L_800C262C
    if (ctx->r2 != 0) {
        // 0x800C2654: lw          $t9, 0x10($v0)
        ctx->r25 = S32(MEM_W(ctx->r2, 0X10));
            goto L_800C262C;
    }
    goto skip_1;
    // 0x800C2654: lw          $t9, 0x10($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X10));
    skip_1:
L_800C2658:
    // 0x800C2658: lw          $t2, 0xB4($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800C265C: lw          $a0, 0x20($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X20));
    // 0x800C2660: lw          $v0, 0x10($t2)
    ctx->r2 = S32(MEM_W(ctx->r10, 0X10));
    // 0x800C2664: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x800C2668: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C266C: beq         $at, $zero, L_800C2750
    if (ctx->r1 == 0) {
        // 0x800C2670: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_800C2750;
    }
    // 0x800C2670: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x800C2674: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C2678: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800C267C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2680: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800C2684: ldc1        $f20, -0x6448($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X6448);
L_800C2688:
    // 0x800C2688: lw          $t4, 0x1C($s1)
    ctx->r12 = S32(MEM_W(ctx->r17, 0X1C));
    // 0x800C268C: lui         $s0, 0x7FFF
    ctx->r16 = S32(0X7FFF << 16);
    // 0x800C2690: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x800C2694: and         $t5, $t4, $s2
    ctx->r13 = ctx->r12 & ctx->r18;
    // 0x800C2698: sw          $t5, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r13;
    // 0x800C269C: lw          $a0, 0xB4($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800C26A0: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800C26A4: jalr        $t9
    // 0x800C26A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800C26A8: nop

    after_0:
    // 0x800C26AC: lw          $t8, 0x44($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X44));
    // 0x800C26B0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800C26B4: lw          $t0, 0xB4($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x800C26B8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800C26BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C26C0: lw          $t1, 0x10($t0)
    ctx->r9 = S32(MEM_W(ctx->r8, 0X10));
    // 0x800C26C4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C26C8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C26CC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800C26D0: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x800C26D4: add.d       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f4.d + ctx->f22.d;
    // 0x800C26D8: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800C26DC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C26E0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800C26E4: nop

    // 0x800C26E8: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800C26EC: sw          $t2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r10;
    // 0x800C26F0: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x800C26F4: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800C26F8: beql        $v1, $zero, L_800C2738
    if (ctx->r3 == 0) {
        // 0x800C26FC: lw          $t7, 0xB4($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0XB4));
            goto L_800C2738;
    }
    goto skip_2;
    // 0x800C26FC: lw          $t7, 0xB4($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XB4));
    skip_2:
    // 0x800C2700: lw          $a0, 0x20($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X20));
    // 0x800C2704: lw          $t3, 0x10($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X10));
L_800C2708:
    // 0x800C2708: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x800C270C: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800C2710: beql        $at, $zero, L_800C272C
    if (ctx->r1 == 0) {
        // 0x800C2714: lw          $v1, 0x0($v1)
        ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800C272C;
    }
    goto skip_3;
    // 0x800C2714: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
    skip_3:
    // 0x800C2718: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    // 0x800C271C: lw          $t5, 0x10($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X10));
    // 0x800C2720: lw          $a0, 0x20($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X20));
    // 0x800C2724: subu        $s0, $t5, $a0
    ctx->r16 = SUB32(ctx->r13, ctx->r4);
    // 0x800C2728: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
L_800C272C:
    // 0x800C272C: bnel        $v1, $zero, L_800C2708
    if (ctx->r3 != 0) {
        // 0x800C2730: lw          $t3, 0x10($v1)
        ctx->r11 = S32(MEM_W(ctx->r3, 0X10));
            goto L_800C2708;
    }
    goto skip_4;
    // 0x800C2730: lw          $t3, 0x10($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X10));
    skip_4:
    // 0x800C2734: lw          $t7, 0xB4($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XB4));
L_800C2738:
    // 0x800C2738: lw          $a0, 0x20($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X20));
    // 0x800C273C: lw          $v0, 0x10($t7)
    ctx->r2 = S32(MEM_W(ctx->r15, 0X10));
    // 0x800C2740: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x800C2744: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C2748: bne         $at, $zero, L_800C2688
    if (ctx->r1 != 0) {
        // 0x800C274C: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_800C2688;
    }
    // 0x800C274C: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_800C2750:
    // 0x800C2750: lw          $t8, 0x1C($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X1C));
    // 0x800C2754: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800C2758: addiu       $s7, $sp, 0xAA
    ctx->r23 = ADD32(ctx->r29, 0XAA);
    // 0x800C275C: and         $t6, $t8, $s2
    ctx->r14 = ctx->r24 & ctx->r18;
    // 0x800C2760: blez        $s3, L_800C27EC
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800C2764: sw          $t6, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r14;
            goto L_800C27EC;
    }
    // 0x800C2764: sw          $t6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r14;
    // 0x800C2768: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_800C276C:
    // 0x800C276C: lw          $v0, 0x48($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X48));
    // 0x800C2770: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800C2774: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800C2778: beq         $at, $zero, L_800C2788
    if (ctx->r1 == 0) {
        // 0x800C277C: nop
    
            goto L_800C2788;
    }
    // 0x800C277C: nop

    // 0x800C2780: b           L_800C2788
    // 0x800C2784: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800C2788;
    // 0x800C2784: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C2788:
    // 0x800C2788: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x800C278C: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x800C2790: lw          $s2, 0x38($s1)
    ctx->r18 = S32(MEM_W(ctx->r17, 0X38));
    // 0x800C2794: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800C2798: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800C279C: lw          $t9, 0x8($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X8));
    // 0x800C27A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C27A4: jalr        $t9
    // 0x800C27A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C27A8: nop

    after_1:
    // 0x800C27AC: lw          $a3, 0x20($s1)
    ctx->r7 = S32(MEM_W(ctx->r17, 0X20));
    // 0x800C27B0: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x800C27B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C27B8: lw          $t9, 0x4($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X4));
    // 0x800C27BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C27C0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800C27C4: jalr        $t9
    // 0x800C27C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C27C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800C27CC: lw          $t3, 0x20($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X20));
    // 0x800C27D0: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x800C27D4: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800C27D8: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800C27DC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800C27E0: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x800C27E4: bgtz        $s3, L_800C276C
    if (SIGNED(ctx->r19) > 0) {
        // 0x800C27E8: sw          $t4, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->r12;
            goto L_800C276C;
    }
    // 0x800C27E8: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
L_800C27EC:
    // 0x800C27EC: lw          $t5, 0xB8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800C27F0: lw          $t6, 0xBC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XBC));
    // 0x800C27F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C27F8: subu        $t7, $s4, $t5
    ctx->r15 = SUB32(ctx->r20, ctx->r13);
    // 0x800C27FC: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800C2800: jal         0x800C24F8
    // 0x800C2804: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    _collectPVoices(rdram, ctx);
        goto after_3;
    // 0x800C2804: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    after_3:
    // 0x800C2808: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_800C280C:
    // 0x800C280C: lw          $ra, 0x4C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800C2810: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C2814: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800C2818: lw          $s0, 0x2C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800C281C: lw          $s1, 0x30($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800C2820: lw          $s2, 0x34($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800C2824: lw          $s3, 0x38($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C2828: lw          $s4, 0x3C($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800C282C: lw          $s5, 0x40($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800C2830: lw          $s6, 0x44($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800C2834: lw          $s7, 0x48($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800C2838: jr          $ra
    // 0x800C283C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800C283C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void getspritescore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4FEC: slti        $at, $a1, 0x65
    ctx->r1 = SIGNED(ctx->r5) < 0X65 ? 1 : 0;
    // 0x800B4FF0: bne         $at, $zero, L_800B5008
    if (ctx->r1 != 0) {
        // 0x800B4FF4: addiu       $at, $zero, 0x544
        ctx->r1 = ADD32(0, 0X544);
            goto L_800B5008;
    }
    // 0x800B4FF4: addiu       $at, $zero, 0x544
    ctx->r1 = ADD32(0, 0X544);
    // 0x800B4FF8: beq         $a1, $at, L_800B55FC
    if (ctx->r5 == ctx->r1) {
        // 0x800B4FFC: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_800B55FC;
    }
    // 0x800B4FFC: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800B5000: b           L_800B5640
    // 0x800B5004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B5640;
    // 0x800B5004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5008:
    // 0x800B5008: slti        $at, $a1, 0x3E
    ctx->r1 = SIGNED(ctx->r5) < 0X3E ? 1 : 0;
    // 0x800B500C: bne         $at, $zero, L_800B5028
    if (ctx->r1 != 0) {
        // 0x800B5010: addiu       $t6, $a1, -0x15
        ctx->r14 = ADD32(ctx->r5, -0X15);
            goto L_800B5028;
    }
    // 0x800B5010: addiu       $t6, $a1, -0x15
    ctx->r14 = ADD32(ctx->r5, -0X15);
    // 0x800B5014: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800B5018: beq         $a1, $at, L_800B559C
    if (ctx->r5 == ctx->r1) {
        // 0x800B501C: sll         $t3, $a0, 3
        ctx->r11 = S32(ctx->r4 << 3);
            goto L_800B559C;
    }
    // 0x800B501C: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800B5020: b           L_800B5640
    // 0x800B5024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B5640;
    // 0x800B5024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5028:
    // 0x800B5028: sltiu       $at, $t6, 0x29
    ctx->r1 = ctx->r14 < 0X29 ? 1 : 0;
    // 0x800B502C: beq         $at, $zero, L_800B563C
    if (ctx->r1 == 0) {
        // 0x800B5030: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B563C;
    }
    // 0x800B5030: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5034: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B5038: addu        $at, $at, $t6
    gpr jr_addend_800B5040 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B503C: lw          $t6, -0x6DF0($at)
    ctx->r14 = ADD32(ctx->r1, -0X6DF0);
    // 0x800B5040: jr          $t6
    // 0x800B5044: nop

    switch (jr_addend_800B5040 >> 2) {
        case 0: goto L_800B5048; break;
        case 1: goto L_800B5050; break;
        case 2: goto L_800B5088; break;
        case 3: goto L_800B5060; break;
        case 4: goto L_800B5068; break;
        case 5: goto L_800B5070; break;
        case 6: goto L_800B5078; break;
        case 7: goto L_800B5080; break;
        case 8: goto L_800B5058; break;
        case 9: goto L_800B563C; break;
        case 10: goto L_800B563C; break;
        case 11: goto L_800B563C; break;
        case 12: goto L_800B563C; break;
        case 13: goto L_800B563C; break;
        case 14: goto L_800B563C; break;
        case 15: goto L_800B563C; break;
        case 16: goto L_800B5090; break;
        case 17: goto L_800B563C; break;
        case 18: goto L_800B563C; break;
        case 19: goto L_800B50DC; break;
        case 20: goto L_800B5128; break;
        case 21: goto L_800B51C0; break;
        case 22: goto L_800B563C; break;
        case 23: goto L_800B5174; break;
        case 24: goto L_800B563C; break;
        case 25: goto L_800B520C; break;
        case 26: goto L_800B5258; break;
        case 27: goto L_800B563C; break;
        case 28: goto L_800B52A4; break;
        case 29: goto L_800B563C; break;
        case 30: goto L_800B52F0; break;
        case 31: goto L_800B5354; break;
        case 32: goto L_800B53B8; break;
        case 33: goto L_800B53FC; break;
        case 34: goto L_800B5440; break;
        case 35: goto L_800B5484; break;
        case 36: goto L_800B54C8; break;
        case 37: goto L_800B563C; break;
        case 38: goto L_800B550C; break;
        case 39: goto L_800B5550; break;
        case 40: goto L_800B5558; break;
        default: switch_error(__func__, 0x800B5040, 0x80109210);
    }
    // 0x800B5044: nop

L_800B5048:
    // 0x800B5048: jr          $ra
    // 0x800B504C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x800B504C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800B5050:
    // 0x800B5050: jr          $ra
    // 0x800B5054: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800B5054: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800B5058:
    // 0x800B5058: jr          $ra
    // 0x800B505C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    return;
    // 0x800B505C: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_800B5060:
    // 0x800B5060: jr          $ra
    // 0x800B5064: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x800B5064: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800B5068:
    // 0x800B5068: jr          $ra
    // 0x800B506C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    return;
    // 0x800B506C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
L_800B5070:
    // 0x800B5070: jr          $ra
    // 0x800B5074: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    return;
    // 0x800B5074: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_800B5078:
    // 0x800B5078: jr          $ra
    // 0x800B507C: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800B507C: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800B5080:
    // 0x800B5080: jr          $ra
    // 0x800B5084: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x800B5084: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_800B5088:
    // 0x800B5088: jr          $ra
    // 0x800B508C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x800B508C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_800B5090:
    // 0x800B5090: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800B5094: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B5098: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B509C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800B50A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B50A4: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B50A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B50AC: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800B50B0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B50B4: lui         $t9, 0x8028
    ctx->r25 = S32(0X8028 << 16);
    // 0x800B50B8: lw          $t9, -0x5C18($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X5C18));
    // 0x800B50BC: lh          $t8, 0x5A12($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X5A12));
    // 0x800B50C0: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B50C4: beq         $at, $zero, L_800B50D4
    if (ctx->r1 == 0) {
        // 0x800B50C8: nop
    
            goto L_800B50D4;
    }
    // 0x800B50C8: nop

    // 0x800B50CC: jr          $ra
    // 0x800B50D0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800B50D0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800B50D4:
    // 0x800B50D4: jr          $ra
    // 0x800B50D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B50D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B50DC:
    // 0x800B50DC: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x800B50E0: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800B50E4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800B50E8: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x800B50EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800B50F0: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800B50F4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800B50F8: lui         $t1, 0x802A
    ctx->r9 = S32(0X802A << 16);
    // 0x800B50FC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800B5100: lui         $t2, 0x8028
    ctx->r10 = S32(0X8028 << 16);
    // 0x800B5104: lw          $t2, -0x5C3C($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X5C3C));
    // 0x800B5108: lh          $t1, 0x5A00($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, 0X5A00));
    // 0x800B510C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B5110: beq         $at, $zero, L_800B5120
    if (ctx->r1 == 0) {
        // 0x800B5114: nop
    
            goto L_800B5120;
    }
    // 0x800B5114: nop

    // 0x800B5118: jr          $ra
    // 0x800B511C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800B511C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800B5120:
    // 0x800B5120: jr          $ra
    // 0x800B5124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5128:
    // 0x800B5128: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800B512C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800B5130: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800B5134: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x800B5138: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B513C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800B5140: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B5144: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x800B5148: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B514C: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x800B5150: lw          $t5, -0x5C34($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X5C34));
    // 0x800B5154: lh          $t4, 0x5A04($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, 0X5A04));
    // 0x800B5158: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B515C: beq         $at, $zero, L_800B516C
    if (ctx->r1 == 0) {
        // 0x800B5160: nop
    
            goto L_800B516C;
    }
    // 0x800B5160: nop

    // 0x800B5164: jr          $ra
    // 0x800B5168: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x800B5168: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_800B516C:
    // 0x800B516C: jr          $ra
    // 0x800B5170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5174:
    // 0x800B5174: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800B5178: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800B517C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800B5180: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800B5184: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5188: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800B518C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5190: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800B5194: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B5198: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x800B519C: lw          $t8, -0x5C30($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X5C30));
    // 0x800B51A0: lh          $t7, 0x5A06($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X5A06));
    // 0x800B51A4: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B51A8: beq         $at, $zero, L_800B51B8
    if (ctx->r1 == 0) {
        // 0x800B51AC: nop
    
            goto L_800B51B8;
    }
    // 0x800B51AC: nop

    // 0x800B51B0: jr          $ra
    // 0x800B51B4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x800B51B4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800B51B8:
    // 0x800B51B8: jr          $ra
    // 0x800B51BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B51BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B51C0:
    // 0x800B51C0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800B51C4: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800B51C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800B51CC: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800B51D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B51D4: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800B51D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B51DC: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x800B51E0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B51E4: lui         $t1, 0x8028
    ctx->r9 = S32(0X8028 << 16);
    // 0x800B51E8: lw          $t1, -0x5C20($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, -0X5C20));
    // 0x800B51EC: lh          $t0, 0x5A0E($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X5A0E));
    // 0x800B51F0: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B51F4: beq         $at, $zero, L_800B5204
    if (ctx->r1 == 0) {
        // 0x800B51F8: nop
    
            goto L_800B5204;
    }
    // 0x800B51F8: nop

    // 0x800B51FC: jr          $ra
    // 0x800B5200: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800B5200: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800B5204:
    // 0x800B5204: jr          $ra
    // 0x800B5208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B520C:
    // 0x800B520C: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x800B5210: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x800B5214: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800B5218: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x800B521C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B5220: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x800B5224: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B5228: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x800B522C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800B5230: lui         $t4, 0x8028
    ctx->r12 = S32(0X8028 << 16);
    // 0x800B5234: lw          $t4, -0x5C28($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X5C28));
    // 0x800B5238: lh          $t3, 0x5A0A($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, 0X5A0A));
    // 0x800B523C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B5240: beq         $at, $zero, L_800B5250
    if (ctx->r1 == 0) {
        // 0x800B5244: nop
    
            goto L_800B5250;
    }
    // 0x800B5244: nop

    // 0x800B5248: jr          $ra
    // 0x800B524C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800B524C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800B5250:
    // 0x800B5250: jr          $ra
    // 0x800B5254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5258:
    // 0x800B5258: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800B525C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800B5260: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800B5264: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x800B5268: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B526C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800B5270: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5274: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800B5278: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800B527C: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800B5280: lw          $t7, -0x5C2C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X5C2C));
    // 0x800B5284: lh          $t6, 0x5A08($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X5A08));
    // 0x800B5288: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B528C: beq         $at, $zero, L_800B529C
    if (ctx->r1 == 0) {
        // 0x800B5290: nop
    
            goto L_800B529C;
    }
    // 0x800B5290: nop

    // 0x800B5294: jr          $ra
    // 0x800B5298: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    return;
    // 0x800B5298: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_800B529C:
    // 0x800B529C: jr          $ra
    // 0x800B52A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B52A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B52A4:
    // 0x800B52A4: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800B52A8: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800B52AC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B52B0: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800B52B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B52B8: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800B52BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B52C0: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x800B52C4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B52C8: lui         $t0, 0x8028
    ctx->r8 = S32(0X8028 << 16);
    // 0x800B52CC: lw          $t0, -0x5C38($t0)
    ctx->r8 = S32(MEM_W(ctx->r8, -0X5C38));
    // 0x800B52D0: lh          $t9, 0x5A02($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X5A02));
    // 0x800B52D4: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B52D8: beq         $at, $zero, L_800B52E8
    if (ctx->r1 == 0) {
        // 0x800B52DC: nop
    
            goto L_800B52E8;
    }
    // 0x800B52DC: nop

    // 0x800B52E0: jr          $ra
    // 0x800B52E4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    return;
    // 0x800B52E4: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_800B52E8:
    // 0x800B52E8: jr          $ra
    // 0x800B52EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B52EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B52F0:
    // 0x800B52F0: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x800B52F4: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800B52F8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800B52FC: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x800B5300: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B5304: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800B5308: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B530C: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x800B5310: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B5314: lh          $t2, 0x5A50($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X5A50));
    // 0x800B5318: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x800B531C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B5320: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800B5324: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B5328: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800B532C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B5330: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B5334: lh          $t4, 0x6BCA($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, 0X6BCA));
    // 0x800B5338: slti        $at, $t4, 0x64
    ctx->r1 = SIGNED(ctx->r12) < 0X64 ? 1 : 0;
    // 0x800B533C: beq         $at, $zero, L_800B534C
    if (ctx->r1 == 0) {
        // 0x800B5340: nop
    
            goto L_800B534C;
    }
    // 0x800B5340: nop

    // 0x800B5344: jr          $ra
    // 0x800B5348: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800B5348: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800B534C:
    // 0x800B534C: jr          $ra
    // 0x800B5350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5354:
    // 0x800B5354: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800B5358: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800B535C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800B5360: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x800B5364: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5368: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800B536C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5370: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800B5374: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800B5378: lh          $t6, 0x5A50($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X5A50));
    // 0x800B537C: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800B5380: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B5384: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B5388: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B538C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B5390: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B5394: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B5398: lh          $t8, 0x6BCA($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X6BCA));
    // 0x800B539C: slti        $at, $t8, 0x64
    ctx->r1 = SIGNED(ctx->r24) < 0X64 ? 1 : 0;
    // 0x800B53A0: beq         $at, $zero, L_800B53B0
    if (ctx->r1 == 0) {
        // 0x800B53A4: nop
    
            goto L_800B53B0;
    }
    // 0x800B53A4: nop

    // 0x800B53A8: jr          $ra
    // 0x800B53AC: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    return;
    // 0x800B53AC: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_800B53B0:
    // 0x800B53B0: jr          $ra
    // 0x800B53B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B53B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B53B8:
    // 0x800B53B8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800B53BC: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800B53C0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800B53C4: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800B53C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B53CC: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800B53D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B53D4: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x800B53D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B53DC: lh          $t0, 0x5A4A($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X5A4A));
    // 0x800B53E0: slti        $at, $t0, 0x64
    ctx->r1 = SIGNED(ctx->r8) < 0X64 ? 1 : 0;
    // 0x800B53E4: beq         $at, $zero, L_800B53F4
    if (ctx->r1 == 0) {
        // 0x800B53E8: nop
    
            goto L_800B53F4;
    }
    // 0x800B53E8: nop

    // 0x800B53EC: jr          $ra
    // 0x800B53F0: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    return;
    // 0x800B53F0: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_800B53F4:
    // 0x800B53F4: jr          $ra
    // 0x800B53F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B53F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B53FC:
    // 0x800B53FC: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x800B5400: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800B5404: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800B5408: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x800B540C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B5410: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800B5414: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B5418: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x800B541C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B5420: lh          $t2, 0x5A92($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X5A92));
    // 0x800B5424: slti        $at, $t2, 0x64
    ctx->r1 = SIGNED(ctx->r10) < 0X64 ? 1 : 0;
    // 0x800B5428: beq         $at, $zero, L_800B5438
    if (ctx->r1 == 0) {
        // 0x800B542C: nop
    
            goto L_800B5438;
    }
    // 0x800B542C: nop

    // 0x800B5430: jr          $ra
    // 0x800B5434: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800B5434: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800B5438:
    // 0x800B5438: jr          $ra
    // 0x800B543C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B543C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5440:
    // 0x800B5440: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800B5444: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800B5448: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800B544C: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x800B5450: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B5454: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800B5458: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B545C: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x800B5460: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B5464: lh          $t4, 0x5A90($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, 0X5A90));
    // 0x800B5468: slti        $at, $t4, 0x190
    ctx->r1 = SIGNED(ctx->r12) < 0X190 ? 1 : 0;
    // 0x800B546C: beq         $at, $zero, L_800B547C
    if (ctx->r1 == 0) {
        // 0x800B5470: nop
    
            goto L_800B547C;
    }
    // 0x800B5470: nop

    // 0x800B5474: jr          $ra
    // 0x800B5478: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    return;
    // 0x800B5478: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_800B547C:
    // 0x800B547C: jr          $ra
    // 0x800B5480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5484:
    // 0x800B5484: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800B5488: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800B548C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800B5490: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x800B5494: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B5498: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800B549C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B54A0: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800B54A4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800B54A8: lh          $t6, 0x5A8C($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X5A8C));
    // 0x800B54AC: slti        $at, $t6, 0x1900
    ctx->r1 = SIGNED(ctx->r14) < 0X1900 ? 1 : 0;
    // 0x800B54B0: beq         $at, $zero, L_800B54C0
    if (ctx->r1 == 0) {
        // 0x800B54B4: nop
    
            goto L_800B54C0;
    }
    // 0x800B54B4: nop

    // 0x800B54B8: jr          $ra
    // 0x800B54BC: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    return;
    // 0x800B54BC: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_800B54C0:
    // 0x800B54C0: jr          $ra
    // 0x800B54C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B54C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B54C8:
    // 0x800B54C8: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800B54CC: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B54D0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B54D4: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800B54D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B54DC: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B54E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B54E4: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800B54E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B54EC: lh          $t8, 0x5A8E($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X5A8E));
    // 0x800B54F0: slti        $at, $t8, 0x640
    ctx->r1 = SIGNED(ctx->r24) < 0X640 ? 1 : 0;
    // 0x800B54F4: beq         $at, $zero, L_800B5504
    if (ctx->r1 == 0) {
        // 0x800B54F8: nop
    
            goto L_800B5504;
    }
    // 0x800B54F8: nop

    // 0x800B54FC: jr          $ra
    // 0x800B5500: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    return;
    // 0x800B5500: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_800B5504:
    // 0x800B5504: jr          $ra
    // 0x800B5508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B550C:
    // 0x800B550C: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800B5510: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800B5514: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800B5518: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800B551C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B5520: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800B5524: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B5528: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x800B552C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800B5530: lh          $t0, 0x5A5C($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X5A5C));
    // 0x800B5534: slti        $at, $t0, 0x4B0
    ctx->r1 = SIGNED(ctx->r8) < 0X4B0 ? 1 : 0;
    // 0x800B5538: beq         $at, $zero, L_800B5548
    if (ctx->r1 == 0) {
        // 0x800B553C: nop
    
            goto L_800B5548;
    }
    // 0x800B553C: nop

    // 0x800B5540: jr          $ra
    // 0x800B5544: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x800B5544: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800B5548:
    // 0x800B5548: jr          $ra
    // 0x800B554C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B554C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5550:
    // 0x800B5550: jr          $ra
    // 0x800B5554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800B5554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B5558:
    // 0x800B5558: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x800B555C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800B5560: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800B5564: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x800B5568: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B556C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800B5570: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B5574: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x800B5578: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800B557C: lh          $t2, 0x5AA2($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X5AA2));
    // 0x800B5580: slti        $at, $t2, 0xC8
    ctx->r1 = SIGNED(ctx->r10) < 0XC8 ? 1 : 0;
    // 0x800B5584: beq         $at, $zero, L_800B5594
    if (ctx->r1 == 0) {
        // 0x800B5588: nop
    
            goto L_800B5594;
    }
    // 0x800B5588: nop

    // 0x800B558C: jr          $ra
    // 0x800B5590: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800B5590: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800B5594:
    // 0x800B5594: jr          $ra
    // 0x800B5598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B559C:
    // 0x800B559C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800B55A0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800B55A4: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x800B55A8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B55AC: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800B55B0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B55B4: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x800B55B8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B55BC: lh          $t4, 0x5A50($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, 0X5A50));
    // 0x800B55C0: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x800B55C4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800B55C8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B55CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B55D0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800B55D4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B55D8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800B55DC: lh          $t6, 0x6BCA($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X6BCA));
    // 0x800B55E0: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x800B55E4: beq         $at, $zero, L_800B55F4
    if (ctx->r1 == 0) {
        // 0x800B55E8: nop
    
            goto L_800B55F4;
    }
    // 0x800B55E8: nop

    // 0x800B55EC: jr          $ra
    // 0x800B55F0: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x800B55F0: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_800B55F4:
    // 0x800B55F4: jr          $ra
    // 0x800B55F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B55F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B55FC:
    // 0x800B55FC: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B5600: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B5604: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800B5608: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B560C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800B5610: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B5614: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800B5618: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B561C: lh          $t8, 0x5A2C($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X5A2C));
    // 0x800B5620: slti        $at, $t8, 0x960
    ctx->r1 = SIGNED(ctx->r24) < 0X960 ? 1 : 0;
    // 0x800B5624: beq         $at, $zero, L_800B5634
    if (ctx->r1 == 0) {
        // 0x800B5628: nop
    
            goto L_800B5634;
    }
    // 0x800B5628: nop

    // 0x800B562C: jr          $ra
    // 0x800B5630: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    return;
    // 0x800B5630: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_800B5634:
    // 0x800B5634: jr          $ra
    // 0x800B5638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B5638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B563C:
    // 0x800B563C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B5640:
    // 0x800B5640: jr          $ra
    // 0x800B5644: nop

    return;
    // 0x800B5644: nop

;}
RECOMP_FUNC void mulscale29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800900D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800900D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800900DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800900E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800900E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800900E8: jal         0x800BB8F8
    // 0x800900EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x800900EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800900F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800900F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800900F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800900FC: jal         0x800BBA24
    // 0x80090100: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x80090100: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    after_1:
    // 0x80090104: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009010C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090110: jr          $ra
    // 0x80090114: nop

    return;
    // 0x80090114: nop

;}
RECOMP_FUNC void inventory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A258: lh          $v0, 0xE($a0)
    ctx->r2 = S32(MEM_H(ctx->r4, 0XE));
    // 0x8009A25C: slti        $at, $v0, 0x3E
    ctx->r1 = SIGNED(ctx->r2) < 0X3E ? 1 : 0;
    // 0x8009A260: bne         $at, $zero, L_8009A27C
    if (ctx->r1 != 0) {
        // 0x8009A264: addiu       $t6, $v0, -0x35
        ctx->r14 = ADD32(ctx->r2, -0X35);
            goto L_8009A27C;
    }
    // 0x8009A264: addiu       $t6, $v0, -0x35
    ctx->r14 = ADD32(ctx->r2, -0X35);
    // 0x8009A268: addiu       $at, $zero, 0x544
    ctx->r1 = ADD32(0, 0X544);
    // 0x8009A26C: beq         $v0, $at, L_8009A29C
    if (ctx->r2 == ctx->r1) {
        // 0x8009A270: nop
    
            goto L_8009A29C;
    }
    // 0x8009A270: nop

    // 0x8009A274: b           L_8009A2A8
    // 0x8009A278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A2A8;
    // 0x8009A278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A27C:
    // 0x8009A27C: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8009A280: beq         $at, $zero, L_8009A2A4
    if (ctx->r1 == 0) {
        // 0x8009A284: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8009A2A4;
    }
    // 0x8009A284: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009A288: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8009A28C: addu        $at, $at, $t6
    gpr jr_addend_8009A294 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8009A290: lw          $t6, 0x6968($at)
    ctx->r14 = ADD32(ctx->r1, 0X6968);
    // 0x8009A294: jr          $t6
    // 0x8009A298: nop

    switch (jr_addend_8009A294 >> 2) {
        case 0: goto L_8009A29C; break;
        case 1: goto L_8009A2A4; break;
        case 2: goto L_8009A29C; break;
        case 3: goto L_8009A29C; break;
        case 4: goto L_8009A29C; break;
        case 5: goto L_8009A2A4; break;
        case 6: goto L_8009A29C; break;
        case 7: goto L_8009A2A4; break;
        case 8: goto L_8009A29C; break;
        default: switch_error(__func__, 0x8009A294, 0x80106968);
    }
    // 0x8009A298: nop

L_8009A29C:
    // 0x8009A29C: jr          $ra
    // 0x8009A2A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009A2A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009A2A4:
    // 0x8009A2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009A2A8:
    // 0x8009A2A8: jr          $ra
    // 0x8009A2AC: nop

    return;
    // 0x8009A2AC: nop

;}
RECOMP_FUNC void mulscale27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009004C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090058: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009005C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80090060: jal         0x800BB8F8
    // 0x80090064: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090064: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009006C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80090070: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090074: jal         0x800BBA24
    // 0x80090078: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x80090078: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    after_1:
    // 0x8009007C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80090080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090084: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090088: jr          $ra
    // 0x8009008C: nop

    return;
    // 0x8009008C: nop

;}
RECOMP_FUNC void mulscale26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80090018: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009001C: jal         0x800BB8F8
    // 0x80090020: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80090020: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090028: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8009002C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80090030: jal         0x800BBA24
    // 0x80090034: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x80090034: addiu       $a3, $zero, 0x1A
    ctx->r7 = ADD32(0, 0X1A);
    after_1:
    // 0x80090038: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8009003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090040: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090044: jr          $ra
    // 0x80090048: nop

    return;
    // 0x80090048: nop

;}
RECOMP_FUNC void gettileid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006370C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80063710: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80063714: bne         $t6, $zero, L_80063724
    if (ctx->r14 != 0) {
        // 0x80063718: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80063724;
    }
    // 0x80063718: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8006371C: jr          $ra
    // 0x80063720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80063720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063724:
    // 0x80063724: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80063728: lui         $v1, 0x8026
    ctx->r3 = S32(0X8026 << 16);
    // 0x8006372C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80063730: lhu         $v1, -0x3C68($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X3C68);
    // 0x80063734: addiu       $at, $zero, 0x1800
    ctx->r1 = ADD32(0, 0X1800);
    // 0x80063738: bne         $v1, $at, L_80063748
    if (ctx->r3 != ctx->r1) {
        // 0x8006373C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80063748;
    }
    // 0x8006373C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80063740: jr          $ra
    // 0x80063744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80063744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80063748:
    // 0x80063748: jr          $ra
    // 0x8006374C: nop

    return;
    // 0x8006374C: nop

;}
RECOMP_FUNC void quickkill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1718: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A171C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A1720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A1724: lh          $t6, 0x2E0($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X2E0));
    // 0x800A1728: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800A172C: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800A1730: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A1734: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800A1738: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A173C: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x800A1740: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x800A1744: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800A1748: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800A174C: mflo        $t7
    ctx->r15 = lo;
    // 0x800A1750: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x800A1754: lh          $t8, 0x22($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X22));
    // 0x800A1758: blezl       $t8, L_800A17F0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800A175C: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_800A17F0;
    }
    goto skip_0;
    // 0x800A175C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_0:
    // 0x800A1760: sb          $v1, 0x367($a0)
    MEM_B(0X367, ctx->r4) = ctx->r3;
    // 0x800A1764: sb          $v1, 0x368($a0)
    MEM_B(0X368, ctx->r4) = ctx->r3;
    // 0x800A1768: sb          $v1, 0x369($a0)
    MEM_B(0X369, ctx->r4) = ctx->r3;
    // 0x800A176C: sw          $t9, 0x274($a0)
    MEM_W(0X274, ctx->r4) = ctx->r25;
    // 0x800A1770: jal         0x8005194C
    // 0x800A1774: lbu         $a0, 0x1B($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1B);
    controllersetvib(rdram, ctx);
        goto after_0;
    // 0x800A1774: lbu         $a0, 0x1B($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1B);
    after_0:
    // 0x800A1778: lh          $t2, 0x2E0($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A177C: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800A1780: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800A1784: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A1788: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800A178C: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800A1790: mflo        $t3
    ctx->r11 = lo;
    // 0x800A1794: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800A1798: sh          $zero, 0x22($t4)
    MEM_H(0X22, ctx->r12) = 0;
    // 0x800A179C: lh          $t5, 0x2E0($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A17A0: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A17A4: mflo        $t6
    ctx->r14 = lo;
    // 0x800A17A8: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x800A17AC: lh          $t7, 0xC($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0XC));
    // 0x800A17B0: ori         $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 | 0X8000;
    // 0x800A17B4: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    // 0x800A17B8: lbu         $t9, -0x5598($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X5598);
    // 0x800A17BC: bnel        $t9, $zero, L_800A17F0
    if (ctx->r25 != 0) {
        // 0x800A17C0: lw          $ra, 0x1C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
            goto L_800A17F0;
    }
    goto skip_1;
    // 0x800A17C0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    skip_1:
    // 0x800A17C4: lh          $t2, 0x2E0($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800A17C8: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x800A17CC: lh          $a3, -0x9D8($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X9D8));
    // 0x800A17D0: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A17D4: addiu       $a1, $zero, 0x8EE
    ctx->r5 = ADD32(0, 0X8EE);
    // 0x800A17D8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800A17DC: mflo        $t3
    ctx->r11 = lo;
    // 0x800A17E0: addu        $a0, $t0, $t3
    ctx->r4 = ADD32(ctx->r8, ctx->r11);
    // 0x800A17E4: jal         0x80076664
    // 0x800A17E8: nop

    guts(rdram, ctx);
        goto after_1;
    // 0x800A17E8: nop

    after_1:
    // 0x800A17EC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_800A17F0:
    // 0x800A17F0: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800A17F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A17F8: jr          $ra
    // 0x800A17FC: nop

    return;
    // 0x800A17FC: nop

;}
RECOMP_FUNC void func_80057E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057E98: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057E9C: jal         0x800C18B0
    // 0x80057EA0: lw          $a0, 0x4D58($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D58));
    alCSPStop(rdram, ctx);
        goto after_0;
    // 0x80057EA0: lw          $a0, 0x4D58($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D58));
    after_0:
    // 0x80057EA4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80057EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057EAC: jr          $ra
    // 0x80057EB0: nop

    return;
    // 0x80057EB0: nop

;}
RECOMP_FUNC void ssp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80076194: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80076198: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007619C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800761A0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800761A4: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800761A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800761AC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800761B0: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x800761B4: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x800761B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800761BC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800761C0: lh          $v1, 0x14($v0)
    ctx->r3 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800761C4: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x800761C8: addiu       $t1, $t1, -0x9A0
    ctx->r9 = ADD32(ctx->r9, -0X9A0);
    // 0x800761CC: addiu       $t2, $v1, 0x200
    ctx->r10 = ADD32(ctx->r3, 0X200);
    // 0x800761D0: andi        $t3, $t2, 0x7FF
    ctx->r11 = ctx->r10 & 0X7FF;
    // 0x800761D4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800761D8: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800761DC: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800761E0: lh          $t0, 0x18($v0)
    ctx->r8 = S32(MEM_H(ctx->r2, 0X18));
    // 0x800761E4: andi        $t8, $v1, 0x7FF
    ctx->r24 = ctx->r3 & 0X7FF;
    // 0x800761E8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800761EC: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800761F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800761F4: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800761F8: lh          $t3, 0x0($t2)
    ctx->r11 = S32(MEM_H(ctx->r10, 0X0));
    // 0x800761FC: lw          $t5, 0x24($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80076200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80076204: lh          $a3, 0x1C($v0)
    ctx->r7 = S32(MEM_H(ctx->r2, 0X1C));
    // 0x80076208: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8007620C: mflo        $a1
    ctx->r5 = lo;
    // 0x80076210: sra         $t7, $a1, 14
    ctx->r15 = S32(SIGNED(ctx->r5) >> 14);
    // 0x80076214: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80076218: multu       $t3, $t0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007621C: mflo        $a2
    ctx->r6 = lo;
    // 0x80076220: sra         $t4, $a2, 14
    ctx->r12 = S32(SIGNED(ctx->r6) >> 14);
    // 0x80076224: jal         0x80075C50
    // 0x80076228: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    movesprite(rdram, ctx);
        goto after_0;
    // 0x80076228: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_0:
    // 0x8007622C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80076230: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076234: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80076238: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8007623C: jr          $ra
    // 0x80076240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80076240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void alBnkfNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0244: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C0248: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C024C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C0250: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C0254: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C0258: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C025C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C0260: lh          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_H(ctx->r4, 0X0));
    // 0x800C0264: addiu       $at, $zero, 0x4231
    ctx->r1 = ADD32(0, 0X4231);
    // 0x800C0268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C026C: bne         $t6, $at, L_800C0328
    if (ctx->r14 != ctx->r1) {
        // 0x800C0270: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_800C0328;
    }
    // 0x800C0270: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C0274: lh          $t7, 0x2($a0)
    ctx->r15 = S32(MEM_H(ctx->r4, 0X2));
    // 0x800C0278: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800C027C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C0280: blez        $t7, L_800C0328
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C0284: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800C0328;
    }
    // 0x800C0284: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800C0288: lw          $t8, 0x4($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X4));
L_800C028C:
    // 0x800C028C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800C0290: beq         $t9, $zero, L_800C0310
    if (ctx->r25 == 0) {
        // 0x800C0294: sw          $t9, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r25;
            goto L_800C0310;
    }
    // 0x800C0294: sw          $t9, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r25;
    // 0x800C0298: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800C029C: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800C02A0: bnel        $t6, $zero, L_800C0314
    if (ctx->r14 != 0) {
        // 0x800C02A4: lh          $t8, 0x2($s0)
        ctx->r24 = S32(MEM_H(ctx->r16, 0X2));
            goto L_800C0314;
    }
    goto skip_0;
    // 0x800C02A4: lh          $t8, 0x2($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2));
    skip_0:
    // 0x800C02A8: lw          $v0, 0x8($t9)
    ctx->r2 = S32(MEM_W(ctx->r25, 0X8));
    // 0x800C02AC: sb          $s4, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r20;
    // 0x800C02B0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800C02B4: beq         $v0, $zero, L_800C02CC
    if (ctx->r2 == 0) {
        // 0x800C02B8: addu        $a0, $v0, $s0
        ctx->r4 = ADD32(ctx->r2, ctx->r16);
            goto L_800C02CC;
    }
    // 0x800C02B8: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x800C02BC: sw          $a0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r4;
    // 0x800C02C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C02C4: jal         0x800C0150
    // 0x800C02C8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_5_800C0150(rdram, ctx);
        goto after_0;
    // 0x800C02C8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_0:
L_800C02CC:
    // 0x800C02CC: lh          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800C02D0: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C02D4: blezl       $t8, L_800C0314
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800C02D8: lh          $t8, 0x2($s0)
        ctx->r24 = S32(MEM_H(ctx->r16, 0X2));
            goto L_800C0314;
    }
    goto skip_1;
    // 0x800C02D8: lh          $t8, 0x2($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2));
    skip_1:
    // 0x800C02DC: lw          $t9, 0xC($t3)
    ctx->r25 = S32(MEM_W(ctx->r11, 0XC));
L_800C02E0:
    // 0x800C02E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C02E4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x800C02E8: beq         $a0, $zero, L_800C02F8
    if (ctx->r4 == 0) {
        // 0x800C02EC: sw          $a0, 0xC($t3)
        MEM_W(0XC, ctx->r11) = ctx->r4;
            goto L_800C02F8;
    }
    // 0x800C02EC: sw          $a0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r4;
    // 0x800C02F0: jal         0x800C0150
    // 0x800C02F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    static_5_800C0150(rdram, ctx);
        goto after_1;
    // 0x800C02F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
L_800C02F8:
    // 0x800C02F8: lh          $t7, 0x0($t5)
    ctx->r15 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800C02FC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C0300: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C0304: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C0308: bnel        $at, $zero, L_800C02E0
    if (ctx->r1 != 0) {
        // 0x800C030C: lw          $t9, 0xC($t3)
        ctx->r25 = S32(MEM_W(ctx->r11, 0XC));
            goto L_800C02E0;
    }
    goto skip_2;
    // 0x800C030C: lw          $t9, 0xC($t3)
    ctx->r25 = S32(MEM_W(ctx->r11, 0XC));
    skip_2:
L_800C0310:
    // 0x800C0310: lh          $t8, 0x2($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2));
L_800C0314:
    // 0x800C0314: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800C0318: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C031C: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C0320: bnel        $at, $zero, L_800C028C
    if (ctx->r1 != 0) {
        // 0x800C0324: lw          $t8, 0x4($s2)
        ctx->r24 = S32(MEM_W(ctx->r18, 0X4));
            goto L_800C028C;
    }
    goto skip_3;
    // 0x800C0324: lw          $t8, 0x4($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X4));
    skip_3:
L_800C0328:
    // 0x800C0328: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800C032C: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800C0330: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C0334: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C0338: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C033C: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800C0340: jr          $ra
    // 0x800C0344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C0344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1330: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800D1334: mflo        $v0
    ctx->r2 = lo;
    // 0x800D1338: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800D133C: bne         $a2, $zero, L_800D1348
    if (ctx->r6 != 0) {
        // 0x800D1340: nop
    
            goto L_800D1348;
    }
    // 0x800D1340: nop

    // 0x800D1344: break       7
    do_break(2148340548);
L_800D1348:
    // 0x800D1348: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D134C: bne         $a2, $at, L_800D1360
    if (ctx->r6 != ctx->r1) {
        // 0x800D1350: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D1360;
    }
    // 0x800D1350: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D1354: bne         $a1, $at, L_800D1360
    if (ctx->r5 != ctx->r1) {
        // 0x800D1358: nop
    
            goto L_800D1360;
    }
    // 0x800D1358: nop

    // 0x800D135C: break       6
    do_break(2148340572);
L_800D1360:
    // 0x800D1360: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1364: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800D1368: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x800D136C: mflo        $t6
    ctx->r14 = lo;
    // 0x800D1370: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x800D1374: bgez        $v0, L_800D1398
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D1378: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800D1398;
    }
    // 0x800D1378: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D137C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800D1380: blez        $v1, L_800D1398
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D1384: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800D1398;
    }
    // 0x800D1384: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D1388: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D138C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800D1390: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800D1394: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_800D1398:
    // 0x800D1398: lw          $at, 0x0($t7)
    ctx->r1 = S32(MEM_W(ctx->r15, 0X0));
    // 0x800D139C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D13A0: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x800D13A4: lw          $t0, 0x4($t7)
    ctx->r8 = S32(MEM_W(ctx->r15, 0X4));
    // 0x800D13A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800D13AC: jr          $ra
    // 0x800D13B0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x800D13B0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void __unmapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA940: lw          $v1, 0x64($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X64));
    // 0x800CA944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA948: addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
    // 0x800CA94C: beq         $v1, $zero, L_800CA9A8
    if (ctx->r3 == 0) {
        // 0x800CA950: nop
    
            goto L_800CA9A8;
    }
    // 0x800CA950: nop

L_800CA954:
    // 0x800CA954: bnel        $v1, $a2, L_800CA99C
    if (ctx->r3 != ctx->r6) {
        // 0x800CA958: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800CA99C;
    }
    goto skip_0;
    // 0x800CA958: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x800CA95C: beql        $v0, $zero, L_800CA974
    if (ctx->r2 == 0) {
        // 0x800CA960: lw          $t7, 0x0($v1)
        ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
            goto L_800CA974;
    }
    goto skip_1;
    // 0x800CA960: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
    skip_1:
    // 0x800CA964: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800CA968: b           L_800CA978
    // 0x800CA96C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_800CA978;
    // 0x800CA96C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800CA970: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
L_800CA974:
    // 0x800CA974: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
L_800CA978:
    // 0x800CA978: lw          $t8, 0x68($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X68));
    // 0x800CA97C: bnel        $v1, $t8, L_800CA98C
    if (ctx->r3 != ctx->r24) {
        // 0x800CA980: lw          $t9, 0x6C($a0)
        ctx->r25 = S32(MEM_W(ctx->r4, 0X6C));
            goto L_800CA98C;
    }
    goto skip_2;
    // 0x800CA980: lw          $t9, 0x6C($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X6C));
    skip_2:
    // 0x800CA984: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
    // 0x800CA988: lw          $t9, 0x6C($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X6C));
L_800CA98C:
    // 0x800CA98C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800CA990: jr          $ra
    // 0x800CA994: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    return;
    // 0x800CA994: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x800CA998: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800CA99C:
    // 0x800CA99C: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800CA9A0: bne         $v1, $zero, L_800CA954
    if (ctx->r3 != 0) {
        // 0x800CA9A4: nop
    
            goto L_800CA954;
    }
    // 0x800CA9A4: nop

L_800CA9A8:
    // 0x800CA9A8: jr          $ra
    // 0x800CA9AC: nop

    return;
    // 0x800CA9AC: nop

;}
RECOMP_FUNC void alCSeqGetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C18E0: lw          $t6, 0x4($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800C18E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C18E8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C18EC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800C18F0: lw          $t7, 0xC($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0XC));
    // 0x800C18F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C18F8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C18FC: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800C1900: lw          $t8, 0x10($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X10));
    // 0x800C1904: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800C1908: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C190C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
L_800C1910:
    // 0x800C1910: lw          $t9, 0x18($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X18));
    // 0x800C1914: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C1918: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C191C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800C1920: lw          $t1, 0x58($a2)
    ctx->r9 = S32(MEM_W(ctx->r6, 0X58));
    // 0x800C1924: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800C1928: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800C192C: sw          $t1, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r9;
    // 0x800C1930: lbu         $t2, 0x98($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X98);
    // 0x800C1934: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C1938: sb          $t2, 0x8A($a3)
    MEM_B(0X8A, ctx->r7) = ctx->r10;
    // 0x800C193C: lbu         $t3, 0xA6($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA6);
    // 0x800C1940: sb          $t3, 0x9A($a3)
    MEM_B(0X9A, ctx->r7) = ctx->r11;
    // 0x800C1944: lw          $t4, 0xB0($a2)
    ctx->r12 = S32(MEM_W(ctx->r6, 0XB0));
    // 0x800C1948: sw          $t4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r12;
    // 0x800C194C: lw          $t5, 0x14($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X14));
    // 0x800C1950: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x800C1954: lw          $t6, 0x54($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X54));
    // 0x800C1958: sw          $t6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r14;
    // 0x800C195C: lbu         $t7, 0x97($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X97);
    // 0x800C1960: sb          $t7, 0x8B($a3)
    MEM_B(0X8B, ctx->r7) = ctx->r15;
    // 0x800C1964: lbu         $t8, 0xA7($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XA7);
    // 0x800C1968: sb          $t8, 0x9B($a3)
    MEM_B(0X9B, ctx->r7) = ctx->r24;
    // 0x800C196C: lw          $t9, 0xB4($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0XB4));
    // 0x800C1970: bne         $v0, $a0, L_800C1910
    if (ctx->r2 != ctx->r4) {
        // 0x800C1974: sw          $t9, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->r25;
            goto L_800C1910;
    }
    // 0x800C1974: sw          $t9, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r25;
    // 0x800C1978: jr          $ra
    // 0x800C197C: nop

    return;
    // 0x800C197C: nop

;}
RECOMP_FUNC void isanearoperator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDC4: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800ACDC8: addiu       $t9, $t8, -0x9
    ctx->r25 = ADD32(ctx->r24, -0X9);
    // 0x800ACDCC: sltiu       $at, $t9, 0x15
    ctx->r1 = ctx->r25 < 0X15 ? 1 : 0;
    // 0x800ACDD0: beq         $at, $zero, L_800ACDF8
    if (ctx->r1 == 0) {
        // 0x800ACDD4: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800ACDF8;
    }
    // 0x800ACDD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800ACDD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800ACDDC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800ACDE0: addu        $at, $at, $t9
    gpr jr_addend_800ACDE8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800ACDE4: lw          $t9, -0x79F8($at)
    ctx->r25 = ADD32(ctx->r1, -0X79F8);
    // 0x800ACDE8: jr          $t9
    // 0x800ACDEC: nop

    switch (jr_addend_800ACDE8 >> 2) {
        case 0: goto L_800ACDF0; break;
        case 1: goto L_800ACDF8; break;
        case 2: goto L_800ACDF8; break;
        case 3: goto L_800ACDF8; break;
        case 4: goto L_800ACDF8; break;
        case 5: goto L_800ACDF8; break;
        case 6: goto L_800ACDF0; break;
        case 7: goto L_800ACDF0; break;
        case 8: goto L_800ACDF0; break;
        case 9: goto L_800ACDF0; break;
        case 10: goto L_800ACDF0; break;
        case 11: goto L_800ACDF0; break;
        case 12: goto L_800ACDF0; break;
        case 13: goto L_800ACDF0; break;
        case 14: goto L_800ACDF0; break;
        case 15: goto L_800ACDF8; break;
        case 16: goto L_800ACDF0; break;
        case 17: goto L_800ACDF0; break;
        case 18: goto L_800ACDF8; break;
        case 19: goto L_800ACDF8; break;
        case 20: goto L_800ACDF0; break;
        default: switch_error(__func__, 0x800ACDE8, 0x80108608);
    }
    // 0x800ACDEC: nop

L_800ACDF0:
    // 0x800ACDF0: jr          $ra
    // 0x800ACDF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800ACDF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ACDF8:
    // 0x800ACDF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ACDFC: jr          $ra
    // 0x800ACE00: nop

    return;
    // 0x800ACE00: nop

;}
RECOMP_FUNC void __lookupSoundQuick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAC30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800CAC34: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800CAC38: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800CAC3C: lw          $t8, 0x60($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CAC40: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x800CAC44: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800CAC48: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x800CAC4C: lw          $v0, 0x0($t4)
    ctx->r2 = S32(MEM_W(ctx->r12, 0X0));
    // 0x800CAC50: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800CAC54: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x800CAC58: lh          $t0, 0xE($v0)
    ctx->r8 = S32(MEM_H(ctx->r2, 0XE));
    // 0x800CAC5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800CAC60: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x800CAC64: blez        $t0, L_800CAD20
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800CAC68: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_800CAD20;
    }
    // 0x800CAC68: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
L_800CAC6C:
    // 0x800CAC6C: bgez        $a1, L_800CAC7C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800CAC70: sra         $t5, $a1, 1
        ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800CAC7C;
    }
    // 0x800CAC70: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800CAC74: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800CAC78: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800CAC7C:
    // 0x800CAC7C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800CAC80: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800CAC84: lw          $a3, 0xC($t7)
    ctx->r7 = S32(MEM_W(ctx->r15, 0XC));
    // 0x800CAC88: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800CAC8C: lw          $a2, 0x4($a3)
    ctx->r6 = S32(MEM_W(ctx->r7, 0X4));
    // 0x800CAC90: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x800CAC94: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800CAC98: bnel        $at, $zero, L_800CACE0
    if (ctx->r1 != 0) {
        // 0x800CAC9C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800CACE0;
    }
    goto skip_0;
    // 0x800CAC9C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_0:
    // 0x800CACA0: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x800CACA4: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CACA8: bnel        $at, $zero, L_800CACE0
    if (ctx->r1 != 0) {
        // 0x800CACAC: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800CACE0;
    }
    goto skip_1;
    // 0x800CACAC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_1:
    // 0x800CACB0: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800CACB4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800CACB8: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800CACBC: bnel        $at, $zero, L_800CACE0
    if (ctx->r1 != 0) {
        // 0x800CACC0: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800CACE0;
    }
    goto skip_2;
    // 0x800CACC0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_2:
    // 0x800CACC4: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x800CACC8: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CACCC: bnel        $at, $zero, L_800CACE0
    if (ctx->r1 != 0) {
        // 0x800CACD0: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800CACE0;
    }
    goto skip_3;
    // 0x800CACD0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x800CACD4: jr          $ra
    // 0x800CACD8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CACD8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800CACDC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_800CACE0:
    // 0x800CACE0: bne         $at, $zero, L_800CAD08
    if (ctx->r1 != 0) {
        // 0x800CACE4: nop
    
            goto L_800CAD08;
    }
    // 0x800CACE4: nop

    // 0x800CACE8: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800CACEC: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800CACF0: beql        $at, $zero, L_800CAD14
    if (ctx->r1 == 0) {
        // 0x800CACF4: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_800CAD14;
    }
    goto skip_4;
    // 0x800CACF4: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x800CACF8: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x800CACFC: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CAD00: bnel        $at, $zero, L_800CAD14
    if (ctx->r1 != 0) {
        // 0x800CAD04: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_800CAD14;
    }
    goto skip_5;
    // 0x800CAD04: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    skip_5:
L_800CAD08:
    // 0x800CAD08: b           L_800CAD14
    // 0x800CAD0C: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
        goto L_800CAD14;
    // 0x800CAD0C: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x800CAD10: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_800CAD14:
    // 0x800CAD14: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800CAD18: beql        $at, $zero, L_800CAC6C
    if (ctx->r1 == 0) {
        // 0x800CAD1C: addu        $a1, $v1, $t0
        ctx->r5 = ADD32(ctx->r3, ctx->r8);
            goto L_800CAC6C;
    }
    goto skip_6;
    // 0x800CAD1C: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    skip_6:
L_800CAD20:
    // 0x800CAD20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CAD24: jr          $ra
    // 0x800CAD28: nop

    return;
    // 0x800CAD28: nop

;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8C78: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C8C7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C8C80: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C8C84: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800C8C88: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800C8C8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C8C90: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C8C94: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C8C98: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800C8C9C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800C8CA0:
    // 0x800C8CA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C8CA4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800C8CA8:
    // 0x800C8CA8: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800C8CAC: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800C8CB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C8CB4: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x800C8CB8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800C8CBC: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x800C8CC0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800C8CC4: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800C8CC8: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800C8CCC: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800C8CD0: lw          $a1, 0x4($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X4));
    // 0x800C8CD4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800C8CD8: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800C8CDC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800C8CE0: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x800C8CE4: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x800C8CE8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C8CEC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800C8CF0: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x800C8CF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C8CF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C8CFC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C8D00: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800C8D04: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800C8D08: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C8D0C: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x800C8D10: bne         $a0, $t3, L_800C8CA8
    if (ctx->r4 != ctx->r11) {
        // 0x800C8D14: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_800C8CA8;
    }
    // 0x800C8D14: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x800C8D18: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C8D1C: bne         $a2, $t4, L_800C8CA0
    if (ctx->r6 != ctx->r12) {
        // 0x800C8D20: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800C8CA0;
    }
    // 0x800C8D20: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800C8D24: jr          $ra
    // 0x800C8D28: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C8D28: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void display_loadgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053C20: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x80053C24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80053C28: jal         0x800524F0
    // 0x80053C2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_800524F0(rdram, ctx);
        goto after_0;
    // 0x80053C2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80053C30: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x80053C34: lb          $t6, -0x46DE($t6)
    ctx->r14 = S32(MEM_B(ctx->r14, -0X46DE));
    // 0x80053C38: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80053C3C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80053C40: beq         $t6, $zero, L_80053C68
    if (ctx->r14 == 0) {
        // 0x80053C44: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80053C68;
    }
    // 0x80053C44: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80053C48: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053C4C: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80053C50: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80053C54: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80053C58: jal         0x8006E994
    // 0x80053C5C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    setrotatespriteflags(rdram, ctx);
        goto after_1;
    // 0x80053C5C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_1:
    // 0x80053C60: b           L_80053C70
    // 0x80053C64: nop

        goto L_80053C70;
    // 0x80053C64: nop

L_80053C68:
    // 0x80053C68: jal         0x8006E994
    // 0x80053C6C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    setrotatespriteflags(rdram, ctx);
        goto after_2;
    // 0x80053C6C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
L_80053C70:
    // 0x80053C70: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x80053C74: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x80053C78: lbu         $t8, -0x4366($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4366);
    // 0x80053C7C: lbu         $t7, -0x4365($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4365);
    // 0x80053C80: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80053C84: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80053C88: bne         $t7, $t8, L_80053CBC
    if (ctx->r15 != ctx->r24) {
        // 0x80053C8C: nop
    
            goto L_80053CBC;
    }
    // 0x80053C8C: nop

    // 0x80053C90: lbu         $t9, 0x3924($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X3924);
    // 0x80053C94: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053C98: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x80053C9C: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80053CA0: addiu       $t1, $t0, -0x100
    ctx->r9 = ADD32(ctx->r8, -0X100);
    // 0x80053CA4: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80053CA8: mflo        $t2
    ctx->r10 = lo;
    // 0x80053CAC: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x80053CB0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80053CB4: b           L_80053CDC
    // 0x80053CB8: sh          $t4, -0x46E0($at)
    MEM_H(-0X46E0, ctx->r1) = ctx->r12;
        goto L_80053CDC;
    // 0x80053CB8: sh          $t4, -0x46E0($at)
    MEM_H(-0X46E0, ctx->r1) = ctx->r12;
L_80053CBC:
    // 0x80053CBC: lbu         $t5, 0x3924($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3924);
    // 0x80053CC0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80053CC4: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80053CC8: addiu       $t7, $t6, -0x100
    ctx->r15 = ADD32(ctx->r14, -0X100);
    // 0x80053CCC: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80053CD0: mflo        $t8
    ctx->r24 = lo;
    // 0x80053CD4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80053CD8: sh          $t8, -0x46E0($at)
    MEM_H(-0X46E0, ctx->r1) = ctx->r24;
L_80053CDC:
    // 0x80053CDC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80053CE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80053CE4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80053CE8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80053CEC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80053CF0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80053CF4: addiu       $t9, $zero, 0xE56
    ctx->r25 = ADD32(0, 0XE56);
    // 0x80053CF8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80053CFC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80053D00: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80053D04: jal         0x8005D13C
    // 0x80053D08: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_3;
    // 0x80053D08: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x80053D0C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80053D10: addiu       $v0, $v0, -0x4365
    ctx->r2 = ADD32(ctx->r2, -0X4365);
    // 0x80053D14: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80053D18: sltiu       $at, $t0, 0x10
    ctx->r1 = ctx->r8 < 0X10 ? 1 : 0;
    // 0x80053D1C: beq         $at, $zero, L_800542E0
    if (ctx->r1 == 0) {
        // 0x80053D20: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_800542E0;
    }
    // 0x80053D20: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80053D24: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80053D28: addu        $at, $at, $t0
    gpr jr_addend_80053D30 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80053D2C: lw          $t0, 0x3FE8($at)
    ctx->r8 = ADD32(ctx->r1, 0X3FE8);
    // 0x80053D30: jr          $t0
    // 0x80053D34: nop

    switch (jr_addend_80053D30 >> 2) {
        case 0: goto L_80053D38; break;
        case 1: goto L_800542E0; break;
        case 2: goto L_80054044; break;
        case 3: goto L_800542E0; break;
        case 4: goto L_800541B0; break;
        case 5: goto L_800542E0; break;
        case 6: goto L_800542E0; break;
        case 7: goto L_80054240; break;
        case 8: goto L_80054280; break;
        case 9: goto L_800542E0; break;
        case 10: goto L_800542E0; break;
        case 11: goto L_80053FA4; break;
        case 12: goto L_80053E1C; break;
        case 13: goto L_80053F88; break;
        case 14: goto L_80053E00; break;
        case 15: goto L_80054028; break;
        default: switch_error(__func__, 0x80053D30, 0x80103FE8);
    }
    // 0x80053D34: nop

L_80053D38:
    // 0x80053D38: jal         0x80052000
    // 0x80053D3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80052000(rdram, ctx);
        goto after_4;
    // 0x80053D3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80053D40: jal         0x8004BD60
    // 0x80053D44: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    updatetime(rdram, ctx);
        goto after_5;
    // 0x80053D44: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_5:
    // 0x80053D48: lw          $a0, 0x34($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80053D4C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80053D50: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80053D54: beq         $a0, $zero, L_80053D78
    if (ctx->r4 == 0) {
        // 0x80053D58: lui         $a3, 0x801D
        ctx->r7 = S32(0X801D << 16);
            goto L_80053D78;
    }
    // 0x80053D58: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053D5C: jal         0x800528AC
    // 0x80053D60: nop

    func_800528AC(rdram, ctx);
        goto after_6;
    // 0x80053D60: nop

    after_6:
    // 0x80053D64: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x80053D68: lbu         $t1, -0x4366($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X4366);
    // 0x80053D6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80053D70: b           L_800547E4
    // 0x80053D74: sb          $t1, -0x4365($at)
    MEM_B(-0X4365, ctx->r1) = ctx->r9;
        goto L_800547E4;
    // 0x80053D74: sb          $t1, -0x4365($at)
    MEM_B(-0X4365, ctx->r1) = ctx->r9;
L_80053D78:
    // 0x80053D78: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80053D7C: jal         0x8006E994
    // 0x80053D80: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    setrotatespriteflags(rdram, ctx);
        goto after_7;
    // 0x80053D80: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    after_7:
    // 0x80053D84: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053D88: addiu       $a2, $a2, 0x3C0C
    ctx->r6 = ADD32(ctx->r6, 0X3C0C);
    // 0x80053D8C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053D90: jal         0x8006413C
    // 0x80053D94: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    menutext(rdram, ctx);
        goto after_8;
    // 0x80053D94: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_8:
    // 0x80053D98: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x80053D9C: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80053DA0: lb          $t2, 0x12A8($t2)
    ctx->r10 = S32(MEM_B(ctx->r10, 0X12A8));
    // 0x80053DA4: lb          $t3, -0x4367($t3)
    ctx->r11 = S32(MEM_B(ctx->r11, -0X4367));
    // 0x80053DA8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80053DAC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80053DB0: bne         $t3, $t2, L_80053DD8
    if (ctx->r11 != ctx->r10) {
        // 0x80053DB4: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80053DD8;
    }
    // 0x80053DB4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80053DB8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053DBC: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80053DC0: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80053DC4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80053DC8: jal         0x8006E994
    // 0x80053DCC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_9;
    // 0x80053DCC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_9:
    // 0x80053DD0: b           L_80053DE4
    // 0x80053DD4: nop

        goto L_80053DE4;
    // 0x80053DD4: nop

L_80053DD8:
    // 0x80053DD8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053DDC: jal         0x8006E994
    // 0x80053DE0: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    setrotatespriteflags(rdram, ctx);
        goto after_10;
    // 0x80053DE0: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    after_10:
L_80053DE4:
    // 0x80053DE4: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053DE8: addiu       $a2, $a2, 0x3C18
    ctx->r6 = ADD32(ctx->r6, 0X3C18);
    // 0x80053DEC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053DF0: jal         0x8006413C
    // 0x80053DF4: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    menutext(rdram, ctx);
        goto after_11;
    // 0x80053DF4: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_11:
    // 0x80053DF8: b           L_800542E4
    // 0x80053DFC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800542E4;
    // 0x80053DFC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80053E00:
    // 0x80053E00: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80053E04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80053E08: sb          $t4, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r12;
    // 0x80053E0C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80053E10: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80053E14: b           L_800542E4
    // 0x80053E18: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800542E4;
    // 0x80053E18: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80053E1C:
    // 0x80053E1C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80053E20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80053E24: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053E28: sb          $s0, -0x4367($at)
    MEM_B(-0X4367, ctx->r1) = ctx->r16;
    // 0x80053E2C: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80053E30: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80053E34: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80053E38: jal         0x8006E994
    // 0x80053E3C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_12;
    // 0x80053E3C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_12:
    // 0x80053E40: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053E44: addiu       $a2, $a2, 0x3C24
    ctx->r6 = ADD32(ctx->r6, 0X3C24);
    // 0x80053E48: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053E4C: jal         0x8006413C
    // 0x80053E50: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    menutext(rdram, ctx);
        goto after_13;
    // 0x80053E50: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_13:
    // 0x80053E54: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053E58: addiu       $a2, $a2, 0x3C34
    ctx->r6 = ADD32(ctx->r6, 0X3C34);
    // 0x80053E5C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053E60: jal         0x8006413C
    // 0x80053E64: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    menutext(rdram, ctx);
        goto after_14;
    // 0x80053E64: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_14:
    // 0x80053E68: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053E6C: addiu       $a2, $a2, 0x3C3C
    ctx->r6 = ADD32(ctx->r6, 0X3C3C);
    // 0x80053E70: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053E74: jal         0x8006413C
    // 0x80053E78: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    menutext(rdram, ctx);
        goto after_15;
    // 0x80053E78: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_15:
    // 0x80053E7C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053E80: addiu       $a2, $a2, 0x3C50
    ctx->r6 = ADD32(ctx->r6, 0X3C50);
    // 0x80053E84: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053E88: jal         0x8006413C
    // 0x80053E8C: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    menutext(rdram, ctx);
        goto after_16;
    // 0x80053E8C: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_16:
    // 0x80053E90: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053E94: addiu       $a2, $a2, 0x3C64
    ctx->r6 = ADD32(ctx->r6, 0X3C64);
    // 0x80053E98: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053E9C: jal         0x8006413C
    // 0x80053EA0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    menutext(rdram, ctx);
        goto after_17;
    // 0x80053EA0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_17:
    // 0x80053EA4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80053EA8: lb          $a2, 0x3748($a2)
    ctx->r6 = S32(MEM_B(ctx->r6, 0X3748));
    // 0x80053EAC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80053EB0: addiu       $a1, $a1, 0x3C74
    ctx->r5 = ADD32(ctx->r5, 0X3C74);
    // 0x80053EB4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80053EB8: jal         0x800BD9E4
    // 0x80053EBC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_18;
    // 0x80053EBC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_18:
    // 0x80053EC0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053EC4: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x80053EC8: jal         0x8006413C
    // 0x80053ECC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    menutext(rdram, ctx);
        goto after_19;
    // 0x80053ECC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_19:
    // 0x80053ED0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80053ED4: lb          $t6, 0x12A8($t6)
    ctx->r14 = S32(MEM_B(ctx->r14, 0X12A8));
    // 0x80053ED8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80053EDC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80053EE0: bne         $t6, $zero, L_80053F08
    if (ctx->r14 != 0) {
        // 0x80053EE4: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80053F08;
    }
    // 0x80053EE4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80053EE8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053EEC: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80053EF0: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80053EF4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80053EF8: jal         0x8006E994
    // 0x80053EFC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_20;
    // 0x80053EFC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_20:
    // 0x80053F00: b           L_80053F14
    // 0x80053F04: nop

        goto L_80053F14;
    // 0x80053F04: nop

L_80053F08:
    // 0x80053F08: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053F0C: jal         0x8006E994
    // 0x80053F10: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    setrotatespriteflags(rdram, ctx);
        goto after_21;
    // 0x80053F10: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    after_21:
L_80053F14:
    // 0x80053F14: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053F18: addiu       $a2, $a2, 0x3C88
    ctx->r6 = ADD32(ctx->r6, 0X3C88);
    // 0x80053F1C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053F20: jal         0x8006413C
    // 0x80053F24: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    menutext(rdram, ctx);
        goto after_22;
    // 0x80053F24: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    after_22:
    // 0x80053F28: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80053F2C: lb          $t7, 0x12A8($t7)
    ctx->r15 = S32(MEM_B(ctx->r15, 0X12A8));
    // 0x80053F30: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80053F34: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80053F38: bne         $s0, $t7, L_80053F60
    if (ctx->r16 != ctx->r15) {
        // 0x80053F3C: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80053F60;
    }
    // 0x80053F3C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80053F40: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053F44: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80053F48: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80053F4C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80053F50: jal         0x8006E994
    // 0x80053F54: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_23;
    // 0x80053F54: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_23:
    // 0x80053F58: b           L_80053F6C
    // 0x80053F5C: nop

        goto L_80053F6C;
    // 0x80053F5C: nop

L_80053F60:
    // 0x80053F60: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053F64: jal         0x8006E994
    // 0x80053F68: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    setrotatespriteflags(rdram, ctx);
        goto after_24;
    // 0x80053F68: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    after_24:
L_80053F6C:
    // 0x80053F6C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053F70: addiu       $a2, $a2, 0x3C8C
    ctx->r6 = ADD32(ctx->r6, 0X3C8C);
    // 0x80053F74: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053F78: jal         0x8006413C
    // 0x80053F7C: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    menutext(rdram, ctx);
        goto after_25;
    // 0x80053F7C: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_25:
    // 0x80053F80: b           L_800542E4
    // 0x80053F84: nop

        goto L_800542E4;
    // 0x80053F84: nop

L_80053F88:
    // 0x80053F88: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x80053F8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80053F90: sb          $t8, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r24;
    // 0x80053F94: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80053F98: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80053F9C: b           L_800542E4
    // 0x80053FA0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800542E4;
    // 0x80053FA0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80053FA4:
    // 0x80053FA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053FA8: sb          $zero, 0x38D0($at)
    MEM_B(0X38D0, ctx->r1) = 0;
    // 0x80053FAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80053FB0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053FB4: sb          $zero, -0x4367($at)
    MEM_B(-0X4367, ctx->r1) = 0;
    // 0x80053FB8: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80053FBC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80053FC0: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80053FC4: jal         0x8006E994
    // 0x80053FC8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_26;
    // 0x80053FC8: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_26:
    // 0x80053FCC: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053FD0: addiu       $a2, $a2, 0x3C98
    ctx->r6 = ADD32(ctx->r6, 0X3C98);
    // 0x80053FD4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053FD8: jal         0x8006413C
    // 0x80053FDC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    menutext(rdram, ctx);
        goto after_27;
    // 0x80053FDC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_27:
    // 0x80053FE0: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80053FE4: addiu       $a2, $a2, 0x3CA8
    ctx->r6 = ADD32(ctx->r6, 0X3CA8);
    // 0x80053FE8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80053FEC: jal         0x8006413C
    // 0x80053FF0: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    menutext(rdram, ctx);
        goto after_28;
    // 0x80053FF0: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_28:
    // 0x80053FF4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80053FF8: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80053FFC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80054000: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80054004: jal         0x8006E994
    // 0x80054008: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_29;
    // 0x80054008: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_29:
    // 0x8005400C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80054010: addiu       $a2, $a2, 0x3CBC
    ctx->r6 = ADD32(ctx->r6, 0X3CBC);
    // 0x80054014: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80054018: jal         0x8006413C
    // 0x8005401C: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    menutext(rdram, ctx);
        goto after_30;
    // 0x8005401C: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_30:
    // 0x80054020: b           L_800542E4
    // 0x80054024: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800542E4;
    // 0x80054024: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80054028:
    // 0x80054028: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8005402C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80054030: sb          $t0, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r8;
    // 0x80054034: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80054038: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8005403C: b           L_800542E4
    // 0x80054040: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800542E4;
    // 0x80054040: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80054044:
    // 0x80054044: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80054048: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005404C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80054050: sb          $s0, -0x4367($at)
    MEM_B(-0X4367, ctx->r1) = ctx->r16;
    // 0x80054054: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80054058: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8005405C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80054060: jal         0x8006E994
    // 0x80054064: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_31;
    // 0x80054064: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_31:
    // 0x80054068: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8005406C: addiu       $a2, $a2, 0x3CC0
    ctx->r6 = ADD32(ctx->r6, 0X3CC0);
    // 0x80054070: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80054074: jal         0x8006413C
    // 0x80054078: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    menutext(rdram, ctx);
        goto after_32;
    // 0x80054078: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_32:
    // 0x8005407C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80054080: addiu       $a2, $a2, 0x3CD0
    ctx->r6 = ADD32(ctx->r6, 0X3CD0);
    // 0x80054084: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80054088: jal         0x8006413C
    // 0x8005408C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    menutext(rdram, ctx);
        goto after_33;
    // 0x8005408C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_33:
    // 0x80054090: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80054094: addiu       $a2, $a2, 0x3CDC
    ctx->r6 = ADD32(ctx->r6, 0X3CDC);
    // 0x80054098: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005409C: jal         0x8006413C
    // 0x800540A0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    menutext(rdram, ctx);
        goto after_34;
    // 0x800540A0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_34:
    // 0x800540A4: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800540A8: addiu       $a2, $a2, 0x3CF0
    ctx->r6 = ADD32(ctx->r6, 0X3CF0);
    // 0x800540AC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800540B0: jal         0x8006413C
    // 0x800540B4: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    menutext(rdram, ctx);
        goto after_35;
    // 0x800540B4: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_35:
    // 0x800540B8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800540BC: addiu       $a2, $a2, 0x3D00
    ctx->r6 = ADD32(ctx->r6, 0X3D00);
    // 0x800540C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800540C4: jal         0x8006413C
    // 0x800540C8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    menutext(rdram, ctx);
        goto after_36;
    // 0x800540C8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_36:
    // 0x800540CC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800540D0: lb          $a2, 0x3748($a2)
    ctx->r6 = S32(MEM_B(ctx->r6, 0X3748));
    // 0x800540D4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800540D8: addiu       $a1, $a1, 0x3D10
    ctx->r5 = ADD32(ctx->r5, 0X3D10);
    // 0x800540DC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800540E0: jal         0x800BD9E4
    // 0x800540E4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_37;
    // 0x800540E4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_37:
    // 0x800540E8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800540EC: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x800540F0: jal         0x8006413C
    // 0x800540F4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    menutext(rdram, ctx);
        goto after_38;
    // 0x800540F4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_38:
    // 0x800540F8: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x800540FC: lb          $t3, 0x12A8($t3)
    ctx->r11 = S32(MEM_B(ctx->r11, 0X12A8));
    // 0x80054100: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80054104: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80054108: bne         $t3, $zero, L_80054130
    if (ctx->r11 != 0) {
        // 0x8005410C: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80054130;
    }
    // 0x8005410C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80054110: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80054114: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80054118: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8005411C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80054120: jal         0x8006E994
    // 0x80054124: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_39;
    // 0x80054124: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_39:
    // 0x80054128: b           L_8005413C
    // 0x8005412C: nop

        goto L_8005413C;
    // 0x8005412C: nop

L_80054130:
    // 0x80054130: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80054134: jal         0x8006E994
    // 0x80054138: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    setrotatespriteflags(rdram, ctx);
        goto after_40;
    // 0x80054138: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    after_40:
L_8005413C:
    // 0x8005413C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80054140: addiu       $a2, $a2, 0x3D24
    ctx->r6 = ADD32(ctx->r6, 0X3D24);
    // 0x80054144: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80054148: jal         0x8006413C
    // 0x8005414C: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    menutext(rdram, ctx);
        goto after_41;
    // 0x8005414C: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    after_41:
    // 0x80054150: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x80054154: lb          $t2, 0x12A8($t2)
    ctx->r10 = S32(MEM_B(ctx->r10, 0X12A8));
    // 0x80054158: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8005415C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80054160: bne         $s0, $t2, L_80054188
    if (ctx->r16 != ctx->r10) {
        // 0x80054164: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80054188;
    }
    // 0x80054164: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80054168: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8005416C: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80054170: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80054174: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80054178: jal         0x8006E994
    // 0x8005417C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_42;
    // 0x8005417C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_42:
    // 0x80054180: b           L_80054194
    // 0x80054184: nop

        goto L_80054194;
    // 0x80054184: nop

L_80054188:
    // 0x80054188: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8005418C: jal         0x8006E994
    // 0x80054190: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    setrotatespriteflags(rdram, ctx);
        goto after_43;
    // 0x80054190: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    after_43:
L_80054194:
    // 0x80054194: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80054198: addiu       $a2, $a2, 0x3D28
    ctx->r6 = ADD32(ctx->r6, 0X3D28);
    // 0x8005419C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800541A0: jal         0x8006413C
    // 0x800541A4: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    menutext(rdram, ctx);
        goto after_44;
    // 0x800541A4: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_44:
    // 0x800541A8: b           L_800542E4
    // 0x800541AC: nop

        goto L_800542E4;
    // 0x800541AC: nop

L_800541B0:
    // 0x800541B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800541B4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x800541B8: sb          $zero, -0x4367($at)
    MEM_B(-0X4367, ctx->r1) = 0;
    // 0x800541BC: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x800541C0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800541C4: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x800541C8: jal         0x8006E994
    // 0x800541CC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_45;
    // 0x800541CC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_45:
    // 0x800541D0: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800541D4: addiu       $a2, $a2, 0x3D34
    ctx->r6 = ADD32(ctx->r6, 0X3D34);
    // 0x800541D8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800541DC: jal         0x8006413C
    // 0x800541E0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    menutext(rdram, ctx);
        goto after_46;
    // 0x800541E0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_46:
    // 0x800541E4: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800541E8: addiu       $a2, $a2, 0x3D3C
    ctx->r6 = ADD32(ctx->r6, 0X3D3C);
    // 0x800541EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800541F0: jal         0x8006413C
    // 0x800541F4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    menutext(rdram, ctx);
        goto after_47;
    // 0x800541F4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_47:
    // 0x800541F8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800541FC: addiu       $a2, $a2, 0x3D4C
    ctx->r6 = ADD32(ctx->r6, 0X3D4C);
    // 0x80054200: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80054204: jal         0x8006413C
    // 0x80054208: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    menutext(rdram, ctx);
        goto after_48;
    // 0x80054208: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_48:
    // 0x8005420C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80054210: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x80054214: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80054218: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8005421C: jal         0x8006E994
    // 0x80054220: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setrotatespriteflags(rdram, ctx);
        goto after_49;
    // 0x80054220: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_49:
    // 0x80054224: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80054228: addiu       $a2, $a2, 0x3D58
    ctx->r6 = ADD32(ctx->r6, 0X3D58);
    // 0x8005422C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80054230: jal         0x8006413C
    // 0x80054234: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    menutext(rdram, ctx);
        goto after_50;
    // 0x80054234: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_50:
    // 0x80054238: b           L_800542E4
    // 0x8005423C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800542E4;
    // 0x8005423C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80054240:
    // 0x80054240: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x80054244: lb          $t4, -0x5380($t4)
    ctx->r12 = S32(MEM_B(ctx->r12, -0X5380));
    // 0x80054248: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8005424C: sb          $zero, 0x12A8($at)
    MEM_B(0X12A8, ctx->r1) = 0;
    // 0x80054250: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054254: sb          $t4, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r12;
    // 0x80054258: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8005425C: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x80054260: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80054264: sh          $t5, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r13;
    // 0x80054268: addiu       $v0, $v0, 0x12B4
    ctx->r2 = ADD32(ctx->r2, 0X12B4);
    // 0x8005426C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80054270: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80054274: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80054278: b           L_800547E4
    // 0x8005427C: sb          $t7, 0x12B0($at)
    MEM_B(0X12B0, ctx->r1) = ctx->r15;
        goto L_800547E4;
    // 0x8005427C: sb          $t7, 0x12B0($at)
    MEM_B(0X12B0, ctx->r1) = ctx->r15;
L_80054280:
    // 0x80054280: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80054284: lh          $t8, 0x3750($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X3750));
    // 0x80054288: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005428C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80054290: sh          $t8, 0x3754($at)
    MEM_H(0X3754, ctx->r1) = ctx->r24;
    // 0x80054294: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x80054298: sh          $zero, -0x54A6($at)
    MEM_H(-0X54A6, ctx->r1) = 0;
    // 0x8005429C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800542A0: sb          $t9, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r25;
    // 0x800542A4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800542A8: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x800542AC: sh          $t0, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r8;
    // 0x800542B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800542B4: sh          $zero, 0x3758($at)
    MEM_H(0X3758, ctx->r1) = 0;
    // 0x800542B8: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800542BC: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800542C0: sb          $t1, 0x5AA8($at)
    MEM_B(0X5AA8, ctx->r1) = ctx->r9;
    // 0x800542C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800542C8: jal         0x800585D4
    // 0x800542CC: sb          $zero, 0x1360($at)
    MEM_B(0X1360, ctx->r1) = 0;
    stopsong(rdram, ctx);
        goto after_51;
    // 0x800542CC: sb          $zero, 0x1360($at)
    MEM_B(0X1360, ctx->r1) = 0;
    after_51:
    // 0x800542D0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800542D4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800542D8: b           L_800547E4
    // 0x800542DC: sh          $s0, 0x12D0($at)
    MEM_H(0X12D0, ctx->r1) = ctx->r16;
        goto L_800547E4;
    // 0x800542DC: sh          $s0, 0x12D0($at)
    MEM_H(0X12D0, ctx->r1) = ctx->r16;
L_800542E0:
    // 0x800542E0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800542E4:
    // 0x800542E4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x800542E8: lh          $a3, -0x46E0($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X46E0));
    // 0x800542EC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800542F0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800542F4: jal         0x8006E994
    // 0x800542F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    setrotatespriteflags(rdram, ctx);
        goto after_52;
    // 0x800542F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_52:
    // 0x800542FC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80054300: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x80054304: lb          $t3, -0x4367($t3)
    ctx->r11 = S32(MEM_B(ctx->r11, -0X4367));
    // 0x80054308: lb          $v0, 0x12A8($v0)
    ctx->r2 = S32(MEM_B(ctx->r2, 0X12A8));
    // 0x8005430C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80054310: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80054314: bne         $t3, $v0, L_8005433C
    if (ctx->r11 != ctx->r2) {
        // 0x80054318: lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
            goto L_8005433C;
    }
    // 0x80054318: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8005431C: jal         0x8005C9BC
    // 0x80054320: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    rotatesprite_simplest(rdram, ctx);
        goto after_53;
    // 0x80054320: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    after_53:
    // 0x80054324: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x80054328: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x8005432C: jal         0x8005C9BC
    // 0x80054330: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    rotatesprite_simplest(rdram, ctx);
        goto after_54;
    // 0x80054330: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    after_54:
    // 0x80054334: b           L_800543A8
    // 0x80054338: nop

        goto L_800543A8;
    // 0x80054338: nop

L_8005433C:
    // 0x8005433C: lbu         $v1, -0x4365($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4365);
    // 0x80054340: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80054344: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80054348: beq         $v1, $at, L_8005435C
    if (ctx->r3 == ctx->r1) {
        // 0x8005434C: addiu       $a1, $zero, 0xB3
        ctx->r5 = ADD32(0, 0XB3);
            goto L_8005435C;
    }
    // 0x8005434C: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    // 0x80054350: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80054354: bne         $v1, $at, L_8005437C
    if (ctx->r3 != ctx->r1) {
        // 0x80054358: addiu       $a2, $zero, 0xC80
        ctx->r6 = ADD32(0, 0XC80);
            goto L_8005437C;
    }
    // 0x80054358: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
L_8005435C:
    // 0x8005435C: jal         0x8005C9BC
    // 0x80054360: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    rotatesprite_simplest(rdram, ctx);
        goto after_55;
    // 0x80054360: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    after_55:
    // 0x80054364: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x80054368: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    // 0x8005436C: jal         0x8005C9BC
    // 0x80054370: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    rotatesprite_simplest(rdram, ctx);
        goto after_56;
    // 0x80054370: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    after_56:
    // 0x80054374: b           L_800543A8
    // 0x80054378: nop

        goto L_800543A8;
    // 0x80054378: nop

L_8005437C:
    // 0x8005437C: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x80054380: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    // 0x80054384: jal         0x8005C9BC
    // 0x80054388: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    rotatesprite_simplest(rdram, ctx);
        goto after_57;
    // 0x80054388: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_57:
    // 0x8005438C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80054390: lb          $a1, 0x12A8($a1)
    ctx->r5 = S32(MEM_B(ctx->r5, 0X12A8));
    // 0x80054394: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x80054398: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    // 0x8005439C: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x800543A0: jal         0x8005C9BC
    // 0x800543A4: addiu       $a1, $t2, 0x34
    ctx->r5 = ADD32(ctx->r10, 0X34);
    rotatesprite_simplest(rdram, ctx);
        goto after_58;
    // 0x800543A4: addiu       $a1, $t2, 0x34
    ctx->r5 = ADD32(ctx->r10, 0X34);
    after_58:
L_800543A8:
    // 0x800543A8: jal         0x800B76A0
    // 0x800543AC: nop

    func_800B76A0(rdram, ctx);
        goto after_59;
    // 0x800543AC: nop

    after_59:
    // 0x800543B0: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x800543B4: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x800543B8: lbu         $t5, -0x4366($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4366);
    // 0x800543BC: lbu         $t4, -0x4365($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X4365);
    // 0x800543C0: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x800543C4: addiu       $v1, $v1, -0x53B4
    ctx->r3 = ADD32(ctx->r3, -0X53B4);
    // 0x800543C8: beq         $t4, $t5, L_800543DC
    if (ctx->r12 == ctx->r13) {
        // 0x800543CC: lui         $v0, 0x8028
        ctx->r2 = S32(0X8028 << 16);
            goto L_800543DC;
    }
    // 0x800543CC: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800543D0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800543D4: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800543D8: sh          $zero, -0x5C42($at)
    MEM_H(-0X5C42, ctx->r1) = 0;
L_800543DC:
    // 0x800543DC: lhu         $v0, -0x5C42($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5C42);
    // 0x800543E0: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x800543E4: addiu       $v1, $v1, -0x53B4
    ctx->r3 = ADD32(ctx->r3, -0X53B4);
    // 0x800543E8: andi        $t7, $v0, 0x404
    ctx->r15 = ctx->r2 & 0X404;
    // 0x800543EC: bne         $t7, $zero, L_80054400
    if (ctx->r15 != 0) {
        // 0x800543F0: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_80054400;
    }
    // 0x800543F0: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x800543F4: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800543F8: bgez        $t8, L_80054444
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800543FC: nop
    
            goto L_80054444;
    }
    // 0x800543FC: nop

L_80054400:
    // 0x80054400: lb          $t9, -0x4367($t9)
    ctx->r25 = S32(MEM_B(ctx->r25, -0X4367));
    // 0x80054404: beq         $t9, $zero, L_80054424
    if (ctx->r25 == 0) {
        // 0x80054408: nop
    
            goto L_80054424;
    }
    // 0x80054408: nop

    // 0x8005440C: jal         0x80058E1C
    // 0x80054410: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound(rdram, ctx);
        goto after_60;
    // 0x80054410: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_60:
    // 0x80054414: lui         $v1, 0x802B
    ctx->r3 = S32(0X802B << 16);
    // 0x80054418: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x8005441C: lhu         $v0, -0x5C42($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5C42);
    // 0x80054420: addiu       $v1, $v1, -0x53B4
    ctx->r3 = ADD32(ctx->r3, -0X53B4);
L_80054424:
    // 0x80054424: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80054428: addiu       $a1, $a1, 0x12A8
    ctx->r5 = ADD32(ctx->r5, 0X12A8);
    // 0x8005442C: lb          $t0, 0x0($a1)
    ctx->r8 = S32(MEM_B(ctx->r5, 0X0));
    // 0x80054430: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80054434: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80054438: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005443C: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    // 0x80054440: sh          $t3, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r11;
L_80054444:
    // 0x80054444: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80054448: andi        $t2, $v0, 0x808
    ctx->r10 = ctx->r2 & 0X808;
    // 0x8005444C: bne         $t2, $zero, L_8005445C
    if (ctx->r10 != 0) {
        // 0x80054450: addiu       $a1, $a1, 0x12A8
        ctx->r5 = ADD32(ctx->r5, 0X12A8);
            goto L_8005445C;
    }
    // 0x80054450: addiu       $a1, $a1, 0x12A8
    ctx->r5 = ADD32(ctx->r5, 0X12A8);
    // 0x80054454: lw          $t4, 0x0($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80054458: blez        $t4, L_8005449C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8005445C: lui         $t5, 0x801D
        ctx->r13 = S32(0X801D << 16);
            goto L_8005449C;
    }
L_8005445C:
    // 0x8005445C: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x80054460: lb          $t5, -0x4367($t5)
    ctx->r13 = S32(MEM_B(ctx->r13, -0X4367));
    // 0x80054464: beql        $t5, $zero, L_80054488
    if (ctx->r13 == 0) {
        // 0x80054468: lb          $t6, 0x0($a1)
        ctx->r14 = S32(MEM_B(ctx->r5, 0X0));
            goto L_80054488;
    }
    goto skip_0;
    // 0x80054468: lb          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_B(ctx->r5, 0X0));
    skip_0:
    // 0x8005446C: jal         0x80058E1C
    // 0x80054470: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound(rdram, ctx);
        goto after_61;
    // 0x80054470: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_61:
    // 0x80054474: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x80054478: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8005447C: addiu       $a1, $a1, 0x12A8
    ctx->r5 = ADD32(ctx->r5, 0X12A8);
    // 0x80054480: lhu         $v0, -0x5C42($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X5C42);
    // 0x80054484: lb          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_B(ctx->r5, 0X0));
L_80054488:
    // 0x80054488: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8005448C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80054490: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80054494: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x80054498: sh          $t8, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r24;
L_8005449C:
    // 0x8005449C: andi        $t9, $v0, 0xE000
    ctx->r25 = ctx->r2 & 0XE000;
    // 0x800544A0: beq         $t9, $zero, L_80054768
    if (ctx->r25 == 0) {
        // 0x800544A4: nop
    
            goto L_80054768;
    }
    // 0x800544A4: nop

    // 0x800544A8: jal         0x80058E1C
    // 0x800544AC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    sound(rdram, ctx);
        goto after_62;
    // 0x800544AC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_62:
    // 0x800544B0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x800544B4: lbu         $t0, -0x4365($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X4365);
    // 0x800544B8: sltiu       $at, $t0, 0xD
    ctx->r1 = ctx->r8 < 0XD ? 1 : 0;
    // 0x800544BC: beq         $at, $zero, L_80054768
    if (ctx->r1 == 0) {
        // 0x800544C0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80054768;
    }
    // 0x800544C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800544C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800544C8: addu        $at, $at, $t0
    gpr jr_addend_800544D0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800544CC: lw          $t0, 0x4028($at)
    ctx->r8 = ADD32(ctx->r1, 0X4028);
    // 0x800544D0: jr          $t0
    // 0x800544D4: nop

    switch (jr_addend_800544D0 >> 2) {
        case 0: goto L_800544D8; break;
        case 1: goto L_80054768; break;
        case 2: goto L_8005464C; break;
        case 3: goto L_80054768; break;
        case 4: goto L_800546F0; break;
        case 5: goto L_80054768; break;
        case 6: goto L_80054768; break;
        case 7: goto L_80054768; break;
        case 8: goto L_80054768; break;
        case 9: goto L_80054768; break;
        case 10: goto L_80054768; break;
        case 11: goto L_800545D0; break;
        case 12: goto L_8005464C; break;
        default: switch_error(__func__, 0x800544D0, 0x80104028);
    }
    // 0x800544D4: nop

L_800544D8:
    // 0x800544D8: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x800544DC: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x800544E0: lb          $t3, 0x12A8($t3)
    ctx->r11 = S32(MEM_B(ctx->r11, 0X12A8));
    // 0x800544E4: lb          $t1, -0x4367($t1)
    ctx->r9 = S32(MEM_B(ctx->r9, -0X4367));
    // 0x800544E8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800544EC: addiu       $a0, $a0, 0x3924
    ctx->r4 = ADD32(ctx->r4, 0X3924);
    // 0x800544F0: bne         $t1, $t3, L_8005450C
    if (ctx->r9 != ctx->r11) {
        // 0x800544F4: addiu       $t2, $zero, 0x6
        ctx->r10 = ADD32(0, 0X6);
            goto L_8005450C;
    }
    // 0x800544F4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800544F8: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x800544FC: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80054500: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80054504: b           L_80054768
    // 0x80054508: sb          $t4, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r12;
        goto L_80054768;
    // 0x80054508: sb          $t4, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r12;
L_8005450C:
    // 0x8005450C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80054510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80054514: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80054518: jal         0x800ABE18
    // 0x8005451C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    newgame(rdram, ctx);
        goto after_63;
    // 0x8005451C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_63:
    // 0x80054520: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80054524: addiu       $v0, $v0, 0x38B8
    ctx->r2 = ADD32(ctx->r2, 0X38B8);
    // 0x80054528: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x8005452C: lb          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_B(ctx->r2, 0X0));
    // 0x80054530: bne         $s0, $t5, L_80054554
    if (ctx->r16 != ctx->r13) {
        // 0x80054534: nop
    
            goto L_80054554;
    }
    // 0x80054534: nop

L_80054538:
    // 0x80054538: jal         0x800BDDD0
    // 0x8005453C: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_64;
    // 0x8005453C: nop

    after_64:
    // 0x80054540: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80054544: addiu       $v0, $v0, 0x38B8
    ctx->r2 = ADD32(ctx->r2, 0X38B8);
    // 0x80054548: lb          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_B(ctx->r2, 0X0));
    // 0x8005454C: beq         $s0, $t6, L_80054538
    if (ctx->r16 == ctx->r14) {
        // 0x80054550: nop
    
            goto L_80054538;
    }
    // 0x80054550: nop

L_80054554:
    // 0x80054554: jal         0x8004BD60
    // 0x80054558: nop

    updatetime(rdram, ctx);
        goto after_65;
    // 0x80054558: nop

    after_65:
    // 0x8005455C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80054560: lw          $a0, 0x38BC($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X38BC));
    // 0x80054564: beq         $a0, $zero, L_8005457C
    if (ctx->r4 == 0) {
        // 0x80054568: nop
    
            goto L_8005457C;
    }
    // 0x80054568: nop

    // 0x8005456C: jal         0x800528AC
    // 0x80054570: nop

    func_800528AC(rdram, ctx);
        goto after_66;
    // 0x80054570: nop

    after_66:
    // 0x80054574: b           L_800547E8
    // 0x80054578: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800547E8;
    // 0x80054578: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_8005457C:
    // 0x8005457C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80054580: jal         0x80055598
    // 0x80054584: lb          $a0, 0x12A8($a0)
    ctx->r4 = S32(MEM_B(ctx->r4, 0X12A8));
    func_80055598(rdram, ctx);
        goto after_67;
    // 0x80054584: lb          $a0, 0x12A8($a0)
    ctx->r4 = S32(MEM_B(ctx->r4, 0X12A8));
    after_67:
    // 0x80054588: beq         $v0, $zero, L_800545A0
    if (ctx->r2 == 0) {
        // 0x8005458C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800545A0;
    }
    // 0x8005458C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80054590: jal         0x800528AC
    // 0x80054594: nop

    func_800528AC(rdram, ctx);
        goto after_68;
    // 0x80054594: nop

    after_68:
    // 0x80054598: b           L_80054768
    // 0x8005459C: nop

        goto L_80054768;
    // 0x8005459C: nop

L_800545A0:
    // 0x800545A0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800545A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800545A8: sb          $t7, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r15;
    // 0x800545AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800545B0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x800545B4: sb          $t8, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r24;
    // 0x800545B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800545BC: sb          $s0, -0x46DE($at)
    MEM_B(-0X46DE, ctx->r1) = ctx->r16;
    // 0x800545C0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800545C4: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x800545C8: b           L_80054768
    // 0x800545CC: sh          $t9, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r25;
        goto L_80054768;
    // 0x800545CC: sh          $t9, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r25;
L_800545D0:
    // 0x800545D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800545D4: addiu       $v0, $v0, 0x38B8
    ctx->r2 = ADD32(ctx->r2, 0X38B8);
    // 0x800545D8: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x800545DC: lb          $t0, 0x0($v0)
    ctx->r8 = S32(MEM_B(ctx->r2, 0X0));
    // 0x800545E0: bne         $s0, $t0, L_80054604
    if (ctx->r16 != ctx->r8) {
        // 0x800545E4: nop
    
            goto L_80054604;
    }
    // 0x800545E4: nop

L_800545E8:
    // 0x800545E8: jal         0x800BDDD0
    // 0x800545EC: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_69;
    // 0x800545EC: nop

    after_69:
    // 0x800545F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800545F4: addiu       $v0, $v0, 0x38B8
    ctx->r2 = ADD32(ctx->r2, 0X38B8);
    // 0x800545F8: lb          $t1, 0x0($v0)
    ctx->r9 = S32(MEM_B(ctx->r2, 0X0));
    // 0x800545FC: beq         $s0, $t1, L_800545E8
    if (ctx->r16 == ctx->r9) {
        // 0x80054600: nop
    
            goto L_800545E8;
    }
    // 0x80054600: nop

L_80054604:
    // 0x80054604: jal         0x8004BD60
    // 0x80054608: nop

    updatetime(rdram, ctx);
        goto after_70;
    // 0x80054608: nop

    after_70:
    // 0x8005460C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80054610: lw          $a0, 0x38BC($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X38BC));
    // 0x80054614: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80054618: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8005461C: beq         $a0, $zero, L_80054634
    if (ctx->r4 == 0) {
        // 0x80054620: addiu       $t2, $zero, 0x32
        ctx->r10 = ADD32(0, 0X32);
            goto L_80054634;
    }
    // 0x80054620: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80054624: jal         0x800528AC
    // 0x80054628: nop

    func_800528AC(rdram, ctx);
        goto after_71;
    // 0x80054628: nop

    after_71:
    // 0x8005462C: b           L_800547E8
    // 0x80054630: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800547E8;
    // 0x80054630: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_80054634:
    // 0x80054634: sb          $zero, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = 0;
    // 0x80054638: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005463C: sb          $t3, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r11;
    // 0x80054640: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80054644: b           L_80054768
    // 0x80054648: sh          $t2, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r10;
        goto L_80054768;
    // 0x80054648: sh          $t2, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r10;
L_8005464C:
    // 0x8005464C: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80054650: lb          $t4, 0x12A8($t4)
    ctx->r12 = S32(MEM_B(ctx->r12, 0X12A8));
    // 0x80054654: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80054658: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005465C: bne         $t4, $zero, L_800546E0
    if (ctx->r12 != 0) {
        // 0x80054660: addiu       $t0, $zero, 0x7
        ctx->r8 = ADD32(0, 0X7);
            goto L_800546E0;
    }
    // 0x80054660: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80054664: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80054668: addiu       $v0, $v0, 0x38B8
    ctx->r2 = ADD32(ctx->r2, 0X38B8);
    // 0x8005466C: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x80054670: lb          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_B(ctx->r2, 0X0));
    // 0x80054674: bne         $s0, $t5, L_80054698
    if (ctx->r16 != ctx->r13) {
        // 0x80054678: nop
    
            goto L_80054698;
    }
    // 0x80054678: nop

L_8005467C:
    // 0x8005467C: jal         0x800BDDD0
    // 0x80054680: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_72;
    // 0x80054680: nop

    after_72:
    // 0x80054684: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80054688: addiu       $v0, $v0, 0x38B8
    ctx->r2 = ADD32(ctx->r2, 0X38B8);
    // 0x8005468C: lb          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_B(ctx->r2, 0X0));
    // 0x80054690: beq         $s0, $t6, L_8005467C
    if (ctx->r16 == ctx->r14) {
        // 0x80054694: nop
    
            goto L_8005467C;
    }
    // 0x80054694: nop

L_80054698:
    // 0x80054698: jal         0x8004BD60
    // 0x8005469C: nop

    updatetime(rdram, ctx);
        goto after_73;
    // 0x8005469C: nop

    after_73:
    // 0x800546A0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800546A4: lw          $a0, 0x38BC($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X38BC));
    // 0x800546A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800546AC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800546B0: beq         $a0, $zero, L_800546C8
    if (ctx->r4 == 0) {
        // 0x800546B4: addiu       $t8, $zero, 0x32
        ctx->r24 = ADD32(0, 0X32);
            goto L_800546C8;
    }
    // 0x800546B4: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x800546B8: jal         0x800528AC
    // 0x800546BC: nop

    func_800528AC(rdram, ctx);
        goto after_74;
    // 0x800546BC: nop

    after_74:
    // 0x800546C0: b           L_800547E8
    // 0x800546C4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800547E8;
    // 0x800546C4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800546C8:
    // 0x800546C8: sb          $zero, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = 0;
    // 0x800546CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800546D0: sb          $t7, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r15;
    // 0x800546D4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800546D8: b           L_80054768
    // 0x800546DC: sh          $t8, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r24;
        goto L_80054768;
    // 0x800546DC: sh          $t8, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r24;
L_800546E0:
    // 0x800546E0: sb          $t9, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r25;
    // 0x800546E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800546E8: b           L_80054768
    // 0x800546EC: sb          $t0, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r8;
        goto L_80054768;
    // 0x800546EC: sb          $t0, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = ctx->r8;
L_800546F0:
    // 0x800546F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800546F4: addiu       $v0, $v0, 0x38B8
    ctx->r2 = ADD32(ctx->r2, 0X38B8);
    // 0x800546F8: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x800546FC: lb          $t1, 0x0($v0)
    ctx->r9 = S32(MEM_B(ctx->r2, 0X0));
    // 0x80054700: bne         $s0, $t1, L_80054724
    if (ctx->r16 != ctx->r9) {
        // 0x80054704: nop
    
            goto L_80054724;
    }
    // 0x80054704: nop

L_80054708:
    // 0x80054708: jal         0x800BDDD0
    // 0x8005470C: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_75;
    // 0x8005470C: nop

    after_75:
    // 0x80054710: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80054714: addiu       $v0, $v0, 0x38B8
    ctx->r2 = ADD32(ctx->r2, 0X38B8);
    // 0x80054718: lb          $t3, 0x0($v0)
    ctx->r11 = S32(MEM_B(ctx->r2, 0X0));
    // 0x8005471C: beq         $s0, $t3, L_80054708
    if (ctx->r16 == ctx->r11) {
        // 0x80054720: nop
    
            goto L_80054708;
    }
    // 0x80054720: nop

L_80054724:
    // 0x80054724: jal         0x8004BD60
    // 0x80054728: nop

    updatetime(rdram, ctx);
        goto after_76;
    // 0x80054728: nop

    after_76:
    // 0x8005472C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80054730: lw          $a0, 0x38BC($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X38BC));
    // 0x80054734: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80054738: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8005473C: beq         $a0, $zero, L_80054754
    if (ctx->r4 == 0) {
        // 0x80054740: addiu       $t4, $zero, 0x32
        ctx->r12 = ADD32(0, 0X32);
            goto L_80054754;
    }
    // 0x80054740: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80054744: jal         0x800528AC
    // 0x80054748: nop

    func_800528AC(rdram, ctx);
        goto after_77;
    // 0x80054748: nop

    after_77:
    // 0x8005474C: b           L_800547E8
    // 0x80054750: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_800547E8;
    // 0x80054750: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_80054754:
    // 0x80054754: sb          $zero, -0x4366($at)
    MEM_B(-0X4366, ctx->r1) = 0;
    // 0x80054758: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005475C: sb          $t2, 0x3924($at)
    MEM_B(0X3924, ctx->r1) = ctx->r10;
    // 0x80054760: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80054764: sh          $t4, 0x12AC($at)
    MEM_H(0X12AC, ctx->r1) = ctx->r12;
L_80054768:
    // 0x80054768: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8005476C: addiu       $a1, $a1, 0x12A8
    ctx->r5 = ADD32(ctx->r5, 0X12A8);
    // 0x80054770: lb          $v0, 0x0($a1)
    ctx->r2 = S32(MEM_B(ctx->r5, 0X0));
    // 0x80054774: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80054778: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8005477C: addiu       $a0, $a0, 0x3924
    ctx->r4 = ADD32(ctx->r4, 0X3924);
    // 0x80054780: bgez        $v0, L_80054790
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80054784: lb          $v1, -0x4367($v1)
        ctx->r3 = S32(MEM_B(ctx->r3, -0X4367));
            goto L_80054790;
    }
    // 0x80054784: lb          $v1, -0x4367($v1)
    ctx->r3 = S32(MEM_B(ctx->r3, -0X4367));
    // 0x80054788: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8005478C: lb          $v0, 0x0($a1)
    ctx->r2 = S32(MEM_B(ctx->r5, 0X0));
L_80054790:
    // 0x80054790: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80054794: beq         $at, $zero, L_800547A0
    if (ctx->r1 == 0) {
        // 0x80054798: lui         $t6, 0x801D
        ctx->r14 = S32(0X801D << 16);
            goto L_800547A0;
    }
    // 0x80054798: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x8005479C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_800547A0:
    // 0x800547A0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800547A4: blez        $v1, L_800547B8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800547A8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800547B8;
    }
    // 0x800547A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800547AC: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x800547B0: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
    // 0x800547B4: andi        $v0, $t5, 0xFF
    ctx->r2 = ctx->r13 & 0XFF;
L_800547B8:
    // 0x800547B8: bne         $v0, $zero, L_800547E4
    if (ctx->r2 != 0) {
        // 0x800547BC: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_800547E4;
    }
    // 0x800547BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800547C0: lbu         $v0, -0x4366($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4366);
    // 0x800547C4: lbu         $t6, -0x4365($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4365);
    // 0x800547C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800547CC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800547D0: beql        $t6, $v0, L_800547E8
    if (ctx->r14 == ctx->r2) {
        // 0x800547D4: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800547E8;
    }
    goto skip_1;
    // 0x800547D4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_1:
    // 0x800547D8: sb          $v0, -0x4365($at)
    MEM_B(-0X4365, ctx->r1) = ctx->r2;
    // 0x800547DC: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x800547E0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_800547E4:
    // 0x800547E4: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_800547E8:
    // 0x800547E8: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800547EC: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x800547F0: jr          $ra
    // 0x800547F4: nop

    return;
    // 0x800547F4: nop

;}
RECOMP_FUNC void operatefta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099568: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8009956C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80099570: addiu       $a1, $a1, 0x4418
    ctx->r5 = ADD32(ctx->r5, 0X4418);
    // 0x80099574: lw          $v1, 0x0($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80099578: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009957C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80099580: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80099584: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80099588: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009958C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80099590: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80099594: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80099598: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009959C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800995A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800995A4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800995A8: lui         $t7, 0xED05
    ctx->r15 = S32(0XED05 << 16);
    // 0x800995AC: lui         $t8, 0x4A
    ctx->r24 = S32(0X4A << 16);
    // 0x800995B0: ori         $t8, $t8, 0xC384
    ctx->r24 = ctx->r24 | 0XC384;
    // 0x800995B4: ori         $t7, $t7, 0x403C
    ctx->r15 = ctx->r15 | 0X403C;
    // 0x800995B8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800995BC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800995C0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800995C4: lh          $a0, -0x9DC($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X9DC));
    // 0x800995C8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800995CC: lui         $s7, 0x8010
    ctx->r23 = S32(0X8010 << 16);
    // 0x800995D0: blez        $a0, L_80099838
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800995D4: addiu       $fp, $zero, 0xA
        ctx->r30 = ADD32(0, 0XA);
            goto L_80099838;
    }
    // 0x800995D4: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x800995D8: addiu       $s7, $s7, -0x147C
    ctx->r23 = ADD32(ctx->r23, -0X147C);
    // 0x800995DC: lh          $s6, 0x46($sp)
    ctx->r22 = S32(MEM_H(ctx->r29, 0X46));
    // 0x800995E0: lh          $s5, 0x48($sp)
    ctx->r21 = S32(MEM_H(ctx->r29, 0X48));
    // 0x800995E4: lh          $s4, 0x4A($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X4A));
    // 0x800995E8: lh          $s2, 0x4C($sp)
    ctx->r18 = S32(MEM_H(ctx->r29, 0X4C));
L_800995EC:
    // 0x800995EC: sll         $t9, $s3, 3
    ctx->r25 = S32(ctx->r19 << 3);
    // 0x800995F0: subu        $t9, $t9, $s3
    ctx->r25 = SUB32(ctx->r25, ctx->r19);
    // 0x800995F4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800995F8: addu        $t9, $t9, $s3
    ctx->r25 = ADD32(ctx->r25, ctx->r19);
    // 0x800995FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80099600: subu        $t9, $t9, $s3
    ctx->r25 = SUB32(ctx->r25, ctx->r19);
    // 0x80099604: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x80099608: addiu       $t0, $t0, 0x5770
    ctx->r8 = ADD32(ctx->r8, 0X5770);
    // 0x8009960C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80099610: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x80099614: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
    // 0x80099618: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8009961C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80099620: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80099624: bnel        $at, $zero, L_80099818
    if (ctx->r1 != 0) {
        // 0x80099628: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80099818;
    }
    goto skip_0;
    // 0x80099628: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x8009962C: lbu         $t1, -0x5B5C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X5B5C);
    // 0x80099630: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80099634: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80099638: beq         $t1, $zero, L_80099654
    if (ctx->r9 == 0) {
        // 0x8009963C: nop
    
            goto L_80099654;
    }
    // 0x8009963C: nop

    // 0x80099640: beql        $at, $zero, L_80099654
    if (ctx->r1 == 0) {
        // 0x80099644: sh          $fp, 0x2CC($s0)
        MEM_H(0X2CC, ctx->r16) = ctx->r30;
            goto L_80099654;
    }
    goto skip_1;
    // 0x80099644: sh          $fp, 0x2CC($s0)
    MEM_H(0X2CC, ctx->r16) = ctx->r30;
    skip_1:
    // 0x80099648: b           L_80099654
    // 0x8009964C: sh          $v1, 0x2CC($s0)
    MEM_H(0X2CC, ctx->r16) = ctx->r3;
        goto L_80099654;
    // 0x8009964C: sh          $v1, 0x2CC($s0)
    MEM_H(0X2CC, ctx->r16) = ctx->r3;
    // 0x80099650: sh          $fp, 0x2CC($s0)
    MEM_H(0X2CC, ctx->r16) = ctx->r30;
L_80099654:
    // 0x80099654: beq         $v0, $zero, L_80099680
    if (ctx->r2 == 0) {
        // 0x80099658: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80099680;
    }
    // 0x80099658: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8009965C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80099660: beq         $v0, $at, L_800996A0
    if (ctx->r2 == ctx->r1) {
        // 0x80099664: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800996A0;
    }
    // 0x80099664: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80099668: beq         $v0, $at, L_800996F4
    if (ctx->r2 == ctx->r1) {
        // 0x8009966C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800996F4;
    }
    // 0x8009966C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80099670: beql        $v0, $at, L_8009971C
    if (ctx->r2 == ctx->r1) {
        // 0x80099674: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_8009971C;
    }
    goto skip_2;
    // 0x80099674: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    skip_2:
    // 0x80099678: b           L_8009975C
    // 0x8009967C: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
        goto L_8009975C;
    // 0x8009967C: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
L_80099680:
    // 0x80099680: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
    // 0x80099684: addiu       $s2, $zero, 0x22
    ctx->r18 = ADD32(0, 0X22);
    // 0x80099688: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x8009968C: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    // 0x80099690: bne         $at, $zero, L_8009975C
    if (ctx->r1 != 0) {
        // 0x80099694: addiu       $s6, $zero, 0xC8
        ctx->r22 = ADD32(0, 0XC8);
            goto L_8009975C;
    }
    // 0x80099694: addiu       $s6, $zero, 0xC8
    ctx->r22 = ADD32(0, 0XC8);
    // 0x80099698: b           L_8009975C
    // 0x8009969C: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
        goto L_8009975C;
    // 0x8009969C: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
L_800996A0:
    // 0x800996A0: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800996A4: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x800996A8: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    // 0x800996AC: bne         $at, $zero, L_800996E8
    if (ctx->r1 != 0) {
        // 0x800996B0: addiu       $s6, $zero, 0x40
        ctx->r22 = ADD32(0, 0X40);
            goto L_800996E8;
    }
    // 0x800996B0: addiu       $s6, $zero, 0x40
    ctx->r22 = ADD32(0, 0X40);
    // 0x800996B4: lh          $t2, 0x2CE($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2CE));
    // 0x800996B8: addiu       $s2, $zero, 0x2C
    ctx->r18 = ADD32(0, 0X2C);
    // 0x800996BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800996C0: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x800996C4: jal         0x80099488
    // 0x800996C8: lw          $a0, 0x0($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
    func_80099488(rdram, ctx);
        goto after_0;
    // 0x800996C8: lw          $a0, 0x0($t4)
    ctx->r4 = S32(MEM_W(ctx->r12, 0X0));
    after_0:
    // 0x800996CC: addiu       $t5, $zero, 0x129
    ctx->r13 = ADD32(0, 0X129);
    // 0x800996D0: subu        $s1, $t5, $v0
    ctx->r17 = SUB32(ctx->r13, ctx->r2);
    // 0x800996D4: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x800996D8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800996DC: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800996E0: b           L_8009975C
    // 0x800996E4: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
        goto L_8009975C;
    // 0x800996E4: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
L_800996E8:
    // 0x800996E8: addiu       $s2, $zero, 0x82
    ctx->r18 = ADD32(0, 0X82);
    // 0x800996EC: b           L_8009975C
    // 0x800996F0: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
        goto L_8009975C;
    // 0x800996F0: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
L_800996F4:
    // 0x800996F4: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800996F8: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
    // 0x800996FC: addiu       $s6, $zero, 0xC8
    ctx->r22 = ADD32(0, 0XC8);
    // 0x80099700: addiu       $s2, $zero, 0x8C
    ctx->r18 = ADD32(0, 0X8C);
    // 0x80099704: addiu       $s4, $zero, 0xC8
    ctx->r20 = ADD32(0, 0XC8);
    // 0x80099708: bne         $at, $zero, L_8009975C
    if (ctx->r1 != 0) {
        // 0x8009970C: addiu       $s5, $zero, 0x40
        ctx->r21 = ADD32(0, 0X40);
            goto L_8009975C;
    }
    // 0x8009970C: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x80099710: b           L_8009975C
    // 0x80099714: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
        goto L_8009975C;
    // 0x80099714: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
    // 0x80099718: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_8009971C:
    // 0x8009971C: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    // 0x80099720: addiu       $s6, $zero, 0x40
    ctx->r22 = ADD32(0, 0X40);
    // 0x80099724: addiu       $s4, $zero, 0xC8
    ctx->r20 = ADD32(0, 0XC8);
    // 0x80099728: bne         $at, $zero, L_80099758
    if (ctx->r1 != 0) {
        // 0x8009972C: addiu       $s2, $zero, 0x96
        ctx->r18 = ADD32(0, 0X96);
            goto L_80099758;
    }
    // 0x8009972C: addiu       $s2, $zero, 0x96
    ctx->r18 = ADD32(0, 0X96);
    // 0x80099730: lh          $t8, 0x2CE($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2CE));
    // 0x80099734: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80099738: addu        $t0, $s7, $t9
    ctx->r8 = ADD32(ctx->r23, ctx->r25);
    // 0x8009973C: jal         0x80099488
    // 0x80099740: lw          $a0, 0x0($t0)
    ctx->r4 = S32(MEM_W(ctx->r8, 0X0));
    func_80099488(rdram, ctx);
        goto after_1;
    // 0x80099740: lw          $a0, 0x0($t0)
    ctx->r4 = S32(MEM_W(ctx->r8, 0X0));
    after_1:
    // 0x80099744: addiu       $t1, $zero, 0x129
    ctx->r9 = ADD32(0, 0X129);
    // 0x80099748: subu        $s1, $t1, $v0
    ctx->r17 = SUB32(ctx->r9, ctx->r2);
    // 0x8009974C: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x80099750: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80099754: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_80099758:
    // 0x80099758: lh          $v1, 0x2CC($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X2CC));
L_8009975C:
    // 0x8009975C: sll         $t4, $v1, 8
    ctx->r12 = S32(ctx->r3 << 8);
    // 0x80099760: div         $zero, $t4, $fp
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r30)));
    // 0x80099764: bne         $fp, $zero, L_80099770
    if (ctx->r30 != 0) {
        // 0x80099768: nop
    
            goto L_80099770;
    }
    // 0x80099768: nop

    // 0x8009976C: break       7
    do_break(2148112236);
L_80099770:
    // 0x80099770: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80099774: bne         $fp, $at, L_80099788
    if (ctx->r30 != ctx->r1) {
        // 0x80099778: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80099788;
    }
    // 0x80099778: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009977C: bne         $t4, $at, L_80099788
    if (ctx->r12 != ctx->r1) {
        // 0x80099780: nop
    
            goto L_80099788;
    }
    // 0x80099780: nop

    // 0x80099784: break       6
    do_break(2148112260);
L_80099788:
    // 0x80099788: mflo        $a3
    ctx->r7 = lo;
    // 0x8009978C: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x80099790: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80099794: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80099798: bne         $at, $zero, L_800997A4
    if (ctx->r1 != 0) {
        // 0x8009979C: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_800997A4;
    }
    // 0x8009979C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800997A0: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
L_800997A4:
    // 0x800997A4: sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20 << 16);
    // 0x800997A8: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x800997AC: sll         $a2, $s6, 16
    ctx->r6 = S32(ctx->r22 << 16);
    // 0x800997B0: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800997B4: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800997B8: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800997BC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800997C0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800997C4: jal         0x8006E994
    // 0x800997C8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_2;
    // 0x800997C8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_2:
    // 0x800997CC: lh          $t2, 0x2CE($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2CE));
    // 0x800997D0: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800997D4: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x800997D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800997DC: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x800997E0: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800997E4: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800997E8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800997EC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800997F0: jal         0x80063F68
    // 0x800997F4: lw          $a2, 0x0($t4)
    ctx->r6 = S32(MEM_W(ctx->r12, 0X0));
    gametext(rdram, ctx);
        goto after_3;
    // 0x800997F4: lw          $a2, 0x0($t4)
    ctx->r6 = S32(MEM_W(ctx->r12, 0X0));
    after_3:
    // 0x800997F8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800997FC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80099800: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80099804: jal         0x8006E994
    // 0x80099808: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    setrotatespriteflags(rdram, ctx);
        goto after_4;
    // 0x80099808: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_4:
    // 0x8009980C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80099810: lh          $a0, -0x9DC($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X9DC));
    // 0x80099814: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80099818:
    // 0x80099818: andi        $t5, $s3, 0xFF
    ctx->r13 = ctx->r19 & 0XFF;
    // 0x8009981C: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80099820: bne         $at, $zero, L_800995EC
    if (ctx->r1 != 0) {
        // 0x80099824: or          $s3, $t5, $zero
        ctx->r19 = ctx->r13 | 0;
            goto L_800995EC;
    }
    // 0x80099824: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x80099828: sh          $s6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r22;
    // 0x8009982C: sh          $s5, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r21;
    // 0x80099830: sh          $s4, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r20;
    // 0x80099834: sh          $s2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r18;
L_80099838:
    // 0x80099838: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8009983C: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80099840: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80099844: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80099848: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8009984C: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80099850: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80099854: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80099858: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8009985C: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80099860: jr          $ra
    // 0x80099864: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80099864: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800551F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800551F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800551FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055200: jal         0x80051D98
    // 0x80055204: nop

    func_80051D98(rdram, ctx);
        goto after_0;
    // 0x80055204: nop

    after_0:
    // 0x80055208: lui         $t0, 0x4E44
    ctx->r8 = S32(0X4E44 << 16);
    // 0x8005520C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80055210: addiu       $a3, $a3, -0x46D8
    ctx->r7 = ADD32(ctx->r7, -0X46D8);
    // 0x80055214: ori         $t0, $t0, 0x4E45
    ctx->r8 = ctx->r8 | 0X4E45;
    // 0x80055218: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8005521C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80055220: addiu       $a2, $zero, 0x3458
    ctx->r6 = ADD32(0, 0X3458);
L_80055224:
    // 0x80055224: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80055228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005522C: addiu       $a0, $a0, -0x4388
    ctx->r4 = ADD32(ctx->r4, -0X4388);
    // 0x80055230: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80055234:
    // 0x80055234: lb          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_B(ctx->r4, 0X0));
    // 0x80055238: sll         $t7, $v1, 5
    ctx->r15 = S32(ctx->r3 << 5);
    // 0x8005523C: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x80055240: bnel        $t6, $zero, L_80055278
    if (ctx->r14 != 0) {
        // 0x80055244: lb          $t5, 0x1($a0)
        ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
            goto L_80055278;
    }
    goto skip_0;
    // 0x80055244: lb          $t5, 0x1($a0)
    ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
    skip_0:
    // 0x80055248: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x8005524C: bnel        $a2, $t8, L_80055278
    if (ctx->r6 != ctx->r24) {
        // 0x80055250: lb          $t5, 0x1($a0)
        ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
            goto L_80055278;
    }
    goto skip_1;
    // 0x80055250: lb          $t5, 0x1($a0)
    ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
    skip_1:
    // 0x80055254: lw          $t9, 0x4($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80055258: bnel        $t0, $t9, L_80055278
    if (ctx->r8 != ctx->r25) {
        // 0x8005525C: lb          $t5, 0x1($a0)
        ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
            goto L_80055278;
    }
    goto skip_2;
    // 0x8005525C: lb          $t5, 0x1($a0)
    ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
    skip_2:
    // 0x80055260: lbu         $t4, 0xA($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XA);
    // 0x80055264: addiu       $t3, $t1, 0x1A
    ctx->r11 = ADD32(ctx->r9, 0X1A);
    // 0x80055268: bnel        $t3, $t4, L_80055278
    if (ctx->r11 != ctx->r12) {
        // 0x8005526C: lb          $t5, 0x1($a0)
        ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
            goto L_80055278;
    }
    goto skip_3;
    // 0x8005526C: lb          $t5, 0x1($a0)
    ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
    skip_3:
    // 0x80055270: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80055274: lb          $t5, 0x1($a0)
    ctx->r13 = S32(MEM_B(ctx->r4, 0X1));
L_80055278:
    // 0x80055278: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x8005527C: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
    // 0x80055280: bnel        $t5, $zero, L_800552B8
    if (ctx->r13 != 0) {
        // 0x80055284: lb          $t4, 0x2($a0)
        ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
            goto L_800552B8;
    }
    goto skip_4;
    // 0x80055284: lb          $t4, 0x2($a0)
    ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
    skip_4:
    // 0x80055288: lhu         $t7, 0x28($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X28);
    // 0x8005528C: bnel        $a2, $t7, L_800552B8
    if (ctx->r6 != ctx->r15) {
        // 0x80055290: lb          $t4, 0x2($a0)
        ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
            goto L_800552B8;
    }
    goto skip_5;
    // 0x80055290: lb          $t4, 0x2($a0)
    ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
    skip_5:
    // 0x80055294: lw          $t8, 0x24($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X24));
    // 0x80055298: bnel        $t0, $t8, L_800552B8
    if (ctx->r8 != ctx->r24) {
        // 0x8005529C: lb          $t4, 0x2($a0)
        ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
            goto L_800552B8;
    }
    goto skip_6;
    // 0x8005529C: lb          $t4, 0x2($a0)
    ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
    skip_6:
    // 0x800552A0: lbu         $t3, 0x2A($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2A);
    // 0x800552A4: addiu       $t9, $t1, 0x1A
    ctx->r25 = ADD32(ctx->r9, 0X1A);
    // 0x800552A8: bnel        $t9, $t3, L_800552B8
    if (ctx->r25 != ctx->r11) {
        // 0x800552AC: lb          $t4, 0x2($a0)
        ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
            goto L_800552B8;
    }
    goto skip_7;
    // 0x800552AC: lb          $t4, 0x2($a0)
    ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
    skip_7:
    // 0x800552B0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800552B4: lb          $t4, 0x2($a0)
    ctx->r12 = S32(MEM_B(ctx->r4, 0X2));
L_800552B8:
    // 0x800552B8: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
    // 0x800552BC: addu        $v0, $a3, $t5
    ctx->r2 = ADD32(ctx->r7, ctx->r13);
    // 0x800552C0: bnel        $t4, $zero, L_800552F8
    if (ctx->r12 != 0) {
        // 0x800552C4: lb          $t3, 0x3($a0)
        ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
            goto L_800552F8;
    }
    goto skip_8;
    // 0x800552C4: lb          $t3, 0x3($a0)
    ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
    skip_8:
    // 0x800552C8: lhu         $t6, 0x48($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X48);
    // 0x800552CC: bnel        $a2, $t6, L_800552F8
    if (ctx->r6 != ctx->r14) {
        // 0x800552D0: lb          $t3, 0x3($a0)
        ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
            goto L_800552F8;
    }
    goto skip_9;
    // 0x800552D0: lb          $t3, 0x3($a0)
    ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
    skip_9:
    // 0x800552D4: lw          $t7, 0x44($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X44));
    // 0x800552D8: bnel        $t0, $t7, L_800552F8
    if (ctx->r8 != ctx->r15) {
        // 0x800552DC: lb          $t3, 0x3($a0)
        ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
            goto L_800552F8;
    }
    goto skip_10;
    // 0x800552DC: lb          $t3, 0x3($a0)
    ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
    skip_10:
    // 0x800552E0: lbu         $t9, 0x4A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4A);
    // 0x800552E4: addiu       $t8, $t1, 0x1A
    ctx->r24 = ADD32(ctx->r9, 0X1A);
    // 0x800552E8: bnel        $t8, $t9, L_800552F8
    if (ctx->r24 != ctx->r25) {
        // 0x800552EC: lb          $t3, 0x3($a0)
        ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
            goto L_800552F8;
    }
    goto skip_11;
    // 0x800552EC: lb          $t3, 0x3($a0)
    ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
    skip_11:
    // 0x800552F0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800552F4: lb          $t3, 0x3($a0)
    ctx->r11 = S32(MEM_B(ctx->r4, 0X3));
L_800552F8:
    // 0x800552F8: sll         $t4, $v1, 5
    ctx->r12 = S32(ctx->r3 << 5);
    // 0x800552FC: addu        $v0, $a3, $t4
    ctx->r2 = ADD32(ctx->r7, ctx->r12);
    // 0x80055300: bnel        $t3, $zero, L_80055338
    if (ctx->r11 != 0) {
        // 0x80055304: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80055338;
    }
    goto skip_12;
    // 0x80055304: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_12:
    // 0x80055308: lhu         $t5, 0x68($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X68);
    // 0x8005530C: bnel        $a2, $t5, L_80055338
    if (ctx->r6 != ctx->r13) {
        // 0x80055310: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80055338;
    }
    goto skip_13;
    // 0x80055310: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_13:
    // 0x80055314: lw          $t6, 0x64($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X64));
    // 0x80055318: bnel        $t0, $t6, L_80055338
    if (ctx->r8 != ctx->r14) {
        // 0x8005531C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80055338;
    }
    goto skip_14;
    // 0x8005531C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_14:
    // 0x80055320: lbu         $t8, 0x6A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6A);
    // 0x80055324: addiu       $t7, $t1, 0x1A
    ctx->r15 = ADD32(ctx->r9, 0X1A);
    // 0x80055328: bnel        $t7, $t8, L_80055338
    if (ctx->r15 != ctx->r24) {
        // 0x8005532C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80055338;
    }
    goto skip_15;
    // 0x8005532C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_15:
    // 0x80055330: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80055334: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80055338:
    // 0x80055338: bne         $v1, $t2, L_80055234
    if (ctx->r3 != ctx->r10) {
        // 0x8005533C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80055234;
    }
    // 0x8005533C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80055340: bne         $a1, $zero, L_80055354
    if (ctx->r5 != 0) {
        // 0x80055344: addiu       $v0, $t1, 0x1A
        ctx->r2 = ADD32(ctx->r9, 0X1A);
            goto L_80055354;
    }
    // 0x80055344: addiu       $v0, $t1, 0x1A
    ctx->r2 = ADD32(ctx->r9, 0X1A);
    // 0x80055348: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8005534C: b           L_80055364
    // 0x80055350: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80055364;
    // 0x80055350: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80055354:
    // 0x80055354: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80055358: bne         $t1, $t2, L_80055224
    if (ctx->r9 != ctx->r10) {
        // 0x8005535C: nop
    
            goto L_80055224;
    }
    // 0x8005535C: nop

    // 0x80055360: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_80055364:
    // 0x80055364: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80055368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005536C: jr          $ra
    // 0x80055370: nop

    return;
    // 0x80055370: nop

;}
RECOMP_FUNC void func_80056200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056200: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x80056204: lw          $t6, -0x27D8($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X27D8));
    // 0x80056208: addiu       $t1, $zero, 0x1A2
    ctx->r9 = ADD32(0, 0X1A2);
    // 0x8005620C: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x80056210: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056214: lw          $t9, -0x27D4($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X27D4));
    // 0x80056218: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8005621C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80056220: lw          $v1, -0x27C8($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X27C8));
    // 0x80056224: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80056228: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005622C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x80056230: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80056234: sdc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X30, ctx->r29);
    // 0x80056238: mflo        $t7
    ctx->r15 = lo;
    // 0x8005623C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80056240: sdc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X28, ctx->r29);
    // 0x80056244: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056248: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x8005624C: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x80056250: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x80056254: addiu       $v0, $v0, -0x27E0
    ctx->r2 = ADD32(ctx->r2, -0X27E0);
    // 0x80056258: addiu       $t0, $t0, -0x4200
    ctx->r8 = ADD32(ctx->r8, -0X4200);
    // 0x8005625C: lwc1        $f20, -0x27C4($at)
    ctx->f20.u32l = S32(MEM_W(ctx->r1, -0X27C4));
    // 0x80056260: addu        $a2, $t8, $v1
    ctx->r6 = ADD32(ctx->r24, ctx->r3);
    // 0x80056264: mflo        $t2
    ctx->r10 = lo;
    // 0x80056268: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8005626C: addu        $a3, $t3, $v1
    ctx->r7 = ADD32(ctx->r11, ctx->r3);
L_80056270:
    // 0x80056270: lh          $t4, 0x0($a2)
    ctx->r12 = S32(MEM_H(ctx->r6, 0X0));
    // 0x80056274: lh          $t5, 0x2($a2)
    ctx->r13 = S32(MEM_H(ctx->r6, 0X2));
    // 0x80056278: lh          $t6, 0x4($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0X4));
    // 0x8005627C: mtc1        $t4, $f30
    ctx->f30.u32l = ctx->r12;
    // 0x80056280: mtc1        $t5, $f28
    ctx->f28.u32l = ctx->r13;
    // 0x80056284: lh          $t8, 0xA($a2)
    ctx->r24 = S32(MEM_H(ctx->r6, 0XA));
    // 0x80056288: cvt.s.w     $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    ctx->f30.fl = CVT_S_W(ctx->f30.u32l);
    // 0x8005628C: lh          $t9, 0xC($a2)
    ctx->r25 = S32(MEM_H(ctx->r6, 0XC));
    // 0x80056290: mtc1        $t8, $f26
    ctx->f26.u32l = ctx->r24;
    // 0x80056294: lh          $t2, 0xE($a2)
    ctx->r10 = S32(MEM_H(ctx->r6, 0XE));
    // 0x80056298: mtc1        $t9, $f24
    ctx->f24.u32l = ctx->r25;
    // 0x8005629C: cvt.s.w     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.fl = CVT_S_W(ctx->f28.u32l);
    // 0x800562A0: lh          $t3, 0x0($a3)
    ctx->r11 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800562A4: lh          $t4, 0x2($a3)
    ctx->r12 = S32(MEM_H(ctx->r7, 0X2));
    // 0x800562A8: lh          $t5, 0x4($a3)
    ctx->r13 = S32(MEM_H(ctx->r7, 0X4));
    // 0x800562AC: mtc1        $t3, $f22
    ctx->f22.u32l = ctx->r11;
    // 0x800562B0: cvt.s.w     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
    // 0x800562B4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800562B8: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800562BC: lh          $t8, 0xC($a3)
    ctx->r24 = S32(MEM_H(ctx->r7, 0XC));
    // 0x800562C0: lh          $t9, 0xE($a3)
    ctx->r25 = S32(MEM_H(ctx->r7, 0XE));
    // 0x800562C4: cvt.s.w     $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    ctx->f24.fl = CVT_S_W(ctx->f24.u32l);
    // 0x800562C8: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x800562CC: mtc1        $t9, $f12
    ctx->f12.u32l = ctx->r25;
    // 0x800562D0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800562D4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800562D8: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x800562DC: lh          $t7, 0xA($a3)
    ctx->r15 = S32(MEM_H(ctx->r7, 0XA));
    // 0x800562E0: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800562E4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800562E8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800562EC: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800562F0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800562F4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800562F8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800562FC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80056300: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80056304: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80056308: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005630C: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x80056310: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80056314: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80056318: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8005631C: lh          $t2, -0xA($a3)
    ctx->r10 = S32(MEM_H(ctx->r7, -0XA));
    // 0x80056320: lh          $t3, -0x8($a3)
    ctx->r11 = S32(MEM_H(ctx->r7, -0X8));
    // 0x80056324: sub.s       $f30, $f30, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f30.fl = ctx->f30.fl - ctx->f22.fl;
    // 0x80056328: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8005632C: mtc1        $t3, $f2
    ctx->f2.u32l = ctx->r11;
    // 0x80056330: sub.s       $f28, $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = ctx->f28.fl - ctx->f16.fl;
    // 0x80056334: mul.s       $f30, $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f20.fl);
    // 0x80056338: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8005633C: mul.s       $f28, $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x80056340: sub.s       $f26, $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f6.fl;
    // 0x80056344: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80056348: sub.s       $f24, $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f14.fl;
    // 0x8005634C: mul.s       $f26, $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x80056350: sub.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80056354: mul.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x80056358: add.s       $f22, $f30, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f30.fl + ctx->f22.fl;
    // 0x8005635C: mul.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80056360: add.s       $f16, $f28, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f28.fl + ctx->f16.fl;
    // 0x80056364: add.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80056368: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005636C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80056370: add.s       $f6, $f26, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f26.fl + ctx->f6.fl;
    // 0x80056374: add.s       $f14, $f24, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f24.fl + ctx->f14.fl;
    // 0x80056378: add.s       $f12, $f18, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8005637C: trunc.w.s   $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80056380: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80056384: mfc1        $t5, $f22
    ctx->r13 = (int32_t)ctx->f22.u32l;
    // 0x80056388: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8005638C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80056390: sh          $t5, -0x10($t0)
    MEM_H(-0X10, ctx->r8) = ctx->r13;
    // 0x80056394: trunc.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80056398: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8005639C: sh          $t7, -0xE($t0)
    MEM_H(-0XE, ctx->r8) = ctx->r15;
    // 0x800563A0: trunc.w.s   $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800563A4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800563A8: sh          $t9, -0xC($t0)
    MEM_H(-0XC, ctx->r8) = ctx->r25;
    // 0x800563AC: trunc.w.s   $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800563B0: mfc1        $t5, $f2
    ctx->r13 = (int32_t)ctx->f2.u32l;
    // 0x800563B4: sh          $t3, -0xA($t0)
    MEM_H(-0XA, ctx->r8) = ctx->r11;
    // 0x800563B8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800563BC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800563C0: sh          $t5, -0x8($t0)
    MEM_H(-0X8, ctx->r8) = ctx->r13;
    // 0x800563C4: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800563C8: mfc1        $t9, $f14
    ctx->r25 = (int32_t)ctx->f14.u32l;
    // 0x800563CC: sh          $t7, -0x6($t0)
    MEM_H(-0X6, ctx->r8) = ctx->r15;
    // 0x800563D0: mfc1        $t3, $f12
    ctx->r11 = (int32_t)ctx->f12.u32l;
    // 0x800563D4: sh          $t9, -0x4($t0)
    MEM_H(-0X4, ctx->r8) = ctx->r25;
    // 0x800563D8: bne         $t0, $v0, L_80056270
    if (ctx->r8 != ctx->r2) {
        // 0x800563DC: sh          $t3, -0x2($t0)
        MEM_H(-0X2, ctx->r8) = ctx->r11;
            goto L_80056270;
    }
    // 0x800563DC: sh          $t3, -0x2($t0)
    MEM_H(-0X2, ctx->r8) = ctx->r11;
    // 0x800563E0: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800563E4: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x800563E8: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x800563EC: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x800563F0: ldc1        $f28, 0x28($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X28);
    // 0x800563F4: ldc1        $f30, 0x30($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X30);
    // 0x800563F8: jr          $ra
    // 0x800563FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800563FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void resetsbarscroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC0C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006EC10: lh          $t6, -0x9DC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X9DC));
    // 0x8006EC14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006EC18: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8006EC1C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8006EC20: bne         $at, $zero, L_8006EC40
    if (ctx->r1 != 0) {
        // 0x8006EC24: addiu       $t0, $zero, -0x18
        ctx->r8 = ADD32(0, -0X18);
            goto L_8006EC40;
    }
    // 0x8006EC24: addiu       $t0, $zero, -0x18
    ctx->r8 = ADD32(0, -0X18);
    // 0x8006EC28: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006EC2C: sh          $t7, -0x134C($at)
    MEM_H(-0X134C, ctx->r1) = ctx->r15;
    // 0x8006EC30: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006EC34: addiu       $t8, $zero, -0x63
    ctx->r24 = ADD32(0, -0X63);
    // 0x8006EC38: jr          $ra
    // 0x8006EC3C: sh          $t8, -0x134E($at)
    MEM_H(-0X134E, ctx->r1) = ctx->r24;
    return;
    // 0x8006EC3C: sh          $t8, -0x134E($at)
    MEM_H(-0X134E, ctx->r1) = ctx->r24;
L_8006EC40:
    // 0x8006EC40: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006EC44: sh          $t9, -0x1350($at)
    MEM_H(-0X1350, ctx->r1) = ctx->r25;
    // 0x8006EC48: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006EC4C: sh          $t0, -0x134E($at)
    MEM_H(-0X134E, ctx->r1) = ctx->r8;
    // 0x8006EC50: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x8006EC54: sh          $zero, -0x134C($at)
    MEM_H(-0X134C, ctx->r1) = 0;
    // 0x8006EC58: jr          $ra
    // 0x8006EC5C: nop

    return;
    // 0x8006EC5C: nop

;}
RECOMP_FUNC void isadoorwall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACC8C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800ACC90: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800ACC94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800ACC98: slti        $at, $t7, 0x30E
    ctx->r1 = SIGNED(ctx->r15) < 0X30E ? 1 : 0;
    // 0x800ACC9C: bne         $at, $zero, L_800ACCE0
    if (ctx->r1 != 0) {
        // 0x800ACCA0: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800ACCE0;
    }
    // 0x800ACCA0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800ACCA4: addiu       $at, $zero, 0x44E
    ctx->r1 = ADD32(0, 0X44E);
    // 0x800ACCA8: beq         $t7, $at, L_800ACD70
    if (ctx->r15 == ctx->r1) {
        // 0x800ACCAC: addiu       $at, $zero, 0x478
        ctx->r1 = ADD32(0, 0X478);
            goto L_800ACD70;
    }
    // 0x800ACCAC: addiu       $at, $zero, 0x478
    ctx->r1 = ADD32(0, 0X478);
    // 0x800ACCB0: beq         $t7, $at, L_800ACD70
    if (ctx->r15 == ctx->r1) {
        // 0x800ACCB4: addiu       $at, $zero, 0x491
        ctx->r1 = ADD32(0, 0X491);
            goto L_800ACD70;
    }
    // 0x800ACCB4: addiu       $at, $zero, 0x491
    ctx->r1 = ADD32(0, 0X491);
    // 0x800ACCB8: beq         $t7, $at, L_800ACD70
    if (ctx->r15 == ctx->r1) {
        // 0x800ACCBC: addiu       $at, $zero, 0x49A
        ctx->r1 = ADD32(0, 0X49A);
            goto L_800ACD70;
    }
    // 0x800ACCBC: addiu       $at, $zero, 0x49A
    ctx->r1 = ADD32(0, 0X49A);
    // 0x800ACCC0: beq         $t7, $at, L_800ACD70
    if (ctx->r15 == ctx->r1) {
        // 0x800ACCC4: addiu       $at, $zero, 0x49B
        ctx->r1 = ADD32(0, 0X49B);
            goto L_800ACD70;
    }
    // 0x800ACCC4: addiu       $at, $zero, 0x49B
    ctx->r1 = ADD32(0, 0X49B);
    // 0x800ACCC8: beq         $t7, $at, L_800ACD70
    if (ctx->r15 == ctx->r1) {
        // 0x800ACCCC: addiu       $at, $zero, 0x1127
        ctx->r1 = ADD32(0, 0X1127);
            goto L_800ACD70;
    }
    // 0x800ACCCC: addiu       $at, $zero, 0x1127
    ctx->r1 = ADD32(0, 0X1127);
    // 0x800ACCD0: beq         $t7, $at, L_800ACD70
    if (ctx->r15 == ctx->r1) {
        // 0x800ACCD4: nop
    
            goto L_800ACD70;
    }
    // 0x800ACCD4: nop

    // 0x800ACCD8: b           L_800ACD7C
    // 0x800ACCDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ACD7C;
    // 0x800ACCDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ACCE0:
    // 0x800ACCE0: slti        $at, $a0, 0x1C1
    ctx->r1 = SIGNED(ctx->r4) < 0X1C1 ? 1 : 0;
    // 0x800ACCE4: bne         $at, $zero, L_800ACD0C
    if (ctx->r1 != 0) {
        // 0x800ACCE8: addiu       $at, $zero, 0x1C1
        ctx->r1 = ADD32(0, 0X1C1);
            goto L_800ACD0C;
    }
    // 0x800ACCE8: addiu       $at, $zero, 0x1C1
    ctx->r1 = ADD32(0, 0X1C1);
    // 0x800ACCEC: beq         $a0, $at, L_800ACD70
    if (ctx->r4 == ctx->r1) {
        // 0x800ACCF0: addiu       $at, $zero, 0x2CD
        ctx->r1 = ADD32(0, 0X2CD);
            goto L_800ACD70;
    }
    // 0x800ACCF0: addiu       $at, $zero, 0x2CD
    ctx->r1 = ADD32(0, 0X2CD);
    // 0x800ACCF4: beq         $a0, $at, L_800ACD70
    if (ctx->r4 == ctx->r1) {
        // 0x800ACCF8: addiu       $at, $zero, 0x30D
        ctx->r1 = ADD32(0, 0X30D);
            goto L_800ACD70;
    }
    // 0x800ACCF8: addiu       $at, $zero, 0x30D
    ctx->r1 = ADD32(0, 0X30D);
    // 0x800ACCFC: beq         $a0, $at, L_800ACD70
    if (ctx->r4 == ctx->r1) {
        // 0x800ACD00: nop
    
            goto L_800ACD70;
    }
    // 0x800ACD00: nop

    // 0x800ACD04: b           L_800ACD7C
    // 0x800ACD08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ACD7C;
    // 0x800ACD08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ACD0C:
    // 0x800ACD0C: slti        $at, $a0, 0x18C
    ctx->r1 = SIGNED(ctx->r4) < 0X18C ? 1 : 0;
    // 0x800ACD10: bne         $at, $zero, L_800ACD30
    if (ctx->r1 != 0) {
        // 0x800ACD14: addiu       $at, $zero, 0x1BF
        ctx->r1 = ADD32(0, 0X1BF);
            goto L_800ACD30;
    }
    // 0x800ACD14: addiu       $at, $zero, 0x1BF
    ctx->r1 = ADD32(0, 0X1BF);
    // 0x800ACD18: beq         $a0, $at, L_800ACD70
    if (ctx->r4 == ctx->r1) {
        // 0x800ACD1C: addiu       $at, $zero, 0x1C0
        ctx->r1 = ADD32(0, 0X1C0);
            goto L_800ACD70;
    }
    // 0x800ACD1C: addiu       $at, $zero, 0x1C0
    ctx->r1 = ADD32(0, 0X1C0);
    // 0x800ACD20: beq         $a0, $at, L_800ACD70
    if (ctx->r4 == ctx->r1) {
        // 0x800ACD24: nop
    
            goto L_800ACD70;
    }
    // 0x800ACD24: nop

    // 0x800ACD28: b           L_800ACD7C
    // 0x800ACD2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ACD7C;
    // 0x800ACD2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ACD30:
    // 0x800ACD30: slti        $at, $a0, 0xA0
    ctx->r1 = SIGNED(ctx->r4) < 0XA0 ? 1 : 0;
    // 0x800ACD34: bne         $at, $zero, L_800ACD50
    if (ctx->r1 != 0) {
        // 0x800ACD38: addiu       $t8, $a0, -0x96
        ctx->r24 = ADD32(ctx->r4, -0X96);
            goto L_800ACD50;
    }
    // 0x800ACD38: addiu       $t8, $a0, -0x96
    ctx->r24 = ADD32(ctx->r4, -0X96);
    // 0x800ACD3C: addiu       $at, $zero, 0x18B
    ctx->r1 = ADD32(0, 0X18B);
    // 0x800ACD40: beq         $a0, $at, L_800ACD70
    if (ctx->r4 == ctx->r1) {
        // 0x800ACD44: nop
    
            goto L_800ACD70;
    }
    // 0x800ACD44: nop

    // 0x800ACD48: b           L_800ACD7C
    // 0x800ACD4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ACD7C;
    // 0x800ACD4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ACD50:
    // 0x800ACD50: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x800ACD54: beq         $at, $zero, L_800ACD78
    if (ctx->r1 == 0) {
        // 0x800ACD58: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800ACD78;
    }
    // 0x800ACD58: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800ACD5C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800ACD60: addu        $at, $at, $t8
    gpr jr_addend_800ACD68 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800ACD64: lw          $t8, -0x7A50($at)
    ctx->r24 = ADD32(ctx->r1, -0X7A50);
    // 0x800ACD68: jr          $t8
    // 0x800ACD6C: nop

    switch (jr_addend_800ACD68 >> 2) {
        case 0: goto L_800ACD70; break;
        case 1: goto L_800ACD70; break;
        case 2: goto L_800ACD70; break;
        case 3: goto L_800ACD70; break;
        case 4: goto L_800ACD70; break;
        case 5: goto L_800ACD70; break;
        case 6: goto L_800ACD70; break;
        case 7: goto L_800ACD70; break;
        case 8: goto L_800ACD70; break;
        case 9: goto L_800ACD70; break;
        default: switch_error(__func__, 0x800ACD68, 0x801085B0);
    }
    // 0x800ACD6C: nop

L_800ACD70:
    // 0x800ACD70: jr          $ra
    // 0x800ACD74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800ACD74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ACD78:
    // 0x800ACD78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ACD7C:
    // 0x800ACD7C: jr          $ra
    // 0x800ACD80: nop

    return;
    // 0x800ACD80: nop

;}
RECOMP_FUNC void func_80063470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063470: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80063474: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80063478: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006347C: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x80063480: lui         $s5, 0x8022
    ctx->r21 = S32(0X8022 << 16);
    // 0x80063484: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80063488: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006348C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80063490: addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
    // 0x80063494: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80063498: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8006349C: addiu       $s5, $s5, -0x5B00
    ctx->r21 = ADD32(ctx->r21, -0X5B00);
    // 0x800634A0: addiu       $s1, $s1, -0x1988
    ctx->r17 = ADD32(ctx->r17, -0X1988);
    // 0x800634A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800634A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
L_800634AC:
    // 0x800634AC: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800634B0: beq         $at, $zero, L_80063570
    if (ctx->r1 == 0) {
        // 0x800634B4: sll         $t6, $s3, 1
        ctx->r14 = S32(ctx->r19 << 1);
            goto L_80063570;
    }
    // 0x800634B4: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800634B8: addu        $t1, $s5, $t6
    ctx->r9 = ADD32(ctx->r21, ctx->r14);
    // 0x800634BC: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x800634C0: addiu       $s0, $s4, -0x1
    ctx->r16 = ADD32(ctx->r20, -0X1);
    // 0x800634C4: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x800634C8: multu       $t7, $s2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800634CC: sll         $t3, $s3, 1
    ctx->r11 = S32(ctx->r19 << 1);
    // 0x800634D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800634D4: addu        $a3, $s5, $t3
    ctx->r7 = ADD32(ctx->r21, ctx->r11);
    // 0x800634D8: addu        $a2, $s5, $t2
    ctx->r6 = ADD32(ctx->r21, ctx->r10);
    // 0x800634DC: mflo        $t8
    ctx->r24 = lo;
    // 0x800634E0: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x800634E4: lh          $a1, 0x14($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, 0X14));
L_800634E8:
    // 0x800634E8: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
L_800634EC:
    // 0x800634EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800634F0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800634F4: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800634F8: mflo        $t4
    ctx->r12 = lo;
    // 0x800634FC: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x80063500: lh          $t6, 0x14($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X14));
    // 0x80063504: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80063508: bnel        $at, $zero, L_800634EC
    if (ctx->r1 != 0) {
        // 0x8006350C: lhu         $v0, 0x2($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X2);
            goto L_800634EC;
    }
    goto skip_0;
    // 0x8006350C: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    skip_0:
    // 0x80063510: lhu         $v1, -0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, -0X2);
L_80063514:
    // 0x80063514: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80063518: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // 0x8006351C: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063520: mflo        $t7
    ctx->r15 = lo;
    // 0x80063524: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80063528: lh          $t9, 0x14($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X14));
    // 0x8006352C: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80063530: bnel        $at, $zero, L_80063514
    if (ctx->r1 != 0) {
        // 0x80063534: lhu         $v1, -0x2($a3)
        ctx->r3 = MEM_HU(ctx->r7, -0X2);
            goto L_80063514;
    }
    goto skip_1;
    // 0x80063534: lhu         $v1, -0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, -0X2);
    skip_1:
    // 0x80063538: sh          $v1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r3;
    // 0x8006353C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80063540: bne         $at, $zero, L_800634E8
    if (ctx->r1 != 0) {
        // 0x80063544: sh          $v0, 0x0($a3)
        MEM_H(0X0, ctx->r7) = ctx->r2;
            goto L_800634E8;
    }
    // 0x80063544: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x80063548: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x8006354C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80063550: addiu       $a1, $s0, -0x1
    ctx->r5 = ADD32(ctx->r16, -0X1);
    // 0x80063554: sh          $t2, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r10;
    // 0x80063558: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8006355C: sh          $t3, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r11;
    // 0x80063560: jal         0x80063470
    // 0x80063564: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    func_80063470(rdram, ctx);
        goto after_0;
    // 0x80063564: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_0:
    // 0x80063568: b           L_800634AC
    // 0x8006356C: addiu       $s4, $s0, 0x1
    ctx->r20 = ADD32(ctx->r16, 0X1);
        goto L_800634AC;
    // 0x8006356C: addiu       $s4, $s0, 0x1
    ctx->r20 = ADD32(ctx->r16, 0X1);
L_80063570:
    // 0x80063570: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80063574: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80063578: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8006357C: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80063580: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80063584: lw          $s4, 0x24($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80063588: lw          $s5, 0x28($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8006358C: jr          $ra
    // 0x80063590: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80063590: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void parseifelse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B6EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B6F0: beq         $a0, $zero, L_8008B718
    if (ctx->r4 == 0) {
        // 0x8008B6F4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8008B718;
    }
    // 0x8008B6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B6F8: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x8008B6FC: addiu       $v1, $v1, 0x2320
    ctx->r3 = ADD32(ctx->r3, 0X2320);
    // 0x8008B700: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8008B704: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8008B708: jal         0x8008B794
    // 0x8008B70C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    parse(rdram, ctx);
        goto after_0;
    // 0x8008B70C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_0:
    // 0x8008B710: b           L_8008B788
    // 0x8008B714: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8008B788;
    // 0x8008B714: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8008B718:
    // 0x8008B718: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x8008B71C: addiu       $v1, $v1, 0x2320
    ctx->r3 = ADD32(ctx->r3, 0X2320);
    // 0x8008B720: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8008B724: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8008B728: addiu       $t0, $t0, -0x1700
    ctx->r8 = ADD32(ctx->r8, -0X1700);
    // 0x8008B72C: lw          $t9, 0x4($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X4));
    // 0x8008B730: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8008B734: addiu       $t1, $t1, -0x4480
    ctx->r9 = ADD32(ctx->r9, -0X4480);
    // 0x8008B738: sltu        $at, $t9, $t0
    ctx->r1 = ctx->r25 < ctx->r8 ? 1 : 0;
    // 0x8008B73C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008B740: bne         $at, $zero, L_8008B750
    if (ctx->r1 != 0) {
        // 0x8008B744: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8008B750;
    }
    // 0x8008B744: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8008B748: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x8008B74C: beq         $at, $zero, L_8008B768
    if (ctx->r1 == 0) {
        // 0x8008B750: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_8008B768;
    }
L_8008B750:
    // 0x8008B750: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8008B754: jal         0x80099460
    // 0x8008B758: addiu       $a0, $a0, 0x5AF4
    ctx->r4 = ADD32(ctx->r4, 0X5AF4);
    gameexit(rdram, ctx);
        goto after_1;
    // 0x8008B758: addiu       $a0, $a0, 0x5AF4
    ctx->r4 = ADD32(ctx->r4, 0X5AF4);
    after_1:
    // 0x8008B75C: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x8008B760: addiu       $v1, $v1, 0x2320
    ctx->r3 = ADD32(ctx->r3, 0X2320);
    // 0x8008B764: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
L_8008B768:
    // 0x8008B768: lw          $t2, 0x0($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8008B76C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008B770: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8008B774: bnel        $t2, $at, L_8008B788
    if (ctx->r10 != ctx->r1) {
        // 0x8008B778: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8008B788;
    }
    goto skip_0;
    // 0x8008B778: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x8008B77C: jal         0x8008B794
    // 0x8008B780: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    parse(rdram, ctx);
        goto after_2;
    // 0x8008B780: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    after_2:
    // 0x8008B784: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8008B788:
    // 0x8008B788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B78C: jr          $ra
    // 0x8008B790: nop

    return;
    // 0x8008B790: nop

;}
RECOMP_FUNC void mulscale24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FF80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FF88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FF8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FF90: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FF94: jal         0x800BB8F8
    // 0x8008FF98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FF98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FF9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FFA0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FFA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FFA8: jal         0x800BBA24
    // 0x8008FFAC: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FFAC: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_1:
    // 0x8008FFB0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FFB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FFBC: jr          $ra
    // 0x8008FFC0: nop

    return;
    // 0x8008FFC0: nop

;}
RECOMP_FUNC void __vsDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA6C0: lw          $t6, 0x24($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X24));
    // 0x800CA6C4: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800CA6C8: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x800CA6CC: bltz        $v1, L_800CA6DC
    if (SIGNED(ctx->r3) < 0) {
        // 0x800CA6D0: nop
    
            goto L_800CA6DC;
    }
    // 0x800CA6D0: nop

    // 0x800CA6D4: jr          $ra
    // 0x800CA6D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800CA6D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800CA6DC:
    // 0x800CA6DC: jr          $ra
    // 0x800CA6E0: nop

    return;
    // 0x800CA6E0: nop

;}
RECOMP_FUNC void xyzsound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058A48: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80058A4C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80058A50: lh          $t6, 0x62($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X62));
    // 0x80058A54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80058A58: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80058A5C: slti        $at, $t6, 0x12D
    ctx->r1 = SIGNED(ctx->r14) < 0X12D ? 1 : 0;
    // 0x80058A60: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80058A64: bne         $at, $zero, L_80058A74
    if (ctx->r1 != 0) {
        // 0x80058A68: sw          $a3, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r7;
            goto L_80058A74;
    }
    // 0x80058A68: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80058A6C: b           L_80058E0C
    // 0x80058A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80058E0C;
    // 0x80058A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058A74:
    // 0x80058A74: lh          $t7, 0x62($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X62));
    // 0x80058A78: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x80058A7C: addiu       $t9, $t9, 0xB00
    ctx->r25 = ADD32(ctx->r25, 0XB00);
    // 0x80058A80: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80058A84: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80058A88: lw          $v1, 0xC($t0)
    ctx->r3 = S32(MEM_W(ctx->r8, 0XC));
    // 0x80058A8C: lh          $t2, 0x62($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X62));
    // 0x80058A90: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80058A94: bne         $at, $zero, L_80058AA4
    if (ctx->r1 != 0) {
        // 0x80058A98: nop
    
            goto L_80058AA4;
    }
    // 0x80058A98: nop

    // 0x80058A9C: b           L_80058E0C
    // 0x80058AA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80058E0C;
    // 0x80058AA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058AA4:
    // 0x80058AA4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80058AA8: addiu       $a1, $a1, -0xB68
    ctx->r5 = ADD32(ctx->r5, -0XB68);
    // 0x80058AAC: addu        $t1, $a1, $t2
    ctx->r9 = ADD32(ctx->r5, ctx->r10);
    // 0x80058AB0: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80058AB4: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x80058AB8: beq         $t3, $zero, L_80058AD0
    if (ctx->r11 == 0) {
        // 0x80058ABC: andi        $t4, $v0, 0x80
        ctx->r12 = ctx->r2 & 0X80;
            goto L_80058AD0;
    }
    // 0x80058ABC: andi        $t4, $v0, 0x80
    ctx->r12 = ctx->r2 & 0X80;
    // 0x80058AC0: blez        $v1, L_80058AD0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80058AC4: nop
    
            goto L_80058AD0;
    }
    // 0x80058AC4: nop

    // 0x80058AC8: b           L_80058E0C
    // 0x80058ACC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80058E0C;
    // 0x80058ACC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058AD0:
    // 0x80058AD0: beq         $t4, $zero, L_80058AE8
    if (ctx->r12 == 0) {
        // 0x80058AD4: andi        $t5, $v0, 0x4
        ctx->r13 = ctx->r2 & 0X4;
            goto L_80058AE8;
    }
    // 0x80058AD4: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x80058AD8: jal         0x80058E1C
    // 0x80058ADC: lh          $a0, 0x62($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X62));
    sound(rdram, ctx);
        goto after_0;
    // 0x80058ADC: lh          $a0, 0x62($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X62));
    after_0:
    // 0x80058AE0: b           L_80058E0C
    // 0x80058AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80058E0C;
    // 0x80058AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80058AE8:
    // 0x80058AE8: beq         $t5, $zero, L_80058B48
    if (ctx->r13 == 0) {
        // 0x80058AEC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80058B48;
    }
    // 0x80058AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80058AF0: lui         $a2, 0x802A
    ctx->r6 = S32(0X802A << 16);
    // 0x80058AF4: addiu       $a2, $a2, 0xB00
    ctx->r6 = ADD32(ctx->r6, 0XB00);
    // 0x80058AF8: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80058AFC:
    // 0x80058AFC: lw          $v1, 0xC($a2)
    ctx->r3 = S32(MEM_W(ctx->r6, 0XC));
    // 0x80058B00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058B04: blezl       $v1, L_80058B40
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80058B08: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80058B40;
    }
    goto skip_0;
    // 0x80058B08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
L_80058B0C:
    // 0x80058B0C: blez        $v1, L_80058B2C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80058B10: addu        $t6, $a1, $a0
        ctx->r14 = ADD32(ctx->r5, ctx->r4);
            goto L_80058B2C;
    }
    // 0x80058B10: addu        $t6, $a1, $a0
    ctx->r14 = ADD32(ctx->r5, ctx->r4);
    // 0x80058B14: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80058B18: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80058B1C: beql        $t8, $zero, L_80058B30
    if (ctx->r24 == 0) {
        // 0x80058B20: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80058B30;
    }
    goto skip_1;
    // 0x80058B20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80058B24: b           L_80058E0C
    // 0x80058B28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80058E0C;
    // 0x80058B28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058B2C:
    // 0x80058B2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80058B30:
    // 0x80058B30: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058B34: bne         $at, $zero, L_80058B0C
    if (ctx->r1 != 0) {
        // 0x80058B38: nop
    
            goto L_80058B0C;
    }
    // 0x80058B38: nop

    // 0x80058B3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80058B40:
    // 0x80058B40: bne         $a0, $a3, L_80058AFC
    if (ctx->r4 != ctx->r7) {
        // 0x80058B44: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80058AFC;
    }
    // 0x80058B44: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80058B48:
    // 0x80058B48: lh          $a0, 0x66($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X66));
    // 0x80058B4C: lh          $a1, 0x62($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X62));
    // 0x80058B50: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80058B54: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80058B58: jal         0x8005878C
    // 0x80058B5C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    func_8005878C(rdram, ctx);
        goto after_1;
    // 0x80058B5C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_1:
    // 0x80058B60: bne         $v0, $zero, L_80058B70
    if (ctx->r2 != 0) {
        // 0x80058B64: sb          $v0, 0x57($sp)
        MEM_B(0X57, ctx->r29) = ctx->r2;
            goto L_80058B70;
    }
    // 0x80058B64: sb          $v0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r2;
    // 0x80058B68: b           L_80058E0C
    // 0x80058B6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80058E0C;
    // 0x80058B6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058B70:
    // 0x80058B70: lh          $v0, 0x62($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X62));
    // 0x80058B74: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80058B78: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80058B7C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80058B80: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80058B84: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80058B88: lh          $a1, -0xDC0($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0XDC0));
    // 0x80058B8C: lh          $v1, -0x1018($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, -0X1018));
    // 0x80058B90: sh          $a1, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r5;
    // 0x80058B94: subu        $a0, $v1, $a1
    ctx->r4 = SUB32(ctx->r3, ctx->r5);
    // 0x80058B98: jal         0x80091A38
    // 0x80058B9C: sh          $v1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r3;
    klabs(rdram, ctx);
        goto after_2;
    // 0x80058B9C: sh          $v1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80058BA0: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80058BA4: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80058BA8: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80058BAC: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80058BB0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80058BB4: lh          $v1, 0x5C($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X5C));
    // 0x80058BB8: beq         $t4, $zero, L_80058C7C
    if (ctx->r12 == 0) {
        // 0x80058BBC: lh          $a1, 0x5A($sp)
        ctx->r5 = S32(MEM_H(ctx->r29, 0X5A));
            goto L_80058C7C;
    }
    // 0x80058BBC: lh          $a1, 0x5A($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x80058BC0: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058BC4: beql        $at, $zero, L_80058C28
    if (ctx->r1 == 0) {
        // 0x80058BC8: sh          $v1, 0x5C($sp)
        MEM_H(0X5C, ctx->r29) = ctx->r3;
            goto L_80058C28;
    }
    goto skip_2;
    // 0x80058BC8: sh          $v1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r3;
    skip_2:
    // 0x80058BCC: sh          $t2, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r10;
    // 0x80058BD0: jal         0x8009800C
    // 0x80058BD4: sh          $a1, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r5;
    krand2(rdram, ctx);
        goto after_3;
    // 0x80058BD4: sh          $a1, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r5;
    after_3:
    // 0x80058BD8: lh          $a0, 0x58($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X58));
    // 0x80058BDC: lh          $a1, 0x5A($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x80058BE0: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80058BE4: mfhi        $t5
    ctx->r13 = hi;
    // 0x80058BE8: addu        $t1, $t5, $a1
    ctx->r9 = ADD32(ctx->r13, ctx->r5);
    // 0x80058BEC: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x80058BF0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80058BF4: bne         $a0, $zero, L_80058C00
    if (ctx->r4 != 0) {
        // 0x80058BF8: nop
    
            goto L_80058C00;
    }
    // 0x80058BF8: nop

    // 0x80058BFC: break       7
    do_break(2147847164);
L_80058C00:
    // 0x80058C00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058C04: bne         $a0, $at, L_80058C18
    if (ctx->r4 != ctx->r1) {
        // 0x80058C08: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80058C18;
    }
    // 0x80058C08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80058C0C: bne         $v0, $at, L_80058C18
    if (ctx->r2 != ctx->r1) {
        // 0x80058C10: nop
    
            goto L_80058C18;
    }
    // 0x80058C10: nop

    // 0x80058C14: break       6
    do_break(2147847188);
L_80058C18:
    // 0x80058C18: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80058C1C: b           L_80058C8C
    // 0x80058C20: lh          $v0, 0x62($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X62));
        goto L_80058C8C;
    // 0x80058C20: lh          $v0, 0x62($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X62));
    // 0x80058C24: sh          $v1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r3;
L_80058C28:
    // 0x80058C28: jal         0x8009800C
    // 0x80058C2C: sh          $a0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r4;
    krand2(rdram, ctx);
        goto after_4;
    // 0x80058C2C: sh          $a0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r4;
    after_4:
    // 0x80058C30: lh          $a0, 0x58($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X58));
    // 0x80058C34: lh          $v1, 0x5C($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X5C));
    // 0x80058C38: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80058C3C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80058C40: addu        $t1, $t8, $v1
    ctx->r9 = ADD32(ctx->r24, ctx->r3);
    // 0x80058C44: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x80058C48: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80058C4C: bne         $a0, $zero, L_80058C58
    if (ctx->r4 != 0) {
        // 0x80058C50: nop
    
            goto L_80058C58;
    }
    // 0x80058C50: nop

    // 0x80058C54: break       7
    do_break(2147847252);
L_80058C58:
    // 0x80058C58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058C5C: bne         $a0, $at, L_80058C70
    if (ctx->r4 != ctx->r1) {
        // 0x80058C60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80058C70;
    }
    // 0x80058C60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80058C64: bne         $v0, $at, L_80058C70
    if (ctx->r2 != ctx->r1) {
        // 0x80058C68: nop
    
            goto L_80058C70;
    }
    // 0x80058C68: nop

    // 0x80058C6C: break       6
    do_break(2147847276);
L_80058C70:
    // 0x80058C70: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x80058C74: b           L_80058C8C
    // 0x80058C78: lh          $v0, 0x62($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X62));
        goto L_80058C8C;
    // 0x80058C78: lh          $v0, 0x62($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X62));
L_80058C7C:
    // 0x80058C7C: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x80058C80: sra         $t3, $t1, 16
    ctx->r11 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80058C84: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
    // 0x80058C88: lh          $v0, 0x62($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X62));
L_80058C8C:
    // 0x80058C8C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80058C90: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x80058C94: beq         $v0, $at, L_80058CB4
    if (ctx->r2 == ctx->r1) {
        // 0x80058C98: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80058CB4;
    }
    // 0x80058C98: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80058C9C: beq         $v0, $at, L_80058CB4
    if (ctx->r2 == ctx->r1) {
        // 0x80058CA0: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80058CB4;
    }
    // 0x80058CA0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80058CA4: beq         $v0, $at, L_80058CB4
    if (ctx->r2 == ctx->r1) {
        // 0x80058CA8: addiu       $at, $zero, 0x10F
        ctx->r1 = ADD32(0, 0X10F);
            goto L_80058CB4;
    }
    // 0x80058CA8: addiu       $at, $zero, 0x10F
    ctx->r1 = ADD32(0, 0X10F);
    // 0x80058CAC: bne         $v0, $at, L_80058D14
    if (ctx->r2 != ctx->r1) {
        // 0x80058CB0: lui         $t3, 0x8022
        ctx->r11 = S32(0X8022 << 16);
            goto L_80058D14;
    }
    // 0x80058CB0: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
L_80058CB4:
    // 0x80058CB4: lbu         $t4, -0x5C08($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X5C08);
    // 0x80058CB8: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x80058CBC: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80058CC0: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80058CC4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80058CC8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80058CCC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80058CD0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80058CD4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80058CD8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80058CDC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80058CE0: lh          $t6, 0x59F8($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X59F8));
    // 0x80058CE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058CE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80058CEC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80058CF0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80058CF4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80058CF8: lh          $t8, -0x1970($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X1970));
    // 0x80058CFC: bne         $t8, $at, L_80058D7C
    if (ctx->r24 != ctx->r1) {
        // 0x80058D00: nop
    
            goto L_80058D7C;
    }
    // 0x80058D00: nop

    // 0x80058D04: addiu       $t1, $t1, -0x400
    ctx->r9 = ADD32(ctx->r9, -0X400);
    // 0x80058D08: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x80058D0C: b           L_80058D7C
    // 0x80058D10: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
        goto L_80058D7C;
    // 0x80058D10: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
L_80058D14:
    // 0x80058D14: lbu         $t3, -0x5C08($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X5C08);
    // 0x80058D18: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x80058D1C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80058D20: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80058D24: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80058D28: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80058D2C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80058D30: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80058D34: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80058D38: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80058D3C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80058D40: lh          $t5, 0x59F8($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X59F8));
    // 0x80058D44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058D48: lw          $t8, 0x30($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80058D4C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80058D50: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80058D54: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80058D58: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80058D5C: lh          $t7, -0x1970($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X1970));
    // 0x80058D60: bne         $t7, $at, L_80058D7C
    if (ctx->r15 != ctx->r1) {
        // 0x80058D64: nop
    
            goto L_80058D7C;
    }
    // 0x80058D64: nop

    // 0x80058D68: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80058D6C: andi        $t2, $t9, 0x4
    ctx->r10 = ctx->r25 & 0X4;
    // 0x80058D70: bne         $t2, $zero, L_80058D7C
    if (ctx->r10 != 0) {
        // 0x80058D74: nop
    
            goto L_80058D7C;
    }
    // 0x80058D74: nop

    // 0x80058D78: addiu       $t1, $zero, -0x300
    ctx->r9 = ADD32(0, -0X300);
L_80058D7C:
    // 0x80058D7C: jal         0x80058A30
    // 0x80058D80: sh          $t1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r9;
    func_80058A30(rdram, ctx);
        goto after_5;
    // 0x80058D80: sh          $t1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r9;
    after_5:
    // 0x80058D84: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80058D88: lh          $t1, 0x5E($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X5E));
    // 0x80058D8C: lbu         $t3, -0x5C08($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X5C08);
    // 0x80058D90: lh          $a0, 0x62($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X62));
    // 0x80058D94: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x80058D98: lh          $a2, 0x66($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X66));
    // 0x80058D9C: lw          $a3, 0x50($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80058DA0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80058DA4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80058DA8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80058DAC: jal         0x80058428
    // 0x80058DB0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    func_80058428(rdram, ctx);
        goto after_6;
    // 0x80058DB0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_6:
    // 0x80058DB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058DB8: bne         $v0, $at, L_80058DC8
    if (ctx->r2 != ctx->r1) {
        // 0x80058DBC: lw          $t0, 0x4C($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
            goto L_80058DC8;
    }
    // 0x80058DBC: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80058DC0: b           L_80058E0C
    // 0x80058DC4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80058E0C;
    // 0x80058DC4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058DC8:
    // 0x80058DC8: lw          $a1, 0x38($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80058DCC: lh          $t4, 0x62($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X62));
    // 0x80058DD0: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x80058DD4: lw          $v1, 0xC($a1)
    ctx->r3 = S32(MEM_W(ctx->r5, 0XC));
    // 0x80058DD8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80058DDC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80058DE0: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80058DE4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80058DE8: lh          $t9, 0x66($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X66));
    // 0x80058DEC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80058DF0: addiu       $t8, $t8, 0x1DC0
    ctx->r24 = ADD32(ctx->r24, 0X1DC0);
    // 0x80058DF4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80058DF8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80058DFC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80058E00: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80058E04: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x80058E08: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
L_80058E0C:
    // 0x80058E0C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80058E10: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80058E14: jr          $ra
    // 0x80058E18: nop

    return;
    // 0x80058E18: nop

;}
RECOMP_FUNC void func_800703A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800703A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800703AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800703B0: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x800703B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800703B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800703BC: beq         $v0, $zero, L_800703EC
    if (ctx->r2 == 0) {
        // 0x800703C0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800703EC;
    }
    // 0x800703C0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800703C4: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x800703C8: addiu       $a0, $a0, -0x1330
    ctx->r4 = ADD32(ctx->r4, -0X1330);
    // 0x800703CC: lw          $t0, 0x0($a0)
    ctx->r8 = S32(MEM_W(ctx->r4, 0X0));
    // 0x800703D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800703D4: lw          $t6, 0x8($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800703D8: sllv        $t8, $t7, $v0
    ctx->r24 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x800703DC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800703E0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800703E4: beql        $t6, $t1, L_80070430
    if (ctx->r14 == ctx->r9) {
        // 0x800703E8: lbu         $a0, 0xD($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0XD);
            goto L_80070430;
    }
    goto skip_0;
    // 0x800703E8: lbu         $a0, 0xD($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XD);
    skip_0:
L_800703EC:
    // 0x800703EC: lhu         $v0, 0x1C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1C);
L_800703F0:
    // 0x800703F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800703F4: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x800703F8: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x800703FC: addiu       $a0, $a0, -0x1330
    ctx->r4 = ADD32(ctx->r4, -0X1330);
    // 0x80070400: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80070404: beq         $v0, $zero, L_800703EC
    if (ctx->r2 == 0) {
        // 0x80070408: or          $a1, $t2, $zero
        ctx->r5 = ctx->r10 | 0;
            goto L_800703EC;
    }
    // 0x80070408: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8007040C: lw          $t8, 0x0($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80070410: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80070414: lw          $t3, 0x8($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X8));
    // 0x80070418: sllv        $t5, $t4, $v0
    ctx->r13 = S32(ctx->r12 << (ctx->r2 & 31));
    // 0x8007041C: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x80070420: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80070424: bnel        $t3, $t9, L_800703F0
    if (ctx->r11 != ctx->r25) {
        // 0x80070428: lhu         $v0, 0x1C($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X1C);
            goto L_800703F0;
    }
    goto skip_1;
    // 0x80070428: lhu         $v0, 0x1C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1C);
    skip_1:
    // 0x8007042C: lbu         $a0, 0xD($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XD);
L_80070430:
    // 0x80070430: jal         0x800702D4
    // 0x80070434: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    func_800702D4(rdram, ctx);
        goto after_0;
    // 0x80070434: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    after_0:
    // 0x80070438: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8007043C: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80070440: beq         $at, $zero, L_80070450
    if (ctx->r1 == 0) {
        // 0x80070444: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80070450;
    }
    // 0x80070444: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80070448: b           L_80070478
    // 0x8007044C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80070478;
    // 0x8007044C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80070450:
    // 0x80070450: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x80070454: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80070458: jal         0x800702D4
    // 0x8007045C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800702D4(rdram, ctx);
        goto after_1;
    // 0x8007045C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80070460: lw          $a1, 0x18($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80070464: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80070468: sllv        $t6, $t0, $a1
    ctx->r14 = S32(ctx->r8 << (ctx->r5 & 31));
    // 0x8007046C: or          $v0, $v0, $t6
    ctx->r2 = ctx->r2 | ctx->r14;
    // 0x80070470: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80070474: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80070478:
    // 0x80070478: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8007047C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80070480: jr          $ra
    // 0x80070484: nop

    return;
    // 0x80070484: nop

;}
RECOMP_FUNC void mulscale25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FFC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FFC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FFCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FFD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FFD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FFD8: jal         0x800BB8F8
    // 0x8008FFDC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FFDC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FFE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FFE4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FFE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FFEC: jal         0x800BBA24
    // 0x8008FFF0: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FFF0: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    after_1:
    // 0x8008FFF4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FFF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FFFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80090000: jr          $ra
    // 0x80090004: nop

    return;
    // 0x80090004: nop

;}
RECOMP_FUNC void func_80063BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063BB8: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80063BBC: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80063BC0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80063BC4: addiu       $s0, $s0, -0x6520
    ctx->r16 = ADD32(ctx->r16, -0X6520);
    // 0x80063BC8: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063BCC: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80063BD0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80063BD4: ldc1        $f20, 0x4D68($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X4D68);
    // 0x80063BD8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80063BDC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80063BE0: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80063BE4: addiu       $v0, $v0, -0x5B58
    ctx->r2 = ADD32(ctx->r2, -0X5B58);
    // 0x80063BE8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80063BEC: lwc1        $f6, 0x4D70($at)
    ctx->f6.u32l = S32(MEM_W(ctx->r1, 0X4D70));
    // 0x80063BF0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = S32(MEM_W(ctx->r2, 0X0));
    // 0x80063BF4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80063BF8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80063BFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80063C00: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x80063C04: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80063C08: jal         0x800C2DB0
    // 0x80063C0C: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x80063C0C: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x80063C10: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063C14: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80063C18: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80063C1C: jal         0x800C2BF0
    // 0x80063C20: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80063C20: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_1:
    // 0x80063C24: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063C28: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x80063C2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80063C30: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80063C34: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80063C38: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x80063C3C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80063C40: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80063C44: swc1        $f18, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f18.u32l;
    // 0x80063C48: jal         0x800C2BF0
    // 0x80063C4C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80063C4C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_2:
    // 0x80063C50: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063C54: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80063C58: div.d       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f20.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f20.d);
    // 0x80063C5C: jal         0x800C2DB0
    // 0x80063C60: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x80063C60: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_3:
    // 0x80063C64: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80063C68: lw          $t6, -0x1990($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X1990));
    // 0x80063C6C: lui         $at, 0x4400
    ctx->r1 = S32(0X4400 << 16);
    // 0x80063C70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80063C74: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80063C78: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80063C7C: addiu       $t9, $t8, 0x190
    ctx->r25 = ADD32(ctx->r24, 0X190);
    // 0x80063C80: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80063C84: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80063C88: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80063C8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80063C90: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80063C94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80063C98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80063C9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80063CA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80063CA4: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80063CA8: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x80063CAC: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x80063CB0: addiu       $a1, $sp, 0xFE
    ctx->r5 = ADD32(ctx->r29, 0XFE);
    // 0x80063CB4: sub.s       $f20, $f22, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x80063CB8: swc1        $f10, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f10.u32l;
    // 0x80063CBC: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80063CC0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80063CC4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80063CC8: jal         0x800C3130
    // 0x80063CCC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_4;
    // 0x80063CCC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80063CD0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80063CD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80063CD8: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x80063CDC: addiu       $s1, $s1, -0x2904
    ctx->r17 = ADD32(ctx->r17, -0X2904);
    // 0x80063CE0: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80063CE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80063CE8: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    // 0x80063CEC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80063CF0: addiu       $s0, $s0, 0x4410
    ctx->r16 = ADD32(ctx->r16, 0X4410);
    // 0x80063CF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80063CF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80063CFC: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063D00: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80063D04: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x80063D08: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x80063D0C: addiu       $a1, $sp, 0xFE
    ctx->r5 = ADD32(ctx->r29, 0XFE);
    // 0x80063D10: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80063D14: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80063D18: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80063D1C: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x80063D20: jal         0x800C3360
    // 0x80063D24: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    guPerspective(rdram, ctx);
        goto after_5;
    // 0x80063D24: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80063D28: lhu         $t7, 0xFE($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XFE);
    // 0x80063D2C: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = S32(MEM_W(ctx->r29, 0X108));
    // 0x80063D30: lwc1        $f16, 0x10C($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X10C));
    // 0x80063D34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80063D38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80063D3C: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80063D40: sh          $t7, -0x1478($at)
    MEM_H(-0X1478, ctx->r1) = ctx->r15;
    // 0x80063D44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063D48: lwc1        $f2, -0x5B70($at)
    ctx->f2.u32l = S32(MEM_W(ctx->r1, -0X5B70));
    // 0x80063D4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063D50: lwc1        $f12, -0x5B6C($at)
    ctx->f12.u32l = S32(MEM_W(ctx->r1, -0X5B6C));
    // 0x80063D54: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80063D58: add.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80063D5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063D60: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80063D64: lwc1        $f14, -0x5B68($at)
    ctx->f14.u32l = S32(MEM_W(ctx->r1, -0X5B68));
    // 0x80063D68: add.s       $f4, $f20, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f12.fl;
    // 0x80063D6C: mul.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80063D70: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80063D74: add.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80063D78: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80063D7C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80063D80: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80063D84: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80063D88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80063D8C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80063D90: mul.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80063D94: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80063D98: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80063D9C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80063DA0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80063DA4: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    // 0x80063DA8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80063DAC: jal         0x800C33C0
    // 0x80063DB0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    guLookAtF(rdram, ctx);
        goto after_6;
    // 0x80063DB0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80063DB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80063DB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80063DBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063DC0: lwc1        $f2, -0x5B70($at)
    ctx->f2.u32l = S32(MEM_W(ctx->r1, -0X5B70));
    // 0x80063DC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063DC8: lwc1        $f12, -0x5B6C($at)
    ctx->f12.u32l = S32(MEM_W(ctx->r1, -0X5B6C));
    // 0x80063DCC: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80063DD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063DD4: lwc1        $f14, -0x5B68($at)
    ctx->f14.u32l = S32(MEM_W(ctx->r1, -0X5B68));
    // 0x80063DD8: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80063DDC: lwc1        $f6, 0x108($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X108));
    // 0x80063DE0: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80063DE4: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80063DE8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80063DEC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80063DF0: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063DF4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80063DF8: add.s       $f16, $f20, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f20.fl + ctx->f12.fl;
    // 0x80063DFC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80063E00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80063E04: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X10C));
    // 0x80063E08: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80063E0C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80063E10: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80063E14: sll         $t5, $t9, 6
    ctx->r13 = S32(ctx->r25 << 6);
    // 0x80063E18: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80063E1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80063E20: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80063E24: addu        $v0, $t8, $t5
    ctx->r2 = ADD32(ctx->r24, ctx->r13);
    // 0x80063E28: addiu       $a0, $v0, 0x100
    ctx->r4 = ADD32(ctx->r2, 0X100);
    // 0x80063E2C: addiu       $a1, $v0, 0x200
    ctx->r5 = ADD32(ctx->r2, 0X200);
    // 0x80063E30: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80063E34: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    // 0x80063E38: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80063E3C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80063E40: jal         0x800C3B30
    // 0x80063E44: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    guLookAtReflect(rdram, ctx);
        goto after_7;
    // 0x80063E44: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80063E48: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80063E4C: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x80063E50: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80063E54: lui         $t6, 0x384
    ctx->r14 = S32(0X384 << 16);
    // 0x80063E58: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80063E5C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80063E60: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80063E64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80063E68: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80063E6C: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063E70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80063E74: sll         $t8, $t9, 6
    ctx->r24 = S32(ctx->r25 << 6);
    // 0x80063E78: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x80063E7C: addiu       $t4, $t5, 0x200
    ctx->r12 = ADD32(ctx->r13, 0X200);
    // 0x80063E80: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80063E84: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80063E88: lui         $t9, 0x382
    ctx->r25 = S32(0X382 << 16);
    // 0x80063E8C: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x80063E90: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80063E94: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80063E98: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80063E9C: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80063EA0: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063EA4: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x80063EA8: sll         $t5, $t8, 6
    ctx->r13 = S32(ctx->r24 << 6);
    // 0x80063EAC: addu        $t4, $t7, $t5
    ctx->r12 = ADD32(ctx->r15, ctx->r13);
    // 0x80063EB0: addiu       $t6, $t4, 0x210
    ctx->r14 = ADD32(ctx->r12, 0X210);
    // 0x80063EB4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80063EB8: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80063EBC: lui         $t8, 0x103
    ctx->r24 = S32(0X103 << 16);
    // 0x80063EC0: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x80063EC4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80063EC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80063ECC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80063ED0: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    // 0x80063ED4: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063ED8: addiu       $a2, $a2, -0x1390
    ctx->r6 = ADD32(ctx->r6, -0X1390);
    // 0x80063EDC: sll         $t4, $t5, 6
    ctx->r12 = S32(ctx->r13 << 6);
    // 0x80063EE0: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80063EE4: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x80063EE8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80063EEC: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80063EF0: lui         $t5, 0x101
    ctx->r13 = S32(0X101 << 16);
    // 0x80063EF4: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x80063EF8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80063EFC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80063F00: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80063F04: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x80063F08: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80063F0C: ori         $at, $at, 0x100
    ctx->r1 = ctx->r1 | 0X100;
    // 0x80063F10: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x80063F14: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80063F18: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x80063F1C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80063F20: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80063F24: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80063F28: ori         $t4, $t4, 0xE
    ctx->r12 = ctx->r12 | 0XE;
    // 0x80063F2C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80063F30: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80063F34: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80063F38: lhu         $t7, 0xFE($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XFE);
    // 0x80063F3C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80063F40: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80063F44: jal         0x800C3C50
    // 0x80063F48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    guMtxCatF(rdram, ctx);
        goto after_8;
    // 0x80063F48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_8:
    // 0x80063F4C: lw          $ra, 0x4C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80063F50: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80063F54: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x80063F58: lw          $s0, 0x44($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80063F5C: lw          $s1, 0x48($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80063F60: jr          $ra
    // 0x80063F64: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x80063F64: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_8005669C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005669C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800566A0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800566A4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800566A8: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800566AC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800566B0: lwc1        $f8, 0x45F0($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, 0X45F0));
    // 0x800566B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800566B8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800566BC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800566C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800566C4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800566C8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800566CC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800566D0: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x800566D4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800566D8: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800566DC: addiu       $s4, $s4, -0x2904
    ctx->r20 = ADD32(ctx->r20, -0X2904);
    // 0x800566E0: lbu         $t8, 0x0($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X0);
    // 0x800566E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800566E8: addiu       $s0, $a2, -0x6800
    ctx->r16 = ADD32(ctx->r6, -0X6800);
    // 0x800566EC: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800566F0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800566F4: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x800566F8: addiu       $s3, $s3, 0x4410
    ctx->r19 = ADD32(ctx->r19, 0X4410);
    // 0x800566FC: lw          $t7, 0x0($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80056700: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80056704: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80056708: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x8005670C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80056710: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80056714: addiu       $a0, $a0, 0x480
    ctx->r4 = ADD32(ctx->r4, 0X480);
    // 0x80056718: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8005671C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80056720: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
    // 0x80056724: bgez        $s2, L_80056734
    if (SIGNED(ctx->r18) >= 0) {
        // 0x80056728: sra         $t5, $s2, 2
        ctx->r13 = S32(SIGNED(ctx->r18) >> 2);
            goto L_80056734;
    }
    // 0x80056728: sra         $t5, $s2, 2
    ctx->r13 = S32(SIGNED(ctx->r18) >> 2);
    // 0x8005672C: addiu       $at, $s2, 0x3
    ctx->r1 = ADD32(ctx->r18, 0X3);
    // 0x80056730: sra         $t5, $at, 2
    ctx->r13 = S32(SIGNED(ctx->r1) >> 2);
L_80056734:
    // 0x80056734: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80056738: nop

    // 0x8005673C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80056740: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80056744: bgez        $s5, L_80056754
    if (SIGNED(ctx->r21) >= 0) {
        // 0x80056748: sra         $t6, $s5, 2
        ctx->r14 = S32(SIGNED(ctx->r21) >> 2);
            goto L_80056754;
    }
    // 0x80056748: sra         $t6, $s5, 2
    ctx->r14 = S32(SIGNED(ctx->r21) >> 2);
    // 0x8005674C: addiu       $at, $s5, 0x3
    ctx->r1 = ADD32(ctx->r21, 0X3);
    // 0x80056750: sra         $t6, $at, 2
    ctx->r14 = S32(SIGNED(ctx->r1) >> 2);
L_80056754:
    // 0x80056754: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80056758: nop

    // 0x8005675C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80056760: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80056764: bgez        $s0, L_80056774
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80056768: sra         $t8, $s0, 5
        ctx->r24 = S32(SIGNED(ctx->r16) >> 5);
            goto L_80056774;
    }
    // 0x80056768: sra         $t8, $s0, 5
    ctx->r24 = S32(SIGNED(ctx->r16) >> 5);
    // 0x8005676C: addiu       $at, $s0, 0x1F
    ctx->r1 = ADD32(ctx->r16, 0X1F);
    // 0x80056770: sra         $t8, $at, 5
    ctx->r24 = S32(SIGNED(ctx->r1) >> 5);
L_80056774:
    // 0x80056774: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80056778: nop

    // 0x8005677C: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80056780: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80056784: jal         0x800BD8C8
    // 0x80056788: nop

    guTranslate(rdram, ctx);
        goto after_0;
    // 0x80056788: nop

    after_0:
    // 0x8005678C: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x80056790: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80056794: lbu         $t9, 0x0($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X0);
    // 0x80056798: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005679C: lw          $t7, 0x0($s3)
    ctx->r15 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800567A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800567A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800567A8: sll         $t5, $t9, 6
    ctx->r13 = S32(ctx->r25 << 6);
    // 0x800567AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800567B0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800567B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800567B8: addu        $a0, $t7, $t5
    ctx->r4 = ADD32(ctx->r15, ctx->r13);
    // 0x800567BC: addiu       $a0, $a0, 0x500
    ctx->r4 = ADD32(ctx->r4, 0X500);
    // 0x800567C0: jal         0x800BF694
    // 0x800567C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    guRotate(rdram, ctx);
        goto after_1;
    // 0x800567C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800567C8: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x800567CC: addiu       $s2, $s2, 0x4418
    ctx->r18 = ADD32(ctx->r18, 0X4418);
    // 0x800567D0: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800567D4: lui         $t8, 0x106
    ctx->r24 = S32(0X106 << 16);
    // 0x800567D8: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x800567DC: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800567E0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800567E4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800567E8: lbu         $t7, 0x0($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X0);
    // 0x800567EC: lw          $t9, 0x0($s3)
    ctx->r25 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800567F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800567F4: sll         $t5, $t7, 6
    ctx->r13 = S32(ctx->r15 << 6);
    // 0x800567F8: ori         $at, $at, 0x480
    ctx->r1 = ctx->r1 | 0X480;
    // 0x800567FC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80056800: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x80056804: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80056808: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8005680C: lui         $t9, 0x100
    ctx->r25 = S32(0X100 << 16);
    // 0x80056810: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x80056814: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80056818: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8005681C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056820: lbu         $t6, 0x0($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X0);
    // 0x80056824: lw          $t5, 0x0($s3)
    ctx->r13 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80056828: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005682C: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x80056830: ori         $at, $at, 0x500
    ctx->r1 = ctx->r1 | 0X500;
    // 0x80056834: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x80056838: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x8005683C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80056840: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056844: addiu       $t8, $zero, 0x3000
    ctx->r24 = ADD32(0, 0X3000);
    // 0x80056848: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8005684C: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80056850: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80056854: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80056858: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005685C: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056860: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80056864: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x80056868: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x8005686C: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80056870: ori         $t9, $t9, 0x1205
    ctx->r25 = ctx->r25 | 0X1205;
    // 0x80056874: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80056878: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005687C: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056880: lui         $t5, 0x4
    ctx->r13 = S32(0X4 << 16);
    // 0x80056884: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x80056888: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x8005688C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80056890: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80056894: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80056898: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8005689C: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x800568A0: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800568A4: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800568A8: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800568AC: ori         $t9, $t9, 0xF87C
    ctx->r25 = ctx->r25 | 0XF87C;
    // 0x800568B0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800568B4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800568B8: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800568BC: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800568C0: ori         $t5, $t5, 0x602
    ctx->r13 = ctx->r13 | 0X602;
    // 0x800568C4: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800568C8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800568CC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800568D0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800568D4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800568D8: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800568DC: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800568E0: ori         $t9, $t9, 0x1301
    ctx->r25 = ctx->r25 | 0X1301;
    // 0x800568E4: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800568E8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800568EC: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800568F0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800568F4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800568F8: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800568FC: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80056900: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x80056904: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80056908: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x8005690C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80056910: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056914: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056918: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8005691C: ori         $t9, $t9, 0xC02
    ctx->r25 = ctx->r25 | 0XC02;
    // 0x80056920: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80056924: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80056928: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x8005692C: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80056930: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056934: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056938: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8005693C: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x80056940: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80056944: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80056948: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005694C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80056950: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056954: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056958: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x8005695C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80056960: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80056964: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80056968: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x8005696C: ori         $t5, $t5, 0x3078
    ctx->r13 = ctx->r13 | 0X3078;
    // 0x80056970: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80056974: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80056978: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8005697C: lui         $t9, 0xFF33
    ctx->r25 = S32(0XFF33 << 16);
    // 0x80056980: lui         $t7, 0xFC12
    ctx->r15 = S32(0XFC12 << 16);
    // 0x80056984: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80056988: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8005698C: ori         $t7, $t7, 0x1824
    ctx->r15 = ctx->r15 | 0X1824;
    // 0x80056990: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80056994: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80056998: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005699C: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800569A0: addiu       $t2, $zero, -0x100
    ctx->r10 = ADD32(0, -0X100);
    // 0x800569A4: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800569A8: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800569AC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800569B0: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800569B4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800569B8: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800569BC: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800569C0: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x800569C4: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800569C8: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800569CC: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800569D0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800569D4: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800569D8: lui         $s7, 0x8022
    ctx->r23 = S32(0X8022 << 16);
    // 0x800569DC: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x800569E0: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800569E4: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800569E8: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800569EC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800569F0: addiu       $fp, $fp, -0x2352
    ctx->r30 = ADD32(ctx->r30, -0X2352);
    // 0x800569F4: addiu       $s7, $s7, -0x2354
    ctx->r23 = ADD32(ctx->r23, -0X2354);
    // 0x800569F8: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
    // 0x800569FC: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
    // 0x80056A00: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80056A04: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80056A08: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80056A0C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80056A10: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80056A14: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    // 0x80056A18: addiu       $v0, $v0, -0x537C
    ctx->r2 = ADD32(ctx->r2, -0X537C);
    // 0x80056A1C: addiu       $a0, $a0, -0x4200
    ctx->r4 = ADD32(ctx->r4, -0X4200);
    // 0x80056A20: addiu       $a3, $a3, 0x4858
    ctx->r7 = ADD32(ctx->r7, 0X4858);
    // 0x80056A24: addiu       $a2, $a2, 0x39B0
    ctx->r6 = ADD32(ctx->r6, 0X39B0);
    // 0x80056A28: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80056A2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80056A30:
    // 0x80056A30: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80056A34:
    // 0x80056A34: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x80056A38: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056A3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80056A40: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80056A44: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80056A48: lh          $t9, 0x0($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X0));
    // 0x80056A4C: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80056A50: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80056A54: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x80056A58: lhu         $t5, -0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, -0X2);
    // 0x80056A5C: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056A60: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80056A64: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80056A68: lh          $t9, 0x2($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X2));
    // 0x80056A6C: sh          $t9, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r25;
    // 0x80056A70: lhu         $t5, -0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, -0X2);
    // 0x80056A74: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056A78: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80056A7C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80056A80: lh          $t9, 0x4($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X4));
    // 0x80056A84: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
    // 0x80056A88: lhu         $t5, -0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, -0X2);
    // 0x80056A8C: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056A90: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80056A94: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80056A98: lh          $t9, 0x6($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X6));
    // 0x80056A9C: sh          $t9, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r25;
    // 0x80056AA0: lhu         $t5, -0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, -0X2);
    // 0x80056AA4: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056AA8: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80056AAC: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80056AB0: lh          $t9, 0x8($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X8));
    // 0x80056AB4: sh          $t9, 0xA($t6)
    MEM_H(0XA, ctx->r14) = ctx->r25;
    // 0x80056AB8: lhu         $t5, -0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, -0X2);
    // 0x80056ABC: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056AC0: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80056AC4: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80056AC8: lh          $t9, 0xA($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0XA));
    // 0x80056ACC: sb          $t9, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r25;
    // 0x80056AD0: lhu         $t5, -0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, -0X2);
    // 0x80056AD4: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056AD8: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80056ADC: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80056AE0: lh          $t9, 0xC($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0XC));
    // 0x80056AE4: sb          $t9, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r25;
    // 0x80056AE8: lhu         $t5, -0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, -0X2);
    // 0x80056AEC: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056AF0: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80056AF4: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80056AF8: lh          $t9, 0xE($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0XE));
    // 0x80056AFC: sb          $t9, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r25;
    // 0x80056B00: lw          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056B04: sb          $a1, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r5;
    // 0x80056B08: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80056B0C: addiu       $t7, $t8, 0x10
    ctx->r15 = ADD32(ctx->r24, 0X10);
    // 0x80056B10: bne         $at, $zero, L_80056A34
    if (ctx->r1 != 0) {
        // 0x80056B14: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80056A34;
    }
    // 0x80056B14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80056B18: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80056B1C: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x80056B20: bnel        $at, $zero, L_80056A30
    if (ctx->r1 != 0) {
        // 0x80056B24: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80056A30;
    }
    goto skip_0;
    // 0x80056B24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_0:
    // 0x80056B28: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056B2C: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x80056B30: lui         $t5, 0x4
    ctx->r13 = S32(0X4 << 16);
    // 0x80056B34: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80056B38: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80056B3C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80056B40: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80056B44: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056B48: lui         $s6, 0xBB00
    ctx->r22 = S32(0XBB00 << 16);
    // 0x80056B4C: ori         $s6, $s6, 0x1
    ctx->r22 = ctx->r22 | 0X1;
    // 0x80056B50: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80056B54: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80056B58: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80056B5C: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x80056B60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80056B64: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80056B68: addiu       $s4, $s4, 0x39B0
    ctx->r20 = ADD32(ctx->r20, 0X39B0);
    // 0x80056B6C: lui         $s5, 0x6
    ctx->r21 = S32(0X6 << 16);
    // 0x80056B70: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80056B74: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
L_80056B78:
    // 0x80056B78: lhu         $t9, 0x6($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X6);
    // 0x80056B7C: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80056B80: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80056B84: beq         $s3, $t9, L_80056D0C
    if (ctx->r19 == ctx->r25) {
        // 0x80056B88: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80056D0C;
    }
    // 0x80056B88: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80056B8C: jal         0x800616A8
    // 0x80056B90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800616A8(rdram, ctx);
        goto after_2;
    // 0x80056B90: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_2:
    // 0x80056B94: lhu         $s3, 0x6($s4)
    ctx->r19 = MEM_HU(ctx->r20, 0X6);
    // 0x80056B98: addiu       $at, $zero, 0xE54
    ctx->r1 = ADD32(0, 0XE54);
    // 0x80056B9C: bne         $s3, $zero, L_80056C18
    if (ctx->r19 != 0) {
        // 0x80056BA0: nop
    
            goto L_80056C18;
    }
    // 0x80056BA0: nop

    // 0x80056BA4: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
    // 0x80056BA8: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
    // 0x80056BAC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80056BB0: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    // 0x80056BB4: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056BB8: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x80056BBC: lui         $t9, 0xFC0
    ctx->r25 = S32(0XFC0 << 16);
    // 0x80056BC0: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80056BC4: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80056BC8: sw          $s5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r21;
    // 0x80056BCC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056BD0: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056BD4: ori         $t9, $t9, 0xFC0
    ctx->r25 = ctx->r25 | 0XFC0;
    // 0x80056BD8: addiu       $a0, $zero, 0xE54
    ctx->r4 = ADD32(0, 0XE54);
    // 0x80056BDC: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80056BE0: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80056BE4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80056BE8: jal         0x80061904
    // 0x80056BEC: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    func_80061904(rdram, ctx);
        goto after_3;
    // 0x80056BEC: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    after_3:
    // 0x80056BF0: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056BF4: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x80056BF8: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x80056BFC: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80056C00: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80056C04: ori         $t8, $t8, 0xF87C
    ctx->r24 = ctx->r24 | 0XF87C;
    // 0x80056C08: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x80056C0C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80056C10: b           L_80056D0C
    // 0x80056C14: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_80056D0C;
    // 0x80056C14: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_80056C18:
    // 0x80056C18: bne         $s3, $at, L_80056C9C
    if (ctx->r19 != ctx->r1) {
        // 0x80056C1C: lui         $t8, 0xB600
        ctx->r24 = S32(0XB600 << 16);
            goto L_80056C9C;
    }
    // 0x80056C1C: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x80056C20: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
    // 0x80056C24: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
    // 0x80056C28: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80056C2C: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    // 0x80056C30: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056C34: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x80056C38: lui         $t5, 0xFC0
    ctx->r13 = S32(0XFC0 << 16);
    // 0x80056C3C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80056C40: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80056C44: sw          $s5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r21;
    // 0x80056C48: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056C4C: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056C50: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80056C54: ori         $t5, $t5, 0xFC0
    ctx->r13 = ctx->r13 | 0XFC0;
    // 0x80056C58: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80056C5C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80056C60: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80056C64: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80056C68: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80056C6C: jal         0x80061904
    // 0x80056C70: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    func_80061904(rdram, ctx);
        goto after_4;
    // 0x80056C70: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    after_4:
    // 0x80056C74: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056C78: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80056C7C: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x80056C80: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80056C84: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80056C88: ori         $t6, $t6, 0xF87C
    ctx->r14 = ctx->r14 | 0XF87C;
    // 0x80056C8C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80056C90: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80056C94: b           L_80056D0C
    // 0x80056C98: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
        goto L_80056D0C;
    // 0x80056C98: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_80056C9C:
    // 0x80056C9C: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
    // 0x80056CA0: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
    // 0x80056CA4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80056CA8: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    // 0x80056CAC: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056CB0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80056CB4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80056CB8: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80056CBC: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80056CC0: sw          $s5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r21;
    // 0x80056CC4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056CC8: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056CCC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80056CD0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80056CD4: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80056CD8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80056CDC: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80056CE0: jal         0x80061904
    // 0x80056CE4: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    func_80061904(rdram, ctx);
        goto after_5;
    // 0x80056CE4: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    after_5:
    // 0x80056CE8: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056CEC: lui         $t8, 0xFC12
    ctx->r24 = S32(0XFC12 << 16);
    // 0x80056CF0: lui         $t7, 0xFF33
    ctx->r15 = S32(0XFF33 << 16);
    // 0x80056CF4: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80056CF8: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80056CFC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80056D00: ori         $t8, $t8, 0x1824
    ctx->r24 = ctx->r24 | 0X1824;
    // 0x80056D04: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056D08: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_80056D0C:
    // 0x80056D0C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80056D10: addiu       $t9, $t9, 0x4858
    ctx->r25 = ADD32(ctx->r25, 0X4858);
    // 0x80056D14: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80056D18: bne         $s4, $t9, L_80056B78
    if (ctx->r20 != ctx->r25) {
        // 0x80056D1C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80056B78;
    }
    // 0x80056D1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80056D20: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80056D24: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80056D28: jal         0x800616A8
    // 0x80056D2C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800616A8(rdram, ctx);
        goto after_6;
    // 0x80056D2C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_6:
    // 0x80056D30: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056D34: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x80056D38: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x80056D3C: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80056D40: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80056D44: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80056D48: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80056D4C: lw          $s0, 0x0($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80056D50: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80056D54: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80056D58: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80056D5C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80056D60: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80056D64: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x80056D68: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80056D6C: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
    // 0x80056D70: sh          $zero, 0x0($fp)
    MEM_H(0X0, ctx->r30) = 0;
    // 0x80056D74: lw          $fp, 0x40($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80056D78: lw          $s7, 0x3C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80056D7C: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80056D80: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80056D84: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80056D88: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80056D8C: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80056D90: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80056D94: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80056D98: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
    // 0x80056D9C: jr          $ra
    // 0x80056DA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80056DA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800B788C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B788C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B7890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B7894: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B7898: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800B789C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800B78A0:
    // 0x800B78A0: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    // 0x800B78A4: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x800B78A8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800B78AC: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800B78B0: beq         $t6, $t7, L_800B78C0
    if (ctx->r14 == ctx->r15) {
        // 0x800B78B4: nop
    
            goto L_800B78C0;
    }
    // 0x800B78B4: nop

    // 0x800B78B8: jr          $ra
    // 0x800B78BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B78BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B78C0:
    // 0x800B78C0: bne         $a2, $v0, L_800B78A0
    if (ctx->r6 != ctx->r2) {
        // 0x800B78C4: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_800B78A0;
    }
    // 0x800B78C4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800B78C8: jr          $ra
    // 0x800B78CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B78CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void guLookAtReflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3B30: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800C3B34: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X88));
    // 0x800C3B38: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800C3B3C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800C3B40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C3B44: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0XA0));
    // 0x800C3B48: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800C3B4C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X90));
    // 0x800C3B50: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X94));
    // 0x800C3B54: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X98));
    // 0x800C3B58: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800C3B5C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C3B60: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800C3B64: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800C3B68: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800C3B6C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800C3B70: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800C3B74: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C3B78: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C3B7C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800C3B80: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800C3B84: jal         0x800C36F0
    // 0x800C3B88: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    guLookAtReflectF(rdram, ctx);
        goto after_0;
    // 0x800C3B88: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800C3B8C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800C3B90: jal         0x800C8AC0
    // 0x800C3B94: lw          $a1, 0x78($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X78));
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800C3B94: lw          $a1, 0x78($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X78));
    after_1:
    // 0x800C3B98: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800C3B9C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x800C3BA0: jr          $ra
    // 0x800C3BA4: nop

    return;
    // 0x800C3BA4: nop

;}
