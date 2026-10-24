#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void cheatkeys(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B31F8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800B31FC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800B3200: lh          $t6, 0x5A($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x800B3204: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x800B3208: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800B320C: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800B3210: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800B3214: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B3218: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800B321C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B3220: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x800B3224: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B3228: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x800B322C: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x800B3230: lh          $t1, 0x2E0($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B3234: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x800B3238: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B323C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B3240: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800B3244: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B3248: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800B324C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B3250: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800B3254: lh          $t3, 0x6BCA($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, 0X6BCA));
    // 0x800B3258: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B325C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B3260: lui         $t0, 0x802A
    ctx->r8 = S32(0X802A << 16);
    // 0x800B3264: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800B3268: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B326C: blez        $t3, L_800B3CBC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B3270: lw          $t0, 0x5608($t0)
        ctx->r8 = S32(MEM_W(ctx->r8, 0X5608));
            goto L_800B3CBC;
    }
    // 0x800B3270: lw          $t0, 0x5608($t0)
    ctx->r8 = S32(MEM_W(ctx->r8, 0X5608));
    // 0x800B3274: lbu         $t4, 0x280($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X280);
    // 0x800B3278: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x800B327C: sll         $t7, $t0, 9
    ctx->r15 = S32(ctx->r8 << 9);
    // 0x800B3280: beq         $t4, $zero, L_800B328C
    if (ctx->r12 == 0) {
        // 0x800B3284: andi        $t2, $t0, 0xF00
        ctx->r10 = ctx->r8 & 0XF00;
            goto L_800B328C;
    }
    // 0x800B3284: andi        $t2, $t0, 0xF00
    ctx->r10 = ctx->r8 & 0XF00;
    // 0x800B3288: sb          $t5, 0x36C($s0)
    MEM_B(0X36C, ctx->r16) = ctx->r13;
L_800B328C:
    // 0x800B328C: bgez        $t7, L_800B32C0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B3290: nop
    
            goto L_800B32C0;
    }
    // 0x800B3290: nop

    // 0x800B3294: lh          $t6, 0x2EA($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2EA));
    // 0x800B3298: bne         $t6, $zero, L_800B32C0
    if (ctx->r14 != 0) {
        // 0x800B329C: nop
    
            goto L_800B32C0;
    }
    // 0x800B329C: nop

    // 0x800B32A0: lh          $t8, 0x2B2($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X2B2));
    // 0x800B32A4: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x800B32A8: bnel        $t8, $zero, L_800B32C0
    if (ctx->r24 != 0) {
        // 0x800B32AC: sh          $t1, 0x2EA($s0)
        MEM_H(0X2EA, ctx->r16) = ctx->r9;
            goto L_800B32C0;
    }
    goto skip_0;
    // 0x800B32AC: sh          $t1, 0x2EA($s0)
    MEM_H(0X2EA, ctx->r16) = ctx->r9;
    skip_0:
    // 0x800B32B0: lh          $t9, 0x2D4($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2D4));
    // 0x800B32B4: bne         $t9, $zero, L_800B32C0
    if (ctx->r25 != 0) {
        // 0x800B32B8: nop
    
            goto L_800B32C0;
    }
    // 0x800B32B8: nop

    // 0x800B32BC: sh          $t1, 0x2EA($s0)
    MEM_H(0X2EA, ctx->r16) = ctx->r9;
L_800B32C0:
    // 0x800B32C0: bnel        $t2, $zero, L_800B334C
    if (ctx->r10 != 0) {
        // 0x800B32C4: lh          $v0, 0x378($s0)
        ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
            goto L_800B334C;
    }
    goto skip_1;
    // 0x800B32C4: lh          $v0, 0x378($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
    skip_1:
    // 0x800B32C8: lh          $t3, 0x376($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X376));
    // 0x800B32CC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800B32D0: sh          $t4, 0x376($s0)
    MEM_H(0X376, ctx->r16) = ctx->r12;
    // 0x800B32D4: lh          $t5, 0x376($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X376));
    // 0x800B32D8: bgtzl       $t5, L_800B3374
    if (SIGNED(ctx->r13) > 0) {
        // 0x800B32DC: lh          $t5, 0x2BA($s0)
        ctx->r13 = S32(MEM_H(ctx->r16, 0X2BA));
            goto L_800B3374;
    }
    goto skip_2;
    // 0x800B32DC: lh          $t5, 0x2BA($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X2BA));
    skip_2:
    // 0x800B32E0: lh          $v0, 0x372($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X372));
    // 0x800B32E4: lh          $t7, 0x2B2($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2B2));
    // 0x800B32E8: beql        $v0, $t7, L_800B3328
    if (ctx->r2 == ctx->r15) {
        // 0x800B32EC: lh          $v0, 0x378($s0)
        ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
            goto L_800B3328;
    }
    goto skip_3;
    // 0x800B32EC: lh          $v0, 0x378($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
    skip_3:
    // 0x800B32F0: beq         $v0, $zero, L_800B3320
    if (ctx->r2 == 0) {
        // 0x800B32F4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800B3320;
    }
    // 0x800B32F4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800B32F8: beq         $v0, $at, L_800B3320
    if (ctx->r2 == ctx->r1) {
        // 0x800B32FC: addu        $t6, $s0, $v0
        ctx->r14 = ADD32(ctx->r16, ctx->r2);
            goto L_800B3320;
    }
    // 0x800B32FC: addu        $t6, $s0, $v0
    ctx->r14 = ADD32(ctx->r16, ctx->r2);
    // 0x800B3300: lbu         $t8, 0x349($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X349);
    // 0x800B3304: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800B3308: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x800B330C: beql        $t8, $zero, L_800B3328
    if (ctx->r24 == 0) {
        // 0x800B3310: lh          $v0, 0x378($s0)
        ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
            goto L_800B3328;
    }
    goto skip_4;
    // 0x800B3310: lh          $v0, 0x378($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
    skip_4:
    // 0x800B3314: lh          $t2, 0x28E($t1)
    ctx->r10 = S32(MEM_H(ctx->r9, 0X28E));
    // 0x800B3318: beql        $t2, $zero, L_800B3328
    if (ctx->r10 == 0) {
        // 0x800B331C: lh          $v0, 0x378($s0)
        ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
            goto L_800B3328;
    }
    goto skip_5;
    // 0x800B331C: lh          $v0, 0x378($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
    skip_5:
L_800B3320:
    // 0x800B3320: sh          $v0, 0x2BA($s0)
    MEM_H(0X2BA, ctx->r16) = ctx->r2;
    // 0x800B3324: lh          $v0, 0x378($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
L_800B3328:
    // 0x800B3328: sh          $zero, 0x376($s0)
    MEM_H(0X376, ctx->r16) = 0;
    // 0x800B332C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800B3330: bgez        $v0, L_800B3340
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B3334: nop
    
            goto L_800B3340;
    }
    // 0x800B3334: nop

    // 0x800B3338: b           L_800B3370
    // 0x800B333C: sh          $zero, 0x378($s0)
    MEM_H(0X378, ctx->r16) = 0;
        goto L_800B3370;
    // 0x800B333C: sh          $zero, 0x378($s0)
    MEM_H(0X378, ctx->r16) = 0;
L_800B3340:
    // 0x800B3340: b           L_800B3370
    // 0x800B3344: sh          $v0, 0x378($s0)
    MEM_H(0X378, ctx->r16) = ctx->r2;
        goto L_800B3370;
    // 0x800B3344: sh          $v0, 0x378($s0)
    MEM_H(0X378, ctx->r16) = ctx->r2;
    // 0x800B3348: lh          $v0, 0x378($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X378));
L_800B334C:
    // 0x800B334C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800B3350: sh          $t3, 0x376($s0)
    MEM_H(0X376, ctx->r16) = ctx->r11;
    // 0x800B3354: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800B3358: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x800B335C: bne         $at, $zero, L_800B336C
    if (ctx->r1 != 0) {
        // 0x800B3360: addiu       $t4, $zero, 0x1E
        ctx->r12 = ADD32(0, 0X1E);
            goto L_800B336C;
    }
    // 0x800B3360: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x800B3364: b           L_800B3370
    // 0x800B3368: sh          $t4, 0x378($s0)
    MEM_H(0X378, ctx->r16) = ctx->r12;
        goto L_800B3370;
    // 0x800B3368: sh          $t4, 0x378($s0)
    MEM_H(0X378, ctx->r16) = ctx->r12;
L_800B336C:
    // 0x800B336C: sh          $v0, 0x378($s0)
    MEM_H(0X378, ctx->r16) = ctx->r2;
L_800B3370:
    // 0x800B3370: lh          $t5, 0x2BA($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X2BA));
L_800B3374:
    // 0x800B3374: bltzl       $t5, L_800B339C
    if (SIGNED(ctx->r13) < 0) {
        // 0x800B3378: lh          $v0, 0x374($s0)
        ctx->r2 = S32(MEM_H(ctx->r16, 0X374));
            goto L_800B339C;
    }
    goto skip_6;
    // 0x800B3378: lh          $v0, 0x374($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X374));
    skip_6:
    // 0x800B337C: lh          $t7, 0x2D4($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2D4));
    // 0x800B3380: bnel        $t7, $zero, L_800B339C
    if (ctx->r15 != 0) {
        // 0x800B3384: lh          $v0, 0x374($s0)
        ctx->r2 = S32(MEM_H(ctx->r16, 0X374));
            goto L_800B339C;
    }
    goto skip_7;
    // 0x800B3384: lh          $v0, 0x374($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X374));
    skip_7:
    // 0x800B3388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B338C: jal         0x80075944
    // 0x800B3390: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    checkavailweapon(rdram, ctx);
        goto after_0;
    // 0x800B3390: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_0:
    // 0x800B3394: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800B3398: lh          $v0, 0x374($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X374));
L_800B339C:
    // 0x800B339C: lui         $at, 0xDB79
    ctx->r1 = S32(0XDB79 << 16);
    // 0x800B33A0: ori         $at, $at, 0x9F00
    ctx->r1 = ctx->r1 | 0X9F00;
    // 0x800B33A4: blez        $v0, L_800B33C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B33A8: and         $t6, $t0, $at
        ctx->r14 = ctx->r8 & ctx->r1;
            goto L_800B33C8;
    }
    // 0x800B33A8: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x800B33AC: addiu       $v1, $v0, -0xC
    ctx->r3 = ADD32(ctx->r2, -0XC);
    // 0x800B33B0: bgez        $v1, L_800B33C0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B33B4: nop
    
            goto L_800B33C0;
    }
    // 0x800B33B4: nop

    // 0x800B33B8: b           L_800B33E0
    // 0x800B33BC: sh          $zero, 0x374($s0)
    MEM_H(0X374, ctx->r16) = 0;
        goto L_800B33E0;
    // 0x800B33BC: sh          $zero, 0x374($s0)
    MEM_H(0X374, ctx->r16) = 0;
L_800B33C0:
    // 0x800B33C0: b           L_800B33E0
    // 0x800B33C4: sh          $v1, 0x374($s0)
    MEM_H(0X374, ctx->r16) = ctx->r3;
        goto L_800B33E0;
    // 0x800B33C4: sh          $v1, 0x374($s0)
    MEM_H(0X374, ctx->r16) = ctx->r3;
L_800B33C8:
    // 0x800B33C8: addiu       $v1, $v0, 0xC
    ctx->r3 = ADD32(ctx->r2, 0XC);
    // 0x800B33CC: blezl       $v1, L_800B33E0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B33D0: sh          $v1, 0x374($s0)
        MEM_H(0X374, ctx->r16) = ctx->r3;
            goto L_800B33E0;
    }
    goto skip_8;
    // 0x800B33D0: sh          $v1, 0x374($s0)
    MEM_H(0X374, ctx->r16) = ctx->r3;
    skip_8:
    // 0x800B33D4: b           L_800B33E0
    // 0x800B33D8: sh          $zero, 0x374($s0)
    MEM_H(0X374, ctx->r16) = 0;
        goto L_800B33E0;
    // 0x800B33D8: sh          $zero, 0x374($s0)
    MEM_H(0X374, ctx->r16) = 0;
    // 0x800B33DC: sh          $v1, 0x374($s0)
    MEM_H(0X374, ctx->r16) = ctx->r3;
L_800B33E0:
    // 0x800B33E0: lh          $v0, 0x316($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X316));
    // 0x800B33E4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B33E8: bgezl       $v0, L_800B33FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B33EC: sh          $v0, 0x316($s0)
        MEM_H(0X316, ctx->r16) = ctx->r2;
            goto L_800B33FC;
    }
    goto skip_9;
    // 0x800B33EC: sh          $v0, 0x316($s0)
    MEM_H(0X316, ctx->r16) = ctx->r2;
    skip_9:
    // 0x800B33F0: b           L_800B33FC
    // 0x800B33F4: sh          $zero, 0x316($s0)
    MEM_H(0X316, ctx->r16) = 0;
        goto L_800B33FC;
    // 0x800B33F4: sh          $zero, 0x316($s0)
    MEM_H(0X316, ctx->r16) = 0;
    // 0x800B33F8: sh          $v0, 0x316($s0)
    MEM_H(0X316, ctx->r16) = ctx->r2;
L_800B33FC:
    // 0x800B33FC: bnel        $t6, $zero, L_800B342C
    if (ctx->r14 != 0) {
        // 0x800B3400: lh          $t9, 0x316($s0)
        ctx->r25 = S32(MEM_H(ctx->r16, 0X316));
            goto L_800B342C;
    }
    goto skip_10;
    // 0x800B3400: lh          $t9, 0x316($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X316));
    skip_10:
    // 0x800B3404: lh          $v0, 0x316($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X316));
    // 0x800B3408: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800B340C: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800B3410: beq         $at, $zero, L_800B3420
    if (ctx->r1 == 0) {
        // 0x800B3414: nop
    
            goto L_800B3420;
    }
    // 0x800B3414: nop

    // 0x800B3418: b           L_800B3CBC
    // 0x800B341C: sh          $v0, 0x316($s0)
    MEM_H(0X316, ctx->r16) = ctx->r2;
        goto L_800B3CBC;
    // 0x800B341C: sh          $v0, 0x316($s0)
    MEM_H(0X316, ctx->r16) = ctx->r2;
L_800B3420:
    // 0x800B3420: b           L_800B3CBC
    // 0x800B3424: sh          $t8, 0x316($s0)
    MEM_H(0X316, ctx->r16) = ctx->r24;
        goto L_800B3CBC;
    // 0x800B3424: sh          $t8, 0x316($s0)
    MEM_H(0X316, ctx->r16) = ctx->r24;
    // 0x800B3428: lh          $t9, 0x316($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X316));
L_800B342C:
    // 0x800B342C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800B3430: bnel        $t9, $zero, L_800B3CC0
    if (ctx->r25 != 0) {
        // 0x800B3434: lw          $ra, 0x44($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
            goto L_800B3CC0;
    }
    goto skip_11;
    // 0x800B3434: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    skip_11:
    // 0x800B3438: lh          $t2, 0x2E0($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B343C: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x800B3440: sh          $t1, 0x316($s0)
    MEM_H(0X316, ctx->r16) = ctx->r9;
    // 0x800B3444: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B3448: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800B344C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B3450: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800B3454: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B3458: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800B345C: lh          $t4, 0x6BCA($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, 0X6BCA));
    // 0x800B3460: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x800B3464: blezl       $t4, L_800B3CC0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B3468: lw          $ra, 0x44($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
            goto L_800B3CC0;
    }
    goto skip_12;
    // 0x800B3468: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    skip_12:
    // 0x800B346C: bgezl       $t5, L_800B34FC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B3470: andi        $t7, $t0, 0x8000
        ctx->r15 = ctx->r8 & 0X8000;
            goto L_800B34FC;
    }
    goto skip_13;
    // 0x800B3470: andi        $t7, $t0, 0x8000
    ctx->r15 = ctx->r8 & 0X8000;
    skip_13:
    // 0x800B3474: lh          $t7, 0x2BE($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2BE));
    // 0x800B3478: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B347C: bnel        $t7, $at, L_800B34FC
    if (ctx->r15 != ctx->r1) {
        // 0x800B3480: andi        $t7, $t0, 0x8000
        ctx->r15 = ctx->r8 & 0X8000;
            goto L_800B34FC;
    }
    goto skip_14;
    // 0x800B3480: andi        $t7, $t0, 0x8000
    ctx->r15 = ctx->r8 & 0X8000;
    skip_14:
    // 0x800B3484: lbu         $t8, 0x33F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X33F);
    // 0x800B3488: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x800B348C: sw          $t6, 0x22C($s0)
    MEM_W(0X22C, ctx->r16) = ctx->r14;
    // 0x800B3490: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B3494: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x800B3498: beq         $at, $zero, L_800B34F8
    if (ctx->r1 == 0) {
        // 0x800B349C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800B34F8;
    }
    // 0x800B349C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B34A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B34A4: addu        $at, $at, $t9
    gpr jr_addend_800B34AC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B34A8: lw          $t9, -0x6E6C($at)
    ctx->r25 = ADD32(ctx->r1, -0X6E6C);
    // 0x800B34AC: jr          $t9
    // 0x800B34B0: nop

    switch (jr_addend_800B34AC >> 2) {
        case 0: goto L_800B34E0; break;
        case 1: goto L_800B34F0; break;
        case 2: goto L_800B34C4; break;
        case 3: goto L_800B34B4; break;
        case 4: goto L_800B34D4; break;
        default: switch_error(__func__, 0x800B34AC, 0x80109194);
    }
    // 0x800B34B0: nop

L_800B34B4:
    // 0x800B34B4: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800B34B8: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x800B34BC: b           L_800B34F8
    // 0x800B34C0: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
        goto L_800B34F8;
    // 0x800B34C0: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_800B34C4:
    // 0x800B34C4: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800B34C8: or          $t2, $t0, $at
    ctx->r10 = ctx->r8 | ctx->r1;
    // 0x800B34CC: b           L_800B34F8
    // 0x800B34D0: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
        goto L_800B34F8;
    // 0x800B34D0: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
L_800B34D4:
    // 0x800B34D4: ori         $t3, $t0, 0x8000
    ctx->r11 = ctx->r8 | 0X8000;
    // 0x800B34D8: b           L_800B34F8
    // 0x800B34DC: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
        goto L_800B34F8;
    // 0x800B34DC: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
L_800B34E0:
    // 0x800B34E0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B34E4: or          $t4, $t0, $at
    ctx->r12 = ctx->r8 | ctx->r1;
    // 0x800B34E8: b           L_800B34F8
    // 0x800B34EC: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
        goto L_800B34F8;
    // 0x800B34EC: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
L_800B34F0:
    // 0x800B34F0: ori         $t5, $t0, 0x1000
    ctx->r13 = ctx->r8 | 0X1000;
    // 0x800B34F4: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
L_800B34F8:
    // 0x800B34F8: andi        $t7, $t0, 0x8000
    ctx->r15 = ctx->r8 & 0X8000;
L_800B34FC:
    // 0x800B34FC: beql        $t7, $zero, L_800B3558
    if (ctx->r15 == 0) {
        // 0x800B3500: andi        $t4, $t0, 0x1000
        ctx->r12 = ctx->r8 & 0X1000;
            goto L_800B3558;
    }
    goto skip_15;
    // 0x800B3500: andi        $t4, $t0, 0x1000
    ctx->r12 = ctx->r8 & 0X1000;
    skip_15:
    // 0x800B3504: lh          $t6, 0x2EC($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2EC));
    // 0x800B3508: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800B350C: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x800B3510: blezl       $t6, L_800B3558
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B3514: andi        $t4, $t0, 0x1000
        ctx->r12 = ctx->r8 & 0X1000;
            goto L_800B3558;
    }
    goto skip_16;
    // 0x800B3514: andi        $t4, $t0, 0x1000
    ctx->r12 = ctx->r8 & 0X1000;
    skip_16:
    // 0x800B3518: lbu         $v1, 0x346($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X346);
    // 0x800B351C: sb          $t9, 0x33F($s0)
    MEM_B(0X33F, ctx->r16) = ctx->r25;
    // 0x800B3520: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B3524: sltiu       $t8, $v1, 0x1
    ctx->r24 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800B3528: sb          $t8, 0x346($s0)
    MEM_B(0X346, ctx->r16) = ctx->r24;
    // 0x800B352C: jal         0x80059034
    // 0x800B3530: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    spritesound(rdram, ctx);
        goto after_1;
    // 0x800B3530: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_1:
    // 0x800B3534: lbu         $v1, 0x346($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X346);
    // 0x800B3538: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B353C: sltiu       $t1, $v1, 0x1
    ctx->r9 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800B3540: addiu       $a0, $t1, 0x6A
    ctx->r4 = ADD32(ctx->r9, 0X6A);
    // 0x800B3544: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x800B3548: jal         0x80099868
    // 0x800B354C: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    FTA(rdram, ctx);
        goto after_2;
    // 0x800B354C: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_2:
    // 0x800B3550: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800B3554: andi        $t4, $t0, 0x1000
    ctx->r12 = ctx->r8 & 0X1000;
L_800B3558:
    // 0x800B3558: beql        $t4, $zero, L_800B35A0
    if (ctx->r12 == 0) {
        // 0x800B355C: lh          $t6, 0x2BE($s0)
        ctx->r14 = S32(MEM_H(ctx->r16, 0X2BE));
            goto L_800B35A0;
    }
    goto skip_17;
    // 0x800B355C: lh          $t6, 0x2BE($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2BE));
    skip_17:
    // 0x800B3560: lh          $v0, 0x320($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X320));
    // 0x800B3564: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x800B3568: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    // 0x800B356C: bne         $v0, $at, L_800B3CBC
    if (ctx->r2 != ctx->r1) {
        // 0x800B3570: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800B3CBC;
    }
    // 0x800B3570: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800B3574: sh          $t5, 0x320($s0)
    MEM_H(0X320, ctx->r16) = ctx->r13;
    // 0x800B3578: jal         0x80059034
    // 0x800B357C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_3;
    // 0x800B357C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_3:
    // 0x800B3580: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800B3584: sb          $t7, 0x33F($s0)
    MEM_B(0X33F, ctx->r16) = ctx->r15;
    // 0x800B3588: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800B358C: jal         0x80099868
    // 0x800B3590: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    FTA(rdram, ctx);
        goto after_4;
    // 0x800B3590: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800B3594: b           L_800B3CC0
    // 0x800B3598: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
        goto L_800B3CC0;
    // 0x800B3598: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800B359C: lh          $t6, 0x2BE($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2BE));
L_800B35A0:
    // 0x800B35A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B35A4: sll         $t8, $t0, 11
    ctx->r24 = S32(ctx->r8 << 11);
    // 0x800B35A8: bnel        $t6, $at, L_800B38A8
    if (ctx->r14 != ctx->r1) {
        // 0x800B35AC: lw          $t8, 0x258($s0)
        ctx->r24 = S32(MEM_W(ctx->r16, 0X258));
            goto L_800B38A8;
    }
    goto skip_18;
    // 0x800B35AC: lw          $t8, 0x258($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X258));
    skip_18:
    // 0x800B35B0: bltz        $t8, L_800B35C8
    if (SIGNED(ctx->r24) < 0) {
        // 0x800B35B4: sll         $t9, $t0, 4
        ctx->r25 = S32(ctx->r8 << 4);
            goto L_800B35C8;
    }
    // 0x800B35B4: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x800B35B8: bltzl       $t9, L_800B35CC
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B35BC: addiu       $t2, $zero, 0x64
        ctx->r10 = ADD32(0, 0X64);
            goto L_800B35CC;
    }
    goto skip_19;
    // 0x800B35BC: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    skip_19:
    // 0x800B35C0: lbu         $t1, 0x358($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X358);
    // 0x800B35C4: beq         $t1, $zero, L_800B38A4
    if (ctx->r9 == 0) {
        // 0x800B35C8: addiu       $t2, $zero, 0x64
        ctx->r10 = ADD32(0, 0X64);
            goto L_800B38A4;
    }
L_800B35C8:
    // 0x800B35C8: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
L_800B35CC:
    // 0x800B35CC: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x800B35D0: bgez        $t3, L_800B35E0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B35D4: sw          $t2, 0x22C($s0)
        MEM_W(0X22C, ctx->r16) = ctx->r10;
            goto L_800B35E0;
    }
    // 0x800B35D4: sw          $t2, 0x22C($s0)
    MEM_W(0X22C, ctx->r16) = ctx->r10;
    // 0x800B35D8: b           L_800B35E4
    // 0x800B35DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B35E4;
    // 0x800B35DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B35E0:
    // 0x800B35E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800B35E4:
    // 0x800B35E4: lbu         $t4, 0x358($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X358);
    // 0x800B35E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B35EC: beql        $t4, $zero, L_800B35FC
    if (ctx->r12 == 0) {
        // 0x800B35F0: lbu         $v0, 0x33F($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X33F);
            goto L_800B35FC;
    }
    goto skip_20;
    // 0x800B35F0: lbu         $v0, 0x33F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X33F);
    skip_20:
    // 0x800B35F4: sb          $zero, 0x358($s0)
    MEM_B(0X358, ctx->r16) = 0;
    // 0x800B35F8: lbu         $v0, 0x33F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X33F);
L_800B35FC:
    // 0x800B35FC: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800B3600: beql        $at, $zero, L_800B37BC
    if (ctx->r1 == 0) {
        // 0x800B3604: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B37BC;
    }
    goto skip_21;
    // 0x800B3604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_21:
L_800B3608:
    // 0x800B3608: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B360C: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x800B3610: sltiu       $at, $v0, 0x9
    ctx->r1 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x800B3614: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800B3618: beq         $at, $zero, L_800B37C0
    if (ctx->r1 == 0) {
        // 0x800B361C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800B37C0;
    }
    // 0x800B361C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B3620: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800B3624: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B3628: addu        $at, $at, $t6
    gpr jr_addend_800B3630 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B362C: lw          $t6, -0x6E58($at)
    ctx->r14 = ADD32(ctx->r1, -0X6E58);
    // 0x800B3630: jr          $t6
    // 0x800B3634: nop

    switch (jr_addend_800B3630 >> 2) {
        case 0: goto L_800B36F8; break;
        case 1: goto L_800B36F8; break;
        case 2: goto L_800B3698; break;
        case 3: goto L_800B36C8; break;
        case 4: goto L_800B3638; break;
        case 5: goto L_800B3728; break;
        case 6: goto L_800B3668; break;
        case 7: goto L_800B3758; break;
        case 8: goto L_800B3788; break;
        default: switch_error(__func__, 0x800B3630, 0x801091A8);
    }
    // 0x800B3634: nop

L_800B3638:
    // 0x800B3638: lh          $t8, 0x31E($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X31E));
    // 0x800B363C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B3640: blez        $t8, L_800B3650
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B3644: nop
    
            goto L_800B3650;
    }
    // 0x800B3644: nop

    // 0x800B3648: beql        $at, $zero, L_800B37C4
    if (ctx->r1 == 0) {
        // 0x800B364C: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800B37C4;
    }
    goto skip_22;
    // 0x800B364C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    skip_22:
L_800B3650:
    // 0x800B3650: beq         $a1, $zero, L_800B3660
    if (ctx->r5 == 0) {
        // 0x800B3654: nop
    
            goto L_800B3660;
    }
    // 0x800B3654: nop

    // 0x800B3658: b           L_800B35FC
    // 0x800B365C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800B35FC;
    // 0x800B365C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800B3660:
    // 0x800B3660: b           L_800B35FC
    // 0x800B3664: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B35FC;
    // 0x800B3664: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800B3668:
    // 0x800B3668: lh          $t9, 0x31C($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X31C));
    // 0x800B366C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B3670: blez        $t9, L_800B3680
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800B3674: nop
    
            goto L_800B3680;
    }
    // 0x800B3674: nop

    // 0x800B3678: beql        $at, $zero, L_800B37C4
    if (ctx->r1 == 0) {
        // 0x800B367C: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800B37C4;
    }
    goto skip_23;
    // 0x800B367C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    skip_23:
L_800B3680:
    // 0x800B3680: beq         $a1, $zero, L_800B3690
    if (ctx->r5 == 0) {
        // 0x800B3684: nop
    
            goto L_800B3690;
    }
    // 0x800B3684: nop

    // 0x800B3688: b           L_800B35FC
    // 0x800B368C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_800B35FC;
    // 0x800B368C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800B3690:
    // 0x800B3690: b           L_800B35FC
    // 0x800B3694: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800B35FC;
    // 0x800B3694: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800B3698:
    // 0x800B3698: lh          $t1, 0x320($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0X320));
    // 0x800B369C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B36A0: blez        $t1, L_800B36B0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B36A4: nop
    
            goto L_800B36B0;
    }
    // 0x800B36A4: nop

    // 0x800B36A8: beql        $at, $zero, L_800B37C4
    if (ctx->r1 == 0) {
        // 0x800B36AC: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800B37C4;
    }
    goto skip_24;
    // 0x800B36AC: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    skip_24:
L_800B36B0:
    // 0x800B36B0: beq         $a1, $zero, L_800B36C0
    if (ctx->r5 == 0) {
        // 0x800B36B4: nop
    
            goto L_800B36C0;
    }
    // 0x800B36B4: nop

    // 0x800B36B8: b           L_800B35FC
    // 0x800B36BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B35FC;
    // 0x800B36BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800B36C0:
    // 0x800B36C0: b           L_800B35FC
    // 0x800B36C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B35FC;
    // 0x800B36C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B36C8:
    // 0x800B36C8: lh          $t2, 0x2BC($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X2BC));
    // 0x800B36CC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B36D0: blez        $t2, L_800B36E0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B36D4: nop
    
            goto L_800B36E0;
    }
    // 0x800B36D4: nop

    // 0x800B36D8: beql        $at, $zero, L_800B37C4
    if (ctx->r1 == 0) {
        // 0x800B36DC: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800B37C4;
    }
    goto skip_25;
    // 0x800B36DC: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    skip_25:
L_800B36E0:
    // 0x800B36E0: beq         $a1, $zero, L_800B36F0
    if (ctx->r5 == 0) {
        // 0x800B36E4: nop
    
            goto L_800B36F0;
    }
    // 0x800B36E4: nop

    // 0x800B36E8: b           L_800B35FC
    // 0x800B36EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B35FC;
    // 0x800B36EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800B36F0:
    // 0x800B36F0: b           L_800B35FC
    // 0x800B36F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B35FC;
    // 0x800B36F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800B36F8:
    // 0x800B36F8: lh          $t3, 0x2DA($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2DA));
    // 0x800B36FC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B3700: blez        $t3, L_800B3710
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B3704: nop
    
            goto L_800B3710;
    }
    // 0x800B3704: nop

    // 0x800B3708: beql        $at, $zero, L_800B37C4
    if (ctx->r1 == 0) {
        // 0x800B370C: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800B37C4;
    }
    goto skip_26;
    // 0x800B370C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    skip_26:
L_800B3710:
    // 0x800B3710: beq         $a1, $zero, L_800B3720
    if (ctx->r5 == 0) {
        // 0x800B3714: nop
    
            goto L_800B3720;
    }
    // 0x800B3714: nop

    // 0x800B3718: b           L_800B35FC
    // 0x800B371C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B35FC;
    // 0x800B371C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800B3720:
    // 0x800B3720: b           L_800B35FC
    // 0x800B3724: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800B35FC;
    // 0x800B3724: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800B3728:
    // 0x800B3728: lh          $t4, 0x2EC($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X2EC));
    // 0x800B372C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B3730: blez        $t4, L_800B3740
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B3734: nop
    
            goto L_800B3740;
    }
    // 0x800B3734: nop

    // 0x800B3738: beql        $at, $zero, L_800B37C4
    if (ctx->r1 == 0) {
        // 0x800B373C: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800B37C4;
    }
    goto skip_27;
    // 0x800B373C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    skip_27:
L_800B3740:
    // 0x800B3740: beq         $a1, $zero, L_800B3750
    if (ctx->r5 == 0) {
        // 0x800B3744: nop
    
            goto L_800B3750;
    }
    // 0x800B3744: nop

    // 0x800B3748: b           L_800B35FC
    // 0x800B374C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800B35FC;
    // 0x800B374C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800B3750:
    // 0x800B3750: b           L_800B35FC
    // 0x800B3754: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800B35FC;
    // 0x800B3754: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800B3758:
    // 0x800B3758: lh          $t5, 0x332($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X332));
    // 0x800B375C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B3760: blez        $t5, L_800B3770
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B3764: nop
    
            goto L_800B3770;
    }
    // 0x800B3764: nop

    // 0x800B3768: beql        $at, $zero, L_800B37C4
    if (ctx->r1 == 0) {
        // 0x800B376C: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800B37C4;
    }
    goto skip_28;
    // 0x800B376C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    skip_28:
L_800B3770:
    // 0x800B3770: beq         $a1, $zero, L_800B3780
    if (ctx->r5 == 0) {
        // 0x800B3774: nop
    
            goto L_800B3780;
    }
    // 0x800B3774: nop

    // 0x800B3778: b           L_800B35FC
    // 0x800B377C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800B35FC;
    // 0x800B377C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800B3780:
    // 0x800B3780: b           L_800B35FC
    // 0x800B3784: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800B35FC;
    // 0x800B3784: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800B3788:
    // 0x800B3788: lh          $t7, 0x322($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X322));
    // 0x800B378C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800B3790: blez        $t7, L_800B37A0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B3794: nop
    
            goto L_800B37A0;
    }
    // 0x800B3794: nop

    // 0x800B3798: beql        $at, $zero, L_800B37C4
    if (ctx->r1 == 0) {
        // 0x800B379C: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800B37C4;
    }
    goto skip_29;
    // 0x800B379C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    skip_29:
L_800B37A0:
    // 0x800B37A0: beq         $a1, $zero, L_800B37B0
    if (ctx->r5 == 0) {
        // 0x800B37A4: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_800B37B0;
    }
    // 0x800B37A4: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800B37A8: b           L_800B35FC
    // 0x800B37AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B35FC;
    // 0x800B37AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B37B0:
    // 0x800B37B0: bne         $at, $zero, L_800B3608
    if (ctx->r1 != 0) {
        // 0x800B37B4: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800B3608;
    }
    // 0x800B37B4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800B37B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B37BC:
    // 0x800B37BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B37C0:
    // 0x800B37C0: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
L_800B37C4:
    // 0x800B37C4: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800B37C8: beq         $at, $zero, L_800B38A4
    if (ctx->r1 == 0) {
        // 0x800B37CC: sb          $v0, 0x33F($s0)
        MEM_B(0X33F, ctx->r16) = ctx->r2;
            goto L_800B38A4;
    }
    // 0x800B37CC: sb          $v0, 0x33F($s0)
    MEM_B(0X33F, ctx->r16) = ctx->r2;
    // 0x800B37D0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B37D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B37D8: addu        $at, $at, $t6
    gpr jr_addend_800B37E0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B37DC: lw          $t6, -0x6E34($at)
    ctx->r14 = ADD32(ctx->r1, -0X6E34);
    // 0x800B37E0: jr          $t6
    // 0x800B37E4: nop

    switch (jr_addend_800B37E0 >> 2) {
        case 0: goto L_800B37E8; break;
        case 1: goto L_800B3800; break;
        case 2: goto L_800B3818; break;
        case 3: goto L_800B3830; break;
        case 4: goto L_800B3848; break;
        case 5: goto L_800B3860; break;
        case 6: goto L_800B3878; break;
        case 7: goto L_800B3890; break;
        default: switch_error(__func__, 0x800B37E0, 0x801091CC);
    }
    // 0x800B37E4: nop

L_800B37E8:
    // 0x800B37E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800B37EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B37F0: jal         0x80099868
    // 0x800B37F4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_5;
    // 0x800B37F4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_5:
    // 0x800B37F8: b           L_800B38A4
    // 0x800B37FC: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B38A4;
    // 0x800B37FC: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3800:
    // 0x800B3800: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x800B3804: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3808: jal         0x80099868
    // 0x800B380C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_6;
    // 0x800B380C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_6:
    // 0x800B3810: b           L_800B38A4
    // 0x800B3814: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B38A4;
    // 0x800B3814: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3818:
    // 0x800B3818: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    // 0x800B381C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3820: jal         0x80099868
    // 0x800B3824: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_7;
    // 0x800B3824: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_7:
    // 0x800B3828: b           L_800B38A4
    // 0x800B382C: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B38A4;
    // 0x800B382C: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3830:
    // 0x800B3830: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    // 0x800B3834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3838: jal         0x80099868
    // 0x800B383C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_8;
    // 0x800B383C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_8:
    // 0x800B3840: b           L_800B38A4
    // 0x800B3844: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B38A4;
    // 0x800B3844: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3848:
    // 0x800B3848: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x800B384C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3850: jal         0x80099868
    // 0x800B3854: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_9;
    // 0x800B3854: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_9:
    // 0x800B3858: b           L_800B38A4
    // 0x800B385C: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B38A4;
    // 0x800B385C: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3860:
    // 0x800B3860: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    // 0x800B3864: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3868: jal         0x80099868
    // 0x800B386C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_10;
    // 0x800B386C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_10:
    // 0x800B3870: b           L_800B38A4
    // 0x800B3874: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B38A4;
    // 0x800B3874: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3878:
    // 0x800B3878: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800B387C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3880: jal         0x80099868
    // 0x800B3884: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_11;
    // 0x800B3884: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_11:
    // 0x800B3888: b           L_800B38A4
    // 0x800B388C: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B38A4;
    // 0x800B388C: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3890:
    // 0x800B3890: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x800B3894: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3898: jal         0x80099868
    // 0x800B389C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_12;
    // 0x800B389C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_12:
    // 0x800B38A0: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B38A4:
    // 0x800B38A4: lw          $t8, 0x258($s0)
    ctx->r24 = S32(MEM_W(ctx->r16, 0X258));
L_800B38A8:
    // 0x800B38A8: slti        $at, $t8, 0x1625
    ctx->r1 = SIGNED(ctx->r24) < 0X1625 ? 1 : 0;
    // 0x800B38AC: beql        $at, $zero, L_800B39DC
    if (ctx->r1 == 0) {
        // 0x800B38B0: sll         $t5, $t0, 7
        ctx->r13 = S32(ctx->r8 << 7);
            goto L_800B39DC;
    }
    goto skip_30;
    // 0x800B38B0: sll         $t5, $t0, 7
    ctx->r13 = S32(ctx->r8 << 7);
    skip_30:
    // 0x800B38B4: lh          $t9, 0x2EA($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X2EA));
    // 0x800B38B8: bnel        $t9, $zero, L_800B39DC
    if (ctx->r25 != 0) {
        // 0x800B38BC: sll         $t5, $t0, 7
        ctx->r13 = S32(ctx->r8 << 7);
            goto L_800B39DC;
    }
    goto skip_31;
    // 0x800B38BC: sll         $t5, $t0, 7
    ctx->r13 = S32(ctx->r8 << 7);
    skip_31:
    // 0x800B38C0: lh          $t1, 0x2E0($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B38C4: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x800B38C8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B38CC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800B38D0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B38D4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800B38D8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B38DC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800B38E0: lbu         $t3, 0x6BCF($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6BCF);
    // 0x800B38E4: slti        $at, $t3, 0x21
    ctx->r1 = SIGNED(ctx->r11) < 0X21 ? 1 : 0;
    // 0x800B38E8: bnel        $at, $zero, L_800B39DC
    if (ctx->r1 != 0) {
        // 0x800B38EC: sll         $t5, $t0, 7
        ctx->r13 = S32(ctx->r8 << 7);
            goto L_800B39DC;
    }
    goto skip_32;
    // 0x800B38EC: sll         $t5, $t0, 7
    ctx->r13 = S32(ctx->r8 << 7);
    skip_32:
    // 0x800B38F0: lh          $t4, 0x2CA($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X2CA));
    // 0x800B38F4: bnel        $t4, $zero, L_800B39DC
    if (ctx->r12 != 0) {
        // 0x800B38F8: sll         $t5, $t0, 7
        ctx->r13 = S32(ctx->r8 << 7);
            goto L_800B39DC;
    }
    goto skip_33;
    // 0x800B38F8: sll         $t5, $t0, 7
    ctx->r13 = S32(ctx->r8 << 7);
    skip_33:
    // 0x800B38FC: lh          $t5, 0x2C8($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X2C8));
    // 0x800B3900: andi        $v0, $t0, 0xF00
    ctx->r2 = ctx->r8 & 0XF00;
    // 0x800B3904: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800B3908: bne         $t5, $zero, L_800B39D8
    if (ctx->r13 != 0) {
        // 0x800B390C: srl         $t7, $v0, 8
        ctx->r15 = S32(U32(ctx->r2) >> 8);
            goto L_800B39D8;
    }
    // 0x800B390C: srl         $t7, $v0, 8
    ctx->r15 = S32(U32(ctx->r2) >> 8);
    // 0x800B3910: addiu       $v0, $t7, -0x1
    ctx->r2 = ADD32(ctx->r15, -0X1);
    // 0x800B3914: beq         $v0, $v1, L_800B3924
    if (ctx->r2 == ctx->r3) {
        // 0x800B3918: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800B3924;
    }
    // 0x800B3918: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800B391C: bnel        $v0, $at, L_800B39DC
    if (ctx->r2 != ctx->r1) {
        // 0x800B3920: sll         $t5, $t0, 7
        ctx->r13 = S32(ctx->r8 << 7);
            goto L_800B39DC;
    }
    goto skip_34;
    // 0x800B3920: sll         $t5, $t0, 7
    ctx->r13 = S32(ctx->r8 << 7);
    skip_34:
L_800B3924:
    // 0x800B3924: lh          $a1, 0x372($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X372));
    // 0x800B3928: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800B392C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3930: beq         $a1, $at, L_800B3950
    if (ctx->r5 == ctx->r1) {
        // 0x800B3934: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800B3950;
    }
    // 0x800B3934: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800B3938: beq         $a1, $at, L_800B3958
    if (ctx->r5 == ctx->r1) {
        // 0x800B393C: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_800B3958;
    }
    // 0x800B393C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800B3940: beql        $a1, $at, L_800B3964
    if (ctx->r5 == ctx->r1) {
        // 0x800B3944: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_800B3964;
    }
    goto skip_35;
    // 0x800B3944: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    skip_35:
    // 0x800B3948: b           L_800B3964
    // 0x800B394C: nop

        goto L_800B3964;
    // 0x800B394C: nop

L_800B3950:
    // 0x800B3950: b           L_800B3964
    // 0x800B3954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B3964;
    // 0x800B3954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B3958:
    // 0x800B3958: b           L_800B3964
    // 0x800B395C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_800B3964;
    // 0x800B395C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800B3960: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_800B3964:
    // 0x800B3964: bnel        $v0, $v1, L_800B3978
    if (ctx->r2 != ctx->r3) {
        // 0x800B3968: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800B3978;
    }
    goto skip_36;
    // 0x800B3968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_36:
    // 0x800B396C: b           L_800B3978
    // 0x800B3970: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B3978;
    // 0x800B3970: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B3974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B3978:
    // 0x800B3978: negu        $at, $v0
    ctx->r1 = SUB32(0, ctx->r2);
    // 0x800B397C: sll         $t6, $at, 4
    ctx->r14 = S32(ctx->r1 << 4);
    // 0x800B3980: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x800B3984: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B3988: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800B398C: sh          $t6, 0x374($s0)
    MEM_H(0X374, ctx->r16) = ctx->r14;
    // 0x800B3990: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800B3994: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B3998: jal         0x800B2FB0
    // 0x800B399C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    getnextweapon(rdram, ctx);
        goto after_13;
    // 0x800B399C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_13:
    // 0x800B39A0: lbu         $t9, 0x347($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X347);
    // 0x800B39A4: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800B39A8: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800B39AC: beq         $t9, $zero, L_800B39C8
    if (ctx->r25 == 0) {
        // 0x800B39B0: addu        $t3, $s0, $v0
        ctx->r11 = ADD32(ctx->r16, ctx->r2);
            goto L_800B39C8;
    }
    // 0x800B39B0: addu        $t3, $s0, $v0
    ctx->r11 = ADD32(ctx->r16, ctx->r2);
    // 0x800B39B4: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x800B39B8: addiu       $t2, $zero, -0x9
    ctx->r10 = ADD32(0, -0X9);
    // 0x800B39BC: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x800B39C0: b           L_800B39D8
    // 0x800B39C4: sh          $t2, 0x328($s0)
    MEM_H(0X328, ctx->r16) = ctx->r10;
        goto L_800B39D8;
    // 0x800B39C4: sh          $t2, 0x328($s0)
    MEM_H(0X328, ctx->r16) = ctx->r10;
L_800B39C8:
    // 0x800B39C8: lbu         $t4, 0x349($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X349);
    // 0x800B39CC: beql        $t4, $zero, L_800B39DC
    if (ctx->r12 == 0) {
        // 0x800B39D0: sll         $t5, $t0, 7
        ctx->r13 = S32(ctx->r8 << 7);
            goto L_800B39DC;
    }
    goto skip_37;
    // 0x800B39D0: sll         $t5, $t0, 7
    ctx->r13 = S32(ctx->r8 << 7);
    skip_37:
    // 0x800B39D4: sh          $v0, 0x372($s0)
    MEM_H(0X372, ctx->r16) = ctx->r2;
L_800B39D8:
    // 0x800B39D8: sll         $t5, $t0, 7
    ctx->r13 = S32(ctx->r8 << 7);
L_800B39DC:
    // 0x800B39DC: bgezl       $t5, L_800B3B20
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B39E0: sll         $t2, $t0, 15
        ctx->r10 = S32(ctx->r8 << 15);
            goto L_800B3B20;
    }
    goto skip_38;
    // 0x800B39E0: sll         $t2, $t0, 15
    ctx->r10 = S32(ctx->r8 << 15);
    skip_38:
    // 0x800B39E4: lh          $t7, 0x2BE($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X2BE));
    // 0x800B39E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B39EC: bnel        $t7, $at, L_800B3B20
    if (ctx->r15 != ctx->r1) {
        // 0x800B39F0: sll         $t2, $t0, 15
        ctx->r10 = S32(ctx->r8 << 15);
            goto L_800B3B20;
    }
    goto skip_39;
    // 0x800B39F0: sll         $t2, $t0, 15
    ctx->r10 = S32(ctx->r8 << 15);
    skip_39:
    // 0x800B39F4: lh          $a1, 0x324($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X324));
    // 0x800B39F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B39FC: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x800B3A00: bne         $a1, $at, L_800B3AFC
    if (ctx->r5 != ctx->r1) {
        // 0x800B3A04: nop
    
            goto L_800B3AFC;
    }
    // 0x800B3A04: nop

    // 0x800B3A08: lh          $t6, 0x2BC($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X2BC));
    // 0x800B3A0C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800B3A10: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x800B3A14: blez        $t6, L_800B3AD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B3A18: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800B3AD8;
    }
    // 0x800B3A18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3A1C: lw          $a3, 0x21C($s0)
    ctx->r7 = S32(MEM_W(ctx->r16, 0X21C));
    // 0x800B3A20: sb          $t8, 0x33F($s0)
    MEM_B(0X33F, ctx->r16) = ctx->r24;
    // 0x800B3A24: lh          $a0, 0x288($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X288));
    // 0x800B3A28: lw          $a1, 0x214($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X214));
    // 0x800B3A2C: lw          $a2, 0x218($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X218));
    // 0x800B3A30: addiu       $t9, $zero, 0x57D
    ctx->r25 = ADD32(0, 0X57D);
    // 0x800B3A34: addiu       $t1, $zero, -0x40
    ctx->r9 = ADD32(0, -0X40);
    // 0x800B3A38: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B3A3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800B3A40: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800B3A44: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B3A48: lh          $t2, 0x282($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X282));
    // 0x800B3A4C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800B3A50: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800B3A54: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x800B3A58: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800B3A5C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800B3A60: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800B3A64: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800B3A68: addiu       $a3, $a3, 0x1E00
    ctx->r7 = ADD32(ctx->r7, 0X1E00);
    // 0x800B3A6C: jal         0x8009B028
    // 0x800B3A70: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    EGS(rdram, ctx);
        goto after_14;
    // 0x800B3A70: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_14:
    // 0x800B3A74: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800B3A78: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800B3A7C: sh          $v0, 0x324($s0)
    MEM_H(0X324, ctx->r16) = ctx->r2;
    // 0x800B3A80: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800B3A84: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B3A88: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x800B3A8C: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800B3A90: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800B3A94: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800B3A98: lh          $t9, 0x5A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x800B3A9C: addiu       $t7, $t7, -0x5C00
    ctx->r15 = ADD32(ctx->r15, -0X5C00);
    // 0x800B3AA0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800B3AA4: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x800B3AA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B3AAC: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x800B3AB0: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x800B3AB4: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x800B3AB8: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x800B3ABC: sh          $zero, 0x22($a2)
    MEM_H(0X22, ctx->r6) = 0;
    // 0x800B3AC0: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x800B3AC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3AC8: jal         0x80099868
    // 0x800B3ACC: sh          $t9, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r25;
    FTA(rdram, ctx);
        goto after_15;
    // 0x800B3ACC: sh          $t9, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r25;
    after_15:
    // 0x800B3AD0: b           L_800B3AE4
    // 0x800B3AD4: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B3AE4;
    // 0x800B3AD4: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3AD8:
    // 0x800B3AD8: jal         0x80099868
    // 0x800B3ADC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    FTA(rdram, ctx);
        goto after_16;
    // 0x800B3ADC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_16:
    // 0x800B3AE0: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3AE4:
    // 0x800B3AE4: lh          $a1, 0x324($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X324));
    // 0x800B3AE8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800B3AEC: jal         0x80059034
    // 0x800B3AF0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    spritesound(rdram, ctx);
        goto after_17;
    // 0x800B3AF0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_17:
    // 0x800B3AF4: b           L_800B3B1C
    // 0x800B3AF8: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B3B1C;
    // 0x800B3AF8: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3AFC:
    // 0x800B3AFC: jal         0x80059034
    // 0x800B3B00: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    spritesound(rdram, ctx);
        goto after_18;
    // 0x800B3B00: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_18:
    // 0x800B3B04: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800B3B08: sh          $t1, 0x324($s0)
    MEM_H(0X324, ctx->r16) = ctx->r9;
    // 0x800B3B0C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x800B3B10: jal         0x80099868
    // 0x800B3B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    FTA(rdram, ctx);
        goto after_19;
    // 0x800B3B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x800B3B18: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3B1C:
    // 0x800B3B1C: sll         $t2, $t0, 15
    ctx->r10 = S32(ctx->r8 << 15);
L_800B3B20:
    // 0x800B3B20: bgezl       $t2, L_800B3BF8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B3B24: sll         $t3, $t0, 6
        ctx->r11 = S32(ctx->r8 << 6);
            goto L_800B3BF8;
    }
    goto skip_40;
    // 0x800B3B24: sll         $t3, $t0, 6
    ctx->r11 = S32(ctx->r8 << 6);
    skip_40:
    // 0x800B3B28: lh          $a2, 0x2DA($s0)
    ctx->r6 = S32(MEM_H(ctx->r16, 0X2DA));
    // 0x800B3B2C: blezl       $a2, L_800B3BF8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800B3B30: sll         $t3, $t0, 6
        ctx->r11 = S32(ctx->r8 << 6);
            goto L_800B3BF8;
    }
    goto skip_41;
    // 0x800B3B30: sll         $t3, $t0, 6
    ctx->r11 = S32(ctx->r8 << 6);
    skip_41:
    // 0x800B3B34: lh          $t3, 0x2E0($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B3B38: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x800B3B3C: addiu       $t5, $t5, 0x6BA8
    ctx->r13 = ADD32(ctx->r13, 0X6BA8);
    // 0x800B3B40: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B3B44: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800B3B48: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B3B4C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800B3B50: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B3B54: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x800B3B58: lh          $a1, 0x22($v1)
    ctx->r5 = S32(MEM_H(ctx->r3, 0X22));
    // 0x800B3B5C: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x800B3B60: slti        $at, $a1, 0x64
    ctx->r1 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
    // 0x800B3B64: beq         $at, $zero, L_800B3BF4
    if (ctx->r1 == 0) {
        // 0x800B3B68: subu        $v0, $t7, $a1
        ctx->r2 = SUB32(ctx->r15, ctx->r5);
            goto L_800B3BF4;
    }
    // 0x800B3B68: subu        $v0, $t7, $a1
    ctx->r2 = SUB32(ctx->r15, ctx->r5);
    // 0x800B3B6C: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800B3B70: beq         $at, $zero, L_800B3B94
    if (ctx->r1 == 0) {
        // 0x800B3B74: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800B3B94;
    }
    // 0x800B3B74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B3B78: subu        $t6, $a0, $v0
    ctx->r14 = SUB32(ctx->r4, ctx->r2);
    // 0x800B3B7C: sh          $t6, 0x2DA($s0)
    MEM_H(0X2DA, ctx->r16) = ctx->r14;
    // 0x800B3B80: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800B3B84: sh          $t8, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r24;
    // 0x800B3B88: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B3B8C: b           L_800B3BB0
    // 0x800B3B90: sb          $t9, 0x33F($s0)
    MEM_B(0X33F, ctx->r16) = ctx->r25;
        goto L_800B3BB0;
    // 0x800B3B90: sb          $t9, 0x33F($s0)
    MEM_B(0X33F, ctx->r16) = ctx->r25;
L_800B3B94:
    // 0x800B3B94: addu        $t1, $a1, $a2
    ctx->r9 = ADD32(ctx->r5, ctx->r6);
    // 0x800B3B98: sh          $t1, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r9;
    // 0x800B3B9C: sh          $zero, 0x2DA($s0)
    MEM_H(0X2DA, ctx->r16) = 0;
    // 0x800B3BA0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800B3BA4: jal         0x80075878
    // 0x800B3BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    checkavailinven(rdram, ctx);
        goto after_20;
    // 0x800B3BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800B3BAC: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3BB0:
    // 0x800B3BB0: jal         0x8009800C
    // 0x800B3BB4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    krand2(rdram, ctx);
        goto after_21;
    // 0x800B3BB4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_21:
    // 0x800B3BB8: andi        $t2, $v0, 0x3F
    ctx->r10 = ctx->r2 & 0X3F;
    // 0x800B3BBC: slti        $at, $t2, 0x32
    ctx->r1 = SIGNED(ctx->r10) < 0X32 ? 1 : 0;
    // 0x800B3BC0: beq         $at, $zero, L_800B3BE0
    if (ctx->r1 == 0) {
        // 0x800B3BC4: lw          $t0, 0x4C($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
            goto L_800B3BE0;
    }
    // 0x800B3BC4: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800B3BC8: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B3BCC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800B3BD0: jal         0x80059034
    // 0x800B3BD4: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    spritesound(rdram, ctx);
        goto after_22;
    // 0x800B3BD4: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    after_22:
    // 0x800B3BD8: b           L_800B3BF4
    // 0x800B3BDC: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
        goto L_800B3BF4;
    // 0x800B3BDC: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3BE0:
    // 0x800B3BE0: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    // 0x800B3BE4: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800B3BE8: jal         0x80059034
    // 0x800B3BEC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    spritesound(rdram, ctx);
        goto after_23;
    // 0x800B3BEC: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_23:
    // 0x800B3BF0: lw          $t0, 0x4C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X4C));
L_800B3BF4:
    // 0x800B3BF4: sll         $t3, $t0, 6
    ctx->r11 = S32(ctx->r8 << 6);
L_800B3BF8:
    // 0x800B3BF8: bgezl       $t3, L_800B3CC0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B3BFC: lw          $ra, 0x44($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
            goto L_800B3CC0;
    }
    goto skip_42;
    // 0x800B3BFC: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    skip_42:
    // 0x800B3C00: lh          $t4, 0x2BE($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0X2BE));
    // 0x800B3C04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B3C08: bnel        $t4, $at, L_800B3CC0
    if (ctx->r12 != ctx->r1) {
        // 0x800B3C0C: lw          $ra, 0x44($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
            goto L_800B3CC0;
    }
    goto skip_43;
    // 0x800B3C0C: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
    skip_43:
    // 0x800B3C10: lh          $t5, 0x31E($s0)
    ctx->r13 = S32(MEM_H(ctx->r16, 0X31E));
    // 0x800B3C14: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800B3C18: blez        $t5, L_800B3CB4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B3C1C: nop
    
            goto L_800B3CB4;
    }
    // 0x800B3C1C: nop

    // 0x800B3C20: lbu         $v1, 0x341($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X341);
    // 0x800B3C24: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x800B3C28: sltiu       $t7, $v1, 0x1
    ctx->r15 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800B3C2C: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800B3C30: beq         $t6, $zero, L_800B3C80
    if (ctx->r14 == 0) {
        // 0x800B3C34: sb          $t7, 0x341($s0)
        MEM_B(0X341, ctx->r16) = ctx->r15;
            goto L_800B3C80;
    }
    // 0x800B3C34: sb          $t7, 0x341($s0)
    MEM_B(0X341, ctx->r16) = ctx->r15;
    // 0x800B3C38: lw          $a0, 0x334($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X334));
    // 0x800B3C3C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800B3C40: sb          $t8, 0x33F($s0)
    MEM_B(0X33F, ctx->r16) = ctx->r24;
    // 0x800B3C44: blezl       $a0, L_800B3C64
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B3C48: addiu       $a0, $zero, 0x26
        ctx->r4 = ADD32(0, 0X26);
            goto L_800B3C64;
    }
    goto skip_44;
    // 0x800B3C48: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    skip_44:
    // 0x800B3C4C: jal         0x800593F8
    // 0x800B3C50: nop

    FX_StopSound(rdram, ctx);
        goto after_24;
    // 0x800B3C50: nop

    after_24:
    // 0x800B3C54: jal         0x800590B0
    // 0x800B3C58: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    testcallback(rdram, ctx);
        goto after_25;
    // 0x800B3C58: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_25:
    // 0x800B3C5C: sw          $zero, 0x334($s0)
    MEM_W(0X334, ctx->r16) = 0;
    // 0x800B3C60: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
L_800B3C64:
    // 0x800B3C64: jal         0x80059034
    // 0x800B3C68: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_26;
    // 0x800B3C68: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_26:
    // 0x800B3C6C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x800B3C70: jal         0x80099868
    // 0x800B3C74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    FTA(rdram, ctx);
        goto after_27;
    // 0x800B3C74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_27:
    // 0x800B3C78: b           L_800B3CC0
    // 0x800B3C7C: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
        goto L_800B3CC0;
    // 0x800B3C7C: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
L_800B3C80:
    // 0x800B3C80: sb          $zero, 0x364($s0)
    MEM_B(0X364, ctx->r16) = 0;
    // 0x800B3C84: sw          $zero, 0x254($s0)
    MEM_W(0X254, ctx->r16) = 0;
    // 0x800B3C88: jal         0x80059034
    // 0x800B3C8C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_28;
    // 0x800B3C8C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_28:
    // 0x800B3C90: jal         0x80059218
    // 0x800B3C94: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    stopsound(rdram, ctx);
        goto after_29;
    // 0x800B3C94: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_29:
    // 0x800B3C98: jal         0x80059218
    // 0x800B3C9C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    stopsound(rdram, ctx);
        goto after_30;
    // 0x800B3C9C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_30:
    // 0x800B3CA0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x800B3CA4: jal         0x80099868
    // 0x800B3CA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    FTA(rdram, ctx);
        goto after_31;
    // 0x800B3CA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_31:
    // 0x800B3CAC: b           L_800B3CC0
    // 0x800B3CB0: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
        goto L_800B3CC0;
    // 0x800B3CB0: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
L_800B3CB4:
    // 0x800B3CB4: jal         0x80099868
    // 0x800B3CB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    FTA(rdram, ctx);
        goto after_32;
    // 0x800B3CB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_32:
L_800B3CBC:
    // 0x800B3CBC: lw          $ra, 0x44($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X44));
L_800B3CC0:
    // 0x800B3CC0: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800B3CC4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800B3CC8: jr          $ra
    // 0x800B3CCC: nop

    return;
    // 0x800B3CCC: nop

;}
RECOMP_FUNC void neartag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094A24: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x80094A28: lw          $t7, 0x144($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X144));
    // 0x80094A2C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80094A30: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80094A34: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80094A38: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80094A3C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80094A40: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80094A44: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80094A48: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80094A4C: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80094A50: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80094A54: sw          $a1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r5;
    // 0x80094A58: sw          $a2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r6;
    // 0x80094A5C: sw          $a3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r7;
    // 0x80094A60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80094A64: sh          $v0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r2;
    // 0x80094A68: lw          $t8, 0x148($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X148));
    // 0x80094A6C: sll         $s0, $a3, 16
    ctx->r16 = S32(ctx->r7 << 16);
    // 0x80094A70: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80094A74: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
    // 0x80094A78: lw          $t9, 0x14C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x80094A7C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80094A80: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80094A84: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x80094A88: lw          $t3, 0x150($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X150));
    // 0x80094A8C: bgez        $t6, L_80094A9C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80094A90: sw          $zero, 0x0($t3)
        MEM_W(0X0, ctx->r11) = 0;
            goto L_80094A9C;
    }
    // 0x80094A90: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x80094A94: b           L_800951EC
    // 0x80094A98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800951EC;
    // 0x80094A98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80094A9C:
    // 0x80094A9C: lbu         $v0, 0x15B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X15B);
    // 0x80094AA0: blez        $v0, L_80094AB0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80094AA4: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80094AB0;
    }
    // 0x80094AA4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80094AA8: bne         $at, $zero, L_80094AB8
    if (ctx->r1 != 0) {
        // 0x80094AAC: lh          $s1, 0x142($sp)
        ctx->r17 = S32(MEM_H(ctx->r29, 0X142));
            goto L_80094AB8;
    }
    // 0x80094AAC: lh          $s1, 0x142($sp)
    ctx->r17 = S32(MEM_H(ctx->r29, 0X142));
L_80094AB0:
    // 0x80094AB0: b           L_800951EC
    // 0x80094AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800951EC;
    // 0x80094AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80094AB8:
    // 0x80094AB8: addiu       $t4, $s1, 0xA00
    ctx->r12 = ADD32(ctx->r17, 0XA00);
    // 0x80094ABC: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x80094AC0: andi        $t5, $t4, 0x7FF
    ctx->r13 = ctx->r12 & 0X7FF;
    // 0x80094AC4: lw          $a3, 0x154($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X154));
    // 0x80094AC8: addiu       $s2, $s2, -0x9A0
    ctx->r18 = ADD32(ctx->r18, -0X9A0);
    // 0x80094ACC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80094AD0: addu        $v1, $s2, $t6
    ctx->r3 = ADD32(ctx->r18, ctx->r14);
    // 0x80094AD4: lh          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_H(ctx->r3, 0X0));
    // 0x80094AD8: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80094ADC: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80094AE0: sw          $v1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r3;
    // 0x80094AE4: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x80094AE8: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80094AEC: jal         0x8008FCD8
    // 0x80094AF0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale14(rdram, ctx);
        goto after_0;
    // 0x80094AF0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_0:
    // 0x80094AF4: addiu       $t3, $s1, 0x800
    ctx->r11 = ADD32(ctx->r17, 0X800);
    // 0x80094AF8: andi        $t6, $t3, 0x7FF
    ctx->r14 = ctx->r11 & 0X7FF;
    // 0x80094AFC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80094B00: addu        $v1, $s2, $t7
    ctx->r3 = ADD32(ctx->r18, ctx->r15);
    // 0x80094B04: lh          $a1, 0x0($v1)
    ctx->r5 = S32(MEM_H(ctx->r3, 0X0));
    // 0x80094B08: addu        $t9, $fp, $v0
    ctx->r25 = ADD32(ctx->r30, ctx->r2);
    // 0x80094B0C: sw          $t9, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r25;
    // 0x80094B10: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // 0x80094B14: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x80094B18: lw          $a2, 0x90($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X90));
    // 0x80094B1C: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    // 0x80094B20: jal         0x8008FCD8
    // 0x80094B24: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    mulscale14(rdram, ctx);
        goto after_1;
    // 0x80094B24: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_1:
    // 0x80094B28: lw          $t4, 0x134($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80094B2C: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80094B30: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80094B34: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80094B38: sw          $t5, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r13;
    // 0x80094B3C: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x80094B40: sw          $zero, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = 0;
    // 0x80094B44: sh          $s0, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = ctx->r16;
    // 0x80094B48: sh          $t9, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r25;
    // 0x80094B4C: sh          $zero, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = 0;
L_80094B50:
    // 0x80094B50: lh          $t3, 0xC2($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x80094B54: lui         $s4, 0x8028
    ctx->r20 = S32(0X8028 << 16);
    // 0x80094B58: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80094B5C: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x80094B60: addu        $s4, $s4, $t6
    ctx->r20 = ADD32(ctx->r20, ctx->r14);
    // 0x80094B64: lh          $s4, -0x70D0($s4)
    ctx->r20 = S32(MEM_H(ctx->r20, -0X70D0));
    // 0x80094B68: addiu       $t8, $t8, -0x1988
    ctx->r24 = ADD32(ctx->r24, -0X1988);
    // 0x80094B6C: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x80094B70: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80094B74: subu        $t7, $t7, $s4
    ctx->r15 = SUB32(ctx->r15, ctx->r20);
    // 0x80094B78: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80094B7C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80094B80: lh          $s7, 0x8($v1)
    ctx->r23 = S32(MEM_H(ctx->r3, 0X8));
    // 0x80094B84: lh          $t4, 0xA($v1)
    ctx->r12 = S32(MEM_H(ctx->r3, 0XA));
    // 0x80094B88: addiu       $t6, $t6, 0x61A8
    ctx->r14 = ADD32(ctx->r14, 0X61A8);
    // 0x80094B8C: sll         $t3, $s7, 3
    ctx->r11 = S32(ctx->r23 << 3);
    // 0x80094B90: addu        $s3, $t4, $s7
    ctx->r19 = ADD32(ctx->r12, ctx->r23);
    // 0x80094B94: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80094B98: sll         $t5, $s3, 16
    ctx->r13 = S32(ctx->r19 << 16);
    // 0x80094B9C: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80094BA0: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x80094BA4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80094BA8: slt         $at, $s3, $s7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80094BAC: bne         $at, $zero, L_80094E38
    if (ctx->r1 != 0) {
        // 0x80094BB0: addu        $s2, $t3, $t6
        ctx->r18 = ADD32(ctx->r11, ctx->r14);
            goto L_80094E38;
    }
    // 0x80094BB0: addu        $s2, $t3, $t6
    ctx->r18 = ADD32(ctx->r11, ctx->r14);
    // 0x80094BB4: lw          $t7, 0xA0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80094BB8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80094BBC: andi        $t4, $t7, 0x2
    ctx->r12 = ctx->r15 & 0X2;
    // 0x80094BC0: sw          $t4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r12;
    // 0x80094BC4: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
L_80094BC8:
    // 0x80094BC8: lh          $t5, 0x8($s2)
    ctx->r13 = S32(MEM_H(ctx->r18, 0X8));
    // 0x80094BCC: lh          $s1, 0xC($s2)
    ctx->r17 = S32(MEM_H(ctx->r18, 0XC));
    // 0x80094BD0: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80094BD4: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x80094BD8: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80094BDC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80094BE0: addiu       $t3, $t3, 0x61A8
    ctx->r11 = ADD32(ctx->r11, 0X61A8);
    // 0x80094BE4: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x80094BE8: lw          $t1, 0x0($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80094BEC: lw          $t2, 0x4($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80094BF0: lw          $v1, 0x0($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80094BF4: lw          $t0, 0x4($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X4));
    // 0x80094BF8: bltz        $s1, L_80094C60
    if (SIGNED(ctx->r17) < 0) {
        // 0x80094BFC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80094C60;
    }
    // 0x80094BFC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80094C00: lw          $t6, 0x88($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80094C04: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80094C08: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80094C0C: beq         $t6, $zero, L_80094C30
    if (ctx->r14 == 0) {
        // 0x80094C10: lw          $t4, 0x84($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X84));
            goto L_80094C30;
    }
    // 0x80094C10: lw          $t4, 0x84($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X84));
    // 0x80094C14: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80094C18: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80094C1C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80094C20: lh          $t7, -0x1970($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X1970));
    // 0x80094C24: beq         $t7, $zero, L_80094C30
    if (ctx->r15 == 0) {
        // 0x80094C28: nop
    
            goto L_80094C30;
    }
    // 0x80094C28: nop

    // 0x80094C2C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80094C30:
    // 0x80094C30: beq         $t4, $zero, L_80094C60
    if (ctx->r12 == 0) {
        // 0x80094C34: sll         $t5, $s1, 2
        ctx->r13 = S32(ctx->r17 << 2);
            goto L_80094C60;
    }
    // 0x80094C34: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80094C38: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80094C3C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80094C40: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x80094C44: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80094C48: lh          $t9, -0x196E($t9)
    ctx->r25 = S32(MEM_H(ctx->r25, -0X196E));
    // 0x80094C4C: ori         $t3, $s0, 0x1
    ctx->r11 = ctx->r16 | 0X1;
    // 0x80094C50: sll         $t6, $t3, 16
    ctx->r14 = S32(ctx->r11 << 16);
    // 0x80094C54: beql        $t9, $zero, L_80094C64
    if (ctx->r25 == 0) {
        // 0x80094C58: lw          $t7, 0x88($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X88));
            goto L_80094C64;
    }
    goto skip_0;
    // 0x80094C58: lw          $t7, 0x88($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X88));
    skip_0:
    // 0x80094C5C: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
L_80094C60:
    // 0x80094C60: lw          $t7, 0x88($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X88));
L_80094C64:
    // 0x80094C64: lw          $t6, 0x84($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X84));
    // 0x80094C68: lw          $t3, 0x134($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80094C6C: beq         $t7, $zero, L_80094C8C
    if (ctx->r15 == 0) {
        // 0x80094C70: nop
    
            goto L_80094C8C;
    }
    // 0x80094C70: nop

    // 0x80094C74: lh          $t4, 0x14($s2)
    ctx->r12 = S32(MEM_H(ctx->r18, 0X14));
    // 0x80094C78: ori         $t5, $s0, 0x2
    ctx->r13 = ctx->r16 | 0X2;
    // 0x80094C7C: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x80094C80: beq         $t4, $zero, L_80094C8C
    if (ctx->r12 == 0) {
        // 0x80094C84: nop
    
            goto L_80094C8C;
    }
    // 0x80094C84: nop

    // 0x80094C88: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
L_80094C8C:
    // 0x80094C8C: beq         $t6, $zero, L_80094CAC
    if (ctx->r14 == 0) {
        // 0x80094C90: subu        $t9, $v1, $fp
        ctx->r25 = SUB32(ctx->r3, ctx->r30);
            goto L_80094CAC;
    }
    // 0x80094C90: subu        $t9, $v1, $fp
    ctx->r25 = SUB32(ctx->r3, ctx->r30);
    // 0x80094C94: lh          $t8, 0x16($s2)
    ctx->r24 = S32(MEM_H(ctx->r18, 0X16));
    // 0x80094C98: ori         $t7, $s0, 0x2
    ctx->r15 = ctx->r16 | 0X2;
    // 0x80094C9C: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x80094CA0: beq         $t8, $zero, L_80094CAC
    if (ctx->r24 == 0) {
        // 0x80094CA4: nop
    
            goto L_80094CAC;
    }
    // 0x80094CA4: nop

    // 0x80094CA8: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
L_80094CAC:
    // 0x80094CAC: bne         $s0, $zero, L_80094CBC
    if (ctx->r16 != 0) {
        // 0x80094CB0: subu        $t6, $t2, $t3
        ctx->r14 = SUB32(ctx->r10, ctx->r11);
            goto L_80094CBC;
    }
    // 0x80094CB0: subu        $t6, $t2, $t3
    ctx->r14 = SUB32(ctx->r10, ctx->r11);
    // 0x80094CB4: bltzl       $s1, L_80094E2C
    if (SIGNED(ctx->r17) < 0) {
        // 0x80094CB8: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80094E2C;
    }
    goto skip_1;
    // 0x80094CB8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_1:
L_80094CBC:
    // 0x80094CBC: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094CC0: subu        $t7, $t1, $fp
    ctx->r15 = SUB32(ctx->r9, ctx->r30);
    // 0x80094CC4: subu        $t4, $t0, $t3
    ctx->r12 = SUB32(ctx->r8, ctx->r11);
    // 0x80094CC8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80094CCC: addiu       $t3, $sp, 0xF0
    ctx->r11 = ADD32(ctx->r29, 0XF0);
    // 0x80094CD0: lw          $t9, 0x110($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X110));
    // 0x80094CD4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80094CD8: lw          $a2, 0x138($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80094CDC: lw          $a3, 0x114($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80094CE0: mflo        $t8
    ctx->r24 = lo;
    // 0x80094CE4: nop

    // 0x80094CE8: nop

    // 0x80094CEC: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094CF0: addiu       $t4, $sp, 0xE8
    ctx->r12 = ADD32(ctx->r29, 0XE8);
    // 0x80094CF4: addiu       $t7, $sp, 0xEC
    ctx->r15 = ADD32(ctx->r29, 0XEC);
    // 0x80094CF8: mflo        $t5
    ctx->r13 = lo;
    // 0x80094CFC: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80094D00: bnel        $at, $zero, L_80094E2C
    if (ctx->r1 != 0) {
        // 0x80094D04: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80094E2C;
    }
    goto skip_2;
    // 0x80094D04: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_2:
    // 0x80094D08: lw          $t6, 0x10C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X10C));
    // 0x80094D0C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80094D10: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80094D14: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80094D18: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80094D1C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80094D20: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80094D24: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80094D28: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80094D2C: jal         0x8009521C
    // 0x80094D30: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    lintersect(rdram, ctx);
        goto after_2;
    // 0x80094D30: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_2:
    // 0x80094D34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80094D38: bnel        $v0, $at, L_80094E2C
    if (ctx->r2 != ctx->r1) {
        // 0x80094D3C: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80094E2C;
    }
    goto skip_3;
    // 0x80094D3C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_3:
    // 0x80094D40: beq         $s0, $zero, L_80094DCC
    if (ctx->r16 == 0) {
        // 0x80094D44: andi        $t8, $s0, 0x1
        ctx->r24 = ctx->r16 & 0X1;
            goto L_80094DCC;
    }
    // 0x80094D44: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x80094D48: beq         $t8, $zero, L_80094D58
    if (ctx->r24 == 0) {
        // 0x80094D4C: andi        $t9, $s0, 0x2
        ctx->r25 = ctx->r16 & 0X2;
            goto L_80094D58;
    }
    // 0x80094D4C: andi        $t9, $s0, 0x2
    ctx->r25 = ctx->r16 & 0X2;
    // 0x80094D50: lw          $t5, 0x144($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X144));
    // 0x80094D54: sh          $s1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r17;
L_80094D58:
    // 0x80094D58: beq         $t9, $zero, L_80094D64
    if (ctx->r25 == 0) {
        // 0x80094D5C: lw          $t6, 0x148($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X148));
            goto L_80094D64;
    }
    // 0x80094D5C: lw          $t6, 0x148($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X148));
    // 0x80094D60: sh          $s7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r23;
L_80094D64:
    // 0x80094D64: lw          $t3, 0xF0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x80094D68: lw          $t0, 0xEC($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0XEC));
    // 0x80094D6C: lw          $t4, 0x9C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80094D70: lw          $t5, 0x134($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80094D74: subu        $a1, $t3, $fp
    ctx->r5 = SUB32(ctx->r11, ctx->r30);
    // 0x80094D78: lw          $t3, 0x8C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x80094D7C: lh          $a3, 0x0($t4)
    ctx->r7 = S32(MEM_H(ctx->r12, 0X0));
    // 0x80094D80: subu        $t9, $t0, $t5
    ctx->r25 = SUB32(ctx->r8, ctx->r13);
    // 0x80094D84: sra         $t6, $t9, 31
    ctx->r14 = S32(SIGNED(ctx->r25) >> 31);
    // 0x80094D88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80094D8C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80094D90: lh          $t4, 0x0($t3)
    ctx->r12 = S32(MEM_H(ctx->r11, 0X0));
    // 0x80094D94: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80094D98: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80094D9C: sra         $t8, $t4, 31
    ctx->r24 = S32(SIGNED(ctx->r12) >> 31);
    // 0x80094DA0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80094DA4: jal         0x80090794
    // 0x80094DA8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    dmulscale14(rdram, ctx);
        goto after_3;
    // 0x80094DA8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_3:
    // 0x80094DAC: lw          $t5, 0x150($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X150));
    // 0x80094DB0: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x80094DB4: lw          $t3, 0xE8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x80094DB8: lw          $t7, 0xEC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XEC));
    // 0x80094DBC: lw          $t6, 0xF0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x80094DC0: sw          $t3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r11;
    // 0x80094DC4: sw          $t7, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r15;
    // 0x80094DC8: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
L_80094DCC:
    // 0x80094DCC: bltz        $s1, L_80094E28
    if (SIGNED(ctx->r17) < 0) {
        // 0x80094DD0: lh          $v0, 0xC0($sp)
        ctx->r2 = S32(MEM_H(ctx->r29, 0XC0));
            goto L_80094E28;
    }
    // 0x80094DD0: lh          $v0, 0xC0($sp)
    ctx->r2 = S32(MEM_H(ctx->r29, 0XC0));
    // 0x80094DD4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80094DD8: bltz        $v0, L_80094E08
    if (SIGNED(ctx->r2) < 0) {
        // 0x80094DDC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80094E08;
    }
    // 0x80094DDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80094DE0: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x80094DE4: addiu       $t8, $t8, -0x70D0
    ctx->r24 = ADD32(ctx->r24, -0X70D0);
    // 0x80094DE8: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x80094DEC: addu        $v0, $t4, $t8
    ctx->r2 = ADD32(ctx->r12, ctx->r24);
L_80094DF0:
    // 0x80094DF0: lh          $t9, 0x0($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80094DF4: beq         $s1, $t9, L_80094E08
    if (ctx->r17 == ctx->r25) {
        // 0x80094DF8: nop
    
            goto L_80094E08;
    }
    // 0x80094DF8: nop

    // 0x80094DFC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80094E00: bgez        $v1, L_80094DF0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80094E04: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_80094DF0;
    }
    // 0x80094E04: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_80094E08:
    // 0x80094E08: bgez        $v1, L_80094E28
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80094E0C: lh          $t5, 0xC0($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XC0));
            goto L_80094E28;
    }
    // 0x80094E0C: lh          $t5, 0xC0($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XC0));
    // 0x80094E10: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80094E14: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80094E18: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80094E1C: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80094E20: sh          $t7, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r15;
    // 0x80094E24: sh          $s1, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = ctx->r17;
L_80094E28:
    // 0x80094E28: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80094E2C:
    // 0x80094E2C: slt         $at, $s3, $s7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80094E30: beq         $at, $zero, L_80094BC8
    if (ctx->r1 == 0) {
        // 0x80094E34: addiu       $s2, $s2, 0x24
        ctx->r18 = ADD32(ctx->r18, 0X24);
            goto L_80094BC8;
    }
    // 0x80094E34: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
L_80094E38:
    // 0x80094E38: sll         $t3, $s4, 1
    ctx->r11 = S32(ctx->r20 << 1);
    // 0x80094E3C: lui         $s7, 0x8027
    ctx->r23 = S32(0X8027 << 16);
    // 0x80094E40: addu        $s7, $s7, $t3
    ctx->r23 = ADD32(ctx->r23, ctx->r11);
    // 0x80094E44: lh          $s7, 0x2330($s7)
    ctx->r23 = S32(MEM_H(ctx->r23, 0X2330));
    // 0x80094E48: lw          $t4, 0xA0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XA0));
    // 0x80094E4C: addiu       $v1, $zero, 0x2C
    ctx->r3 = ADD32(0, 0X2C);
    // 0x80094E50: bltz        $s7, L_800951C8
    if (SIGNED(ctx->r23) < 0) {
        // 0x80094E54: andi        $t8, $t4, 0x1
        ctx->r24 = ctx->r12 & 0X1;
            goto L_800951C8;
    }
    // 0x80094E54: andi        $t8, $t4, 0x1
    ctx->r24 = ctx->r12 & 0X1;
    // 0x80094E58: andi        $t9, $t4, 0x2
    ctx->r25 = ctx->r12 & 0X2;
    // 0x80094E5C: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x80094E60: addiu       $v0, $v0, 0x6BA8
    ctx->r2 = ADD32(ctx->r2, 0X6BA8);
    // 0x80094E64: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x80094E68: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
L_80094E6C:
    // 0x80094E6C: lw          $t6, 0x88($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80094E70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80094E74: lw          $t8, 0x84($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X84));
    // 0x80094E78: beq         $t6, $zero, L_80094E9C
    if (ctx->r14 == 0) {
        // 0x80094E7C: nop
    
            goto L_80094E9C;
    }
    // 0x80094E7C: nop

    // 0x80094E80: multu       $s7, $v1
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094E84: mflo        $t5
    ctx->r13 = lo;
    // 0x80094E88: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x80094E8C: lh          $t3, 0x1E($t7)
    ctx->r11 = S32(MEM_H(ctx->r15, 0X1E));
    // 0x80094E90: beq         $t3, $zero, L_80094E9C
    if (ctx->r11 == 0) {
        // 0x80094E94: nop
    
            goto L_80094E9C;
    }
    // 0x80094E94: nop

    // 0x80094E98: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80094E9C:
    // 0x80094E9C: beq         $t8, $zero, L_80094EC8
    if (ctx->r24 == 0) {
        // 0x80094EA0: nop
    
            goto L_80094EC8;
    }
    // 0x80094EA0: nop

    // 0x80094EA4: multu       $s7, $v1
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094EA8: ori         $t5, $s0, 0x1
    ctx->r13 = ctx->r16 | 0X1;
    // 0x80094EAC: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x80094EB0: mflo        $t4
    ctx->r12 = lo;
    // 0x80094EB4: addu        $t9, $v0, $t4
    ctx->r25 = ADD32(ctx->r2, ctx->r12);
    // 0x80094EB8: lh          $t6, 0x20($t9)
    ctx->r14 = S32(MEM_H(ctx->r25, 0X20));
    // 0x80094EBC: beq         $t6, $zero, L_80094EC8
    if (ctx->r14 == 0) {
        // 0x80094EC0: nop
    
            goto L_80094EC8;
    }
    // 0x80094EC0: nop

    // 0x80094EC4: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
L_80094EC8:
    // 0x80094EC8: beq         $s0, $zero, L_800951A8
    if (ctx->r16 == 0) {
        // 0x80094ECC: sll         $t8, $s7, 2
        ctx->r24 = S32(ctx->r23 << 2);
            goto L_800951A8;
    }
    // 0x80094ECC: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80094ED0: subu        $t8, $t8, $s7
    ctx->r24 = SUB32(ctx->r24, ctx->r23);
    // 0x80094ED4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80094ED8: subu        $t8, $t8, $s7
    ctx->r24 = SUB32(ctx->r24, ctx->r23);
    // 0x80094EDC: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x80094EE0: addiu       $t4, $t4, 0x6BA8
    ctx->r12 = ADD32(ctx->r12, 0X6BA8);
    // 0x80094EE4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80094EE8: addu        $s1, $t8, $t4
    ctx->r17 = ADD32(ctx->r24, ctx->r12);
    // 0x80094EEC: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80094EF0: lw          $t6, 0xCC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80094EF4: lw          $t0, 0x4($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X4));
    // 0x80094EF8: subu        $s4, $v1, $fp
    ctx->r20 = SUB32(ctx->r3, ctx->r30);
    // 0x80094EFC: multu       $s4, $t6
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094F00: lw          $t9, 0x134($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80094F04: lw          $t7, 0xC8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80094F08: lw          $s2, 0x8($s1)
    ctx->r18 = S32(MEM_W(ctx->r17, 0X8));
    // 0x80094F0C: subu        $s6, $t0, $t9
    ctx->r22 = SUB32(ctx->r8, ctx->r25);
    // 0x80094F10: mflo        $t5
    ctx->r13 = lo;
    // 0x80094F14: nop

    // 0x80094F18: nop

    // 0x80094F1C: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094F20: mflo        $t3
    ctx->r11 = lo;
    // 0x80094F24: addu        $s5, $t5, $t3
    ctx->r21 = ADD32(ctx->r13, ctx->r11);
    // 0x80094F28: blezl       $s5, L_800951AC
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80094F2C: sll         $t8, $s7, 1
        ctx->r24 = S32(ctx->r23 << 1);
            goto L_800951AC;
    }
    goto skip_4;
    // 0x80094F2C: sll         $t8, $s7, 1
    ctx->r24 = S32(ctx->r23 << 1);
    skip_4:
    // 0x80094F30: multu       $t6, $t6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80094F38: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80094F3C: mflo        $t8
    ctx->r24 = lo;
    // 0x80094F40: nop

    // 0x80094F44: nop

    // 0x80094F48: multu       $t7, $t7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094F4C: mflo        $t4
    ctx->r12 = lo;
    // 0x80094F50: addu        $s3, $t8, $t4
    ctx->r19 = ADD32(ctx->r24, ctx->r12);
    // 0x80094F54: beql        $s3, $zero, L_800951AC
    if (ctx->r19 == 0) {
        // 0x80094F58: sll         $t8, $s7, 1
        ctx->r24 = S32(ctx->r23 << 1);
            goto L_800951AC;
    }
    goto skip_5;
    // 0x80094F58: sll         $t8, $s7, 1
    ctx->r24 = S32(ctx->r23 << 1);
    skip_5:
    // 0x80094F5C: jal         0x800919B0
    // 0x80094F60: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    scale(rdram, ctx);
        goto after_4;
    // 0x80094F60: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x80094F64: lw          $t9, 0x138($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80094F68: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x80094F6C: sw          $t5, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r13;
    // 0x80094F70: jal         0x800B4EA8
    // 0x80094F74: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    gettilesizy(rdram, ctx);
        goto after_5;
    // 0x80094F74: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_5:
    // 0x80094F78: lbu         $t3, 0x28($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X28);
    // 0x80094F7C: lh          $t7, 0xC($s1)
    ctx->r15 = S32(MEM_H(ctx->r17, 0XC));
    // 0x80094F80: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094F84: andi        $t6, $t7, 0x80
    ctx->r14 = ctx->r15 & 0X80;
    // 0x80094F88: mflo        $s0
    ctx->r16 = lo;
    // 0x80094F8C: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x80094F90: beq         $t6, $zero, L_80094F9C
    if (ctx->r14 == 0) {
        // 0x80094F94: nop
    
            goto L_80094F9C;
    }
    // 0x80094F94: nop

    // 0x80094F98: addu        $s2, $s2, $t8
    ctx->r18 = ADD32(ctx->r18, ctx->r24);
L_80094F9C:
    // 0x80094F9C: jal         0x800B4F00
    // 0x80094FA0: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    getpicanm(rdram, ctx);
        goto after_6;
    // 0x80094FA0: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_6:
    // 0x80094FA4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80094FA8: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x80094FAC: beql        $t4, $zero, L_80094FE0
    if (ctx->r12 == 0) {
        // 0x80094FB0: lw          $v0, 0xE8($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0XE8));
            goto L_80094FE0;
    }
    goto skip_6;
    // 0x80094FB0: lw          $v0, 0xE8($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XE8));
    skip_6:
    // 0x80094FB4: jal         0x800B4F00
    // 0x80094FB8: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    getpicanm(rdram, ctx);
        goto after_7;
    // 0x80094FB8: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    after_7:
    // 0x80094FBC: lbu         $t6, 0x28($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X28);
    // 0x80094FC0: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80094FC4: sll         $t3, $t5, 24
    ctx->r11 = S32(ctx->r13 << 24);
    // 0x80094FC8: sra         $t7, $t3, 24
    ctx->r15 = S32(SIGNED(ctx->r11) >> 24);
    // 0x80094FCC: multu       $t7, $t6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094FD0: mflo        $t8
    ctx->r24 = lo;
    // 0x80094FD4: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x80094FD8: subu        $s2, $s2, $t4
    ctx->r18 = SUB32(ctx->r18, ctx->r12);
    // 0x80094FDC: lw          $v0, 0xE8($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XE8));
L_80094FE0:
    // 0x80094FE0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80094FE4: subu        $t5, $s2, $t9
    ctx->r13 = SUB32(ctx->r18, ctx->r25);
    // 0x80094FE8: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80094FEC: bne         $at, $zero, L_800951A8
    if (ctx->r1 != 0) {
        // 0x80094FF0: slt         $at, $v0, $t5
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
            goto L_800951A8;
    }
    // 0x80094FF0: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80094FF4: bne         $at, $zero, L_800951A8
    if (ctx->r1 != 0) {
        // 0x80094FF8: lw          $a0, 0xCC($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0XCC));
            goto L_800951A8;
    }
    // 0x80094FF8: lw          $a0, 0xCC($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80094FFC: multu       $s6, $a0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095000: lw          $t7, 0xC8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80095004: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80095008: mflo        $t3
    ctx->r11 = lo;
    // 0x8009500C: nop

    // 0x80095010: nop

    // 0x80095014: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095018: mflo        $t6
    ctx->r14 = lo;
    // 0x8009501C: subu        $s0, $t3, $t6
    ctx->r16 = SUB32(ctx->r11, ctx->r14);
    // 0x80095020: jal         0x800919B0
    // 0x80095024: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    scale(rdram, ctx);
        goto after_8;
    // 0x80095024: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80095028: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8009502C: lw          $a0, 0xC8($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x80095030: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80095034: jal         0x800919B0
    // 0x80095038: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    scale(rdram, ctx);
        goto after_9;
    // 0x80095038: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_9:
    // 0x8009503C: multu       $s2, $s2
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095040: lhu         $a0, 0xE($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XE);
    // 0x80095044: mflo        $t8
    ctx->r24 = lo;
    // 0x80095048: nop

    // 0x8009504C: nop

    // 0x80095050: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095054: mflo        $t4
    ctx->r12 = lo;
    // 0x80095058: addu        $s4, $t8, $t4
    ctx->r20 = ADD32(ctx->r24, ctx->r12);
    // 0x8009505C: jal         0x800B4E50
    // 0x80095060: nop

    gettilesizx(rdram, ctx);
        goto after_10;
    // 0x80095060: nop

    after_10:
    // 0x80095064: lbu         $t9, 0x27($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X27);
    // 0x80095068: lw          $t3, 0x110($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X110));
    // 0x8009506C: lw          $t6, 0x134($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80095070: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095074: lw          $a0, 0xCC($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XCC));
    // 0x80095078: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8009507C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80095080: lw          $t7, 0x114($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X114));
    // 0x80095084: subu        $s1, $t3, $t6
    ctx->r17 = SUB32(ctx->r11, ctx->r14);
    // 0x80095088: mflo        $s0
    ctx->r16 = lo;
    // 0x8009508C: nop

    // 0x80095090: nop

    // 0x80095094: multu       $s0, $s0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095098: mflo        $s0
    ctx->r16 = lo;
    // 0x8009509C: sra         $t5, $s0, 7
    ctx->r13 = S32(SIGNED(ctx->r16) >> 7);
    // 0x800950A0: slt         $at, $t5, $s4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800950A4: bnel        $at, $zero, L_800951AC
    if (ctx->r1 != 0) {
        // 0x800950A8: sll         $t8, $s7, 1
        ctx->r24 = S32(ctx->r23 << 1);
            goto L_800951AC;
    }
    goto skip_7;
    // 0x800950A8: sll         $t8, $s7, 1
    ctx->r24 = S32(ctx->r23 << 1);
    skip_7:
    // 0x800950AC: jal         0x800919B0
    // 0x800950B0: subu        $s0, $t7, $fp
    ctx->r16 = SUB32(ctx->r15, ctx->r30);
    scale(rdram, ctx);
        goto after_11;
    // 0x800950B0: subu        $s0, $t7, $fp
    ctx->r16 = SUB32(ctx->r15, ctx->r30);
    after_11:
    // 0x800950B4: addu        $t8, $v0, $fp
    ctx->r24 = ADD32(ctx->r2, ctx->r30);
    // 0x800950B8: sw          $t8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r24;
    // 0x800950BC: lw          $a0, 0xC8($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0XC8));
    // 0x800950C0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800950C4: jal         0x800919B0
    // 0x800950C8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    scale(rdram, ctx);
        goto after_12;
    // 0x800950C8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_12:
    // 0x800950CC: lw          $a0, 0x134($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X134));
    // 0x800950D0: lw          $t4, 0xF0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x800950D4: lw          $t7, 0x14C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X14C));
    // 0x800950D8: addu        $t0, $v0, $a0
    ctx->r8 = ADD32(ctx->r2, ctx->r4);
    // 0x800950DC: subu        $v1, $t0, $a0
    ctx->r3 = SUB32(ctx->r8, ctx->r4);
    // 0x800950E0: blez        $v1, L_800950F0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800950E4: sw          $t0, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r8;
            goto L_800950F0;
    }
    // 0x800950E4: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    // 0x800950E8: b           L_800950F4
    // 0x800950EC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_800950F4;
    // 0x800950EC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800950F0:
    // 0x800950F0: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
L_800950F4:
    // 0x800950F4: subu        $v0, $t4, $fp
    ctx->r2 = SUB32(ctx->r12, ctx->r30);
    // 0x800950F8: blez        $v0, L_80095108
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800950FC: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_80095108;
    }
    // 0x800950FC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80095100: b           L_80095108
    // 0x80095104: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80095108;
    // 0x80095104: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80095108:
    // 0x80095108: blez        $s0, L_80095118
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8009510C: addu        $t9, $v1, $a1
        ctx->r25 = ADD32(ctx->r3, ctx->r5);
            goto L_80095118;
    }
    // 0x8009510C: addu        $t9, $v1, $a1
    ctx->r25 = ADD32(ctx->r3, ctx->r5);
    // 0x80095110: b           L_8009511C
    // 0x80095114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8009511C;
    // 0x80095114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80095118:
    // 0x80095118: negu        $a0, $s0
    ctx->r4 = SUB32(0, ctx->r16);
L_8009511C:
    // 0x8009511C: blez        $s1, L_8009512C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80095120: negu        $v0, $s1
        ctx->r2 = SUB32(0, ctx->r17);
            goto L_8009512C;
    }
    // 0x80095120: negu        $v0, $s1
    ctx->r2 = SUB32(0, ctx->r17);
    // 0x80095124: b           L_8009512C
    // 0x80095128: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8009512C;
    // 0x80095128: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8009512C:
    // 0x8009512C: addu        $t5, $v0, $a0
    ctx->r13 = ADD32(ctx->r2, ctx->r4);
    // 0x80095130: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80095134: beql        $at, $zero, L_800951AC
    if (ctx->r1 == 0) {
        // 0x80095138: sll         $t8, $s7, 1
        ctx->r24 = S32(ctx->r23 << 1);
            goto L_800951AC;
    }
    goto skip_8;
    // 0x80095138: sll         $t8, $s7, 1
    ctx->r24 = S32(ctx->r23 << 1);
    skip_8:
    // 0x8009513C: sh          $s7, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r23;
    // 0x80095140: lw          $t3, 0xF0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x80095144: lw          $t5, 0x134($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80095148: lw          $t9, 0xEC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XEC));
    // 0x8009514C: lw          $t8, 0x9C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80095150: subu        $a1, $t3, $fp
    ctx->r5 = SUB32(ctx->r11, ctx->r30);
    // 0x80095154: lw          $t3, 0x8C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x80095158: lh          $a3, 0x0($t8)
    ctx->r7 = S32(MEM_H(ctx->r24, 0X0));
    // 0x8009515C: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x80095160: sra         $t6, $t7, 31
    ctx->r14 = S32(SIGNED(ctx->r15) >> 31);
    // 0x80095164: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80095168: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009516C: lh          $t8, 0x0($t3)
    ctx->r24 = S32(MEM_H(ctx->r11, 0X0));
    // 0x80095170: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80095174: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80095178: sra         $t4, $t8, 31
    ctx->r12 = S32(SIGNED(ctx->r24) >> 31);
    // 0x8009517C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80095180: jal         0x80090794
    // 0x80095184: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    dmulscale14(rdram, ctx);
        goto after_13;
    // 0x80095184: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_13:
    // 0x80095188: lw          $t9, 0x150($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X150));
    // 0x8009518C: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80095190: lw          $t6, 0xF0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x80095194: lw          $t7, 0xEC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0XEC));
    // 0x80095198: lw          $t3, 0xE8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0XE8));
    // 0x8009519C: sw          $t6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r14;
    // 0x800951A0: sw          $t7, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r15;
    // 0x800951A4: sw          $t3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r11;
L_800951A8:
    // 0x800951A8: sll         $t8, $s7, 1
    ctx->r24 = S32(ctx->r23 << 1);
L_800951AC:
    // 0x800951AC: lui         $s7, 0x8027
    ctx->r23 = S32(0X8027 << 16);
    // 0x800951B0: addu        $s7, $s7, $t8
    ctx->r23 = ADD32(ctx->r23, ctx->r24);
    // 0x800951B4: lh          $s7, 0x4FA0($s7)
    ctx->r23 = S32(MEM_H(ctx->r23, 0X4FA0));
    // 0x800951B8: lui         $v0, 0x8024
    ctx->r2 = S32(0X8024 << 16);
    // 0x800951BC: addiu       $v0, $v0, 0x6BA8
    ctx->r2 = ADD32(ctx->r2, 0X6BA8);
    // 0x800951C0: bgez        $s7, L_80094E6C
    if (SIGNED(ctx->r23) >= 0) {
        // 0x800951C4: addiu       $v1, $zero, 0x2C
        ctx->r3 = ADD32(0, 0X2C);
            goto L_80094E6C;
    }
    // 0x800951C4: addiu       $v1, $zero, 0x2C
    ctx->r3 = ADD32(0, 0X2C);
L_800951C8:
    // 0x800951C8: lh          $t4, 0xC2($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x800951CC: lh          $t7, 0xC0($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XC0));
    // 0x800951D0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800951D4: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x800951D8: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800951DC: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800951E0: bne         $at, $zero, L_80094B50
    if (ctx->r1 != 0) {
        // 0x800951E4: sh          $t5, 0xC2($sp)
        MEM_H(0XC2, ctx->r29) = ctx->r13;
            goto L_80094B50;
    }
    // 0x800951E4: sh          $t5, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r13;
    // 0x800951E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800951EC:
    // 0x800951EC: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800951F0: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800951F4: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800951F8: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800951FC: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80095200: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80095204: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80095208: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x8009520C: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x80095210: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80095214: jr          $ra
    // 0x80095218: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x80095218: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void _memcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A464: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8005A468: beq         $a2, $zero, L_8005A488
    if (ctx->r6 == 0) {
        // 0x8005A46C: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8005A488;
    }
    // 0x8005A46C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8005A470:
    // 0x8005A470: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8005A474: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8005A478: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005A47C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005A480: bne         $a2, $zero, L_8005A470
    if (ctx->r6 != 0) {
        // 0x8005A484: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_8005A470;
    }
    // 0x8005A484: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_8005A488:
    // 0x8005A488: jr          $ra
    // 0x8005A48C: nop

    return;
    // 0x8005A48C: nop

;}
RECOMP_FUNC void __setInstChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA530: lw          $t6, 0x60($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA534: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x800CA538: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800CA53C: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x800CA540: lw          $t9, 0x60($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA544: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x800CA548: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800CA54C: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x800CA550: lw          $t2, 0x60($a0)
    ctx->r10 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA554: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x800CA558: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800CA55C: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x800CA560: lw          $t5, 0x60($a0)
    ctx->r13 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA564: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800CA568: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800CA56C: sb          $t4, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r12;
    // 0x800CA570: lw          $t9, 0x60($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X60));
    // 0x800CA574: lh          $t7, 0xC($a1)
    ctx->r15 = S32(MEM_H(ctx->r5, 0XC));
    // 0x800CA578: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800CA57C: jr          $ra
    // 0x800CA580: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x800CA580: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void func_80051A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051A20: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80051A24: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80051A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051A2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80051A30: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80051A34: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x80051A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80051A40: addiu       $t8, $t8, -0x48D8
    ctx->r24 = ADD32(ctx->r24, -0X48D8);
    // 0x80051A44: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80051A48: jal         0x800BD3C8
    // 0x80051A4C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    osMotorStart_recomp(rdram, ctx);
        goto after_0;
    // 0x80051A4C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80051A50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80051A54: beq         $v0, $at, L_80051A70
    if (ctx->r2 == ctx->r1) {
        // 0x80051A58: lw          $t0, 0x18($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0X18));
            goto L_80051A70;
    }
    // 0x80051A58: lw          $t0, 0x18($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80051A5C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80051A60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A64: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80051A68: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80051A6C: sb          $t9, -0x4707($at)
    MEM_B(-0X4707, ctx->r1) = ctx->r25;
L_80051A70:
    // 0x80051A70: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80051A74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051A78: jr          $ra
    // 0x80051A7C: nop

    return;
    // 0x80051A7C: nop

;}
RECOMP_FUNC void cacheandtileinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006484C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064850: lui         $a0, 0x802C
    ctx->r4 = S32(0X802C << 16);
    // 0x80064854: lui         $a1, 0x11
    ctx->r5 = S32(0X11 << 16);
    // 0x80064858: ori         $a1, $a1, 0x5800
    ctx->r5 = ctx->r5 | 0X5800;
    // 0x8006485C: jal         0x800717F0
    // 0x80064860: ori         $a0, $a0, 0x5000
    ctx->r4 = ctx->r4 | 0X5000;
    initcache(rdram, ctx);
        goto after_0;
    // 0x80064860: ori         $a0, $a0, 0x5000
    ctx->r4 = ctx->r4 | 0X5000;
    after_0:
    // 0x80064864: jal         0x800637C8
    // 0x80064868: nop

    func_800637C8(rdram, ctx);
        goto after_1;
    // 0x80064868: nop

    after_1:
    // 0x8006486C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80064870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064874: jr          $ra
    // 0x80064878: nop

    return;
    // 0x80064878: nop

;}
RECOMP_FUNC void func_80062304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062304: jr          $ra
    // 0x80062308: nop

    return;
    // 0x80062308: nop

;}
RECOMP_FUNC void RNCDecompress2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007070C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80070710: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80070714: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80070718: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007071C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80070720: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80070724: jal         0x800706B8
    // 0x80070728: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800706B8(rdram, ctx);
        goto after_0;
    // 0x80070728: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8007072C: jal         0x800700F0
    // 0x80070730: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800700F0(rdram, ctx);
        goto after_1;
    // 0x80070730: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80070734: lui         $s1, 0x8027
    ctx->r17 = S32(0X8027 << 16);
    // 0x80070738: addiu       $s1, $s1, -0x1338
    ctx->r17 = ADD32(ctx->r17, -0X1338);
    // 0x8007073C: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x80070740: lw          $t7, -0x1334($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X1334));
    // 0x80070744: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070748: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
    // 0x8007074C: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x80070750: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x80070754: beq         $at, $zero, L_80070978
    if (ctx->r1 == 0) {
        // 0x80070758: lui         $s2, 0x8027
        ctx->r18 = S32(0X8027 << 16);
            goto L_80070978;
    }
    // 0x80070758: lui         $s2, 0x8027
    ctx->r18 = S32(0X8027 << 16);
    // 0x8007075C: addiu       $s2, $s2, -0x133C
    ctx->r18 = ADD32(ctx->r18, -0X133C);
L_80070760:
    // 0x80070760: jal         0x800700F0
    // 0x80070764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_2;
    // 0x80070764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80070768: bne         $v0, $zero, L_800707A8
    if (ctx->r2 != 0) {
        // 0x8007076C: nop
    
            goto L_800707A8;
    }
    // 0x8007076C: nop

    // 0x80070770: lw          $t8, 0x0($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X0));
L_80070774:
    // 0x80070774: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070778: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007077C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80070780: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x80070784: lw          $t3, 0x0($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80070788: lw          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007078C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80070790: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80070794: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80070798: jal         0x800700F0
    // 0x8007079C: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    func_800700F0(rdram, ctx);
        goto after_3;
    // 0x8007079C: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    after_3:
    // 0x800707A0: beql        $v0, $zero, L_80070774
    if (ctx->r2 == 0) {
        // 0x800707A4: lw          $t8, 0x0($s2)
        ctx->r24 = S32(MEM_W(ctx->r18, 0X0));
            goto L_80070774;
    }
    goto skip_0;
    // 0x800707A4: lw          $t8, 0x0($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X0));
    skip_0:
L_800707A8:
    // 0x800707A8: jal         0x800700F0
    // 0x800707AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_4;
    // 0x800707AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800707B0: beq         $v0, $zero, L_80070884
    if (ctx->r2 == 0) {
        // 0x800707B4: nop
    
            goto L_80070884;
    }
    // 0x800707B4: nop

    // 0x800707B8: jal         0x800700F0
    // 0x800707BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_5;
    // 0x800707BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800707C0: bne         $v0, $zero, L_800707EC
    if (ctx->r2 != 0) {
        // 0x800707C4: nop
    
            goto L_800707EC;
    }
    // 0x800707C4: nop

    // 0x800707C8: lw          $v0, 0x0($s2)
    ctx->r2 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800707CC: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800707D0: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800707D4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800707D8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800707DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800707E0: andi        $t5, $a1, 0xFFFF
    ctx->r13 = ctx->r5 & 0XFFFF;
    // 0x800707E4: b           L_80070830
    // 0x800707E8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80070830;
    // 0x800707E8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_800707EC:
    // 0x800707EC: jal         0x800700F0
    // 0x800707F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_6;
    // 0x800707F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800707F4: bnel        $v0, $zero, L_80070808
    if (ctx->r2 != 0) {
        // 0x800707F8: lw          $v0, 0x0($s2)
        ctx->r2 = S32(MEM_W(ctx->r18, 0X0));
            goto L_80070808;
    }
    goto skip_1;
    // 0x800707F8: lw          $v0, 0x0($s2)
    ctx->r2 = S32(MEM_W(ctx->r18, 0X0));
    skip_1:
    // 0x800707FC: b           L_80070824
    // 0x80070800: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80070824;
    // 0x80070800: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80070804: lw          $v0, 0x0($s2)
    ctx->r2 = S32(MEM_W(ctx->r18, 0X0));
L_80070808:
    // 0x80070808: lbu         $s0, 0x0($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X0);
    // 0x8007080C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80070810: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80070814: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80070818: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x8007081C: beq         $s3, $t7, L_80070958
    if (ctx->r19 == ctx->r15) {
        // 0x80070820: or          $s0, $t7, $zero
        ctx->r16 = ctx->r15 | 0;
            goto L_80070958;
    }
    // 0x80070820: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_80070824:
    // 0x80070824: jal         0x800701A0
    // 0x80070828: nop

    func_800701A0(rdram, ctx);
        goto after_7;
    // 0x80070828: nop

    after_7:
    // 0x8007082C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
L_80070830:
    // 0x80070830: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80070834: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070838: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8007083C: andi        $t0, $s0, 0xFFFF
    ctx->r8 = ctx->r16 & 0XFFFF;
    // 0x80070840: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80070844: beq         $v1, $zero, L_80070760
    if (ctx->r3 == 0) {
        // 0x80070848: subu        $a0, $t9, $a1
        ctx->r4 = SUB32(ctx->r25, ctx->r5);
            goto L_80070760;
    }
    // 0x80070848: subu        $a0, $t9, $a1
    ctx->r4 = SUB32(ctx->r25, ctx->r5);
L_8007084C:
    // 0x8007084C: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x80070850: lw          $t2, 0x0($s1)
    ctx->r10 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070854: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80070858: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8007085C: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x80070860: lw          $t3, 0x0($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070864: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x80070868: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8007086C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80070870: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80070874: bne         $v1, $zero, L_8007084C
    if (ctx->r3 != 0) {
        // 0x80070878: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8007084C;
    }
    // 0x80070878: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007087C: b           L_80070760
    // 0x80070880: nop

        goto L_80070760;
    // 0x80070880: nop

L_80070884:
    // 0x80070884: jal         0x80070274
    // 0x80070888: nop

    func_80070274(rdram, ctx);
        goto after_8;
    // 0x80070888: nop

    after_8:
    // 0x8007088C: bne         $s4, $v0, L_800708FC
    if (ctx->r20 != ctx->r2) {
        // 0x80070890: andi        $s0, $v0, 0xFFFF
        ctx->r16 = ctx->r2 & 0XFFFF;
            goto L_800708FC;
    }
    // 0x80070890: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80070894: jal         0x800700F0
    // 0x80070898: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800700F0(rdram, ctx);
        goto after_9;
    // 0x80070898: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x8007089C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800708A0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800708A4: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800708A8: addiu       $s0, $t6, -0x1
    ctx->r16 = ADD32(ctx->r14, -0X1);
    // 0x800708AC: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x800708B0: beq         $t6, $zero, L_80070760
    if (ctx->r14 == 0) {
        // 0x800708B4: or          $s0, $t7, $zero
        ctx->r16 = ctx->r15 | 0;
            goto L_80070760;
    }
    // 0x800708B4: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_800708B8:
    // 0x800708B8: lw          $t8, 0x0($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800708BC: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800708C0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800708C4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800708C8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800708CC: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x800708D0: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x800708D4: lw          $t3, 0x0($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X0));
    // 0x800708D8: lw          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800708DC: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x800708E0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800708E4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800708E8: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800708EC: bne         $v1, $zero, L_800708B8
    if (ctx->r3 != 0) {
        // 0x800708F0: sw          $t4, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r12;
            goto L_800708B8;
    }
    // 0x800708F0: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800708F4: b           L_80070760
    // 0x800708F8: nop

        goto L_80070760;
    // 0x800708F8: nop

L_800708FC:
    // 0x800708FC: jal         0x800701A0
    // 0x80070900: nop

    func_800701A0(rdram, ctx);
        goto after_10;
    // 0x80070900: nop

    after_10:
    // 0x80070904: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80070908: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007090C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80070910: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x80070914: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80070918: beq         $v1, $zero, L_80070760
    if (ctx->r3 == 0) {
        // 0x8007091C: subu        $a0, $t6, $v0
        ctx->r4 = SUB32(ctx->r14, ctx->r2);
            goto L_80070760;
    }
    // 0x8007091C: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
L_80070920:
    // 0x80070920: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80070924: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070928: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007092C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80070930: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80070934: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070938: andi        $t2, $s0, 0xFFFF
    ctx->r10 = ctx->r16 & 0XFFFF;
    // 0x8007093C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80070940: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80070944: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80070948: bne         $v1, $zero, L_80070920
    if (ctx->r3 != 0) {
        // 0x8007094C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80070920;
    }
    // 0x8007094C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80070950: b           L_80070760
    // 0x80070954: nop

        goto L_80070760;
    // 0x80070954: nop

L_80070958:
    // 0x80070958: jal         0x800700F0
    // 0x8007095C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800700F0(rdram, ctx);
        goto after_11;
    // 0x8007095C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80070960: lui         $t4, 0x8027
    ctx->r12 = S32(0X8027 << 16);
    // 0x80070964: lw          $t4, -0x1334($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X1334));
    // 0x80070968: lw          $t3, 0x0($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007096C: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x80070970: bne         $at, $zero, L_80070760
    if (ctx->r1 != 0) {
        // 0x80070974: nop
    
            goto L_80070760;
    }
    // 0x80070974: nop

L_80070978:
    // 0x80070978: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8007097C: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80070980: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80070984: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80070988: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8007098C: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80070990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80070994: jr          $ra
    // 0x80070998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80070998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void RNCDecompress1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007099C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800709A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800709A4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800709A8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800709AC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800709B0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800709B4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800709B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800709BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800709C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800709C4: jal         0x800706B8
    // 0x800709C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800706B8(rdram, ctx);
        goto after_0;
    // 0x800709C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800709CC: jal         0x800702D4
    // 0x800709D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800702D4(rdram, ctx);
        goto after_1;
    // 0x800709D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x800709D4: lui         $s1, 0x8027
    ctx->r17 = S32(0X8027 << 16);
    // 0x800709D8: addiu       $s1, $s1, -0x1338
    ctx->r17 = ADD32(ctx->r17, -0X1338);
    // 0x800709DC: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x800709E0: lw          $t7, -0x1334($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X1334));
    // 0x800709E4: lw          $t6, 0x0($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800709E8: lui         $fp, 0x8027
    ctx->r30 = S32(0X8027 << 16);
    // 0x800709EC: addiu       $fp, $fp, -0x133F
    ctx->r30 = ADD32(ctx->r30, -0X133F);
    // 0x800709F0: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x800709F4: beq         $at, $zero, L_80070B78
    if (ctx->r1 == 0) {
        // 0x800709F8: lui         $s7, 0x8027
        ctx->r23 = S32(0X8027 << 16);
            goto L_80070B78;
    }
    // 0x800709F8: lui         $s7, 0x8027
    ctx->r23 = S32(0X8027 << 16);
    // 0x800709FC: lui         $s6, 0x8027
    ctx->r22 = S32(0X8027 << 16);
    // 0x80070A00: lui         $s5, 0x8027
    ctx->r21 = S32(0X8027 << 16);
    // 0x80070A04: lui         $s4, 0x8027
    ctx->r20 = S32(0X8027 << 16);
    // 0x80070A08: lui         $s2, 0x8027
    ctx->r18 = S32(0X8027 << 16);
    // 0x80070A0C: addiu       $s2, $s2, -0x133C
    ctx->r18 = ADD32(ctx->r18, -0X133C);
    // 0x80070A10: addiu       $s4, $s4, -0x1330
    ctx->r20 = ADD32(ctx->r20, -0X1330);
    // 0x80070A14: addiu       $s5, $s5, -0x1328
    ctx->r21 = ADD32(ctx->r21, -0X1328);
    // 0x80070A18: addiu       $s6, $s6, -0x1228
    ctx->r22 = ADD32(ctx->r22, -0X1228);
    // 0x80070A1C: addiu       $s7, $s7, -0x1128
    ctx->r23 = ADD32(ctx->r23, -0X1128);
    // 0x80070A20: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80070A24:
    // 0x80070A24: jal         0x80070614
    // 0x80070A28: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80070614(rdram, ctx);
        goto after_2;
    // 0x80070A28: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80070A2C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80070A30: jal         0x80070614
    // 0x80070A34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80070614(rdram, ctx);
        goto after_3;
    // 0x80070A34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x80070A38: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80070A3C: jal         0x80070614
    // 0x80070A40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80070614(rdram, ctx);
        goto after_4;
    // 0x80070A40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x80070A44: jal         0x800702D4
    // 0x80070A48: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800702D4(rdram, ctx);
        goto after_5;
    // 0x80070A48: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_5:
    // 0x80070A4C: b           L_80070AB8
    // 0x80070A50: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
        goto L_80070AB8;
    // 0x80070A50: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
L_80070A54:
    // 0x80070A54: jal         0x800703A8
    // 0x80070A58: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800703A8(rdram, ctx);
        goto after_6;
    // 0x80070A58: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_6:
    // 0x80070A5C: lw          $t8, 0x0($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070A60: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80070A64: subu        $s0, $t8, $v0
    ctx->r16 = SUB32(ctx->r24, ctx->r2);
    // 0x80070A68: jal         0x800703A8
    // 0x80070A6C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    func_800703A8(rdram, ctx);
        goto after_7;
    // 0x80070A6C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_7:
    // 0x80070A70: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    // 0x80070A74: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x80070A78: addiu       $v1, $t9, -0x1
    ctx->r3 = ADD32(ctx->r25, -0X1);
    // 0x80070A7C: andi        $t0, $v1, 0xFFFF
    ctx->r8 = ctx->r3 & 0XFFFF;
    // 0x80070A80: beq         $t9, $zero, L_80070AB8
    if (ctx->r25 == 0) {
        // 0x80070A84: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80070AB8;
    }
    // 0x80070A84: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80070A88:
    // 0x80070A88: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80070A8C: lw          $t2, 0x0($s1)
    ctx->r10 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070A90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80070A94: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80070A98: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x80070A9C: lw          $t3, 0x0($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070AA0: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x80070AA4: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80070AA8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80070AAC: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80070AB0: bne         $v0, $zero, L_80070A88
    if (ctx->r2 != 0) {
        // 0x80070AB4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80070A88;
    }
    // 0x80070AB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80070AB8:
    // 0x80070AB8: jal         0x800703A8
    // 0x80070ABC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800703A8(rdram, ctx);
        goto after_8;
    // 0x80070ABC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x80070AC0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80070AC4: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x80070AC8: beq         $v0, $zero, L_80070B0C
    if (ctx->r2 == 0) {
        // 0x80070ACC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80070B0C;
    }
    // 0x80070ACC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80070AD0:
    // 0x80070AD0: lw          $t7, 0x0($s2)
    ctx->r15 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80070AD4: lw          $t9, 0x0($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070AD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80070ADC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80070AE0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80070AE4: andi        $t4, $v1, 0xFFFF
    ctx->r12 = ctx->r3 & 0XFFFF;
    // 0x80070AE8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80070AEC: lw          $t2, 0x0($s2)
    ctx->r10 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80070AF0: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070AF4: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80070AF8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80070AFC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80070B00: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x80070B04: bne         $v0, $zero, L_80070AD0
    if (ctx->r2 != 0) {
        // 0x80070B08: sw          $t3, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r11;
            goto L_80070AD0;
    }
    // 0x80070B08: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
L_80070B0C:
    // 0x80070B0C: lw          $v0, 0x0($s2)
    ctx->r2 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80070B10: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x80070B14: lw          $t3, 0x0($s4)
    ctx->r11 = S32(MEM_W(ctx->r20, 0X0));
    // 0x80070B18: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x80070B1C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80070B20: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x80070B24: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80070B28: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80070B2C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80070B30: sllv        $t6, $t4, $v1
    ctx->r14 = S32(ctx->r12 << (ctx->r3 & 31));
    // 0x80070B34: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80070B38: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80070B3C: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x80070B40: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80070B44: sllv        $t2, $t1, $v1
    ctx->r10 = S32(ctx->r9 << (ctx->r3 & 31));
    // 0x80070B48: and         $t7, $t3, $t5
    ctx->r15 = ctx->r11 & ctx->r13;
    // 0x80070B4C: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x80070B50: andi        $t8, $s3, 0xFFFF
    ctx->r24 = ctx->r19 & 0XFFFF;
    // 0x80070B54: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x80070B58: bne         $t8, $zero, L_80070A54
    if (ctx->r24 != 0) {
        // 0x80070B5C: or          $s3, $t8, $zero
        ctx->r19 = ctx->r24 | 0;
            goto L_80070A54;
    }
    // 0x80070B5C: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x80070B60: lui         $t1, 0x8027
    ctx->r9 = S32(0X8027 << 16);
    // 0x80070B64: lw          $t1, -0x1334($t1)
    ctx->r9 = S32(MEM_W(ctx->r9, -0X1334));
    // 0x80070B68: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x80070B6C: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x80070B70: bnel        $at, $zero, L_80070A24
    if (ctx->r1 != 0) {
        // 0x80070B74: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80070A24;
    }
    goto skip_0;
    // 0x80070B74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
L_80070B78:
    // 0x80070B78: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80070B7C: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80070B80: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80070B84: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80070B88: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80070B8C: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80070B90: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80070B94: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80070B98: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80070B9C: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80070BA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80070BA4: jr          $ra
    // 0x80070BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80070BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80060EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060EAC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80060EB0: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80060EB4: lhu         $t6, 0x8A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X8A);
    // 0x80060EB8: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80060EBC: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x80060EC0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80060EC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80060EC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80060ECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80060ED0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80060ED4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80060ED8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80060EDC: lhu         $a0, 0x12($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X12);
    // 0x80060EE0: jal         0x8006370C
    // 0x80060EE4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    gettileid(rdram, ctx);
        goto after_0;
    // 0x80060EE4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80060EE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80060EEC: beq         $v0, $at, L_80061408
    if (ctx->r2 == ctx->r1) {
        // 0x80060EF0: andi        $s1, $v0, 0xFFFF
        ctx->r17 = ctx->r2 & 0XFFFF;
            goto L_80061408;
    }
    // 0x80060EF0: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80060EF4: lui         $a2, 0x8027
    ctx->r6 = S32(0X8027 << 16);
    // 0x80060EF8: addiu       $a2, $a2, -0x13CF
    ctx->r6 = ADD32(ctx->r6, -0X13CF);
    // 0x80060EFC: lb          $t9, 0x0($a2)
    ctx->r25 = S32(MEM_B(ctx->r6, 0X0));
    // 0x80060F00: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80060F04: addiu       $v0, $v0, -0x13D0
    ctx->r2 = ADD32(ctx->r2, -0X13D0);
    // 0x80060F08: beq         $t9, $zero, L_80060F80
    if (ctx->r25 == 0) {
        // 0x80060F0C: lui         $a1, 0x8022
        ctx->r5 = S32(0X8022 << 16);
            goto L_80060F80;
    }
    // 0x80060F0C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80060F10: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80060F14: addiu       $s0, $s0, 0x4418
    ctx->r16 = ADD32(ctx->r16, 0X4418);
    // 0x80060F18: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80060F1C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80060F20: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x80060F24: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80060F28: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80060F2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80060F30: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80060F34: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80060F38: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80060F3C: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80060F40: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x80060F44: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80060F48: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80060F4C: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80060F50: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80060F54: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80060F58: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80060F5C: lui         $t6, 0xFF33
    ctx->r14 = S32(0XFF33 << 16);
    // 0x80060F60: lui         $t9, 0xFC12
    ctx->r25 = S32(0XFC12 << 16);
    // 0x80060F64: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80060F68: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80060F6C: ori         $t9, $t9, 0x1824
    ctx->r25 = ctx->r25 | 0X1824;
    // 0x80060F70: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80060F74: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80060F78: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80060F7C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_80060F80:
    // 0x80060F80: lb          $t7, 0x0($v0)
    ctx->r15 = S32(MEM_B(ctx->r2, 0X0));
    // 0x80060F84: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80060F88: addiu       $s0, $s0, 0x4418
    ctx->r16 = ADD32(ctx->r16, 0X4418);
    // 0x80060F8C: beq         $t7, $zero, L_80060F98
    if (ctx->r15 == 0) {
        // 0x80060F90: addiu       $a1, $a1, -0x2354
        ctx->r5 = ADD32(ctx->r5, -0X2354);
            goto L_80060F98;
    }
    // 0x80060F90: addiu       $a1, $a1, -0x2354
    ctx->r5 = ADD32(ctx->r5, -0X2354);
    // 0x80060F94: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80060F98:
    // 0x80060F98: lh          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_H(ctx->r5, 0X0));
    // 0x80060F9C: bne         $t8, $zero, L_80060FD8
    if (ctx->r24 != 0) {
        // 0x80060FA0: nop
    
            goto L_80060FD8;
    }
    // 0x80060FA0: nop

    // 0x80060FA4: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80060FA8: lui         $t6, 0x4F0
    ctx->r14 = S32(0X4F0 << 16);
    // 0x80060FAC: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80060FB0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80060FB4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80060FB8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80060FBC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80060FC0: lw          $t7, -0x537C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X537C));
    // 0x80060FC4: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80060FC8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80060FCC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80060FD0: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80060FD4: sh          $zero, -0x2350($at)
    MEM_H(-0X2350, ctx->r1) = 0;
L_80060FD8:
    // 0x80060FD8: jal         0x80069130
    // 0x80060FDC: lhu         $a0, 0x8A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X8A);
    func_80069130(rdram, ctx);
        goto after_1;
    // 0x80060FDC: lhu         $a0, 0x8A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X8A);
    after_1:
    // 0x80060FE0: jal         0x80062680
    // 0x80060FE4: lhu         $a0, 0x8A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X8A);
    func_80062680(rdram, ctx);
        goto after_2;
    // 0x80060FE4: lhu         $a0, 0x8A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X8A);
    after_2:
    // 0x80060FE8: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x80060FEC: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x80060FF0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80060FF4: addiu       $t6, $t6, -0x5010
    ctx->r14 = ADD32(ctx->r14, -0X5010);
    // 0x80060FF8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80060FFC: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
    // 0x80061000: lw          $t7, 0x8($t4)
    ctx->r15 = S32(MEM_W(ctx->r12, 0X8));
    // 0x80061004: lw          $t9, 0x24($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80061008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006100C: andi        $t8, $t7, 0xC0
    ctx->r24 = ctx->r15 & 0XC0;
    // 0x80061010: beql        $t8, $zero, L_80061048
    if (ctx->r24 == 0) {
        // 0x80061014: lw          $v1, 0x0($s0)
        ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
            goto L_80061048;
    }
    goto skip_0;
    // 0x80061014: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    skip_0:
    // 0x80061018: jal         0x8009223C
    // 0x8006101C: lh          $a0, 0x12($t9)
    ctx->r4 = S32(MEM_H(ctx->r25, 0X12));
    animateoffs(rdram, ctx);
        goto after_3;
    // 0x8006101C: lh          $a0, 0x12($t9)
    ctx->r4 = S32(MEM_H(ctx->r25, 0X12));
    after_3:
    // 0x80061020: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80061024: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x80061028: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8006102C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80061030: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80061034: addiu       $t8, $t8, -0x5010
    ctx->r24 = ADD32(ctx->r24, -0X5010);
    // 0x80061038: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006103C: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x80061040: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80061044: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
L_80061048:
    // 0x80061048: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8006104C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80061050: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061054: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80061058: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8006105C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80061060: jal         0x80063880
    // 0x80061064: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    func_80063880(rdram, ctx);
        goto after_4;
    // 0x80061064: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    after_4:
    // 0x80061068: lw          $t2, 0x70($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X70));
    // 0x8006106C: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80061070: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80061074: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x80061078: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006107C: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80061080: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80061084: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80061088: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006108C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80061090: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061094: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061098: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8006109C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800610A0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800610A4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800610A8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800610AC: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800610B0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800610B4: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x800610B8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800610BC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800610C0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800610C4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800610C8: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800610CC: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x800610D0: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x800610D4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800610D8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800610DC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800610E0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800610E4: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800610E8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800610EC: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x800610F0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800610F4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800610F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800610FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061100: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061104: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80061108: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006110C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80061110: jal         0x80063880
    // 0x80061114: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    func_80063880(rdram, ctx);
        goto after_5;
    // 0x80061114: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_5:
    // 0x80061118: lw          $t3, 0x58($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X58));
    // 0x8006111C: addiu       $t9, $v0, 0x20
    ctx->r25 = ADD32(ctx->r2, 0X20);
    // 0x80061120: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x80061124: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x80061128: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x8006112C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80061130: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061134: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80061138: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006113C: jal         0x80063AE0
    // 0x80061140: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    func_80063AE0(rdram, ctx);
        goto after_6;
    // 0x80061140: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_6:
    // 0x80061144: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80061148: jal         0x80063A08
    // 0x8006114C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    func_80063A08(rdram, ctx);
        goto after_7;
    // 0x8006114C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_7:
    // 0x80061150: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x80061154: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x80061158: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8006115C: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x80061160: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x80061164: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80061168: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8006116C: lw          $t8, 0x54($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80061170: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80061174: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80061178: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8006117C: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061180: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80061184: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80061188: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8006118C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80061190: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80061194: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061198: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006119C: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800611A0: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x800611A4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800611A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800611AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800611B0: lhu         $t6, 0x14($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X14);
    // 0x800611B4: lhu         $a1, 0x12($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X12);
    // 0x800611B8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800611BC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800611C0: mflo        $a2
    ctx->r6 = lo;
    // 0x800611C4: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x800611C8: sra         $t9, $a2, 2
    ctx->r25 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800611CC: addiu       $a2, $t9, -0x1
    ctx->r6 = ADD32(ctx->r25, -0X1);
    // 0x800611D0: slti        $at, $a2, 0x7FF
    ctx->r1 = SIGNED(ctx->r6) < 0X7FF ? 1 : 0;
    // 0x800611D4: beq         $at, $zero, L_800611E4
    if (ctx->r1 == 0) {
        // 0x800611D8: nop
    
            goto L_800611E4;
    }
    // 0x800611D8: nop

    // 0x800611DC: b           L_800611E4
    // 0x800611E0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
        goto L_800611E4;
    // 0x800611E0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_800611E4:
    // 0x800611E4: bgez        $a1, L_800611F4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800611E8: sra         $v0, $a1, 4
        ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
            goto L_800611F4;
    }
    // 0x800611E8: sra         $v0, $a1, 4
    ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
    // 0x800611EC: addiu       $at, $a1, 0xF
    ctx->r1 = ADD32(ctx->r5, 0XF);
    // 0x800611F0: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_800611F4:
    // 0x800611F4: bgtz        $v0, L_80061204
    if (SIGNED(ctx->r2) > 0) {
        // 0x800611F8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80061204;
    }
    // 0x800611F8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800611FC: b           L_80061204
    // 0x80061200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80061204;
    // 0x80061200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80061204:
    // 0x80061204: bgtz        $v0, L_80061214
    if (SIGNED(ctx->r2) > 0) {
        // 0x80061208: addiu       $t7, $a2, 0x7FF
        ctx->r15 = ADD32(ctx->r6, 0X7FF);
            goto L_80061214;
    }
    // 0x80061208: addiu       $t7, $a2, 0x7FF
    ctx->r15 = ADD32(ctx->r6, 0X7FF);
    // 0x8006120C: b           L_80061218
    // 0x80061210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80061218;
    // 0x80061210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80061214:
    // 0x80061214: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80061218:
    // 0x80061218: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x8006121C: mflo        $t8
    ctx->r24 = lo;
    // 0x80061220: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80061224: bne         $a1, $zero, L_80061230
    if (ctx->r5 != 0) {
        // 0x80061228: nop
    
            goto L_80061230;
    }
    // 0x80061228: nop

    // 0x8006122C: break       7
    do_break(2147881516);
L_80061230:
    // 0x80061230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80061234: bne         $a1, $at, L_80061248
    if (ctx->r5 != ctx->r1) {
        // 0x80061238: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80061248;
    }
    // 0x80061238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006123C: bne         $t7, $at, L_80061248
    if (ctx->r15 != ctx->r1) {
        // 0x80061240: nop
    
            goto L_80061248;
    }
    // 0x80061240: nop

    // 0x80061244: break       6
    do_break(2147881540);
L_80061248:
    // 0x80061248: andi        $t7, $a3, 0xFFF
    ctx->r15 = ctx->r7 & 0XFFF;
    // 0x8006124C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80061250: or          $t9, $t6, $t2
    ctx->r25 = ctx->r14 | ctx->r10;
    // 0x80061254: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80061258: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8006125C: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061260: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80061264: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x80061268: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006126C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80061270: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80061274: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061278: lhu         $t6, 0x12($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X12);
    // 0x8006127C: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061280: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80061284: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80061288: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8006128C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80061290: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x80061294: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80061298: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x8006129C: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800612A0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800612A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800612A8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800612AC: jal         0x80063AE0
    // 0x800612B0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_80063AE0(rdram, ctx);
        goto after_8;
    // 0x800612B0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_8:
    // 0x800612B4: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x800612B8: jal         0x80063A08
    // 0x800612BC: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    func_80063A08(rdram, ctx);
        goto after_9;
    // 0x800612BC: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_9:
    // 0x800612C0: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x800612C4: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x800612C8: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800612CC: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x800612D0: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x800612D4: lw          $t9, 0x44($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800612D8: lw          $t4, 0x20($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800612DC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800612E0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800612E4: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800612E8: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800612EC: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x800612F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800612F4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800612F8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800612FC: lhu         $t7, 0x14($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X14);
    // 0x80061300: addiu       $t1, $t1, -0x1B34
    ctx->r9 = ADD32(ctx->r9, -0X1B34);
    // 0x80061304: lui         $t2, 0xBF00
    ctx->r10 = S32(0XBF00 << 16);
    // 0x80061308: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8006130C: lhu         $t7, 0x12($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X12);
    // 0x80061310: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80061314: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80061318: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8006131C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80061320: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80061324: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80061328: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8006132C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80061330: lw          $t7, 0x0($t1)
    ctx->r15 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80061334: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061338: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x8006133C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80061340: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061344: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80061348: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8006134C: addiu       $t5, $t5, -0x2350
    ctx->r13 = ADD32(ctx->r13, -0X2350);
    // 0x80061350: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80061354: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x80061358: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8006135C: lui         $ra, 0x8022
    ctx->r31 = S32(0X8022 << 16);
    // 0x80061360: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061364: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80061368: addiu       $ra, $ra, -0x2354
    ctx->r31 = ADD32(ctx->r31, -0X2354);
    // 0x8006136C: lui         $at, 0x8027
    ctx->r1 = S32(0X8027 << 16);
    // 0x80061370: mflo        $a0
    ctx->r4 = lo;
    // 0x80061374: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80061378: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8006137C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80061380: addiu       $t8, $a0, 0xA
    ctx->r24 = ADD32(ctx->r4, 0XA);
    // 0x80061384: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x80061388: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8006138C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80061390: addiu       $t7, $a0, 0x14
    ctx->r15 = ADD32(ctx->r4, 0X14);
    // 0x80061394: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x80061398: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8006139C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800613A0: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800613A4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800613A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800613AC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800613B0: lh          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800613B4: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800613B8: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x800613BC: mflo        $a0
    ctx->r4 = lo;
    // 0x800613C0: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x800613C4: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800613C8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800613CC: addiu       $t9, $a0, 0x14
    ctx->r25 = ADD32(ctx->r4, 0X14);
    // 0x800613D0: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800613D4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800613D8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800613DC: addiu       $t6, $a0, 0x1E
    ctx->r14 = ADD32(ctx->r4, 0X1E);
    // 0x800613E0: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800613E4: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800613E8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800613EC: lh          $t8, 0x0($ra)
    ctx->r24 = S32(MEM_H(ctx->r31, 0X0));
    // 0x800613F0: lh          $t6, 0x0($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800613F4: addiu       $t7, $t8, -0x4
    ctx->r15 = ADD32(ctx->r24, -0X4);
    // 0x800613F8: addiu       $t9, $t6, 0x4
    ctx->r25 = ADD32(ctx->r14, 0X4);
    // 0x800613FC: sh          $t9, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r25;
    // 0x80061400: sh          $t7, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r15;
    // 0x80061404: sh          $zero, -0x1400($at)
    MEM_H(-0X1400, ctx->r1) = 0;
L_80061408:
    // 0x80061408: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8006140C: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80061410: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80061414: jr          $ra
    // 0x80061418: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80061418: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void alResampleParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD490: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800CD494: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CD498: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x800CD49C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD4A0: beq         $at, $zero, L_800CD550
    if (ctx->r1 == 0) {
        // 0x800CD4A4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CD550;
    }
    // 0x800CD4A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CD4A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CD4AC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800CD4B0: addu        $at, $at, $t6
    gpr jr_addend_800CD4B8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CD4B4: lw          $t6, -0x5F90($at)
    ctx->r14 = ADD32(ctx->r1, -0X5F90);
    // 0x800CD4B8: jr          $t6
    // 0x800CD4BC: nop

    switch (jr_addend_800CD4B8 >> 2) {
        case 0: goto L_800CD4C0; break;
        case 1: goto L_800CD550; break;
        case 2: goto L_800CD550; break;
        case 3: goto L_800CD4C8; break;
        case 4: goto L_800CD550; break;
        case 5: goto L_800CD550; break;
        case 6: goto L_800CD534; break;
        case 7: goto L_800CD544; break;
        case 8: goto L_800CD504; break;
        default: switch_error(__func__, 0x800CD4B8, 0x8010A070);
    }
    // 0x800CD4BC: nop

L_800CD4C0:
    // 0x800CD4C0: b           L_800CD568
    // 0x800CD4C4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800CD568;
    // 0x800CD4C4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_800CD4C8:
    // 0x800CD4C8: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
    // 0x800CD4CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CD4D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CD4D4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x800CD4D8: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800CD4DC: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800CD4E0: beq         $a0, $zero, L_800CD568
    if (ctx->r4 == 0) {
        // 0x800CD4E4: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_800CD568;
    }
    // 0x800CD4E4: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x800CD4E8: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CD4EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CD4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CD4F4: jalr        $t9
    // 0x800CD4F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CD4F8: nop

    after_0:
    // 0x800CD4FC: b           L_800CD56C
    // 0x800CD500: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800CD56C;
    // 0x800CD500: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CD504:
    // 0x800CD504: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
    // 0x800CD508: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CD50C: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x800CD510: beql        $a0, $zero, L_800CD56C
    if (ctx->r4 == 0) {
        // 0x800CD514: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CD56C;
    }
    goto skip_0;
    // 0x800CD514: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800CD518: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CD51C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CD520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CD524: jalr        $t9
    // 0x800CD528: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CD528: nop

    after_1:
    // 0x800CD52C: b           L_800CD56C
    // 0x800CD530: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800CD56C;
    // 0x800CD530: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CD534:
    // 0x800CD534: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800CD538: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CD53C: b           L_800CD568
    // 0x800CD540: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_800CD568;
    // 0x800CD540: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_800CD544:
    // 0x800CD544: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CD548: b           L_800CD568
    // 0x800CD54C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_800CD568;
    // 0x800CD54C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_800CD550:
    // 0x800CD550: lw          $a0, 0x0($a3)
    ctx->r4 = S32(MEM_W(ctx->r7, 0X0));
    // 0x800CD554: beql        $a0, $zero, L_800CD56C
    if (ctx->r4 == 0) {
        // 0x800CD558: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CD56C;
    }
    goto skip_1;
    // 0x800CD558: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_1:
    // 0x800CD55C: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CD560: jalr        $t9
    // 0x800CD564: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CD564: nop

    after_2:
L_800CD568:
    // 0x800CD568: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CD56C:
    // 0x800CD56C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CD570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CD574: jr          $ra
    // 0x800CD578: nop

    return;
    // 0x800CD578: nop

;}
RECOMP_FUNC void func_800616A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800616A8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800616AC: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x800616B0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800616B4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800616B8: blez        $a0, L_800617A0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800616BC: sw          $s0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r16;
            goto L_800617A0;
    }
    // 0x800616BC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800616C0: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800616C4: lui         $t2, 0x8026
    ctx->r10 = S32(0X8026 << 16);
    // 0x800616C8: lui         $t1, 0x4E0
    ctx->r9 = S32(0X4E0 << 16);
    // 0x800616CC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x800616D0: lui         $a3, 0x8022
    ctx->r7 = S32(0X8022 << 16);
    // 0x800616D4: addiu       $a3, $a3, -0x2354
    ctx->r7 = ADD32(ctx->r7, -0X2354);
    // 0x800616D8: addiu       $t0, $t0, 0x4418
    ctx->r8 = ADD32(ctx->r8, 0X4418);
    // 0x800616DC: ori         $t1, $t1, 0xF0
    ctx->r9 = ctx->r9 | 0XF0;
    // 0x800616E0: addiu       $t2, $t2, -0x3C7C
    ctx->r10 = ADD32(ctx->r10, -0X3C7C);
    // 0x800616E4: addiu       $t4, $t4, -0x2350
    ctx->r12 = ADD32(ctx->r12, -0X2350);
    // 0x800616E8: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x800616EC: lui         $t5, 0xBF00
    ctx->r13 = S32(0XBF00 << 16);
    // 0x800616F0: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
L_800616F4:
    // 0x800616F4: lh          $t8, 0x0($a3)
    ctx->r24 = S32(MEM_H(ctx->r7, 0X0));
    // 0x800616F8: bnel        $t8, $zero, L_80061724
    if (ctx->r24 != 0) {
        // 0x800616FC: lw          $v1, 0x0($t0)
        ctx->r3 = S32(MEM_W(ctx->r8, 0X0));
            goto L_80061724;
    }
    goto skip_0;
    // 0x800616FC: lw          $v1, 0x0($t0)
    ctx->r3 = S32(MEM_W(ctx->r8, 0X0));
    skip_0:
    // 0x80061700: lw          $v1, 0x0($t0)
    ctx->r3 = S32(MEM_W(ctx->r8, 0X0));
    // 0x80061704: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80061708: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8006170C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80061710: lw          $t6, 0x0($t2)
    ctx->r14 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80061714: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80061718: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x8006171C: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x80061720: lw          $v1, 0x0($t0)
    ctx->r3 = S32(MEM_W(ctx->r8, 0X0));
L_80061724:
    // 0x80061724: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80061728: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8006172C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80061730: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80061734: lh          $t8, 0x0($t4)
    ctx->r24 = S32(MEM_H(ctx->r12, 0X0));
    // 0x80061738: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006173C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80061740: mflo        $a2
    ctx->r6 = lo;
    // 0x80061744: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80061748: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8006174C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80061750: addiu       $t6, $a2, 0xA
    ctx->r14 = ADD32(ctx->r6, 0XA);
    // 0x80061754: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80061758: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x8006175C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80061760: addiu       $t9, $a2, 0x14
    ctx->r25 = ADD32(ctx->r6, 0X14);
    // 0x80061764: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x80061768: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8006176C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80061770: lh          $t9, 0x0($t4)
    ctx->r25 = S32(MEM_H(ctx->r12, 0X0));
    // 0x80061774: lh          $t8, 0x0($a3)
    ctx->r24 = S32(MEM_H(ctx->r7, 0X0));
    // 0x80061778: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x8006177C: lw          $t9, 0x0($t2)
    ctx->r25 = S32(MEM_W(ctx->r10, 0X0));
    // 0x80061780: addiu       $t7, $t8, -0x3
    ctx->r15 = ADD32(ctx->r24, -0X3);
    // 0x80061784: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80061788: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x8006178C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80061790: addiu       $t6, $t9, 0x30
    ctx->r14 = ADD32(ctx->r25, 0X30);
    // 0x80061794: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x80061798: bgtz        $a0, L_800616F4
    if (SIGNED(ctx->r4) > 0) {
        // 0x8006179C: sw          $t6, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r14;
            goto L_800616F4;
    }
    // 0x8006179C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_800617A0:
    // 0x800617A0: lw          $s0, 0x4($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X4));
    // 0x800617A4: jr          $ra
    // 0x800617A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800617A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80059384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059384: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80059388: jr          $ra
    // 0x8005938C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005938C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void __postNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA9B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CA9B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA9B8: lw          $t6, 0x2C($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X2C));
    // 0x800CA9BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CA9C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA9C4: bne         $t6, $at, L_800CAA7C
    if (ctx->r14 != ctx->r1) {
        // 0x800CA9C8: lw          $a2, 0x18($a0)
        ctx->r6 = S32(MEM_W(ctx->r4, 0X18));
            goto L_800CAA7C;
    }
    // 0x800CA9C8: lw          $a2, 0x18($a0)
    ctx->r6 = S32(MEM_W(ctx->r4, 0X18));
    // 0x800CA9CC: beq         $a2, $zero, L_800CAA7C
    if (ctx->r6 == 0) {
        // 0x800CA9D0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800CAA7C;
    }
    // 0x800CA9D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800CA9D4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800CA9D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CA9DC: jal         0x800D0400
    // 0x800CA9E0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    __alSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x800CA9E0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x800CA9E4: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CA9E8: beq         $v0, $zero, L_800CAA7C
    if (ctx->r2 == 0) {
        // 0x800CA9EC: lw          $a3, 0x38($sp)
        ctx->r7 = S32(MEM_W(ctx->r29, 0X38));
            goto L_800CAA7C;
    }
    // 0x800CA9EC: lw          $a3, 0x38($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800CA9F0: lw          $t7, 0x84($a3)
    ctx->r15 = S32(MEM_W(ctx->r7, 0X84));
    // 0x800CA9F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800CA9F8: beql        $t7, $zero, L_800CAA5C
    if (ctx->r15 == 0) {
        // 0x800CA9FC: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_800CAA5C;
    }
    goto skip_0;
    // 0x800CA9FC: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_0:
    // 0x800CAA00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CAA04: jal         0x800CFFC8
    // 0x800CAA08: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    alSeqGetTicks(rdram, ctx);
        goto after_1;
    // 0x800CAA08: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x800CAA0C: lw          $a3, 0x38($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800CAA10: lw          $t8, 0x24($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CAA14: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800CAA18: lw          $t0, 0x80($a3)
    ctx->r8 = S32(MEM_W(ctx->r7, 0X80));
    // 0x800CAA1C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800CAA20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800CAA24: lw          $t1, 0x8($t0)
    ctx->r9 = S32(MEM_W(ctx->r8, 0X8));
    // 0x800CAA28: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CAA2C: bnel        $at, $zero, L_800CAA5C
    if (ctx->r1 != 0) {
        // 0x800CAA30: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_800CAA5C;
    }
    goto skip_1;
    // 0x800CAA30: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_1:
    // 0x800CAA34: lw          $a1, 0x7C($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0X7C));
    // 0x800CAA38: jal         0x800CFFAC
    // 0x800CAA3C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    alSeqSetLoc(rdram, ctx);
        goto after_2;
    // 0x800CAA3C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x800CAA40: lw          $a3, 0x38($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800CAA44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CAA48: lw          $v0, 0x84($a3)
    ctx->r2 = S32(MEM_W(ctx->r7, 0X84));
    // 0x800CAA4C: beq         $v0, $at, L_800CAA58
    if (ctx->r2 == ctx->r1) {
        // 0x800CAA50: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800CAA58;
    }
    // 0x800CAA50: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800CAA54: sw          $t2, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r10;
L_800CAA58:
    // 0x800CAA58: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
L_800CAA5C:
    // 0x800CAA5C: lw          $t3, 0x24($a3)
    ctx->r11 = S32(MEM_W(ctx->r7, 0X24));
    // 0x800CAA60: lw          $t4, 0x24($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800CAA64: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x800CAA68: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800CAA6C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CAA70: mflo        $a2
    ctx->r6 = lo;
    // 0x800CAA74: jal         0x800C9C6C
    // 0x800CAA78: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x800CAA78: nop

    after_3:
L_800CAA7C:
    // 0x800CAA7C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800CAA80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800CAA84: jr          $ra
    // 0x800CAA88: nop

    return;
    // 0x800CAA88: nop

;}
RECOMP_FUNC void guRotateF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF500: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BF504: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800BF508: lwc1        $f4, -0x66F0($at)
    ctx->f4.u32l = S32(MEM_W(ctx->r1, -0X66F0));
    // 0x800BF50C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BF510: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BF514: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800BF518: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BF51C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800BF520: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800BF524: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800BF528: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800BF52C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800BF530: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800BF534: jal         0x800C99F0
    // 0x800BF538: swc1        $f4, -0x2BD0($at)
    MEM_W(-0X2BD0, ctx->r1) = ctx->f4.u32l;
    guNormalize(rdram, ctx);
        goto after_0;
    // 0x800BF538: swc1        $f4, -0x2BD0($at)
    MEM_W(-0X2BD0, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x800BF53C: lui         $at, 0x802B
    ctx->r1 = S32(0X802B << 16);
    // 0x800BF540: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800BF544: lwc1        $f6, -0x2BD0($at)
    ctx->f6.u32l = S32(MEM_W(ctx->r1, -0X2BD0));
    // 0x800BF548: mul.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800BF54C: jal         0x800C2BF0
    // 0x800BF550: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BF550: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800BF554: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800BF558: jal         0x800C2DB0
    // 0x800BF55C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800BF55C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800BF560: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x800BF564: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BF568: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BF56C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BF570: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800BF574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BF578: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800BF57C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X48));
    // 0x800BF580: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800BF584: mul.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BF588: nop

    // 0x800BF58C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800BF590: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x800BF594: mul.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BF598: nop

    // 0x800BF59C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BF5A0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x800BF5A4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BF5A8: jal         0x800C8BC0
    // 0x800BF5AC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_3;
    // 0x800BF5AC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800BF5B0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x800BF5B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BF5B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BF5BC: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800BF5C0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X30));
    // 0x800BF5C4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X34));
    // 0x800BF5C8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800BF5CC: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = S32(MEM_W(ctx->r29, 0X28));
    // 0x800BF5D0: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800BF5D4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800BF5D8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800BF5DC: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800BF5E0: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x800BF5E4: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BF5E8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800BF5EC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800BF5F0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x800BF5F4: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BF5F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BF5FC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800BF600: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800BF604: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BF608: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800BF60C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800BF610: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800BF614: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800BF618: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800BF61C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BF620: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BF624: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BF628: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800BF62C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800BF630: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x800BF634: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BF638: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BF63C: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800BF640: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BF644: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800BF648: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X48));
    // 0x800BF64C: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800BF650: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800BF654: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800BF658: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800BF65C: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x800BF660: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X48));
    // 0x800BF664: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BF668: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800BF66C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800BF670: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X48));
    // 0x800BF674: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BF678: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800BF67C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800BF680: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BF684: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800BF688: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800BF68C: jr          $ra
    // 0x800BF690: nop

    return;
    // 0x800BF690: nop

;}
RECOMP_FUNC void alSndpSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1780: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C1784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1788: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C178C: lw          $v0, 0x40($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X40));
    // 0x800C1790: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800C1794: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C1798: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800C179C: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x800C17A0: lw          $t7, 0x3C($a0)
    ctx->r15 = S32(MEM_W(ctx->r4, 0X3C));
    // 0x800C17A4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800C17A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800C17AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C17B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800C17B4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800C17B8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C17BC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800C17C0: jal         0x800C9C6C
    // 0x800C17C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C17C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C17C8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C17CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C17D0: jr          $ra
    // 0x800C17D4: nop

    return;
    // 0x800C17D4: nop

;}
RECOMP_FUNC void alSynStopVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA408: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CA40C: lw          $t6, 0x8($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X8));
    // 0x800CA410: beql        $t6, $zero, L_800CA46C
    if (ctx->r14 == 0) {
        // 0x800CA414: lw          $ra, 0x14($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
            goto L_800CA46C;
    }
    goto skip_0;
    // 0x800CA414: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    skip_0:
    // 0x800CA418: jal         0x800C2570
    // 0x800CA41C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800CA41C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CA420: lw          $a3, 0x1C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800CA424: beq         $v0, $zero, L_800CA468
    if (ctx->r2 == 0) {
        // 0x800CA428: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800CA468;
    }
    // 0x800CA428: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CA42C: lw          $t7, 0x18($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800CA430: lw          $t9, 0x8($a3)
    ctx->r25 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA434: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800CA438: lw          $t8, 0x1C($t7)
    ctx->r24 = S32(MEM_W(ctx->r15, 0X1C));
    // 0x800CA43C: lw          $t0, 0xD8($t9)
    ctx->r8 = S32(MEM_W(ctx->r25, 0XD8));
    // 0x800CA440: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800CA444: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800CA448: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800CA44C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800CA450: lw          $t3, 0x8($a3)
    ctx->r11 = S32(MEM_W(ctx->r7, 0X8));
    // 0x800CA454: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800CA458: lw          $a0, 0xC($t3)
    ctx->r4 = S32(MEM_W(ctx->r11, 0XC));
    // 0x800CA45C: lw          $t9, 0x8($a0)
    ctx->r25 = S32(MEM_W(ctx->r4, 0X8));
    // 0x800CA460: jalr        $t9
    // 0x800CA464: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CA464: nop

    after_1:
L_800CA468:
    // 0x800CA468: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800CA46C:
    // 0x800CA46C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA470: jr          $ra
    // 0x800CA474: nop

    return;
    // 0x800CA474: nop

;}
RECOMP_FUNC void alSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFFAC: lw          $t6, 0x0($a1)
    ctx->r14 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800CFFB0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800CFFB4: lh          $t7, 0xC($a1)
    ctx->r15 = S32(MEM_H(ctx->r5, 0XC));
    // 0x800CFFB8: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x800CFFBC: lw          $t8, 0x4($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X4));
    // 0x800CFFC0: jr          $ra
    // 0x800CFFC4: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    return;
    // 0x800CFFC4: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void gutsdir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007695C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80076960: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80076964: sll         $s4, $a3, 16
    ctx->r20 = S32(ctx->r7 << 16);
    // 0x80076968: sra         $t6, $s4, 16
    ctx->r14 = S32(SIGNED(ctx->r20) >> 16);
    // 0x8007696C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80076970: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80076974: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80076978: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x8007697C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80076980: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80076984: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80076988: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8007698C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80076990: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80076994: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80076998: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8007699C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800769A0: jal         0x80099ED4
    // 0x800769A4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    badguy(rdram, ctx);
        goto after_0;
    // 0x800769A4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_0:
    // 0x800769A8: beq         $v0, $zero, L_800769CC
    if (ctx->r2 == 0) {
        // 0x800769AC: addiu       $s1, $zero, 0x20
        ctx->r17 = ADD32(0, 0X20);
            goto L_800769CC;
    }
    // 0x800769AC: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
    // 0x800769B0: lbu         $t7, 0x27($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X27);
    // 0x800769B4: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x800769B8: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x800769BC: beql        $at, $zero, L_800769D0
    if (ctx->r1 == 0) {
        // 0x800769C0: addiu       $s2, $zero, 0x20
        ctx->r18 = ADD32(0, 0X20);
            goto L_800769D0;
    }
    goto skip_0;
    // 0x800769C0: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    skip_0:
    // 0x800769C4: b           L_800769D0
    // 0x800769C8: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
        goto L_800769D0;
    // 0x800769C8: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_800769CC:
    // 0x800769CC: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
L_800769D0:
    // 0x800769D0: lw          $s5, 0x8($s3)
    ctx->r21 = S32(MEM_W(ctx->r19, 0X8));
    // 0x800769D4: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x800769D8: lw          $a1, 0x0($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X0));
    // 0x800769DC: lw          $a2, 0x4($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X4));
    // 0x800769E0: jal         0x80098FB4
    // 0x800769E4: addiu       $s5, $s5, -0x800
    ctx->r21 = ADD32(ctx->r21, -0X800);
    getflorzofslope(rdram, ctx);
        goto after_1;
    // 0x800769E4: addiu       $s5, $s5, -0x800
    ctx->r21 = ADD32(ctx->r21, -0X800);
    after_1:
    // 0x800769E8: addiu       $v1, $v0, -0x800
    ctx->r3 = ADD32(ctx->r2, -0X800);
    // 0x800769EC: slt         $at, $v1, $s5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800769F0: beq         $at, $zero, L_800769FC
    if (ctx->r1 == 0) {
        // 0x800769F4: lh          $t9, 0x72($sp)
        ctx->r25 = S32(MEM_H(ctx->r29, 0X72));
            goto L_800769FC;
    }
    // 0x800769F4: lh          $t9, 0x72($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X72));
    // 0x800769F8: or          $s5, $v1, $zero
    ctx->r21 = ctx->r3 | 0;
L_800769FC:
    // 0x800769FC: lh          $t8, 0xE($s3)
    ctx->r24 = S32(MEM_H(ctx->r19, 0XE));
    // 0x80076A00: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x80076A04: sll         $s6, $s2, 24
    ctx->r22 = S32(ctx->r18 << 24);
    // 0x80076A08: bne         $t8, $at, L_80076A14
    if (ctx->r24 != ctx->r1) {
        // 0x80076A0C: sra         $t0, $s6, 24
        ctx->r8 = S32(SIGNED(ctx->r22) >> 24);
            goto L_80076A14;
    }
    // 0x80076A0C: sra         $t0, $s6, 24
    ctx->r8 = S32(SIGNED(ctx->r22) >> 24);
    // 0x80076A10: addiu       $s5, $s5, -0x1800
    ctx->r21 = ADD32(ctx->r21, -0X1800);
L_80076A14:
    // 0x80076A14: blez        $t9, L_80076AEC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80076A18: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80076AEC;
    }
    // 0x80076A18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80076A1C: sll         $t2, $s4, 3
    ctx->r10 = S32(ctx->r20 << 3);
    // 0x80076A20: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x80076A24: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80076A28: addu        $t2, $t2, $s4
    ctx->r10 = ADD32(ctx->r10, ctx->r20);
    // 0x80076A2C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80076A30: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x80076A34: sll         $s7, $s1, 24
    ctx->r23 = S32(ctx->r17 << 24);
    // 0x80076A38: lui         $t3, 0x802A
    ctx->r11 = S32(0X802A << 16);
    // 0x80076A3C: addiu       $t3, $t3, 0x5770
    ctx->r11 = ADD32(ctx->r11, 0X5770);
    // 0x80076A40: sra         $t1, $s7, 24
    ctx->r9 = S32(SIGNED(ctx->r23) >> 24);
    // 0x80076A44: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80076A48: addu        $fp, $t2, $t3
    ctx->r30 = ADD32(ctx->r10, ctx->r11);
    // 0x80076A4C: or          $s7, $t1, $zero
    ctx->r23 = ctx->r9 | 0;
    // 0x80076A50: addiu       $s4, $zero, -0x200
    ctx->r20 = ADD32(0, -0X200);
    // 0x80076A54: or          $s6, $t0, $zero
    ctx->r22 = ctx->r8 | 0;
L_80076A58:
    // 0x80076A58: jal         0x80098054
    // 0x80076A5C: nop

    krand(rdram, ctx);
        goto after_2;
    // 0x80076A5C: nop

    after_2:
    // 0x80076A60: andi        $s1, $v0, 0x7FF
    ctx->r17 = ctx->r2 & 0X7FF;
    // 0x80076A64: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x80076A68: jal         0x80098054
    // 0x80076A6C: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    krand(rdram, ctx);
        goto after_3;
    // 0x80076A6C: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    after_3:
    // 0x80076A70: jal         0x80098054
    // 0x80076A74: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    krand(rdram, ctx);
        goto after_4;
    // 0x80076A74: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_4:
    // 0x80076A78: lh          $a0, 0x10($s3)
    ctx->r4 = S32(MEM_H(ctx->r19, 0X10));
    // 0x80076A7C: lw          $a1, 0x0($s3)
    ctx->r5 = S32(MEM_W(ctx->r19, 0X0));
    // 0x80076A80: lw          $a2, 0x4($s3)
    ctx->r6 = S32(MEM_W(ctx->r19, 0X4));
    // 0x80076A84: lh          $t6, 0x6E($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X6E));
    // 0x80076A88: lh          $t2, 0x2E0($fp)
    ctx->r10 = S32(MEM_H(ctx->r30, 0X2E0));
    // 0x80076A8C: andi        $t8, $s2, 0x7F
    ctx->r24 = ctx->r18 & 0X7F;
    // 0x80076A90: andi        $t0, $v0, 0x7FF
    ctx->r8 = ctx->r2 & 0X7FF;
    // 0x80076A94: subu        $t1, $s4, $t0
    ctx->r9 = SUB32(ctx->r20, ctx->r8);
    // 0x80076A98: addiu       $t9, $t8, 0x100
    ctx->r25 = ADD32(ctx->r24, 0X100);
    // 0x80076A9C: addiu       $t7, $zero, -0x20
    ctx->r15 = ADD32(0, -0X20);
    // 0x80076AA0: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80076AA4: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80076AA8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80076AAC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80076AB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80076AB4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80076AB8: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x80076ABC: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x80076AC0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80076AC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80076AC8: jal         0x8009B028
    // 0x80076ACC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    EGS(rdram, ctx);
        goto after_5;
    // 0x80076ACC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_5:
    // 0x80076AD0: lh          $t6, 0x72($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X72));
    // 0x80076AD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80076AD8: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80076ADC: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80076AE0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80076AE4: bne         $at, $zero, L_80076A58
    if (ctx->r1 != 0) {
        // 0x80076AE8: nop
    
            goto L_80076A58;
    }
    // 0x80076AE8: nop

L_80076AEC:
    // 0x80076AEC: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x80076AF0: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80076AF4: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80076AF8: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80076AFC: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80076B00: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80076B04: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80076B08: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80076B0C: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x80076B10: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80076B14: jr          $ra
    // 0x80076B18: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80076B18: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void resetpspritevars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABF64: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800ABF68: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800ABF6C: lui         $s5, 0x802A
    ctx->r21 = S32(0X802A << 16);
    // 0x800ABF70: addiu       $s5, $s5, 0x5770
    ctx->r21 = ADD32(ctx->r21, 0X5770);
    // 0x800ABF74: lh          $t7, 0x282($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X282));
    // 0x800ABF78: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800ABF7C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800ABF80: addiu       $t6, $zero, 0x57D
    ctx->r14 = ADD32(0, 0X57D);
    // 0x800ABF84: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800ABF88: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800ABF8C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800ABF90: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800ABF94: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800ABF98: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800ABF9C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800ABFA0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800ABFA4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800ABFA8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800ABFAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800ABFB0: lh          $a0, 0x288($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0X288));
    // 0x800ABFB4: lw          $a1, 0x214($s5)
    ctx->r5 = S32(MEM_W(ctx->r21, 0X214));
    // 0x800ABFB8: lw          $a2, 0x218($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X218));
    // 0x800ABFBC: lw          $a3, 0x21C($s5)
    ctx->r7 = S32(MEM_W(ctx->r21, 0X21C));
    // 0x800ABFC0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800ABFC4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800ABFC8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800ABFCC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800ABFD0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800ABFD4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800ABFD8: jal         0x8009B028
    // 0x800ABFDC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    EGS(rdram, ctx);
        goto after_0;
    // 0x800ABFDC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x800ABFE0: lui         $s1, 0x802B
    ctx->r17 = S32(0X802B << 16);
    // 0x800ABFE4: addiu       $s1, $s1, -0x5598
    ctx->r17 = ADD32(ctx->r17, -0X5598);
    // 0x800ABFE8: lw          $t9, 0x18C($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X18C));
    // 0x800ABFEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800ABFF0: addiu       $s6, $zero, 0x38C
    ctx->r22 = ADD32(0, 0X38C);
    // 0x800ABFF4: blez        $t9, L_800AC050
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800ABFF8: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800AC050;
    }
    // 0x800ABFF8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800ABFFC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AC000: addiu       $s3, $s3, -0x5B5C
    ctx->r19 = ADD32(ctx->r19, -0X5B5C);
    // 0x800AC004: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
L_800AC008:
    // 0x800AC008: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800AC00C: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AC010: jal         0x800AAE50
    // 0x800AC014: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    resetplayerstats(rdram, ctx);
        goto after_1;
    // 0x800AC014: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
    // 0x800AC018: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC01C: lw          $t6, 0x18C($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X18C));
    // 0x800AC020: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AC024: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x800AC028: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800AC02C: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AC030: sb          $s4, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r20;
    // 0x800AC034: mflo        $t3
    ctx->r11 = lo;
    // 0x800AC038: addu        $v0, $s5, $t3
    ctx->r2 = ADD32(ctx->r21, ctx->r11);
    // 0x800AC03C: sb          $zero, 0x367($v0)
    MEM_B(0X367, ctx->r2) = 0;
    // 0x800AC040: sb          $zero, 0x368($v0)
    MEM_B(0X368, ctx->r2) = 0;
    // 0x800AC044: sb          $zero, 0x369($v0)
    MEM_B(0X369, ctx->r2) = 0;
    // 0x800AC048: bne         $at, $zero, L_800AC008
    if (ctx->r1 != 0) {
        // 0x800AC04C: sw          $s2, 0x274($v0)
        MEM_W(0X274, ctx->r2) = ctx->r18;
            goto L_800AC008;
    }
    // 0x800AC04C: sw          $s2, 0x274($v0)
    MEM_W(0X274, ctx->r2) = ctx->r18;
L_800AC050:
    // 0x800AC050: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x800AC054: lui         $s4, 0x802B
    ctx->r20 = S32(0X802B << 16);
    // 0x800AC058: addiu       $s4, $s4, -0x559E
    ctx->r20 = ADD32(ctx->r20, -0X559E);
    // 0x800AC05C: addiu       $s2, $s2, -0x9C0
    ctx->r18 = ADD32(ctx->r18, -0X9C0);
    // 0x800AC060: addiu       $fp, $zero, 0x9
    ctx->r30 = ADD32(0, 0X9);
    // 0x800AC064: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    // 0x800AC068: sh          $fp, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r30;
    // 0x800AC06C: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x800AC070: lh          $s0, 0x286C($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X286C));
    // 0x800AC074: addiu       $s6, $zero, 0x38C
    ctx->r22 = ADD32(0, 0X38C);
    // 0x800AC078: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AC07C: bltz        $s0, L_800AC278
    if (SIGNED(ctx->r16) < 0) {
        // 0x800AC080: addiu       $s7, $zero, 0x64
        ctx->r23 = ADD32(0, 0X64);
            goto L_800AC278;
    }
    // 0x800AC080: addiu       $s7, $zero, 0x64
    ctx->r23 = ADD32(0, 0X64);
L_800AC084:
    // 0x800AC084: lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X0);
    // 0x800AC088: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800AC08C: lui         $s3, 0x8027
    ctx->r19 = S32(0X8027 << 16);
    // 0x800AC090: addu        $s3, $s3, $t7
    ctx->r19 = ADD32(ctx->r19, ctx->r15);
    // 0x800AC094: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800AC098: bne         $a0, $at, L_800AC0B0
    if (ctx->r4 != ctx->r1) {
        // 0x800AC09C: lh          $s3, 0x5F40($s3)
        ctx->r19 = S32(MEM_H(ctx->r19, 0X5F40));
            goto L_800AC0B0;
    }
    // 0x800AC09C: lh          $s3, 0x5F40($s3)
    ctx->r19 = S32(MEM_H(ctx->r19, 0X5F40));
    // 0x800AC0A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800AC0A4: jal         0x80099460
    // 0x800AC0A8: addiu       $a0, $a0, -0x7C94
    ctx->r4 = ADD32(ctx->r4, -0X7C94);
    gameexit(rdram, ctx);
        goto after_2;
    // 0x800AC0A8: addiu       $a0, $a0, -0x7C94
    ctx->r4 = ADD32(ctx->r4, -0X7C94);
    after_2:
    // 0x800AC0AC: lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X0);
L_800AC0B0:
    // 0x800AC0B0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800AC0B4: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800AC0B8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800AC0BC: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800AC0C0: lui         $t3, 0x8024
    ctx->r11 = S32(0X8024 << 16);
    // 0x800AC0C4: addiu       $t3, $t3, 0x6BA8
    ctx->r11 = ADD32(ctx->r11, 0X6BA8);
    // 0x800AC0C8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800AC0CC: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x800AC0D0: lw          $t4, 0x0($v1)
    ctx->r12 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800AC0D4: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x800AC0D8: lui         $a1, 0x802B
    ctx->r5 = S32(0X802B << 16);
    // 0x800AC0DC: addiu       $t9, $t9, 0x5630
    ctx->r25 = ADD32(ctx->r25, 0X5630);
    // 0x800AC0E0: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800AC0E4: lw          $a1, -0x540C($a1)
    ctx->r5 = S32(MEM_W(ctx->r5, -0X540C));
    // 0x800AC0E8: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800AC0EC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800AC0F0: lw          $t5, 0x4($v1)
    ctx->r13 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800AC0F4: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800AC0F8: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AC0FC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800AC100: lw          $t6, 0x8($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X8));
    // 0x800AC104: addiu       $t2, $zero, 0x2A
    ctx->r10 = ADD32(0, 0X2A);
    // 0x800AC108: addiu       $t3, $zero, 0x24
    ctx->r11 = ADD32(0, 0X24);
    // 0x800AC10C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x800AC110: lh          $t7, 0x14($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0X14));
    // 0x800AC114: addiu       $t4, $zero, 0x101
    ctx->r12 = ADD32(0, 0X101);
    // 0x800AC118: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800AC11C: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x800AC120: lh          $t8, 0x10($v1)
    ctx->r24 = S32(MEM_H(ctx->r3, 0X10));
    // 0x800AC124: sb          $t9, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r25;
    // 0x800AC128: beq         $at, $zero, L_800AC25C
    if (ctx->r1 == 0) {
        // 0x800AC12C: sh          $t8, 0xE($v0)
        MEM_H(0XE, ctx->r2) = ctx->r24;
            goto L_800AC25C;
    }
    // 0x800AC12C: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x800AC130: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800AC134: sh          $s0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r16;
    // 0x800AC138: sb          $zero, 0x24($v1)
    MEM_B(0X24, ctx->r3) = 0;
    // 0x800AC13C: sb          $t2, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r10;
    // 0x800AC140: sb          $t3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r11;
    // 0x800AC144: sh          $t4, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r12;
    // 0x800AC148: sb          $zero, 0x29($v1)
    MEM_B(0X29, ctx->r3) = 0;
    // 0x800AC14C: sb          $t5, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r13;
    // 0x800AC150: lbu         $t6, 0x6B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X6B);
    // 0x800AC154: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800AC158: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x800AC15C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800AC160: bne         $t7, $at, L_800AC180
    if (ctx->r15 != ctx->r1) {
        // 0x800AC164: addu        $t5, $t5, $s0
        ctx->r13 = ADD32(ctx->r13, ctx->r16);
            goto L_800AC180;
    }
    // 0x800AC164: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x800AC168: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC16C: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC170: addu        $a3, $s5, $t8
    ctx->r7 = ADD32(ctx->r21, ctx->r24);
    // 0x800AC174: lh          $v0, 0x28C($a3)
    ctx->r2 = S32(MEM_H(ctx->r7, 0X28C));
    // 0x800AC178: bnel        $v0, $zero, L_800AC19C
    if (ctx->r2 != 0) {
        // 0x800AC17C: sh          $v0, 0x22($v1)
        MEM_H(0X22, ctx->r3) = ctx->r2;
            goto L_800AC19C;
    }
    goto skip_0;
    // 0x800AC17C: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    skip_0:
L_800AC180:
    // 0x800AC180: multu       $s1, $s6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC184: mflo        $t9
    ctx->r25 = lo;
    // 0x800AC188: addu        $a3, $s5, $t9
    ctx->r7 = ADD32(ctx->r21, ctx->r25);
    // 0x800AC18C: sh          $s7, 0x28C($a3)
    MEM_H(0X28C, ctx->r7) = ctx->r23;
    // 0x800AC190: b           L_800AC19C
    // 0x800AC194: sh          $s7, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r23;
        goto L_800AC19C;
    // 0x800AC194: sh          $s7, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r23;
    // 0x800AC198: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
L_800AC19C:
    // 0x800AC19C: lbu         $v0, 0x25($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X25);
    // 0x800AC1A0: sh          $s1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r17;
    // 0x800AC1A4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800AC1A8: bne         $v0, $zero, L_800AC1E0
    if (ctx->r2 != 0) {
        // 0x800AC1AC: lui         $t6, 0x8028
        ctx->r14 = S32(0X8028 << 16);
            goto L_800AC1E0;
    }
    // 0x800AC1AC: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x800AC1B0: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    // 0x800AC1B4: sb          $v0, 0x363($a3)
    MEM_B(0X363, ctx->r7) = ctx->r2;
    // 0x800AC1B8: sb          $v0, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r2;
    // 0x800AC1BC: lh          $t2, 0x0($s2)
    ctx->r10 = S32(MEM_H(ctx->r18, 0X0));
    // 0x800AC1C0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800AC1C4: sh          $t3, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r11;
    // 0x800AC1C8: lh          $t4, 0x0($s2)
    ctx->r12 = S32(MEM_H(ctx->r18, 0X0));
    // 0x800AC1CC: slti        $at, $t4, 0x11
    ctx->r1 = SIGNED(ctx->r12) < 0X11 ? 1 : 0;
    // 0x800AC1D0: bne         $at, $zero, L_800AC1E4
    if (ctx->r1 != 0) {
        // 0x800AC1D4: nop
    
            goto L_800AC1E4;
    }
    // 0x800AC1D4: nop

    // 0x800AC1D8: b           L_800AC1E4
    // 0x800AC1DC: sh          $fp, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r30;
        goto L_800AC1E4;
    // 0x800AC1DC: sh          $fp, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r30;
L_800AC1E0:
    // 0x800AC1E0: sb          $v0, 0x363($a3)
    MEM_B(0X363, ctx->r7) = ctx->r2;
L_800AC1E4:
    // 0x800AC1E4: addiu       $t6, $t6, -0x5C00
    ctx->r14 = ADD32(ctx->r14, -0X5C00);
    // 0x800AC1E8: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x800AC1EC: sh          $s0, 0x2E0($a3)
    MEM_H(0X2E0, ctx->r7) = ctx->r16;
    // 0x800AC1F0: sh          $s1, 0x32A($a3)
    MEM_H(0X32A, ctx->r7) = ctx->r17;
    // 0x800AC1F4: sh          $s0, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r16;
    // 0x800AC1F8: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800AC1FC: addiu       $a2, $a3, 0x288
    ctx->r6 = ADD32(ctx->r7, 0X288);
    // 0x800AC200: sw          $v0, 0x214($a3)
    MEM_W(0X214, ctx->r7) = ctx->r2;
    // 0x800AC204: sw          $v0, 0x238($a3)
    MEM_W(0X238, ctx->r7) = ctx->r2;
    // 0x800AC208: sw          $v0, 0x230($a3)
    MEM_W(0X230, ctx->r7) = ctx->r2;
    // 0x800AC20C: sw          $v0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r2;
    // 0x800AC210: lw          $v0, 0x4($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800AC214: sw          $v0, 0x218($a3)
    MEM_W(0X218, ctx->r7) = ctx->r2;
    // 0x800AC218: sw          $v0, 0x23C($a3)
    MEM_W(0X23C, ctx->r7) = ctx->r2;
    // 0x800AC21C: sw          $v0, 0x234($a3)
    MEM_W(0X234, ctx->r7) = ctx->r2;
    // 0x800AC220: sw          $v0, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r2;
    // 0x800AC224: lw          $v0, 0x8($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X8));
    // 0x800AC228: sw          $v0, 0x21C($a3)
    MEM_W(0X21C, ctx->r7) = ctx->r2;
    // 0x800AC22C: sw          $v0, 0x240($a3)
    MEM_W(0X240, ctx->r7) = ctx->r2;
    // 0x800AC230: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
    // 0x800AC234: lh          $t0, 0x14($v1)
    ctx->r8 = S32(MEM_H(ctx->r3, 0X14));
    // 0x800AC238: sh          $t0, 0x282($a3)
    MEM_H(0X282, ctx->r7) = ctx->r8;
    // 0x800AC23C: sh          $t0, 0x284($a3)
    MEM_H(0X284, ctx->r7) = ctx->r8;
    // 0x800AC240: lw          $a1, 0x4($v1)
    ctx->r5 = S32(MEM_W(ctx->r3, 0X4));
    // 0x800AC244: jal         0x80097DB8
    // 0x800AC248: lw          $a0, 0x0($v1)
    ctx->r4 = S32(MEM_W(ctx->r3, 0X0));
    updatesector(rdram, ctx);
        goto after_3;
    // 0x800AC248: lw          $a0, 0x0($v1)
    ctx->r4 = S32(MEM_W(ctx->r3, 0X0));
    after_3:
    // 0x800AC24C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AC250: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x800AC254: b           L_800AC268
    // 0x800AC258: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
        goto L_800AC268;
    // 0x800AC258: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_800AC25C:
    // 0x800AC25C: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AC260: jal         0x80092728
    // 0x800AC264: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    deletesprite(rdram, ctx);
        goto after_4;
    // 0x800AC264: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_4:
L_800AC268:
    // 0x800AC268: sll         $s0, $s3, 16
    ctx->r16 = S32(ctx->r19 << 16);
    // 0x800AC26C: sra         $t2, $s0, 16
    ctx->r10 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800AC270: bgez        $s3, L_800AC084
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800AC274: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_800AC084;
    }
    // 0x800AC274: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_800AC278:
    // 0x800AC278: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800AC27C: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800AC280: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800AC284: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800AC288: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800AC28C: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800AC290: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800AC294: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800AC298: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800AC29C: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x800AC2A0: jr          $ra
    // 0x800AC2A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AC2A4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3130: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C3134: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C3138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C313C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C3140: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C3144: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C3148: jal         0x800C8BC0
    // 0x800C314C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800C314C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800C3150: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C3154: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3158: ldc1        $f6, -0x6390($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6390);
    // 0x800C315C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x800C3160: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C3164: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C3168: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C316C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800C3170: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800C3174: jal         0x800C2DB0
    // 0x800C3178: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C3178: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800C317C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C3180: jal         0x800C2BF0
    // 0x800C3184: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800C3184: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800C3188: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C318C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X3C));
    // 0x800C3190: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = S32(MEM_W(ctx->r29, 0X40));
    // 0x800C3194: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C3198: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = S32(MEM_W(ctx->r29, 0X44));
    // 0x800C319C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800C31A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C31A4: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x800C31A8: lw          $v0, 0x30($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800C31AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C31B0: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800C31B4: lw          $a1, 0x34($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800C31B8: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x800C31BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C31C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800C31C4: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800C31C8: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x800C31CC: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800C31D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C31D4: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x800C31D8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800C31DC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800C31E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C31E4: nop

    // 0x800C31E8: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800C31EC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C31F0: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800C31F4: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800C31F8: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = S32(MEM_W(ctx->r29, 0X48));
    // 0x800C31FC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = S32(MEM_W(ctx->r2, 0X0));
    // 0x800C3200: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C3204: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = S32(MEM_W(ctx->r2, 0X4));
    // 0x800C3208: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C320C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = S32(MEM_W(ctx->r2, 0X8));
    // 0x800C3210: beq         $v1, $a0, L_800C3254
    if (ctx->r3 == ctx->r4) {
        // 0x800C3214: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = S32(MEM_W(ctx->r2, 0XC));
            goto L_800C3254;
    }
    // 0x800C3214: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = S32(MEM_W(ctx->r2, 0XC));
L_800C3218:
    // 0x800C3218: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C321C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = S32(MEM_W(ctx->r2, 0X10));
    // 0x800C3220: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = S32(MEM_W(ctx->r2, 0X14));
    // 0x800C3224: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C3228: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = S32(MEM_W(ctx->r2, 0X18));
    // 0x800C322C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C3230: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800C3234: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = S32(MEM_W(ctx->r2, 0X1C));
    // 0x800C3238: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800C323C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C3240: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800C3244: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800C3248: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C324C: bne         $v1, $a0, L_800C3218
    if (ctx->r3 != ctx->r4) {
        // 0x800C3250: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_800C3218;
    }
    // 0x800C3250: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_800C3254:
    // 0x800C3254: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C3258: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C325C: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x800C3260: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C3264: nop

    // 0x800C3268: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800C326C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x800C3270: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800C3274: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x800C3278: beq         $a1, $zero, L_800C3350
    if (ctx->r5 == 0) {
        // 0x800C327C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800C3350;
    }
    // 0x800C327C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C3280: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C3284: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3288: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x800C328C: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800C3290: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x800C3294: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800C3298: bc1fl       L_800C32AC
    if (!c1cs) {
        // 0x800C329C: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_800C32AC;
    }
    goto skip_0;
    // 0x800C329C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800C32A0: b           L_800C3350
    // 0x800C32A4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_800C3350;
    // 0x800C32A4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800C32A8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_800C32AC:
    // 0x800C32AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C32B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C32B4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800C32B8: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x800C32BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C32C0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C32C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C32C8: nop

    // 0x800C32CC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800C32D0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C32D4: nop

    // 0x800C32D8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C32DC: beql        $t8, $zero, L_800C3330
    if (ctx->r24 == 0) {
        // 0x800C32E0: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800C3330;
    }
    goto skip_1;
    // 0x800C32E0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800C32E4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C32E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C32EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C32F0: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800C32F4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C32F8: nop

    // 0x800C32FC: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800C3300: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C3304: nop

    // 0x800C3308: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C330C: bne         $t8, $zero, L_800C3324
    if (ctx->r24 != 0) {
        // 0x800C3310: nop
    
            goto L_800C3324;
    }
    // 0x800C3310: nop

    // 0x800C3314: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800C3318: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C331C: b           L_800C333C
    // 0x800C3320: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800C333C;
    // 0x800C3320: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800C3324:
    // 0x800C3324: b           L_800C333C
    // 0x800C3328: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800C333C;
    // 0x800C3328: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C332C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800C3330:
    // 0x800C3330: nop

    // 0x800C3334: bltz        $t8, L_800C3324
    if (SIGNED(ctx->r24) < 0) {
        // 0x800C3338: nop
    
            goto L_800C3324;
    }
    // 0x800C3338: nop

L_800C333C:
    // 0x800C333C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C3340: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800C3344: bgtz        $t9, L_800C3350
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C3348: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_800C3350;
    }
    // 0x800C3348: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800C334C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_800C3350:
    // 0x800C3350: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C3354: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C3358: jr          $ra
    // 0x800C335C: nop

    return;
    // 0x800C335C: nop

;}
RECOMP_FUNC void divscale19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009158C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091590: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80091594: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80091598: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    // 0x8009159C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800915A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800915A4: jal         0x800BB834
    // 0x800915A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x800915A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800915AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800915B0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800915B4: lw          $a2, 0x20($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800915B8: jal         0x800BB89C
    // 0x800915BC: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    __ll_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800915BC: lw          $a3, 0x24($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X24));
    after_1:
    // 0x800915C0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800915C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800915C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800915CC: jr          $ra
    // 0x800915D0: nop

    return;
    // 0x800915D0: nop

;}
RECOMP_FUNC void func_80061CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061CB8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80061CBC: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80061CC0: lhu         $t7, -0x2982($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2982);
    // 0x80061CC4: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x80061CC8: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80061CCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061CD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80061CD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80061CD8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80061CDC: beq         $t6, $t7, L_80061FB4
    if (ctx->r14 == ctx->r15) {
        // 0x80061CE0: sh          $t6, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r14;
            goto L_80061FB4;
    }
    // 0x80061CE0: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
    // 0x80061CE4: jal         0x8006370C
    // 0x80061CE8: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    gettileid(rdram, ctx);
        goto after_0;
    // 0x80061CE8: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    after_0:
    // 0x80061CEC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80061CF0: sra         $t4, $t9, 16
    ctx->r12 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80061CF4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80061CF8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80061CFC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80061D00: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80061D04: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80061D08: lw          $t6, -0x5008($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X5008));
    // 0x80061D0C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80061D10: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80061D14: andi        $t7, $t6, 0xC0
    ctx->r15 = ctx->r14 & 0XC0;
    // 0x80061D18: beq         $t7, $zero, L_80061D40
    if (ctx->r15 == 0) {
        // 0x80061D1C: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80061D40;
    }
    // 0x80061D1C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80061D20: lh          $a0, 0x56($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X56));
    // 0x80061D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80061D28: jal         0x8009223C
    // 0x80061D2C: sh          $t8, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r24;
    animateoffs(rdram, ctx);
        goto after_1;
    // 0x80061D2C: sh          $t8, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r24;
    after_1:
    // 0x80061D30: lh          $a2, 0x5A($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x80061D34: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80061D38: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80061D3C: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
L_80061D40:
    // 0x80061D40: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80061D44: addiu       $s0, $s0, 0x4418
    ctx->r16 = ADD32(ctx->r16, 0X4418);
    // 0x80061D48: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061D4C: lui         $t5, 0xFD90
    ctx->r13 = S32(0XFD90 << 16);
    // 0x80061D50: andi        $s1, $a2, 0xFFFF
    ctx->r17 = ctx->r6 & 0XFFFF;
    // 0x80061D54: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80061D58: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80061D5C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80061D60: sh          $a2, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r6;
    // 0x80061D64: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80061D68: jal         0x80063880
    // 0x80061D6C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    func_80063880(rdram, ctx);
        goto after_2;
    // 0x80061D6C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_2:
    // 0x80061D70: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80061D74: addiu       $t6, $v0, 0x20
    ctx->r14 = ADD32(ctx->r2, 0X20);
    // 0x80061D78: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x80061D7C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80061D80: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061D84: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80061D88: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80061D8C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80061D90: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80061D94: jal         0x80063AE0
    // 0x80061D98: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_80063AE0(rdram, ctx);
        goto after_3;
    // 0x80061D98: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80061D9C: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80061DA0: jal         0x80063A08
    // 0x80061DA4: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    func_80063A08(rdram, ctx);
        goto after_4;
    // 0x80061DA4: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_4:
    // 0x80061DA8: lbu         $t6, 0x33($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X33);
    // 0x80061DAC: andi        $t9, $v0, 0xF
    ctx->r25 = ctx->r2 & 0XF;
    // 0x80061DB0: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x80061DB4: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x80061DB8: or          $t5, $t4, $t3
    ctx->r13 = ctx->r12 | ctx->r11;
    // 0x80061DBC: lw          $t4, 0x4C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80061DC0: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80061DC4: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80061DC8: lh          $a2, 0x5A($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x80061DCC: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80061DD0: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80061DD4: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061DD8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80061DDC: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x80061DE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061DE4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80061DE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80061DEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061DF0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80061DF4: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061DF8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80061DFC: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x80061E00: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80061E04: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80061E08: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80061E0C: addiu       $t4, $t4, -0x5010
    ctx->r12 = ADD32(ctx->r12, -0X5010);
    // 0x80061E10: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80061E14: addu        $a3, $t9, $t4
    ctx->r7 = ADD32(ctx->r25, ctx->r12);
    // 0x80061E18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80061E1C: lhu         $t6, 0x14($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X14);
    // 0x80061E20: lhu         $a1, 0x12($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X12);
    // 0x80061E24: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x80061E28: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80061E2C: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061E30: mflo        $t0
    ctx->r8 = lo;
    // 0x80061E34: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x80061E38: sra         $t7, $t0, 2
    ctx->r15 = S32(SIGNED(ctx->r8) >> 2);
    // 0x80061E3C: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x80061E40: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x80061E44: beq         $at, $zero, L_80061E54
    if (ctx->r1 == 0) {
        // 0x80061E48: nop
    
            goto L_80061E54;
    }
    // 0x80061E48: nop

    // 0x80061E4C: b           L_80061E54
    // 0x80061E50: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
        goto L_80061E54;
    // 0x80061E50: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_80061E54:
    // 0x80061E54: bgez        $a1, L_80061E64
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80061E58: sra         $v0, $a1, 4
        ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
            goto L_80061E64;
    }
    // 0x80061E58: sra         $v0, $a1, 4
    ctx->r2 = S32(SIGNED(ctx->r5) >> 4);
    // 0x80061E5C: addiu       $at, $a1, 0xF
    ctx->r1 = ADD32(ctx->r5, 0XF);
    // 0x80061E60: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_80061E64:
    // 0x80061E64: bgtz        $v0, L_80061E74
    if (SIGNED(ctx->r2) > 0) {
        // 0x80061E68: andi        $t6, $a2, 0xFFF
        ctx->r14 = ctx->r6 & 0XFFF;
            goto L_80061E74;
    }
    // 0x80061E68: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80061E6C: b           L_80061E78
    // 0x80061E70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80061E78;
    // 0x80061E70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80061E74:
    // 0x80061E74: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_80061E78:
    // 0x80061E78: bgtz        $v0, L_80061E88
    if (SIGNED(ctx->r2) > 0) {
        // 0x80061E7C: addiu       $t5, $t0, 0x7FF
        ctx->r13 = ADD32(ctx->r8, 0X7FF);
            goto L_80061E88;
    }
    // 0x80061E7C: addiu       $t5, $t0, 0x7FF
    ctx->r13 = ADD32(ctx->r8, 0X7FF);
    // 0x80061E80: b           L_80061E8C
    // 0x80061E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80061E8C;
    // 0x80061E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80061E88:
    // 0x80061E88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80061E8C:
    // 0x80061E8C: div         $zero, $t5, $a1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r5)));
    // 0x80061E90: mflo        $t8
    ctx->r24 = lo;
    // 0x80061E94: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80061E98: bne         $a1, $zero, L_80061EA4
    if (ctx->r5 != 0) {
        // 0x80061E9C: nop
    
            goto L_80061EA4;
    }
    // 0x80061E9C: nop

    // 0x80061EA0: break       7
    do_break(2147884704);
L_80061EA4:
    // 0x80061EA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80061EA8: bne         $a1, $at, L_80061EBC
    if (ctx->r5 != ctx->r1) {
        // 0x80061EAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80061EBC;
    }
    // 0x80061EAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80061EB0: bne         $t5, $at, L_80061EBC
    if (ctx->r13 != ctx->r1) {
        // 0x80061EB4: nop
    
            goto L_80061EBC;
    }
    // 0x80061EB4: nop

    // 0x80061EB8: break       6
    do_break(2147884728);
L_80061EBC:
    // 0x80061EBC: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x80061EC0: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80061EC4: or          $t5, $t4, $t7
    ctx->r13 = ctx->r12 | ctx->r15;
    // 0x80061EC8: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80061ECC: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061ED0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80061ED4: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x80061ED8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80061EDC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80061EE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80061EE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80061EE8: lhu         $t4, 0x12($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X12);
    // 0x80061EEC: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061EF0: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80061EF4: sra         $t7, $t4, 1
    ctx->r15 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80061EF8: addiu       $t5, $t7, 0x7
    ctx->r13 = ADD32(ctx->r15, 0X7);
    // 0x80061EFC: sra         $t8, $t5, 3
    ctx->r24 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80061F00: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80061F04: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80061F08: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80061F0C: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x80061F10: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x80061F14: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80061F18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80061F1C: jal         0x80063AE0
    // 0x80061F20: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_80063AE0(rdram, ctx);
        goto after_5;
    // 0x80061F20: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_5:
    // 0x80061F24: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80061F28: jal         0x80063A08
    // 0x80061F2C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    func_80063A08(rdram, ctx);
        goto after_6;
    // 0x80061F2C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_6:
    // 0x80061F30: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x80061F34: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x80061F38: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x80061F3C: lw          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80061F40: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80061F44: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80061F48: lw          $a3, 0x20($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80061F4C: or          $t4, $t5, $t6
    ctx->r12 = ctx->r13 | ctx->r14;
    // 0x80061F50: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x80061F54: lw          $v1, 0x0($s0)
    ctx->r3 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80061F58: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80061F5C: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80061F60: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80061F64: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80061F68: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80061F6C: lhu         $t5, 0x14($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X14);
    // 0x80061F70: lhu         $t8, 0x12($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X12);
    // 0x80061F74: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80061F78: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80061F7C: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80061F80: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80061F84: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80061F88: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80061F8C: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x80061F90: sll         $t4, $t6, 12
    ctx->r12 = S32(ctx->r14 << 12);
    // 0x80061F94: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x80061F98: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80061F9C: lhu         $t9, 0x56($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X56);
    // 0x80061FA0: addiu       $a1, $a1, -0x1B34
    ctx->r5 = ADD32(ctx->r5, -0X1B34);
    // 0x80061FA4: sh          $t9, -0x2982($at)
    MEM_H(-0X2982, ctx->r1) = ctx->r25;
    // 0x80061FA8: lw          $t5, 0x0($a1)
    ctx->r13 = S32(MEM_W(ctx->r5, 0X0));
    // 0x80061FAC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80061FB0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80061FB4:
    // 0x80061FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80061FB8: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80061FBC: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80061FC0: jr          $ra
    // 0x80061FC4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80061FC4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void alEvtqFlushType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9B50: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C9B54: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C9B58: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x800C9B5C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C9B60: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C9B64: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800C9B68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9B6C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x800C9B70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C9B74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C9B78: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C9B7C: jal         0x800BC180
    // 0x800C9B80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9B80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C9B84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C9B88: lw          $s0, 0x8($s2)
    ctx->r16 = S32(MEM_W(ctx->r18, 0X8));
    // 0x800C9B8C: beq         $s0, $zero, L_800C9BD8
    if (ctx->r16 == 0) {
        // 0x800C9B90: nop
    
            goto L_800C9BD8;
    }
    // 0x800C9B90: nop

L_800C9B94:
    // 0x800C9B94: lh          $t7, 0xC($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0XC));
    // 0x800C9B98: lw          $s1, 0x0($s0)
    ctx->r17 = S32(MEM_W(ctx->r16, 0X0));
    // 0x800C9B9C: bne         $s3, $t7, L_800C9BD0
    if (ctx->r19 != ctx->r15) {
        // 0x800C9BA0: nop
    
            goto L_800C9BD0;
    }
    // 0x800C9BA0: nop

    // 0x800C9BA4: beq         $s1, $zero, L_800C9BBC
    if (ctx->r17 == 0) {
        // 0x800C9BA8: nop
    
            goto L_800C9BBC;
    }
    // 0x800C9BA8: nop

    // 0x800C9BAC: lw          $t8, 0x8($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X8));
    // 0x800C9BB0: lw          $t9, 0x8($s0)
    ctx->r25 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800C9BB4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C9BB8: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800C9BBC:
    // 0x800C9BBC: jal         0x800BF770
    // 0x800C9BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C9BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9BC8: jal         0x800BF7A0
    // 0x800C9BCC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C9BCC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800C9BD0:
    // 0x800C9BD0: bne         $s1, $zero, L_800C9B94
    if (ctx->r17 != 0) {
        // 0x800C9BD4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C9B94;
    }
    // 0x800C9BD4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C9BD8:
    // 0x800C9BD8: jal         0x800BC180
    // 0x800C9BDC: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C9BDC: lw          $a0, 0x2C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X2C));
    after_3:
    // 0x800C9BE0: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800C9BE4: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800C9BE8: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800C9BEC: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800C9BF0: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C9BF4: jr          $ra
    // 0x800C9BF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C9BF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void checkhitsprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B177C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800B1780: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
    // 0x800B1784: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800B1788: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800B178C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800B1790: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x800B1794: sra         $s6, $t9, 16
    ctx->r22 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800B1798: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800B179C: slti        $at, $s6, 0x7D0
    ctx->r1 = SIGNED(ctx->r22) < 0X7D0 ? 1 : 0;
    // 0x800B17A0: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800B17A4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800B17A8: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800B17AC: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800B17B0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800B17B4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800B17B8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800B17BC: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800B17C0: bne         $at, $zero, L_800B17D4
    if (ctx->r1 != 0) {
        // 0x800B17C4: sw          $a1, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->r5;
            goto L_800B17D4;
    }
    // 0x800B17C4: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800B17C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800B17CC: jal         0x80099460
    // 0x800B17D0: addiu       $a0, $a0, -0x7ACC
    ctx->r4 = ADD32(ctx->r4, -0X7ACC);
    gameexit(rdram, ctx);
        goto after_0;
    // 0x800B17D0: addiu       $a0, $a0, -0x7ACC
    ctx->r4 = ADD32(ctx->r4, -0X7ACC);
    after_0:
L_800B17D4:
    // 0x800B17D4: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x800B17D8: multu       $s6, $a3
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B17DC: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x800B17E0: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x800B17E4: mflo        $t1
    ctx->r9 = lo;
    // 0x800B17E8: addu        $s5, $a2, $t1
    ctx->r21 = ADD32(ctx->r6, ctx->r9);
    // 0x800B17EC: lh          $a0, 0xE($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0XE));
    // 0x800B17F0: slti        $at, $a0, 0x390
    ctx->r1 = SIGNED(ctx->r4) < 0X390 ? 1 : 0;
    // 0x800B17F4: bne         $at, $zero, L_800B18F4
    if (ctx->r1 != 0) {
        // 0x800B17F8: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800B18F4;
    }
    // 0x800B17F8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B17FC: slti        $at, $v1, 0x58D
    ctx->r1 = SIGNED(ctx->r3) < 0X58D ? 1 : 0;
    // 0x800B1800: bne         $at, $zero, L_800B1840
    if (ctx->r1 != 0) {
        // 0x800B1804: addiu       $at, $zero, 0xA1E
        ctx->r1 = ADD32(0, 0XA1E);
            goto L_800B1840;
    }
    // 0x800B1804: addiu       $at, $zero, 0xA1E
    ctx->r1 = ADD32(0, 0XA1E);
    // 0x800B1808: beq         $v1, $at, L_800B22A0
    if (ctx->r3 == ctx->r1) {
        // 0x800B180C: lui         $t1, 0x8028
        ctx->r9 = S32(0X8028 << 16);
            goto L_800B22A0;
    }
    // 0x800B180C: lui         $t1, 0x8028
    ctx->r9 = S32(0X8028 << 16);
    // 0x800B1810: addiu       $at, $zero, 0x1003
    ctx->r1 = ADD32(0, 0X1003);
    // 0x800B1814: beq         $v1, $at, L_800B24C0
    if (ctx->r3 == ctx->r1) {
        // 0x800B1818: addiu       $t6, $zero, 0x1004
        ctx->r14 = ADD32(0, 0X1004);
            goto L_800B24C0;
    }
    // 0x800B1818: addiu       $t6, $zero, 0x1004
    ctx->r14 = ADD32(0, 0X1004);
    // 0x800B181C: addiu       $at, $zero, 0x115C
    ctx->r1 = ADD32(0, 0X115C);
    // 0x800B1820: beq         $v1, $at, L_800B27F0
    if (ctx->r3 == ctx->r1) {
        // 0x800B1824: addiu       $at, $zero, 0x1171
        ctx->r1 = ADD32(0, 0X1171);
            goto L_800B27F0;
    }
    // 0x800B1824: addiu       $at, $zero, 0x1171
    ctx->r1 = ADD32(0, 0X1171);
    // 0x800B1828: beq         $v1, $at, L_800B1D18
    if (ctx->r3 == ctx->r1) {
        // 0x800B182C: addiu       $at, $zero, 0x134F
        ctx->r1 = ADD32(0, 0X134F);
            goto L_800B1D18;
    }
    // 0x800B182C: addiu       $at, $zero, 0x134F
    ctx->r1 = ADD32(0, 0X134F);
    // 0x800B1830: beql        $v1, $at, L_800B25C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B1834: sll         $a1, $s6, 16
        ctx->r5 = S32(ctx->r22 << 16);
            goto L_800B25C8;
    }
    goto skip_0;
    // 0x800B1834: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    skip_0:
    // 0x800B1838: b           L_800B2924
    // 0x800B183C: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
        goto L_800B2924;
    // 0x800B183C: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
L_800B1840:
    // 0x800B1840: slti        $at, $v1, 0x48F
    ctx->r1 = SIGNED(ctx->r3) < 0X48F ? 1 : 0;
    // 0x800B1844: bne         $at, $zero, L_800B1888
    if (ctx->r1 != 0) {
        // 0x800B1848: slti        $at, $v1, 0x550
        ctx->r1 = SIGNED(ctx->r3) < 0X550 ? 1 : 0;
            goto L_800B1888;
    }
    // 0x800B1848: slti        $at, $v1, 0x550
    ctx->r1 = SIGNED(ctx->r3) < 0X550 ? 1 : 0;
    // 0x800B184C: bne         $at, $zero, L_800B1868
    if (ctx->r1 != 0) {
        // 0x800B1850: addiu       $t2, $v1, -0x548
        ctx->r10 = ADD32(ctx->r3, -0X548);
            goto L_800B1868;
    }
    // 0x800B1850: addiu       $t2, $v1, -0x548
    ctx->r10 = ADD32(ctx->r3, -0X548);
    // 0x800B1854: addiu       $at, $zero, 0x58C
    ctx->r1 = ADD32(0, 0X58C);
    // 0x800B1858: beql        $v1, $at, L_800B2908
    if (ctx->r3 == ctx->r1) {
        // 0x800B185C: lh          $s6, 0x16($s5)
        ctx->r22 = S32(MEM_H(ctx->r21, 0X16));
            goto L_800B2908;
    }
    goto skip_1;
    // 0x800B185C: lh          $s6, 0x16($s5)
    ctx->r22 = S32(MEM_H(ctx->r21, 0X16));
    skip_1:
    // 0x800B1860: b           L_800B2924
    // 0x800B1864: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
        goto L_800B2924;
    // 0x800B1864: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
L_800B1868:
    // 0x800B1868: sltiu       $at, $t2, 0x8
    ctx->r1 = ctx->r10 < 0X8 ? 1 : 0;
    // 0x800B186C: beq         $at, $zero, L_800B2920
    if (ctx->r1 == 0) {
        // 0x800B1870: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_800B2920;
    }
    // 0x800B1870: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B1874: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B1878: addu        $at, $at, $t2
    gpr jr_addend_800B1880 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800B187C: lw          $t2, -0x7280($at)
    ctx->r10 = ADD32(ctx->r1, -0X7280);
    // 0x800B1880: jr          $t2
    // 0x800B1884: nop

    switch (jr_addend_800B1880 >> 2) {
        case 0: goto L_800B25C4; break;
        case 1: goto L_800B25F8; break;
        case 2: goto L_800B25C4; break;
        case 3: goto L_800B25C4; break;
        case 4: goto L_800B2920; break;
        case 5: goto L_800B2920; break;
        case 6: goto L_800B217C; break;
        case 7: goto L_800B21B8; break;
        default: switch_error(__func__, 0x800B1880, 0x80108D80);
    }
    // 0x800B1884: nop

L_800B1888:
    // 0x800B1888: slti        $at, $v1, 0x45A
    ctx->r1 = SIGNED(ctx->r3) < 0X45A ? 1 : 0;
    // 0x800B188C: bne         $at, $zero, L_800B18B4
    if (ctx->r1 != 0) {
        // 0x800B1890: addiu       $t3, $v1, -0x485
        ctx->r11 = ADD32(ctx->r3, -0X485);
            goto L_800B18B4;
    }
    // 0x800B1890: addiu       $t3, $v1, -0x485
    ctx->r11 = ADD32(ctx->r3, -0X485);
    // 0x800B1894: sltiu       $at, $t3, 0xA
    ctx->r1 = ctx->r11 < 0XA ? 1 : 0;
    // 0x800B1898: beq         $at, $zero, L_800B2920
    if (ctx->r1 == 0) {
        // 0x800B189C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_800B2920;
    }
    // 0x800B189C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B18A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B18A4: addu        $at, $at, $t3
    gpr jr_addend_800B18AC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800B18A8: lw          $t3, -0x7260($at)
    ctx->r11 = ADD32(ctx->r1, -0X7260);
    // 0x800B18AC: jr          $t3
    // 0x800B18B0: nop

    switch (jr_addend_800B18AC >> 2) {
        case 0: goto L_800B208C; break;
        case 1: goto L_800B208C; break;
        case 2: goto L_800B208C; break;
        case 3: goto L_800B208C; break;
        case 4: goto L_800B208C; break;
        case 5: goto L_800B208C; break;
        case 6: goto L_800B208C; break;
        case 7: goto L_800B208C; break;
        case 8: goto L_800B208C; break;
        case 9: goto L_800B208C; break;
        default: switch_error(__func__, 0x800B18AC, 0x80108DA0);
    }
    // 0x800B18B0: nop

L_800B18B4:
    // 0x800B18B4: slti        $at, $v1, 0x402
    ctx->r1 = SIGNED(ctx->r3) < 0X402 ? 1 : 0;
    // 0x800B18B8: bne         $at, $zero, L_800B18D4
    if (ctx->r1 != 0) {
        // 0x800B18BC: addiu       $t4, $v1, -0x3B7
        ctx->r12 = ADD32(ctx->r3, -0X3B7);
            goto L_800B18D4;
    }
    // 0x800B18BC: addiu       $t4, $v1, -0x3B7
    ctx->r12 = ADD32(ctx->r3, -0X3B7);
    // 0x800B18C0: addiu       $at, $zero, 0x459
    ctx->r1 = ADD32(0, 0X459);
    // 0x800B18C4: beq         $v1, $at, L_800B2468
    if (ctx->r3 == ctx->r1) {
        // 0x800B18C8: addiu       $t0, $zero, 0x45A
        ctx->r8 = ADD32(0, 0X45A);
            goto L_800B2468;
    }
    // 0x800B18C8: addiu       $t0, $zero, 0x45A
    ctx->r8 = ADD32(0, 0X45A);
    // 0x800B18CC: b           L_800B2924
    // 0x800B18D0: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
        goto L_800B2924;
    // 0x800B18D0: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
L_800B18D4:
    // 0x800B18D4: sltiu       $at, $t4, 0x4B
    ctx->r1 = ctx->r12 < 0X4B ? 1 : 0;
    // 0x800B18D8: beq         $at, $zero, L_800B2920
    if (ctx->r1 == 0) {
        // 0x800B18DC: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_800B2920;
    }
    // 0x800B18DC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B18E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B18E4: addu        $at, $at, $t4
    gpr jr_addend_800B18EC = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B18E8: lw          $t4, -0x7238($at)
    ctx->r12 = ADD32(ctx->r1, -0X7238);
    // 0x800B18EC: jr          $t4
    // 0x800B18F0: nop

    switch (jr_addend_800B18EC >> 2) {
        case 0: goto L_800B1B1C; break;
        case 1: goto L_800B2920; break;
        case 2: goto L_800B2920; break;
        case 3: goto L_800B208C; break;
        case 4: goto L_800B208C; break;
        case 5: goto L_800B208C; break;
        case 6: goto L_800B208C; break;
        case 7: goto L_800B2920; break;
        case 8: goto L_800B2920; break;
        case 9: goto L_800B2920; break;
        case 10: goto L_800B2920; break;
        case 11: goto L_800B2920; break;
        case 12: goto L_800B2920; break;
        case 13: goto L_800B2920; break;
        case 14: goto L_800B2920; break;
        case 15: goto L_800B2920; break;
        case 16: goto L_800B2920; break;
        case 17: goto L_800B2920; break;
        case 18: goto L_800B2264; break;
        case 19: goto L_800B2920; break;
        case 20: goto L_800B19FC; break;
        case 21: goto L_800B19FC; break;
        case 22: goto L_800B19FC; break;
        case 23: goto L_800B19FC; break;
        case 24: goto L_800B19FC; break;
        case 25: goto L_800B2920; break;
        case 26: goto L_800B2920; break;
        case 27: goto L_800B1B1C; break;
        case 28: goto L_800B1D18; break;
        case 29: goto L_800B2920; break;
        case 30: goto L_800B2400; break;
        case 31: goto L_800B2920; break;
        case 32: goto L_800B2920; break;
        case 33: goto L_800B2920; break;
        case 34: goto L_800B2920; break;
        case 35: goto L_800B2920; break;
        case 36: goto L_800B2920; break;
        case 37: goto L_800B2920; break;
        case 38: goto L_800B2920; break;
        case 39: goto L_800B1B1C; break;
        case 40: goto L_800B2920; break;
        case 41: goto L_800B2920; break;
        case 42: goto L_800B2920; break;
        case 43: goto L_800B24EC; break;
        case 44: goto L_800B24EC; break;
        case 45: goto L_800B24EC; break;
        case 46: goto L_800B2920; break;
        case 47: goto L_800B2920; break;
        case 48: goto L_800B2920; break;
        case 49: goto L_800B2920; break;
        case 50: goto L_800B2920; break;
        case 51: goto L_800B2920; break;
        case 52: goto L_800B22F8; break;
        case 53: goto L_800B2920; break;
        case 54: goto L_800B2920; break;
        case 55: goto L_800B2920; break;
        case 56: goto L_800B2920; break;
        case 57: goto L_800B2920; break;
        case 58: goto L_800B2920; break;
        case 59: goto L_800B2920; break;
        case 60: goto L_800B2920; break;
        case 61: goto L_800B208C; break;
        case 62: goto L_800B208C; break;
        case 63: goto L_800B208C; break;
        case 64: goto L_800B2920; break;
        case 65: goto L_800B2920; break;
        case 66: goto L_800B2920; break;
        case 67: goto L_800B2920; break;
        case 68: goto L_800B2920; break;
        case 69: goto L_800B2920; break;
        case 70: goto L_800B2920; break;
        case 71: goto L_800B2920; break;
        case 72: goto L_800B2920; break;
        case 73: goto L_800B2920; break;
        case 74: goto L_800B2220; break;
        default: switch_error(__func__, 0x800B18EC, 0x80108DC8);
    }
    // 0x800B18F0: nop

L_800B18F4:
    // 0x800B18F4: slti        $at, $v1, 0x206
    ctx->r1 = SIGNED(ctx->r3) < 0X206 ? 1 : 0;
    // 0x800B18F8: bne         $at, $zero, L_800B19C0
    if (ctx->r1 != 0) {
        // 0x800B18FC: slti        $at, $v1, 0x319
        ctx->r1 = SIGNED(ctx->r3) < 0X319 ? 1 : 0;
            goto L_800B19C0;
    }
    // 0x800B18FC: slti        $at, $v1, 0x319
    ctx->r1 = SIGNED(ctx->r3) < 0X319 ? 1 : 0;
    // 0x800B1900: bne         $at, $zero, L_800B1944
    if (ctx->r1 != 0) {
        // 0x800B1904: slti        $at, $v1, 0x366
        ctx->r1 = SIGNED(ctx->r3) < 0X366 ? 1 : 0;
            goto L_800B1944;
    }
    // 0x800B1904: slti        $at, $v1, 0x366
    ctx->r1 = SIGNED(ctx->r3) < 0X366 ? 1 : 0;
    // 0x800B1908: bne         $at, $zero, L_800B1930
    if (ctx->r1 != 0) {
        // 0x800B190C: addiu       $t5, $v1, -0x385
        ctx->r13 = ADD32(ctx->r3, -0X385);
            goto L_800B1930;
    }
    // 0x800B190C: addiu       $t5, $v1, -0x385
    ctx->r13 = ADD32(ctx->r3, -0X385);
    // 0x800B1910: sltiu       $at, $t5, 0xB
    ctx->r1 = ctx->r13 < 0XB ? 1 : 0;
    // 0x800B1914: beq         $at, $zero, L_800B2920
    if (ctx->r1 == 0) {
        // 0x800B1918: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800B2920;
    }
    // 0x800B1918: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800B191C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B1920: addu        $at, $at, $t5
    gpr jr_addend_800B1928 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800B1924: lw          $t5, -0x710C($at)
    ctx->r13 = ADD32(ctx->r1, -0X710C);
    // 0x800B1928: jr          $t5
    // 0x800B192C: nop

    switch (jr_addend_800B1928 >> 2) {
        case 0: goto L_800B1A28; break;
        case 1: goto L_800B1A28; break;
        case 2: goto L_800B2920; break;
        case 3: goto L_800B2920; break;
        case 4: goto L_800B2920; break;
        case 5: goto L_800B2920; break;
        case 6: goto L_800B2920; break;
        case 7: goto L_800B1B1C; break;
        case 8: goto L_800B2920; break;
        case 9: goto L_800B1B1C; break;
        case 10: goto L_800B1BB8; break;
        default: switch_error(__func__, 0x800B1928, 0x80108EF4);
    }
    // 0x800B192C: nop

L_800B1930:
    // 0x800B1930: addiu       $at, $zero, 0x365
    ctx->r1 = ADD32(0, 0X365);
    // 0x800B1934: beql        $v1, $at, L_800B2090
    if (ctx->r3 == ctx->r1) {
        // 0x800B1938: addiu       $at, $zero, 0x485
        ctx->r1 = ADD32(0, 0X485);
            goto L_800B2090;
    }
    goto skip_2;
    // 0x800B1938: addiu       $at, $zero, 0x485
    ctx->r1 = ADD32(0, 0X485);
    skip_2:
    // 0x800B193C: b           L_800B2924
    // 0x800B1940: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
        goto L_800B2924;
    // 0x800B1940: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
L_800B1944:
    // 0x800B1944: slti        $at, $v1, 0x2CD
    ctx->r1 = SIGNED(ctx->r3) < 0X2CD ? 1 : 0;
    // 0x800B1948: bne         $at, $zero, L_800B1970
    if (ctx->r1 != 0) {
        // 0x800B194C: addiu       $t6, $v1, -0x2F1
        ctx->r14 = ADD32(ctx->r3, -0X2F1);
            goto L_800B1970;
    }
    // 0x800B194C: addiu       $t6, $v1, -0x2F1
    ctx->r14 = ADD32(ctx->r3, -0X2F1);
    // 0x800B1950: sltiu       $at, $t6, 0x28
    ctx->r1 = ctx->r14 < 0X28 ? 1 : 0;
    // 0x800B1954: beq         $at, $zero, L_800B2920
    if (ctx->r1 == 0) {
        // 0x800B1958: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B2920;
    }
    // 0x800B1958: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B195C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B1960: addu        $at, $at, $t6
    gpr jr_addend_800B1968 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B1964: lw          $t6, -0x70E0($at)
    ctx->r14 = ADD32(ctx->r1, -0X70E0);
    // 0x800B1968: jr          $t6
    // 0x800B196C: nop

    switch (jr_addend_800B1968 >> 2) {
        case 0: goto L_800B208C; break;
        case 1: goto L_800B2920; break;
        case 2: goto L_800B2920; break;
        case 3: goto L_800B2920; break;
        case 4: goto L_800B2920; break;
        case 5: goto L_800B2920; break;
        case 6: goto L_800B2920; break;
        case 7: goto L_800B2920; break;
        case 8: goto L_800B2920; break;
        case 9: goto L_800B2920; break;
        case 10: goto L_800B2920; break;
        case 11: goto L_800B2920; break;
        case 12: goto L_800B208C; break;
        case 13: goto L_800B2920; break;
        case 14: goto L_800B2920; break;
        case 15: goto L_800B208C; break;
        case 16: goto L_800B208C; break;
        case 17: goto L_800B2920; break;
        case 18: goto L_800B2920; break;
        case 19: goto L_800B2920; break;
        case 20: goto L_800B2920; break;
        case 21: goto L_800B208C; break;
        case 22: goto L_800B2920; break;
        case 23: goto L_800B2920; break;
        case 24: goto L_800B2920; break;
        case 25: goto L_800B2920; break;
        case 26: goto L_800B208C; break;
        case 27: goto L_800B2920; break;
        case 28: goto L_800B2920; break;
        case 29: goto L_800B2920; break;
        case 30: goto L_800B2920; break;
        case 31: goto L_800B2920; break;
        case 32: goto L_800B2920; break;
        case 33: goto L_800B2920; break;
        case 34: goto L_800B2920; break;
        case 35: goto L_800B2920; break;
        case 36: goto L_800B2920; break;
        case 37: goto L_800B2920; break;
        case 38: goto L_800B2920; break;
        case 39: goto L_800B208C; break;
        default: switch_error(__func__, 0x800B1968, 0x80108F20);
    }
    // 0x800B196C: nop

L_800B1970:
    // 0x800B1970: slti        $at, $v1, 0x26C
    ctx->r1 = SIGNED(ctx->r3) < 0X26C ? 1 : 0;
    // 0x800B1974: bne         $at, $zero, L_800B19A0
    if (ctx->r1 != 0) {
        // 0x800B1978: addiu       $t8, $v1, -0x227
        ctx->r24 = ADD32(ctx->r3, -0X227);
            goto L_800B19A0;
    }
    // 0x800B1978: addiu       $t8, $v1, -0x227
    ctx->r24 = ADD32(ctx->r3, -0X227);
    // 0x800B197C: addiu       $t7, $v1, -0x29D
    ctx->r15 = ADD32(ctx->r3, -0X29D);
    // 0x800B1980: sltiu       $at, $t7, 0x30
    ctx->r1 = ctx->r15 < 0X30 ? 1 : 0;
    // 0x800B1984: beq         $at, $zero, L_800B2920
    if (ctx->r1 == 0) {
        // 0x800B1988: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800B2920;
    }
    // 0x800B1988: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800B198C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B1990: addu        $at, $at, $t7
    gpr jr_addend_800B1998 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800B1994: lw          $t7, -0x7040($at)
    ctx->r15 = ADD32(ctx->r1, -0X7040);
    // 0x800B1998: jr          $t7
    // 0x800B199C: nop

    switch (jr_addend_800B1998 >> 2) {
        case 0: goto L_800B27F0; break;
        case 1: goto L_800B2920; break;
        case 2: goto L_800B2920; break;
        case 3: goto L_800B2920; break;
        case 4: goto L_800B2920; break;
        case 5: goto L_800B2920; break;
        case 6: goto L_800B2920; break;
        case 7: goto L_800B2920; break;
        case 8: goto L_800B2920; break;
        case 9: goto L_800B27F0; break;
        case 10: goto L_800B2920; break;
        case 11: goto L_800B27F0; break;
        case 12: goto L_800B2920; break;
        case 13: goto L_800B2920; break;
        case 14: goto L_800B2920; break;
        case 15: goto L_800B2920; break;
        case 16: goto L_800B27F0; break;
        case 17: goto L_800B27F0; break;
        case 18: goto L_800B2920; break;
        case 19: goto L_800B2920; break;
        case 20: goto L_800B27F0; break;
        case 21: goto L_800B2920; break;
        case 22: goto L_800B2920; break;
        case 23: goto L_800B2920; break;
        case 24: goto L_800B2920; break;
        case 25: goto L_800B27F0; break;
        case 26: goto L_800B27F0; break;
        case 27: goto L_800B2920; break;
        case 28: goto L_800B27F0; break;
        case 29: goto L_800B2920; break;
        case 30: goto L_800B2920; break;
        case 31: goto L_800B2920; break;
        case 32: goto L_800B2920; break;
        case 33: goto L_800B2920; break;
        case 34: goto L_800B2920; break;
        case 35: goto L_800B2920; break;
        case 36: goto L_800B2920; break;
        case 37: goto L_800B2920; break;
        case 38: goto L_800B2920; break;
        case 39: goto L_800B2920; break;
        case 40: goto L_800B2920; break;
        case 41: goto L_800B2920; break;
        case 42: goto L_800B2920; break;
        case 43: goto L_800B2920; break;
        case 44: goto L_800B2920; break;
        case 45: goto L_800B2920; break;
        case 46: goto L_800B2920; break;
        case 47: goto L_800B208C; break;
        default: switch_error(__func__, 0x800B1998, 0x80108FC0);
    }
    // 0x800B199C: nop

L_800B19A0:
    // 0x800B19A0: sltiu       $at, $t8, 0x45
    ctx->r1 = ctx->r24 < 0X45 ? 1 : 0;
    // 0x800B19A4: beq         $at, $zero, L_800B2920
    if (ctx->r1 == 0) {
        // 0x800B19A8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800B2920;
    }
    // 0x800B19A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B19AC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800B19B0: addu        $at, $at, $t8
    gpr jr_addend_800B19B8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B19B4: lw          $t8, -0x6F80($at)
    ctx->r24 = ADD32(ctx->r1, -0X6F80);
    // 0x800B19B8: jr          $t8
    // 0x800B19BC: nop

    switch (jr_addend_800B19B8 >> 2) {
        case 0: goto L_800B208C; break;
        case 1: goto L_800B2920; break;
        case 2: goto L_800B2920; break;
        case 3: goto L_800B2920; break;
        case 4: goto L_800B2920; break;
        case 5: goto L_800B27E0; break;
        case 6: goto L_800B27E0; break;
        case 7: goto L_800B2920; break;
        case 8: goto L_800B2920; break;
        case 9: goto L_800B2920; break;
        case 10: goto L_800B2920; break;
        case 11: goto L_800B2920; break;
        case 12: goto L_800B1F38; break;
        case 13: goto L_800B1F38; break;
        case 14: goto L_800B1F38; break;
        case 15: goto L_800B1F38; break;
        case 16: goto L_800B208C; break;
        case 17: goto L_800B2920; break;
        case 18: goto L_800B2348; break;
        case 19: goto L_800B2920; break;
        case 20: goto L_800B23A4; break;
        case 21: goto L_800B2920; break;
        case 22: goto L_800B2920; break;
        case 23: goto L_800B2920; break;
        case 24: goto L_800B2920; break;
        case 25: goto L_800B2920; break;
        case 26: goto L_800B2920; break;
        case 27: goto L_800B2920; break;
        case 28: goto L_800B2920; break;
        case 29: goto L_800B2920; break;
        case 30: goto L_800B2920; break;
        case 31: goto L_800B2920; break;
        case 32: goto L_800B2920; break;
        case 33: goto L_800B2920; break;
        case 34: goto L_800B2920; break;
        case 35: goto L_800B2920; break;
        case 36: goto L_800B2920; break;
        case 37: goto L_800B2920; break;
        case 38: goto L_800B2920; break;
        case 39: goto L_800B2920; break;
        case 40: goto L_800B2920; break;
        case 41: goto L_800B2920; break;
        case 42: goto L_800B2920; break;
        case 43: goto L_800B2920; break;
        case 44: goto L_800B2438; break;
        case 45: goto L_800B2920; break;
        case 46: goto L_800B2920; break;
        case 47: goto L_800B2920; break;
        case 48: goto L_800B2920; break;
        case 49: goto L_800B2920; break;
        case 50: goto L_800B2920; break;
        case 51: goto L_800B1F5C; break;
        case 52: goto L_800B2920; break;
        case 53: goto L_800B2920; break;
        case 54: goto L_800B2920; break;
        case 55: goto L_800B2920; break;
        case 56: goto L_800B1F5C; break;
        case 57: goto L_800B2920; break;
        case 58: goto L_800B2920; break;
        case 59: goto L_800B2920; break;
        case 60: goto L_800B2920; break;
        case 61: goto L_800B2920; break;
        case 62: goto L_800B2920; break;
        case 63: goto L_800B2920; break;
        case 64: goto L_800B2920; break;
        case 65: goto L_800B24EC; break;
        case 66: goto L_800B2920; break;
        case 67: goto L_800B24EC; break;
        case 68: goto L_800B24EC; break;
        default: switch_error(__func__, 0x800B19B8, 0x80109080);
    }
    // 0x800B19BC: nop

L_800B19C0:
    // 0x800B19C0: addiu       $at, $zero, 0x156
    ctx->r1 = ADD32(0, 0X156);
    // 0x800B19C4: beq         $v1, $at, L_800B2494
    if (ctx->r3 == ctx->r1) {
        // 0x800B19C8: addiu       $t4, $zero, 0x155
        ctx->r12 = ADD32(0, 0X155);
            goto L_800B2494;
    }
    // 0x800B19C8: addiu       $t4, $zero, 0x155
    ctx->r12 = ADD32(0, 0X155);
    // 0x800B19CC: addiu       $at, $zero, 0x157
    ctx->r1 = ADD32(0, 0X157);
    // 0x800B19D0: beq         $v1, $at, L_800B2494
    if (ctx->r3 == ctx->r1) {
        // 0x800B19D4: addiu       $at, $zero, 0x197
        ctx->r1 = ADD32(0, 0X197);
            goto L_800B2494;
    }
    // 0x800B19D4: addiu       $at, $zero, 0x197
    ctx->r1 = ADD32(0, 0X197);
    // 0x800B19D8: beq         $v1, $at, L_800B1DF4
    if (ctx->r3 == ctx->r1) {
        // 0x800B19DC: lui         $s3, 0x8022
        ctx->r19 = S32(0X8022 << 16);
            goto L_800B1DF4;
    }
    // 0x800B19DC: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x800B19E0: addiu       $at, $zero, 0x204
    ctx->r1 = ADD32(0, 0X204);
    // 0x800B19E4: beq         $v1, $at, L_800B1F5C
    if (ctx->r3 == ctx->r1) {
        // 0x800B19E8: addiu       $at, $zero, 0x205
        ctx->r1 = ADD32(0, 0X205);
            goto L_800B1F5C;
    }
    // 0x800B19E8: addiu       $at, $zero, 0x205
    ctx->r1 = ADD32(0, 0X205);
    // 0x800B19EC: beq         $v1, $at, L_800B1F5C
    if (ctx->r3 == ctx->r1) {
        // 0x800B19F0: nop
    
            goto L_800B1F5C;
    }
    // 0x800B19F0: nop

    // 0x800B19F4: b           L_800B2924
    // 0x800B19F8: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
        goto L_800B2924;
    // 0x800B19F8: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
L_800B19FC:
    // 0x800B19FC: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B1A00: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B1A04: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800B1A08: jal         0x8009D240
    // 0x800B1A0C: addiu       $a1, $zero, 0x919
    ctx->r5 = ADD32(0, 0X919);
    spawn(rdram, ctx);
        goto after_1;
    // 0x800B1A0C: addiu       $a1, $zero, 0x919
    ctx->r5 = ADD32(0, 0X919);
    after_1:
    // 0x800B1A10: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B1A14: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B1A18: jal         0x80092728
    // 0x800B1A1C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    deletesprite(rdram, ctx);
        goto after_2;
    // 0x800B1A1C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
    // 0x800B1A20: b           L_800B2E78
    // 0x800B1A24: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B1A24: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B1A28:
    // 0x800B1A28: multu       $s0, $a3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1A2C: addiu       $at, $zero, 0x386
    ctx->r1 = ADD32(0, 0X386);
    // 0x800B1A30: mflo        $t1
    ctx->r9 = lo;
    // 0x800B1A34: addu        $s1, $a2, $t1
    ctx->r17 = ADD32(ctx->r6, ctx->r9);
    // 0x800B1A38: lh          $v0, 0xE($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800B1A3C: beq         $v0, $at, L_800B1A4C
    if (ctx->r2 == ctx->r1) {
        // 0x800B1A40: addiu       $at, $zero, 0x385
        ctx->r1 = ADD32(0, 0X385);
            goto L_800B1A4C;
    }
    // 0x800B1A40: addiu       $at, $zero, 0x385
    ctx->r1 = ADD32(0, 0X385);
    // 0x800B1A44: bne         $v0, $at, L_800B1AC8
    if (ctx->r2 != ctx->r1) {
        // 0x800B1A48: nop
    
            goto L_800B1AC8;
    }
    // 0x800B1A48: nop

L_800B1A4C:
    // 0x800B1A4C: lh          $v0, 0x18($s5)
    ctx->r2 = S32(MEM_H(ctx->r21, 0X18));
    // 0x800B1A50: lh          $t5, 0x14($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800B1A54: lw          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X0));
    // 0x800B1A58: sra         $t2, $v0, 2
    ctx->r10 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800B1A5C: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800B1A60: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B1A64: sh          $t4, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r12;
    // 0x800B1A68: lh          $t6, 0x14($s5)
    ctx->r14 = S32(MEM_H(ctx->r21, 0X14));
    // 0x800B1A6C: lw          $t3, 0x4($s1)
    ctx->r11 = S32(MEM_W(ctx->r17, 0X4));
    // 0x800B1A70: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B1A74: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x800B1A78: addiu       $t9, $t8, -0x400
    ctx->r25 = ADD32(ctx->r24, -0X400);
    // 0x800B1A7C: sh          $t9, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r25;
    // 0x800B1A80: lw          $t2, 0x4($s5)
    ctx->r10 = S32(MEM_W(ctx->r21, 0X4));
    // 0x800B1A84: lw          $t0, 0x0($s5)
    ctx->r8 = S32(MEM_W(ctx->r21, 0X0));
    // 0x800B1A88: subu        $a1, $t2, $t3
    ctx->r5 = SUB32(ctx->r10, ctx->r11);
    // 0x800B1A8C: jal         0x80092024
    // 0x800B1A90: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    getangle(rdram, ctx);
        goto after_3;
    // 0x800B1A90: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    after_3:
    // 0x800B1A94: addiu       $t4, $v0, -0x200
    ctx->r12 = ADD32(ctx->r2, -0X200);
    // 0x800B1A98: sh          $t4, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r12;
    // 0x800B1A9C: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x800B1AA0: lw          $t6, 0xB7C($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, 0XB7C));
    // 0x800B1AA4: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B1AA8: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B1AAC: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800B1AB0: beq         $at, $zero, L_800B2E74
    if (ctx->r1 == 0) {
        // 0x800B1AB4: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800B2E74;
    }
    // 0x800B1AB4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800B1AB8: jal         0x80059034
    // 0x800B1ABC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    spritesound(rdram, ctx);
        goto after_4;
    // 0x800B1ABC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_4:
    // 0x800B1AC0: b           L_800B2E78
    // 0x800B1AC4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B1AC4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B1AC8:
    // 0x800B1AC8: jal         0x8009800C
    // 0x800B1ACC: nop

    krand2(rdram, ctx);
        goto after_5;
    // 0x800B1ACC: nop

    after_5:
    // 0x800B1AD0: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x800B1AD4: beq         $t7, $zero, L_800B1AEC
    if (ctx->r15 == 0) {
        // 0x800B1AD8: addiu       $t8, $zero, 0xA4
        ctx->r24 = ADD32(0, 0XA4);
            goto L_800B1AEC;
    }
    // 0x800B1AD8: addiu       $t8, $zero, 0xA4
    ctx->r24 = ADD32(0, 0XA4);
    // 0x800B1ADC: sh          $t8, 0x18($s5)
    MEM_H(0X18, ctx->r21) = ctx->r24;
    // 0x800B1AE0: lh          $t9, 0x14($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800B1AE4: b           L_800B2E74
    // 0x800B1AE8: sh          $t9, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r25;
        goto L_800B2E74;
    // 0x800B1AE8: sh          $t9, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r25;
L_800B1AEC:
    // 0x800B1AEC: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B1AF0: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B1AF4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800B1AF8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B1AFC: jal         0x8009A2B0
    // 0x800B1B00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    lotsofglass(rdram, ctx);
        goto after_6;
    // 0x800B1B00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x800B1B04: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B1B08: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B1B0C: jal         0x80092728
    // 0x800B1B10: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    deletesprite(rdram, ctx);
        goto after_7;
    // 0x800B1B10: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_7:
    // 0x800B1B14: b           L_800B2E78
    // 0x800B1B18: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B1B18: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B1B1C:
    // 0x800B1B1C: multu       $s0, $a3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1B20: sll         $t4, $s6, 3
    ctx->r12 = S32(ctx->r22 << 3);
    // 0x800B1B24: addu        $t4, $t4, $s6
    ctx->r12 = ADD32(ctx->r12, ctx->r22);
    // 0x800B1B28: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x800B1B2C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x800B1B30: addiu       $t6, $t6, -0x5C00
    ctx->r14 = ADD32(ctx->r14, -0X5C00);
    // 0x800B1B34: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800B1B38: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x800B1B3C: mflo        $t2
    ctx->r10 = lo;
    // 0x800B1B40: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x800B1B44: lh          $v1, 0xE($t3)
    ctx->r3 = S32(MEM_H(ctx->r11, 0XE));
    // 0x800B1B48: beq         $v1, $at, L_800B1B80
    if (ctx->r3 == ctx->r1) {
        // 0x800B1B4C: addiu       $at, $zero, 0x3D5
        ctx->r1 = ADD32(0, 0X3D5);
            goto L_800B1B80;
    }
    // 0x800B1B4C: addiu       $at, $zero, 0x3D5
    ctx->r1 = ADD32(0, 0X3D5);
    // 0x800B1B50: beq         $v1, $at, L_800B1B80
    if (ctx->r3 == ctx->r1) {
        // 0x800B1B54: addiu       $at, $zero, 0x659
        ctx->r1 = ADD32(0, 0X659);
            goto L_800B1B80;
    }
    // 0x800B1B54: addiu       $at, $zero, 0x659
    ctx->r1 = ADD32(0, 0X659);
    // 0x800B1B58: beq         $v1, $at, L_800B1B80
    if (ctx->r3 == ctx->r1) {
        // 0x800B1B5C: addiu       $at, $zero, 0x686
        ctx->r1 = ADD32(0, 0X686);
            goto L_800B1B80;
    }
    // 0x800B1B5C: addiu       $at, $zero, 0x686
    ctx->r1 = ADD32(0, 0X686);
    // 0x800B1B60: beq         $v1, $at, L_800B1B80
    if (ctx->r3 == ctx->r1) {
        // 0x800B1B64: addiu       $at, $zero, 0xA27
        ctx->r1 = ADD32(0, 0XA27);
            goto L_800B1B80;
    }
    // 0x800B1B64: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
    // 0x800B1B68: beq         $v1, $at, L_800B1B80
    if (ctx->r3 == ctx->r1) {
        // 0x800B1B6C: addiu       $at, $zero, 0xA2D
        ctx->r1 = ADD32(0, 0XA2D);
            goto L_800B1B80;
    }
    // 0x800B1B6C: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x800B1B70: beq         $v1, $at, L_800B1B80
    if (ctx->r3 == ctx->r1) {
        // 0x800B1B74: addiu       $at, $zero, 0xE32
        ctx->r1 = ADD32(0, 0XE32);
            goto L_800B1B80;
    }
    // 0x800B1B74: addiu       $at, $zero, 0xE32
    ctx->r1 = ADD32(0, 0XE32);
    // 0x800B1B78: bnel        $v1, $at, L_800B2E78
    if (ctx->r3 != ctx->r1) {
        // 0x800B1B7C: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_3;
    // 0x800B1B7C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_3:
L_800B1B80:
    // 0x800B1B80: lw          $t5, 0x30($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X30));
    // 0x800B1B84: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B1B88: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B1B8C: bne         $t5, $zero, L_800B2E74
    if (ctx->r13 != 0) {
        // 0x800B1B90: sra         $t0, $a0, 16
        ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
            goto L_800B2E74;
    }
    // 0x800B1B90: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B1B94: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B1B98: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    // 0x800B1B9C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800B1BA0: andi        $t8, $t7, 0xFEFE
    ctx->r24 = ctx->r15 & 0XFEFE;
    // 0x800B1BA4: sh          $t8, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r24;
    // 0x800B1BA8: jal         0x8009D240
    // 0x800B1BAC: addiu       $a1, $zero, 0x8DE
    ctx->r5 = ADD32(0, 0X8DE);
    spawn(rdram, ctx);
        goto after_8;
    // 0x800B1BAC: addiu       $a1, $zero, 0x8DE
    ctx->r5 = ADD32(0, 0X8DE);
    after_8:
    // 0x800B1BB0: b           L_800B2E78
    // 0x800B1BB4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B1BB4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B1BB8:
    // 0x800B1BB8: multu       $s0, $a3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1BBC: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x800B1BC0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B1BC4: mflo        $t1
    ctx->r9 = lo;
    // 0x800B1BC8: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x800B1BCC: lh          $v1, 0xE($t2)
    ctx->r3 = S32(MEM_H(ctx->r10, 0XE));
    // 0x800B1BD0: beq         $v1, $at, L_800B1C08
    if (ctx->r3 == ctx->r1) {
        // 0x800B1BD4: addiu       $at, $zero, 0x3D5
        ctx->r1 = ADD32(0, 0X3D5);
            goto L_800B1C08;
    }
    // 0x800B1BD4: addiu       $at, $zero, 0x3D5
    ctx->r1 = ADD32(0, 0X3D5);
    // 0x800B1BD8: beq         $v1, $at, L_800B1C08
    if (ctx->r3 == ctx->r1) {
        // 0x800B1BDC: addiu       $at, $zero, 0x659
        ctx->r1 = ADD32(0, 0X659);
            goto L_800B1C08;
    }
    // 0x800B1BDC: addiu       $at, $zero, 0x659
    ctx->r1 = ADD32(0, 0X659);
    // 0x800B1BE0: beq         $v1, $at, L_800B1C08
    if (ctx->r3 == ctx->r1) {
        // 0x800B1BE4: addiu       $at, $zero, 0x686
        ctx->r1 = ADD32(0, 0X686);
            goto L_800B1C08;
    }
    // 0x800B1BE4: addiu       $at, $zero, 0x686
    ctx->r1 = ADD32(0, 0X686);
    // 0x800B1BE8: beq         $v1, $at, L_800B1C08
    if (ctx->r3 == ctx->r1) {
        // 0x800B1BEC: addiu       $at, $zero, 0xA27
        ctx->r1 = ADD32(0, 0XA27);
            goto L_800B1C08;
    }
    // 0x800B1BEC: addiu       $at, $zero, 0xA27
    ctx->r1 = ADD32(0, 0XA27);
    // 0x800B1BF0: beq         $v1, $at, L_800B1C08
    if (ctx->r3 == ctx->r1) {
        // 0x800B1BF4: addiu       $at, $zero, 0xA2D
        ctx->r1 = ADD32(0, 0XA2D);
            goto L_800B1C08;
    }
    // 0x800B1BF4: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x800B1BF8: beq         $v1, $at, L_800B1C08
    if (ctx->r3 == ctx->r1) {
        // 0x800B1BFC: addiu       $at, $zero, 0xE32
        ctx->r1 = ADD32(0, 0XE32);
            goto L_800B1C08;
    }
    // 0x800B1BFC: addiu       $at, $zero, 0xE32
    ctx->r1 = ADD32(0, 0XE32);
    // 0x800B1C00: bnel        $v1, $at, L_800B2E78
    if (ctx->r3 != ctx->r1) {
        // 0x800B1C04: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_4;
    // 0x800B1C04: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_4:
L_800B1C08:
    // 0x800B1C08: jal         0x8009800C
    // 0x800B1C0C: nop

    krand2(rdram, ctx);
        goto after_9;
    // 0x800B1C0C: nop

    after_9:
    // 0x800B1C10: jal         0x8009800C
    // 0x800B1C14: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    krand2(rdram, ctx);
        goto after_10;
    // 0x800B1C14: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_10:
    // 0x800B1C18: jal         0x8009800C
    // 0x800B1C1C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_11;
    // 0x800B1C1C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_11:
    // 0x800B1C20: jal         0x8009800C
    // 0x800B1C24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_12;
    // 0x800B1C24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_12:
    // 0x800B1C28: jal         0x8009800C
    // 0x800B1C2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_13;
    // 0x800B1C2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_13:
    // 0x800B1C30: lw          $t4, 0x78($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800B1C34: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x800B1C38: lw          $t3, 0x8($s5)
    ctx->r11 = S32(MEM_W(ctx->r21, 0X8));
    // 0x800B1C3C: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800B1C40: andi        $t5, $s2, 0x3
    ctx->r13 = ctx->r18 & 0X3;
    // 0x800B1C44: addiu       $t7, $t5, 0x968
    ctx->r15 = ADD32(ctx->r13, 0X968);
    // 0x800B1C48: lh          $t5, 0x1C($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0X1C));
    // 0x800B1C4C: mfhi        $t6
    ctx->r14 = hi;
    // 0x800B1C50: subu        $a3, $t3, $t6
    ctx->r7 = SUB32(ctx->r11, ctx->r14);
    // 0x800B1C54: andi        $t3, $v0, 0xFFF
    ctx->r11 = ctx->r2 & 0XFFF;
    // 0x800B1C58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800B1C5C: addiu       $t8, $zero, -0x8
    ctx->r24 = ADD32(0, -0X8);
    // 0x800B1C60: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x800B1C64: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800B1C68: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800B1C6C: negu        $t6, $t3
    ctx->r14 = SUB32(0, ctx->r11);
    // 0x800B1C70: andi        $t2, $s0, 0x3F
    ctx->r10 = ctx->r16 & 0X3F;
    // 0x800B1C74: sra         $t7, $t5, 2
    ctx->r15 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800B1C78: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800B1C7C: addiu       $t4, $t2, 0x40
    ctx->r12 = ADD32(ctx->r10, 0X40);
    // 0x800B1C80: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800B1C84: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
    // 0x800B1C88: andi        $t1, $s1, 0x7FF
    ctx->r9 = ctx->r17 & 0X7FF;
    // 0x800B1C8C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800B1C90: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B1C94: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800B1C98: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800B1C9C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800B1CA0: lh          $a0, 0x10($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B1CA4: lw          $a1, 0x0($s5)
    ctx->r5 = S32(MEM_W(ctx->r21, 0X0));
    // 0x800B1CA8: lw          $a2, 0x4($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X4));
    // 0x800B1CAC: jal         0x8009B028
    // 0x800B1CB0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    EGS(rdram, ctx);
        goto after_14;
    // 0x800B1CB0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    after_14:
    // 0x800B1CB4: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800B1CB8: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800B1CBC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B1CC0: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800B1CC4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B1CC8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B1CCC: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x800B1CD0: sll         $t4, $s3, 16
    ctx->r12 = S32(ctx->r19 << 16);
    // 0x800B1CD4: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800B1CD8: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x800B1CDC: sra         $s3, $t4, 16
    ctx->r19 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800B1CE0: sb          $t1, 0x6BCD($at)
    MEM_B(0X6BCD, ctx->r1) = ctx->r9;
    // 0x800B1CE4: slti        $at, $s3, 0x40
    ctx->r1 = SIGNED(ctx->r19) < 0X40 ? 1 : 0;
    // 0x800B1CE8: bne         $at, $zero, L_800B1C08
    if (ctx->r1 != 0) {
        // 0x800B1CEC: sh          $v0, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r2;
            goto L_800B1C08;
    }
    // 0x800B1CEC: sh          $v0, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r2;
    // 0x800B1CF0: lh          $t5, 0xE($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0XE));
    // 0x800B1CF4: addiu       $at, $zero, 0x38F
    ctx->r1 = ADD32(0, 0X38F);
    // 0x800B1CF8: addiu       $t6, $zero, 0x3AB
    ctx->r14 = ADD32(0, 0X3AB);
    // 0x800B1CFC: bnel        $t5, $at, L_800B1D0C
    if (ctx->r13 != ctx->r1) {
        // 0x800B1D00: lh          $t7, 0xC($s5)
        ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
            goto L_800B1D0C;
    }
    goto skip_5;
    // 0x800B1D00: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
    skip_5:
    // 0x800B1D04: sh          $t6, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r14;
    // 0x800B1D08: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
L_800B1D0C:
    // 0x800B1D0C: andi        $t8, $t7, 0xFEFE
    ctx->r24 = ctx->r15 & 0XFEFE;
    // 0x800B1D10: b           L_800B2E74
    // 0x800B1D14: sh          $t8, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r24;
        goto L_800B2E74;
    // 0x800B1D14: sh          $t8, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r24;
L_800B1D18:
    // 0x800B1D18: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800B1D1C:
    // 0x800B1D1C: jal         0x8009800C
    // 0x800B1D20: nop

    krand2(rdram, ctx);
        goto after_15;
    // 0x800B1D20: nop

    after_15:
    // 0x800B1D24: jal         0x8009800C
    // 0x800B1D28: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_16;
    // 0x800B1D28: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_16:
    // 0x800B1D2C: jal         0x8009800C
    // 0x800B1D30: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_17;
    // 0x800B1D30: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_17:
    // 0x800B1D34: jal         0x8009800C
    // 0x800B1D38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_18;
    // 0x800B1D38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_18:
    // 0x800B1D3C: andi        $t9, $s2, 0xF
    ctx->r25 = ctx->r18 & 0XF;
    // 0x800B1D40: addiu       $t0, $t9, 0x960
    ctx->r8 = ADD32(ctx->r25, 0X960);
    // 0x800B1D44: lh          $t9, 0x1C($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0X1C));
    // 0x800B1D48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B1D4C: addiu       $t1, $zero, -0x8
    ctx->r9 = ADD32(0, -0X8);
    // 0x800B1D50: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x800B1D54: andi        $t7, $v0, 0xFFF
    ctx->r15 = ctx->r2 & 0XFFF;
    // 0x800B1D58: lw          $a3, 0x8($s5)
    ctx->r7 = S32(MEM_W(ctx->r21, 0X8));
    // 0x800B1D5C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800B1D60: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800B1D64: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B1D68: andi        $t5, $s0, 0x3F
    ctx->r13 = ctx->r16 & 0X3F;
    // 0x800B1D6C: sra         $t0, $t9, 2
    ctx->r8 = S32(SIGNED(ctx->r25) >> 2);
    // 0x800B1D70: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x800B1D74: addiu       $t6, $t5, 0x40
    ctx->r14 = ADD32(ctx->r13, 0X40);
    // 0x800B1D78: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800B1D7C: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x800B1D80: andi        $t3, $s1, 0x7FF
    ctx->r11 = ctx->r17 & 0X7FF;
    // 0x800B1D84: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800B1D88: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B1D8C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800B1D90: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B1D94: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800B1D98: lh          $a0, 0x10($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B1D9C: lw          $a1, 0x0($s5)
    ctx->r5 = S32(MEM_W(ctx->r21, 0X0));
    // 0x800B1DA0: lw          $a2, 0x4($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X4));
    // 0x800B1DA4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800B1DA8: jal         0x8009B028
    // 0x800B1DAC: addiu       $a3, $a3, -0x800
    ctx->r7 = ADD32(ctx->r7, -0X800);
    EGS(rdram, ctx);
        goto after_19;
    // 0x800B1DAC: addiu       $a3, $a3, -0x800
    ctx->r7 = ADD32(ctx->r7, -0X800);
    after_19:
    // 0x800B1DB0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B1DB4: sll         $t4, $s3, 16
    ctx->r12 = S32(ctx->r19 << 16);
    // 0x800B1DB8: sra         $s3, $t4, 16
    ctx->r19 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800B1DBC: slti        $at, $s3, 0x6
    ctx->r1 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // 0x800B1DC0: bne         $at, $zero, L_800B1D1C
    if (ctx->r1 != 0) {
        // 0x800B1DC4: nop
    
            goto L_800B1D1C;
    }
    // 0x800B1DC4: nop

    // 0x800B1DC8: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B1DCC: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B1DD0: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800B1DD4: jal         0x80059034
    // 0x800B1DD8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    spritesound(rdram, ctx);
        goto after_20;
    // 0x800B1DD8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_20:
    // 0x800B1DDC: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B1DE0: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B1DE4: jal         0x80092728
    // 0x800B1DE8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    deletesprite(rdram, ctx);
        goto after_21;
    // 0x800B1DE8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_21:
    // 0x800B1DEC: b           L_800B2E78
    // 0x800B1DF0: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B1DF0: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B1DF4:
    // 0x800B1DF4: lh          $t0, 0x10($s5)
    ctx->r8 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B1DF8: addiu       $s3, $s3, -0x1988
    ctx->r19 = ADD32(ctx->r19, -0X1988);
    // 0x800B1DFC: lh          $t9, 0xC($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B1E00: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B1E04: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1E08: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800B1E0C: addu        $v0, $s3, $t1
    ctx->r2 = ADD32(ctx->r19, ctx->r9);
    // 0x800B1E10: lh          $t2, 0x14($v0)
    ctx->r10 = S32(MEM_H(ctx->r2, 0X14));
    // 0x800B1E14: addiu       $t7, $zero, 0x19B
    ctx->r15 = ADD32(0, 0X19B);
    // 0x800B1E18: addiu       $at, $zero, 0x19C
    ctx->r1 = ADD32(0, 0X19C);
    // 0x800B1E1C: andi        $t8, $t9, 0xFEFE
    ctx->r24 = ctx->r25 & 0XFEFE;
    // 0x800B1E20: sh          $t7, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r15;
    // 0x800B1E24: bne         $t2, $at, L_800B1E34
    if (ctx->r10 != ctx->r1) {
        // 0x800B1E28: sh          $t8, 0xC($s5)
        MEM_H(0XC, ctx->r21) = ctx->r24;
            goto L_800B1E34;
    }
    // 0x800B1E28: sh          $t8, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r24;
    // 0x800B1E2C: addiu       $t4, $zero, 0x1A0
    ctx->r12 = ADD32(0, 0X1A0);
    // 0x800B1E30: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
L_800B1E34:
    // 0x800B1E34: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B1E38: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B1E3C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800B1E40: jal         0x80059034
    // 0x800B1E44: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    spritesound(rdram, ctx);
        goto after_22;
    // 0x800B1E44: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_22:
    // 0x800B1E48: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
L_800B1E4C:
    // 0x800B1E4C: jal         0x8009800C
    // 0x800B1E50: nop

    krand2(rdram, ctx);
        goto after_23;
    // 0x800B1E50: nop

    after_23:
    // 0x800B1E54: jal         0x8009800C
    // 0x800B1E58: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_24;
    // 0x800B1E58: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    after_24:
    // 0x800B1E5C: jal         0x8009800C
    // 0x800B1E60: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_25;
    // 0x800B1E60: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_25:
    // 0x800B1E64: jal         0x8009800C
    // 0x800B1E68: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    krand2(rdram, ctx);
        goto after_26;
    // 0x800B1E68: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_26:
    // 0x800B1E6C: jal         0x8009800C
    // 0x800B1E70: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_27;
    // 0x800B1E70: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_27:
    // 0x800B1E74: jal         0x8009800C
    // 0x800B1E78: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_28;
    // 0x800B1E78: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_28:
    // 0x800B1E7C: jal         0x8009800C
    // 0x800B1E80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_29;
    // 0x800B1E80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_29:
    // 0x800B1E84: lw          $t0, 0x78($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800B1E88: lw          $t8, 0x8($s5)
    ctx->r24 = S32(MEM_W(ctx->r21, 0X8));
    // 0x800B1E8C: lw          $t6, 0x0($s5)
    ctx->r14 = S32(MEM_W(ctx->r21, 0X0));
    // 0x800B1E90: lw          $t9, 0x4($s5)
    ctx->r25 = S32(MEM_W(ctx->r21, 0X4));
    // 0x800B1E94: andi        $t2, $s2, 0xF
    ctx->r10 = ctx->r18 & 0XF;
    // 0x800B1E98: andi        $t1, $t0, 0x1FFF
    ctx->r9 = ctx->r8 & 0X1FFF;
    // 0x800B1E9C: addiu       $t4, $t2, 0x956
    ctx->r12 = ADD32(ctx->r10, 0X956);
    // 0x800B1EA0: andi        $t5, $s4, 0xFF
    ctx->r13 = ctx->r20 & 0XFF;
    // 0x800B1EA4: andi        $t7, $s3, 0xFF
    ctx->r15 = ctx->r19 & 0XFF;
    // 0x800B1EA8: subu        $a3, $t8, $t1
    ctx->r7 = SUB32(ctx->r24, ctx->r9);
    // 0x800B1EAC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x800B1EB0: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    // 0x800B1EB4: andi        $t9, $s0, 0x3F
    ctx->r25 = ctx->r16 & 0X3F;
    // 0x800B1EB8: addiu       $t1, $zero, -0x200
    ctx->r9 = ADD32(0, -0X200);
    // 0x800B1EBC: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x800B1EC0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800B1EC4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800B1EC8: subu        $t2, $t1, $t8
    ctx->r10 = SUB32(ctx->r9, ctx->r24);
    // 0x800B1ECC: addiu       $t0, $t9, 0x40
    ctx->r8 = ADD32(ctx->r25, 0X40);
    // 0x800B1ED0: andi        $t7, $s1, 0x7FF
    ctx->r15 = ctx->r17 & 0X7FF;
    // 0x800B1ED4: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800B1ED8: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x800B1EDC: addiu       $t3, $zero, -0x8
    ctx->r11 = ADD32(0, -0X8);
    // 0x800B1EE0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800B1EE4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800B1EE8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800B1EEC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800B1EF0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800B1EF4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B1EF8: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x800B1EFC: addiu       $a2, $a2, -0x80
    ctx->r6 = ADD32(ctx->r6, -0X80);
    // 0x800B1F00: addiu       $a1, $a1, -0x80
    ctx->r5 = ADD32(ctx->r5, -0X80);
    // 0x800B1F04: addiu       $a3, $a3, -0x800
    ctx->r7 = ADD32(ctx->r7, -0X800);
    // 0x800B1F08: lh          $a0, 0x10($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B1F0C: jal         0x8009B028
    // 0x800B1F10: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    EGS(rdram, ctx);
        goto after_30;
    // 0x800B1F10: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    after_30:
    // 0x800B1F14: lh          $s4, 0x9E($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x800B1F18: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B1F1C: sll         $t3, $s4, 16
    ctx->r11 = S32(ctx->r20 << 16);
    // 0x800B1F20: sra         $t5, $t3, 16
    ctx->r13 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800B1F24: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x800B1F28: bne         $at, $zero, L_800B1E4C
    if (ctx->r1 != 0) {
        // 0x800B1F2C: sh          $t5, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r13;
            goto L_800B1E4C;
    }
    // 0x800B1F2C: sh          $t5, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r13;
    // 0x800B1F30: b           L_800B2E78
    // 0x800B1F34: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B1F34: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B1F38:
    // 0x800B1F38: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B1F3C: addiu       $t6, $zero, 0x237
    ctx->r14 = ADD32(0, 0X237);
    // 0x800B1F40: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B1F44: sh          $t6, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r14;
    // 0x800B1F48: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B1F4C: jal         0x8009D240
    // 0x800B1F50: addiu       $a1, $zero, 0x399
    ctx->r5 = ADD32(0, 0X399);
    spawn(rdram, ctx);
        goto after_31;
    // 0x800B1F50: addiu       $a1, $zero, 0x399
    ctx->r5 = ADD32(0, 0X399);
    after_31:
    // 0x800B1F54: b           L_800B2E78
    // 0x800B1F58: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B1F58: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B1F5C:
    // 0x800B1F5C: multu       $s0, $a3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1F60: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800B1F64: lh          $t8, -0x3036($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X3036));
    // 0x800B1F68: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800B1F6C: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x800B1F70: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800B1F74: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800B1F78: lw          $t4, -0x1700($t4)
    ctx->r12 = S32(MEM_W(ctx->r12, -0X1700));
    // 0x800B1F7C: addiu       $s3, $s3, -0x1988
    ctx->r19 = ADD32(ctx->r19, -0X1988);
    // 0x800B1F80: mflo        $t9
    ctx->r25 = lo;
    // 0x800B1F84: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x800B1F88: lh          $t1, 0x22($t0)
    ctx->r9 = S32(MEM_H(ctx->r8, 0X22));
    // 0x800B1F8C: beql        $t1, $t4, L_800B2E78
    if (ctx->r9 == ctx->r12) {
        // 0x800B1F90: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_6;
    // 0x800B1F90: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_6:
    // 0x800B1F94: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
L_800B1F98:
    // 0x800B1F98: jal         0x8009800C
    // 0x800B1F9C: nop

    krand2(rdram, ctx);
        goto after_32;
    // 0x800B1F9C: nop

    after_32:
    // 0x800B1FA0: jal         0x8009800C
    // 0x800B1FA4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_33;
    // 0x800B1FA4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_33:
    // 0x800B1FA8: jal         0x8009800C
    // 0x800B1FAC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_34;
    // 0x800B1FAC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_34:
    // 0x800B1FB0: jal         0x8009800C
    // 0x800B1FB4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_35;
    // 0x800B1FB4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_35:
    // 0x800B1FB8: lh          $a0, 0x10($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B1FBC: lh          $s4, 0x9E($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x800B1FC0: andi        $t9, $s2, 0xF
    ctx->r25 = ctx->r18 & 0XF;
    // 0x800B1FC4: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x800B1FC8: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800B1FCC: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800B1FD0: addu        $t5, $s3, $t3
    ctx->r13 = ADD32(ctx->r19, ctx->r11);
    // 0x800B1FD4: lw          $t6, 0x4($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X4));
    // 0x800B1FD8: sll         $t7, $s4, 9
    ctx->r15 = S32(ctx->r20 << 9);
    // 0x800B1FDC: addiu       $t0, $t9, 0x960
    ctx->r8 = ADD32(ctx->r25, 0X960);
    // 0x800B1FE0: subu        $a3, $t6, $t7
    ctx->r7 = SUB32(ctx->r14, ctx->r15);
    // 0x800B1FE4: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x800B1FE8: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x800B1FEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B1FF0: andi        $t3, $s0, 0x7F
    ctx->r11 = ctx->r16 & 0X7F;
    // 0x800B1FF4: addiu       $t5, $t3, 0x40
    ctx->r13 = ADD32(ctx->r11, 0X40);
    // 0x800B1FF8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800B1FFC: subu        $t9, $t7, $t6
    ctx->r25 = SUB32(ctx->r15, ctx->r14);
    // 0x800B2000: addiu       $t8, $zero, -0x8
    ctx->r24 = ADD32(0, -0X8);
    // 0x800B2004: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800B2008: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x800B200C: andi        $t4, $s1, 0x7FF
    ctx->r12 = ctx->r17 & 0X7FF;
    // 0x800B2010: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800B2014: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800B2018: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800B201C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800B2020: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800B2024: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800B2028: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800B202C: addiu       $a3, $a3, -0xC00
    ctx->r7 = ADD32(ctx->r7, -0XC00);
    // 0x800B2030: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800B2034: lw          $a1, 0x0($s5)
    ctx->r5 = S32(MEM_W(ctx->r21, 0X0));
    // 0x800B2038: jal         0x8009B028
    // 0x800B203C: lw          $a2, 0x4($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X4));
    EGS(rdram, ctx);
        goto after_36;
    // 0x800B203C: lw          $a2, 0x4($s5)
    ctx->r6 = S32(MEM_W(ctx->r21, 0X4));
    after_36:
    // 0x800B2040: lh          $s4, 0x9E($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x800B2044: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B2048: sll         $t8, $s4, 16
    ctx->r24 = S32(ctx->r20 << 16);
    // 0x800B204C: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800B2050: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x800B2054: bne         $at, $zero, L_800B1F98
    if (ctx->r1 != 0) {
        // 0x800B2058: sh          $t2, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r10;
            goto L_800B1F98;
    }
    // 0x800B2058: sh          $t2, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r10;
    // 0x800B205C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2060: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2064: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800B2068: jal         0x8009D240
    // 0x800B206C: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    spawn(rdram, ctx);
        goto after_37;
    // 0x800B206C: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    after_37:
    // 0x800B2070: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2074: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2078: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800B207C: jal         0x80092728
    // 0x800B2080: sh          $v0, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r2;
    deletesprite(rdram, ctx);
        goto after_38;
    // 0x800B2080: sh          $v0, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r2;
    after_38:
    // 0x800B2084: b           L_800B2E78
    // 0x800B2088: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B2088: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B208C:
    // 0x800B208C: addiu       $at, $zero, 0x485
    ctx->r1 = ADD32(0, 0X485);
L_800B2090:
    // 0x800B2090: bnel        $a0, $at, L_800B20C4
    if (ctx->r4 != ctx->r1) {
        // 0x800B2094: addiu       $at, $zero, 0x2F1
        ctx->r1 = ADD32(0, 0X2F1);
            goto L_800B20C4;
    }
    goto skip_7;
    // 0x800B2094: addiu       $at, $zero, 0x2F1
    ctx->r1 = ADD32(0, 0X2F1);
    skip_7:
    // 0x800B2098: jal         0x8009800C
    // 0x800B209C: nop

    krand2(rdram, ctx);
        goto after_39;
    // 0x800B209C: nop

    after_39:
    // 0x800B20A0: andi        $a1, $v0, 0x3
    ctx->r5 = ctx->r2 & 0X3;
    // 0x800B20A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B20A8: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x800B20AC: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800B20B0: jal         0x800762BC
    // 0x800B20B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    lotsofmoney(rdram, ctx);
        goto after_40;
    // 0x800B20B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_40:
    // 0x800B20B8: b           L_800B212C
    // 0x800B20BC: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
        goto L_800B212C;
    // 0x800B20BC: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B20C0: addiu       $at, $zero, 0x2F1
    ctx->r1 = ADD32(0, 0X2F1);
L_800B20C4:
    // 0x800B20C4: beq         $a0, $at, L_800B20D8
    if (ctx->r4 == ctx->r1) {
        // 0x800B20C8: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800B20D8;
    }
    // 0x800B20C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B20CC: addiu       $at, $zero, 0x365
    ctx->r1 = ADD32(0, 0X365);
    // 0x800B20D0: bnel        $a0, $at, L_800B210C
    if (ctx->r4 != ctx->r1) {
        // 0x800B20D4: addiu       $at, $zero, 0x2FD
        ctx->r1 = ADD32(0, 0X2FD);
            goto L_800B210C;
    }
    goto skip_8;
    // 0x800B20D4: addiu       $at, $zero, 0x2FD
    ctx->r1 = ADD32(0, 0X2FD);
    skip_8:
L_800B20D8:
    // 0x800B20D8: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B20DC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B20E0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B20E4: jal         0x8009AB30
    // 0x800B20E8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    lotsofcolourglass(rdram, ctx);
        goto after_41;
    // 0x800B20E8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_41:
    // 0x800B20EC: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B20F0: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B20F4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800B20F8: jal         0x80059034
    // 0x800B20FC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    spritesound(rdram, ctx);
        goto after_42;
    // 0x800B20FC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_42:
    // 0x800B2100: b           L_800B212C
    // 0x800B2104: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
        goto L_800B212C;
    // 0x800B2104: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2108: addiu       $at, $zero, 0x2FD
    ctx->r1 = ADD32(0, 0X2FD);
L_800B210C:
    // 0x800B210C: bne         $a0, $at, L_800B2128
    if (ctx->r4 != ctx->r1) {
        // 0x800B2110: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800B2128;
    }
    // 0x800B2110: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B2114: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2118: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B211C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800B2120: jal         0x8009A2B0
    // 0x800B2124: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    lotsofglass(rdram, ctx);
        goto after_43;
    // 0x800B2124: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_43:
L_800B2128:
    // 0x800B2128: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
L_800B212C:
    // 0x800B212C: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2130: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800B2134: jal         0x80059034
    // 0x800B2138: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    spritesound(rdram, ctx);
        goto after_44;
    // 0x800B2138: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_44:
    // 0x800B213C: jal         0x8009800C
    // 0x800B2140: nop

    krand2(rdram, ctx);
        goto after_45;
    // 0x800B2140: nop

    after_45:
    // 0x800B2144: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2148: andi        $t2, $v0, 0x7FF
    ctx->r10 = ctx->r2 & 0X7FF;
    // 0x800B214C: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2150: sh          $t2, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r10;
    // 0x800B2154: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800B2158: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B215C: jal         0x8009A2B0
    // 0x800B2160: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    lotsofglass(rdram, ctx);
        goto after_46;
    // 0x800B2160: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_46:
    // 0x800B2164: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2168: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B216C: jal         0x80092728
    // 0x800B2170: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    deletesprite(rdram, ctx);
        goto after_47;
    // 0x800B2170: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_47:
    // 0x800B2174: b           L_800B2E78
    // 0x800B2178: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B2178: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B217C:
    // 0x800B217C: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2180: addiu       $t3, $zero, 0x54F
    ctx->r11 = ADD32(0, 0X54F);
    // 0x800B2184: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2188: sh          $t3, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r11;
    // 0x800B218C: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800B2190: jal         0x80059034
    // 0x800B2194: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    spritesound(rdram, ctx);
        goto after_48;
    // 0x800B2194: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_48:
    // 0x800B2198: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B219C: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B21A0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B21A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B21A8: jal         0x8009A2B0
    // 0x800B21AC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lotsofglass(rdram, ctx);
        goto after_49;
    // 0x800B21AC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_49:
    // 0x800B21B0: b           L_800B2E78
    // 0x800B21B4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B21B4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B21B8:
    // 0x800B21B8: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
L_800B21BC:
    // 0x800B21BC: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B21C0: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B21C4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B21C8: jal         0x800A66F0
    // 0x800B21CC: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    shoot(rdram, ctx);
        goto after_50;
    // 0x800B21CC: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    after_50:
    // 0x800B21D0: lh          $s4, 0x9E($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x800B21D4: lh          $t9, 0x14($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0X14));
    // 0x800B21D8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B21DC: sll         $t8, $s4, 16
    ctx->r24 = S32(ctx->r20 << 16);
    // 0x800B21E0: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800B21E4: slti        $at, $t2, 0x30
    ctx->r1 = SIGNED(ctx->r10) < 0X30 ? 1 : 0;
    // 0x800B21E8: addiu       $t0, $t9, 0x14D
    ctx->r8 = ADD32(ctx->r25, 0X14D);
    // 0x800B21EC: sh          $t2, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r10;
    // 0x800B21F0: bne         $at, $zero, L_800B21BC
    if (ctx->r1 != 0) {
        // 0x800B21F4: sh          $t0, 0x14($s5)
        MEM_H(0X14, ctx->r21) = ctx->r8;
            goto L_800B21BC;
    }
    // 0x800B21F4: sh          $t0, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r8;
    // 0x800B21F8: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B21FC: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2200: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800B2204: jal         0x80059034
    // 0x800B2208: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    spritesound(rdram, ctx);
        goto after_51;
    // 0x800B2208: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_51:
    // 0x800B220C: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2210: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2214: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800B2218: jal         0x80059034
    // 0x800B221C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    spritesound(rdram, ctx);
        goto after_52;
    // 0x800B221C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_52:
L_800B2220:
    // 0x800B2220: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2224: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2228: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800B222C: jal         0x80059034
    // 0x800B2230: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    spritesound(rdram, ctx);
        goto after_53;
    // 0x800B2230: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_53:
    // 0x800B2234: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2238: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B223C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800B2240: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B2244: jal         0x8009A2B0
    // 0x800B2248: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lotsofglass(rdram, ctx);
        goto after_54;
    // 0x800B2248: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_54:
    // 0x800B224C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2250: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2254: jal         0x80092728
    // 0x800B2258: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    deletesprite(rdram, ctx);
        goto after_55;
    // 0x800B2258: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_55:
    // 0x800B225C: b           L_800B2E78
    // 0x800B2260: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B2260: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B2264:
    // 0x800B2264: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2268: addiu       $t6, $zero, 0x3EB
    ctx->r14 = ADD32(0, 0X3EB);
    // 0x800B226C: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2270: sh          $t6, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r14;
    // 0x800B2274: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800B2278: jal         0x80059034
    // 0x800B227C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    spritesound(rdram, ctx);
        goto after_56;
    // 0x800B227C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_56:
    // 0x800B2280: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2284: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2288: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800B228C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B2290: jal         0x8009A2B0
    // 0x800B2294: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lotsofglass(rdram, ctx);
        goto after_57;
    // 0x800B2294: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_57:
    // 0x800B2298: b           L_800B2E78
    // 0x800B229C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B229C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B22A0:
    // 0x800B22A0: lh          $t8, 0x16($s5)
    ctx->r24 = S32(MEM_H(ctx->r21, 0X16));
    // 0x800B22A4: addiu       $t1, $t1, -0x5C00
    ctx->r9 = ADD32(ctx->r9, -0X5C00);
    // 0x800B22A8: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B22AC: sll         $t2, $t8, 3
    ctx->r10 = S32(ctx->r24 << 3);
    // 0x800B22B0: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x800B22B4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800B22B8: addu        $v0, $t2, $t1
    ctx->r2 = ADD32(ctx->r10, ctx->r9);
    // 0x800B22BC: lw          $v1, 0x34($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0X34));
    // 0x800B22C0: lw          $t5, 0x38($v0)
    ctx->r13 = S32(MEM_W(ctx->r2, 0X38));
    // 0x800B22C4: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x800B22C8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B22CC: sltiu       $t3, $v1, 0x1
    ctx->r11 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800B22D0: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x800B22D4: sb          $zero, 0x27($s5)
    MEM_B(0X27, ctx->r21) = 0;
    // 0x800B22D8: sw          $t4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r12;
    // 0x800B22DC: sw          $t3, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r11;
    // 0x800B22E0: sw          $t7, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r15;
    // 0x800B22E4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B22E8: jal         0x8009D240
    // 0x800B22EC: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    spawn(rdram, ctx);
        goto after_58;
    // 0x800B22EC: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
    after_58:
    // 0x800B22F0: b           L_800B2E78
    // 0x800B22F4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B22F4: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B22F8:
    // 0x800B22F8: lh          $t9, 0xC($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B22FC: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2300: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2304: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800B2308: beq         $t0, $zero, L_800B2E74
    if (ctx->r8 == 0) {
        // 0x800B230C: addiu       $a0, $zero, 0x11
        ctx->r4 = ADD32(0, 0X11);
            goto L_800B2E74;
    }
    // 0x800B230C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x800B2310: jal         0x80059034
    // 0x800B2314: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    spritesound(rdram, ctx);
        goto after_59;
    // 0x800B2314: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_59:
    // 0x800B2318: lw          $t2, 0x8($s5)
    ctx->r10 = S32(MEM_W(ctx->r21, 0X8));
    // 0x800B231C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2320: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2324: addiu       $t1, $t2, 0x1000
    ctx->r9 = ADD32(ctx->r10, 0X1000);
    // 0x800B2328: sw          $t1, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r9;
    // 0x800B232C: sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
    // 0x800B2330: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800B2334: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B2338: jal         0x8009A2B0
    // 0x800B233C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    lotsofglass(rdram, ctx);
        goto after_60;
    // 0x800B233C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_60:
    // 0x800B2340: b           L_800B2E78
    // 0x800B2344: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B2344: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B2348:
    // 0x800B2348: addiu       $t3, $zero, 0x267
    ctx->r11 = ADD32(0, 0X267);
    // 0x800B234C: jal         0x8009800C
    // 0x800B2350: sh          $t3, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r11;
    krand2(rdram, ctx);
        goto after_61;
    // 0x800B2350: sh          $t3, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r11;
    after_61:
    // 0x800B2354: lh          $t5, 0xC($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B2358: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800B235C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800B2360: or          $t9, $t5, $t6
    ctx->r25 = ctx->r13 | ctx->r14;
    // 0x800B2364: sh          $t9, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r25;
    // 0x800B2368: lh          $t0, 0xC($s5)
    ctx->r8 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B236C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2370: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2374: andi        $t8, $t0, 0xFEFE
    ctx->r24 = ctx->r8 & 0XFEFE;
    // 0x800B2378: sh          $t8, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r24;
    // 0x800B237C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800B2380: jal         0x8009D240
    // 0x800B2384: addiu       $a1, $zero, 0x399
    ctx->r5 = ADD32(0, 0X399);
    spawn(rdram, ctx);
        goto after_62;
    // 0x800B2384: addiu       $a1, $zero, 0x399
    ctx->r5 = ADD32(0, 0X399);
    after_62:
    // 0x800B2388: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B238C: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2390: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800B2394: jal         0x80059034
    // 0x800B2398: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    spritesound(rdram, ctx);
        goto after_63;
    // 0x800B2398: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_63:
    // 0x800B239C: b           L_800B2E78
    // 0x800B23A0: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B23A0: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B23A4:
    // 0x800B23A4: addiu       $t4, $zero, 0x23D
    ctx->r12 = ADD32(0, 0X23D);
    // 0x800B23A8: jal         0x8009800C
    // 0x800B23AC: sh          $t4, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r12;
    krand2(rdram, ctx);
        goto after_64;
    // 0x800B23AC: sh          $t4, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r12;
    after_64:
    // 0x800B23B0: lh          $t3, 0xC($s5)
    ctx->r11 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B23B4: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800B23B8: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800B23BC: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x800B23C0: sh          $t6, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r14;
    // 0x800B23C4: lh          $t9, 0xC($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B23C8: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B23CC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B23D0: andi        $t0, $t9, 0xFEFE
    ctx->r8 = ctx->r25 & 0XFEFE;
    // 0x800B23D4: sh          $t0, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r8;
    // 0x800B23D8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800B23DC: jal         0x8009D240
    // 0x800B23E0: addiu       $a1, $zero, 0x399
    ctx->r5 = ADD32(0, 0X399);
    spawn(rdram, ctx);
        goto after_65;
    // 0x800B23E0: addiu       $a1, $zero, 0x399
    ctx->r5 = ADD32(0, 0X399);
    after_65:
    // 0x800B23E4: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B23E8: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B23EC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800B23F0: jal         0x80059034
    // 0x800B23F4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    spritesound(rdram, ctx);
        goto after_66;
    // 0x800B23F4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_66:
    // 0x800B23F8: b           L_800B2E78
    // 0x800B23FC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B23FC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B2400:
    // 0x800B2400: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2404: addiu       $t1, $zero, 0x3B6
    ctx->r9 = ADD32(0, 0X3B6);
    // 0x800B2408: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B240C: sh          $t1, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r9;
    // 0x800B2410: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800B2414: jal         0x8009D240
    // 0x800B2418: addiu       $a1, $zero, 0x399
    ctx->r5 = ADD32(0, 0X399);
    spawn(rdram, ctx);
        goto after_67;
    // 0x800B2418: addiu       $a1, $zero, 0x399
    ctx->r5 = ADD32(0, 0X399);
    after_67:
    // 0x800B241C: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2420: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2424: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B2428: jal         0x80059034
    // 0x800B242C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    spritesound(rdram, ctx);
        goto after_68;
    // 0x800B242C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_68:
    // 0x800B2430: b           L_800B2E78
    // 0x800B2434: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B2434: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B2438:
    // 0x800B2438: lh          $t5, 0xC($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B243C: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2440: addiu       $t3, $zero, 0x254
    ctx->r11 = ADD32(0, 0X254);
    // 0x800B2444: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2448: andi        $t6, $t5, 0xFEFE
    ctx->r14 = ctx->r13 & 0XFEFE;
    // 0x800B244C: sh          $t3, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r11;
    // 0x800B2450: sh          $t6, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r14;
    // 0x800B2454: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800B2458: jal         0x80059034
    // 0x800B245C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    spritesound(rdram, ctx);
        goto after_69;
    // 0x800B245C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_69:
    // 0x800B2460: b           L_800B2E78
    // 0x800B2464: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B2464: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B2468:
    // 0x800B2468: lh          $t8, 0xC($s5)
    ctx->r24 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B246C: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B2470: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2474: andi        $t2, $t8, 0xFEFE
    ctx->r10 = ctx->r24 & 0XFEFE;
    // 0x800B2478: sh          $t0, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r8;
    // 0x800B247C: sh          $t2, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r10;
    // 0x800B2480: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800B2484: jal         0x80059034
    // 0x800B2488: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    spritesound(rdram, ctx);
        goto after_70;
    // 0x800B2488: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_70:
    // 0x800B248C: b           L_800B2E78
    // 0x800B2490: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B2490: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B2494:
    // 0x800B2494: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B2498: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B249C: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B24A0: andi        $t3, $t7, 0xFEFE
    ctx->r11 = ctx->r15 & 0XFEFE;
    // 0x800B24A4: sh          $t4, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r12;
    // 0x800B24A8: sh          $t3, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r11;
    // 0x800B24AC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800B24B0: jal         0x80059034
    // 0x800B24B4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    spritesound(rdram, ctx);
        goto after_71;
    // 0x800B24B4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_71:
    // 0x800B24B8: b           L_800B2E78
    // 0x800B24BC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B24BC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B24C0:
    // 0x800B24C0: lh          $t9, 0xC($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B24C4: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B24C8: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B24CC: andi        $t0, $t9, 0xFEFE
    ctx->r8 = ctx->r25 & 0XFEFE;
    // 0x800B24D0: sh          $t6, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r14;
    // 0x800B24D4: sh          $t0, 0xC($s5)
    MEM_H(0XC, ctx->r21) = ctx->r8;
    // 0x800B24D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800B24DC: jal         0x80059034
    // 0x800B24E0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    spritesound(rdram, ctx);
        goto after_72;
    // 0x800B24E0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_72:
    // 0x800B24E4: b           L_800B2E78
    // 0x800B24E8: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B24E8: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B24EC:
    // 0x800B24EC: addiu       $at, $zero, 0x268
    ctx->r1 = ADD32(0, 0X268);
    // 0x800B24F0: beq         $v1, $at, L_800B2544
    if (ctx->r3 == ctx->r1) {
        // 0x800B24F4: sll         $a0, $s6, 16
        ctx->r4 = S32(ctx->r22 << 16);
            goto L_800B2544;
    }
    // 0x800B24F4: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B24F8: addiu       $at, $zero, 0x26A
    ctx->r1 = ADD32(0, 0X26A);
    // 0x800B24FC: beq         $v1, $at, L_800B2550
    if (ctx->r3 == ctx->r1) {
        // 0x800B2500: addiu       $t4, $zero, 0x2BC
        ctx->r12 = ADD32(0, 0X2BC);
            goto L_800B2550;
    }
    // 0x800B2500: addiu       $t4, $zero, 0x2BC
    ctx->r12 = ADD32(0, 0X2BC);
    // 0x800B2504: addiu       $at, $zero, 0x26B
    ctx->r1 = ADD32(0, 0X26B);
    // 0x800B2508: beq         $v1, $at, L_800B253C
    if (ctx->r3 == ctx->r1) {
        // 0x800B250C: addiu       $t2, $zero, 0x269
        ctx->r10 = ADD32(0, 0X269);
            goto L_800B253C;
    }
    // 0x800B250C: addiu       $t2, $zero, 0x269
    ctx->r10 = ADD32(0, 0X269);
    // 0x800B2510: addiu       $at, $zero, 0x3E2
    ctx->r1 = ADD32(0, 0X3E2);
    // 0x800B2514: beq         $v1, $at, L_800B2560
    if (ctx->r3 == ctx->r1) {
        // 0x800B2518: addiu       $t3, $zero, 0x3ED
        ctx->r11 = ADD32(0, 0X3ED);
            goto L_800B2560;
    }
    // 0x800B2518: addiu       $t3, $zero, 0x3ED
    ctx->r11 = ADD32(0, 0X3ED);
    // 0x800B251C: addiu       $at, $zero, 0x3E3
    ctx->r1 = ADD32(0, 0X3E3);
    // 0x800B2520: beq         $v1, $at, L_800B2568
    if (ctx->r3 == ctx->r1) {
        // 0x800B2524: addiu       $t5, $zero, 0x4EC
        ctx->r13 = ADD32(0, 0X4EC);
            goto L_800B2568;
    }
    // 0x800B2524: addiu       $t5, $zero, 0x4EC
    ctx->r13 = ADD32(0, 0X4EC);
    // 0x800B2528: addiu       $at, $zero, 0x3E4
    ctx->r1 = ADD32(0, 0X3E4);
    // 0x800B252C: beq         $v1, $at, L_800B2558
    if (ctx->r3 == ctx->r1) {
        // 0x800B2530: addiu       $t7, $zero, 0x3E5
        ctx->r15 = ADD32(0, 0X3E5);
            goto L_800B2558;
    }
    // 0x800B2530: addiu       $t7, $zero, 0x3E5
    ctx->r15 = ADD32(0, 0X3E5);
    // 0x800B2534: b           L_800B2570
    // 0x800B2538: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
        goto L_800B2570;
    // 0x800B2538: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
L_800B253C:
    // 0x800B253C: b           L_800B256C
    // 0x800B2540: sh          $t2, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r10;
        goto L_800B256C;
    // 0x800B2540: sh          $t2, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r10;
L_800B2544:
    // 0x800B2544: addiu       $t1, $zero, 0x279
    ctx->r9 = ADD32(0, 0X279);
    // 0x800B2548: b           L_800B256C
    // 0x800B254C: sh          $t1, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r9;
        goto L_800B256C;
    // 0x800B254C: sh          $t1, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r9;
L_800B2550:
    // 0x800B2550: b           L_800B256C
    // 0x800B2554: sh          $t4, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r12;
        goto L_800B256C;
    // 0x800B2554: sh          $t4, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r12;
L_800B2558:
    // 0x800B2558: b           L_800B256C
    // 0x800B255C: sh          $t7, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r15;
        goto L_800B256C;
    // 0x800B255C: sh          $t7, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r15;
L_800B2560:
    // 0x800B2560: b           L_800B256C
    // 0x800B2564: sh          $t3, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r11;
        goto L_800B256C;
    // 0x800B2564: sh          $t3, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r11;
L_800B2568:
    // 0x800B2568: sh          $t5, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r13;
L_800B256C:
    // 0x800B256C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
L_800B2570:
    // 0x800B2570: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B2574: jal         0x8009D240
    // 0x800B2578: addiu       $a1, $zero, 0x4E2
    ctx->r5 = ADD32(0, 0X4E2);
    spawn(rdram, ctx);
        goto after_73;
    // 0x800B2578: addiu       $a1, $zero, 0x4E2
    ctx->r5 = ADD32(0, 0X4E2);
    after_73:
    // 0x800B257C: lh          $t9, 0x10($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B2580: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x800B2584: addiu       $s3, $s3, -0x1988
    ctx->r19 = ADD32(ctx->r19, -0X1988);
    // 0x800B2588: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800B258C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800B2590: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800B2594: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800B2598: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x800B259C: addu        $t8, $s3, $t0
    ctx->r24 = ADD32(ctx->r19, ctx->r8);
    // 0x800B25A0: lw          $t2, 0x4($t8)
    ctx->r10 = S32(MEM_W(ctx->r24, 0X4));
    // 0x800B25A4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B25A8: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x800B25AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B25B0: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x800B25B4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B25B8: addiu       $t1, $t2, -0x2000
    ctx->r9 = ADD32(ctx->r10, -0X2000);
    // 0x800B25BC: b           L_800B2E74
    // 0x800B25C0: sw          $t1, 0x6BB0($at)
    MEM_W(0X6BB0, ctx->r1) = ctx->r9;
        goto L_800B2E74;
    // 0x800B25C0: sw          $t1, 0x6BB0($at)
    MEM_W(0X6BB0, ctx->r1) = ctx->r9;
L_800B25C4:
    // 0x800B25C4: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
L_800B25C8:
    // 0x800B25C8: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B25CC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B25D0: jal         0x80059034
    // 0x800B25D4: lhu         $a0, 0x1E($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X1E);
    spritesound(rdram, ctx);
        goto after_74;
    // 0x800B25D4: lhu         $a0, 0x1E($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X1E);
    after_74:
    // 0x800B25D8: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B25DC: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B25E0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800B25E4: jal         0x8009D240
    // 0x800B25E8: lh          $a1, 0x20($s5)
    ctx->r5 = S32(MEM_H(ctx->r21, 0X20));
    spawn(rdram, ctx);
        goto after_75;
    // 0x800B25E8: lh          $a1, 0x20($s5)
    ctx->r5 = S32(MEM_H(ctx->r21, 0X20));
    after_75:
    // 0x800B25EC: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x800B25F0: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x800B25F4: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
L_800B25F8:
    // 0x800B25F8: multu       $s0, $a3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B25FC: lh          $t5, 0x22($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0X22));
    // 0x800B2600: mflo        $t6
    ctx->r14 = lo;
    // 0x800B2604: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x800B2608: lh          $t0, 0x22($t9)
    ctx->r8 = S32(MEM_H(ctx->r25, 0X22));
    // 0x800B260C: subu        $t8, $t5, $t0
    ctx->r24 = SUB32(ctx->r13, ctx->r8);
    // 0x800B2610: sh          $t8, 0x22($s5)
    MEM_H(0X22, ctx->r21) = ctx->r24;
    // 0x800B2614: lh          $t2, 0x22($s5)
    ctx->r10 = S32(MEM_H(ctx->r21, 0X22));
    // 0x800B2618: bgtzl       $t2, L_800B2E78
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B261C: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_9;
    // 0x800B261C: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_9:
    // 0x800B2620: jal         0x8009800C
    // 0x800B2624: nop

    krand2(rdram, ctx);
        goto after_76;
    // 0x800B2624: nop

    after_76:
    // 0x800B2628: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B262C: andi        $t1, $v0, 0x7FF
    ctx->r9 = ctx->r2 & 0X7FF;
    // 0x800B2630: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2634: sh          $t1, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r9;
    // 0x800B2638: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800B263C: jal         0x800A66F0
    // 0x800B2640: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    shoot(rdram, ctx);
        goto after_77;
    // 0x800B2640: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    after_77:
    // 0x800B2644: jal         0x8009800C
    // 0x800B2648: nop

    krand2(rdram, ctx);
        goto after_78;
    // 0x800B2648: nop

    after_78:
    // 0x800B264C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2650: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x800B2654: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2658: sh          $t7, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r15;
    // 0x800B265C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800B2660: jal         0x800A66F0
    // 0x800B2664: addiu       $a1, $zero, 0x8FA
    ctx->r5 = ADD32(0, 0X8FA);
    shoot(rdram, ctx);
        goto after_79;
    // 0x800B2664: addiu       $a1, $zero, 0x8FA
    ctx->r5 = ADD32(0, 0X8FA);
    after_79:
    // 0x800B2668: jal         0x8009800C
    // 0x800B266C: nop

    krand2(rdram, ctx);
        goto after_80;
    // 0x800B266C: nop

    after_80:
    // 0x800B2670: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2674: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x800B2678: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B267C: sh          $t6, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r14;
    // 0x800B2680: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800B2684: jal         0x800A66F0
    // 0x800B2688: addiu       $a1, $zero, 0x8F9
    ctx->r5 = ADD32(0, 0X8F9);
    shoot(rdram, ctx);
        goto after_81;
    // 0x800B2688: addiu       $a1, $zero, 0x8F9
    ctx->r5 = ADD32(0, 0X8F9);
    after_81:
    // 0x800B268C: jal         0x8009800C
    // 0x800B2690: nop

    krand2(rdram, ctx);
        goto after_82;
    // 0x800B2690: nop

    after_82:
    // 0x800B2694: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2698: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x800B269C: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B26A0: sh          $t5, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r13;
    // 0x800B26A4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800B26A8: jal         0x800A66F0
    // 0x800B26AC: addiu       $a1, $zero, 0x8FB
    ctx->r5 = ADD32(0, 0X8FB);
    shoot(rdram, ctx);
        goto after_83;
    // 0x800B26AC: addiu       $a1, $zero, 0x8FB
    ctx->r5 = ADD32(0, 0X8FB);
    after_83:
    // 0x800B26B0: jal         0x8009800C
    // 0x800B26B4: nop

    krand2(rdram, ctx);
        goto after_84;
    // 0x800B26B4: nop

    after_84:
    // 0x800B26B8: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B26BC: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x800B26C0: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B26C4: sh          $t8, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r24;
    // 0x800B26C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800B26CC: jal         0x800A66F0
    // 0x800B26D0: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    shoot(rdram, ctx);
        goto after_85;
    // 0x800B26D0: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    after_85:
    // 0x800B26D4: jal         0x8009800C
    // 0x800B26D8: nop

    krand2(rdram, ctx);
        goto after_86;
    // 0x800B26D8: nop

    after_86:
    // 0x800B26DC: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B26E0: andi        $t1, $v0, 0x7FF
    ctx->r9 = ctx->r2 & 0X7FF;
    // 0x800B26E4: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B26E8: sh          $t1, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r9;
    // 0x800B26EC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800B26F0: jal         0x800A66F0
    // 0x800B26F4: addiu       $a1, $zero, 0x8FA
    ctx->r5 = ADD32(0, 0X8FA);
    shoot(rdram, ctx);
        goto after_87;
    // 0x800B26F4: addiu       $a1, $zero, 0x8FA
    ctx->r5 = ADD32(0, 0X8FA);
    after_87:
    // 0x800B26F8: jal         0x8009800C
    // 0x800B26FC: nop

    krand2(rdram, ctx);
        goto after_88;
    // 0x800B26FC: nop

    after_88:
    // 0x800B2700: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2704: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x800B2708: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B270C: sh          $t7, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r15;
    // 0x800B2710: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800B2714: jal         0x800A66F0
    // 0x800B2718: addiu       $a1, $zero, 0x8F9
    ctx->r5 = ADD32(0, 0X8F9);
    shoot(rdram, ctx);
        goto after_89;
    // 0x800B2718: addiu       $a1, $zero, 0x8F9
    ctx->r5 = ADD32(0, 0X8F9);
    after_89:
    // 0x800B271C: jal         0x8009800C
    // 0x800B2720: nop

    krand2(rdram, ctx);
        goto after_90;
    // 0x800B2720: nop

    after_90:
    // 0x800B2724: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2728: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x800B272C: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2730: sh          $t6, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r14;
    // 0x800B2734: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800B2738: jal         0x800A66F0
    // 0x800B273C: addiu       $a1, $zero, 0x8FB
    ctx->r5 = ADD32(0, 0X8FB);
    shoot(rdram, ctx);
        goto after_91;
    // 0x800B273C: addiu       $a1, $zero, 0x8FB
    ctx->r5 = ADD32(0, 0X8FB);
    after_91:
    // 0x800B2740: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x800B2744: addiu       $s0, $s0, -0x9D8
    ctx->r16 = ADD32(ctx->r16, -0X9D8);
    // 0x800B2748: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    // 0x800B274C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B2750: addiu       $a1, $zero, 0x8C5
    ctx->r5 = ADD32(0, 0X8C5);
    // 0x800B2754: jal         0x80076664
    // 0x800B2758: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    guts(rdram, ctx);
        goto after_92;
    // 0x800B2758: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_92:
    // 0x800B275C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B2760: addiu       $a1, $zero, 0x8CA
    ctx->r5 = ADD32(0, 0X8CA);
    // 0x800B2764: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800B2768: jal         0x80076664
    // 0x800B276C: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    guts(rdram, ctx);
        goto after_93;
    // 0x800B276C: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    after_93:
    // 0x800B2770: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B2774: addiu       $a1, $zero, 0x8CF
    ctx->r5 = ADD32(0, 0X8CF);
    // 0x800B2778: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800B277C: jal         0x80076664
    // 0x800B2780: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    guts(rdram, ctx);
        goto after_94;
    // 0x800B2780: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    after_94:
    // 0x800B2784: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B2788: addiu       $a1, $zero, 0x8D4
    ctx->r5 = ADD32(0, 0X8D4);
    // 0x800B278C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800B2790: jal         0x80076664
    // 0x800B2794: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    guts(rdram, ctx);
        goto after_95;
    // 0x800B2794: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    after_95:
    // 0x800B2798: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B279C: addiu       $a1, $zero, 0x8D9
    ctx->r5 = ADD32(0, 0X8D9);
    // 0x800B27A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B27A4: jal         0x80076664
    // 0x800B27A8: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    guts(rdram, ctx);
        goto after_96;
    // 0x800B27A8: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    after_96:
    // 0x800B27AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B27B0: addiu       $a1, $zero, 0x8CF
    ctx->r5 = ADD32(0, 0X8CF);
    // 0x800B27B4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800B27B8: jal         0x80076664
    // 0x800B27BC: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    guts(rdram, ctx);
        goto after_97;
    // 0x800B27BC: lh          $a3, 0x0($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X0));
    after_97:
    // 0x800B27C0: jal         0x80058E1C
    // 0x800B27C4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    sound(rdram, ctx);
        goto after_98;
    // 0x800B27C4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_98:
    // 0x800B27C8: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B27CC: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B27D0: jal         0x80092728
    // 0x800B27D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    deletesprite(rdram, ctx);
        goto after_99;
    // 0x800B27D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_99:
    // 0x800B27D8: b           L_800B2E78
    // 0x800B27DC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B27DC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B27E0:
    // 0x800B27E0: addiu       $t0, $zero, 0x22F
    ctx->r8 = ADD32(0, 0X22F);
    // 0x800B27E4: sh          $t0, 0xE($s5)
    MEM_H(0XE, ctx->r21) = ctx->r8;
    // 0x800B27E8: b           L_800B2E74
    // 0x800B27EC: sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
        goto L_800B2E74;
    // 0x800B27EC: sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
L_800B27F0:
    // 0x800B27F0: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x800B27F4: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B27F8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800B27FC: jal         0x80059034
    // 0x800B2800: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    spritesound(rdram, ctx);
        goto after_100;
    // 0x800B2800: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_100:
    // 0x800B2804: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
L_800B2808:
    // 0x800B2808: jal         0x8009800C
    // 0x800B280C: nop

    krand2(rdram, ctx);
        goto after_101;
    // 0x800B280C: nop

    after_101:
    // 0x800B2810: jal         0x8009800C
    // 0x800B2814: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_102;
    // 0x800B2814: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    after_102:
    // 0x800B2818: jal         0x8009800C
    // 0x800B281C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_103;
    // 0x800B281C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_103:
    // 0x800B2820: jal         0x8009800C
    // 0x800B2824: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    krand2(rdram, ctx);
        goto after_104;
    // 0x800B2824: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_104:
    // 0x800B2828: jal         0x8009800C
    // 0x800B282C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_105;
    // 0x800B282C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_105:
    // 0x800B2830: jal         0x8009800C
    // 0x800B2834: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_106;
    // 0x800B2834: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_106:
    // 0x800B2838: jal         0x8009800C
    // 0x800B283C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    krand2(rdram, ctx);
        goto after_107;
    // 0x800B283C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_107:
    // 0x800B2840: lw          $t6, 0x78($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X78));
    // 0x800B2844: lw          $t3, 0x8($s5)
    ctx->r11 = S32(MEM_W(ctx->r21, 0X8));
    // 0x800B2848: lw          $t1, 0x0($s5)
    ctx->r9 = S32(MEM_W(ctx->r21, 0X0));
    // 0x800B284C: lw          $t7, 0x4($s5)
    ctx->r15 = S32(MEM_W(ctx->r21, 0X4));
    // 0x800B2850: andi        $t5, $s2, 0xF
    ctx->r13 = ctx->r18 & 0XF;
    // 0x800B2854: andi        $t9, $t6, 0x1FFF
    ctx->r25 = ctx->r14 & 0X1FFF;
    // 0x800B2858: addiu       $t0, $t5, 0x956
    ctx->r8 = ADD32(ctx->r13, 0X956);
    // 0x800B285C: andi        $t2, $s4, 0xFF
    ctx->r10 = ctx->r20 & 0XFF;
    // 0x800B2860: andi        $t4, $s3, 0xFF
    ctx->r12 = ctx->r19 & 0XFF;
    // 0x800B2864: subu        $a3, $t3, $t9
    ctx->r7 = SUB32(ctx->r11, ctx->r25);
    // 0x800B2868: addu        $a1, $t2, $t1
    ctx->r5 = ADD32(ctx->r10, ctx->r9);
    // 0x800B286C: addu        $a2, $t4, $t7
    ctx->r6 = ADD32(ctx->r12, ctx->r15);
    // 0x800B2870: andi        $t7, $s0, 0x3F
    ctx->r15 = ctx->r16 & 0X3F;
    // 0x800B2874: addiu       $t9, $zero, -0x200
    ctx->r25 = ADD32(0, -0X200);
    // 0x800B2878: andi        $t3, $v0, 0x7FF
    ctx->r11 = ctx->r2 & 0X7FF;
    // 0x800B287C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B2880: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800B2884: subu        $t5, $t9, $t3
    ctx->r13 = SUB32(ctx->r25, ctx->r11);
    // 0x800B2888: addiu       $t6, $t7, 0x40
    ctx->r14 = ADD32(ctx->r15, 0X40);
    // 0x800B288C: andi        $t4, $s1, 0x7FF
    ctx->r12 = ctx->r17 & 0X7FF;
    // 0x800B2890: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x800B2894: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x800B2898: addiu       $t8, $zero, -0x8
    ctx->r24 = ADD32(0, -0X8);
    // 0x800B289C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800B28A0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800B28A4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800B28A8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800B28AC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B28B0: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800B28B4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800B28B8: addiu       $a2, $a2, -0x80
    ctx->r6 = ADD32(ctx->r6, -0X80);
    // 0x800B28BC: addiu       $a1, $a1, -0x80
    ctx->r5 = ADD32(ctx->r5, -0X80);
    // 0x800B28C0: addiu       $a3, $a3, -0x800
    ctx->r7 = ADD32(ctx->r7, -0X800);
    // 0x800B28C4: lh          $a0, 0x10($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B28C8: jal         0x8009B028
    // 0x800B28CC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    EGS(rdram, ctx);
        goto after_108;
    // 0x800B28CC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    after_108:
    // 0x800B28D0: lh          $s4, 0x9E($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x800B28D4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B28D8: sll         $t8, $s4, 16
    ctx->r24 = S32(ctx->r20 << 16);
    // 0x800B28DC: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800B28E0: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x800B28E4: bne         $at, $zero, L_800B2808
    if (ctx->r1 != 0) {
        // 0x800B28E8: sh          $t2, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r10;
            goto L_800B2808;
    }
    // 0x800B28E8: sh          $t2, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r10;
    // 0x800B28EC: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B28F0: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B28F4: jal         0x80092728
    // 0x800B28F8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    deletesprite(rdram, ctx);
        goto after_109;
    // 0x800B28F8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_109:
    // 0x800B28FC: b           L_800B2E78
    // 0x800B2900: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
        goto L_800B2E78;
    // 0x800B2900: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x800B2904: lh          $s6, 0x16($s5)
    ctx->r22 = S32(MEM_H(ctx->r21, 0X16));
L_800B2908:
    // 0x800B2908: sll         $t4, $s6, 2
    ctx->r12 = S32(ctx->r22 << 2);
    // 0x800B290C: subu        $t4, $t4, $s6
    ctx->r12 = SUB32(ctx->r12, ctx->r22);
    // 0x800B2910: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B2914: subu        $t4, $t4, $s6
    ctx->r12 = SUB32(ctx->r12, ctx->r22);
    // 0x800B2918: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800B291C: addu        $s5, $a2, $t4
    ctx->r21 = ADD32(ctx->r6, ctx->r12);
L_800B2920:
    // 0x800B2920: lh          $t7, 0xC($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0XC));
L_800B2924:
    // 0x800B2924: andi        $t6, $t7, 0x10
    ctx->r14 = ctx->r15 & 0X10;
    // 0x800B2928: beq         $t6, $zero, L_800B2954
    if (ctx->r14 == 0) {
        // 0x800B292C: nop
    
            goto L_800B2954;
    }
    // 0x800B292C: nop

    // 0x800B2930: lh          $t9, 0x20($s5)
    ctx->r25 = S32(MEM_H(ctx->r21, 0X20));
    // 0x800B2934: bne         $t9, $zero, L_800B2954
    if (ctx->r25 != 0) {
        // 0x800B2938: nop
    
            goto L_800B2954;
    }
    // 0x800B2938: nop

    // 0x800B293C: lh          $t3, 0x1E($s5)
    ctx->r11 = S32(MEM_H(ctx->r21, 0X1E));
    // 0x800B2940: bne         $t3, $zero, L_800B2954
    if (ctx->r11 != 0) {
        // 0x800B2944: nop
    
            goto L_800B2954;
    }
    // 0x800B2944: nop

    // 0x800B2948: lh          $t5, 0x12($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0X12));
    // 0x800B294C: beql        $t5, $zero, L_800B2E78
    if (ctx->r13 == 0) {
        // 0x800B2950: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_10;
    // 0x800B2950: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_10:
L_800B2954:
    // 0x800B2954: multu       $s0, $a3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2958: mflo        $t0
    ctx->r8 = lo;
    // 0x800B295C: addu        $s1, $a2, $t0
    ctx->r17 = ADD32(ctx->r6, ctx->r8);
    // 0x800B2960: lh          $t8, 0x16($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, 0X16));
    // 0x800B2964: beql        $s6, $t8, L_800B2E78
    if (ctx->r22 == ctx->r24) {
        // 0x800B2968: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_11;
    // 0x800B2968: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_11:
    // 0x800B296C: lh          $t2, 0x12($s5)
    ctx->r10 = S32(MEM_H(ctx->r21, 0X12));
    // 0x800B2970: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B2974: beql        $t2, $at, L_800B2E78
    if (ctx->r10 == ctx->r1) {
        // 0x800B2978: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_12;
    // 0x800B2978: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_12:
    // 0x800B297C: jal         0x80099ED4
    // 0x800B2980: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    badguy(rdram, ctx);
        goto after_110;
    // 0x800B2980: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_110:
    // 0x800B2984: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B2988: bnel        $v0, $at, L_800B2CE4
    if (ctx->r2 != ctx->r1) {
        // 0x800B298C: lh          $v1, 0x12($s5)
        ctx->r3 = S32(MEM_H(ctx->r21, 0X12));
            goto L_800B2CE4;
    }
    goto skip_13;
    // 0x800B298C: lh          $v1, 0x12($s5)
    ctx->r3 = S32(MEM_H(ctx->r21, 0X12));
    skip_13:
    // 0x800B2990: lh          $t1, 0xE($s1)
    ctx->r9 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800B2994: addiu       $at, $zero, 0xA2D
    ctx->r1 = ADD32(0, 0XA2D);
    // 0x800B2998: addiu       $s3, $zero, 0x938
    ctx->r19 = ADD32(0, 0X938);
    // 0x800B299C: bnel        $t1, $at, L_800B29B4
    if (ctx->r9 != ctx->r1) {
        // 0x800B29A0: lh          $a0, 0xE($s5)
        ctx->r4 = S32(MEM_H(ctx->r21, 0XE));
            goto L_800B29B4;
    }
    goto skip_14;
    // 0x800B29A0: lh          $a0, 0xE($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0XE));
    skip_14:
    // 0x800B29A4: lh          $t4, 0x22($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800B29A8: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800B29AC: sh          $t7, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r15;
    // 0x800B29B0: lh          $a0, 0xE($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0XE));
L_800B29B4:
    // 0x800B29B4: addiu       $s2, $zero, 0x758
    ctx->r18 = ADD32(0, 0X758);
    // 0x800B29B8: beql        $s2, $a0, L_800B2AC0
    if (ctx->r18 == ctx->r4) {
        // 0x800B29BC: lh          $s4, 0x16($s1)
        ctx->r20 = S32(MEM_H(ctx->r17, 0X16));
            goto L_800B2AC0;
    }
    goto skip_15;
    // 0x800B29BC: lh          $s4, 0x16($s1)
    ctx->r20 = S32(MEM_H(ctx->r17, 0X16));
    skip_15:
    // 0x800B29C0: beq         $s3, $a0, L_800B2ABC
    if (ctx->r19 == ctx->r4) {
        // 0x800B29C4: addiu       $at, $zero, 0x780
        ctx->r1 = ADD32(0, 0X780);
            goto L_800B2ABC;
    }
    // 0x800B29C4: addiu       $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
    // 0x800B29C8: beq         $a0, $at, L_800B2ABC
    if (ctx->r4 == ctx->r1) {
        // 0x800B29CC: slti        $at, $a0, 0x942
        ctx->r1 = SIGNED(ctx->r4) < 0X942 ? 1 : 0;
            goto L_800B2ABC;
    }
    // 0x800B29CC: slti        $at, $a0, 0x942
    ctx->r1 = SIGNED(ctx->r4) < 0X942 ? 1 : 0;
    // 0x800B29D0: bne         $at, $zero, L_800B29E4
    if (ctx->r1 != 0) {
        // 0x800B29D4: addiu       $a1, $zero, 0x8EE
        ctx->r5 = ADD32(0, 0X8EE);
            goto L_800B29E4;
    }
    // 0x800B29D4: addiu       $a1, $zero, 0x8EE
    ctx->r5 = ADD32(0, 0X8EE);
    // 0x800B29D8: slti        $at, $a0, 0x94A
    ctx->r1 = SIGNED(ctx->r4) < 0X94A ? 1 : 0;
    // 0x800B29DC: bnel        $at, $zero, L_800B2AC0
    if (ctx->r1 != 0) {
        // 0x800B29E0: lh          $s4, 0x16($s1)
        ctx->r20 = S32(MEM_H(ctx->r17, 0X16));
            goto L_800B2AC0;
    }
    goto skip_16;
    // 0x800B29E0: lh          $s4, 0x16($s1)
    ctx->r20 = S32(MEM_H(ctx->r17, 0X16));
    skip_16:
L_800B29E4:
    // 0x800B29E4: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800B29E8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B29EC: jal         0x8009D240
    // 0x800B29F0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    spawn(rdram, ctx);
        goto after_111;
    // 0x800B29F0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_111:
    // 0x800B29F4: lbu         $t3, 0x25($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X25);
    // 0x800B29F8: sll         $s4, $v0, 16
    ctx->r20 = S32(ctx->r2 << 16);
    // 0x800B29FC: sra         $t9, $s4, 16
    ctx->r25 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800B2A00: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800B2A04: bne         $t3, $at, L_800B2A38
    if (ctx->r11 != ctx->r1) {
        // 0x800B2A08: or          $s4, $t9, $zero
        ctx->r20 = ctx->r25 | 0;
            goto L_800B2A38;
    }
    // 0x800B2A08: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x800B2A0C: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x800B2A10: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800B2A14: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800B2A18: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x800B2A1C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B2A20: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x800B2A24: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800B2A28: lui         $at, 0x8024
    ctx->r1 = S32(0X8024 << 16);
    // 0x800B2A2C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800B2A30: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800B2A34: sb          $t5, 0x6BCD($at)
    MEM_B(0X6BCD, ctx->r1) = ctx->r13;
L_800B2A38:
    // 0x800B2A38: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x800B2A3C: subu        $t1, $t1, $s4
    ctx->r9 = SUB32(ctx->r9, ctx->r20);
    // 0x800B2A40: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B2A44: subu        $t1, $t1, $s4
    ctx->r9 = SUB32(ctx->r9, ctx->r20);
    // 0x800B2A48: lui         $t4, 0x8024
    ctx->r12 = S32(0X8024 << 16);
    // 0x800B2A4C: addiu       $t4, $t4, 0x6BA8
    ctx->r12 = ADD32(ctx->r12, 0X6BA8);
    // 0x800B2A50: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B2A54: addu        $s0, $t1, $t4
    ctx->r16 = ADD32(ctx->r9, ctx->r12);
    // 0x800B2A58: lw          $t7, 0x8($s0)
    ctx->r15 = S32(MEM_W(ctx->r16, 0X8));
    // 0x800B2A5C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800B2A60: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x800B2A64: addiu       $t6, $t7, 0x400
    ctx->r14 = ADD32(ctx->r15, 0X400);
    // 0x800B2A68: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // 0x800B2A6C: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // 0x800B2A70: sb          $t0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r8;
    // 0x800B2A74: sb          $t0, 0x27($s0)
    MEM_B(0X27, ctx->r16) = ctx->r8;
    // 0x800B2A78: jal         0x8009800C
    // 0x800B2A7C: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    krand2(rdram, ctx);
        goto after_112;
    // 0x800B2A7C: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    after_112:
    // 0x800B2A80: lh          $s4, 0x9E($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x800B2A84: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x800B2A88: addiu       $t5, $t5, 0x6BA8
    ctx->r13 = ADD32(ctx->r13, 0X6BA8);
    // 0x800B2A8C: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x800B2A90: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x800B2A94: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2A98: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x800B2A9C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2AA0: addu        $s0, $t8, $t5
    ctx->r16 = ADD32(ctx->r24, ctx->r13);
    // 0x800B2AA4: lh          $t2, 0x14($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X14));
    // 0x800B2AA8: andi        $t1, $v0, 0x3F
    ctx->r9 = ctx->r2 & 0X3F;
    // 0x800B2AAC: subu        $t4, $t2, $t1
    ctx->r12 = SUB32(ctx->r10, ctx->r9);
    // 0x800B2AB0: addiu       $t7, $t4, 0x20
    ctx->r15 = ADD32(ctx->r12, 0X20);
    // 0x800B2AB4: sh          $t7, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r15;
    // 0x800B2AB8: lh          $a0, 0xE($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0XE));
L_800B2ABC:
    // 0x800B2ABC: lh          $s4, 0x16($s1)
    ctx->r20 = S32(MEM_H(ctx->r17, 0X16));
L_800B2AC0:
    // 0x800B2AC0: addiu       $s3, $zero, 0x938
    ctx->r19 = ADD32(0, 0X938);
    // 0x800B2AC4: lui         $t9, 0x8024
    ctx->r25 = S32(0X8024 << 16);
    // 0x800B2AC8: bltz        $s4, L_800B2B9C
    if (SIGNED(ctx->r20) < 0) {
        // 0x800B2ACC: sh          $s4, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r20;
            goto L_800B2B9C;
    }
    // 0x800B2ACC: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    // 0x800B2AD0: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x800B2AD4: subu        $t6, $t6, $s4
    ctx->r14 = SUB32(ctx->r14, ctx->r20);
    // 0x800B2AD8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B2ADC: subu        $t6, $t6, $s4
    ctx->r14 = SUB32(ctx->r14, ctx->r20);
    // 0x800B2AE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B2AE4: addiu       $t9, $t9, 0x6BA8
    ctx->r25 = ADD32(ctx->r25, 0X6BA8);
    // 0x800B2AE8: addu        $s0, $t6, $t9
    ctx->r16 = ADD32(ctx->r14, ctx->r25);
    // 0x800B2AEC: lh          $t3, 0xE($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0XE));
    // 0x800B2AF0: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x800B2AF4: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    // 0x800B2AF8: bnel        $t3, $at, L_800B2BA0
    if (ctx->r11 != ctx->r1) {
        // 0x800B2AFC: addiu       $at, $zero, 0xA46
        ctx->r1 = ADD32(0, 0XA46);
            goto L_800B2BA0;
    }
    goto skip_17;
    // 0x800B2AFC: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    skip_17:
    // 0x800B2B00: beql        $s3, $a0, L_800B2BA0
    if (ctx->r19 == ctx->r4) {
        // 0x800B2B04: addiu       $at, $zero, 0xA46
        ctx->r1 = ADD32(0, 0XA46);
            goto L_800B2BA0;
    }
    goto skip_18;
    // 0x800B2B04: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    skip_18:
    // 0x800B2B08: beql        $s2, $a0, L_800B2BA0
    if (ctx->r18 == ctx->r4) {
        // 0x800B2B0C: addiu       $at, $zero, 0xA46
        ctx->r1 = ADD32(0, 0XA46);
            goto L_800B2BA0;
    }
    goto skip_19;
    // 0x800B2B0C: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    skip_19:
    // 0x800B2B10: lh          $t0, 0x1A($s0)
    ctx->r8 = S32(MEM_H(ctx->r16, 0X1A));
    // 0x800B2B14: lui         $t5, 0x802A
    ctx->r13 = S32(0X802A << 16);
    // 0x800B2B18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B2B1C: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x800B2B20: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800B2B24: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B2B28: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x800B2B2C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2B30: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800B2B34: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2B38: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x800B2B3C: lh          $t5, 0x5A22($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X5A22));
    // 0x800B2B40: addiu       $a1, $zero, 0x8F9
    ctx->r5 = ADD32(0, 0X8F9);
    // 0x800B2B44: bnel        $t5, $at, L_800B2BA0
    if (ctx->r13 != ctx->r1) {
        // 0x800B2B48: addiu       $at, $zero, 0xA46
        ctx->r1 = ADD32(0, 0XA46);
            goto L_800B2BA0;
    }
    goto skip_20;
    // 0x800B2B48: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
    skip_20:
    // 0x800B2B4C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2B50: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2B54: jal         0x800A66F0
    // 0x800B2B58: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    shoot(rdram, ctx);
        goto after_113;
    // 0x800B2B58: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_113:
    // 0x800B2B5C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2B60: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2B64: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800B2B68: jal         0x800A66F0
    // 0x800B2B6C: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    shoot(rdram, ctx);
        goto after_114;
    // 0x800B2B6C: addiu       $a1, $zero, 0x8F8
    ctx->r5 = ADD32(0, 0X8F8);
    after_114:
    // 0x800B2B70: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2B74: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2B78: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800B2B7C: jal         0x800A66F0
    // 0x800B2B80: addiu       $a1, $zero, 0x8FA
    ctx->r5 = ADD32(0, 0X8FA);
    shoot(rdram, ctx);
        goto after_115;
    // 0x800B2B80: addiu       $a1, $zero, 0x8FA
    ctx->r5 = ADD32(0, 0X8FA);
    after_115:
    // 0x800B2B84: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2B88: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2B8C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B2B90: jal         0x800A66F0
    // 0x800B2B94: addiu       $a1, $zero, 0x8FB
    ctx->r5 = ADD32(0, 0X8FB);
    shoot(rdram, ctx);
        goto after_116;
    // 0x800B2B94: addiu       $a1, $zero, 0x8FB
    ctx->r5 = ADD32(0, 0X8FB);
    after_116:
    // 0x800B2B98: lh          $a0, 0xE($s5)
    ctx->r4 = S32(MEM_H(ctx->r21, 0XE));
L_800B2B9C:
    // 0x800B2B9C: addiu       $at, $zero, 0xA46
    ctx->r1 = ADD32(0, 0XA46);
L_800B2BA0:
    // 0x800B2BA0: beq         $a0, $at, L_800B2C74
    if (ctx->r4 == ctx->r1) {
        // 0x800B2BA4: addiu       $at, $zero, 0xA96
        ctx->r1 = ADD32(0, 0XA96);
            goto L_800B2C74;
    }
    // 0x800B2BA4: addiu       $at, $zero, 0xA96
    ctx->r1 = ADD32(0, 0XA96);
    // 0x800B2BA8: beq         $a0, $at, L_800B2C74
    if (ctx->r4 == ctx->r1) {
        // 0x800B2BAC: addiu       $at, $zero, 0xAC8
        ctx->r1 = ADD32(0, 0XAC8);
            goto L_800B2C74;
    }
    // 0x800B2BAC: addiu       $at, $zero, 0xAC8
    ctx->r1 = ADD32(0, 0XAC8);
    // 0x800B2BB0: beq         $a0, $at, L_800B2C74
    if (ctx->r4 == ctx->r1) {
        // 0x800B2BB4: addiu       $at, $zero, 0x7A8
        ctx->r1 = ADD32(0, 0X7A8);
            goto L_800B2C74;
    }
    // 0x800B2BB4: addiu       $at, $zero, 0x7A8
    ctx->r1 = ADD32(0, 0X7A8);
    // 0x800B2BB8: beql        $a0, $at, L_800B2C78
    if (ctx->r4 == ctx->r1) {
        // 0x800B2BBC: lh          $t5, 0x12($s5)
        ctx->r13 = S32(MEM_H(ctx->r21, 0X12));
            goto L_800B2C78;
    }
    goto skip_21;
    // 0x800B2BBC: lh          $t5, 0x12($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0X12));
    skip_21:
    // 0x800B2BC0: beq         $s3, $a0, L_800B2C74
    if (ctx->r19 == ctx->r4) {
        // 0x800B2BC4: addiu       $a1, $s5, 0x4
        ctx->r5 = ADD32(ctx->r21, 0X4);
            goto L_800B2C74;
    }
    // 0x800B2BC4: addiu       $a1, $s5, 0x4
    ctx->r5 = ADD32(ctx->r21, 0X4);
    // 0x800B2BC8: lh          $t6, 0xC($s5)
    ctx->r14 = S32(MEM_H(ctx->r21, 0XC));
    // 0x800B2BCC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B2BD0: addiu       $a2, $s5, 0x8
    ctx->r6 = ADD32(ctx->r21, 0X8);
    // 0x800B2BD4: andi        $t9, $t6, 0x30
    ctx->r25 = ctx->r14 & 0X30;
    // 0x800B2BD8: bne         $t9, $zero, L_800B2BF0
    if (ctx->r25 != 0) {
        // 0x800B2BDC: addiu       $a3, $sp, 0x9E
        ctx->r7 = ADD32(ctx->r29, 0X9E);
            goto L_800B2BF0;
    }
    // 0x800B2BDC: addiu       $a3, $sp, 0x9E
    ctx->r7 = ADD32(ctx->r29, 0X9E);
    // 0x800B2BE0: lh          $t3, 0x14($s1)
    ctx->r11 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800B2BE4: addiu       $t0, $t3, 0x400
    ctx->r8 = ADD32(ctx->r11, 0X400);
    // 0x800B2BE8: andi        $t8, $t0, 0x7FF
    ctx->r24 = ctx->r8 & 0X7FF;
    // 0x800B2BEC: sh          $t8, 0x14($s5)
    MEM_H(0X14, ctx->r21) = ctx->r24;
L_800B2BF0:
    // 0x800B2BF0: lh          $t5, 0x22($s1)
    ctx->r13 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800B2BF4: lh          $s4, 0x10($s5)
    ctx->r20 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B2BF8: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800B2BFC: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x800B2C00: negu        $t1, $t2
    ctx->r9 = SUB32(0, ctx->r10);
    // 0x800B2C04: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x800B2C08: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x800B2C0C: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x800B2C10: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800B2C14: sh          $t1, 0x18($s5)
    MEM_H(0X18, ctx->r21) = ctx->r9;
    // 0x800B2C18: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800B2C1C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800B2C20: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800B2C24: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800B2C28: jal         0x80097860
    // 0x800B2C2C: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    pushmove(rdram, ctx);
        goto after_117;
    // 0x800B2C2C: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    after_117:
    // 0x800B2C30: lh          $s4, 0x9E($sp)
    ctx->r20 = S32(MEM_H(ctx->r29, 0X9E));
    // 0x800B2C34: lh          $t3, 0x10($s5)
    ctx->r11 = S32(MEM_H(ctx->r21, 0X10));
    // 0x800B2C38: beql        $s4, $t3, L_800B2C78
    if (ctx->r20 == ctx->r11) {
        // 0x800B2C3C: lh          $t5, 0x12($s5)
        ctx->r13 = S32(MEM_H(ctx->r21, 0X12));
            goto L_800B2C78;
    }
    goto skip_22;
    // 0x800B2C3C: lh          $t5, 0x12($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0X12));
    skip_22:
    // 0x800B2C40: bltz        $s4, L_800B2C74
    if (SIGNED(ctx->r20) < 0) {
        // 0x800B2C44: sh          $s4, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r20;
            goto L_800B2C74;
    }
    // 0x800B2C44: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    // 0x800B2C48: slti        $at, $s4, 0x291
    ctx->r1 = SIGNED(ctx->r20) < 0X291 ? 1 : 0;
    // 0x800B2C4C: beq         $at, $zero, L_800B2C74
    if (ctx->r1 == 0) {
        // 0x800B2C50: sh          $s4, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r20;
            goto L_800B2C74;
    }
    // 0x800B2C50: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    // 0x800B2C54: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2C58: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x800B2C5C: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800B2C60: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2C64: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800B2C68: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800B2C6C: jal         0x80092938
    // 0x800B2C70: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    changespritesect(rdram, ctx);
        goto after_118;
    // 0x800B2C70: sh          $s4, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r20;
    after_118:
L_800B2C74:
    // 0x800B2C74: lh          $t5, 0x12($s5)
    ctx->r13 = S32(MEM_H(ctx->r21, 0X12));
L_800B2C78:
    // 0x800B2C78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B2C7C: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B2C80: bne         $t5, $at, L_800B2CB0
    if (ctx->r13 != ctx->r1) {
        // 0x800B2C84: sra         $t2, $a0, 16
        ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
            goto L_800B2CB0;
    }
    // 0x800B2C84: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2C88: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800B2C8C: jal         0x800929F0
    // 0x800B2C90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    changespritestat(rdram, ctx);
        goto after_119;
    // 0x800B2C90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_119:
    // 0x800B2C94: sll         $t4, $s6, 3
    ctx->r12 = S32(ctx->r22 << 3);
    // 0x800B2C98: addu        $t4, $t4, $s6
    ctx->r12 = ADD32(ctx->r12, ctx->r22);
    // 0x800B2C9C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800B2CA0: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800B2CA4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B2CA8: addiu       $t1, $zero, 0x600
    ctx->r9 = ADD32(0, 0X600);
    // 0x800B2CAC: sh          $t1, -0x5BEE($at)
    MEM_H(-0X5BEE, ctx->r1) = ctx->r9;
L_800B2CB0:
    // 0x800B2CB0: lbu         $t7, 0x27($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X27);
    // 0x800B2CB4: slti        $at, $t7, 0x18
    ctx->r1 = SIGNED(ctx->r15) < 0X18 ? 1 : 0;
    // 0x800B2CB8: bnel        $at, $zero, L_800B2CD4
    if (ctx->r1 != 0) {
        // 0x800B2CBC: lh          $t9, 0xE($s1)
        ctx->r25 = S32(MEM_H(ctx->r17, 0XE));
            goto L_800B2CD4;
    }
    goto skip_23;
    // 0x800B2CBC: lh          $t9, 0xE($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0XE));
    skip_23:
    // 0x800B2CC0: lh          $t6, 0xE($s5)
    ctx->r14 = S32(MEM_H(ctx->r21, 0XE));
    // 0x800B2CC4: addiu       $at, $zero, 0x60E
    ctx->r1 = ADD32(0, 0X60E);
    // 0x800B2CC8: bnel        $t6, $at, L_800B2CE4
    if (ctx->r14 != ctx->r1) {
        // 0x800B2CCC: lh          $v1, 0x12($s5)
        ctx->r3 = S32(MEM_H(ctx->r21, 0X12));
            goto L_800B2CE4;
    }
    goto skip_24;
    // 0x800B2CCC: lh          $v1, 0x12($s5)
    ctx->r3 = S32(MEM_H(ctx->r21, 0X12));
    skip_24:
    // 0x800B2CD0: lh          $t9, 0xE($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0XE));
L_800B2CD4:
    // 0x800B2CD4: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x800B2CD8: beql        $t9, $at, L_800B2E78
    if (ctx->r25 == ctx->r1) {
        // 0x800B2CDC: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_25;
    // 0x800B2CDC: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_25:
    // 0x800B2CE0: lh          $v1, 0x12($s5)
    ctx->r3 = S32(MEM_H(ctx->r21, 0X12));
L_800B2CE4:
    // 0x800B2CE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B2CE8: sll         $t3, $s6, 3
    ctx->r11 = S32(ctx->r22 << 3);
    // 0x800B2CEC: beq         $v1, $at, L_800B2D2C
    if (ctx->r3 == ctx->r1) {
        // 0x800B2CF0: addu        $t3, $t3, $s6
        ctx->r11 = ADD32(ctx->r11, ctx->r22);
            goto L_800B2D2C;
    }
    // 0x800B2CF0: addu        $t3, $t3, $s6
    ctx->r11 = ADD32(ctx->r11, ctx->r22);
    // 0x800B2CF4: lui         $t0, 0x8028
    ctx->r8 = S32(0X8028 << 16);
    // 0x800B2CF8: addiu       $t0, $t0, -0x5C00
    ctx->r8 = ADD32(ctx->r8, -0X5C00);
    // 0x800B2CFC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800B2D00: addu        $v0, $t3, $t0
    ctx->r2 = ADD32(ctx->r11, ctx->r8);
    // 0x800B2D04: lh          $t5, 0x6($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X6));
    // 0x800B2D08: lh          $t2, 0x22($s1)
    ctx->r10 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800B2D0C: lh          $t8, 0xE($s1)
    ctx->r24 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800B2D10: lh          $t4, 0x14($s1)
    ctx->r12 = S32(MEM_H(ctx->r17, 0X14));
    // 0x800B2D14: lh          $t7, 0x16($s1)
    ctx->r15 = S32(MEM_H(ctx->r17, 0X16));
    // 0x800B2D18: addu        $t1, $t5, $t2
    ctx->r9 = ADD32(ctx->r13, ctx->r10);
    // 0x800B2D1C: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
    // 0x800B2D20: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x800B2D24: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    // 0x800B2D28: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
L_800B2D2C:
    // 0x800B2D2C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B2D30: bnel        $v1, $at, L_800B2E78
    if (ctx->r3 != ctx->r1) {
        // 0x800B2D34: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_26;
    // 0x800B2D34: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_26:
    // 0x800B2D38: lh          $v1, 0x1A($s5)
    ctx->r3 = S32(MEM_H(ctx->r21, 0X1A));
    // 0x800B2D3C: lui         $t9, 0x802A
    ctx->r25 = S32(0X802A << 16);
    // 0x800B2D40: addiu       $t9, $t9, 0x5770
    ctx->r25 = ADD32(ctx->r25, 0X5770);
    // 0x800B2D44: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800B2D48: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800B2D4C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800B2D50: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800B2D54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B2D58: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800B2D5C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B2D60: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x800B2D64: lh          $t3, 0x2BE($v0)
    ctx->r11 = S32(MEM_H(ctx->r2, 0X2BE));
    // 0x800B2D68: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800B2D6C: addiu       $a2, $v0, 0x288
    ctx->r6 = ADD32(ctx->r2, 0X288);
    // 0x800B2D70: bltzl       $t3, L_800B2DF8
    if (SIGNED(ctx->r11) < 0) {
        // 0x800B2D74: lbu         $t6, 0x27($s5)
        ctx->r14 = MEM_BU(ctx->r21, 0X27);
            goto L_800B2DF8;
    }
    goto skip_27;
    // 0x800B2D74: lbu         $t6, 0x27($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X27);
    skip_27:
    // 0x800B2D78: lw          $a0, 0x238($v0)
    ctx->r4 = S32(MEM_W(ctx->r2, 0X238));
    // 0x800B2D7C: lw          $a1, 0x23C($v0)
    ctx->r5 = S32(MEM_W(ctx->r2, 0X23C));
    // 0x800B2D80: lw          $t8, 0x240($v0)
    ctx->r24 = S32(MEM_W(ctx->r2, 0X240));
    // 0x800B2D84: lh          $t5, 0x284($v0)
    ctx->r13 = S32(MEM_H(ctx->r2, 0X284));
    // 0x800B2D88: sh          $t0, 0x2BE($v0)
    MEM_H(0X2BE, ctx->r2) = ctx->r8;
    // 0x800B2D8C: sw          $a0, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->r4;
    // 0x800B2D90: sw          $a1, 0x218($v0)
    MEM_W(0X218, ctx->r2) = ctx->r5;
    // 0x800B2D94: sw          $t8, 0x21C($v0)
    MEM_W(0X21C, ctx->r2) = ctx->r24;
    // 0x800B2D98: jal         0x80097DB8
    // 0x800B2D9C: sh          $t5, 0x282($v0)
    MEM_H(0X282, ctx->r2) = ctx->r13;
    updatesector(rdram, ctx);
        goto after_120;
    // 0x800B2D9C: sh          $t5, 0x282($v0)
    MEM_H(0X282, ctx->r2) = ctx->r13;
    after_120:
    // 0x800B2DA0: lui         $s4, 0x8027
    ctx->r20 = S32(0X8027 << 16);
    // 0x800B2DA4: lh          $s4, 0x285A($s4)
    ctx->r20 = S32(MEM_H(ctx->r20, 0X285A));
    // 0x800B2DA8: lui         $a0, 0x8024
    ctx->r4 = S32(0X8024 << 16);
    // 0x800B2DAC: addiu       $a0, $a0, 0x6BA8
    ctx->r4 = ADD32(ctx->r4, 0X6BA8);
    // 0x800B2DB0: bltz        $s4, L_800B2DF4
    if (SIGNED(ctx->r20) < 0) {
        // 0x800B2DB4: addiu       $a1, $zero, 0x2C
        ctx->r5 = ADD32(0, 0X2C);
            goto L_800B2DF4;
    }
    // 0x800B2DB4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x800B2DB8: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x800B2DBC: addiu       $v1, $v1, 0x5F40
    ctx->r3 = ADD32(ctx->r3, 0X5F40);
    // 0x800B2DC0: addiu       $v0, $zero, 0x26D
    ctx->r2 = ADD32(0, 0X26D);
L_800B2DC4:
    // 0x800B2DC4: multu       $s4, $a1
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2DC8: sll         $t4, $s4, 1
    ctx->r12 = S32(ctx->r20 << 1);
    // 0x800B2DCC: addu        $t7, $v1, $t4
    ctx->r15 = ADD32(ctx->r3, ctx->r12);
    // 0x800B2DD0: mflo        $t2
    ctx->r10 = lo;
    // 0x800B2DD4: addu        $s0, $a0, $t2
    ctx->r16 = ADD32(ctx->r4, ctx->r10);
    // 0x800B2DD8: lh          $t1, 0xE($s0)
    ctx->r9 = S32(MEM_H(ctx->r16, 0XE));
    // 0x800B2DDC: bnel        $v0, $t1, L_800B2DEC
    if (ctx->r2 != ctx->r9) {
        // 0x800B2DE0: lh          $s4, 0x0($t7)
        ctx->r20 = S32(MEM_H(ctx->r15, 0X0));
            goto L_800B2DEC;
    }
    goto skip_28;
    // 0x800B2DE0: lh          $s4, 0x0($t7)
    ctx->r20 = S32(MEM_H(ctx->r15, 0X0));
    skip_28:
    // 0x800B2DE4: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x800B2DE8: lh          $s4, 0x0($t7)
    ctx->r20 = S32(MEM_H(ctx->r15, 0X0));
L_800B2DEC:
    // 0x800B2DEC: bgez        $s4, L_800B2DC4
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800B2DF0: nop
    
            goto L_800B2DC4;
    }
    // 0x800B2DF0: nop

L_800B2DF4:
    // 0x800B2DF4: lbu         $t6, 0x27($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X27);
L_800B2DF8:
    // 0x800B2DF8: sll         $t3, $s6, 3
    ctx->r11 = S32(ctx->r22 << 3);
    // 0x800B2DFC: addu        $t3, $t3, $s6
    ctx->r11 = ADD32(ctx->r11, ctx->r22);
    // 0x800B2E00: slti        $at, $t6, 0x18
    ctx->r1 = SIGNED(ctx->r14) < 0X18 ? 1 : 0;
    // 0x800B2E04: beq         $at, $zero, L_800B2E18
    if (ctx->r1 == 0) {
        // 0x800B2E08: sll         $t3, $t3, 3
        ctx->r11 = S32(ctx->r11 << 3);
            goto L_800B2E18;
    }
    // 0x800B2E08: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800B2E0C: lh          $t9, 0xE($s1)
    ctx->r25 = S32(MEM_H(ctx->r17, 0XE));
    // 0x800B2E10: addiu       $at, $zero, 0x66E
    ctx->r1 = ADD32(0, 0X66E);
    // 0x800B2E14: beq         $t9, $at, L_800B2E74
    if (ctx->r25 == ctx->r1) {
        // 0x800B2E18: lui         $t0, 0x8028
        ctx->r8 = S32(0X8028 << 16);
            goto L_800B2E74;
    }
L_800B2E18:
    // 0x800B2E18: lui         $t0, 0x8028
    ctx->r8 = S32(0X8028 << 16);
    // 0x800B2E1C: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x800B2E20: lh          $t0, -0x5BF8($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, -0X5BF8));
    // 0x800B2E24: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x800B2E28: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x800B2E2C: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800B2E30: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800B2E34: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2E38: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800B2E3C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B2E40: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x800B2E44: lh          $t5, 0x6BB6($t5)
    ctx->r13 = S32(MEM_H(ctx->r13, 0X6BB6));
    // 0x800B2E48: lui         $t2, 0x802B
    ctx->r10 = S32(0X802B << 16);
    // 0x800B2E4C: beql        $t5, $at, L_800B2E78
    if (ctx->r13 == ctx->r1) {
        // 0x800B2E50: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_29;
    // 0x800B2E50: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_29:
    // 0x800B2E54: lw          $t2, -0x5408($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, -0X5408));
    // 0x800B2E58: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800B2E5C: bnel        $at, $zero, L_800B2E78
    if (ctx->r1 != 0) {
        // 0x800B2E60: lw          $ra, 0x5C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
            goto L_800B2E78;
    }
    goto skip_30;
    // 0x800B2E60: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
    skip_30:
    // 0x800B2E64: lh          $v0, 0x22($s1)
    ctx->r2 = S32(MEM_H(ctx->r17, 0X22));
    // 0x800B2E68: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800B2E6C: addu        $t4, $v0, $t1
    ctx->r12 = ADD32(ctx->r2, ctx->r9);
    // 0x800B2E70: sh          $t4, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r12;
L_800B2E74:
    // 0x800B2E74: lw          $ra, 0x5C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X5C));
L_800B2E78:
    // 0x800B2E78: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800B2E7C: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x800B2E80: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x800B2E84: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x800B2E88: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800B2E8C: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x800B2E90: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x800B2E94: jr          $ra
    // 0x800B2E98: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800B2E98: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80051D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051D74: jal         0x800518E4
    // 0x80051D78: nop

    func_800518E4(rdram, ctx);
        goto after_0;
    // 0x80051D78: nop

    after_0:
    // 0x80051D7C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80051D80: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80051D84: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80051D88: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80051D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051D90: jr          $ra
    // 0x80051D94: nop

    return;
    // 0x80051D94: nop

;}
RECOMP_FUNC void getglobalz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898D0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800898D4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800898D8: lh          $t6, 0x5A($sp)
    ctx->r14 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x800898DC: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x800898E0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800898E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800898E8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800898EC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800898F0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800898F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800898F8: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x800898FC: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80089900: lh          $v0, 0x12($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X12));
    // 0x80089904: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80089908: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008990C: beq         $v0, $at, L_80089934
    if (ctx->r2 == ctx->r1) {
        // 0x80089910: lh          $t9, 0x5A($sp)
        ctx->r25 = S32(MEM_H(ctx->r29, 0X5A));
            goto L_80089934;
    }
    // 0x80089910: lh          $t9, 0x5A($sp)
    ctx->r25 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x80089914: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80089918: beq         $v0, $at, L_80089934
    if (ctx->r2 == ctx->r1) {
        // 0x8008991C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80089934;
    }
    // 0x8008991C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80089920: beq         $v0, $at, L_80089934
    if (ctx->r2 == ctx->r1) {
        // 0x80089924: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80089934;
    }
    // 0x80089924: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089928: beq         $v0, $at, L_80089934
    if (ctx->r2 == ctx->r1) {
        // 0x8008992C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80089934;
    }
    // 0x8008992C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089930: bne         $v0, $at, L_80089B8C
    if (ctx->r2 != ctx->r1) {
        // 0x80089934: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80089B8C;
    }
L_80089934:
    // 0x80089934: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089938: bne         $v0, $at, L_80089948
    if (ctx->r2 != ctx->r1) {
        // 0x8008993C: sll         $t0, $t9, 3
        ctx->r8 = S32(ctx->r25 << 3);
            goto L_80089948;
    }
    // 0x8008993C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80089940: b           L_8008994C
    // 0x80089944: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8008994C;
    // 0x80089944: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80089948:
    // 0x80089948: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_8008994C:
    // 0x8008994C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80089950: lui         $t1, 0x8028
    ctx->r9 = S32(0X8028 << 16);
    // 0x80089954: addiu       $t1, $t1, -0x5C00
    ctx->r9 = ADD32(ctx->r9, -0X5C00);
    // 0x80089958: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8008995C: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x80089960: lw          $a2, 0x8($s0)
    ctx->r6 = S32(MEM_W(ctx->r16, 0X8));
    // 0x80089964: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80089968: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x8008996C: addiu       $t2, $v1, 0x18
    ctx->r10 = ADD32(ctx->r3, 0X18);
    // 0x80089970: addiu       $t4, $v1, 0x14
    ctx->r12 = ADD32(ctx->r3, 0X14);
    // 0x80089974: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x80089978: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x8008997C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80089980: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80089984: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80089988: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008998C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80089990: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80089994: lw          $a0, 0x0($s0)
    ctx->r4 = S32(MEM_W(ctx->r16, 0X0));
    // 0x80089998: lw          $a1, 0x4($s0)
    ctx->r5 = S32(MEM_W(ctx->r16, 0X4));
    // 0x8008999C: lh          $a3, 0x10($s0)
    ctx->r7 = S32(MEM_H(ctx->r16, 0X10));
    // 0x800899A0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800899A4: jal         0x80098080
    // 0x800899A8: addiu       $a2, $a2, -0x100
    ctx->r6 = ADD32(ctx->r6, -0X100);
    getzrange(rdram, ctx);
        goto after_0;
    // 0x800899A8: addiu       $a2, $a2, -0x100
    ctx->r6 = ADD32(ctx->r6, -0X100);
    after_0:
    // 0x800899AC: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    // 0x800899B0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800899B4: lw          $v1, 0x40($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800899B8: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x800899BC: slti        $at, $t7, 0x7D0
    ctx->r1 = SIGNED(ctx->r15) < 0X7D0 ? 1 : 0;
    // 0x800899C0: bne         $at, $zero, L_800899D8
    if (ctx->r1 != 0) {
        // 0x800899C4: addiu       $a0, $a0, 0x5AD0
        ctx->r4 = ADD32(ctx->r4, 0X5AD0);
            goto L_800899D8;
    }
    // 0x800899C4: addiu       $a0, $a0, 0x5AD0
    ctx->r4 = ADD32(ctx->r4, 0X5AD0);
    // 0x800899C8: jal         0x80099460
    // 0x800899CC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    gameexit(rdram, ctx);
        goto after_1;
    // 0x800899CC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_1:
    // 0x800899D0: lw          $v1, 0x40($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800899D4: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
L_800899D8:
    // 0x800899D8: andi        $t8, $a1, 0xC000
    ctx->r24 = ctx->r5 & 0XC000;
    // 0x800899DC: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x800899E0: bne         $t8, $at, L_80089BE4
    if (ctx->r24 != ctx->r1) {
        // 0x800899E4: addiu       $a3, $zero, 0x2C
        ctx->r7 = ADD32(0, 0X2C);
            goto L_80089BE4;
    }
    // 0x800899E4: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x800899E8: andi        $v0, $a1, 0xFFF
    ctx->r2 = ctx->r5 & 0XFFF;
    // 0x800899EC: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800899F0: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x800899F4: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x800899F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800899FC: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80089A00: lh          $t1, 0xC($t0)
    ctx->r9 = S32(MEM_H(ctx->r8, 0XC));
    // 0x80089A04: andi        $t2, $t1, 0x30
    ctx->r10 = ctx->r9 & 0X30;
    // 0x80089A08: bnel        $t2, $zero, L_80089BE8
    if (ctx->r10 != 0) {
        // 0x80089A0C: lw          $ra, 0x34($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
            goto L_80089BE8;
    }
    goto skip_0;
    // 0x80089A0C: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    skip_0:
    // 0x80089A10: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089A14: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80089A18: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80089A1C: mflo        $t3
    ctx->r11 = lo;
    // 0x80089A20: addu        $a0, $a2, $t3
    ctx->r4 = ADD32(ctx->r6, ctx->r11);
    // 0x80089A24: jal         0x80099ED4
    // 0x80089A28: nop

    badguy(rdram, ctx);
        goto after_2;
    // 0x80089A28: nop

    after_2:
    // 0x80089A2C: beq         $v0, $zero, L_80089A98
    if (ctx->r2 == 0) {
        // 0x80089A30: lw          $v1, 0x40($sp)
        ctx->r3 = S32(MEM_W(ctx->r29, 0X40));
            goto L_80089A98;
    }
    // 0x80089A30: lw          $v1, 0x40($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80089A34: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80089A38: lui         $t5, 0x8024
    ctx->r13 = S32(0X8024 << 16);
    // 0x80089A3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089A40: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x80089A44: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80089A48: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80089A4C: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80089A50: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80089A54: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80089A58: lbu         $t5, 0x6BCD($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X6BCD);
    // 0x80089A5C: beql        $t5, $at, L_80089A9C
    if (ctx->r13 == ctx->r1) {
        // 0x80089A60: lw          $a1, 0x50($sp)
        ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
            goto L_80089A9C;
    }
    goto skip_1;
    // 0x80089A60: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
    skip_1:
    // 0x80089A64: lh          $t6, 0x12($s0)
    ctx->r14 = S32(MEM_H(ctx->r16, 0X12));
    // 0x80089A68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089A6C: addiu       $t7, $zero, -0x4
    ctx->r15 = ADD32(0, -0X4);
    // 0x80089A70: beq         $t6, $at, L_80089BE4
    if (ctx->r14 == ctx->r1) {
        // 0x80089A74: addiu       $t8, $zero, -0x100
        ctx->r24 = ADD32(0, -0X100);
            goto L_80089BE4;
    }
    // 0x80089A74: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x80089A78: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80089A7C: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x80089A80: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x80089A84: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x80089A88: jal         0x80076190
    // 0x80089A8C: lh          $a0, 0x5A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X5A));
    ssp(rdram, ctx);
        goto after_3;
    // 0x80089A8C: lh          $a0, 0x5A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X5A));
    after_3:
    // 0x80089A90: b           L_80089BE8
    // 0x80089A94: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
        goto L_80089BE8;
    // 0x80089A94: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
L_80089A98:
    // 0x80089A98: lw          $a1, 0x50($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X50));
L_80089A9C:
    // 0x80089A9C: lui         $t0, 0x8024
    ctx->r8 = S32(0X8024 << 16);
    // 0x80089AA0: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x80089AA4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80089AA8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80089AAC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80089AB0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80089AB4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80089AB8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80089ABC: lh          $t0, 0x6BB6($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, 0X6BB6));
    // 0x80089AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089AC4: bnel        $t0, $at, L_80089B08
    if (ctx->r8 != ctx->r1) {
        // 0x80089AC8: lh          $t3, 0x12($s0)
        ctx->r11 = S32(MEM_H(ctx->r16, 0X12));
            goto L_80089B08;
    }
    goto skip_2;
    // 0x80089AC8: lh          $t3, 0x12($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X12));
    skip_2:
    // 0x80089ACC: jal         0x80099ED4
    // 0x80089AD0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    badguy(rdram, ctx);
        goto after_4;
    // 0x80089AD0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_4:
    // 0x80089AD4: beq         $v0, $zero, L_80089B04
    if (ctx->r2 == 0) {
        // 0x80089AD8: lw          $v1, 0x40($sp)
        ctx->r3 = S32(MEM_W(ctx->r29, 0X40));
            goto L_80089B04;
    }
    // 0x80089AD8: lw          $v1, 0x40($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X40));
    // 0x80089ADC: addiu       $t1, $zero, -0x4
    ctx->r9 = ADD32(0, -0X4);
    // 0x80089AE0: sh          $t1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r9;
    // 0x80089AE4: addiu       $t2, $zero, -0x100
    ctx->r10 = ADD32(0, -0X100);
    // 0x80089AE8: sh          $t2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r10;
    // 0x80089AEC: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80089AF0: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x80089AF4: jal         0x80076190
    // 0x80089AF8: lh          $a0, 0x5A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X5A));
    ssp(rdram, ctx);
        goto after_5;
    // 0x80089AF8: lh          $a0, 0x5A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X5A));
    after_5:
    // 0x80089AFC: b           L_80089BE8
    // 0x80089B00: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
        goto L_80089BE8;
    // 0x80089B00: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
L_80089B04:
    // 0x80089B04: lh          $t3, 0x12($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X12));
L_80089B08:
    // 0x80089B08: lw          $t4, 0x50($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80089B0C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089B10: bne         $t3, $at, L_80089BE4
    if (ctx->r11 != ctx->r1) {
        // 0x80089B14: sll         $t5, $t4, 2
        ctx->r13 = S32(ctx->r12 << 2);
            goto L_80089BE4;
    }
    // 0x80089B14: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80089B18: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80089B1C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80089B20: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80089B24: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80089B28: lui         $t6, 0x8024
    ctx->r14 = S32(0X8024 << 16);
    // 0x80089B2C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80089B30: lh          $t6, 0x6BB6($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X6BB6));
    // 0x80089B34: addiu       $at, $zero, 0x57D
    ctx->r1 = ADD32(0, 0X57D);
    // 0x80089B38: bnel        $t6, $at, L_80089BE8
    if (ctx->r14 != ctx->r1) {
        // 0x80089B3C: lw          $ra, 0x34($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
            goto L_80089BE8;
    }
    goto skip_3;
    // 0x80089B3C: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    skip_3:
    // 0x80089B40: lh          $t7, 0x16($s0)
    ctx->r15 = S32(MEM_H(ctx->r16, 0X16));
    // 0x80089B44: bnel        $t4, $t7, L_80089BE8
    if (ctx->r12 != ctx->r15) {
        // 0x80089B48: lw          $ra, 0x34($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
            goto L_80089BE8;
    }
    goto skip_4;
    // 0x80089B48: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
    skip_4:
    // 0x80089B4C: lh          $t8, 0x10($s0)
    ctx->r24 = S32(MEM_H(ctx->r16, 0X10));
    // 0x80089B50: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80089B54: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80089B58: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089B5C: addiu       $v0, $v0, -0x1988
    ctx->r2 = ADD32(ctx->r2, -0X1988);
    // 0x80089B60: mflo        $t9
    ctx->r25 = lo;
    // 0x80089B64: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80089B68: lw          $t1, 0x0($t0)
    ctx->r9 = S32(MEM_W(ctx->r8, 0X0));
    // 0x80089B6C: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x80089B70: lh          $t2, 0x10($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0X10));
    // 0x80089B74: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089B78: mflo        $t3
    ctx->r11 = lo;
    // 0x80089B7C: addu        $t5, $v0, $t3
    ctx->r13 = ADD32(ctx->r2, ctx->r11);
    // 0x80089B80: lw          $t6, 0x4($t5)
    ctx->r14 = S32(MEM_W(ctx->r13, 0X4));
    // 0x80089B84: b           L_80089BE4
    // 0x80089B88: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
        goto L_80089BE4;
    // 0x80089B88: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
L_80089B8C:
    // 0x80089B8C: lh          $t9, 0x10($s0)
    ctx->r25 = S32(MEM_H(ctx->r16, 0X10));
    // 0x80089B90: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80089B94: lh          $t4, 0x5A($sp)
    ctx->r12 = S32(MEM_H(ctx->r29, 0X5A));
    // 0x80089B98: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089B9C: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x80089BA0: addiu       $v0, $v0, -0x1988
    ctx->r2 = ADD32(ctx->r2, -0X1988);
    // 0x80089BA4: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x80089BA8: lui         $t8, 0x8028
    ctx->r24 = S32(0X8028 << 16);
    // 0x80089BAC: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x80089BB0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80089BB4: addiu       $t8, $t8, -0x5C00
    ctx->r24 = ADD32(ctx->r24, -0X5C00);
    // 0x80089BB8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80089BBC: mflo        $t0
    ctx->r8 = lo;
    // 0x80089BC0: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80089BC4: lw          $t2, 0x0($t1)
    ctx->r10 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80089BC8: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x80089BCC: lh          $t3, 0x10($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X10));
    // 0x80089BD0: multu       $t3, $a0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089BD4: mflo        $t5
    ctx->r13 = lo;
    // 0x80089BD8: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80089BDC: lw          $t4, 0x4($t6)
    ctx->r12 = S32(MEM_W(ctx->r14, 0X4));
    // 0x80089BE0: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
L_80089BE4:
    // 0x80089BE4: lw          $ra, 0x34($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X34));
L_80089BE8:
    // 0x80089BE8: lw          $s0, 0x30($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80089BEC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80089BF0: jr          $ra
    // 0x80089BF4: nop

    return;
    // 0x80089BF4: nop

;}
RECOMP_FUNC void hitscan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009324C: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x80093250: lw          $t8, 0x19C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80093254: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80093258: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8009325C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80093260: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80093264: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80093268: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8009326C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80093270: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80093274: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80093278: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009327C: sw          $a0, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r4;
    // 0x80093280: sw          $a1, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r5;
    // 0x80093284: sw          $a2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r6;
    // 0x80093288: sw          $a3, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r7;
    // 0x8009328C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80093290: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
    // 0x80093294: lw          $t9, 0x1A0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1A0));
    // 0x80093298: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x8009329C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800932A0: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x800932A4: lw          $t1, 0x1A4($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1A4));
    // 0x800932A8: bgez        $a3, L_800932B8
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800932AC: sh          $v0, 0x0($t1)
        MEM_H(0X0, ctx->r9) = ctx->r2;
            goto L_800932B8;
    }
    // 0x800932AC: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x800932B0: b           L_800949F4
    // 0x800932B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800949F4;
    // 0x800932B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800932B8:
    // 0x800932B8: lw          $t2, 0x1A8($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x800932BC: lui         $v1, 0x1FFF
    ctx->r3 = S32(0X1FFF << 16);
    // 0x800932C0: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x800932C4: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x800932C8: lw          $t3, 0x1AC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x800932CC: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x800932D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800932D4: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    // 0x800932D8: sh          $a3, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = ctx->r7;
    // 0x800932DC: sh          $t4, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r12;
    // 0x800932E0: sh          $zero, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = 0;
    // 0x800932E4: lh          $t5, 0xC6($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XC6));
L_800932E8:
    // 0x800932E8: lui         $t7, 0x8028
    ctx->r15 = S32(0X8028 << 16);
    // 0x800932EC: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x800932F0: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800932F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800932F8: lh          $t7, -0x70D0($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X70D0));
    // 0x800932FC: addiu       $t1, $t1, -0x1988
    ctx->r9 = ADD32(ctx->r9, -0X1988);
    // 0x80093300: lui         $t8, 0x7FFF
    ctx->r24 = S32(0X7FFF << 16);
    // 0x80093304: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80093308: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8009330C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80093310: addu        $s5, $t9, $t1
    ctx->r21 = ADD32(ctx->r25, ctx->r9);
    // 0x80093314: lh          $t2, 0xC($s5)
    ctx->r10 = S32(MEM_H(ctx->r21, 0XC));
    // 0x80093318: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8009331C: sw          $t8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r24;
    // 0x80093320: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80093324: beq         $t3, $zero, L_8009355C
    if (ctx->r11 == 0) {
        // 0x80093328: sh          $t7, 0xC2($sp)
        MEM_H(0XC2, ctx->r29) = ctx->r15;
            goto L_8009355C;
    }
    // 0x80093328: sh          $t7, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r15;
    // 0x8009332C: lh          $t4, 0x8($s5)
    ctx->r12 = S32(MEM_H(ctx->r21, 0X8));
    // 0x80093330: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x80093334: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80093338: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009333C: addiu       $a1, $a1, 0x61A8
    ctx->r5 = ADD32(ctx->r5, 0X61A8);
    // 0x80093340: mflo        $t5
    ctx->r13 = lo;
    // 0x80093344: addu        $s2, $a1, $t5
    ctx->r18 = ADD32(ctx->r5, ctx->r13);
    // 0x80093348: lh          $t6, 0x8($s2)
    ctx->r14 = S32(MEM_H(ctx->r18, 0X8));
    // 0x8009334C: lw          $t9, 0x0($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80093350: lw          $t2, 0x4($s2)
    ctx->r10 = S32(MEM_W(ctx->r18, 0X4));
    // 0x80093354: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093358: mflo        $t8
    ctx->r24 = lo;
    // 0x8009335C: addu        $v0, $a1, $t8
    ctx->r2 = ADD32(ctx->r5, ctx->r24);
    // 0x80093360: lw          $t7, 0x0($v0)
    ctx->r15 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80093364: lw          $t1, 0x4($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80093368: subu        $s4, $t7, $t9
    ctx->r20 = SUB32(ctx->r15, ctx->r25);
    // 0x8009336C: multu       $s4, $s4
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093370: subu        $v1, $t1, $t2
    ctx->r3 = SUB32(ctx->r9, ctx->r10);
    // 0x80093374: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    // 0x80093378: mflo        $t3
    ctx->r11 = lo;
    // 0x8009337C: nop

    // 0x80093380: nop

    // 0x80093384: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093388: mflo        $t4
    ctx->r12 = lo;
    // 0x8009338C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80093390: jal         0x80091A00
    // 0x80093394: nop

    nsqrtasm(rdram, ctx);
        goto after_0;
    // 0x80093394: nop

    after_0:
    // 0x80093398: beq         $v0, $zero, L_800949DC
    if (ctx->r2 == 0) {
        // 0x8009339C: lw          $fp, 0xF4($sp)
        ctx->r30 = S32(MEM_W(ctx->r29, 0XF4));
            goto L_800949DC;
    }
    // 0x8009339C: lw          $fp, 0xF4($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0XF4));
    // 0x800933A0: lh          $a1, 0x12($s5)
    ctx->r5 = S32(MEM_H(ctx->r21, 0X12));
    // 0x800933A4: lw          $t6, 0x194($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X194));
    // 0x800933A8: lw          $t7, 0x190($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X190));
    // 0x800933AC: lw          $s3, 0x198($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X198));
    // 0x800933B0: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800933B4: sra         $t2, $t7, 31
    ctx->r10 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800933B8: sll         $t1, $s3, 8
    ctx->r9 = S32(ctx->r19 << 8);
    // 0x800933BC: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x800933C0: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x800933C4: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x800933C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800933CC: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800933D0: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800933D4: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x800933D8: jal         0x80091458
    // 0x800933DC: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    divscale15(rdram, ctx);
        goto after_1;
    // 0x800933DC: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    after_1:
    // 0x800933E0: multu       $s4, $v0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800933E4: lw          $t2, 0x80($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800933E8: lw          $t3, 0x84($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800933EC: lw          $a2, 0x90($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X90));
    // 0x800933F0: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800933F4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800933F8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800933FC: mflo        $a1
    ctx->r5 = lo;
    // 0x80093400: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80093404: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80093408: multu       $fp, $v0
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009340C: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80093410: mflo        $fp
    ctx->r30 = lo;
    // 0x80093414: negu        $t6, $fp
    ctx->r14 = SUB32(0, ctx->r30);
    // 0x80093418: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8009341C: sw          $t8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r24;
    // 0x80093420: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80093424: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x80093428: jal         0x80090804
    // 0x8009342C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    dmulscale15(rdram, ctx);
        goto after_2;
    // 0x8009342C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_2:
    // 0x80093430: subu        $s0, $s3, $v0
    ctx->r16 = SUB32(ctx->r19, ctx->r2);
    // 0x80093434: beq         $s0, $zero, L_80093618
    if (ctx->r16 == 0) {
        // 0x80093438: lw          $t7, 0x184($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X184));
            goto L_80093618;
    }
    // 0x80093438: lw          $t7, 0x184($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X184));
    // 0x8009343C: lw          $t1, 0x4($s2)
    ctx->r9 = S32(MEM_W(ctx->r18, 0X4));
    // 0x80093440: lw          $t6, 0x88($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80093444: lw          $t5, 0x180($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093448: subu        $a3, $t7, $t1
    ctx->r7 = SUB32(ctx->r15, ctx->r9);
    // 0x8009344C: lw          $t7, 0x8C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x80093450: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80093454: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80093458: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009345C: lw          $t8, 0x0($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80093460: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80093464: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80093468: subu        $t9, $t5, $t8
    ctx->r25 = SUB32(ctx->r13, ctx->r24);
    // 0x8009346C: sra         $t2, $t9, 31
    ctx->r10 = S32(SIGNED(ctx->r25) >> 31);
    // 0x80093470: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80093474: jal         0x80090804
    // 0x80093478: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    dmulscale15(rdram, ctx);
        goto after_3;
    // 0x80093478: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_3:
    // 0x8009347C: lw          $t1, 0x0($s5)
    ctx->r9 = S32(MEM_W(ctx->r21, 0X0));
    // 0x80093480: lw          $t4, 0x188($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80093484: subu        $t6, $t1, $t4
    ctx->r14 = SUB32(ctx->r9, ctx->r12);
    // 0x80093488: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8009348C: addu        $s1, $v0, $t7
    ctx->r17 = ADD32(ctx->r2, ctx->r15);
    // 0x80093490: xor         $t5, $s1, $s0
    ctx->r13 = ctx->r17 ^ ctx->r16;
    // 0x80093494: bltzl       $t5, L_8009361C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80093498: lw          $t8, 0x164($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X164));
            goto L_8009361C;
    }
    goto skip_0;
    // 0x80093498: lw          $t8, 0x164($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X164));
    skip_0:
    // 0x8009349C: blez        $s1, L_800934AC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800934A0: negu        $a0, $s1
        ctx->r4 = SUB32(0, ctx->r17);
            goto L_800934AC;
    }
    // 0x800934A0: negu        $a0, $s1
    ctx->r4 = SUB32(0, ctx->r17);
    // 0x800934A4: b           L_800934AC
    // 0x800934A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800934AC;
    // 0x800934A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800934AC:
    // 0x800934AC: blez        $s0, L_800934BC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800934B0: sra         $t8, $a0, 1
        ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800934BC;
    }
    // 0x800934B0: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800934B4: b           L_800934C0
    // 0x800934B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800934C0;
    // 0x800934B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800934BC:
    // 0x800934BC: negu        $v0, $s0
    ctx->r2 = SUB32(0, ctx->r16);
L_800934C0:
    // 0x800934C0: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800934C4: beq         $at, $zero, L_80093618
    if (ctx->r1 == 0) {
        // 0x800934C8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80093618;
    }
    // 0x800934C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800934CC: lw          $t9, 0x198($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X198));
    // 0x800934D0: sra         $a0, $s1, 31
    ctx->r4 = S32(SIGNED(ctx->r17) >> 31);
    // 0x800934D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800934D8: sra         $t2, $t9, 31
    ctx->r10 = S32(SIGNED(ctx->r25) >> 31);
    // 0x800934DC: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    // 0x800934E0: sra         $a2, $s0, 31
    ctx->r6 = S32(SIGNED(ctx->r16) >> 31);
    // 0x800934E4: jal         0x800918CC
    // 0x800934E8: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    divscale30(rdram, ctx);
        goto after_4;
    // 0x800934E8: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    after_4:
    // 0x800934EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800934F0: lw          $a0, 0x80($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800934F4: lw          $a1, 0x84($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800934F8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800934FC: jal         0x80090118
    // 0x80093500: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    mulscale30(rdram, ctx);
        goto after_5;
    // 0x80093500: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    after_5:
    // 0x80093504: lw          $t1, 0x180($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093508: sra         $a2, $s1, 31
    ctx->r6 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8009350C: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80093510: addu        $t4, $v0, $t1
    ctx->r12 = ADD32(ctx->r2, ctx->r9);
    // 0x80093514: sw          $t4, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r12;
    // 0x80093518: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x8009351C: lw          $a1, 0x94($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X94));
    // 0x80093520: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x80093524: jal         0x80090118
    // 0x80093528: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    mulscale30(rdram, ctx);
        goto after_6;
    // 0x80093528: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x8009352C: lw          $t5, 0x184($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093530: lw          $a0, 0x88($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80093534: lw          $a1, 0x8C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x80093538: addu        $t8, $v0, $t5
    ctx->r24 = ADD32(ctx->r2, ctx->r13);
    // 0x8009353C: sw          $t8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r24;
    // 0x80093540: lw          $a2, 0x98($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80093544: jal         0x80090118
    // 0x80093548: lw          $a3, 0x9C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X9C));
    mulscale30(rdram, ctx);
        goto after_7;
    // 0x80093548: lw          $a3, 0x9C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X9C));
    after_7:
    // 0x8009354C: lw          $t9, 0x188($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80093550: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80093554: b           L_80093618
    // 0x80093558: sw          $t2, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r10;
        goto L_80093618;
    // 0x80093558: sw          $t2, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r10;
L_8009355C:
    // 0x8009355C: lw          $t3, 0x198($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X198));
    // 0x80093560: lw          $t1, 0x188($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80093564: bgezl       $t3, L_8009361C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80093568: lw          $t8, 0x164($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X164));
            goto L_8009361C;
    }
    goto skip_1;
    // 0x80093568: lw          $t8, 0x164($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X164));
    skip_1:
    // 0x8009356C: lw          $v0, 0x0($s5)
    ctx->r2 = S32(MEM_W(ctx->r21, 0X0));
    // 0x80093570: negu        $v1, $t3
    ctx->r3 = SUB32(0, ctx->r11);
    // 0x80093574: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80093578: bne         $at, $zero, L_80093618
    if (ctx->r1 != 0) {
        // 0x8009357C: subu        $s0, $v0, $t1
        ctx->r16 = SUB32(ctx->r2, ctx->r9);
            goto L_80093618;
    }
    // 0x8009357C: subu        $s0, $v0, $t1
    ctx->r16 = SUB32(ctx->r2, ctx->r9);
    // 0x80093580: blez        $s0, L_80093590
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80093584: sw          $v0, 0x15C($sp)
        MEM_W(0X15C, ctx->r29) = ctx->r2;
            goto L_80093590;
    }
    // 0x80093584: sw          $v0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r2;
    // 0x80093588: b           L_80093594
    // 0x8009358C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80093594;
    // 0x8009358C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80093590:
    // 0x80093590: negu        $v0, $s0
    ctx->r2 = SUB32(0, ctx->r16);
L_80093594:
    // 0x80093594: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80093598: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8009359C: beq         $at, $zero, L_80093618
    if (ctx->r1 == 0) {
        // 0x800935A0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80093618;
    }
    // 0x800935A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800935A4: lw          $t7, 0x194($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X194));
    // 0x800935A8: lw          $t5, 0x190($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X190));
    // 0x800935AC: lw          $a3, 0x198($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X198));
    // 0x800935B0: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800935B4: sra         $t2, $t5, 31
    ctx->r10 = S32(SIGNED(ctx->r13) >> 31);
    // 0x800935B8: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x800935BC: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x800935C0: sra         $a0, $s0, 31
    ctx->r4 = S32(SIGNED(ctx->r16) >> 31);
    // 0x800935C4: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x800935C8: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    // 0x800935CC: jal         0x800918CC
    // 0x800935D0: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    divscale30(rdram, ctx);
        goto after_8;
    // 0x800935D0: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_8:
    // 0x800935D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800935D8: lw          $a0, 0x80($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800935DC: lw          $a1, 0x84($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800935E0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800935E4: jal         0x80090118
    // 0x800935E8: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    mulscale30(rdram, ctx);
        goto after_9;
    // 0x800935E8: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    after_9:
    // 0x800935EC: lw          $t1, 0x180($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X180));
    // 0x800935F0: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x800935F4: lw          $a1, 0x94($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800935F8: addu        $t4, $v0, $t1
    ctx->r12 = ADD32(ctx->r2, ctx->r9);
    // 0x800935FC: sw          $t4, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r12;
    // 0x80093600: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80093604: jal         0x80090118
    // 0x80093608: sra         $a2, $s1, 31
    ctx->r6 = S32(SIGNED(ctx->r17) >> 31);
    mulscale30(rdram, ctx);
        goto after_10;
    // 0x80093608: sra         $a2, $s1, 31
    ctx->r6 = S32(SIGNED(ctx->r17) >> 31);
    after_10:
    // 0x8009360C: lw          $t6, 0x184($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093610: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80093614: sw          $t7, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r15;
L_80093618:
    // 0x80093618: lw          $t8, 0x164($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X164));
L_8009361C:
    // 0x8009361C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80093620: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80093624: beq         $t8, $at, L_80093708
    if (ctx->r24 == ctx->r1) {
        // 0x80093628: lw          $a0, 0x184($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X184));
            goto L_80093708;
    }
    // 0x80093628: lw          $a0, 0x184($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X184));
    // 0x8009362C: lw          $t5, 0x1A8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80093630: lw          $t1, 0x1AC($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x80093634: lw          $t9, 0x160($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80093638: lw          $t3, 0x180($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X180));
    // 0x8009363C: lw          $t2, 0x0($t5)
    ctx->r10 = S32(MEM_W(ctx->r13, 0X0));
    // 0x80093640: lw          $t4, 0x0($t1)
    ctx->r12 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80093644: subu        $s4, $t9, $a0
    ctx->r20 = SUB32(ctx->r25, ctx->r4);
    // 0x80093648: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x8009364C: blez        $s4, L_8009365C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80093650: subu        $v1, $t4, $a0
        ctx->r3 = SUB32(ctx->r12, ctx->r4);
            goto L_8009365C;
    }
    // 0x80093650: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x80093654: b           L_80093660
    // 0x80093658: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
        goto L_80093660;
    // 0x80093658: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
L_8009365C:
    // 0x8009365C: negu        $a2, $s4
    ctx->r6 = SUB32(0, ctx->r20);
L_80093660:
    // 0x80093660: lw          $t6, 0x164($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80093664: lw          $t7, 0x180($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093668: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x8009366C: subu        $s6, $t6, $t7
    ctx->r22 = SUB32(ctx->r14, ctx->r15);
    // 0x80093670: blez        $s6, L_80093680
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80093674: negu        $a1, $s6
        ctx->r5 = SUB32(0, ctx->r22);
            goto L_80093680;
    }
    // 0x80093674: negu        $a1, $s6
    ctx->r5 = SUB32(0, ctx->r22);
    // 0x80093678: b           L_80093680
    // 0x8009367C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
        goto L_80093680;
    // 0x8009367C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
L_80093680:
    // 0x80093680: blez        $v0, L_80093690
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80093684: addu        $t8, $a1, $a2
        ctx->r24 = ADD32(ctx->r5, ctx->r6);
            goto L_80093690;
    }
    // 0x80093684: addu        $t8, $a1, $a2
    ctx->r24 = ADD32(ctx->r5, ctx->r6);
    // 0x80093688: b           L_80093690
    // 0x8009368C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80093690;
    // 0x8009368C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80093690:
    // 0x80093690: blez        $v1, L_800936A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80093694: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_800936A0;
    }
    // 0x80093694: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80093698: b           L_800936A0
    // 0x8009369C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800936A0;
    // 0x8009369C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800936A0:
    // 0x800936A0: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x800936A4: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800936A8: beq         $at, $zero, L_80093708
    if (ctx->r1 == 0) {
        // 0x800936AC: lw          $a0, 0x164($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X164));
            goto L_80093708;
    }
    // 0x800936AC: lw          $a0, 0x164($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X164));
    // 0x800936B0: lw          $a1, 0x160($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X160));
    // 0x800936B4: jal         0x80091E14
    // 0x800936B8: lh          $a2, 0xC2($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0XC2));
    inside(rdram, ctx);
        goto after_11;
    // 0x800936B8: lh          $a2, 0xC2($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0XC2));
    after_11:
    // 0x800936BC: beq         $v0, $zero, L_80093708
    if (ctx->r2 == 0) {
        // 0x800936C0: lh          $t5, 0xC2($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XC2));
            goto L_80093708;
    }
    // 0x800936C0: lh          $t5, 0xC2($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x800936C4: lw          $t2, 0x19C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x800936C8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800936CC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800936D0: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x800936D4: lw          $t1, 0x1A0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1A0));
    // 0x800936D8: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x800936DC: lw          $t6, 0x1A4($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1A4));
    // 0x800936E0: sh          $t4, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r12;
    // 0x800936E4: lw          $t8, 0x1A8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x800936E8: lw          $t7, 0x164($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X164));
    // 0x800936EC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800936F0: lw          $t5, 0x1AC($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x800936F4: lw          $t9, 0x160($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X160));
    // 0x800936F8: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800936FC: lw          $t3, 0x1B0($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x80093700: lw          $t2, 0x15C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X15C));
    // 0x80093704: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_80093708:
    // 0x80093708: lui         $t1, 0x7FFF
    ctx->r9 = S32(0X7FFF << 16);
    // 0x8009370C: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80093710: sw          $t1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r9;
    // 0x80093714: lh          $t4, 0xE($s5)
    ctx->r12 = S32(MEM_H(ctx->r21, 0XE));
    // 0x80093718: lw          $t5, 0x198($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X198));
    // 0x8009371C: andi        $t6, $t4, 0x2
    ctx->r14 = ctx->r12 & 0X2;
    // 0x80093720: beq         $t6, $zero, L_80093958
    if (ctx->r14 == 0) {
        // 0x80093724: nop
    
            goto L_80093958;
    }
    // 0x80093724: nop

    // 0x80093728: lh          $t7, 0x8($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X8));
    // 0x8009372C: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x80093730: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x80093734: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093738: addiu       $a1, $a1, 0x61A8
    ctx->r5 = ADD32(ctx->r5, 0X61A8);
    // 0x8009373C: mflo        $t8
    ctx->r24 = lo;
    // 0x80093740: addu        $s2, $a1, $t8
    ctx->r18 = ADD32(ctx->r5, ctx->r24);
    // 0x80093744: lh          $t9, 0x8($s2)
    ctx->r25 = S32(MEM_H(ctx->r18, 0X8));
    // 0x80093748: lw          $t3, 0x0($s2)
    ctx->r11 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8009374C: lw          $t4, 0x4($s2)
    ctx->r12 = S32(MEM_W(ctx->r18, 0X4));
    // 0x80093750: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093754: mflo        $t5
    ctx->r13 = lo;
    // 0x80093758: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
    // 0x8009375C: lw          $t2, 0x0($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80093760: lw          $t1, 0x4($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80093764: subu        $s4, $t2, $t3
    ctx->r20 = SUB32(ctx->r10, ctx->r11);
    // 0x80093768: multu       $s4, $s4
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009376C: subu        $v1, $t1, $t4
    ctx->r3 = SUB32(ctx->r9, ctx->r12);
    // 0x80093770: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    // 0x80093774: mflo        $t6
    ctx->r14 = lo;
    // 0x80093778: nop

    // 0x8009377C: nop

    // 0x80093780: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093784: mflo        $t7
    ctx->r15 = lo;
    // 0x80093788: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8009378C: jal         0x80091A00
    // 0x80093790: nop

    nsqrtasm(rdram, ctx);
        goto after_12;
    // 0x80093790: nop

    after_12:
    // 0x80093794: beq         $v0, $zero, L_800949DC
    if (ctx->r2 == 0) {
        // 0x80093798: lw          $fp, 0xF4($sp)
        ctx->r30 = S32(MEM_W(ctx->r29, 0XF4));
            goto L_800949DC;
    }
    // 0x80093798: lw          $fp, 0xF4($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0XF4));
    // 0x8009379C: lh          $a1, 0x16($s5)
    ctx->r5 = S32(MEM_H(ctx->r21, 0X16));
    // 0x800937A0: lw          $t9, 0x194($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X194));
    // 0x800937A4: lw          $t5, 0x190($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X190));
    // 0x800937A8: lw          $s3, 0x198($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X198));
    // 0x800937AC: sra         $t2, $t9, 31
    ctx->r10 = S32(SIGNED(ctx->r25) >> 31);
    // 0x800937B0: sra         $t4, $t5, 31
    ctx->r12 = S32(SIGNED(ctx->r13) >> 31);
    // 0x800937B4: sll         $t1, $s3, 8
    ctx->r9 = S32(ctx->r19 << 8);
    // 0x800937B8: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x800937BC: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x800937C0: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800937C4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800937C8: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800937CC: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800937D0: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800937D4: jal         0x80091458
    // 0x800937D8: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    divscale15(rdram, ctx);
        goto after_13;
    // 0x800937D8: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    after_13:
    // 0x800937DC: multu       $s4, $v0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800937E0: lw          $t4, 0x80($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800937E4: lw          $t5, 0x84($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800937E8: lw          $a2, 0x90($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X90));
    // 0x800937EC: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800937F0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800937F4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800937F8: mflo        $a1
    ctx->r5 = lo;
    // 0x800937FC: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80093800: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80093804: multu       $fp, $v0
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093808: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8009380C: mflo        $fp
    ctx->r30 = lo;
    // 0x80093810: negu        $t8, $fp
    ctx->r24 = SUB32(0, ctx->r30);
    // 0x80093814: sra         $t2, $t8, 31
    ctx->r10 = S32(SIGNED(ctx->r24) >> 31);
    // 0x80093818: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    // 0x8009381C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80093820: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x80093824: jal         0x80090804
    // 0x80093828: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    dmulscale15(rdram, ctx);
        goto after_14;
    // 0x80093828: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_14:
    // 0x8009382C: subu        $s0, $s3, $v0
    ctx->r16 = SUB32(ctx->r19, ctx->r2);
    // 0x80093830: beq         $s0, $zero, L_80093A0C
    if (ctx->r16 == 0) {
        // 0x80093834: lw          $t9, 0x184($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0X184));
            goto L_80093A0C;
    }
    // 0x80093834: lw          $t9, 0x184($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093838: lw          $t1, 0x4($s2)
    ctx->r9 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8009383C: lw          $t8, 0x88($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80093840: lw          $t7, 0x180($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093844: subu        $a3, $t9, $t1
    ctx->r7 = SUB32(ctx->r25, ctx->r9);
    // 0x80093848: lw          $t9, 0x8C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x8009384C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80093850: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80093854: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80093858: lw          $t2, 0x0($s2)
    ctx->r10 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8009385C: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80093860: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80093864: subu        $t3, $t7, $t2
    ctx->r11 = SUB32(ctx->r15, ctx->r10);
    // 0x80093868: sra         $t4, $t3, 31
    ctx->r12 = S32(SIGNED(ctx->r11) >> 31);
    // 0x8009386C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80093870: jal         0x80090804
    // 0x80093874: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    dmulscale15(rdram, ctx);
        goto after_15;
    // 0x80093874: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_15:
    // 0x80093878: lw          $t1, 0x4($s5)
    ctx->r9 = S32(MEM_W(ctx->r21, 0X4));
    // 0x8009387C: lw          $t6, 0x188($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80093880: subu        $t8, $t1, $t6
    ctx->r24 = SUB32(ctx->r9, ctx->r14);
    // 0x80093884: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80093888: addu        $s1, $v0, $t9
    ctx->r17 = ADD32(ctx->r2, ctx->r25);
    // 0x8009388C: xor         $t7, $s1, $s0
    ctx->r15 = ctx->r17 ^ ctx->r16;
    // 0x80093890: bltzl       $t7, L_80093A10
    if (SIGNED(ctx->r15) < 0) {
        // 0x80093894: lw          $t2, 0x164($sp)
        ctx->r10 = S32(MEM_W(ctx->r29, 0X164));
            goto L_80093A10;
    }
    goto skip_2;
    // 0x80093894: lw          $t2, 0x164($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X164));
    skip_2:
    // 0x80093898: blez        $s1, L_800938A8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8009389C: negu        $a0, $s1
        ctx->r4 = SUB32(0, ctx->r17);
            goto L_800938A8;
    }
    // 0x8009389C: negu        $a0, $s1
    ctx->r4 = SUB32(0, ctx->r17);
    // 0x800938A0: b           L_800938A8
    // 0x800938A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800938A8;
    // 0x800938A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800938A8:
    // 0x800938A8: blez        $s0, L_800938B8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800938AC: sra         $t2, $a0, 1
        ctx->r10 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800938B8;
    }
    // 0x800938AC: sra         $t2, $a0, 1
    ctx->r10 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800938B0: b           L_800938BC
    // 0x800938B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800938BC;
    // 0x800938B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800938B8:
    // 0x800938B8: negu        $v0, $s0
    ctx->r2 = SUB32(0, ctx->r16);
L_800938BC:
    // 0x800938BC: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800938C0: beq         $at, $zero, L_80093A0C
    if (ctx->r1 == 0) {
        // 0x800938C4: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80093A0C;
    }
    // 0x800938C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800938C8: lw          $t3, 0x198($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X198));
    // 0x800938CC: sra         $a0, $s1, 31
    ctx->r4 = S32(SIGNED(ctx->r17) >> 31);
    // 0x800938D0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800938D4: sra         $t4, $t3, 31
    ctx->r12 = S32(SIGNED(ctx->r11) >> 31);
    // 0x800938D8: sw          $t4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r12;
    // 0x800938DC: sra         $a2, $s0, 31
    ctx->r6 = S32(SIGNED(ctx->r16) >> 31);
    // 0x800938E0: jal         0x800918CC
    // 0x800938E4: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    divscale30(rdram, ctx);
        goto after_16;
    // 0x800938E4: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    after_16:
    // 0x800938E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800938EC: lw          $a0, 0x80($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800938F0: lw          $a1, 0x84($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800938F4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800938F8: jal         0x80090118
    // 0x800938FC: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    mulscale30(rdram, ctx);
        goto after_17;
    // 0x800938FC: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    after_17:
    // 0x80093900: lw          $t1, 0x180($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093904: sra         $a2, $s1, 31
    ctx->r6 = S32(SIGNED(ctx->r17) >> 31);
    // 0x80093908: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x8009390C: addu        $t6, $v0, $t1
    ctx->r14 = ADD32(ctx->r2, ctx->r9);
    // 0x80093910: sw          $t6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r14;
    // 0x80093914: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x80093918: lw          $a1, 0x94($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X94));
    // 0x8009391C: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x80093920: jal         0x80090118
    // 0x80093924: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    mulscale30(rdram, ctx);
        goto after_18;
    // 0x80093924: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_18:
    // 0x80093928: lw          $t7, 0x184($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X184));
    // 0x8009392C: lw          $a0, 0x88($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80093930: lw          $a1, 0x8C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x80093934: addu        $t2, $v0, $t7
    ctx->r10 = ADD32(ctx->r2, ctx->r15);
    // 0x80093938: sw          $t2, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r10;
    // 0x8009393C: lw          $a2, 0x98($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80093940: jal         0x80090118
    // 0x80093944: lw          $a3, 0x9C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X9C));
    mulscale30(rdram, ctx);
        goto after_19;
    // 0x80093944: lw          $a3, 0x9C($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X9C));
    after_19:
    // 0x80093948: lw          $t3, 0x188($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X188));
    // 0x8009394C: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80093950: b           L_80093A0C
    // 0x80093954: sw          $t4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r12;
        goto L_80093A0C;
    // 0x80093954: sw          $t4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r12;
L_80093958:
    // 0x80093958: blez        $t5, L_80093A0C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8009395C: lw          $t1, 0x188($sp)
        ctx->r9 = S32(MEM_W(ctx->r29, 0X188));
            goto L_80093A0C;
    }
    // 0x8009395C: lw          $t1, 0x188($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80093960: lw          $v0, 0x4($s5)
    ctx->r2 = S32(MEM_W(ctx->r21, 0X4));
    // 0x80093964: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80093968: bne         $at, $zero, L_80093A0C
    if (ctx->r1 != 0) {
        // 0x8009396C: subu        $s0, $v0, $t1
        ctx->r16 = SUB32(ctx->r2, ctx->r9);
            goto L_80093A0C;
    }
    // 0x8009396C: subu        $s0, $v0, $t1
    ctx->r16 = SUB32(ctx->r2, ctx->r9);
    // 0x80093970: blez        $s0, L_80093980
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80093974: sw          $v0, 0x15C($sp)
        MEM_W(0X15C, ctx->r29) = ctx->r2;
            goto L_80093980;
    }
    // 0x80093974: sw          $v0, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r2;
    // 0x80093978: b           L_80093984
    // 0x8009397C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80093984;
    // 0x8009397C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80093980:
    // 0x80093980: negu        $v0, $s0
    ctx->r2 = SUB32(0, ctx->r16);
L_80093984:
    // 0x80093984: lw          $t8, 0x198($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X198));
    // 0x80093988: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8009398C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80093990: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80093994: beq         $at, $zero, L_80093A0C
    if (ctx->r1 == 0) {
        // 0x80093998: sra         $a0, $s0, 31
        ctx->r4 = S32(SIGNED(ctx->r16) >> 31);
            goto L_80093A0C;
    }
    // 0x80093998: sra         $a0, $s0, 31
    ctx->r4 = S32(SIGNED(ctx->r16) >> 31);
    // 0x8009399C: lw          $t9, 0x194($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X194));
    // 0x800939A0: lw          $t7, 0x190($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X190));
    // 0x800939A4: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800939A8: sra         $t2, $t9, 31
    ctx->r10 = S32(SIGNED(ctx->r25) >> 31);
    // 0x800939AC: sra         $t4, $t7, 31
    ctx->r12 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800939B0: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x800939B4: sw          $t2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r10;
    // 0x800939B8: sra         $a2, $t8, 31
    ctx->r6 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800939BC: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800939C0: jal         0x800918CC
    // 0x800939C4: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    divscale30(rdram, ctx);
        goto after_20;
    // 0x800939C4: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    after_20:
    // 0x800939C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800939CC: lw          $a0, 0x80($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X80));
    // 0x800939D0: lw          $a1, 0x84($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X84));
    // 0x800939D4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800939D8: jal         0x80090118
    // 0x800939DC: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    mulscale30(rdram, ctx);
        goto after_21;
    // 0x800939DC: sra         $a2, $v0, 31
    ctx->r6 = S32(SIGNED(ctx->r2) >> 31);
    after_21:
    // 0x800939E0: lw          $t1, 0x180($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X180));
    // 0x800939E4: lw          $a0, 0x90($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X90));
    // 0x800939E8: lw          $a1, 0x94($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800939EC: addu        $t6, $v0, $t1
    ctx->r14 = ADD32(ctx->r2, ctx->r9);
    // 0x800939F0: sw          $t6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r14;
    // 0x800939F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800939F8: jal         0x80090118
    // 0x800939FC: sra         $a2, $s1, 31
    ctx->r6 = S32(SIGNED(ctx->r17) >> 31);
    mulscale30(rdram, ctx);
        goto after_22;
    // 0x800939FC: sra         $a2, $s1, 31
    ctx->r6 = S32(SIGNED(ctx->r17) >> 31);
    after_22:
    // 0x80093A00: lw          $t8, 0x184($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093A04: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80093A08: sw          $t9, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r25;
L_80093A0C:
    // 0x80093A0C: lw          $t2, 0x164($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X164));
L_80093A10:
    // 0x80093A10: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80093A14: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80093A18: beq         $t2, $at, L_80093AF8
    if (ctx->r10 == ctx->r1) {
        // 0x80093A1C: lw          $a0, 0x184($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X184));
            goto L_80093AF8;
    }
    // 0x80093A1C: lw          $a0, 0x184($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093A20: lw          $t7, 0x1A8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80093A24: lw          $t1, 0x1AC($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x80093A28: lw          $t3, 0x160($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80093A2C: lw          $t5, 0x180($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093A30: lw          $t4, 0x0($t7)
    ctx->r12 = S32(MEM_W(ctx->r15, 0X0));
    // 0x80093A34: lw          $t6, 0x0($t1)
    ctx->r14 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80093A38: subu        $s4, $t3, $a0
    ctx->r20 = SUB32(ctx->r11, ctx->r4);
    // 0x80093A3C: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x80093A40: blez        $s4, L_80093A50
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80093A44: subu        $v1, $t6, $a0
        ctx->r3 = SUB32(ctx->r14, ctx->r4);
            goto L_80093A50;
    }
    // 0x80093A44: subu        $v1, $t6, $a0
    ctx->r3 = SUB32(ctx->r14, ctx->r4);
    // 0x80093A48: b           L_80093A54
    // 0x80093A4C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
        goto L_80093A54;
    // 0x80093A4C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
L_80093A50:
    // 0x80093A50: negu        $a2, $s4
    ctx->r6 = SUB32(0, ctx->r20);
L_80093A54:
    // 0x80093A54: lw          $t8, 0x164($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80093A58: lw          $t9, 0x180($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093A5C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80093A60: subu        $s6, $t8, $t9
    ctx->r22 = SUB32(ctx->r24, ctx->r25);
    // 0x80093A64: blez        $s6, L_80093A74
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80093A68: negu        $a1, $s6
        ctx->r5 = SUB32(0, ctx->r22);
            goto L_80093A74;
    }
    // 0x80093A68: negu        $a1, $s6
    ctx->r5 = SUB32(0, ctx->r22);
    // 0x80093A6C: b           L_80093A74
    // 0x80093A70: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
        goto L_80093A74;
    // 0x80093A70: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
L_80093A74:
    // 0x80093A74: blez        $v0, L_80093A84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80093A78: addu        $t2, $a1, $a2
        ctx->r10 = ADD32(ctx->r5, ctx->r6);
            goto L_80093A84;
    }
    // 0x80093A78: addu        $t2, $a1, $a2
    ctx->r10 = ADD32(ctx->r5, ctx->r6);
    // 0x80093A7C: b           L_80093A84
    // 0x80093A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80093A84;
    // 0x80093A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80093A84:
    // 0x80093A84: blez        $v1, L_80093A94
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80093A88: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_80093A94;
    }
    // 0x80093A88: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80093A8C: b           L_80093A94
    // 0x80093A90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80093A94;
    // 0x80093A90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80093A94:
    // 0x80093A94: addu        $t3, $v0, $a0
    ctx->r11 = ADD32(ctx->r2, ctx->r4);
    // 0x80093A98: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80093A9C: beq         $at, $zero, L_80093AF8
    if (ctx->r1 == 0) {
        // 0x80093AA0: lw          $a0, 0x164($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X164));
            goto L_80093AF8;
    }
    // 0x80093AA0: lw          $a0, 0x164($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80093AA4: lw          $a1, 0x160($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80093AA8: jal         0x80091E14
    // 0x80093AAC: lh          $a2, 0xC2($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0XC2));
    inside(rdram, ctx);
        goto after_23;
    // 0x80093AAC: lh          $a2, 0xC2($sp)
    ctx->r6 = S32(MEM_H(ctx->r29, 0XC2));
    after_23:
    // 0x80093AB0: beq         $v0, $zero, L_80093AF8
    if (ctx->r2 == 0) {
        // 0x80093AB4: lh          $t7, 0xC2($sp)
        ctx->r15 = S32(MEM_H(ctx->r29, 0XC2));
            goto L_80093AF8;
    }
    // 0x80093AB4: lh          $t7, 0xC2($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x80093AB8: lw          $t4, 0x19C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80093ABC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80093AC0: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x80093AC4: lw          $t5, 0x1A0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1A0));
    // 0x80093AC8: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    // 0x80093ACC: lw          $t1, 0x1A4($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1A4));
    // 0x80093AD0: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x80093AD4: lw          $t8, 0x1A8($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80093AD8: lw          $t6, 0x164($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80093ADC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80093AE0: lw          $t2, 0x1AC($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x80093AE4: lw          $t9, 0x160($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80093AE8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80093AEC: lw          $t7, 0x1B0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x80093AF0: lw          $t3, 0x15C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X15C));
    // 0x80093AF4: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
L_80093AF8:
    // 0x80093AF8: lh          $v0, 0x8($s5)
    ctx->r2 = S32(MEM_H(ctx->r21, 0X8));
    // 0x80093AFC: lh          $t4, 0xA($s5)
    ctx->r12 = S32(MEM_H(ctx->r21, 0XA));
    // 0x80093B00: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x80093B04: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80093B08: addu        $s3, $v0, $t4
    ctx->r19 = ADD32(ctx->r2, ctx->r12);
    // 0x80093B0C: sll         $t5, $s3, 16
    ctx->r13 = S32(ctx->r19 << 16);
    // 0x80093B10: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80093B14: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80093B18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80093B1C: addiu       $t8, $t8, 0x61A8
    ctx->r24 = ADD32(ctx->r24, 0X61A8);
    // 0x80093B20: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80093B24: addu        $s2, $t6, $t8
    ctx->r18 = ADD32(ctx->r14, ctx->r24);
    // 0x80093B28: beq         $at, $zero, L_80093DEC
    if (ctx->r1 == 0) {
        // 0x80093B2C: sw          $v0, 0x16C($sp)
        MEM_W(0X16C, ctx->r29) = ctx->r2;
            goto L_80093DEC;
    }
    // 0x80093B2C: sw          $v0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r2;
L_80093B30:
    // 0x80093B30: lh          $t9, 0x8($s2)
    ctx->r25 = S32(MEM_H(ctx->r18, 0X8));
    // 0x80093B34: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80093B38: addiu       $t3, $t3, 0x61A8
    ctx->r11 = ADD32(ctx->r11, 0X61A8);
    // 0x80093B3C: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x80093B40: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80093B44: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80093B48: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80093B4C: lw          $a1, 0x184($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093B50: lw          $a2, 0x180($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093B54: lw          $s0, 0x4($v0)
    ctx->r16 = S32(MEM_W(ctx->r2, 0X4));
    // 0x80093B58: lw          $v1, 0x0($s2)
    ctx->r3 = S32(MEM_W(ctx->r18, 0X0));
    // 0x80093B5C: lw          $s1, 0x0($v0)
    ctx->r17 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80093B60: subu        $t4, $s0, $a1
    ctx->r12 = SUB32(ctx->r16, ctx->r5);
    // 0x80093B64: subu        $t7, $v1, $a2
    ctx->r15 = SUB32(ctx->r3, ctx->r6);
    // 0x80093B68: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093B6C: lw          $a0, 0x4($s2)
    ctx->r4 = S32(MEM_W(ctx->r18, 0X4));
    // 0x80093B70: subu        $t1, $s1, $a2
    ctx->r9 = SUB32(ctx->r17, ctx->r6);
    // 0x80093B74: lw          $a2, 0x188($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80093B78: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x80093B7C: sw          $a0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r4;
    // 0x80093B80: lw          $a0, 0x180($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093B84: lw          $a1, 0x184($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093B88: addiu       $t4, $sp, 0x13C
    ctx->r12 = ADD32(ctx->r29, 0X13C);
    // 0x80093B8C: lw          $t9, 0x194($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X194));
    // 0x80093B90: mflo        $t5
    ctx->r13 = lo;
    // 0x80093B94: lw          $a3, 0x190($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X190));
    // 0x80093B98: sw          $v1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r3;
    // 0x80093B9C: multu       $t1, $t6
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093BA0: addiu       $t6, $sp, 0x134
    ctx->r14 = ADD32(ctx->r29, 0X134);
    // 0x80093BA4: addiu       $t1, $sp, 0x138
    ctx->r9 = ADD32(ctx->r29, 0X138);
    // 0x80093BA8: mflo        $t8
    ctx->r24 = lo;
    // 0x80093BAC: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80093BB0: bnel        $at, $zero, L_80093DD8
    if (ctx->r1 != 0) {
        // 0x80093BB4: lw          $v0, 0x16C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
            goto L_80093DD8;
    }
    goto skip_3;
    // 0x80093BB4: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
    skip_3:
    // 0x80093BB8: lw          $t2, 0x198($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X198));
    // 0x80093BBC: lw          $t7, 0x160($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80093BC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80093BC4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80093BC8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80093BCC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80093BD0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80093BD4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80093BD8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80093BDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80093BE0: jal         0x8009542C
    // 0x80093BE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    rintersect(rdram, ctx);
        goto after_24;
    // 0x80093BE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_24:
    // 0x80093BE8: beq         $v0, $zero, L_80093DD4
    if (ctx->r2 == 0) {
        // 0x80093BEC: lw          $t5, 0x138($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X138));
            goto L_80093DD4;
    }
    // 0x80093BEC: lw          $t5, 0x138($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80093BF0: lw          $t8, 0x184($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093BF4: lw          $t9, 0x13C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80093BF8: lw          $t2, 0x180($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093BFC: subu        $v1, $t5, $t8
    ctx->r3 = SUB32(ctx->r13, ctx->r24);
    // 0x80093C00: blez        $v1, L_80093C10
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80093C04: subu        $v0, $t9, $t2
        ctx->r2 = SUB32(ctx->r25, ctx->r10);
            goto L_80093C10;
    }
    // 0x80093C04: subu        $v0, $t9, $t2
    ctx->r2 = SUB32(ctx->r25, ctx->r10);
    // 0x80093C08: b           L_80093C14
    // 0x80093C0C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_80093C14;
    // 0x80093C0C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80093C10:
    // 0x80093C10: negu        $a2, $v1
    ctx->r6 = SUB32(0, ctx->r3);
L_80093C14:
    // 0x80093C14: blez        $v0, L_80093C24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80093C18: lw          $t3, 0x1A8($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X1A8));
            goto L_80093C24;
    }
    // 0x80093C18: lw          $t3, 0x1A8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80093C1C: b           L_80093C28
    // 0x80093C20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80093C28;
    // 0x80093C20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80093C24:
    // 0x80093C24: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
L_80093C28:
    // 0x80093C28: lw          $t7, 0x0($t3)
    ctx->r15 = S32(MEM_W(ctx->r11, 0X0));
    // 0x80093C2C: lw          $t4, 0x180($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093C30: lw          $t1, 0x1AC($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x80093C34: lw          $t5, 0x184($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093C38: subu        $v0, $t7, $t4
    ctx->r2 = SUB32(ctx->r15, ctx->r12);
    // 0x80093C3C: blez        $v0, L_80093C4C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80093C40: addu        $t8, $a1, $a2
        ctx->r24 = ADD32(ctx->r5, ctx->r6);
            goto L_80093C4C;
    }
    // 0x80093C40: addu        $t8, $a1, $a2
    ctx->r24 = ADD32(ctx->r5, ctx->r6);
    // 0x80093C44: b           L_80093C50
    // 0x80093C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80093C50;
    // 0x80093C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80093C4C:
    // 0x80093C4C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_80093C50:
    // 0x80093C50: lw          $t6, 0x0($t1)
    ctx->r14 = S32(MEM_W(ctx->r9, 0X0));
    // 0x80093C54: subu        $v1, $t6, $t5
    ctx->r3 = SUB32(ctx->r14, ctx->r13);
    // 0x80093C58: blez        $v1, L_80093C68
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80093C5C: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_80093C68;
    }
    // 0x80093C5C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80093C60: b           L_80093C68
    // 0x80093C64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80093C68;
    // 0x80093C64: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80093C68:
    // 0x80093C68: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x80093C6C: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80093C70: beql        $at, $zero, L_80093DD8
    if (ctx->r1 == 0) {
        // 0x80093C74: lw          $v0, 0x16C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
            goto L_80093DD8;
    }
    goto skip_4;
    // 0x80093C74: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
    skip_4:
    // 0x80093C78: lh          $s0, 0xC($s2)
    ctx->r16 = S32(MEM_H(ctx->r18, 0XC));
    // 0x80093C7C: lw          $t3, 0x1B4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1B4));
    // 0x80093C80: lh          $t1, 0xC2($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x80093C84: bltz        $s0, L_80093CA4
    if (SIGNED(ctx->r16) < 0) {
        // 0x80093C88: lw          $t6, 0x19C($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80093CA4;
    }
    // 0x80093C88: lw          $t6, 0x19C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80093C8C: lh          $t2, 0xE($s2)
    ctx->r10 = S32(MEM_H(ctx->r18, 0XE));
    // 0x80093C90: andi        $t7, $t3, 0xFFFF
    ctx->r15 = ctx->r11 & 0XFFFF;
    // 0x80093C94: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80093C98: and         $t4, $t2, $t7
    ctx->r12 = ctx->r10 & ctx->r15;
    // 0x80093C9C: beq         $t4, $zero, L_80093CE8
    if (ctx->r12 == 0) {
        // 0x80093CA0: sra         $t8, $a0, 16
        ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
            goto L_80093CE8;
    }
    // 0x80093CA0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
L_80093CA4:
    // 0x80093CA4: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x80093CA8: lw          $t8, 0x1A0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1A0));
    // 0x80093CAC: lw          $t5, 0x16C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X16C));
    // 0x80093CB0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80093CB4: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x80093CB8: lw          $t3, 0x1A4($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1A4));
    // 0x80093CBC: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x80093CC0: lw          $t7, 0x1A8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80093CC4: lw          $t2, 0x13C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80093CC8: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80093CCC: lw          $t1, 0x1AC($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x80093CD0: lw          $t4, 0x138($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80093CD4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80093CD8: lw          $t5, 0x1B0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x80093CDC: lw          $t6, 0x134($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80093CE0: b           L_80093DD4
    // 0x80093CE4: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_80093DD4;
    // 0x80093CE4: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_80093CE8:
    // 0x80093CE8: addiu       $t9, $sp, 0xEC
    ctx->r25 = ADD32(ctx->r29, 0XEC);
    // 0x80093CEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80093CF0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80093CF4: lw          $a1, 0x13C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80093CF8: lw          $a2, 0x138($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80093CFC: jal         0x80099104
    // 0x80093D00: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    getzsofslope(rdram, ctx);
        goto after_25;
    // 0x80093D00: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    after_25:
    // 0x80093D04: lw          $v0, 0xF0($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x80093D08: lw          $t3, 0x134($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80093D0C: lw          $t2, 0xEC($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0XEC));
    // 0x80093D10: lh          $t7, 0xC2($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x80093D14: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80093D18: beq         $at, $zero, L_80093D2C
    if (ctx->r1 == 0) {
        // 0x80093D1C: lw          $t4, 0x19C($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X19C));
            goto L_80093D2C;
    }
    // 0x80093D1C: lw          $t4, 0x19C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80093D20: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80093D24: bne         $at, $zero, L_80093D70
    if (ctx->r1 != 0) {
        // 0x80093D28: lh          $a0, 0xC4($sp)
        ctx->r4 = S32(MEM_H(ctx->r29, 0XC4));
            goto L_80093D70;
    }
    // 0x80093D28: lh          $a0, 0xC4($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XC4));
L_80093D2C:
    // 0x80093D2C: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x80093D30: lw          $t6, 0x1A0($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1A0));
    // 0x80093D34: lw          $t1, 0x16C($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X16C));
    // 0x80093D38: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80093D3C: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x80093D40: lw          $t8, 0x1A4($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1A4));
    // 0x80093D44: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x80093D48: lw          $t3, 0x1A8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80093D4C: lw          $t9, 0x13C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80093D50: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80093D54: lw          $t7, 0x1AC($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x80093D58: lw          $t2, 0x138($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80093D5C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80093D60: lw          $t1, 0x1B0($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x80093D64: lw          $t4, 0x134($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80093D68: b           L_80093DD4
    // 0x80093D6C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80093DD4;
    // 0x80093D6C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80093D70:
    // 0x80093D70: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80093D74: bltz        $v0, L_80093DB0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80093D78: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80093DB0;
    }
    // 0x80093D78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80093D7C: lui         $t5, 0x8028
    ctx->r13 = S32(0X8028 << 16);
    // 0x80093D80: addiu       $t5, $t5, -0x70D0
    ctx->r13 = ADD32(ctx->r13, -0X70D0);
    // 0x80093D84: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80093D88: addu        $v0, $t6, $t5
    ctx->r2 = ADD32(ctx->r14, ctx->r13);
L_80093D8C:
    // 0x80093D8C: lh          $t8, 0x0($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X0));
    // 0x80093D90: bnel        $s0, $t8, L_80093DA4
    if (ctx->r16 != ctx->r24) {
        // 0x80093D94: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80093DA4;
    }
    goto skip_5;
    // 0x80093D94: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_5:
    // 0x80093D98: b           L_80093DB0
    // 0x80093D9C: lh          $a0, 0xC4($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XC4));
        goto L_80093DB0;
    // 0x80093D9C: lh          $a0, 0xC4($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XC4));
    // 0x80093DA0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80093DA4:
    // 0x80093DA4: bgez        $v1, L_80093D8C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80093DA8: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_80093D8C;
    }
    // 0x80093DA8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80093DAC: lh          $a0, 0xC4($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0XC4));
L_80093DB0:
    // 0x80093DB0: bgez        $v1, L_80093DD0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80093DB4: sll         $t9, $a0, 1
        ctx->r25 = S32(ctx->r4 << 1);
            goto L_80093DD0;
    }
    // 0x80093DB4: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80093DB8: lui         $at, 0x8028
    ctx->r1 = S32(0X8028 << 16);
    // 0x80093DBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80093DC0: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x80093DC4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80093DC8: sh          $s0, -0x70D0($at)
    MEM_H(-0X70D0, ctx->r1) = ctx->r16;
    // 0x80093DCC: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
L_80093DD0:
    // 0x80093DD0: sh          $a0, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r4;
L_80093DD4:
    // 0x80093DD4: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80093DD8:
    // 0x80093DD8: addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
    // 0x80093DDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80093DE0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80093DE4: bne         $at, $zero, L_80093B30
    if (ctx->r1 != 0) {
        // 0x80093DE8: sw          $v0, 0x16C($sp)
        MEM_W(0X16C, ctx->r29) = ctx->r2;
            goto L_80093B30;
    }
    // 0x80093DE8: sw          $v0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r2;
L_80093DEC:
    // 0x80093DEC: lh          $t7, 0xC2($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x80093DF0: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x80093DF4: lw          $t1, 0x1B4($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1B4));
    // 0x80093DF8: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x80093DFC: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80093E00: lh          $v0, 0x2330($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X2330));
    // 0x80093E04: srl         $t6, $t1, 16
    ctx->r14 = S32(U32(ctx->r9) >> 16);
    // 0x80093E08: bltzl       $v0, L_800949D4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80093E0C: lh          $t8, 0xC6($sp)
        ctx->r24 = S32(MEM_H(ctx->r29, 0XC6));
            goto L_800949D4;
    }
    goto skip_6;
    // 0x80093E0C: lh          $t8, 0xC6($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XC6));
    skip_6:
    // 0x80093E10: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x80093E14: sw          $v0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r2;
L_80093E18:
    // 0x80093E18: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
    // 0x80093E1C: lui         $t8, 0x8024
    ctx->r24 = S32(0X8024 << 16);
    // 0x80093E20: addiu       $t8, $t8, 0x6BA8
    ctx->r24 = ADD32(ctx->r24, 0X6BA8);
    // 0x80093E24: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80093E28: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80093E2C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80093E30: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80093E34: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80093E38: addu        $s7, $t5, $t8
    ctx->r23 = ADD32(ctx->r13, ctx->r24);
    // 0x80093E3C: lh          $s5, 0xC($s7)
    ctx->r21 = S32(MEM_H(ctx->r23, 0XC));
    // 0x80093E40: lw          $t9, 0xA4($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0XA4));
    // 0x80093E44: and         $t3, $s5, $t9
    ctx->r11 = ctx->r21 & ctx->r25;
    // 0x80093E48: beql        $t3, $zero, L_800949BC
    if (ctx->r11 == 0) {
        // 0x80093E4C: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_800949BC;
    }
    goto skip_7;
    // 0x80093E4C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    skip_7:
    // 0x80093E50: lw          $t2, 0x0($s7)
    ctx->r10 = S32(MEM_W(ctx->r23, 0X0));
    // 0x80093E54: andi        $v0, $s5, 0x30
    ctx->r2 = ctx->r21 & 0X30;
    // 0x80093E58: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80093E5C: sw          $t2, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r10;
    // 0x80093E60: lw          $t7, 0x4($s7)
    ctx->r15 = S32(MEM_W(ctx->r23, 0X4));
    // 0x80093E64: lw          $t1, 0x164($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80093E68: lw          $t6, 0x180($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80093E6C: sw          $t7, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r15;
    // 0x80093E70: lw          $t4, 0x8($s7)
    ctx->r12 = S32(MEM_W(ctx->r23, 0X8));
    // 0x80093E74: lw          $t9, 0x190($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X190));
    // 0x80093E78: beq         $v0, $zero, L_80093E98
    if (ctx->r2 == 0) {
        // 0x80093E7C: sw          $t4, 0x15C($sp)
        MEM_W(0X15C, ctx->r29) = ctx->r12;
            goto L_80093E98;
    }
    // 0x80093E7C: sw          $t4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r12;
    // 0x80093E80: beq         $v0, $at, L_80094178
    if (ctx->r2 == ctx->r1) {
        // 0x80093E84: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_80094178;
    }
    // 0x80093E84: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80093E88: beq         $v0, $at, L_800944D4
    if (ctx->r2 == ctx->r1) {
        // 0x80093E8C: lw          $t5, 0x198($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X198));
            goto L_800944D4;
    }
    // 0x80093E8C: lw          $t5, 0x198($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X198));
    // 0x80093E90: b           L_800949B8
    // 0x80093E94: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x80093E94: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80093E98:
    // 0x80093E98: subu        $s6, $t1, $t6
    ctx->r22 = SUB32(ctx->r9, ctx->r14);
    // 0x80093E9C: multu       $s6, $t9
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093EA0: lw          $t5, 0x160($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80093EA4: lw          $t8, 0x184($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80093EA8: lw          $t2, 0x194($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X194));
    // 0x80093EAC: lw          $v1, 0x190($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X190));
    // 0x80093EB0: subu        $s4, $t5, $t8
    ctx->r20 = SUB32(ctx->r13, ctx->r24);
    // 0x80093EB4: mflo        $t3
    ctx->r11 = lo;
    // 0x80093EB8: nop

    // 0x80093EBC: nop

    // 0x80093EC0: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093EC4: mflo        $t7
    ctx->r15 = lo;
    // 0x80093EC8: addu        $s3, $t3, $t7
    ctx->r19 = ADD32(ctx->r11, ctx->r15);
    // 0x80093ECC: bgtz        $s3, L_80093EDC
    if (SIGNED(ctx->r19) > 0) {
        // 0x80093ED0: nop
    
            goto L_80093EDC;
    }
    // 0x80093ED0: nop

    // 0x80093ED4: b           L_800949B8
    // 0x80093ED8: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x80093ED8: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80093EDC:
    // 0x80093EDC: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093EE0: lw          $v0, 0x194($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X194));
    // 0x80093EE4: lw          $a0, 0x198($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X198));
    // 0x80093EE8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80093EEC: mflo        $t4
    ctx->r12 = lo;
    // 0x80093EF0: nop

    // 0x80093EF4: nop

    // 0x80093EF8: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093EFC: mflo        $t1
    ctx->r9 = lo;
    // 0x80093F00: addu        $s2, $t4, $t1
    ctx->r18 = ADD32(ctx->r12, ctx->r9);
    // 0x80093F04: bne         $s2, $zero, L_80093F14
    if (ctx->r18 != 0) {
        // 0x80093F08: nop
    
            goto L_80093F14;
    }
    // 0x80093F08: nop

    // 0x80093F0C: b           L_800949B8
    // 0x80093F10: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x80093F10: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80093F14:
    // 0x80093F14: jal         0x800919B0
    // 0x80093F18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    scale(rdram, ctx);
        goto after_26;
    // 0x80093F18: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_26:
    // 0x80093F1C: lw          $t6, 0x188($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80093F20: addu        $t5, $v0, $t6
    ctx->r13 = ADD32(ctx->r2, ctx->r14);
    // 0x80093F24: sw          $t5, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r13;
    // 0x80093F28: jal         0x800B4EA8
    // 0x80093F2C: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    gettilesizy(rdram, ctx);
        goto after_27;
    // 0x80093F2C: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    after_27:
    // 0x80093F30: lbu         $t8, 0x28($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X28);
    // 0x80093F34: andi        $t2, $s5, 0x80
    ctx->r10 = ctx->r21 & 0X80;
    // 0x80093F38: lw          $t3, 0x15C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X15C));
    // 0x80093F3C: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093F40: mflo        $s1
    ctx->r17 = lo;
    // 0x80093F44: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80093F48: beq         $t2, $zero, L_80093F5C
    if (ctx->r10 == 0) {
        // 0x80093F4C: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80093F5C;
    }
    // 0x80093F4C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80093F50: sra         $t7, $t9, 1
    ctx->r15 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80093F54: addu        $t4, $t3, $t7
    ctx->r12 = ADD32(ctx->r11, ctx->r15);
    // 0x80093F58: sw          $t4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r12;
L_80093F5C:
    // 0x80093F5C: jal         0x800B4F00
    // 0x80093F60: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    getpicanm(rdram, ctx);
        goto after_28;
    // 0x80093F60: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    after_28:
    // 0x80093F64: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80093F68: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80093F6C: beql        $t1, $zero, L_80093FA8
    if (ctx->r9 == 0) {
        // 0x80093F70: lw          $t6, 0x15C($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X15C));
            goto L_80093FA8;
    }
    goto skip_8;
    // 0x80093F70: lw          $t6, 0x15C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X15C));
    skip_8:
    // 0x80093F74: jal         0x800B4F00
    // 0x80093F78: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    getpicanm(rdram, ctx);
        goto after_29;
    // 0x80093F78: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    after_29:
    // 0x80093F7C: lbu         $t2, 0x28($s7)
    ctx->r10 = MEM_BU(ctx->r23, 0X28);
    // 0x80093F80: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80093F84: sll         $t8, $t5, 24
    ctx->r24 = S32(ctx->r13 << 24);
    // 0x80093F88: sra         $t9, $t8, 24
    ctx->r25 = S32(SIGNED(ctx->r24) >> 24);
    // 0x80093F8C: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093F90: lw          $t4, 0x15C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X15C));
    // 0x80093F94: mflo        $t3
    ctx->r11 = lo;
    // 0x80093F98: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80093F9C: subu        $t1, $t4, $t7
    ctx->r9 = SUB32(ctx->r12, ctx->r15);
    // 0x80093FA0: sw          $t1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r9;
    // 0x80093FA4: lw          $t6, 0x15C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X15C));
L_80093FA8:
    // 0x80093FA8: lw          $t5, 0x134($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80093FAC: subu        $t8, $t6, $s1
    ctx->r24 = SUB32(ctx->r14, ctx->r17);
    // 0x80093FB0: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80093FB4: bne         $at, $zero, L_80093FC4
    if (ctx->r1 != 0) {
        // 0x80093FB8: slt         $at, $t5, $t8
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_80093FC4;
    }
    // 0x80093FB8: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80093FBC: beq         $at, $zero, L_80093FCC
    if (ctx->r1 == 0) {
        // 0x80093FC0: lw          $a0, 0x190($sp)
        ctx->r4 = S32(MEM_W(ctx->r29, 0X190));
            goto L_80093FCC;
    }
    // 0x80093FC0: lw          $a0, 0x190($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X190));
L_80093FC4:
    // 0x80093FC4: b           L_800949B8
    // 0x80093FC8: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x80093FC8: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80093FCC:
    // 0x80093FCC: multu       $s4, $a0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093FD0: lw          $t3, 0x194($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X194));
    // 0x80093FD4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80093FD8: mflo        $t2
    ctx->r10 = lo;
    // 0x80093FDC: nop

    // 0x80093FE0: nop

    // 0x80093FE4: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80093FE8: mflo        $t4
    ctx->r12 = lo;
    // 0x80093FEC: subu        $s0, $t2, $t4
    ctx->r16 = SUB32(ctx->r10, ctx->r12);
    // 0x80093FF0: jal         0x800919B0
    // 0x80093FF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    scale(rdram, ctx);
        goto after_30;
    // 0x80093FF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_30:
    // 0x80093FF8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80093FFC: lw          $a0, 0x194($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X194));
    // 0x80094000: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80094004: jal         0x800919B0
    // 0x80094008: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    scale(rdram, ctx);
        goto after_31;
    // 0x80094008: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_31:
    // 0x8009400C: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094010: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    // 0x80094014: mflo        $t7
    ctx->r15 = lo;
    // 0x80094018: nop

    // 0x8009401C: nop

    // 0x80094020: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094024: mflo        $t1
    ctx->r9 = lo;
    // 0x80094028: addu        $s0, $t7, $t1
    ctx->r16 = ADD32(ctx->r15, ctx->r9);
    // 0x8009402C: jal         0x800B4E50
    // 0x80094030: nop

    gettilesizx(rdram, ctx);
        goto after_32;
    // 0x80094030: nop

    after_32:
    // 0x80094034: lbu         $t6, 0x27($s7)
    ctx->r14 = MEM_BU(ctx->r23, 0X27);
    // 0x80094038: lw          $a0, 0x190($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X190));
    // 0x8009403C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80094040: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094044: mflo        $s1
    ctx->r17 = lo;
    // 0x80094048: nop

    // 0x8009404C: nop

    // 0x80094050: multu       $s1, $s1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094054: mflo        $s1
    ctx->r17 = lo;
    // 0x80094058: sra         $t5, $s1, 7
    ctx->r13 = S32(SIGNED(ctx->r17) >> 7);
    // 0x8009405C: slt         $at, $t5, $s0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80094060: beq         $at, $zero, L_80094070
    if (ctx->r1 == 0) {
        // 0x80094064: nop
    
            goto L_80094070;
    }
    // 0x80094064: nop

    // 0x80094068: b           L_800949B8
    // 0x8009406C: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x8009406C: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80094070:
    // 0x80094070: jal         0x800919B0
    // 0x80094074: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    scale(rdram, ctx);
        goto after_33;
    // 0x80094074: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_33:
    // 0x80094078: lw          $t8, 0x180($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X180));
    // 0x8009407C: lw          $a0, 0x194($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X194));
    // 0x80094080: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80094084: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80094088: sw          $t9, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r25;
    // 0x8009408C: jal         0x800919B0
    // 0x80094090: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    scale(rdram, ctx);
        goto after_34;
    // 0x80094090: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_34:
    // 0x80094094: lw          $t3, 0x184($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80094098: lw          $t7, 0x13C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x8009409C: lw          $t1, 0x180($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X180));
    // 0x800940A0: addu        $t2, $v0, $t3
    ctx->r10 = ADD32(ctx->r2, ctx->r11);
    // 0x800940A4: subu        $v1, $t2, $t3
    ctx->r3 = SUB32(ctx->r10, ctx->r11);
    // 0x800940A8: blez        $v1, L_800940B8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800940AC: sw          $t2, 0x138($sp)
        MEM_W(0X138, ctx->r29) = ctx->r10;
            goto L_800940B8;
    }
    // 0x800940AC: sw          $t2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r10;
    // 0x800940B0: b           L_800940BC
    // 0x800940B4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_800940BC;
    // 0x800940B4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800940B8:
    // 0x800940B8: negu        $a2, $v1
    ctx->r6 = SUB32(0, ctx->r3);
L_800940BC:
    // 0x800940BC: subu        $v0, $t7, $t1
    ctx->r2 = SUB32(ctx->r15, ctx->r9);
    // 0x800940C0: blez        $v0, L_800940D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800940C4: lw          $t6, 0x1A8($sp)
        ctx->r14 = S32(MEM_W(ctx->r29, 0X1A8));
            goto L_800940D0;
    }
    // 0x800940C4: lw          $t6, 0x1A8($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x800940C8: b           L_800940D4
    // 0x800940CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_800940D4;
    // 0x800940CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800940D0:
    // 0x800940D0: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
L_800940D4:
    // 0x800940D4: lw          $t5, 0x0($t6)
    ctx->r13 = S32(MEM_W(ctx->r14, 0X0));
    // 0x800940D8: lw          $t8, 0x180($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X180));
    // 0x800940DC: lw          $t9, 0x1AC($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x800940E0: lw          $t4, 0x184($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X184));
    // 0x800940E4: subu        $v0, $t5, $t8
    ctx->r2 = SUB32(ctx->r13, ctx->r24);
    // 0x800940E8: blez        $v0, L_800940F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800940EC: addu        $t7, $a1, $a2
        ctx->r15 = ADD32(ctx->r5, ctx->r6);
            goto L_800940F8;
    }
    // 0x800940EC: addu        $t7, $a1, $a2
    ctx->r15 = ADD32(ctx->r5, ctx->r6);
    // 0x800940F0: b           L_800940FC
    // 0x800940F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800940FC;
    // 0x800940F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800940F8:
    // 0x800940F8: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_800940FC:
    // 0x800940FC: lw          $t2, 0x0($t9)
    ctx->r10 = S32(MEM_W(ctx->r25, 0X0));
    // 0x80094100: lh          $t1, 0xC2($sp)
    ctx->r9 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x80094104: lw          $t6, 0x19C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80094108: subu        $v1, $t2, $t4
    ctx->r3 = SUB32(ctx->r10, ctx->r12);
    // 0x8009410C: blez        $v1, L_8009411C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80094110: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_8009411C;
    }
    // 0x80094110: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80094114: b           L_8009411C
    // 0x80094118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8009411C;
    // 0x80094118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009411C:
    // 0x8009411C: addu        $t3, $v0, $a0
    ctx->r11 = ADD32(ctx->r2, ctx->r4);
    // 0x80094120: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80094124: beql        $at, $zero, L_80094138
    if (ctx->r1 == 0) {
        // 0x80094128: sh          $t1, 0x0($t6)
        MEM_H(0X0, ctx->r14) = ctx->r9;
            goto L_80094138;
    }
    goto skip_9;
    // 0x80094128: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    skip_9:
    // 0x8009412C: b           L_800949B8
    // 0x80094130: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x80094130: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
    // 0x80094134: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
L_80094138:
    // 0x80094138: lw          $t8, 0x1A0($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X1A0));
    // 0x8009413C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80094140: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
    // 0x80094144: lw          $t2, 0x1A4($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X1A4));
    // 0x80094148: lw          $t9, 0x16C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X16C));
    // 0x8009414C: sh          $t9, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r25;
    // 0x80094150: lw          $t3, 0x1A8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80094154: lw          $t4, 0x13C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80094158: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8009415C: lw          $t1, 0x1AC($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x80094160: lw          $t7, 0x138($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80094164: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80094168: lw          $t5, 0x1B0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x8009416C: lw          $t6, 0x134($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80094170: b           L_800949B4
    // 0x80094174: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_800949B4;
    // 0x80094174: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_80094178:
    // 0x80094178: lh          $v0, 0xE($s7)
    ctx->r2 = S32(MEM_H(ctx->r23, 0XE));
    // 0x8009417C: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80094180: jal         0x800B4F00
    // 0x80094184: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    getpicanm(rdram, ctx);
        goto after_35;
    // 0x80094184: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_35:
    // 0x80094188: sra         $t9, $v0, 8
    ctx->r25 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8009418C: lb          $t3, 0x29($s7)
    ctx->r11 = S32(MEM_B(ctx->r23, 0X29));
    // 0x80094190: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x80094194: sra         $t4, $t2, 24
    ctx->r12 = S32(SIGNED(ctx->r10) >> 24);
    // 0x80094198: andi        $t7, $s5, 0x4
    ctx->r15 = ctx->r21 & 0X4;
    // 0x8009419C: blez        $t7, L_800941A8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800941A0: addu        $s2, $t4, $t3
        ctx->r18 = ADD32(ctx->r12, ctx->r11);
            goto L_800941A8;
    }
    // 0x800941A0: addu        $s2, $t4, $t3
    ctx->r18 = ADD32(ctx->r12, ctx->r11);
    // 0x800941A4: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
L_800941A8:
    // 0x800941A8: lh          $s3, 0x14($s7)
    ctx->r19 = S32(MEM_H(ctx->r23, 0X14));
    // 0x800941AC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800941B0: addiu       $v0, $v0, -0x9A0
    ctx->r2 = ADD32(ctx->r2, -0X9A0);
    // 0x800941B4: andi        $t1, $s3, 0x7FF
    ctx->r9 = ctx->r19 & 0X7FF;
    // 0x800941B8: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x800941BC: addu        $t5, $v0, $t6
    ctx->r13 = ADD32(ctx->r2, ctx->r14);
    // 0x800941C0: lbu         $s0, 0x27($s7)
    ctx->r16 = MEM_BU(ctx->r23, 0X27);
    // 0x800941C4: lh          $t8, 0x0($t5)
    ctx->r24 = S32(MEM_H(ctx->r13, 0X0));
    // 0x800941C8: addiu       $t9, $s3, 0x600
    ctx->r25 = ADD32(ctx->r19, 0X600);
    // 0x800941CC: andi        $t2, $t9, 0x7FF
    ctx->r10 = ctx->r25 & 0X7FF;
    // 0x800941D0: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800941D4: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x800941D8: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x800941DC: lh          $t7, 0x0($t3)
    ctx->r15 = S32(MEM_H(ctx->r11, 0X0));
    // 0x800941E0: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800941E4: mflo        $s4
    ctx->r20 = lo;
    // 0x800941E8: nop

    // 0x800941EC: nop

    // 0x800941F0: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800941F4: mflo        $fp
    ctx->r30 = lo;
    // 0x800941F8: jal         0x800B4E50
    // 0x800941FC: nop

    gettilesizx(rdram, ctx);
        goto after_36;
    // 0x800941FC: nop

    after_36:
    // 0x80094200: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80094204: addu        $a3, $t1, $s2
    ctx->r7 = ADD32(ctx->r9, ctx->r18);
    // 0x80094208: sra         $a0, $s4, 31
    ctx->r4 = S32(SIGNED(ctx->r20) >> 31);
    // 0x8009420C: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80094210: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80094214: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80094218: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x8009421C: sw          $s4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r20;
    // 0x80094220: jal         0x8008FD60
    // 0x80094224: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mulscale16(rdram, ctx);
        goto after_37;
    // 0x80094224: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_37:
    // 0x80094228: lw          $t5, 0x164($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X164));
    // 0x8009422C: sra         $a2, $s0, 31
    ctx->r6 = S32(SIGNED(ctx->r16) >> 31);
    // 0x80094230: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80094234: subu        $t8, $t5, $v0
    ctx->r24 = SUB32(ctx->r13, ctx->r2);
    // 0x80094238: sw          $t8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r24;
    // 0x8009423C: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80094240: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80094244: sw          $s0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r16;
    // 0x80094248: jal         0x8008FD60
    // 0x8009424C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    mulscale16(rdram, ctx);
        goto after_38;
    // 0x8009424C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_38:
    // 0x80094250: lw          $t9, 0x164($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80094254: sra         $a0, $fp, 31
    ctx->r4 = S32(SIGNED(ctx->r30) >> 31);
    // 0x80094258: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x8009425C: sw          $fp, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r30;
    // 0x80094260: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80094264: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80094268: sra         $a2, $s3, 31
    ctx->r6 = S32(SIGNED(ctx->r19) >> 31);
    // 0x8009426C: jal         0x8008FD60
    // 0x80094270: addu        $s1, $v0, $t9
    ctx->r17 = ADD32(ctx->r2, ctx->r25);
    mulscale16(rdram, ctx);
        goto after_39;
    // 0x80094270: addu        $s1, $v0, $t9
    ctx->r17 = ADD32(ctx->r2, ctx->r25);
    after_39:
    // 0x80094274: lw          $t1, 0x160($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80094278: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x8009427C: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80094280: subu        $t6, $t1, $v0
    ctx->r14 = SUB32(ctx->r9, ctx->r2);
    // 0x80094284: sw          $t6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r14;
    // 0x80094288: lw          $a2, 0x90($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X90));
    // 0x8009428C: jal         0x8008FD60
    // 0x80094290: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    mulscale16(rdram, ctx);
        goto after_40;
    // 0x80094290: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    after_40:
    // 0x80094294: lw          $t7, 0x160($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80094298: andi        $t8, $s5, 0x40
    ctx->r24 = ctx->r21 & 0X40;
    // 0x8009429C: lw          $a0, 0x180($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X180));
    // 0x800942A0: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800942A4: beq         $t8, $zero, L_800942F0
    if (ctx->r24 == 0) {
        // 0x800942A8: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_800942F0;
    }
    // 0x800942A8: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800942AC: lw          $v0, 0x184($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X184));
    // 0x800942B0: lw          $t2, 0x164($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X164));
    // 0x800942B4: subu        $t5, $s1, $a0
    ctx->r13 = SUB32(ctx->r17, ctx->r4);
    // 0x800942B8: subu        $t9, $v1, $v0
    ctx->r25 = SUB32(ctx->r3, ctx->r2);
    // 0x800942BC: subu        $t3, $t2, $a0
    ctx->r11 = SUB32(ctx->r10, ctx->r4);
    // 0x800942C0: multu       $t3, $t9
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800942C4: subu        $t1, $t7, $v0
    ctx->r9 = SUB32(ctx->r15, ctx->r2);
    // 0x800942C8: mflo        $t4
    ctx->r12 = lo;
    // 0x800942CC: nop

    // 0x800942D0: nop

    // 0x800942D4: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800942D8: mflo        $t6
    ctx->r14 = lo;
    // 0x800942DC: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800942E0: beql        $at, $zero, L_800942F4
    if (ctx->r1 == 0) {
        // 0x800942E4: lw          $t8, 0x194($sp)
        ctx->r24 = S32(MEM_W(ctx->r29, 0X194));
            goto L_800942F4;
    }
    goto skip_10;
    // 0x800942E4: lw          $t8, 0x194($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X194));
    skip_10:
    // 0x800942E8: b           L_800949B8
    // 0x800942EC: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x800942EC: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_800942F0:
    // 0x800942F0: lw          $t8, 0x194($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X194));
L_800942F4:
    // 0x800942F4: lw          $t2, 0x198($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X198));
    // 0x800942F8: lw          $t3, 0x164($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X164));
    // 0x800942FC: lw          $t9, 0x160($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80094300: addiu       $t7, $sp, 0x13C
    ctx->r15 = ADD32(ctx->r29, 0X13C);
    // 0x80094304: addiu       $t5, $sp, 0x138
    ctx->r13 = ADD32(ctx->r29, 0X138);
    // 0x80094308: addiu       $t1, $sp, 0x134
    ctx->r9 = ADD32(ctx->r29, 0X134);
    // 0x8009430C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80094310: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80094314: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80094318: lw          $a0, 0x180($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X180));
    // 0x8009431C: lw          $a1, 0x184($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80094320: lw          $a2, 0x188($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80094324: lw          $a3, 0x190($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X190));
    // 0x80094328: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8009432C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80094330: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80094334: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80094338: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8009433C: jal         0x8009542C
    // 0x80094340: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    rintersect(rdram, ctx);
        goto after_41;
    // 0x80094340: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_41:
    // 0x80094344: bne         $v0, $zero, L_80094354
    if (ctx->r2 != 0) {
        // 0x80094348: lw          $t4, 0x138($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X138));
            goto L_80094354;
    }
    // 0x80094348: lw          $t4, 0x138($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X138));
    // 0x8009434C: b           L_800949B8
    // 0x80094350: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x80094350: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80094354:
    // 0x80094354: lw          $t6, 0x184($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80094358: lw          $t8, 0x13C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x8009435C: lw          $t2, 0x180($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80094360: subu        $v1, $t4, $t6
    ctx->r3 = SUB32(ctx->r12, ctx->r14);
    // 0x80094364: blez        $v1, L_80094374
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80094368: subu        $v0, $t8, $t2
        ctx->r2 = SUB32(ctx->r24, ctx->r10);
            goto L_80094374;
    }
    // 0x80094368: subu        $v0, $t8, $t2
    ctx->r2 = SUB32(ctx->r24, ctx->r10);
    // 0x8009436C: b           L_80094378
    // 0x80094370: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_80094378;
    // 0x80094370: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80094374:
    // 0x80094374: negu        $a2, $v1
    ctx->r6 = SUB32(0, ctx->r3);
L_80094378:
    // 0x80094378: blez        $v0, L_80094388
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009437C: lw          $t3, 0x1A8($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X1A8));
            goto L_80094388;
    }
    // 0x8009437C: lw          $t3, 0x1A8($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80094380: b           L_8009438C
    // 0x80094384: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009438C;
    // 0x80094384: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80094388:
    // 0x80094388: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
L_8009438C:
    // 0x8009438C: lw          $t9, 0x0($t3)
    ctx->r25 = S32(MEM_W(ctx->r11, 0X0));
    // 0x80094390: lw          $t7, 0x180($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80094394: lw          $t5, 0x1AC($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x80094398: lw          $t4, 0x184($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X184));
    // 0x8009439C: subu        $v0, $t9, $t7
    ctx->r2 = SUB32(ctx->r25, ctx->r15);
    // 0x800943A0: blez        $v0, L_800943B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800943A4: addu        $t8, $a1, $a2
        ctx->r24 = ADD32(ctx->r5, ctx->r6);
            goto L_800943B0;
    }
    // 0x800943A4: addu        $t8, $a1, $a2
    ctx->r24 = ADD32(ctx->r5, ctx->r6);
    // 0x800943A8: b           L_800943B4
    // 0x800943AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800943B4;
    // 0x800943AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800943B0:
    // 0x800943B0: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_800943B4:
    // 0x800943B4: lw          $t1, 0x0($t5)
    ctx->r9 = S32(MEM_W(ctx->r13, 0X0));
    // 0x800943B8: subu        $v1, $t1, $t4
    ctx->r3 = SUB32(ctx->r9, ctx->r12);
    // 0x800943BC: blez        $v1, L_800943CC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800943C0: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_800943CC;
    }
    // 0x800943C0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x800943C4: b           L_800943CC
    // 0x800943C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800943CC;
    // 0x800943C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800943CC:
    // 0x800943CC: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x800943D0: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800943D4: beq         $at, $zero, L_800943E4
    if (ctx->r1 == 0) {
        // 0x800943D8: nop
    
            goto L_800943E4;
    }
    // 0x800943D8: nop

    // 0x800943DC: b           L_800949B8
    // 0x800943E0: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x800943E0: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_800943E4:
    // 0x800943E4: jal         0x800B4EA8
    // 0x800943E8: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    gettilesizy(rdram, ctx);
        goto after_42;
    // 0x800943E8: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    after_42:
    // 0x800943EC: lbu         $t2, 0x28($s7)
    ctx->r10 = MEM_BU(ctx->r23, 0X28);
    // 0x800943F0: andi        $t9, $s5, 0x80
    ctx->r25 = ctx->r21 & 0X80;
    // 0x800943F4: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800943F8: mflo        $s3
    ctx->r19 = lo;
    // 0x800943FC: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x80094400: beq         $t9, $zero, L_8009441C
    if (ctx->r25 == 0) {
        // 0x80094404: or          $s3, $t3, $zero
        ctx->r19 = ctx->r11 | 0;
            goto L_8009441C;
    }
    // 0x80094404: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x80094408: lw          $t7, 0x8($s7)
    ctx->r15 = S32(MEM_W(ctx->r23, 0X8));
    // 0x8009440C: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80094410: addu        $t1, $t7, $t5
    ctx->r9 = ADD32(ctx->r15, ctx->r13);
    // 0x80094414: b           L_80094424
    // 0x80094418: sw          $t1, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r9;
        goto L_80094424;
    // 0x80094418: sw          $t1, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r9;
L_8009441C:
    // 0x8009441C: lw          $t4, 0x8($s7)
    ctx->r12 = S32(MEM_W(ctx->r23, 0X8));
    // 0x80094420: sw          $t4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r12;
L_80094424:
    // 0x80094424: jal         0x800B4F00
    // 0x80094428: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    getpicanm(rdram, ctx);
        goto after_43;
    // 0x80094428: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    after_43:
    // 0x8009442C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80094430: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80094434: beql        $t6, $zero, L_80094470
    if (ctx->r14 == 0) {
        // 0x80094438: lw          $v0, 0xF0($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0XF0));
            goto L_80094470;
    }
    goto skip_11;
    // 0x80094438: lw          $v0, 0xF0($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XF0));
    skip_11:
    // 0x8009443C: jal         0x800B4F00
    // 0x80094440: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    getpicanm(rdram, ctx);
        goto after_44;
    // 0x80094440: lhu         $a0, 0xE($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0XE);
    after_44:
    // 0x80094444: lbu         $t7, 0x28($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X28);
    // 0x80094448: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8009444C: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x80094450: sra         $t9, $t3, 24
    ctx->r25 = S32(SIGNED(ctx->r11) >> 24);
    // 0x80094454: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094458: lw          $t4, 0xF0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0XF0));
    // 0x8009445C: mflo        $t5
    ctx->r13 = lo;
    // 0x80094460: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x80094464: subu        $t6, $t4, $t1
    ctx->r14 = SUB32(ctx->r12, ctx->r9);
    // 0x80094468: sw          $t6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r14;
    // 0x8009446C: lw          $v0, 0xF0($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0XF0));
L_80094470:
    // 0x80094470: lw          $t8, 0x134($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80094474: subu        $t2, $v0, $s3
    ctx->r10 = SUB32(ctx->r2, ctx->r19);
    // 0x80094478: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8009447C: beq         $at, $zero, L_800949B4
    if (ctx->r1 == 0) {
        // 0x80094480: slt         $at, $t2, $t8
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_800949B4;
    }
    // 0x80094480: slt         $at, $t2, $t8
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80094484: beq         $at, $zero, L_800949B4
    if (ctx->r1 == 0) {
        // 0x80094488: lh          $t3, 0xC2($sp)
        ctx->r11 = S32(MEM_H(ctx->r29, 0XC2));
            goto L_800949B4;
    }
    // 0x80094488: lh          $t3, 0xC2($sp)
    ctx->r11 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x8009448C: lw          $t9, 0x19C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80094490: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80094494: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x80094498: lw          $t5, 0x1A0($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1A0));
    // 0x8009449C: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800944A0: lw          $t1, 0x1A4($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1A4));
    // 0x800944A4: lw          $t4, 0x16C($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X16C));
    // 0x800944A8: sh          $t4, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r12;
    // 0x800944AC: lw          $t2, 0x1A8($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x800944B0: lw          $t6, 0x13C($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x800944B4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800944B8: lw          $t3, 0x1AC($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x800944BC: lw          $t8, 0x138($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800944C0: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800944C4: lw          $t7, 0x1B0($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x800944C8: lw          $t9, 0x134($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X134));
    // 0x800944CC: b           L_800949B4
    // 0x800944D0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
        goto L_800949B4;
    // 0x800944D0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
L_800944D4:
    // 0x800944D4: bne         $t5, $zero, L_800944E4
    if (ctx->r13 != 0) {
        // 0x800944D8: lw          $v0, 0x15C($sp)
        ctx->r2 = S32(MEM_W(ctx->r29, 0X15C));
            goto L_800944E4;
    }
    // 0x800944D8: lw          $v0, 0x15C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X15C));
    // 0x800944DC: b           L_800949B8
    // 0x800944E0: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x800944E0: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_800944E4:
    // 0x800944E4: lw          $t4, 0x188($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X188));
    // 0x800944E8: lw          $t1, 0x198($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X198));
    // 0x800944EC: sw          $v0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r2;
    // 0x800944F0: subu        $s0, $v0, $t4
    ctx->r16 = SUB32(ctx->r2, ctx->r12);
    // 0x800944F4: xor         $t6, $s0, $t1
    ctx->r14 = ctx->r16 ^ ctx->r9;
    // 0x800944F8: bgez        $t6, L_80094508
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800944FC: andi        $t2, $s5, 0x40
        ctx->r10 = ctx->r21 & 0X40;
            goto L_80094508;
    }
    // 0x800944FC: andi        $t2, $s5, 0x40
    ctx->r10 = ctx->r21 & 0X40;
    // 0x80094500: b           L_800949B8
    // 0x80094504: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x80094504: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80094508:
    // 0x80094508: beq         $t2, $zero, L_80094530
    if (ctx->r10 == 0) {
        // 0x8009450C: lw          $t9, 0x15C($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0X15C));
            goto L_80094530;
    }
    // 0x8009450C: lw          $t9, 0x15C($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X15C));
    // 0x80094510: lw          $t7, 0x188($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X188));
    // 0x80094514: andi        $t8, $s5, 0x8
    ctx->r24 = ctx->r21 & 0X8;
    // 0x80094518: sltiu       $t3, $t8, 0x1
    ctx->r11 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8009451C: slt         $t5, $t9, $t7
    ctx->r13 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80094520: bnel        $t3, $t5, L_80094534
    if (ctx->r11 != ctx->r13) {
        // 0x80094524: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80094534;
    }
    goto skip_12;
    // 0x80094524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_12:
    // 0x80094528: b           L_800949B8
    // 0x8009452C: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x8009452C: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_80094530:
    // 0x80094530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80094534:
    // 0x80094534: lw          $a1, 0x190($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X190));
    // 0x80094538: jal         0x800919B0
    // 0x8009453C: lw          $a2, 0x198($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X198));
    scale(rdram, ctx);
        goto after_45;
    // 0x8009453C: lw          $a2, 0x198($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X198));
    after_45:
    // 0x80094540: lw          $t4, 0x180($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80094544: lw          $t6, 0x134($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X134));
    // 0x80094548: lw          $t2, 0x188($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X188));
    // 0x8009454C: addu        $t1, $v0, $t4
    ctx->r9 = ADD32(ctx->r2, ctx->r12);
    // 0x80094550: sw          $t1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r9;
    // 0x80094554: lw          $a1, 0x194($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X194));
    // 0x80094558: lw          $a2, 0x198($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X198));
    // 0x8009455C: jal         0x800919B0
    // 0x80094560: subu        $a0, $t6, $t2
    ctx->r4 = SUB32(ctx->r14, ctx->r10);
    scale(rdram, ctx);
        goto after_46;
    // 0x80094560: subu        $a0, $t6, $t2
    ctx->r4 = SUB32(ctx->r14, ctx->r10);
    after_46:
    // 0x80094564: lw          $a0, 0x184($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X184));
    // 0x80094568: lw          $t7, 0x13C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x8009456C: lw          $t3, 0x180($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X180));
    // 0x80094570: addu        $t8, $v0, $a0
    ctx->r24 = ADD32(ctx->r2, ctx->r4);
    // 0x80094574: subu        $v1, $t8, $a0
    ctx->r3 = SUB32(ctx->r24, ctx->r4);
    // 0x80094578: blez        $v1, L_80094588
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009457C: sw          $t8, 0x138($sp)
        MEM_W(0X138, ctx->r29) = ctx->r24;
            goto L_80094588;
    }
    // 0x8009457C: sw          $t8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r24;
    // 0x80094580: b           L_8009458C
    // 0x80094584: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_8009458C;
    // 0x80094584: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_80094588:
    // 0x80094588: negu        $a2, $v1
    ctx->r6 = SUB32(0, ctx->r3);
L_8009458C:
    // 0x8009458C: subu        $v0, $t7, $t3
    ctx->r2 = SUB32(ctx->r15, ctx->r11);
    // 0x80094590: blez        $v0, L_800945A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80094594: lw          $t5, 0x1A8($sp)
        ctx->r13 = S32(MEM_W(ctx->r29, 0X1A8));
            goto L_800945A0;
    }
    // 0x80094594: lw          $t5, 0x1A8($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80094598: b           L_800945A4
    // 0x8009459C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_800945A4;
    // 0x8009459C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800945A0:
    // 0x800945A0: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
L_800945A4:
    // 0x800945A4: lw          $t4, 0x0($t5)
    ctx->r12 = S32(MEM_W(ctx->r13, 0X0));
    // 0x800945A8: lw          $t1, 0x180($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X180));
    // 0x800945AC: lw          $t6, 0x1AC($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x800945B0: lw          $t8, 0x184($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X184));
    // 0x800945B4: subu        $v0, $t4, $t1
    ctx->r2 = SUB32(ctx->r12, ctx->r9);
    // 0x800945B8: blez        $v0, L_800945C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800945BC: addu        $t7, $a1, $a2
        ctx->r15 = ADD32(ctx->r5, ctx->r6);
            goto L_800945C8;
    }
    // 0x800945BC: addu        $t7, $a1, $a2
    ctx->r15 = ADD32(ctx->r5, ctx->r6);
    // 0x800945C0: b           L_800945CC
    // 0x800945C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800945CC;
    // 0x800945C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800945C8:
    // 0x800945C8: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_800945CC:
    // 0x800945CC: lw          $t2, 0x0($t6)
    ctx->r10 = S32(MEM_W(ctx->r14, 0X0));
    // 0x800945D0: subu        $v1, $t2, $t8
    ctx->r3 = SUB32(ctx->r10, ctx->r24);
    // 0x800945D4: blez        $v1, L_800945E4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800945D8: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_800945E4;
    }
    // 0x800945D8: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x800945DC: b           L_800945E4
    // 0x800945E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800945E4;
    // 0x800945E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800945E4:
    // 0x800945E4: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x800945E8: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800945EC: beql        $at, $zero, L_80094600
    if (ctx->r1 == 0) {
        // 0x800945F0: lh          $v0, 0xE($s7)
        ctx->r2 = S32(MEM_H(ctx->r23, 0XE));
            goto L_80094600;
    }
    goto skip_13;
    // 0x800945F0: lh          $v0, 0xE($s7)
    ctx->r2 = S32(MEM_H(ctx->r23, 0XE));
    skip_13:
    // 0x800945F4: b           L_800949B8
    // 0x800945F8: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
        goto L_800949B8;
    // 0x800945F8: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
    // 0x800945FC: lh          $v0, 0xE($s7)
    ctx->r2 = S32(MEM_H(ctx->r23, 0XE));
L_80094600:
    // 0x80094600: andi        $s0, $s5, 0x8
    ctx->r16 = ctx->r21 & 0X8;
    // 0x80094604: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80094608: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x8009460C: jal         0x800B4F00
    // 0x80094610: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    getpicanm(rdram, ctx);
        goto after_47;
    // 0x80094610: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_47:
    // 0x80094614: sra         $t5, $v0, 8
    ctx->r13 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80094618: lb          $t6, 0x29($s7)
    ctx->r14 = S32(MEM_B(ctx->r23, 0X29));
    // 0x8009461C: sll         $t4, $t5, 24
    ctx->r12 = S32(ctx->r13 << 24);
    // 0x80094620: sra         $t1, $t4, 24
    ctx->r9 = S32(SIGNED(ctx->r12) >> 24);
    // 0x80094624: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80094628: jal         0x800B4F00
    // 0x8009462C: addu        $s2, $t1, $t6
    ctx->r18 = ADD32(ctx->r9, ctx->r14);
    getpicanm(rdram, ctx);
        goto after_48;
    // 0x8009462C: addu        $s2, $t1, $t6
    ctx->r18 = ADD32(ctx->r9, ctx->r14);
    after_48:
    // 0x80094630: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80094634: lb          $t3, 0x2A($s7)
    ctx->r11 = S32(MEM_B(ctx->r23, 0X2A));
    // 0x80094638: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8009463C: sra         $t7, $t9, 24
    ctx->r15 = S32(SIGNED(ctx->r25) >> 24);
    // 0x80094640: andi        $t5, $s5, 0x4
    ctx->r13 = ctx->r21 & 0X4;
    // 0x80094644: blez        $t5, L_80094650
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80094648: addu        $fp, $t7, $t3
        ctx->r30 = ADD32(ctx->r15, ctx->r11);
            goto L_80094650;
    }
    // 0x80094648: addu        $fp, $t7, $t3
    ctx->r30 = ADD32(ctx->r15, ctx->r11);
    // 0x8009464C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
L_80094650:
    // 0x80094650: blez        $s0, L_8009465C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80094654: lui         $v1, 0x8010
        ctx->r3 = S32(0X8010 << 16);
            goto L_8009465C;
    }
    // 0x80094654: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80094658: negu        $fp, $fp
    ctx->r30 = SUB32(0, ctx->r30);
L_8009465C:
    // 0x8009465C: lh          $v0, 0x14($s7)
    ctx->r2 = S32(MEM_H(ctx->r23, 0X14));
    // 0x80094660: addiu       $v1, $v1, -0x9A0
    ctx->r3 = ADD32(ctx->r3, -0X9A0);
    // 0x80094664: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80094668: addiu       $t4, $v0, 0x200
    ctx->r12 = ADD32(ctx->r2, 0X200);
    // 0x8009466C: andi        $t1, $t4, 0x7FF
    ctx->r9 = ctx->r12 & 0X7FF;
    // 0x80094670: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80094674: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80094678: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x8009467C: lh          $t7, 0x0($t9)
    ctx->r15 = S32(MEM_H(ctx->r25, 0X0));
    // 0x80094680: addu        $t2, $v1, $t6
    ctx->r10 = ADD32(ctx->r3, ctx->r14);
    // 0x80094684: lh          $s0, 0x0($t2)
    ctx->r16 = S32(MEM_H(ctx->r10, 0X0));
    // 0x80094688: jal         0x800B4E50
    // 0x8009468C: sw          $t7, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r15;
    gettilesizx(rdram, ctx);
        goto after_49;
    // 0x8009468C: sw          $t7, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r15;
    after_49:
    // 0x80094690: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80094694: lbu         $s5, 0x27($s7)
    ctx->r21 = MEM_BU(ctx->r23, 0X27);
    // 0x80094698: jal         0x800B4EA8
    // 0x8009469C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    gettilesizy(rdram, ctx);
        goto after_50;
    // 0x8009469C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_50:
    // 0x800946A0: sw          $v0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r2;
    // 0x800946A4: lbu         $s6, 0x28($s7)
    ctx->r22 = MEM_BU(ctx->r23, 0X28);
    // 0x800946A8: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800946AC: addu        $t5, $t3, $fp
    ctx->r13 = ADD32(ctx->r11, ctx->r30);
    // 0x800946B0: multu       $t5, $s6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800946B4: sra         $t1, $s4, 1
    ctx->r9 = S32(SIGNED(ctx->r20) >> 1);
    // 0x800946B8: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x800946BC: lw          $a1, 0xE0($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0XE0));
    // 0x800946C0: sra         $t6, $s0, 31
    ctx->r14 = S32(SIGNED(ctx->r16) >> 31);
    // 0x800946C4: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x800946C8: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    // 0x800946CC: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800946D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800946D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800946D8: mflo        $v1
    ctx->r3 = lo;
    // 0x800946DC: sra         $t8, $v1, 31
    ctx->r24 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800946E0: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    // 0x800946E4: multu       $t2, $s5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800946E8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800946EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800946F0: sw          $s0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r16;
    // 0x800946F4: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x800946F8: mflo        $a3
    ctx->r7 = lo;
    // 0x800946FC: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80094700: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80094704: jal         0x80090874
    // 0x80094708: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    dmulscale16(rdram, ctx);
        goto after_51;
    // 0x80094708: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    after_51:
    // 0x8009470C: lw          $t1, 0x164($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80094710: lw          $t5, 0x13C($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80094714: lw          $fp, 0xF4($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0XF4));
    // 0x80094718: lw          $t8, 0x90($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X90));
    // 0x8009471C: lw          $t9, 0x94($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X94));
    // 0x80094720: negu        $t7, $s0
    ctx->r15 = SUB32(0, ctx->r16);
    // 0x80094724: addu        $t4, $t1, $v0
    ctx->r12 = ADD32(ctx->r9, ctx->r2);
    // 0x80094728: sra         $t2, $t7, 31
    ctx->r10 = S32(SIGNED(ctx->r15) >> 31);
    // 0x8009472C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80094730: sw          $t6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r14;
    // 0x80094734: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80094738: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009473C: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80094740: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80094744: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x80094748: sra         $a2, $fp, 31
    ctx->r6 = S32(SIGNED(ctx->r30) >> 31);
    // 0x8009474C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80094750: jal         0x80090874
    // 0x80094754: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    dmulscale16(rdram, ctx);
        goto after_52;
    // 0x80094754: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_52:
    // 0x80094758: multu       $s4, $s5
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009475C: lw          $t1, 0x160($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X160));
    // 0x80094760: lw          $t5, 0x138($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X138));
    // 0x80094764: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x80094768: addu        $t4, $t1, $v0
    ctx->r12 = ADD32(ctx->r9, ctx->r2);
    // 0x8009476C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80094770: sw          $t6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r14;
    // 0x80094774: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x80094778: mflo        $a3
    ctx->r7 = lo;
    // 0x8009477C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x80094780: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80094784: jal         0x8008FD60
    // 0x80094788: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    mulscale16(rdram, ctx);
        goto after_53;
    // 0x80094788: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    after_53:
    // 0x8009478C: lw          $t8, 0x164($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80094790: lw          $a0, 0x88($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X88));
    // 0x80094794: lw          $a1, 0x8C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x80094798: lw          $a2, 0x90($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X90));
    // 0x8009479C: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800947A0: jal         0x8008FD60
    // 0x800947A4: subu        $s1, $t8, $v0
    ctx->r17 = SUB32(ctx->r24, ctx->r2);
    mulscale16(rdram, ctx);
        goto after_54;
    // 0x800947A4: subu        $s1, $t8, $v0
    ctx->r17 = SUB32(ctx->r24, ctx->r2);
    after_54:
    // 0x800947A8: lw          $t1, 0xD8($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0XD8));
    // 0x800947AC: lw          $t9, 0x160($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X160));
    // 0x800947B0: lw          $a0, 0x88($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X88));
    // 0x800947B4: multu       $t1, $s6
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800947B8: lw          $a1, 0x8C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X8C));
    // 0x800947BC: addu        $s0, $v0, $t9
    ctx->r16 = ADD32(ctx->r2, ctx->r25);
    // 0x800947C0: mflo        $a3
    ctx->r7 = lo;
    // 0x800947C4: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    // 0x800947C8: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x800947CC: jal         0x8008FD60
    // 0x800947D0: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    mulscale16(rdram, ctx);
        goto after_55;
    // 0x800947D0: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    after_55:
    // 0x800947D4: lw          $t5, 0x164($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X164));
    // 0x800947D8: negu        $t0, $v0
    ctx->r8 = SUB32(0, ctx->r2);
    // 0x800947DC: addu        $s2, $s1, $t0
    ctx->r18 = ADD32(ctx->r17, ctx->r8);
    // 0x800947E0: lw          $a0, 0x98($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X98));
    // 0x800947E4: lw          $a1, 0x9C($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X9C));
    // 0x800947E8: lw          $a2, 0x90($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X90));
    // 0x800947EC: lw          $a3, 0x94($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X94));
    // 0x800947F0: jal         0x8008FD60
    // 0x800947F4: addu        $s4, $t5, $t0
    ctx->r20 = ADD32(ctx->r13, ctx->r8);
    mulscale16(rdram, ctx);
        goto after_56;
    // 0x800947F4: addu        $s4, $t5, $t0
    ctx->r20 = ADD32(ctx->r13, ctx->r8);
    after_56:
    // 0x800947F8: lw          $t2, 0x160($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X160));
    // 0x800947FC: negu        $t0, $v0
    ctx->r8 = SUB32(0, ctx->r2);
    // 0x80094800: lw          $t8, 0x164($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80094804: xor         $t3, $t2, $s0
    ctx->r11 = ctx->r10 ^ ctx->r16;
    // 0x80094808: bgez        $t3, L_80094858
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8009480C: addu        $v1, $s0, $t0
        ctx->r3 = ADD32(ctx->r16, ctx->r8);
            goto L_80094858;
    }
    // 0x8009480C: addu        $v1, $s0, $t0
    ctx->r3 = ADD32(ctx->r16, ctx->r8);
    // 0x80094810: xor         $t9, $t8, $s1
    ctx->r25 = ctx->r24 ^ ctx->r17;
    // 0x80094814: bgez        $t9, L_8009484C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80094818: lw          $t3, 0x164($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X164));
            goto L_8009484C;
    }
    // 0x80094818: lw          $t3, 0x164($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X164));
    // 0x8009481C: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094820: slt         $t7, $t2, $s0
    ctx->r15 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80094824: mflo        $t1
    ctx->r9 = lo;
    // 0x80094828: nop

    // 0x8009482C: nop

    // 0x80094830: multu       $s1, $t2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094834: mflo        $t4
    ctx->r12 = lo;
    // 0x80094838: slt         $t6, $t1, $t4
    ctx->r14 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8009483C: xor         $s3, $t6, $t7
    ctx->r19 = ctx->r14 ^ ctx->r15;
    // 0x80094840: andi        $t5, $s3, 0xFF
    ctx->r13 = ctx->r19 & 0XFF;
    // 0x80094844: b           L_80094858
    // 0x80094848: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
        goto L_80094858;
    // 0x80094848: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
L_8009484C:
    // 0x8009484C: bltzl       $t3, L_8009485C
    if (SIGNED(ctx->r11) < 0) {
        // 0x80094850: xor         $t9, $s0, $v1
        ctx->r25 = ctx->r16 ^ ctx->r3;
            goto L_8009485C;
    }
    goto skip_14;
    // 0x80094850: xor         $t9, $s0, $v1
    ctx->r25 = ctx->r16 ^ ctx->r3;
    skip_14:
    // 0x80094854: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80094858:
    // 0x80094858: xor         $t9, $s0, $v1
    ctx->r25 = ctx->r16 ^ ctx->r3;
L_8009485C:
    // 0x8009485C: bgez        $t9, L_800948AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80094860: xor         $t8, $s1, $s2
        ctx->r24 = ctx->r17 ^ ctx->r18;
            goto L_800948AC;
    }
    // 0x80094860: xor         $t8, $s1, $s2
    ctx->r24 = ctx->r17 ^ ctx->r18;
    // 0x80094864: bgez        $t8, L_800948A0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80094868: nop
    
            goto L_800948A0;
    }
    // 0x80094868: nop

    // 0x8009486C: multu       $s1, $v1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094870: slt         $t6, $s0, $v1
    ctx->r14 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80094874: mflo        $t1
    ctx->r9 = lo;
    // 0x80094878: nop

    // 0x8009487C: nop

    // 0x80094880: multu       $s2, $s0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094884: mflo        $t4
    ctx->r12 = lo;
    // 0x80094888: slt         $t2, $t1, $t4
    ctx->r10 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8009488C: xor         $t7, $t2, $t6
    ctx->r15 = ctx->r10 ^ ctx->r14;
    // 0x80094890: xor         $s3, $s3, $t7
    ctx->r19 = ctx->r19 ^ ctx->r15;
    // 0x80094894: andi        $t5, $s3, 0xFF
    ctx->r13 = ctx->r19 & 0XFF;
    // 0x80094898: b           L_800948AC
    // 0x8009489C: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
        goto L_800948AC;
    // 0x8009489C: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
L_800948A0:
    // 0x800948A0: bltz        $s1, L_800948AC
    if (SIGNED(ctx->r17) < 0) {
        // 0x800948A4: xori        $t3, $s3, 0x1
        ctx->r11 = ctx->r19 ^ 0X1;
            goto L_800948AC;
    }
    // 0x800948A4: xori        $t3, $s3, 0x1
    ctx->r11 = ctx->r19 ^ 0X1;
    // 0x800948A8: andi        $s3, $t3, 0xFF
    ctx->r19 = ctx->r11 & 0XFF;
L_800948AC:
    // 0x800948AC: lw          $t8, 0x160($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X160));
    // 0x800948B0: xor         $t4, $s2, $s4
    ctx->r12 = ctx->r18 ^ ctx->r20;
    // 0x800948B4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x800948B8: xor         $t1, $v1, $v0
    ctx->r9 = ctx->r3 ^ ctx->r2;
    // 0x800948BC: bgezl       $t1, L_80094910
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800948C0: lw          $t4, 0x160($sp)
        ctx->r12 = S32(MEM_W(ctx->r29, 0X160));
            goto L_80094910;
    }
    goto skip_15;
    // 0x800948C0: lw          $t4, 0x160($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X160));
    skip_15:
    // 0x800948C4: bgez        $t4, L_80094900
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800948C8: nop
    
            goto L_80094900;
    }
    // 0x800948C8: nop

    // 0x800948CC: multu       $s2, $v0
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800948D0: slt         $t5, $v1, $v0
    ctx->r13 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800948D4: mflo        $t2
    ctx->r10 = lo;
    // 0x800948D8: nop

    // 0x800948DC: nop

    // 0x800948E0: multu       $s4, $v1
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800948E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800948E8: slt         $t7, $t2, $t6
    ctx->r15 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800948EC: xor         $t3, $t7, $t5
    ctx->r11 = ctx->r15 ^ ctx->r13;
    // 0x800948F0: xor         $s3, $s3, $t3
    ctx->r19 = ctx->r19 ^ ctx->r11;
    // 0x800948F4: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x800948F8: b           L_8009490C
    // 0x800948FC: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
        goto L_8009490C;
    // 0x800948FC: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
L_80094900:
    // 0x80094900: bltz        $s2, L_8009490C
    if (SIGNED(ctx->r18) < 0) {
        // 0x80094904: xori        $t8, $s3, 0x1
        ctx->r24 = ctx->r19 ^ 0X1;
            goto L_8009490C;
    }
    // 0x80094904: xori        $t8, $s3, 0x1
    ctx->r24 = ctx->r19 ^ 0X1;
    // 0x80094908: andi        $s3, $t8, 0xFF
    ctx->r19 = ctx->r24 & 0XFF;
L_8009490C:
    // 0x8009490C: lw          $t4, 0x160($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X160));
L_80094910:
    // 0x80094910: lw          $t6, 0x164($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X164));
    // 0x80094914: xor         $t2, $v0, $t4
    ctx->r10 = ctx->r2 ^ ctx->r12;
    // 0x80094918: bgez        $t2, L_80094968
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009491C: xor         $t7, $s4, $t6
        ctx->r15 = ctx->r20 ^ ctx->r14;
            goto L_80094968;
    }
    // 0x8009491C: xor         $t7, $s4, $t6
    ctx->r15 = ctx->r20 ^ ctx->r14;
    // 0x80094920: bgez        $t7, L_8009495C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80094924: nop
    
            goto L_8009495C;
    }
    // 0x80094924: nop

    // 0x80094928: multu       $s4, $t4
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009492C: slt         $t8, $v0, $t4
    ctx->r24 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80094930: mflo        $t5
    ctx->r13 = lo;
    // 0x80094934: nop

    // 0x80094938: nop

    // 0x8009493C: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80094940: mflo        $t3
    ctx->r11 = lo;
    // 0x80094944: slt         $t9, $t5, $t3
    ctx->r25 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80094948: xor         $t1, $t9, $t8
    ctx->r9 = ctx->r25 ^ ctx->r24;
    // 0x8009494C: xor         $s3, $s3, $t1
    ctx->r19 = ctx->r19 ^ ctx->r9;
    // 0x80094950: andi        $t2, $s3, 0xFF
    ctx->r10 = ctx->r19 & 0XFF;
    // 0x80094954: b           L_80094968
    // 0x80094958: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
        goto L_80094968;
    // 0x80094958: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
L_8009495C:
    // 0x8009495C: bltz        $s4, L_80094968
    if (SIGNED(ctx->r20) < 0) {
        // 0x80094960: xori        $t7, $s3, 0x1
        ctx->r15 = ctx->r19 ^ 0X1;
            goto L_80094968;
    }
    // 0x80094960: xori        $t7, $s3, 0x1
    ctx->r15 = ctx->r19 ^ 0X1;
    // 0x80094964: andi        $s3, $t7, 0xFF
    ctx->r19 = ctx->r15 & 0XFF;
L_80094968:
    // 0x80094968: beq         $s3, $zero, L_800949B4
    if (ctx->r19 == 0) {
        // 0x8009496C: lh          $t5, 0xC2($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XC2));
            goto L_800949B4;
    }
    // 0x8009496C: lh          $t5, 0xC2($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XC2));
    // 0x80094970: lw          $t3, 0x19C($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X19C));
    // 0x80094974: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80094978: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
    // 0x8009497C: lw          $t9, 0x1A0($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X1A0));
    // 0x80094980: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // 0x80094984: lw          $t1, 0x1A4($sp)
    ctx->r9 = S32(MEM_W(ctx->r29, 0X1A4));
    // 0x80094988: lw          $t8, 0x16C($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X16C));
    // 0x8009498C: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x80094990: lw          $t7, 0x1A8($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X1A8));
    // 0x80094994: lw          $t2, 0x13C($sp)
    ctx->r10 = S32(MEM_W(ctx->r29, 0X13C));
    // 0x80094998: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x8009499C: lw          $t5, 0x1AC($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X1AC));
    // 0x800949A0: lw          $t6, 0x138($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X138));
    // 0x800949A4: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x800949A8: lw          $t4, 0x1B0($sp)
    ctx->r12 = S32(MEM_W(ctx->r29, 0X1B0));
    // 0x800949AC: lw          $t3, 0x134($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X134));
    // 0x800949B0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_800949B4:
    // 0x800949B4: lw          $v0, 0x16C($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X16C));
L_800949B8:
    // 0x800949B8: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
L_800949BC:
    // 0x800949BC: lui         $v0, 0x8027
    ctx->r2 = S32(0X8027 << 16);
    // 0x800949C0: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800949C4: lh          $v0, 0x4FA0($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, 0X4FA0));
    // 0x800949C8: bgez        $v0, L_80093E18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800949CC: sw          $v0, 0x16C($sp)
        MEM_W(0X16C, ctx->r29) = ctx->r2;
            goto L_80093E18;
    }
    // 0x800949CC: sw          $v0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r2;
    // 0x800949D0: lh          $t8, 0xC6($sp)
    ctx->r24 = S32(MEM_H(ctx->r29, 0XC6));
L_800949D4:
    // 0x800949D4: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800949D8: sh          $t1, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = ctx->r9;
L_800949DC:
    // 0x800949DC: lh          $t2, 0xC6($sp)
    ctx->r10 = S32(MEM_H(ctx->r29, 0XC6));
    // 0x800949E0: lh          $t7, 0xC4($sp)
    ctx->r15 = S32(MEM_H(ctx->r29, 0XC4));
    // 0x800949E4: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800949E8: bnel        $at, $zero, L_800932E8
    if (ctx->r1 != 0) {
        // 0x800949EC: lh          $t5, 0xC6($sp)
        ctx->r13 = S32(MEM_H(ctx->r29, 0XC6));
            goto L_800932E8;
    }
    goto skip_16;
    // 0x800949EC: lh          $t5, 0xC6($sp)
    ctx->r13 = S32(MEM_H(ctx->r29, 0XC6));
    skip_16:
    // 0x800949F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800949F4:
    // 0x800949F4: lw          $ra, 0x64($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X64));
    // 0x800949F8: lw          $s0, 0x40($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X40));
    // 0x800949FC: lw          $s1, 0x44($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X44));
    // 0x80094A00: lw          $s2, 0x48($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X48));
    // 0x80094A04: lw          $s3, 0x4C($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X4C));
    // 0x80094A08: lw          $s4, 0x50($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X50));
    // 0x80094A0C: lw          $s5, 0x54($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X54));
    // 0x80094A10: lw          $s6, 0x58($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X58));
    // 0x80094A14: lw          $s7, 0x5C($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X5C));
    // 0x80094A18: lw          $fp, 0x60($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X60));
    // 0x80094A1C: jr          $ra
    // 0x80094A20: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    return;
    // 0x80094A20: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
;}
RECOMP_FUNC void func_8004D888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D888: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D88C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004D890: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8004D894: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8004D898: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8004D89C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8004D8A0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004D8A4: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8004D8A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004D8AC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8004D8B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004D8B4: lui         $v0, 0x802A
    ctx->r2 = S32(0X802A << 16);
    // 0x8004D8B8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8004D8BC: lbu         $v0, 0x59F0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X59F0);
    // 0x8004D8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D8C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004D8C8: beq         $v0, $zero, L_8004D8F0
    if (ctx->r2 == 0) {
        // 0x8004D8CC: nop
    
            goto L_8004D8F0;
    }
    // 0x8004D8CC: nop

    // 0x8004D8D0: beq         $v0, $at, L_8004D900
    if (ctx->r2 == ctx->r1) {
        // 0x8004D8D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004D900;
    }
    // 0x8004D8D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004D8D8: beq         $v0, $at, L_8004D910
    if (ctx->r2 == ctx->r1) {
        // 0x8004D8DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004D910;
    }
    // 0x8004D8DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004D8E0: beq         $v0, $at, L_8004D920
    if (ctx->r2 == ctx->r1) {
        // 0x8004D8E4: nop
    
            goto L_8004D920;
    }
    // 0x8004D8E4: nop

    // 0x8004D8E8: b           L_8004D930
    // 0x8004D8EC: nop

        goto L_8004D930;
    // 0x8004D8EC: nop

L_8004D8F0:
    // 0x8004D8F0: jal         0x8004D2A0
    // 0x8004D8F4: nop

    func_8004D2A0(rdram, ctx);
        goto after_0;
    // 0x8004D8F4: nop

    after_0:
    // 0x8004D8F8: b           L_8004D93C
    // 0x8004D8FC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8004D93C;
    // 0x8004D8FC: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004D900:
    // 0x8004D900: jal         0x8004D380
    // 0x8004D904: nop

    func_8004D380(rdram, ctx);
        goto after_1;
    // 0x8004D904: nop

    after_1:
    // 0x8004D908: b           L_8004D93C
    // 0x8004D90C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8004D93C;
    // 0x8004D90C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004D910:
    // 0x8004D910: jal         0x8004D460
    // 0x8004D914: nop

    func_8004D460(rdram, ctx);
        goto after_2;
    // 0x8004D914: nop

    after_2:
    // 0x8004D918: b           L_8004D93C
    // 0x8004D91C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8004D93C;
    // 0x8004D91C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004D920:
    // 0x8004D920: jal         0x8004D568
    // 0x8004D924: nop

    func_8004D568(rdram, ctx);
        goto after_3;
    // 0x8004D924: nop

    after_3:
    // 0x8004D928: b           L_8004D93C
    // 0x8004D92C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_8004D93C;
    // 0x8004D92C: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004D930:
    // 0x8004D930: jal         0x8004D380
    // 0x8004D934: nop

    func_8004D380(rdram, ctx);
        goto after_4;
    // 0x8004D934: nop

    after_4:
    // 0x8004D938: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_8004D93C:
    // 0x8004D93C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D940: jr          $ra
    // 0x8004D944: nop

    return;
    // 0x8004D944: nop

;}
RECOMP_FUNC void func_80063594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063594: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80063598: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006359C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800635A0: lui         $s1, 0x8022
    ctx->r17 = S32(0X8022 << 16);
    // 0x800635A4: lui         $s5, 0x8022
    ctx->r21 = S32(0X8022 << 16);
    // 0x800635A8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800635AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800635B0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800635B4: addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
    // 0x800635B8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800635BC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800635C0: addiu       $s5, $s5, -0x5C00
    ctx->r21 = ADD32(ctx->r21, -0X5C00);
    // 0x800635C4: addiu       $s1, $s1, -0x1988
    ctx->r17 = ADD32(ctx->r17, -0X1988);
    // 0x800635C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800635CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
L_800635D0:
    // 0x800635D0: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800635D4: beq         $at, $zero, L_80063694
    if (ctx->r1 == 0) {
        // 0x800635D8: sll         $t6, $s3, 1
        ctx->r14 = S32(ctx->r19 << 1);
            goto L_80063694;
    }
    // 0x800635D8: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800635DC: addu        $t1, $s5, $t6
    ctx->r9 = ADD32(ctx->r21, ctx->r14);
    // 0x800635E0: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x800635E4: addiu       $s0, $s4, -0x1
    ctx->r16 = ADD32(ctx->r20, -0X1);
    // 0x800635E8: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x800635EC: multu       $t7, $s2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800635F0: sll         $t3, $s3, 1
    ctx->r11 = S32(ctx->r19 << 1);
    // 0x800635F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800635F8: addu        $a3, $s5, $t3
    ctx->r7 = ADD32(ctx->r21, ctx->r11);
    // 0x800635FC: addu        $a2, $s5, $t2
    ctx->r6 = ADD32(ctx->r21, ctx->r10);
    // 0x80063600: mflo        $t8
    ctx->r24 = lo;
    // 0x80063604: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80063608: lh          $a1, 0x10($t9)
    ctx->r5 = S32(MEM_H(ctx->r25, 0X10));
L_8006360C:
    // 0x8006360C: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
L_80063610:
    // 0x80063610: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80063614: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80063618: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006361C: mflo        $t4
    ctx->r12 = lo;
    // 0x80063620: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x80063624: lh          $t6, 0x10($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0X10));
    // 0x80063628: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006362C: bnel        $at, $zero, L_80063610
    if (ctx->r1 != 0) {
        // 0x80063630: lhu         $v0, 0x2($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X2);
            goto L_80063610;
    }
    goto skip_0;
    // 0x80063630: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    skip_0:
    // 0x80063634: lhu         $v1, -0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, -0X2);
L_80063638:
    // 0x80063638: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006363C: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // 0x80063640: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063644: mflo        $t7
    ctx->r15 = lo;
    // 0x80063648: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8006364C: lh          $t9, 0x10($t8)
    ctx->r25 = S32(MEM_H(ctx->r24, 0X10));
    // 0x80063650: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80063654: bnel        $at, $zero, L_80063638
    if (ctx->r1 != 0) {
        // 0x80063658: lhu         $v1, -0x2($a3)
        ctx->r3 = MEM_HU(ctx->r7, -0X2);
            goto L_80063638;
    }
    goto skip_1;
    // 0x80063658: lhu         $v1, -0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, -0X2);
    skip_1:
    // 0x8006365C: sh          $v1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r3;
    // 0x80063660: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80063664: bne         $at, $zero, L_8006360C
    if (ctx->r1 != 0) {
        // 0x80063668: sh          $v0, 0x0($a3)
        MEM_H(0X0, ctx->r7) = ctx->r2;
            goto L_8006360C;
    }
    // 0x80063668: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x8006366C: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x80063670: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80063674: addiu       $a1, $s0, -0x1
    ctx->r5 = ADD32(ctx->r16, -0X1);
    // 0x80063678: sh          $t2, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r10;
    // 0x8006367C: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80063680: sh          $t3, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r11;
    // 0x80063684: jal         0x80063594
    // 0x80063688: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    func_80063594(rdram, ctx);
        goto after_0;
    // 0x80063688: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_0:
    // 0x8006368C: b           L_800635D0
    // 0x80063690: addiu       $s4, $s0, 0x1
    ctx->r20 = ADD32(ctx->r16, 0X1);
        goto L_800635D0;
    // 0x80063690: addiu       $s4, $s0, 0x1
    ctx->r20 = ADD32(ctx->r16, 0X1);
L_80063694:
    // 0x80063694: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80063698: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8006369C: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800636A0: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800636A4: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800636A8: lw          $s4, 0x24($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800636AC: lw          $s5, 0x28($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X28));
    // 0x800636B0: jr          $ra
    // 0x800636B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800636B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _frexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD7B8: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800CD7BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800CD7C0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800CD7C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CD7C8: c.eq.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d == ctx->f2.d;
    // 0x800CD7CC: nop

    // 0x800CD7D0: bc1fl       L_800CD7E4
    if (!c1cs) {
        // 0x800CD7D4: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800CD7E4;
    }
    goto skip_0;
    // 0x800CD7D4: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_0:
    // 0x800CD7D8: jr          $ra
    // 0x800CD7DC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x800CD7DC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800CD7E0: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800CD7E4:
    // 0x800CD7E4: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800CD7E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800CD7EC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CD7F0: bc1fl       L_800CD804
    if (!c1cs) {
        // 0x800CD7F4: neg.d       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
            goto L_800CD804;
    }
    goto skip_1;
    // 0x800CD7F4: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
    skip_1:
    // 0x800CD7F8: b           L_800CD804
    // 0x800CD7FC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800CD804;
    // 0x800CD7FC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800CD800: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
L_800CD804:
    // 0x800CD804: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800CD808: nop

    // 0x800CD80C: bc1fl       L_800CD844
    if (!c1cs) {
        // 0x800CD810: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800CD844;
    }
    goto skip_2;
    // 0x800CD810: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_2:
    // 0x800CD814: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CD818: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CD81C: nop

L_800CD820:
    // 0x800CD820: mul.d       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x800CD824: lw          $t6, 0x0($a2)
    ctx->r14 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800CD828: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CD82C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800CD830: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800CD834: nop

    // 0x800CD838: bc1t        L_800CD820
    if (c1cs) {
        // 0x800CD83C: nop
    
            goto L_800CD820;
    }
    // 0x800CD83C: nop

    // 0x800CD840: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_800CD844:
    // 0x800CD844: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CD848: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CD84C: nop

    // 0x800CD850: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x800CD854: nop

    // 0x800CD858: bc1fl       L_800CD880
    if (!c1cs) {
        // 0x800CD85C: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800CD880;
    }
    goto skip_3;
    // 0x800CD85C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_3:
    // 0x800CD860: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
L_800CD864:
    // 0x800CD864: lw          $t8, 0x0($a2)
    ctx->r24 = S32(MEM_W(ctx->r6, 0X0));
    // 0x800CD868: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x800CD86C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800CD870: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CD874: bc1tl       L_800CD864
    if (c1cs) {
        // 0x800CD878: add.d       $f0, $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
            goto L_800CD864;
    }
    goto skip_4;
    // 0x800CD878: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    skip_4:
    // 0x800CD87C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800CD880:
    // 0x800CD880: nop

    // 0x800CD884: bc1fl       L_800CD898
    if (!c1cs) {
        // 0x800CD888: neg.d       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
            goto L_800CD898;
    }
    goto skip_5;
    // 0x800CD888: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
    skip_5:
    // 0x800CD88C: b           L_800CD898
    // 0x800CD890: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
        goto L_800CD898;
    // 0x800CD890: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x800CD894: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
L_800CD898:
    // 0x800CD898: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x800CD89C: jr          $ra
    // 0x800CD8A0: nop

    return;
    // 0x800CD8A0: nop

;}
RECOMP_FUNC void __cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2DB0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800C2DB4: lw          $v0, 0x0($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C2DB8: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C2DBC: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C2DC0: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800C2DC4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800C2DC8: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x800C2DCC: beql        $at, $zero, L_800C2EF4
    if (ctx->r1 == 0) {
        // 0x800C2DD0: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_800C2EF4;
    }
    goto skip_0;
    // 0x800C2DD0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x800C2DD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C2DD8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C2DDC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C2DE0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800C2DE4: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = S32(MEM_W(ctx->r29, 0X0));
    // 0x800C2DE8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2DEC: bc1fl       L_800C2E00
    if (!c1cs) {
        // 0x800C2DF0: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800C2E00;
    }
    goto skip_1;
    // 0x800C2DF0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x800C2DF4: b           L_800C2E00
    // 0x800C2DF8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_800C2E00;
    // 0x800C2DF8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800C2DFC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800C2E00:
    // 0x800C2E00: ldc1        $f8, -0x63C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X63C8);
    // 0x800C2E04: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800C2E08: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C2E0C: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800C2E10: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800C2E14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C2E18: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x800C2E1C: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x800C2E20: nop

    // 0x800C2E24: bc1fl       L_800C2E44
    if (!c1cs) {
        // 0x800C2E28: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_800C2E44;
    }
    goto skip_2;
    // 0x800C2E28: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x800C2E2C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x800C2E30: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800C2E34: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800C2E38: b           L_800C2E54
    // 0x800C2E3C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_800C2E54;
    // 0x800C2E3C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800C2E40: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_800C2E44:
    // 0x800C2E44: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800C2E48: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C2E4C: nop

    // 0x800C2E50: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_800C2E54:
    // 0x800C2E54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2E58: ldc1        $f10, -0x63C0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X63C0);
    // 0x800C2E5C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800C2E60: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2E64: ldc1        $f6, -0x63B8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X63B8);
    // 0x800C2E68: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C2E6C: addiu       $v1, $v1, -0x63F0
    ctx->r3 = ADD32(ctx->r3, -0X63F0);
    // 0x800C2E70: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x800C2E74: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800C2E78: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800C2E7C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x800C2E80: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800C2E84: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x800C2E88: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x800C2E8C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x800C2E90: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800C2E94: nop

    // 0x800C2E98: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x800C2E9C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800C2EA0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800C2EA4: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800C2EA8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x800C2EAC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800C2EB0: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x800C2EB4: bne         $t0, $zero, L_800C2ED4
    if (ctx->r8 != 0) {
        // 0x800C2EB8: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_800C2ED4;
    }
    // 0x800C2EB8: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x800C2EBC: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800C2EC0: nop

    // 0x800C2EC4: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800C2EC8: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800C2ECC: jr          $ra
    // 0x800C2ED0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800C2ED0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800C2ED4:
    // 0x800C2ED4: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800C2ED8: nop

    // 0x800C2EDC: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800C2EE0: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x800C2EE4: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800C2EE8: jr          $ra
    // 0x800C2EEC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800C2EEC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C2EF0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_800C2EF4:
    // 0x800C2EF4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2EF8: bc1t        L_800C2F0C
    if (c1cs) {
        // 0x800C2EFC: nop
    
            goto L_800C2F0C;
    }
    // 0x800C2EFC: nop

    // 0x800C2F00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2F04: jr          $ra
    // 0x800C2F08: lwc1        $f0, -0x5EF0($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X5EF0));
    return;
    // 0x800C2F08: lwc1        $f0, -0x5EF0($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X5EF0));
L_800C2F0C:
    // 0x800C2F0C: lwc1        $f0, -0x63B0($at)
    ctx->f0.u32l = S32(MEM_W(ctx->r1, -0X63B0));
    // 0x800C2F10: jr          $ra
    // 0x800C2F14: nop

    return;
    // 0x800C2F14: nop

;}
RECOMP_FUNC void guTranslateF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD888: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BD88C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BD890: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BD894: jal         0x800C8BC0
    // 0x800BD898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800BD898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BD89C: lw          $a0, 0x18($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800BD8A0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800BD8A4: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x800BD8A8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = S32(MEM_W(ctx->r29, 0X20));
    // 0x800BD8AC: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x800BD8B0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = S32(MEM_W(ctx->r29, 0X24));
    // 0x800BD8B4: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x800BD8B8: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800BD8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD8C0: jr          $ra
    // 0x800BD8C4: nop

    return;
    // 0x800BD8C4: nop

;}
RECOMP_FUNC void func_8006230C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006230C: jr          $ra
    // 0x80062310: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80062310: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDA94: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800BDA98: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800BDA9C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800BDAA0: beql        $t6, $v1, L_800BDACC
    if (ctx->r14 == ctx->r3) {
        // 0x800BDAA4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800BDACC;
    }
    goto skip_0;
    // 0x800BDAA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_800BDAA8:
    // 0x800BDAA8: bnel        $v1, $zero, L_800BDABC
    if (ctx->r3 != 0) {
        // 0x800BDAAC: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_800BDABC;
    }
    goto skip_1;
    // 0x800BDAAC: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x800BDAB0: jr          $ra
    // 0x800BDAB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BDAB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BDAB8: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_800BDABC:
    // 0x800BDABC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BDAC0: bne         $v0, $v1, L_800BDAA8
    if (ctx->r2 != ctx->r3) {
        // 0x800BDAC4: nop
    
            goto L_800BDAA8;
    }
    // 0x800BDAC4: nop

    // 0x800BDAC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800BDACC:
    // 0x800BDACC: jr          $ra
    // 0x800BDAD0: nop

    return;
    // 0x800BDAD0: nop

;}
RECOMP_FUNC void func_80062314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062314: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80062318: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x8006231C: lw          $t6, -0x524C($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, -0X524C));
    // 0x80062320: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80062324: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80062328: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8006232C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80062330: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80062334: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80062338: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006233C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062340: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062344: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062348: blez        $t6, L_80062460
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006234C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80062460;
    }
    // 0x8006234C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80062350: lui         $s3, 0x8022
    ctx->r19 = S32(0X8022 << 16);
    // 0x80062354: lui         $fp, 0x8022
    ctx->r30 = S32(0X8022 << 16);
    // 0x80062358: lui         $s7, 0x8022
    ctx->r23 = S32(0X8022 << 16);
    // 0x8006235C: lui         $s6, 0x8022
    ctx->r22 = S32(0X8022 << 16);
    // 0x80062360: lui         $s5, 0x8022
    ctx->r21 = S32(0X8022 << 16);
    // 0x80062364: lui         $s4, 0x8022
    ctx->r20 = S32(0X8022 << 16);
    // 0x80062368: addiu       $s4, $s4, -0x2984
    ctx->r20 = ADD32(ctx->r20, -0X2984);
    // 0x8006236C: addiu       $s5, $s5, -0x298A
    ctx->r21 = ADD32(ctx->r21, -0X298A);
    // 0x80062370: addiu       $s6, $s6, -0x2986
    ctx->r22 = ADD32(ctx->r22, -0X2986);
    // 0x80062374: addiu       $s7, $s7, -0x2988
    ctx->r23 = ADD32(ctx->r23, -0X2988);
    // 0x80062378: addiu       $fp, $fp, -0x2994
    ctx->r30 = ADD32(ctx->r30, -0X2994);
    // 0x8006237C: addiu       $s3, $s3, -0x5900
    ctx->r19 = ADD32(ctx->r19, -0X5900);
    // 0x80062380: lhu         $s1, 0x0($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X0);
L_80062384:
    // 0x80062384: jal         0x8006141C
    // 0x80062388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8006141C(rdram, ctx);
        goto after_0;
    // 0x80062388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8006238C: lh          $t7, 0x0($s5)
    ctx->r15 = S32(MEM_H(ctx->r21, 0X0));
    // 0x80062390: lh          $t8, 0x0($s6)
    ctx->r24 = S32(MEM_H(ctx->r22, 0X0));
    // 0x80062394: lh          $t0, 0x0($s7)
    ctx->r8 = S32(MEM_H(ctx->r23, 0X0));
    // 0x80062398: lh          $t2, 0x0($s4)
    ctx->r10 = S32(MEM_H(ctx->r20, 0X0));
    // 0x8006239C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800623A0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800623A4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800623A8: beq         $t3, $zero, L_80062444
    if (ctx->r11 == 0) {
        // 0x800623AC: sll         $t6, $s1, 3
        ctx->r14 = S32(ctx->r17 << 3);
            goto L_80062444;
    }
    // 0x800623AC: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x800623B0: lw          $t4, 0x0($fp)
    ctx->r12 = S32(MEM_W(ctx->r30, 0X0));
    // 0x800623B4: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x800623B8: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x800623BC: addiu       $t7, $t7, 0x61A8
    ctx->r15 = ADD32(ctx->r15, 0X61A8);
    // 0x800623C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800623C4: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800623C8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800623CC: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
    // 0x800623D0: jal         0x80061904
    // 0x800623D4: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    func_80061904(rdram, ctx);
        goto after_1;
    // 0x800623D4: lh          $a0, 0x10($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X10));
    after_1:
    // 0x800623D8: lh          $t8, 0x0($s5)
    ctx->r24 = S32(MEM_H(ctx->r21, 0X0));
    // 0x800623DC: lh          $t9, 0x0($s6)
    ctx->r25 = S32(MEM_H(ctx->r22, 0X0));
    // 0x800623E0: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800623E4: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x800623E8: jal         0x800617AC
    // 0x800623EC: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    func_800617AC(rdram, ctx);
        goto after_2;
    // 0x800623EC: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_2:
    // 0x800623F0: lh          $t2, 0xE($s0)
    ctx->r10 = S32(MEM_H(ctx->r16, 0XE));
    // 0x800623F4: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800623F8: beq         $t3, $zero, L_80062420
    if (ctx->r11 == 0) {
        // 0x800623FC: nop
    
            goto L_80062420;
    }
    // 0x800623FC: nop

    // 0x80062400: lh          $t4, 0xA($s0)
    ctx->r12 = S32(MEM_H(ctx->r16, 0XA));
    // 0x80062404: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80062408: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8006240C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80062410: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80062414: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80062418: jal         0x80061904
    // 0x8006241C: lh          $a0, 0x61B8($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X61B8));
    func_80061904(rdram, ctx);
        goto after_3;
    // 0x8006241C: lh          $a0, 0x61B8($a0)
    ctx->r4 = S32(MEM_H(ctx->r4, 0X61B8));
    after_3:
L_80062420:
    // 0x80062420: jal         0x800617AC
    // 0x80062424: lh          $a0, 0x0($s7)
    ctx->r4 = S32(MEM_H(ctx->r23, 0X0));
    func_800617AC(rdram, ctx);
        goto after_4;
    // 0x80062424: lh          $a0, 0x0($s7)
    ctx->r4 = S32(MEM_H(ctx->r23, 0X0));
    after_4:
    // 0x80062428: lh          $t6, 0x0($s4)
    ctx->r14 = S32(MEM_H(ctx->r20, 0X0));
    // 0x8006242C: beq         $t6, $zero, L_80062444
    if (ctx->r14 == 0) {
        // 0x80062430: nop
    
            goto L_80062444;
    }
    // 0x80062430: nop

    // 0x80062434: jal         0x80061904
    // 0x80062438: lh          $a0, 0x12($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X12));
    func_80061904(rdram, ctx);
        goto after_5;
    // 0x80062438: lh          $a0, 0x12($s0)
    ctx->r4 = S32(MEM_H(ctx->r16, 0X12));
    after_5:
    // 0x8006243C: jal         0x800617AC
    // 0x80062440: lh          $a0, 0x0($s4)
    ctx->r4 = S32(MEM_H(ctx->r20, 0X0));
    func_800617AC(rdram, ctx);
        goto after_6;
    // 0x80062440: lh          $a0, 0x0($s4)
    ctx->r4 = S32(MEM_H(ctx->r20, 0X0));
    after_6:
L_80062444:
    // 0x80062444: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x80062448: lw          $t7, -0x524C($t7)
    ctx->r15 = S32(MEM_W(ctx->r15, -0X524C));
    // 0x8006244C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80062450: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80062454: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80062458: bnel        $at, $zero, L_80062384
    if (ctx->r1 != 0) {
        // 0x8006245C: lhu         $s1, 0x0($s3)
        ctx->r17 = MEM_HU(ctx->r19, 0X0);
            goto L_80062384;
    }
    goto skip_0;
    // 0x8006245C: lhu         $s1, 0x0($s3)
    ctx->r17 = MEM_HU(ctx->r19, 0X0);
    skip_0:
L_80062460:
    // 0x80062460: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80062464: addiu       $a0, $a0, 0x4418
    ctx->r4 = ADD32(ctx->r4, 0X4418);
    // 0x80062468: lw          $v1, 0x0($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X0));
    // 0x8006246C: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x80062470: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x80062474: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80062478: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8006247C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80062480: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80062484: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80062488: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8006248C: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x80062490: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80062494: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80062498: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8006249C: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800624A0: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800624A4: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800624A8: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800624AC: jr          $ra
    // 0x800624B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800624B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800570E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800570E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800570EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800570F0: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800570F4: lui         $a1, 0x8022
    ctx->r5 = S32(0X8022 << 16);
    // 0x800570F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800570FC: addiu       $a1, $a1, -0x6648
    ctx->r5 = ADD32(ctx->r5, -0X6648);
    // 0x80057100: addiu       $a0, $a0, -0x6660
    ctx->r4 = ADD32(ctx->r4, -0X6660);
    // 0x80057104: jal         0x800BB760
    // 0x80057108: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80057108: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x8005710C: lui         $s0, 0x8022
    ctx->r16 = S32(0X8022 << 16);
    // 0x80057110: addiu       $s0, $s0, -0x6310
    ctx->r16 = ADD32(ctx->r16, -0X6310);
    // 0x80057114: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80057118: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    // 0x8005711C: ori         $a2, $a2, 0xB000
    ctx->r6 = ctx->r6 | 0XB000;
    // 0x80057120: addiu       $a1, $a1, -0x1660
    ctx->r5 = ADD32(ctx->r5, -0X1660);
    // 0x80057124: jal         0x800BF890
    // 0x80057128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alHeapInit(rdram, ctx);
        goto after_1;
    // 0x80057128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8005712C: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80057130: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80057134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80057138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005713C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80057140: jal         0x800BF830
    // 0x80057144: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80057144: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80057148: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x8005714C: addiu       $t7, $zero, 0x4000
    ctx->r15 = ADD32(0, 0X4000);
    // 0x80057150: sw          $v0, -0x6328($at)
    MEM_W(-0X6328, ctx->r1) = ctx->r2;
    // 0x80057154: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80057158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005715C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80057160: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80057164: jal         0x800BF830
    // 0x80057168: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x80057168: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8005716C: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80057170: addiu       $t8, $zero, 0x58
    ctx->r24 = ADD32(0, 0X58);
    // 0x80057174: sw          $v0, -0x6324($at)
    MEM_W(-0X6324, ctx->r1) = ctx->r2;
    // 0x80057178: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005717C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80057180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80057184: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80057188: jal         0x800BF830
    // 0x8005718C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x8005718C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80057190: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057194: addiu       $t9, $zero, 0x58
    ctx->r25 = ADD32(0, 0X58);
    // 0x80057198: sw          $v0, -0x1718($at)
    MEM_W(-0X1718, ctx->r1) = ctx->r2;
    // 0x8005719C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800571A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800571A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800571A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800571AC: jal         0x800BF830
    // 0x800571B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x800571B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800571B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800571B8: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x800571BC: sw          $v0, -0x1714($at)
    MEM_W(-0X1714, ctx->r1) = ctx->r2;
    // 0x800571C0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800571C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800571C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800571CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800571D0: jal         0x800BF830
    // 0x800571D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x800571D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x800571D8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x800571DC: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x800571E0: sw          $v0, -0x6320($at)
    MEM_W(-0X6320, ctx->r1) = ctx->r2;
    // 0x800571E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800571E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800571EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800571F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800571F4: jal         0x800BF830
    // 0x800571F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_7;
    // 0x800571F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x800571FC: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80057200: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x80057204: sw          $v0, -0x631C($at)
    MEM_W(-0X631C, ctx->r1) = ctx->r2;
    // 0x80057208: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005720C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80057210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80057214: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80057218: jal         0x800BF830
    // 0x8005721C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x8005721C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80057220: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x80057224: sw          $v0, -0x6318($at)
    MEM_W(-0X6318, ctx->r1) = ctx->r2;
    // 0x80057228: jal         0x800BF8D0
    // 0x8005722C: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_9;
    // 0x8005722C: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    after_9:
    // 0x80057230: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80057234: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057238: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005723C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80057240: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80057244: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80057248: lui         $a2, 0x8022
    ctx->r6 = S32(0X8022 << 16);
    // 0x8005724C: addiu       $a2, $a2, -0x5FC4
    ctx->r6 = ADD32(ctx->r6, -0X5FC4);
    // 0x80057250: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80057254: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80057258: addiu       $a1, $a1, -0x16B8
    ctx->r5 = ADD32(ctx->r5, -0X16B8);
    // 0x8005725C: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x80057260: addiu       $a0, $a0, -0x5FB8
    ctx->r4 = ADD32(ctx->r4, -0X5FB8);
    // 0x80057264: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x80057268: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8005726C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80057270: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80057274: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80057278: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8005727C: addiu       $t2, $t2, 0x6F68
    ctx->r10 = ADD32(ctx->r10, 0X6F68);
    // 0x80057280: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80057284: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80057288: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = S32(MEM_W(ctx->r6, 0X0));
    // 0x8005728C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80057290: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80057294: nop

    // 0x80057298: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8005729C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800572A0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800572A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800572A8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800572AC: nop

    // 0x800572B0: bc1fl       L_800572C4
    if (!c1cs) {
        // 0x800572B4: andi        $t7, $v1, 0xF
        ctx->r15 = ctx->r3 & 0XF;
            goto L_800572C4;
    }
    goto skip_0;
    // 0x800572B4: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    skip_0:
    // 0x800572B8: addiu       $v1, $t5, 0x1
    ctx->r3 = ADD32(ctx->r13, 0X1);
    // 0x800572BC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800572C0: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
L_800572C4:
    // 0x800572C4: beq         $t7, $zero, L_800572D4
    if (ctx->r15 == 0) {
        // 0x800572C8: and         $t8, $v1, $at
        ctx->r24 = ctx->r3 & ctx->r1;
            goto L_800572D4;
    }
    // 0x800572C8: and         $t8, $v1, $at
    ctx->r24 = ctx->r3 & ctx->r1;
    // 0x800572CC: addiu       $v1, $t8, 0x10
    ctx->r3 = ADD32(ctx->r24, 0X10);
    // 0x800572D0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800572D4:
    // 0x800572D4: addiu       $t0, $v1, -0x10
    ctx->r8 = ADD32(ctx->r3, -0X10);
    // 0x800572D8: lui         $at, 0x8022
    ctx->r1 = S32(0X8022 << 16);
    // 0x800572DC: sw          $t0, -0x5FB4($at)
    MEM_W(-0X5FB4, ctx->r1) = ctx->r8;
    // 0x800572E0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800572E4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800572E8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800572EC: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x800572F0: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x800572F4: sw          $s0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r16;
    // 0x800572F8: sb          $t3, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = ctx->r11;
    // 0x800572FC: sw          $zero, 0x20($a1)
    MEM_W(0X20, ctx->r5) = 0;
    // 0x80057300: jal         0x800BF7FC
    // 0x80057304: addiu       $a0, $a0, -0x1708
    ctx->r4 = ADD32(ctx->r4, -0X1708);
    alInit(rdram, ctx);
        goto after_10;
    // 0x80057304: addiu       $a0, $a0, -0x1708
    ctx->r4 = ADD32(ctx->r4, -0X1708);
    after_10:
    // 0x80057308: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8005730C: lw          $s0, 0x20($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80057310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80057314: jr          $ra
    // 0x80057318: nop

    return;
    // 0x80057318: nop

;}
RECOMP_FUNC void moveexplosions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BC64: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8007BC68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007BC6C: lui         $s3, 0x8027
    ctx->r19 = S32(0X8027 << 16);
    // 0x8007BC70: lh          $s3, 0x2862($s3)
    ctx->r19 = S32(MEM_H(ctx->r19, 0X2862));
    // 0x8007BC74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007BC78: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007BC7C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007BC80: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007BC84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007BC88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007BC8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007BC90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007BC94: bltz        $s3, L_8007D27C
    if (SIGNED(ctx->r19) < 0) {
        // 0x8007BC98: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8007D27C;
    }
    // 0x8007BC98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007BC9C: lui         $fp, 0x1
    ctx->r30 = S32(0X1 << 16);
    // 0x8007BCA0: lui         $s6, 0x8024
    ctx->r22 = S32(0X8024 << 16);
    // 0x8007BCA4: addiu       $s6, $s6, 0x6BA8
    ctx->r22 = ADD32(ctx->r22, 0X6BA8);
    // 0x8007BCA8: ori         $fp, $fp, 0x1
    ctx->r30 = ctx->r30 | 0X1;
    // 0x8007BCAC: addiu       $s7, $zero, 0x2C
    ctx->r23 = ADD32(0, 0X2C);
L_8007BCB0:
    // 0x8007BCB0: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BCB4: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x8007BCB8: lui         $t7, 0x8027
    ctx->r15 = S32(0X8027 << 16);
    // 0x8007BCBC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007BCC0: lh          $t7, 0x5F40($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, 0X5F40));
    // 0x8007BCC4: sh          $t7, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r15;
    // 0x8007BCC8: mflo        $t8
    ctx->r24 = lo;
    // 0x8007BCCC: addu        $s2, $s6, $t8
    ctx->r18 = ADD32(ctx->r22, ctx->r24);
    // 0x8007BCD0: lh          $a0, 0x10($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X10));
    // 0x8007BCD4: sll         $s5, $a0, 16
    ctx->r21 = S32(ctx->r4 << 16);
    // 0x8007BCD8: sra         $t9, $s5, 16
    ctx->r25 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8007BCDC: bltz        $t9, L_8007BCF8
    if (SIGNED(ctx->r25) < 0) {
        // 0x8007BCE0: or          $s5, $t9, $zero
        ctx->r21 = ctx->r25 | 0;
            goto L_8007BCF8;
    }
    // 0x8007BCE0: or          $s5, $t9, $zero
    ctx->r21 = ctx->r25 | 0;
    // 0x8007BCE4: lbu         $t0, 0x27($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X27);
    // 0x8007BCE8: sll         $t2, $s3, 3
    ctx->r10 = S32(ctx->r19 << 3);
    // 0x8007BCEC: addu        $t2, $t2, $s3
    ctx->r10 = ADD32(ctx->r10, ctx->r19);
    // 0x8007BCF0: bne         $t0, $zero, L_8007BD10
    if (ctx->r8 != 0) {
        // 0x8007BCF4: sll         $t2, $t2, 3
        ctx->r10 = S32(ctx->r10 << 3);
            goto L_8007BD10;
    }
    // 0x8007BCF4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
L_8007BCF8:
    // 0x8007BCF8: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007BCFC: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007BD00: jal         0x80092728
    // 0x8007BD04: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    deletesprite(rdram, ctx);
        goto after_0;
    // 0x8007BD04: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
    // 0x8007BD08: b           L_8007D274
    // 0x8007BD0C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007BD0C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007BD10:
    // 0x8007BD10: lw          $t4, 0x0($s2)
    ctx->r12 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007BD14: lui         $t3, 0x8028
    ctx->r11 = S32(0X8028 << 16);
    // 0x8007BD18: addiu       $t3, $t3, -0x5C00
    ctx->r11 = ADD32(ctx->r11, -0X5C00);
    // 0x8007BD1C: addu        $s4, $t2, $t3
    ctx->r20 = ADD32(ctx->r10, ctx->r11);
    // 0x8007BD20: sw          $t4, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r12;
    // 0x8007BD24: lw          $t5, 0x4($s2)
    ctx->r13 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007BD28: sw          $t5, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r13;
    // 0x8007BD2C: lw          $t6, 0x8($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X8));
    // 0x8007BD30: sw          $t6, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = ctx->r14;
    // 0x8007BD34: lh          $v1, 0xE($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8007BD38: slti        $at, $v1, 0x6F1
    ctx->r1 = SIGNED(ctx->r3) < 0X6F1 ? 1 : 0;
    // 0x8007BD3C: bne         $at, $zero, L_8007BE6C
    if (ctx->r1 != 0) {
        // 0x8007BD40: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8007BE6C;
    }
    // 0x8007BD40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007BD44: slti        $at, $v0, 0x9E8
    ctx->r1 = SIGNED(ctx->r2) < 0X9E8 ? 1 : 0;
    // 0x8007BD48: bne         $at, $zero, L_8007BDBC
    if (ctx->r1 != 0) {
        // 0x8007BD4C: slti        $at, $v0, 0x1000
        ctx->r1 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
            goto L_8007BDBC;
    }
    // 0x8007BD4C: slti        $at, $v0, 0x1000
    ctx->r1 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // 0x8007BD50: bne         $at, $zero, L_8007BD88
    if (ctx->r1 != 0) {
        // 0x8007BD54: addiu       $at, $zero, 0x1125
        ctx->r1 = ADD32(0, 0X1125);
            goto L_8007BD88;
    }
    // 0x8007BD54: addiu       $at, $zero, 0x1125
    ctx->r1 = ADD32(0, 0X1125);
    // 0x8007BD58: beq         $v0, $at, L_8007CA74
    if (ctx->r2 == ctx->r1) {
        // 0x8007BD5C: addiu       $at, $zero, 0x113A
        ctx->r1 = ADD32(0, 0X113A);
            goto L_8007CA74;
    }
    // 0x8007BD5C: addiu       $at, $zero, 0x113A
    ctx->r1 = ADD32(0, 0X113A);
    // 0x8007BD60: beq         $v0, $at, L_8007C544
    if (ctx->r2 == ctx->r1) {
        // 0x8007BD64: addiu       $at, $zero, 0x113B
        ctx->r1 = ADD32(0, 0X113B);
            goto L_8007C544;
    }
    // 0x8007BD64: addiu       $at, $zero, 0x113B
    ctx->r1 = ADD32(0, 0X113B);
    // 0x8007BD68: beq         $v0, $at, L_8007C528
    if (ctx->r2 == ctx->r1) {
        // 0x8007BD6C: addiu       $at, $zero, 0x116C
        ctx->r1 = ADD32(0, 0X116C);
            goto L_8007C528;
    }
    // 0x8007BD6C: addiu       $at, $zero, 0x116C
    ctx->r1 = ADD32(0, 0X116C);
    // 0x8007BD70: beq         $v0, $at, L_8007C544
    if (ctx->r2 == ctx->r1) {
        // 0x8007BD74: addiu       $at, $zero, 0x116D
        ctx->r1 = ADD32(0, 0X116D);
            goto L_8007C544;
    }
    // 0x8007BD74: addiu       $at, $zero, 0x116D
    ctx->r1 = ADD32(0, 0X116D);
    // 0x8007BD78: beql        $v0, $at, L_8007C52C
    if (ctx->r2 == ctx->r1) {
        // 0x8007BD7C: lw          $a1, 0x0($s2)
        ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
            goto L_8007C52C;
    }
    goto skip_0;
    // 0x8007BD7C: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    skip_0:
    // 0x8007BD80: b           L_8007D068
    // 0x8007BD84: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BD84: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BD88:
    // 0x8007BD88: addiu       $at, $zero, 0xA1E
    ctx->r1 = ADD32(0, 0XA1E);
    // 0x8007BD8C: beq         $v0, $at, L_8007C1AC
    if (ctx->r2 == ctx->r1) {
        // 0x8007BD90: addiu       $at, $zero, 0xA34
        ctx->r1 = ADD32(0, 0XA34);
            goto L_8007C1AC;
    }
    // 0x8007BD90: addiu       $at, $zero, 0xA34
    ctx->r1 = ADD32(0, 0XA34);
    // 0x8007BD94: beq         $v0, $at, L_8007CD94
    if (ctx->r2 == ctx->r1) {
        // 0x8007BD98: addiu       $at, $zero, 0xF05
        ctx->r1 = ADD32(0, 0XF05);
            goto L_8007CD94;
    }
    // 0x8007BD98: addiu       $at, $zero, 0xF05
    ctx->r1 = ADD32(0, 0XF05);
    // 0x8007BD9C: beq         $v0, $at, L_8007C4DC
    if (ctx->r2 == ctx->r1) {
        // 0x8007BDA0: addiu       $at, $zero, 0xF71
        ctx->r1 = ADD32(0, 0XF71);
            goto L_8007C4DC;
    }
    // 0x8007BDA0: addiu       $at, $zero, 0xF71
    ctx->r1 = ADD32(0, 0XF71);
    // 0x8007BDA4: beq         $v0, $at, L_8007CD94
    if (ctx->r2 == ctx->r1) {
        // 0x8007BDA8: addiu       $at, $zero, 0xFFF
        ctx->r1 = ADD32(0, 0XFFF);
            goto L_8007CD94;
    }
    // 0x8007BDA8: addiu       $at, $zero, 0xFFF
    ctx->r1 = ADD32(0, 0XFFF);
    // 0x8007BDAC: beql        $v0, $at, L_8007C3D4
    if (ctx->r2 == ctx->r1) {
        // 0x8007BDB0: lh          $t0, 0x16($s2)
        ctx->r8 = S32(MEM_H(ctx->r18, 0X16));
            goto L_8007C3D4;
    }
    goto skip_1;
    // 0x8007BDB0: lh          $t0, 0x16($s2)
    ctx->r8 = S32(MEM_H(ctx->r18, 0X16));
    skip_1:
    // 0x8007BDB4: b           L_8007D068
    // 0x8007BDB8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BDB8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BDBC:
    // 0x8007BDBC: slti        $at, $v0, 0x89A
    ctx->r1 = SIGNED(ctx->r2) < 0X89A ? 1 : 0;
    // 0x8007BDC0: bne         $at, $zero, L_8007BE34
    if (ctx->r1 != 0) {
        // 0x8007BDC4: slti        $at, $v0, 0x91A
        ctx->r1 = SIGNED(ctx->r2) < 0X91A ? 1 : 0;
            goto L_8007BE34;
    }
    // 0x8007BDC4: slti        $at, $v0, 0x91A
    ctx->r1 = SIGNED(ctx->r2) < 0X91A ? 1 : 0;
    // 0x8007BDC8: bne         $at, $zero, L_8007BDEC
    if (ctx->r1 != 0) {
        // 0x8007BDCC: addiu       $at, $zero, 0x9E5
        ctx->r1 = ADD32(0, 0X9E5);
            goto L_8007BDEC;
    }
    // 0x8007BDCC: addiu       $at, $zero, 0x9E5
    ctx->r1 = ADD32(0, 0X9E5);
    // 0x8007BDD0: beq         $v0, $at, L_8007CDC8
    if (ctx->r2 == ctx->r1) {
        // 0x8007BDD4: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007CDC8;
    }
    // 0x8007BDD4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007BDD8: addiu       $at, $zero, 0x9E7
    ctx->r1 = ADD32(0, 0X9E7);
    // 0x8007BDDC: beql        $v0, $at, L_8007CDCC
    if (ctx->r2 == ctx->r1) {
        // 0x8007BDE0: sra         $t0, $a0, 16
        ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8007CDCC;
    }
    goto skip_2;
    // 0x8007BDE0: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    skip_2:
    // 0x8007BDE4: b           L_8007D068
    // 0x8007BDE8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BDE8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BDEC:
    // 0x8007BDEC: slti        $at, $v0, 0x8A2
    ctx->r1 = SIGNED(ctx->r2) < 0X8A2 ? 1 : 0;
    // 0x8007BDF0: bne         $at, $zero, L_8007BE18
    if (ctx->r1 != 0) {
        // 0x8007BDF4: addiu       $t7, $v0, -0x8C5
        ctx->r15 = ADD32(ctx->r2, -0X8C5);
            goto L_8007BE18;
    }
    // 0x8007BDF4: addiu       $t7, $v0, -0x8C5
    ctx->r15 = ADD32(ctx->r2, -0X8C5);
    // 0x8007BDF8: sltiu       $at, $t7, 0x55
    ctx->r1 = ctx->r15 < 0X55 ? 1 : 0;
    // 0x8007BDFC: beq         $at, $zero, L_8007D064
    if (ctx->r1 == 0) {
        // 0x8007BE00: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8007D064;
    }
    // 0x8007BE00: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007BE04: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8007BE08: addu        $at, $at, $t7
    gpr jr_addend_8007BE10 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007BE0C: lw          $t7, 0x55B8($at)
    ctx->r15 = ADD32(ctx->r1, 0X55B8);
    // 0x8007BE10: jr          $t7
    // 0x8007BE14: nop

    switch (jr_addend_8007BE10 >> 2) {
        case 0: goto L_8007C728; break;
        case 1: goto L_8007D064; break;
        case 2: goto L_8007D064; break;
        case 3: goto L_8007D064; break;
        case 4: goto L_8007D064; break;
        case 5: goto L_8007C728; break;
        case 6: goto L_8007D064; break;
        case 7: goto L_8007D064; break;
        case 8: goto L_8007D064; break;
        case 9: goto L_8007D064; break;
        case 10: goto L_8007C728; break;
        case 11: goto L_8007D064; break;
        case 12: goto L_8007D064; break;
        case 13: goto L_8007D064; break;
        case 14: goto L_8007D064; break;
        case 15: goto L_8007C728; break;
        case 16: goto L_8007D064; break;
        case 17: goto L_8007D064; break;
        case 18: goto L_8007D064; break;
        case 19: goto L_8007D064; break;
        case 20: goto L_8007C728; break;
        case 21: goto L_8007D064; break;
        case 22: goto L_8007D064; break;
        case 23: goto L_8007D064; break;
        case 24: goto L_8007D064; break;
        case 25: goto L_8007CD94; break;
        case 26: goto L_8007D064; break;
        case 27: goto L_8007D064; break;
        case 28: goto L_8007D064; break;
        case 29: goto L_8007D064; break;
        case 30: goto L_8007D064; break;
        case 31: goto L_8007D064; break;
        case 32: goto L_8007D064; break;
        case 33: goto L_8007D064; break;
        case 34: goto L_8007D064; break;
        case 35: goto L_8007D064; break;
        case 36: goto L_8007D064; break;
        case 37: goto L_8007D064; break;
        case 38: goto L_8007D064; break;
        case 39: goto L_8007D064; break;
        case 40: goto L_8007D064; break;
        case 41: goto L_8007C728; break;
        case 42: goto L_8007D064; break;
        case 43: goto L_8007D064; break;
        case 44: goto L_8007D064; break;
        case 45: goto L_8007D064; break;
        case 46: goto L_8007D064; break;
        case 47: goto L_8007D064; break;
        case 48: goto L_8007D064; break;
        case 49: goto L_8007D064; break;
        case 50: goto L_8007D064; break;
        case 51: goto L_8007C044; break;
        case 52: goto L_8007C044; break;
        case 53: goto L_8007C044; break;
        case 54: goto L_8007C044; break;
        case 55: goto L_8007D064; break;
        case 56: goto L_8007D064; break;
        case 57: goto L_8007D064; break;
        case 58: goto L_8007D064; break;
        case 59: goto L_8007D064; break;
        case 60: goto L_8007D064; break;
        case 61: goto L_8007D064; break;
        case 62: goto L_8007D064; break;
        case 63: goto L_8007D064; break;
        case 64: goto L_8007D064; break;
        case 65: goto L_8007CD94; break;
        case 66: goto L_8007D064; break;
        case 67: goto L_8007D064; break;
        case 68: goto L_8007D064; break;
        case 69: goto L_8007D064; break;
        case 70: goto L_8007D064; break;
        case 71: goto L_8007D064; break;
        case 72: goto L_8007D064; break;
        case 73: goto L_8007D064; break;
        case 74: goto L_8007D064; break;
        case 75: goto L_8007D064; break;
        case 76: goto L_8007D064; break;
        case 77: goto L_8007D064; break;
        case 78: goto L_8007D064; break;
        case 79: goto L_8007D064; break;
        case 80: goto L_8007D064; break;
        case 81: goto L_8007D064; break;
        case 82: goto L_8007D064; break;
        case 83: goto L_8007D064; break;
        case 84: goto L_8007CD94; break;
        default: switch_error(__func__, 0x8007BE10, 0x801055B8);
    }
    // 0x8007BE14: nop

L_8007BE18:
    // 0x8007BE18: addiu       $at, $zero, 0x89D
    ctx->r1 = ADD32(0, 0X89D);
    // 0x8007BE1C: beq         $v0, $at, L_8007C728
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE20: addiu       $at, $zero, 0x8A1
        ctx->r1 = ADD32(0, 0X8A1);
            goto L_8007C728;
    }
    // 0x8007BE20: addiu       $at, $zero, 0x8A1
    ctx->r1 = ADD32(0, 0X8A1);
    // 0x8007BE24: beql        $v0, $at, L_8007C72C
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE28: lh          $v0, 0x18($s2)
        ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
            goto L_8007C72C;
    }
    goto skip_3;
    // 0x8007BE28: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    skip_3:
    // 0x8007BE2C: b           L_8007D068
    // 0x8007BE30: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BE30: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BE34:
    // 0x8007BE34: addiu       $at, $zero, 0x744
    ctx->r1 = ADD32(0, 0X744);
    // 0x8007BE38: beq         $v0, $at, L_8007C464
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE3C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007C464;
    }
    // 0x8007BE3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007BE40: addiu       $at, $zero, 0x745
    ctx->r1 = ADD32(0, 0X745);
    // 0x8007BE44: beq         $v0, $at, L_8007C464
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE48: addiu       $at, $zero, 0x762
        ctx->r1 = ADD32(0, 0X762);
            goto L_8007C464;
    }
    // 0x8007BE48: addiu       $at, $zero, 0x762
    ctx->r1 = ADD32(0, 0X762);
    // 0x8007BE4C: beq         $v0, $at, L_8007CD94
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE50: addiu       $at, $zero, 0x898
        ctx->r1 = ADD32(0, 0X898);
            goto L_8007CD94;
    }
    // 0x8007BE50: addiu       $at, $zero, 0x898
    ctx->r1 = ADD32(0, 0X898);
    // 0x8007BE54: beq         $v0, $at, L_8007CD94
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE58: addiu       $at, $zero, 0x899
        ctx->r1 = ADD32(0, 0X899);
            goto L_8007CD94;
    }
    // 0x8007BE58: addiu       $at, $zero, 0x899
    ctx->r1 = ADD32(0, 0X899);
    // 0x8007BE5C: beql        $v0, $at, L_8007C72C
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE60: lh          $v0, 0x18($s2)
        ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
            goto L_8007C72C;
    }
    goto skip_4;
    // 0x8007BE60: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    skip_4:
    // 0x8007BE64: b           L_8007D068
    // 0x8007BE68: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BE68: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BE6C:
    // 0x8007BE6C: slti        $at, $v0, 0x4D2
    ctx->r1 = SIGNED(ctx->r2) < 0X4D2 ? 1 : 0;
    // 0x8007BE70: bne         $at, $zero, L_8007BF30
    if (ctx->r1 != 0) {
        // 0x8007BE74: slti        $at, $v0, 0x5F9
        ctx->r1 = SIGNED(ctx->r2) < 0X5F9 ? 1 : 0;
            goto L_8007BF30;
    }
    // 0x8007BE74: slti        $at, $v0, 0x5F9
    ctx->r1 = SIGNED(ctx->r2) < 0X5F9 ? 1 : 0;
    // 0x8007BE78: bne         $at, $zero, L_8007BEFC
    if (ctx->r1 != 0) {
        // 0x8007BE7C: slti        $at, $v0, 0x6E9
        ctx->r1 = SIGNED(ctx->r2) < 0X6E9 ? 1 : 0;
            goto L_8007BEFC;
    }
    // 0x8007BE7C: slti        $at, $v0, 0x6E9
    ctx->r1 = SIGNED(ctx->r2) < 0X6E9 ? 1 : 0;
    // 0x8007BE80: bne         $at, $zero, L_8007BEA0
    if (ctx->r1 != 0) {
        // 0x8007BE84: addiu       $at, $zero, 0x6EC
        ctx->r1 = ADD32(0, 0X6EC);
            goto L_8007BEA0;
    }
    // 0x8007BE84: addiu       $at, $zero, 0x6EC
    ctx->r1 = ADD32(0, 0X6EC);
    // 0x8007BE88: beq         $v0, $at, L_8007C728
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE8C: addiu       $at, $zero, 0x6F0
        ctx->r1 = ADD32(0, 0X6F0);
            goto L_8007C728;
    }
    // 0x8007BE8C: addiu       $at, $zero, 0x6F0
    ctx->r1 = ADD32(0, 0X6F0);
    // 0x8007BE90: beql        $v0, $at, L_8007C72C
    if (ctx->r2 == ctx->r1) {
        // 0x8007BE94: lh          $v0, 0x18($s2)
        ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
            goto L_8007C72C;
    }
    goto skip_5;
    // 0x8007BE94: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    skip_5:
    // 0x8007BE98: b           L_8007D068
    // 0x8007BE9C: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BE9C: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BEA0:
    // 0x8007BEA0: slti        $at, $v0, 0x688
    ctx->r1 = SIGNED(ctx->r2) < 0X688 ? 1 : 0;
    // 0x8007BEA4: bne         $at, $zero, L_8007BEBC
    if (ctx->r1 != 0) {
        // 0x8007BEA8: addiu       $at, $zero, 0x6E8
        ctx->r1 = ADD32(0, 0X6E8);
            goto L_8007BEBC;
    }
    // 0x8007BEA8: addiu       $at, $zero, 0x6E8
    ctx->r1 = ADD32(0, 0X6E8);
    // 0x8007BEAC: beql        $v0, $at, L_8007C72C
    if (ctx->r2 == ctx->r1) {
        // 0x8007BEB0: lh          $v0, 0x18($s2)
        ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
            goto L_8007C72C;
    }
    goto skip_6;
    // 0x8007BEB0: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    skip_6:
    // 0x8007BEB4: b           L_8007D068
    // 0x8007BEB8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BEB8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BEBC:
    // 0x8007BEBC: slti        $at, $v0, 0x601
    ctx->r1 = SIGNED(ctx->r2) < 0X601 ? 1 : 0;
    // 0x8007BEC0: bne         $at, $zero, L_8007BEE8
    if (ctx->r1 != 0) {
        // 0x8007BEC4: addiu       $t8, $v0, -0x654
        ctx->r24 = ADD32(ctx->r2, -0X654);
            goto L_8007BEE8;
    }
    // 0x8007BEC4: addiu       $t8, $v0, -0x654
    ctx->r24 = ADD32(ctx->r2, -0X654);
    // 0x8007BEC8: sltiu       $at, $t8, 0x34
    ctx->r1 = ctx->r24 < 0X34 ? 1 : 0;
    // 0x8007BECC: beq         $at, $zero, L_8007D064
    if (ctx->r1 == 0) {
        // 0x8007BED0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8007D064;
    }
    // 0x8007BED0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007BED4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8007BED8: addu        $at, $at, $t8
    gpr jr_addend_8007BEE0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8007BEDC: lw          $t8, 0x570C($at)
    ctx->r24 = ADD32(ctx->r1, 0X570C);
    // 0x8007BEE0: jr          $t8
    // 0x8007BEE4: nop

    switch (jr_addend_8007BEE0 >> 2) {
        case 0: goto L_8007CD94; break;
        case 1: goto L_8007D064; break;
        case 2: goto L_8007D064; break;
        case 3: goto L_8007D064; break;
        case 4: goto L_8007D064; break;
        case 5: goto L_8007C4DC; break;
        case 6: goto L_8007D064; break;
        case 7: goto L_8007D064; break;
        case 8: goto L_8007D064; break;
        case 9: goto L_8007D064; break;
        case 10: goto L_8007CD94; break;
        case 11: goto L_8007D064; break;
        case 12: goto L_8007D064; break;
        case 13: goto L_8007D064; break;
        case 14: goto L_8007D064; break;
        case 15: goto L_8007D064; break;
        case 16: goto L_8007D064; break;
        case 17: goto L_8007D064; break;
        case 18: goto L_8007D064; break;
        case 19: goto L_8007D064; break;
        case 20: goto L_8007D064; break;
        case 21: goto L_8007D064; break;
        case 22: goto L_8007D064; break;
        case 23: goto L_8007D064; break;
        case 24: goto L_8007D064; break;
        case 25: goto L_8007D064; break;
        case 26: goto L_8007D064; break;
        case 27: goto L_8007C510; break;
        case 28: goto L_8007D064; break;
        case 29: goto L_8007D064; break;
        case 30: goto L_8007D064; break;
        case 31: goto L_8007D064; break;
        case 32: goto L_8007D064; break;
        case 33: goto L_8007D064; break;
        case 34: goto L_8007D064; break;
        case 35: goto L_8007D064; break;
        case 36: goto L_8007CD94; break;
        case 37: goto L_8007D064; break;
        case 38: goto L_8007D064; break;
        case 39: goto L_8007D064; break;
        case 40: goto L_8007D064; break;
        case 41: goto L_8007D064; break;
        case 42: goto L_8007D064; break;
        case 43: goto L_8007D064; break;
        case 44: goto L_8007D064; break;
        case 45: goto L_8007D064; break;
        case 46: goto L_8007D064; break;
        case 47: goto L_8007D064; break;
        case 48: goto L_8007D064; break;
        case 49: goto L_8007D064; break;
        case 50: goto L_8007D064; break;
        case 51: goto L_8007CD94; break;
        default: switch_error(__func__, 0x8007BEE0, 0x8010570C);
    }
    // 0x8007BEE4: nop

L_8007BEE8:
    // 0x8007BEE8: addiu       $at, $zero, 0x600
    ctx->r1 = ADD32(0, 0X600);
    // 0x8007BEEC: beql        $v0, $at, L_8007C72C
    if (ctx->r2 == ctx->r1) {
        // 0x8007BEF0: lh          $v0, 0x18($s2)
        ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
            goto L_8007C72C;
    }
    goto skip_7;
    // 0x8007BEF0: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    skip_7:
    // 0x8007BEF4: b           L_8007D068
    // 0x8007BEF8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BEF8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BEFC:
    // 0x8007BEFC: addiu       $at, $zero, 0x4D2
    ctx->r1 = ADD32(0, 0X4D2);
    // 0x8007BF00: beq         $v0, $at, L_8007C528
    if (ctx->r2 == ctx->r1) {
        // 0x8007BF04: addiu       $at, $zero, 0x4ED
        ctx->r1 = ADD32(0, 0X4ED);
            goto L_8007C528;
    }
    // 0x8007BF04: addiu       $at, $zero, 0x4ED
    ctx->r1 = ADD32(0, 0X4ED);
    // 0x8007BF08: beq         $v0, $at, L_8007CD94
    if (ctx->r2 == ctx->r1) {
        // 0x8007BF0C: addiu       $at, $zero, 0x564
        ctx->r1 = ADD32(0, 0X564);
            goto L_8007CD94;
    }
    // 0x8007BF0C: addiu       $at, $zero, 0x564
    ctx->r1 = ADD32(0, 0X564);
    // 0x8007BF10: beq         $v0, $at, L_8007C310
    if (ctx->r2 == ctx->r1) {
        // 0x8007BF14: addiu       $at, $zero, 0x5F0
        ctx->r1 = ADD32(0, 0X5F0);
            goto L_8007C310;
    }
    // 0x8007BF14: addiu       $at, $zero, 0x5F0
    ctx->r1 = ADD32(0, 0X5F0);
    // 0x8007BF18: beq         $v0, $at, L_8007C728
    if (ctx->r2 == ctx->r1) {
        // 0x8007BF1C: addiu       $at, $zero, 0x5F8
        ctx->r1 = ADD32(0, 0X5F8);
            goto L_8007C728;
    }
    // 0x8007BF1C: addiu       $at, $zero, 0x5F8
    ctx->r1 = ADD32(0, 0X5F8);
    // 0x8007BF20: beql        $v0, $at, L_8007C72C
    if (ctx->r2 == ctx->r1) {
        // 0x8007BF24: lh          $v0, 0x18($s2)
        ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
            goto L_8007C72C;
    }
    goto skip_8;
    // 0x8007BF24: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    skip_8:
    // 0x8007BF28: b           L_8007D068
    // 0x8007BF2C: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BF2C: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BF30:
    // 0x8007BF30: slti        $at, $v0, 0x296
    ctx->r1 = SIGNED(ctx->r2) < 0X296 ? 1 : 0;
    // 0x8007BF34: bne         $at, $zero, L_8007BFAC
    if (ctx->r1 != 0) {
        // 0x8007BF38: slti        $at, $v0, 0x417
        ctx->r1 = SIGNED(ctx->r2) < 0X417 ? 1 : 0;
            goto L_8007BFAC;
    }
    // 0x8007BF38: slti        $at, $v0, 0x417
    ctx->r1 = SIGNED(ctx->r2) < 0X417 ? 1 : 0;
    // 0x8007BF3C: bne         $at, $zero, L_8007BF5C
    if (ctx->r1 != 0) {
        // 0x8007BF40: addiu       $at, $zero, 0x4CA
        ctx->r1 = ADD32(0, 0X4CA);
            goto L_8007BF5C;
    }
    // 0x8007BF40: addiu       $at, $zero, 0x4CA
    ctx->r1 = ADD32(0, 0X4CA);
    // 0x8007BF44: beq         $v0, $at, L_8007CA74
    if (ctx->r2 == ctx->r1) {
        // 0x8007BF48: addiu       $at, $zero, 0x4D1
        ctx->r1 = ADD32(0, 0X4D1);
            goto L_8007CA74;
    }
    // 0x8007BF48: addiu       $at, $zero, 0x4D1
    ctx->r1 = ADD32(0, 0X4D1);
    // 0x8007BF4C: beq         $v0, $at, L_8007C544
    if (ctx->r2 == ctx->r1) {
        // 0x8007BF50: nop
    
            goto L_8007C544;
    }
    // 0x8007BF50: nop

    // 0x8007BF54: b           L_8007D068
    // 0x8007BF58: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BF58: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BF5C:
    // 0x8007BF5C: slti        $at, $v0, 0x39F
    ctx->r1 = SIGNED(ctx->r2) < 0X39F ? 1 : 0;
    // 0x8007BF60: bnel        $at, $zero, L_8007BF90
    if (ctx->r1 != 0) {
        // 0x8007BF64: addiu       $at, $zero, 0x39D
        ctx->r1 = ADD32(0, 0X39D);
            goto L_8007BF90;
    }
    goto skip_9;
    // 0x8007BF64: addiu       $at, $zero, 0x39D
    ctx->r1 = ADD32(0, 0X39D);
    skip_9:
    // 0x8007BF68: addiu       $t9, $v0, -0x3EF
    ctx->r25 = ADD32(ctx->r2, -0X3EF);
    // 0x8007BF6C: sltiu       $at, $t9, 0x28
    ctx->r1 = ctx->r25 < 0X28 ? 1 : 0;
    // 0x8007BF70: beq         $at, $zero, L_8007D064
    if (ctx->r1 == 0) {
        // 0x8007BF74: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8007D064;
    }
    // 0x8007BF74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8007BF78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8007BF7C: addu        $at, $at, $t9
    gpr jr_addend_8007BF84 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8007BF80: lw          $t9, 0x57DC($at)
    ctx->r25 = ADD32(ctx->r1, 0X57DC);
    // 0x8007BF84: jr          $t9
    // 0x8007BF88: nop

    switch (jr_addend_8007BF84 >> 2) {
        case 0: goto L_8007BFE4; break;
        case 1: goto L_8007BFE4; break;
        case 2: goto L_8007BFE4; break;
        case 3: goto L_8007D064; break;
        case 4: goto L_8007D064; break;
        case 5: goto L_8007D064; break;
        case 6: goto L_8007D064; break;
        case 7: goto L_8007D064; break;
        case 8: goto L_8007D064; break;
        case 9: goto L_8007D064; break;
        case 10: goto L_8007D064; break;
        case 11: goto L_8007D064; break;
        case 12: goto L_8007D064; break;
        case 13: goto L_8007D064; break;
        case 14: goto L_8007D064; break;
        case 15: goto L_8007D064; break;
        case 16: goto L_8007D064; break;
        case 17: goto L_8007D064; break;
        case 18: goto L_8007D064; break;
        case 19: goto L_8007D064; break;
        case 20: goto L_8007D064; break;
        case 21: goto L_8007D064; break;
        case 22: goto L_8007D064; break;
        case 23: goto L_8007D064; break;
        case 24: goto L_8007CEE4; break;
        case 25: goto L_8007CEE4; break;
        case 26: goto L_8007CEE4; break;
        case 27: goto L_8007D064; break;
        case 28: goto L_8007D064; break;
        case 29: goto L_8007D064; break;
        case 30: goto L_8007D064; break;
        case 31: goto L_8007D064; break;
        case 32: goto L_8007D064; break;
        case 33: goto L_8007D064; break;
        case 34: goto L_8007D064; break;
        case 35: goto L_8007D064; break;
        case 36: goto L_8007D064; break;
        case 37: goto L_8007D064; break;
        case 38: goto L_8007D064; break;
        case 39: goto L_8007BFE4; break;
        default: switch_error(__func__, 0x8007BF84, 0x801057DC);
    }
    // 0x8007BF88: nop

    // 0x8007BF8C: addiu       $at, $zero, 0x39D
    ctx->r1 = ADD32(0, 0X39D);
L_8007BF90:
    // 0x8007BF90: beql        $v0, $at, L_8007BFE8
    if (ctx->r2 == ctx->r1) {
        // 0x8007BF94: lh          $t1, 0x1E($s2)
        ctx->r9 = S32(MEM_H(ctx->r18, 0X1E));
            goto L_8007BFE8;
    }
    goto skip_10;
    // 0x8007BF94: lh          $t1, 0x1E($s2)
    ctx->r9 = S32(MEM_H(ctx->r18, 0X1E));
    skip_10:
    // 0x8007BF98: addiu       $at, $zero, 0x39E
    ctx->r1 = ADD32(0, 0X39E);
    // 0x8007BF9C: beql        $v0, $at, L_8007BFE8
    if (ctx->r2 == ctx->r1) {
        // 0x8007BFA0: lh          $t1, 0x1E($s2)
        ctx->r9 = S32(MEM_H(ctx->r18, 0X1E));
            goto L_8007BFE8;
    }
    goto skip_11;
    // 0x8007BFA0: lh          $t1, 0x1E($s2)
    ctx->r9 = S32(MEM_H(ctx->r18, 0X1E));
    skip_11:
    // 0x8007BFA4: b           L_8007D068
    // 0x8007BFA8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BFA8: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BFAC:
    // 0x8007BFAC: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x8007BFB0: beq         $v0, $at, L_8007C0A4
    if (ctx->r2 == ctx->r1) {
        // 0x8007BFB4: lui         $t8, 0x802B
        ctx->r24 = S32(0X802B << 16);
            goto L_8007C0A4;
    }
    // 0x8007BFB4: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x8007BFB8: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x8007BFBC: beq         $v0, $at, L_8007C0A4
    if (ctx->r2 == ctx->r1) {
        // 0x8007BFC0: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_8007C0A4;
    }
    // 0x8007BFC0: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8007BFC4: beq         $v0, $at, L_8007C0A4
    if (ctx->r2 == ctx->r1) {
        // 0x8007BFC8: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_8007C0A4;
    }
    // 0x8007BFC8: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8007BFCC: beq         $v0, $at, L_8007C0A4
    if (ctx->r2 == ctx->r1) {
        // 0x8007BFD0: addiu       $at, $zero, 0x295
        ctx->r1 = ADD32(0, 0X295);
            goto L_8007C0A4;
    }
    // 0x8007BFD0: addiu       $at, $zero, 0x295
    ctx->r1 = ADD32(0, 0X295);
    // 0x8007BFD4: beql        $v0, $at, L_8007CD98
    if (ctx->r2 == ctx->r1) {
        // 0x8007BFD8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007CD98;
    }
    goto skip_12;
    // 0x8007BFD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_12:
    // 0x8007BFDC: b           L_8007D068
    // 0x8007BFE0: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
        goto L_8007D068;
    // 0x8007BFE0: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007BFE4:
    // 0x8007BFE4: lh          $t1, 0x1E($s2)
    ctx->r9 = S32(MEM_H(ctx->r18, 0X1E));
L_8007BFE8:
    // 0x8007BFE8: lui         $t0, 0x802B
    ctx->r8 = S32(0X802B << 16);
    // 0x8007BFEC: lh          $t0, -0x55BE($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, -0X55BE));
    // 0x8007BFF0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8007BFF4: div         $zero, $t0, $t2
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r10)));
    // 0x8007BFF8: bne         $t2, $zero, L_8007C004
    if (ctx->r10 != 0) {
        // 0x8007BFFC: nop
    
            goto L_8007C004;
    }
    // 0x8007BFFC: nop

    // 0x8007C000: break       7
    do_break(2147991552);
L_8007C004:
    // 0x8007C004: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007C008: bne         $t2, $at, L_8007C01C
    if (ctx->r10 != ctx->r1) {
        // 0x8007C00C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007C01C;
    }
    // 0x8007C00C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C010: bne         $t0, $at, L_8007C01C
    if (ctx->r8 != ctx->r1) {
        // 0x8007C014: nop
    
            goto L_8007C01C;
    }
    // 0x8007C014: nop

    // 0x8007C018: break       6
    do_break(2147991576);
L_8007C01C:
    // 0x8007C01C: mflo        $t3
    ctx->r11 = lo;
    // 0x8007C020: andi        $t4, $t3, 0x1F
    ctx->r12 = ctx->r11 & 0X1F;
    // 0x8007C024: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8007C028: bne         $at, $zero, L_8007C038
    if (ctx->r1 != 0) {
        // 0x8007C02C: addiu       $t5, $zero, -0x7F
        ctx->r13 = ADD32(0, -0X7F);
            goto L_8007C038;
    }
    // 0x8007C02C: addiu       $t5, $zero, -0x7F
    ctx->r13 = ADD32(0, -0X7F);
    // 0x8007C030: b           L_8007D270
    // 0x8007C034: sb          $t5, 0x24($s2)
    MEM_B(0X24, ctx->r18) = ctx->r13;
        goto L_8007D270;
    // 0x8007C034: sb          $t5, 0x24($s2)
    MEM_B(0X24, ctx->r18) = ctx->r13;
L_8007C038:
    // 0x8007C038: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x8007C03C: b           L_8007D270
    // 0x8007C040: sb          $t6, 0x24($s2)
    MEM_B(0X24, ctx->r18) = ctx->r14;
        goto L_8007D270;
    // 0x8007C040: sb          $t6, 0x24($s2)
    MEM_B(0X24, ctx->r18) = ctx->r14;
L_8007C044:
    // 0x8007C044: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007C048: lw          $t7, 0x0($s1)
    ctx->r15 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007C04C: addiu       $at, $zero, 0xB6
    ctx->r1 = ADD32(0, 0XB6);
    // 0x8007C050: beql        $t7, $at, L_8007D274
    if (ctx->r15 == ctx->r1) {
        // 0x8007C054: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_13;
    // 0x8007C054: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_13:
    // 0x8007C058: jal         0x8009800C
    // 0x8007C05C: nop

    krand2(rdram, ctx);
        goto after_1;
    // 0x8007C05C: nop

    after_1:
    // 0x8007C060: lw          $t8, 0x8($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X8));
    // 0x8007C064: andi        $t9, $v0, 0xF
    ctx->r25 = ctx->r2 & 0XF;
    // 0x8007C068: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8007C06C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8007C070: addiu       $t0, $t1, 0x10
    ctx->r8 = ADD32(ctx->r9, 0X10);
    // 0x8007C074: sw          $t0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r8;
    // 0x8007C078: lw          $t2, 0x0($s1)
    ctx->r10 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007C07C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8007C080: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8007C084: mfhi        $t5
    ctx->r13 = hi;
    // 0x8007C088: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8007C08C: bnel        $t5, $zero, L_8007D274
    if (ctx->r13 != 0) {
        // 0x8007C090: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_14;
    // 0x8007C090: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_14:
    // 0x8007C094: lbu         $t6, 0x28($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X28);
    // 0x8007C098: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007C09C: b           L_8007D270
    // 0x8007C0A0: sb          $t7, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r15;
        goto L_8007D270;
    // 0x8007C0A0: sb          $t7, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r15;
L_8007C0A4:
    // 0x8007C0A4: lw          $t8, -0x540C($t8)
    ctx->r24 = S32(MEM_W(ctx->r24, -0X540C));
    // 0x8007C0A8: lui         $t9, 0x802B
    ctx->r25 = S32(0X802B << 16);
    // 0x8007C0AC: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8007C0B0: bnel        $at, $zero, L_8007C0DC
    if (ctx->r1 != 0) {
        // 0x8007C0B4: addiu       $s1, $s4, 0x30
        ctx->r17 = ADD32(ctx->r20, 0X30);
            goto L_8007C0DC;
    }
    goto skip_15;
    // 0x8007C0B4: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    skip_15:
    // 0x8007C0B8: lw          $t9, -0x545C($t9)
    ctx->r25 = S32(MEM_W(ctx->r25, -0X545C));
    // 0x8007C0BC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007C0C0: bnel        $t9, $zero, L_8007C0DC
    if (ctx->r25 != 0) {
        // 0x8007C0C4: addiu       $s1, $s4, 0x30
        ctx->r17 = ADD32(ctx->r20, 0X30);
            goto L_8007C0DC;
    }
    goto skip_16;
    // 0x8007C0C4: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    skip_16:
    // 0x8007C0C8: lbu         $t1, 0x378C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X378C);
    // 0x8007C0CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C0D0: bnel        $t1, $at, L_8007D274
    if (ctx->r9 != ctx->r1) {
        // 0x8007C0D4: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_17;
    // 0x8007C0D4: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_17:
    // 0x8007C0D8: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
L_8007C0DC:
    // 0x8007C0DC: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007C0E0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007C0E4: beq         $v1, $zero, L_8007D270
    if (ctx->r3 == 0) {
        // 0x8007C0E8: addiu       $t0, $v1, 0x1
        ctx->r8 = ADD32(ctx->r3, 0X1);
            goto L_8007D270;
    }
    // 0x8007C0E8: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x8007C0EC: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x8007C0F0: bne         $t0, $at, L_8007C104
    if (ctx->r8 != ctx->r1) {
        // 0x8007C0F4: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8007C104;
    }
    // 0x8007C0F4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8007C0F8: addiu       $t2, $zero, 0x8F
    ctx->r10 = ADD32(0, 0X8F);
    // 0x8007C0FC: b           L_8007C158
    // 0x8007C100: sh          $t2, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r10;
        goto L_8007C158;
    // 0x8007C100: sh          $t2, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r10;
L_8007C104:
    // 0x8007C104: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007C108: bnel        $v1, $at, L_8007C15C
    if (ctx->r3 != ctx->r1) {
        // 0x8007C10C: lh          $t1, 0x16($s2)
        ctx->r9 = S32(MEM_H(ctx->r18, 0X16));
            goto L_8007C15C;
    }
    goto skip_18;
    // 0x8007C10C: lh          $t1, 0x16($s2)
    ctx->r9 = S32(MEM_H(ctx->r18, 0X16));
    skip_18:
    // 0x8007C110: lh          $t5, 0x16($s2)
    ctx->r13 = S32(MEM_H(ctx->r18, 0X16));
    // 0x8007C114: addiu       $t3, $zero, 0x90
    ctx->r11 = ADD32(0, 0X90);
    // 0x8007C118: sh          $t3, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r11;
    // 0x8007C11C: multu       $t5, $s7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007C120: lui         $at, 0x802A
    ctx->r1 = S32(0X802A << 16);
    // 0x8007C124: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007C128: mflo        $t6
    ctx->r14 = lo;
    // 0x8007C12C: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x8007C130: lh          $t8, 0x1A($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0X1A));
    // 0x8007C134: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8007C138: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8007C13C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8007C140: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8007C144: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8007C148: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8007C14C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8007C150: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8007C154: sh          $t4, 0x5A56($at)
    MEM_H(0X5A56, ctx->r1) = ctx->r12;
L_8007C158:
    // 0x8007C158: lh          $t1, 0x16($s2)
    ctx->r9 = S32(MEM_H(ctx->r18, 0X16));
L_8007C15C:
    // 0x8007C15C: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x8007C160: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8007C164: multu       $t1, $s7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007C168: addiu       $t7, $zero, 0x91
    ctx->r15 = ADD32(0, 0X91);
    // 0x8007C16C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007C170: addu        $t2, $s6, $t0
    ctx->r10 = ADD32(ctx->r22, ctx->r8);
    // 0x8007C174: lh          $t3, 0x1A($t2)
    ctx->r11 = S32(MEM_H(ctx->r10, 0X1A));
    // 0x8007C178: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8007C17C: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8007C180: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007C184: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8007C188: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007C18C: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8007C190: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8007C194: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8007C198: lh          $t6, 0x5A56($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, 0X5A56));
    // 0x8007C19C: bnel        $t6, $at, L_8007D274
    if (ctx->r14 != ctx->r1) {
        // 0x8007C1A0: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_19;
    // 0x8007C1A0: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_19:
    // 0x8007C1A4: b           L_8007D270
    // 0x8007C1A8: sh          $t7, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r15;
        goto L_8007D270;
    // 0x8007C1A8: sh          $t7, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r15;
L_8007C1AC:
    // 0x8007C1AC: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007C1B0: lw          $v0, 0x4($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007C1B4: lbu         $a3, 0x27($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X27);
    // 0x8007C1B8: blez        $v0, L_8007C1E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007C1BC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8007C1E0;
    }
    // 0x8007C1BC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8007C1C0: bne         $t8, $zero, L_8007C1E0
    if (ctx->r24 != 0) {
        // 0x8007C1C4: sw          $t8, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r24;
            goto L_8007C1E0;
    }
    // 0x8007C1C4: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x8007C1C8: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C1CC: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C1D0: jal         0x80092728
    // 0x8007C1D4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    deletesprite(rdram, ctx);
        goto after_2;
    // 0x8007C1D4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x8007C1D8: b           L_8007D274
    // 0x8007C1DC: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C1DC: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007C1E0:
    // 0x8007C1E0: lh          $a0, 0x16($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X16));
    // 0x8007C1E4: lui         $t0, 0x8028
    ctx->r8 = S32(0X8028 << 16);
    // 0x8007C1E8: addiu       $t0, $t0, -0x5C00
    ctx->r8 = ADD32(ctx->r8, -0X5C00);
    // 0x8007C1EC: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x8007C1F0: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8007C1F4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007C1F8: addu        $a1, $t1, $t0
    ctx->r5 = ADD32(ctx->r9, ctx->r8);
    // 0x8007C1FC: lw          $t2, 0x34($a1)
    ctx->r10 = S32(MEM_W(ctx->r5, 0X34));
    // 0x8007C200: bnel        $t2, $zero, L_8007C244
    if (ctx->r10 != 0) {
        // 0x8007C204: lw          $v1, 0x0($s1)
        ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
            goto L_8007C244;
    }
    goto skip_20;
    // 0x8007C204: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    skip_20:
    // 0x8007C208: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007C20C: lui         $t6, 0x8028
    ctx->r14 = S32(0X8028 << 16);
    // 0x8007C210: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x8007C214: beq         $at, $zero, L_8007C274
    if (ctx->r1 == 0) {
        // 0x8007C218: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_8007C274;
    }
    // 0x8007C218: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8007C21C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8007C220: lh          $a0, 0x16($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X16));
    // 0x8007C224: addiu       $t6, $t6, -0x5C00
    ctx->r14 = ADD32(ctx->r14, -0X5C00);
    // 0x8007C228: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x8007C22C: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x8007C230: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8007C234: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8007C238: b           L_8007C274
    // 0x8007C23C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
        goto L_8007C274;
    // 0x8007C23C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8007C240: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
L_8007C244:
    // 0x8007C244: lui         $t4, 0x8028
    ctx->r12 = S32(0X8028 << 16);
    // 0x8007C248: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
    // 0x8007C24C: bne         $at, $zero, L_8007C274
    if (ctx->r1 != 0) {
        // 0x8007C250: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8007C274;
    }
    // 0x8007C250: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8007C254: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8007C258: lh          $a0, 0x16($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X16));
    // 0x8007C25C: addiu       $t4, $t4, -0x5C00
    ctx->r12 = ADD32(ctx->r12, -0X5C00);
    // 0x8007C260: addiu       $a3, $a3, -0x3
    ctx->r7 = ADD32(ctx->r7, -0X3);
    // 0x8007C264: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8007C268: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8007C26C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007C270: addu        $a1, $t8, $t4
    ctx->r5 = ADD32(ctx->r24, ctx->r12);
L_8007C274:
    // 0x8007C274: multu       $a0, $s7
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007C278: lh          $t3, 0x14($s2)
    ctx->r11 = S32(MEM_H(ctx->r18, 0X14));
    // 0x8007C27C: slti        $at, $a3, 0x41
    ctx->r1 = SIGNED(ctx->r7) < 0X41 ? 1 : 0;
    // 0x8007C280: mflo        $t9
    ctx->r25 = lo;
    // 0x8007C284: addu        $v0, $s6, $t9
    ctx->r2 = ADD32(ctx->r22, ctx->r25);
    // 0x8007C288: lw          $t1, 0x0($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X0));
    // 0x8007C28C: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x8007C290: lw          $t0, 0x4($v0)
    ctx->r8 = S32(MEM_W(ctx->r2, 0X4));
    // 0x8007C294: sw          $t0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r8;
    // 0x8007C298: lw          $t2, 0x8($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X8));
    // 0x8007C29C: sw          $t2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r10;
    // 0x8007C2A0: lw          $t5, 0x30($a1)
    ctx->r13 = S32(MEM_W(ctx->r5, 0X30));
    // 0x8007C2A4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8007C2A8: bne         $at, $zero, L_8007C2B8
    if (ctx->r1 != 0) {
        // 0x8007C2AC: sh          $t6, 0x14($s2)
        MEM_H(0X14, ctx->r18) = ctx->r14;
            goto L_8007C2B8;
    }
    // 0x8007C2AC: sh          $t6, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r14;
    // 0x8007C2B0: b           L_8007C2C4
    // 0x8007C2B4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
        goto L_8007C2C4;
    // 0x8007C2B4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
L_8007C2B8:
    // 0x8007C2B8: bgtzl       $a3, L_8007C2C8
    if (SIGNED(ctx->r7) > 0) {
        // 0x8007C2BC: sra         $t7, $a3, 1
        ctx->r15 = S32(SIGNED(ctx->r7) >> 1);
            goto L_8007C2C8;
    }
    goto skip_21;
    // 0x8007C2BC: sra         $t7, $a3, 1
    ctx->r15 = S32(SIGNED(ctx->r7) >> 1);
    skip_21:
    // 0x8007C2C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8007C2C4:
    // 0x8007C2C4: sra         $t7, $a3, 1
    ctx->r15 = S32(SIGNED(ctx->r7) >> 1);
L_8007C2C8:
    // 0x8007C2C8: addiu       $t8, $t7, -0x30
    ctx->r24 = ADD32(ctx->r15, -0X30);
    // 0x8007C2CC: sb          $a3, 0x27($s2)
    MEM_B(0X27, ctx->r18) = ctx->r7;
    // 0x8007C2D0: sb          $a3, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r7;
    // 0x8007C2D4: sb          $t8, 0x24($s2)
    MEM_B(0X24, ctx->r18) = ctx->r24;
    // 0x8007C2D8: lh          $s0, 0x2($s1)
    ctx->r16 = S32(MEM_H(ctx->r17, 0X2));
    // 0x8007C2DC: blez        $s0, L_8007D270
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007C2E0: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007D270;
    }
    // 0x8007C2E0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
L_8007C2E4:
    // 0x8007C2E4: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C2E8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8007C2EC: jal         0x80076190
    // 0x8007C2F0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    ssp(rdram, ctx);
        goto after_3;
    // 0x8007C2F0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_3:
    // 0x8007C2F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8007C2F8: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x8007C2FC: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8007C300: bgtzl       $s0, L_8007C2E4
    if (SIGNED(ctx->r16) > 0) {
        // 0x8007C304: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007C2E4;
    }
    goto skip_22;
    // 0x8007C304: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    skip_22:
    // 0x8007C308: b           L_8007D274
    // 0x8007C30C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C30C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007C310:
    // 0x8007C310: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007C314: lw          $t0, 0x0($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007C318: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C31C: sll         $t3, $s5, 2
    ctx->r11 = S32(ctx->r21 << 2);
    // 0x8007C320: addiu       $v1, $t0, 0x1
    ctx->r3 = ADD32(ctx->r8, 0X1);
    // 0x8007C324: bne         $v1, $at, L_8007C390
    if (ctx->r3 != ctx->r1) {
        // 0x8007C328: sw          $v1, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r3;
            goto L_8007C390;
    }
    // 0x8007C328: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x8007C32C: subu        $t3, $t3, $s5
    ctx->r11 = SUB32(ctx->r11, ctx->r21);
    // 0x8007C330: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8007C334: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x8007C338: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8007C33C: lh          $v0, -0x1970($v0)
    ctx->r2 = S32(MEM_H(ctx->r2, -0X1970));
    // 0x8007C340: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007C344: lui         $t6, 0x802A
    ctx->r14 = S32(0X802A << 16);
    // 0x8007C348: beq         $v0, $at, L_8007C36C
    if (ctx->r2 == ctx->r1) {
        // 0x8007C34C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007C36C;
    }
    // 0x8007C34C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007C350: beq         $v0, $at, L_8007C36C
    if (ctx->r2 == ctx->r1) {
        // 0x8007C354: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007C36C;
    }
    // 0x8007C354: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C358: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C35C: jal         0x80092728
    // 0x8007C360: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    deletesprite(rdram, ctx);
        goto after_4;
    // 0x8007C360: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_4:
    // 0x8007C364: b           L_8007D274
    // 0x8007C368: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C368: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007C36C:
    // 0x8007C36C: lw          $t6, 0xC4C($t6)
    ctx->r14 = S32(MEM_W(ctx->r14, 0XC4C));
    // 0x8007C370: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8007C374: bnel        $t6, $zero, L_8007C394
    if (ctx->r14 != 0) {
        // 0x8007C378: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8007C394;
    }
    goto skip_23;
    // 0x8007C378: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_23:
    // 0x8007C37C: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x8007C380: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007C384: jal         0x80059034
    // 0x8007C388: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    spritesound(rdram, ctx);
        goto after_5;
    // 0x8007C388: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_5:
    // 0x8007C38C: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
L_8007C390:
    // 0x8007C390: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8007C394:
    // 0x8007C394: bne         $v1, $at, L_8007C3AC
    if (ctx->r3 != ctx->r1) {
        // 0x8007C398: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007C3AC;
    }
    // 0x8007C398: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C39C: lw          $t8, 0x4($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007C3A0: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8007C3A4: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8007C3A8: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
L_8007C3AC:
    // 0x8007C3AC: lw          $t9, 0x4($s1)
    ctx->r25 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007C3B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007C3B4: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C3B8: bnel        $t9, $at, L_8007D274
    if (ctx->r25 != ctx->r1) {
        // 0x8007C3BC: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_24;
    // 0x8007C3BC: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_24:
    // 0x8007C3C0: jal         0x80092728
    // 0x8007C3C4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    deletesprite(rdram, ctx);
        goto after_6;
    // 0x8007C3C4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_6:
    // 0x8007C3C8: b           L_8007D274
    // 0x8007C3CC: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C3CC: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    // 0x8007C3D0: lh          $t0, 0x16($s2)
    ctx->r8 = S32(MEM_H(ctx->r18, 0X16));
L_8007C3D4:
    // 0x8007C3D4: bltzl       $t0, L_8007D274
    if (SIGNED(ctx->r8) < 0) {
        // 0x8007C3D8: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_25;
    // 0x8007C3D8: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_25:
    // 0x8007C3DC: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007C3E0: lw          $t2, 0x0($s1)
    ctx->r10 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007C3E4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C3E8: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C3EC: addiu       $v1, $t2, 0x1
    ctx->r3 = ADD32(ctx->r10, 0X1);
    // 0x8007C3F0: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8007C3F4: bne         $at, $zero, L_8007C40C
    if (ctx->r1 != 0) {
        // 0x8007C3F8: sw          $v1, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r3;
            goto L_8007C40C;
    }
    // 0x8007C3F8: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x8007C3FC: jal         0x80092728
    // 0x8007C400: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    deletesprite(rdram, ctx);
        goto after_7;
    // 0x8007C400: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_7:
    // 0x8007C404: b           L_8007D274
    // 0x8007C408: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C408: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007C40C:
    // 0x8007C40C: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8007C410: bnel        $at, $zero, L_8007C42C
    if (ctx->r1 != 0) {
        // 0x8007C414: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_8007C42C;
    }
    goto skip_26;
    // 0x8007C414: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    skip_26:
    // 0x8007C418: lh          $t6, 0xC($s2)
    ctx->r14 = S32(MEM_H(ctx->r18, 0XC));
    // 0x8007C41C: ori         $t7, $t6, 0x202
    ctx->r15 = ctx->r14 | 0X202;
    // 0x8007C420: b           L_8007C440
    // 0x8007C424: sh          $t7, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r15;
        goto L_8007C440;
    // 0x8007C424: sh          $t7, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r15;
    // 0x8007C428: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_8007C42C:
    // 0x8007C42C: bnel        $at, $zero, L_8007C444
    if (ctx->r1 != 0) {
        // 0x8007C430: lh          $t9, 0x16($s2)
        ctx->r25 = S32(MEM_H(ctx->r18, 0X16));
            goto L_8007C444;
    }
    goto skip_27;
    // 0x8007C430: lh          $t9, 0x16($s2)
    ctx->r25 = S32(MEM_H(ctx->r18, 0X16));
    skip_27:
    // 0x8007C434: lh          $t8, 0xC($s2)
    ctx->r24 = S32(MEM_H(ctx->r18, 0XC));
    // 0x8007C438: ori         $t4, $t8, 0x2
    ctx->r12 = ctx->r24 | 0X2;
    // 0x8007C43C: sh          $t4, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r12;
L_8007C440:
    // 0x8007C440: lh          $t9, 0x16($s2)
    ctx->r25 = S32(MEM_H(ctx->r18, 0X16));
L_8007C444:
    // 0x8007C444: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007C448: mflo        $t1
    ctx->r9 = lo;
    // 0x8007C44C: addu        $v0, $s6, $t1
    ctx->r2 = ADD32(ctx->r22, ctx->r9);
    // 0x8007C450: lb          $t0, 0x29($v0)
    ctx->r8 = S32(MEM_B(ctx->r2, 0X29));
    // 0x8007C454: sb          $t0, 0x29($s2)
    MEM_B(0X29, ctx->r18) = ctx->r8;
    // 0x8007C458: lb          $t2, 0x2A($v0)
    ctx->r10 = S32(MEM_B(ctx->r2, 0X2A));
    // 0x8007C45C: b           L_8007D270
    // 0x8007C460: sb          $t2, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = ctx->r10;
        goto L_8007D270;
    // 0x8007C460: sb          $t2, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = ctx->r10;
L_8007C464:
    // 0x8007C464: jal         0x800ACF18
    // 0x8007C468: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    findplayer(rdram, ctx);
        goto after_8;
    // 0x8007C468: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_8:
    // 0x8007C46C: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
    // 0x8007C470: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x8007C474: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8007C478: slti        $at, $t3, 0x200
    ctx->r1 = SIGNED(ctx->r11) < 0X200 ? 1 : 0;
    // 0x8007C47C: beq         $at, $zero, L_8007C4DC
    if (ctx->r1 == 0) {
        // 0x8007C480: sll         $t7, $t6, 3
        ctx->r15 = S32(ctx->r14 << 3);
            goto L_8007C4DC;
    }
    // 0x8007C480: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8007C484: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007C488: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007C48C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007C490: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007C494: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007C498: lui         $t8, 0x802A
    ctx->r24 = S32(0X802A << 16);
    // 0x8007C49C: addiu       $t8, $t8, 0x5770
    ctx->r24 = ADD32(ctx->r24, 0X5770);
    // 0x8007C4A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007C4A4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8007C4A8: lh          $t1, 0x2E0($v1)
    ctx->r9 = S32(MEM_H(ctx->r3, 0X2E0));
    // 0x8007C4AC: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x8007C4B0: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8007C4B4: multu       $t1, $s7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007C4B8: sw          $t4, 0x274($v1)
    MEM_W(0X274, ctx->r3) = ctx->r12;
    // 0x8007C4BC: sb          $t9, 0x367($v1)
    MEM_B(0X367, ctx->r3) = ctx->r25;
    // 0x8007C4C0: sb          $zero, 0x368($v1)
    MEM_B(0X368, ctx->r3) = 0;
    // 0x8007C4C4: sb          $zero, 0x369($v1)
    MEM_B(0X369, ctx->r3) = 0;
    // 0x8007C4C8: mflo        $t0
    ctx->r8 = lo;
    // 0x8007C4CC: addu        $a0, $s6, $t0
    ctx->r4 = ADD32(ctx->r22, ctx->r8);
    // 0x8007C4D0: lh          $t2, 0x22($a0)
    ctx->r10 = S32(MEM_H(ctx->r4, 0X22));
    // 0x8007C4D4: addiu       $t3, $t2, -0x4
    ctx->r11 = ADD32(ctx->r10, -0X4);
    // 0x8007C4D8: sh          $t3, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r11;
L_8007C4DC:
    // 0x8007C4DC: lh          $t5, 0x22($s2)
    ctx->r13 = S32(MEM_H(ctx->r18, 0X22));
    // 0x8007C4E0: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x8007C4E4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C4E8: beq         $t5, $at, L_8007C500
    if (ctx->r13 == ctx->r1) {
        // 0x8007C4EC: sra         $t7, $a0, 16
        ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8007C500;
    }
    // 0x8007C4EC: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C4F0: addiu       $t6, $zero, 0x3E7
    ctx->r14 = ADD32(0, 0X3E7);
    // 0x8007C4F4: sh          $t6, 0x22($s2)
    MEM_H(0X22, ctx->r18) = ctx->r14;
    // 0x8007C4F8: b           L_8007D064
    // 0x8007C4FC: lh          $v1, 0xE($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0XE));
        goto L_8007D064;
    // 0x8007C4FC: lh          $v1, 0xE($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0XE));
L_8007C500:
    // 0x8007C500: jal         0x80092728
    // 0x8007C504: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    deletesprite(rdram, ctx);
        goto after_9;
    // 0x8007C504: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_9:
    // 0x8007C508: b           L_8007D274
    // 0x8007C50C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C50C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007C510:
    // 0x8007C510: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C514: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C518: jal         0x80092728
    // 0x8007C51C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    deletesprite(rdram, ctx);
        goto after_10;
    // 0x8007C51C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_10:
    // 0x8007C520: b           L_8007D274
    // 0x8007C524: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C524: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007C528:
    // 0x8007C528: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
L_8007C52C:
    // 0x8007C52C: jal         0x80098FB4
    // 0x8007C530: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    getflorzofslope(rdram, ctx);
        goto after_11;
    // 0x8007C530: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    after_11:
    // 0x8007C534: sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
    // 0x8007C538: sw          $v0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r2;
    // 0x8007C53C: b           L_8007D064
    // 0x8007C540: lh          $v1, 0xE($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0XE));
        goto L_8007D064;
    // 0x8007C540: lh          $v1, 0xE($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0XE));
L_8007C544:
    // 0x8007C544: jal         0x8009800C
    // 0x8007C548: nop

    krand2(rdram, ctx);
        goto after_12;
    // 0x8007C548: nop

    after_12:
    // 0x8007C54C: lw          $t4, 0x30($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X30));
    // 0x8007C550: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8007C554: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x8007C558: andi        $t9, $t4, 0x7FF
    ctx->r25 = ctx->r12 & 0X7FF;
    // 0x8007C55C: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8007C560: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x8007C564: lh          $t0, -0x9A0($t0)
    ctx->r8 = S32(MEM_H(ctx->r8, -0X9A0));
    // 0x8007C568: sra         $t2, $t0, 9
    ctx->r10 = S32(SIGNED(ctx->r8) >> 9);
    // 0x8007C56C: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8007C570: jal         0x8009800C
    // 0x8007C574: sh          $t5, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r13;
    krand2(rdram, ctx);
        goto after_13;
    // 0x8007C574: sh          $t5, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r13;
    after_13:
    // 0x8007C578: lw          $t6, 0x30($s4)
    ctx->r14 = S32(MEM_W(ctx->r20, 0X30));
    // 0x8007C57C: andi        $t7, $v0, 0x3F
    ctx->r15 = ctx->r2 & 0X3F;
    // 0x8007C580: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007C584: andi        $t4, $t8, 0x7FF
    ctx->r12 = ctx->r24 & 0X7FF;
    // 0x8007C588: slti        $at, $t4, 0x201
    ctx->r1 = SIGNED(ctx->r12) < 0X201 ? 1 : 0;
    // 0x8007C58C: bne         $at, $zero, L_8007C61C
    if (ctx->r1 != 0) {
        // 0x8007C590: sw          $t8, 0x30($s4)
        MEM_W(0X30, ctx->r20) = ctx->r24;
            goto L_8007C61C;
    }
    // 0x8007C590: sw          $t8, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->r24;
    // 0x8007C594: slti        $at, $t4, 0x63C
    ctx->r1 = SIGNED(ctx->r12) < 0X63C ? 1 : 0;
    // 0x8007C598: beq         $at, $zero, L_8007C61C
    if (ctx->r1 == 0) {
        // 0x8007C59C: sll         $t9, $s5, 2
        ctx->r25 = S32(ctx->r21 << 2);
            goto L_8007C61C;
    }
    // 0x8007C59C: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x8007C5A0: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x8007C5A4: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8007C5A8: lui         $t1, 0x8022
    ctx->r9 = S32(0X8022 << 16);
    // 0x8007C5AC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8007C5B0: lh          $t1, -0x1970($t1)
    ctx->r9 = S32(MEM_H(ctx->r9, -0X1970));
    // 0x8007C5B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007C5B8: bnel        $t1, $at, L_8007C5F4
    if (ctx->r9 != ctx->r1) {
        // 0x8007C5BC: lh          $t7, 0x1C($s2)
        ctx->r15 = S32(MEM_H(ctx->r18, 0X1C));
            goto L_8007C5F4;
    }
    goto skip_28;
    // 0x8007C5BC: lh          $t7, 0x1C($s2)
    ctx->r15 = S32(MEM_H(ctx->r18, 0X1C));
    skip_28:
    // 0x8007C5C0: lh          $t0, 0x1C($s2)
    ctx->r8 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007C5C4: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x8007C5C8: beql        $at, $zero, L_8007C620
    if (ctx->r1 == 0) {
        // 0x8007C5CC: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007C620;
    }
    goto skip_29;
    // 0x8007C5CC: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    skip_29:
    // 0x8007C5D0: jal         0x8009800C
    // 0x8007C5D4: nop

    krand2(rdram, ctx);
        goto after_14;
    // 0x8007C5D4: nop

    after_14:
    // 0x8007C5D8: lh          $t2, 0x1C($s2)
    ctx->r10 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007C5DC: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x8007C5E0: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8007C5E4: addiu       $t6, $t5, 0x5
    ctx->r14 = ADD32(ctx->r13, 0X5);
    // 0x8007C5E8: b           L_8007C61C
    // 0x8007C5EC: sh          $t6, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r14;
        goto L_8007C61C;
    // 0x8007C5EC: sh          $t6, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r14;
    // 0x8007C5F0: lh          $t7, 0x1C($s2)
    ctx->r15 = S32(MEM_H(ctx->r18, 0X1C));
L_8007C5F4:
    // 0x8007C5F4: slti        $at, $t7, 0x90
    ctx->r1 = SIGNED(ctx->r15) < 0X90 ? 1 : 0;
    // 0x8007C5F8: beql        $at, $zero, L_8007C620
    if (ctx->r1 == 0) {
        // 0x8007C5FC: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007C620;
    }
    goto skip_30;
    // 0x8007C5FC: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    skip_30:
    // 0x8007C600: jal         0x8009800C
    // 0x8007C604: nop

    krand2(rdram, ctx);
        goto after_15;
    // 0x8007C604: nop

    after_15:
    // 0x8007C608: lh          $t8, 0x1C($s2)
    ctx->r24 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007C60C: andi        $t4, $v0, 0x7
    ctx->r12 = ctx->r2 & 0X7;
    // 0x8007C610: addu        $t9, $t8, $t4
    ctx->r25 = ADD32(ctx->r24, ctx->r12);
    // 0x8007C614: addiu       $t1, $t9, 0x5
    ctx->r9 = ADD32(ctx->r25, 0X5);
    // 0x8007C618: sh          $t1, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r9;
L_8007C61C:
    // 0x8007C61C: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
L_8007C620:
    // 0x8007C620: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C624: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8007C628: jal         0x80076190
    // 0x8007C62C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    ssp(rdram, ctx);
        goto after_16;
    // 0x8007C62C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_16:
    // 0x8007C630: jal         0x8009800C
    // 0x8007C634: nop

    krand2(rdram, ctx);
        goto after_17;
    // 0x8007C634: nop

    after_17:
    // 0x8007C638: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x8007C63C: bne         $t2, $zero, L_8007C65C
    if (ctx->r10 != 0) {
        // 0x8007C640: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007C65C;
    }
    // 0x8007C640: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C644: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C648: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8007C64C: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007C650: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007C654: jal         0x8009219C
    // 0x8007C658: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    setsprite(rdram, ctx);
        goto after_18;
    // 0x8007C658: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    after_18:
L_8007C65C:
    // 0x8007C65C: lh          $a0, 0x10($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X10));
    // 0x8007C660: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007C664: bnel        $a0, $at, L_8007C688
    if (ctx->r4 != ctx->r1) {
        // 0x8007C668: lw          $a1, 0x0($s2)
        ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
            goto L_8007C688;
    }
    goto skip_31;
    // 0x8007C668: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    skip_31:
    // 0x8007C66C: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C670: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C674: jal         0x80092728
    // 0x8007C678: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    deletesprite(rdram, ctx);
        goto after_19;
    // 0x8007C678: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_19:
    // 0x8007C67C: b           L_8007D274
    // 0x8007C680: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C680: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    // 0x8007C684: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
L_8007C688:
    // 0x8007C688: jal         0x80098FB4
    // 0x8007C68C: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    getflorzofslope(rdram, ctx);
        goto after_20;
    // 0x8007C68C: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    after_20:
    // 0x8007C690: lw          $t6, 0x8($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X8));
    // 0x8007C694: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C698: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8007C69C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C6A0: beq         $at, $zero, L_8007C720
    if (ctx->r1 == 0) {
        // 0x8007C6A4: sra         $t7, $a0, 16
        ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8007C720;
    }
    // 0x8007C6A4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C6A8: sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
    // 0x8007C6AC: jal         0x80076244
    // 0x8007C6B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    insertspriteq(rdram, ctx);
        goto after_21;
    // 0x8007C6B0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_21:
    // 0x8007C6B4: lh          $t8, 0xE($s2)
    ctx->r24 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8007C6B8: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8007C6BC: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8007C6C0: sh          $t4, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r12;
    // 0x8007C6C4: lh          $s0, 0x2862($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X2862));
    // 0x8007C6C8: bltz        $s0, L_8007C720
    if (SIGNED(ctx->r16) < 0) {
        // 0x8007C6CC: nop
    
            goto L_8007C720;
    }
    // 0x8007C6CC: nop

L_8007C6D0:
    // 0x8007C6D0: multu       $s0, $s7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007C6D4: addiu       $at, $zero, 0x4CA
    ctx->r1 = ADD32(0, 0X4CA);
    // 0x8007C6D8: mflo        $t9
    ctx->r25 = lo;
    // 0x8007C6DC: addu        $a1, $s6, $t9
    ctx->r5 = ADD32(ctx->r22, ctx->r25);
    // 0x8007C6E0: lh          $t1, 0xE($a1)
    ctx->r9 = S32(MEM_H(ctx->r5, 0XE));
    // 0x8007C6E4: bnel        $t1, $at, L_8007C70C
    if (ctx->r9 != ctx->r1) {
        // 0x8007C6E8: sll         $t2, $s0, 1
        ctx->r10 = S32(ctx->r16 << 1);
            goto L_8007C70C;
    }
    goto skip_32;
    // 0x8007C6E8: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    skip_32:
    // 0x8007C6EC: jal         0x800ACE8C
    // 0x8007C6F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    ldist(rdram, ctx);
        goto after_22;
    // 0x8007C6F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_22:
    // 0x8007C6F4: slti        $at, $v0, 0x15C
    ctx->r1 = SIGNED(ctx->r2) < 0X15C ? 1 : 0;
    // 0x8007C6F8: beq         $at, $zero, L_8007C708
    if (ctx->r1 == 0) {
        // 0x8007C6FC: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8007C708;
    }
    // 0x8007C6FC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8007C700: b           L_8007C720
    // 0x8007C704: sb          $t0, 0x25($s2)
    MEM_B(0X25, ctx->r18) = ctx->r8;
        goto L_8007C720;
    // 0x8007C704: sb          $t0, 0x25($s2)
    MEM_B(0X25, ctx->r18) = ctx->r8;
L_8007C708:
    // 0x8007C708: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
L_8007C70C:
    // 0x8007C70C: lui         $s0, 0x8027
    ctx->r16 = S32(0X8027 << 16);
    // 0x8007C710: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x8007C714: lh          $s0, 0x5F40($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, 0X5F40));
    // 0x8007C718: bgez        $s0, L_8007C6D0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8007C71C: nop
    
            goto L_8007C6D0;
    }
    // 0x8007C71C: nop

L_8007C720:
    // 0x8007C720: b           L_8007D064
    // 0x8007C724: lh          $v1, 0xE($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0XE));
        goto L_8007D064;
    // 0x8007C724: lh          $v1, 0xE($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0XE));
L_8007C728:
    // 0x8007C728: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
L_8007C72C:
    // 0x8007C72C: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007C730: blez        $v0, L_8007C740
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007C734: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8007C740;
    }
    // 0x8007C734: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8007C738: b           L_8007C744
    // 0x8007C73C: sh          $t3, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r11;
        goto L_8007C744;
    // 0x8007C73C: sh          $t3, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r11;
L_8007C740:
    // 0x8007C740: sh          $zero, 0x18($s2)
    MEM_H(0X18, ctx->r18) = 0;
L_8007C744:
    // 0x8007C744: lw          $v0, 0x14($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X14));
    // 0x8007C748: slti        $at, $v0, 0xBB8
    ctx->r1 = SIGNED(ctx->r2) < 0XBB8 ? 1 : 0;
    // 0x8007C74C: beq         $at, $zero, L_8007C758
    if (ctx->r1 == 0) {
        // 0x8007C750: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_8007C758;
    }
    // 0x8007C750: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8007C754: sw          $t5, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r13;
L_8007C758:
    // 0x8007C758: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007C75C: slti        $at, $v1, 0x401
    ctx->r1 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
    // 0x8007C760: bne         $at, $zero, L_8007C78C
    if (ctx->r1 != 0) {
        // 0x8007C764: slti        $at, $v1, 0x500
        ctx->r1 = SIGNED(ctx->r3) < 0X500 ? 1 : 0;
            goto L_8007C78C;
    }
    // 0x8007C764: slti        $at, $v1, 0x500
    ctx->r1 = SIGNED(ctx->r3) < 0X500 ? 1 : 0;
    // 0x8007C768: beq         $at, $zero, L_8007C78C
    if (ctx->r1 == 0) {
        // 0x8007C76C: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007C78C;
    }
    // 0x8007C76C: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C770: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C774: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8007C778: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007C77C: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007C780: jal         0x8009219C
    // 0x8007C784: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    setsprite(rdram, ctx);
        goto after_23;
    // 0x8007C784: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    after_23:
    // 0x8007C788: lh          $s5, 0x10($s2)
    ctx->r21 = S32(MEM_H(ctx->r18, 0X10));
L_8007C78C:
    // 0x8007C78C: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x8007C790: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C794: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8007C798: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007C79C: jal         0x80098FB4
    // 0x8007C7A0: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    getflorzofslope(rdram, ctx);
        goto after_24;
    // 0x8007C7A0: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    after_24:
    // 0x8007C7A4: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x8007C7A8: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C7AC: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007C7B0: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007C7B4: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8007C7B8: jal         0x80098E64
    // 0x8007C7BC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    getceilzofslope(rdram, ctx);
        goto after_25;
    // 0x8007C7BC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_25:
    // 0x8007C7C0: lw          $a3, 0x68($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X68));
    // 0x8007C7C4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C7C8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8007C7CC: beq         $v0, $a3, L_8007C7E4
    if (ctx->r2 == ctx->r7) {
        // 0x8007C7D0: sra         $t4, $a0, 16
        ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8007C7E4;
    }
    // 0x8007C7D0: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C7D4: bltz        $s5, L_8007C7E4
    if (SIGNED(ctx->r21) < 0) {
        // 0x8007C7D8: slti        $at, $s5, 0x291
        ctx->r1 = SIGNED(ctx->r21) < 0X291 ? 1 : 0;
            goto L_8007C7E4;
    }
    // 0x8007C7D8: slti        $at, $s5, 0x291
    ctx->r1 = SIGNED(ctx->r21) < 0X291 ? 1 : 0;
    // 0x8007C7DC: bnel        $at, $zero, L_8007C7F8
    if (ctx->r1 != 0) {
        // 0x8007C7E0: lw          $t9, 0x8($s2)
        ctx->r25 = S32(MEM_W(ctx->r18, 0X8));
            goto L_8007C7F8;
    }
    goto skip_33;
    // 0x8007C7E0: lw          $t9, 0x8($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X8));
    skip_33:
L_8007C7E4:
    // 0x8007C7E4: jal         0x80092728
    // 0x8007C7E8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    deletesprite(rdram, ctx);
        goto after_26;
    // 0x8007C7E8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_26:
    // 0x8007C7EC: b           L_8007D274
    // 0x8007C7F0: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C7F0: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    // 0x8007C7F4: lw          $t9, 0x8($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X8));
L_8007C7F8:
    // 0x8007C7F8: addiu       $t1, $a3, -0x200
    ctx->r9 = ADD32(ctx->r7, -0X200);
    // 0x8007C7FC: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8007C800: beql        $at, $zero, L_8007C978
    if (ctx->r1 == 0) {
        // 0x8007C804: lw          $v1, 0x8($s1)
        ctx->r3 = S32(MEM_W(ctx->r17, 0X8));
            goto L_8007C978;
    }
    goto skip_34;
    // 0x8007C804: lw          $v1, 0x8($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X8));
    skip_34:
    // 0x8007C808: lw          $v0, 0x4($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007C80C: sll         $t2, $s5, 2
    ctx->r10 = S32(ctx->r21 << 2);
    // 0x8007C810: subu        $t2, $t2, $s5
    ctx->r10 = SUB32(ctx->r10, ctx->r21);
    // 0x8007C814: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8007C818: beq         $at, $zero, L_8007C82C
    if (ctx->r1 == 0) {
        // 0x8007C81C: sll         $t2, $t2, 4
        ctx->r10 = S32(ctx->r10 << 4);
            goto L_8007C82C;
    }
    // 0x8007C81C: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8007C820: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x8007C824: b           L_8007C8A4
    // 0x8007C828: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
        goto L_8007C8A4;
    // 0x8007C828: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
L_8007C82C:
    // 0x8007C82C: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x8007C830: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007C834: lh          $t3, -0x1970($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X1970));
    // 0x8007C838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007C83C: beql        $t3, $at, L_8007C8A8
    if (ctx->r11 == ctx->r1) {
        // 0x8007C840: lh          $v1, 0x1C($s2)
        ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
            goto L_8007C8A8;
    }
    goto skip_35;
    // 0x8007C840: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
    skip_35:
    // 0x8007C844: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8007C848: lh          $v1, 0xE($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8007C84C: addiu       $at, $zero, 0x600
    ctx->r1 = ADD32(0, 0X600);
    // 0x8007C850: beq         $v1, $at, L_8007C868
    if (ctx->r3 == ctx->r1) {
        // 0x8007C854: addiu       $at, $zero, 0x5F0
        ctx->r1 = ADD32(0, 0X5F0);
            goto L_8007C868;
    }
    // 0x8007C854: addiu       $at, $zero, 0x5F0
    ctx->r1 = ADD32(0, 0X5F0);
    // 0x8007C858: beq         $v1, $at, L_8007C868
    if (ctx->r3 == ctx->r1) {
        // 0x8007C85C: addiu       $at, $zero, 0x5F8
        ctx->r1 = ADD32(0, 0X5F8);
            goto L_8007C868;
    }
    // 0x8007C85C: addiu       $at, $zero, 0x5F8
    ctx->r1 = ADD32(0, 0X5F8);
    // 0x8007C860: bnel        $v1, $at, L_8007C88C
    if (ctx->r3 != ctx->r1) {
        // 0x8007C864: lw          $v1, 0x0($s1)
        ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
            goto L_8007C88C;
    }
    goto skip_36;
    // 0x8007C864: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    skip_36:
L_8007C868:
    // 0x8007C868: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007C86C: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8007C870: bne         $at, $zero, L_8007C880
    if (ctx->r1 != 0) {
        // 0x8007C874: addiu       $t5, $v1, 0x1
        ctx->r13 = ADD32(ctx->r3, 0X1);
            goto L_8007C880;
    }
    // 0x8007C874: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8007C878: b           L_8007C8A4
    // 0x8007C87C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_8007C8A4;
    // 0x8007C87C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8007C880:
    // 0x8007C880: b           L_8007C8A4
    // 0x8007C884: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_8007C8A4;
    // 0x8007C884: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8007C888: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
L_8007C88C:
    // 0x8007C88C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8007C890: bne         $at, $zero, L_8007C8A0
    if (ctx->r1 != 0) {
        // 0x8007C894: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8007C8A0;
    }
    // 0x8007C894: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8007C898: b           L_8007C8A4
    // 0x8007C89C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_8007C8A4;
    // 0x8007C89C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8007C8A0:
    // 0x8007C8A0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_8007C8A4:
    // 0x8007C8A4: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
L_8007C8A8:
    // 0x8007C8A8: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8007C8AC: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x8007C8B0: slti        $at, $v1, 0x1800
    ctx->r1 = SIGNED(ctx->r3) < 0X1800 ? 1 : 0;
    // 0x8007C8B4: beq         $at, $zero, L_8007C900
    if (ctx->r1 == 0) {
        // 0x8007C8B8: sll         $t7, $t7, 4
        ctx->r15 = S32(ctx->r15 << 4);
            goto L_8007C900;
    }
    // 0x8007C8B8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8007C8BC: lui         $t8, 0x8022
    ctx->r24 = S32(0X8022 << 16);
    // 0x8007C8C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8007C8C4: lh          $t8, -0x1970($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X1970));
    // 0x8007C8C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007C8CC: addiu       $t1, $v1, 0x7E
    ctx->r9 = ADD32(ctx->r3, 0X7E);
    // 0x8007C8D0: bne         $t8, $at, L_8007C8F8
    if (ctx->r24 != ctx->r1) {
        // 0x8007C8D4: slti        $at, $v1, 0x400
        ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
            goto L_8007C8F8;
    }
    // 0x8007C8D4: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x8007C8D8: beq         $at, $zero, L_8007C8EC
    if (ctx->r1 == 0) {
        // 0x8007C8DC: addiu       $t9, $zero, 0x400
        ctx->r25 = ADD32(0, 0X400);
            goto L_8007C8EC;
    }
    // 0x8007C8DC: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8007C8E0: addiu       $t4, $v1, 0x30
    ctx->r12 = ADD32(ctx->r3, 0X30);
    // 0x8007C8E4: b           L_8007C8F0
    // 0x8007C8E8: sh          $t4, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r12;
        goto L_8007C8F0;
    // 0x8007C8E8: sh          $t4, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r12;
L_8007C8EC:
    // 0x8007C8EC: sh          $t9, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r25;
L_8007C8F0:
    // 0x8007C8F0: b           L_8007C900
    // 0x8007C8F4: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
        goto L_8007C900;
    // 0x8007C8F4: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
L_8007C8F8:
    // 0x8007C8F8: sh          $t1, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r9;
    // 0x8007C8FC: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
L_8007C900:
    // 0x8007C900: lh          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X14));
    // 0x8007C904: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8007C908: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    // 0x8007C90C: addiu       $t2, $a0, 0x200
    ctx->r10 = ADD32(ctx->r4, 0X200);
    // 0x8007C910: andi        $t3, $t2, 0x7FF
    ctx->r11 = ctx->r10 & 0X7FF;
    // 0x8007C914: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8007C918: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8007C91C: lh          $t6, -0x9A0($t6)
    ctx->r14 = S32(MEM_H(ctx->r14, -0X9A0));
    // 0x8007C920: lw          $t0, 0x0($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007C924: andi        $t1, $a0, 0x7FF
    ctx->r9 = ctx->r4 & 0X7FF;
    // 0x8007C928: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007C92C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8007C930: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8007C934: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007C938: lw          $t9, 0x4($s2)
    ctx->r25 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007C93C: mflo        $t7
    ctx->r15 = lo;
    // 0x8007C940: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x8007C944: addu        $t4, $t0, $t8
    ctx->r12 = ADD32(ctx->r8, ctx->r24);
    // 0x8007C948: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8007C94C: lh          $t3, -0x9A0($t3)
    ctx->r11 = S32(MEM_H(ctx->r11, -0X9A0));
    // 0x8007C950: lw          $t0, 0x8($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X8));
    // 0x8007C954: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007C958: addu        $t8, $t0, $v1
    ctx->r24 = ADD32(ctx->r8, ctx->r3);
    // 0x8007C95C: sw          $t8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r24;
    // 0x8007C960: mflo        $t5
    ctx->r13 = lo;
    // 0x8007C964: sra         $t6, $t5, 14
    ctx->r14 = S32(SIGNED(ctx->r13) >> 14);
    // 0x8007C968: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8007C96C: b           L_8007D270
    // 0x8007C970: sw          $t7, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r15;
        goto L_8007D270;
    // 0x8007C970: sw          $t7, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r15;
    // 0x8007C974: lw          $v1, 0x8($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X8));
L_8007C978:
    // 0x8007C978: bnel        $v1, $zero, L_8007C9E8
    if (ctx->r3 != 0) {
        // 0x8007C97C: lh          $a0, 0x10($s2)
        ctx->r4 = S32(MEM_H(ctx->r18, 0X10));
            goto L_8007C9E8;
    }
    goto skip_37;
    // 0x8007C97C: lh          $a0, 0x10($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X10));
    skip_37:
    // 0x8007C980: lh          $a0, 0x10($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X10));
    // 0x8007C984: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007C988: lui         $t2, 0x8022
    ctx->r10 = S32(0X8022 << 16);
    // 0x8007C98C: bne         $a0, $at, L_8007C9AC
    if (ctx->r4 != ctx->r1) {
        // 0x8007C990: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8007C9AC;
    }
    // 0x8007C990: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8007C994: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C998: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C99C: jal         0x80092728
    // 0x8007C9A0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    deletesprite(rdram, ctx);
        goto after_27;
    // 0x8007C9A0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_27:
    // 0x8007C9A4: b           L_8007D274
    // 0x8007C9A8: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C9A8: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007C9AC:
    // 0x8007C9AC: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8007C9B0: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8007C9B4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8007C9B8: lh          $t2, -0x197A($t2)
    ctx->r10 = S32(MEM_H(ctx->r10, -0X197A));
    // 0x8007C9BC: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007C9C0: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007C9C4: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x8007C9C8: beq         $t3, $zero, L_8007C9E0
    if (ctx->r11 == 0) {
        // 0x8007C9CC: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8007C9E0;
    }
    // 0x8007C9CC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8007C9D0: jal         0x80092728
    // 0x8007C9D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    deletesprite(rdram, ctx);
        goto after_28;
    // 0x8007C9D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_28:
    // 0x8007C9D8: b           L_8007D274
    // 0x8007C9DC: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007C9DC: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007C9E0:
    // 0x8007C9E0: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x8007C9E4: lh          $a0, 0x10($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X10));
L_8007C9E8:
    // 0x8007C9E8: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007C9EC: jal         0x80098FB4
    // 0x8007C9F0: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    getflorzofslope(rdram, ctx);
        goto after_29;
    // 0x8007C9F0: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    after_29:
    // 0x8007C9F4: lh          $t7, 0xE($s2)
    ctx->r15 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8007C9F8: addiu       $t6, $v0, -0x200
    ctx->r14 = ADD32(ctx->r2, -0X200);
    // 0x8007C9FC: addiu       $at, $zero, 0x8EE
    ctx->r1 = ADD32(0, 0X8EE);
    // 0x8007CA00: sw          $t6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r14;
    // 0x8007CA04: bne         $t7, $at, L_8007CA60
    if (ctx->r15 != ctx->r1) {
        // 0x8007CA08: sh          $zero, 0x18($s2)
        MEM_H(0X18, ctx->r18) = 0;
            goto L_8007CA60;
    }
    // 0x8007CA08: sh          $zero, 0x18($s2)
    MEM_H(0X18, ctx->r18) = 0;
    // 0x8007CA0C: lw          $t0, 0x4($s1)
    ctx->r8 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007CA10: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CA14: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CA18: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8007CA1C: andi        $t4, $t8, 0x3
    ctx->r12 = ctx->r24 & 0X3;
    // 0x8007CA20: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x8007CA24: bne         $t4, $zero, L_8007CA44
    if (ctx->r12 != 0) {
        // 0x8007CA28: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8007CA44;
    }
    // 0x8007CA28: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007CA2C: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007CA30: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8007CA34: beq         $at, $zero, L_8007CA44
    if (ctx->r1 == 0) {
        // 0x8007CA38: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_8007CA44;
    }
    // 0x8007CA38: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x8007CA3C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8007CA40: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8007CA44:
    // 0x8007CA44: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8007CA48: bnel        $at, $zero, L_8007D274
    if (ctx->r1 != 0) {
        // 0x8007CA4C: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_38;
    // 0x8007CA4C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_38:
    // 0x8007CA50: jal         0x80092728
    // 0x8007CA54: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    deletesprite(rdram, ctx);
        goto after_30;
    // 0x8007CA54: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_30:
    // 0x8007CA58: b           L_8007D274
    // 0x8007CA5C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007CA5C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007CA60:
    // 0x8007CA60: addiu       $t3, $zero, 0x8EE
    ctx->r11 = ADD32(0, 0X8EE);
    // 0x8007CA64: sh          $t3, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r11;
    // 0x8007CA68: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8007CA6C: b           L_8007D270
    // 0x8007CA70: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_8007D270;
    // 0x8007CA70: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8007CA74:
    // 0x8007CA74: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007CA78: lw          $t5, 0x0($s1)
    ctx->r13 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007CA7C: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8007CA80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007CA84: bne         $t5, $zero, L_8007CAD4
    if (ctx->r13 != 0) {
        // 0x8007CA88: subu        $t6, $t6, $s5
        ctx->r14 = SUB32(ctx->r14, ctx->r21);
            goto L_8007CAD4;
    }
    // 0x8007CA88: subu        $t6, $t6, $s5
    ctx->r14 = SUB32(ctx->r14, ctx->r21);
    // 0x8007CA8C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8007CA90: lui         $t7, 0x8022
    ctx->r15 = S32(0X8022 << 16);
    // 0x8007CA94: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8007CA98: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8007CA9C: lh          $t7, -0x197A($t7)
    ctx->r15 = S32(MEM_H(ctx->r15, -0X197A));
    // 0x8007CAA0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CAA4: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CAA8: andi        $t0, $t7, 0x2
    ctx->r8 = ctx->r15 & 0X2;
    // 0x8007CAAC: beq         $t0, $zero, L_8007CACC
    if (ctx->r8 == 0) {
        // 0x8007CAB0: nop
    
            goto L_8007CACC;
    }
    // 0x8007CAB0: nop

    // 0x8007CAB4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CAB8: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CABC: jal         0x80092728
    // 0x8007CAC0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    deletesprite(rdram, ctx);
        goto after_31;
    // 0x8007CAC0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_31:
    // 0x8007CAC4: b           L_8007D274
    // 0x8007CAC8: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007CAC8: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007CACC:
    // 0x8007CACC: jal         0x80076244
    // 0x8007CAD0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    insertspriteq(rdram, ctx);
        goto after_32;
    // 0x8007CAD0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_32:
L_8007CAD4:
    // 0x8007CAD4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CAD8: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CADC: jal         0x80089BF8
    // 0x8007CAE0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    makeitfall(rdram, ctx);
        goto after_33;
    // 0x8007CAE0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_33:
    // 0x8007CAE4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007CAE8: jal         0x800ACF18
    // 0x8007CAEC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    findplayer(rdram, ctx);
        goto after_34;
    // 0x8007CAEC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_34:
    // 0x8007CAF0: lw          $t3, 0x14($s4)
    ctx->r11 = S32(MEM_W(ctx->r20, 0X14));
    // 0x8007CAF4: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x8007CAF8: sra         $t2, $s3, 16
    ctx->r10 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8007CAFC: addiu       $t5, $t3, -0x100
    ctx->r13 = ADD32(ctx->r11, -0X100);
    // 0x8007CB00: sw          $t5, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r13;
    // 0x8007CB04: lw          $v1, 0x8($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X8));
    // 0x8007CB08: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
    // 0x8007CB0C: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8007CB10: beq         $at, $zero, L_8007CBC8
    if (ctx->r1 == 0) {
        // 0x8007CB14: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8007CBC8;
    }
    // 0x8007CB14: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8007CB18: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x8007CB1C: lh          $t6, 0x2($s4)
    ctx->r14 = S32(MEM_H(ctx->r20, 0X2));
    // 0x8007CB20: addiu       $at, $zero, 0x3DE
    ctx->r1 = ADD32(0, 0X3DE);
    // 0x8007CB24: bnel        $t6, $at, L_8007CB80
    if (ctx->r14 != ctx->r1) {
        // 0x8007CB28: lbu         $t9, 0x27($s2)
        ctx->r25 = MEM_BU(ctx->r18, 0X27);
            goto L_8007CB80;
    }
    goto skip_39;
    // 0x8007CB28: lbu         $t9, 0x27($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X27);
    skip_39:
    // 0x8007CB2C: lbu         $t7, 0x27($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X27);
    // 0x8007CB30: slti        $at, $t7, 0x40
    ctx->r1 = SIGNED(ctx->r15) < 0X40 ? 1 : 0;
    // 0x8007CB34: beql        $at, $zero, L_8007CBCC
    if (ctx->r1 == 0) {
        // 0x8007CB38: lw          $t3, 0x64($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
            goto L_8007CBCC;
    }
    goto skip_40;
    // 0x8007CB38: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
    skip_40:
    // 0x8007CB3C: lbu         $t0, 0x28($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X28);
    // 0x8007CB40: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x8007CB44: beql        $at, $zero, L_8007CBCC
    if (ctx->r1 == 0) {
        // 0x8007CB48: lw          $t3, 0x64($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
            goto L_8007CBCC;
    }
    goto skip_41;
    // 0x8007CB48: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
    skip_41:
    // 0x8007CB4C: jal         0x8009800C
    // 0x8007CB50: nop

    krand2(rdram, ctx);
        goto after_35;
    // 0x8007CB50: nop

    after_35:
    // 0x8007CB54: lbu         $t8, 0x27($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X27);
    // 0x8007CB58: andi        $t4, $v0, 0x3
    ctx->r12 = ctx->r2 & 0X3;
    // 0x8007CB5C: addu        $t1, $t8, $t4
    ctx->r9 = ADD32(ctx->r24, ctx->r12);
    // 0x8007CB60: jal         0x8009800C
    // 0x8007CB64: sb          $t1, 0x27($s2)
    MEM_B(0X27, ctx->r18) = ctx->r9;
    krand2(rdram, ctx);
        goto after_36;
    // 0x8007CB64: sb          $t1, 0x27($s2)
    MEM_B(0X27, ctx->r18) = ctx->r9;
    after_36:
    // 0x8007CB68: lbu         $t2, 0x28($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X28);
    // 0x8007CB6C: andi        $t3, $v0, 0x3
    ctx->r11 = ctx->r2 & 0X3;
    // 0x8007CB70: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8007CB74: b           L_8007CBC8
    // 0x8007CB78: sb          $t5, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r13;
        goto L_8007CBC8;
    // 0x8007CB78: sb          $t5, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r13;
    // 0x8007CB7C: lbu         $t9, 0x27($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X27);
L_8007CB80:
    // 0x8007CB80: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x8007CB84: beql        $at, $zero, L_8007CBCC
    if (ctx->r1 == 0) {
        // 0x8007CB88: lw          $t3, 0x64($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
            goto L_8007CBCC;
    }
    goto skip_42;
    // 0x8007CB88: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
    skip_42:
    // 0x8007CB8C: lbu         $t6, 0x28($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X28);
    // 0x8007CB90: slti        $at, $t6, 0x20
    ctx->r1 = SIGNED(ctx->r14) < 0X20 ? 1 : 0;
    // 0x8007CB94: beql        $at, $zero, L_8007CBCC
    if (ctx->r1 == 0) {
        // 0x8007CB98: lw          $t3, 0x64($sp)
        ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
            goto L_8007CBCC;
    }
    goto skip_43;
    // 0x8007CB98: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
    skip_43:
    // 0x8007CB9C: jal         0x8009800C
    // 0x8007CBA0: nop

    krand2(rdram, ctx);
        goto after_37;
    // 0x8007CBA0: nop

    after_37:
    // 0x8007CBA4: lbu         $t7, 0x27($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X27);
    // 0x8007CBA8: andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // 0x8007CBAC: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8007CBB0: jal         0x8009800C
    // 0x8007CBB4: sb          $t8, 0x27($s2)
    MEM_B(0X27, ctx->r18) = ctx->r24;
    krand2(rdram, ctx);
        goto after_38;
    // 0x8007CBB4: sb          $t8, 0x27($s2)
    MEM_B(0X27, ctx->r18) = ctx->r24;
    after_38:
    // 0x8007CBB8: lbu         $t4, 0x28($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X28);
    // 0x8007CBBC: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x8007CBC0: addu        $t2, $t4, $t1
    ctx->r10 = ADD32(ctx->r12, ctx->r9);
    // 0x8007CBC4: sb          $t2, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r10;
L_8007CBC8:
    // 0x8007CBC8: lw          $t3, 0x64($sp)
    ctx->r11 = S32(MEM_W(ctx->r29, 0X64));
L_8007CBCC:
    // 0x8007CBCC: slti        $at, $t3, 0x34C
    ctx->r1 = SIGNED(ctx->r11) < 0X34C ? 1 : 0;
    // 0x8007CBD0: beq         $at, $zero, L_8007CD8C
    if (ctx->r1 == 0) {
        // 0x8007CBD4: nop
    
            goto L_8007CD8C;
    }
    // 0x8007CBD4: nop

    // 0x8007CBD8: lbu         $t5, 0x27($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X27);
    // 0x8007CBDC: slti        $at, $t5, 0x7
    ctx->r1 = SIGNED(ctx->r13) < 0X7 ? 1 : 0;
    // 0x8007CBE0: bne         $at, $zero, L_8007CD8C
    if (ctx->r1 != 0) {
        // 0x8007CBE4: nop
    
            goto L_8007CD8C;
    }
    // 0x8007CBE4: nop

    // 0x8007CBE8: lbu         $t9, 0x28($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X28);
    // 0x8007CBEC: slti        $at, $t9, 0x7
    ctx->r1 = SIGNED(ctx->r25) < 0X7 ? 1 : 0;
    // 0x8007CBF0: bne         $at, $zero, L_8007CD8C
    if (ctx->r1 != 0) {
        // 0x8007CBF4: nop
    
            goto L_8007CD8C;
    }
    // 0x8007CBF4: nop

    // 0x8007CBF8: lbu         $t6, 0x25($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X25);
    // 0x8007CBFC: bnel        $t6, $zero, L_8007CCB8
    if (ctx->r14 != 0) {
        // 0x8007CC00: lw          $t8, 0x4($s1)
        ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
            goto L_8007CCB8;
    }
    goto skip_44;
    // 0x8007CC00: lw          $t8, 0x4($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
    skip_44:
    // 0x8007CC04: jal         0x8009800C
    // 0x8007CC08: nop

    krand2(rdram, ctx);
        goto after_39;
    // 0x8007CC08: nop

    after_39:
    // 0x8007CC0C: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x8007CC10: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x8007CC14: beql        $at, $zero, L_8007CCB8
    if (ctx->r1 == 0) {
        // 0x8007CC18: lw          $t8, 0x4($s1)
        ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
            goto L_8007CCB8;
    }
    goto skip_45;
    // 0x8007CC18: lw          $t8, 0x4($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
    skip_45:
    // 0x8007CC1C: lh          $t0, 0xE($s2)
    ctx->r8 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8007CC20: addiu       $at, $zero, 0x1125
    ctx->r1 = ADD32(0, 0X1125);
    // 0x8007CC24: sll         $t8, $s3, 3
    ctx->r24 = S32(ctx->r19 << 3);
    // 0x8007CC28: beq         $t0, $at, L_8007CCB4
    if (ctx->r8 == ctx->r1) {
        // 0x8007CC2C: subu        $t8, $t8, $s3
        ctx->r24 = SUB32(ctx->r24, ctx->r19);
            goto L_8007CCB4;
    }
    // 0x8007CC2C: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x8007CC30: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007CC34: addu        $t8, $t8, $s3
    ctx->r24 = ADD32(ctx->r24, ctx->r19);
    // 0x8007CC38: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007CC3C: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x8007CC40: lui         $t4, 0x802A
    ctx->r12 = S32(0X802A << 16);
    // 0x8007CC44: addiu       $t4, $t4, 0x5770
    ctx->r12 = ADD32(ctx->r12, 0X5770);
    // 0x8007CC48: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8007CC4C: addu        $s0, $t8, $t4
    ctx->r16 = ADD32(ctx->r24, ctx->r12);
    // 0x8007CC50: lh          $v0, 0x332($s0)
    ctx->r2 = S32(MEM_H(ctx->r16, 0X332));
    // 0x8007CC54: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x8007CC58: blez        $v0, L_8007CC68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007CC5C: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_8007CC68;
    }
    // 0x8007CC5C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8007CC60: b           L_8007CCB4
    // 0x8007CC64: sh          $t1, 0x332($s0)
    MEM_H(0X332, ctx->r16) = ctx->r9;
        goto L_8007CCB4;
    // 0x8007CC64: sh          $t1, 0x332($s0)
    MEM_H(0X332, ctx->r16) = ctx->r9;
L_8007CC68:
    // 0x8007CC68: lw          $t2, 0x158C($t2)
    ctx->r10 = S32(MEM_W(ctx->r10, 0X158C));
    // 0x8007CC6C: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // 0x8007CC70: bgtzl       $t2, L_8007CC84
    if (SIGNED(ctx->r10) > 0) {
        // 0x8007CC74: lh          $t3, 0x2E0($s0)
        ctx->r11 = S32(MEM_H(ctx->r16, 0X2E0));
            goto L_8007CC84;
    }
    goto skip_46;
    // 0x8007CC74: lh          $t3, 0x2E0($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2E0));
    skip_46:
    // 0x8007CC78: jal         0x80059034
    // 0x8007CC7C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_40;
    // 0x8007CC7C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_40:
    // 0x8007CC80: lh          $t3, 0x2E0($s0)
    ctx->r11 = S32(MEM_H(ctx->r16, 0X2E0));
L_8007CC84:
    // 0x8007CC84: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8007CC88: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8007CC8C: multu       $t3, $s7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007CC90: sw          $t7, 0x274($s0)
    MEM_W(0X274, ctx->r16) = ctx->r15;
    // 0x8007CC94: sb          $t0, 0x367($s0)
    MEM_B(0X367, ctx->r16) = ctx->r8;
    // 0x8007CC98: sb          $zero, 0x368($s0)
    MEM_B(0X368, ctx->r16) = 0;
    // 0x8007CC9C: sb          $zero, 0x369($s0)
    MEM_B(0X369, ctx->r16) = 0;
    // 0x8007CCA0: mflo        $t5
    ctx->r13 = lo;
    // 0x8007CCA4: addu        $v0, $s6, $t5
    ctx->r2 = ADD32(ctx->r22, ctx->r13);
    // 0x8007CCA8: lh          $t9, 0x22($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X22));
    // 0x8007CCAC: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8007CCB0: sh          $t6, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r14;
L_8007CCB4:
    // 0x8007CCB4: lw          $t8, 0x4($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X4));
L_8007CCB8:
    // 0x8007CCB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007CCBC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007CCC0: beq         $t8, $at, L_8007D270
    if (ctx->r24 == ctx->r1) {
        // 0x8007CCC4: sll         $t1, $s3, 3
        ctx->r9 = S32(ctx->r19 << 3);
            goto L_8007D270;
    }
    // 0x8007CCC4: sll         $t1, $s3, 3
    ctx->r9 = S32(ctx->r19 << 3);
    // 0x8007CCC8: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x8007CCCC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8007CCD0: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x8007CCD4: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
    // 0x8007CCD8: lh          $t3, 0x2($s4)
    ctx->r11 = S32(MEM_H(ctx->r20, 0X2));
    // 0x8007CCDC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007CCE0: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x8007CCE4: lui         $t2, 0x802A
    ctx->r10 = S32(0X802A << 16);
    // 0x8007CCE8: addiu       $t2, $t2, 0x5770
    ctx->r10 = ADD32(ctx->r10, 0X5770);
    // 0x8007CCEC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8007CCF0: addiu       $at, $zero, 0x3DE
    ctx->r1 = ADD32(0, 0X3DE);
    // 0x8007CCF4: bne         $t3, $at, L_8007CD08
    if (ctx->r11 != ctx->r1) {
        // 0x8007CCF8: addu        $s0, $t1, $t2
        ctx->r16 = ADD32(ctx->r9, ctx->r10);
            goto L_8007CD08;
    }
    // 0x8007CCF8: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x8007CCFC: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8007CD00: b           L_8007CD10
    // 0x8007CD04: sb          $t5, 0x33A($s0)
    MEM_B(0X33A, ctx->r16) = ctx->r13;
        goto L_8007CD10;
    // 0x8007CD04: sb          $t5, 0x33A($s0)
    MEM_B(0X33A, ctx->r16) = ctx->r13;
L_8007CD08:
    // 0x8007CD08: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8007CD0C: sb          $t9, 0x33A($s0)
    MEM_B(0X33A, ctx->r16) = ctx->r25;
L_8007CD10:
    // 0x8007CD10: lh          $t6, 0xE($s2)
    ctx->r14 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8007CD14: addiu       $at, $zero, 0x4CA
    ctx->r1 = ADD32(0, 0X4CA);
    // 0x8007CD18: bnel        $t6, $at, L_8007CD54
    if (ctx->r14 != ctx->r1) {
        // 0x8007CD1C: lbu         $t8, 0x25($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X25);
            goto L_8007CD54;
    }
    goto skip_47;
    // 0x8007CD1C: lbu         $t8, 0x25($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X25);
    skip_47:
    // 0x8007CD20: lbu         $t7, 0x27($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X27);
    // 0x8007CD24: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x8007CD28: bnel        $at, $zero, L_8007CD54
    if (ctx->r1 != 0) {
        // 0x8007CD2C: lbu         $t8, 0x25($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X25);
            goto L_8007CD54;
    }
    goto skip_48;
    // 0x8007CD2C: lbu         $t8, 0x25($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X25);
    skip_48:
    // 0x8007CD30: jal         0x8009800C
    // 0x8007CD34: nop

    krand2(rdram, ctx);
        goto after_41;
    // 0x8007CD34: nop

    after_41:
    // 0x8007CD38: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8007CD3C: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8007CD40: beq         $at, $zero, L_8007CD50
    if (ctx->r1 == 0) {
        // 0x8007CD44: addiu       $a0, $zero, 0x104
        ctx->r4 = ADD32(0, 0X104);
            goto L_8007CD50;
    }
    // 0x8007CD44: addiu       $a0, $zero, 0x104
    ctx->r4 = ADD32(0, 0X104);
    // 0x8007CD48: jal         0x80059034
    // 0x8007CD4C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    spritesound(rdram, ctx);
        goto after_42;
    // 0x8007CD4C: lh          $a1, 0x2E0($s0)
    ctx->r5 = S32(MEM_H(ctx->r16, 0X2E0));
    after_42:
L_8007CD50:
    // 0x8007CD50: lbu         $t8, 0x25($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X25);
L_8007CD54:
    // 0x8007CD54: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8007CD58: sb          $t8, 0x345($s0)
    MEM_B(0X345, ctx->r16) = ctx->r24;
    // 0x8007CD5C: lb          $t4, 0x24($s2)
    ctx->r12 = S32(MEM_B(ctx->r18, 0X24));
    // 0x8007CD60: sh          $t4, 0x330($s0)
    MEM_H(0X330, ctx->r16) = ctx->r12;
    // 0x8007CD64: lw          $t1, 0x8($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X8));
    // 0x8007CD68: bnel        $t1, $at, L_8007D274
    if (ctx->r9 != ctx->r1) {
        // 0x8007CD6C: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_49;
    // 0x8007CD6C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_49:
    // 0x8007CD70: lbu         $t2, 0x27($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X27);
    // 0x8007CD74: lbu         $t5, 0x28($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X28);
    // 0x8007CD78: addiu       $t3, $t2, -0x6
    ctx->r11 = ADD32(ctx->r10, -0X6);
    // 0x8007CD7C: addiu       $t9, $t5, -0x6
    ctx->r25 = ADD32(ctx->r13, -0X6);
    // 0x8007CD80: sb          $t3, 0x27($s2)
    MEM_B(0X27, ctx->r18) = ctx->r11;
    // 0x8007CD84: b           L_8007D270
    // 0x8007CD88: sb          $t9, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r25;
        goto L_8007D270;
    // 0x8007CD88: sb          $t9, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r25;
L_8007CD8C:
    // 0x8007CD8C: b           L_8007D270
    // 0x8007CD90: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
        goto L_8007D270;
    // 0x8007CD90: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
L_8007CD94:
    // 0x8007CD94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8007CD98:
    // 0x8007CD98: jal         0x800ACF18
    // 0x8007CD9C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    findplayer(rdram, ctx);
        goto after_43;
    // 0x8007CD9C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_43:
    // 0x8007CDA0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CDA4: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8007CDA8: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007CDAC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CDB0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8007CDB4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8007CDB8: jal         0x8008F488
    // 0x8007CDBC: lw          $a2, 0x64($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X64));
    execute(rdram, ctx);
        goto after_44;
    // 0x8007CDBC: lw          $a2, 0x64($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X64));
    after_44:
    // 0x8007CDC0: b           L_8007D274
    // 0x8007CDC4: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007CDC4: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007CDC8:
    // 0x8007CDC8: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
L_8007CDCC:
    // 0x8007CDCC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8007CDD0: jal         0x80076190
    // 0x8007CDD4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    ssp(rdram, ctx);
        goto after_45;
    // 0x8007CDD4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_45:
    // 0x8007CDD8: bltz        $s5, L_8007CE08
    if (SIGNED(ctx->r21) < 0) {
        // 0x8007CDDC: sll         $t8, $s5, 2
        ctx->r24 = S32(ctx->r21 << 2);
            goto L_8007CE08;
    }
    // 0x8007CDDC: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8007CDE0: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8007CDE4: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x8007CDE8: addiu       $t4, $t4, -0x1988
    ctx->r12 = ADD32(ctx->r12, -0X1988);
    // 0x8007CDEC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8007CDF0: addu        $v0, $t8, $t4
    ctx->r2 = ADD32(ctx->r24, ctx->r12);
    // 0x8007CDF4: lw          $t2, 0x4($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X4));
    // 0x8007CDF8: lw          $t1, 0x8($s2)
    ctx->r9 = S32(MEM_W(ctx->r18, 0X8));
    // 0x8007CDFC: addiu       $t3, $t2, 0x1800
    ctx->r11 = ADD32(ctx->r10, 0X1800);
    // 0x8007CE00: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8007CE04: beq         $at, $zero, L_8007CE20
    if (ctx->r1 == 0) {
        // 0x8007CE08: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007CE20;
    }
L_8007CE08:
    // 0x8007CE08: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CE0C: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CE10: jal         0x80092728
    // 0x8007CE14: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    deletesprite(rdram, ctx);
        goto after_46;
    // 0x8007CE14: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_46:
    // 0x8007CE18: b           L_8007D274
    // 0x8007CE1C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007CE1C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007CE20:
    // 0x8007CE20: lh          $t9, 0x18($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0X18));
    // 0x8007CE24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007CE28: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007CE2C: bnel        $t9, $at, L_8007CEA4
    if (ctx->r25 != ctx->r1) {
        // 0x8007CE30: lw          $t6, 0x4($s1)
        ctx->r14 = S32(MEM_W(ctx->r17, 0X4));
            goto L_8007CEA4;
    }
    goto skip_50;
    // 0x8007CE30: lw          $t6, 0x4($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X4));
    skip_50:
    // 0x8007CE34: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007CE38: lw          $t6, 0x4($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007CE3C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007CE40: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x8007CE44: bne         $at, $zero, L_8007CE64
    if (ctx->r1 != 0) {
        // 0x8007CE48: sw          $t7, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r15;
            goto L_8007CE64;
    }
    // 0x8007CE48: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x8007CE4C: lw          $t8, 0x0($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007CE50: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8007CE54: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8007CE58: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8007CE5C: andi        $t1, $t4, 0x3
    ctx->r9 = ctx->r12 & 0X3;
    // 0x8007CE60: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_8007CE64:
    // 0x8007CE64: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007CE68: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8007CE6C: beq         $at, $zero, L_8007CE80
    if (ctx->r1 == 0) {
        // 0x8007CE70: addiu       $t5, $v1, -0x40
        ctx->r13 = ADD32(ctx->r3, -0X40);
            goto L_8007CE80;
    }
    // 0x8007CE70: addiu       $t5, $v1, -0x40
    ctx->r13 = ADD32(ctx->r3, -0X40);
    // 0x8007CE74: addiu       $t3, $v1, 0xD
    ctx->r11 = ADD32(ctx->r3, 0XD);
    // 0x8007CE78: b           L_8007CE84
    // 0x8007CE7C: sh          $t3, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r11;
        goto L_8007CE84;
    // 0x8007CE7C: sh          $t3, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r11;
L_8007CE80:
    // 0x8007CE80: sh          $t5, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r13;
L_8007CE84:
    // 0x8007CE84: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    // 0x8007CE88: blez        $v0, L_8007CE98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007CE8C: addiu       $t9, $v0, -0x4
        ctx->r25 = ADD32(ctx->r2, -0X4);
            goto L_8007CE98;
    }
    // 0x8007CE8C: addiu       $t9, $v0, -0x4
    ctx->r25 = ADD32(ctx->r2, -0X4);
    // 0x8007CE90: b           L_8007D270
    // 0x8007CE94: sh          $t9, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r25;
        goto L_8007D270;
    // 0x8007CE94: sh          $t9, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r25;
L_8007CE98:
    // 0x8007CE98: b           L_8007D270
    // 0x8007CE9C: sh          $zero, 0x18($s2)
    MEM_H(0X18, ctx->r18) = 0;
        goto L_8007D270;
    // 0x8007CE9C: sh          $zero, 0x18($s2)
    MEM_H(0X18, ctx->r18) = 0;
    // 0x8007CEA0: lw          $t6, 0x4($s1)
    ctx->r14 = S32(MEM_W(ctx->r17, 0X4));
L_8007CEA4:
    // 0x8007CEA4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8007CEA8: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8007CEAC: bne         $at, $zero, L_8007CECC
    if (ctx->r1 != 0) {
        // 0x8007CEB0: sw          $t7, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r15;
            goto L_8007CECC;
    }
    // 0x8007CEB0: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x8007CEB4: lw          $t8, 0x0($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007CEB8: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8007CEBC: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8007CEC0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8007CEC4: andi        $t1, $t4, 0x3
    ctx->r9 = ctx->r12 & 0X3;
    // 0x8007CEC8: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_8007CECC:
    // 0x8007CECC: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007CED0: slti        $at, $v1, 0x200
    ctx->r1 = SIGNED(ctx->r3) < 0X200 ? 1 : 0;
    // 0x8007CED4: beq         $at, $zero, L_8007D270
    if (ctx->r1 == 0) {
        // 0x8007CED8: addiu       $t3, $v1, 0x3A
        ctx->r11 = ADD32(ctx->r3, 0X3A);
            goto L_8007D270;
    }
    // 0x8007CED8: addiu       $t3, $v1, 0x3A
    ctx->r11 = ADD32(ctx->r3, 0X3A);
    // 0x8007CEDC: b           L_8007D270
    // 0x8007CEE0: sh          $t3, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r11;
        goto L_8007D270;
    // 0x8007CEE0: sh          $t3, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r11;
L_8007CEE4:
    // 0x8007CEE4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CEE8: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CEEC: jal         0x80089BF8
    // 0x8007CEF0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    makeitfall(rdram, ctx);
        goto after_47;
    // 0x8007CEF0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_47:
    // 0x8007CEF4: lh          $t9, 0x1C($s2)
    ctx->r25 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007CEF8: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CEFC: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x8007CF00: slti        $at, $t9, 0x1001
    ctx->r1 = SIGNED(ctx->r25) < 0X1001 ? 1 : 0;
    // 0x8007CF04: bne         $at, $zero, L_8007CF10
    if (ctx->r1 != 0) {
        // 0x8007CF08: sra         $t7, $a0, 16
        ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8007CF10;
    }
    // 0x8007CF08: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CF0C: sh          $t6, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r14;
L_8007CF10:
    // 0x8007CF10: bgezl       $s5, L_8007CF2C
    if (SIGNED(ctx->r21) >= 0) {
        // 0x8007CF14: lw          $t0, 0x8($s2)
        ctx->r8 = S32(MEM_W(ctx->r18, 0X8));
            goto L_8007CF2C;
    }
    goto skip_51;
    // 0x8007CF14: lw          $t0, 0x8($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X8));
    skip_51:
    // 0x8007CF18: jal         0x80092728
    // 0x8007CF1C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    deletesprite(rdram, ctx);
        goto after_48;
    // 0x8007CF1C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_48:
    // 0x8007CF20: b           L_8007D274
    // 0x8007CF24: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007CF24: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    // 0x8007CF28: lw          $t0, 0x8($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X8));
L_8007CF2C:
    // 0x8007CF2C: lw          $t4, 0x14($s4)
    ctx->r12 = S32(MEM_W(ctx->r20, 0X14));
    // 0x8007CF30: addiu       $t8, $t0, 0x100
    ctx->r24 = ADD32(ctx->r8, 0X100);
    // 0x8007CF34: bnel        $t8, $t4, L_8007D000
    if (ctx->r24 != ctx->r12) {
        // 0x8007CF38: lw          $t2, 0x30($s4)
        ctx->r10 = S32(MEM_W(ctx->r20, 0X30));
            goto L_8007D000;
    }
    goto skip_52;
    // 0x8007CF38: lw          $t2, 0x30($s4)
    ctx->r10 = S32(MEM_W(ctx->r20, 0X30));
    skip_52:
    // 0x8007CF3C: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007CF40: lw          $t2, 0x0($s1)
    ctx->r10 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007CF44: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8007CF48: beql        $at, $zero, L_8007D000
    if (ctx->r1 == 0) {
        // 0x8007CF4C: lw          $t2, 0x30($s4)
        ctx->r10 = S32(MEM_W(ctx->r20, 0X30));
            goto L_8007D000;
    }
    goto skip_53;
    // 0x8007CF4C: lw          $t2, 0x30($s4)
    ctx->r10 = S32(MEM_W(ctx->r20, 0X30));
    skip_53:
    // 0x8007CF50: jal         0x8009800C
    // 0x8007CF54: nop

    krand2(rdram, ctx);
        goto after_49;
    // 0x8007CF54: nop

    after_49:
    // 0x8007CF58: lw          $t1, 0x0($s1)
    ctx->r9 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007CF5C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8007CF60: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8007CF64: subu        $t5, $t3, $t1
    ctx->r13 = SUB32(ctx->r11, ctx->r9);
    // 0x8007CF68: sll         $t9, $t5, 8
    ctx->r25 = S32(ctx->r13 << 8);
    // 0x8007CF6C: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8007CF70: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x8007CF74: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8007CF78: subu        $t0, $t6, $t7
    ctx->r8 = SUB32(ctx->r14, ctx->r15);
    // 0x8007CF7C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8007CF80: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x8007CF84: sh          $t0, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r8;
    // 0x8007CF88: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x8007CF8C: lh          $t4, -0x1970($t4)
    ctx->r12 = S32(MEM_H(ctx->r12, -0X1970));
    // 0x8007CF90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007CF94: bnel        $t4, $at, L_8007CFAC
    if (ctx->r12 != ctx->r1) {
        // 0x8007CF98: lbu         $t1, 0x27($s2)
        ctx->r9 = MEM_BU(ctx->r18, 0X27);
            goto L_8007CFAC;
    }
    goto skip_54;
    // 0x8007CF98: lbu         $t1, 0x27($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X27);
    skip_54:
    // 0x8007CF9C: lh          $t2, 0x1C($s2)
    ctx->r10 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007CFA0: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8007CFA4: sh          $t3, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r11;
    // 0x8007CFA8: lbu         $t1, 0x27($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X27);
L_8007CFAC:
    // 0x8007CFAC: lbu         $t9, 0x28($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X28);
    // 0x8007CFB0: srl         $t5, $t1, 1
    ctx->r13 = S32(U32(ctx->r9) >> 1);
    // 0x8007CFB4: srl         $t6, $t9, 1
    ctx->r14 = S32(U32(ctx->r25) >> 1);
    // 0x8007CFB8: sb          $t5, 0x27($s2)
    MEM_B(0X27, ctx->r18) = ctx->r13;
    // 0x8007CFBC: jal         0x8009800C
    // 0x8007CFC0: sb          $t6, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r14;
    krand2(rdram, ctx);
        goto after_50;
    // 0x8007CFC0: sb          $t6, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r14;
    after_50:
    // 0x8007CFC4: sra         $t7, $v0, 8
    ctx->r15 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8007CFC8: slti        $at, $t7, 0x9F
    ctx->r1 = SIGNED(ctx->r15) < 0X9F ? 1 : 0;
    // 0x8007CFCC: bne         $at, $zero, L_8007CFEC
    if (ctx->r1 != 0) {
        // 0x8007CFD0: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007CFEC;
    }
    // 0x8007CFD0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007CFD4: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007CFD8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8007CFDC: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007CFE0: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007CFE4: jal         0x8009219C
    // 0x8007CFE8: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    setsprite(rdram, ctx);
        goto after_51;
    // 0x8007CFE8: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    after_51:
L_8007CFEC:
    // 0x8007CFEC: lw          $t8, 0x0($s1)
    ctx->r24 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007CFF0: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8007CFF4: b           L_8007D020
    // 0x8007CFF8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
        goto L_8007D020;
    // 0x8007CFF8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8007CFFC: lw          $t2, 0x30($s4)
    ctx->r10 = S32(MEM_W(ctx->r20, 0X30));
L_8007D000:
    // 0x8007D000: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007D004: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007D008: bne         $t2, $at, L_8007D020
    if (ctx->r10 != ctx->r1) {
        // 0x8007D00C: sra         $t3, $a0, 16
        ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
            goto L_8007D020;
    }
    // 0x8007D00C: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007D010: jal         0x80092728
    // 0x8007D014: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    deletesprite(rdram, ctx);
        goto after_52;
    // 0x8007D014: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_52:
    // 0x8007D018: b           L_8007D274
    // 0x8007D01C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007D01C: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007D020:
    // 0x8007D020: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    // 0x8007D024: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007D028: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007D02C: blez        $v0, L_8007D050
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007D030: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8007D050;
    }
    // 0x8007D030: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8007D034: addiu       $t1, $v0, -0x2
    ctx->r9 = ADD32(ctx->r2, -0X2);
    // 0x8007D038: sh          $t1, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r9;
    // 0x8007D03C: lh          $t5, 0x18($s2)
    ctx->r13 = S32(MEM_H(ctx->r18, 0X18));
    // 0x8007D040: andi        $t9, $t5, 0x3
    ctx->r25 = ctx->r13 & 0X3;
    // 0x8007D044: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007D048: b           L_8007D054
    // 0x8007D04C: sh          $t6, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r14;
        goto L_8007D054;
    // 0x8007D04C: sh          $t6, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r14;
L_8007D050:
    // 0x8007D050: sh          $zero, 0x18($s2)
    MEM_H(0X18, ctx->r18) = 0;
L_8007D054:
    // 0x8007D054: jal         0x80076190
    // 0x8007D058: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    ssp(rdram, ctx);
        goto after_53;
    // 0x8007D058: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_53:
    // 0x8007D05C: b           L_8007D274
    // 0x8007D060: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
        goto L_8007D274;
    // 0x8007D060: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007D064:
    // 0x8007D064: slti        $at, $v1, 0x956
    ctx->r1 = SIGNED(ctx->r3) < 0X956 ? 1 : 0;
L_8007D068:
    // 0x8007D068: bne         $at, $zero, L_8007D270
    if (ctx->r1 != 0) {
        // 0x8007D06C: slti        $at, $v1, 0x974
        ctx->r1 = SIGNED(ctx->r3) < 0X974 ? 1 : 0;
            goto L_8007D270;
    }
    // 0x8007D06C: slti        $at, $v1, 0x974
    ctx->r1 = SIGNED(ctx->r3) < 0X974 ? 1 : 0;
    // 0x8007D070: beql        $at, $zero, L_8007D274
    if (ctx->r1 == 0) {
        // 0x8007D074: lh          $s3, 0x70($sp)
        ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
            goto L_8007D274;
    }
    goto skip_55;
    // 0x8007D074: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
    skip_55:
    // 0x8007D078: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    // 0x8007D07C: blez        $v0, L_8007D08C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007D080: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8007D08C;
    }
    // 0x8007D080: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8007D084: b           L_8007D090
    // 0x8007D088: sh          $t0, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r8;
        goto L_8007D090;
    // 0x8007D088: sh          $t0, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r8;
L_8007D08C:
    // 0x8007D08C: sh          $zero, 0x18($s2)
    MEM_H(0X18, ctx->r18) = 0;
L_8007D090:
    // 0x8007D090: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007D094: slti        $at, $v1, 0x401
    ctx->r1 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
    // 0x8007D098: bne         $at, $zero, L_8007D0C4
    if (ctx->r1 != 0) {
        // 0x8007D09C: slti        $at, $v1, 0x500
        ctx->r1 = SIGNED(ctx->r3) < 0X500 ? 1 : 0;
            goto L_8007D0C4;
    }
    // 0x8007D09C: slti        $at, $v1, 0x500
    ctx->r1 = SIGNED(ctx->r3) < 0X500 ? 1 : 0;
    // 0x8007D0A0: beq         $at, $zero, L_8007D0C4
    if (ctx->r1 == 0) {
        // 0x8007D0A4: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007D0C4;
    }
    // 0x8007D0A4: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007D0A8: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007D0AC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8007D0B0: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007D0B4: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007D0B8: jal         0x8009219C
    // 0x8007D0BC: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    setsprite(rdram, ctx);
        goto after_54;
    // 0x8007D0BC: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    after_54:
    // 0x8007D0C0: lh          $s5, 0x10($s2)
    ctx->r21 = S32(MEM_H(ctx->r18, 0X10));
L_8007D0C4:
    // 0x8007D0C4: sll         $t2, $s5, 2
    ctx->r10 = S32(ctx->r21 << 2);
    // 0x8007D0C8: subu        $t2, $t2, $s5
    ctx->r10 = SUB32(ctx->r10, ctx->r21);
    // 0x8007D0CC: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8007D0D0: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x8007D0D4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8007D0D8: lw          $t3, -0x1984($t3)
    ctx->r11 = S32(MEM_W(ctx->r11, -0X1984));
    // 0x8007D0DC: lw          $t4, 0x8($s2)
    ctx->r12 = S32(MEM_W(ctx->r18, 0X8));
    // 0x8007D0E0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8007D0E4: addiu       $t1, $t3, -0x200
    ctx->r9 = ADD32(ctx->r11, -0X200);
    // 0x8007D0E8: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8007D0EC: beql        $at, $zero, L_8007D1E8
    if (ctx->r1 == 0) {
        // 0x8007D0F0: lh          $t2, 0xE($s2)
        ctx->r10 = S32(MEM_H(ctx->r18, 0XE));
            goto L_8007D1E8;
    }
    goto skip_56;
    // 0x8007D0F0: lh          $t2, 0xE($s2)
    ctx->r10 = S32(MEM_H(ctx->r18, 0XE));
    skip_56:
    // 0x8007D0F4: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    // 0x8007D0F8: lw          $v0, 0x4($s1)
    ctx->r2 = S32(MEM_W(ctx->r17, 0X4));
    // 0x8007D0FC: bgtz        $v0, L_8007D10C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8007D100: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_8007D10C;
    }
    // 0x8007D100: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8007D104: b           L_8007D15C
    // 0x8007D108: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
        goto L_8007D15C;
    // 0x8007D108: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
L_8007D10C:
    // 0x8007D10C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8007D110: lh          $t9, 0xE($s2)
    ctx->r25 = S32(MEM_H(ctx->r18, 0XE));
    // 0x8007D114: slti        $at, $t9, 0x95E
    ctx->r1 = SIGNED(ctx->r25) < 0X95E ? 1 : 0;
    // 0x8007D118: beql        $at, $zero, L_8007D144
    if (ctx->r1 == 0) {
        // 0x8007D11C: lw          $v1, 0x0($s1)
        ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
            goto L_8007D144;
    }
    goto skip_57;
    // 0x8007D11C: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    skip_57:
    // 0x8007D120: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
    // 0x8007D124: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8007D128: bne         $at, $zero, L_8007D138
    if (ctx->r1 != 0) {
        // 0x8007D12C: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8007D138;
    }
    // 0x8007D12C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8007D130: b           L_8007D15C
    // 0x8007D134: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_8007D15C;
    // 0x8007D134: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8007D138:
    // 0x8007D138: b           L_8007D15C
    // 0x8007D13C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_8007D15C;
    // 0x8007D13C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8007D140: lw          $v1, 0x0($s1)
    ctx->r3 = S32(MEM_W(ctx->r17, 0X0));
L_8007D144:
    // 0x8007D144: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8007D148: bne         $at, $zero, L_8007D158
    if (ctx->r1 != 0) {
        // 0x8007D14C: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_8007D158;
    }
    // 0x8007D14C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8007D150: b           L_8007D15C
    // 0x8007D154: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_8007D15C;
    // 0x8007D154: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_8007D158:
    // 0x8007D158: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_8007D15C:
    // 0x8007D15C: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
    // 0x8007D160: slti        $at, $v1, 0x1000
    ctx->r1 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // 0x8007D164: beq         $at, $zero, L_8007D174
    if (ctx->r1 == 0) {
        // 0x8007D168: addiu       $t0, $v1, 0x7E
        ctx->r8 = ADD32(ctx->r3, 0X7E);
            goto L_8007D174;
    }
    // 0x8007D168: addiu       $t0, $v1, 0x7E
    ctx->r8 = ADD32(ctx->r3, 0X7E);
    // 0x8007D16C: sh          $t0, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r8;
    // 0x8007D170: lh          $v1, 0x1C($s2)
    ctx->r3 = S32(MEM_H(ctx->r18, 0X1C));
L_8007D174:
    // 0x8007D174: lh          $a0, 0x14($s2)
    ctx->r4 = S32(MEM_H(ctx->r18, 0X14));
    // 0x8007D178: addiu       $a1, $a1, -0x9A0
    ctx->r5 = ADD32(ctx->r5, -0X9A0);
    // 0x8007D17C: lh          $v0, 0x18($s2)
    ctx->r2 = S32(MEM_H(ctx->r18, 0X18));
    // 0x8007D180: addiu       $t2, $a0, 0x200
    ctx->r10 = ADD32(ctx->r4, 0X200);
    // 0x8007D184: andi        $t3, $t2, 0x7FF
    ctx->r11 = ctx->r10 & 0X7FF;
    // 0x8007D188: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8007D18C: addu        $t1, $a1, $t4
    ctx->r9 = ADD32(ctx->r5, ctx->r12);
    // 0x8007D190: lh          $t5, 0x0($t1)
    ctx->r13 = S32(MEM_H(ctx->r9, 0X0));
    // 0x8007D194: lw          $t8, 0x0($s2)
    ctx->r24 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007D198: andi        $t2, $a0, 0x7FF
    ctx->r10 = ctx->r4 & 0X7FF;
    // 0x8007D19C: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D1A0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8007D1A4: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x8007D1A8: lw          $t0, 0x4($s2)
    ctx->r8 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007D1AC: mflo        $t9
    ctx->r25 = lo;
    // 0x8007D1B0: sra         $t6, $t9, 14
    ctx->r14 = S32(SIGNED(ctx->r25) >> 14);
    // 0x8007D1B4: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8007D1B8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8007D1BC: lh          $t1, 0x0($t4)
    ctx->r9 = S32(MEM_H(ctx->r12, 0X0));
    // 0x8007D1C0: lw          $t6, 0x8($s2)
    ctx->r14 = S32(MEM_W(ctx->r18, 0X8));
    // 0x8007D1C4: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D1C8: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8007D1CC: sw          $t7, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r15;
    // 0x8007D1D0: mflo        $t5
    ctx->r13 = lo;
    // 0x8007D1D4: sra         $t9, $t5, 14
    ctx->r25 = S32(SIGNED(ctx->r13) >> 14);
    // 0x8007D1D8: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x8007D1DC: b           L_8007D270
    // 0x8007D1E0: sw          $t8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r24;
        goto L_8007D270;
    // 0x8007D1E0: sw          $t8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r24;
    // 0x8007D1E4: lh          $t2, 0xE($s2)
    ctx->r10 = S32(MEM_H(ctx->r18, 0XE));
L_8007D1E8:
    // 0x8007D1E8: addiu       $at, $zero, 0x960
    ctx->r1 = ADD32(0, 0X960);
    // 0x8007D1EC: bnel        $t2, $at, L_8007D264
    if (ctx->r10 != ctx->r1) {
        // 0x8007D1F0: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007D264;
    }
    goto skip_58;
    // 0x8007D1F0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    skip_58:
    // 0x8007D1F4: lh          $a1, 0x1A($s2)
    ctx->r5 = S32(MEM_H(ctx->r18, 0X1A));
    // 0x8007D1F8: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007D1FC: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007D200: blezl       $a1, L_8007D264
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007D204: sll         $a0, $s3, 16
        ctx->r4 = S32(ctx->r19 << 16);
            goto L_8007D264;
    }
    goto skip_59;
    // 0x8007D204: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    skip_59:
    // 0x8007D208: jal         0x8009D240
    // 0x8007D20C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    spawn(rdram, ctx);
        goto after_55;
    // 0x8007D20C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_55:
    // 0x8007D210: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8007D214: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8007D218: sra         $t4, $s0, 16
    ctx->r12 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8007D21C: sra         $t1, $a0, 16
    ctx->r9 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007D220: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x8007D224: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007D228: lw          $a1, 0x0($s2)
    ctx->r5 = S32(MEM_W(ctx->r18, 0X0));
    // 0x8007D22C: lw          $a2, 0x4($s2)
    ctx->r6 = S32(MEM_W(ctx->r18, 0X4));
    // 0x8007D230: jal         0x8009219C
    // 0x8007D234: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    setsprite(rdram, ctx);
        goto after_56;
    // 0x8007D234: lw          $a3, 0x8($s2)
    ctx->r7 = S32(MEM_W(ctx->r18, 0X8));
    after_56:
    // 0x8007D238: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x8007D23C: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007D240: jal         0x800898D0
    // 0x8007D244: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    getglobalz(rdram, ctx);
        goto after_57;
    // 0x8007D244: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_57:
    // 0x8007D248: multu       $s0, $s7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D24C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007D250: addu        $a1, $s6, $t0
    ctx->r5 = ADD32(ctx->r22, ctx->r8);
    // 0x8007D254: sh          $zero, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = 0;
    // 0x8007D258: lh          $t9, 0x1E($a1)
    ctx->r25 = S32(MEM_H(ctx->r5, 0X1E));
    // 0x8007D25C: sh          $t9, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r25;
    // 0x8007D260: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
L_8007D264:
    // 0x8007D264: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007D268: jal         0x80092728
    // 0x8007D26C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    deletesprite(rdram, ctx);
        goto after_58;
    // 0x8007D26C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_58:
L_8007D270:
    // 0x8007D270: lh          $s3, 0x70($sp)
    ctx->r19 = S32(MEM_H(ctx->r29, 0X70));
L_8007D274:
    // 0x8007D274: bgez        $s3, L_8007BCB0
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8007D278: nop
    
            goto L_8007BCB0;
    }
    // 0x8007D278: nop

L_8007D27C:
    // 0x8007D27C: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x8007D280: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8007D284: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8007D288: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8007D28C: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8007D290: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x8007D294: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x8007D298: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x8007D29C: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8007D2A0: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x8007D2A4: jr          $ra
    // 0x8007D2A8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8007D2A8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void ifhitsectors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007730C: lui         $v1, 0x8027
    ctx->r3 = S32(0X8027 << 16);
    // 0x80077310: lh          $v1, 0x2862($v1)
    ctx->r3 = S32(MEM_H(ctx->r3, 0X2862));
    // 0x80077314: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80077318: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007731C: bltz        $v1, L_8007737C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80077320: sra         $a0, $t6, 16
        ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8007737C;
    }
    // 0x80077320: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80077324: lui         $t0, 0x8027
    ctx->r8 = S32(0X8027 << 16);
    // 0x80077328: lui         $a2, 0x8024
    ctx->r6 = S32(0X8024 << 16);
    // 0x8007732C: addiu       $a2, $a2, 0x6BA8
    ctx->r6 = ADD32(ctx->r6, 0X6BA8);
    // 0x80077330: addiu       $t0, $t0, 0x5F40
    ctx->r8 = ADD32(ctx->r8, 0X5F40);
    // 0x80077334: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80077338: addiu       $a1, $zero, 0x762
    ctx->r5 = ADD32(0, 0X762);
L_8007733C:
    // 0x8007733C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80077340: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x80077344: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80077348: mflo        $t8
    ctx->r24 = lo;
    // 0x8007734C: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x80077350: lh          $t9, 0xE($v0)
    ctx->r25 = S32(MEM_H(ctx->r2, 0XE));
    // 0x80077354: bnel        $a1, $t9, L_80077374
    if (ctx->r5 != ctx->r25) {
        // 0x80077358: lh          $v1, 0x0($t3)
        ctx->r3 = S32(MEM_H(ctx->r11, 0X0));
            goto L_80077374;
    }
    goto skip_0;
    // 0x80077358: lh          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_H(ctx->r11, 0X0));
    skip_0:
    // 0x8007735C: lh          $t1, 0x10($v0)
    ctx->r9 = S32(MEM_H(ctx->r2, 0X10));
    // 0x80077360: bnel        $a0, $t1, L_80077374
    if (ctx->r4 != ctx->r9) {
        // 0x80077364: lh          $v1, 0x0($t3)
        ctx->r3 = S32(MEM_H(ctx->r11, 0X0));
            goto L_80077374;
    }
    goto skip_1;
    // 0x80077364: lh          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_H(ctx->r11, 0X0));
    skip_1:
    // 0x80077368: jr          $ra
    // 0x8007736C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8007736C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80077370: lh          $v1, 0x0($t3)
    ctx->r3 = S32(MEM_H(ctx->r11, 0X0));
L_80077374:
    // 0x80077374: bgez        $v1, L_8007733C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80077378: nop
    
            goto L_8007733C;
    }
    // 0x80077378: nop

L_8007737C:
    // 0x8007737C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80077380: jr          $ra
    // 0x80077384: nop

    return;
    // 0x80077384: nop

;}
RECOMP_FUNC void alignflorslope(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800992B4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800992B8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800992BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800992C0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800992C4: lui         $t9, 0x8022
    ctx->r25 = S32(0X8022 << 16);
    // 0x800992C8: addiu       $t9, $t9, -0x1988
    ctx->r25 = ADD32(ctx->r25, -0X1988);
    // 0x800992CC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800992D0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800992D4: lh          $t6, 0x8($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0X8));
    // 0x800992D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800992DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800992E0: addiu       $ra, $zero, 0x24
    ctx->r31 = ADD32(0, 0X24);
    // 0x800992E4: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800992E8: lui         $t5, 0x8022
    ctx->r13 = S32(0X8022 << 16);
    // 0x800992EC: addiu       $t5, $t5, 0x61A8
    ctx->r13 = ADD32(ctx->r13, 0X61A8);
    // 0x800992F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800992F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800992F8: mflo        $t7
    ctx->r15 = lo;
    // 0x800992FC: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x80099300: lh          $t8, 0x8($v0)
    ctx->r24 = S32(MEM_H(ctx->r2, 0X8));
    // 0x80099304: lw          $t1, 0x0($v0)
    ctx->r9 = S32(MEM_W(ctx->r2, 0X0));
    // 0x80099308: lw          $t2, 0x4($v0)
    ctx->r10 = S32(MEM_W(ctx->r2, 0X4));
    // 0x8009930C: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099310: subu        $t8, $a2, $t2
    ctx->r24 = SUB32(ctx->r6, ctx->r10);
    // 0x80099314: mflo        $t9
    ctx->r25 = lo;
    // 0x80099318: addu        $t0, $t5, $t9
    ctx->r8 = ADD32(ctx->r13, ctx->r25);
    // 0x8009931C: lw          $t6, 0x0($t0)
    ctx->r14 = S32(MEM_W(ctx->r8, 0X0));
    // 0x80099320: lw          $t7, 0x4($t0)
    ctx->r15 = S32(MEM_W(ctx->r8, 0X4));
    // 0x80099324: subu        $t3, $t6, $t1
    ctx->r11 = SUB32(ctx->r14, ctx->r9);
    // 0x80099328: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009932C: subu        $t6, $a1, $t1
    ctx->r14 = SUB32(ctx->r5, ctx->r9);
    // 0x80099330: subu        $t4, $t7, $t2
    ctx->r12 = SUB32(ctx->r15, ctx->r10);
    // 0x80099334: mflo        $t9
    ctx->r25 = lo;
    // 0x80099338: nop

    // 0x8009933C: nop

    // 0x80099340: multu       $t6, $t4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099344: mflo        $t7
    ctx->r15 = lo;
    // 0x80099348: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8009934C: beq         $t8, $zero, L_800993D0
    if (ctx->r24 == 0) {
        // 0x80099350: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_800993D0;
    }
    // 0x80099350: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80099354: multu       $t3, $t3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099358: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8009935C: mflo        $t6
    ctx->r14 = lo;
    // 0x80099360: nop

    // 0x80099364: nop

    // 0x80099368: multu       $t4, $t4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009936C: mflo        $t9
    ctx->r25 = lo;
    // 0x80099370: addu        $a0, $t6, $t9
    ctx->r4 = ADD32(ctx->r14, ctx->r25);
    // 0x80099374: jal         0x80091A00
    // 0x80099378: nop

    nsqrtasm(rdram, ctx);
        goto after_0;
    // 0x80099378: nop

    after_0:
    // 0x8009937C: lw          $v1, 0x18($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80099380: lw          $t7, 0x3C($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X3C));
    // 0x80099384: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80099388: lw          $t8, 0x4($v1)
    ctx->r24 = S32(MEM_W(ctx->r3, 0X4));
    // 0x8009938C: lw          $a2, 0x2C($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80099390: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80099394: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80099398: jal         0x800919B0
    // 0x8009939C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    scale(rdram, ctx);
        goto after_1;
    // 0x8009939C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x800993A0: lw          $v1, 0x18($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800993A4: sh          $v0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r2;
    // 0x800993A8: lh          $t9, 0x16($v1)
    ctx->r25 = S32(MEM_H(ctx->r3, 0X16));
    // 0x800993AC: bnel        $t9, $zero, L_800993C8
    if (ctx->r25 != 0) {
        // 0x800993B0: lh          $t6, 0xE($v1)
        ctx->r14 = S32(MEM_H(ctx->r3, 0XE));
            goto L_800993C8;
    }
    goto skip_0;
    // 0x800993B0: lh          $t6, 0xE($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0XE));
    skip_0:
    // 0x800993B4: lh          $t7, 0xE($v1)
    ctx->r15 = S32(MEM_H(ctx->r3, 0XE));
    // 0x800993B8: andi        $t8, $t7, 0xFFFD
    ctx->r24 = ctx->r15 & 0XFFFD;
    // 0x800993BC: b           L_800993D0
    // 0x800993C0: sh          $t8, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r24;
        goto L_800993D0;
    // 0x800993C0: sh          $t8, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r24;
    // 0x800993C4: lh          $t6, 0xE($v1)
    ctx->r14 = S32(MEM_H(ctx->r3, 0XE));
L_800993C8:
    // 0x800993C8: ori         $t9, $t6, 0x2
    ctx->r25 = ctx->r14 | 0X2;
    // 0x800993CC: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
L_800993D0:
    // 0x800993D0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x800993D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800993D8: jr          $ra
    // 0x800993DC: nop

    return;
    // 0x800993DC: nop

;}
RECOMP_FUNC void allocache2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071F44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80071F48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80071F4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071F50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80071F54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80071F58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80071F5C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80071F60: jal         0x8007197C
    // 0x80071F64: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    allocache(rdram, ctx);
        goto after_0;
    // 0x80071F64: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    after_0:
    // 0x80071F68: bnel        $v0, $zero, L_80071F94
    if (ctx->r2 != 0) {
        // 0x80071F6C: lw          $ra, 0x24($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
            goto L_80071F94;
    }
    goto skip_0;
    // 0x80071F6C: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
    skip_0:
L_80071F70:
    // 0x80071F70: jal         0x80071EEC
    // 0x80071F74: nop

    agecache(rdram, ctx);
        goto after_1;
    // 0x80071F74: nop

    after_1:
    // 0x80071F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80071F7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80071F80: jal         0x8007197C
    // 0x80071F84: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    allocache(rdram, ctx);
        goto after_2;
    // 0x80071F84: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80071F88: beq         $v0, $zero, L_80071F70
    if (ctx->r2 == 0) {
        // 0x80071F8C: nop
    
            goto L_80071F70;
    }
    // 0x80071F8C: nop

    // 0x80071F90: lw          $ra, 0x24($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X24));
L_80071F94:
    // 0x80071F94: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80071F98: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80071F9C: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80071FA0: jr          $ra
    // 0x80071FA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80071FA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80058348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058348: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x8005834C: addiu       $v0, $v0, -0x5F08
    ctx->r2 = ADD32(ctx->r2, -0X5F08);
    // 0x80058350: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80058354: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
L_80058358:
    // 0x80058358: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8005835C: bnel        $t6, $zero, L_80058370
    if (ctx->r14 != 0) {
        // 0x80058360: lbu         $t7, 0x18($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X18);
            goto L_80058370;
    }
    goto skip_0;
    // 0x80058360: lbu         $t7, 0x18($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18);
    skip_0:
    // 0x80058364: jr          $ra
    // 0x80058368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80058368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005836C: lbu         $t7, 0x18($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18);
L_80058370:
    // 0x80058370: bnel        $t7, $zero, L_80058384
    if (ctx->r15 != 0) {
        // 0x80058374: lbu         $t8, 0x30($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X30);
            goto L_80058384;
    }
    goto skip_1;
    // 0x80058374: lbu         $t8, 0x30($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X30);
    skip_1:
    // 0x80058378: jr          $ra
    // 0x8005837C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x8005837C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80058380: lbu         $t8, 0x30($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X30);
L_80058384:
    // 0x80058384: bnel        $t8, $zero, L_80058398
    if (ctx->r24 != 0) {
        // 0x80058388: lbu         $t9, 0x48($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X48);
            goto L_80058398;
    }
    goto skip_2;
    // 0x80058388: lbu         $t9, 0x48($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X48);
    skip_2:
    // 0x8005838C: jr          $ra
    // 0x80058390: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x80058390: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80058394: lbu         $t9, 0x48($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X48);
L_80058398:
    // 0x80058398: bnel        $t9, $zero, L_800583AC
    if (ctx->r25 != 0) {
        // 0x8005839C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800583AC;
    }
    goto skip_3;
    // 0x8005839C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x800583A0: jr          $ra
    // 0x800583A4: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x800583A4: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x800583A8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800583AC:
    // 0x800583AC: bne         $v1, $a0, L_80058358
    if (ctx->r3 != ctx->r4) {
        // 0x800583B0: addiu       $v0, $v0, 0x60
        ctx->r2 = ADD32(ctx->r2, 0X60);
            goto L_80058358;
    }
    // 0x800583B0: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // 0x800583B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800583B8: jr          $ra
    // 0x800583BC: nop

    return;
    // 0x800583BC: nop

;}
RECOMP_FUNC void func_800583C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800583C0: lui         $a0, 0x8022
    ctx->r4 = S32(0X8022 << 16);
    // 0x800583C4: lui         $v0, 0x8022
    ctx->r2 = S32(0X8022 << 16);
    // 0x800583C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800583CC: addiu       $v0, $v0, -0x5C08
    ctx->r2 = ADD32(ctx->r2, -0X5C08);
    // 0x800583D0: addiu       $a0, $a0, -0x5F08
    ctx->r4 = ADD32(ctx->r4, -0X5F08);
    // 0x800583D4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_800583D8:
    // 0x800583D8: bnel        $t6, $zero, L_800583E8
    if (ctx->r14 != 0) {
        // 0x800583DC: lbu         $t7, 0x18($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X18);
            goto L_800583E8;
    }
    goto skip_0;
    // 0x800583DC: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    skip_0:
    // 0x800583E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800583E4: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
L_800583E8:
    // 0x800583E8: bnel        $t7, $zero, L_800583F8
    if (ctx->r15 != 0) {
        // 0x800583EC: lbu         $t8, 0x30($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X30);
            goto L_800583F8;
    }
    goto skip_1;
    // 0x800583EC: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    skip_1:
    // 0x800583F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800583F4: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
L_800583F8:
    // 0x800583F8: bnel        $t8, $zero, L_80058408
    if (ctx->r24 != 0) {
        // 0x800583FC: lbu         $t9, 0x48($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X48);
            goto L_80058408;
    }
    goto skip_2;
    // 0x800583FC: lbu         $t9, 0x48($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X48);
    skip_2:
    // 0x80058400: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80058404: lbu         $t9, 0x48($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X48);
L_80058408:
    // 0x80058408: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    // 0x8005840C: bne         $t9, $zero, L_80058418
    if (ctx->r25 != 0) {
        // 0x80058410: nop
    
            goto L_80058418;
    }
    // 0x80058410: nop

    // 0x80058414: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80058418:
    // 0x80058418: bnel        $a0, $v0, L_800583D8
    if (ctx->r4 != ctx->r2) {
        // 0x8005841C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800583D8;
    }
    goto skip_3;
    // 0x8005841C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_3:
    // 0x80058420: jr          $ra
    // 0x80058424: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80058424: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void deletesprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009272C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80092734: jal         0x80092850
    // 0x80092738: lh          $a0, 0x1A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X1A));
    deletespritestat(rdram, ctx);
        goto after_0;
    // 0x80092738: lh          $a0, 0x1A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X1A));
    after_0:
    // 0x8009273C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80092740: addiu       $v1, $v1, -0x9FC
    ctx->r3 = ADD32(ctx->r3, -0X9FC);
    // 0x80092744: lw          $t6, 0x0($v1)
    ctx->r14 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80092748: lh          $a0, 0x1A($sp)
    ctx->r4 = S32(MEM_H(ctx->r29, 0X1A));
    // 0x8009274C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80092750: jal         0x80092768
    // 0x80092754: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    deletespritesect(rdram, ctx);
        goto after_1;
    // 0x80092754: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_1:
    // 0x80092758: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8009275C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092760: jr          $ra
    // 0x80092764: nop

    return;
    // 0x80092764: nop

;}
RECOMP_FUNC void alEvtqPostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9C6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9C74: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C9C78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C9C7C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800C9C80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C9C84: jal         0x800BC180
    // 0x800C9C88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9C88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C9C8C: lw          $t6, 0x30($sp)
    ctx->r14 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800C9C90: lw          $a3, 0x38($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C9C94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C9C98: lw          $t0, 0x0($t6)
    ctx->r8 = S32(MEM_W(ctx->r14, 0X0));
    // 0x800C9C9C: bne         $t0, $zero, L_800C9CB4
    if (ctx->r8 != 0) {
        // 0x800C9CA0: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800C9CB4;
    }
    // 0x800C9CA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C9CA4: jal         0x800BC180
    // 0x800C9CA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800C9CA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800C9CAC: b           L_800C9D84
    // 0x800C9CB0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
        goto L_800C9D84;
    // 0x800C9CB0: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C9CB4:
    // 0x800C9CB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9CB8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800C9CBC: jal         0x800BF770
    // 0x800C9CC0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800C9CC0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C9CC4: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800C9CC8: lw          $a0, 0x34($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X34));
    // 0x800C9CCC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800C9CD0: jal         0x800CFF10
    // 0x800C9CD4: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alCopy(rdram, ctx);
        goto after_3;
    // 0x800C9CD4: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800C9CD8: lw          $a3, 0x38($sp)
    ctx->r7 = S32(MEM_W(ctx->r29, 0X38));
    // 0x800C9CDC: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800C9CE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800C9CE4: bne         $a3, $at, L_800C9CF4
    if (ctx->r7 != ctx->r1) {
        // 0x800C9CE8: lw          $t0, 0x2C($sp)
        ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
            goto L_800C9CF4;
    }
    // 0x800C9CE8: lw          $t0, 0x2C($sp)
    ctx->r8 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x800C9CEC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C9CF0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800C9CF4:
    // 0x800C9CF4: lw          $v0, 0x30($sp)
    ctx->r2 = S32(MEM_W(ctx->r29, 0X30));
    // 0x800C9CF8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800C9CFC: lw          $t8, 0x20($sp)
    ctx->r24 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800C9D00: beq         $v0, $at, L_800C9D78
    if (ctx->r2 == ctx->r1) {
        // 0x800C9D04: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_800C9D78;
    }
    // 0x800C9D04: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_800C9D08:
    // 0x800C9D08: lw          $v0, 0x0($a1)
    ctx->r2 = S32(MEM_W(ctx->r5, 0X0));
    // 0x800C9D0C: bnel        $v0, $zero, L_800C9D3C
    if (ctx->r2 != 0) {
        // 0x800C9D10: lw          $v1, 0x8($v0)
        ctx->r3 = S32(MEM_W(ctx->r2, 0X8));
            goto L_800C9D3C;
    }
    goto skip_0;
    // 0x800C9D10: lw          $v1, 0x8($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0X8));
    skip_0:
    // 0x800C9D14: beql        $t8, $zero, L_800C9D28
    if (ctx->r24 == 0) {
        // 0x800C9D18: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_800C9D28;
    }
    goto skip_1;
    // 0x800C9D18: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x800C9D1C: b           L_800C9D28
    // 0x800C9D20: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_800C9D28;
    // 0x800C9D20: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x800C9D24: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_800C9D28:
    // 0x800C9D28: jal         0x800BF7A0
    // 0x800C9D2C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800C9D2C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x800C9D30: b           L_800C9D78
    // 0x800C9D34: nop

        goto L_800C9D78;
    // 0x800C9D34: nop

    // 0x800C9D38: lw          $v1, 0x8($v0)
    ctx->r3 = S32(MEM_W(ctx->r2, 0X8));
L_800C9D3C:
    // 0x800C9D3C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9D40: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C9D44: beql        $at, $zero, L_800C9D70
    if (ctx->r1 == 0) {
        // 0x800C9D48: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800C9D70;
    }
    goto skip_2;
    // 0x800C9D48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x800C9D4C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x800C9D50: lw          $t9, 0x8($a2)
    ctx->r25 = S32(MEM_W(ctx->r6, 0X8));
    // 0x800C9D54: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C9D58: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x800C9D5C: jal         0x800BF7A0
    // 0x800C9D60: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800C9D60: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    after_5:
    // 0x800C9D64: b           L_800C9D78
    // 0x800C9D68: nop

        goto L_800C9D78;
    // 0x800C9D68: nop

    // 0x800C9D6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800C9D70:
    // 0x800C9D70: bne         $v0, $zero, L_800C9D08
    if (ctx->r2 != 0) {
        // 0x800C9D74: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_800C9D08;
    }
    // 0x800C9D74: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_800C9D78:
    // 0x800C9D78: jal         0x800BC180
    // 0x800C9D7C: lw          $a0, 0x1C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X1C));
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800C9D7C: lw          $a0, 0x1C($sp)
    ctx->r4 = S32(MEM_W(ctx->r29, 0X1C));
    after_6:
    // 0x800C9D80: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
L_800C9D84:
    // 0x800C9D84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C9D88: jr          $ra
    // 0x800C9D8C: nop

    return;
    // 0x800C9D8C: nop

;}
RECOMP_FUNC void updatesector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097DB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80097DBC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80097DC0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80097DC4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80097DC8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80097DCC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80097DD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80097DD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80097DD8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80097DDC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80097DE0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80097DE4: jal         0x80091E14
    // 0x80097DE8: lh          $a2, 0x0($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X0));
    inside(rdram, ctx);
        goto after_0;
    // 0x80097DE8: lh          $a2, 0x0($a2)
    ctx->r6 = S32(MEM_H(ctx->r6, 0X0));
    after_0:
    // 0x80097DEC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80097DF0: beq         $v0, $s5, L_80097EE0
    if (ctx->r2 == ctx->r21) {
        // 0x80097DF4: lw          $t7, 0x38($sp)
        ctx->r15 = S32(MEM_W(ctx->r29, 0X38));
            goto L_80097EE0;
    }
    // 0x80097DF4: lw          $t7, 0x38($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80097DF8: lh          $v1, 0x0($t7)
    ctx->r3 = S32(MEM_H(ctx->r15, 0X0));
    // 0x80097DFC: lui         $t8, 0x802B
    ctx->r24 = S32(0X802B << 16);
    // 0x80097E00: bltz        $v1, L_80097E8C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80097E04: nop
    
            goto L_80097E8C;
    }
    // 0x80097E04: nop

    // 0x80097E08: lh          $t8, -0x5378($t8)
    ctx->r24 = S32(MEM_H(ctx->r24, -0X5378));
    // 0x80097E0C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80097E10: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80097E14: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80097E18: beq         $at, $zero, L_80097E8C
    if (ctx->r1 == 0) {
        // 0x80097E1C: sll         $t9, $t9, 4
        ctx->r25 = S32(ctx->r25 << 4);
            goto L_80097E8C;
    }
    // 0x80097E1C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80097E20: lui         $t0, 0x8022
    ctx->r8 = S32(0X8022 << 16);
    // 0x80097E24: addiu       $t0, $t0, -0x1988
    ctx->r8 = ADD32(ctx->r8, -0X1988);
    // 0x80097E28: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80097E2C: lh          $t1, 0x8($v0)
    ctx->r9 = S32(MEM_H(ctx->r2, 0X8));
    // 0x80097E30: lui         $t3, 0x8022
    ctx->r11 = S32(0X8022 << 16);
    // 0x80097E34: addiu       $t3, $t3, 0x61A8
    ctx->r11 = ADD32(ctx->r11, 0X61A8);
    // 0x80097E38: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80097E3C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80097E40: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80097E44: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
    // 0x80097E48: lh          $s2, 0xA($v0)
    ctx->r18 = S32(MEM_H(ctx->r2, 0XA));
L_80097E4C:
    // 0x80097E4C: lh          $s0, 0xC($s1)
    ctx->r16 = S32(MEM_H(ctx->r17, 0XC));
    // 0x80097E50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097E54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80097E58: bltz        $s0, L_80097E80
    if (SIGNED(ctx->r16) < 0) {
        // 0x80097E5C: sll         $a2, $s0, 16
        ctx->r6 = S32(ctx->r16 << 16);
            goto L_80097E80;
    }
    // 0x80097E5C: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    // 0x80097E60: sra         $t4, $a2, 16
    ctx->r12 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80097E64: jal         0x80091E14
    // 0x80097E68: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    inside(rdram, ctx);
        goto after_1;
    // 0x80097E68: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_1:
    // 0x80097E6C: bnel        $v0, $s5, L_80097E84
    if (ctx->r2 != ctx->r21) {
        // 0x80097E70: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_80097E84;
    }
    goto skip_0;
    // 0x80097E70: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x80097E74: lw          $t5, 0x38($sp)
    ctx->r13 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80097E78: b           L_80097EE0
    // 0x80097E7C: sh          $s0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r16;
        goto L_80097EE0;
    // 0x80097E7C: sh          $s0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r16;
L_80097E80:
    // 0x80097E80: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80097E84:
    // 0x80097E84: bne         $s2, $zero, L_80097E4C
    if (ctx->r18 != 0) {
        // 0x80097E88: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_80097E4C;
    }
    // 0x80097E88: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
L_80097E8C:
    // 0x80097E8C: lui         $s0, 0x802B
    ctx->r16 = S32(0X802B << 16);
    // 0x80097E90: lh          $s0, -0x5378($s0)
    ctx->r16 = S32(MEM_H(ctx->r16, -0X5378));
    // 0x80097E94: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80097E98: bltz        $s0, L_80097ED4
    if (SIGNED(ctx->r16) < 0) {
        // 0x80097E9C: sll         $a2, $s0, 16
        ctx->r6 = S32(ctx->r16 << 16);
            goto L_80097ED4;
    }
    // 0x80097E9C: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
L_80097EA0:
    // 0x80097EA0: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80097EA4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80097EA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097EAC: jal         0x80091E14
    // 0x80097EB0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    inside(rdram, ctx);
        goto after_2;
    // 0x80097EB0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x80097EB4: bnel        $v0, $s5, L_80097ECC
    if (ctx->r2 != ctx->r21) {
        // 0x80097EB8: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80097ECC;
    }
    goto skip_1;
    // 0x80097EB8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
    // 0x80097EBC: lw          $t7, 0x38($sp)
    ctx->r15 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80097EC0: b           L_80097EE0
    // 0x80097EC4: sh          $s0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r16;
        goto L_80097EE0;
    // 0x80097EC4: sh          $s0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r16;
    // 0x80097EC8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80097ECC:
    // 0x80097ECC: bgezl       $s0, L_80097EA0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80097ED0: sll         $a2, $s0, 16
        ctx->r6 = S32(ctx->r16 << 16);
            goto L_80097EA0;
    }
    goto skip_2;
    // 0x80097ED0: sll         $a2, $s0, 16
    ctx->r6 = S32(ctx->r16 << 16);
    skip_2:
L_80097ED4:
    // 0x80097ED4: lw          $t9, 0x38($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80097ED8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80097EDC: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
L_80097EE0:
    // 0x80097EE0: lw          $ra, 0x2C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80097EE4: lw          $s0, 0x14($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80097EE8: lw          $s1, 0x18($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X18));
    // 0x80097EEC: lw          $s2, 0x1C($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x80097EF0: lw          $s3, 0x20($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X20));
    // 0x80097EF4: lw          $s4, 0x24($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X24));
    // 0x80097EF8: lw          $s5, 0x28($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80097EFC: jr          $ra
    // 0x80097F00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80097F00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void menutext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006413C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80064140: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064144: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x80064148: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006414C: sra         $s1, $s0, 16
    ctx->r17 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80064150: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80064154: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80064158: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8006415C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80064160: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80064164: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80064168: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006416C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80064170: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80064174: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80064178: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8006417C: bne         $s1, $at, L_800642D8
    if (ctx->r17 != ctx->r1) {
        // 0x80064180: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_800642D8;
    }
    // 0x80064180: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80064184: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x80064188: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8006418C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80064190: beq         $v1, $zero, L_800642A4
    if (ctx->r3 == 0) {
        // 0x80064194: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800642A4;
    }
    // 0x80064194: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80064198: beq         $v1, $at, L_800642A4
    if (ctx->r3 == ctx->r1) {
        // 0x8006419C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800642A4;
    }
    // 0x8006419C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800641A0: beq         $v1, $at, L_800642A4
    if (ctx->r3 == ctx->r1) {
        // 0x800641A4: lui         $fp, 0x800E
        ctx->r30 = S32(0X800E << 16);
            goto L_800642A4;
    }
    // 0x800641A4: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800641A8: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x800641AC: addiu       $fp, $fp, -0x5010
    ctx->r30 = ADD32(ctx->r30, -0X5010);
    // 0x800641B0: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
    // 0x800641B4: addiu       $s6, $zero, 0x27
    ctx->r22 = ADD32(0, 0X27);
    // 0x800641B8: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800641BC: addiu       $s4, $zero, 0x2E
    ctx->r20 = ADD32(0, 0X2E);
    // 0x800641C0: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
    // 0x800641C4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_800641C8:
    // 0x800641C8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800641CC: slti        $at, $t7, 0x30
    ctx->r1 = SIGNED(ctx->r15) < 0X30 ? 1 : 0;
    // 0x800641D0: bne         $at, $zero, L_800641F0
    if (ctx->r1 != 0) {
        // 0x800641D4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800641F0;
    }
    // 0x800641D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800641D8: slti        $at, $t7, 0x3A
    ctx->r1 = SIGNED(ctx->r15) < 0X3A ? 1 : 0;
    // 0x800641DC: beql        $at, $zero, L_800641F4
    if (ctx->r1 == 0) {
        // 0x800641E0: slti        $at, $v0, 0x41
        ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
            goto L_800641F4;
    }
    goto skip_0;
    // 0x800641E0: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    skip_0:
    // 0x800641E4: addiu       $v0, $t7, 0xB42
    ctx->r2 = ADD32(ctx->r15, 0XB42);
    // 0x800641E8: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800641EC: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_800641F0:
    // 0x800641F0: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
L_800641F4:
    // 0x800641F4: bne         $at, $zero, L_80064210
    if (ctx->r1 != 0) {
        // 0x800641F8: slti        $at, $v0, 0x5B
        ctx->r1 = SIGNED(ctx->r2) < 0X5B ? 1 : 0;
            goto L_80064210;
    }
    // 0x800641F8: slti        $at, $v0, 0x5B
    ctx->r1 = SIGNED(ctx->r2) < 0X5B ? 1 : 0;
    // 0x800641FC: beq         $at, $zero, L_80064210
    if (ctx->r1 == 0) {
        // 0x80064200: nop
    
            goto L_80064210;
    }
    // 0x80064200: nop

    // 0x80064204: addiu       $v0, $v0, 0xB3B
    ctx->r2 = ADD32(ctx->r2, 0XB3B);
    // 0x80064208: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8006420C: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
L_80064210:
    // 0x80064210: bne         $v0, $s3, L_8006421C
    if (ctx->r2 != ctx->r19) {
        // 0x80064214: nop
    
            goto L_8006421C;
    }
    // 0x80064214: nop

    // 0x80064218: addiu       $v0, $zero, 0xB71
    ctx->r2 = ADD32(0, 0XB71);
L_8006421C:
    // 0x8006421C: bne         $v0, $s4, L_80064228
    if (ctx->r2 != ctx->r20) {
        // 0x80064220: nop
    
            goto L_80064228;
    }
    // 0x80064220: nop

    // 0x80064224: addiu       $v0, $zero, 0xBBA
    ctx->r2 = ADD32(0, 0XBBA);
L_80064228:
    // 0x80064228: bne         $v0, $s5, L_80064234
    if (ctx->r2 != ctx->r21) {
        // 0x8006422C: nop
    
            goto L_80064234;
    }
    // 0x8006422C: nop

    // 0x80064230: addiu       $v0, $zero, 0xBBB
    ctx->r2 = ADD32(0, 0XBBB);
L_80064234:
    // 0x80064234: bne         $v0, $s6, L_80064240
    if (ctx->r2 != ctx->r22) {
        // 0x80064238: nop
    
            goto L_80064240;
    }
    // 0x80064238: nop

    // 0x8006423C: addiu       $v0, $zero, 0xBCE
    ctx->r2 = ADD32(0, 0XBCE);
L_80064240:
    // 0x80064240: bne         $v0, $s7, L_80064258
    if (ctx->r2 != ctx->r23) {
        // 0x80064244: nop
    
            goto L_80064258;
    }
    // 0x80064244: nop

    // 0x80064248: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8006424C: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x80064250: b           L_80064280
    // 0x80064254: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
        goto L_80064280;
    // 0x80064254: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
L_80064258:
    // 0x80064258: jal         0x8006370C
    // 0x8006425C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    gettileid(rdram, ctx);
        goto after_0;
    // 0x8006425C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_0:
    // 0x80064260: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x80064264: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x80064268: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006426C: addu        $t5, $fp, $t4
    ctx->r13 = ADD32(ctx->r30, ctx->r12);
    // 0x80064270: lh          $t6, 0xC($t5)
    ctx->r14 = S32(MEM_H(ctx->r13, 0XC));
    // 0x80064274: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x80064278: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x8006427C: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
L_80064280:
    // 0x80064280: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x80064284: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064288: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8006428C: beq         $v1, $zero, L_800642A4
    if (ctx->r3 == 0) {
        // 0x80064290: nop
    
            goto L_800642A4;
    }
    // 0x80064290: nop

    // 0x80064294: beq         $v1, $at, L_800642A4
    if (ctx->r3 == ctx->r1) {
        // 0x80064298: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800642A4;
    }
    // 0x80064298: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8006429C: bnel        $v1, $at, L_800641C8
    if (ctx->r3 != ctx->r1) {
        // 0x800642A0: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_800641C8;
    }
    goto skip_1;
    // 0x800642A0: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    skip_1:
L_800642A4:
    // 0x800642A4: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800642A8: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x800642AC: addiu       $fp, $fp, -0x5010
    ctx->r30 = ADD32(ctx->r30, -0X5010);
    // 0x800642B0: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
    // 0x800642B4: addiu       $s4, $zero, 0x2E
    ctx->r20 = ADD32(0, 0X2E);
    // 0x800642B8: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800642BC: addiu       $s6, $zero, 0x27
    ctx->r22 = ADD32(0, 0X27);
    // 0x800642C0: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
    // 0x800642C4: bgez        $s0, L_800642D4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800642C8: sra         $t9, $s0, 1
        ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
            goto L_800642D4;
    }
    // 0x800642C8: sra         $t9, $s0, 1
    ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800642CC: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x800642D0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800642D4:
    // 0x800642D4: subu        $s1, $t0, $t9
    ctx->r17 = SUB32(ctx->r8, ctx->r25);
L_800642D8:
    // 0x800642D8: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x800642DC: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800642E0: addiu       $fp, $fp, -0x5010
    ctx->r30 = ADD32(ctx->r30, -0X5010);
    // 0x800642E4: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
    // 0x800642E8: addiu       $s4, $zero, 0x2E
    ctx->r20 = ADD32(0, 0X2E);
    // 0x800642EC: addiu       $s5, $zero, 0x2C
    ctx->r21 = ADD32(0, 0X2C);
    // 0x800642F0: addiu       $s6, $zero, 0x27
    ctx->r22 = ADD32(0, 0X27);
    // 0x800642F4: beq         $v1, $zero, L_800643E8
    if (ctx->r3 == 0) {
        // 0x800642F8: addiu       $s7, $zero, 0x20
        ctx->r23 = ADD32(0, 0X20);
            goto L_800643E8;
    }
    // 0x800642F8: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
    // 0x800642FC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80064300: beq         $v1, $at, L_800643E8
    if (ctx->r3 == ctx->r1) {
        // 0x80064304: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800643E8;
    }
    // 0x80064304: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80064308: beq         $v1, $at, L_800643E8
    if (ctx->r3 == ctx->r1) {
        // 0x8006430C: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_800643E8;
    }
    // 0x8006430C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_80064310:
    // 0x80064310: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80064314: slti        $at, $t1, 0x30
    ctx->r1 = SIGNED(ctx->r9) < 0X30 ? 1 : 0;
    // 0x80064318: bne         $at, $zero, L_80064338
    if (ctx->r1 != 0) {
        // 0x8006431C: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80064338;
    }
    // 0x8006431C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80064320: slti        $at, $t1, 0x3A
    ctx->r1 = SIGNED(ctx->r9) < 0X3A ? 1 : 0;
    // 0x80064324: beql        $at, $zero, L_8006433C
    if (ctx->r1 == 0) {
        // 0x80064328: slti        $at, $v0, 0x41
        ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
            goto L_8006433C;
    }
    goto skip_2;
    // 0x80064328: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    skip_2:
    // 0x8006432C: addiu       $v0, $t1, 0xB42
    ctx->r2 = ADD32(ctx->r9, 0XB42);
    // 0x80064330: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x80064334: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
L_80064338:
    // 0x80064338: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
L_8006433C:
    // 0x8006433C: bne         $at, $zero, L_8006435C
    if (ctx->r1 != 0) {
        // 0x80064340: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8006435C;
    }
    // 0x80064340: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80064344: slti        $at, $v0, 0x5B
    ctx->r1 = SIGNED(ctx->r2) < 0X5B ? 1 : 0;
    // 0x80064348: beq         $at, $zero, L_8006435C
    if (ctx->r1 == 0) {
        // 0x8006434C: nop
    
            goto L_8006435C;
    }
    // 0x8006434C: nop

    // 0x80064350: addiu       $v0, $v0, 0xB3B
    ctx->r2 = ADD32(ctx->r2, 0XB3B);
    // 0x80064354: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80064358: sra         $v0, $t4, 16
    ctx->r2 = S32(SIGNED(ctx->r12) >> 16);
L_8006435C:
    // 0x8006435C: bne         $v0, $s3, L_80064368
    if (ctx->r2 != ctx->r19) {
        // 0x80064360: lh          $a1, 0x46($sp)
        ctx->r5 = S32(MEM_H(ctx->r29, 0X46));
            goto L_80064368;
    }
    // 0x80064360: lh          $a1, 0x46($sp)
    ctx->r5 = S32(MEM_H(ctx->r29, 0X46));
    // 0x80064364: addiu       $v0, $zero, 0xB71
    ctx->r2 = ADD32(0, 0XB71);
L_80064368:
    // 0x80064368: bne         $v0, $s4, L_80064374
    if (ctx->r2 != ctx->r20) {
        // 0x8006436C: nop
    
            goto L_80064374;
    }
    // 0x8006436C: nop

    // 0x80064370: addiu       $v0, $zero, 0xBBA
    ctx->r2 = ADD32(0, 0XBBA);
L_80064374:
    // 0x80064374: bne         $v0, $s5, L_80064380
    if (ctx->r2 != ctx->r21) {
        // 0x80064378: nop
    
            goto L_80064380;
    }
    // 0x80064378: nop

    // 0x8006437C: addiu       $v0, $zero, 0xBBB
    ctx->r2 = ADD32(0, 0XBBB);
L_80064380:
    // 0x80064380: bne         $v0, $s6, L_8006438C
    if (ctx->r2 != ctx->r22) {
        // 0x80064384: nop
    
            goto L_8006438C;
    }
    // 0x80064384: nop

    // 0x80064388: addiu       $v0, $zero, 0xBCE
    ctx->r2 = ADD32(0, 0XBCE);
L_8006438C:
    // 0x8006438C: bne         $v0, $s7, L_8006439C
    if (ctx->r2 != ctx->r23) {
        // 0x80064390: andi        $s0, $v0, 0xFFFF
        ctx->r16 = ctx->r2 & 0XFFFF;
            goto L_8006439C;
    }
    // 0x80064390: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x80064394: b           L_800643C4
    // 0x80064398: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
        goto L_800643C4;
    // 0x80064398: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8006439C:
    // 0x8006439C: jal         0x80065A64
    // 0x800643A0: andi        $a2, $s0, 0xFFFF
    ctx->r6 = ctx->r16 & 0XFFFF;
    rotatesprite_simple(rdram, ctx);
        goto after_1;
    // 0x800643A0: andi        $a2, $s0, 0xFFFF
    ctx->r6 = ctx->r16 & 0XFFFF;
    after_1:
    // 0x800643A4: jal         0x8006370C
    // 0x800643A8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    gettileid(rdram, ctx);
        goto after_2;
    // 0x800643A8: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_2:
    // 0x800643AC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800643B0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800643B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800643B8: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x800643BC: lh          $t8, 0xC($t7)
    ctx->r24 = S32(MEM_H(ctx->r15, 0XC));
    // 0x800643C0: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
L_800643C4:
    // 0x800643C4: lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1);
    // 0x800643C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800643CC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800643D0: beql        $v1, $zero, L_800643EC
    if (ctx->r3 == 0) {
        // 0x800643D4: lw          $ra, 0x3C($sp)
        ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
            goto L_800643EC;
    }
    goto skip_3;
    // 0x800643D4: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
    skip_3:
    // 0x800643D8: beq         $v1, $at, L_800643E8
    if (ctx->r3 == ctx->r1) {
        // 0x800643DC: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800643E8;
    }
    // 0x800643DC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800643E0: bnel        $v1, $at, L_80064310
    if (ctx->r3 != ctx->r1) {
        // 0x800643E4: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_80064310;
    }
    goto skip_4;
    // 0x800643E4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    skip_4:
L_800643E8:
    // 0x800643E8: lw          $ra, 0x3C($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X3C));
L_800643EC:
    // 0x800643EC: lw          $s0, 0x18($sp)
    ctx->r16 = S32(MEM_W(ctx->r29, 0X18));
    // 0x800643F0: lw          $s1, 0x1C($sp)
    ctx->r17 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x800643F4: lw          $s2, 0x20($sp)
    ctx->r18 = S32(MEM_W(ctx->r29, 0X20));
    // 0x800643F8: lw          $s3, 0x24($sp)
    ctx->r19 = S32(MEM_W(ctx->r29, 0X24));
    // 0x800643FC: lw          $s4, 0x28($sp)
    ctx->r20 = S32(MEM_W(ctx->r29, 0X28));
    // 0x80064400: lw          $s5, 0x2C($sp)
    ctx->r21 = S32(MEM_W(ctx->r29, 0X2C));
    // 0x80064404: lw          $s6, 0x30($sp)
    ctx->r22 = S32(MEM_W(ctx->r29, 0X30));
    // 0x80064408: lw          $s7, 0x34($sp)
    ctx->r23 = S32(MEM_W(ctx->r29, 0X34));
    // 0x8006440C: lw          $fp, 0x38($sp)
    ctx->r30 = S32(MEM_W(ctx->r29, 0X38));
    // 0x80064410: jr          $ra
    // 0x80064414: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80064414: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800524F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800524F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800524F4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x800524F8: lw          $a0, 0x4410($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4410));
    // 0x800524FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80052500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052504: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80052508: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005250C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80052510: jal         0x800BD8C8
    // 0x80052514: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    guTranslate(rdram, ctx);
        goto after_0;
    // 0x80052514: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    after_0:
    // 0x80052518: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005251C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80052520: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80052524: lw          $a0, 0x4410($a0)
    ctx->r4 = S32(MEM_W(ctx->r4, 0X4410));
    // 0x80052528: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005252C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80052530: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80052534: jal         0x800BD974
    // 0x80052538: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    guScale(rdram, ctx);
        goto after_1;
    // 0x80052538: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    after_1:
    // 0x8005253C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80052540: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x80052544: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80052548: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x8005254C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80052550: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80052554: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80052558: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x8005255C: addiu       $a3, $a3, 0x4410
    ctx->r7 = ADD32(ctx->r7, 0X4410);
    // 0x80052560: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80052564: lw          $t8, 0x0($a3)
    ctx->r24 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80052568: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005256C: ori         $at, $at, 0x300
    ctx->r1 = ctx->r1 | 0X300;
    // 0x80052570: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80052574: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80052578: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8005257C: lui         $t1, 0x100
    ctx->r9 = S32(0X100 << 16);
    // 0x80052580: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x80052584: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80052588: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8005258C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80052590: lw          $t2, 0x0($a3)
    ctx->r10 = S32(MEM_W(ctx->r7, 0X0));
    // 0x80052594: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80052598: ori         $at, $at, 0x380
    ctx->r1 = ctx->r1 | 0X380;
    // 0x8005259C: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800525A0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800525A4: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800525A8: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x800525AC: addiu       $t6, $t6, 0x1908
    ctx->r14 = ADD32(ctx->r14, 0X1908);
    // 0x800525B0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800525B4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800525B8: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800525BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800525C0: jal         0x8005C28C
    // 0x800525C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    clearscreen(rdram, ctx);
        goto after_2;
    // 0x800525C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    after_2:
    // 0x800525C8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x800525CC: addiu       $v1, $v1, 0x4418
    ctx->r3 = ADD32(ctx->r3, 0X4418);
    // 0x800525D0: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800525D4: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x800525D8: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x800525DC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800525E0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800525E4: ori         $t9, $t9, 0x3048
    ctx->r25 = ctx->r25 | 0X3048;
    // 0x800525E8: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x800525EC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800525F0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800525F4: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x800525F8: lui         $t1, 0xEE00
    ctx->r9 = S32(0XEE00 << 16);
    // 0x800525FC: lui         $t2, 0x33
    ctx->r10 = S32(0X33 << 16);
    // 0x80052600: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80052604: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80052608: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005260C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80052610: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80052614: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x80052618: ori         $t4, $t4, 0x602
    ctx->r12 = ctx->r12 | 0X602;
    // 0x8005261C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80052620: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80052624: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80052628: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005262C: lw          $v0, 0x0($v1)
    ctx->r2 = S32(MEM_W(ctx->r3, 0X0));
    // 0x80052630: lui         $t7, 0x4A
    ctx->r15 = S32(0X4A << 16);
    // 0x80052634: lui         $t6, 0xED05
    ctx->r14 = S32(0XED05 << 16);
    // 0x80052638: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005263C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80052640: ori         $t6, $t6, 0x403C
    ctx->r14 = ctx->r14 | 0X403C;
    // 0x80052644: ori         $t7, $t7, 0xC384
    ctx->r15 = ctx->r15 | 0XC384;
    // 0x80052648: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005264C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80052650: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x80052654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052658: jr          $ra
    // 0x8005265C: nop

    return;
    // 0x8005265C: nop

;}
RECOMP_FUNC void __alCSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C222C: lw          $t6, 0x4($a0)
    ctx->r14 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800C2230: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800C2234: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800C2238: bne         $t6, $zero, L_800C2248
    if (ctx->r14 != 0) {
        // 0x800C223C: lw          $v0, 0x10($a0)
        ctx->r2 = S32(MEM_W(ctx->r4, 0X10));
            goto L_800C2248;
    }
    // 0x800C223C: lw          $v0, 0x10($a0)
    ctx->r2 = S32(MEM_W(ctx->r4, 0X10));
    // 0x800C2240: jr          $ra
    // 0x800C2244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C2244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C2248:
    // 0x800C2248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C224C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800C2250: lw          $a1, 0x4($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X4));
L_800C2254:
    // 0x800C2254: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800C2258: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x800C225C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C2260: beql        $t8, $zero, L_800C22A4
    if (ctx->r24 == 0) {
        // 0x800C2264: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C22A4;
    }
    goto skip_0;
    // 0x800C2264: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x800C2268: lw          $t3, 0x14($a0)
    ctx->r11 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800C226C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C2270: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C2274: beql        $t3, $zero, L_800C2290
    if (ctx->r11 == 0) {
        // 0x800C2278: lw          $t0, 0xB8($a3)
        ctx->r8 = S32(MEM_W(ctx->r7, 0XB8));
            goto L_800C2290;
    }
    goto skip_1;
    // 0x800C2278: lw          $t0, 0xB8($a3)
    ctx->r8 = S32(MEM_W(ctx->r7, 0XB8));
    skip_1:
    // 0x800C227C: lw          $t4, 0xB8($a3)
    ctx->r12 = S32(MEM_W(ctx->r7, 0XB8));
    // 0x800C2280: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C2284: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x800C2288: lw          $a1, 0x4($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800C228C: lw          $t0, 0xB8($a3)
    ctx->r8 = S32(MEM_W(ctx->r7, 0XB8));
L_800C2290:
    // 0x800C2290: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C2294: beql        $at, $zero, L_800C22A4
    if (ctx->r1 == 0) {
        // 0x800C2298: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C22A4;
    }
    goto skip_2;
    // 0x800C2298: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x800C229C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800C22A0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C22A4:
    // 0x800C22A4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C22A8: beq         $t8, $zero, L_800C22E8
    if (ctx->r24 == 0) {
        // 0x800C22AC: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_800C22E8;
    }
    // 0x800C22AC: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x800C22B0: lw          $t3, 0x14($a0)
    ctx->r11 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800C22B4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C22B8: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C22BC: beql        $t3, $zero, L_800C22D8
    if (ctx->r11 == 0) {
        // 0x800C22C0: lw          $t0, 0xBC($a3)
        ctx->r8 = S32(MEM_W(ctx->r7, 0XBC));
            goto L_800C22D8;
    }
    goto skip_3;
    // 0x800C22C0: lw          $t0, 0xBC($a3)
    ctx->r8 = S32(MEM_W(ctx->r7, 0XBC));
    skip_3:
    // 0x800C22C4: lw          $t4, 0xBC($a3)
    ctx->r12 = S32(MEM_W(ctx->r7, 0XBC));
    // 0x800C22C8: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C22CC: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x800C22D0: lw          $a1, 0x4($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800C22D4: lw          $t0, 0xBC($a3)
    ctx->r8 = S32(MEM_W(ctx->r7, 0XBC));
L_800C22D8:
    // 0x800C22D8: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C22DC: beql        $at, $zero, L_800C22EC
    if (ctx->r1 == 0) {
        // 0x800C22E0: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C22EC;
    }
    goto skip_4;
    // 0x800C22E0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x800C22E4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800C22E8:
    // 0x800C22E8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C22EC:
    // 0x800C22EC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C22F0: beq         $t8, $zero, L_800C2330
    if (ctx->r24 == 0) {
        // 0x800C22F4: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_800C2330;
    }
    // 0x800C22F4: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x800C22F8: lw          $t3, 0x14($a0)
    ctx->r11 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800C22FC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C2300: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C2304: beql        $t3, $zero, L_800C2320
    if (ctx->r11 == 0) {
        // 0x800C2308: lw          $t0, 0xC0($a3)
        ctx->r8 = S32(MEM_W(ctx->r7, 0XC0));
            goto L_800C2320;
    }
    goto skip_5;
    // 0x800C2308: lw          $t0, 0xC0($a3)
    ctx->r8 = S32(MEM_W(ctx->r7, 0XC0));
    skip_5:
    // 0x800C230C: lw          $t4, 0xC0($a3)
    ctx->r12 = S32(MEM_W(ctx->r7, 0XC0));
    // 0x800C2310: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C2314: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x800C2318: lw          $a1, 0x4($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X4));
    // 0x800C231C: lw          $t0, 0xC0($a3)
    ctx->r8 = S32(MEM_W(ctx->r7, 0XC0));
L_800C2320:
    // 0x800C2320: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C2324: beql        $at, $zero, L_800C2334
    if (ctx->r1 == 0) {
        // 0x800C2328: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C2334;
    }
    goto skip_6;
    // 0x800C2328: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x800C232C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800C2330:
    // 0x800C2330: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C2334:
    // 0x800C2334: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C2338: beql        $t8, $zero, L_800C2378
    if (ctx->r24 == 0) {
        // 0x800C233C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C2378;
    }
    goto skip_7;
    // 0x800C233C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x800C2340: lw          $t3, 0x14($a0)
    ctx->r11 = S32(MEM_W(ctx->r4, 0X14));
    // 0x800C2344: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C2348: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C234C: beql        $t3, $zero, L_800C2364
    if (ctx->r11 == 0) {
        // 0x800C2350: lw          $a1, 0xC4($a3)
        ctx->r5 = S32(MEM_W(ctx->r7, 0XC4));
            goto L_800C2364;
    }
    goto skip_8;
    // 0x800C2350: lw          $a1, 0xC4($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0XC4));
    skip_8:
    // 0x800C2354: lw          $t4, 0xC4($a3)
    ctx->r12 = S32(MEM_W(ctx->r7, 0XC4));
    // 0x800C2358: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C235C: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x800C2360: lw          $a1, 0xC4($a3)
    ctx->r5 = S32(MEM_W(ctx->r7, 0XC4));
L_800C2364:
    // 0x800C2364: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800C2368: beql        $at, $zero, L_800C2378
    if (ctx->r1 == 0) {
        // 0x800C236C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C2378;
    }
    goto skip_9;
    // 0x800C236C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x800C2370: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C2374: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800C2378:
    // 0x800C2378: bnel        $a2, $t2, L_800C2254
    if (ctx->r6 != ctx->r10) {
        // 0x800C237C: lw          $a1, 0x4($a0)
        ctx->r5 = S32(MEM_W(ctx->r4, 0X4));
            goto L_800C2254;
    }
    goto skip_10;
    // 0x800C237C: lw          $a1, 0x4($a0)
    ctx->r5 = S32(MEM_W(ctx->r4, 0X4));
    skip_10:
    // 0x800C2380: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800C2384: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x800C2388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C238C: jr          $ra
    // 0x800C2390: nop

    return;
    // 0x800C2390: nop

;}
RECOMP_FUNC void osScRemoveClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C5CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004C5D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004C5D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004C5D8: lw          $v1, 0x260($a0)
    ctx->r3 = S32(MEM_W(ctx->r4, 0X260));
    // 0x8004C5DC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8004C5E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004C5E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004C5E8: jal         0x800BC180
    // 0x8004C5EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8004C5EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004C5F0: lw          $v1, 0x1C($sp)
    ctx->r3 = S32(MEM_W(ctx->r29, 0X1C));
    // 0x8004C5F4: lw          $a1, 0x24($sp)
    ctx->r5 = S32(MEM_W(ctx->r29, 0X24));
    // 0x8004C5F8: lw          $a2, 0x18($sp)
    ctx->r6 = S32(MEM_W(ctx->r29, 0X18));
    // 0x8004C5FC: beq         $v1, $zero, L_8004C63C
    if (ctx->r3 == 0) {
        // 0x8004C600: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8004C63C;
    }
    // 0x8004C600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8004C604:
    // 0x8004C604: bnel        $v1, $a1, L_8004C630
    if (ctx->r3 != ctx->r5) {
        // 0x8004C608: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8004C630;
    }
    goto skip_0;
    // 0x8004C608: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    skip_0:
    // 0x8004C60C: beq         $a2, $zero, L_8004C620
    if (ctx->r6 == 0) {
        // 0x8004C610: lw          $t9, 0x20($sp)
        ctx->r25 = S32(MEM_W(ctx->r29, 0X20));
            goto L_8004C620;
    }
    // 0x8004C610: lw          $t9, 0x20($sp)
    ctx->r25 = S32(MEM_W(ctx->r29, 0X20));
    // 0x8004C614: lw          $t7, 0x0($a1)
    ctx->r15 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8004C618: b           L_8004C63C
    // 0x8004C61C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_8004C63C;
    // 0x8004C61C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_8004C620:
    // 0x8004C620: lw          $t8, 0x0($a1)
    ctx->r24 = S32(MEM_W(ctx->r5, 0X0));
    // 0x8004C624: b           L_8004C63C
    // 0x8004C628: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
        goto L_8004C63C;
    // 0x8004C628: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
    // 0x8004C62C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8004C630:
    // 0x8004C630: lw          $v1, 0x0($v1)
    ctx->r3 = S32(MEM_W(ctx->r3, 0X0));
    // 0x8004C634: bne         $v1, $zero, L_8004C604
    if (ctx->r3 != 0) {
        // 0x8004C638: nop
    
            goto L_8004C604;
    }
    // 0x8004C638: nop

L_8004C63C:
    // 0x8004C63C: jal         0x800BC180
    // 0x8004C640: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8004C640: nop

    after_1:
    // 0x8004C644: lw          $ra, 0x14($sp)
    ctx->r31 = S32(MEM_W(ctx->r29, 0X14));
    // 0x8004C648: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004C64C: jr          $ra
    // 0x8004C650: nop

    return;
    // 0x8004C650: nop

;}
