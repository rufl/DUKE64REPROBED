#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80064A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064A54: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80064A58: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80064A5C: addiu       $v0, $v0, -0x25D0
    ctx->r2 = ADD32(ctx->r2, -0X25D0);
    // 0x80064A60: addiu       $v1, $v1, -0x2790
    ctx->r3 = ADD32(ctx->r3, -0X2790);
L_80064A64:
    // 0x80064A64: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80064A68: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80064A6C: bne         $at, $zero, L_80064A64
    if (ctx->r1 != 0) {
        // 0x80064A70: sb          $zero, -0x1C($v1)
        MEM_B(-0X1C, ctx->r3) = 0;
            goto L_80064A64;
    }
    // 0x80064A70: sb          $zero, -0x1C($v1)
    MEM_B(-0X1C, ctx->r3) = 0;
    // 0x80064A74: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x80064A78: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80064A7C: addiu       $v0, $v0, -0x2798
    ctx->r2 = ADD32(ctx->r2, -0X2798);
    // 0x80064A80: addiu       $v1, $v1, -0x28F8
    ctx->r3 = ADD32(ctx->r3, -0X28F8);
L_80064A84:
    // 0x80064A84: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80064A88: sb          $zero, -0x42($v1)
    MEM_B(-0X42, ctx->r3) = 0;
    // 0x80064A8C: sb          $zero, -0x2C($v1)
    MEM_B(-0X2C, ctx->r3) = 0;
    // 0x80064A90: sb          $zero, -0x16($v1)
    MEM_B(-0X16, ctx->r3) = 0;
    // 0x80064A94: bne         $v1, $v0, L_80064A84
    if (ctx->r3 != ctx->r2) {
        // 0x80064A98: sb          $zero, -0x58($v1)
        MEM_B(-0X58, ctx->r3) = 0;
            goto L_80064A84;
    }
    // 0x80064A98: sb          $zero, -0x58($v1)
    MEM_B(-0X58, ctx->r3) = 0;
    // 0x80064A9C: jr          $ra
    // 0x80064AA0: nop

    return;
    // 0x80064AA0: nop

;}
RECOMP_FUNC void timerupdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B9E4: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x8004B9E8: lui         $v1, 0x8028
    ctx->r3 = S32(0X8028 << 16);
    // 0x8004B9EC: addiu       $v1, $v1, -0x68C8
    ctx->r3 = ADD32(ctx->r3, -0X68C8);
    // 0x8004B9F0: addiu       $v0, $v0, -0x5370
    ctx->r2 = ADD32(ctx->r2, -0X5370);
    // 0x8004B9F4: lw          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8004B9F8: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004B9FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004BA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004BA04: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8004BA08: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8004BA0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8004BA10: jal         0x80071EEC
    // 0x8004BA14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    agecache(rdram, ctx);
        goto after_0;
    // 0x8004BA14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_0:
    // 0x8004BA18: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8004BA1C: lb          $t0, 0x36C8($t0)
    ctx->r8 = S32(MEM_B(ctx->r8, 0X36C8));
    // 0x8004BA20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004BA24: bnel        $t0, $at, L_8004BA40
    if (ctx->r8 != ctx->r1) {
        // 0x8004BA28: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_8004BA40;
    }
    goto skip_0;
    // 0x8004BA28: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x8004BA2C: jal         0x8004D950
    // 0x8004BA30: nop

    gameplay(rdram, ctx);
        goto after_1;
    // 0x8004BA30: nop

    after_1:
    // 0x8004BA34: jal         0x800662E4
    // 0x8004BA38: nop

    animatemodels(rdram, ctx);
        goto after_2;
    // 0x8004BA38: nop

    after_2:
    // 0x8004BA3C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004BA40:
    // 0x8004BA40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004BA44: jr          $ra
    // 0x8004BA48: nop

    return;
    // 0x8004BA48: nop

;}
RECOMP_FUNC void alCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFF10: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800CFF14: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800CFF18: blez        $a2, L_800CFF7C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800CFF1C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800CFF7C;
    }
    // 0x800CFF1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800CFF20: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x800CFF24: beq         $a1, $zero, L_800CFF4C
    if (ctx->r5 == 0) {
        // 0x800CFF28: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800CFF4C;
    }
    // 0x800CFF28: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800CFF2C:
    // 0x800CFF2C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800CFF30: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800CFF34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CFF38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CFF3C: bne         $a0, $a3, L_800CFF2C
    if (ctx->r4 != ctx->r7) {
        // 0x800CFF40: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_800CFF2C;
    }
    // 0x800CFF40: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800CFF44: beq         $a3, $a2, L_800CFF7C
    if (ctx->r7 == ctx->r6) {
        // 0x800CFF48: nop
    
            goto L_800CFF7C;
    }
    // 0x800CFF48: nop

L_800CFF4C:
    // 0x800CFF4C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800CFF50: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800CFF54: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800CFF58: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x800CFF5C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800CFF60: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800CFF64: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x800CFF68: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x800CFF6C: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x800CFF70: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x800CFF74: bne         $a3, $a2, L_800CFF4C
    if (ctx->r7 != ctx->r6) {
        // 0x800CFF78: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_800CFF4C;
    }
    // 0x800CFF78: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_800CFF7C:
    // 0x800CFF7C: jr          $ra
    // 0x800CFF80: nop

    return;
    // 0x800CFF80: nop

;}
RECOMP_FUNC void display_logos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055680: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x80055684: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80055688: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005568C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80055690: jal         0x800B76A0
    // 0x80055694: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_800B76A0(rdram, ctx);
        goto after_0;
    // 0x80055694: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80055698: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005569C: addiu       $v0, $v0, 0x39A0
    ctx->r2 = ADD32(ctx->r2, 0X39A0);
    // 0x800556A0: lb          $t6, 0x0($v0)
    ctx->r14 = S32(MEM_B(ctx->r2, 0X0));
    // 0x800556A4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800556A8: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800556AC: bne         $s2, $t6, L_800556F4
    if (ctx->r18 != ctx->r14) {
        // 0x800556B0: nop
    
            goto L_800556F4;
    }
    // 0x800556B0: nop

    // 0x800556B4: lhu         $t7, -0x5C42($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X5C42);
    // 0x800556B8: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x800556BC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800556C0: bne         $t7, $at, L_800556F4
    if (ctx->r15 != ctx->r1) {
        // 0x800556C4: nop
    
            goto L_800556F4;
    }
    // 0x800556C4: nop

    // 0x800556C8: lb          $t8, 0x3748($t8)
    ctx->r24 = S32(MEM_B(ctx->r24, 0X3748));
    // 0x800556CC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800556D0: addiu       $a0, $a0, 0x12AC
    ctx->r4 = ADD32(ctx->r4, 0X12AC);
    // 0x800556D4: bltz        $t8, L_800556F4
    if (SIGNED(ctx->r24) < 0) {
        // 0x800556D8: addiu       $t9, $zero, 0xC
        ctx->r25 = ADD32(0, 0XC);
            goto L_800556F4;
    }
    // 0x800556D8: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800556DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800556E0: sb          $t9, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r25;
    // 0x800556E4: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x800556E8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800556EC: b           L_8005612C
    // 0x800556F0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_8005612C;
    // 0x800556F0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800556F4:
    // 0x800556F4: jal         0x800524F0
    // 0x800556F8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_800524F0(rdram, ctx);
        goto after_1;
    // 0x800556F8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_1:
    // 0x800556FC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80055700: addiu       $v1, $v1, 0x3940
    ctx->r3 = ADD32(ctx->r3, 0X3940);
    // 0x80055704: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80055708: beq         $v0, $zero, L_80055734
    if (ctx->r2 == 0) {
        // 0x8005570C: nop
    
            goto L_80055734;
    }
    // 0x8005570C: nop

    // 0x80055710: beq         $v0, $s2, L_80055770
    if (ctx->r2 == ctx->r18) {
        // 0x80055714: lui         $s1, 0x800D
        ctx->r17 = S32(0X800D << 16);
            goto L_80055770;
    }
    // 0x80055714: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80055718: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005571C: beq         $v0, $at, L_800557AC
    if (ctx->r2 == ctx->r1) {
        // 0x80055720: lui         $a3, 0x800D
        ctx->r7 = S32(0X800D << 16);
            goto L_800557AC;
    }
    // 0x80055720: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80055724: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80055728: addiu       $s1, $s1, 0x393C
    ctx->r17 = ADD32(ctx->r17, 0X393C);
    // 0x8005572C: b           L_800557EC
    // 0x80055730: lh          $a3, 0x393C($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, 0X393C));
        goto L_800557EC;
    // 0x80055730: lh          $a3, 0x393C($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, 0X393C));
L_80055734:
    // 0x80055734: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80055738: addiu       $s1, $s1, 0x393C
    ctx->r17 = ADD32(ctx->r17, 0X393C);
    // 0x8005573C: lh          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_H(ctx->r17, 0X0));
    // 0x80055740: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80055744: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80055748: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x8005574C: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
    // 0x80055750: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    // 0x80055754: slti        $at, $a3, 0xFF
    ctx->r1 = SIGNED(ctx->r7) < 0XFF ? 1 : 0;
    // 0x80055758: bne         $at, $zero, L_800557EC
    if (ctx->r1 != 0) {
        // 0x8005575C: nop
    
            goto L_800557EC;
    }
    // 0x8005575C: nop

    // 0x80055760: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x80055764: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    // 0x80055768: b           L_800557EC
    // 0x8005576C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
        goto L_800557EC;
    // 0x8005576C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_80055770:
    // 0x80055770: addiu       $s1, $s1, 0x393C
    ctx->r17 = ADD32(ctx->r17, 0X393C);
    // 0x80055774: lh          $t5, 0x0($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, 0X0));
    // 0x80055778: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005577C: addiu       $t6, $t5, -0x10
    ctx->r14 = ADD32(ctx->r13, -0X10);
    // 0x80055780: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x80055784: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    // 0x80055788: bgtz        $a3, L_800557EC
    if (SIGNED(ctx->r7) > 0) {
        // 0x8005578C: nop
    
            goto L_800557EC;
    }
    // 0x8005578C: nop

    // 0x80055790: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80055794: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80055798: lb          $t7, 0x3934($t7)
    ctx->r15 = S32(MEM_B(ctx->r15, 0X3934));
    // 0x8005579C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800557A0: sb          $t7, 0x3930($at)
    MEM_B(0X3930, ctx->r1) = ctx->r15;
    // 0x800557A4: b           L_800557EC
    // 0x800557A8: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
        goto L_800557EC;
    // 0x800557A8: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
L_800557AC:
    // 0x800557AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800557B0: lw          $v0, 0x3938($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, 0X3938));
    // 0x800557B4: bne         $v0, $zero, L_800557D0
    if (ctx->r2 != 0) {
        // 0x800557B8: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800557D0;
    }
    // 0x800557B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800557BC: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800557C0: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x800557C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800557C8: b           L_800557DC
    // 0x800557CC: sw          $t9, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r25;
        goto L_800557DC;
    // 0x800557CC: sw          $t9, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r25;
L_800557D0:
    // 0x800557D0: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800557D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800557D8: sw          $t0, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r8;
L_800557DC:
    // 0x800557DC: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800557E0: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800557E4: addiu       $s1, $s1, 0x393C
    ctx->r17 = ADD32(ctx->r17, 0X393C);
    // 0x800557E8: lh          $a3, 0x393C($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, 0X393C));
L_800557EC:
    // 0x800557EC: lui         $t1, 0x8028
    ctx->r9 = S32(0X8028 << 16);
    // 0x800557F0: lhu         $t1, -0x5C42($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X5C42);
    // 0x800557F4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800557F8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800557FC: beq         $t1, $zero, L_8005582C
    if (ctx->r9 == 0) {
        // 0x80055800: lui         $t2, 0x800D
        ctx->r10 = S32(0X800D << 16);
            goto L_8005582C;
    }
    // 0x80055800: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80055804: lb          $t2, 0x3930($t2)
    ctx->r10 = S32(MEM_B(ctx->r10, 0X3930));
    // 0x80055808: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005580C: beq         $t2, $zero, L_8005582C
    if (ctx->r10 == 0) {
        // 0x80055810: nop
    
            goto L_8005582C;
    }
    // 0x80055810: nop

    // 0x80055814: lw          $t3, 0x3938($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X3938));
    // 0x80055818: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8005581C: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x80055820: bne         $at, $zero, L_8005582C
    if (ctx->r1 != 0) {
        // 0x80055824: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005582C;
    }
    // 0x80055824: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055828: sw          $t4, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r12;
L_8005582C:
    // 0x8005582C: jal         0x8006E994
    // 0x80055830: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    setrotatespriteflags(rdram, ctx);
        goto after_2;
    // 0x80055830: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_2:
    // 0x80055834: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80055838: addiu       $v0, $v0, 0x3930
    ctx->r2 = ADD32(ctx->r2, 0X3930);
    // 0x8005583C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80055840: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80055844: beq         $at, $zero, L_8005612C
    if (ctx->r1 == 0) {
        // 0x80055848: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8005612C;
    }
    // 0x80055848: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8005584C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80055850: addu        $at, $at, $t5
    gpr jr_addend_80055858 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80055854: lw          $t5, 0x452C($at)
    ctx->r13 = ADD32(ctx->r1, 0X452C);
    // 0x80055858: jr          $t5
    // 0x8005585C: nop

    switch (jr_addend_80055858 >> 2) {
        case 0: goto L_80055ACC; break;
        case 1: goto L_800558F8; break;
        case 2: goto L_80055860; break;
        case 3: goto L_80055B18; break;
        case 4: goto L_80055B30; break;
        case 5: goto L_80055D88; break;
        default: switch_error(__func__, 0x80055858, 0x8010452C);
    }
    // 0x8005585C: nop

L_80055860:
    // 0x80055860: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80055864: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80055868: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8005586C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80055870: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80055874: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80055878: addiu       $t6, $zero, 0xE09
    ctx->r14 = ADD32(0, 0XE09);
    // 0x8005587C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80055880: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80055884: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80055888: jal         0x8005D13C
    // 0x8005588C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_3;
    // 0x8005588C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x80055890: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80055894: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80055898: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8005589C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800558A0: addiu       $t7, $zero, 0xE5D
    ctx->r15 = ADD32(0, 0XE5D);
    // 0x800558A4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800558A8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800558AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800558B0: jal         0x8005D13C
    // 0x800558B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_4;
    // 0x800558B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x800558B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800558BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800558C0: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x800558C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800558C8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800558CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800558D0: addiu       $t8, $zero, 0xE5E
    ctx->r24 = ADD32(0, 0XE5E);
    // 0x800558D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800558D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800558DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800558E0: jal         0x8005D13C
    // 0x800558E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_5;
    // 0x800558E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x800558E8: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800558EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800558F0: b           L_8005612C
    // 0x800558F4: sb          $t9, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r25;
        goto L_8005612C;
    // 0x800558F4: sb          $t9, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r25;
L_800558F8:
    // 0x800558F8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800558FC: lbu         $t0, 0x3744($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3744);
    // 0x80055900: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055904: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80055908: bne         $t0, $zero, L_80055928
    if (ctx->r8 != 0) {
        // 0x8005590C: lui         $a3, 0x800D
        ctx->r7 = S32(0X800D << 16);
            goto L_80055928;
    }
    // 0x8005590C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80055910: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055914: jal         0x8006413C
    // 0x80055918: addiu       $a2, $a2, 0x42DC
    ctx->r6 = ADD32(ctx->r6, 0X42DC);
    menutext(rdram, ctx);
        goto after_6;
    // 0x80055918: addiu       $a2, $a2, 0x42DC
    ctx->r6 = ADD32(ctx->r6, 0X42DC);
    after_6:
    // 0x8005591C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055920: b           L_8005612C
    // 0x80055924: sw          $s2, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r18;
        goto L_8005612C;
    // 0x80055924: sw          $s2, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r18;
L_80055928:
    // 0x80055928: lb          $a3, 0x3748($a3)
    ctx->r7 = S32(MEM_B(ctx->r7, 0X3748));
    // 0x8005592C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055930: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055934: bne         $a3, $at, L_80055980
    if (ctx->r7 != ctx->r1) {
        // 0x80055938: addiu       $a1, $zero, 0x32
        ctx->r5 = ADD32(0, 0X32);
            goto L_80055980;
    }
    // 0x80055938: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8005593C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055940: jal         0x8006413C
    // 0x80055944: addiu       $a2, $a2, 0x42EC
    ctx->r6 = ADD32(ctx->r6, 0X42EC);
    menutext(rdram, ctx);
        goto after_7;
    // 0x80055944: addiu       $a2, $a2, 0x42EC
    ctx->r6 = ADD32(ctx->r6, 0X42EC);
    after_7:
    // 0x80055948: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8005594C: addiu       $a2, $a2, 0x4300
    ctx->r6 = ADD32(ctx->r6, 0X4300);
    // 0x80055950: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055954: jal         0x8006413C
    // 0x80055958: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    menutext(rdram, ctx);
        goto after_8;
    // 0x80055958: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_8:
    // 0x8005595C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055960: addiu       $a2, $a2, 0x4308
    ctx->r6 = ADD32(ctx->r6, 0X4308);
    // 0x80055964: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055968: jal         0x8006413C
    // 0x8005596C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    menutext(rdram, ctx);
        goto after_9;
    // 0x8005596C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_9:
    // 0x80055970: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80055974: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055978: b           L_8005612C
    // 0x8005597C: sb          $t1, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r9;
        goto L_8005612C;
    // 0x8005597C: sb          $t1, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r9;
L_80055980:
    // 0x80055980: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80055984: bne         $a3, $at, L_800559A4
    if (ctx->r7 != ctx->r1) {
        // 0x80055988: lui         $v1, 0x800D
        ctx->r3 = S32(0X800D << 16);
            goto L_800559A4;
    }
    // 0x80055988: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005598C: addiu       $v1, $v1, 0x3934
    ctx->r3 = ADD32(ctx->r3, 0X3934);
    // 0x80055990: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80055994: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80055998: lb          $t3, 0x0($v1)
    ctx->r11 = S32(MEM_B(ctx->r3, 0X0));
    // 0x8005599C: b           L_8005612C
    // 0x800559A0: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
        goto L_8005612C;
    // 0x800559A0: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_800559A4:
    // 0x800559A4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800559A8: bne         $a3, $at, L_80055A08
    if (ctx->r7 != ctx->r1) {
        // 0x800559AC: lui         $a2, 0x8010
        ctx->r6 = S32(0X8010 << 16);
            goto L_80055A08;
    }
    // 0x800559AC: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800559B0: addiu       $a2, $a2, 0x4320
    ctx->r6 = ADD32(ctx->r6, 0X4320);
    // 0x800559B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800559B8: jal         0x8006413C
    // 0x800559BC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    menutext(rdram, ctx);
        goto after_10;
    // 0x800559BC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_10:
    // 0x800559C0: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800559C4: addiu       $a2, $a2, 0x4330
    ctx->r6 = ADD32(ctx->r6, 0X4330);
    // 0x800559C8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800559CC: jal         0x8006413C
    // 0x800559D0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    menutext(rdram, ctx);
        goto after_11;
    // 0x800559D0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_11:
    // 0x800559D4: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800559D8: addiu       $a2, $a2, 0x4338
    ctx->r6 = ADD32(ctx->r6, 0X4338);
    // 0x800559DC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800559E0: jal         0x8006413C
    // 0x800559E4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    menutext(rdram, ctx);
        goto after_12;
    // 0x800559E4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_12:
    // 0x800559E8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800559EC: addiu       $a2, $a2, 0x4344
    ctx->r6 = ADD32(ctx->r6, 0X4344);
    // 0x800559F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800559F4: jal         0x8006413C
    // 0x800559F8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    menutext(rdram, ctx);
        goto after_13;
    // 0x800559F8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_13:
    // 0x800559FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055A00: b           L_8005612C
    // 0x80055A04: sw          $s2, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r18;
        goto L_8005612C;
    // 0x80055A04: sw          $s2, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r18;
L_80055A08:
    // 0x80055A08: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x80055A0C: lw          $t4, -0x6CC0($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X6CC0));
    // 0x80055A10: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x80055A14: bnel        $t4, $zero, L_80055AC0
    if (ctx->r12 != 0) {
        // 0x80055A18: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80055AC0;
    }
    goto skip_0;
    // 0x80055A18: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    skip_0:
    // 0x80055A1C: lw          $t5, -0x6CBC($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X6CBC));
    // 0x80055A20: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x80055A24: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055A28: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x80055A2C: beq         $at, $zero, L_80055A4C
    if (ctx->r1 == 0) {
        // 0x80055A30: addiu       $a1, $zero, 0x32
        ctx->r5 = ADD32(0, 0X32);
            goto L_80055A4C;
    }
    // 0x80055A30: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80055A34: lw          $t6, -0x6CB8($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X6CB8));
    // 0x80055A38: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80055A3C: addiu       $a2, $a3, 0x1
    ctx->r6 = ADD32(ctx->r7, 0X1);
    // 0x80055A40: slti        $at, $t6, 0x200
    ctx->r1 = SIGNED(ctx->r14) < 0X200 ? 1 : 0;
    // 0x80055A44: beq         $at, $zero, L_80055A88
    if (ctx->r1 == 0) {
        // 0x80055A48: nop
    
            goto L_80055A88;
    }
    // 0x80055A48: nop

L_80055A4C:
    // 0x80055A4C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055A50: jal         0x8006413C
    // 0x80055A54: addiu       $a2, $a2, 0x4350
    ctx->r6 = ADD32(ctx->r6, 0X4350);
    menutext(rdram, ctx);
        goto after_14;
    // 0x80055A54: addiu       $a2, $a2, 0x4350
    ctx->r6 = ADD32(ctx->r6, 0X4350);
    after_14:
    // 0x80055A58: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055A5C: addiu       $a2, $a2, 0x4360
    ctx->r6 = ADD32(ctx->r6, 0X4360);
    // 0x80055A60: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055A64: jal         0x8006413C
    // 0x80055A68: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    menutext(rdram, ctx);
        goto after_15;
    // 0x80055A68: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_15:
    // 0x80055A6C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055A70: addiu       $a2, $a2, 0x4368
    ctx->r6 = ADD32(ctx->r6, 0X4368);
    // 0x80055A74: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055A78: jal         0x8006413C
    // 0x80055A7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    menutext(rdram, ctx);
        goto after_16;
    // 0x80055A7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_16:
    // 0x80055A80: b           L_80055AC0
    // 0x80055A84: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
        goto L_80055AC0;
    // 0x80055A84: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80055A88:
    // 0x80055A88: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80055A8C: addiu       $a1, $a1, 0x4380
    ctx->r5 = ADD32(ctx->r5, 0X4380);
    // 0x80055A90: jal         0x800BD9E4
    // 0x80055A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_17;
    // 0x80055A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80055A98: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055A9C: addiu       $a2, $a2, 0x4398
    ctx->r6 = ADD32(ctx->r6, 0X4398);
    // 0x80055AA0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055AA4: jal         0x8006413C
    // 0x80055AA8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    menutext(rdram, ctx);
        goto after_18;
    // 0x80055AA8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_18:
    // 0x80055AAC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055AB0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80055AB4: jal         0x8006413C
    // 0x80055AB8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    menutext(rdram, ctx);
        goto after_19;
    // 0x80055AB8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_19:
    // 0x80055ABC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80055AC0:
    // 0x80055AC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055AC4: b           L_8005612C
    // 0x80055AC8: sb          $t7, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r15;
        goto L_8005612C;
    // 0x80055AC8: sb          $t7, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r15;
L_80055ACC:
    // 0x80055ACC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80055AD0: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80055AD4: addiu       $s1, $s1, 0x39A0
    ctx->r17 = ADD32(ctx->r17, 0X39A0);
    // 0x80055AD8: addiu       $s0, $s0, 0x3944
    ctx->r16 = ADD32(ctx->r16, 0X3944);
    // 0x80055ADC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80055AE0:
    // 0x80055AE0: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80055AE4: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80055AE8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80055AEC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055AF0: lw          $a2, 0x0($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80055AF4: jal         0x80063F68
    // 0x80055AF8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    gametext(rdram, ctx);
        goto after_20;
    // 0x80055AF8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_20:
    // 0x80055AFC: lw          $v0, 0x38($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80055B00: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80055B04: bne         $s0, $s1, L_80055AE0
    if (ctx->r16 != ctx->r17) {
        // 0x80055B08: addiu       $v0, $v0, 0x9
        ctx->r2 = ADD32(ctx->r2, 0X9);
            goto L_80055AE0;
    }
    // 0x80055B08: addiu       $v0, $v0, 0x9
    ctx->r2 = ADD32(ctx->r2, 0X9);
    // 0x80055B0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B10: b           L_8005612C
    // 0x80055B14: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
        goto L_8005612C;
    // 0x80055B14: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
L_80055B18:
    // 0x80055B18: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x80055B1C: addiu       $s0, $s0, 0x12A8
    ctx->r16 = ADD32(ctx->r16, 0X12A8);
    // 0x80055B20: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80055B24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B28: b           L_8005612C
    // 0x80055B2C: sb          $s2, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r18;
        goto L_8005612C;
    // 0x80055B2C: sb          $s2, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r18;
L_80055B30:
    // 0x80055B30: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055B34: addiu       $a2, $a2, 0x43A8
    ctx->r6 = ADD32(ctx->r6, 0X43A8);
    // 0x80055B38: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055B3C: jal         0x8006413C
    // 0x80055B40: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    menutext(rdram, ctx);
        goto after_21;
    // 0x80055B40: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_21:
    // 0x80055B44: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055B48: addiu       $a2, $a2, 0x43C0
    ctx->r6 = ADD32(ctx->r6, 0X43C0);
    // 0x80055B4C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055B50: jal         0x8006413C
    // 0x80055B54: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    menutext(rdram, ctx);
        goto after_22;
    // 0x80055B54: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_22:
    // 0x80055B58: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055B5C: addiu       $a2, $a2, 0x43C8
    ctx->r6 = ADD32(ctx->r6, 0X43C8);
    // 0x80055B60: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055B64: jal         0x8006413C
    // 0x80055B68: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    menutext(rdram, ctx);
        goto after_23;
    // 0x80055B68: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_23:
    // 0x80055B6C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055B70: addiu       $a2, $a2, 0x43E0
    ctx->r6 = ADD32(ctx->r6, 0X43E0);
    // 0x80055B74: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055B78: jal         0x8006413C
    // 0x80055B7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    menutext(rdram, ctx);
        goto after_24;
    // 0x80055B7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_24:
    // 0x80055B80: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055B84: addiu       $a2, $a2, 0x43F0
    ctx->r6 = ADD32(ctx->r6, 0X43F0);
    // 0x80055B88: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055B8C: jal         0x8006413C
    // 0x80055B90: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    menutext(rdram, ctx);
        goto after_25;
    // 0x80055B90: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_25:
    // 0x80055B94: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80055B98: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80055B9C: jal         0x8005C9BC
    // 0x80055BA0: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    rotatesprite_simplest(rdram, ctx);
        goto after_26;
    // 0x80055BA0: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    after_26:
    // 0x80055BA4: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x80055BA8: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x80055BAC: jal         0x8005C9BC
    // 0x80055BB0: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    rotatesprite_simplest(rdram, ctx);
        goto after_27;
    // 0x80055BB0: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    after_27:
    // 0x80055BB4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80055BB8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80055BBC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80055BC0: jal         0x8006E994
    // 0x80055BC4: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    setrotatespriteflags(rdram, ctx);
        goto after_28;
    // 0x80055BC4: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    after_28:
    // 0x80055BC8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055BCC: addiu       $a2, $a2, 0x4404
    ctx->r6 = ADD32(ctx->r6, 0X4404);
    // 0x80055BD0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055BD4: jal         0x8006413C
    // 0x80055BD8: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    menutext(rdram, ctx);
        goto after_29;
    // 0x80055BD8: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_29:
    // 0x80055BDC: lui         $t9, 0x8028
    ctx->r25 = S32(0X8028 << 16);
    // 0x80055BE0: lhu         $t9, -0x5C42($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X5C42);
    // 0x80055BE4: andi        $t0, $t9, 0xE000
    ctx->r8 = ctx->r25 & 0XE000;
    // 0x80055BE8: beq         $t0, $zero, L_80055D64
    if (ctx->r8 == 0) {
        // 0x80055BEC: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_80055D64;
    }
    // 0x80055BEC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80055BF0: addiu       $a0, $a0, 0x12AC
    ctx->r4 = ADD32(ctx->r4, 0X12AC);
    // 0x80055BF4: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80055BF8: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80055BFC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80055C00: lb          $t2, 0x374C($t2)
    ctx->r10 = S32(MEM_B(ctx->r10, 0X374C));
    // 0x80055C04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C08: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80055C0C: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80055C10: addiu       $s0, $s0, 0x38B8
    ctx->r16 = ADD32(ctx->r16, 0X38B8);
    // 0x80055C14: sb          $t2, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r10;
L_80055C18:
    // 0x80055C18: sb          $s2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r18;
    // 0x80055C1C: lb          $t3, 0x0($s0)
    ctx->r11 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055C20: bne         $s2, $t3, L_80055C3C
    if (ctx->r18 != ctx->r11) {
        // 0x80055C24: nop
    
            goto L_80055C3C;
    }
    // 0x80055C24: nop

L_80055C28:
    // 0x80055C28: jal         0x800BDDD0
    // 0x80055C2C: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_30;
    // 0x80055C2C: nop

    after_30:
    // 0x80055C30: lb          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055C34: beq         $s2, $t4, L_80055C28
    if (ctx->r18 == ctx->r12) {
        // 0x80055C38: nop
    
            goto L_80055C28;
    }
    // 0x80055C38: nop

L_80055C3C:
    // 0x80055C3C: jal         0x8004BD60
    // 0x80055C40: nop

    updatetime(rdram, ctx);
        goto after_31;
    // 0x80055C40: nop

    after_31:
    // 0x80055C44: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80055C48: lw          $t5, 0x38BC($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, 0X38BC));
    // 0x80055C4C: sltiu       $at, $t5, 0xC
    ctx->r1 = ctx->r13 < 0XC ? 1 : 0;
    // 0x80055C50: beq         $at, $zero, L_80055D64
    if (ctx->r1 == 0) {
        // 0x80055C54: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80055D64;
    }
    // 0x80055C54: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80055C58: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80055C5C: addu        $at, $at, $t5
    gpr jr_addend_80055C64 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80055C60: lw          $t5, 0x4544($at)
    ctx->r13 = ADD32(ctx->r1, 0X4544);
    // 0x80055C64: jr          $t5
    // 0x80055C68: nop

    switch (jr_addend_80055C64 >> 2) {
        case 0: goto L_80055C6C; break;
        case 1: goto L_80055CB4; break;
        case 2: goto L_80055C18; break;
        case 3: goto L_80055D64; break;
        case 4: goto L_80055D64; break;
        case 5: goto L_80055D64; break;
        case 6: goto L_80055D64; break;
        case 7: goto L_80055D64; break;
        case 8: goto L_80055D64; break;
        case 9: goto L_80055D64; break;
        case 10: goto L_80055CD4; break;
        case 11: goto L_80055CD4; break;
        default: switch_error(__func__, 0x80055C64, 0x80104544);
    }
    // 0x80055C68: nop

L_80055C6C:
    // 0x80055C6C: jal         0x80051D40
    // 0x80055C70: nop

    func_80051D40(rdram, ctx);
        goto after_32;
    // 0x80055C70: nop

    after_32:
    // 0x80055C74: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80055C78: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80055C7C: addiu       $a2, $a2, -0x6CBC
    ctx->r6 = ADD32(ctx->r6, -0X6CBC);
    // 0x80055C80: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    // 0x80055C84: jal         0x800BCFC0
    // 0x80055C88: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_33;
    // 0x80055C88: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_33:
    // 0x80055C8C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80055C90: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80055C94: addiu       $a1, $a1, -0x6CB8
    ctx->r5 = ADD32(ctx->r5, -0X6CB8);
    // 0x80055C98: jal         0x800BD110
    // 0x80055C9C: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_34;
    // 0x80055C9C: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    after_34:
    // 0x80055CA0: jal         0x80051D6C
    // 0x80055CA4: nop

    func_80051D6C(rdram, ctx);
        goto after_35;
    // 0x80055CA4: nop

    after_35:
    // 0x80055CA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055CAC: b           L_8005612C
    // 0x80055CB0: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
        goto L_8005612C;
    // 0x80055CB0: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
L_80055CB4:
    // 0x80055CB4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80055CB8: bne         $s1, $zero, L_80055C18
    if (ctx->r17 != 0) {
        // 0x80055CBC: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80055C18;
    }
    // 0x80055CBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055CC0: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
    // 0x80055CC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055CC8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80055CCC: b           L_8005612C
    // 0x80055CD0: sb          $t6, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r14;
        goto L_8005612C;
    // 0x80055CD0: sb          $t6, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r14;
L_80055CD4:
    // 0x80055CD4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80055CD8: addiu       $s0, $s0, 0x38C0
    ctx->r16 = ADD32(ctx->r16, 0X38C0);
    // 0x80055CDC: sb          $s2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r18;
    // 0x80055CE0: lb          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055CE4: bne         $s2, $t7, L_80055D00
    if (ctx->r18 != ctx->r15) {
        // 0x80055CE8: nop
    
            goto L_80055D00;
    }
    // 0x80055CE8: nop

L_80055CEC:
    // 0x80055CEC: jal         0x800BDDD0
    // 0x80055CF0: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_36;
    // 0x80055CF0: nop

    after_36:
    // 0x80055CF4: lb          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055CF8: beq         $s2, $t8, L_80055CEC
    if (ctx->r18 == ctx->r24) {
        // 0x80055CFC: nop
    
            goto L_80055CEC;
    }
    // 0x80055CFC: nop

L_80055D00:
    // 0x80055D00: jal         0x8004BD60
    // 0x80055D04: nop

    updatetime(rdram, ctx);
        goto after_37;
    // 0x80055D04: nop

    after_37:
    // 0x80055D08: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80055D0C: lw          $t9, 0x38C4($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X38C4));
    // 0x80055D10: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x80055D14: addiu       $s0, $s0, 0x12A8
    ctx->r16 = ADD32(ctx->r16, 0X12A8);
    // 0x80055D18: bne         $t9, $zero, L_80055D54
    if (ctx->r25 != 0) {
        // 0x80055D1C: addiu       $t2, $zero, 0x5
        ctx->r10 = ADD32(0, 0X5);
            goto L_80055D54;
    }
    // 0x80055D1C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80055D20: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80055D24: lb          $a0, 0x3748($a3)
    ctx->r4 = S32(MEM_B(ctx->r7, 0X3748));
    // 0x80055D28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80055D2C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x80055D30: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80055D34: jal         0x80051A80
    // 0x80055D38: sb          $s2, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r18;
    func_80051A80(rdram, ctx);
        goto after_38;
    // 0x80055D38: sb          $s2, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r18;
    after_38:
    // 0x80055D3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055D40: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
    // 0x80055D44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055D48: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80055D4C: b           L_8005612C
    // 0x80055D50: sb          $t1, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r9;
        goto L_8005612C;
    // 0x80055D50: sb          $t1, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r9;
L_80055D54:
    // 0x80055D54: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80055D58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055D5C: b           L_8005612C
    // 0x80055D60: sb          $t2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r10;
        goto L_8005612C;
    // 0x80055D60: sb          $t2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r10;
L_80055D64:
    // 0x80055D64: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80055D68: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80055D6C: lb          $t4, 0x3930($t4)
    ctx->r12 = S32(MEM_B(ctx->r12, 0X3930));
    // 0x80055D70: lb          $t3, 0x3934($t3)
    ctx->r11 = S32(MEM_B(ctx->r11, 0X3934));
    // 0x80055D74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055D78: bnel        $t3, $t4, L_80056130
    if (ctx->r11 != ctx->r12) {
        // 0x80055D7C: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_80056130;
    }
    goto skip_1;
    // 0x80055D7C: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_1:
    // 0x80055D80: b           L_8005612C
    // 0x80055D84: sw          $s2, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r18;
        goto L_8005612C;
    // 0x80055D84: sw          $s2, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r18;
L_80055D88:
    // 0x80055D88: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055D8C: addiu       $a2, $a2, 0x4460
    ctx->r6 = ADD32(ctx->r6, 0X4460);
    // 0x80055D90: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055D94: jal         0x8006413C
    // 0x80055D98: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    menutext(rdram, ctx);
        goto after_39;
    // 0x80055D98: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_39:
    // 0x80055D9C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055DA0: addiu       $a2, $a2, 0x4478
    ctx->r6 = ADD32(ctx->r6, 0X4478);
    // 0x80055DA4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055DA8: jal         0x8006413C
    // 0x80055DAC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    menutext(rdram, ctx);
        goto after_40;
    // 0x80055DAC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_40:
    // 0x80055DB0: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055DB4: addiu       $a2, $a2, 0x448C
    ctx->r6 = ADD32(ctx->r6, 0X448C);
    // 0x80055DB8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055DBC: jal         0x8006413C
    // 0x80055DC0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    menutext(rdram, ctx);
        goto after_41;
    // 0x80055DC0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_41:
    // 0x80055DC4: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055DC8: addiu       $a2, $a2, 0x44A4
    ctx->r6 = ADD32(ctx->r6, 0X44A4);
    // 0x80055DCC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055DD0: jal         0x8006413C
    // 0x80055DD4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    menutext(rdram, ctx);
        goto after_42;
    // 0x80055DD4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_42:
    // 0x80055DD8: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x80055DDC: addiu       $s0, $s0, 0x12A8
    ctx->r16 = ADD32(ctx->r16, 0X12A8);
    // 0x80055DE0: lb          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055DE4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80055DE8: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    // 0x80055DEC: sll         $t5, $a1, 4
    ctx->r13 = S32(ctx->r5 << 4);
    // 0x80055DF0: jal         0x8005C9BC
    // 0x80055DF4: addiu       $a1, $t5, 0xB3
    ctx->r5 = ADD32(ctx->r13, 0XB3);
    rotatesprite_simplest(rdram, ctx);
        goto after_43;
    // 0x80055DF4: addiu       $a1, $t5, 0xB3
    ctx->r5 = ADD32(ctx->r13, 0XB3);
    after_43:
    // 0x80055DF8: lb          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055DFC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x80055E00: addiu       $a2, $zero, 0xC80
    ctx->r6 = ADD32(0, 0XC80);
    // 0x80055E04: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80055E08: jal         0x8005C9BC
    // 0x80055E0C: addiu       $a1, $t6, 0xB3
    ctx->r5 = ADD32(ctx->r14, 0XB3);
    rotatesprite_simplest(rdram, ctx);
        goto after_44;
    // 0x80055E0C: addiu       $a1, $t6, 0xB3
    ctx->r5 = ADD32(ctx->r14, 0XB3);
    after_44:
    // 0x80055E10: lb          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055E14: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80055E18: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80055E1C: bne         $t7, $zero, L_80055E40
    if (ctx->r15 != 0) {
        // 0x80055E20: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80055E40;
    }
    // 0x80055E20: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80055E24: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80055E28: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80055E2C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80055E30: jal         0x8006E994
    // 0x80055E34: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    setrotatespriteflags(rdram, ctx);
        goto after_45;
    // 0x80055E34: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    after_45:
    // 0x80055E38: b           L_80055E48
    // 0x80055E3C: nop

        goto L_80055E48;
    // 0x80055E3C: nop

L_80055E40:
    // 0x80055E40: jal         0x8006E994
    // 0x80055E44: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    setrotatespriteflags(rdram, ctx);
        goto after_46;
    // 0x80055E44: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    after_46:
L_80055E48:
    // 0x80055E48: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055E4C: addiu       $a2, $a2, 0x44AC
    ctx->r6 = ADD32(ctx->r6, 0X44AC);
    // 0x80055E50: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055E54: jal         0x8006413C
    // 0x80055E58: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    menutext(rdram, ctx);
        goto after_47;
    // 0x80055E58: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    after_47:
    // 0x80055E5C: lb          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055E60: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80055E64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80055E68: bne         $s2, $t8, L_80055E8C
    if (ctx->r18 != ctx->r24) {
        // 0x80055E6C: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80055E8C;
    }
    // 0x80055E6C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80055E70: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80055E74: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80055E78: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80055E7C: jal         0x8006E994
    // 0x80055E80: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    setrotatespriteflags(rdram, ctx);
        goto after_48;
    // 0x80055E80: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    after_48:
    // 0x80055E84: b           L_80055E94
    // 0x80055E88: nop

        goto L_80055E94;
    // 0x80055E88: nop

L_80055E8C:
    // 0x80055E8C: jal         0x8006E994
    // 0x80055E90: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    setrotatespriteflags(rdram, ctx);
        goto after_49;
    // 0x80055E90: lh          $a3, 0x0($s1)
    ctx->r7 = S32(MEM_H(ctx->r17, 0X0));
    after_49:
L_80055E94:
    // 0x80055E94: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80055E98: addiu       $a2, $a2, 0x44B4
    ctx->r6 = ADD32(ctx->r6, 0X44B4);
    // 0x80055E9C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80055EA0: jal         0x8006413C
    // 0x80055EA4: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    menutext(rdram, ctx);
        goto after_50;
    // 0x80055EA4: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    after_50:
    // 0x80055EA8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80055EAC: addiu       $a1, $a1, 0x3934
    ctx->r5 = ADD32(ctx->r5, 0X3934);
    // 0x80055EB0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80055EB4: lb          $t0, 0x3930($t0)
    ctx->r8 = S32(MEM_B(ctx->r8, 0X3930));
    // 0x80055EB8: lb          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_B(ctx->r5, 0X0));
    // 0x80055EBC: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x80055EC0: addiu       $v0, $v0, -0x53B4
    ctx->r2 = ADD32(ctx->r2, -0X53B4);
    // 0x80055EC4: beq         $t9, $t0, L_80055ED8
    if (ctx->r25 == ctx->r8) {
        // 0x80055EC8: lui         $v1, 0x8028
        ctx->r3 = S32(0X8028 << 16);
            goto L_80055ED8;
    }
    // 0x80055EC8: lui         $v1, 0x8028
    ctx->r3 = S32(0X8028 << 16);
    // 0x80055ECC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80055ED0: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80055ED4: sh          $zero, -0x5C42($at)
    MEM_H(-0X5C42, ctx->r1) = 0;
L_80055ED8:
    // 0x80055ED8: lhu         $v1, -0x5C42($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X5C42);
    // 0x80055EDC: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x80055EE0: addiu       $v0, $v0, -0x53B4
    ctx->r2 = ADD32(ctx->r2, -0X53B4);
    // 0x80055EE4: andi        $t2, $v1, 0x404
    ctx->r10 = ctx->r3 & 0X404;
    // 0x80055EE8: bne         $t2, $zero, L_80055EFC
    if (ctx->r10 != 0) {
        // 0x80055EEC: andi        $t7, $v1, 0x808
        ctx->r15 = ctx->r3 & 0X808;
            goto L_80055EFC;
    }
    // 0x80055EEC: andi        $t7, $v1, 0x808
    ctx->r15 = ctx->r3 & 0X808;
    // 0x80055EF0: lw          $t3, 0x0($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80055EF4: bgez        $t3, L_80055F18
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80055EF8: nop
    
            goto L_80055F18;
    }
    // 0x80055EF8: nop

L_80055EFC:
    // 0x80055EFC: lb          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055F00: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80055F04: addiu       $a0, $a0, 0x12AC
    ctx->r4 = ADD32(ctx->r4, 0X12AC);
    // 0x80055F08: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80055F0C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80055F10: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x80055F14: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
L_80055F18:
    // 0x80055F18: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80055F1C: bne         $t7, $zero, L_80055F30
    if (ctx->r15 != 0) {
        // 0x80055F20: addiu       $a0, $a0, 0x12AC
        ctx->r4 = ADD32(ctx->r4, 0X12AC);
            goto L_80055F30;
    }
    // 0x80055F20: addiu       $a0, $a0, 0x12AC
    ctx->r4 = ADD32(ctx->r4, 0X12AC);
    // 0x80055F24: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80055F28: blezl       $t8, L_80055F48
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80055F2C: lb          $v0, 0x0($s0)
        ctx->r2 = S32(MEM_B(ctx->r16, 0X0));
            goto L_80055F48;
    }
    goto skip_2;
    // 0x80055F2C: lb          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_B(ctx->r16, 0X0));
    skip_2:
L_80055F30:
    // 0x80055F30: lb          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055F34: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80055F38: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80055F3C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80055F40: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x80055F44: lb          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_B(ctx->r16, 0X0));
L_80055F48:
    // 0x80055F48: andi        $t2, $v1, 0xE000
    ctx->r10 = ctx->r3 & 0XE000;
    // 0x80055F4C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80055F50: bne         $at, $zero, L_80055F60
    if (ctx->r1 != 0) {
        // 0x80055F54: nop
    
            goto L_80055F60;
    }
    // 0x80055F54: nop

    // 0x80055F58: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80055F5C: lb          $v0, 0x0($s0)
    ctx->r2 = S32(MEM_B(ctx->r16, 0X0));
L_80055F60:
    // 0x80055F60: bgez        $v0, L_80055F6C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80055F64: nop
    
            goto L_80055F6C;
    }
    // 0x80055F64: nop

    // 0x80055F68: sb          $s2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r18;
L_80055F6C:
    // 0x80055F6C: beq         $t2, $zero, L_80056108
    if (ctx->r10 == 0) {
        // 0x80055F70: nop
    
            goto L_80056108;
    }
    // 0x80055F70: nop

    // 0x80055F74: lb          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055F78: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80055F7C: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x80055F80: bne         $t4, $zero, L_80055F98
    if (ctx->r12 != 0) {
        // 0x80055F84: addiu       $t5, $zero, -0x3
        ctx->r13 = ADD32(0, -0X3);
            goto L_80055F98;
    }
    // 0x80055F84: addiu       $t5, $zero, -0x3
    ctx->r13 = ADD32(0, -0X3);
    // 0x80055F88: sb          $s2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r18;
    // 0x80055F8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055F90: b           L_8005612C
    // 0x80055F94: sb          $t5, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r13;
        goto L_8005612C;
    // 0x80055F94: sb          $t5, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r13;
L_80055F98:
    // 0x80055F98: jal         0x80051D40
    // 0x80055F9C: nop

    func_80051D40(rdram, ctx);
        goto after_51;
    // 0x80055F9C: nop

    after_51:
    // 0x80055FA0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80055FA4: jal         0x800BF2A0
    // 0x80055FA8: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    osPfsRepairId_recomp(rdram, ctx);
        goto after_52;
    // 0x80055FA8: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    after_52:
    // 0x80055FAC: jal         0x80051D6C
    // 0x80055FB0: nop

    func_80051D6C(rdram, ctx);
        goto after_53;
    // 0x80055FB0: nop

    after_53:
    // 0x80055FB4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80055FB8: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80055FBC: addiu       $s0, $s0, 0x38B8
    ctx->r16 = ADD32(ctx->r16, 0X38B8);
L_80055FC0:
    // 0x80055FC0: sb          $s2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r18;
    // 0x80055FC4: lb          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055FC8: bne         $s2, $t6, L_80055FE4
    if (ctx->r18 != ctx->r14) {
        // 0x80055FCC: nop
    
            goto L_80055FE4;
    }
    // 0x80055FCC: nop

L_80055FD0:
    // 0x80055FD0: jal         0x800BDDD0
    // 0x80055FD4: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_54;
    // 0x80055FD4: nop

    after_54:
    // 0x80055FD8: lb          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_B(ctx->r16, 0X0));
    // 0x80055FDC: beq         $s2, $t7, L_80055FD0
    if (ctx->r18 == ctx->r15) {
        // 0x80055FE0: nop
    
            goto L_80055FD0;
    }
    // 0x80055FE0: nop

L_80055FE4:
    // 0x80055FE4: jal         0x8004BD60
    // 0x80055FE8: nop

    updatetime(rdram, ctx);
        goto after_55;
    // 0x80055FE8: nop

    after_55:
    // 0x80055FEC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80055FF0: lw          $t8, 0x38BC($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, 0X38BC));
    // 0x80055FF4: sltiu       $at, $t8, 0xC
    ctx->r1 = ctx->r24 < 0XC ? 1 : 0;
    // 0x80055FF8: beq         $at, $zero, L_80056108
    if (ctx->r1 == 0) {
        // 0x80055FFC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80056108;
    }
    // 0x80055FFC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80056000: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80056004: addu        $at, $at, $t8
    gpr jr_addend_8005600C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80056008: lw          $t8, 0x4574($at)
    ctx->r24 = ADD32(ctx->r1, 0X4574);
    // 0x8005600C: jr          $t8
    // 0x80056010: nop

    switch (jr_addend_8005600C >> 2) {
        case 0: goto L_80056014; break;
        case 1: goto L_8005605C; break;
        case 2: goto L_80055FC0; break;
        case 3: goto L_80056108; break;
        case 4: goto L_80056108; break;
        case 5: goto L_80056108; break;
        case 6: goto L_80056108; break;
        case 7: goto L_80056108; break;
        case 8: goto L_80056108; break;
        case 9: goto L_80056108; break;
        case 10: goto L_8005607C; break;
        case 11: goto L_8005607C; break;
        default: switch_error(__func__, 0x8005600C, 0x80104574);
    }
    // 0x80056010: nop

L_80056014:
    // 0x80056014: jal         0x80051D40
    // 0x80056018: nop

    func_80051D40(rdram, ctx);
        goto after_56;
    // 0x80056018: nop

    after_56:
    // 0x8005601C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80056020: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80056024: addiu       $a2, $a2, -0x6CBC
    ctx->r6 = ADD32(ctx->r6, -0X6CBC);
    // 0x80056028: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    // 0x8005602C: jal         0x800BCFC0
    // 0x80056030: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_57;
    // 0x80056030: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_57:
    // 0x80056034: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80056038: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8005603C: addiu       $a1, $a1, -0x6CB8
    ctx->r5 = ADD32(ctx->r5, -0X6CB8);
    // 0x80056040: jal         0x800BD110
    // 0x80056044: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_58;
    // 0x80056044: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    after_58:
    // 0x80056048: jal         0x80051D6C
    // 0x8005604C: nop

    func_80051D6C(rdram, ctx);
        goto after_59;
    // 0x8005604C: nop

    after_59:
    // 0x80056050: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056054: b           L_8005612C
    // 0x80056058: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
        goto L_8005612C;
    // 0x80056058: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
L_8005605C:
    // 0x8005605C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80056060: bne         $s1, $zero, L_80055FC0
    if (ctx->r17 != 0) {
        // 0x80056064: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80055FC0;
    }
    // 0x80056064: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056068: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
    // 0x8005606C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056070: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80056074: b           L_8005612C
    // 0x80056078: sb          $t9, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r25;
        goto L_8005612C;
    // 0x80056078: sb          $t9, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r25;
L_8005607C:
    // 0x8005607C: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80056080: addiu       $s0, $s0, 0x38C0
    ctx->r16 = ADD32(ctx->r16, 0X38C0);
    // 0x80056084: sb          $s2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r18;
    // 0x80056088: lb          $t0, 0x0($s0)
    ctx->r8 = S32(MEM_B(ctx->r16, 0X0));
    // 0x8005608C: bne         $s2, $t0, L_800560A8
    if (ctx->r18 != ctx->r8) {
        // 0x80056090: nop
    
            goto L_800560A8;
    }
    // 0x80056090: nop

L_80056094:
    // 0x80056094: jal         0x800BDDD0
    // 0x80056098: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_60;
    // 0x80056098: nop

    after_60:
    // 0x8005609C: lb          $t1, 0x0($s0)
    ctx->r9 = S32(MEM_B(ctx->r16, 0X0));
    // 0x800560A0: beq         $s2, $t1, L_80056094
    if (ctx->r18 == ctx->r9) {
        // 0x800560A4: nop
    
            goto L_80056094;
    }
    // 0x800560A4: nop

L_800560A8:
    // 0x800560A8: jal         0x8004BD60
    // 0x800560AC: nop

    updatetime(rdram, ctx);
        goto after_61;
    // 0x800560AC: nop

    after_61:
    // 0x800560B0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800560B4: lw          $t2, 0x38C4($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X38C4));
    // 0x800560B8: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800560BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800560C0: bne         $t2, $zero, L_800560F8
    if (ctx->r10 != 0) {
        // 0x800560C4: addiu       $t5, $zero, -0x3
        ctx->r13 = ADD32(0, -0X3);
            goto L_800560F8;
    }
    // 0x800560C4: addiu       $t5, $zero, -0x3
    ctx->r13 = ADD32(0, -0X3);
    // 0x800560C8: lb          $a0, 0x3748($a3)
    ctx->r4 = S32(MEM_B(ctx->r7, 0X3748));
    // 0x800560CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800560D0: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800560D4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800560D8: jal         0x80051A80
    // 0x800560DC: sb          $s2, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r18;
    func_80051A80(rdram, ctx);
        goto after_62;
    // 0x800560DC: sb          $s2, -0x4708($at)
    MEM_B(-0X4708, ctx->r1) = ctx->r18;
    after_62:
    // 0x800560E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800560E4: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
    // 0x800560E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800560EC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800560F0: b           L_8005612C
    // 0x800560F4: sb          $t4, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r12;
        goto L_8005612C;
    // 0x800560F4: sb          $t4, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r12;
L_800560F8:
    // 0x800560F8: sb          $s2, 0x3934($at)
    MEM_B(0X3934, ctx->r1) = ctx->r18;
    // 0x800560FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056100: b           L_8005612C
    // 0x80056104: sb          $t5, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r13;
        goto L_8005612C;
    // 0x80056104: sb          $t5, 0x3748($at)
    MEM_B(0X3748, ctx->r1) = ctx->r13;
L_80056108:
    // 0x80056108: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005610C: addiu       $a1, $a1, 0x3934
    ctx->r5 = ADD32(ctx->r5, 0X3934);
    // 0x80056110: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80056114: lb          $t7, 0x3930($t7)
    ctx->r15 = S32(MEM_B(ctx->r15, 0X3930));
    // 0x80056118: lb          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_B(ctx->r5, 0X0));
    // 0x8005611C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056120: bnel        $t6, $t7, L_80056130
    if (ctx->r14 != ctx->r15) {
        // 0x80056124: lw          $ra, 0x2C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_80056130;
    }
    goto skip_3;
    // 0x80056124: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    skip_3:
    // 0x80056128: sw          $s2, 0x3938($at)
    MEM_W(0X3938, ctx->r1) = ctx->r18;
L_8005612C:
    // 0x8005612C: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
L_80056130:
    // 0x80056130: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80056134: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80056138: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8005613C: jr          $ra
    // 0x80056140: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x80056140: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void initengine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80091A6C: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80091A70: sh          $t6, 0x6F20($at)
    MEM_H(0X6F20, ctx->r1) = ctx->r14;
    // 0x80091A74: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x80091A78: sw          $zero, -0x5370($at)
    MEM_W(-0X5370, ctx->r1) = 0;
    // 0x80091A7C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x80091A80: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x80091A84: sw          $t7, -0x5380($at)
    MEM_W(-0X5380, ctx->r1) = ctx->r15;
    // 0x80091A88: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x80091A8C: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x80091A90: jr          $ra
    // 0x80091A94: sw          $t8, -0x537C($at)
    MEM_W(-0X537C, ctx->r1) = ctx->r24;
    return;
    // 0x80091A94: sw          $t8, -0x537C($at)
    MEM_W(-0X537C, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void getangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092024: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80092028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009202C: or          $t6, $a0, $a1
    ctx->r14 = ctx->r4 | ctx->r5;
    // 0x80092030: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80092034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092038: bne         $t6, $zero, L_80092048
    if (ctx->r14 != 0) {
        // 0x8009203C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80092048;
    }
    // 0x8009203C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80092040: b           L_80092150
    // 0x80092044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80092150;
    // 0x80092044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80092048:
    // 0x80092048: bne         $a3, $zero, L_8009205C
    if (ctx->r7 != 0) {
        // 0x8009204C: slti        $v0, $s0, 0x0
        ctx->r2 = SIGNED(ctx->r16) < 0X0 ? 1 : 0;
            goto L_8009205C;
    }
    // 0x8009204C: slti        $v0, $s0, 0x0
    ctx->r2 = SIGNED(ctx->r16) < 0X0 ? 1 : 0;
    // 0x80092050: sll         $t7, $v0, 10
    ctx->r15 = S32(ctx->r2 << 10);
    // 0x80092054: b           L_80092150
    // 0x80092058: addiu       $v0, $t7, 0x200
    ctx->r2 = ADD32(ctx->r15, 0X200);
        goto L_80092150;
    // 0x80092058: addiu       $v0, $t7, 0x200
    ctx->r2 = ADD32(ctx->r15, 0X200);
L_8009205C:
    // 0x8009205C: bne         $s0, $zero, L_80092070
    if (ctx->r16 != 0) {
        // 0x80092060: slti        $v0, $a3, 0x0
        ctx->r2 = SIGNED(ctx->r7) < 0X0 ? 1 : 0;
            goto L_80092070;
    }
    // 0x80092060: slti        $v0, $a3, 0x0
    ctx->r2 = SIGNED(ctx->r7) < 0X0 ? 1 : 0;
    // 0x80092064: sll         $t8, $v0, 10
    ctx->r24 = S32(ctx->r2 << 10);
    // 0x80092068: b           L_80092150
    // 0x8009206C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80092150;
    // 0x8009206C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80092070:
    // 0x80092070: bne         $a3, $s0, L_80092088
    if (ctx->r7 != ctx->r16) {
        // 0x80092074: negu        $v1, $s0
        ctx->r3 = SUB32(0, ctx->r16);
            goto L_80092088;
    }
    // 0x80092074: negu        $v1, $s0
    ctx->r3 = SUB32(0, ctx->r16);
    // 0x80092078: slti        $v0, $a3, 0x0
    ctx->r2 = SIGNED(ctx->r7) < 0X0 ? 1 : 0;
    // 0x8009207C: sll         $t9, $v0, 10
    ctx->r25 = S32(ctx->r2 << 10);
    // 0x80092080: b           L_80092150
    // 0x80092084: addiu       $v0, $t9, 0x100
    ctx->r2 = ADD32(ctx->r25, 0X100);
        goto L_80092150;
    // 0x80092084: addiu       $v0, $t9, 0x100
    ctx->r2 = ADD32(ctx->r25, 0X100);
L_80092088:
    // 0x80092088: bne         $a3, $v1, L_8009209C
    if (ctx->r7 != ctx->r3) {
        // 0x8009208C: slt         $v0, $zero, $a3
        ctx->r2 = SIGNED(0) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8009209C;
    }
    // 0x8009208C: slt         $v0, $zero, $a3
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80092090: sll         $t0, $v0, 10
    ctx->r8 = S32(ctx->r2 << 10);
    // 0x80092094: b           L_80092150
    // 0x80092098: addiu       $v0, $t0, 0x300
    ctx->r2 = ADD32(ctx->r8, 0X300);
        goto L_80092150;
    // 0x80092098: addiu       $v0, $t0, 0x300
    ctx->r2 = ADD32(ctx->r8, 0X300);
L_8009209C:
    // 0x8009209C: blez        $a3, L_800920AC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800920A0: negu        $a0, $a3
        ctx->r4 = SUB32(0, ctx->r7);
            goto L_800920AC;
    }
    // 0x800920A0: negu        $a0, $a3
    ctx->r4 = SUB32(0, ctx->r7);
    // 0x800920A4: b           L_800920AC
    // 0x800920A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
        goto L_800920AC;
    // 0x800920A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800920AC:
    // 0x800920AC: blez        $s0, L_800920BC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800920B0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800920BC;
    }
    // 0x800920B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800920B4: b           L_800920BC
    // 0x800920B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800920BC;
    // 0x800920B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800920BC:
    // 0x800920BC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800920C0: beq         $at, $zero, L_8009210C
    if (ctx->r1 == 0) {
        // 0x800920C4: addiu       $a0, $zero, 0xA0
        ctx->r4 = ADD32(0, 0XA0);
            goto L_8009210C;
    }
    // 0x800920C4: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x800920C8: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x800920CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800920D0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800920D4: jal         0x800919B0
    // 0x800920D8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    scale(rdram, ctx);
        goto after_0;
    // 0x800920D8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800920DC: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x800920E0: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x800920E4: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800920E8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800920EC: lh          $t2, 0xB60($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0XB60));
    // 0x800920F0: slti        $t4, $a3, 0x0
    ctx->r12 = SIGNED(ctx->r7) < 0X0 ? 1 : 0;
    // 0x800920F4: sll         $t5, $t4, 10
    ctx->r13 = S32(ctx->r12 << 10);
    // 0x800920F8: sra         $t3, $t2, 6
    ctx->r11 = S32(SIGNED(ctx->r10) >> 6);
    // 0x800920FC: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x80092100: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x80092104: b           L_80092150
    // 0x80092108: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80092150;
    // 0x80092108: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8009210C:
    // 0x8009210C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80092110: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80092114: jal         0x800919B0
    // 0x80092118: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    scale(rdram, ctx);
        goto after_1;
    // 0x80092118: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8009211C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80092120: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80092124: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80092128: lw          $v1, 0x24($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8009212C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80092130: lh          $t9, 0xB60($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0XB60));
    // 0x80092134: slt         $t1, $zero, $v1
    ctx->r9 = SIGNED(0) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80092138: sll         $t2, $t1, 10
    ctx->r10 = S32(ctx->r9 << 10);
    // 0x8009213C: sra         $t0, $t9, 6
    ctx->r8 = S32(SIGNED(ctx->r25) >> 6);
    // 0x80092140: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80092144: addiu       $v0, $v0, 0x200
    ctx->r2 = ADD32(ctx->r2, 0X200);
    // 0x80092148: andi        $t4, $v0, 0x7FF
    ctx->r12 = ctx->r2 & 0X7FF;
    // 0x8009214C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80092150:
    // 0x80092150: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80092154: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80092158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009215C: jr          $ra
    // 0x80092160: nop

    return;
    // 0x80092160: nop

;}
RECOMP_FUNC void _freePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C24C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C24C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C24C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C24CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C24D0: jal         0x800BF770
    // 0x800C24D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C24D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800C24D8: lw          $a1, 0x18($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800C24DC: lw          $a0, 0x1C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C24E0: jal         0x800BF7A0
    // 0x800C24E4: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C24E4: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x800C24E8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C24EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C24F0: jr          $ra
    // 0x800C24F4: nop

    return;
    // 0x800C24F4: nop

;}
RECOMP_FUNC void checkhitswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF77C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AF780: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800AF784: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800AF788: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800AF78C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF790: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800AF794: bgez        $a1, L_800AF7A4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800AF798: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_800AF7A4;
    }
    // 0x800AF798: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800AF79C: b           L_800B0570
    // 0x800AF7A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0570;
    // 0x800AF7A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AF7A4:
    // 0x800AF7A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AF7A8: sll         $t0, $t2, 16
    ctx->r8 = S32(ctx->r10 << 16);
    // 0x800AF7AC: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800AF7B0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800AF7B4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800AF7B8: bne         $t2, $a2, L_800AF830
    if (ctx->r10 != ctx->r6) {
        // 0x800AF7BC: or          $t3, $a2, $zero
        ctx->r11 = ctx->r6 | 0;
            goto L_800AF830;
    }
    // 0x800AF7BC: or          $t3, $a2, $zero
    ctx->r11 = ctx->r6 | 0;
    // 0x800AF7C0: lw          $t9, 0x4C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AF7C4: lui         $t7, 0x8024
    ctx->r15 = S32(0X8024 << 16);
    // 0x800AF7C8: addiu       $t7, $t7, 0x6BA8
    ctx->r15 = ADD32(ctx->r15, 0X6BA8);
    // 0x800AF7CC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800AF7D0: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x800AF7D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AF7D8: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x800AF7DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AF7E0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AF7E4: lh          $t8, 0x1E($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X1E));
    // 0x800AF7E8: lui         $ra, 0x8022
    ctx->r31 = S32(0X8022 << 16);
    // 0x800AF7EC: addiu       $ra, $ra, 0x61A8
    ctx->r31 = ADD32(ctx->r31, 0X61A8);
    // 0x800AF7F0: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
    // 0x800AF7F4: lh          $t9, 0x40($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800AF7F8: bnel        $t9, $zero, L_800AF80C
    if (ctx->r25 != 0) {
        // 0x800AF7FC: lh          $t6, 0x20($v0)
        ctx->r14 = S32(MEM_H(ctx->r2, 0X20));
            goto L_800AF80C;
    }
    goto skip_0;
    // 0x800AF7FC: lh          $t6, 0x20($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X20));
    skip_0:
    // 0x800AF800: b           L_800B0570
    // 0x800AF804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0570;
    // 0x800AF804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AF808: lh          $t6, 0x20($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X20));
L_800AF80C:
    // 0x800AF80C: lw          $t7, 0x0($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800AF810: lw          $t8, 0x4($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800AF814: lh          $t9, 0xE($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0XE));
    // 0x800AF818: lbu         $a0, 0x25($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X25);
    // 0x800AF81C: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x800AF820: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800AF824: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800AF828: b           L_800AF88C
    // 0x800AF82C: sh          $t9, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r25;
        goto L_800AF88C;
    // 0x800AF82C: sh          $t9, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r25;
L_800AF830:
    // 0x800AF830: lw          $t6, 0x4C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AF834: lui         $ra, 0x8022
    ctx->r31 = S32(0X8022 << 16);
    // 0x800AF838: addiu       $ra, $ra, 0x61A8
    ctx->r31 = ADD32(ctx->r31, 0X61A8);
    // 0x800AF83C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800AF840: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800AF844: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AF848: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x800AF84C: lh          $t8, 0x14($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800AF850: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
    // 0x800AF854: lh          $t9, 0x40($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800AF858: bnel        $t9, $zero, L_800AF86C
    if (ctx->r25 != 0) {
        // 0x800AF85C: lh          $t6, 0x16($v0)
        ctx->r14 = S32(MEM_H(ctx->r2, 0X16));
            goto L_800AF86C;
    }
    goto skip_1;
    // 0x800AF85C: lh          $t6, 0x16($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X16));
    skip_1:
    // 0x800AF860: b           L_800B0570
    // 0x800AF864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0570;
    // 0x800AF864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AF868: lh          $t6, 0x16($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X16));
L_800AF86C:
    // 0x800AF86C: lw          $t7, 0x0($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800AF870: lw          $t8, 0x4($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800AF874: lh          $t9, 0x10($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X10));
    // 0x800AF878: lbu         $a0, 0x1D($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1D);
    // 0x800AF87C: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x800AF880: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800AF884: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800AF888: sh          $t9, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r25;
L_800AF88C:
    // 0x800AF88C: lh          $t6, 0x3C($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800AF890: slti        $at, $t6, 0x2CA
    ctx->r1 = SIGNED(ctx->r14) < 0X2CA ? 1 : 0;
    // 0x800AF894: bne         $at, $zero, L_800AF8EC
    if (ctx->r1 != 0) {
        // 0x800AF898: slti        $at, $t6, 0x362
        ctx->r1 = SIGNED(ctx->r14) < 0X362 ? 1 : 0;
            goto L_800AF8EC;
    }
    // 0x800AF898: slti        $at, $t6, 0x362
    ctx->r1 = SIGNED(ctx->r14) < 0X362 ? 1 : 0;
    // 0x800AF89C: bne         $at, $zero, L_800AF8C8
    if (ctx->r1 != 0) {
        // 0x800AF8A0: lh          $t8, 0x3C($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
            goto L_800AF8C8;
    }
    // 0x800AF8A0: lh          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800AF8A4: addiu       $t7, $t6, -0x457
    ctx->r15 = ADD32(ctx->r14, -0X457);
    // 0x800AF8A8: sltiu       $at, $t7, 0x21
    ctx->r1 = ctx->r15 < 0X21 ? 1 : 0;
    // 0x800AF8AC: beq         $at, $zero, L_800AFAE4
    if (ctx->r1 == 0) {
        // 0x800AF8B0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800AFAE4;
    }
    // 0x800AF8B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AF8B4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AF8B8: addu        $at, $at, $t7
    gpr jr_addend_800AF8C0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AF8BC: lw          $t7, -0x78EC($at)
    ctx->r15 = ADD32(ctx->r1, -0X78EC);
    // 0x800AF8C0: jr          $t7
    // 0x800AF8C4: nop

    switch (jr_addend_800AF8C0 >> 2) {
        case 0: goto L_800AFAA4; break;
        case 1: goto L_800AFAA4; break;
        case 2: goto L_800AFAE4; break;
        case 3: goto L_800AFAE4; break;
        case 4: goto L_800AFAE4; break;
        case 5: goto L_800AFAE4; break;
        case 6: goto L_800AFAE4; break;
        case 7: goto L_800AFAE4; break;
        case 8: goto L_800AFAE4; break;
        case 9: goto L_800AFAE4; break;
        case 10: goto L_800AFAE4; break;
        case 11: goto L_800AFAA4; break;
        case 12: goto L_800AFAA4; break;
        case 13: goto L_800AFAE4; break;
        case 14: goto L_800AFAE4; break;
        case 15: goto L_800AFAE4; break;
        case 16: goto L_800AFAE4; break;
        case 17: goto L_800AFAE4; break;
        case 18: goto L_800AFAE4; break;
        case 19: goto L_800AFAE4; break;
        case 20: goto L_800AFAE4; break;
        case 21: goto L_800AFAE4; break;
        case 22: goto L_800AFAE4; break;
        case 23: goto L_800AFAE4; break;
        case 24: goto L_800AFAE4; break;
        case 25: goto L_800AFAE4; break;
        case 26: goto L_800AFAE4; break;
        case 27: goto L_800AFAE4; break;
        case 28: goto L_800AFAE4; break;
        case 29: goto L_800AFAE4; break;
        case 30: goto L_800AFAE4; break;
        case 31: goto L_800AF958; break;
        case 32: goto L_800AF958; break;
        default: switch_error(__func__, 0x800AF8C0, 0x80108714);
    }
    // 0x800AF8C4: nop

L_800AF8C8:
    // 0x800AF8C8: addiu       $t9, $t8, -0x35C
    ctx->r25 = ADD32(ctx->r24, -0X35C);
    // 0x800AF8CC: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x800AF8D0: beq         $at, $zero, L_800AFAE4
    if (ctx->r1 == 0) {
        // 0x800AF8D4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800AFAE4;
    }
    // 0x800AF8D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800AF8D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AF8DC: addu        $at, $at, $t9
    gpr jr_addend_800AF8E4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AF8E0: lw          $t9, -0x7868($at)
    ctx->r25 = ADD32(ctx->r1, -0X7868);
    // 0x800AF8E4: jr          $t9
    // 0x800AF8E8: nop

    switch (jr_addend_800AF8E4 >> 2) {
        case 0: goto L_800AFAA4; break;
        case 1: goto L_800AFAA4; break;
        case 2: goto L_800AFAA4; break;
        case 3: goto L_800AFAA4; break;
        case 4: goto L_800AFAA4; break;
        case 5: goto L_800AFAA4; break;
        default: switch_error(__func__, 0x800AF8E4, 0x80108798);
    }
    // 0x800AF8E8: nop

L_800AF8EC:
    // 0x800AF8EC: lh          $t6, 0x3C($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800AF8F0: lh          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800AF8F4: slti        $at, $t6, 0x2C9
    ctx->r1 = SIGNED(ctx->r14) < 0X2C9 ? 1 : 0;
    // 0x800AF8F8: bnel        $at, $zero, L_800AF918
    if (ctx->r1 != 0) {
        // 0x800AF8FC: slti        $at, $t7, 0xAB
        ctx->r1 = SIGNED(ctx->r15) < 0XAB ? 1 : 0;
            goto L_800AF918;
    }
    goto skip_2;
    // 0x800AF8FC: slti        $at, $t7, 0xAB
    ctx->r1 = SIGNED(ctx->r15) < 0XAB ? 1 : 0;
    skip_2:
    // 0x800AF900: addiu       $a3, $zero, 0x2C9
    ctx->r7 = ADD32(0, 0X2C9);
    // 0x800AF904: beq         $t6, $a3, L_800AFAA4
    if (ctx->r14 == ctx->r7) {
        // 0x800AF908: nop
    
            goto L_800AFAA4;
    }
    // 0x800AF908: nop

    // 0x800AF90C: b           L_800AFAE8
    // 0x800AF910: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
        goto L_800AFAE8;
    // 0x800AF910: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800AF914: slti        $at, $t7, 0xAB
    ctx->r1 = SIGNED(ctx->r15) < 0XAB ? 1 : 0;
L_800AF918:
    // 0x800AF918: bne         $at, $zero, L_800AF934
    if (ctx->r1 != 0) {
        // 0x800AF91C: lh          $t8, 0x3C($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
            goto L_800AF934;
    }
    // 0x800AF91C: lh          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800AF920: addiu       $t5, $zero, 0x2C8
    ctx->r13 = ADD32(0, 0X2C8);
    // 0x800AF924: beq         $t7, $t5, L_800AFAA4
    if (ctx->r15 == ctx->r13) {
        // 0x800AF928: nop
    
            goto L_800AFAA4;
    }
    // 0x800AF928: nop

    // 0x800AF92C: b           L_800AFAE8
    // 0x800AF930: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
        goto L_800AFAE8;
    // 0x800AF930: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
L_800AF934:
    // 0x800AF934: addiu       $t9, $t8, -0x82
    ctx->r25 = ADD32(ctx->r24, -0X82);
    // 0x800AF938: sltiu       $at, $t9, 0x29
    ctx->r1 = ctx->r25 < 0X29 ? 1 : 0;
    // 0x800AF93C: beq         $at, $zero, L_800AFAE4
    if (ctx->r1 == 0) {
        // 0x800AF940: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800AFAE4;
    }
    // 0x800AF940: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800AF944: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AF948: addu        $at, $at, $t9
    gpr jr_addend_800AF950 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AF94C: lw          $t9, -0x7850($at)
    ctx->r25 = ADD32(ctx->r1, -0X7850);
    // 0x800AF950: jr          $t9
    // 0x800AF954: nop

    switch (jr_addend_800AF950 >> 2) {
        case 0: goto L_800AF964; break;
        case 1: goto L_800AFAE4; break;
        case 2: goto L_800AFAA4; break;
        case 3: goto L_800AFAA4; break;
        case 4: goto L_800AFAA4; break;
        case 5: goto L_800AFAA4; break;
        case 6: goto L_800AFAA4; break;
        case 7: goto L_800AFAA4; break;
        case 8: goto L_800AFAA4; break;
        case 9: goto L_800AFAA4; break;
        case 10: goto L_800AFAA4; break;
        case 11: goto L_800AFAA4; break;
        case 12: goto L_800AFAE4; break;
        case 13: goto L_800AFAE4; break;
        case 14: goto L_800AFAE4; break;
        case 15: goto L_800AFAE4; break;
        case 16: goto L_800AFAA4; break;
        case 17: goto L_800AFAA4; break;
        case 18: goto L_800AFAA4; break;
        case 19: goto L_800AFAA4; break;
        case 20: goto L_800AFAE4; break;
        case 21: goto L_800AFAE4; break;
        case 22: goto L_800AFAE4; break;
        case 23: goto L_800AFAE4; break;
        case 24: goto L_800AFAE4; break;
        case 25: goto L_800AFAE4; break;
        case 26: goto L_800AFAE4; break;
        case 27: goto L_800AFAE4; break;
        case 28: goto L_800AFAE4; break;
        case 29: goto L_800AFAE4; break;
        case 30: goto L_800AFAE4; break;
        case 31: goto L_800AFAE4; break;
        case 32: goto L_800AF958; break;
        case 33: goto L_800AF958; break;
        case 34: goto L_800AFAA4; break;
        case 35: goto L_800AFAA4; break;
        case 36: goto L_800AF958; break;
        case 37: goto L_800AF958; break;
        case 38: goto L_800AFAA4; break;
        case 39: goto L_800AFAA4; break;
        case 40: goto L_800AF964; break;
        default: switch_error(__func__, 0x800AF950, 0x801087B0);
    }
    // 0x800AF954: nop

L_800AF958:
    // 0x800AF958: addiu       $t5, $zero, 0x2C8
    ctx->r13 = ADD32(0, 0X2C8);
    // 0x800AF95C: b           L_800AFB24
    // 0x800AF960: addiu       $a3, $zero, 0x2C9
    ctx->r7 = ADD32(0, 0X2C9);
        goto L_800AFB24;
    // 0x800AF960: addiu       $a3, $zero, 0x2C9
    ctx->r7 = ADD32(0, 0X2C9);
L_800AF964:
    // 0x800AF964: lh          $t6, 0x4A($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X4A));
    // 0x800AF968: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800AF96C: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x800AF970: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800AF974: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800AF978: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800AF97C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800AF980: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AF984: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800AF988: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AF98C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AF990: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800AF994: lh          $v0, 0x2CA($t9)
    ctx->r2 = S32(MEM_H(ctx->r25, 0X2CA));
    // 0x800AF998: bne         $v0, $zero, L_800AFAA4
    if (ctx->r2 != 0) {
        // 0x800AF99C: nop
    
            goto L_800AFAA4;
    }
    // 0x800AF99C: nop

    // 0x800AF9A0: bne         $a0, $zero, L_800AF9E4
    if (ctx->r4 != 0) {
        // 0x800AF9A4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800AF9E4;
    }
    // 0x800AF9A4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800AF9A8: lh          $t6, 0x2D6($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X2D6));
    // 0x800AF9AC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x800AF9B0: lw          $a1, 0x24($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AF9B4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800AF9B8: beq         $t7, $zero, L_800AF9C8
    if (ctx->r15 == 0) {
        // 0x800AF9BC: nop
    
            goto L_800AF9C8;
    }
    // 0x800AF9BC: nop

    // 0x800AF9C0: b           L_800AF9D8
    // 0x800AF9C4: sh          $t2, 0x2CA($t9)
    MEM_H(0X2CA, ctx->r25) = ctx->r10;
        goto L_800AF9D8;
    // 0x800AF9C4: sh          $t2, 0x2CA($t9)
    MEM_H(0X2CA, ctx->r25) = ctx->r10;
L_800AF9C8:
    // 0x800AF9C8: jal         0x80099868
    // 0x800AF9CC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    FTA(rdram, ctx);
        goto after_0;
    // 0x800AF9CC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_0:
    // 0x800AF9D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AF9D4: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
L_800AF9D8:
    // 0x800AF9D8: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AF9DC: b           L_800AFA70
    // 0x800AF9E0: lh          $v0, 0x2CA($t8)
    ctx->r2 = S32(MEM_H(ctx->r24, 0X2CA));
        goto L_800AFA70;
    // 0x800AF9E0: lh          $v0, 0x2CA($t8)
    ctx->r2 = S32(MEM_H(ctx->r24, 0X2CA));
L_800AF9E4:
    // 0x800AF9E4: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x800AF9E8: bne         $v1, $at, L_800AFA2C
    if (ctx->r3 != ctx->r1) {
        // 0x800AF9EC: lw          $t6, 0x24($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800AFA2C;
    }
    // 0x800AF9EC: lw          $t6, 0x24($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AF9F0: lh          $t7, 0x2D6($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X2D6));
    // 0x800AF9F4: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x800AF9F8: lw          $a1, 0x24($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AF9FC: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x800AFA00: beq         $t9, $zero, L_800AFA10
    if (ctx->r25 == 0) {
        // 0x800AFA04: nop
    
            goto L_800AFA10;
    }
    // 0x800AFA04: nop

    // 0x800AFA08: b           L_800AFA20
    // 0x800AFA0C: sh          $t2, 0x2CA($t6)
    MEM_H(0X2CA, ctx->r14) = ctx->r10;
        goto L_800AFA20;
    // 0x800AFA0C: sh          $t2, 0x2CA($t6)
    MEM_H(0X2CA, ctx->r14) = ctx->r10;
L_800AFA10:
    // 0x800AFA10: jal         0x80099868
    // 0x800AFA14: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    FTA(rdram, ctx);
        goto after_1;
    // 0x800AFA14: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_1:
    // 0x800AFA18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AFA1C: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
L_800AFA20:
    // 0x800AFA20: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AFA24: b           L_800AFA70
    // 0x800AFA28: lh          $v0, 0x2CA($t8)
    ctx->r2 = S32(MEM_H(ctx->r24, 0X2CA));
        goto L_800AFA70;
    // 0x800AFA28: lh          $v0, 0x2CA($t8)
    ctx->r2 = S32(MEM_H(ctx->r24, 0X2CA));
L_800AFA2C:
    // 0x800AFA2C: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x800AFA30: bne         $v1, $at, L_800AFA70
    if (ctx->r3 != ctx->r1) {
        // 0x800AFA34: lw          $t7, 0x24($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800AFA70;
    }
    // 0x800AFA34: lw          $t7, 0x24($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AFA38: lh          $t9, 0x2D6($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X2D6));
    // 0x800AFA3C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800AFA40: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x800AFA44: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x800AFA48: beq         $t6, $zero, L_800AFA58
    if (ctx->r14 == 0) {
        // 0x800AFA4C: lw          $a1, 0x24($sp)
        ctx->r5 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800AFA58;
    }
    // 0x800AFA4C: lw          $a1, 0x24($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AFA50: b           L_800AFA70
    // 0x800AFA54: sh          $t2, 0x2CA($t7)
    MEM_H(0X2CA, ctx->r15) = ctx->r10;
        goto L_800AFA70;
    // 0x800AFA54: sh          $t2, 0x2CA($t7)
    MEM_H(0X2CA, ctx->r15) = ctx->r10;
L_800AFA58:
    // 0x800AFA58: jal         0x80099868
    // 0x800AFA5C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    FTA(rdram, ctx);
        goto after_2;
    // 0x800AFA5C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_2:
    // 0x800AFA60: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AFA64: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AFA68: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800AFA6C: lh          $v0, 0x2CA($t8)
    ctx->r2 = S32(MEM_H(ctx->r24, 0X2CA));
L_800AFA70:
    // 0x800AFA70: bne         $t2, $v0, L_800AFA9C
    if (ctx->r10 != ctx->r2) {
        // 0x800AFA74: nop
    
            goto L_800AFA9C;
    }
    // 0x800AFA74: nop

    // 0x800AFA78: bne         $t3, $zero, L_800AFA94
    if (ctx->r11 != 0) {
        // 0x800AFA7C: lw          $t7, 0x4C($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X4C));
            goto L_800AFA94;
    }
    // 0x800AFA7C: lw          $t7, 0x4C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AFA80: lw          $t9, 0x4C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AFA84: lw          $t6, 0x24($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AFA88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AFA8C: b           L_800B0570
    // 0x800AFA90: sh          $t9, 0x2D0($t6)
    MEM_H(0X2D0, ctx->r14) = ctx->r25;
        goto L_800B0570;
    // 0x800AFA90: sh          $t9, 0x2D0($t6)
    MEM_H(0X2D0, ctx->r14) = ctx->r25;
L_800AFA94:
    // 0x800AFA94: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800AFA98: sh          $t7, 0x2D2($t8)
    MEM_H(0X2D2, ctx->r24) = ctx->r15;
L_800AFA9C:
    // 0x800AFA9C: b           L_800B0570
    // 0x800AFAA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0570;
    // 0x800AFAA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AFAA4:
    // 0x800AFAA4: lh          $a0, 0x40($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800AFAA8: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x800AFAAC: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x800AFAB0: jal         0x800ACB10
    // 0x800AFAB4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    check_activator_motion(rdram, ctx);
        goto after_3;
    // 0x800AFAB4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_3:
    // 0x800AFAB8: lui         $ra, 0x8022
    ctx->r31 = S32(0X8022 << 16);
    // 0x800AFABC: addiu       $ra, $ra, 0x61A8
    ctx->r31 = ADD32(ctx->r31, 0X61A8);
    // 0x800AFAC0: addiu       $a3, $zero, 0x2C9
    ctx->r7 = ADD32(0, 0X2C9);
    // 0x800AFAC4: lh          $t0, 0x3A($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x800AFAC8: lh          $t1, 0x38($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X38));
    // 0x800AFACC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AFAD0: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800AFAD4: beq         $v0, $zero, L_800AFB24
    if (ctx->r2 == 0) {
        // 0x800AFAD8: addiu       $t5, $zero, 0x2C8
        ctx->r13 = ADD32(0, 0X2C8);
            goto L_800AFB24;
    }
    // 0x800AFAD8: addiu       $t5, $zero, 0x2C8
    ctx->r13 = ADD32(0, 0X2C8);
    // 0x800AFADC: b           L_800B0570
    // 0x800AFAE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0570;
    // 0x800AFAE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AFAE4:
    // 0x800AFAE4: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
L_800AFAE8:
    // 0x800AFAE8: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x800AFAEC: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x800AFAF0: jal         0x800ACC8C
    // 0x800AFAF4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    isadoorwall(rdram, ctx);
        goto after_4;
    // 0x800AFAF4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_4:
    // 0x800AFAF8: lui         $ra, 0x8022
    ctx->r31 = S32(0X8022 << 16);
    // 0x800AFAFC: addiu       $ra, $ra, 0x61A8
    ctx->r31 = ADD32(ctx->r31, 0X61A8);
    // 0x800AFB00: addiu       $a3, $zero, 0x2C9
    ctx->r7 = ADD32(0, 0X2C9);
    // 0x800AFB04: lh          $t0, 0x3A($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x800AFB08: lh          $t1, 0x38($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X38));
    // 0x800AFB0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AFB10: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800AFB14: bne         $v0, $zero, L_800AFB24
    if (ctx->r2 != 0) {
        // 0x800AFB18: addiu       $t5, $zero, 0x2C8
        ctx->r13 = ADD32(0, 0X2C8);
            goto L_800AFB24;
    }
    // 0x800AFB18: addiu       $t5, $zero, 0x2C8
    ctx->r13 = ADD32(0, 0X2C8);
    // 0x800AFB1C: b           L_800B0570
    // 0x800AFB20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B0570;
    // 0x800AFB20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AFB24:
    // 0x800AFB24: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x800AFB28: lh          $a0, 0x2858($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2858));
    // 0x800AFB2C: addiu       $t4, $zero, 0x92
    ctx->r12 = ADD32(0, 0X92);
    // 0x800AFB30: bltz        $a0, L_800AFCF0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800AFB34: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_800AFCF0;
    }
    // 0x800AFB34: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
L_800AFB38:
    // 0x800AFB38: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800AFB3C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800AFB40: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800AFB44: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x800AFB48: addiu       $t6, $t6, 0x6BA8
    ctx->r14 = ADD32(ctx->r14, 0X6BA8);
    // 0x800AFB4C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800AFB50: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800AFB54: lh          $t8, 0x1E($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X1E));
    // 0x800AFB58: lh          $t7, 0x40($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800AFB5C: bnel        $t7, $t8, L_800AFCDC
    if (ctx->r15 != ctx->r24) {
        // 0x800AFB60: sll         $t6, $a0, 1
        ctx->r14 = S32(ctx->r4 << 1);
            goto L_800AFCDC;
    }
    goto skip_3;
    // 0x800AFB60: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    skip_3:
    // 0x800AFB64: lh          $a1, 0xE($v0)
    ctx->r5 = S32(MEM_H(ctx->r2, 0XE));
    // 0x800AFB68: slti        $at, $a1, 0x2CA
    ctx->r1 = SIGNED(ctx->r5) < 0X2CA ? 1 : 0;
    // 0x800AFB6C: bne         $at, $zero, L_800AFBC4
    if (ctx->r1 != 0) {
        // 0x800AFB70: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800AFBC4;
    }
    // 0x800AFB70: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800AFB74: slti        $at, $v1, 0x362
    ctx->r1 = SIGNED(ctx->r3) < 0X362 ? 1 : 0;
    // 0x800AFB78: bne         $at, $zero, L_800AFBA4
    if (ctx->r1 != 0) {
        // 0x800AFB7C: addiu       $t6, $v1, -0x35C
        ctx->r14 = ADD32(ctx->r3, -0X35C);
            goto L_800AFBA4;
    }
    // 0x800AFB7C: addiu       $t6, $v1, -0x35C
    ctx->r14 = ADD32(ctx->r3, -0X35C);
    // 0x800AFB80: addiu       $t9, $v1, -0x457
    ctx->r25 = ADD32(ctx->r3, -0X457);
    // 0x800AFB84: sltiu       $at, $t9, 0x21
    ctx->r1 = ctx->r25 < 0X21 ? 1 : 0;
    // 0x800AFB88: beq         $at, $zero, L_800AFCD8
    if (ctx->r1 == 0) {
        // 0x800AFB8C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800AFCD8;
    }
    // 0x800AFB8C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800AFB90: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AFB94: addu        $at, $at, $t9
    gpr jr_addend_800AFB9C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AFB98: lw          $t9, -0x77AC($at)
    ctx->r25 = ADD32(ctx->r1, -0X77AC);
    // 0x800AFB9C: jr          $t9
    // 0x800AFBA0: nop

    switch (jr_addend_800AFB9C >> 2) {
        case 0: goto L_800AFCC4; break;
        case 1: goto L_800AFCD0; break;
        case 2: goto L_800AFCD8; break;
        case 3: goto L_800AFCD8; break;
        case 4: goto L_800AFCD8; break;
        case 5: goto L_800AFCD8; break;
        case 6: goto L_800AFCD8; break;
        case 7: goto L_800AFCD8; break;
        case 8: goto L_800AFCD8; break;
        case 9: goto L_800AFCD8; break;
        case 10: goto L_800AFCD8; break;
        case 11: goto L_800AFCC4; break;
        case 12: goto L_800AFCD0; break;
        case 13: goto L_800AFCD8; break;
        case 14: goto L_800AFCD8; break;
        case 15: goto L_800AFCD8; break;
        case 16: goto L_800AFCD8; break;
        case 17: goto L_800AFCD8; break;
        case 18: goto L_800AFCD8; break;
        case 19: goto L_800AFCD8; break;
        case 20: goto L_800AFCD8; break;
        case 21: goto L_800AFCD8; break;
        case 22: goto L_800AFCD8; break;
        case 23: goto L_800AFCD8; break;
        case 24: goto L_800AFCD8; break;
        case 25: goto L_800AFCD8; break;
        case 26: goto L_800AFCD8; break;
        case 27: goto L_800AFCD8; break;
        case 28: goto L_800AFCD8; break;
        case 29: goto L_800AFCD8; break;
        case 30: goto L_800AFCD8; break;
        case 31: goto L_800AFC1C; break;
        case 32: goto L_800AFC60; break;
        default: switch_error(__func__, 0x800AFB9C, 0x80108854);
    }
    // 0x800AFBA0: nop

L_800AFBA4:
    // 0x800AFBA4: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x800AFBA8: beq         $at, $zero, L_800AFCD8
    if (ctx->r1 == 0) {
        // 0x800AFBAC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800AFCD8;
    }
    // 0x800AFBAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AFBB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AFBB4: addu        $at, $at, $t6
    gpr jr_addend_800AFBBC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AFBB8: lw          $t6, -0x7728($at)
    ctx->r14 = ADD32(ctx->r1, -0X7728);
    // 0x800AFBBC: jr          $t6
    // 0x800AFBC0: nop

    switch (jr_addend_800AFBBC >> 2) {
        case 0: goto L_800AFCC4; break;
        case 1: goto L_800AFCD0; break;
        case 2: goto L_800AFCC4; break;
        case 3: goto L_800AFCD0; break;
        case 4: goto L_800AFCC4; break;
        case 5: goto L_800AFCD0; break;
        default: switch_error(__func__, 0x800AFBBC, 0x801088D8);
    }
    // 0x800AFBC0: nop

L_800AFBC4:
    // 0x800AFBC4: slti        $at, $v1, 0x2C9
    ctx->r1 = SIGNED(ctx->r3) < 0X2C9 ? 1 : 0;
    // 0x800AFBC8: bnel        $at, $zero, L_800AFBE4
    if (ctx->r1 != 0) {
        // 0x800AFBCC: slti        $at, $v1, 0xAB
        ctx->r1 = SIGNED(ctx->r3) < 0XAB ? 1 : 0;
            goto L_800AFBE4;
    }
    goto skip_4;
    // 0x800AFBCC: slti        $at, $v1, 0xAB
    ctx->r1 = SIGNED(ctx->r3) < 0XAB ? 1 : 0;
    skip_4:
    // 0x800AFBD0: beql        $v1, $a3, L_800AFCD4
    if (ctx->r3 == ctx->r7) {
        // 0x800AFBD4: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_800AFCD4;
    }
    goto skip_5;
    // 0x800AFBD4: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    skip_5:
    // 0x800AFBD8: b           L_800AFCDC
    // 0x800AFBDC: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
        goto L_800AFCDC;
    // 0x800AFBDC: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800AFBE0: slti        $at, $v1, 0xAB
    ctx->r1 = SIGNED(ctx->r3) < 0XAB ? 1 : 0;
L_800AFBE4:
    // 0x800AFBE4: bne         $at, $zero, L_800AFBFC
    if (ctx->r1 != 0) {
        // 0x800AFBE8: addiu       $t7, $v1, -0x82
        ctx->r15 = ADD32(ctx->r3, -0X82);
            goto L_800AFBFC;
    }
    // 0x800AFBE8: addiu       $t7, $v1, -0x82
    ctx->r15 = ADD32(ctx->r3, -0X82);
    // 0x800AFBEC: beql        $v1, $t5, L_800AFCC8
    if (ctx->r3 == ctx->r13) {
        // 0x800AFBF0: addiu       $t8, $a1, 0x1
        ctx->r24 = ADD32(ctx->r5, 0X1);
            goto L_800AFCC8;
    }
    goto skip_6;
    // 0x800AFBF0: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    skip_6:
    // 0x800AFBF4: b           L_800AFCDC
    // 0x800AFBF8: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
        goto L_800AFCDC;
    // 0x800AFBF8: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
L_800AFBFC:
    // 0x800AFBFC: sltiu       $at, $t7, 0x29
    ctx->r1 = ctx->r15 < 0X29 ? 1 : 0;
    // 0x800AFC00: beq         $at, $zero, L_800AFCD8
    if (ctx->r1 == 0) {
        // 0x800AFC04: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800AFCD8;
    }
    // 0x800AFC04: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AFC08: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AFC0C: addu        $at, $at, $t7
    gpr jr_addend_800AFC14 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AFC10: lw          $t7, -0x7710($at)
    ctx->r15 = ADD32(ctx->r1, -0X7710);
    // 0x800AFC14: jr          $t7
    // 0x800AFC18: nop

    switch (jr_addend_800AFC14 >> 2) {
        case 0: goto L_800AFCC4; break;
        case 1: goto L_800AFCD8; break;
        case 2: goto L_800AFCC4; break;
        case 3: goto L_800AFCD0; break;
        case 4: goto L_800AFCC4; break;
        case 5: goto L_800AFCD0; break;
        case 6: goto L_800AFCC4; break;
        case 7: goto L_800AFCD0; break;
        case 8: goto L_800AFCC4; break;
        case 9: goto L_800AFCD0; break;
        case 10: goto L_800AFCC4; break;
        case 11: goto L_800AFCD0; break;
        case 12: goto L_800AFCD8; break;
        case 13: goto L_800AFCD8; break;
        case 14: goto L_800AFCD8; break;
        case 15: goto L_800AFCD8; break;
        case 16: goto L_800AFCA4; break;
        case 17: goto L_800AFCA4; break;
        case 18: goto L_800AFCA4; break;
        case 19: goto L_800AFCA4; break;
        case 20: goto L_800AFCD8; break;
        case 21: goto L_800AFCD8; break;
        case 22: goto L_800AFCD8; break;
        case 23: goto L_800AFCD8; break;
        case 24: goto L_800AFCD8; break;
        case 25: goto L_800AFCD8; break;
        case 26: goto L_800AFCD8; break;
        case 27: goto L_800AFCD8; break;
        case 28: goto L_800AFCD8; break;
        case 29: goto L_800AFCD8; break;
        case 30: goto L_800AFCD8; break;
        case 31: goto L_800AFCD8; break;
        case 32: goto L_800AFC1C; break;
        case 33: goto L_800AFC60; break;
        case 34: goto L_800AFCC4; break;
        case 35: goto L_800AFCD0; break;
        case 36: goto L_800AFC1C; break;
        case 37: goto L_800AFC60; break;
        case 38: goto L_800AFCC4; break;
        case 39: goto L_800AFCD0; break;
        case 40: goto L_800AFCC4; break;
        default: switch_error(__func__, 0x800AFC14, 0x801088F0);
    }
    // 0x800AFC18: nop

L_800AFC1C:
    // 0x800AFC1C: bne         $t2, $t3, L_800AFC3C
    if (ctx->r10 != ctx->r11) {
        // 0x800AFC20: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800AFC3C;
    }
    // 0x800AFC20: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800AFC24: lw          $t8, 0x4C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AFC28: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x800AFC2C: bnel        $a0, $t8, L_800AFC40
    if (ctx->r4 != ctx->r24) {
        // 0x800AFC30: lh          $t6, 0x20($v0)
        ctx->r14 = S32(MEM_H(ctx->r2, 0X20));
            goto L_800AFC40;
    }
    goto skip_7;
    // 0x800AFC30: lh          $t6, 0x20($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X20));
    skip_7:
    // 0x800AFC34: b           L_800AFC54
    // 0x800AFC38: sh          $t9, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r25;
        goto L_800AFC54;
    // 0x800AFC38: sh          $t9, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r25;
L_800AFC3C:
    // 0x800AFC3C: lh          $t6, 0x20($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X20));
L_800AFC40:
    // 0x800AFC40: bnel        $t6, $zero, L_800AFC58
    if (ctx->r14 != 0) {
        // 0x800AFC44: sll         $t9, $t1, 16
        ctx->r25 = S32(ctx->r9 << 16);
            goto L_800AFC58;
    }
    goto skip_8;
    // 0x800AFC44: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    skip_8:
    // 0x800AFC48: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AFC4C: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800AFC50: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
L_800AFC54:
    // 0x800AFC54: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
L_800AFC58:
    // 0x800AFC58: b           L_800AFCD8
    // 0x800AFC5C: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
        goto L_800AFCD8;
    // 0x800AFC5C: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
L_800AFC60:
    // 0x800AFC60: bne         $t2, $t3, L_800AFC80
    if (ctx->r10 != ctx->r11) {
        // 0x800AFC64: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800AFC80;
    }
    // 0x800AFC64: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800AFC68: lw          $t7, 0x4C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AFC6C: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x800AFC70: bnel        $a0, $t7, L_800AFC84
    if (ctx->r4 != ctx->r15) {
        // 0x800AFC74: lh          $t9, 0x20($v0)
        ctx->r25 = S32(MEM_H(ctx->r2, 0X20));
            goto L_800AFC84;
    }
    goto skip_9;
    // 0x800AFC74: lh          $t9, 0x20($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X20));
    skip_9:
    // 0x800AFC78: b           L_800AFC98
    // 0x800AFC7C: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
        goto L_800AFC98;
    // 0x800AFC7C: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
L_800AFC80:
    // 0x800AFC80: lh          $t9, 0x20($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X20));
L_800AFC84:
    // 0x800AFC84: bnel        $t2, $t9, L_800AFC9C
    if (ctx->r10 != ctx->r25) {
        // 0x800AFC88: sll         $t8, $t1, 16
        ctx->r24 = S32(ctx->r9 << 16);
            goto L_800AFC9C;
    }
    goto skip_10;
    // 0x800AFC88: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    skip_10:
    // 0x800AFC8C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AFC90: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x800AFC94: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
L_800AFC98:
    // 0x800AFC98: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
L_800AFC9C:
    // 0x800AFC9C: b           L_800AFCD8
    // 0x800AFCA0: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
        goto L_800AFCD8;
    // 0x800AFCA0: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
L_800AFCA4:
    // 0x800AFCA4: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x800AFCA8: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x800AFCAC: lh          $t7, 0xE($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0XE));
    // 0x800AFCB0: slti        $at, $t7, 0x96
    ctx->r1 = SIGNED(ctx->r15) < 0X96 ? 1 : 0;
    // 0x800AFCB4: bnel        $at, $zero, L_800AFCDC
    if (ctx->r1 != 0) {
        // 0x800AFCB8: sll         $t6, $a0, 1
        ctx->r14 = S32(ctx->r4 << 1);
            goto L_800AFCDC;
    }
    goto skip_11;
    // 0x800AFCB8: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    skip_11:
    // 0x800AFCBC: b           L_800AFCD8
    // 0x800AFCC0: sh          $t4, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r12;
        goto L_800AFCD8;
    // 0x800AFCC0: sh          $t4, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r12;
L_800AFCC4:
    // 0x800AFCC4: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
L_800AFCC8:
    // 0x800AFCC8: b           L_800AFCD8
    // 0x800AFCCC: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
        goto L_800AFCD8;
    // 0x800AFCCC: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
L_800AFCD0:
    // 0x800AFCD0: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
L_800AFCD4:
    // 0x800AFCD4: sh          $t9, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r25;
L_800AFCD8:
    // 0x800AFCD8: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
L_800AFCDC:
    // 0x800AFCDC: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x800AFCE0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800AFCE4: lh          $a0, 0x5F40($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X5F40));
    // 0x800AFCE8: bgezl       $a0, L_800AFB38
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800AFCEC: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_800AFB38;
    }
    goto skip_12;
    // 0x800AFCEC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    skip_12:
L_800AFCF0:
    // 0x800AFCF0: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800AFCF4: lh          $a2, -0x5376($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X5376));
    // 0x800AFCF8: addiu       $t4, $zero, 0x92
    ctx->r12 = ADD32(0, 0X92);
    // 0x800AFCFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AFD00: blez        $a2, L_800AFEB0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AFD04: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_800AFEB0;
    }
    // 0x800AFD04: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
L_800AFD08:
    // 0x800AFD08: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800AFD0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AFD10: addu        $v0, $ra, $t7
    ctx->r2 = ADD32(ctx->r31, ctx->r15);
    // 0x800AFD14: lh          $t9, 0x14($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800AFD18: lh          $t8, 0x40($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800AFD1C: bnel        $t8, $t9, L_800AFE9C
    if (ctx->r24 != ctx->r25) {
        // 0x800AFD20: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800AFE9C;
    }
    goto skip_13;
    // 0x800AFD20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_13:
    // 0x800AFD24: lh          $a1, 0x10($v0)
    ctx->r5 = S32(MEM_H(ctx->r2, 0X10));
    // 0x800AFD28: slti        $at, $a1, 0x2CA
    ctx->r1 = SIGNED(ctx->r5) < 0X2CA ? 1 : 0;
    // 0x800AFD2C: bne         $at, $zero, L_800AFD84
    if (ctx->r1 != 0) {
        // 0x800AFD30: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800AFD84;
    }
    // 0x800AFD30: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800AFD34: slti        $at, $v1, 0x362
    ctx->r1 = SIGNED(ctx->r3) < 0X362 ? 1 : 0;
    // 0x800AFD38: bne         $at, $zero, L_800AFD64
    if (ctx->r1 != 0) {
        // 0x800AFD3C: addiu       $t7, $v1, -0x35C
        ctx->r15 = ADD32(ctx->r3, -0X35C);
            goto L_800AFD64;
    }
    // 0x800AFD3C: addiu       $t7, $v1, -0x35C
    ctx->r15 = ADD32(ctx->r3, -0X35C);
    // 0x800AFD40: addiu       $t6, $v1, -0x457
    ctx->r14 = ADD32(ctx->r3, -0X457);
    // 0x800AFD44: sltiu       $at, $t6, 0x21
    ctx->r1 = ctx->r14 < 0X21 ? 1 : 0;
    // 0x800AFD48: beq         $at, $zero, L_800AFE98
    if (ctx->r1 == 0) {
        // 0x800AFD4C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800AFE98;
    }
    // 0x800AFD4C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AFD50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AFD54: addu        $at, $at, $t6
    gpr jr_addend_800AFD5C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AFD58: lw          $t6, -0x766C($at)
    ctx->r14 = ADD32(ctx->r1, -0X766C);
    // 0x800AFD5C: jr          $t6
    // 0x800AFD60: nop

    switch (jr_addend_800AFD5C >> 2) {
        case 0: goto L_800AFE84; break;
        case 1: goto L_800AFE90; break;
        case 2: goto L_800AFE98; break;
        case 3: goto L_800AFE98; break;
        case 4: goto L_800AFE98; break;
        case 5: goto L_800AFE98; break;
        case 6: goto L_800AFE98; break;
        case 7: goto L_800AFE98; break;
        case 8: goto L_800AFE98; break;
        case 9: goto L_800AFE98; break;
        case 10: goto L_800AFE98; break;
        case 11: goto L_800AFE84; break;
        case 12: goto L_800AFE90; break;
        case 13: goto L_800AFE98; break;
        case 14: goto L_800AFE98; break;
        case 15: goto L_800AFE98; break;
        case 16: goto L_800AFE98; break;
        case 17: goto L_800AFE98; break;
        case 18: goto L_800AFE98; break;
        case 19: goto L_800AFE98; break;
        case 20: goto L_800AFE98; break;
        case 21: goto L_800AFE98; break;
        case 22: goto L_800AFE98; break;
        case 23: goto L_800AFE98; break;
        case 24: goto L_800AFE98; break;
        case 25: goto L_800AFE98; break;
        case 26: goto L_800AFE98; break;
        case 27: goto L_800AFE98; break;
        case 28: goto L_800AFE98; break;
        case 29: goto L_800AFE98; break;
        case 30: goto L_800AFE98; break;
        case 31: goto L_800AFDDC; break;
        case 32: goto L_800AFE20; break;
        default: switch_error(__func__, 0x800AFD5C, 0x80108994);
    }
    // 0x800AFD60: nop

L_800AFD64:
    // 0x800AFD64: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x800AFD68: beq         $at, $zero, L_800AFE98
    if (ctx->r1 == 0) {
        // 0x800AFD6C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800AFE98;
    }
    // 0x800AFD6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AFD70: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AFD74: addu        $at, $at, $t7
    gpr jr_addend_800AFD7C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AFD78: lw          $t7, -0x75E8($at)
    ctx->r15 = ADD32(ctx->r1, -0X75E8);
    // 0x800AFD7C: jr          $t7
    // 0x800AFD80: nop

    switch (jr_addend_800AFD7C >> 2) {
        case 0: goto L_800AFE84; break;
        case 1: goto L_800AFE90; break;
        case 2: goto L_800AFE84; break;
        case 3: goto L_800AFE90; break;
        case 4: goto L_800AFE84; break;
        case 5: goto L_800AFE90; break;
        default: switch_error(__func__, 0x800AFD7C, 0x80108A18);
    }
    // 0x800AFD80: nop

L_800AFD84:
    // 0x800AFD84: slti        $at, $v1, 0x2C9
    ctx->r1 = SIGNED(ctx->r3) < 0X2C9 ? 1 : 0;
    // 0x800AFD88: bnel        $at, $zero, L_800AFDA4
    if (ctx->r1 != 0) {
        // 0x800AFD8C: slti        $at, $v1, 0xAB
        ctx->r1 = SIGNED(ctx->r3) < 0XAB ? 1 : 0;
            goto L_800AFDA4;
    }
    goto skip_14;
    // 0x800AFD8C: slti        $at, $v1, 0xAB
    ctx->r1 = SIGNED(ctx->r3) < 0XAB ? 1 : 0;
    skip_14:
    // 0x800AFD90: beql        $v1, $a3, L_800AFE94
    if (ctx->r3 == ctx->r7) {
        // 0x800AFD94: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_800AFE94;
    }
    goto skip_15;
    // 0x800AFD94: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_15:
    // 0x800AFD98: b           L_800AFE9C
    // 0x800AFD9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800AFE9C;
    // 0x800AFD9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800AFDA0: slti        $at, $v1, 0xAB
    ctx->r1 = SIGNED(ctx->r3) < 0XAB ? 1 : 0;
L_800AFDA4:
    // 0x800AFDA4: bne         $at, $zero, L_800AFDBC
    if (ctx->r1 != 0) {
        // 0x800AFDA8: addiu       $t8, $v1, -0x82
        ctx->r24 = ADD32(ctx->r3, -0X82);
            goto L_800AFDBC;
    }
    // 0x800AFDA8: addiu       $t8, $v1, -0x82
    ctx->r24 = ADD32(ctx->r3, -0X82);
    // 0x800AFDAC: beql        $v1, $t5, L_800AFE88
    if (ctx->r3 == ctx->r13) {
        // 0x800AFDB0: addiu       $t9, $a1, 0x1
        ctx->r25 = ADD32(ctx->r5, 0X1);
            goto L_800AFE88;
    }
    goto skip_16;
    // 0x800AFDB0: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    skip_16:
    // 0x800AFDB4: b           L_800AFE9C
    // 0x800AFDB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800AFE9C;
    // 0x800AFDB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800AFDBC:
    // 0x800AFDBC: sltiu       $at, $t8, 0x29
    ctx->r1 = ctx->r24 < 0X29 ? 1 : 0;
    // 0x800AFDC0: beq         $at, $zero, L_800AFE98
    if (ctx->r1 == 0) {
        // 0x800AFDC4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800AFE98;
    }
    // 0x800AFDC4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800AFDC8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AFDCC: addu        $at, $at, $t8
    gpr jr_addend_800AFDD4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800AFDD0: lw          $t8, -0x75D0($at)
    ctx->r24 = ADD32(ctx->r1, -0X75D0);
    // 0x800AFDD4: jr          $t8
    // 0x800AFDD8: nop

    switch (jr_addend_800AFDD4 >> 2) {
        case 0: goto L_800AFE84; break;
        case 1: goto L_800AFE98; break;
        case 2: goto L_800AFE84; break;
        case 3: goto L_800AFE90; break;
        case 4: goto L_800AFE84; break;
        case 5: goto L_800AFE90; break;
        case 6: goto L_800AFE84; break;
        case 7: goto L_800AFE90; break;
        case 8: goto L_800AFE84; break;
        case 9: goto L_800AFE90; break;
        case 10: goto L_800AFE98; break;
        case 11: goto L_800AFE98; break;
        case 12: goto L_800AFE98; break;
        case 13: goto L_800AFE98; break;
        case 14: goto L_800AFE98; break;
        case 15: goto L_800AFE98; break;
        case 16: goto L_800AFE64; break;
        case 17: goto L_800AFE64; break;
        case 18: goto L_800AFE64; break;
        case 19: goto L_800AFE64; break;
        case 20: goto L_800AFE98; break;
        case 21: goto L_800AFE98; break;
        case 22: goto L_800AFE98; break;
        case 23: goto L_800AFE98; break;
        case 24: goto L_800AFE98; break;
        case 25: goto L_800AFE98; break;
        case 26: goto L_800AFE98; break;
        case 27: goto L_800AFE98; break;
        case 28: goto L_800AFE98; break;
        case 29: goto L_800AFE98; break;
        case 30: goto L_800AFE98; break;
        case 31: goto L_800AFE98; break;
        case 32: goto L_800AFDDC; break;
        case 33: goto L_800AFE20; break;
        case 34: goto L_800AFE84; break;
        case 35: goto L_800AFE90; break;
        case 36: goto L_800AFDDC; break;
        case 37: goto L_800AFE20; break;
        case 38: goto L_800AFE84; break;
        case 39: goto L_800AFE90; break;
        case 40: goto L_800AFE84; break;
        default: switch_error(__func__, 0x800AFDD4, 0x80108A30);
    }
    // 0x800AFDD8: nop

L_800AFDDC:
    // 0x800AFDDC: bne         $t3, $zero, L_800AFDFC
    if (ctx->r11 != 0) {
        // 0x800AFDE0: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800AFDFC;
    }
    // 0x800AFDE0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800AFDE4: lw          $t9, 0x4C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AFDE8: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x800AFDEC: bnel        $a0, $t9, L_800AFE00
    if (ctx->r4 != ctx->r25) {
        // 0x800AFDF0: lh          $t7, 0x16($v0)
        ctx->r15 = S32(MEM_H(ctx->r2, 0X16));
            goto L_800AFE00;
    }
    goto skip_17;
    // 0x800AFDF0: lh          $t7, 0x16($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X16));
    skip_17:
    // 0x800AFDF4: b           L_800AFE14
    // 0x800AFDF8: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
        goto L_800AFE14;
    // 0x800AFDF8: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
L_800AFDFC:
    // 0x800AFDFC: lh          $t7, 0x16($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X16));
L_800AFE00:
    // 0x800AFE00: bnel        $t7, $zero, L_800AFE18
    if (ctx->r15 != 0) {
        // 0x800AFE04: sll         $t6, $t1, 16
        ctx->r14 = S32(ctx->r9 << 16);
            goto L_800AFE18;
    }
    goto skip_18;
    // 0x800AFE04: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    skip_18:
    // 0x800AFE08: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AFE0C: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x800AFE10: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
L_800AFE14:
    // 0x800AFE14: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
L_800AFE18:
    // 0x800AFE18: b           L_800AFE98
    // 0x800AFE1C: sra         $t1, $t6, 16
    ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
        goto L_800AFE98;
    // 0x800AFE1C: sra         $t1, $t6, 16
    ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
L_800AFE20:
    // 0x800AFE20: bne         $t3, $zero, L_800AFE40
    if (ctx->r11 != 0) {
        // 0x800AFE24: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800AFE40;
    }
    // 0x800AFE24: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800AFE28: lw          $t8, 0x4C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AFE2C: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800AFE30: bnel        $a0, $t8, L_800AFE44
    if (ctx->r4 != ctx->r24) {
        // 0x800AFE34: lh          $t6, 0x16($v0)
        ctx->r14 = S32(MEM_H(ctx->r2, 0X16));
            goto L_800AFE44;
    }
    goto skip_19;
    // 0x800AFE34: lh          $t6, 0x16($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X16));
    skip_19:
    // 0x800AFE38: b           L_800AFE58
    // 0x800AFE3C: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
        goto L_800AFE58;
    // 0x800AFE3C: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
L_800AFE40:
    // 0x800AFE40: lh          $t6, 0x16($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X16));
L_800AFE44:
    // 0x800AFE44: bnel        $t2, $t6, L_800AFE5C
    if (ctx->r10 != ctx->r14) {
        // 0x800AFE48: sll         $t9, $t1, 16
        ctx->r25 = S32(ctx->r9 << 16);
            goto L_800AFE5C;
    }
    goto skip_20;
    // 0x800AFE48: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    skip_20:
    // 0x800AFE4C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AFE50: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800AFE54: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
L_800AFE58:
    // 0x800AFE58: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
L_800AFE5C:
    // 0x800AFE5C: b           L_800AFE98
    // 0x800AFE60: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
        goto L_800AFE98;
    // 0x800AFE60: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
L_800AFE64:
    // 0x800AFE64: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x800AFE68: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x800AFE6C: lh          $t8, 0x10($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X10));
    // 0x800AFE70: slti        $at, $t8, 0x96
    ctx->r1 = SIGNED(ctx->r24) < 0X96 ? 1 : 0;
    // 0x800AFE74: bnel        $at, $zero, L_800AFE9C
    if (ctx->r1 != 0) {
        // 0x800AFE78: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800AFE9C;
    }
    goto skip_21;
    // 0x800AFE78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_21:
    // 0x800AFE7C: b           L_800AFE98
    // 0x800AFE80: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
        goto L_800AFE98;
    // 0x800AFE80: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
L_800AFE84:
    // 0x800AFE84: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
L_800AFE88:
    // 0x800AFE88: b           L_800AFE98
    // 0x800AFE8C: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
        goto L_800AFE98;
    // 0x800AFE8C: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
L_800AFE90:
    // 0x800AFE90: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_800AFE94:
    // 0x800AFE94: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
L_800AFE98:
    // 0x800AFE98: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800AFE9C:
    // 0x800AFE9C: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800AFEA0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800AFEA4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AFEA8: bnel        $at, $zero, L_800AFD08
    if (ctx->r1 != 0) {
        // 0x800AFEAC: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_800AFD08;
    }
    goto skip_22;
    // 0x800AFEAC: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    skip_22:
L_800AFEB0:
    // 0x800AFEB0: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x800AFEB4: addiu       $v0, $v0, -0x5598
    ctx->r2 = ADD32(ctx->r2, -0X5598);
    // 0x800AFEB8: lw          $t9, 0x18C($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X18C));
    // 0x800AFEBC: lh          $t8, 0x40($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800AFEC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AFEC4: beq         $t2, $t9, L_800AFEE8
    if (ctx->r10 == ctx->r25) {
        // 0x800AFEC8: nop
    
            goto L_800AFEE8;
    }
    // 0x800AFEC8: nop

    // 0x800AFECC: lw          $t6, 0x13C($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X13C));
    // 0x800AFED0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800AFED4: beq         $t2, $t6, L_800AFEE8
    if (ctx->r10 == ctx->r14) {
        // 0x800AFED8: nop
    
            goto L_800AFEE8;
    }
    // 0x800AFED8: nop

    // 0x800AFEDC: lbu         $t7, 0x378C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X378C);
    // 0x800AFEE0: bnel        $t2, $t7, L_800AFF8C
    if (ctx->r10 != ctx->r15) {
        // 0x800AFEE4: lh          $t8, 0x3C($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
            goto L_800AFF8C;
    }
    goto skip_23;
    // 0x800AFEE4: lh          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
    skip_23:
L_800AFEE8:
    // 0x800AFEE8: bne         $t8, $at, L_800AFF88
    if (ctx->r24 != ctx->r1) {
        // 0x800AFEEC: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_800AFF88;
    }
    // 0x800AFEEC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800AFEF0: lh          $t6, -0x9D8($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X9D8));
    // 0x800AFEF4: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x800AFEF8: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x800AFEFC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800AFF00: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800AFF04: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800AFF08: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800AFF0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AFF10: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800AFF14: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AFF18: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AFF1C: sb          $t9, 0x5AA8($at)
    MEM_B(0X5AA8, ctx->r1) = ctx->r25;
    // 0x800AFF20: lh          $v1, 0xEA($v0)
    ctx->r3 = S32(MEM_H(ctx->r2, 0XEA));
    // 0x800AFF24: beql        $v1, $zero, L_800AFF44
    if (ctx->r3 == 0) {
        // 0x800AFF28: lw          $t6, 0x194($v0)
        ctx->r14 = S32(MEM_W(ctx->r2, 0X194));
            goto L_800AFF44;
    }
    goto skip_24;
    // 0x800AFF28: lw          $t6, 0x194($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X194));
    skip_24:
    // 0x800AFF2C: sw          $v1, 0x194($v0)
    MEM_W(0X194, ctx->r2) = ctx->r3;
    // 0x800AFF30: sw          $v1, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r3;
    // 0x800AFF34: sh          $zero, 0xEA($v0)
    MEM_H(0XEA, ctx->r2) = 0;
    // 0x800AFF38: b           L_800B0570
    // 0x800AFF3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B0570;
    // 0x800AFF3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AFF40: lw          $t6, 0x194($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X194));
L_800AFF44:
    // 0x800AFF44: lw          $a0, 0x198($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X198));
    // 0x800AFF48: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800AFF4C: beq         $a0, $zero, L_800AFF60
    if (ctx->r4 == 0) {
        // 0x800AFF50: sw          $t9, 0x194($v0)
        MEM_W(0X194, ctx->r2) = ctx->r25;
            goto L_800AFF60;
    }
    // 0x800AFF50: sw          $t9, 0x194($v0)
    MEM_W(0X194, ctx->r2) = ctx->r25;
    // 0x800AFF54: slti        $at, $t9, 0xB
    ctx->r1 = SIGNED(ctx->r25) < 0XB ? 1 : 0;
    // 0x800AFF58: beql        $at, $zero, L_800AFF78
    if (ctx->r1 == 0) {
        // 0x800AFF5C: sw          $zero, 0x194($v0)
        MEM_W(0X194, ctx->r2) = 0;
            goto L_800AFF78;
    }
    goto skip_25;
    // 0x800AFF5C: sw          $zero, 0x194($v0)
    MEM_W(0X194, ctx->r2) = 0;
    skip_25:
L_800AFF60:
    // 0x800AFF60: bne         $a0, $zero, L_800AFF7C
    if (ctx->r4 != 0) {
        // 0x800AFF64: lw          $v1, 0x194($v0)
        ctx->r3 = S32(MEM_W(ctx->r2, 0X194));
            goto L_800AFF7C;
    }
    // 0x800AFF64: lw          $v1, 0x194($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0X194));
    // 0x800AFF68: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x800AFF6C: bnel        $at, $zero, L_800AFF80
    if (ctx->r1 != 0) {
        // 0x800AFF70: sw          $v1, 0x184($v0)
        MEM_W(0X184, ctx->r2) = ctx->r3;
            goto L_800AFF80;
    }
    goto skip_26;
    // 0x800AFF70: sw          $v1, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r3;
    skip_26:
    // 0x800AFF74: sw          $zero, 0x194($v0)
    MEM_W(0X194, ctx->r2) = 0;
L_800AFF78:
    // 0x800AFF78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800AFF7C:
    // 0x800AFF7C: sw          $v1, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r3;
L_800AFF80:
    // 0x800AFF80: b           L_800B0570
    // 0x800AFF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B0570;
    // 0x800AFF84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AFF88:
    // 0x800AFF88: lh          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
L_800AFF8C:
    // 0x800AFF8C: lh          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800AFF90: slti        $at, $t8, 0x2CA
    ctx->r1 = SIGNED(ctx->r24) < 0X2CA ? 1 : 0;
    // 0x800AFF94: bne         $at, $zero, L_800AFFEC
    if (ctx->r1 != 0) {
        // 0x800AFF98: slti        $at, $t8, 0x362
        ctx->r1 = SIGNED(ctx->r24) < 0X362 ? 1 : 0;
            goto L_800AFFEC;
    }
    // 0x800AFF98: slti        $at, $t8, 0x362
    ctx->r1 = SIGNED(ctx->r24) < 0X362 ? 1 : 0;
    // 0x800AFF9C: bne         $at, $zero, L_800AFFC8
    if (ctx->r1 != 0) {
        // 0x800AFFA0: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800AFFC8;
    }
    // 0x800AFFA0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800AFFA4: addiu       $t6, $t8, -0x457
    ctx->r14 = ADD32(ctx->r24, -0X457);
    // 0x800AFFA8: sltiu       $at, $t6, 0x21
    ctx->r1 = ctx->r14 < 0X21 ? 1 : 0;
    // 0x800AFFAC: beq         $at, $zero, L_800B0048
    if (ctx->r1 == 0) {
        // 0x800AFFB0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B0048;
    }
    // 0x800AFFB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AFFB4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AFFB8: addu        $at, $at, $t6
    gpr jr_addend_800AFFC0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AFFBC: lw          $t6, -0x752C($at)
    ctx->r14 = ADD32(ctx->r1, -0X752C);
    // 0x800AFFC0: jr          $t6
    // 0x800AFFC4: nop

    switch (jr_addend_800AFFC0 >> 2) {
        case 0: goto L_800B0214; break;
        case 1: goto L_800B0214; break;
        case 2: goto L_800B0048; break;
        case 3: goto L_800B0048; break;
        case 4: goto L_800B0048; break;
        case 5: goto L_800B0048; break;
        case 6: goto L_800B0048; break;
        case 7: goto L_800B0048; break;
        case 8: goto L_800B0048; break;
        case 9: goto L_800B0048; break;
        case 10: goto L_800B0048; break;
        case 11: goto L_800B0214; break;
        case 12: goto L_800B0214; break;
        case 13: goto L_800B0048; break;
        case 14: goto L_800B0048; break;
        case 15: goto L_800B0048; break;
        case 16: goto L_800B0048; break;
        case 17: goto L_800B0048; break;
        case 18: goto L_800B0048; break;
        case 19: goto L_800B0048; break;
        case 20: goto L_800B0048; break;
        case 21: goto L_800B0048; break;
        case 22: goto L_800B0048; break;
        case 23: goto L_800B0048; break;
        case 24: goto L_800B0048; break;
        case 25: goto L_800B0048; break;
        case 26: goto L_800B0048; break;
        case 27: goto L_800B0048; break;
        case 28: goto L_800B0048; break;
        case 29: goto L_800B0048; break;
        case 30: goto L_800B0048; break;
        case 31: goto L_800B0074; break;
        case 32: goto L_800B0074; break;
        default: switch_error(__func__, 0x800AFFC0, 0x80108AD4);
    }
    // 0x800AFFC4: nop

L_800AFFC8:
    // 0x800AFFC8: addiu       $t9, $v0, -0x35C
    ctx->r25 = ADD32(ctx->r2, -0X35C);
    // 0x800AFFCC: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x800AFFD0: beq         $at, $zero, L_800B0048
    if (ctx->r1 == 0) {
        // 0x800AFFD4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800B0048;
    }
    // 0x800AFFD4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800AFFD8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800AFFDC: addu        $at, $at, $t9
    gpr jr_addend_800AFFE4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AFFE0: lw          $t9, -0x74A8($at)
    ctx->r25 = ADD32(ctx->r1, -0X74A8);
    // 0x800AFFE4: jr          $t9
    // 0x800AFFE8: nop

    switch (jr_addend_800AFFE4 >> 2) {
        case 0: goto L_800B0214; break;
        case 1: goto L_800B0214; break;
        case 2: goto L_800B0214; break;
        case 3: goto L_800B0214; break;
        case 4: goto L_800B0214; break;
        case 5: goto L_800B0214; break;
        default: switch_error(__func__, 0x800AFFE4, 0x80108B58);
    }
    // 0x800AFFE8: nop

L_800AFFEC:
    // 0x800AFFEC: slti        $at, $t7, 0x2C9
    ctx->r1 = SIGNED(ctx->r15) < 0X2C9 ? 1 : 0;
    // 0x800AFFF0: bne         $at, $zero, L_800B0008
    if (ctx->r1 != 0) {
        // 0x800AFFF4: lh          $t8, 0x3C($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
            goto L_800B0008;
    }
    // 0x800AFFF4: lh          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800AFFF8: beql        $t7, $a3, L_800B0218
    if (ctx->r15 == ctx->r7) {
        // 0x800AFFFC: lh          $t9, 0x4A($sp)
        ctx->r25 = S32(MEM_H(ctx->r29, 0X4A));
            goto L_800B0218;
    }
    goto skip_27;
    // 0x800AFFFC: lh          $t9, 0x4A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X4A));
    skip_27:
    // 0x800B0000: b           L_800B004C
    // 0x800B0004: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
        goto L_800B004C;
    // 0x800B0004: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
L_800B0008:
    // 0x800B0008: slti        $at, $t8, 0xAB
    ctx->r1 = SIGNED(ctx->r24) < 0XAB ? 1 : 0;
    // 0x800B000C: bne         $at, $zero, L_800B0024
    if (ctx->r1 != 0) {
        // 0x800B0010: lh          $t6, 0x3C($sp)
        ctx->r14 = S32(MEM_H(ctx->r29, 0X3C));
            goto L_800B0024;
    }
    // 0x800B0010: lh          $t6, 0x3C($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800B0014: beql        $t8, $t5, L_800B0218
    if (ctx->r24 == ctx->r13) {
        // 0x800B0018: lh          $t9, 0x4A($sp)
        ctx->r25 = S32(MEM_H(ctx->r29, 0X4A));
            goto L_800B0218;
    }
    goto skip_28;
    // 0x800B0018: lh          $t9, 0x4A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X4A));
    skip_28:
    // 0x800B001C: b           L_800B004C
    // 0x800B0020: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
        goto L_800B004C;
    // 0x800B0020: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
L_800B0024:
    // 0x800B0024: addiu       $t9, $t6, -0x82
    ctx->r25 = ADD32(ctx->r14, -0X82);
    // 0x800B0028: sltiu       $at, $t9, 0x29
    ctx->r1 = ctx->r25 < 0X29 ? 1 : 0;
    // 0x800B002C: beq         $at, $zero, L_800B0048
    if (ctx->r1 == 0) {
        // 0x800B0030: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800B0048;
    }
    // 0x800B0030: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B0034: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B0038: addu        $at, $at, $t9
    gpr jr_addend_800B0040 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B003C: lw          $t9, -0x7490($at)
    ctx->r25 = ADD32(ctx->r1, -0X7490);
    // 0x800B0040: jr          $t9
    // 0x800B0044: nop

    switch (jr_addend_800B0040 >> 2) {
        case 0: goto L_800B0214; break;
        case 1: goto L_800B0048; break;
        case 2: goto L_800B0214; break;
        case 3: goto L_800B0214; break;
        case 4: goto L_800B0214; break;
        case 5: goto L_800B0214; break;
        case 6: goto L_800B0214; break;
        case 7: goto L_800B0214; break;
        case 8: goto L_800B0214; break;
        case 9: goto L_800B0214; break;
        case 10: goto L_800B0214; break;
        case 11: goto L_800B0214; break;
        case 12: goto L_800B0048; break;
        case 13: goto L_800B0048; break;
        case 14: goto L_800B0048; break;
        case 15: goto L_800B0048; break;
        case 16: goto L_800B0214; break;
        case 17: goto L_800B0214; break;
        case 18: goto L_800B0214; break;
        case 19: goto L_800B0214; break;
        case 20: goto L_800B0048; break;
        case 21: goto L_800B0048; break;
        case 22: goto L_800B0048; break;
        case 23: goto L_800B0048; break;
        case 24: goto L_800B0048; break;
        case 25: goto L_800B0048; break;
        case 26: goto L_800B0048; break;
        case 27: goto L_800B0048; break;
        case 28: goto L_800B0048; break;
        case 29: goto L_800B0048; break;
        case 30: goto L_800B0048; break;
        case 31: goto L_800B0048; break;
        case 32: goto L_800B0074; break;
        case 33: goto L_800B0074; break;
        case 34: goto L_800B0214; break;
        case 35: goto L_800B0214; break;
        case 36: goto L_800B0074; break;
        case 37: goto L_800B0074; break;
        case 38: goto L_800B0214; break;
        case 39: goto L_800B0214; break;
        case 40: goto L_800B0214; break;
        default: switch_error(__func__, 0x800B0040, 0x80108B70);
    }
    // 0x800B0044: nop

L_800B0048:
    // 0x800B0048: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
L_800B004C:
    // 0x800B004C: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x800B0050: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x800B0054: jal         0x800ACC8C
    // 0x800B0058: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    isadoorwall(rdram, ctx);
        goto after_5;
    // 0x800B0058: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_5:
    // 0x800B005C: lh          $t0, 0x3A($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x800B0060: lh          $t1, 0x38($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X38));
    // 0x800B0064: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B0068: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800B006C: beq         $v0, $zero, L_800B056C
    if (ctx->r2 == 0) {
        // 0x800B0070: addiu       $t4, $zero, 0x92
        ctx->r12 = ADD32(0, 0X92);
            goto L_800B056C;
    }
    // 0x800B0070: addiu       $t4, $zero, 0x92
    ctx->r12 = ADD32(0, 0X92);
L_800B0074:
    // 0x800B0074: lh          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800B0078: lh          $t8, 0x4A($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X4A));
    // 0x800B007C: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x800B0080: beq         $t7, $at, L_800B00B0
    if (ctx->r15 == ctx->r1) {
        // 0x800B0084: sll         $t6, $t8, 3
        ctx->r14 = S32(ctx->r24 << 3);
            goto L_800B00B0;
    }
    // 0x800B0084: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800B0088: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x800B008C: beq         $t7, $at, L_800B00B0
    if (ctx->r15 == ctx->r1) {
        // 0x800B0090: addiu       $at, $zero, 0x476
        ctx->r1 = ADD32(0, 0X476);
            goto L_800B00B0;
    }
    // 0x800B0090: addiu       $at, $zero, 0x476
    ctx->r1 = ADD32(0, 0X476);
    // 0x800B0094: beq         $t7, $at, L_800B00B0
    if (ctx->r15 == ctx->r1) {
        // 0x800B0098: addiu       $at, $zero, 0x477
        ctx->r1 = ADD32(0, 0X477);
            goto L_800B00B0;
    }
    // 0x800B0098: addiu       $at, $zero, 0x477
    ctx->r1 = ADD32(0, 0X477);
    // 0x800B009C: beq         $t7, $at, L_800B00B0
    if (ctx->r15 == ctx->r1) {
        // 0x800B00A0: addiu       $at, $zero, 0xA6
        ctx->r1 = ADD32(0, 0XA6);
            goto L_800B00B0;
    }
    // 0x800B00A0: addiu       $at, $zero, 0xA6
    ctx->r1 = ADD32(0, 0XA6);
    // 0x800B00A4: beq         $t7, $at, L_800B00B0
    if (ctx->r15 == ctx->r1) {
        // 0x800B00A8: addiu       $at, $zero, 0xA7
        ctx->r1 = ADD32(0, 0XA7);
            goto L_800B00B0;
    }
    // 0x800B00A8: addiu       $at, $zero, 0xA7
    ctx->r1 = ADD32(0, 0XA7);
    // 0x800B00AC: bne         $t7, $at, L_800B0214
    if (ctx->r15 != ctx->r1) {
        // 0x800B00B0: subu        $t6, $t6, $t8
        ctx->r14 = SUB32(ctx->r14, ctx->r24);
            goto L_800B0214;
    }
L_800B00B0:
    // 0x800B00B0: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800B00B4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800B00B8: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800B00BC: lh          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800B00C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B00C4: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800B00C8: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x800B00CC: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x800B00D0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B00D4: addiu       $at, $zero, 0x476
    ctx->r1 = ADD32(0, 0X476);
    // 0x800B00D8: beq         $t7, $at, L_800B00EC
    if (ctx->r15 == ctx->r1) {
        // 0x800B00DC: addu        $v0, $t6, $t9
        ctx->r2 = ADD32(ctx->r14, ctx->r25);
            goto L_800B00EC;
    }
    // 0x800B00DC: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x800B00E0: addiu       $at, $zero, 0x477
    ctx->r1 = ADD32(0, 0X477);
    // 0x800B00E4: bne         $t7, $at, L_800B0168
    if (ctx->r15 != ctx->r1) {
        // 0x800B00E8: nop
    
            goto L_800B0168;
    }
    // 0x800B00E8: nop

L_800B00EC:
    // 0x800B00EC: bne         $t2, $t3, L_800B0130
    if (ctx->r10 != ctx->r11) {
        // 0x800B00F0: addiu       $a0, $zero, 0xD6
        ctx->r4 = ADD32(0, 0XD6);
            goto L_800B0130;
    }
    // 0x800B00F0: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x800B00F4: lw          $t8, 0x21C($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X21C));
    // 0x800B00F8: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x800B00FC: lh          $a1, 0x4E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X4E));
    // 0x800B0100: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800B0104: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800B0108: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B010C: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x800B0110: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x800B0114: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800B0118: jal         0x80058A48
    // 0x800B011C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    xyzsound(rdram, ctx);
        goto after_6;
    // 0x800B011C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_6:
    // 0x800B0120: lh          $t0, 0x3A($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x800B0124: lh          $t1, 0x38($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X38));
    // 0x800B0128: b           L_800B01E0
    // 0x800B012C: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
        goto L_800B01E0;
    // 0x800B012C: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
L_800B0130:
    // 0x800B0130: lw          $t6, 0x21C($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X21C));
    // 0x800B0134: lh          $a1, 0x2E0($v0)
    ctx->r5 = S32(MEM_H(ctx->r2, 0X2E0));
    // 0x800B0138: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800B013C: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800B0140: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B0144: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x800B0148: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x800B014C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800B0150: jal         0x80058A48
    // 0x800B0154: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    xyzsound(rdram, ctx);
        goto after_7;
    // 0x800B0154: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_7:
    // 0x800B0158: lh          $t0, 0x3A($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x800B015C: lh          $t1, 0x38($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X38));
    // 0x800B0160: b           L_800B01E0
    // 0x800B0164: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
        goto L_800B01E0;
    // 0x800B0164: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
L_800B0168:
    // 0x800B0168: bne         $t2, $t3, L_800B01AC
    if (ctx->r10 != ctx->r11) {
        // 0x800B016C: addiu       $a0, $zero, 0x33
        ctx->r4 = ADD32(0, 0X33);
            goto L_800B01AC;
    }
    // 0x800B016C: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800B0170: lw          $t9, 0x21C($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X21C));
    // 0x800B0174: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800B0178: lh          $a1, 0x4E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X4E));
    // 0x800B017C: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800B0180: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800B0184: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B0188: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x800B018C: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x800B0190: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800B0194: jal         0x80058A48
    // 0x800B0198: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    xyzsound(rdram, ctx);
        goto after_8;
    // 0x800B0198: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_8:
    // 0x800B019C: lh          $t0, 0x3A($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x800B01A0: lh          $t1, 0x38($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X38));
    // 0x800B01A4: b           L_800B01E0
    // 0x800B01A8: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
        goto L_800B01E0;
    // 0x800B01A8: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
L_800B01AC:
    // 0x800B01AC: lw          $t7, 0x21C($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X21C));
    // 0x800B01B0: lh          $a1, 0x2E0($v0)
    ctx->r5 = S32(MEM_H(ctx->r2, 0X2E0));
    // 0x800B01B4: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800B01B8: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800B01BC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800B01C0: sh          $t0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r8;
    // 0x800B01C4: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x800B01C8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800B01CC: jal         0x80058A48
    // 0x800B01D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    xyzsound(rdram, ctx);
        goto after_9;
    // 0x800B01D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_9:
    // 0x800B01D4: lh          $t0, 0x3A($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x800B01D8: lh          $t1, 0x38($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X38));
    // 0x800B01DC: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
L_800B01E0:
    // 0x800B01E0: bne         $t1, $t0, L_800B056C
    if (ctx->r9 != ctx->r8) {
        // 0x800B01E4: addiu       $a0, $zero, 0x38
        ctx->r4 = ADD32(0, 0X38);
            goto L_800B056C;
    }
    // 0x800B01E4: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800B01E8: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800B01EC: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800B01F0: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800B01F4: lw          $t6, 0x21C($t8)
    ctx->r14 = S32(MEM_W(ctx->r24, 0X21C));
    // 0x800B01F8: lh          $a1, 0x2E0($t8)
    ctx->r5 = S32(MEM_H(ctx->r24, 0X2E0));
    // 0x800B01FC: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800B0200: jal         0x80058A48
    // 0x800B0204: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    xyzsound(rdram, ctx);
        goto after_10;
    // 0x800B0204: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_10:
    // 0x800B0208: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B020C: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800B0210: addiu       $t4, $zero, 0x92
    ctx->r12 = ADD32(0, 0X92);
L_800B0214:
    // 0x800B0214: lh          $t9, 0x4A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X4A));
L_800B0218:
    // 0x800B0218: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800B021C: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x800B0220: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800B0224: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x800B0228: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B022C: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800B0230: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B0234: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x800B0238: lh          $t9, 0x3C($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800B023C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B0240: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800B0244: beq         $t9, $t4, L_800B0268
    if (ctx->r25 == ctx->r12) {
        // 0x800B0248: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_800B0268;
    }
    // 0x800B0248: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B024C: addiu       $at, $zero, 0x93
    ctx->r1 = ADD32(0, 0X93);
    // 0x800B0250: beq         $t9, $at, L_800B0268
    if (ctx->r25 == ctx->r1) {
        // 0x800B0254: addiu       $at, $zero, 0x94
        ctx->r1 = ADD32(0, 0X94);
            goto L_800B0268;
    }
    // 0x800B0254: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x800B0258: beq         $t9, $at, L_800B0268
    if (ctx->r25 == ctx->r1) {
        // 0x800B025C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_800B0268;
    }
    // 0x800B025C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x800B0260: bne         $t9, $at, L_800B027C
    if (ctx->r25 != ctx->r1) {
        // 0x800B0264: nop
    
            goto L_800B027C;
    }
    // 0x800B0264: nop

L_800B0268:
    // 0x800B0268: lh          $t7, 0x40($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800B026C: lh          $t8, 0x3C($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800B0270: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800B0274: addiu       $t9, $t6, -0x92
    ctx->r25 = ADD32(ctx->r14, -0X92);
    // 0x800B0278: sh          $t9, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r25;
L_800B027C:
    // 0x800B027C: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800B0280: lh          $a2, 0x285E($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X285E));
    // 0x800B0284: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800B0288: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800B028C: bltz        $a2, L_800B0424
    if (SIGNED(ctx->r6) < 0) {
        // 0x800B0290: addiu       $t0, $zero, 0x48
        ctx->r8 = ADD32(0, 0X48);
            goto L_800B0424;
    }
    // 0x800B0290: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x800B0294: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
L_800B0298:
    // 0x800B0298: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800B029C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B02A0: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800B02A4: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800B02A8: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x800B02AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B02B0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800B02B4: lh          $t9, 0x20($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X20));
    // 0x800B02B8: lh          $t6, 0x40($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800B02BC: bnel        $t6, $t9, L_800B0410
    if (ctx->r14 != ctx->r25) {
        // 0x800B02C0: sll         $t8, $a2, 1
        ctx->r24 = S32(ctx->r6 << 1);
            goto L_800B0410;
    }
    goto skip_29;
    // 0x800B02C0: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    skip_29:
    // 0x800B02C4: lh          $t7, 0x1E($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X1E));
    // 0x800B02C8: addiu       $t8, $t7, -0xC
    ctx->r24 = ADD32(ctx->r15, -0XC);
    // 0x800B02CC: sltiu       $at, $t8, 0x17
    ctx->r1 = ctx->r24 < 0X17 ? 1 : 0;
    // 0x800B02D0: beq         $at, $zero, L_800B040C
    if (ctx->r1 == 0) {
        // 0x800B02D4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800B040C;
    }
    // 0x800B02D4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B02D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B02DC: addu        $at, $at, $t8
    gpr jr_addend_800B02E4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B02E0: lw          $t8, -0x73EC($at)
    ctx->r24 = ADD32(ctx->r1, -0X73EC);
    // 0x800B02E4: jr          $t8
    // 0x800B02E8: nop

    switch (jr_addend_800B02E4 >> 2) {
        case 0: goto L_800B02EC; break;
        case 1: goto L_800B040C; break;
        case 2: goto L_800B040C; break;
        case 3: goto L_800B040C; break;
        case 4: goto L_800B040C; break;
        case 5: goto L_800B040C; break;
        case 6: goto L_800B040C; break;
        case 7: goto L_800B040C; break;
        case 8: goto L_800B040C; break;
        case 9: goto L_800B03B4; break;
        case 10: goto L_800B040C; break;
        case 11: goto L_800B040C; break;
        case 12: goto L_800B0338; break;
        case 13: goto L_800B0338; break;
        case 14: goto L_800B040C; break;
        case 15: goto L_800B040C; break;
        case 16: goto L_800B040C; break;
        case 17: goto L_800B040C; break;
        case 18: goto L_800B040C; break;
        case 19: goto L_800B040C; break;
        case 20: goto L_800B040C; break;
        case 21: goto L_800B040C; break;
        case 22: goto L_800B0338; break;
        default: switch_error(__func__, 0x800B02E4, 0x80108C14);
    }
    // 0x800B02E8: nop

L_800B02EC:
    // 0x800B02EC: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B02F0: lh          $t6, 0x10($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0X10));
    // 0x800B02F4: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x800B02F8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800B02FC: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800B0300: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800B0304: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B0308: sb          $zero, -0x1961($at)
    MEM_B(-0X1961, ctx->r1) = 0;
    // 0x800B030C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B0310: mflo        $t7
    ctx->r15 = lo;
    // 0x800B0314: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x800B0318: lw          $t8, 0x30($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X30));
    // 0x800B031C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800B0320: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
    // 0x800B0324: bne         $t6, $at, L_800B040C
    if (ctx->r14 != ctx->r1) {
        // 0x800B0328: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800B040C;
    }
    // 0x800B0328: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B032C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800B0330: b           L_800B040C
    // 0x800B0334: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_800B040C;
    // 0x800B0334: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_800B0338:
    // 0x800B0338: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B033C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800B0340: mflo        $t7
    ctx->r15 = lo;
    // 0x800B0344: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x800B0348: lw          $v1, 0x40($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0X40));
    // 0x800B034C: sltiu       $t8, $v1, 0x1
    ctx->r24 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800B0350: beq         $t8, $zero, L_800B0388
    if (ctx->r24 == 0) {
        // 0x800B0354: sw          $t8, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->r24;
            goto L_800B0388;
    }
    // 0x800B0354: sw          $t8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r24;
    // 0x800B0358: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800B035C: lw          $a1, 0x24($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800B0360: sh          $a2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r6;
    // 0x800B0364: jal         0x80099868
    // 0x800B0368: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    FTA(rdram, ctx);
        goto after_11;
    // 0x800B0368: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_11:
    // 0x800B036C: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800B0370: lh          $a2, 0x42($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X42));
    // 0x800B0374: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B0378: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800B037C: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800B0380: b           L_800B040C
    // 0x800B0384: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
        goto L_800B040C;
    // 0x800B0384: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
L_800B0388:
    // 0x800B0388: lw          $a1, 0x24($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800B038C: sh          $a2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r6;
    // 0x800B0390: jal         0x80099868
    // 0x800B0394: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    FTA(rdram, ctx);
        goto after_12;
    // 0x800B0394: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_12:
    // 0x800B0398: lh          $a2, 0x42($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X42));
    // 0x800B039C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B03A0: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800B03A4: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800B03A8: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800B03AC: b           L_800B040C
    // 0x800B03B0: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
        goto L_800B040C;
    // 0x800B03B0: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
L_800B03B4:
    // 0x800B03B4: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B03B8: lh          $t6, -0x53DC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X53DC));
    // 0x800B03BC: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800B03C0: addiu       $t7, $t7, 0x5770
    ctx->r15 = ADD32(ctx->r15, 0X5770);
    // 0x800B03C4: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x800B03C8: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800B03CC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800B03D0: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800B03D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B03D8: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x800B03DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B03E0: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    // 0x800B03E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800B03E8: sh          $a2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r6;
    // 0x800B03EC: jal         0x80099868
    // 0x800B03F0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    FTA(rdram, ctx);
        goto after_13;
    // 0x800B03F0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_13:
    // 0x800B03F4: lui         $a3, 0x8028
    ctx->r7 = S32(0X8028 << 16);
    // 0x800B03F8: lh          $a2, 0x42($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X42));
    // 0x800B03FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B0400: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800B0404: addiu       $a3, $a3, -0x5C00
    ctx->r7 = ADD32(ctx->r7, -0X5C00);
    // 0x800B0408: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
L_800B040C:
    // 0x800B040C: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
L_800B0410:
    // 0x800B0410: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x800B0414: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x800B0418: lh          $a2, 0x5F40($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X5F40));
    // 0x800B041C: bgezl       $a2, L_800B0298
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800B0420: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_800B0298;
    }
    goto skip_30;
    // 0x800B0420: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    skip_30:
L_800B0424:
    // 0x800B0424: lh          $a0, 0x40($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800B0428: lh          $a1, 0x4A($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X4A));
    // 0x800B042C: jal         0x800AF124
    // 0x800B0430: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    operateactivators(rdram, ctx);
        goto after_14;
    // 0x800B0430: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_14:
    // 0x800B0434: lw          $t6, 0x24($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800B0438: lh          $a1, 0x40($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X40));
    // 0x800B043C: jal         0x800AF624
    // 0x800B0440: lh          $a0, 0x2E0($t6)
    ctx->r4 = S32(MEM_H(ctx->r14, 0X2E0));
    operateforcefields(rdram, ctx);
        goto after_15;
    // 0x800B0440: lh          $a0, 0x2E0($t6)
    ctx->r4 = S32(MEM_H(ctx->r14, 0X2E0));
    after_15:
    // 0x800B0444: jal         0x800AF5A0
    // 0x800B0448: lh          $a0, 0x40($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X40));
    operatemasterswitches(rdram, ctx);
        goto after_16;
    // 0x800B0448: lh          $a0, 0x40($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X40));
    after_16:
    // 0x800B044C: lh          $t9, 0x3C($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800B0450: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x800B0454: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B0458: beq         $t9, $at, L_800B048C
    if (ctx->r25 == ctx->r1) {
        // 0x800B045C: lw          $t3, 0x28($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
            goto L_800B048C;
    }
    // 0x800B045C: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800B0460: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x800B0464: beq         $t9, $at, L_800B048C
    if (ctx->r25 == ctx->r1) {
        // 0x800B0468: addiu       $at, $zero, 0x476
        ctx->r1 = ADD32(0, 0X476);
            goto L_800B048C;
    }
    // 0x800B0468: addiu       $at, $zero, 0x476
    ctx->r1 = ADD32(0, 0X476);
    // 0x800B046C: beq         $t9, $at, L_800B048C
    if (ctx->r25 == ctx->r1) {
        // 0x800B0470: addiu       $at, $zero, 0x477
        ctx->r1 = ADD32(0, 0X477);
            goto L_800B048C;
    }
    // 0x800B0470: addiu       $at, $zero, 0x477
    ctx->r1 = ADD32(0, 0X477);
    // 0x800B0474: beq         $t9, $at, L_800B048C
    if (ctx->r25 == ctx->r1) {
        // 0x800B0478: addiu       $at, $zero, 0xA6
        ctx->r1 = ADD32(0, 0XA6);
            goto L_800B048C;
    }
    // 0x800B0478: addiu       $at, $zero, 0xA6
    ctx->r1 = ADD32(0, 0XA6);
    // 0x800B047C: beq         $t9, $at, L_800B048C
    if (ctx->r25 == ctx->r1) {
        // 0x800B0480: addiu       $at, $zero, 0xA7
        ctx->r1 = ADD32(0, 0XA7);
            goto L_800B048C;
    }
    // 0x800B0480: addiu       $at, $zero, 0xA7
    ctx->r1 = ADD32(0, 0XA7);
    // 0x800B0484: bne         $t9, $at, L_800B0494
    if (ctx->r25 != ctx->r1) {
        // 0x800B0488: lh          $t7, 0x3E($sp)
        ctx->r15 = S32(MEM_H(ctx->r29, 0X3E));
            goto L_800B0494;
    }
    // 0x800B0488: lh          $t7, 0x3E($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X3E));
L_800B048C:
    // 0x800B048C: b           L_800B0570
    // 0x800B0490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B0570;
    // 0x800B0490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B0494:
    // 0x800B0494: bne         $t7, $zero, L_800B0504
    if (ctx->r15 != 0) {
        // 0x800B0498: lh          $a0, 0x3C($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
            goto L_800B0504;
    }
    // 0x800B0498: lh          $a0, 0x3C($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X3C));
    // 0x800B049C: jal         0x800ACC8C
    // 0x800B04A0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    isadoorwall(rdram, ctx);
        goto after_17;
    // 0x800B04A0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_17:
    // 0x800B04A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B04A8: bne         $v0, $zero, L_800B0504
    if (ctx->r2 != 0) {
        // 0x800B04AC: lw          $t3, 0x28($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
            goto L_800B0504;
    }
    // 0x800B04AC: lw          $t3, 0x28($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800B04B0: bne         $t2, $t3, L_800B04E0
    if (ctx->r10 != ctx->r11) {
        // 0x800B04B4: addiu       $a0, $zero, 0x33
        ctx->r4 = ADD32(0, 0X33);
            goto L_800B04E0;
    }
    // 0x800B04B4: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800B04B8: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800B04BC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800B04C0: lh          $a1, 0x4E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X4E));
    // 0x800B04C4: lw          $t6, 0x21C($t8)
    ctx->r14 = S32(MEM_W(ctx->r24, 0X21C));
    // 0x800B04C8: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800B04CC: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800B04D0: jal         0x80058A48
    // 0x800B04D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    xyzsound(rdram, ctx);
        goto after_18;
    // 0x800B04D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_18:
    // 0x800B04D8: b           L_800B0570
    // 0x800B04DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B0570;
    // 0x800B04DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B04E0:
    // 0x800B04E0: lw          $t9, 0x24($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800B04E4: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800B04E8: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800B04EC: lw          $t7, 0x21C($t9)
    ctx->r15 = S32(MEM_W(ctx->r25, 0X21C));
    // 0x800B04F0: lh          $a1, 0x2E0($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, 0X2E0));
    // 0x800B04F4: jal         0x80058A48
    // 0x800B04F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    xyzsound(rdram, ctx);
        goto after_19;
    // 0x800B04F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_19:
    // 0x800B04FC: b           L_800B0570
    // 0x800B0500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B0570;
    // 0x800B0500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B0504:
    // 0x800B0504: lh          $t8, 0x3E($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X3E));
    // 0x800B0508: beq         $t8, $zero, L_800B0564
    if (ctx->r24 == 0) {
        // 0x800B050C: nop
    
            goto L_800B0564;
    }
    // 0x800B050C: nop

    // 0x800B0510: bne         $t2, $t3, L_800B0554
    if (ctx->r10 != ctx->r11) {
        // 0x800B0514: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_800B0554;
    }
    // 0x800B0514: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800B0518: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800B051C: lbu         $t6, -0xB68($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0XB68);
    // 0x800B0520: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800B0524: lw          $t7, 0x24($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800B0528: andi        $t9, $t6, 0x4
    ctx->r25 = ctx->r14 & 0X4;
    // 0x800B052C: bnel        $t9, $zero, L_800B0558
    if (ctx->r25 != 0) {
        // 0x800B0530: lw          $t9, 0x24($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0X24));
            goto L_800B0558;
    }
    goto skip_31;
    // 0x800B0530: lw          $t9, 0x24($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X24));
    skip_31:
    // 0x800B0534: lw          $t6, 0x21C($t7)
    ctx->r14 = S32(MEM_W(ctx->r15, 0X21C));
    // 0x800B0538: lh          $a1, 0x4E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X4E));
    // 0x800B053C: lw          $a2, 0x34($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800B0540: lw          $a3, 0x30($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800B0544: jal         0x80058A48
    // 0x800B0548: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    xyzsound(rdram, ctx);
        goto after_20;
    // 0x800B0548: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_20:
    // 0x800B054C: b           L_800B0570
    // 0x800B0550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B0570;
    // 0x800B0550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B0554:
    // 0x800B0554: lw          $t9, 0x24($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X24));
L_800B0558:
    // 0x800B0558: lhu         $a0, 0x3E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3E);
    // 0x800B055C: jal         0x80059034
    // 0x800B0560: lh          $a1, 0x2E0($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, 0X2E0));
    spritesound(rdram, ctx);
        goto after_21;
    // 0x800B0560: lh          $a1, 0x2E0($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, 0X2E0));
    after_21:
L_800B0564:
    // 0x800B0564: b           L_800B0570
    // 0x800B0568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B0570;
    // 0x800B0568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B056C:
    // 0x800B056C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B0570:
    // 0x800B0570: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800B0574: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800B0578: jr          $ra
    // 0x800B057C: nop

    return;
    // 0x800B057C: nop

;}
RECOMP_FUNC void func_800579C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800579C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800579C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800579CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800579D0: slti        $at, $a0, 0x115
    ctx->r1 = SIGNED(ctx->r4) < 0X115 ? 1 : 0;
    // 0x800579D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800579D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800579DC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800579E0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800579E4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800579E8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800579EC: beq         $at, $zero, L_80057C64
    if (ctx->r1 == 0) {
        // 0x800579F0: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_80057C64;
    }
    // 0x800579F0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x800579F4: bltz        $a0, L_80057C64
    if (SIGNED(ctx->r4) < 0) {
        // 0x800579F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80057C64;
    }
    // 0x800579F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800579FC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80057A00: addiu       $a3, $a3, -0x18F0
    ctx->r7 = ADD32(ctx->r7, -0X18F0);
    // 0x80057A04: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_80057A08:
    // 0x80057A08: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80057A0C: lb          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_B(ctx->r15, 0X0));
    // 0x80057A10: bnel        $t8, $zero, L_80057A28
    if (ctx->r24 != 0) {
        // 0x80057A14: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80057A28;
    }
    goto skip_0;
    // 0x80057A14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80057A18: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80057A1C: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80057A20: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x80057A24: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80057A28:
    // 0x80057A28: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80057A2C: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80057A30: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x80057A34: bnel        $at, $zero, L_80057A08
    if (ctx->r1 != 0) {
        // 0x80057A38: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_80057A08;
    }
    goto skip_1;
    // 0x80057A38: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    skip_1:
    // 0x80057A3C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80057A40: bne         $t0, $t2, L_80057A58
    if (ctx->r8 != ctx->r10) {
        // 0x80057A44: sll         $t1, $s1, 1
        ctx->r9 = S32(ctx->r17 << 1);
            goto L_80057A58;
    }
    // 0x80057A44: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x80057A48: jal         0x800590B0
    // 0x80057A4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    testcallback(rdram, ctx);
        goto after_0;
    // 0x80057A4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80057A50: b           L_80057C68
    // 0x80057A54: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_80057C68;
    // 0x80057A54: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_80057A58:
    // 0x80057A58: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057A5C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80057A60: lh          $a0, 0x4AE0($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X4AE0));
    // 0x80057A64: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80057A68: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x80057A6C: blez        $a0, L_80057AB8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80057A70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80057AB8;
    }
    // 0x80057A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057A74: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80057A78: addiu       $a2, $a2, 0x4D90
    ctx->r6 = ADD32(ctx->r6, 0X4D90);
    // 0x80057A7C: lbu         $a1, -0x1830($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1830);
    // 0x80057A80: addu        $t5, $a2, $v0
    ctx->r13 = ADD32(ctx->r6, ctx->r2);
L_80057A84:
    // 0x80057A84: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
    // 0x80057A88: and         $t6, $a1, $v1
    ctx->r14 = ctx->r5 & ctx->r3;
    // 0x80057A8C: beql        $t6, $v1, L_80057AA4
    if (ctx->r14 == ctx->r3) {
        // 0x80057A90: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80057AA4;
    }
    goto skip_2;
    // 0x80057A90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x80057A94: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80057A98: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80057A9C: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80057AA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80057AA4:
    // 0x80057AA4: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80057AA8: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80057AAC: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80057AB0: bnel        $at, $zero, L_80057A84
    if (ctx->r1 != 0) {
        // 0x80057AB4: addu        $t5, $a2, $v0
        ctx->r13 = ADD32(ctx->r6, ctx->r2);
            goto L_80057A84;
    }
    goto skip_3;
    // 0x80057AB4: addu        $t5, $a2, $v0
    ctx->r13 = ADD32(ctx->r6, ctx->r2);
    skip_3:
L_80057AB8:
    // 0x80057AB8: bne         $s0, $t2, L_80057AD0
    if (ctx->r16 != ctx->r10) {
        // 0x80057ABC: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_80057AD0;
    }
    // 0x80057ABC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057AC0: jal         0x800590B0
    // 0x80057AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    testcallback(rdram, ctx);
        goto after_1;
    // 0x80057AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80057AC8: b           L_80057C68
    // 0x80057ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_80057C68;
    // 0x80057ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_80057AD0:
    // 0x80057AD0: sll         $t3, $s0, 4
    ctx->r11 = S32(ctx->r16 << 4);
    // 0x80057AD4: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x80057AD8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80057ADC: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x80057AE0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80057AE4: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x80057AE8: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80057AEC: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x80057AF0: addiu       $t5, $t5, -0x25F0
    ctx->r13 = ADD32(ctx->r13, -0X25F0);
    // 0x80057AF4: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x80057AF8: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80057AFC: lh          $a1, 0x0($v0)
    ctx->r5 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80057B00: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80057B04: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    // 0x80057B08: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    // 0x80057B0C: jal         0x800C16E0
    // 0x80057B10: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    alSndpSetSound(rdram, ctx);
        goto after_2;
    // 0x80057B10: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_2:
    // 0x80057B14: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057B18: jal         0x800C1700
    // 0x80057B1C: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    alSndpGetState(rdram, ctx);
        goto after_3;
    // 0x80057B1C: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    after_3:
    // 0x80057B20: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80057B24: addiu       $a2, $a2, 0x4D90
    ctx->r6 = ADD32(ctx->r6, 0X4D90);
    // 0x80057B28: beq         $v0, $zero, L_80057B40
    if (ctx->r2 == 0) {
        // 0x80057B2C: lh          $t0, 0x2C($sp)
        ctx->r8 = S32(MEM_H(ctx->r29, 0X2C));
            goto L_80057B40;
    }
    // 0x80057B2C: lh          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X2C));
    // 0x80057B30: jal         0x800590B0
    // 0x80057B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    testcallback(rdram, ctx);
        goto after_4;
    // 0x80057B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80057B38: b           L_80057C68
    // 0x80057B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_80057C68;
    // 0x80057B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_80057B40:
    // 0x80057B40: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x80057B44: addiu       $t6, $t6, -0x1830
    ctx->r14 = ADD32(ctx->r14, -0X1830);
    // 0x80057B48: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x80057B4C: addu        $t8, $a2, $s0
    ctx->r24 = ADD32(ctx->r6, ctx->r16);
    // 0x80057B50: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80057B54: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80057B58: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80057B5C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057B60: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x80057B64: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x80057B68: lh          $a1, 0x0($t4)
    ctx->r5 = S32(MEM_H(ctx->r12, 0X0));
    // 0x80057B6C: sh          $t0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r8;
    // 0x80057B70: jal         0x800C16E0
    // 0x80057B74: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    alSndpSetSound(rdram, ctx);
        goto after_5;
    // 0x80057B74: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    after_5:
    // 0x80057B78: lw          $t5, 0x24($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80057B7C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80057B80: lh          $t8, 0x4A($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X4A));
    // 0x80057B84: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80057B88: lh          $t6, 0x48A8($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X48A8));
    // 0x80057B8C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80057B90: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80057B94: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80057B98: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80057B9C: lwc1        $f18, 0x473C($at)
    ctx->f18.u32l = S32(MEM_W(ctx->r1, 0X473C));
    // 0x80057BA0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057BA4: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    // 0x80057BA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80057BAC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80057BB0: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80057BB4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80057BB8: jal         0x800C1720
    // 0x80057BBC: nop

    alSndpSetPitch(rdram, ctx);
        goto after_6;
    // 0x80057BBC: nop

    after_6:
    // 0x80057BC0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057BC4: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    // 0x80057BC8: jal         0x800C1780
    // 0x80057BCC: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    alSndpSetPan(rdram, ctx);
        goto after_7;
    // 0x80057BCC: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    after_7:
    // 0x80057BD0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80057BD4: lh          $t7, 0x12A4($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X12A4));
    // 0x80057BD8: lw          $t9, 0x34($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80057BDC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80057BE0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80057BE4: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057BE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80057BEC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057BF0: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    // 0x80057BF4: mflo        $t3
    ctx->r11 = lo;
    // 0x80057BF8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80057BFC: nop

    // 0x80057C00: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80057C04: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80057C08: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80057C0C: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80057C10: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80057C14: nop

    // 0x80057C18: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80057C1C: jal         0x800C17E0
    // 0x80057C20: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    alSndpSetVol(rdram, ctx);
        goto after_8;
    // 0x80057C20: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    after_8:
    // 0x80057C24: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057C28: jal         0x800C1840
    // 0x80057C2C: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    alSndpPlay(rdram, ctx);
        goto after_9;
    // 0x80057C2C: lw          $a0, 0x4D20($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4D20));
    after_9:
    // 0x80057C30: lh          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X2C));
    // 0x80057C34: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80057C38: addiu       $a3, $a3, -0x18F0
    ctx->r7 = ADD32(ctx->r7, -0X18F0);
    // 0x80057C3C: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x80057C40: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x80057C44: lh          $t9, 0x3A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X3A));
    // 0x80057C48: lw          $t3, 0x40($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80057C4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80057C50: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80057C54: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80057C58: sw          $s0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r16;
    // 0x80057C5C: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80057C60: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_80057C64:
    // 0x80057C64: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_80057C68:
    // 0x80057C68: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80057C6C: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80057C70: jr          $ra
    // 0x80057C74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80057C74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void controllersetvib(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005194C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80051950: lh          $t9, -0x9DC($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X9DC));
    // 0x80051954: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80051958: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8005195C: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80051960: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80051964: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x80051968: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005196C: beq         $at, $zero, L_800519BC
    if (ctx->r1 == 0) {
        // 0x80051970: andi        $t8, $a2, 0xFF
        ctx->r24 = ctx->r6 & 0XFF;
            goto L_800519BC;
    }
    // 0x80051970: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80051974: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80051978: lb          $t0, 0x1360($t0)
    ctx->r8 = S32(MEM_B(ctx->r8, 0X1360));
    // 0x8005197C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80051980: bne         $t0, $zero, L_800519BC
    if (ctx->r8 != 0) {
        // 0x80051984: nop
    
            goto L_800519BC;
    }
    // 0x80051984: nop

    // 0x80051988: lb          $t1, 0x36C8($t1)
    ctx->r9 = S32(MEM_B(ctx->r9, 0X36C8));
    // 0x8005198C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051990: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x80051994: bne         $t1, $at, L_800519BC
    if (ctx->r9 != ctx->r1) {
        // 0x80051998: lui         $t3, 0x801D
        ctx->r11 = S32(0X801D << 16);
            goto L_800519BC;
    }
    // 0x80051998: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x8005199C: addiu       $t3, $t3, -0x4708
    ctx->r11 = ADD32(ctx->r11, -0X4708);
    // 0x800519A0: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800519A4: lb          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_B(ctx->r2, 0X0));
    // 0x800519A8: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x800519AC: beq         $t4, $zero, L_800519BC
    if (ctx->r12 == 0) {
        // 0x800519B0: nop
    
            goto L_800519BC;
    }
    // 0x800519B0: nop

    // 0x800519B4: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x800519B8: sb          $t8, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r24;
L_800519BC:
    // 0x800519BC: jr          $ra
    // 0x800519C0: nop

    return;
    // 0x800519C0: nop

;}
RECOMP_FUNC void addexplosionmodel2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006487C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80064880: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80064884: lh          $t0, -0x9DC($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, -0X9DC));
    // 0x80064888: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006488C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80064890: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80064894: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x80064898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006489C: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800648A0: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800648A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800648A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800648AC: bne         $t0, $at, L_80064950
    if (ctx->r8 != ctx->r1) {
        // 0x800648B0: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80064950;
    }
    // 0x800648B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800648B4: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800648B8: addiu       $a0, $a0, -0x2790
    ctx->r4 = ADD32(ctx->r4, -0X2790);
    // 0x800648BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800648C0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
L_800648C4:
    // 0x800648C4: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800648C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800648CC: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x800648D0: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800648D4: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800648D8: mflo        $t1
    ctx->r9 = lo;
    // 0x800648DC: addu        $v1, $a0, $t1
    ctx->r3 = ADD32(ctx->r4, ctx->r9);
    // 0x800648E0: lb          $t2, 0x0($v1)
    ctx->r10 = S32(MEM_B(ctx->r3, 0X0));
    // 0x800648E4: beql        $t2, $zero, L_80064900
    if (ctx->r10 == 0) {
        // 0x800648E8: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80064900;
    }
    goto skip_0;
    // 0x800648E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    skip_0:
    // 0x800648EC: bne         $at, $zero, L_800648C4
    if (ctx->r1 != 0) {
        // 0x800648F0: nop
    
            goto L_800648C4;
    }
    // 0x800648F0: nop

    // 0x800648F4: b           L_80064954
    // 0x800648F8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80064954;
    // 0x800648F8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800648FC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_80064900:
    // 0x80064900: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80064904: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80064908: lh          $t5, 0x22($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X22));
    // 0x8006490C: lh          $t6, 0x26($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X26));
    // 0x80064910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80064914: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
    // 0x80064918: sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
    // 0x8006491C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80064920: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
    // 0x80064924: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
    // 0x80064928: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x8006492C: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
    // 0x80064930: lwc1        $f8, 0x4D74($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, 0X4D74));
    // 0x80064934: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80064938: jal         0x8009800C
    // 0x8006493C: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    krand2(rdram, ctx);
        goto after_0;
    // 0x8006493C: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    after_0:
    // 0x80064940: lw          $v1, 0x18($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80064944: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80064948: sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // 0x8006494C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80064950:
    // 0x80064950: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80064954:
    // 0x80064954: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80064958: jr          $ra
    // 0x8006495C: nop

    return;
    // 0x8006495C: nop

;}
RECOMP_FUNC void newgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABE18: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800ABE1C: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800ABE20: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800ABE24: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800ABE28: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800ABE2C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800ABE30: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x800ABE34: lui         $t1, 0x802B
    ctx->r9 = S32(0X802B << 16);
    // 0x800ABE38: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800ABE3C: addiu       $t1, $t1, -0x5598
    ctx->r9 = ADD32(ctx->r9, -0X5598);
    // 0x800ABE40: addiu       $t0, $t0, 0x5770
    ctx->r8 = ADD32(ctx->r8, 0X5770);
    // 0x800ABE44: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800ABE48: addu        $v0, $t0, $t8
    ctx->r2 = ADD32(ctx->r8, ctx->r24);
    // 0x800ABE4C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800ABE50: addiu       $t9, $zero, 0x300
    ctx->r25 = ADD32(0, 0X300);
    // 0x800ABE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ABE58: sh          $zero, 0xF2($t1)
    MEM_H(0XF2, ctx->r9) = 0;
    // 0x800ABE5C: sh          $zero, 0xEA($t1)
    MEM_H(0XEA, ctx->r9) = 0;
    // 0x800ABE60: sh          $t7, 0xF0($t1)
    MEM_H(0XF0, ctx->r9) = ctx->r15;
    // 0x800ABE64: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800ABE68: sb          $zero, 0x338($v0)
    MEM_B(0X338, ctx->r2) = 0;
    // 0x800ABE6C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800ABE70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800ABE74: sb          $zero, -0x53C3($at)
    MEM_B(-0X53C3, ctx->r1) = 0;
    // 0x800ABE78: lw          $a2, 0x18C($t1)
    ctx->r6 = S32(MEM_W(ctx->r9, 0X18C));
    // 0x800ABE7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ABE80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800ABE84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800ABE88: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800ABE8C: blez        $a2, L_800ABED4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800ABE90: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800ABED4;
    }
    // 0x800ABE90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800ABE94: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800ABE98: addiu       $a1, $a1, -0x6B28
    ctx->r5 = ADD32(ctx->r5, -0X6B28);
    // 0x800ABE9C: addiu       $a0, $zero, 0x38C
    ctx->r4 = ADD32(0, 0X38C);
L_800ABEA0:
    // 0x800ABEA0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ABEA4: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x800ABEA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800ABEAC: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x800ABEB0: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800ABEB4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800ABEB8: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x800ABEBC: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x800ABEC0: mflo        $t2
    ctx->r10 = lo;
    // 0x800ABEC4: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x800ABEC8: sh          $zero, 0x2AE($v0)
    MEM_H(0X2AE, ctx->r2) = 0;
    // 0x800ABECC: bne         $at, $zero, L_800ABEA0
    if (ctx->r1 != 0) {
        // 0x800ABED0: sh          $zero, 0x2B0($v0)
        MEM_H(0X2B0, ctx->r2) = 0;
            goto L_800ABEA0;
    }
    // 0x800ABED0: sh          $zero, 0x2B0($v0)
    MEM_H(0X2B0, ctx->r2) = 0;
L_800ABED4:
    // 0x800ABED4: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x800ABED8: bne         $at, $zero, L_800ABF18
    if (ctx->r1 != 0) {
        // 0x800ABEDC: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_800ABF18;
    }
    // 0x800ABEDC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800ABEE0: lw          $t7, 0x138($t1)
    ctx->r15 = S32(MEM_W(ctx->r9, 0X138));
    // 0x800ABEE4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800ABEE8: bne         $t7, $zero, L_800ABF18
    if (ctx->r15 != 0) {
        // 0x800ABEEC: nop
    
            goto L_800ABF18;
    }
    // 0x800ABEEC: nop

    // 0x800ABEF0: lbu         $t8, 0x378C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X378C);
    // 0x800ABEF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800ABEF8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800ABEFC: bne         $t8, $at, L_800ABF18
    if (ctx->r24 != ctx->r1) {
        // 0x800ABF00: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800ABF18;
    }
    // 0x800ABF00: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800ABF04: lw          $a0, -0x1448($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X1448));
    // 0x800ABF08: jal         0x800BD9E4
    // 0x800ABF0C: addiu       $a1, $a1, -0x7CC4
    ctx->r5 = ADD32(ctx->r5, -0X7CC4);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800ABF0C: addiu       $a1, $a1, -0x7CC4
    ctx->r5 = ADD32(ctx->r5, -0X7CC4);
    after_0:
    // 0x800ABF10: b           L_800ABF58
    // 0x800ABF14: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800ABF58;
    // 0x800ABF14: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800ABF18:
    // 0x800ABF18: lh          $t9, -0x9DC($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X9DC));
    // 0x800ABF1C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800ABF20: addiu       $a1, $a1, -0x7CB0
    ctx->r5 = ADD32(ctx->r5, -0X7CB0);
    // 0x800ABF24: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x800ABF28: bne         $at, $zero, L_800ABF4C
    if (ctx->r1 != 0) {
        // 0x800ABF2C: lui         $a0, 0x8010
        ctx->r4 = S32(0X8010 << 16);
            goto L_800ABF4C;
    }
    // 0x800ABF2C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800ABF30: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800ABF34: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800ABF38: addiu       $a1, $a1, -0x7CC0
    ctx->r5 = ADD32(ctx->r5, -0X7CC0);
    // 0x800ABF3C: jal         0x800BD9E4
    // 0x800ABF40: lw          $a0, -0x1448($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X1448));
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800ABF40: lw          $a0, -0x1448($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X1448));
    after_1:
    // 0x800ABF44: b           L_800ABF58
    // 0x800ABF48: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800ABF58;
    // 0x800ABF48: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800ABF4C:
    // 0x800ABF4C: jal         0x800BD9E4
    // 0x800ABF50: lw          $a0, -0x1448($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X1448));
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x800ABF50: lw          $a0, -0x1448($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, -0X1448));
    after_2:
    // 0x800ABF54: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800ABF58:
    // 0x800ABF58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ABF5C: jr          $ra
    // 0x800ABF60: nop

    return;
    // 0x800ABF60: nop

;}
RECOMP_FUNC void check_fta_sounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099C78: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80099C7C: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80099C80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80099C84: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80099C88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80099C8C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80099C90: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x80099C94: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x80099C98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80099C9C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80099CA0: lh          $t9, 0x22($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X22));
    // 0x80099CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099CAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80099CB0: blez        $t9, L_80099EC4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80099CB4: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80099EC4;
    }
    // 0x80099CB4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80099CB8: lh          $v0, 0xE($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0XE));
    // 0x80099CBC: slti        $at, $v0, 0x7D1
    ctx->r1 = SIGNED(ctx->r2) < 0X7D1 ? 1 : 0;
    // 0x80099CC0: bne         $at, $zero, L_80099D30
    if (ctx->r1 != 0) {
        // 0x80099CC4: slti        $at, $v0, 0x876
        ctx->r1 = SIGNED(ctx->r2) < 0X876 ? 1 : 0;
            goto L_80099D30;
    }
    // 0x80099CC4: slti        $at, $v0, 0x876
    ctx->r1 = SIGNED(ctx->r2) < 0X876 ? 1 : 0;
    // 0x80099CC8: bne         $at, $zero, L_80099CFC
    if (ctx->r1 != 0) {
        // 0x80099CCC: addiu       $at, $zero, 0x942
        ctx->r1 = ADD32(0, 0X942);
            goto L_80099CFC;
    }
    // 0x80099CCC: addiu       $at, $zero, 0x942
    ctx->r1 = ADD32(0, 0X942);
    // 0x80099CD0: beq         $v0, $at, L_80099EBC
    if (ctx->r2 == ctx->r1) {
        // 0x80099CD4: addiu       $at, $zero, 0xA46
        ctx->r1 = ADD32(0, 0XA46);
            goto L_80099EBC;
    }
    // 0x80099CD4: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    // 0x80099CD8: beq         $v0, $at, L_80099E40
    if (ctx->r2 == ctx->r1) {
        // 0x80099CDC: addiu       $at, $zero, 0xA96
        ctx->r1 = ADD32(0, 0XA96);
            goto L_80099E40;
    }
    // 0x80099CDC: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    // 0x80099CE0: beq         $v0, $at, L_80099E74
    if (ctx->r2 == ctx->r1) {
        // 0x80099CE4: addiu       $a0, $zero, 0xE2
        ctx->r4 = ADD32(0, 0XE2);
            goto L_80099E74;
    }
    // 0x80099CE4: addiu       $a0, $zero, 0xE2
    ctx->r4 = ADD32(0, 0XE2);
    // 0x80099CE8: addiu       $at, $zero, 0xAC8
    ctx->r1 = ADD32(0, 0XAC8);
    // 0x80099CEC: beql        $v0, $at, L_80099E8C
    if (ctx->r2 == ctx->r1) {
        // 0x80099CF0: lbu         $t2, 0x25($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X25);
            goto L_80099E8C;
    }
    goto skip_0;
    // 0x80099CF0: lbu         $t2, 0x25($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X25);
    skip_0:
    // 0x80099CF4: b           L_80099EC8
    // 0x80099CF8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099CF8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099CFC:
    // 0x80099CFC: addiu       $at, $zero, 0x7FD
    ctx->r1 = ADD32(0, 0X7FD);
    // 0x80099D00: beq         $v0, $at, L_80099DF0
    if (ctx->r2 == ctx->r1) {
        // 0x80099D04: addiu       $at, $zero, 0x848
        ctx->r1 = ADD32(0, 0X848);
            goto L_80099DF0;
    }
    // 0x80099D04: addiu       $at, $zero, 0x848
    ctx->r1 = ADD32(0, 0X848);
    // 0x80099D08: beq         $v0, $at, L_80099DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80099D0C: addiu       $at, $zero, 0x866
        ctx->r1 = ADD32(0, 0X866);
            goto L_80099DE0;
    }
    // 0x80099D0C: addiu       $at, $zero, 0x866
    ctx->r1 = ADD32(0, 0X866);
    // 0x80099D10: beq         $v0, $at, L_80099DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80099D14: addiu       $at, $zero, 0x870
        ctx->r1 = ADD32(0, 0X870);
            goto L_80099DE0;
    }
    // 0x80099D14: addiu       $at, $zero, 0x870
    ctx->r1 = ADD32(0, 0X870);
    // 0x80099D18: beq         $v0, $at, L_80099DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80099D1C: addiu       $at, $zero, 0x875
        ctx->r1 = ADD32(0, 0X875);
            goto L_80099DE0;
    }
    // 0x80099D1C: addiu       $at, $zero, 0x875
    ctx->r1 = ADD32(0, 0X875);
    // 0x80099D20: beq         $v0, $at, L_80099DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80099D24: nop
    
            goto L_80099DE0;
    }
    // 0x80099D24: nop

    // 0x80099D28: b           L_80099EC8
    // 0x80099D2C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099D2C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099D30:
    // 0x80099D30: slti        $at, $v0, 0x71E
    ctx->r1 = SIGNED(ctx->r2) < 0X71E ? 1 : 0;
    // 0x80099D34: bne         $at, $zero, L_80099D6C
    if (ctx->r1 != 0) {
        // 0x80099D38: addiu       $at, $zero, 0x758
        ctx->r1 = ADD32(0, 0X758);
            goto L_80099D6C;
    }
    // 0x80099D38: addiu       $at, $zero, 0x758
    ctx->r1 = ADD32(0, 0X758);
    // 0x80099D3C: beq         $v0, $at, L_80099E10
    if (ctx->r2 == ctx->r1) {
        // 0x80099D40: addiu       $at, $zero, 0x780
        ctx->r1 = ADD32(0, 0X780);
            goto L_80099E10;
    }
    // 0x80099D40: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x80099D44: beq         $v0, $at, L_80099E20
    if (ctx->r2 == ctx->r1) {
        // 0x80099D48: addiu       $at, $zero, 0x781
        ctx->r1 = ADD32(0, 0X781);
            goto L_80099E20;
    }
    // 0x80099D48: addiu       $at, $zero, 0x781
    ctx->r1 = ADD32(0, 0X781);
    // 0x80099D4C: beq         $v0, $at, L_80099E20
    if (ctx->r2 == ctx->r1) {
        // 0x80099D50: addiu       $at, $zero, 0x7A8
        ctx->r1 = ADD32(0, 0X7A8);
            goto L_80099E20;
    }
    // 0x80099D50: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
    // 0x80099D54: beq         $v0, $at, L_80099E00
    if (ctx->r2 == ctx->r1) {
        // 0x80099D58: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_80099E00;
    }
    // 0x80099D58: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    // 0x80099D5C: beq         $v0, $at, L_80099DF0
    if (ctx->r2 == ctx->r1) {
        // 0x80099D60: nop
    
            goto L_80099DF0;
    }
    // 0x80099D60: nop

    // 0x80099D64: b           L_80099EC8
    // 0x80099D68: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099D68: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099D6C:
    // 0x80099D6C: slti        $at, $v0, 0x6D1
    ctx->r1 = SIGNED(ctx->r2) < 0X6D1 ? 1 : 0;
    // 0x80099D70: bne         $at, $zero, L_80099D90
    if (ctx->r1 != 0) {
        // 0x80099D74: addiu       $at, $zero, 0x71C
        ctx->r1 = ADD32(0, 0X71C);
            goto L_80099D90;
    }
    // 0x80099D74: addiu       $at, $zero, 0x71C
    ctx->r1 = ADD32(0, 0X71C);
    // 0x80099D78: beq         $v0, $at, L_80099E30
    if (ctx->r2 == ctx->r1) {
        // 0x80099D7C: addiu       $at, $zero, 0x71D
        ctx->r1 = ADD32(0, 0X71D);
            goto L_80099E30;
    }
    // 0x80099D7C: addiu       $at, $zero, 0x71D
    ctx->r1 = ADD32(0, 0X71D);
    // 0x80099D80: beq         $v0, $at, L_80099E30
    if (ctx->r2 == ctx->r1) {
        // 0x80099D84: nop
    
            goto L_80099E30;
    }
    // 0x80099D84: nop

    // 0x80099D88: b           L_80099EC8
    // 0x80099D8C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099D8C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099D90:
    // 0x80099D90: slti        $at, $v0, 0x692
    ctx->r1 = SIGNED(ctx->r2) < 0X692 ? 1 : 0;
    // 0x80099D94: bne         $at, $zero, L_80099DBC
    if (ctx->r1 != 0) {
        // 0x80099D98: addiu       $t0, $v0, -0x6B3
        ctx->r8 = ADD32(ctx->r2, -0X6B3);
            goto L_80099DBC;
    }
    // 0x80099D98: addiu       $t0, $v0, -0x6B3
    ctx->r8 = ADD32(ctx->r2, -0X6B3);
    // 0x80099D9C: sltiu       $at, $t0, 0x1E
    ctx->r1 = ctx->r8 < 0X1E ? 1 : 0;
    // 0x80099DA0: beq         $at, $zero, L_80099EC4
    if (ctx->r1 == 0) {
        // 0x80099DA4: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80099EC4;
    }
    // 0x80099DA4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80099DA8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80099DAC: addu        $at, $at, $t0
    gpr jr_addend_80099DB4 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80099DB0: lw          $t0, 0x6770($at)
    ctx->r8 = ADD32(ctx->r1, 0X6770);
    // 0x80099DB4: jr          $t0
    // 0x80099DB8: nop

    switch (jr_addend_80099DB4 >> 2) {
        case 0: goto L_80099DD0; break;
        case 1: goto L_80099EC4; break;
        case 2: goto L_80099EC4; break;
        case 3: goto L_80099EC4; break;
        case 4: goto L_80099EC4; break;
        case 5: goto L_80099EC4; break;
        case 6: goto L_80099EC4; break;
        case 7: goto L_80099EC4; break;
        case 8: goto L_80099EC4; break;
        case 9: goto L_80099EC4; break;
        case 10: goto L_80099DD0; break;
        case 11: goto L_80099EC4; break;
        case 12: goto L_80099EC4; break;
        case 13: goto L_80099EC4; break;
        case 14: goto L_80099EC4; break;
        case 15: goto L_80099EC4; break;
        case 16: goto L_80099EC4; break;
        case 17: goto L_80099EC4; break;
        case 18: goto L_80099EC4; break;
        case 19: goto L_80099EC4; break;
        case 20: goto L_80099EC4; break;
        case 21: goto L_80099EC4; break;
        case 22: goto L_80099EC4; break;
        case 23: goto L_80099EC4; break;
        case 24: goto L_80099EC4; break;
        case 25: goto L_80099EC4; break;
        case 26: goto L_80099DD0; break;
        case 27: goto L_80099DD0; break;
        case 28: goto L_80099EC4; break;
        case 29: goto L_80099DD0; break;
        default: switch_error(__func__, 0x80099DB4, 0x80106770);
    }
    // 0x80099DB8: nop

L_80099DBC:
    // 0x80099DBC: addiu       $at, $zero, 0x690
    ctx->r1 = ADD32(0, 0X690);
    // 0x80099DC0: beq         $v0, $at, L_80099DD0
    if (ctx->r2 == ctx->r1) {
        // 0x80099DC4: addiu       $at, $zero, 0x691
        ctx->r1 = ADD32(0, 0X691);
            goto L_80099DD0;
    }
    // 0x80099DC4: addiu       $at, $zero, 0x691
    ctx->r1 = ADD32(0, 0X691);
    // 0x80099DC8: bnel        $v0, $at, L_80099EC8
    if (ctx->r2 != ctx->r1) {
        // 0x80099DCC: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_80099EC8;
    }
    goto skip_1;
    // 0x80099DCC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_1:
L_80099DD0:
    // 0x80099DD0: jal         0x80059034
    // 0x80099DD4: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    spritesound(rdram, ctx);
        goto after_0;
    // 0x80099DD4: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_0:
    // 0x80099DD8: b           L_80099EC8
    // 0x80099DDC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099DDC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099DE0:
    // 0x80099DE0: jal         0x80059034
    // 0x80099DE4: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    spritesound(rdram, ctx);
        goto after_1;
    // 0x80099DE4: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    after_1:
    // 0x80099DE8: b           L_80099EC8
    // 0x80099DEC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099DEC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099DF0:
    // 0x80099DF0: jal         0x80059034
    // 0x80099DF4: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    spritesound(rdram, ctx);
        goto after_2;
    // 0x80099DF4: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_2:
    // 0x80099DF8: b           L_80099EC8
    // 0x80099DFC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099DFC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099E00:
    // 0x80099E00: jal         0x80059034
    // 0x80099E04: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    spritesound(rdram, ctx);
        goto after_3;
    // 0x80099E04: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_3:
    // 0x80099E08: b           L_80099EC8
    // 0x80099E0C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099E0C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099E10:
    // 0x80099E10: jal         0x80059034
    // 0x80099E14: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    spritesound(rdram, ctx);
        goto after_4;
    // 0x80099E14: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_4:
    // 0x80099E18: b           L_80099EC8
    // 0x80099E1C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099E1C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099E20:
    // 0x80099E20: jal         0x80059034
    // 0x80099E24: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    spritesound(rdram, ctx);
        goto after_5;
    // 0x80099E24: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    after_5:
    // 0x80099E28: b           L_80099EC8
    // 0x80099E2C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099E2C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099E30:
    // 0x80099E30: jal         0x80059034
    // 0x80099E34: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    spritesound(rdram, ctx);
        goto after_6;
    // 0x80099E34: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_6:
    // 0x80099E38: b           L_80099EC8
    // 0x80099E3C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099E3C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099E40:
    // 0x80099E40: lbu         $t1, 0x25($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X25);
    // 0x80099E44: addiu       $a0, $zero, 0x106
    ctx->r4 = ADD32(0, 0X106);
    // 0x80099E48: beq         $t1, $zero, L_80099E60
    if (ctx->r9 == 0) {
        // 0x80099E4C: nop
    
            goto L_80099E60;
    }
    // 0x80099E4C: nop

    // 0x80099E50: jal         0x80059034
    // 0x80099E54: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    spritesound(rdram, ctx);
        goto after_7;
    // 0x80099E54: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_7:
    // 0x80099E58: b           L_80099EC8
    // 0x80099E5C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099E5C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099E60:
    // 0x80099E60: lui         $a1, 0x802A
    ctx->r5 = S32(0X802A << 16);
    // 0x80099E64: jal         0x80059034
    // 0x80099E68: lh          $a1, 0x5A50($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X5A50));
    spritesound(rdram, ctx);
        goto after_8;
    // 0x80099E68: lh          $a1, 0x5A50($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X5A50));
    after_8:
    // 0x80099E6C: b           L_80099EC8
    // 0x80099E70: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099E70: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099E74:
    // 0x80099E74: lui         $a1, 0x802A
    ctx->r5 = S32(0X802A << 16);
    // 0x80099E78: jal         0x80059034
    // 0x80099E7C: lh          $a1, 0x5A50($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X5A50));
    spritesound(rdram, ctx);
        goto after_9;
    // 0x80099E7C: lh          $a1, 0x5A50($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X5A50));
    after_9:
    // 0x80099E80: b           L_80099EC8
    // 0x80099E84: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099E84: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80099E88: lbu         $t2, 0x25($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X25);
L_80099E8C:
    // 0x80099E8C: addiu       $a0, $zero, 0x105
    ctx->r4 = ADD32(0, 0X105);
    // 0x80099E90: beq         $t2, $zero, L_80099EA8
    if (ctx->r10 == 0) {
        // 0x80099E94: nop
    
            goto L_80099EA8;
    }
    // 0x80099E94: nop

    // 0x80099E98: jal         0x80059034
    // 0x80099E9C: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    spritesound(rdram, ctx);
        goto after_10;
    // 0x80099E9C: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    after_10:
    // 0x80099EA0: b           L_80099EC8
    // 0x80099EA4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099EA4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099EA8:
    // 0x80099EA8: lui         $a1, 0x802A
    ctx->r5 = S32(0X802A << 16);
    // 0x80099EAC: jal         0x80059034
    // 0x80099EB0: lh          $a1, 0x5A50($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X5A50));
    spritesound(rdram, ctx);
        goto after_11;
    // 0x80099EB0: lh          $a1, 0x5A50($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, 0X5A50));
    after_11:
    // 0x80099EB4: b           L_80099EC8
    // 0x80099EB8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80099EC8;
    // 0x80099EB8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099EBC:
    // 0x80099EBC: jal         0x80059034
    // 0x80099EC0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    spritesound(rdram, ctx);
        goto after_12;
    // 0x80099EC0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_12:
L_80099EC4:
    // 0x80099EC4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80099EC8:
    // 0x80099EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099ECC: jr          $ra
    // 0x80099ED0: nop

    return;
    // 0x80099ED0: nop

;}
RECOMP_FUNC void findplayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ACF1C: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800ACF20: lw          $a2, -0x540C($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, -0X540C));
    // 0x800ACF24: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800ACF28: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800ACF2C: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x800ACF30: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800ACF34: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800ACF38: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800ACF3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800ACF40: beq         $at, $zero, L_800ACFEC
    if (ctx->r1 == 0) {
        // 0x800ACF44: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800ACFEC;
    }
    // 0x800ACF44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800ACF48: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x800ACF4C: addiu       $a3, $a3, -0x9D8
    ctx->r7 = ADD32(ctx->r7, -0X9D8);
    // 0x800ACF50: lh          $t6, 0x0($a3)
    ctx->r14 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800ACF54: addiu       $t1, $zero, 0x38C
    ctx->r9 = ADD32(0, 0X38C);
    // 0x800ACF58: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x800ACF5C: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ACF60: addiu       $t0, $t0, 0x5770
    ctx->r8 = ADD32(ctx->r8, 0X5770);
    // 0x800ACF64: lw          $t6, 0x4($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800ACF68: lw          $t9, 0x18($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800ACF6C: mflo        $t7
    ctx->r15 = lo;
    // 0x800ACF70: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x800ACF74: lw          $t8, 0x23C($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X23C));
    // 0x800ACF78: subu        $v1, $t8, $t6
    ctx->r3 = SUB32(ctx->r24, ctx->r14);
    // 0x800ACF7C: blez        $v1, L_800ACF8C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800ACF80: negu        $a0, $v1
        ctx->r4 = SUB32(0, ctx->r3);
            goto L_800ACF8C;
    }
    // 0x800ACF80: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
    // 0x800ACF84: b           L_800ACF8C
    // 0x800ACF88: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_800ACF8C;
    // 0x800ACF88: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800ACF8C:
    // 0x800ACF8C: lw          $t7, 0x238($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X238));
    // 0x800ACF90: lw          $t8, 0x0($t9)
    ctx->r24 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800ACF94: lw          $t9, 0x18($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800ACF98: subu        $a1, $t7, $t8
    ctx->r5 = SUB32(ctx->r15, ctx->r24);
    // 0x800ACF9C: blez        $a1, L_800ACFAC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800ACFA0: negu        $v1, $a1
        ctx->r3 = SUB32(0, ctx->r5);
            goto L_800ACFAC;
    }
    // 0x800ACFA0: negu        $v1, $a1
    ctx->r3 = SUB32(0, ctx->r5);
    // 0x800ACFA4: b           L_800ACFAC
    // 0x800ACFA8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_800ACFAC;
    // 0x800ACFA8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800ACFAC:
    // 0x800ACFAC: lw          $t6, 0x240($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X240));
    // 0x800ACFB0: lw          $t7, 0x8($t9)
    ctx->r15 = S32(MEM_W(ctx->r25, 0X8));
    // 0x800ACFB4: addiu       $t8, $zero, -0x1C00
    ctx->r24 = ADD32(0, -0X1C00);
    // 0x800ACFB8: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    // 0x800ACFBC: addiu       $a2, $a1, 0x1C00
    ctx->r6 = ADD32(ctx->r5, 0X1C00);
    // 0x800ACFC0: blez        $a2, L_800ACFD0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800ACFC4: subu        $t2, $t8, $a1
        ctx->r10 = SUB32(ctx->r24, ctx->r5);
            goto L_800ACFD0;
    }
    // 0x800ACFC4: subu        $t2, $t8, $a1
    ctx->r10 = SUB32(ctx->r24, ctx->r5);
    // 0x800ACFC8: b           L_800ACFD0
    // 0x800ACFCC: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
        goto L_800ACFD0;
    // 0x800ACFCC: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
L_800ACFD0:
    // 0x800ACFD0: lw          $t8, 0x1C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800ACFD4: sra         $t9, $t2, 4
    ctx->r25 = S32(SIGNED(ctx->r10) >> 4);
    // 0x800ACFD8: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800ACFDC: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800ACFE0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800ACFE4: b           L_800AD0EC
    // 0x800ACFE8: lh          $v0, 0x0($a3)
    ctx->r2 = S32(MEM_H(ctx->r7, 0X0));
        goto L_800AD0EC;
    // 0x800ACFE8: lh          $v0, 0x0($a3)
    ctx->r2 = S32(MEM_H(ctx->r7, 0X0));
L_800ACFEC:
    // 0x800ACFEC: lui         $a1, 0x7FFF
    ctx->r5 = S32(0X7FFF << 16);
    // 0x800ACFF0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800ACFF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800ACFF8: blez        $a2, L_800AD0E0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800ACFFC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AD0E0;
    }
    // 0x800ACFFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD000: lw          $t9, 0x18($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800AD004: lui         $s3, 0x8024
    ctx->r19 = S32(0X8024 << 16);
    // 0x800AD008: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x800AD00C: addiu       $t0, $t0, 0x5770
    ctx->r8 = ADD32(ctx->r8, 0X5770);
    // 0x800AD010: addiu       $s3, $s3, 0x6BA8
    ctx->r19 = ADD32(ctx->r19, 0X6BA8);
    // 0x800AD014: addiu       $s4, $zero, 0x2C
    ctx->r20 = ADD32(0, 0X2C);
    // 0x800AD018: addiu       $t1, $zero, 0x38C
    ctx->r9 = ADD32(0, 0X38C);
    // 0x800AD01C: lw          $t3, 0x4($t9)
    ctx->r11 = S32(MEM_W(ctx->r25, 0X4));
    // 0x800AD020: lw          $t4, 0x0($t9)
    ctx->r12 = S32(MEM_W(ctx->r25, 0X0));
    // 0x800AD024: lw          $t5, 0x8($t9)
    ctx->r13 = S32(MEM_W(ctx->r25, 0X8));
L_800AD028:
    // 0x800AD028: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD02C: mflo        $t6
    ctx->r14 = lo;
    // 0x800AD030: addu        $s1, $t0, $t6
    ctx->r17 = ADD32(ctx->r8, ctx->r14);
    // 0x800AD034: lw          $t7, 0x23C($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X23C));
    // 0x800AD038: addiu       $t6, $zero, -0x1C00
    ctx->r14 = ADD32(0, -0X1C00);
    // 0x800AD03C: subu        $v1, $t7, $t3
    ctx->r3 = SUB32(ctx->r15, ctx->r11);
    // 0x800AD040: blez        $v1, L_800AD050
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AD044: negu        $a0, $v1
        ctx->r4 = SUB32(0, ctx->r3);
            goto L_800AD050;
    }
    // 0x800AD044: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
    // 0x800AD048: b           L_800AD050
    // 0x800AD04C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_800AD050;
    // 0x800AD04C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800AD050:
    // 0x800AD050: lw          $t8, 0x238($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X238));
    // 0x800AD054: subu        $t2, $t8, $t4
    ctx->r10 = SUB32(ctx->r24, ctx->r12);
    // 0x800AD058: blez        $t2, L_800AD068
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AD05C: negu        $v1, $t2
        ctx->r3 = SUB32(0, ctx->r10);
            goto L_800AD068;
    }
    // 0x800AD05C: negu        $v1, $t2
    ctx->r3 = SUB32(0, ctx->r10);
    // 0x800AD060: b           L_800AD068
    // 0x800AD064: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
        goto L_800AD068;
    // 0x800AD064: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_800AD068:
    // 0x800AD068: lw          $t9, 0x240($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X240));
    // 0x800AD06C: subu        $s0, $t9, $t5
    ctx->r16 = SUB32(ctx->r25, ctx->r13);
    // 0x800AD070: addiu       $s2, $s0, 0x1C00
    ctx->r18 = ADD32(ctx->r16, 0X1C00);
    // 0x800AD074: blez        $s2, L_800AD084
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800AD078: subu        $t2, $t6, $s0
        ctx->r10 = SUB32(ctx->r14, ctx->r16);
            goto L_800AD084;
    }
    // 0x800AD078: subu        $t2, $t6, $s0
    ctx->r10 = SUB32(ctx->r14, ctx->r16);
    // 0x800AD07C: b           L_800AD084
    // 0x800AD080: or          $t2, $s2, $zero
    ctx->r10 = ctx->r18 | 0;
        goto L_800AD084;
    // 0x800AD080: or          $t2, $s2, $zero
    ctx->r10 = ctx->r18 | 0;
L_800AD084:
    // 0x800AD084: sra         $t7, $t2, 4
    ctx->r15 = S32(SIGNED(ctx->r10) >> 4);
    // 0x800AD088: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800AD08C: addu        $s0, $t8, $a0
    ctx->r16 = ADD32(ctx->r24, ctx->r4);
    // 0x800AD090: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AD094: beql        $at, $zero, L_800AD0CC
    if (ctx->r1 == 0) {
        // 0x800AD098: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800AD0CC;
    }
    goto skip_0;
    // 0x800AD098: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800AD09C: lh          $t9, 0x2E0($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X2E0));
    // 0x800AD0A0: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AD0A4: mflo        $t6
    ctx->r14 = lo;
    // 0x800AD0A8: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x800AD0AC: lh          $t8, 0x22($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X22));
    // 0x800AD0B0: blezl       $t8, L_800AD0CC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AD0B4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800AD0CC;
    }
    goto skip_1;
    // 0x800AD0B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x800AD0B8: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x800AD0BC: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800AD0C0: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800AD0C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AD0C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800AD0CC:
    // 0x800AD0CC: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800AD0D0: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AD0D4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AD0D8: bne         $at, $zero, L_800AD028
    if (ctx->r1 != 0) {
        // 0x800AD0DC: nop
    
            goto L_800AD028;
    }
    // 0x800AD0DC: nop

L_800AD0E0:
    // 0x800AD0E0: lw          $t8, 0x1C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800AD0E4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800AD0E8: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
L_800AD0EC:
    // 0x800AD0EC: lw          $s0, 0x4($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X4));
    // 0x800AD0F0: lw          $s1, 0x8($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X8));
    // 0x800AD0F4: lw          $s2, 0xC($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0XC));
    // 0x800AD0F8: lw          $s3, 0x10($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X10));
    // 0x800AD0FC: lw          $s4, 0x14($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800AD100: jr          $ra
    // 0x800AD104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AD104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80051D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051D98: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80051D9C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80051DA0: lb          $t6, 0x38D0($t6)
    ctx->r14 = S32(MEM_B(ctx->r14, 0X38D0));
    // 0x80051DA4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80051DA8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80051DAC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80051DB0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80051DB4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80051DB8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80051DBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051DC0: beq         $t6, $zero, L_80051DD0
    if (ctx->r14 == 0) {
        // 0x80051DC4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80051DD0;
    }
    // 0x80051DC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051DC8: b           L_80051FD8
    // 0x80051DCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051FD8;
    // 0x80051DCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051DD0:
    // 0x80051DD0: jal         0x80051D40
    // 0x80051DD4: nop

    func_80051D40(rdram, ctx);
        goto after_0;
    // 0x80051DD4: nop

    after_0:
    // 0x80051DD8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80051DDC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80051DE0: addiu       $a1, $a1, -0x6CB8
    ctx->r5 = ADD32(ctx->r5, -0X6CB8);
    // 0x80051DE4: jal         0x800BD110
    // 0x80051DE8: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_1;
    // 0x80051DE8: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    after_1:
    // 0x80051DEC: jal         0x80051D6C
    // 0x80051DF0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    func_80051D6C(rdram, ctx);
        goto after_2;
    // 0x80051DF0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    after_2:
    // 0x80051DF4: beq         $s5, $zero, L_80051E04
    if (ctx->r21 == 0) {
        // 0x80051DF8: nop
    
            goto L_80051E04;
    }
    // 0x80051DF8: nop

    // 0x80051DFC: b           L_80051FD8
    // 0x80051E00: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
        goto L_80051FD8;
    // 0x80051E00: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_80051E04:
    // 0x80051E04: jal         0x80051D40
    // 0x80051E08: nop

    func_80051D40(rdram, ctx);
        goto after_3;
    // 0x80051E08: nop

    after_3:
    // 0x80051E0C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80051E10: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80051E14: addiu       $a2, $a2, -0x6CBC
    ctx->r6 = ADD32(ctx->r6, -0X6CBC);
    // 0x80051E18: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    // 0x80051E1C: jal         0x800BCFC0
    // 0x80051E20: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_4;
    // 0x80051E20: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x80051E24: jal         0x80051D6C
    // 0x80051E28: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    func_80051D6C(rdram, ctx);
        goto after_5;
    // 0x80051E28: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    after_5:
    // 0x80051E2C: beq         $s5, $zero, L_80051E3C
    if (ctx->r21 == 0) {
        // 0x80051E30: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80051E3C;
    }
    // 0x80051E30: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80051E34: b           L_80051FD8
    // 0x80051E38: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
        goto L_80051FD8;
    // 0x80051E38: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_80051E3C:
    // 0x80051E3C: lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // 0x80051E40: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80051E44: addiu       $s0, $s0, 0x38D4
    ctx->r16 = ADD32(ctx->r16, 0X38D4);
    // 0x80051E48: addiu       $s6, $s6, -0x46D8
    ctx->r22 = ADD32(ctx->r22, -0X46D8);
    // 0x80051E4C: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x80051E50: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x80051E54: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80051E58:
    // 0x80051E58: jal         0x80051D40
    // 0x80051E5C: nop

    func_80051D40(rdram, ctx);
        goto after_6;
    // 0x80051E5C: nop

    after_6:
    // 0x80051E60: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80051E64: addiu       $a0, $a0, -0x6CB0
    ctx->r4 = ADD32(ctx->r4, -0X6CB0);
    // 0x80051E68: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80051E6C: jal         0x800BDAE0
    // 0x80051E70: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    osPfsFileState_recomp(rdram, ctx);
        goto after_7;
    // 0x80051E70: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_7:
    // 0x80051E74: jal         0x80051D6C
    // 0x80051E78: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    func_80051D6C(rdram, ctx);
        goto after_8;
    // 0x80051E78: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    after_8:
    // 0x80051E7C: beq         $s5, $zero, L_80051E94
    if (ctx->r21 == 0) {
        // 0x80051E80: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80051E94;
    }
    // 0x80051E80: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80051E84: beql        $s5, $at, L_80051E98
    if (ctx->r21 == ctx->r1) {
        // 0x80051E88: sll         $t8, $s4, 2
        ctx->r24 = S32(ctx->r20 << 2);
            goto L_80051E98;
    }
    goto skip_0;
    // 0x80051E88: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    skip_0:
    // 0x80051E8C: b           L_80051FD8
    // 0x80051E90: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
        goto L_80051FD8;
    // 0x80051E90: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_80051E94:
    // 0x80051E94: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
L_80051E98:
    // 0x80051E98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051E9C: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x80051EA0: addu        $t8, $t8, $s4
    ctx->r24 = ADD32(ctx->r24, ctx->r20);
    // 0x80051EA4: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x80051EA8: addiu       $t7, $t7, -0x4378
    ctx->r15 = ADD32(ctx->r15, -0X4378);
    // 0x80051EAC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80051EB0: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x80051EB4: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x80051EB8: sb          $s5, -0x4388($at)
    MEM_B(-0X4388, ctx->r1) = ctx->r21;
    // 0x80051EBC: addu        $a1, $s4, $t7
    ctx->r5 = ADD32(ctx->r20, ctx->r15);
    // 0x80051EC0: addiu       $t2, $t2, -0x43A8
    ctx->r10 = ADD32(ctx->r10, -0X43A8);
    // 0x80051EC4: addiu       $t9, $t9, -0x44D8
    ctx->r25 = ADD32(ctx->r25, -0X44D8);
    // 0x80051EC8: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x80051ECC: sll         $t1, $s4, 1
    ctx->r9 = S32(ctx->r20 << 1);
    // 0x80051ED0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80051ED4: addu        $a3, $t1, $t2
    ctx->r7 = ADD32(ctx->r9, ctx->r10);
    // 0x80051ED8: bne         $s5, $zero, L_80051FA8
    if (ctx->r21 != 0) {
        // 0x80051EDC: addu        $t0, $t8, $t9
        ctx->r8 = ADD32(ctx->r24, ctx->r25);
            goto L_80051FA8;
    }
    // 0x80051EDC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80051EE0: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x80051EE4: addu        $t5, $t5, $s4
    ctx->r13 = ADD32(ctx->r13, ctx->r20);
    // 0x80051EE8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80051EEC: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x80051EF0: addiu       $t4, $t4, -0x46D8
    ctx->r12 = ADD32(ctx->r12, -0X46D8);
    // 0x80051EF4: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x80051EF8: sll         $t3, $s4, 5
    ctx->r11 = S32(ctx->r20 << 5);
    // 0x80051EFC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80051F00: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x80051F04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80051F08:
    // 0x80051F08: lbu         $v1, 0xE($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XE);
    // 0x80051F0C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80051F10: sltiu       $at, $v1, 0x44
    ctx->r1 = ctx->r3 < 0X44 ? 1 : 0;
    // 0x80051F14: beq         $at, $zero, L_80051F28
    if (ctx->r1 == 0) {
        // 0x80051F18: addu        $t6, $s0, $v1
        ctx->r14 = ADD32(ctx->r16, ctx->r3);
            goto L_80051F28;
    }
    // 0x80051F18: addu        $t6, $s0, $v1
    ctx->r14 = ADD32(ctx->r16, ctx->r3);
    // 0x80051F1C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80051F20: b           L_80051F30
    // 0x80051F24: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_80051F30;
    // 0x80051F24: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_80051F28:
    // 0x80051F28: sb          $s1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r17;
    // 0x80051F2C: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_80051F30:
    // 0x80051F30: lbu         $v1, 0xF($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XF);
    // 0x80051F34: sltiu       $at, $v1, 0x44
    ctx->r1 = ctx->r3 < 0X44 ? 1 : 0;
    // 0x80051F38: beq         $at, $zero, L_80051F4C
    if (ctx->r1 == 0) {
        // 0x80051F3C: addu        $t8, $s0, $v1
        ctx->r24 = ADD32(ctx->r16, ctx->r3);
            goto L_80051F4C;
    }
    // 0x80051F3C: addu        $t8, $s0, $v1
    ctx->r24 = ADD32(ctx->r16, ctx->r3);
    // 0x80051F40: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x80051F44: b           L_80051F54
    // 0x80051F48: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
        goto L_80051F54;
    // 0x80051F48: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
L_80051F4C:
    // 0x80051F4C: sb          $s1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r17;
    // 0x80051F50: sb          $s2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r18;
L_80051F54:
    // 0x80051F54: lbu         $v1, 0x10($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X10);
    // 0x80051F58: sltiu       $at, $v1, 0x44
    ctx->r1 = ctx->r3 < 0X44 ? 1 : 0;
    // 0x80051F5C: beq         $at, $zero, L_80051F70
    if (ctx->r1 == 0) {
        // 0x80051F60: addu        $t2, $s0, $v1
        ctx->r10 = ADD32(ctx->r16, ctx->r3);
            goto L_80051F70;
    }
    // 0x80051F60: addu        $t2, $s0, $v1
    ctx->r10 = ADD32(ctx->r16, ctx->r3);
    // 0x80051F64: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80051F68: b           L_80051F78
    // 0x80051F6C: sb          $t3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r11;
        goto L_80051F78;
    // 0x80051F6C: sb          $t3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r11;
L_80051F70:
    // 0x80051F70: sb          $s1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r17;
    // 0x80051F74: sb          $s2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r18;
L_80051F78:
    // 0x80051F78: lbu         $v1, 0x11($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X11);
    // 0x80051F7C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80051F80: sltiu       $at, $v1, 0x44
    ctx->r1 = ctx->r3 < 0X44 ? 1 : 0;
    // 0x80051F84: beq         $at, $zero, L_80051F98
    if (ctx->r1 == 0) {
        // 0x80051F88: addu        $t4, $s0, $v1
        ctx->r12 = ADD32(ctx->r16, ctx->r3);
            goto L_80051F98;
    }
    // 0x80051F88: addu        $t4, $s0, $v1
    ctx->r12 = ADD32(ctx->r16, ctx->r3);
    // 0x80051F8C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80051F90: b           L_80051FA0
    // 0x80051F94: sb          $t5, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r13;
        goto L_80051FA0;
    // 0x80051F94: sb          $t5, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r13;
L_80051F98:
    // 0x80051F98: sb          $s1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r17;
    // 0x80051F9C: sb          $s2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r18;
L_80051FA0:
    // 0x80051FA0: bne         $a2, $s3, L_80051F08
    if (ctx->r6 != ctx->r19) {
        // 0x80051FA4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80051F08;
    }
    // 0x80051FA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80051FA8:
    // 0x80051FA8: lbu         $t9, 0xA($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0XA);
    // 0x80051FAC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80051FB0: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
    // 0x80051FB4: addu        $t6, $s0, $t9
    ctx->r14 = ADD32(ctx->r16, ctx->r25);
    // 0x80051FB8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80051FBC: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
    // 0x80051FC0: sb          $zero, 0x1($a3)
    MEM_B(0X1, ctx->r7) = 0;
    // 0x80051FC4: bne         $s4, $s3, L_80051E58
    if (ctx->r20 != ctx->r19) {
        // 0x80051FC8: sb          $t7, 0x0($a3)
        MEM_B(0X0, ctx->r7) = ctx->r15;
            goto L_80051E58;
    }
    // 0x80051FC8: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
    // 0x80051FCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051FD0: sb          $s1, 0x38D0($at)
    MEM_B(0X38D0, ctx->r1) = ctx->r17;
    // 0x80051FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051FD8:
    // 0x80051FD8: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80051FDC: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80051FE0: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80051FE4: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80051FE8: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80051FEC: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80051FF0: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80051FF4: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80051FF8: jr          $ra
    // 0x80051FFC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80051FFC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void resetmovesectorinfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A844: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A84C: sh          $zero, 0x4D9C($at)
    MEM_H(0X4D9C, ctx->r1) = 0;
    // 0x8005A850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A854: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005A858: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005A85C: sh          $zero, 0x4DA0($at)
    MEM_H(0X4DA0, ctx->r1) = 0;
    // 0x8005A860: addiu       $a0, $a0, -0x3E28
    ctx->r4 = ADD32(ctx->r4, -0X3E28);
    // 0x8005A864: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8005A868: jal         0x8005A548
    // 0x8005A86C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    clearbufbyte(rdram, ctx);
        goto after_0;
    // 0x8005A86C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_0:
    // 0x8005A870: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005A874: addiu       $a0, $a0, -0x3DD8
    ctx->r4 = ADD32(ctx->r4, -0X3DD8);
    // 0x8005A878: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8005A87C: jal         0x8005A548
    // 0x8005A880: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    clearbufbyte(rdram, ctx);
        goto after_1;
    // 0x8005A880: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x8005A884: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005A888: addiu       $a0, $a0, -0x3D88
    ctx->r4 = ADD32(ctx->r4, -0X3D88);
    // 0x8005A88C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8005A890: jal         0x8005A548
    // 0x8005A894: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    clearbufbyte(rdram, ctx);
        goto after_2;
    // 0x8005A894: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    after_2:
    // 0x8005A898: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005A89C: addiu       $a0, $a0, -0x33A0
    ctx->r4 = ADD32(ctx->r4, -0X33A0);
    // 0x8005A8A0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8005A8A4: jal         0x8005A548
    // 0x8005A8A8: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    clearbufbyte(rdram, ctx);
        goto after_3;
    // 0x8005A8A8: addiu       $a2, $zero, 0x9E4
    ctx->r6 = ADD32(0, 0X9E4);
    after_3:
    // 0x8005A8AC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8005A8B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A8B4: jr          $ra
    // 0x8005A8B8: nop

    return;
    // 0x8005A8B8: nop

;}
RECOMP_FUNC void alAuxBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE3F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CE3F4: bne         $a1, $at, L_800CE418
    if (ctx->r5 != ctx->r1) {
        // 0x800CE3F8: lw          $v0, 0x1C($a0)
        ctx->r2 = S32(MEM_W(ctx->r4, 0X1C));
            goto L_800CE418;
    }
    // 0x800CE3F8: lw          $v0, 0x1C($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X1C));
    // 0x800CE3FC: lw          $t6, 0x14($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800CE400: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CE404: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800CE408: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800CE40C: lw          $t9, 0x14($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800CE410: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CE414: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800CE418:
    // 0x800CE418: jr          $ra
    // 0x800CE41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mulscale9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FB84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FB88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FB8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FB90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FB94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FB98: jal         0x800BB8F8
    // 0x8008FB9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FB9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FBA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FBA4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FBA8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FBAC: jal         0x800BBA24
    // 0x8008FBB0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FBB0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_1:
    // 0x8008FBB4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FBB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FBBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FBC0: jr          $ra
    // 0x8008FBC4: nop

    return;
    // 0x8008FBC4: nop

;}
RECOMP_FUNC void myospal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724B0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800724B4: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800724B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800724BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800724C0: lbu         $v0, 0x4F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X4F);
    // 0x800724C4: sll         $t6, $a3, 24
    ctx->r14 = S32(ctx->r7 << 24);
    // 0x800724C8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800724CC: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800724D0: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800724D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800724D8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800724DC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800724E0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800724E4: beq         $v0, $at, L_80072524
    if (ctx->r2 == ctx->r1) {
        // 0x800724E8: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_80072524;
    }
    // 0x800724E8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800724EC: sll         $a1, $t7, 16
    ctx->r5 = S32(ctx->r15 << 16);
    // 0x800724F0: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800724F4: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800724F8: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800724FC: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80072500: lbu         $a0, -0x2904($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2904);
    // 0x80072504: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80072508: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8007250C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80072510: jal         0x80071FFC
    // 0x80072514: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    rotatesprite_setidshadepal(rdram, ctx);
        goto after_0;
    // 0x80072514: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80072518: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = S32(MEM_W(ctx->r29, 0X24));
    // 0x8007251C: b           L_80072548
    // 0x80072520: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X2C));
        goto L_80072548;
    // 0x80072520: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X2C));
L_80072524:
    // 0x80072524: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80072528: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007252C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80072530: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
    // 0x80072534: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80072538: jal         0x8006E994
    // 0x8007253C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    setrotatespriteflags(rdram, ctx);
        goto after_1;
    // 0x8007253C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80072540: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = S32(MEM_W(ctx->r29, 0X24));
    // 0x80072544: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X2C));
L_80072548:
    // 0x80072548: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8007254C: lh          $v0, -0x9DC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9DC));
    // 0x80072550: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80072554: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x80072558: bne         $v1, $v0, L_80072598
    if (ctx->r3 != ctx->r2) {
        // 0x8007255C: addiu       $t4, $zero, 0x64
        ctx->r12 = ADD32(0, 0X64);
            goto L_80072598;
    }
    // 0x8007255C: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80072560: lbu         $t0, -0x2904($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X2904);
    // 0x80072564: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80072568: bne         $t0, $zero, L_80072588
    if (ctx->r8 != 0) {
        // 0x8007256C: nop
    
            goto L_80072588;
    }
    // 0x8007256C: nop

    // 0x80072570: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80072574: ldc1        $f18, 0x5218($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X5218);
    // 0x80072578: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8007257C: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x80072580: b           L_80072598
    // 0x80072584: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
        goto L_80072598;
    // 0x80072584: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
L_80072588:
    // 0x80072588: ldc1        $f8, 0x5220($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X5220);
    // 0x8007258C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80072590: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80072594: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
L_80072598:
    // 0x80072598: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8007259C: bne         $at, $zero, L_80072674
    if (ctx->r1 != 0) {
        // 0x800725A0: lwc1        $f18, 0x28($sp)
        ctx->f18.u32l = S32(MEM_W(ctx->r29, 0X28));
            goto L_80072674;
    }
    // 0x800725A0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = S32(MEM_W(ctx->r29, 0X28));
    // 0x800725A4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800725A8: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800725AC: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x800725B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800725B4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800725B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800725BC: sub.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800725C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800725C4: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800725C8: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800725CC: lbu         $v0, -0x2904($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2904);
    // 0x800725D0: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x800725D4: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800725D8: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800725DC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800725E0: nop

    // 0x800725E4: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800725E8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800725EC: beq         $v0, $zero, L_800725FC
    if (ctx->r2 == 0) {
        // 0x800725F0: cvt.s.d     $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
            goto L_800725FC;
    }
    // 0x800725F0: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x800725F4: bne         $v1, $v0, L_80072604
    if (ctx->r3 != ctx->r2) {
        // 0x800725F8: lui         $at, 0x4064
        ctx->r1 = S32(0X4064 << 16);
            goto L_80072604;
    }
    // 0x800725F8: lui         $at, 0x4064
    ctx->r1 = S32(0X4064 << 16);
L_800725FC:
    // 0x800725FC: b           L_80072618
    // 0x80072600: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
        goto L_80072618;
    // 0x80072600: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
L_80072604:
    // 0x80072604: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80072608: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007260C: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80072610: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80072614: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_80072618:
    // 0x80072618: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8007261C: lh          $t2, 0x42($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X42));
    // 0x80072620: beq         $v0, $zero, L_80072634
    if (ctx->r2 == 0) {
        // 0x80072624: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80072634;
    }
    // 0x80072624: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80072628: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007262C: bnel        $v0, $at, L_80072640
    if (ctx->r2 != ctx->r1) {
        // 0x80072630: lui         $at, 0x405E
        ctx->r1 = S32(0X405E << 16);
            goto L_80072640;
    }
    goto skip_0;
    // 0x80072630: lui         $at, 0x405E
    ctx->r1 = S32(0X405E << 16);
    skip_0:
L_80072634:
    // 0x80072634: b           L_80072654
    // 0x80072638: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
        goto L_80072654;
    // 0x80072638: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8007263C: lui         $at, 0x405E
    ctx->r1 = S32(0X405E << 16);
L_80072640:
    // 0x80072640: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80072644: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80072648: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x8007264C: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x80072650: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
L_80072654:
    // 0x80072654: lbu         $t3, 0x4B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4B);
    // 0x80072658: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007265C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80072660: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80072664: jal         0x8005EE40
    // 0x80072668: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    rotatespritesc(rdram, ctx);
        goto after_2;
    // 0x80072668: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_2:
    // 0x8007266C: b           L_800726A4
    // 0x80072670: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_800726A4;
    // 0x80072670: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_80072674:
    // 0x80072674: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80072678: lh          $t5, 0x42($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X42));
    // 0x8007267C: lbu         $t6, 0x4B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4B);
    // 0x80072680: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80072684: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X28));
    // 0x80072688: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8007268C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80072690: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80072694: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80072698: jal         0x8005D13C
    // 0x8007269C: nop

    rotatesprite(rdram, ctx);
        goto after_3;
    // 0x8007269C: nop

    after_3:
    // 0x800726A0: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
L_800726A4:
    // 0x800726A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800726A8: jr          $ra
    // 0x800726AC: nop

    return;
    // 0x800726AC: nop

;}
RECOMP_FUNC void checksectors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3CD0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B3CD4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800B3CD8: lh          $t6, 0x72($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X72));
    // 0x800B3CDC: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800B3CE0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800B3CE4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800B3CE8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B3CEC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B3CF0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B3CF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B3CF8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B3CFC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B3D00: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x800B3D04: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x800B3D08: lh          $v0, 0x288($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800B3D0C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B3D10: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800B3D14: bne         $t4, $v0, L_800B3D74
    if (ctx->r12 != ctx->r2) {
        // 0x800B3D18: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800B3D74;
    }
    // 0x800B3D18: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800B3D1C: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B3D20: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B3D24: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B3D28: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3D2C: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B3D30: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x800B3D34: addiu       $t5, $t5, -0x5598
    ctx->r13 = ADD32(ctx->r13, -0X5598);
    // 0x800B3D38: mflo        $t6
    ctx->r14 = lo;
    // 0x800B3D3C: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800B3D40: lh          $t8, 0x22($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X22));
    // 0x800B3D44: blezl       $t8, L_800B4C68
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B3D48: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_0;
    // 0x800B3D48: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_0:
    // 0x800B3D4C: lbu         $t9, 0x7($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X7);
    // 0x800B3D50: bnel        $t9, $zero, L_800B4C68
    if (ctx->r25 != 0) {
        // 0x800B3D54: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_1;
    // 0x800B3D54: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_1:
    // 0x800B3D58: jal         0x800A1718
    // 0x800B3D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    quickkill(rdram, ctx);
        goto after_0;
    // 0x800B3D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800B3D60: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x800B3D64: jal         0x80059034
    // 0x800B3D68: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_1;
    // 0x800B3D68: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_1:
    // 0x800B3D6C: b           L_800B4C68
    // 0x800B3D70: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B3D70: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B3D74:
    // 0x800B3D74: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800B3D78: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800B3D7C: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x800B3D80: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800B3D84: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800B3D88: lh          $a3, 0x18($a2)
    ctx->r7 = S32(MEM_H(ctx->r6, 0X18));
    // 0x800B3D8C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800B3D90: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x800B3D94: beq         $a3, $at, L_800B3EBC
    if (ctx->r7 == ctx->r1) {
        // 0x800B3D98: addiu       $t5, $t5, -0x5598
        ctx->r13 = ADD32(ctx->r13, -0X5598);
            goto L_800B3EBC;
    }
    // 0x800B3D98: addiu       $t5, $t5, -0x5598
    ctx->r13 = ADD32(ctx->r13, -0X5598);
    // 0x800B3D9C: beq         $a3, $t4, L_800B3DCC
    if (ctx->r7 == ctx->r12) {
        // 0x800B3DA0: lui         $t5, 0x802B
        ctx->r13 = S32(0X802B << 16);
            goto L_800B3DCC;
    }
    // 0x800B3DA0: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x800B3DA4: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x800B3DA8: bne         $a3, $at, L_800B3F1C
    if (ctx->r7 != ctx->r1) {
        // 0x800B3DAC: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_800B3F1C;
    }
    // 0x800B3DAC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800B3DB0: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    // 0x800B3DB4: jal         0x80099868
    // 0x800B3DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    FTA(rdram, ctx);
        goto after_2;
    // 0x800B3DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800B3DBC: lbu         $t8, 0x366($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X366);
    // 0x800B3DC0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B3DC4: b           L_800B4C64
    // 0x800B3DC8: sb          $t9, 0x366($s0)
    MEM_B(0X366, ctx->r16) = ctx->r25;
        goto L_800B4C64;
    // 0x800B3DC8: sb          $t9, 0x366($s0)
    MEM_B(0X366, ctx->r16) = ctx->r25;
L_800B3DCC:
    // 0x800B3DCC: addiu       $t5, $t5, -0x5598
    ctx->r13 = ADD32(ctx->r13, -0X5598);
    // 0x800B3DD0: lw          $a1, 0x18C($t5)
    ctx->r5 = S32(MEM_W(ctx->r13, 0X18C));
    // 0x800B3DD4: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800B3DD8: bne         $at, $zero, L_800B3E00
    if (ctx->r1 != 0) {
        // 0x800B3DDC: nop
    
            goto L_800B3E00;
    }
    // 0x800B3DDC: nop

    // 0x800B3DE0: lw          $t6, 0x13C($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X13C));
    // 0x800B3DE4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800B3DE8: bne         $t6, $zero, L_800B3E00
    if (ctx->r14 != 0) {
        // 0x800B3DEC: nop
    
            goto L_800B3E00;
    }
    // 0x800B3DEC: nop

    // 0x800B3DF0: lbu         $t7, 0x378C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X378C);
    // 0x800B3DF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B3DF8: bnel        $t7, $at, L_800B3F8C
    if (ctx->r15 != ctx->r1) {
        // 0x800B3DFC: lh          $t9, 0x2E0($s0)
        ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
            goto L_800B3F8C;
    }
    goto skip_2;
    // 0x800B3DFC: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    skip_2:
L_800B3E00:
    // 0x800B3E00: blez        $a1, L_800B3E5C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800B3E04: lui         $t8, 0x802A
        ctx->r24 = S32(0X802A << 16);
            goto L_800B3E5C;
    }
    // 0x800B3E04: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800B3E08: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x800B3E0C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x800B3E10: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800B3E14: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x800B3E18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B3E1C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x800B3E20: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B3E24: addiu       $v0, $t8, 0x5770
    ctx->r2 = ADD32(ctx->r24, 0X5770);
    // 0x800B3E28: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x800B3E2C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800B3E30:
    // 0x800B3E30: addiu       $v0, $v0, 0x38C
    ctx->r2 = ADD32(ctx->r2, 0X38C);
    // 0x800B3E34: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800B3E38: bne         $at, $zero, L_800B3E30
    if (ctx->r1 != 0) {
        // 0x800B3E3C: sb          $v1, -0x54($v0)
        MEM_B(-0X54, ctx->r2) = ctx->r3;
            goto L_800B3E30;
    }
    // 0x800B3E3C: sb          $v1, -0x54($v0)
    MEM_B(-0X54, ctx->r2) = ctx->r3;
    // 0x800B3E40: lh          $t6, 0x288($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800B3E44: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800B3E48: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x800B3E4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B3E50: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B3E54: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800B3E58: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
L_800B3E5C:
    // 0x800B3E5C: lh          $v0, 0xEA($t5)
    ctx->r2 = S32(MEM_H(ctx->r13, 0XEA));
    // 0x800B3E60: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    // 0x800B3E64: beql        $v0, $zero, L_800B3E80
    if (ctx->r2 == 0) {
        // 0x800B3E68: lw          $t6, 0x194($t5)
        ctx->r14 = S32(MEM_W(ctx->r13, 0X194));
            goto L_800B3E80;
    }
    goto skip_3;
    // 0x800B3E68: lw          $t6, 0x194($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X194));
    skip_3:
    // 0x800B3E6C: sw          $v0, 0x194($t5)
    MEM_W(0X194, ctx->r13) = ctx->r2;
    // 0x800B3E70: sw          $v0, 0x184($t5)
    MEM_W(0X184, ctx->r13) = ctx->r2;
    // 0x800B3E74: b           L_800B4C64
    // 0x800B3E78: sh          $zero, 0xEA($t5)
    MEM_H(0XEA, ctx->r13) = 0;
        goto L_800B4C64;
    // 0x800B3E78: sh          $zero, 0xEA($t5)
    MEM_H(0XEA, ctx->r13) = 0;
    // 0x800B3E7C: lw          $t6, 0x194($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X194));
L_800B3E80:
    // 0x800B3E80: lw          $t9, 0x198($t5)
    ctx->r25 = S32(MEM_W(ctx->r13, 0X198));
    // 0x800B3E84: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B3E88: beq         $t9, $zero, L_800B3E9C
    if (ctx->r25 == 0) {
        // 0x800B3E8C: sw          $t7, 0x194($t5)
        MEM_W(0X194, ctx->r13) = ctx->r15;
            goto L_800B3E9C;
    }
    // 0x800B3E8C: sw          $t7, 0x194($t5)
    MEM_W(0X194, ctx->r13) = ctx->r15;
    // 0x800B3E90: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x800B3E94: beql        $at, $zero, L_800B3EB0
    if (ctx->r1 == 0) {
        // 0x800B3E98: sw          $zero, 0x194($t5)
        MEM_W(0X194, ctx->r13) = 0;
            goto L_800B3EB0;
    }
    goto skip_4;
    // 0x800B3E98: sw          $zero, 0x194($t5)
    MEM_W(0X194, ctx->r13) = 0;
    skip_4:
L_800B3E9C:
    // 0x800B3E9C: lw          $v0, 0x194($t5)
    ctx->r2 = S32(MEM_W(ctx->r13, 0X194));
    // 0x800B3EA0: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800B3EA4: bne         $at, $zero, L_800B3EB4
    if (ctx->r1 != 0) {
        // 0x800B3EA8: nop
    
            goto L_800B3EB4;
    }
    // 0x800B3EA8: nop

    // 0x800B3EAC: sw          $zero, 0x194($t5)
    MEM_W(0X194, ctx->r13) = 0;
L_800B3EB0:
    // 0x800B3EB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B3EB4:
    // 0x800B3EB4: b           L_800B4C64
    // 0x800B3EB8: sw          $v0, 0x184($t5)
    MEM_W(0X184, ctx->r13) = ctx->r2;
        goto L_800B4C64;
    // 0x800B3EB8: sw          $v0, 0x184($t5)
    MEM_W(0X184, ctx->r13) = ctx->r2;
L_800B3EBC:
    // 0x800B3EBC: lw          $t6, 0x18C($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X18C));
    // 0x800B3EC0: addiu       $t8, $zero, 0xD0
    ctx->r24 = ADD32(0, 0XD0);
    // 0x800B3EC4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800B3EC8: bnel        $at, $zero, L_800B3EF4
    if (ctx->r1 != 0) {
        // 0x800B3ECC: sh          $zero, 0x18($a2)
        MEM_H(0X18, ctx->r6) = 0;
            goto L_800B3EF4;
    }
    goto skip_5;
    // 0x800B3ECC: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    skip_5:
    // 0x800B3ED0: lw          $t7, 0x13C($t5)
    ctx->r15 = S32(MEM_W(ctx->r13, 0X13C));
    // 0x800B3ED4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800B3ED8: bnel        $t7, $zero, L_800B3EF4
    if (ctx->r15 != 0) {
        // 0x800B3EDC: sh          $zero, 0x18($a2)
        MEM_H(0X18, ctx->r6) = 0;
            goto L_800B3EF4;
    }
    goto skip_6;
    // 0x800B3EDC: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    skip_6:
    // 0x800B3EE0: lbu         $t9, 0x378C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X378C);
    // 0x800B3EE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B3EE8: bnel        $t9, $at, L_800B3F8C
    if (ctx->r25 != ctx->r1) {
        // 0x800B3EEC: lh          $t9, 0x2E0($s0)
        ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
            goto L_800B3F8C;
    }
    goto skip_7;
    // 0x800B3EEC: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    skip_7:
    // 0x800B3EF0: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
L_800B3EF4:
    // 0x800B3EF4: lh          $t6, 0x288($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800B3EF8: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800B3EFC: sh          $t8, 0x2F0($s0)
    MEM_H(0X2F0, ctx->r16) = ctx->r24;
    // 0x800B3F00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B3F04: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B3F08: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800B3F0C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800B3F10: lh          $t9, -0x196E($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X196E));
    // 0x800B3F14: b           L_800B4C64
    // 0x800B3F18: sh          $t9, 0x2F2($s0)
    MEM_H(0X2F2, ctx->r16) = ctx->r25;
        goto L_800B4C64;
    // 0x800B3F18: sh          $t9, 0x2F2($s0)
    MEM_H(0X2F2, ctx->r16) = ctx->r25;
L_800B3F1C:
    // 0x800B3F1C: slti        $at, $a3, 0x2710
    ctx->r1 = SIGNED(ctx->r7) < 0X2710 ? 1 : 0;
    // 0x800B3F20: bne         $at, $zero, L_800B3F88
    if (ctx->r1 != 0) {
        // 0x800B3F24: slti        $at, $a3, 0x3FFF
        ctx->r1 = SIGNED(ctx->r7) < 0X3FFF ? 1 : 0;
            goto L_800B3F88;
    }
    // 0x800B3F24: slti        $at, $a3, 0x3FFF
    ctx->r1 = SIGNED(ctx->r7) < 0X3FFF ? 1 : 0;
    // 0x800B3F28: beq         $at, $zero, L_800B3F88
    if (ctx->r1 == 0) {
        // 0x800B3F2C: lh          $t8, 0x72($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0X72));
            goto L_800B3F88;
    }
    // 0x800B3F2C: lh          $t8, 0x72($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X72));
    // 0x800B3F30: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B3F34: lh          $t6, -0x53DC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X53DC));
    // 0x800B3F38: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x800B3F3C: addiu       $t5, $t5, -0x5598
    ctx->r13 = ADD32(ctx->r13, -0X5598);
    // 0x800B3F40: beq         $t8, $t6, L_800B3F54
    if (ctx->r24 == ctx->r14) {
        // 0x800B3F44: addiu       $a0, $a3, -0x2710
        ctx->r4 = ADD32(ctx->r7, -0X2710);
            goto L_800B3F54;
    }
    // 0x800B3F44: addiu       $a0, $a3, -0x2710
    ctx->r4 = ADD32(ctx->r7, -0X2710);
    // 0x800B3F48: lw          $t7, 0x13C($t5)
    ctx->r15 = S32(MEM_W(ctx->r13, 0X13C));
    // 0x800B3F4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B3F50: bne         $t7, $at, L_800B3F84
    if (ctx->r15 != ctx->r1) {
        // 0x800B3F54: andi        $t9, $a0, 0xFFFF
        ctx->r25 = ctx->r4 & 0XFFFF;
            goto L_800B3F84;
    }
L_800B3F54:
    // 0x800B3F54: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x800B3F58: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800B3F5C: jal         0x80059034
    // 0x800B3F60: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_3;
    // 0x800B3F60: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_3:
    // 0x800B3F64: lh          $t8, 0x288($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800B3F68: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800B3F6C: addiu       $t7, $t7, -0x1988
    ctx->r15 = ADD32(ctx->r15, -0X1988);
    // 0x800B3F70: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800B3F74: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800B3F78: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800B3F7C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800B3F80: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800B3F84:
    // 0x800B3F84: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
L_800B3F88:
    // 0x800B3F88: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
L_800B3F8C:
    // 0x800B3F8C: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B3F90: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B3F94: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3F98: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B3F9C: mflo        $t8
    ctx->r24 = lo;
    // 0x800B3FA0: addu        $t6, $t0, $t8
    ctx->r14 = ADD32(ctx->r8, ctx->r24);
    // 0x800B3FA4: lh          $t7, 0x22($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X22));
    // 0x800B3FA8: blezl       $t7, L_800B4C68
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B3FAC: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_8;
    // 0x800B3FAC: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_8:
    // 0x800B3FB0: lh          $t3, 0x2BE($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2BE));
    // 0x800B3FB4: lh          $t9, 0x72($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X72));
    // 0x800B3FB8: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800B3FBC: bltz        $t3, L_800B401C
    if (SIGNED(ctx->r11) < 0) {
        // 0x800B3FC0: sll         $t8, $t9, 2
        ctx->r24 = S32(ctx->r25 << 2);
            goto L_800B401C;
    }
    // 0x800B3FC0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800B3FC4: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x800B3FC8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B3FCC: addiu       $t6, $t6, 0x5600
    ctx->r14 = ADD32(ctx->r14, 0X5600);
    // 0x800B3FD0: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x800B3FD4: lh          $v0, 0x4($a0)
    ctx->r2 = S32(MEM_H(ctx->r4, 0X4));
    // 0x800B3FD8: blez        $v0, L_800B3FE8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B3FDC: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_800B3FE8;
    }
    // 0x800B3FDC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x800B3FE0: b           L_800B3FE8
    // 0x800B3FE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B3FE8;
    // 0x800B3FE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B3FE8:
    // 0x800B3FE8: slti        $at, $v1, 0x301
    ctx->r1 = SIGNED(ctx->r3) < 0X301 ? 1 : 0;
    // 0x800B3FEC: beq         $at, $zero, L_800B4014
    if (ctx->r1 == 0) {
        // 0x800B3FF0: nop
    
            goto L_800B4014;
    }
    // 0x800B3FF0: nop

    // 0x800B3FF4: lh          $v0, 0x2($a0)
    ctx->r2 = S32(MEM_H(ctx->r4, 0X2));
    // 0x800B3FF8: blez        $v0, L_800B4008
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B3FFC: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_800B4008;
    }
    // 0x800B3FFC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x800B4000: b           L_800B4008
    // 0x800B4004: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B4008;
    // 0x800B4004: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B4008:
    // 0x800B4008: slti        $at, $v1, 0x301
    ctx->r1 = SIGNED(ctx->r3) < 0X301 ? 1 : 0;
    // 0x800B400C: bnel        $at, $zero, L_800B4020
    if (ctx->r1 != 0) {
        // 0x800B4010: lh          $t7, 0x72($sp)
        ctx->r15 = S32(MEM_H(ctx->r29, 0X72));
            goto L_800B4020;
    }
    goto skip_9;
    // 0x800B4010: lh          $t7, 0x72($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X72));
    skip_9:
L_800B4014:
    // 0x800B4014: b           L_800B48DC
    // 0x800B4018: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_800B48DC;
    // 0x800B4018: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_800B401C:
    // 0x800B401C: lh          $t7, 0x72($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X72));
L_800B4020:
    // 0x800B4020: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x800B4024: addiu       $t8, $t8, 0x5600
    ctx->r24 = ADD32(ctx->r24, 0X5600);
    // 0x800B4028: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B402C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B4030: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B4034: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x800B4038: lw          $v0, 0x8($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X8));
    // 0x800B403C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800B4040: bltz        $t6, L_800B4058
    if (SIGNED(ctx->r14) < 0) {
        // 0x800B4044: sll         $t7, $v0, 0
        ctx->r15 = S32(ctx->r2 << 0);
            goto L_800B4058;
    }
    // 0x800B4044: sll         $t7, $v0, 0
    ctx->r15 = S32(ctx->r2 << 0);
    // 0x800B4048: bltzl       $t7, L_800B405C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B404C: lbu         $t9, 0x360($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X360);
            goto L_800B405C;
    }
    goto skip_10;
    // 0x800B404C: lbu         $t9, 0x360($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X360);
    skip_10:
    // 0x800B4050: b           L_800B4C64
    // 0x800B4054: sb          $zero, 0x360($s0)
    MEM_B(0X360, ctx->r16) = 0;
        goto L_800B4C64;
    // 0x800B4054: sb          $zero, 0x360($s0)
    MEM_B(0X360, ctx->r16) = 0;
L_800B4058:
    // 0x800B4058: lbu         $t9, 0x360($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X360);
L_800B405C:
    // 0x800B405C: sll         $t8, $v0, 0
    ctx->r24 = S32(ctx->r2 << 0);
    // 0x800B4060: bnel        $t9, $zero, L_800B4C68
    if (ctx->r25 != 0) {
        // 0x800B4064: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_11;
    // 0x800B4064: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_11:
    // 0x800B4068: bgez        $t8, L_800B4080
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B406C: lui         $at, 0x802B
        ctx->r1 = S32(0X802B << 16);
            goto L_800B4080;
    }
    // 0x800B406C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800B4070: bltzl       $t3, L_800B4C68
    if (SIGNED(ctx->r11) < 0) {
        // 0x800B4074: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_12;
    // 0x800B4074: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_12:
    // 0x800B4078: b           L_800B48DC
    // 0x800B407C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_800B48DC;
    // 0x800B407C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_800B4080:
    // 0x800B4080: sh          $t4, -0x55B8($at)
    MEM_H(-0X55B8, ctx->r1) = ctx->r12;
    // 0x800B4084: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B4088: sb          $t6, 0x360($s0)
    MEM_B(0X360, ctx->r16) = ctx->r14;
    // 0x800B408C: sh          $t4, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r12;
    // 0x800B4090: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x800B4094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4098: jal         0x800A1E44
    // 0x800B409C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    hitawall(rdram, ctx);
        goto after_4;
    // 0x800B409C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_4:
    // 0x800B40A0: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B40A4: slti        $at, $v0, 0x500
    ctx->r1 = SIGNED(ctx->r2) < 0X500 ? 1 : 0;
    // 0x800B40A8: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B40AC: beq         $at, $zero, L_800B412C
    if (ctx->r1 == 0) {
        // 0x800B40B0: addiu       $t1, $zero, 0x2C
        ctx->r9 = ADD32(0, 0X2C);
            goto L_800B412C;
    }
    // 0x800B40B0: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B40B4: lh          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
    // 0x800B40B8: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800B40BC: addiu       $t9, $t9, 0x61A8
    ctx->r25 = ADD32(ctx->r25, 0X61A8);
    // 0x800B40C0: bltz        $a0, L_800B412C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B40C4: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_800B412C;
    }
    // 0x800B40C4: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800B40C8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800B40CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B40D0: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x800B40D4: lh          $t8, 0x12($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X12));
    // 0x800B40D8: addiu       $at, $zero, 0x230
    ctx->r1 = ADD32(0, 0X230);
    // 0x800B40DC: bnel        $t8, $at, L_800B4130
    if (ctx->r24 != ctx->r1) {
        // 0x800B40E0: lh          $a0, 0x60($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
            goto L_800B4130;
    }
    goto skip_13;
    // 0x800B40E0: lh          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
    skip_13:
    // 0x800B40E4: lh          $v1, 0x14($v0)
    ctx->r3 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800B40E8: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800B40EC: blez        $v1, L_800B412C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B40F0: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_800B412C;
    }
    // 0x800B40F0: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800B40F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B40F8: lw          $t7, 0xB0C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, 0XB0C));
    // 0x800B40FC: lh          $t9, 0x72($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X72));
    // 0x800B4100: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B4104: bnel        $t7, $zero, L_800B4130
    if (ctx->r15 != 0) {
        // 0x800B4108: lh          $a0, 0x60($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
            goto L_800B4130;
    }
    goto skip_14;
    // 0x800B4108: lh          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
    skip_14:
    // 0x800B410C: lh          $t8, -0x53DC($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X53DC));
    // 0x800B4110: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x800B4114: bnel        $t9, $t8, L_800B4130
    if (ctx->r25 != ctx->r24) {
        // 0x800B4118: lh          $a0, 0x60($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
            goto L_800B4130;
    }
    goto skip_15;
    // 0x800B4118: lh          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
    skip_15:
    // 0x800B411C: jal         0x80059034
    // 0x800B4120: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_5;
    // 0x800B4120: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_5:
    // 0x800B4124: b           L_800B4C68
    // 0x800B4128: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4128: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B412C:
    // 0x800B412C: lh          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
L_800B4130:
    // 0x800B4130: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800B4134: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x800B4138: bltz        $a0, L_800B4168
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B413C: sll         $t6, $a0, 3
        ctx->r14 = S32(ctx->r4 << 3);
            goto L_800B4168;
    }
    // 0x800B413C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800B4140: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800B4144: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B4148: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800B414C: lh          $t9, 0xE($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0XE));
    // 0x800B4150: andi        $t8, $t9, 0x10
    ctx->r24 = ctx->r25 & 0X10;
    // 0x800B4154: beql        $t8, $zero, L_800B416C
    if (ctx->r24 == 0) {
        // 0x800B4158: lh          $t7, 0x2BE($s0)
        ctx->r15 = S32(MEM_H(ctx->r16, 0X2BE));
            goto L_800B416C;
    }
    goto skip_16;
    // 0x800B4158: lh          $t7, 0x2BE($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2BE));
    skip_16:
    // 0x800B415C: lh          $t6, 0x14($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800B4160: bnel        $t6, $zero, L_800B4C68
    if (ctx->r14 != 0) {
        // 0x800B4164: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_17;
    // 0x800B4164: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_17:
L_800B4168:
    // 0x800B4168: lh          $t7, 0x2BE($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2BE));
L_800B416C:
    // 0x800B416C: bltzl       $t7, L_800B41F8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B4170: lh          $t6, 0x2E0($s0)
        ctx->r14 = S32(MEM_H(ctx->r16, 0X2E0));
            goto L_800B41F8;
    }
    goto skip_18;
    // 0x800B4170: lh          $t6, 0x2E0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2E0));
    skip_18:
    // 0x800B4174: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B4178: lh          $t7, 0x284($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X284));
    // 0x800B417C: lw          $a0, 0x238($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X238));
    // 0x800B4180: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4184: lw          $a1, 0x23C($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X23C));
    // 0x800B4188: lw          $a2, 0x240($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X240));
    // 0x800B418C: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800B4190: addiu       $t9, $t9, -0x55BC
    ctx->r25 = ADD32(ctx->r25, -0X55BC);
    // 0x800B4194: mflo        $t8
    ctx->r24 = lo;
    // 0x800B4198: addu        $t6, $t0, $t8
    ctx->r14 = ADD32(ctx->r8, ctx->r24);
    // 0x800B419C: lh          $a3, 0x10($t6)
    ctx->r7 = S32(MEM_H(ctx->r14, 0X10));
    // 0x800B41A0: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B41A4: addiu       $t8, $t8, -0x55BA
    ctx->r24 = ADD32(ctx->r24, -0X55BA);
    // 0x800B41A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800B41AC: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800B41B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800B41B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800B41B8: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B41BC: addiu       $t6, $t6, -0x55B8
    ctx->r14 = ADD32(ctx->r14, -0X55B8);
    // 0x800B41C0: addiu       $t9, $zero, 0x500
    ctx->r25 = ADD32(0, 0X500);
    // 0x800B41C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B41C8: addiu       $t7, $t7, -0x55B4
    ctx->r15 = ADD32(ctx->r15, -0X55B4);
    // 0x800B41CC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800B41D0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800B41D4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800B41D8: jal         0x80094A24
    // 0x800B41DC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    neartag(rdram, ctx);
        goto after_6;
    // 0x800B41DC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_6:
    // 0x800B41E0: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B41E4: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B41E8: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B41EC: b           L_800B43C8
    // 0x800B41F0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800B43C8;
    // 0x800B41F0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B41F4: lh          $t6, 0x2E0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2E0));
L_800B41F8:
    // 0x800B41F8: lh          $t8, 0x284($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X284));
    // 0x800B41FC: lw          $a0, 0x214($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800B4200: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4204: lw          $a1, 0x218($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800B4208: lw          $a2, 0x21C($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800B420C: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B4210: addiu       $t6, $t6, -0x55BC
    ctx->r14 = ADD32(ctx->r14, -0X55BC);
    // 0x800B4214: mflo        $t7
    ctx->r15 = lo;
    // 0x800B4218: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x800B421C: lh          $a3, 0x10($t9)
    ctx->r7 = S32(MEM_H(ctx->r25, 0X10));
    // 0x800B4220: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800B4224: addiu       $t7, $t7, -0x55BA
    ctx->r15 = ADD32(ctx->r15, -0X55BA);
    // 0x800B4228: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B422C: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B4230: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800B4234: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800B4238: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800B423C: addiu       $t9, $t9, -0x55B8
    ctx->r25 = ADD32(ctx->r25, -0X55B8);
    // 0x800B4240: addiu       $t6, $zero, 0x500
    ctx->r14 = ADD32(0, 0X500);
    // 0x800B4244: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B4248: addiu       $t8, $t8, -0x55B4
    ctx->r24 = ADD32(ctx->r24, -0X55B4);
    // 0x800B424C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B4250: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800B4254: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B4258: jal         0x80094A24
    // 0x800B425C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    neartag(rdram, ctx);
        goto after_7;
    // 0x800B425C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_7:
    // 0x800B4260: lui         $a3, 0x802B
    ctx->r7 = S32(0X802B << 16);
    // 0x800B4264: lh          $a3, -0x55B8($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X55B8));
    // 0x800B4268: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B426C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B4270: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B4274: bne         $t4, $a3, L_800B4324
    if (ctx->r12 != ctx->r7) {
        // 0x800B4278: addiu       $t1, $zero, 0x2C
        ctx->r9 = ADD32(0, 0X2C);
            goto L_800B4324;
    }
    // 0x800B4278: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B427C: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800B4280: lh          $t9, -0x55BA($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X55BA));
    // 0x800B4284: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B4288: bne         $t4, $t9, L_800B4324
    if (ctx->r12 != ctx->r25) {
        // 0x800B428C: nop
    
            goto L_800B4324;
    }
    // 0x800B428C: nop

    // 0x800B4290: lh          $t8, -0x55BC($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X55BC));
    // 0x800B4294: bne         $t4, $t8, L_800B4324
    if (ctx->r12 != ctx->r24) {
        // 0x800B4298: nop
    
            goto L_800B4324;
    }
    // 0x800B4298: nop

    // 0x800B429C: lh          $t6, 0x2E0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B42A0: lw          $a2, 0x21C($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800B42A4: lh          $t8, 0x284($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X284));
    // 0x800B42A8: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B42AC: lw          $a0, 0x214($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800B42B0: lw          $a1, 0x218($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800B42B4: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B42B8: addiu       $t6, $t6, -0x55BC
    ctx->r14 = ADD32(ctx->r14, -0X55BC);
    // 0x800B42BC: addiu       $a2, $a2, 0x800
    ctx->r6 = ADD32(ctx->r6, 0X800);
    // 0x800B42C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800B42C4: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x800B42C8: lh          $a3, 0x10($t9)
    ctx->r7 = S32(MEM_H(ctx->r25, 0X10));
    // 0x800B42CC: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800B42D0: addiu       $t7, $t7, -0x55BA
    ctx->r15 = ADD32(ctx->r15, -0X55BA);
    // 0x800B42D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B42D8: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B42DC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800B42E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800B42E4: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800B42E8: addiu       $t9, $t9, -0x55B8
    ctx->r25 = ADD32(ctx->r25, -0X55B8);
    // 0x800B42EC: addiu       $t6, $zero, 0x500
    ctx->r14 = ADD32(0, 0X500);
    // 0x800B42F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B42F4: addiu       $t8, $t8, -0x55B4
    ctx->r24 = ADD32(ctx->r24, -0X55B4);
    // 0x800B42F8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B42FC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800B4300: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B4304: jal         0x80094A24
    // 0x800B4308: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    neartag(rdram, ctx);
        goto after_8;
    // 0x800B4308: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_8:
    // 0x800B430C: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B4310: lui         $a3, 0x802B
    ctx->r7 = S32(0X802B << 16);
    // 0x800B4314: lh          $a3, -0x55B8($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X55B8));
    // 0x800B4318: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B431C: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B4320: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800B4324:
    // 0x800B4324: bne         $t4, $a3, L_800B43C8
    if (ctx->r12 != ctx->r7) {
        // 0x800B4328: lui         $t9, 0x802B
        ctx->r25 = S32(0X802B << 16);
            goto L_800B43C8;
    }
    // 0x800B4328: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800B432C: lh          $t9, -0x55BA($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X55BA));
    // 0x800B4330: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B4334: bnel        $t4, $t9, L_800B43CC
    if (ctx->r12 != ctx->r25) {
        // 0x800B4338: lh          $t9, 0x2BE($s0)
        ctx->r25 = S32(MEM_H(ctx->r16, 0X2BE));
            goto L_800B43CC;
    }
    goto skip_19;
    // 0x800B4338: lh          $t9, 0x2BE($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2BE));
    skip_19:
    // 0x800B433C: lh          $t8, -0x55BC($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X55BC));
    // 0x800B4340: bnel        $t4, $t8, L_800B43CC
    if (ctx->r12 != ctx->r24) {
        // 0x800B4344: lh          $t9, 0x2BE($s0)
        ctx->r25 = S32(MEM_H(ctx->r16, 0X2BE));
            goto L_800B43CC;
    }
    goto skip_20;
    // 0x800B4344: lh          $t9, 0x2BE($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2BE));
    skip_20:
    // 0x800B4348: lh          $t6, 0x2E0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B434C: lw          $a2, 0x21C($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800B4350: lh          $t8, 0x284($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X284));
    // 0x800B4354: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4358: lw          $a0, 0x214($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800B435C: lw          $a1, 0x218($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800B4360: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B4364: addiu       $t6, $t6, -0x55BC
    ctx->r14 = ADD32(ctx->r14, -0X55BC);
    // 0x800B4368: addiu       $a2, $a2, 0x1000
    ctx->r6 = ADD32(ctx->r6, 0X1000);
    // 0x800B436C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B4370: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x800B4374: lh          $a3, 0x10($t9)
    ctx->r7 = S32(MEM_H(ctx->r25, 0X10));
    // 0x800B4378: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800B437C: addiu       $t7, $t7, -0x55BA
    ctx->r15 = ADD32(ctx->r15, -0X55BA);
    // 0x800B4380: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B4384: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B4388: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800B438C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800B4390: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800B4394: addiu       $t9, $t9, -0x55B8
    ctx->r25 = ADD32(ctx->r25, -0X55B8);
    // 0x800B4398: addiu       $t6, $zero, 0x500
    ctx->r14 = ADD32(0, 0X500);
    // 0x800B439C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B43A0: addiu       $t8, $t8, -0x55B4
    ctx->r24 = ADD32(ctx->r24, -0X55B4);
    // 0x800B43A4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B43A8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800B43AC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B43B0: jal         0x80094A24
    // 0x800B43B4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    neartag(rdram, ctx);
        goto after_9;
    // 0x800B43B4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_9:
    // 0x800B43B8: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B43BC: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B43C0: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B43C4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800B43C8:
    // 0x800B43C8: lh          $t9, 0x2BE($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2BE));
L_800B43CC:
    // 0x800B43CC: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B43D0: bne         $t4, $t9, L_800B4464
    if (ctx->r12 != ctx->r25) {
        // 0x800B43D4: nop
    
            goto L_800B4464;
    }
    // 0x800B43D4: nop

    // 0x800B43D8: lh          $t8, -0x55B8($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X55B8));
    // 0x800B43DC: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B43E0: bne         $t4, $t8, L_800B4464
    if (ctx->r12 != ctx->r24) {
        // 0x800B43E4: nop
    
            goto L_800B4464;
    }
    // 0x800B43E4: nop

    // 0x800B43E8: lh          $t6, -0x55BC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X55BC));
    // 0x800B43EC: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800B43F0: bne         $t4, $t6, L_800B4464
    if (ctx->r12 != ctx->r14) {
        // 0x800B43F4: nop
    
            goto L_800B4464;
    }
    // 0x800B43F4: nop

    // 0x800B43F8: lh          $t7, -0x55BA($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X55BA));
    // 0x800B43FC: bne         $t4, $t7, L_800B4464
    if (ctx->r12 != ctx->r15) {
        // 0x800B4400: nop
    
            goto L_800B4464;
    }
    // 0x800B4400: nop

    // 0x800B4404: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B4408: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800B440C: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4410: mflo        $t8
    ctx->r24 = lo;
    // 0x800B4414: addu        $t6, $t0, $t8
    ctx->r14 = ADD32(ctx->r8, ctx->r24);
    // 0x800B4418: lh          $t7, 0x10($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X10));
    // 0x800B441C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B4420: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B4424: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800B4428: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800B442C: jal         0x800ACD84
    // 0x800B4430: lh          $a0, -0x1970($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X1970));
    isanunderoperator(rdram, ctx);
        goto after_10;
    // 0x800B4430: lh          $a0, -0x1970($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X1970));
    after_10:
    // 0x800B4434: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B4438: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B443C: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B4440: beq         $v0, $zero, L_800B4464
    if (ctx->r2 == 0) {
        // 0x800B4444: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800B4464;
    }
    // 0x800B4444: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B4448: lh          $t8, 0x2E0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B444C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800B4450: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4454: mflo        $t6
    ctx->r14 = lo;
    // 0x800B4458: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800B445C: lh          $t9, 0x10($t7)
    ctx->r25 = S32(MEM_H(ctx->r15, 0X10));
    // 0x800B4460: sh          $t9, -0x55BC($at)
    MEM_H(-0X55BC, ctx->r1) = ctx->r25;
L_800B4464:
    // 0x800B4464: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800B4468: lh          $a2, -0x55BC($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55BC));
    // 0x800B446C: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800B4470: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800B4474: bltz        $a2, L_800B4498
    if (SIGNED(ctx->r6) < 0) {
        // 0x800B4478: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_800B4498;
    }
    // 0x800B4478: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800B447C: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x800B4480: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800B4484: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800B4488: lh          $t6, -0x1970($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X1970));
    // 0x800B448C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x800B4490: bnel        $t7, $zero, L_800B4C68
    if (ctx->r15 != 0) {
        // 0x800B4494: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_21;
    // 0x800B4494: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_21:
L_800B4498:
    // 0x800B4498: lh          $t9, -0x55B8($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X55B8));
    // 0x800B449C: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B44A0: bne         $t4, $t9, L_800B450C
    if (ctx->r12 != ctx->r25) {
        // 0x800B44A4: nop
    
            goto L_800B450C;
    }
    // 0x800B44A4: nop

    // 0x800B44A8: lh          $t8, -0x55BA($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X55BA));
    // 0x800B44AC: bne         $t4, $t8, L_800B450C
    if (ctx->r12 != ctx->r24) {
        // 0x800B44B0: nop
    
            goto L_800B450C;
    }
    // 0x800B44B0: nop

    // 0x800B44B4: lh          $t6, 0x288($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800B44B8: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800B44BC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800B44C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B44C4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B44C8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800B44CC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800B44D0: lh          $t9, -0x1970($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X1970));
    // 0x800B44D4: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800B44D8: addiu       $a1, $a1, -0x55B8
    ctx->r5 = ADD32(ctx->r5, -0X55B8);
    // 0x800B44DC: bne         $t2, $t9, L_800B450C
    if (ctx->r10 != ctx->r25) {
        // 0x800B44E0: nop
    
            goto L_800B450C;
    }
    // 0x800B44E0: nop

    // 0x800B44E4: jal         0x800A1CD4
    // 0x800B44E8: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    hitasprite(rdram, ctx);
        goto after_11;
    // 0x800B44E8: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    after_11:
    // 0x800B44EC: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B44F0: slti        $at, $v0, 0x501
    ctx->r1 = SIGNED(ctx->r2) < 0X501 ? 1 : 0;
    // 0x800B44F4: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B44F8: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B44FC: bne         $at, $zero, L_800B450C
    if (ctx->r1 != 0) {
        // 0x800B4500: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800B450C;
    }
    // 0x800B4500: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B4504: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800B4508: sh          $t4, -0x55B8($at)
    MEM_H(-0X55B8, ctx->r1) = ctx->r12;
L_800B450C:
    // 0x800B450C: lui         $a3, 0x802B
    ctx->r7 = S32(0X802B << 16);
    // 0x800B4510: lh          $a3, -0x55B8($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X55B8));
    // 0x800B4514: lh          $a0, 0x72($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X72));
    // 0x800B4518: bltz        $a3, L_800B4928
    if (SIGNED(ctx->r7) < 0) {
        // 0x800B451C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800B4928;
    }
    // 0x800B451C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800B4520: jal         0x800AF77C
    // 0x800B4524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    checkhitswitch(rdram, ctx);
        goto after_12;
    // 0x800B4524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x800B4528: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B452C: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B4530: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B4534: bne         $v0, $zero, L_800B4C64
    if (ctx->r2 != 0) {
        // 0x800B4538: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800B4C64;
    }
    // 0x800B4538: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B453C: lui         $a3, 0x802B
    ctx->r7 = S32(0X802B << 16);
    // 0x800B4540: lh          $a3, -0x55B8($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X55B8));
    // 0x800B4544: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x800B4548: addiu       $a1, $sp, 0x62
    ctx->r5 = ADD32(ctx->r29, 0X62);
    // 0x800B454C: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4550: mflo        $t8
    ctx->r24 = lo;
    // 0x800B4554: addu        $a0, $t0, $t8
    ctx->r4 = ADD32(ctx->r8, ctx->r24);
    // 0x800B4558: lh          $v1, 0xE($a0)
    ctx->r3 = S32(MEM_H(ctx->r4, 0XE));
    // 0x800B455C: beq         $v1, $at, L_800B4664
    if (ctx->r3 == ctx->r1) {
        // 0x800B4560: addiu       $at, $zero, 0x1F3
        ctx->r1 = ADD32(0, 0X1F3);
            goto L_800B4664;
    }
    // 0x800B4560: addiu       $at, $zero, 0x1F3
    ctx->r1 = ADD32(0, 0X1F3);
    // 0x800B4564: beq         $v1, $at, L_800B47F8
    if (ctx->r3 == ctx->r1) {
        // 0x800B4568: addiu       $at, $zero, 0x1F6
        ctx->r1 = ADD32(0, 0X1F6);
            goto L_800B47F8;
    }
    // 0x800B4568: addiu       $at, $zero, 0x1F6
    ctx->r1 = ADD32(0, 0X1F6);
    // 0x800B456C: beq         $v1, $at, L_800B47F8
    if (ctx->r3 == ctx->r1) {
        // 0x800B4570: addiu       $at, $zero, 0x233
        ctx->r1 = ADD32(0, 0X233);
            goto L_800B47F8;
    }
    // 0x800B4570: addiu       $at, $zero, 0x233
    ctx->r1 = ADD32(0, 0X233);
    // 0x800B4574: beq         $v1, $at, L_800B472C
    if (ctx->r3 == ctx->r1) {
        // 0x800B4578: sll         $t6, $a3, 3
        ctx->r14 = S32(ctx->r7 << 3);
            goto L_800B472C;
    }
    // 0x800B4578: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x800B457C: addiu       $at, $zero, 0x239
    ctx->r1 = ADD32(0, 0X239);
    // 0x800B4580: beq         $v1, $at, L_800B45A0
    if (ctx->r3 == ctx->r1) {
        // 0x800B4584: addiu       $at, $zero, 0x23B
        ctx->r1 = ADD32(0, 0X23B);
            goto L_800B45A0;
    }
    // 0x800B4584: addiu       $at, $zero, 0x23B
    ctx->r1 = ADD32(0, 0X23B);
    // 0x800B4588: beq         $v1, $at, L_800B45A0
    if (ctx->r3 == ctx->r1) {
        // 0x800B458C: addiu       $at, $zero, 0x42D
        ctx->r1 = ADD32(0, 0X42D);
            goto L_800B45A0;
    }
    // 0x800B458C: addiu       $at, $zero, 0x42D
    ctx->r1 = ADD32(0, 0X42D);
    // 0x800B4590: beq         $v1, $at, L_800B4794
    if (ctx->r3 == ctx->r1) {
        // 0x800B4594: addiu       $a0, $zero, 0x13
        ctx->r4 = ADD32(0, 0X13);
            goto L_800B4794;
    }
    // 0x800B4594: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x800B4598: b           L_800B492C
    // 0x800B459C: lw          $t6, 0x50($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X50));
        goto L_800B492C;
    // 0x800B459C: lw          $t6, 0x50($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X50));
L_800B45A0:
    // 0x800B45A0: lw          $t6, 0x258($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X258));
    // 0x800B45A4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x800B45A8: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x800B45AC: bne         $t6, $zero, L_800B4644
    if (ctx->r14 != 0) {
        // 0x800B45B0: nop
    
            goto L_800B4644;
    }
    // 0x800B45B0: nop

    // 0x800B45B4: jal         0x80059034
    // 0x800B45B8: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_13;
    // 0x800B45B8: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_13:
    // 0x800B45BC: lbu         $t8, 0x347($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X347);
    // 0x800B45C0: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B45C4: addiu       $t7, $zero, 0x1658
    ctx->r15 = ADD32(0, 0X1658);
    // 0x800B45C8: addiu       $t9, $zero, 0x3A
    ctx->r25 = ADD32(0, 0X3A);
    // 0x800B45CC: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B45D0: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B45D4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B45D8: sw          $t7, 0x258($s0)
    MEM_W(0X258, ctx->r16) = ctx->r15;
    // 0x800B45DC: bne         $t8, $zero, L_800B45F0
    if (ctx->r24 != 0) {
        // 0x800B45E0: sh          $t9, 0x32C($s0)
        MEM_H(0X32C, ctx->r16) = ctx->r25;
            goto L_800B45F0;
    }
    // 0x800B45E0: sh          $t9, 0x32C($s0)
    MEM_H(0X32C, ctx->r16) = ctx->r25;
    // 0x800B45E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B45E8: sb          $t6, 0x347($s0)
    MEM_B(0X347, ctx->r16) = ctx->r14;
    // 0x800B45EC: sh          $t4, 0x328($s0)
    MEM_H(0X328, ctx->r16) = ctx->r12;
L_800B45F0:
    // 0x800B45F0: lh          $t7, 0x2E0($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B45F4: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B45F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B45FC: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x800B4600: lh          $v0, 0x22($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X22));
    // 0x800B4604: slti        $at, $v0, 0x5B
    ctx->r1 = SIGNED(ctx->r2) < 0X5B ? 1 : 0;
    // 0x800B4608: beq         $at, $zero, L_800B4630
    if (ctx->r1 == 0) {
        // 0x800B460C: addiu       $t8, $v0, 0xA
        ctx->r24 = ADD32(ctx->r2, 0XA);
            goto L_800B4630;
    }
    // 0x800B460C: addiu       $t8, $v0, 0xA
    ctx->r24 = ADD32(ctx->r2, 0XA);
    // 0x800B4610: sh          $t8, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r24;
    // 0x800B4614: lh          $t6, 0x2E0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B4618: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B461C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B4620: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x800B4624: lh          $t8, 0x22($t9)
    ctx->r24 = S32(MEM_H(ctx->r25, 0X22));
    // 0x800B4628: b           L_800B4C64
    // 0x800B462C: sh          $t8, 0x28C($s0)
    MEM_H(0X28C, ctx->r16) = ctx->r24;
        goto L_800B4C64;
    // 0x800B462C: sh          $t8, 0x28C($s0)
    MEM_H(0X28C, ctx->r16) = ctx->r24;
L_800B4630:
    // 0x800B4630: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800B4634: beq         $at, $zero, L_800B4C64
    if (ctx->r1 == 0) {
        // 0x800B4638: addiu       $t6, $zero, 0x64
        ctx->r14 = ADD32(0, 0X64);
            goto L_800B4C64;
    }
    // 0x800B4638: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x800B463C: b           L_800B4C64
    // 0x800B4640: sh          $t6, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r14;
        goto L_800B4C64;
    // 0x800B4640: sh          $t6, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r14;
L_800B4644:
    // 0x800B4644: lw          $t7, 0xE5C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, 0XE5C));
    // 0x800B4648: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x800B464C: bnel        $t7, $zero, L_800B4C68
    if (ctx->r15 != 0) {
        // 0x800B4650: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_22;
    // 0x800B4650: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_22:
    // 0x800B4654: jal         0x80059034
    // 0x800B4658: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_14;
    // 0x800B4658: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_14:
    // 0x800B465C: b           L_800B4C68
    // 0x800B4660: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4660: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4664:
    // 0x800B4664: jal         0x800A1E44
    // 0x800B4668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    hitawall(rdram, ctx);
        goto after_15;
    // 0x800B4668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800B466C: lh          $v1, 0x62($sp)
    ctx->r3 = S32(MEM_H(ctx->r29, 0X62));
    // 0x800B4670: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B4674: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x800B4678: addiu       $t5, $t5, -0x5598
    ctx->r13 = ADD32(ctx->r13, -0X5598);
    // 0x800B467C: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B4680: bltz        $v1, L_800B4C64
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B4684: addiu       $t1, $zero, 0x2C
        ctx->r9 = ADD32(0, 0X2C);
            goto L_800B4C64;
    }
    // 0x800B4684: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B4688: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800B468C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x800B4690: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B4694: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800B4698: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800B469C: lh          $t8, 0x61BA($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X61BA));
    // 0x800B46A0: lui         $a3, 0x802B
    ctx->r7 = S32(0X802B << 16);
    // 0x800B46A4: bnel        $t8, $zero, L_800B4C68
    if (ctx->r24 != 0) {
        // 0x800B46A8: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_23;
    // 0x800B46A8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_23:
    // 0x800B46AC: lh          $a3, -0x55B8($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X55B8));
    // 0x800B46B0: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800B46B4: addiu       $t7, $t7, -0x5C00
    ctx->r15 = ADD32(ctx->r15, -0X5C00);
    // 0x800B46B8: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x800B46BC: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x800B46C0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800B46C4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800B46C8: lw          $t9, 0x30($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X30));
    // 0x800B46CC: bnel        $t9, $zero, L_800B4C68
    if (ctx->r25 != 0) {
        // 0x800B46D0: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_24;
    // 0x800B46D0: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_24:
    // 0x800B46D4: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B46D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B46DC: sw          $t8, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r24;
    // 0x800B46E0: lh          $t7, 0x2E0($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B46E4: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B46E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800B46EC: addu        $a0, $t0, $t6
    ctx->r4 = ADD32(ctx->r8, ctx->r14);
    // 0x800B46F0: lbu         $t9, 0x25($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X25);
    // 0x800B46F4: sh          $t7, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r15;
    // 0x800B46F8: sb          $t9, 0x340($s0)
    MEM_B(0X340, ctx->r16) = ctx->r25;
    // 0x800B46FC: lh          $t8, -0x55B8($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X55B8));
    // 0x800B4700: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4704: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B4708: mflo        $t6
    ctx->r14 = lo;
    // 0x800B470C: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800B4710: lbu         $t9, 0x25($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X25);
    // 0x800B4714: beq         $t9, $zero, L_800B4724
    if (ctx->r25 == 0) {
        // 0x800B4718: nop
    
            goto L_800B4724;
    }
    // 0x800B4718: nop

    // 0x800B471C: b           L_800B4C64
    // 0x800B4720: sh          $t8, 0xF2($t5)
    MEM_H(0XF2, ctx->r13) = ctx->r24;
        goto L_800B4C64;
    // 0x800B4720: sh          $t8, 0xF2($t5)
    MEM_H(0XF2, ctx->r13) = ctx->r24;
L_800B4724:
    // 0x800B4724: b           L_800B4C64
    // 0x800B4728: sh          $zero, 0xF2($t5)
    MEM_H(0XF2, ctx->r13) = 0;
        goto L_800B4C64;
    // 0x800B4728: sh          $zero, 0xF2($t5)
    MEM_H(0XF2, ctx->r13) = 0;
L_800B472C:
    // 0x800B472C: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x800B4730: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800B4734: addiu       $t7, $t7, -0x5C00
    ctx->r15 = ADD32(ctx->r15, -0X5C00);
    // 0x800B4738: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800B473C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800B4740: lw          $t9, 0x30($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X30));
    // 0x800B4744: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B4748: beql        $a2, $t9, L_800B4C68
    if (ctx->r6 == ctx->r25) {
        // 0x800B474C: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_25;
    // 0x800B474C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_25:
    // 0x800B4750: sw          $a2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r6;
    // 0x800B4754: lh          $t8, 0x2E0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B4758: sh          $t8, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r24;
    // 0x800B475C: lh          $t6, 0x2E0($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B4760: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800B4764: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4768: mflo        $t7
    ctx->r15 = lo;
    // 0x800B476C: addu        $v1, $t0, $t7
    ctx->r3 = ADD32(ctx->r8, ctx->r15);
    // 0x800B4770: lh          $v0, 0x22($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X22));
    // 0x800B4774: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800B4778: beq         $at, $zero, L_800B4C64
    if (ctx->r1 == 0) {
        // 0x800B477C: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_800B4C64;
    }
    // 0x800B477C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800B4780: sh          $t9, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r25;
    // 0x800B4784: jal         0x80059034
    // 0x800B4788: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_16;
    // 0x800B4788: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_16:
    // 0x800B478C: b           L_800B4C68
    // 0x800B4790: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4790: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4794:
    // 0x800B4794: jal         0x80059034
    // 0x800B4798: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_17;
    // 0x800B4798: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_17:
    // 0x800B479C: jal         0x8009800C
    // 0x800B47A0: nop

    krand2(rdram, ctx);
        goto after_18;
    // 0x800B47A0: nop

    after_18:
    // 0x800B47A4: lh          $t8, 0x2E0($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B47A8: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B47AC: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B47B0: multu       $t8, $t1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B47B4: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B47B8: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x800B47BC: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800B47C0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B47C4: mflo        $t6
    ctx->r14 = lo;
    // 0x800B47C8: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x800B47CC: lh          $t7, 0x22($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X22));
    // 0x800B47D0: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x800B47D4: addiu       $t6, $t8, -0x2
    ctx->r14 = ADD32(ctx->r24, -0X2);
    // 0x800B47D8: sh          $t6, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r14;
    // 0x800B47DC: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800B47E0: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800B47E4: sb          $a0, 0x367($s0)
    MEM_B(0X367, ctx->r16) = ctx->r4;
    // 0x800B47E8: sb          $a0, 0x368($s0)
    MEM_B(0X368, ctx->r16) = ctx->r4;
    // 0x800B47EC: sb          $t7, 0x369($s0)
    MEM_B(0X369, ctx->r16) = ctx->r15;
    // 0x800B47F0: b           L_800B4928
    // 0x800B47F4: sw          $t9, 0x274($s0)
    MEM_W(0X274, ctx->r16) = ctx->r25;
        goto L_800B4928;
    // 0x800B47F4: sw          $t9, 0x274($s0)
    MEM_W(0X274, ctx->r16) = ctx->r25;
L_800B47F8:
    // 0x800B47F8: lh          $t3, 0x2BE($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2BE));
    // 0x800B47FC: bne         $t4, $t3, L_800B4814
    if (ctx->r12 != ctx->r11) {
        // 0x800B4800: lui         $v1, 0x8027
        ctx->r3 = S32(0X8027 << 16);
            goto L_800B4814;
    }
    // 0x800B4800: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800B4804: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x800B4808: addiu       $a1, $a1, 0x5F40
    ctx->r5 = ADD32(ctx->r5, 0X5F40);
    // 0x800B480C: b           L_800B4828
    // 0x800B4810: lh          $v1, 0x285A($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X285A));
        goto L_800B4828;
    // 0x800B4810: lh          $v1, 0x285A($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X285A));
L_800B4814:
    // 0x800B4814: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x800B4818: addiu       $a1, $a1, 0x5F40
    ctx->r5 = ADD32(ctx->r5, 0X5F40);
    // 0x800B481C: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800B4820: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x800B4824: lh          $v1, 0x0($t6)
    ctx->r3 = S32(MEM_H(ctx->r14, 0X0));
L_800B4828:
    // 0x800B4828: bltz        $v1, L_800B48DC
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B482C: addiu       $v0, $zero, 0x26D
        ctx->r2 = ADD32(0, 0X26D);
            goto L_800B48DC;
    }
    // 0x800B482C: addiu       $v0, $zero, 0x26D
    ctx->r2 = ADD32(0, 0X26D);
L_800B4830:
    // 0x800B4830: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4834: mflo        $t7
    ctx->r15 = lo;
    // 0x800B4838: addu        $a2, $t0, $t7
    ctx->r6 = ADD32(ctx->r8, ctx->r15);
    // 0x800B483C: lh          $t9, 0xE($a2)
    ctx->r25 = S32(MEM_H(ctx->r6, 0XE));
    // 0x800B4840: bnel        $v0, $t9, L_800B48CC
    if (ctx->r2 != ctx->r25) {
        // 0x800B4844: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_800B48CC;
    }
    goto skip_26;
    // 0x800B4844: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    skip_26:
    // 0x800B4848: lh          $t8, 0x20($a0)
    ctx->r24 = S32(MEM_H(ctx->r4, 0X20));
    // 0x800B484C: lh          $t6, 0x1E($a2)
    ctx->r14 = S32(MEM_H(ctx->r6, 0X1E));
    // 0x800B4850: bnel        $t8, $t6, L_800B48CC
    if (ctx->r24 != ctx->r14) {
        // 0x800B4854: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_800B48CC;
    }
    goto skip_27;
    // 0x800B4854: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    skip_27:
    // 0x800B4858: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x800B485C: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B4860: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B4864: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    // 0x800B4868: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x800B486C: jal         0x80059034
    // 0x800B4870: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    spritesound(rdram, ctx);
        goto after_19;
    // 0x800B4870: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_19:
    // 0x800B4874: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x800B4878: lh          $t9, -0x55B8($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X55B8));
    // 0x800B487C: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B4880: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B4884: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4888: lw          $v1, 0x6C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X6C));
    // 0x800B488C: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B4890: lw          $a2, 0x50($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800B4894: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B4898: mflo        $t8
    ctx->r24 = lo;
    // 0x800B489C: addu        $a0, $t0, $t8
    ctx->r4 = ADD32(ctx->r8, ctx->r24);
    // 0x800B48A0: sh          $t6, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r14;
    // 0x800B48A4: sh          $v1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r3;
    // 0x800B48A8: lh          $t7, 0x288($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800B48AC: lh          $t9, 0x10($a2)
    ctx->r25 = S32(MEM_H(ctx->r6, 0X10));
    // 0x800B48B0: sh          $t7, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r15;
    // 0x800B48B4: sh          $t9, 0x288($s0)
    MEM_H(0X288, ctx->r16) = ctx->r25;
    // 0x800B48B8: lh          $t8, 0x62($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X62));
    // 0x800B48BC: sh          $v1, 0x2BE($s0)
    MEM_H(0X2BE, ctx->r16) = ctx->r3;
    // 0x800B48C0: b           L_800B4C64
    // 0x800B48C4: sh          $t8, 0x288($s0)
    MEM_H(0X288, ctx->r16) = ctx->r24;
        goto L_800B4C64;
    // 0x800B48C4: sh          $t8, 0x288($s0)
    MEM_H(0X288, ctx->r16) = ctx->r24;
    // 0x800B48C8: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
L_800B48CC:
    // 0x800B48CC: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800B48D0: lh          $v1, 0x0($t7)
    ctx->r3 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800B48D4: bgez        $v1, L_800B4830
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B48D8: nop
    
            goto L_800B4830;
    }
    // 0x800B48D8: nop

L_800B48DC:
    // 0x800B48DC: bgez        $v1, L_800B4918
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B48E0: nop
    
            goto L_800B4918;
    }
    // 0x800B48E0: nop

    // 0x800B48E4: lw          $a0, 0x238($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X238));
    // 0x800B48E8: lw          $a1, 0x23C($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X23C));
    // 0x800B48EC: lw          $t9, 0x240($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X240));
    // 0x800B48F0: lh          $t8, 0x284($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X284));
    // 0x800B48F4: sh          $t4, 0x2BE($s0)
    MEM_H(0X2BE, ctx->r16) = ctx->r12;
    // 0x800B48F8: addiu       $a2, $s0, 0x288
    ctx->r6 = ADD32(ctx->r16, 0X288);
    // 0x800B48FC: sw          $a0, 0x214($s0)
    MEM_W(0X214, ctx->r16) = ctx->r4;
    // 0x800B4900: sw          $a1, 0x218($s0)
    MEM_W(0X218, ctx->r16) = ctx->r5;
    // 0x800B4904: sw          $t9, 0x21C($s0)
    MEM_W(0X21C, ctx->r16) = ctx->r25;
    // 0x800B4908: jal         0x80097DB8
    // 0x800B490C: sh          $t8, 0x282($s0)
    MEM_H(0X282, ctx->r16) = ctx->r24;
    updatesector(rdram, ctx);
        goto after_20;
    // 0x800B490C: sh          $t8, 0x282($s0)
    MEM_H(0X282, ctx->r16) = ctx->r24;
    after_20:
    // 0x800B4910: b           L_800B4C68
    // 0x800B4914: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4914: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4918:
    // 0x800B4918: bltzl       $t3, L_800B4C68
    if (SIGNED(ctx->r11) < 0) {
        // 0x800B491C: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_28;
    // 0x800B491C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_28:
    // 0x800B4920: b           L_800B4C64
    // 0x800B4924: sh          $t4, 0x2BE($s0)
    MEM_H(0X2BE, ctx->r16) = ctx->r12;
        goto L_800B4C64;
    // 0x800B4924: sh          $t4, 0x2BE($s0)
    MEM_H(0X2BE, ctx->r16) = ctx->r12;
L_800B4928:
    // 0x800B4928: lw          $t6, 0x50($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X50));
L_800B492C:
    // 0x800B492C: lw          $t7, 0x8($t6)
    ctx->r15 = S32(MEM_W(ctx->r14, 0X8));
    // 0x800B4930: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B4934: bgezl       $t9, L_800B4C68
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B4938: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_29;
    // 0x800B4938: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_29:
    // 0x800B493C: lh          $t3, 0x2BE($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2BE));
    // 0x800B4940: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x800B4944: bltz        $t3, L_800B4954
    if (SIGNED(ctx->r11) < 0) {
        // 0x800B4948: nop
    
            goto L_800B4954;
    }
    // 0x800B4948: nop

    // 0x800B494C: b           L_800B48DC
    // 0x800B4950: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_800B48DC;
    // 0x800B4950: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_800B4954:
    // 0x800B4954: lh          $t8, -0x55BA($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X55BA));
    // 0x800B4958: lui         $t6, 0x802B
    ctx->r14 = S32(0X802B << 16);
    // 0x800B495C: bne         $t4, $t8, L_800B4A14
    if (ctx->r12 != ctx->r24) {
        // 0x800B4960: nop
    
            goto L_800B4A14;
    }
    // 0x800B4960: nop

    // 0x800B4964: lh          $t6, -0x55BC($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X55BC));
    // 0x800B4968: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x800B496C: bne         $t4, $t6, L_800B4A14
    if (ctx->r12 != ctx->r14) {
        // 0x800B4970: nop
    
            goto L_800B4A14;
    }
    // 0x800B4970: nop

    // 0x800B4974: lh          $t7, -0x55B8($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X55B8));
    // 0x800B4978: bne         $t4, $t7, L_800B4A14
    if (ctx->r12 != ctx->r15) {
        // 0x800B497C: nop
    
            goto L_800B4A14;
    }
    // 0x800B497C: nop

    // 0x800B4980: jal         0x800A1BC4
    // 0x800B4984: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    hits(rdram, ctx);
        goto after_21;
    // 0x800B4984: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    after_21:
    // 0x800B4988: blez        $v0, L_800B49B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B498C: nop
    
            goto L_800B49B0;
    }
    // 0x800B498C: nop

    // 0x800B4990: jal         0x800A1BC4
    // 0x800B4994: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    hits(rdram, ctx);
        goto after_22;
    // 0x800B4994: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    after_22:
    // 0x800B4998: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B499C: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B49A0: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B49A4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B49A8: b           L_800B49CC
    // 0x800B49AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800B49CC;
    // 0x800B49AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800B49B0:
    // 0x800B49B0: jal         0x800A1BC4
    // 0x800B49B4: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    hits(rdram, ctx);
        goto after_23;
    // 0x800B49B4: lh          $a0, 0x2E0($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X2E0));
    after_23:
    // 0x800B49B8: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B49BC: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B49C0: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B49C4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B49C8: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_800B49CC:
    // 0x800B49CC: slti        $at, $v1, 0x200
    ctx->r1 = SIGNED(ctx->r3) < 0X200 ? 1 : 0;
    // 0x800B49D0: beq         $at, $zero, L_800B4A14
    if (ctx->r1 == 0) {
        // 0x800B49D4: nop
    
            goto L_800B4A14;
    }
    // 0x800B49D4: nop

    // 0x800B49D8: jal         0x8009800C
    // 0x800B49DC: nop

    krand2(rdram, ctx);
        goto after_24;
    // 0x800B49DC: nop

    after_24:
    // 0x800B49E0: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x800B49E4: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800B49E8: beq         $at, $zero, L_800B4A04
    if (ctx->r1 == 0) {
        // 0x800B49EC: addiu       $a0, $zero, 0xA6
        ctx->r4 = ADD32(0, 0XA6);
            goto L_800B4A04;
    }
    // 0x800B49EC: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    // 0x800B49F0: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    // 0x800B49F4: jal         0x80059034
    // 0x800B49F8: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_25;
    // 0x800B49F8: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_25:
    // 0x800B49FC: b           L_800B4C68
    // 0x800B4A00: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4A00: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4A04:
    // 0x800B4A04: jal         0x80059034
    // 0x800B4A08: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_26;
    // 0x800B4A08: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_26:
    // 0x800B4A0C: b           L_800B4C68
    // 0x800B4A10: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4A10: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4A14:
    // 0x800B4A14: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800B4A18: lh          $a1, -0x55BA($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X55BA));
    // 0x800B4A1C: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800B4A20: addiu       $t6, $t6, 0x61A8
    ctx->r14 = ADD32(ctx->r14, 0X61A8);
    // 0x800B4A24: bltz        $a1, L_800B4AA4
    if (SIGNED(ctx->r5) < 0) {
        // 0x800B4A28: sll         $t8, $a1, 3
        ctx->r24 = S32(ctx->r5 << 3);
            goto L_800B4AA4;
    }
    // 0x800B4A28: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x800B4A2C: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800B4A30: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B4A34: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800B4A38: lh          $t7, 0x14($v0)
    ctx->r15 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800B4A3C: blezl       $t7, L_800B4A94
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B4A40: lh          $t3, 0x2BE($s0)
        ctx->r11 = S32(MEM_H(ctx->r16, 0X2BE));
            goto L_800B4A94;
    }
    goto skip_30;
    // 0x800B4A40: lh          $t3, 0x2BE($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2BE));
    skip_30:
    // 0x800B4A44: jal         0x800ACC8C
    // 0x800B4A48: lh          $a0, 0x10($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0X10));
    isadoorwall(rdram, ctx);
        goto after_27;
    // 0x800B4A48: lh          $a0, 0x10($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0X10));
    after_27:
    // 0x800B4A4C: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B4A50: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B4A54: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B4A58: beq         $v0, $zero, L_800B4A90
    if (ctx->r2 == 0) {
        // 0x800B4A5C: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800B4A90;
    }
    // 0x800B4A5C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B4A60: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800B4A64: lh          $a0, 0x60($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X60));
    // 0x800B4A68: lh          $a1, -0x55BA($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X55BA));
    // 0x800B4A6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B4A70: beq         $a0, $a1, L_800B4A80
    if (ctx->r4 == ctx->r5) {
        // 0x800B4A74: nop
    
            goto L_800B4A80;
    }
    // 0x800B4A74: nop

    // 0x800B4A78: bnel        $a0, $t4, L_800B4C68
    if (ctx->r4 != ctx->r12) {
        // 0x800B4A7C: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_31;
    // 0x800B4A7C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_31:
L_800B4A80:
    // 0x800B4A80: jal         0x800AF77C
    // 0x800B4A84: lh          $a0, 0x72($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X72));
    checkhitswitch(rdram, ctx);
        goto after_28;
    // 0x800B4A84: lh          $a0, 0x72($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X72));
    after_28:
    // 0x800B4A88: b           L_800B4C68
    // 0x800B4A8C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4A8C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4A90:
    // 0x800B4A90: lh          $t3, 0x2BE($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2BE));
L_800B4A94:
    // 0x800B4A94: bltz        $t3, L_800B4AA4
    if (SIGNED(ctx->r11) < 0) {
        // 0x800B4A98: nop
    
            goto L_800B4AA4;
    }
    // 0x800B4A98: nop

    // 0x800B4A9C: b           L_800B48DC
    // 0x800B4AA0: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_800B48DC;
    // 0x800B4AA0: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_800B4AA4:
    // 0x800B4AA4: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800B4AA8: lh          $a2, -0x55BC($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55BC));
    // 0x800B4AAC: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800B4AB0: bltz        $a2, L_800B4B6C
    if (SIGNED(ctx->r6) < 0) {
        // 0x800B4AB4: sll         $t9, $a2, 2
        ctx->r25 = S32(ctx->r6 << 2);
            goto L_800B4B6C;
    }
    // 0x800B4AB4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800B4AB8: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x800B4ABC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800B4AC0: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800B4AC4: lh          $a0, -0x1970($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X1970));
    // 0x800B4AC8: andi        $t8, $a0, 0x4000
    ctx->r24 = ctx->r4 & 0X4000;
    // 0x800B4ACC: bnel        $t8, $zero, L_800B4B70
    if (ctx->r24 != 0) {
        // 0x800B4AD0: lh          $t9, 0x2E0($s0)
        ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
            goto L_800B4B70;
    }
    goto skip_32;
    // 0x800B4AD0: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
    skip_32:
    // 0x800B4AD4: jal         0x800ACDC4
    // 0x800B4AD8: nop

    isanearoperator(rdram, ctx);
        goto after_29;
    // 0x800B4AD8: nop

    after_29:
    // 0x800B4ADC: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B4AE0: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B4AE4: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B4AE8: beq         $v0, $zero, L_800B4B6C
    if (ctx->r2 == 0) {
        // 0x800B4AEC: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800B4B6C;
    }
    // 0x800B4AEC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800B4AF0: lui         $a2, 0x802B
    ctx->r6 = S32(0X802B << 16);
    // 0x800B4AF4: lh          $a2, -0x55BC($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, -0X55BC));
    // 0x800B4AF8: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800B4AFC: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x800B4B00: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x800B4B04: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800B4B08: lh          $v1, 0x2330($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X2330));
    // 0x800B4B0C: addiu       $a1, $a1, 0x4FA0
    ctx->r5 = ADD32(ctx->r5, 0X4FA0);
    // 0x800B4B10: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800B4B14: bltzl       $v1, L_800B4B54
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B4B18: sll         $a0, $a2, 16
        ctx->r4 = S32(ctx->r6 << 16);
            goto L_800B4B54;
    }
    goto skip_33;
    // 0x800B4B18: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
    skip_33:
L_800B4B1C:
    // 0x800B4B1C: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4B20: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800B4B24: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x800B4B28: mflo        $t7
    ctx->r15 = lo;
    // 0x800B4B2C: addu        $t9, $t0, $t7
    ctx->r25 = ADD32(ctx->r8, ctx->r15);
    // 0x800B4B30: lh          $v0, 0xE($t9)
    ctx->r2 = S32(MEM_H(ctx->r25, 0XE));
    // 0x800B4B34: beql        $t2, $v0, L_800B4C68
    if (ctx->r10 == ctx->r2) {
        // 0x800B4B38: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_34;
    // 0x800B4B38: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_34:
    // 0x800B4B3C: beql        $a0, $v0, L_800B4C68
    if (ctx->r4 == ctx->r2) {
        // 0x800B4B40: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_35;
    // 0x800B4B40: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_35:
    // 0x800B4B44: lh          $v1, 0x0($t6)
    ctx->r3 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800B4B48: bgez        $v1, L_800B4B1C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B4B4C: nop
    
            goto L_800B4B1C;
    }
    // 0x800B4B4C: nop

    // 0x800B4B50: sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6 << 16);
L_800B4B54:
    // 0x800B4B54: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B4B58: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B4B5C: jal         0x800ADBFC
    // 0x800B4B60: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    operatesectors(rdram, ctx);
        goto after_30;
    // 0x800B4B60: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_30:
    // 0x800B4B64: b           L_800B4C68
    // 0x800B4B68: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4B68: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4B6C:
    // 0x800B4B6C: lh          $t9, 0x2E0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2E0));
L_800B4B70:
    // 0x800B4B70: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800B4B74: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4B78: mflo        $t8
    ctx->r24 = lo;
    // 0x800B4B7C: addu        $t6, $t0, $t8
    ctx->r14 = ADD32(ctx->r8, ctx->r24);
    // 0x800B4B80: lh          $t7, 0x10($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X10));
    // 0x800B4B84: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800B4B88: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800B4B8C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800B4B90: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800B4B94: lh          $a0, -0x1970($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X1970));
    // 0x800B4B98: andi        $t8, $a0, 0x4000
    ctx->r24 = ctx->r4 & 0X4000;
    // 0x800B4B9C: bnel        $t8, $zero, L_800B4C68
    if (ctx->r24 != 0) {
        // 0x800B4BA0: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_36;
    // 0x800B4BA0: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_36:
    // 0x800B4BA4: jal         0x800ACD84
    // 0x800B4BA8: nop

    isanunderoperator(rdram, ctx);
        goto after_31;
    // 0x800B4BA8: nop

    after_31:
    // 0x800B4BAC: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x800B4BB0: addiu       $t0, $t0, 0x6BA8
    ctx->r8 = ADD32(ctx->r8, 0X6BA8);
    // 0x800B4BB4: addiu       $t1, $zero, 0x2C
    ctx->r9 = ADD32(0, 0X2C);
    // 0x800B4BB8: beq         $v0, $zero, L_800B4C50
    if (ctx->r2 == 0) {
        // 0x800B4BBC: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800B4C50;
    }
    // 0x800B4BBC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800B4BC0: lh          $a2, 0x2E0($s0)
    ctx->r6 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B4BC4: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800B4BC8: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x800B4BCC: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4BD0: addiu       $a1, $a1, 0x4FA0
    ctx->r5 = ADD32(ctx->r5, 0X4FA0);
    // 0x800B4BD4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800B4BD8: mflo        $t6
    ctx->r14 = lo;
    // 0x800B4BDC: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800B4BE0: lh          $a3, 0x10($t7)
    ctx->r7 = S32(MEM_H(ctx->r15, 0X10));
    // 0x800B4BE4: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800B4BE8: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x800B4BEC: lh          $v1, 0x2330($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X2330));
    // 0x800B4BF0: bltzl       $v1, L_800B4C30
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B4BF4: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_800B4C30;
    }
    goto skip_37;
    // 0x800B4BF4: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    skip_37:
L_800B4BF8:
    // 0x800B4BF8: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4BFC: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800B4C00: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800B4C04: mflo        $t8
    ctx->r24 = lo;
    // 0x800B4C08: addu        $t6, $t0, $t8
    ctx->r14 = ADD32(ctx->r8, ctx->r24);
    // 0x800B4C0C: lh          $v0, 0xE($t6)
    ctx->r2 = S32(MEM_H(ctx->r14, 0XE));
    // 0x800B4C10: beql        $t2, $v0, L_800B4C68
    if (ctx->r10 == ctx->r2) {
        // 0x800B4C14: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_38;
    // 0x800B4C14: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_38:
    // 0x800B4C18: beql        $a0, $v0, L_800B4C68
    if (ctx->r4 == ctx->r2) {
        // 0x800B4C1C: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800B4C68;
    }
    goto skip_39;
    // 0x800B4C1C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_39:
    // 0x800B4C20: lh          $v1, 0x0($t9)
    ctx->r3 = S32(MEM_H(ctx->r25, 0X0));
    // 0x800B4C24: bgez        $v1, L_800B4BF8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B4C28: nop
    
            goto L_800B4BF8;
    }
    // 0x800B4C28: nop

    // 0x800B4C2C: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
L_800B4C30:
    // 0x800B4C30: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800B4C34: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B4C38: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B4C3C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800B4C40: jal         0x800ADBFC
    // 0x800B4C44: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    operatesectors(rdram, ctx);
        goto after_32;
    // 0x800B4C44: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_32:
    // 0x800B4C48: b           L_800B4C68
    // 0x800B4C4C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
        goto L_800B4C68;
    // 0x800B4C4C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4C50:
    // 0x800B4C50: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800B4C54: lh          $a1, -0x55BA($a1)
    ctx->r5 = S32(MEM_H(ctx->r5, -0X55BA));
    // 0x800B4C58: lh          $a0, 0x72($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X72));
    // 0x800B4C5C: jal         0x800AF77C
    // 0x800B4C60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    checkhitswitch(rdram, ctx);
        goto after_33;
    // 0x800B4C60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_33:
L_800B4C64:
    // 0x800B4C64: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800B4C68:
    // 0x800B4C68: lw          $s0, 0x38($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800B4C6C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800B4C70: jr          $ra
    // 0x800B4C74: nop

    return;
    // 0x800B4C74: nop

;}
RECOMP_FUNC void func_8004ECF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004ECF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004ECF4: lwc1        $f0, -0x6B2C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004ECF8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8004ECFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004ED00: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x8004ED04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004ED08: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004ED0C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8004ED10: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8004ED14: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004ED18: addiu       $t6, $zero, -0x63
    ctx->r14 = ADD32(0, -0X63);
    // 0x8004ED1C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8004ED20: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8004ED24: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8004ED28: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8004ED2C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8004ED30: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8004ED34: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8004ED38: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004ED3C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8004ED40: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8004ED44: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8004ED48: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8004ED4C: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8004ED50: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004ED54: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8004ED58: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004ED5C: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x8004ED60: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8004ED64: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004ED68: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8004ED6C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8004ED70: sh          $t7, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r15;
    // 0x8004ED74: sh          $t6, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r14;
    // 0x8004ED78: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x8004ED7C: sra         $a2, $t3, 16
    ctx->r6 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004ED80: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8004ED84: jal         0x8006E994
    // 0x8004ED88: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    setrotatespriteflags(rdram, ctx);
        goto after_0;
    // 0x8004ED88: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_0:
    // 0x8004ED8C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004ED90: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8004ED94: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8004ED98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8004ED9C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004EDA0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004EDA4: addiu       $t5, $zero, 0xE56
    ctx->r13 = ADD32(0, 0XE56);
    // 0x8004EDA8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8004EDAC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8004EDB0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004EDB4: jal         0x8005D13C
    // 0x8004EDB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    rotatesprite(rdram, ctx);
        goto after_1;
    // 0x8004EDB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8004EDBC: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x8004EDC0: lw          $v0, -0x540C($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X540C));
    // 0x8004EDC4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8004EDC8: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x8004EDCC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8004EDD0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8004EDD4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8004EDD8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8004EDDC: addiu       $v0, $t6, 0x37
    ctx->r2 = ADD32(ctx->r14, 0X37);
    // 0x8004EDE0: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8004EDE4: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004EDE8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004EDEC: subu        $v0, $t9, $t8
    ctx->r2 = SUB32(ctx->r25, ctx->r24);
    // 0x8004EDF0: bgez        $v0, L_8004EE00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004EDF4: sra         $t0, $v0, 1
        ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8004EE00;
    }
    // 0x8004EDF4: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8004EDF8: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8004EDFC: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8004EE00:
    // 0x8004EE00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004EE04: lwc1        $f0, -0x6B2C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004EE08: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8004EE0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004EE10: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8004EE14: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8004EE18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004EE1C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004EE20: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    // 0x8004EE24: sh          $t2, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r10;
    // 0x8004EE28: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004EE2C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8004EE30: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004EE34: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8004EE38: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8004EE3C: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x8004EE40: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004EE44: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8004EE48: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004EE4C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8004EE50: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8004EE54: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004EE58: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8004EE5C: jal         0x8006E994
    // 0x8004EE60: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    setrotatespriteflags(rdram, ctx);
        goto after_2;
    // 0x8004EE60: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    after_2:
    // 0x8004EE64: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8004EE68: addiu       $a2, $a2, 0x2ABC
    ctx->r6 = ADD32(ctx->r6, 0X2ABC);
    // 0x8004EE6C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8004EE70: jal         0x8006413C
    // 0x8004EE74: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    menutext(rdram, ctx);
        goto after_3;
    // 0x8004EE74: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_3:
    // 0x8004EE78: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8004EE7C: lh          $t2, 0x3750($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X3750));
    // 0x8004EE80: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8004EE84: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8004EE88: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8004EE8C: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x8004EE90: lw          $a2, 0x3790($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, 0X3790));
    // 0x8004EE94: jal         0x8006413C
    // 0x8004EE98: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    menutext(rdram, ctx);
        goto after_4;
    // 0x8004EE98: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_4:
    // 0x8004EE9C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8004EEA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004EEA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004EEA8: lwc1        $f10, -0x6B2C($at)
    ctx->f10.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004EEAC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004EEB0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004EEB4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004EEB8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8004EEBC: nop

    // 0x8004EEC0: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8004EEC4: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004EEC8: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8004EECC: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8004EED0: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004EED4: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004EED8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8004EEDC: jal         0x8006E994
    // 0x8004EEE0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_5;
    // 0x8004EEE0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_5:
    // 0x8004EEE4: lh          $a0, 0x86($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004EEE8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8004EEEC: addiu       $a2, $a2, 0x2AD0
    ctx->r6 = ADD32(ctx->r6, 0X2AD0);
    // 0x8004EEF0: addiu       $a0, $a0, -0x2D
    ctx->r4 = ADD32(ctx->r4, -0X2D);
    // 0x8004EEF4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8004EEF8: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004EEFC: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x8004EF00: jal         0x80063F68
    // 0x8004EF04: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    gametext(rdram, ctx);
        goto after_6;
    // 0x8004EF04: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_6:
    // 0x8004EF08: lui         $t1, 0x802B
    ctx->r9 = S32(0X802B << 16);
    // 0x8004EF0C: lw          $t1, -0x540C($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, -0X540C));
    // 0x8004EF10: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8004EF14: addiu       $s7, $sp, 0x94
    ctx->r23 = ADD32(ctx->r29, 0X94);
    // 0x8004EF18: blez        $t1, L_8004F40C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8004EF1C: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8004F40C;
    }
    // 0x8004EF1C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_8004EF20:
    // 0x8004EF20: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
    // 0x8004EF24: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    // 0x8004EF28: addiu       $s2, $zero, 0xC8
    ctx->r18 = ADD32(0, 0XC8);
    // 0x8004EF2C: beq         $s4, $zero, L_8004EF58
    if (ctx->r20 == 0) {
        // 0x8004EF30: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8004EF58;
    }
    // 0x8004EF30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004EF34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004EF38: beq         $s4, $at, L_8004EF60
    if (ctx->r20 == ctx->r1) {
        // 0x8004EF3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004EF60;
    }
    // 0x8004EF3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004EF40: beq         $s4, $at, L_8004EF6C
    if (ctx->r20 == ctx->r1) {
        // 0x8004EF44: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004EF6C;
    }
    // 0x8004EF44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004EF48: beql        $s4, $at, L_8004EF78
    if (ctx->r20 == ctx->r1) {
        // 0x8004EF4C: addiu       $s2, $zero, 0x40
        ctx->r18 = ADD32(0, 0X40);
            goto L_8004EF78;
    }
    goto skip_0;
    // 0x8004EF4C: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
    skip_0:
    // 0x8004EF50: b           L_8004EF7C
    // 0x8004EF54: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
        goto L_8004EF7C;
    // 0x8004EF54: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_8004EF58:
    // 0x8004EF58: b           L_8004EF78
    // 0x8004EF5C: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
        goto L_8004EF78;
    // 0x8004EF5C: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
L_8004EF60:
    // 0x8004EF60: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x8004EF64: b           L_8004EF78
    // 0x8004EF68: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
        goto L_8004EF78;
    // 0x8004EF68: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
L_8004EF6C:
    // 0x8004EF6C: b           L_8004EF78
    // 0x8004EF70: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
        goto L_8004EF78;
    // 0x8004EF70: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x8004EF74: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
L_8004EF78:
    // 0x8004EF78: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_8004EF7C:
    // 0x8004EF7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004EF80: lwc1        $f0, -0x6B2C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004EF84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004EF88: mtc1        $s5, $f16
    ctx->f16.u32l = ctx->r21;
    // 0x8004EF8C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004EF90: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004EF94: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004EF98: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8004EF9C: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x8004EFA0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004EFA4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8004EFA8: nop

    // 0x8004EFAC: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8004EFB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004EFB4: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004EFB8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8004EFBC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004EFC0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004EFC4: nop

    // 0x8004EFC8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8004EFCC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004EFD0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004EFD4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8004EFD8: nop

    // 0x8004EFDC: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8004EFE0: jal         0x8006E994
    // 0x8004EFE4: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    setrotatespriteflags(rdram, ctx);
        goto after_7;
    // 0x8004EFE4: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    after_7:
    // 0x8004EFE8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8004EFEC: addiu       $a2, $s4, 0x1
    ctx->r6 = ADD32(ctx->r20, 0X1);
    // 0x8004EFF0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8004EFF4: addiu       $a1, $a1, 0x2AD8
    ctx->r5 = ADD32(ctx->r5, 0X2AD8);
    // 0x8004EFF8: jal         0x800BD9E4
    // 0x8004EFFC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8004EFFC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_8:
    // 0x8004F000: sll         $fp, $s4, 4
    ctx->r30 = S32(ctx->r20 << 4);
    // 0x8004F004: addu        $fp, $fp, $s4
    ctx->r30 = ADD32(ctx->r30, ctx->r20);
    // 0x8004F008: addiu       $fp, $fp, 0x5A
    ctx->r30 = ADD32(ctx->r30, 0X5A);
    // 0x8004F00C: sll         $t1, $fp, 16
    ctx->r9 = S32(ctx->r30 << 16);
    // 0x8004F010: sra         $fp, $t1, 16
    ctx->r30 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8004F014: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x8004F018: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F01C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8004F020: lh          $a0, 0x86($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004F024: jal         0x80063F68
    // 0x8004F028: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    gametext(rdram, ctx);
        goto after_9;
    // 0x8004F028: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_9:
    // 0x8004F02C: lui         $t4, 0x802B
    ctx->r12 = S32(0X802B << 16);
    // 0x8004F030: lw          $t4, -0x540C($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X540C));
    // 0x8004F034: blezl       $t4, L_8004F2B0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8004F038: lui         $at, 0x4300
        ctx->r1 = S32(0X4300 << 16);
            goto L_8004F2B0;
    }
    goto skip_1;
    // 0x8004F038: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    skip_1:
L_8004F03C:
    // 0x8004F03C: bne         $s4, $zero, L_8004F148
    if (ctx->r20 != 0) {
        // 0x8004F040: addiu       $s0, $zero, 0xC8
        ctx->r16 = ADD32(0, 0XC8);
            goto L_8004F148;
    }
    // 0x8004F040: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
    // 0x8004F044: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    // 0x8004F048: beq         $s1, $zero, L_8004F074
    if (ctx->r17 == 0) {
        // 0x8004F04C: addiu       $s2, $zero, 0xC8
        ctx->r18 = ADD32(0, 0XC8);
            goto L_8004F074;
    }
    // 0x8004F04C: addiu       $s2, $zero, 0xC8
    ctx->r18 = ADD32(0, 0XC8);
    // 0x8004F050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F054: beq         $s1, $at, L_8004F07C
    if (ctx->r17 == ctx->r1) {
        // 0x8004F058: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004F07C;
    }
    // 0x8004F058: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004F05C: beq         $s1, $at, L_8004F088
    if (ctx->r17 == ctx->r1) {
        // 0x8004F060: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004F088;
    }
    // 0x8004F060: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004F064: beql        $s1, $at, L_8004F094
    if (ctx->r17 == ctx->r1) {
        // 0x8004F068: addiu       $s2, $zero, 0x40
        ctx->r18 = ADD32(0, 0X40);
            goto L_8004F094;
    }
    goto skip_2;
    // 0x8004F068: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
    skip_2:
    // 0x8004F06C: b           L_8004F098
    // 0x8004F070: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
        goto L_8004F098;
    // 0x8004F070: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_8004F074:
    // 0x8004F074: b           L_8004F094
    // 0x8004F078: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
        goto L_8004F094;
    // 0x8004F078: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
L_8004F07C:
    // 0x8004F07C: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x8004F080: b           L_8004F094
    // 0x8004F084: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
        goto L_8004F094;
    // 0x8004F084: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
L_8004F088:
    // 0x8004F088: b           L_8004F094
    // 0x8004F08C: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
        goto L_8004F094;
    // 0x8004F08C: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x8004F090: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
L_8004F094:
    // 0x8004F094: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_8004F098:
    // 0x8004F098: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F09C: lwc1        $f0, -0x6B2C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F0A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004F0A4: mtc1        $s5, $f16
    ctx->f16.u32l = ctx->r21;
    // 0x8004F0A8: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F0AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8004F0B0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004F0B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8004F0B8: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x8004F0BC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004F0C0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8004F0C4: nop

    // 0x8004F0C8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004F0CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004F0D0: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004F0D4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8004F0D8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004F0DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8004F0E0: nop

    // 0x8004F0E4: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8004F0E8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004F0EC: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004F0F0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8004F0F4: nop

    // 0x8004F0F8: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x8004F0FC: jal         0x8006E994
    // 0x8004F100: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    setrotatespriteflags(rdram, ctx);
        goto after_10;
    // 0x8004F100: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    after_10:
    // 0x8004F104: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8004F108: addiu       $a1, $a1, 0x2ADC
    ctx->r5 = ADD32(ctx->r5, 0X2ADC);
    // 0x8004F10C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004F110: jal         0x800BD9E4
    // 0x8004F114: addiu       $a2, $s1, 0x1
    ctx->r6 = ADD32(ctx->r17, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x8004F114: addiu       $a2, $s1, 0x1
    ctx->r6 = ADD32(ctx->r17, 0X1);
    after_11:
    // 0x8004F118: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8004F11C: lh          $t4, 0x86($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004F120: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x8004F124: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8004F128: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8004F12C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x8004F130: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8004F134: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004F138: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004F13C: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    // 0x8004F140: jal         0x80063F68
    // 0x8004F144: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    gametext(rdram, ctx);
        goto after_12;
    // 0x8004F144: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
L_8004F148:
    // 0x8004F148: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x8004F14C: lh          $t8, 0x86($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004F150: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x8004F154: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004F158: addu        $t9, $t9, $s1
    ctx->r25 = ADD32(ctx->r25, ctx->r17);
    // 0x8004F15C: addu        $s3, $t8, $t9
    ctx->r19 = ADD32(ctx->r24, ctx->r25);
    // 0x8004F160: addiu       $s3, $s3, 0x14
    ctx->r19 = ADD32(ctx->r19, 0X14);
    // 0x8004F164: sll         $t0, $s3, 16
    ctx->r8 = S32(ctx->r19 << 16);
    // 0x8004F168: sra         $s3, $t0, 16
    ctx->r19 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004F16C: bne         $s1, $s4, L_8004F1F4
    if (ctx->r17 != ctx->r20) {
        // 0x8004F170: addiu       $s2, $s1, 0x1
        ctx->r18 = ADD32(ctx->r17, 0X1);
            goto L_8004F1F4;
    }
    // 0x8004F170: addiu       $s2, $s1, 0x1
    ctx->r18 = ADD32(ctx->r17, 0X1);
    // 0x8004F174: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F178: lwc1        $f0, -0x6B2C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F17C: sll         $t9, $s4, 3
    ctx->r25 = S32(ctx->r20 << 3);
    // 0x8004F180: subu        $t9, $t9, $s4
    ctx->r25 = SUB32(ctx->r25, ctx->r20);
    // 0x8004F184: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8004F188: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004F18C: addu        $t9, $t9, $s4
    ctx->r25 = ADD32(ctx->r25, ctx->r20);
    // 0x8004F190: mul.s       $f8, $f22, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8004F194: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004F198: subu        $t9, $t9, $s4
    ctx->r25 = SUB32(ctx->r25, ctx->r20);
    // 0x8004F19C: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x8004F1A0: addiu       $t0, $t0, 0x5770
    ctx->r8 = ADD32(ctx->r8, 0X5770);
    // 0x8004F1A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004F1A8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8004F1AC: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x8004F1B0: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F1B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8004F1B8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8004F1BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004F1C0: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8004F1C4: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004F1C8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8004F1CC: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004F1D0: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x8004F1D4: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004F1D8: jal         0x8006E994
    // 0x8004F1DC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_13;
    // 0x8004F1DC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_13:
    // 0x8004F1E0: lh          $s5, 0x2B0($s0)
    ctx->r21 = S32(MEM_H(ctx->r16, 0X2B0));
    // 0x8004F1E4: subu        $s6, $s6, $s5
    ctx->r22 = SUB32(ctx->r22, ctx->r21);
    // 0x8004F1E8: sll         $t1, $s6, 16
    ctx->r9 = S32(ctx->r22 << 16);
    // 0x8004F1EC: b           L_8004F25C
    // 0x8004F1F0: sra         $s6, $t1, 16
    ctx->r22 = S32(SIGNED(ctx->r9) >> 16);
        goto L_8004F25C;
    // 0x8004F1F0: sra         $s6, $t1, 16
    ctx->r22 = S32(SIGNED(ctx->r9) >> 16);
L_8004F1F4:
    // 0x8004F1F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F1F8: lwc1        $f16, -0x6B2C($at)
    ctx->f16.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F1FC: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x8004F200: addiu       $t9, $t9, -0x6A60
    ctx->r25 = ADD32(ctx->r25, -0X6A60);
    // 0x8004F204: mul.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8004F208: sll         $t8, $s4, 3
    ctx->r24 = S32(ctx->r20 << 3);
    // 0x8004F20C: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8004F210: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F214: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8004F218: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8004F21C: nop

    // 0x8004F220: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x8004F224: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004F228: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8004F22C: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8004F230: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004F234: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F238: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8004F23C: jal         0x8006E994
    // 0x8004F240: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_14;
    // 0x8004F240: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_14:
    // 0x8004F244: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
    // 0x8004F248: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x8004F24C: lh          $s5, 0x0($t1)
    ctx->r21 = S32(MEM_H(ctx->r9, 0X0));
    // 0x8004F250: addu        $s6, $s6, $s5
    ctx->r22 = ADD32(ctx->r22, ctx->r21);
    // 0x8004F254: sll         $t2, $s6, 16
    ctx->r10 = S32(ctx->r22 << 16);
    // 0x8004F258: sra         $s6, $t2, 16
    ctx->r22 = S32(SIGNED(ctx->r10) >> 16);
L_8004F25C:
    // 0x8004F25C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8004F260: addiu       $a1, $a1, 0x2AE0
    ctx->r5 = ADD32(ctx->r5, 0X2AE0);
    // 0x8004F264: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004F268: jal         0x800BD9E4
    // 0x8004F26C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_15;
    // 0x8004F26C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_15:
    // 0x8004F270: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8004F274: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x8004F278: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F27C: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004F280: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8004F284: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8004F288: jal         0x80063F68
    // 0x8004F28C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    gametext(rdram, ctx);
        goto after_16;
    // 0x8004F28C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_16:
    // 0x8004F290: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x8004F294: lw          $t7, -0x540C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X540C));
    // 0x8004F298: sll         $s1, $s2, 16
    ctx->r17 = S32(ctx->r18 << 16);
    // 0x8004F29C: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8004F2A0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004F2A4: bne         $at, $zero, L_8004F03C
    if (ctx->r1 != 0) {
        // 0x8004F2A8: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_8004F03C;
    }
    // 0x8004F2A8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8004F2AC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
L_8004F2B0:
    // 0x8004F2B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F2B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F2B8: lwc1        $f8, -0x6B2C($at)
    ctx->f8.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F2BC: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F2C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004F2C4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8004F2C8: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8004F2CC: nop

    // 0x8004F2D0: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8004F2D4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004F2D8: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8004F2DC: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8004F2E0: sra         $t2, $a2, 16
    ctx->r10 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004F2E4: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F2E8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8004F2EC: jal         0x8006E994
    // 0x8004F2F0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_17;
    // 0x8004F2F0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_17:
    // 0x8004F2F4: bne         $s4, $zero, L_8004F32C
    if (ctx->r20 != 0) {
        // 0x8004F2F8: sll         $t4, $s1, 2
        ctx->r12 = S32(ctx->r17 << 2);
            goto L_8004F32C;
    }
    // 0x8004F2F8: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8004F2FC: lh          $t3, 0x86($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004F300: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x8004F304: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8004F308: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x8004F30C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8004F310: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    // 0x8004F314: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8004F318: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8004F31C: addiu       $a2, $a2, 0x2AE4
    ctx->r6 = ADD32(ctx->r6, 0X2AE4);
    // 0x8004F320: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004F324: jal         0x80063F68
    // 0x8004F328: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    gametext(rdram, ctx);
        goto after_18;
    // 0x8004F328: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_18:
L_8004F32C:
    // 0x8004F32C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8004F330: lh          $t7, 0x86($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004F334: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8004F338: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004F33C: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8004F340: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x8004F344: addiu       $s0, $s0, 0x1E
    ctx->r16 = ADD32(ctx->r16, 0X1E);
    // 0x8004F348: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x8004F34C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8004F350: addiu       $a1, $a1, 0x2AE8
    ctx->r5 = ADD32(ctx->r5, 0X2AE8);
    // 0x8004F354: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004F358: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004F35C: jal         0x800BD9E4
    // 0x8004F360: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_19;
    // 0x8004F360: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_19:
    // 0x8004F364: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8004F368: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x8004F36C: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F370: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004F374: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8004F378: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8004F37C: jal         0x80063F68
    // 0x8004F380: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    gametext(rdram, ctx);
        goto after_20;
    // 0x8004F380: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_20:
    // 0x8004F384: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004F388: lbu         $t3, 0x378C($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X378C);
    // 0x8004F38C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004F390: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x8004F394: bne         $t3, $at, L_8004F3D0
    if (ctx->r11 != ctx->r1) {
        // 0x8004F398: sll         $t4, $s4, 3
        ctx->r12 = S32(ctx->r20 << 3);
            goto L_8004F3D0;
    }
    // 0x8004F398: sll         $t4, $s4, 3
    ctx->r12 = S32(ctx->r20 << 3);
    // 0x8004F39C: subu        $t4, $t4, $s4
    ctx->r12 = SUB32(ctx->r12, ctx->r20);
    // 0x8004F3A0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8004F3A4: addu        $t4, $t4, $s4
    ctx->r12 = ADD32(ctx->r12, ctx->r20);
    // 0x8004F3A8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8004F3AC: subu        $t4, $t4, $s4
    ctx->r12 = SUB32(ctx->r12, ctx->r20);
    // 0x8004F3B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8004F3B4: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x8004F3B8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8004F3BC: lh          $t5, 0x59FC($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X59FC));
    // 0x8004F3C0: blezl       $t5, L_8004F3FC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004F3C4: lh          $s4, 0x72($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X72));
            goto L_8004F3FC;
    }
    goto skip_3;
    // 0x8004F3C4: lh          $s4, 0x72($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X72));
    skip_3:
    // 0x8004F3C8: b           L_8004F3F8
    // 0x8004F3CC: sh          $s4, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r20;
        goto L_8004F3F8;
    // 0x8004F3CC: sh          $s4, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r20;
L_8004F3D0:
    // 0x8004F3D0: lh          $v0, 0x92($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0X92));
    // 0x8004F3D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004F3D8: bne         $s6, $v0, L_8004F3E4
    if (ctx->r22 != ctx->r2) {
        // 0x8004F3DC: slt         $at, $v0, $s6
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8004F3E4;
    }
    // 0x8004F3DC: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8004F3E0: sh          $t6, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r14;
L_8004F3E4:
    // 0x8004F3E4: beql        $at, $zero, L_8004F3FC
    if (ctx->r1 == 0) {
        // 0x8004F3E8: lh          $s4, 0x72($sp)
        ctx->r20 = S32(MEM_H(ctx->r29, 0X72));
            goto L_8004F3FC;
    }
    goto skip_4;
    // 0x8004F3E8: lh          $s4, 0x72($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X72));
    skip_4:
    // 0x8004F3EC: sh          $s6, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r22;
    // 0x8004F3F0: sh          $s4, 0x90($sp)
    MEM_H(0X90, ctx->r29) = ctx->r20;
    // 0x8004F3F4: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
L_8004F3F8:
    // 0x8004F3F8: lh          $s4, 0x72($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X72));
L_8004F3FC:
    // 0x8004F3FC: lw          $t7, -0x540C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X540C));
    // 0x8004F400: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004F404: bnel        $at, $zero, L_8004EF20
    if (ctx->r1 != 0) {
        // 0x8004F408: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8004EF20;
    }
    goto skip_5;
    // 0x8004F408: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    skip_5:
L_8004F40C:
    // 0x8004F40C: lh          $t8, 0x90($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X90));
    // 0x8004F410: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004F414: addiu       $s7, $sp, 0x94
    ctx->r23 = ADD32(ctx->r29, 0X94);
    // 0x8004F418: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
    // 0x8004F41C: addiu       $s5, $zero, 0xC8
    ctx->r21 = ADD32(0, 0XC8);
    // 0x8004F420: addiu       $s2, $zero, 0xC8
    ctx->r18 = ADD32(0, 0XC8);
    // 0x8004F424: bne         $t8, $at, L_8004F434
    if (ctx->r24 != ctx->r1) {
        // 0x8004F428: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8004F434;
    }
    // 0x8004F428: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8004F42C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004F430: sh          $t9, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r25;
L_8004F434:
    // 0x8004F434: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8004F438: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004F43C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F440: lwc1        $f4, -0x6B2C($at)
    ctx->f4.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F444: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F448: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004F44C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8004F450: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8004F454: nop

    // 0x8004F458: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x8004F45C: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8004F460: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8004F464: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8004F468: sra         $t4, $a2, 16
    ctx->r12 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004F46C: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F470: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8004F474: jal         0x8006E994
    // 0x8004F478: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_21;
    // 0x8004F478: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_21:
    // 0x8004F47C: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x8004F480: lw          $a1, -0x540C($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X540C));
    // 0x8004F484: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8004F488: addiu       $a2, $a2, 0x2AEC
    ctx->r6 = ADD32(ctx->r6, 0X2AEC);
    // 0x8004F48C: sll         $t5, $a1, 4
    ctx->r13 = S32(ctx->r5 << 4);
    // 0x8004F490: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x8004F494: addiu       $a1, $t5, 0x5A
    ctx->r5 = ADD32(ctx->r13, 0X5A);
    // 0x8004F498: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x8004F49C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004F4A0: jal         0x80063F68
    // 0x8004F4A4: lh          $a0, 0x76($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X76));
    gametext(rdram, ctx);
        goto after_22;
    // 0x8004F4A4: lh          $a0, 0x76($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X76));
    after_22:
    // 0x8004F4A8: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x8004F4AC: lw          $v0, -0x540C($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X540C));
    // 0x8004F4B0: blez        $v0, L_8004F5B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F4B4: lui         $s6, 0x8010
        ctx->r22 = S32(0X8010 << 16);
            goto L_8004F5B0;
    }
    // 0x8004F4B4: lui         $s6, 0x8010
    ctx->r22 = S32(0X8010 << 16);
    // 0x8004F4B8: lui         $s3, 0x802B
    ctx->r19 = S32(0X802B << 16);
    // 0x8004F4BC: addiu       $s3, $s3, -0x6A60
    ctx->r19 = ADD32(ctx->r19, -0X6A60);
    // 0x8004F4C0: addiu       $s6, $s6, 0x2AF4
    ctx->r22 = ADD32(ctx->r22, 0X2AF4);
    // 0x8004F4C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8004F4C8:
    // 0x8004F4C8: blez        $v0, L_8004F538
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004F4CC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8004F538;
    }
    // 0x8004F4CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8004F4D0: lui         $v1, 0x802A
    ctx->r3 = S32(0X802A << 16);
    // 0x8004F4D4: addiu       $v1, $v1, 0x5770
    ctx->r3 = ADD32(ctx->r3, 0X5770);
    // 0x8004F4D8: addiu       $a0, $zero, 0x38C
    ctx->r4 = ADD32(0, 0X38C);
L_8004F4DC:
    // 0x8004F4DC: bne         $s1, $s4, L_8004F504
    if (ctx->r17 != ctx->r20) {
        // 0x8004F4E0: sll         $t3, $s4, 3
        ctx->r11 = S32(ctx->r20 << 3);
            goto L_8004F504;
    }
    // 0x8004F4E0: sll         $t3, $s4, 3
    ctx->r11 = S32(ctx->r20 << 3);
    // 0x8004F4E4: multu       $s1, $a0
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004F4E8: mflo        $t8
    ctx->r24 = lo;
    // 0x8004F4EC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8004F4F0: lh          $t0, 0x2B0($t9)
    ctx->r8 = S32(MEM_H(ctx->r25, 0X2B0));
    // 0x8004F4F4: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8004F4F8: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x8004F4FC: b           L_8004F520
    // 0x8004F500: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
        goto L_8004F520;
    // 0x8004F500: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
L_8004F504:
    // 0x8004F504: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x8004F508: sll         $t5, $s1, 1
    ctx->r13 = S32(ctx->r17 << 1);
    // 0x8004F50C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8004F510: lh          $t7, 0x0($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X0));
    // 0x8004F514: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8004F518: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8004F51C: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
L_8004F520:
    // 0x8004F520: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8004F524: sll         $t0, $s4, 16
    ctx->r8 = S32(ctx->r20 << 16);
    // 0x8004F528: sra         $s4, $t0, 16
    ctx->r20 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004F52C: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004F530: bne         $at, $zero, L_8004F4DC
    if (ctx->r1 != 0) {
        // 0x8004F534: nop
    
            goto L_8004F4DC;
    }
    // 0x8004F534: nop

L_8004F538:
    // 0x8004F538: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004F53C: jal         0x800BD9E4
    // 0x8004F540: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x8004F540: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_23:
    // 0x8004F544: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x8004F548: lw          $a1, -0x540C($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X540C));
    // 0x8004F54C: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8004F550: lh          $t2, 0x86($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004F554: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x8004F558: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004F55C: addu        $t3, $t3, $s1
    ctx->r11 = ADD32(ctx->r11, ctx->r17);
    // 0x8004F560: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8004F564: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8004F568: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8004F56C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x8004F570: addiu       $a1, $t6, 0x5A
    ctx->r5 = ADD32(ctx->r14, 0X5A);
    // 0x8004F574: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8004F578: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x8004F57C: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004F580: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004F584: jal         0x80063F68
    // 0x8004F588: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    gametext(rdram, ctx);
        goto after_24;
    // 0x8004F588: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_24:
    // 0x8004F58C: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x8004F590: lw          $v0, -0x540C($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X540C));
    // 0x8004F594: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004F598: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8004F59C: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004F5A0: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004F5A4: bnel        $at, $zero, L_8004F4C8
    if (ctx->r1 != 0) {
        // 0x8004F5A8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8004F4C8;
    }
    goto skip_6;
    // 0x8004F5A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    skip_6:
    // 0x8004F5AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8004F5B0:
    // 0x8004F5B0: lh          $t1, 0x90($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0X90));
    // 0x8004F5B4: lh          $t2, 0x8E($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0X8E));
    // 0x8004F5B8: beq         $t1, $zero, L_8004F5E0
    if (ctx->r9 == 0) {
        // 0x8004F5BC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8004F5E0;
    }
    // 0x8004F5BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004F5C0: beq         $t1, $at, L_8004F5E8
    if (ctx->r9 == ctx->r1) {
        // 0x8004F5C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004F5E8;
    }
    // 0x8004F5C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004F5C8: beq         $t1, $at, L_8004F5F4
    if (ctx->r9 == ctx->r1) {
        // 0x8004F5CC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004F5F4;
    }
    // 0x8004F5CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004F5D0: beql        $t1, $at, L_8004F600
    if (ctx->r9 == ctx->r1) {
        // 0x8004F5D4: addiu       $s2, $zero, 0x40
        ctx->r18 = ADD32(0, 0X40);
            goto L_8004F600;
    }
    goto skip_7;
    // 0x8004F5D4: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
    skip_7:
    // 0x8004F5D8: b           L_8004F600
    // 0x8004F5DC: nop

        goto L_8004F600;
    // 0x8004F5DC: nop

L_8004F5E0:
    // 0x8004F5E0: b           L_8004F600
    // 0x8004F5E4: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
        goto L_8004F600;
    // 0x8004F5E4: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
L_8004F5E8:
    // 0x8004F5E8: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x8004F5EC: b           L_8004F600
    // 0x8004F5F0: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
        goto L_8004F600;
    // 0x8004F5F0: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
L_8004F5F4:
    // 0x8004F5F4: b           L_8004F600
    // 0x8004F5F8: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
        goto L_8004F600;
    // 0x8004F5F8: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x8004F5FC: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
L_8004F600:
    // 0x8004F600: beq         $t2, $zero, L_8004F664
    if (ctx->r10 == 0) {
        // 0x8004F604: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_8004F664;
    }
    // 0x8004F604: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8004F608: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004F60C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F610: lwc1        $f16, -0x6B2C($at)
    ctx->f16.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F614: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F618: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8004F61C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8004F620: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8004F624: nop

    // 0x8004F628: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x8004F62C: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004F630: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8004F634: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8004F638: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004F63C: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F640: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8004F644: jal         0x8006E994
    // 0x8004F648: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_25;
    // 0x8004F648: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_25:
    // 0x8004F64C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8004F650: addiu       $a1, $a1, 0x2AF8
    ctx->r5 = ADD32(ctx->r5, 0X2AF8);
    // 0x8004F654: jal         0x800BD9E4
    // 0x8004F658: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_26;
    // 0x8004F658: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_26:
    // 0x8004F65C: b           L_8004F718
    // 0x8004F660: nop

        goto L_8004F718;
    // 0x8004F660: nop

L_8004F664:
    // 0x8004F664: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x8004F668: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F66C: lwc1        $f0, -0x6B2C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F670: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004F674: mtc1        $s5, $f18
    ctx->f18.u32l = ctx->r21;
    // 0x8004F678: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F67C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8004F680: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004F684: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8004F688: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x8004F68C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004F690: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8004F694: nop

    // 0x8004F698: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8004F69C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004F6A0: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004F6A4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8004F6A8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004F6AC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004F6B0: nop

    // 0x8004F6B4: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x8004F6B8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8004F6BC: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8004F6C0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8004F6C4: nop

    // 0x8004F6C8: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x8004F6CC: jal         0x8006E994
    // 0x8004F6D0: sra         $a2, $t5, 16
    ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
    setrotatespriteflags(rdram, ctx);
        goto after_27;
    // 0x8004F6D0: sra         $a2, $t5, 16
    ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
    after_27:
    // 0x8004F6D4: lh          $a2, 0x90($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X90));
    // 0x8004F6D8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8004F6DC: addiu       $a1, $a1, 0x2B00
    ctx->r5 = ADD32(ctx->r5, 0X2B00);
    // 0x8004F6E0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004F6E4: jal         0x800BD9E4
    // 0x8004F6E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_28;
    // 0x8004F6E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_28:
    // 0x8004F6EC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8004F6F0: lh          $t7, 0x3778($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X3778));
    // 0x8004F6F4: lh          $t8, 0x90($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X90));
    // 0x8004F6F8: bne         $t7, $zero, L_8004F718
    if (ctx->r15 != 0) {
        // 0x8004F6FC: sll         $t9, $t8, 1
        ctx->r25 = S32(ctx->r24 << 1);
            goto L_8004F718;
    }
    // 0x8004F6FC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8004F700: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8004F704: addiu       $s2, $s2, -0x6B28
    ctx->r18 = ADD32(ctx->r18, -0X6B28);
    // 0x8004F708: addu        $v0, $s2, $t9
    ctx->r2 = ADD32(ctx->r18, ctx->r25);
    // 0x8004F70C: lh          $t0, 0x0($v0)
    ctx->r8 = S32(MEM_H(ctx->r2, 0X0));
    // 0x8004F710: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8004F714: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_8004F718:
    // 0x8004F718: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8004F71C: addiu       $s2, $s2, -0x6B28
    ctx->r18 = ADD32(ctx->r18, -0X6B28);
    // 0x8004F720: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8004F724: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x8004F728: jal         0x8006413C
    // 0x8004F72C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    menutext(rdram, ctx);
        goto after_29;
    // 0x8004F72C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_29:
    // 0x8004F730: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004F734: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F738: sh          $t2, 0x3778($at)
    MEM_H(0X3778, ctx->r1) = ctx->r10;
    // 0x8004F73C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F740: lwc1        $f0, -0x6B2C($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F744: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8004F748: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004F74C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8004F750: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004F754: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004F758: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F75C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004F760: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8004F764: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8004F768: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8004F76C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8004F770: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x8004F774: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004F778: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8004F77C: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F780: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8004F784: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004F788: jal         0x8006E994
    // 0x8004F78C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_30;
    // 0x8004F78C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_30:
    // 0x8004F790: lui         $t1, 0x802B
    ctx->r9 = S32(0X802B << 16);
    // 0x8004F794: lw          $t1, -0x540C($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, -0X540C));
    // 0x8004F798: lh          $t0, 0x86($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004F79C: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8004F7A0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004F7A4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8004F7A8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8004F7AC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8004F7B0: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    // 0x8004F7B4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8004F7B8: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8004F7BC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004F7C0: addiu       $a2, $a2, 0x2B10
    ctx->r6 = ADD32(ctx->r6, 0X2B10);
    // 0x8004F7C4: jal         0x80063F68
    // 0x8004F7C8: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    gametext(rdram, ctx);
        goto after_31;
    // 0x8004F7C8: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_31:
    // 0x8004F7CC: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x8004F7D0: lw          $t5, -0x540C($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, -0X540C));
    // 0x8004F7D4: blez        $t5, L_8004F860
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004F7D8: lui         $s0, 0x8010
        ctx->r16 = S32(0X8010 << 16);
            goto L_8004F860;
    }
    // 0x8004F7D8: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8004F7DC: addiu       $s0, $s0, 0x2B18
    ctx->r16 = ADD32(ctx->r16, 0X2B18);
    // 0x8004F7E0: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
L_8004F7E4:
    // 0x8004F7E4: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8004F7E8: lh          $a2, 0x0($t7)
    ctx->r6 = S32(MEM_H(ctx->r15, 0X0));
    // 0x8004F7EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8004F7F0: jal         0x800BD9E4
    // 0x8004F7F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_32;
    // 0x8004F7F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_32:
    // 0x8004F7F8: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x8004F7FC: lw          $t9, -0x540C($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X540C));
    // 0x8004F800: lh          $t8, 0x86($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X86));
    // 0x8004F804: sll         $a1, $s1, 4
    ctx->r5 = S32(ctx->r17 << 4);
    // 0x8004F808: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8004F80C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8004F810: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8004F814: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8004F818: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x8004F81C: addu        $a0, $t8, $t1
    ctx->r4 = ADD32(ctx->r24, ctx->r9);
    // 0x8004F820: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8004F824: addiu       $a1, $a1, 0x56
    ctx->r5 = ADD32(ctx->r5, 0X56);
    // 0x8004F828: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x8004F82C: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x8004F830: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004F834: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004F838: jal         0x8006413C
    // 0x8004F83C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    menutext(rdram, ctx);
        goto after_33;
    // 0x8004F83C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_33:
    // 0x8004F840: lui         $t7, 0x802B
    ctx->r15 = S32(0X802B << 16);
    // 0x8004F844: lw          $t7, -0x540C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X540C));
    // 0x8004F848: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004F84C: sll         $t5, $s1, 16
    ctx->r13 = S32(ctx->r17 << 16);
    // 0x8004F850: sra         $s1, $t5, 16
    ctx->r17 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004F854: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004F858: bnel        $at, $zero, L_8004F7E4
    if (ctx->r1 != 0) {
        // 0x8004F85C: sll         $t6, $s1, 1
        ctx->r14 = S32(ctx->r17 << 1);
            goto L_8004F7E4;
    }
    goto skip_8;
    // 0x8004F85C: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    skip_8:
L_8004F860:
    // 0x8004F860: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x8004F864: lw          $t9, -0x5370($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X5370));
    // 0x8004F868: lui         $s5, 0x8010
    ctx->r21 = S32(0X8010 << 16);
    // 0x8004F86C: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8004F870: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x8004F874: andi        $t1, $t8, 0x7FF
    ctx->r9 = ctx->r24 & 0X7FF;
    // 0x8004F878: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x8004F87C: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x8004F880: lh          $s5, -0x9A0($s5)
    ctx->r21 = S32(MEM_H(ctx->r21, -0X9A0));
    // 0x8004F884: bgez        $s5, L_8004F894
    if (SIGNED(ctx->r21) >= 0) {
        // 0x8004F888: sra         $t2, $s5, 8
        ctx->r10 = S32(SIGNED(ctx->r21) >> 8);
            goto L_8004F894;
    }
    // 0x8004F888: sra         $t2, $s5, 8
    ctx->r10 = S32(SIGNED(ctx->r21) >> 8);
    // 0x8004F88C: addiu       $at, $s5, 0xFF
    ctx->r1 = ADD32(ctx->r21, 0XFF);
    // 0x8004F890: sra         $t2, $at, 8
    ctx->r10 = S32(SIGNED(ctx->r1) >> 8);
L_8004F894:
    // 0x8004F894: addiu       $s5, $t2, 0xC0
    ctx->r21 = ADD32(ctx->r10, 0XC0);
    // 0x8004F898: sll         $t3, $s5, 16
    ctx->r11 = S32(ctx->r21 << 16);
    // 0x8004F89C: sra         $s5, $t3, 16
    ctx->r21 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004F8A0: mtc1        $s5, $f6
    ctx->f6.u32l = ctx->r21;
    // 0x8004F8A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004F8A8: lwc1        $f10, -0x6B2C($at)
    ctx->f10.u32l = S32(MEM_W(ctx->r1, -0X6B2C));
    // 0x8004F8AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004F8B0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004F8B4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8004F8B8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8004F8BC: nop

    // 0x8004F8C0: sll         $a0, $t7, 16
    ctx->r4 = S32(ctx->r15 << 16);
    // 0x8004F8C4: sll         $a1, $t7, 16
    ctx->r5 = S32(ctx->r15 << 16);
    // 0x8004F8C8: sll         $a2, $t7, 16
    ctx->r6 = S32(ctx->r15 << 16);
    // 0x8004F8CC: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8004F8D0: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004F8D4: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004F8D8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8004F8DC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8004F8E0: jal         0x8006E994
    // 0x8004F8E4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    setrotatespriteflags(rdram, ctx);
        goto after_34;
    // 0x8004F8E4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_34:
    // 0x8004F8E8: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8004F8EC: addiu       $a2, $a2, 0x2B1C
    ctx->r6 = ADD32(ctx->r6, 0X2B1C);
    // 0x8004F8F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8004F8F4: jal         0x80063F68
    // 0x8004F8F8: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    gametext(rdram, ctx);
        goto after_35;
    // 0x8004F8F8: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    after_35:
    // 0x8004F8FC: jal         0x8004DCB8
    // 0x8004F900: nop

    func_8004DCB8(rdram, ctx);
        goto after_36;
    // 0x8004F900: nop

    after_36:
    // 0x8004F904: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8004F908: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8004F90C: addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // 0x8004F910: lw          $a2, 0x3790($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, 0X3790));
    // 0x8004F914: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8004F918: jal         0x8006413C
    // 0x8004F91C: addiu       $a1, $zero, 0xCD
    ctx->r5 = ADD32(0, 0XCD);
    menutext(rdram, ctx);
        goto after_37;
    // 0x8004F91C: addiu       $a1, $zero, 0xCD
    ctx->r5 = ADD32(0, 0XCD);
    after_37:
    // 0x8004F920: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8004F924: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8004F928: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8004F92C: jal         0x8006E994
    // 0x8004F930: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    setrotatespriteflags(rdram, ctx);
        goto after_38;
    // 0x8004F930: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_38:
    // 0x8004F934: lw          $ra, 0x54($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X54));
    // 0x8004F938: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8004F93C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8004F940: lw          $s0, 0x30($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8004F944: lw          $s1, 0x34($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8004F948: lw          $s2, 0x38($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8004F94C: lw          $s3, 0x3C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8004F950: lw          $s4, 0x40($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X40));
    // 0x8004F954: lw          $s5, 0x44($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X44));
    // 0x8004F958: lw          $s6, 0x48($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X48));
    // 0x8004F95C: lw          $s7, 0x4C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8004F960: lw          $fp, 0x50($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X50));
    // 0x8004F964: jr          $ra
    // 0x8004F968: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8004F968: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void getangledelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059554: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    // 0x80059558: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8005955C: bc1fl       L_8005959C
    if (!c1cs) {
        // 0x80059560: sub.s       $f12, $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_8005959C;
    }
    goto skip_0;
    // 0x80059560: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    skip_0:
    // 0x80059564: sub.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80059568: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8005956C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80059570: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80059574: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x80059578: nop

    // 0x8005957C: bc1fl       L_80059590
    if (!c1cs) {
        // 0x80059580: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80059590;
    }
    goto skip_1;
    // 0x80059580: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80059584: jr          $ra
    // 0x80059588: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x80059588: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8005958C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80059590:
    // 0x80059590: jr          $ra
    // 0x80059594: sub.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f6.fl;
    return;
    // 0x80059594: sub.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80059598: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
L_8005959C:
    // 0x8005959C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800595A0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800595A4: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x800595A8: nop

    // 0x800595AC: bc1fl       L_800595C0
    if (!c1cs) {
        // 0x800595B0: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800595C0;
    }
    goto skip_2;
    // 0x800595B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x800595B4: jr          $ra
    // 0x800595B8: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    return;
    // 0x800595B8: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x800595BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800595C0:
    // 0x800595C0: nop

    // 0x800595C4: sub.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800595C8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800595CC: jr          $ra
    // 0x800595D0: nop

    return;
    // 0x800595D0: nop

;}
RECOMP_FUNC void mulscale6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FAB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FAC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FAC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FAC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FACC: jal         0x800BB8F8
    // 0x8008FAD0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FAD0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FAD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FAD8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FADC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FAE0: jal         0x800BBA24
    // 0x8008FAE4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FAE4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_1:
    // 0x8008FAE8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FAEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FAF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FAF4: jr          $ra
    // 0x8008FAF8: nop

    return;
    // 0x8008FAF8: nop

;}
RECOMP_FUNC void divscale9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091298: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009129C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800912A0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x800912A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800912A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800912AC: jal         0x800BB834
    // 0x800912B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800912B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800912B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800912B8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800912BC: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800912C0: jal         0x800BB89C
    // 0x800912C4: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800912C4: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x800912C8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800912CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800912D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800912D4: jr          $ra
    // 0x800912D8: nop

    return;
    // 0x800912D8: nop

;}
RECOMP_FUNC void divscale8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009124C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091250: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091254: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80091258: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009125C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091260: jal         0x800BB834
    // 0x80091264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009126C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091270: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091274: jal         0x800BB89C
    // 0x80091278: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091278: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x8009127C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091284: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091288: jr          $ra
    // 0x8009128C: nop

    return;
    // 0x8009128C: nop

;}
RECOMP_FUNC void func_80067F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F30: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
    // 0x80067F34: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80067F38: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x80067F3C: addiu       $a3, $a3, -0x1988
    ctx->r7 = ADD32(ctx->r7, -0X1988);
    // 0x80067F40: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80067F44: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80067F48: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80067F4C: lui         $a2, 0x8022
    ctx->r6 = S32(0X8022 << 16);
    // 0x80067F50: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x80067F54: lh          $a2, 0x61B4($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X61B4));
    // 0x80067F58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067F5C: mflo        $t7
    ctx->r15 = lo;
    // 0x80067F60: addu        $v1, $a3, $t7
    ctx->r3 = ADD32(ctx->r7, ctx->r15);
    // 0x80067F64: lh          $v0, 0xE($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0XE));
    // 0x80067F68: lh          $t8, 0xC($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0XC));
    // 0x80067F6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80067F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F74: or          $v0, $v0, $t8
    ctx->r2 = ctx->r2 | ctx->r24;
    // 0x80067F78: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80067F7C: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80067F80: beq         $a2, $at, L_80067FAC
    if (ctx->r6 == ctx->r1) {
        // 0x80067F84: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80067FAC;
    }
    // 0x80067F84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80067F88: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80067F8C: mflo        $t2
    ctx->r10 = lo;
    // 0x80067F90: addu        $v1, $a3, $t2
    ctx->r3 = ADD32(ctx->r7, ctx->r10);
    // 0x80067F94: lh          $t3, 0xE($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0XE));
    // 0x80067F98: lh          $t6, 0xC($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0XC));
    // 0x80067F9C: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x80067FA0: or          $v0, $t5, $t6
    ctx->r2 = ctx->r13 | ctx->r14;
    // 0x80067FA4: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80067FA8: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
L_80067FAC:
    // 0x80067FAC: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x80067FB0: beq         $t9, $zero, L_80067FC8
    if (ctx->r25 == 0) {
        // 0x80067FB4: nop
    
            goto L_80067FC8;
    }
    // 0x80067FB4: nop

    // 0x80067FB8: jal         0x80067FE0
    // 0x80067FBC: nop

    func_80067FE0(rdram, ctx);
        goto after_0;
    // 0x80067FBC: nop

    after_0:
    // 0x80067FC0: b           L_80067FD4
    // 0x80067FC4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_80067FD4;
    // 0x80067FC4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80067FC8:
    // 0x80067FC8: jal         0x800695A0
    // 0x80067FCC: nop

    func_800695A0(rdram, ctx);
        goto after_1;
    // 0x80067FCC: nop

    after_1:
    // 0x80067FD0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_80067FD4:
    // 0x80067FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067FD8: jr          $ra
    // 0x80067FDC: nop

    return;
    // 0x80067FDC: nop

;}
RECOMP_FUNC void movefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077CF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80077CF4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80077CF8: lui         $s7, 0x8027
    ctx->r23 = S32(0X8027 << 16);
    // 0x80077CFC: lh          $s7, 0x286E($s7)
    ctx->r23 = S32(MEM_H(ctx->r23, 0X286E));
    // 0x80077D00: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80077D04: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80077D08: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80077D0C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80077D10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80077D14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80077D18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80077D1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80077D20: bltz        $s7, L_800781DC
    if (SIGNED(ctx->r23) < 0) {
        // 0x80077D24: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800781DC;
    }
    // 0x80077D24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80077D28: lui         $fp, 0x802A
    ctx->r30 = S32(0X802A << 16);
    // 0x80077D2C: lui         $s4, 0x8024
    ctx->r20 = S32(0X8024 << 16);
    // 0x80077D30: addiu       $s4, $s4, 0x6BA8
    ctx->r20 = ADD32(ctx->r20, 0X6BA8);
    // 0x80077D34: addiu       $fp, $fp, 0x5770
    ctx->r30 = ADD32(ctx->r30, 0X5770);
    // 0x80077D38: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
L_80077D3C:
    // 0x80077D3C: multu       $s7, $s5
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077D40: sll         $t6, $s7, 1
    ctx->r14 = S32(ctx->r23 << 1);
    // 0x80077D44: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x80077D48: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80077D4C: sll         $t3, $s7, 3
    ctx->r11 = S32(ctx->r23 << 3);
    // 0x80077D50: lh          $t7, 0x5F40($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X5F40));
    // 0x80077D54: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x80077D58: lui         $t4, 0x8028
    ctx->r12 = S32(0X8028 << 16);
    // 0x80077D5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80077D60: addiu       $t4, $t4, -0x5C00
    ctx->r12 = ADD32(ctx->r12, -0X5C00);
    // 0x80077D64: mflo        $t8
    ctx->r24 = lo;
    // 0x80077D68: addu        $s2, $s4, $t8
    ctx->r18 = ADD32(ctx->r20, ctx->r24);
    // 0x80077D6C: lh          $v0, 0xE($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0XE));
    // 0x80077D70: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80077D74: addu        $s6, $t3, $t4
    ctx->r22 = ADD32(ctx->r11, ctx->r12);
    // 0x80077D78: beq         $v0, $at, L_80077DE8
    if (ctx->r2 == ctx->r1) {
        // 0x80077D7C: sh          $t7, 0x52($sp)
        MEM_H(0X52, ctx->r29) = ctx->r15;
            goto L_80077DE8;
    }
    // 0x80077D7C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80077D80: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80077D84: beql        $v0, $at, L_80077D98
    if (ctx->r2 == ctx->r1) {
        // 0x80077D88: lh          $v0, 0x22($s2)
        ctx->r2 = S32(MEM_H(ctx->r18, 0X22));
            goto L_80077D98;
    }
    goto skip_0;
    // 0x80077D88: lh          $v0, 0x22($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X22));
    skip_0:
    // 0x80077D8C: b           L_800781D4
    // 0x80077D90: lh          $s7, 0x52($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
        goto L_800781D4;
    // 0x80077D90: lh          $s7, 0x52($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
    // 0x80077D94: lh          $v0, 0x22($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X22));
L_80077D98:
    // 0x80077D98: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80077D9C: bnel        $v0, $at, L_80077DD4
    if (ctx->r2 != ctx->r1) {
        // 0x80077DA0: slti        $at, $v0, 0x36
        ctx->r1 = SIGNED(ctx->r2) < 0X36 ? 1 : 0;
            goto L_80077DD4;
    }
    goto skip_1;
    // 0x80077DA0: slti        $at, $v0, 0x36
    ctx->r1 = SIGNED(ctx->r2) < 0X36 ? 1 : 0;
    skip_1:
    // 0x80077DA4: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x80077DA8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80077DAC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80077DB0: jal         0x8009D240
    // 0x80077DB4: lh          $a1, 0x20($s2)
    ctx->r5 = S32(MEM_H(ctx->r18, 0X20));
    spawn(rdram, ctx);
        goto after_0;
    // 0x80077DB4: lh          $a1, 0x20($s2)
    ctx->r5 = S32(MEM_H(ctx->r18, 0X20));
    after_0:
    // 0x80077DB8: sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23 << 16);
    // 0x80077DBC: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80077DC0: jal         0x80092728
    // 0x80077DC4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    deletesprite(rdram, ctx);
        goto after_1;
    // 0x80077DC4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x80077DC8: b           L_800781D4
    // 0x80077DCC: lh          $s7, 0x52($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
        goto L_800781D4;
    // 0x80077DCC: lh          $s7, 0x52($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
    // 0x80077DD0: slti        $at, $v0, 0x36
    ctx->r1 = SIGNED(ctx->r2) < 0X36 ? 1 : 0;
L_80077DD4:
    // 0x80077DD4: bne         $at, $zero, L_80077DE0
    if (ctx->r1 != 0) {
        // 0x80077DD8: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_80077DE0;
    }
    // 0x80077DD8: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80077DDC: sh          $t1, 0x22($s2)
    MEM_H(0X22, ctx->r18) = ctx->r9;
L_80077DE0:
    // 0x80077DE0: b           L_800781D4
    // 0x80077DE4: lh          $s7, 0x52($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
        goto L_800781D4;
    // 0x80077DE4: lh          $s7, 0x52($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
L_80077DE8:
    // 0x80077DE8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80077DEC: lw          $v0, -0x9E8($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X9E8));
    // 0x80077DF0: lw          $t5, 0x34($s6)
    ctx->r13 = S32(MEM_W(ctx->r22, 0X34));
    // 0x80077DF4: lh          $t2, 0x20($s2)
    ctx->r10 = S32(MEM_H(ctx->r18, 0X20));
    // 0x80077DF8: beq         $v0, $t5, L_80077E08
    if (ctx->r2 == ctx->r13) {
        // 0x80077DFC: sw          $t2, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r10;
            goto L_80077E08;
    }
    // 0x80077DFC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80077E00: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x80077E04: sw          $zero, 0x30($s6)
    MEM_W(0X30, ctx->r22) = 0;
L_80077E08:
    // 0x80077E08: lh          $v1, 0x1E($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1E));
    // 0x80077E0C: slti        $at, $v1, 0x3E8
    ctx->r1 = SIGNED(ctx->r3) < 0X3E8 ? 1 : 0;
    // 0x80077E10: bne         $at, $zero, L_80077E1C
    if (ctx->r1 != 0) {
        // 0x80077E14: slti        $at, $v1, 0x7D0
        ctx->r1 = SIGNED(ctx->r3) < 0X7D0 ? 1 : 0;
            goto L_80077E1C;
    }
    // 0x80077E14: slti        $at, $v1, 0x7D0
    ctx->r1 = SIGNED(ctx->r3) < 0X7D0 ? 1 : 0;
    // 0x80077E18: bne         $at, $zero, L_800781D0
    if (ctx->r1 != 0) {
        // 0x80077E1C: slti        $at, $v1, 0x3E7
        ctx->r1 = SIGNED(ctx->r3) < 0X3E7 ? 1 : 0;
            goto L_800781D0;
    }
L_80077E1C:
    // 0x80077E1C: slti        $at, $v1, 0x3E7
    ctx->r1 = SIGNED(ctx->r3) < 0X3E7 ? 1 : 0;
    // 0x80077E20: beq         $at, $zero, L_800781D0
    if (ctx->r1 == 0) {
        // 0x80077E24: nop
    
            goto L_800781D0;
    }
    // 0x80077E24: nop

    // 0x80077E28: lh          $t6, 0x10($s2)
    ctx->r14 = S32(MEM_H(ctx->r18, 0X10));
    // 0x80077E2C: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80077E30: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x80077E34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80077E38: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80077E3C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80077E40: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80077E44: lh          $t9, 0x18($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X18));
    // 0x80077E48: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80077E4C: sltiu       $at, $t9, 0x9
    ctx->r1 = ctx->r25 < 0X9 ? 1 : 0;
    // 0x80077E50: beq         $at, $zero, L_800781D0
    if (ctx->r1 == 0) {
        // 0x80077E54: nop
    
            goto L_800781D0;
    }
    // 0x80077E54: nop

    // 0x80077E58: lw          $t0, -0x9EC($t0)
    ctx->r8 = S32(MEM_W(ctx->r8, -0X9EC));
    // 0x80077E5C: beq         $t0, $zero, L_800781D0
    if (ctx->r8 == 0) {
        // 0x80077E60: nop
    
            goto L_800781D0;
    }
    // 0x80077E60: nop

    // 0x80077E64: lw          $t1, 0x4($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80077E68: lw          $t2, 0x0($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80077E6C: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80077E70: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x80077E74: beq         $t1, $t2, L_800781D0
    if (ctx->r9 == ctx->r10) {
        // 0x80077E78: nop
    
            goto L_800781D0;
    }
    // 0x80077E78: nop

    // 0x80077E7C: lbu         $t3, -0xB68($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0XB68);
    // 0x80077E80: lui         $t5, 0x802B
    ctx->r13 = S32(0X802B << 16);
    // 0x80077E84: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80077E88: beql        $t4, $zero, L_800780B8
    if (ctx->r12 == 0) {
        // 0x80077E8C: lh          $t4, 0x1E($s2)
        ctx->r12 = S32(MEM_H(ctx->r18, 0X1E));
            goto L_800780B8;
    }
    goto skip_2;
    // 0x80077E8C: lh          $t4, 0x1E($s2)
    ctx->r12 = S32(MEM_H(ctx->r18, 0X1E));
    skip_2:
    // 0x80077E90: lh          $t5, -0x53DC($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, -0X53DC));
    // 0x80077E94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80077E98: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80077E9C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80077EA0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80077EA4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80077EA8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80077EAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80077EB0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80077EB4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80077EB8: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x80077EBC: lh          $t8, 0x2E0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X2E0));
    // 0x80077EC0: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077EC4: mflo        $t9
    ctx->r25 = lo;
    // 0x80077EC8: addu        $a0, $s4, $t9
    ctx->r4 = ADD32(ctx->r20, ctx->r25);
    // 0x80077ECC: jal         0x800ACEC8
    // 0x80077ED0: nop

    dist(rdram, ctx);
        goto after_2;
    // 0x80077ED0: nop

    after_2:
    // 0x80077ED4: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80077ED8: lh          $t0, -0x9DC($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, -0X9DC));
    // 0x80077EDC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80077EE0: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x80077EE4: bnel        $at, $zero, L_80077F3C
    if (ctx->r1 != 0) {
        // 0x80077EE8: lw          $t4, 0x44($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X44));
            goto L_80077F3C;
    }
    goto skip_3;
    // 0x80077EE8: lw          $t4, 0x44($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X44));
    skip_3:
    // 0x80077EEC: lui         $s0, 0x802A
    ctx->r16 = S32(0X802A << 16);
    // 0x80077EF0: addiu       $s0, $s0, 0x5AFC
    ctx->r16 = ADD32(ctx->r16, 0X5AFC);
    // 0x80077EF4: lh          $t1, 0x2E0($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0X2E0));
L_80077EF8:
    // 0x80077EF8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80077EFC: multu       $t1, $s5
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077F00: mflo        $t2
    ctx->r10 = lo;
    // 0x80077F04: addu        $a0, $s4, $t2
    ctx->r4 = ADD32(ctx->r20, ctx->r10);
    // 0x80077F08: jal         0x800ACEC8
    // 0x80077F0C: nop

    dist(rdram, ctx);
        goto after_3;
    // 0x80077F0C: nop

    after_3:
    // 0x80077F10: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80077F14: beq         $at, $zero, L_80077F20
    if (ctx->r1 == 0) {
        // 0x80077F18: lui         $t3, 0x8010
        ctx->r11 = S32(0X8010 << 16);
            goto L_80077F20;
    }
    // 0x80077F18: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80077F1C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80077F20:
    // 0x80077F20: lh          $t3, -0x9DC($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X9DC));
    // 0x80077F24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80077F28: addiu       $s0, $s0, 0x38C
    ctx->r16 = ADD32(ctx->r16, 0X38C);
    // 0x80077F2C: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80077F30: bnel        $at, $zero, L_80077EF8
    if (ctx->r1 != 0) {
        // 0x80077F34: lh          $t1, 0x2E0($s0)
        ctx->r9 = S32(MEM_H(ctx->r16, 0X2E0));
            goto L_80077EF8;
    }
    goto skip_4;
    // 0x80077F34: lh          $t1, 0x2E0($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0X2E0));
    skip_4:
    // 0x80077F38: lw          $t4, 0x44($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X44));
L_80077F3C:
    // 0x80077F3C: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80077F40: beql        $at, $zero, L_80078080
    if (ctx->r1 == 0) {
        // 0x80077F44: lw          $t1, 0x44($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
            goto L_80078080;
    }
    goto skip_5;
    // 0x80077F44: lw          $t1, 0x44($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
    skip_5:
    // 0x80077F48: lw          $t5, 0x30($s6)
    ctx->r13 = S32(MEM_W(ctx->r22, 0X30));
    // 0x80077F4C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80077F50: bnel        $t5, $zero, L_80078080
    if (ctx->r13 != 0) {
        // 0x80077F54: lw          $t1, 0x44($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
            goto L_80078080;
    }
    goto skip_6;
    // 0x80077F54: lw          $t1, 0x44($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
    skip_6:
    // 0x80077F58: lbu         $t6, -0x9F0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X9F0);
    // 0x80077F5C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80077F60: bnel        $t6, $at, L_80078064
    if (ctx->r14 != ctx->r1) {
        // 0x80077F64: sll         $a1, $s7, 16
        ctx->r5 = S32(ctx->r23 << 16);
            goto L_80078064;
    }
    goto skip_7;
    // 0x80077F64: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    skip_7:
    // 0x80077F68: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x80077F6C: lh          $s0, 0x286E($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X286E));
    // 0x80077F70: bltzl       $s0, L_80078058
    if (SIGNED(ctx->r16) < 0) {
        // 0x80077F74: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80078058;
    }
    goto skip_8;
    // 0x80077F74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_8:
    // 0x80077F78: lh          $t7, 0xE($s2)
    ctx->r15 = S32(MEM_H(ctx->r18, 0XE));
L_80077F7C:
    // 0x80077F7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80077F80: bnel        $t7, $at, L_80078040
    if (ctx->r15 != ctx->r1) {
        // 0x80077F84: sll         $t8, $s0, 1
        ctx->r24 = S32(ctx->r16 << 1);
            goto L_80078040;
    }
    goto skip_9;
    // 0x80077F84: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    skip_9:
    // 0x80077F88: beql        $s0, $s7, L_80078040
    if (ctx->r16 == ctx->r23) {
        // 0x80077F8C: sll         $t8, $s0, 1
        ctx->r24 = S32(ctx->r16 << 1);
            goto L_80078040;
    }
    goto skip_10;
    // 0x80077F8C: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    skip_10:
    // 0x80077F90: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077F94: sll         $t0, $s0, 3
    ctx->r8 = S32(ctx->r16 << 3);
    // 0x80077F98: addu        $t0, $t0, $s0
    ctx->r8 = ADD32(ctx->r8, ctx->r16);
    // 0x80077F9C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80077FA0: lui         $t1, 0x8028
    ctx->r9 = S32(0X8028 << 16);
    // 0x80077FA4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80077FA8: mflo        $t8
    ctx->r24 = lo;
    // 0x80077FAC: addu        $s1, $s4, $t8
    ctx->r17 = ADD32(ctx->r20, ctx->r24);
    // 0x80077FB0: lh          $t9, 0x1E($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X1E));
    // 0x80077FB4: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x80077FB8: beql        $at, $zero, L_80078040
    if (ctx->r1 == 0) {
        // 0x80077FBC: sll         $t8, $s0, 1
        ctx->r24 = S32(ctx->r16 << 1);
            goto L_80078040;
    }
    goto skip_11;
    // 0x80077FBC: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    skip_11:
    // 0x80077FC0: lw          $t1, -0x5BD0($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, -0X5BD0));
    // 0x80077FC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80077FC8: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x80077FCC: bnel        $t1, $at, L_80078040
    if (ctx->r9 != ctx->r1) {
        // 0x80077FD0: sll         $t8, $s0, 1
        ctx->r24 = S32(ctx->r16 << 1);
            goto L_80078040;
    }
    goto skip_12;
    // 0x80077FD0: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    skip_12:
    // 0x80077FD4: lh          $t2, -0x53DC($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X53DC));
    // 0x80077FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80077FDC: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80077FE0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80077FE4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80077FE8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80077FEC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80077FF0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80077FF4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80077FF8: addu        $t4, $fp, $t3
    ctx->r12 = ADD32(ctx->r30, ctx->r11);
    // 0x80077FFC: lh          $t5, 0x2E0($t4)
    ctx->r13 = S32(MEM_H(ctx->r12, 0X2E0));
    // 0x80078000: multu       $t5, $s5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80078004: mflo        $t6
    ctx->r14 = lo;
    // 0x80078008: addu        $a1, $s4, $t6
    ctx->r5 = ADD32(ctx->r20, ctx->r14);
    // 0x8007800C: jal         0x800ACEC8
    // 0x80078010: nop

    dist(rdram, ctx);
        goto after_4;
    // 0x80078010: nop

    after_4:
    // 0x80078014: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80078018: beql        $at, $zero, L_80078040
    if (ctx->r1 == 0) {
        // 0x8007801C: sll         $t8, $s0, 1
        ctx->r24 = S32(ctx->r16 << 1);
            goto L_80078040;
    }
    goto skip_13;
    // 0x8007801C: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    skip_13:
    // 0x80078020: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80078024: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80078028: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8007802C: jal         0x80059280
    // 0x80078030: lh          $a0, 0x1E($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X1E));
    stopenvsound(rdram, ctx);
        goto after_5;
    // 0x80078030: lh          $a0, 0x1E($s1)
    ctx->r4 = S32(MEM_H(ctx->r17, 0X1E));
    after_5:
    // 0x80078034: b           L_80078058
    // 0x80078038: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_80078058;
    // 0x80078038: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007803C: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
L_80078040:
    // 0x80078040: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x80078044: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80078048: lh          $s0, 0x5F40($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X5F40));
    // 0x8007804C: bgezl       $s0, L_80077F7C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80078050: lh          $t7, 0xE($s2)
        ctx->r15 = S32(MEM_H(ctx->r18, 0XE));
            goto L_80077F7C;
    }
    goto skip_14;
    // 0x80078050: lh          $t7, 0xE($s2)
    ctx->r15 = S32(MEM_H(ctx->r18, 0XE));
    skip_14:
    // 0x80078054: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80078058:
    // 0x80078058: beql        $s0, $at, L_800781D4
    if (ctx->r16 == ctx->r1) {
        // 0x8007805C: lh          $s7, 0x52($sp)
        ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
            goto L_800781D4;
    }
    goto skip_15;
    // 0x8007805C: lh          $s7, 0x52($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
    skip_15:
    // 0x80078060: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
L_80078064:
    // 0x80078064: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80078068: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8007806C: jal         0x80059034
    // 0x80078070: lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1E);
    spritesound(rdram, ctx);
        goto after_6;
    // 0x80078070: lhu         $a0, 0x1E($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1E);
    after_6:
    // 0x80078074: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80078078: sw          $t0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r8;
    // 0x8007807C: lw          $t1, 0x44($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X44));
L_80078080:
    // 0x80078080: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80078084: bnel        $at, $zero, L_800780B8
    if (ctx->r1 != 0) {
        // 0x80078088: lh          $t4, 0x1E($s2)
        ctx->r12 = S32(MEM_H(ctx->r18, 0X1E));
            goto L_800780B8;
    }
    goto skip_16;
    // 0x80078088: lh          $t4, 0x1E($s2)
    ctx->r12 = S32(MEM_H(ctx->r18, 0X1E));
    skip_16:
    // 0x8007808C: lw          $t2, 0x30($s6)
    ctx->r10 = S32(MEM_W(ctx->r22, 0X30));
    // 0x80078090: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80078094: bnel        $t2, $at, L_800780B8
    if (ctx->r10 != ctx->r1) {
        // 0x80078098: lh          $t4, 0x1E($s2)
        ctx->r12 = S32(MEM_H(ctx->r18, 0X1E));
            goto L_800780B8;
    }
    goto skip_17;
    // 0x80078098: lh          $t4, 0x1E($s2)
    ctx->r12 = S32(MEM_H(ctx->r18, 0X1E));
    skip_17:
    // 0x8007809C: sll         $a1, $s7, 16
    ctx->r5 = S32(ctx->r23 << 16);
    // 0x800780A0: sw          $zero, 0x30($s6)
    MEM_W(0X30, ctx->r22) = 0;
    // 0x800780A4: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800780A8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800780AC: jal         0x80059280
    // 0x800780B0: lh          $a0, 0x1E($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X1E));
    stopenvsound(rdram, ctx);
        goto after_7;
    // 0x800780B0: lh          $a0, 0x1E($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X1E));
    after_7:
    // 0x800780B4: lh          $t4, 0x1E($s2)
    ctx->r12 = S32(MEM_H(ctx->r18, 0X1E));
L_800780B8:
    // 0x800780B8: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x800780BC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800780C0: lbu         $t5, -0xB68($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0XB68);
    // 0x800780C4: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x800780C8: beq         $t6, $zero, L_800781D0
    if (ctx->r14 == 0) {
        // 0x800780CC: nop
    
            goto L_800781D0;
    }
    // 0x800780CC: nop

    // 0x800780D0: lw          $v0, 0x40($s6)
    ctx->r2 = S32(MEM_W(ctx->r22, 0X40));
    // 0x800780D4: blez        $v0, L_800780E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800780D8: nop
    
            goto L_800780E8;
    }
    // 0x800780D8: nop

    // 0x800780DC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800780E0: b           L_800781D0
    // 0x800780E4: sw          $t7, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r15;
        goto L_800781D0;
    // 0x800780E4: sw          $t7, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r15;
L_800780E8:
    // 0x800780E8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800780EC: lh          $v0, -0x9DC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9DC));
    // 0x800780F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800780F4: addiu       $s3, $zero, 0x410
    ctx->r19 = ADD32(0, 0X410);
    // 0x800780F8: blez        $v0, L_800781D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800780FC: sll         $t9, $s1, 3
        ctx->r25 = S32(ctx->r17 << 3);
            goto L_800781D0;
    }
    // 0x800780FC: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
L_80078100:
    // 0x80078100: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x80078104: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80078108: addu        $t9, $t9, $s1
    ctx->r25 = ADD32(ctx->r25, ctx->r17);
    // 0x8007810C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80078110: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x80078114: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80078118: addu        $t0, $fp, $t9
    ctx->r8 = ADD32(ctx->r30, ctx->r25);
    // 0x8007811C: lh          $t1, 0x288($t0)
    ctx->r9 = S32(MEM_H(ctx->r8, 0X288));
    // 0x80078120: lh          $t8, 0x10($s2)
    ctx->r24 = S32(MEM_H(ctx->r18, 0X10));
    // 0x80078124: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x80078128: bnel        $t8, $t1, L_800781BC
    if (ctx->r24 != ctx->r9) {
        // 0x8007812C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800781BC;
    }
    goto skip_18;
    // 0x8007812C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_18:
    // 0x80078130: lh          $t3, 0x20($s2)
    ctx->r11 = S32(MEM_H(ctx->r18, 0X20));
    // 0x80078134: lh          $t2, -0x55BE($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X55BE));
    // 0x80078138: lh          $t6, 0x1E($s2)
    ctx->r14 = S32(MEM_H(ctx->r18, 0X1E));
    // 0x8007813C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80078140: divu        $zero, $t2, $t4
    lo = S32(U32(ctx->r10) / U32(ctx->r12)); hi = S32(U32(ctx->r10) % U32(ctx->r12));
    // 0x80078144: mfhi        $t5
    ctx->r13 = hi;
    // 0x80078148: addu        $s0, $t6, $t5
    ctx->r16 = ADD32(ctx->r14, ctx->r13);
    // 0x8007814C: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x80078150: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80078154: sll         $a0, $t9, 16
    ctx->r4 = S32(ctx->r25 << 16);
    // 0x80078158: bne         $t4, $zero, L_80078164
    if (ctx->r12 != 0) {
        // 0x8007815C: nop
    
            goto L_80078164;
    }
    // 0x8007815C: nop

    // 0x80078160: break       7
    do_break(2147975520);
L_80078164:
    // 0x80078164: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80078168: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8007816C: jal         0x80058E1C
    // 0x80078170: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    sound(rdram, ctx);
        goto after_8;
    // 0x80078170: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_8:
    // 0x80078174: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x80078178: lh          $t8, -0x55BE($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X55BE));
    // 0x8007817C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80078180: div         $zero, $t8, $s3
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r19)));
    // 0x80078184: mfhi        $t1
    ctx->r9 = hi;
    // 0x80078188: addiu       $t3, $t1, 0x410
    ctx->r11 = ADD32(ctx->r9, 0X410);
    // 0x8007818C: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x80078190: lh          $v0, -0x9DC($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X9DC));
    // 0x80078194: bne         $s3, $zero, L_800781A0
    if (ctx->r19 != 0) {
        // 0x80078198: nop
    
            goto L_800781A0;
    }
    // 0x80078198: nop

    // 0x8007819C: break       7
    do_break(2147975580);
L_800781A0:
    // 0x800781A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800781A4: bne         $s3, $at, L_800781B8
    if (ctx->r19 != ctx->r1) {
        // 0x800781A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800781B8;
    }
    // 0x800781A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800781AC: bne         $t8, $at, L_800781B8
    if (ctx->r24 != ctx->r1) {
        // 0x800781B0: nop
    
            goto L_800781B8;
    }
    // 0x800781B0: nop

    // 0x800781B4: break       6
    do_break(2147975604);
L_800781B8:
    // 0x800781B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800781BC:
    // 0x800781BC: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x800781C0: sra         $s1, $t2, 16
    ctx->r17 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800781C4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800781C8: bnel        $at, $zero, L_80078100
    if (ctx->r1 != 0) {
        // 0x800781CC: sll         $t9, $s1, 3
        ctx->r25 = S32(ctx->r17 << 3);
            goto L_80078100;
    }
    goto skip_19;
    // 0x800781CC: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    skip_19:
L_800781D0:
    // 0x800781D0: lh          $s7, 0x52($sp)
    ctx->r23 = S32(MEM_H(ctx->r29, 0X52));
L_800781D4:
    // 0x800781D4: bgez        $s7, L_80077D3C
    if (SIGNED(ctx->r23) >= 0) {
        // 0x800781D8: nop
    
            goto L_80077D3C;
    }
    // 0x800781D8: nop

L_800781DC:
    // 0x800781DC: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800781E0: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800781E4: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800781E8: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800781EC: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800781F0: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800781F4: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800781F8: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800781FC: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80078200: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80078204: jr          $ra
    // 0x80078208: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80078208: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mulscale3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F9EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F9F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F9F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F9F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008F9FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FA00: jal         0x800BB8F8
    // 0x8008FA04: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FA04: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FA08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FA0C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FA10: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FA14: jal         0x800BBA24
    // 0x8008FA18: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FA18: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x8008FA1C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FA20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FA24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FA28: jr          $ra
    // 0x8008FA2C: nop

    return;
    // 0x8008FA2C: nop

;}
RECOMP_FUNC void mulscale7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FAFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FB00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FB04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FB08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FB0C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FB10: jal         0x800BB8F8
    // 0x8008FB14: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FB14: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FB18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FB1C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FB20: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FB24: jal         0x800BBA24
    // 0x8008FB28: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FB28: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x8008FB2C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FB34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FB38: jr          $ra
    // 0x8008FB3C: nop

    return;
    // 0x8008FB3C: nop

;}
RECOMP_FUNC void activatebysector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0580: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B0584: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B0588: lh          $t6, 0x32($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X32));
    // 0x800B058C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B0590: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800B0594: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B0598: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800B059C: lh          $s0, 0x2330($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X2330));
    // 0x800B05A0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B05A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B05A8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B05AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B05B0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B05B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B05B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800B05BC: bltz        $s0, L_800B0618
    if (SIGNED(ctx->r16) < 0) {
        // 0x800B05C0: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800B0618;
    }
    // 0x800B05C0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B05C4: lui         $s4, 0x8027
    ctx->r20 = S32(0X8027 << 16);
    // 0x800B05C8: lui         $s2, 0x8024
    ctx->r18 = S32(0X8024 << 16);
    // 0x800B05CC: addiu       $s2, $s2, 0x6BA8
    ctx->r18 = ADD32(ctx->r18, 0X6BA8);
    // 0x800B05D0: addiu       $s4, $s4, 0x4FA0
    ctx->r20 = ADD32(ctx->r20, 0X4FA0);
    // 0x800B05D4: addiu       $s3, $zero, 0x2C
    ctx->r19 = ADD32(0, 0X2C);
    // 0x800B05D8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_800B05DC:
    // 0x800B05DC: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B05E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B05E4: mflo        $t8
    ctx->r24 = lo;
    // 0x800B05E8: addu        $v0, $s2, $t8
    ctx->r2 = ADD32(ctx->r18, ctx->r24);
    // 0x800B05EC: lh          $t9, 0xE($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0XE));
    // 0x800B05F0: bnel        $s1, $t9, L_800B0608
    if (ctx->r17 != ctx->r25) {
        // 0x800B05F4: sll         $t0, $s0, 1
        ctx->r8 = S32(ctx->r16 << 1);
            goto L_800B0608;
    }
    goto skip_0;
    // 0x800B05F4: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    skip_0:
    // 0x800B05F8: lh          $a0, 0x1E($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0X1E));
    // 0x800B05FC: jal         0x800AF124
    // 0x800B0600: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    operateactivators(rdram, ctx);
        goto after_0;
    // 0x800B0600: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    after_0:
    // 0x800B0604: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
L_800B0608:
    // 0x800B0608: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x800B060C: lh          $s0, 0x0($t1)
    ctx->r16 = S32(MEM_H(ctx->r9, 0X0));
    // 0x800B0610: bgez        $s0, L_800B05DC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800B0614: nop
    
            goto L_800B05DC;
    }
    // 0x800B0614: nop

L_800B0618:
    // 0x800B0618: bne         $s5, $zero, L_800B0628
    if (ctx->r21 != 0) {
        // 0x800B061C: lh          $a0, 0x32($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0X32));
            goto L_800B0628;
    }
    // 0x800B061C: lh          $a0, 0x32($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X32));
    // 0x800B0620: jal         0x800ADBFC
    // 0x800B0624: lh          $a1, 0x36($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X36));
    operatesectors(rdram, ctx);
        goto after_1;
    // 0x800B0624: lh          $a1, 0x36($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X36));
    after_1:
L_800B0628:
    // 0x800B0628: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800B062C: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800B0630: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800B0634: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800B0638: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800B063C: lw          $s4, 0x24($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800B0640: lw          $s5, 0x28($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800B0644: jr          $ra
    // 0x800B0648: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B0648: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mulscale8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FB40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FB44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FB48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FB4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FB50: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FB54: jal         0x800BB8F8
    // 0x8008FB58: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FB58: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FB5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FB60: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FB64: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FB68: jal         0x800BBA24
    // 0x8008FB6C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FB6C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_1:
    // 0x8008FB70: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FB74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FB78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FB7C: jr          $ra
    // 0x8008FB80: nop

    return;
    // 0x8008FB80: nop

;}
RECOMP_FUNC void func_8005757C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005757C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80057580: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80057584: lui         $s2, 0x7C
    ctx->r18 = S32(0X7C << 16);
    // 0x80057588: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8005758C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80057590: lui         $t6, 0x7C
    ctx->r14 = S32(0X7C << 16);
    // 0x80057594: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x80057598: lui         $s7, 0x8022
    ctx->r23 = S32(0X8022 << 16);
    // 0x8005759C: addiu       $s2, $s2, -0x3920
    ctx->r18 = ADD32(ctx->r18, -0X3920);
    // 0x800575A0: addiu       $t6, $t6, -0x2A80
    ctx->r14 = ADD32(ctx->r14, -0X2A80);
    // 0x800575A4: addiu       $s7, $s7, -0x6310
    ctx->r23 = ADD32(ctx->r23, -0X6310);
    // 0x800575A8: addiu       $s0, $s0, -0x5FC0
    ctx->r16 = ADD32(ctx->r16, -0X5FC0);
    // 0x800575AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800575B0: subu        $t7, $t6, $s2
    ctx->r15 = SUB32(ctx->r14, ctx->r18);
    // 0x800575B4: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x800575B8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800575BC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800575C0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800575C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800575C8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800575CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800575D0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800575D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800575D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800575DC: jal         0x800BF830
    // 0x800575E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800575E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800575E4: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x800575E8: addiu       $s1, $s1, -0x5FCC
    ctx->r17 = ADD32(ctx->r17, -0X5FCC);
    // 0x800575EC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800575F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800575F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800575F8: jal         0x8004B560
    // 0x800575FC: lw          $a2, 0x0($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X0));
    copyfromrom(rdram, ctx);
        goto after_1;
    // 0x800575FC: lw          $a2, 0x0($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X0));
    after_1:
    // 0x80057600: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80057604: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80057608: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005760C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80057610: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80057614: jal         0x800BF830
    // 0x80057618: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80057618: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8005761C: lui         $s2, 0x7C
    ctx->r18 = S32(0X7C << 16);
    // 0x80057620: lui         $s6, 0x8022
    ctx->r22 = S32(0X8022 << 16);
    // 0x80057624: addiu       $s6, $s6, -0x606C
    ctx->r22 = ADD32(ctx->r22, -0X606C);
    // 0x80057628: addiu       $s2, $s2, -0x4040
    ctx->r18 = ADD32(ctx->r18, -0X4040);
    // 0x8005762C: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x80057630: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80057634: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80057638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005763C: jal         0x8004B560
    // 0x80057640: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    copyfromrom(rdram, ctx);
        goto after_3;
    // 0x80057640: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80057644: lw          $v0, 0x0($s6)
    ctx->r2 = S32(MEM_W(ctx->r22, 0X0));
    // 0x80057648: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x8005764C: addiu       $s4, $s4, -0x5FBC
    ctx->r20 = ADD32(ctx->r20, -0X5FBC);
    // 0x80057650: lh          $t0, 0x2($v0)
    ctx->r8 = S32(MEM_H(ctx->r2, 0X2));
    // 0x80057654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80057658: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005765C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80057660: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80057664: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x80057668: lh          $t3, 0x2($v0)
    ctx->r11 = S32(MEM_H(ctx->r2, 0X2));
    // 0x8005766C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80057670: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80057674: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80057678: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x8005767C: jal         0x800BF830
    // 0x80057680: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x80057680: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_4:
    // 0x80057684: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x80057688: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005768C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80057690: jal         0x8004B560
    // 0x80057694: lw          $a2, 0x0($s4)
    ctx->r6 = S32(MEM_W(ctx->r20, 0X0));
    copyfromrom(rdram, ctx);
        goto after_5;
    // 0x80057694: lw          $a2, 0x0($s4)
    ctx->r6 = S32(MEM_W(ctx->r20, 0X0));
    after_5:
    // 0x80057698: lw          $a0, 0x0($s6)
    ctx->r4 = S32(MEM_W(ctx->r22, 0X0));
    // 0x8005769C: jal         0x800C0348
    // 0x800576A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alSeqFileNew(rdram, ctx);
        goto after_6;
    // 0x800576A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x800576A4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800576A8: addiu       $a1, $a1, -0x1690
    ctx->r5 = ADD32(ctx->r5, -0X1690);
    // 0x800576AC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800576B0: addiu       $s0, $s0, 0x4D58
    ctx->r16 = ADD32(ctx->r16, 0X4D58);
    // 0x800576B4: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800576B8: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800576BC: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800576C0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800576C4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800576C8: sb          $t8, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r24;
    // 0x800576CC: sw          $s7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r23;
    // 0x800576D0: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x800576D4: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    // 0x800576D8: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x800576DC: jal         0x800C14F0
    // 0x800576E0: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    alCSPNew(rdram, ctx);
        goto after_7;
    // 0x800576E0: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    after_7:
    // 0x800576E4: lui         $a1, 0x7C
    ctx->r5 = S32(0X7C << 16);
    // 0x800576E8: addiu       $a1, $a1, -0x2A80
    ctx->r5 = ADD32(ctx->r5, -0X2A80);
    // 0x800576EC: jal         0x800C0244
    // 0x800576F0: lw          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X0));
    alBnkfNew(rdram, ctx);
        goto after_8;
    // 0x800576F0: lw          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X0));
    after_8:
    // 0x800576F4: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800576F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800576FC: addiu       $v0, $v0, 0x4D64
    ctx->r2 = ADD32(ctx->r2, 0X4D64);
    // 0x80057700: lw          $a1, 0x4($t9)
    ctx->r5 = S32(MEM_W(ctx->r25, 0X4));
    // 0x80057704: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80057708: jal         0x800C1660
    // 0x8005770C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    alSeqpSetBank(rdram, ctx);
        goto after_9;
    // 0x8005770C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    after_9:
    // 0x80057710: lw          $t1, 0x0($s6)
    ctx->r9 = S32(MEM_W(ctx->r22, 0X0));
    // 0x80057714: lui         $s5, 0x8022
    ctx->r21 = S32(0X8022 << 16);
    // 0x80057718: addiu       $s5, $s5, -0x5FA4
    ctx->r21 = ADD32(ctx->r21, -0X5FA4);
    // 0x8005771C: lh          $t2, 0x2($t1)
    ctx->r10 = S32(MEM_H(ctx->r9, 0X2));
    // 0x80057720: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80057724: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80057728: blez        $t2, L_800577B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8005772C: sw          $t2, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r10;
            goto L_800577B0;
    }
    // 0x8005772C: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    // 0x80057730: lui         $s2, 0x8022
    ctx->r18 = S32(0X8022 << 16);
    // 0x80057734: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x80057738: addiu       $s3, $s3, -0x5FC8
    ctx->r19 = ADD32(ctx->r19, -0X5FC8);
    // 0x8005773C: addiu       $s2, $s2, -0x6050
    ctx->r18 = ADD32(ctx->r18, -0X6050);
L_80057740:
    // 0x80057740: lw          $t3, 0x0($s6)
    ctx->r11 = S32(MEM_W(ctx->r22, 0X0));
    // 0x80057744: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80057748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005774C: addu        $v0, $t3, $s1
    ctx->r2 = ADD32(ctx->r11, ctx->r17);
    // 0x80057750: lw          $t4, 0x4($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80057754: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80057758: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005775C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80057760: lw          $t5, 0x8($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X8));
    // 0x80057764: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80057768: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x8005776C: beq         $t6, $zero, L_8005777C
    if (ctx->r14 == 0) {
        // 0x80057770: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_8005777C;
    }
    // 0x80057770: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80057774: addiu       $v1, $t5, 0x1
    ctx->r3 = ADD32(ctx->r13, 0X1);
    // 0x80057778: sw          $v1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r3;
L_8005777C:
    // 0x8005777C: jal         0x800BF830
    // 0x80057780: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x80057780: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_10:
    // 0x80057784: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x80057788: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005778C: lw          $a1, 0x0($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80057790: jal         0x8004B560
    // 0x80057794: lw          $a2, 0x0($s4)
    ctx->r6 = S32(MEM_W(ctx->r20, 0X0));
    copyfromrom(rdram, ctx);
        goto after_11;
    // 0x80057794: lw          $a2, 0x0($s4)
    ctx->r6 = S32(MEM_W(ctx->r20, 0X0));
    after_11:
    // 0x80057798: lw          $t8, 0x0($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X0));
    // 0x8005779C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800577A0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800577A4: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800577A8: bne         $at, $zero, L_80057740
    if (ctx->r1 != 0) {
        // 0x800577AC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80057740;
    }
    // 0x800577AC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800577B0:
    // 0x800577B0: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800577B4: lw          $s0, 0x1C($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800577B8: lw          $s1, 0x20($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800577BC: lw          $s2, 0x24($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800577C0: lw          $s3, 0x28($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800577C4: lw          $s4, 0x2C($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800577C8: lw          $s5, 0x30($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800577CC: lw          $s6, 0x34($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800577D0: lw          $s7, 0x38($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800577D4: jr          $ra
    // 0x800577D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800577D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void insertspritesect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092588: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009258C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80092590: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80092594: slti        $at, $a0, 0x291
    ctx->r1 = SIGNED(ctx->r4) < 0X291 ? 1 : 0;
    // 0x80092598: beq         $at, $zero, L_800925B8
    if (ctx->r1 == 0) {
        // 0x8009259C: lui         $t1, 0x8027
        ctx->r9 = S32(0X8027 << 16);
            goto L_800925B8;
    }
    // 0x8009259C: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x800925A0: addiu       $t1, $t1, 0x2330
    ctx->r9 = ADD32(ctx->r9, 0X2330);
    // 0x800925A4: lh          $v0, 0x522($t1)
    ctx->r2 = S32(MEM_H(ctx->r9, 0X522));
    // 0x800925A8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800925AC: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x800925B0: bne         $t0, $v0, L_800925C0
    if (ctx->r8 != ctx->r2) {
        // 0x800925B4: sll         $v1, $v0, 16
        ctx->r3 = S32(ctx->r2 << 16);
            goto L_800925C0;
    }
    // 0x800925B4: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
L_800925B8:
    // 0x800925B8: jr          $ra
    // 0x800925BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800925BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800925C0:
    // 0x800925C0: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800925C4: sll         $a1, $t8, 1
    ctx->r5 = S32(ctx->r24 << 1);
    // 0x800925C8: addiu       $t9, $t9, 0x4FA0
    ctx->r25 = ADD32(ctx->r25, 0X4FA0);
    // 0x800925CC: addu        $a2, $a1, $t9
    ctx->r6 = ADD32(ctx->r5, ctx->r25);
    // 0x800925D0: lh          $t3, 0x0($a2)
    ctx->r11 = S32(MEM_H(ctx->r6, 0X0));
    // 0x800925D4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800925D8: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800925DC: sh          $t3, 0x522($t1)
    MEM_H(0X522, ctx->r9) = ctx->r11;
    // 0x800925E0: lh          $v0, 0x522($t1)
    ctx->r2 = S32(MEM_H(ctx->r9, 0X522));
    // 0x800925E4: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800925E8: addu        $a3, $t1, $t7
    ctx->r7 = ADD32(ctx->r9, ctx->r15);
    // 0x800925EC: bltz        $v0, L_80092608
    if (SIGNED(ctx->r2) < 0) {
        // 0x800925F0: subu        $t3, $t3, $v1
        ctx->r11 = SUB32(ctx->r11, ctx->r3);
            goto L_80092608;
    }
    // 0x800925F0: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x800925F4: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x800925F8: addiu       $t2, $t2, 0x3060
    ctx->r10 = ADD32(ctx->r10, 0X3060);
    // 0x800925FC: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x80092600: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80092604: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
L_80092608:
    // 0x80092608: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8009260C: addiu       $t2, $t2, 0x3060
    ctx->r10 = ADD32(ctx->r10, 0X3060);
    // 0x80092610: addu        $t6, $t2, $a1
    ctx->r14 = ADD32(ctx->r10, ctx->r5);
    // 0x80092614: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
    // 0x80092618: lh          $v0, 0x0($a3)
    ctx->r2 = S32(MEM_H(ctx->r7, 0X0));
    // 0x8009261C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80092620: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80092624: bltz        $v0, L_80092638
    if (SIGNED(ctx->r2) < 0) {
        // 0x80092628: sh          $v0, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r2;
            goto L_80092638;
    }
    // 0x80092628: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8009262C: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80092630: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80092634: sh          $v1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r3;
L_80092638:
    // 0x80092638: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8009263C: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x80092640: sh          $v1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r3;
    // 0x80092644: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80092648: sh          $a0, 0x6BB8($at)
    MEM_H(0X6BB8, ctx->r1) = ctx->r4;
    // 0x8009264C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80092650: jr          $ra
    // 0x80092654: nop

    return;
    // 0x80092654: nop

;}
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4AF0: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800C4AF4: bne         $at, $zero, L_800C4B6C
    if (ctx->r1 != 0) {
        // 0x800C4AF8: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_800C4B6C;
    }
    // 0x800C4AF8: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800C4AFC: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800C4B00: beq         $v1, $zero, L_800C4B10
    if (ctx->r3 == 0) {
        // 0x800C4B04: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_800C4B10;
    }
    // 0x800C4B04: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800C4B08: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x800C4B0C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800C4B10:
    // 0x800C4B10: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800C4B14: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800C4B18: beq         $a3, $zero, L_800C4B4C
    if (ctx->r7 == 0) {
        // 0x800C4B1C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800C4B4C;
    }
    // 0x800C4B1C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800C4B20: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800C4B24:
    // 0x800C4B24: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800C4B28: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x800C4B2C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x800C4B30: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x800C4B34: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x800C4B38: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800C4B3C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x800C4B40: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x800C4B44: bne         $a0, $a3, L_800C4B24
    if (ctx->r4 != ctx->r7) {
        // 0x800C4B48: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800C4B24;
    }
    // 0x800C4B48: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800C4B4C:
    // 0x800C4B4C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800C4B50: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800C4B54: beq         $a3, $zero, L_800C4B6C
    if (ctx->r7 == 0) {
        // 0x800C4B58: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800C4B6C;
    }
    // 0x800C4B58: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800C4B5C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800C4B60:
    // 0x800C4B60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C4B64: bne         $a0, $a3, L_800C4B60
    if (ctx->r4 != ctx->r7) {
        // 0x800C4B68: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800C4B60;
    }
    // 0x800C4B68: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800C4B6C:
    // 0x800C4B6C: blez        $a1, L_800C4B84
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C4B70: nop
    
            goto L_800C4B84;
    }
    // 0x800C4B70: nop

    // 0x800C4B74: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800C4B78:
    // 0x800C4B78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C4B7C: bne         $a0, $a1, L_800C4B78
    if (ctx->r4 != ctx->r5) {
        // 0x800C4B80: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800C4B78;
    }
    // 0x800C4B80: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800C4B84:
    // 0x800C4B84: jr          $ra
    // 0x800C4B88: nop

    return;
    // 0x800C4B88: nop

;}
RECOMP_FUNC void mulscale5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FA74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FA78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FA7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FA80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008FA84: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8008FA88: jal         0x800BB8F8
    // 0x8008FA8C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x8008FA8C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008FA90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FA94: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008FA98: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008FA9C: jal         0x800BBA24
    // 0x8008FAA0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    __ll_rshift_recomp(rdram, ctx);
        goto after_1;
    // 0x8008FAA0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x8008FAA4: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8008FAA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FAAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008FAB0: jr          $ra
    // 0x8008FAB4: nop

    return;
    // 0x8008FAB4: nop

;}
RECOMP_FUNC void hits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1BC4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800A1BC8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800A1BCC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A1BD0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A1BD4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A1BD8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A1BDC: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x800A1BE0: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x800A1BE4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A1BE8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800A1BEC: lh          $t2, 0xE($v1)
    ctx->r10 = S32(MEM_H(ctx->r3, 0XE));
    // 0x800A1BF0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A1BF4: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x800A1BF8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A1BFC: bne         $t2, $at, L_800A1C0C
    if (ctx->r10 != ctx->r1) {
        // 0x800A1C00: sw          $a0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r4;
            goto L_800A1C0C;
    }
    // 0x800A1C00: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800A1C04: b           L_800A1C10
    // 0x800A1C08: addiu       $t0, $zero, 0x2800
    ctx->r8 = ADD32(0, 0X2800);
        goto L_800A1C10;
    // 0x800A1C08: addiu       $t0, $zero, 0x2800
    ctx->r8 = ADD32(0, 0X2800);
L_800A1C0C:
    // 0x800A1C0C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800A1C10:
    // 0x800A1C10: lh          $v0, 0x14($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X14));
    // 0x800A1C14: lw          $t3, 0x8($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X8));
    // 0x800A1C18: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x800A1C1C: addiu       $t4, $v0, 0x200
    ctx->r12 = ADD32(ctx->r2, 0X200);
    // 0x800A1C20: andi        $t5, $t4, 0x7FF
    ctx->r13 = ctx->r12 & 0X7FF;
    // 0x800A1C24: addiu       $t1, $t1, -0x9A0
    ctx->r9 = ADD32(ctx->r9, -0X9A0);
    // 0x800A1C28: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800A1C2C: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800A1C30: andi        $t9, $v0, 0x7FF
    ctx->r25 = ctx->r2 & 0X7FF;
    // 0x800A1C34: lh          $t8, 0x0($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X0));
    // 0x800A1C38: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x800A1C3C: subu        $a2, $t3, $t0
    ctx->r6 = SUB32(ctx->r11, ctx->r8);
    // 0x800A1C40: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A1C44: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x800A1C48: lui         $t3, 0x100
    ctx->r11 = S32(0X100 << 16);
    // 0x800A1C4C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A1C50: addiu       $t8, $sp, 0x5C
    ctx->r24 = ADD32(ctx->r29, 0X5C);
    // 0x800A1C54: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x800A1C58: addiu       $t2, $sp, 0x54
    ctx->r10 = ADD32(ctx->r29, 0X54);
    // 0x800A1C5C: addiu       $t9, $sp, 0x58
    ctx->r25 = ADD32(ctx->r29, 0X58);
    // 0x800A1C60: addiu       $t7, $sp, 0x4E
    ctx->r15 = ADD32(ctx->r29, 0X4E);
    // 0x800A1C64: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x800A1C68: addiu       $t5, $sp, 0x52
    ctx->r13 = ADD32(ctx->r29, 0X52);
    // 0x800A1C6C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800A1C70: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A1C74: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800A1C78: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800A1C7C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800A1C80: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800A1C84: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800A1C88: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800A1C8C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800A1C90: lw          $a0, 0x0($v1)
    ctx->r4 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800A1C94: lw          $a1, 0x4($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800A1C98: lh          $a3, 0x10($v1)
    ctx->r7 = S32(MEM_H(ctx->r3, 0X10));
    // 0x800A1C9C: jal         0x8009324C
    // 0x800A1CA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    hitscan(rdram, ctx);
        goto after_0;
    // 0x800A1CA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_0:
    // 0x800A1CA4: lw          $v1, 0x44($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800A1CA8: lw          $t4, 0x5C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800A1CAC: lw          $t6, 0x58($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800A1CB0: lw          $t5, 0x0($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800A1CB4: lw          $t7, 0x4($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800A1CB8: subu        $a0, $t4, $t5
    ctx->r4 = SUB32(ctx->r12, ctx->r13);
    // 0x800A1CBC: jal         0x800993E0
    // 0x800A1CC0: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    FindDistance2D(rdram, ctx);
        goto after_1;
    // 0x800A1CC0: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    after_1:
    // 0x800A1CC4: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800A1CC8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800A1CCC: jr          $ra
    // 0x800A1CD0: nop

    return;
    // 0x800A1CD0: nop

;}
RECOMP_FUNC void demoinput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B480: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8005B484: lbu         $v0, 0x1364($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1364);
    // 0x8005B488: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005B48C: addiu       $a0, $a0, -0x29AC
    ctx->r4 = ADD32(ctx->r4, -0X29AC);
    // 0x8005B490: beq         $v0, $zero, L_8005B4B8
    if (ctx->r2 == 0) {
        // 0x8005B494: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005B4B8;
    }
    // 0x8005B494: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B498: beq         $v0, $at, L_8005B500
    if (ctx->r2 == ctx->r1) {
        // 0x8005B49C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005B500;
    }
    // 0x8005B49C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005B4A0: beq         $v0, $at, L_8005B550
    if (ctx->r2 == ctx->r1) {
        // 0x8005B4A4: lui         $a0, 0x8022
        ctx->r4 = S32(0X8022 << 16);
            goto L_8005B550;
    }
    // 0x8005B4A4: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005B4A8: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x8005B4AC: addiu       $v1, $v1, -0x29AE
    ctx->r3 = ADD32(ctx->r3, -0X29AE);
    // 0x8005B4B0: b           L_8005B59C
    // 0x8005B4B4: addiu       $a0, $a0, -0x29AC
    ctx->r4 = ADD32(ctx->r4, -0X29AC);
        goto L_8005B59C;
    // 0x8005B4B4: addiu       $a0, $a0, -0x29AC
    ctx->r4 = ADD32(ctx->r4, -0X29AC);
L_8005B4B8:
    // 0x8005B4B8: lw          $t6, 0x0($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005B4BC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005B4C0: addiu       $t8, $t8, 0x4DA4
    ctx->r24 = ADD32(ctx->r24, 0X4DA4);
    // 0x8005B4C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005B4C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005B4CC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8005B4D0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8005B4D4: lh          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X0));
    // 0x8005B4D8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B4DC: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x8005B4E0: sh          $t9, -0x29B2($at)
    MEM_H(-0X29B2, ctx->r1) = ctx->r25;
    // 0x8005B4E4: lh          $t0, 0x2($v0)
    ctx->r8 = S32(MEM_H(ctx->r2, 0X2));
    // 0x8005B4E8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B4EC: addiu       $v1, $v1, -0x29AE
    ctx->r3 = ADD32(ctx->r3, -0X29AE);
    // 0x8005B4F0: sh          $t0, -0x29B0($at)
    MEM_H(-0X29B0, ctx->r1) = ctx->r8;
    // 0x8005B4F4: lhu         $t1, 0x4($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X4);
    // 0x8005B4F8: b           L_8005B59C
    // 0x8005B4FC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
        goto L_8005B59C;
    // 0x8005B4FC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
L_8005B500:
    // 0x8005B500: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005B504: addiu       $a0, $a0, -0x29AC
    ctx->r4 = ADD32(ctx->r4, -0X29AC);
    // 0x8005B508: lw          $t2, 0x0($a0)
    ctx->r10 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005B50C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8005B510: addiu       $t4, $t4, 0x5D70
    ctx->r12 = ADD32(ctx->r12, 0X5D70);
    // 0x8005B514: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005B518: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8005B51C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8005B520: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8005B524: lh          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X0));
    // 0x8005B528: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B52C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x8005B530: sh          $t5, -0x29B2($at)
    MEM_H(-0X29B2, ctx->r1) = ctx->r13;
    // 0x8005B534: lh          $t6, 0x2($v0)
    ctx->r14 = S32(MEM_H(ctx->r2, 0X2));
    // 0x8005B538: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B53C: addiu       $v1, $v1, -0x29AE
    ctx->r3 = ADD32(ctx->r3, -0X29AE);
    // 0x8005B540: sh          $t6, -0x29B0($at)
    MEM_H(-0X29B0, ctx->r1) = ctx->r14;
    // 0x8005B544: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    // 0x8005B548: b           L_8005B59C
    // 0x8005B54C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
        goto L_8005B59C;
    // 0x8005B54C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_8005B550:
    // 0x8005B550: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8005B554: addiu       $a0, $a0, -0x29AC
    ctx->r4 = ADD32(ctx->r4, -0X29AC);
    // 0x8005B558: lw          $t8, 0x0($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005B55C: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8005B560: addiu       $t0, $t0, 0x7948
    ctx->r8 = ADD32(ctx->r8, 0X7948);
    // 0x8005B564: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005B568: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005B56C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005B570: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8005B574: lh          $t1, 0x0($v0)
    ctx->r9 = S32(MEM_H(ctx->r2, 0X0));
    // 0x8005B578: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B57C: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x8005B580: sh          $t1, -0x29B2($at)
    MEM_H(-0X29B2, ctx->r1) = ctx->r9;
    // 0x8005B584: lh          $t2, 0x2($v0)
    ctx->r10 = S32(MEM_H(ctx->r2, 0X2));
    // 0x8005B588: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B58C: addiu       $v1, $v1, -0x29AE
    ctx->r3 = ADD32(ctx->r3, -0X29AE);
    // 0x8005B590: sh          $t2, -0x29B0($at)
    MEM_H(-0X29B0, ctx->r1) = ctx->r10;
    // 0x8005B594: lhu         $t3, 0x4($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X4);
    // 0x8005B598: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
L_8005B59C:
    // 0x8005B59C: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x8005B5A0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005B5A4: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x8005B5A8: beq         $t4, $at, L_8005B5B8
    if (ctx->r12 == ctx->r1) {
        // 0x8005B5AC: addiu       $t6, $zero, 0xD
        ctx->r14 = ADD32(0, 0XD);
            goto L_8005B5B8;
    }
    // 0x8005B5AC: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8005B5B0: lh          $t5, 0x59FC($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X59FC));
    // 0x8005B5B4: bgtz        $t5, L_8005B5D8
    if (SIGNED(ctx->r13) > 0) {
        // 0x8005B5B8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005B5D8;
    }
L_8005B5B8:
    // 0x8005B5B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005B5BC: sb          $t6, 0x36C8($at)
    MEM_B(0X36C8, ctx->r1) = ctx->r14;
    // 0x8005B5C0: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B5C4: sh          $zero, -0x29B2($at)
    MEM_H(-0X29B2, ctx->r1) = 0;
    // 0x8005B5C8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005B5CC: sh          $zero, -0x29B0($at)
    MEM_H(-0X29B0, ctx->r1) = 0;
    // 0x8005B5D0: jr          $ra
    // 0x8005B5D4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    return;
    // 0x8005B5D4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8005B5D8:
    // 0x8005B5D8: lw          $t7, 0x0($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8005B5DC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8005B5E0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005B5E4: jr          $ra
    // 0x8005B5E8: nop

    return;
    // 0x8005B5E8: nop

    // 0x8005B5EC: nop

;}
RECOMP_FUNC void alSynFreeVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA488: lw          $a2, 0x8($a1)
    ctx->r6 = S32(MEM_W(ctx->r5, 0X8));
    // 0x800CA48C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800CA490: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CA494: beql        $a2, $zero, L_800CA524
    if (ctx->r6 == 0) {
        // 0x800CA498: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CA524;
    }
    goto skip_0;
    // 0x800CA498: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800CA49C: lw          $t6, 0xD8($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0XD8));
    // 0x800CA4A0: beql        $t6, $zero, L_800CA50C
    if (ctx->r14 == 0) {
        // 0x800CA4A4: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800CA50C;
    }
    goto skip_1;
    // 0x800CA4A4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    skip_1:
    // 0x800CA4A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CA4AC: jal         0x800C2570
    // 0x800CA4B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800CA4B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CA4B4: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CA4B8: lw          $t0, 0x18($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800CA4BC: beq         $v0, $zero, L_800CA520
    if (ctx->r2 == 0) {
        // 0x800CA4C0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800CA520;
    }
    // 0x800CA4C0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CA4C4: lw          $t8, 0x8($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA4C8: lw          $t7, 0x1C($t0)
    ctx->r15 = S32(MEM_W(ctx->r8, 0X1C));
    // 0x800CA4CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800CA4D0: lw          $t9, 0xD8($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0XD8));
    // 0x800CA4D4: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800CA4D8: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800CA4DC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800CA4E0: lw          $t2, 0x8($a3)
    ctx->r10 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA4E4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800CA4E8: lw          $t3, 0x8($a3)
    ctx->r11 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA4EC: lw          $a0, 0xC($t3)
    ctx->r4 = S32(MEM_W(ctx->r11, 0XC));
    // 0x800CA4F0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800CA4F4: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CA4F8: jalr        $t9
    // 0x800CA4FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CA4FC: nop

    after_1:
    // 0x800CA500: b           L_800CA51C
    // 0x800CA504: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
        goto L_800CA51C;
    // 0x800CA504: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CA508: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800CA50C:
    // 0x800CA50C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800CA510: jal         0x800C24C0
    // 0x800CA514: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _freePVoice(rdram, ctx);
        goto after_2;
    // 0x800CA514: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800CA518: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
L_800CA51C:
    // 0x800CA51C: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_800CA520:
    // 0x800CA520: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CA524:
    // 0x800CA524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA528: jr          $ra
    // 0x800CA52C: nop

    return;
    // 0x800CA52C: nop

;}
RECOMP_FUNC void alAuxBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE420: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800CE424: lw          $t0, 0x50($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800CE428: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800CE42C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800CE430: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800CE434: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800CE438: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CE43C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CE440: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800CE444: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CE448: lw          $v1, 0x1C($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X1C));
    // 0x800CE44C: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800CE450: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800CE454: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800CE458: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x800CE45C: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x800CE460: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800CE464: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800CE468: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800CE46C: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800CE470: lw          $t8, 0x14($a0)
    ctx->r24 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800CE474: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800CE478: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800CE47C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800CE480: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800CE484: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800CE488: blez        $t8, L_800CE4CC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800CE48C: addiu       $s2, $t0, 0x10
        ctx->r18 = ADD32(ctx->r8, 0X10);
            goto L_800CE4CC;
    }
    // 0x800CE48C: addiu       $s2, $t0, 0x10
    ctx->r18 = ADD32(ctx->r8, 0X10);
    // 0x800CE490: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800CE494:
    // 0x800CE494: lw          $a0, 0x0($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800CE498: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800CE49C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800CE4A0: lw          $t9, 0x4($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800CE4A4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800CE4A8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800CE4AC: jalr        $t9
    // 0x800CE4B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CE4B0: nop

    after_0:
    // 0x800CE4B4: lw          $t1, 0x14($s3)
    ctx->r9 = S32(MEM_W(ctx->r19, 0X14));
    // 0x800CE4B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800CE4BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800CE4C0: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CE4C4: bne         $at, $zero, L_800CE494
    if (ctx->r1 != 0) {
        // 0x800CE4C8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800CE494;
    }
    // 0x800CE4C8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800CE4CC:
    // 0x800CE4CC: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800CE4D0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800CE4D4: lw          $s2, 0x28($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800CE4D8: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CE4DC: lw          $s1, 0x24($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CE4E0: lw          $s3, 0x2C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800CE4E4: lw          $s4, 0x30($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800CE4E8: lw          $s5, 0x34($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800CE4EC: lw          $s6, 0x38($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800CE4F0: jr          $ra
    // 0x800CE4F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800CE4F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A9A0: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8008A9A4: addiu       $t0, $t0, 0x231C
    ctx->r8 = ADD32(ctx->r8, 0X231C);
    // 0x8008A9A8: lw          $t6, 0x0($t0)
    ctx->r14 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008A9AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008A9B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008A9B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008A9B8: lh          $t7, 0x20($t6)
    ctx->r15 = S32(MEM_H(ctx->r14, 0X20));
    // 0x8008A9BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008A9C0: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x8008A9C4: sh          $t7, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r15;
    // 0x8008A9C8: lh          $t8, 0x36($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X36));
    // 0x8008A9CC: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8008A9D0: bne         $t8, $at, L_8008A9DC
    if (ctx->r24 != ctx->r1) {
        // 0x8008A9D4: nop
    
            goto L_8008A9DC;
    }
    // 0x8008A9D4: nop

    // 0x8008A9D8: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
L_8008A9DC:
    // 0x8008A9DC: lw          $v0, 0x2318($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, 0X2318));
    // 0x8008A9E0: lw          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8008A9E4: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8008A9E8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8008A9EC: lh          $t3, 0x36($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X36));
    // 0x8008A9F0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8008A9F4: beql        $t4, $zero, L_8008AAFC
    if (ctx->r12 == 0) {
        // 0x8008A9F8: lh          $t9, 0x36($sp)
        ctx->r25 = S32(MEM_H(ctx->r29, 0X36));
            goto L_8008AAFC;
    }
    goto skip_0;
    // 0x8008A9F8: lh          $t9, 0x36($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X36));
    skip_0:
    // 0x8008A9FC: lh          $t5, 0x2312($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X2312));
    // 0x8008AA00: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x8008AA04: addiu       $t7, $t7, 0x5770
    ctx->r15 = ADD32(ctx->r15, 0X5770);
    // 0x8008AA08: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8008AA0C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8008AA10: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8008AA14: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008AA18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008AA1C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8008AA20: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008AA24: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8008AA28: lh          $t8, 0x2BE($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X2BE));
    // 0x8008AA2C: bltzl       $t8, L_8008AA68
    if (SIGNED(ctx->r24) < 0) {
        // 0x8008AA30: lw          $s0, 0x0($t0)
        ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
            goto L_8008AA68;
    }
    goto skip_1;
    // 0x8008AA30: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    skip_1:
    // 0x8008AA34: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008AA38: lw          $t9, 0x238($v1)
    ctx->r25 = S32(MEM_W(ctx->r3, 0X238));
    // 0x8008AA3C: lw          $t3, 0x23C($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X23C));
    // 0x8008AA40: lw          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008AA44: lw          $t4, 0x4($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008AA48: subu        $a0, $t9, $t2
    ctx->r4 = SUB32(ctx->r25, ctx->r10);
    // 0x8008AA4C: jal         0x80092024
    // 0x8008AA50: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    getangle(rdram, ctx);
        goto after_0;
    // 0x8008AA50: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    after_0:
    // 0x8008AA54: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8008AA58: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8008AA5C: b           L_8008AA90
    // 0x8008AA60: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
        goto L_8008AA90;
    // 0x8008AA60: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8008AA64: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
L_8008AA68:
    // 0x8008AA68: lw          $t6, 0x214($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X214));
    // 0x8008AA6C: lw          $t8, 0x218($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X218));
    // 0x8008AA70: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008AA74: lw          $t9, 0x4($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008AA78: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x8008AA7C: jal         0x80092024
    // 0x8008AA80: subu        $a1, $t8, $t9
    ctx->r5 = SUB32(ctx->r24, ctx->r25);
    getangle(rdram, ctx);
        goto after_1;
    // 0x8008AA80: subu        $a1, $t8, $t9
    ctx->r5 = SUB32(ctx->r24, ctx->r25);
    after_1:
    // 0x8008AA84: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8008AA88: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8008AA8C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8008AA90:
    // 0x8008AA90: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8008AA94: lw          $t3, 0x231C($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X231C));
    // 0x8008AA98: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8008AA9C: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8008AAA0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8008AAA4: jal         0x80089834
    // 0x8008AAA8: lh          $a0, 0x14($t3)
    ctx->r4 = S32(MEM_H(ctx->r11, 0X14));
    getincangle(rdram, ctx);
        goto after_2;
    // 0x8008AAA8: lh          $a0, 0x14($t3)
    ctx->r4 = S32(MEM_H(ctx->r11, 0X14));
    after_2:
    // 0x8008AAAC: sra         $v1, $v0, 2
    ctx->r3 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8008AAB0: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x8008AAB4: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x8008AAB8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008AABC: sra         $t5, $t0, 16
    ctx->r13 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8008AAC0: slti        $at, $t6, -0x7
    ctx->r1 = SIGNED(ctx->r14) < -0X7 ? 1 : 0;
    // 0x8008AAC4: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8008AAC8: bne         $at, $zero, L_8008AADC
    if (ctx->r1 != 0) {
        // 0x8008AACC: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_8008AADC;
    }
    // 0x8008AACC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008AAD0: bgez        $t6, L_8008AADC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008AAD4: nop
    
            goto L_8008AADC;
    }
    // 0x8008AAD4: nop

    // 0x8008AAD8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8008AADC:
    // 0x8008AADC: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008AAE0: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008AAE4: lh          $t7, 0x14($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X14));
    // 0x8008AAE8: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8008AAEC: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8008AAF0: addiu       $t0, $t0, 0x231C
    ctx->r8 = ADD32(ctx->r8, 0X231C);
    // 0x8008AAF4: sh          $t8, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r24;
    // 0x8008AAF8: lh          $t9, 0x36($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X36));
L_8008AAFC:
    // 0x8008AAFC: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x8008AB00: andi        $t2, $t9, 0x20
    ctx->r10 = ctx->r25 & 0X20;
    // 0x8008AB04: beql        $t2, $zero, L_8008AB44
    if (ctx->r10 == 0) {
        // 0x8008AB08: lh          $t5, 0x36($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0X36));
            goto L_8008AB44;
    }
    goto skip_2;
    // 0x8008AB08: lh          $t5, 0x36($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X36));
    skip_2:
    // 0x8008AB0C: lw          $t4, 0x2318($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, 0X2318));
    // 0x8008AB10: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008AB14: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8008AB18: lw          $t5, 0x0($t4)
    ctx->r13 = S32(MEM_W(ctx->r12, 0X0));
    // 0x8008AB1C: lh          $t3, 0x14($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X14));
    // 0x8008AB20: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8008AB24: andi        $t7, $t6, 0x7FF
    ctx->r15 = ctx->r14 & 0X7FF;
    // 0x8008AB28: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008AB2C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008AB30: lh          $t9, -0x9A0($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X9A0));
    // 0x8008AB34: sra         $t2, $t9, 6
    ctx->r10 = S32(SIGNED(ctx->r25) >> 6);
    // 0x8008AB38: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x8008AB3C: sh          $t4, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r12;
    // 0x8008AB40: lh          $t5, 0x36($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X36));
L_8008AB44:
    // 0x8008AB44: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8008AB48: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x8008AB4C: beql        $t6, $zero, L_8008AC64
    if (ctx->r14 == 0) {
        // 0x8008AB50: lh          $t4, 0x36($sp)
        ctx->r12 = S32(MEM_H(ctx->r29, 0X36));
            goto L_8008AC64;
    }
    goto skip_3;
    // 0x8008AB50: lh          $t4, 0x36($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X36));
    skip_3:
    // 0x8008AB54: lh          $t7, 0x2312($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X2312));
    // 0x8008AB58: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x8008AB5C: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x8008AB60: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008AB64: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008AB68: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8008AB6C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008AB70: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008AB74: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008AB78: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008AB7C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8008AB80: lh          $t3, 0x2BE($v1)
    ctx->r11 = S32(MEM_H(ctx->r3, 0X2BE));
    // 0x8008AB84: bltzl       $t3, L_8008ABC0
    if (SIGNED(ctx->r11) < 0) {
        // 0x8008AB88: lw          $s0, 0x0($t0)
        ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
            goto L_8008ABC0;
    }
    goto skip_4;
    // 0x8008AB88: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    skip_4:
    // 0x8008AB8C: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008AB90: lw          $t2, 0x238($v1)
    ctx->r10 = S32(MEM_W(ctx->r3, 0X238));
    // 0x8008AB94: lw          $t5, 0x23C($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X23C));
    // 0x8008AB98: lw          $t4, 0x0($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008AB9C: lw          $t6, 0x4($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008ABA0: subu        $a0, $t2, $t4
    ctx->r4 = SUB32(ctx->r10, ctx->r12);
    // 0x8008ABA4: jal         0x80092024
    // 0x8008ABA8: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    getangle(rdram, ctx);
        goto after_3;
    // 0x8008ABA8: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    after_3:
    // 0x8008ABAC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8008ABB0: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8008ABB4: b           L_8008ABE8
    // 0x8008ABB8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
        goto L_8008ABE8;
    // 0x8008ABB8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x8008ABBC: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
L_8008ABC0:
    // 0x8008ABC0: lw          $t8, 0x214($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X214));
    // 0x8008ABC4: lw          $t3, 0x218($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X218));
    // 0x8008ABC8: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008ABCC: lw          $t2, 0x4($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008ABD0: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    // 0x8008ABD4: jal         0x80092024
    // 0x8008ABD8: subu        $a1, $t3, $t2
    ctx->r5 = SUB32(ctx->r11, ctx->r10);
    getangle(rdram, ctx);
        goto after_4;
    // 0x8008ABD8: subu        $a1, $t3, $t2
    ctx->r5 = SUB32(ctx->r11, ctx->r10);
    after_4:
    // 0x8008ABDC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8008ABE0: sra         $t4, $s0, 16
    ctx->r12 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8008ABE4: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_8008ABE8:
    // 0x8008ABE8: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8008ABEC: lw          $t5, 0x231C($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, 0X231C));
    // 0x8008ABF0: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8008ABF4: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8008ABF8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8008ABFC: jal         0x80089834
    // 0x8008AC00: lh          $a0, 0x14($t5)
    ctx->r4 = S32(MEM_H(ctx->r13, 0X14));
    getincangle(rdram, ctx);
        goto after_5;
    // 0x8008AC00: lh          $a0, 0x14($t5)
    ctx->r4 = S32(MEM_H(ctx->r13, 0X14));
    after_5:
    // 0x8008AC04: jal         0x80091A50
    // 0x8008AC08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    ksgn(rdram, ctx);
        goto after_6;
    // 0x8008AC08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8008AC0C: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x8008AC10: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x8008AC14: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x8008AC18: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008AC1C: sra         $t7, $t0, 16
    ctx->r15 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8008AC20: slti        $at, $t8, -0x1F
    ctx->r1 = SIGNED(ctx->r24) < -0X1F ? 1 : 0;
    // 0x8008AC24: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x8008AC28: bne         $at, $zero, L_8008AC44
    if (ctx->r1 != 0) {
        // 0x8008AC2C: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8008AC44;
    }
    // 0x8008AC2C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8008AC30: bgez        $t8, L_8008AC44
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008AC34: lui         $t9, 0x8027
        ctx->r25 = S32(0X8027 << 16);
            goto L_8008AC44;
    }
    // 0x8008AC34: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8008AC38: lw          $t9, 0x231C($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X231C));
    // 0x8008AC3C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008AC40: sh          $s0, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r16;
L_8008AC44:
    // 0x8008AC44: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008AC48: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008AC4C: lh          $t3, 0x14($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X14));
    // 0x8008AC50: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x8008AC54: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8008AC58: addiu       $t0, $t0, 0x231C
    ctx->r8 = ADD32(ctx->r8, 0X231C);
    // 0x8008AC5C: sh          $t2, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r10;
    // 0x8008AC60: lh          $t4, 0x36($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X36));
L_8008AC64:
    // 0x8008AC64: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x8008AC68: addiu       $a3, $zero, 0x300
    ctx->r7 = ADD32(0, 0X300);
    // 0x8008AC6C: andi        $t5, $t4, 0x101
    ctx->r13 = ctx->r12 & 0X101;
    // 0x8008AC70: bnel        $t5, $at, L_8008ACC0
    if (ctx->r13 != ctx->r1) {
        // 0x8008AC74: lh          $t8, 0x36($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0X36));
            goto L_8008ACC0;
    }
    goto skip_5;
    // 0x8008AC74: lh          $t8, 0x36($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X36));
    skip_5:
    // 0x8008AC78: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8008AC7C: lw          $t6, 0x2318($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, 0X2318));
    // 0x8008AC80: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8008AC84: lw          $v0, 0x0($t6)
    ctx->r2 = S32(MEM_W(ctx->r14, 0X0));
    // 0x8008AC88: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8008AC8C: beq         $at, $zero, L_8008ACBC
    if (ctx->r1 == 0) {
        // 0x8008AC90: sll         $t8, $v0, 4
        ctx->r24 = S32(ctx->r2 << 4);
            goto L_8008ACBC;
    }
    // 0x8008AC90: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8008AC94: addiu       $t9, $t8, 0x200
    ctx->r25 = ADD32(ctx->r24, 0X200);
    // 0x8008AC98: andi        $t3, $t9, 0x7FF
    ctx->r11 = ctx->r25 & 0X7FF;
    // 0x8008AC9C: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008ACA0: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x8008ACA4: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8008ACA8: lh          $t4, -0x9A0($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X9A0));
    // 0x8008ACAC: lh          $t7, 0x1C($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X1C));
    // 0x8008ACB0: sra         $t5, $t4, 5
    ctx->r13 = S32(SIGNED(ctx->r12) >> 5);
    // 0x8008ACB4: subu        $t6, $t7, $t5
    ctx->r14 = SUB32(ctx->r15, ctx->r13);
    // 0x8008ACB8: sh          $t6, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r14;
L_8008ACBC:
    // 0x8008ACBC: lh          $t8, 0x36($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0X36));
L_8008ACC0:
    // 0x8008ACC0: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8008ACC4: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x8008ACC8: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x8008ACCC: beq         $t9, $zero, L_8008ADE8
    if (ctx->r25 == 0) {
        // 0x8008ACD0: nop
    
            goto L_8008ADE8;
    }
    // 0x8008ACD0: nop

    // 0x8008ACD4: lh          $t3, 0x2312($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, 0X2312));
    // 0x8008ACD8: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x8008ACDC: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008ACE0: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x8008ACE4: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8008ACE8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8008ACEC: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8008ACF0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008ACF4: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8008ACF8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008ACFC: addu        $v1, $t2, $t4
    ctx->r3 = ADD32(ctx->r10, ctx->r12);
    // 0x8008AD00: lw          $t7, 0x24C($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X24C));
    // 0x8008AD04: lw          $t8, 0x250($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X250));
    // 0x8008AD08: lw          $t6, 0x214($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X214));
    // 0x8008AD0C: div         $zero, $t7, $a3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r7)));
    // 0x8008AD10: mflo        $t5
    ctx->r13 = lo;
    // 0x8008AD14: lw          $t3, 0x218($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X218));
    // 0x8008AD18: bne         $a3, $zero, L_8008AD24
    if (ctx->r7 != 0) {
        // 0x8008AD1C: nop
    
            goto L_8008AD24;
    }
    // 0x8008AD1C: nop

    // 0x8008AD20: break       7
    do_break(2148052256);
L_8008AD24:
    // 0x8008AD24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008AD28: bne         $a3, $at, L_8008AD3C
    if (ctx->r7 != ctx->r1) {
        // 0x8008AD2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008AD3C;
    }
    // 0x8008AD2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008AD30: bne         $t7, $at, L_8008AD3C
    if (ctx->r15 != ctx->r1) {
        // 0x8008AD34: nop
    
            goto L_8008AD3C;
    }
    // 0x8008AD34: nop

    // 0x8008AD38: break       6
    do_break(2148052280);
L_8008AD3C:
    // 0x8008AD3C: div         $zero, $t8, $a3
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r7)));
    // 0x8008AD40: lw          $t4, 0x4($s0)
    ctx->r12 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008AD44: lw          $t2, 0x0($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008AD48: mflo        $t9
    ctx->r25 = lo;
    // 0x8008AD4C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008AD50: bne         $a3, $zero, L_8008AD5C
    if (ctx->r7 != 0) {
        // 0x8008AD54: nop
    
            goto L_8008AD5C;
    }
    // 0x8008AD54: nop

    // 0x8008AD58: break       7
    do_break(2148052312);
L_8008AD5C:
    // 0x8008AD5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008AD60: bne         $a3, $at, L_8008AD74
    if (ctx->r7 != ctx->r1) {
        // 0x8008AD64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008AD74;
    }
    // 0x8008AD64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008AD68: bne         $t8, $at, L_8008AD74
    if (ctx->r24 != ctx->r1) {
        // 0x8008AD6C: nop
    
            goto L_8008AD74;
    }
    // 0x8008AD6C: nop

    // 0x8008AD70: break       6
    do_break(2148052336);
L_8008AD74:
    // 0x8008AD74: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    // 0x8008AD78: subu        $a1, $a2, $t4
    ctx->r5 = SUB32(ctx->r6, ctx->r12);
    // 0x8008AD7C: jal         0x80092024
    // 0x8008AD80: subu        $a0, $v0, $t2
    ctx->r4 = SUB32(ctx->r2, ctx->r10);
    getangle(rdram, ctx);
        goto after_7;
    // 0x8008AD80: subu        $a0, $v0, $t2
    ctx->r4 = SUB32(ctx->r2, ctx->r10);
    after_7:
    // 0x8008AD84: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8008AD88: lw          $t7, 0x231C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, 0X231C));
    // 0x8008AD8C: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8008AD90: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8008AD94: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8008AD98: jal         0x80089834
    // 0x8008AD9C: lh          $a0, 0x14($t7)
    ctx->r4 = S32(MEM_H(ctx->r15, 0X14));
    getincangle(rdram, ctx);
        goto after_8;
    // 0x8008AD9C: lh          $a0, 0x14($t7)
    ctx->r4 = S32(MEM_H(ctx->r15, 0X14));
    after_8:
    // 0x8008ADA0: sra         $v1, $v0, 2
    ctx->r3 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8008ADA4: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x8008ADA8: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x8008ADAC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008ADB0: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8008ADB4: slti        $at, $t8, -0x7
    ctx->r1 = SIGNED(ctx->r24) < -0X7 ? 1 : 0;
    // 0x8008ADB8: bne         $at, $zero, L_8008ADCC
    if (ctx->r1 != 0) {
        // 0x8008ADBC: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_8008ADCC;
    }
    // 0x8008ADBC: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8008ADC0: bgez        $t8, L_8008ADCC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008ADC4: nop
    
            goto L_8008ADCC;
    }
    // 0x8008ADC4: nop

    // 0x8008ADC8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8008ADCC:
    // 0x8008ADCC: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008ADD0: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008ADD4: lh          $t9, 0x14($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X14));
    // 0x8008ADD8: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x8008ADDC: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8008ADE0: addiu       $t0, $t0, 0x231C
    ctx->r8 = ADD32(ctx->r8, 0X231C);
    // 0x8008ADE4: sh          $t3, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r11;
L_8008ADE8:
    // 0x8008ADE8: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8008ADEC: lw          $t2, 0x2318($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X2318));
    // 0x8008ADF0: lh          $t4, 0x36($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X36));
    // 0x8008ADF4: lw          $v0, 0x4($t2)
    ctx->r2 = S32(MEM_W(ctx->r10, 0X4));
    // 0x8008ADF8: beq         $v0, $zero, L_8008AE08
    if (ctx->r2 == 0) {
        // 0x8008ADFC: nop
    
            goto L_8008AE08;
    }
    // 0x8008ADFC: nop

    // 0x8008AE00: bne         $t4, $zero, L_8008AEB0
    if (ctx->r12 != 0) {
        // 0x8008AE04: lh          $t9, 0x36($sp)
        ctx->r25 = S32(MEM_H(ctx->r29, 0X36));
            goto L_8008AEB0;
    }
    // 0x8008AE04: lh          $t9, 0x36($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X36));
L_8008AE08:
    // 0x8008AE08: jal         0x80099ED4
    // 0x8008AE0C: lw          $a0, 0x0($t0)
    ctx->r4 = S32(MEM_W(ctx->r8, 0X0));
    badguy(rdram, ctx);
        goto after_9;
    // 0x8008AE0C: lw          $a0, 0x0($t0)
    ctx->r4 = S32(MEM_W(ctx->r8, 0X0));
    after_9:
    // 0x8008AE10: beq         $v0, $zero, L_8008AE24
    if (ctx->r2 == 0) {
        // 0x8008AE14: lui         $s0, 0x8027
        ctx->r16 = S32(0X8027 << 16);
            goto L_8008AE24;
    }
    // 0x8008AE14: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008AE18: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008AE1C: lh          $t7, 0x22($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X22));
    // 0x8008AE20: blez        $t7, L_8008AE68
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8008AE24: lui         $t5, 0x8027
        ctx->r13 = S32(0X8027 << 16);
            goto L_8008AE68;
    }
L_8008AE24:
    // 0x8008AE24: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8008AE28: lh          $t5, 0x2310($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X2310));
    // 0x8008AE2C: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008AE30: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008AE34: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8008AE38: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x8008AE3C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008AE40: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8008AE44: addiu       $t8, $t8, -0x5C00
    ctx->r24 = ADD32(ctx->r24, -0X5C00);
    // 0x8008AE48: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x8008AE4C: lw          $t3, 0x24($v0)
    ctx->r11 = S32(MEM_W(ctx->r2, 0X24));
    // 0x8008AE50: lw          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008AE54: bne         $t9, $t3, L_8008AE68
    if (ctx->r25 != ctx->r11) {
        // 0x8008AE58: nop
    
            goto L_8008AE68;
    }
    // 0x8008AE58: nop

    // 0x8008AE5C: lw          $t2, 0x4($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008AE60: lw          $t4, 0x28($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X28));
    // 0x8008AE64: beq         $t2, $t4, L_8008B6D8
    if (ctx->r10 == ctx->r12) {
        // 0x8008AE68: lui         $a0, 0x8027
        ctx->r4 = S32(0X8027 << 16);
            goto L_8008B6D8;
    }
L_8008AE68:
    // 0x8008AE68: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008AE6C: lh          $a0, 0x2310($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2310));
    // 0x8008AE70: lw          $t6, 0x0($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008AE74: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x8008AE78: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8008AE7C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8008AE80: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8008AE84: addiu       $t5, $t5, -0x5C00
    ctx->r13 = ADD32(ctx->r13, -0X5C00);
    // 0x8008AE88: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
    // 0x8008AE8C: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x8008AE90: lw          $t8, 0x4($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008AE94: sw          $t8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r24;
    // 0x8008AE98: lw          $a3, 0x8($s0)
    ctx->r7 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008AE9C: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008AEA0: jal         0x8009219C
    // 0x8008AEA4: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    setsprite(rdram, ctx);
        goto after_10;
    // 0x8008AEA4: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    after_10:
    // 0x8008AEA8: b           L_8008B6DC
    // 0x8008AEAC: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
        goto L_8008B6DC;
    // 0x8008AEAC: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_8008AEB0:
    // 0x8008AEB0: andi        $t3, $t9, 0x2
    ctx->r11 = ctx->r25 & 0X2;
    // 0x8008AEB4: beq         $t3, $zero, L_8008AED8
    if (ctx->r11 == 0) {
        // 0x8008AEB8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8008AED8;
    }
    // 0x8008AEB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008AEBC: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008AEC0: lw          $t2, 0x0($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8008AEC4: lh          $v1, 0x18($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
    // 0x8008AEC8: subu        $t4, $t2, $v1
    ctx->r12 = SUB32(ctx->r10, ctx->r3);
    // 0x8008AECC: sra         $t7, $t4, 1
    ctx->r15 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8008AED0: addu        $t5, $v1, $t7
    ctx->r13 = ADD32(ctx->r3, ctx->r15);
    // 0x8008AED4: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
L_8008AED8:
    // 0x8008AED8: lh          $t6, 0x36($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X36));
    // 0x8008AEDC: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x8008AEE0: beql        $t8, $zero, L_8008AF0C
    if (ctx->r24 == 0) {
        // 0x8008AEE4: lh          $t5, 0x36($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0X36));
            goto L_8008AF0C;
    }
    goto skip_6;
    // 0x8008AEE4: lh          $t5, 0x36($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X36));
    skip_6:
    // 0x8008AEE8: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    // 0x8008AEEC: lw          $t9, 0x4($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X4));
    // 0x8008AEF0: lh          $v0, 0x1C($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X1C));
    // 0x8008AEF4: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8008AEF8: subu        $t2, $t3, $v0
    ctx->r10 = SUB32(ctx->r11, ctx->r2);
    // 0x8008AEFC: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8008AF00: addu        $t7, $v0, $t4
    ctx->r15 = ADD32(ctx->r2, ctx->r12);
    // 0x8008AF04: sh          $t7, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r15;
    // 0x8008AF08: lh          $t5, 0x36($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X36));
L_8008AF0C:
    // 0x8008AF0C: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x8008AF10: beql        $t6, $zero, L_8008AF2C
    if (ctx->r14 == 0) {
        // 0x8008AF14: lw          $s0, 0x0($t0)
        ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
            goto L_8008AF2C;
    }
    goto skip_7;
    // 0x8008AF14: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
    skip_7:
    // 0x8008AF18: jal         0x80089E48
    // 0x8008AF1C: lw          $a0, 0x0($t0)
    ctx->r4 = S32(MEM_W(ctx->r8, 0X0));
    dodge(rdram, ctx);
        goto after_11;
    // 0x8008AF1C: lw          $a0, 0x0($t0)
    ctx->r4 = S32(MEM_W(ctx->r8, 0X0));
    after_11:
    // 0x8008AF20: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8008AF24: addiu       $t0, $t0, 0x231C
    ctx->r8 = ADD32(ctx->r8, 0X231C);
    // 0x8008AF28: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
L_8008AF2C:
    // 0x8008AF2C: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x8008AF30: lh          $t8, 0xE($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0XE));
    // 0x8008AF34: beql        $t8, $at, L_8008AF58
    if (ctx->r24 == ctx->r1) {
        // 0x8008AF38: lh          $v1, 0x18($s0)
        ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
            goto L_8008AF58;
    }
    goto skip_8;
    // 0x8008AF38: lh          $v1, 0x18($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
    skip_8:
    // 0x8008AF3C: jal         0x8008A540
    // 0x8008AF40: lh          $a0, 0x36($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X36));
    alterang(rdram, ctx);
        goto after_12;
    // 0x8008AF40: lh          $a0, 0x36($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X36));
    after_12:
    // 0x8008AF44: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008AF48: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x8008AF4C: addiu       $t0, $t0, 0x231C
    ctx->r8 = ADD32(ctx->r8, 0X231C);
    // 0x8008AF50: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008AF54: lh          $v1, 0x18($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
L_8008AF58:
    // 0x8008AF58: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
    // 0x8008AF5C: bne         $at, $zero, L_8008AF74
    if (ctx->r1 != 0) {
        // 0x8008AF60: slti        $at, $v1, 0x6
        ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
            goto L_8008AF74;
    }
    // 0x8008AF60: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8008AF64: beq         $at, $zero, L_8008AF74
    if (ctx->r1 == 0) {
        // 0x8008AF68: nop
    
            goto L_8008AF74;
    }
    // 0x8008AF68: nop

    // 0x8008AF6C: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x8008AF70: lw          $s0, 0x0($t0)
    ctx->r16 = S32(MEM_W(ctx->r8, 0X0));
L_8008AF74:
    // 0x8008AF74: jal         0x80099ED4
    // 0x8008AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    badguy(rdram, ctx);
        goto after_13;
    // 0x8008AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8008AF7C: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008AF80: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008AF84: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8008AF88: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x8008AF8C: lh          $v1, 0x18($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
    // 0x8008AF90: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8008AF94: bne         $v1, $zero, L_8008AFA8
    if (ctx->r3 != 0) {
        // 0x8008AF98: nop
    
            goto L_8008AFA8;
    }
    // 0x8008AF98: nop

    // 0x8008AF9C: lh          $t9, 0x1C($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X1C));
    // 0x8008AFA0: beql        $t9, $zero, L_8008B634
    if (ctx->r25 == 0) {
        // 0x8008AFA4: lh          $t4, 0x36($sp)
        ctx->r12 = S32(MEM_H(ctx->r29, 0X36));
            goto L_8008B634;
    }
    goto skip_9;
    // 0x8008AFA4: lh          $t4, 0x36($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X36));
    skip_9:
L_8008AFA8:
    // 0x8008AFA8: beql        $t2, $zero, L_8008B250
    if (ctx->r10 == 0) {
        // 0x8008AFAC: lh          $t6, 0xE($s0)
        ctx->r14 = S32(MEM_H(ctx->r16, 0XE));
            goto L_8008B250;
    }
    goto skip_10;
    // 0x8008AFAC: lh          $t6, 0xE($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0XE));
    skip_10:
    // 0x8008AFB0: lh          $v0, 0xE($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0XE));
    // 0x8008AFB4: addiu       $at, $zero, 0x938
    ctx->r1 = ADD32(0, 0X938);
    // 0x8008AFB8: beq         $v0, $at, L_8008B24C
    if (ctx->r2 == ctx->r1) {
        // 0x8008AFBC: addiu       $at, $zero, 0x758
        ctx->r1 = ADD32(0, 0X758);
            goto L_8008B24C;
    }
    // 0x8008AFBC: addiu       $at, $zero, 0x758
    ctx->r1 = ADD32(0, 0X758);
    // 0x8008AFC0: beq         $v0, $at, L_8008AFD0
    if (ctx->r2 == ctx->r1) {
        // 0x8008AFC4: addiu       $at, $zero, 0x780
        ctx->r1 = ADD32(0, 0X780);
            goto L_8008AFD0;
    }
    // 0x8008AFC4: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x8008AFC8: bnel        $v0, $at, L_8008B198
    if (ctx->r2 != ctx->r1) {
        // 0x8008AFCC: addiu       $at, $zero, 0x974
        ctx->r1 = ADD32(0, 0X974);
            goto L_8008B198;
    }
    goto skip_11;
    // 0x8008AFCC: addiu       $at, $zero, 0x974
    ctx->r1 = ADD32(0, 0X974);
    skip_11:
L_8008AFD0:
    // 0x8008AFD0: lh          $t4, 0x22($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X22));
    // 0x8008AFD4: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x8008AFD8: blezl       $t4, L_8008B198
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8008AFDC: addiu       $at, $zero, 0x974
        ctx->r1 = ADD32(0, 0X974);
            goto L_8008B198;
    }
    goto skip_12;
    // 0x8008AFDC: addiu       $at, $zero, 0x974
    ctx->r1 = ADD32(0, 0X974);
    skip_12:
    // 0x8008AFE0: bnel        $v0, $at, L_8008B0C4
    if (ctx->r2 != ctx->r1) {
        // 0x8008AFE4: lh          $t7, 0x1C($s0)
        ctx->r15 = S32(MEM_H(ctx->r16, 0X1C));
            goto L_8008B0C4;
    }
    goto skip_13;
    // 0x8008AFE4: lh          $t7, 0x1C($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X1C));
    skip_13:
    // 0x8008AFE8: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    // 0x8008AFEC: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008AFF0: jal         0x80098E64
    // 0x8008AFF4: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    getceilzofslope(rdram, ctx);
        goto after_14;
    // 0x8008AFF4: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    after_14:
    // 0x8008AFF8: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8008AFFC: lh          $t7, 0x2310($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X2310));
    // 0x8008B000: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B004: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B008: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x8008B00C: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8008B010: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8008B014: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8008B018: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8008B01C: sw          $v0, -0x5BE8($at)
    MEM_W(-0X5BE8, ctx->r1) = ctx->r2;
    // 0x8008B020: lw          $t6, 0x8($s0)
    ctx->r14 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008B024: addiu       $t9, $v0, 0x5000
    ctx->r25 = ADD32(ctx->r2, 0X5000);
    // 0x8008B028: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8008B02C: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x8008B030: slti        $at, $t8, 0x5000
    ctx->r1 = SIGNED(ctx->r24) < 0X5000 ? 1 : 0;
    // 0x8008B034: beql        $at, $zero, L_8008B054
    if (ctx->r1 == 0) {
        // 0x8008B038: lh          $a0, 0x10($s0)
        ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
            goto L_8008B054;
    }
    goto skip_14;
    // 0x8008B038: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    skip_14:
    // 0x8008B03C: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x8008B040: lw          $t3, 0x231C($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X231C));
    // 0x8008B044: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B048: sh          $zero, 0x1C($t3)
    MEM_H(0X1C, ctx->r11) = 0;
    // 0x8008B04C: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B050: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
L_8008B054:
    // 0x8008B054: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008B058: jal         0x80098FB4
    // 0x8008B05C: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    getflorzofslope(rdram, ctx);
        goto after_15;
    // 0x8008B05C: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    after_15:
    // 0x8008B060: lui         $t2, 0x8027
    ctx->r10 = S32(0X8027 << 16);
    // 0x8008B064: lh          $t2, 0x2310($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X2310));
    // 0x8008B068: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B06C: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B070: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x8008B074: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8008B078: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8008B07C: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8008B080: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8008B084: sw          $v0, -0x5BEC($at)
    MEM_W(-0X5BEC, ctx->r1) = ctx->r2;
    // 0x8008B088: lw          $a0, 0x8($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008B08C: addiu       $v1, $v0, -0x800
    ctx->r3 = ADD32(ctx->r2, -0X800);
    // 0x8008B090: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8008B094: beq         $at, $zero, L_8008B244
    if (ctx->r1 == 0) {
        // 0x8008B098: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8008B244;
    }
    // 0x8008B098: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8008B09C: beql        $at, $zero, L_8008B0B4
    if (ctx->r1 == 0) {
        // 0x8008B0A0: sh          $zero, 0x1C($s0)
        MEM_H(0X1C, ctx->r16) = 0;
            goto L_8008B0B4;
    }
    goto skip_15;
    // 0x8008B0A0: sh          $zero, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = 0;
    skip_15:
    // 0x8008B0A4: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x8008B0A8: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B0AC: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B0B0: sh          $zero, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = 0;
L_8008B0B4:
    // 0x8008B0B4: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B0B8: b           L_8008B244
    // 0x8008B0BC: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
        goto L_8008B244;
    // 0x8008B0BC: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B0C0: lh          $t7, 0x1C($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X1C));
L_8008B0C4:
    // 0x8008B0C4: blezl       $t7, L_8008B12C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8008B0C8: lh          $a0, 0x10($s0)
        ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
            goto L_8008B12C;
    }
    goto skip_16;
    // 0x8008B0C8: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    skip_16:
    // 0x8008B0CC: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    // 0x8008B0D0: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008B0D4: jal         0x80098FB4
    // 0x8008B0D8: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    getflorzofslope(rdram, ctx);
        goto after_16;
    // 0x8008B0D8: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    after_16:
    // 0x8008B0DC: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8008B0E0: lh          $t5, 0x2310($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X2310));
    // 0x8008B0E4: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B0E8: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B0EC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8008B0F0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008B0F4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8008B0F8: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8008B0FC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008B100: sw          $v0, -0x5BEC($at)
    MEM_W(-0X5BEC, ctx->r1) = ctx->r2;
    // 0x8008B104: lw          $t8, 0x8($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008B108: addiu       $v1, $v0, -0x1E00
    ctx->r3 = ADD32(ctx->r2, -0X1E00);
    // 0x8008B10C: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8008B110: beq         $at, $zero, L_8008B244
    if (ctx->r1 == 0) {
        // 0x8008B114: nop
    
            goto L_8008B244;
    }
    // 0x8008B114: nop

    // 0x8008B118: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x8008B11C: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B120: b           L_8008B244
    // 0x8008B124: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
        goto L_8008B244;
    // 0x8008B124: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B128: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
L_8008B12C:
    // 0x8008B12C: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008B130: jal         0x80098E64
    // 0x8008B134: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    getceilzofslope(rdram, ctx);
        goto after_17;
    // 0x8008B134: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    after_17:
    // 0x8008B138: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8008B13C: lh          $t9, 0x2310($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X2310));
    // 0x8008B140: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B144: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B148: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x8008B14C: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8008B150: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008B154: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8008B158: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8008B15C: sw          $v0, -0x5BE8($at)
    MEM_W(-0X5BE8, ctx->r1) = ctx->r2;
    // 0x8008B160: lw          $t2, 0x8($s0)
    ctx->r10 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008B164: addiu       $t7, $v0, 0x3200
    ctx->r15 = ADD32(ctx->r2, 0X3200);
    // 0x8008B168: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8008B16C: subu        $t4, $t2, $v0
    ctx->r12 = SUB32(ctx->r10, ctx->r2);
    // 0x8008B170: slti        $at, $t4, 0x3200
    ctx->r1 = SIGNED(ctx->r12) < 0X3200 ? 1 : 0;
    // 0x8008B174: beq         $at, $zero, L_8008B244
    if (ctx->r1 == 0) {
        // 0x8008B178: nop
    
            goto L_8008B244;
    }
    // 0x8008B178: nop

    // 0x8008B17C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x8008B180: lw          $t5, 0x231C($t5)
    ctx->r13 = S32(MEM_W(ctx->r13, 0X231C));
    // 0x8008B184: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B188: sh          $zero, 0x1C($t5)
    MEM_H(0X1C, ctx->r13) = 0;
    // 0x8008B18C: b           L_8008B244
    // 0x8008B190: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
        goto L_8008B244;
    // 0x8008B190: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B194: addiu       $at, $zero, 0x974
    ctx->r1 = ADD32(0, 0X974);
L_8008B198:
    // 0x8008B198: beq         $v0, $at, L_8008B244
    if (ctx->r2 == ctx->r1) {
        // 0x8008B19C: nop
    
            goto L_8008B244;
    }
    // 0x8008B19C: nop

    // 0x8008B1A0: lh          $v0, 0x1C($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X1C));
    // 0x8008B1A4: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8008B1A8: blez        $v0, L_8008B1EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008B1AC: nop
    
            goto L_8008B1EC;
    }
    // 0x8008B1AC: nop

    // 0x8008B1B0: lh          $t6, 0x2310($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X2310));
    // 0x8008B1B4: lui         $v1, 0x8028
    ctx->r3 = S32(0X8028 << 16);
    // 0x8008B1B8: lw          $t9, 0x8($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008B1BC: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8008B1C0: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8008B1C4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8008B1C8: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8008B1CC: lw          $v1, -0x5BEC($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, -0X5BEC));
    // 0x8008B1D0: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008B1D4: beq         $at, $zero, L_8008B1EC
    if (ctx->r1 == 0) {
        // 0x8008B1D8: nop
    
            goto L_8008B1EC;
    }
    // 0x8008B1D8: nop

    // 0x8008B1DC: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x8008B1E0: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B1E4: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B1E8: lh          $v0, 0x1C($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X1C));
L_8008B1EC:
    // 0x8008B1EC: bgez        $v0, L_8008B244
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008B1F0: nop
    
            goto L_8008B244;
    }
    // 0x8008B1F0: nop

    // 0x8008B1F4: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    // 0x8008B1F8: lw          $a1, 0x0($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008B1FC: jal         0x80098E64
    // 0x8008B200: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    getceilzofslope(rdram, ctx);
        goto after_18;
    // 0x8008B200: lw          $a2, 0x4($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X4));
    after_18:
    // 0x8008B204: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B208: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B20C: addiu       $t4, $v0, 0x4200
    ctx->r12 = ADD32(ctx->r2, 0X4200);
    // 0x8008B210: lw          $t3, 0x8($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008B214: subu        $t2, $t3, $v0
    ctx->r10 = SUB32(ctx->r11, ctx->r2);
    // 0x8008B218: slti        $at, $t2, 0x4200
    ctx->r1 = SIGNED(ctx->r10) < 0X4200 ? 1 : 0;
    // 0x8008B21C: beq         $at, $zero, L_8008B244
    if (ctx->r1 == 0) {
        // 0x8008B220: nop
    
            goto L_8008B244;
    }
    // 0x8008B220: nop

    // 0x8008B224: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x8008B228: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B22C: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B230: lh          $t7, 0x1C($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X1C));
    // 0x8008B234: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8008B238: sh          $t5, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r13;
    // 0x8008B23C: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B240: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
L_8008B244:
    // 0x8008B244: b           L_8008B2A0
    // 0x8008B248: lh          $v1, 0x18($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
        goto L_8008B2A0;
    // 0x8008B248: lh          $v1, 0x18($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
L_8008B24C:
    // 0x8008B24C: lh          $t6, 0xE($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0XE));
L_8008B250:
    // 0x8008B250: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x8008B254: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8008B258: bnel        $t6, $at, L_8008B2A4
    if (ctx->r14 != ctx->r1) {
        // 0x8008B25C: lh          $t7, 0x36($sp)
        ctx->r15 = S32(MEM_H(ctx->r29, 0X36));
            goto L_8008B2A4;
    }
    goto skip_17;
    // 0x8008B25C: lh          $t7, 0x36($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X36));
    skip_17:
    // 0x8008B260: lh          $t8, 0x2310($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, 0X2310));
    // 0x8008B264: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x8008B268: lw          $t3, 0x8($s0)
    ctx->r11 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008B26C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8008B270: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008B274: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8008B278: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8008B27C: lw          $v0, -0x5BE8($v0)
    ctx->r2 = S32(MEM_W(ctx->r2, -0X5BE8));
    // 0x8008B280: subu        $t2, $t3, $v0
    ctx->r10 = SUB32(ctx->r11, ctx->r2);
    // 0x8008B284: slti        $at, $t2, 0x2000
    ctx->r1 = SIGNED(ctx->r10) < 0X2000 ? 1 : 0;
    // 0x8008B288: beq         $at, $zero, L_8008B2A0
    if (ctx->r1 == 0) {
        // 0x8008B28C: addiu       $t4, $v0, 0x2000
        ctx->r12 = ADD32(ctx->r2, 0X2000);
            goto L_8008B2A0;
    }
    // 0x8008B28C: addiu       $t4, $v0, 0x2000
    ctx->r12 = ADD32(ctx->r2, 0X2000);
    // 0x8008B290: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x8008B294: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B298: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B29C: lh          $v1, 0x18($s0)
    ctx->r3 = S32(MEM_H(ctx->r16, 0X18));
L_8008B2A0:
    // 0x8008B2A0: lh          $t7, 0x36($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X36));
L_8008B2A4:
    // 0x8008B2A4: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8008B2A8: lh          $t0, 0x14($s0)
    ctx->r8 = S32(MEM_H(ctx->r16, 0X14));
    // 0x8008B2AC: beql        $t7, $zero, L_8008B5AC
    if (ctx->r15 == 0) {
        // 0x8008B2B0: addiu       $t4, $t0, 0x200
        ctx->r12 = ADD32(ctx->r8, 0X200);
            goto L_8008B5AC;
    }
    goto skip_18;
    // 0x8008B2B0: addiu       $t4, $t0, 0x200
    ctx->r12 = ADD32(ctx->r8, 0X200);
    skip_18:
    // 0x8008B2B4: lh          $v0, 0xE($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0XE));
    // 0x8008B2B8: addiu       $at, $zero, 0x938
    ctx->r1 = ADD32(0, 0X938);
    // 0x8008B2BC: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x8008B2C0: beql        $v0, $at, L_8008B5AC
    if (ctx->r2 == ctx->r1) {
        // 0x8008B2C4: addiu       $t4, $t0, 0x200
        ctx->r12 = ADD32(ctx->r8, 0X200);
            goto L_8008B5AC;
    }
    goto skip_19;
    // 0x8008B2C4: addiu       $t4, $t0, 0x200
    ctx->r12 = ADD32(ctx->r8, 0X200);
    skip_19:
    // 0x8008B2C8: lw          $a2, 0x2314($a2)
    ctx->r6 = S32(MEM_W(ctx->r6, 0X2314));
    // 0x8008B2CC: slti        $at, $a2, 0x3C0
    ctx->r1 = SIGNED(ctx->r6) < 0X3C0 ? 1 : 0;
    // 0x8008B2D0: beql        $at, $zero, L_8008B494
    if (ctx->r1 == 0) {
        // 0x8008B2D4: addiu       $at, $zero, 0x758
        ctx->r1 = ADD32(0, 0X758);
            goto L_8008B494;
    }
    goto skip_20;
    // 0x8008B2D4: addiu       $at, $zero, 0x758
    ctx->r1 = ADD32(0, 0X758);
    skip_20:
    // 0x8008B2D8: lbu         $t5, 0x27($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X27);
    // 0x8008B2DC: negu        $t6, $a2
    ctx->r14 = SUB32(0, ctx->r6);
    // 0x8008B2E0: addiu       $t8, $zero, -0x400
    ctx->r24 = ADD32(0, -0X400);
    // 0x8008B2E4: slti        $at, $t5, 0x11
    ctx->r1 = SIGNED(ctx->r13) < 0X11 ? 1 : 0;
    // 0x8008B2E8: bne         $at, $zero, L_8008B490
    if (ctx->r1 != 0) {
        // 0x8008B2EC: lui         $t9, 0x8027
        ctx->r25 = S32(0X8027 << 16);
            goto L_8008B490;
    }
    // 0x8008B2EC: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8008B2F0: lh          $t9, 0x2312($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X2312));
    // 0x8008B2F4: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x8008B2F8: addiu       $t2, $t2, 0x5770
    ctx->r10 = ADD32(ctx->r10, 0X5770);
    // 0x8008B2FC: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x8008B300: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8008B304: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008B308: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8008B30C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008B310: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8008B314: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008B318: addu        $v1, $t3, $t2
    ctx->r3 = ADD32(ctx->r11, ctx->r10);
    // 0x8008B31C: subu        $t1, $t8, $t6
    ctx->r9 = SUB32(ctx->r24, ctx->r14);
    // 0x8008B320: lw          $t8, 0x4($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008B324: lw          $t4, 0x214($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, 0X214));
    // 0x8008B328: lw          $t5, 0x218($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X218));
    // 0x8008B32C: lw          $t7, 0x0($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8008B330: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8008B334: subu        $a1, $t5, $t8
    ctx->r5 = SUB32(ctx->r13, ctx->r24);
    // 0x8008B338: jal         0x80092024
    // 0x8008B33C: subu        $a0, $t4, $t7
    ctx->r4 = SUB32(ctx->r12, ctx->r15);
    getangle(rdram, ctx);
        goto after_19;
    // 0x8008B33C: subu        $a0, $t4, $t7
    ctx->r4 = SUB32(ctx->r12, ctx->r15);
    after_19:
    // 0x8008B340: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8008B344: lw          $t9, 0x2314($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X2314));
    // 0x8008B348: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8008B34C: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8008B350: slti        $at, $t9, 0x200
    ctx->r1 = SIGNED(ctx->r25) < 0X200 ? 1 : 0;
    // 0x8008B354: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8008B358: beq         $at, $zero, L_8008B39C
    if (ctx->r1 == 0) {
        // 0x8008B35C: lw          $t1, 0x2C($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_8008B39C;
    }
    // 0x8008B35C: lw          $t1, 0x2C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8008B360: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8008B364: lh          $t3, 0x2312($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, 0X2312));
    // 0x8008B368: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x8008B36C: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x8008B370: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x8008B374: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8008B378: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8008B37C: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8008B380: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008B384: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8008B388: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008B38C: addu        $v1, $t2, $t4
    ctx->r3 = ADD32(ctx->r10, ctx->r12);
    // 0x8008B390: sw          $zero, 0x24C($v1)
    MEM_W(0X24C, ctx->r3) = 0;
    // 0x8008B394: b           L_8008B484
    // 0x8008B398: sw          $zero, 0x250($v1)
    MEM_W(0X250, ctx->r3) = 0;
        goto L_8008B484;
    // 0x8008B398: sw          $zero, 0x250($v1)
    MEM_W(0X250, ctx->r3) = 0;
L_8008B39C:
    // 0x8008B39C: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8008B3A0: lh          $t7, 0x2312($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X2312));
    // 0x8008B3A4: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x8008B3A8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8008B3AC: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x8008B3B0: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x8008B3B4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8008B3B8: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8008B3BC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B3C0: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x8008B3C4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008B3C8: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8008B3CC: lw          $a1, 0x59BC($t8)
    ctx->r5 = S32(MEM_W(ctx->r24, 0X59BC));
    // 0x8008B3D0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8008B3D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8008B3D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008B3DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008B3E0: ori         $a3, $zero, 0xAFD0
    ctx->r7 = 0 | 0XAFD0;
    // 0x8008B3E4: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x8008B3E8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8008B3EC: jal         0x8008F920
    // 0x8008B3F0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale(rdram, ctx);
        goto after_20;
    // 0x8008B3F0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_20:
    // 0x8008B3F4: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8008B3F8: lh          $t9, 0x2312($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, 0X2312));
    // 0x8008B3FC: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x8008B400: addiu       $t2, $t2, 0x5770
    ctx->r10 = ADD32(ctx->r10, 0X5770);
    // 0x8008B404: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x8008B408: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8008B40C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008B410: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8008B414: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008B418: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8008B41C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008B420: addu        $v1, $t3, $t2
    ctx->r3 = ADD32(ctx->r11, ctx->r10);
    // 0x8008B424: lw          $a1, 0x250($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X250));
    // 0x8008B428: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8008B42C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8008B430: sw          $v0, 0x24C($v1)
    MEM_W(0X24C, ctx->r3) = ctx->r2;
    // 0x8008B434: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008B438: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8008B43C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8008B440: ori         $a3, $zero, 0xAFD0
    ctx->r7 = 0 | 0XAFD0;
    // 0x8008B444: jal         0x8008F920
    // 0x8008B448: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale(rdram, ctx);
        goto after_21;
    // 0x8008B448: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_21:
    // 0x8008B44C: lui         $t5, 0x8027
    ctx->r13 = S32(0X8027 << 16);
    // 0x8008B450: lh          $t5, 0x2312($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X2312));
    // 0x8008B454: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x8008B458: lh          $t0, 0x32($sp)
    ctx->r8 = S32(MEM_H(ctx->r29, 0X32));
    // 0x8008B45C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8008B460: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8008B464: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8008B468: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008B46C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008B470: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8008B474: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008B478: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008B47C: sw          $v0, 0x59C0($at)
    MEM_W(0X59C0, ctx->r1) = ctx->r2;
    // 0x8008B480: lw          $t1, 0x2C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X2C));
L_8008B484:
    // 0x8008B484: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B488: b           L_8008B5A8
    // 0x8008B48C: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
        goto L_8008B5A8;
    // 0x8008B48C: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
L_8008B490:
    // 0x8008B490: addiu       $at, $zero, 0x758
    ctx->r1 = ADD32(0, 0X758);
L_8008B494:
    // 0x8008B494: beq         $v0, $at, L_8008B5A8
    if (ctx->r2 == ctx->r1) {
        // 0x8008B498: addiu       $at, $zero, 0x60E
        ctx->r1 = ADD32(0, 0X60E);
            goto L_8008B5A8;
    }
    // 0x8008B498: addiu       $at, $zero, 0x60E
    ctx->r1 = ADD32(0, 0X60E);
    // 0x8008B49C: beq         $v0, $at, L_8008B5A8
    if (ctx->r2 == ctx->r1) {
        // 0x8008B4A0: addiu       $at, $zero, 0x780
        ctx->r1 = ADD32(0, 0X780);
            goto L_8008B5A8;
    }
    // 0x8008B4A0: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x8008B4A4: beq         $v0, $at, L_8008B5A8
    if (ctx->r2 == ctx->r1) {
        // 0x8008B4A8: lui         $a0, 0x8027
        ctx->r4 = S32(0X8027 << 16);
            goto L_8008B5A8;
    }
    // 0x8008B4A8: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008B4AC: lh          $a0, 0x2310($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2310));
    // 0x8008B4B0: lui         $t2, 0x8028
    ctx->r10 = S32(0X8028 << 16);
    // 0x8008B4B4: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x8008B4B8: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x8008B4BC: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8008B4C0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008B4C4: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8008B4C8: lw          $t2, -0x5BD4($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X5BD4));
    // 0x8008B4CC: lui         $v0, 0x802B
    ctx->r2 = S32(0X802B << 16);
    // 0x8008B4D0: addiu       $v0, $v0, -0x5598
    ctx->r2 = ADD32(ctx->r2, -0X5598);
    // 0x8008B4D4: bne         $t7, $t2, L_8008B4FC
    if (ctx->r15 != ctx->r10) {
        // 0x8008B4D8: lui         $t9, 0x8027
        ctx->r25 = S32(0X8027 << 16);
            goto L_8008B4FC;
    }
    // 0x8008B4D8: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x8008B4DC: lw          $t4, 0x18C($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X18C));
    // 0x8008B4E0: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x8008B4E4: beq         $at, $zero, L_8008B554
    if (ctx->r1 == 0) {
        // 0x8008B4E8: nop
    
            goto L_8008B554;
    }
    // 0x8008B4E8: nop

    // 0x8008B4EC: lw          $t8, 0x190($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X190));
    // 0x8008B4F0: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8008B4F4: beq         $at, $zero, L_8008B554
    if (ctx->r1 == 0) {
        // 0x8008B4F8: nop
    
            goto L_8008B554;
    }
    // 0x8008B4F8: nop

L_8008B4FC:
    // 0x8008B4FC: lw          $t9, 0x2318($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X2318));
    // 0x8008B500: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8008B504: lw          $t5, 0x0($t9)
    ctx->r13 = S32(MEM_W(ctx->r25, 0X0));
    // 0x8008B508: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8008B50C: bnel        $t6, $zero, L_8008B6DC
    if (ctx->r14 != 0) {
        // 0x8008B510: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8008B6DC;
    }
    goto skip_21;
    // 0x8008B510: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_21:
    // 0x8008B514: lh          $t3, 0x2312($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, 0X2312));
    // 0x8008B518: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x8008B51C: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8008B520: sll         $t7, $t3, 3
    ctx->r15 = S32(ctx->r11 << 3);
    // 0x8008B524: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8008B528: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8008B52C: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8008B530: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008B534: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8008B538: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8008B53C: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x8008B540: lh          $t2, 0x5A5E($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, 0X5A5E));
    // 0x8008B544: beql        $a0, $t2, L_8008B6DC
    if (ctx->r4 == ctx->r10) {
        // 0x8008B548: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8008B6DC;
    }
    goto skip_22;
    // 0x8008B548: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_22:
    // 0x8008B54C: b           L_8008B5A8
    // 0x8008B550: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
        goto L_8008B5A8;
    // 0x8008B550: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
L_8008B554:
    // 0x8008B554: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x8008B558: lw          $t8, 0x2318($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, 0X2318));
    // 0x8008B55C: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x8008B560: lw          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X0));
    // 0x8008B564: andi        $t5, $t9, 0x3
    ctx->r13 = ctx->r25 & 0X3;
    // 0x8008B568: bnel        $t5, $zero, L_8008B6DC
    if (ctx->r13 != 0) {
        // 0x8008B56C: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8008B6DC;
    }
    goto skip_23;
    // 0x8008B56C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_23:
    // 0x8008B570: lh          $t6, 0x2312($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X2312));
    // 0x8008B574: lui         $t7, 0x802A
    ctx->r15 = S32(0X802A << 16);
    // 0x8008B578: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008B57C: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x8008B580: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8008B584: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008B588: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8008B58C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008B590: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8008B594: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008B598: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8008B59C: lh          $t7, 0x5A5E($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X5A5E));
    // 0x8008B5A0: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x8008B5A4: beq         $a0, $t7, L_8008B6D8
    if (ctx->r4 == ctx->r15) {
        // 0x8008B5A8: addiu       $t4, $t0, 0x200
        ctx->r12 = ADD32(ctx->r8, 0X200);
            goto L_8008B6D8;
    }
L_8008B5A8:
    // 0x8008B5A8: addiu       $t4, $t0, 0x200
    ctx->r12 = ADD32(ctx->r8, 0X200);
L_8008B5AC:
    // 0x8008B5AC: andi        $t8, $t4, 0x7FF
    ctx->r24 = ctx->r12 & 0X7FF;
    // 0x8008B5B0: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8008B5B4: addiu       $t5, $t5, -0x9A0
    ctx->r13 = ADD32(ctx->r13, -0X9A0);
    // 0x8008B5B8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8008B5BC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8008B5C0: lh          $t3, 0x0($t6)
    ctx->r11 = S32(MEM_H(ctx->r14, 0X0));
    // 0x8008B5C4: andi        $t2, $t0, 0x7FF
    ctx->r10 = ctx->r8 & 0X7FF;
    // 0x8008B5C8: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8008B5CC: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B5D0: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x8008B5D4: lh          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X0));
    // 0x8008B5D8: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x8008B5DC: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x8008B5E0: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008B5E4: lh          $a3, 0x1C($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X1C));
    // 0x8008B5E8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008B5EC: lh          $a0, 0x2310($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2310));
    // 0x8008B5F0: mflo        $a1
    ctx->r5 = lo;
    // 0x8008B5F4: sra         $t7, $a1, 14
    ctx->r15 = S32(SIGNED(ctx->r5) >> 14);
    // 0x8008B5F8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8008B5FC: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B600: mflo        $a2
    ctx->r6 = lo;
    // 0x8008B604: sra         $t6, $a2, 14
    ctx->r14 = S32(SIGNED(ctx->r6) >> 14);
    // 0x8008B608: jal         0x80075C50
    // 0x8008B60C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    movesprite(rdram, ctx);
        goto after_22;
    // 0x8008B60C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_22:
    // 0x8008B610: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8008B614: lh          $t7, 0x2310($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X2310));
    // 0x8008B618: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8008B61C: sll         $t2, $t7, 3
    ctx->r10 = S32(ctx->r15 << 3);
    // 0x8008B620: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x8008B624: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8008B628: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8008B62C: sh          $v0, -0x5BF6($at)
    MEM_H(-0X5BF6, ctx->r1) = ctx->r2;
    // 0x8008B630: lh          $t4, 0x36($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X36));
L_8008B634:
    // 0x8008B634: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8008B638: beql        $t4, $zero, L_8008B6DC
    if (ctx->r12 == 0) {
        // 0x8008B63C: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8008B6DC;
    }
    goto skip_24;
    // 0x8008B63C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_24:
    // 0x8008B640: lw          $s0, 0x231C($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X231C));
    // 0x8008B644: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8008B648: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x8008B64C: lh          $t5, 0x10($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X10));
    // 0x8008B650: addiu       $a0, $a0, -0x1988
    ctx->r4 = ADD32(ctx->r4, -0X1988);
    // 0x8008B654: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B658: mflo        $t8
    ctx->r24 = lo;
    // 0x8008B65C: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8008B660: lh          $t9, 0xC($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0XC));
    // 0x8008B664: andi        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 & 0X1;
    // 0x8008B668: beql        $t6, $zero, L_8008B690
    if (ctx->r14 == 0) {
        // 0x8008B66C: lb          $v0, 0x24($s0)
        ctx->r2 = S32(MEM_B(ctx->r16, 0X24));
            goto L_8008B690;
    }
    goto skip_25;
    // 0x8008B66C: lb          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_B(ctx->r16, 0X24));
    skip_25:
    // 0x8008B670: lb          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_B(ctx->r16, 0X24));
    // 0x8008B674: lb          $t3, 0x22($v1)
    ctx->r11 = S32(MEM_B(ctx->r3, 0X22));
    // 0x8008B678: subu        $t7, $t3, $v0
    ctx->r15 = SUB32(ctx->r11, ctx->r2);
    // 0x8008B67C: sra         $t2, $t7, 1
    ctx->r10 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8008B680: addu        $t4, $v0, $t2
    ctx->r12 = ADD32(ctx->r2, ctx->r10);
    // 0x8008B684: b           L_8008B6A4
    // 0x8008B688: sb          $t4, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r12;
        goto L_8008B6A4;
    // 0x8008B688: sb          $t4, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r12;
    // 0x8008B68C: lb          $v0, 0x24($s0)
    ctx->r2 = S32(MEM_B(ctx->r16, 0X24));
L_8008B690:
    // 0x8008B690: lb          $t5, 0x26($v1)
    ctx->r13 = S32(MEM_B(ctx->r3, 0X26));
    // 0x8008B694: subu        $t8, $t5, $v0
    ctx->r24 = SUB32(ctx->r13, ctx->r2);
    // 0x8008B698: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8008B69C: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x8008B6A0: sb          $t6, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r14;
L_8008B6A4:
    // 0x8008B6A4: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x8008B6A8: lw          $t3, 0x231C($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X231C));
    // 0x8008B6AC: addiu       $at, $zero, 0x230
    ctx->r1 = ADD32(0, 0X230);
    // 0x8008B6B0: lh          $t7, 0x10($t3)
    ctx->r15 = S32(MEM_H(ctx->r11, 0X10));
    // 0x8008B6B4: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B6B8: mflo        $t2
    ctx->r10 = lo;
    // 0x8008B6BC: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x8008B6C0: lh          $t5, 0x14($t4)
    ctx->r13 = S32(MEM_H(ctx->r12, 0X14));
    // 0x8008B6C4: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x8008B6C8: bnel        $t5, $at, L_8008B6DC
    if (ctx->r13 != ctx->r1) {
        // 0x8008B6CC: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_8008B6DC;
    }
    goto skip_26;
    // 0x8008B6CC: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_26:
    // 0x8008B6D0: jal         0x80092728
    // 0x8008B6D4: lh          $a0, 0x2310($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2310));
    deletesprite(rdram, ctx);
        goto after_23;
    // 0x8008B6D4: lh          $a0, 0x2310($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X2310));
    after_23:
L_8008B6D8:
    // 0x8008B6D8: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_8008B6DC:
    // 0x8008B6DC: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8008B6E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8008B6E4: jr          $ra
    // 0x8008B6E8: nop

    return;
    // 0x8008B6E8: nop

;}
RECOMP_FUNC void clipmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800958C8: addiu       $sp, $sp, -0x1B8
    ctx->r29 = ADD32(ctx->r29, -0X1B8);
    // 0x800958CC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800958D0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800958D4: lw          $s1, 0x1C8($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C8));
    // 0x800958D8: lw          $s2, 0x1CC($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1CC));
    // 0x800958DC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800958E0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800958E4: or          $t0, $s1, $s2
    ctx->r8 = ctx->r17 | ctx->r18;
    // 0x800958E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800958EC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800958F0: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800958F4: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800958F8: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800958FC: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80095900: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80095904: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80095908: sw          $a2, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r6;
    // 0x8009590C: beq         $t0, $zero, L_80095920
    if (ctx->r8 == 0) {
        // 0x80095910: sw          $a3, 0x1C4($sp)
        MEM_W(0X1C4, ctx->r29) = ctx->r7;
            goto L_80095920;
    }
    // 0x80095910: sw          $a3, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r7;
    // 0x80095914: lh          $t7, 0x0($a3)
    ctx->r15 = S32(MEM_H(ctx->r7, 0X0));
    // 0x80095918: bgezl       $t7, L_8009592C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8009591C: sw          $zero, 0x170($sp)
        MEM_W(0X170, ctx->r29) = 0;
            goto L_8009592C;
    }
    goto skip_0;
    // 0x8009591C: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
    skip_0:
L_80095920:
    // 0x80095920: b           L_80097408
    // 0x80095924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097408;
    // 0x80095924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80095928: sw          $zero, 0x170($sp)
    MEM_W(0X170, ctx->r29) = 0;
L_8009592C:
    // 0x8009592C: sw          $s1, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r17;
    // 0x80095930: sw          $s2, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r18;
    // 0x80095934: lw          $t8, 0x0($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80095938: sra         $t9, $s1, 14
    ctx->r25 = S32(SIGNED(ctx->r17) >> 14);
    // 0x8009593C: sra         $t5, $s2, 14
    ctx->r13 = S32(SIGNED(ctx->r18) >> 14);
    // 0x80095940: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80095944: sw          $t7, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r15;
    // 0x80095948: lw          $t4, 0x0($s3)
    ctx->r12 = S32(MEM_W(ctx->r19, 0X0));
    // 0x8009594C: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80095950: sh          $zero, 0x6F22($at)
    MEM_H(0X6F22, ctx->r1) = 0;
    // 0x80095954: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80095958: sw          $t6, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r14;
    // 0x8009595C: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80095960: subu        $v0, $t7, $v1
    ctx->r2 = SUB32(ctx->r15, ctx->r3);
    // 0x80095964: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095968: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8009596C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80095970: sw          $t9, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r25;
    // 0x80095974: lw          $a1, 0x0($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80095978: sw          $s3, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->r19;
    // 0x8009597C: sw          $s0, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r16;
    // 0x80095980: addu        $t4, $a1, $t6
    ctx->r12 = ADD32(ctx->r5, ctx->r14);
    // 0x80095984: subu        $a2, $t6, $a1
    ctx->r6 = SUB32(ctx->r14, ctx->r5);
    // 0x80095988: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8009598C: mflo        $t6
    ctx->r14 = lo;
    // 0x80095990: sw          $t5, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r13;
    // 0x80095994: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x80095998: multu       $a2, $a2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009599C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800959A0: sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
    // 0x800959A4: mflo        $t8
    ctx->r24 = lo;
    // 0x800959A8: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800959AC: jal         0x80091A00
    // 0x800959B0: nop

    nsqrtasm(rdram, ctx);
        goto after_0;
    // 0x800959B0: nop

    after_0:
    // 0x800959B4: lw          $t9, 0x1D0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x800959B8: lw          $a0, 0x140($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X140));
    // 0x800959BC: lw          $a1, 0x13C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800959C0: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800959C4: subu        $t5, $a0, $v1
    ctx->r13 = SUB32(ctx->r4, ctx->r3);
    // 0x800959C8: addiu       $t4, $v1, 0x408
    ctx->r12 = ADD32(ctx->r3, 0X408);
    // 0x800959CC: addiu       $t7, $t5, -0x408
    ctx->r15 = ADD32(ctx->r13, -0X408);
    // 0x800959D0: sw          $t4, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r12;
    // 0x800959D4: sw          $t7, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r15;
    // 0x800959D8: lw          $t7, 0x1C4($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C4));
    // 0x800959DC: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x800959E0: subu        $t3, $a1, $v1
    ctx->r11 = SUB32(ctx->r5, ctx->r3);
    // 0x800959E4: addu        $t4, $a1, $v1
    ctx->r12 = ADD32(ctx->r5, ctx->r3);
    // 0x800959E8: addiu       $t6, $t3, -0x408
    ctx->r14 = ADD32(ctx->r11, -0X408);
    // 0x800959EC: addiu       $t5, $t4, 0x408
    ctx->r13 = ADD32(ctx->r12, 0X408);
    // 0x800959F0: addiu       $t9, $t8, 0x408
    ctx->r25 = ADD32(ctx->r24, 0X408);
    // 0x800959F4: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
    // 0x800959F8: sw          $t9, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r25;
    // 0x800959FC: sw          $t5, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r13;
    // 0x80095A00: lh          $t3, 0x0($t7)
    ctx->r11 = S32(MEM_H(ctx->r15, 0X0));
    // 0x80095A04: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80095A08: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x80095A0C: sh          $t3, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = ctx->r11;
    // 0x80095A10: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80095A14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095A18: addiu       $t8, $t8, -0x70D0
    ctx->r24 = ADD32(ctx->r24, -0X70D0);
    // 0x80095A1C: sh          $t6, -0x6CD0($at)
    MEM_H(-0X6CD0, ctx->r1) = ctx->r14;
    // 0x80095A20: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    // 0x80095A24: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
L_80095A28:
    // 0x80095A28: lw          $t9, 0xB4($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XB4));
    // 0x80095A2C: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80095A30: addiu       $t6, $t6, -0x1988
    ctx->r14 = ADD32(ctx->r14, -0X1988);
    // 0x80095A34: lh          $a0, 0x0($t9)
    ctx->r4 = S32(MEM_H(ctx->r25, 0X0));
    // 0x80095A38: lw          $t4, 0x164($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80095A3C: addiu       $t7, $t9, 0x2
    ctx->r15 = ADD32(ctx->r25, 0X2);
    // 0x80095A40: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80095A44: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x80095A48: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80095A4C: addu        $v1, $t3, $t6
    ctx->r3 = ADD32(ctx->r11, ctx->r14);
    // 0x80095A50: lh          $v0, 0x8($v1)
    ctx->r2 = S32(MEM_H(ctx->r3, 0X8));
    // 0x80095A54: lh          $t8, 0xA($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0XA));
    // 0x80095A58: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80095A5C: sw          $t5, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r13;
    // 0x80095A60: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x80095A64: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80095A68: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x80095A6C: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    // 0x80095A70: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80095A74: addiu       $t5, $t5, 0x61A8
    ctx->r13 = ADD32(ctx->r13, 0X61A8);
    // 0x80095A78: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80095A7C: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80095A80: addu        $s7, $t4, $t5
    ctx->r23 = ADD32(ctx->r12, ctx->r13);
    // 0x80095A84: sw          $a1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r5;
    // 0x80095A88: sw          $a0, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r4;
    // 0x80095A8C: beq         $at, $zero, L_8009606C
    if (ctx->r1 == 0) {
        // 0x80095A90: sw          $v0, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r2;
            goto L_8009606C;
    }
    // 0x80095A90: sw          $v0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r2;
    // 0x80095A94: lw          $t0, 0x128($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X128));
    // 0x80095A98: lw          $a3, 0x12C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X12C));
    // 0x80095A9C: lw          $a1, 0x130($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X130));
L_80095AA0:
    // 0x80095AA0: lh          $t9, 0x8($s7)
    ctx->r25 = S32(MEM_H(ctx->r23, 0X8));
    // 0x80095AA4: lw          $a2, 0x0($s7)
    ctx->r6 = S32(MEM_W(ctx->r23, 0X0));
    // 0x80095AA8: lw          $t6, 0x134($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80095AAC: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x80095AB0: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80095AB4: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80095AB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80095ABC: addiu       $t3, $t3, 0x61A8
    ctx->r11 = ADD32(ctx->r11, 0X61A8);
    // 0x80095AC0: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80095AC4: beq         $at, $zero, L_80095AD8
    if (ctx->r1 == 0) {
        // 0x80095AC8: addu        $v0, $t7, $t3
        ctx->r2 = ADD32(ctx->r15, ctx->r11);
            goto L_80095AD8;
    }
    // 0x80095AC8: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x80095ACC: lw          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80095AD0: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80095AD4: bne         $at, $zero, L_80096050
    if (ctx->r1 != 0) {
        // 0x80095AD8: slt         $at, $a3, $a2
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80096050;
    }
L_80095AD8:
    // 0x80095AD8: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80095ADC: beql        $at, $zero, L_80095AF8
    if (ctx->r1 == 0) {
        // 0x80095AE0: lw          $v1, 0x4($s7)
        ctx->r3 = S32(MEM_W(ctx->r23, 0X4));
            goto L_80095AF8;
    }
    goto skip_1;
    // 0x80095AE0: lw          $v1, 0x4($s7)
    ctx->r3 = S32(MEM_W(ctx->r23, 0X4));
    skip_1:
    // 0x80095AE4: lw          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80095AE8: slt         $at, $a3, $t4
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80095AEC: bnel        $at, $zero, L_80096054
    if (ctx->r1 != 0) {
        // 0x80095AF0: lw          $v0, 0x19C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80096054;
    }
    goto skip_2;
    // 0x80095AF0: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
    skip_2:
    // 0x80095AF4: lw          $v1, 0x4($s7)
    ctx->r3 = S32(MEM_W(ctx->r23, 0X4));
L_80095AF8:
    // 0x80095AF8: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80095AFC: beql        $at, $zero, L_80095B14
    if (ctx->r1 == 0) {
        // 0x80095B00: slt         $at, $t0, $v1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80095B14;
    }
    goto skip_3;
    // 0x80095B00: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    skip_3:
    // 0x80095B04: lw          $t5, 0x4($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80095B08: slt         $at, $t5, $a1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80095B0C: bne         $at, $zero, L_80096050
    if (ctx->r1 != 0) {
        // 0x80095B10: slt         $at, $t0, $v1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80096050;
    }
    // 0x80095B10: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
L_80095B14:
    // 0x80095B14: beq         $at, $zero, L_80095B28
    if (ctx->r1 == 0) {
        // 0x80095B18: lw          $a0, 0x4($v0)
        ctx->r4 = S32(MEM_W(ctx->r2, 0X4));
            goto L_80095B28;
    }
    // 0x80095B18: lw          $a0, 0x4($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80095B1C: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80095B20: bnel        $at, $zero, L_80096054
    if (ctx->r1 != 0) {
        // 0x80095B24: lw          $v0, 0x19C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80096054;
    }
    goto skip_4;
    // 0x80095B24: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
    skip_4:
L_80095B28:
    // 0x80095B28: lw          $s4, 0x0($v0)
    ctx->r20 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80095B2C: lw          $t9, 0x1BC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80095B30: subu        $a3, $a0, $v1
    ctx->r7 = SUB32(ctx->r4, ctx->r3);
    // 0x80095B34: subu        $a1, $s4, $a2
    ctx->r5 = SUB32(ctx->r20, ctx->r6);
    // 0x80095B38: sw          $a1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r5;
    // 0x80095B3C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x80095B40: sw          $v1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r3;
    // 0x80095B44: lw          $t7, 0x0($t9)
    ctx->r15 = S32(MEM_W(ctx->r25, 0X0));
    // 0x80095B48: lw          $t6, 0x1B8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80095B4C: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x80095B50: subu        $t3, $t7, $v1
    ctx->r11 = SUB32(ctx->r15, ctx->r3);
    // 0x80095B54: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095B58: lw          $t4, 0x0($t6)
    ctx->r12 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80095B5C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80095B60: lw          $t0, 0x128($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X128));
    // 0x80095B64: subu        $t5, $t4, $a2
    ctx->r13 = SUB32(ctx->r12, ctx->r6);
    // 0x80095B68: lw          $t7, 0xB0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x80095B6C: mflo        $t8
    ctx->r24 = lo;
    // 0x80095B70: nop

    // 0x80095B74: nop

    // 0x80095B78: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095B7C: mflo        $t9
    ctx->r25 = lo;
    // 0x80095B80: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80095B84: beq         $at, $zero, L_80095B98
    if (ctx->r1 == 0) {
        // 0x80095B88: nop
    
            goto L_80095B98;
    }
    // 0x80095B88: nop

    // 0x80095B8C: lw          $a3, 0x12C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X12C));
    // 0x80095B90: b           L_80096050
    // 0x80095B94: lw          $a1, 0x130($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X130));
        goto L_80096050;
    // 0x80095B94: lw          $a1, 0x130($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X130));
L_80095B98:
    // 0x80095B98: blez        $t7, L_80095BBC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80095B9C: lw          $t5, 0x128($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X128));
            goto L_80095BBC;
    }
    // 0x80095B9C: lw          $t5, 0x128($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X128));
    // 0x80095BA0: lw          $t3, 0x130($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X130));
    // 0x80095BA4: lw          $t6, 0x14C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80095BA8: subu        $t4, $t3, $t6
    ctx->r12 = SUB32(ctx->r11, ctx->r14);
    // 0x80095BAC: multu       $t4, $a1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095BB0: mflo        $s3
    ctx->r19 = lo;
    // 0x80095BB4: b           L_80095BD8
    // 0x80095BB8: lw          $t7, 0xAC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XAC));
        goto L_80095BD8;
    // 0x80095BB8: lw          $t7, 0xAC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XAC));
L_80095BBC:
    // 0x80095BBC: lw          $t8, 0x14C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80095BC0: subu        $t9, $t5, $t8
    ctx->r25 = SUB32(ctx->r13, ctx->r24);
    // 0x80095BC4: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095BC8: mflo        $s3
    ctx->r19 = lo;
    // 0x80095BCC: nop

    // 0x80095BD0: nop

    // 0x80095BD4: lw          $t7, 0xAC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XAC));
L_80095BD8:
    // 0x80095BD8: lw          $t4, 0x134($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80095BDC: lw          $t3, 0x12C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X12C));
    // 0x80095BE0: blez        $t7, L_80095BFC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80095BE4: subu        $t5, $t4, $fp
        ctx->r13 = SUB32(ctx->r12, ctx->r30);
            goto L_80095BFC;
    }
    // 0x80095BE4: subu        $t5, $t4, $fp
    ctx->r13 = SUB32(ctx->r12, ctx->r30);
    // 0x80095BE8: subu        $t6, $t3, $fp
    ctx->r14 = SUB32(ctx->r11, ctx->r30);
    // 0x80095BEC: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095BF0: mflo        $s0
    ctx->r16 = lo;
    // 0x80095BF4: b           L_80095C10
    // 0x80095BF8: slt         $at, $s3, $s0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
        goto L_80095C10;
    // 0x80095BF8: slt         $at, $s3, $s0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
L_80095BFC:
    // 0x80095BFC: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095C00: mflo        $s0
    ctx->r16 = lo;
    // 0x80095C04: nop

    // 0x80095C08: nop

    // 0x80095C0C: slt         $at, $s3, $s0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
L_80095C10:
    // 0x80095C10: sw          $s0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r16;
    // 0x80095C14: bne         $at, $zero, L_80095C2C
    if (ctx->r1 != 0) {
        // 0x80095C18: sw          $s3, 0x118($sp)
        MEM_W(0X118, ctx->r29) = ctx->r19;
            goto L_80095C2C;
    }
    // 0x80095C18: sw          $s3, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r19;
    // 0x80095C1C: lw          $t0, 0x128($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X128));
    // 0x80095C20: lw          $a3, 0x12C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X12C));
    // 0x80095C24: b           L_80096050
    // 0x80095C28: lw          $a1, 0x130($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X130));
        goto L_80096050;
    // 0x80095C28: lw          $a1, 0x130($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X130));
L_80095C2C:
    // 0x80095C2C: lh          $t8, 0xC($s7)
    ctx->r24 = S32(MEM_H(ctx->r23, 0XC));
    // 0x80095C30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80095C34: lw          $t7, 0x1DC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1DC));
    // 0x80095C38: bltz        $t8, L_80095C58
    if (SIGNED(ctx->r24) < 0) {
        // 0x80095C3C: nop
    
            goto L_80095C58;
    }
    // 0x80095C3C: nop

    // 0x80095C40: lh          $t9, 0xE($s7)
    ctx->r25 = S32(MEM_H(ctx->r23, 0XE));
    // 0x80095C44: andi        $t3, $t7, 0xFFFF
    ctx->r11 = ctx->r15 & 0XFFFF;
    // 0x80095C48: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80095C4C: and         $t6, $t9, $t3
    ctx->r14 = ctx->r25 & ctx->r11;
    // 0x80095C50: beq         $t6, $zero, L_80095C60
    if (ctx->r14 == 0) {
        // 0x80095C54: nop
    
            goto L_80095C60;
    }
    // 0x80095C54: nop

L_80095C58:
    // 0x80095C58: b           L_80095DD8
    // 0x80095C5C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80095DD8;
    // 0x80095C5C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80095C60:
    // 0x80095C60: lh          $t4, -0xA00($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0XA00));
    // 0x80095C64: lw          $t5, 0x1B8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80095C68: lw          $t8, 0x1BC($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80095C6C: bne         $t4, $zero, L_80095DD8
    if (ctx->r12 != 0) {
        // 0x80095C70: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80095DD8;
    }
    // 0x80095C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80095C74: lw          $a0, 0x0($t5)
    ctx->r4 = S32(MEM_W(ctx->r13, 0X0));
    // 0x80095C78: lw          $a1, 0x0($t8)
    ctx->r5 = S32(MEM_W(ctx->r24, 0X0));
    // 0x80095C7C: lw          $t7, 0xE8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x80095C80: lw          $t9, 0x14C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80095C84: addiu       $t3, $sp, 0x118
    ctx->r11 = ADD32(ctx->r29, 0X118);
    // 0x80095C88: addiu       $t6, $sp, 0x114
    ctx->r14 = ADD32(ctx->r29, 0X114);
    // 0x80095C8C: addiu       $t4, $sp, 0x124
    ctx->r12 = ADD32(ctx->r29, 0X124);
    // 0x80095C90: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80095C94: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80095C98: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80095C9C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80095CA0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80095CA4: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x80095CA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80095CAC: lw          $a3, 0xEC($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XEC));
    // 0x80095CB0: lh          $s6, 0x156($sp)
    ctx->r22 = S32(MEM_H(ctx->r29, 0X156));
    // 0x80095CB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80095CB8: jal         0x8009542C
    // 0x80095CBC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    rintersect(rdram, ctx);
        goto after_1;
    // 0x80095CBC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_1:
    // 0x80095CC0: bne         $v0, $zero, L_80095CE0
    if (ctx->r2 != 0) {
        // 0x80095CC4: sll         $a0, $s6, 16
        ctx->r4 = S32(ctx->r22 << 16);
            goto L_80095CE0;
    }
    // 0x80095CC4: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x80095CC8: lw          $t5, 0x1B8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80095CCC: lw          $t7, 0x1BC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80095CD0: lw          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_W(ctx->r13, 0X0));
    // 0x80095CD4: sw          $t8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r24;
    // 0x80095CD8: lw          $t9, 0x0($t7)
    ctx->r25 = S32(MEM_W(ctx->r15, 0X0));
    // 0x80095CDC: sw          $t9, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r25;
L_80095CE0:
    // 0x80095CE0: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80095CE4: lw          $a2, 0x114($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80095CE8: lw          $a1, 0x118($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80095CEC: jal         0x80098FB4
    // 0x80095CF0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    getflorzofslope(rdram, ctx);
        goto after_2;
    // 0x80095CF0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_2:
    // 0x80095CF4: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x80095CF8: lh          $a0, 0xC($s7)
    ctx->r4 = S32(MEM_H(ctx->r23, 0XC));
    // 0x80095CFC: lw          $a1, 0x118($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80095D00: jal         0x80098FB4
    // 0x80095D04: lw          $a2, 0x114($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X114));
    getflorzofslope(rdram, ctx);
        goto after_3;
    // 0x80095D04: lw          $a2, 0x114($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X114));
    after_3:
    // 0x80095D08: lh          $t6, 0xC($s7)
    ctx->r14 = S32(MEM_H(ctx->r23, 0XC));
    // 0x80095D0C: lw          $t8, 0x124($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X124));
    // 0x80095D10: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x80095D14: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80095D18: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x80095D1C: addiu       $t7, $t8, -0x100
    ctx->r15 = ADD32(ctx->r24, -0X100);
    // 0x80095D20: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80095D24: addiu       $t5, $t5, -0x1988
    ctx->r13 = ADD32(ctx->r13, -0X1988);
    // 0x80095D28: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80095D2C: beq         $at, $zero, L_80095D64
    if (ctx->r1 == 0) {
        // 0x80095D30: addu        $s5, $t4, $t5
        ctx->r21 = ADD32(ctx->r12, ctx->r13);
            goto L_80095D64;
    }
    // 0x80095D30: addu        $s5, $t4, $t5
    ctx->r21 = ADD32(ctx->r12, ctx->r13);
    // 0x80095D34: lh          $t9, 0xE($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0XE));
    // 0x80095D38: lw          $t6, 0x1C0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1C0));
    // 0x80095D3C: lw          $t5, 0x1D8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1D8));
    // 0x80095D40: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x80095D44: bne         $t3, $zero, L_80095D64
    if (ctx->r11 != 0) {
        // 0x80095D48: nop
    
            goto L_80095D64;
    }
    // 0x80095D48: nop

    // 0x80095D4C: lw          $t4, 0x0($t6)
    ctx->r12 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80095D50: subu        $t8, $v0, $t5
    ctx->r24 = SUB32(ctx->r2, ctx->r13);
    // 0x80095D54: slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80095D58: beq         $at, $zero, L_80095D64
    if (ctx->r1 == 0) {
        // 0x80095D5C: nop
    
            goto L_80095D64;
    }
    // 0x80095D5C: nop

    // 0x80095D60: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80095D64:
    // 0x80095D64: bne         $s1, $zero, L_80095DD8
    if (ctx->r17 != 0) {
        // 0x80095D68: lw          $a2, 0x114($sp)
        ctx->r6 = S32(MEM_W(ctx->r29, 0X114));
            goto L_80095DD8;
    }
    // 0x80095D68: lw          $a2, 0x114($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80095D6C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x80095D70: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80095D74: lw          $a1, 0x118($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80095D78: jal         0x80098E64
    // 0x80095D7C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    getceilzofslope(rdram, ctx);
        goto after_4;
    // 0x80095D7C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x80095D80: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x80095D84: lh          $a0, 0xC($s7)
    ctx->r4 = S32(MEM_H(ctx->r23, 0XC));
    // 0x80095D88: lw          $a1, 0x118($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80095D8C: jal         0x80098E64
    // 0x80095D90: lw          $a2, 0x114($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X114));
    getceilzofslope(rdram, ctx);
        goto after_5;
    // 0x80095D90: lw          $a2, 0x114($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X114));
    after_5:
    // 0x80095D94: lw          $t9, 0x124($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X124));
    // 0x80095D98: addiu       $t3, $t9, 0x100
    ctx->r11 = ADD32(ctx->r25, 0X100);
    // 0x80095D9C: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80095DA0: beq         $at, $zero, L_80095DD8
    if (ctx->r1 == 0) {
        // 0x80095DA4: nop
    
            goto L_80095DD8;
    }
    // 0x80095DA4: nop

    // 0x80095DA8: lh          $t6, 0xC($s5)
    ctx->r14 = S32(MEM_H(ctx->r21, 0XC));
    // 0x80095DAC: lw          $t4, 0x1C0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1C0));
    // 0x80095DB0: lw          $t7, 0x1D4($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1D4));
    // 0x80095DB4: andi        $t5, $t6, 0x1
    ctx->r13 = ctx->r14 & 0X1;
    // 0x80095DB8: bne         $t5, $zero, L_80095DD8
    if (ctx->r13 != 0) {
        // 0x80095DBC: nop
    
            goto L_80095DD8;
    }
    // 0x80095DBC: nop

    // 0x80095DC0: lw          $t8, 0x0($t4)
    ctx->r24 = S32(MEM_W(ctx->r12, 0X0));
    // 0x80095DC4: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x80095DC8: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80095DCC: beq         $at, $zero, L_80095DD8
    if (ctx->r1 == 0) {
        // 0x80095DD0: nop
    
            goto L_80095DD8;
    }
    // 0x80095DD0: nop

    // 0x80095DD4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80095DD8:
    // 0x80095DD8: beq         $s1, $zero, L_80095FE0
    if (ctx->r17 == 0) {
        // 0x80095DDC: lw          $t6, 0xEC($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0XEC));
            goto L_80095FE0;
    }
    // 0x80095DDC: lw          $t6, 0xEC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XEC));
    // 0x80095DE0: lw          $t3, 0x1D0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x80095DE4: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x80095DE8: bgez        $t6, L_80095DF4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80095DEC: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80095DF4;
    }
    // 0x80095DEC: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80095DF0: negu        $v0, $t3
    ctx->r2 = SUB32(0, ctx->r11);
L_80095DF4:
    // 0x80095DF4: addiu       $t0, $t0, 0x6F22
    ctx->r8 = ADD32(ctx->r8, 0X6F22);
    // 0x80095DF8: lh          $a0, 0x0($t0)
    ctx->r4 = S32(MEM_H(ctx->r8, 0X0));
    // 0x80095DFC: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x80095E00: lh          $a3, 0x19E($sp)
    ctx->r7 = S32(MEM_H(ctx->r29, 0X19E));
    // 0x80095E04: addiu       $t4, $t4, 0x6F30
    ctx->r12 = ADD32(ctx->r12, 0X6F30);
    // 0x80095E08: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x80095E0C: lw          $t7, 0x14C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80095E10: lw          $t9, 0x14C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80095E14: addu        $v1, $t5, $t4
    ctx->r3 = ADD32(ctx->r13, ctx->r12);
    // 0x80095E18: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80095E1C: subu        $a1, $fp, $v0
    ctx->r5 = SUB32(ctx->r30, ctx->r2);
    // 0x80095E20: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    // 0x80095E24: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80095E28: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x80095E2C: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80095E30: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80095E34: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x80095E38: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80095E3C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80095E40: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80095E44: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x80095E48: sh          $a3, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r7;
    // 0x80095E4C: addiu       $t5, $a0, 0x1
    ctx->r13 = ADD32(ctx->r4, 0X1);
    // 0x80095E50: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x80095E54: lh          $a0, 0x0($t0)
    ctx->r4 = S32(MEM_H(ctx->r8, 0X0));
    // 0x80095E58: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x80095E5C: addiu       $t7, $t7, 0x6F30
    ctx->r15 = ADD32(ctx->r15, 0X6F30);
    // 0x80095E60: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x80095E64: addu        $v1, $t4, $t7
    ctx->r3 = ADD32(ctx->r12, ctx->r15);
    // 0x80095E68: subu        $a2, $s4, $v0
    ctx->r6 = SUB32(ctx->r20, ctx->r2);
    // 0x80095E6C: lw          $t4, 0xE8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x80095E70: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80095E74: subu        $t8, $s2, $v0
    ctx->r24 = SUB32(ctx->r18, ctx->r2);
    // 0x80095E78: addu        $t9, $s2, $v0
    ctx->r25 = ADD32(ctx->r18, ctx->r2);
    // 0x80095E7C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80095E80: lw          $t5, 0x1D0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x80095E84: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80095E88: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x80095E8C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80095E90: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80095E94: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x80095E98: sh          $a3, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r7;
    // 0x80095E9C: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x80095EA0: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x80095EA4: bgez        $t4, L_80095EB0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80095EA8: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_80095EB0;
    }
    // 0x80095EA8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80095EAC: negu        $v0, $t5
    ctx->r2 = SUB32(0, ctx->r13);
L_80095EB0:
    // 0x80095EB0: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x80095EB4: lh          $a0, 0x6F22($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X6F22));
    // 0x80095EB8: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x80095EBC: lw          $t6, 0x14C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80095EC0: addiu       $t8, $t8, 0x6F30
    ctx->r24 = ADD32(ctx->r24, 0X6F30);
    // 0x80095EC4: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80095EC8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80095ECC: subu        $a1, $t6, $v0
    ctx->r5 = SUB32(ctx->r14, ctx->r2);
    // 0x80095ED0: addu        $t9, $fp, $v0
    ctx->r25 = ADD32(ctx->r30, ctx->r2);
    // 0x80095ED4: subu        $t3, $fp, $v0
    ctx->r11 = SUB32(ctx->r30, ctx->r2);
    // 0x80095ED8: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80095EDC: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x80095EE0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80095EE4: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x80095EE8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80095EEC: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80095EF0: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x80095EF4: sh          $a3, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r7;
    // 0x80095EF8: addiu       $t5, $a0, 0x1
    ctx->r13 = ADD32(ctx->r4, 0X1);
    // 0x80095EFC: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80095F00: sh          $t5, 0x6F22($at)
    MEM_H(0X6F22, ctx->r1) = ctx->r13;
    // 0x80095F04: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x80095F08: lh          $a0, 0x6F22($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X6F22));
    // 0x80095F0C: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x80095F10: addiu       $t8, $t8, 0x6F30
    ctx->r24 = ADD32(ctx->r24, 0X6F30);
    // 0x80095F14: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80095F18: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80095F1C: subu        $a2, $s2, $v0
    ctx->r6 = SUB32(ctx->r18, ctx->r2);
    // 0x80095F20: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80095F24: addu        $t9, $s4, $v0
    ctx->r25 = ADD32(ctx->r20, ctx->r2);
    // 0x80095F28: subu        $t6, $s4, $v0
    ctx->r14 = SUB32(ctx->r20, ctx->r2);
    // 0x80095F2C: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x80095F30: lw          $t7, 0xAC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XAC));
    // 0x80095F34: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80095F38: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80095F3C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80095F40: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80095F44: sw          $a2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r6;
    // 0x80095F48: lw          $t5, 0x1D0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x80095F4C: sh          $a3, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r7;
    // 0x80095F50: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80095F54: addiu       $t4, $a0, 0x1
    ctx->r12 = ADD32(ctx->r4, 0X1);
    // 0x80095F58: sh          $t4, 0x6F22($at)
    MEM_H(0X6F22, ctx->r1) = ctx->r12;
    // 0x80095F5C: blez        $t7, L_80095F68
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80095F60: or          $s3, $t5, $zero
        ctx->r19 = ctx->r13 | 0;
            goto L_80095F68;
    }
    // 0x80095F60: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x80095F64: negu        $s3, $t5
    ctx->r19 = SUB32(0, ctx->r13);
L_80095F68:
    // 0x80095F68: lw          $t9, 0xB0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XB0));
    // 0x80095F6C: lw          $t8, 0x1D0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x80095F70: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x80095F74: bgez        $t9, L_80095F80
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80095F78: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_80095F80;
    }
    // 0x80095F78: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80095F7C: negu        $s0, $t8
    ctx->r16 = SUB32(0, ctx->r24);
L_80095F80:
    // 0x80095F80: lh          $a0, 0x6F22($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X6F22));
    // 0x80095F84: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x80095F88: addiu       $t3, $t3, 0x6F30
    ctx->r11 = ADD32(ctx->r11, 0X6F30);
    // 0x80095F8C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80095F90: addu        $v1, $t6, $t3
    ctx->r3 = ADD32(ctx->r14, ctx->r11);
    // 0x80095F94: lw          $t7, 0x14C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80095F98: addu        $t4, $fp, $s3
    ctx->r12 = ADD32(ctx->r30, ctx->r19);
    // 0x80095F9C: addu        $t9, $s4, $s3
    ctx->r25 = ADD32(ctx->r20, ctx->r19);
    // 0x80095FA0: addu        $t8, $s2, $s0
    ctx->r24 = ADD32(ctx->r18, ctx->r16);
    // 0x80095FA4: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80095FA8: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80095FAC: addu        $t5, $t7, $s0
    ctx->r13 = ADD32(ctx->r15, ctx->r16);
    // 0x80095FB0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80095FB4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80095FB8: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x80095FBC: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x80095FC0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80095FC4: sh          $a3, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r7;
    // 0x80095FC8: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80095FCC: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x80095FD0: sh          $t3, 0x6F22($at)
    MEM_H(0X6F22, ctx->r1) = ctx->r11;
    // 0x80095FD4: sw          $s0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r16;
    // 0x80095FD8: b           L_80096044
    // 0x80095FDC: sw          $s3, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r19;
        goto L_80096044;
    // 0x80095FDC: sw          $s3, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r19;
L_80095FE0:
    // 0x80095FE0: lui         $a0, 0x8028
    ctx->r4 = S32(0X8028 << 16);
    // 0x80095FE4: lh          $a0, -0x6CD0($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, -0X6CD0));
    // 0x80095FE8: addiu       $s0, $a0, -0x1
    ctx->r16 = ADD32(ctx->r4, -0X1);
    // 0x80095FEC: bltz        $s0, L_8009601C
    if (SIGNED(ctx->r16) < 0) {
        // 0x80095FF0: lui         $t7, 0x8028
        ctx->r15 = S32(0X8028 << 16);
            goto L_8009601C;
    }
    // 0x80095FF0: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x80095FF4: addiu       $t7, $t7, -0x70D0
    ctx->r15 = ADD32(ctx->r15, -0X70D0);
    // 0x80095FF8: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x80095FFC: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
    // 0x80096000: lh          $v1, 0xC($s7)
    ctx->r3 = S32(MEM_H(ctx->r23, 0XC));
L_80096004:
    // 0x80096004: lh          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80096008: beq         $v1, $t5, L_8009601C
    if (ctx->r3 == ctx->r13) {
        // 0x8009600C: nop
    
            goto L_8009601C;
    }
    // 0x8009600C: nop

    // 0x80096010: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80096014: bgez        $s0, L_80096004
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80096018: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_80096004;
    }
    // 0x80096018: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_8009601C:
    // 0x8009601C: bgezl       $s0, L_80096048
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80096020: lw          $t0, 0x128($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0X128));
            goto L_80096048;
    }
    goto skip_5;
    // 0x80096020: lw          $t0, 0x128($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X128));
    skip_5:
    // 0x80096024: lh          $t9, 0xC($s7)
    ctx->r25 = S32(MEM_H(ctx->r23, 0XC));
    // 0x80096028: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x8009602C: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80096030: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80096034: sh          $t9, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = ctx->r25;
    // 0x80096038: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8009603C: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80096040: sh          $t6, -0x6CD0($at)
    MEM_H(-0X6CD0, ctx->r1) = ctx->r14;
L_80096044:
    // 0x80096044: lw          $t0, 0x128($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X128));
L_80096048:
    // 0x80096048: lw          $a3, 0x12C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X12C));
    // 0x8009604C: lw          $a1, 0x130($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X130));
L_80096050:
    // 0x80096050: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
L_80096054:
    // 0x80096054: lw          $t3, 0x15C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X15C));
    // 0x80096058: addiu       $s7, $s7, 0x24
    ctx->r23 = ADD32(ctx->r23, 0X24);
    // 0x8009605C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80096060: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80096064: bne         $at, $zero, L_80095AA0
    if (ctx->r1 != 0) {
        // 0x80096068: sw          $v0, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r2;
            goto L_80095AA0;
    }
    // 0x80096068: sw          $v0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r2;
L_8009606C:
    // 0x8009606C: lw          $t4, 0x154($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X154));
    // 0x80096070: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80096074: lw          $t5, 0x1DC($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1DC));
    // 0x80096078: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8009607C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80096080: lh          $v0, 0x2330($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X2330));
    // 0x80096084: srl         $t9, $t5, 16
    ctx->r25 = S32(U32(ctx->r13) >> 16);
    // 0x80096088: bltz        $v0, L_80096F08
    if (SIGNED(ctx->r2) < 0) {
        // 0x8009608C: sw          $v0, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r2;
            goto L_80096F08;
    }
    // 0x8009608C: sw          $v0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r2;
    // 0x80096090: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
L_80096094:
    // 0x80096094: lw          $t8, 0x19C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80096098: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x8009609C: addiu       $t3, $t3, 0x6BA8
    ctx->r11 = ADD32(ctx->r11, 0X6BA8);
    // 0x800960A0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800960A4: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800960A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800960AC: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800960B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800960B4: addu        $s1, $t6, $t3
    ctx->r17 = ADD32(ctx->r14, ctx->r11);
    // 0x800960B8: lh          $s5, 0xC($s1)
    ctx->r21 = S32(MEM_H(ctx->r17, 0XC));
    // 0x800960BC: lw          $t4, 0xB8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XB8));
    // 0x800960C0: andi        $v0, $s5, 0x30
    ctx->r2 = ctx->r21 & 0X30;
    // 0x800960C4: and         $t7, $s5, $t4
    ctx->r15 = ctx->r21 & ctx->r12;
    // 0x800960C8: beql        $t7, $zero, L_80096EF0
    if (ctx->r15 == 0) {
        // 0x800960CC: lw          $v0, 0x19C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80096EF0;
    }
    goto skip_6;
    // 0x800960CC: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
    skip_6:
    // 0x800960D0: lw          $t5, 0x4($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800960D4: lw          $fp, 0x0($s1)
    ctx->r30 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800960D8: beq         $v0, $zero, L_800960FC
    if (ctx->r2 == 0) {
        // 0x800960DC: sw          $t5, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r13;
            goto L_800960FC;
    }
    // 0x800960DC: sw          $t5, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r13;
    // 0x800960E0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800960E4: beq         $v0, $at, L_800962DC
    if (ctx->r2 == ctx->r1) {
        // 0x800960E8: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800962DC;
    }
    // 0x800960E8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800960EC: beq         $v0, $at, L_80096784
    if (ctx->r2 == ctx->r1) {
        // 0x800960F0: lw          $t3, 0x1D4($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X1D4));
            goto L_80096784;
    }
    // 0x800960F0: lw          $t3, 0x1D4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1D4));
    // 0x800960F4: b           L_80096EF0
    // 0x800960F8: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
        goto L_80096EF0;
    // 0x800960F8: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
L_800960FC:
    // 0x800960FC: lw          $t9, 0x134($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80096100: lw          $t8, 0x12C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X12C));
    // 0x80096104: slt         $at, $fp, $t9
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80096108: bne         $at, $zero, L_80096EEC
    if (ctx->r1 != 0) {
        // 0x8009610C: slt         $at, $t8, $fp
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r30) ? 1 : 0;
            goto L_80096EEC;
    }
    // 0x8009610C: slt         $at, $t8, $fp
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x80096110: bne         $at, $zero, L_80096EEC
    if (ctx->r1 != 0) {
        // 0x80096114: lw          $t6, 0x14C($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X14C));
            goto L_80096EEC;
    }
    // 0x80096114: lw          $t6, 0x14C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80096118: lw          $t3, 0x130($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X130));
    // 0x8009611C: lw          $t4, 0x128($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X128));
    // 0x80096120: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80096124: bne         $at, $zero, L_80096EEC
    if (ctx->r1 != 0) {
        // 0x80096128: slt         $at, $t4, $t6
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_80096EEC;
    }
    // 0x80096128: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009612C: bnel        $at, $zero, L_80096EF0
    if (ctx->r1 != 0) {
        // 0x80096130: lw          $v0, 0x19C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80096EF0;
    }
    goto skip_7;
    // 0x80096130: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
    skip_7:
    // 0x80096134: jal         0x800B4EA8
    // 0x80096138: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    gettilesizy(rdram, ctx);
        goto after_6;
    // 0x80096138: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_6:
    // 0x8009613C: lbu         $t7, 0x28($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X28);
    // 0x80096140: andi        $t9, $s5, 0x80
    ctx->r25 = ctx->r21 & 0X80;
    // 0x80096144: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096148: mflo        $s2
    ctx->r18 = lo;
    // 0x8009614C: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x80096150: beq         $t9, $zero, L_8009616C
    if (ctx->r25 == 0) {
        // 0x80096154: or          $s2, $t5, $zero
        ctx->r18 = ctx->r13 | 0;
            goto L_8009616C;
    }
    // 0x80096154: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x80096158: lw          $t8, 0x8($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X8));
    // 0x8009615C: sra         $t3, $t5, 1
    ctx->r11 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80096160: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x80096164: b           L_80096174
    // 0x80096168: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
        goto L_80096174;
    // 0x80096168: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
L_8009616C:
    // 0x8009616C: lw          $t6, 0x8($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80096170: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
L_80096174:
    // 0x80096174: jal         0x800B4F00
    // 0x80096178: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    getpicanm(rdram, ctx);
        goto after_7;
    // 0x80096178: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_7:
    // 0x8009617C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80096180: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80096184: beql        $t7, $zero, L_800961C0
    if (ctx->r15 == 0) {
        // 0x80096188: lw          $t8, 0x1C0($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X1C0));
            goto L_800961C0;
    }
    goto skip_8;
    // 0x80096188: lw          $t8, 0x1C0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1C0));
    skip_8:
    // 0x8009618C: jal         0x800B4F00
    // 0x80096190: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    getpicanm(rdram, ctx);
        goto after_8;
    // 0x80096190: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_8:
    // 0x80096194: lbu         $t4, 0x28($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X28);
    // 0x80096198: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8009619C: sll         $t8, $t9, 24
    ctx->r24 = S32(ctx->r25 << 24);
    // 0x800961A0: sra         $t3, $t8, 24
    ctx->r11 = S32(SIGNED(ctx->r24) >> 24);
    // 0x800961A4: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800961A8: lw          $t5, 0x124($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800961AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800961B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800961B4: subu        $t9, $t5, $t7
    ctx->r25 = SUB32(ctx->r13, ctx->r15);
    // 0x800961B8: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x800961BC: lw          $t8, 0x1C0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1C0));
L_800961C0:
    // 0x800961C0: lw          $t3, 0x124($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X124));
    // 0x800961C4: lw          $t4, 0x1D4($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1D4));
    // 0x800961C8: lw          $v1, 0x0($t8)
    ctx->r3 = S32(MEM_W(ctx->r24, 0X0));
    // 0x800961CC: lw          $t7, 0x1D8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1D8));
    // 0x800961D0: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800961D4: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800961D8: beq         $at, $zero, L_80096EEC
    if (ctx->r1 == 0) {
        // 0x800961DC: subu        $t5, $t3, $s2
        ctx->r13 = SUB32(ctx->r11, ctx->r18);
            goto L_80096EEC;
    }
    // 0x800961DC: subu        $t5, $t3, $s2
    ctx->r13 = SUB32(ctx->r11, ctx->r18);
    // 0x800961E0: subu        $t9, $t5, $t7
    ctx->r25 = SUB32(ctx->r13, ctx->r15);
    // 0x800961E4: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800961E8: beq         $at, $zero, L_80096EEC
    if (ctx->r1 == 0) {
        // 0x800961EC: lui         $a3, 0x8027
        ctx->r7 = S32(0X8027 << 16);
            goto L_80096EEC;
    }
    // 0x800961EC: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x800961F0: lbu         $t8, 0x26($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X26);
    // 0x800961F4: lw          $t3, 0xEC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XEC));
    // 0x800961F8: lw          $t6, 0x1D0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x800961FC: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x80096200: bgez        $t3, L_8009620C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80096204: addu        $v0, $t4, $t6
        ctx->r2 = ADD32(ctx->r12, ctx->r14);
            goto L_8009620C;
    }
    // 0x80096204: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x80096208: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8009620C:
    // 0x8009620C: addiu       $a3, $a3, 0x6F22
    ctx->r7 = ADD32(ctx->r7, 0X6F22);
    // 0x80096210: lh          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_H(ctx->r7, 0X0));
    // 0x80096214: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x80096218: lw          $t0, 0x14C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x8009621C: lh          $a2, 0x19E($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X19E));
    // 0x80096220: addiu       $t7, $t7, 0x6F30
    ctx->r15 = ADD32(ctx->r15, 0X6F30);
    // 0x80096224: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x80096228: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x8009622C: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80096230: subu        $a1, $fp, $v0
    ctx->r5 = SUB32(ctx->r30, ctx->r2);
    // 0x80096234: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80096238: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x8009623C: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x80096240: subu        $t9, $t0, $v0
    ctx->r25 = SUB32(ctx->r8, ctx->r2);
    // 0x80096244: addu        $t8, $t0, $v0
    ctx->r24 = ADD32(ctx->r8, ctx->r2);
    // 0x80096248: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8009624C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80096250: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80096254: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80096258: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8009625C: sh          $a2, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r6;
    // 0x80096260: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80096264: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x80096268: lbu         $t3, 0x26($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X26);
    // 0x8009626C: lw          $t9, 0xE8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x80096270: lw          $t7, 0x1D0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x80096274: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80096278: bgez        $t9, L_8009628C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8009627C: addu        $v0, $t5, $t7
        ctx->r2 = ADD32(ctx->r13, ctx->r15);
            goto L_8009628C;
    }
    // 0x8009627C: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x80096280: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x80096284: addiu       $a3, $a3, 0x6F22
    ctx->r7 = ADD32(ctx->r7, 0X6F22);
    // 0x80096288: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8009628C:
    // 0x8009628C: lh          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_H(ctx->r7, 0X0));
    // 0x80096290: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x80096294: lw          $t3, 0x14C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80096298: addiu       $t4, $t4, 0x6F30
    ctx->r12 = ADD32(ctx->r12, 0X6F30);
    // 0x8009629C: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800962A0: addu        $v1, $t8, $t4
    ctx->r3 = ADD32(ctx->r24, ctx->r12);
    // 0x800962A4: subu        $a1, $t3, $v0
    ctx->r5 = SUB32(ctx->r11, ctx->r2);
    // 0x800962A8: addu        $t6, $fp, $v0
    ctx->r14 = ADD32(ctx->r30, ctx->r2);
    // 0x800962AC: subu        $t5, $fp, $v0
    ctx->r13 = SUB32(ctx->r30, ctx->r2);
    // 0x800962B0: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800962B4: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800962B8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800962BC: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x800962C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800962C4: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800962C8: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x800962CC: sh          $a2, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r6;
    // 0x800962D0: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800962D4: b           L_80096EEC
    // 0x800962D8: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
        goto L_80096EEC;
    // 0x800962D8: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_800962DC:
    // 0x800962DC: jal         0x800B4EA8
    // 0x800962E0: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    gettilesizy(rdram, ctx);
        goto after_9;
    // 0x800962E0: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_9:
    // 0x800962E4: lbu         $t8, 0x28($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X28);
    // 0x800962E8: andi        $t6, $s5, 0x80
    ctx->r14 = ctx->r21 & 0X80;
    // 0x800962EC: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800962F0: mflo        $s2
    ctx->r18 = lo;
    // 0x800962F4: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x800962F8: beq         $t6, $zero, L_80096314
    if (ctx->r14 == 0) {
        // 0x800962FC: or          $s2, $t4, $zero
        ctx->r18 = ctx->r12 | 0;
            goto L_80096314;
    }
    // 0x800962FC: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
    // 0x80096300: lw          $t3, 0x8($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80096304: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80096308: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8009630C: b           L_8009631C
    // 0x80096310: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
        goto L_8009631C;
    // 0x80096310: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
L_80096314:
    // 0x80096314: lw          $t9, 0x8($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80096318: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
L_8009631C:
    // 0x8009631C: jal         0x800B4F00
    // 0x80096320: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    getpicanm(rdram, ctx);
        goto after_10;
    // 0x80096320: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_10:
    // 0x80096324: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80096328: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8009632C: beql        $t8, $zero, L_80096368
    if (ctx->r24 == 0) {
        // 0x80096330: lw          $t3, 0x124($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X124));
            goto L_80096368;
    }
    goto skip_9;
    // 0x80096330: lw          $t3, 0x124($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X124));
    skip_9:
    // 0x80096334: jal         0x800B4F00
    // 0x80096338: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    getpicanm(rdram, ctx);
        goto after_11;
    // 0x80096338: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_11:
    // 0x8009633C: lbu         $t7, 0x28($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X28);
    // 0x80096340: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80096344: sll         $t3, $t6, 24
    ctx->r11 = S32(ctx->r14 << 24);
    // 0x80096348: sra         $t5, $t3, 24
    ctx->r13 = S32(SIGNED(ctx->r11) >> 24);
    // 0x8009634C: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096350: lw          $t4, 0x124($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X124));
    // 0x80096354: mflo        $t9
    ctx->r25 = lo;
    // 0x80096358: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8009635C: subu        $t6, $t4, $t8
    ctx->r14 = SUB32(ctx->r12, ctx->r24);
    // 0x80096360: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80096364: lw          $t3, 0x124($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X124));
L_80096368:
    // 0x80096368: lw          $t5, 0x1D4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1D4));
    // 0x8009636C: lw          $t4, 0x1C0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1C0));
    // 0x80096370: lw          $t9, 0x1D8($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1D8));
    // 0x80096374: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80096378: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x8009637C: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x80096380: subu        $v0, $t3, $s2
    ctx->r2 = SUB32(ctx->r11, ctx->r18);
    // 0x80096384: subu        $v0, $v0, $t9
    ctx->r2 = SUB32(ctx->r2, ctx->r25);
    // 0x80096388: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8009638C: beq         $at, $zero, L_80096EEC
    if (ctx->r1 == 0) {
        // 0x80096390: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80096EEC;
    }
    // 0x80096390: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80096394: beql        $at, $zero, L_80096EF0
    if (ctx->r1 == 0) {
        // 0x80096398: lw          $v0, 0x19C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80096EF0;
    }
    goto skip_10;
    // 0x80096398: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
    skip_10:
    // 0x8009639C: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800963A0: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x800963A4: jal         0x800B4F00
    // 0x800963A8: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    getpicanm(rdram, ctx);
        goto after_12;
    // 0x800963A8: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    after_12:
    // 0x800963AC: sra         $t6, $v0, 8
    ctx->r14 = S32(SIGNED(ctx->r2) >> 8);
    // 0x800963B0: lb          $t9, 0x29($s1)
    ctx->r25 = S32(MEM_B(ctx->r17, 0X29));
    // 0x800963B4: sll         $t3, $t6, 24
    ctx->r11 = S32(ctx->r14 << 24);
    // 0x800963B8: sra         $t5, $t3, 24
    ctx->r13 = S32(SIGNED(ctx->r11) >> 24);
    // 0x800963BC: andi        $t4, $s5, 0x4
    ctx->r12 = ctx->r21 & 0X4;
    // 0x800963C0: blez        $t4, L_800963CC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800963C4: addu        $s4, $t5, $t9
        ctx->r20 = ADD32(ctx->r13, ctx->r25);
            goto L_800963CC;
    }
    // 0x800963C4: addu        $s4, $t5, $t9
    ctx->r20 = ADD32(ctx->r13, ctx->r25);
    // 0x800963C8: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
L_800963CC:
    // 0x800963CC: lh          $s2, 0x14($s1)
    ctx->r18 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800963D0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800963D4: addiu       $v0, $v0, -0x9A0
    ctx->r2 = ADD32(ctx->r2, -0X9A0);
    // 0x800963D8: andi        $t7, $s2, 0x7FF
    ctx->r15 = ctx->r18 & 0X7FF;
    // 0x800963DC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800963E0: addu        $t6, $v0, $t8
    ctx->r14 = ADD32(ctx->r2, ctx->r24);
    // 0x800963E4: lbu         $s0, 0x27($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X27);
    // 0x800963E8: lh          $t3, 0x0($t6)
    ctx->r11 = S32(MEM_H(ctx->r14, 0X0));
    // 0x800963EC: addiu       $t9, $s2, 0x600
    ctx->r25 = ADD32(ctx->r18, 0X600);
    // 0x800963F0: andi        $t4, $t9, 0x7FF
    ctx->r12 = ctx->r25 & 0X7FF;
    // 0x800963F4: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800963F8: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800963FC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80096400: lh          $t6, 0x0($t8)
    ctx->r14 = S32(MEM_H(ctx->r24, 0X0));
    // 0x80096404: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    // 0x80096408: mflo        $t5
    ctx->r13 = lo;
    // 0x8009640C: sw          $t5, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r13;
    // 0x80096410: nop

    // 0x80096414: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096418: mflo        $t3
    ctx->r11 = lo;
    // 0x8009641C: sw          $t3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r11;
    // 0x80096420: jal         0x800B4E50
    // 0x80096424: nop

    gettilesizx(rdram, ctx);
        goto after_13;
    // 0x80096424: nop

    after_13:
    // 0x80096428: lw          $a1, 0x118($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X118));
    // 0x8009642C: sra         $t5, $v0, 1
    ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80096430: addu        $a3, $t5, $s4
    ctx->r7 = ADD32(ctx->r13, ctx->r20);
    // 0x80096434: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80096438: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8009643C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80096440: jal         0x8008FD60
    // 0x80096444: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_14;
    // 0x80096444: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_14:
    // 0x80096448: lw          $a1, 0x118($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X118));
    // 0x8009644C: sra         $a2, $s0, 31
    ctx->r6 = S32(SIGNED(ctx->r16) >> 31);
    // 0x80096450: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80096454: subu        $fp, $fp, $v0
    ctx->r30 = SUB32(ctx->r30, ctx->r2);
    // 0x80096458: sw          $s0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r16;
    // 0x8009645C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80096460: jal         0x8008FD60
    // 0x80096464: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_15;
    // 0x80096464: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_15:
    // 0x80096468: lw          $a1, 0x114($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X114));
    // 0x8009646C: addu        $s4, $v0, $fp
    ctx->r20 = ADD32(ctx->r2, ctx->r30);
    // 0x80096470: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80096474: sra         $a2, $s2, 31
    ctx->r6 = S32(SIGNED(ctx->r18) >> 31);
    // 0x80096478: jal         0x8008FD60
    // 0x8009647C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_16;
    // 0x8009647C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_16:
    // 0x80096480: lw          $t9, 0x14C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80096484: lw          $a1, 0x114($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80096488: lw          $a2, 0xA0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x8009648C: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x80096490: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
    // 0x80096494: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x80096498: jal         0x8008FD60
    // 0x8009649C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale16(rdram, ctx);
        goto after_17;
    // 0x8009649C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_17:
    // 0x800964A0: lw          $a3, 0x14C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x800964A4: lw          $t8, 0x138($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800964A8: lw          $a0, 0x140($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X140));
    // 0x800964AC: addu        $s2, $v0, $a3
    ctx->r18 = ADD32(ctx->r2, ctx->r7);
    // 0x800964B0: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800964B4: lw          $a1, 0x13C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800964B8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800964BC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800964C0: jal         0x80091C68
    // 0x800964C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    clipinsideboxline(rdram, ctx);
        goto after_18;
    // 0x800964C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_18:
    // 0x800964C8: beq         $v0, $zero, L_80096EEC
    if (ctx->r2 == 0) {
        // 0x800964CC: lw          $a3, 0x1D0($sp)
        ctx->r7 = S32(MEM_W(ctx->r29, 0X1D0));
            goto L_80096EEC;
    }
    // 0x800964CC: lw          $a3, 0x1D0($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x800964D0: lh          $t6, 0x14($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800964D4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800964D8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x800964DC: addiu       $t3, $t6, 0x300
    ctx->r11 = ADD32(ctx->r14, 0X300);
    // 0x800964E0: andi        $t4, $t3, 0x7FF
    ctx->r12 = ctx->r11 & 0X7FF;
    // 0x800964E4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800964E8: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800964EC: lh          $a1, -0x9A0($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, -0X9A0));
    // 0x800964F0: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x800964F4: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x800964F8: jal         0x8008FCD8
    // 0x800964FC: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale14(rdram, ctx);
        goto after_19;
    // 0x800964FC: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_19:
    // 0x80096500: sw          $v0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r2;
    // 0x80096504: lh          $t6, 0x14($s1)
    ctx->r14 = S32(MEM_H(ctx->r17, 0X14));
    // 0x80096508: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8009650C: lw          $a2, 0xA0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80096510: addiu       $t3, $t6, 0x100
    ctx->r11 = ADD32(ctx->r14, 0X100);
    // 0x80096514: andi        $t4, $t3, 0x7FF
    ctx->r12 = ctx->r11 & 0X7FF;
    // 0x80096518: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8009651C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80096520: lh          $a1, -0x9A0($t7)
    ctx->r5 = S32(MEM_H(ctx->r15, -0X9A0));
    // 0x80096524: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x80096528: jal         0x8008FCD8
    // 0x8009652C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale14(rdram, ctx);
        goto after_20;
    // 0x8009652C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_20:
    // 0x80096530: lw          $t8, 0x1B8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80096534: lw          $t9, 0x1BC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80096538: sw          $v0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r2;
    // 0x8009653C: lw          $v1, 0x0($t8)
    ctx->r3 = S32(MEM_W(ctx->r24, 0X0));
    // 0x80096540: lw          $a1, 0x0($t9)
    ctx->r5 = S32(MEM_W(ctx->r25, 0X0));
    // 0x80096544: lw          $t5, 0x14C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80096548: subu        $t6, $fp, $v1
    ctx->r14 = SUB32(ctx->r30, ctx->r3);
    // 0x8009654C: subu        $t3, $s2, $a1
    ctx->r11 = SUB32(ctx->r18, ctx->r5);
    // 0x80096550: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096554: subu        $t8, $s4, $v1
    ctx->r24 = SUB32(ctx->r20, ctx->r3);
    // 0x80096558: subu        $t7, $t5, $a1
    ctx->r15 = SUB32(ctx->r13, ctx->r5);
    // 0x8009655C: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80096560: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x80096564: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x80096568: addiu       $a1, $a1, 0x6F22
    ctx->r5 = ADD32(ctx->r5, 0X6F22);
    // 0x8009656C: addiu       $t3, $t3, 0x6F30
    ctx->r11 = ADD32(ctx->r11, 0X6F30);
    // 0x80096570: addu        $t5, $fp, $s3
    ctx->r13 = ADD32(ctx->r30, ctx->r19);
    // 0x80096574: mflo        $t4
    ctx->r12 = lo;
    // 0x80096578: nop

    // 0x8009657C: nop

    // 0x80096580: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096584: mflo        $t9
    ctx->r25 = lo;
    // 0x80096588: slt         $at, $t4, $t9
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8009658C: bne         $at, $zero, L_800965E4
    if (ctx->r1 != 0) {
        // 0x80096590: addu        $t4, $s4, $v0
        ctx->r12 = ADD32(ctx->r20, ctx->r2);
            goto L_800965E4;
    }
    // 0x80096590: addu        $t4, $s4, $v0
    ctx->r12 = ADD32(ctx->r20, ctx->r2);
    // 0x80096594: lh          $a0, 0x0($a1)
    ctx->r4 = S32(MEM_H(ctx->r5, 0X0));
    // 0x80096598: lh          $a2, 0x19E($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X19E));
    // 0x8009659C: lw          $t7, 0x14C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x800965A0: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800965A4: addu        $v1, $t6, $t3
    ctx->r3 = ADD32(ctx->r14, ctx->r11);
    // 0x800965A8: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x800965AC: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x800965B0: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800965B4: subu        $t9, $s2, $s3
    ctx->r25 = SUB32(ctx->r18, ctx->r19);
    // 0x800965B8: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800965BC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800965C0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800965C4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800965C8: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x800965CC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800965D0: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x800965D4: sh          $a2, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r6;
    // 0x800965D8: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x800965DC: b           L_80096654
    // 0x800965E0: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
        goto L_80096654;
    // 0x800965E0: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
L_800965E4:
    // 0x800965E4: andi        $t5, $s5, 0x40
    ctx->r13 = ctx->r21 & 0X40;
    // 0x800965E8: bne         $t5, $zero, L_80096EEC
    if (ctx->r13 != 0) {
        // 0x800965EC: lui         $a1, 0x8027
        ctx->r5 = S32(0X8027 << 16);
            goto L_80096EEC;
    }
    // 0x800965EC: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x800965F0: addiu       $a1, $a1, 0x6F22
    ctx->r5 = ADD32(ctx->r5, 0X6F22);
    // 0x800965F4: lh          $a0, 0x0($a1)
    ctx->r4 = S32(MEM_H(ctx->r5, 0X0));
    // 0x800965F8: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x800965FC: addiu       $t8, $t8, 0x6F30
    ctx->r24 = ADD32(ctx->r24, 0X6F30);
    // 0x80096600: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80096604: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80096608: lh          $a2, 0x19E($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X19E));
    // 0x8009660C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80096610: lw          $t3, 0x14C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80096614: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80096618: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8009661C: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80096620: subu        $t9, $s2, $v0
    ctx->r25 = SUB32(ctx->r18, ctx->r2);
    // 0x80096624: subu        $t6, $fp, $v0
    ctx->r14 = SUB32(ctx->r30, ctx->r2);
    // 0x80096628: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x8009662C: subu        $t4, $s4, $s3
    ctx->r12 = SUB32(ctx->r20, ctx->r19);
    // 0x80096630: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x80096634: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80096638: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8009663C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80096640: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80096644: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80096648: sh          $a2, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r6;
    // 0x8009664C: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x80096650: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
L_80096654:
    // 0x80096654: lw          $t9, 0x1BC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80096658: lw          $t4, 0x14C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x8009665C: lw          $t6, 0x1B8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80096660: lw          $a1, 0x0($t9)
    ctx->r5 = S32(MEM_W(ctx->r25, 0X0));
    // 0x80096664: subu        $t5, $s2, $t4
    ctx->r13 = SUB32(ctx->r18, ctx->r12);
    // 0x80096668: lw          $v1, 0x0($t6)
    ctx->r3 = S32(MEM_W(ctx->r14, 0X0));
    // 0x8009666C: subu        $t3, $a1, $t4
    ctx->r11 = SUB32(ctx->r5, ctx->r12);
    // 0x80096670: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096674: subu        $t8, $s4, $fp
    ctx->r24 = SUB32(ctx->r20, ctx->r30);
    // 0x80096678: subu        $t9, $v1, $fp
    ctx->r25 = SUB32(ctx->r3, ctx->r30);
    // 0x8009667C: mflo        $t7
    ctx->r15 = lo;
    // 0x80096680: nop

    // 0x80096684: nop

    // 0x80096688: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009668C: mflo        $t6
    ctx->r14 = lo;
    // 0x80096690: addu        $t3, $t7, $t6
    ctx->r11 = ADD32(ctx->r15, ctx->r14);
    // 0x80096694: bgez        $t3, L_800966F4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80096698: lui         $a3, 0x8027
        ctx->r7 = S32(0X8027 << 16);
            goto L_800966F4;
    }
    // 0x80096698: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x8009669C: addiu       $a3, $a3, 0x6F22
    ctx->r7 = ADD32(ctx->r7, 0X6F22);
    // 0x800966A0: lh          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800966A4: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x800966A8: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x800966AC: addiu       $t8, $t8, 0x6F30
    ctx->r24 = ADD32(ctx->r24, 0X6F30);
    // 0x800966B0: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800966B4: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x800966B8: addu        $t3, $t4, $v0
    ctx->r11 = ADD32(ctx->r12, ctx->r2);
    // 0x800966BC: addu        $t7, $t4, $s3
    ctx->r15 = ADD32(ctx->r12, ctx->r19);
    // 0x800966C0: subu        $t9, $fp, $v0
    ctx->r25 = SUB32(ctx->r30, ctx->r2);
    // 0x800966C4: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800966C8: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x800966CC: addu        $t6, $fp, $s3
    ctx->r14 = ADD32(ctx->r30, ctx->r19);
    // 0x800966D0: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x800966D4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800966D8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800966DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800966E0: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800966E4: sh          $a2, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r6;
    // 0x800966E8: addiu       $t5, $a0, 0x1
    ctx->r13 = ADD32(ctx->r4, 0X1);
    // 0x800966EC: b           L_80096EEC
    // 0x800966F0: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
        goto L_80096EEC;
    // 0x800966F0: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
L_800966F4:
    // 0x800966F4: lw          $t9, 0x14C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x800966F8: subu        $t8, $a1, $s2
    ctx->r24 = SUB32(ctx->r5, ctx->r18);
    // 0x800966FC: subu        $t3, $fp, $s4
    ctx->r11 = SUB32(ctx->r30, ctx->r20);
    // 0x80096700: subu        $t7, $t9, $s2
    ctx->r15 = SUB32(ctx->r25, ctx->r18);
    // 0x80096704: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096708: subu        $t4, $v1, $s4
    ctx->r12 = SUB32(ctx->r3, ctx->r20);
    // 0x8009670C: mflo        $t6
    ctx->r14 = lo;
    // 0x80096710: nop

    // 0x80096714: nop

    // 0x80096718: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009671C: mflo        $t5
    ctx->r13 = lo;
    // 0x80096720: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x80096724: bgez        $t9, L_80096EEC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80096728: lui         $a1, 0x8027
        ctx->r5 = S32(0X8027 << 16);
            goto L_80096EEC;
    }
    // 0x80096728: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x8009672C: addiu       $a1, $a1, 0x6F22
    ctx->r5 = ADD32(ctx->r5, 0X6F22);
    // 0x80096730: lh          $a0, 0x0($a1)
    ctx->r4 = S32(MEM_H(ctx->r5, 0X0));
    // 0x80096734: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x80096738: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x8009673C: addiu       $t7, $t7, 0x6F30
    ctx->r15 = ADD32(ctx->r15, 0X6F30);
    // 0x80096740: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x80096744: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x80096748: addu        $t3, $s4, $v0
    ctx->r11 = ADD32(ctx->r20, ctx->r2);
    // 0x8009674C: subu        $t5, $s2, $v0
    ctx->r13 = SUB32(ctx->r18, ctx->r2);
    // 0x80096750: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80096754: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80096758: subu        $t4, $s2, $s3
    ctx->r12 = SUB32(ctx->r18, ctx->r19);
    // 0x8009675C: subu        $t6, $s4, $s3
    ctx->r14 = SUB32(ctx->r20, ctx->r19);
    // 0x80096760: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80096764: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80096768: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8009676C: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80096770: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80096774: sh          $a2, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r6;
    // 0x80096778: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x8009677C: b           L_80096EEC
    // 0x80096780: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
        goto L_80096EEC;
    // 0x80096780: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
L_80096784:
    // 0x80096784: lw          $t7, 0x8($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80096788: lw          $t5, 0x1C0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1C0));
    // 0x8009678C: lw          $t6, 0x1D8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1D8));
    // 0x80096790: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x80096794: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x80096798: lw          $v1, 0x0($t5)
    ctx->r3 = S32(MEM_W(ctx->r13, 0X0));
    // 0x8009679C: lw          $a0, 0x8($s1)
    ctx->r4 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800967A0: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800967A4: beq         $at, $zero, L_80096EEC
    if (ctx->r1 == 0) {
        // 0x800967A8: subu        $v0, $a0, $t6
        ctx->r2 = SUB32(ctx->r4, ctx->r14);
            goto L_80096EEC;
    }
    // 0x800967A8: subu        $v0, $a0, $t6
    ctx->r2 = SUB32(ctx->r4, ctx->r14);
    // 0x800967AC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800967B0: beq         $at, $zero, L_80096EEC
    if (ctx->r1 == 0) {
        // 0x800967B4: andi        $t8, $s5, 0x40
        ctx->r24 = ctx->r21 & 0X40;
            goto L_80096EEC;
    }
    // 0x800967B4: andi        $t8, $s5, 0x40
    ctx->r24 = ctx->r21 & 0X40;
    // 0x800967B8: beq         $t8, $zero, L_800967D0
    if (ctx->r24 == 0) {
        // 0x800967BC: andi        $t7, $s5, 0x8
        ctx->r15 = ctx->r21 & 0X8;
            goto L_800967D0;
    }
    // 0x800967BC: andi        $t7, $s5, 0x8
    ctx->r15 = ctx->r21 & 0X8;
    // 0x800967C0: sltiu       $t3, $t7, 0x1
    ctx->r11 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800967C4: slt         $t4, $a0, $v1
    ctx->r12 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800967C8: beql        $t3, $t4, L_80096EF0
    if (ctx->r11 == ctx->r12) {
        // 0x800967CC: lw          $v0, 0x19C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80096EF0;
    }
    goto skip_11;
    // 0x800967CC: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
    skip_11:
L_800967D0:
    // 0x800967D0: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800967D4: lw          $t6, 0x1D0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1D0));
    // 0x800967D8: andi        $s2, $s5, 0x8
    ctx->r18 = ctx->r21 & 0X8;
    // 0x800967DC: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x800967E0: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800967E4: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
    // 0x800967E8: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    // 0x800967EC: jal         0x800B4F00
    // 0x800967F0: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    getpicanm(rdram, ctx);
        goto after_21;
    // 0x800967F0: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    after_21:
    // 0x800967F4: sra         $t7, $v0, 8
    ctx->r15 = S32(SIGNED(ctx->r2) >> 8);
    // 0x800967F8: lb          $t6, 0x29($s1)
    ctx->r14 = S32(MEM_B(ctx->r17, 0X29));
    // 0x800967FC: sll         $t3, $t7, 24
    ctx->r11 = S32(ctx->r15 << 24);
    // 0x80096800: sra         $t4, $t3, 24
    ctx->r12 = S32(SIGNED(ctx->r11) >> 24);
    // 0x80096804: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    // 0x80096808: jal         0x800B4F00
    // 0x8009680C: addu        $s4, $t4, $t6
    ctx->r20 = ADD32(ctx->r12, ctx->r14);
    getpicanm(rdram, ctx);
        goto after_22;
    // 0x8009680C: addu        $s4, $t4, $t6
    ctx->r20 = ADD32(ctx->r12, ctx->r14);
    after_22:
    // 0x80096810: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80096814: lb          $t3, 0x2A($s1)
    ctx->r11 = S32(MEM_B(ctx->r17, 0X2A));
    // 0x80096818: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x8009681C: sra         $t7, $t5, 24
    ctx->r15 = S32(SIGNED(ctx->r13) >> 24);
    // 0x80096820: andi        $t4, $s5, 0x4
    ctx->r12 = ctx->r21 & 0X4;
    // 0x80096824: blez        $t4, L_80096830
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80096828: addu        $s0, $t7, $t3
        ctx->r16 = ADD32(ctx->r15, ctx->r11);
            goto L_80096830;
    }
    // 0x80096828: addu        $s0, $t7, $t3
    ctx->r16 = ADD32(ctx->r15, ctx->r11);
    // 0x8009682C: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
L_80096830:
    // 0x80096830: blez        $s2, L_8009683C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80096834: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_8009683C;
    }
    // 0x80096834: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80096838: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_8009683C:
    // 0x8009683C: lh          $s2, 0x14($s1)
    ctx->r18 = S32(MEM_H(ctx->r17, 0X14));
    // 0x80096840: addiu       $v0, $v0, -0x9A0
    ctx->r2 = ADD32(ctx->r2, -0X9A0);
    // 0x80096844: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    // 0x80096848: addiu       $t6, $s2, 0x200
    ctx->r14 = ADD32(ctx->r18, 0X200);
    // 0x8009684C: andi        $t8, $t6, 0x7FF
    ctx->r24 = ctx->r14 & 0X7FF;
    // 0x80096850: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    // 0x80096854: addu        $t3, $v0, $t7
    ctx->r11 = ADD32(ctx->r2, ctx->r15);
    // 0x80096858: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8009685C: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x80096860: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x80096864: lh          $s5, 0x0($t5)
    ctx->r21 = S32(MEM_H(ctx->r13, 0X0));
    // 0x80096868: jal         0x800B4E50
    // 0x8009686C: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
    gettilesizx(rdram, ctx);
        goto after_23;
    // 0x8009686C: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
    after_23:
    // 0x80096870: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80096874: lbu         $s6, 0x27($s1)
    ctx->r22 = MEM_BU(ctx->r17, 0X27);
    // 0x80096878: jal         0x800B4EA8
    // 0x8009687C: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    gettilesizy(rdram, ctx);
        goto after_24;
    // 0x8009687C: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    after_24:
    // 0x80096880: sra         $t6, $s2, 1
    ctx->r14 = S32(SIGNED(ctx->r18) >> 1);
    // 0x80096884: addu        $t8, $t6, $s4
    ctx->r24 = ADD32(ctx->r14, ctx->r20);
    // 0x80096888: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009688C: sw          $v0, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r2;
    // 0x80096890: lbu         $s7, 0x28($s1)
    ctx->r23 = MEM_BU(ctx->r17, 0X28);
    // 0x80096894: sra         $t5, $v0, 1
    ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80096898: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x8009689C: lw          $a1, 0xFC($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XFC));
    // 0x800968A0: sra         $t8, $s5, 31
    ctx->r24 = S32(SIGNED(ctx->r21) >> 31);
    // 0x800968A4: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x800968A8: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800968AC: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800968B0: mflo        $a3
    ctx->r7 = lo;
    // 0x800968B4: sw          $a3, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r7;
    // 0x800968B8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x800968BC: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800968C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800968C4: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x800968C8: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x800968CC: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800968D0: mflo        $t3
    ctx->r11 = lo;
    // 0x800968D4: sra         $t6, $t3, 31
    ctx->r14 = S32(SIGNED(ctx->r11) >> 31);
    // 0x800968D8: sw          $t3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r11;
    // 0x800968DC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800968E0: jal         0x80090874
    // 0x800968E4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    dmulscale16(rdram, ctx);
        goto after_25;
    // 0x800968E4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_25:
    // 0x800968E8: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x800968EC: lw          $a3, 0x114($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X114));
    // 0x800968F0: negu        $t9, $s5
    ctx->r25 = SUB32(0, ctx->r21);
    // 0x800968F4: addu        $t8, $v0, $fp
    ctx->r24 = ADD32(ctx->r2, ctx->r30);
    // 0x800968F8: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x800968FC: sra         $t4, $t9, 31
    ctx->r12 = S32(SIGNED(ctx->r25) >> 31);
    // 0x80096900: sra         $t6, $s3, 31
    ctx->r14 = S32(SIGNED(ctx->r19) >> 31);
    // 0x80096904: sw          $t8, 0x6EE0($at)
    MEM_W(0X6EE0, ctx->r1) = ctx->r24;
    // 0x80096908: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8009690C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80096910: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80096914: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80096918: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x8009691C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80096920: jal         0x80090874
    // 0x80096924: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    dmulscale16(rdram, ctx);
        goto after_26;
    // 0x80096924: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_26:
    // 0x80096928: multu       $s2, $s6
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009692C: lw          $t3, 0x14C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80096930: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80096934: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80096938: addu        $t8, $v0, $t3
    ctx->r24 = ADD32(ctx->r2, ctx->r11);
    // 0x8009693C: sw          $t8, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = ctx->r24;
    // 0x80096940: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80096944: mflo        $a3
    ctx->r7 = lo;
    // 0x80096948: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x8009694C: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80096950: jal         0x8008FD60
    // 0x80096954: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    mulscale16(rdram, ctx);
        goto after_27;
    // 0x80096954: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    after_27:
    // 0x80096958: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x8009695C: addiu       $v1, $v1, 0x6EE0
    ctx->r3 = ADD32(ctx->r3, 0X6EE0);
    // 0x80096960: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80096964: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x80096968: lw          $a1, 0x94($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X94));
    // 0x8009696C: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80096970: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80096974: lw          $a2, 0x88($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80096978: jal         0x8008FD60
    // 0x8009697C: lw          $a3, 0x8C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X8C));
    mulscale16(rdram, ctx);
        goto after_28;
    // 0x8009697C: lw          $a3, 0x8C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X8C));
    after_28:
    // 0x80096980: lw          $t9, 0x104($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X104));
    // 0x80096984: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x80096988: addiu       $v1, $v1, 0x6F00
    ctx->r3 = ADD32(ctx->r3, 0X6F00);
    // 0x8009698C: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096990: lw          $t3, 0x0($v1)
    ctx->r11 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80096994: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x80096998: lw          $a1, 0x94($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X94));
    // 0x8009699C: addu        $t8, $v0, $t3
    ctx->r24 = ADD32(ctx->r2, ctx->r11);
    // 0x800969A0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800969A4: mflo        $a3
    ctx->r7 = lo;
    // 0x800969A8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x800969AC: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800969B0: jal         0x8008FD60
    // 0x800969B4: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    mulscale16(rdram, ctx);
        goto after_29;
    // 0x800969B4: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    after_29:
    // 0x800969B8: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800969BC: addiu       $v1, $v1, 0x6EE0
    ctx->r3 = ADD32(ctx->r3, 0X6EE0);
    // 0x800969C0: lw          $t5, 0x4($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800969C4: lw          $t8, 0x0($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800969C8: negu        $s0, $v0
    ctx->r16 = SUB32(0, ctx->r2);
    // 0x800969CC: addu        $t3, $t5, $s0
    ctx->r11 = ADD32(ctx->r13, ctx->r16);
    // 0x800969D0: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800969D4: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x800969D8: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800969DC: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800969E0: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800969E4: lw          $a2, 0x88($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X88));
    // 0x800969E8: jal         0x8008FD60
    // 0x800969EC: lw          $a3, 0x8C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X8C));
    mulscale16(rdram, ctx);
        goto after_30;
    // 0x800969EC: lw          $a3, 0x8C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X8C));
    after_30:
    // 0x800969F0: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800969F4: addiu       $v1, $v1, 0x6F00
    ctx->r3 = ADD32(ctx->r3, 0X6F00);
    // 0x800969F8: lw          $t4, 0x4($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800969FC: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80096A00: negu        $s0, $v0
    ctx->r16 = SUB32(0, ctx->r2);
    // 0x80096A04: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x80096A08: addu        $t5, $t7, $s0
    ctx->r13 = ADD32(ctx->r15, ctx->r16);
    // 0x80096A0C: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80096A10: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80096A14: lh          $t3, 0x14($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0X14));
    // 0x80096A18: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80096A1C: lw          $a2, 0xA0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80096A20: addiu       $t8, $t3, 0x100
    ctx->r24 = ADD32(ctx->r11, 0X100);
    // 0x80096A24: andi        $t9, $t8, 0x7FF
    ctx->r25 = ctx->r24 & 0X7FF;
    // 0x80096A28: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x80096A2C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80096A30: lh          $a1, -0x9A0($t6)
    ctx->r5 = S32(MEM_H(ctx->r14, -0X9A0));
    // 0x80096A34: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x80096A38: jal         0x8008FCD8
    // 0x80096A3C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale14(rdram, ctx);
        goto after_31;
    // 0x80096A3C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_31:
    // 0x80096A40: sw          $v0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r2;
    // 0x80096A44: lh          $t7, 0x14($s1)
    ctx->r15 = S32(MEM_H(ctx->r17, 0X14));
    // 0x80096A48: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80096A4C: lw          $a2, 0xA0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80096A50: addiu       $t5, $t7, -0x100
    ctx->r13 = ADD32(ctx->r15, -0X100);
    // 0x80096A54: andi        $t3, $t5, 0x7FF
    ctx->r11 = ctx->r13 & 0X7FF;
    // 0x80096A58: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x80096A5C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80096A60: lh          $a1, -0x9A0($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, -0X9A0));
    // 0x80096A64: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x80096A68: jal         0x8008FCD8
    // 0x80096A6C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale14(rdram, ctx);
        goto after_32;
    // 0x80096A6C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_32:
    // 0x80096A70: lw          $t4, 0x1B8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80096A74: lw          $t6, 0x1BC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80096A78: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x80096A7C: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x80096A80: sw          $v0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r2;
    // 0x80096A84: addiu       $t0, $t0, 0x6F00
    ctx->r8 = ADD32(ctx->r8, 0X6F00);
    // 0x80096A88: addiu       $a3, $a3, 0x6EE0
    ctx->r7 = ADD32(ctx->r7, 0X6EE0);
    // 0x80096A8C: lw          $s0, 0x0($a3)
    ctx->r16 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80096A90: lw          $s5, 0x4($t0)
    ctx->r21 = S32(MEM_W(ctx->r8, 0X4));
    // 0x80096A94: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x80096A98: lw          $a1, 0x0($t6)
    ctx->r5 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80096A9C: lw          $s4, 0x4($a3)
    ctx->r20 = S32(MEM_W(ctx->r7, 0X4));
    // 0x80096AA0: subu        $t7, $s0, $v1
    ctx->r15 = SUB32(ctx->r16, ctx->r3);
    // 0x80096AA4: subu        $a0, $s5, $a1
    ctx->r4 = SUB32(ctx->r21, ctx->r5);
    // 0x80096AA8: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096AAC: lw          $s1, 0x0($t0)
    ctx->r17 = S32(MEM_W(ctx->r8, 0X0));
    // 0x80096AB0: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
    // 0x80096AB4: lui         $s2, 0x8027
    ctx->r18 = S32(0X8027 << 16);
    // 0x80096AB8: subu        $t3, $s1, $a1
    ctx->r11 = SUB32(ctx->r17, ctx->r5);
    // 0x80096ABC: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80096AC0: mflo        $t5
    ctx->r13 = lo;
    // 0x80096AC4: nop

    // 0x80096AC8: nop

    // 0x80096ACC: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096AD0: mflo        $t8
    ctx->r24 = lo;
    // 0x80096AD4: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80096AD8: beq         $at, $zero, L_80096BD0
    if (ctx->r1 == 0) {
        // 0x80096ADC: nop
    
            goto L_80096BD0;
    }
    // 0x80096ADC: nop

    // 0x80096AE0: lw          $t9, 0x138($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80096AE4: lw          $a0, 0x140($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X140));
    // 0x80096AE8: lw          $a1, 0x13C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80096AEC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80096AF0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80096AF4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80096AF8: jal         0x80091C68
    // 0x80096AFC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    clipinsideboxline(rdram, ctx);
        goto after_33;
    // 0x80096AFC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_33:
    // 0x80096B00: beq         $v0, $zero, L_80096B90
    if (ctx->r2 == 0) {
        // 0x80096B04: lui         $s4, 0x8027
        ctx->r20 = S32(0X8027 << 16);
            goto L_80096B90;
    }
    // 0x80096B04: lui         $s4, 0x8027
    ctx->r20 = S32(0X8027 << 16);
    // 0x80096B08: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80096B0C: addiu       $v0, $v0, 0x6F22
    ctx->r2 = ADD32(ctx->r2, 0X6F22);
    // 0x80096B10: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x80096B14: lh          $a0, 0x0($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80096B18: addiu       $a1, $a1, 0x6EE0
    ctx->r5 = ADD32(ctx->r5, 0X6EE0);
    // 0x80096B1C: lw          $s0, 0x114($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80096B20: lw          $t7, 0x4($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X4));
    // 0x80096B24: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x80096B28: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x80096B2C: addiu       $a2, $a2, 0x6F00
    ctx->r6 = ADD32(ctx->r6, 0X6F00);
    // 0x80096B30: addiu       $t6, $t6, 0x6F30
    ctx->r14 = ADD32(ctx->r14, 0X6F30);
    // 0x80096B34: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x80096B38: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80096B3C: lw          $t5, 0x4($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X4));
    // 0x80096B40: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x80096B44: subu        $t3, $t7, $s0
    ctx->r11 = SUB32(ctx->r15, ctx->r16);
    // 0x80096B48: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80096B4C: lh          $t3, 0x19E($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0X19E));
    // 0x80096B50: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
    // 0x80096B54: lw          $t9, 0x0($a1)
    ctx->r25 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80096B58: addu        $t8, $t5, $s3
    ctx->r24 = ADD32(ctx->r13, ctx->r19);
    // 0x80096B5C: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80096B60: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80096B64: addu        $t5, $t3, $at
    ctx->r13 = ADD32(ctx->r11, ctx->r1);
    // 0x80096B68: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80096B6C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80096B70: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80096B74: addu        $t4, $t9, $s3
    ctx->r12 = ADD32(ctx->r25, ctx->r19);
    // 0x80096B78: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80096B7C: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x80096B80: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80096B84: sh          $t5, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r13;
    // 0x80096B88: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x80096B8C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_80096B90:
    // 0x80096B90: lw          $t4, 0x1B8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80096B94: lw          $t6, 0x1BC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80096B98: lui         $s5, 0x8027
    ctx->r21 = S32(0X8027 << 16);
    // 0x80096B9C: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x80096BA0: lw          $a1, 0x0($t6)
    ctx->r5 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80096BA4: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x80096BA8: lui         $s1, 0x8027
    ctx->r17 = S32(0X8027 << 16);
    // 0x80096BAC: lw          $s1, 0x6F08($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X6F08));
    // 0x80096BB0: lw          $s0, 0x6EE8($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X6EE8));
    // 0x80096BB4: lw          $s5, 0x6F04($s5)
    ctx->r21 = S32(MEM_W(ctx->r21, 0X6F04));
    // 0x80096BB8: lw          $s4, 0x6EE4($s4)
    ctx->r20 = S32(MEM_W(ctx->r20, 0X6EE4));
    // 0x80096BBC: subu        $a3, $s1, $a1
    ctx->r7 = SUB32(ctx->r17, ctx->r5);
    // 0x80096BC0: subu        $v0, $s0, $v1
    ctx->r2 = SUB32(ctx->r16, ctx->r3);
    // 0x80096BC4: subu        $a0, $s5, $a1
    ctx->r4 = SUB32(ctx->r21, ctx->r5);
    // 0x80096BC8: b           L_80096D10
    // 0x80096BCC: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
        goto L_80096D10;
    // 0x80096BCC: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
L_80096BD0:
    // 0x80096BD0: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x80096BD4: lw          $s0, 0x6EE8($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X6EE8));
    // 0x80096BD8: lw          $s2, 0x6F0C($s2)
    ctx->r18 = S32(MEM_W(ctx->r18, 0X6F0C));
    // 0x80096BDC: lui         $s1, 0x8027
    ctx->r17 = S32(0X8027 << 16);
    // 0x80096BE0: subu        $v0, $s0, $v1
    ctx->r2 = SUB32(ctx->r16, ctx->r3);
    // 0x80096BE4: subu        $t7, $s2, $a1
    ctx->r15 = SUB32(ctx->r18, ctx->r5);
    // 0x80096BE8: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096BEC: lui         $s3, 0x8027
    ctx->r19 = S32(0X8027 << 16);
    // 0x80096BF0: lw          $s3, 0x6EEC($s3)
    ctx->r19 = S32(MEM_W(ctx->r19, 0X6EEC));
    // 0x80096BF4: lw          $s1, 0x6F08($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X6F08));
    // 0x80096BF8: subu        $t5, $s3, $v1
    ctx->r13 = SUB32(ctx->r19, ctx->r3);
    // 0x80096BFC: subu        $a3, $s1, $a1
    ctx->r7 = SUB32(ctx->r17, ctx->r5);
    // 0x80096C00: mflo        $t3
    ctx->r11 = lo;
    // 0x80096C04: nop

    // 0x80096C08: nop

    // 0x80096C0C: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096C10: mflo        $t8
    ctx->r24 = lo;
    // 0x80096C14: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80096C18: beq         $at, $zero, L_80096D10
    if (ctx->r1 == 0) {
        // 0x80096C1C: nop
    
            goto L_80096D10;
    }
    // 0x80096C1C: nop

    // 0x80096C20: lw          $t9, 0x138($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80096C24: lw          $a0, 0x140($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X140));
    // 0x80096C28: lw          $a1, 0x13C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80096C2C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80096C30: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80096C34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80096C38: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80096C3C: jal         0x80091C68
    // 0x80096C40: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    clipinsideboxline(rdram, ctx);
        goto after_34;
    // 0x80096C40: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_34:
    // 0x80096C44: beq         $v0, $zero, L_80096CD4
    if (ctx->r2 == 0) {
        // 0x80096C48: lui         $s4, 0x8027
        ctx->r20 = S32(0X8027 << 16);
            goto L_80096CD4;
    }
    // 0x80096C48: lui         $s4, 0x8027
    ctx->r20 = S32(0X8027 << 16);
    // 0x80096C4C: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80096C50: addiu       $v0, $v0, 0x6F22
    ctx->r2 = ADD32(ctx->r2, 0X6F22);
    // 0x80096C54: lh          $a0, 0x0($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80096C58: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x80096C5C: lw          $s0, 0x114($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80096C60: lw          $t7, 0x6EEC($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, 0X6EEC));
    // 0x80096C64: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x80096C68: addiu       $t6, $t6, 0x6F30
    ctx->r14 = ADD32(ctx->r14, 0X6F30);
    // 0x80096C6C: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x80096C70: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x80096C74: addu        $t5, $t7, $s0
    ctx->r13 = ADD32(ctx->r15, ctx->r16);
    // 0x80096C78: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80096C7C: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x80096C80: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80096C84: lw          $t3, 0x6F0C($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X6F0C));
    // 0x80096C88: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x80096C8C: lh          $t5, 0x19E($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0X19E));
    // 0x80096C90: subu        $t8, $t3, $s3
    ctx->r24 = SUB32(ctx->r11, ctx->r19);
    // 0x80096C94: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80096C98: lw          $t9, 0x6EE8($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X6EE8));
    // 0x80096C9C: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x80096CA0: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80096CA4: subu        $t4, $t9, $s3
    ctx->r12 = SUB32(ctx->r25, ctx->r19);
    // 0x80096CA8: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80096CAC: lw          $t6, 0x6F08($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, 0X6F08));
    // 0x80096CB0: addu        $t3, $t5, $at
    ctx->r11 = ADD32(ctx->r13, ctx->r1);
    // 0x80096CB4: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80096CB8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80096CBC: subu        $t7, $t6, $s0
    ctx->r15 = SUB32(ctx->r14, ctx->r16);
    // 0x80096CC0: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x80096CC4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80096CC8: sh          $t3, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r11;
    // 0x80096CCC: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x80096CD0: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_80096CD4:
    // 0x80096CD4: lw          $t4, 0x1B8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80096CD8: lw          $t6, 0x1BC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80096CDC: lui         $s5, 0x8027
    ctx->r21 = S32(0X8027 << 16);
    // 0x80096CE0: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x80096CE4: lw          $a1, 0x0($t6)
    ctx->r5 = S32(MEM_W(ctx->r14, 0X0));
    // 0x80096CE8: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x80096CEC: lui         $s1, 0x8027
    ctx->r17 = S32(0X8027 << 16);
    // 0x80096CF0: lw          $s1, 0x6F08($s1)
    ctx->r17 = S32(MEM_W(ctx->r17, 0X6F08));
    // 0x80096CF4: lw          $s0, 0x6EE8($s0)
    ctx->r16 = S32(MEM_W(ctx->r16, 0X6EE8));
    // 0x80096CF8: lw          $s5, 0x6F04($s5)
    ctx->r21 = S32(MEM_W(ctx->r21, 0X6F04));
    // 0x80096CFC: lw          $s4, 0x6EE4($s4)
    ctx->r20 = S32(MEM_W(ctx->r20, 0X6EE4));
    // 0x80096D00: subu        $a3, $s1, $a1
    ctx->r7 = SUB32(ctx->r17, ctx->r5);
    // 0x80096D04: subu        $v0, $s0, $v1
    ctx->r2 = SUB32(ctx->r16, ctx->r3);
    // 0x80096D08: subu        $a0, $s5, $a1
    ctx->r4 = SUB32(ctx->r21, ctx->r5);
    // 0x80096D0C: subu        $a2, $s4, $v1
    ctx->r6 = SUB32(ctx->r20, ctx->r3);
L_80096D10:
    // 0x80096D10: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096D14: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80096D18: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80096D1C: mflo        $t7
    ctx->r15 = lo;
    // 0x80096D20: nop

    // 0x80096D24: nop

    // 0x80096D28: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096D2C: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80096D30: lui         $a0, 0x8027
    ctx->r4 = S32(0X8027 << 16);
    // 0x80096D34: addiu       $a0, $a0, 0x6F00
    ctx->r4 = ADD32(ctx->r4, 0X6F00);
    // 0x80096D38: addiu       $v0, $v0, 0x6EE0
    ctx->r2 = ADD32(ctx->r2, 0X6EE0);
    // 0x80096D3C: mflo        $t5
    ctx->r13 = lo;
    // 0x80096D40: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80096D44: beql        $at, $zero, L_80096DFC
    if (ctx->r1 == 0) {
        // 0x80096D48: lw          $s3, 0xC($v0)
        ctx->r19 = S32(MEM_W(ctx->r2, 0XC));
            goto L_80096DFC;
    }
    goto skip_12;
    // 0x80096D48: lw          $s3, 0xC($v0)
    ctx->r19 = S32(MEM_W(ctx->r2, 0XC));
    skip_12:
    // 0x80096D4C: lw          $t3, 0x138($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80096D50: lw          $a0, 0x140($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X140));
    // 0x80096D54: lw          $a1, 0x13C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80096D58: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80096D5C: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80096D60: jal         0x80091C68
    // 0x80096D64: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    clipinsideboxline(rdram, ctx);
        goto after_35;
    // 0x80096D64: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_35:
    // 0x80096D68: beq         $v0, $zero, L_80096EEC
    if (ctx->r2 == 0) {
        // 0x80096D6C: lui         $a1, 0x8027
        ctx->r5 = S32(0X8027 << 16);
            goto L_80096EEC;
    }
    // 0x80096D6C: lui         $a1, 0x8027
    ctx->r5 = S32(0X8027 << 16);
    // 0x80096D70: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80096D74: addiu       $v0, $v0, 0x6F22
    ctx->r2 = ADD32(ctx->r2, 0X6F22);
    // 0x80096D78: lh          $a0, 0x0($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80096D7C: addiu       $a1, $a1, 0x6EE0
    ctx->r5 = ADD32(ctx->r5, 0X6EE0);
    // 0x80096D80: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80096D84: lw          $t4, 0x8($a1)
    ctx->r12 = S32(MEM_W(ctx->r5, 0X8));
    // 0x80096D88: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x80096D8C: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x80096D90: addiu       $a2, $a2, 0x6F00
    ctx->r6 = ADD32(ctx->r6, 0X6F00);
    // 0x80096D94: addiu       $t9, $t9, 0x6F30
    ctx->r25 = ADD32(ctx->r25, 0X6F30);
    // 0x80096D98: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x80096D9C: lw          $s0, 0x114($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80096DA0: lw          $t7, 0x8($a2)
    ctx->r15 = S32(MEM_W(ctx->r6, 0X8));
    // 0x80096DA4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80096DA8: subu        $t6, $t4, $s3
    ctx->r14 = SUB32(ctx->r12, ctx->r19);
    // 0x80096DAC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80096DB0: lh          $t6, 0x19E($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X19E));
    // 0x80096DB4: lw          $t9, 0x4($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X4));
    // 0x80096DB8: lw          $t3, 0x4($a1)
    ctx->r11 = S32(MEM_W(ctx->r5, 0X4));
    // 0x80096DBC: subu        $t5, $t7, $s0
    ctx->r13 = SUB32(ctx->r15, ctx->r16);
    // 0x80096DC0: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80096DC4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80096DC8: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80096DCC: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80096DD0: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x80096DD4: addu        $t4, $t9, $s3
    ctx->r12 = ADD32(ctx->r25, ctx->r19);
    // 0x80096DD8: subu        $t8, $t3, $s0
    ctx->r24 = SUB32(ctx->r11, ctx->r16);
    // 0x80096DDC: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80096DE0: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x80096DE4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80096DE8: sh          $t7, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r15;
    // 0x80096DEC: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x80096DF0: b           L_80096EEC
    // 0x80096DF4: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
        goto L_80096EEC;
    // 0x80096DF4: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80096DF8: lw          $s3, 0xC($v0)
    ctx->r19 = S32(MEM_W(ctx->r2, 0XC));
L_80096DFC:
    // 0x80096DFC: lw          $s1, 0x0($a0)
    ctx->r17 = S32(MEM_W(ctx->r4, 0X0));
    // 0x80096E00: lw          $s2, 0xC($a0)
    ctx->r18 = S32(MEM_W(ctx->r4, 0XC));
    // 0x80096E04: subu        $t8, $s3, $v1
    ctx->r24 = SUB32(ctx->r19, ctx->r3);
    // 0x80096E08: subu        $t9, $s1, $a1
    ctx->r25 = SUB32(ctx->r17, ctx->r5);
    // 0x80096E0C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096E10: lw          $s0, 0x0($v0)
    ctx->r16 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80096E14: subu        $t6, $s2, $a1
    ctx->r14 = SUB32(ctx->r18, ctx->r5);
    // 0x80096E18: lw          $a1, 0x13C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80096E1C: subu        $t7, $s0, $v1
    ctx->r15 = SUB32(ctx->r16, ctx->r3);
    // 0x80096E20: lw          $a0, 0x140($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X140));
    // 0x80096E24: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80096E28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80096E2C: mflo        $t4
    ctx->r12 = lo;
    // 0x80096E30: nop

    // 0x80096E34: nop

    // 0x80096E38: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096E3C: mflo        $t5
    ctx->r13 = lo;
    // 0x80096E40: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80096E44: beql        $at, $zero, L_80096EF0
    if (ctx->r1 == 0) {
        // 0x80096E48: lw          $v0, 0x19C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80096EF0;
    }
    goto skip_13;
    // 0x80096E48: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
    skip_13:
    // 0x80096E4C: lw          $t3, 0x138($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80096E50: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80096E54: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80096E58: jal         0x80091C68
    // 0x80096E5C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    clipinsideboxline(rdram, ctx);
        goto after_36;
    // 0x80096E5C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_36:
    // 0x80096E60: beq         $v0, $zero, L_80096EEC
    if (ctx->r2 == 0) {
        // 0x80096E64: lw          $s0, 0x114($sp)
        ctx->r16 = S32(MEM_W(ctx->r29, 0X114));
            goto L_80096EEC;
    }
    // 0x80096E64: lw          $s0, 0x114($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80096E68: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80096E6C: addiu       $v0, $v0, 0x6F22
    ctx->r2 = ADD32(ctx->r2, 0X6F22);
    // 0x80096E70: lh          $a0, 0x0($v0)
    ctx->r4 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80096E74: lui         $t6, 0x8027
    ctx->r14 = S32(0X8027 << 16);
    // 0x80096E78: lw          $s3, 0x118($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X118));
    // 0x80096E7C: lw          $t6, 0x6EE0($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, 0X6EE0));
    // 0x80096E80: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x80096E84: addiu       $t9, $t9, 0x6F30
    ctx->r25 = ADD32(ctx->r25, 0X6F30);
    // 0x80096E88: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x80096E8C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80096E90: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x80096E94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80096E98: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x80096E9C: lw          $t4, 0x6F00($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, 0X6F00));
    // 0x80096EA0: lui         $t3, 0x8027
    ctx->r11 = S32(0X8027 << 16);
    // 0x80096EA4: lh          $t7, 0x19E($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0X19E));
    // 0x80096EA8: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80096EAC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80096EB0: lw          $t3, 0x6EEC($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, 0X6EEC));
    // 0x80096EB4: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x80096EB8: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x80096EBC: addu        $t8, $t3, $s0
    ctx->r24 = ADD32(ctx->r11, ctx->r16);
    // 0x80096EC0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80096EC4: lw          $t9, 0x6F0C($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, 0X6F0C));
    // 0x80096EC8: addu        $t4, $t7, $at
    ctx->r12 = ADD32(ctx->r15, ctx->r1);
    // 0x80096ECC: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80096ED0: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x80096ED4: subu        $t6, $t9, $s3
    ctx->r14 = SUB32(ctx->r25, ctx->r19);
    // 0x80096ED8: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x80096EDC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80096EE0: sh          $t4, -0x6CC8($at)
    MEM_H(-0X6CC8, ctx->r1) = ctx->r12;
    // 0x80096EE4: addiu       $t3, $a0, 0x1
    ctx->r11 = ADD32(ctx->r4, 0X1);
    // 0x80096EE8: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_80096EEC:
    // 0x80096EEC: lw          $v0, 0x19C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X19C));
L_80096EF0:
    // 0x80096EF0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80096EF4: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80096EF8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80096EFC: lh          $v0, 0x4FA0($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X4FA0));
    // 0x80096F00: bgez        $v0, L_80096094
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80096F04: sw          $v0, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r2;
            goto L_80096094;
    }
    // 0x80096F04: sw          $v0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r2;
L_80096F08:
    // 0x80096F08: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x80096F0C: lh          $t6, -0x6CD0($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X6CD0));
    // 0x80096F10: lw          $t9, 0x164($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80096F14: lui         $s4, 0x8010
    ctx->r20 = S32(0X8010 << 16);
    // 0x80096F18: addiu       $s4, $s4, -0x9F8
    ctx->r20 = ADD32(ctx->r20, -0X9F8);
    // 0x80096F1C: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80096F20: bne         $at, $zero, L_80095A28
    if (ctx->r1 != 0) {
        // 0x80096F24: addiu       $fp, $sp, 0x17C
        ctx->r30 = ADD32(ctx->r29, 0X17C);
            goto L_80095A28;
    }
    // 0x80096F24: addiu       $fp, $sp, 0x17C
    ctx->r30 = ADD32(ctx->r29, 0X17C);
    // 0x80096F28: lw          $s5, 0x0($s4)
    ctx->r21 = S32(MEM_W(ctx->r20, 0X0));
    // 0x80096F2C: addiu       $s7, $sp, 0x180
    ctx->r23 = ADD32(ctx->r29, 0X180);
    // 0x80096F30: lw          $t7, 0x188($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X188));
L_80096F34:
    // 0x80096F34: lw          $t4, 0x184($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80096F38: lw          $t5, 0x1B8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80096F3C: lw          $t3, 0x1BC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80096F40: sw          $t7, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r15;
    // 0x80096F44: sw          $t4, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r12;
    // 0x80096F48: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80096F4C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x80096F50: lw          $a0, 0x0($t5)
    ctx->r4 = S32(MEM_W(ctx->r13, 0X0));
    // 0x80096F54: jal         0x80097564
    // 0x80096F58: lw          $a1, 0x0($t3)
    ctx->r5 = S32(MEM_W(ctx->r11, 0X0));
    raytrace(rdram, ctx);
        goto after_37;
    // 0x80096F58: lw          $a1, 0x0($t3)
    ctx->r5 = S32(MEM_W(ctx->r11, 0X0));
    after_37:
    // 0x80096F5C: bltz        $v0, L_800971EC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80096F60: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_800971EC;
    }
    // 0x80096F60: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80096F64: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x80096F68: addiu       $t9, $t9, 0x6F30
    ctx->r25 = ADD32(ctx->r25, 0X6F30);
    // 0x80096F6C: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80096F70: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80096F74: lw          $t6, 0x8($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X8));
    // 0x80096F78: lw          $t7, 0x0($v1)
    ctx->r15 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80096F7C: lw          $t4, 0xC($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, 0XC));
    // 0x80096F80: lw          $t5, 0x4($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X4));
    // 0x80096F84: subu        $s1, $t6, $t7
    ctx->r17 = SUB32(ctx->r14, ctx->r15);
    // 0x80096F88: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096F8C: subu        $s3, $t4, $t5
    ctx->r19 = SUB32(ctx->r12, ctx->r13);
    // 0x80096F90: lw          $t4, 0x18C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X18C));
    // 0x80096F94: lw          $t9, 0x190($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X190));
    // 0x80096F98: lw          $t5, 0x188($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80096F9C: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x80096FA0: sra         $t6, $t9, 31
    ctx->r14 = S32(SIGNED(ctx->r25) >> 31);
    // 0x80096FA4: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x80096FA8: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x80096FAC: mflo        $t3
    ctx->r11 = lo;
    // 0x80096FB0: nop

    // 0x80096FB4: nop

    // 0x80096FB8: multu       $s3, $s3
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096FBC: mflo        $t8
    ctx->r24 = lo;
    // 0x80096FC0: addu        $t0, $t3, $t8
    ctx->r8 = ADD32(ctx->r11, ctx->r24);
    // 0x80096FC4: sra         $t8, $t4, 31
    ctx->r24 = S32(SIGNED(ctx->r12) >> 31);
    // 0x80096FC8: blez        $t0, L_80097088
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80096FCC: sw          $t8, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r24;
            goto L_80097088;
    }
    // 0x80096FCC: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x80096FD0: lw          $t3, 0x180($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80096FD4: lw          $t4, 0x184($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80096FD8: lw          $t8, 0x17C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X17C));
    // 0x80096FDC: subu        $t6, $t5, $t3
    ctx->r14 = SUB32(ctx->r13, ctx->r11);
    // 0x80096FE0: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096FE4: subu        $t9, $t4, $t8
    ctx->r25 = SUB32(ctx->r12, ctx->r24);
    // 0x80096FE8: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80096FEC: sra         $a2, $t0, 31
    ctx->r6 = S32(SIGNED(ctx->r8) >> 31);
    // 0x80096FF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80096FF4: mflo        $t7
    ctx->r15 = lo;
    // 0x80096FF8: nop

    // 0x80096FFC: nop

    // 0x80097000: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097004: mflo        $t5
    ctx->r13 = lo;
    // 0x80097008: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
    // 0x8009700C: blez        $v0, L_8009701C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097010: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8009701C;
    }
    // 0x80097010: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80097014: b           L_80097020
    // 0x80097018: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80097020;
    // 0x80097018: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009701C:
    // 0x8009701C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80097020:
    // 0x80097020: sra         $t3, $v1, 11
    ctx->r11 = S32(SIGNED(ctx->r3) >> 11);
    // 0x80097024: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80097028: beq         $at, $zero, L_80097040
    if (ctx->r1 == 0) {
        // 0x8009702C: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80097040;
    }
    // 0x8009702C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80097030: jal         0x800915D4
    // 0x80097034: sra         $a0, $s2, 31
    ctx->r4 = S32(SIGNED(ctx->r18) >> 31);
    divscale20(rdram, ctx);
        goto after_38;
    // 0x80097034: sra         $a0, $s2, 31
    ctx->r4 = S32(SIGNED(ctx->r18) >> 31);
    after_38:
    // 0x80097038: b           L_80097040
    // 0x8009703C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80097040;
    // 0x8009703C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80097040:
    // 0x80097040: sra         $a2, $s0, 31
    ctx->r6 = S32(SIGNED(ctx->r16) >> 31);
    // 0x80097044: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80097048: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8009704C: sra         $a0, $s1, 31
    ctx->r4 = S32(SIGNED(ctx->r17) >> 31);
    // 0x80097050: sw          $s0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r16;
    // 0x80097054: jal         0x8008FE70
    // 0x80097058: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    mulscale20(rdram, ctx);
        goto after_39;
    // 0x80097058: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_39:
    // 0x8009705C: lw          $t4, 0x180($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80097060: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80097064: sra         $a0, $s3, 31
    ctx->r4 = S32(SIGNED(ctx->r19) >> 31);
    // 0x80097068: addu        $t8, $v0, $t4
    ctx->r24 = ADD32(ctx->r2, ctx->r12);
    // 0x8009706C: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
    // 0x80097070: lw          $a2, 0xA0($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80097074: jal         0x8008FE70
    // 0x80097078: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    mulscale20(rdram, ctx);
        goto after_40;
    // 0x80097078: lw          $a3, 0xA4($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0XA4));
    after_40:
    // 0x8009707C: lw          $t9, 0x17C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X17C));
    // 0x80097080: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x80097084: sw          $t5, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r13;
L_80097088:
    // 0x80097088: lw          $t4, 0x90($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X90));
    // 0x8009708C: lw          $t5, 0x94($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X94));
    // 0x80097090: sra         $t6, $s3, 31
    ctx->r14 = S32(SIGNED(ctx->r19) >> 31);
    // 0x80097094: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80097098: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8009709C: sra         $a0, $s1, 31
    ctx->r4 = S32(SIGNED(ctx->r17) >> 31);
    // 0x800970A0: lw          $a2, 0x98($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800970A4: lw          $a3, 0x9C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800970A8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800970AC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800970B0: jal         0x80090414
    // 0x800970B4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    dmulscale6(rdram, ctx);
        goto after_41;
    // 0x800970B4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_41:
    // 0x800970B8: lw          $t3, 0x0($s4)
    ctx->r11 = S32(MEM_W(ctx->r20, 0X0));
    // 0x800970BC: addiu       $v1, $s5, 0x1
    ctx->r3 = ADD32(ctx->r21, 0X1);
    // 0x800970C0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800970C4: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800970C8: bne         $at, $zero, L_8009717C
    if (ctx->r1 != 0) {
        // 0x800970CC: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_8009717C;
    }
    // 0x800970CC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800970D0: lui         $t9, 0x8027
    ctx->r25 = S32(0X8027 << 16);
    // 0x800970D4: addiu       $t9, $t9, 0x6F28
    ctx->r25 = ADD32(ctx->r25, 0X6F28);
    // 0x800970D8: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800970DC: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x800970E0: lh          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X0));
L_800970E4:
    // 0x800970E4: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x800970E8: addiu       $t7, $t7, 0x6F30
    ctx->r15 = ADD32(ctx->r15, 0X6F30);
    // 0x800970EC: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800970F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800970F4: lw          $t8, 0xC($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0XC));
    // 0x800970F8: lw          $t9, 0x4($v0)
    ctx->r25 = S32(MEM_W(ctx->r2, 0X4));
    // 0x800970FC: lw          $t4, 0x8($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X8));
    // 0x80097100: lw          $t5, 0x0($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80097104: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x80097108: lw          $t9, 0x94($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X94));
    // 0x8009710C: lw          $t8, 0x90($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X90));
    // 0x80097110: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x80097114: sra         $t4, $t6, 31
    ctx->r12 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80097118: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009711C: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80097120: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80097124: lw          $a2, 0x98($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80097128: lw          $a3, 0x9C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x8009712C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80097130: jal         0x80090414
    // 0x80097134: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    dmulscale6(rdram, ctx);
        goto after_42;
    // 0x80097134: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_42:
    // 0x80097138: xor         $t7, $s2, $v0
    ctx->r15 = ctx->r18 ^ ctx->r2;
    // 0x8009713C: bgezl       $t7, L_80097168
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80097140: lw          $t4, 0x0($s4)
        ctx->r12 = S32(MEM_W(ctx->r20, 0X0));
            goto L_80097168;
    }
    goto skip_14;
    // 0x80097140: lw          $t4, 0x0($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X0));
    skip_14:
    // 0x80097144: lw          $t3, 0x1B8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80097148: lw          $t6, 0x1BC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x8009714C: lw          $a2, 0x1C4($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X1C4));
    // 0x80097150: lw          $a0, 0x0($t3)
    ctx->r4 = S32(MEM_W(ctx->r11, 0X0));
    // 0x80097154: jal         0x80097DB8
    // 0x80097158: lw          $a1, 0x0($t6)
    ctx->r5 = S32(MEM_W(ctx->r14, 0X0));
    updatesector(rdram, ctx);
        goto after_43;
    // 0x80097158: lw          $a1, 0x0($t6)
    ctx->r5 = S32(MEM_W(ctx->r14, 0X0));
    after_43:
    // 0x8009715C: b           L_80097408
    // 0x80097160: lw          $v0, 0x170($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
        goto L_80097408;
    // 0x80097160: lw          $v0, 0x170($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
    // 0x80097164: lw          $t4, 0x0($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X0));
L_80097168:
    // 0x80097168: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009716C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80097170: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80097174: beql        $at, $zero, L_800970E4
    if (ctx->r1 == 0) {
        // 0x80097178: lh          $v1, 0x0($s1)
        ctx->r3 = S32(MEM_H(ctx->r17, 0X0));
            goto L_800970E4;
    }
    goto skip_15;
    // 0x80097178: lh          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_H(ctx->r17, 0X0));
    skip_15:
L_8009717C:
    // 0x8009717C: lui         $t8, 0x8027
    ctx->r24 = S32(0X8027 << 16);
    // 0x80097180: addiu       $t8, $t8, 0x6F28
    ctx->r24 = ADD32(ctx->r24, 0X6F28);
    // 0x80097184: sll         $t5, $s5, 1
    ctx->r13 = S32(ctx->r21 << 1);
    // 0x80097188: addu        $s0, $t5, $t8
    ctx->r16 = ADD32(ctx->r13, ctx->r24);
    // 0x8009718C: addiu       $a0, $sp, 0x188
    ctx->r4 = ADD32(ctx->r29, 0X188);
    // 0x80097190: addiu       $a1, $sp, 0x184
    ctx->r5 = ADD32(ctx->r29, 0X184);
    // 0x80097194: jal         0x80097438
    // 0x80097198: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    keepaway(rdram, ctx);
        goto after_44;
    // 0x80097198: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_44:
    // 0x8009719C: lw          $t9, 0x188($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X188));
    // 0x800971A0: lw          $t7, 0x180($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X180));
    // 0x800971A4: lw          $t6, 0x184($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X184));
    // 0x800971A8: lw          $t4, 0x17C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X17C));
    // 0x800971AC: lw          $t8, 0x0($s4)
    ctx->r24 = S32(MEM_W(ctx->r20, 0X0));
    // 0x800971B0: subu        $s1, $t9, $t7
    ctx->r17 = SUB32(ctx->r25, ctx->r15);
    // 0x800971B4: subu        $s2, $t6, $t4
    ctx->r18 = SUB32(ctx->r14, ctx->r12);
    // 0x800971B8: sll         $t3, $s1, 14
    ctx->r11 = S32(ctx->r17 << 14);
    // 0x800971BC: sll         $t5, $s2, 14
    ctx->r13 = S32(ctx->r18 << 14);
    // 0x800971C0: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x800971C4: bne         $s5, $t8, L_800971E0
    if (ctx->r21 != ctx->r24) {
        // 0x800971C8: or          $s2, $t5, $zero
        ctx->r18 = ctx->r13 | 0;
            goto L_800971E0;
    }
    // 0x800971C8: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x800971CC: sll         $t9, $s6, 1
    ctx->r25 = S32(ctx->r22 << 1);
    // 0x800971D0: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800971D4: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800971D8: lh          $t7, -0x6CC8($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X6CC8));
    // 0x800971DC: sw          $t7, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r15;
L_800971E0:
    // 0x800971E0: or          $t3, $s1, $s2
    ctx->r11 = ctx->r17 | ctx->r18;
    // 0x800971E4: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    // 0x800971E8: sh          $s6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r22;
L_800971EC:
    // 0x800971EC: lw          $v0, 0x1B8($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x800971F0: lw          $t6, 0x180($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X180));
    // 0x800971F4: lw          $v1, 0x1BC($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x800971F8: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800971FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80097200: lw          $t4, 0x17C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X17C));
    // 0x80097204: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80097208: lw          $t5, 0xC4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0XC4));
    // 0x8009720C: beq         $t5, $zero, L_80097224
    if (ctx->r13 == 0) {
        // 0x80097210: nop
    
            goto L_80097224;
    }
    // 0x80097210: nop

    // 0x80097214: bltz        $s6, L_80097224
    if (SIGNED(ctx->r22) < 0) {
        // 0x80097218: nop
    
            goto L_80097224;
    }
    // 0x80097218: nop

    // 0x8009721C: bgtzl       $s5, L_80096F34
    if (SIGNED(ctx->r21) > 0) {
        // 0x80097220: lw          $t7, 0x188($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X188));
            goto L_80096F34;
    }
    goto skip_16;
    // 0x80097220: lw          $t7, 0x188($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X188));
    skip_16:
L_80097224:
    // 0x80097224: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x80097228: lh          $t8, -0x6CD0($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X6CD0));
    // 0x8009722C: lui         $s0, 0x8028
    ctx->r16 = S32(0X8028 << 16);
    // 0x80097230: addiu       $s0, $s0, -0x70D0
    ctx->r16 = ADD32(ctx->r16, -0X70D0);
    // 0x80097234: blezl       $t8, L_80097298
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80097238: lw          $t8, 0x1C4($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X1C4));
            goto L_80097298;
    }
    goto skip_17;
    // 0x80097238: lw          $t8, 0x1C4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1C4));
    skip_17:
    // 0x8009723C: sw          $zero, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = 0;
L_80097240:
    // 0x80097240: lw          $v0, 0x1B8($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80097244: lw          $v1, 0x1BC($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80097248: lh          $a2, 0x0($s0)
    ctx->r6 = S32(MEM_H(ctx->r16, 0X0));
    // 0x8009724C: lw          $a0, 0x0($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80097250: jal         0x80091E14
    // 0x80097254: lw          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X0));
    inside(rdram, ctx);
        goto after_45;
    // 0x80097254: lw          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X0));
    after_45:
    // 0x80097258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009725C: bne         $v0, $at, L_80097278
    if (ctx->r2 != ctx->r1) {
        // 0x80097260: lw          $t3, 0x19C($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80097278;
    }
    // 0x80097260: lw          $t3, 0x19C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80097264: lh          $t9, 0x0($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X0));
    // 0x80097268: lw          $t7, 0x1C4($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1C4));
    // 0x8009726C: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x80097270: b           L_80097408
    // 0x80097274: lw          $v0, 0x170($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
        goto L_80097408;
    // 0x80097274: lw          $v0, 0x170($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
L_80097278:
    // 0x80097278: lui         $t4, 0x8028
    ctx->r12 = S32(0X8028 << 16);
    // 0x8009727C: lh          $t4, -0x6CD0($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X6CD0));
    // 0x80097280: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80097284: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x80097288: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8009728C: bne         $at, $zero, L_80097240
    if (ctx->r1 != 0) {
        // 0x80097290: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80097240;
    }
    // 0x80097290: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80097294: lw          $t8, 0x1C4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1C4));
L_80097298:
    // 0x80097298: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8009729C: lui         $a3, 0x802B
    ctx->r7 = S32(0X802B << 16);
    // 0x800972A0: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x800972A4: lh          $a3, -0x5378($a3)
    ctx->r7 = S32(MEM_H(ctx->r7, -0X5378));
    // 0x800972A8: lui         $s2, 0x7FFF
    ctx->r18 = S32(0X7FFF << 16);
    // 0x800972AC: ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
    // 0x800972B0: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800972B4: bltzl       $a3, L_80097408
    if (SIGNED(ctx->r7) < 0) {
        // 0x800972B8: lw          $v0, 0x170($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
            goto L_80097408;
    }
    goto skip_18;
    // 0x800972B8: lw          $v0, 0x170($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
    skip_18:
    // 0x800972BC: sw          $a3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r7;
L_800972C0:
    // 0x800972C0: lw          $a3, 0x19C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x800972C4: lw          $v0, 0x1B8($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x800972C8: lw          $v1, 0x1BC($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x800972CC: sll         $s1, $a3, 16
    ctx->r17 = S32(ctx->r7 << 16);
    // 0x800972D0: sra         $t9, $s1, 16
    ctx->r25 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800972D4: sll         $a2, $t9, 16
    ctx->r6 = S32(ctx->r25 << 16);
    // 0x800972D8: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800972DC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800972E0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800972E4: lw          $a0, 0x0($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X0));
    // 0x800972E8: jal         0x80091E14
    // 0x800972EC: lw          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X0));
    inside(rdram, ctx);
        goto after_46;
    // 0x800972EC: lw          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X0));
    after_46:
    // 0x800972F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800972F4: bne         $v0, $at, L_800973F4
    if (ctx->r2 != ctx->r1) {
        // 0x800972F8: lw          $t3, 0x19C($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_800973F4;
    }
    // 0x800972F8: lw          $t3, 0x19C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x800972FC: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80097300: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80097304: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x80097308: addiu       $t4, $t4, -0x1988
    ctx->r12 = ADD32(ctx->r12, -0X1988);
    // 0x8009730C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80097310: addu        $s0, $t6, $t4
    ctx->r16 = ADD32(ctx->r14, ctx->r12);
    // 0x80097314: lh          $t5, 0xC($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0XC));
    // 0x80097318: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8009731C: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80097320: andi        $t8, $t5, 0x2
    ctx->r24 = ctx->r13 & 0X2;
    // 0x80097324: beq         $t8, $zero, L_80097354
    if (ctx->r24 == 0) {
        // 0x80097328: lw          $t4, 0x1C0($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X1C0));
            goto L_80097354;
    }
    // 0x80097328: lw          $t4, 0x1C0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1C0));
    // 0x8009732C: lw          $t7, 0x1B8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80097330: lw          $t3, 0x1BC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x80097334: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80097338: lw          $a1, 0x0($t7)
    ctx->r5 = S32(MEM_W(ctx->r15, 0X0));
    // 0x8009733C: jal         0x80098E64
    // 0x80097340: lw          $a2, 0x0($t3)
    ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
    getceilzofslope(rdram, ctx);
        goto after_47;
    // 0x80097340: lw          $a2, 0x0($t3)
    ctx->r6 = S32(MEM_W(ctx->r11, 0X0));
    after_47:
    // 0x80097344: lw          $t6, 0x1C0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1C0));
    // 0x80097348: lw          $v1, 0x0($t6)
    ctx->r3 = S32(MEM_W(ctx->r14, 0X0));
    // 0x8009734C: b           L_80097360
    // 0x80097350: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
        goto L_80097360;
    // 0x80097350: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
L_80097354:
    // 0x80097354: lw          $v1, 0x0($t4)
    ctx->r3 = S32(MEM_W(ctx->r12, 0X0));
    // 0x80097358: lw          $t5, 0x0($s0)
    ctx->r13 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8009735C: subu        $a0, $t5, $v1
    ctx->r4 = SUB32(ctx->r13, ctx->r3);
L_80097360:
    // 0x80097360: blez        $a0, L_80097380
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80097364: slt         $at, $a0, $s2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80097380;
    }
    // 0x80097364: slt         $at, $a0, $s2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80097368: beq         $at, $zero, L_800973F4
    if (ctx->r1 == 0) {
        // 0x8009736C: lw          $t8, 0x19C($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_800973F4;
    }
    // 0x8009736C: lw          $t8, 0x19C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80097370: lw          $t9, 0x1C4($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1C4));
    // 0x80097374: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80097378: b           L_800973F4
    // 0x8009737C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
        goto L_800973F4;
    // 0x8009737C: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
L_80097380:
    // 0x80097380: lh          $t7, 0xE($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0XE));
    // 0x80097384: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80097388: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8009738C: andi        $t3, $t7, 0x2
    ctx->r11 = ctx->r15 & 0X2;
    // 0x80097390: beq         $t3, $zero, L_800973BC
    if (ctx->r11 == 0) {
        // 0x80097394: lw          $t4, 0x1B8($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X1B8));
            goto L_800973BC;
    }
    // 0x80097394: lw          $t4, 0x1B8($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1B8));
    // 0x80097398: lw          $t5, 0x1BC($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1BC));
    // 0x8009739C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800973A0: lw          $a1, 0x0($t4)
    ctx->r5 = S32(MEM_W(ctx->r12, 0X0));
    // 0x800973A4: jal         0x80098FB4
    // 0x800973A8: lw          $a2, 0x0($t5)
    ctx->r6 = S32(MEM_W(ctx->r13, 0X0));
    getflorzofslope(rdram, ctx);
        goto after_48;
    // 0x800973A8: lw          $a2, 0x0($t5)
    ctx->r6 = S32(MEM_W(ctx->r13, 0X0));
    after_48:
    // 0x800973AC: lw          $t8, 0x1C0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1C0));
    // 0x800973B0: lw          $t9, 0x0($t8)
    ctx->r25 = S32(MEM_W(ctx->r24, 0X0));
    // 0x800973B4: b           L_800973C4
    // 0x800973B8: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
        goto L_800973C4;
    // 0x800973B8: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
L_800973BC:
    // 0x800973BC: lw          $t7, 0x4($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X4));
    // 0x800973C0: subu        $a0, $v1, $t7
    ctx->r4 = SUB32(ctx->r3, ctx->r15);
L_800973C4:
    // 0x800973C4: bgtz        $a0, L_800973E0
    if (SIGNED(ctx->r4) > 0) {
        // 0x800973C8: slt         $at, $a0, $s2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800973E0;
    }
    // 0x800973C8: slt         $at, $a0, $s2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800973CC: lw          $t3, 0x19C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x800973D0: lw          $t6, 0x1C4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1C4));
    // 0x800973D4: sh          $t3, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r11;
    // 0x800973D8: b           L_80097408
    // 0x800973DC: lw          $v0, 0x170($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
        goto L_80097408;
    // 0x800973DC: lw          $v0, 0x170($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
L_800973E0:
    // 0x800973E0: beq         $at, $zero, L_800973F4
    if (ctx->r1 == 0) {
        // 0x800973E4: lw          $t4, 0x19C($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_800973F4;
    }
    // 0x800973E4: lw          $t4, 0x19C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x800973E8: lw          $t5, 0x1C4($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1C4));
    // 0x800973EC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800973F0: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
L_800973F4:
    // 0x800973F4: lw          $t8, 0x19C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x800973F8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800973FC: bgez        $t9, L_800972C0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80097400: sw          $t9, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r25;
            goto L_800972C0;
    }
    // 0x80097400: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x80097404: lw          $v0, 0x170($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X170));
L_80097408:
    // 0x80097408: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x8009740C: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80097410: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80097414: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80097418: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x8009741C: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80097420: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80097424: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80097428: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x8009742C: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80097430: jr          $ra
    // 0x80097434: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
    return;
    // 0x80097434: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3DC0: jr          $ra
    // 0x800C3DC4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x800C3DC4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void changespritestat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800929F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800929F4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800929F8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800929FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80092A00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80092A04: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80092A08: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80092A0C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80092A10: bltz        $t9, L_80092A24
    if (SIGNED(ctx->r25) < 0) {
        // 0x80092A14: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80092A24;
    }
    // 0x80092A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092A18: slti        $at, $t9, 0x401
    ctx->r1 = SIGNED(ctx->r25) < 0X401 ? 1 : 0;
    // 0x80092A1C: bne         $at, $zero, L_80092A2C
    if (ctx->r1 != 0) {
        // 0x80092A20: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80092A2C;
    }
    // 0x80092A20: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
L_80092A24:
    // 0x80092A24: b           L_80092A98
    // 0x80092A28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80092A98;
    // 0x80092A28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80092A2C:
    // 0x80092A2C: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80092A30: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80092A34: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80092A38: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80092A3C: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80092A40: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80092A44: lh          $v0, 0x6BBA($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X6BBA));
    // 0x80092A48: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80092A4C: bne         $a1, $v0, L_80092A5C
    if (ctx->r5 != ctx->r2) {
        // 0x80092A50: nop
    
            goto L_80092A5C;
    }
    // 0x80092A50: nop

    // 0x80092A54: b           L_80092A98
    // 0x80092A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80092A98;
    // 0x80092A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80092A5C:
    // 0x80092A5C: bne         $v0, $at, L_80092A6C
    if (ctx->r2 != ctx->r1) {
        // 0x80092A60: nop
    
            goto L_80092A6C;
    }
    // 0x80092A60: nop

    // 0x80092A64: b           L_80092A98
    // 0x80092A68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80092A98;
    // 0x80092A68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80092A6C:
    // 0x80092A6C: jal         0x80092850
    // 0x80092A70: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    deletespritestat(rdram, ctx);
        goto after_0;
    // 0x80092A70: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_0:
    // 0x80092A74: bgez        $v0, L_80092A84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80092A78: lh          $a1, 0x1E($sp)
        ctx->r5 = S32(MEM_H(ctx->r29, 0X1E));
            goto L_80092A84;
    }
    // 0x80092A78: lh          $a1, 0x1E($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X1E));
    // 0x80092A7C: b           L_80092A98
    // 0x80092A80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80092A98;
    // 0x80092A80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80092A84:
    // 0x80092A84: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80092A88: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80092A8C: jal         0x80092658
    // 0x80092A90: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    insertspritestat(rdram, ctx);
        goto after_1;
    // 0x80092A90: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_1:
    // 0x80092A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80092A98:
    // 0x80092A98: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80092A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092AA0: jr          $ra
    // 0x80092AA4: nop

    return;
    // 0x80092AA4: nop

;}
RECOMP_FUNC void boot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004B454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004B458: jal         0x800BAAE0
    // 0x8004B45C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_0;
    // 0x8004B45C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8004B460: jal         0x800BAB50
    // 0x8004B464: nop

    osInitialize_recomp(rdram, ctx);
        goto after_1;
    // 0x8004B464: nop

    after_1:
    // 0x8004B468: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8004B46C: addiu       $t6, $t6, 0x2E38
    ctx->r14 = ADD32(ctx->r14, 0X2E38);
    // 0x8004B470: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004B474: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8004B478: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8004B47C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004B480: addiu       $a2, $a2, -0x4B4C
    ctx->r6 = ADD32(ctx->r6, -0X4B4C);
    // 0x8004B484: addiu       $a0, $a0, -0x1378
    ctx->r4 = ADD32(ctx->r4, -0X1378);
    // 0x8004B488: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004B48C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8004B490: jal         0x800BADE0
    // 0x8004B494: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8004B494: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8004B498: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8004B49C: jal         0x800BAF30
    // 0x8004B4A0: addiu       $a0, $a0, -0x1378
    ctx->r4 = ADD32(ctx->r4, -0X1378);
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8004B4A0: addiu       $a0, $a0, -0x1378
    ctx->r4 = ADD32(ctx->r4, -0X1378);
    after_3:
    // 0x8004B4A4: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004B4A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004B4AC: jr          $ra
    // 0x8004B4B0: nop

    return;
    // 0x8004B4B0: nop

;}
RECOMP_FUNC void divscale4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009111C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091120: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091124: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80091128: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8009112C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091130: jal         0x800BB834
    // 0x80091134: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091134: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009113C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091140: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091144: jal         0x800BB89C
    // 0x80091148: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091148: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x8009114C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091154: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091158: jr          $ra
    // 0x8009115C: nop

    return;
    // 0x8009115C: nop

;}
RECOMP_FUNC void func_800700F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800700F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800700F4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800700F8: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    // 0x800700FC: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x80070100: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80070104: beq         $t6, $zero, L_80070198
    if (ctx->r14 == 0) {
        // 0x80070108: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80070198;
    }
    // 0x80070108: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8007010C: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x80070110: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x80070114: lui         $a3, 0x8027
    ctx->r7 = S32(0X8027 << 16);
    // 0x80070118: addiu       $a3, $a3, -0x133F
    ctx->r7 = ADD32(ctx->r7, -0X133F);
    // 0x8007011C: addiu       $t0, $t0, -0x1340
    ctx->r8 = ADD32(ctx->r8, -0X1340);
    // 0x80070120: addiu       $t1, $t1, -0x133C
    ctx->r9 = ADD32(ctx->r9, -0X133C);
    // 0x80070124: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
L_80070128:
    // 0x80070128: lbu         $a1, 0x0($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X0);
    // 0x8007012C: bnel        $a1, $zero, L_80070154
    if (ctx->r5 != 0) {
        // 0x80070130: lbu         $a2, 0x0($t0)
        ctx->r6 = MEM_BU(ctx->r8, 0X0);
            goto L_80070154;
    }
    goto skip_0;
    // 0x80070130: lbu         $a2, 0x0($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X0);
    skip_0:
    // 0x80070134: lw          $v0, 0x0($t1)
    ctx->r2 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80070138: andi        $a1, $t2, 0xFF
    ctx->r5 = ctx->r10 & 0XFF;
    // 0x8007013C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80070140: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80070144: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80070148: sb          $t2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r10;
    // 0x8007014C: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x80070150: lbu         $a2, 0x0($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X0);
L_80070154:
    // 0x80070154: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x80070158: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8007015C: andi        $t5, $a2, 0x80
    ctx->r13 = ctx->r6 & 0X80;
    // 0x80070160: beq         $t5, $zero, L_80070174
    if (ctx->r13 == 0) {
        // 0x80070164: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_80070174;
    }
    // 0x80070164: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80070168: addiu       $v1, $t4, 0x1
    ctx->r3 = ADD32(ctx->r12, 0X1);
    // 0x8007016C: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x80070170: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80070174:
    // 0x80070174: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80070178: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8007017C: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x80070180: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x80070184: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x80070188: sb          $t7, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r15;
    // 0x8007018C: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x80070190: bne         $v0, $zero, L_80070128
    if (ctx->r2 != 0) {
        // 0x80070194: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_80070128;
    }
    // 0x80070194: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_80070198:
    // 0x80070198: jr          $ra
    // 0x8007019C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8007019C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void divscale1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091038: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009103C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091040: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80091044: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009104C: jal         0x800BB834
    // 0x80091050: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091050: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80091054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091058: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8009105C: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091060: jal         0x800BB89C
    // 0x80091064: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80091064: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091068: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8009106C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091070: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80091074: jr          $ra
    // 0x80091078: nop

    return;
    // 0x80091078: nop

;}
RECOMP_FUNC void soundSetupMsgQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800582F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800582F4: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800582F8: lui         $v1, 0x8022
    ctx->r3 = S32(0X8022 << 16);
    // 0x800582FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058300: addiu       $v1, $v1, -0x5C08
    ctx->r3 = ADD32(ctx->r3, -0X5C08);
    // 0x80058304: addiu       $v0, $v0, -0x5F08
    ctx->r2 = ADD32(ctx->r2, -0X5F08);
L_80058308:
    // 0x80058308: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // 0x8005830C: sb          $zero, -0x48($v0)
    MEM_B(-0X48, ctx->r2) = 0;
    // 0x80058310: sb          $zero, -0x30($v0)
    MEM_B(-0X30, ctx->r2) = 0;
    // 0x80058314: sb          $zero, -0x18($v0)
    MEM_B(-0X18, ctx->r2) = 0;
    // 0x80058318: bne         $v0, $v1, L_80058308
    if (ctx->r2 != ctx->r3) {
        // 0x8005831C: sb          $zero, -0x60($v0)
        MEM_B(-0X60, ctx->r2) = 0;
            goto L_80058308;
    }
    // 0x8005831C: sb          $zero, -0x60($v0)
    MEM_B(-0X60, ctx->r2) = 0;
    // 0x80058320: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80058324: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80058328: addiu       $a1, $a1, -0x5F88
    ctx->r5 = ADD32(ctx->r5, -0X5F88);
    // 0x8005832C: addiu       $a0, $a0, -0x5FA0
    ctx->r4 = ADD32(ctx->r4, -0X5FA0);
    // 0x80058330: jal         0x800BB760
    // 0x80058334: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80058334: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_0:
    // 0x80058338: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8005833C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058340: jr          $ra
    // 0x80058344: nop

    return;
    // 0x80058344: nop

;}
RECOMP_FUNC void func_80058684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058684: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80058688: lh          $t7, 0x12A0($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X12A0));
    // 0x8005868C: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x80058690: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80058694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005869C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800586A0: bne         $t7, $zero, L_800586B0
    if (ctx->r15 != 0) {
        // 0x800586A4: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_800586B0;
    }
    // 0x800586A4: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800586A8: b           L_8005877C
    // 0x800586AC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_8005877C;
    // 0x800586AC: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_800586B0:
    // 0x800586B0: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x800586B4: lbu         $t8, -0x5C08($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X5C08);
    // 0x800586B8: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x800586BC: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x800586C0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800586C4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800586C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800586CC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800586D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800586D4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800586D8: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x800586DC: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x800586E0: lui         $t2, 0x8024
    ctx->r10 = S32(0X8024 << 16);
    // 0x800586E4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800586E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800586EC: addiu       $t2, $t2, 0x6BA8
    ctx->r10 = ADD32(ctx->r10, 0X6BA8);
    // 0x800586F0: addiu       $t0, $t0, 0x5770
    ctx->r8 = ADD32(ctx->r8, 0X5770);
    // 0x800586F4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800586F8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800586FC: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x80058700: lw          $t3, 0x238($a2)
    ctx->r11 = S32(MEM_W(ctx->r6, 0X238));
    // 0x80058704: lw          $t5, 0x23C($a2)
    ctx->r13 = S32(MEM_W(ctx->r6, 0X23C));
    // 0x80058708: lw          $t4, 0x0($v0)
    ctx->r12 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8005870C: lw          $t6, 0x4($v0)
    ctx->r14 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80058710: subu        $a0, $t3, $t4
    ctx->r4 = SUB32(ctx->r11, ctx->r12);
    // 0x80058714: jal         0x80092024
    // 0x80058718: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    getangle(rdram, ctx);
        goto after_0;
    // 0x80058718: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    after_0:
    // 0x8005871C: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80058720: lbu         $t7, -0x5C08($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X5C08);
    // 0x80058724: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x80058728: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x8005872C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80058730: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80058734: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80058738: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005873C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80058740: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80058744: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80058748: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x8005874C: lh          $t0, 0x282($a2)
    ctx->r8 = S32(MEM_H(ctx->r6, 0X282));
    // 0x80058750: lh          $t1, 0x28A($a2)
    ctx->r9 = S32(MEM_H(ctx->r6, 0X28A));
    // 0x80058754: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x80058758: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8005875C: subu        $v1, $t2, $v0
    ctx->r3 = SUB32(ctx->r10, ctx->r2);
    // 0x80058760: addiu       $v1, $v1, 0xA00
    ctx->r3 = ADD32(ctx->r3, 0XA00);
    // 0x80058764: andi        $t3, $v1, 0x7FF
    ctx->r11 = ctx->r3 & 0X7FF;
    // 0x80058768: slti        $at, $t3, 0x400
    ctx->r1 = SIGNED(ctx->r11) < 0X400 ? 1 : 0;
    // 0x8005876C: bne         $at, $zero, L_80058778
    if (ctx->r1 != 0) {
        // 0x80058770: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80058778;
    }
    // 0x80058770: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80058774: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
L_80058778:
    // 0x80058778: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
L_8005877C:
    // 0x8005877C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80058780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058784: jr          $ra
    // 0x80058788: nop

    return;
    // 0x80058788: nop

;}
RECOMP_FUNC void divscale7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800911F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800911FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091200: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091204: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091208: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x8009120C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80091210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80091214: jal         0x800BB834
    // 0x80091218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80091218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009121C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80091220: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80091224: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80091228: jal         0x800BB89C
    // 0x8009122C: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x8009122C: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x80091230: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80091234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091238: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009123C: jr          $ra
    // 0x80091240: nop

    return;
    // 0x80091240: nop

;}
